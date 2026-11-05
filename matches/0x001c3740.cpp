#include "compat/ptr.h"
#include "gen/owners.h"
class H {
  public:
    int check(int);
};
class C_1c3740 {
    char pad[0x0c];
    H* member;

  public:
    void f(hulk_intptr);
};
void C_1c3740::f(hulk_intptr x) {
    if (member->check(x))
        ((owners::Obj_1c5b10 *)member)->FUN_001c5b10((unsigned int)x);
}