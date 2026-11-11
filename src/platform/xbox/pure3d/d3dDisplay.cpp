// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0031acc0..0x0031b760 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dDisplay
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "decls/data/records.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f5e589ad {
#define TREE_TU_END }
namespace fn_f5e589ad {} using namespace fn_f5e589ad;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f5e589ad {
class pddiObject_31acd0 {
  public:
    pddiObject_31acd0();
    virtual void f();
};
class pddiDisplay : public pddiObject_31acd0 {
  public:
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual bool f4(int*);
    virtual bool f5(int, int, int);
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual void _m_vf15();
    virtual void _m_vf16();
    virtual void _m_vf17();
    pddiDisplay();
};
} // namespace fn_f5e589ad
namespace pure3d {
class pddiDisplay_31ad30 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
}
namespace pure3d {
class pddiObject_31ad30 {};
}
namespace fn_f5e589ad {
class pddiObject_31ad50 {
  public:
    virtual int vfunc_0();
    virtual int vfunc_1();
    virtual int vfunc_2();
};
class pddiDisplay_31ad50 : public pddiObject_31ad50 {};
} // namespace fn_f5e589ad
namespace pure3d {
class pddiDisplay_31ad70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
}
namespace pure3d {
class pddiObject_31ad70 {};
}
namespace pure3d {
class pddiObject_31ad80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
}
namespace pure3d {
class pddiDisplay_31ad80 : public pddiObject_31ad80 {};
}
namespace fn_f5e589ad {
class PddiObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class d3dDisplay : public pddiDisplay {
  public:
    char pad[0x43c - sizeof(pddiDisplay)];
    int a, b, c;
    char gap[0x478 - 0x448];
    int y, x, z;
    bool f5(int, int, int);
};
extern int FUN_00356667();
struct DisplayMode_31adf0 { int width; unsigned char bytes[8]; };
namespace D3D8 {
void D3D_KickOffAndWaitForIdle();
}
namespace D3D8 {
void D3DDevice_BlockUntilVerticalBlank();
}
namespace D3D8 {
void __stdcall D3DDevice_Swap(int);
}
struct RECT { int left, top, right, bottom; };
struct D3DLOCKED_RECT { int Pitch; unsigned char* pBits; };
namespace D3D8 {
void __stdcall D3DDevice_CopyRects(hulk_intptr, int, int, int, int);
}
namespace D3D8 {
void __stdcall D3DSurface_LockRect(int, D3DLOCKED_RECT*, int, int);
}
extern int __stdcall FUN_00382400(int, int, int, int);
class d3dDisplay_31b230 {
public:
    char pad[0x478];
    int height;
    int width;
    int Capture(unsigned char* dest, int unused, const RECT* r, int which);
};
struct GammaRamp {
    unsigned char red[256];
    unsigned char green[256];
    unsigned char blue[256];
};
namespace D3D8 {
void __stdcall D3DDevice_SetGammaRamp(unsigned long flags, GammaRamp* ramp);
}
} // namespace fn_f5e589ad
namespace pure3d {
extern const float ratio1;
}
namespace pure3d {
extern const float ratio2;
}
namespace fn_f5e589ad {
extern int vtD_31b5c0;
extern int vtP;
class d3dDisplay_31b5c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dDisplay_31b5c0* f3(unsigned char);
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
    int pad0[3];
    int x10;
    char pad[0x484];
    int x498;
};
void __stdcall D3DDevice_Release();
void __stdcall D3DResource_Release(int);
struct d3dDisplay_nv_31b5c0 {
    void Run();
};
void thunk_FUN_00267090(d3dDisplay_31b5c0*);
} // namespace fn_f5e589ad
namespace pure3d {
struct DisplayRect {
    int x;
    int y;
    int height;
    int width;
};
}
namespace pure3d {
struct d3dDisplay_nv_31b610 {
    void FUN_0031b230(int, int, DisplayRect*, int);
};
}

