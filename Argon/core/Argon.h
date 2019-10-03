#pragma once

#ifdef ARGON_BUILD
#define ARGON_EXPORT __declspec(dllexport)
#else 
#define ARGON_EXPORT
#endif