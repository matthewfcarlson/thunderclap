// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00343b10 @ 0x00343b10
// Recursive split-radix float FFT pass (cftrec2 of an Ooura-style FFT).
// equiv-conv: FUN_00341660 eax stack stack
void FUN_00341660(float *a, int n, float *w);
// equiv-conv: FUN_003435d0 eax stack stack stack
void __cdecl FUN_003435d0(int n, float *a, int nw, float *w);
void __cdecl FUN_00343a70(int n, float *a, int nw, float *w);

void __cdecl FUN_00343b10(int n, float *a, int nw, float *w)
{
    FUN_00341660(a, n, &w[nw - n]);
    while (n > 0x200) {
        int m = n >> 2;
        FUN_00343a70(m, a, nw, w);
        FUN_00343b10(m, a + m, nw, w);
        FUN_00343a70(m, a + 2 * m, nw, w);
        a += 3 * m;
        n = m;
        FUN_00341660(a, n, &w[nw - n]);
    }
    FUN_003435d0(n, a, nw, w);
}
