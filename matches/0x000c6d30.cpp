// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000c6d30 @ 0x000c6d30
// cl-flags: /GS
extern "C" char* __cdecl strchr(const char*, int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
void __cdecl FUN_000c6b60(char*, char*, unsigned int);
void __cdecl FUN_000c6d30(char* path, unsigned int value)
{
    char prefix[32];
    char* dot = strchr(path, '.');
    unsigned int length = (unsigned int)(dot - path);
    strncpy(prefix, path, length);
    prefix[length] = 0;
    FUN_000c6b60(prefix, dot + 1, value);
}
