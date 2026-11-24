// MetalFX temporal upscaling (wperf2, docs/performance.md 4.2; Video Options > Upscaler: MetalFX, or Auto on macOS):
// Apple's MTLFXTemporalScaler (macOS 13+), loaded at run time (dlopen of the system framework, the Objective-C runtime
// from C++: nothing linked or vendored). It encodes into bgfx's own command buffer between two views through the
// view hook of our bgfx build (tools/wine_gfx.py PATCHES: bgfx_hulk_mtl_set_view_hook / bgfx_hulk_mtl_texture), so
// it is ordered with bgfx's work in the same frame: upscale.cpp reserves a view, schedules the scaler's inputs (TAA's
// motion, depth and HUD mask: upscale.h) and touches the view; when bgfx's Metal renderer reaches it, the hook encodes
// the scaler and the next view reads its output. Output only. Other platforms: none (mfxAvailable is false).
#include "mfx.h"

#if defined(__APPLE__)
#include <dlfcn.h>
#include <objc/message.h>
#include <objc/runtime.h>
#include <stdio.h>
#include <stdlib.h>

#include <bgfx/bgfx.h>

extern "C" void bgfx_hulk_mtl_set_view_hook(bool (*hook)(uint16_t, void*, void*), void* user);
extern "C" void* bgfx_hulk_mtl_texture(uint16_t idx);

namespace {

typedef void* objp;
SEL sel(const char* n) { return sel_registerName(n); }
objp msg(objp o, const char* s) { return ((objp(*)(objp, SEL))objc_msgSend)(o, sel(s)); }
objp msgP(objp o, const char* s, objp a) { return ((objp(*)(objp, SEL, objp))objc_msgSend)(o, sel(s), a); }
void msgU(objp o, const char* s, unsigned long a) { ((void (*)(objp, SEL, unsigned long))objc_msgSend)(o, sel(s), a); }
void msgB(objp o, const char* s, bool a) { ((void (*)(objp, SEL, signed char))objc_msgSend)(o, sel(s), a ? 1 : 0); }
void msgF(objp o, const char* s, float a) { ((void (*)(objp, SEL, float))objc_msgSend)(o, sel(s), a); }
bool responds(objp o, const char* s)
{
    return ((signed char (*)(objp, SEL, SEL))objc_msgSend)(o, sel("respondsToSelector:"), sel(s)) != 0;
}

enum : unsigned long { kR8Unorm = 10, kRG16Float = 65, kBGRA8Unorm = 80, kRGBA16Float = 115, kDepth32Float = 252 };

struct State {
    int avail = -1;                  // -1 unknown, 0 no, 1 yes
    objp scaler = nullptr;
    bool reactive = false;
    uint32_t inW = 0, inH = 0, outW = 0, outH = 0, colourFmt = 0;
    uint16_t outTex = 0xffff;
    // the scheduled encode
    bool pending = false;
    uint16_t view = 0xffff;
    rm::MfxInputs in;
    uint32_t encoded = 0, failed = 0;
} s;

objp device()
{
    const bgfx::InternalData* d = bgfx::getInternalData();
    return d && bgfx::getRendererType() == bgfx::RendererType::Metal ? (objp)d->context : nullptr;
}

bool hook(uint16_t view, void* cb, void*)
{
    if (!s.pending || view != s.view || !s.scaler)
        return false;
    if (!cb)
        return true;
    s.pending = false;
    objp colour = (objp)bgfx_hulk_mtl_texture(s.in.colour), depth = (objp)bgfx_hulk_mtl_texture(s.in.depth),
         motion = (objp)bgfx_hulk_mtl_texture(s.in.motion), out = (objp)bgfx_hulk_mtl_texture(s.outTex),
         mask = (objp)bgfx_hulk_mtl_texture(s.in.mask);
    if (!colour || !depth || !motion || !out) {
        s.failed++;
        return true;
    }
    objp sc = s.scaler;
    msgP(sc, "setColorTexture:", colour);
    msgP(sc, "setDepthTexture:", depth);
    msgP(sc, "setMotionTexture:", motion);
    msgP(sc, "setOutputTexture:", out);
    if (s.reactive)
        msgP(sc, "setReactiveMaskTexture:", mask);
    msgU(sc, "setInputContentWidth:", s.inW);
    msgU(sc, "setInputContentHeight:", s.inH);
    msgF(sc, "setJitterOffsetX:", s.in.jitter[0]);
    msgF(sc, "setJitterOffsetY:", s.in.jitter[1]);
    msgF(sc, "setMotionVectorScaleX:", s.in.mvScale[0]);
    msgF(sc, "setMotionVectorScaleY:", s.in.mvScale[1]);
    msgB(sc, "setReset:", s.in.reset);
    msgB(sc, "setDepthReversed:", false);
    msgP(sc, "encodeToCommandBuffer:", (objp)cb);
    s.encoded++;
    return true;
}

Class descClass()
{
    static Class c;
    static bool tried;
    if (!tried) {
        tried = true;
        if (dlopen("/System/Library/Frameworks/MetalFX.framework/MetalFX", RTLD_LAZY | RTLD_LOCAL))
            c = objc_getClass("MTLFXTemporalScalerDescriptor");
    }
    return c;
}

void dropScaler()
{
    if (s.scaler)
        msg(s.scaler, "release");
    s.scaler = nullptr;
    if (s.outTex != 0xffff)
        bgfx::destroy(bgfx::TextureHandle{s.outTex});
    s.outTex = 0xffff;
    s.inW = s.inH = s.outW = s.outH = 0;
}

} // namespace

