#include "compat/ptr.h"
extern int gVtable;
class ParamValueBool_5b9f0 {
  public:
    virtual void V();
    ParamValueBool_5b9f0(int);
};
class ParamBool_5b9f0 : public ParamValueBool_5b9f0 {
  public:
    ParamBool_5b9f0(int a, int b);
    char pad[0xc];
    int m10;
};
ParamBool_5b9f0::ParamBool_5b9f0(int a, int b) : ParamValueBool_5b9f0(a) {
    *(hulk_intptr*)this = (hulk_intptr)&gVtable;
    m10 = b;
}
