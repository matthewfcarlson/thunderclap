#include "decls/data/game/global.h"
// data: flag_678d0 = DAT_004dcec0, object_678d0 = DAT_004dc678

extern "C" int atexit(void (*)());
extern "C" void cleanup();
struct Obj_678d0 {
    void init();
};
extern "C" Obj_678d0* FUN_000678d0() {
    if (((*(unsigned int*)&DAT_004dcec0) & 1) == 0) {
        (*(unsigned int*)&DAT_004dcec0) = (*(unsigned int*)&DAT_004dcec0) | 1;
        (*(Obj_678d0*)&DAT_004dc678).init();
        atexit(cleanup);
    }
    return ((Obj_678d0*)&DAT_004dc678);
}