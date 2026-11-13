// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014ffc0..0x001508d0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fb14e9c5 {
#define TREE_TU_END }
namespace fn_fb14e9c5 {} using namespace fn_fb14e9c5;
namespace fn_fb14e9c5 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fb14e9c5 {
class Record_14ffc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* f3();
};
class Helper_14ffc0 {
  public:
    void Fng_00059510();
};
extern void* hulk_at_00413f70[];
class Condition_1501e0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class InterruptAccumulatorCondition_1501e0 : public Condition_1501e0 {
  public:
    InterruptAccumulatorCondition_1501e0* vfunc_5(signed char flags);
};
extern void* hulk_at_00413f90[];
class Condition_150210 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionSourceForceMagnitudeCondition_150210 : public Condition_150210 {
  public:
    CollisionSourceForceMagnitudeCondition_150210* vfunc_5(signed char flags);
};
extern void* hulk_at_00413fb0[];
class Condition_150240 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionThrowCondition_150240 : public Condition_150240 {
  public:
    CollisionThrowCondition_150240* vfunc_5(signed char flags);
};
extern void* hulk_at_00413fd0[];
class Condition_150270 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionSourceSizeCondition_150270 : public Condition_150270 {
  public:
    CollisionSourceSizeCondition_150270* vfunc_5(signed char flags);
};
extern void* hulk_at_00413ff0[];
class Condition_1502a0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionSourceTypeCondition_1502a0 : public Condition_1502a0 {
  public:
    CollisionSourceTypeCondition_1502a0* vfunc_5(signed char flags);
};
extern void* hulk_at_00414010[];
class Condition_1502d0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionTargetPriorityCondition_1502d0 : public Condition_1502d0 {
  public:
    CollisionTargetPriorityCondition_1502d0* vfunc_5(signed char flags);
};
extern void* hulk_at_00414030[];
class Condition_150300 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionDevastatorCondition_150300 : public Condition_150300 {
  public:
    CollisionDevastatorCondition_150300* vfunc_5(signed char flags);
};
extern void* hulk_at_00414050[];
class Condition_150330 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class HitPushbackCondition_150330 : public Condition_150330 {
  public:
    HitPushbackCondition_150330* vfunc_5(signed char flags);
};
extern void* hulk_at_00414070[];
class Condition_150360 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionTargetIsTargetCondition_150360 : public Condition_150360 {
  public:
    CollisionTargetIsTargetCondition_150360* vfunc_5(signed char flags);
};
extern void* hulk_at_00414090[];
class Condition_150390 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionTargetSizeCondition_150390 : public Condition_150390 {
  public:
    CollisionTargetSizeCondition_150390* vfunc_5(signed char flags);
};
extern void* hulk_at_004140b0[];
class Condition_1503c0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionSourceIsMissileCondition_1503c0 : public Condition_1503c0 {
  public:
    CollisionSourceIsMissileCondition_1503c0* vfunc_5(signed char flags);
};
extern void* hulk_at_004140d0[];
class Condition_1503f0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class HitPushbackVelocityCondition_1503f0 : public Condition_1503f0 {
  public:
    HitPushbackVelocityCondition_1503f0* vfunc_5(signed char flags);
};
extern char hulk_at_004140f0;
struct Obj_150420 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_150420*);
class CollisionThrownObjectCondition_150420 {
  public:
    void* vftable;
    char pad[0x0c];
    CollisionThrownObjectCondition_150420* vfunc_5(unsigned char);
};
extern void* hulk_at_00414110[];
class Condition_150450 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionExplosionCondition_150450 : public Condition_150450 {
  public:
    CollisionExplosionCondition_150450* vfunc_5(signed char flags);
};
extern char hulk_at_00414130;
struct Obj_150480 {
    int x;
    void f1_00234150();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_150480*);
