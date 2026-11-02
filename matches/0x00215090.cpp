#include "compat/ptr.h"
typedef unsigned short u16;
struct Obj_215090 {
    char pad[0x1c];
    int a;
    int c;
    char gap[4];
    int b;
    u16 d;
};
void prep(Obj_215090*, int);
void copy(void*, hulk_intptr, unsigned int, int);
extern "C" void FUN_00215090(void* p, void * s) {
    prep(((Obj_215090 *)s), ((Obj_215090 *)s)->a);
    copy(p, ((Obj_215090 *)s)->b, ((unsigned int)((Obj_215090 *)s)->d) << 4, 0);
    copy(p, ((Obj_215090 *)s)->a, ((unsigned int)((Obj_215090 *)s)->c) << 3, 0);
    copy(p, (hulk_intptr)((Obj_215090 *)s), 0x58, 0);
}