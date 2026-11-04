// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00238bb0 @ 0x00238bb0
// cl-flags: /GS
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"

typedef int (__cdecl *SinkFn)(int, int, const char*, int);
int __cdecl FUN_00267730(char* buf, int size, const char* fmt, char* args);

int __cdecl FUN_00238bb0(int a1, int a2, const char* fmt, ...)
{
    struct Frame {
        char buf[0x400];
    } fr;
#if defined(HULK_PTR64)
    __builtin_va_list va;
    __builtin_va_start(va, fmt);
    FUN_00267730(fr.buf, 0x400, fmt, va);
#else
    FUN_00267730(fr.buf, 0x400, fmt, (char*)(&fmt + 1));
#endif
    if (!(*(SinkFn*)&DAT_004e5c30)) {
        return -1;
    }
    int result = (*(SinkFn*)&DAT_004e5c30)(a1, a2, fr.buf, DAT_004e5c34);
    return result;
}
