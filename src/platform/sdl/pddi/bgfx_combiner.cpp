// The device state the shader classes' pass set-up writes, and the combiner key the draw makes of it (G2).
//
// The game's shaders (d3dSimpleShader, d3dLayeredShader, d3dBuildingShader, d3dReflShader, ...) set up each pass in
// their slot 14 through small helpers of the d3dContext's state cache (FUN_00329bb0..FUN_0032b530 in the tree's
// d3dSimpleShader.cpp / d3dLayeredShader.cpp / d3dErrorShader.cpp): texture-stage colour and alpha operations and
// arguments, the texture factor, stage textures, texture coordinates and addressing, the lighting material, alpha
// blending and the alpha test. They write D3D's texture-stage registers (D3D__TextureState[stage][n] at 0x39db10, 32
// words a stage: n = 0-2 address, 3-5 filter, 12-16 colour op/args, 16-19 alpha op/args, 20 result arg, 21 texture
// transform flags) and render states. Here the same helpers write `bgfxContext::m_d3d` (D3D values, so the ports of
// the shaders read like the game's code), and the draw turns that into a fragment program (the combiner key),
// sampler flags, bgfx blend state and uniforms (bgfx_draw.cpp).
//
// Specification: the verified sources of the helpers (named on each function) and the game's tables they index,
// read from the XBE by address (only their values are used); the D3D operations' meaning: public Direct3D 8
// documentation (the Xbox numbering of D3DTOP differs from the PC's after addsmooth: blendcurrentalpha is 13 and
// the bump-mapping ops come last; the game's own uses confirm it, e.g. the layered alpha layer TBLM 1 -> op 14 with
// arguments (texture, current) is blendtexturealpha).
#include "bgfx_pddi.h"

#include <string.h>

