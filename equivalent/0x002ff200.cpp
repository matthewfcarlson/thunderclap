// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 42/46, incomplete)
// FUN_002ff200 @ 0x002ff200
struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Target;

struct Element {
    char pad00[0x20];
    Target *owner;           // 0x20
    char pad24[0x50 - 0x24];
    char f50;
    char pad51[0x72 - 0x51];
    char f72;
};

struct Group {
    Element **begin;         // 0x00
    Element **end;           // 0x04
    char pad08[0x50 - 8];
    char active;             // 0x50
    char pad51[0x6c - 0x51];
};

struct Query {
    char pad00[8];
    Target *target;          // 0x08
};

char __cdecl FUN_002f15a0(V3 *from, V3 *dir, V3 *delta, float len, Target *skip, Query *q);

class Tracer {
public:
    Group *groups;           // 0x00
    int count;               // 0x04

    char FUN_002ff200(Query *q, V3 *from, V3 *to, char flag, int index);
};

char Tracer::FUN_002ff200(Query *q, V3 *from, V3 *to, char flag, int index)
{
    V3 d;
    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    V3 v = d;
    float len = v.FUN_0022d110();
    char hit = 0;

    if (q->target != 0) {
        hit = FUN_002f15a0(from, &v, &d, len, q->target, q);
        if (hit)
            return hit;
    }

    if (index == -1) {
        for (int i = 0; i < count; i++) {
            if (groups[i].active) {
                for (unsigned j = 0; j < (unsigned)(groups[i].end - groups[i].begin); j++) {
                    Element *e = groups[i].begin[j];
                    if (e->f72 && e->owner != q->target && (!flag || e->f50)) {
                        hit = FUN_002f15a0(from, &v, &d, len, e->owner, q);
                        if (hit)
                            break;
                    }
                }
            }
        }
        if (hit)
            return hit;
    } else if (index >= 0 && index < count) {
        for (unsigned j = 0; j < (unsigned)(groups[index].end - groups[index].begin); j++) {
            Element *e = groups[index].begin[j];
            if (e->f72 && e->owner != q->target && (!flag || e->f50)) {
                hit = FUN_002f15a0(from, &v, &d, len, e->owner, q);
                if (hit)
                    return hit;
            }
        }
        if (hit)
            return hit;
    }
    q->target = 0;
    return hit;
}
