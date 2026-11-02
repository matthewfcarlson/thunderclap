// STATUS: equivalent (tools/equiv.py level 3: 149 inputs, branch coverage 18/21, incomplete)
// FUN_0021d830 @ 0x0021d830
struct LuaState;

struct FuncState;

struct LexState_21d830 {
    char pad0[4];
    int linenumber;
    int lastline;
    int token;
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState* fs;
    LuaState* L;
};

struct ExpDesc_21d830 {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

extern "C" int __cdecl FUN_0021bbc0(void *, void *);
void __cdecl FUN_0021b060(LexState_21d830* ls, const char* msg);
const char* __cdecl FUN_0021af00(LexState_21d830* ls, int token);
const char* FUN_00216320(LuaState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_0021ded0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_00221110(void *, void *);
extern "C" int __cdecl FUN_00221190(void *, void *);
extern "C" void __cdecl FUN_002211e0(void *, void *);
void __cdecl FUN_002216e0(FuncState* fs, ExpDesc_21d830* v, ExpDesc_21d830* key);
void __cdecl FUN_00221360(FuncState* fs, ExpDesc_21d830* v, ExpDesc_21d830* key);
int __cdecl FUN_002209b0(FuncState* fs, int ts);
// equiv-conv: FUN_0021d790 eax ebx
extern "C" void __cdecl FUN_0021d790(void *, void *);
// equiv-conv: FUN_0021ccb0 eax ebx
void FUN_0021ccb0(LexState_21d830* ls, ExpDesc_21d830* v);
// equiv-conv: FUN_0021d630 eax stack
extern "C" void __cdecl FUN_0021d630(void *, void *);

// Lua 5.0 primaryexp: a prefix expression followed by any number of field,
// index, method-call and call suffixes. v arrives in eax, ls in esi.
// equiv-conv: FUN_0021d830 eax esi
extern "C" void FUN_0021d830(void * v, void * ls_)
{
    LexState_21d830 * ls = (LexState_21d830 *)ls_;
    ExpDesc_21d830 key;
    ExpDesc_21d830 method;
    FuncState* fs = ls->fs;

    FUN_0021d790((LexState_21d830 *)ls, (ExpDesc_21d830 *)((ExpDesc_21d830 *)v));
    for (;;) {
        switch (ls->token) {
        case '.':
            FUN_0021ccb0(ls, ((ExpDesc_21d830 *)v));
            break;
        case '[':
            FUN_00221190((FuncState *)fs, (ExpDesc_21d830 *)((ExpDesc_21d830 *)v));
            ls->lastline = ls->linenumber;
            if (ls->lookaheadToken != 0x11f) {
                ls->token = ls->lookaheadToken;
                ls->seminfo = ls->lookaheadSeminfo;
                ls->lookaheadToken = 0x11f;
            } else {
                ls->token = FUN_0021bbc0((LexState_21d830 *)ls, (int *)(&ls->seminfo));
            }
            FUN_0021ded0((LexState_21d830 *)ls, (ExpDesc_21d830 *)(&key), 0);
            FUN_002211e0((FuncState *)(ls->fs), (ExpDesc_21d830 *)(&key));
            if (ls->token != ']')
                FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected", FUN_0021af00(ls, ']')));
            ls->lastline = ls->linenumber;
            if (ls->lookaheadToken != 0x11f) {
                ls->token = ls->lookaheadToken;
                ls->seminfo = ls->lookaheadSeminfo;
                ls->lookaheadToken = 0x11f;
            } else {
                ls->token = FUN_0021bbc0((LexState_21d830 *)ls, (int *)(&ls->seminfo));
            }
            FUN_002216e0(fs, ((ExpDesc_21d830 *)v), &key);
            break;
        case ':': {
            ls->lastline = ls->linenumber;
            if (ls->lookaheadToken != 0x11f) {
                ls->token = ls->lookaheadToken;
                ls->seminfo = ls->lookaheadSeminfo;
                ls->lookaheadToken = 0x11f;
            } else {
                ls->token = FUN_0021bbc0((LexState_21d830 *)ls, (int *)(&ls->seminfo));
            }
            if (ls->token != 0x116)
                FUN_0021b060(ls, "<name> expected");
            int name = ls->seminfo;
            ls->lastline = ls->linenumber;
            if (ls->lookaheadToken != 0x11f) {
                ls->token = ls->lookaheadToken;
                ls->seminfo = ls->lookaheadSeminfo;
                ls->lookaheadToken = 0x11f;
            } else {
                ls->token = FUN_0021bbc0((LexState_21d830 *)ls, (int *)(&ls->seminfo));
            }
            method.k = 4;
            method.info = FUN_002209b0(ls->fs, name);
            method.t = -1;
            method.f = -1;
            FUN_00221360(fs, ((ExpDesc_21d830 *)v), &method);
            FUN_0021d630((LexState_21d830 *)ls, (ExpDesc_21d830 *)((ExpDesc_21d830 *)v));
            break;
        }
        case '(':
        case '{':
        case 0x11e:
            FUN_00221110((FuncState *)fs, (ExpDesc_21d830 *)((ExpDesc_21d830 *)v));
            FUN_0021d630((LexState_21d830 *)ls, (ExpDesc_21d830 *)((ExpDesc_21d830 *)v));
            break;
        default:
            return;
        }
    }
}
