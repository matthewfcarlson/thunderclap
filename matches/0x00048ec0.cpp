#include "gen/global.h"

class Result_48ec0 {
    char pad[0x24];

  public:
    unsigned char value;
};
class Input_48ec0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Result_48ec0* f3();
};

bool CCollisionInterruptCondition::vfunc_7(void* __p0) { Input_48ec0 * param = (Input_48ec0 *)__p0;

    Result_48ec0* result = param->f3();
    if (!result)
        return false;
    return result->value == this->f_0c;
}
