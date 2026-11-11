// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028d130..0x0028df60 (kind game, layer engine, confidence high), dominant class math::CompressedQuaternion3
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f5ce7ee6 {
#define TREE_TU_END }
namespace fn_f5ce7ee6 {} using namespace fn_f5ce7ee6;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f5ce7ee6 {
extern char DAT_0042caa8[];
void* __cdecl FUN_0008d6d0(unsigned size);
void __stdcall FUN_00011520(void* base, unsigned size, int count, void* ctor);
extern char FUN_00289ed0;
struct Pool_28d150 {
};
class CompressedQuaternionChannel_28d150 {
public:
    hulk_intptr vptr;
    int field_04;
    int field_08;
    Pool_28d150* parent;
    int count;
    int field_14;
    void* data;
    CompressedQuaternionChannel_28d150* FUN_0028b420(int a, int b);
    CompressedQuaternionChannel_28d150* Construct(int a, hulk_intptr b);
};
class QuaternionChannel {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int, void*);
    virtual void f4(int, int);
    virtual void f5();
    virtual void f6();
    void vfunc_4(int a, int b, int c);
};
struct Helper_28d2a0 {
    void call(int);
};
struct Quat_28d2d0 {
    float x, y, z, w;
};
struct CompressedQuaternion8 {
    short v[4];
};
struct Frame_28d2d0 {
    int lo;
    int hi;
    Quat_28d2d0 q1;
    Quat_28d2d0 q0;
    Quat_28d2d0 tmp;
};
class CompressedQuaternionChannel {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float time, Quat_28d2d0 *out);
    virtual void vfunc_6();
    void *field04;
    char pad08[0x10 - 8];
    int count;
    short *times;
    CompressedQuaternion8 *values;
    char FUN_00289f80(float time, int *lo, int *hi);
};
struct Obj_28d440 {
    virtual void f0();
    virtual void f1();
};
void thunk(int*);
class IntChannel {
  public:
    char pad0[12];
    Obj_28d440* volatile mObj;
    char pad10[4];
    int* m14;
    int* m18;
    void vfunc_1();
};
extern char DAT_0042cac8[];
extern char FUN_001db770;
struct Pool_28d490 {
};
class CompressedQuaternionChannel_28d490 {
public:
    hulk_intptr vptr;
    int field_04;
    int field_08;
    Pool_28d490* parent;
    int count;
    int field_14;
    void* data;
    CompressedQuaternionChannel_28d490* FUN_0028b420(int a, int b);
    CompressedQuaternionChannel_28d490* Construct(int a, hulk_intptr b);
};
class Decoder_28d510 {
  public:
    void* Decode(void*);
};
struct Q_28d510 {
    unsigned int a, b, c, d;
};
typedef void(__fastcall* Callback_28d750)(void*);
extern void* Alloc(hulk_uintptr);
extern void __stdcall VecNew(void*, int, int, Callback_28d750);
class Mem_28d750 {
  public:
};
class RotationChannel_28d750 {
  public:
    RotationChannel_28d750(int, int);
    virtual void v0();
    int m4, m8;
    Mem_28d750* mc;
    int m10, m14;
};
class CompressedQuaternionChannel_28d750 : public RotationChannel_28d750 {
  public:
    void* m18;
    CompressedQuaternionChannel_28d750(int, hulk_intptr);
    virtual void v1();
};
struct CompressedQuaternion4_28d7d0 {
    unsigned int x[4];
};
struct PackedQ {
    unsigned int v;
    CompressedQuaternion4_28d7d0* Decode(CompressedQuaternion4_28d7d0* tmp);
};
struct Quaternion_28d820 { float x,y,z,w; };
struct Packed { unsigned int bits; Quaternion_28d820* decode(Quaternion_28d820* out); };
} // namespace fn_f5ce7ee6
namespace math {
struct Quaternion {
    float x, y, z, w;
};
}
namespace math {
struct CompressedQuaternion3_28db60 {
    unsigned char bytes[3];
    Quaternion* FUN_0028dbb0(Quaternion* result);
};
}
namespace fn_f5ce7ee6 {
struct Quaternion_28dbb0 { float x,y,z,w; };
struct PackedQuaternion_28dbb0 {
 signed char x,y,z;
 Quaternion_28dbb0* unpack(Quaternion_28dbb0* output);
};
extern int g_vftable_28de70;
struct CompressedQuaternionChannel_28de70 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
extern int g_vftable_28dea0;
struct CompressedQuaternionChannel_28dea0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
extern int g_vftable_28ded0;
struct CompressedQuaternionChannel_28ded0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
extern int g_vftable_28df00;
struct CompressedQuaternionChannel_28df00 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f5ce7ee6

// 0x0028d130 pure3d::DefaultChannelHandler::vfunc_2 (31 B): matches/0x0028d130.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0028d130@@UAEPAV123@E@Z
namespace fn_0028d130 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ChannelHandler_28d130 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ChannelHandler_28d130 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0028d130

namespace fn_f5ce7ee6 {

// 0x0028d150 FUN_0028d150 (128 B): equivalent/0x0028d150.cpp
// sym: ?Construct@CompressedQuaternionChannel_28d150@fn_f5ce7ee6@@QAEPAV12@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_0028d150 @ 0x0028d150
// 0x0028d150: channel constructor holding 8-byte elements, allocated from the parent pool or the heap
CompressedQuaternionChannel_28d150* CompressedQuaternionChannel_28d150::Construct(int a, hulk_intptr b)
{
    FUN_0028b420(a, b);
    vptr = (hulk_intptr)DAT_0042caa8;
    data = 0;
    if (parent == 0) {
        int n = count;
        void* mem = FUN_0008d6d0(n * 8);
        if (mem == 0) {
            data = 0;
            return this;
        }
        FUN_00011520(mem, 8, n, &FUN_00289ed0);
        data = mem;
        return this;
    }
    data = ((void *)((owners::C_2888c0 *)parent)->FUN_002888c0((unsigned)(count * 8), 3));
    return this;
}

} // namespace fn_f5ce7ee6

// 0x0028d220 FUN_0028d220 (121 B): equivalent/0x0028d220.cpp
// sym: ?FUN_0028d220@Quat16_28d220@owners@@QAEPAMPAM@Z
// STATUS: equivalent (tools/equiv.py level 3: 15723 inputs, branch coverage 0/0)
// FUN_0028d220 @ 0x0028d220
// FUN_0028d220 @ 0x0028d220
// Converts four signed 16-bit components to floats scaled by 1/32767.
float* owners::Quat16_28d220::FUN_0028d220(float* out) {
    const float scale = 3.0518509447574615e-05f;
    out[0] = (float)x * scale;
    out[1] = (float)y * scale;
    out[2] = (float)z * scale;
    out[3] = (float)w * scale;
    return out;
}

namespace fn_f5ce7ee6 {

// 0x0028d2a0 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_4 (42 B): matches/0x0028d2a0.cpp
// sym: ?vfunc_4@QuaternionChannel@fn_f5ce7ee6@@QAEXHHH@Z
// Same code shape as 0x0028a9f0 (propagated; names are from that function)
void QuaternionChannel::vfunc_4(int a, int b, int c) {
    char local[16];
    f3(a, b, local);
    ((Helper_28d2a0*)local)->call(c);
}


// 0x0028d2d0 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_5 (306 B): equivalent/0x0028d2d0.cpp
// sym: ?vfunc_5@CompressedQuaternionChannel@fn_f5ce7ee6@@UAEXMPAUQuat_28d2d0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 6/6)
// pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_5 @ 0x0028d2d0
void CompressedQuaternionChannel::vfunc_5(float time, Quat_28d2d0 *out)
{
    Frame_28d2d0 f;

    if (FUN_00289f80(time, &f.lo, &f.hi) && field04 != 0) {
        hulk_freg dt = time - (float)times[f.lo];
        if (dt != 0.0f) {
            int hi = f.hi;
            int span = times[hi] - times[f.lo];
            hulk_freg frac = dt / (float)span;
            CompressedQuaternion8 *vals = values;
            f.q0 = *((Quat_28d2d0 *)((owners::Quat16_28d220 *)&(vals[f.lo]))->FUN_0028d220((float *)(Quat_28d2d0 *)(&f.tmp)));
            f.q1 = *((Quat_28d2d0 *)((owners::Quat16_28d220 *)&(vals[hi]))->FUN_0028d220((float *)(Quat_28d2d0 *)(&f.tmp)));
            ((owners::Quaternion_22b750 *)out)->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_28d2d0 *)(&f.q0), (const owners::Quaternion_22b750 *)(const Quat_28d2d0 *)(&f.q1), frac);
            return;
        }
        *out = *((Quat_28d2d0 *)((owners::Quat16_28d220 *)&(values[f.lo]))->FUN_0028d220((float *)(Quat_28d2d0 *)(&f.q0)));
        return;
    }
    *out = *((Quat_28d2d0 *)((owners::Quat16_28d220 *)&(values[f.lo]))->FUN_0028d220((float *)(Quat_28d2d0 *)(&f.tmp)));
}

} // namespace fn_f5ce7ee6

