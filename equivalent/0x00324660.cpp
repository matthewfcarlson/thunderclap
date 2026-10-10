// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 7/8, incomplete)
// FUN_00324660 @ 0x00324660
struct Vec3 {
    float x, y, z;
};
struct Vec4 {
    float x, y, z, w;
};
struct Vertex {
    float x, y, z, rhw, u, v;
};
namespace D3D8 {
void __stdcall D3DDevice_SetVertexShader(int);
void __stdcall D3DDevice_SetPixelShader(int);
void __stdcall D3DDevice_SetPixelShaderConstant(int, const void*, int);
void __stdcall D3DDevice_SetTexture(int, int);
void __stdcall D3DDevice_DrawVerticesUP(int, int, const void*, int);
}
extern float __cdecl FUN_003209f0(float);
extern int __cdecl FUN_00356c30(int);
struct Locals {
    char pad0[12];
    float dot;
    Vec4 c2;
    float base;
    float scale;
    Vec4 c4;
    float inv;
    Vec4 c1;
    Vec4 c0;
    Vertex verts[4];
};
class FilterPass {
  public:
    char pad0[0x20];
    int texture;
    int shaders[17];
    void Draw(const Vec3* a, float f1, float f2, const Vec3* b, float f3, float f4, int w, int h, float u, float v);
};
void FilterPass::Draw(const Vec3* a, float f1, float f2, const Vec3* b, float f3, float f4, int w, int h, float u, float v) {
    Locals L;
    D3D8::D3DDevice_SetVertexShader(0x104);
    float fw = (float)w - 0.5f;
    float fh = (float)h - 0.5f;
    Vertex* verts = L.verts;
    verts[0].x = -0.5f;
    verts[0].y = -0.5f;
    verts[0].z = 1.0f;
    verts[0].rhw = 1.0f;
    verts[0].u = 0.0f;
    verts[0].v = 0.0f;
    verts[1].x = fw;
    verts[1].y = -0.5f;
    verts[1].z = 1.0f;
    verts[1].rhw = 1.0f;
    verts[1].u = u;
    verts[1].v = 0.0f;
    verts[2].x = -0.5f;
    verts[2].y = fh;
    verts[2].z = 1.0f;
    verts[2].rhw = 1.0f;
    verts[2].u = 0.0f;
    verts[2].v = v;
    verts[3].x = fw;
    verts[3].y = fh;
    verts[3].z = 1.0f;
    verts[3].rhw = 1.0f;
    verts[3].u = u;
    verts[3].v = v;
    unsigned int absBits = *(unsigned int*)&f1 & 0x7fffffff;
    float absF1 = *(float*)&absBits;
    int far_ = absF1 >= 0.5f;
    L.dot = a->z * b->z + a->y * b->y + a->x * b->x;
    float dd = L.dot * f4;
    L.c0.x = dd;
    L.c0.y = dd;
    L.c0.z = dd;
    L.c0.w = dd;
    L.c1.x = (b->x - L.dot + 1.0f) * 0.5f;
    L.c1.y = (b->y - L.dot + 1.0f) * 0.5f;
    L.c1.z = (b->z - L.dot + 1.0f) * 0.5f;
    L.c1.w = 0.0f;
    L.c2.x = f2;
    L.c2.y = f2;
    L.c2.z = f2;
    L.c2.w = f2;
    if (f2 == 1.0f)
        L.base = f1;
    else
        L.base = ((f1 - f3) * f2 + f3) * L.dot;
    L.scale = far_ ? 0.5f : 1.0f;
    if (f2 == 255.0f) {
        float t = ((f1 - f3) * 0.5f + 1.0f) * 0.5f;
        L.c4.x = t;
        L.c4.y = t;
        L.c4.z = t;
        L.c4.w = t;
        D3D8::D3DDevice_SetPixelShader(shaders[16]);
        D3D8::D3DDevice_SetPixelShaderConstant(0, a, 1);
        D3D8::D3DDevice_SetPixelShaderConstant(5, &L.c4, 1);
    } else {
        float r = FUN_003209f0(f2);
        L.inv = 1.0f / r;
        int lg = FUN_00356c30((int)r);
        float q = L.inv * L.scale;
        int idx = far_ + lg * 2;
        float cv = (L.base * q + 1.0f) * 0.5f;
        L.c4.x = cv;
        L.c4.y = cv;
        L.c4.z = cv;
        L.c4.w = cv;
        float q2 = q * L.dot;
        L.c2.x = L.c2.x * q2;
        L.c2.y = L.c2.y * q2;
        L.c2.z = L.c2.z * q2;
        L.c2.w = L.c2.w * q2;
        D3D8::D3DDevice_SetPixelShader(shaders[idx]);
        D3D8::D3DDevice_SetPixelShaderConstant(0, a, 1);
        D3D8::D3DDevice_SetPixelShaderConstant(3, &L.c4, 1);
        D3D8::D3DDevice_SetPixelShaderConstant(5, &L.c2, 1);
        D3D8::D3DDevice_SetPixelShaderConstant(6, &L.c1, 1);
        D3D8::D3DDevice_SetPixelShaderConstant(7, &L.c0, 1);
    }
    D3D8::D3DDevice_SetTexture(0, texture);
    D3D8::D3DDevice_DrawVerticesUP(6, 4, verts, 0x18);
}
