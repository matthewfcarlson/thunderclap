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
static void PDDI_THISCALL setBlend(S* s, int v) { s->m_blendMode = v; }
static void PDDI_THISCALL setAlphaTest(S* s, int v) { s->m_alphaTest = v != 0; }
static void PDDI_THISCALL setAlphaCompare(S* s, int v) { s->m_alphaCompare = v; }
static void PDDI_THISCALL setUvMode(S* s, int v) { s->m_uvMode = v; }
static void PDDI_THISCALL setFilter(S* s, int v) { s->m_filter = v; }
static void PDDI_THISCALL setShade(S* s, int v) { s->m_shadeMode = v; }
static void PDDI_THISCALL setLit(S* s, int v) { s->m_lit = v != 0; }
static void PDDI_THISCALL setTwoSided(S* s, int v) { s->m_twoSided = v != 0; }
static void PDDI_THISCALL setAlphaRef(S* s, float v) { s->m_alphaRef = v; }
static void PDDI_THISCALL setAmbient(S* s, uint32_t v) { s->m_ambient = v; }
static void PDDI_THISCALL setDiffuse(S* s, uint32_t v) { s->m_diffuse = v; }
static void PDDI_THISCALL setEmissive(S* s, uint32_t v) { s->m_emissive = v; }
static void PDDI_THISCALL setSpecular(S* s, uint32_t v) { s->m_specular = v; }
static void PDDI_THISCALL setShininess(S* s, float v) { s->m_shininess = v; }
static void PDDI_THISCALL ignoreVector(S*, const void*) {}
static void PDDI_THISCALL ignoreInt(S*, int) {}                // accepted, not used yet (G2/G3)
static void PDDI_THISCALL ignoreFloat(S*, float) {}

#define P(name, fn) {K(name), 0, (const void*)&fn, 0, {0, 0}}
#define END {0, 0, 0, 0, {0, 0}}
// the parameters every d3dShader kind shares (in the game's order)
#define COMMON_INTS P("UVMD", setUvMode), P("FIMD", setFilter), P("SHMD", setShade), P("LIT", setLit), \
    P("BLMD", setBlend), P("ATST", setAlphaTest), P("ACMP", setAlphaCompare), P("2SID", setTwoSided)
#define COMMON_FLOATS P("SHIN", setShininess), P("ACTH", setAlphaRef), P("FADE", ignoreFloat)
#define COMMON_COLOURS P("AMBI", setAmbient), P("DIFF", setDiffuse), P("EMIS", setEmissive), P("SPEC", setSpecular)

static const S::Param kNone[] = {END};
static const S::Param kVectors[] = {P("LITV", ignoreVector), END};    // the light vector slot 32 passes
static const S::Param kSimpleTex[] = {P("TEX", setTex), END};
static const S::Param kSimpleInt[] = {COMMON_INTS, P("MCBV", ignoreInt), P("CBVP", ignoreInt), P("CBVY", ignoreInt), END};
static const S::Param kSimpleFloat[] = {COMMON_FLOATS, P("CBVV", ignoreFloat), END};
static const S::Param kColours[] = {COMMON_COLOURS, END};
static const S::Param kLayeredTex[] = {P("TEX", setTex), P("TTEX", setTex2), END};
static const S::Param kLayeredInt[] = {COMMON_INTS, P("TBLM", ignoreInt), P("CLYR", ignoreInt), P("MCBV", ignoreInt),
                                       P("CBVP", ignoreInt), P("CBVY", ignoreInt), END};
