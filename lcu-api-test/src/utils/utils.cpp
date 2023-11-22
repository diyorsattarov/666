#include <cwctype>
#include "../../include/utils/utils.h"

std::string Utils::ToUpper(std::string str) {
	std::ranges::transform(str, str.begin(), [](const unsigned char c) { return static_cast<char>(std::toupper(c)); });
	return str;
}

std::wstring Utils::ToUpper(std::wstring wstr) {
	std::ranges::transform(wstr, wstr.begin(), std::towupper);
	return wstr;
}
