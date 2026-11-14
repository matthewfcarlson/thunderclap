// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0032fc40..0x00330990 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dToon2VertexShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f6ae905d {
#define TREE_TU_END }
namespace fn_f6ae905d {} using namespace fn_f6ae905d;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f6ae905d {
class Ref_32fc40 {
  public:
    virtual void A();
    virtual void Release();
};
extern int toonVftable;
class d3dToon2VertexShader_32fc40 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[0x7c];
    Ref_32fc40* m80;
    Ref_32fc40* m84;
    Ref_32fc40* m88;
    void Reset();
};
struct d3dToon2VertexShader_nv_32fc40 {
    void Go();
};
class pddiObject_32fcc0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_32fcc0 : public pddiObject_32fcc0 {};
class pddiBaseShader_32fcc0 : public pddiShader_32fcc0 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_32fcc0 : public pddiBaseShader_32fcc0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class Obj {
    char pad[0xcc];
    int mode;
    float value;

  public:
    void Set(int x);
};
struct Vec4_32fd40 {
    float x, y, z, w;
};
struct Matrix {
    float m[16];
    void FUN_0022c310(Vec4_32fd40* in, Vec4_32fd40* out);
};
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(unsigned long type, Matrix* out);
}
struct D3DLOCKED_RECT {
    int Pitch;
    unsigned int* pBits;
};
namespace D3D8 {
void __stdcall D3DTexture_LockRect(int texture, int level, D3DLOCKED_RECT* lr, const void* rect, int flags);
}
struct TexObj_32fe00 {
    char pad0[0x10];
    int handle;
};
class GradientTex {
  public:
    char pad0[0x80];
    TexObj_32fe00* tex;
    char pad84[0xd4 - 0x84];
    int size;
    void Fill();
};
namespace D3D8 {
struct LockedRect_32ff00 { int pitch; unsigned int* bits; };
}
namespace D3D8 {
void __stdcall D3DTexture_LockRect(void*, unsigned int, LockedRect_32ff00*, void*, unsigned int);
}
struct Texture { char pad[0x10]; void* texture; };
struct Object { char pad0[0x84]; Texture* texture; char pad1[0x50]; int count; void FUN_0032ff00(); };
class Owner {
    char pad[0x88];
    Ref* ptr;

  public:
    void Set(Ref* p);
};
class d3dShader_32ff90 {
  public:
    virtual void v();
    d3dShader_32ff90(int);
    char pad[0x7c];
    int a, b, c;
    char p[0x44];
    float d;
    int e, f;
};
class d3dToon2VertexShader_32ff90 : public d3dShader_32ff90 {
  public:
    virtual void v();
    d3dToon2VertexShader_32ff90(int);
};
class Obj_32ffe0 {
  public:
    virtual void a();
    virtual void b();
};
extern int vtable_32ffe0;
class d3dToon2VertexShader_32ffe0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dToon2VertexShader_32ffe0* vfunc_3(unsigned char);
    char pad[0x7c];
    Obj_32ffe0* p80;
    Obj_32ffe0* p84;
    Obj_32ffe0* p88;
    void helper();
};
void thunk_FUN_00267090(d3dToon2VertexShader_32ffe0*);


// 0x0032fc40 FUN_0032fc40 (62 B): matches/0x0032fc40.cpp
// sym: ?Reset@d3dToon2VertexShader_32fc40@fn_f6ae905d@@QAEXXZ
void d3dToon2VertexShader_32fc40::Reset() {
    *(hulk_intptr*)this = (hulk_intptr)&toonVftable;
    if (m88)
        m88->Release();
    if (m80)
        m80->Release();
    if (m84)
        m84->Release();
    ((d3dToon2VertexShader_nv_32fc40*)(((pure3d::d3dToon2VertexShader*)this)))->Go();
}


// 0x0032fc80 pure3d::d3dToon2VertexShader::vfunc_16 (6 B): matches/0x0032fc80.cpp
// sym: _FUN_0032fc80
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032fc80() {
    return &(*(int*)&DAT_004d8b70);
}