static const S::Param kBuildingTex[] = {P("TEX", setTex), P("TTEX", setTex2), P("REFL", setRefl), END};
static const S::Param kBuildingInt[] = {COMMON_INTS, P("LRSA", ignoreInt), END};
static const S::Param kCommonInt[] = {COMMON_INTS, END};
static const S::Param kCommonFloat[] = {COMMON_FLOATS, END};
static const S::Param kReflTex[] = {P("TEX", setTex), P("REFL", setRefl), END};
static const S::Param kReflColours[] = {COMMON_COLOURS, P("ENVB", setSpecular), END};
static const S::Param kRefractFloat[] = {COMMON_FLOATS, P("REFI", ignoreFloat), P("REFB", ignoreFloat), P("TEX", ignoreFloat), END};
static const S::Param kRefractColours[] = {COMMON_COLOURS, P("REFC", setSpecular), END};
static const S::Param kFBInt[] = {P("CLRE", ignoreInt), P("UPDT", ignoreInt), END};
static const S::Param kFBFloat[] = {P("SAT", ignoreFloat), P("BRIT", ignoreFloat), P("MDPT", ignoreFloat), P("CONT", ignoreFloat), END};
static const S::Param kFBColours[] = {P("TINT", setDiffuse), END};
#undef P
#undef END

bgfxShader::bgfxShader(bgfxContext* context)
    : m_context(context), m_kind(kShaderError), m_name("error"), m_blendMode(0), m_alphaCompare(0), m_uvMode(0),
      m_filter(0), m_shadeMode(0), m_alphaTest(false), m_lit(false), m_twoSided(false), m_alphaRef(0.5f),
      m_diffuse(0xffffffffu), m_ambient(0xff000000u), m_emissive(0xff000000u), m_specular(0xff000000u),
      m_shininess(1.0f), m_skinned(false)
{
    m_base[0] = m_base[1] = 0;
    for (int i = 0; i < 6; i++)
        m_tables[i] = 0;
    for (int i = 0; i < 3; i++)
        m_texture[i] = 0;
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

// ---- bgfxShader slots
const char* bgfxShader::vfunc_4() { return m_name; }
bool bgfxShader::vfunc_5(int a0, int a1) { PDDI_BASE(5, FUN_003279e0(a0, a1)); }
bool bgfxShader::vfunc_6(int a0, int a1) { PDDI_BASE(6, FUN_00327a40(a0, a1)); }
unsigned char bgfxShader::vfunc_7(int a0, int a1) { PDDI_BASE(7, FUN_00327aa0(a0, a1)); }
bool bgfxShader::vfunc_8(int a0, int a1) { PDDI_BASE(8, FUN_00327b00(a0, a1)); }
bool bgfxShader::vfunc_9(int a0, int a1) { PDDI_BASE(9, FUN_00327b60(a0, a1)); }
bool bgfxShader::vfunc_10(int a0, int a1) { PDDI_BASE(10, FUN_00327bc0(a0, a1)); }
// slot 11: passes (every kind the data uses draws in one pass here; the stage set-up is G2's combiner key)
int bgfxShader::vfunc_11() { return 1; }
// slots 12/13 (0x333420, 0x3334a0): activate / deactivate: the game swaps the context's colour for the shader's
// fade mode 2; the draw reads the shader's state directly here
void bgfxShader::vfunc_12() {}
void bgfxShader::vfunc_13() {}
// slot 14: set up pass n (the game: texture stages and render states through D3D; ours are read at the draw)
void bgfxShader::vfunc_14(int) {}
const void* bgfxShader::vfunc_15() { return m_tables[0]; }
const void* bgfxShader::vfunc_16() { return m_tables[1]; }
const void* bgfxShader::vfunc_17() { return m_tables[2]; }
const void* bgfxShader::vfunc_18() { return m_tables[3]; }
const void* bgfxShader::vfunc_19() { return m_tables[4]; }
const void* bgfxShader::vfunc_20() { return m_tables[5]; }
// slot 21 (0x333370): the material (diffuse, specular, ambient, emissive, specular power), as FUN_00324270 reads it
void bgfxShader::vfunc_21(void* out)
{
    ShaderMaterial* m = (ShaderMaterial*)out;
    m->diffuse = m_diffuse;
    m->specular = m_specular;
    m->ambient = m_ambient;
    m->emissive = m_emissive;
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

// ---- bgfxSimpleShader (d3dSimpleShader)
bgfxSimpleShader::bgfxSimpleShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderSimple;
    m_name = "simple";
    tables(this, kSimpleTex, kSimpleInt, kSimpleFloat, kColours);
}
int bgfxSimpleShader::vfunc_11() { return 1; }
void bgfxSimpleShader::vfunc_14(int a0) { bgfxShader::vfunc_14(a0); }
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
void bgfxLayeredShader::vfunc_14(int a0) { bgfxShader::vfunc_14(a0); }
bool bgfxLayeredShader::vfunc_22() { return false; }
void* bgfxLayeredShader::vfunc_23() { return (void*)""; }
void bgfxLayeredShader::vfunc_24() {}

// ---- bgfxBuildingShader (d3dBuildingShader)
bgfxBuildingShader::bgfxBuildingShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderBuilding;
    m_name = "building";
    tables(this, kBuildingTex, kBuildingInt, kCommonFloat, kColours);
}
int bgfxBuildingShader::vfunc_11() { return 1; }
void bgfxBuildingShader::vfunc_12() { bgfxShader::vfunc_12(); }
void bgfxBuildingShader::vfunc_13() { bgfxShader::vfunc_13(); }
void bgfxBuildingShader::vfunc_14(int a0) { bgfxShader::vfunc_14(a0); }
void* bgfxBuildingShader::vfunc_23() { return (void*)""; }

