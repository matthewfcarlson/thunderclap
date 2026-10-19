// STATUS: equivalent (tools/equiv.py level 3: 2237 inputs, branch coverage 50/52, incomplete)
// FUN_0008b560 @ 0x0008b560
// checked with equiv.py --time-budget 3600 (at the defaults most inputs hit the time budget)
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
extern "C" void *__cdecl memset(void *, int, unsigned int);

struct Rec6 {
    int w[6];
};

struct Slot_8b560 {
    int f00;
    char b04;
    char pad05[3];
    int f08;
    char f0c[0xc];
    char b18, b19, b1a, b1b;
    float f1c, f20, f24;
    char b28, b29, b2a, b2b, b2c, b2d;
    char pad2e[2];
    int f30;
    char b34, b35, b36;
    char pad37;
    unsigned int bits38[24];
    char pad98[0xb8 - 0x98];
    unsigned int bitsb8[24];
    char pad118[0x138 - 0x118];
    Rec6 rec[100];
    int row0[50];
    int fb60;
    int fb64;
    unsigned short name[64];
};

struct Obj3Item {
    char pad00[0x38];
    int f38;
};

struct Obj3_8b560 {
    char padz[0xc80];
    int fc80;
};

struct Obj2_8b560 {
    char FUN_00092860(int i);
    char FUN_00092940(int i);
};

struct Ent0 {
    char pad[0xc];
    char b0c;
};
struct Ent1 {
    char pad[5];
    char b05;
};
struct Ent2 {
    char pad[8];
    char b08;
};

struct Obj1_8b560 {
    char pad000[0x10c];
    int f10c;
    unsigned short *FUN_000f7d30(char *name);
    unsigned short *FUN_000f7220(unsigned short *p);
};

struct Cfg_8b560 {
    float FUN_001eb9d0();
    float FUN_001eba20();
    float FUN_001eba70();
    char FUN_001ebac0();
    void FUN_001eb870();
    void FUN_001eb890();
};

struct Obj3Src {
    Obj3Item *FUN_00090250(int i);
    int FUN_00090110();
};

struct Res;
Obj1_8b560 *__fastcall thunk_FUN_000fc1b0(Res *r);

struct Singleton_4dd6ec {
    Cfg_8b560 *FUN_000862e0();
    Res *FUN_00086280();
    Ent2 *FUN_000862c0();
    Ent1 *FUN_00086330();
    Obj2_8b560 *FUN_00086340();
    Obj3_8b560 *FUN_00086370();
    Ent0 *FUN_00086380();
};

struct Mgr2_8b560 {
    int FUN_0008cd80(int a1, int a2);
    int FUN_0008cbe0(int a1, int a2, Slot_8b560 *slot, int size, unsigned short *name);
};

char FUN_00035da0();
int __cdecl FUN_000964a0(char *buf, int n, const char *fmt, ...);
unsigned int *__cdecl FUN_000964d0();
void __cdecl FUN_000fb690(unsigned short *dst, const unsigned short *src, int n);
void __cdecl FUN_000fb740(unsigned short *dst, const char *src, int n);
int __cdecl FUN_000fc000(unsigned short *dst, int n, const char *fmt, ...);
int __cdecl FUN_000fb720(const unsigned short *s);
char __cdecl FUN_000fb6e0(const unsigned short *a, const unsigned short *b, int n);

class SaveMgr {
public:
    char pad000[0xd0];
    char bd0;
    char pad0d1[3];
    char bd4;
    char pad0d5[0x158 - 0xd5];
    Rec6 rec[100];
    char bab8;
    char pad0ab9[6];
    char babf;
    char pad0ac0[4];
    Mgr2_8b560 *fac4;
    Slot_8b560 *slots;
    void FUN_00089a60(char *out);
    int FUN_00089160();
    void FUN_0008ad90(int *chapter, int *mission);
    int FUN_0008b560(int a1, int a2, Singleton_4dd6ec *a3);
};

