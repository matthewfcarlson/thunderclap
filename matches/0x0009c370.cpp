#include "compat/ptr.h"
#include "gen/global.h"

namespace math {
struct Vector_9c370 {
    float x, y, z;
};
} // namespace math
class CCameraManager_9c370 {
  public:
    void fn(float, float, math::Vector_9c370, float);
};

template <> void Closure4<CCameraManager, void, float, float,math::Vector, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; float * p = (float *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    float a = *p++;
    float b = *p++;
    math::Vector_9c370 v = *(math::Vector_9c370*)p;
    p += 3;
    float c = *p;
    ((*(CCameraManager_9c370 * *)&this->f_20)->*(*(void (CCameraManager_9c370::**)(float, float, math::Vector_9c370, float))&this->f_1c))(a, b, v, c);
}
