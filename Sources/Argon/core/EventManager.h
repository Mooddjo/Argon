#pragma once
#include <functional>
#include <list>
#include "tools/Singleton.h"
#include "core/StringId.h"

namespace Ar
{
	class Event
	{
		StringId name;
	};

	class EventManager : public Singleton<EventManager>
	{
		using EventFunction = std::function<void(const Event&)>;
		using EventHandlers = std::list<EventFunction>;

	public:
		void subscribe(StringId name);
		void unsubscribe(StringId Name);
		void fire(const Event& event);
		void fireWithDelay(const Event& event, int ms);

	protected:
		std::list<EventFunction>			m_eventHandlers;
		std::map<StringId, EventHandlers>	m_eventHandlersMap;
	};
}