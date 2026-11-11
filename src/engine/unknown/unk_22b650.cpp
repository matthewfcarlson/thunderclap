// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022b650..0x0022baf0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fddc1d6f {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fddc1d6f {} using namespace fn_fddc1d6f;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fddc1d6f {
struct Matrix { float m[12]; void FUN_0022b9c0(); };
struct Quaternion_22b650 { float x,y,z,w; void convert(Matrix* out); };
extern "C" hulk_freg __cdecl FUN_00018a20(float);
struct S_22b9c0 {
    unsigned a[11];
};
class Target_22ba00 {
  public:
    char pad0[0xc];
    int a;
    char pad10[0xc];
    int b;
    char pad20[0xc];
    int c;
    char pad30[0xc];
    int d;
};
class X {
  public:
    void f(void*);
};
class Y {
  public:
    void target(X* p);
};


// 0x0022b650 FUN_0022b650 (255 B): equivalent/0x0022b650.cpp
// sym: ?convert@Quaternion_22b650@fn_fddc1d6f@@QAEXPAUMatrix@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0022b650 @ 0x0022b650
void Quaternion_22b650::convert(Matrix* out) {
 float delta=w-1.0f;
 if (delta<0) delta=-delta;
 if (delta<=1e-05f) { out->FUN_0022b9c0(); return; }
 double dx=(double)x*2, dy=(double)y*2;
 float dz=z*2;
 float xw=(float)(dx*w), yw=(float)(dy*w), zw=dz*w;
 float xx=(float)(dx*x), xy=(float)(dy*x), xz=dz*x, yy=(float)(dy*y);
 double yz=dy*z, zz=(double)dz*z;
 out->m[0]=(float)(1.0-(yy+zz));
 out->m[4]=xy-zw;
 out->m[8]=xz+yw;
 out->m[1]=xy+zw;
 out->m[5]=(float)(1.0-(zz+xx));
 out->m[9]=(float)(yz-xw);
 out->m[2]=xz-yw;
 out->m[6]=(float)(yz+xw);
 out->m[10]=1.0f-(yy+xx);
}

} // namespace fn_fddc1d6f

// 0x0022b750 FUN_0022b750 (261 B): equivalent/0x0022b750.cpp
// sym: ?FUN_0022b750@Quaternion_22b750@owners@@QAEXPBU12@0M@Z
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 4/4; Wine build 605 inputs, 4/4)
// FUN_0022b750 @ 0x0022b750
void owners::Quaternion_22b750::FUN_0022b750(const owners::Quaternion_22b750* a,const owners::Quaternion_22b750* b,float t) {
 double dot = (double)a->z*b->z + (double)a->y*b->y + (double)b->w*a->w + (double)a->x*b->x;
 float d=(float)dot;
 float sign=1.0f;
 if(dot<0.0f) { sign=-1.0f; d=-d; dot=d; }
 double first, second;
 if(dot>=0.997222245f) { first=1.0-t; second=(double)sign*t; }
 else {
  // x87: the acos result stays in st0 for the first fsin (1/sin(angle)); its rounded copy (fst) is what the two
  // products (1-t)*angle and angle*t read
  hulk_freg ang=FUN_00018a20(d);
  float angle=(float)ang;
  float inv=(float)(1.0/sin((double)ang));
  first=sin((1.0-t)*angle)*inv;
  second=sin((double)angle*t)*inv*sign;
 }
 x=(float)(first*a->x+second*b->x);
 y=(float)(first*a->y+second*b->y);
 z=(float)(first*a->z+second*b->z);
 w=(float)(first*a->w+second*b->w);
}