// 0x0032fc90 pure3d::d3dToon2VertexShader::vfunc_15 (6 B): matches/0x0032fc90.cpp
// sym: _FUN_0032fc90
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032fc90() {
    return &(*(int*)&DAT_004d8b40);
}


// 0x0032fca0 pure3d::d3dToon2VertexShader::vfunc_18 (6 B): matches/0x0032fca0.cpp
// sym: _FUN_0032fca0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032fca0() {
    return &(*(int*)&DAT_004d8b10);
}


// 0x0032fcb0 pure3d::d3dToon2VertexShader::vfunc_4 (6 B): matches/0x0032fcb0.cpp
// sym: _FUN_0032fcb0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032fcb0() {
    return &(*(int*)&DAT_004d8a7c);
}

} // namespace fn_f6ae905d

// 0x0032fcc0 pure3d::d3dToon2VertexShader::vfunc_11 (6 B): matches/0x0032fcc0.cpp
// sym: ?vfunc_11@d3dToon2VertexShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dToon2VertexShader::vfunc_11() {
    return 1;
}

namespace fn_f6ae905d {

// 0x0032fcd0 pure3d::d3dToon2VertexShader::vfunc_12 (1 B): matches/0x0032fcd0.cpp
// sym: ?FUN_0032fcd0@fn_f6ae905d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0032fcd0() {}

} // namespace fn_f6ae905d

// 0x0032fce0 pure3d::d3dToon2VertexShader::vfunc_22 (3 B): matches/0x0032fce0.cpp
// sym: ?vfunc_22@d3dToon2VertexShader@pure3d@@UAE_NXZ
bool pure3d::d3dToon2VertexShader::vfunc_22() {
    return true;
}

namespace fn_f6ae905d {

// 0x0032fcf0 pure3d::d3dToon2VertexShader::vfunc_23 (6 B): matches/0x0032fcf0.cpp
// sym: _FUN_0032fcf0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0032fcf0() {
    return &(*(int*)&DAT_00433650);
}


// 0x0032fd00 pure3d::d3dToon2VertexShader::vfunc_13 (1 B): matches/0x0032fd00.cpp
// sym: ?FUN_0032fd00@fn_f6ae905d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0032fd00() {}


// 0x0032fd10 FUN_0032fd10 (47 B): matches/0x0032fd10.cpp
// sym: ?Set@Obj@fn_f6ae905d@@QAEXH@Z
void Obj::Set(int x) {
    mode = x;
    switch (x) {
    case 0:
    case 2:
        value = 1.0f;
        break;
    case 1:
        value = 0.05f;
        break;
    }
}


// 0x0032fd40 FUN_0032fd40 (185 B): equivalent/0x0032fd40.cpp
// sym: _FUN_0032fd40@4 @9c6f4251b3db @w4a02617d1b8a
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0032fd40 @ 0x0032fd40
extern "C" void __stdcall FUN_0032fd40(void * result) {
    Vec4_32fd40 origin;
    Vec4_32fd40 transformed;
    Matrix view;
    Matrix world;
    Matrix product;
    Matrix inverse;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    origin.w = 1.0f;
    D3D8::D3DDevice_GetTransform(6, &view);
    D3D8::D3DDevice_GetTransform(0, &world);
    ((owners::Matrix_22ca90 *)&product)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(&view), (const owners::Matrix_22ca90 *)(Matrix *)(&world));
    inverse = product;
    ((owners::Matrix_22cdb0 *)&inverse)->FUN_0022cdb0();
    inverse.FUN_0022c310(&origin, &transformed);
    ((Vec4_32fd40 *)result)->x = transformed.x;
    ((Vec4_32fd40 *)result)->y = transformed.y;
    ((Vec4_32fd40 *)result)->z = transformed.z;
    ((Vec4_32fd40 *)result)->w = transformed.w;
}


