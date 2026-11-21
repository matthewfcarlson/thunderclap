/* A null Direct3D 8 (Xbox) and XGraphics: the slice the game's pddi layer calls (which address is which:
 * src/platform/sdl/xdk/imports.h and library.h), keeping what the game reads back (resources and their memory, the
 * viewport, transforms, lights, shaders' handles) and drawing nothing. Written from the documented XDK interfaces
 * (after the owner's fusion-frenzy port, port/host/d3d_null.c).
 *
 * Every object the game gets a pointer to lives in the game arena and the counters in the sim block, so a snapshot
 * carries them. One Swap is one 60 Hz field: the virtual clock moves on by 1/60 s. */
#include <stdio.h>
#include <stdlib.h>
#include "hulk_host.h"
#include "sim.h"

static int trace = -1;
#define T(name) do { if (trace < 0) trace = getenv("HULK_TRACE_D3D") != 0; if (trace) fprintf(stderr, "d3d: %s\n", name); } while (0)
#define W 640
#define H 480

/* a resource is { Common, Data, Lock }; pixel containers add { Format, Size }; ours add the parent (a surface of a
 * texture level) and the byte size */
typedef struct { uint32_t common, data, lock, format, size, parent, bytes, owned; } res;
#define COMMON(type) (1u | ((uint32_t)(type) << 16))
enum { T_VB = 0, T_IB = 1, T_PALETTE = 3, T_TEXTURE = 4, T_SURFACE = 5 };

static uint32_t arena(uint32_t n) { return (uint32_t)(uintptr_t)ff_arena_alloc(n ? n : 16, 64); }
static res* R(uint32_t p) { return PTR(p); }

/* D3DFORMAT -> bits per pixel (Xbox values); DXT formats are 4 (DXT1) or 8 bits per pixel in 4x4 blocks */
static uint32_t bpp(uint32_t fmt) {
    switch (fmt) {
    case 0x00: case 0x01: case 0x0b: case 0x13: case 0x19: case 0x1a: case 0x1b: case 0x1f: case 0x20: return 8;
    case 0x02: case 0x03: case 0x04: case 0x05: case 0x10: case 0x11: case 0x1c: case 0x1d: case 0x28: case 0x2c:
    case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: case 0x38: return 16;
    case 0x0c: return 4;
    case 0x0e: case 0x0f: return 8;
    default: return 32;
    }
}
static int is_dxt(uint32_t fmt) { return fmt == 0x0c || fmt == 0x0e || fmt == 0x0f; }
static int is_linear(uint32_t fmt) {
    return (fmt >= 0x10 && fmt <= 0x18) || fmt == 0x1c || fmt == 0x1d || fmt == 0x1e || fmt == 0x1f || fmt == 0x20 ||
           fmt == 0x2e || fmt == 0x2f || fmt == 0x30 || fmt == 0x31 || fmt == 0x35 || fmt == 0x36 || fmt == 0x37;
}
static uint32_t log2u(uint32_t v) { uint32_t n = 0; while ((1u << n) < v) n++; return n; }
static uint32_t level_pitch(uint32_t fmt, uint32_t w) {
    if (is_dxt(fmt)) return ((w + 3) / 4) * (fmt == 0x0c ? 8 : 16);
    return w * bpp(fmt) / 8;
}
static uint32_t level_bytes(uint32_t fmt, uint32_t w, uint32_t h) {
    if (is_dxt(fmt)) return level_pitch(fmt, w) * ((h + 3) / 4);
    return w * h * bpp(fmt) / 8;
}
/* the dimensions and levels a header's Format/Size words say */
static void dims(const res* r, uint32_t* w, uint32_t* h, uint32_t* levels) {
    if (r->size) {
        *w = (r->size & 0xfff) + 1;
        *h = ((r->size >> 12) & 0xfff) + 1;
    } else {
        *w = 1u << ((r->format >> 20) & 15);
        *h = 1u << ((r->format >> 24) & 15);
    }
    *levels = (r->format >> 16) & 15;
    if (!*levels) *levels = 1;
}
static uint32_t level_offset(uint32_t fmt, uint32_t w, uint32_t h, uint32_t level) {
    uint32_t off = 0;
    for (uint32_t i = 0; i < level; i++) {
        off += level_bytes(fmt, w, h);
        if (w > 1) w >>= 1;
        if (h > 1) h >>= 1;
    }
    return off;
}

