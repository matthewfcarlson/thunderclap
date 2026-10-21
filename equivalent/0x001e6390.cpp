// STATUS: equivalent (tools/equiv.py level 3: 426 inputs, branch coverage 178/180, incomplete)
// FUN_001e6390 @ 0x001e6390
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/om.h"

struct V3_1e6390 {
    float x, y, z;
};

struct Entry_1e6390 {
    V3_1e6390 pos;
    float d2;
    unsigned short flags;
    short slot;
};

struct Inner2_1e6390 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual char v11();
};

struct Inner_1e6390 {
    char pad0[0x6c];
    void *f6c;
    Inner2_1e6390 *f70;
};

struct Gen_1e6390 {
    char pad0[0x80];
    float f80;
    void FUN_001c5080(float a, float b);
};

struct Obj_1e6390 {
    char pad0[0x114];
    int f114;
    char pad118[4];
    Gen_1e6390 *f11c;
    int FUN_001d6c70();
    V3_1e6390 *FUN_001d6b40();
    Inner_1e6390 *FUN_001d72e0();
};

struct Slot_1e6390 {
    char pad0[0x18];
    Obj_1e6390 *f18;
    char pad1c[6];
    short s22;
    char pad24[4];
};

struct Listener_1e6390 {
    V3_1e6390 *FUN_001c39d0();
    char FUN_001c4010(V3_1e6390 *v);
};

struct Chain3_1e6390 {
    int f0;
    char pad4[4];
    hulk_intptr f8;
    int fc;
};
struct Chain2_1e6390 {
    char pad0[0x328];
    Chain3_1e6390 *f328;
};
struct Chain1_1e6390 {
    char pad0[0x124];
    Chain2_1e6390 *f124;
};
struct Chain0 {
    char pad0[0x20];
    Chain1_1e6390 *f20;
};

extern Listener_1e6390 *__cdecl FUN_001c3d90();
extern void __cdecl FUN_001e55f0(Entry_1e6390 *first, Entry_1e6390 *last, hulk_intptr n);

struct Frame_1e6390 {
    int idx;                    // 0x00
    char pad4[0x1c - 4];
    volatile int cntB;          // 0x1c
    union {
        volatile int cntA;
        void *cur;
    } u20;                      // 0x20
    char pad24[4];
    int n2;                     // 0x28
    V3_1e6390 L;                       // 0x2c
    volatile float tmpT;        // 0x38
    char pad3c[0x48 - 0x3c];
    int list2[128];             // 0x48
    int list3[128];             // 0x248
};

class Mgr_1e6390 {
public:
    char pad0[0x608];
    Slot_1e6390 slots[2048];
    Entry_1e6390 entries[2048];
    char pad1e608[4];
    int lo;                     // 0x1e60c
    int hi;                     // 0x1e610
    int count;                  // 0x1e614
    char pad1e618[8];
    Obj_1e6390 *objs[128];             // 0x1e620
    int nObjs;                  // 0x1e820
    char pad1e824[0x1e830 - 0x1e824];
    Chain0 *p1e830;
    char pad1e834[0x1eee4 - 0x1e834];
    int limit;                  // 0x1eee4
    void FUN_001e5980(int a);
    void FUN_001e2940(int a);
    void FUN_001e6390();
};

