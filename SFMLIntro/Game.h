#pragma once
#include "Entity.h"

#define PI 3.14159
//			shapeRadius(SR), collisionRadius(CR), fill(RGB), outline(RGB), outlineThickness(OT), velocity(V) 
struct PlayerConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V; float S; };
struct EnemyConfig  { int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI; float SMIN; };
struct BulletConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L; float S; };

class Game
{
	sf::RenderWindow	m_window;
	EntityManager		m_entities;
	sf::Font			m_font;
	sf::Text			m_text;
	PlayerConfig		m_PlayerConfig;
	EnemyConfig			m_EnemyConfig;
	BulletConfig		m_BulletConfig;
	int					m_score = 0;
	int					m_currentFrame = 0;
	int					m_lastEnemySpawnTime = 0;
	bool				m_paused = true;		//for game logic
	bool				m_running = true;		//playing

	std::shared_ptr<Entity> m_player;

	void init(const std::string & config);
	void setPaused(bool paused);

	void sMovement();
	void sUserInput();
	void sLifespan();
	void sRender();
	void sEnemySpawner();
	void sCollision();

	void spawnPlayer();
	void spawnEnemy();
	void deathEffect(std::shared_ptr<Entity> entity);
	void spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos);
	void spawnSpecialWeapon(std::shared_ptr<Entity> entity, const Vec2& mousePos);

public:
	Game(const std::string& config);

	void run();
};