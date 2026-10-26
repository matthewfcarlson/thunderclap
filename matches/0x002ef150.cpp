#include "decls/data/game/global.h"

class CollisionDetector_2ef150 {
  public:
    void f();
    char pad[0x40];
};
class ImpulseBasedCollisionSolver_2ef150 {
  public:
    void f();
    char pad[0x100];
};
class C {
  public:
    void f();
};
class Obj {
  public:
    void clean();
    char p0[0x70];
    CollisionDetector_2ef150 a;
    ImpulseBasedCollisionSolver_2ef150 b;
    C c;
};
extern "C" void __cdecl freeObj(void*);
void destroyObj() {
    Obj* p = (*(Obj**)&DAT_00554c14);
    if (p) {
        p->c.f();
        p->b.f();
        p->a.f();
        p->clean();
        freeObj(p);
    }
    (*(Obj**)&DAT_00554c14) = 0;
}