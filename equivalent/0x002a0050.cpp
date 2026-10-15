// STATUS: equivalent (tools/equiv.py level 3: 2535 inputs, branch coverage 87/90, incomplete)
// FUN_002a0050 @ 0x002a0050
extern int DAT_004cf730;

struct Item {
    void FUN_002a0820(int v);
};

struct Elem {
    float v;
    char pad[0x1c];
};

struct Hdr {
    char pad0[0x10];
    int f10;
    int n;
    void **arr18;
};

struct Pair {
    Hdr *hdr;
    Elem *base;
};

struct A {
    char pad0[0x10];
    int f10;
    int m;
    Item **arr18;
    void FUN_002a0fc0(int idx, void *item);
    void FUN_002a1180(int idx);
};

struct B {
    char pad[4];
};

struct C {
    char pad0[0x18];
    int f18;
    char pad1c[0x34 - 0x1c];
    int f34;
    void FUN_0029e7f0(A *a, B *b, int v);
};

class Skin {
public:
    char pad0[0x10];
    int color;
    char pad14[0x24 - 0x14];
    int f24;
    char pad28[0x3c - 0x28];
    Pair *p3c;
    bool FUN_0029fc00(A *a, B *b, C *c);
    void FUN_0029e640(A *a);
    void FUN_0029e680(A *a);
    float FUN_0029d5d0(B *b, int z);
    void FUN_002a0050(A *a, B *b, C *c);
};

void Skin::FUN_002a0050(A *a, B *b, C *c)
{
    int n = p3c->hdr->n;
    int m = a->m;
    color = DAT_004cf730;
    if (m == 0) {
        if (c == 0)
            return;
        c->f18 = m;
        c->FUN_0029e7f0(a, b, f24);
        c->f34 = DAT_004cf730;
        return;
    }
    if (FUN_0029fc00(a, b, c)) {
        FUN_0029e640(a);
        FUN_0029e680(a);
        return;
    }

    int idx[4];
    if (n <= 4) {
        int i = 0;
        if (m > 0) {
            int lim = m;
            do {
                if (i < n) {
                    Hdr *h = p3c->hdr;
                    if (i < h->f10)
                        a->FUN_002a0fc0(i, h->arr18[i]);
                    else
                        a->FUN_002a0fc0(i, 0);
                } else {
                    int start = i;
                    if (i < m) {
                        do {
                            a->FUN_002a0fc0(i, 0);
                            i++;
                        } while (i < m);
                    }
                    a->FUN_002a1180(start);
                    lim = m;
                }
                i++;
            } while (i < lim);
        }
    } else {
        FUN_0029d5d0(b, 0);
        float S0 = 0.0f, S1 = 0.0f, N = 0.0f, M = 0.0f;
        int iS0 = -1, iS1 = -1, iN = -1, iM = -1;
        Elem *base = p3c->base;
        for (int i = 0; i < n; i++) {
            float x = base[i].v;
            if (!(x <= S0)) {
                M = S0;
                iM = iS0;
                if (!(x <= S1)) {
                    float S1old = S1;
                    iS0 = iS1;
                    if (!(x <= N)) {
                        S1 = N;
                        iS1 = iN;
                        N = x;
                        iN = i;
                    } else {
                        S1 = x;
                        iS1 = i;
                    }
                    S0 = S1old;
                } else {
                    S0 = x;
                    iS0 = i;
                }
            } else {
                if (x > M) {
                    M = x;
                    iM = i;
                }
            }
        }
        idx[0] = iN;
        idx[1] = iS1;
        idx[2] = iS0;
        idx[3] = iM;
        int i = 0;
        if (m > 0) {
            do {
                int e = idx[i];
                if (e != -1) {
                    Hdr *h = p3c->hdr;
                    if (e < h->f10)
                        a->FUN_002a0fc0(e, h->arr18[e]);
                    else
                        a->FUN_002a0fc0(e, 0);
                } else {
                    int start = i + 1;
                    for (; i < m; i++)
                        a->FUN_002a0fc0(i, 0);
                    a->FUN_002a1180(start);
                }
                i++;
            } while (i < m);
        }
    }

    if (c) {
        c->f18 = n;
        c->FUN_0029e7f0(a, b, f24);
        c->f34 = color;
    }
    int cnt = a->m;
    for (int i = 0; i < cnt; i = i + 1) {
        if (i < a->f10) {
            Item *it = a->arr18[i];
            if (it)
                it->FUN_002a0820(1);
        }
        cnt = a->m;
    }
}
