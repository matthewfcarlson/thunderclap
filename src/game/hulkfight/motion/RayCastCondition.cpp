// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001677b0..0x00168280 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f88f56f3 {
#define TREE_TU_END }
namespace fn_f88f56f3 {} using namespace fn_f88f56f3;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f88f56f3 {
extern void* hulk_at_004168b8[];
class Condition_1677b0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class VelocityXZAngleCondition_1677b0 : public Condition_1677b0 {
  public:
    VelocityXZAngleCondition_1677b0* vfunc_5(signed char flags);
};
extern char hulk_at_004168d8;
struct RayCastCondition_nv_1677e0 {
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(hulkfight::motion::RayCastCondition*);
class RayCastCondition_1677e0 {
  public:
    void* vftable;
    char pad[0x0c];
    RayCastCondition_1677e0* vfunc_5(unsigned char);
};
extern void* hulk_at_004168f8[];
class Condition_167810 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class InLoadedRoomCondition_167810 : public Condition_167810 {
  public:
    InLoadedRoomCondition_167810* vfunc_5(signed char flags);
};
extern void* hulk_at_00416918[];
class Condition_167840 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class VelocityXZCondition_167840 : public Condition_167840 {
  public:
    VelocityXZCondition_167840* vfunc_5(signed char flags);
};
extern void* hulk_at_00416938[];
class Condition_167870 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class VelocityAnimatedXZAngleCondition_167870 : public Condition_167870 {
  public:
    VelocityAnimatedXZAngleCondition_167870* vfunc_5(signed char flags);
};
extern void* hulk_at_00416958[];
class Condition_1678a0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class RageModeStateCondition_1678a0 : public Condition_1678a0 {
  public:
    RageModeStateCondition_1678a0* vfunc_5(signed char flags);
};
extern void* hulk_at_00416978[];
class Condition_1678d0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class ShoreNearCondition_1678d0 : public Condition_1678d0 {
  public:
    ShoreNearCondition_1678d0* vfunc_5(signed char flags);
};
extern void* hulk_at_00416998[];
class Condition_167900 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class HealthPercentCondition_167900 : public Condition_167900 {
  public:
    HealthPercentCondition_167900* vfunc_5(signed char flags);
};
extern void* hulk_at_004169b8[];
class Condition_167930 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class ThinkingCondition_167930 : public Condition_167930 {
  public:
    ThinkingCondition_167930* vfunc_5(signed char flags);
};
extern void* hulk_at_004169d8[];
class Condition_167960 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class VelocityAnimatedCondition_167960 : public Condition_167960 {
  public:
    VelocityAnimatedCondition_167960* vfunc_5(signed char flags);
};
extern void* hulk_at_004169f8[];
class Condition_167990 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class HealthCondition_167990 : public Condition_167990 {
  public:
    HealthCondition_167990* vfunc_5(signed char flags);
};
struct Vec3_167cc0 {
    float x, y, z;
};
struct Fighter_167cc0 {
};
struct Holder_167cc0 {
    Fighter_167cc0 *FUN_00059a30();
};
extern "C" bool FUN_00018960(float a, float b, float eps);
} // namespace fn_f88f56f3
namespace fight {
class Params_167cc0 {
public:
    virtual void v0();
    virtual void v1();
    Holder_167cc0 *FUN_000592a0();
};
}
namespace fn_f88f56f3 {
class CFightParams_167cc0 : public fight::Params_167cc0 {
public:
    virtual void v2();
};
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00494b44;
extern char DAT_00494b60;
struct Body_167e20 { float FUN_00035680(); };
struct Actor_167e20 { Body_167e20* FUN_00059a30(); };
struct Context_167e20 {  };
struct Speed_167f20 { hulk_freg FUN_00035690(); };
struct Motion_167f20 { Speed_167f20* FUN_00059a30(); };
struct Actor_167f20 {  };
struct Vec3_168120 {
    float x, y, z;
};
struct Fighter_168120 {
};
struct Holder_168120 {
    Fighter_168120 *FUN_00059a30();
};
} // namespace fn_f88f56f3
namespace fight {
class Params_168120 {
public:
    virtual void v0();
    virtual void v1();
    Holder_168120 *FUN_000592a0();
};
}
namespace fn_f88f56f3 {
class CFightParams_168120 : public fight::Params_168120 {
public:
    virtual void v2();
};


// 0x001677b0 hulkfight::motion::VelocityXZAngleCondition::vfunc_5 (36 B): matches/0x001677b0.cpp
// sym: ?vfunc_5@VelocityXZAngleCondition_1677b0@fn_f88f56f3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
VelocityXZAngleCondition_1677b0* VelocityXZAngleCondition_1677b0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004168b8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001677e0 hulkfight::motion::RayCastCondition::vfunc_5 (46 B): matches/0x001677e0.cpp
// sym: ?vfunc_5@RayCastCondition_1677e0@fn_f88f56f3@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
RayCastCondition_1677e0* RayCastCondition_1677e0::vfunc_5(unsigned char param) {
    RayCastCondition_1677e0* p = this;
    *(char**)p = &hulk_at_004168d8;
    ((RayCastCondition_nv_1677e0*)(((hulkfight::motion::RayCastCondition*)((char*)p + 0x10))))->f1_0027af50();
    ((RayCastCondition_nv_1677e0*)(((hulkfight::motion::RayCastCondition*)p)))->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::motion::RayCastCondition*)p);
    return p;
}