// 0x0031acc0 pure3d__d3dDisplay__VBlankCallback (7 B): not yet verified
namespace fn_f5e589ad {

// 0x0031acd0 FUN_0031acd0 (18 B): matches/0x0031acd0.cpp
// sym: ??0pddiDisplay@fn_f5e589ad@@QAE@XZ
pddiDisplay::pddiDisplay() {}

} // namespace fn_f5e589ad

// 0x0031acf0 FUN_0031acf0 (51 B): matches/0x0031acf0.cpp [wrapped: compile error C2264: 'fn_f5e589ad::D3DResource_Release' : error in function definition or declaration; function not called]
// sym: ?FUN_0031acf0@fn_0031acf0@@YIXPAUd3dDisplay_31acf0@1@@Z
namespace fn_0031acf0 {
extern "C" char DAT_004323e4[];
extern "C" char DAT_0043242c[];
typedef unsigned int u32_31acf0;
extern void __stdcall D3DDevice_Release();
extern void __stdcall D3DResource_Release(u32_31acf0);
struct d3dDisplay_31acf0 {
    hulk_uintptr vptr;
    char pad[0x0c];
    u32_31acf0 device;
    char pad2[0x484];
    u32_31acf0 resource;
    void Finish();
};
void __fastcall FUN_0031acf0(d3dDisplay_31acf0* self) {
    u32_31acf0 d = self->device;
    self->vptr = ((hulk_intptr)DAT_0043242c);
    if (d)
        D3DDevice_Release();
    u32_31acf0 r = self->resource;
    if (r)
        D3DResource_Release(r);
    self->vptr = ((hulk_intptr)DAT_004323e4);
    self->Finish();
}
} // namespace fn_0031acf0


// 0x0031ad30 pure3d::d3dDisplay::vfunc_6 (7 B): matches/0x0031ad30.cpp
// sym: ?vfunc_6@d3dDisplay@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::d3dDisplay::vfunc_6() {
    return *(unsigned int*)((char*)this + 0x478);
}


// 0x0031ad40 pure3d::d3dDisplay::vfunc_7 (7 B): matches/0x0031ad40.cpp
// sym: ?vfunc_7@d3dDisplay@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::d3dDisplay::vfunc_7() {
    return this->f_47c;
}


// 0x0031ad50 pure3d::d3dDisplay::vfunc_8 (7 B): matches/0x0031ad50.cpp
// sym: ?vfunc_8@d3dDisplay@pure3d@@UAEHXZ
int pure3d::d3dDisplay::vfunc_8() {
    return *(int*)((char*)this + 0x480);
}

namespace fn_f5e589ad {

// 0x0031ad60 pure3d::d3dDisplay::vfunc_9 (3 B): matches/0x0031ad60.cpp
// sym: ?GetZero@fn_f5e589ad@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f5e589ad

// 0x0031ad70 pure3d::d3dDisplay::vfunc_11 (7 B): matches/0x0031ad70.cpp
// sym: ?vfunc_11@d3dDisplay@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::d3dDisplay::vfunc_11() {
    return *(unsigned int*)((char*)this + 0x470);
}


// 0x0031ad80 pure3d::d3dDisplay::vfunc_12 (7 B): matches/0x0031ad80.cpp
// sym: ?vfunc_12@d3dDisplay@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::d3dDisplay::vfunc_12() {
    return *(unsigned int*)((char*)this + 0x474);
}


// 0x0031ad90 pure3d::d3dDisplay::vfunc_10 (7 B): matches/0x0031ad90.cpp
// sym: ?vfunc_10@d3dDisplay@pure3d@@UAEEXZ
unsigned char pure3d::d3dDisplay::vfunc_10() {
    return (*(char (*)[1080])&this->f_04)[0x433];
}

