// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00263f30..0x00265bf0 (kind game, layer engine, confidence medium), dominant class content::LoadStream
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/content.h"
#include "decls/data/records.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa1126e6 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa1126e6 {} using namespace fn_fa1126e6;
#include "engine/content.h"

// ---- declarations shared by the functions below
namespace fn_fa1126e6 {
class Service_263f50 {
  public:
    int Get_00264870();
};
class LoadStream_263f50 {
  public:
    char p[8];
    int a;
    char b[4];
    int c[12];
    int d;
    int e;
    void Init();
};
class Obj_263fb0 {
    char pad[0x10];

  public:
    unsigned int value;
};
struct X_263fc0 {
    char pad[0x14];
    unsigned value;
};
} // namespace fn_fa1126e6
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned);
#endif
namespace fn_fa1126e6 {
struct Job_263fd0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool IsDone();
};
struct Pump_263fd0 {
    void Tick_00264d20();
};
Job_263fd0* StartJob_002703c0(void* dst, int mode, void* src, int one, unsigned n);
int __cdecl FUN_0026fd50(hulk_intptr a, int b);
class Inner_2640f0 {
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
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual bool f20();
    virtual void f21();
};
class Manager_2640f0 {
  public:
};
extern int getThing_00267f80();
class Target_2640f0 {
  public:
    char pad0[8];
    Inner_2640f0* obj;
    char padc[1];
    bool flag;
    char pad_e[0x36];
    int result;
    void run();
};
namespace content {
struct LoadStream {
    virtual void hulk_slot_FUN_00263f50(); void FUN_00263f50();
    int field04;
    char pad08[4];
    unsigned char flag0c;
    char pad0d;
    unsigned char flag0e;
    char pad0f;
    int field10, field14, field18, field1c;
    char pad20[8];
    int field28, field2c, field30, field34, field38;
    LoadStream(hulk_intptr a, int b);
};
}
extern "C" char DAT_0042ae9c[];
class Obj_2641e0 {
  public:
    virtual void X();
    virtual void Release();
};
class LoadStream {
  public:
    LoadStream(void* a, hulk_intptr b, int c);
    union { void* vp; hulk_uintptr vt; hulk_intptr vtable; };
    union { int field4; int m; };
    Obj_2641e0* mObj;
    char _m_pad_c[0x1];
    union { unsigned char flagD; unsigned char value; };
    union { unsigned char flag; unsigned char flagE; };
    char _m_pad_f[0x11];
    void* m20;
    void* m24;
    void Init();
    void Destroy();
    void Setup_00264310(int);
    LoadStream* Target(hulk_intptr, int, int);
    void Base0_00263f50();
    void Init_00264310(void* a);
};
extern "C" void FUN_00267070(void*);
class Sink_264230 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(int);
};
class Obj_264230 {
  public:
    char pad0[8];
    Sink_264230* sink;
    char padc[1];
    char flag;
    char padE[6];
    int pos;
    void target(int);
    void refresh_002640f0();
};
class Inner_264270 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int, int);
};
class Obj_264270 {
  public:
    char p[8];
    Inner_264270* mInner;
    char q[8];
    int mCount;
    char r[4];
    void FUN_002640f0();
    bool fnB(int, int, int, int);
};
struct Sink_264310 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual unsigned int vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual bool vfn23();
};
class Stream {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void v3(int a, int b, int c);
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
    virtual void _m_vf14();
    virtual void _m_vf15();
    virtual int v16();
    char _m_pad_4[0x4];
    Sink_264310 *sink;
    char open;
    char _m_pad_d[0x1];
    char buffered;
    char _m_pad_f[0x1];
    unsigned int size;
    char _m_pad_14[0x8];
    int bank;
    char _m_pad_20[0x10];
    unsigned int limit;
    char _m_pad_34[0x4];
    unsigned int capacity;
    void FUN_00264050(char *other);
    void FUN_002640f0();
    void FUN_00264310(const char *name);
};
class Reader {
public:
    char pad0[8];
    Stream* stream;
    char pad0c[4];
    unsigned int limit;
    char pad14[4];
    unsigned int pos;
    char pad1c[0x34 - 0x1c];
    int lastCount;
    unsigned int chunk;
    void FUN_00264050(int dest);
};
void __cdecl thunk_FUN_002710d0(Sink_264310 **out, const char *name, int a, int b, int c, int d, int e, int f);
struct X_264870 {
    int pad;
    unsigned int value;
};
extern "C" CoreFiber* __cdecl FUN_0026dbf0();
extern "C" void* __cdecl FUN_00266da0(void*);
extern "C" void __cdecl FUN_0026dc00(CoreFiber*);
struct Pair_264e10 {
    unsigned a;
    unsigned b;
};
class Queue_264e10 {
  public:
    unsigned mBegin;
    Pair_264e10* mNext;
    Pair_264e10* mEndQueue;
    Pair_264e10* mLimit;
    bool Push(Pair_264e10* value);
};
class Item_264ff0 {
  public:
    virtual void V0();
    virtual void V1();
};
class Owner_264ff0 {
  public:
};
class Temp_264ff0 {
    char pad[8];

  public:
    void Init_002314a0(Owner_264ff0*);
    Item_264ff0* First_00231640();
    Item_264ff0* Next_002314c0();
};
class Item_2650e0 {
  public:
    virtual void V0();
    virtual void V1();
};
class Owner_2650e0 {
  public:
};
class Temp_2650e0 {
    char pad[8];

  public:
    void Init_002314a0(Owner_2650e0*);
    Item_2650e0* First_00231640();
    Item_2650e0* Next_002314c0();
};
class Releasable_265190 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};
struct Entry_265190 {
    int tag;
    Releasable_265190* obj;
};
struct Ring_265190 {
    Entry_265190* head;
    Entry_265190* tail;
    Entry_265190* start;
    Entry_265190* end;
    void FUN_00264e10(Entry_265190* e);
};
class Queue_265190 {
public:
    char pad0[8];
    int pending;
    char pad1[8];
    Ring_265190 ring;
    void FUN_00265190(Releasable_265190* obj);
};
class Obj {
  public:
    virtual void Fn();
};
class Worker {
  public:
    void Do_00231590(unsigned low, unsigned high, Obj* o);
};
class Owner {
    char pad[12];
    Worker* worker;

