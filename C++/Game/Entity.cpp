#include "Entity.h"

void Entity::destroy()
{
	is_alive = false;
}

const std::string& Entity::tag()
{
	return _tag;
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string & tag)
{
	auto e = std::make_shared<Entity>(tag, m_totalEntities++);
	m_toAdd.push_back(e);
	return e;
}

void EntityManager::update()
{
	for (auto e : m_toAdd)
	{
		m_entities.push_back(e);
		m_entityMap[e->tag()].push_back(e);
	}
	m_toAdd.clear();
	removeDeadEntities(m_entities);

	for (auto& [tag, entityVec] : m_entityMap)
		removeDeadEntities(entityVec);

}

const EntityVector& EntityManager::getEntities()
{
	return m_entities;
}

const EntityVector& EntityManager::getEntities(const std::string& tag)
{
	return m_entityMap[tag];
}

void EntityManager::removeDeadEntities(EntityVector& vec)
{
	EntityVector::iterator it;
	for (it = vec.begin(); it < vec.end();)
	{
		if (!((*it)->is_alive))
			it = vec.erase(it);
		else
			it++;
	}
}

int EntityManager::getEntityCount()
{
	return m_entities.size();
}

int EntityManager::getEntityCount(const std::string& key)
{
	return m_entityMap[key].size() + 1;
}