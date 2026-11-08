// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 2/2)
// luaD_rawrunprotected: run f(L, ud) with a longjmp record on the error chain; returns its status.
#include "decls/data/lua.h"

extern "C" int __cdecl __setjmp3(void* environment, int count);

extern "C" int __cdecl FUN_002152f0(LuaVMState* L, void(__cdecl* f)(LuaVMState* L, void* ud), void* ud) {
    struct {
        LuaVMLongjmp lj;
#if defined(_MSC_VER) && !defined(__clang__)
        volatile int extra;  // MSVC 7.1 puts the frame 4 bytes lower without it (the stored address is compared)
#endif
    } frame;
    frame.lj.previous = L->errorJmp;
    L->errorJmp = &frame.lj;
    frame.lj.status = 0;
#if defined(_MSC_VER) && !defined(__clang__)
    frame.extra = 0;
#endif
    if (__setjmp3(frame.lj.b, 0) == 0)
        f(L, ud);
    L->errorJmp = frame.lj.previous;
#if defined(_MSC_VER) && !defined(__clang__)
    return frame.lj.status + frame.extra;
#else
    return frame.lj.status;
#endif
}
