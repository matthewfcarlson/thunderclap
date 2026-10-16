// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_00321310 @ 0x00321310
#include "decls/data/platform/xbox/pure3d.h"

typedef unsigned long DWORD;
struct Vec3_321310 {
    float x, y, z;
    void FUN_0022d290(Vec3_321310* v, void* matrix);
    void FUN_0022d240(Vec3_321310* v, void* matrix);
};
struct Color4 {
    float r, g, b, a;
};
struct Light8_321310 {
    int Type;
    Color4 Diffuse;
    Color4 Specular;
    Color4 Ambient;
    Vec3_321310 Position;
    Vec3_321310 Direction;
    float Range;
    float Falloff;
    float Attenuation0;
    float Attenuation1;
    float Attenuation2;
    float Theta;
    float Phi;
};
struct LightSource_321310 {
    Vec3_321310 position;
    char pad0[0x20 - 12];
    Vec3_321310 direction;
    char pad1[0x54 - 0x2c];
    float range;
    float att0;
    float att1;
    float att2;
    float phi;
    float theta;
    float falloff;
    int type;
    int colorId;
    unsigned char enabled;
    char pad2[3];
};
struct LightSet_321310 {
    char pad[4];
    LightSource_321310 lights[8];
};
struct MatrixData_321310 {
    float m[16];
};
// equiv-conv: FUN_0031ffc0 ecx stack
void FUN_0031ffc0(Color4* self, int id);
namespace D3D8 {
void __stdcall D3DDevice_SetLight(DWORD index, Light8_321310* light);
void __stdcall D3DDevice_LightEnable(DWORD index, int enable);
}
struct LightingState {
    char pad0[0x50];
    LightSet_321310* set;
    char pad1[0x20c - 0x54];
    MatrixData_321310 matrices[8];
    unsigned char dirty[8];
    unsigned char anyDirty;
    void FUN_00321310();
};
void LightingState::FUN_00321310() {
    if (!anyDirty)
        return;
    anyDirty = 0;
    for (int i = 0; i < 8; i++) {
        if (!dirty[i])
            continue;
        dirty[i] = 0;
        LightSource_321310* src = &set->lights[i];
        Vec3_321310 dir;
        dir.FUN_0022d290(&src->direction, &matrices[i]);
        Vec3_321310 pos;
        pos.FUN_0022d240(&src->position, &matrices[i]);
        LightSource_321310* cur = &set->lights[i];
        Light8_321310 light;
        Color4 zero;
        zero.r = 0.0f;
        zero.g = 0.0f;
        zero.b = 0.0f;
        zero.a = 0.0f;
        light.Type = DAT_004d3a10[cur->type];
        FUN_0031ffc0(&light.Diffuse, cur->colorId);
        light.Specular = light.Diffuse;
        light.Ambient = zero;
        light.Position = pos;
        light.Direction = dir;
        light.Range = cur->range;
        light.Falloff = cur->falloff;
        light.Attenuation0 = cur->att0;
        light.Attenuation1 = cur->att1;
        light.Attenuation2 = cur->att2;
        light.Theta = cur->theta;
        light.Phi = cur->phi;
        D3D8::D3DDevice_SetLight(i, &light);
        D3D8::D3DDevice_LightEnable(i, set->lights[i].enabled);
    }
}
