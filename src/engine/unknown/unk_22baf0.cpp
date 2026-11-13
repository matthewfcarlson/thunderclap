// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022baf0..0x00230800 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0c6a717 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0c6a717 {} using namespace fn_f0c6a717;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f0c6a717 {
struct Vec_22bec0 { float x,y,z,w; void FUN_0022d180(); };
struct Basis_22bec0 { Vec_22bec0 a,b,c; void FUN_0022bec0(Vec_22bec0* u, Vec_22bec0* v); };
struct Vec_22c1b0 { float x,y,z; void FUN_0022d180(); };
struct Matrix { Vec_22c1b0 a; float pad0; Vec_22c1b0 b; float pad1; Vec_22c1b0 c; void target(); };
struct V4_22c310 {
    float x, y, z, w;
};
struct M_22c310 {
    float a[16];
    void Transform(const V4_22c310* in, V4_22c310* out);
};
struct Vec3_22c8e0 { float x, y, z; };
struct Mat_22c8e0 {
    float m[16];
    void LookAt(const Vec3_22c8e0 *center, const Vec3_22c8e0 *eye, const Vec3_22c8e0 *up);
};
struct Vec {
  public:
    float x;
    float y;
    float z;
};
class Mat {
  public:
    union { float a[11]; float v[11]; };
    void Set(const Vec* p);
    void Init(const Vec* v);
};
struct V {
    float pad;
    float b;
    float c;
};
struct Mat_22ccf0 {
    float a[11];
    void Set(V* v);
};
} // namespace fn_f0c6a717
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f0c6a717 {
struct Vec_22d110 {
    float x, y, z;
    hulk_freg Normalize();
};
struct V3_22d330 {
    float x, y, z;
    unsigned IsSmall();
};
inline float Abs(float v) {
    float t = v;
    *(unsigned*)&t = *(unsigned*)&t & 0x7fffffff;
    return t;
}
struct Vec3_22d3a0 {
    float x, y, z;
};
struct V3_22d550 {
    float x, y, z;
    void FUN_0022d180();
};
struct V3_22d730 {
    float x, y, z;
};
struct V3_22db60 {
    float x, y, z;
};
union Slot_22db60 {
    V3_22db60 *v;
    float *fp;
    float f;
    unsigned char b;
};
struct Frame_22db60 {
    float uu;
    float t[3];
    float R[3];
    float Rp[3];
    float pad38;
    float Qy;
    float Qz;
};
struct Vec3_22de70 { float x,y,z; };
struct Vec3_22dfe0 {
    float x, y, z;
};
class Plane_22dfe0 {
public:
    Vec3_22dfe0 normal;
    float d;

    void FUN_0022d180();    // normalize
    void FUN_0022dfe0(const Vec3_22dfe0 *a, const Vec3_22dfe0 *b, const Vec3_22dfe0 *c);
};
struct Plane_22e100 {
    float nx, ny, nz, w;
    bool FUN_0022e100(const float *box);
};
struct Vec3_22e1f0 { float x, y, z; };
union FloatBits_22e1f0 {
    float f;
    int i;
};
struct Plane_22e1f0 {
    Vec3_22e1f0 normal;
    float d;
    bool FUN_0022e1f0(const Vec3_22e1f0 *a, const Vec3_22e1f0 *b, float *t);
};
typedef unsigned int u32_22e320;
struct This_FUN_0022e180 {
    void FUN_0022e180(u32_22e320, hulk_uintptr);
};
struct M16 {
    float m[16];
};
struct V4_22e470 {
    int a, b, c, d;
};
class Foo_22e470 {
  public:
    Foo_22e470& Copy(const Foo_22e470& o);
    M16 m;
    V4_22e470 v0;
    V4_22e470 v1;
    V4_22e470 v2;
    V4_22e470 v3;
};
struct Vec3_22e500 {
    float x, y, z;
};
struct Vec4_22e500 {
    float x, y, z, w;
};
struct Matrix4_22e500 {
    Vec4_22e500 row[4];
};
struct Curve_22e500 {
    void FUN_0022e500(int type, const Vec3_22e500 *p0, const Vec3_22e500 *p1, const Vec3_22e500 *p2, const Vec3_22e500 *p3);
};
struct Vec4_22e670 {
    float x, y, z, w;
};
struct Matrix4_22e670 {
    Vec4_22e670 row[4];
};
struct Curve_22e670 {
    void FUN_0022e670(int type, const Vec4_22e670 *p0, const Vec4_22e670 *p1, const Vec4_22e670 *p2, const Vec4_22e670 *p3);
};
struct Vec3_22eb00 {
    float x, y, z;
};
struct Vec4_22eb00 {
    float x, y, z, w;
};
class Integrator {
public:
    char pad00[0x40];
    Vec4_22eb00 pos;               // 0x40
    float r50;
    float vx;               // 0x54
    float ax;               // 0x58
    float jx;               // 0x5c
    float r60;
    float vy;               // 0x64
    float ay;               // 0x68
    float jy;               // 0x6c
    float r70;
    float vz;               // 0x74
    float az;               // 0x78
    float jz;               // 0x7c
    void FUN_0022eb00(Vec3_22eb00 *out);
};
class C_22ec20 {
  public:
    char pad[0x114];
    int a;
    int b;
    void f();
};
extern void __cdecl ReleaseThing_0008d330(void*);
extern void* __cdecl Alloc_0008d690(unsigned int);
extern void __stdcall Init_00011520(void*, unsigned int, unsigned int, void(__cdecl*)());
extern void* ElemCtor_000a9e50(void*); /* (unb4) as defined; address taken only */
class Obj_22eda0 {
  public:
    int m0, m1;
    char pad[0x108];
    unsigned int count;
    void* data1;
    void* data2;
    void Target(unsigned int);
};
struct Sub_22ef20 {
    void Update_0022e670(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};
struct Cursor_22efb0 {
    void FUN_0022e890(int target, float delta);
};
class Track {
public:
    int first;
    char pad04[4];
    Cursor_22efb0 cursor;
    char pad_cursor[0x100 - sizeof(Cursor_22efb0)];
    char fromEnd;
    char pad109[7];
    unsigned int count;
    int FUN_0022efb0(int target, float position);
};
struct Buffer_22f060 { void FUN_0022e930(void* destination, unsigned int stride); };
struct Object {
 char pad0[0x88]; Buffer_22f060 buffer;
 char pad1[0x108-0x88-sizeof(Buffer_22f060)];
 unsigned char mode; char pad2[7]; unsigned int count;
 char pad3[8]; unsigned int total; unsigned int stride;
 void* FUN_0022f060(void* destination, unsigned int step, unsigned int requested);
};
struct OutputState {
    char data[0x80];
    void FUN_0022e930(void* output, int divisor);
    void FUN_0022eb00(void* output);
};
struct Animator_22f120 {
    char padding[0x88];
    OutputState state;
    unsigned char looping;
    char pad109[7];
    unsigned int count;
    char pad114[8];
    int tick;
    int divisor;
    bool FUN_0022ef20(int flag, float position);
    void* FUN_0022f120(void* output);
};
void* FUN_0008d690(unsigned int size);
void FUN_000a9e50(void* p);
void __stdcall FUN_00011520(void* base, int stride, int count, void (*fn)(void*));
struct Matrix4_22f230 {
    char data[0x80];
    Matrix4_22f230* FUN_0022e470(const Matrix4_22f230* src);
};
struct Elem_22f230 {
    unsigned int w0, w1, w2, w3;
};
struct Shape_22f230 {
    unsigned int f00;
    unsigned int f04;
    Matrix4_22f230 m08;
    Matrix4_22f230 m88;
    char flag108;
    char pad109[3];
    unsigned int f10c;
    unsigned int count;
    Elem_22f230* elems;
    unsigned int* extra;
    unsigned int f11c;
    unsigned int f120;
    Shape_22f230* FUN_0022f230(const Shape_22f230* src);
};
struct Matrix4_22f400 {
    char data[0x80];
    Matrix4_22f400* FUN_0022e470(const Matrix4_22f400* src);
};
struct Elem_22f400 {
    unsigned int w0, w1, w2, w3;
};
struct Shape_22f400 {
    unsigned int f00;
    unsigned int f04;
    Matrix4_22f400 m08;
    Matrix4_22f400 m88;
    char flag108;
    char pad109[3];
    unsigned int f10c;
    unsigned int count;
    Elem_22f400* elems;
    unsigned int* extra;
    unsigned int f11c;
    unsigned int f120;
    Shape_22f400* FUN_0022f400(const Shape_22f400* src);
};
struct Vec3_22f760 {
    float x, y, z;
};
struct Sampler_22f760 {
    void FUN_0022e890(Vec3_22f760* out, float t);
};
typedef unsigned int uint_22f7e0;
struct Point_22f7e0 { float x,y,z,w; };
struct Segment_22f7e0 {
 char data[0x80];
 void FUN_0022e670(uint_22f7e0, Point_22f7e0*, Point_22f7e0*, Point_22f7e0*, Point_22f7e0*);
};
hulk_freg __cdecl FUN_0022f760(Segment_22f7e0*, float);
void* __cdecl FUN_0008d690(uint_22f7e0);
struct Curve_22f7e0 {
 char padding[0x108];
 unsigned char closed;
 char padding2[3];
 uint_22f7e0 degree;
 uint_22f7e0 count;
 Point_22f7e0* points;
 float* cache;
 float FUN_0022f7e0(uint_22f7e0 index);
};
struct Point_22fa60 { float x,y,z,w; };
struct Segment_22fa60 { char data[128]; void FUN_0022e670(unsigned int, Point_22fa60*, Point_22fa60*, Point_22fa60*, Point_22fa60*); };
extern "C" double __cdecl FUN_0022f760(Segment_22fa60*, float);
struct Curve_22fa60 {
 char pad[0x108]; unsigned char closed; char pad2[3]; unsigned int degree; unsigned int count; Point_22fa60* points;
 double FUN_0022f7e0(unsigned int);
 hulk_freg FUN_0022fa60(float);
};
struct Bounds_22fec0 {
    float min[3];
    float max[3];
    void GetCenter(struct CenterRadius *out);
};
struct CenterRadius {
    float x, y, z;
    float radius;
};
struct Vec3_22ff50 { float x, y, z; };
class Segment_22ff50 {
public:
    Vec3_22ff50 a;
    Vec3_22ff50 b;
    hulk_freg FUN_0022ff50(Vec3_22ff50 *p);
};
struct Vec_2300a0 { float x,y,z; };
struct Line { Vec_2300a0 start,end; double distance(const Vec_2300a0* p); };
struct Vec3_230160 {
    float x, y, z;
};
union FloatBits_230160 {
    float value;
    unsigned int bits;
};
class Segment_230160 {
  public:
    Vec3_230160 p0, p1;
    hulk_freg FUN_00230160(Segment_230160* other);
};
struct Segment_2304b0 {
    float p0x, p0y, p0z;
    float p1x, p1y, p1z;

    hulk_freg FUN_002304b0(const Segment_2304b0* o);
};
typedef unsigned int U_2306c0;
struct H {
  public:
    void Run(int a, hulk_intptr originalThis);
    void run_0022c310(owners::Obj_2306c0*, U_2306c0*);
};
class X;
class Y {
  public:
    void Fnf_0022c310(int, X*);
};
class X {
  public:
    void g(int a, Y* y);
};

} // namespace fn_f0c6a717

// 0x0022bc20 FUN_0022bc20 (174 B): equivalent/0x0022bc20.cpp
// sym: ?FUN_0022bc20@Matrix_22bc20@owners@@QAEXMMM@Z @6378b2984061 @wb8379dc1753e
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0022bc20 @ 0x0022bc20
void owners::Matrix_22bc20::FUN_0022bc20(float x,float y,float z) {
 double sx=sin(x), cx=cos(x), sy=sin(y);
 float cy=(float)cos(y);
 double sz=sin(z), cz=cos(z);
 float a=(float)(cz*cx), b=(float)(sz*sx), c=(float)(cz*sx), d=(float)(sz*cx);
 m[0][0]=(float)(cz*cy); m[0][1]=(float)(sz*cy); m[0][2]=(float)-sy;
 m[1][0]=(float)(c*sy-d); m[1][1]=(float)(b*sy+a); m[1][2]=(float)(cy*sx);
 m[2][0]=(float)(a*sy+b); m[2][1]=(float)(d*sy-c); m[2][2]=(float)(cy*cx);
}


// 0x0022bcd0 FUN_0022bcd0 (201 B): matches/0x0022bcd0.cpp
// sym: ?FUN_0022bcd0@Matrix_22bcd0@owners@@QAEXMMM@Z
void owners::Matrix_22bcd0::FUN_0022bcd0(float x, float y, float z) {
    double sx = sin(x), cx = cos(x);
    float sy = (float)sin(y);
    double cy = cos(y);
    float sz = (float)sin(z), cz = (float)cos(z);
    float a = (float)(cy * cx), b = (float)(sy * sx), c = (float)(cy * sx), d = (float)(sy * cx);
    m[0][0] = (float)(cz * cy);
    m[0][1] = a * sz + b;
    m[0][2] = c * sz - d;
    m[1][0] = -sz;
    m[1][1] = (float)(cz * cx);
    m[1][2] = (float)(cz * sx);
    m[2][0] = cz * sy;
    m[2][1] = d * sz - c;
    m[2][2] = b * sz + a;
}


// 0x0022bda0 FUN_0022bda0 (153 B): equivalent/0x0022bda0.cpp
// sym: ?FUN_0022bda0@Matrix_22bda0@owners@@QAEXMMM@Z @c3e8240179ec @w7ce5040cf25e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022bda0 @ 0x0022bda0
// Builds the 3x3 rotation block from three Euler angles.
void owners::Matrix_22bda0::FUN_0022bda0(float a, float b, float c)
{
    double sa = sin(a);
    double ca = cos(a);
    double sb = sin(b);
    volatile float cb = (float)cos(b);
    double sc = sin(c);
    double cc = cos(c);
    volatile float t1 = (float)(sc * sb);
    volatile float t2 = (float)(cc * cb);
    m[0][0] = (float)(t1 * sa + t2);
    m[0][1] = (float)(sc * ca);
    m[0][2] = (float)((sc * cb) * sa - cc * sb);
    m[1][0] = (float)((cc * sb) * sa - sc * cb);
    m[1][1] = (float)(cc * ca);
    m[1][2] = (float)(t2 * sa + t1);
    m[2][0] = (float)(sb * ca);
    m[2][1] = (float)(-sa);
    m[2][2] = (float)(cb * ca);
}


// 0x0022be40 FUN_0022be40 (24 B): matches/0x0022be40.cpp
// sym: ?FUN_0022be40@Target_22be40@owners@@QAEXPBH@Z
void owners::Target_22be40::FUN_0022be40(const int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
}


// 0x0022be60 FUN_0022be60 (43 B): matches/0x0022be60.cpp
// sym: ?FUN_0022be60@C_22be60@owners@@QAEXHHH@Z
void owners::C_22be60::FUN_0022be60(int p, int q, int r) {
    a[0] = p;
    a[1] = 0;
    a[2] = 0;
    a[4] = 0;
    a[6] = 0;
    a[8] = 0;
    a[9] = 0;
    a[5] = q;
    a[10] = r;
}

namespace fn_f0c6a717 {

// 0x0022bec0 FUN_0022bec0 (277 B): equivalent/0x0022bec0.cpp
// sym: ?FUN_0022bec0@Basis_22bec0@fn_f0c6a717@@QAEXPAUVec_22bec0@2@0@Z @efd380f2bd65 @w7ea761a9f5ed
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0022bec0 @ 0x0022bec0
void Basis_22bec0::FUN_0022bec0(Vec_22bec0* u, Vec_22bec0* v) {
 float cy=u->x*v->z-u->z*v->x;
 float cz=u->y*v->x-u->x*v->y;
 float cx=u->z*v->y-u->y*v->z;
 a.x=cx; a.y=cy; a.z=cz;
 if (a.x*a.x+a.y*a.y+a.z*a.z <= (*(float*)&DAT_00427598)) {
 float y=u->y, z=u->z;
 a.x=0.0f; a.y=-z; a.z=y;
 if (a.y*a.y+a.z*a.z+a.x*a.x <= (*(float*)&DAT_00427598)) {
 float x=u->x; float z2=u->z;
 a.x=z2; a.z=-x; a.y=0.0f;
 }
 }
 cy=u->z*a.x-a.z*u->x;
 cz=a.y*u->x-u->y*a.x;
 cx=a.z*u->y-a.y*u->z;
 b.x=cx; b.y=cy; b.z=cz;
 c.x=u->x; c.y=u->y; c.z=u->z;
 a.FUN_0022d180(); b.FUN_0022d180(); c.FUN_0022d180();
}

} // namespace fn_f0c6a717

// 0x0022c0b0 FUN_0022c0b0 (111 B): matches/0x0022c0b0.cpp
// sym: ?FUN_0022c0b0@M_22c0b0@owners@@QAEXXZ
void owners::M_22c0b0::FUN_0022c0b0() {
    float a = m[0][1], b = m[0][2], c = m[0][3], d = m[1][2], e = m[1][3], f = m[2][3];
    m[0][1] = m[1][0];
    m[0][2] = m[2][0];
    m[0][3] = m[3][0];
    m[1][2] = m[2][1];
    m[1][3] = m[3][1];
    m[1][0] = a;
    m[2][0] = b;
    m[2][1] = d;
    m[2][3] = m[3][2];
    m[3][0] = c;
    m[3][1] = e;
    m[3][2] = f;
}


// 0x0022c120 FUN_0022c120 (136 B): equivalent/0x0022c120.cpp
// sym: ?FUN_0022c120@Matrix_22c120@owners@@QAEXXZ @883e90ece2dd @wd9c9e0f64243
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022c120 @ 0x0022c120
// Inverts a rigid transform in place: transposes the rotation, then maps the negated translation through it.
void owners::Matrix_22c120::FUN_0022c120()
{
    float tx = -m[12];
    float ty = -m[13];
    float tz = -m[14];
    FUN_0022c0b0();
    m[11] = 0.0f;
    m[7] = 0.0f;
    m[3] = 0.0f;
    m[15] = 1.0f;
    m[12] = (tz * m[8] + ty * m[4]) + tx * m[0];
    m[13] = (tz * m[9] + ty * m[5]) + tx * m[1];
    m[14] = (tz * m[10] + ty * m[6]) + tx * m[2];
}

namespace fn_f0c6a717 {

// 0x0022c1b0 FUN_0022c1b0 (250 B): equivalent/0x0022c1b0.cpp
// sym: ?target@Matrix@fn_f0c6a717@@QAEXXZ @9d0d147d6b11 @w620f3ce21074
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022c1b0 @ 0x0022c1b0
void Matrix::target() {
 Vec_22c1b0 first = a;
 Vec_22c1b0 second = b;
 first.FUN_0022d180();
 Vec_22c1b0 third;
 third.x = second.z * first.y - second.y * first.z;
 third.y = first.z * second.x - second.z * first.x;
 third.z = second.y * first.x - first.y * second.x;
 third.FUN_0022d180();
 a = first;
 b.x = third.y * first.z - third.z * first.y;
 b.y = third.z * first.x - first.z * third.x;
 b.z = first.y * third.x - third.y * first.x;
 c = third;
}

} // namespace fn_f0c6a717

// 0x0022c2b0 FUN_0022c2b0 (92 B): matches/0x0022c2b0.cpp
// sym: ?FUN_0022c2b0@Mat_22c2b0@owners@@QAEXPAM0@Z
void owners::Mat_22c2b0::FUN_0022c2b0(float* v, float* out) {
    float b = v[0] * x1 + v[1] * x5 + v[2] * x9 + x13;
    float c = v[0] * x2 + v[1] * x6 + v[2] * x10 + x14;
    float a = v[1] * x4 + v[2] * x8 + v[0] * x0 + x12;  // the listing's order (MSVC 7.1 reassociates)
    out[0] = a;
    out[1] = b;
    out[2] = c;
}

namespace fn_f0c6a717 {

// 0x0022c310 FUN_0022c310 (147 B): matches/0x0022c310.cpp
// sym: ?Transform@M_22c310@fn_f0c6a717@@QAEXPBUV4_22c310@2@PAU32@@Z
void M_22c310::Transform(const V4_22c310* in, V4_22c310* out) {
    float e1 = a[1] * in->x + a[13] * in->w + a[9] * in->z + a[5] * in->y;
    float e2 = a[2] * in->x + a[14] * in->w + a[10] * in->z + a[6] * in->y;
    float e3 = a[3] * in->x + a[15] * in->w + a[11] * in->z + a[7] * in->y;
    float e4 = a[12] * in->w + a[8] * in->z + a[4] * in->y + a[0] * in->x;
    out->x = e4;
    out->y = e1;
    out->z = e2;
    out->w = e3;
}

} // namespace fn_f0c6a717

// 0x0022c3b0 FUN_0022c3b0 (83 B): matches/0x0022c3b0.cpp
// sym: ?FUN_0022c3b0@M_22c3b0@owners@@QAEXPAM0@Z
void owners::M_22c3b0::FUN_0022c3b0(float* p, float* out) {
    float x = a[1] * p[0] + a[5] * p[1] + a[9] * p[2];
    float y = a[2] * p[0] + a[6] * p[1] + a[10] * p[2];
    float z = a[4] * p[1] + a[8] * p[2] + a[0] * p[0];  // the listing's order (MSVC 7.1 reassociates; clang does not)
    out[0] = z;
    out[1] = x;
    out[2] = y;
}


// 0x0022c410 FUN_0022c410 (517 B): equivalent/0x0022c410.cpp [wrapped: conflict: Matrix]
// sym: ?FUN_0022c410@Matrix@fn_0022c410@@QAEXHPBUVec3_22c410@2@PAU32@@Z @ce1b6a4545bb @weac4d6023396
namespace fn_0022c410 {
// STATUS: equivalent (tools/equiv.py level 3: 10208 inputs, branch coverage 8/8)
// FUN_0022c410 @ 0x0022c410
struct Vec3_22c410 {
    float x, y, z;
};

struct Matrix {
    float m[16];

    // Transforms n points (row-vector convention, translation in the last row).
    void FUN_0022c410(int n, const Vec3_22c410* src, Vec3_22c410* dst);
};

void Matrix::FUN_0022c410(int n, const Vec3_22c410* src, Vec3_22c410* dst)
{
    for (int i = 0; i < n; i++) {
        float x = src[i].z * m[8] + src[i].y * m[4] + src[i].x * m[0] + m[12];
        float y = m[5] * src[i].y + src[i].x * m[1] + src[i].z * m[9] + m[13];
        float z = src[i].x * m[2] + m[10] * src[i].z + m[6] * src[i].y + m[14];
        dst[i].x = x;
        dst[i].y = y;
        dst[i].z = z;
    }
}
} // namespace fn_0022c410


// 0x0022c6c0 FUN_0022c6c0 (429 B): equivalent/0x0022c6c0.cpp [wrapped: conflict: Matrix]
// sym: ?LookAt@Matrix@fn_0022c6c0@@QAEXPBUV3_22c6c0@2@00@Z @f1c8ff7280d3 @w3028c51247ad
namespace fn_0022c6c0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0022c6c0 @ 0x0022c6c0
struct V3_22c6c0 {
    float x, y, z;
    void FUN_0022d180();
};

struct Matrix {
    float m[16];
    void LookAt(const V3_22c6c0* at, const V3_22c6c0* eye, const V3_22c6c0* up);
};

void Matrix::LookAt(const V3_22c6c0* at, const V3_22c6c0* eye, const V3_22c6c0* up)
{
    V3_22c6c0 f;
    f.x = at->x - eye->x;
    f.y = at->y - eye->y;
    f.z = at->z - eye->z;
    f.FUN_0022d180();

    volatile float rx;
    volatile float ry;
    volatile float rz;
    double rxWide = f.z * up->y - f.y * up->z;
    rx = (float)rxWide;
    ry = f.x * up->z - f.z * up->x;
    rz = f.y * up->x - f.x * up->y;

    volatile float ux, uy, uz;
    ux = f.y * rz - ry * f.z;
    uy = f.z * rxWide - f.x * rz;
    uz = f.x * ry - rxWide * f.y;

    m[0] = rx;  m[1] = ux;  m[2] = f.x;  m[3] = 0.0f;
    m[4] = ry;  m[5] = uy;  m[6] = f.y;  m[7] = 0.0f;
    m[8] = rz;  m[9] = uz;  m[10] = f.z; m[11] = 0.0f;
    m[12] = -(rz * eye->z + rx * eye->x + ry * eye->y);
    m[13] = -(uz * eye->z + ux * eye->x + uy * eye->y);
    m[14] = -(f.x * eye->x + f.y * eye->y + f.z * eye->z);
    m[15] = 1.0f;
}
} // namespace fn_0022c6c0

