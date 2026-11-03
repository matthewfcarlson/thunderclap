#include "gen/owners.h"
class Callee {
  public:
};
class Obj {
  public:
    char pad[0x1c];
    Callee* ptr;
};
extern "C" void FUN_002469f0(Obj* o, void* a, void* b, void* c) {
    ((owners::X_2647e0 *)(o->ptr))->FUN_002647e0((hulk_intptr)a, (hulk_intptr)b, 1, (hulk_intptr)c);
}