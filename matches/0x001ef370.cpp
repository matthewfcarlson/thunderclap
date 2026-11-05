#include "compat/ptr.h"
#include "gen/owners.h"
struct Item_1ef370 {
    char pad[8];
};
class C_1ef370 {
  public:
    Item_1ef370 items[8];
    int count;
    void f(hulk_intptr);
};
void C_1ef370::f(hulk_intptr x) {
    if (count < 8) {
        ((owners::Target_27b040 *)&(items[count]))->FUN_0027b040((hulk_uintptr)x);
        ++count;
    }
}