  public:
    void Run(Obj* o, hulk_intptr n);
};
extern "C" unsigned __int64 __cdecl Calc_00267340(int n, int a, int b);
struct Item_265280 {
    virtual void unused();
    virtual void release();
    void FUN_00266950(int);
};
struct Owner_265280 {  };
struct Entry_265280 { Item_265280* item; unsigned value; };
struct Queue_265280 {
    char pad0[8];
    Owner_265280* owner;
    char padC[8];
    Entry_265280* read;
    Entry_265280* write;
    Entry_265280* begin;
    Entry_265280* end;
    void clear();
};
struct Temp_265310 {
    char x[0x18];
    void Fnf_00231160(int);
    int Fng_00231180(int, int);
};
typedef unsigned int u32_265340;
struct Pair_265340 {
    char data[24];
    void First_00231160(u32_265340);
    int Second_00231180(u32_265340, u32_265340);
};
extern unsigned long long __cdecl Parse_00267340(char*, int, int);
} // namespace fn_fa1126e6
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *strrchr(const char *s, int c);
#endif
namespace fn_fa1126e6 {
struct Sink_265390 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3(const char *name, struct Job_265390 *job);
};
struct Local_265390 {
    char data[0x18];
    void FUN_00231160(int v);
    Sink_265390 *FUN_00231180(long long v);
};
struct Job_265390 {
    virtual void vfn0();
    virtual void vfn1();
    int FUN_00266710();
    void FUN_00266950(int v);
    const char *FUN_002666d0();
};
struct Entry_265390 {
    Job_265390 *job;
    int arg;
};
long long FUN_00267340(const char *s, int a, int b);
void FUN_00266da0(int v);
class Queue_265390 {
public:
    char pad0;
    char stop;                // 0x1
    char pad1[6];
    Job_265390 *current;             // 0x8
    int fc;
    char pad2[4];
    Entry_265390 *head;              // 0x14
    Entry_265390 *tail;              // 0x18
    Entry_265390 *begin;             // 0x1c
    Entry_265390 *end;               // 0x20
    char pad3[4];
    int *ringHead;            // 0x28
    int *ringTail;            // 0x2c
    int *ringBegin;           // 0x30
    int *ringEnd;             // 0x34
    void FUN_00265390();
};
struct Obj_265520 {
    void Target_00265390();
};
class Obj_265560 {
  public:
    virtual void f();
    virtual void g();
};
class Holder_265560 {
  public:
};
class C_265560 {
  public:
    char pad[0x0c];
    Holder_265560* m;
    void target(Obj_265560* p);
};
class B_265590 {
  public:
    void First_00264ff0();
    void Second_002650e0();
};
class A_265590 {
  public:
    char pad[12];
    B_265590* x;
    B_265590* y;
    void Run();
};
struct Obj_2656a0 {
    void Target_002655b0();
};
struct Config_2656b0 { unsigned first, second, count, value; };
struct Block_2656b0 { unsigned capacity, count, used; char padding[12]; void* slots; void* entries; int sentinel; void FUN_00231550(unsigned, unsigned, unsigned); };
extern void* __cdecl FUN_0008d690(unsigned);
extern "C" void* __cdecl FUN_0008d6d0(unsigned);
extern void __cdecl FUN_00265520();
extern "C" void __cdecl FUN_0026dd70(void*, void (__cdecl*)(), void*, unsigned, unsigned);
struct Object {
 unsigned char a,b,c,pad;
 unsigned interval, unused;
 Block_2656b0 *first,*second;
 char *storage,*begin,*current,*end;
 unsigned reserved;
 char *buffer,*bufferBegin,*bufferCurrent,*bufferEnd;
 Object* FUN_002656b0(Config_2656b0* config);
};
struct Request { char pad[0x100]; void* context; char pad104[8]; unsigned char flags; };
struct LoadRequest_265810 { virtual void slot0(); LoadRequest_265810* FUN_00266890(Request*);  void FUN_00266950(int); void FUN_00266850(void*); int FUN_00266710(); };
extern "C" void* __cdecl FUN_00263ed0(unsigned int,int);
struct Entry_265810 { LoadRequest_265810* task; unsigned int value; };
struct Manager_265810 { unsigned char flags; char pad[0x13]; Entry_265810* head; Entry_265810* tail; Entry_265810* begin; Entry_265810* end; void FUN_002655b0(); void FUN_00265810(Request*,LoadRequest_265810**); };
} // namespace fn_fa1126e6
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strncpy(char*, const char*, unsigned);
#endif
namespace fn_fa1126e6 {
struct S_265920 {
    char buf[256];
    int a;
    int b;
    int c;
    char f;
};
class C_265920 {
  public:
    void Fn_00265810(S_265920*, int);
    void Go(const char* s, int x, int z);
};
struct Node { virtual void slot0(); virtual void slot1(); };
struct Pool_2659a0 {  };
struct Iter_2659a0 {
  char pad[0x18];
  void FUN_00231160(Pool_2659a0*);
  Node* FUN_00231180(int, int);
};
struct W_2659a0 {
  char pad[0x10]; Pool_2659a0* pool;
  void FUN_002659a0(int);
};
class Thing_265ad0 {
  public:
    char pad0[8];
    int field8;
    char padc[8];
    unsigned int a, b, c, d;
    void step_002655b0();
};
struct Params {
    int a, b, c, d;
};
struct Obj_265b70 {
    unsigned char a, b, c, pad;
    unsigned interval, unused;
    void *first, *second;
    char *storage, *begin, *current, *end;
    unsigned reserved;
    char *buffer, *bufferBegin, *bufferCurrent, *bufferEnd;
    unsigned tail;                 // +0x38 (not set by the constructor)
    Obj_265b70* FUN_002656b0(Params* p);
};
void* FUN_0008d690(int size);

// 0x00263f30 thunk_FUN_00267090 (5 B): not yet verified
// 0x00263f40 thunk_FUN_00267090 (5 B): not yet verified

// 0x00263f50 FUN_00263f50 (89 B): matches/0x00263f50.cpp
// sym: ?Init@LoadStream_263f50@fn_fa1126e6@@QAEXXZ
void LoadStream_263f50::Init() {
    a = 0;
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
    b[3] = 0;
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    c[3] = 0;
    c[4] = 0;
    c[5] = 0;
    c[6] = 0;
    c[7] = 0;
    c[8] = 0;
    c[9] = 0;
    c[10] = 0;
    c[11] = 0;
    unsigned int x = (*(Service_263f50**)&DAT_00527c58)->Get_00264870();
    e = 0;
    d = x / 1000;
}


// 0x00263fb0 FUN_00263fb0 (4 B): matches/0x00263fb0.cpp
// sym: ?FUN_00263fb0@fn_fa1126e6@@YIIPAVObj_263fb0@1@@Z
// Same code shape as 0x00059a30 (propagated; names are from that function)
unsigned int __fastcall FUN_00263fb0(Obj_263fb0* self) {
    return self->value;
}


// 0x00263fc0 FUN_00263fc0 (4 B): matches/0x00263fc0.cpp
// sym: @FUN_00263fc0@4
// Same code shape as 0x000862d0 (propagated; names are from that function)
extern "C" unsigned __fastcall FUN_00263fc0(X_263fc0* self) {
    return self->value;
}


// 0x00263fd0 FUN_00263fd0 (116 B): matches/0x00263fd0.cpp
// sym: ?F@fn_fa1126e6@@YGXPAX0IH@Z
// data: g_pump = DAT_00527c58
void __stdcall F(void* dst, void* src, unsigned n, int mode) {
    if (mode == 1) {
        memcpy(dst, src, n);
        return;
    }
    Job_263fd0* j = StartJob_002703c0(dst, mode, src, 1, n);
    j->v0();
    while (!j->IsDone())
        (*(Pump_263fd0**)&DAT_00527c58)->Tick_00264d20();
    j->v1();
}


// 0x00264050 FUN_00264050 (105 B): equivalent/0x00264050.cpp
// sym: ?FUN_00264050@Reader@fn_fa1126e6@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00264050 @ 0x00264050
void Reader::FUN_00264050(int dest) {
    if (pos >= limit)
        return;
    unsigned int n = chunk;
    if (pos + n >= limit) {
        int rest = limit - pos;
        stream->v3(dest, FUN_0026fd50(rest, stream->v16()), 1);
        lastCount = rest;
        pos = pos + rest;
        return;
    }
    stream->v3(dest, n, 1);
    pos += n;
    lastCount = n;
}


// 0x002640f0 FUN_002640f0 (65 B): matches/0x002640f0.cpp
// sym: ?run@Target_2640f0@fn_fa1126e6@@QAEXXZ
// data: gThing_2640f0 = DAT_00527c58
void Target_2640f0::run() {
    if (obj) {
        if (flag) {
            obj->f21();
            return;
        }
        while (!obj->f20()) {
            ((owners::Q_264d20 *)((*(Manager_2640f0**)&DAT_00527c58)))->FUN_00264d20();
            result = getThing_00267f80();
        }
    }
}

} // namespace fn_fa1126e6

