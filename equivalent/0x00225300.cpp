// STATUS: equivalent (tools/equiv.py level 3: 62 inputs, branch coverage 21/22, incomplete)
// choreo2::AnimationDriver::vfunc_10 @ 0x00225300
struct Quat {
    float x, y, z, w;
    void FUN_0022b750(const Quat* a, const Quat* b, float t);
};

struct Vec3 {
    float x, y, z;
};

struct Mat4 {
    char pad00[0x30];
    Vec3 pos;
    float w;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(int track, Vec3* out);
    virtual void vf5(int track, Quat* out);
    void FUN_0028a8f0(int a, int b, Quat* out);
};

class Pose {
public:
    char pad0[0x30];
    Vec3 position;
    char pad1[0x50 - 0x3c];
    int state;
    Quat* FUN_00221cd0();
    void FUN_00221cf0(Quat* q);
    void FUN_0022be40(Vec3* v);
};

struct PoseData {
    char pad00[0x10];
    Quat* quats;
    Mat4* mats;
};

struct SourceData {
    char pad00[0x14];
    Quat* quats;
    Mat4* mats;
};

struct Mask {
    int pad00;
    unsigned int bits[1];
};

struct Filter {
    char pad00[0x10];
    Mask* mask;
};

struct Frame {
    union {
        Quat root;
        Vec3 cur;
        Vec3 old;
    };
    union {
        Quat qb;
        Vec3 tgt;
        Vec3 pos;
    };
    union {
        Quat qa;
        Quat dst;
    };
    Quat src;
};

struct Pair {
    Channel* pos;
    Channel* rot;
};

void FUN_0022b080(Quat* out, Quat* a, Quat* b);

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
    virtual void vfunc_10(Pose* from, Pose* to, PoseData* data, float t);

    char pad04[0x10 - 4];
    SourceData* source;
    Filter* filter;
    unsigned int first;
    unsigned int last;
    char pad20[4];
    Pair pairs[1];
    char pad2c[0x234 - 0x2c];
    char doPosition;
    char doRotation;
    char pad236[2];
    int prevTrack;
    int track;
    void FUN_002251d0(Pose* pose, int a, int b, Vec3* out);
};

void AnimationDriver::vfunc_10(Pose* from, Pose* to, PoseData* data, float t)
{
    Frame f;
    Mask* mask = 0;
    if (filter)
        mask = filter->mask;
    unsigned int count = last;
    unsigned int i = first;

    if (i == 0) {
        if (doRotation) {
            if (pairs[0].rot) {
                pairs[0].rot->FUN_0028a8f0(prevTrack, track, &f.root);
            } else {
                f.root.x = 0;
                f.root.y = 0;
                f.root.z = 0;
                f.root.w = 1.0f;
            }
            f.qa = *from->FUN_00221cd0();
            FUN_0022b080(&f.qa, &f.qa, &f.root);
            f.qb = *to->FUN_00221cd0();
            f.qb.FUN_0022b750(&f.qb, &f.qa, t);
            to->FUN_00221cf0(&f.qb);
        }
        if (doPosition) {
            FUN_002251d0(from, prevTrack, track, &f.tgt);
            f.tgt.x = f.tgt.x + from->position.x;
            f.cur = to->position;
            f.tgt.y = f.tgt.y + from->position.y;
            f.tgt.z = f.tgt.z + from->position.z;
            double u = 1.0f - t;
            double cx = f.cur.x * u;
            f.cur.y = f.cur.y * u;
            f.cur.z = f.cur.z * u;
            f.cur.x = f.tgt.x * t + cx;
            f.cur.y = f.tgt.y * t + f.cur.y;
            f.cur.z = f.tgt.z * t + f.cur.z;
            to->FUN_0022be40(&f.cur);
        }
        i = 1;
    }

    if (i > count) {
        prevTrack = track;
        return;
    }

    for (; i <= count; i++) {
        if (mask && !(mask->bits[i >> 5] & (1u << (i & 31))))
            continue;

        if (pairs[i].rot) {
            pairs[i].rot->vf5(track, &f.src);
        } else {
            f.src = source->quats[i];
        }
        f.dst = data->quats[i];
        f.dst.FUN_0022b750(&f.dst, &f.src, t);
        data->quats[i] = f.dst;

        if (pairs[i].pos) {
            pairs[i].pos->vf4(track, &f.pos);
        } else {
            f.pos = source->mats[i].pos;
        }
        f.old = data->mats[i].pos;
        Vec3* out = &data->mats[i].pos;
        out->z = (f.pos.z - f.old.z) * t + f.old.z;
        out->x = (f.pos.x - f.old.x) * t + f.old.x;
        out->y = (f.pos.y - f.old.y) * t + f.old.y;
    }
    prevTrack = track;
}
