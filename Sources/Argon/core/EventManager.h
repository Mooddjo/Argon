#pragma once
#include <functional>
#include <list>
#include "tools/Singleton.h"
#include "core/StringId.h"

namespace Ar
{

	#define BUILD_EVENT_FUNCTION(function, object) std::bind(function, object, std::placeholders::_1)
	
	struct Event
	{
		Event(): name(""){};
		StringId name;
	};

//#define REGISTER_FOR_EVENT(name, eventHandler) EventManager::instance()->subscribe(name, EventHandler);
	using EventFunction = std::function<void(const Event&)>;

	struct EventHandler
	{
		EventHandler(const char* pFunctionName, EventFunction pFunction):
			functionName(pFunctionName),
			function(pFunction){}

		StringId		functionName;
		EventFunction	function;
	};
	using EventHandlers = std::list<EventHandler>;


	class EventManager : public Singleton<EventManager>
	{

	public:
		void subscribe(const StringId& eventName, EventHandler eventHandler);
		void unsubscribe(const StringId& eventName, EventHandler eventHandler);
		void fire(const Event& event);
		void fireWithDelay(const Event& event, int ms);

	private:
		bool isSameEventFunction(EventHandler& eventHandler1, EventHandler& eventHandler2);

	protected:
		std::map<StringId, EventHandlers>	m_eventHandlersMap;
	};
}