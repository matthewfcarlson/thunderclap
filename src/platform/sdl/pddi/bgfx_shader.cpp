// The shader classes: bgfxShader (d3dShader) and the kinds the game's data uses (docs/graphics-backend.md 2).
//
// Parameters: the engine sets a shader's parameters by four-character key through pddiBaseShader's slots 5-10
// (textures, ints, floats, colours, vectors, matrices: portable code in the tree), which walk the key -> setter table
// the class returns from slots 15-20 and call the setter, thiscall with the value, on this + offset. The game's
// classes fill their tables at start-up with d3dShader's setters (FUN_00361a90 ...); ours are static tables of our
// own setters with the same keys per kind (the keys are the game's parameter names, read off its tables).
#include "bgfx_pddi.h"

#include <string.h>

#if HULK_PDDI_GAME
#define PDDI_THISCALL __thiscall
#else
#define PDDI_THISCALL
#endif

namespace hulk {
namespace pddi {

// The key as the game stores it: the name's characters in memory order ("TEX" -> 'T','E','X',0)
static constexpr uint32_t K(const char* s)
{
    return (uint32_t)(unsigned char)s[0] | (uint32_t)(unsigned char)s[1] << 8 | (uint32_t)(unsigned char)s[2] << 16 |
           (s[2] ? (uint32_t)(unsigned char)s[3] << 24 : 0u);
}

typedef bgfxShader S;
static void PDDI_THISCALL setTex(S* s, bgfxObject* t) { s->setTexture(0, t); }
static void PDDI_THISCALL setTex2(S* s, bgfxObject* t) { s->setTexture(1, t); }
static void PDDI_THISCALL setRefl(S* s, bgfxObject* t) { s->setTexture(2, t); }
// d3dShader's setters (0x3333a0.., 0x333770..): the ones that change what the fade derives call FUN_003335e0
static void PDDI_THISCALL setBlend(S* s, int v) { s->m_blendMode = v; s->fade(); }                 // 0x333770
static void PDDI_THISCALL setAlphaTest(S* s, int v) { s->m_alphaTest = v != 0; }                   // 0x3333a0
static void PDDI_THISCALL setAlphaCompare(S* s, int v) { s->m_alphaCompare = v; }                  // 0x3333b0
static void PDDI_THISCALL setUvMode(S* s, int v) { s->m_uvMode = v; }                              // 0x3333c0
static void PDDI_THISCALL setFilter(S* s, int v) { s->m_filter = v; }                              // 0x3333e0
static void PDDI_THISCALL setShade(S* s, int v) { s->m_shadeMode = v; }                            // 0x3333f0
static void PDDI_THISCALL setLit(S* s, int v) { s->m_lit = v != 0; s->fade(); }                   // 0x3337d0
static void PDDI_THISCALL setTwoSided(S* s, int v) { s->m_twoSided = v != 0; }                     // 0x333400
static void PDDI_THISCALL setAlphaRef(S* s, float v)                                              // 0x333780
{
    s->m_alphaRef = v < 0.0f ? 0.0f : v > 1.0f ? 1.0f : v;
    s->fade();
}
static void PDDI_THISCALL setFade(S* s, float v)                                                  // 0x333830
{
    int f = (int)(v * 255.0f);
    s->m_fade = f < 0 ? 0 : f > 255 ? 255 : f;
    s->fade();
}
static void PDDI_THISCALL setAmbient(S* s, uint32_t v) { s->m_ambient = v; s->fade(); }            // 0x3337f0
static void PDDI_THISCALL setDiffuse(S* s, uint32_t v) { s->m_diffuse = v; s->fade(); }            // 0x333800
static void PDDI_THISCALL setSpecular(S* s, uint32_t v) { s->m_specular = v; s->fade(); }          // 0x333810
static void PDDI_THISCALL setEmissive(S* s, uint32_t v) { s->m_emissive = v; s->fade(); }          // 0x333820
static void PDDI_THISCALL setShininess(S* s, float v) { s->m_shininess = v; }                      // 0x333410
static void PDDI_THISCALL setLayerMode(S* s, int v) { s->m_layerMode = v; }                       // TBLM 0x32da30
static void PDDI_THISCALL setLayerPath(S* s, int v) { s->m_layerPath = v; }                       // CLYR 0x32d8d0
static void PDDI_THISCALL setNoLayer(S* s, int v) { s->m_noLayer = v != 0; }                      // LRSA 0x3327e0
static void PDDI_THISCALL setEnvColour(S* s, uint32_t v) { s->m_envColour = v; }                  // ENVB 0x32c480, REFC
static void PDDI_THISCALL setRefractBlend(S* s, float v) { s->m_refractBlend = v; }               // REFB 0x32eef0
static void PDDI_THISCALL ignoreVector(S*, const void*) {}
static void PDDI_THISCALL ignoreInt(S*, int) {}                // accepted, not used (the CBV programs; G4's)
static void PDDI_THISCALL ignoreFloat(S*, float) {}
static void PDDI_THISCALL ignoreColour(S*, uint32_t) {}

#define P(name, fn) {K(name), 0, (const void*)&fn, 0, {0, 0}}
#define END {0, 0, 0, 0, {0, 0}}
// the parameters every d3dShader kind shares (in the game's order)
#define COMMON_INTS P("UVMD", setUvMode), P("FIMD", setFilter), P("SHMD", setShade), P("LIT", setLit), \
    P("BLMD", setBlend), P("ATST", setAlphaTest), P("ACMP", setAlphaCompare), P("2SID", setTwoSided)
#define COMMON_FLOATS P("SHIN", setShininess), P("ACTH", setAlphaRef), P("FADE", setFade)
#define COMMON_COLOURS P("AMBI", setAmbient), P("DIFF", setDiffuse), P("EMIS", setEmissive), P("SPEC", setSpecular)

static const S::Param kNone[] = {END};
static const S::Param kVectors[] = {P("LITV", ignoreVector), END};    // the light vector slot 32 passes
static const S::Param kSimpleTex[] = {P("TEX", setTex), END};
static const S::Param kSimpleInt[] = {COMMON_INTS, P("MCBV", ignoreInt), P("CBVP", ignoreInt), P("CBVY", ignoreInt), END};
static const S::Param kSimpleFloat[] = {COMMON_FLOATS, P("CBVV", ignoreFloat), END};
static const S::Param kColours[] = {COMMON_COLOURS, END};
static const S::Param kLayeredTex[] = {P("TEX", setTex), P("TTEX", setTex2), END};
static const S::Param kLayeredInt[] = {COMMON_INTS, P("TBLM", setLayerMode), P("CLYR", setLayerPath),
                                       P("MCBV", ignoreInt), P("CBVP", ignoreInt), P("CBVY", ignoreInt), END};
static const S::Param kBuildingTex[] = {P("TEX", setTex), P("TTEX", setTex2), P("REFL", setRefl), END};
static const S::Param kBuildingInt[] = {COMMON_INTS, P("LRSA", setNoLayer), END};
static const S::Param kCommonInt[] = {COMMON_INTS, END};
static const S::Param kCommonFloat[] = {COMMON_FLOATS, END};
static const S::Param kReflTex[] = {P("TEX", setTex), P("REFL", setRefl), END};
static const S::Param kReflColours[] = {COMMON_COLOURS, P("ENVB", setEnvColour), END};
static const S::Param kRefractFloat[] = {COMMON_FLOATS, P("REFI", ignoreFloat), P("REFB", setRefractBlend), END};
static const S::Param kRefractColours[] = {COMMON_COLOURS, P("REFC", setEnvColour), END};
static const S::Param kFBInt[] = {P("CLRE", ignoreInt), P("UPDT", ignoreInt), END};
static const S::Param kFBFloat[] = {P("SAT", ignoreFloat), P("BRIT", ignoreFloat), P("MDPT", ignoreFloat), P("CONT", ignoreFloat), END};
static const S::Param kFBColours[] = {P("TINT", ignoreColour), END};
#undef P
#undef END

// The d3dShader constructor's defaults (0x333520): ACMP 5 (gequal), ACTH 0.5, UVMD 1 (clamp), FIMD 1 (linear),
// SHMD 1 (gouraud), DIFF/SPEC/EMIS opaque black, AMBI white.
bgfxShader::bgfxShader(bgfxContext* context)
    : m_context(context), m_kind(kShaderError), m_name("error"), m_blendMode(0), m_activeMode(0), m_alphaTest(false),
      m_alphaCompare(5), m_alphaRef(0.5f), m_alphaRefFaded(0.5f), m_fade(0), m_uvMode(1), m_filter(1), m_lit(false),
      m_shadeMode(1), m_shininess(0.0f), m_diffuse(0xff000000u), m_specular(0xff000000u), m_ambient(0xffffffffu),
      m_emissive(0xff000000u), m_savedFog(0), m_twoSided(false), m_skinned(false), m_layerMode(4), m_layerPath(0),
      m_noLayer(false), m_envColour(0), m_refractBlend(0.0f), m_savedMode(0), m_savedAlphaTest(false)
{
    m_base[0] = m_base[1] = 0;
    for (int i = 0; i < 6; i++)
        m_tables[i] = 0;
    for (int i = 0; i < 3; i++)
        m_texture[i] = 0;
    fade();
}

bgfxShader::~bgfxShader()
{
    shaderDestroyed(this);
    for (int i = 0; i < 3; i++)
        setTexture(i, 0);
}

void bgfxShader::setTexture(int which, bgfxObject* t)
{
    if (t)
        t->vfunc_0();                         // AddRef
    if (m_texture[which])
        m_texture[which]->vfunc_1();          // Release
    m_texture[which] = t;
}

bool bgfxShader::setParam(int table, uint32_t key, const void* value)
{
    if (table < 0 || table > 3 || !m_tables[table])
        return false;
    for (const Param* p = m_tables[table]; p->key; p++) {
        if (p->key != key)
            continue;
        switch (table) {
        case 0: ((void(PDDI_THISCALL*)(S*, bgfxObject*))p->setter)(this, *(bgfxObject* const*)value); break;
        case 1: ((void(PDDI_THISCALL*)(S*, int))p->setter)(this, *(const int*)value); break;
        case 2: ((void(PDDI_THISCALL*)(S*, float))p->setter)(this, *(const float*)value); break;
        default: ((void(PDDI_THISCALL*)(S*, uint32_t))p->setter)(this, *(const uint32_t*)value); break;
        }
        return true;
    }
    return false;
}

// FUN_0031c680: a D3DCOLOR moved toward another by weight / 255, per byte (>> 8)
static uint32_t towards(uint32_t from, uint32_t to, int weight)
{
    if (weight <= 0)
        return from;
    if (weight >= 255)
        return to;
    uint32_t a = 255 - (uint32_t)weight, b = (uint32_t)weight, r = 0;
    for (unsigned sh = 0; sh < 32; sh += 8)
        r |= ((((from >> sh) & 255) * a + ((to >> sh) & 255) * b) >> 8) << sh;
    return r;
}

// FUN_003335e0: what the fade (FADE, 0..255 faded out) derives. The mode the blend uses (alpha when BLMD is none
// and the shader fades), the alpha reference scaled by what is left, and the lit material: alpha modes scale the
// diffuse alpha, add/subtract fade every colour to black, modulate the emissive to white.
void bgfxShader::fade()
{
    int a0 = m_fade, inverse = 255 - a0;
    m_activeMode = (m_blendMode == 0 && a0 > 0) ? 1 : m_blendMode;
    float v = (float)inverse * 0.0039215688593685627f * m_alphaRef;
    if (!(v >= 0.0f && v <= 1.0f))
        v = v > 1.0f ? 1.0f : 0.0f;
    m_alphaRefFaded = v;
    m_matFaded[0] = m_diffuse;
    m_matFaded[1] = m_specular;
    m_matFaded[2] = m_ambient;
    m_matFaded[3] = m_emissive;
    if (!m_lit)
        return;
    switch (m_activeMode) {
    case 1:
    case 7:
        m_matFaded[0] = (m_matFaded[0] & 0xffffffu) | ((((m_matFaded[0] >> 24) * (uint32_t)inverse) << 16) & 0xff000000u);
        break;
    case 2:
    case 3:
        m_matFaded[2] = towards(m_ambient, 0xff000000u, a0);
        m_matFaded[0] = towards(m_diffuse, 0xff000000u, a0);
        m_matFaded[1] = towards(m_specular, 0xff000000u, a0);
        m_matFaded[3] = towards(m_emissive, 0xff000000u, a0);
        break;
    case 4:
    case 5:
        m_matFaded[3] = towards(m_emissive, 0xffffffffu, a0);
        break;
    }
}

// FUN_0032a260: blending from the mode (0x4d4e50: enable, operation, source and destination factor per pddi blend
// mode: none; alpha; add one+one; subtract (reverse); modulate dst*0; modulate2x dst*src; dst + src alpha; reverse
// subtract by src alpha), then the alpha test (ATST, ACMP) with the faded reference
void bgfxShader::applyBlendAndTest()
{
    static const int kBlend[8][4] = {{0, 0x8006, 1, 0}, {1, 0x8006, 6, 7}, {1, 0x8006, 1, 1}, {1, 0x800b, 1, 1},
                                     {1, 0x8006, 4, 0}, {1, 0x8006, 4, 2}, {1, 0x8006, 4, 6}, {1, 0x800b, 6, 6}};
    const int* e = kBlend[(unsigned)m_activeMode < 8 ? m_activeMode : 0];
    m_context->alphaBlend(e[0] != 0, (uint32_t)e[1], e[2], e[3]);
    m_context->alphaTest(m_alphaTest, m_alphaCompare, 0);
    m_context->m_d3d.alphaRef = (uint32_t)(int)(m_alphaRefFaded * 255.0f);
}

// The fade as a texture stage (unlit shaders; lit ones fade through the material): the simple and layered shaders'
// common block. Alpha modes scale the alpha by the texture factor's (255 - fade), add/subtract the colour by
// (255 - fade), modulate by the fade. Returns the next free stage.
static int fadeStage(bgfxShader* s, int n)
{
    bgfxContext* c = s->m_context;
    if (s->m_lit || !s->m_fade)
        return n;
    uint32_t v = (uint32_t)s->m_fade;
    switch (s->m_activeMode) {
    case 1:
    case 7:
        c->stageColour(n, 2, 1);
        c->setTextureFactor((0xffffffffu - v) << 24);
        c->stageAlpha(n, 4, 1, 3);
        break;
    case 2:
    case 3: {
        uint32_t a = 0xff - v;
        c->setTextureFactor((((a << 8) | a) << 8) | a);
        c->stageColour(n, 4, 1, 3);
        c->stageAlpha(n, 2, 1);
        break;
    }
    case 4:
    case 5:
        c->setTextureFactor((((v << 8) | v) << 8) | v);
        c->stageColour(n, 4, 1, 3);
        c->stageAlpha(n, 2, 1);
        break;
    default:
        return n;
    }
    c->stageTexture(n, 0);
    c->stageCoords(n, (uint32_t)n, 0, s->m_uvMode, s->m_filter);
    return n + 1;
}

// ---- bgfxShader slots
const char* bgfxShader::vfunc_4() { return m_name; }
bool bgfxShader::vfunc_5(int a0, int a1) { PDDI_BASE(5, FUN_003279e0(a0, a1)); }
bool bgfxShader::vfunc_6(int a0, int a1) { PDDI_BASE(6, FUN_00327a40(a0, a1)); }
unsigned char bgfxShader::vfunc_7(int a0, int a1) { PDDI_BASE(7, FUN_00327aa0(a0, a1)); }
bool bgfxShader::vfunc_8(int a0, int a1) { PDDI_BASE(8, FUN_00327b00(a0, a1)); }
bool bgfxShader::vfunc_9(int a0, int a1) { PDDI_BASE(9, FUN_00327b60(a0, a1)); }
bool bgfxShader::vfunc_10(int a0, int a1) { PDDI_BASE(10, FUN_00327bc0(a0, a1)); }
// slot 11: passes (every kind the data uses draws in one)
int bgfxShader::vfunc_11() { return 1; }
// slots 12/13 (0x333420, 0x3334a0): activate / deactivate. With the additive mode and fog on, the fog colour is put
// aside and fogging goes to black while the shader is active (context slots 79-81: fog enabled, set, get)
void bgfxShader::vfunc_12()
{
    if (m_activeMode == 2 && m_context->vfunc_79()) {
        int start, end;
        m_context->vfunc_81(&m_savedFog, &start, &end);
        m_context->vfunc_80((int)0xff000000u, start, end);
    }
}
void bgfxShader::vfunc_13()
{
    if (m_activeMode == 2 && m_context->vfunc_79()) {
        uint32_t colour;
        int start, end;
        m_context->vfunc_81(&colour, &start, &end);
        if (colour == 0xff000000u)
            m_context->vfunc_80((int)m_savedFog, start, end);
    }
}
// slot 14: set up pass n (pure in d3dShader; each kind's own below)
void bgfxShader::vfunc_14(int) {}
const void* bgfxShader::vfunc_15() { return m_tables[0]; }
const void* bgfxShader::vfunc_16() { return m_tables[1]; }
const void* bgfxShader::vfunc_17() { return m_tables[2]; }
const void* bgfxShader::vfunc_18() { return m_tables[3]; }
const void* bgfxShader::vfunc_19() { return m_tables[4]; }
const void* bgfxShader::vfunc_20() { return m_tables[5]; }
// slot 21 (0x333370): the (faded) material, as FUN_00324270 reads it
void bgfxShader::vfunc_21(void* out)
{
    ShaderMaterial* m = (ShaderMaterial*)out;
    m->diffuse = m_matFaded[0];
    m->specular = m_matFaded[1];
    m->ambient = m_matFaded[2];
    m->emissive = m_matFaded[3];
    memcpy(&m->shininessBits, &m_shininess, 4);
}
// slots 22-24 (0x3286b0..): uses a vertex program with constants of its own (no), its program name (none: fixed
// function), upload them (nothing)
bool bgfxShader::vfunc_22() { return false; }
void* bgfxShader::vfunc_23() { return (void*)""; }
void bgfxShader::vfunc_24() {}

static void tables(bgfxShader* s, const S::Param* tex, const S::Param* ints, const S::Param* floats, const S::Param* colours)
{
    s->m_tables[0] = tex;
    s->m_tables[1] = ints;
    s->m_tables[2] = floats;
    s->m_tables[3] = colours;
    s->m_tables[4] = kVectors;
    s->m_tables[5] = kNone;
}

// What every kind's pass ends with: the shade mode, lighting and material (FUN_00329f70)
static void finishPass(bgfxShader* s)
{
    s->m_context->setShadeMode(s->m_shadeMode);
    s->m_context->lightingMaterial(s->m_lit, s->m_twoSided, s->m_matFaded, s->m_shininess);
}

// The sphere map the reflective kinds' activation loads into a texture matrix stack (slot 15 push, slot 14 load:
// the base then hands it to slot 108 -> D3DTS_TEXTUREn): the camera-space reflection vector's x, y to 0..1
static void pushSphereMatrix(bgfxContext* c, int stack)
{
    static const float m[16] = {0.5f, 0, 0, 0, 0, 0.5f, 0, 0, 0, 0, 1.0f, 0, 0.5f, 0.5f, 0, 1.0f};
    c->vfunc_15(stack);
    c->vfunc_14(stack, (void*)m);
}

// ---- bgfxSimpleShader (d3dSimpleShader)
bgfxSimpleShader::bgfxSimpleShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderSimple;
    m_name = "simple";
    tables(this, kSimpleTex, kSimpleInt, kSimpleFloat, kColours);
}
int bgfxSimpleShader::vfunc_11() { return 1; }
// 0x32aa70: stage 0 the texture modulated by the diffuse colour (when there is one), the fade stage, the rest off
void bgfxSimpleShader::vfunc_14(int)
{
    bgfxContext* c = m_context;
    int n = 0;
    if (m_texture[0]) {
        c->stageBoth(0, 4, 0, 2);
        c->stageCoords(0, 0, 0, m_uvMode, m_filter);
        n = 1;
    }
    n = fadeStage(this, n);
    c->stageTexture(0, m_texture[0]);
    for (int i = 1; i < 4; i++)
        c->stageTexture(i, 0);
    c->stageDisable(n);
    finishPass(this);
    applyBlendAndTest();
}
void bgfxSimpleShader::vfunc_21(void* a0) { bgfxShader::vfunc_21(a0); }
bool bgfxSimpleShader::vfunc_22() { return false; }
void* bgfxSimpleShader::vfunc_23() { return (void*)""; }
void bgfxSimpleShader::vfunc_24() {}

// ---- bgfxLayeredShader (d3dLayeredShader)
bgfxLayeredShader::bgfxLayeredShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderLayered;
    m_name = "layered";
    tables(this, kLayeredTex, kLayeredInt, kSimpleFloat, kColours);
}
int bgfxLayeredShader::vfunc_11() { return 1; }
// FUN_0032da40: the layer's blend mode (TBLM, a pddi blend mode) as a texture-stage operation: none -> select
// current, alpha -> blendtexturealpha, add, subtract, modulate (and the default), modulate2x, modulatealpha_addcolor
static uint32_t layerOp(int mode)
{
    switch (mode) {
    case 0: return 2;
    case 1: return 14;
    case 2: return 7;
    case 3: return 10;
    case 5: return 5;
    case 6: return 18;
    default: return 4;
    }
}
// the layer stage: TTEX by the layer op over what is below (alpha layer: the current alpha stays)
static void layerStage(bgfxLayeredShader* s, int stage)
{
    bgfxContext* c = s->m_context;
    int m = s->m_layerMode;
    if (m == 1) {
        c->stageBoth(stage, layerOp(m), 2, (uint32_t)m);
        c->stageAlpha(stage, 2, 1);
    } else {
        c->stageBoth(stage, layerOp(m), 1, 2);
    }
    c->stageTexture(stage, s->m_texture[1]);
}
// 0x32dc40. CLYR picks one of three stage set-ups: 0 TEX, the layer over it, then the diffuse colour; 1 the diffuse
// colour times TEX (when there is one), the layer over it; else TTEX, TEX blended with it by the diffuse alpha
// (blenddiffusealpha), then the diffuse colour. Then the fade stage; the sub-modulate-alpha layer (TBLM 7) turns
// its stage into a subtraction with its own blending (and leaves the shader's blend and alpha test as they were).
void bgfxLayeredShader::vfunc_14(int)
{
    bgfxContext* c = m_context;
    int stage = 0, last = -1;
    int p = m_layerPath;
    if (p == 0) {
        c->stageBoth(0, 3, 1, 2);
        c->stageTexture(0, m_texture[0]);
        c->stageCoords(0, 0, 0, m_uvMode, m_filter);
        layerStage(this, 1);
        c->stageCoords(1, 1, 0, m_uvMode, m_filter);
        last = 1;
        c->stageBoth(2, 4, 0, 1);
    } else if (p == 1) {
        c->stageTextures(0, m_texture[0], m_texture[1], 0, 0);
        if (m_texture[0]) {
            c->stageBoth(0, 4, 0, 2);
            c->stageTexture(0, m_texture[0]);
            c->stageCoords(0, 0, 0, m_uvMode, m_filter);
            stage = 1;
        }
        layerStage(this, stage);
        c->stageCoords(stage, 1, 0, m_uvMode, m_filter);
        last = stage;
        stage++;
    } else {
        c->stageBoth(0, 3, 1, 2);
        c->stageTexture(0, m_texture[1]);
        c->stageCoords(0, 1, 0, m_uvMode, m_filter);
        c->stageBoth(1, 12, 1, 2);
        c->stageTexture(1, m_texture[0]);
        c->stageCoords(1, 0, 0, m_uvMode, m_filter);
        c->stageColour(2, 4, 0, 1);
        c->stageAlpha(2, 2, 1);
    }
    if (p != 1) {
        c->stageTexture(2, 0);
        c->stageCoords(2, 2, 0, m_uvMode, m_filter);
        stage = 3;
    }
    stage = fadeStage(this, stage);
    c->stageDisable(stage);
    finishPass(this);
    if (m_layerMode == 7 && last != -1) {
        c->stageColour(last, 10, 1, 2);
        c->stageAlpha(last, 3, 1, 2);
        c->alphaBlend(true, 0x8006, 6, 0);
        return;
    }
    applyBlendAndTest();
}
bool bgfxLayeredShader::vfunc_22() { return false; }
void* bgfxLayeredShader::vfunc_23() { return (void*)""; }
void bgfxLayeredShader::vfunc_24() {}

