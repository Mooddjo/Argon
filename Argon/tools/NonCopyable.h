#pragma once
namespace Ar
{
	class NonCopyable
	{
	protected:
		NonCopyable(){}
		~NonCopyable(){}
		NonCopyable(const NonCopyable&)				= delete;
		NonCopyable& operator= (const NonCopyable&) = delete;
	};
}