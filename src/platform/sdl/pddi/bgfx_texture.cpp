// bgfxTexture (stands in for pure3d::d3dTexture).
#include "bgfx_pddi.h"

namespace hulk {
namespace pddi {

bgfxTexture::bgfxTexture(bgfxContext* context)
    : m_context(context), m_handle(0xffff), m_width(0), m_height(0), m_format(0), m_mips(0)
{
}

bgfxTexture::~bgfxTexture() {}

// ---- slots
unsigned int bgfxTexture::vfunc_4() { PDDI_STUB(4); return 0; }
unsigned int bgfxTexture::vfunc_5() { PDDI_STUB(5); return 0; }
int bgfxTexture::vfunc_6() { PDDI_STUB(6); return 0; }
unsigned int bgfxTexture::vfunc_7() { PDDI_STUB(7); return 0; }
int bgfxTexture::vfunc_8() { PDDI_STUB(8); return 0; }
unsigned int bgfxTexture::vfunc_9() { PDDI_STUB(9); return 0; }
unsigned int bgfxTexture::vfunc_10() { PDDI_STUB(10); return 0; }
void bgfxTexture::vfunc_11(unsigned int a0, void* a1) { PDDI_STUB(11); }
void bgfxTexture::vfunc_12(int a0) { PDDI_STUB(12); }
void bgfxTexture::vfunc_13(int a0, int a1) { PDDI_STUB(13); }
void bgfxTexture::vfunc_14(int a0) { PDDI_STUB(14); }
void bgfxTexture::vfunc_15(int a0, int a1, int a2) { PDDI_BASE_V(15, FUN_00325ee0(a0, a1, a2)); }
void bgfxTexture::vfunc_16() { PDDI_STUB(16); }
void bgfxTexture::vfunc_17() { PDDI_STUB(17); }
void bgfxTexture::vfunc_18(unsigned int a0) { PDDI_STUB(18); }
unsigned int bgfxTexture::vfunc_19() { PDDI_STUB(19); return 0; }
void bgfxTexture::vfunc_20(int a0, int a1, int a2, int a3, int a4, int a5, int a6) { PDDI_BASE_V(20, FUN_00325ef0(a0, a1, a2, a3, a4, a5, a6)); }
} // namespace pddi
} // namespace hulk
