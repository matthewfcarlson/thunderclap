// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// om::MetaTypeAttrib<int>::vfunc_2 @ 0x0024d740
#include "compat/ptr.h"
void __cdecl FUN_0025ab50(int, int);
namespace om {
struct MetaTypeAttribBase {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, int);
    virtual void vfunc_3();
    char pad[0x10];
    int offset;
};
template<class T> struct MetaTypeAttrib : MetaTypeAttribBase {
    void vfunc_2(void *destination, int additionalOffset);
};
template<> void MetaTypeAttrib<int>::vfunc_2(void *destination, int additionalOffset) {
    FUN_0025ab50((hulk_intptr)destination, offset + additionalOffset);
}
}