namespace fn_f5e589ad {

// 0x0031ada0 pure3d::d3dDisplay::vfunc_5 (76 B): matches/0x0031ada0.cpp
// sym: ?f5@d3dDisplay@fn_f5e589ad@@UAE_NHHH@Z
bool d3dDisplay::f5(int p2, int p3, int p4) {
    if (p2 == x && p3 == y && p4 == z)
        return true;
    a = p2;
    b = p3;
    c = p4;
    return f4(&a);
}


// 0x0031adf0 FUN_0031adf0 (113 B): equivalent/0x0031adf0.cpp
// sym: ?FUN_0031adf0@fn_f5e589ad@@YAHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 20/22, incomplete)
// FUN_0031adf0 @ 0x0031adf0
int __cdecl FUN_0031adf0(int index) {
    int flags = (*(int*)&DAT_004d35dc);
    if (flags == -1) {
        flags = FUN_00356667();
        (*(int*)&DAT_004d35dc) = flags;
    }
    DisplayMode_31adf0 &mode = ((DisplayMode_31adf0*)((char*)&DAT_004d3508 + 4))[index];
    int width = mode.width;
    int result = 1;
    if (width == 480) {
        if (mode.bytes[1] && !(flags & 1)) result = 0;
        else if (mode.bytes[0] && !(flags & 8)) result = 0;
    }
    if (result && width == 720 && !(flags & 2)) result = 0;
    if (result && width == 1080 && !(flags & 4)) result = 0;
    return (flags & ~255) | result;
}

} // namespace fn_f5e589ad

// 0x0031ae70 pure3d::d3dDisplay::vfunc_4 (772 B): equivalent/0x0031ae70.cpp [wrapped: macros]
// sym: ?vfunc_4@d3dDisplay@pure3d@fn_0031ae70@@UAE_NPBUDisplayConfig@3@@Z
namespace fn_0031ae70 {
// STATUS: equivalent (tools/equiv.py level 3: 20031 inputs, branch coverage 31/32, incomplete)
// pure3d::d3dDisplay::vfunc_4 @ 0x0031ae70

typedef unsigned long DWORD;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, hulk_uintptr);
#endif

