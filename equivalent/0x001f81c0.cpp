// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_001f81c0 @ 0x001f81c0
inline void *operator new(unsigned int, void *p) throw() { return p; }

void *FUN_0008d690(unsigned int size);
extern "C" char __cdecl FUN_001d04d0(const char *);
extern "C" const char DAT_0048e100[];
extern "C" const char DAT_0048e128[];
extern "C" const char DAT_0048e0e4[];
extern "C" const char DAT_0049b95c[];
extern "C" const char DAT_0049cad8[];

namespace math {
class Vector {
public:
    float x, y, z;
};
}

template <class T> struct TypeName;
template <> struct TypeName<void> { static const char *get() { return DAT_0048e100; } };
template <> struct TypeName<float> { static const char *get() { return DAT_0048e128; } };
template <> struct TypeName<bool> { static const char *get() { return DAT_0048e0e4; } };
template <> struct TypeName<unsigned int> { static const char *get() { return DAT_0049b95c; } };
template <> struct TypeName<char *> { static const char *get() { return DAT_0049cad8; } };

class __declspec(novtable) Function {
public:
    virtual void f0();
    virtual void f1();
    char pad04[0x0c];
    char args[4];
    char pad14[4];
    char ret;
    char pad19[3];
    void FUN_001d0480(const char *name, int arity);
    Function() {}
    __forceinline Function(const char *name, int arity) { FUN_001d0480(name, arity); }
};

class CEffectManager {
public:
    int FUN_001f7200(const char *name, math::Vector pos);
    int FUN_001f7280(int id, math::Vector pos);
    int FUN_001f7150(const char *name, math::Vector pos, math::Vector dir);
    unsigned int FUN_001f6f30(char *name, float a, float b);
    unsigned int FUN_001f6fc0(const char *name);
    unsigned int FUN_001f6e60(char *name);
    bool FUN_001f6ff0(bool on);
    bool FUN_001f7080(bool on);
    bool FUN_001f7110(bool on);
    void FUN_001f81c0();
};


