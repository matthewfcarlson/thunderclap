// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00115ed0..0x00116760 (kind game, layer game, confidence medium), dominant class hulkfight::ai::ComputeDropZoneCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb4fb98f {
#define TREE_TU_END }
namespace fn_fb4fb98f {} using namespace fn_fb4fb98f;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fb4fb98f {
class A_115ed0 {
  public:
};
class B_115ed0 {
  public:
    void* Fng_00059a30();
};
class Obj_115f00 {
  public:
    void* FUN_00059a30();
    void FUN_00036e70(void*, int);
};
} // namespace fn_fb4fb98f
namespace fight {
class Params_115f40 {
public:
    virtual void vfunc_0();
};
}
namespace fn_fb4fb98f {
class CFightParams_115f40 : public fight::Params_115f40 {
public:
    virtual void vfunc_0();
};
struct Owner_115f40 {
    char pad[8];
    int state;
    Owner_115f40* next;
    char pad2[0x1a39 - 0x10];
    char groundPoint;
};
struct Fighter_115f40 {
    char pad[0x328];
    Owner_115f40* owner;
    char pad2[0x1a39 - 0x32c];
    char groundPoint;
};
struct Slot_115f40 {
    char pad[8];
    int kind;
    Fighter_115f40* fighter;
};
struct Mid_115f40 {
    char pad[0x328];
    Slot_115f40* slot;
    char pad2[0x1a39 - 0x32c];
    char groundPoint;
};
void* __fastcall FUN_000592a0(void* p);
extern "C" Mid_115f40* __fastcall FUN_00059a30(void* p);
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern char DAT_00494b44[];
extern char DAT_00494b60[];
struct Vec3_115fb0 {
    float x, y, z;
    float FUN_0022d110();
};
struct Sys54 {
    void FUN_00086310();
};
struct Obj0c_115fb0 {
    void FUN_001dcf60(int a);
};
struct Part11c {
    char pad0[0x1b0];
    int f1b0;
};
struct Sub328;
struct Obj124_115fb0 {
    char pad0[0x11c];
    Part11c *p11c;
    char pad120[0xc];
    Sub328 *p12c;
};
struct Obj20_115fb0 {
    char pad0[0x124];
    Obj124_115fb0 *p124;
    void FUN_00025260(int a, int b, int c);
};
} // namespace fn_fb4fb98f
struct World {
    char pad0[0xc];
    Obj0c_115fb0 *p0c;
    char pad10[0x10];
    Obj20_115fb0 *p20;
    char pad24[0x54 - 0x24];
    Sys54 *p54;
};
namespace fn_fb4fb98f {
struct Obj8_115fb0 {
    void FUN_000356c0(Vec3_115fb0 *v);
    void FUN_00035550(Vec3_115fb0 *v);
};
struct Sub328 {
    char pad0[8];
    Obj8_115fb0 *p8;
    int fc;
    char pad10[0x30];
    Vec3_115fb0 pos;
};
struct Part10 {
    void FUN_00059a50(Vec3_115fb0 *out);
};
struct Obj3_115fb0 {
    char pad0[0x10];
    Part10 *p10;
    char pad14[0x11c - 0x14];
    Part11c *p11c;
    char pad120[0x328 - 0x120];
    Sub328 *p328;
    char pad32c[0x20a8 - 0x32c];
    int f20a8;
    void FUN_0003ffa0(Sub328 *s, int z);
    void FUN_00035430(Vec3_115fb0 *v);
    void FUN_00035490(Vec3_115fb0 *v);
};
struct T1 {
    Obj3_115fb0 *FUN_00059a30();
};
struct Entity {
    T1 *FUN_000592a0();
};
struct Hit_115fb0 {
    char pad0[8];
    char flag8;
};
struct Finder_115fb0 {
    Hit_115fb0 *FUN_001c8060(Vec3_115fb0 *v, int z);
};
struct Holder_115fb0 {
    char pad0[4];
    Finder_115fb0 *finder;
};
Holder_115fb0 *FUN_001c3d90();
char FUN_00036b10(World *w, Vec3_115fb0 *p, Vec3_115fb0 *q, Vec3_115fb0 *o1, Vec3_115fb0 *o2, char *c1, char *c2);
struct Frame_115fb0 {
    Vec3_115fb0 pos;
    char pad0c;
    char ok;
    char hitA;
    char hitB;
    Vec3_115fb0 cand;
    float acc;
    Vec3_115fb0 dirC;
    Vec3_115fb0 tmp;
    Vec3_115fb0 P;
    Obj3_115fb0 *obj;
    Vec3_115fb0 Q;
    Vec3_115fb0 zv;
    Vec3_115fb0 *posPtr;
    float y1;
    World *world;
    Vec3_115fb0 out108;
    Vec3_115fb0 out120;
};
class ComputeDropZoneCondition {
public:
    char pad4[8];
    float step;
    float limit;
    float scale;
    char pad18[4];
    char useOffsets;
    char pad1d[3];
    float offset;
    virtual bool vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a0, Entity *e, int a2);
};
extern void* hulk_at_0040eaa0[];
class Condition_1166d0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class HasGroundPointCondition_1166d0 : public Condition_1166d0 {
  public:
    HasGroundPointCondition_1166d0* vfunc_5(signed char flags);
};
extern void* hulk_at_0040eac0[];
class Condition_116700 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class LocatorDistanceCondition_116700 : public Condition_116700 {
  public:
    LocatorDistanceCondition_116700* vfunc_5(signed char flags);
};
extern void* hulk_at_0040eae0[];
class Condition_116730 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class ComputeDropZoneCondition_116730 : public Condition_116730 {
  public:
    ComputeDropZoneCondition_116730* vfunc_5(signed char flags);
};

} // namespace fn_fb4fb98f

