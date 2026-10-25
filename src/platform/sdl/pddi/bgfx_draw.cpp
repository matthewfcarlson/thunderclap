// The draw path every pddi draw goes through (G3): the backend's vertex, the vertex programs and the fixed-function
// program, the constant file, the D3D-side render state, views for viewports and mid-frame clears. This is the
// front end's half (API-independent since the front-end/sink split, docs/graphics-backend.md section 15): it
// resolves each draw into a DrawPacket for the build's sink (draw_sink.h; the bgfx sink is bgfx_sink.cpp).
//
// One vertex for every draw (the backend's own, `Vertex` below): prim streams and prim buffers are converted to it
// from the layouts the game writes (d3dPrimStream's unpacked layout; d3dPrimBuffer's packed one, FUN_00326e90:
// normals and blend weights 11:11:10, bone indices as D3DCOLOR bytes). Every attribute any program reads is in it,
// with Direct3D's defaults where the game's vertex has none, so one layout serves every program (80 bytes a
// vertex; per-format layouts are a later memory optimisation).
//
// Vertex programs: a prim buffer carries the program its creation chose (FUN_00327860: the parameter block's name,
// else "skin" / "skin_onebone" for skinned vertex flags); the draw uses the proven counterpart from shaders/vp/
// (docs/shaders.md) with the constant file c96..c191 as `u_vc`. A program whose constant upload is not ported yet
// (only the skinning extension's is) is drawn with the fixed-function program instead, logged once.
#include "bgfx_pddi.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

