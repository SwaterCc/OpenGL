#include <windows.h>
#include <cstdio>

void log(const char * format, ...)
{
	char LogStr[512];
	memset(LogStr, 0, 512);
	sprintf(LogStr, format, 1);
	OutputDebugString(LogStr);
}