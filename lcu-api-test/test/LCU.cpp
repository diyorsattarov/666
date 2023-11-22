#include "LCU.h"

std::string LCU::Request(const std::string& method, const std::string& endpoint, const cpr::Header& headers, const std::string& body) {
	std::string sURL = endpoint;
	
	cpr::Response r = {};

	session.SetUrl(sURL);
	session.SetBody(body);
	session.SetHeader(headers);
	session.SetVerifySsl(false);

	r = session.Get();

	return r.text;
}