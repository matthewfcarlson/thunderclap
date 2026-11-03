#include "decls/data/game/unknown.h"
// data: gRandom = DAT_004de948
#include "gen/owners.h"

typedef float(__cdecl* RandomFn)();
void owners::Obj_de1d0::FUN_000de1d0() {
    first += (*(RandomFn*)&DAT_004de948)();
    second += (*(RandomFn*)&DAT_004de948)();
}