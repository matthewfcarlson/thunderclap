#include "gen/global.h"

namespace math {
struct Vector_ced10 {
    float x, y, z;
};
} // namespace math
class HUDOverlay_ced10 {
  public:
    void Action(math::Vector_ced10);
};
class Function_ced10 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<HUDOverlay, void,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_ced10 * o = (HUDOverlay_ced10 *)__p0; math::Vector_ced10 * v = (math::Vector_ced10 *)__p1;

    (o->*(*(void (HUDOverlay_ced10::**)(math::Vector_ced10))&this->f_1c))(*v);
}
