#include "decls/data/game/global.h"
// data: Half = DAT_003f32f4

#include "compat/ptr.h"
struct V {
    char pad[8];
    float value;
};
hulk_freg __cdecl FUN_002f2950(V* a, V* b) {
    return (a->value + b->value) * DAT_003f32f4;
}