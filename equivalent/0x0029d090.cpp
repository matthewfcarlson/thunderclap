// STATUS: equivalent (tools/equiv.py level 3: 2668 inputs, branch coverage 35/38, incomplete)
// FUN_0029d090 @ 0x0029d090
struct V3 {
    float x, y, z;
};

struct Light {
    char pad0[0x11];
    unsigned char active;           // 0x11
    char pad12[2];
    unsigned int color;             // 0x14
    V3 pos;                         // 0x18
    char pad24[0x58 - 0x24];
    V3 dir;                         // 0x58
    float FUN_002a0d00(V3 *p);
};

struct LightList {
    char pad0[0x10];
    int limit;                      // 0x10
    int count;                      // 0x14
    Light **items;                  // 0x18
};

struct Record {
    float intensity;                // 0x00
    unsigned int color;             // 0x04
    float radius2;                  // 0x08
    V3 dir;                         // 0x0c
    unsigned int flags;             // 0x18
    char pad1c[4];
};

struct Pool {
    LightList *list;                // 0x00
    Record *records;                // 0x04
};

class Lights {
public:
    char pad0[0x18];
    int active;                     // 0x18
    char pad1c[0x30 - 0x1c];
    Pool *pool;                     // 0x30
    float FUN_0029d090(V3 *pos, unsigned int mask);
};

static int clamp255(int v)
{
    if (v >= 0) {
        if (v > 0xff)
            v = 0xff;
    } else {
        v = 0;
    }
    return v;
}

float Lights::FUN_0029d090(V3 *pos, unsigned int mask)
{
    float total = 0.0f;
    int idx = pool->list->count - 1;
    if (idx < 0)
        return total;

    for (; idx >= 0; --idx) {
        LightList *list = pool->list;
        if (idx >= list->limit || list->items[idx] == 0 || !list->items[idx]->active) {
            pool->records[idx].intensity = 0;
            continue;
        }
        Light *l = list->items[idx];
        Record *r = &pool->records[idx];
        if ((r->flags & mask) != mask) {
            pool->records[idx].intensity = 0;
            continue;
        }

        double dx = (double)pos->x - l->pos.x;
        double dy = (double)pos->y - l->pos.y;
        double dz = (double)pos->z - l->pos.z;
        double dist2 = dz * dz + dy * dy + dx * dx;
        if (dist2 >= r->radius2) {
            r->intensity = 0;
            continue;
        }

        float f = l->FUN_002a0d00(pos);
        unsigned int c = l->color;
        int cr = c & 0xff;
        int cg = (c >> 8) & 0xff;
        int cb = (c >> 16) & 0xff;
        int m = cg;
        if (cg < cr)
            m = cr;
        if (cb >= m)
            m = cb;
        double val = (double)m * f;
        int ir = (int)((double)cr * f);
        int ig = (int)((double)cg * f);
        int ib = (int)((double)cb * f);
        ir = clamp255(ir);
        ig = clamp255(ig);
        ib = clamp255(ib);
        unsigned int out = (((((unsigned int)ib | 0xffffff00u) << 8) | ig) << 8) | ir;
        pool->records[idx].color = out;
        pool->records[idx].intensity = (float)val;
        Record *r2 = &pool->records[idx];
        r2->dir = l->dir;
        if (val >= 0.0)
            ++active;
        total = (float)(val + total);
    }
    return total;
}
