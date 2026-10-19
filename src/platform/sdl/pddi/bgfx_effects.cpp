// G4: the framebuffer effects extension (stands in for pure3d::d3dExtFramebufferEffects) and the context's
// full-screen pass machinery it runs on.
//
// Specification: the verified sources in the tree's pure3d/d3dExtFramebufferEffects.cpp (the constructor 0x3224b0,
// slots 0x3225c0 0x3226b0 0x320530 0x3239e0 0x3202a0 0x324a00 0x320290 0x322cd0 0x325110, and FUN_003226d0 /
// FUN_00322990 the overlay, FUN_00320330 / FUN_00323910 the resources, FUN_00320540 the 17 pixel programs built from
// text, FUN_00320aa0 the render-target copy, FUN_00323130 the gaussian, FUN_00324660 the colour pass, FUN_003209f0
// the level), pure3d/d3dFBEffectsShader.cpp (FUN_003285d0 the accumulation), pure3d/d3dVertexProgram.cpp
// (FUN_003287a0 the average) and the game's data the code reads by address (the contrast table 0x432a10, the level
// thresholds, the threshold program's text 0x432da0: only values). What the game asks of Direct3D (render targets,
// CopyRects, pre-transformed DrawVerticesUP quads with pixel shaders) becomes bgfx views: each pass is a view after
// what was drawn so far, drawing into the scene target or one of the extension's own targets (bgfxContext::fx*).
// The pixel programs are translated by hand (shaders/fx/), with the register combiners' clamping and the 8-bit
// constants they get.
//
// Who calls what (the game): CRenderManager FUN_001b93a0 every in-game frame after the scene: slot 4 + 3 (a debug
// button's preset) or slot 5 (the fbeffects shaders' average), slot 6 (the colour pass), slots 8 + 7 when a script
// changed the bloom (FUN_001b98e0), slot 9 (the bloom); FUN_001b8780 slot 7; the HUD's FUN_001c16e0 slot 1 and
// FUN_001c22f0 slot 2 (the motion trail).
#include "bgfx_pddi.h"

#include <bgfx/bgfx.h>
#include <math.h>
#include <string.h>

