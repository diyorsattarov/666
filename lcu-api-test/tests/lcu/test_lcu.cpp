#include <gtest/gtest.h>
#include <json/json.h>
#include "../../include/lcu/lcu.h"

class LCUTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
    LCU lcu;
    std::string endpoint;
    std::string jsonPayload;

    cpr::Header headers{
        {"accept", "application/json"},
        {"Authorization", "Basic cmlvdDpyNEZ3TjJoVHJKUllPTTZDaGxBczRB"},
        {"Content-Type", "application/json"}
    };
};

TEST_F(LCUTest, PutRequestTest) {
    jsonPayload = R"(
        {
            "inventoryToken": "string",
            "profileIconId": 29
        }
    )";
    endpoint = "https://127.0.0.1:59284/lol-summoner/v1/current-summoner/icon";
    std::string response = lcu.Request("PUT", endpoint, headers, jsonPayload);
    Json::CharReaderBuilder reader;
    Json::Value root;
    std::istringstream response_stream(response);
    Json::parseFromStream(reader, response_stream, &root, nullptr);

    if (root.isObject() && root.isMember("profileIconId")) {
        ASSERT_EQ(root["profileIconId"], 29);
    }
    else {
        std::cerr << "Invalid JSON response." << std::endl;
    }
}