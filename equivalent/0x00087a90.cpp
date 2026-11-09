// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00087a90 @ 0x00087a90
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }

class __declspec(novtable) MethodBase_87a90 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char*, int);
    MethodBase_87a90(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class R>
class Function0_87a90 : public MethodBase_87a90 {
  public:
    typedef R (*Fn)();
    Function0_87a90(const char* name, Fn f) : MethodBase_87a90(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
    Fn fn;
};

struct Registry_87a90 {
    void FUN_00087a90(const char* name, float (*fn)());
};

void Registry_87a90::FUN_00087a90(const char* name, float (*fn)()) {
    HULK_SIZE32(Function0_87a90<float>, 0x20);
    void* mem = FUN_0008d690((int)sizeof(Function0_87a90<float>));
    Function0_87a90<float>* c = 0;
    if (mem)
        c = new (mem) Function0_87a90<float>(name, fn);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)name, (hulk_intptr)c);
}
