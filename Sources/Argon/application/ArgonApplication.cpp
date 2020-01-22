#pragma once
#include "ArgonApplication.h"

#include "tools/Logger.h"

#include "Test_EventManager.h"

using namespace Ar;

void Ar::ArgonApplication::start()
{
	
	onInit();
	argon = ArgonEngine::instance();
	argon->init();
	Test_EventManager::run();
	argon->run();
	onFinished();
}

