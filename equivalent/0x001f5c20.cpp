// STATUS: equivalent (tools/equiv.py level 3: 397 inputs, branch coverage 97/102, incomplete)
// FUN_001f5c20 @ 0x001f5c20
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" double sqrt(double);
extern "C" void __cdecl qsort(void *base, unsigned int count, unsigned int size,
                              int (__cdecl *cmp)(const void *, const void *));

struct __declspec(align(8)) Pair_1f5c20 {
    int a, b;
};

struct HandleKey {
    unsigned int lo, hi;
};

struct Slot20_1f5c20 {
    char pad0[0x20];
    union {
        float f20;
        int bits20;
    };
};

struct Info30 {
    char pad0[0x30];
    Slot20_1f5c20 *slot;
};

struct VoiceRef {
    char pad0[4];
    void *res;
};

struct Resource_1f5c20 {
    char pad0[4];
    VoiceRef *ref;
    void FUN_001f34f0();
};

struct Binding_1f5c20 {
    char pad0[0x18];
    int f18;
    HandleKey *FUN_001e8b00();
};

union Target_1f5c20 {
    float f;
    int bits;
};

union Key_1f5c20 {
    __int64 q;
    unsigned int w[2];
};

struct Row_1f5c20 {
    Key_1f5c20 key;
    int hash;
    char flag;
    char pad0d[3];
    Target_1f5c20 f90;
    float f94;
    float f98;
    float f9c;
    float fa0;
    char pad24[4];
};

struct Voice_1f5c20 {
    char pad0[0x10];
    Binding_1f5c20 *bind[4];
    Resource_1f5c20 *res[4];
    char pad30[0x54 - 0x30];
    float vx, vy, vz;
    char pad60[0x6c - 0x60];
    float f6c;
    char pad70[4];
    int type;
    char pad78[8];
    Row_1f5c20 rows[4];
};


int __cdecl FUN_001f2e80(const void *a, const void *b);
Resource_1f5c20 *FUN_0024a370(void *voice, int *hash);
void FUN_0024ac40(void *voice, void *r2, int a, int b, int c);
char FUN_00249b40(void *voice);
Info30 *FUN_002495f0(void *r2);
void FUN_00249bd0(void *voice, void *r2, Pair_1f5c20 *p);
int FUN_002673a0(int a, int b);

class Mgr_1f5c20 {
public:
    char pad0[8];
    void *handles[(0x88 - 8) / 4];
    int count88;
    char pad8c[0xd4 - 0x8c];
    Voice_1f5c20 *voices[(0x324 - 0xd4) / 4];
    int count324;
    Resource_1f5c20 *FUN_001f3ec0(Binding_1f5c20 *b, Voice_1f5c20 *v, Voice_1f5c20 *v2, int a, int c);
    void FUN_001f5b70();
    void FUN_001f5c20(int arg);
};

struct Handle_1f5c20 {
    void FUN_001f5860(int arg);
};

// Spare stack words of the original's frame that matter to the callees (the two scratch pairs) or are
// read back after the call.
struct Frame_1f5c20 {
    union {
        float len;
        Resource_1f5c20 *saved;
    } w;
    Pair_1f5c20 pairA;
    Pair_1f5c20 pairB;
};