// 0x00264140 FUN_00264140 (74 B): equivalent/0x00264140.cpp
// sym: ?FUN_00264140@Converter_264140@owners@@QAEXPAEII@Z
// STATUS: equivalent (tools/equiv.py level 3: 2544 inputs, branch coverage 12/12)
// FUN_00264140 @ 0x00264140
void owners::Converter_264140::FUN_00264140(unsigned char* data, unsigned int count, unsigned int size)
{
    if (!reverse || size == 1) return;
    for (unsigned int i = 0; i < count; ++i) {
        unsigned char* left = data;
        unsigned char* right = data + size - 1;
        while (left < right) {
            unsigned char value = *right;
            *right = *left;
            *left = value;
            ++left;
            --right;
        }
        data += size;
    }
}

namespace fn_fa1126e6 {

// 0x00264190 FUN_00264190 (70 B): equivalent/0x00264190.cpp
// sym: ??0LoadStream@content@fn_fa1126e6@@QAE@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00264190 @ 0x00264190
namespace content {
LoadStream::LoadStream(hulk_intptr a, int b) {
    field04 = 0;
    FUN_00263f50();
    field28 = a;
    field1c = 0;
    field2c = 0;
    field18 = 0;
    field14 = 0;
    field34 = 0;
    field10 = b;
    field30 = b;
    field38 = b;
    flag0c = 1;
    flag0e = 1;
}
}


// 0x002641e0 FUN_002641e0 (66 B): matches/0x002641e0.cpp
// sym: ?Destroy@LoadStream@fn_fa1126e6@@QAEXXZ
void LoadStream::Destroy() {
    vt = ((hulk_intptr)DAT_0042ae9c);
    Init();
    if (mObj)
        mObj->Release();
    if (m20)
        FUN_00267070(m20);
    if (m24)
        FUN_00267070(m24);
    vt = ((hulk_intptr)DAT_003f6098);
}


// 0x00264230 FUN_00264230 (49 B): matches/0x00264230.cpp
// sym: ?target@Obj_264230@fn_fa1126e6@@QAEXH@Z
void Obj_264230::target(int amount) {
    sink->f(pos + amount);
    pos += amount;
    if (flag)
        refresh_002640f0();
}


// 0x00264270 FUN_00264270 (76 B): matches/0x00264270.cpp
// sym: ?fnB@Obj_264270@fn_fa1126e6@@QAE_NHHHH@Z
bool Obj_264270::fnB(int a, int b, int c, int d) {
    int n = b * c;
    mInner->f3(a, n, d);
    mCount += n;
    FUN_002640f0();
    ((owners::Converter_264140 *)this)->FUN_00264140((unsigned char *)(hulk_uintptr)(int)a, (unsigned int)b, (unsigned int)c);
    return true;
}

} // namespace fn_fa1126e6