// 0x0028d410 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_6 (37 B): matches/0x0028d410.cpp [wrapped: conflict: QuaternionChannel]
// sym: ?vfunc_6@QuaternionChannel@fn_0028d410@@UAEXII@Z
namespace fn_0028d410 {
// Same code shape as 0x0028ab20 (propagated; names are from that function)
typedef unsigned int u32_28d410;
struct Buf_28d410 {
    char d[16];
    void Fn(u32_28d410);
};
struct RotationChannel {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(u32_28d410, void*);
};
struct QuaternionChannel : RotationChannel {
    virtual void vfunc_6(u32_28d410, u32_28d410);
};
void QuaternionChannel::vfunc_6(u32_28d410 a, u32_28d410 b) {
    Buf_28d410 buf;
    f5(a, buf.d);
    buf.Fn(b);
}
} // namespace fn_0028d410

namespace fn_f5ce7ee6 {

// 0x0028d440 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_1 (72 B): matches/0x0028d440.cpp
// sym: ?vfunc_1@IntChannel@fn_f5ce7ee6@@QAEXXZ
// Same code shape as 0x0028b4d0 (propagated; names are from that function)
void IntChannel::vfunc_1() {
    if (mObj == 0)
        thunk(m18);
    m18 = 0;
    if (mObj == 0) {
        thunk(m14);
        m14 = 0;
        return;
    }
    Obj_28d440* p = mObj;
    if (p) {
        p->f1();
        mObj = 0;
    }
    m14 = 0;
}


// 0x0028d490 FUN_0028d490 (128 B): equivalent/0x0028d490.cpp
// sym: ?Construct@CompressedQuaternionChannel_28d490@fn_f5ce7ee6@@QAEPAV12@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_0028d490 @ 0x0028d490
// 0x0028d490: channel constructor holding 6-byte elements, allocated from the parent pool or the heap
CompressedQuaternionChannel_28d490* CompressedQuaternionChannel_28d490::Construct(int a, hulk_intptr b)
{
    FUN_0028b420(a, b);
    vptr = (hulk_intptr)DAT_0042cac8;
    data = 0;
    if (parent == 0) {
        int n = count;
        void* mem = FUN_0008d6d0(n * 6);
        if (mem == 0) {
            data = 0;
            return this;
        }
        FUN_00011520(mem, 6, n, &FUN_001db770);
        data = mem;
        return this;
    }
    data = ((void *)((owners::C_2888c0 *)parent)->FUN_002888c0((unsigned)(count * 6), 3));
    return this;
}

} // namespace fn_f5ce7ee6

