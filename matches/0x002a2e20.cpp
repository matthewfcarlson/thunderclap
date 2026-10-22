#include "gen/pure3d.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a2e20[];
struct OpaqueTraversal_nv_2a2e20 {
    void Fn();
};
class OpaqueTraversal_2a2e20 {
  public:
    void* vptr;
    char p4[0x1c];
    void* m20;
    char p24[8];
    void* m2c;
    OpaqueTraversal_2a2e20* f2(unsigned char flags);
};
void operator delete(void*);
void operator delete[](void*);
OpaqueTraversal_2a2e20* OpaqueTraversal_2a2e20::f2(unsigned char flags) {
    vptr = g_vftable_2a2e20;
    _ReadWriteBarrier();
    if (m2c)
        operator delete[](m2c);
    if (m20)
        operator delete[](m20);
    ((OpaqueTraversal_nv_2a2e20*)(((pure3d::OpaqueTraversal*)this)))->Fn();
    if (flags & 1)
        operator delete(this);
    return this;
}