namespace fn_f0c6a717 {

// 0x0022c8e0 FUN_0022c8e0 (425 B): equivalent/0x0022c8e0.cpp
// sym: ?LookAt@Mat_22c8e0@fn_f0c6a717@@QAEXPBUVec3_22c8e0@2@00@Z @b2767677ca5f @w8cb1944439a8
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 0/0; --wine 606 inputs)
// FUN_0022c8e0 @ 0x0022c8e0
void Mat_22c8e0::LookAt(const Vec3_22c8e0 *center, const Vec3_22c8e0 *eye, const Vec3_22c8e0 *up)
{
    Vec3N z;
    z.x = eye->x - center->x;
    z.y = eye->y - center->y;
    z.z = eye->z - center->z;
    z.FUN_0022d180();

    Vec3_22c8e0 s;
    hulk_freg sxr = z.z * up->y - z.y * up->z;
    s.x = sxr;
    s.y = z.x * up->z - z.z * up->x;
    s.z = z.y * up->x - z.x * up->y;

    Vec3_22c8e0 sc = s;
    Vec3_22c8e0 t;
    t.x = s.y * z.z - s.z * z.y;
    t.y = s.z * z.x - sxr * z.z;
    t.z = z.y * sxr - s.y * z.x;

    Vec3_22c8e0 tc = t;
    Vec3_22c8e0 zc;
    zc.x = z.x;
    zc.y = z.y;
    zc.z = z.z;
    float a = sc.x * eye->x + sc.y * eye->y + sc.z * eye->z;
    float b = tc.x * eye->x + tc.y * eye->y + tc.z * eye->z;
    float c = zc.x * eye->x + zc.y * eye->y + zc.z * eye->z;

    m[1] = s.y;
    m[5] = t.y;
    m[2] = s.z;
    m[4] = t.x;
    m[9] = z.y;
    m[0] = s.x;
    m[3] = -a;
    m[6] = z.z;
    m[8] = z.x;
    m[7] = -b;
    m[10] = z.z;
    m[11] = -c;
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;
}

} // namespace fn_f0c6a717

