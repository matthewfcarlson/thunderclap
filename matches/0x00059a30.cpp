#include "compat/ptr.h"
class Obj_59a30 {
    char pad[0x10];

  public:
    unsigned int value;
};
extern "C" hulk_uintptr __fastcall FUN_00059a30(Obj_59a30* self) {
    return self->value;
}