class CollisionSourceNodeCondition_150480 {
  public:
    void* vftable;
    char pad[0x0c];
    CollisionSourceNodeCondition_150480* vfunc_5(unsigned char);
};
extern void* hulk_at_00414150[];
class Condition_1504b0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionChargeCondition_1504b0 : public Condition_1504b0 {
  public:
    CollisionChargeCondition_1504b0* vfunc_5(signed char flags);
};
extern char hulk_at_00414170;
struct Obj_1504e0 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_1504e0*);
class CollisionTargetNameCondition_1504e0 {
  public:
    void* vftable;
    char pad[0x0c];
    CollisionTargetNameCondition_1504e0* vfunc_5(unsigned char);
};
extern void* hulk_at_00414190[];
class Condition_150510 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionDamageHealthCompareCondition_150510 : public Condition_150510 {
  public:
    CollisionDamageHealthCompareCondition_150510* vfunc_5(signed char flags);
};
extern void* hulk_at_004141b0[];
class Condition_150540 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionTargetTypeCondition_150540 : public Condition_150540 {
  public:
    CollisionTargetTypeCondition_150540* vfunc_5(signed char flags);
};
extern void* hulk_at_004141d0[];
class Condition_150570 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionInterruptPriorityCondition_150570 : public Condition_150570 {
  public:
    CollisionInterruptPriorityCondition_150570* vfunc_5(signed char flags);
};
extern char hulk_at_004141f0;
struct Obj_1505a0 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_1505a0*);
class CollisionSourceNameCondition_1505a0 {
  public:
    void* vftable;
    char pad[0x0c];
    CollisionSourceNameCondition_1505a0* vfunc_5(unsigned char);
};
extern void* hulk_at_00414210[];
class Track_1505d0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class InterruptAccumulatorSetTrack_1505d0 : public Track_1505d0 {
  public:
    InterruptAccumulatorSetTrack_1505d0* vfunc_5(signed char flags);
};
extern void* hulk_at_00414240[];
class Track_150600 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class HitThrowTrack_150600 : public Track_150600 {
  public:
    HitThrowTrack_150600* vfunc_5(signed char flags);
};
extern void* hulk_at_00414270[];
class Mem_150630 {
  public:
    ~Mem_150630();
};
class Track_150630 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class HitReactionFloatTrack_150630 : public Track_150630 {
  public:
    char pad[20];
    Mem_150630 m;
    HitReactionFloatTrack_150630* f2(unsigned char flags);
};
extern void* hulk_at_004142a0[];
class Track_150660 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class HitPauseTrack_150660 : public Track_150660 {
  public:
    HitPauseTrack_150660* vfunc_5(signed char flags);
};
class Sub_150690 {
  public:
    Sub_150690();
};
class HitReactionTrack {
  public:
    virtual hulk_intptr v0_0014ddf0(int);
    virtual bool v1_00234270(void*);
    virtual bool v2_002342b0(int);
    virtual bool v3_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool v4_00234350(int, int);
    virtual void* v5_00150690(int);
    virtual void v6_0014de60();
    virtual void v7_0014de70();
    virtual void* v8_00236ba0(void*, void*);
    virtual int v9_0014f110(void*, void*, void*);
    virtual hulk_intptr v10_00156f80(hulk_intptr, hulk_intptr, hulk_intptr);
    char pad[0x14];
    Sub_150690 sub;
    void BaseCall_00236d60();
    HitReactionTrack(int);
};
extern void __cdecl thunk_FUN_00267090(HitReactionTrack*);
extern void* hulk_at_00414300[];
class Track_1506c0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class HitWaitTrack_1506c0 : public Track_1506c0 {
  public:
    HitWaitTrack_1506c0* vfunc_5(signed char flags);
};
extern void* hulk_at_00414330[];
class Track_1506f0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class InterruptPriorityTrack_1506f0 : public Track_1506f0 {
  public:
    InterruptPriorityTrack_1506f0* vfunc_5(signed char flags);
};
extern void* hulk_at_00414360[];
class Track_150720 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class HitOrientToPushbackTrack_150720 : public Track_150720 {
  public:
    HitOrientToPushbackTrack_150720* vfunc_5(signed char flags);
};
extern void* hulk_at_00414390[];
class Track_150750 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class HitFloatTrack_150750 : public Track_150750 {
  public:
    HitFloatTrack_150750* vfunc_5(signed char flags);
};
extern void* hulk_at_004143c0[];
class Track_150780 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class ClearFightParamsHitRecordTrack_150780 : public Track_150780 {
  public:
    ClearFightParamsHitRecordTrack_150780* vfunc_5(signed char flags);
};
extern void* hulk_at_004143f0[];
class Track_1507b0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class HitPushbackAddTrack_1507b0 : public Track_1507b0 {
  public:
    HitPushbackAddTrack_1507b0* vfunc_5(signed char flags);
};
extern void* hulk_at_00414420[];
class Track_1507e0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class HealthTrack_1507e0 : public Track_1507e0 {
  public:
    HealthTrack_1507e0* vfunc_5(signed char flags);
};
extern void* hulk_at_00414450[];
class Track_150810 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class HitDamageTrack_150810 : public Track_150810 {
  public:
    HitDamageTrack_150810* vfunc_5(signed char flags);
};
extern void* hulk_at_00414480[];
class Track_150840 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class GroundSlideTrack_150840 : public Track_150840 {
  public:
    GroundSlideTrack_150840* vfunc_5(signed char flags);
};
extern void* hulk_at_004144b0[];
class Track_150870 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class HitPushbackTrack_150870 : public Track_150870 {
  public:
    HitPushbackTrack_150870* vfunc_5(signed char flags);
};
extern void* hulk_at_004144e0[];
class Track_1508a0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class NoHitPushbackTrack_1508a0 : public Track_1508a0 {
  public:
    NoHitPushbackTrack_1508a0* vfunc_5(signed char flags);
};

} // namespace fn_fb14e9c5

