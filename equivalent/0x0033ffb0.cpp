// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0033ffb0 @ 0x0033ffb0
// equiv-conv: FUN_0033ffb0 eax
union Pair_33ffb0 {
    unsigned w[2];
    float f[2];
};

struct Table_33ffb0 {
    char head[8];
    Pair_33ffb0 p[15];
};

// Permutes the fifteen 8-byte entries that start at +8.  Entries 2 and 0 are
// moved through the FPU (float copies), all others as raw words.
void FUN_0033ffb0(Table_33ffb0* t)
{
    float f2a = t->p[2].f[0];
    float f2b = t->p[2].f[1];
    float f0a = t->p[0].f[0];
    float f0b = t->p[0].f[1];
    Pair_33ffb0 old[15];
    for (int i = 0; i < 15; i++) {
        old[i].w[0] = t->p[i].w[0];
        old[i].w[1] = t->p[i].w[1];
    }
    t->p[3].f[0] = f2a;
    t->p[3].f[1] = f2b;
    t->p[7].f[0] = f0a;
    t->p[7].f[1] = f0b;
    t->p[0] = old[14];
    t->p[1] = old[6];
    t->p[2] = old[10];
    t->p[4] = old[12];
    t->p[5] = old[4];
    t->p[6] = old[8];
    t->p[8] = old[13];
    t->p[9] = old[5];
    t->p[10] = old[9];
    t->p[11] = old[1];
    t->p[12] = old[11];
    t->p[13] = old[3];
    t->p[14] = old[7];
}
