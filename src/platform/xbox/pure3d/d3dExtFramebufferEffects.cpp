// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00320160..0x00325ee0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dExtFramebufferEffects
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f57e27cb {
#define TREE_TU_END }
namespace fn_f57e27cb {} using namespace fn_f57e27cb;
// (x64t3) a local view's pad up to gen d3dContext's field F (byte K of the 32-bit context), less the view's own leading
// bytes B (its vftable pointer, or nothing): the views' fields sit at gen's offsets on 64-bit too (they were 32-bit pads)
#if defined(HULK_PTR64)
#define HULK_D3DCTX_PAD(f, k, b) (__builtin_offsetof(::pure3d::d3dContext, f) - (b))
#else
#define HULK_D3DCTX_PAD(f, k, b) ((k) - (b))
#endif
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f57e27cb {
class Device_320160 {
    char pad[0x154];

  public:
    void Read(void*, int, int*, void*);
};
class Mid_320160 {
    char pad[HULK_D3DCTX_PAD(f_154, 0x154, 0)];

  public:
    Device_320160* dev;
};
extern "C" unsigned int __stdcall FUN_003a8753(int, const char *, int, int, int, int *, int, int, int, int, int);
extern "C" void * __stdcall FUN_003a04fc(int);
extern "C" unsigned int __stdcall FUN_003a41dc(int);
namespace D3D8 {
unsigned int __stdcall D3DDevice_CreatePixelShader(void *, unsigned int);
}
struct SurfaceDesc_320330 {
    unsigned int Format, Type, Usage, Size, MultiSampleType, Width, Height;
};
namespace D3D8 {
int __stdcall D3DDevice_GetRenderTarget2();
}
namespace D3D8 {
void __stdcall D3DSurface_GetDesc(int, SurfaceDesc_320330*);
}
namespace D3D8 {
int __stdcall D3DDevice_CreateTexture2(int, int, int, int, int, unsigned int, int);
}
class Viewport_320330 {
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
struct Parent_320330 {
    char pad[HULK_D3DCTX_PAD(f_154, 0x154, 0)];
    Viewport_320330* viewport;
};
class d3dExtFramebufferEffects_320330 {
  public:
    unsigned char FUN_003202b0(const char* src, int* out);
    void Setup();
    char pad0[4];
    Parent_320330* parent;
    char pad8[0x8c - 8];
    int ps0, ps1, ps2, ps3;
    int pad9c;
    int ps4;
    int pada4;
    int tex2;
    int tex0;
    int tex1;
    unsigned char busy;
    char padb5[0xd0 - 0xb5];
    float scaleX;
    float scaleY;
};
class pddiExtFramebufferEffects_320530 {
  public:
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
};
class pddiExtension_320530 {};
} // namespace fn_f57e27cb
extern "C" char * __cdecl _strncpy(char *, const char *, unsigned int);
namespace fn_f57e27cb {
extern "C++" __declspec(nothrow) int __stdcall FUN_003a8753(int, const char *, int, int, int, void **, int, int, int, int, int);
extern "C++" __declspec(nothrow) void * __stdcall FUN_003a04fc(void *);
namespace D3D8 {
extern "C" int __stdcall D3DDevice_CreatePixelShader(void *, unsigned int *);
}
extern "C++" __declspec(nothrow) void __stdcall FUN_003a41dc(void *);
struct ShaderCollection {
    char padding[36];
    unsigned int shaders[17];
    unsigned char FUN_00320540();
};
struct Frame_320540 {
    void *compiled;
    ShaderCollection *self;
    unsigned int *slot;
    float levels[8];
};
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
extern void FUN_00328be0();
extern void thunk_FUN_00267090(CCollisionAction*);
namespace D3D8 {
struct CreationParameters { unsigned adapter; unsigned deviceType; void* focusWindow; unsigned behaviorFlags; };
}
namespace D3D8 {
extern "C" int __stdcall D3DDevice_GetCreationParameters(CreationParameters*);
}
namespace D3D8 {
extern "C" int __stdcall D3D_CheckDeviceFormat(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
}
extern "C" void* __cdecl FUN_0008d690(unsigned);
// (x64t2) the display (a d3dDisplay: its vftable, then 32-bit words) and the context in gen's d3dContext layout
struct DeviceInfo { void* vftable; char pad[0x428]; unsigned format; };
struct Renderer_320d30 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
 virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
 virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
 virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
 virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
 virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
 virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
 char pad[sizeof(::pure3d::pddiBaseContext) - sizeof(void*)]; int f14c; void* f150; DeviceInfo* device; void* f158; char pad15c[4];
 hulk_intptr f160; int f164[8]; unsigned formats[30]; char pad3[8]; void* object;
 static void FUN_00320c60(); unsigned char FUN_00320d30();   // (x64t2) 0x00320c60 takes no object
};
struct d3dPrimStream_nv_320d30 {
    void* FUN_0031bfa0(Renderer_320d30*);
};
struct Vec3_321310 {
    float x, y, z;
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
extern "C" void FUN_0031ffc0(Color4* self, int id);
namespace D3D8 {
void __stdcall D3DDevice_SetLight(DWORD index, Light8_321310* light);
}
namespace D3D8 {
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
typedef long long QWORD_3214e0;
extern "C" void __stdcall QueryPerformanceCounter(QWORD_3214e0*);
struct Viewport_321520 {
    int x;
    int y;
    int width;
    int height;
};
// (x64t2) the XDK's viewport calls under their own names (were GetViewport / SetViewport: unbound in the native links)
namespace D3D8 {
void __stdcall D3DDevice_GetViewport(Viewport_321520*);
void __stdcall D3DDevice_SetViewport(Viewport_321520*);
}
// the d3dContext (gen's layout: the base, then f_14c..f_168), its viewport at f_16c
class Thing_321520 {
    void* vftable;
    char base[sizeof(::pure3d::pddiBaseContext) - sizeof(void*)];
    int f14c;
    void *f150, *f154, *f158;
    char pad15c[4];
    hulk_intptr f160;
    int f164, f168;

  public:
    Viewport_321520 vp;
    void f(float, float, float, float);
};
struct d3dContext_nv_321860 {
    void fix();
};
class Worker_321860 {
  public:
    int run(int, int, hulk_intptr, int, int);
};
struct Thing_3218b0 {
    void call();
};
struct RTTI {
    char data[1];
};
extern RTTI DAT_004d3c0c, DAT_004d3bec;
extern void* __cdecl FUN_00344e74(void*, int, RTTI*, RTTI*, int);
struct Special_3218c0 {
};
struct Shader_3218c0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9(unsigned, void*);
    virtual void s10();
    virtual int s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual bool s22();
    virtual void s23();
    virtual void s24();
    void FUN_00327d00();
    void FUN_00327d20(int);
};
struct Output_3218c0 {
    void FUN_003272f0();
};
} // namespace fn_f57e27cb
namespace pure3d {
struct d3dContext_nv_3218c0 {
    void FUN_00321310();
};
}
namespace fn_f57e27cb {
typedef unsigned int UINT;
extern void __stdcall D3DDevice_SetRenderState_CullMode(UINT mode);
struct Thing_3219c0 {
    char pad[0x4c];
    void* p;
};
class pddiBaseContext {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a50();
    virtual void a51();
    virtual void a52();
    virtual void a53();
    virtual void a54();
    virtual void a55();
    virtual void a56();
    virtual void a57();
    virtual void a58();
    virtual void a59();
    virtual void a60();
    virtual void a61();
    virtual void a62();
    virtual void a63();
    virtual void v64(int);
    void FUN_0031df80(unsigned char);   // (x64t2) pddiBaseContext::vfunc_58, called directly: named by address
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void v64(int);
};
namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_ZEnable(unsigned int);   // (x64t2) was SetStencilEnable (an invented name)
}
namespace D3D8 {
void __stdcall D3DDevice_SetViewport(void*);
}
typedef unsigned int u32_321c90;
struct d3dContext_nv_321c90 {
    void FUN_0031e0e0(unsigned long);   // (x64t2) pddiBaseContext::vfunc_76, called directly: named by address
};
extern void __stdcall D3DDevice_SetRenderState_FillMode(u32_321c90);
struct Texture_321d40 {
    char pad[0x14];
    void* surface;
};
extern "C" void* __stdcall D3DDevice_GetDepthStencilSurface2();
extern "C" void* __stdcall D3DDevice_GetBackBuffer2(int);
extern "C" void* __stdcall D3DTexture_GetSurfaceLevel2(void*, int);
extern "C" void __stdcall D3DDevice_SetRenderTarget(void*, void*);
extern "C" void __stdcall D3DResource_Release(void*);
} // namespace fn_f57e27cb
namespace pure3d {
class pddiObject_321d90 {};
}
namespace pure3d {
class pddiBaseContext_321d90 : public pddiObject_321d90 {};
}
namespace pure3d {
class pddiRenderContext_321d90 {};
}
namespace fn_f57e27cb {
struct Dest_321da0 {
    int go(int, int, int, int);
};
struct Obj_321da0 {
    char pad[0x208];
    Dest_321da0* member;
    hulk_intptr target(hulk_intptr, int, int, int);
};
struct Entry_321dc0 {
    char padding[0x70];
    int key;
    char padding2[4];
    unsigned char active;
    char padding3[3];
};
struct Entries_321dc0 { int header; Entry_321dc0 entries[8]; };
struct d3dPrimStream_321dc0 {
    char padding[0x50];
    Entries_321dc0 *data;
    unsigned int FUN_00321dc0(int *output, int key);
};
namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_MultiSampleAntiAlias(unsigned int);
}
class D3DDeviceState {
  public:
    char pad[0x44c];
    unsigned char value;
};
class Ref_3220a0 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Block_3220a0 {
    unsigned int x[16];
};
struct Block_3220f0 {
    unsigned int x[16];
};
extern "C" char DAT_0043276c[];
extern "C" char DAT_00433094[];
class RefCounted_322150 {
  public:
    virtual void f0();
    virtual void Release();
};
class d3dExtGlobalProjectedTexture_322150 {
  public:
    void* vftable;
    RefCounted_322150* items[16];
    void f();
};
class pddiExtHardwareSkinning_3221e0 {
  public:
    virtual void vfunc_0();
    virtual unsigned int vfunc_1(unsigned int);
};
namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstantNotInline(int, const void*, int);
}
} // namespace fn_f57e27cb
namespace pure3d {
struct Device_322200 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual unsigned int slot18(int);
};
}
namespace pure3d {
struct Matrix_322200 {
    float m[16];
    void FUN_0022ca90(unsigned int, unsigned int);
    void FUN_0022c0b0();
};
}
namespace fn_f57e27cb {
class pddiExtVisibilityTest_3222c0 {
  public:
    virtual void vfunc_0();
    virtual unsigned int vfunc_1();
};
class pddiExtension_3222c0 {};
typedef unsigned int u32_3222f0;
namespace D3D8 {
int __stdcall D3DDevice_GetVisibilityTestResult(u32_3222f0, u32_3222f0*, u32_3222f0);
}
class d3dExtVisibilityTest_3222f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual u32_3222f0 vfunc_4(u32_3222f0 arg);
};
} // namespace fn_f57e27cb
namespace pure3d {
class NonCopyable_322320 : public ::pure3d::pddiExtVisibilityTest {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_322320* f2(unsigned char);
};
}
namespace fn_f57e27cb {
void thunk_FUN_00267090(pure3d::NonCopyable_322320*);
class d3dExtVertexProgram_322360 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void f4(d3dExtVertexProgram_322360*, char);
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    char pad[0x79];
    u8 flag;
};
class Base_3223a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(unsigned int);
    virtual void f7();
    virtual void f8();
};
struct Data_3223a0 {
    char pad[HULK_D3DCTX_PAD(f_154, 0x154, 0)];
    unsigned int field;
};
struct Inner_3223a0 {
    char pad[0x204];
    Data_3223a0* data;
};
class Base_322400 {
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
    virtual void v21(void*);
};
struct Child_322420 {
};
struct Inner_322420 {
    char pad[0x208];
    Child_322420* child;
};
struct VertexSource {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual unsigned int slot23();
 char padding[0x79];
 unsigned char temporary;
};
struct Device_322440 { void FUN_003290e0(unsigned int, unsigned int, unsigned int, unsigned int); };
struct Context_322440 { char padding[0x208]; Device_322440* device; };
namespace D3D8 {
void __stdcall D3DDevice_DeletePixelShader(DWORD);
}
struct RefObj_322610 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class pddiExtension {
  public:
    virtual ~pddiExtension() throw() {}
};
class d3dExtFramebufferEffects : public pddiExtension {
  public:
    char pad4[4];
    RefObj_322610* objA;
    RefObj_322610* objB;
    char pad0[0x20 - 0x10];
    void* res20;
    DWORD shaders[8][2];
    DWORD shader64;
    char pad1[0xa8 - 0x68];
    void* resA8;
    virtual ~d3dExtFramebufferEffects() throw();
};
struct ThisCall_00322990 {
    void FUN_00322990();
};
struct ThisCall_003226d0 {
    void FUN_003226d0();
};
struct Surface_3226d0 {
    unsigned int common;
};
struct Ctx_3226d0;
struct HeapObj {
    static void* operator new(size_t size) HULK_NEW_THROW;
};
class d3dTexture_3226d0 : public HeapObj {
  public:
    d3dTexture_3226d0(Ctx_3226d0* ctx, int arg) throw();
    virtual void v0();
    void FUN_00326300(Surface_3226d0* s);
    char pad4[0xf8 - 4];
};
class ShaderObj_3226d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void SetTexture(int slot, d3dTexture_3226d0* tex);
    virtual void SetMode(int mode, int on);
};
class Factory_3226d0 {
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
    virtual ShaderObj_3226d0* CreateShader(const char* name, int arg);
};
class Viewport_3226d0 {
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
struct Prim_3226d0 {
    char pad0[8];
    float* pos;
    char padc[4];
    unsigned int* color;
    float* uv;
    void FUN_0008ef00();
};
struct Ctx_3226d0 {
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
    virtual Prim_3226d0* f30(ShaderObj_3226d0*, int, int, int, int);
    virtual void f31(Prim_3226d0*);
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
    char pad4[HULK_D3DCTX_PAD(f_154, 0x154, sizeof(void*))];
    Viewport_3226d0* viewport;
    Factory_3226d0* factory;
};
class Overlay {
  public:
    char pad0[4];
    Ctx_3226d0* ctx;
    ShaderObj_3226d0* shader;
    d3dTexture_3226d0* tex;
    unsigned char enabled;
    char pad11[3];
    float alpha;
    float scale;
    void Draw();
};
struct SurfaceDesc_323910 {
    unsigned int Format, Type, Usage, Size, MultiSampleType, Width, Height;
};
namespace D3D8 {
void __stdcall D3DSurface_GetDesc(int, SurfaceDesc_323910*);
}
class Viewport_323910 {
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
struct Parent_323910 {
    char pad[HULK_D3DCTX_PAD(f_154, 0x154, 0)];
    Viewport_323910* viewport;
};
class d3dExtFramebufferEffects_323910 {
  public:
    bool FUN_00320540();
    void Setup();
    char pad0[4];
    Parent_323910* parent;
    char pad8[0x20 - 8];
    int tex;
    char pad24[0x7c - 0x24];
    unsigned char busy;
    char pad7d[0xd0 - 0x7d];
    float scaleX;
    float scaleY;
};
class Obj_323be0 {
  public:
    virtual void Init();
    Obj_323be0* Create(void*, int);
    void Attach(unsigned int*);
};
unsigned int* __stdcall GetBackBuffer(int);
namespace D3D8 {
struct D3DResource { unsigned flags; };
}
namespace D3D8 {
void __stdcall D3DResource_Release(D3DResource*);
}
struct Texture_323c50 { virtual void vfunc_0(); virtual void vfunc_1(); void FUN_00326300(int); };
struct Matrix_323ee0 {
    float m[16];
};
namespace D3D8 {
void __stdcall D3DDevice_SetTransform(int, const Matrix_323ee0*);
}
extern void __fastcall FUN_0022b980(Matrix_323ee0*);
class Viewport_323ee0 {
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
struct ViewInfo {   // the view state (gen's f_48): its vftable first, then 32-bit words (x64t3: was a 0x10-byte pad)
    void* vftable;
    char pad4[0xc];
    int mode;
    float x0, y0, x1, y1;
    float nearZ, farZ, fov, aspect;
};
struct d3dContext_nv_323ee0 {
    void FUN_00321520(float x, float y, float w, float h);
};
struct Y_324590 {
    void g(int, int, int);
};
struct Y_3245a0 {
};
struct Local_3245d0 {
    unsigned a, b, c;
};
struct Skin_3245d0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9(unsigned, Local_3245d0*);
    virtual void s10();
    virtual int s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual bool s22();
    virtual void s23();
    virtual void s24();
    char pad[0x79];
    unsigned char active;
    void FUN_00327d00();
    void FUN_00327d20(int);
};
struct Device_3245d0 {
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
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(int, Local_3245d0*);
    void FUN_00324270(Skin_3245d0*);
};
struct Receiver_3245d0 {
    void FUN_003272f0();
};
struct Vec3_324660 {
    float x, y, z;
};
struct Vec4_324660 {
    float x, y, z, w;
};
struct Vertex_324660 {
    float x, y, z, rhw, u, v;
};
namespace D3D8 {
void __stdcall D3DDevice_SetVertexShader(int);
}
namespace D3D8 {
void __stdcall D3DDevice_SetPixelShader(int);
}
namespace D3D8 {
void __stdcall D3DDevice_SetPixelShaderConstant(int, const void*, int);
}
namespace D3D8 {
void __stdcall D3DDevice_DrawVerticesUP(int, int, const void*, int);
}
extern float __cdecl FUN_003209f0(float);
extern int __cdecl FUN_00356c30(int);
struct Locals_324660 {
    char pad0[12];
    float dot;
    Vec4_324660 c2;
    float base;
    float scale;
    Vec4_324660 c4;
    float inv;
    Vec4_324660 c1;
    Vec4_324660 c0;
    Vertex_324660 verts[4];
};
class FilterPass {
  public:
    char pad0[0x20];
    int texture;
    int shaders[17];
    void Draw(const Vec3_324660* a, float f1, float f2, const Vec3_324660* b, float f3, float f4, int w, int h, float u, float v);
};

} // namespace fn_f57e27cb

// 0x00320160 pure3d::d3dExtReadPixels::vfunc_1 (58 B): matches/0x00320160.cpp
// sym: ?vfunc_1@d3dExtReadPixels@pure3d@@UAEXPAX00@Z
void pure3d::d3dExtReadPixels::vfunc_1(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; int * r = (int *)__p1; void * c = (void *)__p2;

    Device_320160* d = (*(Mid_320160 * *)&this->f_04)->dev;
    d->Read(c, (r[3] - r[1]) * (r[2] - r[0]) * 4, r, a);
}


// 0x003201b0 pure3d::pddiExtHardwareSkinning::vfunc_0 (31 B): matches/0x003201b0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_003201b0@@UAEPAV123@E@Z
namespace fn_003201b0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtension_3201b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtension_3201b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_003201b0


// 0x003201e0 pure3d::pddiExtVisibilityTest::vfunc_0 (31 B): matches/0x003201e0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_003201e0@@UAEPAV123@E@Z
namespace fn_003201e0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtension_3201e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtension_3201e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_003201e0


// 0x00320210 pure3d::pddiExtVertexProgram::vfunc_0 (31 B): matches/0x00320210.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00320210@@UAEPAV123@E@Z
namespace fn_00320210 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtension_320210 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtension_320210 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00320210


// 0x00320240 pure3d::pddiExtFramebufferEffects::vfunc_0 (31 B): matches/0x00320240.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00320240@@UAEPAV123@E@Z
namespace fn_00320240 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtension_320240 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtension_320240 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00320240


// 0x00320290 pure3d::d3dExtFramebufferEffects::vfunc_7 (13 B): matches/0x00320290.cpp
// sym: ?vfunc_7@d3dExtFramebufferEffects@pure3d@@UAEXE@Z
void pure3d::d3dExtFramebufferEffects::vfunc_7(unsigned char value) {
    this->f_ec = value;
}

// 0x003202a0 pure3d::d3dExtFramebufferEffects::vfunc_5 (5 B): not yet verified
namespace fn_f57e27cb {

// 0x003202b0 FUN_003202b0 (114 B): equivalent/0x003202b0.cpp
// sym: ?FUN_003202b0@fn_f57e27cb@@YG_NPBDI@Z @de6eace05f27 @w75309eb6b2dc
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_003202b0 @ 0x003202b0
bool __stdcall FUN_003202b0(const char *source, unsigned int shader)
{
    int buffer = 0;
    const char *end = source;
    while (*end) ++end;
    unsigned int result = FUN_003a8753(0, source, (int)(end - source), 0, 0, &buffer, 0, 0, 0, 0, 0);
    bool success = (result == 0);
    if (buffer) {
        void *code = FUN_003a04fc(buffer);
        D3D8::D3DDevice_CreatePixelShader(code, shader);
        FUN_003a41dc(buffer);
    }
    return success;
}


// 0x00320330 FUN_00320330 (506 B): equivalent/0x00320330.cpp
// sym: ?Setup@d3dExtFramebufferEffects_320330@fn_f57e27cb@@QAEXXZ @ab1f723ee121 @w669a48675edd
// STATUS: equivalent (tools/equiv.py level 3: 20053 inputs, branch coverage 16/16)
// FUN_00320330 @ 0x00320330
void d3dExtFramebufferEffects_320330::Setup() {
    if (tex0 != 0)
        return;
    if (busy)
        return;
    busy = 1;
    unsigned char ok = FUN_003202b0("    ps.1.1 \n    tex t0 \n    mul r0, t0, c0 \n", &ps0) & 1;
    ok &= FUN_003202b0("    ps.1.1 \n    tex t0 \n    tex t1 \n    mul r0, t0, c0 \n    mad r0, t1, c1, r0 \n", &ps1);
    ok &= FUN_003202b0("    ps.1.1 \n    tex t0 \n    tex t1 \n    tex t2 \n    mul r0, t0, c0 \n    mad r0, t1, c1, r0 \n    mad r0, t2, c2, r0 \n", &ps2);
    ok &= FUN_003202b0("    ps.1.1 \n    tex t0 \n    tex t1 \n    tex t2 \n    tex t3 \n    mul r0, t0, c0 \n    mad r0, t1, c1, r0 \n    mad r0, t2, c2, r0 \n    mad r0, t3, c3, r0 \n", &ps3);
    ok &= FUN_003202b0("    ps.1.1 \n    tex t0 \n    tex t1 \n    mul_x2 r0, t0, c0 \n    mad r0, t1, c1, r0 \n", &ps4);
    unsigned char last = ok;
    if (!(ok & last))
        return;
    int rt = D3D8::D3DDevice_GetRenderTarget2();
    SurfaceDesc_320330 desc;
    D3D8::D3DSurface_GetDesc(rt, &desc);
    D3D8::D3DResource_Release(rt);
    scaleX = (float)parent->viewport->GetWidth() / (float)desc.Width;
    scaleY = (float)parent->viewport->GetHeight() / (float)desc.Height;
    Viewport_320330* vp = parent->viewport;
    int h = vp->GetHeight() / 4;
    int w = vp->GetWidth() / 4;
    tex0 = D3D8::D3DDevice_CreateTexture2(w, h, 1, 1, 0, desc.Format, 3);
    if (!tex0)
        return;
    vp = parent->viewport;
    h = vp->GetHeight() / 4;
    w = vp->GetWidth() / 4;
    tex1 = D3D8::D3DDevice_CreateTexture2(w, h, 1, 1, 0, desc.Format, 3);
    if (!tex1)
        return;
    vp = parent->viewport;
    h = vp->GetHeight() / 2;
    w = vp->GetWidth() / 2;
    tex2 = D3D8::D3DDevice_CreateTexture2(w, h, 1, 1, 0, desc.Format, 3);
    if (!tex2)
        return;
    busy = 0;
}

} // namespace fn_f57e27cb

// 0x00320530 pure3d::d3dExtFramebufferEffects::vfunc_3 (10 B): matches/0x00320530.cpp
// sym: ?vfunc_3@d3dExtFramebufferEffects@pure3d@@UAEXE@Z
void pure3d::d3dExtFramebufferEffects::vfunc_3(unsigned char value) {
    (*(char (*)[122])&this->f_04)[0x79] = value;
}

namespace fn_f57e27cb {

// 0x00320540 FUN_00320540 (1199 B): equivalent/0x00320540.cpp
// sym: ?FUN_00320540@ShaderCollection@fn_f57e27cb@@QAEEXZ @1efd85545c63 @wa9ce024a26c3
// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 73/74, incomplete)
// FUN_00320540 @ 0x00320540
unsigned char ShaderCollection::FUN_00320540() {
    Frame_320540 f;
    f.self = this;
    f.levels[0] = 1.0f; f.levels[1] = 2.0f; f.levels[2] = 4.0f; f.levels[3] = 8.0f;
    f.levels[4] = 16.0f; f.levels[5] = 32.0f; f.levels[6] = 64.0f; f.levels[7] = 255.0f;
    const char *const add = "add     r0.xyz, r0.xyz, r1.w \n";
    const char *const doubleAlpha = "+mov_x2 r1.w,   r1.w \n";
    unsigned char succeeded = 1;

    for (int level = 0; level < 8; ++level) {
        for (int pass = 0; pass < (level == 7 ? 1 : 2); ++pass) {
            char source[1024] = {0};
            if (level == 7) {
                f.slot = &f.self->shaders[16];
                _strncpy(source, ((char*)&DAT_00432da0), 1023);
            } else {
                f.slot = &f.self->shaders[level * 2 + pass];
                const char *parts[24];
                int partCount = 0;
                parts[partCount++] = "xps.1.1 \n";
                parts[partCount++] = "def     c1, 0.5, 0.5, 0.5, 0.5 \n";
                parts[partCount++] = "tex     t0 \n";
                parts[partCount++] = "dp3     r0,     t0, c0 \n";
                parts[partCount++] = "add     r0.xyz, t0, -r0 \n";
                parts[partCount++] = "+mad    r1.w,   r0.w, c5, c3_bx2 \n";
                parts[partCount++] = "mul_x2  r0.xyz, r0, c7 \n";
                if (f.levels[level] >= 32.0f)
                    parts[partCount++] = "+mov_x4 r1.w,   r1.w \n";
                else if (f.levels[level] >= 16.0f)
                    parts[partCount++] = doubleAlpha;
                parts[partCount++] = "mad     r0.xyz, c6_bx2, r0.w, r0 \n";
                if (f.levels[level] == 64.0f)
                    parts[partCount++] = doubleAlpha;
                parts[partCount++] = add;

                if (pass == 0) {
                    if (f.levels[level] > 1.0f) {
                        parts[partCount++] = add;
                        if (f.levels[level] > 2.0f) {
                            parts[partCount++] = doubleAlpha;
                            parts[partCount++] = add;
                            if (f.levels[level] > 4.0f) {
                                parts[partCount++] = doubleAlpha;
                                parts[partCount++] = add;
                            }
                        }
                    }
                } else {
                    parts[partCount++] = add;
                    if (f.levels[level] > 1.0f) {
                        parts[partCount++] = doubleAlpha;
                        parts[partCount++] = add;
                        if (f.levels[level] > 2.0f) {
                            parts[partCount++] = doubleAlpha;
                            parts[partCount++] = add;
                        }
                    }
                }

                char *end = source;
                for (int part = 0; part < partCount; ++part) {
                    const char *text = parts[part];
                    while (*text)
                        *end++ = *text++;
                }
            }

            int length = 0;
            while (source[length])
                ++length;
            f.compiled = 0;
            int result = FUN_003a8753(0, source, length, 0, 0, &f.compiled, 0, 0, 0, 0, 0);
            succeeded &= result == 0;
            if (f.compiled) {
                void *shader = FUN_003a04fc(f.compiled);
                D3D8::D3DDevice_CreatePixelShader(shader, f.slot);
                FUN_003a41dc(f.compiled);
            }
        }
    }
    return succeeded;
}

} // namespace fn_f57e27cb

// 0x003209f0 FUN_003209f0 (175 B): matches/0x003209f0.cpp [wrapped: compile error C2732: linkage specification contradicts earlier specification for 'fn_f57e27cb::FUN_003209f0']
// sym: _FUN_003209f0
namespace fn_003209f0 {

extern "C" float FUN_003209f0(float x) {
    if (x <= DAT_003f32dc)
        return DAT_003f32dc;
    if (x <= DAT_003f5cf8)
        return DAT_003f5cf8;
    if (x <= DAT_003f3318)
        return DAT_003f3318;
    if (x <= DAT_003f5cd4)
        return DAT_003f5cd4;
    if (x <= DAT_003ff9e8)
        return DAT_003ff9e8;
    if (x <= DAT_0041d804)
        return DAT_0041d804;
    if (x <= DAT_0041d87c)
        return DAT_0041d87c;
    return DAT_00409000;
}
} // namespace fn_003209f0


// 0x00320aa0 FUN_00320aa0 (179 B): matches/0x00320aa0.cpp [wrapped: conflict: D3D8::D3DDevice_GetRenderTarget2]
// sym: ?FUN_00320aa0@fn_00320aa0@@YGXPAUTexture@1@@Z
namespace fn_00320aa0 {
typedef unsigned long DWORD;
struct SurfaceDesc_320aa0 {
    DWORD Format, Type, Usage, Size, MultiSampleType, Width, Height;
};
struct Rect_320aa0 {
    long left, top, right, bottom;
};
struct Texture;
struct Surface;
namespace D3D8 {
void __stdcall D3DResource_AddRef(Texture*);
void __stdcall D3DResource_Release(void*);
Surface* __stdcall D3DTexture_GetSurfaceLevel2(Texture*, DWORD);
void __stdcall D3DSurface_GetDesc(Surface*, SurfaceDesc_320aa0*);
Surface* __stdcall D3DDevice_GetRenderTarget2();
void __stdcall D3DDevice_CopyRects(Surface*, Rect_320aa0*, DWORD, Surface*, void*);
} // namespace D3D8
extern "C" void __cdecl FUN_0031c230(int);
void __stdcall FUN_00320aa0(Texture* tex) {
    if (!tex)
        return;
    D3D8::D3DResource_AddRef(tex);
    Surface* src = D3D8::D3DTexture_GetSurfaceLevel2(tex, 0);
    FUN_0031c230((long)(src ? 0 : 0x8007000e));
    SurfaceDesc_320aa0 desc;
    D3D8::D3DSurface_GetDesc(src, &desc);
    FUN_0031c230(0);
    Rect_320aa0 r;
    r.left = 0;
    r.top = 0;
    r.right = desc.Width;
    r.bottom = desc.Height;
    Surface* rt = D3D8::D3DDevice_GetRenderTarget2();
    FUN_0031c230(0);
    D3D8::D3DDevice_CopyRects(rt, &r, 1, src, 0);
    FUN_0031c230(0);
    D3D8::D3DResource_Release(rt);
    D3D8::D3DResource_Release(src);
    D3D8::D3DResource_Release(tex);
}
} // namespace fn_00320aa0


// 0x00320b70 pure3d::pddiExtFrameBufferTexture::vfunc_0 (31 B): matches/0x00320b70.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00320b70@@UAEPAV123@E@Z
namespace fn_00320b70 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtension_320b70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtension_320b70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00320b70

namespace fn_f57e27cb {

// 0x00320b90 FUN_00320b90 (30 B): matches/0x00320b90.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f57e27cb@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_00328be0();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f57e27cb

// 0x00320bb0 FUN_00320bb0 (30 B): matches/0x00320bb0.cpp [wrapped: same definition as 0x00320b90 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_00320bb0@@UAEPAV12@E@Z
namespace fn_00320bb0 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_00329400 {
    void FUN_00329400();
};
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_00329400*)(this))->FUN_00329400();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00320bb0


