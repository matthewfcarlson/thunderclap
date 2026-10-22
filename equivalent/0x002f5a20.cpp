// STATUS: equivalent (tools/equiv.py level 3: 19923 inputs, branch coverage 2/2)
// FUN_002f5a20 @ 0x002f5a20
#include "compat/ptr.h"
// FUN_002f5a20: move the pivot (or, when free, the cross product of the offset and the axis) onto a position
struct V3_2f5a20 {
    float x, y, z;
};

struct Body_2f5a20 {
    char pad00[0x40];
    float x, y, z;
    char pad4c[4];
    V3_2f5a20 pos;
    float ax, ay, az;
};

class PhysicsObject_2f5a20 {
public:
    char pad00[0x10];
    Body_2f5a20 *body;
    char pad14[0x84];
    float px, py, pz;
    char locked;

    void FUN_002f5a20(V3_2f5a20 *target);
};

void PhysicsObject_2f5a20::FUN_002f5a20(V3_2f5a20 *target)
{
    Body_2f5a20 *b = body;
    if (locked) {
        b->pos = *target;
        return;
    }
    // x87: the differences and cz stay in registers (53 bits); cx and cy are rounded frame copies
    hulk_freg dx = b->x - px;
    hulk_freg dy = b->y - py;
    hulk_freg dz = b->z - pz;
    volatile float cx = dz * b->ay - dy * b->az;
    volatile float cy = dx * b->az - dz * b->ax;
    hulk_freg cz = dy * b->ax - dx * b->ay;
    b->pos.x = cx + target->x;
    b->pos.y = cy + target->y;
    b->pos.z = cz + target->z;
}
