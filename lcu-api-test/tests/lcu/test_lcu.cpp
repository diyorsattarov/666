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
};

TEST_F(LCUTest, PutRequestTest) {
    jsonPayload = R"(
        {
            "inventoryToken": "string",
            "profileIconId": 29
        }
    )";
    endpoint = "/lol-summoner/v1/current-summoner/icon";

    // Expect no throw for the Request
    EXPECT_NO_THROW({
        std::string response = lcu.Request("PUT", endpoint, jsonPayload);
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
    });
}

TEST_F(LCUTest, GetRequestTest) {
    std::string endpoint = "/lol-summoner/v1/current-summoner";

    // Expect no throw for the Request
    EXPECT_NO_THROW({
        std::string response = lcu.Request("GET", endpoint);
        Json::CharReaderBuilder reader;
        Json::Value root;
        std::istringstream response_stream(response);
        Json::parseFromStream(reader, response_stream, &root, nullptr);

        if (root.isObject() && root.isMember("gameName")) {
            ASSERT_EQ(root["gameName"], "koshka");
        }
        else {
            std::cerr << "Invalid JSON response." << std::endl;
        }
    });
}