// 0x0014ffc0 hulkfight::motion::ClearFightParamsHitRecordAction::vfunc_3 (30 B): matches/0x0014ffc0.cpp
// sym: ?vfunc_3@ClearFightParamsHitRecordAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::ClearFightParamsHitRecordAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if ((*(Record_14ffc0 * *)&this->f_20)) {
        void* p = (*(Record_14ffc0 * *)&this->f_20)->f3();
        if (p) {
            ((Helper_14ffc0*)p)->Fng_00059510();
        }
    }
    return false;
}

namespace fn_fb14e9c5 {

// 0x00150000 FUN_00150000 (11 B): matches/0x00150000.cpp
// sym: ?Set@fn_fb14e9c5@@YAXPAXH@Z
void Set(void* p, int x) {
    *(int*)p = x;
}


// 0x001500a0 FUN_001500a0 (11 B): matches/0x001500a0.cpp
// sym: ?FUN_001500a0@fn_fb14e9c5@@YAHPAXH@Z
int __cdecl FUN_001500a0(void* p, int value) {
    *(int*)p = value;
    return value;
}

} // namespace fn_fb14e9c5

// 0x00150100 FUN_00150100 (11 B): matches/0x00150100.cpp [wrapped: same definition as 0x00150000 in this TU]
// sym: ?Set@fn_00150100@@YAXPAXH@Z
namespace fn_00150100 {
void Set(void* p, int v) {
    *(int*)p = v;
}
} // namespace fn_00150100