// 0x00167810 hulkfight::motion::InLoadedRoomCondition::vfunc_5 (36 B): matches/0x00167810.cpp
// sym: ?vfunc_5@InLoadedRoomCondition_167810@fn_f88f56f3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
InLoadedRoomCondition_167810* InLoadedRoomCondition_167810::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004168f8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167840 hulkfight::motion::VelocityXZCondition::vfunc_5 (36 B): matches/0x00167840.cpp
// sym: ?vfunc_5@VelocityXZCondition_167840@fn_f88f56f3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
VelocityXZCondition_167840* VelocityXZCondition_167840::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416918;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167870 hulkfight::motion::VelocityAnimatedXZAngleCondition::vfunc_5 (36 B): matches/0x00167870.cpp
// sym: ?vfunc_5@VelocityAnimatedXZAngleCondition_167870@fn_f88f56f3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
VelocityAnimatedXZAngleCondition_167870* VelocityAnimatedXZAngleCondition_167870::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416938;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001678a0 hulkfight::motion::RageModeStateCondition::vfunc_5 (36 B): matches/0x001678a0.cpp
// sym: ?vfunc_5@RageModeStateCondition_1678a0@fn_f88f56f3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
RageModeStateCondition_1678a0* RageModeStateCondition_1678a0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416958;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001678d0 hulkfight::motion::ShoreNearCondition::vfunc_5 (36 B): matches/0x001678d0.cpp
// sym: ?vfunc_5@ShoreNearCondition_1678d0@fn_f88f56f3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ShoreNearCondition_1678d0* ShoreNearCondition_1678d0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416978;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167900 hulkfight::motion::HealthPercentCondition::vfunc_5 (36 B): matches/0x00167900.cpp
// sym: ?vfunc_5@HealthPercentCondition_167900@fn_f88f56f3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HealthPercentCondition_167900* HealthPercentCondition_167900::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416998;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167930 hulkfight::motion::ThinkingCondition::vfunc_5 (36 B): matches/0x00167930.cpp
// sym: ?vfunc_5@ThinkingCondition_167930@fn_f88f56f3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ThinkingCondition_167930* ThinkingCondition_167930::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004169b8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167960 hulkfight::motion::VelocityAnimatedCondition::vfunc_5 (36 B): matches/0x00167960.cpp
// sym: ?vfunc_5@VelocityAnimatedCondition_167960@fn_f88f56f3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
VelocityAnimatedCondition_167960* VelocityAnimatedCondition_167960::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004169d8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167990 hulkfight::motion::HealthCondition::vfunc_5 (36 B): matches/0x00167990.cpp
// sym: ?vfunc_5@HealthCondition_167990@fn_f88f56f3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HealthCondition_167990* HealthCondition_167990::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004169f8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f88f56f3

