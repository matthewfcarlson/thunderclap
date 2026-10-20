// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 9/10, incomplete)
// FUN_002b0e90 @ 0x002b0e90
#include "compat/ptr.h"
void *FUN_0008d6d0(hulk_uintptr size);

struct Elem_2b0e90 {
    int a;
    int b;
};
struct Vec_2b0e90 {
    Elem_2b0e90 *begin;
    Elem_2b0e90 *end;
    Vec_2b0e90 *FUN_002b0e90(const Vec_2b0e90 *src);
};

Vec_2b0e90 *Vec_2b0e90::FUN_002b0e90(const Vec_2b0e90 *src)
{
    hulk_intptr n = src->end - src->begin;
    if (n != 0) {
        Elem_2b0e90 *dst = (Elem_2b0e90 *)FUN_0008d6d0(n * sizeof(Elem_2b0e90));
        begin = dst;
        if (dst != 0) {
            end = dst + n;
            const Elem_2b0e90 *s = src->begin;
            for (hulk_intptr k = src->end - s; k != 0; k--) {
                if (dst != 0) {
                    dst->a = s->a;
                    dst->b = s->b;
                }
                s++;
                dst++;
            }
            return this;
        }
    }
    begin = 0;
    end = 0;
    return this;
}
