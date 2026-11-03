#include "gen/owners.h"
class Obj_1f6ba0 {
  public:
    char pad[8];
    int field;
};
class Owner_1f6ba0 {
  public:
    char pad[0xc8];
    Obj_1f6ba0* member;
};
bool __fastcall run(Owner_1f6ba0* self) {
    Obj_1f6ba0* p = self->member;
    if (p && p->field) {
        ((owners::Obj_1f67c0 *)p)->FUN_001f67c0();
        return true;
    }
    return false;
}
