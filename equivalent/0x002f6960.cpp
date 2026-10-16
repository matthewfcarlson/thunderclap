// STATUS: equivalent (tools/equiv.py level 3: 102 inputs, branch coverage 21/24, incomplete)
// physics::PhysicsObject::vfunc_5 @ 0x002f6960
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"

struct Vec3_2f6960 {
    float x, y, z;
};

class Part_2f6960;
struct PartList {
    Part_2f6960 **parts;
};

struct Probe_2f6960 {
    char pad0[0x1c];
    float a;                 // 0x1c
    char pad20[8];
    float b;                 // 0x28
    char pad2c[8];
    float c;                 // 0x34
};

class Part_2f6960 {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual int GetKind();           // slot 6
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual Probe_2f6960 *GetProbe();       // slot 15
    char pad4[0x10];
    PartList *list;                  // 0x14
};

struct Rig_2f6960 {
    char pad0[0x20];
    Part_2f6960 *part;                      // 0x20
};

struct Body_2f6960 {
    char pad0[0x50];
    Vec3_2f6960 force;                      // 0x50
    Vec3_2f6960 torque;                     // 0x5c
    char pad68[4];
    int mode;                        // 0x6c
    char pad70[4];
    Rig_2f6960 *rig;                        // 0x74
};

struct Contact_2f6960 {
    char pad0[0x1c];
    char data1c[1];                  // 0x1c
};

struct Solver_2f6960 {
    void FUN_00011160(int a, char *b);
};

class PhysicsObject {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(float dt);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual bool v11();
    virtual bool v12(float dt);
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38(float dt);
    virtual void v39();
    char pad4[0xc];
    Body_2f6960 *body;                      // 0x10
    char pad14[8];
    Contact_2f6960 *contact;                // 0x1c
    char pad20[0x20];
    int param40;                     // 0x40
    char pad44[0xec];
    Solver_2f6960 solver;                   // 0x130
    char pad131[0x1cc - 0x131];
    float accum;                     // 0x1cc
    char pad1d0[0x1ec - 0x1d0];
    int timer;                       // 0x1ec
    char pad1f0;
    unsigned char partIndex;         // 0x1f1
    char pad1f2[2];
    unsigned char flags;             // 0x1f4
};

static float absf(float v)
{
    union { float f; unsigned int u; } x;
    x.f = v;
    x.u &= 0x7fffffff;
    return x.f;
}

void PhysicsObject::vfunc_5(float dt)
{
    if (body->mode != 1)
        return;
    if (v11())
        return;
    if (!(dt > (*(float*)&DAT_003f32e0)))
        return;

    if (contact != 0) {
        if (v12(dt)) {
            bool ok = (flags & 1) != 0;
            if (ok) {
                Part_2f6960 *part = body->rig->part;
                if (partIndex != 0xff) {
                    PartList *list = part->list;
                    if (list != 0)
                        part = list->parts[partIndex];
                }
                ok = (part->GetKind() == 5);
                if (ok) {
                    Probe_2f6960 *p = part->GetProbe();
                    ok = absf(p->a) < DAT_004d2bc8 && absf(p->b) < DAT_004d2bc8 && absf(p->c) < DAT_004d2bc8;
                }
            }
            if (!ok) {
                Vec3_2f6960 *f = &body->force;
                f->z = 0;
                f->y = 0;
                f->x = 0;
                Vec3_2f6960 *t = &body->torque;
                t->z = 0;
                t->y = 0;
                t->x = 0;
                return;
            }
            v13();
        }
        solver.FUN_00011160(param40, contact->data1c);
    }
    v38(dt);
    v37();
    accum = dt + accum;
    timer = 0;
    flags |= 1;
}