// 0x0028d510 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_3 (78 B): matches/0x0028d510.cpp
// sym: ?vfunc_3@?$CompressedQuaternionChannel@VCompressedQuaternion6@math@@@pure3d@@UAEXHPAX0@Z
template <> void pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_3(int index, void* __p1, void* __p2) { float * time = (float *)__p1; void * out = (void *)__p2;

    short v = (*(short * *)&this->f_14)[index];
    *time = (float)(int)v;
    char local[16];
    Q_28d510* p = (Q_28d510*)((Decoder_28d510*)((*(char * *)&this->f_18) + index * 6))->Decode(local);
    *(Q_28d510*)out = *p;
}


// 0x0028d560 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_4 (42 B): matches/0x0028d560.cpp [wrapped: same definition as 0x0028d2a0 in this TU]
// sym: ?vfunc_4@QuaternionChannel@fn_0028d560@@QAEXHHH@Z
namespace fn_0028d560 {
// Same code shape as 0x0028a9f0 (propagated; names are from that function)
class QuaternionChannel {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int, void*);
    virtual void f4(int, int);
    virtual void f5();
    virtual void f6();
    void vfunc_4(int a, int b, int c);
};
struct Helper_28d560 {
    void call(int);
};
void QuaternionChannel::vfunc_4(int a, int b, int c) {
    char local[16];
    f3(a, b, local);
    ((Helper_28d560*)local)->call(c);
}
} // namespace fn_0028d560


