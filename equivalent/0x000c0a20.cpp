// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0a20 @ 0x000c0a20
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
class CFEManager { public: float FUN_dummy(); };

class Base_c0a20 {
public:
    virtual void v();
    char p[12];
    char a[8];
    char result;
    char z[3];
    Base_c0a20(const char*, int) throw();
    void FUN_001d04a0();
};
template <class T, class R>
class Method0 : public Base_c0a20 {
public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : Base_c0a20(name, 0) {
        fn = f;
        result = FUN_001d04d0(((char*)&DAT_0048e100));
    }
    virtual void v();
    Fn fn;
};
template <class T, class R>
class Closure0 : public Method0<T, R> {
public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    virtual void v();
    T* owner;
};
class Registry_c0a20 {
public:
    void FUN_001d26d0(const char* name, Base_c0a20* fn);
    void FUN_000c0a20(const char* name, CFEManager* owner, void (CFEManager::*fn)());
};
struct Frame_c0a20 {
    Closure0<CFEManager, void> closure;
    unsigned int cookie;
    Frame_c0a20(const char* n, CFEManager* o, void (CFEManager::*f)()) : closure(n, o, f) {
        cookie = DAT_004d9968;
    }
};
void Registry_c0a20::FUN_000c0a20(const char* name, CFEManager* owner, void (CFEManager::*fn)()) {
    Frame_c0a20 fr(name, owner, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
    __security_check_cookie(fr.cookie);
}
