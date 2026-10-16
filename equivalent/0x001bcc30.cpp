// STATUS: equivalent (tools/equiv.py level 3: 104 inputs, branch coverage 29/30, incomplete)
// FUN_001bcc30 @ 0x001bcc30
#include "decls/address.h"
struct V3_1bcc30 {
    float x, y, z;
};

struct V4_1bcc30 {
    float v[4];
};

struct Sub;

struct Target_1bcc30 {
    char pad0[0x20];
    Sub *sub;
};

struct Names_1bcc30 {
    int FUN_0027b200(__int64 key);
};

struct Node;

struct Link_1bcc30 {
    Node *FUN_001d72e0();
};

struct Node {
    char pad0[0x74];
    Target_1bcc30 *target;
};

struct Ctl_1bcc30 {
    char pad0[8];
    struct Child_1bcc30 *child;
    int mode;
    char pad10[0x74 - 0x10];
    Target_1bcc30 *target;
};

struct Child_1bcc30 {
    char pad0[0x40];
    int handle;
    char pad44[0x120 - 0x44];
    struct Skel_1bcc30 *skel;
    char pad124[4];
    Link_1bcc30 *link;
};

struct Skel_1bcc30 {
    char pad0[8];
    Names_1bcc30 *names;
    char pad0c[0x1c - 0x0c];
    char *joints;
};

struct Hero_1bcc30 {
    char pad0[0x328];
    Ctl_1bcc30 *ctl;
};

struct Scene_1bcc30 {
    char pad0[0x124];
    Hero_1bcc30 *hero;
    char pad128[0x350 - 0x128];
    bool active;
};

struct World {
    char pad0[0x20];
    Scene_1bcc30 *scene;
};

struct Cursor_1bcc30 {
    void FUN_001c19a0();
};

struct Holder2_1bcc30 {
    char pad0[0x10];
    Sub *sub10;
};

extern unsigned int DAT_004e22d0;
extern __int64 DAT_004e22a0;
extern __int64 DAT_004e22a8;
extern __int64 DAT_004e22b0;
extern __int64 DAT_004e22b8;
extern __int64 DAT_004e22c0;
extern __int64 DAT_004e22c8;

Cursor_1bcc30 **FUN_001c3d90();
// equiv-conv: FUN_001bc530 esi stack
void FUN_001bc530(V4_1bcc30 *q, V3_1bcc30 *v);
void FUN_001bc8a0(Sub *sub, V4_1bcc30 *q);
void FUN_00096a90(Ctl_1bcc30 *ctl, V3_1bcc30 *out);
Holder2_1bcc30 *__stdcall FUN_001d75c0(int handle);

class Rig_1bcc30 {
public:
    char pad0[0x1c];
    V4_1bcc30 quat;
    void FUN_001bcc30();
};

struct Frame_1bcc30 {
    Target_1bcc30 *target;
    Ctl_1bcc30 *ctl;
    Rig_1bcc30 *self;
    V3_1bcc30 a;
    V3_1bcc30 b;
    V4_1bcc30 q;
};

void Rig_1bcc30::FUN_001bcc30()
{
    Frame_1bcc30 f;
    Scene_1bcc30 *scene = DAT_004dd700->scene;
    f.self = this;
    (*FUN_001c3d90())->FUN_001c19a0();
    if (!scene->active)
        return;
    Hero_1bcc30 *hero = scene->hero;
    if (hero == 0)
        return;
    f.ctl = hero->ctl;
    if (f.ctl == 0)
        return;
    f.target = f.ctl->target;
    f.q.v[0] = 1.0f;
    f.q.v[2] = -1.0f;
    f.q.v[1] = -1.0f;
    f.q.v[3] = 1.0f;
    if (f.ctl->mode == 1) {
        Child_1bcc30 *child = f.ctl->child;
        if (child != 0) {
            if (child->link != 0) {
                Node *n = child->link->FUN_001d72e0();
                if (n != 0)
                    f.target = n->target;
            } else if (child->skel != 0) {
                Skel_1bcc30 *skel = child->skel;
                Names_1bcc30 *names = skel->names;
                if (!(DAT_004e22d0 & 1)) {
                    DAT_004e22d0 |= 1;
                    DAT_004e22a0 = FUN_002672f0("Motion_Root", 0, 0);
                    DAT_004e22a8 = FUN_002672f0("Neck", 0, 0);
                    DAT_004e22b0 = FUN_002672f0("Wrist_R", 0, 0);
                    DAT_004e22b8 = FUN_002672f0("Wrist_L", 0, 0);
                    DAT_004e22c0 = FUN_002672f0("Ankle_R", 0, 0);
                    DAT_004e22c8 = FUN_002672f0("Ankle_L", 0, 0);
                }
                __int64 *p = &DAT_004e22a0;
                do {
                    int idx = names->FUN_0027b200(*p);
                    if (idx != 0xffff) {
                        const V3_1bcc30 *src = (const V3_1bcc30 *)(skel->joints + idx * 64 + 0x30);
                        f.b = *src;
                        FUN_001bc530(&f.q, &f.b);
                    }
                    p++;
                } while (p < (__int64 *)&DAT_004e22d0);
            }
        }
    } else if (f.ctl->mode == 5) {
        Child_1bcc30 *child = f.ctl->child;
        if (child != 0) {
            Holder2_1bcc30 *h = FUN_001d75c0(child->handle);
            if (h != 0)
                FUN_001bc8a0(h->sub10, &f.q);
        }
    }
    if (f.target != 0)
        FUN_001bc8a0(f.target->sub, &f.q);
    f.a.x = 0;
    f.a.y = 0;
    f.a.z = 0;
    FUN_00096a90(f.ctl, &f.a);
    FUN_001bc530(&f.q, &f.a);
    quat = f.q;
}
