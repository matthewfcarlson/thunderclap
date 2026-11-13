// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00222460..0x002248a0 (kind game, layer engine, confidence high), dominant class choreo2::Puppet
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/choreo2.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe86d092 {
#define TREE_TU_END }
namespace fn_fe86d092 {} using namespace fn_fe86d092;
#include "engine/choreo2.h"

// ---- declarations shared by the functions below
namespace fn_fe86d092 {
class Ref_222460 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_222460 {
  public:
    char pad[0x10];
    Ref_222460* mRef;
    int a;
    int b;
    int c;
    Obj_222460* Copy(Obj_222460* src);
};
struct BitSet_2224a0 {
    unsigned int count;
    unsigned int words[1];
};
struct BitSource {
    char pad00[0x10];
    BitSet_2224a0 *bits;            // 0x10
    unsigned int total;      // not used here
};
class BitRange {
public:
    char pad00[0x10];
    BitSource *owner;        // 0x10
    BitSource *source;       // 0x14
    unsigned int first;      // 0x18
    unsigned int last;       // 0x1c
    void FUN_002224a0(BitSource *src);
};
class Inner_222550 {
  public:
    char pad[16];
    int value;
    int make_0027b670(int, int);
};
class Base_222550 {
  public:
    char pad[16];
    Inner_222550* inner;
    int a, b, c;
    void f(int, int);
    void helper_002224a0(int);
};
class Obj_222590 {
  public:
    virtual void A();
    virtual void B();
};
class Driver_222590 {
  public:
    virtual void Init();
    char pad[12];
    Driver_222590();
};
class PartitionDriver : public Driver_222590 {
  public:
    PartitionDriver(const PartitionDriver* src);
    virtual void Init();
    Obj_222590* mObj;
    int a;
    int b;
    int c;
};
extern "C" char DAT_004272b8[];
typedef unsigned int u32_222620;
struct Arg_222620 {
    virtual void F();
};
struct Sub_222620 {
    char x[4];
    void Init_00222050();
};
struct Puppet_nv_222620 {
    void BaseInit_0027b070();
};
class Target_2226b0 {
  public:
    char pad[0x64];
    struct Inner {
        char pad[8];
        int value;
    }* member;
};
class Inner_2226e0 {
  public:
    void call_00221c60(int);
};
class Obj_2226e0 {
  public:
    char pad[0x10];
    void target(hulk_intptr);
};
class Inner_2226f0 {
  public:
};
class Obj_2226f0 {
  public:
    char pad[0x10];
    void target(hulk_intptr);
};
class Inner_222700 {
  public:
    void call_00221d20(int);
};
class Obj_222700 {
  public:
    char pad[0x10];
    void target(int);
};
class Inner_222710 {
  public:
    void call_00222180(int);
};
class Obj_222710 {
  public:
    char pad[0x10];
    void target(hulk_intptr);
};
class Inner_222720 {
  public:
    void call_00221cf0(int);
};
class Obj_222720 {
  public:
    char pad[0x10];
    void target(hulk_intptr);
};
struct Resource_2227d0 {
 virtual void AddRef();
 virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6();
 virtual unsigned GetFirst();
 virtual unsigned GetSecond();
};
struct Entry_2227d0 {
 Resource_2227d0* resource;
 float value;
 bool negative;
 char padding[3];
 unsigned first, second, parameter;
 float clamped;
 unsigned arg5, arg6, zero;
};
struct Owner_2227d0 {
 char padding[0x68];
 unsigned count;
 Entry_2227d0 entries[16];
 bool changed;
 bool FUN_002227d0(Resource_2227d0* resource, float value, unsigned parameter, float clamped, unsigned arg5, unsigned arg6);
};
struct Item_222890 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
 virtual unsigned int v7(); virtual unsigned int v8();
};
struct Entry_222890 {
 Item_222890* item;
 float value;
 bool negative;
 char pad[3];
 unsigned int first;
 unsigned int second;
 unsigned int arg3;
 float arg4;
 unsigned int arg5;
 unsigned int arg6;
 float arg7;
};
struct Owner_222890 {
 char pad[0x68];
 unsigned int count;
 Entry_222890 entries[16];
 bool dirty;
 bool FUN_002227d0(Item_222890*, float, unsigned int, float, unsigned int, unsigned int);
 bool FUN_00222890(Item_222890*, float, unsigned int, float, unsigned int, unsigned int, float);
};
} // namespace fn_fe86d092
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memmove(void *, const void *, unsigned int);
#endif
namespace fn_fe86d092 {
class Handler_222970 {
public:
    virtual void v0();
    virtual void Release();      // slot 1
};
struct Slot_222970 {
    Handler_222970 *handler;        // 0x00
    float time;              // 0x04
    char active;             // 0x08
    char pad09[0x1f];
};
class SlotList_222970 {
public:
    char pad00[0x68];
    unsigned int count;      // 0x68
    Slot_222970 slots[1];           // 0x6c
    bool FUN_00222970(Handler_222970 *handler, bool remove);
};
class EntryOwner {
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
    virtual int f13();
};
struct Item_222a00 {
    char pad[4];
    float value;
    unsigned char enabled;
};
class Container_222a00 {
  public:
    char pad[0x68];
    unsigned count;
    Item_222a00 entries[1];
    unsigned char Check(EntryOwner* item);
};
class C_222b50 {
  public:
    char pad[0x68];
    unsigned count;
    struct Entry {
        int key;
        int value;
        unsigned char flag;
        char pad[0x1f];
    } entries[1];
    bool f(int key, unsigned char flag, int value);
};
struct Item_222b90 {
    void* pad;
    float val;
    char flag;
    char rest[31];
};
class Obj_222b90 {
    char pad[0x68];
    int count;
    Item_222b90 items[1];

