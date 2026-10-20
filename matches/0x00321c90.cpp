#include "compat/ptr.h"
#include "gen/pure3d.h"

#include "decls/data/platform/xbox/pure3d.h"

typedef unsigned int u32_321c90;
struct d3dContext_nv_321c90 {
    void BaseVfunc76(u32_321c90);
};
extern void __stdcall D3DDevice_SetRenderState_FillMode(u32_321c90);

void pure3d::d3dContext::vfunc_76(unsigned long __p0) { hulk_uintptr x = (u32_321c90)__p0;

    ((d3dContext_nv_321c90*)(this))->BaseVfunc76(x);
    D3DDevice_SetRenderState_FillMode(*(u32_321c90*)(((hulk_intptr)((char*)&DAT_004d3a8c)) + x * 4));
}
