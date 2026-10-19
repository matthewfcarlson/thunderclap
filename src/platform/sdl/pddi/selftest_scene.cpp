// The backend's self-test scene (G3): one frame of draws through the same slots the engine uses, laid out as a 4 x 3
// grid of cells, each testing one thing, with the pixel each should produce (probes). The host smoke test
// (smoke/smoke_main.cpp, Metal) and the native image's HULK_GFX_SELFTEST (win32_platform.cpp, under Wine: Vulkan)
// draw it and check a screenshot against the probes.
//
//   row 0: fixed-function triangle (prim stream) | texture through device slot 9 + the simple shader | z test
//          (LEQUAL keeps the nearer quad drawn first) | z compare ALWAYS (the farther quad drawn last wins)
//   row 1: alpha blend (BLMD 1) | additive blend (BLMD 2) | stencil (write 1 with colour writes off, then draw
//          where stencil == 1) | cull (a counter-clockwise quad with pddi cull 1: nothing)
//   row 2: lit prim buffer (indexed, packed normal, one directional light, fixed-function program) | skinned prim
//          buffer through d3dExtHardwareSkinning (slots 5/6: the "skin" vertex program, bones blended 50/50,
//          lit by the skin program's light) | linear fog | colour write mask (red only)
// Everything is in clip space (identity modelview and projection, z in [0, 1]); D3DCOLORs are 0xAARRGGBB.
#include "bgfx_pddi.h"

#include <string.h>

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
};
static SceneState s_scene;
static SelfTestProbe s_probes[24];
static int s_nprobes;

static void probe(int x, int y, unsigned rgb, int tol, const char* what)
{
    if (s_nprobes < 24) {
        SelfTestProbe& p = s_probes[s_nprobes++];
        p.x = x;
        p.y = y;
        p.rgb = rgb & 0xffffff;
        p.tolerance = tol;
        p.what = what;
    }
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

static bgfxShader* simpleShader(bgfxDevice* dev, int blend)
{
    bgfxShader* s = (bgfxShader*)dev->vfunc_11("simple", 0);
    if (s) {
        s->vfunc_0();          // AddRef: the scene keeps it
        s->m_blendMode = blend;
    }
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
    if (S.lit)
        S.lit->m_lit = true;
    if (S.skin)
        S.skin->m_lit = true;
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
        if (S.textured) {
#if HULK_PDDI_GAME
            // TEX through pddiBaseShader's slot 5 (tree code walking our key table), as the engine sets it
            S.textured->vfunc_5(0x584554 /* "TEX" */, (int)(intptr_t)S.texture);
#else
            S.textured->setTexture(0, S.texture);
#endif
        }
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

// One frame of the scene (between the caller's begin frame and end frame). Returns the number of probes.
int selfTestScene(bgfxContext* ctx)
{
    SceneState& S = s_scene;
    S.w = ctx->m_display ? ctx->m_display->m_width : 640;
    S.h = ctx->m_display ? ctx->m_display->m_height : 480;
    if (!S.made)
        setup(ctx);
    s_nprobes = 0;
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

// A screenshot's pixel against the probes: the number that pass (each logged through `out`)
int selfTestCheck(const unsigned char* px, unsigned w, unsigned h, unsigned pitch, bool bgra, bool yflip,
                  void (*out)(const char* line))
{
    int ok = 0;
    for (int i = 0; i < s_nprobes; i++) {
        const SelfTestProbe& p = s_probes[i];
        if (p.x < 0 || p.y < 0 || (unsigned)p.x >= w || (unsigned)p.y >= h)
            continue;
        unsigned row = yflip ? h - 1 - (unsigned)p.y : (unsigned)p.y;
        const unsigned char* c = px + row * pitch + (unsigned)p.x * 4;
        int rgb[3] = {bgra ? c[2] : c[0], c[1], bgra ? c[0] : c[2]};
        int want[3] = {(int)(p.rgb >> 16) & 255, (int)(p.rgb >> 8) & 255, (int)p.rgb & 255};
        bool good = true;
        for (int k = 0; k < 3; k++)
            if (rgb[k] - want[k] > p.tolerance || want[k] - rgb[k] > p.tolerance)
                good = false;
        ok += good;
        if (out) {
            char line[256];
            logLine(line, sizeof(line), "pddi: probe %d,%d %s: %d,%d,%d (want %d,%d,%d) %s\n", p.x, p.y,
                    good ? "ok" : "FAIL", rgb[0], rgb[1], rgb[2], want[0], want[1], want[2], p.what);
            out(line);
        }
    }
    return ok;
}

} // namespace pddi
} // namespace hulk
