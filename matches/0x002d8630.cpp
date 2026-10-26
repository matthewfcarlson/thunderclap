#include "compat/ptr.h"
struct S_2d8630 {
    char p0[8];
    unsigned char f8;
    char p1[0xd];
    unsigned short f16;
    char p2[1];
    unsigned char f19;
    char p3[0x32];
    int f4c;
    int f50;
};
int F(int a, S_2d8630* s, int* o1, unsigned* o2, int* o3) {
    int r = 0;
    if (a != 0 && s != 0 && (s->f8 & 0x10) != 0) {
        if (s->f19 == 3) {
            if (o1 != 0) {
                *o1 = s->f4c;
                r = 0x10;
            }
            if (o3 != 0) {
                *(hulk_intptr*)o3 = (hulk_intptr)&s->f50;
            }
        } else {
            if (o3 != 0) {
                *(hulk_intptr*)o3 = (hulk_intptr)&s->f50;
                r = 0x10;
            }
            if (o1 != 0) {
                *o1 = 0;
            }
        }
        if (o2 != 0) {
            *o2 = s->f16;
            r |= 0x10;
        }
    }
    return r;
}
