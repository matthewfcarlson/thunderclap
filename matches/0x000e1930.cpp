#include "gen/global.h"

typedef unsigned char u8;
class Callback_e1930 {
  public:
    virtual void a();
    virtual void b();
};
extern "C" float(__cdecl* GetDelta)();
class FEDoAction_e1930 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

void FEDoWait::vfunc_2() {
    if (!(*(u8 *)&this->f_40)) {
        if ((*(float *)&this->f_38) >= this->f_34) {
            (*(u8 *)&this->f_40) = 1;
            if (!(*(Callback_e1930 * *)&this->f_3c))
                return;
            (*(Callback_e1930 * *)&this->f_3c)->b();
        }
        (*(float *)&this->f_38) += GetDelta();
    }
}
