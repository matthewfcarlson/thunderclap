// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00224ce0..0x00225ef0 (kind game, layer engine, confidence high), dominant class choreo2::AnimationDriver
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/choreo2.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/choreo2.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe002747 {
#define TREE_TU_END }
namespace fn_fe002747 {} using namespace fn_fe002747;
#include "engine/choreo2.h"

// ---- declarations shared by the functions below
namespace fn_fe002747 {
struct Mat4_224ce0 {
    float m[16];
};
struct Quat_224ce0 {
    float q[4];
                             // from rotation matrix
    void FUN_0022b650(Mat4_224ce0 *out);                             // to rotation matrix
     // spherical interpolation
};
} // namespace fn_fe002747
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sin(double);
#endif
namespace fn_fe002747 {
struct Vec_224db0 { float x,y,z; };
struct Matrix {
  public:
    float m[4][4];
};
union FU_224ea0 {
    float f;
    unsigned u;
};
__forceinline float Abs(float x) {
    FU_224ea0 t;
    t.f = x;
    t.u &= 0x7fffffff;
    return t.f;
}
struct Vec3_224f10 { float x,y,z; };
extern hulk_freg __cdecl FUN_00224ea0(float x, float z);
float Helper_0004af40(float, float, float);
extern "C" char DAT_00427368[];
struct Inner_225000 {
    virtual void A();
    virtual void B();
};
struct AnimationDriver_nv_225000 {
    void Tail_002222d0();
};
struct Id_225030 {
    int lo;
    int hi;
};
struct Table_225030 {
    char pad00[0x10];
    unsigned int count;
    char pad14[0x10];
    Id_225030 *ids;
};
struct Pair_225030 {
    int trans;
    int rot;
};
struct Channel_225030;
struct Skeleton_225030 {
    virtual void AddRef();
    virtual void Release();
    Channel_225030 *FUN_00288ad0(int lo, int hi);
};
struct Channel_225030 {
    int FUN_00288960(int a, int b);
};
class Inner_2250e0 {
    char pad[0x10];

  public:
    float value;
};
class AnimationDriver_2250e0 {
    char pad[0x20];

  public:
    Inner_2250e0* p;
    char pad2[0x208];
    float result;
    void set(float x);
};
struct Inner_225140 {
    char pad[0x10];
    float f;
};
class AnimationDriver_225140 {
  public:
    char pad[0x20];
    Inner_225140* p;
    char pad2[0x20c];
    float value;
    void Set(float x);
};
struct Vec_2251d0 { float x,y,z; };
struct Vec4_2251d0 { float x,y,z,w; };
struct Quat_2251d0 { float x,y,z,w; void FUN_0022b650(Matrix*); };
extern "C" void __cdecl FUN_0022b080(float *, const float *, const float *);
struct Input_2251d0 { Quat_2251d0* FUN_00221cd0(); Matrix* FUN_00221c40(); };
struct PairSource { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void sample(void*,void*,Vec_2251d0*); };
struct SingleSource { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void sample(void*,Vec4_2251d0*); };
struct AnimationDriver_2251d0 { char pad0[0x24]; PairSource* pair; SingleSource* single; char pad1[0x228-0x2c]; float direction; void run(Input_2251d0*,void*,void*,Vec_2251d0*); };
struct Quat_225300 {
    float x, y, z, w;
};
struct Vec3_225300 {
    float x, y, z;
};
struct Mat4_225300 {
    char pad00[0x30];
    Vec3_225300 pos;
    float w;
};
class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(int track, Vec3_225300* out);
    virtual void vf5(int track, Quat_225300* out);
    void FUN_0028a8f0(int a, int b, Quat_225300* out);
};
class Pose {
public:
    char pad0[0x30];
    Vec3_225300 position;
    char pad1[0x50 - 0x3c];
    int state;
    Quat_225300* FUN_00221cd0();
    void FUN_00221cf0(Quat_225300* q);
};
struct PoseData_225300 {
    char pad00[0x10];
    Quat_225300* quats;
    Mat4_225300* mats;
};
struct SourceData {
    char pad00[0x14];
    Quat_225300* quats;
    Mat4_225300* mats;
};
struct Mask_225300 {
    int pad00;
    unsigned int bits[1];
};
struct Filter_225300 {
    char pad00[0x10];
    Mask_225300* mask;
};
struct Frame_225300 {
    union {
        Quat_225300 root;
        Vec3_225300 cur;
        Vec3_225300 old;
    };
    union {
        Quat_225300 qb;
        Vec3_225300 tgt;
        Vec3_225300 pos;
    };
    union {
        Quat_225300 qa;
        Quat_225300 dst;
    };
    Quat_225300 src;
};
struct Pair_225300 {
    Channel* pos;
    Channel* rot;
};
struct Query_225800 { char pad[8]; int first; int second; };
struct Tracks {
 bool FUN_00288d10(int, int, int, int*, int*);
 float FUN_00288de0(int, int, int, int);
};
} // namespace fn_fe002747
namespace choreo2 {
struct AnimationDriver_nv_225800 {
    bool FUN_00222330(Query_225800*);
};
}
namespace fn_fe002747 {
class AnimationDriver_225a20 {
  public:
    char pad0[0x20];
    int value20;
    char pad[0x200];
    char b224;
    char b225;
    char pad226[2];
    int d228;
    int d22c;
    int d230;
    char b234;
    char b235;
    char pad236[2];
    int d238;
    int d23c;
    void First_00222460(AnimationDriver_225a20*);
    AnimationDriver_225a20* Copy(AnimationDriver_225a20*);
};
struct AnimationDriver_225b30 {
    char pad[0x224];
    unsigned char a;
    unsigned char b;
    float fallback_00225ab0();
    float target();
};
hulk_freg __cdecl FUN_0004af40(float lo, float hi, float v);
struct EntityData { char pad[0x14]; float scale; };
struct Object {
 char pad0[0x20]; EntityData* data;
 char pad1[0x200]; unsigned char flag;
 char pad2[3]; float factor;
 int valueA;
 int valueB;
 char pad3[8]; float offset;
 hulk_freg FUN_00225c90(float amount);
};
hulk_freg __cdecl FUN_00225be0(float, int, int, unsigned char, unsigned char, int, int);
extern hulk_freg __cdecl FUN_00225be0(int, int, int, unsigned char);
struct This_GetValue {
    float GetValue_00225c90(int);
};
extern "C" void* __cdecl alloc(hulk_uintptr);
struct AnimationDriver_225da0 {
    hulk_intptr v;
    void InitA_00222590(void*);
    void InitB_00225a20(void*);
};
struct Factory_225da0 {
    AnimationDriver_225da0* Make();
};
struct V3_225e00 {
    float x, y, z;
};
struct Node {
    char pad0[0x10];
    float f10;              // 0x10
};
class AnimationDriver {
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
    virtual void vfunc_10(Pose* from, Pose* to, PoseData_225300* data, float t);
    char _m_pad_4[0xc];
    SourceData* source;
    Filter_225300* filter;
    unsigned int first;
    unsigned int last;
    Node *node;
    Pair_225300 pairs[1];
    char _m_pad_2c[0x1f8];
    char b224;
    char _m_pad_225[0x3];
    float f228;
    char _m_pad_22c[0x8];
    char doPosition;
    char doRotation;
    char _m_pad_236[0x2];
    int prevTrack;
    int track;
    void FUN_002251d0(Pose* pose, int a, int b, Vec3_225300* out);
    void FUN_002250e0(float v);
    void FUN_00225140(float v);
    float FUN_00225ab0();
    void FUN_00225e00(float t, V3_225e00 v);
};


// 0x00224ce0 FUN_00224ce0 (143 B): matches/0x00224ce0.cpp
// sym: _FUN_00224ce0
// FUN_00224ce0 @ 0x00224ce0
// Interpolates two transforms: translation linearly, rotation spherically.
extern "C" void FUN_00224ce0(const Mat4_224ce0 *from, const Mat4_224ce0 *to, float t, Mat4_224ce0 *out) {
    Quat_224ce0 qTo, qFrom, qOut;
    out->m[12] = (to->m[12] - from->m[12]) * t + from->m[12];
    out->m[13] = (to->m[13] - from->m[13]) * t + from->m[13];
    out->m[14] = (to->m[14] - from->m[14]) * t + from->m[14];
    ((owners::Quat_22b370 *)&qFrom)->FUN_0022b370((const float *)(const Mat4_224ce0 *)from);
    ((owners::Quat_22b370 *)&qTo)->FUN_0022b370((const float *)(const Mat4_224ce0 *)to);
    ((owners::Quaternion_22b750 *)&qOut)->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_224ce0 *)(&qFrom), (const owners::Quaternion_22b750 *)(const Quat_224ce0 *)(&qTo), t);
    qOut.FUN_0022b650(out);
    out->m[3] = 0;
    out->m[7] = 0;
    out->m[11] = 0;
    out->m[15] = 1.0f;
}


