// eq64 (integ2, D102): a heap id parameter annotated HULK_RANGE(0, 45) (DAT_00527c60's 46 slots; cited): drawn in range,
// the fuzzed out-of-table ids that crashed the 64-bit run (a negative index) are gone.
// object 0x00266950..0x00267050 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f49c50bb {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f49c50bb {} using namespace fn_f49c50bb;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f49c50bb {
class Ref_266950 {
  public:
    virtual void A();
    virtual void B();
};
extern "C" int FUN_00267f80();
class Obj_266950 {
  public:
    char pad0[12];
    int a;
    int b;
    int mode;
    char pad18[4];
    Ref_266950* ref;
    void F(int mode);
};
class Inner_2669c0 {
  public:
    virtual void f();
    virtual void g();
};
// (x64t14) the chunk reader's methods on records.h ContentChunkReader (the stream pointer natively at +0x288; 0x002669f0
// passed it to 0x00263fc0 as an int) and the stream's on ContentLoadStream (its byte-order flag at +0xf)
class Outer_2669c0 : public ContentChunkReader {};
typedef unsigned int u32_2669f0;
class Thing_2669f0 : public ContentChunkReader {};
// (x64t15) whether the innermost chunk has data left: the loaders declare it `bool` (it returns 0 / 1); the 64-bit
// builds return that, so their calls bind (the 32-bit object keeps the 32-bit result its bytes need)
#if defined(HULK_PTR64)
typedef bool Ret_2669f0;
#else
typedef u32_2669f0 Ret_2669f0;
#endif
extern "C" u32_2669f0 __fastcall FUN_00263fc0(ContentLoadStream*);
typedef unsigned int uint_266a30;
class Stream : public ContentLoadStream {
  public:
    uint_266a30 FUN_00263fc0();
};
struct Ref_266cb0 {
    virtual void f0();
};
struct Entry_266a30 {
    uint_266a30 value;
    uint_266a30 second;
    uint_266a30 third;
    uint_266a30 position;
};
struct Object {
    char prefix[0x70];
    Entry_266a30 entries[33];
    uint_266a30 index;
    Stream* stream;
    uint_266a30 FUN_00266a30();
};
class Manager_266b30 {
  public:
    int Get_00263fc0();
};
struct E_266b30 {
    int a, b, c, d;
};
class Obj_266b30 {
  public:
    char pad0[0x80];
    E_266b30 e[1];
    char pad1[0x280 - 0x90];
    int count;
    Manager_266b30* mgr;
    int Target(int);
};
struct Context { int FUN_00263fc0();  };
struct State { char pad[0x88]; struct Entry { int first; int second; char rest[8]; } entries[31]; char spare[8]; int index; Context* context; void FUN_00266be0(); };
struct C_266c30 {
    char pad[0x280];
    int idx;
};
struct C_266c40 {
    char pad[0x280];
    int count;
};
class CAgent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(int a);
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};
class Obj_266cb0 : public ContentChunkReader {
  public:
    Obj_266cb0* Init(Stream* s);
    void Next_00266b30(unsigned int v);
};
struct Manager {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int value);
};
extern "C" void FUN_00270380();
extern "C" void FUN_00270530();
class Item_266e00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* Get(int);
};
typedef int(__cdecl* Callback_266e00)(int, int, int, int);
class Entry_266eb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void* Get(int, int);
};
typedef int(__cdecl* Callback_266eb0)(int, int, int, int);
struct C_266f00 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(void*);
};
class Item_266f20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void h();
    virtual int g(void*);
};
class Item_266f50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool Match(void*);
};
class Node_266f50 {
  public:
    Item_266f50* item;
    Node_266f50* child;
    Node_266f50* next;
};
class Item_266f90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual bool Test(int);
};
struct Node {
    Item_266f90* item;
    Node* child;
    Node* next;
};


