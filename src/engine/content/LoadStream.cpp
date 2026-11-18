// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00263f30..0x00265bf0 (kind game, layer engine, confidence medium), dominant class content::LoadStream
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/loaders.h"
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
// (x64t14) content::LoadStream's methods on records.h ContentLoadStream (the pads put its words at their 32-bit
// offsets natively)
class LoadStream_263f50 : public ContentLoadStream {
  public:
    void Init();
};
class Obj_263fb0 : public ContentLoadStream {};
struct X_263fc0 : ContentLoadStream {};
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
// (x64t14) the stream's copy (a thiscall method that does not read the stream: 0x00264590 calls it with the stream
// in ecx; natively a free function took the stream for the destination)
struct Copy_263fd0 : ContentLoadStream { void F(void* dst, void* src, unsigned n, int mode); };
extern "C" hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr value, unsigned int alignment);   // (x64t15) as defined (MemoryPool.cpp; a C++ int (hulk_intptr, int) did not bind natively)
class Manager_2640f0 {
  public:
};
extern int getThing_00267f80();
class Target_2640f0 : public ContentLoadStream {
  public:
    void run();
};
// (x64t14) the memory stream's constructor on the record: it writes the game's vftable itself (was a local
// polymorphic stand-in, whose vftable natively was its own one-slot table)
namespace content {
struct LoadStream : ContentLoadStream {
    void FUN_00263f50();
    LoadStream(hulk_intptr a, int b);
};
}
extern "C" char DAT_0042ae9c[];
class LoadStream : public ContentLoadStream {
  public:
    LoadStream(const ContentLoadArgs* a, void* b, int c);
    void Init();
    void Destroy();
    void Setup_00264310(const char*);
    LoadStream* Target(const char*, int, int);
    void Base0_00263f50();
    void Init_00264310(const ContentLoadArgs* a);
};
extern "C" void FUN_00267070(void*);
class Obj_264230 : public ContentLoadStream {
  public:
    void target(int);
    void refresh_002640f0();
};
class Obj_264270 : public ContentLoadStream {
  public:
    void FUN_002640f0();
    bool fnB(void*, int, int, int);
};
class Stream : public ContentLoadStream {
  public:
    void FUN_00264050(char *other);
    void FUN_002640f0();
    void FUN_00264310(const char *name);
};
class Reader : public ContentLoadStream {
public:
    void FUN_00264050(void* dest);
};
void __cdecl thunk_FUN_002710d0(ContentStreamFile **out, const char *name, int a, int b, int c, int d, int e, int f);
struct X_264870 {
    int pad;
    unsigned int value;
};
extern "C" CoreFiber* __cdecl FUN_0026dbf0();
extern "C" int __cdecl FUN_00266da0(int);   // (x64t15) the heap id, as defined (unk_266950.cpp)
extern "C" void __cdecl FUN_0026dc00(CoreFiber*);
// (x64t19) the registry's ring of pending requests (decls/loaders.h: head, tail, start, end of HulkLoadEntry; the
// head was an unsigned word and the entries two words, 8 bytes, natively 16)
struct Pair_264e10 : HulkLoadEntry {
};
class Queue_264e10 {
  public:
    Pair_264e10* mBegin;
    Pair_264e10* mNext;
    Pair_264e10* mEndQueue;
    Pair_264e10* mLimit;
    bool Push(Pair_264e10* value);
};
// (x64t19) the registry's record (was gen's owners::X_264c70 / Q_264d20, 32-bit pad views): the pending ring by
// entries, the running request a pointer
struct Registry_264c70 : HulkContentRegistry {
    int FUN_00264c70();
    void FUN_00264d20();
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
struct Entry_265190 : HulkLoadEntry {   // (x64t19) a pending entry: no request, the object as its value (natively the
};                                     // int tag left the request pointer's high word unset)
struct Ring_265190 {
    Entry_265190* head;
    Entry_265190* tail;
    Entry_265190* start;
    Entry_265190* end;
    void FUN_00264e10(Entry_265190* e);
};
class Queue_265190 : public HulkContentRegistry {   // (x64t19) the registry's record (was a pad view)
public:
    Ring_265190 &ring() { return *(Ring_265190 *)&head; }
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
extern "C" unsigned __int64 __cdecl Calc_00267340(const char* text, int a, int b);   // (x64t6) the name hashed (0x00267340's `text`; was an `int`)
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
// (x64t13) the handler probe (decls/loaders.h FUN_00231160): its words, the table a pointer, the key as its two words
struct Local_265390 {
    char data[sizeof(FUN_00231160)];
    void FUN_00231160(void* table);
    Sink_265390 *FUN_00231180(unsigned int first, unsigned int second);
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
// (x64t13) the loader fiber's view of decls/loaders.h HulkContentRegistry (its pads put the words at their 32-bit
// offsets natively): the stop flag (b), the running request, the handler table, the request ring (its entries are
// HulkLoadEntry) and the 256-byte buffer used as a ring of finished requests' values
class Queue_265390 : public HulkContentRegistry {
public:
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
extern "C" void __cdecl FUN_0026dd70(void*, void*, void*, unsigned, unsigned);   // (x64t13) as defined (unk_26d480.cpp)
// (x64t8) the registry's record (decls/loaders.h HulkContentRegistry)
struct Object : HulkContentRegistry {
 Object* FUN_002656b0(Config_2656b0* config);
};
struct Request : ContentLoadArgs {};   // (x64t13) records.h: the context at +0x100 and the wait flag at +0x10c
struct LoadRequest_265810 { virtual void slot0(); LoadRequest_265810* FUN_00266890(Request*);  void FUN_00266950(int); void FUN_00266850(void*); int FUN_00266710(); };
extern "C" void* __cdecl FUN_00263ed0(unsigned int,int);
struct Entry_265810 { LoadRequest_265810* task; unsigned int value; };
// (x64t8) the registry's record (decls/loaders.h HulkContentRegistry: the flags at 0, the request ring; was a 0x13-byte
// pad, so natively the ring sat 8 bytes before the constructor's)
struct Manager_265810 : HulkContentRegistry { void FUN_002655b0(); void FUN_00265810(Request*,LoadRequest_265810**); };
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
  char pad[sizeof(FUN_00231160)];   // (x64t8) the probe's words (decls/loaders.h; 0x18 was short natively)
  void FUN_00231160(Pool_2659a0*);
  Node* FUN_00231180(int, int);
};
struct W_2659a0 {
  char pad[0xc]; void* first; Pool_2659a0* pool;   // (x64t7) the registry's words: the first table (0xc) a pointer, so the second at 0x18 natively
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
// (x64t8) the registry's record (decls/loaders.h HulkContentRegistry), allocated at its size
struct Obj_265b70 : HulkContentRegistry {
    unsigned tail;                 // +0x38 (not set by the constructor)
    Obj_265b70* FUN_002656b0(Params* p);
};
void* FUN_0008d690(int size);

// 0x00263f30 thunk_FUN_00267090 (5 B): not yet verified
// 0x00263f40 thunk_FUN_00267090 (5 B): not yet verified

// 0x00263f50 FUN_00263f50 (89 B): matches/0x00263f50.cpp
// sym: ?Init@LoadStream_263f50@fn_fa1126e6@@QAEXXZ
void LoadStream_263f50::Init() {
    file = 0;
    open = 0;
    sync = 0;
    buffered = 0;
    swap = 0;
    size = 0;
    pos = 0;
    offset = 0;
    bank = 0;
    m20 = 0;
    m24 = 0;
    buffer = 0;
    bufPos = 0;
    limit = 0;
    filled = 0;
    chunk = 0;
    pending = 0;
    unsigned int x = (*(Service_263f50**)&DAT_00527c58)->Get_00264870();
    lastTime = 0;
    interval = x / 1000;
}


// 0x00263fb0 FUN_00263fb0 (4 B): matches/0x00263fb0.cpp
// sym: ?FUN_00263fb0@fn_fa1126e6@@YIIPAVObj_263fb0@1@@Z
// Same code shape as 0x00059a30 (propagated; names are from that function)
unsigned int __fastcall FUN_00263fb0(Obj_263fb0* self) {
    return self->size;
}


// 0x00263fc0 FUN_00263fc0 (4 B): matches/0x00263fc0.cpp
// sym: @FUN_00263fc0@4
// Same code shape as 0x000862d0 (propagated; names are from that function)
extern "C" unsigned __fastcall FUN_00263fc0(X_263fc0* self) {
    return self->pos;
}


// 0x00263fd0 FUN_00263fd0 (116 B): matches/0x00263fd0.cpp
// sym: ?F@Copy_263fd0@fn_fa1126e6@@QAEXPAX0IH@Z
// data: g_pump = DAT_00527c58
void Copy_263fd0::F(void* dst, void* src, unsigned n, int mode) {
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
// sym: ?FUN_00264050@Reader@fn_fa1126e6@@QAEXPAX@Z @df4c877e83b1 @w8ec67ce6e27b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00264050 @ 0x00264050
void Reader::FUN_00264050(void* dest) {
    if (offset >= size)
        return;
    unsigned int n = chunk;
    if (offset + n >= size) {
        int rest = size - offset;
        file->Read(dest, (int)FUN_0026fd50(rest, file->GetGranularity()), 1);
        filled = rest;
        offset = offset + rest;
        return;
    }
    file->Read(dest, n, 1);
    offset += n;
    filled = n;
}


// 0x002640f0 FUN_002640f0 (65 B): matches/0x002640f0.cpp
// sym: ?run@Target_2640f0@fn_fa1126e6@@QAEXXZ
// data: gThing_2640f0 = DAT_00527c58
void Target_2640f0::run() {
    if (file) {
        if (sync) {
            file->Wait();
            return;
        }
        while (!file->IsDone()) {
            ((owners::Q_264d20 *)((*(Manager_2640f0**)&DAT_00527c58)))->FUN_00264d20();
            lastTime = getThing_00267f80();
        }
    }
}

} // namespace fn_fa1126e6

// 0x00264140 FUN_00264140 (74 B): equivalent/0x00264140.cpp
// sym: ?FUN_00264140@Converter_264140@owners@@QAEXPAEII@Z @13ade0e732d2 @w73141b7868f0 @ve310d72f3697
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
// sym: ??0LoadStream@content@fn_fa1126e6@@QAE@HH@Z @05a87e20d3c7 @wf2f750d5b988 @vaf147775a4de
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00264190 @ 0x00264190
namespace content {
LoadStream::LoadStream(hulk_intptr a, int b) {
    refs = 0;
    vftable = (void*)DAT_0042ae9c;
    FUN_00263f50();
    buffer = (char*)a;
    bank = 0;
    bufPos = 0;
    offset = 0;
    pos = 0;
    filled = 0;
    size = b;
    limit = b;
    chunk = b;
    open = 1;
    buffered = 1;
}
}


// 0x002641e0 FUN_002641e0 (66 B): matches/0x002641e0.cpp
// sym: ?Destroy@LoadStream@fn_fa1126e6@@QAEXXZ
void LoadStream::Destroy() {
    vftable = (void*)DAT_0042ae9c;
    Init();
    if (file)
        file->Release();
    if (m20)
        FUN_00267070(m20);
    if (m24)
        FUN_00267070(m24);
    vftable = (void*)DAT_003f6098;
}


// 0x00264230 FUN_00264230 (49 B): matches/0x00264230.cpp
// sym: ?target@Obj_264230@fn_fa1126e6@@QAEXH@Z
void Obj_264230::target(int amount) {
    file->Seek(pos + amount);
    pos += amount;
    if (sync)
        refresh_002640f0();
}


// 0x00264270 FUN_00264270 (76 B): matches/0x00264270.cpp
// sym: ?fnB@Obj_264270@fn_fa1126e6@@QAE_NPAXHHH@Z
bool Obj_264270::fnB(void* a, int b, int c, int d) {
    int n = b * c;
    file->Read(a, n, d);
    pos += n;
    FUN_002640f0();
    ((owners::Converter_264140 *)this)->FUN_00264140((unsigned char *)a, (unsigned int)b, (unsigned int)c);
    return true;
}

} // namespace fn_fa1126e6

// 0x002642c0 FUN_002642c0 (74 B): equivalent/0x002642c0.cpp
// sym: ?FUN_002642c0@Controller_2642c0@owners@@QAEXXZ @4d134cc2f98b @w5204fcc7a6d3 @v01d55d1a92c7
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
// sym: ?FUN_00264310@Stream@fn_fa1126e6@@QAEXPBD@Z @d31e99726804 @wa5c993ebc06b @vf8792b4bcacc
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 10/10)
// FUN_00264310 @ 0x00264310
void Stream::FUN_00264310(const char *name)
{
    thunk_FUN_002710d0(&file, name, 0, 0, 1, 0, 1, 1);
    if (file != 0) {
        FUN_002640f0();
        if (file->IsOpen()) {
            open = 1;
            unsigned int n = file->GetSize();
            size = n;
            if (!buffered) {
                limit = n;
                chunk = n;
                return;
            }
            if (n < 0x20000) {
                bank = 1;
                chunk = n;
            } else {
                chunk = 0x20000;
            }
            FUN_00264050(((char*)((char*)&DAT_004e7c28)) + ((bank == 0) << 17));
            FUN_002640f0();
            return;
        }
    }
    open = 0;
}


// 0x00264430 FUN_00264430 (59 B): matches/0x00264430.cpp
// sym: ?Target@LoadStream@fn_fa1126e6@@QAEPAV12@PBDHH@Z
LoadStream* LoadStream::Target(const char* a, int b, int c) {
    refs = 0;
    vftable = (void*)DAT_0042ae9c;
    Init();
    sync = 1;
    buffered = (c == 1);
    Setup_00264310(a);
    return this;
}

} // namespace fn_fa1126e6

// 0x00264470 content::LoadStream::vfunc_2 (86 B): matches/0x00264470.cpp [wrapped: conflict: LoadStream]
// sym: ?f2@LoadStream@fn_00264470@@UAEPAV12@E@Z
namespace fn_00264470 {
// (x64t14) the destructor slot of content::LoadStream's vftable: a polymorphic view (its slot 2 is this), the words
// read through records.h ContentLoadStream (pads after the vftable put them at their 32-bit offsets natively)
class LoadStream {
  public:
    virtual void f0();
    virtual void f1();
    virtual LoadStream* f2(unsigned char);
};
extern int hulk_at_0042ae9c, hulk_at_003f6098;
struct ThisCall_002640f0 {
    void Init_002640f0();
};
extern "C" void FUN_00267070(void*);
void Destroy_00263f30(LoadStream*);
LoadStream* LoadStream::f2(unsigned char flag) {
    ContentLoadStream* s = (ContentLoadStream*)this;
    s->vftable = (void*)&hulk_at_0042ae9c;
    ((ThisCall_002640f0*)(this))->Init_002640f0();
    if (s->file)
        s->file->Release();
    if (s->m20)
        FUN_00267070(s->m20);
    if (s->m24)
        FUN_00267070(s->m24);
    s->vftable = (void*)&hulk_at_003f6098;
    if (flag & 1)
        Destroy_00263f30(this);
    return this;
}
} // namespace fn_00264470

namespace fn_fa1126e6 {

// 0x002644d0 FUN_002644d0 (59 B): matches/0x002644d0.cpp
// sym: ??0LoadStream@fn_fa1126e6@@QAE@PBUContentLoadArgs@@PAXH@Z
LoadStream::LoadStream(const ContentLoadArgs* a, void* b, int c) {
    refs = 0;
    vftable = (void*)DAT_0042ae9c;
    Base0_00263f50();
    buffered = (c == 1);
    sync = a->wait;
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
// sym: ?FUN_00264590@Stream@fn_00264590@@QAE_NPBXHHH@Z @898fe5807097 @w57d277de22da @v455d9d67e857
namespace fn_00264590 {
// STATUS: equivalent (tools/equiv.py level 3: 2949 inputs, branch coverage 28/28)
// FUN_00264590 @ 0x00264590

struct Clock_264590 {
};
unsigned int FUN_00267f80();

// (x64t14) on records.h ContentLoadStream (the read from the banks; `data` is the destination)
class Stream : public ContentLoadStream {
public:
    void FUN_00263fd0(const void *src, char *dst, int n, int flag);
    void FUN_00264050(char *other);
    bool FUN_00264590(const void *data, int count, int size, int flag);
};

bool Stream::FUN_00264590(const void *data, int count, int size, int flag)
{
    int n = count * size;
    unsigned int used = bufPos;
    pending += n;
    if (used + n <= limit) {
        FUN_00263fd0(data, buffer + used, n, flag);
        bufPos += n;
        pos += n;
    } else {
        const char *src = (const char *)data;
        while (n > 0) {
            int chunk = n;
            if (bufPos + n > limit)
                chunk = limit - bufPos;
            FUN_00263fd0(src, buffer + bufPos, chunk, flag);
            bufPos += chunk;
            pos += chunk;
            n -= chunk;
            src += chunk;
            if (n <= 0)
                break;
            if (file != 0) {
                if (sync) {
                    file->Wait();
                } else {
                    while (!file->IsDone()) {
                        ((owners::Q_264d20 *)((*(Clock_264590**)&DAT_00527c58)))->FUN_00264d20();
                        lastTime = FUN_00267f80();
                    }
                }
            }
            int next = (bank == 0);
            bufPos = 0;
            limit = filled;
            buffer = ((char*)((char*)&DAT_004e7c28)) + (next << 17);
            bank = next;
            FUN_00264050(((char*)((char*)&DAT_004e7c28)) + ((next == 0) << 17));
        }
    }
    if (swap)
        ((owners::Converter_264140 *)this)->FUN_00264140((unsigned char *)data, (unsigned int)count, (unsigned int)size);
    if (!sync) {
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
// sym: ?FUN_002647e0@X_2647e0@owners@@QAE_NPAXHHH@Z
bool owners::X_2647e0::FUN_002647e0(void* x, int y, int z, int w) {   // (x64t15) the readers' arguments (were pointer-sized integers: natively the
                                                                    // loaders' calls did not bind)
    if (!a)
        return 0;
    if (!b)
        return FUN_00264270(x, y, z, w);
    return FUN_00264590(x, y, z, w);
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
// sym: ?FUN_00264c70@Registry_264c70@fn_fa1126e6@@QAEHXZ
namespace fn_fa1126e6 {
int Registry_264c70::FUN_00264c70() {
    HulkLoadEntry* edx = head;
    HulkLoadEntry* eax = tail;
    int count;
    if (edx <= eax) {
        count = (int)(eax - edx);
    } else {
        count = (int)(eax - begin) + (int)(end - edx);
    }
    if ((unsigned int)count > 0u || current != 0)
        return 1;
    return 0;
}
} // namespace fn_fa1126e6


// 0x00264d20 FUN_00264d20 (125 B): matches/0x00264d20.cpp
// sym: ?FUN_00264d20@Registry_264c70@fn_fa1126e6@@QAEXXZ
// data: g_cur_264d20 = DAT_00527c4c, g_obj_264d20 = DAT_00527c28
// the content loader's yield: from the game's fiber (0x00527c4c) to the loader's fiber when there is work, and back
// from the loader's; each side keeps its current heap (0x00527c50 / 0x00527c54)
namespace fn_fa1126e6 {
void Registry_264c70::FUN_00264d20() {
    if (FUN_0026dbf0() == (*(CoreFiber**)&DAT_00527c4c)) {
        HulkLoadEntry* s = head;
        HulkLoadEntry* e = tail;
        int n;
        if (s <= e) {
            n = (int)(e - s);
        } else {
            n = (int)(e - begin) + (int)(end - s);
        }
        if ((unsigned)n > 0 || current != 0) {
            DAT_00527c54 = FUN_00266da0(DAT_00527c50);
            FUN_0026dc00(&DAT_00527c28);
        }
    } else {
        DAT_00527c50 = FUN_00266da0(DAT_00527c54);
        FUN_0026dc00((*(CoreFiber**)&DAT_00527c4c));
    }
}
} // namespace fn_fa1126e6

namespace fn_fa1126e6 {

// 0x00264e10 FUN_00264e10 (81 B): matches/0x00264e10.cpp
// sym: ?Push@Queue_264e10@fn_fa1126e6@@QAE_NPAUPair_264e10@2@@Z
bool Queue_264e10::Push(Pair_264e10* value) {
    Pair_264e10* p = mNext;
    if (p < mLimit) {
        if (p != 0) {
            p->task = value->task;
            p->value = value->value;
        }
        mNext = mNext + 1;
        if (mNext == mLimit)
            mNext = mEndQueue;
        if (mBegin == mNext)
            mNext = mNext + (mLimit - mEndQueue);
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
// sym: ?FUN_00265190@Queue_265190@fn_fa1126e6@@QAEXPAVReleasable_265190@2@@Z @e029440ee375 @w6827aed81182 @v25f101ec1515
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00265190 @ 0x00265190
void Queue_265190::FUN_00265190(Releasable_265190* obj) {
    if (!obj)
        return;
    hulk_uintptr count;
    if (ring().head <= ring().tail)
        count = ring().tail - ring().head;
    else
        count = (ring().tail - ring().start) + (ring().end - ring().head);
    if (count == 0 && current == 0) {
        obj->v3();
        obj->v1();
        return;
    }
    Entry_265190 e;
    obj->v0();
    e.task = 0;
    e.value = (hulk_uintptr)obj;
    ring().FUN_00264e10(&e);
}

} // namespace fn_fa1126e6

// 0x00265210 FUN_00265210 (35 B): matches/0x00265210.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?run@C_265210@fn_00265210@@QAEXPAVA_265210@2@I@Z
namespace fn_00265210 {
class D {
  public:
    void Fng_00231590(unsigned int, unsigned int, void*);   // (x64t7) the key first (0x00231590's own signature; was a pointer)
};
class A_265210 {
  public:
    virtual void f();
};
class C_265210 {
    // (x64t7) the registry's words (its constructor 0x002656b0's view, `Object`): the first table at 0xc is a
    // pointer, so natively the second (m, 0x10) is at 0x18 (was a 0x10-byte pad: natively it read the first table)
    char pad[0xc];
    void* first;
    D* m;

  public:
    void run(A_265210* a, unsigned int b);   // (x64t7) b: the chunk id the handler is registered under (was a pointer)
};
void A_265210::f() {}
void C_265210::run(A_265210* a, unsigned int b) {
    D* mm = m;
    a->f();
    mm->Fng_00231590(b, 0, a);
}
} // namespace fn_00265210

namespace fn_fa1126e6 {

// 0x00265240 FUN_00265240 (57 B): matches/0x00265240.cpp
// sym: ?Run@Owner@fn_fa1126e6@@QAEXPAVObj@2@H@Z
void Owner::Run(Obj* o, hulk_intptr n) {
    unsigned __int64 v = Calc_00267340((const char*)n, 0, 0);
    Worker* w = worker;
    o->Fn();
    w->Do_00231590((unsigned)v, (unsigned)(v >> 32), o);
}


// 0x00265280 FUN_00265280 (138 B): equivalent/0x00265280.cpp
// sym: ?clear@Queue_265280@fn_fa1126e6@@QAEXXZ @4eeeea257599 @we95566e7bfdd
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
// sym: ?FUN_00265310@Obj_265310@owners@@QAEPAXI@Z
void* owners::Obj_265310::FUN_00265310(unsigned int param) {   // (x64t15) the loader as a pointer (was an integer: natively unbound for the callers)
    FUN_00231160 t((hulk_intptr)value);   // (x64t8) the probe by its constructor's address (decls/loaders.h; was 0x18 bytes, short natively, and unbound)
    return t.FUN_00231180(param, 0);
}


// 0x00265340 FUN_00265340 (68 B): matches/0x00265340.cpp
// sym: ?FUN_00265340@Thing_265340@owners@@QAEHPAD@Z
hulk_intptr owners::Thing_265340::FUN_00265340(char* text) {
    if (*text == '.')
        ++text;
    unsigned long long value = Parse_00267340(text, 0, 0);
    FUN_00231160 local((hulk_intptr)field);   // (x64t8) as 0x00265310's
    return (hulk_intptr)local.FUN_00231180((u32_265340)value, (u32_265340)(value >> 32));
}

namespace fn_fa1126e6 {

// 0x00265390 FUN_00265390 (390 B): equivalent/0x00265390.cpp
// sym: ?FUN_00265390@Queue_265390@fn_fa1126e6@@QAEXXZ @207b6f25a6c3 @wc01adbc99001 @v08609b03e395
// STATUS: equivalent (tools/equiv.py level 3: 124 inputs, branch coverage 30/30)
// FUN_00265390 @ 0x00265390
void Queue_265390::FUN_00265390()
{
    while (!b) {
        int count;
        if (head > tail)
            count = (int)(tail - begin) + (int)(end - head);
        else
            count = (int)(tail - head);
        if (count == 0) {
            ((owners::Q_264d20 *)this)->FUN_00264d20();
        } else {
            Job_265390 *job = (Job_265390 *)head->task;
            hulk_intptr arg = (hulk_intptr)head->value;   // (x64t19) a task pointer natively
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
                    ((Job_265390 *)current)->FUN_00266950(2);
                    const char *ext = strrchr(job->FUN_002666d0(), '.');
                    long long key = FUN_00267340(ext + 1, 0, 0);
                    Local_265390 local;
                    local.FUN_00231160(first);
                    Sink_265390 *sink = local.FUN_00231180((unsigned int)key, (unsigned int)(key >> 32));
                    // (x64t13) the request's kind selects the heap (0x00266da0 as defined: C, a word)
                    FUN_00266da0((int)((const ContentLoadArgs *)job->FUN_002666d0())->kind);
                    sink->vfn3(job->FUN_002666d0(), job);
                    if (((Job_265390 *)current)->FUN_00266710() == 2)
                        ((Job_265390 *)current)->FUN_00266950(3);
                }
                if (((Job_265390 *)current)->FUN_00266710() == 4)
                    ((Job_265390 *)current)->FUN_00266950(3);
                ((Job_265390 *)current)->vfn1();
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
// sym: ?FUN_002655b0@TaskQueue@fn_002655b0@@QAEXXZ @d13277cca01d @w8a93d35f8459 @vd7258cdb6e0b
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

// (x64t19) the content registry's record (decls/loaders.h HulkContentRegistry; was a pad view: natively the running
// request is a pointer and the rings 8 to 0x20 bytes further on): the pending requests' ring (8-byte entries on the
// 32-bit builds, counted by entry) and the finished tasks' ring
class TaskQueue : public HulkContentRegistry {
public:
    Task_2655b0 **&ring2Cur() { return *(Task_2655b0 ***)&ringHead; }
    Task_2655b0 **&ring2End() { return *(Task_2655b0 ***)&ringTail; }
    Task_2655b0 **ring2Base() { return (Task_2655b0 **)ringBegin; }
    Task_2655b0 **ring2Limit() { return (Task_2655b0 **)ringEnd; }
    void FUN_002655b0();
};

static hulk_intptr Ring1Count(HulkLoadEntry *cur, HulkLoadEntry *end, HulkLoadEntry *base, HulkLoadEntry *limit)
{
    if (cur <= end)
        return end - cur;
    return (end - base) + (limit - cur);
}

static hulk_intptr Ring2Count(Task_2655b0 **cur, Task_2655b0 **end, Task_2655b0 **base, Task_2655b0 **limit)
{
    if (cur <= end)
        return (end - cur);
    return (end - base) + (limit - cur);
}

void TaskQueue::FUN_002655b0()
{
    if (Ring1Count(head, tail, begin, end) != 0 || current != 0)
        ((owners::Q_264d20 *)this)->FUN_00264d20();
    while (Ring2Count(ring2Cur(), ring2End(), ring2Base(), ring2Limit()) != 0) {
        Task_2655b0 *t = *ring2Cur();
        if (ring2End() >= ring2Limit())
            ring2End() = ring2Cur();
        ring2Cur()++;
        if (ring2Cur() == ring2Limit())
            ring2Cur() = ring2Base();
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
// sym: ?FUN_002656b0@Object@fn_fa1126e6@@QAEPAU12@PAUConfig_2656b0@2@@Z @cec56271febd @w6f98310057fa @vdcb55796e93d
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 10/10)
// FUN_002656b0 @ 0x002656b0
Object* Object::FUN_002656b0(Config_2656b0* config) {
 a=0; b=0; c=0; interval=5000; current=0; first=0; second=0; head=0; tail=0; ringHead=0; ringTail=0;
 Block_2656b0* p=(Block_2656b0*)FUN_0008d690((unsigned)sizeof(Block_2656b0));
 if(p) { unsigned n=config->first; p->FUN_00231550(n,200,n); }
 first=p;
 p=(Block_2656b0*)FUN_0008d690((unsigned)sizeof(Block_2656b0));
 if(p) { unsigned n=config->second; p->FUN_00231550(n,200,n); }
 second=p;
 unsigned n=config->count;
 // (x64t8) the request ring's entries by their size (8 bytes on the 32-bit builds; each holds a pointer)
 if(n) { unsigned bytes=n*(unsigned)sizeof(HulkLoadEntry); HulkLoadEntry* data=(HulkLoadEntry*)FUN_0008d6d0(bytes); head=data; if(data) { tail=data; begin=data; end=(HulkLoadEntry*)((char*)data+bytes); } else tail=0; }
 else { head=0; tail=0; }
 hulk_intptr* data=(hulk_intptr*)FUN_0008d6d0(256); ringHead=data;
 if(data) { ringTail=data; ringBegin=data; ringEnd=(hulk_intptr*)((char*)data+256); } else ringTail=0;
 (*(CoreFiber**)&DAT_00527c4c)=FUN_0026dbf0();
 unsigned v=config->value; (*(unsigned*)&DAT_004cd504)=v;
 FUN_0026dd70(&DAT_00527c28,(void*)&FUN_00265520,this,v,0);   // (x64t13) the fiber entry by its definition
 return this;
}


// 0x00265810 FUN_00265810 (264 B): equivalent/0x00265810.cpp
// sym: ?FUN_00265810@Manager_265810@fn_fa1126e6@@QAEXPAURequest@2@PAPAULoadRequest_265810@2@@Z @f1975c8f97b4 @w86e686969579 @vc8e8ebc7b05f
// STATUS: equivalent (tools/equiv.py level 3: 170 inputs, branch coverage 20/20)
// FUN_00265810 @ 0x00265810
void Manager_265810::FUN_00265810(Request* request,LoadRequest_265810** output) {
 HULK_SIZE32(ContentLoadRequest, 0x130);
 request->wait |= a;   // (x64t8) the registry's first flag
 LoadRequest_265810* memory = (LoadRequest_265810*)FUN_00263ed0(sizeof(ContentLoadRequest),1);   // (x64t13) 0x130
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
 if(request->wait) {
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
// sym: ?FUN_002659a0@W_2659a0@fn_fa1126e6@@QAEXH@Z @d43238c65b41 @w28ae076ea759 @v8c7ac955b2cc
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
// sym: ?FUN_00265a20@Registry_265a20@fn_00265a20@@QAEXPBD@Z @1890a3036cc2 @we8cb5ebab5b7 @v39ac4c7f11fc
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
    char pad04[sizeof(FUN_00231160) - sizeof(void*)];   // (x64t8) the probe's words (decls/loaders.h; was 0x14, short natively)
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
