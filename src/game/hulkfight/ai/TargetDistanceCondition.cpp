// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00125010..0x00125820 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDistanceCondition
#include "tree_prelude.h"
#include "decls/address.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd2212ac {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fd2212ac {} using namespace fn_fd2212ac;
namespace fn_fd2212ac {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fd2212ac {
extern void* hulk_at_0040fe94[];
class Condition_125010 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class TargetDistanceXZCondition_125010 : public Condition_125010 {
  public:
    TargetDistanceXZCondition_125010* vfunc_5(signed char flags);
};
extern void* hulk_at_0040feb4[];
class Condition_125040 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class AcquireTargetCondition_125040 : public Condition_125040 {
  public:
    AcquireTargetCondition_125040* vfunc_5(signed char flags);
};
extern void* hulk_at_0040fed4[];
class Condition_125070 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class TargetVelocityXZCondition_125070 : public Condition_125070 {
  public:
    TargetVelocityXZCondition_125070* vfunc_5(signed char flags);
};
extern void* hulk_at_0040fef4[];
class Condition_1250a0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class TargetDirectionXZCondition_1250a0 : public Condition_1250a0 {
  public:
    TargetDirectionXZCondition_1250a0* vfunc_5(signed char flags);
};
extern void* hulk_at_0040ff14[];
class Condition_1250d0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class TargetFirstShotCondition_1250d0 : public Condition_1250d0 {
  public:
    TargetFirstShotCondition_1250d0* vfunc_5(signed char flags);
};
extern void* hulk_at_0040ff34[];
class Condition_125100 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class TargetInvincibleCondition_125100 : public Condition_125100 {
  public:
    TargetInvincibleCondition_125100* vfunc_5(signed char flags);
};
extern void* hulk_at_0040ff54[];
class Condition_125130 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CanSeeTargetCondition_125130 : public Condition_125130 {
  public:
    CanSeeTargetCondition_125130* vfunc_5(signed char flags);
};
extern void* hulk_at_0040ff74[];
class Track_125160 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class TargetClearTrack_125160 : public Track_125160 {
  public:
    TargetClearTrack_125160* vfunc_5(signed char flags);
};
extern void* hulk_at_0040ffa4[];
class Track_125190 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class AcquireTargetTrack_125190 : public Track_125190 {
  public:
    AcquireTargetTrack_125190* vfunc_5(signed char flags);
};
extern void* hulk_at_0040ffd4[];
class Track_1251c0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class ClearProjectileDistanceTrack_1251c0 : public Track_1251c0 {
  public:
    ClearProjectileDistanceTrack_1251c0* vfunc_5(signed char flags);
};
extern char DAT_00494b44[];
extern char DAT_00494b60[];
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
char __cdecl FUN_00018960(float a, float b, float eps);
struct V3_1251f0 {
    float x, y, z;
    bool FUN_0022d2b0(const V3_1251f0 *other, float eps);
};
struct Mgr10_1251f0 {
    bool FUN_00059a50(V3_1251f0 *out);
};
struct Obj10_1251f0 {
    char pad0[0x10];
    Mgr10_1251f0 *f10;
};
struct Target_1251f0;
struct Agent_1251f0 {
    char pad0[0x1a60];
    V3_1251f0 pos;                 // 0x1a60
};
struct Target_1251f0 {
    char pad0[8];
    Agent_1251f0 *p8;              // 0x8
    int kind;               // 0xc
    char pad10[0x40 - 0x10];
    V3_1251f0 v40;
};
struct Player_1251f0 {
    char pad0[0x10];
    Mgr10_1251f0 *f10;
    char pad14[0x328 - 0x14];
    Target_1251f0 *f328;
    char pad32c[0x1d54 - 0x32c];
    V3_1251f0 v1d54;
    int lo1d60;
    int hi1d64;
};
struct Mgr_1251f0 {
    Player_1251f0 *FUN_00059a30();
};
struct Source_1251f0 {
};
struct Mid_1251f0 {
    char pad0[0x40];
    V3_1251f0 v40;                 // 0x40
};
struct Hero_1251f0 {
    char pad0[0x12c];
    Mid_1251f0 *f12c;
    char pad130[0x1a60 - 0x130];
    V3_1251f0 pos;                 // 0x1a60
};
struct Reg_1251f0 {
    char pad0[0x124];
    Hero_1251f0 *f124;
    Obj10_1251f0 *FUN_00024280(int lo, int hi);
};
} // namespace fn_fd2212ac
struct World {
    char pad0[0x20];
    Reg_1251f0 *f20;
};
namespace fn_fd2212ac {
class TargetDistanceCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, Source_1251f0 *source, int c);
    char pad04[8];
    int mode;               // 0xc
    float threshold;        // 0x10
    char flag14;
    char flag15;
};


