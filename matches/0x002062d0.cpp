#include "decls/data/engine/content.h"
// data: gManager_2062d0 = DAT_00527c58

#include "compat/ptr.h"
extern "C" char DAT_00425c28[];
extern void* __cdecl Alloc(hulk_uintptr);
struct Loader_2062d0 {
    hulk_uintptr vptr;
    int a;
    int b;
    int c;
    int d;
    void* owner;
};
class Manager_2062d0 {
  public:
    void Register(Loader_2062d0*, unsigned int);
};
class Owner_2062d0 {
  public:
    char pad[0x588];
    int param;
    void Target(int);
};
void Owner_2062d0::Target(int value) {
    param = value;
    Loader_2062d0* r;
    Loader_2062d0* p = (Loader_2062d0*)Alloc(0x18);
    if (p != 0) {
        p->a = 0;
        p->b = 0x60000722;
        p->c = 0;
        p->d = 0;
        p->vptr = ((hulk_intptr)DAT_00425c28);
        p->owner = this;
        r = p;
    } else {
        r = 0;
    }
    (*(Manager_2062d0**)&DAT_00527c58)->Register(r, 0x60000722);
}
