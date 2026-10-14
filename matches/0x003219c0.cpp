typedef unsigned int UINT;
extern void __stdcall D3DDevice_SetRenderState_CullMode(UINT mode);
struct Thing_3219c0 {
    char pad[0x4c];
    void* p;
};
extern UINT gValues_3219c0[];
void __fastcall FUN_003219c0(Thing_3219c0* self) {
    D3DDevice_SetRenderState_CullMode(gValues_3219c0[*((UINT*)((char*)self->p + 4))]);
}