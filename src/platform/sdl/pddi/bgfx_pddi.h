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

namespace hulk {
namespace pddi {

class bgfxDevice;
class bgfxDisplay;
class bgfxContext;
class bgfxPrimStream;
class bgfxShader;

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
// d3dCreateDevice 0x31ba60). Slot 5/6: the current display, 7: new display (0x49c bytes in the game), 8: new context
// (0x450), 9: new texture (0xf8) from a parameter block, 10: new prim buffer (0x40), 11: shader registration.
class bgfxDevice : public bgfxObject {
  public:
    enum { kClass = kClassDevice };
    bgfxDevice();
    virtual ~bgfxDevice();
    virtual void vfunc_4(int);                // slot 4: d3dDevice 0x31b7d0 (pure3d/d3dDevice.cpp)
    virtual void vfunc_5(void*);              // slot 5: d3dDevice 0x31b810 (pure3d/d3dDevice.cpp)
    virtual void* vfunc_6();                  // slot 6: d3dDevice 0x31b820 (pure3d/d3dDevice.cpp)
    virtual void* vfunc_7(int);               // slot 7: d3dDevice 0x31b830 (pure3d/d3dDevice.cpp)
    virtual void* vfunc_8(void*);             // slot 8: d3dDevice 0x31b860 (pure3d/d3dDevice.cpp)
    virtual void* vfunc_9(int);                // slot 9: d3dDevice 0x31b8a0 (pure3d/d3dDevice.cpp)
    virtual void* vfunc_10(void*);            // slot 10: d3dDevice 0x31b960 (pure3d/d3dDevice.cpp)
    virtual void vfunc_11(int, int);          // slot 11: d3dDevice 0x31b9d0 (pure3d/d3dDevice.cpp)
    virtual void vfunc_12(int, int);          // slot 12: d3dDevice 0x31b9f0 (pure3d/d3dDevice.cpp)
    virtual void vfunc_13(int);               // slot 13: base pddiDevice 0x31e230 (pure3d/pddiBaseContext.cpp)

    int m_lastError;                          // +8 (slot 10 stores the prim buffer's status here)
    bgfxDisplay* m_display;                   // +0xc (slots 5/6)
    bgfxContext* m_context;
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
                  void* callback = 0);     // callback: a bgfx::CallbackI (screenshots, traces) or 0
    void hostShutdown();
    bgfxDevice* m_device;
    unsigned m_width, m_height, m_depth;
    bool m_initialised;
    unsigned m_frame;
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
    virtual void vfunc_7(int);                // slot 7: base pddiBaseContext 0x31d500 (pure3d/pddiBaseContext.cpp)
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
    virtual void vfunc_36(int);               // slot 36: base pddiBaseContext 0x31d920 (pure3d/pddiBaseContext.cpp)
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
    virtual void vfunc_82(int);               // slot 82: base pddiBaseContext 0x31e180 (pure3d/pddiBaseContext.cpp)
    virtual float vfunc_83(int);              // slot 83: base pddiBaseContext 0x31e1a0 (pure3d/pddiBaseContext.cpp)
    virtual unsigned int vfunc_84();          // slot 84: d3dContext 0x321d90 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_85(unsigned char);     // slot 85: base pddiBaseContext 0x31e1b0 (pure3d/pddiBaseContext.cpp)
    virtual unsigned char vfunc_86();         // slot 86: base pddiBaseContext 0x31e1c0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_87(int);               // slot 87: base pddiBaseContext 0x31f290 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_88(unsigned char);     // slot 88: base pddiBaseContext 0x31e9b0 (pure3d/pddiBaseContext.cpp)
    virtual void vfunc_89(int);               // slot 89: d3dContext 0x321ea0 (pure3d/d3dExtFramebufferEffects.cpp)
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
    ClearInfo* clearInfo();
    void hostSetClear(unsigned colour, float depth, unsigned stencil);
    void setViewTransform(const float* view, const float* proj);
    void submit(bgfxPrimStream* stream);
    int m_base[(0x14c - 8) / 4];              // +8..+0x14c: the portable base's data (see above)
    bgfxDisplay* m_display;
    bgfxDevice* m_device;
    bgfxPrimStream* m_stream;
    bgfxShader* m_defaultShader;
    ClearInfo m_hostClear;
    unsigned m_cull;                          // slot 54
    unsigned m_drawIndex;                     // draws in this frame (drawlog)
    unsigned m_program;                       // bgfx::ProgramHandle of the fixed-function stand-in
    float m_view[16], m_proj[16];
};

// Stands in for pure3d::d3dTexture (vftable 0x4333ac, 21 slots). 4-10: size/format/mip queries, 11: palette,
// 12: ?, 13/14: lock/unlock a mip level (the unlock swizzles on the Xbox: here it uploads linear), 15/20: base.
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
    virtual void vfunc_12(int);               // slot 12: d3dTexture 0x3268d0 (pure3d/d3dTexture.cpp)
    virtual void vfunc_13(int, int);          // slot 13: d3dTexture 0x326900 (pure3d/d3dTexture.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dTexture 0x326a10 (pure3d/d3dTexture.cpp)
    virtual void vfunc_15(int, int, int);     // slot 15: base pddiTexture 0x325ee0 (pure3d/pddiTexture.cpp)
    virtual void vfunc_16();                  // slot 16: d3dTexture 0x326ad0 (pure3d/d3dTexture.cpp)
    virtual void vfunc_17();                  // slot 17: d3dTexture 0x326ae0 (pure3d/d3dTexture.cpp)
    virtual void vfunc_18(unsigned int);      // slot 18: d3dTexture 0x326af0 (pure3d/d3dTexture.cpp)
    virtual unsigned int vfunc_19();          // slot 19: d3dTexture 0x326280 (pure3d/d3dTexture.cpp)
    virtual void vfunc_20(int, int, int, int, int, int, int); // slot 20: base pddiTexture 0x325ef0 (pure3d/pddiTexture.cpp)

