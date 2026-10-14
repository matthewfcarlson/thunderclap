// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 31/34, incomplete)
// FUN_001fe080 @ 0x001fe080
struct V3_1fe080 {
    float x, y, z;
};

class Elem_1fe080 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual V3_1fe080 *getPos(V3_1fe080 *out);
    char pad04[0x40 - 4];
};

struct Group_1fe080 {
    int count;
    Elem_1fe080 *data;
};

struct Rng_1fe080 {
    int FUN_00011330(int maxValue);
};
Rng_1fe080 *__cdecl FUN_000964d0();

struct Zones {
    int FUN_00204200(float x, float y, float z);
};

struct Holder54_1fe080 {
    Zones *FUN_000862a0();
};

struct Globals_1fe080 {
    char pad[0x54];
    Holder54_1fe080 *holder;        // 0x54
};
extern Globals_1fe080 *DAT_004dd700;

class ElemSet {
public:
    char pad00[0x214];
    Group_1fe080 *groups[6];        // 0x214

    int FUN_001fd360(int zone);
    Elem_1fe080 *FUN_001fe080(float x, float y, float z, int type, int mode, float yMin, float yMax);
};

Elem_1fe080 *ElemSet::FUN_001fe080(float x, float y, float z, int type, int mode, float yMin, float yMax)
{
    if (type < 0 || type >= 6)
        return 0;

    Elem_1fe080 *best = 0;
    float bestDist = 3.4028235e38f;

    if (mode == 2) {
        int zone = DAT_004dd700->holder->FUN_000862a0()->FUN_00204200(x, y, z);
        if (zone == -1)
            return 0;
        int idx = FUN_001fd360(zone);
        if (idx == -1)
            return 0;
        int count = groups[type][idx].count;
        if (count <= 0)
            return 0;
        int pick = FUN_000964d0()->FUN_00011330(count - 1);
        return groups[type][idx].data + pick;
    }

    if (mode == 1)
        bestDist = 1.17549435e-38f;

    for (int gi = 0; gi < 20; gi++) {
        for (int j = 0; j < groups[type][gi].count; j++) {
            Elem_1fe080 *e = groups[type][gi].data + j;
            V3_1fe080 tmp;
            V3_1fe080 q = *e->getPos(&tmp);
            if (q.y < yMin)
                continue;
            if (q.y > yMax)
                continue;
            double dx = (double)x - (double)q.x;
            double dy = (double)y - (double)q.y;
            double dz = (double)z - (double)q.z;
            double total = dz * dz + dx * dx + dy * dy;
            if (mode == 0) {
                if (total < bestDist) {
                    bestDist = (float)total;
                    best = e;
                }
            } else if (mode == 1) {
                if (total > bestDist) {
                    bestDist = (float)total;
                    best = e;
                }
            } else {
                return e;
            }
        }
    }
    return best;
}
