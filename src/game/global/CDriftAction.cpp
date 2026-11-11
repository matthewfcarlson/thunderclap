// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001fc60..0x00020020 (kind game, layer game, confidence medium), dominant class CDriftAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f47061e1 {
#define TREE_TU_END }
namespace fn_f47061e1 {} using namespace fn_f47061e1;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f47061e1 {
extern void* hulk_at_003f3390[];
class Ref_1fcc0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_1fcc0 {
  public:
    void* vptr;
};
class COrientTargetAction_1fcc0 : public CAction_1fcc0 {
  public:
    char pad_1c[0x18];
    Ref_1fcc0* m1c;
    char pad_28[0x8];
    Ref_1fcc0* m28;
    ~COrientTargetAction_1fcc0();
};
extern void* g_vftable_1fe30[];
class Ref_1fe30 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1fe30 {
  public:
    void* vptr;
};
class CAction_1fe30 : public Action_1fe30 {
  public:
    char pad[0x18];
    Ref_1fe30* m1c;
    ~CAction_1fe30();
};

} // namespace fn_f47061e1

// 0x0001fc60 FUN_0001fc60 (85 B): matches/0x0001fc60.cpp [wrapped: merged class would differ: COrientTargetAction: field target missing]
// sym: ??0COrientTargetAction@fn_0001fc60@@QAE@HPAVTarget@1@H@Z
namespace fn_0001fc60 {
class Target {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_1fc60 {
  public:
    Action_1fc60();
    virtual void V();
};
class CAction : public Action_1fc60 {
  public:
    virtual void V();
    char pad[24];
    Target* target;
    int arg;
    int val;
    CAction(Target* t, int b) : Action_1fc60() {
        target = 0;
        if (t)
            t->Add();
        if (target)
            target->Release();
        target = t;
        val = b;
    }
};
class COrientTargetAction : public CAction {
  public:
    COrientTargetAction(int a, Target* t, int b);
    virtual void V();
    int zero;
};
COrientTargetAction::COrientTargetAction(int a, Target* t, int b) : CAction(t, b) {
    zero = 0;
    arg = a;
}
} // namespace fn_0001fc60

namespace fn_f47061e1 {

// 0x0001fcc0 FUN_0001fcc0 (61 B): matches/0x0001fcc0.cpp
// sym: ??1COrientTargetAction_1fcc0@fn_f47061e1@@QAE@XZ
COrientTargetAction_1fcc0::~COrientTargetAction_1fcc0() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_1fcc0 *)this)->FUN_002326a0();
}

} // namespace fn_f47061e1

// 0x0001fd00 COrientTargetAction::vfunc_7 (223 B): matches/0x0001fd00.cpp [wrapped: conflict: COrientTargetAction]
// sym: ?vfunc_7@COrientTargetAction@fn_0001fd00@@UAE_NM@Z
namespace fn_0001fd00 {
struct Angle_1fd00 {
    hulk_freg FUN_000354c0();
    void FUN_00221d20(float);
};
struct Link2_1fd00 {
    Angle_1fd00* FUN_00059a30();
};
struct Link1_1fd00 {
    Link2_1fd00* FUN_000592a0();
};
struct Settings_1fd00 {
    char pad[20];
    float speed;
    float offset;
};
struct Destination_1fd00 {
    char pad[24];
    Angle_1fd00 angle;
};
hulk_freg __cdecl FUN_00224fc0(float, float);
struct COrientTargetAction {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(float);
    virtual void vfunc_8();
    char pad[24];
    Link1_1fd00* source;
    Settings_1fd00* settings;
    Angle_1fd00* target;
    Destination_1fd00* destination;
};
bool COrientTargetAction::vfunc_7(float dt) {
    if (!destination)
        return false;
    float current = source->FUN_000592a0()->FUN_00059a30()->FUN_000354c0();
    hulk_freg heading = target->FUN_000354c0();   // st0: added unrounded (clang would round a float local)
    float desired = heading + settings->offset;
    if (settings->speed < 0.0f)
        current = desired;
    else {
        float delta = FUN_00224fc0(current, desired);
        float step = dt * settings->speed;
        union {
            float f;
            unsigned int u;
        } absolute;
        absolute.f = delta;
        absolute.u &= 0x7fffffff;
        if (absolute.f <= step)
            current = desired;
        else if (delta < 0.0f)
            current -= step;
        else
            current += step;
    }
    destination->angle.FUN_00221d20(current);
    return true;
}
} // namespace fn_0001fd00


