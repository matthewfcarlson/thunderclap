// Same code shape as 0x00059a30 (propagated; names are from that function)
#include "compat/ptr.h"
class Obj_862c0 {
    char pad[0x10];

  public:
    unsigned int value;
};
extern "C" hulk_uintptr __fastcall FUN_000862c0(Obj_862c0* self) {
    return self->value;
}