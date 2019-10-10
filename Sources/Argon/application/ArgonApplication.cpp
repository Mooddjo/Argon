#pragma once
#include "ArgonApplication.h"

#include "tools/Logger.h"

using namespace Ar;

void Ar::ArgonApplication::start()
{
	
	onInit();
	argon = ArgonEngine::instance();
	argon->init();
	argon->run();
	onFinished();
}

