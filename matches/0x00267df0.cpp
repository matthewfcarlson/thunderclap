#include "compat/ptr.h"
namespace core {
class Timer {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual hulk_freg vfunc_13();
    int a[2];
    unsigned int denominator;
    int b;
    unsigned int numerator;
};
hulk_freg Timer::vfunc_13() {
    return (float)numerator / (float)denominator;
}
} // namespace core