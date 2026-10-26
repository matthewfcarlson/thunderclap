#include "gen/global.h"
#include "decls/data/game/global.h"

class IDollyControllerState_dd8d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual float vfunc_8(int);
    virtual void f9();
    virtual void f10();
    virtual void f11();
};
struct Pair_dd8d0 {
    int a, b;
};

hulk_freg ControllerState::vfunc_8(int i) {
    float* p = (*(float * *)&this->f_10);
    return p[((Pair_dd8d0*)&DAT_004a0d6c)[i].a] - p[((Pair_dd8d0*)&DAT_004a0d6c)[i].b];
}
