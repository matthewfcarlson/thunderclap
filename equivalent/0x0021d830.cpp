// STATUS: equivalent (tools/equiv.py level 3: 149 inputs, branch coverage 18/21, incomplete)
// FUN_0021d830 @ 0x0021d830
struct LuaState;

struct FuncState;

struct LexState {
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

struct ExpDesc {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

int __cdecl FUN_0021bbc0(LexState* ls, int* seminfo);
void __cdecl FUN_0021b060(LexState* ls, const char* msg);
const char* __cdecl FUN_0021af00(LexState* ls, int token);
const char* FUN_00216320(LuaState* L, const char* fmt, ...);
int __cdecl FUN_0021ded0(LexState* ls, ExpDesc* v, unsigned int limit);
void __cdecl FUN_00221110(FuncState* fs, ExpDesc* e);
void __cdecl FUN_00221190(FuncState* fs, ExpDesc* e);
void __cdecl FUN_002211e0(FuncState* fs, ExpDesc* e);
void __cdecl FUN_002216e0(FuncState* fs, ExpDesc* v, ExpDesc* key);
void __cdecl FUN_00221360(FuncState* fs, ExpDesc* v, ExpDesc* key);
int __cdecl FUN_002209b0(FuncState* fs, int ts);
// equiv-conv: FUN_0021d790 eax ebx
void FUN_0021d790(LexState* ls, ExpDesc* v);
// equiv-conv: FUN_0021ccb0 eax ebx
void FUN_0021ccb0(LexState* ls, ExpDesc* v);
// equiv-conv: FUN_0021d630 eax stack
void FUN_0021d630(LexState* ls, ExpDesc* f);

// Lua 5.0 primaryexp: a prefix expression followed by any number of field,
// index, method-call and call suffixes. v arrives in eax, ls in esi.
// equiv-conv: FUN_0021d830 eax esi
void FUN_0021d830(ExpDesc* v, LexState* ls)
{
    ExpDesc key;
    ExpDesc method;
    FuncState* fs = ls->fs;

    FUN_0021d790(ls, v);
    for (;;) {
        switch (ls->token) {
        case '.':
            FUN_0021ccb0(ls, v);
            break;
        case '[':
            FUN_00221190(fs, v);
            ls->lastline = ls->linenumber;
            if (ls->lookaheadToken != 0x11f) {
                ls->token = ls->lookaheadToken;
                ls->seminfo = ls->lookaheadSeminfo;
                ls->lookaheadToken = 0x11f;
            } else {
                ls->token = FUN_0021bbc0(ls, &ls->seminfo);
            }
            FUN_0021ded0(ls, &key, 0);
            FUN_002211e0(ls->fs, &key);
            if (ls->token != ']')
                FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected", FUN_0021af00(ls, ']')));
            ls->lastline = ls->linenumber;
            if (ls->lookaheadToken != 0x11f) {
                ls->token = ls->lookaheadToken;
                ls->seminfo = ls->lookaheadSeminfo;
                ls->lookaheadToken = 0x11f;
            } else {
                ls->token = FUN_0021bbc0(ls, &ls->seminfo);
            }
            FUN_002216e0(fs, v, &key);
            break;
        case ':': {
            ls->lastline = ls->linenumber;
            if (ls->lookaheadToken != 0x11f) {
                ls->token = ls->lookaheadToken;
                ls->seminfo = ls->lookaheadSeminfo;
                ls->lookaheadToken = 0x11f;
            } else {
                ls->token = FUN_0021bbc0(ls, &ls->seminfo);
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
                ls->token = FUN_0021bbc0(ls, &ls->seminfo);
            }
            method.k = 4;
            method.info = FUN_002209b0(ls->fs, name);
            method.t = -1;
            method.f = -1;
            FUN_00221360(fs, v, &method);
            FUN_0021d630(ls, v);
            break;
        }
        case '(':
        case '{':
        case 0x11e:
            FUN_00221110(fs, v);
            FUN_0021d630(ls, v);
            break;
        default:
            return;
        }
    }
}
