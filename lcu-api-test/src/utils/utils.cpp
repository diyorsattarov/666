#include <locale>
#include <codecvt>
#include <sstream>
#include <filesystem>
#include <array>
#include <cwctype>
#include <random>
//URLDownloadToFileA
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#include "../../include/utils/utils.h"

std::string Utils::ToUpper(std::string str) {
	std::ranges::transform(str, str.begin(), [](const unsigned char c) { return static_cast<char>(std::toupper(c)); });
	return str;
}

std::wstring Utils::ToUpper(std::wstring wstr) {
	std::ranges::transform(wstr, wstr.begin(), std::towupper);
	return wstr;
}

std::string Utils::WstringToString(const std::wstring& wstr) {
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), static_cast<int>(wstr.length()), nullptr, 0, nullptr, nullptr);
	std::string result(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), static_cast<int>(wstr.length()), &result[0], size_needed, nullptr, nullptr);
	return result;
}