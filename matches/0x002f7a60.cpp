#include "decls/data/game/global.h"

struct Global_2f7a60 {
    char pad[0x28];
    int a;
    char pad2[4];
    int b;
};
class Obj_2f7a60 {
  public:
    char pad[0xe8];
    int a;
    int b;
};
void __fastcall target(Obj_2f7a60* self) {
    self->a = (*(Global_2f7a60**)&DAT_00554c10)->b;
    self->b = (*(Global_2f7a60**)&DAT_00554c10)->a;
}