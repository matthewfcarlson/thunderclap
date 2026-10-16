#include "gen/core.h"

extern "C" double __cdecl fabs(double);
class Callback_268f00 {
  public:
    virtual void Call(int, float);
};
extern float __stdcall Convert(int);

void core::ControllerInputPointXBox::vfunc_14(int a, int b) {
    float value = Convert(b);
    if (value == this->f_08 || !((float)fabs(value - this->f_08) >= this->f_14))
        this->f_18 = a - this->f_1c;
    else {
        this->f_08 = value;
        this->f_1c = a;
        this->f_18 = 0;
        if ((*(Callback_268f00 * *)&this->f_2c))
            (*(Callback_268f00 * *)&this->f_2c)->Call(this->f_30, (this->f_10 - this->f_0c) * value + this->f_0c);
    }
}
