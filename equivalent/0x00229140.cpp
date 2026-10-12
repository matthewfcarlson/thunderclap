// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 17/18, incomplete)
// choreo2::LocomotionSteerDriver::vfunc_11 @ 0x00229140
struct Quat {
    float x, y, z, w;
    void FUN_0022b750(const Quat *a, const Quat *b, float t);
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

class ChannelSet {
public:
    Channel *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

class Pose {
public:
    char pad0[0x30];
    Vec3 position;
    Quat *FUN_00221cd0();
    void FUN_00221cf0(Quat *q);
    void FUN_0022be40(Vec3 *v);
};

class Source {
public:
    char pad0[0x10];
    float length;
    ChannelSet *FUN_00288ad0(unsigned int a, unsigned int b);
};

struct Slot {
    char pad0[0x34];
    Source *source;
    char pad38[0x238 - 0x38];
    float bias;
};

struct Blend {
    unsigned int index;
    float weight;
    int pad;
};

float __cdecl FUN_0004af40(int mode, float a, float b);

namespace choreo2 {
class LocomotionSteerDriver {
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
    virtual void vfunc_10();
    virtual char vfunc_11(unsigned int a, unsigned int b, Pose *pose, float t);
    char pad04[0x24 - 4];
    float rate;
    char pad28[0x8b4 - 0x28];
    unsigned int blendCount;
    Blend blends[1];
};
}

char choreo2::LocomotionSteerDriver::vfunc_11(unsigned int a, unsigned int b, Pose *pose, float t)
{
    if (blendCount == 0)
        return 0;

    struct Frame {
        Quat rot;
        Vec3 target;
        Vec3 cur;
        Quat q;
    } fr;
    char result = 0;
    float w = 0.0f;
    volatile float acc = 1.0f - t;
    for (unsigned int i = 0; i < blendCount; i++) {
        Blend *bl = &blends[i];
        double tw = t * bl->weight;
        Slot *slot = (Slot *)((char *)this + bl->index * 0x208);
        acc = (float)(acc + tw);
        w = (float)(tw / acc);
        Source *src = slot->source;
        if (src == 0)
            continue;
        ChannelSet *set = src->FUN_00288ad0(a, b);
        if (set == 0)
            continue;
        double d = src->length - 1.0f;
        float dd = (float)d;
        float frame = FUN_0004af40(0, dd, (float)(d * rate + slot->bias));
        Channel *rotCh = set->FUN_00288960(0x544f52, 0x544f52);
        if (rotCh != 0) {
            rotCh->vf5(frame, &fr.rot);
            fr.q = *pose->FUN_00221cd0();
            fr.q.FUN_0022b750(&fr.q, &fr.rot, w);
            pose->FUN_00221cf0(&fr.q);
            if (w > 0.0f)
                result = 1;
        }
        Channel *posCh = set->FUN_00288960(0x4e415254, 0x54434556);
        if (posCh == 0)
            continue;
        posCh->vf4(frame, &fr.target);
        fr.cur = pose->position;
        fr.cur.x = (fr.target.x - fr.cur.x) * w + fr.cur.x;
        fr.cur.y = (fr.target.y - fr.cur.y) * w + fr.cur.y;
        fr.cur.z = (fr.target.z - fr.cur.z) * w + fr.cur.z;
        pose->FUN_0022be40(&fr.cur);
        if (w > 0.0f)
            result = 1;
    }
    return result;
}
