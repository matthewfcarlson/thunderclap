// STATUS: equivalent (tools/equiv.py level 3: 32 inputs, branch coverage 18/22, incomplete)
// FUN_00300780 @ 0x00300780
struct Vec3_300780 {
    float x, y, z;
};

struct Edge_300780 {
    void *a;
    void *b;
    int c;
    int d;
    char e;
    char pad11[3];
    Edge_300780 *FUN_002f8ef0(void *first, void *second);
};

struct Body_300780 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Vec3_300780 *vfunc_3();
    char pad04[0x28 - 4];
    Vec3_300780 half;
};

struct Item_300780 {
    char pad00[0x20];
    Body_300780 *body;
};

struct Group_300780 {
    Item_300780 **begin;
    Item_300780 **end;
    char pad08[0x30 - 8];
    Edge_300780 *edgeBegin;
    Edge_300780 *edgeEnd;
    Edge_300780 *edgeCap;
};

struct Box_300780 {
    Vec3_300780 lo;
    Vec3_300780 hi;
};

struct GridPart {
    char pad00[0x2024];
    Box_300780 *boxes;
    short *links;
    short *heads;
    char pad2030[4];
    unsigned flags;
    void FUN_00312db0(int n);
    int FUN_00313450(int n);
};

class Broadphase_300780 {
public:
    Group_300780 *group;
    char pad04[0x168 - 4];
    GridPart grid;
    void FUN_003006e0(int arg);
    void FUN_002ff1b0(int arg);
    void FUN_00300780(int arg);
};

void Broadphase_300780::FUN_00300780(int arg)
{
    if (grid.flags & 8) {
        Group_300780 *g = group;
        g->edgeEnd = g->edgeBegin;
        int count = g->end - g->begin;
        grid.FUN_00312db0(count);
        Box_300780 *boxes = grid.boxes;
        for (int i = 0; i < count; i++) {
            Body_300780 *body = g->begin[i]->body;
            Vec3_300780 *c = body->vfunc_3();
            boxes[i].lo.x = c->x - body->half.x;
            boxes[i].lo.y = c->y - body->half.y;
            boxes[i].lo.z = c->z - body->half.z;
            boxes[i].hi.x = body->half.x + c->x;
            boxes[i].hi.y = c->y + body->half.y;
            boxes[i].hi.z = c->z + body->half.z;
        }
        int n = grid.FUN_00313450(count);
        short *links = grid.links;
        short *heads = grid.heads;
        for (int i = 0; i < n; i++) {
            short bx = heads[i];
            if (bx == -1)
                continue;
            do {
                int a = bx;
                unsigned short ax = links[a];
                while (ax != 0xffff) {
                    int b = (short)ax;
                    Edge_300780 tmp;
                    Edge_300780 *e = tmp.FUN_002f8ef0(g->begin[a], g->begin[b]);
                    Edge_300780 *end = g->edgeEnd;
                    if (end < g->edgeCap) {
                        g->edgeEnd = end + 1;
                        if (end)
                            *end = *e;
                    }
                    ax = links[b];
                }
                bx = links[a];
            } while (bx != -1);
        }
    }
    FUN_003006e0(arg);
    FUN_002ff1b0(arg);
}
