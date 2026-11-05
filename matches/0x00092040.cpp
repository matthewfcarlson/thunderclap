// Same code shape as 0x000862e0 (propagated; names are from that function)
#include "compat/ptr.h"
class C_92040 {
    char pad[0x30];

  public:
    unsigned int value;
};
hulk_uintptr __fastcall FUN_00092040(C_92040* self) {
    return self->value;
}