#include "gen/owners.h"
struct Inner_201c00 {
};
class Thing_201c00 {
  public:
    char pad[0x18];
    int value;
    char pad2[4];
    Inner_201c00 inner;
    void f();
};
void Thing_201c00::f() {
    value = 0xc61c4000;
    ((owners::Target_27b040 *)&inner)->FUN_0027b040((hulk_uintptr)0);
    ((char*)this)[0x28] = 0;
}