// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024cc00..0x0024d210 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f96c52ec {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f96c52ec {} using namespace fn_f96c52ec;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f96c52ec {
struct Light {
    float pos[3];
    char pad[0x24 - 12];
    float dir[3];
    float nearD;
    float farD;
    float k;
    float extra;
    char Check(const Light* l, int key) const;
};
struct Obj_24cc00 {
    float x, y, z;
    char Check_0022d2b0(const Light* l, int key) const;
};
extern float Dot_0025e5f0(const float* a, const float* b);
struct Body_24ccb0 {
 float x,y,z,vx,vy,vz; char pad[0x18]; float a,b;
 bool FUN_0022d2b0(Body_24ccb0*,float);
};
struct Vec3_24ce50 { float x,y,z; };
struct Source_24ce50 { float x,y,z; char pad[12]; float vx,vy,vz; };
struct Vec3_24cf20 {
    float x, y, z;
};
struct Edge_24cf20 {
    Vec3_24cf20 origin;
    char pad0c[0x18 - 0xc];
    Vec3_24cf20 axis;
    Vec3_24cf20 side;
    char pad30[0x3c - 0x30];
    char clampMode;
    bool FUN_0022d2b0(const Vec3_24cf20 *p, float eps);
};
struct Obj_24d140 {
    char pad[0x54];
    float value;
    float slot58;
    float slot5c;
    float slot60;
};
float __cdecl f1_0024ce50(int, Obj_24d140*);
float __cdecl f2_0024cc00(int, Obj_24d140*);
float __cdecl f3_0024cdd0(int, Obj_24d140*);
float __cdecl f4_0024ccb0(int, Obj_24d140*);
extern "C" void __cdecl FUN_0024cf20(void *, const void *, float *, float *);


// 0x0024cc00 FUN_0024cc00 (166 B): matches/0x0024cc00.cpp
// sym: ?FUN_0024cc00@fn_f96c52ec@@YAMPBUObj_24cc00@1@PBULight@1@@Z
hulk_freg FUN_0024cc00(const Obj_24cc00* p, const Light* l) {
    float d;
    if (p->Check_0022d2b0(l, 0x3727c5ac) == 0) {
        float v[3];
        v[0] = p->x - l->pos[0];
        v[1] = p->y - l->pos[1];
        v[2] = p->z - l->pos[2];
        d = Dot_0025e5f0(l->dir, v);
    } else {
        d = 0.0f;
    }
    if (d <= l->nearD)
        return 1.0f;
    if (l->nearD < d && d < l->farD)
        return (d - l->nearD) / (l->farD - l->nearD) * (1.0f - l->k);
    return l->k;
}


// 0x0024ccb0 FUN_0024ccb0 (285 B): equivalent/0x0024ccb0.cpp
// sym: ?FUN_0024ccb0@fn_f96c52ec@@YAMPAUBody_24ccb0@1@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 16/16)
// FUN_0024ccb0 @ 0x0024ccb0
hulk_freg __cdecl FUN_0024ccb0(Body_24ccb0* p, Body_24ccb0* q) {
 double value;
 if (p->FUN_0022d2b0(q,0.00001f)) value=0.0;
 else {
 double x=(double)p->x-q->x, y=(double)p->y-q->y, z=(double)p->z-q->z;
 value=-(((double)p->vz-q->vz)*z+((double)p->vy-q->vy)*y+((double)p->vx-q->vx)*x)/sqrt(z*z+y*y+x*x);
 }
 double scaled=value*p->a; // MSVC would reassociate value*a*b into value*(a*b)
 value=scaled*p->b;
 if(value>0.0) {
 if(value>=345.0) value=344.99f;
 value=345.0/(345.0-value);
 } else if(value<0.0) {
 if(value<=-345.0) value=-344.99f;
 value=1.0/(345.0/(value+345.0));
 } else return 1.0f;
 if(value>=0.5 && value<=1.5) return (hulk_freg)value;
 if(value>1.5) return 1.5f;
 return 0.5f;
}


// 0x0024cdd0 FUN_0024cdd0 (114 B): matches/0x0024cdd0.cpp
// sym: ?FUN_0024cdd0@fn_f96c52ec@@YAMPAM0@Z
// data: gOne_24cdd0 = DAT_003f32dc, gZero_24cdd0 = DAT_003f32e0
hulk_freg FUN_0024cdd0(float* a, float* b) {
    hulk_freg x = a[0] - b[0];
    hulk_freg y = a[1] - b[1];
    hulk_freg z = a[2] - b[2];
    double s = sqrt(y * y + z * z + x * x);  // the listing's order (MSVC 7.1 reassociates; clang does not)
    float d = (float)s;
    if ((float)s <= b[15])
        return DAT_003f32dc;
    if (d >= b[16])
        return DAT_003f32e0;
    hulk_freg r = pow(b[17], (d - b[15]) / (b[16] - b[15]));     // x87: the original returns __CIpow's st0 unrounded
    _ReadWriteBarrier();
    return r;
}


