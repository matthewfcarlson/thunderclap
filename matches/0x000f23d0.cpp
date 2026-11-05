#include "compat/ptr.h"
class DynamicCaster_f23d0 {
  public:
    virtual void f();
};
class Inv {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int use(DynamicCaster_f23d0*, __int64);
};
extern __int64 __cdecl fetch(void*);
extern "C" hulk_intptr __cdecl FUN_000f23d0(Inv* inv, void* name) {
    __int64 val = fetch(name);
    DynamicCaster_f23d0 caster;
    return inv->use(&caster, val);
}