  public:
    void Clear(char b);
};
class Ref_222b90 {
  public:
    virtual void a();
    virtual void release();
};
struct Entry_222da0 {
    int key;
    char pad[0x20];
    float value;
};
class Obj_222da0 {
  public:
    char pad[0x68];
    unsigned count;
    Entry_222da0 entries[1];
    float target(hulk_intptr key);
};
class Item_222ee0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual bool Check();
};
struct Entry_222ee0 {
    Item_222ee0* obj;
    float value;
    char flag;
    char pad[31];
};
class Owner_222ee0 {
  public:
    char pad[0x68];
    unsigned count;
    Entry_222ee0 entries[1];
    hulk_intptr target(int index);
};
struct Effect_222f40 {
 virtual void slot0();
 virtual void release();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void update(float);
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual bool finished();
};
struct Entry_222f40 {
 Effect_222f40* effect;
 float delay;
 unsigned char flag;
 char padding[19];
 float fadeIn;
 float fadeOut;
 float weight;
};
struct Manager_222f40 {
 char padding[0x68];
 unsigned int count;
 Entry_222f40 entries[1];
 void FUN_00222f40(float dt);
};
class A_223060 {
  public:
    int Fnf_00221c40();
};
class B_223060 {
  public:
};
class C_223060 {
  public:
    char pad[0x10];
    A_223060 a;
    void f();
};
struct Entry_223110 {
    int f0, f4, f8;
    unsigned int f0c;
    unsigned int f10;
    int f14;
    int rest[4];
};
struct Item_223190 { unsigned int words[10]; };
struct Ref_2232d0 {
 virtual void AddRef();
 virtual void Release();
 virtual void Slot2();
 virtual void Slot3();
 virtual void Slot4();
 virtual Ref_2232d0* Clone();
};
struct BasePart_2232d0 { char data[0x54]; void FUN_00221be0(BasePart_2232d0*); };
struct Entry_2232d0 { Ref_2232d0* object; unsigned value; unsigned char flag; char pad[3]; unsigned a,b,c,d,e,f,g; };
struct Puppet_2232d0 {
 char prefix[0x10]; BasePart_2232d0 base; Ref_2232d0* ref; unsigned count; Entry_2232d0 entries[1];
 Puppet_2232d0* assign(Puppet_2232d0* source);
};
struct Item_2233e0 {
 unsigned int data[3];
 unsigned int key;
 unsigned int secondary;
 int priority;
 unsigned int tail[4];
};
struct Sub_2235f0 {
    char pad[0x54];
    void init_00222050();
};
struct Puppet {
    void* vt;
    char pad[0xc];
    Sub_2235f0 sub;
    int a, b;
    void baseInit_0027b070();
    void finish_002232d0(int);
    Puppet* ctor(int arg);
};
struct Elem40 { char data[40]; };
void __cdecl FUN_002233e0(Elem40 *a, Elem40 *b, Elem40 *c);
struct Elem_223760 {
    int w[10];
};
void __cdecl FUN_002234d0(Elem_223760 *first, hulk_intptr index, hulk_intptr count, Elem_223760 value);
struct Elem_223800 {
    int w[10];
};
void __cdecl FUN_002234d0(Elem_223800 *first, int index, hulk_intptr count, Elem_223800 value);
struct Item_223c20 {
 char pad[12];
 unsigned int key;
 unsigned int secondary;
 int priority;
 char tail[16];
};
extern void __cdecl FUN_00223190(Item_223c20*, Item_223c20*, Item_223c20*, int, int);
struct Elem_223d20 {
    int w[10];
};
void __cdecl FUN_002234d0(Elem_223d20 *first, int index, hulk_intptr count, Elem_223d20 value);
struct Record_223dc0 { char data[40]; };
struct Partition { Record_223dc0* first; Record_223dc0* second; };
extern void __cdecl FUN_00223870(Partition*, Record_223dc0*, Record_223dc0*);
extern "C" void __cdecl FUN_00223c20(void *, void *);
extern void __cdecl FUN_00223760(Record_223dc0*, Record_223dc0*, int, int);
extern "C" void __cdecl FUN_00223d20(void *, void *);
class Obj_223f50 {
  public:
    char pad0[0x68];
    int count;
    char pad1[0x280];
    unsigned char dirty;
};
extern "C" void __cdecl Move_00223dc0(void*, void*, int);
struct Matrix {
    float m[16];
};
struct Pose {
    Matrix matrix;
    char extra[0x14];
    Pose() {}
    void FUN_00221b30(Pose *src);
    void FUN_00221ee0();
};
struct Target_223fa0 {
    char pad0[0x20];
    char b20;
    char b21;
    char b22;
    char b23;
};
struct Layer_223fa0 {
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
    virtual void Apply(Pose *out, Pose *xform, Target_223fa0 *target, float weight);
};
struct Elem_223fa0 {
    Layer_223fa0 *layer;
    char pad4[0x10];
    int key;        // 0x14
    float factor;   // 0x18
    char pad1c[8];
    float weight;   // 0x24
};
void __cdecl FUN_00223dc0(Elem_223fa0 *first, Elem_223fa0 *last, int depth);
class Blender_223fa0 {
public:
    char pad0[0x10];
    Pose xform;         // 0x10
    Target_223fa0 *target;     // 0x64
    unsigned int count; // 0x68
    Elem_223fa0 elems[16];     // 0x6c
    bool dirty;         // 0x2ec
    void FUN_00223fa0();
};
struct Sink_224260;
struct Target_224260 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual bool v11(int a, int b, Sink_224260 *c, float amount);
};
struct Sink_224260 {
    void FUN_00221ee0();
};
struct Entry_224260 {
    Target_224260 *target;         // 0x00
    char pad04[0x14 - 0x4];
    int key;                // 0x14
    float f18;              // 0x18
    char pad1c[0x24 - 0x1c];
    float w;                // 0x24
};
extern void __cdecl FUN_00223dc0(Entry_224260 *first, Entry_224260 *last, hulk_intptr count);
struct Mixer {
    char pad0[0x68];
    unsigned count;                         // 0x68
    Entry_224260 e[16];                            // 0x6c
    char dirty;                             // 0x2ec
    bool FUN_00224260(int a, int b, Sink_224260 *sink);
};
struct Layer_224540 {
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
    virtual void v11();
    virtual bool v12(unsigned ctx, float *out);
};
struct Entry_224540 {
    Layer_224540 *layer;
    char pad0[0x10];
    unsigned key;
    float a;
    char pad1[8];
    float b;
};
struct Frame_224540 {
    char pad[3];
    bool changed;       // 0x13
    float f14;          // weight of the finished group / out value of the final layer
    float f18;          // out value / final weight
    float sum;          // 0x1c
    unsigned start;     // 0x20
    float w2;           // 0x24
    unsigned i;         // 0x28
    unsigned t2c;
    unsigned k;         // 0x30
    unsigned key0;      // 0x34
};
class Blend_224540 {
public:
    char pad[0x68];
    unsigned count;
    Entry_224540 e[1];

    void FUN_00223f50();
    bool FUN_00224540(hulk_uintptr ctx, float *out);
};


// 0x00222460 FUN_00222460 (63 B): matches/0x00222460.cpp
// sym: ?Copy@Obj_222460@fn_fe86d092@@QAEPAV12@PAV12@@Z
Obj_222460* Obj_222460::Copy(Obj_222460* src) {
    Ref_222460* p = src->mRef;
    if (p)
        p->A();
    if (mRef)
        mRef->B();
    mRef = p;
    a = src->a;
    b = src->b;
    c = src->c;
    return this;
}


