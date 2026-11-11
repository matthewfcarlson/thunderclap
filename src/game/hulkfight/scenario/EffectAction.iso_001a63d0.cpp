// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001a1ed0..0x001aace0 (kind game, layer game, confidence high), dominant class hulkfight::scenario::EffectAction
// (tree_prelude.h: not needed)


// 0x001a63d0 hulkfight::scenario::EffectAction::vfunc_4 (40 B): matches/0x001a63d0.cpp [isolated: conflict: FUN_0027f250; on include/gen/ and not mergeable]
// sym: ?vfunc_4@EffectAction@scenario@hulkfight@@UAEXXZ
#include "gen/hulkfight.h"

struct Helper_1a63d0 {
    void apply(int);
};
Helper_1a63d0* FUN_0027f250();
void FUN_0027ffb0(int);
class Ref_1a63d0 {
  public:
    virtual void f0();
    virtual void f1();
};

void hulkfight::scenario::EffectAction::vfunc_4() {
    Helper_1a63d0* x = FUN_0027f250();
    x->apply(this->f_24);
    if ((*(void * *)&this->f_28)) {
        ((Ref_1a63d0*)(*(void * *)&this->f_28))->f1();
        (*(void * *)&this->f_28) = 0;
    }
}

