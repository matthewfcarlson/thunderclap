// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00087b40 @ 0x00087b40
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "decls/data/game/global.h"
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }

class __declspec(novtable) MethodBase_87b40 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char*, int);
    MethodBase_87b40(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class A, class R>
class Function1 : public MethodBase_87b40 {
  public:
    typedef R (*Fn)(A);
    Function1(const char* name, Fn f) : MethodBase_87b40(name, 1) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0f0));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
    Fn fn;
};

struct Registry_87b40 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00087b40(const char* name, const char* (*fn)(const char*));
};

void Registry_87b40::FUN_00087b40(const char* name, const char* (*fn)(const char*)) {
    typedef Function1<const char*, const char*> Alloc_87b40;
    HULK_SIZE32(Alloc_87b40, 0x20);
    void* mem = FUN_0008d690((int)sizeof(Function1<const char*, const char*>));
    Function1<const char*, const char*>* c = 0;
    if (mem)
        c = new (mem) Function1<const char*, const char*>(name, fn);
    FUN_001d3b70(name, c);
}