    bgfxContext* m_context;
    unsigned m_handle;                        // bgfx::TextureHandle
    unsigned m_width, m_height, m_format, m_mips;
};

// Stands in for pure3d::d3dPrimBuffer (vftable 0x4334b4, 15 slots): a static vertex (+ index) buffer, filled
// through a pddiPrimBufferStream (slot 7 or so) and drawn by bgfxContext::vfunc_32.
class bgfxPrimBuffer : public bgfxObject {
  public:
    enum { kClass = kClassPrimBuffer };
    explicit bgfxPrimBuffer(bgfxContext* context);
    virtual ~bgfxPrimBuffer();
    virtual void vfunc_4();                   // slot 4: d3dPrimBuffer 0x327190 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_5(void*);              // slot 5: d3dPrimBuffer 0x3271f0 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_6();                   // slot 6: base pddiPrimBuffer 0x326d60 (pure3d/pddiPrimBuffer.cpp)
    virtual void vfunc_7();                   // slot 7: d3dPrimBuffer 0x327200 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_8(unsigned int);       // slot 8: d3dPrimBuffer 0x327220 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_9(void*, int);         // slot 9: d3dPrimBuffer 0x3272b0 (pure3d/d3dPrimBufferStream.cpp)
    virtual bool vfunc_10(int);               // slot 10: d3dPrimBuffer 0x327230 (pure3d/d3dPrimBufferStream.cpp)
    virtual unsigned int vfunc_11(int);       // slot 11: d3dPrimBuffer 0x327250 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_12();                  // slot 12: d3dPrimBuffer 0x327280 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_13(int, int);          // slot 13: d3dPrimBuffer 0x3272a0 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dPrimBuffer 0x3270a0 (pure3d/d3dPrimBufferStream.cpp)

    bgfxContext* m_context;
    unsigned m_vb, m_ib;                      // bgfx handles
};

