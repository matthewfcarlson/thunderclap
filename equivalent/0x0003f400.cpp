// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 18/18)
// FUN_0003f400 @ 0x0003f400
#include "decls/address.h"
struct Vec3_3f400 {
    float x, y, z;
    void FUN_00011160(float amount, Vec3_3f400* dir);
};

struct Xform_3f400 {
    struct Matrix* FUN_00221c40();
};

struct Matrix {
    float m[16];
    Matrix() {}
    void FUN_0022b980();
};

// a matrix with extra transform state: 0x54 bytes
struct Pose {
    Matrix matrix;
    char extra[0x14];
    Pose() {}
    void FUN_00221b30(Xform_3f400* src);
    void FUN_0022be40(Vec3_3f400* pos);
};

struct Placement_3f400 {
    void FUN_00221be0(Pose* m);
};

struct Holder_3f400 {
    char pad00[0x10];
    Xform_3f400 xform;
};

struct Owner_3f400 {
    Holder_3f400* FUN_00059a40();
};

struct Rig_3f400 {
    float pad00[12];
    float f30;
    float f34;
};

struct Camera {
    void FUN_001c5e40(Matrix* m);
    void FUN_001c5e80(Vec3_3f400* pos);
    void FUN_001c5ed0(Vec3_3f400* v);
    void FUN_001c5ef0(bool flag);
};

struct Listener_3f400 {
    void FUN_001d7810(Vec3_3f400 pos);
};

struct Manager_3f400 {
    void FUN_00099aa0(void* who);
};

struct World {
    char pad00[8];
    Manager_3f400* manager;
};


class Controller_3f400 {
public:
    bool FUN_0003f400(Vec3_3f400* p);

    bool FUN_00035250(Vec3_3f400* p);
    void FUN_00035550(Vec3_3f400* out);
    void FUN_00038c40();

    char pad00[0x10];
    Owner_3f400* owner;           // 0x10
    Placement_3f400 placement;    // 0x14
    char pad15[0x44 - 0x15];
    Vec3_3f400 pos;               // 0x44
    char pad50[0x68 - 0x50];
    Vec3_3f400 focus;             // 0x68
    char pad74[0x11c - 0x74];
    Rig_3f400* rig;               // 0x11c
    char pad120[4];
    Camera* camera;         // 0x124
    Listener_3f400* listener;     // 0x128
    char pad12c[0x140 - 0x12c];
    int mode;               // 0x140
    int f144;
    char pad148[0x1a38 - 0x148];
    char b1a38;
    char b1a39;
    char pad1a3a[0x1a48 - 0x1a3a];
    Vec3_3f400 v1a48;
    Vec3_3f400 v1a54;
    Vec3_3f400 v1a60;
    float f1a6c;
    float f1a70;
    float f1a74;
    float f1a78;
    float f1a7c;
    float f1a80;
    Vec3_3f400 v1a84;
};

bool Controller_3f400::FUN_0003f400(Vec3_3f400* p)
{
    if (!FUN_00035250(p))
        return false;

    Pose m;
    m.FUN_00221b30(&owner->FUN_00059a40()->xform);
    m.FUN_0022be40(p);
    placement.FUN_00221be0(&m);

    focus = pos;
    if (rig) {
        if (mode == 1 || mode == 2) {
            focus.y = rig->f30 * 0.5f + focus.y;
        } else if (mode == 4) {
            Vec3_3f400 v;
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = 0.0f;
            FUN_00035550(&v);
            focus.FUN_00011160(-rig->f34, &v);
        }
    }
    FUN_00038c40();

    b1a38 = 1;
    b1a39 = 1;
    v1a48 = *p;
    v1a54 = *p;
    v1a60 = *p;
    f1a6c = 0.0f;
    f1a74 = 0.0f;
    f1a70 = 1.0f;
    f1a78 = 0.0f;
    f1a7c = 1.0f;
    f1a80 = 0.0f;
    v1a84 = *p;

    f144 = 1;
    if (camera) {
        Matrix n;
        n.FUN_0022b980();
        Holder_3f400* h = owner->FUN_00059a40();
        if (h)
            n = *h->xform.FUN_00221c40();
        camera->FUN_001c5e40(&n);
        camera->FUN_001c5e80((Vec3_3f400*)&n.m[12]);
        camera->FUN_001c5ed0(&v1a84);
        camera->FUN_001c5ef0(mode == 3);
    }
    if (listener)
        listener->FUN_001d7810(*p);
    DAT_004dd700->manager->FUN_00099aa0(this);
    return true;
}
