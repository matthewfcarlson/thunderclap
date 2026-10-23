// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// pure3d::d3dBumpMapVertexShader::vfunc_12 @ 0x00332ec0
#include "gen/pure3d.h"

struct Color4 {
    float r, g, b, a;
};
struct Light8_332ec0 {
    unsigned int type;
    Color4 diffuse;
    Color4 specular;
    Color4 ambient;
    float position[3];
    float direction[3];
    float range;
    float falloff;
    float attenuation0, attenuation1, attenuation2;
    float theta, phi;
};
struct Context_332ec0 {
    char pad[0x110];
    unsigned int pixelShader;
};
struct LightQuery {
    int index;
    int extra[3];
};
struct LightSource_332ec0 {
    void FUN_00321dc0(LightQuery* out, int flags);
};
namespace D3D8 {
void __stdcall D3DDevice_GetLight(unsigned int index, Light8_332ec0* out);
void __stdcall D3DDevice_SetPixelShaderConstant(unsigned int reg, const float* data, unsigned int count);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const float* data);
void __stdcall D3DDevice_SetPixelShader(unsigned int handle);
}

namespace pure3d {

}
void pure3d::d3dBumpMapVertexShader::vfunc_12() {
    Context_332ec0* c = (*(Context_332ec0 * *)&this->f_14);
    unsigned int shader = (*(unsigned int *)&this->f_8c);
    if (c->pixelShader != shader) {
        c->pixelShader = shader;
        D3D8::D3DDevice_SetPixelShader(shader);
    }
    LightQuery query;
    (*(LightSource_332ec0 * *)&this->f_10)->FUN_00321dc0(&query, 0);
    int lightIndex = query.index;
    if (lightIndex == -1)
        lightIndex = 0;
    Light8_332ec0 light;
    D3D8::D3DDevice_GetLight(lightIndex, &light);
    float v[4];
    v[0] = (float)(*(unsigned char *)&this->f_52) * light.diffuse.r * 0.003921569f;
    v[1] = (float)(*(unsigned char *)&this->f_51) * light.diffuse.g * 0.003921569f;
    v[2] = (float)(*(unsigned char *)&this->f_50) * light.diffuse.b * 0.003921569f;
    v[3] = 1.0f;
    D3D8::D3DDevice_SetPixelShaderConstant(1, v, 1);
    v[0] = (float)(*(unsigned char *)&this->f_56) * light.specular.r * 0.003921569f;
    v[1] = (float)(*(unsigned char *)&this->f_55) * light.specular.g * 0.003921569f;
    v[2] = (float)(*(unsigned char *)&this->f_54) * light.specular.b * 0.003921569f;
    v[3] = 1.0f;
    D3D8::D3DDevice_SetPixelShaderConstant(0, v, 1);
    v[0] = 0; v[1] = 0; v[2] = 0; v[3] = 0;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, v);
    v[0] = 1.0f; v[1] = 1.0f; v[2] = 1.0f; v[3] = 1.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x61, v);
    v[0] = 0.5f; v[1] = 0.5f; v[2] = 0.5f; v[3] = 0.5f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x72, v);
    v[0] = 0; v[1] = 0; v[2] = 0; v[3] = 1.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x77, v);
    if (this->f_88) {
        v[0] = 1.0f; v[1] = 1.0f; v[2] = 1.0f; v[3] = 1.0f;
    } else {
        v[0] = 0; v[1] = 0; v[2] = 0; v[3] = 0;
    }
    D3D8::D3DDevice_SetVertexShaderConstant1(0x71, v);
}
