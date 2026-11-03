#include "gen/owners.h"
class Obj_1c9fb0 {
  public:
    void finish();
};
class This_1c9fb0 {
  public:
    char pad[0x14];
    int a;
    char pad2[0x1c];
    int b;
    Obj_1c9fb0* get();
};
bool __fastcall target(This_1c9fb0* self) {
    Obj_1c9fb0* o = self->get();
    if (!o)
        return false;
    if (!((owners::Obj_1d2e80 *)o)->FUN_001d2e80())
        return false;
    ((owners::Thing_1d1d50 *)o)->FUN_001d1d50((hulk_uintptr)"eg", (hulk_uintptr)(&self->a));
    ((owners::Thing_1d1d50 *)o)->FUN_001d1d50((hulk_uintptr)"locator", (hulk_uintptr)(&self->b));
    o->finish();
    return true;
}