// 0x00320bd0 FUN_00320bd0 (30 B): matches/0x00320bd0.cpp [wrapped: same definition as 0x00320b90 in this TU]
// sym: ?vfunc_2@CCollisionAction@fn_00320bd0@@UAEPAV12@E@Z
namespace fn_00320bd0 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
extern void __fastcall FUN_0031bcf0(void*);
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_0031bcf0((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00320bd0


// 0x00320c60 FUN_00320c60 (160 B): matches/0x00320c60.cpp [wrapped: compile error C2668: 'fn_f57e27cb::D3D8::D3DDevice_SetRenderState_Simple' : ambiguous call to overloaded function]
// sym: ?FUN_00320c60@fn_00320c60@@YAXXZ
namespace fn_00320c60 {
struct Matrix {
    float m[16];
};
namespace D3D8 {
void __stdcall D3DDevice_SetTransform(int, const Matrix*);
void __fastcall D3DDevice_SetRenderState_Simple(unsigned long, unsigned long);
void __stdcall D3DDevice_SetRenderState_TextureFactor(unsigned long);
} // namespace D3D8
extern void __fastcall FUN_0022b980(Matrix*);
extern unsigned int DAT_0039db08;
extern int DAT_0039de14;
extern int DAT_0039deb4;
extern int DAT_0039deb8;
extern int DAT_0039debc;
extern int DAT_0039dec0;
extern int DAT_0039dec4;
extern int DAT_0039dec8;
extern int DAT_0039decc;
extern int DAT_0039ded0;
extern int DAT_0039ded4;
void FUN_00320c60() {
    Matrix identity;
    FUN_0022b980(&identity);
    D3D8::D3DDevice_SetTransform(0, &identity);
    D3D8::D3DDevice_SetTransform(6, &identity);
    D3D8::D3DDevice_SetTransform(1, &identity);
    D3D8::D3DDevice_SetRenderState_Simple(0x40310, 1);
    DAT_0039de14 = 1;
    D3D8::D3DDevice_SetRenderState_TextureFactor(0xffffffff);
    unsigned int flags = DAT_0039db08 | 0x1000;
    DAT_0039decc = 0;
    DAT_0039dec8 = 0;
    DAT_0039ded0 = 0;
    DAT_0039ded4 = 0;
    DAT_0039debc = 0;
    DAT_0039deb8 = 0;
    DAT_0039dec0 = 0;
    DAT_0039dec4 = 0;
    DAT_0039deb4 = 1;
    DAT_0039db08 = flags;
}
} // namespace fn_00320c60


// 0x00320d00 FUN_00320d00 (48 B): matches/0x00320d00.cpp
// sym: ?FUN_00320d00@Holder_320d00@owners@@QAE_NH@Z
bool owners::Holder_320d00::FUN_00320d00(int value) {
    int i = 0;
    int* p = (int*)((char*)this + 0x184);
    do {
        int x = *p;
        if (x == -1)
            return false;
        if (x == value)
            return true;
        ++i;
        ++p;
    } while (i < 0x20);
    return false;
}

namespace fn_f57e27cb {

// 0x00320d30 FUN_00320d30 (1359 B): equivalent/0x00320d30.cpp
// sym: ?FUN_00320d30@Renderer_320d30@fn_f57e27cb@@QAEEXZ @63b29412881b @w14bc8bc889e3
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 58/58)
// FUN_00320d30 @ 0x00320d30
unsigned char Renderer_320d30::FUN_00320d30() {
 D3D8::CreationParameters p;
 D3D8::D3DDevice_GetCreationParameters(&p);
 unsigned format = device->format;
 const unsigned candidates[] = {6,7,5,3,2,4,0x19,0xb,0,0x1a,0x28,0x27,7,0x3a,0x33,0x25,0x24,0xc,0xe,0xe,0xf,0xf,0x11,0x10,0x1d,0x1e,0x12,0x12};
 unsigned count=0;
 unsigned deviceType=p.deviceType;
 for (unsigned i=0;i<28;++i) {
   unsigned candidate=candidates[i];
   if (D3D8::D3D_CheckDeviceFormat(p.adapter,deviceType,format,0,3,candidate)==0) {
     formats[count]=candidate;
     formats[count+1]=0xffffffff;
     if (i!=27) ++count;
   }
 }
 ::pure3d::d3dPrimStream* allocated=(::pure3d::d3dPrimStream*)FUN_0008d690((int)sizeof(::pure3d::d3dPrimStream));
 object=allocated ? ((d3dPrimStream_nv_320d30*)(((::pure3d::d3dPrimStream*)(allocated))))->FUN_0031bfa0(this) : 0;
 v99();
 FUN_00320c60();
 return 1;
}

} // namespace fn_f57e27cb

// 0x00321280 pure3d::d3dContext::vfunc_5 (62 B): matches/0x00321280.cpp [wrapped: conflict: d3dContext]
// sym: ?vfunc_5@d3dContext@fn_00321280@@UAEXXZ
namespace fn_00321280 {
namespace D3D8 {
void __stdcall D3DDevice_SetTexture(unsigned int stage, int texture);
void __stdcall D3DDevice_SetPalette(unsigned int stage, int palette);
} // namespace D3D8
void FUN_00327dd0();   // (x64t3) the shader state reset (pddiBaseShader.cpp), a free function: by address (was `Init`,
                       // a member of a fake object, unbound)
class pddiBaseContext {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    void FUN_0031d4c0();   // (x64t3) pddiBaseContext::vfunc_5, called directly: by address (its local name was unbound)
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void vfunc_5();
    char pad[HULK_D3DCTX_PAD(f_150, 0x150, sizeof(void*))];
    struct D {
        int a, b, c[4];
    }* data;
};
void d3dContext::vfunc_5() {
    FUN_00327dd0();
    D* d = data;
    for (unsigned int i = 0; i < 4; ++i) {
        d->c[i] = 0;
        D3D8::D3DDevice_SetTexture(i, 0);
        D3D8::D3DDevice_SetPalette(i, 0);
    }
    FUN_0031d4c0();
}
} // namespace fn_00321280

namespace fn_f57e27cb {

// 0x003212c0 pure3d::d3dContext::vfunc_91 (1 B): matches/0x003212c0.cpp
// sym: ?FUN_003212c0@fn_f57e27cb@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_003212c0() {}

} // namespace fn_f57e27cb

// 0x003212d0 pure3d::d3dContext::vfunc_110 (62 B): matches/0x003212d0.cpp [wrapped: conflict: pure3d::d3dContext]
// sym: ?vfunc_110@d3dContext@pure3d@fn_003212d0@@QAEXHD@Z
namespace fn_003212d0 {
namespace pure3d {
struct Block_3212d0 {
    unsigned int v[16];
};
class d3dContext {
  public:
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
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual Block_3212d0* f20();
    char pad[0x414 - 4];
    void vfunc_110(int n, char b);
};
void d3dContext::vfunc_110(int n, char b) {
    char* p = (char*)this;
    p[0x414] = 1;
    p[n + 0x40c] = 1;
    if (b) {
        Block_3212d0* s = f20();
        Block_3212d0* d = (Block_3212d0*)(p + n * 0x40 + 0x20c);
        *d = *s;
    }
}
} // namespace pure3d
} // namespace fn_003212d0

namespace fn_f57e27cb {

// 0x00321310 FUN_00321310 (435 B): equivalent/0x00321310.cpp
// sym: ?FUN_00321310@LightingState@fn_f57e27cb@@QAEXXZ @6c17fa216213 @w56d78f954c1d
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_00321310 @ 0x00321310
// equiv-conv: FUN_0031ffc0 ecx stack
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
        ((owners::C_22d290 *)&dir)->FUN_0022d290((hulk_intptr)(Vec3_321310 *)(&src->direction), (hulk_intptr)(&matrices[i]));
        Vec3_321310 pos;
        ((owners::C_22d240 *)&pos)->FUN_0022d240((hulk_intptr)(Vec3_321310 *)(&src->position), (hulk_intptr)(&matrices[i]));
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

} // namespace fn_f57e27cb

// 0x003214d0 pure3d::d3dContext::vfunc_106 (13 B): matches/0x003214d0.cpp [wrapped: conflict: d3dContext]
// sym: ?vfunc_106@d3dContext@fn_003214d0@@QAEXXZ
namespace fn_003214d0 {
typedef long long LARGE_INTEGER;
namespace XAPILIB {
void __stdcall QueryPerformanceCounter(LARGE_INTEGER*);
}
class d3dContext {
  public:
    char pad[0x418];
    void vfunc_106();
};
void d3dContext::vfunc_106() {
    XAPILIB::QueryPerformanceCounter((LARGE_INTEGER*)(pad + 0x418));
}
} // namespace fn_003214d0


// 0x003214e0 pure3d::d3dContext::vfunc_107 (63 B): matches/0x003214e0.cpp
// sym: ?vfunc_107@d3dContext@pure3d@@UAEMXZ
hulk_freg pure3d::d3dContext::vfunc_107() {
    QWORD_3214e0 q;
    QueryPerformanceCounter(&q);
    return (hulk_freg)(q - (*(QWORD_3214e0 *)&this->f_418)) * this->f_420;
}

namespace fn_f57e27cb {

// 0x00321520 FUN_00321520 (83 B): matches/0x00321520.cpp
// sym: ?f@Thing_321520@fn_f57e27cb@@QAEXMMMM@Z
void Thing_321520::f(float a, float b, float c, float d) {
    D3D8::D3DDevice_GetViewport(&vp);
    vp.x = (int)a;
    vp.y = (int)b;
    vp.width = (int)c;
    vp.height = (int)d;
    D3D8::D3DDevice_SetViewport(&vp);
}

} // namespace fn_f57e27cb

// 0x00321580 pure3d::d3dContext::vfunc_12 (726 B): equivalent/0x00321580.cpp [wrapped: conflict: pure3d::d3dContext; pure3d::pddiBaseContext]
// sym: ?vfunc_12@d3dContext@pure3d@fn_00321580@@UAEXI@Z @ad2e0d0f58bb @w59920f24a1e0
namespace fn_00321580 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/32, incomplete)
// pure3d::d3dContext::vfunc_12 @ 0x00321580
struct Matrix { float m[16]; };
namespace D3D8 {
void __stdcall D3DDevice_Clear(int, int, int, int, int, int);
}
extern "C" void __cdecl FUN_0031c230(int);
extern void __fastcall FUN_0022b980(Matrix*);
struct Prim_321580 {
    char pad0[8];
    float* pos;
    char padc[4];
    int* color;
    void FUN_0008ef00();
};
struct ClearInfo {
    char pad0[4];
    int color;
    int depth;
    int stencil;
    char pad10[0x28 - 0x10];
    float z;
};
class FlagSource {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual unsigned int GetClearFlags();
};
namespace pure3d {
class pddiBaseContext {
  public:
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
    virtual void vfunc_12(unsigned int);
    virtual void f13();
    virtual void f14(int, const Matrix*);
    virtual void f15(int);
    virtual void f16(int);
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
    virtual void f29();
    virtual Prim_321580* f30(int, int, int, int, int);
    virtual void f31(Prim_321580*);
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
    virtual void f58();
    virtual void f59();
    virtual void f60(int);
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87(int);
    virtual void f88(int);
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void vfunc_12(unsigned int flags);
    char pad4[0x48 - 4];
    ClearInfo* clear;
    char pad4c[0x154 - 0x4c];
    FlagSource* source;
    char pad158[0x16c - 0x158];
    unsigned int x, y, w, h;
    char pad17c[0x44c - 0x17c];
    unsigned char hasTarget;
};
void d3dContext::vfunc_12(unsigned int flags) {
    pddiBaseContext::vfunc_12(flags);
    if (hasTarget) {
        Matrix identity;
        FUN_0022b980(&identity);
        f15(0);
        f14(0, &identity);
        f87(2);
        f87(1);
        f87(0x10);
        f24(2);
        f60(1);
        Prim_321580* p = f30(0, 1, 0x2020, 4, 0);
        *p->color = clear->color;
        p->pos[0] = (float)x;
        p->pos[1] = (float)y;
        p->pos[2] = clear->z;
        p->FUN_0008ef00();
        *p->color = clear->color;
        p->pos[0] = (float)w + (float)x;
        p->pos[1] = (float)y;
        p->pos[2] = clear->z;
        p->FUN_0008ef00();
        *p->color = clear->color;
        p->pos[0] = (float)x;
        p->pos[1] = (float)h + (float)y;
        p->pos[2] = clear->z;
        p->FUN_0008ef00();
        *p->color = clear->color;
        p->pos[0] = (float)w + (float)x;
        p->pos[1] = (float)h + (float)y;
        p->pos[2] = clear->z;
        p->FUN_0008ef00();
        f31(p);
        f88(2);
        f88(1);
        f88(0x10);
        f16(0);
    } else {
        int bits = 0;
        flags &= source->GetClearFlags();
        if (flags & 1)
            bits = 0xf0;
        if (flags & 2)
            bits |= 1;
        if (flags & 4)
            bits |= 2;
        ClearInfo* c = clear;
        D3D8::D3DDevice_Clear(0, 0, bits, c->color, c->depth, c->stencil);
        FUN_0031c230(0);
    }
}
}
} // namespace fn_00321580


