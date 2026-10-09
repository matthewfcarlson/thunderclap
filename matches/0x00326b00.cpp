typedef unsigned long DWORD;
namespace D3D8 { void __stdcall D3DDevice_SetPalette(DWORD, DWORD); void __stdcall D3DDevice_SetTexture(DWORD, DWORD); }
class Obj { public: char pad[0x10]; DWORD texA; DWORD texB; DWORD texC; char pad2[0x4c]; DWORD palette; void Apply(DWORD); };
void Obj::Apply(DWORD stage) {
    D3D8::D3DDevice_SetPalette(stage, palette);
    DWORD texture = texB;
    if (texture == 0) texture = texC;
    if (texture != 0) D3D8::D3DDevice_SetTexture(stage, texture);
    else if (texA != 0) D3D8::D3DDevice_SetTexture(stage, texA);
}