// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 18/18)
// auxgetinfo: fill ar according to the option letters in what for the function f (ci its activation or NULL).
#include "decls/data/lua.h"

// equiv-conv: FUN_00214160 ecx eax
extern "C" void FUN_00214160(LuaVMDebug* ar, const LuaVMTObject* func);
extern "C" int __fastcall FUN_00213f20(LuaVMState* L, LuaVMCallInfo* ci);
// equiv-conv: FUN_00214840 ecx stack
extern "C" const char* __cdecl FUN_00214840(LuaVMCallInfo* ci, const char** name);

// equiv-conv: FUN_00214ac0 eax esi edi stack stack
extern "C" int __cdecl FUN_00214ac0(const char* what, LuaVMDebug* ar, LuaVMCallInfo* ci, LuaVMState* L, const LuaVMTObject* f)
{
    int status = 1;
    for (; *what; what++) {
        switch (*what) {
        case 'S':
            FUN_00214160(ar, f);
            break;
        case 'l':
            ar->currentline = ci ? FUN_00213f20(0, ci) : -1;
            break;
        case 'u':
            ar->nups = ((LuaVMClosure*)f->value.gc)->c.nupvalues;
            break;
        case 'n':
            ar->namewhat = ci ? FUN_00214840(ci, &ar->name) : 0;
            if (ar->namewhat == 0) {
                ar->namewhat = "";
                ar->name = 0;
            }
            break;
        case 'f':
            L->top->tt = f->tt;
            L->top->value = f->value;
            break;
        default:
            status = 0;
        }
    }
    return status;
}
