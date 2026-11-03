#include "gen/owners.h"
struct B_d6f10 {
};
struct C_d6f10 {
    void y(int);
};
struct A_d6f10 {
    int pad;
    B_d6f10* b;
    C_d6f10* c;
    void run(int);
};
void A_d6f10::run(int v) {
    ((owners::Obj_d4370 *)b)->FUN_000d4370((hulk_intptr)v);
    c->y(v);
}
