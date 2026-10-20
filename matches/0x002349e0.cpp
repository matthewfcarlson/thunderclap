#include "compat/ptr.h"
extern "C" char DAT_004279fc[];
extern "C" char DAT_00427a78[];
class Sub_2349e0 {
  public:
    void Init(const char*);
};
class ParamValueString {
  public:
    int vf;
    int pad;
    Sub_2349e0 sub;
    ParamValueString(const char*);
};
ParamValueString::ParamValueString(const char* s) {
    vf = ((hulk_intptr)DAT_004279fc);
    sub.Init(s);
    vf = ((hulk_intptr)DAT_00427a78);
}