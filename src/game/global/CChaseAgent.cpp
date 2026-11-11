// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000fc800..0x000fcd30 (kind game, layer game, confidence high), dominant class CChaseAgent
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0405f54 {
#define TREE_TU_END }
namespace fn_f0405f54 {} using namespace fn_f0405f54;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0405f54 {
struct Binding_fc970;
struct Unit_fc970 {
    char pad0[8];
    Binding_fc970 *binding;
    char pad0c[0x12 - 0xc];
    char flag12;
    char pad13;
    float f14;
    char pad18[0x45 - 0x18];
    char flag45;
    char pad46[0x70 - 0x46];
    char flag70;
    char flag71;
    bool FUN_000fc900();
};
struct Stats_fc970 {
    char pad0[0x3a0];
    float limit;
};
struct Weapon_fc970 {
    char pad0[0x11c];
    Stats_fc970 *stats;
};
struct Mode_fc970 {
    char pad0[0x140];
    int kind;
};
struct Binding_fc970 {
    char pad0[8];
    Mode_fc970 *mode;
    int type;
};
class Brain_fc970 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Weapon_fc970 *v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
    char pad[0x58 - 4];
    Unit_fc970 unit;
};
struct CChaseAgent_nv_fc970 {
    float FUN_000fc4e0(Unit_fc970 *u, int a);
};
typedef unsigned int u32_fcb10;
struct CCharacterAgent_fcb10 {
    void InitBase(u32_fcb10);
};
struct CChaseAgent_nv_fcb10 {
    void InitBase_000fc760(u32_fcb10);
};
extern char hulk_at_0040d034;
extern void* CCharacterAgent_fcb40_vftable[];
class CCharacterAgent_fcb40 {
  public:
    void Destroy_000fc630(); // FUN_00236d60, __thiscall, this in ecx
};
class CChaseAgent_fcb40 : public CCharacterAgent_fcb40 {
  public:
    CChaseAgent_fcb40* vfunc_5(signed char flags);
};

} // namespace fn_f0405f54

// 0x000fc800 FUN_000fc800 (36 B): matches/0x000fc800.cpp
// sym: ?FUN_000fc800@Obj_fc800@owners@@QAE_NXZ
// data: threshold_fc800 = DAT_003f5d00
bool owners::Obj_fc800::FUN_000fc800() {
    if (flag12)
        return true;
    if (!(value < DAT_003f5d00) && !flag10)
        return false;
    return true;
}


// 0x000fc830 FUN_000fc830 (18 B): matches/0x000fc830.cpp
// sym: ?FUN_000fc830@C_fc830@owners@@QAEMXZ
// data: gZero_fc830 = DAT_003f32e0
float owners::C_fc830::FUN_000fc830() {
    if (flag)
        return DAT_003f32e0;
    return value;
}


// 0x000fc850 FUN_000fc850 (53 B): matches/0x000fc850.cpp
// sym: ?FUN_000fc850@Obj_fc850@owners@@QAEHXZ
int owners::Obj_fc850::FUN_000fc850() {
    if ((!c && !(x < 0.1f) && !a) || !d) {
        if (!b)
            return 0;
    }
    return 1;
}


// 0x000fc890 FUN_000fc890 (55 B): matches/0x000fc890.cpp
// sym: ?FUN_000fc890@Obj_fc890@owners@@QAEMXZ
float owners::Obj_fc890::FUN_000fc890()
{
    bool direct = !flag12 && !(threshold < 0.1f) && !flag10;
    if ((!direct && flag13) || flag11)
        return 0.0f;
    return value;
}


// 0x000fc900 FUN_000fc900 (23 B): matches/0x000fc900.cpp
// sym: ?FUN_000fc900@X_fc900@owners@@QAEHXZ
int owners::X_fc900::FUN_000fc900() {
    return a && b;
}


// 0x000fc950 CChaseAgent::vfunc_9 (19 B): matches/0x000fc950.cpp
// sym: ?vfunc_9@CChaseAgent@@UAEXXZ
void CChaseAgent::vfunc_9() {
    this->f_08 = 0;
    this->f_68 = (int)0xbf800000;
    this->f_70 = 0;
    *((unsigned char*)this + 0x6c) = 0;
}


