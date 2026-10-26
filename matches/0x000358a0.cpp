#include "decls/data/game/global.h"
// data: zero_358a0 = DAT_003f32e0

struct Obj_358a0 {
    char pad[0x1e4];
    float value;
};
int __fastcall target(Obj_358a0* self) {
    return self->value > DAT_003f32e0;
}