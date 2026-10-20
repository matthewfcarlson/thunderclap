#include "compat/ptr.h"
class Function {
  public:
    char pad[0x18];
    void(__cdecl* mFn)(const char*, const char*, float);
};
class Function3 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, void*, int);
};
void Function3::vfunc_2(int, void* arg, int) {
    volatile unsigned long* p = (volatile unsigned long*)arg;
    hulk_ulongptr a = p[0];
    unsigned long c = p[2];
    hulk_ulongptr b = p[1];
    mFn((const char*)a, (const char*)b, *(float*)&c);
}