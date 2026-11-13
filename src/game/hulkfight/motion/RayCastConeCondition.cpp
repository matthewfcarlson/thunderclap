// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001665e0..0x00167560 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastConeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa2e0d0f {
#define TREE_TU_END }
namespace fn_fa2e0d0f {} using namespace fn_fa2e0d0f;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fa2e0d0f {
extern int* hulk_at_004e12a0;
class CCondition_1665e0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e12a8;
class CCondition_166640 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e12b0;
class CCondition_1666b0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e12b8;
class CCondition_166710 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e12c0;
class CCondition_166780 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
struct Lvl3 {
    unsigned char third_000373d0();
};
struct Lvl2 {
    Lvl3* second_00059a30();
};
struct Lvl1 {
};
} // namespace fn_fa2e0d0f
namespace fight {
class Params_166b40;
}
namespace fn_fa2e0d0f {
class CFightParams_166b40;
class Holder_166b40 {
public:
    char pad0[0x1f58];
    struct Slot { int state; int a; int b; } slots[11];
};
class Inner_166b40 {
public:
    Holder_166b40* FUN_00059a30();
};
} // namespace fn_fa2e0d0f
namespace fight {
class Params_166b40 {
public:
    virtual void p0();
    Inner_166b40* FUN_000592a0();
};
}
namespace fn_fa2e0d0f {
class CFightParams_166b40 : public fight::Params_166b40 {
public:
    virtual void c0();
};
struct Slot_166bc0 {
    int state;
    int pad[2];
};
struct Controller_166bc0 {
    char pad00[0x1f58];
    Slot_166bc0 slots[4];
    char pad1f88[0x1ff4 - 0x1f88];
    int extra;
};
struct Holder_166bc0 {
    Controller_166bc0 *FUN_00059a30();
};
} // namespace fn_fa2e0d0f
namespace fight {
class Params_166bc0 {
public:
    virtual void v0();
    Holder_166bc0 *FUN_000592a0();
};
}
namespace fn_fa2e0d0f {
class CFightParams_166bc0 : public fight::Params_166bc0 {
public:
    virtual void v1();
};
struct Obj_166c60 {
    void* getB_00059a30();
};
struct Stats_167290;
struct Ctx_167290 {
    Stats_167290 *FUN_00059a30();
};
class Owner_167290 {
public:
};
struct Target_167290 {
    char pad0[0x140];
    unsigned int f140;
};
struct Stats_167290 {
    char pad0[0x328];
    struct Slot {
        char pad0[8];
        Target_167290 *f8;
        int fc;
    } *f328;
};
class Obj {
  public:
};
class Mid {
  public:
    Obj* get_00059a30();
};
class Arg {
  public:
    Mid* get_000592a0();
};
struct MotionState_167350 {
};
struct Locomotion_167350 {
    char pad00[8];
    MotionState_167350* state;   // 0x08
    int kind;             // 0x0c
};
struct Fighter_167350 {
    char pad00[0x328];
    Locomotion_167350* locomotion;   // 0x328
};
struct Body_167350 {
    Fighter_167350* FUN_00059a30();
};
class Target_167350 {
public:
};
struct ObjEnd {
    char pad[0x1b28];
    int field;
};
struct ObjMid {
    ObjEnd* Call2_00059a30();
};
struct ObjA_1673c0 {
};
extern void* hulk_at_00416658[];
class Condition_167410 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class ChargeCondition_167410 : public Condition_167410 {
  public:
    ChargeCondition_167410* vfunc_5(signed char flags);
};
extern void* hulk_at_00416678[];
class Condition_167440 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class TargetMotionStateCondition_167440 : public Condition_167440 {
  public:
    TargetMotionStateCondition_167440* vfunc_5(signed char flags);
};
extern void* hulk_at_00416698[];
class Condition_167470 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class IntentionButtonDownAnyCondition_167470 : public Condition_167470 {
  public:
    IntentionButtonDownAnyCondition_167470* vfunc_5(signed char flags);
};
extern void* hulk_at_004166b8[];
class Condition_1674a0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class VelocityCondition_1674a0 : public Condition_1674a0 {
  public:
    VelocityCondition_1674a0* vfunc_5(signed char flags);
};
extern void* hulk_at_004166d8[];
class Condition_1674d0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class VelocityYCondition_1674d0 : public Condition_1674d0 {
  public:
    VelocityYCondition_1674d0* vfunc_5(signed char flags);
};
extern void* hulk_at_004166f8[];
class Condition_167500 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class VelocityAnimatedXZCondition_167500 : public Condition_167500 {
  public:
    VelocityAnimatedXZCondition_167500* vfunc_5(signed char flags);
};
extern char hulk_at_00416718;
struct RayCastConeCondition_nv_167530 {
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(hulkfight::motion::RayCastConeCondition*);
class RayCastTargetCondition_167530 {
  public:
    void* vftable;
    char pad[0x0c];
    RayCastTargetCondition_167530* vfunc_5(unsigned char);
};

} // namespace fn_fa2e0d0f

// 0x001665e0 hulkfight::motion::ShoreNearCondition::vfunc_0 (16 B): matches/0x001665e0.cpp
// sym: ?vfunc_0@ShoreNearCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::ShoreNearCondition::vfunc_0(int index) {
    int* p = hulk_at_004e12a0;
    return p[index];
}

