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
extern "C" int FUN_00213470(Obj_213470* self, int arg) {
    Inner_213470* q = self->p;
    if (q->b >= q->a)
        helper1(self);
    return ((int)(hulk_uintptr)FUN_002160c0((Obj_213470 *)self, (const char *)(hulk_uintptr)(int)arg, (char *)(int *)((int*)((char*)&arg + 4))));
}