int SaveMgr::FUN_0008b560(int a1, int a2, Singleton_4dd6ec *a3)
{
    struct Frame {
        union {
            int *rowBase;
            int chapter;
        } u0;
        union {
            int j;
            int mission;
        } u1;
        Obj3_8b560 *obj3;
        char buf[64];
        unsigned short wbuf[64];
    } fr;

    DAT_004dd6ec->FUN_000862e0()->FUN_001eb870();
    int off = a2 * 0xbe8;
    Slot_8b560 *esi = (Slot_8b560 *)((char *)slots + off);
    esi->b18 = bd0;
    esi->b19 = bd4;
    esi->b1a = babf;
    FUN_00089a60(esi->f0c);
    esi->f00 = DAT_0049c294;
    esi->f08 = FUN_00089160();
    esi->b04 = 1;
    Obj1_8b560 *obj1 = thunk_FUN_000fc1b0(a3->FUN_00086280());
    int cls = obj1->f10c;
    char kind;
    switch (cls) {
    case 1: kind = 1; break;
    case 2: kind = 2; break;
    case 3: kind = 3; break;
    case 4: kind = 4; break;
    case 5: kind = 5; break;
    default: kind = 0; break;
    }
    esi->b1b = kind;
    esi->f1c = a3->FUN_000862e0()->FUN_001eb9d0();
    esi->f20 = a3->FUN_000862e0()->FUN_001eba20();
    esi->f24 = a3->FUN_000862e0()->FUN_001eba70();
    esi->b28 = a3->FUN_000862e0()->FUN_001ebac0();
    esi->b29 = a3->FUN_00086380()->b0c;
    esi->b2a = a3->FUN_00086330()->b05;
    esi->b2b = a3->FUN_000862c0()->b08;
    for (int i = 0; i < 100; i++)
        esi->rec[i] = rec[i];
    esi->b2c = bab8;
    Obj2_8b560 *obj2 = a3->FUN_00086340();
    for (int i = 0; i < 0x2fe; i++) {
        if (i == 0x1b) {
            esi->bits38[0] |= 0x8000000;
            esi->bitsb8[0] &= 0xf7ffffff;
        } else {
            int idx = i / 32;
            unsigned int mask = 1 << (i % 32);
            char f1 = obj2->FUN_00092860(i);
            unsigned int w = esi->bits38[idx];
            if (f1)
                w = w | mask;
            else
                w = w & ~mask;
            esi->bits38[idx] = w;
            char f2 = obj2->FUN_00092940(i);
            unsigned int w2 = esi->bitsb8[idx];
            if (f2)
                w2 = w2 | mask;
            else
                w2 = w2 & ~mask;
            esi->bitsb8[idx] = w2;
        }
    }
    fr.obj3 = a3->FUN_00086370();
    Obj3_8b560 *obj3 = fr.obj3;
    esi->fb64 = obj3->fc80;
    memset(esi->row0, 0, 200);
    esi->fb60 = 1;
    {
        fr.u1.j = 0;
        fr.u0.rowBase = esi->row0;
        do {
            int *p = fr.u0.rowBase;
            int k = 0;
            if (esi->fb64 > 0) {
                do {
                    p[0] = ((Obj3Src *)obj3)->FUN_00090250(k)->f38;
                    k++;
                    p++;
                } while (k < esi->fb64);
            }
            fr.u1.j++;
            fr.u0.rowBase = fr.u0.rowBase + 50;
        } while (fr.u1.j < esi->fb60);
    }
    esi->f30 = ((Obj3Src *)obj3)->FUN_00090110();
    esi->b34 = FUN_00035da0();
    esi->b35 = DAT_004dd83a;
    char b36 = DAT_004dd83b;
    esi->b36 = b36;
    FUN_0008ad90(&fr.u0.chapter, &fr.u1.mission);
    if (babf)
        FUN_000964a0(fr.buf, 0x40, "TBS_COMPLETE_PROMPT");
    else
        FUN_000964a0(fr.buf, 0x40, "TBS_C%dM%d_NAME", fr.u0.chapter, fr.u1.mission);
    unsigned short *nm = obj1->FUN_000f7220((unsigned short *)obj1->FUN_000f7d30(fr.buf));
    if (nm != 0)
        FUN_000fb690(fr.wbuf, nm, 0x40);
    else
        FUN_000fb740(fr.wbuf, fr.buf, 0x40);
    unsigned int counter = 0;
    int r = fac4->FUN_0008cd80(a1, a2);
    if (r != 1 && r != 0) {
        return r;
    }
    int result = 8;
    int attempt = 0;
    while (attempt < 10) {
        unsigned short *namep = esi->name;
        char dup = 0;
        for (;;) {
            dup = 0;
            if (counter != 0)
                FUN_000fc000(namep, 0x40, "%S (%u)", fr.wbuf, counter);
            else
                FUN_000fb690(namep, fr.wbuf, 0x40);
            esi->b2d = (char)counter;
            int slotNo = 0;
            int soff = 0;
            do {
                int h1 = FUN_000fb720(namep);
                unsigned short *other = (unsigned short *)((char *)slots + soff + 0xb68);
                int h2 = FUN_000fb720(other);
                if (slotNo != a2) {
                    if (h1 == h2) {
                        if (FUN_000fb6e0(namep, (unsigned short *)((char *)slots + soff + 0xb68), h1))
                            dup = 1;
                    }
                }
                slotNo++;
                soff += 0xbe8;
            } while (soff < 0x3b88);
            counter = counter + 1;
            if (!dup)
                break;
        }
        result = fac4->FUN_0008cbe0(a1, a2, (Slot_8b560 *)((char *)slots + off), 0xbe8, namep);
        if (counter >= 5) {
            unsigned int *rng = FUN_000964d0();
            unsigned int lo = rng[0];
            rng[0] = (lo & 0xffff) * 0x9069 + (lo >> 16);
            unsigned int hi = rng[1];
            unsigned int v1 = (hi >> 16) + (hi & 0xffff) * 0x4650;
            rng[1] = v1;
            counter = ((v1 & 0xffff) + (rng[0] << 16)) % 0x60 + 5;
        }
        attempt++;
        if (result != 8)
            break;
    }
    DAT_004dd6ec->FUN_000862e0()->FUN_001eb890();
    return result;
}