// 0x000fc970 CChaseAgent::vfunc_3 (351 B): equivalent/0x000fc970.cpp
// sym: ?vfunc_3@CChaseAgent@@UAEMHH@Z @33356ab84ef8 @we842c03a254a
// STATUS: equivalent (tools/equiv.py level 3: 3081 inputs, branch coverage 40/40)
// CChaseAgent::vfunc_3 @ 0x000fc970
hulk_freg CChaseAgent::vfunc_3(hulk_intptr __p0, int a) { Unit_fc970 * arg = (Unit_fc970 *)__p0;

    ((CChaseAgent_nv_fc970*)this)->FUN_000fc4e0(arg, a);
    Binding_fc970 *bind = (*(Brain_fc970 * *)&this->f_58)->unit.binding;
    Unit_fc970 *u = &(*(Brain_fc970 * *)&this->f_58)->unit;
    (*(float *)&this->f_08) = 0.0f;
    if (!bind)
        return 0.0f;

    Weapon_fc970 *w = (*(Brain_fc970 * *)&this->f_58)->v6();
    if (!w)
        return (*(float *)&this->f_08);
    if ((*(Brain_fc970 * *)&this->f_58)->v9() < 2)
        return (*(float *)&this->f_08);

    int kind = 0;
    if (bind->type == 1)
        kind = bind->mode->kind;
    bool is3 = (kind == 3);
    bool is2 = (kind == 2);
    bool ready = false;
    if (((int)((owners::C_35ef0 *)w)->FUN_00035ef0((hulk_intptr)0))) {
        if (w->stats->limit >= 4.0f)
            ready = true;
    }

    bool reset = false;
    if (!is3 && !is2) {
        if (u->FUN_000fc900() && (!ready || !u->flag45))
            reset = true;
        if (!reset && ready) {
            if (((owners::Obj_fc890 *)u)->FUN_000fc890() > 1.5f)
                reset = true;
        }
        if (!reset && u->flag70) {
            if (((owners::C_fc830 *)u)->FUN_000fc830() > 2.5f)
                reset = true;
        }
    }
    if (reset) {
        (*(float *)&this->f_08) = 50.0f;
        this->f_6c = 0;
        return (*(float *)&this->f_08);
    }

    if (!u->flag12 && u->f14 > 2.5f && (*(float *)&this->f_70) > 0.0f) {
        this->f_6c = 1;
        (*(float *)&this->f_08) = 50.0f;
    }
    return (*(float *)&this->f_08);
}


// 0x000fcad0 CChaseAgent::vfunc_7 (62 B): equivalent/0x000fcad0.cpp [wrapped: conflict: CChaseAgent]
// sym: ?vfunc_7@CChaseAgent@fn_000fcad0@@UAEXH@Z @14d0909148e9 @wfe967db2b171
namespace fn_000fcad0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CChaseAgent::vfunc_7 @ 0x000fcad0
struct ChaseState { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void set(int); };
struct ChaseSource { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual int lookup(const char*, unsigned int); ChaseState* FUN_000fefc0(); };
struct CChaseAgent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(int); virtual void vfunc_8(int); char pad[0x58-4]; ChaseSource* source; };
void CChaseAgent::vfunc_7(int enabled) { if ((char)enabled) vfunc_8(source->lookup("Chase", 0xffff0000)); source->FUN_000fefc0()->set(enabled); }
} // namespace fn_000fcad0


// 0x000fcb10 FUN_000fcb10 (43 B): matches/0x000fcb10.cpp
// sym: ?FUN_000fcb10@CChaseAgent@@QAEPAV1@I@Z
CChaseAgent* CChaseAgent::FUN_000fcb10(unsigned int __p0) { u32_fcb10 x = (u32_fcb10)__p0;

    ((CChaseAgent_nv_fcb10*)(((CCharacterAgent_fcb10*)this)))->InitBase_000fc760(x);
    (*(u32_fcb10 *)&this->f_08) = 0;
    (*(u32_fcb10 *)&this->f_70) = 0;
    this->f_6c = 0;
    *(hulk_uintptr*)this = (hulk_uintptr)&hulk_at_0040d034;
    (*(float *)&this->f_68) = -1.0f;
    return (CChaseAgent*)(this);
}

