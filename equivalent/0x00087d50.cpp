// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00087d50 @ 0x00087d50
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "decls/data/game/unknown.h"
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }

class CTimeManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_87d50 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char*, int);
    MethodBase_87d50(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R>
class Method0 : public MethodBase_87d50 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_87d50(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_87d50 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00087d50(const char* name, CTimeManager* owner, float (CTimeManager::*fn)());
};

void Registry_87d50::FUN_00087d50(const char* name, CTimeManager* owner, float (CTimeManager::*fn)()) {
    typedef Closure0<CTimeManager, float> Alloc_87d50;
    HULK_SIZE32(Alloc_87d50, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CTimeManager, float>));
    Closure0<CTimeManager, float>* c = 0;
    if (mem)
        c = new (mem) Closure0<CTimeManager, float>(name, owner, fn);
    FUN_001d3b70(name, c);
}
