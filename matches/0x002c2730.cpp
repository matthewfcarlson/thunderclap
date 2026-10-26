#include "compat/ptr.h"
#include "gen/pure3d.h"

class Part_2c2730 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
struct Geometry_nv_2c2730 {
    void helper(hulk_intptr, int);
};

void pure3d::Geometry::vfunc_8(hulk_intptr a, int b) {
    if ((*(Part_2c2730 * *)&this->f_60))
        (*(Part_2c2730 * *)&this->f_60)->f6(0, 1);
    if ((*(Part_2c2730 * *)&this->f_64))
        (*(Part_2c2730 * *)&this->f_64)->f6(0, 1);
    ((Geometry_nv_2c2730*)this)->helper(a, b);
}