static uint32_t new_texture(uint32_t w, uint32_t h, uint32_t levels, uint32_t fmt, int type) {
    res* r = PTR(arena(sizeof(res)));
    r->common = COMMON(type);
    if (!levels) {
        levels = 1;
        for (uint32_t a = w, b = h; a > 1 || b > 1; a >>= 1, b >>= 1) levels++;
    }
    if (is_linear(fmt)) {
        r->format = (fmt << 8) | (1u << 16) | (2u << 4);
        r->size = (w - 1) | (h - 1) << 12 | ((level_pitch(fmt, w) / 64) - (level_pitch(fmt, w) >= 64)) << 24;
        levels = 1;
    } else {
        r->format = (fmt << 8) | (levels << 16) | (log2u(w) << 20) | (log2u(h) << 24) | (2u << 4);
        r->size = 0;
    }
    r->bytes = level_offset(fmt, w, h, levels) + 64;
    r->data = arena(r->bytes);
    r->owned = 1;
    return (uint32_t)(uintptr_t)r;
}
static uint32_t fmt_of(const res* r) { return (r->format >> 8) & 0xff; }

static uint32_t surface_of(uint32_t tex, uint32_t level) {
    res* t = R(tex);
    uint32_t w, h, levels;
    dims(t, &w, &h, &levels);
    res* s = PTR(arena(sizeof(res)));
    s->common = COMMON(T_SURFACE);
    s->data = t->data + level_offset(fmt_of(t), w, h, level);
    s->format = (t->format & ~0x000f0000u) | (1u << 16);
    w = w >> level ? w >> level : 1;
    h = h >> level ? h >> level : 1;
    s->size = (w - 1) | (h - 1) << 12;
    s->parent = tex;
    s->owned = 2;               /* (the header is ours; the texels are the texture's) */
    return (uint32_t)(uintptr_t)s;
}

/* the device's own surfaces */
static void device_objects(void) {
    if (SIM->d3d_back) return;
    SIM->d3d_device = arena(1024);
    SIM->d3d_back = surface_of(new_texture(W, H, 1, 0x1e, T_TEXTURE), 0);      /* LIN_X8R8G8B8 */
    SIM->d3d_depth = surface_of(new_texture(W, H, 1, 0x2e, T_TEXTURE), 0);     /* LIN_D24S8 */
    SIM->d3d_rt = SIM->d3d_back;
    SIM->d3d_ds = SIM->d3d_depth;
}

static void desc(uint32_t r_, uint32_t level, uint32_t* d) {
    res* r = R(r_);
    uint32_t w, h, levels, f = fmt_of(r);
    dims(r, &w, &h, &levels);
    w = w >> level ? w >> level : 1;
    h = h >> level ? h >> level : 1;
    d[0] = f;
    d[1] = (r->common >> 16) & 7;
    d[2] = 0;
    d[3] = level_bytes(f, w, h);
    d[4] = 0;
    d[5] = w;
    d[6] = h;
}

