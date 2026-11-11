// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00221b30..0x002222f0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f403c6ef {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f403c6ef {} using namespace fn_f403c6ef;
#include "engine/choreo2.h"

// ---- declarations shared by the functions below
namespace fn_f403c6ef {
struct P_221b30 {
    int a[16];
};
struct Q_221b30 {
    int a[4];
};
class X_221b30 {
  public:
    P_221b30 p;
    Q_221b30 q;
    int c;
    void Copy(const X_221b30&);
};
typedef unsigned int u32_221b70;
struct Block_221b70 {
    u32_221b70 x[16];
};
struct Obj_221b70 {
    Block_221b70 block;
    u32_221b70 a, b, c, d, e;
    void Copy(const Block_221b70* src);
};
struct Pair_221ba0 {
    int a, b, c, d;
};
class Obj_221ba0 {
  public:
    char pad[0x40];
    Pair_221ba0 value;
    int flag;
    void First();
    Obj_221ba0* Run(Pair_221ba0* src, int x);
};
struct P_221be0 {
    int a[16];
};
struct Q_221be0 {
    int a[4];
};
class X_221be0 {
  public:
    P_221be0 p;
    Q_221be0 q;
    int c;
    void Copy(const X_221be0&);
};
class Base_221c20 {
  public:
    void Init();
};
class Thing_221c20 : public Base_221c20 {
    char pad[0x40];
    volatile int a;
    volatile int b;
    volatile int c;
    volatile int d;
    volatile int e;

