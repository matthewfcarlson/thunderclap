#include "compat/ptr.h"
typedef unsigned int u32_25bbd0;
extern "C" void __cdecl FUN_0025b7d0(void *);
void thunk_FUN_00267090(u32_25bbd0);
struct S_25bbd0 {
    u32_25bbd0 value;
};
void __fastcall target(S_25bbd0* self) {
    if (self->value != 0) {
        FUN_0025b7d0((void *)(hulk_uintptr)(unsigned int)(self->value));
        if (self->value != 0)
            thunk_FUN_00267090(self->value);
        self->value = 0;
    }
}