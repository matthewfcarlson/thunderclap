// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00319c80..0x0031ac80 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/engine/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fdd3dec6 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fdd3dec6 {} using namespace fn_fdd3dec6;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fdd3dec6 {
class Data_319e90 {
  public:
    void Init_0031a8b0(void* src);
};
struct Element_319e90 {
    void* header;
    Data_319e90 data;
};
class Container_319e90 {
    char _pad0[4];

  public:
    Element_319e90* mCurrent;
    Element_319e90* mEnd;

  private:
    char _padC[0xA0 - 0xC];
    int mState;

  public:
    void Add(void* param2, void* param3);
};
union Bits_319f40 {
    float f;
    unsigned int u;
};
struct V3_319f40 {
    float x, y, z;
    float FUN_00018990();
};
struct Body_319f40 {
    char pad00[0x50];
    V3_319f40 pos;                     // 0x50
    V3_319f40 vel;                     // 0x5c
    char pad68[0x18];
    float f80;                  // 0x80
};
struct Event_319f40 {
    int type;                   // 0x00
    Bits_319f40 a[6];                  // 0x04
    Bits_319f40 f1c;                   // 0x1c
    char pad20[0x10];
    V3_319f40 diff;                    // 0x30
    Bits_319f40 f3c;                   // 0x3c
    Bits_319f40 f40;                   // 0x40
    char pad44[0x1c];                  // FUN_0031a830 fills 0x60 bytes
    void FUN_0031a830();
};
struct Tracker_319f40 {
    char pad00[0x10];
    int state;                  // 0x10
    Bits_319f40 f14;
    Bits_319f40 f18;
    Bits_319f40 f1c;
    Bits_319f40 f20;
    Bits_319f40 f24;
    Bits_319f40 f28;
    Bits_319f40 f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    V3_319f40 v40;                     // 0x40
    Bits_319f40 f4c;
    float f50;
    float f54;
    float f58;
    float f5c;
    float f60;
    char pad64[4];
    float f68;
    float f6c;
    Body_319f40 *a;                    // 0x70
    Body_319f40 *b;                    // 0x74
    char pad78[8];
    unsigned int flags;         // 0x80
    char flag84;
    char pad85[3];
    int count;                  // 0x88
    Bits_319f40 f8c;
    Bits_319f40 f90;
    Bits_319f40 f94;
    Bits_319f40 f98;
    Bits_319f40 f9c;
    void FUN_00319e90(int what, void *arg);
    void FUN_00319f40();
};
class Obj_31a400 {
  public:
    void* v;
    void* x;
    char pad[0x98];
    int state;
};
struct Part_31a440 {
    char data[0x60];
    void FUN_0031a830();
};
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char* base;
    char* current;
    char* end;
    unsigned int untouched;
    Part_31a440 part;
    unsigned int f70, f74, f78, f7c, flags, f84, f88, f8c, f90, f94, f98, f9c, fa0;
    Object* init();
};
struct Rest_31a6b0 {
    char data[96];
    void FUN_0031a8b0(const Rest_31a6b0 *src);
};
struct Elem_31a6b0 {
    unsigned int first;
    Rest_31a6b0 rest;
};
struct Sub_31a6b0 {
    char data[0x60];
};
class Container_31a6b0 {
public:
    Elem_31a6b0 *begin;
    Elem_31a6b0 *end;
    Elem_31a6b0 *cap;
    char pad0c[4];
    Sub_31a6b0 sub;
    unsigned int f70, f74, f78, f7c, f80;
    unsigned char f84;
    char pad85[3];
    unsigned int f88, f8c, f90, f94, f98, f9c;
    int state;

    Container_31a6b0 *FUN_0031a6b0(const Container_31a6b0 *other);
};
struct Obj_31a800 {
    int value;
    int copy;
    char pad[0x98];
    int state;
};
extern "C" {
extern float hulk_at_004d34e8;
}
extern "C" {
extern float hulk_at_004d34ec;
}
class Obj_31a830 {
  public:
    float v[25];
    Obj_31a830();
};

} // namespace fn_fdd3dec6

