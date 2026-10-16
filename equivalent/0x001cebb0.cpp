// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cebb0 @ 0x001cebb0
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<float> { static const void *get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<int> { static const void *get() { return ((char*)&DAT_0048e134); } };

class CScenarioManager {
public:
    virtual void vfn0();
};

class MethodBase_1cebb0 {
public:
    virtual void m0();
    char pad_04[0xc];
    char argType;
    char pad_11[7];
    char retType;
    char pad_19[3];
    MethodBase_1cebb0(const char *n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R, class A>
class Method1 : public MethodBase_1cebb0 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) throw() : MethodBase_1cebb0(name, 1) {
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

typedef Closure1<CScenarioManager, void, bool> Closure_1cebb0;

struct Frame_1cebb0 {
    Closure_1cebb0 closure;
    unsigned int cookie;
    Frame_1cebb0(const char *n, CScenarioManager *o, Closure_1cebb0::Fn f) throw() : closure(n, o, f) {
        cookie = DAT_004d9968;
    }
};

class Registry_1cebb0 {
public:
    void FUN_001d26d0(const char *name, MethodBase_1cebb0 *m);
    void FUN_001cebb0(const char *name, CScenarioManager *owner, Closure_1cebb0::Fn f);
};

void Registry_1cebb0::FUN_001cebb0(const char *name, CScenarioManager *owner, Closure_1cebb0::Fn f) {
    Frame_1cebb0 fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
    __security_check_cookie(fr.cookie);
}
