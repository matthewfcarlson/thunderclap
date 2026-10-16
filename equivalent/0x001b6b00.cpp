// STATUS: equivalent (tools/equiv.py level 3: 113 inputs, branch coverage 33/36, incomplete)
// FUN_001b6b00 @ 0x001b6b00
#include "decls/address.h"
struct V3_1b6b00 {
    float x, y, z;
};

struct Info_1b6b00 {
    char pad[0x114];
    int blocked;
};

class Slot_1b6b00 {
public:
    virtual void v0();
    virtual void release();
    virtual void v2();
    virtual V3_1b6b00 *getPos();
    virtual void v4();
    virtual Info_1b6b00 *getInfo();
    char pad08[0x8 - 4];
    int link;                // 0x08
    char pad0c[0x14 - 0xc];
    int priority;            // 0x14
};

struct Camera {
    void FUN_00059a50(V3_1b6b00 *out);
};

struct Reg124_1b6b00 {
    char pad[0x10];
    Camera *cam;
};

struct Reg20_1b6b00 {
    char pad[0x124];
    Reg124_1b6b00 *p124;
};

struct World {
    char pad[0x20];
    Reg20_1b6b00 *p20;
};


class SlotTable_1b6b00 {
public:
    Slot_1b6b00 *slots[32];
    int FUN_001b6b00(int bestPriority, V3_1b6b00 *pt);
};

static double dist2(V3_1b6b00 *a, V3_1b6b00 *b)
{
    double dx = (double)a->x - (double)b->x;
    double dy = (double)a->y - (double)b->y;
    double dz = (double)a->z - (double)b->z;
    return dz * dz + dy * dy + dx * dx;
}

int SlotTable_1b6b00::FUN_001b6b00(int bestPriority, V3_1b6b00 *pt)
{
    int i;
    for (i = 0; i < 32; i++) {
        if (slots[i] == 0)
            return i;
    }
    if (DAT_004dd700 == 0)
        return -1;
    Reg20_1b6b00 *r20 = DAT_004dd700->p20;
    if (r20 == 0)
        return -1;
    Reg124_1b6b00 *r124 = r20->p124;
    if (r124 == 0)
        return -1;

    V3_1b6b00 origin;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    r124->cam->FUN_00059a50(&origin);

    float best = (float)dist2(pt, &origin);
    int bestIndex = -1;
    int prio = bestPriority;
    for (i = 0; i < 32; i++) {
        if (slots[i] == 0)
            continue;
        Info_1b6b00 *info = slots[i]->getInfo();
        if (info != 0 && info->blocked != 0)
            continue;
        int p = slots[i]->priority;
        if (p < prio) {
            bestIndex = i;
            prio = p;
            V3_1b6b00 *pos = slots[i]->getPos();
            best = (float)dist2(pos, &origin);
        } else if (p == prio) {
            V3_1b6b00 *pos = slots[i]->getPos();
            double d = dist2(pos, &origin);
            if (d < best) {
                best = (float)d;
                bestIndex = i;
            }
        }
    }

    if (bestIndex < 0)
        return -1;

    Slot_1b6b00 *s = slots[bestIndex];
    if (s != 0) {
        int j = s->link;
        if (j >= 0 && j < 32) {
            Slot_1b6b00 *t = slots[j];
            if (t != 0) {
                t->release();
                slots[j] = 0;
            }
        }
    }
    return bestIndex;
}