// 0x00319c80 FUN_00319c80 (151 B): matches/0x00319c80.cpp
// sym: ?FUN_00319c80@DataBlock_319c80@owners@@QAEPAU12@PBU12@@Z
owners::DataBlock_319c80* owners::DataBlock_319c80::FUN_00319c80(const owners::DataBlock_319c80* src) {
    m00 = src->m00;
    m04 = src->m04;
    m08 = src->m08;
    m0c = src->m0c;
    m10 = src->m10;
    m14 = src->m14;
    m18 = src->m18;
    m1c = src->m1c;
    m20 = src->m20;
    m24 = src->m24;
    m28 = src->m28;
    m2c = src->m2c;
    m30 = src->m30;
    m34 = src->m34;
    m38 = src->m38;
    m3c = src->m3c;
    m40 = src->m40;
    m44 = src->m44;
    m48 = src->m48;
    m4c = src->m4c;
    m50 = src->m50;
    m54 = src->m54;
    m58 = src->m58;
    m5c = src->m5c;
    return this;
}


// 0x00319d20 FUN_00319d20 (11 B): matches/0x00319d20.cpp
// sym: ?FUN_00319d20@Obj_319d20@owners@@QAE_NXZ
bool owners::Obj_319d20::FUN_00319d20() {
    if (value == 2)
        return true;
    return false;
}

namespace fn_fdd3dec6 {

// 0x00319e90 FUN_00319e90 (81 B): matches/0x00319e90.cpp
// sym: ?Add@Container_319e90@fn_fdd3dec6@@QAEXPAX0@Z
void Container_319e90::Add(void* param2, void* param3) {
    if (mState != 2) {
        char buffer[0x64];
        *(void**)buffer = param2;
        Data_319e90* temp = (Data_319e90*)(buffer + 4);
        temp->Init_0031a8b0(param3);

        if (mCurrent < mEnd) {
            Element_319e90* oldCurrent = mCurrent;
            mCurrent = (Element_319e90*)((char*)mCurrent + 0x64);
            if (oldCurrent) {
                oldCurrent->header = *(void**)buffer;
                oldCurrent->data.Init_0031a8b0(temp);
            }
        }
    }
}

} // namespace fn_fdd3dec6

// 0x00319ef0 FUN_00319ef0 (52 B): matches/0x00319ef0.cpp
// sym: ?FUN_00319ef0@Thing_319ef0@owners@@QAEXXZ
void owners::Thing_319ef0::FUN_00319ef0() {
    if (flag == 0) {
        if (state == 2) {
            state = 0;
            Change(3, &state);
        }
        flag = 1;
    }
}