  public:
    void Run();
};
struct Obj_221c40 {
    char pad[0x40];
    struct Sub {
        void F(Obj_221c40*);
    } sub;
    char pad2[0x0c];
    int state;
    Obj_221c40* target();
};
struct Data_221c60 {
    unsigned int a[16];
};
class C_221c60 {
  public:
    Data_221c60 d;
    char pad[0x10];
    int x;
    void Copy(C_221c60*);
};
struct X {
    int a, b, c;
    char pad0[4];
    int d, e, f;
    char pad1[4];
    int g, h, i;
    char pad2[36];
    int state;
    void Copy(const X* p);
};
struct Sub_221cd0 {
    char pad[0x10];
};
struct C_221cd0 {
    char pad[0x40];
    Sub_221cd0 sub;
    int state;
    void* target();
};
struct Four_221cf0 {
    int x, y, z, w;
};
class Obj_221cf0 {
  public:
    char pad[0x40];
    Four_221cf0 v;
    int flag;
    void Set(const Four_221cf0& p);
};
struct Four {
    int a, b, c, d;
    void Set(int);
};
class Obj {
  public:
    char pad[0x40];
    Four f;
    int flag;
    void Fn(int);
};
class Obj_221d60;
class Elem_221d60 {
  public:
};
class Obj_221d60 {
  public:
    void Fn(Obj_221d60*, float);
    char pad0[0x30];
    float x, y, z;
    char pad3c[4];
    Elem_221d60 elem;
    char pad44[0xc];
    int state;
};
} // namespace fn_f403c6ef
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f403c6ef {
class Obj_221df0;
class Sub_221df0 {
  public:
    void Fn(Obj_221df0*);
};
class Obj_221df0 {
  public:
    char pad[0x40];
    Sub_221df0 sub;
    char pad44[0x0c];
    int state;
    char pad54[0x2c];
    void Run(Obj_221df0*);
};
class Tmp_221df0 {
  public:
    char data[0x40];
};
struct Work_221e60 {
    void First(owners::Obj_221e60*);
};
struct Sub_221eb0 {
    void call(struct Obj_221eb0*);
};
struct Obj_221eb0 {
    char pad[0x40];
    Sub_221eb0 sub;
    char pad2[0xc];
    int state;
    void target();
};
class Inner_221ee0 {
  public:
    char pad[0x10];
};
class Obj_221ee0 {
  public:
    void Run();
    void Other();
    char pad0[0x40];
    Inner_221ee0 inner;
    int state;
};
class Obj2_221f70 {
  public:
    char pad[0x40];
    void callee1(int, int);
};
struct MatrixData_221f90 {
    float matrix[4][4];
    float extra[4];
    bool FUN_00221f90();
};
extern "C" void __fastcall FUN_0022b980(void*);
class Obj_222050 {
  public:
    char pad[0x40];
    volatile int a, b, c, d, e;
    Obj_222050();
};
class Base_222080 {
  public:
    Base_222080();
    char pad[0x40];
};
class Thing_222080 : public Base_222080 {
  public:
    int a;
    int b;
    int c;
    float d;
    int e;
    Thing_222080(int);
};
struct Helper { void FUN_0022b4d0(float *source, Vec3 *out); };
struct Object {
    char pad[0x40];
    Helper helper;
    char pad2[0x0f];
    int mode;
    Vec3 *FUN_00222120(Vec3 *result);
};
struct Arg_222180 {
    char pad0[4];
    int f4;                     // 0x04
};
hulk_freg __cdecl FUN_000189c0(int v);
hulk_freg __cdecl FUN_00224f10(Arg_222180 *a);
struct Pos_222180 {
    int x, y, z;
};
struct Mat_222180 {
    float m[12];
    Pos_222180 pos;                    // 0x30
    float tw;
    void FUN_0022b980();
};
class Node {
public:
    Mat_222180 mat;
    char pad40[0x10];
    int state;                  // 0x50
    void FUN_00222180(Arg_222180 *a);
};
struct Sub40_222230 {
    char pad0[0x10];
    void FUN_0022b650(struct Xform_222230* dst);
};
struct Xform_222230 {
    char pad0[0x40];
    Sub40_222230 sub;          // 0x40
    int mode;           // 0x50
    void FUN_00222230(void* a, void* b);
};
class Member_2222d0 {
  public:
    virtual void f0();
    virtual void f1();
};
class PartitionDriver {
  public:
    virtual ~PartitionDriver();
    char pad[12];
    Member_2222d0* mChild;
    void Finish();
};


// 0x00221b30 FUN_00221b30 (58 B): matches/0x00221b30.cpp
// sym: ?Copy@X_221b30@fn_f403c6ef@@QAEXABV12@@Z
void X_221b30::Copy(const X_221b30& other) {
    p = other.p;
    q = other.q;
    c = other.c;
}


// 0x00221b70 FUN_00221b70 (47 B): matches/0x00221b70.cpp
// sym: ?Copy@Obj_221b70@fn_f403c6ef@@QAEXPBUBlock_221b70@2@@Z
void Obj_221b70::Copy(const Block_221b70* src) {
    block = *src;
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 2;
}


// 0x00221ba0 FUN_00221ba0 (62 B): matches/0x00221ba0.cpp
// sym: ?Run@Obj_221ba0@fn_f403c6ef@@QAEPAV12@PAUPair_221ba0@2@H@Z
// Same code shape as 0x0030f0a0 (propagated; names are from that function)
Obj_221ba0* Obj_221ba0::Run(Pair_221ba0* src, int x) {
    First();
    ((owners::Target_22be40 *)this)->FUN_0022be40((const int *)(hulk_uintptr)(int)x);
    value = *src;
    flag = 1;
    return this;
}


// 0x00221be0 FUN_00221be0 (58 B): matches/0x00221be0.cpp
// sym: ?Copy@X_221be0@fn_f403c6ef@@QAEXABV12@@Z
// Same code shape as 0x00221b30 (propagated; names are from that function)
void X_221be0::Copy(const X_221be0& other) {
    p = other.p;
    q = other.q;
    c = other.c;
}


// 0x00221c20 FUN_00221c20 (31 B): matches/0x00221c20.cpp
// sym: ?Run@Thing_221c20@fn_f403c6ef@@QAEXXZ
void Thing_221c20::Run() {
    Init();
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 0;
}


// 0x00221c40 FUN_00221c40 (29 B): matches/0x00221c40.cpp
// sym: ?target@Obj_221c40@fn_f403c6ef@@QAEPAU12@XZ
Obj_221c40* Obj_221c40::target() {
    if (state == 1) {
        sub.F(this);
        state = 0;
    }
    return this;
}


// 0x00221c60 FUN_00221c60 (29 B): matches/0x00221c60.cpp
// sym: ?Copy@C_221c60@fn_f403c6ef@@QAEXPAV12@@Z
void C_221c60::Copy(C_221c60* src) {
    d = src->d;
    x = 2;
}


// 0x00221c80 FUN_00221c80 (66 B): matches/0x00221c80.cpp
// sym: ?Copy@X@fn_f403c6ef@@QAEXPBU12@@Z
void X::Copy(const X* p) {
    a = p->a;
    b = p->b;
    c = p->c;
    d = p->d;
    e = p->e;
    f = p->f;
    g = p->g;
    h = p->h;
    i = p->i;
    state = 2;
}


// 0x00221cd0 FUN_00221cd0 (30 B): matches/0x00221cd0.cpp
// sym: ?target@C_221cd0@fn_f403c6ef@@QAEPAXXZ
void* C_221cd0::target() {
    if (state == 2) {
        ((owners::Quat_22b370 *)&sub)->FUN_0022b370((const float *)(hulk_uintptr)(hulk_intptr)((hulk_intptr)this));
        state = 0;
    }
    return (void*)&sub;
}


// 0x00221cf0 FUN_00221cf0 (41 B): matches/0x00221cf0.cpp
// sym: ?Set@Obj_221cf0@fn_f403c6ef@@QAEXABUFour_221cf0@2@@Z
void Obj_221cf0::Set(const Four_221cf0& p) {
    v = p;
    flag = 1;
}


// 0x00221d20 FUN_00221d20 (64 B): matches/0x00221d20.cpp
// sym: ?Fn@Obj@fn_f403c6ef@@QAEXH@Z
void Obj::Fn(int x) {
    Four v;
    v.Set(x);
    f = v;
    flag = 1;
}


// 0x00221d60 FUN_00221d60 (132 B): matches/0x00221d60.cpp
// sym: ?Fn@Obj_221d60@fn_f403c6ef@@QAEXPAV12@M@Z
void Obj_221d60::Fn(Obj_221d60* other, float t) {
    x = (other->x - x) * t + x;
    y = (other->y - y) * t + y;
    z = (other->z - z) * t + z;

    _ReadWriteBarrier();
    int s = *(volatile int*)&state;
    if (s == 2) {
        ((owners::Quat_22b370 *)&elem)->FUN_0022b370((const float *)(Obj_221d60 *)this);
        state = 0;
    }
    if (other->state == 2) {
        ((owners::Quat_22b370 *)&(other->elem))->FUN_0022b370((const float *)(Obj_221d60 *)other);
        other->state = 0;
    }
    ((owners::Quaternion_22b750 *)&elem)->FUN_0022b750((const owners::Quaternion_22b750 *)(Elem_221d60 *)(&elem), (const owners::Quaternion_22b750 *)(Elem_221d60 *)(&other->elem), t);
    state = 1;
}


// 0x00221df0 FUN_00221df0 (101 B): matches/0x00221df0.cpp
// sym: ?Run@Obj_221df0@fn_f403c6ef@@QAEXPAV12@@Z
void Obj_221df0::Run(Obj_221df0* other) {
    Obj_221df0* self = this;
    if (self->state == 1) {
        self->sub.Fn(self);
        self->state = 0;
    }
    if (other->state == 1) {
        other->sub.Fn(other);
        other->state = 0;
    }
    Tmp_221df0 tmp;
    ((owners::Matrix_22ca90 *)&tmp)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Obj_221df0 *)self, (const owners::Matrix_22ca90 *)(Obj_221df0 *)other);
    memcpy(self, &tmp, 0x40);
    self->state = 2;
}

} // namespace fn_f403c6ef

