// STATUS: equivalent (tools/equiv.py level 3: 3040 inputs, branch coverage 38/38)
// FUN_0003ba60 @ 0x0003ba60
#include "compat/ptr.h"
#include "decls/data/game/global.h"

struct V3_3ba60 {
    float x, y, z;
};
struct Mat4_3ba60 {
    float m[12];
    V3_3ba60 trans;
    float w;
    void FUN_0022c120();
    void FUN_0022ca90(const Mat4_3ba60* a, const Mat4_3ba60* b);
};
struct Xform_3ba60 {
    char data[0x54];
    void FUN_00221b70(const Mat4_3ba60* m);
    void FUN_00221e60(const Mat4_3ba60* m);
    Mat4_3ba60* FUN_00221c40();
};
struct EventFlags {
    char pad0[0x18];
    char flag18;
};
struct EventMid {
    char pad0[0x20];
    EventFlags* flags;
};
struct Event_3ba60 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Mat4_3ba60* m, int arg);
    char pad04[0x74 - 4];
    EventMid* mid;
    void FUN_002ef8b0(int v);
};
struct Link_3ba60 {
    int FUN_001d5e80(int v);
    unsigned __int64 FUN_001d4f70();
};
struct Effect_3ba60 {
    char pad0[0x20];
    char b20, b21, b22, b23;
    void FUN_002845a0();
};
struct Holder_3ba60 {
    char pad0[0x18];
    Effect_3ba60* effect;
};
struct Bank {
    hulk_intptr FUN_000446c0(int index);
};
struct Prop_3ba60 {
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
    virtual Mat4_3ba60* v15();
    char pad04[0x40 - 4];
    int f40;
    char pad44[0xec - 0x44];
    Link_3ba60* link;
    char padf0[0x11c - 0xf0];
    Holder_3ba60* holder;
    char pad120[0x1ec - 0x120];
    char b1ec;
    char pad1ed[3];
    V3_3ba60 offset;
    Event_3ba60* FUN_001d72e0();
    V3_3ba60* FUN_001d6b40();
    void FUN_001d6b60(Mat4_3ba60 m, int flag);
};
struct Bones_3ba60 {
    char pad0[0x1c];
    char* mats;
};
struct SceneXf {
    char data[0x54];
    Mat4_3ba60* FUN_00221c40();
};
struct Scene_3ba60 {
    char pad0[0x10];
    SceneXf xf;
    Bones_3ba60* bones;
    void FUN_00224260(unsigned int lo, unsigned int hi, Xform_3ba60* x);
};
struct OwnerLink {
    char pad0[0x124];
    void* self;
};
struct Args_3ba60 {
    char pad0[0x20];
    OwnerLink* link;
};
struct Source_3ba60 {
    Prop_3ba60* prop;
    unsigned int bone;
    unsigned int idLo, idHi;
    Mat4_3ba60 mat;
};
struct Holder10_3ba60 {
    Scene_3ba60* FUN_00059a40();
};
class Fighter_3ba60 {
  public:
    char pad0[0x10];
    Holder10_3ba60* holder;
    char pad14[0x11c - 0x14];
    Bank* bank;
    char pad120[0x3a8 - 0x120];
    Source_3ba60 slots[8];
    char pad628[0x22e9 - 0x628];
    char b22e9;
    void FUN_0003acf0(int slot, int a, int b, int c, int d, int e);
    void FUN_0003ba60(Args_3ba60* args, int arg2);
};

void Fighter_3ba60::FUN_0003ba60(Args_3ba60* args, int arg2) {
    OwnerLink* owner = args->link;
    Scene_3ba60* scene = holder->FUN_00059a40();
    if (!b22e9)
        return;

    for (int i = 0; i < 8; ++i) {
        Source_3ba60* source = &slots[i];
        Prop_3ba60* prop = source->prop;
        if (!prop)
            continue;

        if (prop->FUN_001d72e0() && !prop->FUN_001d72e0()->mid->flags->flag18) {
            bool release = true;
            if (bank) {
                Link_3ba60* link = prop->link;
                release = link != (Link_3ba60*)bank->FUN_000446c0(i);
            }
            if (release) {
                FUN_0003acf0(i, 0, -1, 0, 0, 0);
                continue;
            }
        }

        Event_3ba60* event = prop->FUN_001d72e0();
        if (event)
            event->FUN_002ef8b0(0);
        if (prop->link->FUN_001d5e80(prop->f40) == 4) {
            if (prop->link->FUN_001d4f70() == (*(unsigned __int64*)&DAT_004dc0c0) ||
                prop->link->FUN_001d4f70() == (*(unsigned __int64*)&DAT_004dc098)) {
                Effect_3ba60* effect = prop->holder->effect;
                effect->FUN_002845a0();
                effect->b22 = 0;
                effect->b23 = 0;
                effect->b20 = 0;
                effect->b21 = 0;
            }
        }

        if (owner && prop->b1ec && owner->self != (void*)this) {
            V3_3ba60* position = prop->FUN_001d6b40();
            volatile float x = prop->offset.x + position->x;
            volatile float y = prop->offset.y + position->y;
            volatile float z = prop->offset.z + position->z;
            Mat4_3ba60 transform = *prop->v15();
            transform.trans.y = y;
            transform.trans.x = x;
            transform.trans.z = z;
            prop->FUN_001d6b60(transform, 0);
            return;
        }

        Mat4_3ba60 objectTransform = *prop->v15();
        Mat4_3ba60* base;
        if (source->bone != 0xffff)
            base = (Mat4_3ba60*)(scene->bones->mats + (source->bone << 6));
        else
            base = scene->xf.FUN_00221c40();
        Mat4_3ba60 boneTransform = *base;
        Mat4_3ba60 relative;
        if (source->idLo | source->idHi) {
            Mat4_3ba60 adjustedBone = boneTransform;
            adjustedBone.FUN_0022c120();
            Mat4_3ba60 slotTransform = source->mat;
            slotTransform.FUN_0022c120();
            Xform_3ba60 composition;
            composition.FUN_00221b70(&slotTransform);
            composition.FUN_00221e60(&objectTransform);
            composition.FUN_00221e60(&adjustedBone);
            scene->FUN_00224260(source->idLo, source->idHi, &composition);
            relative.FUN_0022ca90(&source->mat, composition.FUN_00221c40());
        } else {
            relative = source->mat;
        }
        objectTransform.FUN_0022ca90(&relative, &boneTransform);
        if (event)
            event->v6(&objectTransform, arg2);
        prop->FUN_001d6b60(objectTransform, 0);
    }
}