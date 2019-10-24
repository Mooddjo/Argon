#include <iostream>
#include "Argon.h"
#include <string>

using namespace std;

class Playground : public Ar::ArgonApplication
{

public:
	virtual void onInit() override
	{
		LOGV("Playground application onInit");
		Ar::StringId s = "coucou mon poulet";
		Ar::StringId s2 = "coucou mon poulet";
		string str = "CRC de ";
		str += s.getString();
		str += ":";
		str += std::to_string(s.getId());

		string str2 = "CRC: ";
		str2 += s2.internString();
		LOGV(str.c_str());
		LOGV(str2.c_str());
	}




	virtual void onFinished() override
	{
		LOGV("Playground application onFinished");
	}

};

int main()
{
	Playground app;
	app.start();
	return  EXIT_SUCCESS;
}