// 0x00224d70 FUN_00224d70 (53 B): matches/0x00224d70.cpp
// sym: _FUN_00224d70
extern "C" void __cdecl FUN_00224d70(float angle, Vec3* v) {
    double s = sin(angle);
    double c = cos(angle);
    float x = v->x;
    float z = v->z;
    double zs = z * s;
    v->x = (float)(zs + x * c);
    double negxs = -(x * s);
    v->z = (float)(negxs + z * c);
}


// 0x00224db0 FUN_00224db0 (229 B): equivalent/0x00224db0.cpp
// sym: _FUN_00224db0 @daec2201ccab @wd1b99064dae7
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_00224db0 @ 0x00224db0
extern "C" void __cdecl FUN_00224db0(Matrix* out, const Vec_224db0* a, const Vec_224db0* b) {
 double x=(double)b->z*a->y-(double)b->y*a->z;
 double y=(double)b->x*a->z-(double)b->z*a->x;
 double z=(double)b->y*a->x-(double)b->x*a->y;
 volatile float dot=(float)(((double)b->z*a->z+(double)b->y*a->y)+(double)a->x*b->x);
 volatile float zz=(float)(z*z); double yy=y*y,xx=x*x;
 volatile float factor=(float)((1.0f-dot)/((xx+yy)+zz));
 out->m[0][0]=(float)(xx*factor+dot);
 double xyp=x*y; double xy=xyp*factor; out->m[0][1]=(float)(xy+z);
 double xzp=x*z; double xz=xzp*factor; volatile float sxz=(float)xz; out->m[0][2]=(float)(xz-y);
 out->m[1][0]=(float)(xy-z); out->m[1][1]=(float)(yy*factor+dot);
 double yzp=z*y; double yz=yzp*factor; volatile float syz=(float)yz; out->m[1][2]=(float)(yz+x);
 out->m[2][0]=(float)((double)sxz+y); out->m[2][1]=(float)((double)syz-x); out->m[2][2]=zz*factor+dot;
}


