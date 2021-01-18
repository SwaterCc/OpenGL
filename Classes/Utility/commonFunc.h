#ifndef _COMMONFUNC_H_
#define _COMMONFUNC_H_
#include<iostream>
#include<cstdio>
#include<string>
#if _WIN32
	#include <windows.h>
#endif
std::string formatStr(const char* format, ...);

void log(const char* format, ...);




#endif