namespace hulk {
namespace pddi {

enum { kNone = 0xffff };

// ---------------------------------------------------------------------------------------------
// The context's full-screen passes
static const bgfx::VertexLayout& fxLayout()
{
    static bgfx::VertexLayout s_layout;
    static bool s_made;
    if (!s_made) {
        s_layout.begin()
            .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord1, 2, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord2, 2, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord3, 2, bgfx::AttribType::Float)
            .end();
        s_made = true;
    }
    return s_layout;
}

bool bgfxContext::fxEnsure()
{
    if (!m_display || !m_display->m_initialised || !m_display->m_offscreen)
        return false;
    if (m_fxUniforms[0] == kNone) {
        m_fxUniforms[0] = bgfx::createUniform("u_fxC", bgfx::UniformType::Vec4, 8).idx;
        m_fxUniforms[1] = bgfx::createUniform("u_fxProg", bgfx::UniformType::Vec4).idx;
        m_fxUniforms[2] = bgfx::createUniform("u_fxTarget", bgfx::UniformType::Vec4).idx;
        static const char* const kS[4] = {"s_fx0", "s_fx1", "s_fx2", "s_fx3"};
        for (int i = 0; i < 4; i++)
            m_fxSamplers[i] = bgfx::createUniform(kS[i], bgfx::UniformType::Sampler).idx;
        m_fxUniformK = bgfx::createUniform("u_fxK", bgfx::UniformType::Vec4).idx;
        m_fxPrograms[0] = loadProgram("vs_fx", "fs_fx_filter");
        m_fxPrograms[1] = loadProgram("vs_fx", "fs_fx_blur");
        if (m_fxPrograms[0] == kNone || m_fxPrograms[1] == kNone)
            logf("pddi: framebuffer effects: no pass programs for this renderer: the passes are skipped\n");
    }
    return m_fxPrograms[0] != kNone && m_fxPrograms[1] != kNone;
}

// A view after everything submitted so far, drawing into `fb` (kNone: the scene target) over the rectangle; no
// clear. The pass's draws go to it; fxDone hands what follows back to the scene.
uint16_t bgfxContext::fxView(unsigned fb, unsigned x, unsigned y, unsigned w, unsigned h)
{
    if (m_viewUsed || m_clearFlags) {
        if (m_viewId < 250)
            m_viewId++;
        else {
            static int s_logged;
            if (!s_logged++)
                logf("pddi: framebuffer effects: out of bgfx views this frame (passes share one)\n");
        }
    }
    m_viewUsed = true;
    m_clearFlags = 0;
    bgfx::ViewId v = (bgfx::ViewId)m_viewId;
    unsigned target = fb == kNone ? m_display->m_sceneFb : fb;
    bgfx::setViewFrameBuffer(v, bgfx::FrameBufferHandle{(uint16_t)target});
    bgfx::setViewMode(v, bgfx::ViewMode::Sequential);
    bgfx::setViewRect(v, (uint16_t)x, (uint16_t)y, (uint16_t)w, (uint16_t)h);
    bgfx::setViewClear(v, BGFX_CLEAR_NONE);
    bgfx::touch(v);
    return v;
}

void bgfxContext::fxDone()
{
    m_viewUsed = true;                        // the next draw starts a new scene view with the current viewport
    m_clearFlags = 0;
    viewChanged(-1);
}

// FUN_00320aa0: CopyRects of the render target (here always the scene target) into `dstTex`, a texture of its size:
// a blit at the start of a new view
bool bgfxContext::fxCopy(unsigned dstTex)
{
    if (dstTex == kNone || !m_display->m_offscreen)
        return false;
    if (m_viewUsed || m_clearFlags) {
        if (m_viewId >= 250)
            return false;
        m_viewId++;
        m_viewUsed = false;
        m_clearFlags = 0;
        setupView();
    }
    bgfx::TextureRegion dst, src;
    dst.init(bgfx::TextureHandle{(uint16_t)dstTex});
    src.init(bgfx::TextureHandle{(uint16_t)m_display->m_sceneColour});
    bgfx::blit((bgfx::ViewId)m_viewId, dst, src);
    return true;
}

// One quad of a pass. `prog` = u_fxProg (and u_fxK after it when the filter program draws), `consts` = c0.. (already
// as the combiners get them). Renderers with the origin at the bottom left sample targets upside down: v flipped.
void bgfxContext::fxDraw(uint16_t view, uint16_t program, const FxQuad& q, const unsigned* tex, int ntex,
                         uint64_t state, const float* consts, int nconsts, const float* prog)
{
    if (bgfx::getAvailTransientVertexBuffer(4, fxLayout()) < 4)
        return;
    bgfx::TransientVertexBuffer tvb;
    bgfx::allocTransientVertexBuffer(&tvb, 4, fxLayout());
    const bgfx::Caps* caps = bgfx::getCaps();
    bool flip = caps && caps->originBottomLeft;
    float* v = (float*)tvb.data;
    for (int i = 0; i < 4; i++, v += 11) {
        bool right = (i & 1) != 0, bottom = (i & 2) != 0;
        v[0] = right ? q.x1 : q.x0;
        v[1] = bottom ? q.y1 : q.y0;
        v[2] = 0.0f;
        for (int s = 0; s < 4; s++) {
            v[3 + 2 * s] = right ? q.uv[s][2] : q.uv[s][0];
            float tv = bottom ? q.uv[s][3] : q.uv[s][1];
            v[4 + 2 * s] = flip ? 1.0f - tv : tv;
        }
    }
    float target[4] = {2.0f / (float)(m_fxTargetW ? m_fxTargetW : 1), 2.0f / (float)(m_fxTargetH ? m_fxTargetH : 1),
                       0.0f, 0.0f};
    bgfx::setUniform(bgfx::UniformHandle{(uint16_t)m_fxUniforms[2]}, target);
    float c[8][4];
    memset(c, 0, sizeof(c));
    if (consts)
        memcpy(c, consts, 16 * (nconsts > 8 ? 8 : nconsts));
    bgfx::setUniform(bgfx::UniformHandle{(uint16_t)m_fxUniforms[0]}, c, 8);
    bgfx::setUniform(bgfx::UniformHandle{(uint16_t)m_fxUniforms[1]}, prog);
    if (program == m_fxPrograms[0])
        bgfx::setUniform(bgfx::UniformHandle{(uint16_t)m_fxUniformK}, prog + 4);
    for (int i = 0; i < ntex && i < 4; i++)
        bgfx::setTexture((uint8_t)i, bgfx::UniformHandle{(uint16_t)m_fxSamplers[i]},
                         bgfx::TextureHandle{(uint16_t)tex[i]}, BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP);
    bgfx::setVertexBuffer(0, &tvb);
    bgfx::setState(state | BGFX_STATE_PT_TRISTRIP);
    bgfx::submit(view, bgfx::ProgramHandle{program});
}

// ---------------------------------------------------------------------------------------------
// The fbeffects shaders (d3dFBEffectsShader): a draw of one through context slot 32, or its UPDT parameter, adds
// its settings to the frame's sums (FUN_003285d0, the globals at 0x555b68..0x555b84); slot 5 of the extension
// averages and applies them (FUN_003287a0)
static struct {
    int count;
    float sat, bright, mid, contrast;         // 0x555b68 .. 0x555b74
    float c2, c1, c0;                         // 0x555b78 (the colour's byte 2), 0x555b7c (byte 1), 0x555b80 (byte 0)
} s_fbSum;

void fbEffectsAccumulate(bgfxShader* shader)
{
    bgfxFBEffectsShader* s = (bgfxFBEffectsShader*)shader;
    if (!s || !s->m_fxOn)
        return;
    s_fbSum.count++;
    s_fbSum.sat += s->m_fxSat;
    s_fbSum.bright += s->m_fxBright;
    s_fbSum.mid += s->m_fxMid;
    s_fbSum.contrast += s->m_fxContrast;
    s_fbSum.c2 += (float)((s->m_fxTint >> 16) & 255);
    s_fbSum.c1 += (float)((s->m_fxTint >> 8) & 255);
    s_fbSum.c0 += (float)(s->m_fxTint & 255);
}

// ---------------------------------------------------------------------------------------------
// The extension
// 0x3224b0: the overlay at 0.9, the colour correction neutral and off, the bloom on with nothing added (amount 0,
// blend 1), its weights (1, 0, 1), factor opaque white, mix 0.5
bgfxExtFramebufferEffects::bgfxExtFramebufferEffects(bgfxContext* context)
    : m_context(context), m_overlayShader(0), m_overlayTex(0), m_overlayOn(false), m_overlayAlpha(0.9f),
      m_overlayScale(0.0f), m_overlaySplit(false), m_ccScale(1.0f), m_ccAmount(0.0f), m_ccCurve(1.0f),
      m_ccBias(0.5f), m_ccResult(1.0f), m_ccBusy(false), m_ccEnabled(false), m_bAmount(0.0f), m_bBlend(1.0f),
      m_bContrast(1.0f), m_bRadius(0.0f), m_bMix(0.5f), m_bD0(1.0f), m_bD4(1.0f), m_bSigma(0.0f),
      m_bFactor(0xffffffffu), m_bEnabled(true), m_blurBusy(false), m_full(kNone), m_half(kNone), m_halfFb(kNone),
      m_w(0), m_h(0)
{
    m_ccTint[0] = m_ccTint[1] = m_ccTint[2] = 1.0f;
    m_bWeights[0] = 1.0f;
    m_bWeights[1] = 0.0f;
    m_bWeights[2] = 1.0f;
    for (int i = 0; i < 2; i++)
        m_quarter[i] = m_quarterFb[i] = kNone;
    for (int i = 0; i < 20; i++)
        m_positions[i] = m_values[i] = 0.0f;
}

bgfxExtFramebufferEffects::~bgfxExtFramebufferEffects()
{
    if (m_overlayShader)
        m_overlayShader->vfunc_1();
    if (m_overlayTex) {
        m_overlayTex->m_handle = kNone;       // the display's texture
        delete m_overlayTex;
    }
    if (m_context && m_context->m_display && m_context->m_display->m_initialised)
        releaseResources();
}

void bgfxExtFramebufferEffects::releaseResources()
{
    if (m_full != kNone)
        bgfx::destroy(bgfx::TextureHandle{(uint16_t)m_full});
    if (m_halfFb != kNone)
        bgfx::destroy(bgfx::FrameBufferHandle{(uint16_t)m_halfFb});
    for (int i = 0; i < 2; i++)
        if (m_quarterFb[i] != kNone)
            bgfx::destroy(bgfx::FrameBufferHandle{(uint16_t)m_quarterFb[i]});
    m_full = m_half = m_halfFb = kNone;
    for (int i = 0; i < 2; i++)
        m_quarter[i] = m_quarterFb[i] = kNone;
    m_w = m_h = 0;
}

static unsigned makeTarget(unsigned w, unsigned h, unsigned* tex)
{
    bgfx::TextureHandle t = bgfx::createTexture2D((uint16_t)(w ? w : 1), (uint16_t)(h ? h : 1), false, 1,
                                                  bgfx::TextureFormat::BGRA8,
                                                  BGFX_TEXTURE_RT | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP);
    bgfx::FrameBufferHandle fb = bgfx::createFrameBuffer(1, &t, true);
    *tex = t.idx;
    return fb.idx;
}

// FUN_00323910 + FUN_00320330: the full-size copy (the render target's size and format), the half target and the
// two quarter targets (the display's size / 2, / 4); remade when the size changes
bool bgfxExtFramebufferEffects::ensureResources()
{
    bgfxContext* c = m_context;
    if (!c->fxEnsure())
        return false;
    bgfxDisplay* d = c->m_display;
    unsigned w = d->m_targetWidth, h = d->m_targetHeight;
    if (m_full != kNone && w == m_w && h == m_h)
        return true;
    releaseResources();
    m_w = w;
    m_h = h;
    m_full = bgfx::createTexture2D((uint16_t)w, (uint16_t)h, false, 1, bgfx::TextureFormat::BGRA8,
                                   BGFX_TEXTURE_BLIT_DST | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP).idx;
    m_halfFb = makeTarget(w / 2, h / 2, &m_half);
    m_quarterFb[0] = makeTarget(w / 4, h / 4, &m_quarter[0]);
    m_quarterFb[1] = makeTarget(w / 4, h / 4, &m_quarter[1]);
    return true;
}

// the contrast curve above 0 (the game's table at 0x432a10: index = contrast + 0.5)
static const float kContrast[101] = {
        1.0f, 1.01001f, 1.02026f, 1.03076f, 1.04151f, 1.05253f, 1.06382f, 1.07539f, 1.08725f, 1.09941f,
        1.11189f, 1.12468f, 1.13782f, 1.1513f, 1.16514f, 1.17935f, 1.19395f, 1.20895f, 1.22437f, 1.24022f,
        1.25653f, 1.2733f, 1.29056f, 1.30832f, 1.32662f, 1.34546f, 1.36488f, 1.38489f, 1.40553f, 1.42682f,
        1.44878f, 1.47146f, 1.49488f, 1.51908f, 1.5441f, 1.56996f, 1.59672f, 1.62442f, 1.6531f, 1.68281f,
        1.71362f, 1.74556f, 1.77871f, 1.81313f, 1.84888f, 1.88605f, 1.92471f, 1.96495f, 2.00686f, 2.05053f,
        2.09608f, 2.14363f, 2.19329f, 2.24521f, 2.29952f, 2.35639f, 2.416f, 2.47853f, 2.5442f, 2.61322f,
        2.68584f, 2.76235f, 2.84303f, 2.92823f, 3.0183f, 3.11366f, 3.21475f, 3.32208f, 3.43622f, 3.55778f,
        3.68748f, 3.82612f, 3.9746f, 4.13394f, 4.30531f, 4.49006f, 4.68971f, 4.90605f, 5.14113f, 5.39736f,
        5.67756f, 5.98506f, 6.32382f, 6.69857f, 7.11503f, 7.58014f, 8.10242f, 8.69245f, 9.36347f, 10.13227f,
        11.02048f, 12.05631f, 13.27721f, 14.73389f, 16.49652f, 18.66463f, 21.3836f, 24.87321f, 29.47937f,
        35.77384f, 255.0f};

// slot 1 (0x3225c0): the overlay's settings
void bgfxExtFramebufferEffects::vfunc_1(unsigned char on, float alpha, float scale, unsigned char split)
{
    m_overlayOn = on != 0;
    m_overlayAlpha = alpha;
    m_overlayScale = scale;
    m_overlaySplit = split != 0;
}

// slot 2 (0x3226b0 -> FUN_003226d0 / FUN_00322990): the previous frame (the front buffer: GetBackBuffer(-1)) over the
// frame through the context's own 2D path: a "simple" shader with it as TEX, a pixel-space strip from (scale,
// scale x aspect) to (w - scale, h - scale x aspect) of it (texel coordinates: a linear texture), z off, the modelview
// the identity. Scale 0: one quad, alpha-blended at alpha. Otherwise additive, alpha x 254 as the colour: one quad,
// or with split three, one channel each (red, green, blue) at scales 4 apart.
void bgfxExtFramebufferEffects::vfunc_2()
{
    if (!m_overlayOn)
        return;
    bgfxContext* c = m_context;
    bgfxDisplay* d = c->m_display;
    if (!m_overlayShader) {
        m_overlayShader = (bgfxShader*)c->m_device->vfunc_11("simple", 0);
        m_overlayTex = new bgfxTexture(c);
        m_overlayTex->m_linear = true;
        m_overlayTex->m_pddiFormat = 11;
        if (m_overlayShader) {
            m_overlayShader->vfunc_0();
            m_overlayShader->setTexture(0, m_overlayTex);
        }
    }
    if (!m_overlayShader || !d)
        return;
    unsigned prev = d->prevFrame();
    m_overlayTex->m_handle = prev;            // kNone (no scene target): the stage samples white
    m_overlayTex->m_width = d->m_targetWidth;
    m_overlayTex->m_height = d->m_targetHeight;
    float zNear = 0.0f, farv = 1.0f, unused;
#if HULK_PDDI_GAME
    c->vfunc_29(&zNear, &unused, &unused, &farv);          // the view block's near, far, fov, aspect
#else
    zNear = c->m_hostView.nearZ;
    farv = c->m_hostView.aspect;
    unused = 0.0f;
    (void)unused;
#endif
    zNear *= 1.01f;
    c->vfunc_24(2);                           // pixel coordinates
    c->vfunc_58(0);                           // no z
    c->vfunc_13(0);                           // the modelview the identity
    bool single = m_overlayScale == 0.0f;
    int blend = single ? 1 : 2;
    m_overlayShader->setParam(1, 0x444d4c42u, &blend);  // BLMD
    float h = (float)d->vfunc_6(), w = (float)d->vfunc_7();
    unsigned colours[3];
    float scales[3];
    int n = 1;
    if (single) {
        colours[0] = ((uint32_t)(unsigned char)(int)(m_overlayAlpha * 255.0f) << 24) | 0xffffffu;
        scales[0] = m_overlayScale;
    } else {
        unsigned a = (unsigned char)(int)(m_overlayAlpha * 254.0f);
        scales[0] = m_overlayScale;
        scales[1] = m_overlayScale + 4.0f;
        scales[2] = m_overlayScale + 8.0f;
        if (m_overlaySplit) {
            colours[0] = a << 16;
            colours[1] = a << 8;
            colours[2] = a;
            n = 3;
        } else {
            colours[0] = (((a << 8) | a) << 8) | a;
        }
    }
    for (int i = 0; i < n; i++) {
        float u = scales[i], v = farv * scales[i];
        float uMax = w - scales[i], vMax = h - v;
        bgfxPrimStream* p = (bgfxPrimStream*)c->vfunc_30(m_overlayShader, kPrimTriStrip, 0x2021, 4, 0);
        const float pos[4][2] = {{0, 0}, {w, 0}, {0, h}, {w, h}};
        const float uv[4][2] = {{u, v}, {uMax, v}, {u, vMax}, {uMax, vMax}};
        for (int k = 0; k < 4; k++) {
            float xyz[3] = {pos[k][0], pos[k][1], zNear};
            memcpy(p->posPtr, xyz, 12);
            *(unsigned*)p->colorPtr = colours[i];
            memcpy(p->uvPtr, uv[k], 8);
            p->vertex();
        }
        c->vfunc_31(p);
    }
    c->vfunc_24(0);
    c->vfunc_58(1);
}

// slot 3 (0x320530): the colour correction on/off (+0x7d)
void bgfxExtFramebufferEffects::vfunc_3(unsigned char on) { m_ccEnabled = on != 0; }

// slot 4 (0x3239e0): saturation a, brightness b, contrast c (each -100..100), the contrast's midpoint d (0..1),
// a tint. Contrast below 0 scales linearly (and the saturation with it); above, the game's table (0x432a10).
void bgfxExtFramebufferEffects::vfunc_4(float a, float b, float c, float d, unsigned int colour)
{
    m_ccTint[0] = (float)((colour >> 16) & 255) * 0.00392156862745098f;
    m_ccTint[1] = (float)((colour >> 8) & 255) * 0.00392156862745098f;
    m_ccTint[2] = (float)(colour & 255) * 0.00392156862745098f;
    if (!(a >= -100.0f && a <= 100.0f))
        a = a > 100.0f ? 100.0f : -100.0f;
    float initial = a * 0.01f + 1.0f;
    m_ccScale = initial;
    if (!(c >= -100.0f && c <= 100.0f))
        c = c > 100.0f ? 100.0f : -100.0f;
    m_ccCurve = c;
    if (!(d >= 0.0f && d <= 1.0f))
        d = d > 1.0f ? 1.0f : 0.0f;
    m_ccBias = d;
    if (!(b >= -100.0f && b <= 100.0f))
        b = b > 100.0f ? 100.0f : -100.0f;
    m_ccAmount = b * 0.00392156862745098f;
    if (c < 0.0f) {
        m_ccCurve = c * 0.01f + 1.0f;
        m_ccScale = (c * 0.01f + 1.0f) * initial;
    } else {
        m_ccCurve = kContrast[(int)(c + 0.5f)];
    }
    m_ccResult = (m_ccCurve < 1.0f ? m_ccCurve : 1.0f) * m_ccScale;
}

// slot 5 (0x3202a0 -> FUN_003287a0): the frame's fbeffects shaders: none -> the colour correction off; else on,
// with their averages (the colour rebuilt from the averaged bytes); the sums cleared for the next frame
void bgfxExtFramebufferEffects::vfunc_5()
{
    if (!s_fbSum.count) {
        vfunc_3(0);
    } else {
        float scale = 1.0f / (float)s_fbSum.count;
        vfunc_3(1);
        int r = (int)(s_fbSum.c0 * scale), g = (int)(s_fbSum.c1 * scale), b = (int)(s_fbSum.c2 * scale);
        r = r < 0 ? 0 : r > 255 ? 255 : r;
        g = g < 0 ? 0 : g > 255 ? 255 : g;
        b = b < 0 ? 0 : b > 255 ? 255 : b;
        unsigned colour = 0xff000000u | ((unsigned)b << 16) | ((unsigned)g << 8) | (unsigned)r;
        vfunc_4(s_fbSum.sat * scale, s_fbSum.bright * scale, s_fbSum.contrast * scale, s_fbSum.mid * scale, colour);
    }
    memset(&s_fbSum, 0, sizeof(s_fbSum));
}

// the combiners' constants: 8 bits per channel in [0, 1]
static float q8(float v)
{
    v = v < 0.0f ? 0.0f : v > 1.0f ? 1.0f : v;
    return floorf(v * 255.0f + 0.5f) / 255.0f;
}
static void q8v(float* c, float a, float b, float cc, float d)
{
    c[0] = q8(a);
    c[1] = q8(b);
    c[2] = q8(cc);
    c[3] = q8(d);
}

// FUN_003209f0: the level a contrast factor needs (the smallest of 1, 2, 4, .. 64, else 255)
static float fxLevel(float x)
{
    static const float k[7] = {1.0f, 2.0f, 4.0f, 8.0f, 16.0f, 32.0f, 64.0f};
    for (int i = 0; i < 7; i++)
        if (x <= k[i])
            return k[i];
    return 255.0f;
}

// FUN_00320540's text for level `lv` (1..64) and side `pass` as the filter program's parameters: the alpha's
// multipliers co-issued with mul_x2 and the first mad, then the adds of r1.w and whether a mov_x2 is co-issued
// with each
static void fxProgram(int lv, int pass, float* prog)
{
    const char* ops[8];
    int n = 0;
    ops[n++] = "add";
    if (pass == 0) {
        if (lv > 1) {
            ops[n++] = "add";
            if (lv > 2) {
                ops[n++] = "dbl";
                ops[n++] = "add";
                if (lv > 4) {
                    ops[n++] = "dbl";
                    ops[n++] = "add";
                }
            }
        }
    } else {
        ops[n++] = "add";
        if (lv > 1) {
            ops[n++] = "dbl";
            ops[n++] = "add";
            if (lv > 2) {
                ops[n++] = "dbl";
                ops[n++] = "add";
            }
        }
    }
    prog[0] = 0.0f;
    prog[1] = lv >= 32 ? 4.0f : lv >= 16 ? 2.0f : 1.0f;
    prog[2] = lv == 64 ? 2.0f : 1.0f;
    int adds = 0;
    for (int i = 0; i < 4; i++)
        prog[4 + i] = 1.0f;
    for (int i = 0; i < n; i++) {
        if (!strcmp(ops[i], "add"))
            adds++;
        else if (adds >= 1 && adds <= 4)
            prog[4 + adds - 1] = 2.0f;                   // co-issued with the add before it
    }
    prog[3] = (float)adds;
}

// FUN_00324660: the colour pass. weights: the luminance weights (c0); f1 the brightness; f2 the contrast factor;
// colour: the tint; f3 the contrast's midpoint; f4 the saturation (/ 2). The quad covers w x h pixels of the current
// fx view and reads the whole full-size copy. c7 = luminance . tint x f4, c6 = (tint - that + 1) / 2, c3 and c5 the
// brightness curve at the level's scale (1 / level; another half for brightness of 0.5 or more, which takes the
// level's second program); f2 = 255: the threshold program, c5 = ((f1 - f3) / 2 + 1) / 2.
void bgfxExtFramebufferEffects::filterPass(const float* a, float f1, float f2, const float* b, float f3, float f4,
                                           int w, int h)
{
    bgfxContext* c = m_context;
    bool farSide = fabsf(f1) >= 0.5f;
    float dot = a[2] * b[2] + a[1] * b[1] + a[0] * b[0];
    float dd = dot * f4;
    float k[8][4];
    memset(k, 0, sizeof(k));
    float prog[8];
    float base = f2 == 1.0f ? f1 : ((f1 - f3) * f2 + f3) * dot;
    float scale = farSide ? 0.5f : 1.0f;
    q8v(k[0], a[0], a[1], a[2], 0.0f);
    if (f2 == 255.0f) {
        float t = ((f1 - f3) * 0.5f + 1.0f) * 0.5f;
        q8v(k[5], t, t, t, t);
        memset(prog, 0, sizeof(prog));
        prog[0] = 1.0f;
    } else {
        float r = fxLevel(f2);
        float inv = 1.0f / r;
        float q = inv * scale;
        float cv = (base * q + 1.0f) * 0.5f;
        float c5 = f2 * (q * dot);
        q8v(k[3], cv, cv, cv, cv);
        q8v(k[5], c5, c5, c5, c5);
        q8v(k[6], (b[0] - dot + 1.0f) * 0.5f, (b[1] - dot + 1.0f) * 0.5f, (b[2] - dot + 1.0f) * 0.5f, 0.0f);
        q8v(k[7], dd, dd, dd, dd);
        fxProgram((int)r, farSide ? 1 : 0, prog);
    }
    bgfxContext::FxQuad quad;
    memset(&quad, 0, sizeof(quad));
    quad.x1 = (float)w;
    quad.y1 = (float)h;
    quad.uv[0][2] = quad.uv[0][3] = 1.0f;
    c->fxDraw((uint16_t)c->m_viewId, (uint16_t)c->m_fxPrograms[0], quad, &m_full, 1,
              BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A, k[0], 8, prog);
}

// slot 6 (0x324a00): the colour correction: the render target copied (FUN_00320aa0), then the colour pass over the
// display's size from the copy back into it (no blending, no z, no stencil), luminance weights (0.25, 0.625,
// 0.125), the settings of slot 4
void bgfxExtFramebufferEffects::vfunc_6()
{
    if (m_ccBusy || !m_ccEnabled)
        return;
    if (!ensureResources())
        return;
    bgfxContext* c = m_context;
    bgfxDisplay* d = c->m_display;
    if (!c->fxCopy(m_full))
        return;
    static const float kTint[3] = {0.25f, 0.625f, 0.125f};
    c->m_fxTargetW = d->m_targetWidth;
    c->m_fxTargetH = d->m_targetHeight;
    c->fxView(kNone, 0, 0, d->m_targetWidth, d->m_targetHeight);
    filterPass(kTint, m_ccAmount, m_ccCurve, m_ccTint, m_ccBias, m_ccResult * 0.5f, (int)d->vfunc_7(),
               (int)d->vfunc_6());
    c->fxDone();
}

// slot 7 (0x320290): the bloom on/off (+0xec)
void bgfxExtFramebufferEffects::vfunc_7(unsigned char on) { m_bEnabled = on != 0; }

// slot 8 (0x322cd0): the bloom's settings: amount a (x 0.5, 0..1: c0 of the composite), the quarter copy's colour
// (the texture factor), blend b (0..1: c1), the gaussian's width q (x 0.25: sigma 0..25), the bright pass's colour
// weights (normalised to sum 1; black -> a third each), its brightness r (-100..100, / 255), contrast c (-100..100:
// linear below 0, the table above) and midpoint m (0..1). The gaussian's taps: weights exp(-i^2 / s^2) with
// s = 0.45 sigma + 0.3, as many as stay above 1/255 of the sum (at most 20), normalised over both sides.
void bgfxExtFramebufferEffects::vfunc_8(float a, unsigned int factor, float b, float q, unsigned int colour, float r,
                                        float c, float m)
{
    m_bBlend = (b >= 0.0f && b <= 1.0f) ? b : (b > 1.0f ? 1.0f : 0.0f);
    m_bRadius = ((r >= -100.0f && r <= 100.0f) ? r : (r > 100.0f ? 100.0f : -100.0f)) * 0.003921568859368563f;
    double x = (double)a * 0.5f;
    m_bAmount = (x >= 0.0f && x <= 1.0f) ? (float)x : (x > 1.0f ? 1.0f : 0.0f);
    m_bMix = (m >= 0.0f && m <= 1.0f) ? m : (m > 1.0f ? 1.0f : 0.0f);
    m_bContrast = (c >= -100.0f && c <= 100.0f) ? c : (c > 100.0f ? 100.0f : -100.0f);
    m_bFactor = factor;
    x = (double)q * 0.25f;
    m_bSigma = (x >= 0.0f && x <= 25.0f) ? (float)x : (x > 25.0f ? 25.0f : 0.0f);
    m_bWeights[2] = (float)(colour & 255) * 0.003921568859368563f;
    m_bWeights[0] = (float)((colour >> 16) & 255) * 0.003921568859368563f;
    m_bWeights[1] = (float)((colour >> 8) & 255) * 0.003921568859368563f;
    double total = (double)m_bWeights[2] + m_bWeights[1] + m_bWeights[0];
    if (total > 0.0f) {
        double inv = 1.0f / total;
        m_bWeights[0] = (float)(inv * m_bWeights[0]);
        m_bWeights[1] = (float)(inv * m_bWeights[1]);
        m_bWeights[2] = (float)(inv * m_bWeights[2]);
    } else {
        m_bWeights[0] = m_bWeights[1] = m_bWeights[2] = 0.3333333432674408f;
    }
    if (m_bContrast < 0.0f)
        m_bContrast = (float)((double)m_bContrast * 0.01f + 1.0f);
    else
        m_bContrast = kContrast[(int)((double)m_bContrast + 0.5f)];
    // the gaussian
    x = (double)m_bSigma * 0.45f + 0.3f;
    float square = (float)(x * x);
    double initial = exp(0.0f / square), accum = initial;
    int count = 1;
    for (; count < 20; ++count) {
        double wgt = exp(-((double)count * count) / square);
        if (accum > 255.5 * wgt)
            break;
        accum += wgt + wgt;
    }
    double sum = initial;
    m_values[0] = (float)initial;
    m_positions[0] = 0.0f;
    for (int i = 1; i < count; ++i) {
        float wgt = (float)exp(-((double)i * i) / square);
        m_values[i] = wgt;
        m_positions[i] = (float)i;
        if (!(wgt > 0.003921568859368563f)) {
            count = i;
            break;
        }
        sum += (double)wgt + wgt;
    }
    float s = (float)(1.0f / sum);
    int j;
    for (j = 0; j < count; ++j)
        m_values[j] *= s;
    for (; j < 20; ++j)
        m_values[j] = 0.0f;
}

// FUN_00323130: the separable gaussian of a quarter target: horizontally from `source` into `target`, then vertically
// back. Each direction: the centre and the taps to one side in batches of up to four (one program each: 1 to 4 taps
// at their offsets, weights as c0..c3), then the other side's taps (not the centre); the first draw writes, every
// later one adds (one, one). Returns the target holding the result (the source).
int bgfxExtFramebufferEffects::blur(int source, int target)
{
    bgfxContext* c = m_context;
    int count = 0;
    for (int j = 0; j < 20 && m_values[j] != 0.0f; j++)
        count++;
    unsigned qw = m_w / 4, qh = m_h / 4;
    float tw = (float)(qw ? qw : 1), th = (float)(qh ? qh : 1);
    for (int stage = 0; stage < 2; ++stage) {
        int dst = stage == 0 ? target : source, src = stage == 0 ? source : target;
        c->m_fxTargetW = qw;
        c->m_fxTargetH = qh;
        uint16_t view = c->fxView(m_quarterFb[dst], 0, 0, qw, qh);
        bool blend = false;
        unsigned tex[4] = {m_quarter[src], m_quarter[src], m_quarter[src], m_quarter[src]};
        for (int side = 0; side < 2; ++side) {
            float sign = side == 0 ? 1.0f : -1.0f;
            bgfxContext::FxQuad quad;
            memset(&quad, 0, sizeof(quad));
            quad.x1 = (float)qw;
            quad.y1 = (float)qh;
            for (int k = 0; k < 4; k++)
                quad.uv[k][2] = quad.uv[k][3] = 1.0f;
            bgfxContext::FxQuad base = quad;
            float k8[8][4];
            memset(k8, 0, sizeof(k8));
            int batch = 0, draws = 0;
            for (int n = 0; n < count; ++n) {
                if (side == 1 && n == 0)
                    continue;
                float wgt = q8(m_values[n]);
                for (int k = 0; k < 4; k++)
                    k8[batch][k] = wgt;
                float shift = sign * m_positions[n];
                if (stage == 0) {
                    quad.uv[batch][0] += shift / tw;
                    quad.uv[batch][2] += shift / tw;
                } else {
                    quad.uv[batch][1] += shift / th;
                    quad.uv[batch][3] += shift / th;
                }
                if (draws == 1)
                    blend = true;
                ++batch;
                if (batch == 4 || n == count - 1) {
                    float prog[8] = {(float)batch, 0.0f, 0.0f, 0.0f, 1, 1, 1, 1};
                    uint64_t st = BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A;
                    if (blend)
                        st |= BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_ONE, BGFX_STATE_BLEND_ONE);
                    c->fxDraw(view, (uint16_t)c->m_fxPrograms[1], quad, tex, 4, st, k8[0], 4, prog);
                    ++draws;
                    batch = 0;
                    quad = base;
                    memset(k8, 0, sizeof(k8));
                }
            }
            blend = true;
        }
    }
    return source;
}