struct PresentParams {
    DWORD BackBufferWidth;
    DWORD BackBufferHeight;
    DWORD BackBufferFormat;
    DWORD BackBufferCount;
    DWORD MultiSampleType;
    DWORD SwapEffect;
    DWORD hDeviceWindow;
    DWORD Windowed;
    DWORD EnableAutoDepthStencil;
    DWORD AutoDepthStencilFormat;
    DWORD Flags;
    DWORD FullScreen_RefreshRateInHz;
    DWORD FullScreen_PresentationInterval;
    DWORD reserved[4];
};
struct SurfaceDesc_31ae70 {
    DWORD Format, Type, Usage, Size, MultiSampleType, Width, Height;
};
struct DisplayConfig {
    int width;
    int height;
    int depth;
    int pad0c;
    int flags;
    int mode_a;
    int mode_b;
    int mode_c;
    int mode_d;
    int msaaA;
    int msaaB;
    unsigned char b2c;
    unsigned char b2d;
    unsigned char createTexture;
    unsigned char autoSelect;
    unsigned char allowInterlaced;
    unsigned char pad31[3];
};
struct ModeEntry {
    int width;
    int height;
    unsigned char scanFlag;
    unsigned char hdFlag;
    unsigned char pad[2];
};
struct Texture;
struct Surface;
namespace D3D8 {
void __stdcall D3DDevice_Reset(PresentParams*);
long __stdcall Direct3D_CreateDevice(DWORD, DWORD, void*, DWORD, PresentParams*, void*);
void __stdcall D3DDevice_Swap(DWORD);
void __stdcall D3DDevice_GetGammaRamp(void*);
Surface* __stdcall D3DDevice_GetRenderTarget2();
void __stdcall D3DSurface_GetDesc(Surface*, SurfaceDesc_31ae70*);
Texture* __stdcall D3DDevice_CreateTexture2(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
void __stdcall D3DResource_Release(void*);
void __stdcall D3DDevice_SetVerticalBlankCallback(void (__cdecl*)(void*));
}
#if defined(HULK_PTR64)
int __cdecl FUN_0031adf0(int index);   // the definition's type (equivalent/0x0031adf0.cpp returns the mode flags | 1): the
                                      // native link checks the IR signatures agree
#else
bool FUN_0031adf0(int index);
#endif
extern "C" void __cdecl FUN_0031c230(int);
unsigned char FUN_00356667();
void __stdcall FUN_0037d8e0(int, int);
extern "C" void FUN_0031bcc0(int, int);
void __cdecl FUN_0031acc0(void*);
namespace pure3d {
class pddiObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class d3dDisplay : public pddiObject {
  public:
    virtual void vfunc_3();
    virtual bool vfunc_4(const DisplayConfig* init);
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
    char pad4[0x10 - 4];
    void* device;
    PresentParams pp;
    char pad58[0x12c - 0x14 - sizeof(PresentParams)];
    unsigned char gammaRamp[0x300];
    int backFormat;
    int depthFormat;
    unsigned char wasReset;
    unsigned char b435;
    unsigned char b436;
    unsigned char hdFlag;
    char pad438[4];
    DisplayConfig cfg;
    int backBufferCount;
    int cfgFlags;
    int curHeight;
    int curWidth;
    int curDepth;
    char pad484[0x490 - 0x484];
    int bbHeight;
    int bbWidth;
    Texture* texture;
};
}
bool pure3d::d3dDisplay::vfunc_4(const DisplayConfig* init) {
    cfg = *init;
    int flags = 0;
    if (cfg.autoSelect) {
        int i = 0;
        for (;;) {
            if (i * 12 >= 0x60) {
                cfg.width = 640;
                cfg.height = 480;
                break;
            }
            if (FUN_0031adf0(i) && ((ModeEntry*)&DAT_004d3508)[i].height <= cfg.height && ((ModeEntry*)&DAT_004d3508)[i].width <= cfg.width) {
                if (!((ModeEntry*)&DAT_004d3508)[i].hdFlag || cfg.allowInterlaced) {
                    cfg.width = ((ModeEntry*)&DAT_004d3508)[i].width;
                    cfg.height = ((ModeEntry*)&DAT_004d3508)[i].height;
                    hdFlag = ((ModeEntry*)&DAT_004d3508)[i].hdFlag;
                    flags = (((ModeEntry*)&DAT_004d3508)[i].scanFlag ? 0x40 : 0x20) | (((ModeEntry*)&DAT_004d3508)[i].hdFlag ? 0x10 : 0);
                    break;
                }
            }
            i++;
        }
    } else {
        cfg.width = 640;
        cfg.height = 480;
    }
    int w = cfg.width;
    int h = cfg.height;
    if (w > 0x2d0)
        cfg.depth = 0x10;
    int depth = cfg.depth;
    int cfgFlagsLocal = cfg.flags;
    b435 = cfg.b2c;
    curWidth = w;
    b436 = cfg.b2d;
    backBufferCount = 1;
    cfgFlags = cfgFlagsLocal;
    curDepth = depth;
    curHeight = h;
    backFormat = 5 + (depth == 0x20);
    if (depth == 0x20)
        depthFormat = 0x2a;
    else
        depthFormat = (cfgFlagsLocal & 4) ? 0x2a : 0x2c;
    memset(&pp, 0, sizeof(pp));
    pp.BackBufferWidth = curWidth;
    pp.BackBufferHeight = curHeight;
    pp.BackBufferFormat = backFormat;
    pp.BackBufferCount = backBufferCount;
    pp.MultiSampleType = cfg.msaaA | cfg.msaaB;
    pp.SwapEffect = 1;
    pp.hDeviceWindow = 0;
    pp.Windowed = 0;
    pp.EnableAutoDepthStencil = 1;
    pp.AutoDepthStencilFormat = depthFormat;
    unsigned char videoFlags = FUN_00356667();
    pp.FullScreen_PresentationInterval = 0x80000000;
    pp.FullScreen_RefreshRateInHz = (videoFlags & 0x40) ? 0x3c : 0;
    pp.Flags = flags;
    if (device) {
        D3D8::D3DDevice_Reset(&pp);
        wasReset = 1;
    } else {
        FUN_0037d8e0(init->mode_a, init->mode_b);
        FUN_0031c230(0);
        if (pp.BackBufferFormat == 5) {
            pp.BackBufferFormat = 6;
            FUN_0031c230((long)(D3D8::Direct3D_CreateDevice(0, 1, 0, 0x40, &pp, &device)));
            D3D8::D3DDevice_Swap(0);
            pp.BackBufferFormat = 5;
            D3D8::D3DDevice_Reset(&pp);
        } else {
            FUN_0031c230((long)(D3D8::Direct3D_CreateDevice(0, 1, 0, 0x40, &pp, &device)));
        }
    }
    D3D8::D3DDevice_GetGammaRamp(gammaRamp);
    Surface* rt = D3D8::D3DDevice_GetRenderTarget2();
    SurfaceDesc_31ae70 desc;
    D3D8::D3DSurface_GetDesc(rt, &desc);
    bbWidth = desc.Width;
    bbHeight = desc.Height;
    if (init->createTexture) {
        texture = D3D8::D3DDevice_CreateTexture2(desc.Width, desc.Height, 1, 1, 1, desc.Format, 3);
        FUN_0031c230((long)(texture ? 0 : 0x8007000e));
        D3D8::D3DResource_Release(rt);
    }
    FUN_0031bcc0(init->mode_c, init->mode_d);
    D3D8::D3DDevice_SetVerticalBlankCallback(FUN_0031acc0);
    return device != 0;
}
} // namespace fn_0031ae70


