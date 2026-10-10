struct Mat {
    float v[16];
    void FUN_0022b980();
    void FUN_0022bc20(float, float, float);
    void FUN_0022ca90(const Mat*, const Mat*);
    void FUN_0022cc10(const Mat*, const Mat*);
    void FUN_0022c0b0();
    void FUN_0022cdb0();
    void FUN_0022c310(const float*, float*);
};
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(int, Mat*);
void __fastcall D3DDevice_SetVertexShaderConstant4(int, const Mat*);
void __fastcall D3DDevice_SetVertexShaderConstant1(int, const float*);
} // namespace D3D8
namespace pure3d {
struct d3dSpheremapVertexShader {
    char pad[0x8c];
    float x, y, z;
    void vfunc_24();
};
void d3dSpheremapVertexShader::vfunc_24() {
    Mat projection, view, world, base, combined, temp, light, normal, transposedLight, transposedCombined,
        transposedProjection, transposedBase;
    float in[4], out[4];
    D3D8::D3DDevice_GetTransform(6, &projection);
    D3D8::D3DDevice_GetTransform(0, &view);
    D3D8::D3DDevice_GetTransform(1, &world);
    base.FUN_0022b980();
    base.FUN_0022bc20(x, y, z);
    combined.FUN_0022ca90(&projection, &view);
    temp.FUN_0022cc10(&combined, &world);
    light = temp;
    light.FUN_0022c0b0();
    transposedCombined = combined;
    transposedCombined.FUN_0022c0b0();
    transposedProjection = projection;
    transposedProjection.FUN_0022c0b0();
    normal = combined;
    normal.FUN_0022cdb0();
    transposedBase = base;
    transposedBase.FUN_0022c0b0();
    in[0] = 0;
    in[1] = 0;
    in[2] = 0;
    in[3] = 1.0f;
    normal.FUN_0022c310(in, out);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x62, &light);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x66, &transposedCombined);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x77, &transposedProjection);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x7b, out);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x7c, &transposedBase);
}
} // namespace pure3d