// 0x00224ea0 FUN_00224ea0 (107 B): matches/0x00224ea0.cpp
// sym: ?Angle@fn_fe002747@@YAMMM@Z
// data: kZero_224ea0 = DAT_003f32e0
hulk_freg Angle(float a, float b) {
    if (Abs(a) <= DAT_00427334 && Abs(b) <= DAT_00427334)
        return DAT_003f32e0;
    hulk_freg r = (hulk_freg)atan2(-a, -b);
    if (r < DAT_003f32e0)
        r += DAT_0042732c;
    return r;
}


// 0x00224f10 FUN_00224f10 (172 B): equivalent/0x00224f10.cpp
// sym: ?FUN_00224f10@fn_fe002747@@YAMPBUVec3_224f10@1@@Z @3e3ce36c49ef @wf5b094c8ecec
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 4/4)
// FUN_00224f10 @ 0x00224f10
hulk_freg __cdecl FUN_00224f10(const Vec3_224f10* v) {
    float x=v->x, z=v->z;
    union { float f; unsigned int u; } a;
    a.f=v->y; a.u &= 0x7fffffff;
    if (!(a.f <= 1.0e-5f)) {
        double length=sqrt((double)z*z + (double)x*x);
        a.f=(float)length; a.u &= 0x7fffffff;
        if (!(a.f <= 1.0e-5f)) {
            double scale=1.0f/length;
            x=(float)(x*scale);
            z=(float)(z*scale);
        } else { x=0.0f; z=0.0f; }
    }
    return FUN_00224ea0(x,z);
}


// 0x00224fc0 FUN_00224fc0 (31 B): matches/0x00224fc0.cpp
// sym: ?Target@fn_fe002747@@YAMMM@Z
hulk_freg Target(float from, float to) {
    return Helper_0004af40(-3.1415927f, 3.1415927f, to - from);
}

} // namespace fn_fe002747

// 0x00225000 FUN_00225000 (36 B): matches/0x00225000.cpp
// sym: ?FUN_00225000@AnimationDriver@choreo2@@QAEXXZ
// data: gCount_225000 = DAT_004e5ab4
void choreo2::AnimationDriver::FUN_00225000() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427368);
    (*(Inner_225000 * *)&this->f_20)->B();
    --DAT_004e5ab4;
    ((AnimationDriver_nv_225000*)this)->Tail_002222d0();
}


