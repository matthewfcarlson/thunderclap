// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014ffc0..0x001508d0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fb14e9c5 {
#define TREE_TU_END }
namespace fn_fb14e9c5 {} using namespace fn_fb14e9c5;
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
    void g();
};
extern void* Condition_1501e0_vftable[];
class Condition_1501e0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class InterruptAccumulatorCondition_1501e0 : public Condition_1501e0 {
  public:
    InterruptAccumulatorCondition_1501e0* vfunc_5(signed char flags);
};
extern void* Condition_150210_vftable[];
class Condition_150210 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionSourceForceMagnitudeCondition_150210 : public Condition_150210 {
  public:
    CollisionSourceForceMagnitudeCondition_150210* vfunc_5(signed char flags);
};
extern void* Condition_150240_vftable[];
class Condition_150240 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionThrowCondition_150240 : public Condition_150240 {
  public:
    CollisionThrowCondition_150240* vfunc_5(signed char flags);
};
extern void* Condition_150270_vftable[];
class Condition_150270 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionSourceSizeCondition_150270 : public Condition_150270 {
  public:
    CollisionSourceSizeCondition_150270* vfunc_5(signed char flags);
};
extern void* Condition_1502a0_vftable[];
class Condition_1502a0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionSourceTypeCondition_1502a0 : public Condition_1502a0 {
  public:
    CollisionSourceTypeCondition_1502a0* vfunc_5(signed char flags);
};
extern void* Condition_1502d0_vftable[];
class Condition_1502d0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionTargetPriorityCondition_1502d0 : public Condition_1502d0 {
  public:
    CollisionTargetPriorityCondition_1502d0* vfunc_5(signed char flags);
};
extern void* Condition_150300_vftable[];
class Condition_150300 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionDevastatorCondition_150300 : public Condition_150300 {
  public:
    CollisionDevastatorCondition_150300* vfunc_5(signed char flags);
};
extern void* Condition_150330_vftable[];
class Condition_150330 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class HitPushbackCondition_150330 : public Condition_150330 {
  public:
    HitPushbackCondition_150330* vfunc_5(signed char flags);
};
extern void* Condition_150360_vftable[];
class Condition_150360 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionTargetIsTargetCondition_150360 : public Condition_150360 {
  public:
    CollisionTargetIsTargetCondition_150360* vfunc_5(signed char flags);
};
extern void* Condition_150390_vftable[];
class Condition_150390 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionTargetSizeCondition_150390 : public Condition_150390 {
  public:
    CollisionTargetSizeCondition_150390* vfunc_5(signed char flags);
};
extern void* Condition_1503c0_vftable[];
class Condition_1503c0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionSourceIsMissileCondition_1503c0 : public Condition_1503c0 {
  public:
    CollisionSourceIsMissileCondition_1503c0* vfunc_5(signed char flags);
};
extern void* Condition_1503f0_vftable[];
class Condition_1503f0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class HitPushbackVelocityCondition_1503f0 : public Condition_1503f0 {
  public:
    HitPushbackVelocityCondition_1503f0* vfunc_5(signed char flags);
};
extern char threat_vftable_150420;
struct Obj_150420 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_150420*);
class CollisionThrownObjectCondition_150420 {
  public:
    void* vftable;
    char pad[0x0c];
    CollisionThrownObjectCondition_150420* vfunc_5(unsigned char);
};
extern void* Condition_150450_vftable[];
class Condition_150450 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionExplosionCondition_150450 : public Condition_150450 {
  public:
    CollisionExplosionCondition_150450* vfunc_5(signed char flags);
};
extern char threat_vftable_150480;
struct Obj_150480 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_150480*);
class CollisionSourceNodeCondition_150480 {
  public:
    void* vftable;
    char pad[0x0c];
    CollisionSourceNodeCondition_150480* vfunc_5(unsigned char);
};
extern void* Condition_1504b0_vftable[];
class Condition_1504b0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionChargeCondition_1504b0 : public Condition_1504b0 {
  public:
    CollisionChargeCondition_1504b0* vfunc_5(signed char flags);
};
extern char threat_vftable_1504e0;
struct Obj_1504e0 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_1504e0*);
class CollisionTargetNameCondition_1504e0 {
  public:
    void* vftable;
    char pad[0x0c];
    CollisionTargetNameCondition_1504e0* vfunc_5(unsigned char);
};
extern void* Condition_150510_vftable[];
class Condition_150510 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionDamageHealthCompareCondition_150510 : public Condition_150510 {
  public:
    CollisionDamageHealthCompareCondition_150510* vfunc_5(signed char flags);
};
extern void* Condition_150540_vftable[];
class Condition_150540 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionTargetTypeCondition_150540 : public Condition_150540 {
  public:
    CollisionTargetTypeCondition_150540* vfunc_5(signed char flags);
};
extern void* Condition_150570_vftable[];
class Condition_150570 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionInterruptPriorityCondition_150570 : public Condition_150570 {
  public:
    CollisionInterruptPriorityCondition_150570* vfunc_5(signed char flags);
};
extern char threat_vftable_1505a0;
struct Obj_1505a0 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_1505a0*);
class CollisionSourceNameCondition_1505a0 {
  public:
    void* vftable;
    char pad[0x0c];
    CollisionSourceNameCondition_1505a0* vfunc_5(unsigned char);
};
extern void* Track_1505d0_vftable[];
class Track_1505d0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class InterruptAccumulatorSetTrack_1505d0 : public Track_1505d0 {
  public:
    InterruptAccumulatorSetTrack_1505d0* vfunc_5(signed char flags);
};
extern void* Track_150600_vftable[];
class Track_150600 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class HitThrowTrack_150600 : public Track_150600 {
  public:
    HitThrowTrack_150600* vfunc_5(signed char flags);
};
extern void* g_vftable_150630[];
class Mem_150630 {
  public:
    ~Mem_150630();
};
class Track_150630 {
  public:
    void* vptr;
    void Fin();
};
class HitReactionFloatTrack_150630 : public Track_150630 {
  public:
    char pad[20];
    Mem_150630 m;
    HitReactionFloatTrack_150630* f2(unsigned char flags);
};
extern void* Track_150660_vftable[];
class Track_150660 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
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
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x14];
    Sub_150690 sub;
    void BaseCall();
    HitReactionTrack(int);
};
extern void __cdecl thunk_FUN_00267090(HitReactionTrack*);
extern void* Track_1506c0_vftable[];
class Track_1506c0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class HitWaitTrack_1506c0 : public Track_1506c0 {
  public:
    HitWaitTrack_1506c0* vfunc_5(signed char flags);
};
extern void* Track_1506f0_vftable[];
class Track_1506f0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class InterruptPriorityTrack_1506f0 : public Track_1506f0 {
  public:
    InterruptPriorityTrack_1506f0* vfunc_5(signed char flags);
};
extern void* Track_150720_vftable[];
class Track_150720 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class HitOrientToPushbackTrack_150720 : public Track_150720 {
  public:
    HitOrientToPushbackTrack_150720* vfunc_5(signed char flags);
};
extern void* Track_150750_vftable[];
class Track_150750 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class HitFloatTrack_150750 : public Track_150750 {
  public:
    HitFloatTrack_150750* vfunc_5(signed char flags);
};
extern void* Track_150780_vftable[];
class Track_150780 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class ClearFightParamsHitRecordTrack_150780 : public Track_150780 {
  public:
    ClearFightParamsHitRecordTrack_150780* vfunc_5(signed char flags);
};
extern void* Track_1507b0_vftable[];
class Track_1507b0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class HitPushbackAddTrack_1507b0 : public Track_1507b0 {
  public:
    HitPushbackAddTrack_1507b0* vfunc_5(signed char flags);
};
extern void* Track_1507e0_vftable[];
class Track_1507e0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class HealthTrack_1507e0 : public Track_1507e0 {
  public:
    HealthTrack_1507e0* vfunc_5(signed char flags);
};
extern void* Track_150810_vftable[];
class Track_150810 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class HitDamageTrack_150810 : public Track_150810 {
  public:
    HitDamageTrack_150810* vfunc_5(signed char flags);
};
extern void* Track_150840_vftable[];
class Track_150840 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class GroundSlideTrack_150840 : public Track_150840 {
  public:
    GroundSlideTrack_150840* vfunc_5(signed char flags);
};
extern void* Track_150870_vftable[];
class Track_150870 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class HitPushbackTrack_150870 : public Track_150870 {
  public:
    HitPushbackTrack_150870* vfunc_5(signed char flags);
};
extern void* Track_1508a0_vftable[];
class Track_1508a0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
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
            ((Helper_14ffc0*)p)->g();
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
    *(void***)this = Condition_1501e0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150210 hulkfight::motion::CollisionSourceForceMagnitudeCondition::vfunc_5 (36 B): matches/0x00150210.cpp
