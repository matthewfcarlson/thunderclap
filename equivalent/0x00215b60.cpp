// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00215b60 @ 0x00215b60
struct Closure_215b60 {
    char pad0[6];
    unsigned char isC;
};

struct TObject_215b60 {
    int tt;
    Closure_215b60 *cl;
};

struct CallInfo_215b60 {
    TObject_215b60 *func;
};

struct LState_215b60 {
    char pad0[8];
    TObject_215b60 *top;
    TObject_215b60 *base;
    char pad10[4];
    CallInfo_215b60 *ci;
    char pad18[0x16];
    unsigned short nCcalls;
    char pad30[2];
    unsigned char yielded;
};

void __cdecl FUN_00214a90(LState_215b60 *L, const char *msg);

int __cdecl FUN_00215b60(LState_215b60 *L, int nresults)
{
    CallInfo_215b60 *ci = L->ci;
    if (L->nCcalls > 0)
        FUN_00214a90(L, "attempt to yield across metamethod/C-call boundary");
    if (ci->func[-1].cl->isC) {
        if (L->top - nresults > L->base) {
            for (int i = 0; i < nresults; i++)
                L->base[i] = L->top[i - nresults];
            L->top = L->base + nresults;
        }
    }
    L->yielded = 1;
    return -1;
}
