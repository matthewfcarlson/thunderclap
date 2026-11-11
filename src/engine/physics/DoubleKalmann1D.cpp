// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x003198d0..0x00319c80 (kind game, layer engine, confidence high), dominant class physics::DoubleKalmann1D
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fb7d26a7 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fb7d26a7 {} using namespace fn_fb7d26a7;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_fb7d26a7 {
class Sub_3199d0 {
  public:
    virtual void Fn(float a, float b, float c);
};
class DoubleKalmann1D_3199d0 {
  public:
    virtual bool Init(float a, float b, float c);
    int pad4;
    char p8[4];
    float m0c;
    float m10;
    float m14;
    float m18;
    Sub_3199d0 sub;
    char p20[0x18];
    float m38;
};
class Filter_319a40 {
public:
    virtual float v0(float a, int b);
    virtual float v1(float a, int b);
};
class DoubleKalmann1D {
public:
    virtual void vfunc_0();
    virtual hulk_freg vfunc_1(float x, float dt);
    virtual void vfunc_2();
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    Filter_319a40 filter;
    char pad20[0x38 - 0x20];
    float f38;
};

} // namespace fn_fb7d26a7

// 0x003198d0 physics::Kalmann1D::vfunc_0 (65 B): matches/0x003198d0.cpp [wrapped: conflict: physics::Filter1D; physics::Kalmann1D]
// sym: ?vfunc_0@Kalmann1D@physics@fn_003198d0@@UAE_NHMM@Z
namespace fn_003198d0 {
namespace physics {
class Filter1D {
  public:
    virtual bool vfunc_0(int, float, float);
    virtual void vfunc_1();
    virtual void vfunc_2();
    int a;
    int pad;
    float b, c, d;
    int e;
};
class Kalmann1D : public Filter1D {
  public:
    bool vfunc_0(int, float, float);
};
bool Kalmann1D::vfunc_0(int x, float y, float z) {
    e = x;
    c = y * y;
    d = z * z;
    b = d > 0.0f ? d : 1.0f;
    a = 0;
    return true;
}
} // namespace physics
} // namespace fn_003198d0


// 0x00319920 physics::Kalmann1D::vfunc_1 (59 B): matches/0x00319920.cpp [wrapped: conflict: physics::Filter1D; physics::Kalmann1D]
// sym: ?vfunc_1@Kalmann1D@physics@fn_00319920@@UAEMMM@Z
namespace fn_00319920 {

// cl-flags: /O2 /GR /GX

namespace physics {
class Filter1D {
  public:
    virtual void vfunc_0();
    virtual hulk_freg vfunc_1(float, float);
    virtual void vfunc_2();
};

class Kalmann1D : public Filter1D {
  public:
    float m4;  // offset 0x4
    float m8;  // offset 0x8
    float mC;  // offset 0xC
    float m10; // offset 0x10
    float m14; // offset 0x14
    float m18; // offset 0x18

    virtual hulk_freg vfunc_1(float measurement, float control);
};
} // namespace physics


hulk_freg physics::Kalmann1D::vfunc_1(float measurement, float control) {
#if defined(__clang__)
    hulk_freg q = mC / (m10 + mC);
    m8 = q;
    mC = (DAT_003f32dc - q) * mC + m14;
    hulk_freg result = (measurement - m18) * m8 + control * m4 + m18;
    m18 = result;
    return result;
#else
    m8 = mC / (m10 + mC);
    mC = (DAT_003f32dc - m8) * mC + m14;
    m18 = (measurement - m18) * m8 + control * m4 + m18;
    return m18;
#endif
}
} // namespace fn_00319920

