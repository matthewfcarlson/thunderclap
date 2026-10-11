// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 18/18)
// FUN_00066390 @ 0x00066390
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Transform {
    void FUN_00059a50(Vec3 *out);
};

struct Target {
    char pad0[0x10];
    Transform *transform;
    char pad1[0x1b0c - 0x14];
    float score;
    char pad2[0x1ba4 - 0x1b10];
    char locked;
};

struct TargetTable {
    Target *FUN_00024280(int a, int b);
};

struct World {
    char pad0[0x20];
    TargetTable *targets;
};

extern World *DAT_004dd700;

struct Key {
    int a, b;
};

struct Clock {
    float FUN_00086080();
};

class Tracker {
public:
    Target *FUN_00066390(Vec3 *pos);

    char pad0[4];
    Clock *clock;
    char pad1[0x154 - 8];
    Vec3 origin;
    char pad2[0x170 - 0x160];
    Key keys[40];
    int count;
    char pad4[0x354 - 0x2b4];
    float result;
};

Target *Tracker::FUN_00066390(Vec3 *pos)
{
    origin = *pos;
    Target *best = 0;
    float bestDist = 0.0f;
    for (int i = 0; i < count; i++) {
        Target *t = DAT_004dd700->targets->FUN_00024280(keys[i].a, keys[i].b);
        Vec3 p;
        t->transform->FUN_00059a50(&p);
        if (t->score < 0.0f) {
            for (int j = i + 1; j < count; j++)
                keys[j - 1] = keys[j];
            count--;
            i--;
        } else {
            Vec3 d;
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