namespace fn_fa2e0d0f {

// 0x00166620 FUN_00166620 (19 B): matches/0x00166620.cpp
// sym: ?FUN_00166620@fn_fa2e0d0f@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166620(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e12a8), ((char*)&DAT_004e12ac));
}

} // namespace fn_fa2e0d0f

// 0x00166640 hulkfight::motion::HealthPercentCondition::vfunc_0 (16 B): matches/0x00166640.cpp
// sym: ?vfunc_0@HealthPercentCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HealthPercentCondition::vfunc_0(int index) {
    int* p = hulk_at_004e12a8;
    return p[index];
}

namespace fn_fa2e0d0f {

// 0x00166690 FUN_00166690 (19 B): matches/0x00166690.cpp
// sym: ?FUN_00166690@fn_fa2e0d0f@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166690(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e12b0), ((char*)&DAT_004e12b4));
}

} // namespace fn_fa2e0d0f

// 0x001666b0 hulkfight::motion::ThinkingCondition::vfunc_0 (16 B): matches/0x001666b0.cpp
// sym: ?vfunc_0@ThinkingCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::ThinkingCondition::vfunc_0(int index) {
    int* p = hulk_at_004e12b0;
    return p[index];
}

namespace fn_fa2e0d0f {

// 0x001666f0 FUN_001666f0 (19 B): matches/0x001666f0.cpp
// sym: ?FUN_001666f0@fn_fa2e0d0f@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001666f0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e12b8), ((char*)&DAT_004e12bc));
}

} // namespace fn_fa2e0d0f

// 0x00166710 hulkfight::motion::VelocityAnimatedCondition::vfunc_0 (16 B): matches/0x00166710.cpp
// sym: ?vfunc_0@VelocityAnimatedCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::VelocityAnimatedCondition::vfunc_0(int index) {
    int* p = hulk_at_004e12b8;
    return p[index];
}

namespace fn_fa2e0d0f {

// 0x00166760 FUN_00166760 (19 B): matches/0x00166760.cpp
// sym: ?FUN_00166760@fn_fa2e0d0f@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166760(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e12c0), ((char*)&DAT_004e12c4));
}

} // namespace fn_fa2e0d0f

// 0x00166780 hulkfight::motion::HealthCondition::vfunc_0 (16 B): matches/0x00166780.cpp
// sym: ?vfunc_0@HealthCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HealthCondition::vfunc_0(int index) {
    int* p = hulk_at_004e12c0;
    return p[index];
}


// 0x001667d0 hulkfight::motion::ThinkingCondition::vfunc_6 (80 B): matches/0x001667d0.cpp
// sym: ?vfunc_6@ThinkingCondition@motion@hulkfight@@UAE_NPAX00@Z
bool hulkfight::motion::ThinkingCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * p = (void *)__p1; void * c = (void *)__p2;

    if (!((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)((hulk_intptr)DAT_00494b44), (void*)((hulk_intptr)DAT_00494b60), 0)))
        return false;
    Lvl1* q = (Lvl1*)p;
    Lvl2* r = ((Lvl2 *)((owners::Object_592a0 *)q)->FUN_000592a0());
    Lvl3* s = r->second_00059a30();
    unsigned char v = this->f_0c;
    return s->third_000373d0() == v;
}


