typedef unsigned int u32;
void __stdcall BaseVfunc76(u32);
extern void D3DDevice_SetRenderState_FillMode(u32);
void stub_vfunc_76(u32 x) {
    BaseVfunc76(x);
    D3DDevice_SetRenderState_FillMode(*(u32*)(0x4d3a8c + x * 4));
}
