// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 16/16)
// FUN_00287a40 @ 0x00287a40
struct Quat {
    float x, y, z, w;
    void FUN_0022b750(const Quat* a, const Quat* b, float t);
};

struct Vec3 {
    float x, y, z;
};

struct QuatChannel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(float time, Quat* out);
    void FUN_0028a8f0(float prev, float time, Quat* out);
};

struct VecChannel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4(float time, Vec3* out);
    virtual void vfunc_5(float prev, float time, Vec3* out);
};

struct ChannelPair {
    QuatChannel* quat;
    VecChannel* vec;
    float last;
};

struct Record {
    char pad0[0x30];
    Vec3 v30;
    int pad3c;
};

struct Pose {
    char pad0[0x14];
    Quat* quats;
    Record* records;
};

struct PoseSet {
    char pad0[8];
    Pose* pose;
    unsigned int count;
    Quat* quats;
    Record* records;
    char pad18[8];
    char f20;
    char f21;
    char f22;
    char f23;
};

struct BitSet {
    int x0;
    unsigned int words[1];
};

struct Mask {
    char pad0[0x10];
    BitSet* bits;
};

class Blender {
public:
    char pad0[0x110];
    PoseSet* set;
    char pad114[0x131 - 0x114];
    char perItem;
    char pad132[2];
    float* items;
    char pad138[0x148 - 0x138];
    int selected;
    Mask* mask;
    void FUN_00287a40(int unused, float v, float t, ChannelPair* pairs);
};

void Blender::FUN_00287a40(int unused, float v, float t, ChannelPair* pairs)
{
    t = 1.0f - t;
    PoseSet* s0 = set;
    Pose* base = s0->pose;
    unsigned int n = s0->count;
    BitSet* bits = mask->bits;

    for (unsigned int i = 0; i < n; i++) {
        if (!(bits->words[i >> 5] & (1u << (i & 0x1f))))
            continue;
        if (perItem)
            v = items[i];

        Quat qa;
        Vec3 vb;
        if (pairs[i].quat != 0) {
            if (selected != (int)i)
                pairs[i].quat->vfunc_5(v, &qa);
            else
                pairs[i].quat->FUN_0028a8f0(pairs[i].last, v, &qa);
        } else {
            qa = base->quats[i];
        }
        qa.FUN_0022b750(&qa, &set->quats[i], t);

        if (pairs[i].vec != 0) {
            if (selected == (int)i)
                pairs[i].vec->vfunc_5(pairs[i].last, v, &vb);
            else
                pairs[i].vec->vfunc_4(v, &vb);
            Vec3* r = &set->records[i].v30;
            vb.x = (r->x - vb.x) * t + vb.x;
            vb.y = (r->y - vb.y) * t + vb.y;
            vb.z = (r->z - vb.z) * t + vb.z;
        } else {
            vb = base->records[i].v30;
        }

        pairs[i].last = v;
        set->quats[i] = qa;
        set->records[i].v30 = vb;
    }
    PoseSet* done = set;
    done->f22 = 1;
    done->f23 = 1;
    done->f20 = 0;
    done->f21 = 1;
}
