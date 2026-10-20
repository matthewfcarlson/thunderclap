// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 14/14)
// pure3d::d3dSpheremapVertexShader::vfunc_12 @ 0x00331cd0
// pure3d::d3dSpheremapVertexShader::vfunc_12 @ 0x00331cd0
#include "gen/pure3d.h"

namespace pure3d {
struct Vec4_331cd0 {
    float x;
    float y;
    float z;
    union {
        float w;
        unsigned int wBits;
    };
};
// equiv-conv: FUN_00331620 ecx stack
void FUN_00331620(Vec4_331cd0* self, unsigned int packed);
struct ShaderColors {
    unsigned int c0;
    unsigned int c1;
    unsigned int c2;
    unsigned int c3;
    unsigned int extra;
};
struct Light_331cd0 {
    int type;
    Vec4_331cd0 diffuse;
    Vec4_331cd0 specular;
    Vec4_331cd0 ambient;
    float position[3];
    Vec4_331cd0 directionRange;
    float falloff;
    float attenuation[3];
    float theta;
    float phi;
};
class LightManager_331cd0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual unsigned int* v36(unsigned int* out);
    void FUN_00321dc0(int* ids, int key);
};
}
namespace D3D8 {
void __stdcall D3DDevice_GetLight(int index, pure3d::Light_331cd0* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const pure3d::Vec4_331cd0* data);
}
void pure3d::d3dSpheremapVertexShader::vfunc_12() {
    int ids[4];
    Vec4_331cd0 constA, constB, zero, out1, out2, out3, out4, out5;
    ShaderColors colors;
    unsigned int scratch;
    Light_331cd0 light0, light1, light2;

    constA.x = 0.0f;
    constA.y = 1.0f;
    constA.z = 0.5f;
    constA.w = 2.0f;
    constB.x = 0.0f;
    constB.y = 0.0f;
    constB.z = 1.0f;
    constB.w = 0.0f;
    (*(LightManager_331cd0 * *)&this->f_10)->FUN_00321dc0(ids, 0);
    D3D8::D3DDevice_GetLight(ids[0] == -1 ? 0 : ids[0], &light0);
    D3D8::D3DDevice_GetLight(ids[1] == -1 ? 0 : ids[1], &light1);
    D3D8::D3DDevice_GetLight(ids[2] == -1 ? 0 : ids[2], &light2);
    vfunc_21(&colors);
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    zero.w = 0.0f;
    FUN_00331620(&out1, colors.c1);
    FUN_00331620(&out2, colors.c0);
    FUN_00331620(&out3, colors.c3);
    FUN_00331620(&out4, colors.c2);
    FUN_00331620(&out5, *(*(LightManager_331cd0 * *)&this->f_10)->v36(&scratch));
    if (out3.w == 0.0f) {
        out3.wBits = out2.wBits;
        out2.wBits = 0;
    }
    out1.wBits = colors.extra;
    out3.x = out5.x * out4.x + out3.x;
    out3.y = out5.y * out4.y + out3.y;
    out3.z = out5.z * out4.z + out3.z;
    out3.w = out5.w * out4.w + out3.w;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, &constA);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x61, &constB);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6e, &out2);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6f, &out1);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x70, &out3);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x71, &light0.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x72, ids[0] != -1 ? &light0.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x73, &light1.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x74, ids[1] != -1 ? &light1.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x75, &light2.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x76, ids[2] != -1 ? &light2.diffuse : &zero);
}
