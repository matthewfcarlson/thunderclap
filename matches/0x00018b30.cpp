#include "gen/pure3d.h"

class IRefCount_18b30 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};

void pure3d::NonCopyable::vfunc_0() {
    ++this->f_04;
}