// 0x00166820 hulkfight::motion::RayCastConeCondition::vfunc_6 (799 B): equivalent/0x00166820.cpp [wrapped: conflict: CFightParams; fight::Params; hulkfight::motion::RayCastConeCondition]
// sym: ?vfunc_6@RayCastConeCondition@motion@hulkfight@fn_00166820@@UAE_NHPAVParams@fight@4@H@Z @ba7f74258753 @w9bad3331aaf5
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00166820 {
// STATUS: equivalent (tools/equiv.py level 3: 19389 inputs, branch coverage 28/28)
// hulkfight::motion::RayCastConeCondition::vfunc_6 @ 0x00166820
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct V3_166820 {
    float x, y, z;
    void FUN_0022d180();
    hulk_freg FUN_0022d110();
};

struct Matrix {
    float m[16];
    void FUN_0022c2b0(V3_166820* in, V3_166820* out);
    void FUN_0022c3b0(V3_166820* in, V3_166820* out);
};

struct Key_166820 {
    unsigned int lo;
    unsigned int hi;
};

struct Skeleton {
    char pad00[0x1c];
    char* table;
    unsigned int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct Fighter_166820 {
    char pad00[0x120];
    Skeleton* skel;
    char pad124[0x334 - 0x124];
    void* f334;
    void* f338;
    void FUN_00035550(V3_166820* out);
};

struct Anchor_166820 {
    Fighter_166820* FUN_00059a30();
};

namespace fight {
class Params {
public:
    virtual void v0();
    virtual void v1();
    Anchor_166820* FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v2();
};

struct Game20_166820 {
    char pad00[0x124];
    void* f124;
};

struct World {
    char pad00[0x20];
    Game20_166820* f20;
};


bool FUN_002027c0(V3_166820* from, V3_166820* to, int a, int notSelf, V3_166820* out1, V3_166820* out2, int b, int c);

struct Frame_166820 {
    float v;
    V3_166820 z0;
    V3_166820 end;
    V3_166820 c;
    int i;
    Fighter_166820* fighter;
    V3_166820 dirZ;
    V3_166820 q18;
    V3_166820 p;
    V3_166820 pts[3];
    char pad78[0x90 - 0x78];
    V3_166820 out2;
    V3_166820 out1;
    Matrix m;
};

namespace hulkfight {
namespace motion {
class RayCastConeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a0, fight::Params* a1, int a2);
    char pad04[0x10 - 4];
    Key_166820 key;
    V3_166820 axis;
    float len;
    float start;
    float step;
    unsigned char flag;
};

bool RayCastConeCondition::vfunc_6(int a0, fight::Params* a1, int a2)
{
    Frame_166820 f;
    if (dynamic_cast<CFightParams*>(a1) == 0)
        return false;
    Anchor_166820* anchor = a1->FUN_000592a0();
    f.fighter = anchor->FUN_00059a30();
    f.fighter->FUN_00035550(&f.c);
    f.v = start;
    if (f.v > 0.0f) {
        do {
            float t = f.v * 0.017453292519943295f;
            f.pts[0].x = f.c.x + t;
            f.pts[0].y = f.z0.y + f.c.y;
            f.pts[0].z = f.z0.z + f.c.z;
            f.pts[1] = f.c;
            f.pts[2].x = f.c.x - t;
            f.pts[2].y = f.c.y - f.z0.y;
            f.pts[2].z = f.c.z - f.z0.z;
            for (int k = 0; k < 3; k++)
                f.pts[k].FUN_0022d180();
            f.i = 0;
            V3_166820* pp = f.pts;
            do {
                Skeleton* skel = f.fighter->skel;
                if (skel != 0) {
                    unsigned int j = 0;
                    if ((key.lo | key.hi) != 0) {
                        j = skel->FUN_002843a0(key.lo, key.hi);
                        if (j == 0xffff)
                            j = 0;
                    }
                    f.p = *pp;
                    f.z0.x = 0.0f;
                    f.z0.y = 0.0f;
                    f.z0.z = 0.0f;
                    f.dirZ.x = 0.0f;
                    f.dirZ.y = 0.0f;
                    f.dirZ.z = -1.0f;
                    f.end.x = 0.0f;
                    f.end.y = 0.0f;
                    f.end.z = 0.0f;
                    f.m = *(Matrix*)(skel->table + j * 64);
                    f.q18 = axis;
                    f.m.FUN_0022c2b0(&f.q18, &f.z0);
                    f.m.FUN_0022c3b0(&f.p, &f.dirZ);
                    f.dirZ.FUN_0022d110();
                    volatile float *ev = &f.end.x; // y and z products are rounded through the frame in the original
                    ev[1] = f.dirZ.y * len;
                    ev[2] = f.dirZ.z * len;
                    f.end.x = f.dirZ.x * len + f.z0.x;
                    ev[1] = ev[1] + f.z0.y;
                    ev[2] = ev[2] + f.z0.z;
                    void* g = DAT_004dd700->f20->f124;
                    int notSelf = 0;
                    if (g != (void*)f.fighter && f.fighter->f338 != g && f.fighter->f334 != g)
                        notSelf = 1;
                    if (FUN_002027c0(&f.z0, &f.end, 0, notSelf, &f.out1, &f.out2, 0, 0))
                        return flag != 0;
                }
                f.v = f.v - step;
                f.i++;
                pp++;
            } while (f.i < 3);
        } while (f.v > 0.0f);
    }
    return flag == 0;
}
}
}
} // namespace fn_00166820
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00166b40 hulkfight::motion::IntentionButtonDownAnyCondition::vfunc_6 (121 B): equivalent/0x00166b40.cpp
// sym: ?vfunc_6@IntentionButtonDownAnyCondition@motion@hulkfight@@UAE_NPAX00@Z @ebe074a54509 @w5647646b64c6
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::IntentionButtonDownAnyCondition::vfunc_6 @ 0x00166b40
bool hulkfight::motion::IntentionButtonDownAnyCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int unused1 = (int)__p0; fight::Params_166b40 * params = (fight::Params_166b40 *)__p1; int unused2 = (int)__p2;

    if (!dynamic_cast<CFightParams_166b40*>(params))
        return false;
    Holder_166b40* h = params->FUN_000592a0()->FUN_00059a30();
    char down = 0;
    for (int i = 0; i < 11; i++) {
        if (h->slots[i].state == 2 || h->slots[i].state == 1) {
            down = 1;
            break;
        }
    }
    return down == this->f_0c;
}