// 0x002224a0 FUN_002224a0 (142 B): matches/0x002224a0.cpp
// sym: ?FUN_002224a0@BitRange@fn_fe86d092@@QAEXPAUBitSource@2@@Z
// FUN_002224a0 @ 0x002224a0
// Finds the first and last set bits of the source's bit set.
void BitRange::FUN_002224a0(BitSource *src) {
    if (src == 0) {
        source = 0;
        first = 0;
        last = *(unsigned int *)((char *)owner + 0x10) - 1;
        return;
    }
    source = src;
    BitSet_2224a0 *b = src->bits;
    unsigned int count = b->count;
    for (unsigned int i = 0; i < count; i++) {
        if (b->words[i >> 5] & (1u << (i & 31))) {
            first = i;
            break;
        }
    }
    for (unsigned int i = count - 1; i >= first; i--) {
        if (b->words[i >> 5] & (1u << (i & 31))) {
            last = i;
            break;
        }
    }
}


// 0x00222550 FUN_00222550 (61 B): matches/0x00222550.cpp
// sym: ?f@Base_222550@fn_fe86d092@@QAEXHH@Z
void Base_222550::f(int x, int y) {
    if ((x | y) == 0) {
        a = 0;
        b = 0;
        c = inner->value - 1;
    } else {
        int z = inner->make_0027b670(x, y);
        helper_002224a0(z);
    }
}


// 0x00222590 FUN_00222590 (81 B): matches/0x00222590.cpp
// sym: ??0PartitionDriver@fn_fe86d092@@QAE@PBV01@@Z
PartitionDriver::PartitionDriver(const PartitionDriver* src) : Driver_222590() {
    mObj = 0;
    Obj_222590* p = src->mObj;
    if (p)
        p->A();
    if (mObj)
        mObj->B();
    mObj = p;
    a = src->a;
    b = src->b;
    c = src->c;
}

} // namespace fn_fe86d092

// 0x00222620 FUN_00222620 (50 B): matches/0x00222620.cpp
// sym: ?FUN_00222620@Puppet@choreo2@@QAEPAV12@PAX@Z
choreo2::Puppet* choreo2::Puppet::FUN_00222620(void* __p0) { Arg_222620 * param = (Arg_222620 *)__p0;

    ((Puppet_nv_222620*)this)->BaseInit_0027b070();
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_004272b8);
    ((Sub_222620*)((char*)this + 0x10))->Init_00222050();
    *(u32_222620*)((char*)&this->f_68) = 0;
    *(u8*)((char*)this + 0x2ec) = 0;
    *(Arg_222620**)((char*)this + 0x64) = param;
    param->F();
    return (choreo2::Puppet*)(this);
}


// 0x00222660 FUN_00222660 (63 B): matches/0x00222660.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ??1Puppet@fn_00222660@@QAE@XZ
namespace fn_00222660 {
class Ref_222660 {
  public:
    virtual void f0();
    virtual void Release();
};
class Puppet {
  public:
    virtual void f0();
    virtual void f1();
    char pad[0x60];
    Ref_222660* m64;
    int count;
    struct Entry {
        Ref_222660* ref;
        char pad[36];
    } items[1];
    void Tail_0027afd0();
    ~Puppet();
};
void Puppet::f0() {}
void Puppet::f1() {}
Puppet::~Puppet() {
    int n = count - 1;
    if (n >= 0) {
        Entry* p = items + n;
        int k = n + 1;
        do {
            p->ref->Release();
            --p;
            --k;
        } while (k != 0);
    }
    m64->Release();
    Tail_0027afd0();
}
} // namespace fn_00222660


// 0x002226a0 choreo2::Puppet::vfunc_3 (3 B): matches/0x002226a0.cpp
// sym: ?vfunc_3@Puppet@choreo2@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool choreo2::Puppet::vfunc_3() {
    return true;
}

