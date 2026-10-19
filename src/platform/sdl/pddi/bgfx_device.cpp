// bgfxDevice: the device and its factories (stands in for pure3d::d3dDevice).
#include "bgfx_pddi.h"

namespace hulk {
namespace pddi {

bgfxDevice::bgfxDevice() : m_lastError(0), m_display(0), m_context(0) {}

bgfxDevice::~bgfxDevice() {}

// ---- slots (generated stubs, then implemented by hand)
void bgfxDevice::vfunc_4(int a0) { PDDI_STUB(4); }
void bgfxDevice::vfunc_5(void* a0) { m_display = (bgfxDisplay*)a0; }
void* bgfxDevice::vfunc_6() { return m_display; }
void* bgfxDevice::vfunc_7(int a0) { return new bgfxDisplay(this); }
void* bgfxDevice::vfunc_8(void* a0)
{
    // the game: new d3dContext(display, this); here the display argument is ours
    m_context = new bgfxContext((bgfxDisplay*)a0, this);
    return m_context;
}
void* bgfxDevice::vfunc_9(int a0)
{
    PDDI_STUB(9);     // G1: the texture parameter block (size, format, mips, usage) -> bgfxTexture
    return new bgfxTexture(m_context);
}
void* bgfxDevice::vfunc_10(void* a0)
{
    PDDI_STUB(10);    // G1/G3: the prim buffer parameter block -> static buffers
    return new bgfxPrimBuffer(m_context);
}
void bgfxDevice::vfunc_11(int a0, int a1) { PDDI_STUB(11); }
void bgfxDevice::vfunc_12(int a0, int a1) { PDDI_STUB(12); }
void bgfxDevice::vfunc_13(int a0) { PDDI_BASE_V(13, FUN_0031e230(a0)); }
} // namespace pddi
} // namespace hulk
