#include "decls/data/game/global.h"
// data: gTable_1d4f40 = DAT_004e24c0

struct Obj_1d4f40 {
    char pad[0xa0];
    int index;
};
struct Pair_1d4f40 {
    int lo;
    int hi;
};
Pair_1d4f40 __fastcall target(Obj_1d4f40* self) {
    return ((Pair_1d4f40*)&DAT_004e24c0)[self->index];
}