// 0x00166bc0 hulkfight::motion::IntentionInputCondition::vfunc_6 (160 B): equivalent/0x00166bc0.cpp
// sym: ?vfunc_6@IntentionInputCondition@motion@hulkfight@@UAE_NPAX00@Z @133c1407e978 @w690349ebd486
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 20/20)
// hulkfight::motion::IntentionInputCondition::vfunc_6 @ 0x00166bc0
// hulkfight::motion::IntentionInputCondition::vfunc_6 @ 0x00166bc0: checks the requested pad inputs against the controller state
bool hulkfight::motion::IntentionInputCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_166bc0 * params = (fight::Params_166bc0 *)__p1; int c = (int)__p2;

    if (dynamic_cast<CFightParams_166bc0 *>(params) == 0)
        return false;
    Controller_166bc0 *ctl = params->FUN_000592a0()->FUN_00059a30();
    bool hit = false;
    for (int i = 0; i <= 3; i++) {
        int state = ctl->slots[i].state;
        if (state == 2)
            hit = ((*(unsigned char *)&this->f_0c) == 1);
        else if (state == 1)
            hit = ((*(unsigned char *)&this->f_0d) == 1);
        if (hit)
            return true;
    }
    int extra = ctl->extra;
    if (extra == 2)
        return (*(unsigned char *)&this->f_0e) == 1;
    if (extra == 1)
        return (*(unsigned char *)&this->f_0f) == 1;
    return hit;
}


// 0x00166c60 hulkfight::motion::TargetingCondition::vfunc_6 (75 B): matches/0x00166c60.cpp
// sym: ?vfunc_6@TargetingCondition@motion@hulkfight@@UAE_NPAX00@Z
bool hulkfight::motion::TargetingCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * params = (void *)__p1; void * last = (void *)__p2;

    if (!((int)(hulk_uintptr)__RTDynamicCast(params, 0, (void*)((hulk_intptr)DAT_00494b44), (void*)((hulk_intptr)DAT_00494b60), 0)))
        return false;
    void* x = ((void *)((owners::Object_592a0 *)(((Obj_166c60*)params)))->FUN_000592a0());
    void* y = ((Obj_166c60*)x)->getB_00059a30();
    return *((unsigned char*)y + 0x32c) == this->f_0c;
}


// 0x00166cb0 hulkfight::motion::GrappleReactionTypeCondition::vfunc_6 (196 B): equivalent/0x00166cb0.cpp [wrapped: conflict: DAT_00494b44; DAT_00494b60; hulkfight::motion::GrappleReactionTypeCondition]
// sym: ?vfunc_6@GrappleReactionTypeCondition@motion@hulkfight@fn_00166cb0@@UAE_NPAXPAUActor_166cb0@4@0@Z @b82070aa6fe4 @wee13b26d9a1c
namespace fn_00166cb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// hulkfight::motion::GrappleReactionTypeCondition::vfunc_6 @ 0x00166cb0
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct ActorState_166cb0 { void FUN_00059a30(); };
struct Actor_166cb0 { ActorState_166cb0* FUN_000592a0(); };
struct Reaction_166cb0 { char pad[0x394]; int reactionType; };
extern "C" Reaction_166cb0* __cdecl FUN_00048260(Actor_166cb0*);
namespace hulkfight { namespace motion {
struct GrappleReactionTypeCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Actor_166cb0*, void*);
 char pad[8]; unsigned comparison; int value;
};
bool GrappleReactionTypeCondition::vfunc_6(void*, Actor_166cb0* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 actor->FUN_000592a0()->FUN_00059a30();
 Reaction_166cb0* reaction = FUN_00048260(actor);
 if (!reaction) return false;
 int actual = reaction->reactionType;
 switch (comparison) {
 case 0: return actual < value;
 case 1: return actual <= value;
 case 2: return actual == value;
 case 3: return actual != value;
 case 4: return actual >= value;
 case 5: return actual > value;
 default: return false;
 }
}
}}
} // namespace fn_00166cb0


