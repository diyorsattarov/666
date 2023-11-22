#include "Utils.h"
#include "LCU.h"

std::string LCU::Request(const std::string& method, const std::string& endpoint, const cpr::Header& headers, const std::string& body) {
	std::string sURL = endpoint;
	
	cpr::Response r = {};

	session.SetUrl(sURL);
	session.SetBody(body);
	session.SetHeader(headers);
	session.SetVerifySsl(false);

	if (const std::string upperMethod = Utils::ToUpper(method); upperMethod == "GET") {
		r = session.Get();
	}
	else if (upperMethod == "PUT") {
		r = session.Put();
	}

	return r.text;
}