void Mgr_1e6390::FUN_001e6390()
{
    Frame_1e6390 f;
    if (nObjs > 0) {
        f.u20.cntA = nObjs;
        Obj_1e6390 **po = objs;
        do {
            Obj_1e6390 *o = *po;
            int sid = o->FUN_001d6c70();
            Entry_1e6390 *e = &entries[slots[sid].s22];
            V3_1e6390 *pos = o->FUN_001d6b40();
            e->pos.x = pos->x;
            e->pos.y = pos->y;
            e->pos.z = pos->z;
            if (o->f114 != 0)
                e->flags = e->flags | 0x8000;
            else
                e->flags = e->flags & 0x7fff;
            po++;
            f.u20.cntA--;
        } while (f.u20.cntA != 0);
    }
    V3_1e6390 *lp = FUN_001c3d90()->FUN_001c39d0();
    f.L.x = lp->x;
    f.L.y = lp->y;
    f.L.z = lp->z;
    f.cntB = count;
    Entry_1e6390 *e = &entries[0];
    for (int i = 0; i < f.cntB; i++, e++) {
        unsigned short fl = e->flags;
        if ((fl & 2) || (fl & 0x8000)) {
            int l = lo;
            if (i > l) {
                int h = hi;
                if (i > h) {
                    if (i != h + 1) {
                        Entry_1e6390 t = entries[h + 1];
                        entries[h + 1] = *e;
                        *e = t;
                    }
                    int hh = hi + 1;
                    hi = hh;
                    if (lo < 0) {
                        if (hh != 0) {
                            Entry_1e6390 t = entries[0];
                            entries[0] = entries[hh];
                            entries[hh] = t;
                        }
                        lo = 1;
                    } else {
                        Entry_1e6390 t = entries[lo];
                        entries[lo] = entries[hh];
                        entries[hi] = t;
                        lo = lo + 1;
                    }
                } else {
                    if (lo < 0) {
                        if (i != 0) {
                            Entry_1e6390 t = entries[0];
                            entries[0] = *e;
                            *e = t;
                        }
                        lo = 1;
                    } else {
                        Entry_1e6390 t = entries[lo];
                        entries[lo] = *e;
                        *e = t;
                        lo = lo + 1;
                    }
                }
            } else if (i == l) {
                lo = l + 1;
            }
            if (hi < 0 || hi < lo)
                hi = lo;
        } else {
            float dx = e->pos.x - f.L.x;   // x87: dx goes through the frame (rounded), dz and d2 stay in registers
            hulk_freg dz = e->pos.z - f.L.z;
            int sh = ((fl >> 10) & 2) + ((fl >> 10) & 1);
            hulk_freg d2 = dz * dz + (hulk_freg)dx * dx;
            if (sh > 0)
                d2 = d2 * (3600.0f / ((float*)&DAT_004237cc)[sh]);
            e->d2 = d2;
            if (d2 > DAT_004c6f48) {
                if (!(i > hi) && i != lo) {
                    int cnt = count;
                    if (hi >= cnt - 1) {
                        if (i != cnt - 1) {
                            Entry_1e6390 t = entries[cnt - 1];
                            entries[cnt - 1] = *e;
                            *e = t;
                        }
                        hi = count - 2;
                    } else {
                        if (hi != i) {
                            Entry_1e6390 t = entries[hi];
                            entries[hi] = *e;
                            *e = t;
                        }
                        hi = hi - 1;
                    }
                    if (lo < 0 || lo > hi)
                        lo = hi;
                }
            } else {
                if (i > hi) {
                    if (hi < 0) {
                        if (i != 0) {
                            Entry_1e6390 t = entries[0];
                            entries[0] = *e;
                            *e = t;
                        }
                        hi = 0;
                    } else if (i == hi + 1) {
                        hi = hi + 1;
                    } else {
                        Entry_1e6390 t = entries[hi + 1];
                        entries[hi + 1] = *e;
                        *e = t;
                        hi = hi + 1;
                    }
                    if (lo < 0 || lo > hi)
                        lo = hi;
                }
            }
            int lw = lo;
            if (i < lw - 1) {
                Entry_1e6390 t = entries[lw - 1];
                entries[lw - 1] = *e;
                *e = t;
                lo = lo - 1;
            } else if (i == lw - 1) {
                lo = lw - 1;
            }
        }
    }
    if (lo >= 0 && lo < count && lo < hi) {
        int h1 = hi + 1;
        if (h1 >= count)
            h1 = count;
        Entry_1e6390 *first = &entries[lo];
        Entry_1e6390 *last = &entries[h1];
        FUN_001e55f0(first, last, last - first);
    }
    for (int i = 0; i < count; i++)
        slots[entries[i].slot].s22 = (short)i;

    f.u20.cur = 0;
    {
        Chain1_1e6390 *c1 = p1e830->f20;
        if (c1 != 0) {
            Chain2_1e6390 *c2 = c1->f124;
            if (c2 != 0) {
                Chain3_1e6390 *c3 = c2->f328;
                if (c3 != 0 && c3->fc == 5)
                    f.u20.cur = (void *)c3->f8;
            }
        }
    }
    int ebp = 0;
    int idx = 0;
    int n2 = 0;
    int cnt = count;
    if (cnt > 0) {
        Entry_1e6390 *ee = &entries[0];
        for (f.cntB = cnt; f.cntB != 0; f.cntB--, ee++) {
            int L = limit;
            unsigned short fl = ee->flags;
            if (idx >= L - 5) {
                if (!(fl & 1))
                    continue;
                idx++;
                if (idx >= L) {
                    if (ebp >= L)
                        continue;
                    f.list2[ebp++] = ee->slot;
                    idx--;
                    continue;
                }
                if (fl & 0x4000) {
                    int s = ee->slot;
                    if ((*(float*)&DAT_00421894) == slots[s].f18->f11c->f80) {
                        if (ebp < L) {
                            f.list2[ebp++] = s;
                            idx--;
                        }
                    }
                } else {
                    Slot_1e6390 *sl = &slots[ee->slot];
                    if (sl->f18 != f.u20.cur) {
                        Inner_1e6390 *in = sl->f18->FUN_001d72e0();
                        if (in != 0 && in->f6c != 0 && in->f70 != 0 && !in->f70->v11())
                            continue;
                        sl->f18->f11c->FUN_001c5080((*(float*)&DAT_00421894), (*(float*)&DAT_0042189c));
                        ee->flags = ee->flags | 0x4000;
                    }
                }
                continue;
            }
            char bl = (fl >> 12) & 1;
            char flagA = 0;
            int dsh = 0;
            char alv = 1;
            if ((fl & 2) || (fl & 0x8000)) {
                flagA = 1;
            } else {
                if (fl & 0x40)
                    dsh = 1;
                if (fl & 0x80)
                    dsh += 2;
                if (dsh > 0) {
                    f.tmpT = ((float*)&DAT_00423198)[dsh];
                    f.L = ee->pos;
                    alv = FUN_001c3d90()->FUN_001c4010(&f.L);
                }
            }
            if (ee->flags & 1) {
                idx++;
                if (flagA || (alv && !bl)) {
                    if (ee->flags & 0x4000) {
                        slots[ee->slot].f18->f11c->FUN_001c5080((*(float*)&DAT_00421898), (*(float*)&DAT_0042189c));
                        ee->flags = ee->flags & 0xbfff;
                    }
                } else if (alv) {
                    if (ee->flags & 0x4000) {
                        int s = ee->slot;
                        if ((*(float*)&DAT_00421894) == slots[s].f18->f11c->f80) {
                            if (ebp < L) {
                                f.list2[ebp++] = s;
                                idx--;
                            }
                        }
                    } else {
                        slots[ee->slot].f18->f11c->FUN_001c5080((*(float*)&DAT_00421894), (*(float*)&DAT_0042189c));
                        ee->flags = ee->flags | 0x4000;
                    }
                } else {
                    Slot_1e6390 *sl = &slots[ee->slot];
                    if (sl->f18 != f.u20.cur) {
                        Inner_1e6390 *in = sl->f18->FUN_001d72e0();
                        if (in != 0 && in->f6c != 0 && in->f70 != 0 && !in->f70->v11())
                            continue;
                        if (ebp < L) {
                            f.list2[ebp++] = ee->slot;
                            idx--;
                        }
                    }
                }
            } else {
                if (flagA || (alv && !bl && ee->d2 <= DAT_004c6f44)) {
                    f.list3[n2++] = ee->slot;
                    idx++;
                }
            }
        }
    }

    if (!((*(unsigned int*)&DAT_004e2760) & 1)) {
        (*(unsigned int*)&DAT_004e2760) |= 1;
        DAT_004e275c = limit;
    }
    int st = DAT_004e275c;
    int nb = ebp;
    if (nObjs > limit - 7) {
        nb = st;
        if (ebp < st)
            nb = ebp;
    }
    for (int i = 0; i < nb; i++) {
        Slot_1e6390 *sl = &slots[f.list2[i]];
        if (sl->f18 != 0)
            FUN_001e5980(sl->s22);
    }
    int nc;
    if (nObjs <= limit - 7) {
        nc = n2;
    } else {
        nc = 2;
        if (n2 < 2)
            nc = n2;
    }
    if (nc >= limit - nObjs)
        nc = limit - nObjs;
    for (int i = 0; i < nc; i++) {
        Slot_1e6390 *sl = &slots[f.list3[i]];
        if (sl->f18 == 0)
            FUN_001e2940(sl->s22);
    }
}
