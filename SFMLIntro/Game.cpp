#include "Game.h"
#include <fstream>

Game::Game(const std::string& config)
{
	init(config);
}

void Game::init(const std::string& path)
{
	std::ifstream fin(path);
	fin >> m_PlayerConfig.SR >> m_PlayerConfig.CR >> m_PlayerConfig.FR 
		>> m_PlayerConfig.FG >> m_PlayerConfig.OR >> m_PlayerConfig.OG
		>> m_PlayerConfig.OB >> m_PlayerConfig.OT >> m_PlayerConfig.V;

	m_window.create(sf::VideoMode(1280,720), "FirstGame");	//will be replaced by window config
	m_window.setFramerateLimit(60);

	spawnPlayer();
}

void Game::run()
{
	while (m_running)
	{
		m_entities.update();

		sUserInput();
		if (!m_paused)
		{
			sEnemySpawner();
			sMovement();
			sCollision();
			sLifespan();
			m_currentFrame++;
		}
		sRender();
	}
}

void Game::sRender()
{
	m_window.clear();
	for (auto e : m_entities.getEntities())
	{
		e->cShape->circle.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);
		e->cTransform->angle += 1.0f;
		e->cShape->circle.setRotation(e->cTransform->angle);
		m_window.draw(e->cShape->circle);
	}
	m_window.display();
}

void Game::setPaused(bool paused)
{
	m_paused = true;
}

void Game::sUserInput()
{


	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_running = false;
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				if(!m_paused)m_player->cInput->up = true;
				break;
			case sf::Keyboard::A:
				if (!m_paused)m_player->cInput->left = true;
				break;
			case sf::Keyboard::S:
				if (!m_paused)m_player->cInput->down = true;
				break;
			case sf::Keyboard::D:
				if (!m_paused)m_player->cInput->right = true;
				break;
			case sf::Keyboard::P:
				if(m_paused)
					m_paused = false;
				else
					m_paused = true;
				break;
			default:
				break;
			}
		}
		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				if (!m_paused)m_player->cInput->up = false;
				break;
			case sf::Keyboard::A:
				if (!m_paused)m_player->cInput->left = false;
				break;
			case sf::Keyboard::S:
				if (!m_paused)m_player->cInput->down = false;
				break;
			case sf::Keyboard::D:
				if (!m_paused)m_player->cInput->right = false;
				break;
			default:
				break;
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)	//shoot
			{
				if (!m_paused)spawnBullet(m_player, Vec2(event.mouseButton.x, event.mouseButton.y));
			}
			if (event.mouseButton.button == sf::Mouse::Right)	//special
			{
				if (!m_paused)spawnSpecialWeapon(m_player, Vec2(event.mouseButton.x, event.mouseButton.y));
			}
		}
	}
}

void Game::sMovement()
{
	for (auto E : m_entities.getEntities("Bullet"))
	{
		E->cTransform->pos.y += E->cTransform->velocity.y;
		E->cTransform->pos.x += E->cTransform->velocity.x;
	}
	for (auto e : m_entities.getEntities("SmallEnemy"))
	{
		e->cTransform->pos.y += e->cTransform->velocity.y;
		e->cTransform->pos.x += e->cTransform->velocity.x;
	}
	for (auto s : m_entities.getEntities("Special"))
	{
		s->cTransform->pos.y += s->cTransform->velocity.y;
		s->cTransform->pos.x += s->cTransform->velocity.x;
	}
	if(m_player->cInput->up)
		m_player->cTransform->pos.y -= m_player->cTransform->velocity.y;
	if (m_player->cInput->down)
		m_player->cTransform->pos.y += m_player->cTransform->velocity.y;

	if (m_player->cInput->left)
		m_player->cTransform->pos.x -= m_player->cTransform->velocity.x;
	if (m_player->cInput->right)
		m_player->cTransform->pos.x += m_player->cTransform->velocity.x;
			
}
void Game::sLifespan()
{
	for (auto e : m_entities.getEntities("Bullet"))
	{
		if (!e->cLifespan->remaining)
			e->destroy();
		else
			e->cLifespan->remaining--;
	}
	for (auto e : m_entities.getEntities("SmallEnemy"))
	{
		if (!e->cLifespan->remaining)
			e->destroy();
		else
			e->cLifespan->remaining--;
	}
	for (auto s : m_entities.getEntities("Special"))
	{
		if (!s->cLifespan->remaining)
			s->destroy();
		else
			s->cLifespan->remaining--;
	}
}
void Game::sEnemySpawner()
{
	if (m_currentFrame - m_lastEnemySpawnTime >= 60)
	{
		if (m_entities.getEntityCount("Enemy") <= 15)
			spawnEnemy();
	}
}
void Game::sCollision()
{
	Vec2 diff;
	for (auto e : m_entities.getEntities("Enemy"))
	{
		for (auto b : m_entities.getEntities("Bullet"))
		{
			diff = e->cTransform->pos - b->cTransform->pos;
			if (diff.length() < (e->cCollision->radius + b->cCollision->radius))
			{
				e->destroy();
				deathEffect(e);
				b->destroy();
			}
		}
		diff = e->cTransform->pos - m_player->cTransform->pos;
		if (diff.length() < (e->cCollision->radius + m_player->cCollision->radius))
		{
			m_player->cTransform->pos.x = m_window.getSize().x / 2;
			m_player->cTransform->pos.y = m_window.getSize().y / 2;
		}
		for (auto s : m_entities.getEntities("Special"))
		{
			diff = e->cTransform->pos - s->cTransform->pos;
			if (diff.length() < (e->cCollision->radius + s->cCollision->radius))
			{
				e->destroy();
				deathEffect(e);
			}
		}
	}
}