/* ------------------------------------------------------------------------------------------- the device */
FFG(0037d240) { UNUSED; T("Direct3D_Object"); device_objects(); RET(SIM->d3d_device); }
FFG(0037d480) {         /* D3D_GetDeviceCaps(adapter, type, D3DCAPS8*): an Xbox GPU, as far as the game reads */
    UNUSED;
    uint8_t* c = PTR(ARG(2));
    memset(c, 0, 212);
    *(uint32_t*)(c + 0) = 1;
    *(uint32_t*)(c + 88) = 4096;
    *(uint32_t*)(c + 92) = 4096;
    *(uint32_t*)(c + 148) = 4;
    *(uint32_t*)(c + 152) = 4;
    *(uint32_t*)(c + 160) = 8;
    *(float*)(c + 176) = 64.0f;
    *(uint32_t*)(c + 180) = 0xffff;
    *(uint32_t*)(c + 184) = 0xffff;
    *(uint32_t*)(c + 188) = 16;
    *(uint32_t*)(c + 192) = 255;
    *(uint32_t*)(c + 196) = 0xfffe0101;
    *(uint32_t*)(c + 200) = 192;
    *(uint32_t*)(c + 204) = 0xffff0101;
    *(float*)(c + 208) = 1.0f;
    RET(0);
}
FFG(0037d780) { UNUSED; RET(0); }                               /* D3D_CheckDeviceFormat: every format */
FFG(0037d8e0) { UNUSED; RET(0); }                               /* D3D_SetPushBufferSize */
FFG(0037d900) {         /* Direct3D_CreateDevice(adapter, type, window, flags, params*, device**) */
    UNUSED;
    T("CreateDevice");
    device_objects();
    *(uint32_t*)PTR(ARG(5)) = SIM->d3d_device;
    RET(0);
}
FFG(0037d9e0) { UNUSED; memset(PTR(ARG(0)), 0, 16); RET(0); }   /* GetCreationParameters */
FFG(0037da20) { UNUSED; memcpy(SIM->d3d_gamma, PTR(ARG(1)), sizeof SIM->d3d_gamma); RET(0); }   /* SetGammaRamp */
FFG(0037dab0) { UNUSED; memcpy(PTR(ARG(0)), SIM->d3d_gamma, sizeof SIM->d3d_gamma); RET(0); }   /* GetGammaRamp */
static float* xf(uint32_t state) {
    uint32_t i = state < 20 ? state : 20 + (state & 3);
    float* m = SIM->d3d_xf[i];
    if (!SIM->d3d_xf_set[i]) {
        memset(m, 0, 64);
        m[0] = m[5] = m[10] = m[15] = 1.0f;
        SIM->d3d_xf_set[i] = 1;
    }
    return m;
}
FFG(0037db40) { UNUSED; memcpy(xf(ARG(0)), PTR(ARG(1)), 64); RET(0); }     /* SetTransform */
FFG(0037dc60) { UNUSED; memcpy(PTR(ARG(1)), xf(ARG(0)), 64); RET(0); }     /* GetTransform */
FFG(0037dcf0) { UNUSED; memcpy(PTR(ARG(0)), SIM->d3d_viewport, 24); RET(0); }  /* GetViewport */
FFG(0037f720) { UNUSED; memcpy(SIM->d3d_viewport, PTR(ARG(0)), 24); RET(0); }  /* SetViewport */
FFG(0037dd30) { UNUSED; RET(0); }                               /* SetMaterial */
FFG(0037dd80) { UNUSED; RET(0); }                               /* SetBackMaterial */
FFG(0037f950) { UNUSED; if (ARG(0) < 8) memcpy(SIM->d3d_lights[ARG(0)], PTR(ARG(1)), 104); RET(0); }  /* SetLight */
FFG(0037dde0) { UNUSED; if (ARG(0) < 8) memcpy(PTR(ARG(1)), SIM->d3d_lights[ARG(0)], 104); RET(0); }  /* GetLight */
FFG(0037fc10) { UNUSED; RET(0); }                               /* LightEnable */
FFG(0037ded0) { UNUSED; RET(0); }                               /* D3DDevice_Release */
FFG(0037df40) {         /* GetVisibilityTestResult(index, pixels*, timestamp*): done, everything visible */
    UNUSED;
    if (ARG(1)) *(uint32_t*)PTR(ARG(1)) = W * H;
    if (ARG(2)) memset(PTR(ARG(2)), 0, 8);
    RET(0);
}
FFG(0037df10) { UNUSED; }                                       /* D3D_KickOffAndWaitForIdle */
FFG(0037dfb0) { UNUSED; SIM->d3d_vblank_cb = ARG(0); RET(0); }  /* SetVerticalBlankCallback */
FFG(0037dff0) { UNUSED; RET(0); }                               /* BlockUntilVerticalBlank */
FFG(0037eb70) { UNUSED; RET(0); }                               /* Reset */
FFG(0037ec20) {                                                 /* SetRenderTarget(target, depth) */
    UNUSED;
    if (ARG(0)) SIM->d3d_rt = ARG(0);
    SIM->d3d_ds = ARG(1);
    RET(0);
}
static uint32_t addref(uint32_t r) { if (r) R(r)->common++; return r; }
FFG(0037efc0) { UNUSED; device_objects(); RET(addref(SIM->d3d_back)); }       /* GetBackBuffer2 */
FFG(0037f6e0) { UNUSED; device_objects(); RET(addref(SIM->d3d_rt)); }         /* GetRenderTarget2 */
FFG(0037f700) { UNUSED; device_objects(); RET(addref(SIM->d3d_ds)); }         /* GetDepthStencilSurface2 */
FFG(0037f3b0) { UNUSED; RET(0); }                               /* CopyRects */
FFG(0037fda0) { UNUSED; RET(0); }                               /* SetTexture */
FFG(0037ff80) { UNUSED; RET(0); }                               /* SetPalette */
FFG(00380010) { UNUSED; RET(0); }                               /* SetIndices */

