// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002926d0..0x00292eb0 (kind game, layer engine, confidence high), dominant class pure3d::Camera
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f91e2119 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f91e2119 {} using namespace fn_f91e2119;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace pure3d {
struct Plane_2927e0 { float x,y,z,w; };
}
namespace fn_f91e2119 {
typedef unsigned int u32_2928e0;
struct Receiver_2928e0 {
};
struct Entity_292910 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
struct Vec3_292970 {
    float x, y, z;
};
class Inner_292a10 {
  public:
};
struct Sub_292a50 {
};
class Camera {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void a11(void*, void*);
    virtual void vfunc_12(void*, Receiver_2928e0*);
    virtual void _m_vf13();
    virtual u32_2928e0 a14();
    virtual void f15(void*);
    virtual void f16(void*, void*);
    virtual void f17(int);
    virtual void vfunc_18(void*, void*);
    virtual int f19(void*);
    virtual void _m_vf20();
    virtual void _m_vf21();
    virtual void _m_vf22();
    virtual void _m_vf23();
    virtual void _m_vf24();
    virtual void _m_vf25();
    virtual void f26();
    char _m_pad_4[0x48];
    Sub_292a50 sub;
    char _m_pad_4d[0x7f];
    unsigned char flag;
    char _m_pad_cd[0x3];
};
class Manager_292b60 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28(int, int, int, int);
};
extern Manager_292b60* hulk_at_0052c2a8;
struct Block_292ba0 {
    int x[16];
};
class Receiver_292ba0 {
  public:
};
struct Helper_292c90 {
};
struct Vec3_292cc0 { float x, y, z; };
struct Matrix { float m[16]; };
struct Vec3Ops : Vec3_292cc0 {
};
class Display {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual float GetAspect();      // slot 16
};
union PosArg { const Vec3_292cc0 *p; float f; };
struct Out { float x, y; int z; };
class View {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void GetFov(float *a, float *b);    // slot 6
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12();
    virtual Matrix *GetMatrix();                // slot 13

    void FUN_00292cc0(PosArg pos, Out *out);
};
extern void* hulk_at_0042cedc[];
class Entity_292dc0 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class Camera_292dc0 : public Entity_292dc0 {
  public:
    Camera_292dc0* vfunc_5(signed char flags);
};

} // namespace fn_f91e2119

// 0x002926d0 pure3d::Camera::vfunc_5 (171 B): equivalent/0x002926d0.cpp [wrapped: conflict: pure3d::Camera]
// sym: ?vfunc_5@Camera@pure3d@fn_002926d0@@UAEXMM@Z @7ba91647ae32 @wc445f97fe05e
namespace fn_002926d0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::Camera::vfunc_5 @ 0x002926d0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl tan(double);
#endif
 
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sin(double);
#endif
 
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl cos(double);
#endif
 
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl atan(double);
#endif

struct Renderer_2926d0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual float s16(); }; 
namespace pure3d { struct Camera { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(float,float); char pad[12]; float fov,aspect,scaledAspect; char pad2[8]; float sx,sy,leftX,leftY,rightX,rightY,topX,topY,bottomX,bottomY; }; }
void pure3d::Camera::vfunc_5(float f,float a) { fov=f; aspect=a; float scale=(*(Renderer_2926d0**)&DAT_0052c2a4)->s16()*aspect; scaledAspect=scale; double half=fov*0.5; double t=tan(half); double reciprocal=1.0/t; sx=(float)reciprocal; sy=(float)(reciprocal*scale); float vertical=(float)atan(t/scale); float sh=(float)sin(half); double ch=cos(half); float sv=(float)sin(vertical); float cv=(float)cos(vertical); topX=cv; leftX=(float)-ch; leftY=-sh; rightX=(float)ch; rightY=-sh; topY=-sv; bottomX=-cv; bottomY=-sv; }
} // namespace fn_002926d0


// 0x00292780 pure3d::Camera::vfunc_6 (21 B): matches/0x00292780.cpp
// sym: ?vfunc_6@Camera@pure3d@@UAEXPAX0@Z
 // namespace pure3d
