#include "compat/ptr.h"
struct Obj_2907f0 {
    int a;
    int b;
};
extern "C" void __cdecl FUN_00290500(void *, void *);
extern void __cdecl g(int);
void __fastcall target(Obj_2907f0* self) {
    if (self->a) {
        FUN_00290500((void *)(hulk_uintptr)(int)(self->a), (void *)(hulk_uintptr)(int)(self->b));
        g(self->a);
    }
}