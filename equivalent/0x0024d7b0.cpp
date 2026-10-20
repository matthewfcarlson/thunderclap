// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// om::MetaTypeAttrib<float>::vfunc_2 @ 0x0024d7b0
#include "compat/ptr.h"
namespace om {
struct MetaTypeAttribBase {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2(void* source, void* destination);
    virtual void vfunc_3();
    char reserved[0x10];
    char* data;
};
template <typename T> struct MetaTypeAttrib : MetaTypeAttribBase {
    virtual int vfunc_2(void* source, void* destination);
};
}
int __cdecl FUN_0025ac10(void*, void*);
template <> int om::MetaTypeAttrib<float>::vfunc_2(void* source, void* destination) {
    return FUN_0025ac10(source, data + (hulk_uintptr)destination);
}