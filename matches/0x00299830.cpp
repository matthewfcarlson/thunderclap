#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_299830[];
extern void* g_base_vftable[];
void operator delete(void*);
void operator delete[](void*);
class Ref_299830 {
  public:
    virtual void F0();
    virtual void Release();
};
class ActiveControllerList_299830 {
  public:
    void* vptr;
    char pad[8];
    void* mc;
    char pad2[8];
    void* m18;
    char pad3[8];
    Ref_299830** m24;
    Ref_299830** m28;
    ~ActiveControllerList_299830();
};
ActiveControllerList_299830::~ActiveControllerList_299830() {
    vptr = g_vftable_299830;
    _ReadWriteBarrier();
    hulk_uintptr n = m28 - m24;
    for (unsigned i = 0; i < n; i++) {
        Ref_299830** p = &m24[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (m24)
        operator delete[](m24);
    if (m18)
        operator delete[](m18);
    if (mc)
        operator delete[](mc);
    vptr = g_base_vftable;
}
