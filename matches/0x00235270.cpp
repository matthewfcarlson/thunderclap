// Same code shape as 0x002351a0 (propagated; names are from that function)
#include "compat/ptr.h"
class Helper_235270 {
  public:
    void Process(int);
};
class ParamValueConditionGroup_235270 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(int, int);
    virtual void f4();
    virtual void f5();
    virtual int Query(int);
    virtual void f7();
};
void ParamValueConditionGroup_235270::vfunc_3(int a, int b) {
    hulk_intptr x = Query(a);
    if (x)
        ((Helper_235270*)x)->Process(b);
}