#include "compat/ptr.h"
extern "C" char DAT_004279fc[];
class Inner_235330 {
  public:
    void Init();
};
class ParamValue {
  public:
    virtual ParamValue* f0(int);
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[4];
    Inner_235330 inner;
};
class ParamValueInt : public ParamValue {
  public:
    virtual ParamValueInt* f0(int);
};
extern void Cleanup(ParamValueInt*);
ParamValueInt* ParamValueInt::f0(int flags) {
    int* q = (int*)this;
    *(hulk_intptr*)q = ((hulk_intptr)DAT_004279fc);
    inner.Init();
    if (flags & 1)
        Cleanup(this);
    return this;
}