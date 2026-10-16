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
