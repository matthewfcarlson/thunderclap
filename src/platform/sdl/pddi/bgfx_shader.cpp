// The shader classes: bgfxShader (d3dShader) and the kinds the game's data uses (docs/graphics-backend.md 2).
#include "bgfx_pddi.h"

namespace hulk {
namespace pddi {

bgfxShader::bgfxShader(bgfxContext* context) : m_context(context), m_kind(kShaderError)
{
    m_base[0] = m_base[1] = 0;
}

bgfxShader::~bgfxShader() {}

// ---- bgfxShader slots
void bgfxShader::vfunc_4() { PDDI_STUB(4); }
void bgfxShader::vfunc_5(int a0, int a1) { PDDI_BASE_V(5, FUN_003279e0(a0, a1)); }
bool bgfxShader::vfunc_6(int a0, int a1) { PDDI_BASE(6, FUN_00327a40(a0, a1)); }
unsigned char bgfxShader::vfunc_7(int a0, int a1) { PDDI_BASE(7, FUN_00327aa0(a0, a1)); }
void bgfxShader::vfunc_8(int a0, int a1) { PDDI_BASE_V(8, FUN_00327b00(a0, a1)); }
bool bgfxShader::vfunc_9(int a0, int a1) { PDDI_BASE(9, FUN_00327b60(a0, a1)); }
bool bgfxShader::vfunc_10(int a0, int a1) { PDDI_BASE(10, FUN_00327bc0(a0, a1)); }
int bgfxShader::vfunc_11() { PDDI_STUB(11); return 0; }
void bgfxShader::vfunc_12() { PDDI_STUB(12); }
void bgfxShader::vfunc_13() { PDDI_STUB(13); }
void bgfxShader::vfunc_14(int a0) { PDDI_STUB(14); }
void bgfxShader::vfunc_15() { PDDI_BASE_V(15, FUN_00327980()); }
void bgfxShader::vfunc_16() { PDDI_BASE_V(16, FUN_00327990()); }
void bgfxShader::vfunc_17() { PDDI_BASE_V(17, FUN_003279a0()); }
void bgfxShader::vfunc_18() { PDDI_BASE_V(18, FUN_003279b0()); }
void bgfxShader::vfunc_19() { PDDI_BASE_V(19, FUN_003279c0()); }
void bgfxShader::vfunc_20() { PDDI_BASE_V(20, FUN_003279d0()); }
void bgfxShader::vfunc_21(void* a0) { PDDI_STUB(21); }
bool bgfxShader::vfunc_22() { PDDI_STUB(22); return false; }
void* bgfxShader::vfunc_23() { PDDI_STUB(23); return 0; }
void bgfxShader::vfunc_24() { PDDI_STUB(24); }

// ---- bgfxSimpleShader (d3dSimpleShader)
bgfxSimpleShader::bgfxSimpleShader(bgfxContext* context) : bgfxShader(context) { m_kind = kShaderSimple; }
void bgfxSimpleShader::vfunc_4() { PDDI_STUB(4); }
int bgfxSimpleShader::vfunc_11() { PDDI_STUB(11); return 0; }
void bgfxSimpleShader::vfunc_14(int a0) { PDDI_STUB(14); }
void bgfxSimpleShader::vfunc_15() { PDDI_STUB(15); }
void bgfxSimpleShader::vfunc_16() { PDDI_STUB(16); }
void bgfxSimpleShader::vfunc_17() { PDDI_STUB(17); }
void bgfxSimpleShader::vfunc_18() { PDDI_STUB(18); }
void bgfxSimpleShader::vfunc_21(void* a0) { PDDI_STUB(21); }
bool bgfxSimpleShader::vfunc_22() { PDDI_STUB(22); return false; }
void* bgfxSimpleShader::vfunc_23() { PDDI_STUB(23); return 0; }
void bgfxSimpleShader::vfunc_24() { PDDI_STUB(24); }

// ---- bgfxLayeredShader (d3dLayeredShader)
bgfxLayeredShader::bgfxLayeredShader(bgfxContext* context) : bgfxShader(context) { m_kind = kShaderLayered; }
void bgfxLayeredShader::vfunc_4() { PDDI_STUB(4); }
int bgfxLayeredShader::vfunc_11() { PDDI_STUB(11); return 0; }
void bgfxLayeredShader::vfunc_14(int a0) { PDDI_STUB(14); }
void bgfxLayeredShader::vfunc_15() { PDDI_STUB(15); }
void bgfxLayeredShader::vfunc_16() { PDDI_STUB(16); }
void bgfxLayeredShader::vfunc_17() { PDDI_STUB(17); }
void bgfxLayeredShader::vfunc_18() { PDDI_STUB(18); }
bool bgfxLayeredShader::vfunc_22() { PDDI_STUB(22); return false; }
void* bgfxLayeredShader::vfunc_23() { PDDI_STUB(23); return 0; }
void bgfxLayeredShader::vfunc_24() { PDDI_STUB(24); }

// ---- bgfxBuildingShader (d3dBuildingShader)
bgfxBuildingShader::bgfxBuildingShader(bgfxContext* context) : bgfxShader(context) { m_kind = kShaderBuilding; }
void bgfxBuildingShader::vfunc_4() { PDDI_STUB(4); }
int bgfxBuildingShader::vfunc_11() { PDDI_STUB(11); return 0; }
void bgfxBuildingShader::vfunc_12() { PDDI_STUB(12); }
void bgfxBuildingShader::vfunc_13() { PDDI_STUB(13); }
void bgfxBuildingShader::vfunc_14(int a0) { PDDI_STUB(14); }
void bgfxBuildingShader::vfunc_15() { PDDI_STUB(15); }
void bgfxBuildingShader::vfunc_16() { PDDI_STUB(16); }
void bgfxBuildingShader::vfunc_17() { PDDI_STUB(17); }
void bgfxBuildingShader::vfunc_18() { PDDI_STUB(18); }
void* bgfxBuildingShader::vfunc_23() { PDDI_STUB(23); return 0; }

// ---- bgfxReflShader (d3dReflShader)
bgfxReflShader::bgfxReflShader(bgfxContext* context) : bgfxShader(context) { m_kind = kShaderRefl; }
void bgfxReflShader::vfunc_4() { PDDI_STUB(4); }
int bgfxReflShader::vfunc_11() { PDDI_STUB(11); return 0; }
void bgfxReflShader::vfunc_12() { PDDI_STUB(12); }
void bgfxReflShader::vfunc_13() { PDDI_STUB(13); }
void bgfxReflShader::vfunc_14(int a0) { PDDI_STUB(14); }
void bgfxReflShader::vfunc_15() { PDDI_STUB(15); }
void bgfxReflShader::vfunc_16() { PDDI_STUB(16); }
void bgfxReflShader::vfunc_17() { PDDI_STUB(17); }
void bgfxReflShader::vfunc_18() { PDDI_STUB(18); }

// ---- bgfxRefractShader (d3dRefractVertexShader)
bgfxRefractShader::bgfxRefractShader(bgfxContext* context) : bgfxShader(context) { m_kind = kShaderRefract; }
void bgfxRefractShader::vfunc_4() { PDDI_STUB(4); }
int bgfxRefractShader::vfunc_11() { PDDI_STUB(11); return 0; }
void bgfxRefractShader::vfunc_12() { PDDI_STUB(12); }
void bgfxRefractShader::vfunc_13() { PDDI_STUB(13); }
void bgfxRefractShader::vfunc_14(int a0) { PDDI_STUB(14); }
void bgfxRefractShader::vfunc_15() { PDDI_STUB(15); }
void bgfxRefractShader::vfunc_16() { PDDI_STUB(16); }
void bgfxRefractShader::vfunc_17() { PDDI_STUB(17); }
void bgfxRefractShader::vfunc_18() { PDDI_STUB(18); }
bool bgfxRefractShader::vfunc_22() { PDDI_STUB(22); return false; }
void* bgfxRefractShader::vfunc_23() { PDDI_STUB(23); return 0; }
void bgfxRefractShader::vfunc_24() { PDDI_STUB(24); }

// ---- bgfxFBEffectsShader (d3dFBEffectsShader)
bgfxFBEffectsShader::bgfxFBEffectsShader(bgfxContext* context) : bgfxShader(context) { m_kind = kShaderFBEffects; }
void bgfxFBEffectsShader::vfunc_4() { PDDI_STUB(4); }
int bgfxFBEffectsShader::vfunc_11() { PDDI_STUB(11); return 0; }
void bgfxFBEffectsShader::vfunc_12() { PDDI_STUB(12); }
void bgfxFBEffectsShader::vfunc_13() { PDDI_STUB(13); }
void bgfxFBEffectsShader::vfunc_14(int a0) { PDDI_STUB(14); }
void bgfxFBEffectsShader::vfunc_16() { PDDI_STUB(16); }
void bgfxFBEffectsShader::vfunc_17() { PDDI_STUB(17); }
void bgfxFBEffectsShader::vfunc_18() { PDDI_STUB(18); }

// ---- bgfxErrorShader (d3dErrorShader)
bgfxErrorShader::bgfxErrorShader(bgfxContext* context) : bgfxShader(context) { m_kind = kShaderError; }
void bgfxErrorShader::vfunc_4() { PDDI_STUB(4); }
int bgfxErrorShader::vfunc_11() { PDDI_STUB(11); return 0; }
void bgfxErrorShader::vfunc_14(int a0) { PDDI_STUB(14); }
} // namespace pddi
} // namespace hulk
