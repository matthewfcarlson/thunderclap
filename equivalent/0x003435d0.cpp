// STATUS: equivalent (tools/equiv.py level 3: 207 inputs, branch coverage 31/36, incomplete)
// FUN_003435d0 @ 0x003435d0
// split-radix float FFT pass (Ooura-style cftrec4 middle): n in eax, then (a, nw, w) on the stack
// equiv-conv: FUN_00341290 eax stack stack
extern void __cdecl FUN_00341290(float *a, int l, float *w);
// equiv-conv: FUN_00341660 eax stack stack
extern void __cdecl FUN_00341660(float *a, int l, float *w);
// equiv-conv: FUN_00341bd0 ecx eax
extern void __cdecl FUN_00341bd0(float *w, float *a);
// equiv-conv: FUN_00342180 ecx eax
extern void __cdecl FUN_00342180(float *w, float *a);
// equiv-conv: FUN_00342800 ecx eax
extern void __cdecl FUN_00342800(float *w, float *a);
// equiv-conv: FUN_003429f0 ecx eax
extern void __cdecl FUN_003429f0(float *w, float *a);

// equiv-conv: FUN_003435d0 eax stack stack stack
void __cdecl FUN_003435d0(int n, float *a, int nw, float *w)
{
    int m = n >> 1;
    int l = n >> 2;
    int j, k;

    while (l > 0x80) {
        for (k = l; k < m; k <<= 2) {
            for (j = k - l; j < m; j += 2 * k) {
                FUN_00341290(&a[j], l, &w[nw - (l >> 1)]);
                FUN_00341290(&a[j + m], l, &w[nw - (l >> 1)]);
            }
            for (j = 2 * k - l; j < m; j += 4 * k) {
                FUN_00341660(&a[j], l, &w[nw - l]);
                FUN_00341660(&a[j + m], l, &w[nw - l]);
            }
        }
        l >>= 2;
    }
    for (k = l; k < m; k <<= 2) {
        for (j = k - l; j < m; j += 2 * k) {
            float *p = &a[j];
            FUN_00341290(p, l, &w[nw - (l >> 1)]);
            if (l == 0x80) {
                FUN_00341bd0(&w[nw - 8], p);
                FUN_00342180(&w[nw - 0x20], p + 0x20);
                FUN_00341bd0(&w[nw - 8], p + 0x40);
                FUN_00341bd0(&w[nw - 8], p + 0x60);
            } else {
                FUN_00342800(&w[nw - 0x10], p);
                FUN_003429f0(&w[nw - 0x10], p + 0x10);
                FUN_00342800(&w[nw - 0x10], p + 0x20);
                FUN_00342800(&w[nw - 0x10], p + 0x30);
            }
            p = &a[j + m];
            FUN_00341290(p, l, &w[nw - (l >> 1)]);
            if (l == 0x80) {
                FUN_00341bd0(&w[nw - 8], p);
                FUN_00342180(&w[nw - 0x20], p + 0x20);
                FUN_00341bd0(&w[nw - 8], p + 0x40);
                FUN_00341bd0(&w[nw - 8], p + 0x60);
            } else {
                FUN_00342800(&w[nw - 0x10], p);
                FUN_003429f0(&w[nw - 0x10], p + 0x10);
                FUN_00342800(&w[nw - 0x10], p + 0x20);
                FUN_00342800(&w[nw - 0x10], p + 0x30);
            }
        }
        for (j = 2 * k - l; j < m; j += 4 * k) {
            float *p = &a[j];
            FUN_00341660(p, l, &w[nw - l]);
            if (l == 0x80) {
                FUN_00341bd0(&w[nw - 8], p);
                FUN_00342180(&w[nw - 0x20], p + 0x20);
                FUN_00341bd0(&w[nw - 8], p + 0x40);
                FUN_00342180(&w[nw - 0x20], p + 0x60);
            } else {
                FUN_00342800(&w[nw - 0x10], p);
                FUN_003429f0(&w[nw - 0x10], p + 0x10);
                FUN_00342800(&w[nw - 0x10], p + 0x20);
                FUN_003429f0(&w[nw - 0x10], p + 0x30);
            }
            p = &a[j + m];
            FUN_00341660(p, l, &w[nw - l]);
            if (l == 0x80) {
                FUN_00341bd0(&w[nw - 8], p);
                FUN_00342180(&w[nw - 0x20], p + 0x20);
                FUN_00341bd0(&w[nw - 8], p + 0x40);
                FUN_00342180(&w[nw - 0x20], p + 0x60);
            } else {
                FUN_00342800(&w[nw - 0x10], p);
                FUN_003429f0(&w[nw - 0x10], p + 0x10);
                FUN_00342800(&w[nw - 0x10], p + 0x20);
                FUN_003429f0(&w[nw - 0x10], p + 0x30);
            }
        }
    }
}
