// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 13/14, incomplete)
// FUN_002b4b40 @ 0x002b4b40
#include "decls/data/game/global.h"

struct Vec3_2b4b40 {
    float x, y, z;
    void FUN_0022c3b0(const Vec3_2b4b40*, Vec3_2b4b40*);
    void FUN_0022d180();
};

struct Vec4_2b4b40 { float x, y, z, w; };

class Probe_2b4b40 {
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
    virtual Vec3_2b4b40 *Direction();
    virtual void v14();
    virtual void v15();
    virtual bool Step(Vec4_2b4b40 *pos, float w);
};

struct Space_2b4b40 {
    char pad0[0x18];
    Probe_2b4b40 *probe;
    void FUN_002940d0(const Vec3_2b4b40 *in, Vec3_2b4b40 *out);
};

struct Root_2b4b40 {
    char pad0[8];
    Space_2b4b40 *space;
};

struct Globals_2b4b40 {
    Root_2b4b40 *root;
};

struct Node {
    char pad0[0x1c];
    char *data;
};

class Tracer_2b4b40 {
public:
    char pad0[0x2c];
    Vec4_2b4b40 origin;
    char pad3c[0x4c - 0x3c];
    float result;
    float override;
    char useOffset;
    char pad55[0x64 - 0x55];
    Vec3_2b4b40 point;
    void FUN_002b4b40(Node *node);
};

struct Frame_2b4b40 {
    Vec3_2b4b40 dir;
    Vec3_2b4b40 tmp;
    Vec4_2b4b40 pos;
};

void Tracer_2b4b40::FUN_002b4b40(Node *node)
{
    if (override != 0.0f) {
        result = override;
        return;
    }
    if (result != 0.0f || node == 0)
        return;

    Space_2b4b40 *space = (*(Globals_2b4b40**)&DAT_0052c2b0)->root->space;
    Probe_2b4b40 *probe = space->probe;
    Frame_2b4b40 f;
    f.pos = origin;
    const Vec3_2b4b40 *shift = (const Vec3_2b4b40 *)(node->data + 0x30);
    f.pos.x = f.pos.x + shift->x;
    f.pos.y = f.pos.y + shift->y;
    f.pos.z = f.pos.z + shift->z;
    space->FUN_002940d0((Vec3_2b4b40 *)&f.pos, (Vec3_2b4b40 *)&f.pos);
    if (!useOffset) {
        probe->Direction()->FUN_0022c3b0(&point, &f.dir);
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