// 0x0031b180 FUN_0031b180 (7 B): matches/0x0031b180.cpp
// sym: ?FUN_0031b180@A_31b180@owners@@QAEEXZ
unsigned char owners::A_31b180::FUN_0031b180() {
    return value;
}


// 0x0031b190 pure3d::d3dDisplay::vfunc_14 (74 B): matches/0x0031b190.cpp
// sym: ?vfunc_14@d3dDisplay@pure3d@@UAEXXZ
 // namespace D3D8
void pure3d::d3dDisplay::vfunc_14() {
    D3D8::D3D_KickOffAndWaitForIdle();
    unsigned char c = (*(unsigned char*)&DAT_005554a0);
    int n = (*(int*)&DAT_0055549c);
    bool wait = true;
    if (c == 0) {
        if (n == 0)
            D3D8::D3DDevice_BlockUntilVerticalBlank();
        else if (n != 1)
            wait = false;
    }
    if (wait)
        D3D8::D3DDevice_BlockUntilVerticalBlank();
    (*(int*)&DAT_0055549c) = 0;
    this->f_434 = 0;
    D3D8::D3DDevice_Swap(0);
    D3D8::D3D_KickOffAndWaitForIdle();
}


// 0x0031b1e0 FUN_0031b1e0 (65 B): matches/0x0031b1e0.cpp [wrapped: compile error in a shared declaration (C2556)]
// sym: ?target@fn_0031b1e0@@YIXPAUObj_31b1e0@1@PAX@Z
namespace fn_0031b1e0 {
typedef unsigned int U_31b1e0;
struct Obj_31b1e0 {
    char pad[0x498];
    U_31b1e0 texture;
};
extern U_31b1e0 __stdcall D3DDevice_GetRenderTarget2();
extern U_31b1e0 __stdcall D3DTexture_GetSurfaceLevel2(U_31b1e0, U_31b1e0);
extern U_31b1e0 __stdcall D3DDevice_CopyRects(U_31b1e0, U_31b1e0, U_31b1e0, U_31b1e0, U_31b1e0);
extern U_31b1e0 __stdcall D3DResource_Release(U_31b1e0);
void __fastcall target(Obj_31b1e0* self, void*) {
    if (self->texture) {
        U_31b1e0 a = D3DDevice_GetRenderTarget2();
        U_31b1e0 b = D3DTexture_GetSurfaceLevel2(self->texture, 0);
        D3DDevice_CopyRects(a, 0, 0, b, 0);
        D3DResource_Release(a);
        D3DResource_Release(b);
    }
}
} // namespace fn_0031b1e0

