#include "compat/ptr.h"
typedef unsigned char u8_2b5560;
typedef unsigned int u32_2b5560;
extern int shadow_vtable;
extern int ref_vtable;
void release(void*);
void release_self(void*);
class ShadowSkinTopology {
  public:
    virtual void v0();
    virtual void v1();
    virtual ShadowSkinTopology* vfunc_2(u8_2b5560);
    u32_2b5560 a;
    hulk_uintptr b;
    hulk_uintptr c;
    hulk_uintptr d;
};
ShadowSkinTopology* ShadowSkinTopology::vfunc_2(u8_2b5560 param) {
    *(int**)this = &shadow_vtable;
    release((void*)b);
    release((void*)c);
    release((void*)d);
    *(int**)this = &ref_vtable;
    if (param & 1)
        release_self((void*)this);
    return this;
}