// 0x002642c0 FUN_002642c0 (74 B): equivalent/0x002642c0.cpp
// sym: ?FUN_002642c0@Controller_2642c0@owners@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002642c0 @ 0x002642c0
void owners::Controller_2642c0::FUN_002642c0() {
    FUN_002640f0();
    unsigned int next = selected == 0;
    position = 0;
    limit = capacity;
    currentBuffer = ((char*)((char*)&DAT_004e7c28)) + next * 0x20000;
    selected = next;
    FUN_00264050(((char*)((char*)&DAT_004e7c28)) + (next == 0) * 0x20000);
}

namespace fn_fa1126e6 {

// 0x00264310 FUN_00264310 (167 B): equivalent/0x00264310.cpp
// sym: ?FUN_00264310@Stream@fn_fa1126e6@@QAEXPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 10/10)
// FUN_00264310 @ 0x00264310
void Stream::FUN_00264310(const char *name)
{
    thunk_FUN_002710d0(&sink, name, 0, 0, 1, 0, 1, 1);
    if (sink != 0) {
        FUN_002640f0();
        if (sink->vfn23()) {
            open = 1;
            unsigned int n = sink->vfn15();
            size = n;
            if (!buffered) {
                limit = n;
                capacity = n;
                return;
            }
            if (n < 0x20000) {
                bank = 1;
                capacity = n;
            } else {
                capacity = 0x20000;
            }
            FUN_00264050(((char*)((char*)&DAT_004e7c28)) + ((bank == 0) << 17));
            FUN_002640f0();
            return;
        }
    }
    open = 0;
}


// 0x00264430 FUN_00264430 (59 B): matches/0x00264430.cpp
// sym: ?Target@LoadStream@fn_fa1126e6@@QAEPAV12@HHH@Z
LoadStream* LoadStream::Target(hulk_intptr a, int b, int c) {
    field4 = 0;
    vtable = ((hulk_intptr)DAT_0042ae9c);
    Init();
    flagD = 1;
    flagE = (c == 1);
    Setup_00264310(a);
    return this;
}

} // namespace fn_fa1126e6

// 0x00264470 content::LoadStream::vfunc_2 (86 B): matches/0x00264470.cpp [wrapped: conflict: LoadStream]
// sym: ?f2@LoadStream@fn_00264470@@UAEPAV12@E@Z
namespace fn_00264470 {
class Ref_264470 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class LoadStream {
  public:
    virtual void f0();
    virtual void f1();
    virtual LoadStream* f2(unsigned char);
    char pad[4];
    Ref_264470* mRef;
    char pad2[20];
    void* a;
    void* b;
};
extern int hulk_at_0042ae9c, hulk_at_003f6098;
struct ThisCall_002640f0 {
    void Init_002640f0();
};
extern "C" void FUN_00267070(void*);
void Destroy_00263f30(LoadStream*);
LoadStream* LoadStream::f2(unsigned char flag) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0042ae9c;
    ((ThisCall_002640f0*)(this))->Init_002640f0();
    if (mRef)
        mRef->f1();
    if (a)
        FUN_00267070(a);
    if (b)
        FUN_00267070(b);
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f6098;
    if (flag & 1)
        Destroy_00263f30(this);
    return this;
}
} // namespace fn_00264470

namespace fn_fa1126e6 {

// 0x002644d0 FUN_002644d0 (59 B): matches/0x002644d0.cpp
// sym: ??0LoadStream@fn_fa1126e6@@QAE@PAXHH@Z
LoadStream::LoadStream(void* a, hulk_intptr b, int c) {
    m = 0;
    vp = (void*)((hulk_intptr)DAT_0042ae9c);
    Base0_00263f50();
    flag = (c == 1);
    value = ((unsigned char*)a)[0x10c];
    Init_00264310(a);
}

} // namespace fn_fa1126e6

// 0x00264510 FUN_00264510 (121 B): matches/0x00264510.cpp
// sym: ?FUN_00264510@S_264510@owners@@QAEXI@Z
void owners::S_264510::FUN_00264510(unsigned n) {
    if (m0c && n) {
        if (!m0e) {
            A(n);
            return;
        }
        unsigned t = m2c + n;
        if (t <= m30) {
            m2c = t;
            m14 += n;
            return;
        }
        unsigned left = n;
        if (left > 0) {
            for (;;) {
                unsigned c = m2c;
                unsigned k = left;
                if (c + left > m30)
                    k = m30 - c;

                m2c += k;
                m14 += k;
                left -= k;
                if (left == 0)
                    break;
                B();
            }
        }
    }
}


// 0x00264590 FUN_00264590 (390 B): equivalent/0x00264590.cpp [wrapped: conflict: Stream]
// sym: ?FUN_00264590@Stream@fn_00264590@@QAE_NPBXHHH@Z
namespace fn_00264590 {
// STATUS: equivalent (tools/equiv.py level 3: 2949 inputs, branch coverage 28/28)
// FUN_00264590 @ 0x00264590

struct Sink_264590 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual bool vfn20();
    virtual void vfn21();
};
struct Clock_264590 {
};
unsigned int FUN_00267f80();

class Stream {
public:
    char pad0[8];
    Sink_264590 *sink;              // 0x8
    char pad1[1];
    char fd;                 // 0xd
    char pad2;
    char notify;             // 0xf
    char pad3[0x14 - 0x10];
    int total;               // 0x14
    char pad4[0x1c - 0x18];
    int bank;                // 0x1c
    char pad5[0x28 - 0x20];
    char *buffer;            // 0x28
    unsigned int pos;        // 0x2c
    unsigned int limit;      // 0x30
    unsigned int capacity;   // 0x34
    char pad6[4];
    unsigned int pending;    // 0x3c
    unsigned int interval;   // 0x40
    unsigned int lastTime;   // 0x44
    void FUN_00263fd0(const void *src, char *dst, int n, int flag);
    void FUN_00264050(char *other);
    bool FUN_00264590(const void *data, int count, int size, int flag);
};

