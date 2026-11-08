// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_00339ad0 @ 0x00339ad0
// aux_do's error report: a failed chunk's message goes to the global ALERT function, or to stderr.
#include "decls/data/lua.h"
#include "decls/data/engine/core.h"
#include "decls/data/engine/unknown.h"

extern "C" const char DAT_00428328[];
extern "C" void __cdecl FUN_002135a0(LuaVMState *L, int idx, const char *k);
extern "C" int __cdecl FUN_00212f00(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00212e20(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_002139a0(LuaVMState *L, int nargs, int nresults);
extern "C" const char * __cdecl FUN_00213190(LuaVMState *L, int idx);
extern "C" int __cdecl FID_conflict__fwprintf(void *stream, const char *format, const char *text);
extern "C" void __cdecl FUN_00212d80(LuaVMState *L, int idx);
// equiv-conv: FUN_00339ad0 eax esi
extern "C" void __cdecl FUN_00339ad0(int active, LuaVMState *session)
{
    if (!active) return;
    FUN_002135a0(session, -10001, DAT_0043469c);
    int result = FUN_00212f00(session, -1);
    if (result == 6) {
        FUN_00212e20(session, -2);
        FUN_002139a0(session, 1, 0);
    } else {
        const char *message = FUN_00213190(session, -2);
        FID_conflict__fwprintf(((void*)&DAT_004d9a30), DAT_00428328, message);
        FUN_00212d80(session, -3);
    }
}
