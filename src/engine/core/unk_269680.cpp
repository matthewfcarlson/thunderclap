// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00269680..0x002699f0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f7c593cc {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7c593cc {} using namespace fn_f7c593cc;
#include "engine/core.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
#endif
namespace fn_f7c593cc {
extern "C" void __cdecl FUN_00270b70(char *);
extern "C" int __cdecl FUN_00345b90(int);
extern "C" void __cdecl FUN_00267660(char *);
typedef int(__cdecl* Dummy_2698b0)(void);
extern "C" int __cdecl FUN_002673d0(char*, int);

// 0x00269680 thunk_FUN_002709b0 (5 B): not yet verified
// 0x00269690 thunk_FUN_00271070 (5 B): not yet verified
// 0x002696a0 thunk_FUN_00270a50 (5 B): not yet verified
// 0x002696d0 thunk_FUN_002710d0 (5 B): not yet verified
// 0x002696e0 thunk_FUN_00271230 (5 B): not yet verified
// 0x00269720 thunk_FUN_00271530 (5 B): not yet verified
// 0x00269740 thunk_FUN_00270b70 (5 B): not yet verified
// 0x00269750 thunk_FUN_00271560 (5 B): not yet verified
// 0x00269780 thunk_FUN_00270f10 (5 B): not yet verified
// 0x00269790 thunk_FUN_00270f90 (5 B): not yet verified

// 0x002697c0 FUN_002697c0 (227 B): equivalent/0x002697c0.cpp
// sym: _FUN_002697c0
// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 26/26)
// FUN_002697c0 @ 0x002697c0
extern "C" void __cdecl FUN_002697c0(const char *source, char *output, char *workspace, char **suffix, const char **remainder)
{
    char *prefix = workspace ? workspace : output;
    const char *colon = strchr(source, ':');
    unsigned int length;
    const char *rest;
    if (colon) {
        length = (unsigned int)(colon - source + 1);
        strncpy(prefix, source, length);
        prefix[length] = 0;
        rest = source + length;
    } else {
        FUN_00270b70(prefix);
        length = 0;
        while (prefix[length]) ++length;
        rest = source;
    }
    if (remainder) *remainder = rest;
    for (char *p = prefix; *p; ++p)
        *p = (char)FUN_00345b90((signed char)*p);
    if (output) {
        char *dst = output;
        const char *src = prefix;
        do { *dst++ = *src; } while (*src++);
        if (suffix) *suffix = output + length;
        char *tail = output + length;
        dst = tail;
        src = rest;
        do { *dst++ = *src; } while (*src++);
        for (char *p = tail; *p; ++p)
            if (*p == '/') *p = '\\';
        FUN_00267660(tail);
    }
}


// 0x002698b0 FUN_002698b0 (22 B): matches/0x002698b0.cpp
// sym: _FUN_002698b0
extern "C" int __cdecl FUN_002698b0(char* path) {
    if (*path == '\\')
        ++path;
    return FUN_002673d0(path, 0);
}

// 0x002698f0 thunk_FUN_00271cf0 (5 B): not yet verified
// 0x00269900 thunk_FUN_00271f20 (5 B): not yet verified
} // namespace fn_f7c593cc
