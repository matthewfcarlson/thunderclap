// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 30/30)
// pure3d::MultiController::vfunc_20 @ 0x002b1c40
#include "compat/ptr.h"
#include "gen/pure3d.h"

struct Controller_2b1c40 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual int v19();
};

hulk_freg pure3d::MultiController::vfunc_20() {
    float a = this->f_28 * this->f_1c;
    double endp = this->f_2c * this->f_1c; // unrounded for dur, a rounded frame copy (end) for the later uses
    volatile float end = endp;
    float dur = endp - a;

    switch (this->f_3c) {
    case 0: {
        for (unsigned i = 0; i < (*(unsigned int *)&this->f_44); i++) {
            if (!(*(Controller_2b1c40 ** *)&this->f_48)[i]->v19())
                return 3.4028235e+38f;
        }
        return dur;
    }
    case 2:
        if ((*(unsigned int *)&this->f_38) == 0)
            return 3.4028235e+38f;
        return (float)(*(unsigned int *)&this->f_38) * dur - (this->f_24 - a);
    case 3:
        if ((*(unsigned int *)&this->f_38) == 0)
            return 3.4028235e+38f;
        return (float)(*(unsigned int *)&this->f_38) * dur - (end - this->f_24);
    case 4:
        if ((*(unsigned int *)&this->f_38) == 0)
            return 3.4028235e+38f;
        {
            double v = (float)(*(unsigned int *)&this->f_38) * dur;
            return (v + v) - (this->f_24 - a);
        }
    case 5:
        if ((*(unsigned int *)&this->f_38) == 0)
            return 3.4028235e+38f;
        {
            double v = (float)(*(unsigned int *)&this->f_38) * dur;
            return (v + v) - (end - this->f_24);
        }
    default:
        return 0.0f;
    }
}
