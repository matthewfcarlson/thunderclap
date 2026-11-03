#include "gen/owners.h"
struct Obj_309820 {
    int x;
    int* target();
};
int* Obj_309820::target() {
    ((owners::Obj_2fd730 *)this)->FUN_002fd730();
    return &x + 1;
}