// 0x00115ed0 hulkfight::ai::MotionBoostAction::vfunc_3 (45 B): matches/0x00115ed0.cpp
// sym: ?vfunc_3@MotionBoostAction@ai@hulkfight@@UAE_NHH@Z
bool hulkfight::ai::MotionBoostAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if (!(*(void * *)&this->f_20))
        return false;
    void* x = ((void *)((owners::Object_592a0 *)(((A_115ed0*)(*(void * *)&this->f_20))))->FUN_000592a0());
    x = ((B_115ed0*)x)->Fng_00059a30();
    ((owners::C_35460 *)(((B_115ed0*)x)))->FUN_00035460((unsigned *)((char*)&this->f_28));
    return true;
}


// 0x00115f00 hulkfight::ai::MotionClosestWaypointAction::vfunc_4 (57 B): matches/0x00115f00.cpp
// sym: ?vfunc_4@MotionClosestWaypointAction@ai@hulkfight@@UAEXXZ
void hulkfight::ai::MotionClosestWaypointAction::vfunc_4() {
    if ((*(Obj_115f00 * *)&this->f_20)) {
        void* a = ((void *)((owners::Object_592a0 *)((*(Obj_115f00 * *)&this->f_20)))->FUN_000592a0());
        a = ((Obj_115f00*)a)->FUN_00059a30();
        if (a) {
            *(unsigned char*)((char*)a + 0x2140) = this->f_58;
            *((unsigned char*)a + 0x2149) = 0;
            ((Obj_115f00*)a)->FUN_00036e70((char*)this + 0x60, 0);
        }
    }
}


// 0x00115f40 hulkfight::ai::HasGroundPointCondition::vfunc_6 (103 B): equivalent/0x00115f40.cpp
// sym: ?vfunc_6@HasGroundPointCondition@ai@hulkfight@@UAE_NPAX00@Z @8626c836c4fd @w36ba08242754
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 12/12)
// hulkfight::ai::HasGroundPointCondition::vfunc_6 @ 0x00115f40
bool hulkfight::ai::HasGroundPointCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_115f40 * params = (fight::Params_115f40 *)__p1; int c = (int)__p2;

    if (!dynamic_cast<CFightParams_115f40*>(params))
        return false;
    Mid_115f40* m = FUN_00059a30(FUN_000592a0(params));
    if (this->f_0d) {
        Slot_115f40* s = m->slot;
        if (!s || s->kind != 1)
            return false;
        Fighter_115f40* f = s->fighter;
        if (!f)
            return false;
        return f->groundPoint == this->f_0c;
    }
    return m->groundPoint == this->f_0c;
}

