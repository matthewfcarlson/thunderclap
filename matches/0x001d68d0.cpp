#include "compat/ptr.h"
class C_1d68d0 {
  public:
    char pad[0x11c];
    int* p;
};
hulk_intptr __fastcall target(C_1d68d0* self) {
    if (!self->p)
        return 0;
    return self->p[6];
}