// 0x0022ca90 FUN_0022ca90 (380 B): equivalent/0x0022ca90.cpp
// sym: ?FUN_0022ca90@Matrix_22ca90@owners@@QAEXPBU12@0@Z @447f21597577 @wcc38af0bdc02
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0022ca90 @ 0x0022ca90
void owners::Matrix_22ca90::FUN_0022ca90(const owners::Matrix_22ca90* a, const owners::Matrix_22ca90* b) {
 owners::Matrix_22ca90 r;
 r.m[0][0]=(a->m[0][0]*b->m[0][0]+a->m[0][2]*b->m[2][0])+b->m[1][0]*a->m[0][1];
 r.m[0][1]=(b->m[0][1]*a->m[0][0]+a->m[0][2]*b->m[2][1])+b->m[1][1]*a->m[0][1];
 r.m[0][2]=(b->m[2][2]*a->m[0][2]+b->m[1][2]*a->m[0][1])+a->m[0][0]*b->m[0][2];
 r.m[0][3]=0.0f;
 r.m[1][0]=(a->m[1][0]*b->m[0][0]+a->m[1][2]*b->m[2][0])+a->m[1][1]*b->m[1][0];
 r.m[1][1]=(a->m[1][2]*b->m[2][1]+a->m[1][1]*b->m[1][1])+b->m[0][1]*a->m[1][0];
 r.m[1][2]=(a->m[1][1]*b->m[1][2]+a->m[1][0]*b->m[0][2])+a->m[1][2]*b->m[2][2];
 r.m[1][3]=0.0f;
 r.m[2][0]=(a->m[2][2]*b->m[2][0]+b->m[1][0]*a->m[2][1])+a->m[2][0]*b->m[0][0];
 r.m[2][1]=(a->m[2][2]*b->m[2][1]+b->m[0][1]*a->m[2][0])+b->m[1][1]*a->m[2][1];
 r.m[2][2]=(b->m[1][2]*a->m[2][1]+a->m[2][0]*b->m[0][2])+a->m[2][2]*b->m[2][2];
 r.m[2][3]=0.0f;
 r.m[3][0]=((a->m[3][1]*b->m[1][0]+a->m[3][0]*b->m[0][0])+a->m[3][2]*b->m[2][0])+b->m[3][0];
 r.m[3][1]=((a->m[3][1]*b->m[1][1]+a->m[3][0]*b->m[0][1])+a->m[3][2]*b->m[2][1])+b->m[3][1];
 r.m[3][2]=((a->m[3][0]*b->m[0][2]+b->m[2][2]*a->m[3][2])+b->m[1][2]*a->m[3][1])+b->m[3][2];
 r.m[3][3]=1.0f;
 *this=r;
}


// 0x0022cc10 FUN_0022cc10 (116 B): equivalent/0x0022cc10.cpp
// sym: ?FUN_0022cc10@Matrix_22cc10@owners@@QAEXPBU12@0@Z @560217a1c807 @wa5836bf6c562
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0022cc10 @ 0x0022cc10
void owners::Matrix_22cc10::FUN_0022cc10(const owners::Matrix_22cc10* a, const owners::Matrix_22cc10* b)
{
    owners::Matrix_22cc10 result;
    for (int row = 3; row >= 0; --row) {
        for (int col = 3; col >= 0; --col) {
            result.m[row][col] = ((b->m[0][col] * a->m[row][0] + b->m[1][col] * a->m[row][1]) + a->m[row][2] * b->m[2][col]) + b->m[3][col] * a->m[row][3];
        }
    }
    *this = result;
}

namespace fn_f0c6a717 {

// 0x0022cc90 FUN_0022cc90 (85 B): matches/0x0022cc90.cpp
// sym: ?Set@Mat@fn_f0c6a717@@QAEXPBUVec@2@@Z
// x87: the reciprocal length stays in a register for b; MSVC spills it to a float slot (rounded) and computes a
// from the spilled copy
void Mat::Set(const Vec* p) {
    float x = p->x;
    float z = p->z;
    hulk_freg inv = 1.0f / (hulk_freg)sqrt((hulk_freg)z * z + (hulk_freg)x * x);
    hulk_freg b = inv * p->x;
    float spilled = inv;
    hulk_freg a = spilled * p->z;
    v[1] = 0;
    v[4] = 0;
    v[0] = a;
    v[5] = 1;
    v[6] = 0;
    v[9] = 0;
    v[2] = -b;
    v[8] = b;
    v[10] = a;
}


// 0x0022ccf0 FUN_0022ccf0 (87 B): matches/0x0022ccf0.cpp
// sym: ?Set@Mat_22ccf0@fn_f0c6a717@@QAEXPAUV@2@@Z
// x87: the root and its reciprocal stay in registers; x uses the register copy, y the copy MSVC spills to a
// float slot (rounded)
void Mat_22ccf0::Set(V* v) {
    hulk_freg s = (hulk_freg)sqrt((double)((hulk_freg)v->c * v->c + (hulk_freg)v->b * v->b));
    hulk_freg n = 1.0f / s;
    hulk_freg x = n * v->b;
    float spilled = n;
    hulk_freg y = spilled * v->c;
    a[0] = 1.0f;
    a[1] = 0.0f;
    a[5] = y;
    a[2] = 0.0f;
    a[4] = 0.0f;
    a[8] = 0.0f;
    a[6] = -x;
    a[9] = x;
    a[10] = y;
}


// 0x0022cd50 FUN_0022cd50 (83 B): matches/0x0022cd50.cpp
// sym: ?Init@Mat@fn_f0c6a717@@QAEXPBUVec@2@@Z
// x87: the reciprocal length stays in a register for x; y uses the copy MSVC spills to a float slot (rounded)
void Mat::Init(const Vec* v) {
    float vx = v->x;
    hulk_freg n = 1.0f / (hulk_freg)sqrt((hulk_freg)v->y * v->y + (hulk_freg)vx * vx);
    hulk_freg x = n * v->x;
    float spilled = n;
    hulk_freg y = spilled * v->y;
    a[0] = x;
    a[2] = 0;
    a[6] = 0;
    a[8] = 0;
    a[1] = y;
    a[9] = 0;
    a[10] = 1.0f;
    a[4] = -y;
    a[5] = x;
}

} // namespace fn_f0c6a717

