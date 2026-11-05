// Same code shape as 0x000862d0 (propagated; names are from that function)
#include "compat/ptr.h"
struct X_c7b60 {
    char pad[0x14];
    unsigned value;
};
hulk_uintptr __fastcall target(X_c7b60* self) {
    return self->value;
}