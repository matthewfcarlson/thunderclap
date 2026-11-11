// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00167560..0x001677b0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fb3274a2 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb3274a2 {} using namespace fn_fb3274a2;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fb3274a2 {
extern void* hulk_at_00416738[];
class Condition_167560 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class TurningVelocityCondition : public Condition_167560 {
  public:
    TurningVelocityCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_00416758[];
class Condition_167590 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class IntentionInputCondition : public Condition_167590 {
  public:
    IntentionInputCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_00416778[];
class Condition_1675c0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class LocomotionMotionStateCondition : public Condition_1675c0 {
  public:
    LocomotionMotionStateCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_00416798[];
class Condition_1675f0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class GrappleReactionTypeCondition : public Condition_1675f0 {
  public:
    GrappleReactionTypeCondition* vfunc_5(signed char flags);
};
} }
extern char hulk_at_004167b8;
struct Obj_167620 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_167620*);
namespace hulkfight { namespace motion {
class RayCastConeCondition {
  public:
    void* vftable;
    char pad[0x0c];
    RayCastConeCondition* vfunc_5(unsigned char);
};
} }
extern void* hulk_at_004167d8[];
class Condition_167650 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class TargetingCondition : public Condition_167650 {
  public:
    TargetingCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_004167f8[];
class Condition_167680 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class VelocityAnimatedYCondition : public Condition_167680 {
  public:
    VelocityAnimatedYCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_00416818[];
class Condition_1676b0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class TargetLocomotionMotionStateCondition : public Condition_1676b0 {
  public:
    TargetLocomotionMotionStateCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_00416838[];
class Condition_1676e0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class TargetHealthPercentCondition : public Condition_1676e0 {
  public:
    TargetHealthPercentCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_00416858[];
class Condition_167710 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class GrappleHealthCondition : public Condition_167710 {
  public:
    GrappleHealthCondition* vfunc_5(signed char flags);
};
} }
namespace hulkfight { namespace motion {
class TargetCharacterTemplateCondition {
  public:
    virtual void vfunc_0();
    virtual void p_vfunc_1();
    virtual void p_vfunc_2();
    virtual void c_vfunc_3();
    virtual void p_vfunc_4();
    void* vfunc_5(unsigned char flag);
    virtual void vfunc_6();
    void Cleanup_002345b0();
    char pad[8];
    void* m_p;
};
} }
extern void* hulk_at_00416898[];
class Condition_167780 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace motion {
class CharacterPropStatusCondition : public Condition_167780 {
  public:
    CharacterPropStatusCondition* vfunc_5(signed char flags);
};
} }


// 0x00167560 hulkfight::motion::TurningVelocityCondition::vfunc_5 (36 B): matches/0x00167560.cpp
// sym: ?vfunc_5@TurningVelocityCondition@motion@hulkfight@fn_fb3274a2@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::TurningVelocityCondition* hulkfight::motion::TurningVelocityCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416738;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167590 hulkfight::motion::IntentionInputCondition::vfunc_5 (36 B): matches/0x00167590.cpp
// sym: ?vfunc_5@IntentionInputCondition@motion@hulkfight@fn_fb3274a2@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::IntentionInputCondition* hulkfight::motion::IntentionInputCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416758;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001675c0 hulkfight::motion::LocomotionMotionStateCondition::vfunc_5 (36 B): matches/0x001675c0.cpp
// sym: ?vfunc_5@LocomotionMotionStateCondition@motion@hulkfight@fn_fb3274a2@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::LocomotionMotionStateCondition* hulkfight::motion::LocomotionMotionStateCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416778;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001675f0 hulkfight::motion::GrappleReactionTypeCondition::vfunc_5 (36 B): matches/0x001675f0.cpp
// sym: ?vfunc_5@GrappleReactionTypeCondition@motion@hulkfight@fn_fb3274a2@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::GrappleReactionTypeCondition* hulkfight::motion::GrappleReactionTypeCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416798;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167620 hulkfight::motion::RayCastConeCondition::vfunc_5 (46 B): matches/0x00167620.cpp
// sym: ?vfunc_5@RayCastConeCondition@motion@hulkfight@fn_fb3274a2@@QAEPAV1234@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
hulkfight::motion::RayCastConeCondition* hulkfight::motion::RayCastConeCondition::vfunc_5(unsigned char param) {
    hulkfight::motion::RayCastConeCondition* p = this;
    *(char**)p = &hulk_at_004167b8;
    ((Obj_167620*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_167620*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_167620*)p);
    return p;
}


// 0x00167650 hulkfight::motion::TargetingCondition::vfunc_5 (36 B): matches/0x00167650.cpp
// sym: ?vfunc_5@TargetingCondition@motion@hulkfight@fn_fb3274a2@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::TargetingCondition* hulkfight::motion::TargetingCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004167d8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167680 hulkfight::motion::VelocityAnimatedYCondition::vfunc_5 (36 B): matches/0x00167680.cpp
// sym: ?vfunc_5@VelocityAnimatedYCondition@motion@hulkfight@fn_fb3274a2@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::VelocityAnimatedYCondition* hulkfight::motion::VelocityAnimatedYCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004167f8;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001676b0 hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_5 (36 B): matches/0x001676b0.cpp
// sym: ?vfunc_5@TargetLocomotionMotionStateCondition@motion@hulkfight@fn_fb3274a2@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::TargetLocomotionMotionStateCondition* hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416818;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001676e0 hulkfight::motion::TargetHealthPercentCondition::vfunc_5 (36 B): matches/0x001676e0.cpp
// sym: ?vfunc_5@TargetHealthPercentCondition@motion@hulkfight@fn_fb3274a2@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::TargetHealthPercentCondition* hulkfight::motion::TargetHealthPercentCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416838;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167710 hulkfight::motion::GrappleHealthCondition::vfunc_5 (36 B): matches/0x00167710.cpp
// sym: ?vfunc_5@GrappleHealthCondition@motion@hulkfight@fn_fb3274a2@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::GrappleHealthCondition* hulkfight::motion::GrappleHealthCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416858;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00167740 hulkfight::motion::TargetCharacterTemplateCondition::vfunc_5 (50 B): matches/0x00167740.cpp
// sym: ?vfunc_5@TargetCharacterTemplateCondition@motion@hulkfight@fn_fb3274a2@@QAEPAXE@Z
// Same code shape as 0x0011cbc0 (propagated; names are from that function)
void* hulkfight::motion::TargetCharacterTemplateCondition::vfunc_5(unsigned char flag) {
    *(const VFT**)this = &PathLocatorTestCondition_vftable;
    ai_free(m_p);
    Cleanup_002345b0();
    if (flag & 1) {
        ai_delete(this);
    }
    return this;
}


// 0x00167780 hulkfight::motion::CharacterPropStatusCondition::vfunc_5 (36 B): matches/0x00167780.cpp
// sym: ?vfunc_5@CharacterPropStatusCondition@motion@hulkfight@fn_fb3274a2@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::motion::CharacterPropStatusCondition* hulkfight::motion::CharacterPropStatusCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00416898;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fb3274a2