// 0x00321860 pure3d::d3dContext::vfunc_30 (78 B): matches/0x00321860.cpp
// sym: ?vfunc_30@d3dContext@pure3d@@UAEPAXHHHHH@Z
void* pure3d::d3dContext::vfunc_30(hulk_intptr a, int b, int c, int d, int e) {
    if (!a)
        a = this->f_160;
    if (this->f_414)
        ((d3dContext_nv_321860*)this)->fix();
    ((Worker_321860*)this->f_204)->run(b, c, a, d, e);
    return this->f_204;   // (x64t3) the prim stream (gen's slot returned int: truncated on 64-bit)
}


// 0x003218b0 pure3d::d3dContext::vfunc_31 (14 B): matches/0x003218b0.cpp
// sym: ?vfunc_31@d3dContext@pure3d@@UAEXH@Z
void pure3d::d3dContext::vfunc_31(int ) {
    ((Thing_3218b0*)(*(char**)((char*)this + 0x204)))->call();
}


// 0x003218c0 pure3d::d3dContext::vfunc_32 (195 B): matches/0x003218c0.cpp
// sym: ?vfunc_32@d3dContext@pure3d@@UAEXHH@Z
 // namespace pure3d
void pure3d::d3dContext::vfunc_32(hulk_intptr __p0, hulk_intptr __p1) { Shader_3218c0 * shader = (Shader_3218c0 *)__p0; Output_3218c0 * output = (Output_3218c0 *)__p1;

    Special_3218c0* special = (Special_3218c0*)FUN_00344e74(shader, 0, &DAT_004d3bec, &DAT_004d3c0c, 0);
    if (special) {
        ((owners::AccumulatorSource_3285d0 *)special)->FUN_003285d0(0);
        return;
    }
    if (!shader)
        shader = (*(Shader_3218c0 * *)&this->f_160);
    if ((*(bool *)&this->f_414))
        ((d3dContext_nv_3218c0*)this)->FUN_00321310();
    unsigned values[3];
    vfunc_47(0, values);
    shader->s9(0x5654494c, values);
    if (shader->s22())
        shader->s24();
    int i = 0;
    if (shader->s11() > 0) {
        do {
            shader->FUN_00327d00();
            shader->FUN_00327d20(i);
            output->FUN_003272f0();
            ++i;
        } while (i < shader->s11());
    }
}


// 0x00321990 pure3d::d3dContext::vfunc_35 (42 B): matches/0x00321990.cpp [wrapped: conflict: d3dContext]
// sym: ?vfunc_35@d3dContext@fn_00321990@@UAEXPAX@Z
namespace fn_00321990 {
typedef unsigned int u32_321990;
extern volatile u32_321990 state;
extern volatile void* globalA;
extern volatile void* globalB;
class pddiBaseContext {
  public:
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
    virtual void f13();
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
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void vfunc_35(void*);
    // (x64t2) the base pddiBaseContext::vfunc_35 (0x0031d910), called directly: named by address for the native link
    void FUN_0031d910(int);   // (the definition's int: the ambient colour gen's signature passes as a pointer)
};
class d3dContext : public pddiBaseContext {
  public:
    void vfunc_35(void*);
};
void d3dContext::vfunc_35(void* p) {
    FUN_0031d910((int)(hulk_intptr)p);
    globalA = p;
    globalB = p;
    state |= 0x1000;
}
} // namespace fn_00321990

namespace fn_f57e27cb {

// 0x003219c0 FUN_003219c0 (20 B): matches/0x003219c0.cpp
// sym: ?FUN_003219c0@fn_f57e27cb@@YIXPAUThing_3219c0@1@@Z
// data: gValues_3219c0 = DAT_004d3a48
void __fastcall FUN_003219c0(Thing_3219c0* self) {
    D3DDevice_SetRenderState_CullMode(((UINT*)&DAT_004d3a48)[*((UINT*)((char*)self->p + 4))]);
}

} // namespace fn_f57e27cb

// 0x003219f0 pure3d::d3dContext::vfunc_54 (53 B): matches/0x003219f0.cpp [wrapped: conflict: pure3d::d3dContext; pure3d::pddiBaseContext]
// sym: ?vfunc_54@d3dContext@pure3d@fn_003219f0@@UAEXH@Z
namespace fn_003219f0 {

namespace pure3d {
class pddiBaseContext {
  public:
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
    virtual void f13();
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
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
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
    virtual void vfunc_54(int);
    void FUN_0031def0(int);   // pddiBaseContext::vfunc_54, called directly: named by address for the native link
};
// (x64t2) the context in gen's layout up to its state cache f_150 (owners::State_328f10)
class d3dContext : public pddiBaseContext {
  public:
    char pad[sizeof(::pure3d::pddiBaseContext) + sizeof(int) - sizeof(pddiBaseContext)];
    owners::State_328f10* state;
    void vfunc_54(int);
};
} // namespace pure3d
void __stdcall D3DDevice_SetRenderState_CullMode(int);
void pure3d::d3dContext::vfunc_54(int x) {
    FUN_0031def0(x);
    if (!state->flag105)
        D3DDevice_SetRenderState_CullMode(((int*)&DAT_004d3a48)[x]);
}
} // namespace fn_003219f0


// 0x00321a30 pure3d::d3dContext::vfunc_56 (100 B): matches/0x00321a30.cpp [wrapped: conflict: pure3d::d3dContext; pure3d::pddiBaseContext]
// sym: ?vfunc_56@d3dContext@pure3d@fn_00321a30@@UAEXDDDD@Z
namespace fn_00321a30 {
namespace pure3d {
class pddiBaseContext {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void aa();
    virtual void ab();
    virtual void ac();
    virtual void ad();
    virtual void ae();
    virtual void af();
    virtual void ag();
    virtual void ah();
    virtual void ai();
    virtual void aj();
    virtual void ak();
    virtual void al();
    virtual void am();
    virtual void an();
    virtual void ao();
    virtual void ap();
    virtual void aq();
    virtual void ar();
    virtual void as();
    virtual void at();
    virtual void au();
    virtual void av();
    virtual void aw();
    virtual void ax();
    virtual void ay();
    virtual void az();
    virtual void ba();
    virtual void bb();
    virtual void bc();
    virtual void bd();
    virtual void be();
    virtual void bf();
    virtual void vfunc_56(char, char, char, char);
    // (x64t2) the base pddiBaseContext::vfunc_56 (0x0031df10), called directly: named by address for the native link
    void FUN_0031df10(char, char, char, char);
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void c48();
    virtual void c49();
    virtual void c50();
    virtual void c51();
    virtual void c52();
    virtual void c53();
    virtual void c54();
    virtual void c55();
    virtual void vfunc_56(char, char, char, char);
};
} // namespace pure3d
extern void __fastcall D3DDevice_SetRenderState_Simple(int, int);   // (x64t2) was D3D8_D3DDevice_... (unbound)
extern int gRender;
void pure3d::d3dContext::vfunc_56(char a, char b, char c, char d) {
    FUN_0031df10(a, b, c, d);
    int bits = 0;
    if (a)
        bits |= 0x10000;
    if (b)
        bits |= 0x100;
    if (c)
        bits |= 1;
    if (d)
        bits |= 0x1000000;
    D3DDevice_SetRenderState_Simple(0x40358, bits);
    gRender = bits;
}
} // namespace fn_00321a30

namespace fn_f57e27cb {

// 0x00321aa0 pure3d::d3dContext::vfunc_58 (24 B): matches/0x00321aa0.cpp
// sym: ?v64@d3dContext@fn_f57e27cb@@UAEXH@Z
// Same code shape as 0x00321b50 (propagated; names are from that function)
void d3dContext::v64(int b) {
    FUN_0031df80((unsigned char)b);
    D3D8::D3DDevice_SetRenderState_ZEnable((unsigned char)b);
}

} // namespace fn_f57e27cb

// 0x00321ac0 pure3d::d3dContext::vfunc_60 (40 B): matches/0x00321ac0.cpp [wrapped: conflict: d3dContext]
// sym: ?vfunc_60@d3dContext@fn_00321ac0@@QAEXH@Z
namespace fn_00321ac0 {

class pddiBaseContext {
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
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60(int);
    // (x64t2) the base pddiBaseContext::vfunc_60 (0x0031dfa0), called directly: named by address for the native link
    void FUN_0031dfa0(int);
};
class d3dContext : public pddiBaseContext {
  public:
    void vfunc_60(int);
};
extern unsigned int globalState_321ac0;
void __fastcall D3DDevice_SetRenderState_Simple(unsigned int, unsigned int);
void d3dContext::vfunc_60(int x) {
    FUN_0031dfa0(x);
    unsigned int v = *(unsigned int*)(((hulk_intptr)((char*)&DAT_004d3a6c)) + x * 4);
    D3DDevice_SetRenderState_Simple(0x40354, v);
    globalState_321ac0 = v;
}
} // namespace fn_00321ac0


// 0x00321af0 pure3d::d3dContext::vfunc_62 (38 B): matches/0x00321af0.cpp [wrapped: conflict: pure3d::d3dContext; pure3d::pddiBaseContext]
// sym: ?vfunc_62@d3dContext@pure3d@fn_00321af0@@UAEXI@Z
namespace fn_00321af0 {
typedef unsigned int u32_321af0;
typedef unsigned char u8;
namespace pure3d {
class pddiBaseContext {
  public:
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
    virtual void f13();
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
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
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
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void vfunc_62(u32_321af0);
    // (x64t2) the base pddiBaseContext::vfunc_62 (0x0031dfc0), called directly: named by address for the native link
    void FUN_0031dfc0(u8);
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void g63();
    void vfunc_62(u32_321af0);
};
extern int state;
void __fastcall D3DDevice_SetRenderState_Simple(u32_321af0, u32_321af0);
void d3dContext::vfunc_62(u32_321af0 value) {
    FUN_0031dfc0((u8)value);
    u32_321af0 v = (u8)value;
    D3DDevice_SetRenderState_Simple(0x4035c, v);   // (x64t2) was a fastcall member of a fake object at 0x4035c
    state = v;
}
} // namespace pure3d
} // namespace fn_00321af0


// 0x00321b20 pure3d::d3dContext::vfunc_96 (35 B): matches/0x00321b20.cpp
// sym: ?vfunc_96@d3dContext@pure3d@@UAEXII@Z
 // namespace pure3d
void pure3d::d3dContext::vfunc_96(unsigned int x, unsigned int y) {
    this->f_17c = x;
    this->f_180 = y;
    D3D8::D3DDevice_SetViewport((char*)this + 0x16c);
}


// 0x00321b50 pure3d::d3dContext::vfunc_64 (24 B): matches/0x00321b50.cpp [wrapped: same definition as 0x00321aa0 in this TU]
// sym: ?v64@d3dContext@fn_00321b50@@UAEXH@Z
namespace fn_00321b50 {
class pddiBaseContext {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a50();
    virtual void a51();
    virtual void a52();
    virtual void a53();
    virtual void a54();
    virtual void a55();
    virtual void a56();
    virtual void a57();
    virtual void a58();
    virtual void a59();
    virtual void a60();
    virtual void a61();
    virtual void a62();
    virtual void a63();
    virtual void v64(int);
    // (x64t2) the base pddiBaseContext::vfunc_64 (0x0031dfe0), called directly: named by address for the native link
    void FUN_0031dfe0(int);
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void v64(int);
};
extern void __stdcall D3DDevice_SetRenderState_StencilEnable(unsigned int);   // (x64t2) was SetStencilEnable
void d3dContext::v64(int b) {
    FUN_0031dfe0(b);
    D3DDevice_SetRenderState_StencilEnable((unsigned char)b);
}
} // namespace fn_00321b50


// 0x00321b70 pure3d::d3dContext::vfunc_66 (40 B): matches/0x00321b70.cpp [wrapped: conflict: D3DDevice_SetRenderState_Simple; pure3d::d3dContext; pure3d::pddiBaseContext]
// sym: ?v66@d3dContext@pure3d@fn_00321b70@@UAEXH@Z
namespace fn_00321b70 {

extern "C++" __declspec(nothrow) void __fastcall D3DDevice_SetRenderState_Simple(int*, int);
extern int DAT_0039de28;
namespace pure3d {
class pddiBaseContext {
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
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66(int);
    // (x64t2) the base pddiBaseContext::vfunc_66 (0x0031e000), called directly: named by address for the native link
    void FUN_0031e000(int);
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void v66(int);
};
void d3dContext::v66(int x) {
    FUN_0031e000(x);
    int v = ((int*)((hulk_intptr)((char*)&DAT_004d3a6c)))[x];
    D3DDevice_SetRenderState_Simple((int*)0x40364, v);
    DAT_0039de28 = v;
}
} // namespace pure3d
} // namespace fn_00321b70


// 0x00321ba0 pure3d::d3dContext::vfunc_68 (33 B): matches/0x00321ba0.cpp [wrapped: conflict: pure3d::d3dContext; pure3d::pddiBaseContext]
// sym: ?vfunc_68@d3dContext@pure3d@fn_00321ba0@@UAEXK@Z
namespace fn_00321ba0 {
namespace pure3d {
class pddiBaseContext {
  public:
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
    virtual void f13();
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
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
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
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void vfunc_68(unsigned long);
    // (x64t2) the base pddiBaseContext::vfunc_68 (0x0031e020), called directly: named by address for the native link
    void FUN_0031e020(unsigned long);
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void vfunc_68(unsigned long);
};
} // namespace pure3d
extern void __fastcall D3DDevice_SetRenderState_Simple(unsigned long, unsigned long);
extern unsigned long g_state_321ba0;
void pure3d::d3dContext::vfunc_68(unsigned long x) {
    FUN_0031e020(x);
    D3DDevice_SetRenderState_Simple(0x40368, x);
    g_state_321ba0 = x;
}
} // namespace fn_00321ba0


