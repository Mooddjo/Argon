#pragma once
#include "core/Argon.h"

namespace argon
{
	class ARGON_EXPORT Application
	{
	public:
		virtual void init() = 0;
		virtual void run() = 0;
	};
}