namespace fn_fe86d092 {

// 0x002226b0 FUN_002226b0 (7 B): matches/0x002226b0.cpp
// sym: ?FUN_002226b0@fn_fe86d092@@YIHPAVTarget_2226b0@1@@Z
hulk_intptr __fastcall FUN_002226b0(Target_2226b0* self) {
    return self->member->value;
}


// 0x002226e0 FUN_002226e0 (8 B): matches/0x002226e0.cpp
// sym: ?target@Obj_2226e0@fn_fe86d092@@QAEXH@Z
void Obj_2226e0::target(hulk_intptr a0) {
    ((Inner_2226e0*)((char*)this + 0x10))->call_00221c60(a0);
}


// 0x002226f0 FUN_002226f0 (8 B): matches/0x002226f0.cpp
// sym: ?target@Obj_2226f0@fn_fe86d092@@QAEXH@Z
// Same code shape as 0x002226e0 (propagated; names are from that function)
void Obj_2226f0::target(hulk_intptr a0) {
    ((owners::Target_22be40 *)(((Inner_2226f0*)((char*)this + 0x10))))->FUN_0022be40((const int *)(hulk_uintptr)(int)a0);
}


// 0x00222700 FUN_00222700 (8 B): matches/0x00222700.cpp
// sym: ?target@Obj_222700@fn_fe86d092@@QAEXH@Z
// Same code shape as 0x002226e0 (propagated; names are from that function)
void Obj_222700::target(int a0) {
    ((Inner_222700*)((char*)this + 0x10))->call_00221d20(a0);
}


// 0x00222710 FUN_00222710 (8 B): matches/0x00222710.cpp
// sym: ?target@Obj_222710@fn_fe86d092@@QAEXH@Z
// Same code shape as 0x002226e0 (propagated; names are from that function)
void Obj_222710::target(hulk_intptr a0) {
    ((Inner_222710*)((char*)this + 0x10))->call_00222180(a0);
}


// 0x00222720 FUN_00222720 (8 B): matches/0x00222720.cpp
// sym: ?target@Obj_222720@fn_fe86d092@@QAEXH@Z
// Same code shape as 0x002226e0 (propagated; names are from that function)
void Obj_222720::target(hulk_intptr a0) {
    ((Inner_222720*)((char*)this + 0x10))->call_00221cf0(a0);
}


// 0x002227d0 FUN_002227d0 (177 B): equivalent/0x002227d0.cpp
// sym: ?FUN_002227d0@Owner_2227d0@fn_fe86d092@@QAE_NPAUResource_2227d0@2@MIMII@Z @5a06cb36b068 @wab28bac08e28
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002227d0 @ 0x002227d0
bool Owner_2227d0::FUN_002227d0(Resource_2227d0* resource, float value, unsigned parameter, float clamped, unsigned arg5, unsigned arg6) {
 if(count >= 16) return false;
 Entry_2227d0& entry = entries[count];
 entry.resource = resource;
 resource->AddRef();
 entry.value = value;
 entry.negative = value < 0.0f;
 entry.first = resource->GetFirst();
 entry.second = resource->GetSecond();
 entry.parameter = parameter;
 entry.clamped = clamped < 0.0f ? 0.0f : clamped;
 entry.arg5 = arg5;
 entry.arg6 = arg6;
 entry.zero = 0;
 ++count;
 changed = true;
 return true;
}


// 0x00222890 FUN_00222890 (224 B): equivalent/0x00222890.cpp
// sym: ?FUN_00222890@Owner_222890@fn_fe86d092@@QAE_NPAUItem_222890@2@MIMIIM@Z @d66ed735d343 @wb36a4a07369d
// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 12/12)
// FUN_00222890 @ 0x00222890
bool Owner_222890::FUN_00222890(Item_222890* item, float value, unsigned int a3, float a4, unsigned int a5, unsigned int a6, float a7) {
 for (unsigned int i=0; i<count; ++i) {
  Entry_222890& entry=entries[i];
  if (entry.item != item) continue;
  entry.value=value;
  entry.negative=value < 0.0f;
  entry.first=item->v7();
  entry.second=item->v8();
  entry.arg3=a3;
  entry.arg4=a4 < 0.0f ? 0.0f : a4;
  entry.arg5=a5;
  entry.arg6=a6;
  if (a7 >= 0.0f) entry.arg7=a7;
  dirty=true;
  return true;
 }
 return FUN_002227d0(item,value,a3,a4,a5,a6);
}


// 0x00222970 FUN_00222970 (143 B): equivalent/0x00222970.cpp
// sym: ?FUN_00222970@SlotList_222970@fn_fe86d092@@QAE_NPAVHandler_222970@2@_N@Z @0e49b17e197b @wfab4b5ae05ed
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00222970 @ 0x00222970
// Finds the slot of a handler; either removes it, or marks it inactive.
bool SlotList_222970::FUN_00222970(Handler_222970 *handler, bool remove) {
    unsigned int i = 0;
    Slot_222970 *slot = slots;
    for (; i < count; i++, slot++) {
        if (slot->handler == handler)
            break;
    }
    if (i >= count)
        return false;
    if (remove) {
        handler->Release();
        hulk_intptr index = slot - slots;
        count--;
        memmove(&slots[index], &slots[index + 1], (count - index) * sizeof(Slot_222970));
        return true;
    }
    slot->time = -1.0f;
    slot->active = 0;
    return true;
}


// 0x00222a00 FUN_00222a00 (67 B): matches/0x00222a00.cpp
// sym: ?Check@Container_222a00@fn_fe86d092@@QAEEPAVEntryOwner@2@@Z
// data: zero_222a00 = DAT_003f32e0
unsigned char Container_222a00::Check(EntryOwner* item) {
    unsigned i = 0;
    while (i < count) {
        Item_222a00* e = (Item_222a00*)((char*)this + 0x6c + i * 0x28);
        if (*(EntryOwner**)e == item) {
            if (!(e->value < DAT_003f32e0) || e->enabled)
                return (unsigned char)item->f13();
            break;
        }
        ++i;
    }
    return 1;
}


// 0x00222b50 FUN_00222b50 (55 B): matches/0x00222b50.cpp
// sym: ?f@C_222b50@fn_fe86d092@@QAE_NHEH@Z
bool C_222b50::f(int key, unsigned char flag, int value) {
    for (unsigned i = 0; i < count; ++i) {
        Entry* e = (Entry*)((char*)this + 0x6c + i * 0x28);
        if (e->key == key) {
            e->flag = flag;
            e->value = value;
            return true;
        }
    }
    return false;
}


// 0x00222b90 FUN_00222b90 (96 B): matches/0x00222b90.cpp
// sym: ?Clear@Obj_222b90@fn_fe86d092@@QAEXD@Z
void Obj_222b90::Clear(char b) {
    if (b) {
        for (int i = count - 1; i >= 0; --i)
            ((Ref_222b90*)items[i].pad)->release();
        count = 0;
    } else {
        for (int i = count - 1; i >= 0; --i) {
            items[i].val = -1.0f;
            items[i].flag = 0;
        }
    }
}

} // namespace fn_fe86d092

// 0x00222bf0 FUN_00222bf0 (42 B): matches/0x00222bf0.cpp
// sym: ?FUN_00222bf0@A_222bf0@owners@@QAEHH@Z
int owners::A_222bf0::FUN_00222bf0(hulk_intptr key) {
    unsigned n = count;
    unsigned i = 0;
    if (n > 0) {
        int k = ((int)key);
        int* p = (int*)((char*)this + 0x6c);
        do {
            if (*p == k)
                return p[5];
            ++i;
            p += 10;
        } while (i < n);
    }
    return 0;
}


// 0x00222d70 FUN_00222d70 (48 B): matches/0x00222d70.cpp
// sym: ?FUN_00222d70@Obj_222d70@owners@@QAE_NHH@Z
bool owners::Obj_222d70::FUN_00222d70(hulk_intptr key, int value) {
    unsigned i = 0;
    while (i < count) {
        int* p = (int*)((char*)this + 0x6c + i * 0x28);
        if (*p == ((int)key)) {
            p[8] = value;
            return true;
        }
        ++i;
    }
    return false;
}

namespace fn_fe86d092 {

// 0x00222da0 FUN_00222da0 (46 B): matches/0x00222da0.cpp
// sym: ?target@Obj_222da0@fn_fe86d092@@QAEMH@Z
// data: gZero_222da0 = DAT_003f32e0
float Obj_222da0::target(hulk_intptr key) {
    unsigned n = count;
    unsigned i = 0;
    if (n > 0) {
        Entry_222da0* p = (Entry_222da0*)((char*)this + 0x6c);
        do {
            if (p->key == key)
                return p->value;
            ++i;
            p = (Entry_222da0*)((char*)p + 0x28);
        } while (i < n);
    }
    return DAT_003f32e0;
}

} // namespace fn_fe86d092

// 0x00222e20 FUN_00222e20 (24 B): matches/0x00222e20.cpp
// sym: ?FUN_00222e20@C_222e20@owners@@QAEII@Z
hulk_uintptr owners::C_222e20::FUN_00222e20(unsigned i) {
    if (i < count)
        return *(unsigned*)(rest + i * 0x28);
    return 0;
}

namespace fn_fe86d092 {

// 0x00222ee0 FUN_00222ee0 (90 B): matches/0x00222ee0.cpp
// sym: ?target@Owner_222ee0@fn_fe86d092@@QAEHH@Z
// data: zeroValue_222ee0 = DAT_003f32e0
hulk_intptr Owner_222ee0::target(int index) {
    int found = 0;
    for (unsigned i = 0; i < count; ++i) {
        Entry_222ee0* e = &entries[i];
        if (!e->obj->Check() && (e->value >= DAT_003f32e0 || e->flag)) {
            if (index == found)
                return (hulk_intptr)e->obj;
            ++found;
        }
    }
    return 0;
}


// 0x00222f40 FUN_00222f40 (286 B): equivalent/0x00222f40.cpp
// sym: ?FUN_00222f40@Manager_222f40@fn_fe86d092@@QAEXM@Z @4479af794401 @wd4f0e2fb4911
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 20/20)
// FUN_00222f40 @ 0x00222f40
void Manager_222f40::FUN_00222f40(float dt) {
 unsigned int i=0;
 while(i<count) {
  Entry_222f40& e=entries[i];
  Effect_222f40* effect=e.effect;
  if ((e.delay<0.0f && !e.flag) || effect->finished()) {
   if(e.fadeOut<=0.0f) e.weight=0.0f;
   else e.weight=e.weight-dt/e.fadeOut;
   if(e.weight<=0.0f) {
    effect->release();
    --count;
    memmove(&e,&entries[i+1],(count-i)*sizeof(Entry_222f40));
    continue;
   }
  } else {
   if(!e.flag) e.delay-=dt;
   if(e.fadeIn<=0.0f) e.weight=1.0f;
   else {
    double value=(double)dt/e.fadeIn+e.weight;
    e.weight=(float)value;
    if(value>1.0) e.weight=1.0f;
   }
  }
  effect->update(dt);
  ++i;
 }
}


