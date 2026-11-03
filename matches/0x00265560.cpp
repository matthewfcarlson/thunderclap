#include "gen/owners.h"
class Obj_265560 {
  public:
    virtual void f();
    virtual void g();
};
class Holder_265560 {
  public:
};
class C_265560 {
  public:
    char pad[0x0c];
    Holder_265560* m;
    void target(Obj_265560* p);
};
void C_265560::target(Obj_265560* p) {
    int n = ((owners::Obj_231770 *)m)->FUN_00231770((hulk_uintptr)(Obj_265560 *)p);
    while (n > 0) {
        p->g();
        --n;
    }
}