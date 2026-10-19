// The pddi extensions (stubs).
#include "bgfx_pddi.h"

namespace hulk {
namespace pddi {

// ---- bgfxExtAntialiasControl
void bgfxExtAntialiasControl::vfunc_1(unsigned char a0) { PDDI_STUB(1); }
void bgfxExtAntialiasControl::vfunc_2(unsigned char a0) { PDDI_STUB(2); }
void bgfxExtAntialiasControl::vfunc_3() { PDDI_STUB(3); }
unsigned int bgfxExtAntialiasControl::vfunc_4() { PDDI_STUB(4); return 0; }

// ---- bgfxExtFrameBufferTexture
void* bgfxExtFrameBufferTexture::vfunc_1(int a0) { PDDI_STUB(1); return 0; }
void bgfxExtFrameBufferTexture::vfunc_2() { PDDI_STUB(2); }

// ---- bgfxExtFramebufferEffects
void bgfxExtFramebufferEffects::vfunc_1(unsigned char a0, int a1, int a2, unsigned char a3) { PDDI_STUB(1); }
void bgfxExtFramebufferEffects::vfunc_2() { PDDI_STUB(2); }
void bgfxExtFramebufferEffects::vfunc_3(unsigned char a0) { PDDI_STUB(3); }
void bgfxExtFramebufferEffects::vfunc_4(int a0, int a1, int a2, int a3, int a4) { PDDI_STUB(4); }
void bgfxExtFramebufferEffects::vfunc_5() { PDDI_STUB(5); }
void bgfxExtFramebufferEffects::vfunc_6() { PDDI_STUB(6); }
void bgfxExtFramebufferEffects::vfunc_7(unsigned char a0) { PDDI_STUB(7); }
void bgfxExtFramebufferEffects::vfunc_8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) { PDDI_STUB(8); }
void bgfxExtFramebufferEffects::vfunc_9() { PDDI_STUB(9); }
void bgfxExtFramebufferEffects::vfunc_10(int a0) { PDDI_STUB(10); }

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
    const char* program = buffer->m_program;
    if (shader->m_kind == kShaderRefract)
        program = "skin_refract";
    m_context->drawPrimBuffer(shader, buffer, program);
    shader->m_skinned = false;
}

// ---- bgfxExtReadPixels
void bgfxExtReadPixels::vfunc_1(void* a0, void* a1, void* a2) { PDDI_STUB(1); }

// ---- bgfxExtVertexProgram
void bgfxExtVertexProgram::vfunc_1() { PDDI_STUB(1); }
void bgfxExtVertexProgram::vfunc_2(int a0, int a1, int a2, int a3, int a4) { PDDI_STUB(2); }
void bgfxExtVertexProgram::vfunc_3() { PDDI_STUB(3); }
void bgfxExtVertexProgram::vfunc_4(void* a0, char a1) { PDDI_STUB(4); }
void bgfxExtVertexProgram::vfunc_5(int a0, int a1) { PDDI_STUB(5); }
void bgfxExtVertexProgram::vfunc_6(unsigned int a0) { PDDI_STUB(6); }
void bgfxExtVertexProgram::vfunc_7(int a0, int a1, int a2) { PDDI_STUB(7); }
void bgfxExtVertexProgram::vfunc_8(int a0, int a1) { PDDI_STUB(8); }

// ---- bgfxExtVisibilityTest
unsigned int bgfxExtVisibilityTest::vfunc_1() { PDDI_STUB(1); return 0; }
void bgfxExtVisibilityTest::vfunc_2() { PDDI_STUB(2); }
void bgfxExtVisibilityTest::vfunc_3() { PDDI_STUB(3); }
unsigned int bgfxExtVisibilityTest::vfunc_4(int a0) { PDDI_STUB(4); return 0; }

} // namespace pddi
} // namespace hulk
