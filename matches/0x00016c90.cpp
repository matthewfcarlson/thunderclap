#include "gen/global.h"

class Aux_16c90 {
  public:
    void helper(int);
};
struct CEffectAction_nv_16c90 {
    Aux_16c90* helper1();
};

void CEffectAction::vfunc_4() {
    Aux_16c90* p = ((CEffectAction_nv_16c90*)this)->helper1();
    if (*((char*)(*(void * *)&this->f_20) + 0x50))
        p->helper(this->f_28);
}
