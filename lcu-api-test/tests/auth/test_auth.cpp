#include <gtest/gtest.h>
#include <Windows.h>
#include "../../include/auth/auth.h" // Include the actual path to your Auth header

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
    }
}