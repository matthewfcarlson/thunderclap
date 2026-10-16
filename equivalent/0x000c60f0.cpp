// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_000c60f0 @ 0x000c60f0
#include "decls/address.h"
struct Vec3_c60f0 {
    float x, y, z;
};

class Resource_c60f0;
class Handle;

class Factory_c60f0 {
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
    virtual Resource_c60f0 *v11(const char *name, int flag);
};

class Resource_c60f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int tag, int flag);
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
    virtual Handle *v30(Resource_c60f0 *r, int count, int a, int b, int c);
    virtual void v31(Handle *h);
};

extern Factory_c60f0 *DAT_0052c2a0;
extern Resource_c60f0 *DAT_004dde68;

void FUN_000c5fa0(Handle *h, Vec3_c60f0 a, Vec3_c60f0 b, unsigned int color);

void FUN_000c60f0(Vec3_c60f0 a, Vec3_c60f0 b, Vec3_c60f0 c, Vec3_c60f0 d, unsigned int color, int count)
{
    if (DAT_004dde68 == 0) {
        DAT_004dde68 = DAT_0052c2a0->v11("simple", 0);
        DAT_004dde68->v0();
        DAT_004dde68->v6(0x444d4c42, 1);
    }
    Handle *h = DAT_0052c2a8->v30(DAT_004dde68, count, 0x2020, 8, 0);
    if (h) {
        FUN_000c5fa0(h, a, b, color);
        FUN_000c5fa0(h, b, d, color);
        FUN_000c5fa0(h, d, c, color);
        FUN_000c5fa0(h, c, a, color);
    }
    DAT_0052c2a8->v31(h);
}
