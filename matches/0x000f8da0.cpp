#include "gen/global.h"

struct Callback_f8da0 {
    virtual void changed(float);
};

void NamedValueFloat::vfunc_1() {
    float v = this->f_44;
    this->f_40 = v;
    if ((*(void * *)&this->f_48))
        ((Callback_f8da0*)(*(void * *)&this->f_48))->changed(v);
    vfunc_0();
}
