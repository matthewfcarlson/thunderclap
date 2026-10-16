// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cee40 @ 0x001cee40
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

class CScenarioManager { public: void FUN_dummy(); };

class __declspec(novtable) MethodBase_1cee40 {
  public:
    virtual void m0();
    char pad_04[0x14];
    char retType;
    char pad_19[3];
    MethodBase_1cee40(const char* n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R>
class Method0 : public MethodBase_1cee40 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) throw() : MethodBase_1cee40(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) throw() : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Frame_1cee40 {
    Closure0<CScenarioManager, void> closure;
    unsigned int cookie;
    Frame_1cee40(const char* n, CScenarioManager* o, void (CScenarioManager::*f)()) throw() : closure(n, o, f) {
        cookie = DAT_004d9968;
    }
};

struct Registry_1cee40 {
    void FUN_001d26d0(const char*, void*);
    void FUN_001cee40(const char* name, CScenarioManager* owner, void (CScenarioManager::*fn)());
};

void Registry_1cee40::FUN_001cee40(const char* name, CScenarioManager* owner, void (CScenarioManager::*fn)()) {
    Frame_1cee40 fr(name, owner, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
    __security_check_cookie(fr.cookie);
}
