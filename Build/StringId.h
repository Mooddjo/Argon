#pragma once
#include <map>


namespace Ar
{
	class StringId
	{
	public:
		StringId(const char* str);
		StringId(const StringId& sid);
		StringId&							operator=(const StringId& sid);
		bool								operator==(const StringId& sid);
		int									internString();
		const char*							getString() const;
		int									getId() const;

	protected:

		const char*							m_rawStr;
		int									m_sid;
		static std::map<int, const char*>	s_sidMap;
	};

	inline const char* StringId::getString() const { return m_rawStr; }
	inline int StringId::getId() const { return m_sid; }
}