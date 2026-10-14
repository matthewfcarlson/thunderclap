extern "C" char DAT_004d3a8c[];
typedef unsigned int u32_321c90;
void __stdcall BaseVfunc76(u32_321c90);
extern void D3DDevice_SetRenderState_FillMode(u32_321c90);
void stub_vfunc_76(u32_321c90 x) {
    BaseVfunc76(x);
    D3DDevice_SetRenderState_FillMode(*(u32_321c90*)(((int)DAT_004d3a8c) + x * 4));
}