// 0x0032fe00 FUN_0032fe00 (241 B): equivalent/0x0032fe00.cpp
// sym: ?Fill@GradientTex@fn_f6ae905d@@QAEXXZ @76516aff8a93 @wb413f4c014e9
// STATUS: equivalent (tools/equiv.py level 3: 476 inputs, branch coverage 9/10, incomplete)
// FUN_0032fe00 @ 0x0032fe00
void GradientTex::Fill() {
    D3DLOCKED_RECT lr;
    D3D8::D3DTexture_LockRect(tex->handle, 0, &lr, 0, 0);
    unsigned int* p = lr.pBits;
    hulk_freg step = 1.0f / (hulk_freg)size;
    float x105 = step * 105.0f;
    hulk_freg val = 150.0f;
    for (int i = 0; i < size; i++) {
        hulk_freg k = step * 64.0f;
        if (0.0f < k) {
            int j = 0;
            do {
                *p++ = (signed char)(int)val * 0x10101 + 0xff000000;
                j++;
                k = 64.0f / (hulk_freg)size;
            } while ((hulk_freg)j < k);
        }
        val += x105;
        if (i >= size - 2)
            val = 255.0f;
    }
}


// 0x0032ff00 FUN_0032ff00 (90 B): equivalent/0x0032ff00.cpp
// sym: ?FUN_0032ff00@Object@fn_f6ae905d@@QAEXXZ @895a5c757dd9 @wc64d2e53e958
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0032ff00 @ 0x0032ff00
void Object::FUN_0032ff00() {
    D3D8::LockedRect_32ff00 rect;
    D3D8::D3DTexture_LockRect(texture->texture, 0, &rect, 0, 0);
    for (int i = 0; i < 256; ++i) rect.bits[i] = i < count ? 0 : 0xffffffff;
}


// 0x0032ff60 FUN_0032ff60 (44 B): matches/0x0032ff60.cpp
// sym: ?Set@Owner@fn_f6ae905d@@QAEXPAVRef@2@@Z
void Owner::Set(Ref* p) {
    if (p)
        p->AddRef();
    if (ptr)
        ptr->Release();
    ptr = p;
}


// 0x0032ff90 FUN_0032ff90 (75 B): matches/0x0032ff90.cpp
// sym: ??0d3dToon2VertexShader_32ff90@fn_f6ae905d@@QAE@H@Z
d3dToon2VertexShader_32ff90::d3dToon2VertexShader_32ff90(int x) : d3dShader_32ff90(x) {
    c = 0;
    b = 0;
    a = 0;
    d = 1.0f;
    e = 4;
    f = 0x20;
}


