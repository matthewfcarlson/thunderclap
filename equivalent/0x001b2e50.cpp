// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_001b2e50 @ 0x001b2e50
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
extern "C" char __cdecl FUN_001d04d0(const char*);
extern "C" void* __cdecl FUN_001d4c90();
extern "C" const char DAT_0048e100[];
extern "C" const char DAT_0048e0f0[];
extern "C" const char DAT_0048e128[];
extern "C" void __cdecl FUN_001afa70(float, float);
extern "C" void __cdecl FUN_001afa90(float, float);
extern "C" void __cdecl FUN_001afab0(float, float);
extern "C" void __cdecl FUN_001afad0(const char*, float);
inline void* operator new(unsigned int, void* p) throw() { return p; }

template <class T> struct TypeName;
template <> struct TypeName<void> { static const char* get() { return DAT_0048e100; } };
template <> struct TypeName<float> { static const char* get() { return DAT_0048e128; } };
template <> struct TypeName<const char*> { static const char* get() { return DAT_0048e0f0; } };

class __declspec(novtable) Function {
  public:
    virtual void f0();
    virtual void f1();
    char pad_04[0x0c];
    char argA;
    char argB;
    char pad_12[6];
    char ret;
    char pad_19[3];
    void FUN_001d0480(const char*, int);
    Function(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class R, class A, class B>
class Function2 : public Function {
  public:
    typedef R (__cdecl *Fn)(A, B);
    Function2(const char* name, Fn f) : Function(name, 2) {
        fn = f;
        ret = FUN_001d04d0(TypeName<R>::get());
        argA = FUN_001d04d0(TypeName<A>::get());
        argB = FUN_001d04d0(TypeName<B>::get());
    }
    Fn fn;
};

struct Registry { void FUN_001d3b70(const char*, void*); };

class __declspec(novtable) CollisionSolverAgentBase {
  public:
    virtual void f0();
    void FUN_002f8800();
    CollisionSolverAgentBase() { FUN_002f8800(); }
};

class AICollisionSolverAgent : public CollisionSolverAgentBase {
  public:
    AICollisionSolverAgent();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual bool vfunc_10(void*, void*);
    virtual void f11();
};

AICollisionSolverAgent::AICollisionSolverAgent() {
    Registry* reg = (Registry*)FUN_001d4c90();
    if (reg) {
        void* mem = FUN_0008d690(0x20);
        Function2<void, float, float>* a = 0;
        if (mem) a = new (mem) Function2<void, float, float>("phy_SetCharVsSmallPropDamage", FUN_001afa70);
        reg->FUN_001d3b70("phy_SetCharVsSmallPropDamage", a);
        mem = FUN_0008d690(0x20);
        Function2<void, float, float>* b = 0;
        if (mem) b = new (mem) Function2<void, float, float>("phy_SetCharVsLargePropDamage", FUN_001afa90);
        reg->FUN_001d3b70("phy_SetCharVsLargePropDamage", b);
        mem = FUN_0008d690(0x20);
        Function2<void, float, float>* c = 0;
        if (mem) c = new (mem) Function2<void, float, float>("phy_SetCharVsHeavyPropDamage", FUN_001afab0);
        reg->FUN_001d3b70("phy_SetCharVsHeavyPropDamage", c);
        mem = FUN_0008d690(0x20);
        Function2<void, const char*, float>* d = 0;
        if (mem) d = new (mem) Function2<void, const char*, float>("phy_SetElectrifiedDamage", FUN_001afad0);
        reg->FUN_001d3b70("phy_SetElectrifiedDamage", d);
    }
}