namespace fn_f5e589ad {

// 0x0031b230 FUN_0031b230 (264 B): equivalent/0x0031b230.cpp
// sym: ?Capture@d3dDisplay_31b230@fn_f5e589ad@@QAEHPAEHPBURECT@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 40 inputs, branch coverage 10/10)
// FUN_0031b230 @ 0x0031b230
int d3dDisplay_31b230::Capture(unsigned char* dest, int unused, const RECT* r, int which) {
    int w = r->right - r->left;
    int h = r->bottom - r->top;
    int surf = FUN_00382400(w, h, 0, 0x12);
    FUN_0031c230((surf != 0) - 1 & 0x8007000e);
    hulk_intptr back = D3D8::D3DDevice_GetBackBuffer2(which == 0 ? -1 : 0);
    FUN_0031c230(0);
    D3D8::D3DDevice_CopyRects(back, 0, 0, surf, 0);
    D3DLOCKED_RECT lr;
    D3D8::D3DSurface_LockRect(surf, &lr, 0, 0x80);
    FUN_0031c230(0);
    const unsigned char* src = lr.pBits;
    for (int y = 0; y < h; y++) {
        for (int i = 0; i < w * 4; i++)
            dest[i] = src[i];
        dest += w * 4;
        src += lr.Pitch;
    }
    D3D8::D3DResource_Release(surf);
    D3D8::D3DResource_Release(back);
    return width * height * 4;
}

} // namespace fn_f5e589ad

// 0x0031b340 pure3d::d3dDisplay::vfunc_17 (3 B): matches/0x0031b340.cpp [wrapped: same definition as 0x0031ad60 in this TU]
// sym: ?GetZero@fn_0031b340@@YAIXZ
namespace fn_0031b340 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_0031b340


// 0x0031b350 pure3d::d3dDisplay::vfunc_13 (3 B): matches/0x0031b350.cpp [wrapped: same definition as 0x0031ad60 in this TU]
// sym: ?GetZero@fn_0031b350@@YAIXZ
namespace fn_0031b350 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_0031b350


// 0x0031b360 FUN_0031b360 (39 B): matches/0x0031b360.cpp
// sym: ?FUN_0031b360@C_31b360@owners@@QAEXPAH00@Z
void owners::C_31b360::FUN_0031b360(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}


// 0x0031b390 FUN_0031b390 (364 B): equivalent/0x0031b390.cpp
// sym: ?FUN_0031b390@GammaControl_31b390@owners@@QAEXMMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_0031b390 @ 0x0031b390
void owners::GammaControl_31b390::FUN_0031b390(float r, float g, float b) {
    GammaRamp ramp;
    gammaR = r;
    gammaG = g;
    gammaB = b;
    double invR = 1.0 / r;
    double invG = 1.0 / g;
    double invB = 1.0 / b;
    for (int i = 0; i < 256; i++) {
        double vr = pow(srcRed[i] * 0.00390625, invR);
        double vg = pow(srcGreen[i] * 0.00390625, invG);
        double vb = pow(srcBlue[i] * 0.00390625, invB);
        if (vr > 1.0)
            vr = 1.0;
        ramp.red[i] = (unsigned char)(int)(vr * 256.0);
        if (vg > 1.0)
            vg = 1.0;
        ramp.green[i] = (unsigned char)(int)(vg * 256.0);
        if (vb > 1.0)
            vb = 1.0;
        ramp.blue[i] = (unsigned char)(int)(vb * 256.0);
    }
    D3D8::D3DDevice_SetGammaRamp(1, &ramp);
}