// 0x001679c0 hulkfight::motion::RayCastCondition::vfunc_6 (756 B): equivalent/0x001679c0.cpp [wrapped: conflict: DAT_00494b44; DAT_00494b60; hulkfight::motion::RayCastCondition]
// sym: ?vfunc_6@RayCastCondition@motion@hulkfight@fn_001679c0@@UAEDHPAUObj1_1679c0@4@H@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001679c0 {
// STATUS: equivalent (tools/equiv.py level 3: 20081 inputs, branch coverage 32/34, incomplete)
// hulkfight::motion::RayCastCondition::vfunc_6 @ 0x001679c0
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

struct Vec3_1679c0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Matrix {
    float m[16];
    void FUN_0022c2b0(const Vec3_1679c0* in, Vec3_1679c0* out);
    void FUN_0022c3b0(const Vec3_1679c0* in, Vec3_1679c0* out);
};

struct Skeleton {
    char pad00[0x1c];
    Matrix* matrices;
    int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct Entity {
    char pad00[0x120];
    Skeleton* skeleton;
    char pad124[0x334 - 0x124];
    Entity* ignoreB;
    Entity* ignoreA;
};

struct Fader_1679c0 {
    void FUN_001dcf60(int on);
};

struct Player_1679c0 {
    char pad00[0x124];
    Entity* current;
    void FUN_00025260(int a, int b, int c);
};

struct World {
    char pad00[0xc];
    Fader_1679c0* fader;
    char pad10[0x10];
    Player_1679c0* player;
};

struct Obj2_1679c0 {
    Entity* FUN_00059a30();
};

struct Obj1_1679c0 {
    Obj2_1679c0* FUN_000592a0();
};

extern "C" char FUN_002027c0(Vec3_1679c0* a, Vec3_1679c0* b, int c, int d, Vec3_1679c0* hitPos, Vec3_1679c0* hitNormal, int e, int f);
extern "C" char __cdecl FUN_00202560(Vec3_1679c0* origin, float dist, int a, Vec3_1679c0* outB, Vec3_1679c0* outA, int b, int c, float* d);

namespace hulkfight {
namespace motion {
class RayCastCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual char vfunc_6(int arg0, Obj1_1679c0* target, int arg2);
    char pad04[0xc];
    unsigned int boneLo;    // 0x10
    unsigned int boneHi;    // 0x14
    Vec3_1679c0 offset;            // 0x18
    Vec3_1679c0 direction;         // 0x24
    float length;           // 0x30
    char invert;            // 0x34
    char groundCheck;       // 0x35
    char pad36[2];
    float groundTolerance;  // 0x38
};

char RayCastCondition::vfunc_6(int arg0, Obj1_1679c0* target, int arg2)
{
    if (FUN_00344e74(target, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return 0;
    Entity* ent = target->FUN_000592a0()->FUN_00059a30();

    // One contiguous frame: the stubs fill through the pointers handed to callees.
    struct {
        float ground;
        Vec3_1679c0 res;
        Vec3_1679c0 tmp;
        Vec3_1679c0 from;
        Vec3_1679c0 dir;
        Vec3_1679c0 hitNormal;
        Vec3_1679c0 hitPos;
        Matrix mtx;
    } f;

    char hit = 0;
    Skeleton* skel = ent->skeleton;
    f.res.x = 0.0f;
    f.res.y = 0.0f;
    f.res.z = 0.0f;
    if (skel != 0) {
        unsigned int idx = 0;
        if ((boneLo | boneHi) != 0) {
            idx = skel->FUN_002843a0(boneLo, boneHi);
            if (idx == 0xffff)
                idx = 0;
        }
        Matrix* src = &skel->matrices[idx];

        f.from.x = 0; f.from.y = 0; f.from.z = 0;
        f.dir.x = 0; f.dir.y = 0; f.dir.z = -1.0f;
        f.mtx = *src;

        f.tmp = offset;
        f.mtx.FUN_0022c2b0(&f.tmp, &f.from);
        f.tmp = direction;
        f.mtx.FUN_0022c3b0(&f.tmp, &f.dir);
        f.dir.FUN_0022d110();

        float len = length;
        volatile float *rv = &f.res.x; // y and z products are rounded through the frame in the original
        rv[1] = f.dir.y * len;
        rv[2] = f.dir.z * len;
        f.res.x = f.dir.x * len + f.from.x;
        rv[1] = rv[1] + f.from.y;
        rv[2] = rv[2] + f.from.z;

        Entity* cur = DAT_004dd700->player->current;
        int notIgnored = 0;
        if (cur != ent && ent->ignoreA != cur && ent->ignoreB != cur)
            notIgnored = 1;

        hit = FUN_002027c0(&f.from, &f.res, 0, notIgnored, &f.hitNormal, &f.hitPos, 0, 0);
    }

    if (groundCheck == 0) {
        if (invert != 0)
            return hit;
        return hit == 0;
    }
    if (invert != 0)
        return hit;
    if (hit != 0)
        return 0;
    if (f.res.x == 0.0f && f.res.y == 0.0f && f.res.z == 0.0f)
        return 0;

    f.ground = 0.0f;
    DAT_004dd700->player->FUN_00025260(0, 0, 0);
    DAT_004dd700->fader->FUN_001dcf60(0);
    char grounded = FUN_00202560(&f.res, 20.0f, 1, &f.tmp, &f.hitNormal, 0, 0, &f.ground);
    DAT_004dd700->player->FUN_00025260(1, 0, 0);
    DAT_004dd700->fader->FUN_001dcf60(1);

    f.ground = f.tmp.y - f.res.y;
    unsigned int bits = *(unsigned int*)&f.ground & 0x7fffffff;
    *(unsigned int*)&f.ground = bits;
    if (grounded != 0 && !(f.ground < groundTolerance))
        return 0;
    return 1;
}
}
}
} // namespace fn_001679c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00167cc0 hulkfight::motion::VelocityCondition::vfunc_6 (320 B): equivalent/0x00167cc0.cpp
// sym: ?vfunc_6@VelocityCondition@motion@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 15/16, incomplete)
// hulkfight::motion::VelocityCondition::vfunc_6 @ 0x00167cc0
bool hulkfight::motion::VelocityCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a1 = (int)__p0; fight::Params_167cc0 * params = (fight::Params_167cc0 *)__p1; int a3 = (int)__p2;

