// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 14/14)
// FUN_00343bb0 @ 0x00343bb0
// FUN_00343bb0 @ 0x00343bb0
// Forward complex FFT driver (Ooura-style cftfsub, float): w (twiddle table) in eax, the data in ecx,
// then n, the bit-reversal table ip and the twiddle count nw on the stack.
// equiv-conv: FUN_003401b0 eax ecx stack
extern "C" void FUN_003401b0(float *a, int n, float *tw);
extern "C" void __cdecl FUN_00343a70(int n, float *a, int nw, float *w);
extern "C" void __cdecl FUN_00343b10(int n, float *a, int nw, float *w);
extern "C" void __cdecl FUN_003431d0(int n, float *a, int nw, float *w);
// equiv-conv: FUN_003430f0 eax esi edx ebx
extern "C" void FUN_003430f0(int n, float *a, float *w, int nw);
// equiv-conv: FUN_0033ef80 ecx stack eax
extern "C" void FUN_0033ef80(int n, int *ip, float *a);
// equiv-conv: FUN_00341bd0 eax ecx
extern "C" void __cdecl FUN_00341bd0(float *, void *);
struct ThisNote_00342800 {
    // equiv-conv: FUN_00342800 ecx eax
    void FUN_00342800(float *a);
};
// equiv-conv: FUN_0033fed0 eax
extern "C" void __cdecl FUN_0033fed0(void *);
// equiv-conv: FUN_003400e0 eax
extern "C" void __cdecl FUN_003400e0(void *);
// equiv-conv: FUN_00342c20 eax
extern "C" void __cdecl FUN_00342c20(void *);

// equiv-conv: FUN_00343bb0 eax ecx stack stack stack
extern "C" void __cdecl FUN_00343bb0(float *w, float *a, int n, int *ip, int nw)
{
    if (n > 0x20) {
        int m = n >> 2;
        FUN_003401b0(a, n, &w[nw - m]);
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
        FUN_0033ef80(n, ip, a);
    } else if (n > 8) {
        if (n == 0x20) {
            FUN_00341bd0(a, (float *)(&w[nw - 8]));
            FUN_0033fed0((float *)a);
        } else {
            ((ThisNote_00342800*)(w))->FUN_00342800(a);
            FUN_003400e0((float *)a);
        }
    } else if (n == 8) {
        FUN_00342c20((float *)a);
    } else if (n == 4) {
        float x0r = a[0] - a[2];
        float x0i = a[1] - a[3];
        a[0] = a[0] + a[2];
        a[1] = a[3] + a[1];
        a[2] = x0r;
        a[3] = x0i;
    }
}
