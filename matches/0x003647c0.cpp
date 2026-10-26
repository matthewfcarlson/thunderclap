#include "decls/data/engine/physics.h"

extern "C" {
void __cdecl thunk(int);
void __cdecl work(int, int);
void __cdecl FUN_003647c0(void) {
    if ((*(int*)&DAT_00555468) != 0)
        thunk((*(int*)&DAT_00555468));
    if ((*(int*)&DAT_0055545c) != 0) {
        work((*(int*)&DAT_0055545c), (*(int*)&DAT_00555460));
        thunk((*(int*)&DAT_0055545c));
    }
}
}