// 0x0024ce50 FUN_0024ce50 (208 B): equivalent/0x0024ce50.cpp
// sym: ?FUN_0024ce50@fn_f96c52ec@@YAMPBUSource_24ce50@1@PBUVec3_24ce50@1@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 6/6)
// FUN_0024ce50 @ 0x0024ce50
hulk_freg __cdecl FUN_0024ce50(const Source_24ce50* a, const Vec3_24ce50* b) {
    double x=(double)a->x-b->x;
    double y=(double)a->y-b->y;
    double z=(double)a->z-b->z;
    float distance=(float)sqrt(z*z+y*y+x*x);
    double negativeDot=y*a->vy*-1.0f-z*a->vz-x*a->vx;
    double length=sqrt((double)a->vx*a->vx+(double)a->vy*a->vy+(double)a->vz*a->vz);
    float ratio=(float)(negativeDot/(length*distance));
    if(distance==0.0f || ratio>0.0f) return 1.0f;
    if(ratio > -0.58f) return 1.0f-ratio*-0.862069f;
    return 0.5f;
}


// 0x0024cf20 FUN_0024cf20 (540 B): equivalent/0x0024cf20.cpp
// sym: _FUN_0024cf20
// STATUS: equivalent (tools/equiv.py level 3: 20031 inputs, branch coverage 16/18, incomplete)
// FUN_0024cf20 @ 0x0024cf20
extern "C" void FUN_0024cf20(void * e_, const void *p, float *outCross, float *outAlong)
{
    Edge_24cf20 * e = (Edge_24cf20 *)e_;
    double q;
    if (e->FUN_0022d2b0(((const Vec3_24cf20 *)p), 1e-5f)) {
        q = 0.0f;
    } else {
        // the offset is a rounded frame copy in the original
        struct { volatile float x, y, z; } d;
        d.x = e->origin.x - ((const Vec3_24cf20 *)p)->x;
        d.y = e->origin.y - ((const Vec3_24cf20 *)p)->y;
        d.z = e->origin.z - ((const Vec3_24cf20 *)p)->z;
        double c0 = e->side.z * e->axis.y - e->side.y * e->axis.z;
        double c1 = e->side.x * e->axis.z - e->side.z * e->axis.x;
        double c2 = e->side.y * e->axis.x - e->side.x * e->axis.y;
        double t = d.z * c2 + c1 * d.y + c0 * d.x;
        double lc = sqrt(c2 * c2 + c1 * c1 + c0 * c0);
        double ld = sqrt(d.z * d.z + d.y * d.y + d.x * d.x);
        q = t / (lc * ld);
    }
    *outCross = (float)q;

    if (e->clampMode != 1) {
        *outAlong = 0.0f;
    } else {
        double r;
        if (e->FUN_0022d2b0(((const Vec3_24cf20 *)p), 1e-5f)) {
            r = 0.0f;
        } else {
            struct { volatile float x, y, z; } d;
            d.x = e->origin.x - ((const Vec3_24cf20 *)p)->x;
            d.y = e->origin.y - ((const Vec3_24cf20 *)p)->y;
            d.z = e->origin.z - ((const Vec3_24cf20 *)p)->z;
            double s = d.z * e->axis.z + d.y * e->axis.y + d.x * e->axis.x;
            double la = sqrt(e->axis.x * e->axis.x + e->axis.y * e->axis.y + e->axis.z * e->axis.z);
            double ld = sqrt(d.z * d.z + d.y * d.y + d.x * d.x);
            r = -(s / (la * ld));
        }
        *outAlong = (float)r;
        if (r >= -1.0f && r <= 1.0f) {
            *outAlong = *outAlong;
        } else if (r > 1.0f) {
            *outAlong = 1.0f;
        } else {
            *outAlong = -1.0f;
        }
    }

    float v = *outCross;
    if (v >= -1.0f && v <= 1.0f) {
        *outCross = *outCross;
    } else if (v > 1.0f) {
        *outCross = 1.0f;
    } else {
        *outCross = -1.0f;
    }
}


// 0x0024d140 FUN_0024d140 (81 B): matches/0x0024d140.cpp
// sym: _FUN_0024d140
extern "C" void __cdecl FUN_0024d140(int a, Obj_24d140* b) {
    // MSVC evaluates the operands right to left: f1, then f2, then f3
    float x1 = f1_0024ce50(a, b);
    float x2 = f2_0024cc00(a, b) * x1;
    b->value = f3_0024cdd0(a, b) * x2;
    b->slot60 = f4_0024ccb0(a, b);
    FUN_0024cf20((void *)(hulk_uintptr)(int)a, (Obj_24d140 *)b, &b->slot58, &b->slot5c);
}


// 0x0024d200 FUN_0024d200 (6 B): matches/0x0024d200.cpp
// sym: _FUN_0024d200
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024d200() {
    return &(*(int*)&DAT_004e62d8);
}

} // namespace fn_f96c52ec
