#include "compat/ptr.h"
class Helper_2351a0 {
  public:
    void Process(int);
};
namespace fight { class ParamValueBranch {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(int, int);
    virtual void f4();
    virtual void f5();
    virtual int Query(int);
    virtual void f7();
}; }
void fight::ParamValueBranch::vfunc_3(int a, int b) {
    hulk_intptr x = Query(a);
    if (x)
        ((Helper_2351a0*)x)->Process(b);
}