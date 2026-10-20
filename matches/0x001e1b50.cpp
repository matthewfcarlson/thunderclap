#include "gen/global.h"

class CSPManager_1e1b50 {
  public:
    void Fn(int, float, float, float);
};
class Function_1e1b50 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
};
class Method4_1e1b50 : public Function_1e1b50 {
  public:
    char pad[24];
    void (CSPManager_1e1b50::*fn)(int, float, float, float);
    CSPManager_1e1b50* obj;
};

template <> void Closure4<CSPManager, void, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int x = (int)__p0; const float * p = (const float *)__p1; int y = (int)__p2;

    const int* q = (const int*)p;
    int a = *q++;
    volatile int b = *q++;
    int d = q[1];
    int c = q[0];
    ((*(CSPManager_1e1b50 * *)&this->f_20)->*(*(void (CSPManager_1e1b50::**)(int, float, float, float))&this->f_1c))(a, *(float*)&b, *(float*)&c, *(float*)&d);
}
