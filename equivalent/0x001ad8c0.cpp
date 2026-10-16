// STATUS: equivalent (tools/equiv.py level 3: 2594 inputs, branch coverage 79/80, incomplete)
// FUN_001ad8c0 @ 0x001ad8c0
extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
    void FUN_0022d180();
};

struct Seg {
    V3 a;
    V3 b;
    float FUN_0022ff50(const V3 *p);
};

struct Node {
    int nbr[3];
    char pad0c[3];
    unsigned char b0f;
};

struct Pool {
    Node *FUN_001b5800(int idx);
    V3 *FUN_001b5a20(V3 *out, int idx);
    char FUN_001b65f0(int a, int k);
};

char FUN_001ad730(int idx, struct Graph *g);
void FUN_000658d0(V3 *c, V3 *q, V3 *p, float *out);

struct Graph {
    Pool *p0;
    char pad4[4];
    unsigned int f8;
    int F(V3 *Q, V3 *P, int c, float minD, float maxD, int a6, char maximize, char useDist, int n, int a10,
          char fallback, float a12, float a13);
};

int Graph::F(V3 *Q, V3 *P, int c, float minD, float maxD, int a6, char maximize, char useDist, int n, int a10,
             char fallback, float a12, float a13)
{
    struct Frame {
        float dist;
        int bestIdx;
        float dotp;
        V3 NP;
        int thisSpill;
        int p0Spill;
        int k;
        float bestA;
        Node *nb;
        float t3c;
        float bestB;
        float bestC;
        float bestD;
        float absBest;
        int j;
        V3 VQ;
        Seg seg;
        float out78;
        float bestE;
        V3 tmp80;
        float t8c;
        V3 tmp90;
    } fr;

    fr.thisSpill = (int)this;
    Node *n0 = p0->FUN_001b5800(c);
    Pool *pool = p0;
    int ebx = 0;
    fr.bestIdx = c;
    fr.out78 = 0;
    fr.bestE = 0;
    fr.bestB = 0;
    fr.bestC = 0;
    fr.absBest = 0;
    fr.p0Spill = (int)pool;
    if (!n0)
        return 0;
    V3 *cp = pool->FUN_001b5a20(&fr.tmp80, c);
    float dx0 = cp->x - P->x;
    float dy0 = cp->y - P->y;
    float dz0 = cp->z - P->z;
    fr.bestA = (float)sqrt(dz0 * dz0 + dy0 * dy0 + dx0 * dx0);
    fr.VQ.x = P->x - Q->x;
    fr.VQ.y = P->y - Q->y;
    fr.VQ.z = P->z - Q->z;
    pool->FUN_001b5a20(&fr.NP, c);
    fr.NP.FUN_0022d180();
    fr.VQ.FUN_0022d180();
    fr.bestD = fr.NP.z * fr.VQ.z + fr.NP.y * fr.VQ.y + fr.VQ.x * fr.NP.x;
    fr.j = 0;
    bool doLoop = n > 0;
    if (doLoop) {
        do {
            int esi = c;
            if (fr.j > 0 && fr.bestIdx == esi && ebx != 0)
                fr.nb = p0->FUN_001b5800(ebx);
            else
                fr.nb = p0->FUN_001b5800(fr.bestIdx);
            fr.k = 0;
            do {
                int cand = fr.nb->nbr[fr.k];
                if (cand == -1) {
                    if (!p0->FUN_001b65f0(c, fr.k))
                        goto next;
                    cand = fr.nb->nbr[fr.k];
                    if (cand == -1)
                        goto next;
                }
                {
                    Node *node = p0->FUN_001b5800(cand);
                    if (!node) {
                        fr.nb->nbr[fr.k] = -1;
                        goto next;
                    }
                    if (c == cand)
                        goto next;
                    if (node->b0f > f8) {
                        if (!FUN_001ad730(cand, this))
                            goto next;
                    }
                    V3 *cp2 = pool->FUN_001b5a20(&fr.tmp80, cand);
                    fr.NP.x = cp2->x;
                    fr.NP.y = cp2->y;
                    float nz = cp2->z;
                    float ddx = fr.NP.x - P->x;
                    float ddy = fr.NP.y - P->y;
                    float ddz = nz - P->z;
                    fr.dist = (float)sqrt(ddz * ddz + ddy * ddy + ddx * ddx);
                    fr.NP.x = fr.NP.x - Q->x;
                    fr.NP.y = fr.NP.y - Q->y;
                    fr.NP.z = nz - Q->z;
                    fr.NP.FUN_0022d180();
                    fr.VQ.FUN_0022d180();
                    fr.dotp = fr.NP.z * fr.VQ.z + fr.NP.y * fr.VQ.y + fr.VQ.x * fr.NP.x;
                    if (fr.dist < minD)
                        goto next;
                    if (fr.dist > maxD)
                        goto next;
                    fr.seg.a.x = fr.NP.x;
                    fr.seg.a.y = fr.NP.y;
                    fr.seg.a.z = fr.NP.z;
                    fr.seg.b.x = Q->x;
                    fr.seg.b.y = Q->y;
                    fr.seg.b.z = Q->z;
                    float d = fr.seg.FUN_0022ff50(P);
                    if (a13 != 0.0f && d < a13)
                        goto next;
                    if (a12 != 0.0f) {
                        V3 *c3 = pool->FUN_001b5a20(&fr.tmp90, cand);
                        FUN_000658d0(c3, Q, P, &fr.out78);
                        fr.t8c = fr.out78 - a12;
                        unsigned int bits = *(unsigned int *)&fr.t8c & 0x7fffffff;
                        *(unsigned int *)&fr.t3c = bits;
                        if (fr.absBest == 0.0f || fr.t3c < fr.absBest) {
                            *(unsigned int *)&fr.absBest = bits;
                            fr.bestIdx = cand;
                            goto next;
                        }
                        if (ebx != 0 && !(fr.t3c < fr.bestE))
                            goto next;
                        fr.bestE = fr.t3c;
                        ebx = cand;
                        goto next;
                    }
                    float key;
                    float *best;
                    float *second;
                    if (useDist) {
                        key = fr.dist;
                        best = &fr.bestA;
                        second = &fr.bestB;
                    } else {
                        key = fr.dotp;
                        best = &fr.bestD;
                        second = &fr.bestC;
                    }
                    if (maximize) {
                        if (key > *best) {
                            *best = key;
                            fr.bestIdx = cand;
                            goto next;
                        }
                        if (ebx != 0 && !(key > *second))
                            goto next;
                    } else {
                        if (key < *best) {
                            *best = key;
                            fr.bestIdx = cand;
                            goto next;
                        }
                        if (ebx != 0 && !(key < *second))
                            goto next;
                    }
                    *second = key;
                    ebx = cand;
                }
            next:
                fr.k++;
            } while ((unsigned int)fr.k < 3);
            fr.j++;
        } while (fr.j < n);
    }
    if (!doLoop || fr.bestIdx == c) {
        if (fallback) {
            V3 *cp3 = pool->FUN_001b5a20(&fr.tmp90, ebx);
            fr.seg.a.x = cp3->x;
            fr.seg.a.y = cp3->y;
            fr.seg.a.z = cp3->z;
            fr.seg.b.x = Q->x;
            fr.seg.b.y = Q->y;
            fr.seg.b.z = Q->z;
            fr.seg.FUN_0022ff50(P);
            return ebx;
        }
    }
    int res = fr.bestIdx;
    V3 *cp4 = pool->FUN_001b5a20(&fr.tmp90, res);
    fr.seg.a.x = cp4->x;
    fr.seg.a.y = cp4->y;
    fr.seg.a.z = cp4->z;
    fr.seg.b.x = Q->x;
    fr.seg.b.y = Q->y;
    fr.seg.b.z = Q->z;
    fr.seg.FUN_0022ff50(P);
    return res;
}
