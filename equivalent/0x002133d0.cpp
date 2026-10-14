// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_002133d0 @ 0x002133d0
struct TValue { int tt; int value; };
struct Global { char pad[0x48]; unsigned int GCthreshold; unsigned int nblocks; };
struct State { char pad0[8]; TValue *top; char pad1[4]; Global *g; };
void __cdecl FUN_00217440(State *L);
int __cdecl FUN_00219430(State *L, const char *s, unsigned int len);

void FUN_002133d0(State *L, const char *s)
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
    TValue *t = L->top;
    t->value = FUN_00219430(L, s, len);
    t->tt = 4;
    L->top++;
}
