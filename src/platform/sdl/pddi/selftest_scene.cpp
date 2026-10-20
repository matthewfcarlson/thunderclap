// The backend's self-test scene: pages of one frame of draws each, through the same slots the engine uses, laid out
// as a 4 x 3 grid of cells, each testing one thing, with the pixel each should produce (probes). The host smoke test
// (smoke/smoke_main.cpp, Metal: every page) and the native image's HULK_GFX_SELFTEST (sdl_platform.cpp, under
// Wine: Vulkan; HULK_GFX_SELFTEST_PAGE picks the page) draw them and check a screenshot against the probes.
//
// Page 0 (G3: the draw path):
//   row 0: fixed-function triangle (prim stream) | texture through device slot 9 + the simple shader | z test
//          (LEQUAL keeps the nearer quad drawn first) | z compare ALWAYS (the farther quad drawn last wins)
//   row 1: alpha blend (BLMD 1) | additive blend (BLMD 2) | stencil (write 1 with colour writes off, then draw
//          where stencil == 1) | cull (a counter-clockwise quad with pddi cull 1: nothing)
//   row 2: lit prim buffer (indexed, packed normal, one directional light, fixed-function program) | skinned prim
//          buffer through d3dExtHardwareSkinning (slots 5/6: the "skin" vertex program, bones blended 50/50,
//          lit by the skin program's light) | linear fog | colour write mask (red only)
// Page 1 (G2: the shader classes' texture-stage combiners, each from its pass set-up; generated programs):
//   row 0: simple TEX x vertex colour | simple unlit FADE (alpha mode: the factor scales alpha) | simple FADE +
//          BLMD 2 (the factor scales colour, added) | simple LIT FADE + BLMD 2 (the faded material)
//   row 1: layered CLYR 0 TBLM 1 (blendtexturealpha) | TBLM 2 (add, then x diffuse) | TBLM 3 (subtract) | CLYR 2
//          (TTEX, TEX blended by the diffuse alpha)
//   row 2: layeredReflect TEX + TTEX + REFL (modulateinvalpha_addcolor twice) | environment (temp, factor x
//          reflection, modulatealpha_addcolor) | alpha test ATST/ACMP/ACTH | layered TBLM 7 (subtract, own blend)
// Page 2: page 1 again with the generic combiner (the stages as uniforms) for every draw: the same pixels.
// Page 3 (G2: 2D, textures, movies, state):
//   row 0: pixel projection (slot 24 mode 2: the 2D mode) | orthographic projection (mode 1) | a linear texture
//          (format 11, 6 x 3: texel coordinates) | a movie tile as RenderStrategyBink draws it (a frame written
//          through the lock: upright)
//   row 1: UVMD 0 wrap | UVMD 1 clamp | FIMD 0 point | FIMD 1 linear
//   row 2: 2SID (a culled winding drawn) | additive + fog (fog to black while active, then restored) | environment
//          reflection through the sphere map (texgen + texture matrix) | FADE scales the alpha reference
// Page 4 (G2: the combiner sweep): every key of combiners.txt through its generated program and the generic
//   combiner, colour and alpha, against a CPU reference of the texture-stage operations (4 cells a key)
// Pages 5-8 (G4): the frame-buffer copy and refraction; the framebuffer effects' colour correction and the
//   visibility test; the bloom; the overlay (each described where it is drawn, below)
// Everything is in clip space (identity modelview and projection, z in [0, 1]) unless a cell says otherwise;
// D3DCOLORs are 0xAARRGGBB.
#include "bgfx_pddi.h"

#include <math.h>
#include <string.h>

#if HULK_PDDI_HOST || HULK_PDDI_EMBED_SHADERS
#include "pddi_combiners.h"     // the combiner keys (tools/native_gfx.py, from shaders/vp/combiners.txt)
#else
static const char* const g_pddi_combiner_keys[] = {0};
#endif

