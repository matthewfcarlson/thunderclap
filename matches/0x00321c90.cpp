#include "decls/data/platform/xbox/pure3d.h"

typedef unsigned int u32_321c90;
struct ThisWrap_00321c90 {
    void BaseVfunc76(u32_321c90);
    void stub_vfunc_76(u32_321c90 x);
};
extern void __stdcall D3DDevice_SetRenderState_FillMode(u32_321c90);
void ThisWrap_00321c90::stub_vfunc_76(u32_321c90 x) {
    this->BaseVfunc76(x);
    D3DDevice_SetRenderState_FillMode(*(u32_321c90*)(((int)((char*)&DAT_004d3a8c)) + x * 4));
}