namespace fn_fdd3dec6 {

// 0x00319f40 FUN_00319f40 (1066 B): equivalent/0x00319f40.cpp
// sym: ?FUN_00319f40@Tracker_319f40@fn_fdd3dec6@@QAEXXZ @81e418418931 @w6f2010787463
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 38/38)
// FUN_00319f40 @ 0x00319f40
void Tracker_319f40::FUN_00319f40()
{
    int n = count;
    if (n == 0)
        return;
    if (n > 1) {
        double inv = 1.0f / n;
        f90.f = inv * f90.f;
        f8c.f = inv * f8c.f;
        f14.f = inv * f14.f;
        f18.f = inv * f18.f;
        f1c.f = inv * f1c.f;
        f20.f = inv * f20.f;
        f24.f = inv * f24.f;
        f28.f = inv * f28.f;
    }
    double t = f90.f * 0.05f + f50 * 0.95f;
    f50 = t;
    if (t == 0.0)
        f50 = 0.00001f;

    double d = f94.f - f98.f;
    f4c.u = f8c.u;
    bool big = d > f60;
    if (!big) {
        unsigned int g = f8c.u;
        Bits_319f40 absg;
        absg.u = g & 0x7fffffff;
        double dbl = f9c.f;
        dbl = dbl + dbl;
        if (dbl < absg.f) {
            absg.u = f8c.u & 0x7fffffff;
            if (absg.f > f5c)
                big = true;
        }
    }

    if (big) {
        if (flags & 1) {
            if (state == 2) {
                state = 0;
                FUN_00319e90(3, &state);
            }
            Event_319f40 e;
            e.FUN_0031a830();
            Body_319f40 *pa = a;
            Body_319f40 *pb = b;
            e.a[0] = f14;
            e.a[1] = f18;
            e.a[2] = f1c;
            e.a[3] = f20;
            e.a[4] = f24;
            e.a[5] = f28;
            e.type = 1;
            e.f1c = f94;
            e.diff.x = pa->pos.x - pb->pos.x;
            e.diff.y = pa->pos.y - pb->pos.y;
            e.diff.z = pa->pos.z - pb->pos.z;
            Bits_319f40 eb = f8c;
            e.f40 = f90;
            Bits_319f40 absg;
            absg.u = eb.u & 0x7fffffff;
            f9c.u = absg.u;
            e.f3c = eb;
            FUN_00319e90(1, &e);
        }
    } else if (flags & 0xe) {
        Body_319f40 *pa = a;
        Body_319f40 *pb = b;
        double dx = pa->pos.x - pb->pos.x;
        double dy = pa->pos.y - pb->pos.y;
        volatile float dz = pa->pos.z - pb->pos.z;
        volatile V3_319f40 *vv = &v40;
        vv->x = vv->x * 0.95f;
        vv->y = vv->y * 0.95f;
        vv->z = vv->z * 0.95f;
        vv->x = dx * 0.05f + vv->x;
        vv->y = dy * 0.05f + vv->y;
        vv->z = dz * 0.05f + vv->z;
        unsigned int fl = flags;
        if (fl & 8) {
            if (fl & 0x800) {
                Body_319f40 *p = a;
                double h = 1.0f / DAT_004d2960;
                Bits_319f40 ab;
                ab.u = *(unsigned int *)&f50 & 0x7fffffff;
                double w = (h + DAT_004d2960) * p->f80 * 0.5f * 0.05f + f54 * 0.95f;
                volatile float v = w;
                f54 = w;
                float len = p->vel.FUN_00018990();
                double r = len / ((v + ab.f) * 0.5f);
                if (r > 15.0f)
                    f38 = r;
                else
                    f38 = 0.0f;
            }
            if (fl & 0x80000) {
                Body_319f40 *p = b;
                double h = 1.0f / DAT_004d2960;
                Bits_319f40 ab;
                ab.u = *(unsigned int *)&f50 & 0x7fffffff;
                double w = (h + DAT_004d2960) * p->f80 * 0.5f * 0.05f + f58 * 0.95f;
                volatile float v = w;
                f58 = w;
                float len = p->vel.FUN_00018990();
                double r = len / ((v + ab.f) * 0.5f);
                if (r > 15.0f)
                    f3c = r;
                else
                    f3c = 0.0f;
            }
        }
        if ((fl & 6) == 6) {
            double r2d = v40.FUN_00018990() / f50;
            volatile float r2 = r2d;
            if (r2d < f68) {
                f30 = 1.0f;
                f34 = 0.0f;
            } else if (r2 > f6c) {
                f30 = 0.0f;
                f34 = 1.0f;
            } else {
                double u = (r2 - f68) / (f6c - f68);
                f34 = u;
                f30 = 1.0 - u;
            }
        }
        if (state != 2) {
            f2c = f94;
            state = 2;
            FUN_00319e90(2, &state);
        }
        f9c.u = 0;
    }
    f98 = f94;
    count = 0;
    flag84 = 1;
}

} // namespace fn_fdd3dec6

// 0x0031a380 FUN_0031a380 (128 B): matches/0x0031a380.cpp
// sym: ?FUN_0031a380@Thing_31a380@owners@@QAEXHHHHH@Z
void owners::Thing_31a380::FUN_0031a380(int p1, int p2, int p3, int p4, int p5) {
    mCopy = mVptr;
    a = p1;
    b = p3;
    c = p2;
    d = p4;
    e = p5;
    x[0] = 0;
    x[1] = 0;
    x[2] = 0;
    x[3] = 0;
    x[4] = 0;
    x[5] = 0;
    x[6] = 0;
    if ((p5 & 6) == 0)
        return;
    if (!(p5 & 4)) {
        u = 0x3f800000;
        v = 0;
        return;
    }
    if (p5 & 2)
        return;
    u = 0;
    v = 0x3f800000;
}

namespace fn_fdd3dec6 {

// 0x0031a400 FUN_0031a400 (25 B): matches/0x0031a400.cpp
// sym: ?FUN_0031a400@fn_fdd3dec6@@YIXPAVObj_31a400@1@@Z
void __fastcall FUN_0031a400(Obj_31a400* self) {
    self->x = self->v;
    if (self->state == 1)
        self->state = 2;
}


// 0x0031a440 FUN_0031a440 (168 B): matches/0x0031a440.cpp
// sym: ?init@Object@fn_fdd3dec6@@QAEPAU12@XZ
Object* Object::init() {
    base = 0;
    current = 0;
    end = 0;
    part.FUN_0031a830();
    f70 = 0;
    f74 = 0;
    f78 = 0;
    f7c = 0;
    flags = 0;
    f88 = 0;
    f8c = 0;
    f90 = 0;
    f94 = 0;
    f98 = 0;
    f9c = 0;
    fa0 = 0;
    char* p = (char*)FUN_0008d6d0(1000);
    base = p;
    if (p) {
        current = p;
        end = p + 1000;
    } else {
        current = 0;
        end = 0;
    }
    if (flags & 6) {
        float* values = (float*)(part.data + 0x20);
        if (!(flags & 4)) {
            values[0] = 1.0f;
            values[1] = 0.0f;
        } else if (!(flags & 2)) {
            values[0] = 0.0f;
            values[1] = 1.0f;
        }
    }
    return this;
}

} // namespace fn_fdd3dec6

