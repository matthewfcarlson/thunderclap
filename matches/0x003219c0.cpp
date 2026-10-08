typedef unsigned int UINT;
extern void __stdcall D3DDevice_SetRenderState_CullMode(UINT mode);
struct Thing { char pad[0x4c]; void* p; };
extern UINT gValues[];
void __fastcall FUN_003219c0(Thing* self) { D3DDevice_SetRenderState_CullMode(gValues[*((UINT*)((char*)self->p + 4))]); }