// 0x0028d590 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_5 (319 B): equivalent/0x0028d590.cpp [wrapped: conflict: CompressedQuaternionChannel]
// sym: ?vfunc_5@CompressedQuaternionChannel@fn_0028d590@@UAEXMPAUQuat_28d590@2@@Z
namespace fn_0028d590 {
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 6/6)
// pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_5 @ 0x0028d590
struct Quat_28d590 {
    float x, y, z, w;
};

struct CompressedQuaternion6 {
    short v[3];
    Quat_28d590 *FUN_001db820(Quat_28d590 *tmp);
};

struct Frame_28d590 {
    int lo;
    int hi;
    Quat_28d590 q1;
    Quat_28d590 q0;
    Quat_28d590 tmp;
};

class CompressedQuaternionChannel {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float time, Quat_28d590 *out);
    virtual void vfunc_6();
    void *field04;
    char pad08[0x10 - 8];
    int count;
    short *times;
    CompressedQuaternion6 *values;
    char FUN_00289f80(float time, int *lo, int *hi);
};

void CompressedQuaternionChannel::vfunc_5(float time, Quat_28d590 *out)
{
    Frame_28d590 f;

    if (FUN_00289f80(time, &f.lo, &f.hi) && field04 != 0) {
        hulk_freg dt = time - (float)times[f.lo];
        if (dt != 0.0f) {
            int hi = f.hi;
            int span = times[hi] - times[f.lo];
            hulk_freg frac = dt / (float)span;
            CompressedQuaternion6 *vals = values;
            f.q0 = *vals[f.lo].FUN_001db820(&f.tmp);
            f.q1 = *vals[hi].FUN_001db820(&f.tmp);
            ((owners::Quaternion_22b750 *)out)->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_28d590 *)(&f.q0), (const owners::Quaternion_22b750 *)(const Quat_28d590 *)(&f.q1), frac);
            return;
        }
        *out = *values[f.lo].FUN_001db820(&f.q0);
        return;
    }
    *out = *values[f.lo].FUN_001db820(&f.tmp);
}
} // namespace fn_0028d590


// 0x0028d6d0 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_6 (37 B): matches/0x0028d6d0.cpp [wrapped: conflict: QuaternionChannel; RotationChannel]
// sym: ?vfunc_6@QuaternionChannel@fn_0028d6d0@@UAEXII@Z
namespace fn_0028d6d0 {
// Same code shape as 0x0028ab20 (propagated; names are from that function)
typedef unsigned int u32_28d6d0;
struct Buf_28d6d0 {
    char d[16];
    void Fn(u32_28d6d0);
};
struct RotationChannel {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(u32_28d6d0, void*);
};
struct QuaternionChannel : RotationChannel {
    virtual void vfunc_6(u32_28d6d0, u32_28d6d0);
};
void QuaternionChannel::vfunc_6(u32_28d6d0 a, u32_28d6d0 b) {
    Buf_28d6d0 buf;
    f5(a, buf.d);
    buf.Fn(b);
}
} // namespace fn_0028d6d0


// 0x0028d700 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_1 (72 B): matches/0x0028d700.cpp [wrapped: conflict: IntChannel]
// sym: ?vfunc_1@IntChannel@fn_0028d700@@QAEXXZ
namespace fn_0028d700 {
// Same code shape as 0x0028b4d0 (propagated; names are from that function)
struct Obj_28d700 {
    virtual void f0();
    virtual void f1();
};
void thunk(int*);
class IntChannel {
  public:
    char pad0[12];
    Obj_28d700* volatile mObj;
    char pad10[4];
    int* m14;
    int* m18;
    void vfunc_1();
};
void IntChannel::vfunc_1() {
    if (mObj == 0)
        thunk(m18);
    m18 = 0;
    if (mObj == 0) {
        thunk(m14);
        m14 = 0;
        return;
    }
    Obj_28d700* p = mObj;
    if (p) {
        p->f1();
        mObj = 0;
    }
    m14 = 0;
}
} // namespace fn_0028d700

