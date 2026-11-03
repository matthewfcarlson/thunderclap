#include "gen/owners.h"
class B_1c3bb0 {
  public:
};
class A_1c3bb0 {
  public:
    char pad[12];
    B_1c3bb0* member;
    void* f(int);
};
class C_1c3bb0 {
  public:
    char pad[12];
    A_1c3bb0* member;
    void run(int, int);
};
void C_1c3bb0::run(int a, int b) {
    B_1c3bb0* p = (B_1c3bb0*)member->f(a);
    if (p)
        ((owners::X_1c4d60 *)p)->FUN_001c4d60((unsigned int *)(hulk_uintptr)(int)b);
}