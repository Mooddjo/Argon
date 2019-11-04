#include "EventManager.h"

using namespace Ar;

void EventManager::subscribe(const StringId& eventName, EventFunction eventFunc)
{
	auto funcs = m_eventHandlersMap[eventName];
	auto closure = [](EventFunction func)
	{

	};
}
	

void EventManager::unsubscribe(StringId Name)
{

}

void EventManager::fire(const Event& event)
{

}

void EventManager::fireWithDelay(const Event& event, int ms)
{

}
