// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e4330..0x000e8490 (kind game, layer game, confidence high), dominant class FEThingsBase
// (tree_prelude.h: not needed)


// 0x000e6a60 FEThingsBase::vfunc_13 (68 B): matches/0x000e6a60.cpp [isolated: lost its match in the tree (call sequence differs); on include/gen/ and not mergeable]
// sym: ?vfunc_13@FEThingsBase@@UAEXXZ
#include "gen/global.h"
#include "gen/owners.h"

class Obj_e6a60 {
  public:
};

void FEThingsBase::vfunc_13() {
    if ((*(Obj_e6a60 * *)&this->f_175c)) {
        this->f_1768 = 0;
        vfunc_48(4);
        this->f_17f8 = 0;
        this->f_176c = 2;
        ((owners::Fader_e5440 *)((*(Obj_e6a60 * *)&this->f_175c)))->FUN_000e5440(2);
    }
}

