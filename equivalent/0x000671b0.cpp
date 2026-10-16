// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000671b0 @ 0x000671b0
// 0x000671b0: record a target position and re-arm the timer once the cooldown has passed or it moved
#include "decls/address.h"
struct Vec3_671b0 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_671b0* other, float eps);
};

struct Clock_671b0 {
    float FUN_00086080();
};

struct World {
    char pad[0x2c];
    int link;
};

class Tracker_671b0 {
public:
    int link;
    Clock_671b0* clock;
    char pad08[0x14c];
    Vec3_671b0 pos;
    char pad160[0x1e8];
    float next_time;
    char pad34c[4];
    float interval;
    void FUN_00066d50();
    void FUN_000671b0(const Vec3_671b0* target);
};

void Tracker_671b0::FUN_000671b0(const Vec3_671b0* target)
{
    if (clock == 0)
        return;
    if (link == 0) {
        link = DAT_004dd700->link;
        if (link == 0)
            return;
    }
    pos.x = target->x;
    pos.y = target->y;
    pos.z = target->z;
    if (clock->FUN_00086080() >= next_time || !((Vec3_671b0*)target)->FUN_0022d2b0(&pos, 1e-05f)) {
        FUN_00066d50();
        next_time = clock->FUN_00086080() + interval;
    }
}