namespace fn_f5ce7ee6 {

// 0x0028d750 FUN_0028d750 (128 B): matches/0x0028d750.cpp
// sym: ??0CompressedQuaternionChannel_28d750@fn_f5ce7ee6@@QAE@HH@Z
CompressedQuaternionChannel_28d750::CompressedQuaternionChannel_28d750(int x, hulk_intptr y) : RotationChannel_28d750(x, y) {
    m18 = 0;
    if (mc == 0) {
        int n = m10;
        void* p = Alloc(n * 4);
        m18 = (p ? (VecNew(p, 4, n, ElemCtor), p) : 0);
        return;
    }
    m18 = ((void *)((owners::C_2888c0 *)mc)->FUN_002888c0((unsigned)(m10 << 2), 3));
}

} // namespace fn_f5ce7ee6

// 0x0028d7d0 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion4>::vfunc_3 (75 B): matches/0x0028d7d0.cpp
// sym: ?vfunc_3@?$CompressedQuaternionChannel@VCompressedQuaternion4@math@@@pure3d@@UAEXHPAX0@Z
template <> void pure3d::CompressedQuaternionChannel<math::CompressedQuaternion4>::vfunc_3(int index, void* __p1, void* __p2) { float * time = (float *)__p1; CompressedQuaternion4_28d7d0 * out = (CompressedQuaternion4_28d7d0 *)__p2;

    int value = (*(short * *)&this->f_14)[index];
    *time = (float)value;
    CompressedQuaternion4_28d7d0 temp;
    CompressedQuaternion4_28d7d0* p = (*(PackedQ * *)&this->f_18)[index].Decode(&temp);
    *out = *p;
}

namespace fn_f5ce7ee6 {

// 0x0028d820 FUN_0028d820 (207 B): equivalent/0x0028d820.cpp
// sym: ?decode@Packed@fn_f5ce7ee6@@QAEPAUQuaternion_28d820@2@PAU32@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0028d820 @ 0x0028d820
Quaternion_28d820* Packed::decode(Quaternion_28d820* out) {
 unsigned int v=bits;
 double x=(int)(v&2047)* (double)0.00097751710657030344f - 1.0;
 float y=(float)((int)((v>>11)&2047)*(double)0.00097751710657030344f-1.0);
 double zz=(int)(v>>22)*(double)0.001956947147846222f-1.0;
 float z=(float)zz;
 double w=1.0-((zz*z+(double)y*y)+x*x);
 if(w<0.0) w=0.0; else w=sqrt(w);
 out->x=(float)x; out->y=y; out->z=z; out->w=(float)w;
 return out;
}

} // namespace fn_f5ce7ee6

// 0x0028d8f0 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion4>::vfunc_4 (42 B): matches/0x0028d8f0.cpp [wrapped: same definition as 0x0028d2a0 in this TU]
// sym: ?vfunc_4@QuaternionChannel@fn_0028d8f0@@QAEXHHH@Z
namespace fn_0028d8f0 {
// Same code shape as 0x0028a9f0 (propagated; names are from that function)
class QuaternionChannel {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int, void*);
    virtual void f4(int, int);
    virtual void f5();
    virtual void f6();
    void vfunc_4(int a, int b, int c);
};
struct Helper_28d8f0 {
    void call(int);
};
void QuaternionChannel::vfunc_4(int a, int b, int c) {
    char local[16];
    f3(a, b, local);
    ((Helper_28d8f0*)local)->call(c);
}
} // namespace fn_0028d8f0


// 0x0028d920 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion4>::vfunc_5 (306 B): equivalent/0x0028d920.cpp [wrapped: conflict: CompressedQuaternionChannel]
// sym: ?vfunc_5@CompressedQuaternionChannel@fn_0028d920@@UAEXMPAUQuat_28d920@2@@Z
namespace fn_0028d920 {
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 6/6)
// pure3d::CompressedQuaternionChannel<math::CompressedQuaternion4>::vfunc_5 @ 0x0028d920
struct Quat_28d920 {
    float x, y, z, w;
};

struct CompressedQuaternion4 {
    short v[2];
    Quat_28d920 *FUN_0028d820(Quat_28d920 *tmp);
};

struct Frame_28d920 {
    int lo;
    int hi;
    Quat_28d920 q1;
    Quat_28d920 q0;
    Quat_28d920 tmp;
};

class CompressedQuaternionChannel {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float time, Quat_28d920 *out);
    virtual void vfunc_6();
    void *field04;
    char pad08[0x10 - 8];
    int count;
    short *times;
    CompressedQuaternion4 *values;
    char FUN_00289f80(float time, int *lo, int *hi);
};

