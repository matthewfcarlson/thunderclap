// The pddi backend on bgfx: one class per D3D-side pddi class of Pure3D (docs/graphics-backend.md, stage G0).
//
// Every class keeps the MS-ABI vtable slot order of the game class it stands in for (build/rtti.json), so the
// portable engine code, which calls pddi objects by slot, can be handed these objects in the native 32-bit image.
// Slot signatures come from include/gen/pure3d.h, corrected where the verified source of the game's function shows
// otherwise, and each slot's stack shape was checked against the game function's `ret N`. `tools/native_gfx.py
// slots` checks the slot counts of a win32 compile against build/rtti.json.
//
// Each slot is one of:
//   - ours: the D3D backend's override (or a slot the game's class leaves pure). Logged stub or a minimal
//     implementation on bgfx; written from the verified platform/xbox/pure3d source of the game's function, which
//     is the specification (its body is not copied: the D3D call is what gets replaced).
//   - base: inherited by the game's class from a portable pddi base (engine objects in the tree). In the native
//     image (HULK_PDDI_GAME) it calls the tree's definition by XBE address (game_base.h); in the host build, where
//     there is no game, it is a logged stub.
// Names stay vfunc_N (as in include/gen and the verified sources) until the slot meanings are settled; what is known
// is in the comment.
#pragma once

#include "pddi.h"
#include "draw_sink.h"

namespace hulk {
namespace pddi {

class bgfxDevice;
class bgfxDisplay;
class bgfxContext;
class bgfxPrimStream;
class bgfxShader;
class bgfxPrimBuffer;
class bgfxTexture;

// pddiObject's three slots and the virtual destructor (slot 3): every class below that the game derives from
// pddiObject. In the game, slots 0-2 are pddiObject's inline functions (emitted into the Xbox objects, so they are
// reimplemented here): add a reference, drop one (deleting at zero through slot 3), and the word at +8 (an accessor
// the linker folded with another identical function).
class bgfxObject {
  public:
    bgfxObject() : m_refCount(0) {}
    virtual void vfunc_0();                   // slot 0: AddRef
    virtual void vfunc_1();                   // slot 1: Release (deletes at 0)
    virtual int vfunc_2();                    // slot 2: the word at +8
    virtual ~bgfxObject();                    // slot 3: scalar deleting destructor
    int m_refCount;                           // +4, as pddiObject's
};

// Stands in for pure3d::d3dDevice (vftable 0x4324e4, 14 slots). Created by hulk_pddi_create_device (in place of
// d3dCreateDevice 0x31ba60). Slot 4: version, 5/6: the current context, 7: new display (0x49c bytes in the game),
// 8: new context (0x450), 9: new texture (0xf8) from a parameter block, 10: new prim buffer (0x40), 11: new shader by
// pddi name (the game: the factory table 0x5555c8 that d3dDevice's constructor fills through FUN_00328130; ours is
// bgfxDevice::newShader, see docs/graphics-backend.md G1 "binding").
class bgfxDevice : public bgfxObject {
  public:
    enum { kClass = kClassDevice };
    bgfxDevice();
    virtual ~bgfxDevice();
    virtual void vfunc_4(void* version);      // slot 4: d3dDevice 0x31b7d0 (pure3d/d3dDevice.cpp)
    virtual void vfunc_5(void*);              // slot 5: d3dDevice 0x31b810 (pure3d/d3dDevice.cpp)
    virtual void* vfunc_6();                  // slot 6: d3dDevice 0x31b820 (pure3d/d3dDevice.cpp)
    virtual void* vfunc_7(int);               // slot 7: d3dDevice 0x31b830 (pure3d/d3dDevice.cpp)
    virtual void* vfunc_8(void*);             // slot 8: d3dDevice 0x31b860 (pure3d/d3dDevice.cpp)
    virtual void* vfunc_9(const void*);       // slot 9: d3dDevice 0x31b8a0 (pure3d/d3dDevice.cpp)
    virtual void* vfunc_10(void*);            // slot 10: d3dDevice 0x31b960 (pure3d/d3dDevice.cpp)
    virtual void* vfunc_11(const char* name, int); // slot 11: d3dDevice 0x31b9d0 (pure3d/d3dDevice.cpp)
    virtual void vfunc_12(int, int);          // slot 12: d3dDevice 0x31b9f0 (pure3d/d3dDevice.cpp)
    virtual void vfunc_13(int);               // slot 13: base pddiDevice 0x31e230 (pure3d/pddiBaseContext.cpp)

    bgfxShader* newShader(const char* name);  // slot 11's factory (bgfx_device.cpp)
    int m_lastError;                          // +8 (slots 9/10 store a failed object's status here)
    bgfxContext* m_context;                   // +0xc: the current context (slots 5/6; slot 11 hands it to shaders)
    bgfxDisplay* m_display;                   // +0x10 (the game: the Direct3D object, passed to new displays)
};

// Stands in for pure3d::d3dDisplay (vftable 0x43242c, 18 slots). Slot 4: init from a display config (mode table,
// auto-select), 5: set mode (width, height, depth; re-inits when changed), 6/7: width/height, 8: depth,
// 10: a flag, 11/12: back-buffer size, 14: swap (present + vblank pacing), 15: copy a rect, 16: aspect ratio.
class bgfxDisplay : public bgfxObject {
  public:
    enum { kClass = kClassDisplay };
    explicit bgfxDisplay(bgfxDevice* device);
    virtual ~bgfxDisplay();
    virtual bool vfunc_4(int);                // slot 4: d3dDisplay 0x31ae70 (pure3d/d3dDisplay.cpp)
    virtual bool vfunc_5(int, int, int);      // slot 5: d3dDisplay 0x31ada0 (pure3d/d3dDisplay.cpp)
    virtual unsigned int vfunc_6();           // slot 6: d3dDisplay 0x31ad30 (pure3d/d3dDisplay.cpp)
    virtual unsigned int vfunc_7();           // slot 7: d3dDisplay 0x31ad40 (pure3d/d3dDisplay.cpp)
    virtual int vfunc_8();                    // slot 8: d3dDisplay 0x31ad50 (pure3d/d3dDisplay.cpp)
    virtual unsigned int vfunc_9();           // slot 9: d3dDisplay 0x31ad60 (pure3d/d3dDisplay.cpp): returns 0
    virtual unsigned char vfunc_10();         // slot 10: d3dDisplay 0x31ad90 (pure3d/d3dDisplay.cpp)
    virtual unsigned int vfunc_11();          // slot 11: d3dDisplay 0x31ad70 (pure3d/d3dDisplay.cpp)
    virtual unsigned int vfunc_12();          // slot 12: d3dDisplay 0x31ad80 (pure3d/d3dDisplay.cpp)
    virtual unsigned int vfunc_13();          // slot 13: d3dDisplay 0x31b350 (pure3d/d3dDisplay.cpp): returns 0
    virtual void vfunc_14();                  // slot 14: d3dDisplay 0x31b190 (pure3d/d3dDisplay.cpp)
    virtual void vfunc_15(int, int);          // slot 15: d3dDisplay 0x31b610 (pure3d/d3dDisplay.cpp)
    virtual float vfunc_16();                 // slot 16: d3dDisplay 0x31b500 (pure3d/d3dDisplay.cpp)
    virtual unsigned int vfunc_17();          // slot 17: d3dDisplay 0x31b340 (pure3d/d3dDisplay.cpp): returns 0

    // ours (not slots)
    bool hostInit(void* nativeWindow, void* nativeDisplay, unsigned width, unsigned height, int renderer,
                  void* callback = 0);     // callback: the sink's (the bgfx sink: a bgfx::CallbackI) or 0
    void hostShutdown();
    void hostResize(unsigned width, unsigned height);   // the window's pixel size changed: the back buffer follows
    bgfxDevice* m_device;
    unsigned m_width, m_height, m_depth;
    bool m_initialised;
    unsigned m_frame;
    int m_nativeType;         // set before hostInit: 1 = the handles are a Wayland display/surface

    // G4: the frame is drawn into a frame buffer of the sink's (the scene target: colour + D24S8), which the present
    // pass (before the sink's frame) draws onto the back buffer. That is what makes the game's reads of the render
    // target possible: bgfx can neither read nor blit the back buffer. The copy texture is the one the game's display
    // makes at init (0x31ae70: CreateTexture of the back buffer's size and format, display+0x498) and FUN_0031b1e0
    // fills with CopyRects of the render target: the refraction shader samples it (bgfxContext::copyFrameBuffer
    // copies into it at the point in the frame the copy is asked for). Without a present program for the renderer
    // (no shader build, e.g. D3D11 under Wine 7.7) the frame goes straight to the back buffer and no copy exists (the
    // refraction stage samples white). The targets are the sink's (draw_sink.h; bgfx_sink.cpp since the split, D3).
    bool ensureTargets();                     // (re)make the scene target and the copy at the current size
    void present();                           // the scene target onto the back buffer (display slot 14)
    bool offscreen() const;                   // the scene target is in use (a present program exists)
    unsigned targetWidth() const;             // the scene target's size
    unsigned targetHeight() const;
    unsigned char m_wantCopy;                 // DisplayConfig.createTexture (+0x2e) as the game asked (logged)
    // the front buffer: what the last present showed, kept (a copy at the present) while the framebuffer effects'
    // overlay asks for it (GetBackBuffer(-1) in 0x3226d0); m_prevAsked: the frame it was last asked in
    unsigned m_prevAsked;
    unsigned prevFrame();                     // the sink's texture (made on first use), and keep it coming

