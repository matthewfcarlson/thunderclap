#include "gen/global.h"

class CCameraManager_9cbd0 {
  public:
    void Action(int, float, float, float);
};

template <> void Closure4<CCameraManager, void, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * p = (int *)__p1;

    int a = *p++;
    float b = *(float*)p++;
    float c = *(float*)p++;
    float d = *(float*)p++;
    ((*(CCameraManager_9cbd0 * *)&this->f_20)->*(*(void (CCameraManager_9cbd0::**)(int, float, float, float))&this->f_1c))(a, b, c, d);
}
