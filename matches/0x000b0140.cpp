#include "gen/global.h"

class CHapticControllerManager_b0140 {
  public:
    void Action(int, float, float, float);
};
class Function_b0140 {
  public:
    virtual void F0();
    virtual void F1();
};

template <> void Method4<CHapticControllerManager, void, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CHapticControllerManager_b0140 * obj = (CHapticControllerManager_b0140 *)__p0; void * args = (void *)__p1; void * unused = (void *)__p2;

    char* p = (char*)args;
    int a = *(int*)p;
    p += 4;
    float b = *(float*)p;
    p += 4;
    float c = *(float*)p;
    float d = *(float*)(p + 4);
    (obj->*(*(void (CHapticControllerManager_b0140::**)(int, float, float, float))&this->f_1c))(a, b, c, d);
}
