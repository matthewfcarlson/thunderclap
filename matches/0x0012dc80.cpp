#include "compat/ptr.h"
extern "C" int FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(int);
    virtual void vfunc_1();
};
namespace fight {
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(int);
};
int TrackFactoryCasterTemplate::vfunc_0(int a) {
    int result = FUN_00344e74(a, 0, 0x49850c, 0x4a9b10, 0);
    return result != 0;
}
} // namespace fight
