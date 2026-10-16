// STATUS: equivalent (tools/equiv.py level 3: 3051 inputs, branch coverage 20/20)
// FUN_0003be00 @ 0x0003be00
#include "decls/address.h"
struct Vec3_3be00 {
    float x, y, z;
};

struct Quat_3be00 {
    float x, y, z, w;
    void FUN_0022b220(float a, float b, float c);
    char FUN_000375f0(const Quat_3be00 *other, float eps);
};

void FUN_0022b080(Quat_3be00 *out, const Quat_3be00 *a, const Quat_3be00 *b);

struct Skeleton {
    char pad00[0x100];
    Quat_3be00 qa;
    Quat_3be00 qb;
    Quat_3be00 qc;
};

struct Pose {
    char pad00[0xb0];
    Vec3_3be00 pos;
};

struct Reference {
    char pad00[0x14];
    Skeleton *skeleton;
};

struct Rig_3be00 {
    char pad00[8];
    Reference *ref;
    char padc[4];
    Skeleton *skeleton;
    Pose *pose;
    void FUN_00034d80(int mode, Vec3_3be00 *v);
};

struct Actor_3be00 {
    char pad00[0x64];
    Rig_3be00 *rig;
};

struct Owner_3be00 {
    Actor_3be00 *FUN_00059a40();
};

struct Pad_3be00 {
    char FUN_00092de0(int button);
};

struct Input_3be00 {
    Pad_3be00 *FUN_00086340();
};

struct Holder_3be00 {
    char pad00[0x124];
    void *current;
};

struct World {
    char pad00[0x20];
    Holder_3be00 *holder;
    char pad24[0x54 - 0x24];
    Input_3be00 *input;
};


class Controller_3be00 {
public:
    char pad00[0x10];
    Owner_3be00 *owner;
    char pad14[0x140 - 0x14];
    int state;
    void FUN_0003be00();
};

void Controller_3be00::FUN_0003be00()
{
    World *g = DAT_004dd700;
    if (g->holder->current != this) {
        return;
    }
    Pad_3be00 *pad = g->input->FUN_00086340();
    Rig_3be00 *rig = owner->FUN_00059a40()->rig;
    Reference *ref = rig->ref;
    Quat_3be00 q;
    Quat_3be00 l;
    if (pad->FUN_00092de0(4)) {
        l.FUN_0022b220(0.0f, 0.0f, -0.7853982f);
        q = rig->skeleton->qa;
        FUN_0022b080(&q, &q, &l);
        rig->skeleton->qa = q;

        l.FUN_0022b220(0.0f, 0.0f, -0.7853982f);
        q = rig->skeleton->qb;
        FUN_0022b080(&q, &q, &l);
        rig->skeleton->qb = q;

        q = rig->skeleton->qc;
        l = ref->skeleton->qc;
        if (!q.FUN_000375f0(&l, 1e-05f)) {
            l.FUN_0022b220(0.0f, 0.0f, 1.2217305f);
            FUN_0022b080(&q, &q, &l);
            rig->skeleton->qc = q;
        }
        int s = state;
        if (s <= 0) {
            return;
        }
        if (s > 2) {
            if (s != 4) {
                return;
            }
            Vec3_3be00 v;
            v.x = 0.0f;
            v.y = 1.3125f;
            v.z = -0.6f;
            rig->FUN_00034d80(2, &v);
            return;
        }
        Pose *pose = rig->pose;
        Vec3_3be00 p = pose->pos;
        pose->pos.x = p.x;
        pose->pos.y = p.y - 0.6625f;
        pose->pos.z = p.z;
        return;
    }
    if (pad->FUN_00092de0(3)) {
        l.FUN_0022b220(0.0f, 0.0f, -0.69813174f);
        q = rig->skeleton->qa;
        FUN_0022b080(&q, &q, &l);
        rig->skeleton->qa = q;

        q = rig->skeleton->qc;
        l = ref->skeleton->qc;
        if (!q.FUN_000375f0(&l, 1e-05f)) {
            l.FUN_0022b220(0.0f, 0.0f, 0.5235988f);
            FUN_0022b080(&q, &q, &l);
            rig->skeleton->qc = q;
        }
        int s = state;
        if (s > 0 && s <= 2) {
            Vec3_3be00 p = rig->pose->pos;
            Vec3_3be00 v;
            v.x = p.x;
            v.y = p.y + 0.6375f;
            v.z = p.z;
            rig->FUN_00034d80(2, &v);
        }
    }
}
