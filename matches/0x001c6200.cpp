#include "gen/owners.h"
class B_1c6200 {
  public:
};
class A_1c6200 {
  public:
    char pad[0x284];
    B_1c6200* member;
    void f(void*);
};
void A_1c6200::f(void* param) {
    ((owners::X_2647e0 *)member)->FUN_002647e0((hulk_intptr)param, (hulk_intptr)3, 4, (hulk_intptr)1);
}