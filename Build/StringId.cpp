#include "StringId.h"

using namespace Ar;

//TODO internString first and affectresult...
StringId::StringId(const char* str)
{
	m_rawStr = strdup(str);
	m_sid = internString(m_rawStr);
	
}

StringId::StringId(const StringId& sid)
{
	if (&sid != this)
	{
		delete m_rawStr;
		m_rawStr = sid.m_rawStr;
		m_sid = sid.m_sid;
	}
}

StringId& StringId::operator=(const StringId& sid)
{
	if (&sid != this)
	{
		delete m_rawStr;
		m_rawStr = sid.m_rawStr;
		m_sid = sid.m_sid;
	}

	return *this;
}

int StringId::internString(const char* str)
{
	auto sid = s_sidMap.find(str);
	if(sid == s_sidMap.end())
	{
		int newSid = hashString(str);
		s_sidMap[str] = newSid;
	}

	return sid->second;
}

bool StringId::operator==(const StringId& sid)
{
	return this->m_sid == sid.m_sid;
}


//TODO hashString
int hashString(const char* str)
{
	return 0;
}