// 0x0022cdb0 FUN_0022cdb0 (473 B): equivalent/0x0022cdb0.cpp
// sym: ?FUN_0022cdb0@Matrix_22cdb0@owners@@QAEXXZ @fa8eb2369c37 @wfe9bd5afc779
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// FUN_0022cdb0 @ 0x0022cdb0
// x87: the determinant and its reciprocal stay in registers (53 bits); the products p1-p5 and the result go
// through the frame (rounded)
void owners::Matrix_22cdb0::FUN_0022cdb0()
{
    float t[16];
    volatile float p1 = m[6] * m[8];
    volatile float p2 = m[9] * m[4];
    volatile float p3 = m[5] * m[8];
    volatile float p4 = m[4] * m[10];
    volatile float p5 = m[6] * m[9];
    hulk_freg det = m[5] * m[10] * m[0];
    det = det + p1 * m[1];
    det = det + p2 * m[2];
    hulk_freg n3 = -(p3 * m[2]);
    det = det + n3;
    hulk_freg n4 = -(p4 * m[1]);
    det = det + n4;
    hulk_freg n5 = -(p5 * m[0]);
    det = det + n5;
    union {
        float f;
        unsigned int u;
    } d;
    d.f = det - 1.0f;
    d.u &= 0x7fffffff;
    if (d.f <= 0.00001f) {
        FUN_0022c120();
        return;
    }
    hulk_freg r = 1.0f / det;
    t[0] = (m[5] * m[10] - p5) * r;
    t[4] = -((p4 - p1) * r);
    t[8] = (p2 - p3) * r;
    t[1] = -((m[1] * m[10] - m[9] * m[2]) * r);
    t[5] = (m[0] * m[10] - m[2] * m[8]) * r;
    t[9] = -((m[9] * m[0] - m[1] * m[8]) * r);
    t[2] = (m[6] * m[1] - m[5] * m[2]) * r;
    t[6] = -((m[6] * m[0] - m[4] * m[2]) * r);
    t[15] = m[15];
    t[10] = (m[5] * m[0] - m[1] * m[4]) * r;
    t[12] = -(t[0] * m[12] + t[4] * m[13] + t[8] * m[14]);
    t[13] = -(t[1] * m[12] + t[5] * m[13] + t[9] * m[14]);
    t[14] = -(t[2] * m[12] + t[6] * m[13] + t[10] * m[14]);
    memcpy(m, t, 64);
    m[11] = 0.0f;
    m[7] = 0.0f;
    m[3] = 0.0f;
    m[15] = 1.0f;
}


