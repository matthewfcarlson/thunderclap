// bgfxPrimBuffer, bgfxPrimBufferStream, bgfxPrimStream (stand in for d3dPrimBuffer,
// d3dPrimBufferStream, d3dPrimStream).
#include "bgfx_pddi.h"

namespace hulk {
namespace pddi {

bgfxPrimBuffer::bgfxPrimBuffer(bgfxContext* context) : m_context(context), m_vb(0xffff), m_ib(0xffff) {}

bgfxPrimBuffer::~bgfxPrimBuffer() {}

bgfxPrimBufferStream::bgfxPrimBufferStream(bgfxPrimBuffer* buffer) : m_buffer(buffer) {}

// ---- bgfxPrimStream
bgfxPrimStream::bgfxPrimStream(bgfxContext* context)
    : stride(12), posPtr(m_data), normalPtr(0), colorPtr(0), uvPtr(0), pad18(0), vertCount(0), pendingCount(0),
      m_context(context), m_shader(0), m_kind(0), m_flags(0), m_uvCount(0)
{
}

// What the context's begin-prims does before handing the stream out (0x31bd30): note the shader, kind and vertex
// flags, then (re)start the batch.
void bgfxPrimStream::begin(bgfxShader* shader, int kind, unsigned flags, int count)
{
    m_shader = shader;
    m_kind = kind;
    m_flags = flags;
    m_uvCount = (int)(flags & kVertexUvMask);
    pendingCount = count;
    vfunc_0(false);
}

// slot 0 (0x31be40): start a batch: the vertex layout from the flags (position; normal with 0x10; one colour with
// 0x20; uv sets from the low bits), pointers at the first vertex. Carrying pending vertices over (strips split
// across batches) is G1.
void bgfxPrimStream::vfunc_0(bool carry)
{
    char* p = m_data;
    vertCount = 0;
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
    if (m_flags & kVertexColour) {
        colorPtr = p;
        stride += 4;
        p += 4;
    }
    uvPtr = 0;
    if (m_uvCount) {
        uvPtr = p;
        stride += 8 * m_uvCount;
    }
}

// slot 1 (0x31c080): draw what was written (strips need 3, lines 2) and start over
void bgfxPrimStream::vfunc_1()
{
    m_context->submit(this);
    pendingCount -= vertCount;
    vfunc_0(false);
}

// After the engine wrote one vertex through the pointers: advance them (the game's FUN_0008ef00, game code that
// stays in the native image, does this itself on the game's stream layout above)
void bgfxPrimStream::vertex()
{
    posPtr += stride;
    if (normalPtr)
        normalPtr += stride;
    if (colorPtr)
        colorPtr += stride;
    if (uvPtr)
        uvPtr += stride;
    vertCount++;
    if ((vertCount + 1) * stride > (int)sizeof(m_data)) {
        vfunc_1();
    }
}

// ---- bgfxPrimBuffer slots
void* bgfxPrimBuffer::vfunc_4() { PDDI_STUB(4); return 0; }
void bgfxPrimBuffer::vfunc_5(void* a0) { PDDI_STUB(5); }
void bgfxPrimBuffer::vfunc_6() { PDDI_BASE_V(6, FUN_00326d60()); }
unsigned int bgfxPrimBuffer::vfunc_7() { PDDI_STUB(7); return 0; }
void bgfxPrimBuffer::vfunc_8(unsigned int a0) { PDDI_STUB(8); }
void bgfxPrimBuffer::vfunc_9(void* a0, int a1) { PDDI_STUB(9); }
bool bgfxPrimBuffer::vfunc_10(int a0) { PDDI_STUB(10); return false; }
unsigned int bgfxPrimBuffer::vfunc_11(int a0) { PDDI_STUB(11); return 0; }
void bgfxPrimBuffer::vfunc_12() { PDDI_STUB(12); }
void bgfxPrimBuffer::vfunc_13(int a0, int a1) { PDDI_STUB(13); }
void bgfxPrimBuffer::vfunc_14(int a0) { PDDI_STUB(14); }

// ---- bgfxPrimBufferStream slots
void bgfxPrimBufferStream::vfunc_0(int a0, int a1, int a2) { PDDI_STUB(0); }
void bgfxPrimBufferStream::vfunc_1(int a0, int a1, int a2) { PDDI_STUB(1); }
void bgfxPrimBufferStream::vfunc_2(unsigned long a0, unsigned long a1, unsigned long a2) { PDDI_STUB(2); }
void bgfxPrimBufferStream::vfunc_3(unsigned int a0, unsigned int a1, unsigned int a2) { PDDI_STUB(3); }
void bgfxPrimBufferStream::vfunc_4(int a0, int a1) { PDDI_STUB(4); }
void bgfxPrimBufferStream::vfunc_5(int a0, int a1) { PDDI_STUB(5); }
void bgfxPrimBufferStream::vfunc_6(float a0, float a1, int a2) { PDDI_STUB(6); }
void bgfxPrimBufferStream::vfunc_7(int a0, int a1, int a2, int a3) { PDDI_STUB(7); }
void bgfxPrimBufferStream::vfunc_8(int a0, int a1, int a2, int a3, int a4) { PDDI_STUB(8); }
void bgfxPrimBufferStream::vfunc_9(unsigned int a0) { PDDI_STUB(9); }
void bgfxPrimBufferStream::vfunc_10(char a0, char a1, char a2, char a3) { PDDI_STUB(10); }
void bgfxPrimBufferStream::vfunc_11(int a0, int a1, int a2) { PDDI_STUB(11); }
void bgfxPrimBufferStream::vfunc_12(int a0, int a1, int a2) { PDDI_STUB(12); }
void bgfxPrimBufferStream::vfunc_13(int a0, int a1, int a2) { PDDI_STUB(13); }
void bgfxPrimBufferStream::vfunc_14(int a0, int a1) { PDDI_STUB(14); }
void bgfxPrimBufferStream::vfunc_15(void* a0, void* a1) { PDDI_STUB(15); }
void bgfxPrimBufferStream::vfunc_16(int a0, int a1) { PDDI_STUB(16); }
void bgfxPrimBufferStream::vfunc_17() { PDDI_STUB(17); }
} // namespace pddi
} // namespace hulk
