// FUN_0007f560 @ 0x0007f560
#include "decls/data/game/global.h"

struct Vec3_7f560 {
    float x, y, z;
};

struct Emitter_7f560 {
    void FUN_001c5080(float a, float b);
};

struct Obj_7f560 {
    virtual void v0();
    virtual void v1();
    char pad[0xec - 4];
    Emitter_7f560 *emitter;

    void FUN_00080ea0(Vec3_7f560 *a, Vec3_7f560 *b);
    void FUN_00080ef0(int a);
    void FUN_00080f00(int a);
    void FUN_00080f20(int a);
    void FUN_00080e30(Vec3_7f560 *a);
    void FUN_00080f30(int a);
    void FUN_00081b20(int a);
};

struct Cell_7f560 {
    char pad0[0x1c];
    int head;
    char pad1[0x2c - 0x20];
    int total;
    int counts[6];
};

struct Row_7f560 {
    Cell_7f560 cells[14];
};

struct Mgr_7f560 {
    char pad[0x1904];
    Row_7f560 rows[1];

    bool FUN_00078d20(int a2, int a3, int *outA, int *a2slot);
    Obj_7f560 *FUN_0007f310(int a1, int one, int a, int b);
    void FUN_0007afb0(int a2, int a3, int a4, int a5, Vec3_7f560 *c, Vec3_7f560 *b);
    void FUN_00078ee0(Vec3_7f560 *c, Vec3_7f560 *b);
    void FUN_0007b380(Obj_7f560 *o);

    void FUN_0007f560(int a1, int a2, int a3, int a4, int a5);
};

void Mgr_7f560::FUN_0007f560(int a1, int a2, int a3, int a4, int a5)
{
    int la;
    Vec3_7f560 lc;
    Vec3_7f560 lb;

    int a2orig = a2;
    if (!FUN_00078d20(a2orig, a3, &la, &a2))
        return;
    Obj_7f560 *o = FUN_0007f310(a1, 1, la, a2);
    if (o == 0)
        return;
    o->v0();
    o->emitter->FUN_001c5080((*(float*)&DAT_00421898), (*(float*)&DAT_004218c0));
    FUN_0007afb0(a2orig, a3, a4, a5, &lc, &lb);
    FUN_00078ee0(&lc, &lb);
    o->FUN_00080ea0(&lc, &lb);
    o->FUN_00080ef0(rows[a2orig].cells[0].head);
    o->FUN_00080f00(a3);
    o->FUN_00080f20(a4);
    o->FUN_00080e30(&lc);
    o->FUN_00080f30(a5);
    FUN_0007b380(o);
    Cell_7f560 *c = &rows[a2orig].cells[a3];
    c->counts[a4]++;
    c->total++;
    o->FUN_00081b20(0);
    o->v1();
}
