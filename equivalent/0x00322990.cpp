// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 11/12, incomplete)
// FUN_00322990 @ 0x00322990
#include "compat/ptr.h"
namespace D3D8 {
int __stdcall D3DDevice_GetBackBuffer2(int);
void __stdcall D3DResource_Release(int);
}
struct Surface_322990 {
    unsigned int common;
};
struct Ctx_322990;
struct HeapObj {
    static void* operator new(unsigned size) throw();
};
class TexRef_322990 : public HeapObj {
  public:
    TexRef_322990(Ctx_322990* ctx, int arg) throw();
    virtual void v0();
    void FUN_00326300(Surface_322990* s);
    char pad4[0xf8 - 4];
};
class ShaderObj_322990 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void SetTexture(int slot, TexRef_322990* tex);
    virtual void SetMode(int mode, int on);
};
class Factory_322990 {
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
    virtual ShaderObj_322990* CreateShader(const char* name, int arg);
};
class Viewport_322990 {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int GetHeight();
    virtual int GetWidth();
};
struct Prim_322990 {
    char pad0[8];
    float* pos;
    char padc[4];
    unsigned int* color;
    float* uv;
    void FUN_0008ef00();
};
struct Ctx_322990 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(int);
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24(int);
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29(float*, float*, float*, float*);
    virtual Prim_322990* f30(ShaderObj_322990*, int, int, int, int);
    virtual void f31(Prim_322990*);
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58(int);
    char pad4[0x154 - 4];
    Viewport_322990* viewport;
    Factory_322990* factory;
};
class Overlay {
  public:
    char pad0[4];
    Ctx_322990* ctx;
    ShaderObj_322990* shader;
    TexRef_322990* tex;
    unsigned char enabled;
    char pad11[3];
    float alpha;
    float scale;
    unsigned char split;
    void Draw();
};
void Overlay::Draw() {
    if (!enabled)
        return;
    if (shader == 0) {
        shader = ctx->factory->CreateShader("simple", 0);
        tex = new TexRef_322990(ctx, 0);
        shader->v0();
        tex->v0();
        shader->SetTexture(0x584554, tex);
    }
    unsigned int a = (unsigned char)(int)(alpha * 254.0f);
    float f[3];
    f[0] = scale;
    f[1] = scale + 4.0f;
    f[2] = scale + 8.0f;
    unsigned int col[3];
    int n;
    if (split) {
        col[0] = a << 16;
        col[1] = a << 8;
        col[2] = a;
        n = 3;
    } else {
        col[0] = (((a << 8) | a) << 8) | a;
        n = 1;
    }
    float zNear, unusedB, farv;
    ctx->f29(&zNear, &unusedB, &unusedB, &farv);
    zNear = zNear * 1.01f;
    ctx->f24(2);
    ctx->f58(0);
    ctx->f13(0);
    shader->SetMode(0x444d4c42, 2);
    Surface_322990* bb = (Surface_322990*)D3D8::D3DDevice_GetBackBuffer2(-1);
    unsigned int saved = bb->common;
    bb->common = (bb->common & 0xfffcffffu) | 0x40000;
    tex->FUN_00326300(bb);
    float h = (float)ctx->viewport->GetHeight();
    float w = (float)ctx->viewport->GetWidth();
    for (int i = 0; i < n; i++) {
        Prim_322990* p = ctx->f30(shader, 1, 0x2021, 4, 0);
        float v = farv * f[i];
        float u = f[i];
        float vMax = h - v;
        float uMax = w - f[i];
        *p->color = col[i];
        p->uv[0] = u;
        p->uv[1] = v;
        p->pos[0] = 0;
        p->pos[1] = 0;
        p->pos[2] = zNear;
        p->FUN_0008ef00();
        *p->color = col[i];
        p->uv[0] = uMax;
        p->uv[1] = v;
        p->pos[0] = w;
        p->pos[1] = 0;
        p->pos[2] = zNear;
        p->FUN_0008ef00();
        *p->color = col[i];
        p->uv[0] = u;
        p->uv[1] = vMax;
        p->pos[0] = 0;
        p->pos[1] = h;
        p->pos[2] = zNear;
        p->FUN_0008ef00();
        *p->color = col[i];
        p->uv[0] = uMax;
        p->uv[1] = vMax;
        p->pos[0] = w;
        p->pos[1] = h;
        p->pos[2] = zNear;
        p->FUN_0008ef00();
        ctx->f31(p);
    }
    tex->FUN_00326300(0);
    bb->common = (bb->common & ~0x70000u) | (saved & 0x70000);
    D3D8::D3DResource_Release((hulk_intptr)bb);
    ctx->f24(0);
    ctx->f58(1);
}
