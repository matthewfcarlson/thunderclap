#include "gen/global.h"

class Other_e6340 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2x();
    virtual bool f3(int, int);
};

bool FEThingsBase::vfunc_2(int x, int index) {
    if (*((char*)this + 0x2100 + index))
        return true;
    if ((*(Other_e6340 * *)&this->f_2218))
        return (*(Other_e6340 * *)&this->f_2218)->f3(x, index);
    if ((*(Other_e6340 * *)&this->f_1760))
        return (*(Other_e6340 * *)&this->f_1760)->f3(x, index);
    if ((*(Other_e6340 * *)&this->f_175c))
        return (*(Other_e6340 * *)&this->f_175c)->f3(x, index);
    return false;
}
