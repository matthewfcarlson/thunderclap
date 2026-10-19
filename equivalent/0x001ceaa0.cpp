// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_001ceaa0 @ 0x001ceaa0
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/unknown.h"

class CScenarioManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_1ceaa0 {
  public:
    virtual void m0();
    char pad_04[0x14];
    char retType;
    char pad_19[3];
    MethodBase_1ceaa0(const char* n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R>
class Method0 : public MethodBase_1ceaa0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) throw() : MethodBase_1ceaa0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((char*)&DAT_0048e128));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) throw() : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Frame_1ceaa0 {
    Closure0<CScenarioManager, float> closure;
    Frame_1ceaa0(const char* n, CScenarioManager* o, float (CScenarioManager::*f)()) throw() : closure(n, o, f) {
    }
};

struct Registry_1ceaa0 {
    void FUN_001d26d0(const char*, void*);
    void FUN_001ceaa0(const char* name, CScenarioManager* owner, float (CScenarioManager::*fn)());
};

void Registry_1ceaa0::FUN_001ceaa0(const char* name, CScenarioManager* owner, float (CScenarioManager::*fn)()) {
    Frame_1ceaa0 fr(name, owner, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
