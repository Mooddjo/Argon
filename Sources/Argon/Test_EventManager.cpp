#include "Test_EventManager.h"
#include <cstdlib>

enum Weather : unsigned int
{
	RAIN,
	CLOUDY,
	SUN,
	SNOW,
	MAX,
};

class Week
{
public:
	Week():currentIndex(-1){}

	void nextDay()
	{
		currentIndex++;
		if (currentIndex >= 7)
		{
			currentIndex = 0;
		}
		m_currentDay = m_day[currentIndex];
	}

	Day m_day[7];
	Day m_currentDay;
	short currentIndex;
};

class Day
{
public:
	Day() 
	{
		float coef = RAND_MAX  / (1.f * Weather::MAX - 1);
		unsigned int w = rand() / coef;
		m_weather = static_cast<Weather>(w);
	}

	Weather m_weather;
};

class Sensor
{
	void detect()
	{

	}
};

void Test_EventManager::run()
{
	Week w;
	Sensor s;
	
}