// 0x00166d90 hulkfight::motion::InLoadedRoomCondition::vfunc_6 (147 B): equivalent/0x00166d90.cpp [wrapped: conflict: CFightParams; DAT_004dd700; World; fight::Params (+1)]
// sym: ?vfunc_6@InLoadedRoomCondition@motion@hulkfight@fn_00166d90@@QAE_NHPAVParams@fight@4@H@Z @90a4f13bc7b6 @w52d117267ada
namespace fn_00166d90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::InLoadedRoomCondition::vfunc_6 @ 0x00166d90
struct V3_166d90 {
    float x, y, z;
};

struct Handle_166d90 {
    char FUN_00059a50(V3_166d90 *out);
};

namespace fight {
class Params {
public:
    virtual void p0();
};
}

class CFightParams : public fight::Params {
public:
    Handle_166d90 *FUN_000592a0();
};

struct Room {
    char FUN_00204350(float x, float y, float z);
};

struct World {
    Room *FUN_000862a0();
};

struct Game_166d90 {
    char pad00[0x54];
    World *world;           // 0x54
};

#define DAT_004dd700 (*(Game_166d90 * *)&::DAT_004dd700)


namespace hulkfight {
namespace motion {
class InLoadedRoomCondition {
public:
    char pad00[0xc];
    char expected;          // 0xc

    bool vfunc_6(int arg0, fight::Params *params, int arg2);
};

bool InLoadedRoomCondition::vfunc_6(int arg0, fight::Params *params, int arg2)
{
    if (!dynamic_cast<CFightParams *>(params))
        return false;
    Handle_166d90 *handle = ((CFightParams *)params)->FUN_000592a0();
    V3_166d90 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    handle->FUN_00059a50(&pos);
    return DAT_004dd700->world->FUN_000862a0()->FUN_00204350(pos.x, pos.y, pos.z) == expected;
}
}
}
} // namespace fn_00166d90
#undef DAT_004dd700


// 0x00166e30 hulkfight::motion::ShoreNearCondition::vfunc_6 (400 B): equivalent/0x00166e30.cpp [wrapped: conflict: World]
// sym: ?FUN_00166e30@ShoreNearCondition@fn_00166e30@@UAEDHPAVParams_166e30@fight@2@H@Z @b435ceb17242 @w206634eeb3fa
namespace fn_00166e30 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 16/16)
// hulkfight::motion::ShoreNearCondition::vfunc_6 @ 0x00166e30
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct V3_166e30 {
    float x, y, z;
    hulk_freg FUN_000111f0();
};

struct Fighter_166e30 {
    char pad0[0x1a39];
    char flag1a39;
    char pad1a3a[2];
    V3_166e30 shorePos;
};

struct Holder_166e30 {
    Fighter_166e30 *FUN_00059a30();
    void FUN_00059a50(V3_166e30 *out);
};

struct Checker_166e30 {
    bool FUN_00204350(float x, float y, float z);
};

struct Mgr54_166e30 {
};

struct Nav28 {
    bool FUN_001fe380(V3_166e30 *from, V3_166e30 *out);
};

struct World {
    char pad0[0x28];
    Nav28 *nav;
    char pad2c[0x54 - 0x2c];
    Mgr54_166e30 *mgr;
};


namespace fight {
class Params_166e30 {
  public:
    virtual void v0();
    virtual void v1();
    Holder_166e30 *FUN_000592a0();
};
}

class CFightParams_166e30 : public fight::Params_166e30 {
  public:
    virtual void v2();
};

class ShoreNearCondition {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual char FUN_00166e30(int a1, fight::Params_166e30 *params, int a3);
    char pad4[8];
    char flag;
};

