#include "gen/owners.h"
class C_1c3b80;
class D {
  public:
};
class C_1c3b80 {
  public:
    void* pad[3];
    int Get(int);
    void Finish(int);
};
class Obj_1c3b80 {
  public:
    char pad0[4];
    D* m4;
    char pad8[4];
    C_1c3b80* mC;
    void Target(int);
};
void Obj_1c3b80::Target(int arg) {
    int x = mC->Get(arg);
    if (x) {
        ((owners::C_1c8860 *)m4)->FUN_001c8860(x);
        mC->Finish(arg);
    }
}