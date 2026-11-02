// STATUS: equivalent (tools/equiv.py level 3: 6610 inputs, branch coverage 18/18)
// FUN_00214ac0 @ 0x00214ac0
// FUN_00214ac0 @ 0x00214ac0
// Lua 5.0 auxgetinfo: fills a lua_Debug according to the option letters in `what`.
// what arrives in eax, ar in esi and ci in edi; L and f are on the stack.
#include "compat/ptr.h"
struct TObject_214ac0 {
    int tt;
    hulk_intptr value;
};

struct Closure_214ac0 {
    char pad0[7];
    unsigned char nupvalues;        // 7
};

struct lua_State_214ac0 {
    char pad0[8];
    TObject_214ac0 *top;                   // 8
};

struct CallInfo;

struct lua_Debug_214ac0 {
    int event;
    const char *name;               // 4
    const char *namewhat;           // 8
    const char *what;
    const char *source;
    int currentline;                // 0x14
    int nups;                       // 0x18
};

// equiv-conv: FUN_00214160 ecx eax
extern "C" void __cdecl FUN_00214160(void *, void *);
extern "C" int __fastcall FUN_00213f20(void *, int *);
// equiv-conv: FUN_00214840 ecx stack
extern "C" const char * __cdecl FUN_00214840(void *, char **);

// equiv-conv: FUN_00214ac0 eax esi edi stack stack
extern "C" int __cdecl FUN_00214ac0(const char *what, void * ar_, void *ci, void *L, const void *f)
{
    lua_Debug_214ac0 * ar = (lua_Debug_214ac0 *)ar_;
    int status = 1;
    for (; *what; what++) {
        switch (*what) {
        case 'S':
            FUN_00214160((lua_Debug_214ac0 *)ar, (void *)(const TObject_214ac0 *)((const TObject_214ac0 *)f));
            break;
        case 'l':
            ar->currentline = ((CallInfo *)ci) ? FUN_00213f20((void *)(hulk_uintptr)(int)0, (int *)(CallInfo *)((CallInfo *)ci)) : -1;
            break;
        case 'u':
            ar->nups = ((Closure_214ac0 *)((const TObject_214ac0 *)f)->value)->nupvalues;
            break;
        case 'n':
            ar->namewhat = ((CallInfo *)ci) ? FUN_00214840((CallInfo *)((CallInfo *)ci), (char **)(const char * *)(&ar->name)) : 0;
            if (ar->namewhat == 0) {
                ar->namewhat = "";
                ar->name = 0;
            }
            break;
        case 'f':
            ((lua_State_214ac0 *)L)->top->tt = ((const TObject_214ac0 *)f)->tt;
            ((lua_State_214ac0 *)L)->top->value = ((const TObject_214ac0 *)f)->value;
            break;
        default:
            status = 0;
        }
    }
    return status;
}