// Stands in for pure3d::d3dPrimBufferStream (vftable 0x4334f4, 18 slots; no pddiObject base): writes vertices into
// a prim buffer. 0: position (x, y, z; floats passed as words) and next vertex, 1: normal, 2/3: two more vectors,
// 4: colour (value, set), 6: uv (u, v, set), 9/10: skin index/weights, 11: packed normal, 12-16: whole vertices
// (position + normal/colour/uv in the combinations the engine uses).
class bgfxPrimBufferStream final {      // final: no virtual destructor (the game class has no slot for one)
  public:
    enum { kClass = kClassPrimBufferStream };
    explicit bgfxPrimBufferStream(bgfxPrimBuffer* buffer);
    virtual void vfunc_0(int, int, int);      // slot 0: d3dPrimBufferStream 0x327450 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_1(int, int, int);      // slot 1: d3dPrimBufferStream 0x327480 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_2(unsigned long, unsigned long, unsigned long); // slot 2: d3dPrimBufferStream 0x327530 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_3(unsigned int, unsigned int, unsigned int); // slot 3: d3dPrimBufferStream 0x327550 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_4(int, int);           // slot 4: d3dPrimBufferStream 0x327570 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_5(int, int);           // slot 5: d3dPrimBufferStream 0x327420 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_6(float, float, int);  // slot 6: d3dPrimBufferStream 0x327590 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_7(int, int, int, int); // slot 7: d3dPrimBufferStream 0x327430 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_8(int, int, int, int, int); // slot 8: d3dPrimBufferStream 0x327440 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_9(unsigned int);       // slot 9: d3dPrimBufferStream 0x3275b0 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_10(char, char, char, char); // slot 10: d3dPrimBufferStream 0x3275c0 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_11(int, int, int);     // slot 11: d3dPrimBufferStream 0x327600 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_12(int, int, int);     // slot 12: d3dPrimBufferStream 0x327750 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_13(int, int, int);     // slot 13: d3dPrimBufferStream 0x327710 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_14(int, int);          // slot 14: d3dPrimBufferStream 0x3276d0 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_15(void*, void*);      // slot 15: d3dPrimBufferStream 0x327690 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_16(int, int);          // slot 16: d3dPrimBufferStream 0x327660 (pure3d/d3dPrimBufferStream.cpp)
    virtual void vfunc_17();                  // slot 17: d3dPrimBufferStream 0x3277a0 (pure3d/d3dPrimBufferStream.cpp)

    bgfxPrimBuffer* m_buffer;
};

// Stands in for pure3d::d3dPrimStream (vftable 0x432578: d3dBasePrimStream's 2 slots), what bgfxContext::vfunc_30
// returns. Portable code writes vertices inline through the pointers below and calls FUN_0008ef00 (game code) to
// advance, so the first fields keep d3dPrimStream's layout: slot 0 = (re)start a batch (lock; bool: carry the
// pending vertices over), slot 1 = draw what was written.
class bgfxPrimStream final {            // final: no virtual destructor (2 slots, as the game's)
  public:
    enum { kClass = kClassPrimStream };
    explicit bgfxPrimStream(bgfxContext* context);
    virtual void vfunc_0(bool carry);         // slot 0: d3dPrimStream 0x31be40
    virtual void vfunc_1();                   // slot 1: d3dPrimStream 0x31c080
    int stride;                               // +4 (game layout from here to +0x24)
    char* posPtr;                             // +8
    char* normalPtr;                          // +0xc
    char* colorPtr;                           // +0x10
    char* uvPtr;                              // +0x14
    int pad18;
    int vertCount;                            // +0x1c
    int pendingCount;                         // +0x20
    // ours
    void begin(bgfxShader* shader, int kind, unsigned flags, int count);
    void vertex();                            // what the engine's FUN_0008ef00 does after writing one vertex
    bgfxContext* m_context;
    bgfxShader* m_shader;
    int m_kind;                               // pddi prim kind (0 tri list, 1 tri strip, 2 line list, 3 line strip, 4 points)
    unsigned m_flags;                         // vertex flags: 0x10 normal, 0x20 colour, 0x4000 colour sets, low 4 bits uv sets
    int m_uvCount;
    enum { kMaxVerts = 4096 };
    char m_data[kMaxVerts * 64];
};