// 0x00223060 FUN_00223060 (22 B): matches/0x00223060.cpp
// sym: ?f@C_223060@fn_fe86d092@@QAEXXZ
void C_223060::f() {
    int x = a.Fnf_00221c40();
    ((owners::C_284820 *)(((B_223060*)*(void**)((char*)this + 0x64))))->FUN_00284820((hulk_intptr)x);
}


// 0x00223110 FUN_00223110 (120 B): equivalent/0x00223110.cpp
// sym: ?FUN_00223110@fn_fe86d092@@YAXPAUEntry_223110@1@HHU21@@Z @611fe2b1af1c @w4d2c4036a506
// STATUS: equivalent (tools/equiv.py level 3: 625 inputs, branch coverage 14/14)
// FUN_00223110 @ 0x00223110
// Sift-up of one element into a binary heap.
void FUN_00223110(Entry_223110* heap, int index, int top, Entry_223110 item) {
    int parent = (index - 1) / 2;
    while (top < index) {
        Entry_223110* p = &heap[parent];
        if (p->f14 < item.f14)
            break;
        if (p->f14 == item.f14) {
            if (p->f0c > item.f0c)
                break;
            if (p->f0c == item.f0c && p->f10 <= item.f10)
                break;
        }
        heap[index] = *p;
        index = parent;
        parent = (index - 1) / 2;
    }
    heap[index] = item;
}


// 0x00223190 FUN_00223190 (280 B): equivalent/0x00223190.cpp
// sym: ?FUN_00223190@fn_fe86d092@@YAXPAUItem_223190@1@00@Z @ec2d12d55c90 @we3a53ef2c0d1
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 17/18, incomplete)
// FUN_00223190 @ 0x00223190
void __cdecl FUN_00223190(Item_223190* first, Item_223190* middle, Item_223190* last) {
    hulk_intptr shift = middle - first;
    hulk_intptr count = last - first;
    hulk_intptr a = count, b = shift;
    while (b != 0) { hulk_intptr r = a % b; a = b; b = r; }
    if (a >= count || a <= 0) return;
    Item_223190* start = first + a;
    for (hulk_intptr cycles = a; cycles != 0; --cycles, --start) {
        Item_223190 saved = *start;
        Item_223190* dest = start;
        Item_223190* next = start + shift;
        if (next == last) next = first;
        while (next != start) {
            *dest = *next;
            dest = next;
            hulk_intptr remaining = last - next;
            if (shift < remaining) next += shift;
            else next = first + (shift - remaining);
        }
        *dest = saved;
    }
}

} // namespace fn_fe86d092

// 0x002232b0 choreo2::Puppet::vfunc_2 (30 B): matches/0x002232b0.cpp
// sym: ??_GPuppet@choreo2@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
choreo2::Puppet::~Puppet() {}

namespace fn_fe86d092 {

// 0x002232d0 FUN_002232d0 (208 B): equivalent/0x002232d0.cpp
// sym: ?assign@Puppet_2232d0@fn_fe86d092@@QAEPAU12@PAU12@@Z @b68dcae21619 @wfc90129b529f
// STATUS: equivalent (tools/equiv.py level 3: 44 inputs, branch coverage 12/12)
// FUN_002232d0 @ 0x002232d0
Puppet_2232d0* Puppet_2232d0::assign(Puppet_2232d0* source) {
 base.FUN_00221be0(&source->base);
 Ref_2232d0* incoming=source->ref;
 if(incoming) incoming->AddRef();
 if(ref) ref->Release();
 ref=incoming;
 int last=(int)(count-1);
 if(last>=0) {
 Entry_2232d0* current=&entries[last];
 unsigned remaining=(unsigned)last+1;
 do { current->object->Release(); --current; } while(--remaining);
 }
 count=0;
 count=source->count;
 for(unsigned i=0;i<count;++i) {
 Entry_2232d0* from=&source->entries[i];
 Entry_2232d0* to=&entries[i];
 Ref_2232d0* cloned=from->object->Clone();
 to->object=cloned;
 cloned->AddRef();
 to->value=from->value;
 to->flag=from->flag;
 to->a=from->a;
 to->b=from->b;
 to->c=from->c;
 to->d=from->d;
 to->e=from->e;
 to->f=from->f;
 to->g=from->g;
 }
 return this;
}


// 0x002233e0 FUN_002233e0 (232 B): equivalent/0x002233e0.cpp
// sym: ?FUN_002233e0@fn_fe86d092@@YAPAUItem_2233e0@1@PAU21@00@Z @4772ad6f87c6 @wf3775b281d7b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// FUN_002233e0 @ 0x002233e0
Item_2233e0* __cdecl FUN_002233e0(Item_2233e0* first, Item_2233e0* second, Item_2233e0* third) {
 Item_2233e0 temp;
 if(second->priority > first->priority || (second->priority == first->priority && (second->key < first->key || (second->key == first->key && second->secondary > first->secondary)))) {
 temp = *second; *second = *first; *first = temp;
 }
 if(third->priority > second->priority || (third->priority == second->priority && (third->key < second->key || (third->key == second->key && third->secondary > second->secondary)))) {
 temp = *third; *third = *second; *second = temp;
 }
 if(second->priority > first->priority || (second->priority == first->priority && (second->key < first->key || (second->key == first->key && second->secondary > first->secondary)))) {
 temp = *second; *second = *first; *first = temp;
 }
 return second;
}

} // namespace fn_fe86d092

