// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 11/12, incomplete)
// FUN_00217cf0 @ 0x00217cf0
struct TString;
struct TObject_217cf0 {
    int tt;
    union {
        float n;
        TString *s;
    };
};

struct LState;

int __cdecl FUN_00214d80(LState *L, const TObject_217cf0 *a, const TObject_217cf0 *b);
// equiv-conv: FUN_00217be0 eax stack stack ebx
int __cdecl FUN_00217be0(LState *L, const TObject_217cf0 *a, int event, const TObject_217cf0 *b);
// equiv-conv: FUN_00217c80 ecx eax
int FUN_00217c80(const TString *a, const TString *b);

int FUN_00217cf0(LState *L, const TObject_217cf0 *l, const TObject_217cf0 *r)
{
    if (l->tt != r->tt)
        return FUN_00214d80(L, l, r);
    if (l->tt == 3)
        return l->n < r->n;
    if (l->tt == 4)
        return FUN_00217c80(l->s, r->s) < 0;
    int res = FUN_00217be0(L, l, 0xb, r);
    if (res == -1)
        return FUN_00214d80(L, l, r);
    return res;
}