/* Swap: the end of a frame */
void ff_frame_end(void);
FFG(00381df0) {
    UNUSED;
    T("Swap");
    if (SIM->d3d_vblank_cb) ff_call(SIM->d3d_vblank_cb, 0);
    ff_frame_end();
    RET(0);
}

/* ------------------------------------------------------------------------------------------- resources */
FFG(00382100) {         /* CreateTexture2(w, h, depth, levels, usage, format, type) -> texture */
    UNUSED;
    uint32_t w = ARG(0), h = ARG(1), d = ARG(2) ? ARG(2) : 1;
    RET(new_texture(w, h * d, ARG(3), ARG(5), T_TEXTURE));
}
FFG(003821c0) { UNUSED; desc(ARG(0), ARG(1), PTR(ARG(2))); RET(0); }          /* D3DTexture_GetLevelDesc */
FFG(0038acb0) { UNUSED; desc(ARG(0), ARG(1), PTR(ARG(2))); RET(0); }          /* the surface-desc helper */
FFG(003821d0) { UNUSED; RET(surface_of(ARG(0), ARG(1))); }                    /* GetSurfaceLevel2 */
FFG(00382220) {         /* D3DTexture_LockRect(tex, level, D3DLOCKED_RECT*, rect, flags) */
    UNUSED;
    res* t = R(ARG(0));
    uint32_t w, h, levels, f = fmt_of(t);
    dims(t, &w, &h, &levels);
    uint32_t* lr = PTR(ARG(2));
    uint32_t lw = w >> ARG(1) ? w >> ARG(1) : 1;
    lr[0] = level_pitch(f, lw);
    lr[1] = t->data + level_offset(f, w, h, ARG(1));
    RET(0);
}
FFG(00382320) {         /* D3DVolumeTexture_LockBox(tex, level, D3DLOCKED_BOX*, box, flags) */
    UNUSED;
    res* t = R(ARG(0));
    uint32_t w, h, levels, f = fmt_of(t);
    dims(t, &w, &h, &levels);
    uint32_t* lb = PTR(ARG(2));
    lb[0] = level_pitch(f, w);
    lb[1] = level_bytes(f, w, h);
    lb[2] = t->data;
    RET(0);
}
FFG(00382400) {         /* CreateImageSurface / render target (w, h, format, surface**) */
    UNUSED;
    uint32_t s = surface_of(new_texture(ARG(0), ARG(1), 1, ARG(2), T_TEXTURE), 0);
    *(uint32_t*)PTR(ARG(3)) = s;
    RET(0);
}
FFG(00382520) { UNUSED; desc(ARG(0), 0, PTR(ARG(1))); RET(0); }               /* D3DSurface_GetDesc */
FFG(00382540) {         /* D3DSurface_LockRect(surface, D3DLOCKED_RECT*, rect, flags) */
    UNUSED;
    res* s = R(ARG(0));
    uint32_t w, h, levels;
    dims(s, &w, &h, &levels);
    uint32_t* lr = PTR(ARG(1));
    lr[0] = level_pitch(fmt_of(s), w);
    lr[1] = s->data;
    RET(0);
}
FFG(003828b0) { UNUSED; RET(ARG(0) ? (++R(ARG(0))->common) & 0xffff : 0); }   /* D3DResource_AddRef */
FFG(003828f0) {                                                                 /* D3DResource_Release */
    UNUSED;
    res* r = R(ARG(0));
    if (!r) { RET(0); return; }
    if (r->common & 0xffff) r->common--;
    uint32_t left = r->common & 0xffff;
    if (!left && r->owned && ARG(0) != SIM->d3d_back && ARG(0) != SIM->d3d_depth) {
        if (r->owned == 1) ff_arena_free(PTR(r->data));
        r->owned = 0;
        ff_arena_free(r);
    }
    RET(left);
}
static uint32_t new_buffer(uint32_t n, int type) {
    res* r = PTR(arena(sizeof(res)));
    r->common = COMMON(type);
    r->bytes = n;
    r->data = arena(n);
    r->owned = 1;
    return (uint32_t)(uintptr_t)r;
}
FFG(00382ce0) { UNUSED; RET(new_buffer(ARG(0), T_IB)); }                      /* CreateIndexBuffer2(bytes) */
FFG(00382db0) { UNUSED; RET(new_buffer(ARG(0), T_VB)); }                      /* CreateVertexBuffer2(bytes) */
FFG(00382e00) { UNUSED; RET(R(ARG(0))->data + ARG(1)); }                      /* D3DVertexBuffer_Lock2(vb, flags) */
FFG(00382e90) {                                                                 /* CreatePalette2(size) */
    UNUSED;
    static const uint32_t entries[4] = {256, 128, 64, 32};
    RET(new_buffer(entries[ARG(0) & 3] * 4, T_PALETTE));
}
FFG(00382ef0) { UNUSED; RET(R(ARG(0))->data); }                               /* D3DPalette_Lock2(palette, flags) */

