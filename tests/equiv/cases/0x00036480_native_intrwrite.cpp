// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 16/16)
// FUN_00036480 @ 0x00036480
#include "compat/ptr.h"
struct Vec3_36480 { float x, y, z; };

struct Mat_36480 {
    float m[16];
};

struct Xform_36480 {
    char pad0[4];
    const Mat_36480 *FUN_00221c40();
};

struct Body_36480 {
    char pad0[0x10];
    Xform_36480 xform;
};

struct Fighter_36480 { char pad[4]; };
Body_36480 *__fastcall FUN_00059a40(Fighter_36480 *f);

class Drawable;

struct Holder_36480 {
    char pad0[0x20];
    Drawable *target;
};

class Drawable {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Draw(const Mat_36480 *m, int arg);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad04[0x74 - 4];
    Holder_36480 *holder;
};

struct Props_36480 {
    char pad0[0x30];
    float f30;
    float f34;
};

class Overlay {
public:
    char pad0[1];
    Drawable *FUN_001d72e0();
    void FUN_001d6b60(Mat_36480 m, int flag);
};

class Actor_36480 {
public:
    char pad0[0x10];
    Fighter_36480 *fighter;
    char pad14[0x11c - 0x14];
    Props_36480 *props;
    char pad120[0x128 - 0x120];
    Overlay *overlay;
    Drawable *shadow;
    Drawable *shape;
    char pad134[0x140 - 0x134];
    int mode;
    char pad144[0x22e0 - 0x144];
    char overlayEnabled;
    void FUN_00035550(Vec3_36480 *out);
    void FUN_00036480(int unused, int arg);
};

struct Frame_36480 {
    Vec3_36480 offset;
    Mat_36480 shadowMat;
    Mat_36480 bodyMat;
};

void Actor_36480::FUN_00036480(int unused, int arg)
{
    Frame_36480 f;
    FUN_00059a40(fighter);
    Body_36480 *body = FUN_00059a40(fighter);
    if (body != 0)
        f.bodyMat = *body->xform.FUN_00221c40();
    if (shadow != 0) {
        f.shadowMat = f.bodyMat;
        if (mode == 4) {
            FUN_00035550(&f.offset);
            hulk_freg k = props->f34 * -1.1f;
            f.offset.y = f.offset.y * k;
            f.offset.z = f.offset.z * k;
            f.shadowMat.m[12] = f.shadowMat.m[12] + f.offset.x * k;
            f.shadowMat.m[13] = f.shadowMat.m[13] + f.offset.y;
            f.shadowMat.m[14] = f.shadowMat.m[14] + f.offset.z;
            f.shadowMat.m[13] = f.shadowMat.m[13] - props->f30 * 0.5f;
        } else if (mode == 3) {
            f.shadowMat.m[13] = f.shadowMat.m[13] - props->f30 * 0.5f;
        }
        shadow->Draw(&f.shadowMat, arg);
    }
    if (shape != 0)
        shape->Draw(&f.bodyMat, arg);
    if (overlay != 0 && overlayEnabled != 0) {
        Drawable *d = overlay->FUN_001d72e0();
        if (d != 0) {
            d->Draw(&f.bodyMat, 0);
            d->holder->target->v10();
        }
        overlay->FUN_001d6b60(f.bodyMat, 0);
    }
}