    // G5: the window. The game's frame (m_width x m_height: the mode slots 6/7/11/12 report, the scene target's size)
    // is presented into the window's back buffer (m_windowWidth x m_windowHeight) scaled with its aspect kept: bars
    // (black) left and right or above and below. HULK_GFX_SCALE: linear (default), nearest, integer (whole
    // multiples, point sampled; a window smaller than the frame falls back to linear). Without a scene target (no
    // present program, HULK_GFX_DIRECT) the back buffer is the frame and follows the window as before.
    unsigned m_windowWidth, m_windowHeight;
    int m_scaleMode;                          // 0 linear, 1 nearest, 2 integer
    void presentRect(int* x, int* y, int* w, int* h) const;   // where the frame lands in the window
    // G5: render-target copies where the renderer can't blit (desktop OpenGL: bgfx blits there only through
    // glCopyImageSubData, GL 4.3) are full-screen draws into a frame buffer over the destination
    // (HULK_GFX_QUAD_COPY=1 forces them, 0 forbids them; default: on for OpenGL): the sink's (SinkCaps::copyTakesPass)
};

// Stands in for pure3d::d3dContext (vftable 0x433164, 111 slots). 33 slots are the D3D backend's overrides
// (ours); 78 are pddiBaseContext's (base). In the native image the portable base's data (0x04..0x14c: state stacks,
// matrix stacks at +0x20.., render state blocks at +0x4c/+0x54/+0x58, the clear block at +0x48, ...) is laid out
// by the base constructor (0x31f410) and owned by the base's functions; our fields start at 0x14c.
// Known meanings (from the verified sources): 4/5 begin/end frame, 12 clear (flags 1 colour, 2 depth, 4 stencil),
// 30 begin prims (shader, prim kind, vertex flags, count, ...) -> stream, 31 end prims (stream), 32 draw a prim
// buffer with a shader, 54 cull mode, 56 colour write mask, 58/60/62 depth state, 64-74 stencil, 76 fill mode,
// 78/80 fog, 106/107 the frame timer, 108 load matrix N into the device, 110 update light N.
class bgfxContext : public bgfxObject {
  public:
    enum { kClass = kClassContext };
    bgfxContext(bgfxDisplay* display, bgfxDevice* device);
    virtual ~bgfxContext();
    virtual void vfunc_4();                   // slot 4: d3dContext 0x323df0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_5();                   // slot 5: d3dContext 0x321280 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_6(unsigned int);       // slot 6: base pddiBaseContext 0x31d4f0 (pure3d/pddiBaseContext.cpp)
    virtual int* vfunc_7(int*);               // slot 7: base pddiBaseContext 0x31d500 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_8(void*);              // slot 8: base pddiBaseContext 0x31d510 (pure3d/pddiBaseContext.cpp)
    virtual float vfunc_9();                  // slot 9: base pddiBaseContext 0x31d520 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_10(void*);             // slot 10: base pddiBaseContext 0x31d530 (pure3d/pddiBaseContext.cpp)
    virtual int vfunc_11();                   // slot 11: base pddiBaseContext 0x31d540 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_12(int);               // slot 12: d3dContext 0x321580 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_13(int);               // slot 13: base pddiBaseContext 0x31d560 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_14(int, void*);        // slot 14: base pddiBaseContext 0x31d590 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_15(int);               // slot 15: base pddiBaseContext 0x31e810 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_16(int);               // slot 16: base pddiBaseContext 0x31e840 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_17(int, int);          // slot 17: base pddiBaseContext 0x31d5d0 (pure3d/pddiBaseContext.cpp)
    virtual int vfunc_18(int);                // slot 18: base pddiBaseContext 0x31e860 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_19(void*);             // slot 19: base pddiBaseContext 0x31d6c0 (pure3d/pddiBaseContext.cpp)
    virtual void* vfunc_20();                 // slot 20: base pddiBaseContext 0x31d6e0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_21(int);               // slot 21: base pddiBaseContext 0x31e880 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_22(int, int);          // slot 22: base pddiBaseContext 0x31e8d0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_23(int, void*);        // slot 23: base pddiBaseContext 0x31e930 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_24(int);               // slot 24: base pddiBaseContext 0x31d6f0 (pure3d/pddiBaseContext.cpp)
    virtual unsigned int vfunc_25();          // slot 25: base pddiBaseContext 0x31d710 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_26(unsigned int, unsigned int, unsigned int, unsigned int); // slot 26: base pddiBaseContext 0x31d720 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_27(void*, void*, void*, void*); // slot 27: base pddiBaseContext 0x31d750 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_28(unsigned int, unsigned int, unsigned int, unsigned int); // slot 28: base pddiBaseContext 0x31d790 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_29(void*, void*, void*, void*); // slot 29: base pddiBaseContext 0x31d7c0 (pure3d/pddiBaseContext.cpp)
    virtual void* vfunc_30(void*, int, int, int, int); // slot 30: d3dContext 0x321860 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_31(void*);             // slot 31: d3dContext 0x3218b0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_32(void*, void*);      // slot 32: d3dContext 0x3218c0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_33(int, int, int, int); // slot 33: base pddiBaseContext 0x31d830 (pure3d/pddiBaseContext.cpp)
    virtual int vfunc_34();                   // slot 34: base pddiBaseContext 0x31d900 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_35(void*);             // slot 35: d3dContext 0x321990 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual int* vfunc_36(int*);              // slot 36: base pddiBaseContext 0x31d920 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_37(int, int, int);     // slot 37: base pddiBaseContext 0x31d940 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_38(int, int);          // slot 38: base pddiBaseContext 0x31da40 (pure3d/pddiBaseContext.cpp)
    virtual unsigned char vfunc_39(unsigned int); // slot 39: base pddiBaseContext 0x31da80 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_40(int, int);          // slot 40: base pddiBaseContext 0x31daa0 (pure3d/pddiBaseContext.cpp)
    virtual int vfunc_41(int);                // slot 41: base pddiBaseContext 0x31dae0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_42(int, int);          // slot 42: base pddiBaseContext 0x31db00 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_43(int, int);          // slot 43: base pddiBaseContext 0x31dba0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_44(int, int);          // slot 44: base pddiBaseContext 0x31dbd0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_45(int, void*);        // slot 45: base pddiBaseContext 0x31dc50 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_46(int, int);          // slot 46: base pddiBaseContext 0x31dc90 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_47(int, void*);        // slot 47: base pddiBaseContext 0x31dd10 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_48(int, float);        // slot 48: base pddiBaseContext 0x31dd50 (pure3d/pddiBaseContext.cpp)
    virtual float vfunc_49(int);              // slot 49: base pddiBaseContext 0x31dd90 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_50(int, float, float, float); // slot 50: base pddiBaseContext 0x31ddb0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_51(int, void*, void*, void*); // slot 51: base pddiBaseContext 0x31ddf0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_52(int, float, float, float); // slot 52: base pddiBaseContext 0x31de50 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_53(int, void*, void*, void*); // slot 53: base pddiBaseContext 0x31de90 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_54(int);               // slot 54: d3dContext 0x3219f0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual unsigned int vfunc_55();          // slot 55: base pddiBaseContext 0x31df00 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_56(char, char, char, char); // slot 56: d3dContext 0x321a30 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_57(void*, void*, void*, void*); // slot 57: base pddiBaseContext 0x31df40 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_58(int);               // slot 58: d3dContext 0x321aa0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual unsigned char vfunc_59();         // slot 59: base pddiBaseContext 0x31df90 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_60(int);               // slot 60: d3dContext 0x321ac0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual unsigned int vfunc_61();          // slot 61: base pddiBaseContext 0x31dfb0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_62(unsigned char);     // slot 62: d3dContext 0x321af0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual unsigned char vfunc_63();         // slot 63: base pddiBaseContext 0x31dfd0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_64(int);               // slot 64: d3dContext 0x321b50 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual unsigned char vfunc_65();         // slot 65: base pddiBaseContext 0x31dff0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_66(int);               // slot 66: d3dContext 0x321b70 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual int vfunc_67();                   // slot 67: base pddiBaseContext 0x31e010 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_68(unsigned long);     // slot 68: d3dContext 0x321ba0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual int vfunc_69();                   // slot 69: base pddiBaseContext 0x31e030 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_70(int);               // slot 70: d3dContext 0x321bd0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual int vfunc_71();                   // slot 71: base pddiBaseContext 0x31e050 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_72(int);               // slot 72: d3dContext 0x321c00 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual int vfunc_73();                   // slot 73: base pddiBaseContext 0x31e070 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_74(int, int, int);     // slot 74: d3dContext 0x321c30 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_75(void*, void*, void*); // slot 75: base pddiBaseContext 0x31e0b0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_76(unsigned long);     // slot 76: d3dContext 0x321c90 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual int vfunc_77();                   // slot 77: base pddiBaseContext 0x31e0f0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_78(unsigned int);      // slot 78: d3dContext 0x321cb0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual bool vfunc_79();                  // slot 79: base pddiBaseContext 0x31e110 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_80(int, int, int);     // slot 80: d3dContext 0x321ce0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_81(void*, void*, void*); // slot 81: base pddiBaseContext 0x31e150 (pure3d/pddiBaseContext.cpp)
    virtual int vfunc_82(int);                // slot 82: base pddiBaseContext 0x31e180 (pure3d/pddiBaseContext.cpp)
    virtual float vfunc_83(int);              // slot 83: base pddiBaseContext 0x31e1a0 (pure3d/pddiBaseContext.cpp)
    virtual unsigned int vfunc_84();          // slot 84: d3dContext 0x321d90 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_85(unsigned char);     // slot 85: base pddiBaseContext 0x31e1b0 (pure3d/pddiBaseContext.cpp)
    virtual unsigned char vfunc_86();         // slot 86: base pddiBaseContext 0x31e1c0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_87(int);               // slot 87: base pddiBaseContext 0x31f290 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_88(unsigned char);     // slot 88: base pddiBaseContext 0x31e9b0 (pure3d/pddiBaseContext.cpp)
    virtual int vfunc_89(int);                // slot 89: d3dContext 0x321ea0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual bool vfunc_90(int);               // slot 90: d3dContext 0x321f50 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_91();                  // slot 91: d3dContext 0x3212c0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual int vfunc_92(void*);              // slot 92: d3dContext 0x321d40 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_93(int, int, int, int); // slot 93: base pddiBaseContext 0x31d630 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_94(int);               // slot 94: base pddiBaseContext 0x31e5a0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_95(int);               // slot 95: base pddiBaseContext 0x31e5b0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_96(unsigned int, unsigned int); // slot 96: d3dContext 0x321b20 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_97(int, int);          // slot 97: base pddiBaseContext 0x31e5d0 (pure3d/pddiBaseContext.cpp)
    virtual int vfunc_98(void*, int);         // slot 98: base pddiBaseContext 0x31e600 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_99();                  // slot 99: base pddiBaseContext 0x31cb60 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_100();                 // slot 100: base pddiBaseContext 0x31e610 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_101();                 // slot 101: base pddiBaseContext 0x31f190 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_102(unsigned char);    // slot 102: base pddiBaseContext 0x31d2b0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_103();                 // slot 103: base pddiBaseContext 0x31d300 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_104();                 // slot 104: base pddiBaseContext 0x31d380 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_105();                 // slot 105: base pddiBaseContext 0x31d3f0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_106();                 // slot 106: d3dContext 0x3214d0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual float vfunc_107();                // slot 107: d3dContext 0x3214e0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_108(int);              // slot 108: d3dContext 0x323eb0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_109();                 // slot 109: d3dContext 0x323ee0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_110(int, char);        // slot 110: d3dContext 0x3212d0 (pure3d/d3dExtFramebufferEffects.cpp)

