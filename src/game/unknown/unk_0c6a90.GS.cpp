// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000c6a90..0x000c7280 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f2637ef0 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f2637ef0 {} using namespace fn_f2637ef0;
#include "game/unknown.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f2637ef0 {
extern "C" void __cdecl FUN_000c6b60(char*, char*, unsigned int);
extern "C" void __cdecl FUN_000c6bc0(const char* name, const char* ext, int arg);
extern "C" void __cdecl FUN_000c6c40(const char* name, const char* ext, int arg);


// 0x000c6d30 FUN_000c6d30 (86 B): matches/0x000c6d30.cpp
// sym: ?FUN_000c6d30@fn_f2637ef0@@YAXPADI@Z
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000c6d30 @ 0x000c6d30
void __cdecl FUN_000c6d30(char* path, unsigned int value)
{
    char prefix[32];
    char* dot = strchr(path, '.');
    unsigned int length = (unsigned int)(dot - path);
    strncpy(prefix, path, length);
    prefix[length] = 0;
    FUN_000c6b60(prefix, dot + 1, value);
}


// 0x000c6d90 FUN_000c6d90 (86 B): matches/0x000c6d90.cpp
// sym: ?FUN_000c6d90@fn_f2637ef0@@YAXPBDH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000c6d90 @ 0x000c6d90
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


// 0x000c6df0 FUN_000c6df0 (86 B): matches/0x000c6df0.cpp
// sym: ?FUN_000c6df0@fn_f2637ef0@@YAXPBDH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000c6df0 @ 0x000c6df0
// Splits "name.ext" at the first '.' and passes both halves on.
void __cdecl FUN_000c6df0(const char* path, int arg)
{
    struct Frame {
        char name[0x20];
    } f;
    const char* dot = strchr(path, '.');
    hulk_intptr len = dot - path;
    strncpy(f.name, path, len);
    f.name[len] = 0;
    FUN_000c6c40(f.name, dot + 1, arg);
}

} // namespace fn_f2637ef0
