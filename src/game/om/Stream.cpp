// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001e6390..0x001e85c0 (kind game, layer game, confidence medium), dominant class om::Stream
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/om.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb8261dc {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb8261dc {} using namespace fn_fb8261dc;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_fb8261dc {
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
};
struct Obj_1e6390 {
    char pad0[0x114];
    int f114;
    char pad118[4];
    Gen_1e6390 *f11c;
    V3_1e6390 *FUN_001d6b40();
};
struct Slot_1e6390 {
    char pad0[0x18];
    Obj_1e6390 *f18;
    char pad1c[6];
    short s22;
    char pad24[4];
};
struct Listener_1e6390 {
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
extern "C" Listener_1e6390 *__cdecl FUN_001c3d90();
extern "C" void __cdecl FUN_001e55f0(Entry_1e6390 *first, Entry_1e6390 *last, hulk_intptr n);
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
struct Vec3_1e6f10 {
    float x, y, z;
};
class Tracker_1e6f10 {
public:
    void FUN_00034c80(float v);
};
class ObjSub {
public:
};
class Zone_1e6f10 {
public:
};
class Ground_1e6f10 {
public:
    int FUN_002043e0();
    char FUN_00204440(int id);
    int FUN_00204200(float x, int y, float z);
};
class Holder_1e6f10 {
public:
};
class Caster_1e6f10 {
public:
    char FUN_00201f20(Vec3_1e6f10 *from, int mask, Vec3_1e6f10 *hit, Vec3_1e6f10 *normal, int *out5, int *out6);
};
class Settings_1e6f10 {
public:
    char FUN_0023f760(const char *name, int a, int b);
};
class Obj_1e6f10 {
public:
    char FUN_001d62a0();
    char FUN_001d6980();
    int FUN_001d6990();
    void FUN_001d69c0(int v);
    Vec3_1e6f10 *FUN_001d6b40();
    void FUN_001d7590();
    void FUN_001d7810(Vec3_1e6f10 v);
    void FUN_001d7ff0();
    void FUN_001d6290(int v);
    void FUN_001d6770();
    void FUN_001d8fc0(float v);

    char pad0[8];
    float pos[3];
    char pad1[0xf9 - 0x14];
    char dead;
    char pad1b[2];
    int mode;
    char pad2[0x11c - 0x100];
    Tracker_1e6f10 *tracker;
    char pad3[0x144 - 0x120];
    char timed;
    char pad4[3];
    int held;
    char pad5[0x14d - 0x14c];
    char zoned;
    char pad6[0x1a4 - 0x14e];
    ObjSub sub;
    char pad7[0x1c4 - 0x1a5];
    float timer;
};
struct Globals_1e6f10 {
    char pad0[0x24];
    Caster_1e6f10 *caster;
    char pad1[0x4c - 0x28];
    Zone_1e6f10 *zone;
    char pad2[4];
    Holder_1e6f10 *holder;
};
} // namespace fn_fb8261dc
extern "C" { extern Globals_1e6f10 *DAT_004dd700; }
class World {
public:
    void FUN_001e6f10(int unused, float dt);
    void FUN_001e57a0();
    void FUN_001e6390();
    char FUN_001dc1f0(Obj_1e6f10 *obj);
    void FUN_001e5720(Obj_1e6f10 *obj);
    void FUN_001e5bc0(int v);

    char pad0[0x1e620];
    Obj_1e6f10 *objs[128];
    int count;
    char pad1[0x1e830 - 0x1e824];
    Globals_1e6f10 *globals;
    char gather;
    char pad2[3];
    float threshold;
};
namespace fn_fb8261dc {
struct Obj_1e73b0 {
    bool FUN_001d62c0();
};
struct Slot_1e73b0 {
    Obj_1e73b0* obj;
    char pad4[6];
    short rec;
    char padc[0x26 - 0xc];
    short nextId;               // id of the following slot
};
struct Rec_1e73b0 {
    char pad0[0x10];
    unsigned char flags;
    char pad11;
    short link;
};
class Pool_1e73b0 {
public:
    char pad0[0x61e];
    short firstId;
    union {
        Slot_1e73b0 slots[0x800];
        struct {                // the record table starts inside the slot area
            char pad[0x14608 - 0x620];
            Rec_1e73b0 recs[1];
        } tbl;
    };

    void FUN_001e5980(int rec);
    void FUN_001e5bc0(int link);
    void FUN_001e73b0(int id);
};
struct This_Lookup {
    int Lookup(int);
};
class Obj {
  public:
    char Act(int);
    char Find(int);
};
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x001e6390 FUN_001e6390 (2935 B): equivalent/0x001e6390.cpp
// sym: ?FUN_001e6390@Mgr_1e6390@fn_fb8261dc@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 426 inputs, branch coverage 178/180, incomplete)
// FUN_001e6390 @ 0x001e6390
void Mgr_1e6390::FUN_001e6390()
{
    Frame_1e6390 f;
    if (nObjs > 0) {
        f.u20.cntA = nObjs;
        Obj_1e6390 **po = objs;
        do {
            Obj_1e6390 *o = *po;
            int sid = ((owners::C_1d6c70 *)o)->FUN_001d6c70();
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
    V3_1e6390 *lp = ((V3_1e6390 *)((owners::Object_1c39d0 *)(FUN_001c3d90()))->FUN_001c39d0());
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
                        Inner_1e6390 *in = ((Inner_1e6390 *)((owners::C_1d72e0 *)(sl->f18))->FUN_001d72e0());
                        if (in != 0 && in->f6c != 0 && in->f70 != 0 && !in->f70->v11())
                            continue;
                        ((owners::Blend_1c5080 *)(sl->f18->f11c))->FUN_001c5080((*(float*)&DAT_00421894), (*(float*)&DAT_0042189c));
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
                        ((owners::Blend_1c5080 *)(slots[ee->slot].f18->f11c))->FUN_001c5080((*(float*)&DAT_00421898), (*(float*)&DAT_0042189c));
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
                        ((owners::Blend_1c5080 *)(slots[ee->slot].f18->f11c))->FUN_001c5080((*(float*)&DAT_00421894), (*(float*)&DAT_0042189c));
                        ee->flags = ee->flags | 0x4000;
                    }
                } else {
                    Slot_1e6390 *sl = &slots[ee->slot];
                    if (sl->f18 != f.u20.cur) {
                        Inner_1e6390 *in = ((Inner_1e6390 *)((owners::C_1d72e0 *)(sl->f18))->FUN_001d72e0());
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

} // namespace fn_fb8261dc

// 0x001e6f10 FUN_001e6f10 (895 B): equivalent/0x001e6f10.cpp
// sym: ?FUN_001e6f10@World@@QAEXHM@Z
// STATUS: equivalent (tools/equiv.py level 3: 796 inputs, branch coverage 61/62, incomplete)
// FUN_001e6f10 @ 0x001e6f10
void World::FUN_001e6f10(int unused, float dt)
{
    if (((Ground_1e6f10 *)((owners::Target_862a0 *)(globals->holder))->FUN_000862a0())->FUN_002043e0() == 0)
        return;
    FUN_001e57a0();
    FUN_001e6390();
    if (!(*(Settings_1e6f10**)&DAT_004dd6e8)->FUN_0023f760("DoPhysics", 0x66, 1))
        return;
    for (int i = count - 1; i >= 0; i--) {
        Obj_1e6f10 *obj = objs[i];
        if (!obj)
            continue;
        if (obj->FUN_001d62a0())
            continue;
        if (obj->timed && obj->FUN_001d6980() && obj->mode != 2 && obj->mode != 3 &&
            obj->FUN_001d6990() != 10) {
            float d = obj->timer - dt;
            if (d > 1.0f && d < 1.5f)
                obj->tracker->FUN_00034c80((*(float*)&DAT_0042189c));
            if (d <= 0.0f) {
                obj->FUN_001d7ff0();
                obj->FUN_001d6290(1);
                continue;
            }
            obj->timer = d;
        }
        if (obj->zoned) {
            if (!((int)((owners::Obj_7ad00 *)(DAT_004dd700->zone))->FUN_0007ad00((hulk_intptr)(&obj->pos[0])))) {
                obj->FUN_001d7ff0();
                obj->FUN_001d6290(1);
            }
        }
        bool remove = false;
        if (gather) {
            Vec3_1e6f10 v = *obj->FUN_001d6b40();
            bool done = false;
            if (v.y < threshold && obj->mode != 2 && obj->mode != 3 && obj->held == 0) {
                if (((char)((owners::C_1d69b0 *)obj)->FUN_001d69b0())) {
                    Globals_1e6f10 *g = DAT_004dd700;
                    Holder_1e6f10 *h = g->holder;
                    int id = ((owners::Obj_1d69d0 *)obj)->FUN_001d69d0();
                    if (((Ground_1e6f10 *)((owners::Target_862a0 *)h)->FUN_000862a0())->FUN_00204440(id)) {
                        Vec3_1e6f10 *pos = obj->FUN_001d6b40();
                        Vec3_1e6f10 from;
                        from.x = pos->x;
                        from.y = 300.0f;
                        from.z = pos->z;
                        Vec3_1e6f10 hit;
                        Vec3_1e6f10 normal;
                        if (!DAT_004dd700->caster->FUN_00201f20(&from, 1, &hit, &normal, 0, 0)) {
                            remove = true;
                        } else {
                            hit.y = hit.y + 0.1f;
                            obj->FUN_001d7810(hit);
                            done = true;
                        }
                    }
                } else if (FUN_001dc1f0(obj)) {
                    obj->FUN_001d69c0(1);
                    obj->FUN_001d7590();
                    Vec3_1e6f10 *q = obj->FUN_001d6b40();
                    float qx = q->x;
                    float qz = q->z;
                    int id = ((Ground_1e6f10 *)((owners::Target_862a0 *)(DAT_004dd700->holder))->FUN_000862a0())->FUN_00204200(qx, 0, qz);
                    ((owners::A_1d69e0 *)obj)->FUN_001d69e0(id);
                    if (id == -1)
                        remove = true;
                } else {
                    remove = true;
                }
                if (remove) {
                    obj->FUN_001d6770();
                    FUN_001e5720(obj);
                    continue;
                }
                if (done)
                    obj->FUN_001d69c0(0);
            } else {
                obj->FUN_001d69c0(0);
            }
        }
        if (obj->held == 0)
            obj->FUN_001d8fc0(dt * 1000.0f);
        ((owners::Obj_1b6d70 *)&(obj->sub))->FUN_001b6d70(dt);
    }
    for (int i = count - 1; i >= 0; i--) {
        Obj_1e6f10 *obj = objs[i];
        if (obj && obj->FUN_001d62a0())
            FUN_001e5bc0(((owners::C_1d6c70 *)obj)->FUN_001d6c70());
    }
}


// 0x001e7290 FUN_001e7290 (274 B): equivalent/0x001e7290.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_001e7290@World@fn_001e7290@@QAEXPAVProbe@2@_N@Z
namespace fn_001e7290 {
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 22/22)
// FUN_001e7290 @ 0x001e7290
namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

class CSPHulkProp;

struct Vec3_1e7290 {
    float x, y, z;
};

struct Asset {
    int FUN_001d5000();
};

class Factory_1e7290 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Asset *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44 { Factory_1e7290 *FUN_00203d70(); };
struct Holder28 { Holder44 *FUN_000862a0(); };
struct Manager_1e7290 { char pad0[0x54]; Holder28 *holder; };

#define DAT_004dd700 (*(Manager_1e7290 * *)&::DAT_004dd700)


struct Prop_1e7290 {
    char pad00[0x114];
    int f114;
    char FUN_001d7300();
};

class Probe {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual bool v8(Vec3_1e7290 pos);
};

struct Entry_1e7290 {
    Vec3_1e7290 pos;
    int unused0c;
    int flags;
};

struct Slot_1e7290 {
    unsigned int keyLo;
    unsigned int keyHi;
    char pad08[6];
    short used;
    Prop_1e7290 *prop;
    char pad14[6];
    short index;
    char pad1c[0xc];
};

class World {
public:
    char pad0000[0x610];
    Slot_1e7290 slots[0x800];
    // the entry table (stride 0x14) starts at +0x14608, just inside the end of the slot array
    Entry_1e7290 *entryAt(int index) { return (Entry_1e7290 *)((char *)this + 0x14608) + index; }

    void FUN_001e5bc0(int index);
    void FUN_001e7290(Probe *probe, bool mustBeReady);
};

void World::FUN_001e7290(Probe *probe, bool mustBeReady)
{
    for (int i = 0; i < 0x800; i++) {
        Slot_1e7290 *slot = &slots[i];
        if (slot->used == 0)
            continue;
        Entry_1e7290 *e = entryAt(slot->index);
        Vec3_1e7290 pos = e->pos;
        char ready;
        if ((e->flags & 1) && slot->prop) {
            ready = slot->prop->FUN_001d7300();
            if (slot->prop->f114 != 0)
                continue;
        } else {
            content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
            Asset *asset = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70()->f3(&caster, slot->keyLo, slot->keyHi);
            ready = asset != 0 && asset->FUN_001d5000() != 0;
        }
        if (mustBeReady && !ready)
            continue;
        if (probe->v8(pos))
            FUN_001e5bc0(i);
    }
}
} // namespace fn_001e7290
#undef DAT_004dd700

namespace fn_fb8261dc {

// 0x001e73b0 FUN_001e73b0 (139 B): equivalent/0x001e73b0.cpp
// sym: ?FUN_001e73b0@Pool_1e73b0@fn_fb8261dc@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 252 inputs, branch coverage 12/12)
// FUN_001e73b0 @ 0x001e73b0
// Walk the 0x800 slots and release the record of every slot that carries the given id.
void Pool_1e73b0::FUN_001e73b0(int id)
{
    short* slotId = &firstId;
    Slot_1e73b0* slot = slots;
    Rec_1e73b0* recs = tbl.recs;
    for (int n = 0x800; n != 0; --n) {
        Rec_1e73b0* rec = &recs[slot->rec];
        if (*slotId == id) {
            bool release = true;
            if (rec->flags & 1) {
                if (slot->obj == 0 || !slot->obj->FUN_001d62c0()) {
                    release = false;
                } else {
                    FUN_001e5980(slot->rec);
                }
            }
            if (release && (rec->flags & 8) == 0) {
                FUN_001e5bc0(rec->link);
            }
        }
        slotId = &slot->nextId;
        ++slot;
    }
}


// 0x001e7440 FUN_001e7440 (42 B): matches/0x001e7440.cpp
// sym: ?Find@Obj@fn_fb8261dc@@QAEDH@Z
char Obj::Find(int x) {
    char result = 0;
    int n = ((This_Lookup*)this)->Lookup(x);
    if (n >= 0) {
        Act(n);
        result = 1;
    }
    return result;
}

} // namespace fn_fb8261dc

// 0x001e7470 FUN_001e7470 (4113 B): equivalent/0x001e7470.cpp [wrapped: macros]
// sym: ??0CSPManager@fn_001e7470@@QAE@XZ
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
void* operator new(hulk_uintptr) throw();
namespace fn_001e7470 {
// STATUS: equivalent (tools/equiv.py level 3: 934 inputs, branch coverage 102/102)
// FUN_001e7470 @ 0x001e7470


void* FUN_0008d690(unsigned int);
char FUN_001d04d0(const void*) throw();
class CSPManager;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
extern char DAT_0048e0e4, DAT_0048e0f0, DAT_0048e100, DAT_0048e10c, DAT_0048e128, DAT_0048e134;
#define tBool DAT_0048e0e4
#define tString DAT_0048e0f0
#define tVoid DAT_0048e100
#define tVector DAT_0048e10c
#define tFloat DAT_0048e128
#define tInt DAT_0048e134
// Function (include/decls/data/script.h): the vftable, then Function's fields; Method<N> adds the member-function
// pointer, Closure<N> the object.
class Base : public ScriptFunctionFields { public: virtual void v(); Base(const char*, int) throw(); };
template<class C, class R, class A1> class Method1 : public Base { public: R (C::*f)(A1); Method1(const char* n, R (C::*x)(A1), const void* r, const void* a1) : Base(n, 1) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); } virtual void v(); };
template<class C, class R, class A1> class Closure1 : public Method1<C, R, A1> { public: C* owner; Closure1(const char* n, C* o, R (C::*f)(A1), const void* r, const void* a1) : Method1<C, R, A1>(n, f, r, a1) { owner = o; } virtual void v(); };
// Function<N> (a free function, no object): Function's fields and the function pointer.
struct FunctionN_1e7470 { void* vftable; ScriptFunctionFields f; void (*fn)(); };
#define FN(b) extern void FUN_##b();
#define MF(b) (&CSPManager::FUN_##b)
#define G1(n, b, R, A1) { r->FUN_001d3b70(n, new Closure1<CSPManager, R, A1>(n, this, MF(b), &t##R, &t##A1)); }
#define E(n, c, b) { HULK_SIZE32(ScriptClosureView, 0x24); Entry* e = (Entry*)FUN_0008d690((unsigned int)sizeof(ScriptClosureView)); void* x = 0; if (e) x = e->FUN_##c(n, this, MF(b)); r->FUN_001d3b70(n, x); }
#define EF(n, c, b) { FN(b) HULK_SIZE32(FunctionN_1e7470, 0x20); Entry* e = (Entry*)FUN_0008d690((unsigned int)sizeof(FunctionN_1e7470)); void* x = 0; if (e) x = e->FUN_##c(n, FUN_##b); r->FUN_001d3b70(n, x); }
#define O(n, c, b) { r->FUN_##c(n, this, MF(b)); }
#define OF(n, c, b) { FN(b) r->FUN_##c(n, FUN_##b); }

class Link { public: char b[8]; void FUN_0027af00(); void FUN_0027b040(int); };
class Sub6 { public: char b[6]; void FUN_001db780(const void*); };
struct Slot { Link a; Link b; char pad[0x18]; };
struct Entry40 {
    Link a;
    Link b;
    Sub6 c;
    unsigned short w16;
    int d18;
    int d1c;
    unsigned short w20;
    unsigned short w22;
    unsigned short w24;
    unsigned char b26;
    unsigned char b27;
};
struct Rec14 { int a; int b; int c; float d; unsigned short w; unsigned short x; };
struct Rec18 { Link l; int a; int b; int c; int pad[1]; };
struct Vec4 { float x, y, z, w; };

class CSPManager {
public:
    // The member functions bound to Lua below.
    CSPManager();
    virtual void v0();
    char pad_04[4];
    int arr8[0x180];
    Entry40 e[0x800];
    Rec14 r14[0x800];
    int i1e608, i1e60c, i1e610, i1e614, i1e618, i1e61c;
    int arr1e620[0x80];
    int i1e820, i1e824, i1e828, i1e82c, i1e830;
    char c1e834;
    char pad1e835[3];
    int i1e838;
    char pad1e83c[4];
    Link links[0x80];
    char pad1ec40[0x10];
    int i1ec50, i1ec54, i1ec58;
    char pad1ec5c[4];
    int arr1ec60[0x40];
    Rec18 r18[0x10];
    float f1eee0;
    int i1eee4;
    // The member functions bound to Lua below (types: the game's Closure<N> instantiations).
    void FUN_001dba80(bool);
    void FUN_001dba90(float);
    bool FUN_001dc100(const char*, bool);
    int FUN_001dc350(const char*);
    float FUN_001dc4a0(const char*);
    bool FUN_001dc550(const char*, math::Vector);
    math::Vector FUN_001dc660(const char*);
    bool FUN_001dc720(const char*, math::Vector);
    math::Vector FUN_001dc810(const char*);
    float FUN_001dc8d0(const char*);
    int FUN_001dc940(const char*);
    void FUN_001dc9a0(const char*, int);
    int FUN_001dca00(const char*);
    void FUN_001dca40(const char*, bool, float);
    bool FUN_001dccf0(const char*, bool);
    bool FUN_001dcdf0(math::Vector, float);
    bool FUN_001dcf00(float, float, float, float);
    int FUN_001dcf50();
    void FUN_001dd030(int, int, const char*);
    void FUN_001dd090(float, float, float);
    bool FUN_001dd110(const char*, float);
    bool FUN_001dd1e0(const char*, float, float, int);
    void FUN_001ddb30(const char*, bool);
    void FUN_001ddb80(const char*, bool);
    void FUN_001ddbd0(const char*, float);
    void FUN_001ddc20(const char*, const char*);
    const char* FUN_001ddcc0(const char*);
    void FUN_001ddd50(const char*, float);
    float FUN_001ddda0(const char*);
    void FUN_001dde00(float);
    void FUN_001dde20(int);
    void FUN_001dde30(int);
    bool FUN_001dde50(const char*, int, int);
    void FUN_001defe0(const char*, bool);
    void FUN_001df010(const char*, const char*, int, const char*, math::Vector, math::Vector);
    int FUN_001df100(const char*, int);
    int FUN_001df130(const char*);
    bool FUN_001df160(const char*, int);
    math::Vector FUN_001df190(const char*);
    bool FUN_001df1e0(const char*, math::Vector);
    int FUN_001df2e0(const char*, int);
    void FUN_001df320(const char*, int, float, float, float, float);
    void FUN_001df330(const char*, bool);
    bool FUN_001df350(const char*);
    bool FUN_001df370(const char*);
    bool FUN_001df3a0(const char*, bool);
    bool FUN_001df400(const char*, const char*, int, float, const char*);
    void FUN_001e30f0(const char*, const char*);
    int FUN_001e3230(const char*, const char*);
    int FUN_001e32b0(const char*);
    int FUN_001e3360(const char*);
    void FUN_001e4e50(int, float, float, float, float, int);
    void FUN_001e4fc0(int, float, float, float);
    void FUN_001e5070(int, float, float, float, const char*);
    void FUN_001e5110(int, float, float, float, const char*);
    void FUN_001e54b0(const char*, const char*, float, float, float);
    void FUN_001e5540(const char*, const char*, math::Vector, math::Vector);
    void FUN_001e57e0(const char*, const char*, float, float, float);
    void FUN_001e5860(const char*, const char*, math::Vector);
    bool FUN_001e7440(const char*);
};
class Registry { public:
    void FUN_001d3b70(const char*, void*);
    void FUN_001e12b0(const char*, void (*)());
    void FUN_001e35a0(const char*, CSPManager*, bool (CSPManager::*)(const char*, int, int));
    void FUN_001e3790(const char*, CSPManager*, void (CSPManager::*)(const char*, const char*, int, const char*, math::Vector, math::Vector));
    void FUN_001e3930(const char*, CSPManager*, bool (CSPManager::*)(const char*, const char*, int, float, const char*));
    void FUN_001e3990(const char*, CSPManager*, void (CSPManager::*)(int, float, float, float));
    void FUN_001e39f0(const char*, CSPManager*, void (CSPManager::*)(int, float, float, float, const char*));
    void FUN_001e3a50(const char*, CSPManager*, void (CSPManager::*)(const char*, bool, float));
    void FUN_001e3ba0(const char*, CSPManager*, void (CSPManager::*)(const char*, int, float, float, float, float));
    void FUN_001e3c50(const char*, CSPManager*, void (CSPManager::*)(const char*, const char*, float, float, float));
    void FUN_001e3cb0(const char*, CSPManager*, void (CSPManager::*)(const char*, const char*, math::Vector));
    void FUN_001e3d10(const char*, CSPManager*, void (CSPManager::*)(const char*, const char*, math::Vector, math::Vector));
    void FUN_001e3dc0(const char*, CSPManager*, bool (CSPManager::*)(float, float, float, float));
    void FUN_001e3e20(const char*, CSPManager*, int (CSPManager::*)());
    void FUN_001e3ee0(const char*, CSPManager*, void (CSPManager::*)(int, int, const char*));
    void FUN_001e3f40(const char*, CSPManager*, void (CSPManager::*)(float, float, float));
    void FUN_001e3ff0(const char*, CSPManager*, bool (CSPManager::*)(const char*, float, float, int));
    void FUN_001e40f0(const char*, CSPManager*, void (CSPManager::*)(int, float, float, float, float, int));
};
class Entry { public:
    void* FUN_001df560(const char*, void (*)());
    void* FUN_001e1430(const char*, CSPManager*, bool (CSPManager::*)(const char*, bool));
    void* FUN_001e14e0(const char*, CSPManager*, bool (CSPManager::*)(const char*, int));
    void* FUN_001e1620(const char*, CSPManager*, void (CSPManager::*)(const char*, const char*));
    void* FUN_001e16c0(const char*, CSPManager*, void (CSPManager::*)(const char*, bool));
    void* FUN_001e17d0(const char*, CSPManager*, int (CSPManager::*)(const char*, int));
    void* FUN_001e1880(const char*, CSPManager*, int (CSPManager::*)(const char*, const char*));
    void* FUN_001e1930(const char*, CSPManager*, void (CSPManager::*)(const char*, int));
    void* FUN_001e1d40(const char*, CSPManager*, bool (CSPManager::*)(const char*, math::Vector));
    void* FUN_001e2150(const char*, CSPManager*, bool (CSPManager::*)(math::Vector, float));
    void* FUN_001e24c0(const char*, CSPManager*, bool (CSPManager::*)(const char*, float));
    void* FUN_001e26a0(const char*, CSPManager*, void (CSPManager::*)(const char*, float));
};
Registry* FUN_001d4c90();

CSPManager::CSPManager() {
    int i;
    for (i = 0; i < 0x800; i++) {
        e[i].a.FUN_0027af00();
        e[i].b.FUN_0027af00();
    }
    i1e608 = 0; i1e60c = 0; i1e610 = 0; i1e614 = 0; i1e61c = 0;
    i1e820 = 0; i1e824 = 0; i1e828 = 0; i1e82c = 0; i1e830 = 0;
    c1e834 = 0;
    i1e838 = 0;
    for (i = 0; i < 0x80; i++)
        links[i].FUN_0027af00();
    i1ec50 = 0; i1ec54 = 0; i1ec58 = 0;
    for (i = 0; i < 0x10; i++)
        r18[i].l.FUN_0027af00();
    f1eee0 = 1.0f;
    i1eee4 = 0x2d;
    Registry* r = FUN_001d4c90();
    if (r) {
G1("spm_SetMaxVU1RenderableCount", 001dde30, Void, Int)
O("spm_AddVU1Renderable", 001e35a0, 001dde50)
E("spm_SetSmartPropMustBeActive", 001e1430, 001dc100)
E("spm_SetSmartPropStateDescription", 001e14e0, 001df160)
G1("spm_GetSmartPropStateDescription", 001df130, Int, String)
G1("spm_SetMaxInstancedProps", 001dde20, Void, Int)
E("spm_SendSmartPropEvent", 001e1620, 001e30f0)
E("spm_ShowSmartProp", 001e16c0, 001defe0)
O("spm_AttachSmartProp", 001e3790, 001df010)
E("spm_SetSmartPropState", 001e17d0, 001df100)
G1("spm_GetSmartPropState", 001dc350, Int, String)
E("spm_SetSmartPropStateByName", 001e1880, 001e3230)
E("spm_SetSmartPropHitPoints", 001e1930, 001dc9a0)
G1("spm_GetSmartPropHitPoints", 001dc940, Int, String)
G1("spm_GetSmartPropERSIncrease", 001dca00, Int, String)
G1("spm_SetEnemyDamageFactor", 001dde00, Void, Float)
O("spm_SetSmartPropPatrolPath", 001e3930, 001df400)
O("spm_SpawnCollectable", 001e3990, 001e4fc0)
O("spm_SpawnCollectableName", 001e39f0, 001e5070)
O("spm_SpawnCollectableNameOffQueue", 001e39f0, 001e5110)
O("spm_SetMustRespawn", 001e3a50, 001dca40)
E("spm_AddCollectable", 001e17d0, 001df2e0)
E("spm_SetIsCollected", 001e1430, 001dccf0)
EF("spm_PhysicsProperty", 001df560, 001dca50)
G1("spm_GetSmartPropPosition", 001df190, Vector, String)
E("spm_SetSmartPropPosition", 001e1d40, 001df1e0)
G1("spm_GetSmartPropOrientation", 001dc4a0, Float, String)
E("spm_SetSmartPropOrientation", 001e1d40, 001dc550)
G1("spm_GetSmartPropVelocity", 001dc660, Vector, String)
E("spm_SetSmartPropVelocity", 001e1d40, 001dc720)
G1("spm_GetSmartPropLastLaunchPosition", 001dc810, Vector, String)
G1("spm_GetSmartPropCurrentFrame", 001dc8d0, Float, String)
G1("spm_GetSmartPropWeaponizableType", 001e32b0, Int, String)
G1("spm_GetSmartPropWeaponType", 001e3360, Int, String)
OF("spm_SetMajorHealthBonus", 001e12b0, 001dba30)
OF("spm_SetMinorHealthBonus", 001e12b0, 001dba40)
OF("spm_SetMajorRageBonus", 001e12b0, 001dba50)
OF("spm_SetMinorRageBonus", 001e12b0, 001dba60)
O("spm_SetRumbleEvent", 001e3ba0, 001df320)
E("spm_SetIndestructable", 001e16c0, 001df330)
G1("spm_GetIndestructable", 001df350, Bool, String)
O("spm_SpawnSmartPropOffQueue", 001e3c50, 001e54b0)
O("spm_SpawnSmartProp", 001e3c50, 001e57e0)
O("spm_SpawnSmartPropV", 001e3cb0, 001e5860)
O("spm_SpawnSmartPropDirV", 001e3d10, 001e5540)
G1("spm_RemovePropInstance", 001e7440, Bool, String)
E("spm_IsSmartPropInAreaV", 001e2150, 001dcdf0)
O("spm_IsSmartPropInArea", 001e3dc0, 001dcf00)
O("spm_GetNumActiveProps", 001e3e20, 001dcf50)
G1("spm_GetSmartPropCollisionEnabled", 001df370, Bool, String)
E("spm_SetSmartPropCollisionEnabled", 001e1430, 001df3a0)
G1("spm_SetDoYCheck", 001dba80, Void, Bool)
G1("spm_SetYCheck", 001dba90, Void, Float)
OF("spm_SetCollectableFadeTime", 001e12b0, 001dba70)
O("spm_SetDestructionEffectName", 001e3ee0, 001dd030)
O("spm_SetRestingSensitivity", 001e3f40, 001dd090)
E("spm_AddMassClass", 001e24c0, 001dd110)
O("spm_AddPhysicsRestingParam", 001e3ff0, 001dd1e0)
E("spm_SetSmartPropCharacterAlignment", 001e1620, 001ddc20)
G1("spm_GetSmartPropCharacterAlignment", 001ddcc0, String, String)
E("spm_SetSmartPropCharacterAlignmentDamageFactor", 001e26a0, 001ddd50)
G1("spm_GetSmartPropCharacterAlignmentDamageFactor", 001ddda0, Float, String)
E("spm_SetSmartPropSuckable", 001e16c0, 001ddb80)
E("spm_SetSmartPropChuckable", 001e16c0, 001ddb30)
E("spm_SetSmartPropMustSimulateTime", 001e26a0, 001ddbd0)
O("spm_SpewCollectables", 001e40f0, 001e4e50)
        for (i = 0; i < 4; i++)
            for (int j = 0; j < 0x20; j++)
                links[i * 0x20 + j].FUN_0027b040(0);
        for (i = 0; i < 0x40; i++)
            arr1ec60[i] = 0;
        for (i = 0; i < 0x10; i++) {
            r18[i].l.FUN_0027b040(0);
            r18[i].a = 0;
            r18[i].b = 0;
            r18[i].c = 0xff;
        }
        i1e618 = 0;
        for (i = 0; i < 0x80; i++)
            arr1e620[i] = 0;
        for (i = 0; i < 0x180; i++)
            arr8[i] = 0;
        Vec4 q;
        q.x = 0; q.y = 0; q.z = 0; q.w = 1.0f;
        for (i = 0; i < 0x800; i++) {
            e[i].a.FUN_0027b040(0);
            e[i].b.FUN_0027b040(0);
            e[i].d1c = 0;
            e[i].c.FUN_001db780(&q);
            e[i].d18 = 0;
            e[i].w20 = 0;
            e[i].w16 = 0;
            e[i].b26 = 0;
            e[i].w24 = 0;
            e[i].b27 = 1;
            e[i].w22 = 0xffff;
            r14[i].a = 0;
            r14[i].b = 0;
            r14[i].c = 0;
            r14[i].d = 3.4028235e38f;
            r14[i].w = 0;
            r14[i].x = 0xffff;
        }
    }
}
} // namespace fn_001e7470
#undef E
#undef EF
#undef FN
#undef G1
#undef MF
#undef O
#undef OF
#undef tBool
#undef tFloat
#undef tInt
#undef tString
#undef tVector
#undef tVoid

namespace fn_fb8261dc {

// 0x001e85a0 om::Stream::vfunc_0 (31 B): matches/0x001e85a0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_fb8261dc@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fb8261dc