// 0x0022cf90 FUN_0022cf90 (371 B): equivalent/0x0022cf90.cpp [wrapped: helper definitions (5 out-of-line function bodies)]
// sym: ?FUN_0022cf90@Mat3@fn_0022cf90@@QAE_NXZ @da6466141410 @wb3fad1665885
namespace fn_0022cf90 {
// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 11/12, incomplete)
// FUN_0022cf90 @ 0x0022cf90

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif

extern "C" bool FUN_00018960(float a, float b, float eps);

struct Mat3 {
    float r0[3]; float p0;
    float r1[3]; float p1;
    float r2[3]; float p2;
    bool FUN_0022cf90();
};

static float Len(const float* v)
{
    return (float)sqrt((double)(v[2] * v[2] + v[1] * v[1] + v[0] * v[0]));
}
static double LenD(const float* v)
{
    return sqrt((double)(v[2] * v[2] + v[1] * v[1] + v[0] * v[0]));
}
static float LenXYZ(const float* v)
{
    return (float)sqrt((double)(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}
static double Abs(double v)
{
    return v < 0.0f ? -v : v;
}

bool Mat3::FUN_0022cf90()
{
    const float eps = 1e-05f;
    float len1 = LenXYZ(r1);
    float len2 = LenXYZ(r2);
    float d10 = r1[1] * r0[1] + r1[2] * r0[2] + r1[0] * r0[0];
    float d21 = r2[2] * r1[2] + r2[1] * r1[1] + r2[0] * r1[0];
    float d20 = r2[1] * r0[1] + r2[2] * r0[2] + r2[0] * r0[0];
    double len0 = LenD(r0);
    if (!(Abs(len0 - 1.0) <= eps)) return false;
    if (!(Abs(len1 - 1.0f) <= eps)) return false;
    if (!(Abs(len2 - 1.0f) <= eps)) return false;
    if (!(Abs(d10) <= eps)) return false;
    if (!FUN_00018960(d21, 0.0f, eps)) return false;
    if (!FUN_00018960(d20, 0.0f, eps)) return false;
    return true;
}
} // namespace fn_0022cf90

namespace fn_f0c6a717 {

// 0x0022d110 FUN_0022d110 (99 B): matches/0x0022d110.cpp
// sym: ?Normalize@Vec_22d110@fn_f0c6a717@@QAEMXZ
// data: gSmall = DAT_004275c4, gZero = DAT_003f32e0
// x87: the squared length, the root and its reciprocal stay in registers, and the length comes back unrounded in st0
// (hulk_freg return: double natively, bound to the callers' float declarations by tools/native_link.py, which on x87
// read it from st0 the same way); the sum is x*x + y*y, then + z*z (the listing order)
hulk_freg Vec_22d110::Normalize() {
    hulk_freg n = (hulk_freg)x * x + (hulk_freg)y * y + (hulk_freg)z * z;
    if (n >= DAT_004275c4) {
        hulk_freg s = sqrt(n);
        s = DAT_003f32dc / s;
        x *= s;
        y *= s;
        z *= s;
        return DAT_003f32dc / s;
    }
    hulk_freg result = DAT_003f32e0;
    x = y = z = 0;
    return result;
}


// 0x0022d180 FUN_0022d180 (59 B): matches/0x0022d180.cpp
// sym: ?Normalize@fn_f0c6a717@@YIXPAMPAX@Z
// data: one = DAT_003f32dc
// x87: the squared length (x*x + y*y, then + z*z), its root and the reciprocal stay in registers; MSVC drops the
// (float) cast of sqrt's result
void __fastcall Normalize(float* p, void*) {
    hulk_freg s = (hulk_freg)p[0] * p[0] + (hulk_freg)p[1] * p[1] + (hulk_freg)p[2] * p[2];
    hulk_freg f = DAT_003f32dc / (hulk_freg)sqrt((double)s);
    p[0] = f * p[0];
    p[1] = f * p[1];
    p[2] = f * p[2];
}

} // namespace fn_f0c6a717

// 0x0022d1c0 FUN_0022d1c0 (65 B): matches/0x0022d1c0.cpp
// sym: ?FUN_0022d1c0@Vec3_22d1c0@owners@@QAEXPBU12@@Z
// data: one = DAT_003f32dc
// x87: the squared length (x*x + y*y, then + z*z), its root and the reciprocal stay in registers; MSVC drops the
// (float) cast of sqrt's result
void owners::Vec3_22d1c0::FUN_0022d1c0(const owners::Vec3_22d1c0* p) {
    hulk_freg s = (hulk_freg)p->x * p->x + (hulk_freg)p->y * p->y + (hulk_freg)p->z * p->z;
    hulk_freg f = DAT_003f32dc / (hulk_freg)sqrt((double)s);
    x = f * p->x;
    y = f * p->y;
    z = f * p->z;
}


// 0x0022d240 FUN_0022d240 (18 B): matches/0x0022d240.cpp
// sym: ?FUN_0022d240@C_22d240@owners@@QAEXHH@Z
void owners::C_22d240::FUN_0022d240(hulk_intptr a, hulk_intptr b) {
    ((H*)((hulk_intptr)b))->Run(((int)a), (hulk_intptr)this);
}


// 0x0022d290 FUN_0022d290 (18 B): matches/0x0022d290.cpp
// sym: ?FUN_0022d290@C_22d290@owners@@QAEXHH@Z
// Same code shape as 0x0022d240 (propagated; names are from that function)
void owners::C_22d290::FUN_0022d290(hulk_intptr a, hulk_intptr b) {
    ((H*)((hulk_intptr)b))->Run(((int)a), (hulk_intptr)this);
}


// 0x0022d2b0 FUN_0022d2b0 (114 B): matches/0x0022d2b0.cpp
// sym: ?FUN_0022d2b0@V_22d2b0@owners@@QAEHPAU12@M@Z
int owners::V_22d2b0::FUN_0022d2b0(owners::V_22d2b0* other, float limit) {
    float d = x - other->x;
    *(int*)&d &= 0x7fffffff;
    if (d <= limit) {
        d = y - other->y;
        *(int*)&d &= 0x7fffffff;
        if (d <= limit) {
            d = z - other->z;
            *(int*)&d &= 0x7fffffff;
            if (d <= limit)
                return 1;
        }
    }
    return 0;
}

namespace fn_f0c6a717 {

// 0x0022d330 FUN_0022d330 (99 B): matches/0x0022d330.cpp
// sym: ?IsSmall@V3_22d330@fn_f0c6a717@@QAEIXZ
unsigned V3_22d330::IsSmall() {
    if (Abs(x) < 1e-05f)
        if (Abs(y) < 1e-05f)
            if (Abs(z) < 1e-05f)
                return 1;
    return 0;
}


// 0x0022d3a0 FUN_0022d3a0 (141 B): equivalent/0x0022d3a0.cpp
// sym: _FUN_0022d3a0 @3a97d80c151f @w753561835220
// STATUS: equivalent (tools/equiv.py level 3: 20017 inputs, branch coverage 6/6)
// FUN_0022d3a0 @ 0x0022d3a0
// Distance along `dir` from point `b` to point `a`, clamped to [0, limit]; 0 when limit is 0.
extern "C" void FUN_0022d3a0(const Vec3_22d3a0* a, const Vec3_22d3a0* b, const Vec3_22d3a0* dir, float limit, float* out)
{
    if (limit == 0.0f) {
        *out = 0.0f;
        return;
    }
    hulk_freg t = (a->z - b->z) * dir->z + (a->y - b->y) * dir->y + (a->x - b->x) * dir->x;
    if (t <= 0.0f) {
        *out = 0.0f;
        return;
    }
    if (t >= limit) {
        *out = limit;
    } else {
        *out = t;
    }
}


// 0x0022d550 FUN_0022d550 (465 B): equivalent/0x0022d550.cpp
// sym: _FUN_0022d550 @5bfd19ade526 @w0e6af82aac5e
// STATUS: equivalent (tools/equiv.py level 3: 20019 inputs, branch coverage 10/10)
// FUN_0022d550 @ 0x0022d550
// Closest approach between a line (point P + t * dir ...) and a segment, see out parameters.
extern "C" char FUN_0022d550(const V3_22d550 *s, const V3_22d550 *dir, const V3_22d550 *p, const V3_22d550 *t, float *outA, float *outB)
{
    V3_22d550 d1;
    d1.x = s->x - p->x;
    d1.y = s->y - p->y;
    d1.z = s->z - p->z;
    V3_22d550 d2;
    d2.x = t->x - p->x;
    d2.y = t->y - p->y;
    d2.z = t->z - p->z;
    float len = (float)sqrt(d2.z * d2.z + d2.y * d2.y + d2.x * d2.x);
    d2.FUN_0022d180();

    hulk_freg a = dir->y * dir->y + dir->z * dir->z + dir->x * dir->x;
    float b = d2.x * dir->x + d2.y * dir->y + d2.z * dir->z;
    hulk_freg e = d2.z * d2.z + d2.y * d2.y + d2.x * d2.x;
    float c = d1.z * dir->z + d1.x * dir->x + d1.y * dir->y;
    hulk_freg f = d2.z * d1.z + d2.x * d1.x + d2.y * d1.y;

    hulk_freg denom = e * a - b * b;
    if (denom < 1e-5f) {
        *outB = 0;
        *outA = -(c / a);
        return 0;
    }
    hulk_freg inv = 1.0f / denom;
    *outA = (f * b - c * e) * inv;
    hulk_freg tt = (f * a - c * b) * inv;
    *outB = tt;
    if (!(tt < 0.0f) && !(len < tt))
        return 1;
    if (tt < 0.0f)
        *outB = 0;
    if (*outB > len)
        *outB = len;
    *outA = (b * *outB - c) / a;
    return 1;
}


// 0x0022d730 FUN_0022d730 (1065 B): equivalent/0x0022d730.cpp
// sym: _FUN_0022d730 @9e607b5414af @wd21a1cdac70a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 50/50)
// FUN_0022d730 @ 0x0022d730
extern "C" bool FUN_0022d730(const V3_22d730 *p1, const V3_22d730 *d1, float smax, const V3_22d730 *p2, const V3_22d730 *d2,
                  float tmax, float *sOut, float *tOut)
{
    double x0 = p1->x - p2->x;
    double y0 = p1->y - p2->y;
    double z0 = p1->z - p2->z;
    float b = d1->x * d2->x + d1->z * d2->z + d1->y * d2->y;
    float c = z0 * d1->z + y0 * d1->y + x0 * d1->x;
    float f = (x0 * d2->x + z0 * d2->z) + y0 * d2->y;
    float denom = 1.0f - b * b;

    if (denom >= 0.00001f) {
        double inv = 1.0 / denom;
        *sOut = (f * b - c) * inv;
        float t = (f - c * b) * inv;
        *tOut = t;
        volatile bool inRange = (0.0f <= *sOut && *sOut <= smax && 0.0f <= t && t <= tmax);
        if (inRange)
            return true;
    }

    bool sOutside = (*sOut < 0.0f) || (*sOut > smax);
    bool tOutside = (*tOut < 0.0f) || (*tOut > tmax);

    if (!sOutside) {
        float tt = (*tOut < 0.0f) ? 0.0f : tmax;
        *tOut = tt;
        double sp = tt * b - c;
        *sOut = (float)sp;
        if (sp < 0.0)
            *sOut = 0.0f;
        else if (sp > smax)
            *sOut = smax;
    } else if (!tOutside) {
        float sc = (*sOut < 0.0f) ? 0.0f : smax;
        *sOut = sc;
        double tp = sc * b + f;
        *tOut = (float)tp;
        if (tp < 0.0)
            *tOut = 0.0f;
        else if (tp > tmax)
            *tOut = tmax;
    } else {
        float sc = (*sOut < 0.0f) ? 0.0f : smax;
        double uu = sc * b + f;
        float tc = (float)uu;
        if (uu < 0.0)
            tc = 0.0f;
        else if (tc > tmax)
            tc = tmax;
        float ts = (*tOut < 0.0f) ? 0.0f : tmax;
        double sv = ts * b - c;
        if (sv < 0.0)
            sv = 0.0f;
        else if (sv > smax)
            sv = smax;

        volatile float qx = tc * d2->x + p2->x;
        double qy = tc * d2->y + p2->y;
        volatile float qz0 = tc * d2->z;
        double qz = qz0 + p2->z;
        volatile float scz0 = sc * d1->z;
        volatile float px = sc * d1->x + p1->x;
        double py = sc * d1->y + p1->y;
        volatile float pz = scz0 + p1->z;
        volatile float dx1 = px - qx;
        volatile float dy1 = py - qy;
        double dz1 = pz - qz;

        volatile float q2x = ts * d2->x + p2->x;
        double q2y = ts * d2->y + p2->y;
        volatile float q2z0 = ts * d2->z;
        double q2z = q2z0 + p2->z;
        volatile float svz0 = sv * d1->z;
        volatile float p2x = sv * d1->x + p1->x;
        volatile float p2y = sv * d1->y + p1->y;
        double p2z = svz0 + p1->z;
        volatile float dx2 = p2x - q2x;
        volatile float dy2 = p2y - q2y;
        double dz2 = p2z - q2z;

        double n1 = dz1 * dz1 + dy1 * dy1 + dx1 * dx1;
        double n2 = dz2 * dz2 + dy2 * dy2 + dx2 * dx2;
        if (n1 < n2) {
            *sOut = sc;
            *tOut = tc;
        } else {
            *sOut = (float)sv;
            *tOut = ts;
        }
    }
    return denom >= 0.00001f;
}


// 0x0022db60 FUN_0022db60 (779 B): equivalent/0x0022db60.cpp
// sym: ?FUN_0022db60@fn_f0c6a717@@YA_NTSlot_22db60@1@00PAUV3_22db60@1@M0PAM@Z @04de11224171 @w8249f57e067d
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_0022db60 @ 0x0022db60
bool __cdecl FUN_0022db60(Slot_22db60 a1, Slot_22db60 a2, Slot_22db60 a3, V3_22db60 *a4, float a5, Slot_22db60 a6, float *a7)
{
    Frame_22db60 f;
    V3_22db60 *u = a2.v;
    V3_22db60 *p3 = a3.v;
    V3_22db60 *p1 = a1.v;
    V3_22db60 *c = a4;

    a1.b = 1;
    f.t[0] = p1->x - p3->x;
    f.t[1] = p1->y - p3->y;
    f.t[2] = p1->z - p3->z;
    f.uu = u->x * u->x + u->y * u->y + u->z * u->z;
    double ud = u->x * c->x + u->z * c->z + u->y * c->y;
    a2.f = c->x * c->x + c->y * c->y + c->z * c->z;
    double e = f.t[0] * u->x + f.t[1] * u->y + f.t[2] * u->z;
    a3.f = f.t[0] * c->x + f.t[1] * c->y + f.t[2] * c->z;

    if (ud < 0.0f) {
        ud = -ud;
        a1.b = 0;
        a3.f = -a3.f;
    }

    double den = a2.f * f.uu - ud * ud;
    float *out6;
    float *out7;
    if (den < 1e-05f) {
        double s;
        if (ud > a2.f)
            s = e / ud;
        else
            s = a3.f / a2.f;
        out7 = a7;
        out6 = a6.fp;
        *out7 = (float)s;
        if (s > 0.0f) {
            *out6 = 0.0f;
        } else {
            *out6 = (float)-s;
            *out7 = 0.0f;
        }
    } else {
        double inv = 1.0f / den;
        out6 = a6.fp;
        out7 = a7;
        *out6 = (float)((a3.f * ud - e * a2.f) * inv);
        *out7 = (float)((a3.f * f.uu - e * ud) * inv);
    }

    double p = *out6;
    bool sgn = a1.b != 0;
    f.t[1] = p * u->y;
    f.t[2] = p * u->z;
    double qx = p * u->x + p1->x;
    f.Qy = f.t[1] + p1->y;
    f.Qz = f.t[2] + p1->z;

    float *r;
    double q = *out7;
    if (sgn) {
        f.t[1] = q * c->y;
        f.t[2] = q * c->z;
        f.R[0] = q * c->x + p3->x;
        f.R[1] = f.t[1] + p3->y;
        f.R[2] = f.t[2] + p3->z;
        r = f.R;
    } else {
        f.R[1] = q * c->y;
        f.R[2] = q * c->z;
        f.Rp[0] = p3->x - q * c->x;
        f.Rp[1] = p3->y - f.R[1];
        f.Rp[2] = p3->z - f.R[2];
        r = f.Rp;
    }

    f.t[0] = r[0];
    double dx = f.t[0] - qx;
    f.t[1] = r[1];
    double dy = f.t[1] - f.Qy;
    f.t[2] = r[2];
    double dz = f.t[2] - f.Qz;
    double dist = sqrt(dz * dz + dy * dy + dx * dx);
    a6.f = (float)dist;
    if (dist > a5)
        return false;

    double wx, wy, wz;
    if (sgn) {
        wx = c->x - u->x;
        wy = c->y - u->y;
        wz = c->z - u->z;
    } else {
        wx = u->x + c->x;
        wy = u->y + c->y;
        wz = u->z + c->z;
    }
    double norm = sqrt(wz * wz + wy * wy + wx * wx);
    double h = sqrt(a5 * a5 - a6.f * a6.f);
    double rr = h / norm;
    *out6 = *out6 - rr;
    if (sgn)
        *out7 = *out7 - rr;
    else
        *out7 = rr - *out7;
    return true;
}


// 0x0022de70 FUN_0022de70 (291 B): equivalent/0x0022de70.cpp
// sym: _FUN_0022de70 @3d613220a376 @wfe765a04c743
// STATUS: equivalent (tools/equiv.py level 3: 20017 inputs, branch coverage 2/2)
// FUN_0022de70 @ 0x0022de70
extern "C" bool __cdecl FUN_0022de70(const Vec3_22de70* point, const Vec3_22de70* direction, const Vec3_22de70* planePoint, const Vec3_22de70* normal, Vec3_22de70* result, float* parameter) {
    hulk_freg planeDot = normal->z * planePoint->z + normal->y * planePoint->y + planePoint->x * normal->x;
    hulk_freg denominator = direction->y * normal->y + direction->x * normal->x + normal->z * direction->z;
    union { float f; unsigned int u; } magnitude;
    magnitude.f = denominator; magnitude.u &= 0x7fffffff;
    if (!(magnitude.f < 1e-05f)) {
        hulk_freg pointDot = point->z * normal->z + point->y * normal->y + point->x * normal->x;
        hulk_freg t = (planeDot - pointDot) * (1.0f / denominator);
        *parameter = t;
        hulk_freg x = t * direction->x;
        volatile float y = t * direction->y;
        volatile float z = t * direction->z;
        hulk_freg rx = x + point->x;
        hulk_freg ry = y + point->y;
        hulk_freg rz = z + point->z;
        result->x = rx; result->y = ry; result->z = rz;
        return true;
    }
    hulk_freg t = (point->z - planePoint->z) * normal->z + (point->x - planePoint->x) * normal->x + (point->y - planePoint->y) * normal->y;
    *parameter = t;
    hulk_freg x = t * normal->x;
    volatile float y = t * normal->y;
    volatile float z = t * normal->z;
    hulk_freg rx = point->x - x;
    hulk_freg ry = point->y - y;
    hulk_freg rz = point->z - z;
    result->x = rx; result->y = ry; result->z = rz;
    return false;
}


// 0x0022dfe0 FUN_0022dfe0 (147 B): equivalent/0x0022dfe0.cpp
// sym: ?FUN_0022dfe0@Plane_22dfe0@fn_f0c6a717@@QAEXPBUVec3_22dfe0@2@00@Z @7bf7b97b9036 @wa7ebb3c2f7e9
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_0022dfe0 @ 0x0022dfe0
// Plane through three points: normal = (b - a) x (c - a), d = -dot(a, normal).
void Plane_22dfe0::FUN_0022dfe0(const Vec3_22dfe0 *a, const Vec3_22dfe0 *b, const Vec3_22dfe0 *c)
{
    hulk_freg ux = b->x - a->x;
    hulk_freg uy = b->y - a->y;
    hulk_freg uz = b->z - a->z;
    volatile float vx = c->x - a->x;
    volatile float vy = c->y - a->y;
    hulk_freg vz = c->z - a->z;
    normal.x = vz * uy - vy * uz;
    normal.y = uz * vx - vz * ux;
    normal.z = vy * ux - vx * uy;
    FUN_0022d180();
    d = -(a->x * normal.x + a->z * normal.z + a->y * normal.y);
}

} // namespace fn_f0c6a717

// 0x0022e080 FUN_0022e080 (115 B): equivalent/0x0022e080.cpp
// sym: ?FUN_0022e080@Plane_22e080@owners@@QAE_NPBM@Z @c1f1b02de214 @w7aa4de3d3771
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0022e080 @ 0x0022e080
bool owners::Plane_22e080::FUN_0022e080(const float *box)
{
    float x = (nx >= 0.0f) ? box[0] : box[3];
    float y = (ny >= 0.0f) ? box[1] : box[4];
    float z = (nz >= 0.0f) ? box[2] : box[5];
    return -w >= ((z * nz + x * nx) + y * ny);
}

namespace fn_f0c6a717 {

// 0x0022e100 FUN_0022e100 (115 B): equivalent/0x0022e100.cpp
// sym: ?FUN_0022e100@Plane_22e100@fn_f0c6a717@@QAE_NPBM@Z @a25ac1ef4dd9 @w6925c755bd43
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0022e100 @ 0x0022e100
bool Plane_22e100::FUN_0022e100(const float *box)
{
    float x = (nx < 0.0f) ? box[0] : box[3];
    float y = (ny < 0.0f) ? box[1] : box[4];
    float z = (nz < 0.0f) ? box[2] : box[5];
    return -w >= ((z * nz + x * nx) + y * ny);
}


// 0x0022e1f0 FUN_0022e1f0 (136 B): equivalent/0x0022e1f0.cpp
// sym: ?FUN_0022e1f0@Plane_22e1f0@fn_f0c6a717@@QAE_NPBUVec3_22e1f0@2@0PAM@Z @39c86fc7eeab @wb6baff4b705b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0022e1f0 @ 0x0022e1f0
// Segment a-b against the plane: true (and the crossing fraction in *t) when the endpoints lie on opposite sides.
bool Plane_22e1f0::FUN_0022e1f0(const Vec3_22e1f0 *a, const Vec3_22e1f0 *b, float *t)
{
    FloatBits_22e1f0 da, db;
    da.f = (a->z * normal.z + a->y * normal.y) + a->x * normal.x + d;
    double distB = (b->z * normal.z + b->y * normal.y) + b->x * normal.x + d;
    db.f = (float)distB;
    if ((db.i ^ da.i) >= 0)
        return false;
    double diff = da.f - distB;
    FloatBits_22e1f0 span;
    span.f = (float)diff;
    span.i &= 0x7fffffff;
    if (span.f <= 1e-5f)
        return false;
    *t = da.f / diff;
    return true;
}

} // namespace fn_f0c6a717

// 0x0022e320 FUN_0022e320 (14 B): matches/0x0022e320.cpp
// sym: ?FUN_0022e320@Obj_22e320@owners@@QAEXI@Z
void owners::Obj_22e320::FUN_0022e320(u32_22e320 param2) {
    ((This_FUN_0022e180*)this)->FUN_0022e180(param2, (hulk_uintptr)this);
}

namespace fn_f0c6a717 {

// 0x0022e340 FUN_0022e340 (8 B): matches/0x0022e340.cpp
// sym: _FUN_0022e340
extern "C" void FUN_0022e340(void) {
    (*(unsigned char*)&DAT_004e5ae4) = 1;
}


// 0x0022e470 FUN_0022e470 (136 B): matches/0x0022e470.cpp
// sym: ?Copy@Foo_22e470@fn_f0c6a717@@QAEAAV12@ABV12@@Z
Foo_22e470& Foo_22e470::Copy(const Foo_22e470& o) {
    m = o.m;
    v0 = o.v0;
    v1 = o.v1;
    v2 = o.v2;
    v3 = o.v3;
    return *this;
}


// 0x0022e500 FUN_0022e500 (330 B): equivalent/0x0022e500.cpp
// sym: ?FUN_0022e500@Curve_22e500@fn_f0c6a717@@QAEXHPBUVec3_22e500@2@000@Z @34f9270aeeea @w0f7708b6819c
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 11/11)
// FUN_0022e500 @ 0x0022e500
void Curve_22e500::FUN_0022e500(int type, const Vec3_22e500 *p0, const Vec3_22e500 *p1, const Vec3_22e500 *p2, const Vec3_22e500 *p3)
{
    Matrix4_22e500 g;
    g.row[0].x = p0->x;
    g.row[0].y = p0->y;
    g.row[0].z = p0->z;
    g.row[0].w = 1.0f;
    g.row[1].x = p1->x;
    g.row[1].y = p1->y;
    g.row[1].z = p1->z;
    g.row[1].w = 1.0f;
    g.row[2].x = p2->x;
    g.row[2].y = p2->y;
    g.row[2].z = p2->z;
    g.row[2].w = 1.0f;
    g.row[3].x = p3->x;
    g.row[3].y = p3->y;
    g.row[3].z = p3->z;
    g.row[3].w = 1.0f;
    switch (type) {
    case 0:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004c9fa8)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 1:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004c9fe8)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 2:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca028)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 3:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca068)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 4:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca0a8)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 5:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca0e8)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 6:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca128)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 7:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca168)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 8:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca1a8)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    }
}