bool Stream::FUN_00264590(const void *data, int count, int size, int flag)
{
    int n = count * size;
    unsigned int used = pos;
    pending += n;
    if (used + n <= limit) {
        FUN_00263fd0(data, buffer + used, n, flag);
        pos += n;
        total += n;
    } else {
        const char *src = (const char *)data;
        while (n > 0) {
            int chunk = n;
            if (pos + n > limit)
                chunk = limit - pos;
            FUN_00263fd0(src, buffer + pos, chunk, flag);
            pos += chunk;
            total += chunk;
            n -= chunk;
            src += chunk;
            if (n <= 0)
                break;
            if (sink != 0) {
                if (fd) {
                    sink->vfn21();
                } else {
                    while (!sink->vfn20()) {
                        ((owners::Q_264d20 *)((*(Clock_264590**)&DAT_00527c58)))->FUN_00264d20();
                        lastTime = FUN_00267f80();
                    }
                }
            }
            int next = (bank == 0);
            pos = 0;
            limit = capacity;
            buffer = ((char*)((char*)&DAT_004e7c28)) + (next << 17);
            bank = next;
            FUN_00264050(((char*)((char*)&DAT_004e7c28)) + ((next == 0) << 17));
        }
    }
    if (notify)
        ((owners::Converter_264140 *)this)->FUN_00264140((unsigned char *)data, (unsigned int)count, (unsigned int)size);
    if (!fd) {
        if (pending >= 0x400) {
            if (FUN_00267f80() - lastTime >= interval) {
                ((owners::Q_264d20 *)((*(Clock_264590**)&DAT_00527c58)))->FUN_00264d20();
                lastTime = FUN_00267f80();
            }
            pending = 0;
        }
    }
    return true;
}
} // namespace fn_00264590


// 0x002647e0 FUN_002647e0 (29 B): matches/0x002647e0.cpp
// sym: ?FUN_002647e0@X_2647e0@owners@@QAEEHHHH@Z
unsigned char owners::X_2647e0::FUN_002647e0(hulk_intptr x, hulk_intptr y, int z, hulk_intptr w) {
    if (!a)
        return 0;
    if (!b)
        return first(((int)x), ((int)y), z, ((int)w));
    return second(((int)x), ((int)y), z, ((int)w));
}


// 0x00264860 FUN_00264860 (10 B): matches/0x00264860.cpp
// sym: ?FUN_00264860@C_264860@owners@@QAEXH@Z
void owners::C_264860::FUN_00264860(int x) {
    value = x;
}

namespace fn_fa1126e6 {

// 0x00264870 FUN_00264870 (4 B): matches/0x00264870.cpp
// sym: ?FUN_00264870@fn_fa1126e6@@YIIPAUX_264870@1@@Z
// Same code shape as 0x00086270 (propagated; names are from that function)
unsigned int __fastcall FUN_00264870(X_264870* p) {
    return p->value;
}

} // namespace fn_fa1126e6

// 0x00264c70 FUN_00264c70 (55 B): matches/0x00264c70.cpp
// sym: ?FUN_00264c70@X_264c70@owners@@QAEHXZ
int owners::X_264c70::FUN_00264c70() {
    unsigned int edx = f14;
    unsigned int eax = f18;
    int count;
    if (edx <= eax) {
        count = (int)(eax - edx) >> 3;
    } else {
        count = ((int)(eax - f1c) >> 3) + ((int)(f20 - edx) >> 3);
    }
    if ((unsigned int)count > 0u || f8 != 0)
        return 1;
    return 0;
}


// 0x00264d20 FUN_00264d20 (125 B): matches/0x00264d20.cpp
// sym: ?FUN_00264d20@Q_264d20@owners@@QAEXXZ
// data: g_cur_264d20 = DAT_00527c4c, g_obj_264d20 = DAT_00527c28
// the content loader's yield: from the game's fiber (0x00527c4c) to the loader's fiber when there is work, and back
// from the loader's; each side keeps its current heap (0x00527c50 / 0x00527c54)
void owners::Q_264d20::FUN_00264d20() {
    if (FUN_0026dbf0() == (*(CoreFiber**)&DAT_00527c4c)) {
        unsigned s = m14;
        unsigned e = m18;
        int n;
        if (s <= e) {
            n = (int)(e - s) >> 3;
        } else {
            n = ((int)(e - m1c) >> 3) + ((int)(m20 - s) >> 3);
        }
        if ((unsigned)n > 0 || m8 != 0) {
            (*(void**)&DAT_00527c54) = FUN_00266da0((*(void**)&DAT_00527c50));
            FUN_0026dc00(&DAT_00527c28);
        }
    } else {
        (*(void**)&DAT_00527c50) = FUN_00266da0((*(void**)&DAT_00527c54));
        FUN_0026dc00((*(CoreFiber**)&DAT_00527c4c));
    }
}

