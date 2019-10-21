#pragma once
#include "core/Macro.h"
#include <map>


namespace Ar
{
	class ARGON_EXPORT StringId
	{
	public:
		StringId(const char* str);
		~StringId();
		StringId(const StringId& sid);
		StringId& operator=(const StringId& sid);
		bool operator==(const StringId& sid);

		const char* getString() const { return m_rawStr; }
		int getSID() const { return m_sid; }

	protected:
		int internString(const char* str);

		const char*							m_rawStr;
		int									m_sid;

		static std::map<int, const char*>	s_sidMap;
	};
}