// 0x00221e60 FUN_00221e60 (74 B): matches/0x00221e60.cpp
// sym: ?FUN_00221e60@Obj_221e60@owners@@QAEXI@Z
void owners::Obj_221e60::FUN_00221e60(hulk_uintptr arg) {
    char local[0x40];
    if (state == 1) {
        ((Work_221e60*)((char*)this + 0x40))->First(this);
        state = 0;
    }
    ((owners::Matrix_22ca90 *)(((Work_221e60*)local)))->FUN_0022ca90((const owners::Matrix_22ca90 *)(owners :: Obj_221e60 *)this, (const owners::Matrix_22ca90 *)(hulk_uintptr)(unsigned int)(((unsigned int)arg)));
    struct Block {
        unsigned int a[16];
    };
    *(Block*)this = *(Block*)local;
    state = 2;
}

namespace fn_f403c6ef {

// 0x00221eb0 FUN_00221eb0 (41 B): matches/0x00221eb0.cpp
// sym: ?target@Obj_221eb0@fn_f403c6ef@@QAEXXZ
void Obj_221eb0::target() {
    if (state == 1) {
        sub.call(this);
        state = 0;
    }
    ((owners::Matrix_22c120 *)this)->FUN_0022c120();
    state = 2;
}


// 0x00221ee0 FUN_00221ee0 (49 B): matches/0x00221ee0.cpp
// sym: ?Run@Obj_221ee0@fn_f403c6ef@@QAEXXZ
void Obj_221ee0::Run() {
    switch (state) {
    case 0:
        ((owners::Vec4_22b120 *)&inner)->FUN_0022b120();
        state = 1;
        break;
    case 1:
        ((owners::Vec4_22b120 *)&inner)->FUN_0022b120();
        break;
    case 2:
        Other();
        break;
    }
}

} // namespace fn_f403c6ef