namespace fn_fa1126e6 {

// 0x00264e10 FUN_00264e10 (81 B): matches/0x00264e10.cpp
// sym: ?Push@Queue_264e10@fn_fa1126e6@@QAE_NPAUPair_264e10@2@@Z
bool Queue_264e10::Push(Pair_264e10* value) {
    Pair_264e10* p = mNext;
    if (p < mLimit) {
        if (p != 0) {
            p->a = value->a;
            p->b = value->b;
        }
        mNext = (Pair_264e10*)((char*)mNext + 8);
        if (mNext == mLimit)
            mNext = mEndQueue;
        if (mBegin == (hulk_uintptr)mNext)
            mNext = (Pair_264e10*)((char*)mNext + (((char*)mLimit - (char*)mEndQueue) >> 3) * 8);
        return true;
    }
    return false;
}


// 0x00264ff0 FUN_00264ff0 (64 B): matches/0x00264ff0.cpp
// sym: ?FUN_00264ff0@fn_fa1126e6@@YIXPAVOwner_264ff0@1@@Z
// Same code shape as 0x002366e0 (propagated; names are from that function)
void __fastcall FUN_00264ff0(Owner_264ff0* self) {
    Temp_264ff0 t;
    t.Init_002314a0(self);
    Item_264ff0* item = t.First_00231640();
    while (item) {
        item->V1();
        item = t.Next_002314c0();
    }
    ((owners::X_231070 *)self)->FUN_00231070();
}


// 0x002650e0 FUN_002650e0 (64 B): matches/0x002650e0.cpp
// sym: ?FUN_002650e0@fn_fa1126e6@@YIXPAVOwner_2650e0@1@@Z
// Same code shape as 0x002366e0 (propagated; names are from that function)
void __fastcall FUN_002650e0(Owner_2650e0* self) {
    Temp_2650e0 t;
    t.Init_002314a0(self);
    Item_2650e0* item = t.First_00231640();
    while (item) {
        item->V1();
        item = t.Next_002314c0();
    }
    ((owners::X_231070 *)self)->FUN_00231070();
}


// 0x00265190 FUN_00265190 (122 B): equivalent/0x00265190.cpp
// sym: ?FUN_00265190@Queue_265190@fn_fa1126e6@@QAEXPAVReleasable_265190@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00265190 @ 0x00265190
void Queue_265190::FUN_00265190(Releasable_265190* obj) {
    if (!obj)
        return;
    hulk_uintptr count;
    if (ring.head <= ring.tail)
        count = ring.tail - ring.head;
    else
        count = (ring.tail - ring.start) + (ring.end - ring.head);
    if (count == 0 && pending == 0) {
        obj->v3();
        obj->v1();
        return;
    }
    Entry_265190 e;
    obj->v0();
    e.tag = 0;
    e.obj = obj;
    ring.FUN_00264e10(&e);
}

} // namespace fn_fa1126e6

// 0x00265210 FUN_00265210 (35 B): matches/0x00265210.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?run@C_265210@fn_00265210@@QAEXPAVA_265210@2@PAX@Z
namespace fn_00265210 {
class D {
  public:
    void Fng_00231590(void*, int, void*);
};
class A_265210 {
  public:
    virtual void f();
};
class C_265210 {
    char pad[0x10];
    D* m;

  public:
    void run(A_265210* a, void* b);
};
void A_265210::f() {}
void C_265210::run(A_265210* a, void* b) {
    D* mm = m;
    a->f();
    mm->Fng_00231590(b, 0, a);
}
} // namespace fn_00265210

namespace fn_fa1126e6 {

// 0x00265240 FUN_00265240 (57 B): matches/0x00265240.cpp
// sym: ?Run@Owner@fn_fa1126e6@@QAEXPAVObj@2@H@Z
void Owner::Run(Obj* o, hulk_intptr n) {
    unsigned __int64 v = Calc_00267340(n, 0, 0);
    Worker* w = worker;
    o->Fn();
    w->Do_00231590((unsigned)v, (unsigned)(v >> 32), o);
}


// 0x00265280 FUN_00265280 (138 B): equivalent/0x00265280.cpp
// sym: ?clear@Queue_265280@fn_fa1126e6@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// FUN_00265280 @ 0x00265280
void Queue_265280::clear() {
    for (;;) {
        unsigned count;
        if ((hulk_uintptr)read <= (hulk_uintptr)write)
            count = ((int)((hulk_uintptr)write - (hulk_uintptr)read)) >> 3;
        else
            count = (((int)((hulk_uintptr)write - (hulk_uintptr)begin)) >> 3) + (((int)((hulk_uintptr)end - (hulk_uintptr)read)) >> 3);
        if (!count) break;
        Item_265280* item = read->item;
        unsigned value = read->value;
        if ((hulk_uintptr)write >= (hulk_uintptr)end) write = read;
        ++read;
        if (read == end) read = begin;
        if (item) {
            item->FUN_00266950(4);
            item->release();
        }
    }
    if (owner) ((owners::C_2666e0 *)owner)->FUN_002666e0();
}

} // namespace fn_fa1126e6

// 0x00265310 FUN_00265310 (38 B): matches/0x00265310.cpp
// sym: ?FUN_00265310@Obj_265310@owners@@QAEHH@Z
hulk_intptr owners::Obj_265310::FUN_00265310(hulk_intptr param) {
    Temp_265310 t;
    t.Fnf_00231160(value);
    return t.Fng_00231180(((int)param), 0);
}


// 0x00265340 FUN_00265340 (68 B): matches/0x00265340.cpp
// sym: ?FUN_00265340@Thing_265340@owners@@QAEHPAD@Z
hulk_intptr owners::Thing_265340::FUN_00265340(char* text) {
    if (*text == '.')
        ++text;
    unsigned long long value = Parse_00267340(text, 0, 0);
    Pair_265340 local;
    local.First_00231160(field);
    return local.Second_00231180((u32_265340)value, (u32_265340)(value >> 32));
}

