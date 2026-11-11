// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00116760..0x00116ad0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f72f4502 {
#define TREE_TU_END }
namespace fn_f72f4502 {} using namespace fn_f72f4502;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f72f4502 {
extern void* hulk_at_0040eb20[];
class Track_116790 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f72f4502
namespace hulkfight { namespace ai {
class MotionFleeTrack : public Track_116790 {
  public:
    MotionFleeTrack* vfunc_5(signed char flags);
};
} }
namespace fn_f72f4502 {
extern void* hulk_at_0040eb50[];
class Track_1167c0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f72f4502
namespace hulkfight { namespace ai {
class MotionStopTrack : public Track_1167c0 {
  public:
    MotionStopTrack* vfunc_5(signed char flags);
};
} }
namespace fn_f72f4502 {
extern void* hulk_at_0040eb80[];
class Track_1167f0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f72f4502
namespace hulkfight { namespace ai {
class MotionFacingTrack : public Track_1167f0 {
  public:
    MotionFacingTrack* vfunc_5(signed char flags);
};
} }
namespace fn_f72f4502 {
extern void* hulk_at_0040ebb0[];
class Track_116820 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f72f4502
namespace hulkfight { namespace ai {
class MotionBoostTrack : public Track_116820 {
  public:
    MotionBoostTrack* vfunc_5(signed char flags);
};
} }
namespace fn_f72f4502 {
typedef unsigned char u8_116850;
class Track {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vfunc_3();
    virtual void v4();
    virtual void v5(u8_116850);
    virtual void v6();
    virtual void v7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void v10();
};
class Param {};
} // namespace fn_f72f4502
namespace hulkfight { namespace ai {
class MotionLocatorTrack : public Track, public Param {
  public:
    virtual MotionLocatorTrack* vfunc_5(u8_116850);
    char pad[0x30 - sizeof(Track)];
};
} }
namespace fn_f72f4502 {
class Sub_116850 {
  public:
    void Fnf_0027af50();
};
class Main_116850 {
  public:
    void Fnf_00236d60();
};
void __cdecl Destroy_0008d330(hulkfight::ai::MotionLocatorTrack*);
extern void* hulk_at_0040ebe0;
extern void* hulk_at_0040ec10[];
class Track_116880 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f72f4502
namespace hulkfight { namespace ai {
class MotionTargetTrack : public Track_116880 {
  public:
    MotionTargetTrack* vfunc_5(signed char flags);
};
} }
namespace fn_f72f4502 {
extern void* hulk_at_0040ec40[];
class Track_1168b0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f72f4502
namespace hulkfight { namespace ai {
class MotionChaseTrack : public Track_1168b0 {
  public:
    MotionChaseTrack* vfunc_5(signed char flags);
};
} }
namespace fn_f72f4502 {
extern void* hulk_at_0040ec70[];
class Track_1168e0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f72f4502
namespace hulkfight { namespace ai {
class MotionClosestWaypointTrack : public Track_1168e0 {
  public:
    MotionClosestWaypointTrack* vfunc_5(signed char flags);
};
} }
namespace fn_f72f4502 {
class RefObj_116910 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_116910 {
  public:
    Action_116910();
    virtual void Update();
    char pad[0x18];
};
class MotionStopAction_116910 : public Action_116910 {
  public:
    int mTarget;
    RefObj_116910* mObj;
    MotionStopAction_116910(int target, RefObj_116910* obj);
    virtual void Execute();
};
extern void* hulk_at_0040eca0[];
class Ref_116960 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_116960 {
  public:
    void* vptr;
};
class MotionStopAction_116960 : public Action_116960 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_116960* m20;
    ~MotionStopAction_116960();
};
class RefObj_1169a0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1169a0 {
  public:
    Action_1169a0();
    virtual void Update();
    char pad[0x18];
};
class MotionFacingAction_1169a0 : public Action_1169a0 {
  public:
    int mTarget;
    RefObj_1169a0* mObj;
    MotionFacingAction_1169a0(int target, RefObj_1169a0* obj);
    virtual void Execute();
};
extern void* hulk_at_0040ecbc[];
class Ref_1169f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1169f0 {
  public:
    void* vptr;
};
class MotionFacingAction_1169f0 : public Action_1169f0 {
  public:
    char pad1c[0x18];
    void* m1c;
    Ref_1169f0* m20;
    ~MotionFacingAction_1169f0();
};
extern "C" char DAT_0040ecd8[];
class Ref_116a30 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_116a30 {
  public:
    volatile hulk_intptr v;
    Action_116a30();
};
class MotionTargetAction : public Action_116a30 {
  public:
    char pad[24];
    volatile int a;
    Ref_116a30* b;
    int c;
    MotionTargetAction(int x, Ref_116a30* r);
};
extern void* hulk_at_0040ecd8[];
class Ref_116a80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_116a80 {
  public:
    void* vptr;
};
class MotionTargetAction_116a80 : public Action_116a80 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_116a80* m20;
    Ref_116a80* m24;
    ~MotionTargetAction_116a80();
};

} // namespace fn_f72f4502

// 0x00116760 hulkfight::ai::HasGroundPointExtendedCondition::vfunc_5 (36 B): matches/0x00116760.cpp [wrapped: conflict: fight::Condition; fight::Param]
// sym: ?vfunc_5@HasGroundPointExtendedCondition@ai@hulkfight@fn_00116760@@QAEPAXD@Z
namespace fn_00116760 {
extern "C" char DAT_0040eb00[];

namespace fight {
class Condition {
  public:
    void munge_002345b0();
};
class Param {};
} // namespace fight

void __cdecl opDelete_0008d330(void* p);

namespace hulkfight {
namespace ai {
class HasGroundPointExtendedCondition : public fight::Condition, public fight::Param {
  public:
    void* vfunc_5(char flag);
};

void* HasGroundPointExtendedCondition::vfunc_5(char flag) {
    HasGroundPointExtendedCondition* self = this;
    *(void**)self = DAT_0040eb00;
    this->fight::Condition::munge_002345b0();
    if (flag & 1) {
        opDelete_0008d330(self);
    }
    return self;
}
} // namespace ai
} // namespace hulkfight
} // namespace fn_00116760


// 0x00116790 hulkfight::ai::MotionFleeTrack::vfunc_5 (36 B): matches/0x00116790.cpp
// sym: ?vfunc_5@MotionFleeTrack@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::MotionFleeTrack* hulkfight::ai::MotionFleeTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040eb20;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001167c0 hulkfight::ai::MotionStopTrack::vfunc_5 (36 B): matches/0x001167c0.cpp
// sym: ?vfunc_5@MotionStopTrack@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::MotionStopTrack* hulkfight::ai::MotionStopTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040eb50;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001167f0 hulkfight::ai::MotionFacingTrack::vfunc_5 (36 B): matches/0x001167f0.cpp
// sym: ?vfunc_5@MotionFacingTrack@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::MotionFacingTrack* hulkfight::ai::MotionFacingTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040eb80;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00116820 hulkfight::ai::MotionBoostTrack::vfunc_5 (36 B): matches/0x00116820.cpp
// sym: ?vfunc_5@MotionBoostTrack@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::MotionBoostTrack* hulkfight::ai::MotionBoostTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040ebb0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00116850 hulkfight::ai::MotionLocatorTrack::vfunc_5 (46 B): matches/0x00116850.cpp
// sym: ?vfunc_5@MotionLocatorTrack@ai@hulkfight@@UAEPAV123@E@Z
hulkfight::ai::MotionLocatorTrack* hulkfight::ai::MotionLocatorTrack::vfunc_5(u8_116850 flag) {
    ((void**)this)[0] = &hulk_at_0040ebe0;
    ((Sub_116850*)((char*)this + 0x30))->Fnf_0027af50();
    ((Main_116850*)this)->Fnf_00236d60();
    if (flag & 1)
        Destroy_0008d330(this);
    return this;
}


// 0x00116880 hulkfight::ai::MotionTargetTrack::vfunc_5 (36 B): matches/0x00116880.cpp
// sym: ?vfunc_5@MotionTargetTrack@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::MotionTargetTrack* hulkfight::ai::MotionTargetTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040ec10;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001168b0 hulkfight::ai::MotionChaseTrack::vfunc_5 (36 B): matches/0x001168b0.cpp
// sym: ?vfunc_5@MotionChaseTrack@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::MotionChaseTrack* hulkfight::ai::MotionChaseTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040ec40;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001168e0 hulkfight::ai::MotionClosestWaypointTrack::vfunc_5 (36 B): matches/0x001168e0.cpp
// sym: ?vfunc_5@MotionClosestWaypointTrack@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::MotionClosestWaypointTrack* hulkfight::ai::MotionClosestWaypointTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040ec70;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

namespace fn_f72f4502 {

// 0x00116910 FUN_00116910 (72 B): matches/0x00116910.cpp
// sym: ??0MotionStopAction_116910@fn_f72f4502@@QAE@HPAVRefObj_116910@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
MotionStopAction_116910::MotionStopAction_116910(int target, RefObj_116910* obj) {
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


// 0x00116960 FUN_00116960 (50 B): matches/0x00116960.cpp
// sym: ??1MotionStopAction_116960@fn_f72f4502@@QAE@XZ
MotionStopAction_116960::~MotionStopAction_116960() {
    vptr = hulk_at_0040eca0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_116960 *)this)->FUN_002326a0();
}


// 0x001169a0 FUN_001169a0 (72 B): matches/0x001169a0.cpp
// sym: ??0MotionFacingAction_1169a0@fn_f72f4502@@QAE@HPAVRefObj_1169a0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
MotionFacingAction_1169a0::MotionFacingAction_1169a0(int target, RefObj_1169a0* obj) {
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


// 0x001169f0 FUN_001169f0 (50 B): matches/0x001169f0.cpp
// sym: ??1MotionFacingAction_1169f0@fn_f72f4502@@QAE@XZ
MotionFacingAction_1169f0::~MotionFacingAction_1169f0() {
    vptr = hulk_at_0040ecbc;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1169f0 *)this)->FUN_002326a0();
}


// 0x00116a30 FUN_00116a30 (79 B): matches/0x00116a30.cpp
// sym: ??0MotionTargetAction@fn_f72f4502@@QAE@HPAVRef_116a30@1@@Z
MotionTargetAction::MotionTargetAction(int x, Ref_116a30* r) : Action_116a30() {
    v = ((hulk_intptr)DAT_0040ecd8);
    a = 0;
    b = 0;
    c = 0;
    a = x;
    if (r)
        r->AddRef();
    if (b)
        b->Release();
    b = r;
}


// 0x00116a80 FUN_00116a80 (69 B): matches/0x00116a80.cpp
// sym: ??1MotionTargetAction_116a80@fn_f72f4502@@QAE@XZ
MotionTargetAction_116a80::~MotionTargetAction_116a80() {
    vptr = hulk_at_0040ecd8;
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
    ((fight::Action *)(Action_116a80 *)this)->FUN_002326a0();
}

} // namespace fn_f72f4502
