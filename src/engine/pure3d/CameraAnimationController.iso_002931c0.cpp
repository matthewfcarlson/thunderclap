// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00292eb0..0x00293b20 (kind game, layer engine, confidence high), dominant class pure3d::CameraAnimationController
// (tree_prelude.h: not needed)


// 0x002931c0 pure3d::CameraAnimationController::vfunc_27 (649 B): equivalent/0x002931c0.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_002931c0@CameraAnimationController@fn_fbdfd4a6@@QAEXXZ
#include "gen/owners.h"
namespace fn_fbdfd4a6 {} using namespace fn_fbdfd4a6;
namespace fn_fbdfd4a6 {
// STATUS: equivalent (tools/equiv.py level 3: 4432 inputs, branch coverage 22/22)
// pure3d::CameraAnimationController::vfunc_27 @ 0x002931c0
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
};

struct Group_2931c0 {
    Channel *FUN_00288960(unsigned __int64 key);
};

struct Source_2931c0 {
};

struct Clip {
    char pad[0x2c];
};

struct ClipHead_2931c0 {
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
    void FUN_002c3410(const Vec3_2931c0 *v);
    void FUN_00293ac0(const Vec3_2931c0 *v);
};

// equiv-conv: FUN_00292f60 esi edi stack
extern "C" void __cdecl FUN_00292f60(void *, void *, float *);

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
    Source_2931c0 *src = ((Source_2931c0 *)((owners::Target_284f50 *)&head)->FUN_00284f50());
    Group_2931c0 *grp = ((Group_2931c0 *)((owners::Target_288a10 *)src)->FUN_00288a10(0));
    fr.t = head.FUN_00284f70();
    fr.U.x = 0.0f;
    fr.U.y = 0.0f;
    fr.U.z = 0.0f;
    Channel *tran = grp->FUN_00288960(0x544345564e415254ui64);
    Channel *look = grp->FUN_00288960(0x544345564b4f4f4cui64);
    fr.up = grp->FUN_00288960(0x5443455600005055ui64);
    FUN_00292f60((Channel *)tran, (Channel *)look, &fr.t);

    if (mode == 0) {
        fr.cam = camera;
        if (tran) {
            tran->vfunc_4(fr.t, &fr.U);
            ((owners::C_293af0 *)(fr.cam))->FUN_00293af0((int *)(const Vec3_2931c0 *)(&fr.U));
        }
        if (look) {
            look->vfunc_4(fr.t, &fr.U);
            ((owners::C_293a90 *)(fr.cam))->FUN_00293a90((int *)(const Vec3_2931c0 *)(&fr.U));
        }
        if (fr.up) {
            fr.up->vfunc_4(fr.t, &fr.U);
            fr.cam->FUN_00293ac0(&fr.U);
        }
    } else if (mode == 1) {
        fr.cam = camera;
        if (tran) {
            tran->vfunc_4(fr.t, &fr.U);
            ((owners::C_2c33e0 *)(fr.cam))->FUN_002c33e0((int *)(const Vec3_2931c0 *)(&fr.U));
            if (look) {
                fr.W.x = 0.0f;
                fr.W.y = 0.0f;
                fr.W.z = 0.0f;
                look->vfunc_4(fr.t, &fr.W);
                fr.Z.x = fr.W.x + fr.U.x;
                fr.Z.y = fr.W.y + fr.U.y;
                fr.Z.z = fr.W.z + fr.U.z;
                ((owners::C_2c33b0 *)(fr.cam))->FUN_002c33b0((int *)(const Vec3_2931c0 *)(&fr.Z));
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
        ((owners::Curve_28a1c0 *)fov)->FUN_0028a1c0(t, &fr.U.x);
        camera->vfunc_6(&fr.p14, &fr.p18);
        camera->vfunc_5(fr.U.x, fr.p18);
    }
    Channel *nclp = grp->FUN_00288960(0x31544c46504c434eui64);
    if (nclp) {
        ((owners::Curve_28a1c0 *)nclp)->FUN_0028a1c0(t, &fr.U.x);
        camera->vfunc_7(fr.U.x);
    }
    Channel *fclp = grp->FUN_00288960(0x31544c46504c4346ui64);
    if (fclp) {
        ((owners::Curve_28a1c0 *)fclp)->FUN_0028a1c0(t, &fr.U.x);
        camera->vfunc_9(fr.U.x);
    }
}
} // namespace fn_fbdfd4a6