// 0x00221f20 FUN_00221f20 (75 B): matches/0x00221f20.cpp [wrapped: conflict: Obj]
// sym: ?dispatch@Obj@fn_00221f20@@QAEXHH@Z
namespace fn_00221f20 {
class Obj;
struct Sub {
    void reset(Obj*);
};
class Obj {
    char pad[0x40];
    Sub sub;
    char gap[0xf];
    int state;

  public:
    void dispatch(hulk_intptr a, hulk_intptr b);
};
void Obj::dispatch(hulk_intptr a, hulk_intptr b) {
    switch (state) {
    case 0:
    case 2:
        ((owners::Mat_22c2b0 *)this)->FUN_0022c2b0((float *)(hulk_uintptr)(int)a, (float *)(hulk_uintptr)(int)b);
        break;
    case 1:
        sub.reset(this);
        state = 0;
        ((owners::Mat_22c2b0 *)this)->FUN_0022c2b0((float *)(hulk_uintptr)(int)a, (float *)(hulk_uintptr)(int)b);
        break;
    }
}
} // namespace fn_00221f20


// 0x00221f70 FUN_00221f70 (30 B): matches/0x00221f70.cpp
// sym: ?FUN_00221f70@Obj_221f70@owners@@QAEXHH@Z
void owners::Obj_221f70::FUN_00221f70(hulk_intptr a, hulk_intptr b) {
    switch (state) {
    case 0:
    case 2:
        return callee2(((int)a), ((int)b));
    case 1:
        return ((Obj2_221f70*)((char*)this + 0x40))->callee1(((int)a), ((int)b));
    }
}

namespace fn_f403c6ef {

// 0x00221f90 FUN_00221f90 (178 B): equivalent/0x00221f90.cpp
// sym: ?FUN_00221f90@MatrixData_221f90@fn_f403c6ef@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 12/12)
// FUN_00221f90 @ 0x00221f90
bool MatrixData_221f90::FUN_00221f90() {
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (__isnan(matrix[row][col])) return false;
        }
    }
    if (__isnan(extra[0])) return false;
    if (__isnan(extra[1])) return false;
    if (__isnan(extra[2])) return false;
    return __isnan(extra[3]) == 0;
}


// 0x00222050 FUN_00222050 (33 B): matches/0x00222050.cpp
// sym: ??0Obj_222050@fn_f403c6ef@@QAE@XZ
Obj_222050::Obj_222050() {
    FUN_0022b980((void*)(this));
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 0;
}


