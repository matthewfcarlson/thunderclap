// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 26/26)
// choreo2::LocomotionStrafeDriver::vfunc_10 @ 0x00226b40
struct Quat_226b40 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_226b40 *a, const Quat_226b40 *b, float t);
    void FUN_0022b1c0(float angle);
};

struct Vec3_226b40 {
    float x, y, z;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(float frame, Vec3_226b40 *out);
    virtual void vf5(float frame, Quat_226b40 *out);
};

class ChannelSet;

class Pose {
public:
    char pad0[0x30];
    Vec3_226b40 position;
    Quat_226b40 *FUN_00221cd0();
    void FUN_00221cf0(Quat_226b40 *q);
    void FUN_0022be40(Vec3_226b40 *v);
};

struct Base_226b40 {
    char pad0[0x30];
    Vec3_226b40 v;
};

struct Rig_226b40 {
    char pad0[0x10];
    Quat_226b40 *quats;            // 0x10
    char *mats;             // 0x14 stride 0x40, position at +0x30
};

struct Rest_226b40 {
    char pad0[0x14];
    Quat_226b40 *quats;            // 0x14
    char *mats;             // 0x18
};

struct Mask_226b40 {
    unsigned int pad0;
    unsigned int bits[1];
};

struct MaskHolder_226b40 {
    char pad0[0x10];
    Mask_226b40 *mask;
};

struct Source_226b40 {
    char pad0[0x10];
    float length;
};

struct Chans_226b40 {
    Channel *pos;
    Channel *rot;
};

struct Blend_226b40 {
    unsigned int index;
    float weight;
    int pad;
};

float __cdecl FUN_0004af40(int mode, float a, float b);

union ArgBase_226b40 {
    Base_226b40 *base;
    float acc;
};

union ArgPose_226b40 {
    Pose *pose;
    float w;
};

namespace choreo2 {
class LocomotionStrafeDriver {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(ArgBase_226b40 a, ArgPose_226b40 p, Rig_226b40 *rig, float t);
    virtual void vfunc_11();
    char pad04[0xc];
    Rest_226b40 *rest;             // 0x10
    MaskHolder_226b40 *maskHolder; // 0x14
    unsigned int first;     // 0x18
    unsigned int last;      // 0x1c
    char pad20[4];
    float rate;             // 0x24
    char pad28[0x34 - 0x28];
    char slots[0x12dc - 0x34];
    char b12dc;
    char b12dd;
    char pad12de[2];
    float angle;            // 0x12e0
    char pad12e4[8];
    unsigned int blendCount;    // 0x12ec
    Blend_226b40 blends[1];            // 0x12f0
};
}

struct Frame_226b40 {
    choreo2::LocomotionStrafeDriver *self;      // 0x10
    unsigned int first;                         // 0x14
    float frame;                                // 0x18
    Mask_226b40 *mask;                                 // 0x1c
    unsigned int last;                          // 0x20
    unsigned int k;                             // 0x24
    Blend_226b40 *bl;                                  // 0x28
    Vec3_226b40 c;                                     // 0x2c
    Vec3_226b40 v;                                     // 0x38
    Quat_226b40 q2;                                    // 0x44
    Quat_226b40 q;                                     // 0x54
};

void choreo2::LocomotionStrafeDriver::vfunc_10(ArgBase_226b40 a, ArgPose_226b40 p, Rig_226b40 *rig, float t)
{
    Frame_226b40 f;
    f.self = this;
    if (maskHolder != 0)
        f.mask = maskHolder->mask;
    else
        f.mask = 0;
    unsigned int first = this->first;
    unsigned int last = this->last;
    f.first = first;
    f.last = last;
    if (first == 0) {
        Pose *pose = p.pose;
        if (b12dc) {
            Vec3_226b40 *acc = (Vec3_226b40 *)((char *)this + 0x1320);
            f.c = *acc;
            float s0 = f.c.x + a.base->v.x;
            float s1 = f.c.y + a.base->v.y;
            float s2 = f.c.z + a.base->v.z;
            f.c.z = s2;
            f.c.x = s0 * t;
            float s1t = s1 * t;
            float s2t = f.c.z * t;
            float u = 1.0f - t;
            f.c.x = u * pose->position.x + f.c.x;
            f.c.y = u * pose->position.y + s1t;
            f.c.z = u * pose->position.z + s2t;
            pose->FUN_0022be40(&f.c);
            acc->z = 0;
            acc->y = 0;
            acc->x = 0;
        }
        if (b12dd) {
            f.q.FUN_0022b1c0(angle);
            f.q2 = *pose->FUN_00221cd0();
            f.q2.FUN_0022b750(&f.q2, &f.q, t);
            pose->FUN_00221cf0(&f.q2);
        }
        first = 1;
        f.first = first;
    }
    if (blendCount > 0) {
        f.k = 0;
        f.bl = &blends[0];
        a.acc = 1.0f - t;
        do {
            char *slot = (char *)this + f.bl->index * 0x208;
            a.acc = a.acc + t * f.bl->weight;
            p.w = t * f.bl->weight / a.acc;
            Source_226b40 *src = *(Source_226b40 **)(slot + 0x34);
            if (src != 0) {
                double d = src->length - 1.0f;
                float dd = (float)d;
                f.frame = dd;
                f.frame = FUN_0004af40(0, dd, (float)(d * rate + *(float *)(slot + 0x238)));
                if (first <= last) {
                    Chans_226b40 *ch = (Chans_226b40 *)(slot + 0x38);
                    unsigned int i = first;
                    do {
                        if (f.mask == 0 || (f.mask->bits[i >> 5] & (1u << (i & 0x1f)))) {
                            if (ch[i].rot != 0)
                                ch[i].rot->vf5(f.frame, &f.q);
                            else
                                f.q = rest->quats[i];
                            f.q2 = rig->quats[i];
                            f.q2.FUN_0022b750(&f.q2, &f.q, p.w);
                            rig->quats[i] = f.q2;
                            if (ch[i].pos != 0)
                                ch[i].pos->vf4(f.frame, &f.v);
                            else
                                f.v = *(Vec3_226b40 *)(rest->mats + i * 0x40 + 0x30);
                            Vec3_226b40 *c = (Vec3_226b40 *)(rig->mats + i * 0x40 + 0x30);
                            f.c = *c;
                            c->z = (f.v.z - f.c.z) * p.w + f.c.z;
                            c->x = (f.v.x - f.c.x) * p.w + f.c.x;
                            c->y = (f.v.y - f.c.y) * p.w + f.c.y;
                        }
                        i++;
                    } while (i <= f.last);
                }
            }
            f.k++;
            f.bl++;
        } while (f.k < blendCount);
    }
}
