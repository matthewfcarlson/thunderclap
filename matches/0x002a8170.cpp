#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
extern int vt1_2a8170;
extern void Free(void*);
extern void Free2(void*);
class Root_2a8170 {
  public:
    void* vptr;
    void Fini();
};
class D : public Root_2a8170 {
  public:
    char p[0x3c];
    int a40;
    hulk_intptr a44;
    char q[8];
    void* a50;
    D* vfunc2(unsigned char f);
};
D* D::vfunc2(unsigned char f) {
    vptr = &vt1_2a8170;
    a40 = 0;
    _ReadWriteBarrier();
    if (a50)
        Free(a50);
    if (a44)
        Free((void*)a44);
    Fini();
    if (f & 1)
        Free2(this);
    return this;
}
