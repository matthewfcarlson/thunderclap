// Same code shape as 0x000dd8d0 (propagated; names are from that function)
#include "gen/global.h"

class IDollyControllerState_dd920 {
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
struct Pair_dd920 {
    int a, b;
};
extern Pair_dd920 table_dd920[];

hulk_freg ControllerState::vfunc_11(int i) {
    float* p = (*(float * *)&this->f_10);
    return p[table_dd920[i].a] - p[table_dd920[i].b];
}
