#include "compat/ptr.h"
extern "C" char DAT_00400c1c[];
typedef unsigned char u8_8ff70;
extern void thunk_FUN_00267090(void*);
class CStaticAllocator {
  public:
    virtual CStaticAllocator* vfunc_0(u8_8ff70);
    char pad[0x0c];
    void* p10;
    void* p14;
};
CStaticAllocator* CStaticAllocator::vfunc_0(u8_8ff70 param_2) {
    void* a = p14;
    *(void**)this = (void*)((hulk_intptr)DAT_00400c1c);
    thunk_FUN_00267090(a);
    thunk_FUN_00267090(p10);
    if (param_2 & 1)
        thunk_FUN_00267090(this);
    return this;
}