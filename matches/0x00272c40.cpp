// Same code shape as 0x00049c80 (propagated; names are from that function)
#include "gen/core.h"

namespace fight {
class Condition_272c40 {
  public:
    virtual int vfunc_3();
};
class Param_272c40 {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
} // namespace fight
class Drive_272c40 : public ::core::IRefCount, public fight::Condition_272c40, public fight::Param_272c40 {
  public:
    virtual int vfunc_0(int);
};
int Drive_272c40::vfunc_0(int) {
    return 0;
}
