#include "compat/ptr.h"
class Obj_213440 {
  public:
    char pad[0x10];
    void* state;
};
struct State_213440 {
    char pad[0x48];
    unsigned int a;
    unsigned int b;
};
void __cdecl helper1(Obj_213440*);
extern "C" const char * __cdecl FUN_002160c0(void *, const char *, char *);
extern "C" void __cdecl FUN_00213440(Obj_213440* self, hulk_intptr x, hulk_intptr y) {
    State_213440* s = (State_213440*)self->state;
    if (s->b >= s->a)
        helper1(self);
    FUN_002160c0((Obj_213440 *)self, (const char *)(hulk_uintptr)x, (char *)(hulk_uintptr)y);
}