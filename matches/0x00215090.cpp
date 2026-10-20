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
void copy(void*, int, unsigned int, int);
void target(void* p, Obj_215090* s) {
    prep(s, s->a);
    copy(p, s->b, ((unsigned int)s->d) << 4, 0);
    copy(p, s->a, ((unsigned int)s->c) << 3, 0);
    copy(p, (hulk_intptr)s, 0x58, 0);
}