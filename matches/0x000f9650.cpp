#include "gen/owners.h"
struct Inner_f9650 {
};
struct Obj_f9650 {
    char pad[0x284];
    Inner_f9650* p;
    void Target(int a, int b, int c);
};
void Obj_f9650::Target(int a, int b, int c) {
    ((owners::X_2647e0 *)p)->FUN_002647e0((hulk_intptr)a, (hulk_intptr)b, c, (hulk_intptr)1);
}