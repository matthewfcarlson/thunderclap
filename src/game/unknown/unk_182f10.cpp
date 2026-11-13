// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00182f10..0x00183510 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f6fed9ea {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6fed9ea {} using namespace fn_f6fed9ea;
namespace fn_f6fed9ea {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f6fed9ea {
extern void* hulk_at_0041912c[];
class Condition_182f10 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropMissionCriticalCondition : public Condition_182f10 {
  public:
    PropMissionCriticalCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0041914c[];
class Condition_182f40 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class SmartPropGrabbableCondition : public Condition_182f40 {
  public:
    SmartPropGrabbableCondition* vfunc_5(signed char flags);
};
} }
extern int hulk_at_0041916c;
class Condition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Elem_182f70 {
  public:
    void Fn_0027af50();
};
namespace hulkfight { namespace motion {
class GrapplePropStateByNameCondition : public Condition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual GrapplePropStateByNameCondition* vfunc_5(int);
    virtual void v6();
    char pad0[0x14];
    Elem_182f70 elem;
    void Init_002345b0();
};
} }
extern void __cdecl thunk_0008d330(hulkfight::motion::GrapplePropStateByNameCondition*);
extern void* hulk_at_0041918c[];
class Condition_182fa0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropGrabbableIsThrownCondition : public Condition_182fa0 {
  public:
    PropGrabbableIsThrownCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_004191ac;
class Elem_182fd0 {
  public:
    void Fn_0027af50();
};
namespace hulkfight { namespace motion {
class PropMassCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual PropMassCondition* vfunc_5(char flag);
    virtual void v6();
    char pad[0x18 - sizeof(void*)];
    Elem_182fd0 elem;
    void BaseFn_002345b0();
};
} }
extern void Cleanup_0008d330(hulkfight::motion::PropMassCondition*);
extern void* hulk_at_004191cc[];
class Condition_183000 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropAtRestCondition : public Condition_183000 {
  public:
    PropAtRestCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_004191ec[];
class Condition_183030 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropIsAttachedCondition : public Condition_183030 {
  public:
    PropIsAttachedCondition* vfunc_5(signed char flags);
};
} }
extern int hulk_at_0041920c;
class Sub_183060 {
  public:
    void Init_0027af50();
};
namespace hulkfight { namespace motion {
class PropStateByNameCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual PropStateByNameCondition* vfunc_5(unsigned int);
    virtual void vfunc_6();
    char pad[0x18 - 4];
    void Second_002345b0();
};
} }
extern void thunk_FUN_00267090(void*);
extern void* hulk_at_0041922c[];
class Condition_183090 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropStateByIndexCondition : public Condition_183090 {
  public:
    PropStateByIndexCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0041924c[];
class Condition_1830c0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropMissileCountCondition : public Condition_1830c0 {
  public:
    PropMissileCountCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0041926c[];
class Condition_1830f0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropCollidedWithWorldCondition : public Condition_1830f0 {
  public:
    PropCollidedWithWorldCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0041928c[];
class Condition_183120 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class SmartPropIsCargoCondition : public Condition_183120 {
  public:
    SmartPropIsCargoCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_004192ac[];
class Condition_183150 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class CSMPropIsCharacterCondition : public Condition_183150 {
  public:
    CSMPropIsCharacterCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_004192cc[];
class Track_183180 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropActorToPropTrack : public Track_183180 {
  public:
    PropActorToPropTrack* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_004192fc[];
class Str_1831b0 {
  public:
    void Init_0027af50();
};
class Track_1831b0 {
  public:
    void* vptr;
    char pad[20];
    Str_1831b0 s;
    void Fin_00236d60();
};
class PropSetStateByNameTrack_1831b0 : public Track_1831b0 {
  public:
    void* Del(unsigned char flags);
};
extern void* hulk_at_0041932c[];
class Track_1831e0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropActorThinkingTrack : public Track_1831e0 {
  public:
    PropActorThinkingTrack* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0041935c[];
class Track_183210 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropDropTrack : public Track_183210 {
  public:
    PropDropTrack* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0041938c[];
struct Sub_183240 {
    char c;
    void Fin_0027af50();
};
class Track_183240 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class PropAnimationTrack_183240 : public Track_183240 {
  public:
    char pad[0x18 - 4];
    Sub_183240 sub;
    PropAnimationTrack_183240* f5(unsigned char flags);
};
extern void* hulk_at_004193bc[];
class Track_183270 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class GrapplePropDamageTrack : public Track_183270 {
  public:
    GrapplePropDamageTrack* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_004193ec[];
class Ref_1832a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Track_1832a0 {
  public:
    void* vptr;
    void Fin_00236d60();
};
void Free_0008d330(void*) throw();
struct Sub_1832a0 {
    char c;
};
extern "C" void __fastcall FUN_0027af50(Sub_1832a0*) throw();
extern "C" void __fastcall FUN_00234150(Sub_1832a0*) throw();
class PropThrowTrack_1832a0 : public Track_1832a0 {
  public:
    char p68[100];
    Sub_1832a0 s68;
    char p78[15];
    Sub_1832a0 s78;
    PropThrowTrack_1832a0* f(unsigned char fl);
};
extern "C" char DAT_0041941c[];
typedef unsigned char u8_1832e0;
extern void __cdecl cleanup_0008d330(void*);
class Sub_1832e0 {
  public:
    void Init_0027af50();
};
namespace hulkfight { namespace motion {
class BallAndChainReturnTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual BallAndChainReturnTrack* vfunc_5(u8_1832e0);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    void BaseInit_00236d60();
    char pad[0x60 - 4];
};
} }
extern void* hulk_at_0041944c[];
class Track_183320 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropSetStateByIndexTrack : public Track_183320 {
  public:
    PropSetStateByIndexTrack* vfunc_5(signed char flags);
};
} }
extern "C" char DAT_0041947c[];
typedef unsigned char u8_183350;
struct Sub_183350 {
    void Init_0027af50();
};
extern void DeleteObj_0008d330(void*);
namespace hulkfight { namespace motion {
class BallAndChainShootTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual BallAndChainShootTrack* vfunc_5(u8_183350);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    void BaseInit_00236d60();
    char pad[0x78 - 4];
};
} }
extern void* hulk_at_004194ac[];
class Track_183390 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class BallAndChainSpinTrack : public Track_183390 {
  public:
    BallAndChainSpinTrack* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_004194dc[];
class Track_1833c0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class ShieldArcTrack : public Track_1833c0 {
  public:
    ShieldArcTrack* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0041950c[];
class Track_1833f0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropAddToCollisionTrack : public Track_1833f0 {
  public:
    PropAddToCollisionTrack* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0041953c[];
class Track_183420 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropAddToMissileCountTrack : public Track_183420 {
  public:
    PropAddToMissileCountTrack* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0041956c[];
class Track_183450 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropDamageTrack : public Track_183450 {
  public:
    PropDamageTrack* vfunc_5(signed char flags);
};
} }
extern "C" void __cdecl thunk_FUN_00267090_2_0008d330(void*);
extern char hulk_at_0041959c;
class SubObj_183480 {
  public:
    void Reset_0027af50();
};
namespace hulkfight { namespace motion {
class PropSpawnTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void* vfunc_5(unsigned char param);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();

