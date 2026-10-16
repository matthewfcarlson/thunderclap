// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 18/18)
// FUN_00306650 @ 0x00306650
#include "decls/data/game/global.h"

struct Vec3_306650 {
    float x, y, z;
};


class Box_306650 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_306650 *GetPos();
    char pad4[0x24];
    float ex;
    float ey;
    float ez;
    char pad34[4];
    float sx;
    float sy;
    float sz;
};

// equiv-conv: FUN_00306650 esi edi stack
bool FUN_00306650(Box_306650 *a, Box_306650 *b, float margin)
{
    Vec3_306650 *pb = b->GetPos();
    Vec3_306650 *pa = a->GetPos();
    float d = pb->y - pa->y;
    if (a->ey == (*(float*)&DAT_003f32e0)) {
        if (margin + b->ey < d * a->sy)
            return false;
    } else {
        *(unsigned *)&d &= 0x7fffffff;
        if (b->ey + a->ey + margin < d)
            return false;
    }

    pb = b->GetPos();
    pa = a->GetPos();
    d = pb->x - pa->x;
    if (a->ex == (*(float*)&DAT_003f32e0)) {
        if (margin + b->ex < d * a->sx)
            return false;
    } else {
        *(unsigned *)&d &= 0x7fffffff;
        if (margin + b->ex + a->ex < d)
            return false;
    }

    pb = b->GetPos();
    pa = a->GetPos();
    d = pb->z - pa->z;
    if (a->ez == (*(float*)&DAT_003f32e0)) {
        if (margin + b->ez < d * a->sz)
            return false;
    } else {
        *(unsigned *)&d &= 0x7fffffff;
        if (margin + b->ez + a->ez < d)
            return false;
    }
    return true;
}
