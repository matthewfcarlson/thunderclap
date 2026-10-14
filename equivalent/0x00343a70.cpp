// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00343a70 @ 0x00343a70
// Recursive split-radix float FFT pass (cftrec1 of an Ooura-style FFT).
// equiv-conv: FUN_00341290 eax stack stack
void FUN_00341290(float *a, int n, float *w);
void __cdecl FUN_00343b10(int n, float *a, int nw, float *w);
void __cdecl FUN_003431d0(int n, float *a, int nw, float *w);

void __cdecl FUN_00343a70(int n, float *a, int nw, float *w)
{
    int m = n >> 2;
    FUN_00341290(a, n, &w[nw - 2 * m]);
    while (n > 0x200) {
        FUN_00343a70(m, a, nw, w);
        FUN_00343b10(m, a + m, nw, w);
        FUN_00343a70(m, a + 2 * m, nw, w);
        a += 3 * m;
        n = m;
        m = n >> 2;
        FUN_00341290(a, n, &w[nw - 2 * m]);
    }
    FUN_003431d0(n, a, nw, w);
}
