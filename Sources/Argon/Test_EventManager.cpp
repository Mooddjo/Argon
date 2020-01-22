#include "Test_EventManager.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "core/EventManager.h"

using namespace Ar;

enum Weather : unsigned int
{
	RAIN,
	CLOUDY,
	SUN,
	SNOW,
	MAX,
};

class Day
{
public:
	Day()
	{
		float coef = RAND_MAX / (1.f * Weather::MAX - 1);
		unsigned int w = static_cast<unsigned int>(rand() / coef);
		m_weather = static_cast<Weather>(w);
	}

	Weather m_weather;
};

class Week
{
public:
	Week():
		m_currentIndex(-1),
		m_currentDay(nullptr){}

	void nextDay()
	{
		m_currentIndex++;
		if (m_currentIndex >= 7)
		{
			m_currentIndex = 0;
		}
		m_currentDay = &m_day[m_currentIndex];
		Ar::Event ev;
		ev.name = "new day";
		EventManager::instance()->fire(ev);
	}

	Day m_day[7];
	const Day* m_currentDay;
	short m_currentIndex;
};



class Sensor
{
public:
	void detect(const Event& event)
	{
		StringId strId = event.name;
		const char* rawStr = strId.getString();
		std::string str = rawStr;
		std::cout << "OOOOOOOOK: " << str << std::endl;
	}
};

void Test_EventManager::run()
{
	Week w;
	Sensor s;
	auto eventFunction = BUILD_EVENT_FUNCTION(&Sensor::detect, s);
	EventHandler evHandler("detect", eventFunction);
	EventManager::instance()->subscribe("new day", evHandler);

	for (int i = 0; i < 7; i++)
	{
		w.nextDay();
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}


}

