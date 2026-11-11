// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028a8e0..0x0028b8f0 (kind game, layer engine, confidence high), dominant class pure3d::QuaternionChannel
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f66a22d3 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f66a22d3 {} using namespace fn_f66a22d3;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f66a22d3 {
struct Vec_28a8f0 {
    float x, y, z, w;
    void FUN_0022b610(const Vec_28a8f0* a, const Vec_28a8f0* b);
};
extern "C" void __cdecl FUN_0022b080(Vec_28a8f0* out, const Vec_28a8f0* a, const Vec_28a8f0* b);
struct Curve_28a8f0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void sample(float t, Vec_28a8f0* out);
    char pad[12];
    int count;
    short* times;
    void target(float a, float b, Vec_28a8f0* out);
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
struct Helper_28a9f0 {
    void call_0022b650(int);
};
} // namespace fn_f66a22d3
namespace pure3d {
struct Quaternion_28aa20 {
 float x,y,z,w;
 void FUN_0022b750(const Quaternion_28aa20*, const Quaternion_28aa20*, float);
};
}
namespace pure3d {
struct QuaternionChannel_nv_28aa20 {
    bool FUN_00289f80(float, int*, int*);
};
}
namespace fn_f66a22d3 {
class pure3d__Channel {
  public:
    virtual ~pure3d__Channel();
    virtual void vfunc_1();
    virtual unsigned int GetTypeID();
};
class pure3d__SimpleChannel : public pure3d__Channel {};
} // namespace fn_f66a22d3
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
#endif
namespace fn_f66a22d3 {
class Item {
  public:
    virtual void AddRef();
};
class List {
  public:
    char pad[8];
    int count;
    Item* items[1];
    void Add(Item* item);
};
class Item_28b020 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Match(int);
};
class List_28b020 {
  public:
    char pad[8];
    int count;
    Item_28b020* items[1];
    Item_28b020* Find(int arg);
};
class Item_28b070 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Test(void*);
};
class Container_28b070 {
  public:
    char pad[8];
    int count;
    Item_28b070* items[1];
    bool Find(void*);
};
class Elem_28b0b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(void*);
    virtual int v4(Elem_28b0b0* a, int b, int c);
};
class Arg_28b0b0 {
  public:
    void* Get_00266c30();
};
struct Container_28b0b0 {
    int m_a;
    int m_b;
    int m_count;
    Elem_28b0b0* arr[1];
    hulk_intptr Find(Elem_28b0b0* arg, int p2, hulk_intptr p3);
};
class C_28b100 {
  public:
    void Decode_0028a0b0(int, int*);
};
struct Obj_28b150 {
    void Get_0028a1c0(int d, float* out);
};
struct Pair_28b190 {
    float x, y;
};
class Obj_28b190 {
  public:
    void Get_0028a2c0(int, Pair_28b190*);
};
struct Vec3_28b200 {
    float x, y, z;
};
class Curve_28b200 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(int key, Vec3_28b200* out);
};
struct Source_28b2f0 { void FUN_0028ad20(int index, unsigned int* result); };
extern "C" void* __cdecl AllocA_0008d6d0(unsigned int) throw();
} // namespace fn_f66a22d3
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int) throw();
#endif
namespace fn_f66a22d3 {
class Owner_28b420 {
  public:
    virtual void V() throw();
};
class Channel {
  public:
    virtual ~Channel() throw();
    int a, b;
    Channel() throw() : a(-1), b(0) {}
};
class SimpleChannel : public Channel {
  public:
    virtual ~SimpleChannel() throw();
    Owner_28b420* c;
    int d;
    char* e;
    SimpleChannel(int size, Owner_28b420* owner) throw();
};
struct Obj_28b4d0 {
    virtual void f0();
    virtual void f1();
};
void thunk_0008d340(int*);
struct Obj_28b520 {
    virtual void f0();
    virtual void f1();
};
struct Obj_28b570 {
    virtual void f0();
    virtual void f1();
};
class Ref_28b5c0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Ref_28b610 {
  public:
    virtual void f0();
    virtual void Release();
};
struct Obj_28b660 {
    virtual void f0();
    virtual void f1();
};
struct Obj_28b6b0 {
    virtual void f0();
    virtual void f1();
};
class Ref_28b760 {
  public:
    virtual void v0();
    virtual void v1();
};
class Elem_28b760 {
  public:
    char d[8];
    ~Elem_28b760() throw();
};
} // namespace fn_f66a22d3
void operator delete(void*);
namespace fn_f66a22d3 {
struct Obj_28b7d0 {
    virtual void v0();
    virtual void Release();
};
void __cdecl Free_0008d340(void*);
inline void Del(Obj_28b7d0*& p) {
    if (p) {
        p->Release();
        p = 0;
    }
}
struct Obj_28b840 {
    virtual void f0();
    virtual void f1();
};
class BoolChannel_28b840 {
  public:
    char pad0[12];
    Obj_28b840* volatile mObj;
    char pad10[4];
    int* m14;
    int* m18;
    void vfunc_1();
};
struct Obj_28b890 {
    virtual void f0();
    virtual void f1();
};


// 0x0028a8e0 pure3d::RotationChannel::vfunc_2 (6 B): matches/0x0028a8e0.cpp
// sym: _FUN_0028a8e0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0028a8e0() {
    return (int*)0x544f52;
}