// 0x0001fde0 FUN_0001fde0 (71 B): matches/0x0001fde0.cpp [wrapped: merged class would differ: CAction: size 40 vs 36]
// sym: ??0CDriftAction@fn_0001fde0@@QAE@HPAVIRef_1fde0@1@@Z
namespace fn_0001fde0 {
class IRef_1fde0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1fde0 {
  public:
    virtual void VFunc_00018b30();
    Action_1fde0();
};

class CAction : public Action_1fde0 {
  public:
    char m_pad[0x18];
    IRef_1fde0* m_pRef;
    int m_param;
    virtual void Process_00018b40();
    CAction(int a, IRef_1fde0* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CDriftAction : public CAction {
  public:
    virtual void ProcessDrift();
    CDriftAction(int a, IRef_1fde0* p);
};

CDriftAction::CDriftAction(int a, IRef_1fde0* p) : CAction(a, p) {}
} // namespace fn_0001fde0

namespace fn_f47061e1 {

// 0x0001fe30 FUN_0001fe30 (36 B): matches/0x0001fe30.cpp
// sym: ??1CAction_1fe30@fn_f47061e1@@QAE@XZ
CAction_1fe30::~CAction_1fe30() {
    vptr = g_vftable_1fe30;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1fe30 *)this)->FUN_002326a0();
}

} // namespace fn_f47061e1

// 0x0001fe60 CDriftAction::vfunc_7 (448 B): equivalent/0x0001fe60.cpp [wrapped: conflict: CDriftAction]
// sym: ?vfunc_7@CDriftAction@fn_0001fe60@@UAE_NM@Z @e0c844c4d74c @w534b0c885c4a
namespace fn_0001fe60 {
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 7/8, incomplete)
// CDriftAction::vfunc_7 @ 0x0001fe60

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_1fe60 {
    float x, y, z;
};

struct Player_1fe60 {
    char pad0[0x2064];
    float f2064;
    float f2068;
    float f206c;
    float f2070;
    bool FUN_00035550(V3_1fe60 *out);
    bool FUN_000356c0(V3_1fe60 *out);
    hulk_freg FUN_000354c0();
    void FUN_000357a0(const V3_1fe60 *v);
};

struct Mgr_1fe60 {
    Player_1fe60 *FUN_00059a30();
};

struct Holder_1fe60 {
    Mgr_1fe60 *FUN_000592a0();
};

struct Cfg_1fe60 {
    char pad0[0x14];
    float c14;
    float c18;
};

void FUN_00224d70(float angle, V3_1fe60 *v);

class CDriftAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(float arg);
    char pad[0x1c - 4];
    Holder_1fe60 *f1c;
    Cfg_1fe60 *f20;
};

bool CDriftAction::vfunc_7(float arg)
{
    struct Frame {
        float dot;
        float s;
        float L;
        V3_1fe60 h;
        V3_1fe60 g;
        V3_1fe60 k;
    } fr;
    Mgr_1fe60 *mgr = f1c->FUN_000592a0();
    Player_1fe60 *pl = mgr->FUN_00059a30();
    fr.s = pl->f2070;
    if (!(fr.s > 0.0f))
        return true;

    fr.g.x = 0.0f;
    fr.g.y = 0.0f;
    fr.g.z = 0.0f;
    pl->FUN_00035550(&fr.g);
    double d = fr.g.y * pl->f2068 + fr.g.z * pl->f206c + fr.g.x * pl->f2064;
    fr.dot = (float)d;
    if (d > 0.0) {
        Cfg_1fe60 *cfg = f20;
        fr.h.x = 0.0f;
        fr.h.y = 0.0f;
        fr.h.z = -((cfg->c14 + (cfg->c18 - cfg->c14) * fr.s) * fr.dot * arg);
        float g1 = pl->FUN_000354c0();
        FUN_00224d70(g1, &fr.h);
        pl->FUN_000357a0(&fr.h);
    } else {
        fr.h.x = 0.0f;
        fr.h.y = 0.0f;
        fr.h.z = 0.0f;
        pl->FUN_000356c0(&fr.h);
        fr.h.y = 0.0f;
        if (!(fr.h.x * fr.g.x + fr.h.z * fr.g.z + fr.g.y * 0.0f > 0.0f))
            return true;
        Cfg_1fe60 *cfg = f20;
        fr.L = (float)sqrt(fr.h.z * fr.h.z + fr.h.x * fr.h.x);
        float A = cfg->c14 + (cfg->c18 - cfg->c14) * fr.s;
        float B = A;
        if (fr.L - A < 0.0f)
            B = fr.L;
        fr.k.x = 0.0f;
        fr.k.y = 0.0f;
        fr.k.z = -(B * fr.dot * arg);
        float g1 = pl->FUN_000354c0();
        FUN_00224d70(g1, &fr.k);
        pl->FUN_000357a0(&fr.k);
    }
    return true;
}
} // namespace fn_0001fe60

