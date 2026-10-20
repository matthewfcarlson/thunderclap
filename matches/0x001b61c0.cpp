#include "gen/global.h"

class CCollisionManager_1b61c0 {
  public:
    void Method(float, float, float);
};

template <> void Closure3<CCollisionManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { float * p = (float *)__p1;

    float* q = p;
    *(volatile int*)&p = *(int*)q;
    ((*(CCollisionManager_1b61c0 * *)&this->f_20)->*(*(void (CCollisionManager_1b61c0::**)(float, float, float))&this->f_1c))(*(float*)&p, q[1], q[2]);
}
