#include "compat/ptr.h"
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(int);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(int);
};
} // namespace fight
extern int a, b;
extern "C" int __cdecl FUN_00344e74(hulk_intptr, int, int*, int*, int);
int fight::TrackFactoryCasterTemplate::vfunc_0(int x) {
    return FUN_00344e74(x, 0, &a, &b, 0) != 0;
}