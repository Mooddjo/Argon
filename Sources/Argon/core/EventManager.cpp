#include "EventManager.h"
#include <algorithm>

using namespace Ar;

bool EventManager::isSameEventFunction(EventHandler& eventHandler1, EventHandler& eventHandler2)
{
	auto target1 = eventHandler1.functionName.getId();
	auto target2 = eventHandler1.functionName.getId();
	return target1 == target2;
}

void EventManager::subscribe(const StringId& eventName, EventHandler eventHandler)
{
	auto handlers = m_eventHandlersMap[eventName];
	auto bindCompareFunction = std::bind(&EventManager::isSameEventFunction, this, std::placeholders::_1, eventHandler);
	auto it = std::find_if(handlers.begin(), handlers.end(), bindCompareFunction);
	if (it == handlers.end())// eventFunc not already exists in map, so insert
	{
		handlers.push_back(eventHandler);
	}

}
	

void EventManager::unsubscribe(const StringId& eventName, EventHandler eventHandler)
{
	auto handlers = m_eventHandlersMap[eventName];
	auto bindCompareFunction = std::bind(&EventManager::isSameEventFunction, this, std::placeholders::_1, eventHandler);
	std::remove_if(handlers.begin(), handlers.end(), bindCompareFunction);
}

void EventManager::fire(const Event& event)
{
	auto handlers = m_eventHandlersMap[event.name];
	auto callHandlerClosure = [&event](const EventHandler& ev)
	{
		ev.function(event);
	};
	std::for_each(std::begin(handlers), std::end(handlers), callHandlerClosure);
}

void EventManager::fireWithDelay(const Event& event, int ms)
{

}
