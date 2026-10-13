// STATUS: equivalent (tools/equiv.py level 3: 126 inputs, branch coverage 29/30, incomplete)
// pure3d::BillboardQuadGroupAnimationController::vfunc_7 @ 0x002a9920
struct Vec3 { float x, y, z; };

union Scalar {
    float f;
    int i;
    unsigned int u;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void sampleVec3(float frame, Vec3 *out);
    virtual void sampleRot(float frame, Vec3 *out);
    void FUN_0028ac90(float frame, unsigned char *out);
    void FUN_0028a1c0(float frame, Scalar *out);
    void FUN_0028ad20(float frame, int *out);
    void FUN_0028a0b0(float frame, unsigned int *out);
    void FUN_0028a2c0(float frame, int *out);
};

struct ChannelSet {
    Channel *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

struct Transform {
    void FUN_0022be40(Vec3 *v);
    void FUN_0022ba20(Vec3 *v);
};

struct Billboard {
    char pad00[8];
    int key0;
    int key1;
    char pad10[0x28];
    unsigned char visible;
    char pad39[3];
    int color;
    Transform xform;
    char pad41[0x80 - 0x40 - sizeof(Transform)];
    float width;
    float height;
    Scalar dist;
    char pad8c[0xb8 - 0x8c];
    int off0;
    int off1;
    unsigned int limit;
    unsigned int cur;
};

struct ItemList {
    char pad[0x8c];
    Billboard **begin;
    Billboard **end;
};

struct Resolver {
    ChannelSet *FUN_00288ad0(int key0, int key1);
};

class BillboardQuadGroupAnimationController {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void vfunc_7();
    char pad04[0x34 - 4];
    float time;
    char pad38[4];
    Resolver *resolver;
    ItemList *list;
};

void BillboardQuadGroupAnimationController::vfunc_7()
{
    struct Frame {
        char pad[3];
        unsigned char b;
        Scalar a;
        float f2;
        int i3;
        int i4;
        unsigned int u5;
        int pair[2];
        Vec3 v1;
        Vec3 v2;
        int xpad[8];
    } fr;
    unsigned int i;

    for (i = 0; i < (unsigned int)(list->end - list->begin); i++) {
        if (i >= (unsigned int)(list->end - list->begin))
            continue;
        Billboard *item = list->begin[i];
        if (item == 0)
            continue;
        ChannelSet *cs = resolver->FUN_00288ad0(item->key0, item->key1);
        if (cs == 0)
            continue;

        Channel *c = cs->FUN_00288960(0x534956, 0x4c4f4f42);
        if (c != 0) {
            c->FUN_0028ac90(time, &fr.b);
            item->visible = fr.b;
        }
        c = cs->FUN_00288960(0x4e415254, 0x54434556);
        if (c != 0) {
            c->sampleVec3(time, &fr.v1);
            item->xform.FUN_0022be40(&fr.v1);
        }
        c = cs->FUN_00288960(0x544f52, 0x544f52);
        if (c != 0) {
            c->sampleRot(time, &fr.v2);
            item->xform.FUN_0022ba20(&fr.v2);
        }
        c = cs->FUN_00288960(0x544457, 0x31544c46);
        if (c != 0) {
            c->FUN_0028a1c0(time, &fr.a);
            item->width = fr.a.f * 0.5f;
        }
        c = cs->FUN_00288960(0x544748, 0x31544c46);
        if (c != 0) {
            c->FUN_0028a1c0(time, (Scalar *)&fr.f2);
            item->height = fr.f2 * 0.5f;
        }
        c = cs->FUN_00288960(0x54534944, 0x31544c46);
        if (c != 0) {
            c->FUN_0028a1c0(time, (Scalar *)&fr.i3);
            item->dist.i = fr.i3;
        }
        c = cs->FUN_00288960(0x524c43, 0x524c43);
        if (c != 0) {
            c->FUN_0028ad20(time, &fr.i4);
            item->color = fr.i4;
        }
        c = cs->FUN_00288960(0x465346, 0x544e49);
        if (c != 0) {
            c->FUN_0028a0b0(time, &fr.u5);
            unsigned int lim = item->cur;
            if (fr.u5 <= lim)
                lim = fr.u5;
            item->limit = lim;
        }
        c = cs->FUN_00288960(0x46464f, 0x32544c46);
        if (c != 0) {
            c->FUN_0028a2c0(time, fr.pair);
            item->off0 = fr.pair[0];
            item->off1 = fr.pair[1];
        }
    }
}
