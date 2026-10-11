// STATUS: equivalent (tools/equiv.py level 3: 47 inputs, branch coverage 12/12)
// choreo2::RestPoseDriver::vfunc_10 @ 0x0022a640
struct Quat {
    float x, y, z, w;
    void FUN_0022b750(const Quat *a, const Quat *b, float t);
};

struct Mat {
    char pad00[0x30];
    float px, py, pz;
    char pad3c[4];
};

struct Mask {
    int pad00;
    unsigned bits[1];
};

struct Pose {
    char pad00[0x10];
    Quat *quats;
    Mat *mats;
};

struct RestPose {
    char pad00[0x14];
    Quat *quats;
    Mat *mats;
};

struct MaskHolder {
    char pad00[0x10];
    Mask *mask;
};

struct Blend {
    char pad00[0x30];
    void FUN_00221d60(Blend *other, float t);
};

class RestPoseDriver {
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
    virtual void vfunc_10(Blend *a, Blend *b, Pose *pose, float t);
    char pad04[0x10 - 4];
    RestPose *rest;
    MaskHolder *holder;
    unsigned first;
    unsigned last;
};

void RestPoseDriver::vfunc_10(Blend *a, Blend *b, Pose *pose, float t)
{
    Mask *mask = holder ? holder->mask : 0;
    unsigned i = first;
    unsigned end = last;
    if (i == 0) {
        b->FUN_00221d60(a, t);
        i = 1;
    }
    for (; i <= end; i++) {
        if (mask && !(mask->bits[i >> 5] & (1u << (i & 31))))
            continue;
        Quat qa = pose->quats[i];
        Quat qb = rest->quats[i];
        qa.FUN_0022b750(&qa, &qb, t);
        pose->quats[i] = qa;

        Mat *pm = &pose->mats[i];
        Mat *rm = &rest->mats[i];
        float ax = pm->px, ay = pm->py, az = pm->pz;
        float bx = rm->px, by = rm->py, bz = rm->pz;
        float rx = (bx - ax) * t + ax;
        float ry = (by - ay) * t + ay;
        float rz = (bz - az) * t + az;
        pm->px = rx;
        pm->py = ry;
        pm->pz = rz;
    }
}
