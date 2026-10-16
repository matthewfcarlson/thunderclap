// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00087a90 @ 0x00087a90
#include "decls/address.h"
#include "decls/data/game/unknown.h"
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
inline void* operator new(unsigned int, void* p) throw() { return p; }

class __declspec(novtable) MethodBase_87a90 {
  public:
    virtual void m0();
    char pad_04[0x14];
    char enabled;
    char pad_19[3];
    void FUN_001d0480(const char*, int);
    MethodBase_87a90(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class R>
class Function0 : public MethodBase_87a90 {
  public:
    typedef R (*Fn)();
    Function0(const char* name, Fn f) : MethodBase_87a90(name, 0) {
        fn = f;
        enabled = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
    Fn fn;
};

struct Registry_87a90 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00087a90(const char* name, float (*fn)());
};

void Registry_87a90::FUN_00087a90(const char* name, float (*fn)()) {
    void* mem = FUN_0008d690(0x20);
    Function0<float>* c = 0;
    if (mem)
        c = new (mem) Function0<float>(name, fn);
    FUN_001d3b70(name, c);
}