void CompressedQuaternionChannel::vfunc_5(float time, Quat_28d920 *out)
{
    Frame_28d920 f;

    if (FUN_00289f80(time, &f.lo, &f.hi) && field04 != 0) {
        hulk_freg dt = time - (float)times[f.lo];
        if (dt != 0.0f) {
            int hi = f.hi;
            int span = times[hi] - times[f.lo];
            hulk_freg frac = dt / (float)span;
            CompressedQuaternion4 *vals = values;
            f.q0 = *vals[f.lo].FUN_0028d820(&f.tmp);
            f.q1 = *vals[hi].FUN_0028d820(&f.tmp);
            ((owners::Quaternion_22b750 *)out)->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_28d920 *)(&f.q0), (const owners::Quaternion_22b750 *)(const Quat_28d920 *)(&f.q1), frac);
            return;
        }
        *out = *values[f.lo].FUN_0028d820(&f.q0);
        return;
    }
    *out = *values[f.lo].FUN_0028d820(&f.tmp);
}
} // namespace fn_0028d920


// 0x0028da60 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion4>::vfunc_6 (37 B): matches/0x0028da60.cpp [wrapped: conflict: QuaternionChannel; RotationChannel]
// sym: ?vfunc_6@QuaternionChannel@fn_0028da60@@UAEXII@Z
namespace fn_0028da60 {
// Same code shape as 0x0028ab20 (propagated; names are from that function)
typedef unsigned int u32_28da60;
struct Buf_28da60 {
    char d[16];
    void Fn(u32_28da60);
};
struct RotationChannel {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(u32_28da60, void*);
};
struct QuaternionChannel : RotationChannel {
    virtual void vfunc_6(u32_28da60, u32_28da60);
};
void QuaternionChannel::vfunc_6(u32_28da60 a, u32_28da60 b) {
    Buf_28da60 buf;
    f5(a, buf.d);
    buf.Fn(b);
}
} // namespace fn_0028da60


// 0x0028da90 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion4>::vfunc_1 (72 B): matches/0x0028da90.cpp [wrapped: conflict: IntChannel]
// sym: ?vfunc_1@IntChannel@fn_0028da90@@QAEXXZ
namespace fn_0028da90 {
// Same code shape as 0x0028b4d0 (propagated; names are from that function)
struct Obj_28da90 {
    virtual void f0();
    virtual void f1();
};
void thunk(int*);
class IntChannel {
  public:
    char pad0[12];
    Obj_28da90* volatile mObj;
    char pad10[4];
    int* m14;
    int* m18;
    void vfunc_1();
};
void IntChannel::vfunc_1() {
    if (mObj == 0)
        thunk(m18);
    m18 = 0;
    if (mObj == 0) {
        thunk(m14);
        m14 = 0;
        return;
    }
    Obj_28da90* p = mObj;
    if (p) {
        p->f1();
        mObj = 0;
    }
    m14 = 0;
}
} // namespace fn_0028da90


// 0x0028dae0 FUN_0028dae0 (124 B): equivalent/0x0028dae0.cpp [wrapped: conflict: CompressedQuaternionChannel]
// sym: ??0CompressedQuaternionChannel@fn_0028dae0@@QAE@HH@Z
namespace fn_0028dae0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0028dae0 @ 0x0028dae0
void *__cdecl FUN_0008d6d0(unsigned int size);
void __stdcall FUN_00011520(void *base, unsigned int size, int count, void *ctor);
extern char FUN_00289ef0;

struct SharedPool {
};

class RotationChannel_28dae0 {
public:
    RotationChannel_28dae0(int a, int b) throw();
    virtual void v0();

    char pad04[8];
    SharedPool *shared;  // +0x0c
    int count;           // +0x10
    int pad14;
};

// equiv-map: ??0ChannelBase@@QAE@HH@Z = 0x0028b420
class CompressedQuaternionChannel : public RotationChannel_28dae0 {
public:
    CompressedQuaternionChannel(int a, hulk_intptr b);
    virtual void v0();

    void *data;          // +0x18
};

