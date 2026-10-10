// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0032e0e0 @ 0x0032e0e0
typedef unsigned long DWORD;
struct Color4 {
    float r, g, b, a;
};
struct Vec3 {
    float x, y, z;
};
struct Light8 {
    int Type;
    Color4 Diffuse;
    Color4 Specular;
    Color4 Ambient;
    Vec3 Position;
    Vec3 Direction;
    float Range;
    float Falloff;
    float Attenuation0;
    float Attenuation1;
    float Attenuation2;
    float Theta;
    float Phi;
};
struct LightConsts {
    float position[4];
    float attenuation[4];
    float color[4];
    unsigned char used;
};
struct LightList {
    void FUN_00321dc0(int* indices, int count);
};
namespace D3D8 {
void __stdcall D3DDevice_GetLight(DWORD index, Light8* light);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
}
struct LightShader {
    char pad0[0x10];
    LightList* lights;
    char pad14[0x90 - 0x14];
    unsigned char directional;
    unsigned char useLights;
    char pad92[2];
    int mode;
    void FUN_0032e0e0();
};
void LightShader::FUN_0032e0e0() {
    LightConsts c[4];
    for (int i = 0; i < 4; i++) {
        c[i].used = 0;
        for (int k = 0; k < 4; k++) {
            c[i].position[k] = 1.0f;
            c[i].attenuation[k] = 1e10f;
            c[i].color[k] = 0.0f;
        }
    }
    if (mode == 1 || useLights) {
        int idx[4];
        lights->FUN_00321dc0(idx, 3);
        for (int i = 0; i < 4; i++) {
            if (idx[i] == -1)
                continue;
            Light8 light;
            D3D8::D3DDevice_GetLight(idx[i], &light);
            c[i].position[0] = light.Position.x;
            c[i].position[1] = light.Position.y;
            c[i].position[2] = light.Position.z;
            c[i].attenuation[2] = light.Attenuation2;
            if (mode == 1 && directional) {
                c[i].color[3] = 1.0f;
            } else {
                c[i].color[0] = light.Diffuse.r;
                c[i].color[1] = light.Diffuse.g;
                c[i].color[2] = light.Diffuse.b;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        D3D8::D3DDevice_SetVertexShaderConstant1(0x7e + i * 3, c[i].position);
        D3D8::D3DDevice_SetVertexShaderConstant1(0x7f + i * 3, c[i].attenuation);
        D3D8::D3DDevice_SetVertexShaderConstant1(0x80 + i * 3, c[i].color);
    }
}