// ---- bgfxBuildingShader (d3dBuildingShader, "layeredReflect")
bgfxBuildingShader::bgfxBuildingShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderBuilding;
    m_name = "layeredReflect";
    tables(this, kBuildingTex, kBuildingInt, kCommonFloat, kColours);
}
int bgfxBuildingShader::vfunc_11() { return 1; }
// 0x332620 / 0x3326d0: the sphere map in texture matrix stack 3 (D3DTS_TEXTURE2) while active; deactivating puts
// stage 0's result back in current and stage 2's coordinates back to its own set, untransformed
void bgfxBuildingShader::vfunc_12() { pushSphereMatrix(m_context, 3); }
void bgfxBuildingShader::vfunc_13()
{
    bgfxContext* c = m_context;
    c->m_d3d.stage[0].resultArg = 1;
    c->m_d3d.stage[2].texCoordIndex = 2;
    c->m_d3d.stage[2].transformFlags = 0;
    c->vfunc_16(3);
}
// 0x332310: TEX times the diffuse colour (its own alpha), TTEX added where that is not opaque
// (modulateinvalpha_addcolor; LRSA leaves it out), the reflection (REFL through the camera-space reflection vector
// and the sphere map, clamped) added the same way, then the fade stage (alpha modes: the factor's alpha replaces)
void bgfxBuildingShader::vfunc_14(int)
{
    bgfxContext* c = m_context;
    int stage = 0;
    if (m_texture[0]) {
        c->stageColour(0, 4, 0, 2);
        c->stageAlpha(0, 2, 2);
        c->stageTexture(0, m_texture[0]);
        c->stageCoords(0, 0, 0, m_uvMode, m_filter);
        stage = 1;
    }
    if (m_texture[1] && !m_noLayer) {
        c->stageColour(stage, 20, 1, 2);
        c->stageAlpha(stage, 2, 1);
        c->stageTexture(stage, m_texture[1]);
        c->stageCoords(stage, (uint32_t)stage, 0, m_uvMode, m_filter);
        ++stage;
    }
    if (m_texture[2]) {
        c->stageColour(stage, 20, 1, 2);
        c->stageAlpha(stage, 2, 1);
        c->stageTexture(stage, m_texture[2]);
        c->m_d3d.stage[stage].texCoordIndex = 0x30000;
        c->m_d3d.stage[stage].transformFlags = 2;
        c->stageAddress(stage, 1);
        c->stageFilter(stage, m_filter);
        ++stage;
    }
    int e = m_activeMode;
    if (!m_lit && m_fade && e >= 1 && e <= 7 && e != 6) {
        uint32_t v = (uint32_t)m_fade;
        if (e == 1 || e == 7) {
            c->stageColour(stage, 2, 1);
            c->setTextureFactor((0xffffffffu - v) << 24);
            c->stageAlpha(stage, 2, 3);
        } else {
            uint32_t x = (e == 2 || e == 3) ? 255 - v : v;
            c->setTextureFactor((x << 16) | (x << 8) | x);
            c->stageColour(stage, 4, 1, 3);
            c->stageAlpha(stage, 2, 1);
        }
        c->stageTexture(stage, 0);
        c->stageCoords(stage, (uint32_t)stage, 0, m_uvMode, m_filter);
        ++stage;
    }
    c->stageDisable(stage);
    finishPass(this);
    applyBlendAndTest();
}
void* bgfxBuildingShader::vfunc_23() { return (void*)""; }

