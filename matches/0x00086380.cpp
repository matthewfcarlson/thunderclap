#include "compat/ptr.h"
class A_86380 {
    char pad[0x4c];

  public:
    unsigned int value;
};
hulk_uintptr __fastcall target(A_86380* self) {
    return self->value;
}