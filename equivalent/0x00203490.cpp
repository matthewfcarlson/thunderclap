// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_00203490 @ 0x00203490
namespace math { class Vector; }

extern char DAT_0048e100;
extern char DAT_0048e0f0;
extern char DAT_0048e10c;
extern char DAT_0048e128;
char FUN_001d04d0(const void* type);
void* FUN_0008d690(unsigned size);
inline void* operator new(unsigned int, void* p) throw() { return p; }

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void* get() { return &DAT_0048e100; } };
template <> struct TypeTag<float> { static const void* get() { return &DAT_0048e128; } };
template <> struct TypeTag<const char*> { static const void* get() { return &DAT_0048e0f0; } };
template <> struct TypeTag<math::Vector> { static const void* get() { return &DAT_0048e10c; } };

class __declspec(novtable) MethodBase_203490 {
  public:
    virtual void m0();
    char pad_04[0xc];
    char argType;
    char pad_11[7];
    char retType;
    char pad_19[3];
    void FUN_001d0480(const char*, int);
    MethodBase_203490(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase_203490 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char* name, Fn f) : MethodBase_203490(name, 1) {
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

class CWorldCollisionManager;

struct Registry_203490 {
    void FUN_001d3b70(const char* name, void* closure);
    void FUN_002033d0(const char* name, CWorldCollisionManager* owner, float (CWorldCollisionManager::*fn)());
};
Registry_203490* FUN_001d4c90();

class CWorldCollisionManager {
  public:
    math::Vector FUN_00202500(math::Vector);
    float FUN_00034e60();
    void FUN_00201bc0(float);
    void FUN_00201bd0(const char*);
    void FUN_00201be0(const char*);
    void FUN_00203490();
};

void CWorldCollisionManager::FUN_00203490()
{
    Registry_203490* reg = FUN_001d4c90();
    if (reg) {
        void* mem;

        mem = FUN_0008d690(0x24);
        Closure1<CWorldCollisionManager, math::Vector, math::Vector>* c1 = 0;
        if (mem)
            c1 = new (mem) Closure1<CWorldCollisionManager, math::Vector, math::Vector>("wcm_IntersectGround", this, &CWorldCollisionManager::FUN_00202500);
        reg->FUN_001d3b70("wcm_IntersectGround", c1);

        mem = FUN_0008d690(0x24);
        Closure1<CWorldCollisionManager, void, float>* c2 = 0;
        if (mem)
            c2 = new (mem) Closure1<CWorldCollisionManager, void, float>("wcm_SetWaterHeight", this, &CWorldCollisionManager::FUN_00201bc0);
        reg->FUN_001d3b70("wcm_SetWaterHeight", c2);

        reg->FUN_002033d0("wcm_GetWaterHeight", this, &CWorldCollisionManager::FUN_00034e60);

        mem = FUN_0008d690(0x24);
        Closure1<CWorldCollisionManager, void, const char*>* c3 = 0;
        if (mem)
            c3 = new (mem) Closure1<CWorldCollisionManager, void, const char*>("wcm_SetWaterEffectName", this, &CWorldCollisionManager::FUN_00201bd0);
        reg->FUN_001d3b70("wcm_SetWaterEffectName", c3);

        mem = FUN_0008d690(0x24);
        Closure1<CWorldCollisionManager, void, const char*>* c4 = 0;
        if (mem)
            c4 = new (mem) Closure1<CWorldCollisionManager, void, const char*>("wcm_SetWaterSound", this, &CWorldCollisionManager::FUN_00201be0);
        reg->FUN_001d3b70("wcm_SetWaterSound", c4);
    }
}
