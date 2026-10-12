// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 26/26)
// pure3d::PoseAnimationController::vfunc_28 @ 0x002882f0
struct Vec3 {
    float x, y, z;
};

struct Quat {
    float x, y, z, w;
    void FUN_0022b750(const Quat* a, const Quat* b, float t);
};

struct Mat4 {
    char pad00[0x30];
    Vec3 pos;
    float w;
};

class RotChannel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(float t, Quat* out);
    void FUN_0028a8f0(float prevT, float t, Quat* out);
};

class PosChannel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(float t, Vec3* out);
    virtual void vf5(float prevT, float t, Vec3* out);
};

struct Binding {
    RotChannel* rot;
    PosChannel* pos;
    float prevTime;
};

struct Layer {
    float time;
    char pad04[0x14 - 4];
    float weight;
    char pad18[0x2c - 0x18];
    float FUN_00284f70();
    float FUN_00284f60();
};

struct SourcePose {
    char pad00[0x14];
    Quat* quats;
    Mat4* mats;
};

struct PoseBuffer {
    char pad00[8];
    SourcePose* src;
    unsigned int count;
    Quat* quats;
    Mat4* mats;
    char pad18[8];
    char flag20;
    char flag21;
    char flag22;
    char flag23;
};

struct Mask {
    int pad00;
    unsigned int bits[1];
};

struct Filter {
    char pad00[0x10];
    Mask* mask;
};

struct BlendFrame {
    Vec3 p0;
    Vec3 v;
    Quat q;
    Quat r;
};

namespace pure3d {

class PoseAnimationController {
public:
    virtual void vfunc_0();
    char pad04[0x28 - 4];
    unsigned int layerCount;
    Layer layers[5];
    char pad108[0x110 - 0x108];
    PoseBuffer* pose;
    float weight;
    char pad118[4];
    Binding* binds[4];
    char pad12c[4];
    char flag130;
    char useTimes;
    char pad132[2];
    float* times[4];
    char pad144[4];
    int special;
    Filter* filter;
    void FUN_00287e20();
    virtual void vfunc_28();
};

void PoseAnimationController::vfunc_28()
{
    if (weight < 0.00001f)
        return;
    FUN_00287e20();
    bool partial = weight < 1.0f;
    SourcePose* src = pose->src;
    float invw = 1.0f - weight;
    unsigned int n = pose->count;
    Mask* mask = filter->mask;

    for (unsigned int i = 0; i < n; i++) {
        if (!(mask->bits[i >> 5] & (1u << (i & 31))))
            continue;

        BlendFrame f;
        f.q.x = 0;
        f.q.y = 0;
        f.q.z = 0;
        f.q.w = 1.0f;
        f.p0.x = 0;
        f.p0.y = 0;
        f.p0.z = 0;

        for (unsigned int l = 0; l < layerCount; l++) {
            float tt = layers[l].FUN_00284f70();
            float wl = layers[l].FUN_00284f60();
            if (useTimes)
                tt = times[l][i];

            if (binds[l][i].rot) {
                if (special != (int)i)
                    binds[l][i].rot->vf5(tt, &f.r);
                else
                    binds[l][i].rot->FUN_0028a8f0(binds[l][i].prevTime, tt, &f.r);
                f.q.FUN_0022b750(&f.q, &f.r, wl);
            } else {
                f.q.FUN_0022b750(&f.q, &src->quats[i], wl);
            }

            if (binds[l][i].pos) {
                if (special != (int)i)
                    binds[l][i].pos->vf4(tt, &f.v);
                else
                    binds[l][i].pos->vf5(binds[l][i].prevTime, tt, &f.v);
                f.p0.x = (f.v.x - f.p0.x) * wl + f.p0.x;
                f.p0.y = (f.v.y - f.p0.y) * wl + f.p0.y;
                f.p0.z = (f.v.z - f.p0.z) * wl + f.p0.z;
            } else {
                Vec3* sp = &src->mats[i].pos;
                f.p0.x = (sp->x - f.p0.x) * wl + f.p0.x;
                f.p0.y = (sp->y - f.p0.y) * wl + f.p0.y;
                f.p0.z = (sp->z - f.p0.z) * wl + f.p0.z;
            }
            binds[l][i].prevTime = tt;
        }

        if (partial) {
            f.q.FUN_0022b750(&f.q, &pose->quats[i], invw);
            Vec3* dp = &pose->mats[i].pos;
            f.p0.x = (dp->x - f.p0.x) * invw + f.p0.x;
            f.p0.y = (dp->y - f.p0.y) * invw + f.p0.y;
            f.p0.z = (dp->z - f.p0.z) * invw + f.p0.z;
        }
        pose->quats[i] = f.q;
        pose->mats[i].pos = f.p0;
    }

    PoseBuffer* pb = pose;
    pb->flag22 = 1;
    pb->flag23 = 1;
    pb->flag20 = 0;
    pb->flag21 = 1;
}

}
