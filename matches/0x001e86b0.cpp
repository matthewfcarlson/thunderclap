// Same code shape as 0x00018b30 (propagated; names are from that function)
#include "gen/global.h"

class IRefCount_1e86b0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};

void CSoundMix::vfunc_0() {
    ++this->f_04;
}
