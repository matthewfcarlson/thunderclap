// Same code shape as 0x000862e0 (propagated; names are from that function)
#include "compat/ptr.h"
class C_1b3300 {
    char pad[0x30];

  public:
    unsigned int value;
};
hulk_uintptr __fastcall FUN_001b3300(C_1b3300* self) {
    return self->value;
}