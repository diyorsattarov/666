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
    std::string endpoint = "";
    cpr::Header headers{
        {"accept", "application/json"},
        {"Authorization", "Basic cmlvdDpyNEZ3TjJoVHJKUllPTTZDaGxBczRB"},
        {"Content-Type", "application/json"}
    };
    std::string jsonPayload = R"(
        {
            "inventoryToken": "string",
            "profileIconId": 29
        }
    )";
};

TEST_F(LCUTest, PutRequestTest) {
    endpoint = "https://127.0.0.1:59284/lol-summoner/v1/current-summoner/icon";
    std::string response = lcu.Request("PUT", endpoint, headers, jsonPayload);

    std::cout << response << std::endl;

    ASSERT_TRUE(response.find("expected_response_string") != std::string::npos);
}