void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos)
{
	Vec2 spawnLoc(entity->cTransform->pos);
	auto e = m_entities.addEntity("Bullet");
	Vec2 velocity = mousePos - spawnLoc;
	velocity.normalize();
	velocity *= 18.0f;
	e->cTransform = std::make_shared<CTransform>(spawnLoc, velocity, 0.0f);
	e->cShape = std::make_shared<CShape>(6, entity->cShape->circle.getPointCount()
		, sf::Color(0,0,0), sf::Color(255, 255, 255), 2);
	e->cCollision = std::make_shared<CCollision>(6);
	e->cLifespan = std::make_shared<CLifespan>(60);
}

void Game::spawnPlayer()
{
	auto e = m_entities.addEntity("Player");
	e->cTransform = std::make_shared<CTransform>(Vec2(200.0f, 200.0f), Vec2(5.0f, 5.0f), 0.0f);
	e->cShape = std::make_shared<CShape>(32.0f, 3, sf::Color(100, 50, 100), sf::Color(255, 0, 0), 3.0f);
	e->cInput = std::make_shared<CInput>();
	e->cCollision = std::make_shared<CCollision>(35);
	m_player = e;
}

void Game::spawnEnemy()
{
	Vec2 spawnLoc((rand() % (m_window.getSize().x - 74)) + 35, (rand() % (m_window.getSize().y - 74)) + 35);
	auto entity = m_entities.addEntity("Enemy");
	entity->cTransform = std::make_shared<CTransform>(spawnLoc, Vec2(1.0f, 1.0f), 0.0f);
	entity->cShape = std::make_shared<CShape>(32.0f, 5, sf::Color(0, 200, 133), sf::Color(0, 0, 255), 3.0f);
	entity->cCollision = std::make_shared<CCollision>(35);
	entity->cInput = std::make_shared<CInput>();
	m_lastEnemySpawnTime = m_currentFrame;
}

void Game::deathEffect(std::shared_ptr<Entity> entity)
{
	Vec2 spawnLoc(entity->cTransform->pos);
	Vec2 vel;
	size_t numPoints = entity->cShape->circle.getPointCount();
	float toDeg = 180 / PI;
	for (size_t i = 1; i <= numPoints; i++)
	{
		vel.x = cos((360 / (numPoints * i)) * toDeg);
		vel.y = sin((360 / (numPoints * i)) * toDeg);
		vel.normalize();
		vel *= 4;
		auto e = m_entities.addEntity("SmallEnemy");
		e->cTransform = std::make_shared<CTransform>(spawnLoc, vel, 0.0f);
		e->cShape = std::make_shared<CShape>(entity->cShape->circle.getRadius() / 3, entity->cShape->circle.getPointCount()
			, entity->cShape->circle.getFillColor(), entity->cShape->circle.getOutlineColor()
			, entity->cShape->circle.getOutlineThickness());
		e->cLifespan = std::make_shared<CLifespan>(20);
	}
}

void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity, const Vec2& mousePos)
{
	Vec2 spawnLoc(entity->cTransform->pos);
	auto e = m_entities.addEntity("Special");
	Vec2 velocity = mousePos - spawnLoc;
	velocity.normalize();
	velocity *= 9.0f;
	e->cTransform = std::make_shared<CTransform>(spawnLoc, velocity, 0.0f);
	e->cShape = std::make_shared<CShape>(entity->cShape->circle.getRadius(), entity->cShape->circle.getPointCount()
		, sf::Color(255,255,255), sf::Color(0,0,0), 2);
	e->cCollision = std::make_shared<CCollision>(entity->cShape->circle.getRadius());
	e->cLifespan = std::make_shared<CLifespan>(90);
}
