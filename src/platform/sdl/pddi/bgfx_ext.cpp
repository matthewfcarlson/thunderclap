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
unsigned int bgfxExtHardwareSkinning::vfunc_1(unsigned int a0) { PDDI_STUB(1); return 0; }
void bgfxExtHardwareSkinning::vfunc_2() { PDDI_STUB(2); }
void bgfxExtHardwareSkinning::vfunc_3() { PDDI_STUB(3); }
void bgfxExtHardwareSkinning::vfunc_4(int a0) { PDDI_STUB(4); }
void bgfxExtHardwareSkinning::vfunc_5(int a0, int a1) { PDDI_STUB(5); }
void bgfxExtHardwareSkinning::vfunc_6(int a0, int a1) { PDDI_STUB(6); }

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
