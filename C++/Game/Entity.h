#pragma once
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

#include "Components.h"


class Entity
{
	friend class EntityManager;

	bool is_alive = true;
	std::string _tag = "Default";
	const size_t _id = 0;


public:
	Entity(const std::string& tag, size_t id)
		: _tag(tag), _id(id) {}

	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CCollision> cCollision;
	std::shared_ptr<CShape> cShape;
	std::shared_ptr<CScore> cScore;
	std::shared_ptr<CInput> cInput;
	std::shared_ptr<CLifespan> cLifespan;

	void destroy();
	const std::string& tag();
};

typedef std::vector<std::shared_ptr<Entity>> EntityVector;
typedef std::map   <std::string, EntityVector> EntityMap;

class EntityManager
{
	EntityVector m_entities;
	EntityMap m_entityMap;
	EntityVector m_toAdd;
	size_t m_totalEntities = 0;

public:
	EntityManager() {}
	void update();
	std::shared_ptr<Entity> addEntity(const std::string & tag);
	int getEntityCount();
	int getEntityCount(const std::string& key);
	const EntityVector& getEntities();
	const EntityVector& getEntities(const std::string& tag);
	void removeDeadEntities(EntityVector& vec);
};
