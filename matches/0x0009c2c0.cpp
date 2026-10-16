#include "gen/global.h"

class CCameraManager_9c2c0 {
  public:
    void Fn(float, float, float, float, float, float);
};
class Function_9c2c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};

template <> void Closure6<CCameraManager, void, float, float, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { float * p = (float *)__p1;

    volatile float* q = p;
    float a = *q++;
    float b = *q++;
    float c = *q++;
    float d = *q++;
    float e = ((float*)q)[0], f = ((float*)q)[1];
    ((*(CCameraManager_9c2c0 * *)&this->f_20)->*(*(void (CCameraManager_9c2c0::**)(float, float, float, float, float, float))&this->f_1c))(a, b, c, d, e, f);
}
