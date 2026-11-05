#include "compat/ptr.h"
class Target_1d6c90 {
    char pad[0x258];

  public:
    unsigned int value;
};
hulk_uintptr __fastcall FUN_001d6c90(Target_1d6c90* self) {
    return self->value;
}