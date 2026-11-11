// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001727f0..0x00172910 (kind game, layer game, confidence medium), dominant class hulkfight::motion::MomentumXZAddAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f975d6ff {
#define TREE_TU_END }
namespace fn_f975d6ff {} using namespace fn_f975d6ff;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f975d6ff {
struct Helper1_1727f0 {
    int f();
};
struct Helper2_1727f0 {
    int f();
};
struct Helper3 {
    void f(void*);
};

} // namespace fn_f975d6ff

// 0x001727f0 hulkfight::motion::MomentumXZAddAction::vfunc_3 (60 B): matches/0x001727f0.cpp
// sym: ?vfunc_3@MomentumXZAddAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::MomentumXZAddAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) { unsigned int x = (unsigned int)__p0; unsigned int y = (unsigned int)__p1;

    Helper1_1727f0* p = (*(Helper1_1727f0 * *)&this->f_20);
    if (!p)
        return false;
    hulk_intptr q = p->f();
    if (!q)
        return false;
    Helper2_1727f0* z = (Helper2_1727f0*)q;
    hulk_intptr r = z->f();
    if (!r)
        return false;
    ((Helper3*)r)->f(&this->f_24);
    this->f_28 = 0;
    return true;
}


// 0x00172830 hulkfight::motion::MomentumXZAddAction::vfunc_5 (222 B): matches/0x00172830.cpp [wrapped: conflict: hulkfight::motion::MomentumXZAddAction]
// sym: ?vfunc_5@MomentumXZAddAction@motion@hulkfight@fn_00172830@@UAE_NHM@Z
namespace fn_00172830 {
struct Vec_172830 {
    float x, y, z;
    float elapsed;
    hulk_freg FUN_0022d110();
    void FUN_00011140(float);
};
struct Body_172830 {
    void FUN_00035760(Vec_172830*);
};
struct Actor_172830 {
    Body_172830* FUN_00059a30();
};
struct Handle_172830 {
    Actor_172830* FUN_000592a0();
};
struct Source_172830 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    char pad[16];
    float rate;
};
namespace hulkfight {
namespace motion {
struct MomentumXZAddAction {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool vfunc_5(int, float);
    char pad[24];
    Source_172830* source;
    Handle_172830* handle;
    Vec_172830 momentum;
};
bool MomentumXZAddAction::vfunc_5(int flag, float dt) {
    if (flag)
        return true;
    if (!handle)
        return false;
    Actor_172830* actor = handle->FUN_000592a0();
    if (!actor)
        return false;
    Body_172830* body = actor->FUN_00059a30();
    if (!body)
        return false;
    hulk_freg rate = source->rate;
    if (rate >= 0.0f) {
        hulk_freg duration = source->v7();
        if (duration >= 0.0f) {
            hulk_freg remaining = duration - momentum.elapsed;
            if (remaining <= 0.0f) {
                momentum.FUN_0022d110();
                momentum.FUN_00011140(rate);
            } else {
                hulk_freg current = momentum.FUN_0022d110();
                momentum.FUN_00011140(current + (rate - current) * (dt / remaining));
            }
        }
    }
    momentum.elapsed += dt;
    body->FUN_00035760(&momentum);
    return true;
}
} // namespace motion
} // namespace hulkfight
} // namespace fn_00172830

