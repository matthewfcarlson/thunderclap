// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000a8340..0x000a9050 (kind game, layer game, confidence high), dominant class CDramaticCamera
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6c39404 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6c39404 {} using namespace fn_f6c39404;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6c39404 {
class X_a8340 {
  public:
    X_a8340();
};
void *thunk_FUN_0008d690(unsigned int size);
struct ResourceName_a8400 {
    int word;
    void FUN_0027b040(const char *name);
};
class Target;
class VectorCamera_a8400 {
public:
    virtual void AddRef();
    VectorCamera_a8400 *FUN_002939a0();
};
class CameraAnimationController_a8400 {
public:
    virtual void AddRef();
    CameraAnimationController_a8400 *FUN_00292eb0();
    void FUN_00293100(VectorCamera_a8400 *rig);
};
class __declspec(novtable) CGameCamera_a8400 {
public:
    virtual void v0();
    char pad04[4];
    ResourceName_a8400 name;      // 0x08
    char pad0c[0xd0 - 0xc];
    int mode;               // 0xd0
    char padd4[0x170 - 0xd4];
    CGameCamera_a8400 *FUN_000a9400();
    CGameCamera_a8400() { FUN_000a9400(); }
};
struct Mat {
    int d[16];
};
class Device {
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
    virtual void Set0(int);
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
    virtual void Set1(int, int, int);
};
class Obj {
    char pad[0x170];
    Device* dev;
    char pad2[4];
    int value;
    float amount;
    Mat mat;

  public:
    void Fn(hulk_intptr, int, const Mat*);
};
struct Vec3_a8670 {
    float x, y, z;
    char FUN_0022d2b0(const Vec3_a8670 *other, float eps) const;
};
class Curve_a8670 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual float v11();
    virtual void v12(float t);
};
struct Follower_a8670 {
    char pad0[0xd0];
    Vec3_a8670 position;
};
struct Matrix {
    float m[16];
};
struct PathSampler {
    char pad0[0x170];
    Curve_a8670 *curve;
    Follower_a8670 *follower;
    char pad178[8];
    Matrix transform;
    int FUN_000a8670(Vec3_a8670 *out, int count);
};
struct Sphere_a8890 { float x,y,z,radius; };
struct Box_a8890 { float minX,minY,minZ,maxX,maxY,maxZ; Sphere_a8890* FUN_000a8890(Sphere_a8890* out); };
extern void* hulk_at_00405754[];
class Ref_a8970 {
  public:
    virtual void F0();
    virtual void Release();
};
class CGameCamera_a8970 {
  public:
    void* vptr;
    void Fin_000a9620();
};
class CDramaticCamera_a8970 : public CGameCamera_a8970 {
  public:
    char pad[0x170 - 4];
    Ref_a8970* m170;
    Ref_a8970* m174;
    ~CDramaticCamera_a8970();
};
struct Vec3_a8f70 {
    float x, y, z;
};
struct Mat_a8f70 {
    char pad[0x20];
    Vec3_a8f70 a;
    float padf;
    Vec3_a8f70 b;
};
class CDramaticCamera : public CGameCamera_a8400 {
  public:
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
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual Mat_a8f70* GetMat();
    virtual void _m_vf15();
    virtual void _m_vf16();
    virtual void _m_vf17();
    virtual void _m_vf18();
    virtual void _m_vf19();
    virtual void _m_vf20();
    virtual void _m_vf21();
    virtual void _m_vf22();
    virtual void _m_vf23();
    virtual void _m_vf24();
    virtual void _m_vf25();
    virtual void _m_vf26();
    virtual void vfunc_27(Vec3_a8f70* out);
    CDramaticCamera();
    CameraAnimationController_a8400 *controller;
    VectorCamera_a8400 *rig;
    float f178;
};


// 0x000a8340 FUN_000a8340 (3 B): matches/0x000a8340.cpp
// sym: ??0X_a8340@fn_f6c39404@@QAE@XZ
X_a8340::X_a8340() {}


