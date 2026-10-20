#include "gen/global.h"

namespace math {
struct Vector_cfc00 {
    float x, y, z;
};
} // namespace math
class HUDOverlay_cfc00 {
  public:
    void Show(math::Vector_cfc00);
};
class Function_cfc00 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, math::Vector_cfc00*, int);
};
class Method1_cfc00 : public Function_cfc00 {
  public:
    char pad[0x18];
    void (HUDOverlay_cfc00::*method)(math::Vector_cfc00);
    HUDOverlay_cfc00* obj;
};

template <> void Closure1<HUDOverlay, void,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { math::Vector_cfc00 * v = (math::Vector_cfc00 *)__p1;

    ((*(HUDOverlay_cfc00 * *)&this->f_20)->*(*(void (HUDOverlay_cfc00::**)(math::Vector_cfc00))&this->f_1c))(*v);
}