// 0x00321bd0 pure3d::d3dContext::vfunc_70 (33 B): matches/0x00321bd0.cpp [wrapped: conflict: pure3d::d3dContext; pure3d::pddiBaseContext]
// sym: ?vfunc_70@d3dContext@pure3d@fn_00321bd0@@UAEXI@Z
namespace fn_00321bd0 {
namespace pure3d {
class pddiBaseContext {
  public:
    virtual void vfunc_70(unsigned);
    // (x64t2) the base pddiBaseContext::vfunc_70 (0x0031e040), called directly: named by address for the native link
    void FUN_0031e040(unsigned);
};
class d3dContext : public pddiBaseContext {
  public:
    void vfunc_70(unsigned);
};
} // namespace pure3d
namespace D3D8 {
void __fastcall D3DDevice_SetRenderState_Simple(unsigned, unsigned);
}
extern unsigned DAT_0039de30;
void pure3d::d3dContext::vfunc_70(unsigned x) {
    FUN_0031e040(x);
    D3D8::D3DDevice_SetRenderState_Simple(0x4036c, x);
    DAT_0039de30 = x;
}
} // namespace fn_00321bd0


// 0x00321c00 pure3d::d3dContext::vfunc_72 (33 B): matches/0x00321c00.cpp [wrapped: conflict: d3dContext]
// sym: ?vfunc_72@d3dContext@fn_00321c00@@UAEXH@Z
namespace fn_00321c00 {
class pddiBaseContext {
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
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void vfunc_72(int);
    // (x64t2) the base pddiBaseContext::vfunc_72 (0x0031e060), called directly: named by address for the native link
    void FUN_0031e060(int);
};
class d3dContext : public pddiBaseContext {
  public:
    void vfunc_72(int);
};
extern void __fastcall D3DDevice_SetRenderState_Simple(int*, int);   // (x64t2) was D3D8_D3DDevice_... (unbound)
extern int gRender;
void d3dContext::vfunc_72(int x) {
    FUN_0031e060(x);
    D3DDevice_SetRenderState_Simple((int*)0x40360, x);
    gRender = x;
}
} // namespace fn_00321c00


// 0x00321c30 pure3d::d3dContext::vfunc_74 (92 B): matches/0x00321c30.cpp [wrapped: conflict: pure3d::d3dContext; pure3d::pddiBaseContext]
// sym: ?vfunc_74@d3dContext@pure3d@fn_00321c30@@UAEXHHH@Z
namespace fn_00321c30 {

typedef unsigned int u32_321c30;
namespace pure3d {
class pddiBaseContext {
  public:
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
    virtual void f13();
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
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
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
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void vfunc_74(int, int, int);
    // (x64t2) the base pddiBaseContext::vfunc_74 (0x0031e080), called directly: named by address for the native link
    void FUN_0031e080(int, int, int);
};
class d3dContext : public pddiBaseContext {
  public:
    void vfunc_74(int, int, int);
};
} // namespace pure3d
extern u32_321c30 DAT_0039de20;
extern u32_321c30 DAT_0039de24;
// (x64t2) the XDK's names (were SetStencil / SetSimple)
void __stdcall D3DDevice_SetRenderState_StencilFail(u32_321c30);
void __fastcall D3DDevice_SetRenderState_Simple(u32_321c30, u32_321c30);
void pure3d::d3dContext::vfunc_74(int a, int b, int c) {
    FUN_0031e080(a, b, c);
    D3DDevice_SetRenderState_StencilFail(*(u32_321c30*)(((hulk_intptr)((char*)&DAT_004d3a54)) + a * 4));
    u32_321c30 x = *(u32_321c30*)(((hulk_intptr)((char*)&DAT_004d3a54)) + b * 4);
    D3DDevice_SetRenderState_Simple(0x40374, x);
    DAT_0039de20 = x;
    u32_321c30 y = *(u32_321c30*)(((hulk_intptr)((char*)&DAT_004d3a54)) + c * 4);
    D3DDevice_SetRenderState_Simple(0x40378, y);
    DAT_0039de24 = y;
}
} // namespace fn_00321c30


// 0x00321c90 pure3d::d3dContext::vfunc_76 (28 B): matches/0x00321c90.cpp
// sym: ?vfunc_76@d3dContext@pure3d@@UAEXK@Z
void pure3d::d3dContext::vfunc_76(unsigned long __p0) { hulk_uintptr x = (u32_321c90)__p0;

    ((d3dContext_nv_321c90*)(this))->FUN_0031e0e0((unsigned long)x);
    D3DDevice_SetRenderState_FillMode(*(u32_321c90*)(((hulk_intptr)((char*)&DAT_004d3a8c)) + x * 4));
}


// 0x00321cb0 pure3d::d3dContext::vfunc_78 (33 B): matches/0x00321cb0.cpp [wrapped: conflict: pure3d::d3dContext; pure3d::pddiBaseContext]
// sym: ?vfunc_78@d3dContext@pure3d@fn_00321cb0@@QAEXI@Z
namespace fn_00321cb0 {
namespace pure3d {
class pddiBaseContext {
  public:
    virtual void f();
    void vfunc_78(unsigned int);
    // (x64t2) the base pddiBaseContext::vfunc_78 (0x0031e100), called directly: named by address for the native link
    void FUN_0031e100(unsigned int);
};
class d3dContext : public pddiBaseContext {
  public:
    void vfunc_78(unsigned int);
};
} // namespace pure3d
extern unsigned int gFlags_321cb0;
extern unsigned int gFog;
void pure3d::d3dContext::vfunc_78(unsigned int x) {
    FUN_0031e100(x);
    gFlags_321cb0 |= 0x2000;
    gFog = (unsigned char)x;
}
} // namespace fn_00321cb0


// 0x00321ce0 pure3d::d3dContext::vfunc_80 (90 B): matches/0x00321ce0.cpp [wrapped: conflict: pure3d::d3dContext; pure3d::pddiBaseContext]
// sym: ?vfunc_80@d3dContext@pure3d@fn_00321ce0@@UAEXIII@Z
namespace fn_00321ce0 {
typedef unsigned int U_321ce0;
namespace pure3d {
class pddiBaseContext {
  public:
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
    virtual void f13();
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
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
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
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void vfunc_80(U_321ce0, U_321ce0, U_321ce0);
    // (x64t2) the base pddiBaseContext::vfunc_80 (0x0031e120), called directly: named by address for the native link
    void FUN_0031e120(U_321ce0, U_321ce0, U_321ce0);
};
class d3dContext : public pddiBaseContext {
  public:
    void vfunc_80(U_321ce0, U_321ce0, U_321ce0);
};
} // namespace pure3d
extern U_321ce0 gFlags_321ce0, gState, gFog, gA, gB;
void __stdcall D3DDevice_SetRenderState_FogColor(U_321ce0);   // (x64t2) was SetFog
void pure3d::d3dContext::vfunc_80(U_321ce0 a, U_321ce0 b, U_321ce0 c) {
    FUN_0031e120(a, b, c);
    gFlags_321ce0 |= 0x2000;
    gFog = 3;
    D3DDevice_SetRenderState_FogColor(a);
    gA = b;
    gB = c;
    gFlags_321ce0 |= 0x2000;
}
} // namespace fn_00321ce0


// 0x00321d40 pure3d::d3dContext::vfunc_92 (69 B): matches/0x00321d40.cpp
// sym: ?vfunc_92@d3dContext@pure3d@@UAEHPAX@Z
 // namespace pure3d
int pure3d::d3dContext::vfunc_92(void* __p0) { Texture_321d40 * p = (Texture_321d40 *)__p0;

    void* d = D3DDevice_GetDepthStencilSurface2();
    void* s;
    if (p == 0)
        s = D3DDevice_GetBackBuffer2(0);
    else
        s = D3DTexture_GetSurfaceLevel2(p->surface, 0);
    if (p == 0 || s)
        D3DDevice_SetRenderTarget(s, d);
    D3DResource_Release(s);
    D3DResource_Release(d);
    return 0;
}


// 0x00321d90 pure3d::d3dContext::vfunc_84 (6 B): matches/0x00321d90.cpp
// sym: ?vfunc_84@d3dContext@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::d3dContext::vfunc_84() {
    return 0x800;
}

namespace fn_f57e27cb {

// 0x00321da0 FUN_00321da0 (11 B): matches/0x00321da0.cpp
// sym: ?target@Obj_321da0@fn_f57e27cb@@QAEHHHHH@Z
hulk_intptr Obj_321da0::target(hulk_intptr a0, int a1, int a2, int a3) {
    return member->go(a0, a1, a2, a3);
}


// 0x00321dc0 FUN_00321dc0 (206 B): equivalent/0x00321dc0.cpp
// sym: ?FUN_00321dc0@d3dPrimStream_321dc0@fn_f57e27cb@@QAEIPAHH@Z @583c33957b8a @wbbe348e0b917
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 26/26)
// FUN_00321dc0 @ 0x00321dc0
unsigned int d3dPrimStream_321dc0::FUN_00321dc0(int *output, int key) {
    output[0] = -1;
    output[1] = -1;
    output[2] = -1;
    output[3] = -1;
    unsigned int count = 0;
    for (int i = 0; i < 8 && count < 4; ++i) {
        if (data->entries[i].active && data->entries[i].key == key) {
            output[count++] = i;
        }
    }
    return count;
}

} // namespace fn_f57e27cb

// 0x00321ea0 pure3d::d3dContext::vfunc_89 (148 B): equivalent/0x00321ea0.cpp [wrapped: conflict: pure3d::d3dContext]
// sym: ?vfunc_89@d3dContext@pure3d@fn_00321ea0@@QAEHH@Z @6522f2bd005f @w674c2601099d
namespace fn_00321ea0 {
// STATUS: equivalent (tools/equiv.py level 3: 20028 inputs, branch coverage 18/18)
// pure3d::d3dContext::vfunc_89 @ 0x00321ea0
// Property getter: returns cached context values by property id; unknown ids fall through to the base default.
// (x64t3) the extensions and the word after them are gen d3dContext's f_424..f_448 (the view's 32-bit pad put them
// at 32-bit offsets on 64-bit); the extensions are returned pointer-sized (gen's slot 89 returns hulk_intptr)
#define HULK_CTX89(f) ((hulk_intptr)((::pure3d::d3dContext*)(void*)this)->f)
namespace pure3d {
class d3dContext {
public:
    virtual void vfunc_0();
    hulk_intptr vfunc_89(int property);
    int FUN_0031e2d0(int property);
};

hulk_intptr d3dContext::vfunc_89(int property)
{
    switch (property) {
    case 0x101: return HULK_CTX89(f_424);
    case 0x102: return HULK_CTX89(f_434);
    case 0x103: return HULK_CTX89(f_440);
    case 0x104: return HULK_CTX89(f_444);
    case 0x105: return HULK_CTX89(f_448);
    case 0x106: return HULK_CTX89(f_43c);
    case 0x500001: return HULK_CTX89(f_428);
    case 0x500002: return HULK_CTX89(f_438);
    case 0x500004: return HULK_CTX89(f_42c);
    case 0x500005: return HULK_CTX89(f_430);
    default: return FUN_0031e2d0(property);
    }
}
#undef HULK_CTX89
}
} // namespace fn_00321ea0


// 0x00321f50 pure3d::d3dContext::vfunc_90 (60 B): matches/0x00321f50.cpp [wrapped: conflict: pure3d::d3dContext; pure3d::pddiBaseContext]
// sym: ?vfunc_90@d3dContext@pure3d@fn_00321f50@@QAEEI@Z
namespace fn_00321f50 {
namespace pure3d {
class pddiBaseContext {
  public:
    unsigned char vfunc_90(unsigned int);
};
class d3dContext : public pddiBaseContext {
  public:
    unsigned char vfunc_90(unsigned int);
};
unsigned char d3dContext::vfunc_90(unsigned int x) {
    switch (x) {
    case 0x101:
    case 0x102:
    case 0x103:
    case 0x106:
    case 0x500001:
    case 0x500002:
    case 0x500004:
        return 1;
    default:
        return pddiBaseContext::vfunc_90(x);
    }
}
} // namespace pure3d
} // namespace fn_00321f50


// 0x00321fc0 pure3d::pddiExtGammaControl::vfunc_0 (31 B): matches/0x00321fc0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00321fc0@@UAEPAV123@E@Z
namespace fn_00321fc0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtension_321fc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtension_321fc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00321fc0


// 0x00322000 pure3d::d3dExtAntialiasControl::vfunc_1 (14 B): matches/0x00322000.cpp
// sym: ?vfunc_1@d3dExtAntialiasControl@pure3d@@UAEXE@Z
void pure3d::d3dExtAntialiasControl::vfunc_1(unsigned char value) {
    D3D8::D3DDevice_SetRenderState_MultiSampleAntiAlias(value);
}

// 0x00322010 pure3d::d3dExtAntialiasControl::vfunc_3 (5 B): not yet verified

// 0x00322020 pure3d::d3dExtAntialiasControl::vfunc_4 (16 B): matches/0x00322020.cpp
// sym: ?vfunc_4@d3dExtAntialiasControl@pure3d@@UAEIXZ
unsigned int pure3d::d3dExtAntialiasControl::vfunc_4() {
    return *(unsigned int*)((*(char**)((char*)(*(void * *)&this->f_04) + 0x154)) + 0x460);
}


// 0x00322030 pure3d::d3dExtAntialiasControl::vfunc_2 (16 B): matches/0x00322030.cpp
// sym: ?vfunc_2@d3dExtAntialiasControl@pure3d@@UAEXE@Z
void pure3d::d3dExtAntialiasControl::vfunc_2(unsigned char value) {
    (*(D3DDeviceState * *)&this->f_04)->value = value;
}


// 0x00322040 pure3d::d3dExtAntialiasControl::vfunc_0 (31 B): matches/0x00322040.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00322040@@UAEPAV123@E@Z
namespace fn_00322040 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtAntialiasControl_322040 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtAntialiasControl_322040 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00322040


// 0x003220a0 pure3d::d3dExtGlobalProjectedTexture::vfunc_1 (68 B): matches/0x003220a0.cpp
// sym: ?vfunc_1@d3dExtGlobalProjectedTexture@pure3d@@UAEXHPAX0@Z
void pure3d::d3dExtGlobalProjectedTexture::vfunc_1(int index, void* __p1, void* __p2) { Block_3220a0 * data = (Block_3220a0 *)__p1; Ref_3220a0 * ref = (Ref_3220a0 *)__p2;

    Block_3220a0* dest = (Block_3220a0*)((char*)this + index * 0x40 + 0x44);
    *dest = *data;
    if (ref)
        ref->f0();
    Ref_3220a0** p = (Ref_3220a0**)((char*)this + index * 4 + 4);
    if (*p)
        (*p)->f1();
    *p = ref;
}


// 0x003220f0 pure3d::d3dExtGlobalProjectedTexture::vfunc_2 (52 B): matches/0x003220f0.cpp
// sym: ?vfunc_2@d3dExtGlobalProjectedTexture@pure3d@@UAE_NHPAX0@Z
bool pure3d::d3dExtGlobalProjectedTexture::vfunc_2(int index, void* __p1, void* __p2) { Block_3220f0 * output = (Block_3220f0 *)__p1; int * value = (int *)__p2;

    *output = *(Block_3220f0*)((char*)this + index * 0x40 + 0x44);
    int v = *(int*)((char*)this + index * 4 + 4);
    *value = v;
    return v != 0;
}


// 0x00322130 pure3d::d3dExtGlobalProjectedTexture::vfunc_0 (30 B): matches/0x00322130.cpp
// sym: ??_Gd3dExtGlobalProjectedTexture@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::d3dExtGlobalProjectedTexture::~d3dExtGlobalProjectedTexture() {}

namespace fn_f57e27cb {

// 0x00322150 FUN_00322150 (48 B): matches/0x00322150.cpp
// sym: ?f@d3dExtGlobalProjectedTexture_322150@fn_f57e27cb@@QAEXXZ
void d3dExtGlobalProjectedTexture_322150::f() {
    vftable = (void*)((hulk_intptr)DAT_00433094);
    for (int i = 0; i < 16; ++i)
        if (items[i])
            items[i]->Release();
    vftable = (void*)((hulk_intptr)DAT_0043276c);
}

} // namespace fn_f57e27cb

// 0x003221a0 pure3d::d3dExtReadPixels::vfunc_0 (31 B): matches/0x003221a0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_003221a0@@UAEPAV123@E@Z
namespace fn_003221a0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtReadPixels_3221a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtReadPixels_3221a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_003221a0


// 0x003221e0 pure3d::d3dExtHardwareSkinning::vfunc_1 (8 B): matches/0x003221e0.cpp
// sym: ?vfunc_1@d3dExtHardwareSkinning@pure3d@@UAEII@Z
unsigned int pure3d::d3dExtHardwareSkinning::vfunc_1(unsigned int ) {
    return 0x19;
}


// 0x003221f0 pure3d::d3dExtHardwareSkinning::vfunc_4 (3 B): matches/0x003221f0.cpp
// sym: ?vfunc_4@d3dExtHardwareSkinning@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::d3dExtHardwareSkinning::vfunc_4(int a) {
    (void)a;
}


// 0x00322200 pure3d::d3dExtHardwareSkinning::vfunc_5 (93 B): matches/0x00322200.cpp
// sym: ?vfunc_5@d3dExtHardwareSkinning@pure3d@@UAEXHH@Z
 // namespace pure3d
void pure3d::d3dExtHardwareSkinning::vfunc_5(int index, int __p1) { unsigned int value = (unsigned int)__p1;

    unsigned int result = (*(Device_322200 * *)&this->f_04)->slot18(0);
    Matrix_322200 matrix;
    matrix.FUN_0022ca90(value, result);
    Matrix_322200 transformed = matrix;
    transformed.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstantNotInline(index * 3 + 0x71, &transformed, 12);
}

namespace fn_f57e27cb {

// 0x00322260 pure3d::d3dExtHardwareSkinning::vfunc_2 (1 B): matches/0x00322260.cpp
// sym: ?FUN_00322260@fn_f57e27cb@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00322260() {}


// 0x00322270 pure3d::d3dExtHardwareSkinning::vfunc_3 (1 B): matches/0x00322270.cpp
// sym: ?FUN_00322270@fn_f57e27cb@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00322270() {}

} // namespace fn_f57e27cb

// 0x00322280 pure3d::d3dExtHardwareSkinning::vfunc_0 (31 B): matches/0x00322280.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00322280@@UAEPAV123@E@Z
namespace fn_00322280 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtHardwareSkinning_322280 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtHardwareSkinning_322280 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00322280


// 0x003222c0 pure3d::d3dExtVisibilityTest::vfunc_1 (6 B): matches/0x003222c0.cpp
// sym: ?vfunc_1@d3dExtVisibilityTest@pure3d@@UAEIXZ
unsigned int pure3d::d3dExtVisibilityTest::vfunc_1() {
    return 0x4000;
}

// 0x003222d0 pure3d::d3dExtVisibilityTest::vfunc_2 (5 B): not yet verified
// 0x003222e0 pure3d::d3dExtVisibilityTest::vfunc_3 (5 B): not yet verified
namespace fn_f57e27cb {

// 0x003222f0 pure3d::d3dExtVisibilityTest::vfunc_4 (33 B): matches/0x003222f0.cpp
// sym: ?vfunc_4@d3dExtVisibilityTest_3222f0@fn_f57e27cb@@UAEII@Z
u32_3222f0 d3dExtVisibilityTest_3222f0::vfunc_4(u32_3222f0 arg) {
    u32_3222f0 v = arg;
    while (D3D8::D3DDevice_GetVisibilityTestResult(v, &arg, 0) == 0x88760828u) {
    }
    return arg;
}

} // namespace fn_f57e27cb

// 0x00322320 pure3d::d3dExtVisibilityTest::vfunc_0 (31 B): matches/0x00322320.cpp
// sym: ?f2@NonCopyable_322320@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_322320* pure3d::NonCopyable_322320::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

