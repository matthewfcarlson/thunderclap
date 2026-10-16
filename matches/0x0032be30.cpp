#include "gen/pure3d.h"

struct Vec4_32be30 {
    float x, y, z, w;
};
struct Matrix_32be30 {
    float m[16];
    void FUN_0022ca90(Matrix_32be30*, Matrix_32be30*);
    void FUN_0022cc10(Matrix_32be30*, Matrix_32be30*);
    void FUN_0022c0b0();
};
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(unsigned long type, Matrix_32be30* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(int reg, const void* data);
} // namespace D3D8
namespace pure3d {
struct d3dLightMapShader_nv_32be30 {
    void FUN_0032b990();
    void FUN_0032bb10();
};
} // namespace pure3d
void pure3d::d3dLightMapShader::vfunc_24() {
    Vec4_32be30 consts;
    Matrix_32be30 m6, m0, m1, prod, full, a, b;
    consts.x = 0.0f;
    consts.y = 0.5f;
    consts.z = 1.0f;
    consts.w = 1000.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, &consts);
    D3D8::D3DDevice_GetTransform(6, &m6);
    D3D8::D3DDevice_GetTransform(0, &m0);
    D3D8::D3DDevice_GetTransform(1, &m1);
    prod.FUN_0022ca90(&m6, &m0);
    full.FUN_0022cc10(&prod, &m1);
    a = full;
    a.FUN_0022c0b0();
    b = m6;
    b.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6a, &b);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6e, &a);
    ((d3dLightMapShader_nv_32be30*)this)->FUN_0032b990();
    ((d3dLightMapShader_nv_32be30*)this)->FUN_0032bb10();
}