namespace fn_fb14e9c5 {

// 0x001501e0 hulkfight::motion::InterruptAccumulatorCondition::vfunc_5 (36 B): matches/0x001501e0.cpp
// sym: ?vfunc_5@InterruptAccumulatorCondition_1501e0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
InterruptAccumulatorCondition_1501e0* InterruptAccumulatorCondition_1501e0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00413f70;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150210 hulkfight::motion::CollisionSourceForceMagnitudeCondition::vfunc_5 (36 B): matches/0x00150210.cpp
// sym: ?vfunc_5@CollisionSourceForceMagnitudeCondition_150210@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionSourceForceMagnitudeCondition_150210* CollisionSourceForceMagnitudeCondition_150210::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00413f90;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150240 hulkfight::motion::CollisionThrowCondition::vfunc_5 (36 B): matches/0x00150240.cpp
// sym: ?vfunc_5@CollisionThrowCondition_150240@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionThrowCondition_150240* CollisionThrowCondition_150240::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00413fb0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150270 hulkfight::motion::CollisionSourceSizeCondition::vfunc_5 (36 B): matches/0x00150270.cpp
// sym: ?vfunc_5@CollisionSourceSizeCondition_150270@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionSourceSizeCondition_150270* CollisionSourceSizeCondition_150270::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00413fd0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001502a0 hulkfight::motion::CollisionSourceTypeCondition::vfunc_5 (36 B): matches/0x001502a0.cpp
// sym: ?vfunc_5@CollisionSourceTypeCondition_1502a0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionSourceTypeCondition_1502a0* CollisionSourceTypeCondition_1502a0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00413ff0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001502d0 hulkfight::motion::CollisionTargetPriorityCondition::vfunc_5 (36 B): matches/0x001502d0.cpp
// sym: ?vfunc_5@CollisionTargetPriorityCondition_1502d0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionTargetPriorityCondition_1502d0* CollisionTargetPriorityCondition_1502d0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414010;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150300 hulkfight::motion::CollisionDevastatorCondition::vfunc_5 (36 B): matches/0x00150300.cpp
// sym: ?vfunc_5@CollisionDevastatorCondition_150300@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionDevastatorCondition_150300* CollisionDevastatorCondition_150300::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414030;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150330 hulkfight::motion::HitPushbackCondition::vfunc_5 (36 B): matches/0x00150330.cpp
// sym: ?vfunc_5@HitPushbackCondition_150330@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitPushbackCondition_150330* HitPushbackCondition_150330::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414050;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150360 hulkfight::motion::CollisionTargetIsTargetCondition::vfunc_5 (36 B): matches/0x00150360.cpp
// sym: ?vfunc_5@CollisionTargetIsTargetCondition_150360@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionTargetIsTargetCondition_150360* CollisionTargetIsTargetCondition_150360::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414070;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150390 hulkfight::motion::CollisionTargetSizeCondition::vfunc_5 (36 B): matches/0x00150390.cpp
// sym: ?vfunc_5@CollisionTargetSizeCondition_150390@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionTargetSizeCondition_150390* CollisionTargetSizeCondition_150390::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414090;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001503c0 hulkfight::motion::CollisionSourceIsMissileCondition::vfunc_5 (36 B): matches/0x001503c0.cpp
// sym: ?vfunc_5@CollisionSourceIsMissileCondition_1503c0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionSourceIsMissileCondition_1503c0* CollisionSourceIsMissileCondition_1503c0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004140b0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001503f0 hulkfight::motion::HitPushbackVelocityCondition::vfunc_5 (36 B): matches/0x001503f0.cpp
// sym: ?vfunc_5@HitPushbackVelocityCondition_1503f0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitPushbackVelocityCondition_1503f0* HitPushbackVelocityCondition_1503f0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004140d0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150420 hulkfight::motion::CollisionThrownObjectCondition::vfunc_5 (46 B): matches/0x00150420.cpp
// sym: ?vfunc_5@CollisionThrownObjectCondition_150420@fn_fb14e9c5@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
CollisionThrownObjectCondition_150420* CollisionThrownObjectCondition_150420::vfunc_5(unsigned char param) {
    CollisionThrownObjectCondition_150420* p = this;
    *(char**)p = &hulk_at_004140f0;
    ((Obj_150420*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_150420*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_150420*)p);
    return p;
}


// 0x00150450 hulkfight::motion::CollisionExplosionCondition::vfunc_5 (36 B): matches/0x00150450.cpp
// sym: ?vfunc_5@CollisionExplosionCondition_150450@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionExplosionCondition_150450* CollisionExplosionCondition_150450::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414110;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150480 hulkfight::motion::CollisionSourceNodeCondition::vfunc_5 (46 B): matches/0x00150480.cpp
// sym: ?vfunc_5@CollisionSourceNodeCondition_150480@fn_fb14e9c5@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
CollisionSourceNodeCondition_150480* CollisionSourceNodeCondition_150480::vfunc_5(unsigned char param) {
    CollisionSourceNodeCondition_150480* p = this;
    *(char**)p = &hulk_at_00414130;
    ((Obj_150480*)((char*)p + 0x10))->f1_00234150();
    ((Obj_150480*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_150480*)p);
    return p;
}


// 0x001504b0 hulkfight::motion::CollisionChargeCondition::vfunc_5 (36 B): matches/0x001504b0.cpp
// sym: ?vfunc_5@CollisionChargeCondition_1504b0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionChargeCondition_1504b0* CollisionChargeCondition_1504b0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414150;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001504e0 hulkfight::motion::CollisionTargetNameCondition::vfunc_5 (46 B): matches/0x001504e0.cpp
// sym: ?vfunc_5@CollisionTargetNameCondition_1504e0@fn_fb14e9c5@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
CollisionTargetNameCondition_1504e0* CollisionTargetNameCondition_1504e0::vfunc_5(unsigned char param) {
    CollisionTargetNameCondition_1504e0* p = this;
    *(char**)p = &hulk_at_00414170;
    ((Obj_1504e0*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_1504e0*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_1504e0*)p);
    return p;
}


// 0x00150510 hulkfight::motion::CollisionDamageHealthCompareCondition::vfunc_5 (36 B): matches/0x00150510.cpp
// sym: ?vfunc_5@CollisionDamageHealthCompareCondition_150510@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionDamageHealthCompareCondition_150510* CollisionDamageHealthCompareCondition_150510::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414190;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150540 hulkfight::motion::CollisionTargetTypeCondition::vfunc_5 (36 B): matches/0x00150540.cpp
// sym: ?vfunc_5@CollisionTargetTypeCondition_150540@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionTargetTypeCondition_150540* CollisionTargetTypeCondition_150540::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004141b0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150570 hulkfight::motion::CollisionInterruptPriorityCondition::vfunc_5 (36 B): matches/0x00150570.cpp
// sym: ?vfunc_5@CollisionInterruptPriorityCondition_150570@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionInterruptPriorityCondition_150570* CollisionInterruptPriorityCondition_150570::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004141d0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001505a0 hulkfight::motion::CollisionSourceNameCondition::vfunc_5 (46 B): matches/0x001505a0.cpp
// sym: ?vfunc_5@CollisionSourceNameCondition_1505a0@fn_fb14e9c5@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
CollisionSourceNameCondition_1505a0* CollisionSourceNameCondition_1505a0::vfunc_5(unsigned char param) {
    CollisionSourceNameCondition_1505a0* p = this;
    *(char**)p = &hulk_at_004141f0;
    ((Obj_1505a0*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_1505a0*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_1505a0*)p);
    return p;
}


// 0x001505d0 hulkfight::motion::InterruptAccumulatorSetTrack::vfunc_5 (36 B): matches/0x001505d0.cpp
// sym: ?vfunc_5@InterruptAccumulatorSetTrack_1505d0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
InterruptAccumulatorSetTrack_1505d0* InterruptAccumulatorSetTrack_1505d0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414210;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150600 hulkfight::motion::HitThrowTrack::vfunc_5 (36 B): matches/0x00150600.cpp
// sym: ?vfunc_5@HitThrowTrack_150600@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitThrowTrack_150600* HitThrowTrack_150600::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414240;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150630 hulkfight::motion::HitReactionFloatTrack::vfunc_5 (46 B): matches/0x00150630.cpp
// sym: ?f2@HitReactionFloatTrack_150630@fn_fb14e9c5@@QAEPAV12@E@Z
HitReactionFloatTrack_150630* HitReactionFloatTrack_150630::f2(unsigned char flags) {
    vptr = hulk_at_00414270;

    m.~Mem_150630();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00150660 hulkfight::motion::HitPauseTrack::vfunc_5 (36 B): matches/0x00150660.cpp
// sym: ?vfunc_5@HitPauseTrack_150660@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitPauseTrack_150660* HitPauseTrack_150660::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004142a0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150690 hulkfight::motion::HitReactionTrack::vfunc_5 (46 B): matches/0x00150690.cpp
// sym: ??0HitReactionTrack@fn_fb14e9c5@@QAE@H@Z
HitReactionTrack::HitReactionTrack(int flag) {
    BaseCall_00236d60();
    if (flag & 1)
        thunk_FUN_00267090(this);
}


// 0x001506c0 hulkfight::motion::HitWaitTrack::vfunc_5 (36 B): matches/0x001506c0.cpp
// sym: ?vfunc_5@HitWaitTrack_1506c0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitWaitTrack_1506c0* HitWaitTrack_1506c0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414300;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001506f0 hulkfight::motion::InterruptPriorityTrack::vfunc_5 (36 B): matches/0x001506f0.cpp
// sym: ?vfunc_5@InterruptPriorityTrack_1506f0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
InterruptPriorityTrack_1506f0* InterruptPriorityTrack_1506f0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414330;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150720 hulkfight::motion::HitOrientToPushbackTrack::vfunc_5 (36 B): matches/0x00150720.cpp
// sym: ?vfunc_5@HitOrientToPushbackTrack_150720@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitOrientToPushbackTrack_150720* HitOrientToPushbackTrack_150720::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414360;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150750 hulkfight::motion::HitFloatTrack::vfunc_5 (36 B): matches/0x00150750.cpp
// sym: ?vfunc_5@HitFloatTrack_150750@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitFloatTrack_150750* HitFloatTrack_150750::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414390;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150780 hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_5 (36 B): matches/0x00150780.cpp
// sym: ?vfunc_5@ClearFightParamsHitRecordTrack_150780@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ClearFightParamsHitRecordTrack_150780* ClearFightParamsHitRecordTrack_150780::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004143c0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001507b0 hulkfight::motion::HitPushbackAddTrack::vfunc_5 (36 B): matches/0x001507b0.cpp
// sym: ?vfunc_5@HitPushbackAddTrack_1507b0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitPushbackAddTrack_1507b0* HitPushbackAddTrack_1507b0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004143f0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001507e0 hulkfight::motion::HealthTrack::vfunc_5 (36 B): matches/0x001507e0.cpp
// sym: ?vfunc_5@HealthTrack_1507e0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HealthTrack_1507e0* HealthTrack_1507e0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414420;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150810 hulkfight::motion::HitDamageTrack::vfunc_5 (36 B): matches/0x00150810.cpp
// sym: ?vfunc_5@HitDamageTrack_150810@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitDamageTrack_150810* HitDamageTrack_150810::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414450;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150840 hulkfight::motion::GroundSlideTrack::vfunc_5 (36 B): matches/0x00150840.cpp
// sym: ?vfunc_5@GroundSlideTrack_150840@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
GroundSlideTrack_150840* GroundSlideTrack_150840::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00414480;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00150870 hulkfight::motion::HitPushbackTrack::vfunc_5 (36 B): matches/0x00150870.cpp
// sym: ?vfunc_5@HitPushbackTrack_150870@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitPushbackTrack_150870* HitPushbackTrack_150870::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004144b0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001508a0 hulkfight::motion::NoHitPushbackTrack::vfunc_5 (36 B): matches/0x001508a0.cpp
// sym: ?vfunc_5@NoHitPushbackTrack_1508a0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
NoHitPushbackTrack_1508a0* NoHitPushbackTrack_1508a0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004144e0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_fb14e9c5