// 0x00225030 FUN_00225030 (156 B): equivalent/0x00225030.cpp
// sym: ?FUN_00225030@AnimationDriver@choreo2@@QAEXPAX@Z @21f6648d0aa6 @w091b0f4f94d0
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 6/6)
// FUN_00225030 @ 0x00225030
// FUN_00225030: bind to a skeleton and look up the rotation / translation channels of each bone
void choreo2::AnimationDriver::FUN_00225030(void* __p0) { Skeleton_225030 * s = (Skeleton_225030 *)__p0;

    (*(Skeleton_225030 * *)&this->f_20) = s;
    s->AddRef();
    unsigned int n = (*(Table_225030 * *)&this->f_10)->count;
    for (unsigned int i = 0; i < n; i++) {
        Channel_225030 *ch = s->FUN_00288ad0((*(Table_225030 * *)&this->f_10)->ids[i].lo, (*(Table_225030 * *)&this->f_10)->ids[i].hi);
        if (ch != 0) {
            (*(Pair_225030 (*)[1])&this->f_24)[i].rot = ch->FUN_00288960(0x544f52, 0x544f52);
            (*(Pair_225030 (*)[1])&this->f_24)[i].trans = ch->FUN_00288960(0x4e415254, 0x54434556);
        } else {
            (*(Pair_225030 (*)[1])&this->f_24)[i].rot = 0;
            (*(Pair_225030 (*)[1])&this->f_24)[i].trans = 0;
        }
    }
}


// 0x002250d0 choreo2::AnimationDriver::vfunc_3 (3 B): matches/0x002250d0.cpp
// sym: ?vfunc_3@AnimationDriver@choreo2@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool choreo2::AnimationDriver::vfunc_3() {
    return true;
}