// 0x002234d0 FUN_002234d0 (164 B): equivalent/0x002234d0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_002234d0@fn_002234d0@@YAXPAUElem_2234d0@1@HHU21@@Z @0438815e0049 @w27ab91545c34
namespace fn_002234d0 {
// STATUS: equivalent (tools/equiv.py level 3: 2974 inputs, branch coverage 16/16)
// FUN_002234d0 @ 0x002234d0
struct Elem_2234d0 {
    int w0, w1, w2;
    unsigned int minor;     // 0x0c
    unsigned int tail;      // 0x10
    int major;              // 0x14
    int rest[4];
};

void __cdecl FUN_00223110(Elem_2234d0 *first, int hole, int top, Elem_2234d0 value);

// true when the element at idx should be replaced by its left neighbour
static bool PreferLeft(const Elem_2234d0 &cur, const Elem_2234d0 &prev)
{
    if (cur.major > prev.major)
        return true;
    if (cur.major < prev.major)
        return false;
    if (cur.minor < prev.minor)
        return true;
    if (cur.minor > prev.minor)
        return false;
    return cur.tail > prev.tail;
}

void __cdecl FUN_002234d0(Elem_2234d0 *first, int top, hulk_intptr bottom, Elem_2234d0 value)
{
    int hole = top;
    int idx = 2 * top + 2;
    while (idx < bottom) {
        if (PreferLeft(first[idx], first[idx - 1]))
            idx--;
        first[hole] = first[idx];
        hole = idx;
        idx = 2 * idx + 2;
    }
    if (idx == bottom) {
        first[hole] = first[bottom - 1];
        hole = bottom - 1;
    }
    FUN_00223110(first, hole, top, value);
}
} // namespace fn_002234d0

namespace fn_fe86d092 {

// 0x002235f0 FUN_002235f0 (48 B): matches/0x002235f0.cpp
// sym: ?ctor@Puppet@fn_fe86d092@@QAEPAU12@H@Z
Puppet* Puppet::ctor(int arg) {
    baseInit_0027b070();
    vt = (void*)((hulk_intptr)DAT_004272b8);
    sub.init_00222050();
    a = 0;
    b = 0;
    finish_002232d0(arg);
    return this;
}

} // namespace fn_fe86d092

// 0x00223670 choreo2::Puppet::vfunc_5 (76 B): matches/0x00223670.cpp [wrapped: conflict: Puppet]
// sym: ?f5@Puppet@fn_00223670@@UAEPAV12@XZ
namespace fn_00223670 {
extern "C" char DAT_004272b8[];
class Puppet;
class Aux_223670 {
  public:
    void Init_00222050();
};
class Puppet {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual Puppet* f5();
    void InitA_0027b070();
    void InitC_002232d0(Puppet*);
    char pad[0x60];
    int x;
    int y;
};
extern void* __cdecl allocThunk_00263ea0(unsigned int);
Puppet* Puppet::f5() {
    Puppet* p = (Puppet*)allocThunk_00263ea0(0x2f0);
    if (p) {
        p->InitA_0027b070();
        *((hulk_intptr*)p) = ((hulk_intptr)DAT_004272b8);
        ((Aux_223670*)((char*)p + 0x10))->Init_00222050();
        p->x = 0;
        p->y = 0;
        p->InitC_002232d0(this);
        return p;
    } else {
        return 0;
    }
}
} // namespace fn_00223670

namespace fn_fe86d092 {

// 0x002236c0 FUN_002236c0 (156 B): matches/0x002236c0.cpp
// sym: ?FUN_002236c0@fn_fe86d092@@YAXPAUElem40@1@00@Z
// FUN_002236c0 @ 0x002236c0
// FUN_002236c0: median-of-nine pivot selection step of a sort over 40-byte elements
void __cdecl FUN_002236c0(Elem40 *first, Elem40 *mid, Elem40 *last)
{
    int n = (int)(last - first);
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_002233e0(first, first + step, first + 2 * step);
        FUN_002233e0(mid - step, mid, mid + step);
        FUN_002233e0(last - 2 * step, last - step, last);
        FUN_002233e0(first + step, mid, last - step);
    } else {
        FUN_002233e0(first, mid, last);
    }
}


// 0x00223760 FUN_00223760 (100 B): equivalent/0x00223760.cpp
// sym: ?FUN_00223760@fn_fe86d092@@YAXPAUElem_223760@1@0@Z @c99077b0c4e0 @w32fae3518314
// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 4/4)
// FUN_00223760 @ 0x00223760
void FUN_00223760(Elem_223760 *first, Elem_223760 *last)
{
    hulk_intptr n = last - first;
    hulk_intptr i = n / 2;
    last = first + i;
    while (i > 0) {
        --last;
        --i;
        FUN_002234d0(first, i, n, *last);
    }
}


// 0x00223800 FUN_00223800 (100 B): matches/0x00223800.cpp
// sym: ?FUN_00223800@fn_fe86d092@@YAXPAUElem_223800@1@0@Z
// FUN_00223800 @ 0x00223800
void FUN_00223800(Elem_223800 *first, Elem_223800 *last)
{
    Elem_223800 tmp = last[-1];
    last[-1] = *first;
    FUN_002234d0(first, 0, (last - 1) - first, tmp);
}

} // namespace fn_fe86d092

// 0x00223870 FUN_00223870 (867 B): equivalent/0x00223870.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ?FUN_00223870@fn_00223870@@YAPAUElemPair_223870@1@PAU21@PAUElem_223870@1@1@Z @dbbe4d970a6e @w693c13d23798
namespace fn_00223870 {
// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 97/106, incomplete)
// FUN_00223870 @ 0x00223870
struct Elem_223870 {
    char pad00[0xc];
    unsigned k0;
    unsigned k1;
    int hi;
    char pad18[0x28 - 0x18];
};

struct ElemPair_223870 {
    Elem_223870 *first;
    Elem_223870 *second;
};

void __cdecl FUN_002236c0(Elem_223870 *first, Elem_223870 *mid, Elem_223870 *last);

static bool Less(const Elem_223870 &a, const Elem_223870 &b)
{
    if (a.hi != b.hi)
        return a.hi > b.hi;
    if (a.k0 != b.k0)
        return a.k0 < b.k0;
    return a.k1 > b.k1;
}

static void IterSwap(Elem_223870 *a, Elem_223870 *b)
{
    Elem_223870 t = *a;
    *a = *b;
    *b = t;
}

// std::_Unguarded_partition on a 40-byte element
ElemPair_223870 *__cdecl FUN_00223870(ElemPair_223870 *out, Elem_223870 *first, Elem_223870 *last)
{
    Elem_223870 *mid = first + (last - first) / 2;
    FUN_002236c0(first, mid, last - 1);

    Elem_223870 *pfirst = mid;
    Elem_223870 *plast = pfirst + 1;
    while (first < pfirst && !Less(pfirst[-1], *pfirst) && !Less(*pfirst, pfirst[-1]))
        --pfirst;
    while (plast < last && !Less(*plast, *pfirst) && !Less(*pfirst, *plast))
        ++plast;

    Elem_223870 *gfirst = plast;
    Elem_223870 *glast = pfirst;
    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (Less(*pfirst, *gfirst)) {
            } else if (Less(*gfirst, *pfirst)) {
                break;
            } else {
                IterSwap(plast++, gfirst);
            }
        }
        for (; first < glast; --glast) {
            if (Less(glast[-1], *pfirst)) {
            } else if (Less(*pfirst, glast[-1])) {
                break;
            } else {
                IterSwap(--pfirst, glast - 1);
            }
        }
        if (glast == first && gfirst == last) {
            out->first = pfirst;
            out->second = plast;
            return out;
        }
        if (glast == first) {
            if (plast != gfirst)
                IterSwap(pfirst, plast);
            ++plast;
            IterSwap(pfirst++, gfirst++);
        } else if (gfirst == last) {
            if (--glast != --pfirst)
                IterSwap(glast, pfirst);
            IterSwap(pfirst, --plast);
        } else {
            IterSwap(gfirst++, --glast);
        }
    }
}
} // namespace fn_00223870

