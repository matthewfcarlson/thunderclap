// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ceec0 @ 0x001ceec0
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
extern char DAT_0048e100;
extern char DAT_0048e0e4;
extern char DAT_0048e0f0;
extern char DAT_0048e128;
extern char DAT_0048e134;
char FUN_001d04d0(const void *type) throw();

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return &DAT_0048e100; } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return &DAT_0048e0f0; } };
template <> struct TypeTag<float> { static const void *get() { return &DAT_0048e128; } };
template <> struct TypeTag<int> { static const void *get() { return &DAT_0048e134; } };

class CScenarioManager {
public:
    virtual void vfn0();
};

class MethodBase {
public:
    virtual void m0();
    char pad_04[0xc];
    char argType;
    char pad_11[7];
    char retType;
    char pad_19[3];
    MethodBase(const char *n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R, class A>
class Method1 : public MethodBase {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) throw() : MethodBase(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argType = FUN_001d04d0(TypeTag<A>::get());
    }
    virtual void m0();
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
public:
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) throw() : Method1<T, R, A>(name, f), owner(o) {}
    virtual void m0();
    T *owner;
};

typedef Closure1<CScenarioManager, void, const char *> Closure;

struct Frame {
    Closure closure;
    unsigned int cookie;
    Frame(const char *n, CScenarioManager *o, Closure::Fn f) throw() : closure(n, o, f) {
        cookie = DAT_004d9968;
    }
};

class Registry {
public:
    void FUN_001d26d0(const char *name, MethodBase *m);
    void FUN_001ceec0(const char *name, CScenarioManager *owner, Closure::Fn f);
};

void Registry::FUN_001ceec0(const char *name, CScenarioManager *owner, Closure::Fn f) {
    Frame fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
    __security_check_cookie(fr.cookie);
}
