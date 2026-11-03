#include "compat/ptr.h"
#include "gen/owners.h"
typedef unsigned short U16;
void owners::Buffer_2f9930::FUN_002f9930(U16* src, int count, hulk_intptr value) {
    U16* p = cur;
    U16* q = p + count;
    if (q <= end) {
        cur = q;
        while (p != src) {
            --p;
            --q;
            if (q != 0)
                *q = *p;
        }
        U16* r = src;
        if (count != 0) {
            hulk_intptr d = ((int)value) - (hulk_intptr)src;
            int n = count;
            do {
                if (r != 0)
                    *r = *(U16*)(d + (hulk_intptr)r);
                ++r;
                --n;
            } while (n != 0);
        }
    }
}
