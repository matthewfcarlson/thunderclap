#include "gen/global.h"

class Child_e6280 {
  public:
    virtual int f0();
    virtual bool f1(int, int);
};

bool FEThingsBase::vfunc_0(int x, int index) {
    char* p = (char*)this;
    if (p[index + 0x2100])
        return true;
    if ((*(Child_e6280 * *)&this->f_2218))
        return (*(Child_e6280 * *)&this->f_2218)->f1(x, index);
    if ((*(Child_e6280 * *)&this->f_1760))
        return (*(Child_e6280 * *)&this->f_1760)->f1(x, index);
    if ((*(Child_e6280 * *)&this->f_175c))
        return (*(Child_e6280 * *)&this->f_175c)->f1(x, index);
    return false;
}