    // ours (not slots)
    struct ClearInfo {                        // the base's clear block (*(this+0x48) in the game)
        int pad0;
        unsigned colour;                      // D3DCOLOR (0xAARRGGBB)
        float depth;
        unsigned stencil;
    };
    // The render state the d3dContext's overrides of slots 35 and 54-80 hand to D3D (each calls the base's setter
    // first, which keeps the portable blocks the draw log reads; the D3D state is ours: bgfx state per draw).
    // pddi enums (the game's tables): compare 0 never 1 always 2 less 3 lequal 4 greater 5 gequal 6 equal
    // 7 notequal (0x4d3a6c); stencil op 0 keep 1 zero 2 replace 3 incr (wrap) 4 decr (wrap) 5 invert (0x4d3a54);
    // fill 0 solid 1 wireframe 2 points (0x4d3a8c); cull 0 none 1 counter-clockwise 2 clockwise (0x4d3a48).
    struct RenderState {
        unsigned cull;                        // 54
        bool colourMask[4];                   // 56: r g b a
        bool zEnable;                         // 58
        unsigned zFunc;                       // 60
        bool zWrite;                          // 62
        bool stencil;                         // 64
        unsigned stencilFunc;                 // 66
        unsigned stencilRef;                  // 68
        unsigned stencilMask;                 // 70 (read mask)
        unsigned stencilWriteMask;            // 72 (bgfx has none: logged when not 0xff)
        unsigned stencilOp[3];                // 74: fail, depth fail, pass
        unsigned fill;                        // 76 (bgfx: solid only; logged)
        bool fog;                             // 78
        unsigned fogColour;                   // 80 (D3DCOLOR)
        float fogStart, fogEnd;               // 80 (passed as float bits)
        unsigned ambient;                     // 35: the ambient light (D3DCOLOR)
    };
    // One light as D3D gets it (FUN_00321310 from the base's light set at +0x50): already in camera space.
    // type: D3D 1 point, 2 spot, 3 directional (0x4d3a10: pddi 0 dir, 1 point, 2 spot, 3 point); diffuse: the
    // light colour (also its specular, as the game sets it). The sink's struct, so packets can point at the set.
    typedef SinkLight Light;
    enum { kLights = 8 };
    ClearInfo* clearInfo();
    void hostSetClear(unsigned colour, float depth, unsigned stencil);
    void setViewTransform(const float* view, const float* proj);   // the modelview (D3D world) and projection
    void hostSetLight(int i, const Light& l);   // host builds and the self-test: a light in camera space
    void submit(bgfxPrimStream* stream);
    // A draw of either source (bgfx_draw.cpp): what the prim stream and the prim buffer hand to the common path.
    struct DrawSource {
        int kind;                             // pddi prim kind
        uint32_t count;                       // vertices (no indices) or indices to draw
        uint32_t vertexCount;
        uint32_t transient;                   // the sink's transient token (kSinkNone: the buffers below)
        unsigned vb, ib;                      // sink buffer ids (ib kSinkNone: not indexed)
        uint32_t owner;                       // the prim buffer's serial (0: a prim stream)
        unsigned flags;                       // the vertex flags (what the program may read)
        const char* program;                  // vertex program name ("" or 0: fixed function)
    };
    void draw(bgfxShader* shader, const DrawSource& src);
    // the per-pass loop of slot 32 / d3dExtHardwareSkinning::vfunc_6: activate the shader (0x327d20), pass, draw
    void drawPrimBuffer(bgfxShader* shader, bgfxPrimBuffer* buffer, const char* program);
    void beginPass(bgfxShader* shader, int pass);
    // the D3D-side state the draws read
    void updateLights();                      // FUN_00321310: the dirty lights from the base's set
    int directionalLights(int* ids);          // FUN_00321dc0(ids, 0): up to 4 enabled directional lights
    void setVertexConstants(int reg, const float* v, int count);   // SetVertexShaderConstant (hardware numbering)
    void skinConstants(bgfxShader* shader);  // FUN_00324270: the skin programs' material, light, projection
    // d3dRefractVertexShader::vfunc_24's unskinned upload (0x32f3b0; the class computes the four rows it passes)
    void refractConstants(bgfxShader* shader, const float* viewport, const float* uv, const float* half,
                          const float* one);
    const float* worldMatrix();               // the modelview (D3D world: the base's matrix stack 0)
    // the viewport changed (clearFlags < 0) or a clear (bgfx flags): a new bgfx view when the current one has draws
    void viewChanged(int clearFlags);
    void setupView();                         // the current view's target, rectangle, clear, mode
    // FUN_0031b1e0 (display): CopyRects of the render target into the display's frame-buffer texture, at this point
    // of the frame: a blit into the copy at the start of a new view (bgfx runs a view's blits before its draws), so
    // what was drawn so far is in it and what follows can sample it. Returns the texture object the refraction shader
    // binds (its tex84 wraps the display's texture, FUN_00326300), or 0 when there is no copy (no scene target).
    bgfxTexture* copyFrameBuffer();
    // the scene target into `dstTex` (its size): a blit at the start of a new view, or with quad copies a draw into
    // `dstFb` in a view of its own (the scene goes on in the next one). False when out of views.
    bool sceneCopy(unsigned dstTex, unsigned dstFb);
    // ---- full-screen passes (bgfx_effects.cpp): each pass is a view of its own after what was drawn so far
    // a view drawing into `fb` (0xffff: the scene target) over the rectangle, no clear, in submission order
    uint16_t fxView(unsigned fb, unsigned x, unsigned y, unsigned w, unsigned h);
    void fxDone();                            // what follows goes to a new scene view (the current viewport)
    bool fxCopy(unsigned dstTex, unsigned dstFb);   // FUN_00320aa0: the render target (the scene) into a texture of
                                                    // its size (dstFb: its frame buffer, for quad copies)
    // a quad in target pixels (edges: 0..w, 0..h) with up to four texture coordinate sets (normalised), one program
    struct FxQuad {
        float x0, y0, x1, y1;
        float uv[4][4];                       // set i: u0, v0, u1, v1
    };
    void fxDraw(uint16_t view, uint32_t program, const FxQuad& q, const unsigned* tex, int ntex, uint32_t state,
                const float* consts, int nconsts, const float* prog);   // program: SinkFxProgram; state: kFx*
    bool fxEnsure();
    void renderState(int kind, SinkRenderState* out);   // the context's (slots 54-80) and D3D's blend, resolved
    void drawlogState(DrawRecord& r);
    int m_base[(0x14c - 8) / 4];              // +8..+0x14c: the portable base's data (see above)
    bgfxDisplay* m_display;
    bgfxDevice* m_device;
    bgfxPrimStream* m_stream;
    bgfxShader* m_defaultShader;
    unsigned m_drawIndex;                     // draws in this frame (drawlog)
    RenderState m_rs;
    float m_hudShift = 0.0f, m_hudRegion = 1.0f;   // HULK_HUD=edge: the overlay camera is current (ndc shift, 4:3 region half-width)
    float m_world[16], m_proj[16];            // D3DTS_WORLD (the modelview) and D3DTS_PROJECTION, row-vector
    float m_texMatrix[3][16];                 // stacks 1..3 (D3DTS_TEXTURE0..2): kept, not applied yet
    Light m_lights[kLights];
    bool m_lightDirty[kLights], m_anyLightDirty, m_hostLights;
    float m_lightMatrix[kLights][16];         // slot 110: the modelview when the light was set
    float m_vc[192][4];                       // the vertex constant file (hardware numbering; programs read c96..)
    unsigned m_viewport[4];                   // x, y, w, h (FUN_00321520)
    unsigned m_viewId;                        // the bgfx view draws go to now
    bool m_viewUsed;                          // a draw went to m_viewId (a clear/viewport change opens a new view)
    unsigned m_clearFlags, m_clearRgba;       // what the pending view clears
    float m_clearDepth;
    unsigned m_clearStencil;
    bool ensureResources();                   // the display is up and the sink's draw resources are made

