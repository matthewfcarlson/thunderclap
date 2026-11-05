#include "compat/ptr.h"
class C_86280 {
    char pad[0x20];

  public:
    unsigned int value;
};
hulk_uintptr __fastcall target(C_86280* self) {
    return self->value;
}