void pure3d::Camera::vfunc_6(void* __p0, void* __p1) { unsigned int * a = (unsigned int *)__p0; unsigned int * b = (unsigned int *)__p1;

    *a = this->f_10;
    *b = this->f_14;
}


// 0x002927a0 pure3d::Camera::vfunc_7 (10 B): matches/0x002927a0.cpp
// sym: ?vfunc_7@Camera@pure3d@@UAEXH@Z
// Same code shape as 0x001fb9b0 (propagated; names are from that function)
void pure3d::Camera::vfunc_7(int x) {
    (*(int *)&this->f_1c) = x;
}


// 0x002927b0 pure3d::Camera::vfunc_9 (10 B): matches/0x002927b0.cpp
// sym: ?vfunc_9@Camera@pure3d@@UAEXH@Z
// Same code shape as 0x00083d50 (propagated; names are from that function)
void pure3d::Camera::vfunc_9(int x) {
    (*(int *)&this->f_20) = x;
}


// 0x002927c0 pure3d::Camera::vfunc_8 (4 B): matches/0x002927c0.cpp
// sym: ?vfunc_8@Camera@pure3d@@UAEMXZ
// Same code shape as 0x00069070 (propagated; names are from that function)
hulk_freg pure3d::Camera::vfunc_8() {
    return this->f_1c;
}


// 0x002927d0 pure3d::Camera::vfunc_10 (4 B): matches/0x002927d0.cpp
// sym: ?vfunc_10@Camera@pure3d@@UAEMXZ
// Same code shape as 0x00069080 (propagated; names are from that function)
hulk_freg pure3d::Camera::vfunc_10() {
    return this->f_20;
}


// 0x002927e0 pure3d::Camera::vfunc_11 (188 B): equivalent/0x002927e0.cpp
// sym: ?vfunc_11@Camera@pure3d@@UAEXHH@Z @9191a344b355 @we38f3264df42
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/9)
// pure3d::Camera::vfunc_11 @ 0x002927e0
void pure3d::Camera::vfunc_11(int __p0, hulk_intptr __p1) { unsigned int which = (unsigned int)__p0; Plane_2927e0 * out = (Plane_2927e0 *)__p1;

switch(which) {
case 1: out->x=0; out->y=0; out->z=-1.0f; out->w=this->f_1c; break;
case 2: out->x=0; out->y=0; out->z=1.0f; out->w=-this->f_20; break;
case 4: { float z=this->f_40,y=this->f_3c; out->y=y; out->x=0; out->w=0; out->z=z; break; }
case 8: { float z=this->f_48,y=this->f_44; out->y=y; out->x=0; out->w=0; out->z=z; break; }
case 16: { float x=this->f_2c,z=this->f_30; out->x=x; out->z=z; out->y=0; out->w=0; break; }
case 32: { float z=this->f_38,x=this->f_34; out->z=z; out->x=x; out->y=0; out->w=0; break; }
}
}

namespace fn_f91e2119 {

// 0x002928e0 pure3d::Camera::vfunc_12 (41 B): matches/0x002928e0.cpp
// sym: ?vfunc_12@Camera@fn_f91e2119@@UAEXPAXPAUReceiver_2928e0@2@@Z
void Camera::vfunc_12(void* p2, Receiver_2928e0* p3) {
    a11(p2, p3);
    u32_2928e0 x = a14();
    ((owners::Obj_22e320 *)p3)->FUN_0022e320(x);
}

} // namespace fn_f91e2119

// 0x00292910 pure3d::Camera::vfunc_13 (23 B): matches/0x00292910.cpp
// sym: ?vfunc_13@Camera@pure3d@@UAEPAXXZ
 // namespace pure3d
void* pure3d::Camera::vfunc_13() {
    if (!this->f_cc)
        vfunc_26();
    return (void*)((char*)this + 0x4c);
}


// 0x00292930 pure3d::Camera::vfunc_14 (26 B): matches/0x00292930.cpp
// sym: ?vfunc_14@Camera@pure3d@@UAEPAXXZ
void* pure3d::Camera::vfunc_14() {
    if (!this->f_cc)
        vfunc_26();
    return (void*)((pure3d::Camera*)((char*)this + 0x8c));
}

