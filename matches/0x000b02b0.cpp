#include "gen/global.h"

class CHapticControllerManager_b02b0 {
  public:
    void Run(int, float, float, float);
};
class Function_b02b0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, int*, void*);
};

template <> void Closure4<CHapticControllerManager, void, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * args = (int *)__p1;

    int a = *args;
    float b = *(float*)++args;
    args++;
    float c = *(float*)args;
    float d = *(float*)(args + 1);
    ((*(CHapticControllerManager_b02b0 * *)&this->f_20)->*(*(void (CHapticControllerManager_b02b0::**)(int, float, float, float))&this->f_1c))(a, b, c, d);
}
