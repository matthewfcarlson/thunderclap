// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e1920..0x000e1970 (kind game, layer game, confidence medium), dominant class FEDoWait
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fcb4e139 {
#define TREE_TU_END }
namespace fn_fcb4e139 {} using namespace fn_fcb4e139;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fcb4e139 {
class FEDoAction_e1920 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class Callback_e1930 {
  public:
    virtual void a();
    virtual void b();
};
extern "C" float(__cdecl* GetDelta)();
class FEDoAction_e1930 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

} // namespace fn_fcb4e139

// 0x000e1920 FEDoWait::vfunc_1 (9 B): matches/0x000e1920.cpp
// sym: ?vfunc_1@FEDoWait@@UAEXXZ
void FEDoWait::vfunc_1() {
    this->f_38 = 0;
    this->f_40 = 0;
}


// 0x000e1930 FEDoWait::vfunc_2 (53 B): matches/0x000e1930.cpp
// sym: ?vfunc_2@FEDoWait@@UAEXXZ
void FEDoWait::vfunc_2() {
    if (!(*(u8 *)&this->f_40)) {
        if ((*(float *)&this->f_38) >= this->f_34) {
            (*(u8 *)&this->f_40) = 1;
            if (!(*(Callback_e1930 * *)&this->f_3c))
                return;
            (*(Callback_e1930 * *)&this->f_3c)->b();
        }
        (*(float *)&this->f_38) += GetDelta();
    }
}

