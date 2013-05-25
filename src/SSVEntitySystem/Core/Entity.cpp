// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include <vector>
#include <string>
#include <algorithm>
#include "SSVEntitySystem/Core/Entity.h"
#include "SSVEntitySystem/Core/Component.h"

using namespace std;

namespace sses
{
	Entity::Entity(Manager& mManager, const std::string& mId) : manager(mManager), id{mId} { }

	void Entity::update(float mFrameTime)
	{
		memoryManager.cleanUp();
		for(const auto& component : memoryManager.getItems()) component->update(mFrameTime);
	}
	void Entity::draw() { for(const auto& component : memoryManager.getItems()) component->draw(); }
	void Entity::destroy() { manager.del(*this); }

	// Setters
	void Entity::setDrawPriority(int mDrawPriority) 	{ drawPriority = mDrawPriority; }

	// Getters
	Manager& Entity::getManager()	 					{ return manager; }
	const string& Entity::getId() const					{ return id; }
	int Entity::getDrawPriority() const 				{ return drawPriority; }
	vector<Component*>& Entity::getComponents()			{ return memoryManager.getItems().getItems(); }
	Repository<Component*>& Entity::getComponentRepo()	{ return memoryManager.getItems(); }
}
