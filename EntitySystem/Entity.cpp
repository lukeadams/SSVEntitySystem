/* The MIT License (MIT)
 * Copyright (c) 2012 Vittorio Romeo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "Entity.h"
#include "Component.h"
#include "Manager.h"

using namespace std;

namespace sses
{
	Entity::Entity(const std::string& mId) : id{mId} { }
	Entity::~Entity() { }

	void Entity::addComponent(Component* mComponent)
	{
		mComponent->entity = this;
		components.add(mComponent->id, mComponent);
		manager->addComponent(mComponent);
		mComponent->init();
	}
	void Entity::update(float mFrameTime) { for (auto& component : components.getItems()) component->update(mFrameTime); }
	void Entity::draw() { for (auto& component : components.getItems()) component->draw(); }
	void Entity::destroy() { manager->del(this); }

	void Entity::setDrawPriority(int mDrawPriority) { drawPriority = mDrawPriority; }
	int Entity::getDrawPriority() const { return drawPriority; }

	Manager& Entity::getManager() { return *manager; }
	Repository<Component*>& Entity::getComponentRepo() { return components; }

	// Shortcuts
	Entity& Entity::operator+=(Component* mComponent) { addComponent(mComponent); return *this; }
} /* namespace sses */