// 0x000a8400 FUN_000a8400 (150 B): equivalent/0x000a8400.cpp
// sym: ??0CDramaticCamera@fn_f6c39404@@QAE@XZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000a8400 @ 0x000a8400
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
CDramaticCamera::CDramaticCamera()
{
    mode = 1;
    name.FUN_0027b040((*(const char**)&DAT_0049ed3c));
    void *mem = thunk_FUN_0008d690(0x118);
    CameraAnimationController_a8400 *c = 0;
    if (mem != 0)
        c = ((CameraAnimationController_a8400 *)mem)->FUN_00292eb0();
    controller = c;
    c->AddRef();
    mem = thunk_FUN_0008d690(0xf8);
    VectorCamera_a8400 *r = 0;
    if (mem != 0)
        r = ((VectorCamera_a8400 *)mem)->FUN_002939a0();
    rig = r;
    r->AddRef();
    controller->FUN_00293100(rig);
    f178 = 1.0f;
}


// 0x000a84a0 CDramaticCamera::vfunc_28 (1 B): matches/0x000a84a0.cpp
// sym: ?FUN_000a84a0@fn_f6c39404@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000a84a0() {}


// 0x000a84b0 CDramaticCamera::vfunc_29 (1 B): matches/0x000a84b0.cpp
// sym: ?FUN_000a84b0@fn_f6c39404@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000a84b0() {}


// 0x000a84c0 FUN_000a84c0 (81 B): matches/0x000a84c0.cpp
// sym: ?Fn@Obj@fn_f6c39404@@QAEXHHPBUMat@2@@Z
void Obj::Fn(hulk_intptr a, int b, const Mat* m) {
    dev->Set1(a, 0, 0);
    dev->Set0(0);
    mat = *m;
    value = b;
    amount = 0.3f;
}


// 0x000a8670 FUN_000a8670 (306 B): equivalent/0x000a8670.cpp
// sym: ?FUN_000a8670@PathSampler@fn_f6c39404@@QAEHPAUVec3_a8670@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 14682 inputs, branch coverage 14/14)
// FUN_000a8670 @ 0x000a8670
int PathSampler::FUN_000a8670(Vec3_a8670 *out, int count)
{
    if (curve == 0)
        return -1;

    float length = curve->v11();
    int written = 0;
    int lastIndex = 0;
    Vec3_a8670 last;
    Vec3_a8670 pos;

    if (count > 0) {
        volatile float denom = (float)(count - 1); // volatile: MSVC would turn the division into a reciprocal multiply
        lastIndex = count - 1;
        for (int i = 0; i < count; i++) {
            curve->v12((float)i * length / denom);
            curve->v7();
            pos = follower->position;
            if (i != 0) {
                if (pos.FUN_0022d2b0(&last, 1e-5f))
                    continue;
                if (i != lastIndex && pos.FUN_0022d2b0(&last, 0.1f))
                    continue;
            }
            last = pos;
            ((owners::Obj_22d210 *)&pos)->FUN_0022d210((owners::Obj_22d210 *)(const Matrix *)(&transform));
            out[written] = pos;
            written++;
        }
    }
    return written;
}

} // namespace fn_f6c39404

// 0x000a87f0 FUN_000a87f0 (148 B): matches/0x000a87f0.cpp
// sym: ?FUN_000a87f0@V_a87f0@owners@@QAEXPAU12@@Z
void owners::V_a87f0::FUN_000a87f0(owners::V_a87f0* p) {
    v[0] = (v[0] < p->v[0]) ? v[0] : p->v[0];
    v[1] = (v[1] < p->v[1]) ? v[1] : p->v[1];
    v[2] = (v[2] < p->v[2]) ? v[2] : p->v[2];
    v[3] = (v[3] < p->v[0]) ? p->v[0] : v[3];
    v[4] = (v[4] < p->v[1]) ? p->v[1] : v[4];
    v[5] = (v[5] < p->v[2]) ? p->v[2] : v[5];
}

