#include <iostream>
#include "Argon.h"
#include "core/tests/Test_StringId.h"
#include "core/tests/Test_EventManager.h"
using namespace std;

class Playground : public Ar::ArgonApplication
{

public:
	virtual void onInit() override
	{
		LOGV("Playground application onInit");
		
	}




	virtual void onFinished() override
	{
		LOGV("Playground application onFinished");
	}

};

int main()
{
	//Test_StringId::run();
	Test_EventManager::run();
	Playground app;
	app.start();
	return  EXIT_SUCCESS;
}