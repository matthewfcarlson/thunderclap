#include "gen/global.h"

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
extern Pair_dd8d0 table_dd8d0[];

float ControllerState::vfunc_8(int i) {
    float* p = (*(float * *)&this->f_10);
    return p[table_dd8d0[i].a] - p[table_dd8d0[i].b];
}
