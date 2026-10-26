#include "decls/data/platform/xbox/pure3d.h"
// data: gValues_3219c0 = DAT_004d3a48

typedef unsigned int UINT;
extern void __stdcall D3DDevice_SetRenderState_CullMode(UINT mode);
struct Thing_3219c0 {
    char pad[0x4c];
    void* p;
};
void __fastcall FUN_003219c0(Thing_3219c0* self) {
    D3DDevice_SetRenderState_CullMode(((UINT*)&DAT_004d3a48)[*((UINT*)((char*)self->p + 4))]);
}