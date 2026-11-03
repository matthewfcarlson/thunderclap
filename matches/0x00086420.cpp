#include "gen/owners.h"
struct A_86420 {
    void f();
};
struct B_86420 {
    void g();
};
struct Hub_86420 {
    char pad[0x10];
    A_86420* a;
    char pad2[4];
    B_86420* b;
};
struct Manager_86420 {
    char pad[0x54];
    Hub_86420* hub;
};
extern Manager_86420* gManager_86420;
void owners::Target_86420::FUN_00086420(int v) {
    value = v;
    if (v == 1)
        gManager_86420->hub->a->f();
    gManager_86420->hub->b->g();
}
