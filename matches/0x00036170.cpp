#include "decls/data/game/global.h"
// data: zero_36170 = DAT_003f32e0

class Obj_36170 {
    char pad[0x1b18];

  public:
    float value;
    int count;
};
bool __fastcall FUN_00036170(Obj_36170* self) {
    if (self->value > DAT_003f32e0)
        return true;
    return self->count > 0;
}