bool rm::mfxAvailable()
{
    if (s.avail >= 0)
        return s.avail == 1;
    objp dev = device();
    if (!dev)
        return false;                      // (not yet: bgfx is not up, or not Metal; asked again later)
    Class c = descClass();
    bool ok = c && ((signed char (*)(objp, SEL, objp))objc_msgSend)((objp)c, sel("supportsDevice:"), dev);
    if (getenv("HULK_MFX") && atoi(getenv("HULK_MFX")) == 0)
        ok = false;
    s.avail = ok ? 1 : 0;
    fprintf(stderr, "hulk-app: MetalFX temporal scaler %s\n", ok ? "available" : "not available on this Mac");
    if (ok)
        bgfx_hulk_mtl_set_view_hook(hook, nullptr);
    return ok;
}

uint16_t rm::mfxPrepare(uint32_t inW, uint32_t inH, uint32_t outW, uint32_t outH, bool hdrColour)
{
    if (!mfxAvailable())
        return 0xffff;
    uint32_t fmt = hdrColour ? kRGBA16Float : kBGRA8Unorm;
    if (s.scaler && s.inW == inW && s.inH == inH && s.outW == outW && s.outH == outH && s.colourFmt == fmt)
        return s.outTex;
    dropScaler();
    objp dev = device();
    Class c = descClass();
    for (int attempt = 0; attempt < 2 && !s.scaler; attempt++) {
        objp d = msg(msg((objp)c, "alloc"), "init");
        if (!d)
            break;
        msgU(d, "setColorTextureFormat:", fmt);
        msgU(d, "setDepthTextureFormat:", kDepth32Float);
        msgU(d, "setMotionTextureFormat:", kRG16Float);
        msgU(d, "setOutputTextureFormat:", kRGBA16Float);
        msgU(d, "setInputWidth:", inW);
        msgU(d, "setInputHeight:", inH);
        msgU(d, "setOutputWidth:", outW);
        msgU(d, "setOutputHeight:", outH);
        msgB(d, "setAutoExposureEnabled:", false);
        // the HUD mask as MetalFX's reactive mask (macOS 14.4+); without it the composite still puts the HUD back
        bool reactive = attempt == 0 && responds(d, "setReactiveMaskTextureEnabled:");
        if (reactive) {
            msgB(d, "setReactiveMaskTextureEnabled:", true);
            msgU(d, "setReactiveMaskTextureFormat:", kR8Unorm);
        }
        objp sc = msgP(d, "newTemporalScalerWithDevice:", dev);
        msg(d, "release");
        if (sc) {
            s.scaler = sc;
            s.reactive = reactive;
        } else if (!reactive) {
            break;
        }
    }
    if (!s.scaler) {
        fprintf(stderr, "hulk-app: MetalFX: no temporal scaler for %ux%u -> %ux%u\n", inW, inH, outW, outH);
        s.avail = 0;
        return 0xffff;
    }
    bgfx::TextureHandle t = bgfx::createTexture2D((uint16_t)outW, (uint16_t)outH, false, 1,
                                                  bgfx::TextureFormat::RGBA16F,
                                                  BGFX_TEXTURE_COMPUTE_WRITE | BGFX_TEXTURE_RT | BGFX_SAMPLER_U_CLAMP |
                                                      BGFX_SAMPLER_V_CLAMP);
    if (!bgfx::isValid(t)) {
        dropScaler();
        return 0xffff;
    }
    s.outTex = t.idx;
    s.inW = inW, s.inH = inH, s.outW = outW, s.outH = outH, s.colourFmt = fmt;
    fprintf(stderr, "hulk-app: MetalFX temporal scaler %ux%u -> %ux%u%s\n", inW, inH, outW, outH,
            s.reactive ? " (HUD as its reactive mask)" : "");
    return s.outTex;
}

void rm::mfxSchedule(uint16_t view, const MfxInputs& in)
{
    s.view = view;
    s.in = in;
    s.pending = true;
    bgfx::touch(view);
}

void rm::mfxStats(uint32_t* encoded, uint32_t* failed)
{
    *encoded = s.encoded, *failed = s.failed;
    s.encoded = s.failed = 0;
}

#else

bool rm::mfxAvailable() { return false; }
uint16_t rm::mfxPrepare(uint32_t, uint32_t, uint32_t, uint32_t, bool) { return 0xffff; }
void rm::mfxSchedule(uint16_t, const MfxInputs&) {}
void rm::mfxStats(uint32_t* encoded, uint32_t* failed) { *encoded = *failed = 0; }

#endif