// sym: ?vfunc_5@CollisionSourceForceMagnitudeCondition_150210@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionSourceForceMagnitudeCondition_150210* CollisionSourceForceMagnitudeCondition_150210::vfunc_5(signed char flags) {
    *(void***)this = Condition_150210_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150240 hulkfight::motion::CollisionThrowCondition::vfunc_5 (36 B): matches/0x00150240.cpp
// sym: ?vfunc_5@CollisionThrowCondition_150240@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionThrowCondition_150240* CollisionThrowCondition_150240::vfunc_5(signed char flags) {
    *(void***)this = Condition_150240_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150270 hulkfight::motion::CollisionSourceSizeCondition::vfunc_5 (36 B): matches/0x00150270.cpp
// sym: ?vfunc_5@CollisionSourceSizeCondition_150270@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionSourceSizeCondition_150270* CollisionSourceSizeCondition_150270::vfunc_5(signed char flags) {
    *(void***)this = Condition_150270_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001502a0 hulkfight::motion::CollisionSourceTypeCondition::vfunc_5 (36 B): matches/0x001502a0.cpp
// sym: ?vfunc_5@CollisionSourceTypeCondition_1502a0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionSourceTypeCondition_1502a0* CollisionSourceTypeCondition_1502a0::vfunc_5(signed char flags) {
    *(void***)this = Condition_1502a0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001502d0 hulkfight::motion::CollisionTargetPriorityCondition::vfunc_5 (36 B): matches/0x001502d0.cpp