namespace fn_fe002747 {

// 0x002250e0 FUN_002250e0 (81 B): matches/0x002250e0.cpp
// sym: ?set@AnimationDriver_2250e0@fn_fe002747@@QAEXM@Z
void AnimationDriver_2250e0::set(float x) {
    float v = p->value - 1.0f;
    if (x < 0.0f)
        result = 0.0f;
    else if (x > v)
        result = v;
    else
        result = x;
}


// 0x00225140 FUN_00225140 (81 B): matches/0x00225140.cpp
// sym: ?Set@AnimationDriver_225140@fn_fe002747@@QAEXM@Z
// data: one = DAT_003f32dc, zero_225140 = DAT_003f32e0
void AnimationDriver_225140::Set(float x) {
    float v = p->f - DAT_003f32dc;
    if (x < DAT_003f32e0) {
        value = 0;
        return;
    }
    if (x > v)
        value = v;
    else
        value = x;
}


// 0x002251d0 FUN_002251d0 (294 B): equivalent/0x002251d0.cpp
// sym: ?run@AnimationDriver_2251d0@fn_fe002747@@QAEXPAUInput_2251d0@2@PAX1PAUVec_2251d0@2@@Z @675d670de255 @wbf542e9f78a0
// STATUS: equivalent (tools/equiv.py level 3: 6630 inputs, branch coverage 6/6)
// FUN_002251d0 @ 0x002251d0
void AnimationDriver_2251d0::run(Input_2251d0* input, void* a, void* b, Vec_2251d0* out) {
 Vec_2251d0 offset;
 if(pair) {
  if(direction >= 0.0f) pair->sample(a,b,&offset);
  else { pair->sample(b,a,&offset); offset.x=-offset.x; offset.y=-offset.y; offset.z=-offset.z; }
 } else { offset.x=0.0f; offset.y=0.0f; offset.z=0.0f; }
 Matrix matrix;
 if(single) {
  Quat_2251d0 q=*input->FUN_00221cd0();
  Vec4_2251d0 v;
  single->sample(a,&v);
  v.x=-v.x; v.y=-v.y; v.z=-v.z;
  FUN_0022b080((float *)(Quat_2251d0 *)(&q),(const float *)(Quat_2251d0 *)(&q),(const float *)(Vec4_2251d0 *)(&v));
  q.FUN_0022b650(&matrix);
 } else matrix=*input->FUN_00221c40();
 ((owners::M_22c3b0 *)&matrix)->FUN_0022c3b0((float *)(Vec_2251d0 *)(&offset), (float *)(Vec_2251d0 *)out);
}


// 0x00225300 choreo2::AnimationDriver::vfunc_10 (928 B): equivalent/0x00225300.cpp
// sym: ?vfunc_10@AnimationDriver@fn_fe002747@@UAEXPAVPose@2@0PAUPoseData_225300@2@M@Z @57eadab2eaed @w890aaddf25b5
// STATUS: equivalent (tools/equiv.py level 3: 62 inputs, branch coverage 21/22, incomplete)
// choreo2::AnimationDriver::vfunc_10 @ 0x00225300
void AnimationDriver::vfunc_10(Pose* from, Pose* to, PoseData_225300* data, float t)
{
    Frame_225300 f;
    Mask_225300* mask = 0;
    if (filter)
        mask = filter->mask;
    unsigned int count = last;
    unsigned int i = first;

    if (i == 0) {
        if (doRotation) {
            if (pairs[0].rot) {
                pairs[0].rot->FUN_0028a8f0(prevTrack, track, &f.root);
            } else {
                f.root.x = 0;
                f.root.y = 0;
                f.root.z = 0;
                f.root.w = 1.0f;
            }
            f.qa = *from->FUN_00221cd0();
            FUN_0022b080((float *)(Quat_225300 *)(&f.qa), (const float *)(Quat_225300 *)(&f.qa), (const float *)(Quat_225300 *)(&f.root));
            f.qb = *to->FUN_00221cd0();
            ((owners::Quaternion_22b750 *)&(f.qb))->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_225300 *)(&f.qb), (const owners::Quaternion_22b750 *)(const Quat_225300 *)(&f.qa), t);
            to->FUN_00221cf0(&f.qb);
        }
        if (doPosition) {
            FUN_002251d0(from, prevTrack, track, &f.tgt);
            f.tgt.x = f.tgt.x + from->position.x;
            f.cur = to->position;
            f.tgt.y = f.tgt.y + from->position.y;
            f.tgt.z = f.tgt.z + from->position.z;
            double u = 1.0f - t;
            double cx = f.cur.x * u;
            f.cur.y = f.cur.y * u;
            f.cur.z = f.cur.z * u;
            f.cur.x = f.tgt.x * t + cx;
            f.cur.y = f.tgt.y * t + f.cur.y;
            f.cur.z = f.tgt.z * t + f.cur.z;
            ((owners::Target_22be40 *)to)->FUN_0022be40((const int *)(Vec3_225300 *)(&f.cur));
        }
        i = 1;
    }

    if (i > count) {
        prevTrack = track;
        return;
    }

    for (; i <= count; i++) {
        if (mask && !(mask->bits[i >> 5] & (1u << (i & 31))))
            continue;

        if (pairs[i].rot) {
            pairs[i].rot->vf5(track, &f.src);
        } else {
            f.src = source->quats[i];
        }
        f.dst = data->quats[i];
        ((owners::Quaternion_22b750 *)&(f.dst))->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_225300 *)(&f.dst), (const owners::Quaternion_22b750 *)(const Quat_225300 *)(&f.src), t);
        data->quats[i] = f.dst;

        if (pairs[i].pos) {
            pairs[i].pos->vf4(track, &f.pos);
        } else {
            f.pos = source->mats[i].pos;
        }
        f.old = data->mats[i].pos;
        Vec3_225300* out = &data->mats[i].pos;
        out->z = (f.pos.z - f.old.z) * t + f.old.z;
        out->x = (f.pos.x - f.old.x) * t + f.old.x;
        out->y = (f.pos.y - f.old.y) * t + f.old.y;
    }
    prevTrack = track;
}

} // namespace fn_fe002747

// 0x002256a0 choreo2::AnimationDriver::vfunc_11 (346 B): equivalent/0x002256a0.cpp [wrapped: conflict: AnimationDriver; Channel; Pose]
// sym: ?vfunc_11@AnimationDriver@fn_002256a0@@UAEDIIPAVPose@2@M@Z @89a8c4a9534b @w08787e464986
namespace fn_002256a0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// choreo2::AnimationDriver::vfunc_11 @ 0x002256a0
struct Quat_2256a0 {
    float x, y, z, w;
};

struct Vec3_2256a0 {
    float x, y, z;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(int track, Vec3_2256a0 *out);
    virtual void vf5(int track, Quat_2256a0 *out);
};

