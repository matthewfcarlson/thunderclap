// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 18/18)
// FUN_00066390 @ 0x00066390
struct Vec3_66390 {
    float x, y, z;
    float FUN_0022d110();
};

struct Transform_66390 {
    void FUN_00059a50(Vec3_66390 *out);
};

struct Target_66390 {
    char pad0[0x10];
    Transform_66390 *transform;
    char pad1[0x1b0c - 0x14];
    float score;
    char pad2[0x1ba4 - 0x1b10];
    char locked;
};

struct TargetTable_66390 {
    Target_66390 *FUN_00024280(int a, int b);
};

struct World {
    char pad0[0x20];
    TargetTable_66390 *targets;
};

extern World *DAT_004dd700;

struct Key_66390 {
    int a, b;
};

struct Clock_66390 {
    float FUN_00086080();
};

class Tracker_66390 {
public:
    Target_66390 *FUN_00066390(Vec3_66390 *pos);

    char pad0[4];
    Clock_66390 *clock;
    char pad1[0x154 - 8];
    Vec3_66390 origin;
    char pad2[0x170 - 0x160];
    Key_66390 keys[40];
    int count;
    char pad4[0x354 - 0x2b4];
    float result;
};

Target_66390 *Tracker_66390::FUN_00066390(Vec3_66390 *pos)
{
    origin = *pos;
    Target_66390 *best = 0;
    float bestDist = 0.0f;
    for (int i = 0; i < count; i++) {
        Target_66390 *t = DAT_004dd700->targets->FUN_00024280(keys[i].a, keys[i].b);
        Vec3_66390 p;
        t->transform->FUN_00059a50(&p);
        if (t->score < 0.0f) {
            for (int j = i + 1; j < count; j++)
                keys[j - 1] = keys[j];
            count--;
            i--;
        } else {
            Vec3_66390 d;
            d.x = p.x - origin.x;
            d.y = p.y - origin.y;
            d.z = p.z - origin.z;
            float dist = d.FUN_0022d110();
            if (best == 0 || dist < bestDist) {
                bestDist = dist;
                best = t;
            }
        }
    }
    if (best != 0 && !best->locked)
        result = clock->FUN_00086080();
    return best;
}