// Stands in for pure3d::d3dShader (vftable 0x433ffc, 25 slots): pddiBaseShader's slots are base, d3dShader's own
// (12/13: per-draw material colour, 21-24: vertex program, constants) and the pure ones are ours. The game's data
// layout: pddiBaseShader's words at +8/+0xc, then d3dShader's (+0x10 context, +0x1c mode, ...).
class bgfxShader : public bgfxObject {
  public:
    enum { kClass = kClassShader };
    explicit bgfxShader(bgfxContext* context);
    virtual ~bgfxShader();
    virtual void vfunc_4();                   // slot 4: pure in the game's class
    virtual void vfunc_5(int, int);           // slot 5: base pddiBaseShader 0x3279e0 (pure3d/pddiBaseShader.cpp)
    virtual bool vfunc_6(int, int);           // slot 6: base pddiBaseShader 0x327a40 (pure3d/pddiBaseShader.cpp)
    virtual unsigned char vfunc_7(int, int);  // slot 7: base pddiBaseShader 0x327aa0 (pure3d/pddiBaseShader.cpp)
    virtual void vfunc_8(int, int);           // slot 8: base pddiBaseShader 0x327b00 (pure3d/pddiBaseShader.cpp)
    virtual bool vfunc_9(int, int);           // slot 9: base pddiBaseShader 0x327b60 (pure3d/pddiBaseShader.cpp)
    virtual bool vfunc_10(int, int);          // slot 10: base pddiBaseShader 0x327bc0 (pure3d/pddiBaseShader.cpp)
    virtual int vfunc_11();                   // slot 11: pure in the game's class
    virtual void vfunc_12();                  // slot 12: d3dShader 0x333420 (pure3d/d3dShader.cpp)
    virtual void vfunc_13();                  // slot 13: d3dShader 0x3334a0 (pure3d/d3dShader.cpp)
    virtual void vfunc_14(int);               // slot 14: pure in the game's class
    virtual void vfunc_15();                  // slot 15: base pddiBaseShader 0x327980 (pure3d/pddiBaseShader.cpp)
    virtual void vfunc_16();                  // slot 16: base pddiBaseShader 0x327990 (pure3d/pddiBaseShader.cpp)
    virtual void vfunc_17();                  // slot 17: base pddiBaseShader 0x3279a0 (pure3d/pddiBaseShader.cpp)
    virtual void vfunc_18();                  // slot 18: base pddiBaseShader 0x3279b0 (pure3d/pddiBaseShader.cpp)
    virtual void vfunc_19();                  // slot 19: base pddiBaseShader 0x3279c0 (pure3d/pddiBaseShader.cpp)
    virtual void vfunc_20();                  // slot 20: base pddiBaseShader 0x3279d0 (pure3d/pddiBaseShader.cpp)
    virtual void vfunc_21(void*);             // slot 21: d3dShader 0x333370 (pure3d/d3dShader.cpp)
    virtual bool vfunc_22();                  // slot 22: d3dShader 0x3286b0 (pure3d/d3dFBEffectsShader.cpp)
    virtual void* vfunc_23();                 // slot 23: d3dShader 0x3286c0 (pure3d/d3dFBEffectsShader.cpp)
    virtual void vfunc_24();                  // slot 24: d3dShader 0x3286d0 (pure3d/d3dFBEffectsShader.cpp)

    int m_base[2];                            // +8, +0xc: pddiBaseShader's data
    bgfxContext* m_context;                   // +0x10
    int m_kind;                               // ShaderKind
};

// Stands in for pure3d::d3dSimpleShader (25 slots; pddi shader name: simple, lightweight). Only the slots d3dSimpleShader overrides.
class bgfxSimpleShader : public bgfxShader {
  public:
    explicit bgfxSimpleShader(bgfxContext* context);
    virtual void vfunc_4();                   // slot 4: d3dSimpleShader 0x32a430 (pure3d/d3dSimpleShader.cpp)
    virtual int vfunc_11();                   // slot 11: d3dSimpleShader 0x32a440 (pure3d/d3dSimpleShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dSimpleShader 0x32aa70 (pure3d/d3dSimpleShader.cpp)
    virtual void vfunc_15();                  // slot 15: d3dSimpleShader 0x32a3f0 (pure3d/d3dSimpleShader.cpp)
    virtual void vfunc_16();                  // slot 16: d3dSimpleShader 0x32a400 (pure3d/d3dSimpleShader.cpp)
    virtual void vfunc_17();                  // slot 17: d3dSimpleShader 0x32a410 (pure3d/d3dSimpleShader.cpp)
    virtual void vfunc_18();                  // slot 18: d3dSimpleShader 0x32a420 (pure3d/d3dSimpleShader.cpp)
    virtual void vfunc_21(void*);             // slot 21: d3dSimpleShader 0x32a450 (pure3d/d3dSimpleShader.cpp)
    virtual bool vfunc_22();                  // slot 22: d3dSimpleShader 0x32a540 (pure3d/d3dSimpleShader.cpp)
    virtual void* vfunc_23();                 // slot 23: d3dSimpleShader 0x32a570 (pure3d/d3dSimpleShader.cpp)
    virtual void vfunc_24();                  // slot 24: d3dSimpleShader 0x32aca0 (pure3d/d3dSimpleShader.cpp)
};

