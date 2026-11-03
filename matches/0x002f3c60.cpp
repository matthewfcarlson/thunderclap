#include "gen/owners.h"
void Free(void* p);
void Free2(void* p);
owners::T_2f3c60* owners::T_2f3c60::FUN_002f3c60(unsigned char f) {
    if (f & 2) {
        int n = ((int*)this)[-1];
        owners::T_2f3c60* p = this + n;
        while (--n >= 0) {
            --p;
            p->Dtor();
        }
        if (f & 1)
            Free((int*)this - 1);
        return (owners::T_2f3c60*)((int*)this - 1);
    }
    Dtor();
    if (f & 1)
        Free2(this);
    return this;
}