namespace fn_f57e27cb {

// 0x00322360 pure3d::d3dExtVertexProgram::vfunc_4 (38 B): matches/0x00322360.cpp
// sym: ?f4@d3dExtVertexProgram_322360@fn_f57e27cb@@UAEXPAV12@D@Z
void d3dExtVertexProgram_322360::f4(d3dExtVertexProgram_322360* self, char on) {
    if (on)
        self->flag = 1;
    self->a22();
    if (on)
        self->flag = 0;
}


// 0x00322390 pure3d::d3dExtVertexProgram::vfunc_5 (14 B): matches/0x00322390.cpp
// sym: ?vfunc_5@fn_f57e27cb@@YGXPAXH@Z
void __stdcall vfunc_5(void* self, int value) {
    *(int*)((char*)self + 0x3c) = value;
}

} // namespace fn_f57e27cb

// 0x003223a0 pure3d::d3dExtVertexProgram::vfunc_6 (22 B): matches/0x003223a0.cpp
// sym: ?vfunc_6@d3dExtVertexProgram@pure3d@@UAEXI@Z
void pure3d::d3dExtVertexProgram::vfunc_6(unsigned int x) {
    (*(Inner_3223a0 * *)&this->f_04)->data->field = x;
}


// 0x003223c0 pure3d::d3dExtVertexProgram::vfunc_7 (53 B): matches/0x003223c0.cpp [wrapped: conflict: pure3d::d3dExtVertexProgram]
// sym: ?vfunc_7_impl@fn_003223c0@@YGXPAVd3dExtVertexProgram@pure3d@1@HH@Z
namespace fn_003223c0 {
namespace pure3d {
class d3dExtVertexProgram {
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
};
} // namespace pure3d
namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstant1(void* dev, int reg);
void __fastcall D3DDevice_SetVertexShaderConstant4(void* dev, int reg);
void __fastcall D3DDevice_SetVertexShaderConstantNotInline(void* dev, int reg, int bytes);
} // namespace D3D8
void __stdcall vfunc_7_impl(pure3d::d3dExtVertexProgram* self, int reg, int count) {
    char* dev = (char*)self + 0x60;
    if (count == 1) {
        D3D8::D3DDevice_SetVertexShaderConstant1(dev, reg);
        return;
    }
    if (count == 4) {
        D3D8::D3DDevice_SetVertexShaderConstant4(dev, reg);
        return;
    }
    D3D8::D3DDevice_SetVertexShaderConstantNotInline(dev, reg, count << 2);
}
} // namespace fn_003223c0

namespace fn_f57e27cb {

// 0x00322400 pure3d::d3dExtVertexProgram::vfunc_8 (17 B): matches/0x00322400.cpp
// sym: ?vfunc_8@fn_f57e27cb@@YGXPAVBase_322400@1@PAX@Z
void __stdcall vfunc_8(Base_322400* self, void* arg) {
    self->v21(arg);
}

} // namespace fn_f57e27cb

// 0x00322420 pure3d::d3dExtVertexProgram::vfunc_1 (14 B): matches/0x00322420.cpp
// sym: ?vfunc_1@d3dExtVertexProgram@pure3d@@UAEXHH@Z
void pure3d::d3dExtVertexProgram::vfunc_1(int a0, int a1) {
    ((owners::Registry_329320 *)((*(Inner_322420 * *)&this->f_04)->child))->FUN_00329320((const char *)(hulk_uintptr)(int)a0, (unsigned int)a1);
}


// 0x00322430 pure3d::d3dExtVertexProgram::vfunc_3 (14 B): equivalent/0x00322430.cpp [wrapped: conflict: pure3d::d3dExtVertexProgram]
// sym: ?vfunc_3@d3dExtVertexProgram@pure3d@fn_00322430@@UAEXHHHH@Z @499164e1c531 @wd2f72b87657e
namespace fn_00322430 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// pure3d::d3dExtVertexProgram::vfunc_3 @ 0x00322430
// pure3d::d3dExtVertexProgram::vfunc_3 @ 0x00322430
namespace pure3d {
struct VertexProgramState {
    char reserved[0x208];
    struct VertexProgramDevice* device;
};
struct VertexProgramDevice {
    void FUN_003290e0(int, int, int, int);
};
struct d3dExtVertexProgram {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(int, int, int, int);
    VertexProgramState* state;
};
void d3dExtVertexProgram::vfunc_3(int a0, int a1, int a2, int a3) {
    state->device->FUN_003290e0(a0, a1, a2, a3);
}
}
} // namespace fn_00322430


// 0x00322440 pure3d::d3dExtVertexProgram::vfunc_2 (72 B): equivalent/0x00322440.cpp
// sym: ?vfunc_2@d3dExtVertexProgram@pure3d@@UAEXHHHHH@Z @a38ab194c921 @w3eb982f37879
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// pure3d::d3dExtVertexProgram::vfunc_2 @ 0x00322440
void pure3d::d3dExtVertexProgram::vfunc_2(hulk_intptr __p0, int __p1, int __p2, int __p3, int __p4) { VertexSource * source = (VertexSource *)__p0; unsigned int a = (unsigned int)__p1; unsigned int b = (unsigned int)__p2; unsigned int c = (unsigned int)__p3; unsigned char temporary = (unsigned char)__p4;

 if (temporary) source->temporary=1;
 unsigned int handle=source->slot23();
 (*(Context_322440 * *)&this->f_04)->device->FUN_003290e0(handle,a,b,c);
 if (temporary) source->temporary=0;
}


// 0x00322490 pure3d::d3dExtVertexProgram::vfunc_0 (31 B): matches/0x00322490.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00322490@@UAEPAV123@E@Z
namespace fn_00322490 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtVertexProgram_322490 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtVertexProgram_322490 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00322490


// 0x003224b0 FUN_003224b0 (269 B): equivalent/0x003224b0.cpp [wrapped: conflict: pure3d::d3dExtFramebufferEffects]
// sym: ??0d3dExtFramebufferEffects@pure3d@fn_003224b0@@QAE@PAVd3dContext@1@@Z @694602d59337 @wc865cf514a12
namespace fn_003224b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0; --wine 600 inputs)
// FUN_003224b0 @ 0x003224b0
extern "C" char DAT_00433110[];  // pure3d::d3dExtFramebufferEffects's vftable, stored by address (a local class's own
                                 // vftable would be the 64-bit link's stub)
namespace pure3d {
struct d3dExtFramebufferEffects {
 void* vftable;
 ::pure3d::d3dContext* owner; // 04: the context (0x00324e00 constructs the extension on itself)
 unsigned int f08, f0c;
 unsigned char f10; char pad11[3];
 float f14;
 unsigned int f18;
 unsigned char f1c; char pad1d[3];
 unsigned int f20;
 unsigned int table[16];
 unsigned int f64;
 float f68, f6c, f70, f74, f78;
 unsigned char f7c, f7d; char pad7e[2];
 float f80, f84, f88;
 unsigned int f8c,f90,f94,f98,f9c,fa0,fa4,fa8,fac,fb0;
 unsigned char fb4; char padb5[3];
 unsigned int fb8;
 float fbc,fc0;
 unsigned int fc4,fc8;
 float fcc,fd0,fd4;
 char padd8[4];
 int fdc;
 float fe0;
 unsigned int fe4;
 float fe8;
 unsigned char fec;
 d3dExtFramebufferEffects(::pure3d::d3dContext* value);
};
d3dExtFramebufferEffects::d3dExtFramebufferEffects(::pure3d::d3dContext* value) {
 vftable=DAT_00433110;
 owner=value;
 f08=f0c=0; f10=0; f18=0; f1c=0; f20=0;
 f68=1.0f; f70=1.0f; f6c=0.0f; f78=1.0f;
 f14=0.9f; f74=0.5f;
 f80=f84=f88=1.0f;
 f7c=f7d=0; f64=0;
 for(int i=0;i<16;++i) table[i]=0;
 fdc=-1; fe0=1.0f; fe4=0; fe8=1.0f;
 fc0=fd0=fd4=fbc=1.0f;
 f8c=f90=f94=f98=f9c=fa0=fac=fb0=fa8=0;
 fb4=0; fa4=fc4=fc8=fb8=0;
 fcc=0.5f; fec=1;
}
}
} // namespace fn_003224b0


// 0x003225c0 pure3d::d3dExtFramebufferEffects::vfunc_1 (31 B): matches/0x003225c0.cpp
// sym: ?vfunc_1@d3dExtFramebufferEffects@pure3d@@UAEXEHHE@Z
void pure3d::d3dExtFramebufferEffects::vfunc_1(unsigned char x, int y, int z, unsigned char w) {
    this->f_10 = x;
    this->f_14 = y;
    this->f_18 = z;
    this->f_1c = w;
}


// 0x003225e0 pure3d::d3dExtFramebufferEffects::vfunc_10 (3 B): matches/0x003225e0.cpp
// sym: ?vfunc_10@d3dExtFramebufferEffects@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::d3dExtFramebufferEffects::vfunc_10(int a) {
    (void)a;
}


// 0x003225f0 pure3d::d3dExtFramebufferEffects::vfunc_0 (30 B): matches/0x003225f0.cpp
// sym: ??_Gd3dExtFramebufferEffects@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::d3dExtFramebufferEffects::~d3dExtFramebufferEffects() {}

namespace fn_f57e27cb {

// 0x00322610 FUN_00322610 (159 B): matches/0x00322610.cpp
// sym: ??1d3dExtFramebufferEffects@fn_f57e27cb@@UAE@XZ
d3dExtFramebufferEffects::~d3dExtFramebufferEffects() throw() {
    if (objA)
        objA->vfunc_1();
    if (objB)
        objB->vfunc_1();
    if (res20) {
        D3D8::D3DResource_Release(res20);
        res20 = 0;
    }
    if (resA8) {
        D3D8::D3DResource_Release(resA8);
        resA8 = 0;
    }
    if (shader64) {
        D3D8::D3DDevice_DeletePixelShader(shader64);
        shader64 = 0;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
            if (shaders[i][j]) {
                D3D8::D3DDevice_DeletePixelShader(shaders[i][j]);
                shaders[i][j] = 0;
            }
        }
    }
}

} // namespace fn_f57e27cb

// 0x003226b0 pure3d::d3dExtFramebufferEffects::vfunc_2 (28 B): matches/0x003226b0.cpp
// sym: ?vfunc_2@d3dExtFramebufferEffects@pure3d@@UAEXXZ
// data: zero_3226b0 = DAT_003f32e0
void pure3d::d3dExtFramebufferEffects::vfunc_2() {
    if ((*(float *)&this->f_18) != DAT_003f32e0)
        ((ThisCall_00322990*)(this))->FUN_00322990();
    else
        ((ThisCall_003226d0*)(this))->FUN_003226d0();
}

namespace fn_f57e27cb {

// 0x003226d0 FUN_003226d0 (696 B): equivalent/0x003226d0.cpp
// sym: ?Draw@Overlay@fn_f57e27cb@@QAEXXZ @303fb9133d34 @wd89f07a4f622
// STATUS: equivalent (tools/equiv.py level 3: 18904 inputs, branch coverage 6/6)
// FUN_003226d0 @ 0x003226d0
void Overlay::Draw() {
    if (!enabled)
        return;
    if (shader == 0) {
        shader = ctx->factory->CreateShader("simple", 0);
        tex = new d3dTexture_3226d0(ctx, 0);
        shader->v0();
        tex->v0();
        shader->SetTexture(0x584554, tex);
    }
    unsigned int color = ((unsigned char)(__int64)(int)(__int64)(alpha * 255.0f) << 24) | 0xffffff;
    float zNear, unusedB, farv;
    ctx->f29(&zNear, &unusedB, &unusedB, &farv);
    zNear = zNear * 1.01f;
    ctx->f24(2);
    ctx->f58(0);
    ctx->f13(0);
    shader->SetMode(0x444d4c42, 1);
    Surface_3226d0* bb = (Surface_3226d0*)D3D8::D3DDevice_GetBackBuffer2(-1);
    unsigned int saved = bb->common;
    bb->common = (bb->common & 0xfffcffffu) | 0x40000;
    tex->FUN_00326300(bb);
    Prim_3226d0* p = ctx->f30(shader, 1, 0x2021, 4, 0);
    float h = (hulk_freg)ctx->viewport->GetHeight();
    float w = (hulk_freg)ctx->viewport->GetWidth();
    hulk_freg v = farv * scale;
    hulk_freg u = scale;
    hulk_freg uMax = w - scale;
    hulk_freg vMax = h - v;
    *p->color = color;
    p->uv[0] = u;
    p->uv[1] = v;
    p->pos[0] = 0;
    p->pos[1] = 0;
    p->pos[2] = zNear;
    p->FUN_0008ef00();
    *p->color = color;
    p->uv[0] = uMax;
    p->uv[1] = v;
    p->pos[0] = w;
    p->pos[1] = 0;
    p->pos[2] = zNear;
    p->FUN_0008ef00();
    *p->color = color;
    p->uv[0] = u;
    p->uv[1] = vMax;
    p->pos[0] = 0;
    p->pos[1] = h;
    p->pos[2] = zNear;
    p->FUN_0008ef00();
    *p->color = color;
    p->uv[0] = uMax;
    p->uv[1] = vMax;
    p->pos[0] = w;
    p->pos[1] = h;
    p->pos[2] = zNear;
    p->FUN_0008ef00();
    ctx->f31(p);
    tex->FUN_00326300(0);
    bb->common = (bb->common & ~0x70000u) | (saved & 0x70000);
    D3D8::D3DResource_Release((hulk_intptr)bb);
    ctx->f24(0);
    ctx->f58(1);
}

} // namespace fn_f57e27cb

// 0x00322990 FUN_00322990 (821 B): equivalent/0x00322990.cpp [wrapped: conflict: Overlay]
// sym: ?Draw@Overlay@fn_00322990@@QAEXXZ @a9bc73cdad02 @wfe9d79e92977
namespace fn_00322990 {
// STATUS: equivalent (tools/equiv.py level 3: 18262 inputs, branch coverage 11/12, incomplete)
// FUN_00322990 @ 0x00322990
namespace D3D8 {
hulk_intptr __stdcall D3DDevice_GetBackBuffer2(int);
void __stdcall D3DResource_Release(hulk_intptr);
}
struct Surface_322990 {
    unsigned int common;
};
struct Ctx_322990;
struct HeapObj {
    static void* operator new(size_t size) HULK_NEW_THROW;
};
class d3dTexture_322990 : public HeapObj {
  public:
    d3dTexture_322990(Ctx_322990* ctx, int arg) throw();
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
    virtual void SetTexture(int slot, d3dTexture_322990* tex);
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
    char pad4[HULK_D3DCTX_PAD(f_154, 0x154, sizeof(void*))];
    Viewport_322990* viewport;
    Factory_322990* factory;
};
class Overlay {
  public:
    char pad0[4];
    Ctx_322990* ctx;
    ShaderObj_322990* shader;
    d3dTexture_322990* tex;
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
        tex = new d3dTexture_322990(ctx, 0);
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
} // namespace fn_00322990


// 0x00322cd0 pure3d::d3dExtFramebufferEffects::vfunc_8 (1119 B): equivalent/0x00322cd0.cpp [wrapped: conflict: pure3d::d3dExtFramebufferEffects]
// sym: ?vfunc_8@d3dExtFramebufferEffects@pure3d@fn_00322cd0@@UAEXMHMMIMMM@Z @a1b484250638 @w1456a23ac841
namespace fn_00322cd0 {
// STATUS: equivalent (tools/equiv.py level 3: 20075 inputs, branch coverage 57/60, incomplete)
// pure3d::d3dExtFramebufferEffects::vfunc_8 @ 0x00322cd0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl exp(double);
#endif

namespace pure3d {struct d3dExtFramebufferEffects {virtual void vfunc_0();virtual void vfunc_1();virtual void vfunc_2();virtual void vfunc_3();virtual void vfunc_4();virtual void vfunc_5();virtual void vfunc_6();virtual void vfunc_7();virtual void vfunc_8(float,int,float,float,unsigned,float,float,float);char pad[180];float amount,blend,contrast,radius,unusedC8,mix;char padD0[8];float sigma;int mode;float red,green,blue;int unusedEC;float positions[20],weights[20];};
void d3dExtFramebufferEffects::vfunc_8(float a,int flag,float b,float q,unsigned color,float r,float c,float m){
blend=(b>=0.0f&&b<=1.0f)?b:(b>1.0f?1.0f:0.0f);radius=((r>=-100.0f&&r<=100.0f)?r:(r>100.0f?100.0f:-100.0f))*0.003921568859368563f;
double x=(double)a*0.5f;amount=(x>=0.0f&&x<=1.0f)?(float)x:(x>1.0f?1.0f:0.0f);mix=(m>=0.0f&&m<=1.0f)?m:(m>1.0f?1.0f:0.0f);contrast=(c>=-100.0f&&c<=100.0f)?c:(c>100.0f?100.0f:-100.0f);mode=flag;x=(double)q*0.25f;sigma=(x>=0.0f&&x<=25.0f)?(float)x:(x>25.0f?25.0f:0.0f);
blue=(color&255)*0.003921568859368563f;red=((color>>16)&255)*0.003921568859368563f;green=((color>>8)&255)*0.003921568859368563f;double total=(double)*(volatile float*)&blue+*(volatile float*)&green+*(volatile float*)&red;if(total>0.0f){double inv=1.0f/total;red=(float)(inv**(volatile float*)&red);green=(float)(inv**(volatile float*)&green);blue=(float)(inv**(volatile float*)&blue);}else{red=green=blue=0.3333333432674408f;}
if(contrast<0.0f)contrast=(float)((double)contrast*0.01f+1.0f);else contrast=((float*)&DAT_00432a10)[(int)((double)contrast+0.5f)];
x=(double)sigma*0.45f+0.3f;float square=(float)(x*x);double initial=exp(0.0f/square),accum=initial;int count=1;for(;count<20;++count){double w=exp(-((double)count*count)/square);if(accum>255.5*w)break;accum+=w+w;}double sum=initial;weights[0]=(float)initial;positions[0]=0.0f;for(int i=1;i<count;++i){volatile float w=(float)exp(-((double)i*i)/square);weights[i]=w;positions[i]=(float)i;if(!(w>0.003921568859368563f)){count=i;break;}sum+=(double)w+w;}float scale=(float)(1.0f/sum);int j;for(j=0;j<count;++j)weights[j]*=scale;for(;j<20;++j)weights[j]=0.0f;
}}
} // namespace fn_00322cd0


// 0x00323130 FUN_00323130 (2016 B): equivalent/0x00323130.cpp [wrapped: compile error C2666: 'fn_f57e27cb::D3D8::D3DDevice_SetPixelShaderConstant' : 2 overloads have similar conversions]
// sym: ?FUN_00323130@d3dExtFramebufferEffects_323130@fn_00323130@@QAEPAUTexture@D3D8@2@PAU342@0@Z @ec52a5f04414 @wa86075858c76
namespace fn_00323130 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 69/70, incomplete)
// FUN_00323130 @ 0x00323130
namespace D3D8 { struct Texture; struct Surface; struct SurfaceDesc_323130 { unsigned int data[16]; }; Surface* __stdcall D3DTexture_GetSurfaceLevel2(Texture*, unsigned int); void __stdcall D3DDevice_SetRenderTarget(Surface*, unsigned int); void __stdcall D3DResource_Release(Surface*); void __stdcall D3DDevice_SetTexture(unsigned int, Texture*); void __fastcall D3DDevice_SetRenderState_Simple(unsigned int, unsigned int); void __stdcall D3DDevice_SetVertexShader(unsigned int); void __stdcall D3DDevice_SetPixelShader(unsigned int); void __stdcall D3DDevice_SetPixelShaderConstant(unsigned int, const float*, unsigned int); void __stdcall D3DDevice_DrawVerticesUP(unsigned int, unsigned int, const void*, unsigned int); }
void __stdcall FUN_003821c0(D3D8::Texture*, unsigned int, D3D8::SurfaceDesc_323130*);
namespace XGRAPHC { int __stdcall XGIsSwizzledFormat(unsigned int); }
extern unsigned int DAT_0039db08,DAT_0039db1c,DAT_0039db20,DAT_0039db9c,DAT_0039dba0,DAT_0039dc1c,DAT_0039dc20,DAT_0039dc9c,DAT_0039dca0,DAT_0039ddfc,DAT_0039de08,DAT_0039de0c,DAT_0039de38;
struct d3dExtFramebufferEffects_323130 { char pad0[0x88]; unsigned int shaders[5]; char pad1[0xf0-0x9c]; float offsets[20]; float values[20]; D3D8::Texture* FUN_00323130(D3D8::Texture* source,D3D8::Texture* target); };
D3D8::Texture* d3dExtFramebufferEffects_323130::FUN_00323130(D3D8::Texture* source,D3D8::Texture* target) {
 D3D8::Surface* surface=D3D8::D3DTexture_GetSurfaceLevel2(target,0); D3D8::D3DDevice_SetRenderTarget(surface,0); D3D8::D3DResource_Release(surface);
 for(unsigned int i=0;i<4;++i) D3D8::D3DDevice_SetTexture(i,source);
 DAT_0039db1c=DAT_0039db20=DAT_0039db9c=DAT_0039dba0=DAT_0039dc1c=DAT_0039dc20=DAT_0039dc9c=DAT_0039dca0=2; DAT_0039db08|=15;
 D3D8::SurfaceDesc_323130 desc; FUN_003821c0(source,0,&desc);
 float w=(float)desc.data[5]-0.5f, h=(float)desc.data[6]-0.5f;
 float tw=XGRAPHC::XGIsSwizzledFormat(desc.data[0])?1.0f:(float)desc.data[5];
 float th=XGRAPHC::XGIsSwizzledFormat(desc.data[0])?1.0f:(float)desc.data[6];
 float original[4][12]={0};
 for(int v=0;v<4;++v) { original[v][0]=(v&1)?w:-0.5f; original[v][1]=(v&2)?h:-0.5f; original[v][2]=1.0f; original[v][3]=1.0f; for(int k=0;k<4;++k) { original[v][4+k*2]=(v&1)?tw:0.0f; original[v][5+k*2]=(v&2)?th:0.0f; } }
 int count=0; for(int j=0;j<20;++j) { if(values[j]==0.0f) break; ++count; }
 D3D8::D3DDevice_SetRenderState_Simple(0x40304,0); DAT_0039ddfc=0;
 D3D8::D3DDevice_SetRenderState_Simple(0x40348,1); DAT_0039de0c=1;
 D3D8::D3DDevice_SetRenderState_Simple(0x40344,1); DAT_0039de08=1;
 D3D8::D3DDevice_SetRenderState_Simple(0x40350,0x8006); DAT_0039de38=0x8006;
 D3D8::D3DDevice_SetVertexShader(0x404);
 struct DrawData { float vertices[4][12]; float constants[4][4]; } draw;
 for(int stage=0;stage<2;++stage) {
  if(stage==1) { surface=D3D8::D3DTexture_GetSurfaceLevel2(source,0); D3D8::D3DDevice_SetRenderTarget(surface,0); D3D8::D3DResource_Release(surface); for(unsigned int s=0;s<4;++s) D3D8::D3DDevice_SetTexture(s,target); D3D8::D3DDevice_SetRenderState_Simple(0x40304,0); DAT_0039ddfc=0; }
  for(int side=0;side<2;++side) {
   float sign=side==0?1.0f:-1.0f;
   for(int a=0;a<4;++a) for(int b=0;b<12;++b) draw.vertices[a][b]=original[a][b];
   int batch=0,draws=0;
   for(int n=0;n<count;++n) {
    if(side==1 && n==0) continue;
    float intensity=values[n]; for(int c=0;c<4;++c) draw.constants[batch][c]=intensity;
    float shift=sign*offsets[n];
    for(int v=0;v<4;++v) draw.vertices[v][4+stage+2*batch]+=shift;
    if(draws==1) { D3D8::D3DDevice_SetRenderState_Simple(0x40304,1); DAT_0039ddfc=1; }
    ++batch;
    if(batch==4 || n==count-1) {
     D3D8::D3DDevice_SetPixelShader(shaders[batch]);
     D3D8::D3DDevice_SetPixelShaderConstant(0,&draw.constants[0][0],batch);
     D3D8::D3DDevice_DrawVerticesUP(6,4,draw.vertices,0x30);
     ++draws; batch=0;
     for(int a=0;a<4;++a) for(int b=0;b<12;++b) draw.vertices[a][b]=original[a][b];
    }
   }
   D3D8::D3DDevice_SetRenderState_Simple(0x40304,1); DAT_0039ddfc=1;
  }
 }
 D3D8::D3DDevice_SetRenderState_Simple(0x40304,0); DAT_0039ddfc=0; return source;
}
} // namespace fn_00323130

