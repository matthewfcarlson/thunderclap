// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 36/36)
// FUN_001bb990 @ 0x001bb990
namespace math {
class Vector {
  public:
    float x, y, z;
};
}

class CRenderManager;
class ControlObj {
  public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6(int tag, int flag);
};
class OverlayObj {
  public:
    OverlayObj* FUN_0028edb0();
    virtual void vfn0();
    char pad[0x10 - 4];
    ControlObj* control;
    char pad2[0x20 - 0x14];
};

extern char DAT_0048e100;
extern char DAT_0048e0e4;
extern char DAT_0048e128;
extern char DAT_0049b95c;
char FUN_001d04d0(const void* type);
void* FUN_0008d690(unsigned size);
void* FUN_00263ea0(unsigned size);
inline void* operator new(unsigned int, void* p) throw() { return p; }

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void* get() { return &DAT_0048e100; } };
template <> struct TypeTag<bool> { static const void* get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<float> { static const void* get() { return &DAT_0048e128; } };
template <> struct TypeTag<unsigned int> { static const void* get() { return &DAT_0049b95c; } };

class __declspec(novtable) MethodBase {
  public:
    virtual void m0();
    char pad_04[0xc];
    char argType;
    char pad_11[7];
    char retType;
    char pad_19[3];
    void FUN_001d0480(const char*, int);
    MethodBase() {}
    MethodBase(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char* name, Fn f) : MethodBase(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argType = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char* name, T* o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T* owner;
};

// Methods whose base constructors are out of line.
template <class T, class R, class A, class B, class C>
class __declspec(novtable) Method3 : public MethodBase {
  public:
    typedef R (T::*Fn)(A, B, C);
    Method3(const char* name, Fn f) : MethodBase() { FUN_001b9c50(name, f); }
    void FUN_001b9c50(const char* name, Fn f);
    Fn fn;
};

template <class T, class R, class A, class B, class C>
class Closure3 : public Method3<T, R, A, B, C> {
  public:
    Closure3(const char* name, T* o, typename Method3<T, R, A, B, C>::Fn f) : Method3<T, R, A, B, C>(name, f), owner(o) {}
    T* owner;
};

template <class T, class R, class A, class B, class C, class D, class E, class F>
class __declspec(novtable) Method6 : public MethodBase {
  public:
    typedef R (T::*Fn)(A, B, C, D, E, F);
    Method6(const char* name, Fn f) : MethodBase() { FUN_001b9d80(name, f); }
    void FUN_001b9d80(const char* name, Fn f);
    Fn fn;
};

template <class T, class R, class A, class B, class C, class D, class E, class F>
class Closure6 : public Method6<T, R, A, B, C, D, E, F> {
  public:
    Closure6(const char* name, T* o, typename Method6<T, R, A, B, C, D, E, F>::Fn f)
        : Method6<T, R, A, B, C, D, E, F>(name, f), owner(o) {}
    T* owner;
};

template <class T, class R, class A, class B, class C, class D>
class Method4;

class CRenderManager {
  public:
    CRenderManager();
    virtual void vfn0();

    void FUN_001b8770(bool);
    void FUN_001b8780(bool);
    void FUN_001b8900(bool);
    void FUN_001b9ab0(int, int, int);
    void FUN_001b9b40(int, int, int);
    void FUN_001b87d0(int, int, int);
    void FUN_001b87f0(int, int, int);
    void FUN_001b88c0(float, float);
    void FUN_001b98e0(float, float, float, float, float, float);
    void FUN_001b8ab0();
    bool FUN_001b8b30();
    unsigned int FUN_001b8e40(const char*, float, float, float);
    unsigned int FUN_001b8dc0(const char*, math::Vector, math::Vector, float);
    void FUN_001b8ec0(unsigned int);
    void FUN_001b9020();
    void FUN_001b90b0();
    bool FUN_001b9120();
    bool FUN_001b88f0();
    void FUN_001b9130(float);
    void FUN_001b9160(float);
    void FUN_001b9180(float);
    void FUN_001b91b0(float);
    void FUN_001b91d0(math::Vector*);
    void FUN_001b9200(math::Vector*);
    void FUN_001b9230(math::Vector*);
    void FUN_001b9260(math::Vector*);
    void FUN_001b9290(int);

    int f4, f8, fc;
    float f10, f14;
    char f18;
    char pad19[3];
    int f1c, f20, f24, f28;
    OverlayObj* overlay;     // 0x2c
    char flags30[4];
    int f34, f38, f3c;
    int f40, f44, f48, f4c;
    float f50;
    int f54, f58, f5c, f60;
};

template <>
class __declspec(novtable) Method4<CRenderManager, unsigned int, const char*, float, float, float> : public MethodBase {
  public:
    typedef unsigned int (CRenderManager::*Fn)(const char*, float, float, float);
    Method4(const char* name, Fn f) : MethodBase() { FUN_001b9f90(name, f); }
    void FUN_001b9f90(const char* name, Fn f);
    Fn fn;
};

template <>
class __declspec(novtable) Method4<CRenderManager, unsigned int, const char*, math::Vector, math::Vector, float> : public MethodBase {
  public:
    typedef unsigned int (CRenderManager::*Fn)(const char*, math::Vector, math::Vector, float);
    Method4(const char* name, Fn f) : MethodBase() { FUN_001ba090(name, f); }
    void FUN_001ba090(const char* name, Fn f);
    Fn fn;
};

template <class T, class R, class A, class B, class C, class D>
class Closure4 : public Method4<T, R, A, B, C, D> {
  public:
    Closure4(const char* name, T* o, typename Method4<T, R, A, B, C, D>::Fn f) : Method4<T, R, A, B, C, D>(name, f), owner(o) {}
    T* owner;
};

struct ClosureFogPlanes {
    ClosureFogPlanes* FUN_001ba510(const char* name, CRenderManager* owner, void (CRenderManager::*fn)(float, float));
};
struct ClosureShaderLight {
    ClosureShaderLight* FUN_001ba980(const char* name, CRenderManager* owner, void (CRenderManager::*fn)(int));
};

struct Registry {
    void FUN_001d3b70(const char* name, void* closure);
    void FUN_001bb690(const char* name, CRenderManager* owner, void (CRenderManager::*fn)());
    void FUN_001bb700(const char* name, CRenderManager* owner, bool (CRenderManager::*fn)());
    void FUN_001bb880(const char* name, CRenderManager* owner, void (CRenderManager::*fn)(math::Vector*));
};
Registry* FUN_001d4c90();
void FUN_001c3d90();

CRenderManager::CRenderManager()
{
    f34 = 0xff;
    f38 = 0xff;
    f3c = 0xff;
    f4 = 0;
    f8 = 0;
    fc = 0;
    f10 = 1.0f;
    f14 = 1.0f;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f28 = 0;
    overlay = 0;
    flags30[0] = 0;
    flags30[1] = 0;
    flags30[2] = 0;
    flags30[3] = 0;
    f40 = 0x80;
    f44 = 0x80;
    f48 = 0x80;
    f4c = 0;
    f50 = 1.0f;
    f54 = 0;
    f58 = 0;
    f5c = 0;
    f60 = 0;

    Registry* reg = FUN_001d4c90();
    void* mem;

    mem = FUN_0008d690(0x24);
    Closure1<CRenderManager, void, bool>* enableFog = 0;
    if (mem)
        enableFog = new (mem) Closure1<CRenderManager, void, bool>("rm_EnableFog", this, &CRenderManager::FUN_001b8770);
    reg->FUN_001d3b70("rm_EnableFog", enableFog);

    mem = FUN_0008d690(0x24);
    Closure3<CRenderManager, void, int, int, int>* fogColour = 0;
    if (mem)
        fogColour = new (mem) Closure3<CRenderManager, void, int, int, int>("rm_SetFogColour", this, &CRenderManager::FUN_001b9ab0);
    reg->FUN_001d3b70("rm_SetFogColour", fogColour);

    mem = FUN_0008d690(0x24);
    ClosureFogPlanes* fogPlanes = 0;
    if (mem)
        fogPlanes = ((ClosureFogPlanes*)mem)->FUN_001ba510("rm_SetFogPlanes", this, &CRenderManager::FUN_001b88c0);
    reg->FUN_001d3b70("rm_SetFogPlanes", fogPlanes);

    mem = FUN_0008d690(0x24);
    Closure3<CRenderManager, void, int, int, int>* shadowColour = 0;
    if (mem)
        shadowColour = new (mem) Closure3<CRenderManager, void, int, int, int>("rm_SetShadowColour", this, &CRenderManager::FUN_001b9b40);
    reg->FUN_001d3b70("rm_SetShadowColour", shadowColour);

    mem = FUN_0008d690(0x24);
    Closure1<CRenderManager, void, bool>* enableBloom = 0;
    if (mem)
        enableBloom = new (mem) Closure1<CRenderManager, void, bool>("rm_EnableBloom", this, &CRenderManager::FUN_001b8780);
    reg->FUN_001d3b70("rm_EnableBloom", enableBloom);

    mem = FUN_0008d690(0x24);
    Closure3<CRenderManager, void, int, int, int>* bloomColour = 0;
    if (mem)
        bloomColour = new (mem) Closure3<CRenderManager, void, int, int, int>("rm_SetBloomColour", this, &CRenderManager::FUN_001b87d0);
    reg->FUN_001d3b70("rm_SetBloomColour", bloomColour);

    mem = FUN_0008d690(0x24);
    Closure3<CRenderManager, void, int, int, int>* bloomWeights = 0;
    if (mem)
        bloomWeights = new (mem) Closure3<CRenderManager, void, int, int, int>("rm_SetBloomWeights", this, &CRenderManager::FUN_001b87f0);
    reg->FUN_001d3b70("rm_SetBloomWeights", bloomWeights);

    mem = FUN_0008d690(0x24);
    Closure6<CRenderManager, void, float, float, float, float, float, float>* bloomParams = 0;
    if (mem)
        bloomParams = new (mem) Closure6<CRenderManager, void, float, float, float, float, float, float>("rm_SetBloomParameters", this, &CRenderManager::FUN_001b98e0);
    reg->FUN_001d3b70("rm_SetBloomParameters", bloomParams);

    reg->FUN_001bb690("rm_DoCredits", this, &CRenderManager::FUN_001b8ab0);
    reg->FUN_001bb700("rm_IsCredits", this, &CRenderManager::FUN_001b8b30);

    mem = FUN_0008d690(0x24);
    Closure4<CRenderManager, unsigned int, const char*, float, float, float>* addEffect = 0;
    if (mem)
        addEffect = new (mem) Closure4<CRenderManager, unsigned int, const char*, float, float, float>("rm_AddAnEffect", this, &CRenderManager::FUN_001b8e40);
    reg->FUN_001d3b70("rm_AddAnEffect", addEffect);

    mem = FUN_0008d690(0x24);
    Closure4<CRenderManager, unsigned int, const char*, math::Vector, math::Vector, float>* addEffectEx = 0;
    if (mem)
        addEffectEx = new (mem) Closure4<CRenderManager, unsigned int, const char*, math::Vector, math::Vector, float>("rm_AddAnEffectEx", this, &CRenderManager::FUN_001b8dc0);
    reg->FUN_001d3b70("rm_AddAnEffectEx", addEffectEx);

    mem = FUN_0008d690(0x24);
    Closure1<CRenderManager, void, unsigned int>* removeEffect = 0;
    if (mem)
        removeEffect = new (mem) Closure1<CRenderManager, void, unsigned int>("rm_RemoveAnEffect", this, &CRenderManager::FUN_001b8ec0);
    reg->FUN_001d3b70("rm_RemoveAnEffect", removeEffect);

    reg->FUN_001bb880("rm_GetCameraRight", this, &CRenderManager::FUN_001b91d0);
    reg->FUN_001bb880("rm_GetCameraUp", this, &CRenderManager::FUN_001b9200);
    reg->FUN_001bb880("rm_GetCameraHeading", this, &CRenderManager::FUN_001b9230);
    reg->FUN_001bb880("rm_GetCameraPosition", this, &CRenderManager::FUN_001b9260);

    mem = FUN_0008d690(0x24);
    ClosureShaderLight* shaderLight = 0;
    if (mem)
        shaderLight = ((ClosureShaderLight*)mem)->FUN_001ba980("rm_SetBuildingShaderLight", this, &CRenderManager::FUN_001b9290);
    reg->FUN_001d3b70("rm_SetBuildingShaderLight", shaderLight);

    reg->FUN_001bb700("rm_GetDrawEffectsWithWorld", this, &CRenderManager::FUN_001b88f0);

    mem = FUN_0008d690(0x24);
    Closure1<CRenderManager, void, bool>* drawEffects = 0;
    if (mem)
        drawEffects = new (mem) Closure1<CRenderManager, void, bool>("rm_SetDrawEffectsWithWorld", this, &CRenderManager::FUN_001b8900);
    reg->FUN_001d3b70("rm_SetDrawEffectsWithWorld", drawEffects);

    reg->FUN_001bb690("nism_LetterBoxOn", this, &CRenderManager::FUN_001b9020);
    reg->FUN_001bb690("nism_LetterBoxOff", this, &CRenderManager::FUN_001b90b0);

    mem = FUN_0008d690(0x24);
    Closure1<CRenderManager, void, float>* fadeToBlack = 0;
    if (mem)
        fadeToBlack = new (mem) Closure1<CRenderManager, void, float>("nism_FadeToBlack", this, &CRenderManager::FUN_001b9130);
    reg->FUN_001d3b70("nism_FadeToBlack", fadeToBlack);

    mem = FUN_0008d690(0x24);
    Closure1<CRenderManager, void, float>* fadeFromBlack = 0;
    if (mem)
        fadeFromBlack = new (mem) Closure1<CRenderManager, void, float>("nism_FadeFromBlack", this, &CRenderManager::FUN_001b9160);
    reg->FUN_001d3b70("nism_FadeFromBlack", fadeFromBlack);

    mem = FUN_0008d690(0x24);
    Closure1<CRenderManager, void, float>* fadeToWhite = 0;
    if (mem)
        fadeToWhite = new (mem) Closure1<CRenderManager, void, float>("nism_FadeToWhite", this, &CRenderManager::FUN_001b9180);
    reg->FUN_001d3b70("nism_FadeToWhite", fadeToWhite);

    mem = FUN_0008d690(0x24);
    Closure1<CRenderManager, void, float>* fadeFromWhite = 0;
    if (mem)
        fadeFromWhite = new (mem) Closure1<CRenderManager, void, float>("nism_FadeFromWhite", this, &CRenderManager::FUN_001b91b0);
    reg->FUN_001d3b70("nism_FadeFromWhite", fadeFromWhite);

    reg->FUN_001bb700("nism_IsLetterBoxOn", this, &CRenderManager::FUN_001b9120);

    FUN_001c3d90();

    OverlayObj* ov = (OverlayObj*)FUN_00263ea0(0x20);
    if (ov)
        ov = ov->FUN_0028edb0();
    overlay = ov;
    ov->vfn0();
    overlay->control->vfn6(0x444d4c42, 1);
}
