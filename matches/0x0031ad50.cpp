#include "gen/pure3d.h"

class pddiObject_31ad50 {
  public:
    virtual int vfunc_0();
    virtual int vfunc_1();
    virtual int vfunc_2();
};
class pddiDisplay_31ad50 : public pddiObject_31ad50 {};

int pure3d::d3dDisplay::vfunc_8() {
    return *(int*)((char*)this + 0x480);
}
