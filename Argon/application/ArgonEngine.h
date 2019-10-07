#pragma once
#include "tools/Singleton.h"

namespace Ar
{
	class ArgonEngine: public Singleton<ArgonEngine>
	{
	public:
		void init();
		void run();
	};
}