    // ---- the device state the shaders' pass set-up writes (bgfx_combiner.cpp)
    // What the game's shader classes write in their slot 14 (pass set-up) through its d3dContext state cache
    // (+0x150) into D3D's texture-stage and render states, kept as D3D values: the draw turns them into a combiner
    // key (a fragment program), sampler flags, bgfx blend state and uniforms. Xbox D3D values: D3DTOP 1 disable,
    // 2 selectarg1, 3 selectarg2, 4 modulate, 5 modulate2x, 6 modulate4x, 7 add, 8 addsigned, 9 addsigned2x,
    // 10 subtract, 11 addsmooth, 12 blenddiffusealpha, 13 blendcurrentalpha, 14 blendtexturealpha, 15
    // blendfactoralpha, 16 blendtexturealphapm, 17 premodulate, 18 modulatealpha_addcolor, 19
    // modulatecolor_addalpha, 20 modulateinvalpha_addcolor, 21 modulateinvcolor_addalpha, 22 dotproduct3, 23
    // multiplyadd, 24 lerp (25/26 bump: unused); D3DTA 0 diffuse, 1 current, 2 texture, 3 tfactor, 4 specular,
    // 5 temp, +0x10 complement, +0x20 alpha replicate; blend factors/ops and compare functions as their GL-style
    // values (0x302 src alpha, 0x8006 add, 0x204 greater, ...).
    struct Stage {
        uint32_t colorOp, colorArg1, colorArg2, alphaOp, alphaArg1, alphaArg2, resultArg;
        uint32_t texCoordIndex;               // low bits: the uv set; 0x10000 normal, 0x20000 position, 0x30000
                                              // reflection vector (camera space)
        uint32_t transformFlags;              // D3DTTFF: 0 off, 2/3/4 components through D3DTS_TEXTUREn
        uint32_t address;                     // D3DTADDRESS: 1 wrap, 2 mirror, 3 clamp, 4 border
        uint32_t magFilter, minFilter, mipFilter;   // D3DTEXF: 0 none, 1 point, 2 linear
        bgfxTexture* texture;                 // what the cache's +8.. has bound to the stage
    };
    struct DeviceState {
        Stage stage[4];
        uint32_t textureFactor;               // D3DCOLOR
        bool blend;                           // ALPHABLENDENABLE, BLENDOP, SRCBLEND, DESTBLEND
        uint32_t blendOp, srcBlend, dstBlend;
        bool alphaTest;                       // ALPHATESTENABLE, ALPHAFUNC, ALPHAREF (0..255)
        uint32_t alphaFunc, alphaRef;
        uint32_t shadeMode;                   // 0x1d00 flat, 0x1d01 gouraud
        bool lighting, specular, twoSidedLighting;   // LIGHTING, SPECULARENABLE, TWOSIDEDLIGHTING
        uint32_t material[4];                 // SetMaterial: diffuse, specular, ambient, emissive (D3DCOLOR)
        float power;
        unsigned cull;                        // the cull mode D3D has (pddi enum): slot 54's, none under 2SID
        bool cacheLit, cacheTwoSided;         // FUN_00329f70's cache (+0x104, +0x105)
    };
    DeviceState m_d3d;
    void resetDeviceState();                  // Direct3D's defaults (stage 0 modulate texture, the rest disabled)
    // the game's state-cache helpers the shaders call (d3dSimpleShader.cpp / d3dVertexProgram.cpp of the tree)
    void stageDisable(int stage);                                   // FUN_00329bb0: colour and alpha op disable
    void stageColour(int stage, uint32_t op, uint32_t arg1);        // FUN_00329cf0
    void stageColour(int stage, uint32_t op, uint32_t arg1, uint32_t arg2);   // FUN_00329d50
    void stageAlpha(int stage, uint32_t op, uint32_t arg1);         // FUN_00329da0
    void stageAlpha(int stage, uint32_t op, uint32_t arg1, uint32_t arg2);    // FUN_00329e00
    void stageBoth(int stage, uint32_t op, uint32_t arg1, uint32_t arg2);     // FUN_00329e50
    void stageTexture(int stage, bgfxObject* texture);              // the inline bind (FUN_00326b00 / unbind)
    void stageTextures(int disableFrom, bgfxObject* t0, bgfxObject* t1, bgfxObject* t2, bgfxObject* t3);  // 0x32a920
    void stageAddress(int stage, int uvMode);                       // FUN_00329c40 (pddi UVMD -> 0x4d4efc)
    void stageFilter(int stage, int filterMode);                    // FUN_00329c90 (pddi FIMD -> 0x4d4e10)
    void stageCoords(int stage, uint32_t texCoordIndex, uint32_t transformFlags, int uvMode, int filterMode);
                                                                    // FUN_0032a320 / FUN_0032b530
    void setTextureFactor(uint32_t c);                              // FUN_00329f20
    void setShadeMode(int shmd);                                    // the inline 0x4037c write (0x4d4f24)
    void lightingMaterial(bool lit, bool twoSided, const uint32_t* material, float power);   // FUN_00329f70
    void alphaBlend(bool enable, uint32_t op, int src, int dst);    // FUN_0032a0c0 (pddi factor -> 0x4d4ed0)
    void alphaTest(bool enable, int compare, uint32_t ref);         // FUN_0032a190 (pddi compare -> 0x4d4f04)
    // The draw's combiner: the canonical key of the active stages ("c4.0.2a4.0.2r1|..."), its hash; the sink picks
    // the fragment program for (vertex program, key): the bgfx sink one generated per key the shader classes can
    // produce (shaders/vp/combiners.txt, made by `native_gfx.py combiners`), else the generic combiner with the
    // stages as uniforms (logged once per key)
    static int combinerKey(const DeviceState& d, char* out, int size);
    static uint32_t combinerHash(const char* key);
    bool m_forceGeneric;                      // the self-test: every draw through the generic combiner
    void combinerStats(int* generated, int* generic, int* draws);   // keys seen with/without a program; draws
    // host builds: the base's matrix stacks 1..3 and its view block, which the game image has in the base's data
    // (slots 14-16, 24 and 109 use them there); the self-test drives these slots on the host too
    struct ViewBlock {                        // *(context+0x48) in the game: the clear values, then the view
        int pad0;
        unsigned colour;
        float depth;
        unsigned stencil;
        int mode;                             // +0x10: 0 perspective, 1 orthographic, 2 pixels
        float x0, y0, x1, y1, nearZ, farZ, fov, aspect;
    };
    ViewBlock* viewBlock();
    ViewBlock m_hostView;
    float m_hostStack[4][8][16];
    int m_hostDepth[4];
    void hostSetView(int mode, float nearZ, float farZ, float fov, float aspect);   // as the engine's camera sets it
    // slot 89 (GetExtension): the d3dContext's extension objects by id, in the game's order (+0x424..+0x448):
    // 0x101 gamma, 0x500001 antialias, 0x500004 projected texture, 0x500005 read pixels, 0x102 hardware skinning,
    // 0x500002 visibility test, 0x106 vertex program, 0x103 framebuffer effects, 0x104 framebuffer texture, 0x105 none
    void* m_ext[10];
    // G4 (the data members stay after the base's block at +8..+0x14c: m_base must be the first)
    unsigned m_visQuery;                      // the visibility test's bgfx occlusion query the draws go to (0xffff)
    const char* m_streamProgram;              // d3dExtVertexProgram slot 6: the program prim streams draw with (0)
    bgfxTexture* m_fbCopy;                    // a linear texture object over the display's copy (texel coordinates)
    unsigned m_copiesThisFrame;
    unsigned m_fxTargetW, m_fxTargetH;        // the fx view's target size (u_fxTarget)
    DrawSink* m_sink;                         // the build's sink (draw_sink.h; D3: the front-end/sink split)
};

// Stands in for pure3d::d3dTexture (vftable 0x4333ac, 21 slots). 4: pixel type, 5/6: width/height, 7: bits per
// pixel, 8: alpha bits, 9: mip count, 10: palette size, 11/12: palette write/read, 13/14: lock/unlock a mip level
// (the unlock swizzles on the Xbox: here it uploads linear), 15/20: base, 18/19: a priority word.
class bgfxTexture : public bgfxObject {
  public:
    enum { kClass = kClassTexture };
    explicit bgfxTexture(bgfxContext* context);
    virtual ~bgfxTexture();
    virtual unsigned int vfunc_4();           // slot 4: d3dTexture 0x326220 (pure3d/d3dTexture.cpp)
    virtual unsigned int vfunc_5();           // slot 5: d3dTexture 0x326230 (pure3d/d3dTexture.cpp)
    virtual int vfunc_6();                    // slot 6: d3dTexture 0x326240 (pure3d/d3dTexture.cpp)
    virtual unsigned int vfunc_7();           // slot 7: d3dTexture 0x326250 (pure3d/d3dTexture.cpp)
    virtual int vfunc_8();                    // slot 8: d3dTexture 0x326260 (pure3d/d3dTexture.cpp)
    virtual unsigned int vfunc_9();           // slot 9: d3dTexture 0x326270 (pure3d/d3dTexture.cpp)
    virtual unsigned int vfunc_10();          // slot 10: d3dTexture 0x326890 (pure3d/d3dTexture.cpp)
    virtual void vfunc_11(unsigned int, void*); // slot 11: d3dTexture 0x3268a0 (pure3d/d3dTexture.cpp)
    virtual unsigned int vfunc_12(void*);     // slot 12: d3dTexture 0x3268d0 (pure3d/d3dTexture.cpp)
    virtual void* vfunc_13(int, int);         // slot 13: d3dTexture 0x326900 (pure3d/d3dTexture.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dTexture 0x326a10 (pure3d/d3dTexture.cpp)
    virtual void vfunc_15(int, int, int);     // slot 15: base pddiTexture 0x325ee0 (pure3d/pddiTexture.cpp)
    virtual void vfunc_16();                  // slot 16: d3dTexture 0x326ad0 (pure3d/d3dTexture.cpp)
    virtual void vfunc_17();                  // slot 17: d3dTexture 0x326ae0 (pure3d/d3dTexture.cpp)
    virtual void vfunc_18(unsigned int);      // slot 18: d3dTexture 0x326af0 (pure3d/d3dTexture.cpp)
    virtual unsigned int vfunc_19();          // slot 19: d3dTexture 0x326280 (pure3d/d3dTexture.cpp)
    virtual void vfunc_20(int, int, int, int, int, int, int); // slot 20: base pddiTexture 0x325ef0 (pure3d/pddiTexture.cpp)

