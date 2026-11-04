#include "compat/ptr.h"
class Obj_213470 {
  public:
    // lua_State's head: CommonHeader (next, tt, marked), top, base, then l_G (pointers: +0x10 on i386, +0x20 on x64)
    void* next;
    unsigned char tt, marked;
    void* top;
    void* base;
    struct Inner_213470* p;
};
struct Inner_213470 {
    char pad[0x48];
    unsigned int a;
    unsigned int b;
};
void helper1(Obj_213470*);
extern "C" const char * __cdecl FUN_002160c0(void *, const char *, char *);
extern "C" const char* FUN_00213470(Obj_213470* self, hulk_intptr arg, ...) {
    Inner_213470* q = self->p;
    if (q->b >= q->a)
        helper1(self);
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, arg);
    return FUN_002160c0((Obj_213470 *)self, (const char *)arg, args);
#else
    return FUN_002160c0((Obj_213470 *)self, (const char *)(hulk_uintptr)(int)arg, (char *)(int *)((int*)((char*)&arg + 4)));
#endif
}