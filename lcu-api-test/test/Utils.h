#pragma once
#include <cpr/cpr.h>

class Utils{
public:
	Utils() = default;
	~Utils() = default;

	static std::string ToUpper(std::string str);
	static std::wstring ToUpper(std::wstring wstr);

};