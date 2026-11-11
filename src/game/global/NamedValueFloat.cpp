// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f8da0..0x000f8dd0 (kind game, layer game, confidence medium), dominant class NamedValueFloat
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fe8a8073 {
#define TREE_TU_END }
namespace fn_fe8a8073 {} using namespace fn_fe8a8073;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe8a8073 {
struct Callback_f8da0 {
    virtual void changed(float);
};

} // namespace fn_fe8a8073

// 0x000f8da0 NamedValueFloat::vfunc_1 (40 B): matches/0x000f8da0.cpp
// sym: ?vfunc_1@NamedValueFloat@@UAEXXZ
void NamedValueFloat::vfunc_1() {
    float v = this->f_44;
    this->f_40 = v;
    if ((*(void * *)&this->f_48))
        ((Callback_f8da0*)(*(void * *)&this->f_48))->changed(v);
    vfunc_0();
}

