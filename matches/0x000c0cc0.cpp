// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0cc0 @ 0x000c0cc0
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<float> { static const void *get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<int> { static const void *get() { return ((char*)&DAT_0048e134); } };

class CFEManager {
public:
    virtual void vfn0();
};

class MethodBase_c0cc0 {
public:
    virtual void m0();
    char pad_04[0xc];
    char argType;
    char pad_11[7];
    char retType;
    char pad_19[3];
    MethodBase_c0cc0(const char *n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R, class A>
class Method1 : public MethodBase_c0cc0 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) throw() : MethodBase_c0cc0(name, 1) {
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

typedef Closure1<CFEManager, void, int> Closure_c0cc0;

struct Frame_c0cc0 {
    Closure_c0cc0 closure;
    Frame_c0cc0(const char *n, CFEManager *o, Closure_c0cc0::Fn f) throw() : closure(n, o, f) {
    }
};

class Registry_c0cc0 {
public:
    void FUN_001d26d0(const char *name, MethodBase_c0cc0 *m);
    void FUN_000c0cc0(const char *name, CFEManager *owner, Closure_c0cc0::Fn f);
};

void Registry_c0cc0::FUN_000c0cc0(const char *name, CFEManager *owner, Closure_c0cc0::Fn f) {
    Frame_c0cc0 fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