// Stands in for pure3d::d3dLayeredShader (25 slots; pddi shader name: layered). Only the slots d3dLayeredShader overrides.
class bgfxLayeredShader : public bgfxShader {
  public:
    explicit bgfxLayeredShader(bgfxContext* context);
    virtual void vfunc_4();                   // slot 4: d3dLayeredShader 0x32d950 (pure3d/d3dLayeredShader.cpp)
    virtual int vfunc_11();                   // slot 11: d3dLayeredShader 0x32d960 (pure3d/d3dLayeredShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dLayeredShader 0x32dc40 (pure3d/d3dLayeredShader.cpp)
    virtual void vfunc_15();                  // slot 15: d3dLayeredShader 0x32d910 (pure3d/d3dLayeredShader.cpp)
    virtual void vfunc_16();                  // slot 16: d3dLayeredShader 0x32d920 (pure3d/d3dLayeredShader.cpp)
    virtual void vfunc_17();                  // slot 17: d3dLayeredShader 0x32d930 (pure3d/d3dLayeredShader.cpp)
    virtual void vfunc_18();                  // slot 18: d3dLayeredShader 0x32d940 (pure3d/d3dLayeredShader.cpp)
    virtual bool vfunc_22();                  // slot 22: d3dLayeredShader 0x32d970 (pure3d/d3dLayeredShader.cpp)
    virtual void* vfunc_23();                 // slot 23: d3dLayeredShader 0x32d9a0 (pure3d/d3dLayeredShader.cpp)
    virtual void vfunc_24();                  // slot 24: d3dLayeredShader 0x32e400 (pure3d/d3dLayeredShader.cpp)
};

// Stands in for pure3d::d3dBuildingShader (25 slots; pddi shader name: layeredReflect). Only the slots d3dBuildingShader overrides.
class bgfxBuildingShader : public bgfxShader {
  public:
    explicit bgfxBuildingShader(bgfxContext* context);
    virtual void vfunc_4();                   // slot 4: d3dBuildingShader 0x3322e0 (pure3d/d3dBuildingShader.cpp)
    virtual int vfunc_11();                   // slot 11: d3dBuildingShader 0x3322f0 (pure3d/d3dBuildingShader.cpp)
    virtual void vfunc_12();                  // slot 12: d3dBuildingShader 0x332620 (pure3d/d3dBuildingShader.cpp)
    virtual void vfunc_13();                  // slot 13: d3dBuildingShader 0x3326d0 (pure3d/d3dBuildingShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dBuildingShader 0x332310 (pure3d/d3dBuildingShader.cpp)
    virtual void vfunc_15();                  // slot 15: d3dBuildingShader 0x3322a0 (pure3d/d3dBuildingShader.cpp)
    virtual void vfunc_16();                  // slot 16: d3dBuildingShader 0x3322b0 (pure3d/d3dBuildingShader.cpp)
    virtual void vfunc_17();                  // slot 17: d3dBuildingShader 0x3322c0 (pure3d/d3dBuildingShader.cpp)
    virtual void vfunc_18();                  // slot 18: d3dBuildingShader 0x3322d0 (pure3d/d3dBuildingShader.cpp)
    virtual void* vfunc_23();                 // slot 23: d3dBuildingShader 0x332300 (pure3d/d3dBuildingShader.cpp)
};

