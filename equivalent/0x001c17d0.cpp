// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 11/12, incomplete)
// FUN_001c17d0 @ 0x001c17d0
struct Vec3_1c17d0 {
    float x, y, z;
    float FUN_0022d110() const;
};

struct Collider;

struct Query_1c17d0 {
    int kind;
    int f1, f2, f3, f4, f5;
    unsigned char flag;
};

struct Shape_1c17d0 {
    char pad0[0x20];
    Collider *collider;
};

struct Body_1c17d0 {
    char pad0[0x74];
    Shape_1c17d0 *shape;
};

struct Owner_1c17d0 {
    Body_1c17d0 *FUN_001d72e0();
};

struct Source_1c17d0 {
    char pad0[0xa0];
    Owner_1c17d0 *owner;
    Owner_1c17d0 *FUN_001d72e0();
};

struct Entity {
    char pad0[0x30];
    Vec3_1c17d0 pos;
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
    Source_1c17d0 *source;
};

bool FUN_002f15a0(Vec3_1c17d0 *from, Vec3_1c17d0 *delta, Vec3_1c17d0 *hit, float length, Collider *collider, Query_1c17d0 *query);

struct Probe_1c17d0 {
    char pad0[8];
    World *world;
    char padC[0xf4 - 0xc];
    Vec3_1c17d0 points[2];
    bool FUN_001c17d0(Request *req);
};

bool Probe_1c17d0::FUN_001c17d0(Request *req)
{
    Vec3_1c17d0 dir;
    Vec3_1c17d0 from;
    Vec3_1c17d0 delta;
    Query_1c17d0 query;

    if (req->source == 0)
        return false;
    Body_1c17d0 *body = (Body_1c17d0 *)((Source_1c17d0 *)req->source)->FUN_001d72e0();
    if (body == 0)
        return false;
    Shape_1c17d0 *shape = body->shape;
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
