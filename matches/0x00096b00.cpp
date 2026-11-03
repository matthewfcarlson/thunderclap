#include "gen/owners.h"
struct Helper_96b00 {
    char pad[8];
};
struct Obj_96b00 {
    char pad0[8];
    Helper_96b00* helper;
    int state;
    char pad10[0x40];
    int a;
    int b;
    int c;
};
extern "C" void __cdecl FUN_00096b00(void * self, int* out) {
    int n = ((Obj_96b00 *)self)->state;
    --n;
    if (n != 0) {
        out[0] = ((Obj_96b00 *)self)->a;
        out[1] = ((Obj_96b00 *)self)->b;
        out[2] = ((Obj_96b00 *)self)->c;
        return;
    }
    if (!((owners::C_35660 *)(((Obj_96b00 *)self)->helper))->FUN_00035660((int *)out)) {
        out[0] = ((Obj_96b00 *)self)->a;
        out[1] = ((Obj_96b00 *)self)->b;
        out[2] = ((Obj_96b00 *)self)->c;
    }
}