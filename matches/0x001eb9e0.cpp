#include "decls/data/game/global.h"
// data: g_limit_1eb9e0 = DAT_003f32d8, g_zero_1eb9e0 = DAT_003f32e0
#include "gen/owners.h"

struct Chain_1eb9e0 {
};
struct Wrap_1eb9e0 {
    Chain_1eb9e0* inner;
};
struct Obj_1eb9e0 {
    Wrap_1eb9e0* next;
    char pad[8];
    float value;
    void UpdateValue(float x);
};
void Obj_1eb9e0::UpdateValue(float x) {
    if (x < DAT_003f32e0 || x > DAT_003f32d8)
        return;
    value = x;
    ((owners::Obj_1f3950 *)(next->inner))->FUN_001f3950(x);
}