namespace hulk {
namespace pddi {

enum { kNone = 0xffff };

// ---------------------------------------------------------------------------------------------
// The sink and the tag points
DrawSink* drawSink()
{
#if HULK_REMASTER
    return remasterSink();
#else
    return bgfxSink();
#endif
}

static uint32_t s_tagPhase;     // SinkPhase of the draws that follow (sinkTag)
static uint64_t s_tagInstance;

void sinkTag(uint32_t phase, uint64_t instance)
{
    s_tagPhase = phase;
    s_tagInstance = instance;
}

// ---------------------------------------------------------------------------------------------
// The backend's vertex
typedef SinkVertex Vertex;


static void defaults(Vertex& v)
{
    memset(&v, 0, sizeof(v));
    v.colour0 = 0xffffffffu;    // no diffuse in the vertex: white (Direct3D's fixed-function default)
    v.colour1 = 0;
}

// NORMPACKED3: x bits 0-10, y 11-21, z 22-31, each signed normalised (what the stream's slots 1/11 write)
static void unpack3(uint32_t v, float* out)
{
    int x = (int)(v << 21) >> 21;
    int y = (int)(v << 10) >> 21;
    int z = (int)v >> 22;
    out[0] = x < -1023 ? -1.0f : (float)x / 1023.0f;
    out[1] = y < -1023 ? -1.0f : (float)y / 1023.0f;
    out[2] = z < -511 ? -1.0f : (float)z / 511.0f;
}

// The packed layout of a prim buffer's vertex (FUN_00326e90 for the offsets the stream writes, FUN_003290e0 for
// the size the declaration reads): position, 0x100 weights (packed), 0x80 bone indices, 0x10 normal (packed),
// 0x20 one colour or 0x4000 colour sets, 0x40 a second colour, uv sets, 0x200/0x400 a float each, 0x800 a vector,
// 0x1000 a vector.
struct PackedLayout {
    int weights, indices, normal, colours, colourSets, colour2, uv, uvCount, extra[4], stride;
};

static PackedLayout packedLayout(unsigned flags)
{
    PackedLayout l;
    memset(&l, 0xff, sizeof(l));        // -1: absent
    int p = 12, size = 12;
    l.colourSets = (flags & 0x20) ? 1 : ((flags & 0x4000) ? (int)((flags >> 15) & 7) : 0);
    l.uvCount = (int)(flags & 15);
    if (flags & 0x100) { l.weights = p; p += 4; size += 4; }
    if (flags & 0x80) { l.indices = p; p += 4; size += 4; }
    if (flags & 0x10) { l.normal = p; p += 4; size += 4; }
    if (flags & 0x20) { l.colours = p; p += 4; size += 4; }
    else if ((flags & 0x4000) && l.colourSets > 0) { l.colours = p; p += 4 * l.colourSets; }
    if (flags & 0x4000) size += 8;
    if (flags & 0x40) { l.colour2 = p; p += 4; size += 4; }
    if (l.uvCount) { l.uv = p; p += 8 * l.uvCount; size += 8 * l.uvCount; }
    if (flags & 0x200) { l.extra[0] = p; p += 4; size += 4; }
    if (flags & 0x400) { l.extra[1] = p; p += 4; size += 4; }
    if (flags & 0x800) { l.extra[2] = p; p += 12; size += 12; }
    if (flags & 0x1000) { l.extra[3] = p; size += 12; }
    l.stride = size;
    return l;
}

int packedStride(unsigned flags)
{
    return packedLayout(flags).stride;
}

void packedOffsets(unsigned flags, int* weights, int* indices, int* normal, int* colours, int* colour2, int* uv,
                   int* extra)
{
    PackedLayout l = packedLayout(flags);
    *weights = l.weights;
    *indices = l.indices;
    *normal = l.normal;
    *colours = l.colours;
    *colour2 = l.colour2;
    *uv = l.uv;
    for (int i = 0; i < 4; i++)
        extra[i] = l.extra[i];
}

static void convertPacked(const char* src, int n, unsigned flags, Vertex* out)
{
    PackedLayout l = packedLayout(flags);
    int uvs = l.uvCount > 4 ? 4 : l.uvCount;
    for (int i = 0; i < n; i++, src += l.stride) {
        Vertex& v = out[i];
        defaults(v);
        memcpy(v.pos, src, 12);
        if (l.weights >= 0)
            unpack3(*(const uint32_t*)(src + l.weights), v.weight);
        if (l.indices >= 0) {
            const uint8_t* b = (const uint8_t*)(src + l.indices);
            v.indices[0] = b[2];
            v.indices[1] = b[1];
            v.indices[2] = b[0];
            v.indices[3] = b[3];
        }
        if (l.normal >= 0)
            unpack3(*(const uint32_t*)(src + l.normal), v.normal);
        if (l.colours >= 0) {
            v.colour0 = *(const uint32_t*)(src + l.colours);
            if (l.colourSets > 1)
                v.colour1 = *(const uint32_t*)(src + l.colours + 4);
        }
        if (l.colour2 >= 0)
            v.colour1 = *(const uint32_t*)(src + l.colour2);
        if (uvs)
            memcpy(v.uv, src + l.uv, 8 * uvs);
    }
}

// d3dPrimStream's layout (0x31be40; bgfxPrimStream::vfunc_0): position, 0x10 normal (3 floats), 0x20 colour, uvs
static void convertStream(const bgfxPrimStream* s, Vertex* out)
{
    int normalOff = s->normalPtr ? (int)(s->normalPtr - s->posPtr) : -1;
    int colourOff = s->colorPtr ? (int)(s->colorPtr - s->posPtr) : -1;
    int uvOff = s->uvPtr ? (int)(s->uvPtr - s->posPtr) : -1;
    int uvs = s->m_uvCount > 4 ? 4 : s->m_uvCount;
    const char* v = s->m_data;
    for (int i = 0; i < s->vertCount; i++, v += s->stride) {
        defaults(out[i]);
        memcpy(out[i].pos, v, 12);
        if (normalOff >= 0)
            memcpy(out[i].normal, v + normalOff, 12);
        if (colourOff >= 0)
            out[i].colour0 = *(const uint32_t*)(v + colourOff);
        if (uvOff >= 0 && uvs)
            memcpy(out[i].uv, v + uvOff, 8 * uvs);
    }
}

// ---------------------------------------------------------------------------------------------
// Programs
struct ProgramInfo {
    const char* name;           // the game's program name ("" = fixed function)
    bool constants;             // its constant upload is ported (else: drawn with the fixed-function program)
};
// (the sink has each one's shaders, in this order: bgfx_sink.cpp kProgramShaders)
static const ProgramInfo kPrograms[] = {
    {"", true},                                 // vs_vp_ff
    {"skin", true},                             // d3dExtHardwareSkinning (FUN_00324270 + bones)
    {"skin_onebone", true},                     // the same uploads
    {"refract", true},                          // d3dRefractVertexShader::vfunc_24 (0x32f3b0)
    {"skin_refract", true},                     // the same, after the skinning extension's
    {"simple_proximity", false},                // d3dSimpleShader::vfunc_24: CBVP is 0 in the data
    // G5: the fixed-function path with two-sided lighting (not a game program: chosen by the draw, never by name)
    {"\x01" "ff two-sided", true},
};
enum { kProgramFF2S = 6 };
enum { kProgramCount = sizeof(kPrograms) / sizeof(kPrograms[0]) };
static_assert((int)kProgramCount == (int)kVertexProgramCount, "the sink's vertex program table has the same entries");

static int programIndex(const char* name, bool* fellBack)
{
    *fellBack = false;
    if (!name || !*name)
        return 0;
    for (int i = 0; i < kProgramCount; i++)
        if (!strcmp(kPrograms[i].name, name)) {
            if (kPrograms[i].constants)
                return i;
            break;
        }
    *fellBack = true;
    return 0;
}

bool bgfxContext::ensureResources()
{
    if (!m_display || !m_display->m_initialised)
        return false;
    return m_sink->drawResources();
}

void bgfxContext::combinerStats(int* generated, int* generic, int* draws)
{
    m_sink->combinerStats(generated, generic, draws);
}


// ---------------------------------------------------------------------------------------------
// Constants
static void colour4(uint32_t c, float* out)       // FUN_0031ffc0: D3DCOLOR -> r, g, b, a in 0..1
{
    out[0] = (float)((c >> 16) & 255) * (1.0f / 255.0f);
    out[1] = (float)((c >> 8) & 255) * (1.0f / 255.0f);
    out[2] = (float)(c & 255) * (1.0f / 255.0f);
    out[3] = (float)(c >> 24) * (1.0f / 255.0f);
}

// a row-vector matrix's columns (what dot(v, column) gives: the shaders' rows), with Direct3D's [0, w] depth
// mapped to [-w, w] where the renderer wants it (OpenGL)
static void columns(const float* m, float (*out)[4], bool remapDepth)
{
    for (int i = 0; i < 4; i++)
        for (int k = 0; k < 4; k++)
            out[i][k] = m[k * 4 + i];
    if (remapDepth)
        for (int k = 0; k < 4; k++)
            out[2][k] = 2.0f * out[2][k] - out[3][k];
}

static bool homogeneousDepth()
{
    return drawSink()->caps().homogeneousDepth != 0;
}

static bool originBottomLeft()
{
    return drawSink()->caps().originBottomLeft != 0;
}

void bgfxContext::setVertexConstants(int reg, const float* v, int count)
{
    for (int i = 0; i < count; i++)
        if (reg + i >= 0 && reg + i < 192)
            memcpy(m_vc[reg + i], v + 4 * i, 16);
}

const float* bgfxContext::worldMatrix()
{
    return m_world;
}

// FUN_00321310: the lights whose slot 110 marked them, from the base's light set (+0x50: 8 x 0x7c bytes), moved
// into camera space with the matrix noted then (direction rotated, position transformed). The host build sets
// lights directly (hostSetLight).
void bgfxContext::updateLights()
{
    if (!m_anyLightDirty)
        return;
    m_anyLightDirty = false;
#if HULK_PDDI_GAME
    if (m_hostLights)
        return;
    const char* set = *(const char* const*)((const char*)this + 0x50);
    for (int i = 0; i < kLights; i++) {
        if (!m_lightDirty[i])
            continue;
        m_lightDirty[i] = false;
        if (!set)
            continue;
        const char* src = set + 4 + 0x7c * i;
        const float* pos = (const float*)src;
        const float* dir = (const float*)(src + 0x20);
        const float* m = m_lightMatrix[i];
        Light& l = m_lights[i];
        for (int j = 0; j < 3; j++) {
            l.direction[j] = dir[0] * m[j] + dir[1] * m[4 + j] + dir[2] * m[8 + j];
            l.position[j] = pos[0] * m[j] + pos[1] * m[4 + j] + pos[2] * m[8 + j] + m[12 + j];
        }
        static const int kType[4] = {3, 1, 2, 1};     // 0x4d3a10
        unsigned t = *(const unsigned*)(src + 0x70);
        l.type = t < 4 ? kType[t] : 1;
        colour4(*(const uint32_t*)(src + 0x74), l.diffuse);
        l.range = *(const float*)(src + 0x54);
        l.att[0] = *(const float*)(src + 0x58);
        l.att[1] = *(const float*)(src + 0x5c);
        l.att[2] = *(const float*)(src + 0x60);
        l.on = *(const unsigned char*)(src + 0x78) != 0;
    }
#else
    for (int i = 0; i < kLights; i++)
        m_lightDirty[i] = false;
#endif
}

// FUN_00321dc0(ids, 0): the enabled lights of pddi type 0 (directional), at most four, in index order
int bgfxContext::directionalLights(int* ids)
{
    int n = 0;
    for (int i = 0; i < 4; i++)
        ids[i] = -1;
    for (int i = 0; i < kLights && n < 4; i++)
        if (m_lights[i].on && m_lights[i].type == 3)
            ids[n++] = i;
    return n;
}

// FUN_00324270: the constants the skin programs read besides the bones (c96 fixed, c98-c101 the projection's
// columns, c102 diffuse, c103 specular + power, c104 emissive + ambient light x ambient, c105+2i / c106+2i the
// direction and colour of up to four directional lights; a missing light gets light 0's direction and black)
void bgfxContext::skinConstants(bgfxShader* shader)
{
    updateLights();
    int ids[4];
    directionalLights(ids);
    ShaderMaterial mat;
    shader->vfunc_21(&mat);
    float c[17][4];
    memset(c, 0, sizeof(c));
    c[0][0] = 0.0f;
    c[0][1] = 1.0f;
    c[0][2] = 256.0f;
    c[0][3] = 0.5f;
    float spec[4], diff[4], emis[4], amb[4], ambLight[4];
    colour4(mat.specular, spec);
    colour4(mat.diffuse, diff);
    colour4(mat.emissive, emis);
    colour4(mat.ambient, amb);
    colour4(m_rs.ambient, ambLight);
    memcpy(&spec[3], &mat.shininessBits, 4);
    if (emis[3] == 0.0f) {
        emis[3] = diff[3];
        diff[3] = 0.0f;
    }
    for (int k = 0; k < 4; k++)
        emis[k] = ambLight[k] * amb[k] + emis[k];
    columns(m_proj, &c[2], homogeneousDepth());
    memcpy(c[6], diff, 16);
    memcpy(c[7], spec, 16);
    memcpy(c[8], emis, 16);
    for (int i = 0; i < 4; i++) {
        const Light& l = m_lights[ids[i] < 0 ? 0 : ids[i]];
        memcpy(c[9 + 2 * i], l.direction, 12);
        c[9 + 2 * i][3] = l.range;
        if (ids[i] >= 0)
            memcpy(c[10 + 2 * i], l.diffuse, 16);
    }
    setVertexConstants(96, c[0], 1);
    setVertexConstants(98, c[2], 4);
    setVertexConstants(102, c[6], 11);
}

// 0x32f3b0's unskinned constants. The transforms are D3D's: GetTransform(WORLD) (the modelview: D3D's VIEW is the
// identity here), x VIEW (the affine product FUN_0022ca90), x PROJECTION (FUN_0022cc10), transposed (FUN_0022c0b0);
// and WORLD transposed. Lights as FUN_00324270 takes them (FUN_00321dc0: up to three of the enabled directional
// lights; a missing one is light 0's direction and black). The material as slot 21 hands it out.
void bgfxContext::refractConstants(bgfxShader* shader, const float* viewport, const float* uv, const float* half,
                                   const float* one)
{
    updateLights();
    float wv[16];
    for (int r = 0; r < 4; r++)                    // the world with the affine product's last column
        for (int k = 0; k < 4; k++)
            wv[r * 4 + k] = k == 3 ? (r == 3 ? 1.0f : 0.0f) : m_world[r * 4 + k];
    float wvp[16];
    for (int r = 0; r < 4; r++)
        for (int k = 0; k < 4; k++)
            wvp[r * 4 + k] = wv[r * 4 + 0] * m_proj[0 * 4 + k] + wv[r * 4 + 1] * m_proj[1 * 4 + k] +
                             wv[r * 4 + 2] * m_proj[2 * 4 + k] + wv[r * 4 + 3] * m_proj[3 * 4 + k];
    float clip[4][4], world[4][4];
    columns(wvp, clip, homogeneousDepth());
    columns(m_world, world, false);
    setVertexConstants(98, clip[0], 4);
    setVertexConstants(102, world[0], 4);
    setVertexConstants(107, viewport, 1);
    setVertexConstants(108, uv, 1);
    setVertexConstants(109, half, 1);
    int ids[4];
    directionalLights(ids);
    static const float kCoeff[4] = {0.0f, 1.0f, 256.0f, 0.5f};
    ShaderMaterial mat;
    shader->vfunc_21(&mat);
    float spec[4], diff[4], emis[4], amb[4], ambLight[4];
    colour4(mat.specular, spec);
    colour4(mat.diffuse, diff);
    colour4(mat.emissive, emis);
    colour4(mat.ambient, amb);
    colour4(m_rs.ambient, ambLight);
    if (emis[3] == 0.0f) {
        emis[3] = diff[3];
        diff[3] = 0.0f;
    }
    memcpy(&spec[3], &mat.shininessBits, 4);
    for (int k = 0; k < 4; k++)
        emis[k] = ambLight[k] * amb[k] + emis[k];
    setVertexConstants(96, kCoeff, 1);
    setVertexConstants(110, diff, 1);
    setVertexConstants(111, spec, 1);
    setVertexConstants(112, emis, 1);
    static const float kZero[4] = {0, 0, 0, 0};
    for (int i = 0; i < 3; i++) {
        const Light& l = m_lights[ids[i] < 0 ? 0 : ids[i]];
        float dir[4] = {l.direction[0], l.direction[1], l.direction[2], l.range};
        setVertexConstants(113 + 2 * i, dir, 1);
        setVertexConstants(114 + 2 * i, ids[i] < 0 ? kZero : l.diffuse, 1);
    }
    setVertexConstants(121, one, 1);
}

// The fixed-function program's constants (vs_vp_ff.sc has the layout) from the D3D-side state: the transforms, the
// material and lighting the shader's pass set (FUN_00329f70), the lights, each stage's texture coordinates
static void ffConstants(bgfxContext* ctx, unsigned flags, float (*c)[4])
{
    const bgfxContext::DeviceState& d = ctx->m_d3d;
    memset(c, 0, 56 * 16);
    // HULK_HUD=edge (vs_vp_ff.sh; 0 = off): only the HUD's frame models, which the game draws at scale 4 (the text, the
    // message box and the icons are laid out from the wider layout width by the game itself, at scales below 1.5)
    c[55][0] = ctx->m_world[0] >= 2.0f ? ctx->m_hudShift : 0.0f;
    c[55][1] = ctx->m_hudRegion;
    columns(ctx->m_world, &c[0], false);
    columns(ctx->m_proj, &c[4], homogeneousDepth());
    colour4(d.material[0], c[8]);
    colour4(d.material[2], c[9]);
    colour4(d.material[3], c[10]);
    colour4(d.material[1], c[11]);
    c[11][3] = d.power;
    colour4(ctx->m_rs.ambient, c[12]);
    c[13][0] = d.lighting ? 1.0f : 0.0f;
    // FUN_00320c60 (the device set-up) leaves COLORVERTEX on but sets every material source to D3DMCS_MATERIAL: a
    // lit draw takes its colours from the material, never from the vertex. NORMALIZENORMALS is never set: off.
    (void)flags;
    c[13][1] = 0.0f;
    c[13][2] = (d.lighting && d.specular) ? 1.0f : 0.0f;
    c[13][3] = 0.0f;
    // Direct3D's normal transform: the inverse transpose of the world-view 3x3 (rows for the shader's dots)
    {
        const float* w = ctx->m_world;
        float a00 = w[0], a01 = w[1], a02 = w[2], a10 = w[4], a11 = w[5], a12 = w[6], a20 = w[8], a21 = w[9],
              a22 = w[10];
        float c00 = a11 * a22 - a12 * a21, c01 = a12 * a20 - a10 * a22, c02 = a10 * a21 - a11 * a20;
        float det = a00 * c00 + a01 * c01 + a02 * c02;
        float k = det != 0.0f ? 1.0f / det : 0.0f;
        // inverse = adjugate / det; row i of the inverse: the cofactors of column i
        float inv[3][3] = {
            {c00 * k, (a02 * a21 - a01 * a22) * k, (a01 * a12 - a02 * a11) * k},
            {c01 * k, (a00 * a22 - a02 * a20) * k, (a02 * a10 - a00 * a12) * k},
            {c02 * k, (a01 * a20 - a00 * a21) * k, (a00 * a11 - a01 * a10) * k},
        };
        // n' = n (M^-1)^T: n'_i = sum_k n_k inv[i][k]
        for (int i = 0; i < 3; i++) {
            c[52 + i][0] = inv[i][0];
            c[52 + i][1] = inv[i][1];
            c[52 + i][2] = inv[i][2];
            c[52 + i][3] = 0.0f;
        }
    }
    int n = 0;
    for (int i = 0; i < bgfxContext::kLights && n < 4; i++) {
        const bgfxContext::Light& l = ctx->m_lights[i];
        if (!l.on)
            continue;
        float* q = c[14 + 4 * n];
        memcpy(q, l.position, 12);
        q[3] = (float)l.type;
        memcpy(q + 4, l.direction, 12);
        q[7] = l.range;
        memcpy(q + 8, l.diffuse, 16);
        q[12] = l.att[0];
        q[13] = l.att[1];
        q[14] = l.att[2];
        n++;
    }
    static const float kIdentity[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    for (int s = 0; s < 4; s++) {
        const bgfxContext::Stage& st = d.stage[s];
        uint32_t gen = st.texCoordIndex >> 16;
        c[48 + s][0] = gen == 0 ? (float)(st.texCoordIndex & 3) : gen == 1 ? 10.0f : gen == 2 ? 11.0f : 12.0f;
        c[48 + s][1] = (float)(st.transformFlags & 0xff);
        columns(s < 3 ? ctx->m_texMatrix[s] : kIdentity, &c[32 + 4 * s], false);
    }
}
// ---------------------------------------------------------------------------------------------
// State
static const uint32_t kPrimToD3D[5] = {5, 6, 2, 4, 1};          // the game's table at 0x4d3650

// The D3D blend state (what FUN_0032a0c0 left: enable, operation, factors) as the sink's: GL-style factor values
// (0x302 src alpha ...) and operations (0x8006 add ...); anything else: one / add, as before the split
static uint8_t blendFactor(uint32_t f)
{
    switch (f) {
    case 0: return kBlendZero;
    case 1: return kBlendOne;
    case 0x300: return kBlendSrcColour;
    case 0x301: return kBlendInvSrcColour;
    case 0x302: return kBlendSrcAlpha;
    case 0x303: return kBlendInvSrcAlpha;
    case 0x304: return kBlendDstAlpha;
    case 0x305: return kBlendInvDstAlpha;
    case 0x306: return kBlendDstColour;
    case 0x307: return kBlendInvDstColour;
    case 0x308: return kBlendSrcAlphaSat;
    default: return kBlendOne;
    }
}

static uint8_t blendOp(uint32_t op)
{
    switch (op) {
    case 0x800a: return kBlendSub;
    case 0x800b: return kBlendRevSub;
    case 0x8007: return kBlendMin;
    case 0x8008: return kBlendMax;
    default: return kBlendAdd;
    }
}

// The render state of a draw: the context's (slots 54-80) and the D3D blend state the shader's pass left
void bgfxContext::renderState(int kind, SinkRenderState* o)
{
    const RenderState& rs = m_rs;
    memset(o, 0, sizeof(*o));
    o->prim = (uint8_t)kind;
    o->writeMask = (rs.colourMask[0] ? 1 : 0) | (rs.colourMask[1] ? 2 : 0) | (rs.colourMask[2] ? 4 : 0) |
                   (rs.colourMask[3] ? 8 : 0);
    o->depthTest = rs.zEnable ? 1 : 0;
    o->depthFunc = (uint8_t)(rs.zFunc & 7);
    o->depthWrite = rs.zWrite ? 1 : 0;
    o->cull = m_d3d.cull == 1 || m_d3d.cull == 2 ? (uint8_t)m_d3d.cull : 0;   // D3D's: slot 54's, none under 2SID
    if (m_d3d.blend) {
        o->blend = 1;
        o->blendOp = blendOp(m_d3d.blendOp);
        o->srcBlend = blendFactor(m_d3d.srcBlend);
        o->dstBlend = blendFactor(m_d3d.dstBlend);
    }
    if (rs.stencil) {
        o->stencil = 1;
        o->stencilFunc = (uint8_t)(rs.stencilFunc & 7);
        o->stencilRef = (uint8_t)(rs.stencilRef & 255);
        o->stencilReadMask = (uint8_t)(rs.stencilMask & 255);
        for (int i = 0; i < 3; i++)
            o->stencilOp[i] = (uint8_t)(rs.stencilOp[i] % 6);
    }
}


// A new bgfx view for what follows when the current one already has draws (a viewport change or a clear in the
// middle of a frame: bgfx clears a view at its start and has one rectangle per view). Views run in submission order.
void bgfxContext::viewChanged(int clearFlags)
{
    // a view that only clears keeps the rectangle it cleared (Direct3D clears the viewport of the time): a viewport
    // change after it opens the next view too
    bool clearPending = clearFlags < 0 && m_clearFlags != 0;
    if ((m_viewUsed || clearPending) && m_viewId < 250) {
        m_viewId++;
        m_viewUsed = false;
        m_clearFlags = 0;
    }
    if (clearFlags >= 0)
        m_clearFlags = (unsigned)clearFlags;
    setupView();
}

void bgfxContext::setupView()
{
    if (!m_display || !m_display->m_initialised)
        return;
    SinkPass p;
    memset(&p, 0, sizeof(p));
    p.id = (uint16_t)m_viewId;
    p.target = kSinkTargetScene;
    p.x = (uint16_t)m_viewport[0];
    p.y = (uint16_t)m_viewport[1];
    p.w = (uint16_t)m_viewport[2];
    p.h = (uint16_t)m_viewport[3];
    p.clearFlags = (uint16_t)m_clearFlags;
    p.clearRgba = m_clearRgba;
    p.clearDepth = m_clearDepth;
    p.clearStencil = (uint8_t)m_clearStencil;
    m_sink->setPass(p);
}

bgfxTexture* bgfxContext::copyFrameBuffer()
{
    bgfxDisplay* d = m_display;
    if (!d || !d->m_initialised || !d->offscreen())
        return 0;
    SinkTarget copy = m_sink->frameCopy();
    if (copy.texture == kNone)
        return 0;
    if (!m_fbCopy) {
        m_fbCopy = new bgfxTexture(this);
        m_fbCopy->m_linear = true;            // the game's copy is a render-target (linear) texture
        m_fbCopy->m_pddiFormat = 11;
    }
    m_fbCopy->m_handle = copy.texture;        // (re)made with the target on a resize
    m_fbCopy->m_width = d->targetWidth();
    m_fbCopy->m_height = d->targetHeight();
    m_fbCopy->m_fromTarget = true;
    if (!sceneCopy(copy.texture, copy.frameBuffer)) {
        static int s_logged;
        if (!s_logged++)
            logf("pddi: frame-buffer copy: out of bgfx views this frame (the copy keeps older contents)\n");
        return m_fbCopy;
    }
    m_copiesThisFrame++;
    return m_fbCopy;
}

// The copy goes at the start of a view that follows everything drawn (and cleared) so far: a view runs its blits
// before its clear and its draws. A quad copy (SinkCaps::copyTakesPass) is a view of its own drawing into the
// destination's frame buffer; the scene goes on in the next view.
bool bgfxContext::sceneCopy(unsigned dstTex, unsigned dstFb)
{
    SinkCaps caps = m_sink->caps();
    bool quad = caps.copyTakesPass != 0;
    unsigned last = caps.lastPass;
    if (quad && dstFb == kNone)
        return false;
    if (m_viewUsed || m_clearFlags) {
        if (m_viewId >= (quad ? last - 1 : last))
            return false;
        m_viewId++;
        m_viewUsed = false;
        m_clearFlags = 0;
        setupView();
    } else if (quad && m_viewId >= last) {
        return false;
    }
    SinkTarget dst = {dstTex, dstFb};
    m_sink->copyFrame((uint16_t)m_viewId, dst);
    if (!quad)
        return true;
    m_viewId++;
    m_viewUsed = false;
    m_clearFlags = 0;
    setupView();
    return true;
}


static uint32_t fnv(uint32_t h, const void* p, unsigned n)
{
    const unsigned char* b = (const unsigned char*)p;
    for (unsigned i = 0; i < n; i++)
        h = (h ^ b[i]) * 16777619u;
    return h;
}

// The pddi state of the draw as the hybrid build's hook reads it from the game's context (hybrid/hooks.cpp drawlog):
// the portable base keeps the same blocks in our context (+0x4c render state, +0x58 stencil, +0x54 fog, the matrix
// stacks at +0x20..), so these words are comparable field by field. The host build has no base: our own state.
void bgfxContext::drawlogState(DrawRecord& r)
{
#if HULK_PDDI_GAME
    const char* me = (const char*)this;
    const uint32_t* a = *(const uint32_t* const*)(me + 0x4c);
    const uint32_t* st = *(const uint32_t* const*)(me + 0x58);
    const unsigned char* fog = *(const unsigned char* const*)(me + 0x54);
    for (int i = 0; i < 6; i++) {
        r.stateA[i] = a ? a[i] : 0;
        r.stateS[i] = st ? st[i] : 0;
    }
    r.fog = fog ? fog[4] : 0;
    uint32_t h = 2166136261u;
    for (int i = 0; i < 4; i++) {
        const uint32_t* stack = *(const uint32_t* const*)(me + 0x20 + 4 * i);   // +8 index, +0xc matrices
        if (!stack)
            continue;
        uint32_t idx = stack[2];
        const char* m = (const char*)(uintptr_t)stack[3];
        if (idx < 64 && m)
            h = fnv(h, m + 64 * idx, 64);
    }
    r.mtx = h;
#else
    r.stateA[1] = m_rs.cull;
    r.stateA[2] = m_rs.zEnable;
    r.stateA[3] = m_rs.zFunc;
    r.stateA[4] = m_rs.zWrite;
    r.stateS[1] = m_rs.stencil;
    r.stateS[2] = m_rs.stencilFunc;
    r.stateS[3] = m_rs.stencilRef;
    r.fog = m_rs.fog;
    r.mtx = fnv(fnv(2166136261u, m_world, sizeof(m_world)), m_proj, sizeof(m_proj));
#endif
}

// ---------------------------------------------------------------------------------------------
// The draw
void bgfxContext::draw(bgfxShader* sh, const DrawSource& src)
{
    if (src.kind < 0 || src.kind > kPrimPoints || src.count == 0)
        return;
    uint32_t frame = drawlogFrame(m_display ? m_display->m_frame : 0);
    if (drawlogWants(frame)) {
        DrawRecord r;
        memset(&r, 0, sizeof(r));
        r.frame = frame;
        r.seq = m_drawIndex;
        r.prim = kPrimToD3D[src.kind];
        r.count = src.count;
        r.shader = 0x8000u | (uint32_t)(sh ? sh->m_kind : kShaderError);
        r.shaderId = sh ? (uint32_t)sh->m_base[1] : 0;     // pddiBaseShader's word at +0xc
        for (int t = 0; t < 4; t++)                     // the stage textures, as the hybrid log's
            r.tex[t] = drawlogTexture(m_d3d.stage[t].texture);
        drawlogState(r);
        drawlogAppend(r);
    }
    uint32_t drawIndex = m_drawIndex++;
    countDraw();
    if (!ensureResources())
        return;
    updateLights();
    bool fellBack;
    int pi = programIndex(src.program, &fellBack);
    if (fellBack) {
        static const char* s_logged[16];
        static int s_nlogged;
        bool seen = false;
        for (int i = 0; i < s_nlogged; i++)
            seen |= s_logged[i] == src.program;
        if (!seen && s_nlogged < 16) {
            s_logged[s_nlogged++] = src.program;
            logf("pddi: vertex program '%s' not wired yet: fixed-function program instead\n", src.program);
        }
    }
    DrawSink* sink = m_sink;
    // a lit two-sided draw (FUN_00329f70: TWOSIDEDLIGHTING with LIGHTING) on the fixed-function path: the variant
    // with the back face's colours (G5), when this sink has it
    if (pi == 0 && m_d3d.lighting && m_d3d.twoSidedLighting && sink->hasVertexProgram(kProgramFF2S))
        pi = kProgramFF2S;
    char key[160];
    combinerKey(m_d3d, key, sizeof(key));
    DrawPacket p;
    memset(&p, 0, sizeof(p));
    p.vertexProgram = (uint32_t)pi;
    p.programName = src.program ? src.program : "";
    p.combinerKey = key;
    p.combinerHash = combinerHash(key);
    p.forceGeneric = m_forceGeneric ? 1 : 0;
    if (!sink->preparePipeline(p))
        return;

    // identity and the scene (for sinks that rebuild the frame: docs/remaster.md 2.6)
    p.frame = m_display ? m_display->m_frame : 0;
    p.drawIndex = drawIndex;
    p.phase = s_tagPhase;
    p.instance = s_tagInstance;
    p.shaderKind = (uint32_t)(sh ? sh->m_kind : kShaderError);
    p.shaderSerial = sh ? (uint32_t)sh->m_base[1] : 0;
    p.bufferOwner = src.owner;
    ViewBlock* vb = viewBlock();
    p.viewMode = vb ? (uint32_t)vb->mode : 0;
    p.modelview = m_world;
    p.projection = m_proj;
    p.view = 0;
    p.lights = m_lights;
    for (int i = 0; i < 4; i++)
        p.material[i] = m_d3d.material[i];
    p.power = m_d3d.power;
    p.ambient = m_rs.ambient;
    p.lighting = m_d3d.lighting ? 1 : 0;
    p.fog = m_rs.fog ? 1 : 0;

    // constants
    float c[56][4];
    if (pi == 0 || pi == kProgramFF2S) {
        ffConstants(this, src.flags, c);
        p.vertexConstants = c[0];
        p.vertexConstantCount = 56;
    } else {
        p.vertexConstants = m_vc[96];
        p.vertexConstantCount = 96;
    }
    // the stage textures (an empty stage samples white), with the stage's addressing and filtering
    float (*frag)[4] = p.frag;
    bool flipTargets = originBottomLeft();
    for (int i = 0; i < 4; i++) {
        const Stage& stg = m_d3d.stage[i];
        const bgfxTexture* tex = stg.texture;
        SinkStage& o = p.stage[i];
        if (tex)
            const_cast<bgfxTexture*>(tex)->flush();           // its latest unlocked contents (deferred uploads)
        o.texture = tex ? tex->m_handle : kNone;
        o.ordinal = tex ? tex->m_ordinal : 0;
        switch (stg.address) {
        case 2: o.address = kAddressMirror; break;
        case 3: case 5: o.address = kAddressClamp; break;
        case 4: o.address = kAddressBorder; break;
        default: o.address = kAddressWrap; break;
        }
        o.minPoint = stg.minFilter <= 1;
        o.magPoint = stg.magFilter <= 1;
        o.mipPoint = stg.mipFilter <= 1;
        o.linear = tex && tex->m_linear;
        o.fromTarget = tex && tex->m_fromTarget;
        // linear textures take texel coordinates; a copy of a render target is stored bottom-up where targets have
        // the origin at the bottom left (OpenGL): v -> 1 - v there
        float sx = 1.0f, sy = 1.0f, oy = 0.0f;
        if (tex && tex->m_linear && tex->m_width && tex->m_height) {
            sx = 1.0f / (float)tex->m_width;
            sy = 1.0f / (float)tex->m_height;
        }
        if (tex && tex->m_fromTarget && flipTargets) {
            sy = -sy;
            oy = 1.0f;
        }
        frag[4 + i / 2][(i & 1) * 2] = sx;
        frag[4 + i / 2][(i & 1) * 2 + 1] = sy;
        frag[14 + i / 2][(i & 1) * 2] = 0.0f;
        frag[14 + i / 2][(i & 1) * 2 + 1] = oy;
    }

    // the alpha test (D3D compare -> pddi order), the specular add, fog, the texture factor
    static const int kCmp[8] = {0, 2, 6, 3, 4, 7, 5, 1};       // D3DCMP 0x200.. -> pddi compare
    frag[0][0] = (float)(m_d3d.alphaRef & 255);
    frag[0][1] = m_d3d.alphaTest ? (float)kCmp[(m_d3d.alphaFunc - 0x200) & 7] : -1.0f;
    frag[0][2] = m_d3d.specular ? 1.0f : 0.0f;
    colour4(m_rs.fogColour, frag[1]);
    frag[1][3] = m_rs.fog ? 1.0f : 0.0f;
    frag[2][0] = m_rs.fogStart;
    frag[2][1] = m_rs.fogEnd;
    colour4(m_d3d.textureFactor, frag[3]);
    // the generic combiner's stages (as the key has them)
    bool on = true;
    for (int i = 0; i < 4; i++) {
        const Stage& stg = m_d3d.stage[i];
        float* k = frag[6 + 2 * i];
        float* l = frag[7 + 2 * i];
        on = on && stg.colorOp > 1 && stg.colorOp <= 26;
        if (!on) {
            k[0] = 1.0f;
            continue;
        }
        bool alphaOff = stg.alphaOp <= 1 || stg.alphaOp > 26;
        k[0] = (float)stg.colorOp;
        k[1] = (float)stg.colorArg1;
        k[2] = (float)stg.colorArg2;
        k[3] = alphaOff ? 2.0f : (float)stg.alphaOp;
        l[0] = alphaOff ? 1.0f : (float)stg.alphaArg1;
        l[1] = (float)stg.alphaArg2;
        l[2] = stg.resultArg == 5 ? 5.0f : 1.0f;
    }

    renderState(src.kind, &p.state);
    p.count = src.count;
    p.vertexCount = src.vertexCount;
    p.transient = src.transient;
    p.vertexBuffer = src.vb;
    p.indexBuffer = src.ib;
    if (!m_viewUsed) {
        m_viewUsed = true;
    }
    p.query = m_visQuery;                     // inside a visibility test: the draw is the query
    p.pass = (uint16_t)m_viewId;
    sink->submitDraw(p);
}

// Draw what a prim stream holds: converted to the backend's vertex in the sink's transient vertices
void bgfxContext::submit(bgfxPrimStream* s)
{
    int n = s->vertCount;
    if (n <= 0)
        return;
    DrawSource src;
    memset(&src, 0, sizeof(src));
    src.kind = s->m_kind;
    src.count = (uint32_t)n;
    src.vertexCount = (uint32_t)n;
    src.transient = kNone;
    src.flags = s->m_flags;
    src.program = m_streamProgram ? m_streamProgram : "";   // a streamed prim group's (vertex program ext slot 6)
    src.vb = src.ib = kNone;
    if (m_display && m_display->m_initialised) {
        uint32_t token;
        Vertex* v = m_sink->allocTransient((uint32_t)n, &token);
        if (!v)
            return;
        convertStream(s, v);
        src.transient = token;
    }
    draw(s->m_shader, src);
}

// ---------------------------------------------------------------------------------------------
// Prim buffers: the sink's buffers from the CPU copy, at the first draw after a change (the bgfx sink: static
// buffers the first time; a buffer written again, animated geometry, gets dynamic ones from then on)
bool bgfxPrimBuffer::prepare()
{
    if (!m_context->ensureResources())
        return false;
    DrawSink* sink = m_context->m_sink;
    if (m_vertsDirty && m_vertexCount > 0) {
        m_vertsDirty = false;
        Vertex* v = (Vertex*)malloc(sizeof(Vertex) * (size_t)m_vertexCount);
        if (v) {
            convertPacked(m_vertices, m_vertexCount, m_flags, v);
            SinkVertexData d;
            d.vertices = v;
            d.count = (uint32_t)m_vertexCount;
            d.owner = m_serial;
            d.packed = m_vertices;
            d.packedStride = (uint32_t)m_stride;
            d.vertexFlags = m_flags;
            d.primKind = (uint32_t)m_kind;
            m_vb = sink->updateVertexBuffer(m_vb, d);
            free(v);
        }
        m_uploads++;
    }
    if (m_indicesDirty && m_indexCapacity > 0) {
        m_indicesDirty = false;
        m_ib = sink->updateIndexBuffer(m_ib, m_indices, (uint32_t)m_indexCapacity, m_serial);
    }
    return m_vb != kNone;
}


// 0x003272f0: draw the buffer (an override count from slot 14 replaces the index or vertex count), as many whole
// primitives as the count holds (FUN_00326dc0 and the table at 0x3f3260)
static uint32_t wholePrims(int kind, int n)
{
    switch (kind) {
    case kPrimTriList: return (uint32_t)(n / 3 * 3);
    case kPrimTriStrip: return n >= 3 ? (uint32_t)n : 0;
    case kPrimLineList: return (uint32_t)(n / 2 * 2);
    case kPrimLineStrip: return n >= 2 ? (uint32_t)n : 0;
    default: return n > 0 ? (uint32_t)n : 0;
    }
}

static void drawBuffer(bgfxContext* ctx, bgfxShader* sh, bgfxPrimBuffer* b, const char* program)
{
    bgfxContext::DrawSource src;
    memset(&src, 0, sizeof(src));
    src.kind = b->m_kind;
    src.flags = b->m_flags;
    src.program = program;
    src.vertexCount = (uint32_t)b->m_vertexCount;
    src.transient = kNone;
    src.owner = b->m_serial;
    src.vb = src.ib = kNone;
    bool indexed = b->m_indexCount > 0;
    int n = indexed ? b->m_indexCount : b->m_vertexCount;
    if (b->m_overrideCount)
        n = b->m_overrideCount;
    src.count = wholePrims(b->m_kind, n);
    if (b->prepare()) {
        src.vb = b->m_vb;
        if (indexed)
            src.ib = b->m_ib;
    } else if (ctx->m_display && ctx->m_display->m_initialised) {
        return;
    }
    ctx->draw(sh, src);
}


// 0x327d20 for our shaders: a shader that isn't the last one activated deactivates that one (slot 13) and
// activates itself (slot 12); then the pass (slot 14)
static bgfxShader* s_activeShader;
void shaderDestroyed(bgfxShader* sh)
{
    if (s_activeShader == sh)
        s_activeShader = 0;
}

void bgfxContext::beginPass(bgfxShader* sh, int pass)
{
    if (sh != s_activeShader) {
        if (s_activeShader)
            s_activeShader->vfunc_13();
        s_activeShader = sh;
        sh->vfunc_12();
    }
    sh->vfunc_14(pass);
}

// context slot 32 and d3dExtHardwareSkinning::vfunc_6: every pass of the shader draws the buffer
void bgfxContext::drawPrimBuffer(bgfxShader* sh, bgfxPrimBuffer* b, const char* program)
{
    if (!sh)
        sh = m_defaultShader;
    if (!b)
        return;
    int passes = sh->vfunc_11();
    for (int i = 0; i < passes; i++) {
        beginPass(sh, i);
        drawBuffer(this, sh, b, program);
    }
}

} // namespace pddi
} // namespace hulk
