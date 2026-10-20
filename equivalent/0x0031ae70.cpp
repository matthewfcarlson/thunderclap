// STATUS: equivalent (tools/equiv.py level 3: 20031 inputs, branch coverage 31/32, incomplete)
// pure3d::d3dDisplay::vfunc_4 @ 0x0031ae70
#include "decls/data/engine/unknown.h"

typedef unsigned long DWORD;
extern "C" void* memset(void*, int, unsigned int);
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
bool FUN_0031adf0(int index);
void FUN_0031c230(long hr);
unsigned char FUN_00356667();
void __stdcall FUN_0037d8e0(int, int);
void FUN_0031bcc0(int, int);
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
            FUN_0031c230(D3D8::Direct3D_CreateDevice(0, 1, 0, 0x40, &pp, &device));
            D3D8::D3DDevice_Swap(0);
            pp.BackBufferFormat = 5;
            D3D8::D3DDevice_Reset(&pp);
        } else {
            FUN_0031c230(D3D8::Direct3D_CreateDevice(0, 1, 0, 0x40, &pp, &device));
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
        FUN_0031c230(texture ? 0 : 0x8007000e);
        D3D8::D3DResource_Release(rt);
    }
    FUN_0031bcc0(init->mode_c, init->mode_d);
    D3D8::D3DDevice_SetVerticalBlankCallback(FUN_0031acc0);
    return device != 0;
}
