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
TEST_F(AuthTest, TestGetClientInfo) {
    // Assuming you have a valid process ID for testing
    const DWORD testProcessId = 7760;
    const bool testRiotClient = false; // or false depending on your use case

    ClientInfo info = Auth::GetClientInfo(testProcessId, testRiotClient);

    // Replace these assertions with your actual expected values
    ASSERT_EQ(info.port, 54182);
    ASSERT_EQ(info.token, "cmlvdDp0a3hHclo4dGs0SUV3VVdNMm9ocGh3");
    //ASSERT_EQ(info.path, /* expected path value */);
    //ASSERT_EQ(info.version, /* expected version value */);
}
