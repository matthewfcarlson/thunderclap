#include "gen/hulkfight.h"

class A_1710a0 {
  public:
    void* f();
};
class B_1710a0 {
  public:
    void* g();
};
class C_1710a0 {
  public:
    void h(int);
};

bool hulkfight::motion::MotionStateAction::vfunc_5(int param_2, int unused) {
    if (param_2 == 0) {
        void* a = (*(A_1710a0 * *)&this->f_20)->f();
        void* b = ((B_1710a0*)a)->g();
        ((C_1710a0*)b)->h(*(int*)((char*)(*(void * *)&this->f_1c) + 0x14));
    }
    return true;
}