    // ours
    // What lock (slot 13) returns: the level's description, laid out as the game's (FUN_0031c570 / FUN_0031c290):
    // size, bits per pixel, the pixel layout (a type and channel masks) and where to write (bits, stride; a
    // negative stride for the uncompressed formats: the engine writes its rows bottom-up, as into the Xbox buffer).
    struct LockInfo {
        int width, height, bitsPerPixel, depth;
        int type;                             // 6 A8R8G8B8, 11 DXT1, 13 DXT2/3, 15 DXT4/5 (the game's numbering)
        unsigned char direct;                 // masks are exactly A8R8G8B8
        char pad15[3];
        unsigned start[4], shift[4], mask[4]; // red, green, blue, alpha
        int stride, slicePitch;
        void* bits;
    };
    // device slot 9: the parameter block (width, height, ?, bits, alpha depth, mip count, pddi format, usage;
    // byte +0x20: volume). Returns 0 with *error set when the game's checks would fail (non-power-of-two, ...).
    static bgfxTexture* create(bgfxContext* context, const int* params, int* error);
    // A movie frame into this texture (G2's movie render strategy): what the game's movie player does with the
    // tiles RenderStrategyBink makes (linear 32-bit pddi textures of at most 1024 x 1024, vfunc_6) and hands out
    // locked (vfunc_4: the lock's bits and stride): the decoder writes the frame's rows, top row first, at bits,
    // bits + stride, ... (the lock's stride is negative: the engine's bottom-up layout), then the unlock uploads.
    // `frame` is B, G, R, A bytes (D3DCOLOR order), `pitch` bytes a row, read from (srcX, srcY) on: the tile's part
    // of a larger frame. The decoder itself (Bink's replacement) is a separate task; this is its seam.
    bool writeFrame(const unsigned char* frame, int frameWidth, int frameHeight, int pitch, int srcX, int srcY);
    bool init(int width, int height, int bits, int alphaDepth, int mips, int format);
    void upload(int level);
    bgfxContext* m_context;
    unsigned m_handle;                        // the sink's texture (created on first upload: the sink may not be up yet)
    unsigned m_width, m_height, m_format, m_mips;   // m_format: SinkTextureFormat
    unsigned m_pddiFormat, m_bits, m_alphaBits, m_usage;
    int m_type;                               // LockInfo::type
    int m_lockedLevel;                        // -1: not locked
    unsigned m_priority;                      // slots 18/19
    unsigned m_ordinal;                       // first-seen order (the drawlog's texture key)
    bool m_linear;                            // pddi format 11/12: a linear (unswizzled) texture: any size, and
                                              // texture coordinates in texels (the NV2A's rule for them)
    LockInfo m_info;
    unsigned char* m_levels[16];              // CPU copies per mip level (bgfx gets them on unlock)
    uint32_t m_palette[256];
    // G5: a copy of a render target (the frame-buffer copy, the front buffer): on renderers whose targets have the
    // origin at the bottom left (OpenGL) its rows are stored bottom-up, so the draw samples it with v flipped
    bool m_fromTarget;
    // G5: deferred uploads (bgfx_texture.cpp upload): the levels unlocked since the last flush, queued for the next
    // present; a draw that binds the texture flushes it first
    unsigned m_dirtyLevels;
    bool m_pendingQueued;
    bgfxTexture* m_pendingNext;
    void flush();
    void unqueue();
};
void flushPendingTextures(int limit);         // display slot 14, before the sink's frame

// Stands in for pure3d::d3dPrimBufferStream (vftable 0x4334f4, 18 slots; no pddiObject base): what a prim buffer's
// lock (slot 4) hands out to write vertices with. The fields keep the game's record layout (FUN_00326e90 fills
// it: pointers into the locked vertices per attribute, the stride, the vertices written), in case engine code
// reads them; the slots are ours. 0: position + next vertex, 1: normal (packed 11:11:10 when the layout packs it),
// 2/3: the 0x800/0x1000 vectors, 4: colour (value, set), 6: uv (u, v, set), 9: the second colour, 10: three bone
// indices (x3, D3DCOLOR order), 11: packed blend weights, 12-16: whole vertices (+ next), 17: next vertex.
class bgfxPrimBufferStream final {      // final: no virtual destructor (the game class has no slot for one)
  public:
    enum { kClass = kClassPrimBufferStream };
    bgfxPrimBufferStream();
    virtual void vfunc_0(float, float, float); // slot 0: d3dPrimBufferStream 0x327450 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_1(float, float, float); // slot 1: d3dPrimBufferStream 0x327480 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_2(unsigned long, unsigned long, unsigned long); // slot 2: d3dPrimBufferStream 0x327530 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_3(unsigned int, unsigned int, unsigned int); // slot 3: d3dPrimBufferStream 0x327550 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_4(int, int);           // slot 4: d3dPrimBufferStream 0x327570 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_5(int, int);           // slot 5: d3dPrimBufferStream 0x327420 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_6(float, float, int);  // slot 6: d3dPrimBufferStream 0x327590 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_7(int, int, int, int); // slot 7: d3dPrimBufferStream 0x327430 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_8(int, int, int, int, int); // slot 8: d3dPrimBufferStream 0x327440 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_9(unsigned int);       // slot 9: d3dPrimBufferStream 0x3275b0 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_10(char, char, char, char); // slot 10: d3dPrimBufferStream 0x3275c0 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_11(float, float, float); // slot 11: d3dPrimBufferStream 0x327600 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_12(const float*, const float*, const float*); // slot 12: d3dPrimBufferStream 0x327750 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_13(const float*, unsigned int, const float*); // slot 13: d3dPrimBufferStream 0x327710 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_14(const float*, const float*); // slot 14: d3dPrimBufferStream 0x3276d0 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_15(const float*, const float*); // slot 15: d3dPrimBufferStream 0x327690 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_16(const float*, unsigned int); // slot 16: d3dPrimBufferStream 0x327660 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_17();                  // slot 17: d3dPrimBufferStream 0x3277a0 (jumps to 0x326f90)

    // the game's record (offsets from the vftable pointer)
    unsigned char active;                     // +4
    char pad5[3];
    void* format;                             // +8 (the game: the vertex format; here our prim buffer)
    char* base;                               // +0xc the first vertex
    int written;                              // +0x10 vertices written
    int arg;                                  // +0x14
    int stride;                               // +0x18
    int texCount, colourSets;                 // +0x1c, +0x20
    char* position;                           // +0x24
    float* normal;                            // +0x28 (unpacked normals; 0: this layout packs them)
    unsigned* packedNormal;                   // +0x2c
    unsigned* colours;                        // +0x30 (0x20 / 0x4000 sets)
    unsigned* colour2;                        // +0x34 (0x40)
    float* uv;                                // +0x38
    char* extra[4];                           // +0x3c 0x200, 0x400, 0x800, 0x1000
    unsigned char* indices;                   // +0x4c (0x80)
    unsigned* weights;                        // +0x50 (0x100, packed)
    void layout(char* data, unsigned flags, int stride);   // FUN_00326e90 (the packed layout)
    void next();                              // FUN_00326f90
};

// Stands in for pure3d::d3dPrimBuffer (vftable 0x4334b4, 15 slots): a vertex (+ index) buffer made by device slot 10
// from a parameter block (prim kind, vertex flags, vertex count, index count, vertex program name), filled through
// the stream its slot 4 hands out (or raw, slots 11/12) and indices (slots 7/8 or 9), drawn by context slot 32 and
// d3dExtHardwareSkinning::vfunc_6. The vertices are kept in the game's packed layout (FUN_00326e90: normals and
// blend weights 11:11:10, bone indices as D3DCOLOR bytes) and converted to the backend's vertex at the next draw
// after a change: a static bgfx buffer the first time, a dynamic one when the buffer is rewritten.
class bgfxPrimBuffer : public bgfxObject {
  public:
    enum { kClass = kClassPrimBuffer };
    bgfxPrimBuffer(bgfxContext* context, int kind, unsigned flags, int vertexCount, int indexCount,
                   const char* program);
    virtual ~bgfxPrimBuffer();
    virtual void* vfunc_4();                  // slot 4: d3dPrimBuffer 0x327190 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_5(void*);              // slot 5: d3dPrimBuffer 0x3271f0 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_6();                   // slot 6: base pddiPrimBuffer 0x326d60 (pure3d/pddiPrimBuffer.cpp)
    virtual unsigned int vfunc_7();           // slot 7: d3dPrimBuffer 0x327200 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_8(unsigned int);       // slot 8: d3dPrimBuffer 0x327220 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_9(void*, int);         // slot 9: d3dPrimBuffer 0x3272b0 (pure3d/d3dPrimBufferStream.cpp)
    virtual bool vfunc_10(int);               // slot 10: d3dPrimBuffer 0x327230 (pure3d/d3dPrimBufferStream.cpp)
    virtual unsigned int vfunc_11(int);       // slot 11: d3dPrimBuffer 0x327250 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_12();                  // slot 12: d3dPrimBuffer 0x327280 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_13(int, int);          // slot 13: d3dPrimBuffer 0x3272a0 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dPrimBuffer 0x3270a0 (pure3d/d3dPrimBufferStream.cpp)

