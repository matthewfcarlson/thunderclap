// STATUS: equivalent (tools/equiv.py level 3: 134 inputs, branch coverage 25/28, incomplete)
// FUN_003431d0 @ 0x003431d0
// FUN_003431d0 @ 0x003431d0
// equiv-conv: FUN_00341290 eax stack stack
void FUN_00341290(float *a, int n, float *w);
// equiv-conv: FUN_00341660 eax stack stack
void FUN_00341660(float *a, int n, float *w);
// equiv-conv: FUN_00341bd0 eax ecx
void FUN_00341bd0(float *a, float *w);
// equiv-conv: FUN_00342180 eax ecx
void FUN_00342180(float *a, float *w);
struct ThisNote_00342800 {
    // equiv-conv: FUN_00342800 ecx eax
    void FUN_00342800(float *a);
};
struct ThisNote_003429f0 {
    // equiv-conv: FUN_003429f0 ecx eax
    void FUN_003429f0(float *a);
};

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
                        FUN_00341bd0(d0, w8);
                        FUN_00342180(d0 + 0x20, w32);
                        FUN_00341bd0(d0 + 0x40, w8);
                        FUN_00341bd0(d0 + 0x60, w8);
                    } else {
                        ((ThisNote_00342800*)(w16))->FUN_00342800(d0);
                        ((ThisNote_003429f0*)(w16))->FUN_003429f0(d0 + 0x10);
                        ((ThisNote_00342800*)(w16))->FUN_00342800(d0 + 0x20);
                        ((ThisNote_00342800*)(w16))->FUN_00342800(d0 + 0x30);
                    }
                    FUN_00341660(d1, l, t1);
                    if (l == 0x80) {
                        FUN_00341bd0(d1, w8);
                        FUN_00342180(d1 + 0x20, w32);
                        FUN_00341bd0(d1 + 0x40, w8);
                        FUN_00342180(d1 + 0x60, w32);
                    } else {
                        ((ThisNote_00342800*)(w16))->FUN_00342800(d1);
                        ((ThisNote_003429f0*)(w16))->FUN_003429f0(d1 + 0x10);
                        ((ThisNote_00342800*)(w16))->FUN_00342800(d1 + 0x20);
                        ((ThisNote_003429f0*)(w16))->FUN_003429f0(d1 + 0x30);
                    }
                    FUN_00341290(d2, l, t2);
                    if (l == 0x80) {
                        FUN_00341bd0(d2, w8);
                        FUN_00342180(d2 + 0x20, w32);
                        FUN_00341bd0(d2 + 0x40, w8);
                        FUN_00341bd0(d2 + 0x60, w8);
                    } else {
                        ((ThisNote_00342800*)(w16))->FUN_00342800(d2);
                        ((ThisNote_003429f0*)(w16))->FUN_003429f0(d2 + 0x10);
                        ((ThisNote_00342800*)(w16))->FUN_00342800(d2 + 0x20);
                        ((ThisNote_00342800*)(w16))->FUN_00342800(d2 + 0x30);
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
        FUN_00341bd0(e, &w[nw - 8]);
        FUN_00342180(e + 0x20, &w[nw - 32]);
        FUN_00341bd0(e + 0x40, &w[nw - 8]);
        FUN_00341bd0(e + 0x60, &w[nw - 8]);
    } else {
        ((ThisNote_00342800*)(&w[nw - 16]))->FUN_00342800(e);
        ((ThisNote_003429f0*)(&w[nw - 16]))->FUN_003429f0(e + 0x10);
        ((ThisNote_00342800*)(&w[nw - 16]))->FUN_00342800(e + 0x20);
        ((ThisNote_00342800*)(&w[nw - 16]))->FUN_00342800(e + 0x30);
    }
}
