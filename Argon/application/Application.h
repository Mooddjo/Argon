#pragma once

namespace argon
{
	class Application
	{
	public:
		virtual void init() = 0;
		virtual void run() = 0;
	};
}