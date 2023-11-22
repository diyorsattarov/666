#pragma once
#include <cpr/cpr.h>

#include <string>

class LCU {
public:
	static inline cpr::Session session;
	static std::string Request(const std::string& method, const std::string& endpoint, const cpr::Header& headers = {}, const std::string & body = "");

private:
};