namespace hulk {
namespace pddi {

// the game's tables
static const uint32_t kAddress[2] = {1, 3};                              // 0x4d4efc: UVMD 0 wrap, 1 clamp
static const uint32_t kFilter[5][3] = {{1, 1, 0}, {2, 2, 0}, {1, 1, 1}, {2, 2, 1}, {2, 2, 2}};   // 0x4d4e10: FIMD
static const uint32_t kShade[2] = {0x1d00, 0x1d01};                      // 0x4d4f24: SHMD 0 flat, 1 gouraud
static const uint32_t kBlendFactor[11] = {0, 1, 0x300, 0x301, 0x306, 0x307, 0x302, 0x303, 0x304, 0x305, 0x308};
                                                                         // 0x4d4ed0: pddi blend factor -> D3D
static const uint32_t kCompare[8] = {0x200, 0x207, 0x201, 0x203, 0x204, 0x206, 0x202, 0x205};   // 0x4d4f04: ACMP

void bgfxContext::resetDeviceState()
{
    DeviceState& d = m_d3d;
    memset(&d, 0, sizeof(d));
    for (int i = 0; i < 4; i++) {
        Stage& s = d.stage[i];
        s.colorOp = i == 0 ? 4 : 1;           // D3D: stage 0 modulate (texture, current), select texture alpha
        s.colorArg1 = 2;
        s.colorArg2 = 1;
        s.alphaOp = i == 0 ? 2 : 1;
        s.alphaArg1 = 2;
        s.alphaArg2 = 1;
        s.resultArg = 1;
        s.texCoordIndex = (uint32_t)i;
        s.address = 1;
        s.magFilter = s.minFilter = 1;
    }
    d.textureFactor = 0xffffffffu;
    d.blendOp = 0x8006;
    d.srcBlend = 1;
    d.alphaFunc = 0x207;
    d.shadeMode = 0x1d01;
    d.material[0] = d.material[2] = 0xffffffffu;
    d.material[1] = d.material[3] = 0xff000000u;
    d.cull = m_rs.cull;
}

void bgfxContext::stageDisable(int stage)
{
    if (stage < 0 || stage > 3)
        return;
    m_d3d.stage[stage].colorOp = 1;
    m_d3d.stage[stage].alphaOp = 1;
}
void bgfxContext::stageColour(int stage, uint32_t op, uint32_t arg1)
{
    m_d3d.stage[stage & 3].colorOp = op;
    m_d3d.stage[stage & 3].colorArg1 = arg1;
}
void bgfxContext::stageColour(int stage, uint32_t op, uint32_t arg1, uint32_t arg2)
{
    stageColour(stage, op, arg1);
    m_d3d.stage[stage & 3].colorArg2 = arg2;
}
void bgfxContext::stageAlpha(int stage, uint32_t op, uint32_t arg1)
{
    m_d3d.stage[stage & 3].alphaOp = op;
    m_d3d.stage[stage & 3].alphaArg1 = arg1;
}
void bgfxContext::stageAlpha(int stage, uint32_t op, uint32_t arg1, uint32_t arg2)
{
    stageAlpha(stage, op, arg1);
    m_d3d.stage[stage & 3].alphaArg2 = arg2;
}
void bgfxContext::stageBoth(int stage, uint32_t op, uint32_t arg1, uint32_t arg2)
{
    stageColour(stage, op, arg1, arg2);
    stageAlpha(stage, op, arg1, arg2);
}
void bgfxContext::stageTexture(int stage, bgfxObject* texture)
{
    m_d3d.stage[stage & 3].texture = (bgfxTexture*)texture;
}
// FUN_0032a920: the four stage textures, then the stages from `disableFrom` on disabled (FUN_00329bb0)
void bgfxContext::stageTextures(int disableFrom, bgfxObject* t0, bgfxObject* t1, bgfxObject* t2, bgfxObject* t3)
{
    stageTexture(0, t0);
    stageTexture(1, t1);
    stageTexture(2, t2);
    stageTexture(3, t3);
    stageDisable(disableFrom);
}
void bgfxContext::stageAddress(int stage, int uvMode)
{
    m_d3d.stage[stage & 3].address = kAddress[uvMode == 1 ? 1 : 0];
}
void bgfxContext::stageFilter(int stage, int filterMode)
{
    const uint32_t* f = kFilter[filterMode >= 0 && filterMode < 5 ? filterMode : 1];
    Stage& s = m_d3d.stage[stage & 3];
    s.magFilter = f[0];
    s.minFilter = f[1];
    s.mipFilter = f[2];
}
// FUN_0032a320 (coordinates: the stage's own set) and FUN_0032b530 (a given set): texture coordinate index,
// texture transform flags, addressing from UVMD, filtering from FIMD
void bgfxContext::stageCoords(int stage, uint32_t texCoordIndex, uint32_t transformFlags, int uvMode, int filterMode)
{
    Stage& s = m_d3d.stage[stage & 3];
    s.texCoordIndex = texCoordIndex;
    s.transformFlags = transformFlags;
    stageAddress(stage, uvMode);
    stageFilter(stage, filterMode);
}
void bgfxContext::setTextureFactor(uint32_t c) { m_d3d.textureFactor = c; }
void bgfxContext::setShadeMode(int shmd)
{
    uint32_t v = kShade[shmd == 0 ? 0 : 1];
    if (v == 0x1d00 && m_d3d.shadeMode != v) {
        static bool s_logged;
        if (!s_logged) {
            s_logged = true;
            logf("pddi: flat shading (SHMD 0) asked for: drawn smooth\n");
        }
    }
    m_d3d.shadeMode = v;
}

// FUN_00329f70: lighting on/off with the material, and two-sided drawing. The cache (+0x104 lit, +0x105 two-sided)
// decides what is sent: two-sided turns culling off (and two-sided lighting on when lit); leaving it puts back the
// context's cull mode (FUN_003219c0). Lit: LIGHTING on, SPECULARENABLE when the power is above 0, the material.
void bgfxContext::lightingMaterial(bool lit, bool twoSided, const uint32_t* material, float power)
{
    DeviceState& d = m_d3d;
    if (d.cacheTwoSided != twoSided || d.cacheLit != lit) {
        d.cacheTwoSided = twoSided;
        if (twoSided) {
            d.cull = 0;
            d.twoSidedLighting = lit;
        } else {
            d.twoSidedLighting = false;
            d.cull = m_rs.cull;
        }
    }
    if (d.cacheLit) {
        if (!lit) {
            d.cacheLit = false;
            d.lighting = false;
            d.specular = false;
            return;
        }
    } else if (!lit) {
        return;
    }
    d.cacheLit = true;
    d.lighting = true;
    d.specular = power > 0.0f;
    memcpy(d.material, material, sizeof(d.material));
    d.power = power;
}

// FUN_0032a0c0: alpha blending on/off; when on, the operation (a D3D value) and the factors (pddi -> 0x4d4ed0)
void bgfxContext::alphaBlend(bool enable, uint32_t op, int src, int dst)
{
    m_d3d.blend = enable;
    if (enable) {
        m_d3d.blendOp = op;
        m_d3d.srcBlend = kBlendFactor[src >= 0 && src < 11 ? src : 1];
        m_d3d.dstBlend = kBlendFactor[dst >= 0 && dst < 11 ? dst : 0];
    }
}
// FUN_0032a190: the alpha test on/off; when on, the compare (pddi -> 0x4d4f04) and the reference
void bgfxContext::alphaTest(bool enable, int compare, uint32_t ref)
{
    m_d3d.alphaTest = enable;
    if (enable) {
        m_d3d.alphaFunc = kCompare[compare & 7];
        m_d3d.alphaRef = ref;
    }
}

// ---------------------------------------------------------------------------------------------
// The combiner key: the active stages (up to the first whose colour op is disable), each as its colour op and the
// arguments the op reads, its alpha op and arguments and its result register. Arguments an op doesn't read are 0,
// so equal combiners give equal keys. "-" when stage 0 is disabled (the diffuse colour passes through).
static bool readsArg1(uint32_t op) { return op != 1 && op != 3; }
static bool readsArg2(uint32_t op) { return op != 1 && op != 2; }

struct KeyWriter {
    char* out;
    int size, len;
    bool ok;
    void ch(char c)
    {
        if (len + 1 < size)
            out[len++] = c;
        else
            ok = false;
        out[len < size ? len : size - 1] = 0;
    }
    void num(uint32_t v)
    {
        char t[12];
        int n = 0;
        do {
            t[n++] = (char)('0' + v % 10);
            v /= 10;
        } while (v);
        while (n)
            ch(t[--n]);
    }
};

int bgfxContext::combinerKey(const DeviceState& d, char* out, int size)
{
    KeyWriter w = {out, size, 0, true};
    out[0] = 0;
    int n = 0;
    for (int i = 0; i < 4; i++) {
        const Stage& s = d.stage[i];
        if (s.colorOp <= 1 || s.colorOp > 26)
            break;
        bool alphaOff = s.alphaOp <= 1 || s.alphaOp > 26;
        uint32_t aop = alphaOff ? 2 : s.alphaOp;         // alpha disabled: the current alpha passes on
        uint32_t aa1 = alphaOff ? 1 : s.alphaArg1;
        if (i)
            w.ch('|');
        w.ch('c');
        w.num(s.colorOp);
        w.ch('.');
        w.num(readsArg1(s.colorOp) ? s.colorArg1 : 0);
        w.ch('.');
        w.num(readsArg2(s.colorOp) ? s.colorArg2 : 0);
        w.ch('a');
        w.num(aop);
        w.ch('.');
        w.num(readsArg1(aop) ? aa1 : 0);
        w.ch('.');
        w.num(readsArg2(aop) && !alphaOff ? s.alphaArg2 : 0);
        w.ch('r');
        w.num(s.resultArg == 5 ? 5u : 1u);
        n++;
    }
    if (!n)
        w.ch('-');
    return w.ok ? n : -1;
}

uint32_t bgfxContext::combinerHash(const char* key)
{
    uint32_t h = 2166136261u;
    for (const unsigned char* p = (const unsigned char*)key; *p; p++)
        h = (h ^ *p) * 16777619u;
    return h;
}

} // namespace pddi
} // namespace hulk

