// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 13/16, incomplete)
// FUN_0008ed60 @ 0x0008ed60
namespace XAPILIB { int __stdcall XGetLaunchInfo(unsigned long* launchType, void* launchData); }
extern "C" void __cdecl FUN_0008f880(int argc, char** argv);
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);
struct LaunchData_8ed60 { char bytes[0xc00]; };
void __cdecl FUN_0008ed60()
{
    unsigned int cookie = DAT_004d9968;
    unsigned long launchType = 0;
    char* args[32];
    LaunchData_8ed60 commandLine;
    LaunchData_8ed60 launchData;
    int result = XAPILIB::XGetLaunchInfo(&launchType, &launchData);
    commandLine = launchData;
    args[0] = "HULK-XBOX";
    int count = 1;
    if (result == 0 && launchType == 3) {
        for (char* p = commandLine.bytes; *p; ++p) {
            if (*p == ' ') {
                *p = 0;
            } else if (p == commandLine.bytes || p[-1] == ' ' || p[-1] == 0) {
                args[count++] = p;
            }
        }
    }
    FUN_0008f880(count, args);
    __security_check_cookie(cookie);
}
