// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 30/34, incomplete)
// FUN_00083320 @ 0x00083320
#include "decls/address.h"
struct Vec3_83320 {
    float x, y, z;
    void FUN_00011220(Vec3_83320* delta);
};

// 4x4 transform; the last row is the translation
struct Xform_83320 {
    float rot[12];
    Vec3_83320 pos;
    float w;
};

struct Part_83320 {
    char pad00[0x6c];
    int f6c;
    void FUN_002ef8b0(int a);
};

class Body_83320 {
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
    virtual Xform_83320* GetXform();      // slot 15
    Part_83320* FUN_001d72e0();
    void FUN_001d7510();
    void FUN_001d6b60(Xform_83320 pose, int flag);
};

struct Registry_83320 {
    Body_83320* FUN_001dc0d0(int id);
};

struct World {
    char pad00[0xc];
    Registry_83320* registry;             // 0x0c
};


// equiv-conv: FUN_00082d30 esi
void FUN_00082d30(Xform_83320* pose);

class Mover_83320 {
public:
    void FUN_00083320(Vec3_83320* anchor, Vec3_83320* dir, float scale, char airborne, int unused, char forced);

    char pad00[0x10];
    int id;                         // 0x10
    int state;                      // 0x14
    char pad18[4];
    char b1c;                       // 0x1c
    char pad1d[3];
    float f20;
    float f24;
    int f28;
    Vec3_83320 vel;                       // 0x2c
};

void Mover_83320::FUN_00083320(Vec3_83320* anchor, Vec3_83320* dir, float scale, char airborne, int unused, char forced)
{
    b1c = 1;
    f28 = 0;
    Body_83320* body = DAT_004dd700->registry->FUN_001dc0d0(id);
    Xform_83320 pose = *body->GetXform();

    bool grounded = false;
    if (!forced) {
        union { float f; unsigned int u; } a, b;
        a.f = dir->y;
        a.u &= 0x7fffffff;
        b.f = a.f - 1.0f;
        b.u &= 0x7fffffff;
        if (b.f <= 0.1f) {
            grounded = true;
            if (body->FUN_001d72e0()->f6c == 0)
                pose.pos.y = anchor->y;
        }
    }

    if (!airborne) {
        switch (state) {
        case 2:
            if (!grounded) {
                Vec3_83320 v;
                v.x = -(scale * dir->x);
                v.y = 0.0f;
                v.z = -(scale * dir->z);
                pose.pos.FUN_00011220(&v);
                state = 3;
                f24 = 0.0f;
            }
            break;
        case 3:
            if (!grounded) {
                Vec3_83320 v;
                v.x = -(scale * dir->x);
                v.y = 0.0f;
                v.z = -(scale * dir->z);
                pose.pos.FUN_00011220(&v);
            }
            break;
        case 4:
            if (!grounded && vel.y * dir->y + vel.z * dir->z + dir->x * vel.x < 0.0f) {
                Vec3_83320 v;
                v.x = -(scale * dir->x);
                v.y = 0.0f;
                v.z = -(scale * dir->z);
                pose.pos.FUN_00011220(&v);
                state = 1;
                f24 = 0.0f;
            }
            break;
        case 6:
            if (grounded) {
                if (f24 > f20) {
                    FUN_00082d30(&pose);
                    pose.pos.y = anchor->y;
                    vel.y = 0.0f;
                    body->FUN_001d72e0()->FUN_002ef8b0(0);
                    state = 8;
                    f24 = 0.0f;
                } else {
                    f20 = 2.0f;
                }
            }
            break;
        }
    } else {
        if ((unsigned int)state <= 8 && state != 3 && state != 7) {
            body->FUN_001d7510();
            state = 7;
            f24 = 0.0f;
        }
    }

    if (body->FUN_001d72e0()->f6c == 0)
        body->FUN_001d6b60(pose, 0);
}