// ---- bgfxReflShader (d3dReflShader)
bgfxReflShader::bgfxReflShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderRefl;
    m_name = "reflection";
    tables(this, kReflTex, kCommonInt, kCommonFloat, kReflColours);
}
int bgfxReflShader::vfunc_11() { return 1; }
void bgfxReflShader::vfunc_12() { bgfxShader::vfunc_12(); }
void bgfxReflShader::vfunc_13() { bgfxShader::vfunc_13(); }
void bgfxReflShader::vfunc_14(int a0) { bgfxShader::vfunc_14(a0); }

// ---- bgfxRefractShader (d3dRefractVertexShader)
bgfxRefractShader::bgfxRefractShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderRefract;
    m_name = "refract";
    tables(this, kSimpleTex, kCommonInt, kRefractFloat, kRefractColours);
}
int bgfxRefractShader::vfunc_11() { return 1; }
void bgfxRefractShader::vfunc_12() { bgfxShader::vfunc_12(); }
void bgfxRefractShader::vfunc_13() { bgfxShader::vfunc_13(); }
void bgfxRefractShader::vfunc_14(int a0) { bgfxShader::vfunc_14(a0); }
bool bgfxRefractShader::vfunc_22() { return false; }
void* bgfxRefractShader::vfunc_23() { return (void*)(m_skinned ? "skin_refract" : "refract"); }   // 0x32f250
void bgfxRefractShader::vfunc_24() {}

// ---- bgfxFBEffectsShader (d3dFBEffectsShader)
bgfxFBEffectsShader::bgfxFBEffectsShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderFBEffects;
    m_name = "fbeffectsshader";
    tables(this, kNone, kFBInt, kFBFloat, kFBColours);
}
int bgfxFBEffectsShader::vfunc_11() { return 1; }
void bgfxFBEffectsShader::vfunc_12() { bgfxShader::vfunc_12(); }
void bgfxFBEffectsShader::vfunc_13() { bgfxShader::vfunc_13(); }
void bgfxFBEffectsShader::vfunc_14(int a0) { bgfxShader::vfunc_14(a0); }

// ---- bgfxErrorShader (d3dErrorShader)
bgfxErrorShader::bgfxErrorShader(bgfxContext* context) : bgfxShader(context)
{
    m_kind = kShaderError;
    m_name = "error";
    tables(this, kNone, kNone, kNone, kNone);
}
int bgfxErrorShader::vfunc_11() { return 1; }
void bgfxErrorShader::vfunc_14(int a0) { bgfxShader::vfunc_14(a0); }
} // namespace pddi
} // namespace hulk
