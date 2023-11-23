#pragma once

#include <string>
#include <vector>

struct ClientInfo {
	int port = 0;
	std::string token;
	std::string header;
	std::string version;
	std::wstring path;
};

class Auth {
public: 
	Auth() = default;
	~Auth() = default;

	static std::vector<DWORD> GetAllProcessIds(const std::wstring& processName);

	static ClientInfo GetClientInfo(const DWORD& pid, bool riotClient = false);
	static DWORD GetProcessId(const std::wstring& processName);

	// MakeLeagueHeader method
	// MakeRiotHeader method
private:
	//static inline Base64 base64;

	static int GetPort(const std::string& cmdLine, bool riotClient = false);
	static std::string GetToken(const std::string& cmdLine, bool riotClient = false);

	static std::wstring GetProcessCommandLine(const DWORD& processId);
	static std::wstring GetProcessPath(const DWORD& processId);
	static std::string GetFileVersion(const std::wstring& file);
};