// 0x0028a8f0 FUN_0028a8f0 (192 B): matches/0x0028a8f0.cpp
// sym: ?target@Curve_28a8f0@fn_f66a22d3@@QAEXMMPAUVec_28a8f0@2@@Z
void Curve_28a8f0::target(float a, float b, Vec_28a8f0* out) {
    Vec_28a8f0 first, second, start, end, tail;
    sample(a, &first);
    sample(b, &second);
    if (a <= b) {
        out->FUN_0022b610(&second, &first);
    } else {
        sample(0.0f, &start);
        sample((float)times[count - 1], &end);
        tail.FUN_0022b610(&second, &start);
        out->FUN_0022b610(&end, &first);
        FUN_0022b080(out, out, &tail);
    }
}

} // namespace fn_f66a22d3

// 0x0028a9b0 pure3d::QuaternionChannel::vfunc_3 (62 B): matches/0x0028a9b0.cpp
// sym: ?vfunc_3@QuaternionChannel@pure3d@@UAEXHPAX0@Z
void pure3d::QuaternionChannel::vfunc_3(int index, void* __p1, void* __p2) { float * time = (float *)__p1; unsigned int * out = (unsigned int *)__p2;

    *time = (float)(*(short * *)&this->f_14)[index];
    unsigned int* p = (unsigned int*)((char*)(*(unsigned int * *)&this->f_18) + index * 16);
    out[0] = p[0];
    out[1] = p[1];
    out[2] = p[2];
    out[3] = p[3];
}

namespace fn_f66a22d3 {

// 0x0028a9f0 pure3d::QuaternionChannel::vfunc_4 (42 B): matches/0x0028a9f0.cpp
// sym: ?vfunc_4@QuaternionChannel@fn_f66a22d3@@QAEXHHH@Z
void QuaternionChannel::vfunc_4(int a, int b, int c) {
    char local[16];
    f3(a, b, local);
    ((Helper_28a9f0*)local)->call_0022b650(c);
}

} // namespace fn_f66a22d3

// 0x0028aa20 pure3d::QuaternionChannel::vfunc_5 (241 B): equivalent/0x0028aa20.cpp
// sym: ?vfunc_5@QuaternionChannel@pure3d@@UAEXMH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// pure3d::QuaternionChannel::vfunc_5 @ 0x0028aa20
void pure3d::QuaternionChannel::vfunc_5(float time, hulk_intptr __p1) { Quaternion_28aa20 * out = (Quaternion_28aa20 *)__p1;

 int first, second;
 bool found = ((QuaternionChannel_nv_28aa20*)this)->FUN_00289f80(time, &first, &second);
 if (found && this->f_04) {
   double delta = (double)time - (int)(*(short * *)&this->f_14)[first];
   if (delta != 0.0f) {
     int span = (int)(*(short * *)&this->f_14)[second] - (int)(*(short * *)&this->f_14)[first];
     out->FUN_0022b750(&(*(Quaternion_28aa20 * *)&this->f_18)[first], &(*(Quaternion_28aa20 * *)&this->f_18)[second], (float)(delta / span));
     return;
   }
 }
 *out = (*(Quaternion_28aa20 * *)&this->f_18)[first];
}