template <class R, class A, class B>
class Function2 : public Function {
public:
    typedef R (*Fn)(A, B);
    __forceinline Function2(const char *name, Fn f) : Function(name, 2) {
        fn = f;
        ret = FUN_001d04d0(TypeName<R>::get());
        args[0] = FUN_001d04d0(TypeName<A>::get());
        args[1] = FUN_001d04d0(TypeName<B>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Method1 : public Function {
public:
    typedef R (T::*Fn)(A);
    __forceinline Method1(const char *name, Fn f) : Function(name, 1) {
        fn = f;
        ret = FUN_001d04d0(TypeName<R>::get());
        args[0] = FUN_001d04d0(TypeName<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
public:
    __forceinline Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T *owner;
};

// Method3 instances whose constructors were not inlined
class __declspec(novtable) Method3Oriented : public Function {
public:
    typedef int (CEffectManager::*Fn)(const char *, math::Vector, math::Vector);
    __forceinline Method3Oriented(const char *name, Fn f) : Function() { FUN_001f7720(name, f); }
    void FUN_001f7720(const char *name, Fn f);
    Fn fn;
};

class __declspec(novtable) Method3Decal : public Function {
public:
    typedef unsigned int (CEffectManager::*Fn)(char *, float, float);
    __forceinline Method3Decal(const char *name, Fn f) : Function() { FUN_001f78c0(name, f); }
    void FUN_001f78c0(const char *name, Fn f);
    Fn fn;
};

template <class T, class R, class A, class B, class C>
class Closure3;

template <>
class Closure3<CEffectManager, int, const char *, math::Vector, math::Vector> : public Method3Oriented {
public:
    __forceinline Closure3(const char *name, CEffectManager *o, Fn f) : Method3Oriented(name, f), owner(o) {}
    CEffectManager *owner;
};

template <>
class Closure3<CEffectManager, unsigned int, char *, float, float> : public Method3Decal {
public:
    __forceinline Closure3(const char *name, CEffectManager *o, Fn f) : Method3Decal(name, f), owner(o) {}
    CEffectManager *owner;
};

// closures whose constructors were out of line too
struct ClosureWorld {
    ClosureWorld *FUN_001f7b20(const char *name, CEffectManager *owner,
                               int (CEffectManager::*fn)(const char *, math::Vector));
};

struct ClosureSetPos {
    ClosureSetPos *FUN_001f7c40(const char *name, CEffectManager *owner,
                                int (CEffectManager::*fn)(int, math::Vector));
};

extern "C" void thunk_FUN_001b8750();
void FUN_001f7120(float, float);

struct Registry {
    void FUN_001d3b70(const char *name, void *closure);
    void FUN_001e12b0(const char *name, void (*fn)());
    void FUN_001f80b0(const char *name, CEffectManager *owner,
                      unsigned int (CEffectManager::*fn)(const char *));
};
Registry *FUN_001d4c90();

void CEffectManager::FUN_001f81c0()
{
    Registry *reg = FUN_001d4c90();
    reg->FUN_001e12b0("SetXBoxGamma", thunk_FUN_001b8750);

    void *mem = FUN_0008d690(0x20);
    Function2<void, float, float> *blur = 0;
    if (mem)
        blur = new (mem) Function2<void, float, float>("em_SetMotionBlur", FUN_001f7120);
    reg->FUN_001d3b70("em_SetMotionBlur", blur);

    mem = FUN_0008d690(0x24);
    ClosureWorld *world = 0;
    if (mem)
        world = ((ClosureWorld *)mem)->FUN_001f7b20("em_AddWorldEffect", this, &CEffectManager::FUN_001f7200);
    reg->FUN_001d3b70("em_AddWorldEffect", world);

    mem = FUN_0008d690(0x24);
    Closure3<CEffectManager, int, const char *, math::Vector, math::Vector> *oriented = 0;
    if (mem)
        oriented = new (mem) Closure3<CEffectManager, int, const char *, math::Vector, math::Vector>(
            "em_AddWorldEffectOriented", this, &CEffectManager::FUN_001f7150);
    reg->FUN_001d3b70("em_AddWorldEffectOriented", oriented);

    mem = FUN_0008d690(0x24);
    ClosureSetPos *setpos = 0;
    if (mem)
        setpos = ((ClosureSetPos *)mem)->FUN_001f7c40("em_SetPositionWorldEffect", this, &CEffectManager::FUN_001f7280);
    reg->FUN_001d3b70("em_SetPositionWorldEffect", setpos);

    mem = FUN_0008d690(0x24);
    Closure3<CEffectManager, unsigned int, char *, float, float> *decal = 0;
    if (mem)
        decal = new (mem) Closure3<CEffectManager, unsigned int, char *, float, float>(
            "CDQ_AddDecal", this, &CEffectManager::FUN_001f6f30);
    reg->FUN_001d3b70("CDQ_AddDecal", decal);

    reg->FUN_001f80b0("CDQ_Nearest", this, &CEffectManager::FUN_001f6fc0);

    mem = FUN_0008d690(0x24);
    Closure1<CEffectManager, unsigned int, char *> *addps = 0;
    if (mem)
        addps = new (mem) Closure1<CEffectManager, unsigned int, char *>("CPS_AddPS", this, &CEffectManager::FUN_001f6e60);
    reg->FUN_001d3b70("CPS_AddPS", addps);

    mem = FUN_0008d690(0x24);
    Closure1<CEffectManager, bool, bool> *rain = 0;
    if (mem)
        rain = new (mem) Closure1<CEffectManager, bool, bool>("em_EnableRain", this, &CEffectManager::FUN_001f6ff0);
    reg->FUN_001d3b70("em_EnableRain", rain);

    mem = FUN_0008d690(0x24);
    Closure1<CEffectManager, bool, bool> *dust = 0;
    if (mem)
        dust = new (mem) Closure1<CEffectManager, bool, bool>("em_EnableDust", this, &CEffectManager::FUN_001f7080);
    reg->FUN_001d3b70("em_EnableDust", dust);

    mem = FUN_0008d690(0x24);
    Closure1<CEffectManager, bool, bool> *debris = 0;
    if (mem)
        debris = new (mem) Closure1<CEffectManager, bool, bool>("em_EnableDebris", this, &CEffectManager::FUN_001f7110);
    reg->FUN_001d3b70("em_EnableDebris", debris);
}
