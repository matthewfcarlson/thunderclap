// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 23/26, incomplete)
// FUN_001adeb0 @ 0x001adeb0
extern float DAT_003f32e0;
extern "C" double sqrt(double);

struct Vec3_1adeb0 {
    float x, y, z;
};

struct Node {
    int ids[3];                      // 0x00 (slots 1 and 2 are the neighbours)
    unsigned char level[3];          // 0x0c (bytes 1 and 2 used)
    unsigned char kind;              // 0x0f
};

struct Mgr_1adeb0 {
    Node *FUN_001b5800(int id);
    Vec3_1adeb0 *FUN_001b5a20(Vec3_1adeb0 *out, int id);
    char FUN_001b65f0(int id, int slot);
};

struct Frame_1adeb0 {
    Node *node;
    float best;
    int bestId;
    Mgr_1adeb0 *mgr;
    Vec3_1adeb0 tmp;
};

struct Finder_1adeb0 {
    Mgr_1adeb0 *mgr;                        // 0x00
    unsigned minLevel;               // 0x04
    unsigned maxKind;                // 0x08

    int FUN_001adeb0(Vec3_1adeb0 *pos, int id, char recurse, int unused);
};

int Finder_1adeb0::FUN_001adeb0(Vec3_1adeb0 *pos, int id, char recurse, int unused)
{
    Frame_1adeb0 f;
    f.node = mgr->FUN_001b5800(id);
    f.bestId = 0;
    f.best = 0;
    if (f.node == 0)
        return 0;
    f.mgr = mgr;

    Vec3_1adeb0 *p = f.mgr->FUN_001b5a20(&f.tmp, id);
    float dx = p->x - pos->x;
    float dy = p->y - pos->y;
    float dz = p->z - pos->z;
    float base = (float)sqrt((double)(dz * dz + dy * dy + dx * dx));

    for (int slot = 1; slot < 3; slot++) {
        int cid = f.node->ids[slot];
        if (cid == -1) {
            if (!mgr->FUN_001b65f0(id, slot))
                continue;
            cid = f.node->ids[slot];
            if (cid == -1)
                continue;
        }
        Node *child = mgr->FUN_001b5800(cid);
        if (child == 0) {
            f.node->ids[slot] = -1;
            continue;
        }
        if (child->kind > maxKind)
            continue;
        if (f.node->level[slot] < minLevel)
            continue;

        Vec3_1adeb0 *q = f.mgr->FUN_001b5a20(&f.tmp, cid);
        float ex = q->x - pos->x;
        float ey = q->y - pos->y;
        float ez = q->z - pos->z;
        double d = sqrt((double)(ez * ez + ey * ey + ex * ex));
        if (!(base > d)) {
            if (f.best == DAT_003f32e0 || d > f.best) {
                f.best = (float)d;
                f.bestId = cid;
            }
        }
    }

    if (recurse) {
        int r = FUN_001adeb0(pos, f.bestId, 0, 1);
        if (r != 0)
            return r;
    }
    return f.bestId;
}