    void DoSomething_00236d60();

    void* vftable_;
    char pad_04[0x0c];
    void* field_10;
    char pad_14[0x04];
};
} }
extern void* hulk_at_004195cc[];
class Track_1834c0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class PropDestroyTrack : public Track_1834c0 {
  public:
    PropDestroyTrack* vfunc_5(signed char flags);
};
} }


// 0x00182f10 hulkfight::motion::PropMissionCriticalCondition::vfunc_5 (36 B): matches/0x00182f10.cpp
// sym: ?vfunc_5@PropMissionCriticalCondition@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropMissionCriticalCondition* hulkfight::motion::PropMissionCriticalCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041912c;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00182f40 hulkfight::motion::SmartPropGrabbableCondition::vfunc_5 (36 B): matches/0x00182f40.cpp
// sym: ?vfunc_5@SmartPropGrabbableCondition@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::SmartPropGrabbableCondition* hulkfight::motion::SmartPropGrabbableCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041914c;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00182f70 hulkfight::motion::GrapplePropStateByNameCondition::vfunc_5 (46 B): matches/0x00182f70.cpp
// sym: ?vfunc_5@GrapplePropStateByNameCondition@motion@hulkfight@fn_f6fed9ea@@UAEPAV1234@H@Z
hulkfight::motion::GrapplePropStateByNameCondition* hulkfight::motion::GrapplePropStateByNameCondition::vfunc_5(int flag) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0041916c;
    elem.Fn_0027af50();
    Init_002345b0();
    if (flag & 1)
        thunk_0008d330(this);
    return this;
}


// 0x00182fa0 hulkfight::motion::PropGrabbableIsThrownCondition::vfunc_5 (36 B): matches/0x00182fa0.cpp
// sym: ?vfunc_5@PropGrabbableIsThrownCondition@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropGrabbableIsThrownCondition* hulkfight::motion::PropGrabbableIsThrownCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041918c;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00182fd0 hulkfight::motion::PropMassCondition::vfunc_5 (46 B): matches/0x00182fd0.cpp
// sym: ?vfunc_5@PropMassCondition@motion@hulkfight@fn_f6fed9ea@@UAEPAV1234@D@Z
hulkfight::motion::PropMassCondition* hulkfight::motion::PropMassCondition::vfunc_5(char flag) {
    *(void**)this = &hulk_at_004191ac;
    elem.Fn_0027af50();
    BaseFn_002345b0();
    if (flag & 1)
        Cleanup_0008d330(this);
    return this;
}


// 0x00183000 hulkfight::motion::PropAtRestCondition::vfunc_5 (36 B): matches/0x00183000.cpp
// sym: ?vfunc_5@PropAtRestCondition@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropAtRestCondition* hulkfight::motion::PropAtRestCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004191cc;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00183030 hulkfight::motion::PropIsAttachedCondition::vfunc_5 (36 B): matches/0x00183030.cpp
// sym: ?vfunc_5@PropIsAttachedCondition@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropIsAttachedCondition* hulkfight::motion::PropIsAttachedCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004191ec;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00183060 hulkfight::motion::PropStateByNameCondition::vfunc_5 (46 B): matches/0x00183060.cpp
// sym: ?vfunc_5@PropStateByNameCondition@motion@hulkfight@fn_f6fed9ea@@UAEPAV1234@I@Z
hulkfight::motion::PropStateByNameCondition* hulkfight::motion::PropStateByNameCondition::vfunc_5(unsigned int flags) {
    Sub_183060* s = (Sub_183060*)((char*)this + 0x18);
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0041920c;
    s->Init_0027af50();
    Second_002345b0();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00183090 hulkfight::motion::PropStateByIndexCondition::vfunc_5 (36 B): matches/0x00183090.cpp
// sym: ?vfunc_5@PropStateByIndexCondition@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropStateByIndexCondition* hulkfight::motion::PropStateByIndexCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041922c;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001830c0 hulkfight::motion::PropMissileCountCondition::vfunc_5 (36 B): matches/0x001830c0.cpp
// sym: ?vfunc_5@PropMissileCountCondition@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropMissileCountCondition* hulkfight::motion::PropMissileCountCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041924c;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001830f0 hulkfight::motion::PropCollidedWithWorldCondition::vfunc_5 (36 B): matches/0x001830f0.cpp
// sym: ?vfunc_5@PropCollidedWithWorldCondition@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropCollidedWithWorldCondition* hulkfight::motion::PropCollidedWithWorldCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041926c;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00183120 hulkfight::motion::SmartPropIsCargoCondition::vfunc_5 (36 B): matches/0x00183120.cpp
// sym: ?vfunc_5@SmartPropIsCargoCondition@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::SmartPropIsCargoCondition* hulkfight::motion::SmartPropIsCargoCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041928c;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00183150 hulkfight::motion::CSMPropIsCharacterCondition::vfunc_5 (36 B): matches/0x00183150.cpp
// sym: ?vfunc_5@CSMPropIsCharacterCondition@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::CSMPropIsCharacterCondition* hulkfight::motion::CSMPropIsCharacterCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004192ac;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00183180 hulkfight::motion::PropActorToPropTrack::vfunc_5 (36 B): matches/0x00183180.cpp
// sym: ?vfunc_5@PropActorToPropTrack@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropActorToPropTrack* hulkfight::motion::PropActorToPropTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004192cc;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001831b0 hulkfight::motion::PropSetStateByNameTrack::vfunc_5 (46 B): matches/0x001831b0.cpp
// sym: ?Del@PropSetStateByNameTrack_1831b0@fn_f6fed9ea@@QAEPAXE@Z
void* PropSetStateByNameTrack_1831b0::Del(unsigned char flags) {
    vptr = hulk_at_004192fc;
    s.Init_0027af50();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x001831e0 hulkfight::motion::PropActorThinkingTrack::vfunc_5 (36 B): matches/0x001831e0.cpp
// sym: ?vfunc_5@PropActorThinkingTrack@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropActorThinkingTrack* hulkfight::motion::PropActorThinkingTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041932c;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00183210 hulkfight::motion::PropDropTrack::vfunc_5 (36 B): matches/0x00183210.cpp
// sym: ?vfunc_5@PropDropTrack@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropDropTrack* hulkfight::motion::PropDropTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041935c;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00183240 hulkfight::motion::PropAnimationTrack::vfunc_5 (46 B): matches/0x00183240.cpp
// sym: ?f5@PropAnimationTrack_183240@fn_f6fed9ea@@QAEPAV12@E@Z
PropAnimationTrack_183240* PropAnimationTrack_183240::f5(unsigned char flags) {
    vptr = hulk_at_0041938c;
    sub.Fin_0027af50();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00183270 hulkfight::motion::GrapplePropDamageTrack::vfunc_5 (36 B): matches/0x00183270.cpp
// sym: ?vfunc_5@GrapplePropDamageTrack@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::GrapplePropDamageTrack* hulkfight::motion::GrapplePropDamageTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004193bc;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001832a0 hulkfight::motion::PropThrowTrack::vfunc_5 (54 B): matches/0x001832a0.cpp
// sym: ?f@PropThrowTrack_1832a0@fn_f6fed9ea@@QAEPAV12@E@Z
PropThrowTrack_1832a0* PropThrowTrack_1832a0::f(unsigned char fl) {
    vptr = hulk_at_004193ec;
    FUN_0027af50(&s78);
    FUN_00234150(&s68);
    Fin_00236d60();
    if (fl & 1)
        Free_0008d330(this);
    return this;
}


// 0x001832e0 hulkfight::motion::BallAndChainReturnTrack::vfunc_5 (54 B): matches/0x001832e0.cpp
// sym: ?vfunc_5@BallAndChainReturnTrack@motion@hulkfight@fn_f6fed9ea@@UAEPAV1234@E@Z
hulkfight::motion::BallAndChainReturnTrack* hulkfight::motion::BallAndChainReturnTrack::vfunc_5(u8_1832e0 flag) {
    Sub_1832e0* a = (Sub_1832e0*)((char*)this + 0x60);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0041941c);
    a->Init_0027af50();
    ((Sub_1832e0*)((char*)this + 0x48))->Init_0027af50();
    this->BaseInit_00236d60();
    if (flag & 1)
        cleanup_0008d330(this);
    return this;
}


// 0x00183320 hulkfight::motion::PropSetStateByIndexTrack::vfunc_5 (36 B): matches/0x00183320.cpp
// sym: ?vfunc_5@PropSetStateByIndexTrack@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropSetStateByIndexTrack* hulkfight::motion::PropSetStateByIndexTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041944c;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00183350 hulkfight::motion::BallAndChainShootTrack::vfunc_5 (54 B): matches/0x00183350.cpp
// sym: ?vfunc_5@BallAndChainShootTrack@motion@hulkfight@fn_f6fed9ea@@UAEPAV1234@E@Z
hulkfight::motion::BallAndChainShootTrack* hulkfight::motion::BallAndChainShootTrack::vfunc_5(u8_183350 x) {
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0041947c);
    ((Sub_183350*)((char*)this + 0x78))->Init_0027af50();
    ((Sub_183350*)((char*)this + 0x60))->Init_0027af50();
    BaseInit_00236d60();
    if (x & 1)
        DeleteObj_0008d330(this);
    return this;
}


// 0x00183390 hulkfight::motion::BallAndChainSpinTrack::vfunc_5 (36 B): matches/0x00183390.cpp
// sym: ?vfunc_5@BallAndChainSpinTrack@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::BallAndChainSpinTrack* hulkfight::motion::BallAndChainSpinTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004194ac;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001833c0 hulkfight::motion::ShieldArcTrack::vfunc_5 (36 B): matches/0x001833c0.cpp
// sym: ?vfunc_5@ShieldArcTrack@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::ShieldArcTrack* hulkfight::motion::ShieldArcTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004194dc;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x001833f0 hulkfight::motion::PropAddToCollisionTrack::vfunc_5 (36 B): matches/0x001833f0.cpp
// sym: ?vfunc_5@PropAddToCollisionTrack@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropAddToCollisionTrack* hulkfight::motion::PropAddToCollisionTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041950c;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00183420 hulkfight::motion::PropAddToMissileCountTrack::vfunc_5 (36 B): matches/0x00183420.cpp
// sym: ?vfunc_5@PropAddToMissileCountTrack@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropAddToMissileCountTrack* hulkfight::motion::PropAddToMissileCountTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041953c;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00183450 hulkfight::motion::PropDamageTrack::vfunc_5 (36 B): matches/0x00183450.cpp
// sym: ?vfunc_5@PropDamageTrack@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropDamageTrack* hulkfight::motion::PropDamageTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041956c;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00183480 hulkfight::motion::PropSpawnTrack::vfunc_5 (58 B): matches/0x00183480.cpp
// sym: ?vfunc_5@PropSpawnTrack@motion@hulkfight@fn_f6fed9ea@@UAEPAXE@Z
void* hulkfight::motion::PropSpawnTrack::vfunc_5(unsigned char param) {
    void* m = *(void**)((char*)this + 0x10);
    *(void**)this = (void*)&hulk_at_0041959c;
    thunk_FUN_00267090(m);
    ((SubObj_183480*)((char*)this + 0x18))->Reset_0027af50();
    this->DoSomething_00236d60();
    if (param & 1) {
        thunk_FUN_00267090_2_0008d330(this);
    }
    return this;
}


// 0x001834c0 hulkfight::motion::PropDestroyTrack::vfunc_5 (36 B): matches/0x001834c0.cpp
// sym: ?vfunc_5@PropDestroyTrack@motion@hulkfight@fn_f6fed9ea@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::PropDestroyTrack* hulkfight::motion::PropDestroyTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004195cc;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_f6fed9ea
