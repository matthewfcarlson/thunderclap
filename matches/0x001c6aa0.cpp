#include "compat/ptr.h"
class C_1c6aa0 {
  public:
    char pad[0x0c];
    int value;
};
hulk_intptr __fastcall target(C_1c6aa0* self) {
    return self->value + 0x14;
}