// 0x0031a4f0 FUN_0031a4f0 (243 B): equivalent/0x0031a4f0.cpp [wrapped: conflict: Object]
// sym: ?copy@Object@fn_0031a4f0@@QAEPAU12@PBU12@@Z @d9d6f269c03a @w652cdbf5614a
namespace fn_0031a4f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0031a4f0 @ 0x0031a4f0
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
struct State_31a4f0 {
 char pad0[0x20];
 float weightA, weightB;
 char pad1[0x38];
 void FUN_0031a8b0(const State_31a4f0*);
};
struct Object {
 void* begin;
 void* current;
 void* end;
 unsigned int reserved;
 State_31a4f0 state;
 unsigned int field70, field74, field78, field7c, flags, field84;
 unsigned int field88, field8c, field90, field94, field98, field9c, fielda0;
 Object* copy(const Object* src);
};
Object* Object::copy(const Object* src) {
 begin = current = end = 0;
 state.FUN_0031a8b0(&src->state);
 field70 = src->field70;
 field74 = src->field74;
 field78 = src->field78;
 field7c = src->field7c;
 flags = src->flags;
 field88 = src->field88;
 field8c = src->field8c;
 field90 = src->field90;
 field94 = src->field94;
 field98 = src->field98;
 field9c = src->field9c;
 fielda0 = src->fielda0;
 begin = FUN_0008d6d0(1000);
 if (begin) { current = begin; end = (char*)begin + 1000; }
 else { current = end = 0; }
 if ((flags & 6) == 2) { state.weightA = 1.0f; state.weightB = 0.0f; }
 else if ((flags & 6) == 4) { state.weightA = 0.0f; state.weightB = 1.0f; }
 return this;
}
} // namespace fn_0031a4f0


// 0x0031a5f0 FUN_0031a5f0 (192 B): equivalent/0x0031a5f0.cpp [wrapped: conflict: Object]
// sym: ?FUN_0031a5f0@Object@fn_0031a5f0@@QAEPAU12@IIIII@Z @773990e6ee35 @w2e71fc029a47
namespace fn_0031a5f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0031a5f0 @ 0x0031a5f0
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);
struct State_31a5f0 {
 char pad0[0x20];
 float first;
 float second;
 char pad1[0x38];
 void FUN_0031a830();
};
struct Object {
 char* begin;
 char* current;
 char* end;
 unsigned int spare;
 State_31a5f0 state;
 unsigned int arg1;
 unsigned int arg3;
 unsigned int arg2;
 unsigned int arg4;
 unsigned int flags;
 unsigned int untouched;
 unsigned int zero[7];
 Object* FUN_0031a5f0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int f);
};
Object* Object::FUN_0031a5f0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int f) {
 begin = 0; current = 0; end = 0;
 state.FUN_0031a830();
 arg1 = a; arg3 = c; arg2 = b; arg4 = d; flags = f;
 zero[0]=0; zero[1]=0; zero[2]=0; zero[3]=0; zero[4]=0; zero[5]=0; zero[6]=0;
 char* memory = (char*)FUN_0008d6d0(1000);
 begin = memory;
 if (memory) { current = memory; end = memory + 1000; }
 else { current = 0; end = 0; }
 if ((f & 6) == 2) { state.first = 1.0f; state.second = 0.0f; }
 else if ((f & 6) == 4) { state.first = 0.0f; state.second = 1.0f; }
 return this;
}
} // namespace fn_0031a5f0

