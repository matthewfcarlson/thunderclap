// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000c6d90 @ 0x000c6d90
// cl-flags: /GS
#include "compat/ptr.h"
extern "C" char* __cdecl strchr(const char*, int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

void __cdecl FUN_000c6bc0(const char* name, const char* ext, int arg);

// Splits "name.ext" at the first '.' and passes both halves on.
void __cdecl FUN_000c6d90(const char* path, int arg)
{
    struct Frame {
        char name[0x20];
    } f;
    const char* dot = strchr(path, '.');
    hulk_intptr len = dot - path;
    strncpy(f.name, path, len);
    f.name[len] = 0;
    FUN_000c6bc0(f.name, dot + 1, arg);
}
