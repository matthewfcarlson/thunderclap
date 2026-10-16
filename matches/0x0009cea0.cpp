#include "gen/global.h"

class Vector_9cea0 {
  public:
    float x, y, z;
};
class CCameraManager_9cea0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c(Vector_9cea0, unsigned char);
};

template <> void Closure2<CCameraManager, void,math::Vector, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Vector_9cea0 * p = (Vector_9cea0 *)__p1;

    ((*(CCameraManager_9cea0 * *)&this->f_20)->*(*(void (CCameraManager_9cea0::**)(Vector_9cea0, unsigned char))&this->f_1c))(*p, *((unsigned char*)p + 12));
}
