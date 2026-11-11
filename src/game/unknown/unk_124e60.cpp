// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00124e60..0x00125010 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f60bff30 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f60bff30 {} using namespace fn_f60bff30;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f60bff30 {
extern void* hulk_at_0040fd74[];
class Condition_124e60 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace ai {
class TargetDistanceCondition : public Condition_124e60 {
  public:
    TargetDistanceCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0040fd94[];
class Condition_124e90 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace ai {
class TargetAngleYCondition : public Condition_124e90 {
  public:
    TargetAngleYCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0040fdb4[];
class Condition_124ec0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace ai {
class TargetDirectionCondition : public Condition_124ec0 {
  public:
    TargetDirectionCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0040fdd4[];
class Condition_124ef0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace ai {
class TargetDistanceYCondition : public Condition_124ef0 {
  public:
    TargetDistanceYCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0040fdf4[];
class Condition_124f20 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace ai {
class TargetOrientationCondition : public Condition_124f20 {
  public:
    TargetOrientationCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0040fe14[];
class Condition_124f50 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace ai {
class ProjectileDistanceCondition : public Condition_124f50 {
  public:
    ProjectileDistanceCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0040fe34[];
class Condition_124f80 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace ai {
class HasTargetCondition : public Condition_124f80 {
  public:
    HasTargetCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0040fe54[];
class Condition_124fb0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace ai {
class TargetVelocityYCondition : public Condition_124fb0 {
  public:
    TargetVelocityYCondition* vfunc_5(signed char flags);
};
} }
extern void* hulk_at_0040fe74[];
class Condition_124fe0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
namespace hulkfight { namespace ai {
class TargetVelocityCondition : public Condition_124fe0 {
  public:
    TargetVelocityCondition* vfunc_5(signed char flags);
};
} }


// 0x00124e60 hulkfight::ai::TargetDistanceCondition::vfunc_5 (36 B): matches/0x00124e60.cpp
// sym: ?vfunc_5@TargetDistanceCondition@ai@hulkfight@fn_f60bff30@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::TargetDistanceCondition* hulkfight::ai::TargetDistanceCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fd74;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00124e90 hulkfight::ai::TargetAngleYCondition::vfunc_5 (36 B): matches/0x00124e90.cpp
// sym: ?vfunc_5@TargetAngleYCondition@ai@hulkfight@fn_f60bff30@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::TargetAngleYCondition* hulkfight::ai::TargetAngleYCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fd94;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00124ec0 hulkfight::ai::TargetDirectionCondition::vfunc_5 (36 B): matches/0x00124ec0.cpp
// sym: ?vfunc_5@TargetDirectionCondition@ai@hulkfight@fn_f60bff30@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::TargetDirectionCondition* hulkfight::ai::TargetDirectionCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fdb4;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00124ef0 hulkfight::ai::TargetDistanceYCondition::vfunc_5 (36 B): matches/0x00124ef0.cpp
// sym: ?vfunc_5@TargetDistanceYCondition@ai@hulkfight@fn_f60bff30@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::TargetDistanceYCondition* hulkfight::ai::TargetDistanceYCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fdd4;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00124f20 hulkfight::ai::TargetOrientationCondition::vfunc_5 (36 B): matches/0x00124f20.cpp
// sym: ?vfunc_5@TargetOrientationCondition@ai@hulkfight@fn_f60bff30@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::TargetOrientationCondition* hulkfight::ai::TargetOrientationCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fdf4;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00124f50 hulkfight::ai::ProjectileDistanceCondition::vfunc_5 (36 B): matches/0x00124f50.cpp
// sym: ?vfunc_5@ProjectileDistanceCondition@ai@hulkfight@fn_f60bff30@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::ProjectileDistanceCondition* hulkfight::ai::ProjectileDistanceCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fe14;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00124f80 hulkfight::ai::HasTargetCondition::vfunc_5 (36 B): matches/0x00124f80.cpp
// sym: ?vfunc_5@HasTargetCondition@ai@hulkfight@fn_f60bff30@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::HasTargetCondition* hulkfight::ai::HasTargetCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fe34;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00124fb0 hulkfight::ai::TargetVelocityYCondition::vfunc_5 (36 B): matches/0x00124fb0.cpp
// sym: ?vfunc_5@TargetVelocityYCondition@ai@hulkfight@fn_f60bff30@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::TargetVelocityYCondition* hulkfight::ai::TargetVelocityYCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fe54;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00124fe0 hulkfight::ai::TargetVelocityCondition::vfunc_5 (36 B): matches/0x00124fe0.cpp
// sym: ?vfunc_5@TargetVelocityCondition@ai@hulkfight@fn_f60bff30@@QAEPAV1234@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::TargetVelocityCondition* hulkfight::ai::TargetVelocityCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fe74;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f60bff30