namespace fn_f57e27cb {

// 0x00323910 FUN_00323910 (196 B): matches/0x00323910.cpp
// sym: ?Setup@d3dExtFramebufferEffects_323910@fn_f57e27cb@@QAEXXZ
void d3dExtFramebufferEffects_323910::Setup() {
    if (tex != 0)
        return;
    busy = 1;
    if (!FUN_00320540())
        return;
    int rt = D3D8::D3DDevice_GetRenderTarget2();
    SurfaceDesc_323910 desc;
    D3D8::D3DSurface_GetDesc(rt, &desc);
    D3D8::D3DResource_Release(rt);
    scaleX = (float)parent->viewport->GetWidth() / (float)desc.Width;
    scaleY = (float)parent->viewport->GetHeight() / (float)desc.Height;
    tex = D3D8::D3DDevice_CreateTexture2(desc.Width, desc.Height, 1, 1, 0, desc.Format, 3);
    if (tex)
        busy = 0;
}

} // namespace fn_f57e27cb

// 0x003239e0 pure3d::d3dExtFramebufferEffects::vfunc_4 (478 B): equivalent/0x003239e0.cpp [wrapped: conflict: pure3d::d3dExtFramebufferEffects]
// sym: ?vfunc_4@d3dExtFramebufferEffects@pure3d@fn_003239e0@@UAEXMMMMH@Z @11f24711611c @wd69412e509ba
namespace fn_003239e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3065 inputs, branch coverage 28/28; --wine 665 inputs)
// pure3d::d3dExtFramebufferEffects::vfunc_4 @ 0x003239e0

namespace pure3d {
struct d3dExtFramebufferEffects {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(float a,float b,float c,float d,int color);
char pad[0x64]; float scale, amount, curve, bias, result; char pad2[4]; float red,green,blue;
};
void d3dExtFramebufferEffects::vfunc_4(float a,float b,float c,float d,int color) {
red = int((color>>16)&255)*0.00392156862745098f;
green = int((color>>8)&255)*0.00392156862745098f;
blue = int(color&255)*0.00392156862745098f;
if (!(a >= -100.0f && a <= 100.0f)) { if (a > 100.0f) a = 100.0f; else a = -100.0f; }
float initial = a * 0.01f + 1.0f; scale = initial;
if (!(c >= -100.0f && c <= 100.0f)) { if (c > 100.0f) c = 100.0f; else c = -100.0f; }
curve = c;
if (!(d >= 0.0f && d <= 1.0f)) d = d > 1.0f ? 1.0f : 0.0f;
bias = d;
if (!(b >= -100.0f && b <= 100.0f)) { if (b > 100.0f) b = 100.0f; else b = -100.0f; }
amount = b * 0.00392156862745098f;
if (c < 0.0f) {
 curve = c * 0.01f + 1.0f;
 scale = (c * 0.01f + 1.0f) * initial;
} else {
 int index = (int)(c + 0.5f);
 curve = ((float*)&DAT_00432a10)[index];
}
result = (curve < 1.0f ? curve : 1.0f) * scale;
}
}
} // namespace fn_003239e0


// 0x00323be0 pure3d::d3dExtFrameBufferTexture::vfunc_1 (112 B): matches/0x00323be0.cpp
// sym: ?vfunc_1@d3dExtFrameBufferTexture@pure3d@@UAEPAXH@Z
void* pure3d::d3dExtFrameBufferTexture::vfunc_1(int param) {
    if (!(*(Obj_323be0 * *)&this->f_08)) {
        Obj_323be0* p = (Obj_323be0*)FUN_0008d690(0xf8);
        Obj_323be0* r;
        if (p)
            r = p->Create((*(void * *)&this->f_04), 0);
        else
            r = 0;
        (*(Obj_323be0 * *)&this->f_08) = r;
        r->Init();
        unsigned int* b = GetBackBuffer(param ? 0 : -1);
        (*(unsigned int * *)&this->f_0c) = b;
        unsigned int o = *b;
        this->f_10 = o;
        *b = (o & 0xfffcffff) | 0x40000;
        (*(Obj_323be0 * *)&this->f_08)->Attach((*(unsigned int * *)&this->f_0c));
    }
    return (void*)((*(Obj_323be0 * *)&this->f_08));
}


// 0x00323c50 pure3d::d3dExtFrameBufferTexture::vfunc_2 (70 B): equivalent/0x00323c50.cpp
// sym: ?vfunc_2@d3dExtFrameBufferTexture@pure3d@@UAEXXZ @fa980c0a54a8 @waa1fabc5161f
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::d3dExtFrameBufferTexture::vfunc_2 @ 0x00323c50
void pure3d::d3dExtFrameBufferTexture::vfunc_2() {
 if ((*(Texture_323c50 * *)&this->f_08)) {
  (*(Texture_323c50 * *)&this->f_08)->FUN_00326300(0);
  (*(D3D8::D3DResource * *)&this->f_0c)->flags ^= (this->f_10 ^ (*(D3D8::D3DResource * *)&this->f_0c)->flags) & 0x70000;
  (*(Texture_323c50 * *)&this->f_08)->vfunc_1();
  D3D8::D3DResource_Release((*(D3D8::D3DResource * *)&this->f_0c));
  (*(D3D8::D3DResource * *)&this->f_0c) = 0;
  (*(Texture_323c50 * *)&this->f_08) = 0;
 }
}


// 0x00323ca0 pure3d::d3dExtFrameBufferTexture::vfunc_0 (42 B): matches/0x00323ca0.cpp [wrapped: conflict: pure3d::d3dExtFrameBufferTexture; pure3d::pddiExtFrameBufferTexture; pure3d::pddiExtension]
// sym: ?vfunc_0@d3dExtFrameBufferTexture@pure3d@fn_00323ca0@@UAEPAV123@E@Z
namespace fn_00323ca0 {
typedef unsigned char u8_323ca0;
namespace pure3d {
extern int vt_d3d;
extern int vt_ext;
class pddiExtension {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
class pddiExtFrameBufferTexture {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
struct Helper_323ca0 {
    void call();
};
void thunk_FUN_00267090(Helper_323ca0*);
class d3dExtFrameBufferTexture : public pddiExtFrameBufferTexture, public pddiExtension {
  public:
    virtual d3dExtFrameBufferTexture* vfunc_0(u8_323ca0);
    virtual void vfunc_1();
    virtual void vfunc_2();
};
d3dExtFrameBufferTexture* d3dExtFrameBufferTexture::vfunc_0(u8_323ca0 param) {
    *(hulk_intptr*)this = (hulk_intptr)&vt_d3d;
    ((Helper_323ca0*)this)->call();
    *(hulk_intptr*)this = (hulk_intptr)&vt_ext;
    if (param & 1)
        thunk_FUN_00267090((Helper_323ca0*)this);
    return this;
}
} // namespace pure3d
} // namespace fn_00323ca0


// 0x00323cd0 FUN_00323cd0 (278 B): matches/0x00323cd0.cpp [wrapped: conflict: pure3d::d3dContext]
// sym: ??1d3dContext@pure3d@fn_00323cd0@@UAE@XZ
namespace fn_00323cd0 {
struct Resource_323cd0 {
    virtual void destroy(unsigned int);
    virtual void release();
};
struct A_323cd0 {
    void FUN_00328be0();
};
struct B_323cd0 {
    void FUN_00329400();
};
struct d3dPrimStream_323cd0 {
    void FUN_0031bcf0();
};
void __cdecl thunk_FUN_00267090(void*);
namespace pure3d {
struct Base_323cd0 {
    virtual void slot0();
    void FUN_0031e500();
};
struct d3dContext : Base_323cd0 {
    char pad04[HULK_D3DCTX_PAD(f_150, 0x150, sizeof(void*))];
    A_323cd0* a;
    Resource_323cd0* r154;
    Resource_323cd0* r158;
    char pad15c[4];
    Resource_323cd0* r160;
    char pad164[0x204 - 0x164];
    d3dPrimStream_323cd0* c;
    B_323cd0* b;
    char pad20c[0x424 - 0x20c];
    Resource_323cd0* r424;
    Resource_323cd0* r428;
    Resource_323cd0* r42c;
    Resource_323cd0* r430;
    Resource_323cd0* r434;
    Resource_323cd0* r438;
    Resource_323cd0* r43c;
    Resource_323cd0* r440;
    Resource_323cd0* r444;
    virtual ~d3dContext();
};
d3dContext::~d3dContext() {
    if (r424)
        r424->destroy(1);
    if (r428)
        r428->destroy(1);
    if (r430)
        r430->destroy(1);
    if (r434)
        r434->destroy(1);
    if (r438)
        r438->destroy(1);
    if (r43c)
        r43c->destroy(1);
    if (r42c)
        r42c->destroy(1);
    if (r440)
        r440->destroy(1);
    if (r444)
        r444->destroy(1);
    if (r160)
        r160->release();
    A_323cd0* pa = a;
    if (pa) {
        pa->FUN_00328be0();
        thunk_FUN_00267090(pa);
    }
    B_323cd0* pb = b;
    if (pb) {
        pb->FUN_00329400();
        thunk_FUN_00267090(pb);
    }
    d3dPrimStream_323cd0* pc = c;
    if (pc) {
        pc->FUN_0031bcf0();
        thunk_FUN_00267090(pc);
    }
    r154->release();
    r158->release();
    FUN_0031e500();
}
} // namespace pure3d
} // namespace fn_00323cd0


// 0x00323df0 pure3d::d3dContext::vfunc_4 (188 B): matches/0x00323df0.cpp [wrapped: conflict: pure3d::d3dContext; pure3d::pddiBaseContext; pure3d::pddiObject]
// sym: ?vfunc_4@d3dContext@pure3d@fn_00323df0@@UAEXXZ
namespace fn_00323df0 {
typedef unsigned long DWORD;
struct Viewport_323df0 {
    DWORD X, Y, Width, Height;
    float MinZ, MaxZ;
};
namespace D3D8 {
void __stdcall D3DDevice_GetViewport(Viewport_323df0*);
void __stdcall D3DDevice_SetViewport(Viewport_323df0*);
} // namespace D3D8
struct RenderTarget {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int GetHeight();
    virtual int GetWidth();
    bool FUN_0031b180();
};
struct Aux_323df0 {
    void FUN_00328f10();
};
namespace pure3d {
class pddiObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class pddiBaseContext : public pddiObject {
  public:
    virtual void f3();
    virtual void vfunc_4();
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void f3();
    virtual void vfunc_4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
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
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
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
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void vfunc_102(int);
    char pad4[HULK_D3DCTX_PAD(f_14c, 0x14c, sizeof(void*))];
    int counter;
    Aux_323df0* aux;
    RenderTarget* target;
    char pad158[0x16c - 0x158];
    Viewport_323df0 vp;
    void FUN_00320c60();
};
} // namespace pure3d
void pure3d::d3dContext::vfunc_4() {
    if (target->FUN_0031b180()) {
        counter++;
        FUN_00320c60();
        aux->FUN_00328f10();
        vfunc_102(-1);
    }
    pddiBaseContext::vfunc_4();
    float h = (hulk_freg)target->GetHeight();
    float w = (hulk_freg)target->GetWidth();
    D3D8::D3DDevice_GetViewport(&vp);
    vp.X = 0;
    vp.Y = 0;
    vp.Width = (int)w;
    vp.Height = (int)h;
    D3D8::D3DDevice_SetViewport(&vp);
}
} // namespace fn_00323df0


// 0x00323eb0 pure3d::d3dContext::vfunc_108 (38 B): matches/0x00323eb0.cpp [wrapped: macros]
// sym: ?vfunc_108@d3dContext@fn_00323eb0@@UAEXH@Z
namespace fn_00323eb0 {
// data: g_transformTypes = DAT_004d3a34

typedef unsigned int uint;
// (x64t3) the matrix stack record (0x0031e610: vftable, capacity, top, matrices), the stacks gen's f_20..f_30
struct Matrix {
    void* vftable;
    int capacity;
    int index;
    hulk_intptr data;
};
extern void __stdcall D3DDevice_SetTransform(uint, const void*);
class d3dContext {
  public:
#define V(n) virtual void f##n();
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
        V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
            V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52)
                V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67)
                    V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82)
                        V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96)
                            V(97) V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106)
                                V(107) virtual void vfunc_108(int);
    V(109)
    V(110)
#undef V
};
void d3dContext::vfunc_108(int n) {
    Matrix* m = (Matrix*)(&((::pure3d::pddiBaseContext*)(void*)this)->f_20)[n];
    D3DDevice_SetTransform((((const uint*)&DAT_004d3a34))[n], (char*)m->data + m->index * 64);
}
} // namespace fn_00323eb0
#undef V


