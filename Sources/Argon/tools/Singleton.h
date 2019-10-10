#pragma once
#include "NonCopyable.h"

namespace Ar
{
	template<class T>
	class Singleton: NonCopyable
	{

	public:
		static T* instance()
		{
			if (s_instance == nullptr)
			{
				s_instance = new T();
			}

			return s_instance;
		}

	protected:
		Singleton() {};
		virtual ~Singleton()
		{
			if (s_instance != nullptr)
			{
				delete s_instance;
			}
		}

		static T* s_instance;
	};

	template<class T>
	T* Singleton<T>::s_instance = nullptr;
}