// 0x0022e670 FUN_0022e670 (326 B): equivalent/0x0022e670.cpp
// sym: ?FUN_0022e670@Curve_22e670@fn_f0c6a717@@QAEXHPBUVec4_22e670@2@000@Z @d44e3b70d003 @wfb69971675e8
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 11/11)
// FUN_0022e670 @ 0x0022e670
void Curve_22e670::FUN_0022e670(int type, const Vec4_22e670 *p0, const Vec4_22e670 *p1, const Vec4_22e670 *p2, const Vec4_22e670 *p3)
{
    Matrix4_22e670 g;
    g.row[0] = *p0;
    g.row[1] = *p1;
    g.row[2] = *p2;
    g.row[3] = *p3;
    switch (type) {
    case 0:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e670 *)(((Matrix4_22e670*)&DAT_004c9fa8)), (const owners::Matrix_22cc10 *)(Matrix4_22e670 *)(&g));
        break;
    case 1:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e670 *)(((Matrix4_22e670*)&DAT_004c9fe8)), (const owners::Matrix_22cc10 *)(Matrix4_22e670 *)(&g));
        break;
    case 2:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e670 *)(((Matrix4_22e670*)&DAT_004ca028)), (const owners::Matrix_22cc10 *)(Matrix4_22e670 *)(&g));
        break;
    case 3:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e670 *)(((Matrix4_22e670*)&DAT_004ca068)), (const owners::Matrix_22cc10 *)(Matrix4_22e670 *)(&g));
        break;
    case 4:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e670 *)(((Matrix4_22e670*)&DAT_004ca0a8)), (const owners::Matrix_22cc10 *)(Matrix4_22e670 *)(&g));
        break;
    case 5:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e670 *)(((Matrix4_22e670*)&DAT_004ca0e8)), (const owners::Matrix_22cc10 *)(Matrix4_22e670 *)(&g));
        break;
    case 6:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e670 *)(((Matrix4_22e670*)&DAT_004ca128)), (const owners::Matrix_22cc10 *)(Matrix4_22e670 *)(&g));
        break;
    case 7:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e670 *)(((Matrix4_22e670*)&DAT_004ca168)), (const owners::Matrix_22cc10 *)(Matrix4_22e670 *)(&g));
        break;
    case 8:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e670 *)(((Matrix4_22e670*)&DAT_004ca1a8)), (const owners::Matrix_22cc10 *)(Matrix4_22e670 *)(&g));
        break;
    }
}


// 0x0022eb00 FUN_0022eb00 (131 B): equivalent/0x0022eb00.cpp
// sym: ?FUN_0022eb00@Integrator@fn_f0c6a717@@QAEXPAUVec3_22eb00@2@@Z @b747ec3f296e @w98948cc928e0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022eb00 @ 0x0022eb00
void Integrator::FUN_0022eb00(Vec3_22eb00 *out)
{
    pos.x = vx + pos.x;
    pos.y = vy + pos.y;
    pos.z = vz + pos.z;
    vx = ax + vx;
    vy = vy + ay;
    vz = vz + az;
    ax = jx + ax;
    ay = jy + ay;
    az = jz + az;
    out->x = pos.x;
    out->y = pos.y;
    out->z = pos.z;
}


// 0x0022ec20 FUN_0022ec20 (32 B): matches/0x0022ec20.cpp
// sym: ?f@C_22ec20@fn_f0c6a717@@QAEXXZ
void C_22ec20::f() {
    thunk(a);
    thunk(b);
}


// 0x0022eda0 FUN_0022eda0 (149 B): matches/0x0022eda0.cpp
// sym: ?Target@Obj_22eda0@fn_f0c6a717@@QAEXI@Z
void Obj_22eda0::Target(unsigned int n) {
    m0 = -1;
    m1 = -1;
    if (count != n) {
        ReleaseThing_0008d330(data1);
        ReleaseThing_0008d330(data2);
        data1 = 0;
        data2 = 0;
        count = n;
        if (n > 0) {
            void* p = Alloc_0008d690(n << 4);
            if (p)
                Init_00011520(p, 0x10, n, (void (*)())ElemCtor_000a9e50);
            else
                p = 0;
            data1 = p;
        }
    }
}

} // namespace fn_f0c6a717

// 0x0022ef20 FUN_0022ef20 (130 B): matches/0x0022ef20.cpp
// sym: ?FUN_0022ef20@Obj_22ef20@owners@@QAEDHM@Z
char owners::Obj_22ef20::FUN_0022ef20(int index, float value) {
    int i = (int)value;
    if (i == (int)mCache[index])
        return 0;
    unsigned int q = mDiv, b = mBase;
    unsigned int a = ((i + 3) % q) * 16 + b, c = ((i + 2) % q) * 16 + b, d = ((i + 1) % q) * 16 + b,
                 e = (i % q) * 16 + b;
    Sub_22ef20* sub = (Sub_22ef20*)((char*)this + 8 + index * 128);
    sub->Update_0022e670(mSize, e, d, c, a);
    mCache[index] = i;
    return 1;
}

