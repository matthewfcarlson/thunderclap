// Same code shape as 0x00018b30 (propagated; names are from that function)
#include "gen/pure3d.h"

class IRefCount_31baf0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};

void pure3d::pddiObject::vfunc_0() {
    ++this->f_04;
}