// Stands in for pure3d::d3dReflShader (25 slots; pddi shader name: environment). Only the slots d3dReflShader overrides.
class bgfxReflShader : public bgfxShader {
  public:
    explicit bgfxReflShader(bgfxContext* context);
    virtual void vfunc_4();                   // slot 4: d3dReflShader 0x32c2e0 (pure3d/d3dReflShader.cpp)
    virtual int vfunc_11();                   // slot 11: d3dReflShader 0x32c2f0 (pure3d/d3dReflShader.cpp)
    virtual void vfunc_12();                  // slot 12: d3dReflShader 0x32c300 (pure3d/d3dReflShader.cpp)
    virtual void vfunc_13();                  // slot 13: d3dReflShader 0x32c3b0 (pure3d/d3dReflShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dReflShader 0x32c520 (pure3d/d3dReflShader.cpp)
    virtual void vfunc_15();                  // slot 15: d3dReflShader 0x32c2a0 (pure3d/d3dReflShader.cpp)
    virtual void vfunc_16();                  // slot 16: d3dReflShader 0x32c2b0 (pure3d/d3dReflShader.cpp)
    virtual void vfunc_17();                  // slot 17: d3dReflShader 0x32c2c0 (pure3d/d3dReflShader.cpp)
    virtual void vfunc_18();                  // slot 18: d3dReflShader 0x32c2d0 (pure3d/d3dReflShader.cpp)
};

// Stands in for pure3d::d3dRefractVertexShader (25 slots; pddi shader name: refract). Only the slots d3dRefractVertexShader overrides.
class bgfxRefractShader : public bgfxShader {
  public:
    explicit bgfxRefractShader(bgfxContext* context);
    virtual void vfunc_4();                   // slot 4: d3dRefractVertexShader 0x32ef80 (pure3d/d3dRefractVertexShader.cpp)
    virtual int vfunc_11();                   // slot 11: d3dRefractVertexShader 0x32ef90 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_12();                  // slot 12: d3dRefractVertexShader 0x32f270 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_13();                  // slot 13: d3dRefractVertexShader 0x32f280 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dRefractVertexShader 0x32efa0 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_15();                  // slot 15: d3dRefractVertexShader 0x32ef40 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_16();                  // slot 16: d3dRefractVertexShader 0x32ef50 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_17();                  // slot 17: d3dRefractVertexShader 0x32ef60 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_18();                  // slot 18: d3dRefractVertexShader 0x32ef70 (pure3d/d3dRefractVertexShader.cpp)
    virtual bool vfunc_22();                  // slot 22: d3dRefractVertexShader 0x32f240 (pure3d/d3dRefractVertexShader.cpp)
    virtual void* vfunc_23();                 // slot 23: d3dRefractVertexShader 0x32f250 (pure3d/d3dRefractVertexShader.cpp)
    virtual void vfunc_24();                  // slot 24: d3dRefractVertexShader 0x32f3b0 (pure3d/d3dRefractVertexShader.cpp)
};

// Stands in for pure3d::d3dFBEffectsShader (25 slots; pddi shader name: fbeffectsshader). Only the slots d3dFBEffectsShader overrides.
class bgfxFBEffectsShader : public bgfxShader {
  public:
    explicit bgfxFBEffectsShader(bgfxContext* context);
    virtual void vfunc_4();                   // slot 4: d3dFBEffectsShader 0x328510 (pure3d/d3dFBEffectsShader.cpp)
    virtual int vfunc_11();                   // slot 11: d3dFBEffectsShader 0x328520 (pure3d/d3dFBEffectsShader.cpp)
    virtual void vfunc_12();                  // slot 12: d3dFBEffectsShader 0x328540 (pure3d/d3dFBEffectsShader.cpp)
    virtual void vfunc_13();                  // slot 13: d3dFBEffectsShader 0x328550 (pure3d/d3dFBEffectsShader.cpp)
    virtual void vfunc_14(int);               // slot 14: d3dFBEffectsShader 0x328530 (pure3d/d3dFBEffectsShader.cpp)
    virtual void vfunc_16();                  // slot 16: d3dFBEffectsShader 0x328700 (pure3d/d3dFBEffectsShader.cpp)
    virtual void vfunc_17();                  // slot 17: d3dFBEffectsShader 0x3286f0 (pure3d/d3dFBEffectsShader.cpp)
    virtual void vfunc_18();                  // slot 18: d3dFBEffectsShader 0x3286e0 (pure3d/d3dFBEffectsShader.cpp)
};

