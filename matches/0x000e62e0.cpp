#include "gen/global.h"

class Obj_e62e0 {
  public:
    virtual void f0();
    virtual bool f1(int, int);
    virtual bool f2(int, int);
};

bool FEThingsBase::vfunc_1(int a, int index) {
    if (*((unsigned char*)this + index + 0x2100))
        return true;
    if ((*(Obj_e62e0 * *)&this->f_2218))
        return (*(Obj_e62e0 * *)&this->f_2218)->f2(a, index);
    if ((*(Obj_e62e0 * *)&this->f_1760))
        return (*(Obj_e62e0 * *)&this->f_1760)->f2(a, index);
    if ((*(Obj_e62e0 * *)&this->f_175c))
        return (*(Obj_e62e0 * *)&this->f_175c)->f2(a, index);
    return false;
}
