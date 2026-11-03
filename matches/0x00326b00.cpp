#include "gen/owners.h"
typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetPalette(DWORD, DWORD);
void __stdcall D3DDevice_SetTexture(DWORD, DWORD);
} // namespace D3D8
void owners::Obj_326b00::FUN_00326b00(DWORD stage) {
    D3D8::D3DDevice_SetPalette(stage, palette);
    DWORD texture = texB;
    if (texture == 0)
        texture = texC;
    if (texture != 0)
        D3D8::D3DDevice_SetTexture(stage, texture);
    else if (texA != 0)
        D3D8::D3DDevice_SetTexture(stage, texA);
}