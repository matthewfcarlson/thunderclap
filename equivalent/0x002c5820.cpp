// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002c5820 @ 0x002c5820
#include "decls/address.h"
struct Vec3_2c5820 {
    float x, y, z;
};

struct Prim_2c5820 {
    char pad0[8];
    Vec3_2c5820 *pos;
    char pad0c[4];
    int *tag;
    void FUN_0008ef00();
};

class Gfx {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual Prim_2c5820 *Begin(int shape, int a, int flags, int b, int c);
    virtual void End(Prim_2c5820 *p);
};


class CubeDrawer {
public:
    int f0;
    int f4;
    void FUN_002c5820(Vec3_2c5820 *c, float s);
};

void CubeDrawer::FUN_002c5820(Vec3_2c5820 *c, float s)
{
    Prim_2c5820 *p = DAT_0052c2a8->Begin(f0, 2, 0x2020, 6, 0);
    Vec3_2c5820 t;

    *p->tag = f4;
    t = *c;
    p->pos->x = t.x - s;
    p->pos->y = t.y;
    p->pos->z = t.z;
    p->FUN_0008ef00();

    *p->tag = f4;
    t = *c;
    p->pos->x = s + t.x;
    p->pos->y = t.y;
    p->pos->z = t.z;
    p->FUN_0008ef00();

    *p->tag = f4;
    t = *c;
    p->pos->x = t.x;
    p->pos->y = t.y - s;
    p->pos->z = t.z;
    p->FUN_0008ef00();

    *p->tag = f4;
    t = *c;
    p->pos->x = t.x;
    p->pos->y = s + t.y;
    p->pos->z = t.z;
    p->FUN_0008ef00();

    *p->tag = f4;
    t = *c;
    p->pos->x = t.x;
    p->pos->y = t.y;
    p->pos->z = t.z - s;
    p->FUN_0008ef00();

    *p->tag = f4;
    t = *c;
    p->pos->x = t.x;
    p->pos->y = t.y;
    p->pos->z = s + t.z;
    p->FUN_0008ef00();

    DAT_0052c2a8->End(p);
}
