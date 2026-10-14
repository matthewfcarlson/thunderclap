// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_00343ce0 @ 0x00343ce0
// Backward complex FFT driver (Ooura-style cftbsub, float): w (twiddle table) in eax, the data in ecx,
// then n, the bit-reversal table ip and the twiddle count nw on the stack.
// equiv-conv: FUN_00340a10 eax ecx stack
void FUN_00340a10(float *a, int n, float *tw);
void __cdecl FUN_00343a70(int n, float *a, int nw, float *w);
void __cdecl FUN_00343b10(int n, float *a, int nw, float *w);
void __cdecl FUN_003431d0(int n, float *a, int nw, float *w);
// equiv-conv: FUN_003430f0 eax esi edx ebx
void FUN_003430f0(int n, float *a, float *w, int nw);
// equiv-conv: FUN_0033f6d0 ecx stack eax
void FUN_0033f6d0(int n, int *ip, float *a);
// equiv-conv: FUN_00341bd0 ecx eax
void FUN_00341bd0(float *w, float *a);
// equiv-conv: FUN_00342800 ecx eax
void FUN_00342800(float *w, float *a);
// equiv-conv: FUN_0033ffb0 eax
void FUN_0033ffb0(float *a);
// equiv-conv: FUN_00340130 eax
void FUN_00340130(float *a);
// equiv-conv: FUN_00342cc0 eax
void FUN_00342cc0(float *a);

// equiv-conv: FUN_00343ce0 eax ecx stack stack stack
void __cdecl FUN_00343ce0(float *w, float *a, int n, int *ip, int nw)
{
    if (n > 0x20) {
        int m = n >> 2;
        FUN_00340a10(a, n, &w[nw - m]);
        if (n > 0x200) {
            FUN_00343a70(m, a, nw, w);
            FUN_00343b10(m, a + m, nw, w);
            FUN_00343a70(m, a + 2 * m, nw, w);
            FUN_00343a70(m, a + 3 * m, nw, w);
        } else if (m > 0x20) {
            FUN_003431d0(n, a, nw, w);
        } else {
            FUN_003430f0(n, a, w, nw);
        }
        FUN_0033f6d0(n, ip, a);
    } else if (n > 8) {
        if (n == 0x20) {
            FUN_00341bd0(&w[nw - 8], a);
            FUN_0033ffb0(a);
        } else {
            FUN_00342800(w, a);
            FUN_00340130(a);
        }
    } else if (n == 8) {
        FUN_00342cc0(a);
    } else if (n == 4) {
        float x0r = a[0] - a[2];
        float x0i = a[1] - a[3];
        a[0] = a[0] + a[2];
        a[1] = a[3] + a[1];
        a[2] = x0r;
        a[3] = x0i;
    }
}
