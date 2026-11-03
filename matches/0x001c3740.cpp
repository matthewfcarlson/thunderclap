#include "gen/owners.h"
class H {
  public:
    int check(int);
};
class C_1c3740 {
    char pad[0x0c];
    H* member;

  public:
    void f(int);
};
void C_1c3740::f(int x) {
    if (member->check(x))
        ((owners::Obj_1c5b10 *)member)->FUN_001c5b10((unsigned int)x);
}