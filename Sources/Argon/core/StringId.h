#pragma once
#include "core/Macro.h"
#include <map>

#pragma warning(push)
#pragma warning(disable:4251)

namespace Ar
{
	class ARGON_EXPORT StringId
	{
	public:
		StringId(const char* str);
		~StringId();
		StringId(const StringId& sid);
		StringId&							operator=(const StringId& sid);
		int									internString();
		inline const char*					getString() const;
		inline int							getId() const;
		friend inline bool					operator<(const StringId& sid1, const StringId sid2);
		friend inline bool					operator==(const StringId& sid1, const StringId& sid2);

	protected:
		const char*							m_rawStr;
		int									m_sid;
		static std::map<int, const char*>	s_sidMap;
	};

	inline const char*						StringId::getString() const { return m_rawStr; }
	inline int								StringId::getId() const { return m_sid; }	
	inline bool								operator<(const StringId& sid1, const StringId sid2)
	{
		return sid1.getId() < sid2.getId();
	}

	inline bool operator==(const StringId& sid1, const StringId& sid2)
	{
		if (sid1.m_sid != -1 && sid2.m_sid != -1)
		{
			return sid1.m_sid == sid2.m_sid;
		}
		return strcmp(sid1.m_rawStr, sid2.m_rawStr) == 0;
	}

}
#pragma warning(pop)