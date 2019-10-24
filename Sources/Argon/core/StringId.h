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
		const char*							getString() const;
		int									getId() const;

		const char* getString() const { return m_rawStr; }
		int getSID() const { return m_sid; }

	protected:

		const char*							m_rawStr;
		int									m_sid;
<<<<<<< HEAD:Build/StringId.h
=======

>>>>>>> da8fc80c70262a40c366527f9f55a7a13d1ccf28:Sources/Argon/core/StringId.h
		static std::map<int, const char*>	s_sidMap;
	};

	inline const char* StringId::getString() const { return m_rawStr; }
	inline int StringId::getId() const { return m_sid; }
}