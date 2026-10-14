// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 22/22)
// pure3d::CameraAnimationController::vfunc_27 @ 0x002931c0
struct Vec3_2931c0 {
    float x, y, z;
};

class Channel {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(float t, Vec3_2931c0 *out);
    void FUN_0028a1c0(float t, float *out);
};

struct Group_2931c0 {
    Channel *FUN_00288960(unsigned __int64 key);
};

struct Source_2931c0 {
    Group_2931c0 *FUN_00288a10(int arg);
};

struct Clip {
    char pad[0x2c];
};

struct ClipHead_2931c0 {
    Source_2931c0 *FUN_00284f50();
    float FUN_00284f70();
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
    virtual void vfunc_9(float v);
    void FUN_002c33e0(const Vec3_2931c0 *v);
    void FUN_002c33b0(const Vec3_2931c0 *v);
    void FUN_002c3410(const Vec3_2931c0 *v);
    void FUN_00293af0(const Vec3_2931c0 *v);
    void FUN_00293a90(const Vec3_2931c0 *v);
    void FUN_00293ac0(const Vec3_2931c0 *v);
};

void __cdecl FUN_00292f60(float *t);

class Camera;
struct Frame_2931c0 {
    float t;
    union {
        float p14;
        Camera *cam;
    };
    union {
        float p18;
        Channel *up;
    };
    Vec3_2931c0 U;
    Vec3_2931c0 W;
    Vec3_2931c0 Z;
};

class CameraAnimationController {
public:
    char pad0[0x2c];
    ClipHead_2931c0 head;
    char pad1[0x110 - 0x2c - sizeof(ClipHead_2931c0)];
    int mode;
    Camera *camera;

    void FUN_002931c0();
};

void CameraAnimationController::FUN_002931c0()
{
    Frame_2931c0 fr;
    Source_2931c0 *src = head.FUN_00284f50();
    Group_2931c0 *grp = src->FUN_00288a10(0);
    fr.t = head.FUN_00284f70();
    fr.U.x = 0.0f;
    fr.U.y = 0.0f;
    fr.U.z = 0.0f;
    Channel *tran = grp->FUN_00288960(0x544345564e415254ui64);
    Channel *look = grp->FUN_00288960(0x544345564b4f4f4cui64);
    fr.up = grp->FUN_00288960(0x5443455600005055ui64);
    FUN_00292f60(&fr.t);

    if (mode == 0) {
        fr.cam = camera;
        if (tran) {
            tran->vfunc_4(fr.t, &fr.U);
            fr.cam->FUN_00293af0(&fr.U);
        }
        if (look) {
            look->vfunc_4(fr.t, &fr.U);
            fr.cam->FUN_00293a90(&fr.U);
        }
        if (fr.up) {
            fr.up->vfunc_4(fr.t, &fr.U);
            fr.cam->FUN_00293ac0(&fr.U);
        }
    } else if (mode == 1) {
        fr.cam = camera;
        if (tran) {
            tran->vfunc_4(fr.t, &fr.U);
            fr.cam->FUN_002c33e0(&fr.U);
            if (look) {
                fr.W.x = 0.0f;
                fr.W.y = 0.0f;
                fr.W.z = 0.0f;
                look->vfunc_4(fr.t, &fr.W);
                fr.Z.x = fr.W.x + fr.U.x;
                fr.Z.y = fr.W.y + fr.U.y;
                fr.Z.z = fr.W.z + fr.U.z;
                fr.cam->FUN_002c33b0(&fr.Z);
            }
        }
        if (fr.up) {
            fr.up->vfunc_4(fr.t, &fr.U);
            fr.cam->FUN_002c3410(&fr.U);
        }
    }

    Channel *fov = grp->FUN_00288960(0x31544c4600564f46ui64);
    float t = fr.t;
    if (fov) {
        fov->FUN_0028a1c0(t, &fr.U.x);
        camera->vfunc_6(&fr.p14, &fr.p18);
        camera->vfunc_5(fr.U.x, fr.p18);
    }
    Channel *nclp = grp->FUN_00288960(0x31544c46504c434eui64);
    if (nclp) {
        nclp->FUN_0028a1c0(t, &fr.U.x);
        camera->vfunc_7(fr.U.x);
    }
    Channel *fclp = grp->FUN_00288960(0x31544c46504c4346ui64);
    if (fclp) {
        fclp->FUN_0028a1c0(t, &fr.U.x);
        camera->vfunc_9(fr.U.x);
    }
}
