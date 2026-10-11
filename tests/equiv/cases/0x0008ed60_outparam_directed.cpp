extern "C" int __stdcall XGetLaunchInfo(unsigned long* launchType, void* launchData);
extern "C" void __cdecl FUN_0008f880(int argc, char** argv);
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);

void __cdecl FUN_0008ed60()
{
    unsigned int cookie = DAT_004d9968;
    unsigned long launchType = 0;
    char launchData[0xc00];
    char commandLine[0xc00];
    char* args[128];
    int result = XGetLaunchInfo(&launchType, launchData);
    for (int i = 0; i < 0xc00; ++i)
        commandLine[i] = launchData[i];
    args[0] = "HULK-XBOX";
    int count = 1;
    if (result == 0 && launchType == 3 && commandLine[0]) {
        for (char* p = commandLine; *p; ++p) {
            if (*p == ' ') {
                *p = 0;
            } else if (p == commandLine || (p[-1] != ' ' && p[-1] != 0)) {
                args[count++] = p;
            }
        }
    }
    FUN_0008f880(count, args);
    __security_check_cookie(cookie);
}