// 0x0028ab20 pure3d::QuaternionChannel::vfunc_6 (37 B): matches/0x0028ab20.cpp [wrapped: conflict: QuaternionChannel]
// sym: ?vfunc_6@QuaternionChannel@fn_0028ab20@@UAEXII@Z
namespace fn_0028ab20 {
typedef unsigned int u32_28ab20;
struct Buf_28ab20 {
    char d[16];
    void Fn_0022b650(u32_28ab20);
};
struct RotationChannel {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(u32_28ab20, void*);
};
struct QuaternionChannel : RotationChannel {
    virtual void vfunc_6(u32_28ab20, u32_28ab20);
};
void QuaternionChannel::vfunc_6(u32_28ab20 a, u32_28ab20 b) {
    Buf_28ab20 buf;
    f5(a, buf.d);
    buf.Fn_0022b650(b);
}
} // namespace fn_0028ab20

namespace fn_f66a22d3 {

// 0x0028ab50 pure3d::StringChannel::vfunc_2 (6 B): matches/0x0028ab50.cpp
// sym: _FUN_0028ab50
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0028ab50() {
    return (int*)0x525453;
}


// 0x0028abc0 pure3d::EntityChannel::vfunc_2 (6 B): matches/0x0028abc0.cpp
// sym: _FUN_0028abc0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0028abc0() {
    return (int*)0x544e45;
}

} // namespace fn_f66a22d3

// 0x0028ac00 FUN_0028ac00 (47 B): matches/0x0028ac00.cpp
// sym: ?FUN_0028ac00@Obj_28ac00@owners@@QAEXHPAH@Z
void owners::Obj_28ac00::FUN_0028ac00(int a, int* out) {
    int local;
    helper(a, &a, &local);
    *out = arr[a];
}


// 0x0028ac30 pure3d::BoolChannel::vfunc_2 (6 B): matches/0x0028ac30.cpp
// sym: ?vfunc_2@BoolChannel@pure3d@@UAEIXZ
unsigned int pure3d::BoolChannel::vfunc_2() {
    return 0x4c4f4f42;
}


// 0x0028ac90 FUN_0028ac90 (76 B): matches/0x0028ac90.cpp
// sym: ?FUN_0028ac90@Obj_28ac90@owners@@QAEXIPA_N@Z
void owners::Obj_28ac90::FUN_0028ac90(unsigned int index, bool* out) {
    unsigned int local;
    Normalize(index, &index, &local);
    unsigned int offset = (index >> 5) * 4;
    unsigned int rem = index - offset * 8;
    unsigned int mask = 1;
    mask <<= rem;
    unsigned int value = *(unsigned int*)(bits + offset);
    *out = (value & mask) > 0;
}

namespace fn_f66a22d3 {

// 0x0028ace0 pure3d::ColourChannel::vfunc_2 (6 B): matches/0x0028ace0.cpp
// sym: _FUN_0028ace0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0028ace0() {
    return (int*)0x524c43;
}

} // namespace fn_f66a22d3

// 0x0028ad20 FUN_0028ad20 (290 B): equivalent/0x0028ad20.cpp
// sym: ?FUN_0028ad20@Track_28ad20@owners@@QAEXMPAI@Z
// STATUS: equivalent (tools/equiv.py level 3: 2628 inputs, branch coverage 6/6)
// FUN_0028ad20 @ 0x0028ad20
void owners::Track_28ad20::FUN_0028ad20(float value,unsigned int* output) {
 int lower,upper;
 if (!FUN_00289f80(value,&lower,&upper) || !enabled) { *output=colors[lower]; return; }
 int start=times[lower];
 int delta=(int)value-start;
 if (!delta) { *output=colors[lower]; return; }
 int duration=times[upper]-times[lower];
 unsigned int a=colors[lower],b=colors[upper];
 int alpha=a>>24, green=(a>>8)&255, blue=(a>>16)&255, red=a&255;
 unsigned int result=(unsigned int)(alpha+((int)(b>>24)-alpha)*delta/duration)<<24;
 result|=(unsigned int)(green+((int)((b>>8)&255)-green)*delta/duration)<<8;
 result|=(unsigned int)(blue+((int)((b>>16)&255)-blue)*delta/duration)<<16;
 result|=(unsigned int)(red+((int)(b&255)-red)*delta/duration);
 *output=result;
}


