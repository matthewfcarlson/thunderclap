#include "compat/ptr.h"
class Obj_37400 {
    char pad[0x22b4];

  public:
    int value;
};
hulk_intptr __fastcall target(Obj_37400* self) {
    return self->value;
}