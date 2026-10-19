// bgfxPrimBuffer, bgfxPrimBufferStream, bgfxPrimStream (stand in for d3dPrimBuffer, d3dPrimBufferStream,
// d3dPrimStream). Specification: the verified pure3d/d3dPrimBufferStream.cpp (0x326e90..0x3278e0) and d3dDevice's
// slot 10 (0x31b960); the bgfx side (conversion, buffers, the draw) is in bgfx_draw.cpp.
#include "bgfx_pddi.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

namespace hulk {
namespace pddi {

enum { kNoHandle = 0xffff };

static const unsigned kKindToD3D[5] = {5, 6, 2, 4, 1};      // 0x4d3ea8 (the same as 0x4d3650)

// ---------------------------------------------------------------------------------------------
// bgfxPrimBuffer
// The game: FUN_003277b0 (the fields), then FUN_00327860(kind, flags, 0, vertices, indices, program): the D3D
// primitive type, the vertex program ("skin" / "skin_onebone" for skinned flags when the block names none; the
// lookup builds the declaration with packed normals and weights), the vertex buffer (FUN_003270c0: stride x count)
// and the index buffer (FUN_00327130: 2 bytes an index).
bgfxPrimBuffer::bgfxPrimBuffer(bgfxContext* context, int kind, unsigned flags, int vertexCount, int indexCount,
                               const char* program)
    : m_base8(1), m_baseC(0), m_d3dPrim(kind >= 0 && kind < 5 ? kKindToD3D[kind] : 0), m_kind(kind), m_flags(flags),
      m_vertexCount(vertexCount > 0 ? vertexCount : 0), m_indexCapacity(indexCount > 0 ? indexCount : 0),
      m_indexCount(0), m_overrideCount(0), m_indices(0), m_vertices(0), m_locked(0), m_indexLocked(0),
      m_rawLocked(0), pad37(0), m_context(context), m_program(""), m_stride(packedStride(flags)),
      m_vertsDirty(false), m_indicesDirty(false), m_uploads(0), m_vb(kNoHandle), m_ib(kNoHandle),
      m_dynamicVb(false), m_dynamicIb(false)
{
    if ((flags & 0x80) && !(program && *program))
        m_program = (flags & 0x100) ? "skin" : "skin_onebone";
    else if (program)
        m_program = program;
    if (m_vertexCount)
        m_vertices = (char*)calloc((size_t)m_vertexCount, (size_t)m_stride);
    if (m_indexCapacity)
        m_indices = (unsigned short*)calloc((size_t)m_indexCapacity, 2);
}

bgfxPrimBuffer::~bgfxPrimBuffer()
{
    free(m_vertices);
    free(m_indices);
    releaseBuffers(m_vb, m_dynamicVb, m_ib, m_dynamicIb);
}

// slot 4 (0x327190): lock the vertices -> a stream laid out over them (the game takes one of four records at
// 0x4d3ed0; each buffer has its own here)
void* bgfxPrimBuffer::vfunc_4()
{
    m_locked = 1;
    m_stream.active = 1;
    m_stream.format = this;
    m_stream.arg = 0;
    m_stream.layout(m_vertices, m_flags, m_stride);
    return &m_stream;
}
// slot 5 (0x3271f0): unlock (the stream given back): the vertices changed
void bgfxPrimBuffer::vfunc_5(void* stream)
{
    m_locked = 0;
    if (stream)
        ((bgfxPrimBufferStream*)stream)->active = 0;
    m_vertsDirty = true;
}
void bgfxPrimBuffer::vfunc_6() { PDDI_BASE_V(6, FUN_00326d60()); }
// slot 7 (0x327200): lock the indices -> where to write them (16-bit)
unsigned int bgfxPrimBuffer::vfunc_7()
{
    m_indexLocked = 1;
    return (unsigned int)(uintptr_t)m_indices;
}
// slot 8 (0x327220): unlock the indices, n of them in use
void bgfxPrimBuffer::vfunc_8(unsigned int n)
{
    m_indexLocked = 0;
    m_indexCount = (int)n > m_indexCapacity ? m_indexCapacity : (int)n;
    m_indicesDirty = true;
}
// slot 9 (0x3272b0): copy n indices in
void bgfxPrimBuffer::vfunc_9(void* src, int n)
{
    if (n > m_indexCapacity)
        n = m_indexCapacity;
    if (n > 0 && src)
        memcpy(m_indices, src, (size_t)n * 2);
    m_indexCount = n > 0 ? n : 0;
    m_indicesDirty = true;
}
// slot 10 (0x327230): a capability query: true for 0x20001 only
bool bgfxPrimBuffer::vfunc_10(int what) { return what == 0x20001; }
// slot 11 (0x327250): lock the vertices raw (the packed layout) -> the first vertex
unsigned int bgfxPrimBuffer::vfunc_11(int)
{
    m_locked = 1;
    m_rawLocked = 1;
    return (unsigned int)(uintptr_t)m_vertices;
}
// slot 12 (0x327280): the raw unlock
void bgfxPrimBuffer::vfunc_12()
{
    m_rawLocked = 0;
    m_locked = 0;
    m_vertsDirty = true;
}
void bgfxPrimBuffer::vfunc_13(int, int) {}                  // empty in the game (0x3272a0)
// slot 14 (0x3270a0): draw only this many vertices or indices (0: all)
void bgfxPrimBuffer::vfunc_14(int n) { m_overrideCount = n; }

// ---------------------------------------------------------------------------------------------
// bgfxPrimBufferStream
bgfxPrimBufferStream::bgfxPrimBufferStream()
    : active(0), format(0), base(0), written(0), arg(0), stride(0), texCount(0), colourSets(0), position(0),
      normal(0), packedNormal(0), colours(0), colour2(0), uv(0), indices(0), weights(0)
{
    pad5[0] = pad5[1] = pad5[2] = 0;
    for (int i = 0; i < 4; i++)
        extra[i] = 0;
}

// FUN_00326e90: pointers to each attribute of the first vertex (the packed layout: normals and weights 32 bits)
void bgfxPrimBufferStream::layout(char* data, unsigned flags, int vertexStride)
{
    int w, ix, n, c, c2, t, e[4];
    packedOffsets(flags, &w, &ix, &n, &c, &c2, &t, e);
    base = data;
    written = 0;
    stride = vertexStride;
    texCount = (int)(flags & 15);
    colourSets = (flags & 0x20) ? 1 : ((flags & 0x4000) ? (int)((flags >> 15) & 7) : 0);
    position = data;
    normal = 0;
    packedNormal = n >= 0 && data ? (unsigned*)(data + n) : 0;
    colours = c >= 0 && data ? (unsigned*)(data + c) : 0;
    colour2 = c2 >= 0 && data ? (unsigned*)(data + c2) : 0;
    uv = t >= 0 && data ? (float*)(data + t) : 0;
    for (int i = 0; i < 4; i++)
        extra[i] = e[i] >= 0 && data ? data + e[i] : 0;
    indices = ix >= 0 && data ? (unsigned char*)(data + ix) : 0;
    weights = w >= 0 && data ? (unsigned*)(data + w) : 0;
}

// FUN_00326f90: the next vertex (every attribute pointer moves by the stride); past the end, writes are dropped
void bgfxPrimBufferStream::next()
{
    written++;
    bgfxPrimBuffer* b = (bgfxPrimBuffer*)format;
    if (b && written >= b->m_vertexCount) {
        position = 0;
        normal = 0;
        packedNormal = 0;
        colours = colour2 = 0;
        uv = 0;
        indices = 0;
        weights = 0;
        for (int i = 0; i < 4; i++)
            extra[i] = 0;
        return;
    }
    position += stride;
    if (packedNormal) packedNormal = (unsigned*)((char*)packedNormal + stride);
    if (normal) normal = (float*)((char*)normal + stride);
    if (colours) colours = (unsigned*)((char*)colours + stride);
    if (colour2) colour2 = (unsigned*)((char*)colour2 + stride);
    if (uv) uv = (float*)((char*)uv + stride);
    if (indices) indices += stride;
    if (weights) weights = (unsigned*)((char*)weights + stride);
    for (int i = 0; i < 4; i++)
        if (extra[i])
            extra[i] += stride;
}

// 11:11:10 as slot 1 packs a normal (scaled by 1/(|n| x 1.001) first) and slot 11 a weight triple
static unsigned pack3(float x, float y, float z, double scale, float k)
{
    int iy = (int)((double)y * scale * k);
    int iz = (int)((double)z * scale * k);
    int ix = (int)((double)x * scale * k);
    unsigned bits = ((unsigned)(iy >> 21) & 0x7ffu) | ((unsigned)(iz >> 22) << 11);
    return (bits << 11) | ((unsigned)(ix >> 21) & 0x7ffu);
}

static double invLength(float x, float y, float z)
{
    double l2 = (double)x * x + (double)y * y + (double)z * z;
    if (l2 <= 0.0)
        return 0.0;
    double r = l2;                           // sqrt by Newton's method (no CRT in the image's graphics objects)
    for (int i = 0; i < 40; i++)
        r = 0.5 * (r + l2 / r);
    return 1.0 / (r * 1.001f);
}

// slot 0 (0x327450): position, next vertex
void bgfxPrimBufferStream::vfunc_0(float x, float y, float z)
{
    if (position) {
        float* p = (float*)position;
        p[0] = x;
        p[1] = y;
        p[2] = z;
    }
    next();
}
// slot 1 (0x327480): normal (packed when the layout packs normals)
void bgfxPrimBufferStream::vfunc_1(float x, float y, float z)
{
    if (packedNormal) {
        *packedNormal = pack3(x, y, z, invLength(x, y, z), 2147483648.0f);
    } else if (normal) {
        normal[0] = x;
        normal[1] = y;
        normal[2] = z;
    }
}
// slots 2/3 (0x327530, 0x327550): the 0x800 and 0x1000 vectors
void bgfxPrimBufferStream::vfunc_2(unsigned long a, unsigned long b, unsigned long c)
{
    if (extra[2]) {
        unsigned* p = (unsigned*)extra[2];
        p[0] = (unsigned)a;
        p[1] = (unsigned)b;
        p[2] = (unsigned)c;
    }
}
void bgfxPrimBufferStream::vfunc_3(unsigned int a, unsigned int b, unsigned int c)
{
    if (extra[3]) {
        unsigned* p = (unsigned*)extra[3];
        p[0] = a;
        p[1] = b;
        p[2] = c;
    }
}
// slot 4 (0x327570): colour of set i
void bgfxPrimBufferStream::vfunc_4(int colour, int set)
{
    if (colours && set >= 0 && set < (colourSets > 0 ? colourSets : 1))
        colours[set] = (unsigned)colour;
}
void bgfxPrimBufferStream::vfunc_5(int, int) {}            // empty in the game (0x327420)
// slot 6 (0x327590): uv of set i
void bgfxPrimBufferStream::vfunc_6(float u, float v, int set)
{
    if (uv && set >= 0 && set < texCount) {
        uv[set * 2] = u;
        uv[set * 2 + 1] = v;
    }
}
void bgfxPrimBufferStream::vfunc_7(int, int, int, int) {}  // empty (0x327430)
void bgfxPrimBufferStream::vfunc_8(int, int, int, int, int) {}     // empty (0x327440)
// slot 9 (0x3275b0): the second colour (0x40)
void bgfxPrimBufferStream::vfunc_9(unsigned int colour)
{
    if (colour2)
        *colour2 = colour;
}
// slot 10 (0x3275c0): three bone indices (x 3: the program's rows per bone) and a fourth, in D3DCOLOR byte order
void bgfxPrimBufferStream::vfunc_10(char a, char b, char c, char d)
{
    if (indices) {
        indices[0] = (unsigned char)(c * 3);
        indices[1] = (unsigned char)(b * 3);
        indices[2] = (unsigned char)(a * 3);
        indices[3] = (unsigned char)(d * 3);
    }
}
// slot 11 (0x327600): the blend weights, packed 11:11:10 (no normalisation)
void bgfxPrimBufferStream::vfunc_11(float x, float y, float z)
{
    if (weights)
        *weights = pack3(x, y, z, 1.0, 2147418112.0f);
}
// slot 12 (0x327750): position, normal, uv 0, next
void bgfxPrimBufferStream::vfunc_12(const float* p, const float* n, const float* t)
{
    if (position)
        memcpy(position, p, 12);
    vfunc_1(n[0], n[1], n[2]);
    if (uv)
        memcpy(uv, t, 8);
    next();
}
// slot 13 (0x327710): position, colour, uv 0, next
void bgfxPrimBufferStream::vfunc_13(const float* p, unsigned int c, const float* t)
{
    if (position)
        memcpy(position, p, 12);
    if (colours)
        *colours = c;
    if (uv)
        memcpy(uv, t, 8);
    next();
}
// slot 14 (0x3276d0): position, uv 0, next
void bgfxPrimBufferStream::vfunc_14(const float* p, const float* t)
{
    if (position)
        memcpy(position, p, 12);
    if (uv)
        memcpy(uv, t, 8);
    next();
}
// slot 15 (0x327690): position, normal, next
void bgfxPrimBufferStream::vfunc_15(const float* p, const float* n)
{
    if (position)
        memcpy(position, p, 12);
    vfunc_1(n[0], n[1], n[2]);
    next();
}
// slot 16 (0x327660): position, colour, next
void bgfxPrimBufferStream::vfunc_16(const float* p, unsigned int c)
{
    if (position)
        memcpy(position, p, 12);
    if (colours)
        *colours = c;
    next();
}
// slot 17 (0x3277a0): next vertex
void bgfxPrimBufferStream::vfunc_17() { next(); }

// ---------------------------------------------------------------------------------------------
// bgfxPrimStream
bgfxPrimStream::bgfxPrimStream(bgfxContext* context)
    : stride(12), posPtr(m_data), normalPtr(0), colorPtr(0), uvPtr(0), limit(0), vertCount(0), retained(0),
      m_context(context), m_shader(0), m_kind(0), m_flags(0), m_uvCount(0), m_colourSets(0), m_pendingTotal(0)
{
    memset(m_carry, 0, sizeof(m_carry));
}

static const int kRetained[5] = {0, 2, 0, 1, 0};             // 0x4d3664: what a full batch hands on, per kind

// What the context's begin-prims does before handing the stream out (0x31bd30): note the shader, kind and vertex
// flags, the batch limit (a multiple of 6 vertices), what a full batch carries over, then start the batch.
void bgfxPrimStream::begin(bgfxShader* shader, int kind, unsigned flags, int count)
{
    m_shader = shader;
    m_kind = kind;
    m_flags = flags;
    m_uvCount = (int)(flags & kVertexUvMask);
    m_colourSets = (flags & kVertexColour) ? 1 : ((flags & kVertexColourSets) ? (int)((flags >> 15) & 7) : 0);
    int vstride = 12 + ((flags & kVertexNormal) ? 12 : 0) + 4 * m_colourSets + 8 * m_uvCount;
    limit = (int)(sizeof(m_data) / (unsigned)vstride) / 6 * 6;
    retained = kind >= 0 && kind < 5 ? kRetained[kind] : 0;
    m_pendingTotal = count;
    vertCount = 0;
    vfunc_0(false);
}

// slot 0 (0x31be40): start a batch: with carry, the vertices FUN_0008ef00 kept at +0x24 first; then the vertex
// layout from the flags (position; 0x10 normal; 0x20 one colour or 0x4000 colour sets; uv sets) and the pointers
// at the next vertex
void bgfxPrimStream::vfunc_0(bool carry)
{
    char* p = m_data;
    if (carry && retained > 0) {
        memcpy(p, m_carry, (size_t)(stride * retained));
        p += stride * retained;
        vertCount = retained;
    } else {
        vertCount = 0;
    }
    posPtr = p;
    stride = 12;
    p += 12;
    normalPtr = 0;
    if (m_flags & kVertexNormal) {
        normalPtr = p;
        stride += 12;
        p += 12;
    }
    colorPtr = 0;
    if (m_colourSets > 0) {
        colorPtr = p;
        stride += 4 * m_colourSets;
        p += 4 * m_colourSets;
    }
    uvPtr = 0;
    if (m_uvCount) {
        uvPtr = p;
        stride += 8 * m_uvCount;
    }
}

// slot 1 (0x31c080): draw what was written (a strip needs 3, a line strip 2) and empty the batch
void bgfxPrimStream::vfunc_1()
{
    if (vertCount > 0 && !(m_kind == kPrimTriStrip && vertCount <= 2) && !(m_kind == kPrimLineStrip && vertCount <= 1))
        m_context->submit(this);
    m_pendingTotal -= vertCount;
    vertCount = 0;
}

// FUN_0008ef00: one vertex written: the next, or at the batch's limit, keep the last `retained` vertices at +0x24,
// draw (slot 1) and start the next batch with them (slot 0, carry)
void bgfxPrimStream::vertex()
{
    ++vertCount;
    if (vertCount != limit) {
        posPtr += stride;
        if (normalPtr)
            normalPtr += stride;
        if (colorPtr)
            colorPtr += stride;
        if (uvPtr)
            uvPtr += stride;
        return;
    }
    if (retained > 0)
        memcpy(m_carry, posPtr - stride * (retained - 1), (size_t)(stride * retained));
    vfunc_1();
    vfunc_0(true);
}

} // namespace pddi
} // namespace hulk
