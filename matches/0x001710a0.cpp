#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

class A_1710a0 {
  public:
};
class B_1710a0 {
  public:
    void* g();
};
class C_1710a0 {
  public:
};

bool hulkfight::motion::MotionStateAction::vfunc_5(hulk_intptr param_2, int unused) {
    if (param_2 == 0) {
        void* a = ((void *)((owners::Object_592a0 *)((*(A_1710a0 * *)&this->f_20)))->FUN_000592a0());
        void* b = ((B_1710a0*)a)->g();
        ((owners::C_359c0 *)(((C_1710a0*)b)))->FUN_000359c0(*(int*)((char*)(*(void * *)&this->f_1c) + 0x14));
    }
    return true;
}