namespace fn_fdd3dec6 {

// 0x0031a6b0 FUN_0031a6b0 (326 B): matches/0x0031a6b0.cpp
// sym: ?FUN_0031a6b0@Container_31a6b0@fn_fdd3dec6@@QAEPAV12@PBV12@@Z
// FUN_0031a6b0 @ 0x0031a6b0
Container_31a6b0 *Container_31a6b0::FUN_0031a6b0(const Container_31a6b0 *other)
{
    if (this == other)
        return this;

    end = begin;
    if (state == 1)
        state = 2;
    end = begin;

    for (unsigned int i = 0; i < (unsigned int)(((hulk_intptr)other->end - (hulk_intptr)other->begin) / 100); i++) {
        Elem_31a6b0 tmp;
        const Elem_31a6b0 *s = &other->begin[i];
        tmp.first = s->first;
        tmp.rest.FUN_0031a8b0(&s->rest);
        Elem_31a6b0 *p = end;
        if (p < cap) {
            end = p + 1;
            if (p) {
                p->first = tmp.first;
                p->rest.FUN_0031a8b0(&tmp.rest);
            }
        }
    }

    ((owners::DataBlock_319c80 *)&sub)->FUN_00319c80((const owners::DataBlock_319c80 *)(const Sub_31a6b0 *)(&other->sub));
    f70 = other->f70;
    f74 = other->f74;
    f78 = other->f78;
    f7c = other->f7c;
    f80 = other->f80;
    f84 = other->f84;
    f88 = other->f88;
    f8c = other->f8c;
    f90 = other->f90;
    f94 = other->f94;
    f98 = other->f98;
    f9c = other->f9c;
    state = other->state;
    return this;
}


// 0x0031a800 FUN_0031a800 (39 B): matches/0x0031a800.cpp
// sym: @FUN_0031a800@4
extern "C" void __fastcall FUN_0031a800(Obj_31a800* p) {
    int i = p->value;
    p->copy = i;
    if (p->state == 1)
        p->state = 2;
    p->copy = i;
    if (i)
        thunk(i);
}


// 0x0031a830 FUN_0031a830 (122 B): matches/0x0031a830.cpp
// sym: ??0Obj_31a830@fn_fdd3dec6@@QAE@XZ
Obj_31a830::Obj_31a830() {
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    v[3] = 0.0f;
    v[4] = 0.0f;
    v[5] = 0.0f;
    v[6] = 0.0f;
    v[7] = 0.0f;
    v[8] = 0.0f;
    v[9] = 0.0f;
    v[10] = 0.0f;
    v[11] = 0.0f;
    v[12] = 0.0f;
    v[13] = 0.0f;
    v[14] = 0.0f;
    v[15] = 0.0f;
    v[16] = 1.0f;
    v[17] = 0.0f;
    v[18] = 0.0f;
    v[19] = (*(float*)&DAT_004d34e0);
    v[20] = (*(float*)&DAT_004d34e4);
    v[21] = hulk_at_004d34e8;
    v[22] = hulk_at_004d34ec * hulk_at_004d34e8;
    v[23] = DAT_004d34f0 * hulk_at_004d34e8;
}

} // namespace fn_fdd3dec6

// 0x0031a8b0 FUN_0031a8b0 (167 B): matches/0x0031a8b0.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ??4X_31a8b0@fn_0031a8b0@@QAEAAU01@ABU01@@Z
namespace fn_0031a8b0 {
struct T3 {
    unsigned int x, y, z;
};
struct X_31a8b0 {
    unsigned int a;
    T3 b;
    T3 c;
    unsigned int d[5];
    T3 e;
    unsigned int f[9];
    X_31a8b0& operator=(const X_31a8b0&);
};
X_31a8b0& X_31a8b0::operator=(const X_31a8b0& o_31a8b0) {
    a = o_31a8b0.a;
    b = o_31a8b0.b;
    c = o_31a8b0.c;
    d[0] = o_31a8b0.d[0];
    d[1] = o_31a8b0.d[1];
    d[2] = o_31a8b0.d[2];
    d[3] = o_31a8b0.d[3];
    d[4] = o_31a8b0.d[4];
    e = o_31a8b0.e;
    f[0] = o_31a8b0.f[0];
    f[1] = o_31a8b0.f[1];
    f[2] = o_31a8b0.f[2];
    f[3] = o_31a8b0.f[3];
    f[4] = o_31a8b0.f[4];
    f[5] = o_31a8b0.f[5];
    f[6] = o_31a8b0.f[6];
    f[7] = o_31a8b0.f[7];
    f[8] = o_31a8b0.f[8];
    return *this;
}
} // namespace fn_0031a8b0