namespace hulk {
namespace pddi {

static const unsigned kClearColour = 0xff203040u;

struct SceneState {
    bgfxShader* plain;          // simple, no blend
    bgfxShader* textured;       // simple + TEX
    bgfxShader* alpha;          // BLMD 1
    bgfxShader* add;            // BLMD 2
    bgfxShader* lit;            // LIT, white diffuse
    bgfxShader* skin;           // LIT, white diffuse (the skin program's material)
    bgfxTexture* texture;
    bgfxPrimBuffer* litQuad;
    bgfxPrimBuffer* skinQuad;
    unsigned w, h;
    bool made;
    bgfxDisplay* display;       // the shot's display (window probes, the present rectangle)
};
static SceneState s_scene;
enum { kMaxProbes = 512 };
static SelfTestProbe s_probes[kMaxProbes];
static int s_nprobes;

static void probe(int x, int y, unsigned rgb, int tol, const char* what)
{
    if (s_nprobes < kMaxProbes) {
        SelfTestProbe& p = s_probes[s_nprobes++];
        p.x = x;
        p.y = y;
        p.rgb = rgb & 0xffffff;
        p.tolerance = tol;
        p.what = what;
        p.window = false;
    }
}

// a probe at a pixel of the window (the bars around a scaled frame)
static void probeWindow(int x, int y, unsigned rgb, int tol, const char* what)
{
    probe(x, y, rgb, tol, what);
    if (s_nprobes > 0)
        s_probes[s_nprobes - 1].window = true;
}

// cell (c, r) of the 4 x 3 grid in clip space: x0, y0 (top-left), x1, y1 (bottom-right), shrunk by `inset` pixels
struct Rect { float x0, y0, x1, y1; };
static Rect cell(int c, int r, float inset)
{
    float cw = s_scene.w / 4.0f, ch = s_scene.h / 3.0f;
    float px0 = c * cw + inset, px1 = (c + 1) * cw - inset, py0 = r * ch + inset, py1 = (r + 1) * ch - inset;
    Rect q = {2.0f * px0 / s_scene.w - 1.0f, 1.0f - 2.0f * py0 / s_scene.h, 2.0f * px1 / s_scene.w - 1.0f,
              1.0f - 2.0f * py1 / s_scene.h};
    return q;
}
static int cx(int c) { return (int)((c + 0.5f) * s_scene.w / 4.0f); }
static int cy(int r) { return (int)((r + 0.5f) * s_scene.h / 3.0f); }

// a quad as a triangle strip through the prim stream (clockwise on screen: kept by D3D's default cull)
static void quad(bgfxContext* ctx, bgfxShader* sh, const Rect& q, float z, unsigned colour, bool ccw = false,
                 bool uv = false)
{
    float v[4][5] = {{q.x0, q.y1, z, 0, 1}, {q.x0, q.y0, z, 0, 0}, {q.x1, q.y1, z, 1, 1}, {q.x1, q.y0, z, 1, 0}};
    if (ccw) {
        float t[5];
        memcpy(t, v[1], sizeof(t));
        memcpy(v[1], v[2], sizeof(t));
        memcpy(v[2], t, sizeof(t));
    }
    bgfxPrimStream* p = (bgfxPrimStream*)ctx->vfunc_30(sh, kPrimTriStrip, kVertexColour | (uv ? 1 : 0), 4, 0);
    for (int i = 0; i < 4; i++) {
        memcpy(p->posPtr, v[i], 12);
        *(unsigned*)p->colorPtr = colour;
        if (uv)
            memcpy(p->uvPtr, v[i] + 3, 8);
        p->vertex();
    }
    ctx->vfunc_31(p);
}

// A shader parameter by its key, as the engine sets it: pddiBaseShader's slots 5-8 (tree code walking our key
// tables) in the game image; the same tables through setParam on the host, where the base slots are stubs
static uint32_t K4(const char* s)
{
    return (uint32_t)(unsigned char)s[0] | (uint32_t)(unsigned char)s[1] << 8 | (uint32_t)(unsigned char)s[2] << 16 |
           (s[2] ? (uint32_t)(unsigned char)s[3] << 24 : 0u);
}
static void setI(bgfxShader* sh, const char* k, int v)
{
#if HULK_PDDI_GAME
    sh->vfunc_6((int)K4(k), v);
#else
    sh->setParam(1, K4(k), &v);
#endif
}
static void setF(bgfxShader* sh, const char* k, float v)
{
#if HULK_PDDI_GAME
    int bits;
    memcpy(&bits, &v, 4);
    sh->vfunc_7((int)K4(k), bits);              // the float travels as its bits in the same stack slot
#else
    sh->setParam(2, K4(k), &v);
#endif
}
static void setC(bgfxShader* sh, const char* k, unsigned v)
{
#if HULK_PDDI_GAME
    sh->vfunc_8((int)K4(k), (int)v);
#else
    sh->setParam(3, K4(k), &v);
#endif
}
static void setT(bgfxShader* sh, const char* k, bgfxObject* t)
{
#if HULK_PDDI_GAME
    sh->vfunc_5((int)K4(k), (int)(intptr_t)t);
#else
    sh->setParam(0, K4(k), &t);
#endif
}

static bgfxShader* makeShader(bgfxDevice* dev, const char* name)
{
    bgfxShader* s = (bgfxShader*)dev->vfunc_11(name, 0);
    if (s)
        s->vfunc_0();          // AddRef: the scene keeps it
    return s;
}

static bgfxShader* simpleShader(bgfxDevice* dev, int blend)
{
    bgfxShader* s = makeShader(dev, "simple");
    if (s)
        setI(s, "BLMD", blend);
    return s;
}

// a prim buffer through device slot 10, filled through its stream (slot 4/5) and indices (slot 9)
static bgfxPrimBuffer* makeQuadBuffer(bgfxDevice* dev, const Rect& q, unsigned flags, const char* program)
{
    intptr_t params[8] = {kPrimTriList, (intptr_t)flags, 0, 0, 4, 6, 0, (intptr_t)program};
    bgfxPrimBuffer* b = (bgfxPrimBuffer*)dev->vfunc_10(params);
    if (!b)
        return 0;
    b->vfunc_0();
    bgfxPrimBufferStream* s = (bgfxPrimBufferStream*)b->vfunc_4();
    const float pos[4][3] = {{q.x0, q.y1, 0.5f}, {q.x0, q.y0, 0.5f}, {q.x1, q.y1, 0.5f}, {q.x1, q.y0, 0.5f}};
    for (int i = 0; i < 4; i++) {
        if (flags & 0x100)
            s->vfunc_11(0.5f, 0.5f, 0.0f);             // weights: half bone 0, half bone 1, none of bone 2
        if (flags & 0x80)
            s->vfunc_10(0, 1, 2, 0);                   // bones 0, 1, 2
        if (flags & 0x10)
            s->vfunc_1(0.0f, 0.0f, -1.0f);             // facing the camera
        if (flags & 15)
            s->vfunc_6(0.0f, 0.0f, 0);
        s->vfunc_0(pos[i][0], pos[i][1], pos[i][2]);   // position, next vertex
    }
    b->vfunc_5(s);
    static const unsigned short idx[6] = {0, 1, 2, 2, 1, 3};
    b->vfunc_9((void*)idx, 6);
    return b;
}

static void setup(bgfxContext* ctx)
{
    SceneState& S = s_scene;
    S.made = true;
    bgfxDevice* dev = ctx->m_device;
    S.plain = simpleShader(dev, 0);
    S.textured = simpleShader(dev, 0);
    S.alpha = simpleShader(dev, 1);
    S.add = simpleShader(dev, 2);
    S.lit = simpleShader(dev, 0);
    S.skin = simpleShader(dev, 0);
    bgfxShader* lits[2] = {S.lit, S.skin};
    for (int i = 0; i < 2; i++)
        if (lits[i]) {
            setI(lits[i], "LIT", 1);
            setC(lits[i], "DIFF", 0xffffffffu);   // the game's default diffuse is black (0x333520)
            setC(lits[i], "AMBI", 0xff000000u);   // and its ambient white: x the ambient light the state reset
                                                  // sets in the game image; the probes want the light alone
        }
    // a 4x4 A8R8G8B8 texture: left half magenta, right half cyan (device slot 9, lock 13, unlock 14)
    int params[9] = {4, 4, 0, 32, 8, 0, 0, 0, 0};
    S.texture = (bgfxTexture*)dev->vfunc_9(params);
    if (S.texture) {
        bgfxTexture::LockInfo* li = (bgfxTexture::LockInfo*)S.texture->vfunc_13(0, 0);
        for (int y = 0; y < li->height; y++) {
            unsigned* row = (unsigned*)((char*)li->bits + y * li->stride);
            for (int x = 0; x < li->width; x++)
                row[x] = x < li->width / 2 ? 0xffff00ffu : 0xff00ffffu;
        }
        S.texture->vfunc_14(0);
        if (S.textured)
            setT(S.textured, "TEX", S.texture);     // through pddiBaseShader's slot 5 in the game image
    }
    S.litQuad = makeQuadBuffer(dev, cell(0, 2, 16), 0x10, "");
    // skinned: bit 7 (bone indices) and bit 8 (weights) select "skin" (FUN_00327860); the quad is placed half a
    // screen to the left: the bones move it into its cell
    Rect sq = cell(1, 2, 16);
    sq.x0 -= 0.5f;
    sq.x1 -= 0.5f;
    S.skinQuad = makeQuadBuffer(dev, sq, 0x180 | 0x10 | 1, 0);
}

int selfTestProbes(const SelfTestProbe** out)
{
    *out = s_probes;
    return s_nprobes;
}

static void identity(float* m)
{
    memset(m, 0, 64);
    m[0] = m[5] = m[10] = m[15] = 1.0f;
}

static void resetState(bgfxContext* ctx)
{
    ctx->vfunc_54(0);                       // no culling
    ctx->vfunc_56(1, 1, 1, 1);
    ctx->vfunc_58(1);
    ctx->vfunc_60(3);                       // LEQUAL
    ctx->vfunc_62(1);
    ctx->vfunc_64(0);
    ctx->vfunc_78(0);
}

static void page1(bgfxContext* ctx, bool generic);
static void page3(bgfxContext* ctx);
static void page4(bgfxContext* ctx);
static void page5(bgfxContext* ctx);
static void page6(bgfxContext* ctx);
static void page7(bgfxContext* ctx);
static void page8(bgfxContext* ctx);

static void page9(bgfxContext* ctx);
static void page10(bgfxContext* ctx);

int selfTestPages() { return 11; }

// One frame of a page of the scene (between the caller's begin frame and end frame). Returns the number of probes.
int selfTestScene(bgfxContext* ctx, int page)
{
    SceneState& S = s_scene;
    S.w = ctx->m_display ? ctx->m_display->m_width : 640;
    S.h = ctx->m_display ? ctx->m_display->m_height : 480;
    S.display = ctx->m_display;
    if (!S.made)
        setup(ctx);
    s_nprobes = 0;
    ctx->m_forceGeneric = false;
    if (page == 1 || page == 2) {
        page1(ctx, page == 2);
        ctx->m_forceGeneric = false;
        return s_nprobes;
    }
    if (page == 3) {
        page3(ctx);
        return s_nprobes;
    }
    if (page == 4) {
        page4(ctx);
        ctx->m_forceGeneric = false;
        return s_nprobes;
    }
    if (page == 5) {
        page5(ctx);
        return s_nprobes;
    }
    if (page == 6) {
        page6(ctx);
        return s_nprobes;
    }
    if (page == 7) {
        page7(ctx);
        return s_nprobes;
    }
    if (page == 9) {
        page9(ctx);
        return s_nprobes;
    }
    if (page == 10) {
        page10(ctx);
        return s_nprobes;
    }
    if (page == 8) {
        page8(ctx);
        return s_nprobes;
    }
    float I[16];
    identity(I);
#if HULK_PDDI_GAME
    ctx->vfunc_14(0, I);                    // the base's matrix stack 0 (-> slot 108: D3D's world)
#endif
    ctx->setViewTransform(I, I);
    ctx->vfunc_6(kClearColour);             // the base's clear block (host: ours)
    ctx->hostSetClear(kClearColour, 1.0f, 0);
    ctx->vfunc_12(1 | 2 | 4);
    resetState(ctx);
    const unsigned clear = kClearColour & 0xffffff;

    // row 0
    {
        Rect q = cell(0, 0, 16);
        bgfxPrimStream* p = (bgfxPrimStream*)ctx->vfunc_30(0, kPrimTriList, kVertexColour, 3, 0);
        float v[3][3] = {{q.x0, q.y1, 0.5f}, {(q.x0 + q.x1) / 2, q.y0, 0.5f}, {q.x1, q.y1, 0.5f}};
        for (int i = 0; i < 3; i++) {
            memcpy(p->posPtr, v[i], 12);
            *(unsigned*)p->colorPtr = 0xffff8000u;
            p->vertex();
        }
        ctx->vfunc_31(p);
        probe(cx(0), cy(0) + 10, 0xff8000, 2, "fixed-function triangle (prim stream)");
    }
    if (S.textured && S.texture) {
        quad(ctx, S.textured, cell(1, 0, 16), 0.5f, 0xffffffffu, false, true);
        int x0 = (int)(1 * S.w / 4.0f + 16), x1 = (int)(2 * S.w / 4.0f - 16);
        probe(x0 + (x1 - x0) / 4, cy(0), 0xff00ff, 3, "texture, left half (device slot 9, TEX)");
        probe(x0 + 3 * (x1 - x0) / 4, cy(0), 0x00ffff, 3, "texture, right half");
    }
    quad(ctx, S.plain, cell(2, 0, 16), 0.3f, 0xffff0000u);
    quad(ctx, S.plain, cell(2, 0, 8), 0.7f, 0xff00ff00u);
    probe(cx(2), cy(0), 0xff0000, 2, "z test LEQUAL: the nearer quad stays");
    quad(ctx, S.plain, cell(3, 0, 16), 0.3f, 0xffff0000u);
    ctx->vfunc_60(1);                       // ALWAYS
    quad(ctx, S.plain, cell(3, 0, 8), 0.7f, 0xff00ff00u);
    ctx->vfunc_60(3);
    probe(cx(3), cy(0), 0x00ff00, 2, "z compare ALWAYS: the farther quad drawn last");

    // row 1
    quad(ctx, S.plain, cell(0, 1, 16), 0.5f, 0xffffffffu);
    if (S.alpha) {
        ctx->vfunc_62(0);
        quad(ctx, S.alpha, cell(0, 1, 16), 0.4f, 0x80000000u);
        ctx->vfunc_62(1);
        probe(cx(0), cy(1), 0x7f7f7f, 3, "alpha blend (BLMD 1): half black over white");
    }
    quad(ctx, S.plain, cell(1, 1, 16), 0.5f, 0xff400000u);
    if (S.add) {
        ctx->vfunc_62(0);
        quad(ctx, S.add, cell(1, 1, 16), 0.4f, 0xff008000u);
        ctx->vfunc_62(1);
        probe(cx(1), cy(1), 0x408000, 3, "additive blend (BLMD 2)");
    }
    {
        ctx->vfunc_64(1);                   // stencil on
        ctx->vfunc_66(1);                   // ALWAYS
        ctx->vfunc_68(1);
        ctx->vfunc_70(0xff);
        ctx->vfunc_72(0xff);
        ctx->vfunc_74(0, 0, 2);             // pass: REPLACE
        ctx->vfunc_56(0, 0, 0, 0);          // no colour writes
        ctx->vfunc_58(0);
        quad(ctx, S.plain, cell(2, 1, 48), 0.5f, 0xffffffffu);
        ctx->vfunc_56(1, 1, 1, 1);
        ctx->vfunc_66(6);                   // EQUAL
        ctx->vfunc_74(0, 0, 0);
        quad(ctx, S.plain, cell(2, 1, 16), 0.5f, 0xff0000ffu);
        ctx->vfunc_58(1);
        ctx->vfunc_64(0);
        probe(cx(2), cy(1), 0x0000ff, 2, "stencil: drawn where 1 was written");
        probe(cx(2) - (int)(S.w / 8.0f) + 24, cy(1) - (int)(S.h / 6.0f) + 24, clear, 2,
              "stencil: not drawn where 0 (colour writes were off)");
    }
    ctx->vfunc_54(1);                       // cull counter-clockwise (D3D's default)
    quad(ctx, S.plain, cell(3, 1, 16), 0.5f, 0xffffffffu, true);
    ctx->vfunc_54(0);
    probe(cx(3), cy(1) - 40, clear, 2, "cull: a counter-clockwise quad with cull mode 1 is not drawn");
    {
        // a 12-vertex strip through a stream whose batch holds 6 (FUN_0008ef00's carry: each full batch is drawn
        // and its last two vertices start the next)
        Rect q = cell(3, 1, 16);
        float y0 = 1.0f - 2.0f * (cy(1) + 20) / S.h, y1 = 1.0f - 2.0f * (cy(1) + 60) / S.h;
        bgfxPrimStream* p = (bgfxPrimStream*)ctx->vfunc_30(S.plain, kPrimTriStrip, kVertexColour, 12, 0);
        p->limit = 6;
        for (int i = 0; i < 12; i++) {
            float v[3] = {q.x0 + (q.x1 - q.x0) * (i / 2) / 5.0f, (i & 1) ? y0 : y1, 0.5f};
            memcpy(p->posPtr, v, 12);
            *(unsigned*)p->colorPtr = 0xffffff00u;
            p->vertex();
        }
        ctx->vfunc_31(p);
        int x0 = (int)(3 * S.w / 4.0f + 16), x1 = (int)(S.w - 16);
        probe(x0 + (x1 - x0) / 10, cy(1) + 40, 0xffff00, 2, "strip split across batches: first batch");
        probe(x0 + 9 * (x1 - x0) / 10, cy(1) + 40, 0xffff00, 2, "strip split across batches: last batch");
        probe(x0 + 45 * (x1 - x0) / 100, cy(1) + 40, 0xffff00, 2, "strip split across batches: first seam");
        probe(x0 + 85 * (x1 - x0) / 100, cy(1) + 40, 0xffff00, 2, "strip split across batches: second seam");
    }

    // row 2
    bgfxContext::Light l;
    memset(&l, 0, sizeof(l));
    for (int i = 1; i < bgfxContext::kLights; i++)
        ctx->hostSetLight(i, l);            // off
    l.type = 3;
    l.on = true;
    l.direction[2] = 1.0f;                  // pointing into the screen: lights faces turned to the camera
    l.range = 1e30f;
    l.att[0] = 1.0f;
    if (S.litQuad && S.lit) {
        l.diffuse[0] = 0.5f;
        l.diffuse[1] = 0.25f;
        l.diffuse[2] = 1.0f;
        l.diffuse[3] = 1.0f;
        ctx->hostSetLight(0, l);
        ctx->vfunc_32(S.lit, S.litQuad);    // context slot 32: a prim buffer with a shader
        probe(cx(0), cy(2), 0x8040ff, 3, "lit prim buffer (fixed function, packed normal)");
    }
    if (S.skinQuad && S.skin) {
        l.diffuse[0] = 0.25f;
        l.diffuse[1] = 0.75f;
        l.diffuse[2] = 0.5f;
        ctx->hostSetLight(0, l);
        bgfxExtHardwareSkinning* sk = (bgfxExtHardwareSkinning*)ctx->m_ext[4];     // slot 89 (0x102) hands it out
        if (sk) {
            float b0[16], b1[16], b2[16];
            identity(b0);
            identity(b1);
            identity(b2);
            b0[12] = 1.0f;                  // bone 0 moves +1 in x, bone 1 not at all, bone 2 (weight 0) +5
            b2[12] = 5.0f;
            sk->vfunc_5(0, b0);
            sk->vfunc_5(1, b1);
            sk->vfunc_5(2, b2);
            sk->vfunc_6(S.skin, S.skinQuad);
            probe(cx(1), cy(2), 0x40bf80, 4, "skinned prim buffer: \"skin\" program, two bones, its light");
            probe(cx(1) - (int)(S.w / 4.0f), cy(2), 0x8040ff, 3,
                  "skinned: nothing where the unskinned quad would be (the lit cell shows through)");
        }
    }
    {
        ctx->vfunc_78(1);
        float start = 0.0f, end = 1.0f;
        int a, b;
        memcpy(&a, &start, 4);
        memcpy(&b, &end, 4);
        ctx->vfunc_80((int)0xffff0000u, a, b);
        quad(ctx, S.plain, cell(2, 2, 16), 0.5f, 0xffffffffu);
        ctx->vfunc_78(0);
        probe(cx(2), cy(2), 0xff8080, 3, "linear fog halfway: half red, half white");
    }
    ctx->vfunc_56(1, 0, 0, 0);
    quad(ctx, S.plain, cell(3, 2, 16), 0.5f, 0xffffffffu);
    ctx->vfunc_56(1, 1, 1, 1);
    probe(cx(3), cy(2), 0xff3040, 2, "colour write mask: red only");
    return s_nprobes;
}

// ---------------------------------------------------------------------------------------------
// G2 pages
static void beginPage(bgfxContext* ctx)
{
    float I[16];
    identity(I);
#if HULK_PDDI_GAME
    ctx->vfunc_14(0, I);
#endif
    ctx->setViewTransform(I, I);
    ctx->vfunc_6(kClearColour);
    ctx->hostSetClear(kClearColour, 1.0f, 0);
    ctx->vfunc_12(1 | 2 | 4);
    resetState(ctx);
    ctx->vfunc_78(0);
}

// A texture through device slot 9 + lock (13) / unlock (14): `image` row-major, top row first, written as the
// engine writes (row y at bits + y * stride)
static bgfxTexture* makeTexture(bgfxDevice* dev, int w, int h, int format, const unsigned* image)
{
    int params[9] = {w, h, 0, 32, 8, 0, format, 0, 0};
    bgfxTexture* t = (bgfxTexture*)dev->vfunc_9(params);
    if (!t)
        return 0;
    t->vfunc_0();
    bgfxTexture::LockInfo* li = (bgfxTexture::LockInfo*)t->vfunc_13(0, 0);
    for (int y = 0; y < li->height; y++)
        memcpy((char*)li->bits + y * li->stride, image + y * w, 4 * (size_t)w);
    t->vfunc_14(0);
    return t;
}
static bgfxTexture* solid(bgfxDevice* dev, unsigned c)
{
    unsigned px[4] = {c, c, c, c};
    return makeTexture(dev, 2, 2, 0, px);
}

// A quad as a strip through the prim stream: vertices bottom-left, top-left, bottom-right, top-right (clockwise on
// screen), each with its colour and uv (both uv sets the same), an optional normal facing the camera
struct QuadSpec {
    unsigned colour[4];
    float uv[4][2];
    int uvSets;
    bool colours, normal, ccw;
};
static QuadSpec spec(unsigned c, int uvSets = 1)
{
    QuadSpec q;
    for (int i = 0; i < 4; i++)
        q.colour[i] = c;
    static const float uv[4][2] = {{0, 1}, {0, 0}, {1, 1}, {1, 0}};
    memcpy(q.uv, uv, sizeof(uv));
    q.uvSets = uvSets;
    q.colours = true;
    q.normal = false;
    q.ccw = false;
    return q;
}
static void quadEx(bgfxContext* ctx, bgfxShader* sh, const Rect& q, float z, const QuadSpec& s)
{
    float pos[4][3] = {{q.x0, q.y1, z}, {q.x0, q.y0, z}, {q.x1, q.y1, z}, {q.x1, q.y0, z}};
    int order[4] = {0, 1, 2, 3};
    if (s.ccw) {
        order[1] = 2;
        order[2] = 1;
    }
    unsigned flags = (s.colours ? kVertexColour : 0) | (s.normal ? kVertexNormal : 0) | (unsigned)s.uvSets;
    bgfxPrimStream* p = (bgfxPrimStream*)ctx->vfunc_30(sh, kPrimTriStrip, (int)flags, 4, 0);
    for (int k = 0; k < 4; k++) {
        int i = order[k];
        memcpy(p->posPtr, pos[i], 12);
        if (s.normal) {
            const float n[3] = {0.0f, 0.0f, -1.0f};
            memcpy(p->normalPtr, n, 12);
        }
        if (s.colours)
            *(unsigned*)p->colorPtr = s.colour[i];
        for (int u = 0; u < s.uvSets; u++)
            memcpy(p->uvPtr + 8 * u, s.uv[i], 8);
        p->vertex();
    }
    ctx->vfunc_31(p);
}
static Rect half(const Rect& r, bool top)
{
    Rect q = r;
    float mid = (r.y0 + r.y1) * 0.5f;
    if (top)
        q.y1 = mid;
    else
        q.y0 = mid;
    return q;
}
static void directionalLight(bgfxContext* ctx, float r, float g, float b)
{
    bgfxContext::Light l;
    memset(&l, 0, sizeof(l));
    for (int i = 1; i < bgfxContext::kLights; i++)
        ctx->hostSetLight(i, l);
    l.type = 3;
    l.on = true;
    l.direction[2] = 1.0f;
    l.range = 1e30f;
    l.att[0] = 1.0f;
    l.diffuse[0] = r;
    l.diffuse[1] = g;
    l.diffuse[2] = b;
    l.diffuse[3] = 1.0f;
    ctx->hostSetLight(0, l);
}

struct Page1 {
    bool made;
    bgfxTexture *t1, *t2, *t5, *t6, *t7, *t8;
    bgfxShader *tex, *fadeAlpha, *fadeAdd, *litFade, *lay1, *lay2, *lay3, *layPath2, *building, *env, *test, *lay7;
};
static Page1 s_p1;

static bgfxShader* layered(bgfxDevice* dev, bgfxTexture* a, bgfxTexture* b, int tblm, int clyr)
{
    bgfxShader* s = makeShader(dev, "layered");
    if (s) {
        setT(s, "TEX", a);
        setT(s, "TTEX", b);
        setI(s, "TBLM", tblm);
        setI(s, "CLYR", clyr);
    }
    return s;
}

static void setupPage1(bgfxContext* ctx)
{
    Page1& P = s_p1;
    P.made = true;
    bgfxDevice* dev = ctx->m_device;
    P.t1 = solid(dev, 0xff804020u);             // 128, 64, 32, opaque
    P.t2 = solid(dev, 0x8000ff00u);             // green, alpha 128
    P.t5 = solid(dev, 0x80404040u);             // grey 64, alpha 128
    P.t6 = solid(dev, 0xffff0000u);             // red
    P.t7 = solid(dev, 0xff0000ffu);             // blue
    P.t8 = solid(dev, 0x80202020u);             // grey 32, alpha 128
    P.tex = simpleShader(dev, 0);
    P.fadeAlpha = simpleShader(dev, 0);
    P.fadeAdd = simpleShader(dev, 2);
    P.litFade = simpleShader(dev, 2);
    if (P.tex)
        setT(P.tex, "TEX", P.t1);
    if (P.fadeAlpha) {
        setT(P.fadeAlpha, "TEX", P.t1);
        setF(P.fadeAlpha, "FADE", 0.5f);
    }
    if (P.fadeAdd) {
        setT(P.fadeAdd, "TEX", P.t1);
        setF(P.fadeAdd, "FADE", 0.5f);
    }
    if (P.litFade) {
        setI(P.litFade, "LIT", 1);
        setC(P.litFade, "DIFF", 0xffffffffu);
        setC(P.litFade, "AMBI", 0xff000000u);
        setF(P.litFade, "FADE", 0.5f);
    }
    P.lay1 = layered(dev, P.t1, P.t2, 1, 0);
    P.lay2 = layered(dev, P.t1, P.t2, 2, 0);
    P.lay3 = layered(dev, P.t1, P.t2, 3, 0);
    P.layPath2 = layered(dev, P.t1, P.t2, 4, 2);
    P.lay7 = layered(dev, P.t1, P.t8, 7, 0);
    P.building = makeShader(dev, "layeredReflect");
    if (P.building) {
        setT(P.building, "TEX", P.t5);
        setT(P.building, "TTEX", P.t6);
        setT(P.building, "REFL", P.t7);
    }
    P.env = makeShader(dev, "environment");
    if (P.env) {
        setT(P.env, "TEX", P.t1);
        setT(P.env, "REFL", P.t7);
        setC(P.env, "ENVB", 0xff808080u);
    }
    P.test = simpleShader(dev, 0);
    if (P.test) {
        setI(P.test, "ATST", 1);
        setI(P.test, "ACMP", 4);                // greater
        setF(P.test, "ACTH", 0.5f);
    }
}

static void page1(bgfxContext* ctx, bool generic)
{
    Page1& P = s_p1;
    if (!P.made)
        setupPage1(ctx);
    beginPage(ctx);
    ctx->m_forceGeneric = generic;
    // row 0
    if (P.tex) {
        quadEx(ctx, P.tex, cell(0, 0, 16), 0.5f, spec(0xff808080u));
        probe(cx(0), cy(0), 0x402010, 3, generic ? "simple TEX x diffuse [generic]" : "simple TEX x diffuse");
    }
    quad(ctx, s_scene.plain, cell(1, 0, 16), 0.5f, 0xffffffffu);
    if (P.fadeAlpha) {
        ctx->vfunc_62(0);
        quadEx(ctx, P.fadeAlpha, cell(1, 0, 16), 0.4f, spec(0xffffffffu));
        ctx->vfunc_62(1);
        probe(cx(1), cy(0), 0xbf9f8f, 4, generic ? "simple FADE alpha mode [generic]" : "simple FADE: alpha x factor");
    }
    quad(ctx, s_scene.plain, cell(2, 0, 16), 0.5f, 0xff404040u);
    if (P.fadeAdd) {
        ctx->vfunc_62(0);
        quadEx(ctx, P.fadeAdd, cell(2, 0, 16), 0.4f, spec(0xffffffffu));
        ctx->vfunc_62(1);
        probe(cx(2), cy(0), 0x806050, 4, generic ? "simple FADE add [generic]" : "simple FADE + BLMD 2: colour x factor, added");
    }
    quad(ctx, s_scene.plain, cell(3, 0, 16), 0.5f, 0xff000040u);
    if (P.litFade) {
        directionalLight(ctx, 1.0f, 1.0f, 1.0f);
        QuadSpec q = spec(0, 0);
        q.colours = false;
        q.normal = true;
        ctx->vfunc_62(0);
        quadEx(ctx, P.litFade, cell(3, 0, 16), 0.4f, q);
        ctx->vfunc_62(1);
        probe(cx(3), cy(0), 0x7f7fbf, 4, generic ? "simple LIT FADE add [generic]" : "simple LIT FADE + BLMD 2: the faded material");
    }
    // row 1: layered (TTEX on uv set 1)
    if (P.lay1) {
        quadEx(ctx, P.lay1, cell(0, 1, 16), 0.5f, spec(0xffffffffu, 2));
        probe(cx(0), cy(1), 0x40a010, 4, generic ? "layered TBLM 1 [generic]" : "layered CLYR 0 TBLM 1: blendtexturealpha");
    }
    if (P.lay2) {
        quadEx(ctx, P.lay2, cell(1, 1, 16), 0.5f, spec(0xff808080u, 2));
        probe(cx(1), cy(1), 0x408010, 4, generic ? "layered TBLM 2 [generic]" : "layered TBLM 2: add, then x diffuse");
    }
    if (P.lay3) {
        quadEx(ctx, P.lay3, cell(2, 1, 16), 0.5f, spec(0xffffffffu, 2));
        probe(cx(2), cy(1), 0x800020, 4, generic ? "layered TBLM 3 [generic]" : "layered TBLM 3: subtract");
    }
    if (P.layPath2) {
        quadEx(ctx, P.layPath2, cell(3, 1, 16), 0.5f, spec(0x40ffffffu, 2));
        probe(cx(3), cy(1), 0x607018, 4, generic ? "layered CLYR 2 [generic]" : "layered CLYR 2: blenddiffusealpha");
    }
    // row 2
    if (P.building) {
        quadEx(ctx, P.building, cell(0, 2, 16), 0.5f, spec(0xffffffffu, 2));
        probe(cx(0), cy(2), 0xbf40bf, 4, generic ? "layeredReflect [generic]" : "layeredReflect: TEX, TTEX and REFL by inverse alpha");
    }
    if (P.env) {
        quadEx(ctx, P.env, cell(1, 2, 16), 0.5f, spec(0xffffffffu));
        probe(cx(1), cy(2), 0x8040a0, 4, generic ? "environment [generic]" : "environment: temp + temp alpha x factor x REFL");
    }
    if (P.test) {
        QuadSpec q = spec(0xffffffffu, 0);
        q.colour[0] = q.colour[1] = 0x00ffffffu;   // alpha 0 on the left, 1 on the right
        Rect r = cell(2, 2, 16);
        quadEx(ctx, P.test, r, 0.5f, q);
        int x0 = (int)(2 * s_scene.w / 4.0f + 16), x1 = (int)(3 * s_scene.w / 4.0f - 16);
        probe(x0 + (x1 - x0) / 4, cy(2), kClearColour & 0xffffff, 2,
              generic ? "alpha test, left [generic]" : "alpha test GREATER 0.5: alpha 0.25 discarded");
        probe(x0 + 3 * (x1 - x0) / 4, cy(2), 0xffffff, 2,
              generic ? "alpha test, right [generic]" : "alpha test GREATER 0.5: alpha 0.75 drawn");
    }
    if (P.lay7) {
        quadEx(ctx, P.lay7, cell(3, 2, 16), 0.5f, spec(0xffffffffu, 2));
        probe(cx(3), cy(2), 0x301000, 4, generic ? "layered TBLM 7 [generic]" : "layered TBLM 7: subtract, src x src alpha");
    }
}

struct Page3 {
    bool made;
    bgfxTexture *linear, *movie, *bw, *black, *refl;
    bgfxShader *plain, *linearSh, *movieSh, *wrap, *clamp, *point, *bilinear, *twoSided, *add, *env, *fadeTest;
};
static Page3 s_p3;

static void setupPage3(bgfxContext* ctx)
{
    Page3& P = s_p3;
    P.made = true;
    bgfxDevice* dev = ctx->m_device;
    unsigned lin[18];
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 6; x++)
            lin[y * 6 + x] = x < 3 ? 0xffff0000u : 0xff0000ffu;
    P.linear = makeTexture(dev, 6, 3, 11, lin);
    // the movie tile: a 16 x 8 linear texture (format 11, as RenderStrategyBink::vfunc_6 makes them), its frame
    // written through the lock as the movie player does
    int tparams[9] = {16, 8, 0, 32, 0, 0, 11, 0, 0};
    P.movie = (bgfxTexture*)dev->vfunc_9(tparams);
    if (P.movie) {
        P.movie->vfunc_0();
        unsigned char frame[16 * 8 * 4];
        for (int y = 0; y < 8; y++)
            for (int x = 0; x < 16; x++) {
                unsigned c = y < 4 ? 0xffff0000u : 0xff00ff00u;     // top half red, bottom half green
                memcpy(frame + (y * 16 + x) * 4, &c, 4);
            }
        P.movie->writeFrame(frame, 16, 8, 16 * 4, 0, 0);
    }
    unsigned bw[2] = {0xff000000u, 0xffffffffu};
    P.bw = makeTexture(dev, 2, 1, 0, bw);
    P.black = solid(dev, 0xff000000u);
    unsigned refl[4] = {0xff00ff00u, 0xff00ff00u, 0xff00ff00u, 0xffff00ffu};   // image row 1, right: magenta
    P.refl = makeTexture(dev, 2, 2, 0, refl);
    P.plain = simpleShader(dev, 0);
    P.linearSh = simpleShader(dev, 0);
    if (P.linearSh) {
        setT(P.linearSh, "TEX", P.linear);
        setI(P.linearSh, "UVMD", 1);
        setI(P.linearSh, "FIMD", 0);
    }
    P.movieSh = simpleShader(dev, 0);
    if (P.movieSh)
        setT(P.movieSh, "TEX", P.movie);
    P.wrap = simpleShader(dev, 0);
    P.clamp = simpleShader(dev, 0);
    P.point = simpleShader(dev, 0);
    P.bilinear = simpleShader(dev, 0);
    bgfxShader* bws[4] = {P.wrap, P.clamp, P.point, P.bilinear};
    static const int kUv[4] = {0, 1, 1, 1}, kFi[4] = {0, 0, 0, 1};
    for (int i = 0; i < 4; i++)
        if (bws[i]) {
            setT(bws[i], "TEX", P.bw);
            setI(bws[i], "UVMD", kUv[i]);
            setI(bws[i], "FIMD", kFi[i]);
        }
    P.twoSided = simpleShader(dev, 0);
    if (P.twoSided)
        setI(P.twoSided, "2SID", 1);
    P.add = simpleShader(dev, 2);
    P.env = makeShader(dev, "environment");
    if (P.env) {
        setT(P.env, "TEX", P.black);
        setT(P.env, "REFL", P.refl);
        setC(P.env, "ENVB", 0xffffffffu);
        setI(P.env, "FIMD", 0);
    }
    P.fadeTest = simpleShader(dev, 0);
    if (P.fadeTest) {
        setI(P.fadeTest, "ATST", 1);
        setI(P.fadeTest, "ACMP", 4);
        setF(P.fadeTest, "ACTH", 0.5f);
        setF(P.fadeTest, "FADE", 0.5f);
    }
}

// pixel rectangle of a cell (top-left origin, y down), shrunk
struct PixRect { float x0, y0, x1, y1; };
static PixRect pixCell(int c, int r, float inset)
{
    float cw = s_scene.w / 4.0f, ch = s_scene.h / 3.0f;
    PixRect p = {c * cw + inset, r * ch + inset, (c + 1) * cw - inset, (r + 1) * ch - inset};
    return p;
}

static void page3(bgfxContext* ctx)
{
    Page3& P = s_p3;
    if (!P.made)
        setupPage3(ctx);
    beginPage(ctx);
    float W = (float)s_scene.w, H = (float)s_scene.h, aspect = W / H;
    float I[16];
    identity(I);
    // (0, 0): the pixel projection (slot 24 mode 2, as the 2D text and HUD draw): a quad in the cell's top half,
    // in pixels
    if (P.plain) {
        ctx->hostSetView(2, 0.0f, 1.0f, 1.0f, aspect);
        PixRect p = pixCell(0, 0, 16);
        Rect q = {p.x0, p.y0, p.x1, (p.y0 + p.y1) * 0.5f};      // pixel coordinates: y down
        quadEx(ctx, P.plain, q, 0.5f, spec(0xff00ff80u, 0));
        probe(cx(0), (int)(p.y0 + (p.y1 - p.y0) * 0.25f), 0x00ff80, 2, "2D (mode 2): a pixel-space quad, top half");
        probe(cx(0), (int)(p.y0 + (p.y1 - p.y0) * 0.75f), kClearColour & 0xffffff, 2, "2D (mode 2): nothing below");
        // (1, 0): the orthographic projection (mode 1: x over [-0.5, 0.5], y over [-0.5, 0.5] / aspect, y up)
        ctx->hostSetView(1, 0.0f, 1.0f, 1.0f, aspect);
        Rect c = half(cell(1, 0, 16), true);
        Rect o = {c.x0 * 0.5f, c.y0 / (2.0f * aspect), c.x1 * 0.5f, c.y1 / (2.0f * aspect)};
        quadEx(ctx, P.plain, o, 0.5f, spec(0xff8000ffu, 0));
        PixRect pc = pixCell(1, 0, 16);
        probe(cx(1), (int)(pc.y0 + (pc.y1 - pc.y0) * 0.25f), 0x8000ff, 2, "orthographic (mode 1): top half");
        probe(cx(1), (int)(pc.y0 + (pc.y1 - pc.y0) * 0.75f), kClearColour & 0xffffff, 2,
              "orthographic (mode 1): nothing below");
        ctx->setViewTransform(I, I);
    }
    // (2, 0): a linear texture (format 11, 6 x 3, left half red, right half blue) with texel coordinates
    if (P.linearSh) {
        QuadSpec q = spec(0xffffffffu);
        float uv[4][2] = {{0, 3}, {0, 0}, {6, 3}, {6, 0}};
        memcpy(q.uv, uv, sizeof(uv));
        quadEx(ctx, P.linearSh, cell(2, 0, 16), 0.5f, q);
        PixRect p = pixCell(2, 0, 16);
        probe((int)(p.x0 + (p.x1 - p.x0) * 0.25f), cy(0), 0xff0000, 2, "linear texture, texel u 1.5: red");
        probe((int)(p.x0 + (p.x1 - p.x0) * 0.75f), cy(0), 0x0000ff, 2, "linear texture, texel u 4.5: blue");
    }
    // (3, 0): a movie tile drawn as RenderStrategyBink::vfunc_7 draws it: the pixel projection, BLMD 0, UVMD 1,
    // FIMD 1 (scaled), a 6-vertex list with texel coordinates (+0.5), the tile 4x
    if (P.movieSh && P.movie) {
        ctx->hostSetView(2, 0.0f, 1.0f, 1.0f, aspect);
        setI(P.movieSh, "BLMD", 0);
        setI(P.movieSh, "UVMD", 1);
        setI(P.movieSh, "FIMD", 1);
        PixRect pc = pixCell(3, 0, 0);
        float left = pc.x0 + 40, top = pc.y0 + 30, tw = 16, th = 8, sx = 4, sy = 4;
        float u = tw + 0.5f, v = th + 0.5f, right = tw * sx + left, bottom = th * sy + top;
        bgfxPrimStream* s = (bgfxPrimStream*)ctx->vfunc_30(P.movieSh, kPrimTriList, 0x2021, 6, 0);
        for (int j = 0; j < 6; j++) {
            *(unsigned*)s->colorPtr = 0xffffffffu;
            float t[2] = {(j == 1 || j == 2 || j == 4) ? u : 0.5f, (j == 2 || j == 4 || j == 5) ? v : 0.5f};
            memcpy(s->uvPtr, t, 8);
            float p[3] = {(j == 1 || j == 2 || j == 4) ? right : left, (j == 0 || j == 1 || j == 3) ? bottom : top, 0.5f};
            memcpy(s->posPtr, p, 12);
            s->vertex();
        }
        ctx->vfunc_31(s);
        probe((int)(left + 32), (int)(top + 6), 0xff0000, 3, "movie tile: the frame's top rows at the top");
        probe((int)(left + 32), (int)(top + 26), 0x00ff00, 3, "movie tile: its bottom rows at the bottom");
        ctx->setViewTransform(I, I);
    }
    // row 1: addressing and filtering of a 2 x 1 texture (black, white)
    {
        bgfxShader* sh[4] = {P.wrap, P.clamp, P.point, P.bilinear};
        float umax[4] = {2.0f, 2.0f, 1.0f, 1.0f};
        for (int i = 0; i < 4; i++) {
            if (!sh[i])
                continue;
            QuadSpec q = spec(0xffffffffu);
            float uv[4][2] = {{0, 1}, {0, 0}, {umax[i], 1}, {umax[i], 0}};
            memcpy(q.uv, uv, sizeof(uv));
            quadEx(ctx, sh[i], cell(i, 1, 16), 0.5f, q);
        }
        PixRect p = pixCell(0, 1, 16);
        int px = (int)(p.x0 + (p.x1 - p.x0) * 0.625f);
        probe(px, cy(1), 0x000000, 2, "UVMD 0 wrap: u 1.25 -> texel 0");
        p = pixCell(1, 1, 16);
        px = (int)(p.x0 + (p.x1 - p.x0) * 0.625f);
        probe(px, cy(1), 0xffffff, 2, "UVMD 1 clamp: u 1.25 -> texel 1");
        p = pixCell(2, 1, 16);
        px = (int)(p.x0 + (p.x1 - p.x0) * 0.45f);
        probe(px, cy(1), 0x000000, 2, "FIMD 0 point: u 0.45 -> texel 0");
        p = pixCell(3, 1, 16);
        px = (int)(p.x0 + (p.x1 - p.x0) * 0.45f);
        float u = ((float)px + 0.5f - p.x0) / (p.x1 - p.x0), t = u * 2.0f - 0.5f;
        int g = (int)(255.0f * (t < 0 ? 0 : t > 1 ? 1 : t) + 0.5f);
        probe(px, cy(1), (unsigned)(g << 16 | g << 8 | g), 6, "FIMD 1 linear: u 0.45 between the texels");
    }
    // (0, 2): two-sided: culling is off while a 2SID shader draws (FUN_00329f70), so the culled winding shows
    if (P.twoSided) {
        ctx->vfunc_54(1);
        QuadSpec q = spec(0xffff8000u, 0);
        q.ccw = true;
        quadEx(ctx, P.twoSided, cell(0, 2, 16), 0.5f, q);
        QuadSpec q2 = q;
        for (int i = 0; i < 4; i++)
            q2.colour[i] = 0xff0000ffu;
        quadEx(ctx, P.plain, half(cell(0, 2, 16), false), 0.4f, q2);    // the plain shader culls again
        ctx->vfunc_54(0);
        PixRect p = pixCell(0, 2, 16);
        probe(cx(0), (int)(p.y0 + (p.y1 - p.y0) * 0.25f), 0xff8000, 2, "2SID: a counter-clockwise quad drawn");
        probe(cx(0), (int)(p.y0 + (p.y1 - p.y0) * 0.75f), 0xff8000, 2,
              "2SID left behind: the next shader culls (the 2SID quad shows)");
    }
    // (1, 2): additive with fog: fogging goes to black while the shader is active (d3dShader::vfunc_12), the
    // colour comes back when another shader is activated (vfunc_13)
    if (P.add && P.plain) {
        Rect c = cell(1, 2, 16);
        quad(ctx, P.plain, half(c, true), 0.5f, 0xff404040u);
        ctx->vfunc_78(1);
        float start = 0.0f, end = 1.0f;
        int a, b;
        memcpy(&a, &start, 4);
        memcpy(&b, &end, 4);
        ctx->vfunc_80((int)0xffff0000u, a, b);
        ctx->vfunc_62(0);
        quad(ctx, P.add, half(c, true), 0.5f, 0xff808080u);
        ctx->vfunc_62(1);
        quad(ctx, P.plain, half(c, false), 0.5f, 0xffffffffu);
        ctx->vfunc_78(0);
        PixRect p = pixCell(1, 2, 16);
        probe(cx(1), (int)(p.y0 + (p.y1 - p.y0) * 0.25f), 0x808080, 4, "additive + fog: fogged to black, added");
        probe(cx(1), (int)(p.y0 + (p.y1 - p.y0) * 0.75f), 0xff8080, 4, "fog colour back for the next shader");
    }
    // (2, 2): the environment shader's reflection: camera-space reflection vector (texgen), the sphere map in
    // texture stack 2 (its activation), clamped, point filtered: the centre's vector lands on texel (1, row 0)
    if (P.env) {
        QuadSpec q = spec(0xffffffffu);
        q.normal = true;
        quadEx(ctx, P.env, cell(2, 2, 16), 0.5f, q);
        probe(cx(2), cy(2), 0xff00ff, 4, "environment: reflection vector through the sphere map");
    }
    // (3, 2): FADE scales the alpha reference with the alpha: ACTH 0.5 still cuts at half the vertex alpha
    if (P.fadeTest) {
        Rect c = cell(3, 2, 16);
        quad(ctx, P.plain, c, 0.5f, 0xff000000u);
        QuadSpec q = spec(0xffffffffu, 0);
        q.colour[0] = q.colour[1] = 0x00ffffffu;
        ctx->vfunc_62(0);
        quadEx(ctx, P.fadeTest, c, 0.4f, q);
        ctx->vfunc_62(1);
        PixRect p = pixCell(3, 2, 16);
        probe((int)(p.x0 + (p.x1 - p.x0) * 0.25f), cy(2), 0x000000, 3, "FADE + alpha test: alpha 0.25 x fade cut");
        probe((int)(p.x0 + (p.x1 - p.x0) * 0.75f), cy(2), 0x606060, 5, "FADE + alpha test: 0.75 x fade kept, blended");
    }
}

// ---------------------------------------------------------------------------------------------
// Page 4: every combiner key of combiners.txt, drawn through its generated program and through the generic
// combiner, its colour and its alpha, each against a CPU reference of the D3D texture-stage operations (written
// from Direct3D 8's documentation, separately from the shader): 4 cells per key (colour generated, colour generic,
// alpha generated, alpha generic; the alpha shown as grey by blending a white cell by it). Inputs: solid textures
// per stage, the diffuse colour, the texture factor; the stages set straight into the device state and drawn with
// the framebuffer-effects shader (whose pass set-up is empty, so the state stays as set).
struct V4 {
    float c[4];
};
static V4 v4(unsigned d3dcolor)
{
    V4 v = {{((d3dcolor >> 16) & 255) / 255.0f, ((d3dcolor >> 8) & 255) / 255.0f, (d3dcolor & 255) / 255.0f,
             (d3dcolor >> 24) / 255.0f}};
    return v;
}
static float sat(float x) { return x < 0.0f ? 0.0f : x > 1.0f ? 1.0f : x; }

static V4 refArg(unsigned a, const V4& diff, const V4& cur, const V4& tex, const V4& tf, const V4& temp)
{
    V4 v;
    switch (a & 15) {
    case 0: v = diff; break;
    case 1: v = cur; break;
    case 2: v = tex; break;
    case 3: v = tf; break;
    case 5: v = temp; break;
    default: v = V4{{0, 0, 0, 0}}; break;      // specular: none in the sweep
    }
    if (a & 0x10)
        for (int i = 0; i < 4; i++)
            v.c[i] = 1.0f - v.c[i];
    if (a & 0x20)
        for (int i = 0; i < 3; i++)
            v.c[i] = v.c[3];
    return v;
}

// D3DTOP (Xbox numbering) on one channel k of the arguments; `alpha` channel 3
static float refOp(unsigned op, const V4& a1, const V4& a2, const V4& a0, int k, const V4& diff, const V4& cur,
                   const V4& tex, const V4& tf)
{
    float x = a1.c[k], y = a2.c[k];
    switch (op) {
    case 2: return x;
    case 3: return y;
    case 4: return x * y;
    case 5: return 2 * x * y;
    case 6: return 4 * x * y;
    case 7: return x + y;
    case 8: return x + y - 0.5f;
    case 9: return 2 * (x + y - 0.5f);
    case 10: return x - y;
    case 11: return x + y - x * y;
    case 12: return x * diff.c[3] + y * (1 - diff.c[3]);
    case 13: return x * cur.c[3] + y * (1 - cur.c[3]);
    case 14: return x * tex.c[3] + y * (1 - tex.c[3]);
    case 15: return x * tf.c[3] + y * (1 - tf.c[3]);
    case 16: return x + y * (1 - tex.c[3]);
    case 18: return k == 3 ? a1.c[3] : x + a1.c[3] * y;
    case 19: return k == 3 ? a1.c[3] : x * y + a1.c[3];
    case 20: return k == 3 ? a1.c[3] : x + (1 - a1.c[3]) * y;
    case 21: return k == 3 ? a1.c[3] : (1 - x) * y + a1.c[3];
    case 22: {
        float d = 0;
        for (int i = 0; i < 3; i++)
            d += (a1.c[i] - 0.5f) * (a2.c[i] - 0.5f);
        return sat(4 * d);
    }
    case 23: return a0.c[k] + x * y;
    case 24: return a0.c[k] * x + (1 - a0.c[k]) * y;
    default: return x;
    }
}

static int parseKey(const char* key, unsigned (*st)[7])
{
    if (!strcmp(key, "-"))
        return 0;
    int n = 0;
    const char* p = key;
    while (*p && n < 4) {
        unsigned v[7] = {0, 0, 0, 0, 0, 0, 0};
        for (int f = 0; f < 7; f++) {
            while (*p && (*p < '0' || *p > '9'))
                p++;
            while (*p >= '0' && *p <= '9')
                v[f] = v[f] * 10 + (unsigned)(*p++ - '0');
        }
        memcpy(st[n++], v, sizeof(v));
        while (*p && *p != '|')
            p++;
        if (*p == '|')
            p++;
    }
    return n;
}

static const unsigned kSweepTex[4] = {0xb4c86432u, 0x5a28dc78u, 0xc8963ce6u, 0xff5aaa1eu};
static const unsigned kSweepDiffuse = 0xa0b48c64u, kSweepFactor = 0x783c82d2u;

static V4 refCombine(unsigned (*st)[7], int n)
{
    V4 diff = v4(kSweepDiffuse), tf = v4(kSweepFactor), cur = diff, temp = {{0, 0, 0, 0}};
    for (int i = 0; i < n; i++) {
        V4 tex = v4(kSweepTex[i]);
        V4 c1 = refArg(st[i][1], diff, cur, tex, tf, temp), c2 = refArg(st[i][2], diff, cur, tex, tf, temp);
        V4 a1 = refArg(st[i][4], diff, cur, tex, tf, temp), a2 = refArg(st[i][5], diff, cur, tex, tf, temp);
        V4 r;
        for (int k = 0; k < 3; k++)
            r.c[k] = sat(refOp(st[i][0], c1, c2, cur, k, diff, cur, tex, tf));
        r.c[3] = sat(refOp(st[i][3], a1, a2, cur, 3, diff, cur, tex, tf));
        if (st[i][6] == 5)
            temp = r;
        else
            cur = r;
    }
    return cur;
}

struct Page4 {
    bool made;
    bgfxTexture* tex[4];
    bgfxShader* raw;
};
static Page4 s_p4;

static void sweepState(bgfxContext* ctx, unsigned (*st)[7], int n, Page4& P)
{
    bgfxContext::DeviceState& d = ctx->m_d3d;
    for (int i = 0; i < 4; i++) {
        bgfxContext::Stage& s = d.stage[i];
        if (i < n) {
            s.colorOp = st[i][0];
            s.colorArg1 = st[i][1];
            s.colorArg2 = st[i][2];
            s.alphaOp = st[i][3];
            s.alphaArg1 = st[i][4];
            s.alphaArg2 = st[i][5];
            s.resultArg = st[i][6];
        } else {
            s.colorOp = s.alphaOp = 1;
        }
        s.texCoordIndex = 0;
        s.transformFlags = 0;
        s.address = 1;
        s.magFilter = s.minFilter = 1;
        s.mipFilter = 0;
        s.texture = P.tex[i];
    }
    d.textureFactor = kSweepFactor;
    d.blend = false;
    d.alphaTest = false;
    d.lighting = d.specular = false;
    d.cull = 0;
}

static void page4(bgfxContext* ctx)
{
    Page4& P = s_p4;
    bgfxDevice* dev = ctx->m_device;
    if (!P.made) {
        P.made = true;
        for (int i = 0; i < 4; i++)
            P.tex[i] = solid(dev, kSweepTex[i]);
        P.raw = makeShader(dev, "fbeffectsshader");
    }
    beginPage(ctx);
    if (!P.raw)
        return;
    int nkeys = 0;
    while (g_pddi_combiner_keys[nkeys])
        nkeys++;
    if (!nkeys)
        return;
    const int perRow = 5, cols = perRow * 4, rows = (nkeys + perRow - 1) / perRow;
    float cw = s_scene.w / (float)cols, ch = s_scene.h / (float)rows;
    ctx->beginPass(P.raw, 0);               // active now: the draws below switch no shader (no slot 12/13 runs)
    for (int k = 0; k < nkeys; k++) {
        unsigned st[4][7];
        int n = parseKey(g_pddi_combiner_keys[k], st);
        V4 want = refCombine(st, n);
        int r8 = (int)(want.c[0] * 255.0f + 0.5f), g8 = (int)(want.c[1] * 255.0f + 0.5f),
            b8 = (int)(want.c[2] * 255.0f + 0.5f), a8 = (int)(want.c[3] * 255.0f + 0.5f);
        for (int cell4 = 0; cell4 < 4; cell4++) {
            int col = (k % perRow) * 4 + cell4, row = k / perRow;
            float px0 = col * cw + 2, px1 = (col + 1) * cw - 2, py0 = row * ch + 2, py1 = (row + 1) * ch - 2;
            Rect q = {2.0f * px0 / s_scene.w - 1.0f, 1.0f - 2.0f * py0 / s_scene.h, 2.0f * px1 / s_scene.w - 1.0f,
                      1.0f - 2.0f * py1 / s_scene.h};
            bool alpha = cell4 >= 2;
            ctx->m_forceGeneric = (cell4 & 1) != 0;
            if (alpha) {                        // a white cell, then the key's alpha multiplies it
                unsigned none[1][7];
                sweepState(ctx, none, 0, P);
                quadEx(ctx, P.raw, q, 0.5f, spec(0xffffffffu));
            }
            sweepState(ctx, st, n, P);
            if (alpha) {
                ctx->m_d3d.blend = true;
                ctx->m_d3d.blendOp = 0x8006;
                ctx->m_d3d.srcBlend = 0;        // zero
                ctx->m_d3d.dstBlend = 0x302;    // source alpha
            }
            quadEx(ctx, P.raw, q, 0.5f, spec(kSweepDiffuse));
            unsigned rgb = alpha ? (unsigned)(a8 << 16 | a8 << 8 | a8) : (unsigned)(r8 << 16 | g8 << 8 | b8);
            static char s_what[512][96];
            static const char* const kCell[4] = {"colour, generated", "colour, generic", "alpha, generated",
                                                 "alpha, generic"};
            char* w = s_what[s_nprobes < 512 ? s_nprobes : 511];
            logLine(w, 96, "sweep %s: %s", kCell[cell4], g_pddi_combiner_keys[k]);
            probe((int)((px0 + px1) * 0.5f), (int)((py0 + py1) * 0.5f), rgb, 3, w);
        }
    }
    ctx->m_forceGeneric = false;
    ctx->resetDeviceState();
}

// A screenshot's pixel against the probes: the number that pass (each logged through `out`)
int selfTestCheck(const unsigned char* px, unsigned w, unsigned h, unsigned pitch, bool bgra, bool yflip,
                  void (*out)(const char* line))
{
    int ok = 0;
    // a shot of a window the frame is scaled into (G5): frame probes land where the present put the frame
    int rx = 0, ry = 0, rw = (int)w, rh = (int)h;
    bool mapped = s_scene.display && (w != s_scene.w || h != s_scene.h);
    if (mapped)
        s_scene.display->presentRect(&rx, &ry, &rw, &rh);
    for (int i = 0; i < s_nprobes; i++) {
        const SelfTestProbe& p = s_probes[i];
        int x = p.x, y = p.y;
        if (mapped && !p.window) {
            x = rx + (int)(((float)p.x + 0.5f) * (float)rw / (float)s_scene.w);
            y = ry + (int)(((float)p.y + 0.5f) * (float)rh / (float)s_scene.h);
        }
        if (x < 0 || y < 0 || (unsigned)x >= w || (unsigned)y >= h)
            continue;
        unsigned row = yflip ? h - 1 - (unsigned)y : (unsigned)y;
        const unsigned char* c = px + row * pitch + (unsigned)x * 4;
        int rgb[3] = {bgra ? c[2] : c[0], c[1], bgra ? c[0] : c[2]};
        int want[3] = {(int)(p.rgb >> 16) & 255, (int)(p.rgb >> 8) & 255, (int)p.rgb & 255};
        bool good = true;
        for (int k = 0; k < 3; k++)
            if (rgb[k] - want[k] > p.tolerance || want[k] - rgb[k] > p.tolerance)
                good = false;
        ok += good;
        if (out) {
            char line[256];
            logLine(line, sizeof(line), "pddi: probe %d,%d %s: %d,%d,%d (want %d,%d,%d) %s\n", x, y,
                    good ? "ok" : "FAIL", rgb[0], rgb[1], rgb[2], want[0], want[1], want[2], p.what);
            out(line);
        }
    }
    return ok;
}


// ---------------------------------------------------------------------------------------------
// G4 page 5: the frame-buffer copy and the refraction shader (prim buffers with the "refract" program; the
// skinning extension's "skin_refract"). Each cell: a known pattern (left half red, right half green, behind), then
// the refraction shader over the whole cell. With the copy, the shader shows the frame as it was when its pass began,
// sampled at the pixel's own place plus the projected normal x REFI pixels, times REFC; then blended by the program's
// alpha (refract: k = clamp((n . ndc)^2 + REFB - 0.3, 0, 1); skin_refract: REFB - 0.3).
//   (0, 0) the pattern alone | (1, 0) refract, normal (1, 0, 2), REFI so that the offset is 20 pixels right, REFC
//   (128, 255, 128): k = 1 | (2, 0) two refraction draws, no offset: the second's copy holds the first's output (the
//   tint twice) | (3, 0) skin_refract through d3dExtHardwareSkinning (bones move the quad half a screen right; the
//   same 20-pixel offset from the blended normal), alpha 0.7
//   (0, 1) refract, normal (0, 0, 1) at z 0: k = 0.7 (the program's alpha blends the tinted copy over the frame)
//   (1, 1) the copy follows a mid-frame clear: a cell cleared to blue (a viewport + clear), then refract with no
//   offset and REFC (255, 0, 255): the copy's blue comes through (outside the cleared viewport: the clear colour)
//   (2, 1) a prim buffer made with no program, given "refract" the way the prim group loaders do it: the vertex
//   program extension (0x106) slots 4 (has a program), 2 (its handle), 5 (onto the buffer); the 20-pixel offset
//   (3, 1) a streamed prim group's way: extension slot 6 binds the handle, prim streams (normals) draw with it
struct Page5 {
    bool made;
    bgfxShader *plain, *refract[7];
    bgfxPrimBuffer *buf[7];
    int streamHandle;
};
static Page5 s_p5;

// a quad prim buffer (the refraction program, or skinned for skin_refract) with one normal for every vertex
static bgfxPrimBuffer* refractQuad(bgfxDevice* dev, const Rect& q, float z, const float* n, bool skinned)
{
    unsigned flags = skinned ? (0x180u | 0x10u | 1u) : (0x10u | 1u);
    intptr_t params[8] = {kPrimTriList, (intptr_t)flags, 0, 0, 4, 6, 0, (intptr_t)(skinned ? 0 : "refract")};
    bgfxPrimBuffer* b = (bgfxPrimBuffer*)dev->vfunc_10(params);
    if (!b)
        return 0;
    b->vfunc_0();
    bgfxPrimBufferStream* s = (bgfxPrimBufferStream*)b->vfunc_4();
    const float pos[4][3] = {{q.x0, q.y1, z}, {q.x0, q.y0, z}, {q.x1, q.y1, z}, {q.x1, q.y0, z}};
    for (int i = 0; i < 4; i++) {
        if (skinned) {
            s->vfunc_11(0.5f, 0.5f, 0.0f);
            s->vfunc_10(0, 1, 2, 0);
        }
        s->vfunc_1(n[0], n[1], n[2]);
        s->vfunc_6(0.0f, 0.0f, 0);
        s->vfunc_0(pos[i][0], pos[i][1], pos[i][2]);
    }
    b->vfunc_5(s);
    static const unsigned short idx[6] = {0, 1, 2, 2, 1, 3};
    b->vfunc_9((void*)idx, 6);
    return b;
}

// the pattern a cell's refraction reads: left half red, right half green, at the back
static void pattern(bgfxContext* ctx, int c, int r)
{
    Rect q = cell(c, r, 16);
    Rect left = q, right = q;
    float mid = (q.x0 + q.x1) * 0.5f;
    left.x1 = mid;
    right.x0 = mid;
    quad(ctx, s_p5.plain, left, 0.95f, 0xffff0000u);
    quad(ctx, s_p5.plain, right, 0.95f, 0xff00ff00u);
}

static void setupPage5(bgfxContext* ctx)
{
    Page5& P = s_p5;
    P.made = true;
    bgfxDevice* dev = ctx->m_device;
    P.plain = simpleShader(dev, 0);
    // the packed normal is scaled by 1 / (length x 1.001) (the stream's slot 1): n = (1, 0, 2) gives x 0.4464
    static const float n12[3] = {1.0f, 0.0f, 2.0f}, n001[3] = {0.0f, 0.0f, 1.0f};
    const float nx = 1.0f / (2.2360680f * 1.001f);
    for (int i = 0; i < 7; i++) {
        P.refract[i] = makeShader(dev, "refract");
        if (P.refract[i])
            setC(P.refract[i], "REFC", 0xff80ff80u);
    }
    P.buf[0] = refractQuad(dev, cell(1, 0, 16), 0.9f, n12, false);
    if (P.refract[0])
        setF(P.refract[0], "REFI", 20.0f / nx);
    P.buf[1] = refractQuad(dev, cell(2, 0, 16), 0.9f, n12, false);
    if (P.refract[1])
        setF(P.refract[1], "REFI", 0.0f);
    // skinned: placed half a screen to the left, the bones (half +1, half 0 in x) move it into cell (3, 0)
    Rect sq = cell(3, 0, 16);
    sq.x0 -= 0.5f;
    sq.x1 -= 0.5f;
    P.buf[2] = refractQuad(dev, sq, 0.9f, n12, true);
    if (P.refract[2])
        setF(P.refract[2], "REFI", 20.0f / nx);
    P.buf[3] = refractQuad(dev, cell(0, 1, 16), 0.0f, n001, false);
    if (P.refract[3])
        setF(P.refract[3], "REFI", 0.0f);
    P.buf[4] = refractQuad(dev, cell(1, 1, 16), 0.9f, n12, false);
    if (P.refract[4]) {
        setF(P.refract[4], "REFI", 0.0f);
        setC(P.refract[4], "REFC", 0xffff00ffu);
    }
    // (2, 1): no program name at creation (fixed function), then the loaders' extension calls
    P.buf[5] = refractQuad(dev, cell(2, 1, 16), 0.9f, n12, false);
    if (P.buf[5])
        P.buf[5]->m_program = "";
    bgfxExtVertexProgram* vp = (bgfxExtVertexProgram*)ctx->m_ext[6];         // slot 89 (0x106)
    if (P.refract[5]) {
        setF(P.refract[5], "REFI", 20.0f / nx);
        if (vp && P.buf[5] && vp->vfunc_4(P.refract[5], 0))
            vp->vfunc_5(P.buf[5], vp->vfunc_2(P.refract[5], 0x11, 0, 1, 0));
    }
    // (3, 1): the streamed binding
    P.streamHandle = 0;
    if (P.refract[6]) {
        setF(P.refract[6], "REFI", 20.0f / nx);
        if (vp && vp->vfunc_4(P.refract[6], 0))
            P.streamHandle = vp->vfunc_2(P.refract[6], 0x11, 0, 1, 0);
    }
}

static void page5(bgfxContext* ctx)
{
    Page5& P = s_p5;
    if (!P.made)
        setupPage5(ctx);
    beginPage(ctx);
    bgfxContext::Light l;                   // lights don't reach the colour here (unlit: the stages ignore it)
    memset(&l, 0, sizeof(l));
    for (int i = 0; i < bgfxContext::kLights; i++)
        ctx->hostSetLight(i, l);
    int cw = (int)(s_scene.w / 4.0f);
    // the half boundary of cell c, in pixels
    #define BX(c) ((c) * cw + cw / 2)
    const unsigned red = 0xff0000, green = 0x00ff00;
    const unsigned redT = 0x800000, greenT = 0x00ff00;          // x REFC (128, 255, 128)
    if (!P.plain)
        return;
    pattern(ctx, 0, 0);
    probe(BX(0) - 30, cy(0), red, 2, "pattern: left half red");
    probe(BX(0) + 30, cy(0), green, 2, "pattern: right half green");
    pattern(ctx, 1, 0);
    pattern(ctx, 2, 0);
    pattern(ctx, 3, 0);
    pattern(ctx, 0, 1);
    if (P.refract[0] && P.buf[0]) {
        ctx->vfunc_32(P.refract[0], P.buf[0]);
        probe(BX(1) - 30, cy(0), redT, 3, "refract: 20 px right of 30 px left of the edge: red x REFC");
        probe(BX(1) - 10, cy(0), greenT, 3, "refract: 20 px right of 10 px left of the edge: green x REFC");
        probe(BX(1) + 20, cy(0), greenT, 3, "refract: right half samples green");
    }
    if (P.refract[1] && P.buf[1]) {
        ctx->vfunc_32(P.refract[1], P.buf[1]);
        ctx->vfunc_32(P.refract[1], P.buf[1]);
        probe(BX(2) - 30, cy(0), 0x400000, 3, "refract twice: the second copy has the first's output (red x 0.5^2)");
        probe(BX(2) + 30, cy(0), green, 3, "refract twice: green x 1 x 1");
    }
    bgfxExtHardwareSkinning* sk = (bgfxExtHardwareSkinning*)ctx->m_ext[4];
    if (P.refract[2] && P.buf[2] && sk) {
        float b0[16], b1[16], b2[16];
        identity(b0);
        identity(b1);
        identity(b2);
        b0[12] = 1.0f;
        b2[12] = 5.0f;
        sk->vfunc_5(0, b0);
        sk->vfunc_5(1, b1);
        sk->vfunc_5(2, b2);
        sk->vfunc_6(P.refract[2], P.buf[2]);
        // alpha 0.7: 0.7 x (sampled x REFC) + 0.3 x the pattern under it
        probe(BX(3) - 30, cy(0), 0xa50000, 4, "skin_refract: 0.7 red x REFC + 0.3 red");
        probe(BX(3) - 10, cy(0), 0x4cb200, 4, "skin_refract: 0.7 green (offset 20) + 0.3 red");
        probe(BX(3) + 20, cy(0), 0x00ff00, 4, "skin_refract: green");
    }
    if (P.refract[3] && P.buf[3]) {
        ctx->vfunc_32(P.refract[3], P.buf[3]);
        // k = 0.7 (n . ndc = 0): 0.7 x red x REFC + 0.3 x red
        probe(BX(0) - 30, cy(1), 0xa50000, 4, "refract, k = 0.7: the program's alpha blends the copy");
        probe(BX(0) + 30, cy(1), green, 3, "refract, k = 0.7: green x 1");
    }
    if (P.refract[4] && P.buf[4]) {
        // a mid-frame viewport + clear to blue over cell (1, 1), then the refraction: its copy sees the clear
        unsigned saved[4];
        memcpy(saved, ctx->m_viewport, sizeof(saved));
        bgfxContext::ViewBlock* v = ctx->viewBlock();
        bgfxContext::ViewBlock keep = *v;
        int px0 = cw + 16, px1 = 2 * cw - 16, py0 = (int)(s_scene.h / 3.0f) + 16, py1 = (int)(2 * s_scene.h / 3.0f) - 16;
        v->x0 = (float)px0 / s_scene.w;
        v->x1 = (float)px1 / s_scene.w;
        v->y0 = (float)py0 / s_scene.h;
        v->y1 = (float)py1 / s_scene.h;
        ctx->vfunc_24(1);                   // orthographic: the viewport of the view block
        ctx->vfunc_6(0xff0000ffu);
        ctx->hostSetClear(0xff0000ffu, 1.0f, 0);
        ctx->vfunc_12(1 | 2);
        *v = keep;
        ctx->vfunc_24(0);
        float I[16];
        identity(I);
        ctx->setViewTransform(I, I);        // back to clip space for the quad
        ctx->vfunc_32(P.refract[4], P.buf[4]);
        probe(cx(1), cy(1), 0x0000ff, 3, "refract after a mid-frame clear: the copy holds the clear (blue x REFC)");
        probe(cx(1) - cw / 2 + 8, cy(1), kClearColour & 0xffffff, 3, "refract after a clear: outside the viewport");
    }
    pattern(ctx, 2, 1);
    pattern(ctx, 3, 1);
    if (P.refract[5] && P.buf[5]) {
        ctx->vfunc_32(P.refract[5], P.buf[5]);
        probe(BX(2) - 30, cy(1), redT, 3, "refract via the vertex program extension (slots 4, 2, 5): red x REFC");
        probe(BX(2) - 10, cy(1), greenT, 3, "refract via the extension: 20 px offset, green x REFC");
    }
    bgfxExtVertexProgram* vp = (bgfxExtVertexProgram*)ctx->m_ext[6];
    if (P.refract[6] && vp && P.streamHandle) {
        vp->vfunc_6((unsigned)P.streamHandle);              // PrimGroupStreamed::vfunc_6 binds it around its draws
        Rect q = cell(3, 1, 16);
        const float pos[4][3] = {{q.x0, q.y1, 0.9f}, {q.x0, q.y0, 0.9f}, {q.x1, q.y1, 0.9f}, {q.x1, q.y0, 0.9f}};
        const float n[3] = {1.0f / 2.2360680f, 0.0f, 2.0f / 2.2360680f};
        bgfxPrimStream* p = (bgfxPrimStream*)ctx->vfunc_30(P.refract[6], kPrimTriStrip, kVertexNormal | 1, 4, 0);
        for (int i = 0; i < 4; i++) {
            memcpy(p->posPtr, pos[i], 12);
            memcpy(p->normalPtr, n, 12);
            const float uv[2] = {0.0f, 0.0f};
            memcpy(p->uvPtr, uv, 8);
            p->vertex();
        }
        ctx->vfunc_31(p);
        vp->vfunc_6(0);
        // the stream's normal is not packed: x = 0.4472 (the buffer's 0.4464 sets REFI): 20.04 pixels
        probe(BX(3) - 30, cy(1), redT, 3, "refract on a prim stream bound through extension slot 6: red x REFC");
        probe(BX(3) - 10, cy(1), greenT, 3, "refract on the bound prim stream: 20 px offset, green x REFC");
    }
    #undef BX
    (void)red;
}


// ---------------------------------------------------------------------------------------------
// G4 pages 6-8: the framebuffer effects extension (context slot 89, 0x103), each pass over the whole frame, checked
// against a CPU reference written here from the xps text and the slots' arithmetic (not from the shaders):
// combiner clamps to [-1, 1], 8-bit constants, 8-bit targets.
// Page 6: eight colour cells (rows 0-1); two fbeffects shaders (one drawn through context slot 32, the other through
//   its UPDT parameter) averaged by slot 5 into the colour correction, slot 6 over the frame; row 2 after it: the
//   visibility test (a quad half behind an occluder: the cell turns green when the count is half the quad's pixels,
//   red otherwise; the count is last frame's) | untouched cells (drawn after the pass)
// Page 7: the bloom (slots 8, 7, 9): bright pass (luminance, contrast, midpoint), the tinted quarter copy, the gaussian
//   (sigma 2: three taps), the composite 2 x blur x amount + frame x blend; probes in the uniform cells' interiors
// Page 8: the overlay (slots 1, 2): additive, split into three channels, scale 4: the front buffer zoomed onto the
//   frame each frame; a uniform region converges to colour / (1 - a)
static float rq8(float v)
{
    v = v < 0.0f ? 0.0f : v > 1.0f ? 1.0f : v;
    return (float)(int)(v * 255.0f + 0.5f) / 255.0f;
}
static float rs(float v) { return v < -1.0f ? -1.0f : v > 1.0f ? 1.0f : v; }
static int r8(float v) { v = v < 0.0f ? 0.0f : v > 1.0f ? 1.0f : v; return (int)(v * 255.0f + 0.5f); }

// FUN_00320540's program for (level lv, side 0) run on one colour: the xps text as instructions
static void refColourPass(const float* rgb, const float* c0, float c3, float c5, const float* c6, float c7, int lv,
                          float* out)
{
    float lum = rs(c0[0] * rgb[0] + c0[1] * rgb[1] + c0[2] * rgb[2]);         // dp3 r0, t0, c0
    float r0[3], r1;
    for (int k = 0; k < 3; k++)
        r0[k] = rs(rgb[k] - lum);                                          // add r0.xyz, t0, -r0
    r1 = rs(lum * c5 + (2.0f * c3 - 1.0f));                                // + mad r1.w, r0.w, c5, c3_bx2
    for (int k = 0; k < 3; k++)
        r0[k] = rs(2.0f * r0[k] * c7);                                     // mul_x2 r0.xyz, r0, c7
    if (lv >= 32)
        r1 = rs(4.0f * r1);                                                // + mov_x4
    else if (lv >= 16)
        r1 = rs(2.0f * r1);                                                // + mov_x2
    for (int k = 0; k < 3; k++)
        r0[k] = rs((2.0f * c6[k] - 1.0f) * lum + r0[k]);                   // mad r0.xyz, c6_bx2, r0.w, r0
    if (lv == 64)
        r1 = rs(2.0f * r1);
    // side 0: add; [add; [+mov_x2; add; [+mov_x2; add]]] by level
    int adds = lv > 4 ? 4 : lv > 2 ? 3 : lv > 1 ? 2 : 1;
    for (int i = 0; i < adds; i++) {
        for (int k = 0; k < 3; k++)
            r0[k] = rs(r0[k] + r1);
        if (i >= 1)                                                        // the mov_x2 paired with adds 2 and 3
            r1 = rs(2.0f * r1);
    }
    for (int k = 0; k < 3; k++)
        out[k] = r0[k] < 0.0f ? 0.0f : r0[k];
}

// FUN_00324660 for brightness below 0.5 (all the game can ask for): the constants, then the program
static void refFilter(const float* rgb, const float* w, float f1, float f2, const float* b, float f3, float f4,
                      float* out)
{
    float dot = w[0] * b[0] + w[1] * b[1] + w[2] * b[2];
    float c0[3] = {rq8(w[0]), rq8(w[1]), rq8(w[2])};
    float base = f2 == 1.0f ? f1 : ((f1 - f3) * f2 + f3) * dot;
    int lv = 1;
    while (lv < 64 && f2 > (float)lv)
        lv *= 2;
    float q = 1.0f / (float)lv;
    float c6[3];
    for (int k = 0; k < 3; k++)
        c6[k] = rq8((b[k] - dot + 1.0f) * 0.5f);
    refColourPass(rgb, c0, rq8((base * q + 1.0f) * 0.5f), rq8(f2 * q * dot), c6, rq8(dot * f4), lv, out);
}

struct Page6 {
    bool made;
    bgfxShader *plain, *fx[2];
};
static Page6 s_p6;

static const unsigned kP6Colours[8] = {0xff808080u, 0xffc04020u, 0xff20c040u, 0xff3060d0u,
                                       0xffffffffu, 0xff000000u, 0xffe0d020u, 0xff40d0d0u};

static void page6(bgfxContext* ctx)
{
    Page6& P = s_p6;
    bgfxDevice* dev = ctx->m_device;
    if (!P.made) {
        P.made = true;
        P.plain = simpleShader(dev, 0);
        // two fbeffects shaders (pddi name "fbeffectsshader"): their average drives the colour correction
        P.fx[0] = makeShader(dev, "fbeffectsshader");
        P.fx[1] = makeShader(dev, "fbeffectsshader");
        const float sat[2] = {20.0f, -20.0f}, brit[2] = {10.0f, 30.0f}, mid[2] = {0.5f, 0.3f}, cont[2] = {40.0f, 60.0f};
        const unsigned tint[2] = {0xffe0c0a0u, 0xffb0d0e0u};
        for (int i = 0; i < 2; i++)
            if (P.fx[i]) {
                setF(P.fx[i], "SAT", sat[i]);
                setF(P.fx[i], "BRIT", brit[i]);
                setF(P.fx[i], "MDPT", mid[i]);
                setF(P.fx[i], "CONT", cont[i]);
                setC(P.fx[i], "TINT", tint[i]);
                setI(P.fx[i], "CLRE", 1);
            }
    }
    beginPage(ctx);
    bgfxExtFramebufferEffects* fx = (bgfxExtFramebufferEffects*)ctx->m_ext[7];   // slot 89 (0x103)
    if (!P.plain || !fx || !P.fx[0] || !P.fx[1])
        return;
    for (int i = 0; i < 8; i++)
        quad(ctx, P.plain, cell(i % 4, i / 4, 16), 0.5f, kP6Colours[i]);
    ctx->vfunc_32(P.fx[0], 0);                // slot 32 with an fbeffects shader: no draw, its settings added
    setI(P.fx[1], "UPDT", 1);                 // UPDT adds them too
    fx->vfunc_5();                            // the average: on, saturation 0, brightness 20, contrast 50, mid 0.4
    fx->vfunc_6();
    // the reference: slot 4 with the averages, then the colour pass
    float amount = 20.0f / 255.0f, curve = 2.09608f, bias = 0.4f;
    float result = (curve < 1.0f ? curve : 1.0f) * 1.0f;
    float tint[3] = {(float)0xc8 / 255.0f, (float)0xc8 / 255.0f, (float)0xc0 / 255.0f};
    static const float kW[3] = {0.25f, 0.625f, 0.125f};
    static char what[8][64];
    for (int i = 0; i < 8; i++) {
        unsigned c = kP6Colours[i];
        float rgb[3] = {(float)((c >> 16) & 255) / 255.0f, (float)((c >> 8) & 255) / 255.0f, (float)(c & 255) / 255.0f};
        float out[3];
        refFilter(rgb, kW, amount, curve, tint, bias, result * 0.5f, out);
        unsigned want = (unsigned)(r8(out[0]) << 16 | r8(out[1]) << 8 | r8(out[2]));
        logLine(what[i], sizeof(what[i]), "colour correction of %06x", c & 0xffffff);
        probe(cx(i % 4), cy(i / 4), want, 4, what[i]);
    }
    unsigned clearCorrected;
    {
        float clr[3] = {0x20 / 255.0f, 0x30 / 255.0f, 0x40 / 255.0f}, out[3];
        refFilter(clr, kW, amount, curve, tint, bias, result * 0.5f, out);
        clearCorrected = (unsigned)(r8(out[0]) << 16 | r8(out[1]) << 8 | r8(out[2]));
        probe(cx(0), (int)(s_scene.h / 3.0f) - 6, clearCorrected, 4, "colour correction of the clear colour");
    }
    // row 2: the visibility test (BillboardQuadGroup's use): occluder at z 0.3 over the left half, the test quad at
    // z 0.6 with colour writes off; the count is last frame's (bgfx answers late)
    bgfxExtVisibilityTest* vis = (bgfxExtVisibilityTest*)ctx->m_ext[5];       // slot 89 (0x500002)
    if (vis) {
        int cw = (int)(s_scene.w / 4.0f), ch = (int)(s_scene.h / 3.0f);
        int px0 = 16, px1 = cw - 16, py0 = 2 * ch + 16, py1 = 3 * ch - 16;
        Rect q = cell(0, 2, 16);
        Rect left = q;
        left.x1 = (q.x0 + q.x1) * 0.5f;
        quad(ctx, P.plain, left, 0.3f, 0xff404040u);
        ctx->vfunc_56(0, 0, 0, 1);
        ctx->vfunc_62(0);
        vis->vfunc_2();
        quad(ctx, P.plain, q, 0.6f, 0xffffffffu);
        vis->vfunc_3(0);
        unsigned n = vis->vfunc_4(0);
        ctx->vfunc_62(1);
        ctx->vfunc_56(1, 1, 1, 1);
        int area = (px1 - px0) * (py1 - py0), half = area / 2;
        bool good = (int)n >= half - area / 50 && (int)n <= half + area / 50;
        Rect ind = cell(1, 2, 16);
        quad(ctx, P.plain, ind, 0.5f, good ? 0xff00ff00u : 0xffff0000u);
        static char visWhat[96];
        logLine(visWhat, sizeof(visWhat), "visibility test: half the quad's pixels pass (last frame's count: %u of %d)",
                n, area);
        probe(cx(1), cy(2), 0x00ff00, 2, visWhat);
        probe(cx(0) - cw / 4, cy(2), 0x404040, 2, "visibility test: the occluder (the test quad drew nothing)");
        probe(cx(0) + cw / 4, cy(2), clearCorrected, 4, "visibility test: no colour where it passed (the corrected "
              "clear)");
    }
    quad(ctx, P.plain, cell(2, 2, 16), 0.5f, 0xff808080u);
    probe(cx(2), cy(2), 0x808080, 2, "after the pass: untouched");
}

// ---- page 7: the bloom
struct Page7 {
    bool made;
    bgfxShader* plain;
};
static Page7 s_p7;
static const unsigned kP7Colours[4] = {0xff808080u, 0xffe04020u, 0xff2060f0u, 0xffffffffu};

// the bloom of a uniform region, as the passes do it (8-bit targets between them)
static void refBloom(const float* rgb, const float* weights, float radius, float contrast, float mix, uint32_t factor,
                     const float* taps, int count, float amount, float blend, float* out)
{
    static const float kOne[3] = {1.0f, 1.0f, 1.0f};
    float bright[3];
    refFilter(rgb, weights, radius, contrast, kOne, mix, 0.0f, bright);
    float half[3], quarter[3];
    for (int k = 0; k < 3; k++) {
        half[k] = (float)r8(bright[k]) / 255.0f;
        float f = (float)((factor >> (16 - 8 * k)) & 255) / 255.0f;
        quarter[k] = (float)r8(half[k] * f) / 255.0f;
    }
    // the gaussian of a uniform value: each direction, one side's draws (batches of 4 taps) then the other's,
    // added in an 8-bit target; then the other direction
    float v[3];
    memcpy(v, quarter, sizeof(v));
    for (int pass = 0; pass < 2; pass++) {
        float acc[3] = {0, 0, 0};
        bool first = true;
        for (int side = 0; side < 2; side++) {
            float sum[3] = {0, 0, 0};
            int batch = 0;
            for (int n = 0; n < count; n++) {
                if (side == 1 && n == 0)
                    continue;
                for (int k = 0; k < 3; k++)
                    sum[k] = rs(v[k] * rq8(taps[n]) + sum[k]);
                ++batch;
                if (batch == 4 || n == count - 1) {
                    for (int k = 0; k < 3; k++) {
                        float d = sum[k] < 0.0f ? 0.0f : sum[k];
                        acc[k] = first ? (float)r8(d) / 255.0f : (float)r8(acc[k] + (float)r8(d) / 255.0f) / 255.0f;
                        sum[k] = 0.0f;
                    }
                    first = false;
                    batch = 0;
                }
            }
        }
        memcpy(v, acc, sizeof(v));
    }
    for (int k = 0; k < 3; k++)
        out[k] = rs(rs(2.0f * v[k] * rq8(amount)) + rgb[k] * rq8(blend));
}

static void page7(bgfxContext* ctx)
{
    Page7& P = s_p7;
    if (!P.made) {
        P.made = true;
        P.plain = simpleShader(ctx->m_device, 0);
    }
    beginPage(ctx);
    bgfxExtFramebufferEffects* fx = (bgfxExtFramebufferEffects*)ctx->m_ext[7];
    if (!P.plain || !fx)
        return;
    // four big uniform regions (each a 2 x 1 block of cells, rows 0-1), the clear colour in row 2
    int cw = (int)(s_scene.w / 4.0f), ch = (int)(s_scene.h / 3.0f);
    for (int i = 0; i < 4; i++) {
        Rect q = cell((i % 2) * 2, i / 2, 0);
        Rect q2 = cell((i % 2) * 2 + 1, i / 2, 0);
        q.x1 = q2.x1;
        quad(ctx, P.plain, q, 0.5f, kP7Colours[i]);
    }
    // amount 1 (x 0.5), the quarter copy at (0.75, 0.5, 1), blend 0.5, width 8 (sigma 2), weights from (255, 128, 64)
    // (normalised), brightness -20, contrast 30, midpoint 0.6
    fx->vfunc_8(1.0f, 0xffc080ffu, 0.5f, 8.0f, 0xffff8040u, -20.0f, 30.0f, 0.6f);
    fx->vfunc_7(1);
    fx->vfunc_9();
    float wsum = 255.0f + 128.0f + 64.0f;
    float weights[3] = {255.0f / wsum, 128.0f / wsum, 64.0f / wsum};
    // the gaussian's taps, as slot 8 computes them (sigma 2: s = 1.2)
    float taps[20];
    int count = 0;
    {
        double s2 = 1.2 * 1.2, sum = 1.0;
        taps[0] = 1.0f;
        count = 1;
        for (int i = 1; i < 20; i++) {
            double wv = exp(-(double)(i * i) / s2);
            if (!(wv > 1.0 / 255.0))
                break;
            taps[count++] = (float)wv;
            sum += 2.0 * wv;
        }
        for (int i = 0; i < count; i++)
            taps[i] = (float)(taps[i] / sum);
    }
    static char what[5][64];
    for (int i = 0; i < 5; i++) {
        unsigned c = i < 4 ? kP7Colours[i] : kClearColour;
        float rgb[3] = {(float)((c >> 16) & 255) / 255.0f, (float)((c >> 8) & 255) / 255.0f, (float)(c & 255) / 255.0f};
        float out[3];
        refBloom(rgb, weights, -20.0f / 255.0f, 1.44878f, 0.6f, 0xffc080ffu, taps, count, 0.5f, 0.5f, out);
        unsigned want = (unsigned)(r8(out[0]) << 16 | r8(out[1]) << 8 | r8(out[2]));
        logLine(what[i], sizeof(what[i]), "bloom of %06x", c & 0xffffff);
        int x = i < 4 ? (i % 2) * 2 * cw + cw : 2 * cw, y = i < 4 ? (i / 2) * ch + ch / 2 : 2 * ch + ch / 2;
        probe(x, y, want, 4, what[i]);
    }
}

// ---- page 8: the overlay
struct Page8 {
    bool made;
    bgfxShader* plain;
};
static Page8 s_p8;

static void page8(bgfxContext* ctx)
{
    Page8& P = s_p8;
    if (!P.made) {
        P.made = true;
        P.plain = simpleShader(ctx->m_device, 0);
    }
    beginPage(ctx);
    bgfxExtFramebufferEffects* fx = (bgfxExtFramebufferEffects*)ctx->m_ext[7];
    if (!P.plain || !fx)
        return;
    Rect big = cell(1, 0, 0);
    Rect b2 = cell(2, 2, 0);
    big.x1 = b2.x1;
    big.y1 = b2.y1;
    quad(ctx, P.plain, big, 0.5f, 0xff102030u);
    // on, alpha 0.5, scale 4 (additive: 0.5 x 254 = 127 per channel), split: red, green, blue at scales 4, 8, 12
    fx->vfunc_1(1, 0.5f, 4.0f, 1);
    fx->vfunc_2();
    // a uniform region: x = c + (127/255) x, so x = c / (1 - 127/255) (in 8 bits, settling a little lower)
    float a = 127.0f / 255.0f;
    unsigned want = 0;
    const unsigned c[3] = {0x10, 0x20, 0x30};
    for (int k = 0; k < 3; k++) {
        int x = (int)c[k];
        for (int i = 0; i < 40; i++)                          // what the 8-bit target settles to
            x = r8((float)c[k] / 255.0f + (float)(int)((float)x * a + 0.5f) / 255.0f);
        want = (want << 8) | (unsigned)x;
    }
    probe(s_scene.w / 2, s_scene.h / 2, want, 4, "overlay: additive, split, the front buffer zoomed: c / (1 - a)");
    probe(s_scene.w / 2 + 40, s_scene.h / 2 - 30, want, 4, "overlay: the same off centre");
}

} // namespace pddi
} // namespace hulk