// ---- bgfxReflShader (d3dReflShader, "environment")
bgfxReflShader::bgfxReflShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderRefl;
    m_name = "environment";
    tables(this, kReflTex, kCommonInt, kCommonFloat, kReflColours);
}
int bgfxReflShader::vfunc_11() { return 1; }
// 0x32c300 / 0x32c3b0: the sphere map in stack 2 (D3DTS_TEXTURE1) while active; deactivating restores stage 0's
// result register and stage 1's coordinates
void bgfxReflShader::vfunc_12() { pushSphereMatrix(m_context, 2); }
void bgfxReflShader::vfunc_13()
{
    bgfxContext* c = m_context;
    c->m_d3d.stage[0].resultArg = 1;
    c->m_d3d.stage[1].texCoordIndex = 1;
    c->m_d3d.stage[1].transformFlags = 0;
    c->vfunc_16(2);
}
// 0x32c520: stage 0 TEX times the diffuse colour into temp; stage 1 the reflection map (camera-space reflection
// vector through the sphere map, clamped) times the factor (ENVB, its alpha faded); stage 2 temp + temp's alpha x
// the reflection (modulatealpha_addcolor), the factor's alpha
void bgfxReflShader::vfunc_14(int)
{
    bgfxContext* c = m_context;
    uint32_t col = m_envColour, a = (uint32_t)m_fade;
    uint32_t t1 = (0xff - a) * ((col >> 8) & 0xffff0000u);
    uint32_t t2 = (0xff - a) * ((col >> 8) & 0xff0000u);
    c->setTextureFactor(((t1 ^ col) & 0xffffffu) ^ t2);
    c->stageBoth(0, 4, 0, 2);
    c->m_d3d.stage[0].resultArg = 5;
    c->stageCoords(0, 0, 0, m_uvMode, m_filter);
    c->stageBoth(1, 4, 3, 2);
    c->m_d3d.stage[1].texCoordIndex = 0x30000;
    c->m_d3d.stage[1].transformFlags = 2;
    c->stageAddress(1, 1);
    c->stageFilter(1, m_filter);
    c->stageColour(2, 18, 5, 1);
    c->stageAlpha(2, 3, 1, 3);
    c->stageTextures(3, m_texture[0], m_texture[2], 0, 0);
    finishPass(this);
    applyBlendAndTest();
}

