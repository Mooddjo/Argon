#include "StringId.h"
#include <algorithm>
#include <array>
#include <cstdint>
#include <numeric>

using namespace Ar;



std::map<int, const char*>	Ar::StringId::s_sidMap;

// CRC from https://rosettacode.org/wiki/CRC-32#C.2B.2B
// Generates a lookup table for the checksums of all 8-bit values.
std::array<std::uint_fast32_t, 256> generate_crc_lookup_table() noexcept
{
	auto const reversed_polynomial = std::uint_fast32_t{ 0xEDB88320uL };

	// This is a function object that calculates the checksum for a value,
	// then increments the value, starting from zero.
	struct byte_checksum
	{
		std::uint_fast32_t operator()() noexcept
		{
			auto checksum = static_cast<std::uint_fast32_t>(n++);

			for (auto i = 0; i < 8; ++i)
				checksum = (checksum >> 1) ^ ((checksum & 0x1u) ? reversed_polynomial : 0);

			return checksum;
		}

		unsigned n = 0;
	};

	auto table = std::array<std::uint_fast32_t, 256>{};
	std::generate(table.begin(), table.end(), byte_checksum{});

	return table;
}

// Calculates the CRC for any sequence of values. (You could use type traits and a
// static assert to ensure the values can be converted to 8 bits.)
template <typename InputIterator>
std::uint_fast32_t crc(InputIterator first, InputIterator last)
{
	// Generate lookup table only on first use then cache it - this is thread-safe.
	static auto const table = generate_crc_lookup_table();

	// Calculate the checksum - make sure to clip to 32 bits, for systems that don't
	// have a true (fast) 32-bit type.
	return std::uint_fast32_t{ 0xFFFFFFFFuL } &
		~std::accumulate(first, last,
			~std::uint_fast32_t{ 0 } &std::uint_fast32_t{ 0xFFFFFFFFuL },
			[](std::uint_fast32_t checksum, std::uint_fast8_t value)
	{ return table[(checksum ^ value) & 0xFFu] ^ (checksum >> 8); });
}



StringId::StringId(const char* str) :
	m_sid(-1)
 {
	m_rawStr = _strdup(str);
	internString();
}

StringId::~StringId()
{
	delete m_rawStr;
}

StringId::StringId(const StringId& sid)
{
	if (&sid != this)
	{
		m_rawStr = _strdup(sid.m_rawStr);
		m_sid = sid.m_sid;
		internString();
	}
}


StringId& StringId::operator=(const StringId& sid)
{
	if (&sid != this)
	{
		delete m_rawStr;
		m_rawStr = _strdup(sid.m_rawStr);
		m_sid = sid.m_sid;
		internString();
	}

	return *this;
}

int StringId::internString()
{
	auto sid = s_sidMap.find(m_sid);
	if (sid == s_sidMap.end())
	{
		std::string s = std::string(m_rawStr);
		m_sid = crc(s.begin(), s.end());
		s_sidMap[m_sid] = _strdup(m_rawStr);
	}

	return m_sid;
}