namespace fn_f6c39404 {

// 0x000a8890 FUN_000a8890 (217 B): equivalent/0x000a8890.cpp
// sym: ?FUN_000a8890@Box_a8890@fn_f6c39404@@QAEPAUSphere_a8890@2@PAU32@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 6/6)
// FUN_000a8890 @ 0x000a8890
// FUN_000a8890 @ 0x000a8890
Sphere_a8890* Box_a8890::FUN_000a8890(Sphere_a8890* out) {
 float x,y,z,r;
 if (!(minX > maxX) && !(minY > maxY) && !(minZ > maxZ)) {
  volatile float hx = (maxX-minX)*0.5f;
  volatile float dz = maxZ-minZ;
  double hy = ((double)maxY-minY)*0.5;
  double hz = (double)dz*0.5;
  x = hx+minX; y = (float)(hy+minY); z = (float)(hz+minZ);
  double zy = hz*hz+hy*hy; // keep the original's summation order
  r = (float)sqrt(zy+(double)hx*hx);
 } else { x=y=z=r=0.0f; }
 out->radius=r; out->x=x; out->y=y; out->z=z;
    return out;
}


// 0x000a8970 FUN_000a8970 (67 B): matches/0x000a8970.cpp
// sym: ??1CDramaticCamera_a8970@fn_f6c39404@@QAE@XZ
CDramaticCamera_a8970::~CDramaticCamera_a8970() {
    vptr = hulk_at_00405754;
    _ReadWriteBarrier();
    if (m170) {
        m170->Release();
        m170 = 0;
    }
    if (m174) {
        m174->Release();
        m174 = 0;
    }
    Fin_000a9620();
}


// 0x000a8f70 CDramaticCamera::vfunc_27 (101 B): matches/0x000a8f70.cpp
// sym: ?vfunc_27@CDramaticCamera@fn_f6c39404@@UAEXPAUVec3_a8f70@2@@Z
void CDramaticCamera::vfunc_27(Vec3_a8f70* out) {
    Vec3_a8f70 d;
    Vec3_a8f70* f = &GetMat()->a;
    d.x = f->x * 10.0f;
    d.y = f->y * 10.0f;
    d.z = f->z * 10.0f;
    Vec3_a8f70* p = &GetMat()->b;
    float z = d.z + p->z;
    float y = d.y + p->y;
    float x = d.x + p->x;
    out->x = x;
    out->y = y;
    out->z = z;
}

} // namespace fn_f6c39404

// 0x000a8fe0 CDramaticCamera::vfunc_2 (88 B): matches/0x000a8fe0.cpp [wrapped: conflict: CDramaticCamera]
// sym: ?vfunc_2@CDramaticCamera@fn_000a8fe0@@QAEPAXE@Z
namespace fn_000a8fe0 {
extern int CDramaticCamera_vftable;

struct IRelease {
    virtual void v0();
    virtual void Release();
};

class CDramaticCamera {
  public:
    IRelease* volatile mVftable;
    char pad[0x170 - 4];
    IRelease* volatile a;
    IRelease* volatile b;
    void BaseCleanup_000a9620();
    void* vfunc_2(unsigned char flag);
};

extern "C++" __declspec(nothrow) void __cdecl DeleteObj_00263f30(void* p);

void* CDramaticCamera::vfunc_2(unsigned char flag) {
    mVftable = (IRelease*)&CDramaticCamera_vftable;
    IRelease* pa = a;
    if (pa != 0) {
        pa->Release();
        a = 0;
    }
    IRelease* pb = b;
    if (pb != 0) {
        pb->Release();
        b = 0;
    }
    BaseCleanup_000a9620();
    if (flag & 1) {
        DeleteObj_00263f30(this);
    }
    return this;
}
} // namespace fn_000a8fe0