namespace fn_f0405f54 {

// 0x000fcb40 CChaseAgent::vfunc_2 (36 B): matches/0x000fcb40.cpp
// sym: ?vfunc_5@CChaseAgent_fcb40@fn_f0405f54@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CChaseAgent_fcb40* CChaseAgent_fcb40::vfunc_5(signed char flags) {
    *(void***)this = CCharacterAgent_fcb40_vftable;
    Destroy_000fc630();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f0405f54

// 0x000fcb70 CChaseAgent::vfunc_4 (437 B): equivalent/0x000fcb70.cpp [wrapped: conflict: CChaseAgent]
// sym: ?vfunc_4@CChaseAgent@fn_000fcb70@@UAEXPAXMH@Z @50ea76bdbec0 @w9f5f1e446efa
namespace fn_000fcb70 {
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 18/18)
// CChaseAgent::vfunc_4 @ 0x000fcb70

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_fcb70 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Clock;
extern "C" Clock *__cdecl FUN_000964d0();

struct Anchor_fcb70 {
    char pad0[0x10];
    char FUN_00059a50(V3_fcb70 *out);
};

struct Latch {
    char FUN_00231ee0();
};

struct NameHolder_fcb70 {
    void FUN_0027b040(const char *name);
};

struct Player_fcb70 {
    char pad0[0x10];
    struct Anchor_fcb70 *anchor;
    char pad14[0xdc - 0x14];
    Latch latch;
    char padDd[0x1ce4 - 0xdd];
    float f1ce4;
    char pad1ce8[0x2098 - 0x1ce8];
    NameHolder_fcb70 gestureName;
    char pad2099[0x20a0 - 0x2099];
    unsigned char gestureFlag;
};

struct Unit_fcb70 {
    char pad0[0x12];
    char flag12;
    char pad13;
    float f14;
    char pad18[0x28 - 0x18];
    V3_fcb70 target;
    void FUN_000fde40(V3_fcb70 *out);
    void FUN_000fde60(V3_fcb70 *out);
};

struct Marker_fcb70 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void *a, float b, int c);
    void FUN_001048d0(void *agent);
    void FUN_00104c60(void *a, V3_fcb70 *p, V3_fcb70 *q, float f0, int zero, float f1, float f2);
};

class Brain_fcb70 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Player_fcb70 *v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
    char pad[0x58 - 4];
    Unit_fcb70 unit;
    Marker_fcb70 *FUN_000fefc0();
};


class CChaseAgent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(void *a, float b, int c);
    char pad04[0x58 - 4];
    Brain_fcb70 *brain;
    char pad5c[0x6c - 0x5c];
    char engaged;
    char pad6d[3];
    float f70;
    void FUN_000fc550(void *a, float b, int c);
};

void CChaseAgent::vfunc_4(void *a, float b, int c)
{
    V3_fcb70 pos;
    V3_fcb70 dir;
    V3_fcb70 flat;

    FUN_000964d0();
    FUN_000fc550(a, b, c);
    Player_fcb70 *player = brain->v6();
    player->anchor->FUN_00059a50(&pos);
    Unit_fcb70 *unit = &brain->unit;
    if (brain != 0 && brain->v9() == 4)
        return;

    if (!engaged) {
        float v = unit->flag12 ? 0.0f : unit->f14;
        if (v < player->f1ce4)
            unit->FUN_000fde40(&dir);
        else
            unit->FUN_000fde60(&dir);
        f70 = 2.0f;
    } else {
        dir = unit->target;
        float dx = dir.x - pos.x;
        float dz = dir.z - pos.z;
        float dist = (float)sqrt(dz * dz + dx * dx);
        if (dist < 2.0f)
            f70 = f70 - b;
    }
    flat.x = dir.x - pos.x;
    flat.y = 0.0f;
    flat.z = dir.z - pos.z;
    flat.FUN_0022d110();
    char busy = player->latch.FUN_00231ee0();
    if ((char)c != 0 && !busy && brain->v9() < 3) {
        player->gestureName.FUN_0027b040("gesture_3");
        player->gestureFlag = 1;
    }
    Marker_fcb70 *marker = brain->FUN_000fefc0();
    marker->FUN_001048d0(this);
    marker->FUN_00104c60(a, &pos, &dir, 1.0f, 0, 0.5f, 1.0f);
    marker->v4(a, b, c);
}
} // namespace fn_000fcb70