// 0x00323ee0 pure3d::d3dContext::vfunc_109 (901 B): equivalent/0x00323ee0.cpp
// sym: ?vfunc_109@d3dContext@pure3d@@UAEXXZ @ad661e8d3a77 @w396468c4d05f
// STATUS: equivalent (tools/equiv.py level 3: 20029 inputs, branch coverage 22/22)
// pure3d::d3dContext::vfunc_109 @ 0x00323ee0
// volatile locals (nf, w2) force the float-rounded memory temporaries the original uses; 0.0f - (lo - hi) reproduces its constant-load order.
void pure3d::d3dContext::vfunc_109() {
    ViewInfo* k0 = (*(ViewInfo * *)&this->f_48);
    Matrix_323ee0 mat;
    FUN_0022b980(&mat);
    float W = (float)(*(Viewport_323ee0 * *)&this->f_154)->GetWidth();
    float H = (float)(*(Viewport_323ee0 * *)&this->f_154)->GetHeight();
    ViewInfo* k = (*(ViewInfo * *)&this->f_48);
    volatile float nf[2];
    switch (k->mode) {
    case 0: {
        nf[0] = k0->nearZ;
        nf[1] = k0->farZ;
        float A = (float)tan((*(ViewInfo * *)&this->f_48)->fov * 0.5) * (*(ViewInfo * *)&this->f_48)->nearZ;
        float X = A / (*(ViewInfo * *)&this->f_48)->aspect;
        float v20 = (k->x0 + k->x0) / (k->x1 - k->x0) + 1.0f;
        if (v20 > 1.0f)
            v20 = 1.0f;
        float v1c = 1.0f - ((k->x1 - 1.0f) * 2.0f) / (k->x1 - k->x0);
        if (v1c > 1.0f)
            v1c = 1.0f;
        float va = ((k->y1 - 1.0f) * 2.0f) / (k->y0 - k->y1) + 1.0f;
        if (va > 1.0f)
            va = 1.0f;
        float vb = 1.0f - (k->y0 + k->y0) / (k->y0 - k->y1);
        if (vb > 1.0f)
            vb = 1.0f;
        float right = v1c * A;
        float left = -(v20 * A);
        float bottom = vb * X;
        float top = -(X * va);
        float Q = nf[1] / (nf[1] - nf[0]);
        volatile float w2 = bottom - top;
        mat.m[0] = (nf[0] + nf[0]) / (right - left);
        mat.m[1] = 0;
        mat.m[2] = 0;
        mat.m[3] = 0;
        mat.m[4] = 0;
        mat.m[5] = (nf[0] + nf[0]) / w2;
        mat.m[6] = 0;
        mat.m[7] = 0;
        mat.m[8] = -((left + right) / (right - left));
        mat.m[9] = -((top + bottom) / w2);
        mat.m[10] = Q;
        mat.m[11] = 1.0f;
        mat.m[12] = 0;
        mat.m[13] = 0;
        mat.m[14] = -(Q * nf[0]);
        mat.m[15] = 0;
        if (k->x0 < 0.0f)
            k->x0 = 0.0f;
        if (k->x1 > 1.0f)
            k->x1 = 1.0f;
        if (k->y1 > 1.0f)
            k->y1 = 1.0f;
        if (k->y0 < 0.0f)
            k->y0 = 0.0f;
        ((d3dContext_nv_323ee0*)this)->FUN_00321520(W * k->x0, H * k->y0, (k->x1 - k->x0) * W, (k->y1 - k->y0) * H);
        break;
    }
    case 1: {
        nf[0] = k0->nearZ;
        nf[1] = k0->farZ;
        mat.m[0] = 2.0f;
        float s = 1.0f / k0->aspect;
        mat.m[5] = 2.0f / (0.0f - ((-0.5f * s) - (0.5f * s)));
        float r = 1.0f / (nf[1] - nf[0]);
        mat.m[10] = r;
        mat.m[14] = -(r * nf[0]);
        ((d3dContext_nv_323ee0*)this)->FUN_00321520(W * k->x0, H * k->y0, (k->x1 - k->x0) * W, (k->y1 - k->y0) * H);
        break;
    }
    case 2: {
        nf[0] = k0->nearZ;
        nf[1] = k0->farZ;
        mat.m[12] = -1.0f;
        mat.m[0] = 2.0f / ((W - 0.5f) - (-0.5f));
        mat.m[13] = 1.0f;
        mat.m[5] = 2.0f / (-0.5f - (H - 0.5f));
        float r = 1.0f / (nf[1] - nf[0]);
        mat.m[10] = r;
        mat.m[14] = -(r * nf[0]);
        ((d3dContext_nv_323ee0*)this)->FUN_00321520(0.0f, 0.0f, W, H);
        break;
    }
    }
    D3D8::D3DDevice_SetTransform(1, &mat);
}


// 0x00324270 FUN_00324270 (768 B): equivalent/0x00324270.cpp [wrapped: conflict: pure3d::Light; pure3d::Shader]
// sym: ?FUN_00324270@Shader@pure3d@fn_00324270@@QAEXPAVColorSource@23@@Z @b3fa6b00921a @w05676adf9111
namespace fn_00324270 {
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 18/18)
// FUN_00324270 @ 0x00324270
// FUN_00324270 @ 0x00324270
namespace pure3d {
struct Vec4_324270 {
    float x;
    float y;
    float z;
    union {
        float w;
        unsigned int wBits;
    };
};
// equiv-conv: FUN_0031ffc0 ecx stack
void FUN_0031ffc0(Vec4_324270* self, unsigned int packed);
struct Matrix {
    float m[16];
    void FUN_0022c0b0();
};
struct ShaderColors {
    unsigned int c0;
    unsigned int c1;
    unsigned int c2;
    unsigned int c3;
    unsigned int extra;
};
struct Light {
    int type;
    Vec4_324270 diffuse;
    Vec4_324270 specular;
    Vec4_324270 ambient;
    float position[3];
    Vec4_324270 directionRange;
    float falloff;
    float attenuation[3];
    float theta;
    float phi;
};
class ColorSource {
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
    virtual void v21(ShaderColors* out);
};
class Shader {
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
    void FUN_00321310();
    void FUN_00321dc0(int* ids, int key);
    void FUN_00324270(ColorSource* source);
};
}
namespace D3D8 {
void __stdcall D3DDevice_GetLight(int index, pure3d::Light* out);
void __stdcall D3DDevice_GetTransform(int state, pure3d::Matrix* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(int reg, const void* data);
}

void pure3d::Shader::FUN_00324270(ColorSource* source) {
    int ids[4];
    Vec4_324270 constA, zero, out1, out2, out3, out4, out5;
    ShaderColors colors;
    unsigned int scratch;
    Matrix view, inverse;
    Light light0, light1, light2, light3;

    FUN_00321310();
    constA.x = 0.0f;
    constA.y = 1.0f;
    constA.z = 256.0f;
    constA.w = 0.5f;
    FUN_00321dc0(ids, 0);
    int id0 = ids[0];
    int id1 = ids[1];
    D3D8::D3DDevice_GetLight(id0 == -1 ? 0 : id0, &light0);
    D3D8::D3DDevice_GetLight(id1 == -1 ? 0 : id1, &light1);
    D3D8::D3DDevice_GetLight(ids[2] == -1 ? 0 : ids[2], &light2);
    D3D8::D3DDevice_GetLight(ids[3] == -1 ? 0 : ids[3], &light3);
    source->v21(&colors);
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    zero.w = 0.0f;
    FUN_0031ffc0(&out1, colors.c1);
    FUN_0031ffc0(&out2, colors.c0);
    FUN_0031ffc0(&out3, colors.c3);
    FUN_0031ffc0(&out4, colors.c2);
    FUN_0031ffc0(&out5, *v36(&scratch));
    if (out3.w == 0.0f) {
        out3.wBits = out2.wBits;
        out2.wBits = 0;
    }
    out1.wBits = colors.extra;
    out3.x = out5.x * out4.x + out3.x;
    out3.y = out5.y * out4.y + out3.y;
    out3.z = out5.z * out4.z + out3.z;
    out3.w = out5.w * out4.w + out3.w;
    D3D8::D3DDevice_GetTransform(1, &view);
    inverse = view;
    inverse.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, &constA);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x62, &inverse);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x66, &out2);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x67, &out1);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x68, &out3);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x69, &light0.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6a, id0 != -1 ? &light0.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6b, &light1.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6c, id1 != -1 ? &light1.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6d, &light2.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6e, ids[2] != -1 ? &light2.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6f, &light3.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x70, ids[3] != -1 ? &light3.diffuse : &zero);
}
} // namespace fn_00324270


// 0x00324590 pure3d::d3dExtGammaControl::vfunc_1 (8 B): matches/0x00324590.cpp
// sym: ?vfunc_1@d3dExtGammaControl@pure3d@@UAEXHHH@Z
// Same code shape as 0x000244a0 (propagated; names are from that function)
void pure3d::d3dExtGammaControl::vfunc_1(int a0, int a1, int a2) {
    (*(Y_324590 * *)&this->f_04)->g(a0, a1, a2);
}


// 0x003245a0 pure3d::d3dExtGammaControl::vfunc_2 (8 B): matches/0x003245a0.cpp
// sym: ?vfunc_2@d3dExtGammaControl@pure3d@@UAEXHHH@Z
// Same code shape as 0x000244a0 (propagated; names are from that function)
void pure3d::d3dExtGammaControl::vfunc_2(int a0, int a1, int a2) {
    ((owners::C_31b360 *)((*(Y_3245a0 * *)&this->f_04)))->FUN_0031b360((int *)(hulk_uintptr)(int)a0, (int *)(hulk_uintptr)(int)a1, (int *)(hulk_uintptr)(int)a2);
}


// 0x003245b0 pure3d::d3dExtGammaControl::vfunc_0 (31 B): matches/0x003245b0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_003245b0@@UAEPAV123@E@Z
namespace fn_003245b0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class pddiExtGammaControl_3245b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public pddiExtGammaControl_3245b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_003245b0


// 0x003245d0 pure3d::d3dExtHardwareSkinning::vfunc_6 (143 B): matches/0x003245d0.cpp
// sym: ?vfunc_6@d3dExtHardwareSkinning@pure3d@@UAEXHH@Z
 // namespace pure3d
void pure3d::d3dExtHardwareSkinning::vfunc_6(hulk_intptr __p0, hulk_intptr __p1) { Skin_3245d0 * skin = (Skin_3245d0 *)__p0; Receiver_3245d0 * receiver = (Receiver_3245d0 *)__p1;

    Local_3245d0 data;
    (*(Device_3245d0 * *)&this->f_04)->FUN_00324270(skin);
    skin->active = 1;
    (*(Device_3245d0 * *)&this->f_04)->v47(0, &data);
    skin->s9(0x5654494c, &data);
    if (skin->s22())
        skin->s24();
    for (int i = 0; i < skin->s11(); ++i) {
        skin->FUN_00327d00();
        skin->FUN_00327d20(i);
        receiver->FUN_003272f0();
    }
    skin->active = 0;
}

namespace fn_f57e27cb {

// 0x00324660 FUN_00324660 (923 B): equivalent/0x00324660.cpp
// sym: ?Draw@FilterPass@fn_f57e27cb@@QAEXPBUVec3_324660@2@MM0MMHHMM@Z @aac31f5d514e @w772ac4750a55
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 7/8, incomplete)
// FUN_00324660 @ 0x00324660
void FilterPass::Draw(const Vec3_324660* a, float f1, float f2, const Vec3_324660* b, float f3, float f4, int w, int h, float u, float v) {
    Locals_324660 L;
    D3D8::D3DDevice_SetVertexShader(0x104);
    float fw = (float)w - 0.5f;
    float fh = (float)h - 0.5f;
    Vertex_324660* verts = L.verts;
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

} // namespace fn_f57e27cb

// 0x00324a00 pure3d::d3dExtFramebufferEffects::vfunc_6 (1021 B): equivalent/0x00324a00.cpp [wrapped: conflict: pure3d::d3dExtFramebufferEffects]
// sym: ?vfunc_6@d3dExtFramebufferEffects@pure3d@fn_00324a00@@UAEXXZ @0ec074a5055f @wd158f902a60f
namespace fn_00324a00 {
// STATUS: equivalent (tools/equiv.py level 3: 3023 inputs, branch coverage 14/14)
// pure3d::d3dExtFramebufferEffects::vfunc_6 @ 0x00324a00
typedef unsigned int U_324a00;
extern U_324a00 DAT_0039db08, DAT_0039db10, DAT_0039db14, DAT_0039db18, DAT_0039db40, DAT_0039db48, DAT_0039db50;
extern U_324a00 DAT_0039dbc0, DAT_0039dbd0, DAT_0039ddfc, DAT_0039de00, DAT_0039de08, DAT_0039de0c, DAT_0039de38;
extern U_324a00 DAT_0039de80, DAT_0039dea8, DAT_0039df3c, DAT_0039df4c, DAT_0039df50;
namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_FillMode(U_324a00);
void __fastcall D3DDevice_SetRenderState_Simple(U_324a00, U_324a00);
void __stdcall D3DDevice_SetRenderState_ZEnable(U_324a00);
void __stdcall D3DDevice_SetRenderState_StencilEnable(U_324a00);
void __stdcall D3DDevice_GetPixelShader(U_324a00*);
void __stdcall D3DDevice_GetVertexShader(U_324a00*);
void __stdcall Get2DSurfaceDesc(void*, U_324a00, void*);
void __stdcall D3DDevice_SetTexture(U_324a00, void*);
void __stdcall D3DDevice_SetPixelShader(U_324a00);
void __stdcall D3DDevice_SetVertexShader(U_324a00);
}
namespace XGRAPHC { int __stdcall XGIsSwizzledFormat(U_324a00); }
struct Device_324a00 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual U_324a00 v6();
    virtual U_324a00 v7();
};
struct Context { char pad[HULK_D3DCTX_PAD(f_154, 0x154, 0)]; Device_324a00* device; };
struct SurfaceDesc_324a00 { U_324a00 format, type, usage, size, multiSample, width, height; };
namespace pure3d {
struct d3dExtFramebufferEffects {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    Context* context;
    char pad08[0x18];
    void* surface;
    char pad24[0x48];
    U_324a00 a, b, c;
    float intensity;
    unsigned char active, enabled;
    char pad7e[2];
    char data[0x40];
    void FUN_00323910();
    void FUN_00320aa0(void*);
    void FUN_00324660(float*, U_324a00, U_324a00, void*, U_324a00, float, U_324a00, U_324a00, float, float);
};
}
void pure3d::d3dExtFramebufferEffects::vfunc_6() {
    if (active || !enabled)
        return;
    FUN_00323910();
    if (active)
        return;
    U_324a00 savedFillArg = DAT_0039df3c;
    U_324a00 savedFill = DAT_0039dea8;
    U_324a00 savedZArg = DAT_0039df4c;
    U_324a00 savedBlend = DAT_0039ddfc;
    U_324a00 savedStencil = DAT_0039de80;
    U_324a00 savedZ = DAT_0039de00;
    U_324a00 savedDst = DAT_0039de0c;
    U_324a00 savedStencilArg = DAT_0039df50;
    U_324a00 savedOp = DAT_0039de38;
    U_324a00 savedSrc = DAT_0039de08;
    DAT_0039db08 |= 0x1200;
    DAT_0039dea8 = 0;
    D3D8::D3DDevice_SetRenderState_FillMode(0x1b02);
    D3D8::D3DDevice_SetRenderState_Simple(0x40300, 0);
    DAT_0039de00 = 0;
    D3D8::D3DDevice_SetRenderState_ZEnable(0);
    D3D8::D3DDevice_SetRenderState_StencilEnable(0);
    DAT_0039db08 |= 0x2000;
    DAT_0039de80 = 0;
    D3D8::D3DDevice_SetRenderState_Simple(0x40304, 0);
    DAT_0039ddfc = 0;
    D3D8::D3DDevice_SetRenderState_Simple(0x40350, 0x8006);
    DAT_0039de38 = 0x8006;
    D3D8::D3DDevice_SetRenderState_Simple(0x40344, 1);
    DAT_0039de08 = 1;
    D3D8::D3DDevice_SetRenderState_Simple(0x40348, 0);
    U_324a00 old48 = DAT_0039db48;
    U_324a00 old40 = DAT_0039db40;
    U_324a00 old50 = DAT_0039db50;
    U_324a00 oldD0 = DAT_0039dbd0;
    U_324a00 oldC0 = DAT_0039dbc0;
    U_324a00 old18 = DAT_0039db18;
    U_324a00 old10 = DAT_0039db10;
    U_324a00 old14 = DAT_0039db14;
    DAT_0039db40 = 2;
    DAT_0039db48 = 2;
    DAT_0039de0c = 0;
    DAT_0039db50 = 1;
    DAT_0039dbc0 = 1;
    DAT_0039dbd0 = 1;
    DAT_0039db10 = 5;
    DAT_0039db08 |= 0x801;
    DAT_0039db14 = 5;
    DAT_0039db18 = 5;
    U_324a00 pixelShader;
    U_324a00 vertexShader;
    D3D8::D3DDevice_GetPixelShader(&pixelShader);
    D3D8::D3DDevice_GetVertexShader(&vertexShader);
    float tint[3];
    tint[0] = 0.25f;
    tint[1] = 0.625f;
    tint[2] = 0.125f;
    FUN_00320aa0(surface);
    SurfaceDesc_324a00 desc;
    D3D8::Get2DSurfaceDesc(surface, 0, &desc);
    float w;
    if (XGRAPHC::XGIsSwizzledFormat(desc.format))
        w = 1.0f;
    else
        w = (float)desc.height;
    float h;
    if (XGRAPHC::XGIsSwizzledFormat(desc.format))
        h = 1.0f;
    else
        h = (float)desc.width;
    Device_324a00* dev = context->device;
    FUN_00324660(tint, a, b, data, c, intensity * 0.5f, dev->v7(), dev->v6(), h, w);
    D3D8::D3DDevice_SetTexture(0, 0);
    D3D8::D3DDevice_SetPixelShader(pixelShader);
    D3D8::D3DDevice_SetVertexShader(vertexShader);
    DAT_0039db48 = old48;
    DAT_0039db40 = old40;
    DAT_0039dbd0 = oldD0;
    DAT_0039dbc0 = oldC0;
    DAT_0039db50 = old50;
    DAT_0039db18 = old18;
    DAT_0039db14 = old14;
    DAT_0039db10 = old10;
    DAT_0039db08 |= 0x1a01;
    DAT_0039dea8 = savedFill;
    D3D8::D3DDevice_SetRenderState_FillMode(savedFillArg);
    D3D8::D3DDevice_SetRenderState_Simple(0x40300, savedZ);
    DAT_0039de00 = savedZ;
    D3D8::D3DDevice_SetRenderState_ZEnable(savedZArg);
    D3D8::D3DDevice_SetRenderState_StencilEnable(savedStencilArg);
    DAT_0039db08 |= 0x2000;
    DAT_0039de80 = savedStencil;
    D3D8::D3DDevice_SetRenderState_Simple(0x40304, savedBlend);
    DAT_0039ddfc = savedBlend;
    D3D8::D3DDevice_SetRenderState_Simple(0x40350, savedOp);
    DAT_0039de38 = savedOp;
    D3D8::D3DDevice_SetRenderState_Simple(0x40344, savedSrc);
    DAT_0039de08 = savedSrc;
    D3D8::D3DDevice_SetRenderState_Simple(0x40348, savedDst);
    DAT_0039de0c = savedDst;
}
} // namespace fn_00324a00


