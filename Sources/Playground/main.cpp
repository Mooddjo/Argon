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
		string str = "CRC de ";
		str += s.getString();
		str += ":";
		str += std::to_string(s.getSID());
		LOGV(str.c_str());
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