// 0x00125010 hulkfight::ai::TargetDistanceXZCondition::vfunc_5 (36 B): matches/0x00125010.cpp
// sym: ?vfunc_5@TargetDistanceXZCondition_125010@fn_fd2212ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TargetDistanceXZCondition_125010* TargetDistanceXZCondition_125010::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fe94;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00125040 hulkfight::ai::AcquireTargetCondition::vfunc_5 (36 B): matches/0x00125040.cpp
// sym: ?vfunc_5@AcquireTargetCondition_125040@fn_fd2212ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
AcquireTargetCondition_125040* AcquireTargetCondition_125040::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040feb4;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00125070 hulkfight::ai::TargetVelocityXZCondition::vfunc_5 (36 B): matches/0x00125070.cpp
// sym: ?vfunc_5@TargetVelocityXZCondition_125070@fn_fd2212ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TargetVelocityXZCondition_125070* TargetVelocityXZCondition_125070::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fed4;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001250a0 hulkfight::ai::TargetDirectionXZCondition::vfunc_5 (36 B): matches/0x001250a0.cpp
// sym: ?vfunc_5@TargetDirectionXZCondition_1250a0@fn_fd2212ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TargetDirectionXZCondition_1250a0* TargetDirectionXZCondition_1250a0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fef4;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001250d0 hulkfight::ai::TargetFirstShotCondition::vfunc_5 (36 B): matches/0x001250d0.cpp
// sym: ?vfunc_5@TargetFirstShotCondition_1250d0@fn_fd2212ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TargetFirstShotCondition_1250d0* TargetFirstShotCondition_1250d0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040ff14;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00125100 hulkfight::ai::TargetInvincibleCondition::vfunc_5 (36 B): matches/0x00125100.cpp
// sym: ?vfunc_5@TargetInvincibleCondition_125100@fn_fd2212ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TargetInvincibleCondition_125100* TargetInvincibleCondition_125100::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040ff34;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00125130 hulkfight::ai::CanSeeTargetCondition::vfunc_5 (36 B): matches/0x00125130.cpp
// sym: ?vfunc_5@CanSeeTargetCondition_125130@fn_fd2212ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CanSeeTargetCondition_125130* CanSeeTargetCondition_125130::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040ff54;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00125160 hulkfight::ai::TargetClearTrack::vfunc_5 (36 B): matches/0x00125160.cpp
// sym: ?vfunc_5@TargetClearTrack_125160@fn_fd2212ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TargetClearTrack_125160* TargetClearTrack_125160::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040ff74;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00125190 hulkfight::ai::AcquireTargetTrack::vfunc_5 (36 B): matches/0x00125190.cpp
// sym: ?vfunc_5@AcquireTargetTrack_125190@fn_fd2212ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
AcquireTargetTrack_125190* AcquireTargetTrack_125190::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040ffa4;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001251c0 hulkfight::ai::ClearProjectileDistanceTrack::vfunc_5 (36 B): matches/0x001251c0.cpp
// sym: ?vfunc_5@ClearProjectileDistanceTrack_1251c0@fn_fd2212ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ClearProjectileDistanceTrack_1251c0* ClearProjectileDistanceTrack_1251c0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040ffd4;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001251f0 hulkfight::ai::TargetDistanceCondition::vfunc_6 (680 B): equivalent/0x001251f0.cpp
// sym: ?vfunc_6@TargetDistanceCondition@fn_fd2212ac@@UAEDHPAUSource_1251f0@2@H@Z @1533291ee71b @w5c3b075632c7
// STATUS: equivalent (tools/equiv.py level 3: 3037 inputs, branch coverage 42/42)
// hulkfight::ai::TargetDistanceCondition::vfunc_6 @ 0x001251f0
char TargetDistanceCondition::vfunc_6(int a, Source_1251f0 *source, int c)
{
    V3_1251f0 A;
    V3_1251f0 B;
    V3_1251f0 T;
    V3_1251f0 C;

    if (!FUN_00344e74(source, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;

    Player_1251f0 *pl = ((Mgr_1251f0 *)((owners::Object_592a0 *)source)->FUN_000592a0())->FUN_00059a30();
    A.x = 0.0f;
    A.y = 0.0f;
    A.z = 0.0f;
    B.x = 0.0f;
    B.y = 0.0f;
    B.z = 0.0f;
    pl->f10->FUN_00059a50(&A);
    Target_1251f0 *tgt = pl->f328;

    if (flag14) {
        Hero_1251f0 *x = DAT_004dd700->f20->f124;
        if (x) {
            Mid_1251f0 *y = x->f12c;
            if (flag15 == 0)
                T = y->v40;
            else
                T = x->pos;
        }
    } else {
        if (!tgt)
            return false;
        C = pl->v1d54;
        bool done = false;
        if (!C.FUN_0022d2b0(&B, 0.00001f)) {
            Reg_1251f0 *reg = DAT_004dd700->f20;
            if (reg) {
                Obj10_1251f0 *o = reg->FUN_00024280(pl->lo1d60, pl->hi1d64);
                if (o) {
                    o->f10->FUN_00059a50(&T);
                    done = true;
                }
            }
        }
        if (!done) {
            if (tgt->kind == 1 && tgt->p8 && flag15)
                T = tgt->p8->pos;
            else
                T = tgt->v40;
        }
    }

    float dist = (float)sqrt((double)((T.z - A.z) * (T.z - A.z) + (T.y - A.y) * (T.y - A.y) + (T.x - A.x) * (T.x - A.x)));

    switch (mode) {
    case 0:
        return dist < threshold;
    case 1:
        return dist <= threshold;
    case 2:
        return FUN_00018960(dist, threshold, 0.00001f);
    case 3:
        return FUN_00018960(dist, threshold, 0.00001f) == 0;
    case 4:
        return dist >= threshold;
    case 5:
        return dist > threshold;
    }
    return false;
}

} // namespace fn_fd2212ac

// 0x001254b0 hulkfight::ai::ProjectileDistanceCondition::vfunc_6 (435 B): equivalent/0x001254b0.cpp [wrapped: conflict: FUN_00018960]
// sym: ?vfunc_6@ProjectileDistanceCondition@fn_001254b0@@UAE_NHPAVParams@fight@2@H@Z @027c9894bf72 @w3bdd1ff3b76c
namespace fn_001254b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3239 inputs, branch coverage 32/32; Wine build 740 inputs, 32/32)
// hulkfight::ai::ProjectileDistanceCondition::vfunc_6 @ 0x001254b0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_1254b0 {
    float x, y, z;
};

