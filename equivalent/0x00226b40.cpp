// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 26/26)
// choreo2::LocomotionStrafeDriver::vfunc_10 @ 0x00226b40
struct Quat {
    float x, y, z, w;
    void FUN_0022b750(const Quat *a, const Quat *b, float t);
    void FUN_0022b1c0(float angle);
};

struct Vec3 {
    float x, y, z;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(float frame, Vec3 *out);
    virtual void vf5(float frame, Quat *out);
};

class ChannelSet;

class Pose {
public:
    char pad0[0x30];
    Vec3 position;
    Quat *FUN_00221cd0();
    void FUN_00221cf0(Quat *q);
    void FUN_0022be40(Vec3 *v);
};

struct Base {
    char pad0[0x30];
    Vec3 v;
};

struct Rig {
    char pad0[0x10];
    Quat *quats;            // 0x10
    char *mats;             // 0x14 stride 0x40, position at +0x30
};

struct Rest {
    char pad0[0x14];
    Quat *quats;            // 0x14
    char *mats;             // 0x18
};

struct Mask {
    unsigned int pad0;
    unsigned int bits[1];
};

struct MaskHolder {
    char pad0[0x10];
    Mask *mask;
};

struct Source {
    char pad0[0x10];
    float length;
};

struct Chans {
    Channel *pos;
    Channel *rot;
};

struct Blend {
    unsigned int index;
    float weight;
    int pad;
};

float __cdecl FUN_0004af40(int mode, float a, float b);

union ArgBase {
    Base *base;
    float acc;
};

union ArgPose {
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
    virtual void vfunc_10(ArgBase a, ArgPose p, Rig *rig, float t);
    virtual void vfunc_11();
    char pad04[0xc];
    Rest *rest;             // 0x10
    MaskHolder *maskHolder; // 0x14
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
    Blend blends[1];            // 0x12f0
};
}

struct Frame {
    choreo2::LocomotionStrafeDriver *self;      // 0x10
    unsigned int first;                         // 0x14
    float frame;                                // 0x18
    Mask *mask;                                 // 0x1c
    unsigned int last;                          // 0x20
    unsigned int k;                             // 0x24
    Blend *bl;                                  // 0x28
    Vec3 c;                                     // 0x2c
    Vec3 v;                                     // 0x38
    Quat q2;                                    // 0x44
    Quat q;                                     // 0x54
};

void choreo2::LocomotionStrafeDriver::vfunc_10(ArgBase a, ArgPose p, Rig *rig, float t)
{
    Frame f;
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
            Vec3 *acc = (Vec3 *)((char *)this + 0x1320);
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
            double tw = t * f.bl->weight;
            char *slot = (char *)this + f.bl->index * 0x208;
            a.acc = (float)(a.acc + tw);
            p.w = (float)(tw / a.acc);
            Source *src = *(Source **)(slot + 0x34);
            if (src != 0) {
                double d = src->length - 1.0f;
                float dd = (float)d;
                f.frame = dd;
                f.frame = FUN_0004af40(0, dd, (float)(d * rate + *(float *)(slot + 0x238)));
                if (first <= last) {
                    Chans *ch = (Chans *)(slot + 0x38);
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
                                f.v = *(Vec3 *)(rest->mats + i * 0x40 + 0x30);
                            Vec3 *c = (Vec3 *)(rig->mats + i * 0x40 + 0x30);
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
