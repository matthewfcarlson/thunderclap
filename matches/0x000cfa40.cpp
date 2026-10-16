#include "gen/global.h"

namespace math {
struct Vector_cfa40 {
    float x, y, z;
};
} // namespace math
class HUDOverlay_cfa40 {
  public:
    void Fn(const char*, float, float, math::Vector_cfa40);
};

template <> void Closure4<HUDOverlay, void, const char *, float, float,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * args = (void *)__p1; void * extra = (void *)__p2;

    char* p = (char*)args;
    const char* s = *(const char**)p;
    p += 4;
    float a = *(float*)p;
    p += 4;
    float b = *(float*)p;
    p += 4;
    math::Vector_cfa40 v = *(math::Vector_cfa40*)p;
    ((*(HUDOverlay_cfa40 * *)&this->f_20)->*(*(void (HUDOverlay_cfa40::**)(const char *, float, float, math::Vector_cfa40))&this->f_1c))(s, a, b, v);
}
