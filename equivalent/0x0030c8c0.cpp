// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0030c8c0 @ 0x0030c8c0
#include "gen/owners.h"

owners::Obj_30c8c0 *owners::Obj_30c8c0::FUN_0030c8c0(owners::Obj_30c8c0 *src)
{
    FUN_0030c690(src);
    b0 = src->b0;
    for (int i = 0; i < 0x15; i++)
        a[i] = src->a[i];
    c0 = src->c0;
    c1 = src->c1;
    d0 = src->d0;
    d1 = src->d1;
    return this;
}