void Mgr_1f5c20::FUN_001f5c20(int arg)
{
    Frame_1f5c20 f;
    int started = 0;
    DAT_004e3768[1] = 0;
    DAT_004e3798[1] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[1] = 0;
    DAT_004e3768[2] = 0;
    DAT_004e3798[2] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[2] = 0;
    DAT_004e3768[3] = 0;
    DAT_004e3798[3] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[3] = 0;
    DAT_004e3768[4] = 0;
    DAT_004e3798[4] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[4] = 0;
    DAT_004e3768[5] = 0;
    DAT_004e3798[5] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[5] = 0;
    DAT_004e3768[6] = 0;
    DAT_004e3798[6] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[6] = 0;
    qsort(voices, count324, 4, FUN_001f2e80);

    for (int k = 0; k < count324; k++) {
        Voice_1f5c20 **p = &voices[k];
        DAT_004e3798[(*p)->type]++;
        for (int i = 0; i < 4; i++) {
            Voice_1f5c20 *v = *p;
            Binding_1f5c20 *b = v->bind[i];
            if (!b)
                continue;
            if (!b->f18)
                continue;
            Resource_1f5c20 *cur = v->res[i];
            if (!cur) {
                if (!(DAT_004e3768[(*p)->type] < ((int*)&DAT_004c7df8)[(*p)->type]))
                    continue;
                if (!((float)DAT_004c7e10[(*p)->type] > (*p)->f6c))
                    continue;
                if (!(started < 0x18))
                    continue;
                Resource_1f5c20 *r = FUN_001f3ec0(b, *p, *p, 1, 0);
                if (r)
                    (*p)->res[i] = r;
                DAT_004e3768[(*p)->type]++;
                started++;
                continue;
            }
            if (DAT_004e3768[(*p)->type] < ((int*)&DAT_004c7df8)[(*p)->type] &&
                !((float)DAT_004c7e10[(*p)->type] <= (*p)->f6c) && started < 0x18) {
                DAT_004e3768[(*p)->type]++;
                Resource_1f5c20 *r = (*p)->res[i];
                started++;
                if (!r)
                    continue;
                r = (*p)->res[i];
                if (!r->ref)
                    continue;
                if (FUN_00249b40(r->ref))
                    continue;
                ((int*)((char*)&DAT_004e3768 + 24))[(*p)->type]++;
                continue;
            }
            if (cur->ref && !FUN_00249b40(cur->ref)) {
                DAT_004e3768[(*p)->type]++;
                started++;
                continue;
            }
            (*p)->res[i]->FUN_001f34f0();
            (*p)->res[i] = 0;
        }

        for (int m = 0; m < 4; m++) {
            Key_1f5c20 empty;
            empty.q = FUN_002672f0(0, 0, 0);
            if ((*p)->rows[m].key.w[0] == empty.w[0] && (*p)->rows[m].key.w[1] == empty.w[1])
                continue;
            for (int n = 0; n < 4; n++) {
                Voice_1f5c20 *v = *p;
                if (v->res[n] == 0)
                    continue;
                HandleKey *hk = v->bind[n]->FUN_001e8b00();
                if (hk->lo != v->rows[m].key.w[0])
                    continue;
                if (hk->hi != v->rows[m].key.w[1])
                    continue;
                Resource_1f5c20 *res = (*p)->res[n];
                int *hashp = &(*p)->rows[m].hash;
                if (res->ref) {
                    Resource_1f5c20 *r2 = FUN_0024a370(res->ref, hashp);
                    if (r2)
                        FUN_0024ac40(res->ref, r2, 1, 0, 0);
                }
                v = *p;
                double dlen = sqrt(v->vz * v->vz + v->vy * v->vy + v->vx * v->vx);
                f.w.len = (float)dlen;
                Row_1f5c20 *row = &v->rows[m];
                if (row->flag == 0) {
                    float t = 1.0f;
                    if (row->fa0 > 0.01f)
                        t = (row->f9c - row->f98) * (f.w.len / row->fa0) + row->f98;
                    if (t > row->f9c)
                        t = row->f9c;
                    Resource_1f5c20 *rr = v->res[n];
                    if (!rr->ref)
                        continue;
                    Resource_1f5c20 *r2 = FUN_0024a370(rr->ref, &row->hash);
                    if (!r2)
                        continue;
                    FUN_002495f0(r2)->slot->f20 = t;
                    continue;
                }
                Resource_1f5c20 *rr = v->res[n];
                if (!rr->ref)
                    continue;
                int *hashSaved = &row->hash;
                Resource_1f5c20 *r2 = FUN_0024a370(rr->ref, hashSaved);
                if (!r2)
                    continue;
                Info30 *q = FUN_002495f0(r2);
                if (!q)
                    continue;
                Slot20_1f5c20 *sl = q->slot;
                if (!sl)
                    continue;
                float cur20 = sl->f20;
                if (cur20 == -1.0f)
                    continue;
                float sum = 0.0f;
                bool viaSum = false;
                if (row->f94 == 0.0f) {
                } else {
                    sum = cur20 + row->f94;
                    viaSum = true;
                    bool to4b2;
                    if (sum < 0.01f)
                        to4b2 = true;
                    else if (!(row->f94 > 0.0f))
                        to4b2 = false;
                    else
                        to4b2 = sum > row->f90.f;
                    if (!to4b2) {
                        Resource_1f5c20 *rr2 = (*p)->res[n];
                        if (!rr2->ref)
                            continue;
                        Resource_1f5c20 *r3 = FUN_0024a370(rr2->ref, hashSaved);
                        if (!r3)
                            continue;
                        FUN_002495f0(r3)->slot->f20 = sum;
                        continue;
                    }
                }
                if (!viaSum) {
                    int copy90 = row->f90.bits;
                    Resource_1f5c20 *rr2 = (*p)->res[n];
                    if (rr2->ref) {
                        Resource_1f5c20 *r3 = FUN_0024a370(rr2->ref, hashSaved);
                        if (r3)
                            FUN_002495f0(r3)->slot->bits20 = copy90;
                    }
                }
                if (!(row->f90.f < 0.01f))
                    continue;
                Resource_1f5c20 *rr3 = (*p)->res[n];
                f.w.saved = rr3;
                Resource_1f5c20 *r4 = FUN_0024a370(rr3->ref, hashSaved);
                if (r4) {
                    if (!viaSum) {
                        f.pairA.a = 0;
                        f.pairA.b = 200;
                        FUN_00249bd0(f.w.saved->ref, r4, &f.pairA);
                    } else {
                        f.pairB.a = 0;
                        f.pairB.b = 200;
                        FUN_00249bd0(f.w.saved->ref, r4, &f.pairB);
                    }
                }
                v->rows[m].key.q = FUN_002672f0(0, 0, 0);
                *hashSaved = FUN_002673a0(0, 0);
            }
        }
    }
    FUN_001f5b70();
    int j = 0;
    if (count88 > 0) {
        void **hp = &handles[0];
        do {
            ((Handle_1f5c20 *)*hp)->FUN_001f5860(arg);
            j++;
            hp++;
        } while (j < count88);
    }
}
