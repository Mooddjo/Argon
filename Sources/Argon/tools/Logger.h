#pragma once

#include <iostream>
#include "core/Macro.h"

namespace Ar
{
	class ARGON_EXPORT Logger
	{
	public:
		enum class LogFilter : unsigned short {
			info,
			warning,
			error
		};

		static void log(LogFilter filter,const char* message)
		{
			switch (filter)
			{
			case LogFilter::info:
				std::cout << "[INFO] " << message << std::endl;
			default:
				break;
			}
			
		}
	};


}

#define LOGV(message) Ar::Logger::log(Ar::Logger::LogFilter::info, message);