char ShoreNearCondition::FUN_00166e30(int a1, fight::Params_166e30 *params, int a3)
{
    if (dynamic_cast<CFightParams_166e30 *>(params) == 0)
        return false;

    Holder_166e30 *holder = params->FUN_000592a0();
    Fighter_166e30 *fighter = holder->FUN_00059a30();
    if (fighter->flag1a39)
        return flag;

    V3_166e30 pos;
    V3_166e30 d;
    V3_166e30 out;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    holder->FUN_00059a50(&pos);

    World *game = DAT_004dd700;
    if (((Checker_166e30 *)((owners::Target_862a0 *)(game->mgr))->FUN_000862a0())->FUN_00204350(pos.x, pos.y, pos.z))
        return flag;

    V3_166e30 *shore = &fighter->shorePos;
    d.x = shore->x;
    d.y = shore->y;
    d.z = shore->z;
    hulk_freg dist2 = (d.z - pos.z) * (d.z - pos.z) + (d.x - pos.x) * (d.x - pos.x);
    d.y = 0.0f;
    if ((DAT_004e12d4 & 1) == 0) {
        DAT_004e12d4 |= 1;
        DAT_004e12d0 = 3600.0f;
    }
    if (dist2 < DAT_004e12d0)
        return flag;

    out.x = 0.0f;
    out.y = 0.0f;
    out.z = 0.0f;
    if (game->nav->FUN_001fe380(&pos, &out)) {
        d.x = out.x - pos.x;
        d.y = 0.0f;
        d.z = out.z - pos.z;
        if (d.FUN_000111f0() < DAT_004e12d0)
            return flag;
    }
    return flag == 0;
}
} // namespace fn_00166e30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00166fc0 hulkfight::motion::RayCastTargetCondition::vfunc_6 (514 B): equivalent/0x00166fc0.cpp [wrapped: conflict: Skeleton; World]
// sym: ?vfunc_6@RayCastTargetCondition@fn_00166fc0@@QAEDHPAUObj1_166fc0@2@H@Z @e4ff3ca9026c @w6c36c4043e06
namespace fn_00166fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 25/26, incomplete)
// hulkfight::motion::RayCastTargetCondition::vfunc_6 @ 0x00166fc0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

struct Vec3_166fc0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Matrix {
    float m[16];
};

struct Skeleton {
    char pad00[0x1c];
    Matrix* matrices;
    int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct Entity;

struct World {
    char pad00[0x20];
    struct Player_166fc0* player;
};

struct Player_166fc0 {
    char pad00[0x124];
    Entity* current;
};

struct Slot_166fc0 {
    int pad00;
    int pad04;
    struct Entity* entity;
    int count;
};

struct Entity {
    char pad00[0x120];
    Skeleton* skeleton;
    char pad124[0x334 - 0x124];
    Entity* ignoreB;
    Entity* ignoreA;
};

struct Holder_166fc0 {
    char pad00[0x328];
    Slot_166fc0* slot;
};

struct Target_166fc0 {
    Holder_166fc0* FUN_000592a0();
};

struct Holder2_166fc0 {
    Holder_166fc0* FUN_00059a30();
};

struct Obj2_166fc0 {
    Holder_166fc0* FUN_00059a30();
};

struct Obj1_166fc0 {
    Obj2_166fc0* FUN_000592a0();
};

char FUN_002027c0(Vec3_166fc0* a, Vec3_166fc0* b, int c, int d, Vec3_166fc0* hitPos, Vec3_166fc0* hitNormal, int e, int f);

class RayCastTargetCondition {
public:
    virtual void v0();
    char pad04[0xc];
    unsigned int boneLo;
    unsigned int boneHi;
    Vec3_166fc0 offset;
    Vec3_166fc0 direction;
    float length;
    char invert;