// Stands in for pure3d::d3dErrorShader (25 slots; pddi shader name: error (the fallback)). Only the slots d3dErrorShader overrides.
class bgfxErrorShader : public bgfxShader {
  public:
    explicit bgfxErrorShader(bgfxContext* context);
    virtual void vfunc_4();                   // slot 4: d3dErrorShader 0x32b0a0 (pure3d/d3dErrorShader.cpp)
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
    explicit bgfxExtAntialiasControl(bgfxContext* context) : m_context(context) {}
    virtual void vfunc_1(unsigned char);      // slot 1: d3dExtAntialiasControl 0x322000 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_2(unsigned char);      // slot 2: d3dExtAntialiasControl 0x322030 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_3();                   // slot 3: d3dExtAntialiasControl 0x322010 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual unsigned int vfunc_4();           // slot 4: d3dExtAntialiasControl 0x322020 (pure3d/d3dExtFramebufferEffects.cpp)
    bgfxContext* m_context;
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

// Stands in for pure3d::d3dExtFramebufferEffects.
class bgfxExtFramebufferEffects : public bgfxExtension {
  public:
    enum { kClass = kClassExtFramebufferEffects };
    explicit bgfxExtFramebufferEffects(bgfxContext* context) : m_context(context) {}
    virtual void vfunc_1(unsigned char, int, int, unsigned char); // slot 1: d3dExtFramebufferEffects 0x3225c0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_2();                   // slot 2: d3dExtFramebufferEffects 0x3226b0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_3(unsigned char);      // slot 3: d3dExtFramebufferEffects 0x320530 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_4(int, int, int, int, int); // slot 4: d3dExtFramebufferEffects 0x3239e0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_5();                   // slot 5: d3dExtFramebufferEffects 0x3202a0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_6();                   // slot 6: d3dExtFramebufferEffects 0x324a00 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_7(unsigned char);      // slot 7: d3dExtFramebufferEffects 0x320290 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_8(int, int, int, int, int, int, int, int); // slot 8: d3dExtFramebufferEffects 0x322cd0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_9();                   // slot 9: d3dExtFramebufferEffects 0x325110 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_10(int);               // slot 10: d3dExtFramebufferEffects 0x3225e0 (pure3d/d3dExtFramebufferEffects.cpp)
    bgfxContext* m_context;
};

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
    virtual void vfunc_5(int, int);           // slot 5: d3dExtHardwareSkinning 0x322200 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_6(int, int);           // slot 6: d3dExtHardwareSkinning 0x3245d0 (pure3d/d3dExtFramebufferEffects.cpp)
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

// Stands in for pure3d::d3dExtVertexProgram.
class bgfxExtVertexProgram : public bgfxExtension {
  public:
    enum { kClass = kClassExtVertexProgram };
    explicit bgfxExtVertexProgram(bgfxContext* context) : m_context(context) {}
    virtual void vfunc_1();                   // slot 1: d3dExtVertexProgram 0x322420 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_2(int, int, int, int, int); // slot 2: d3dExtVertexProgram 0x322440 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_3();                   // slot 3: d3dExtVertexProgram 0x322430 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_4(void*, char);        // slot 4: d3dExtVertexProgram 0x322360 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_5(int, int);           // slot 5: d3dExtVertexProgram 0x322390 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_6(unsigned int);       // slot 6: d3dExtVertexProgram 0x3223a0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_7(int, int, int);      // slot 7: d3dExtVertexProgram 0x3223c0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_8(int, int);           // slot 8: d3dExtVertexProgram 0x322400 (pure3d/d3dExtFramebufferEffects.cpp)
    bgfxContext* m_context;
};

// Stands in for pure3d::d3dExtVisibilityTest.
class bgfxExtVisibilityTest : public bgfxExtension {
  public:
    enum { kClass = kClassExtVisibilityTest };
    explicit bgfxExtVisibilityTest(bgfxContext* context) : m_context(context) {}
    virtual unsigned int vfunc_1();           // slot 1: d3dExtVisibilityTest 0x3222c0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_2();                   // slot 2: d3dExtVisibilityTest 0x3222d0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_3();                   // slot 3: d3dExtVisibilityTest 0x3222e0 (pure3d/d3dExtFramebufferEffects.cpp)
    virtual void vfunc_4(int);                // slot 4: d3dExtVisibilityTest 0x3222f0 (pure3d/d3dExtFramebufferEffects.cpp)
    bgfxContext* m_context;
};

} // namespace pddi
} // namespace hulk

// The entry point the engine calls instead of d3dCreateDevice (0x31ba60): version (0x12, 0xb) -> the device.
extern "C" int hulk_pddi_create_device(int major, int minor, void** out);
