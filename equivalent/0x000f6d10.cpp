// STATUS: equivalent (tools/equiv.py level 3: 19983 inputs, branch coverage 0/0)
// FUN_000f6d10 @ 0x000f6d10
// cl-flags: /GS
extern "C" char* __cdecl strchr(const char*, int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
void __cdecl FUN_000f6b50(char*, const char*, int);

void __cdecl FUN_000f6d10(const char* filename, int value)
{
    struct Scratch { char stem[40];  } scratch;
    const char* dot = strchr(filename, '.');
    unsigned int length = dot - filename;
    strncpy(scratch.stem, filename, length);
    scratch.stem[length] = '\0';
    FUN_000f6b50(scratch.stem, dot + 1, value);
}