// 0x0028ae50 pure3d::DefaultChannelHandler::vfunc_3 (38 B): equivalent/0x0028ae50.cpp
// sym: ?vfunc_3@DefaultChannelHandler@pure3d@@UAEHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 4/4)
// pure3d::DefaultChannelHandler::vfunc_3 @ 0x0028ae50
int pure3d::DefaultChannelHandler::vfunc_3(int __p0) { unsigned int channel = (unsigned int)__p0;
 unsigned int index = channel - 0x121100; if (index <= 0x14) { switch (index) { case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 14: case 17: case 18: case 19: case 20: return (int)(1); default: return (int)(0); } } return (int)(index & 0xffffff00u); }


// 0x0028aea0 pure3d::DefaultChannelHandler::vfunc_5 (218 B): equivalent/0x0028aea0.cpp
// sym: ?vfunc_5@DefaultChannelHandler@pure3d@@UAEXHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 23/23)
// pure3d::DefaultChannelHandler::vfunc_5 @ 0x0028aea0
void pure3d::DefaultChannelHandler::vfunc_5(hulk_intptr __p0, hulk_intptr __p1, int __p2, int __p3) { unsigned int * header = (unsigned int *)__p0; unsigned int * size = (unsigned int *)__p1; unsigned int type = (unsigned int)__p2; unsigned short count = (unsigned short)__p3;

 unsigned a=0,b=0; *header=0;
 switch(type) {
 case 0x121100: case 0x121107: case 0x121109: case 0x12110e: case 0x121113: a=count*4; b=count*2; *header=0x1c; break;
 case 0x121101: case 0x121111: a=count*8; b=count*2; *header=0x1c; break;
 case 0x121102: a=count*4; b=count*2; *header=0x2c; break;
 case 0x121103: a=count*8; b=count*2; *header=0x2c; break;
 case 0x121104: a=count*12; b=count*2; *header=0x1c; break;
 case 0x121105: a=count*16; b=count*2; *header=0x1c; break;
 case 0x121106: a=count*8; b=count*2; *header=0x1c; break;
 case 0x121108: a=(((int)count-1)>>5)*4+4; b=count*2; *header=0x1c; break;
 case 0x121112: a=count*6; b=count*2; *header=0x1c; break;
 case 0x121114: a=count*3; b=count*2; *header=0x1c; break;
 }
 *header=(*header+7)&~7u;
 *size=((a+3)&~3u)+((b+3)&~3u);
}

