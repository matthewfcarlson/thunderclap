// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 15/16, incomplete)
// FUN_00217d80 @ 0x00217d80
// Lua 5.0 luaV_lessequal
struct TString;
struct TObject_217d80 {
    int tt;
    union {
        float n;
        TString *s;
    };
};

struct LState;

int __cdecl FUN_00214d80(LState *L, const TObject_217d80 *a, const TObject_217d80 *b);
// equiv-conv: FUN_00217be0 eax stack stack ebx
int __cdecl FUN_00217be0(LState *L, const TObject_217d80 *a, int event, const TObject_217d80 *b);
// equiv-conv: FUN_00217c80 ecx eax
int FUN_00217c80(const TString *a, const TString *b);

// equiv-conv: FUN_00217d80 edi esi stack
int FUN_00217d80(const TObject_217d80 *l, const TObject_217d80 *r, LState *L)
{
    if (l->tt != r->tt)
        return FUN_00214d80(L, l, r);
    if (l->tt == 3)
        return l->n <= r->n;
    if (l->tt == 4)
        return FUN_00217c80(l->s, r->s) <= 0;
    int res = FUN_00217be0(L, l, 0xc, r);
    if (res != -1)
        return res;
    res = FUN_00217be0(L, r, 0xb, l);
    if (res != -1)
        return res == 0;
    return FUN_00214d80(L, l, r);
}
