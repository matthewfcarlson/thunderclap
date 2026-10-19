// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_00214ac0 @ 0x00214ac0
// Lua 5.0 auxgetinfo: fills a lua_Debug according to the option letters in `what`.
// what arrives in eax, ar in esi and ci in edi; L and f are on the stack.
struct TObject_214ac0 {
    int tt;
    int value;
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
void FUN_00214160(lua_Debug_214ac0 *ar, const TObject_214ac0 *f);
int __fastcall FUN_00213f20(int unused, CallInfo *ci);
// equiv-conv: FUN_00214840 ecx stack
const char *__cdecl FUN_00214840(CallInfo *ci, const char **name);

// equiv-conv: FUN_00214ac0 eax esi edi stack stack
int __cdecl FUN_00214ac0(const char *what, lua_Debug_214ac0 *ar, CallInfo *ci, lua_State_214ac0 *L, const TObject_214ac0 *f)
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
            ar->nups = ((Closure_214ac0 *)f->value)->nupvalues;
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