// 0x0032ffe0 pure3d::d3dToon2VertexShader::vfunc_3 (83 B): matches/0x0032ffe0.cpp
// sym: ?vfunc_3@d3dToon2VertexShader_32ffe0@fn_f6ae905d@@UAEPAV12@E@Z
d3dToon2VertexShader_32ffe0* d3dToon2VertexShader_32ffe0::vfunc_3(unsigned char flag) {
    *(volatile hulk_intptr*)this = (hulk_intptr)&vtable_32ffe0;
    if (p88)
        p88->b();
    if (p80)
        p80->b();
    if (p84)
        p84->b();
    helper();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f6ae905d

// 0x00330040 pure3d::d3dToon2VertexShader::vfunc_24 (782 B): equivalent/0x00330040.cpp [wrapped: conflict: pure3d::d3dToon2VertexShader]
// sym: ?vfunc_24@d3dToon2VertexShader@pure3d@fn_00330040@@UAEXXZ @612e0212896a @w371af56298dd
namespace fn_00330040 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// pure3d::d3dToon2VertexShader::vfunc_24 @ 0x00330040
typedef unsigned int uint;
struct Four_330040 {
    float x, y, z, w;
};
struct Matrix {
    float v[16];
    void FUN_0022ca90(const Matrix* a, const Matrix* b);
    void FUN_0022c0b0();
    void FUN_0022cdb0();
};
struct Light {
    char data[0x68];
};
extern "C++" void __stdcall FUN_0032fd40(void *);
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(uint type, Matrix* out);
void __stdcall D3DDevice_GetLight(uint index, Light* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(uint reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(uint reg, const void* data);
}
struct LightManager_330040 {
    void FUN_00321dc0(int* indices, int flags);
};
namespace pure3d {
class d3dToon2VertexShader {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(Four_330040* out);
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    char pad04[0x10 - 4];
    LightManager_330040* manager;
    char pad14[0x50 - 0x14];
    uint color;
    char pad54[0xd0 - 0x54];
    uint texture;
};
}

void pure3d::d3dToon2VertexShader::vfunc_24() {
    // Locals are kept in one block so their relative stack layout matches the original.
    struct Frame {
        int indices[4];
        Four_330040 zero;
        Four_330040 tint;
        Four_330040 settings;
        Four_330040 other;
        Four_330040 base;
        Matrix inv6Copy;
        Matrix transform6;
        Four_330040 ambient;
        int pad;
        Matrix r1;
        Matrix inv2;
        Matrix inv1;
        Matrix r2;
        Matrix inv6CopyB;
        Matrix transform1;
        Matrix inv6B;
        Matrix transform0;
        Light lights[3];
    } f;

    FUN_0032fd40((Four_330040 *)(&f.base));
    f.tint.x = (float)((color >> 16) & 0xff) * 0.0039215689f;
    f.tint.y = (float)((color >> 8) & 0xff) * 0.0039215689f;
    f.tint.z = (float)(color & 0xff) * 0.0039215689f;
    f.tint.w = 1.0f;
    f.other.x = 256.0f;
    f.other.y = 64.0f;
    f.other.z = 0.0f;
    f.other.w = 0.0f;
    f.settings.x = 0.0f;
    f.settings.y = 1.0f;
    *(uint*)&f.settings.z = texture;
    f.settings.w = 64.0f;
    D3D8::D3DDevice_GetTransform(6, &f.transform6);
    D3D8::D3DDevice_GetTransform(0, &f.transform0);
    D3D8::D3DDevice_GetTransform(1, &f.transform1);
    f.r1.FUN_0022ca90(&f.transform6, &f.transform0);
    f.r2.FUN_0022ca90(&f.r1, &f.transform1);
    f.inv1 = f.r1;
    f.inv1.FUN_0022c0b0();
    f.inv2 = f.r2;
    f.inv2.FUN_0022c0b0();
    f.inv6Copy = f.transform6;
    f.inv6Copy.FUN_0022c0b0();
    f.inv6B = f.transform6;
    f.inv6B.FUN_0022cdb0();
    f.inv6CopyB = f.inv6Copy;
    f.inv6CopyB.FUN_0022cdb0();
    D3D8::D3DDevice_SetVertexShaderConstant1(0x61, &f.base);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x62, &f.inv2);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x75, &f.inv1);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x66, &f.inv6Copy);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6c, &f.inv6Copy);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x70, &f.settings);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6a, &f.tint);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6b, &f.other);
    f.zero.x = 0.0f;
    f.zero.y = 0.0f;
    f.zero.z = 0.0f;
    f.zero.w = 0.0f;
    manager->FUN_00321dc0(f.indices, 0);
    D3D8::D3DDevice_GetLight(f.indices[0] == -1 ? 0 : f.indices[0], &f.lights[0]);
    D3D8::D3DDevice_GetLight(f.indices[1] == -1 ? 0 : f.indices[1], &f.lights[1]);
    D3D8::D3DDevice_GetLight(f.indices[2] == -1 ? 0 : f.indices[2], &f.lights[2]);
    vfunc_21(&f.ambient);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x71, f.indices[0] == -1 ? (const void*)&f.zero : (const void*)(f.lights[0].data + 0x40));
    D3D8::D3DDevice_SetVertexShaderConstant1(0x72, f.indices[1] == -1 ? (const void*)&f.zero : (const void*)(f.lights[1].data + 0x40));
    // (the original tests indices[1] again here, not indices[2])
    D3D8::D3DDevice_SetVertexShaderConstant1(0x73, f.indices[1] == -1 ? (const void*)&f.zero : (const void*)(f.lights[2].data + 0x40));
}
} // namespace fn_00330040


