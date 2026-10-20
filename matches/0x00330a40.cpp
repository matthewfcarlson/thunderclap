#include "gen/pure3d.h"

namespace D3D8 {
void __stdcall D3DDevice_GetTransform(unsigned int, float*);
void __fastcall D3DDevice_SetVertexShaderConstant4(unsigned int, const float*);
} // namespace D3D8
struct Matrix_330a40 {
    float v[16];
    void FUN_0022ca90(const Matrix_330a40*, const Matrix_330a40*);
    void FUN_0022cc10(const Matrix_330a40*, const Matrix_330a40*);
    void FUN_0022c0b0();
    void FUN_0022cdb0();
};
namespace pure3d {
} // namespace pure3d
void pure3d::d3dToonVertexShader::vfunc_24() {
    if ((*(unsigned char *)&this->f_7d))
        return;
    Matrix_330a40 projection, view, world, worldView, combined, invCombined, invWorldView, invProjection, adjusted;
    D3D8::D3DDevice_GetTransform(6, projection.v);
    D3D8::D3DDevice_GetTransform(0, view.v);
    D3D8::D3DDevice_GetTransform(1, world.v);
    worldView.FUN_0022ca90(&projection, &view);
    combined.FUN_0022cc10(&worldView, &world);
    invCombined = combined;
    invCombined.FUN_0022c0b0();
    invWorldView = worldView;
    invWorldView.FUN_0022c0b0();
    invProjection = projection;
    invProjection.FUN_0022c0b0();
    adjusted = projection;
    adjusted.FUN_0022cdb0();
    D3D8::D3DDevice_SetVertexShaderConstant4(0x62, invCombined.v);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x66, invProjection.v);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x75, invWorldView.v);
}