/* ------------------------------------------------------------------------------------------- drawing, state */
FFG(00383210) { UNUSED; RET(0); }                               /* DrawVerticesUP */
FFG(003834c0) { UNUSED; RET(0); }                               /* DrawVertices */
FFG(00383560) { UNUSED; RET(0); }                               /* DrawIndexedVertices */
FFG(00386d70) { UNUSED; RET(0); }                               /* Clear */
FFG(00384030) { UNUSED; *(uint32_t*)PTR(ARG(2)) = (++SIM->d3d_shaders << 1) | 1; RET(0); }   /* CreateVertexShader */
FFG(00384170) { UNUSED; *(uint32_t*)PTR(ARG(0)) = SIM->d3d_vs; RET(0); }      /* GetVertexShader */
FFG(00384b70) { UNUSED; SIM->d3d_vs = ARG(0); RET(0); }                       /* SetVertexShader */
FFG(00384190) { UNUSED; RET(0); }                               /* SetVertexShaderConstant1 (fastcall) */
FFG(00384240) { UNUSED; RET(0); }                               /* SetVertexShaderConstant4 (fastcall) */
FFG(003843d0) { UNUSED; RET(0); }                               /* SetVertexShaderConstantNotInline (fastcall) */
FFG(00384610) { UNUSED; RET(0); }                               /* SetStreamSource */
FFG(00385290) { UNUSED; RET(0); }                               /* SetRenderState_Simple (fastcall) */
FFG(00385850) { UNUSED; RET(0); }                               /* SetRenderState_FogColor */
FFG(003858a0) { UNUSED; RET(0); }                               /* SetRenderState_CullMode */
FFG(00385950) { UNUSED; RET(0); }                               /* SetRenderState_NormalizeNormals */
FFG(00385990) { UNUSED; RET(0); }                               /* SetRenderState_TextureFactor */
FFG(00385bc0) { UNUSED; RET(0); }                               /* SetRenderState_FillMode */
FFG(00385c70) { UNUSED; RET(0); }                               /* SetRenderState_TwoSidedLighting */
FFG(00385d40) { UNUSED; RET(0); }                               /* SetTextureState_TexCoordIndex */
FFG(00385e50) { UNUSED; RET(0); }                               /* SetTextureState_BumpEnv */
FFG(00386870) { UNUSED; RET(0); }                               /* SetRenderState_ZEnable */
FFG(00386900) { UNUSED; RET(0); }                               /* SetRenderState_StencilEnable */
FFG(003869a0) { UNUSED; RET(0); }                               /* SetRenderState_StencilFail */
FFG(00386be0) { UNUSED; RET(0); }                               /* SetRenderState_MultiSampleAntiAlias */
FFG(00387160) { UNUSED; *(uint32_t*)PTR(ARG(1)) = (++SIM->d3d_shaders << 1) | 1; RET(0); }   /* CreatePixelShader */
FFG(003871b0) { UNUSED; RET(0); }                               /* DeletePixelShader */
FFG(00387210) { UNUSED; *(uint32_t*)PTR(ARG(0)) = SIM->d3d_ps; RET(0); }      /* GetPixelShader */
FFG(00387610) { UNUSED; SIM->d3d_ps = ARG(0); RET(0); }                       /* SetPixelShader */
FFG(00387810) { UNUSED; RET(0); }                               /* SetPixelShaderConstant */