// 0x0022b980 FUN_0022b980 (55 B): matches/0x0022b980.cpp [wrapped: conflict: Matrix]
// sym: @FUN_0022b980@4
namespace fn_0022b980 {
typedef unsigned int u32_22b980;
struct Matrix {
    u32_22b980 v[16];
};
extern "C" void __fastcall FUN_0022b980(Matrix* p) {
    p->v[0] = 0x3f800000;
    p->v[1] = 0;
    p->v[2] = 0;
    p->v[3] = 0;
    p->v[4] = 0;
    p->v[5] = 0x3f800000;
    p->v[6] = 0;
    p->v[7] = 0;
    p->v[8] = 0;
    p->v[9] = 0;
    p->v[10] = 0x3f800000;
    p->v[11] = 0;
    p->v[12] = 0;
    p->v[13] = 0;
    p->v[14] = 0;
    p->v[15] = 0x3f800000;
}
} // namespace fn_0022b980

namespace fn_fddc1d6f {

// 0x0022b9c0 FUN_0022b9c0 (34 B): matches/0x0022b9c0.cpp
// sym: ?FUN_0022b9c0@fn_fddc1d6f@@YIXPAUS_22b9c0@1@@Z
void __fastcall FUN_0022b9c0(S_22b9c0* p) {
    p->a[0] = 0x3f800000;
    p->a[1] = 0;
    p->a[2] = 0;
    p->a[4] = 0;
    p->a[5] = 0x3f800000;
    p->a[6] = 0;
    p->a[8] = 0;
    p->a[9] = 0;
    p->a[10] = 0x3f800000;
}

} // namespace fn_fddc1d6f

// 0x0022b9f0 FUN_0022b9f0 (12 B): matches/0x0022b9f0.cpp
// sym: ?FUN_0022b9f0@C_22b9f0@owners@@QAEXXZ
void owners::C_22b9f0::FUN_0022b9f0() {
    c = 0;
    b = 0;
    a = 0;
}

namespace fn_fddc1d6f {

// 0x0022ba00 FUN_0022ba00 (19 B): matches/0x0022ba00.cpp
// sym: ?TargetFn@fn_fddc1d6f@@YIXPAVTarget_22ba00@1@@Z
void __fastcall TargetFn(Target_22ba00* self) {
    self->c = 0;
    self->b = 0;
    self->a = 0;
    self->d = 0x3f800000;
}


// 0x0022ba20 FUN_0022ba20 (13 B): matches/0x0022ba20.cpp
// sym: ?target@Y@fn_fddc1d6f@@QAEXPAVX@2@@Z
void Y::target(X* p) {
    p->f(this);
}

} // namespace fn_fddc1d6f

// 0x0022ba30 FUN_0022ba30 (53 B): matches/0x0022ba30.cpp
// sym: ?FUN_0022ba30@Matrix_22ba30@owners@@QAEXM@Z
void owners::Matrix_22ba30::FUN_0022ba30(float angle) {
    double s = sin(angle);
    m[0] = 0x3f800000;
    m[1] = 0;
    m[2] = 0;
    m[4] = 0;
    m[8] = 0;
    double c = cos(angle);
    ((float*)this)[5] = (float)c;
    ((float*)this)[6] = (float)s;
    ((float*)this)[9] = (float)-s;
    ((float*)this)[10] = (float)c;
}


// 0x0022ba70 FUN_0022ba70 (53 B): matches/0x0022ba70.cpp
// sym: ?FUN_0022ba70@Mat_22ba70@owners@@QAEXM@Z
void owners::Mat_22ba70::FUN_0022ba70(float x) {
    float s = (float)sin(x);
    a[1] = 0;
    a[4] = 0;
    a[5] = 1;
    a[6] = 0;
    a[9] = 0;
    float c = (float)cos(x);
    a[0] = c;
    a[2] = -s;
    a[8] = s;
    a[10] = c;
}


// 0x0022bab0 FUN_0022bab0 (53 B): matches/0x0022bab0.cpp
// sym: ?FUN_0022bab0@Mat_22bab0@owners@@QAEXM@Z
void owners::Mat_22bab0::FUN_0022bab0(float angle) {
    float s = sin(angle);
    v[2] = 0.0f;
    v[6] = 0.0f;
    v[8] = 0.0f;
    v[9] = 0.0f;
    v[10] = 1.0f;
    float c = cos(angle);
    v[0] = c;
    v[1] = s;
    v[4] = -s;
    v[5] = c;
}

