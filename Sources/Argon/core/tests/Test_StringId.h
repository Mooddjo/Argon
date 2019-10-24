#pragma once
#include "core/Macro.h"

class ARGON_EXPORT Test_StringId
{
public:
	Test_StringId() = delete;
	Test_StringId(const Test_StringId&) = delete;
	Test_StringId& operator=(const Test_StringId&) = delete;
	
	static void run();
};