/* ------------------------------------------------------------------------------------------- XGraphics */
typedef struct { uint32_t refs, data, size; } xgbuffer;
static uint32_t xgbuffer_new(const void* p, uint32_t n) {
    xgbuffer* b = ff_arena_alloc(sizeof *b, 16);
    char* d = ff_arena_alloc(n + 1, 16);
    if (n) memcpy(d, p, n);
    b->refs = 1;
    b->data = (uint32_t)(uintptr_t)d;
    b->size = n;
    return (uint32_t)(uintptr_t)b;
}
/* XGAssembleShader(name, src, len, flags, constants**, code**, errors**, listing**, ...): the "code" keeps the text */
FFG(003a8753) {
    UNUSED;
    if (ARG(4)) *(uint32_t*)PTR(ARG(4)) = xgbuffer_new(0, 0);
    if (ARG(5)) *(uint32_t*)PTR(ARG(5)) = xgbuffer_new(PTR(ARG(1)), ARG(2));
    if (ARG(6)) *(uint32_t*)PTR(ARG(6)) = xgbuffer_new(0, 0);
    if (ARG(7)) *(uint32_t*)PTR(ARG(7)) = xgbuffer_new(0, 0);
    RET(0);
}
FFG(003a04fc) { UNUSED; RET(((xgbuffer*)PTR(ARG(0)))->data); }                /* XGBuffer_GetBufferPointer */
FFG(003a41dc) {                                                                 /* XGBuffer_Release */
    UNUSED;
    xgbuffer* b = PTR(ARG(0));
    uint32_t left = b ? --b->refs : 0;
    if (b && !left) {
        ff_arena_free(PTR(b->data));
        ff_arena_free(b);
    }
    RET(left);
}
FFG(003a9114) { UNUSED; RET(!is_linear(ARG(0)) && !is_dxt(ARG(0))); }        /* XGIsSwizzledFormat */
/* XGSwizzleRect(src, pitch, rect, dst, w, h, point, bpp): the null layer keeps texels in row order (nothing
 * samples them) */
FFG(003a9a93) {
    UNUSED;
    uint32_t w = ARG(4), h = ARG(5), bytes = ARG(7), pitch = ARG(1) ? ARG(1) : w * bytes;
    for (uint32_t y = 0; y < h; y++) memcpy((char*)PTR(ARG(3)) + y * w * bytes, (char*)PTR(ARG(0)) + y * pitch, w * bytes);
    RET(0);
}
/* XGSwizzleBox(src, row pitch, slice pitch, box, dst, w, h, d, point, bpp) */
FFG(003aa8fb) {
    UNUSED;
    uint32_t w = ARG(5), h = ARG(6), d = ARG(7), bytes = ARG(9);
    memcpy(PTR(ARG(4)), PTR(ARG(0)), w * h * d * bytes);
    RET(0);
}