namespace hulk {
namespace pddi {

// ---------------------------------------------------------------------------------------------
// G5 page 9: window scaling. Four quadrants of known colours fill the frame; the shot is of the window, which the
// driver may have resized (the smoke test: 960x540 linear, 900x600 integer, 800x800 nearest; the game image:
// HULK_GFX_WINDOW / HULK_GFX_SCALE). Probes: each quadrant's centre (frame pixels, mapped through the present
// rectangle), the frame's first and last columns and rows in the window (the quadrant there), and the bars just
// outside them (black). At the frame's own size the page is the quadrants alone.
static void page9(bgfxContext* ctx)
{
    SceneState& S = s_scene;
    beginPage(ctx);
    static const unsigned kQ[4] = {0xffe02020u, 0xff20e020u, 0xff2020e0u, 0xffe0e020u};   // TL, TR, BL, BR
    static const char* const kWhat[4] = {"scaled frame: top-left quadrant", "scaled frame: top-right quadrant",
                                         "scaled frame: bottom-left quadrant", "scaled frame: bottom-right quadrant"};
    for (int k = 0; k < 4; k++) {
        Rect q = {k & 1 ? 0.0f : -1.0f, k & 2 ? 0.0f : 1.0f, k & 1 ? 1.0f : 0.0f, k & 2 ? -1.0f : 0.0f};
        quad(ctx, S.plain, q, 0.5f, kQ[k]);
        probe((int)(S.w * (k & 1 ? 3 : 1) / 4), (int)(S.h * (k & 2 ? 3 : 1) / 4), kQ[k], 2, kWhat[k]);
    }
    bgfxDisplay* d = S.display;
    if (!d || (d->m_windowWidth == S.w && d->m_windowHeight == S.h))
        return;
    int rx, ry, rw, rh;
    d->presentRect(&rx, &ry, &rw, &rh);
    int midY = ry + rh / 4, midX = rx + rw / 4;
    probeWindow(rx, midY, kQ[0], 2, "scaled frame: its first column (top-left quadrant)");
    probeWindow(rx + rw - 1, midY, kQ[1], 2, "scaled frame: its last column (top-right quadrant)");
    probeWindow(midX, ry, kQ[0], 2, "scaled frame: its first row (top-left quadrant)");
    probeWindow(midX, ry + rh - 1, kQ[2], 2, "scaled frame: its last row (bottom-left quadrant)");
    if (rx > 0) {
        probeWindow(rx - 1, midY, 0, 0, "bar: just left of the frame (black)");
        probeWindow(rx / 2, ry + rh / 2, 0, 0, "bar: the middle of the left bar");
    }
    if (rx + rw < (int)d->m_windowWidth)
        probeWindow(rx + rw, midY, 0, 0, "bar: just right of the frame (black)");
    if (ry > 0) {
        probeWindow(midX, ry - 1, 0, 0, "bar: just above the frame (black)");
        probeWindow(rx + rw / 2, ry / 2, 0, 0, "bar: the middle of the top bar");
    }
    if (ry + rh < (int)d->m_windowHeight)
        probeWindow(midX, ry + rh, 0, 0, "bar: just below the frame (black)");
}

} // namespace pddi
} // namespace hulk

