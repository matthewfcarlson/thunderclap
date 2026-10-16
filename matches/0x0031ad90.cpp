#include "gen/pure3d.h"

class PddiObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

unsigned char pure3d::d3dDisplay::vfunc_10() {
    return (*(char (*)[1080])&this->f_04)[0x433];
}