namespace fn_fa1126e6 {

// 0x00265390 FUN_00265390 (390 B): equivalent/0x00265390.cpp
// sym: ?FUN_00265390@Queue_265390@fn_fa1126e6@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 124 inputs, branch coverage 30/30)
// FUN_00265390 @ 0x00265390
void Queue_265390::FUN_00265390()
{
    while (!stop) {
        int count;
        if (head > tail)
            count = (int)(tail - begin) + (int)(end - head);
        else
            count = (int)(tail - head);
        if (count == 0) {
            ((owners::Q_264d20 *)this)->FUN_00264d20();
        } else {
            Job_265390 *job = head->job;
            int arg = head->arg;
            if (tail >= end)
                tail = head;
            head = head + 1;
            if (head == end)
                head = begin;
            if (arg != 0) {
                if (ringTail < ringEnd) {
                    if (ringTail)
                        *ringTail = arg;
                    ringTail = ringTail + 1;
                    if (ringTail == ringEnd)
                        ringTail = ringBegin;
                    if (ringHead == ringTail)
                        ringTail = ringTail + (ringEnd - ringBegin);
                }
            }
            if (job != 0) {
                current = job;
                if (job->FUN_00266710() != 4) {
                    current->FUN_00266950(2);
                    const char *ext = strrchr(job->FUN_002666d0(), '.');
                    long long key = FUN_00267340(ext + 1, 0, 0);
                    Local_265390 local;
                    local.FUN_00231160(fc);
                    Sink_265390 *sink = local.FUN_00231180(key);
                    FUN_00266da0(*(int *)((const char *)job->FUN_002666d0() + 0x108));
                    sink->vfn3(job->FUN_002666d0(), job);
                    if (current->FUN_00266710() == 2)
                        current->FUN_00266950(3);
                }
                if (current->FUN_00266710() == 4)
                    current->FUN_00266950(3);
                current->vfn1();
                current = 0;
            }
        }
    }
}


// 0x00265520 FUN_00265520 (9 B): matches/0x00265520.cpp
// sym: ?FUN_00265520@fn_fa1126e6@@YAXPAX@Z
void FUN_00265520(void* p) {
    ((Obj_265520*)p)->Target_00265390();
}


// 0x00265560 FUN_00265560 (36 B): matches/0x00265560.cpp
// sym: ?target@C_265560@fn_fa1126e6@@QAEXPAVObj_265560@2@@Z
void C_265560::target(Obj_265560* p) {
    int n = ((owners::Obj_231770 *)m)->FUN_00231770((hulk_uintptr)(Obj_265560 *)p);
    while (n > 0) {
        p->g();
        --n;
    }
}


// 0x00265590 FUN_00265590 (20 B): matches/0x00265590.cpp
// sym: ?Run@A_265590@fn_fa1126e6@@QAEXXZ
void A_265590::Run() {
    x->First_00264ff0();
    y->Second_002650e0();
}

} // namespace fn_fa1126e6

// 0x002655b0 FUN_002655b0 (162 B): equivalent/0x002655b0.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ?FUN_002655b0@TaskQueue@fn_002655b0@@QAEXXZ
namespace fn_002655b0 {
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 14/14)
// FUN_002655b0 @ 0x002655b0
class Task_2655b0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

class TaskQueue {
public:
    char pad0[8];
    int busy;                 // 0x08
    char pad1[8];
    char *ring1Cur;           // 0x14
    char *ring1End;           // 0x18
    char *ring1Base;          // 0x1c
    char *ring1Limit;         // 0x20
    char pad2[4];
    Task_2655b0 **ring2Cur;          // 0x28
    Task_2655b0 **ring2End;          // 0x2c
    Task_2655b0 **ring2Base;         // 0x30
    Task_2655b0 **ring2Limit;        // 0x34
    void FUN_002655b0();
};

static hulk_intptr Ring1Count(char *cur, char *end, char *base, char *limit)
{
    if (cur <= end)
        return (end - cur) >> 3;
    return ((end - base) >> 3) + ((limit - cur) >> 3);
}

static hulk_intptr Ring2Count(Task_2655b0 **cur, Task_2655b0 **end, Task_2655b0 **base, Task_2655b0 **limit)
{
    if (cur <= end)
        return (end - cur);
    return (end - base) + (limit - cur);
}

void TaskQueue::FUN_002655b0()
{
    if (Ring1Count(ring1Cur, ring1End, ring1Base, ring1Limit) != 0 || busy != 0)
        ((owners::Q_264d20 *)this)->FUN_00264d20();
    while (Ring2Count(ring2Cur, ring2End, ring2Base, ring2Limit) != 0) {
        Task_2655b0 *t = *ring2Cur;
        if (ring2End >= ring2Limit)
            ring2End = ring2Cur;
        ring2Cur++;
        if (ring2Cur == ring2Limit)
            ring2Cur = ring2Base;
        t->v3();
        t->v1();
    }
}
} // namespace fn_002655b0

