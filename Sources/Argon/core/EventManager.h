#pragma once
#include "tools/Singleton.h"

namespace Ar
{
	class Event
	{

	};

	class EventManager : public Singleton<EventManager>
	{
	public:
		void subscribe();
		void unsubscribe();
		void fire(Event& event);
		void fireWithDelay(int ms);
	};
}