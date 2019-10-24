#include "StringId.h"

using namespace Ar;

StringId::StringId(const char* str):
	m_sid(-1)
{
	m_rawStr = strdup(str);
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

int StringId::internString()
{
	auto sid = s_sidMap.find(m_sid);
	if(sid == s_sidMap.end())
	{
		int newSid = hashString(m_rawStr);
		s_sidMap[newSid] = m_rawStr;
	}

	return m_sid;
}

bool StringId::operator==(const StringId& sid)
{
	if (m_sid != -1)
	{
		return this->m_sid == sid.m_sid;
	}
	return (strcmp(sid.m_rawStr, this->m_rawStr) == 0);
}


//TODO hashString
int hashString(const char* str)
{
	return 0;
}