namespace fn_fa1126e6 {

// 0x002656a0 FUN_002656a0 (11 B): matches/0x002656a0.cpp
// sym: _FUN_002656a0
// Same code shape as 0x000fc1a0 (propagated; names are from that function)
// data: g_object_2656a0 = DAT_00527c58
extern "C" void __cdecl FUN_002656a0(void) {
    (*(Obj_2656a0**)&DAT_00527c58)->Target_002655b0();
}


// 0x002656b0 FUN_002656b0 (264 B): equivalent/0x002656b0.cpp
// sym: ?FUN_002656b0@Object@fn_fa1126e6@@QAEPAU12@PAUConfig_2656b0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 10/10)
// FUN_002656b0 @ 0x002656b0
Object* Object::FUN_002656b0(Config_2656b0* config) {
 a=0; b=0; c=0; interval=5000; unused=0; first=0; second=0; storage=0; begin=0; buffer=0; bufferBegin=0;
 Block_2656b0* p=(Block_2656b0*)FUN_0008d690((unsigned)sizeof(Block_2656b0));
 if(p) { unsigned n=config->first; p->FUN_00231550(n,200,n); }
 first=p;
 p=(Block_2656b0*)FUN_0008d690((unsigned)sizeof(Block_2656b0));
 if(p) { unsigned n=config->second; p->FUN_00231550(n,200,n); }
 second=p;
 unsigned n=config->count;
 if(n) { unsigned bytes=n*8; char* data=(char*)FUN_0008d6d0(bytes); storage=data; if(data) { begin=data; current=data; end=data+bytes; } else begin=0; }
 else { storage=0; begin=0; }
 char* data=(char*)FUN_0008d6d0(256); buffer=data;
 if(data) { bufferBegin=data; bufferCurrent=data; bufferEnd=data+256; } else bufferBegin=0;
 (*(CoreFiber**)&DAT_00527c4c)=FUN_0026dbf0();
 unsigned v=config->value; (*(unsigned*)&DAT_004cd504)=v;
 FUN_0026dd70(&DAT_00527c28,FUN_00265520,this,v,0);
 return this;
}


// 0x00265810 FUN_00265810 (264 B): equivalent/0x00265810.cpp
// sym: ?FUN_00265810@Manager_265810@fn_fa1126e6@@QAEXPAURequest@2@PAPAULoadRequest_265810@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 170 inputs, branch coverage 20/20)
// FUN_00265810 @ 0x00265810
void Manager_265810::FUN_00265810(Request* request,LoadRequest_265810** output) {
 request->flags |= flags;
 LoadRequest_265810* memory = (LoadRequest_265810*)FUN_00263ed0(0x130,1);
 LoadRequest_265810* task = memory ? memory->FUN_00266890(request) : 0;
 task->slot0(); task->slot0();
 if(tail < end) {
  if(tail) { tail->task = task; tail->value=0; }
  tail = tail+1;
  if(tail==end) tail=begin;
  if(head==tail) tail = tail+(end-begin);
 }
 ((owners::C_266800 *)task)->FUN_00266800((char *)(Request *)request);
 task->FUN_00266950(1);
 if(request->context) task->FUN_00266850(request->context);
 if(request->flags) {
  while(task->FUN_00266710()!=3) {
   if(task->FUN_00266710()==5) break;
   FUN_002655b0();
   thunk_FUN_00270a50();
  }
 }
 *output=task;
}


// 0x00265920 FUN_00265920 (113 B): matches/0x00265920.cpp
// sym: ?Go@C_265920@fn_fa1126e6@@QAEXPBDHH@Z
void C_265920::Go(const char* s, int x, int z) {
    S_265920 l;
    l.f = (z == 0);
    l.buf[0] = 0;
    l.a = 0;
    l.b = 0;
    l.c = 0;
    if (s)
        strncpy(l.buf, s, 0xff);
    Fn_00265810(&l, x);
}


// 0x002659a0 FUN_002659a0 (116 B): equivalent/0x002659a0.cpp
// sym: ?FUN_002659a0@W_2659a0@fn_fa1126e6@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 13 inputs, branch coverage 8/8)
// FUN_002659a0 @ 0x002659a0
void W_2659a0::FUN_002659a0(int key){
  Iter_2659a0 first;
  first.FUN_00231160(pool);
  Node* n = first.FUN_00231180(key, 0);
  while (n) {
    int count = ((owners::Obj_231770 *)pool)->FUN_00231770((hulk_uintptr)(Node *)n);
    while (count > 0) {
      n->slot1();
      count--;
    }
    Iter_2659a0 next;
    next.FUN_00231160(pool);
    n = next.FUN_00231180(key, 0);
  }
}

} // namespace fn_fa1126e6

// 0x00265a20 FUN_00265a20 (164 B): equivalent/0x00265a20.cpp [wrapped: conflict: FUN_00267340; Object]
// sym: ?FUN_00265a20@Registry_265a20@fn_00265a20@@QAEXPBD@Z
namespace fn_00265a20 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00265a20 @ 0x00265a20
struct Table_265a20;

class Object {
public:
    virtual void v0();
    virtual void v1();
};

struct Probe_265a20 {
    Table_265a20 *table;           // 0x00
    char pad04[0x14];
    void FUN_00231160(Table_265a20 *t);
    Object *FUN_00231180(unsigned int first, unsigned int second);
};

struct Table_265a20 {
};

unsigned __int64 __cdecl FUN_00267340(const char *name, int a, int b);

class Registry_265a20 {
public:
    char pad0[0xc];
    Table_265a20 *table;           // 0x0c
    void FUN_00265a20(const char *name);
};

void Registry_265a20::FUN_00265a20(const char *name)
{
    Probe_265a20 first;
    Probe_265a20 again;
    const char *key = name;
    if (*name == '.')
        key = name + 1;
    unsigned __int64 id = FUN_00267340(key, 0, 0);
    first.FUN_00231160(table);
    Object *obj = first.FUN_00231180((unsigned int)id, (unsigned int)(id >> 32));
    while (obj != 0) {
        int n = ((owners::Obj_231770 *)table)->FUN_00231770((hulk_uintptr)(Object *)obj);
        if (n > 0) {
            do {
                obj->v1();
            } while (--n != 0);
        }
        key = name;
        if (*name == '.')
            key = name + 1;
        id = FUN_00267340(key, 0, 0);
        again.FUN_00231160(table);
        obj = again.FUN_00231180((unsigned int)id, (unsigned int)(id >> 32));
    }
}
} // namespace fn_00265a20

namespace fn_fa1126e6 {

// 0x00265ad0 FUN_00265ad0 (58 B): matches/0x00265ad0.cpp
// sym: ?target@fn_fa1126e6@@YIXPAVThing_265ad0@1@@Z
void __fastcall target(Thing_265ad0* self) {
    for (;;) {
        unsigned int x = self->a, y = self->b;
        int n;
        if (x <= y)
            n = (int)(y - x) >> 3;
        else
            n = ((int)(y - self->c) >> 3) + ((int)(self->d - x) >> 3);
        if ((unsigned int)n > 0 || self->field8 != 0)
            self->step_002655b0();
        else
            break;
    }
}


// 0x00265b70 FUN_00265b70 (125 B): matches/0x00265b70.cpp
// sym: _FUN_00265b70
// data: g_obj_265b70 = DAT_00527c58
extern "C" void FUN_00265b70(Params* p) {
    if (!p) {
        Params def;
        def.a = 0x10;
        def.b = 0x80;
        def.c = 0x20;
        def.d = 0x10000;
        Obj_265b70* o = (Obj_265b70*)FUN_0008d690((int)sizeof(Obj_265b70));
        if (o) {
            (*(Obj_265b70**)&DAT_00527c58) = o->FUN_002656b0(&def);
            return;
        }
        (*(Obj_265b70**)&DAT_00527c58) = 0;
        return;
    }
    Obj_265b70* o = (Obj_265b70*)FUN_0008d690((int)sizeof(Obj_265b70));
    if (o) {
        (*(Obj_265b70**)&DAT_00527c58) = o->FUN_002656b0(p);
        return;
    }
    (*(Obj_265b70**)&DAT_00527c58) = 0;
}

} // namespace fn_fa1126e6
