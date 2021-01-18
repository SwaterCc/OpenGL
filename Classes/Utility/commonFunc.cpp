#include"commonFunc.h"

std::string formatStr(const char* format, ...)
{
	va_list ap;
	__crt_va_start(ap, format);

	char buff[512];
	memset(buff, 0, 512);
	vsprintf_s(buff, format, ap);
	__crt_va_end(ap);
	std::string res(buff);
	return res;
}

void log(const char* format, ...)
{
	va_list ap;
	__crt_va_start(ap, format);
	char LogStr[512];
	memset(LogStr, 0, 512);
	vsprintf_s(LogStr, format, ap);
	__crt_va_end(ap);

	OutputDebugString(strcat(LogStr,"\n"));
}