struct Aim_1254b0 {
    bool FUN_00059a50(V3_1254b0 *out);
};

struct Body_1254b0 {
    char pad0[0x1c9];
    char flag;
};

struct Weapon_1254b0 {
    char pad0[0x1b0];
    int state;
};

struct Rig_1254b0 {
    char pad0[0x11c];
    Weapon_1254b0 *weapon;
};

struct Target_1254b0 {
    char pad0[8];
    Rig_1254b0 *rig;             // 0x08 (a Body when type == 5)
    int type;             // 0x0c
    char pad10[0x40 - 0x10];
    V3_1254b0 pos;               // 0x40
};

struct Fighter_1254b0 {
    char pad0[0x10];
    Aim_1254b0 *aim;
    Target_1254b0 *FUN_00037400();
};

struct Holder_1254b0 {
    Fighter_1254b0 *FUN_00059a30();
};

namespace fight {
class Params {
public:
    virtual void v0();
    Holder_1254b0 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v1();
};

bool __cdecl FUN_00018960(float a, float b, float eps);

class ProjectileDistanceCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int b);
    char pad04[0x0c - 4];
    int op;             // 0x0c
    float threshold;    // 0x10
    char requireLive;   // 0x14
    char skipNonBody;   // 0x15
};

bool ProjectileDistanceCondition::vfunc_6(int a, fight::Params *params, int b)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;

    Fighter_1254b0 *f = params->FUN_000592a0()->FUN_00059a30();
    V3_1254b0 origin;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    f->aim->FUN_00059a50(&origin);

    Target_1254b0 *t = f->FUN_00037400();
    if (t == 0)
        return false;

    int type = t->type;
    if (type == 5) {
        if (((Body_1254b0 *)t->rig)->flag == 0)
            return false;
    } else {
        if (skipNonBody != 0)
            return false;
    }

    if (requireLive != 0) {
        if (type != 1)
            return false;
        if (t->rig != 0) {
            if (t->rig->weapon->state != 3)
                return false;
        }
    }

    V3_1254b0 *p = &t->pos;
    float dx = p->x - origin.x;
    float dy = p->y - origin.y;
    float dz = p->z - origin.z;
    float dist = (float)sqrt(dz * dz + dy * dy + dx * dx);

    switch (op) {
    case 0:
        return dist < threshold;
    case 1:
        return dist <= threshold;
    case 2:
        return FUN_00018960(dist, threshold, 1e-05f);
    case 3:
        return !FUN_00018960(dist, threshold, 1e-05f);
    case 4:
        return dist >= threshold;
    case 5:
        return dist > threshold;
    }
    return false;
}
} // namespace fn_001254b0