class ChannelSet_2256a0 {
public:
    Channel *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

class Pose {
public:
    char pad0[0x30];
    Vec3_2256a0 position;
    char pad1[0x50 - 0x3c];
    int state;
    Quat_2256a0 *FUN_00221cd0();
    void FUN_00221cf0(Quat_2256a0 *q);
};

class Source_2256a0 {
public:
    ChannelSet_2256a0 *FUN_00288ad0(unsigned int a, unsigned int b);
};

struct Frame_2256a0 {
    char pad[0x10];
    Quat_2256a0 rot;
    Quat_2256a0 q;
};

class AnimationDriver {
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
    virtual void vfunc_10();
    virtual char vfunc_11(unsigned int a, unsigned int b, Pose *pose, float t);

    char pad0[0x20 - 4];
    Source_2256a0 *source;
    char pad1[0x23c - 0x24];
    int track;
};

char AnimationDriver::vfunc_11(unsigned int a, unsigned int b, Pose *pose, float t)
{
    ChannelSet_2256a0 *set = source->FUN_00288ad0(a, b);
    if (set == 0)
        return 0;
    Frame_2256a0 f;
    char result = 0;
    Channel *rotCh = set->FUN_00288960(0x544f52, 0x544f52);
    if (rotCh != 0) {
        rotCh->vf5(track, &f.rot);
        f.q = *pose->FUN_00221cd0();
        ((owners::Quaternion_22b750 *)&(f.q))->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_2256a0 *)(&f.q), (const owners::Quaternion_22b750 *)(const Quat_2256a0 *)(&f.rot), t);
        pose->FUN_00221cf0(&f.q);
        if (t > 0.0f)
            result = 1;
    }
    Channel *posCh = set->FUN_00288960(0x4e415254, 0x54434556);
    if (posCh != 0) {
        posCh->vf4(track, (Vec3_2256a0 *)&f.q);
        Vec3_2256a0 *tp = (Vec3_2256a0 *)&f.q;
        Vec3_2256a0 cur = pose->position;
        cur.x = (tp->x - cur.x) * t + cur.x;
        cur.y = (tp->y - cur.y) * t + cur.y;
        cur.z = (tp->z - cur.z) * t + cur.z;
        ((owners::Target_22be40 *)pose)->FUN_0022be40((const int *)(Vec3_2256a0 *)(&cur));
        if (t > 0.0f)
            result = 1;
    }
    return result;
}
} // namespace fn_002256a0


// 0x00225800 choreo2::AnimationDriver::vfunc_12 (240 B): equivalent/0x00225800.cpp
// sym: ?vfunc_12@AnimationDriver@choreo2@@UAE_NHH@Z @cc7259b32fe5 @wd3923c9981d9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// choreo2::AnimationDriver::vfunc_12 @ 0x00225800
bool choreo2::AnimationDriver::vfunc_12(hulk_intptr __p0, hulk_intptr __p1) { Query_225800 * query = (Query_225800 *)__p0; float * result = (float *)__p1;

 int a,b;
 int first=query->first, second=query->second;
 if (!(*(Tracks * *)&this->f_20)->FUN_00288d10(0,first,second,&b,&a)) return false;
 if (!((AnimationDriver_nv_225800*)this)->FUN_00222330(query)) return false;
 float start=(*(Tracks * *)&this->f_20)->FUN_00288de0(0,0,first,second);
 float end=(*(Tracks * *)&this->f_20)->FUN_00288de0(1,0,first,second);
 if (!(end>=start)) {
  *result=(end<=this->f_23c && this->f_23c<start)?1.0f:0.0f;
 } else {
  *result=(this->f_23c<start || !(end>this->f_23c))?1.0f:0.0f;
 }
 return true;
}


// 0x002258f0 choreo2::AnimationDriver::vfunc_13 (83 B): equivalent/0x002258f0.cpp [wrapped: conflict: choreo2::AnimationDriver]
// sym: ?vfunc_13@AnimationDriver@choreo2@fn_002258f0@@UAE_NXZ @ce3b30a823e7 @w1209437205b2
namespace fn_002258f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// choreo2::AnimationDriver::vfunc_13 @ 0x002258f0
namespace choreo2 {
class AnimationDriver {
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual bool vfunc_13();
    char pad4[0x224 - 4];
    bool finished;
    bool paused;
    float rate;
    float upper;
    float lower;
    char pad234[8];
    float time;
};

bool AnimationDriver::vfunc_13()
{
    if (finished)
        return false;
    if (!paused) {
        if (rate >= 0.0f)
            return time >= lower;
        return time <= upper;
    }
    return false;
}
}
} // namespace fn_002258f0


