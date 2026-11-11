// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00172c00..0x001734b0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ff4cbdc8 {
#define TREE_TU_END }
namespace fn_ff4cbdc8 {} using namespace fn_ff4cbdc8;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_ff4cbdc8 {
extern "C" char DAT_00417898[];
class Part_172da0 {
  public:
    void Init_0027af50();
};
extern void DestroyTrack_0008d330(void*);
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class JointTrackerTrack {
  public:
    virtual void* vfunc_0();
    virtual void* vfunc_1();
    virtual void* vfunc_2();
    virtual void* vfunc_3();
    virtual void* vfunc_4();
    virtual JointTrackerTrack* vfunc_5(int);
    virtual void* vfunc_6();
    virtual void* vfunc_7();
    virtual void* vfunc_8();
    virtual void* vfunc_9();
    virtual void* vfunc_10();
    char pad[0x14];
    Part_172da0 part;
    void Init_00236d60();
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_004178c8[];
class Track_172dd0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class ChargeTrack : public Track_172dd0 {
  public:
    ChargeTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
struct Sub_172e00 {
    void* v;
    void Fin_0027af50();
};
class Track_172e00 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class RestPoseTrack_172e00 : public Track_172e00 {
  public:
    char pad[0x18 - 4];
    Sub_172e00 sub;
    RestPoseTrack_172e00* f5(unsigned char flags);
};
extern void* hulk_at_00417928[];
class Track_172e30 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class SnapToGroundTrack : public Track_172e30 {
  public:
    SnapToGroundTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern "C" char DAT_00417958[];
class JointRelativeTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x18 - 4];
    JointRelativeTrack(int);
    void Init2_00236d60();
};
struct Sub_172e60 {
    void Init_0027af50();
};
void __cdecl destroy_0008d330(JointRelativeTrack*);
extern "C" char DAT_00417988[];
class Sub_172e90 {
  public:
    void run_0027af50();
    char pad[8];
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class SyncToLocatorTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual SyncToLocatorTrack* vfunc_5(unsigned char flags);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x1c];
    Sub_172e90 sub;
    void* mThing;
    void step_00236d60();
};
} }
namespace fn_ff4cbdc8 {
void cleanup_0008d340(void* p);
void destroyObj_0008d330(hulkfight::motion::SyncToLocatorTrack* p);
extern void* hulk_at_004179b8[];
class Track_172ed0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class SuckTrack : public Track_172ed0 {
  public:
    SuckTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_004179e8[];
class Track_172f00 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class LocomotionStateTrack : public Track_172f00 {
  public:
    LocomotionStateTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417a18[];
extern void* g_vftable2[];
class Ref_172f30 {
  public:
    virtual void F0();
    virtual void Release();
};
class Track_172f30 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class Sub_172f30 {
  public:
    void Fin_0027af50();
};
class MoveJointTrack_172f30 : public Track_172f30 {
  public:
    char pad[0x14];
    Sub_172f30 s18;
    char pad2[7];
    Sub_172f30 s20;
    MoveJointTrack_172f30* f2(unsigned char flags);
};
typedef unsigned char u8_172f70;
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class DriftToPositionTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual DriftToPositionTrack* vfunc_5(u8_172f70);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x24];
    void Finish_00236d60();
};
} }
namespace fn_ff4cbdc8 {
extern void __cdecl ReleaseThing_0008d340(void*);
extern void* hulk_at_00417a48;
extern void* hulk_at_00417a78[];
class Track_172fb0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class DriftToHulkTrack : public Track_172fb0 {
  public:
    DriftToHulkTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417aa8[];
class Track_172fe0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class MotionStateTrack : public Track_172fe0 {
  public:
    MotionStateTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417ad8[];
class Track_173010 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class MomentumXZAddTrack : public Track_173010 {
  public:
    MomentumXZAddTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417b08[];
class Track_173040 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class TargetBreakTrack : public Track_173040 {
  public:
    TargetBreakTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern "C" char DAT_00417b38[];
class Sub_173070 {
  public:
    void Init_0027af50();
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class PushOutTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual PushOutTrack* vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x14];
    void Middle_00236d60();
};
} }
namespace fn_ff4cbdc8 {
extern void __cdecl thunk_FUN_00267090(hulkfight::motion::PushOutTrack*);
extern void* hulk_at_00417b68[];
class Track_1730a0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class TeleportTrack : public Track_1730a0 {
  public:
    TeleportTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417b98[];
struct Sub_1730d0 {
    char c;
    void Fin_0027af50();
};
class Track_1730d0 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class JointPivotTrackerTrack_1730d0 : public Track_1730d0 {
  public:
    char pad[0x18 - 4];
    Sub_1730d0 sub;
    JointPivotTrackerTrack_1730d0* f5(unsigned char flags);
};
extern void* hulk_at_00417bc8[];
class Track_173100 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class SurfTrack : public Track_173100 {
  public:
    SurfTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417bf8[];
class Track_173130 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class TargetIconDistanceTrack : public Track_173130 {
  public:
    TargetIconDistanceTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417c28[];
class Track_173160 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class CriticalMassDrainTrack : public Track_173160 {
  public:
    CriticalMassDrainTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417c58[];
class Track_173190 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class SuckInPropsTrack : public Track_173190 {
  public:
    SuckInPropsTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417c88[];
class Track_1731c0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class TeleportRelativeTrack : public Track_1731c0 {
  public:
    TeleportRelativeTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417cb8[];
class Track_1731f0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class IntentionClearTrack : public Track_1731f0 {
  public:
    IntentionClearTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
class TeleportToLocatorTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~TeleportToLocatorTrack();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    int pad04[3];
    int m10;
    void trackCall_00236d60();
};
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
extern void* hulk_at_00417d18[];
class Track_173260 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class ChargeClearTrack : public Track_173260 {
  public:
    ChargeClearTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417d48[];
class Track_173290 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
class VisibilityTrack : public Track_173290 {
  public:
    VisibilityTrack* vfunc_5(signed char flags);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417d78[];
class Mem_1732c0 {
  public:
    ~Mem_1732c0();
};
class Track_1732c0 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class FootPivotTrack_1732c0 : public Track_1732c0 {
  public:
    char pad[20];
    Mem_1732c0 m;
    FootPivotTrack_1732c0* f2(unsigned char flags);
};
class RefObj_1732f0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1732f0 {
  public:
    Action_1732f0();
    virtual void Update();
    char pad[0x18];
};
class LocomotionStateAction_1732f0 : public Action_1732f0 {
  public:
    int mTarget;
    RefObj_1732f0* mObj;
    LocomotionStateAction_1732f0(int target, RefObj_1732f0* obj);
    virtual void Execute();
};
extern void* hulk_at_00417db8[];
class Ref_173340 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_173340 {
  public:
    void* vptr;
};
class LocomotionStateAction_173340 : public Action_173340 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_173340* m20;
    ~LocomotionStateAction_173340();
};
class RefObj_173380 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_173380 {
  public:
    Action_173380();
    virtual void Update();
    char pad[0x18];
};
class MotionStateAction_173380 : public Action_173380 {
  public:
    int mTarget;
    RefObj_173380* mObj;
    MotionStateAction_173380(int target, RefObj_173380* obj);
    virtual void Execute();
};
class Ref_1733d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1733d0 {
  public:
    void* vptr;
};
class MotionStateAction_1733d0 : public Action_1733d0 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_1733d0* m20;
    ~MotionStateAction_1733d0() throw();
};
} // namespace fn_ff4cbdc8
namespace hulkfight { namespace motion {
struct Ref {
    virtual void FUN_00000000();
    virtual void FUN_00000001();
};
} }
namespace hulkfight { namespace motion {
struct Base {
    Base();
    virtual void FUN_00000002();
};
} }
namespace hulkfight { namespace motion {
struct Fields {
    int value;
    Ref* ref;
    int other;
    Fields() : value(0), ref(0), other(0) {}
};
} }
namespace hulkfight { namespace motion {
struct JointTrackerAction : Base {
    char pad[0x18];
    Fields fields;
    char pad2[0x4c];
    int last;
    JointTrackerAction(int v, Ref* r);
};
} }
namespace fn_ff4cbdc8 {
extern void* hulk_at_00417df0[];
class Ref_173460 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_173460 {
  public:
    void* vptr;
};
void Free(void*) throw();
struct Sub_173460 {
    char c;
};
void __fastcall SubFini(Sub_173460*) throw();
void __fastcall SubFini2(Sub_173460*) throw();
class JointTrackerAction_173460 : public Action_173460 {
  public:
    char p1c[24];
    void* m1c;
    Ref_173460* m20;
    Ref_173460* m24;
    char p74[76];
    Ref_173460* m74;
    ~JointTrackerAction_173460() throw();
};


// 0x00172c00 FUN_00172c00 (11 B): matches/0x00172c00.cpp
// sym: ?FUN_00172c00@fn_ff4cbdc8@@YAHPAHH@Z
int __cdecl FUN_00172c00(int* out, int value) {
    *out = value;
    return value;
}

} // namespace fn_ff4cbdc8

// 0x00172da0 hulkfight::motion::JointTrackerTrack::vfunc_5 (46 B): matches/0x00172da0.cpp
// sym: ?vfunc_5@JointTrackerTrack@motion@hulkfight@@UAEPAV123@H@Z
hulkfight::motion::JointTrackerTrack* hulkfight::motion::JointTrackerTrack::vfunc_5(int f) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00417898);
    part.Init_0027af50();
    Init_00236d60();
    if (f & 1)
        DestroyTrack_0008d330(this);
    return this;
}


// 0x00172dd0 hulkfight::motion::ChargeTrack::vfunc_5 (36 B): matches/0x00172dd0.cpp
// sym: ?vfunc_5@ChargeTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::ChargeTrack* hulkfight::motion::ChargeTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004178c8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

namespace fn_ff4cbdc8 {

// 0x00172e00 hulkfight::motion::RestPoseTrack::vfunc_5 (46 B): matches/0x00172e00.cpp
// sym: ?f5@RestPoseTrack_172e00@fn_ff4cbdc8@@QAEPAV12@E@Z
RestPoseTrack_172e00* RestPoseTrack_172e00::f5(unsigned char flags) {
    vptr = g_vA;
    sub.Fin_0027af50();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_ff4cbdc8

// 0x00172e30 hulkfight::motion::SnapToGroundTrack::vfunc_5 (36 B): matches/0x00172e30.cpp
// sym: ?vfunc_5@SnapToGroundTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::SnapToGroundTrack* hulkfight::motion::SnapToGroundTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417928;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

namespace fn_ff4cbdc8 {

// 0x00172e60 hulkfight::motion::JointRelativeTrack::vfunc_5 (46 B): matches/0x00172e60.cpp
// sym: ??0JointRelativeTrack@fn_ff4cbdc8@@QAE@H@Z
JointRelativeTrack::JointRelativeTrack(int flag) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00417958);
    ((Sub_172e60*)((char*)this + 0x18))->Init_0027af50();
    Init2_00236d60();
    if (flag & 1)
        destroy_0008d330(this);
}

} // namespace fn_ff4cbdc8

// 0x00172e90 hulkfight::motion::SyncToLocatorTrack::vfunc_5 (58 B): matches/0x00172e90.cpp
// sym: ?vfunc_5@SyncToLocatorTrack@motion@hulkfight@@UAEPAV123@E@Z
hulkfight::motion::SyncToLocatorTrack* hulkfight::motion::SyncToLocatorTrack::vfunc_5(unsigned char flags) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_00417988);
    cleanup_0008d340(mThing);
    sub.run_0027af50();
    step_00236d60();
    if (flags & 1)
        destroyObj_0008d330(this);
    return this;
}


// 0x00172ed0 hulkfight::motion::SuckTrack::vfunc_5 (36 B): matches/0x00172ed0.cpp
// sym: ?vfunc_5@SuckTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::SuckTrack* hulkfight::motion::SuckTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004179b8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00172f00 hulkfight::motion::LocomotionStateTrack::vfunc_5 (36 B): matches/0x00172f00.cpp
// sym: ?vfunc_5@LocomotionStateTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::LocomotionStateTrack* hulkfight::motion::LocomotionStateTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004179e8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

namespace fn_ff4cbdc8 {

// 0x00172f30 hulkfight::motion::MoveJointTrack::vfunc_5 (54 B): matches/0x00172f30.cpp
// sym: ?f2@MoveJointTrack_172f30@fn_ff4cbdc8@@QAEPAV12@E@Z
MoveJointTrack_172f30* MoveJointTrack_172f30::f2(unsigned char flags) {
    vptr = hulk_at_00417a18;
    s20.Fin_0027af50();
    s18.Fin_0027af50();
    Track_172f30::Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_ff4cbdc8

// 0x00172f70 hulkfight::motion::DriftToPositionTrack::vfunc_5 (50 B): matches/0x00172f70.cpp
// sym: ?vfunc_5@DriftToPositionTrack@motion@hulkfight@@UAEPAV123@E@Z
hulkfight::motion::DriftToPositionTrack* hulkfight::motion::DriftToPositionTrack::vfunc_5(u8_172f70 flag) {
    *(void**)this = &hulk_at_00417a48;
    ReleaseThing_0008d340(*(void**)((char*)this + 0x28));
    Finish_00236d60();
    if (flag & 1)
        ReleaseSelf(this);
    return this;
}


// 0x00172fb0 hulkfight::motion::DriftToHulkTrack::vfunc_5 (36 B): matches/0x00172fb0.cpp
// sym: ?vfunc_5@DriftToHulkTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::DriftToHulkTrack* hulkfight::motion::DriftToHulkTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417a78;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00172fe0 hulkfight::motion::MotionStateTrack::vfunc_5 (36 B): matches/0x00172fe0.cpp
// sym: ?vfunc_5@MotionStateTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::MotionStateTrack* hulkfight::motion::MotionStateTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417aa8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00173010 hulkfight::motion::MomentumXZAddTrack::vfunc_5 (36 B): matches/0x00173010.cpp
// sym: ?vfunc_5@MomentumXZAddTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::MomentumXZAddTrack* hulkfight::motion::MomentumXZAddTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417ad8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00173040 hulkfight::motion::TargetBreakTrack::vfunc_5 (36 B): matches/0x00173040.cpp
// sym: ?vfunc_5@TargetBreakTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::TargetBreakTrack* hulkfight::motion::TargetBreakTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417b08;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00173070 hulkfight::motion::PushOutTrack::vfunc_5 (46 B): matches/0x00173070.cpp
// sym: ?vfunc_5@PushOutTrack@motion@hulkfight@@UAEPAV123@H@Z
hulkfight::motion::PushOutTrack* hulkfight::motion::PushOutTrack::vfunc_5(int flag) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00417b38);
    Sub_173070* p = (Sub_173070*)((char*)this + 0x18);
    p->Init_0027af50();
    Middle_00236d60();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001730a0 hulkfight::motion::TeleportTrack::vfunc_5 (36 B): matches/0x001730a0.cpp
// sym: ?vfunc_5@TeleportTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::TeleportTrack* hulkfight::motion::TeleportTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417b68;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

namespace fn_ff4cbdc8 {

// 0x001730d0 hulkfight::motion::JointPivotTrackerTrack::vfunc_5 (46 B): matches/0x001730d0.cpp
// sym: ?f5@JointPivotTrackerTrack_1730d0@fn_ff4cbdc8@@QAEPAV12@E@Z
JointPivotTrackerTrack_1730d0* JointPivotTrackerTrack_1730d0::f5(unsigned char flags) {
    vptr = hulk_at_00417b98;
    sub.Fin_0027af50();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_ff4cbdc8

// 0x00173100 hulkfight::motion::SurfTrack::vfunc_5 (36 B): matches/0x00173100.cpp
// sym: ?vfunc_5@SurfTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::SurfTrack* hulkfight::motion::SurfTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417bc8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00173130 hulkfight::motion::TargetIconDistanceTrack::vfunc_5 (36 B): matches/0x00173130.cpp
// sym: ?vfunc_5@TargetIconDistanceTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::TargetIconDistanceTrack* hulkfight::motion::TargetIconDistanceTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417bf8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00173160 hulkfight::motion::CriticalMassDrainTrack::vfunc_5 (36 B): matches/0x00173160.cpp
// sym: ?vfunc_5@CriticalMassDrainTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::CriticalMassDrainTrack* hulkfight::motion::CriticalMassDrainTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417c28;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00173190 hulkfight::motion::SuckInPropsTrack::vfunc_5 (36 B): matches/0x00173190.cpp
// sym: ?vfunc_5@SuckInPropsTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::SuckInPropsTrack* hulkfight::motion::SuckInPropsTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417c58;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001731c0 hulkfight::motion::TeleportRelativeTrack::vfunc_5 (36 B): matches/0x001731c0.cpp
// sym: ?vfunc_5@TeleportRelativeTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::TeleportRelativeTrack* hulkfight::motion::TeleportRelativeTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417c88;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001731f0 hulkfight::motion::IntentionClearTrack::vfunc_5 (36 B): matches/0x001731f0.cpp
// sym: ?vfunc_5@IntentionClearTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::IntentionClearTrack* hulkfight::motion::IntentionClearTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417cb8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

namespace fn_ff4cbdc8 {

// 0x00173220 hulkfight::motion::TeleportToLocatorTrack::vfunc_5 (50 B): matches/0x00173220.cpp
// sym: ??_GTeleportToLocatorTrack@fn_ff4cbdc8@@UAEPAXI@Z
TeleportToLocatorTrack::~TeleportToLocatorTrack() {
    thunk_FUN_00267090(m10);
    trackCall_00236d60();
}

} // namespace fn_ff4cbdc8

// 0x00173260 hulkfight::motion::ChargeClearTrack::vfunc_5 (36 B): matches/0x00173260.cpp
// sym: ?vfunc_5@ChargeClearTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::ChargeClearTrack* hulkfight::motion::ChargeClearTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417d18;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00173290 hulkfight::motion::VisibilityTrack::vfunc_5 (36 B): matches/0x00173290.cpp
// sym: ?vfunc_5@VisibilityTrack@motion@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::VisibilityTrack* hulkfight::motion::VisibilityTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00417d48;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

namespace fn_ff4cbdc8 {

// 0x001732c0 hulkfight::motion::FootPivotTrack::vfunc_5 (46 B): matches/0x001732c0.cpp
// sym: ?f2@FootPivotTrack_1732c0@fn_ff4cbdc8@@QAEPAV12@E@Z
FootPivotTrack_1732c0* FootPivotTrack_1732c0::f2(unsigned char flags) {
    vptr = hulk_at_00417d78;

    m.~Mem_1732c0();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x001732f0 FUN_001732f0 (72 B): matches/0x001732f0.cpp
// sym: ??0LocomotionStateAction_1732f0@fn_ff4cbdc8@@QAE@HPAVRefObj_1732f0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
LocomotionStateAction_1732f0::LocomotionStateAction_1732f0(int target, RefObj_1732f0* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x00173340 FUN_00173340 (50 B): matches/0x00173340.cpp
// sym: ??1LocomotionStateAction_173340@fn_ff4cbdc8@@QAE@XZ
LocomotionStateAction_173340::~LocomotionStateAction_173340() {
    vptr = hulk_at_00417db8;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_173340 *)this)->FUN_002326a0();
}


// 0x00173380 FUN_00173380 (72 B): matches/0x00173380.cpp
// sym: ??0MotionStateAction_173380@fn_ff4cbdc8@@QAE@HPAVRefObj_173380@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
MotionStateAction_173380::MotionStateAction_173380(int target, RefObj_173380* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x001733d0 FUN_001733d0 (50 B): matches/0x001733d0.cpp
// sym: ??1MotionStateAction_1733d0@fn_ff4cbdc8@@QAE@XZ
MotionStateAction_1733d0::~MotionStateAction_1733d0() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1733d0 *)this)->FUN_002326a0();
}

} // namespace fn_ff4cbdc8

// 0x00173410 FUN_00173410 (74 B): matches/0x00173410.cpp
// sym: ??0JointTrackerAction@motion@hulkfight@@QAE@HPAURef@12@@Z
namespace hulkfight { namespace motion {
JointTrackerAction::JointTrackerAction(int v, Ref* r) : Base(), fields(), last(0) {
    fields.value = v;
    if (r)
        r->FUN_00000000();
    if (fields.ref)
        fields.ref->FUN_00000001();
    fields.ref = r;
}
} }

namespace fn_ff4cbdc8 {

// 0x00173460 FUN_00173460 (74 B): matches/0x00173460.cpp
// sym: ??1JointTrackerAction_173460@fn_ff4cbdc8@@QAE@XZ
JointTrackerAction_173460::~JointTrackerAction_173460() throw() {
    vptr = hulk_at_00417df0;
    _ReadWriteBarrier();
    if (m74) {
        m74->Release();
        m74 = 0;
    }
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
    ((fight::Action *)(Action_173460 *)this)->FUN_002326a0();
}

} // namespace fn_ff4cbdc8