namespace fn_fb7d26a7 {

// 0x003199d0 physics::DoubleKalmann1D::vfunc_0 (99 B): matches/0x003199d0.cpp
// sym: ?Init@DoubleKalmann1D_3199d0@fn_fb7d26a7@@UAE_NMMM@Z
bool DoubleKalmann1D_3199d0::Init(float a, float b, float c) {
    m18 = a;
    m10 = b * b;
    float v = c * c;
    m14 = v;
    if (!(v > 0.0f))
        v = 1.0f;
    m0c = v;
    pad4 = 0;
    (&sub)->Fn(a, b, c);
    m38 = a;
    return true;
}


// 0x00319a40 physics::DoubleKalmann1D::vfunc_1 (109 B): equivalent/0x00319a40.cpp
// sym: ?vfunc_1@DoubleKalmann1D@fn_fb7d26a7@@UAEMMM@Z @0953d2d14f0b @wc599c8ec6060
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// physics::DoubleKalmann1D::vfunc_1 @ 0x00319a40
hulk_freg DoubleKalmann1D::vfunc_1(float x, float dt)
{
    hulk_freg vel = (x - f38) / dt;
    f4 = vel;
    Filter_319a40 *flt = &filter;
    f4 = flt->v1(vel, 0);
    f38 = x;
    hulk_freg k = fc / (f10 + fc);
    f8 = k;
    fc = (((*(float*)&DAT_003f32dc) - k) * fc) + f14;
    hulk_freg est = (((x - f18) * *(volatile float *)&f8) + (dt * *(volatile float *)&f4)) + f18;
    f18 = est;
    return est;
}

} // namespace fn_fb7d26a7

// 0x00319af0 physics::SimpleFilterAbs3D::vfunc_0 (85 B): equivalent/0x00319af0.cpp [wrapped: conflict: physics::SimpleFilter3D; physics::SimpleFilterAbs3D]
// sym: ?vfunc_0@SimpleFilterAbs3D@physics@fn_00319af0@@UAEEIII@Z @c15d22603b80 @w8e02565149e7
namespace fn_00319af0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::SimpleFilterAbs3D::vfunc_0 @ 0x00319af0
namespace physics {
struct SimpleFilter3D {
    virtual unsigned char vfunc_0(unsigned int, unsigned int, unsigned int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    unsigned int x, y, z;
};
struct SimpleFilterAbs3D : SimpleFilter3D {
    virtual unsigned char vfunc_0(unsigned int a, unsigned int b, unsigned int c);
};
unsigned char SimpleFilterAbs3D::vfunc_0(unsigned int a, unsigned int b, unsigned int c) {
    if (!SimpleFilter3D::vfunc_0(a,b,c)) return 0;
    x &= 0x7fffffff;
    y &= 0x7fffffff;
    z &= 0x7fffffff;
    return 1;
}
}
} // namespace fn_00319af0


// 0x00319b50 physics::SimpleFilterAbs3D::vfunc_1 (95 B): equivalent/0x00319b50.cpp [wrapped: conflict: physics::SimpleFilter3D; physics::SimpleFilterAbs3D]
// sym: ?vfunc_1@SimpleFilterAbs3D@physics@fn_00319b50@@UAEXPBUVec3@23@I@Z @851e8cf9fcaa @w481a9c3dd7c3
namespace fn_00319b50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::SimpleFilterAbs3D::vfunc_1 @ 0x00319b50
namespace physics {
struct Vec3 { float x, y, z; };
class SimpleFilter3D {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(const Vec3*, unsigned int);
    virtual void vfunc_2();
};
class SimpleFilterAbs3D : public SimpleFilter3D {
public:
    virtual void vfunc_1(const Vec3* input, unsigned int param);
};
void SimpleFilterAbs3D::vfunc_1(const Vec3* input, unsigned int param)
{
    union Bits { float value; unsigned int bits; } x, y, z;
    x.value = input->x;
    y.value = input->y;
    z.value = input->z;
    x.bits &= 0x7fffffff;
    y.bits &= 0x7fffffff;
    z.bits &= 0x7fffffff;
    Vec3 absolute = {x.value, y.value, z.value};
    SimpleFilter3D::vfunc_1(&absolute, param);
}
}
} // namespace fn_00319b50


// 0x00319bd0 physics::Kalmann1D::vfunc_2 (7 B): matches/0x00319bd0.cpp
// sym: ?vfunc_2@Kalmann1D@physics@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg physics::Kalmann1D::vfunc_2() {
    return DAT_003f32e0;
}


// 0x00319c20 physics::DoubleKalmann1D::vfunc_2 (7 B): matches/0x00319c20.cpp
// sym: ?vfunc_2@DoubleKalmann1D@physics@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg physics::DoubleKalmann1D::vfunc_2() {
    return DAT_003f32e0;
}