namespace fn_f91e2119 {

// 0x00292950 pure3d::Camera::vfunc_15 (18 B): matches/0x00292950.cpp
// sym: ?target@fn_f91e2119@@YI_NPAVCamera@1@PAX1@Z
bool __fastcall target(Camera* self, void*, void* arg) {
    return self->f19(arg) == 0;
}

} // namespace fn_f91e2119

// 0x00292970 pure3d::Camera::vfunc_16 (146 B): matches/0x00292970.cpp
// sym: ?vfunc_16@Camera@pure3d@@UAEDPAXM@Z
char pure3d::Camera::vfunc_16(void* __p0, float r) { const Vec3_292970 * p = (const Vec3_292970 *)__p0;

    if (p->z + r < this->f_1c)
        return 0;
    if (p->z - r > this->f_20)
        return 0;
    if (this->f_2c * p->x + this->f_30 * p->z > r)
        return 0;
    if (this->f_34 * p->x + this->f_38 * p->z > r)
        return 0;
    if (this->f_40 * p->z + this->f_3c * p->y > r)
        return 0;
    if (this->f_48 * p->z + this->f_44 * p->y > r)
        return 0;
    return 1;
}

namespace fn_f91e2119 {

// 0x00292a10 pure3d::Camera::vfunc_17 (58 B): matches/0x00292a10.cpp
// sym: ?f17@Camera@fn_f91e2119@@UAEXH@Z
void Camera::f17(int arg) {
    char t[12];
    if (!flag)
        f26();
    ((owners::Mat_22c2b0 *)(((Inner_292a10*)((char*)this + 0x4c))))->FUN_0022c2b0((float *)(hulk_uintptr)(int)arg, (float *)t);
    f15(t);
}


// 0x00292a50 pure3d::Camera::vfunc_18 (63 B): matches/0x00292a50.cpp
// sym: ?vfunc_18@Camera@fn_f91e2119@@UAEXPAX0@Z
void Camera::vfunc_18(void* a, void* b) {
    char local[12];
    if (!flag)
        f26();
    ((owners::Mat_22c2b0 *)&sub)->FUN_0022c2b0((float *)a, (float *)local);
    f16(local, b);
}

} // namespace fn_f91e2119

// 0x00292a90 pure3d::Camera::vfunc_19 (143 B): equivalent/0x00292a90.cpp [wrapped: conflict: Camera]
// sym: ?vfunc_19@Camera@fn_00292a90@@UAEIPBUVec3_292a90@2@@Z @c9f89c28cd84 @w8835eaa6a7d1
namespace fn_00292a90 {
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 12/12)
// pure3d::Camera::vfunc_19 @ 0x00292a90
struct Vec3_292a90 {
    float x, y, z;
};

class Camera {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual unsigned int vfunc_19(const Vec3_292a90 *p);
    char pad04[0x14];
    float yScale;            // 0x18
    float nearDist;          // 0x1c
    float farDist;           // 0x20
    float xFactor;           // 0x24
    float yFactor;           // 0x28
};

// Frustum outcode of a point: bit 0/1 near/far, 2/3 top/bottom, 4/5 left/right.
unsigned int Camera::vfunc_19(const Vec3_292a90 *p) {
    unsigned int code = 0;
    hulk_freg z = p->z;
    hulk_freg x = xFactor * p->x;
    hulk_freg y = yFactor * p->y;
    if (z > farDist)
        code = 2;
    else if (z < nearDist)
        code = 1;
    if (y * yScale > z)
        code |= 4;
    else if (-(y * yScale) > z)
        code |= 8;
    if (x > z)
        code |= 0x20;
    else if (-x > z)
        code |= 0x10;
    return code;
}
} // namespace fn_00292a90


// 0x00292b20 pure3d::Camera::vfunc_20 (52 B): matches/0x00292b20.cpp
// sym: ?vfunc_20@Camera@pure3d@@UAEXPAX@Z
void pure3d::Camera::vfunc_20(void* __p0) { unsigned long * out = (unsigned long *)__p0;

    if (!this->f_cc)
        vfunc_26();
    out[0] = this->f_bc;
    out[1] = this->f_c0;
    out[2] = this->f_c4;
}


