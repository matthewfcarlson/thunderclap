#include "compat/ptr.h"
class DynamicCaster_1a9420 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d();
};
extern "C" __int64 __cdecl lookup(void*, int, int);
class LoadInventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d(DynamicCaster_1a9420*, __int64);
    hulk_intptr Load(void* p);
};
hulk_intptr LoadInventory::Load(void* p) {
    DynamicCaster_1a9420 caster;
    return d(&caster, lookup(p, 0, 0));
}