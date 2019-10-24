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
		StringId&							operator=(const StringId& sid);
		bool								operator==(const StringId& sid);
		int									internString();
		inline const char*					getString() const;
		inline int							getId() const;

	protected:

		const char*							m_rawStr;
		int									m_sid;
		static std::map<int, const char*>	s_sidMap;
	};

	inline const char*						StringId::getString() const { return m_rawStr; }
	inline int								StringId::getId() const { return m_sid; }
}