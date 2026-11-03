#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

class A_115ed0 {
  public:
};
class B_115ed0 {
  public:
    void* g();
};

bool hulkfight::ai::MotionBoostAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if (!(*(void * *)&this->f_20))
        return false;
    void* x = ((void *)((owners::Object_592a0 *)(((A_115ed0*)(*(void * *)&this->f_20))))->FUN_000592a0());
    x = ((B_115ed0*)x)->g();
    ((owners::C_35460 *)(((B_115ed0*)x)))->FUN_00035460((unsigned *)((char*)this + 0x28));
    return true;
}
