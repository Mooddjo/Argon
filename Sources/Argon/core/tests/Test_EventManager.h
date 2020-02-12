#pragma once
#include "core/Macro.h"

class ARGON_EXPORT Test_EventManager
{
public:
	Test_EventManager() = delete;
	Test_EventManager(const Test_EventManager&) = delete;
	Test_EventManager& operator=(const Test_EventManager&) = delete;

	static void run();
};

