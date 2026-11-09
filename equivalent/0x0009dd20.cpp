// STATUS: equivalent (tools/equiv.py level 3: 252 inputs, branch coverage 126/126)
// FUN_0009dd20 @ 0x0009dd20
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
void* operator new(hulk_uintptr) throw();
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int);
char FUN_001d04d0(const void*) throw();
class CCameraManager;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
extern char DAT_0048e0e4, DAT_0048e0f0, DAT_0048e100, DAT_0048e10c, DAT_0048e128, DAT_0048e134, DAT_0049cad8;
#define tBool DAT_0048e0e4
#define tString DAT_0048e0f0
#define tVoid DAT_0048e100
#define tVector DAT_0048e10c
#define tFloat DAT_0048e128
#define tInt DAT_0048e134
#define tCharPtr DAT_0049cad8
// Function's fields (include/decls/data/script.h); Method<N> adds the member-function pointer (CCameraManager's,
// held as ScriptMemberFn), Closure<N> the object.
class Base : public ScriptFunctionFields { public: virtual void v(); Base(const char*, int) throw(); };
template<class C, class R> class Method0 : public Base { public: ScriptMemberFn f; Method0(const char* n, ScriptMemberFn x, const void* r) : Base(n, 0) { f = x; retType = FUN_001d04d0(r); } virtual void v(); };
template<class C, class R> class Closure0 : public Method0<C, R> { public: C* owner; Closure0(const char* n, C* o, ScriptMemberFn f, const void* r) : Method0<C, R>(n, f, r) { owner = o; } virtual void v(); };
template<class C, class R, class A1> class Method1 : public Base { public: ScriptMemberFn f; Method1(const char* n, ScriptMemberFn x, const void* r, const void* a1) : Base(n, 1) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); } virtual void v(); };
template<class C, class R, class A1> class Closure1 : public Method1<C, R, A1> { public: C* owner; Closure1(const char* n, C* o, ScriptMemberFn f, const void* r, const void* a1) : Method1<C, R, A1>(n, f, r, a1) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2> class Method2 : public Base { public: ScriptMemberFn f; Method2(const char* n, ScriptMemberFn x, const void* r, const void* a1, const void* a2) : Base(n, 2) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); } virtual void v(); };
template<class C, class R, class A1, class A2> class Closure2 : public Method2<C, R, A1, A2> { public: C* owner; Closure2(const char* n, C* o, ScriptMemberFn f, const void* r, const void* a1, const void* a2) : Method2<C, R, A1, A2>(n, f, r, a1, a2) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3> class Method3 : public Base { public: ScriptMemberFn f; Method3(const char* n, ScriptMemberFn x, const void* r, const void* a1, const void* a2, const void* a3) : Base(n, 3) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3> class Closure3 : public Method3<C, R, A1, A2, A3> { public: C* owner; Closure3(const char* n, C* o, ScriptMemberFn f, const void* r, const void* a1, const void* a2, const void* a3) : Method3<C, R, A1, A2, A3>(n, f, r, a1, a2, a3) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Method4 : public Base { public: ScriptMemberFn f; Method4(const char* n, ScriptMemberFn x, const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Base(n, 4) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4 : public Method4<C, R, A1, A2, A3, A4> { public: C* owner; Closure4(const char* n, C* o, ScriptMemberFn f, const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Method4<C, R, A1, A2, A3, A4>(n, f, r, a1, a2, a3, a4) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Method5 : public Base { public: ScriptMemberFn f; Method5(const char* n, ScriptMemberFn x, const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5) : Base(n, 5) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); argTypes[4] = FUN_001d04d0(a5); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5 : public Method5<C, R, A1, A2, A3, A4, A5> { public: C* owner; Closure5(const char* n, C* o, ScriptMemberFn f, const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5) : Method5<C, R, A1, A2, A3, A4, A5>(n, f, r, a1, a2, a3, a4, a5) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Method6 : public Base { public: ScriptMemberFn f; Method6(const char* n, ScriptMemberFn x, const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5, const void* a6) : Base(n, 6) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); argTypes[4] = FUN_001d04d0(a5); argTypes[5] = FUN_001d04d0(a6); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6 : public Method6<C, R, A1, A2, A3, A4, A5, A6> { public: C* owner; Closure6(const char* n, C* o, ScriptMemberFn f, const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5, const void* a6) : Method6<C, R, A1, A2, A3, A4, A5, A6>(n, f, r, a1, a2, a3, a4, a5, a6) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7> class Method7 : public Base { public: ScriptMemberFn f; Method7(const char* n, ScriptMemberFn x, const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5, const void* a6, const void* a7) : Base(n, 7) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); argTypes[4] = FUN_001d04d0(a5); argTypes[5] = FUN_001d04d0(a6); argTypes[6] = FUN_001d04d0(a7); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7> class Closure7 : public Method7<C, R, A1, A2, A3, A4, A5, A6, A7> { public: C* owner; Closure7(const char* n, C* o, ScriptMemberFn f, const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5, const void* a6, const void* a7) : Method7<C, R, A1, A2, A3, A4, A5, A6, A7>(n, f, r, a1, a2, a3, a4, a5, a6, a7) { owner = o; } virtual void v(); };
template<> class Closure6<CCameraManager, bool, float, float, float, float, float, float> { public: virtual void v(); ScriptFunctionFields fields; ScriptMemberFn fn; CCameraManager* owner; Closure6(CCameraManager* o) { owner = o; } };
template<> class Closure6<CCameraManager, void, float, float, float, float, float, float> { public: virtual void v(); ScriptFunctionFields fields; ScriptMemberFn fn; CCameraManager* owner; Closure6(CCameraManager* o) { owner = o; } };
template<> class Closure6<CCameraManager, void, int, int, float, int, int, float> { public: virtual void v(); ScriptFunctionFields fields; ScriptMemberFn fn; CCameraManager* owner; Closure6(CCameraManager* o) { owner = o; } };
template<> class Closure7<CCameraManager, void, bool, bool, bool, bool, bool, bool, float> { public: virtual void v(); ScriptFunctionFields fields; ScriptMemberFn fn; CCameraManager* owner; Closure7(CCameraManager* o) { owner = o; } };
class Registry { public:
    void FUN_001d3b70(const char*, void*);
};
class Entry { public:
};
class Raw_0009a6e0 { public: void FUN_0009a6e0(const char*, ScriptMemberFn); };
class Raw_0009ae50 { public: void FUN_0009ae50(const char*, ScriptMemberFn); };
class Raw_0009b080 { public: void FUN_0009b080(const char*, ScriptMemberFn); };
class Raw_0009b4a0 { public: void FUN_0009b4a0(const char*, ScriptMemberFn); };
Registry* FUN_001d4c90();
#define FN(b) void FUN_##b();
#define CB(b) reinterpret_cast<ScriptMemberFn>(&CCameraManager::FUN_##b)
#define G0(n, b, R) { typedef Closure0<CCameraManager, R> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R)); }
#define G1(n, b, R, A1) { typedef Closure1<CCameraManager, R, A1> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R, &t##A1)); }
#define G2(n, b, R, A1, A2) { typedef Closure2<CCameraManager, R, A1, A2> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R, &t##A1, &t##A2)); }
#define G3(n, b, R, A1, A2, A3) { typedef Closure3<CCameraManager, R, A1, A2, A3> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R, &t##A1, &t##A2, &t##A3)); }
#define G4(n, b, R, A1, A2, A3, A4) { typedef Closure4<CCameraManager, R, A1, A2, A3, A4> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R, &t##A1, &t##A2, &t##A3, &t##A4)); }
#define G5(n, b, R, A1, A2, A3, A4, A5) { typedef Closure5<CCameraManager, R, A1, A2, A3, A4, A5> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R, &t##A1, &t##A2, &t##A3, &t##A4, &t##A5)); }
#define M6(n, c, b, R, A1, A2, A3, A4, A5, A6) { typedef Closure6<CCameraManager, R, A1, A2, A3, A4, A5, A6> Built_t; HULK_SIZE32(Built_t, 0x24); void* m = FUN_0008d690((unsigned int)sizeof(Built_t)); void* x = 0; if (m) { ((Raw_##c*)m)->FUN_##c(n, CB(b)); x = new (m) Built_t(this); } r->FUN_001d3b70(n, x); }
#define M7(n, c, b, R, A1, A2, A3, A4, A5, A6, A7) { typedef Closure7<CCameraManager, R, A1, A2, A3, A4, A5, A6, A7> Built_t; HULK_SIZE32(Built_t, 0x24); void* m = FUN_0008d690((unsigned int)sizeof(Built_t)); void* x = 0; if (m) { ((Raw_##c*)m)->FUN_##c(n, CB(b)); x = new (m) Built_t(this); } r->FUN_001d3b70(n, x); }

class CCameraManager {
public:
    CCameraManager();
    virtual void v0();
    int i04;
    int i08;
    int i0c;
    int i10;
    int i14;
    char b18;
    char b19;
    char b1a;
    char pad1b;
    int i1c;
    int i20, i24, i28, i2c, i30, i34, i38, i3c;
    char pad40[0x60];
    int ia0, ia4, ia8, iac, ib0, ib4, ib8, ibc, ic0, ic4;
    void FUN_0009a220();
    // The member functions bound to Lua below.
    FN(00099570) FN(00099500) FN(000995c0) FN(00099600) FN(00099640) FN(00099680) FN(000996c0) FN(0009c170) FN(0009c1a0) FN(0009c1d0) FN(0009c200) FN(0009c230) FN(00099710) FN(00099760) FN(000997b0) FN(000997e0) FN(00099810) FN(000993f0) FN(00099860) FN(00099880) FN(000998a0) FN(00099840) FN(000998c0) FN(000998f0) FN(00099960) FN(00099980) FN(000999b0) FN(000999f0) FN(00099a10) FN(00099a20) FN(00099a30) FN(00098f40) FN(00099330) FN(00099bf0) FN(00099730) FN(00099740) FN(00099750) FN(00099790) FN(000997a0) FN(00099c60) FN(00099c80) FN(00099ca0) FN(00099cc0) FN(00099ce0) FN(0009a5d0) FN(00099a50) FN(00099a70) FN(00099ae0) FN(00099b00) FN(00099d60) FN(00099000) FN(00099030) FN(00099040) FN(0009d1b0) FN(00099b30) FN(00099b50) FN(0009a480) FN(0009a500) FN(00099b70) FN(00099b90) FN(00099bb0) FN(00099bd0)
};

CCameraManager::CCameraManager() {
    i04 = 1;
    i08 = 0;
    i1c = 0;
    i10 = 0;
    ib8 = 0;
    i14 = 0;
    ib0 = 0;
    ib4 = 0;
    ibc = 0;
    ic0 = 0;
    ic4 = 0;
    b19 = 1;
    b1a = 0;
    b18 = 0;
    i20 = 0; i24 = 0; i28 = 0; i2c = 0; i30 = 0; i34 = 0; i38 = 0; i3c = 0;
    ia0 = 0; ia4 = 0; ia8 = 0; iac = 0;
    FUN_0009a220();
    i0c = 0;
    Registry* r = FUN_001d4c90();
    if (r) {
M6("cm_SetScriptCamStatic", 0009a6e0, 00099570, Void, Float, Float, Float, Float, Float, Float)
G4("cm_SetScriptCamStaticV", 00099500, Void, Float, Float, Vector, Float)
G3("cm_SetScriptCamShot", 000995c0, Void, Float, Float, Bool)
G2("cm_SetScriptCamZoom", 00099600, Void, Float, Float)
G2("cm_SetScriptCamPan", 00099640, Void, Float, Float)
G2("cm_SetScriptCamPitch", 00099680, Void, Float, Float)
G4("cm_SetScriptCamShake", 000996c0, Void, Float, Float, Float, Float)
G3("cm_SwitchToScriptCamera", 0009c170, Void, Bool, Bool, Bool)
G4("cm_SwitchToScriptCameraTD", 0009c1a0, Void, Bool, Bool, Bool, Float)
G4("cm_SwitchToScriptCameraP", 0009c1d0, Void, Bool, Bool, Bool, Bool)
G5("cm_SwitchToScriptCameraTDP", 0009c200, Void, Bool, Bool, Bool, Bool, Float)
M7("cm_SwitchToScriptCameraAll", 0009ae50, 0009c230, Void, Bool, Bool, Bool, Bool, Bool, Bool, Float)
G0("cm_AbortScriptCamera", 00099710, Void)
G0("cm_IsScriptCameraPlaying", 00099760, Bool)
G2("cm_SetScriptCamPanTiming", 000997b0, Void, Float, Float)
G2("cm_SetScriptCamPitchTiming", 000997e0, Void, Float, Float)
G2("cm_SetScriptCamZoomTiming", 00099810, Void, Float, Float)
M6("cm_SetScriptCamBlending", 0009b080, 000993f0, Void, Int, Int, Float, Int, Int, Float)
G2("cm_SetScriptCamZoomEaseInOut", 00099860, Void, Float, Float)
G2("cm_SetScriptCamPitchEaseInOut", 00099880, Void, Float, Float)
G2("cm_SetScriptCamPanEaseInOut", 000998a0, Void, Float, Float)
G1("cm_SetScriptCamSkipTime", 00099840, Void, Float)
G2("cm_SetScriptCamTargetTiming", 000998c0, Void, Float, Float)
G2("cm_SetScriptCamTarget", 000998f0, Void, Vector, Vector)
G2("cm_SetScriptCamTargetEaseInOut", 00099960, Void, Float, Float)
G2("cm_SetScriptCamFovaTiming", 00099980, Void, Float, Float)
G2("cm_SetScriptCamFova", 000999b0, Void, Float, Float)
G2("cm_SetScriptCamFovaEaseInOut", 000999f0, Void, Float, Float)
G1("cm_SetScriptCamNearPlane", 00099a10, Void, Float)
G1("cm_SetScriptCamFarPlane", 00099a20, Void, Float)
G1("cm_SetScriptCamDontSwitch", 00099a30, Void, Bool)
G1("cm_EnableDramaticCamera", 00098f40, Void, Bool)
G4("cm_CameraShake", 00099330, Void, Int, Float, Float, Float)
G0("cm_GetCurrentCameraPosition", 00099bf0, Vector)
G0("cm_IsDramaticCameraActive", 00099730, Bool)
G0("cm_IsHypnoticCameraActive", 00099740, Bool)
G0("cm_IsScriptCameraActive", 00099750, Bool)
G0("cm_IsNISCameraActive", 00099790, Bool)
G0("cm_IsGameCameraActive", 000997a0, Bool)
G1("cm_SetScriptCamTargetBias", 00099c60, Void, Float)
G1("cm_SetScriptCamFovaBias", 00099c80, Void, Float)
G1("cm_SetScriptCamPitchBias", 00099ca0, Void, Float)
G1("cm_SetScriptCamPanBias", 00099cc0, Void, Float)
G1("cm_SetScriptCamZoomBias", 00099ce0, Void, Float)
M6("cm_CanScriptCamSeeTarget", 0009b4a0, 0009a5d0, Bool, Float, Float, Float, Float, Float, Float)
G1("cm_SetChaseCamTarget", 00099a50, Void, String)
G0("cm_GetChaseCamTarget", 00099a70, String)
G1("cm_ResetChaseCam", 00099ae0, Void, Bool)
G2("cm_ResetChaseCamFacing", 00099b00, Void, Vector, Bool)
G5("cm_IsPointInCameraView", 00099d60, Bool, Float, Float, Float, Float, Bool)
G2("cm_SetHypnoticCamTarget", 00099000, Void, Vector, Float)
G1("cm_SetHypnoticCamSoundTrigger", 00099030, Void, Float)
G1("cm_SetHypnoticCamMinHeight", 00099040, Void, Float)
G4("cm_StartHypnoticCam", 0009d1b0, Void, CharPtr, CharPtr, CharPtr, CharPtr)
G0("cm_GetChaseCamBaseDist", 00099b30, Float)
G0("cm_GetChaseCamFOV", 00099b50, Float)
G1("cm_SetChaseCamBaseDist", 0009a480, Void, Float)
G2("cm_SetChaseCamFOV", 0009a500, Void, Float, Float)
G0("cm_GetChaseCamMaxHeight", 00099b70, Float)
G1("cm_SetChaseCamMaxHeight", 00099b90, Void, Float)
G0("cm_GetChaseCamMinHeight", 00099bb0, Float)
G1("cm_SetChaseCamMinHeight", 00099bd0, Void, Float)
    }
}
