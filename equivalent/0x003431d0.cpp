// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 25/28, incomplete)
// FUN_003431d0 @ 0x003431d0
// equiv-conv: FUN_00341290 eax stack stack
void FUN_00341290(float *a, int n, float *w);
// equiv-conv: FUN_00341660 eax stack stack
void FUN_00341660(float *a, int n, float *w);
// equiv-conv: FUN_00341bd0 ecx eax
void FUN_00341bd0(float *w, float *a);
// equiv-conv: FUN_00342180 ecx eax
void FUN_00342180(float *w, float *a);
// equiv-conv: FUN_00342800 ecx eax
void FUN_00342800(float *w, float *a);
// equiv-conv: FUN_003429f0 ecx eax
void FUN_003429f0(float *w, float *a);

void FUN_003431d0(int n, float *b, int nw, float *w)
{
    int l = n >> 2;

    if (l > 0x80) {
        do {
            int m = l;
            if (l < n) {
                do {
                    int idx = m - l;
                    if (idx < n) {
                        float *t1 = &w[nw - l];
                        float *t2 = &w[nw - (l >> 1)];
                        float *d0 = &b[idx];
                        float *d1 = &b[idx + m];
                        float *d2 = &b[idx + 2 * m];
                        do {
                            FUN_00341290(d0, l, t2);
                            FUN_00341660(d1, l, t1);
                            FUN_00341290(d2, l, t2);
                            idx += 4 * m;
                            d0 += 4 * m;
                            d1 += 4 * m;
                            d2 += 4 * m;
                        } while (idx < n);
                    }
                    m *= 4;
                } while (m < n);
            }
            FUN_00341290(&b[n - l], l, &w[nw - (l >> 1)]);
            l >>= 2;
        } while (l > 0x80);
    }

    int m = l;
    if (l < n) {
        do {
            int idx = m - l;
            if (idx < n) {
                float *t1 = &w[nw - l];
                float *t2 = &w[nw - (l >> 1)];
                float *w8 = &w[nw - 8];
                float *w16 = &w[nw - 16];
                float *w32 = &w[nw - 32];
                float *d0 = &b[idx];
                float *d1 = &b[idx + m];
                float *d2 = &b[idx + 2 * m];
                do {
                    FUN_00341290(d0, l, t2);
                    if (l == 0x80) {
                        FUN_00341bd0(w8, d0);
                        FUN_00342180(w32, d0 + 0x20);
                        FUN_00341bd0(w8, d0 + 0x40);
                        FUN_00341bd0(w8, d0 + 0x60);
                    } else {
                        FUN_00342800(w16, d0);
                        FUN_003429f0(w16, d0 + 0x10);
                        FUN_00342800(w16, d0 + 0x20);
                        FUN_00342800(w16, d0 + 0x30);
                    }
                    FUN_00341660(d1, l, t1);
                    if (l == 0x80) {
                        FUN_00341bd0(w8, d1);
                        FUN_00342180(w32, d1 + 0x20);
                        FUN_00341bd0(w8, d1 + 0x40);
                        FUN_00342180(w32, d1 + 0x60);
                    } else {
                        FUN_00342800(w16, d1);
                        FUN_003429f0(w16, d1 + 0x10);
                        FUN_00342800(w16, d1 + 0x20);
                        FUN_003429f0(w16, d1 + 0x30);
                    }
                    FUN_00341290(d2, l, t2);
                    if (l == 0x80) {
                        FUN_00341bd0(w8, d2);
                        FUN_00342180(w32, d2 + 0x20);
                        FUN_00341bd0(w8, d2 + 0x40);
                        FUN_00341bd0(w8, d2 + 0x60);
                    } else {
                        FUN_00342800(w16, d2);
                        FUN_003429f0(w16, d2 + 0x10);
                        FUN_00342800(w16, d2 + 0x20);
                        FUN_00342800(w16, d2 + 0x30);
                    }
                    idx += 4 * m;
                    d0 += 4 * m;
                    d1 += 4 * m;
                    d2 += 4 * m;
                } while (idx < n);
            }
            m *= 4;
        } while (m < n);
    }

    float *e = &b[n - l];
    FUN_00341290(e, l, &w[nw - (l >> 1)]);
    if (l == 0x80) {
        FUN_00341bd0(&w[nw - 8], e);
        FUN_00342180(&w[nw - 32], e + 0x20);
        FUN_00341bd0(&w[nw - 8], e + 0x40);
        FUN_00341bd0(&w[nw - 8], e + 0x60);
    } else {
        FUN_00342800(&w[nw - 16], e);
        FUN_003429f0(&w[nw - 16], e + 0x10);
        FUN_00342800(&w[nw - 16], e + 0x20);
        FUN_00342800(&w[nw - 16], e + 0x30);
    }
}
