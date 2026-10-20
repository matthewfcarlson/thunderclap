#include "compat/ptr.h"
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
extern const int TranslucentTraversal_vftable;

namespace pure3d {

class TranslucentTraversal {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();

    void BaseDtor();

    char pad0[0x1c - 4];
    void* m1c;
    char pad1[8];
    void* m28;
};

void* TranslucentTraversal::vfunc_2(unsigned char param) {
    volatile int* v = (volatile int*)this;
    *v = (hulk_intptr)&TranslucentTraversal_vftable;
    void* p28 = (void*)*(volatile hulk_intptr*)((char*)v + 0x28);
    if (p28 != 0) {
        operator delete[](p28);
    }
    void* p1c = (void*)*(volatile hulk_intptr*)((char*)v + 0x1c);
    if (p1c != 0) {
        operator delete[](p1c);
    }
    BaseDtor();
    if ((param & 1) != 0) {
        operator delete(this);
    }
    return this;
}

} // namespace pure3d
