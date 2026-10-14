// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// choreo2::AnimationDriver::vfunc_11 @ 0x002256a0
struct Quat_2256a0 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_2256a0 *a, const Quat_2256a0 *b, float t);
};

struct Vec3_2256a0 {
    float x, y, z;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(int track, Vec3_2256a0 *out);
    virtual void vf5(int track, Quat_2256a0 *out);
};

class ChannelSet_2256a0 {
public:
    Channel *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

class Pose {
public:
    char pad0[0x30];
    Vec3_2256a0 position;
    char pad1[0x50 - 0x3c];
    int state;
    Quat_2256a0 *FUN_00221cd0();
    void FUN_00221cf0(Quat_2256a0 *q);
    void FUN_0022be40(Vec3_2256a0 *v);
};

class Source_2256a0 {
public:
    ChannelSet_2256a0 *FUN_00288ad0(unsigned int a, unsigned int b);
};

struct Frame_2256a0 {
    char pad[0x10];
    Quat_2256a0 rot;
    Quat_2256a0 q;
};

class AnimationDriver {
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

    char pad0[0x20 - 4];
    Source_2256a0 *source;
    char pad1[0x23c - 0x24];
    int track;
};

char AnimationDriver::vfunc_11(unsigned int a, unsigned int b, Pose *pose, float t)
{
    ChannelSet_2256a0 *set = source->FUN_00288ad0(a, b);
    if (set == 0)
        return 0;
    Frame_2256a0 f;
    char result = 0;
    Channel *rotCh = set->FUN_00288960(0x544f52, 0x544f52);
    if (rotCh != 0) {
        rotCh->vf5(track, &f.rot);
        f.q = *pose->FUN_00221cd0();
        f.q.FUN_0022b750(&f.q, &f.rot, t);
        pose->FUN_00221cf0(&f.q);
        if (t > 0.0f)
            result = 1;
    }
    Channel *posCh = set->FUN_00288960(0x4e415254, 0x54434556);
    if (posCh != 0) {
        posCh->vf4(track, (Vec3_2256a0 *)&f.q);
        Vec3_2256a0 *tp = (Vec3_2256a0 *)&f.q;
        Vec3_2256a0 cur = pose->position;
        cur.x = (tp->x - cur.x) * t + cur.x;
        cur.y = (tp->y - cur.y) * t + cur.y;
        cur.z = (tp->z - cur.z) * t + cur.z;
        pose->FUN_0022be40(&cur);
        if (t > 0.0f)
            result = 1;
    }
    return result;
}
