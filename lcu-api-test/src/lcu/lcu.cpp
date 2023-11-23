#include "../../include/lcu/lcu.h"
#include "../../include/utils/utils.h"

std::string LCU::Request(const std::string& method, const std::string& endpoint, const std::string& body) {
    std::string sURL = "https://127.0.0.1:54182" + endpoint;

    cpr::Response r = {};
    cpr::Header defaultHeaders{
        {"accept", "application/json"},
        {"Authorization", "Basic cmlvdDpfdGJ0Z0psUFBRSjBYbFVOYzRVR19B"},
        {"Content-Type", "application/json"}
    };

    session.SetUrl(sURL);
    session.SetBody(body);
    session.SetHeader(defaultHeaders);
    session.SetVerifySsl(false);

    if (const std::string upperMethod = Utils::ToUpper(method); upperMethod == "GET") {
        r = session.Get();
    }
    else if (upperMethod == "PUT") {
        r = session.Put();
    }

    return r.text;
}
