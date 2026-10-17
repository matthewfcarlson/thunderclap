// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000f6d10 @ 0x000f6d10
extern "C" char* __cdecl strchr(const char*, int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
void __cdecl FUN_000f6b50(char*, const char*, int);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

void __cdecl FUN_000f6d10(const char* filename, int value)
{
    struct Scratch { char stem[40]; unsigned int cookie; } scratch;
    scratch.cookie = DAT_004d9968;
    const char* dot = strchr(filename, '.');
    unsigned int length = dot - filename;
    strncpy(scratch.stem, filename, length);
    scratch.stem[length] = '\0';
    FUN_000f6b50(scratch.stem, dot + 1, value);
    __security_check_cookie(scratch.cookie);
}