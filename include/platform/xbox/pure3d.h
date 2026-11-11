// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_PLATFORM_XBOX_PURE3D_H
#define TREE_PLATFORM_XBOX_PURE3D_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "compat/ptr.h"
#include "common.h"
TREE_TU_BEGIN
namespace D3D8 {
hulk_intptr __stdcall D3DDevice_GetBackBuffer2(int);
}
namespace D3D8 {
void __stdcall D3DResource_Release(hulk_intptr);
}
extern "C" void __cdecl FUN_0031c230(int);
typedef unsigned long DWORD;
struct Color4 {
    float r, g, b, a;
};
namespace D3D8 {
void __stdcall D3DResource_Release(void*);
}
namespace D3D8 {
void __stdcall D3DDevice_SetTexture(int, int);
}
namespace D3D8 {
void __stdcall D3DDevice_SetPalette(DWORD, DWORD);
}
namespace D3D8 {
void __stdcall D3DDevice_SetTexture(DWORD, DWORD);
}
struct CullState {
    void FUN_003219c0();
};
extern void __stdcall D3DDevice_SetRenderState_TwoSidedLighting(unsigned int on);
extern unsigned int DAT_0039dea8;
extern unsigned int DAT_0039deac;
class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstant1(unsigned int index, const float *values);
}
namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
}
struct LightMgr {
    void FUN_00321dc0(int* out, int count);
};
extern void thunk_FUN_00267090(void*);
namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstant4(int reg, const void* data);
}
namespace D3D8 {
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(int stage, int value);
}
struct TexSlot {
    unsigned int v0, v4, v8;
    char pad0c[0x54 - 0xc];
    unsigned int v54;
    char pad58[0x80 - 0x58];
};
namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_TextureFactor(unsigned int);
}
namespace D3D8 {
void __fastcall D3DDevice_SetRenderState_Simple(unsigned int state, unsigned int value);
}
extern unsigned int DAT_0039db60;
extern unsigned int DAT_0039dc4c;
extern unsigned int DAT_0039de18;
class Item {
  public:
    virtual void AddRef();
    virtual void Release();
};
namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstant1(int,const float*);
}
TREE_TU_END
#endif