namespace fn_f0c6a717 {

// 0x0022efb0 FUN_0022efb0 (161 B): equivalent/0x0022efb0.cpp
// sym: ?FUN_0022efb0@Track@fn_f0c6a717@@QAEHHM@Z @824777df0400 @w538579847705
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// FUN_0022efb0 @ 0x0022efb0
// FUN_0022efb0 @ 0x0022efb0: clamps a fractional position into [0, count], then moves the cursor there
int Track::FUN_0022efb0(int target, float position)
{
    if (position < 0.0f)
        position = 0.0f;
    unsigned int limit = fromEnd ? count : count - 3;
    if ((double)limit < position)
        position = (float)limit;
    ((owners::Obj_22ef20 *)this)->FUN_0022ef20(0, position);
    cursor.FUN_0022e890(target, position - (float)first);
    return target;
}


// 0x0022f060 FUN_0022f060 (186 B): equivalent/0x0022f060.cpp
// sym: ?FUN_0022f060@Object@fn_f0c6a717@@QAEPAXPAXII@Z @65691faf19a1 @w18fa06d50b82
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_0022f060 @ 0x0022f060
void* Object::FUN_0022f060(void* destination, unsigned int step, unsigned int requested) {
 unsigned int limit = count;
 if (!mode) limit -= 3;
 if ((double)limit < (double)requested) {
   unsigned int cap = count;
   if (!mode) cap -= 3;
   volatile double converted = (double)cap;
   requested = (unsigned int)converted;
 }
 total = step * requested;
 stride = step;
 ((owners::Obj_22ef20 *)this)->FUN_0022ef20(1, (float)requested);
 buffer.FUN_0022e930(destination, stride);
 return destination;
}


// 0x0022f120 FUN_0022f120 (262 B): equivalent/0x0022f120.cpp
// sym: ?FUN_0022f120@Animator_22f120@fn_f0c6a717@@QAEPAXPAX@Z @4dee2c1c4668 @wd4464c9b988f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_0022f120 @ 0x0022f120
void* Animator_22f120::FUN_0022f120(void* output) {
    int next = (int)((unsigned int)tick + 1u);
    float position = (float)((double)next / (double)divisor);
    unsigned char loop = looping;
    tick = next;
    if (loop && (double)position == (double)count) {
        tick = 0;
        position = 0.0f;
    } else if (position < 0.0f) {
        position = 0.0f;
    }
    unsigned int limit = loop ? count : count - 3u;
    if ((double)limit < (double)position)
        position = (float)limit;
    if (FUN_0022ef20(1, position))
        state.FUN_0022e930(output, divisor);
    else
        state.FUN_0022eb00(output);
    return output;
}


// 0x0022f230 FUN_0022f230 (456 B): equivalent/0x0022f230.cpp
// sym: ?FUN_0022f230@Shape_22f230@fn_f0c6a717@@QAEPAU12@PBU12@@Z @393b9728d232 @w692cde685c0f
// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 24/24)
// FUN_0022f230 @ 0x0022f230
Shape_22f230* Shape_22f230::FUN_0022f230(const Shape_22f230* src)
{
    f00 = src->f00;
    f04 = src->f04;
    flag108 = src->flag108;
    m08.FUN_0022e470(&src->m08);
    m88.FUN_0022e470(&src->m88);
    f10c = src->f10c;
    extra = 0;
    unsigned int n = src->count;
    count = n;
    if (n != 0) {
        Elem_22f230* e = (Elem_22f230*)FUN_0008d690(n << 4);
        if (e != 0)
            FUN_00011520(e, 0x10, n, (void (*)(void*))FUN_000a9e50);
        elems = e;
    }
    for (unsigned int i = 0; i < count; i++) {
        Elem_22f230* d = &elems[i];
        const Elem_22f230* s = &src->elems[i];
        d->w0 = s->w0;
        d->w1 = s->w1;
        d->w2 = s->w2;
        d->w3 = s->w3;
    }
    unsigned int m = count;
    if (m >= 4) {
        if (flag108 == 0)
            m -= 3;
    } else if (flag108 == 0) {
        m = 0;
    }
    m++;
    if (src->extra != 0) {
        extra = (unsigned int*)FUN_0008d690(m * 4);
        for (unsigned int i = 0; i < m; i++)
            extra[i] = src->extra[i];
    }
    f11c = src->f11c;
    f120 = src->f120;
    return this;
}


// 0x0022f400 FUN_0022f400 (472 B): equivalent/0x0022f400.cpp
// sym: ?FUN_0022f400@Shape_22f400@fn_f0c6a717@@QAEPAU12@PBU12@@Z @fd1f6ef5b304 @w656c5b42fa7b
// STATUS: equivalent (tools/equiv.py level 3: 43 inputs, branch coverage 24/24)
// FUN_0022f400 @ 0x0022f400
Shape_22f400* Shape_22f400::FUN_0022f400(const Shape_22f400* src)
{
    f00 = src->f00;
    f04 = src->f04;
    flag108 = src->flag108;
    m08.FUN_0022e470(&src->m08);
    m88.FUN_0022e470(&src->m88);
    f10c = src->f10c;
    FUN_0008d330(elems);
    FUN_0008d330(extra);
    unsigned int n = src->count;
    count = n;
    if (n != 0) {
        Elem_22f400* e = (Elem_22f400*)FUN_0008d690(n << 4);
        if (e != 0)
            FUN_00011520(e, 0x10, n, (void (*)(void*))FUN_000a9e50);
        elems = e;
    }
    for (unsigned int i = 0; i < count; i++) {
        Elem_22f400* d = &elems[i];
        const Elem_22f400* s = &src->elems[i];
        d->w0 = s->w0;
        d->w1 = s->w1;
        d->w2 = s->w2;
        d->w3 = s->w3;
    }
    unsigned int m = count;
    if (m >= 4) {
        if (flag108 == 0)
            m -= 3;
    } else if (flag108 == 0) {
        m = 0;
    }
    m++;
    if (src->extra != 0) {
        extra = (unsigned int*)FUN_0008d690(m * 4);
        for (unsigned int i = 0; i < m; i++)
            extra[i] = src->extra[i];
    }
    f11c = src->f11c;
    f120 = src->f120;
    return this;
}


// 0x0022f760 FUN_0022f760 (126 B): equivalent/0x0022f760.cpp
// sym: ?FUN_0022f760@fn_f0c6a717@@YAMPAUSampler_22f760@1@M@Z @a6b62ce31f00 @w9c890a13a988
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// FUN_0022f760 @ 0x0022f760
// equiv-conv: FUN_0022f760 edi stack
hulk_freg FUN_0022f760(Sampler_22f760* s, float t)
{
    float half = t * 0.5f;
    float acc = 0.0f;
    for (int i = 0; i < 5; i++) {
        Vec3_22f760 v;
        s->FUN_0022e890(&v, half * ((float*)&DAT_00427620)[i] + half);
        acc = (float)(sqrt(v.x * v.x + v.z * v.z + v.y * v.y) * ((float*)&DAT_0042760c)[i] + acc);
    }
    return acc * half;
}


// 0x0022f7e0 FUN_0022f7e0 (370 B): equivalent/0x0022f7e0.cpp
// sym: ?FUN_0022f7e0@Curve_22f7e0@fn_f0c6a717@@QAEMI@Z @ef2393e2869c @we524fe1d23ff
// STATUS: equivalent (tools/equiv.py level 3: 341 inputs, branch coverage 21/22, incomplete)
// FUN_0022f7e0 @ 0x0022f7e0
// equiv-conv: FUN_0022f760 edi stack
float Curve_22f7e0::FUN_0022f7e0(uint_22f7e0 index) {
 uint_22f7e0 spans=count;
 if (!closed) spans=spans<4 ? 0 : spans-3;
 if(cache && cache[index]>=0.0f) return cache[index];
 if(!cache) {
  uint_22f7e0 size=spans+1;
  cache=(float*)FUN_0008d690(size*4);
  for(uint_22f7e0 i=0;i<size;++i) cache[i]=-1.0f;
 }
 ((owners::Obj_22ef20 *)this)->FUN_0022ef20(0, (float)index);
 uint_22f7e0 n=count;
 Point_22f7e0* p=points;
 Segment_22f7e0 segment;
 segment.FUN_0022e670(degree+3,p+(index%n),p+((index+1)%n),p+((index+2)%n),p+((index+3)%n));
 cache[index]=FUN_0022f760(&segment,1.0f);
 return cache[index];
}

} // namespace fn_f0c6a717

// 0x0022f960 FUN_0022f960 (251 B): equivalent/0x0022f960.cpp [wrapped: conflict: Object]
// sym: ?target@Object@fn_0022f960@@QAEMXZ @43978d3237d6 @w6fe9f703410c
namespace fn_0022f960 {
// STATUS: equivalent (tools/equiv.py level 3: 2518 inputs, branch coverage 24/24)
// FUN_0022f960 @ 0x0022f960
// FUN_0022f960 @ 0x0022f960
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(unsigned int bytes);
struct Object {
 char pad[0x108];
 unsigned char enabled;
 char pad109[7];
 unsigned int count;
 char pad114[4];
 float* cache;
 float FUN_0022f7e0(unsigned int index);
 float target();
};
float Object::target() {
 unsigned int n=count;
 if (!enabled) { if(n<4) n=0; else n-=3; }
 if(cache && cache[n]>=0.0f) return cache[n];   // a NaN entry is recomputed
 if(!cache) {
  cache=(float*)FUN_0008d690(n*4+4);
  unsigned int total=n+1;
  unsigned int i=0;
  if((int)total>=4) {
   do {
    cache[i]=-1.0f;
    cache[i+1]=-1.0f;
    cache[i+2]=-1.0f;
    cache[i+3]=-1.0f;
    i+=4;
   } while(i<total-3);
  }
  for(;i<total;++i) cache[i]=-1.0f;
 }
 float sum=0.0f;
 for(unsigned int j=0;j<n;++j) sum=FUN_0022f7e0(j)+sum;
 cache[n]=sum;
 return sum;
}
} // namespace fn_0022f960

namespace fn_f0c6a717 {

// 0x0022fa60 FUN_0022fa60 (331 B): equivalent/0x0022fa60.cpp
// sym: ?FUN_0022fa60@Curve_22fa60@fn_f0c6a717@@QAEMM@Z @83f6c67eb129 @wc2e9e6b54d44
// STATUS: equivalent (tools/equiv.py level 3: 15368 inputs, branch coverage 16/18, incomplete)
// FUN_0022fa60 @ 0x0022fa60
// equiv-conv: FUN_0022f760 edi stack
hulk_freg Curve_22fa60::FUN_0022fa60(float t) {
 if(t < 0.0f) t=0.0f;
 unsigned int limit=closed ? count : count-3;
 if((double)limit < t) t=(hulk_freg)limit;
 unsigned int index=(unsigned int)(int)t;
 float sum=0.0f;
 for(unsigned int i=0;i<index;++i) sum=(hulk_freg)(FUN_0022f7e0(i)+sum);
 ((owners::Obj_22ef20 *)this)->FUN_0022ef20(0, t);
 unsigned int n=count; Point_22fa60* p=points;
 Segment_22fa60 segment;
 segment.FUN_0022e670(degree+3,p+(index%n),p+((index+1)%n),p+((index+2)%n),p+((index+3)%n));
 float fraction=(hulk_freg)(t-(double)index);
 return (hulk_freg)(FUN_0022f760(&segment,fraction)+sum);
}

} // namespace fn_f0c6a717

// 0x0022fe40 FUN_0022fe40 (128 B): equivalent/0x0022fe40.cpp
// sym: ?FUN_0022fe40@Box_22fe40@owners@@QAEPAU12@PAU12@@Z @43f3f4a696a3 @w775ea9b9af15
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0022fe40 @ 0x0022fe40
// 0x0022fe40: write the component-wise normalised (min, max) corners of an axis aligned box
owners::Box_22fe40* owners::Box_22fe40::FUN_0022fe40(owners::Box_22fe40* out)
{
    float lo[3];
    float hi[3];
    for (int i = 2; i >= 0; i--) {
        float a = v[i];
        float b = v[i + 3];
        if (a < b) {
            lo[i] = a;
            hi[i] = b;
        } else {
            lo[i] = b;
            hi[i] = a;
        }
    }
    out->v[0] = lo[0];
    out->v[1] = lo[1];
    out->v[2] = lo[2];
    out->v[3] = hi[0];
    out->v[4] = hi[1];
    out->v[5] = hi[2];
    return out;
}

