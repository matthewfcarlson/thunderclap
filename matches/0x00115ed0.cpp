#include "compat/ptr.h"
#include "gen/hulkfight.h"

class A_115ed0 {
  public:
    void* f();
};
class B_115ed0 {
  public:
    void* g();
    void h(void*);
};

bool hulkfight::ai::MotionBoostAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if (!(*(void * *)&this->f_20))
        return false;
    void* x = ((A_115ed0*)(*(void * *)&this->f_20))->f();
    x = ((B_115ed0*)x)->g();
    ((B_115ed0*)x)->h((char*)this + 0x28);
    return true;
}
