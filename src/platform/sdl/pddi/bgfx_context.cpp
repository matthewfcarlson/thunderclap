// bgfxContext: render state, transforms, lights, clears, views, immediate prims and prim-buffer draws (stands in
// for pure3d::d3dContext; specification: the verified d3dContext overrides in pure3d/d3dExtFramebufferEffects.cpp
// of the tree). The draw path itself is bgfx_draw.cpp.
#include "bgfx_pddi.h"

#include <bgfx/bgfx.h>
#include <bx/math.h>
#include <stddef.h>
#include <string.h>

namespace hulk {
namespace pddi {

enum { kNone = 0xffff };

static void identity(float* m)
{
    memset(m, 0, 16 * sizeof(float));
    m[0] = m[5] = m[10] = m[15] = 1.0f;
}

bgfxContext::bgfxContext(bgfxDisplay* display, bgfxDevice* device)
    : m_display(display), m_device(device), m_stream(0), m_defaultShader(0), m_drawIndex(0), m_anyLightDirty(false),
      m_hostLights(false), m_viewId(0), m_viewUsed(false), m_clearFlags(0), m_clearRgba(0), m_clearDepth(1.0f),
      m_clearStencil(0), m_uVc(kNone), m_uFrag(kNone), m_uTex0(kNone), m_whiteTex(kNone)
{
    memset(m_base, 0, sizeof(m_base));
#if HULK_PDDI_GAME
    // the portable base lays out its data at +4..+0x14c (and sets its own vftable, which we put back)
    void* vft = *(void**)this;
    reinterpret_cast<GameBase*>(this)->FUN_0031f410(display, device);
    *(void**)this = vft;
#endif
    m_hostClear.pad0 = 0;
    m_hostClear.colour = 0xff000000u;
    m_hostClear.depth = 1.0f;
    m_hostClear.stencil = 0;
    // Direct3D's defaults until the base's state reset (slot 99) pushes the game's through the slots
    memset(&m_rs, 0, sizeof(m_rs));
    for (int i = 0; i < 4; i++)
        m_rs.colourMask[i] = true;
    m_rs.zEnable = true;
    m_rs.zFunc = 3;
    m_rs.zWrite = true;
    m_rs.stencilFunc = 1;
    m_rs.stencilMask = m_rs.stencilWriteMask = 0xff;
    m_rs.fogEnd = 1.0f;
    identity(m_world);
    identity(m_proj);
    for (int i = 0; i < 3; i++)
        identity(m_texMatrix[i]);
    memset(m_lights, 0, sizeof(m_lights));
    for (int i = 0; i < kLights; i++) {
        m_lightDirty[i] = false;
        identity(m_lightMatrix[i]);
        m_lights[i].type = 3;
        m_lights[i].direction[2] = 1.0f;
        m_lights[i].att[0] = 1.0f;
        m_lights[i].range = 1e30f;
    }
    memset(m_vc, 0, sizeof(m_vc));
    m_viewport[0] = m_viewport[1] = 0;
    m_viewport[2] = display ? display->m_width : 640;
    m_viewport[3] = display ? display->m_height : 480;
    for (int i = 0; i < 8; i++)
        m_programs[i] = kNone;
    m_stream = new bgfxPrimStream(this);
    m_defaultShader = new bgfxErrorShader(this);
    m_ext[0] = new bgfxExtGammaControl(this);
    m_ext[1] = new bgfxExtAntialiasControl(this);
    m_ext[2] = new bgfxExtGlobalProjectedTexture(this);
    m_ext[3] = new bgfxExtReadPixels(this);
    m_ext[4] = new bgfxExtHardwareSkinning(this);
    m_ext[5] = new bgfxExtVisibilityTest(this);
    m_ext[6] = new bgfxExtVertexProgram(this);
    m_ext[7] = new bgfxExtFramebufferEffects(this);
    m_ext[8] = new bgfxExtFrameBufferTexture(this);
    m_ext[9] = 0;
}

bgfxContext::~bgfxContext()
{
    if (m_display && m_display->m_initialised) {
        for (int i = 0; i < 8; i++)
            if (m_programs[i] != kNone && m_programs[i] != 0xfffe)
                bgfx::destroy(bgfx::ProgramHandle{(uint16_t)m_programs[i]});
        if (m_uVc != kNone) {
            bgfx::destroy(bgfx::UniformHandle{(uint16_t)m_uVc});
            bgfx::destroy(bgfx::UniformHandle{(uint16_t)m_uFrag});
            bgfx::destroy(bgfx::UniformHandle{(uint16_t)m_uTex0});
            bgfx::destroy(bgfx::TextureHandle{(uint16_t)m_whiteTex});
        }
    }
    delete m_stream;
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031ece0(0);     // ~pddiBaseContext, no free
#endif
}

bgfxContext::ClearInfo* bgfxContext::clearInfo()
{
#if HULK_PDDI_GAME
    return *(ClearInfo**)((char*)this + 0x48);
#else
    return &m_hostClear;
#endif
}

void bgfxContext::hostSetClear(unsigned colour, float depth, unsigned stencil)
{
    ClearInfo* c = clearInfo();
    c->colour = colour;
    c->depth = depth;
    c->stencil = stencil;
}

// SetTransform(WORLD) and SetTransform(PROJECTION) from outside the engine (host tests, the self-test); the engine
// sets them through slots 108/109
void bgfxContext::setViewTransform(const float* view, const float* proj)
{
    memcpy(m_world, view, sizeof(m_world));
    memcpy(m_proj, proj, sizeof(m_proj));
}

// SetLight + LightEnable from outside the engine (host tests, the self-test): the light in camera space. From then
// on the base's light set is not read (updateLights) until slot 110 marks a light again.
void bgfxContext::hostSetLight(int i, const Light& l)
{
    if (i < 0 || i >= kLights)
        return;
    m_lights[i] = l;
    m_hostLights = true;
}

// ---- slots
// slot 4 (0x323df0): begin a frame: the base's frame count and timer (0x31d470), the viewport the whole target.
// Each frame's draws start in bgfx view 0; clears and viewport changes after draws open the next views.
void bgfxContext::vfunc_4()
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031d470();
#endif
    m_drawIndex = 0;
    m_viewId = 0;
    m_viewUsed = false;
    m_viewport[0] = m_viewport[1] = 0;
    m_viewport[2] = m_display ? m_display->m_width : 640;
    m_viewport[3] = m_display ? m_display->m_height : 480;
    viewChanged(0);
}
// slot 5 (0x321280): end the frame (the game unbinds the 4 texture stages and palettes, then pddiBaseContext's
// slot 5)
void bgfxContext::vfunc_5()
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031d4c0();
#endif
}
void bgfxContext::vfunc_6(unsigned int a0) { PDDI_BASE_V(6, FUN_0031d4f0(a0)); }
int* bgfxContext::vfunc_7(int* a0) { PDDI_BASE(7, FUN_0031d500(a0)); }
void bgfxContext::vfunc_8(void* a0) { PDDI_BASE_V(8, FUN_0031d510(a0)); }
float bgfxContext::vfunc_9() { PDDI_BASE(9, FUN_0031d520()); }
void bgfxContext::vfunc_10(void* a0) { PDDI_BASE_V(10, FUN_0031d530(a0)); }
int bgfxContext::vfunc_11() { PDDI_BASE(11, FUN_0031d540()); }
// slot 12 (0x321580): clear (flags: 1 colour, 2 depth, 4 stencil; the values from the base's clear block). bgfx
// clears a view at its start: a clear after draws opens the next view. (The game draws a quad instead when it renders
// into a target texture, +0x44c: G4 with the targets.)
void bgfxContext::vfunc_12(int a0)
{
    ClearInfo* c = clearInfo();
    int f = 0;
    if (a0 & 1)
        f |= BGFX_CLEAR_COLOR;
    if (a0 & 2)
        f |= BGFX_CLEAR_DEPTH;
    if (a0 & 4)
        f |= BGFX_CLEAR_STENCIL;
    m_clearRgba = (c->colour << 8) | (c->colour >> 24);       // D3DCOLOR 0xAARRGGBB -> 0xRRGGBBAA
    m_clearDepth = c->depth;
    m_clearStencil = c->stencil;
    viewChanged(f | (m_viewUsed ? 0 : (int)m_clearFlags));
}
void bgfxContext::vfunc_13(int a0) { PDDI_BASE_V(13, FUN_0031d560(a0)); }
void bgfxContext::vfunc_14(int a0, void* a1) { PDDI_BASE_V(14, FUN_0031d590(a0, a1)); }
void bgfxContext::vfunc_15(int a0) { PDDI_BASE_V(15, FUN_0031e810(a0)); }
void bgfxContext::vfunc_16(int a0) { PDDI_BASE_V(16, FUN_0031e840(a0)); }
void bgfxContext::vfunc_17(int a0, int a1) { PDDI_BASE_V(17, FUN_0031d5d0(a0, a1)); }
int bgfxContext::vfunc_18(int a0) { PDDI_BASE(18, FUN_0031e860(a0)); }
void bgfxContext::vfunc_19(void* a0) { PDDI_BASE_V(19, FUN_0031d6c0(a0)); }
void* bgfxContext::vfunc_20() { PDDI_BASE(20, FUN_0031d6e0()); }
void bgfxContext::vfunc_21(int a0) { PDDI_BASE_V(21, FUN_0031e880(a0)); }
void bgfxContext::vfunc_22(int a0, int a1) { PDDI_BASE_V(22, FUN_0031e8d0(a0, a1)); }
void bgfxContext::vfunc_23(int a0, void* a1) { PDDI_BASE_V(23, FUN_0031e930(a0, a1)); }
void bgfxContext::vfunc_24(int a0) { PDDI_BASE_V(24, FUN_0031d6f0(a0)); }
unsigned int bgfxContext::vfunc_25() { PDDI_BASE(25, FUN_0031d710()); }
void bgfxContext::vfunc_26(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { PDDI_BASE_V(26, FUN_0031d720(a0, a1, a2, a3)); }
void bgfxContext::vfunc_27(void* a0, void* a1, void* a2, void* a3) { PDDI_BASE_V(27, FUN_0031d750(a0, a1, a2, a3)); }
void bgfxContext::vfunc_28(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) { PDDI_BASE_V(28, FUN_0031d790(a0, a1, a2, a3)); }
void bgfxContext::vfunc_29(void* a0, void* a1, void* a2, void* a3) { PDDI_BASE_V(29, FUN_0031d7c0(a0, a1, a2, a3)); }
// slot 30 (0x321860 -> 0x31bd30): begin immediate prims (shader or 0 for the default, prim kind, vertex flags,
// vertex count, the shader's pass) -> the prim stream the engine writes vertices into. The game also uploads the
// shader's program constants (slots 22/24) and, for skinned flags, the skin constants (FUN_00324270), then activates
// the shader for the pass (0x327d20).
void* bgfxContext::vfunc_30(void* a0, int a1, int a2, int a3, int a4)
{
    bgfxShader* sh = a0 ? (bgfxShader*)a0 : m_defaultShader;
    if (sh->vfunc_22())
        sh->vfunc_24();
    if ((unsigned)a2 & 0x80)
        skinConstants(sh);
    beginPass(sh, a4);
    m_stream->begin(sh, a1, (unsigned)a2, a3);
    return m_stream;
}
// slot 31: end prims: draw what the stream holds
void bgfxContext::vfunc_31(void* a0)
{
    ((bgfxPrimStream*)a0)->vfunc_1();
}
// slot 32 (0x3218c0): draw a prim buffer with a shader (0: the default shader), every pass of it. (The game first
// hands a framebuffer-effects shader to its own path, 0x3285d0, and passes the light vector LITV to the shader:
// G4 / not needed by our shaders.)
void bgfxContext::vfunc_32(void* shader, void* buffer)
{
    bgfxShader* sh = shader ? (bgfxShader*)shader : m_defaultShader;
    bgfxPrimBuffer* b = (bgfxPrimBuffer*)buffer;
    if (!b)
        return;
    // a skinned buffer drawn with the refraction shader takes its skinned program (the class's +0x7d case)
    const char* program = b->m_program;
    if (sh->m_kind == kShaderRefract && (b->m_flags & 0x80))
        program = "skin_refract";
    drawPrimBuffer(sh, b, program);
}
void bgfxContext::vfunc_33(int a0, int a1, int a2, int a3) { PDDI_BASE_V(33, FUN_0031d830(a0, a1, a2, a3)); }
int bgfxContext::vfunc_34() { PDDI_BASE(34, FUN_0031d900()); }
// slot 35 (0x321990): the ambient light (D3DRS_AMBIENT; the base keeps it in its lighting block)
void bgfxContext::vfunc_35(void* a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031d910(a0);
#endif
    m_rs.ambient = (unsigned)(uintptr_t)a0;
}
int* bgfxContext::vfunc_36(int* a0) { PDDI_BASE(36, FUN_0031d920(a0)); }
void bgfxContext::vfunc_37(int a0, int a1, int a2) { PDDI_BASE_V(37, FUN_0031d940(a0, a1, a2)); }
void bgfxContext::vfunc_38(int a0, int a1) { PDDI_BASE_V(38, FUN_0031da40(a0, a1)); }
unsigned char bgfxContext::vfunc_39(unsigned int a0) { PDDI_BASE(39, FUN_0031da80(a0)); }
void bgfxContext::vfunc_40(int a0, int a1) { PDDI_BASE_V(40, FUN_0031daa0(a0, a1)); }
int bgfxContext::vfunc_41(int a0) { PDDI_BASE(41, FUN_0031dae0(a0)); }
void bgfxContext::vfunc_42(int a0, int a1) { PDDI_BASE_V(42, FUN_0031db00(a0, a1)); }
void bgfxContext::vfunc_43(int a0, int a1) { PDDI_BASE_V(43, FUN_0031dba0(a0, a1)); }
void bgfxContext::vfunc_44(int a0, int a1) { PDDI_BASE_V(44, FUN_0031dbd0(a0, a1)); }
void bgfxContext::vfunc_45(int a0, void* a1) { PDDI_BASE_V(45, FUN_0031dc50(a0, a1)); }
void bgfxContext::vfunc_46(int a0, int a1) { PDDI_BASE_V(46, FUN_0031dc90(a0, a1)); }
void bgfxContext::vfunc_47(int a0, void* a1) { PDDI_BASE_V(47, FUN_0031dd10(a0, a1)); }
void bgfxContext::vfunc_48(int a0, float a1) { PDDI_BASE_V(48, FUN_0031dd50(a0, a1)); }
float bgfxContext::vfunc_49(int a0) { PDDI_BASE(49, FUN_0031dd90(a0)); }
void bgfxContext::vfunc_50(int a0, float a1, float a2, float a3) { PDDI_BASE_V(50, FUN_0031ddb0(a0, a1, a2, a3)); }
void bgfxContext::vfunc_51(int a0, void* a1, void* a2, void* a3) { PDDI_BASE_V(51, FUN_0031ddf0(a0, a1, a2, a3)); }
void bgfxContext::vfunc_52(int a0, float a1, float a2, float a3) { PDDI_BASE_V(52, FUN_0031de50(a0, a1, a2, a3)); }
void bgfxContext::vfunc_53(int a0, void* a1, void* a2, void* a3) { PDDI_BASE_V(53, FUN_0031de90(a0, a1, a2, a3)); }
// slot 54 (0x3219f0): cull mode (0 none, 1 counter-clockwise: D3D's default, 2 clockwise; 0x4d3a48)
void bgfxContext::vfunc_54(int a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031def0(a0);
#endif
    m_rs.cull = (unsigned)a0;
}
unsigned int bgfxContext::vfunc_55() { PDDI_BASE(55, FUN_0031df00()); }
// slot 56 (0x321a30): colour write mask (red, green, blue, alpha)
void bgfxContext::vfunc_56(char a0, char a1, char a2, char a3)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031df10(a0, a1, a2, a3);
#endif
    m_rs.colourMask[0] = a0 != 0;
    m_rs.colourMask[1] = a1 != 0;
    m_rs.colourMask[2] = a2 != 0;
    m_rs.colourMask[3] = a3 != 0;
}
void bgfxContext::vfunc_57(void* a0, void* a1, void* a2, void* a3) { PDDI_BASE_V(57, FUN_0031df40(a0, a1, a2, a3)); }
// slot 58 (0x321aa0): z enable (D3DRS_ZENABLE)
void bgfxContext::vfunc_58(int a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031df80((unsigned char)a0);
#endif
    m_rs.zEnable = (unsigned char)a0 != 0;
}
unsigned char bgfxContext::vfunc_59() { PDDI_BASE(59, FUN_0031df90()); }
// slot 60 (0x321ac0): z compare (pddi compare -> 0x4d3a6c)
void bgfxContext::vfunc_60(int a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031dfa0(a0);
#endif
    m_rs.zFunc = (unsigned)a0 & 7;
}
unsigned int bgfxContext::vfunc_61() { PDDI_BASE(61, FUN_0031dfb0()); }
// slot 62 (0x321af0): z write
void bgfxContext::vfunc_62(unsigned char a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031dfc0(a0);
#endif
    m_rs.zWrite = a0 != 0;
}
unsigned char bgfxContext::vfunc_63() { PDDI_BASE(63, FUN_0031dfd0()); }
// slot 64 (0x321b50): stencil enable
void bgfxContext::vfunc_64(int a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031dfe0(a0);
#endif
    m_rs.stencil = (unsigned char)a0 != 0;
}
unsigned char bgfxContext::vfunc_65() { PDDI_BASE(65, FUN_0031dff0()); }
// slot 66 (0x321b70): stencil compare (pddi compare)
void bgfxContext::vfunc_66(int a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031e000(a0);
#endif
    m_rs.stencilFunc = (unsigned)a0 & 7;
}
int bgfxContext::vfunc_67() { PDDI_BASE(67, FUN_0031e010()); }
// slot 68 (0x321ba0): stencil reference
void bgfxContext::vfunc_68(unsigned long a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031e020((int)a0);
#endif
    m_rs.stencilRef = (unsigned)a0;
}
int bgfxContext::vfunc_69() { PDDI_BASE(69, FUN_0031e030()); }
// slot 70 (0x321bd0): stencil (read) mask
void bgfxContext::vfunc_70(int a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031e040(a0);
#endif
    m_rs.stencilMask = (unsigned)a0;
}
int bgfxContext::vfunc_71() { PDDI_BASE(71, FUN_0031e050()); }
// slot 72 (0x321c00): stencil write mask (bgfx has no separate one: only 0xff is honoured)
void bgfxContext::vfunc_72(int a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031e060(a0);
#endif
    m_rs.stencilWriteMask = (unsigned)a0;
    if (((unsigned)a0 & 0xff) != 0xff)
        PDDI_STUB(72);
}
int bgfxContext::vfunc_73() { PDDI_BASE(73, FUN_0031e070()); }
// slot 74 (0x321c30): stencil ops: fail, depth fail, pass (pddi op -> 0x4d3a54)
void bgfxContext::vfunc_74(int a0, int a1, int a2)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031e080(a0, a1, a2);
#endif
    m_rs.stencilOp[0] = (unsigned)a0;
    m_rs.stencilOp[1] = (unsigned)a1;
    m_rs.stencilOp[2] = (unsigned)a2;
}
void bgfxContext::vfunc_75(void* a0, void* a1, void* a2) { PDDI_BASE_V(75, FUN_0031e0b0(a0, a1, a2)); }
// slot 76 (0x321c90): fill mode (0 solid, 1 wireframe, 2 points: bgfx draws solid; logged)
void bgfxContext::vfunc_76(unsigned long a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031e0e0(a0);
#endif
    m_rs.fill = (unsigned)a0;
    if (a0)
        PDDI_STUB(76);
}
int bgfxContext::vfunc_77() { PDDI_BASE(77, FUN_0031e0f0()); }
// slot 78 (0x321cb0): fog enable
void bgfxContext::vfunc_78(unsigned int a0)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031e100(a0);
#endif
    m_rs.fog = (unsigned char)a0 != 0;
}
bool bgfxContext::vfunc_79() { PDDI_BASE(79, FUN_0031e110()); }
// slot 80 (0x321ce0): fog colour, start, end (floats as words); the game sets linear table fog
void bgfxContext::vfunc_80(int a0, int a1, int a2)
{
#if HULK_PDDI_GAME
    reinterpret_cast<GameBase*>(this)->FUN_0031e120(a0, a1, a2);
#endif
    m_rs.fogColour = (unsigned)a0;
    memcpy(&m_rs.fogStart, &a1, 4);
    memcpy(&m_rs.fogEnd, &a2, 4);
}
void bgfxContext::vfunc_81(void* a0, void* a1, void* a2) { PDDI_BASE_V(81, FUN_0031e150(a0, a1, a2)); }
int bgfxContext::vfunc_82(int a0) { PDDI_BASE(82, FUN_0031e180(a0)); }
float bgfxContext::vfunc_83(int a0) { PDDI_BASE(83, FUN_0031e1a0(a0)); }
unsigned int bgfxContext::vfunc_84() { return 0x800; }      // 0x321d90
void bgfxContext::vfunc_85(unsigned char a0) { PDDI_BASE_V(85, FUN_0031e1b0(a0)); }
unsigned char bgfxContext::vfunc_86() { PDDI_BASE(86, FUN_0031e1c0()); }
void bgfxContext::vfunc_87(int a0) { PDDI_BASE_V(87, FUN_0031f290(a0)); }
void bgfxContext::vfunc_88(unsigned char a0) { PDDI_BASE_V(88, FUN_0031e9b0(a0)); }
// slot 89: the extension with this id (0x321ea0), or the base's answer (0) for any other
int bgfxContext::vfunc_89(int id)
{
    static const int kIds[10] = {0x101, 0x500001, 0x500004, 0x500005, 0x102, 0x500002, 0x106, 0x103, 0x104, 0x105};
    for (int i = 0; i < 10; i++)
        if (kIds[i] == id)
            return (int)(intptr_t)m_ext[i];
    logf("pddi: extension 0x%x asked for: none\n", id);
    return 0;
}
// slot 90 (0x321f50): is extension `id` supported: the seven the game's d3dContext answers for, else the base's
bool bgfxContext::vfunc_90(int id)
{
    switch (id) {
    case 0x101: case 0x102: case 0x103: case 0x106: case 0x500001: case 0x500002: case 0x500004:
        return true;
    default:
        PDDI_BASE(90, FUN_0031e2f0(id));
    }
}
void bgfxContext::vfunc_91() {}                           // empty in the game (0x3212c0)
int bgfxContext::vfunc_92(void* a0) { PDDI_STUB(92); return 0; }
void bgfxContext::vfunc_93(int a0, int a1, int a2, int a3) { PDDI_BASE_V(93, FUN_0031d630(a0, a1, a2, a3)); }
void bgfxContext::vfunc_94(int a0) { PDDI_BASE_V(94, FUN_0031e5a0(a0)); }
void bgfxContext::vfunc_95(int a0) { PDDI_BASE_V(95, FUN_0031e5b0(a0)); }
// slot 96 (0x321b20): the viewport's depth range (MinZ, MaxZ): bgfx has none per view; noted, logged when not 0..1
void bgfxContext::vfunc_96(unsigned int a0, unsigned int a1)
{
    float lo, hi;
    memcpy(&lo, &a0, 4);
    memcpy(&hi, &a1, 4);
    if (lo != 0.0f || hi != 1.0f)
        PDDI_STUB(96);
}
void bgfxContext::vfunc_97(int a0, int a1) { PDDI_BASE_V(97, FUN_0031e5d0(a0, a1)); }
int bgfxContext::vfunc_98(void* a0, int a1) { PDDI_BASE(98, FUN_0031e600(a0, a1)); }
void bgfxContext::vfunc_99() { PDDI_BASE_V(99, FUN_0031cb60()); }
void bgfxContext::vfunc_100() { PDDI_BASE_V(100, FUN_0031e610()); }
void bgfxContext::vfunc_101() { PDDI_BASE_V(101, FUN_0031f190()); }
void bgfxContext::vfunc_102(unsigned char a0) { PDDI_BASE_V(102, FUN_0031d2b0(a0)); }
void bgfxContext::vfunc_103() { PDDI_BASE_V(103, FUN_0031d300()); }
void bgfxContext::vfunc_104() { PDDI_BASE_V(104, FUN_0031d380()); }
void bgfxContext::vfunc_105() { PDDI_BASE_V(105, FUN_0031d3f0()); }
void bgfxContext::vfunc_106() { PDDI_STUB(106); }
float bgfxContext::vfunc_107() { PDDI_STUB(107); return 0.0f; }
// slot 108 (0x323eb0): load the top of matrix stack n into the device: stack 0 is D3DTS_WORLD (the modelview;
// D3D's VIEW stays the identity), 1..3 the texture transforms (0x4d3a34: 6, 2, 3, 4)
void bgfxContext::vfunc_108(int n)
{
#if HULK_PDDI_GAME
    const uint32_t* stack = *(const uint32_t* const*)((const char*)this + 0x20 + 4 * n);
    if (!stack || n < 0 || n > 3)
        return;
    const float* m = (const float*)(uintptr_t)stack[3] + 16 * stack[2];
    memcpy(n == 0 ? m_world : m_texMatrix[n - 1], m, 64);
#else
    (void)n;
#endif
}
// slot 109 (0x323ee0): the projection and viewport from the base's view block (*(this+0x48): +0x10 mode, +0x14
// the viewport's x0, y0, x1, y1 as fractions, +0x24 near, far, field of view, aspect): mode 0 a perspective
// (z in [0, w], w = camera depth), 1 an orthographic view of the aspect, 2 pixel coordinates; the viewport in
// pixels of the target (FUN_00321520)
void bgfxContext::vfunc_109()
{
#if HULK_PDDI_GAME
    struct View { char pad[0x10]; int mode; float x0, y0, x1, y1, nearZ, farZ, fov, aspect; };
    View* k = *(View**)((char*)this + 0x48);
    if (!k)
        return;
    float W = (float)(m_display ? m_display->m_width : 640), H = (float)(m_display ? m_display->m_height : 480);
    float m[16];
    identity(m);
    float vx = 0, vy = 0, vw = W, vh = H;
    float n = k->nearZ, f = k->farZ;
    if (k->mode == 0) {
        float A = (float)bx::tan(k->fov * 0.5f) * k->nearZ;
        float X = A / k->aspect;
        float v20 = (k->x0 + k->x0) / (k->x1 - k->x0) + 1.0f;
        if (v20 > 1.0f) v20 = 1.0f;
        float v1c = 1.0f - ((k->x1 - 1.0f) * 2.0f) / (k->x1 - k->x0);
        if (v1c > 1.0f) v1c = 1.0f;
        float va = ((k->y1 - 1.0f) * 2.0f) / (k->y0 - k->y1) + 1.0f;
        if (va > 1.0f) va = 1.0f;
        float vb = 1.0f - (k->y0 + k->y0) / (k->y0 - k->y1);
        if (vb > 1.0f) vb = 1.0f;
        float right = v1c * A, left = -(v20 * A), bottom = vb * X, top = -(X * va);
        float Q = f / (f - n);
        memset(m, 0, sizeof(m));
        m[0] = (n + n) / (right - left);
        m[5] = (n + n) / (bottom - top);
        m[8] = -((left + right) / (right - left));
        m[9] = -((top + bottom) / (bottom - top));
        m[10] = Q;
        m[11] = 1.0f;
        m[14] = -(Q * n);
        if (k->x0 < 0.0f) k->x0 = 0.0f;
        if (k->x1 > 1.0f) k->x1 = 1.0f;
        if (k->y1 > 1.0f) k->y1 = 1.0f;
        if (k->y0 < 0.0f) k->y0 = 0.0f;
        vx = W * k->x0; vy = H * k->y0; vw = (k->x1 - k->x0) * W; vh = (k->y1 - k->y0) * H;
    } else if (k->mode == 1) {
        m[0] = 2.0f;
        float sc = 1.0f / k->aspect;
        m[5] = 2.0f / (0.0f - ((-0.5f * sc) - (0.5f * sc)));
        float r = 1.0f / (f - n);
        m[10] = r;
        m[14] = -(r * n);
        vx = W * k->x0; vy = H * k->y0; vw = (k->x1 - k->x0) * W; vh = (k->y1 - k->y0) * H;
    } else if (k->mode == 2) {
        m[12] = -1.0f;
        m[0] = 2.0f / ((W - 0.5f) - (-0.5f));
        m[13] = 1.0f;
        m[5] = 2.0f / (-0.5f - (H - 0.5f));
        float r = 1.0f / (f - n);
        m[10] = r;
        m[14] = -(r * n);
    }
    memcpy(m_proj, m, sizeof(m));
    unsigned vp[4] = {(unsigned)(int)vx, (unsigned)(int)vy, (unsigned)(int)vw, (unsigned)(int)vh};
    if (memcmp(vp, m_viewport, sizeof(vp))) {
        memcpy(m_viewport, vp, sizeof(vp));
        viewChanged(-1);
    }
#endif
}
// slot 110 (0x3212d0): light n changed; with b, the modelview now (the base's current matrix, slot 20) is the one
// it is placed with. FUN_00321310 (updateLights) moves the marked lights to camera space at the next draw.
void bgfxContext::vfunc_110(int n, char b)
{
    if (n < 0 || n >= kLights)
        return;
    m_anyLightDirty = true;
    m_lightDirty[n] = true;
    m_hostLights = false;
    if (b) {
#if HULK_PDDI_GAME
        memcpy(m_lightMatrix[n], (char*)this + 0x5c, 64);
#else
        memcpy(m_lightMatrix[n], m_world, 64);
#endif
    }
}
} // namespace pddi
} // namespace hulk
