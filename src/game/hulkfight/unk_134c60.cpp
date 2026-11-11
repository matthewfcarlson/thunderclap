// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00134c60..0x00134ee0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fea6dcf4 {
#define TREE_TU_END }
namespace fn_fea6dcf4 {} using namespace fn_fea6dcf4;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_fea6dcf4 {
extern void* Track_134c60_vftable[];
class Track_134c60 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fea6dcf4
namespace hulkfight { namespace motion {
class FlyingBrakeTrack : public Track_134c60 {
  public:
    FlyingBrakeTrack* vfunc_5(signed char flags);
};
} }
namespace fn_fea6dcf4 {
extern void* Track_134c90_vftable[];
class Track_134c90 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fea6dcf4
namespace hulkfight { namespace motion {
class BounceTrack : public Track_134c90 {
  public:
    BounceTrack* vfunc_5(signed char flags);
};
} }
namespace fn_fea6dcf4 {
extern void* Track_134cc0_vftable[];
class Track_134cc0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fea6dcf4
namespace hulkfight { namespace motion {
class AirToGroundTargetTrack : public Track_134cc0 {
  public:
    AirToGroundTargetTrack* vfunc_5(signed char flags);
};
} }
namespace fn_fea6dcf4 {
extern void* Track_134cf0_vftable[];
class Track_134cf0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fea6dcf4
namespace hulkfight { namespace motion {
class HoverTrack : public Track_134cf0 {
  public:
    HoverTrack* vfunc_5(signed char flags);
};
} }
namespace fn_fea6dcf4 {
extern void* Track_134d20_vftable[];
class Track_134d20 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fea6dcf4
namespace hulkfight { namespace motion {
class FallTrack : public Track_134d20 {
  public:
    FallTrack* vfunc_5(signed char flags);
};
} }
namespace fn_fea6dcf4 {
extern void* Track_134d50_vftable[];
class Track_134d50 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fea6dcf4
namespace hulkfight { namespace motion {
class FlyingAutoTargetTrack : public Track_134d50 {
  public:
    FlyingAutoTargetTrack* vfunc_5(signed char flags);
};
} }
namespace fn_fea6dcf4 {
extern void* Track_134d80_vftable[];
class Track_134d80 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_fea6dcf4
namespace hulkfight { namespace motion {
class FlyingAttackTrack : public Track_134d80 {
  public:
    FlyingAttackTrack* vfunc_5(signed char flags);
};
} }
namespace fn_fea6dcf4 {
class Ref_134db0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
struct ThisCall_00232660 {
    void BaseCtor();
};
extern int hoverVftable;
class HoverAction {
  public:
    virtual void V();
    char pad[0x18];
    int field1c;
    Ref_134db0* field20;
    HoverAction* Init(int a, Ref_134db0* r);
};
extern void* g_vftable_134e00[];
class Ref_134e00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_134e00 {
  public:
    void* vptr;
};
class HoverAction_134e00 : public Action_134e00 {
  public:
    char pad[28];
    Ref_134e00* m;
    ~HoverAction_134e00();
};
class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_134e30 {
  public:
    virtual void fn();
    char pad[24];
    Action_134e30();
};
struct Fields {
    volatile int a;
    Ref* ref;
    int c, d, e, f, g;
    Fields() : a(0), ref(0), c(0), d(0), e(0), f(0), g(0) {}
};
class FallAction : public Action_134e30 {
  public:
    Fields fields;
    FallAction(int, Ref*);
    virtual void fn();
};
extern void* g_vftable_134e90[];
class Ref_134e90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_134e90 {
  public:
    void* vptr;
};
class FallAction_134e90 : public Action_134e90 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_134e90* m20;
    Ref_134e90* m24;
    ~FallAction_134e90();
};

} // namespace fn_fea6dcf4

// 0x00134c60 hulkfight::motion::FlyingBrakeTrack::vfunc_5 (36 B): matches/0x00134c60.cpp
// sym: ?vfunc_5@FlyingBrakeTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::FlyingBrakeTrack* hulkfight::motion::FlyingBrakeTrack::vfunc_5(signed char flags) {
    *(void***)this = Track_134c60_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00134c90 hulkfight::motion::BounceTrack::vfunc_5 (36 B): matches/0x00134c90.cpp
// sym: ?vfunc_5@BounceTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::BounceTrack* hulkfight::motion::BounceTrack::vfunc_5(signed char flags) {
    *(void***)this = Track_134c90_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00134cc0 hulkfight::motion::AirToGroundTargetTrack::vfunc_5 (36 B): matches/0x00134cc0.cpp
// sym: ?vfunc_5@AirToGroundTargetTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::AirToGroundTargetTrack* hulkfight::motion::AirToGroundTargetTrack::vfunc_5(signed char flags) {
    *(void***)this = Track_134cc0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00134cf0 hulkfight::motion::HoverTrack::vfunc_5 (36 B): matches/0x00134cf0.cpp
// sym: ?vfunc_5@HoverTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::HoverTrack* hulkfight::motion::HoverTrack::vfunc_5(signed char flags) {
    *(void***)this = Track_134cf0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00134d20 hulkfight::motion::FallTrack::vfunc_5 (36 B): matches/0x00134d20.cpp
// sym: ?vfunc_5@FallTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::FallTrack* hulkfight::motion::FallTrack::vfunc_5(signed char flags) {
    *(void***)this = Track_134d20_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00134d50 hulkfight::motion::FlyingAutoTargetTrack::vfunc_5 (36 B): matches/0x00134d50.cpp
// sym: ?vfunc_5@FlyingAutoTargetTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::FlyingAutoTargetTrack* hulkfight::motion::FlyingAutoTargetTrack::vfunc_5(signed char flags) {
    *(void***)this = Track_134d50_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00134d80 hulkfight::motion::FlyingAttackTrack::vfunc_5 (36 B): matches/0x00134d80.cpp
// sym: ?vfunc_5@FlyingAttackTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::FlyingAttackTrack* hulkfight::motion::FlyingAttackTrack::vfunc_5(signed char flags) {
    *(void***)this = Track_134d80_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

namespace fn_fea6dcf4 {

// 0x00134db0 FUN_00134db0 (65 B): matches/0x00134db0.cpp
// sym: ?Init@HoverAction@fn_fea6dcf4@@QAEPAV12@HPAVRef_134db0@2@@Z
HoverAction* HoverAction::Init(int a, Ref_134db0* r) {
    ((ThisCall_00232660*)(this))->BaseCtor();
    *(hulk_intptr*)this = (hulk_intptr)&hoverVftable;
    field1c = a;
    field20 = 0;
    if (r)
        r->AddRef();
    if (field20)
        field20->Release();
    field20 = r;
    return this;
}


// 0x00134e00 FUN_00134e00 (36 B): matches/0x00134e00.cpp
// sym: ??1HoverAction_134e00@fn_fea6dcf4@@QAE@XZ
HoverAction_134e00::~HoverAction_134e00() {
    vptr = g_vftable_134e00;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_134e00 *)this)->FUN_002326a0();
}


// 0x00134e30 FUN_00134e30 (83 B): matches/0x00134e30.cpp
// sym: ??0FallAction@fn_fea6dcf4@@QAE@HPAVRef@1@@Z
FallAction::FallAction(int v, Ref* p) : Action_134e30(), fields() {
    fields.a = v;
    if (p)
        p->AddRef();
    if (fields.ref)
        fields.ref->Release();
    fields.ref = p;
}


// 0x00134e90 FUN_00134e90 (69 B): matches/0x00134e90.cpp
// sym: ??1FallAction_134e90@fn_fea6dcf4@@QAE@XZ
FallAction_134e90::~FallAction_134e90() {
    vptr = g_vftable_134e90;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_134e90 *)this)->FUN_002326a0();
}

} // namespace fn_fea6dcf4
