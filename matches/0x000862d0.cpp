#include "compat/ptr.h"
struct X_862d0 {
    char pad[0x14];
    unsigned value;
};
hulk_uintptr __fastcall target(X_862d0* self) {
    return self->value;
}