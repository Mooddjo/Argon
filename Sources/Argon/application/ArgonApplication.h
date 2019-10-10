#pragma once
#include "core/Macro.h"
#include "ArgonEngine.h"

namespace Ar
{
	class ARGON_EXPORT ArgonApplication
	{
	public:
		void start();

	protected:
		virtual void onInit()		= 0;
		virtual void onFinished()	= 0;

	private:
		ArgonEngine* argon;
	};
}