namespace fn_f0c6a717 {

// 0x0022fec0 FUN_0022fec0 (134 B): equivalent/0x0022fec0.cpp
// sym: ?GetCenter@Bounds_22fec0@fn_f0c6a717@@QAEXPAUCenterRadius@2@@Z @8ad2c8b7e813 @wc17280bc26b6
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// FUN_0022fec0 @ 0x0022fec0
void Bounds_22fec0::GetCenter(CenterRadius *out)
{
    hulk_freg dx = min[0] - max[0];
    hulk_freg dy = min[1] - max[1];
    hulk_freg dz = min[2] - max[2];
    hulk_freg sx = min[0] + max[0];
    hulk_freg sy = max[1] + min[1];
    hulk_freg sz = max[2] + min[2];
    out->x = sx * 0.5f;
    out->y = sy * 0.5f;
    out->z = sz * 0.5f;
    out->radius = (float)sqrt(dz * dz + dx * dx + dy * dy);
}


// 0x0022ff50 FUN_0022ff50 (333 B): equivalent/0x0022ff50.cpp
// sym: ?FUN_0022ff50@Segment_22ff50@fn_f0c6a717@@QAEMPAUVec3_22ff50@2@@Z @844b98866539 @w37da17a84c2e
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 4/4)
// FUN_0022ff50 @ 0x0022ff50
// x87: the segment's deltas go through the frame (rounded); the point's x delta stays in a register, its y and z
// deltas are rounded copies for the distance but unrounded in the dot product; the dot product is compared
// unrounded with 0 and rounded with the squared length and for t. Each sum is one statement per term, in the
// listing's order (MSVC 7.1 reorders a sum written as one expression).
hulk_freg Segment_22ff50::FUN_0022ff50(Vec3_22ff50 *p)
{
    volatile float dx = b.x - a.x;
    volatile float dy = b.y - a.y;
    volatile float dz = b.z - a.z;
    hulk_freg px = p->x - a.x;
    hulk_freg py = p->y - a.y;
    volatile float pyr = py;
    hulk_freg pz = p->z - a.z;
    volatile float pzr = pz;
    hulk_freg dotx = pz * dz;
    dotx += py * dy;
    dotx += px * dx;
    volatile float dot = dotx;
    hulk_freg s;
    if (dotx <= 0.0f) {
        s = (hulk_freg)pzr * pzr;
        s += (hulk_freg)pyr * pyr;
        s += px * px;
        return sqrt(s);
    }
    hulk_freg len2 = (hulk_freg)dz * dz;
    len2 += (hulk_freg)dx * dx;
    len2 += (hulk_freg)dy * dy;
    if (len2 <= dot) {
        hulk_freg ex = p->x - b.x;
        hulk_freg ey = p->y - b.y;
        hulk_freg ez = p->z - b.z;
        s = ez * ez;
        s += ey * ey;
        s += ex * ex;
        return sqrt(s);
    }
    // The original's temporaries st = d*t, c = a + st and e = p - c: MSVC keeps some members in x87 registers
    // (unrounded: hulk_freg) and stores the others (rounded); written as structs so MSVC 7.1 makes the same choice.
    hulk_freg t = dot / len2;
    struct { hulk_freg x; float y, z; } st;
    st.x = dx * t;
    st.y = dy * t;
    st.z = dz * t;
    struct { hulk_freg x, y; float z; } c;
    c.x = st.x + a.x;
    c.y = st.y + a.y;
    c.z = st.z + a.z;
    struct { float x; hulk_freg y, z; } e;
    e.x = p->x - c.x;
    e.y = p->y - c.y;
    e.z = p->z - c.z;
    s = e.z * e.z;
    s += e.y * e.y;
    s += (hulk_freg)e.x * e.x;
    return sqrt(s);
}


// 0x002300a0 FUN_002300a0 (178 B): equivalent/0x002300a0.cpp
// sym: ?distance@Line@fn_f0c6a717@@QAENPBUVec_2300a0@2@@Z @22e0f027c374 @wb17ff611175f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002300a0 @ 0x002300a0
double Line::distance(const Vec_2300a0* p) {
 double dx=(double)end.x-start.x, dy=(double)end.y-start.y;
 volatile float dz=end.z-start.z;
 volatile float t=(((double)p->z-start.z)*dz+((double)p->y-start.y)*dy+((double)p->x-start.x)*dx)/((double)dz*dz+dx*dx+dy*dy);
 volatile float sx=(float)(dx*t);
 volatile float x=sx+start.x;
 volatile float y=(float)(dy*t+start.y);
 double z=(double)dz*t+start.z;
 double px=(double)p->x-x, py=(double)p->y-y, pz=(double)p->z-z;
 return sqrt(pz*pz+py*py+px*px);
}


// 0x00230160 FUN_00230160 (834 B): equivalent/0x00230160.cpp
// sym: ?FUN_00230160@Segment_230160@fn_f0c6a717@@QAEMPAV12@@Z @5af86f5e5267 @w12cbc5f074c8
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 22/22)
// FUN_00230160 @ 0x00230160
hulk_freg Segment_230160::FUN_00230160(Segment_230160* other) {
    float ux = p1.x - p0.x, uy = p1.y - p0.y, uz = p1.z - p0.z;
    float vx = other->p1.x - other->p0.x, vy = other->p1.y - other->p0.y, vz = other->p1.z - other->p0.z;
    float wx = p0.x - other->p0.x, wy = p0.y - other->p0.y, wz = p0.z - other->p0.z;
    float uu = uz * uz + uy * uy + ux * ux;
    float uv = vz * uz + vy * uy + vx * ux;
    float vv = vz * vz + vy * vy + vx * vx;
    float wu = wz * uz + wy * uy + wx * ux;
    float wv = wz * vz + wy * vy + wx * vx;
    float determinant = vv * uu - uv * uv;
    float sDenominator = determinant, tDenominator = determinant;
    float tNumerator;
    double sNumerator;
    if (determinant < 1.0e-5f) {
        sNumerator = 0.0;
        sDenominator = 1.0f;
        tNumerator = wv;
        tDenominator = vv;
    } else {
        sNumerator = wv * uv - wu * vv;
        tNumerator = wv * uu - wu * uv;
        if (sNumerator < 0.0) {
            sNumerator = 0.0;
            tNumerator = wv;
            tDenominator = vv;
        } else if (sNumerator > determinant) {
            sNumerator = determinant;
            tNumerator = wv + uv;
            tDenominator = vv;
        }
    }
    if (tNumerator < 0.0f) {
        tNumerator = 0.0f;
        double boundary = -wu;
        if (boundary < 0.0)
            sNumerator = 0.0;
        else if (boundary > uu)
            sNumerator = sDenominator;
        else {
            sNumerator = boundary;
            sDenominator = uu;
        }
    } else if (tNumerator > tDenominator) {
        tNumerator = tDenominator;
        double boundary = uv - wu;
        if (boundary < 0.0)
            sNumerator = 0.0;
        else if (boundary > uu)
            sNumerator = sDenominator;
        else {
            sNumerator = boundary;
            sDenominator = uu;
        }
    }
    FloatBits_230160 magnitude;
    magnitude.value = (float)sNumerator;
    magnitude.bits &= 0x7fffffff;
    double s = magnitude.value < 1.0e-5f ? 0.0 : sNumerator / sDenominator;
    magnitude.value = tNumerator;
    magnitude.bits &= 0x7fffffff;
    double t = magnitude.value < 1.0e-5f ? 0.0 : tNumerator / tDenominator;
    volatile float tvx = vx * t, tvy = vy * t;
    double tvz = t * vz;
    volatile float suz = uz * s;
    volatile float nearestX = ux * s + wx;
    double nearestY = uy * s + wy;
    volatile float nearestZ = suz + wz;
    volatile float dx = nearestX - tvx, dy = nearestY - tvy;
    double dz = nearestZ - tvz;
    double zy = dz * dz + dy * dy; // keep the original's summation order
    return sqrt(zy + dx * dx);
}


// 0x002304b0 FUN_002304b0 (514 B): equivalent/0x002304b0.cpp
// sym: ?FUN_002304b0@Segment_2304b0@fn_f0c6a717@@QAEMPBU12@@Z @8aa0eb52a22a @wd11ea1e6d0db
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 4/4)
// FUN_002304b0 @ 0x002304b0
hulk_freg Segment_2304b0::FUN_002304b0(const Segment_2304b0* o)
{
    float d1x = p1x - p0x;
    float d1y = p1y - p0y;
    float d1z = p1z - p0z;
    float d2x = o->p1x - o->p0x;
    float d2y = o->p1y - o->p0y;
    float d2z = o->p1z - o->p0z;
    float rx = p0x - o->p0x;
    float ry = p0y - o->p0y;
    float rz = p0z - o->p0z;

    float a = d1z * d1z + d1x * d1x + d1y * d1y;
    float b = d2z * d1z + d2y * d1y + d2x * d1x;
    float c = d2z * d2z + d2y * d2y + d2x * d2x;
    float d = rz * d1z + ry * d1y + rx * d1x;
    float e = rz * d2z + ry * d2y + rx * d2x;

    double s;
    double t;
    double denom = c * a - b * b; // compared unrounded
    if (denom < 1e-5f) {
        s = 0.0f;
        if (b > c)
            t = d / b;
        else
            t = e / c;
    } else {
        float inv = 1.0f / denom;
        s = (e * b - d * c) * inv;
        t = (e * a - d * b) * inv;
    }

    volatile float c2x = d2x * t;
    volatile float c2y = d2y * t;
    double c2z = t * d2z;
    volatile float c1z = d1z * s;
    volatile float xx = d1x * s + rx;
    double yy = d1y * s + ry;
    volatile float zz = c1z + rz;
    volatile float dx = xx - c2x;
    volatile float dy = yy - c2y;
    double dz = zz - c2z;
    double zy = dz * dz + dy * dy; // keep the original's summation order
    return sqrt(zy + dx * dx);
}

} // namespace fn_f0c6a717

// 0x002306c0 FUN_002306c0 (55 B): matches/0x002306c0.cpp
// sym: ?FUN_002306c0@Obj_2306c0@owners@@QAEXH@Z
void owners::Obj_2306c0::FUN_002306c0(hulk_intptr arg) {
    U_2306c0 temp[4];
    ((H*)((hulk_uintptr)arg))->run_0022c310(this, temp);
    a = temp[0];
    b = temp[1];
    c = temp[2];
    d = temp[3];
}

namespace fn_f0c6a717 {

// 0x00230700 FUN_00230700 (18 B): matches/0x00230700.cpp
// sym: ?g@X@fn_f0c6a717@@QAEXHPAVY@2@@Z
void X::g(int a, Y* y) {
    y->Fnf_0022c310(a, this);
}

} // namespace fn_f0c6a717
