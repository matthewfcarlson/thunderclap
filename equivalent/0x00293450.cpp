// STATUS: equivalent (tools/equiv.py level 3: 43 inputs, branch coverage 20/20)
// pure3d::CameraAnimationController::vfunc_28 @ 0x00293450
struct Vec3_293450 {
    float x, y, z;
};

class Channel {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(float t, Vec3_293450 *out);
    void FUN_0028a1c0(float t, float *out);
};

struct Group_293450 {
    Channel *FUN_00288960(unsigned __int64 key);
};

struct Source_293450 {
    Group_293450 *FUN_00288a10(int arg);
};

struct ClipHead_293450 {
    char pad[0x2c];
    Source_293450 *FUN_00284f50();
    float FUN_00284f70();
    float FUN_00284f60();
};

class Camera {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float a, float b);
    virtual void vfunc_6(float *a, float *b);
    virtual void vfunc_7(float v);
    virtual void vfunc_8();
    virtual int vfunc_9(float v);
    void FUN_002c33e0(const Vec3_293450 *v);
    void FUN_002c33b0(const Vec3_293450 *v);
    void FUN_002c3410(const Vec3_293450 *v);
    void FUN_00293af0(const Vec3_293450 *v);
    void FUN_00293a90(const Vec3_293450 *v);
    void FUN_00293ac0(const Vec3_293450 *v);
};

void __cdecl FUN_00292f60(float *t);

class CameraAnimationController {
public:
    char pad0[0x28];
    unsigned int count;         // 0x28
    ClipHead_293450 clips[5];          // 0x2c
    char pad108[0x110 - 0x108];
    int mode;                   // 0x110
    Camera *camera;             // 0x114

    int FUN_00293450();
};

int CameraAnimationController::FUN_00293450()
{
    struct Frame {
        int pad0;
        float B;
        float C;
        float A;
        float acc1;
        float acc2;
        float acc3;
        unsigned int i;
        CameraAnimationController *self;
        union {
            Channel *up;
            int slot24;
        };
        union {
            Channel *fov;
            float out28;
        };
        union {
            Channel *nclp;
            float out2c;
        };
        Vec3_293450 tmp;
        Vec3_293450 U;
        Vec3_293450 W;
        Vec3_293450 Z;
    } fr;

    fr.self = this;
    fr.U.x = 0.0f;
    fr.U.y = 0.0f;
    fr.U.z = 0.0f;
    fr.W.x = 0.0f;
    fr.W.y = 0.0f;
    fr.W.z = 0.0f;
    fr.Z.x = 0.0f;
    fr.Z.y = 0.0f;
    fr.Z.z = 0.0f;
    fr.acc1 = 0.0f;
    fr.acc2 = 0.0f;
    fr.acc3 = 0.0f;
    fr.i = 0;

    if (count != 0) {
        ClipHead_293450 *h = &clips[0];
        do {
            Source_293450 *src = h->FUN_00284f50();
            Group_293450 *grp = src->FUN_00288a10(0);
            fr.A = h->FUN_00284f70();
            fr.B = h->FUN_00284f60();
            fr.C = 1.0f - fr.B;
            fr.tmp.x = 0.0f;
            fr.tmp.y = 0.0f;
            fr.tmp.z = 0.0f;
            Channel *tran = grp->FUN_00288960(0x544345564e415254ui64);
            Channel *look = grp->FUN_00288960(0x544345564b4f4f4cui64);
            fr.up = grp->FUN_00288960(0x5443455600005055ui64);
            fr.fov = grp->FUN_00288960(0x31544c4600564f46ui64);
            fr.nclp = grp->FUN_00288960(0x31544c46504c434eui64);
            Channel *fclp = grp->FUN_00288960(0x31544c46504c4346ui64);
            FUN_00292f60(&fr.A);

            if (tran) {
                fr.U.x = fr.U.x * fr.C;
                fr.U.y = fr.U.y * fr.C;
                fr.U.z = fr.U.z * fr.C;
                tran->vfunc_4(fr.A, &fr.tmp);
                fr.U.x = fr.tmp.x * fr.B + fr.U.x;
                fr.U.y = fr.tmp.y * fr.B + fr.U.y;
                fr.U.z = fr.tmp.z * fr.B + fr.U.z;
            }
            if (look) {
                fr.W.x = fr.W.x * fr.C;
                fr.W.y = fr.W.y * fr.C;
                fr.W.z = fr.W.z * fr.C;
                look->vfunc_4(fr.A, &fr.tmp);
                fr.W.x = fr.tmp.x * fr.B + fr.W.x;
                fr.W.y = fr.tmp.y * fr.B + fr.W.y;
                fr.W.z = fr.tmp.z * fr.B + fr.W.z;
            }
            if (fr.up) {
                fr.Z.x = fr.Z.x * fr.C;
                fr.Z.y = fr.Z.y * fr.C;
                fr.Z.z = fr.Z.z * fr.C;
                fr.up->vfunc_4(fr.A, &fr.tmp);
                fr.Z.x = fr.tmp.x * fr.B + fr.Z.x;
                fr.Z.y = fr.tmp.y * fr.B + fr.Z.y;
                fr.Z.z = fr.tmp.z * fr.B + fr.Z.z;
            }
            if (fr.fov) {
                fr.fov->FUN_0028a1c0(fr.A, &fr.tmp.x);
                fr.acc1 = fr.tmp.x * fr.B + fr.C * fr.acc1;
            }
            if (fr.nclp) {
                fr.nclp->FUN_0028a1c0(fr.A, &fr.tmp.x);
                fr.acc2 = fr.tmp.x * fr.B + fr.C * fr.acc2;
            }
            if (fclp) {
                fclp->FUN_0028a1c0(fr.A, &fr.tmp.x);
                fr.acc3 = fr.tmp.x * fr.B + fr.C * fr.acc3;
            }
            fr.i++;
            h = h + 1;
        } while (fr.i < fr.self->count);
    }

    if (mode == 0) {
        Camera *cam = camera;
        cam->FUN_00293af0(&fr.U);
        cam->FUN_00293a90(&fr.W);
        cam->FUN_00293ac0(&fr.Z);
        cam->vfunc_6(&fr.out28, &fr.out2c);
        cam->vfunc_5(fr.acc1, fr.out2c);
        cam->vfunc_7(fr.acc2);
        return cam->vfunc_9(fr.acc3);
    } else if (mode == 1) {
        Camera *cam = camera;
        cam->FUN_002c33e0(&fr.U);
        fr.tmp.x = fr.W.x + fr.U.x;
        fr.tmp.y = fr.W.y + fr.U.y;
        fr.tmp.z = fr.W.z + fr.U.z;
        cam->FUN_002c33b0(&fr.tmp);
        cam->FUN_002c3410(&fr.Z);
        cam->vfunc_6(&fr.out28, &fr.out2c);
        cam->vfunc_5(fr.acc1, fr.out2c);
        cam->vfunc_7(fr.acc2);
        return cam->vfunc_9(fr.acc3);
    }
    return mode - 1;
}