// sym: ?vfunc_5@CollisionTargetPriorityCondition_1502d0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionTargetPriorityCondition_1502d0* CollisionTargetPriorityCondition_1502d0::vfunc_5(signed char flags) {
    *(void***)this = Condition_1502d0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150300 hulkfight::motion::CollisionDevastatorCondition::vfunc_5 (36 B): matches/0x00150300.cpp
// sym: ?vfunc_5@CollisionDevastatorCondition_150300@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionDevastatorCondition_150300* CollisionDevastatorCondition_150300::vfunc_5(signed char flags) {
    *(void***)this = Condition_150300_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150330 hulkfight::motion::HitPushbackCondition::vfunc_5 (36 B): matches/0x00150330.cpp
// sym: ?vfunc_5@HitPushbackCondition_150330@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitPushbackCondition_150330* HitPushbackCondition_150330::vfunc_5(signed char flags) {
    *(void***)this = Condition_150330_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150360 hulkfight::motion::CollisionTargetIsTargetCondition::vfunc_5 (36 B): matches/0x00150360.cpp
// sym: ?vfunc_5@CollisionTargetIsTargetCondition_150360@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionTargetIsTargetCondition_150360* CollisionTargetIsTargetCondition_150360::vfunc_5(signed char flags) {
    *(void***)this = Condition_150360_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150390 hulkfight::motion::CollisionTargetSizeCondition::vfunc_5 (36 B): matches/0x00150390.cpp
// sym: ?vfunc_5@CollisionTargetSizeCondition_150390@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionTargetSizeCondition_150390* CollisionTargetSizeCondition_150390::vfunc_5(signed char flags) {
    *(void***)this = Condition_150390_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001503c0 hulkfight::motion::CollisionSourceIsMissileCondition::vfunc_5 (36 B): matches/0x001503c0.cpp
// sym: ?vfunc_5@CollisionSourceIsMissileCondition_1503c0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionSourceIsMissileCondition_1503c0* CollisionSourceIsMissileCondition_1503c0::vfunc_5(signed char flags) {
    *(void***)this = Condition_1503c0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001503f0 hulkfight::motion::HitPushbackVelocityCondition::vfunc_5 (36 B): matches/0x001503f0.cpp
