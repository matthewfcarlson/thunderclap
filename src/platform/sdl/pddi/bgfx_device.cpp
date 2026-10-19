// bgfxDevice: the device and its factories (stands in for pure3d::d3dDevice).
#include "bgfx_pddi.h"

#include <string.h>

namespace hulk {
namespace pddi {

bgfxDevice::bgfxDevice() : m_lastError(0), m_context(0), m_display(0) {}

bgfxDevice::~bgfxDevice() {}

// The shader factory. The game's d3dDevice constructor fills a name -> creator table (FUN_00328130 in the engine
// object pddiBaseShader.cpp registers 16 creators, each constructing a d3d* shader class) and slot 11 looks the name
// up (FUN_00327c70), falling back to the first entry ("error"). The table is the one place where engine-layer code
// names backend classes, so the backend owns it: with our device the d3dDevice constructor never runs, the game's
// table stays empty and nothing reaches the d3d shader constructors; this is the same lookup over our classes.
// Names the data never uses (lightmap, projtex, pointsprite, layeredlmap, toon, toon2, spheremap, bumpmap;
// docs/graphics-backend.md section 2) get the error shader, logged once per name.
bgfxShader* bgfxDevice::newShader(const char* name)
{
    struct Kind {
        const char* name;
        int kind;
    };
    static const Kind kKinds[] = {
        {"error", kShaderError},      {"simple", kShaderSimple},       {"lightweight", kShaderSimple},
        {"environment", kShaderRefl}, {"layered", kShaderLayered},     {"refract", kShaderRefract},
        {"layeredReflect", kShaderBuilding}, {"fbeffectsshader", kShaderFBEffects},
    };
    int kind = -1;
    for (unsigned i = 0; name && i < sizeof(kKinds) / sizeof(kKinds[0]); i++)
        if (strcmp(name, kKinds[i].name) == 0)
            kind = kKinds[i].kind;
    if (kind < 0) {
        logf("pddi: shader '%s' is not one the data uses: error shader\n", name ? name : "(null)");
        kind = kShaderError;
    }
    switch (kind) {
    case kShaderSimple: return new bgfxSimpleShader(m_context);
    case kShaderLayered: return new bgfxLayeredShader(m_context);
    case kShaderBuilding: return new bgfxBuildingShader(m_context);
    case kShaderRefl: return new bgfxReflShader(m_context);
    case kShaderRefract: return new bgfxRefractShader(m_context);
    case kShaderFBEffects: return new bgfxFBEffectsShader(m_context);
    default: return new bgfxErrorShader(m_context);
    }
}

// ---- slots
// slot 4: the device's version block (major, minor, build, a word, then the description; the game: 18, 11, 56, 10,
// "XBox Console"). 0x292560 prints "PDDI v%d.%d (build %d), '%s'".
void bgfxDevice::vfunc_4(void* version)
{
    unsigned* q = (unsigned*)version;
    q[0] = 18;
    q[1] = 11;
    q[2] = 56;
    q[3] = 10;
    strcpy((char*)version + 16, "bgfx (hulk pddi backend)");
}
void bgfxDevice::vfunc_5(void* a0) { m_context = (bgfxContext*)a0; }
void* bgfxDevice::vfunc_6() { return m_context; }
void* bgfxDevice::vfunc_7(int a0)
{
    m_display = new bgfxDisplay(this);
    return m_display;
}
void* bgfxDevice::vfunc_8(void* a0)
{
    // the game: new d3dContext(display, this), then its set-up (which makes it the device's current context)
    m_context = new bgfxContext((bgfxDisplay*)a0, this);
    // what the game's set-up (0x320d30) does after the device-format survey: the base's state reset (slot 99), which
    // pushes the default render state through the context's own slots
    m_context->vfunc_99();
#if HULK_PDDI_GAME && defined(_WIN32)
    platformSelfTest(m_context, (bgfxDisplay*)a0);
#endif
    return m_context;
}
void* bgfxDevice::vfunc_9(const void* a0)
{
    return bgfxTexture::create(m_context, (const int*)a0, &m_lastError);
}
void* bgfxDevice::vfunc_10(void* a0)
{
    PDDI_STUB(10);    // G1/G3: the prim buffer parameter block -> static buffers
    return new bgfxPrimBuffer(m_context);
}
void* bgfxDevice::vfunc_11(const char* name, int a1) { return newShader(name); }
void bgfxDevice::vfunc_12(int a0, int a1) {}       // empty in the game too (0x31b9f0)
void bgfxDevice::vfunc_13(int a0) { PDDI_BASE_V(13, FUN_0031e230(a0)); }
} // namespace pddi
} // namespace hulk