// Allocates (or borrows from the shared pool) 3 bytes per element.
CompressedQuaternionChannel::CompressedQuaternionChannel(int a, hulk_intptr b) : RotationChannel_28dae0(a, b) {
    data = 0;
    if (shared == 0) {
        int n = count;
        void *mem = FUN_0008d6d0(n * 3);
        if (mem != 0) {
            FUN_00011520(mem, 3, n, &FUN_00289ef0);
            data = mem;
        } else {
            data = 0;
        }
    } else {
        data = ((void *)((owners::C_2888c0 *)shared)->FUN_002888c0((unsigned)(count * 3), 3));
    }
}
} // namespace fn_0028dae0


// 0x0028db60 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion3>::vfunc_3 (77 B): matches/0x0028db60.cpp
// sym: ?vfunc_3@?$CompressedQuaternionChannel@VCompressedQuaternion3@math@@@pure3d@@UAEXHPAX0@Z
 // namespace pure3d
template <> void pure3d::CompressedQuaternionChannel<math::CompressedQuaternion3>::vfunc_3(int index, void* __p1, void* __p2) { float * time = (float *)__p1; math::Quaternion * rotation = (math::Quaternion *)__p2;

    *time = (float)(*(short * *)&this->f_14)[index];
    math::Quaternion temp;
    math::Quaternion* decoded = (*(math::CompressedQuaternion3_28db60 * *)&this->f_18)[index].FUN_0028dbb0(&temp);
    *rotation = *decoded;
}

namespace fn_f5ce7ee6 {

// 0x0028dbb0 FUN_0028dbb0 (176 B): equivalent/0x0028dbb0.cpp
// sym: ?unpack@PackedQuaternion_28dbb0@fn_f5ce7ee6@@QAEPAUQuaternion_28dbb0@2@PAU32@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 2/2)
// FUN_0028dbb0 @ 0x0028dbb0
Quaternion_28dbb0* PackedQuaternion_28dbb0::unpack(Quaternion_28dbb0* output) {
 // x87: fx and the sum stay in registers (53 bits), fy goes through the frame; z is squared as its register value
 // times its rounded frame copy (fst, then fmul by the copy)
 double fx = x * 0.0078740157186985016f;
 float fy = y * 0.0078740157186985016f;
 hulk_freg fzu = z * 0.0078740157186985016f;
 float fz = (float)fzu;
 double remainder = 1.0f - (fzu*fz + fy*fy + fx*fx);
 float w = remainder > 0.0f ? (float)sqrt(remainder) : 0.0f;
 output->x=fx; output->y=fy; output->z=fz; output->w=w;
 return output;
}

} // namespace fn_f5ce7ee6

// 0x0028dc60 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion3>::vfunc_4 (42 B): matches/0x0028dc60.cpp [wrapped: same definition as 0x0028d2a0 in this TU]
// sym: ?vfunc_4@QuaternionChannel@fn_0028dc60@@QAEXHHH@Z
namespace fn_0028dc60 {
// Same code shape as 0x0028a9f0 (propagated; names are from that function)
class QuaternionChannel {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int, void*);
    virtual void f4(int, int);
    virtual void f5();
    virtual void f6();
    void vfunc_4(int a, int b, int c);
};
struct Helper_28dc60 {
    void call(int);
};
void QuaternionChannel::vfunc_4(int a, int b, int c) {
    char local[16];
    f3(a, b, local);
    ((Helper_28dc60*)local)->call(c);
}
} // namespace fn_0028dc60


// 0x0028dc90 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion3>::vfunc_5 (346 B): equivalent/0x0028dc90.cpp [wrapped: conflict: CompressedQuaternionChannel]
// sym: ?vfunc_5@CompressedQuaternionChannel@fn_0028dc90@@UAEXMPAUQuat_28dc90@2@@Z
namespace fn_0028dc90 {
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 6/6)
// pure3d::CompressedQuaternionChannel<math::CompressedQuaternion3>::vfunc_5 @ 0x0028dc90
struct Quat_28dc90 {
    float x, y, z, w;
};

struct CompressedQuaternion3 {
    signed char v[3];
    Quat_28dc90 *FUN_0028dbb0(Quat_28dc90 *tmp);
};

struct Frame_28dc90 {
    int lo;
    int hi;
    Quat_28dc90 q1;
    Quat_28dc90 q0;
    Quat_28dc90 tmp;
};

class CompressedQuaternionChannel {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float time, Quat_28dc90 *out);
    virtual void vfunc_6();
    void *field04;
    char pad08[0x10 - 8];
    int count;
    short *times;
    CompressedQuaternion3 *values;
    char FUN_00289f80(float time, int *lo, int *hi);
};

