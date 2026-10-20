#include "compat/ptr.h"
extern "C" void* __cdecl Alloc(hulk_uintptr);
class Obj {
  public:
    Obj* init(int) throw();
    char pad[0x94];
};
Obj* __cdecl FUN_00327ec0(int a) {
    Obj* p = (Obj*)Alloc(sizeof(Obj));
    if (p)
        return p->init(a);
    return 0;
}