namespace fn_fe86d092 {

// 0x00223c20 FUN_00223c20 (189 B): equivalent/0x00223c20.cpp
// sym: _FUN_00223c20 @33340a365bc8 @wcd5593c1619f
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 29/34, incomplete)
// FUN_00223c20 @ 0x00223c20
extern "C" void __cdecl FUN_00223c20(void * first_, void * last) {
    Item_223c20 * first = (Item_223c20 *)first_;
 if (first == ((Item_223c20 *)last)) return;
 for (Item_223c20* current = first + 1; current != ((Item_223c20 *)last); ++current) {
  int priority = current->priority;
  if (priority > first->priority || (priority == first->priority && (current->key < first->key || (current->key == first->key && current->secondary > first->secondary)))) {
   if (first != current) FUN_00223190(first, current, current + 1, 0, 0);
  } else {
   Item_223c20* position = current;
   Item_223c20* previous = current - 1;
   while (priority > previous->priority || (priority == previous->priority && (current->key < previous->key || (current->key == previous->key && current->secondary > previous->secondary)))) {
    position = previous;
    --previous;
   }
   if (position != current) FUN_00223190(position, current, current + 1, 0, 0);
  }
 }
}


// 0x00223d20 FUN_00223d20 (148 B): equivalent/0x00223d20.cpp
// sym: _FUN_00223d20 @500efd578f41 @w0d8919d07759
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 4/4)
// FUN_00223d20 @ 0x00223d20
extern "C" void FUN_00223d20(void *first, void * last_)
{
    Elem_223d20 * last = (Elem_223d20 *)last_;
    while (last - ((Elem_223d20 *)first) > 1) {
        --last;
        Elem_223d20 tmp = *last;
        *last = *((Elem_223d20 *)first);
        FUN_002234d0(((Elem_223d20 *)first), 0, last - ((Elem_223d20 *)first), tmp);
    }
}


// 0x00223dc0 FUN_00223dc0 (294 B): equivalent/0x00223dc0.cpp
// sym: ?FUN_00223dc0@fn_fe86d092@@YAXPAURecord_223dc0@1@0H@Z @b529dcf23c93 @wa7ebdd48d8d8
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 12/14, incomplete)
// FUN_00223dc0 @ 0x00223dc0
void __cdecl FUN_00223dc0(Record_223dc0* first, Record_223dc0* last, int depth) {
    while (last - first > 32) {
        if (depth <= 0) {
            if (last - first > 1) FUN_00223760(first, last, 0, 0);
            FUN_00223d20((Record_223dc0 *)first, (Record_223dc0 *)last);
            return;
        }
        Partition middle;
        FUN_00223870(&middle, first, last);
        depth = depth / 2;
        depth += depth / 2;
        if (middle.first - first < last - middle.second) {
            FUN_00223dc0(first, middle.first, depth);
            first = middle.second;
        } else {
            FUN_00223dc0(middle.second, last, depth);
            last = middle.first;
        }
    }
    if (last - first > 1) FUN_00223c20((Record_223dc0 *)first, (Record_223dc0 *)last);
}


// 0x00223f50 FUN_00223f50 (67 B): matches/0x00223f50.cpp
// sym: ?Target@fn_fe86d092@@YIXPAVObj_223f50@1@@Z
void __fastcall Target(Obj_223f50* p) {
    if (p->dirty) {
        char* end = (char*)p + 0x6c + p->count * 0x28;
        p->dirty = 0;
        char* base = (char*)p + 0x6c;
        Move_00223dc0(base, end, (int)(end - base) / 0x28);
    }
}


// 0x00223fa0 FUN_00223fa0 (696 B): equivalent/0x00223fa0.cpp
// sym: ?FUN_00223fa0@Blender_223fa0@fn_fe86d092@@QAEXXZ @ab915c8a3b01 @w820c6f7221de
// STATUS: equivalent (tools/equiv.py level 3: 13934 inputs, branch coverage 34/34)
// FUN_00223fa0 @ 0x00223fa0
void Blender_223fa0::FUN_00223fa0()
{
    if (count == 0)
        return;
    if (dirty) {
        Elem_223fa0 *first = elems;
        Elem_223fa0 *last = elems + count;
        dirty = false;
        FUN_00223dc0(first, last, (int)(last - first));
    }
    Pose pose;
    pose.FUN_00221b30(&xform);
    hulk_freg sum = elems[0].weight;
    int key0 = elems[0].key;
    int curKey = key0;
    unsigned int start = 0;
    unsigned int i = 1;
    float weight;   // x87: the layer weight is stored (fstp [esp+0x10]); the blend divides by the stored float
    volatile float acc;
    volatile float wt;
    if (count > 1) {
        do {
            int key = elems[i].key;
            if (key != curKey) {
                if (curKey == key0) {
                    weight = 1.0f;
                } else if (sum > 0.0f) {
                    if (sum > 1.0f)
                        weight = 1.0f;
                    else
                        weight = sum;
                } else {
                    weight = 0.0f;
                }
                acc = elems[i].factor * elems[i].weight;
                elems[start].layer->Apply(&pose, &xform, target, weight);
                for (unsigned int j = start + 1; j < i; j++) {
                    hulk_freg p = elems[j].weight * elems[j].factor;
                    hulk_freg t = acc + p;
                    acc = t;
                    if (t > 0.0f)
                        wt = p / acc * weight;
                    else
                        wt = 0.0f;
                    elems[j].layer->Apply(&pose, &xform, target, wt);
                }
                sum = 0.0f;
                curKey = key;
                start = i;
            }
            sum += elems[i].weight;
            i++;
        } while (i < count);
    }
    if (curKey == key0) {
        weight = 1.0f;
    } else if (sum > 0.0f) {
        if (sum > 1.0f)
            weight = 1.0f;
        else
            weight = sum;
    } else {
        weight = 0.0f;
    }
    acc = elems[start].weight * elems[start].factor;
    elems[start].layer->Apply(&pose, &xform, target, weight);
    for (unsigned int j = start + 1; j < count; j++) {
        hulk_freg p = elems[j].weight * elems[j].factor;
        hulk_freg t = acc + p;
        acc = t;
        if (t > 0.0f)
            wt = p / acc * weight;
        else
            wt = 0.0f;
        elems[j].layer->Apply(&pose, &xform, target, wt);
    }
    xform.FUN_00221ee0();
    target->b22 = 1;
    target->b23 = 1;
    target->b20 = 0;
    target->b21 = 1;
}


