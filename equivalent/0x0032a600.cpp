// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 12/12)
// FUN_0032a600 @ 0x0032a600
struct Vec4_32a600 {
    float x, y, z, w;
};
struct D3DLIGHT8 {
    int Type;
    Vec4_32a600 Diffuse, Specular, Ambient;
    float Position[3];
    float Direction[3];
    float Range, Falloff, Attenuation0, Attenuation1, Attenuation2, Theta, Phi;
};
namespace D3D8 {
void __stdcall D3DDevice_GetLight(int index, D3DLIGHT8* light);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
}
struct LightMgr {
    void FUN_00321dc0(int* out, int count);
};
struct LightConst_32a600 {
    unsigned char used;
    Vec4_32a600 pos;
    Vec4_32a600 atten;
    Vec4_32a600 color;
};
struct Frame_32a600 {
    LightConst_32a600 lights[4];
    int ids[4];
    D3DLIGHT8 light;
};
class LightSet_32a600 {
  public:
    char pad0[0x10];
    LightMgr* mgr;
    char pad14[0x84 - 0x14];
    unsigned char dirLight;
    char pad85[0x8c - 0x85];
    unsigned char b8c;
    int mode;
    void Upload();
};
void LightSet_32a600::Upload() {
    Frame_32a600 F;
    F.lights[0].used = 0;
    F.lights[0].pos.x = 1.0f;
    F.lights[0].pos.y = 1.0f;
    F.lights[0].pos.z = 1.0f;
    F.lights[0].pos.w = 1.0f;
    F.lights[0].atten.x = 1.0e10f;
    F.lights[0].atten.y = 1.0e10f;
    F.lights[0].atten.z = 1.0e10f;
    F.lights[0].atten.w = 1.0e10f;
    F.lights[0].color.x = 0.0f;
    F.lights[0].color.y = 0.0f;
    F.lights[0].color.z = 0.0f;
    F.lights[0].color.w = 0.0f;
    F.lights[1].used = 0;
    F.lights[1].pos.x = 1.0f;
    F.lights[1].pos.y = 1.0f;
    F.lights[1].pos.z = 1.0f;
    F.lights[1].pos.w = 1.0f;
    F.lights[1].atten.x = 1.0e10f;
    F.lights[1].atten.y = 1.0e10f;
    F.lights[1].atten.z = 1.0e10f;
    F.lights[1].atten.w = 1.0e10f;
    F.lights[1].color.x = 0.0f;
    F.lights[1].color.y = 0.0f;
    F.lights[1].color.z = 0.0f;
    F.lights[1].color.w = 0.0f;
    F.lights[2].used = 0;
    F.lights[2].pos.x = 1.0f;
    F.lights[2].pos.y = 1.0f;
    F.lights[2].pos.z = 1.0f;
    F.lights[2].pos.w = 1.0f;
    F.lights[2].atten.x = 1.0e10f;
    F.lights[2].atten.y = 1.0e10f;
    F.lights[2].atten.z = 1.0e10f;
    F.lights[2].atten.w = 1.0e10f;
    F.lights[2].color.x = 0.0f;
    F.lights[2].color.y = 0.0f;
    F.lights[2].color.z = 0.0f;
    F.lights[2].color.w = 0.0f;
    F.lights[3].used = 0;
    F.lights[3].pos.x = 1.0f;
    F.lights[3].pos.y = 1.0f;
    F.lights[3].pos.z = 1.0f;
    F.lights[3].pos.w = 1.0f;
    F.lights[3].atten.x = 1.0e10f;
    F.lights[3].atten.y = 1.0e10f;
    F.lights[3].atten.z = 1.0e10f;
    F.lights[3].atten.w = 1.0e10f;
    F.lights[3].color.x = 0.0f;
    F.lights[3].color.y = 0.0f;
    F.lights[3].color.z = 0.0f;
    F.lights[3].color.w = 0.0f;
    if (mode == 1 || b8c) {
        mgr->FUN_00321dc0(F.ids, 3);
        for (int i = 0; i < 4; i++) {
            int id = F.ids[i];
            if (id == -1)
                continue;
            D3D8::D3DDevice_GetLight(id, &F.light);
            F.lights[i].pos.x = F.light.Position[0];
            F.lights[i].pos.y = F.light.Position[1];
            F.lights[i].pos.z = F.light.Position[2];
            F.lights[i].atten.z = F.light.Attenuation2;
            if (mode == 1 && dirLight) {
                F.lights[i].color.w = 1.0f;
            } else {
                F.lights[i].color.x = F.light.Diffuse.x;
                F.lights[i].color.y = F.light.Diffuse.y;
                F.lights[i].color.z = F.light.Diffuse.z;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        D3D8::D3DDevice_SetVertexShaderConstant1(0x7e + i * 3, &F.lights[i].pos);
        D3D8::D3DDevice_SetVertexShaderConstant1(0x7f + i * 3, &F.lights[i].atten);
        D3D8::D3DDevice_SetVertexShaderConstant1(0x80 + i * 3, &F.lights[i].color);
    }
}
