// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e54b0 @ 0x001e54b0
struct Id_1e54b0 {
    unsigned int lo, hi;
    void FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};

struct Vec3_1e54b0 {
    float x, y, z;
};

struct Transform_1e54b0 {
    char data[0x3c];
    void FUN_0022b980();
    void FUN_0022be40(const Vec3_1e54b0 *pos);
};

class World {
public:
    void FUN_001e43b0(Id_1e54b0 *a, Id_1e54b0 *b, Transform_1e54b0 *xf, int flag);
    void FUN_001e54b0(const char *nameA, const char *nameB, float x, float y, float z);
};

void World::FUN_001e54b0(const char *nameA, const char *nameB, float x, float y, float z)
{
    // Frame slots follow the original's layout; the position block is dead
    // before the second name is built, so they share a slot.
    struct Frame {
        Id_1e54b0 a;
        union {
            Vec3_1e54b0 pos;
            Id_1e54b0 b;
        } u;
        Transform_1e54b0 xf;
        int pad;
    } f;
    f.xf.FUN_0022b980();
    f.u.pos.x = x;
    f.u.pos.y = y;
    f.u.pos.z = z;
    f.xf.FUN_0022be40(&f.u.pos);
    f.u.b.FUN_0027b0e0(nameB);
    f.a.FUN_0027b0e0(nameA);
    FUN_001e43b0(&f.a, &f.u.b, &f.xf, 0);
    f.a.FUN_0027af50();
    f.u.b.FUN_0027af50();
}