// 0x00292b60 pure3d::Camera::vfunc_22 (64 B): matches/0x00292b60.cpp
// sym: ?vfunc_22@Camera@pure3d@@UAEXXZ
void pure3d::Camera::vfunc_22() {
    vfunc_5((*(int *)&this->f_10), (*(int *)&this->f_14));
    if (!this->f_cc)
        vfunc_26();
    hulk_at_0052c2a8->f28((*(int *)&this->f_1c), (*(int *)&this->f_20), (*(int *)&this->f_10), this->f_18);
}


// 0x00292ba0 pure3d::Camera::vfunc_26 (36 B): matches/0x00292ba0.cpp
// sym: ?vfunc_26@Camera@pure3d@@UAEXXZ
void pure3d::Camera::vfunc_26() {
    Block_292ba0* dst = (Block_292ba0*)((char*)this + 0x4c);
    this->f_cc = 1;
    *dst = *(Block_292ba0*)((char*)this + 0x8c);
    ((owners::Matrix_22c120 *)(((Receiver_292ba0*)dst)))->FUN_0022c120();
}


// 0x00292bd0 pure3d::Camera::vfunc_25 (109 B): matches/0x00292bd0.cpp
// sym: ?vfunc_25@Camera@pure3d@@UAEXPAX00@Z
// x87: the two reciprocals stay in registers (53 bits)
void pure3d::Camera::vfunc_25(void* __p0, void* __p1, void* __p2) { float * x = (float *)__p0; float * y = (float *)__p1; float * z = (float *)__p2;

    hulk_freg q = 1.0f / this->f_1c;
    hulk_freg r = 1.0f / this->f_20;
    y[0] = *x / (q * this->f_24 * 0.5f);
    y[1] = x[1] / (q * this->f_28 * 0.5f);
    y[2] = this->f_1c;
    z[0] = *x / (r * this->f_24 * 0.5f);
    z[1] = x[1] / (r * this->f_28 * 0.5f);
    z[2] = this->f_20;
}


// 0x00292c40 pure3d::Camera::vfunc_24 (69 B): matches/0x00292c40.cpp [wrapped: conflict: pure3d::Camera]
// sym: ?vfunc_24@Camera@pure3d@fn_00292c40@@UAEXMMM@Z
namespace fn_00292c40 {
namespace pure3d {
class Camera {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23(float*, float);
    virtual void vfunc_24(float, float, float);
    virtual void f25(float, float*, float*);
    virtual void f26();
};
void Camera::vfunc_24(float a, float b, float c) {
    float p[3];
    float q[3];
    f25(a, p, q);
    f23(p, b);
    f23(q, c);
}
} // namespace pure3d
} // namespace fn_00292c40


// 0x00292c90 pure3d::Camera::vfunc_23 (43 B): matches/0x00292c90.cpp
// sym: ?vfunc_23@Camera@pure3d@@UAEXHH@Z
void pure3d::Camera::vfunc_23(int a, int b) {
    if (!this->f_cc)
        vfunc_26();
    ((owners::Mat_22c2b0 *)(((Helper_292c90*)((char*)this + 0x8c))))->FUN_0022c2b0((float *)(hulk_uintptr)(int)a, (float *)(hulk_uintptr)(int)b);
}

namespace fn_f91e2119 {

// 0x00292cc0 FUN_00292cc0 (168 B): matches/0x00292cc0.cpp
// sym: ?FUN_00292cc0@View@fn_f91e2119@@QAEXTPosArg@2@PAUOut@2@@Z
// FUN_00292cc0 @ 0x00292cc0
// Screen-space scale of a point: projects the point through the view, then writes
// (x, y) scale factors derived from the field of view and aspect ratio, and the depth.
void View::FUN_00292cc0(PosArg pos, Out *out)
{
    struct Frame {
        float b;
        float a;
        Vec3Ops v;
    } fr;
    ((owners::C_22d240 *)&(fr.v))->FUN_0022d240((hulk_intptr)(const Vec3_292cc0 *)(pos.p), (hulk_intptr)(const Matrix *)(GetMatrix()));
    if (fr.v.z != 0.0f) {
        pos.f = 1.0f / fr.v.z;      // the argument slot is reused for 1/z
        GetFov(&fr.a, &fr.b);
        #if defined(__clang__)
        hulk_freg aspect = (*(Display**)&DAT_0052c2a4)->GetAspect() * fr.b; // kept unrounded by the original
#else
        float aspect = (*(Display**)&DAT_0052c2a4)->GetAspect() * fr.b;
#endif
        out->z = *(int *)&fr.v.z;
        #if defined(__clang__)
        hulk_freg cot = 1.0f / tan(fr.a * 0.5f);
#else
        float cot = 1.0f / (float)tan(fr.a * 0.5f);
#endif
        out->x = (float)(fr.v.x * cot * pos.f * 0.5f);
        out->y = (float)((cot * aspect) * fr.v.y * pos.f * 0.5f);
    }
}

} // namespace fn_f91e2119