// 0x00224260 FUN_00224260 (725 B): equivalent/0x00224260.cpp
// sym: ?FUN_00224260@Mixer@fn_fe86d092@@QAE_NHHPAUSink_224260@2@@Z @b618605e6702 @wa65b0585bf83
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 42/42)
// FUN_00224260 @ 0x00224260
bool Mixer::FUN_00224260(int a, int b, Sink_224260 *sink)
{
    if (!(count > 0))
        return false;
    bool any = false;
    if (dirty != 0) {
        Entry_224260 *begin = &e[0];
        Entry_224260 *end = begin + count;
        dirty = 0;
        FUN_00223dc0(begin, end, end - begin);
    }
    int k0 = e[0].key;
    double S = e[0].w;
    int cur = k0;
    unsigned j = 0;
    float s;
    float P = 0.0f;
    unsigned n = count;
    if (n > 1) {
        unsigned i = 1;
        do {
            int ki = e[i].key;
            if (ki != cur) {
                if (cur == k0)
                    s = 1.0f;
                else if (!(S > 0.0))
                    s = 0.0f;
                else if (!(S > 1.0))
                    s = (float)S;
                else
                    s = 1.0f;
                double v = e[i].f18 * e[i].w;
                Target_224260 *t0 = e[j].target;
                P = (float)v;
                if (t0->v11(a, b, sink, s))
                    any = true;
                for (unsigned k = j + 1; k < i; k++) {
                    double c = e[k].w * e[k].f18;
                    Target_224260 *tk = e[k].target;
                    double Q = P + c;
                    P = (float)Q;
                    float amt;
                    if (Q > 0.0)
                        amt = (float)(c / P * s);
                    else
                        amt = 0.0f;
                    if (tk->v11(a, b, sink, amt))
                        any = true;
                }
                S = 0.0;
                cur = ki;
                j = i;
            }
            S = S + e[i].w;
            n = count;
            i++;
        } while (i < n);
    }
    if (cur == k0)
        s = 1.0f;
    else if (!(S > 0.0))
        s = 0.0f;
    else if (!(S > 1.0))
        s = (float)S;
    else
        s = 1.0f;
    {
        double v = e[j].w * e[j].f18;
        Target_224260 *tj = e[j].target;
        P = (float)v;
        if (tj->v11(a, b, sink, s))
            any = true;
    }
    for (unsigned k = j + 1; k < count; k++) {
        double c = e[k].w * e[k].f18;
        Target_224260 *tk = e[k].target;
        double Q = P + c;
        P = (float)Q;
        float amt;
        if (Q > 0.0)
            amt = (float)(c / P * s);
        else
            amt = 0.0f;
        if (tk->v11(a, b, sink, amt))
            any = true;
    }
    sink->FUN_00221ee0();
    return any;
}


// 0x00224540 FUN_00224540 (772 B): equivalent/0x00224540.cpp
// sym: ?FUN_00224540@Blend_224540@fn_fe86d092@@QAE_NIPAM@Z @4150bde2f204 @w8e5225dce6dc
// STATUS: equivalent (tools/equiv.py level 3: 2647 inputs, branch coverage 42/42)
// FUN_00224540 @ 0x00224540
// FUN_00224540 @ 0x00224540
// Weighted blend of a run of layers. Consecutive entries with the same key form a group; the first layer of
// each finished group is sampled with the weight accumulated so far (clamped to 0..1), the rest of the group
// share the remaining weight in proportion to their a*b contribution. Returns true if any layer produced a
// value; *out is blended towards each layer's value.
bool Blend_224540::FUN_00224540(hulk_uintptr ctx, float *result)
{
    if (ctx == 0 || count == 0)
        return false;

    Frame_224540 fr;
    fr.changed = false;
    FUN_00223f50();

    float acc = e[0].b;
    fr.key0 = e[0].key;
    unsigned cur = fr.key0;
    fr.start = 0;
    fr.i = 1;

    if (count > 1) {
        do {
            fr.k = e[fr.i].key;
            if (fr.k != cur) {
                if (cur == fr.key0) {
                    fr.f14 = 1.0f;
                } else if (acc > 0.0f) {
                    if (acc > 1.0f)
                        fr.f14 = 1.0f;
                    else
                        fr.f14 = acc;
                } else {
                    fr.f14 = 0.0f;
                }
                fr.sum = e[fr.i].a * e[fr.i].b;
                fr.f18 = 0.0f;
                if (e[fr.start].layer->v12(ctx, &fr.f18)) {
                    fr.changed = true;
                    *result = (fr.f18 - *result) * fr.f14 + *result;
                }
                for (unsigned j = fr.start + 1; j < fr.i; ++j) {
                    fr.sum = fr.sum + e[j].b * e[j].a;
                    if (fr.sum > 0.0f)
                        fr.w2 = ((e[j].b * e[j].a) / fr.sum) * fr.f14;
                    else
                        fr.w2 = 0.0f;
                    fr.f18 = 0.0f;
                    if (e[j].layer->v12(ctx, &fr.f18)) {
                        fr.changed = true;
                        *result = (fr.f18 - *result) * fr.w2 + *result;
                    }
                }
                acc = 0.0f;
                cur = fr.k;
                fr.start = fr.i;
            }
            acc = acc + e[fr.i].b;
            ++fr.i;
        } while (fr.i < count);
    }

    if (cur == fr.key0) {
        fr.f18 = 1.0f;
    } else if (acc > 0.0f) {
        if (acc > 1.0f)
            fr.f18 = 1.0f;
        else
            fr.f18 = acc;
    } else {
        fr.f18 = 0.0f;
    }

    fr.sum = e[fr.start].b * e[fr.start].a;
    fr.f14 = 0.0f;
    if (e[fr.start].layer->v12(ctx, &fr.f14)) {
        fr.changed = true;
        *result = (fr.f14 - *result) * fr.f18 + *result;
    }
    for (unsigned j = fr.start + 1; j < count; ++j) {
        fr.sum = fr.sum + e[j].b * e[j].a;
        if (fr.sum > 0.0f)
            fr.w2 = ((e[j].b * e[j].a) / fr.sum) * fr.f18;
        else
            fr.w2 = 0.0f;
        fr.f14 = 0.0f;
        if (e[j].layer->v12(ctx, &fr.f14)) {
            fr.changed = true;
            *result = (fr.f14 - *result) * fr.w2 + *result;
        }
    }
    return fr.changed;
}

} // namespace fn_fe86d092
