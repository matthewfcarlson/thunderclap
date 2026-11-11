// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022a5d0..0x0022a8e0 (kind game, layer engine, confidence high), dominant class choreo2::RestPoseDriver
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/choreo2.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f792b616 {
#define TREE_TU_END }
namespace fn_f792b616 {} using namespace fn_f792b616;
#include "engine/choreo2.h"

// ---- declarations shared by the functions below
namespace fn_f792b616 {
struct ThisCall_002223f0 {
    void InitRestPose(void*);
};
struct Quat_22a640 {
    float x, y, z, w;
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
class Driver_22a7e0 {
    char pad[1];
};
extern void* PartitionDriver_22a800_vftable[];
class PartitionDriver_22a800 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class RestPoseDriver_22a800 : public PartitionDriver_22a800 {
  public:
    RestPoseDriver_22a800* vfunc_5(signed char flags);
};
void* __cdecl alloc(hulk_uintptr);
extern int vt_22a8a0;
struct RestPoseDriver_nv_22a8a0 {
    void InitA(choreo2::RestPoseDriver*);
    void InitB(choreo2::RestPoseDriver*);
};

} // namespace fn_f792b616

// 0x0022a5d0 FUN_0022a5d0 (25 B): matches/0x0022a5d0.cpp
// sym: ?FUN_0022a5d0@RestPoseDriver@choreo2@@QAEPAV12@PAX@Z
choreo2::RestPoseDriver* choreo2::RestPoseDriver::FUN_0022a5d0(void* arg) {
    ((ThisCall_002223f0*)(this))->InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return (choreo2::RestPoseDriver*)(this);
}


// 0x0022a620 choreo2::RestPoseDriver::vfunc_3 (3 B): matches/0x0022a620.cpp
// sym: ?vfunc_3@RestPoseDriver@choreo2@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool choreo2::RestPoseDriver::vfunc_3() {
    return true;
}


// 0x0022a630 choreo2::RestPoseDriver::vfunc_9 (3 B): matches/0x0022a630.cpp
// sym: ?vfunc_9@RestPoseDriver@choreo2@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void choreo2::RestPoseDriver::vfunc_9(int a) {
    (void)a;
}

namespace fn_f792b616 {

// 0x0022a640 choreo2::RestPoseDriver::vfunc_10 (414 B): equivalent/0x0022a640.cpp
// sym: ?vfunc_10@RestPoseDriver@fn_f792b616@@UAEXPAUBlend_22a640@2@0PAUPose@2@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 47 inputs, branch coverage 12/12)
// choreo2::RestPoseDriver::vfunc_10 @ 0x0022a640
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
        ((owners::Quaternion_22b750 *)&qa)->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_22a640 *)(&qa), (const owners::Quaternion_22b750 *)(const Quat_22a640 *)(&qb), t);
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

} // namespace fn_f792b616

// 0x0022a7e0 choreo2::RestPoseDriver::vfunc_11 (5 B): matches/0x0022a7e0.cpp
// sym: ?vfunc_11@RestPoseDriver@choreo2@@UAE_NHHHH@Z
// Same code shape as 0x00224b90 (propagated; names are from that function)
bool choreo2::RestPoseDriver::vfunc_11(int , int , int , int ) {
    return false;
}


// 0x0022a7f0 choreo2::RestPoseDriver::vfunc_13 (3 B): matches/0x0022a7f0.cpp
// sym: ?vfunc_13@RestPoseDriver@choreo2@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char choreo2::RestPoseDriver::vfunc_13() {
    return 0;
}

namespace fn_f792b616 {

// 0x0022a800 choreo2::RestPoseDriver::vfunc_2 (36 B): matches/0x0022a800.cpp
// sym: ?vfunc_5@RestPoseDriver_22a800@fn_f792b616@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
RestPoseDriver_22a800* RestPoseDriver_22a800::vfunc_5(signed char flags) {
    *(void***)this = PartitionDriver_22a800_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f792b616

// 0x0022a8a0 choreo2::RestPoseDriver::vfunc_5 (52 B): matches/0x0022a8a0.cpp
// sym: ?vfunc_5@RestPoseDriver@choreo2@@UAEPAXXZ
void* choreo2::RestPoseDriver::vfunc_5() {
    choreo2::RestPoseDriver* p = (choreo2::RestPoseDriver*)alloc(0x20);
    if (p) {
        ((RestPoseDriver_nv_22a8a0*)(p))->InitA(this);
        *(hulk_intptr*)p = (hulk_intptr)&vt_22a8a0;
        ((RestPoseDriver_nv_22a8a0*)(p))->InitB(this);
        return (void*)(p);
    }
    return (void*)(0);
}

