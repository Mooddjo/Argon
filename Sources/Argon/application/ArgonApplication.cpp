#pragma once
#include "ArgonApplication.h"

#include "tools/Logger.h"

#include "core/tests/Test_EventManager.h"

using namespace Ar;

void Ar::ArgonApplication::start()
{
	
	onInit();
	argon = ArgonEngine::instance();
	argon->init();
	argon->run();
	onFinished();
}