namespace hulk {
namespace pddi {

// ---------------------------------------------------------------------------------------------
// Every combiner key the shader classes' pass set-up can produce, found by running it (vfunc_12, 14, 13: what
// beginPass does) over each class's parameters that change the stages: the textures present, LIT, BLMD, a fade,
// and each kind's own (TBLM, CLYR, LRSA). `out` gets each new key with the first set-up that made it.
// tools/native_gfx.py combiners writes them to shaders/vp/combiners.txt (one generated program per key).
static void keyOf(bgfxContext* ctx, bgfxShader* sh, const char* what, void (*out)(const char*, const char*),
                  char (*seen)[160], int* nseen, int maxSeen)
{
    ctx->resetDeviceState();
    sh->vfunc_12();
    sh->vfunc_14(0);
    char key[160];
    bgfxContext::combinerKey(ctx->m_d3d, key, sizeof(key));
    sh->vfunc_13();
    for (int i = 0; i < *nseen; i++)
        if (!strcmp(seen[i], key))
            return;
    if (*nseen < maxSeen)
        memcpy(seen[(*nseen)++], key, sizeof(key));
    out(key, what);
}

static uint32_t key4(const char* s)
{
    return (uint32_t)(unsigned char)s[0] | (uint32_t)(unsigned char)s[1] << 8 | (uint32_t)(unsigned char)s[2] << 16 |
           (s[2] ? (uint32_t)(unsigned char)s[3] << 24 : 0u);
}
static void setI(bgfxShader* s, const char* k, int v) { s->setParam(1, key4(k), &v); }
static void setF(bgfxShader* s, const char* k, float v) { s->setParam(2, key4(k), &v); }
static void setT(bgfxShader* s, const char* k, bgfxObject* t) { s->setParam(0, key4(k), &t); }

static void describe(char* buf, int size, const char* kind, int mask, const char* const* texNames, int nTex,
                     int lit, int blend, int fade, const char* extra)
{
    int n = 0;
    for (const char* p = kind; *p && n < size - 1; p++)
        buf[n++] = *p;
    for (int t = 0; t < nTex; t++) {
        if (!(mask & (1 << t)))
            continue;
        if (n < size - 1)
            buf[n++] = ' ';
        for (const char* p = texNames[t]; *p && n < size - 1; p++)
            buf[n++] = *p;
    }
    buf[n] = 0;
    char tail[64];
    logLine(tail, sizeof(tail), " LIT %d BLMD %d%s%s", lit, blend, fade ? " FADE 0.5" : "", extra ? extra : "");
    for (const char* p = tail; *p && n < size - 1; p++)
        buf[n++] = *p;
    buf[n] = 0;
}

int enumerateCombinerKeys(bgfxContext* ctx, void (*out)(const char* key, const char* example))
{
    static char seen[512][160];
    int nseen = 0;
    bgfxTexture* tex[3] = {new bgfxTexture(ctx), new bgfxTexture(ctx), new bgfxTexture(ctx)};
    for (int i = 0; i < 3; i++)
        tex[i]->vfunc_0();
    char what[160];
    struct Kind {
        const char* name;
        const char* tex[3];
        int nTex;
    };
    static const Kind kKinds[] = {          // each kind's texture keys
        {"error", {0, 0, 0}, 0},
        {"simple", {"TEX", 0, 0}, 1},
        {"layered", {"TEX", "TTEX", 0}, 2},
        {"layeredReflect", {"TEX", "TTEX", "REFL"}, 3},
        {"environment", {"TEX", "REFL", 0}, 2},
        {"refract", {"TEX", 0, 0}, 1},
    };
    for (unsigned k = 0; k < sizeof(kKinds) / sizeof(kKinds[0]); k++) {
        const Kind& K = kKinds[k];
        bgfxShader* sh = ctx->m_device->newShader(K.name);
        sh->vfunc_0();
        int extraN = !strcmp(K.name, "layered") ? 8 * 3 : !strcmp(K.name, "layeredReflect") ? 2 : 1;
        for (int mask = 0; mask < (1 << K.nTex); mask++)
            for (int lit = 0; lit < 2; lit++)
                for (int blend = 0; blend < 8; blend++)
                    for (int fade = 0; fade < 2; fade++)
                        for (int x = 0; x < extraN; x++) {
                            for (int t = 0; t < K.nTex; t++)
                                setT(sh, K.tex[t], (mask & (1 << t)) ? tex[t] : 0);
                            setI(sh, "LIT", lit);
                            setI(sh, "BLMD", blend);
                            setF(sh, "FADE", fade ? 0.5f : 0.0f);
                            char extra[48] = "";
                            if (!strcmp(K.name, "layered")) {
                                setI(sh, "TBLM", x % 8);
                                setI(sh, "CLYR", x / 8);
                                logLine(extra, sizeof(extra), " TBLM %d CLYR %d", x % 8, x / 8);
                            } else if (!strcmp(K.name, "layeredReflect")) {
                                setI(sh, "LRSA", x);
                                logLine(extra, sizeof(extra), " LRSA %d", x);
                            }
                            describe(what, sizeof(what), K.name, mask, K.tex, K.nTex, lit, blend, fade, extra);
                            keyOf(ctx, sh, what, out, seen, &nseen, 512);
                        }
        for (int t = 0; t < K.nTex; t++)
            setT(sh, K.tex[t], 0);
        sh->vfunc_1();
    }
    for (int i = 0; i < 3; i++)
        tex[i]->vfunc_1();
    ctx->resetDeviceState();
    return nseen;
}

} // namespace pddi
} // namespace hulk