// 0x0031b500 pure3d::d3dDisplay::vfunc_16 (24 B): matches/0x0031b500.cpp
// sym: ?vfunc_16@d3dDisplay@pure3d@@UAEMXZ
 // namespace pure3d
hulk_freg pure3d::d3dDisplay::vfunc_16() {
    if (this->f_437)
        return ratio2;
    return ratio1;
}


// 0x0031b520 FUN_0031b520 (154 B): matches/0x0031b520.cpp [wrapped: conflict: pure3d::d3dDisplay]
// sym: ??0d3dDisplay@pure3d@fn_0031b520@@QAE@H@Z
namespace fn_0031b520 {
namespace D3D8 {
void __stdcall D3D_GetDeviceCaps(int, int, void*);
}
extern "C" char DAT_0043242c[];  // pure3d::d3dDisplay's vftable
namespace pure3d {
// pddiObject (0x0031bac0 constructs it: its vftable, then two words). The class is named by its constructor's address
// so that the native link binds the base-constructor call; the vftables are stored by address (a local class's own
// vftable would be the 64-bit link's stub).
class FUN_0031bac0 {
  public:
    FUN_0031bac0() throw();
    void* vftable;
    int field4;
    int field8;
};
struct DisplayMode_31b520 {
    void FUN_00292330();
    char data[0x34];
};
class d3dDisplay : public FUN_0031bac0 {
  public:
    d3dDisplay(int arg) throw();
    int field_c;
    int field_10;
    char pad14[0x58 - 0x14];
    char caps[0x434 - 0x58];
    unsigned char b434, b435, b436, b437;
    int field438;
    DisplayMode_31b520 mode;
    int field470, field474, field478, field47c, field480;
    float scaleX, scaleY, scaleZ;
    char pad490[8];
    int field498;
};
d3dDisplay::d3dDisplay(int arg) throw() {
    HULK_SIZE32(d3dDisplay, 0x49c);
    vftable = (void*)DAT_0043242c;
    mode.FUN_00292330();
    field_c = arg;
    field_10 = 0;
    field438 = 0;
    field470 = 2;
    field474 = 1;
    field478 = 0;
    field47c = 0;
    field480 = 0;
    b434 = 0;
    b435 = 0;
    b436 = 1;
    scaleX = 1.0f;
    scaleY = 1.0f;
    scaleZ = 1.0f;
    D3D8::D3D_GetDeviceCaps(0, 1, caps);
    field498 = 0;
    b437 = 0;
}
} // namespace pure3d
} // namespace fn_0031b520

namespace fn_f5e589ad {

// 0x0031b5c0 pure3d::d3dDisplay::vfunc_3 (72 B): matches/0x0031b5c0.cpp
// sym: ?f3@d3dDisplay_31b5c0@fn_f5e589ad@@UAEPAV12@E@Z
d3dDisplay_31b5c0* d3dDisplay_31b5c0::f3(unsigned char flag) {
    *(hulk_intptr*)this = (hulk_intptr)&vtD_31b5c0;
    if (x10)
        D3DDevice_Release();
    if (x498)
        D3DResource_Release(x498);
    *(hulk_intptr*)this = (hulk_intptr)&vtP;
    ((d3dDisplay_nv_31b5c0*)(((pure3d::d3dDisplay*)this)))->Run();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f5e589ad

// 0x0031b610 pure3d::d3dDisplay::vfunc_15 (60 B): matches/0x0031b610.cpp
// sym: ?vfunc_15@d3dDisplay@pure3d@@UAEXHH@Z
 // namespace pure3d
void pure3d::d3dDisplay::vfunc_15(int a, int b) {
    DisplayRect rect;
    rect.y = 0;
    rect.x = 0;
    rect.width = this->f_478;
    rect.height = (*(int *)&this->f_47c);
    ((d3dDisplay_nv_31b610*)this)->FUN_0031b230(a, b, &rect, 0);
}

