#include "compat/ptr.h"
struct X_35b60 {
    char pad[0x22e4];
    unsigned int value;
};
hulk_uintptr __fastcall target(X_35b60* self) {
    return self->value;
}