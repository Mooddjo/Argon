#pragma once
#include <map>


namespace Ar
{
	class StringId
	{
	public:
		StringId(const char* str);
		StringId(const StringId& sid);
		StringId& operator=(const StringId& sid);
		bool operator==(const StringId& sid);

	protected:
		int internString(const char* str);

		const char*							m_rawStr;
		int									m_sid;

		static std::map<const char*, int>	s_sidMap;
	};
}