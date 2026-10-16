#include "gen/pure3d.h"

struct Vec4_32e400 {
    float x, y, z, w;
};
struct Matrix_32e400 {
    float m[16];
    void FUN_0022ca90(const Matrix_32e400* a, const Matrix_32e400* b);
    void FUN_0022cc10(const Matrix_32e400* a, const Matrix_32e400* b);
    void FUN_0022c0b0();
};
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(int type, Matrix_32e400* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(int reg, const void* data);
} // namespace D3D8
struct Frame_32e400 {
    Vec4_32e400 consts;
    Matrix_32e400 worldViewT;
    Matrix_32e400 viewT;
    Matrix_32e400 view;
    Matrix_32e400 world;
    Matrix_32e400 worldView;
    Matrix_32e400 proj;
    Matrix_32e400 worldViewProj;
};
namespace pure3d {
struct d3dLayeredShader_nv_32e400 {
    void FUN_0032db00();
    void FUN_0032e0e0();
};

} // namespace pure3d
void pure3d::d3dLayeredShader::vfunc_24() {
    Frame_32e400 F;
    F.consts.x = 0.0f;
    F.consts.y = 0.5f;
    F.consts.z = 1.0f;
    F.consts.w = 1000.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, &F.consts);
    D3D8::D3DDevice_GetTransform(6, &F.view);
    D3D8::D3DDevice_GetTransform(0, &F.world);
    D3D8::D3DDevice_GetTransform(1, &F.proj);
    F.worldView.FUN_0022ca90(&F.view, &F.world);
    F.worldViewProj.FUN_0022cc10(&F.worldView, &F.proj);
    F.worldViewT = F.worldViewProj;
    F.worldViewT.FUN_0022c0b0();
    F.viewT = F.view;
    F.viewT.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6a, &F.viewT);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6e, &F.worldViewT);
    ((d3dLayeredShader_nv_32e400*)this)->FUN_0032db00();
    ((d3dLayeredShader_nv_32e400*)this)->FUN_0032e0e0();
}