// sym: ?vfunc_5@HitPushbackVelocityCondition_1503f0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitPushbackVelocityCondition_1503f0* HitPushbackVelocityCondition_1503f0::vfunc_5(signed char flags) {
    *(void***)this = Condition_1503f0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150420 hulkfight::motion::CollisionThrownObjectCondition::vfunc_5 (46 B): matches/0x00150420.cpp
// sym: ?vfunc_5@CollisionThrownObjectCondition_150420@fn_fb14e9c5@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
CollisionThrownObjectCondition_150420* CollisionThrownObjectCondition_150420::vfunc_5(unsigned char param) {
    CollisionThrownObjectCondition_150420* p = this;
    *(char**)p = &threat_vftable_150420;
    ((Obj_150420*)((char*)p + 0x10))->f1();
    ((Obj_150420*)p)->f2();
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
    *(void***)this = Condition_150450_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150480 hulkfight::motion::CollisionSourceNodeCondition::vfunc_5 (46 B): matches/0x00150480.cpp
// sym: ?vfunc_5@CollisionSourceNodeCondition_150480@fn_fb14e9c5@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
CollisionSourceNodeCondition_150480* CollisionSourceNodeCondition_150480::vfunc_5(unsigned char param) {
    CollisionSourceNodeCondition_150480* p = this;
    *(char**)p = &threat_vftable_150480;
    ((Obj_150480*)((char*)p + 0x10))->f1();
    ((Obj_150480*)p)->f2();
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
    *(void***)this = Condition_1504b0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001504e0 hulkfight::motion::CollisionTargetNameCondition::vfunc_5 (46 B): matches/0x001504e0.cpp
// sym: ?vfunc_5@CollisionTargetNameCondition_1504e0@fn_fb14e9c5@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
CollisionTargetNameCondition_1504e0* CollisionTargetNameCondition_1504e0::vfunc_5(unsigned char param) {
    CollisionTargetNameCondition_1504e0* p = this;
    *(char**)p = &threat_vftable_1504e0;
    ((Obj_1504e0*)((char*)p + 0x10))->f1();
    ((Obj_1504e0*)p)->f2();
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
    *(void***)this = Condition_150510_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150540 hulkfight::motion::CollisionTargetTypeCondition::vfunc_5 (36 B): matches/0x00150540.cpp
// sym: ?vfunc_5@CollisionTargetTypeCondition_150540@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionTargetTypeCondition_150540* CollisionTargetTypeCondition_150540::vfunc_5(signed char flags) {
    *(void***)this = Condition_150540_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150570 hulkfight::motion::CollisionInterruptPriorityCondition::vfunc_5 (36 B): matches/0x00150570.cpp
// sym: ?vfunc_5@CollisionInterruptPriorityCondition_150570@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionInterruptPriorityCondition_150570* CollisionInterruptPriorityCondition_150570::vfunc_5(signed char flags) {
    *(void***)this = Condition_150570_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001505a0 hulkfight::motion::CollisionSourceNameCondition::vfunc_5 (46 B): matches/0x001505a0.cpp
// sym: ?vfunc_5@CollisionSourceNameCondition_1505a0@fn_fb14e9c5@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
CollisionSourceNameCondition_1505a0* CollisionSourceNameCondition_1505a0::vfunc_5(unsigned char param) {
    CollisionSourceNameCondition_1505a0* p = this;
    *(char**)p = &threat_vftable_1505a0;
    ((Obj_1505a0*)((char*)p + 0x10))->f1();
    ((Obj_1505a0*)p)->f2();
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
    *(void***)this = Track_1505d0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150600 hulkfight::motion::HitThrowTrack::vfunc_5 (36 B): matches/0x00150600.cpp
// sym: ?vfunc_5@HitThrowTrack_150600@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitThrowTrack_150600* HitThrowTrack_150600::vfunc_5(signed char flags) {
    *(void***)this = Track_150600_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150630 hulkfight::motion::HitReactionFloatTrack::vfunc_5 (46 B): matches/0x00150630.cpp
// sym: ?f2@HitReactionFloatTrack_150630@fn_fb14e9c5@@QAEPAV12@E@Z
HitReactionFloatTrack_150630* HitReactionFloatTrack_150630::f2(unsigned char flags) {
    vptr = g_vftable_150630;

    m.~Mem_150630();
    Fin();
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
    *(void***)this = Track_150660_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150690 hulkfight::motion::HitReactionTrack::vfunc_5 (46 B): matches/0x00150690.cpp
// sym: ??0HitReactionTrack@fn_fb14e9c5@@QAE@H@Z
HitReactionTrack::HitReactionTrack(int flag) {
    BaseCall();
    if (flag & 1)
        thunk_FUN_00267090(this);
}


// 0x001506c0 hulkfight::motion::HitWaitTrack::vfunc_5 (36 B): matches/0x001506c0.cpp
// sym: ?vfunc_5@HitWaitTrack_1506c0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitWaitTrack_1506c0* HitWaitTrack_1506c0::vfunc_5(signed char flags) {
    *(void***)this = Track_1506c0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001506f0 hulkfight::motion::InterruptPriorityTrack::vfunc_5 (36 B): matches/0x001506f0.cpp
// sym: ?vfunc_5@InterruptPriorityTrack_1506f0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
InterruptPriorityTrack_1506f0* InterruptPriorityTrack_1506f0::vfunc_5(signed char flags) {
    *(void***)this = Track_1506f0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150720 hulkfight::motion::HitOrientToPushbackTrack::vfunc_5 (36 B): matches/0x00150720.cpp
// sym: ?vfunc_5@HitOrientToPushbackTrack_150720@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitOrientToPushbackTrack_150720* HitOrientToPushbackTrack_150720::vfunc_5(signed char flags) {
    *(void***)this = Track_150720_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150750 hulkfight::motion::HitFloatTrack::vfunc_5 (36 B): matches/0x00150750.cpp
// sym: ?vfunc_5@HitFloatTrack_150750@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitFloatTrack_150750* HitFloatTrack_150750::vfunc_5(signed char flags) {
    *(void***)this = Track_150750_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150780 hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_5 (36 B): matches/0x00150780.cpp
// sym: ?vfunc_5@ClearFightParamsHitRecordTrack_150780@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ClearFightParamsHitRecordTrack_150780* ClearFightParamsHitRecordTrack_150780::vfunc_5(signed char flags) {
    *(void***)this = Track_150780_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001507b0 hulkfight::motion::HitPushbackAddTrack::vfunc_5 (36 B): matches/0x001507b0.cpp
// sym: ?vfunc_5@HitPushbackAddTrack_1507b0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitPushbackAddTrack_1507b0* HitPushbackAddTrack_1507b0::vfunc_5(signed char flags) {
    *(void***)this = Track_1507b0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001507e0 hulkfight::motion::HealthTrack::vfunc_5 (36 B): matches/0x001507e0.cpp
// sym: ?vfunc_5@HealthTrack_1507e0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HealthTrack_1507e0* HealthTrack_1507e0::vfunc_5(signed char flags) {
    *(void***)this = Track_1507e0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150810 hulkfight::motion::HitDamageTrack::vfunc_5 (36 B): matches/0x00150810.cpp
// sym: ?vfunc_5@HitDamageTrack_150810@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitDamageTrack_150810* HitDamageTrack_150810::vfunc_5(signed char flags) {
    *(void***)this = Track_150810_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150840 hulkfight::motion::GroundSlideTrack::vfunc_5 (36 B): matches/0x00150840.cpp
// sym: ?vfunc_5@GroundSlideTrack_150840@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
GroundSlideTrack_150840* GroundSlideTrack_150840::vfunc_5(signed char flags) {
    *(void***)this = Track_150840_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00150870 hulkfight::motion::HitPushbackTrack::vfunc_5 (36 B): matches/0x00150870.cpp
// sym: ?vfunc_5@HitPushbackTrack_150870@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
HitPushbackTrack_150870* HitPushbackTrack_150870::vfunc_5(signed char flags) {
    *(void***)this = Track_150870_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001508a0 hulkfight::motion::NoHitPushbackTrack::vfunc_5 (36 B): matches/0x001508a0.cpp
// sym: ?vfunc_5@NoHitPushbackTrack_1508a0@fn_fb14e9c5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
NoHitPushbackTrack_1508a0* NoHitPushbackTrack_1508a0::vfunc_5(signed char flags) {
    *(void***)this = Track_1508a0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fb14e9c5
