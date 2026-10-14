// STATUS: equivalent (tools/equiv.py level 3: 47 inputs, branch coverage 12/12)
// choreo2::RestPoseDriver::vfunc_10 @ 0x0022a640
struct Quat_22a640 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_22a640 *a, const Quat_22a640 *b, float t);
};

struct Mat_22a640 {
    char pad00[0x30];
    float px, py, pz;
    char pad3c[4];
};

struct Mask_22a640 {
    int pad00;
    unsigned bits[1];
};

struct Pose {
    char pad00[0x10];
    Quat_22a640 *quats;
    Mat_22a640 *mats;
};

struct RestPose {
    char pad00[0x14];
    Quat_22a640 *quats;
    Mat_22a640 *mats;
};

struct MaskHolder_22a640 {
    char pad00[0x10];
    Mask_22a640 *mask;
};

struct Blend_22a640 {
    char pad00[0x30];
    void FUN_00221d60(Blend_22a640 *other, float t);
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
    virtual void vfunc_10(Blend_22a640 *a, Blend_22a640 *b, Pose *pose, float t);
    char pad04[0x10 - 4];
    RestPose *rest;
    MaskHolder_22a640 *holder;
    unsigned first;
    unsigned last;
};

void RestPoseDriver::vfunc_10(Blend_22a640 *a, Blend_22a640 *b, Pose *pose, float t)
{
    Mask_22a640 *mask = holder ? holder->mask : 0;
    unsigned i = first;
    unsigned end = last;
    if (i == 0) {
        b->FUN_00221d60(a, t);
        i = 1;
    }
    for (; i <= end; i++) {
        if (mask && !(mask->bits[i >> 5] & (1u << (i & 31))))
            continue;
        Quat_22a640 qa = pose->quats[i];
        Quat_22a640 qb = rest->quats[i];
        qa.FUN_0022b750(&qa, &qb, t);
        pose->quats[i] = qa;

        Mat_22a640 *pm = &pose->mats[i];
        Mat_22a640 *rm = &rest->mats[i];
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