    if (dynamic_cast<CFightParams_167cc0 *>(params) == 0)
        return false;

    Fighter_167cc0 *fighter = params->FUN_000592a0()->FUN_00059a30();
    Vec3_167cc0 v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    ((owners::C_35660 *)fighter)->FUN_00035660((int *)(Vec3_167cc0 *)(&v));
    float s = (float)sqrt((double)(v.z * v.z + v.x * v.x + v.y * v.y));

    switch ((*(unsigned int *)&this->f_0c)) {
    case 0:
        return s < this->f_10;
    case 1:
        return s <= this->f_10;
    case 2:
        return FUN_00018960(s, this->f_10, 1e-05f);
    case 3:
        return !FUN_00018960(s, this->f_10, 1e-05f);
    case 4:
        return s >= this->f_10;
    case 5:
        return s > this->f_10;
    }
    return false;
}


// 0x00167e20 hulkfight::motion::VelocityYCondition::vfunc_6 (232 B): equivalent/0x00167e20.cpp
// sym: ?vfunc_6@VelocityYCondition@motion@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::VelocityYCondition::vfunc_6 @ 0x00167e20
bool hulkfight::motion::VelocityYCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Context_167e20 * context = (Context_167e20 *)__p1;

 if (!FUN_00344e74(context,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float velocity = ((Actor_167e20 *)((owners::Object_592a0 *)context)->FUN_000592a0())->FUN_00059a30()->FUN_00035680();
 switch ((*(unsigned int *)&this->f_0c)) {
 case 0: return velocity < this->f_10;
 case 1: return velocity <= this->f_10;
 case 2: return FUN_00018960(velocity,this->f_10,0.00001f);
 case 3: return !FUN_00018960(velocity,this->f_10,0.00001f);
 case 4: return velocity >= this->f_10;
 case 5: return velocity > this->f_10;
 default: return false;
 }
}


// 0x00167f20 hulkfight::motion::VelocityXZCondition::vfunc_6 (232 B): equivalent/0x00167f20.cpp
// sym: ?vfunc_6@VelocityXZCondition@motion@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::motion::VelocityXZCondition::vfunc_6 @ 0x00167f20
bool hulkfight::motion::VelocityXZCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Actor_167f20 * actor = (Actor_167f20 *)__p1;

 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 float speed = ((Motion_167f20 *)((owners::Object_592a0 *)actor)->FUN_000592a0())->FUN_00059a30()->FUN_00035690();
 switch((*(unsigned int *)&this->f_0c)) {
 case 0: return speed < this->f_10;
 case 1: return speed <= this->f_10;
 case 2: return FUN_00018960(speed,this->f_10,0.00001f);
 case 3: return !FUN_00018960(speed,this->f_10,0.00001f);
 case 4: return speed >= this->f_10;
 case 5: return speed > this->f_10;
 default: return false;
 }
}


