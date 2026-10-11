// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 11/12, incomplete)
// FUN_001c17d0 @ 0x001c17d0
struct Vec3 {
    float x, y, z;
    float FUN_0022d110() const;
};

struct Collider;

struct Query {
    int kind;
    int f1, f2, f3, f4, f5;
    unsigned char flag;
};

struct Shape {
    char pad0[0x20];
    Collider *collider;
};

struct Body {
    char pad0[0x74];
    Shape *shape;
};

struct Owner {
    Body *FUN_001d72e0();
};

struct Source {
    char pad0[0xa0];
    Owner *owner;
    Owner *FUN_001d72e0();
};

struct Entity {
    char pad0[0x30];
    Vec3 pos;
};

class World {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual Entity *v14();
};

struct Request {
    char pad0[0x1c];
    Source *source;
};

bool FUN_002f15a0(Vec3 *from, Vec3 *delta, Vec3 *hit, float length, Collider *collider, Query *query);

struct Probe {
    char pad0[8];
    World *world;
    char padC[0xf4 - 0xc];
    Vec3 points[2];
    bool FUN_001c17d0(Request *req);
};

bool Probe::FUN_001c17d0(Request *req)
{
    Vec3 dir;
    Vec3 from;
    Vec3 delta;
    Query query;

    if (req->source == 0)
        return false;
    Body *body = (Body *)((Source *)req->source)->FUN_001d72e0();
    if (body == 0)
        return false;
    Shape *shape = body->shape;
    if (shape == 0)
        return false;
    Collider *collider = shape->collider;
    if (collider == 0)
        return false;

    from = world->v14()->pos;
    for (int i = 0; i < 2; i++) {
        dir.x = points[i].x - from.x;
        dir.y = points[i].y - from.y;
        dir.z = points[i].z - from.z;
        delta = dir;
        query.kind = 2;
        query.f1 = 0;
        query.f2 = 0;
        query.f3 = 0;
        query.f4 = 0;
        query.f5 = 0;
        query.flag = 1;
        float length = delta.FUN_0022d110();
        if (FUN_002f15a0(&from, &delta, &dir, length, collider, &query))
            return true;
    }
    return false;
}
