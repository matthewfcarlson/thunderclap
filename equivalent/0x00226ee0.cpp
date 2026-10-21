// STATUS: equivalent (tools/equiv.py level 3: 6674 inputs, branch coverage 17/18, incomplete)
// choreo2::LocomotionStrafeDriver::vfunc_11 @ 0x00226ee0
struct Quat_226ee0 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_226ee0 *a, const Quat_226ee0 *b, float t);
};

struct Vec3_226ee0 {
    float x, y, z;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(float frame, Vec3_226ee0 *out);
    virtual void vf5(float frame, Quat_226ee0 *out);
};

class ChannelSet_226ee0 {
public:
    Channel *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

class Pose {
public:
    char pad0[0x30];
    Vec3_226ee0 position;
    Quat_226ee0 *FUN_00221cd0();
    void FUN_00221cf0(Quat_226ee0 *q);
    void FUN_0022be40(Vec3_226ee0 *v);
};

class Source_226ee0 {
public:
    char pad0[0x10];
    float length;
    ChannelSet_226ee0 *FUN_00288ad0(unsigned int a, unsigned int b);
};

struct Slot_226ee0 {
    char pad0[0x34];
    Source_226ee0 *source;
    char pad38[0x238 - 0x38];
    float bias;
};

struct Blend_226ee0 {
    unsigned int index;
    float weight;
    int pad;
};

float __cdecl FUN_0004af40(float lo, float a, float b);

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
    virtual void vfunc_10();
    virtual char vfunc_11(unsigned int a, unsigned int b, Pose *pose, float t);
    char pad04[0x24 - 4];
    float rate;
    char pad28[0x12ec - 0x28];
    unsigned int blendCount;
    Blend_226ee0 blends[1];
};
}

char choreo2::LocomotionStrafeDriver::vfunc_11(unsigned int a, unsigned int b, Pose *pose, float t)
{
    if (blendCount == 0)
        return 0;

    struct Frame {
        Quat_226ee0 rot;
        Vec3_226ee0 target;
        Vec3_226ee0 cur;
        Quat_226ee0 q;
    } fr;
    char result = 0;
    float w = 0.0f;
    volatile float acc = 1.0f - t;
    for (unsigned int i = 0; i < blendCount; i++) {
        Blend_226ee0 *bl = &blends[i];
        double tw = t * bl->weight;
        Slot_226ee0 *slot = (Slot_226ee0 *)((char *)this + bl->index * 0x208);
        acc = (float)(acc + tw);
        w = (float)(tw / acc);
        Source_226ee0 *src = slot->source;
        if (src == 0)
            continue;
        ChannelSet_226ee0 *set = src->FUN_00288ad0(a, b);
        if (set == 0)
            continue;
        double d = src->length - 1.0f;
        float dd = (float)d;
        float frame = FUN_0004af40(0.0f, dd, (float)(d * rate + slot->bias));
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