namespace fn_f66a22d3 {

// 0x0028afe0 FUN_0028afe0 (53 B): matches/0x0028afe0.cpp
// sym: ?Add@List@fn_f66a22d3@@QAEXPAVItem@2@@Z
void List::Add(Item* item) {
    if (item) {
        memmove(items + 1, items, count * 4);
        items[0] = item;
        item->AddRef();
        ++count;
    }
}


// 0x0028b020 FUN_0028b020 (65 B): matches/0x0028b020.cpp
// sym: ?Find@List_28b020@fn_f66a22d3@@QAEPAVItem_28b020@2@H@Z
Item_28b020* List_28b020::Find(int arg) {
    int i = 0;
    if (count > 0) {
        do {
            if (items[i]->Match(arg) == 1)
                return items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}


// 0x0028b070 FUN_0028b070 (63 B): matches/0x0028b070.cpp
// sym: ?Find@Container_28b070@fn_f66a22d3@@QAE_NPAX@Z
bool Container_28b070::Find(void* arg) {
    int i = 0;
    if (count > 0) {
        Item_28b070** p = items;
        do {
            if ((*p)->Test(arg) == true)
                return true;
            ++i;
            ++p;
        } while (i < count);
    }
    return false;
}


// 0x0028b0b0 FUN_0028b0b0 (74 B): matches/0x0028b0b0.cpp
// sym: ?Find@Container_28b0b0@fn_f66a22d3@@QAEHPAVElem_28b0b0@2@HH@Z
hulk_intptr Container_28b0b0::Find(Elem_28b0b0* arg, int p2, hulk_intptr p3) {
    int i = 0;
    Elem_28b0b0** p = arr;
    if (m_count > 0) {
        do {
            if (arr[i]->v3(((Arg_28b0b0*)arg)->Get_00266c30()) == 1)
                return arr[i]->v4(arg, p2, p3);
            i++;
        } while (i < m_count);
    }
    return 0;
}


// 0x0028b100 FUN_0028b100 (72 B): matches/0x0028b100.cpp
// sym: _FUN_0028b100
extern "C" int __cdecl FUN_0028b100(C_28b100* a, C_28b100* b, float scale, int input) {
    int x;
    int y;
    a->Decode_0028a0b0(input, &x);
    b->Decode_0028a0b0(input, &y);
    int d = y - x;
    return (int)(__int64)((float)d * scale) + x;
}


// 0x0028b150 FUN_0028b150 (58 B): matches/0x0028b150.cpp
// sym: ?FUN_0028b150@fn_f66a22d3@@YAMPAUObj_28b150@1@0MH@Z
hulk_freg __cdecl FUN_0028b150(Obj_28b150* a, Obj_28b150* b, float t, int d) {
    float x, y;
    a->Get_0028a1c0(d, &x);
    b->Get_0028a1c0(d, &y);
    return (y - x) * t + x;
}


// 0x0028b190 FUN_0028b190 (97 B): matches/0x0028b190.cpp
// sym: ?F@fn_f66a22d3@@YAXPAUPair_28b190@1@PAVObj_28b190@1@1MH@Z
void F(Pair_28b190* out, Obj_28b190* a, Obj_28b190* b, float t, int n) {
    Pair_28b190 p, q;
    a->Get_0028a2c0(n, &p);
    b->Get_0028a2c0(n, &q);
    p.x = (q.x - p.x) * t + p.x;
    p.y = (q.y - p.y) * t + p.y;
    *out = p;
}


// 0x0028b200 FUN_0028b200 (126 B): equivalent/0x0028b200.cpp
// sym: ?FUN_0028b200@fn_f66a22d3@@YAXPAUVec3_28b200@1@PAVCurve_28b200@1@1MH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0028b200 @ 0x0028b200
// Linearly interpolates between the values of two curves sampled at key.
void FUN_0028b200(Vec3_28b200* out, Curve_28b200* a, Curve_28b200* b, float t, int key)
{
    Vec3_28b200 va, vb;
    a->vfunc_4(key, &va);
    b->vfunc_4(key, &vb);
    va.x = (vb.x - va.x) * t + va.x;
    out->x = va.x;
    va.y = (vb.y - va.y) * t + va.y;
    out->y = va.y;
    va.z = (vb.z - va.z) * t + va.z;
    out->z = va.z;
}


// 0x0028b2f0 FUN_0028b2f0 (210 B): equivalent/0x0028b2f0.cpp
// sym: _FUN_0028b2f0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0028b2f0 @ 0x0028b2f0
extern "C" unsigned int* __cdecl FUN_0028b2f0(unsigned int* output, Source_28b2f0* first, Source_28b2f0* second, float factor, int index) {
 unsigned int a,b;
 first->FUN_0028ad20(index, &a);
 second->FUN_0028ad20(index, &b);
 int a1=(a>>8)&255, a2=(a>>16)&255, a3=a>>24, a0=a&255;
 unsigned int result=(unsigned int)((int)(((int)((b>>8)&255)-a1)*(double)factor)+a1)<<8;
 result |= (unsigned int)((int)(((int)((b>>16)&255)-a2)*(double)factor)+a2)<<16;
 result |= (unsigned int)((int)(((int)(b>>24)-a3)*(double)factor)+a3)<<24;
 result |= (unsigned int)((int)(((int)(b&255)-a0)*(double)factor)+a0);
 *output=result;
 return output;
}


// 0x0028b420 FUN_0028b420 (111 B): matches/0x0028b420.cpp
// sym: ??0SimpleChannel@fn_f66a22d3@@QAE@HPAVOwner_28b420@1@@Z
SimpleChannel::SimpleChannel(int size, Owner_28b420* owner) throw() : c(owner), d(size), e(0) {
    if (owner == 0)
        e = (char*)AllocA_0008d6d0(size * 2);
    else {
        e = (char*)((void *)((owners::C_2888c0 *)owner)->FUN_002888c0((unsigned)(size * 2), 3));
        Owner_28b420* o = c;
        o->V();
    }
    memset(e, 0, d * 2);
}

} // namespace fn_f66a22d3

// 0x0028b490 pure3d::SimpleChannel::vfunc_1 (52 B): equivalent/0x0028b490.cpp [wrapped: conflict: pure3d::Channel; pure3d::SimpleChannel]
// sym: ?vfunc_1@SimpleChannel@pure3d@fn_0028b490@@UAEXXZ
namespace fn_0028b490 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 3/4, incomplete)
// pure3d::SimpleChannel::vfunc_1 @ 0x0028b490
namespace pure3d {
struct Object {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Channel {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    char pad[8];
    Object* object;
    char pad2[4];
    void* data;
};
struct SimpleChannel : Channel {
    void vfunc_1();
};
}
void __cdecl FUN_0008d340(void*);
void pure3d::SimpleChannel::vfunc_1() {
    if (object == 0) {
        FUN_0008d340(data);
        data = 0;
        return;
    }
    if (object != 0) {
        object->vfunc_1();
        object = 0;
    }
    data = 0;
}
} // namespace fn_0028b490


// 0x0028b4d0 pure3d::IntChannel::vfunc_1 (72 B): matches/0x0028b4d0.cpp
// sym: ?vfunc_1@IntChannel@pure3d@@UAEXXZ
void pure3d::IntChannel::vfunc_1() {
    if ((*(Obj_28b4d0 *volatile *)&this->f_0c) == 0)
        thunk_0008d340((*(int * *)&this->f_18));
    (*(int * *)&this->f_18) = 0;
    if ((*(Obj_28b4d0 *volatile *)&this->f_0c) == 0) {
        thunk_0008d340((*(int * *)&this->f_14));
        (*(int * *)&this->f_14) = 0;
        return;
    }
    Obj_28b4d0* p = (*(Obj_28b4d0 *volatile *)&this->f_0c);
    if (p) {
        p->f1();
        (*(Obj_28b4d0 *volatile *)&this->f_0c) = 0;
    }
    (*(int * *)&this->f_14) = 0;
}


// 0x0028b520 pure3d::Float1Channel::vfunc_1 (72 B): matches/0x0028b520.cpp
// sym: ?vfunc_1@Float1Channel@pure3d@@UAEXXZ
// Same code shape as 0x0028b4d0 (propagated; names are from that function)
void pure3d::Float1Channel::vfunc_1() {
    if ((*(Obj_28b520 *volatile *)&this->f_0c) == 0)
        thunk_0008d340((*(int * *)&this->f_18));
    (*(int * *)&this->f_18) = 0;
    if ((*(Obj_28b520 *volatile *)&this->f_0c) == 0) {
        thunk_0008d340((*(int * *)&this->f_14));
        (*(int * *)&this->f_14) = 0;
        return;
    }
    Obj_28b520* p = (*(Obj_28b520 *volatile *)&this->f_0c);
    if (p) {
        p->f1();
        (*(Obj_28b520 *volatile *)&this->f_0c) = 0;
    }
    (*(int * *)&this->f_14) = 0;
}


// 0x0028b570 pure3d::Float2Channel::vfunc_1 (72 B): matches/0x0028b570.cpp
// sym: ?vfunc_1@Float2Channel@pure3d@@UAEXXZ
// Same code shape as 0x0028b4d0 (propagated; names are from that function)
void pure3d::Float2Channel::vfunc_1() {
    if ((*(Obj_28b570 *volatile *)&this->f_0c) == 0)
        thunk_0008d340((*(int * *)&this->f_18));
    (*(int * *)&this->f_18) = 0;
    if ((*(Obj_28b570 *volatile *)&this->f_0c) == 0) {
        thunk_0008d340((*(int * *)&this->f_14));
        (*(int * *)&this->f_14) = 0;
        return;
    }
    Obj_28b570* p = (*(Obj_28b570 *volatile *)&this->f_0c);
    if (p) {
        p->f1();
        (*(Obj_28b570 *volatile *)&this->f_0c) = 0;
    }
    (*(int * *)&this->f_14) = 0;
}


// 0x0028b5c0 pure3d::Vector1DOFChannel::vfunc_1 (72 B): matches/0x0028b5c0.cpp
// sym: ?vfunc_1@Vector1DOFChannel@pure3d@@UAEXXZ
void pure3d::Vector1DOFChannel::vfunc_1() {
    if ((*(volatile int *)&this->f_0c) == 0)
        thunk((*(void * *)&this->f_28));
    (*(void * *)&this->f_28) = 0;
    if ((*(volatile int *)&this->f_0c) == 0) {
        thunk((*(void * *)&this->f_14));
        (*(void * *)&this->f_14) = 0;
        return;
    }
    Ref_28b5c0* p = (Ref_28b5c0*)(*(volatile hulk_intptr *)&this->f_0c);
    if (p != 0) {
        p->Release();
        (*(volatile int *)&this->f_0c) = 0;
    }
    (*(void * *)&this->f_14) = 0;
}


// 0x0028b610 pure3d::Vector2DOFChannel::vfunc_1 (72 B): matches/0x0028b610.cpp
// sym: ?vfunc_1@Vector2DOFChannel@pure3d@@UAEXXZ
// Same code shape as 0x0028b5c0 (propagated; names are from that function)
void pure3d::Vector2DOFChannel::vfunc_1() {
    if ((*(volatile int *)&this->f_0c) == 0)
        thunk((*(void * *)&this->f_28));
    (*(void * *)&this->f_28) = 0;
    if ((*(volatile int *)&this->f_0c) == 0) {
        thunk((*(void * *)&this->f_14));
        (*(void * *)&this->f_14) = 0;
        return;
    }
    Ref_28b610* p = (Ref_28b610*)(*(volatile hulk_intptr *)&this->f_0c);
    if (p != 0) {
        p->Release();
        (*(volatile int *)&this->f_0c) = 0;
    }
    (*(void * *)&this->f_14) = 0;
}


// 0x0028b660 pure3d::Vector3DOFChannel::vfunc_1 (72 B): matches/0x0028b660.cpp
// sym: ?vfunc_1@Vector3DOFChannel@pure3d@@UAEXXZ
// Same code shape as 0x0028b4d0 (propagated; names are from that function)
void pure3d::Vector3DOFChannel::vfunc_1() {
    if ((*(Obj_28b660 *volatile *)&this->f_0c) == 0)
        thunk_0008d340((*(int * *)&this->f_18));
    (*(int * *)&this->f_18) = 0;
    if ((*(Obj_28b660 *volatile *)&this->f_0c) == 0) {
        thunk_0008d340((*(int * *)&this->f_14));
        (*(int * *)&this->f_14) = 0;
        return;
    }
    Obj_28b660* p = (*(Obj_28b660 *volatile *)&this->f_0c);
    if (p) {
        p->f1();
        (*(Obj_28b660 *volatile *)&this->f_0c) = 0;
    }
    (*(int * *)&this->f_14) = 0;
}


// 0x0028b6b0 pure3d::QuaternionChannel::vfunc_1 (72 B): matches/0x0028b6b0.cpp
// sym: ?vfunc_1@QuaternionChannel@pure3d@@UAEXXZ
// Same code shape as 0x0028b4d0 (propagated; names are from that function)
void pure3d::QuaternionChannel::vfunc_1() {
    if ((*(Obj_28b6b0 *volatile *)&this->f_0c) == 0)
        thunk_0008d340((*(int * *)&this->f_18));
    (*(int * *)&this->f_18) = 0;
    if ((*(Obj_28b6b0 *volatile *)&this->f_0c) == 0) {
        thunk_0008d340((*(int * *)&this->f_14));
        (*(int * *)&this->f_14) = 0;
        return;
    }
    Obj_28b6b0* p = (*(Obj_28b6b0 *volatile *)&this->f_0c);
    if (p) {
        p->f1();
        (*(Obj_28b6b0 *volatile *)&this->f_0c) = 0;
    }
    (*(int * *)&this->f_14) = 0;
}


// 0x0028b760 pure3d::StringChannel::vfunc_1 (110 B): matches/0x0028b760.cpp
// sym: ?vfunc_1@StringChannel@pure3d@@UAEXXZ
void pure3d::StringChannel::vfunc_1() {
    if ((*(Ref_28b760 *volatile *)&this->f_0c) == 0 && (*(Elem_28b760 * *)&this->f_18) != 0) {
        int* base = (int*)(*(Elem_28b760 * *)&this->f_18) - 1;
        int n = *base;
        Elem_28b760* e = (*(Elem_28b760 * *)&this->f_18) + n;
        n--;
        if (n >= 0) {
            int c = n + 1;
            do {
                e--;
                e->~Elem_28b760();
                c--;
            } while (c != 0);
        }
        operator delete(base);
    }
    (*(Elem_28b760 * *)&this->f_18) = 0;
    if ((*(Ref_28b760 *volatile *)&this->f_0c) == 0) {
        operator delete((*(void * *)&this->f_14));
        (*(void * *)&this->f_14) = 0;
    } else {
        Ref_28b760* r = (*(Ref_28b760 *volatile *)&this->f_0c);
        if (r != 0) {
            r->v1();
            (*(Ref_28b760 *volatile *)&this->f_0c) = 0;
        }
        (*(void * *)&this->f_14) = 0;
    }
}


// 0x0028b7d0 pure3d::EntityChannel::vfunc_1 (112 B): matches/0x0028b7d0.cpp
// sym: ?vfunc_1@EntityChannel@pure3d@@UAEXXZ
void pure3d::EntityChannel::vfunc_1() {
    for (unsigned i = 0; i < this->f_10; i++) {
        Obj_28b7d0** slot = (*(Obj_28b7d0 ** *)&this->f_18) + i;
        Obj_28b7d0* o = *slot;
        if (o) {
            o->Release();
            *slot = 0;
        }
    }
    if ((*(Obj_28b7d0 * *)&this->f_0c) == 0)
        Free_0008d340((*(Obj_28b7d0 ** *)&this->f_18));
    (*(Obj_28b7d0 ** *)&this->f_18) = 0;
    if ((*(Obj_28b7d0 * *)&this->f_0c) == 0) {
        Free_0008d340((*(void * *)&this->f_14));
        (*(void * *)&this->f_14) = 0;
    } else {
        Del((*(Obj_28b7d0 * *)&this->f_0c));
        (*(void * *)&this->f_14) = 0;
    }
}

namespace fn_f66a22d3 {

// 0x0028b840 pure3d::BoolChannel::vfunc_1 (72 B): matches/0x0028b840.cpp
// sym: ?vfunc_1@BoolChannel_28b840@fn_f66a22d3@@QAEXXZ
// Same code shape as 0x0028b4d0 (propagated; names are from that function)
void BoolChannel_28b840::vfunc_1() {
    if (mObj == 0)
        thunk_0008d340(m18);
    m18 = 0;
    if (mObj == 0) {
        thunk_0008d340(m14);
        m14 = 0;
        return;
    }
    Obj_28b840* p = mObj;
    if (p) {
        p->f1();
        mObj = 0;
    }
    m14 = 0;
}

} // namespace fn_f66a22d3

// 0x0028b890 pure3d::ColourChannel::vfunc_1 (72 B): matches/0x0028b890.cpp
// sym: ?vfunc_1@ColourChannel@pure3d@@UAEXXZ
// Same code shape as 0x0028b4d0 (propagated; names are from that function)
void pure3d::ColourChannel::vfunc_1() {
    if ((*(Obj_28b890 *volatile *)&this->f_0c) == 0)
        thunk_0008d340((*(int * *)&this->f_18));
    (*(int * *)&this->f_18) = 0;
    if ((*(Obj_28b890 *volatile *)&this->f_0c) == 0) {
        thunk_0008d340((*(int * *)&this->f_14));
        (*(int * *)&this->f_14) = 0;
        return;
    }
    Obj_28b890* p = (*(Obj_28b890 *volatile *)&this->f_0c);
    if (p) {
        p->f1();
        (*(Obj_28b890 *volatile *)&this->f_0c) = 0;
    }
    (*(int * *)&this->f_14) = 0;
}