void CompressedQuaternionChannel::vfunc_5(float time, Quat_28dc90 *out)
{
    Frame_28dc90 f;

    if (FUN_00289f80(time, &f.lo, &f.hi) && field04 != 0) {
        hulk_freg dt = time - (float)times[f.lo];
        if (dt != 0.0f) {
            int hi = f.hi;
            int span = times[hi] - times[f.lo];
            hulk_freg frac = dt / (float)span;
            CompressedQuaternion3 *vals = values;
            f.q0 = *vals[f.lo].FUN_0028dbb0(&f.tmp);
            f.q1 = *vals[hi].FUN_0028dbb0(&f.tmp);
            ((owners::Quaternion_22b750 *)out)->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_28dc90 *)(&f.q0), (const owners::Quaternion_22b750 *)(const Quat_28dc90 *)(&f.q1), frac);
            return;
        }
        *out = *values[f.lo].FUN_0028dbb0(&f.q0);
        return;
    }
    *out = *values[f.lo].FUN_0028dbb0(&f.tmp);
}
} // namespace fn_0028dc90


// 0x0028ddf0 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion3>::vfunc_6 (37 B): matches/0x0028ddf0.cpp [wrapped: conflict: QuaternionChannel; RotationChannel]
// sym: ?vfunc_6@QuaternionChannel@fn_0028ddf0@@UAEXII@Z
namespace fn_0028ddf0 {
// Same code shape as 0x0028ab20 (propagated; names are from that function)
typedef unsigned int u32_28ddf0;
struct Buf_28ddf0 {
    char d[16];
    void Fn(u32_28ddf0);
};
struct RotationChannel {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(u32_28ddf0, void*);
};
struct QuaternionChannel : RotationChannel {
    virtual void vfunc_6(u32_28ddf0, u32_28ddf0);
};
void QuaternionChannel::vfunc_6(u32_28ddf0 a, u32_28ddf0 b) {
    Buf_28ddf0 buf;
    f5(a, buf.d);
    buf.Fn(b);
}
} // namespace fn_0028ddf0


// 0x0028de20 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion3>::vfunc_1 (72 B): matches/0x0028de20.cpp [wrapped: conflict: IntChannel]
// sym: ?vfunc_1@IntChannel@fn_0028de20@@QAEXXZ
namespace fn_0028de20 {
// Same code shape as 0x0028b4d0 (propagated; names are from that function)
struct Obj_28de20 {
    virtual void f0();
    virtual void f1();
};
void thunk(int*);
class IntChannel {
  public:
    char pad0[12];
    Obj_28de20* volatile mObj;
    char pad10[4];
    int* m14;
    int* m18;
    void vfunc_1();
};
void IntChannel::vfunc_1() {
    if (mObj == 0)
        thunk(m18);
    m18 = 0;
    if (mObj == 0) {
        thunk(m14);
        m14 = 0;
        return;
    }
    Obj_28de20* p = mObj;
    if (p) {
        p->f1();
        mObj = 0;
    }
    m14 = 0;
}
} // namespace fn_0028de20

namespace fn_f5ce7ee6 {

// 0x0028de70 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_0 (43 B): matches/0x0028de70.cpp
// sym: ?scalar_dtor@CompressedQuaternionChannel_28de70@fn_f5ce7ee6@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* CompressedQuaternionChannel_28de70::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_28de70;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}


// 0x0028dea0 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_0 (43 B): matches/0x0028dea0.cpp
// sym: ?scalar_dtor@CompressedQuaternionChannel_28dea0@fn_f5ce7ee6@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* CompressedQuaternionChannel_28dea0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_28dea0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}


// 0x0028ded0 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion4>::vfunc_0 (43 B): matches/0x0028ded0.cpp
// sym: ?scalar_dtor@CompressedQuaternionChannel_28ded0@fn_f5ce7ee6@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* CompressedQuaternionChannel_28ded0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_28ded0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}


// 0x0028df00 pure3d::CompressedQuaternionChannel<math::CompressedQuaternion3>::vfunc_0 (43 B): matches/0x0028df00.cpp
// sym: ?scalar_dtor@CompressedQuaternionChannel_28df00@fn_f5ce7ee6@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* CompressedQuaternionChannel_28df00::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_28df00;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5ce7ee6