// ---- bgfxRefractShader (d3dRefractVertexShader)
bgfxRefractShader::bgfxRefractShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderRefract;
    m_name = "refract";
    tables(this, kSimpleTex, kCommonInt, kRefractFloat, kRefractColours);
}
int bgfxRefractShader::vfunc_11() { return 1; }
void bgfxRefractShader::vfunc_12() {}                                  // 0x32f270: empty
// 0x32f280: the frame-buffer texture let go, stage 0's result back in current, the mode and alpha test back
void bgfxRefractShader::vfunc_13()
{
    m_context->m_d3d.stage[0].resultArg = 1;
    m_activeMode = m_savedMode;
    m_alphaTest = m_savedAlphaTest;
    applyBlendAndTest();
}
// 0x32efa0: stage 0 a copy of the frame buffer (G4: not made yet, the stage samples white) times the factor (REFC,
// alpha REFB) into temp; stage 1 TEX (times the diffuse colour when lit); stage 2 temp blended over that by the
// factor's alpha (blendfactoralpha), the diffuse alpha. The pass draws alpha-blended without the alpha test.
void bgfxRefractShader::vfunc_14(int)
{
    bgfxContext* c = m_context;
    c->setTextureFactor(((uint32_t)(int)(m_refractBlend * 255.0f) << 24) | (m_envColour & 0xffffffu));
    c->stageBoth(0, 4, 3, 2);
    c->m_d3d.stage[0].texCoordIndex = 0;
    c->m_d3d.stage[0].transformFlags = 0;
    c->stageAddress(0, 1);
    c->stageFilter(0, m_filter);
    c->m_d3d.stage[0].resultArg = 5;
    c->stageTexture(0, 0);
    c->stageBoth(1, m_lit ? 4 : 3, 0, 2);
    c->stageTexture(1, m_texture[0]);
    c->stageCoords(1, 1, 0, m_uvMode, m_filter);
    c->stageColour(2, 15, 5, 1);
    c->stageAlpha(2, 2, 0);
    c->stageTexture(2, 0);
    c->stageDisable(3);
    m_savedMode = m_activeMode;
    m_savedAlphaTest = m_alphaTest;
    m_activeMode = 1;
    m_alphaTest = false;
    finishPass(this);
    applyBlendAndTest();
}
bool bgfxRefractShader::vfunc_22() { return false; }
void* bgfxRefractShader::vfunc_23() { return (void*)(m_skinned ? "skin_refract" : "refract"); }   // 0x32f250
void bgfxRefractShader::vfunc_24() {}

// ---- bgfxFBEffectsShader (d3dFBEffectsShader): slots 12-14 are empty in the game (its draws are the
// framebuffer-effects extension's, G4)
bgfxFBEffectsShader::bgfxFBEffectsShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderFBEffects;
    m_name = "fbeffectsshader";
    tables(this, kNone, kFBInt, kFBFloat, kFBColours);
}
int bgfxFBEffectsShader::vfunc_11() { return 1; }
void bgfxFBEffectsShader::vfunc_12() {}
void bgfxFBEffectsShader::vfunc_13() {}
void bgfxFBEffectsShader::vfunc_14(int) {}

// ---- bgfxErrorShader (d3dErrorShader)
bgfxErrorShader::bgfxErrorShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderError;
    m_name = "error";
    tables(this, kNone, kNone, kNone, kNone);
}
int bgfxErrorShader::vfunc_11() { return 1; }
// 0x32b120: no textures, stage 0 off (the diffuse colour as it is), lighting as LIT says; blending and the alpha
// test stay as they were
void bgfxErrorShader::vfunc_14(int)
{
    m_context->stageTextures(0, 0, 0, 0, 0);
    finishPass(this);
}
} // namespace pddi
} // namespace hulk