// 0x00225950 FUN_00225950 (137 B): equivalent/0x00225950.cpp [wrapped: conflict: choreo2::AnimationDriver; choreo2::Driver]
// sym: ??0AnimationDriver@choreo2@fn_00225950@@QAE@HH@Z @cf0edd9a972f @w4c942458fe94
namespace fn_00225950 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00225950 @ 0x00225950
// equiv-map: ??0Driver@choreo2@@QAE@H@Z = 0x002223f0

namespace choreo2 {
struct Skel_225950 { char pad[0x10]; float length; };
class Driver {
public:
    virtual void v0();
    char pad[0x1c];
    Skel_225950* skel;
    char pad2[0x224 - 0x24];
    Driver(int a);
};
class AnimationDriver : public Driver {
public:
    virtual void v0();
    char f224, f225;
    char pad3[2];
    float f228;
    int f22c;
    float f230;
    char f234, f235;
    char pad4[2];
    int f238, f23c;
    void FUN_00225030(int b);
    AnimationDriver(hulk_intptr a, hulk_intptr b);
};
AnimationDriver::AnimationDriver(hulk_intptr a, hulk_intptr b) : Driver(a) {
    f234 = 1;
    f235 = 1;
    f224 = 0;
    f225 = 0;
    f228 = 1.0f;
    f22c = 0;
    f238 = 0;
    f23c = 0;
    FUN_00225030(b);
    f230 = skel->length - 1.0f;
    int n = DAT_004e5ab4;
    int hi = DAT_004e5ab8;
    n++;
    DAT_004e5ab4 = n;
    if (n > hi) DAT_004e5ab8 = n;
}
}
} // namespace fn_00225950


// 0x002259e0 choreo2::AnimationDriver::vfunc_2 (52 B): matches/0x002259e0.cpp [wrapped: conflict: AnimationDriver]
// sym: ?vfunc_2@AnimationDriver@fn_002259e0@@QAEPAU12@E@Z
namespace fn_002259e0 {
// data: g_count_2259e0 = DAT_004e5ab4

extern "C" char DAT_00427368[];
typedef unsigned char u8_2259e0;
struct Load {
    virtual void f0();
    virtual void f1();
};
struct AnimationDriver {
    void* vptr;
    char pad[0x1c];
    Load* member;
    void Cleanup_002222d0();
    AnimationDriver* vfunc_2(u8_2259e0 flag);
};
void thunk_00263f30(AnimationDriver*);
AnimationDriver* AnimationDriver::vfunc_2(u8_2259e0 flag) {
    this->vptr = (void*)((hulk_intptr)DAT_00427368);
    this->member->f1();
    --DAT_004e5ab4;
    this->Cleanup_002222d0();
    if (flag & 1)
        thunk_00263f30(this);
    return this;
}
} // namespace fn_002259e0

namespace fn_fe002747 {

// 0x00225a20 FUN_00225a20 (140 B): matches/0x00225a20.cpp
// sym: ?Copy@AnimationDriver_225a20@fn_fe002747@@QAEPAV12@PAV12@@Z
AnimationDriver_225a20* AnimationDriver_225a20::Copy(AnimationDriver_225a20* src) {
    First_00222460(src);
    ((choreo2::AnimationDriver *)this)->FUN_00225030((void *)(hulk_uintptr)(int)(src->value20));
    b224 = src->b224;
    b225 = src->b225;
    d228 = src->d228;
    d22c = src->d22c;
    d230 = src->d230;
    b234 = src->b234;
    b235 = src->b235;
    d238 = src->d238;
    d23c = src->d23c;
    return this;
}

} // namespace fn_fe002747

// 0x00225ab0 FUN_00225ab0 (113 B): matches/0x00225ab0.cpp [wrapped: conflict: Abs]
// sym: ?Fn@AnimationDriver_225ab0@fn_00225ab0@@QAEMXZ
namespace fn_00225ab0 {

union Bits_225ab0 {
    float f;
    unsigned long u;
};
inline float Abs(float v) {
    Bits_225ab0 b;
    b.f = v;
    b.u &= 0x7fffffffUL;
    return b.f;
}
struct Sub_225ab0 {
    char pad[0x14];
    float m14;
};
class AnimationDriver_225ab0 {
  public:
    float Fn();
    char pad0[0x20];
    Sub_225ab0* m20;
    char pad1[0x204];
    float m228, m22c, m230;
};
float AnimationDriver_225ab0::Fn() {
    float calc;
    if (Abs(m228) <= DAT_00427350)
        return DAT_003f3388;
    if (Abs(m20->m14) <= DAT_00427350)
        return DAT_003f3388;
    return Abs((m230 - m22c) / (m20->m14 * m228));
}
} // namespace fn_00225ab0