// 0x00125680 hulkfight::ai::TargetDistanceXZCondition::vfunc_6 (382 B): equivalent/0x00125680.cpp [wrapped: conflict: World]
// sym: ?vfunc_6@TargetDistanceXZCondition@fn_00125680@@UAEDHPAUOwner_125680@2@H@Z @6544b18ab1fe @w0656e51860a9
namespace fn_00125680 {
// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 26/28, incomplete)
// hulkfight::ai::TargetDistanceXZCondition::vfunc_6 @ 0x00125680
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif

extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
char __cdecl FUN_00018960(float a, float b, float epsilon);

struct Vec3_125680 {
    float x, y, z;
};

struct TargetObj {
    char pad0[0x1a60];
    float x;
    float y;
    float z;
};

struct Target_125680 {
    char pad0[8];
    TargetObj *obj;
    int kind;
    char pad10[0x30];
    Vec3_125680 pos;
};

struct Locator {
    char pad0[0x12c];
    Target_125680 *target;
};

struct Slot_125680 {
    char pad0[0x124];
    Locator *locator;
};

struct World {
    char pad0[0x20];
    Slot_125680 *slot;
};


struct Position_125680 {
    void FUN_00059a50(Vec3_125680 *out);
};

struct Actor_125680 {
    char pad0[0x10];
    Position_125680 *position;
    char pad14[0x314];
    Target_125680 *target;
};

struct Chain_125680 {
    Actor_125680 *FUN_00059a30();
};

struct Owner_125680 {
};

class TargetDistanceXZCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int unused1, Owner_125680 *owner, int unused3);
    char pad4[8];
    int mode;
    float threshold;
    char useLocator;
    char useObj;
};

char TargetDistanceXZCondition::vfunc_6(int unused1, Owner_125680 *owner, int unused3)
{
    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Actor_125680 *actor = ((Chain_125680 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();
    Vec3_125680 origin;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    actor->position->FUN_00059a50(&origin);
    Target_125680 *t = actor->target;
    if (useLocator) {
        Locator *loc = DAT_004dd700->slot->locator;
        if (loc)
            t = loc->target;
    }
    if (!t)
        return 0;
    float tx, tz;
    if (t->kind == 1 && t->obj && useObj) {
        tx = t->obj->x;
        tz = t->obj->z;
    } else {
        tx = t->pos.x;
        tz = t->pos.z;
    }
    float dx = tx - origin.x;
    float dz = tz - origin.z;
    float dist = (float)sqrt(dz * dz + dx * dx);
    switch (mode) {
    case 0:
        return dist < threshold;
    case 1:
        return dist <= threshold;
    case 2:
        return FUN_00018960(dist, threshold, 1e-5f);
    case 3:
        return !FUN_00018960(dist, threshold, 1e-5f);
    case 4:
        return dist >= threshold;
    case 5:
        return dist > threshold;
    }
    return 0;
}
} // namespace fn_00125680
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

