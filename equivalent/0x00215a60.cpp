// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00215a60 @ 0x00215a60
struct Closure_215a60 {
    char pad0[6];
    unsigned char isC;
};

struct TObject_215a60 {
    int tt;
    Closure_215a60 *cl;
};

struct CallInfo_215a60 {
    TObject_215a60 *func;              // 0
    TObject_215a60 *top;               // 4
    const unsigned int *savedpc; // 8
    int nresults;               // 0xc
};

struct LState_215a60 {
    char pad0[8];
    TObject_215a60 *top;               // 8
    char pad0c[8];
    CallInfo_215a60 *ci;               // 0x14
    char pad18[0x10];
    CallInfo_215a60 *base_ci;          // 0x28
    char pad2c[6];
    unsigned char yielded;      // 0x32
};

void __cdecl FUN_00215790(LState_215a60 *L, TObject_215a60 *firstResult);
void __cdecl FUN_00215970(LState_215a60 *L, int nresults, TObject_215a60 *firstResult);
TObject_215a60 *__cdecl FUN_00218350(LState_215a60 *L, int level);

void __cdecl FUN_00215a60(LState_215a60 *L, int *pn)
{
    int n = *pn;
    if (!L->yielded) {
        FUN_00215790(L, L->top - (n + 1));
    } else if (L->ci->func[-1].cl->isC) {
        unsigned int inst = L->ci[-1].savedpc[-1];
        int want = (int)((inst >> 6) & 0x1ff) - 1;
        FUN_00215970(L, want, L->top - n);
        if (want >= 0)
            L->top = L->ci->top;
    }
    L->yielded = 0;
    TObject_215a60 *res = FUN_00218350(L, (int)(L->ci - L->base_ci));
    if (res)
        FUN_00215970(L, -1, res);
}
