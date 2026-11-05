#include "compat/ptr.h"
#include "gen/owners.h"
class Child_99aa0 {
  public:
    void run(int a, int b);
};
class Obj_99aa0 {
  public:
    char pad[0xb8];
    Child_99aa0* member;
    void f(hulk_intptr x);
};
extern int gValue_99aa0;
void Obj_99aa0::f(hulk_intptr x) {
    if (member != 0) {
        int v = ((int)((owners::C_a0b70 *)member)->FUN_000a0b70());
        if (v != 0 && x == v)
            member->run(gValue_99aa0, x);
    }
}