namespace hulk {
namespace pddi {

// ---------------------------------------------------------------------------------------------
// G5 page 10: two-sided lighting (a lit 2SID shader: FUN_00329f70 turns culling off and TWOSIDEDLIGHTING on). One
// directional light shining into the screen; quads with their normal toward the camera or away, drawn clockwise
// (front faces) or counter-clockwise (back faces). A back face is lit with the reversed normal: lit where its normal
// points away. The same quads through a lit one-sided shader (culling off by hand) show the back faces unlit.
struct Page10 {
    bool made;
    bgfxShader* twoSided;       // LIT, 2SID, white diffuse, black ambient
    bgfxPrimBuffer* quads[4];   // (normal toward, cw), (toward, ccw), (away, ccw), (away, cw)
};
static Page10 s_p10;

static bgfxPrimBuffer* normalQuad(bgfxDevice* dev, const Rect& q, float nz, bool ccw)
{
    intptr_t params[8] = {kPrimTriList, 0x10, 0, 0, 4, 6, 0, (intptr_t)""};
    bgfxPrimBuffer* b = (bgfxPrimBuffer*)dev->vfunc_10(params);
    if (!b)
        return 0;
    b->vfunc_0();
    bgfxPrimBufferStream* s = (bgfxPrimBufferStream*)b->vfunc_4();
    const float pos[4][3] = {{q.x0, q.y1, 0.5f}, {q.x0, q.y0, 0.5f}, {q.x1, q.y1, 0.5f}, {q.x1, q.y0, 0.5f}};
    for (int i = 0; i < 4; i++) {
        s->vfunc_1(0.0f, 0.0f, nz);
        s->vfunc_0(pos[i][0], pos[i][1], pos[i][2]);
    }
    b->vfunc_5(s);
    static const unsigned short cw[6] = {0, 1, 2, 2, 1, 3}, ccwIdx[6] = {0, 2, 1, 2, 3, 1};
    b->vfunc_9((void*)(ccw ? ccwIdx : cw), 6);
    return b;
}

static void page10(bgfxContext* ctx)
{
    SceneState& S = s_scene;
    Page10& P = s_p10;
    if (!P.made) {
        P.made = true;
        P.twoSided = simpleShader(ctx->m_device, 0);
        if (P.twoSided) {
            setI(P.twoSided, "LIT", 1);
            setI(P.twoSided, "2SID", 1);
            setC(P.twoSided, "DIFF", 0xffffffffu);
            setC(P.twoSided, "AMBI", 0xff000000u);
        }
        for (int k = 0; k < 4; k++)
            P.quads[k] = normalQuad(ctx->m_device, cell(k, 0, 16), k < 2 ? -1.0f : 1.0f, k == 1 || k == 2);
    }
    beginPage(ctx);
    if (!P.twoSided || !S.lit)
        return;
    bgfxContext::Light l;
    memset(&l, 0, sizeof(l));
    for (int i = 1; i < bgfxContext::kLights; i++)
        ctx->hostSetLight(i, l);
    l.type = 3;
    l.on = true;
    l.direction[2] = 1.0f;
    l.range = 1e30f;
    l.att[0] = 1.0f;
    l.diffuse[0] = 0.5f;
    l.diffuse[1] = 0.25f;
    l.diffuse[2] = 1.0f;
    l.diffuse[3] = 1.0f;
    ctx->hostSetLight(0, l);
    static const unsigned kLit = 0x8040ff, kDark = 0x000000;
    static const char* const kWhat[4] = {
        "two-sided: front face, normal toward the light: lit",
        "two-sided: back face, normal toward the light: the reversed normal is unlit",
        "two-sided: back face, normal away: lit through the reversed normal",
        "two-sided: front face, normal away: unlit"};
    for (int k = 0; k < 4; k++) {
        if (!P.quads[k])
            continue;
        ctx->vfunc_32(P.twoSided, P.quads[k]);
        probe(cx(k), cy(0), k == 0 || k == 2 ? kLit : kDark, 3, kWhat[k]);
    }
    // row 1: the same through the one-sided lit shader with culling off by hand: back faces keep the front colours
    ctx->vfunc_54(0);
    static const char* const kWhat1[2] = {"one-sided lighting, back face, normal toward the light: lit as the front",
                                          "one-sided lighting, back face, normal away: unlit"};
    for (int k = 1; k <= 2; k++) {
        if (!P.quads[k])
            continue;
        float I[16];
        identity(I);
        I[13] = -2.0f / 3.0f;                 // one row down (the base's matrix stack 0: the draw loads it)
        ctx->vfunc_14(0, I);
        ctx->vfunc_32(S.lit, P.quads[k]);
        probe(cx(k), cy(1), k == 1 ? kLit : kDark, 3, kWhat1[k - 1]);
    }
}

} // namespace pddi
} // namespace hulk