// 0x00330350 FUN_00330350 (139 B): matches/0x00330350.cpp [wrapped: compile error C2440: 'initializing' : cannot convert from 'hulk_intptr' to 'void *']
// sym: ?FUN_00330350@d3dToon2VertexShader_330350@fn_00330350@@QAEXXZ
namespace fn_00330350 {
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 4/4)
// FUN_00330350 @ 0x00330350
struct SurfaceDesc_330350 {
    unsigned int format;
    unsigned int rest[6];
};
namespace D3D8 {
void* __stdcall D3DDevice_GetBackBuffer2(unsigned int index);
void __stdcall D3DSurface_GetDesc(void* surface, SurfaceDesc_330350* desc);
void __stdcall D3DResource_Release(void* surface);
void* __stdcall D3DDevice_CreateTexture2(unsigned int width, unsigned int height, unsigned int depth,
                                         unsigned int levels, unsigned int usage, unsigned int format,
                                         unsigned int pool);
} // namespace D3D8
extern "C" void* __cdecl FUN_0008d690(unsigned int bytes);
struct d3dToon2VertexShader_330350 {
    char pad0[0x10];
    void* device;
    char pad1[0x70];
    void* texture;
    void FUN_0032ff00();
    void FUN_00330350();
};
struct d3dTexture_330350 {
    d3dTexture_330350* FUN_00326110(void* device, void* texture);
};
void d3dToon2VertexShader_330350::FUN_00330350() {
    if (texture == 0) {
        SurfaceDesc_330350 desc;
        void* backBuffer = D3D8::D3DDevice_GetBackBuffer2(0);
        D3D8::D3DSurface_GetDesc(backBuffer, &desc);
        D3D8::D3DResource_Release(backBuffer);
        void* newTexture = D3D8::D3DDevice_CreateTexture2(256, 1, 1, 1, 0, desc.format, 3);
        d3dTexture_330350* object = (d3dTexture_330350*)FUN_0008d690(0xf8);
        texture = object != 0 ? object->FUN_00326110(device, newTexture) : 0;
        FUN_0032ff00();
    }
}
} // namespace fn_00330350


// 0x003303e0 FUN_003303e0 (136 B): matches/0x003303e0.cpp [wrapped: compile error C2440: 'initializing' : cannot convert from 'hulk_intptr' to 'void *']
// sym: ?FUN_003303e0@d3dToon2VertexShader_3303e0@fn_003303e0@@QAEXXZ
namespace fn_003303e0 {
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 4/4)
// FUN_003303e0 @ 0x003303e0
namespace D3D8 {
void* __stdcall D3DDevice_GetBackBuffer2(unsigned int index);
void __stdcall D3DSurface_GetDesc(void* surface, void* description);
unsigned int __stdcall D3DResource_Release(void* resource);
void* __stdcall D3DDevice_CreateTexture2(unsigned int width, unsigned int height, unsigned int depth,
                                         unsigned int levels, unsigned int usage, unsigned int format,
                                         unsigned int pool);
} // namespace D3D8
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
struct d3dTexture_3303e0 {
    char pad[0xf8];
    d3dTexture_3303e0* FUN_00326110(void* device, void* texture);
};
struct d3dToon2VertexShader_3303e0 {
    char pad0[0x10];
    void* device;
    char pad1[0x6c];
    d3dTexture_3303e0* texture;
    void FUN_0032fe00();
    void FUN_003303e0();
};
void d3dToon2VertexShader_3303e0::FUN_003303e0() {
    if (texture == 0) {
        unsigned int description[7];
        void* surface = D3D8::D3DDevice_GetBackBuffer2(0);
        D3D8::D3DSurface_GetDesc(surface, description);
        D3D8::D3DResource_Release(surface);
        void* createdTexture = D3D8::D3DDevice_CreateTexture2(0x40, 1, 1, 1, 0, description[0], 3);
        d3dTexture_3303e0* memory = (d3dTexture_3303e0*)FUN_0008d690((int)sizeof(d3dTexture_3303e0));
        texture = memory != 0 ? memory->FUN_00326110(device, createdTexture) : 0;
        FUN_0032fe00();
    }
}
} // namespace fn_003303e0