    // the game's layout from +8 (d3dPrimBuffer: FUN_003277b0, FUN_00327860, FUN_003270c0, FUN_00327130, 0x3272f0)
    int m_base8, m_baseC;                     // +8, +0xc
    unsigned m_d3dPrim;                       // +0x10 D3D primitive type (0x4d3ea8[kind])
    int m_kind;                               // +0x14 pddi prim kind
    unsigned m_flags;                         // +0x18 vertex flags
    int m_vertexCount;                        // +0x1c
    int m_indexCapacity;                      // +0x20
    int m_indexCount;                         // +0x24 indices in use (slots 8, 9)
    int m_overrideCount;                      // +0x28 slot 14: draw only this many (0: all)
    unsigned short* m_indices;                // +0x2c (the game: the index buffer)
    char* m_vertices;                         // +0x30 (the game: the vertex buffer), the packed layout
    unsigned char m_locked, m_indexLocked, m_rawLocked, pad37;  // +0x34..+0x36
    bgfxContext* m_context;                   // +0x38
    const char* m_program;                    // +0x3c (the game: the vertex format the program lookup made)
    // ours
    int m_stride;                             // of the packed layout
    bgfxPrimBufferStream m_stream;
    bool m_vertsDirty, m_indicesDirty;
    int m_uploads;                            // vertex conversions so far (the bgfx sink: the second makes it dynamic)
    unsigned m_vb, m_ib;                      // the sink's buffers (0xffff: none)
    uint32_t m_serial;                        // ours: the buffer's id in draw packets (stable for its life)
    bool prepare();                           // the sink's buffers up to date with the CPU copy (draw time)
};

// Stands in for pure3d::d3dPrimStream (vftable 0x432578: d3dBasePrimStream's 2 slots), what bgfxContext::vfunc_30
// returns. Portable code writes vertices inline through the pointers below and advances with FUN_0008ef00 (game
// code that stays in the native image), so the first fields keep d3dPrimStream's layout (0x31bd30, 0x31be40,
// 0x31c080 and 0x8ef00 read and write them): the attribute pointers, the batch's vertex limit, the vertices
// written, how many a full batch hands on to the next (2 for strips, 1 for line strips: 0x4d3664) and, at +0x24,
// where FUN_0008ef00 copies those before it calls slot 1 (draw) and slot 0 with carry (start the next batch).
class bgfxPrimStream final {            // final: no virtual destructor (2 slots, as the game's)
  public:
    enum { kClass = kClassPrimStream };
    explicit bgfxPrimStream(bgfxContext* context);
    virtual void vfunc_0(bool carry);         // slot 0: d3dPrimStream 0x31be40
    virtual void vfunc_1();                   // slot 1: d3dPrimStream 0x31c080
    int stride;                               // +4 (game layout from here to +0x130)
    char* posPtr;                             // +8
    char* normalPtr;                          // +0xc
    char* colorPtr;                           // +0x10
    char* uvPtr;                              // +0x14
    int limit;                                // +0x18 vertices a batch holds (a multiple of 6)
    int vertCount;                            // +0x1c vertices written in this batch
    int retained;                             // +0x20 vertices a full batch carries over
    char m_carry[0x10c];                      // +0x24 the carried vertices (FUN_0008ef00 copies them here)
    // ours
    void begin(bgfxShader* shader, int kind, unsigned flags, int count);
    void vertex();                            // FUN_0008ef00 (for the backend's own callers: tests, the scene)
    bgfxContext* m_context;
    bgfxShader* m_shader;
    int m_kind;                               // pddi prim kind (0 tri list, 1 tri strip, 2 line list, 3 line strip, 4 points)
    unsigned m_flags;                         // vertex flags: 0x10 normal, 0x20 colour, 0x4000 colour sets, low 4 bits uv sets
    int m_uvCount;
    int m_colourSets;
    int m_pendingTotal;                       // the vertex count begin announced, less what was drawn
    enum { kMaxVerts = 4096 };
    char m_data[kMaxVerts * 64];              // the batch (the game: one of its rotating vertex buffers)
};

// Stands in for pure3d::d3dShader (vftable 0x433ffc, 25 slots): pddiBaseShader's slots are base, d3dShader's own
// (12/13: per-draw material colour, 21-24: vertex program, constants) and the pure ones are ours. The game's data
// layout: pddiBaseShader's words at +8/+0xc, then d3dShader's (+0x10 context, +0x1c mode, ...).
class bgfxShader : public bgfxObject {
  public:
    enum { kClass = kClassShader };
    explicit bgfxShader(bgfxContext* context);
    virtual ~bgfxShader();
    virtual const char* vfunc_4();            // slot 4: the pddi name (pure in d3dShader; each kind returns its own)
    virtual bool vfunc_5(int, int);           // slot 5: base pddiBaseShader 0x3279e0 (pure3d/pddiBaseShader.cpp)
    virtual bool vfunc_6(int, int);           // slot 6: base pddiBaseShader 0x327a40 (pure3d/pddiBaseShader.cpp)
    virtual unsigned char vfunc_7(int, int);  // slot 7: base pddiBaseShader 0x327aa0 (pure3d/pddiBaseShader.cpp)
    virtual bool vfunc_8(int, int);           // slot 8: base pddiBaseShader 0x327b00 (pure3d/pddiBaseShader.cpp)
    virtual bool vfunc_9(int, int);           // slot 9: base pddiBaseShader 0x327b60 (pure3d/pddiBaseShader.cpp)
    virtual bool vfunc_10(int, int);          // slot 10: base pddiBaseShader 0x327bc0 (pure3d/pddiBaseShader.cpp)
    virtual int vfunc_11();                   // slot 11: pure in the game's class
    virtual void vfunc_12();                  // slot 12: d3dShader 0x333420 (pure3d/d3dShader.cpp)
    virtual void vfunc_13();                  // slot 13: d3dShader 0x3334a0 (pure3d/d3dShader.cpp)
    virtual void vfunc_14(int);               // slot 14: pure in the game's class
    virtual const void* vfunc_15();           // slot 15: base pddiBaseShader 0x327980 (pure3d/pddiBaseShader.cpp)
    virtual const void* vfunc_16();           // slot 16: base pddiBaseShader 0x327990 (pure3d/pddiBaseShader.cpp)
    virtual const void* vfunc_17();           // slot 17: base pddiBaseShader 0x3279a0 (pure3d/pddiBaseShader.cpp)
    virtual const void* vfunc_18();           // slot 18: base pddiBaseShader 0x3279b0 (pure3d/pddiBaseShader.cpp)
    virtual const void* vfunc_19();           // slot 19: base pddiBaseShader 0x3279c0 (pure3d/pddiBaseShader.cpp)
    virtual const void* vfunc_20();           // slot 20: base pddiBaseShader 0x3279d0 (pure3d/pddiBaseShader.cpp)
    virtual void vfunc_21(void*);             // slot 21: d3dShader 0x333370 (pure3d/d3dShader.cpp)
    virtual bool vfunc_22();                  // slot 22: d3dShader 0x3286b0 (pure3d/d3dFBEffectsShader.cpp)
    virtual void* vfunc_23();                 // slot 23: d3dShader 0x3286c0 (pure3d/d3dFBEffectsShader.cpp)
    virtual void vfunc_24();                  // slot 24: d3dShader 0x3286d0 (pure3d/d3dFBEffectsShader.cpp)

    int m_base[2];                            // +8, +0xc: pddiBaseShader's data (+0xc: the change serial)
    bgfxContext* m_context;                   // +0x10
    int m_kind;                               // ShaderKind