    char vfunc_6(int arg0, Obj1_166fc0* target, int arg2);
};

char RayCastTargetCondition::vfunc_6(int arg0, Obj1_166fc0* target, int arg2)
{
    if (FUN_00344e74(target, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return 0;
    Holder_166fc0* holder = target->FUN_000592a0()->FUN_00059a30();
    if (holder == 0)
        return 0;

    Slot_166fc0* slot = holder->slot;
    if (slot == 0)
        return 0;
    Entity* ent = slot->entity;
    if (ent == 0)
        return 0;
    if (slot->count != 1)
        return 0;

    char hit = 0;
    Skeleton* skel = ent->skeleton;
    if (skel != 0) {
        unsigned int idx = 0;
        if ((boneLo | boneHi) != 0) {
            idx = skel->FUN_002843a0(boneLo, boneHi);
            if (idx == 0xffff)
                idx = 0;
        }
        Matrix* src = &skel->matrices[idx];

        Vec3_166fc0 res;
        Vec3_166fc0 tmp;
        Vec3_166fc0 from;
        Vec3_166fc0 dir;
        Vec3_166fc0 hitPos;
        Vec3_166fc0 hitNormal;
        Matrix mtx;

        from.x = 0; from.y = 0; from.z = 0;
        dir.x = 0; dir.y = 0; dir.z = -1.0f;
        res.x = 0; res.y = 0; res.z = 0;
        mtx = *src;

        tmp = offset;
        ((owners::Mat_22c2b0 *)&mtx)->FUN_0022c2b0((float *)(const Vec3_166fc0 *)(&tmp), (float *)(Vec3_166fc0 *)(&from));
        tmp = direction;
        ((owners::M_22c3b0 *)&mtx)->FUN_0022c3b0((float *)(const Vec3_166fc0 *)(&tmp), (float *)(Vec3_166fc0 *)(&dir));
        dir.FUN_0022d110();

        float len = length;
        res.y = dir.y * len;
        res.z = dir.z * len;
        res.x = dir.x * len + from.x;
        res.y = res.y + from.y;
        res.z = res.z + from.z;

        Entity* cur = DAT_004dd700->player->current;
        int notIgnored = 0;
        if (cur != ent && ent->ignoreA != cur && ent->ignoreB != cur)
            notIgnored = 1;

        hit = FUN_002027c0(&from, &res, 0, notIgnored, &hitNormal, &hitPos, 0, 0);
    }
    if (invert != 0)
        return hit;
    return hit == 0;
}
} // namespace fn_00166fc0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001671d0 hulkfight::motion::CharacterPropStatusCondition::vfunc_6 (160 B): equivalent/0x001671d0.cpp [wrapped: conflict: hulkfight::motion::CharacterPropStatusCondition]
// sym: ?vfunc_6@CharacterPropStatusCondition@motion@hulkfight@fn_001671d0@@UAE_NHPAUSource_1671d0@4@H@Z @de7270f7bfcd @w1eb47f25ecd9
namespace fn_001671d0 {
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 20/20)
// hulkfight::motion::CharacterPropStatusCondition::vfunc_6 @ 0x001671d0
// hulkfight::motion::CharacterPropStatusCondition::vfunc_6 @ 0x001671d0: compares a count against a threshold
struct Player_1671d0 {
    int FUN_00066530();
    int FUN_00065f60();
};
Player_1671d0 *__cdecl FUN_000678d0();

struct Slot_1671d0 {
    void *FUN_00059a30();
};
struct Source_1671d0 {
    Slot_1671d0 *FUN_000592a0();
};

namespace hulkfight {
namespace motion {
class CharacterPropStatusCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(int a, Source_1671d0 *source, int c);
    char pad04[8];
    unsigned int op;
    float threshold;
};
}
}

bool hulkfight::motion::CharacterPropStatusCondition::vfunc_6(int a, Source_1671d0 *source, int c)
{
    source->FUN_000592a0()->FUN_00059a30();
    FUN_000678d0()->FUN_00066530();
    int count = FUN_000678d0()->FUN_00065f60();
    int limit = (int)(__int64)threshold;  // _ftol: low word of the 64-bit conversion
    switch (op) {
    case 0:
        return count < limit;
    case 1:
        return count <= limit;
    case 2:
        return count == limit;
    case 3:
        return count != limit;
    case 4:
        return count >= limit;
    case 5:
        return count > limit;
    default:
        return false;
    }
}
} // namespace fn_001671d0


// 0x00167290 hulkfight::motion::TargetMotionStateCondition::vfunc_6 (100 B): equivalent/0x00167290.cpp
// sym: ?vfunc_6@TargetMotionStateCondition@motion@hulkfight@@UAE_NPAX00@Z @a74dd210a86a @wbdbe90ac11e4
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 14/14)
// hulkfight::motion::TargetMotionStateCondition::vfunc_6 @ 0x00167290
bool hulkfight::motion::TargetMotionStateCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a1 = (int)__p0; Owner_167290 * owner = (Owner_167290 *)__p1; int a3 = (int)__p2;

    Stats_167290 *st = ((Ctx_167290 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();
    Stats_167290::Slot *slot = st->f328;
    if (slot == 0 || slot->f8 == 0 || slot->fc != 1)
        return (bool)(1);
    unsigned int want = (*(unsigned int *)&this->motionState);
    unsigned int cur = slot->f8->f140;
    if (this->compare == 0)
        return (bool)(cur == want);
    if (this->compare == 1)
        return (bool)(cur != want);
    return (bool)(0);
}


// 0x00167300 hulkfight::motion::LocomotionMotionStateCondition::vfunc_6 (79 B): matches/0x00167300.cpp
// sym: ?vfunc_6@LocomotionMotionStateCondition@motion@hulkfight@@UAE_NPAX00@Z
bool hulkfight::motion::LocomotionMotionStateCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; Arg * b = (Arg *)__p1; int c = (int)__p2;

    Obj* p = b->get_000592a0()->get_00059a30();
    int x = this->locomotionMotionState;
    switch (this->compare) {
    case 0:
        return ((int)((owners::Widget_35910 *)p)->FUN_00035910()) == x;
    case 1:
        return ((int)((owners::Widget_35910 *)p)->FUN_00035910()) != x;
    default:
        return false;
    }
}


