#include "compat/ptr.h"
extern "C" int FUN_00344e74(void*, int, void*, hulk_intptr, int);
extern int DAT_0049850c;
extern int DAT_004a8d20;
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(int a);
    virtual int vfunc_1(int a);
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(int a);
};
int TrackFactoryCasterTemplate::vfunc_0(int a) {
    return (FUN_00344e74((void*)a, 0, &DAT_0049850c, (hulk_intptr)&DAT_004a8d20, 0) != 0);
}
