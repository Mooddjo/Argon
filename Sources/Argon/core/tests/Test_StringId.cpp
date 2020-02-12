#include "Test_StringId.h"
#include "tools/Logger.h"
#include "core/StringId.h"
#include <iostream>
#include <string>

void Test_StringId::run()
{
	Ar::StringId s = "coucou mon poulet";
	Ar::StringId s2 = "coucou mon poulet";
	std::string str = "CRC de " + std::string(s.getString()) + ":" + std::to_string(s.getId());
	s2.internString();
	std::string str2 = "CRC: " + std::to_string(s2.getId());
	bool isEqual = s == s2;
	std::string equalStr = isEqual ? " is equal to " : " is not equal to ";
	std::string result = std::string(s.getString()) + equalStr + std::string(s2.getString());
	LOGV(str.c_str());
	LOGV(str2.c_str());
	LOGV(result.c_str());
}
