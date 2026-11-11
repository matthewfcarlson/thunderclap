// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f8dd0..0x000f8df0 (kind game, layer game, confidence medium), dominant class NamedValueInt
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fe7cba98 {
#define TREE_TU_END }
namespace fn_fe7cba98 {} using namespace fn_fe7cba98;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe7cba98 {
class Callback_f8dd0 {
  public:
    virtual void call(int);
};

} // namespace fn_fe7cba98

// 0x000f8dd0 NamedValueInt::vfunc_1 (28 B): matches/0x000f8dd0.cpp
// sym: ?vfunc_1@NamedValueInt@@UAEXXZ
void NamedValueInt::vfunc_1() {
    this->f_40 = this->f_44;
    if ((*(Callback_f8dd0 * *)&this->f_48))
        (*(Callback_f8dd0 * *)&this->f_48)->call(this->f_44);
    vfunc_0();
}