// 0x00292d70 FUN_00292d70 (75 B): matches/0x00292d70.cpp [wrapped: conflict: Camera]
// sym: ??0Camera@fn_00292d70@@QAE@XZ
namespace fn_00292d70 {
class Entity_292d70 {
  public:
    virtual void b0();
    Entity_292d70();
};
class Camera : public Entity_292d70 {
  public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void hulk_slot_vfunc_5(float, float) = 0; void vfunc_5_002926d0(float, float);
    char p0[0x18];
    float a;
    float b;
    char p1[0x28];
    struct Sub {
        char x[0x40];
        void init_0022b980();
    } sub1, sub2;
    unsigned char flag;
    Camera();
};
Camera::Camera() : Entity_292d70() {
    vfunc_5_002926d0(1.5707964f, 1.0f);
    a = 1.0f;
    b = 1000.0f;
    sub1.init_0022b980();
    sub2.init_0022b980();
    flag = 1;
}
} // namespace fn_00292d70

namespace fn_f91e2119 {

// 0x00292dc0 pure3d::Camera::vfunc_2 (36 B): matches/0x00292dc0.cpp
// sym: ?vfunc_5@Camera_292dc0@fn_f91e2119@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Camera_292dc0* Camera_292dc0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042cedc;
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f91e2119

// 0x00292df0 FUN_00292df0 (119 B): matches/0x00292df0.cpp [wrapped: conflict: Camera]
// sym: ??0Camera@fn_00292df0@@QAE@PAUSrc_292df0@1@@Z
namespace fn_00292df0 {
struct Mat_292df0 {
    float m[16];
    void Init_0022b980();
};
struct Src_292df0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual float F8();
    virtual void v9();
    virtual float F10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual Mat_292df0* GetMat();
    int pad[3];
    int a, b;
};
struct Entity_292df0 {
    Entity_292df0(Src_292df0* s);
    virtual void bv();
    int pad[6];
};
struct Camera : Entity_292df0 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void hulk_slot_Set(int a, int b); void Set_002926d0(int a, int b);
    Camera(Src_292df0* s);
    float f1c, f20;
    char p[0x28];
    Mat_292df0 m4c, m8c;
    char flag;
};
Camera::Camera(Src_292df0* s) : Entity_292df0(s) {
    Set_002926d0(s->a, s->b);
    f1c = s->F8();
    f20 = s->F10();
    m4c.Init_0022b980();
    m8c.Init_0022b980();
    m8c = *s->GetMat();
    m4c.Init_0022b980();
    flag = 0;
}
} // namespace fn_00292df0


// 0x00292e70 pure3d::Camera::vfunc_21 (56 B): matches/0x00292e70.cpp [wrapped: conflict: pure3d::Camera]
// sym: ?vfunc_21@Camera@pure3d@fn_00292e70@@QAEXPBI@Z
namespace fn_00292e70 {
typedef unsigned int u32_292e70;
namespace pure3d {
struct Sub_292e70 {
    void update_0022c120();
};
struct Block_292e70 {
    u32_292e70 v[16];
};
struct Camera {
    char pad[0x8c];
    Block_292e70 field;
    char flag;
    void vfunc_21(const u32_292e70* p);
};
void Camera::vfunc_21(const u32_292e70* p) {
    field = *(const Block_292e70*)p;
    flag = 1;
    *(Block_292e70*)((char*)this + 0x4c) = field;
    ((Sub_292e70*)((char*)this + 0x4c))->update_0022c120();
}
} // namespace pure3d
} // namespace fn_00292e70