namespace fn_fe002747 {

// 0x00225b30 FUN_00225b30 (32 B): matches/0x00225b30.cpp
// sym: ?target@AnimationDriver_225b30@fn_fe002747@@QAEMXZ
float AnimationDriver_225b30::target() {
    if (a)
        return -1.0f;
    if (b)
        return -1.0f;
    return fallback_00225ab0();
}


// 0x00225be0 FUN_00225be0 (112 B): equivalent/0x00225be0.cpp
// sym: ?FUN_00225be0@fn_fe002747@@YAMMMM_N@Z @c2bfffe81f23 @wb9aae7d30f27
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 12/12)
// FUN_00225be0 @ 0x00225be0
// Clamp v into [lo, hi] (bounds may be given in either order), or wrap it into the range.
hulk_freg FUN_00225be0(float v, float lo, float hi, bool wrap)
{
    if (wrap)
        return FUN_0004af40(lo, hi, v);
    if (hi > lo) {
        if (v < lo)
            return lo;
        if (v > hi)
            return hi;
        return v;
    }
    if (v > lo)
        return lo;
    if (v < hi)
        return hi;
    return v;
}


// 0x00225c90 FUN_00225c90 (85 B): equivalent/0x00225c90.cpp
// sym: ?FUN_00225c90@Object@fn_fe002747@@QAEMM@Z @284631d040d3 @wb3f1d6b6a4e9
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_00225c90 @ 0x00225c90
hulk_freg Object::FUN_00225c90(float amount) {
 return FUN_00225be0(data->scale * factor * amount + offset, valueA, valueB, flag, flag, valueB, valueA);
}

} // namespace fn_fe002747

// 0x00225cf0 FUN_00225cf0 (75 B): equivalent/0x00225cf0.cpp
// sym: ?FUN_00225cf0@Object_225cf0@owners@@QAEXH@Z @50c8cf1e7526 @wfe2cb867a39c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00225cf0 @ 0x00225cf0
void owners::Object_225cf0::FUN_00225cf0(int input) {
 float result = FUN_00225be0(input, value1, value2, flag);
 result1 = result;
 result2 = result;
}


// 0x00225d40 choreo2::AnimationDriver::vfunc_9 (23 B): matches/0x00225d40.cpp
// sym: ?vfunc_9@AnimationDriver@choreo2@@UAEXH@Z
void choreo2::AnimationDriver::vfunc_9(int x) {
    this->f_23c = ((This_GetValue*)this)->GetValue_00225c90(x);
}

namespace fn_fe002747 {

// 0x00225da0 FUN_00225da0 (81 B): matches/0x00225da0.cpp
// sym: ?Make@Factory_225da0@fn_fe002747@@QAEPAUAnimationDriver_225da0@2@XZ
// data: gCount_225da0 = DAT_004e5ab4
AnimationDriver_225da0* Factory_225da0::Make() {
    AnimationDriver_225da0* p = (AnimationDriver_225da0*)alloc(0x240);
    if (p != 0) {
        p->InitA_00222590(this);
        p->v = ((hulk_intptr)DAT_00427368);
        p->InitB_00225a20(this);
        ++DAT_004e5ab4;
        if (DAT_004e5ab4 > DAT_004e5ab8)
            DAT_004e5ab8 = DAT_004e5ab4;
        return p;
    }
    return 0;
}


// 0x00225e00 FUN_00225e00 (130 B): equivalent/0x00225e00.cpp
// sym: ?FUN_00225e00@AnimationDriver@fn_fe002747@@QAEXMUV3_225e00@2@@Z @eeceb8e36ce7 @w1dae024c1bcf
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00225e00 @ 0x00225e00
void AnimationDriver::FUN_00225e00(float t, V3_225e00 v)
{
    FUN_002250e0(v.y);
    if (v.z < 0.0f)
        FUN_00225140(node->f10 - 1.0f);
    else
        FUN_00225140(v.z);
    if (t > 0.0f && !b224) {
        f228 = 1.0f;
        f228 = FUN_00225ab0() / t;
    } else {
        f228 = v.x;
    }
}

// 0x00225e90 choreo2::AnimationDriver::vfunc_5 (5 B): not yet verified
} // namespace fn_fe002747
