// The pddi extensions (stubs).
#include "bgfx_pddi.h"

#include <bgfx/bgfx.h>
#include <string.h>

namespace hulk {
namespace pddi {

// ---- bgfxExtAntialiasControl
// slot 1 (0x322000): D3DRS_MULTISAMPLEANTIALIAS. The scene target is not multisampled (an MSAA option is G5's):
// kept, not applied
void bgfxExtAntialiasControl::vfunc_1(unsigned char on) { m_on = on != 0; }
// slot 2 (0x322030): the context's clear-by-quad flag (+0x44c: slot 12 then draws a pixel-space quad instead of
// clearing). No game code calls it (the only user of this extension, BillboardQuadGroup FUN_002ba220, asks slot 4):
// kept and logged, not implemented
void bgfxExtAntialiasControl::vfunc_2(unsigned char v)
{
    m_quadClear = v != 0;
    if (v)
        PDDI_STUB(2);
}
// slot 3 (0x322010: a jump into the XDK's Direct3D, 0x386c60): no caller in the game; logged
void bgfxExtAntialiasControl::vfunc_3() { PDDI_STUB(3); }
// slot 4 (0x322020): the display's multisample type (+0x460): 0, none (BillboardQuadGroup counts one sample a pixel)
unsigned int bgfxExtAntialiasControl::vfunc_4() { return 0; }

// ---- bgfxExtFrameBufferTexture
void* bgfxExtFrameBufferTexture::vfunc_1(int a0) { PDDI_STUB(1); return 0; }
void bgfxExtFrameBufferTexture::vfunc_2() { PDDI_STUB(2); }

// ---- bgfxExtFramebufferEffects: bgfx_effects.cpp

// ---- bgfxExtGammaControl
void bgfxExtGammaControl::vfunc_1() { PDDI_STUB(1); }
void bgfxExtGammaControl::vfunc_2() { PDDI_STUB(2); }

// ---- bgfxExtGlobalProjectedTexture
void bgfxExtGlobalProjectedTexture::vfunc_1(int a0, void* a1, void* a2) { PDDI_STUB(1); }
bool bgfxExtGlobalProjectedTexture::vfunc_2(int a0, void* a1, void* a2) { PDDI_STUB(2); return false; }

// ---- bgfxExtHardwareSkinning
// slot 1 (0x3221e0): the most bones a draw can have: 25 (c113.. three rows each, up to c187)
unsigned int bgfxExtHardwareSkinning::vfunc_1(unsigned int) { return 0x19; }
void bgfxExtHardwareSkinning::vfunc_2() {}                 // empty in the game (0x322260)
void bgfxExtHardwareSkinning::vfunc_3() {}                 // empty (0x322270)
void bgfxExtHardwareSkinning::vfunc_4(int) {}              // empty (0x3221f0)
// slot 5 (0x322200): bone i's matrix: bone x the modelview (the base's stack 0 top, slot 18), transposed, three rows
// to c113 + 3i (the skin programs' relative constants)
void bgfxExtHardwareSkinning::vfunc_5(int bone, const float* matrix)
{
    if (!matrix || bone < 0 || bone >= 0x19)
        return;
    const float* mv = m_context->worldMatrix();
#if HULK_PDDI_GAME
    const uint32_t* stack = *(const uint32_t* const*)((const char*)m_context + 0x20);
    if (stack)
        mv = (const float*)(uintptr_t)stack[3] + 16 * stack[2];
#endif
    float r[16], t[12];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            r[i * 4 + j] = matrix[i * 4 + 0] * mv[0 * 4 + j] + matrix[i * 4 + 1] * mv[1 * 4 + j] +
                           matrix[i * 4 + 2] * mv[2 * 4 + j] + matrix[i * 4 + 3] * mv[3 * 4 + j];
    for (int row = 0; row < 3; row++)
        for (int k = 0; k < 4; k++)
            t[row * 4 + k] = r[k * 4 + row];
    m_context->setVertexConstants(0x71 + 3 * bone, t, 3);
}
// slot 6 (0x3245d0): draw a skinned prim buffer: the skin programs' constants (FUN_00324270), the shader marked
// skinned during the draw (+0x7d: the refraction shader picks skin_refract), every pass
void bgfxExtHardwareSkinning::vfunc_6(bgfxShader* shader, bgfxPrimBuffer* buffer)
{
    if (!shader || !buffer)
        return;
    m_context->skinConstants(shader);
    shader->m_skinned = true;
    if (shader->vfunc_22())                   // skin_refract's own constants (c188-c191)
        shader->vfunc_24();
    const char* program = buffer->m_program;
    if (shader->m_kind == kShaderRefract)
        program = "skin_refract";
    m_context->drawPrimBuffer(shader, buffer, program);
    shader->m_skinned = false;
}

// ---- bgfxExtReadPixels
void bgfxExtReadPixels::vfunc_1(void* a0, void* a1, void* a2) { PDDI_STUB(1); }

// ---- bgfxExtVertexProgram (the prim group loaders FUN_002e1960 / FUN_002e22c0 / FUN_002e30f0 / FUN_002e3bd0 ask
// slot 4, then slot 2 for the handle, then slot 5 to give it to the prim buffer, or keep it as a streamed prim
// group's binding, which PrimGroupStreamed::vfunc_6 (0x2df5a0) hands to slot 6 around its prim stream draws)
void bgfxExtVertexProgram::vfunc_1() { PDDI_STUB(1); }
// the handles: 1 + an index into the program names seen (a name pointer would not fit an int on 64-bit hosts)
static const char* s_vpNames[32];
static int vpHandle(const char* name)
{
    if (!name || !*name)
        return 0;
    for (int i = 0; i < 32; i++) {
        if (!s_vpNames[i])
            s_vpNames[i] = name;
        if (s_vpNames[i] == name || !strcmp(s_vpNames[i], name))
            return i + 1;
    }
    return 0;
}
static const char* vpName(unsigned handle)
{
    return handle >= 1 && handle <= 32 ? s_vpNames[handle - 1] : 0;
}

// slot 2 (0x322440): the shader's program for the vertex format (a, b, c: FUN_003290e0's flags; not needed: our draws
// convert every format to the backend's vertex); `skinned` sets the shader's +0x7d around the name lookup (slot 23:
// the refraction shader then names skin_refract)
int bgfxExtVertexProgram::vfunc_2(bgfxShader* shader, int, int, int, unsigned char skinned)
{
    if (!shader)
        return 0;
    bool was = shader->m_skinned;
    if (skinned)
        shader->m_skinned = true;
    const char* name = (const char*)shader->vfunc_23();
    if (skinned)
        shader->m_skinned = was;
    return vpHandle(name);
}
void bgfxExtVertexProgram::vfunc_3() { PDDI_STUB(3); }
// slot 4 (0x322360): whether the shader has program constants (slot 22: the refraction shader; the CBV programs of
// simple/layered when CBVP is set, which no data does), with +0x7d set around the question when `skinned`
bool bgfxExtVertexProgram::vfunc_4(bgfxShader* shader, unsigned char skinned)
{
    if (!shader)
        return false;
    bool was = shader->m_skinned;
    if (skinned)
        shader->m_skinned = true;
    bool r = shader->vfunc_22();
    if (skinned)
        shader->m_skinned = was;
    return r;
}
// slot 5 (0x322390): the prim buffer draws with this program (+0x3c)
void bgfxExtVertexProgram::vfunc_5(bgfxPrimBuffer* buffer, int handle)
{
    if (!buffer)
        return;
    const char* name = vpName((unsigned)handle);
    buffer->m_program = name ? name : "";
}
// slot 6 (0x3223a0): the program the following prim streams draw with (0: their own, fixed function)
void bgfxExtVertexProgram::vfunc_6(unsigned int handle) { m_context->m_streamProgram = vpName(handle); }
void bgfxExtVertexProgram::vfunc_7(int, int, int) { PDDI_STUB(7); }
void bgfxExtVertexProgram::vfunc_8(int, int) { PDDI_STUB(8); }

// ---- bgfxExtVisibilityTest (BillboardQuadGroup FUN_002ba220: a flare's occlusion: begin, one quad drawn with colour
// writes off, end(0), result(0) / the quad's area = how much of the flare shows)
// slot 1 (0x3222c0): how many tests there are: 0x4000
unsigned int bgfxExtVisibilityTest::vfunc_1() { return 0x4000; }
// slot 2 (0x3222d0, BeginVisibilityTest): the draws until slot 3 are a bgfx occlusion query. The Xbox answers at once
// (slot 4 spins until the GPU has); bgfx answers a frame or two later, so each test of a frame has a query of its own
// (the k-th test of every frame the k-th query) and slot 4 gives that query's latest answer: last frame's count for
// the same flare (0 until the first arrives)
void bgfxExtVisibilityTest::vfunc_2()
{
    bgfxContext* c = m_context;
    if (!c->m_display || !c->m_display->m_initialised)
        return;
    unsigned frame = c->m_display->m_frame;
    if (frame != m_frame) {
        m_frame = frame;
        m_next = 0;
    }
    if (m_next >= kQueries)
        return;
    if (m_query[m_next] == 0xffff) {
        bgfx::OcclusionQueryHandle h = bgfx::createOcclusionQuery();
        if (!bgfx::isValid(h)) {
            m_noQueries = true;               // no queries (this bgfx has no capability bit): every test passes all
            return;
        }
        m_query[m_next] = h.idx;
    }
    c->m_visQuery = m_query[m_next];
    m_current = (int)m_next++;
}
// slot 3 (0x3222e0, EndVisibilityTest(index)): the query is test `index`'s
void bgfxExtVisibilityTest::vfunc_3(int index)
{
    m_context->m_visQuery = 0xffff;
    if (index >= 0 && index < kIndices)
        m_byIndex[index] = m_current;
    m_current = -1;
}
// slot 4 (0x3222f0, GetVisibilityTestResult(index), waiting): the pixels that passed
unsigned int bgfxExtVisibilityTest::vfunc_4(int index)
{
    if (index < 0 || index >= kIndices || m_byIndex[index] < 0)
        return m_noQueries ? 0x7fffffffu : 0u;
    int q = m_byIndex[index];
    int32_t n = 0;
    bgfx::OcclusionQueryResult::Enum r = bgfx::getResult(bgfx::OcclusionQueryHandle{(uint16_t)m_query[q]}, &n);
    if (r == bgfx::OcclusionQueryResult::Visible)
        m_last[q] = (unsigned)n;
    else if (r == bgfx::OcclusionQueryResult::Invisible)
        m_last[q] = 0;
    return m_last[q];
}

bgfxExtVisibilityTest::bgfxExtVisibilityTest(bgfxContext* context)
    : m_context(context), m_frame(0xffffffffu), m_next(0), m_current(-1), m_noQueries(false)
{
    for (int i = 0; i < kQueries; i++) {
        m_query[i] = 0xffff;
        m_last[i] = 0;
    }
    for (int i = 0; i < kIndices; i++)
        m_byIndex[i] = -1;
}

} // namespace pddi
} // namespace hulk
