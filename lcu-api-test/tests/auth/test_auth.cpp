#include <gtest/gtest.h>
#include <Windows.h>
#include "../../include/auth/auth.h"
#include "../../include/utils/utils.h"

DWORD testProcessId;

class AuthTest : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(AuthTest, TestGetAllProcessIds) {
    const std::wstring processName = L"LeagueClientUx.exe";
    std::vector<DWORD> processIds = Auth::GetAllProcessIds(processName);
    ASSERT_FALSE(processIds.empty());
    for (const auto& pid : processIds) {
        std::cout << "Found process with ID: " << pid << std::endl;
        testProcessId = pid;
    }
}
TEST_F(AuthTest, TestGetClientInfo) {
    ClientInfo info = Auth::GetClientInfo(testProcessId, false);
    std::cout << "Found port: " << info.port << std::endl;
    std::cout << "Found token: " << info.token << std::endl;
    std::cout << "Found Path: " << Utils::WstringToString(info.path) << std::endl;
    std::cout << "Found Version: " << info.version << std::endl;
    ASSERT_NE(info.port, 0);
    ASSERT_NE(info.token, "");
    ASSERT_NE(Utils::WstringToString(info.path), "");
    ASSERT_NE(info.version, "");
}