// 0x00330470 FUN_00330470 (52 B): matches/0x00330470.cpp [wrapped: same definition as 0x0032fd10 in this TU]
// sym: ?Set@Obj@fn_00330470@@QAEXH@Z
namespace fn_00330470 {
class Obj {
  public:
    char pad[0x80];
    void* ptr;
    char gap[0x50];
    int val;
    void Set(int n);
    void Refresh();
};
void Obj::Set(int n) {
    if (n != val) {
        val = n;
        if (n < 4)
            n = 4;
        val = n;
        if (ptr)
            Refresh();
    }
}
} // namespace fn_00330470


// 0x003304b0 FUN_003304b0 (87 B): matches/0x003304b0.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_003304b0@@QAEXM@Z
namespace fn_003304b0 {
class Obj {
    char pad0[0x80];
    void* ptr;
    char pad1[0xd8 - 0x84];
    int value;

  public:
    void Update();
    void Set(float x);
};
void Obj::Set(float x) {
    int n = (int)(x * 256.0f);
    if (n != value) {
        value = n;
        if (n < 32)
            n = 32;
        value = n;
        if (n > 128)
            n = 128;
        value = n;
        if (ptr)
            Update();
    }
}
} // namespace fn_003304b0


// 0x00330510 pure3d::d3dToon2VertexShader::vfunc_14 (322 B): equivalent/0x00330510.cpp [wrapped: conflict: pure3d::d3dToon2VertexShader]
// sym: ?vfunc_14@d3dToon2VertexShader@pure3d@fn_00330510@@QAEXH@Z @0300cea07b81 @w459856103468
namespace fn_00330510 {
// STATUS: equivalent (tools/equiv.py level 3: 19782 inputs, branch coverage 10/10)
// pure3d::d3dToon2VertexShader::vfunc_14 @ 0x00330510

struct Context { char pad0[0x2c]; int state2; int state4; char pad1[0x14]; int mode; void FUN_0032a920(int,int,int,int,int); void FUN_00329e50(int,int,int,int); void FUN_00329c90(int,int); void FUN_00329f70(int,int,void*); };
namespace D3D8 { void __fastcall D3DDevice_SetRenderState_Simple(void*,int); }
extern int DAT_0039db08, DAT_0039db90, DAT_0039db94, DAT_0039db98, DAT_0039dc10, DAT_0039dc14, DAT_0039dc18, DAT_0039de18;
namespace pure3d { struct d3dToon2VertexShader { char pad0[0x14]; Context* context; char pad1[0x2c]; int texture; unsigned char flag; char pad2[3]; int mode; char pad3[0x2c]; unsigned char flag2; char pad4[3]; int vertex; int pixel; int extra; void FUN_00330350(); void FUN_003303e0(); void FUN_0032a260(); void vfunc_14(int unused); }; }
void pure3d::d3dToon2VertexShader::vfunc_14(int unused) {
 if (!pixel) FUN_00330350();
 if (!vertex) FUN_003303e0();
 context->FUN_0032a920(3,extra,vertex,pixel,0);
 context->FUN_00329e50(0,4,1,2);
 context->FUN_00329e50(1,4,1,2);
 context->FUN_00329e50(2,4,1,2);
 if (context->state2 != 1) { context->state2=1; DAT_0039db90=(*(int*)((char*)&DAT_004d4efc + 4)); DAT_0039db94=(*(int*)((char*)&DAT_004d4efc + 4)); DAT_0039db08 |= 2; DAT_0039db98=(*(int*)((char*)&DAT_004d4efc + 4)); }
 context->FUN_00329c90(1,2);
 if (context->state4 != 1) { context->state4=1; DAT_0039dc10=(*(int*)((char*)&DAT_004d4efc + 4)); DAT_0039dc14=(*(int*)((char*)&DAT_004d4efc + 4)); DAT_0039db08 |= 4; DAT_0039dc18=(*(int*)((char*)&DAT_004d4efc + 4)); }
 context->FUN_00329c90(2,texture);
 context->FUN_00329c90(2,2);
 if (context->mode != mode) { context->mode=mode; int value=DAT_004d4f24[mode]; D3D8::D3DDevice_SetRenderState_Simple(((char*)0x0004037c),value); DAT_0039de18=value; }
 context->FUN_00329f70(flag,flag2,&pad3[0]);
 FUN_0032a260();
}
} // namespace fn_00330510