namespace fn_fb4fb98f {

// 0x00115fb0 hulkfight::ai::ComputeDropZoneCondition::vfunc_6 (1556 B): equivalent/0x00115fb0.cpp
// sym: ?vfunc_6@ComputeDropZoneCondition@fn_fb4fb98f@@UAE_NHPAUEntity@2@H@Z @cd883323e8c0 @w583eafae34f3
// STATUS: equivalent (tools/equiv.py level 3: 3073 inputs, branch coverage 90/104, incomplete)
// hulkfight::ai::ComputeDropZoneCondition::vfunc_6 @ 0x00115fb0
bool ComputeDropZoneCondition::vfunc_6(int a0, Entity *e, int a2)
{
    Frame_115fb0 f;
    if (!FUN_00344e74(e, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;
    World *w = DAT_004dd700;
    if (!w)
        return false;
    if (DAT_004e0c94 > 8)
        DAT_004e0c94 = 0;
    w->p54->FUN_00086310();
    Obj3_115fb0 *obj = e->FUN_000592a0()->FUN_00059a30();
    f.zv.x = 0.0f;
    f.zv.y = 0.0f;
    f.zv.z = 0.0f;
    f.obj = obj;
    obj->p10->FUN_00059a50(&f.zv);
    Sub328 *sub = obj->p328;
    f.world = DAT_004dd700;
    if (sub == 0) {
        if (obj->f20a8 >= 0)
            return false;
        Part11c *p = obj->p11c;
        if (!p)
            return false;
        Obj124_115fb0 *o = f.world->p20->p124;
        if (!o)
            return false;
        sub = o->p12c;
        if (!sub)
            return false;
        Part11c *q = o->p11c;
        if (!q)
            return false;
        if (p->f1b0 == q->f1b0)
            return false;
        obj->FUN_0003ffa0(sub, 0);
    }
    if (sub->fc != 1)
        return false;
    Obj8_115fb0 *o8 = sub->p8;
    if (!o8)
        return false;
    f.posPtr = &sub->pos;
    f.pos = *f.posPtr;
    f.tmp.x = 0.0f;
    f.tmp.y = 0.0f;
    f.tmp.z = 0.0f;
    o8->FUN_000356c0(&f.tmp);
    float len = f.tmp.FUN_0022d110();
    float s;
    if (len <= 0.0f) {
        o8->FUN_00035550(&f.tmp);
        s = 4.0f;
    } else if (len < 1.0f) {
        s = 4.0f;
    } else {
        s = len;
    }
    float k = s * scale;
    f.cand = f.tmp;
    f.cand.y = f.cand.y * k;
    f.cand.z = f.cand.z * k;
    f.pos.x = f.cand.x * k + f.pos.x;
    f.pos.y = f.cand.y + f.pos.y;
    f.pos.z = f.cand.z + f.pos.z;
    f.pos.y = sub->pos.y + 2.5f;
    if (useOffsets) {
        int st = DAT_004e0c94;
        if (st == 1 || st == 2 || st == 8)
            f.pos.x = f.pos.x + offset;
        if (st == 6 || st == 5 || st == 4)
            f.pos.x = f.pos.x - offset;
        if (st == 2 || st == 3 || st == 4)
            f.pos.z = f.pos.z + offset;
        if (st == 8 || st == 7 || st == 6)
            f.pos.z = f.pos.z - offset;
    }
    f.dirC = f.zv;
    f.ok = 0;
    f.acc = 0.0f;
    if (!((*(char*)&DAT_004e0c90) & 1))
        (*(char*)&DAT_004e0c90) |= 1;
    (*(Vec3_115fb0*)&DAT_004e0c84).z = 0.0f;
    (*(Vec3_115fb0*)&DAT_004e0c84).y = 0.0f;
    (*(Vec3_115fb0*)&DAT_004e0c84).x = 0.0f;
    f.y1 = f.dirC.y + 1.0f;
    while (f.acc < limit) {
        f.acc = f.acc + step;
        DAT_004d2a3c = 2;
        (*(char*)&DAT_00554c1c) = 1;
        DAT_00554c18 = 0;
        f.dirC.y = f.y1 + f.acc;
        DAT_004dd700->p20->FUN_00025260(0, 0, 0);
        DAT_004dd700->p0c->FUN_001dcf60(1);
        if (!f.ok) {
            Vec3_115fb0 *pp = f.posPtr;
            f.P.x = pp->x;
            f.P.y = pp->y + 1.0f;
            f.P.z = pp->z;
            f.Q = f.pos;
            if (!FUN_00036b10(DAT_004dd700, &f.P, &f.Q, &f.out120, &f.out108, &f.hitA, &f.hitB)) {
                if (!useOffsets)
                    return false;
                char r = 0;
                int i = 1;
                do {
                    if (r)
                        break;
                    f.cand = f.pos;
                    if (i == 1 || i == 2 || i == 8)
                        f.cand.x = f.pos.x + offset;
                    if (i == 6 || i == 5 || i == 4)
                        f.cand.x = f.cand.x - offset;
                    if (i == 2 || i == 3 || i == 4)
                        f.cand.z = f.pos.z + offset;
                    if (i == 8 || i == 7 || i == 6)
                        f.cand.z = f.cand.z - offset;
                    r = FUN_00036b10(DAT_004dd700, &f.P, &f.cand, &f.out120, &f.out108, &f.hitA, &f.hitB);
                    i++;
                } while (i < 9);
                if (!r)
                    return false;
                DAT_004e0c94 = i;
                f.pos = f.cand;
            }
            f.ok = 1;
        }
        f.P.x = f.dirC.x;
        f.P.y = f.dirC.y + 1.0f;
        f.P.z = f.dirC.z;
        f.Q.x = f.pos.x;
        f.Q.y = f.pos.y + 1.0f;
        f.Q.z = f.pos.z;
        char hit = FUN_00036b10(DAT_004dd700, &f.P, &f.Q, &f.out120, &f.out108, &f.hitA, &f.hitB);
        f.world->p20->FUN_00025260(1, 0, 0);
        DAT_004dd700->p0c->FUN_001dcf60(1);
        obj = f.obj;
        if (hit)
            break;
    }

    Finder_115fb0 *fd = FUN_001c3d90()->finder;
    Hit_115fb0 *h1 = fd->FUN_001c8060(&f.pos, 0);
    Hit_115fb0 *h2 = fd->FUN_001c8060(&f.dirC, 0);
    if (h1 && h2 && h1->flag8 && h2->flag8) {
        obj->FUN_00035430(&f.pos);
        obj->FUN_00035490(&f.dirC);
        DAT_004e0c94++;
        return true;
    }
    obj->FUN_00035430(((Vec3_115fb0*)&DAT_004e0c84));
    obj->FUN_00035490(((Vec3_115fb0*)&DAT_004e0c84));
    return false;
}


// 0x001166c0 FUN_001166c0 (16 B): matches/0x001166c0.cpp
// sym: ?f@fn_fb4fb98f@@YAXPAH@Z
void f(int* p) {
    int v = *p;
    if (v)
        *p = 0;
}


// 0x001166d0 hulkfight::ai::HasGroundPointCondition::vfunc_5 (36 B): matches/0x001166d0.cpp
// sym: ?vfunc_5@HasGroundPointCondition_1166d0@fn_fb4fb98f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HasGroundPointCondition_1166d0* HasGroundPointCondition_1166d0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040eaa0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00116700 hulkfight::ai::LocatorDistanceCondition::vfunc_5 (36 B): matches/0x00116700.cpp
// sym: ?vfunc_5@LocatorDistanceCondition_116700@fn_fb4fb98f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
LocatorDistanceCondition_116700* LocatorDistanceCondition_116700::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040eac0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00116730 hulkfight::ai::ComputeDropZoneCondition::vfunc_5 (36 B): matches/0x00116730.cpp
// sym: ?vfunc_5@ComputeDropZoneCondition_116730@fn_fb4fb98f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ComputeDropZoneCondition_116730* ComputeDropZoneCondition_116730::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040eae0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fb4fb98f