    // ours: the pddi parameters, set through the base's slots 5-10 (key -> setter tables, slots 15-20)
    struct Param {                            // the layout pddiBaseShader's slots 5-10 walk (24 bytes)
        uint32_t key;                         // the parameter's four-character code ("TEX", "BLMD", ...)
        uint32_t reserved;
        const void* setter;                   // thiscall (value), called on this + offset
        int offset;
        int unused[2];
    };
    const Param* m_tables[6];                 // slots 15..20: textures, ints, floats, colours, (vectors, matrices)
    const char* m_name;                       // slot 4
    // The d3dShader fields the game's setters write (offsets in the game's object, the setters 0x3333a0.. and
    // 0x333770..; the constructor 0x333520 gives the defaults). FUN_003335e0 (fade()) derives the faded ones.
    bgfxObject* m_texture[3];                 // TEX (+0x80), TTEX (layered +0x84, building +0x88), REFL (+0x84)
    int m_blendMode;                          // BLMD (+0x18): pddi blend mode
    int m_activeMode;                         // +0x1c: BLMD, or alpha (1) when BLMD is none and the shader fades
    bool m_alphaTest;                         // ATST (+0x28)
    int m_alphaCompare;                       // ACMP (+0x2c): pddi compare (default 5: gequal)
    float m_alphaRef;                         // ACTH (+0x30)
    float m_alphaRefFaded;                    // +0x34: ACTH x (255 - fade) / 255, clamped (the alpha reference used)
    int m_fade;                               // FADE (+0x38): 0..255 (255: faded out)
    int m_uvMode, m_filter;                   // UVMD (+0x40: 0 wrap, 1 clamp), FIMD (+0x44: 0x4d4e10's 5 filters)
    bool m_lit;                               // LIT (+0x48)
    int m_shadeMode;                          // SHMD (+0x4c: 0 flat, 1 gouraud)
    uint32_t m_matFaded[4];                   // +0x50: diffuse, specular, ambient, emissive after the fade
    float m_shininess;                        // SHIN (+0x60: the specular power)
    uint32_t m_diffuse, m_specular, m_ambient, m_emissive;   // DIFF, SPEC, AMBI, EMIS (+0x64..+0x70; D3DCOLOR)
    uint32_t m_savedFog;                      // +0x74: the fog colour d3dShader::vfunc_12 put aside
    bool m_twoSided;                          // 2SID (+0x7c)
    bool m_skinned;                           // d3dExtHardwareSkinning::vfunc_6 sets it around its draw (+0x7d)
    // the kinds' own parameters
    int m_layerMode;                          // layered TBLM (+0x88, default 4: modulate)
    int m_layerPath;                          // layered CLYR (+0x8c)
    bool m_noLayer;                           // layeredReflect LRSA (+0x8c): leave the TTEX layer out
    uint32_t m_envColour;                     // environment ENVB (+0x88), refract REFC (+0x90)
    float m_refractBlend;                     // refract REFB (+0x8c): the factor's alpha and the intensity
    float m_refractScale;                     // refract REFI (+0x88, default 10): the refraction's offset scale
    int m_savedMode;                          // refract: what its pass set-up put aside (+0x94, +0x98)
    bool m_savedAlphaTest;
    void setTexture(int which, bgfxObject* t);
    void fade();                              // FUN_003335e0: the faded material, mode and alpha reference
    void applyBlendAndTest();                 // FUN_0032a260: blend from the mode, the alpha test
    // A parameter by key, as the base's slots 5-8 set it (walks our tables): for the backend's own callers
    // (the self-test on the host, where the base slots are stubs). Returns false for an unknown key.
    bool setParam(int table, uint32_t key, const void* value);
};

// What slot 21 hands out (d3dShader's five words at +0x50, as FUN_00324270 reads them): the material.
struct ShaderMaterial {
    uint32_t diffuse, specular, ambient, emissive;   // D3DCOLOR
    uint32_t shininessBits;                   // the specular power (float bits)
};

// Stands in for pure3d::d3dSimpleShader (25 slots; pddi shader name: simple, lightweight). Only the slots d3dSimpleShader overrides.
class bgfxSimpleShader : public bgfxShader {
  public:
    explicit bgfxSimpleShader(bgfxContext* context);
    virtual int vfunc_11();                   // slot 11: d3dSimpleShader 0x32a440 (pure3d/d3dSimpleShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dSimpleShader 0x32aa70 (pure3d/d3dSimpleShader.cpp)
    virtual void vfunc_21(void*);             // slot 21: d3dSimpleShader 0x32a450 (pure3d/d3dSimpleShader.cpp)
    virtual bool vfunc_22();                  // slot 22: d3dSimpleShader 0x32a540 (pure3d/d3dSimpleShader.cpp)
    virtual void* vfunc_23();                 // slot 23: d3dSimpleShader 0x32a570 (pure3d/d3dSimpleShader.cpp)
    virtual void vfunc_24();                  // slot 24: d3dSimpleShader 0x32aca0 (pure3d/d3dSimpleShader.cpp)
};

// Stands in for pure3d::d3dLayeredShader (25 slots; pddi shader name: layered). Only the slots d3dLayeredShader overrides.
class bgfxLayeredShader : public bgfxShader {
  public:
    explicit bgfxLayeredShader(bgfxContext* context);
    virtual int vfunc_11();                   // slot 11: d3dLayeredShader 0x32d960 (pure3d/d3dLayeredShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dLayeredShader 0x32dc40 (pure3d/d3dLayeredShader.cpp)
    virtual bool vfunc_22();                  // slot 22: d3dLayeredShader 0x32d970 (pure3d/d3dLayeredShader.cpp)
    virtual void* vfunc_23();                 // slot 23: d3dLayeredShader 0x32d9a0 (pure3d/d3dLayeredShader.cpp)
    virtual void vfunc_24();                  // slot 24: d3dLayeredShader 0x32e400 (pure3d/d3dLayeredShader.cpp)
};

// Stands in for pure3d::d3dBuildingShader (25 slots; pddi shader name: layeredReflect). Only the slots d3dBuildingShader overrides.
class bgfxBuildingShader : public bgfxShader {
  public:
    explicit bgfxBuildingShader(bgfxContext* context);
    virtual int vfunc_11();                   // slot 11: d3dBuildingShader 0x3322f0 (pure3d/d3dBuildingShader.cpp)
    virtual void vfunc_12();                  // slot 12: d3dBuildingShader 0x332620 (pure3d/d3dBuildingShader.cpp)
    virtual void vfunc_13();                  // slot 13: d3dBuildingShader 0x3326d0 (pure3d/d3dBuildingShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dBuildingShader 0x332310 (pure3d/d3dBuildingShader.cpp)
    virtual void* vfunc_23();                 // slot 23: d3dBuildingShader 0x332300 (pure3d/d3dBuildingShader.cpp)
};

// Stands in for pure3d::d3dReflShader (25 slots; pddi shader name: environment). Only the slots d3dReflShader overrides.
class bgfxReflShader : public bgfxShader {
  public:
    explicit bgfxReflShader(bgfxContext* context);
    virtual int vfunc_11();                   // slot 11: d3dReflShader 0x32c2f0 (pure3d/d3dReflShader.cpp)
    virtual void vfunc_12();                  // slot 12: d3dReflShader 0x32c300 (pure3d/d3dReflShader.cpp)
    virtual void vfunc_13();                  // slot 13: d3dReflShader 0x32c3b0 (pure3d/d3dReflShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dReflShader 0x32c520 (pure3d/d3dReflShader.cpp)
};

// Stands in for pure3d::d3dRefractVertexShader (25 slots; pddi shader name: refract). Only the slots d3dRefractVertexShader overrides.
class bgfxRefractShader : public bgfxShader {
  public:
    explicit bgfxRefractShader(bgfxContext* context);
    virtual int vfunc_11();                   // slot 11: d3dRefractVertexShader 0x32ef90 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_12();                  // slot 12: d3dRefractVertexShader 0x32f270 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_13();                  // slot 13: d3dRefractVertexShader 0x32f280 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dRefractVertexShader 0x32efa0 (pure3d/d3dRefractVertexShader.cpp)
    virtual bool vfunc_22();                  // slot 22: d3dRefractVertexShader 0x32f240 (pure3d/d3dRefractVertexShader.cpp)
    virtual void* vfunc_23();                 // slot 23: d3dRefractVertexShader 0x32f250 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_24();                  // slot 24: d3dRefractVertexShader 0x32f3b0 (pure3d/d3dRefractVertexShader.cpp)
};

// Stands in for pure3d::d3dFBEffectsShader (25 slots; pddi shader name: fbeffectsshader). Only the slots d3dFBEffectsShader overrides.
class bgfxFBEffectsShader : public bgfxShader {
  public:
    explicit bgfxFBEffectsShader(bgfxContext* context);
    // 0x328720: SAT +0x80, BRIT +0x84, MDPT +0x88 (0.5), CONT +0x8c, TINT +0x90 (opaque white), CLRE +0x94 (on/off);
    // UPDT adds them to the frame's average (FUN_003285d0)
    float m_fxSat, m_fxBright, m_fxMid, m_fxContrast;
    uint32_t m_fxTint;
    bool m_fxOn;
    virtual int vfunc_11();                   // slot 11: d3dFBEffectsShader 0x328520 (pure3d/d3dFBEffectsShader.cpp)
    virtual void vfunc_12();                  // slot 12: d3dFBEffectsShader 0x328540 (pure3d/d3dFBEffectsShader.cpp)
    virtual void vfunc_13();                  // slot 13: d3dFBEffectsShader 0x328550 (pure3d/d3dFBEffectsShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dFBEffectsShader 0x328530 (pure3d/d3dFBEffectsShader.cpp)
};

// Stands in for pure3d::d3dErrorShader (25 slots; pddi shader name: error (the fallback)). Only the slots d3dErrorShader overrides.
class bgfxErrorShader : public bgfxShader {
  public:
    explicit bgfxErrorShader(bgfxContext* context);
    virtual int vfunc_11();                   // slot 11: d3dErrorShader 0x32b0b0 (pure3d/d3dErrorShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dErrorShader 0x32b120 (pure3d/d3dErrorShader.cpp)
};

// The extensions (pddiExtension: slot 0 is the virtual destructor). Stubs; the context creates one of each.
class bgfxExtension {
  public:
    virtual ~bgfxExtension() {}               // slot 0
};

// Stands in for pure3d::d3dExtAntialiasControl.
class bgfxExtAntialiasControl : public bgfxExtension {
  public:
    enum { kClass = kClassExtAntialiasControl };
    explicit bgfxExtAntialiasControl(bgfxContext* context) : m_context(context), m_on(false), m_quadClear(false) {}
    virtual void vfunc_1(unsigned char);      // slot 1: d3dExtAntialiasControl 0x322000 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_2(unsigned char);      // slot 2: d3dExtAntialiasControl 0x322030 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_3();                   // slot 3: d3dExtAntialiasControl 0x322010 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual unsigned int vfunc_4();           // slot 4: d3dExtAntialiasControl 0x322020 (pure3d/d3dExtFramebufferEffects.cpp)
    bgfxContext* m_context;
    bool m_on, m_quadClear;
};

// Stands in for pure3d::d3dExtFrameBufferTexture.
class bgfxExtFrameBufferTexture : public bgfxExtension {
  public:
    enum { kClass = kClassExtFrameBufferTexture };
    explicit bgfxExtFrameBufferTexture(bgfxContext* context) : m_context(context) {}
    virtual void* vfunc_1(int);               // slot 1: d3dExtFrameBufferTexture 0x323be0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_2();                   // slot 2: d3dExtFrameBufferTexture 0x323c50 (pure3d/d3dExtFramebufferEffects.cpp)
    bgfxContext* m_context;
};

// Stands in for pure3d::d3dExtFramebufferEffects (bgfx_effects.cpp): the game's full-screen passes, run by
// CRenderManager after the 3D scene each frame (FUN_001b93a0) and by the HUD's motion-trail overlay (FUN_001c22f0).
// Slots: 1/2 the overlay (the previous frame drawn over the frame, zoomed, at an alpha), 3/4/5/6 the colour correction
// (enable, settings, settings from the fbeffects shaders of the data, the pass), 7/8/9 the bloom (enable, settings,
// the passes: bright pass to half size, a tinted copy to quarter size, a separable gaussian, the composite). The
// fields keep the game's meanings (offsets in the comments); the passes are views of the context (bgfxContext::fx*).
class bgfxExtFramebufferEffects : public bgfxExtension {
  public:
    enum { kClass = kClassExtFramebufferEffects };
    explicit bgfxExtFramebufferEffects(bgfxContext* context);    // 0x3224b0's defaults
    virtual ~bgfxExtFramebufferEffects();
    virtual void vfunc_1(unsigned char, float, float, unsigned char); // slot 1: 0x3225c0: the overlay's on, alpha, scale, split
    virtual void vfunc_2();                   // slot 2: d3dExtFramebufferEffects 0x3226b0: draw the overlay
    virtual void vfunc_3(unsigned char);      // slot 3: d3dExtFramebufferEffects 0x320530: colour correction on/off
    virtual void vfunc_4(float, float, float, float, unsigned int); // slot 4: 0x3239e0: its settings (sat, bright, contrast, mid, tint)
    virtual void vfunc_5();                   // slot 5: d3dExtFramebufferEffects 0x3202a0 -> FUN_003287a0: the fbeffects shaders' average
    virtual void vfunc_6();                   // slot 6: d3dExtFramebufferEffects 0x324a00: the colour correction pass
    virtual void vfunc_7(unsigned char);      // slot 7: d3dExtFramebufferEffects 0x320290: bloom on/off
    virtual void vfunc_8(float, unsigned int, float, float, unsigned int, float, float, float); // slot 8: 0x322cd0: bloom settings
    virtual void vfunc_9();                   // slot 9: d3dExtFramebufferEffects 0x325110: the bloom passes
    virtual void vfunc_10(int);               // slot 10: d3dExtFramebufferEffects 0x3225e0: nothing
    bgfxContext* m_context;
    // the overlay (+0x08..+0x1c)
    bgfxShader* m_overlayShader;              // +0x08: a "simple" shader with TEX = the previous frame
    bgfxTexture* m_overlayTex;                // +0x0c
    bool m_overlayOn;                         // +0x10
    float m_overlayAlpha, m_overlayScale;     // +0x14 (0.9), +0x18
    bool m_overlaySplit;                      // +0x1c: three passes, one colour channel each, scales 4 apart
    // colour correction (+0x68..+0x88; vfunc_4)
    float m_ccScale, m_ccAmount, m_ccCurve, m_ccBias, m_ccResult;
    bool m_ccBusy, m_ccEnabled;               // +0x7c (no resources), +0x7d (vfunc_3)
    float m_ccTint[3];                        // +0x80 red, green, blue
    // bloom (+0xb8..+0x18c; vfunc_8)
    float m_bAmount, m_bBlend, m_bContrast, m_bRadius, m_bMix, m_bD0, m_bD4, m_bSigma;
    uint32_t m_bFactor;                       // +0xdc: the quarter copy's tint (texture factor)
    float m_bWeights[3];                      // +0xe0: the bright pass's channel weights (the colour, summing to 1)
    bool m_bEnabled;                          // +0xec (vfunc_7; on by default)
    bool m_blurBusy;                          // +0xb4
    float m_positions[20], m_values[20];      // +0xf0, +0x140: the gaussian's tap offsets and weights
    // resources (bgfx handles; 0xffff none): the full-size copy (+0x20), the half (+0xa8) and quarter (+0xac, +0xb0)
    // targets, the previous frame (what GetBackBuffer(-1) is to the overlay: the front buffer)
    unsigned m_full, m_half, m_halfFb, m_quarter[2], m_quarterFb[2], m_w, m_h;
    unsigned m_fullFb;                        // the full copy's frame buffer (quad copies only)
    bool ensureResources();
    void releaseResources();
    // FUN_00324660: the colour pass from the full copy into the current fx view (17 shader variants: level, side)
    void filterPass(const float* weights, float f1, float f2, const float* colour, float f3, float f4, int w, int h);
    // FUN_00323130: the separable gaussian between two quarter targets; returns the one holding the result
    int blur(int source, int target);
};

// the fbeffects shaders' settings, accumulated by context slot 32 / UPDT (FUN_003285d0) and averaged by
// d3dExtFramebufferEffects::vfunc_5 (FUN_003287a0) into the colour correction (bgfx_effects.cpp)
void fbEffectsAccumulate(bgfxShader* shader);

// Stands in for pure3d::d3dExtGammaControl.
class bgfxExtGammaControl : public bgfxExtension {
  public:
    enum { kClass = kClassExtGammaControl };
    explicit bgfxExtGammaControl(bgfxContext* context) : m_context(context) {}
    virtual void vfunc_1();                   // slot 1: d3dExtGammaControl 0x324590 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_2();                   // slot 2: d3dExtGammaControl 0x3245a0 (pure3d/d3dExtFramebufferEffects.cpp)
    bgfxContext* m_context;
};

// Stands in for pure3d::d3dExtGlobalProjectedTexture.
class bgfxExtGlobalProjectedTexture : public bgfxExtension {
  public:
    enum { kClass = kClassExtGlobalProjectedTexture };
    explicit bgfxExtGlobalProjectedTexture(bgfxContext* context) : m_context(context) {}
    virtual void vfunc_1(int, void*, void*);  // slot 1: d3dExtGlobalProjectedTexture 0x3220a0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual bool vfunc_2(int, void*, void*);  // slot 2: d3dExtGlobalProjectedTexture 0x3220f0 (pure3d/d3dExtFramebufferEffects.cpp)
    bgfxContext* m_context;
};

// Stands in for pure3d::d3dExtHardwareSkinning.
class bgfxExtHardwareSkinning : public bgfxExtension {
  public:
    enum { kClass = kClassExtHardwareSkinning };
    explicit bgfxExtHardwareSkinning(bgfxContext* context) : m_context(context) {}
    virtual unsigned int vfunc_1(unsigned int); // slot 1: d3dExtHardwareSkinning 0x3221e0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_2();                   // slot 2: d3dExtHardwareSkinning 0x322260 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_3();                   // slot 3: d3dExtHardwareSkinning 0x322270 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_4(int);                // slot 4: d3dExtHardwareSkinning 0x3221f0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_5(int bone, const float* matrix); // slot 5: d3dExtHardwareSkinning 0x322200: bone matrix
    virtual void vfunc_6(bgfxShader* shader, bgfxPrimBuffer* buffer); // slot 6: d3dExtHardwareSkinning 0x3245d0: draw skinned
    bgfxContext* m_context;
};

// Stands in for pure3d::d3dExtReadPixels.
class bgfxExtReadPixels : public bgfxExtension {
  public:
    enum { kClass = kClassExtReadPixels };
    explicit bgfxExtReadPixels(bgfxContext* context) : m_context(context) {}
    virtual void vfunc_1(void*, void*, void*); // slot 1: d3dExtReadPixels 0x320160 (pure3d/d3dExtFramebufferEffects.cpp)
    bgfxContext* m_context;
};

// Stands in for pure3d::d3dExtVertexProgram (bgfx_ext.cpp): how the prim group loaders give a mesh its vertex
// program. The game's handles are Direct3D vertex shader handles from the declaration builder (FUN_003290e0, for the
// shader's program name and the vertex format); ours are the program name itself (the static string slot 23 of the
// shader returns), which the prim buffer (+0x3c) or the streamed prim group's binding (slot 6) carries to the draw.
class bgfxExtVertexProgram : public bgfxExtension {
  public:
    enum { kClass = kClassExtVertexProgram };
    explicit bgfxExtVertexProgram(bgfxContext* context) : m_context(context) {}
    virtual void vfunc_1();                   // slot 1: d3dExtVertexProgram 0x322420 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual int vfunc_2(bgfxShader*, int, int, int, unsigned char); // slot 2: 0x322440: the handle for a shader
    virtual void vfunc_3();                   // slot 3: d3dExtVertexProgram 0x322430 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual bool vfunc_4(bgfxShader*, unsigned char); // slot 4: 0x322360: does the shader have a program (slot 22)
    virtual void vfunc_5(bgfxPrimBuffer*, int); // slot 5: 0x322390: a prim buffer's handle (+0x3c)
    virtual void vfunc_6(unsigned int);       // slot 6: 0x3223a0: the handle prim streams draw with (0: none)
    virtual void vfunc_7(int, int, int);      // slot 7: d3dExtVertexProgram 0x3223c0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_8(int, int);           // slot 8: d3dExtVertexProgram 0x322400 (pure3d/d3dExtFramebufferEffects.cpp)
    bgfxContext* m_context;
};

// Stands in for pure3d::d3dExtVisibilityTest (bgfx_ext.cpp): occlusion queries.
class bgfxExtVisibilityTest : public bgfxExtension {
  public:
    enum { kClass = kClassExtVisibilityTest, kQueries = 64, kIndices = 16 };
    explicit bgfxExtVisibilityTest(bgfxContext* context);
    virtual unsigned int vfunc_1();           // slot 1: d3dExtVisibilityTest 0x3222c0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_2();                   // slot 2: d3dExtVisibilityTest 0x3222d0: begin a test
    virtual void vfunc_3(int);                // slot 3: d3dExtVisibilityTest 0x3222e0: end test n
    virtual unsigned int vfunc_4(int);        // slot 4: d3dExtVisibilityTest 0x3222f0 (pure3d/d3dExtFramebufferEffects.cpp)
    bgfxContext* m_context;
    unsigned m_query[kQueries], m_last[kQueries];
    int m_byIndex[kIndices];
    unsigned m_frame, m_next;
    int m_current;
    bool m_noQueries;
};

// bgfx_draw.cpp: the packed prim-buffer layout (FUN_00326e90 / FUN_003290e0) and the active-shader bookkeeping
int packedStride(unsigned flags);
void packedOffsets(unsigned flags, int* weights, int* indices, int* normal, int* colours, int* colour2, int* uv,
                   int* extra);
void shaderDestroyed(bgfxShader* shader);

// bgfx_combiner.cpp: every combiner key the shader classes can produce (tools/native_gfx.py combiners)
int enumerateCombinerKeys(bgfxContext* ctx, void (*out)(const char* key, const char* example));
// bgfx_effects.cpp: the filter program's parameters (u_fxProg, u_fxK) for colour-pass level `lv` (1..64) and side
// 0/1, as the colour pass sets them (tools/xps.py prove reads them through pddi_smoke --fx-params)
void fxProgramParams(int lv, int side, float* prog8);

// selftest_scene.cpp: the self-test scene (host smoke test, HULK_GFX_SELFTEST) and its expected pixels
struct SelfTestProbe {
    int x, y;                                 // pixel, top-left origin
    unsigned rgb;                             // expected 0xRRGGBB
    int tolerance;                            // per channel
    const char* what;
    bool window;                              // x, y are the window's pixels (else the frame's: mapped through the
                                              // display's present rectangle when the shot is of a scaled window)
};
int selfTestPages();                          // pages of the scene (0: G3's draw path, 1-3: G2's, 5-8: G4's,
                                              // 9: window scaling, G5)
int selfTestScene(bgfxContext* ctx, int page);   // one frame's draws (between begin and end frame) -> probes
int selfTestProbes(const SelfTestProbe** out);
int selfTestCheck(const unsigned char* px, unsigned w, unsigned h, unsigned pitch, bool bgra, bool yflip,
                  void (*out)(const char* line));   // -> probes that pass

} // namespace pddi
} // namespace hulk

// The entry point the engine calls instead of d3dCreateDevice (0x31ba60): version (0x12, 0xb) -> the device.
extern "C" int hulk_pddi_create_device(int major, int minor, void** out);
