#pragma once
#include <sstream>
#include <iomanip>


class Debug {
public:
	static void LogDxError(const char* msg, HRESULT hr, const char* file, int line);
};








