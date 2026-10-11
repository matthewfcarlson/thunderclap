// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/14, incomplete)
// FUN_002b4b40 @ 0x002b4b40
struct Vec3 {
    float x, y, z;
    void FUN_0022c3b0();
    void FUN_0022d180();
};

struct Vec4 { float x, y, z, w; };

class Probe {
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
    virtual Vec3 *Direction(const Vec3 *point, Vec3 *out);
    virtual void v14();
    virtual void v15();
    virtual bool Step(Vec4 *pos, float w);
};

struct Space {
    char pad0[0x18];
    Probe *probe;
    void FUN_002940d0(const Vec3 *in, Vec3 *out);
};

struct Root {
    char pad0[8];
    Space *space;
};

struct Globals {
    Root *root;
};
extern Globals *DAT_0052c2b0;

struct Node {
    char pad0[0x1c];
    char *data;
};

class Tracer {
public:
    char pad0[0x2c];
    Vec4 origin;
    char pad3c[0x4c - 0x3c];
    float result;
    float override;
    char useOffset;
    char pad55[0x64 - 0x55];
    Vec3 point;
    void FUN_002b4b40(Node *node);
};

struct Frame {
    Vec3 dir;
    Vec3 tmp;
    Vec4 pos;
};

void Tracer::FUN_002b4b40(Node *node)
{
    if (override != 0.0f) {
        result = override;
        return;
    }
    if (result != 0.0f || node == 0)
        return;

    Space *space = DAT_0052c2b0->root->space;
    Probe *probe = space->probe;
    Frame f;
    f.pos = origin;
    const Vec3 *shift = (const Vec3 *)(node->data + 0x30);
    f.pos.x = f.pos.x + shift->x;
    f.pos.y = f.pos.y + shift->y;
    f.pos.z = f.pos.z + shift->z;
    space->FUN_002940d0((Vec3 *)&f.pos, (Vec3 *)&f.pos);
    if (!useOffset) {
        probe->Direction(&point, &f.dir)->FUN_0022c3b0();
    } else {
        space->FUN_002940d0(&point, &f.tmp);
        f.dir.x = f.pos.x - f.tmp.x;
        f.dir.y = f.pos.y - f.tmp.y;
        f.dir.z = f.pos.z - f.tmp.z;
        f.dir.FUN_0022d180();
    }
    unsigned int n = 1;
    do {
        float w = f.pos.w;
        f.pos.x = f.dir.x + f.pos.x;
        f.pos.y = f.dir.y + f.pos.y;
        f.pos.z = f.dir.z + f.pos.z;
        if (!probe->Step(&f.pos, w))
            break;
        n++;
    } while (n < 100);
    result = (float)n;
}