// 0x00167350 hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_6 (106 B): equivalent/0x00167350.cpp
// sym: ?vfunc_6@TargetLocomotionMotionStateCondition@motion@hulkfight@@UAE_NPAX00@Z @f7f1ed190b49 @w699a408716be
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 12/12)
// hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_6 @ 0x00167350
bool hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * a1 = (void *)__p0; Target_167350 * target = (Target_167350 *)__p1; void * a3 = (void *)__p2;

    Locomotion_167350* loco = ((Body_167350 *)((owners::Object_592a0 *)target)->FUN_000592a0())->FUN_00059a30()->locomotion;
    if (loco == 0 || loco->state == 0 || loco->kind != 1)
        return false;
    int want = this->locomotionMotionState;
    switch (this->compare) {
    case 0:
        return ((int)((owners::Widget_35910 *)(loco->state))->FUN_00035910()) == want;
    case 1:
        return ((int)((owners::Widget_35910 *)(loco->state))->FUN_00035910()) != want;
    }
    return false;
}


// 0x001673c0 hulkfight::motion::RageModeStateCondition::vfunc_6 (70 B): matches/0x001673c0.cpp
// sym: ?vfunc_6@RageModeStateCondition@motion@hulkfight@@UAE_NPAX00@Z
bool hulkfight::motion::RageModeStateCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; hulk_intptr c = (hulk_intptr)__p2;

    ObjMid* m = ((ObjMid *)((owners::Object_592a0 *)(((ObjA_1673c0*)b)))->FUN_000592a0());
    ObjEnd* e = m->Call2_00059a30();
    int v = e->field;
    switch (this->compare) {
    case 0:
        return v == this->rageMode;
    case 1:
        return v != this->rageMode;
    default:
        return false;
    }
}

namespace fn_fa2e0d0f {

// 0x00167410 hulkfight::motion::ChargeCondition::vfunc_5 (36 B): matches/0x00167410.cpp
// sym: ?vfunc_5@ChargeCondition_167410@fn_fa2e0d0f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ChargeCondition_167410* ChargeCondition_167410::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416658;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167440 hulkfight::motion::TargetMotionStateCondition::vfunc_5 (36 B): matches/0x00167440.cpp
// sym: ?vfunc_5@TargetMotionStateCondition_167440@fn_fa2e0d0f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TargetMotionStateCondition_167440* TargetMotionStateCondition_167440::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416678;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167470 hulkfight::motion::IntentionButtonDownAnyCondition::vfunc_5 (36 B): matches/0x00167470.cpp
// sym: ?vfunc_5@IntentionButtonDownAnyCondition_167470@fn_fa2e0d0f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
IntentionButtonDownAnyCondition_167470* IntentionButtonDownAnyCondition_167470::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416698;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001674a0 hulkfight::motion::VelocityCondition::vfunc_5 (36 B): matches/0x001674a0.cpp
// sym: ?vfunc_5@VelocityCondition_1674a0@fn_fa2e0d0f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
VelocityCondition_1674a0* VelocityCondition_1674a0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004166b8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001674d0 hulkfight::motion::VelocityYCondition::vfunc_5 (36 B): matches/0x001674d0.cpp
// sym: ?vfunc_5@VelocityYCondition_1674d0@fn_fa2e0d0f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
VelocityYCondition_1674d0* VelocityYCondition_1674d0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004166d8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167500 hulkfight::motion::VelocityAnimatedXZCondition::vfunc_5 (36 B): matches/0x00167500.cpp
// sym: ?vfunc_5@VelocityAnimatedXZCondition_167500@fn_fa2e0d0f@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
VelocityAnimatedXZCondition_167500* VelocityAnimatedXZCondition_167500::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004166f8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167530 hulkfight::motion::RayCastTargetCondition::vfunc_5 (46 B): matches/0x00167530.cpp
// sym: ?vfunc_5@RayCastTargetCondition_167530@fn_fa2e0d0f@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
RayCastTargetCondition_167530* RayCastTargetCondition_167530::vfunc_5(unsigned char param) {
    RayCastTargetCondition_167530* p = this;
    *(char**)p = &hulk_at_00416718;
    ((RayCastConeCondition_nv_167530*)(((hulkfight::motion::RayCastConeCondition*)(((hulkfight::motion::RayCastConeCondition*)((char*)p + 0x10))))))->f1_0027af50();
    ((RayCastConeCondition_nv_167530*)(((hulkfight::motion::RayCastConeCondition*)(((hulkfight::motion::RayCastConeCondition*)p)))))->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::motion::RayCastConeCondition*)p);
    return p;
}

} // namespace fn_fa2e0d0f
