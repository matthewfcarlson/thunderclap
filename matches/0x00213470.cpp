#include "compat/ptr.h"
class Obj_213470 {
  public:
    char pad[0x10];
    struct Inner_213470* p;
};
struct Inner_213470 {
    char pad[0x48];
    unsigned int a;
    unsigned int b;
};
void helper1(Obj_213470*);
extern "C" const char * __cdecl FUN_002160c0(void *, const char *, char *);
extern "C" int FUN_00213470(Obj_213470* self, hulk_intptr arg, ...) {
    Inner_213470* q = self->p;
    if (q->b >= q->a)
        helper1(self);
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, arg);
    return ((int)(hulk_uintptr)FUN_002160c0((Obj_213470 *)self, (const char *)arg, args));
#else
    return ((int)(hulk_uintptr)FUN_002160c0((Obj_213470 *)self, (const char *)(hulk_uintptr)(int)arg, (char *)(int *)((int*)((char*)&arg + 4))));
#endif
}