// slot 9 (0x325110): the bloom. The render target copied to the full-size texture; the bright pass (the colour pass
// with the bloom's weights, brightness, contrast and midpoint, no tint, no saturation) from it into the half target;
// the half target times the factor into quarter target 0; the gaussian (0 <-> 1); then over the frame: 2 x the
// blurred quarter x amount + the copy x blend (the composite program), the quad shifted by (d0, d4) / 2 pixels.
void bgfxExtFramebufferEffects::vfunc_9()
{
    if (!m_bEnabled)
        return;
    if (!ensureResources())
        return;
    if (m_blurBusy || m_ccBusy)
        return;
    bgfxContext* c = m_context;
    bgfxDisplay* d = c->m_display;
    int fullW = (int)d->vfunc_7(), fullH = (int)d->vfunc_6();
    if (!c->fxCopy(m_full))
        return;
    // the bright pass: viewport (0, 0, w / 2, h / 2) of the half target
    c->m_fxTargetW = m_w / 2;
    c->m_fxTargetH = m_h / 2;
    c->fxView(m_halfFb, 0, 0, (unsigned)fullW / 2, (unsigned)fullH / 2);
    static const float kOne[3] = {1.0f, 1.0f, 1.0f};
    filterPass(m_bWeights, m_bRadius, m_bContrast, kOne, m_bMix, 0.0f, fullW / 2, fullH / 2);
    // the quarter copy, tinted (fixed function: texture x factor)
    {
        c->m_fxTargetW = m_w / 4;
        c->m_fxTargetH = m_h / 4;
        uint16_t view = c->fxView(m_quarterFb[0], 0, 0, (unsigned)fullW / 4, (unsigned)fullH / 4);
        bgfxContext::FxQuad quad;
        memset(&quad, 0, sizeof(quad));
        quad.x1 = (float)(fullW / 4);
        quad.y1 = (float)(fullH / 4);
        quad.uv[0][2] = quad.uv[0][3] = 1.0f;
        float k[8][4];
        memset(k, 0, sizeof(k));
        uint32_t f = m_bFactor;
        k[0][0] = (float)((f >> 16) & 255) / 255.0f;
        k[0][1] = (float)((f >> 8) & 255) / 255.0f;
        k[0][2] = (float)(f & 255) / 255.0f;
        k[0][3] = 1.0f;                       // the stage's alpha op is off: the alpha passes
        float prog[8] = {1.0f, 0.0f, 0.0f, 0.0f, 1, 1, 1, 1};
        c->fxDraw(view, (uint16_t)c->m_fxPrograms[1], quad, &m_half, 1, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A,
                  k[0], 1, prog);
    }
    int result = blur(0, 1);
    // the composite over the frame
    {
        c->m_fxTargetW = d->m_targetWidth;
        c->m_fxTargetH = d->m_targetHeight;
        uint16_t view = c->fxView(kNone, 0, 0, d->m_targetWidth, d->m_targetHeight);
        bgfxContext::FxQuad quad;
        memset(&quad, 0, sizeof(quad));
        quad.x0 = 0.5f - m_bD0 * 0.5f;
        quad.y0 = 0.5f - m_bD4 * 0.5f;
        quad.x1 = (float)fullW + 0.5f - m_bD0 * 0.5f;
        quad.y1 = (float)fullH + 0.5f - m_bD4 * 0.5f;
        for (int s = 0; s < 2; s++)
            quad.uv[s][2] = quad.uv[s][3] = 1.0f;
        float k[8][4];
        memset(k, 0, sizeof(k));
        q8v(k[0], m_bAmount, m_bAmount, m_bAmount, m_bAmount);
        q8v(k[1], m_bBlend, m_bBlend, m_bBlend, m_bBlend);
        unsigned tex[2] = {m_quarter[result], m_full};
        float prog[8] = {2.0f, 1.0f, 0.0f, 0.0f, 1, 1, 1, 1};
        c->fxDraw(view, (uint16_t)c->m_fxPrograms[1], quad, tex, 2, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A, k[0],
                  2, prog);
    }
    c->fxDone();
}

// slot 10 (0x3225e0): nothing
void bgfxExtFramebufferEffects::vfunc_10(int) {}

} // namespace pddi
} // namespace hulk
