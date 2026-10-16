// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 60/64, incomplete)
// FUN_0007a420 @ 0x0007a420
#include "decls/data/game/unknown.h"

struct V3_7a420 {
    float x, y, z;
};

struct Rng_7a420 {
    unsigned int s0;
    unsigned int s1;
    int FUN_00011330(int maxValue);
};

struct Cell_7a420 {
    float x0;
    float pad04;
    float z0;
    float x1;
    float pad10;
    float z1;
    char pad18[4];
    int f1c;
    char pad20[0xc];
    int state;
    int arr[4];
    char pad40[4];
    char active;
    char pad45[3];
};

struct Probe_7a420 {
    void FUN_00059a50(V3_7a420 *out);
};

struct Actor_7a420 {
    char pad00[0x10];
    Probe_7a420 *probe;
    void FUN_00035660(V3_7a420 *out);
};

struct Ctx_7a420 {
    char pad00[0x124];
    Actor_7a420 *actor;
};

struct Owner_7a420 {
    char pad00[0x20];
    Ctx_7a420 *ctx;
};

Rng_7a420 *FUN_000964d0();

class Grid_7a420 {
public:
    char pad0000[0x1904];
    Cell_7a420 cells[98];
    char pad3494[0x382c - 0x3494];
    Owner_7a420 *owner;
    char FUN_0007a420(int *outRow, int *outCol, int *outSlot, int *outFlag);
};

char Grid_7a420::FUN_0007a420(int *outRow, int *outCol, int *outSlot, int *outFlag)
{
    struct Frame {
        Grid_7a420 *self;
        int row;
        int bestFlag;
        int n;
        int k;
        float u0;
        float pad28;
        float u2;
        float t0;
        float pad34;
        float t2;
        V3_7a420 B;
        int start;
        V3_7a420 A;
        int flags[14];
        int cand[14];
    } fr;

    fr.self = this;
    Actor_7a420 *actor = owner->ctx->actor;
    actor->probe->FUN_00059a50(&fr.A);
    actor->FUN_00035660(&fr.B);

    Rng_7a420 *r0 = (*(Rng_7a420**)&DAT_004e5acc);
    r0->s0 = (r0->s0 & 0xffff) * 0x9069 + (r0->s0 >> 16);
    r0->s1 = (r0->s1 & 0xffff) * 0x4650 + (r0->s1 >> 16);
    unsigned int v = (r0->s0 << 16) + (r0->s1 & 0xffff);
    fr.start = (int)(v % 7);
    fr.k = 0;
    for (;;) {
        fr.row = (fr.k + fr.start) % 7;
        Cell_7a420 *row0 = &cells[fr.row * 14];
        if (row0->f1c > 0) {
            int n = 0;
            for (int j = 0; j < 14; j++) {
                Cell_7a420 *c = &row0[j];
                if (!c->active)
                    continue;
                if (c->state >= 4)
                    continue;
                fr.t0 = fr.A.x - c->x0;
                double t2x = fr.A.z - c->z0;
                fr.t2 = (float)t2x;
                double d0 = t2x * fr.t2 + fr.t0 * fr.t0;
                bool b4900 = d0 < 4900.0f;
                bool b2500 = d0 < 2500.0f;
                fr.u0 = fr.A.x - c->x1;
                double u2x = fr.A.z - c->z1;
                fr.u2 = (float)u2x;
                double d1 = u2x * fr.u2 + fr.u0 * fr.u0;
                bool c4900 = d1 < 4900.0f;
                bool c2500 = d1 < 2500.0f;
                if (b4900 && !b2500 && c2500) {
                    double dot = fr.B.z * fr.t2 + fr.t0 * fr.B.x + fr.B.y * 0.0f;
                    int flag;
                    if (!(dot <= 0.0))
                        flag = 0;
                    else if (FUN_000964d0()->FUN_00011330(1))
                        flag = 1;
                    else
                        flag = 0;
                    fr.flags[n] = flag;
                    fr.cand[n] = j;
                    n++;
                } else if (c4900 && !c2500 && b2500) {
                    double dot = fr.B.z * fr.u2 + fr.u0 * fr.B.x + fr.B.y * 0.0f;
                    int flag;
                    if (!(dot <= 0.0))
                        flag = 1;
                    else if (FUN_000964d0()->FUN_00011330(1))
                        flag = 0;
                    else
                        flag = 1;
                    fr.flags[n] = flag;
                    fr.cand[n] = j;
                    n++;
                }
            }
            fr.n = n;
            if (n != 0) {
                int best = 5;
                int bi = -1;
                fr.bestFlag = 0;
                for (int m = 0; m < n; m++) {
                    int ci = fr.cand[m];
                    int st = cells[ci + fr.row * 14].state;
                    if (st < best) {
                        bi = ci;
                        fr.bestFlag = fr.flags[m];
                        best = st;
                    }
                }
                if (bi != -1) {
                    int best2 = 2;
                    int bj = -1;
                    Rng_7a420 *rr = FUN_000964d0();
                    rr->s0 = (rr->s0 & 0xffff) * 0x9069 + (rr->s0 >> 16);
                    unsigned int b = (rr->s1 & 0xffff) * 0x4650 + (rr->s1 >> 16);
                    rr->s1 = b;
                    int k = (int)(b & 3);
                    Cell_7a420 *cc = &cells[bi + fr.row * 14];
                    if (cc->arr[k] < best2) {
                        best2 = cc->arr[0];
                        bj = 0;
                    }
                    k = (k + 1) % 4;
                    if (cc->arr[k] < best2) {
                        best2 = cc->arr[1];
                        bj = 1;
                    }
                    k = (k + 1) % 4;
                    if (cc->arr[k] < best2) {
                        best2 = cc->arr[2];
                        bj = 2;
                    }
                    k = (k + 1) % 4;
                    if (cc->arr[k] < best2)
                        bj = 3;
                    if (bj != -1) {
                        *outRow = fr.row;
                        *outCol = bi;
                        *outSlot = bj;
                        *outFlag = fr.bestFlag;
                        return 1;
                    }
                }
            }
        }
        fr.k++;
        if (fr.k >= 7)
            return 0;
    }
}
