// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000c6d30 @ 0x000c6d30
extern "C" char* __cdecl strchr(const char*, int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
void __cdecl FUN_000c6b60(char*, char*, unsigned int);
void __cdecl FUN_000c6d30(char* path, unsigned int value)
{
    char prefix[36];
    unsigned int cookie = DAT_004d9968;
    char* dot = strchr(path, '.');
    unsigned int length = (unsigned int)(dot - path);
    strncpy(prefix, path, length);
    prefix[length] = 0;
    FUN_000c6b60(prefix, dot + 1, value);
    __security_check_cookie(cookie);
}
