#include "compat/ptr.h"
#include "gen/global.h"

class Obj_fce10 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
};
struct CControllerAgent_nv_fce10 {
    float helper(hulk_intptr, int);
};

hulk_freg CControllerAgent::vfunc_3(hulk_intptr a, int b) {
    ((CControllerAgent_nv_fce10*)this)->helper(a, b);
    hulk_intptr x = (*(Obj_fce10 * *)&this->f_58)->f6();
    if (*(int*)((char*)x + 0x20a8) >= 0)
        *(float*)((char*)this + 8) = 100.0f;
    else
        *(float*)((char*)this + 8) = 0.0f;
    return *(float*)((char*)this + 8);
}
