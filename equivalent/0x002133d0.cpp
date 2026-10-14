// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_002133d0 @ 0x002133d0
struct TValue_2133d0 { int tt; int value; };
struct Global_2133d0 { char pad[0x48]; unsigned int GCthreshold; unsigned int nblocks; };
struct State_2133d0 { char pad0[8]; TValue_2133d0 *top; char pad1[4]; Global_2133d0 *g; };
void __cdecl FUN_00217440(State_2133d0 *L);
int __cdecl FUN_00219430(State_2133d0 *L, const char *s, unsigned int len);

void FUN_002133d0(State_2133d0 *L, const char *s)
{
    if (s == 0) {
        L->top->tt = 0;
        L->top++;
        return;
    }
    unsigned int len = 0;
    while (s[len] != 0)
        len++;
    if (L->g->nblocks >= L->g->GCthreshold)
        FUN_00217440(L);
    TValue_2133d0 *t = L->top;
    t->value = FUN_00219430(L, s, len);
    t->tt = 4;
    L->top++;
}
