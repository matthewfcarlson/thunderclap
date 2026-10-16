// Same code shape as 0x00018b30 (propagated; names are from that function)
#include "gen/content.h"

class IRefCount_38290 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};

void content::LoadObject::vfunc_0() {
    ++this->f_04;
}
