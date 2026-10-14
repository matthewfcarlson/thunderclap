// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00215b60 @ 0x00215b60
struct Closure {
    char pad0[6];
    unsigned char isC;
};

struct TObject {
    int tt;
    Closure *cl;
};

struct CallInfo {
    TObject *func;
};

struct LState {
    char pad0[8];
    TObject *top;
    TObject *base;
    char pad10[4];
    CallInfo *ci;
    char pad18[0x16];
    unsigned short nCcalls;
    char pad30[2];
    unsigned char yielded;
};

void __cdecl FUN_00214a90(LState *L, const char *msg);

int __cdecl FUN_00215b60(LState *L, int nresults)
{
    CallInfo *ci = L->ci;
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
