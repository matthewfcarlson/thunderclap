// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00319670..0x003198d0 (kind game, layer engine, confidence medium), dominant class physics::SimpleFilter3D
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f097f303 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f097f303 {} using namespace fn_f097f303;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f097f303 {
extern "C" char DAT_0043235c[];
class SimpleFilter3D {
  public:
    void* vptr;
    int a[10];
    SimpleFilter3D();
};
struct Vec3_3196a0 {
    float x, y, z;
};
struct V3_319720 {
    float x, y, z;
};
namespace physics {
class SimpleFilter3D {
  public:
    virtual bool vfunc_0(const Vec3_3196a0* origin, const Vec3_3196a0* extent, int unused);
    virtual void vfunc_1(const V3_319720 *in, float dt);
    virtual void _m_vf2();
    union { float inv[3]; float rate[3]; };
    float alpha[3];
    union { int origin[3]; float out[3]; };
    union { float field28; float lastDt; };
};
}


// 0x00319670 FUN_00319670 (41 B): matches/0x00319670.cpp
// sym: ??0SimpleFilter3D@fn_f097f303@@QAE@XZ
SimpleFilter3D::SimpleFilter3D() {
    vptr = (void*)((hulk_intptr)DAT_0043235c);
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    a[6] = 0;
    a[7] = 0;
    a[8] = 0;
    a[9] = 0;
}


// 0x003196a0 physics::SimpleFilter3D::vfunc_0 (126 B): equivalent/0x003196a0.cpp
// sym: ?vfunc_0@SimpleFilter3D@physics@fn_f097f303@@UAE_NPBUVec3_3196a0@3@0H@Z @f6b879e4ccfd @wf9d754e6f1df
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// physics::SimpleFilter3D::vfunc_0 @ 0x003196a0
// Stores the origin and the reciprocal of each extent; fails unless every extent is positive.
bool physics::SimpleFilter3D::vfunc_0(const Vec3_3196a0* o, const Vec3_3196a0* e, int unused)
{
    if (e->x > 0.0f && e->y > 0.0f && e->z > 0.0f) {
        const int* src = (const int*)o;
        origin[0] = src[0];
        origin[1] = src[1];
        origin[2] = src[2];
        inv[0] = 1.0f / e->x;
        inv[1] = 1.0f / e->y;
        field28 = 0.0f;
        inv[2] = 1.0f / e->z;
        return true;
    }
    return false;
}


// 0x00319720 physics::SimpleFilter3D::vfunc_1 (430 B): equivalent/0x00319720.cpp
// sym: ?vfunc_1@SimpleFilter3D@physics@fn_f097f303@@UAEXPBUV3_319720@3@M@Z @61e64329ec82 @w121b47fa0d06
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// physics::SimpleFilter3D::vfunc_1 @ 0x00319720
void physics::SimpleFilter3D::vfunc_1(const V3_319720 *in, float dt)
{
    if (dt != lastDt) {
        alpha[0] = dt * rate[0];
        alpha[1] = dt * rate[1];
        alpha[2] = dt * rate[2];
        for (int i = 0; i < 3; i++) {
            if (alpha[i] <= 0.0f)
                alpha[i] = 0.0f;
            else if (alpha[i] > 0.999999f)
                alpha[i] = 0.999999f;
        }
        if (lastDt == 0.0f) {
            float x = in->x;
            float y = in->y;
            float z = in->z;
            volatile float sz = z * alpha[2];
            volatile float *o = out;
            o[0] = o[0] * 1.5f;
            o[1] = o[1] * 1.5f;
            o[2] = o[2] * 1.5f;
            o[0] = o[0] - x * alpha[0];
            o[1] = o[1] - y * alpha[1];
            o[2] = o[2] - sz;
            o[0] = o[0] / (1.0f - alpha[0]);
            o[1] = o[1] / (1.0f - alpha[1]);
            o[2] = o[2] / (1.0f - alpha[2]);
        }
        lastDt = dt;
    }
    out[0] = (in->x - out[0]) * alpha[0] + out[0];
    out[1] = (in->y - out[1]) * alpha[1] + out[1];
    out[2] = (in->z - out[2]) * alpha[2] + out[2];
}

} // namespace fn_f097f303
