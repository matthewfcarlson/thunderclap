#include "decls/data/game/hulkfight.h"
// data: g_one_78b20 = DAT_00421894

class Object {
    char pad[0x80];

  public:
    float value;
};
int __fastcall target(Object* self) {
    return self->value == DAT_00421894;
}