// 0x00324e00 FUN_00324e00 (742 B): matches/0x00324e00.cpp [wrapped: conflict: d3dContext]
// sym: ??0d3dContext@fn_00324e00@@QAE@PAVAssetSource@1@PAVAllocator@1@@Z
namespace fn_00324e00 {
// FUN_00324e00 @ 0x00324e00
// FUN_00324e00 @ 0x00324e00
extern "C" void* __cdecl FUN_0008d690(unsigned int);
// The pddi objects below live on the game's heap (the original's inlined operator new is the allocator call).
struct HeapObj {
    static void* operator new(hulk_uintptr size) throw() { return FUN_0008d690((unsigned int)size); }
};
struct Matrix {
    float m[16];
    void FUN_0022b980();
};
class d3dContext;
class AssetSource {
  public:
    virtual void AddRef();
    char pad4[0x10 - 4];
    int handle;
};
class Allocator {
  public:
    virtual void AddRef();
};
// The objects whose constructors live elsewhere are named by the constructor's address (the native link binds a
// constructor of a class named FUN_<addr> to the definition there): the state cache (0x00328fc0), the light pool
// (0x00329430), pure3d::d3dExtFramebufferEffects (0x003224b0) and pure3d::d3dSimpleShader (0x0032a9f0).
class FUN_00328fc0 : public HeapObj {
  public:
    FUN_00328fc0(d3dContext* ctx, int handle) throw();
    char pad[sizeof(owners::State_328f10)];
};
class FUN_00329430 : public HeapObj {
  public:
    FUN_00329430(d3dContext* ctx) throw();
    char pad[sizeof(Registry_329430)];
};
class FUN_003224b0 : public HeapObj {
  public:
    FUN_003224b0(d3dContext* ctx) throw();
    char pad[0x190];
};
class FUN_0032a9f0 : public HeapObj {
  public:
    FUN_0032a9f0(d3dContext* ctx) throw();
    virtual void f0();
    char pad[0x94 - 4];
};
// The extensions constructed inline store the game's vftables by address (a local class's own vftable would be the
// 64-bit link's stub).
extern "C" char DAT_00433164[];  // pure3d::d3dContext
extern "C" char DAT_00433324[];  // pure3d::d3dExtGammaControl
extern "C" char DAT_0043307c[];  // pure3d::d3dExtAntialiasControl
extern "C" char DAT_004330a4[];  // pure3d::d3dExtReadPixels
extern "C" char DAT_00433094[];  // pure3d::d3dExtGlobalProjectedTexture
extern "C" char DAT_004330b0[];  // pure3d::d3dExtHardwareSkinning
extern "C" char DAT_004330d0[];  // pure3d::d3dExtVisibilityTest
extern "C" char DAT_004330e8[];  // pure3d::d3dExtVertexProgram
extern "C" char DAT_00433154[];  // pure3d::d3dExtFrameBufferTexture
class d3dExtGammaControl : public HeapObj {
  public:
    void* vftable;
    AssetSource* src;
    d3dExtGammaControl(AssetSource* s) throw() { vftable = DAT_00433324; src = s; }
};
class d3dExtAntialiasControl : public HeapObj {
  public:
    void* vftable;
    d3dContext* ctx;
    d3dExtAntialiasControl(d3dContext* c) throw() { vftable = DAT_0043307c; ctx = c; }
};
class d3dExtReadPixels : public HeapObj {
  public:
    void* vftable;
    d3dContext* ctx;
    d3dExtReadPixels(d3dContext* c) throw() { vftable = DAT_004330a4; ctx = c; }
};
class d3dExtGlobalProjectedTexture : public HeapObj {
  public:
    void* vftable;
    int zero[16];
    char pad[0x444 - 0x44];
    d3dExtGlobalProjectedTexture() throw() {
        vftable = DAT_00433094;
        for (int i = 0; i < 16; i++)
            zero[i] = 0;
    }
};
class d3dExtHardwareSkinning : public HeapObj {
  public:
    void* vftable;
    d3dContext* ctx;
    d3dExtHardwareSkinning(d3dContext* c) throw() { vftable = DAT_004330b0; ctx = c; }
};
class d3dExtVisibilityTest : public HeapObj {
  public:
    void* vftable;
    d3dContext* ctx;
    d3dExtVisibilityTest(d3dContext* c) throw() { vftable = DAT_004330d0; ctx = c; }
};
class d3dExtVertexProgram : public HeapObj {
  public:
    void* vftable;
    d3dContext* ctx;
    d3dExtVertexProgram(d3dContext* c) throw() { vftable = DAT_004330e8; ctx = c; }
};
class d3dExtFrameBufferTexture : public HeapObj {
  public:
    void* vftable;
    d3dContext* ctx;
    int a, b, c;
    d3dExtFrameBufferTexture(d3dContext* x) throw() {
        vftable = DAT_00433154;
        ctx = x;
        a = 0;
        b = 0;
        c = 0;
    }
};
extern "C" void FUN_00328690(d3dContext*);
struct LargeInt { unsigned int lo; int hi; };
void __stdcall FUN_00354ce2(LargeInt*);
// pddiBaseContext, named by its constructor's address (0x0031f410) so that the native link binds the base-constructor call;
// gen's pure3d::pddiBaseContext's size (0x14c; larger on 64-bit, where the context's own fields follow it: f_14c...)
class FUN_0031f410 {
  public:
    FUN_0031f410(AssetSource* a, Allocator* b) throw();
    void* vftable;
    char pad[sizeof(::pure3d::pddiBaseContext) - sizeof(void*)];
};
class d3dContext : public FUN_0031f410 {
  public:
    int counter;
    FUN_00328fc0* stateCache;
    AssetSource* src;
    Allocator* alloc;
    char pad15c[4];
    FUN_0032a9f0* shaders;
    int handle;
    int f168;
    int f16c;
    int f170;
    int width;
    int height;
    int f17c;
    float f180;
    char pad184[0x204 - 0x184];
    void* f204;   // the prim stream (0x00320d30)
    FUN_00329430* lightPool;
    Matrix lightMatrices[8];
    unsigned char lightDirty[8];
    unsigned char anyLightDirty;
    char pad415[3];
    int f418;
    int f41c;
    float msPerTick;
    d3dExtGammaControl* gamma;
    d3dExtAntialiasControl* antialias;
    d3dExtGlobalProjectedTexture* projTex;
    d3dExtReadPixels* readPixels;
    d3dExtHardwareSkinning* hwSkinning;
    d3dExtVisibilityTest* visTest;
    d3dExtVertexProgram* vertexProgram;
    FUN_003224b0* fbEffects;
    d3dExtFrameBufferTexture* fbTexture;
    int f448;
    unsigned char f44c;
    d3dContext(AssetSource* a, Allocator* b) throw();
};
d3dContext::d3dContext(AssetSource* a, Allocator* b) throw() : FUN_0031f410(a, b) {
    HULK_SIZE32(FUN_0031f410, 0x14c);
    vftable = DAT_00433164;
    counter = 0;
    f168 = 0;
    f204 = 0;
    f418 = 0;
    f41c = 0;
    f448 = 0;
    f44c = 0;
    FUN_00328690(this);
    src = a;
    a->AddRef();
    alloc = b;
    b->AddRef();
    handle = src->handle;
    HULK_SIZE32(owners::State_328f10, 0x124);
    stateCache = new FUN_00328fc0(this, handle);
    f16c = 0;
    f170 = 0;
    width = 0x280;
    height = 0x1e0;
    f17c = 0;
    f180 = 1.0f;
    LargeInt freq;
    FUN_00354ce2(&freq);
    msPerTick = 1000.0f / (float)freq.lo;
    HULK_SIZE32(Registry_329430, 0x3cf8);
    lightPool = new FUN_00329430(this);
    for (int i = 0; i < 8; i++) {
        lightMatrices[i].FUN_0022b980();
        lightDirty[i] = 0;
    }
    anyLightDirty = 0;
    gamma = new d3dExtGammaControl(src);
    antialias = new d3dExtAntialiasControl(this);
    readPixels = new d3dExtReadPixels(this);
    projTex = new d3dExtGlobalProjectedTexture();
    hwSkinning = new d3dExtHardwareSkinning(this);
    visTest = new d3dExtVisibilityTest(this);
    vertexProgram = new d3dExtVertexProgram(this);
    fbEffects = new FUN_003224b0(this);
    fbTexture = new d3dExtFrameBufferTexture(this);
    shaders = new FUN_0032a9f0(this);
    shaders->f0();
}
} // namespace fn_00324e00


// 0x00325110 pure3d::d3dExtFramebufferEffects::vfunc_9 (3062 B): equivalent/0x00325110.cpp [wrapped: macros]
// sym: ?vfunc_9@d3dExtFramebufferEffects@pure3d@fn_00325110@@UAEXXZ @ff2b17e099f0 @w6356ac644170
namespace fn_00325110 {
// STATUS: equivalent (tools/equiv.py level 3: 20027 inputs, branch coverage 26/26)
// pure3d::d3dExtFramebufferEffects::vfunc_9 @ 0x00325110
namespace D3D8 { void __stdcall D3DDevice_GetPixelShader(unsigned*); void __stdcall D3DDevice_GetVertexShader(unsigned*); void __stdcall Get2DSurfaceDesc(void*,int,void*); void __stdcall D3DDevice_SetViewport(void*); void __stdcall D3DDevice_SetRenderState_FillMode(int); void __fastcall D3DDevice_SetRenderState_Simple(int,int); void __stdcall D3DDevice_SetRenderState_ZEnable(int); void __stdcall D3DDevice_SetRenderState_StencilEnable(int); void __stdcall D3DDevice_SetTexture(int,void*); void* __stdcall D3DDevice_GetDepthStencilSurface2(); void* __stdcall D3DDevice_GetRenderTarget2(); void* __stdcall D3DTexture_GetSurfaceLevel2(void*,int); void __stdcall D3DDevice_SetRenderTarget(void*,void*); void __stdcall D3DResource_Release(void*); void __stdcall D3DDevice_SetVertexShader(unsigned); void __stdcall D3DDevice_SetPixelShader(unsigned); void __stdcall D3DDevice_SetRenderState_TextureFactor(unsigned); void __stdcall D3DDevice_DrawVerticesUP(int,int,void*,int); void __stdcall D3DDevice_SetPixelShaderConstant(int,void*,int); } namespace XGRAPHC { int __stdcall XGIsSwizzledFormat(int); }
#define G(x) extern volatile int DAT_0039##x
G(db08);G(db10);G(db14);G(db18);G(db1c);G(db20);G(db40);G(db48);G(db4c);G(db50);G(db90);G(db94);G(db98);G(db9c);G(dba0);G(dbc0);G(dbd0);G(dc10);G(dc14);G(dc1c);G(dc20);G(dc90);G(dc94);G(dc9c);G(dca0);G(ddfc);G(de00);G(de08);G(de0c);G(de38);G(de80);G(dea8);G(df3c);G(df4c);G(df50);G(df60);
struct Screen { virtual void f0();virtual void f1();virtual void f2();virtual void f3();virtual void f4();virtual void f5();virtual int height();virtual int width(); }; struct Context { char pad[HULK_D3DCTX_PAD(f_154, 0x154, 0)];Screen* screen; }; struct Desc { int format;char pad[16];unsigned width,height; }; struct Viewport { int x,y,w,h;float nearZ,farZ; }; struct Vertex { float x,y,z,rhw,u,v; }; struct Vertex2 { float x,y,z,rhw,u,v,s,t; };
struct Work { float fx,fy;void* depth;void* target;unsigned oldPS,oldVS;union { float uv[4];struct { int spare[2];int quarterW,quarterH; } size; };int save[23];unsigned p1[4],p0[4];Viewport vp,full,smallVP;Vertex small[4];Vertex2 verts[4];int unused[2];int fullW,fullH;Desc info,db,ds,da; };
namespace pure3d { struct d3dExtFramebufferEffects { virtual void vfunc_0();virtual void vfunc_1();virtual void vfunc_2();virtual void vfunc_3();virtual void vfunc_4();virtual void vfunc_5();virtual void vfunc_6();virtual void vfunc_7();virtual void vfunc_8();virtual void vfunc_9();virtual void vfunc_10();Context* context;char pad0[0x18];void* source;char pad1[0x58];unsigned char flag7c;char pad2[0x23];unsigned pixel;char pad3[4];void* dest;void* intermediate;void* temp;unsigned char flagb4;char pad4[3];unsigned b8,bc;int c0,c4;char pad5[4];int cc;float d0,d4;char pad6[4];unsigned dc;int e0,e4,e8;unsigned char enabled;void FUN_00323910();void FUN_00320330();void FUN_00320aa0(void*);void FUN_00324660(void*,int,int,void*,int,int,int,int,float,float);void* FUN_00323130(void*,void*); }; }
void pure3d::d3dExtFramebufferEffects::vfunc_9() {
 if(!enabled)return;FUN_00323910();FUN_00320330();if(flagb4||flag7c)return;Work a;
#define SAVE(i,n) a.save[i]=DAT_0039##n
 SAVE(0,dea8);SAVE(1,df3c);SAVE(2,de00);SAVE(3,df4c);SAVE(4,df50);SAVE(5,de80);SAVE(6,ddfc);SAVE(7,de38);SAVE(8,de08);SAVE(9,de0c);SAVE(10,df60);SAVE(11,db40);SAVE(12,db48);SAVE(13,db4c);SAVE(14,db50);SAVE(15,dbc0);SAVE(16,dbd0);SAVE(17,db10);SAVE(18,db14);SAVE(19,db18);SAVE(20,db90);SAVE(21,db94);SAVE(22,db98);
 D3D8::D3DDevice_GetPixelShader(&a.oldPS);D3D8::D3DDevice_GetVertexShader(&a.oldVS);
 a.size.quarterW=context->screen->width()/4;a.size.quarterH=context->screen->height()/4;context->screen->width();context->screen->height();a.fullW=context->screen->width();a.fullH=context->screen->height();
 D3D8::Get2DSurfaceDesc(intermediate,0,&a.da);D3D8::Get2DSurfaceDesc(dest,0,&a.db);D3D8::Get2DSurfaceDesc(source,0,&a.ds);
 volatile float halfW=d0*0.5f;double halfH=(double)d4*0.5f;float x0=-d0*0.5f,y0=(float)-halfH,x1=(float)((double)a.fullW-halfW),y1=(float)((double)a.fullH-halfH);
 float uu=(float)a.da.width,vv=(float)a.da.height,su=(float)a.ds.width,sv=(float)a.ds.height;
 for(int i=0;i<4;i++){a.verts[i].x=(i&1)?x1:x0;a.verts[i].y=(i&2)?y1:y0;a.verts[i].z=1;a.verts[i].rhw=1;a.verts[i].u=(i&1)?uu:0;a.verts[i].v=(i&2)?vv:0;a.verts[i].s=(i&1)?su:0;a.verts[i].t=(i&2)?sv:0;}
 float right=(float)((double)a.size.quarterW-0.5f),bottom=(float)((double)a.size.quarterH-0.5f);float du=(float)a.db.width,dv=(float)a.db.height;
 for(int i=0;i<4;i++){a.small[i].x=(i&1)?right:-0.5f;a.small[i].y=(i&2)?bottom:-0.5f;a.small[i].z=1;a.small[i].rhw=1;a.small[i].u=(i&1)?du:0;a.small[i].v=(i&2)?dv:0;}
 FUN_00320aa0(source);a.vp.x=a.vp.y=0;a.vp.w=context->screen->width()/2;a.vp.h=context->screen->height()/2;a.vp.nearZ=0;a.vp.farZ=1;D3D8::D3DDevice_SetViewport(&a.vp);
 DAT_0039db08|=0x1200;DAT_0039dea8=0;D3D8::D3DDevice_SetRenderState_FillMode(0x1b02);D3D8::D3DDevice_SetRenderState_Simple(0x40300,0);DAT_0039de00=0;D3D8::D3DDevice_SetRenderState_ZEnable(0);D3D8::D3DDevice_SetRenderState_StencilEnable(0);DAT_0039db08|=0x2000;DAT_0039de80=0;D3D8::D3DDevice_SetRenderState_Simple(0x40304,0);DAT_0039ddfc=0;D3D8::D3DDevice_SetRenderState_Simple(0x40348,0);DAT_0039de0c=0;D3D8::D3DDevice_SetRenderState_Simple(0x40344,1);DAT_0039de08=1;D3D8::D3DDevice_SetRenderState_Simple(0x40350,0x8006);
 DAT_0039db50=1;DAT_0039dbc0=1;DAT_0039dbd0=1;int dirty=DAT_0039db08|0x80f;DAT_0039de38=0x8006;DAT_0039db40=2;DAT_0039db48=2;DAT_0039db10=5;DAT_0039db14=5;DAT_0039db18=5;DAT_0039db1c=2;DAT_0039db20=2;DAT_0039db9c=2;DAT_0039dba0=2;DAT_0039dc1c=2;DAT_0039dc20=2;DAT_0039dc9c=2;DAT_0039dca0=2;DAT_0039db90=5;DAT_0039db94=5;DAT_0039dc10=5;DAT_0039dc14=5;DAT_0039dc90=5;DAT_0039db08=dirty;DAT_0039dc94=5;
 D3D8::D3DDevice_SetTexture(0,source);a.depth=D3D8::D3DDevice_GetDepthStencilSurface2();a.target=D3D8::D3DDevice_GetRenderTarget2();void* surf=D3D8::D3DTexture_GetSurfaceLevel2(dest,0);D3D8::D3DDevice_SetRenderTarget(surf,0);D3D8::D3DResource_Release(surf);
 D3D8::Get2DSurfaceDesc(source,0,&a.info);a.fx=XGRAPHC::XGIsSwizzledFormat(a.info.format)?1.0f:(float)a.info.height;a.fy=XGRAPHC::XGIsSwizzledFormat(a.info.format)?1.0f:(float)a.info.width;
 Screen* screen=context->screen;a.uv[0]=a.uv[1]=a.uv[2]=1;FUN_00324660(&e0,c4,c0,a.uv,cc,0,screen->width()/2,screen->height()/2,a.fy,a.fx);
 a.smallVP.x=a.smallVP.y=0;a.smallVP.w=context->screen->width()/4;a.smallVP.h=context->screen->height()/4;a.smallVP.nearZ=0;a.smallVP.farZ=1;D3D8::D3DDevice_SetViewport(&a.smallVP);surf=D3D8::D3DTexture_GetSurfaceLevel2(intermediate,0);D3D8::D3DDevice_SetRenderTarget(surf,0);D3D8::D3DResource_Release(surf);D3D8::D3DDevice_SetVertexShader(0x104);D3D8::D3DDevice_SetPixelShader(0);D3D8::D3DDevice_SetRenderState_TextureFactor(dc);dirty=DAT_0039db08;DAT_0039db40=4;DAT_0039db08=dirty|0x800;DAT_0039db4c=3;D3D8::D3DDevice_SetTexture(0,dest);D3D8::D3DDevice_DrawVerticesUP(6,4,a.small,0x18);DAT_0039db08|=0x800;DAT_0039db40=2;D3D8::D3DDevice_SetVertexShader(0x404);void* result=FUN_00323130(intermediate,temp);D3D8::D3DDevice_SetRenderTarget(a.target,a.depth);D3D8::D3DResource_Release(a.target);D3D8::D3DResource_Release(a.depth);
 a.full.x=a.full.y=0;a.full.w=context->screen->width();a.full.h=context->screen->height();a.full.nearZ=0;a.full.farZ=1;D3D8::D3DDevice_SetViewport(&a.full);for(int i=0;i<4;i++){a.p0[i]=b8;a.p1[i]=bc;}D3D8::D3DDevice_SetVertexShader(0x204);D3D8::D3DDevice_SetPixelShader(pixel);D3D8::D3DDevice_SetPixelShaderConstant(0,a.p0,1);D3D8::D3DDevice_SetPixelShaderConstant(1,a.p1,1);dirty=DAT_0039db08|3;DAT_0039db1c=2;DAT_0039db20=2;DAT_0039db9c=2;DAT_0039db08=dirty;DAT_0039dba0=2;D3D8::D3DDevice_SetTexture(0,result);D3D8::D3DDevice_SetTexture(1,source);D3D8::D3DDevice_DrawVerticesUP(6,4,a.verts,0x20);for(int i=0;i<4;i++)D3D8::D3DDevice_SetTexture(i,0);D3D8::D3DDevice_SetPixelShader(a.oldPS);D3D8::D3DDevice_SetVertexShader(a.oldVS);
#define REST(i,n) DAT_0039##n=a.save[i]
 dirty=DAT_0039db08|0x1a03;REST(12,db48);REST(11,db40);REST(15,dbc0);REST(13,db4c);REST(14,db50);REST(18,db14);REST(16,dbd0);REST(17,db10);REST(21,db94);REST(19,db18);REST(20,db90);REST(22,db98);DAT_0039db08=dirty;REST(0,dea8);D3D8::D3DDevice_SetRenderState_FillMode(a.save[1]);int s=a.save[2];D3D8::D3DDevice_SetRenderState_Simple(0x40300,s);DAT_0039de00=s;D3D8::D3DDevice_SetRenderState_ZEnable(a.save[3]);D3D8::D3DDevice_SetRenderState_StencilEnable(a.save[4]);DAT_0039db08|=0x2000;s=a.save[6];REST(5,de80);D3D8::D3DDevice_SetRenderState_Simple(0x40304,s);DAT_0039ddfc=s;s=a.save[7];D3D8::D3DDevice_SetRenderState_Simple(0x40350,s);DAT_0039de38=s;s=a.save[8];D3D8::D3DDevice_SetRenderState_Simple(0x40344,s);DAT_0039de08=s;s=a.save[9];D3D8::D3DDevice_SetRenderState_Simple(0x40348,s);DAT_0039de0c=s;D3D8::D3DDevice_SetRenderState_TextureFactor(a.save[10]);
}
} // namespace fn_00325110
#undef G
#undef REST
#undef SAVE

