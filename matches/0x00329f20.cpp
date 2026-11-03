#include "gen/owners.h"
typedef unsigned int u32_329f20;
namespace D3D8 {
    void __stdcall D3DDevice_SetRenderState_TextureFactor(u32_329f20);
}
void owners::Device_329f20::FUN_00329f20(u32_329f20 value) {
    if (value != textureFactor) {
        textureFactor = value;
        D3D8::D3DDevice_SetRenderState_TextureFactor(value);
    }
}
