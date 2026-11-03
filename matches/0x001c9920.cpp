#include "gen/owners.h"
typedef unsigned char u8_1c9920;
__int64 Make(int);
struct ThisCall_001c9750 {
};
owners::Obj_1c9920* owners::Obj_1c9920::FUN_001c9920(int p2, hulk_intptr p3, int p4, u8_1c9920 p5) {
    ((owners::Object_1c9750 *)(((ThisCall_001c9750*)(this))))->FUN_001c9750(1, 0xc0, (unsigned)p2);
    union U {
        __int64 q;
        struct {
            unsigned int lo, hi;
        } s;
    } u;
    u.q = Make(((int)p3));
    a = u.s.lo;
    b = u.s.hi;
    c = p5;
    value = p4;
    return this;
}