// 0x00266950 FUN_00266950 (69 B): matches/0x00266950.cpp
// sym: ?F@Obj_266950@fn_f49c50bb@@QAEXH@Z
void Obj_266950::F(int mode) {
    switch (mode) {
    case 2:
        a = FUN_00267f80();
        break;
    case 3:
        b = FUN_00267f80();
        if (ref)
            ref->B();
        ref = 0;
        break;
    }
    this->mode = mode;
}


// 0x002669c0 FUN_002669c0 (11 B): matches/0x002669c0.cpp
// sym: ?target@fn_f49c50bb@@YIXPAVOuter_2669c0@1@@Z
void __fastcall target(Outer_2669c0* self) {
    ((Inner_2669c0*)self->stream)->g();
}

} // namespace fn_f49c50bb

// 0x002669d0 FUN_002669d0 (19 B): matches/0x002669d0.cpp
// sym: ?FUN_002669d0@Copy_2669d0@owners@@QAEXPBD@Z
void owners::Copy_2669d0::FUN_002669d0(const char* source) {
    strncpy((char*)this, source, 0x7f);
}

namespace fn_f49c50bb {

// 0x002669f0 FUN_002669f0 (59 B): matches/0x002669f0.cpp
// sym: ?FUN_002669f0@fn_f49c50bb@@YIIPAVThing_2669f0@1@@Z
Ret_2669f0 __fastcall FUN_002669f0(Thing_2669f0* self) {
    u32_2669f0* p = (u32_2669f0*)((char*)self + (self->index + 8) * 16);
    if (p[2] > p[1]) {
        u32_2669f0 value = FUN_00263fc0(self->stream);
        if (value < p[3] + p[2])
            return 1;
    }
    return 0;
}


// 0x00266a30 FUN_00266a30 (245 B): matches/0x00266a30.cpp
// sym: ?FUN_00266a30@Object@fn_f49c50bb@@QAEIXZ
uint_266a30 Object::FUN_00266a30() {
    ++index;
    if (index != 0) {
        uint_266a30 end = entries[index].second + entries[index].position;
        if (stream->FUN_00263fc0() < end) {
            uint_266a30 current = stream->FUN_00263fc0();
            ((owners::S_264510 *)stream)->FUN_00264510((unsigned)(end - current));
        }
    }
    uint_266a30 pos = stream->FUN_00263fc0();
    entries[index + 1].position = pos;
    uint_266a30 value;
    ((owners::X_2647e0 *)stream)->FUN_002647e0((void*)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    entries[index + 1].value = value;
    ((owners::X_2647e0 *)stream)->FUN_002647e0((void*)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    entries[index + 1].second = value;
    ((owners::X_2647e0 *)stream)->FUN_002647e0((void*)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    entries[index + 1].third = value;
    return entries[index + 1].value;
}


// 0x00266b30 FUN_00266b30 (168 B): matches/0x00266b30.cpp
// sym: ?Target@Obj_266b30@fn_f49c50bb@@QAEHH@Z
int Obj_266b30::Target(int arg) {
    count++;
    e[count].d = mgr->Get_00263fc0() - 4;
    e[count].a = arg;
    ((owners::X_2647e0 *)mgr)->FUN_002647e0((void*)(&arg), (hulk_intptr)1, 4, (hulk_intptr)1);
    e[count].b = arg;
    ((owners::X_2647e0 *)mgr)->FUN_002647e0((void*)(&arg), (hulk_intptr)1, 4, (hulk_intptr)1);
    e[count].c = arg;
    return e[count].a;
}


// 0x00266be0 FUN_00266be0 (73 B): equivalent/0x00266be0.cpp
// sym: ?FUN_00266be0@State@fn_f49c50bb@@QAEXXZ @158715ec4b9c @wae1bfe290291 @v1b92c6ca9389
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00266be0 @ 0x00266be0
void State::FUN_00266be0() { int first = entries[index].first; int second = entries[index].second; int used = context->FUN_00263fc0(); ((owners::S_264510 *)context)->FUN_00264510((unsigned)(first + second - used)); --index; }


// 0x00266c30 FUN_00266c30 (16 B): matches/0x00266c30.cpp
// sym: ?FUN_00266c30@fn_f49c50bb@@YIHPAUC_266c30@1@@Z
int __fastcall FUN_00266c30(C_266c30* p) {
    return *(int*)((char*)p + ((p->idx + 8) << 4));
}


// 0x00266c40 FUN_00266c40 (20 B): matches/0x00266c40.cpp
// sym: ?target@fn_f49c50bb@@YIHPAUC_266c40@1@@Z
int __fastcall target(C_266c40* p) {
    return *(int*)((char*)p + 0x84 + p->count * 0x10) - 0xc;
}

} // namespace fn_f49c50bb

// 0x00266c60 FUN_00266c60 (43 B): equivalent/0x00266c60.cpp [wrapped: conflict: Object]
// sym: ?FUN_00266c60@Object@fn_00266c60@@QAEHXZ @a4d0cf28f476 @w0f9d2842e98f @v229bd0bf4bdb
namespace fn_00266c60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00266c60 @ 0x00266c60
struct Counter { int FUN_00263fc0(); }; struct Object { char pad0[0x8c]; struct Entry { int value; char pad[12]; } entries[31]; char pad1[0x280 - 0x8c - 31*16]; int index; Counter* counter; int FUN_00266c60(); }; int Object::FUN_00266c60() { int result = counter->FUN_00263fc0(); return result - 12 - entries[index].value; }
} // namespace fn_00266c60


// 0x00266c90 FUN_00266c90 (7 B): matches/0x00266c90.cpp
// sym: ?FUN_00266c90@Target_266c90@owners@@QAEPAXXZ
void* owners::Target_266c90::FUN_00266c90() {   // (x64t16) the reader's stream
    return value;
}

namespace fn_f49c50bb {

// 0x00266ca0 FUN_00266ca0 (3 B): matches/0x00266ca0.cpp
// sym: ?vfunc_7@CAgent@fn_f49c50bb@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void CAgent::vfunc_7(int a) {
    (void)a;
}


// 0x00266cb0 FUN_00266cb0 (103 B): matches/0x00266cb0.cpp
// sym: ?Init@Obj_266cb0@fn_f49c50bb@@QAEPAV12@PAVStream@2@@Z
Obj_266cb0* Obj_266cb0::Init(Stream* s) {
    unsigned int v;
    index = -1;
    stream = s;
    name[0] = 0;
    ((Ref_266cb0*)s)->f0();
    ((owners::X_2647e0 *)stream)->FUN_002647e0((void*)(&v), (hulk_intptr)4, 1, (hulk_intptr)1);
    if (v == 0x503344ff) {
        stream->swap = (stream->swap == 0);
        v = 0xff443350;
    }
    Next_00266b30(v);
    return this;
}


// 0x00266d70 FUN_00266d70 (30 B): equivalent/0x00266d70.cpp
// sym: _FUN_00266d70 @a678cb81575b @wa87e53988893 @v6ccecf93c85a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00266d70 @ 0x00266d70
extern "C" void FUN_00266d70()
{
    FUN_00270380();
    (*(unsigned char*)&DAT_00527f5c) = 0;
    (*(Manager**)&DAT_00527f58)->slot2(0);
    FUN_00270530();
}


// 0x00266d90 FUN_00266d90 (6 B): matches/0x00266d90.cpp
// sym: _FUN_00266d90
// Same code shape as 0x00085cd0 (propagated; names are from that function)
extern "C" int FUN_00266d90(void) {
    return (*(int*)&DAT_00527f60);
}


// 0x00266da0 FUN_00266da0 (16 B): matches/0x00266da0.cpp
// sym: _FUN_00266da0
// Same code shape as 0x002474f0 (propagated; names are from that function)
// data: g_ptr = DAT_00527f60
// (x64t15) the current heap's id (DAT_00527f60, 4 bytes: 0x00266d90 returns it as an int and 0x00266e00 allocates
// from the heap it names; the callers pass 1, 0xb, 0xd, ...): set, the previous one returned. It was a pointer, which
// natively wrote 8 bytes into the 4-byte item.
extern "C" int __cdecl FUN_00266da0(int value) {
    int old = (*(int*)&DAT_00527f60);
    (*(int*)&DAT_00527f60) = value;
    return old;
}


// 0x00266db0 FUN_00266db0 (20 B): matches/0x00266db0.cpp
// sym: _FUN_00266db0
// Same code shape as 0x00232d70 (propagated; names are from that function)
extern "C" void FUN_00266db0(int a, int b) {
    (*(int*)&DAT_00527f64) = a;
    (*(int*)&DAT_00527f68) = b;
}


// 0x00266e00 FUN_00266e00 (65 B): matches/0x00266e00.cpp
// sym: _FUN_00266e00
// data: gCallback_266e00 = DAT_00527f64, gContext = DAT_00527f68
// (integ2, D102) a: a heap id, an index into DAT_00527c60's 46 slots (0x00527c60, records.h MemoryHeapSlot[46]). Its 71
// call sites push a constant (29: 0, 1, 6, ...; 0x8d4ec, 0x1e8e50, 0x20197a) or a register holding the current heap
// (0x004cdbb0), a parameter or a field (42; 0x8d6c4, 0x1d09b6, 0x204807): HULK_RANGE(0, 45)
extern "C" void* FUN_00266e00(int a HULK_RANGE(0, 45), int b) {
    void* r = ((Item_266e00*)DAT_00527c60[a].allocator)->Get(b);
    if (!r && (*(Callback_266e00*)&DAT_00527f64))
        (*(Callback_266e00*)&DAT_00527f64)((*(int*)&DAT_00527f68), a, b, 1);
    return r;
}


// 0x00266eb0 FUN_00266eb0 (71 B): matches/0x00266eb0.cpp
// sym: _FUN_00266eb0
// data: gCallback_266eb0 = DAT_00527f64, gContext = DAT_00527f68
extern "C" void* FUN_00266eb0(int a, int b, int c) {
    void* r = ((Entry_266eb0*)DAT_00527c60[a].allocator)->Get(b, c);
    if (r == 0 && (*(Callback_266eb0*)&DAT_00527f64))
        (*(Callback_266eb0*)&DAT_00527f64)((*(int*)&DAT_00527f68), a, b, c);
    return r;
}


// 0x00266f00 FUN_00266f00 (24 B): matches/0x00266f00.cpp
// sym: _FUN_00266f00
// (integ2, D102) a: a heap id, an index into DAT_00527c60's 46 slots (0x00527c60, records.h MemoryHeapSlot[46]). Its 27
// call sites push 1 (0x201b78, 0x2adb8c) or a register holding a heap id the caller has (25; 0x267ef0, 0x269576,
// 0x26d200): HULK_RANGE(0, 45)
extern "C" int __cdecl FUN_00266f00(int a HULK_RANGE(0, 45), void* b) {
    return ((C_266f00*)DAT_00527c60[a].allocator)->f4(b);
}


// 0x00266f20 FUN_00266f20 (24 B): matches/0x00266f20.cpp
// sym: _FUN_00266f20
// (integ2, D102) index: a heap id, an index into DAT_00527c60's 46 slots (0x00527c60, records.h MemoryHeapSlot[46]). Its
// 6 call sites: 0x26ffbf, 0x2704aa, 0x277681, 0x277715, 0x277752 (registers holding the caller's heap id) and
// 0x2474e7 (one of them rejects negative ids first): HULK_RANGE(0, 45)
extern "C" int FUN_00266f20(int index HULK_RANGE(0, 45), void* value) {
    return ((Item_266f20*)DAT_00527c60[index].allocator)->g(value);
}


} // namespace (case end)