// 0x00222080 FUN_00222080 (47 B): matches/0x00222080.cpp
// sym: ??0Thing_222080@fn_f403c6ef@@QAE@H@Z
// Same code shape as 0x0030f3d0 (propagated; names are from that function)
Thing_222080::Thing_222080(int x) : Base_222080() {
    c = 0;
    b = 0;
    a = 0;
    d = 1.0f;
    int* q = &e;
    *q = 0;
    ((owners::Target_22be40 *)this)->FUN_0022be40((const int *)(hulk_uintptr)(int)x);
}

} // namespace fn_f403c6ef

// 0x002220d0 FUN_002220d0 (74 B): matches/0x002220d0.cpp [wrapped: conflict: Obj]
// sym: ?FUN_002220d0@Obj@fn_002220d0@@QAEMXZ
namespace fn_002220d0 {

struct Result {
    char data[12];
};
hulk_freg __cdecl FUN_00224f10(Result*);
struct Sub {
    char data[16];
    void FUN_0022b4d0(float*, Result*);
};
struct Obj {
    char pad[0x40];
    Sub sub;
    int mode;
    hulk_freg FUN_002220d0();
};
hulk_freg Obj::FUN_002220d0() {
    Result result;
    switch (mode) {
    case 0:
    case 2:
        ((owners::M_22c3b0 *)this)->FUN_0022c3b0(((float*)&DAT_004c9d60), (float *)(Result *)(&result));
        break;
    case 1:
        sub.FUN_0022b4d0(((float*)&DAT_004c9d60), &result);
        break;
    }
    return FUN_00224f10(&result);
}
} // namespace fn_002220d0

namespace fn_f403c6ef {

// 0x00222120 FUN_00222120 (81 B): equivalent/0x00222120.cpp
// sym: ?FUN_00222120@Object@fn_f403c6ef@@QAEPAUVec3@2@PAU32@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00222120 @ 0x00222120
Vec3 *Object::FUN_00222120(Vec3 *result) {
    Vec3 value;
    if (mode == 0 || mode == 2)
        ((owners::M_22c3b0 *)this)->FUN_0022c3b0(((float*)&DAT_004c9d60), (float *)(Vec3 *)(&value));
    else if (mode == 1)
        helper.FUN_0022b4d0(((float*)&DAT_004c9d60), &value);
    *result = value;
    return result;
}


// 0x00222180 FUN_00222180 (166 B): equivalent/0x00222180.cpp
// sym: ?FUN_00222180@Node@fn_f403c6ef@@QAEXPAUArg_222180@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// FUN_00222180 @ 0x00222180
void Node::FUN_00222180(Arg_222180 *a)
{
    struct Frame {
        Pos_222180 saved;
        Mat_222180 tilt;
        Mat_222180 product;
    } fr;
    fr.saved = mat.pos;
    mat.FUN_0022b980();
    ((owners::Matrix_22ba30 *)&mat)->FUN_0022ba30(FUN_000189c0(a->f4));
    fr.tilt.FUN_0022b980();
    ((owners::Mat_22ba70 *)&(fr.tilt))->FUN_0022ba70(FUN_00224f10(a));
    ((owners::Matrix_22ca90 *)&(fr.product))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Mat_222180 *)(&mat), (const owners::Matrix_22ca90 *)(Mat_222180 *)(&fr.tilt));
    mat = fr.product;
    mat.pos = fr.saved;
    state = 2;
}


// 0x00222230 FUN_00222230 (126 B): equivalent/0x00222230.cpp
// sym: ?FUN_00222230@Xform_222230@fn_f403c6ef@@QAEXPAX0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00222230 @ 0x00222230
void Xform_222230::FUN_00222230(void* a, void* b)
{
    Xform_222230 local = *this;
    if (mode == 1) {
        local.sub.FUN_0022b650(&local);
        local.mode = 0;
    }
    ((owners::Matrix_22c120 *)&local)->FUN_0022c120();
    local.mode = 2;
    ((owners::Mat_22c2b0 *)&local)->FUN_0022c2b0((float *)a, (float *)b);
}


// 0x002222d0 FUN_002222d0 (25 B): matches/0x002222d0.cpp
// sym: ??1PartitionDriver@fn_f403c6ef@@UAE@XZ
PartitionDriver::~PartitionDriver() {
    mChild->f1();
    Finish();
}

} // namespace fn_f403c6ef
