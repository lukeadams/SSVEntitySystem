// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "SSVEntitySystem/Core/Manager.h"
#include "SSVEntitySystem/Core/Entity.h"

using namespace std;
using namespace ssvu;

namespace sses
{
	void Manager::update(float mFrameTime)
	{
		for(auto& p : groupedEntities) eraseRemoveIf(groupedEntities[p.first], &memoryManager.isDead<Entity*>);
		memoryManager.refresh();
		for(const auto& e : memoryManager) e->update(mFrameTime);
	}
	void Manager::draw()
	{
		toSort.clear();
		for(const auto& e : memoryManager) toSort.push_back(e.get());
		sort(toSort, [](const Entity* mA, const Entity* mB){ return mA->getDrawPriority() > mB->getDrawPriority(); });
		for(const auto& e : toSort) e->draw();
	}
}