// 0x00168020 hulkfight::motion::VelocityXZAngleCondition::vfunc_6 (254 B): equivalent/0x00168020.cpp [wrapped: conflict: DAT_00494b60; hulkfight::motion::VelocityXZAngleCondition]
// sym: ?vfunc_6@VelocityXZAngleCondition@motion@hulkfight@fn_00168020@@UAE_NPAXPAUActor_168020@4@0@Z
namespace fn_00168020 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::VelocityXZAngleCondition::vfunc_6 @ 0x00168020
struct TypeInfo_168020 { unsigned int value; }; extern TypeInfo_168020 DAT_00494b60, DAT_00494b44;
extern "C++" __declspec(nothrow) void* __cdecl FUN_00344e74(void*, int, TypeInfo_168020*, TypeInfo_168020*, int);
struct Vec_168020 { float x,y,z; };
struct Motion_168020 { void FUN_00035660(Vec_168020*); void FUN_00035550(Vec_168020*); };
struct ActorPart { Motion_168020* FUN_00059a30(); };
struct Actor_168020 { ActorPart* FUN_000592a0(); };
extern "C" hulk_freg __cdecl FUN_00224f10(Vec_168020*);
extern "C" hulk_freg __cdecl FUN_00224fc0(float,float);
namespace hulkfight { namespace motion {
struct VelocityXZAngleCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,Actor_168020*,void*);
 char pad[8]; float angle; float width;
};
bool VelocityXZAngleCondition::vfunc_6(void*,Actor_168020* actor,void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Motion_168020* m=actor->FUN_000592a0()->FUN_00059a30();
 Vec_168020 velocity={0.0f,0.0f,0.0f}; m->FUN_00035660(&velocity);
 float a=FUN_00224f10(&velocity);
 Vec_168020 direction={0.0f,0.0f,0.0f}; m->FUN_00035550(&direction);
 float b=FUN_00224f10(&direction);
 float difference=FUN_00224fc0(b,a);
 float delta=FUN_00224fc0(difference,angle);
 union {float f; unsigned int u;} absolute; absolute.f=delta; absolute.u &=0x7fffffff;
 return width*0.5f > absolute.f;
}
}}
} // namespace fn_00168020


// 0x00168120 hulkfight::motion::VelocityAnimatedCondition::vfunc_6 (320 B): equivalent/0x00168120.cpp
// sym: ?vfunc_6@VelocityAnimatedCondition@motion@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 15/16, incomplete)
// hulkfight::motion::VelocityAnimatedCondition::vfunc_6 @ 0x00168120
bool hulkfight::motion::VelocityAnimatedCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a1 = (int)__p0; fight::Params_168120 * params = (fight::Params_168120 *)__p1; int a3 = (int)__p2;

    if (dynamic_cast<CFightParams_168120 *>(params) == 0)
        return false;

    Fighter_168120 *fighter = params->FUN_000592a0()->FUN_00059a30();
    Vec3_168120 v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    ((owners::Thing_356c0 *)fighter)->FUN_000356c0((unsigned int *)(Vec3_168120 *)(&v));
    float s = (float)sqrt((double)(v.z * v.z + v.x * v.x + v.y * v.y));

    switch ((*(unsigned int *)&this->f_0c)) {
    case 0:
        return s < this->f_10;
    case 1:
        return s <= this->f_10;
    case 2:
        return FUN_00018960(s, this->f_10, 1e-05f);
    case 3:
        return !FUN_00018960(s, this->f_10, 1e-05f);
    case 4:
        return s >= this->f_10;
    case 5:
        return s > this->f_10;
    }
    return false;
}

