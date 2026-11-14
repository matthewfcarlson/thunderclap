// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001c96e0..0x001cc5e0 (kind game, layer game, confidence high), dominant class CEventManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffd7287e {
#define TREE_TU_END }
namespace fn_ffd7287e {} using namespace fn_ffd7287e;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ffd7287e {
struct Details_1c9750 { char pad[0x118]; unsigned value1; unsigned value2; };
struct Texts_1c9750 { const char* FUN_000443b0(); const char* FUN_00044360(); };
struct Entry_1c9750 { char pad[0x11c]; Texts_1c9750* texts; char pad2[0x1ca0-0x120]; Details_1c9750* details; const char* FUN_00036d00(); };
struct Handle_1c9750 { void FUN_00059a50(void*); };
struct Manager_1c9750 {  Handle_1c9750* FUN_00059ba0(unsigned); };
} // namespace fn_ffd7287e
struct World { char pad[0x44]; Manager_1c9750* manager; };
namespace fn_ffd7287e {
extern "C" void __cdecl FUN_00267830(char*, const char*, unsigned);
typedef unsigned char u8_1c9920;
__int64 Make_0027b020(int);
struct ThisCall_001c9750 {
};
typedef unsigned int u32_1c9a20;
} // namespace fn_ffd7287e
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#endif
namespace fn_ffd7287e {
struct Item {
    volatile hulk_intptr a, b;
    int c, d;
    volatile int e;
    int f, g;
    Item(int x, int y, int z);
};
struct Args {
  public:
    unsigned int x;
    unsigned int y;
    void FUN_0027af50();
};
struct Argument { unsigned int value; void FUN_0027af50(); };
struct Object {
 unsigned int size, kind, field8, fieldC, field10, field14, field18, field1C;
 Object* FUN_001c9c00(Argument first, unsigned int second, unsigned int third);
};
struct Arg {
  public:
    unsigned x;
    unsigned y;
    void FUN_0027af50();
};
int __cdecl Fmt_00267760(char*, unsigned int, const char*, ...);
class Obj_1c9fb0 {
  public:
    void finish_001d1d10();
};
class This_1c9fb0 {
  public:
    char pad[0x14];
    int a;
    char pad2[0x1c];
    int b;
    Obj_1c9fb0* get_001d4c90();
};
struct X {
    int a, b, c, d, e, f;
    X(int);
};
class Thing_1ca090 {
  public:
    void finish_001d1d10();
};
Thing_1ca090* GetThing_001d4c90();
struct Obj {
  public:
    Obj();
    Obj(int x, int y);
    int a;
    int b;
    char _m_pad_8[0xc];
    int f;
    int g;
};
extern "C" int __cdecl format_00267760(char*, int, const char*, ...);
class Obj_1ca110 {
  public:
    volatile int a, b;
    char pad[8];
    int x;
    char text[64];
    volatile int p, q, r, s;
    Obj_1ca110(int u, int v, int w, int y, int z);
};
struct Record {
    unsigned int size, type, field8, fieldC, value3, value1, value2;
    Record(unsigned int first, unsigned int second, unsigned int third);
};
extern "C" int __cdecl FUN_00267760(char *, unsigned int, const char *, ...);
struct Name {
    int lo;
    int hi;
    ~Name() throw();
};
struct Request {
    int size;               // 0x00
    int kind;               // 0x04
    int f08;
    int f0c;
    int value;              // 0x10
    int f14;
    Name first;             // 0x18
    Name second;            // 0x20
    Request* Init(Name a, Name b, int v);
};
class Item_1cacc0 {
  public:
    void Finish_001d1d10();
};
Item_1cacc0* GetItem_001d4c90();
struct Pair { unsigned int low, high; };
} // namespace fn_ffd7287e
Pair __cdecl FUN_0027b020(unsigned int value);
namespace fn_ffd7287e {
typedef unsigned int u32_1caf80;
extern void __cdecl CopyText_00267760(char*, unsigned int, const char*, ...);
class Writer_1cafd0 {
  public:
    void Close_001d1d10();
};
class Mgr_1cafd0 {
  public:
    char pad[0x44];
};
class Info_1cafd0 {
  public:
    const char* Name_00036d00();
};
class Look_1cafd0 {
  public:
};
struct G_1cafd0 {
    char pad[0x44];
    Look_1cafd0* look;
};
extern G_1cafd0* hulk_at_004dd700;
Writer_1cafd0* GetWriter_001d4c90();
extern void Copy_00267760(void*, unsigned int, const char*, ...);
struct Data { int kind; int a; int b; int c; int d; char rest[0xc0]; };
struct Obj_1cb3a0 {
    char pad[4];
    int index;
};
class Item_1cb770 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_1cb770 {
    char pad[0x400];
    Item_1cb770* item;

  public:
    void Set(Item_1cb770* p);
};
struct Slot_1cb7c0 {
    bool InUse_00231ee0();
    char pad[0x28];
};
struct Obj_1cb7c0 {
    void Set_00231ad0(Slot_1cb7c0* s, int v, int z);
};
class T_1cb7c0 {
  public:
    char pad[0x24];
    Slot_1cb7c0 mSlots[0x18];
    unsigned Find() {
        for (unsigned i = 0; i < 0x18; i++)
            if (!mSlots[i].InUse_00231ee0())
                return i;
        return 0xffffffff;
    }
    unsigned Alloc(Obj_1cb7c0* o, hulk_intptr v);
};
struct Entry_1cb840 {
    char pad[0x28];
    bool IsActive_00231ee0();
};
struct Owner_1cb840 {
    char pad[0x24];
    int Target();
};
class Entry_1cb930 {
  public:
    int first;
    int second;
    char pad[0x20];
    bool Check_00231e80(int);
};
class Owner_1cb930 {
  public:
    char pad[0x24];
    Entry_1cb930 entries[24];
    bool Find(int);
};
struct QueryArg { void FUN_0027af50(); int value; };
class CEventManager_1cbb00 {
  public:
    bool Test(const char*);
};
class Function_1cbb00 {
  public:
    virtual void v0();
    virtual void v1();
};
class CActorManager_1cbb80 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_1cbb80::*MFn_1cbb80)(unsigned char);
class Function_1cbb80 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Dummy_1cbc00 {
  public:
    void Call(void*);
};
struct Entry_1cbcb0 {
    void Set_002322f0(int, int);
    void Reset_00231f20(int);
    void Finish_002324b0(int);
};
} // namespace fn_ffd7287e
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_ffd7287e {
extern "C" char __cdecl getFlag_001d04d0(const char*);
class Function_1cbe20 {
  public:
    Function_1cbe20(void*, int);
    virtual void f0();
    char pad[12];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    void* handler;
};
class Method1_1cbe20 : public Function_1cbe20 {
  public:
    virtual bool f1_001d04c0(int, int);
    Method1_1cbe20(void* p, void* h) : Function_1cbe20(p, 1) {
        handler = h;
        b = getFlag_001d04d0(((const char*)&DAT_0048e100));
        a = getFlag_001d04d0(((const char*)&DAT_0048e0e4));
    }
};
class Closure1_1cbe20 : public Method1_1cbe20 {
  public:
    virtual void f2_001cbe90(void*, void*, void*);
    void* extra;
    Closure1_1cbe20(void* p, void* q, void* h);
};
class Actor_1cbe90 {
  public:
    void fn(unsigned char);
};
class CActorManager_1cbf20 {
  public:
    void invoke(const char*);
};
class Listener {
public:
    virtual void vfunc_0();
};
struct Entry {
  public:
    char _m_pad_0[0x4];
    int type;
    char _m_pad_8[0x10];
    int first;
    int second;
    char _m_pad_20[0x3c];
    Listener* listener;
    char _m_pad_60[0x80];
};
struct Container {
    char padding[0xc];
    Entry *begin;
    Entry *end;
    bool FUN_001cb990(QueryArg key, int second);
};
class Registry {
public:
    Entry* FUN_00232840(U64 id);
};
class Obj_1cbf40 {
public:
    char pad0[8];
    int field8;
    int fieldC;
    int field10;
    char pad14[0xc];
    Listener* listener;
    char pad24[0x3d8];
    char flag3fc;
    void FUN_001cbf40(hulk_intptr value);
};
class Ref_1cbf90 {
  public:
    virtual void f0();
    virtual void Release();
};
class Worker_1cbf90 {
  public:
    void run_00232240();
    char pad[0x28];
};
class Root_1cbf90 {
  public:
    char pad0[12];
    int a;
    int b;
    int c;
    char pad14[8];
    Ref_1cbf90* r20;
    Worker_1cbf90 first;
    char padEnd[0x3b4];
    Ref_1cbf90* r400;
    void clear();
};
} // namespace fn_ffd7287e
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __cdecl qsort(void *base, unsigned int count, unsigned int size,
                              int (__cdecl *cmp)(const void *, const void *));
#endif
namespace fn_ffd7287e {
struct Item_1cbfe0 {
    int pad0;
    int type;
    char pad1[0xe0 - 8];
};
struct Event_1cbfe0 {
    int words[6];
    void FUN_001caf10(float dt);
};
struct CScenarioParams_1cbfe0 {
    CScenarioParams *FUN_001d0360(const Item_1cbfe0 *item);
};
class Node_1cbfe0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual Node_1cbfe0 *vf8(CScenarioParams *task, int arg);
    char FUN_00232ed0(Node_1cbfe0 *other);
    Node_1cbfe0 *FUN_00231a00(CScenarioParams *task);
};
class Slot_1cbfe0 {
public:
    void FUN_002322f0(int a, float dt);
    void FUN_00231f20(int a);
    void FUN_002324b0(int a);
    char pad[0x28];
};
} // namespace fn_ffd7287e
class Gfx {
public:
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
};
namespace fn_ffd7287e {
int __cdecl FUN_00266da0(int value);
void *__cdecl FUN_0008d690(unsigned int size);
int __cdecl FUN_001cb3a0(const Item_1cbfe0 *a, const Item_1cbfe0 *b);
struct ItemVec_1cbfe0 {
    Item_1cbfe0 *begin;
    Item_1cbfe0 *end;
    void FUN_001cbd40(Item_1cbfe0 *first, Item_1cbfe0 *last);
};
class ItemQueue {
public:
    void FUN_001cbfe0(float dt);
    bool FUN_001cbc20(Event_1cbfe0 *ev);
    char FUN_001cb400(Item_1cbfe0 *item);
    unsigned int FUN_001cb7c0(Node_1cbfe0 *node, CScenarioParams *task);
    char FUN_001cbcb0(float dt);

    char pad0[0xc];
    ItemVec_1cbfe0 vec;
    char pad1[8];
    char sorted;
    char pad2[3];
    Node_1cbfe0 *owner;
    Slot_1cbfe0 slots[24];
    char free[24];
    char active;
    char pad3[3];
    Node_1cbfe0 *current;
};
struct Item_1cc230 {
    char pad[0x28];
    void Init_00232240();
};
struct Obj_1cc230 {
    char pad0[0xC];
    int a;
    int b;
    char pad1[0x10];
    Item_1cc230 items[0x18];
};
} // namespace fn_ffd7287e
inline void* operator new(hulk_uintptr, void* p) throw() {
    return p;
}
namespace fn_ffd7287e {
class Owner {};
typedef void (Owner::*Fn_1cc2c0)(bool);
class Registry_1cc2c0 {
  public:
    void FUN_001cc2c0(const char* a1, Owner* a2, Fn_1cc2c0 a3);
};
class Closure1_1cc2c0 {
  public:
    Closure1_1cc2c0(const char*, Owner*, Fn_1cc2c0);
};

} // namespace fn_ffd7287e

// 0x001c96e0 FUN_001c96e0 (25 B): matches/0x001c96e0.cpp
// sym: ?FUN_001c96e0@C_1c96e0@owners@@QAEHH@Z
int owners::C_1c96e0::FUN_001c96e0(int i) {
    if (i >= 0 && i < 3)
        return ((int*)this)[2 + i];
    return 0;
}


// 0x001c9700 FUN_001c9700 (31 B): matches/0x001c9700.cpp
// sym: ?FUN_001c9700@Thing_1c9700@owners@@QAE_NHH@Z
bool owners::Thing_1c9700::FUN_001c9700(int index, int value) {
    if (index >= 0 && index < 3) {
        ((int*)this)[2 + index] = value;
        return true;
    }
    return false;
}


// 0x001c9750 FUN_001c9750 (237 B): equivalent/0x001c9750.cpp
// sym: ?FUN_001c9750@Object_1c9750@owners@@QAEPAU12@III@Z @aea657a2c84f @wa1cc9c7bb710
// STATUS: equivalent (tools/equiv.py level 3: 136 inputs, branch coverage 4/4)
// FUN_001c9750 @ 0x001c9750
owners::Object_1c9750* owners::Object_1c9750::FUN_001c9750(unsigned a, unsigned bytes, unsigned identifier) {
 unsigned char* p = reinterpret_cast<unsigned char*>(this);
 for (unsigned i=0;i<bytes;++i) p[i]=0;
 size=bytes; arg=a; id=identifier; name[0]=0; text1[0]=0;
 Entry_1c9750* entry=((Entry_1c9750 *)((owners::ThisWrap_00059c10 *)(DAT_004dd700->manager))->FUN_00059c10((void *)(hulk_uintptr)(unsigned)identifier));
 if(entry) {
 const char* s=entry->FUN_00036d00();
 FUN_00267830(name,s,0x40);
 s=entry->texts->FUN_000443b0();
 FUN_00267830(text1,s,0x20);
 s=entry->texts->FUN_00044360();
 FUN_00267830(text2,s,0x20);
 Handle_1c9750* h=DAT_004dd700->manager->FUN_00059ba0(identifier);
 h->FUN_00059a50(&extra);
 value1=0; value2=0;
 Details_1c9750* d=entry->details;
 if(d) { value1=d->value1; value2=d->value2; }
 }
 return this;
}


// 0x001c9920 FUN_001c9920 (68 B): matches/0x001c9920.cpp
// sym: ?FUN_001c9920@Obj_1c9920@owners@@QAEPAU12@HHHE@Z
owners::Obj_1c9920* owners::Obj_1c9920::FUN_001c9920(int p2, hulk_intptr p3, int p4, u8_1c9920 p5) {
    ((owners::Object_1c9750 *)(((ThisCall_001c9750*)(this))))->FUN_001c9750(1, 0xc0, (unsigned)p2);
    union U {
        __int64 q;
        struct {
            unsigned int lo, hi;
        } s;
    } u;
    u.q = Make_0027b020(((int)p3));
    a = u.s.lo;
    b = u.s.hi;
    c = p5;
    value = p4;
    return this;
}


// 0x001c9a20 FUN_001c9a20 (26 B): matches/0x001c9a20.cpp
// sym: ?FUN_001c9a20@Obj_1c9a20@owners@@QAEII@Z
hulk_uintptr owners::Obj_1c9a20::FUN_001c9a20(u32_1c9a20 param) {
    ((owners::Object_1c9750 *)(((ThisCall_001c9750*)(this))))->FUN_001c9750(2, 0xb0, (unsigned)param);
    return (hulk_uintptr)this;
}


// 0x001c9a40 FUN_001c9a40 (26 B): matches/0x001c9a40.cpp
// sym: ?FUN_001c9a40@C_1c9a40@owners@@QAEPAU12@I@Z
owners::C_1c9a40* owners::C_1c9a40::FUN_001c9a40(unsigned p) {
    helper(3, 0xb0, p);
    return this;
}

namespace fn_ffd7287e {

// 0x001c9a60 FUN_001c9a60 (63 B): matches/0x001c9a60.cpp
// sym: ??0Item@fn_ffd7287e@@QAE@HHH@Z
Item::Item(int x, int y, int z) {
    memset(this, 0, sizeof(*this));
    a = 28;
    b = 4;
    e = x;
    f = y;
    g = z;
}

} // namespace fn_ffd7287e

// 0x001c9b30 FUN_001c9b30 (70 B): equivalent/0x001c9b30.cpp
// sym: ?FUN_001c9b30@Task_1c9b30@owners@@QAEPAU12@II@Z @5a6a1be40a28 @w822d5265c80e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c9b30 @ 0x001c9b30
owners::Task_1c9b30 * owners::Task_1c9b30::FUN_001c9b30(unsigned x, unsigned y) {
 type=0; kind=0; a=0; b=0; c=0; d=0; arg1=0; arg2=0;
 type=32; kind=5; arg1=x; arg2=y;
 ((Args *)&x)->FUN_0027af50();
 return this;
}

namespace fn_ffd7287e {

// 0x001c9c00 FUN_001c9c00 (77 B): equivalent/0x001c9c00.cpp
// sym: ?FUN_001c9c00@Object@fn_ffd7287e@@QAEPAU12@UArgument@2@II@Z @231a64f3eff0 @w0d50f61d7e68
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c9c00 @ 0x001c9c00
Object* Object::FUN_001c9c00(Argument first, unsigned int second, unsigned int third) {
 size = 0; kind = 0; field8 = 0; fieldC = 0;
 field10 = 0; field14 = 0; field18 = 0; field1C = 0;
 size = 0x20; kind = 6;
 field18 = first.value;
 field1C = second;
 fieldC = third;
 first.FUN_0027af50();
 return this;
}

} // namespace fn_ffd7287e

// 0x001c9cd0 FUN_001c9cd0 (70 B): equivalent/0x001c9cd0.cpp
// sym: ?FUN_001c9cd0@Item_1c9cd0@owners@@QAEPAU12@II@Z @6a204321ac62 @w27bfc04ab9b4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c9cd0 @ 0x001c9cd0
owners::Item_1c9cd0* owners::Item_1c9cd0::FUN_001c9cd0(unsigned int x,unsigned int y) { size=0; kind=0; a=0; b=0; c=0; d=0; first=0; second=0; size=32; kind=7; first=x; second=y; ((Args*)&x)->FUN_0027af50(); return this; }


// 0x001c9e70 FUN_001c9e70 (70 B): equivalent/0x001c9e70.cpp
// sym: ?FUN_001c9e70@Obj_1c9e70@owners@@QAEPAU12@II@Z @c5cc0cd931ec @w2dacdb3fe37d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c9e70 @ 0x001c9e70
owners::Obj_1c9e70* owners::Obj_1c9e70::FUN_001c9e70(unsigned x,unsigned y) { a=0; b=0; c=0; d=0; e=0; f=0; g=0; h=0; a=32; b=9; g=x; h=y; ((Arg*)&x)->FUN_0027af50(); return this; }


// 0x001c9f40 FUN_001c9f40 (97 B): matches/0x001c9f40.cpp
// sym: ?FUN_001c9f40@Obj_1c9f40@owners@@QAEPAU12@HPBD0@Z
owners::Obj_1c9f40* owners::Obj_1c9f40::FUN_001c9f40(int a, const char* b, const char* c) {
    memset(this, 0, 0x54);
    this->a = a;
    this->v = 0x54;
    this->s1[0] = 0;
    this->s2[0] = 0;
    if (b)
        Fmt_00267760(this->s1, 0x20, "%s", b);
    if (c)
        Fmt_00267760(this->s2, 0x20, "%s", c);
    return this;
}

namespace fn_ffd7287e {

// 0x001c9fb0 FUN_001c9fb0 (75 B): matches/0x001c9fb0.cpp
// sym: ?target@fn_ffd7287e@@YI_NPAVThis_1c9fb0@1@@Z
bool __fastcall target(This_1c9fb0* self) {
    Obj_1c9fb0* o = self->get_001d4c90();
    if (!o)
        return false;
    if (!((owners::Obj_1d2e80 *)o)->FUN_001d2e80())
        return false;
    ((owners::Thing_1d1d50 *)o)->FUN_001d1d50((hulk_uintptr)"eg", (hulk_uintptr)(&self->a));
    ((owners::Thing_1d1d50 *)o)->FUN_001d1d50((hulk_uintptr)"locator", (hulk_uintptr)(&self->b));
    o->finish_001d1d10();
    return true;
}

} // namespace fn_ffd7287e

// 0x001ca000 FUN_001ca000 (28 B): matches/0x001ca000.cpp
// sym: ?FUN_001ca000@C_1ca000@owners@@QAEHHH@Z
hulk_intptr owners::C_1ca000::FUN_001ca000(hulk_intptr a, hulk_intptr b) {
    helper(10, ((int)a), ((int)b));
    return (hulk_intptr)this;
}


// 0x001ca020 FUN_001ca020 (28 B): matches/0x001ca020.cpp
// sym: ?FUN_001ca020@C_1ca020@owners@@QAEPAU12@HH@Z
owners::C_1ca020* owners::C_1ca020::FUN_001ca020(hulk_intptr a, hulk_intptr b) {
    callee(11, ((int)a), ((int)b));
    return this;
}


// 0x001ca040 FUN_001ca040 (28 B): matches/0x001ca040.cpp
// sym: ?FUN_001ca040@Obj_1ca040@owners@@QAEPAU12@HH@Z
owners::Obj_1ca040* owners::Obj_1ca040::FUN_001ca040(hulk_intptr a, hulk_intptr b) {
    helper(12, ((int)a), ((int)b));
    return this;
}

namespace fn_ffd7287e {

// 0x001ca060 FUN_001ca060 (46 B): matches/0x001ca060.cpp
// sym: ??0X@fn_ffd7287e@@QAE@H@Z
X::X(int x) {
    memset(this, 0, 24);
    a = 24;
    b = 13;
    f = x;
}

} // namespace fn_ffd7287e

// 0x001ca090 FUN_001ca090 (59 B): matches/0x001ca090.cpp
// sym: ?FUN_001ca090@Owner_1ca090@owners@@QAE_NXZ
// data: checkpoint = DAT_00421ba0
bool owners::Owner_1ca090::FUN_001ca090() {
    Thing_1ca090* t = GetThing_001d4c90();
    if (!t)
        return false;
    if (!((owners::Obj_1d2e80 *)t)->FUN_001d2e80())
        return false;
    ((owners::Obj_1d1dd0 *)t)->FUN_001d1dd0((hulk_intptr)DAT_00421ba0, value);
    t->finish_001d1d10();
    return true;
}

namespace fn_ffd7287e {

// 0x001ca0d0 FUN_001ca0d0 (34 B): matches/0x001ca0d0.cpp
// sym: ??0Obj@fn_ffd7287e@@QAE@XZ
Obj::Obj() {
    memset(this, 0, 20);
    a = 20;
    b = 14;
}


// 0x001ca110 FUN_001ca110 (94 B): matches/0x001ca110.cpp
// sym: ??0Obj_1ca110@fn_ffd7287e@@QAE@HHHHH@Z
Obj_1ca110::Obj_1ca110(int u, int v, int w, int y, int z) {
    memset(this, 0, 0x64);
    a = 100;
    b = 16;
    p = w;
    q = y;
    r = z;
    s = 1;
    format_00267760(text, 64, "%s", v);
    x = u;
}


// 0x001ca210 FUN_001ca210 (63 B): matches/0x001ca210.cpp
// sym: ??0Record@fn_ffd7287e@@QAE@III@Z
Record::Record(unsigned int first, unsigned int second, unsigned int third) {
    memset(this, 0, sizeof(*this));
    value1 = first;
    size = 0x1c;
    type = 0xf;
    value2 = second;
    value3 = third;
}

} // namespace fn_ffd7287e

// 0x001ca2e0 FUN_001ca2e0 (80 B): equivalent/0x001ca2e0.cpp
// sym: ?FUN_001ca2e0@Record_1ca2e0@owners@@QAEPAU12@PBDIIE@Z @4f9e41742681 @w36c848481511
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca2e0 @ 0x001ca2e0
owners::Record_1ca2e0 *owners::Record_1ca2e0::FUN_001ca2e0(const char *input, unsigned int valueArg, unsigned int extraArg, unsigned char flagArg) { unsigned int *p = (unsigned int *)this; for (int i = 0; i < 0x17; ++i) p[i] = 0; size = 0x5c; kind = 0x11; FUN_00267760(text, 0x40, "%s", input); flag = flagArg; extra = extraArg; value = valueArg; return this; }


// 0x001ca3d0 FUN_001ca3d0 (95 B): equivalent/0x001ca3d0.cpp
// sym: ?FUN_001ca3d0@Packet_1ca3d0@owners@@QAEPAU12@IIIIII@Z @5d94dafca698 @wb6084c248c17
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca3d0 @ 0x001ca3d0
owners::Packet_1ca3d0* owners::Packet_1ca3d0::FUN_001ca3d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f)
{
    unsigned int* words = (unsigned int*)this;
    for (int i = 0; i < 12; ++i) words[i] = 0;
    value1c = b;
    value18 = a;
    value20 = c;
    value28 = f;
    kind = 0x30;
    subtype = 0x12;
    value24 = d;
    value10 = e;
    ((Arg*)&a)->FUN_0027af50();
    ((Arg*)&c)->FUN_0027af50();
    return this;
}

namespace fn_ffd7287e {

// 0x001ca540 FUN_001ca540 (106 B): equivalent/0x001ca540.cpp
// sym: ?Init@Request@fn_ffd7287e@@QAEPAU12@UName@2@0H@Z @9df1454fb565 @wf93b714576ce
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca540 @ 0x001ca540
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
Request* Request::Init(Name a, Name b, int v)
{
    size = 0;
    kind = 0;
    f08 = 0;
    f0c = 0;
    value = 0;
    f14 = 0;
    first.lo = 0;
    first.hi = 0;
    second.lo = 0;
    second.hi = 0;
    first = a;
    second = b;
    size = 0x28;
    kind = 0x13;
    value = v;
    return this;
}

} // namespace fn_ffd7287e

// 0x001ca6b0 FUN_001ca6b0 (114 B): equivalent/0x001ca6b0.cpp [wrapped: conflict: FUN_0027b020; Request]
// sym: ?FUN_001ca6b0@Request@fn_001ca6b0@@QAEPAU12@UId64_1ca6b0@2@0HPBDH@Z @3f0cbb29208d @wd4a0e3f70845
namespace fn_001ca6b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca6b0 @ 0x001ca6b0
struct Id64_1ca6b0 {
    unsigned int lo, hi;
    ~Id64_1ca6b0() throw();
};
union Key_1ca6b0 {
    unsigned __int64 q;
    unsigned int w[2];
};
unsigned __int64 __cdecl FUN_0027b020(const char *name) throw();

struct Request {
    int size;
    int kind;
    int f08;
    int f0c;
    int value;
    int f14;
    Id64_1ca6b0 first;
    Id64_1ca6b0 second;
    int f28;
    int f2c;
    unsigned int keyLo;
    unsigned int keyHi;
    Request *FUN_001ca6b0(Id64_1ca6b0 a, Id64_1ca6b0 b, int c, const char *name, int v);
};

Request *Request::FUN_001ca6b0(Id64_1ca6b0 a, Id64_1ca6b0 b, int c, const char *name, int v)
{
    size = 0;
    kind = 0;
    f08 = 0;
    f0c = 0;
    value = 0;
    f14 = 0;
    first.lo = 0;
    first.hi = 0;
    second.lo = 0;
    second.hi = 0;
    f28 = 0;
    f2c = 0;
    keyLo = 0;
    keyHi = 0;
    first = a;
    second = b;
    size = 0x38;
    kind = 0x14;
    f28 = c;
    Key_1ca6b0 k;
    k.q = FUN_0027b020(name);
    keyLo = k.w[0];
    keyHi = k.w[1];
    value = v;
    return this;
}
} // namespace fn_001ca6b0


// 0x001ca830 FUN_001ca830 (95 B): equivalent/0x001ca830.cpp [wrapped: conflict: Record]
// sym: ?FUN_001ca830@Record@fn_001ca830@@QAEPAU12@UValue@2@I0III@Z @3dd872cebc35 @w65e8b1473c5f
namespace fn_001ca830 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca830 @ 0x001ca830
struct Value { unsigned int word; void FUN_0027af50(); };
struct Record {
    unsigned int fields[12];
    Record* FUN_001ca830(Value first, unsigned int second, Value third, unsigned int fourth, unsigned int fifth, unsigned int sixth);
};
Record* Record::FUN_001ca830(Value first, unsigned int second, Value third, unsigned int fourth, unsigned int fifth, unsigned int sixth) {
    for (int i = 0; i < 12; ++i) fields[i] = 0;
    fields[7] = second;
    fields[6] = first.word;
    fields[8] = third.word;
    fields[10] = sixth;
    fields[0] = 0x30;
    fields[1] = 0x15;
    fields[9] = fourth;
    fields[4] = fifth;
    first.FUN_0027af50();
    third.FUN_0027af50();
    return this;
}
} // namespace fn_001ca830


// 0x001ca9a0 FUN_001ca9a0 (99 B): equivalent/0x001ca9a0.cpp [wrapped: merged class would differ: Arg: size 8 vs 4]
// sym: ?FUN_001ca9a0@Result@fn_001ca9a0@@QAEPAU12@UArg@2@I0I@Z @aa6cf788a1b5 @w60f621163fe4
namespace fn_001ca9a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca9a0 @ 0x001ca9a0
struct Arg { unsigned value; void FUN_0027af50(); };
struct Result { unsigned size, kind, unused8, unusedC, unused10, unused14; Arg first; unsigned second; Arg third; unsigned fourth; Result* FUN_001ca9a0(Arg a, unsigned b, Arg c, unsigned d); };
Result* Result::FUN_001ca9a0(Arg a, unsigned b, Arg c, unsigned d)
{
 size=0; kind=0; unused8=0; unusedC=0; unused10=0; unused14=0; first.value=0; second=0; third.value=0; fourth=0;
 first=a; second=b; third=c; fourth=d; size=0x28; kind=0x16;
 a.FUN_0027af50(); c.FUN_0027af50();
 return this;
}
} // namespace fn_001ca9a0


// 0x001caae0 FUN_001caae0 (128 B): equivalent/0x001caae0.cpp [wrapped: conflict: memset]
// sym: ?Init@Request@fn_001caae0@@QAEPAV12@UName@2@H0HPBDHH@Z @999c7e8f3c74 @w8d18ff90cf3a
namespace fn_001caae0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001caae0 @ 0x001caae0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
// 0x001caae0: fill a 0x38-byte request record from two names and several values
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int) throw();
#endif


struct Name {
    int lo;
    int hi;
    ~Name() throw();
};

class Request {
public:
    int size;
    int kind;
    int field_08;
    int pad0c;
    int field_10;
    int pad14;
    Name first;
    Name second;
    int field_28;
    int field_2c;
    unsigned __int64 key;
    Request* Init(Name a, int v28, Name b, int v2c, const char* text, int v10, int v08) throw();
};

Request* Request::Init(Name a, int v28, Name b, int v2c, const char* text, int v10, int v08) throw()
{
    memset(this, 0, 0x38);
    first = a;
    second = b;
    size = 0x38;
    kind = 0x17;
    field_28 = v28;
    field_2c = v2c;
    key = FUN_0027b020(text);
    field_10 = v10;
    field_08 = v08;
    return this;
}
} // namespace fn_001caae0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ffd7287e {

// 0x001cac80 FUN_001cac80 (56 B): matches/0x001cac80.cpp
// sym: ??0Obj@fn_ffd7287e@@QAE@HH@Z
Obj::Obj(int x, int y) {
    memset(this, 0, 28);
    a = 28;
    b = 24;
    f = x;
    g = y;
}

} // namespace fn_ffd7287e

// 0x001cacc0 FUN_001cacc0 (75 B): matches/0x001cacc0.cpp
// sym: ?FUN_001cacc0@Owner_1cacc0@owners@@QAE_NXZ
bool owners::Owner_1cacc0::FUN_001cacc0() {
    Item_1cacc0* item = GetItem_001d4c90();
    if (!item)
        return false;
    if (!((owners::Obj_1d2e80 *)item)->FUN_001d2e80())
        return false;
    ((owners::Obj_1d1dd0 *)item)->FUN_001d1dd0((hulk_intptr)"old", oldValue);
    ((owners::Obj_1d1dd0 *)item)->FUN_001d1dd0((hulk_intptr)"new", newValue);
    item->Finish_001d1d10();
    return true;
}


// 0x001cad10 FUN_001cad10 (46 B): matches/0x001cad10.cpp [wrapped: same definition as 0x001ca060 in this TU]
// sym: ??0X@fn_001cad10@@QAE@H@Z
namespace fn_001cad10 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned);
#endif

struct X {
    int a, b, c, d, e, f;
    X(int v);
};
X::X(int v) {
    memset(this, 0, sizeof(*this));
    a = 24;
    b = 25;
    f = v;
}
} // namespace fn_001cad10


// 0x001cad80 FUN_001cad80 (46 B): matches/0x001cad80.cpp [wrapped: same definition as 0x001ca060 in this TU]
// sym: ??0X@fn_001cad80@@QAE@H@Z
namespace fn_001cad80 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#endif

struct X {
    int a, b, c, d, e, f;
    X(int x);
};
X::X(int x) {
    memset(this, 0, 24);
    a = 0x18;
    b = 0x1a;
    f = x;
}
} // namespace fn_001cad80


// 0x001cadf0 FUN_001cadf0 (70 B): equivalent/0x001cadf0.cpp
// sym: ?FUN_001cadf0@Item_1cadf0@owners@@QAEPAU12@II@Z @6a07fe3dd04c @w2fd10e119859
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cadf0 @ 0x001cadf0
owners::Item_1cadf0 * owners::Item_1cadf0::FUN_001cadf0(unsigned int x, unsigned int y) { a=0; b=0; c=0; d=0; e=0; f=0; g=0; h=0; a=0x20; b=0x1b; g=x; h=y; ((Args *)&x)->FUN_0027af50(); return this; }


// 0x001cae40 FUN_001cae40 (66 B): equivalent/0x001cae40.cpp
// sym: ?FUN_001cae40@Result_1cae40@owners@@QAEPAU12@I@Z @b8af6ee997a2 @wed18fb1bd58e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cae40 @ 0x001cae40
owners::Result_1cae40* owners::Result_1cae40::FUN_001cae40(hulk_uintptr value) { first=0; second=0; a=0; b=0; c=0; d=0; low=0; high=0; first=0x20; second=0x1b; Pair p=FUN_0027b020(((unsigned int)value)); low=p.low; high=p.high; return this; }


// 0x001caf10 FUN_001caf10 (46 B): matches/0x001caf10.cpp [wrapped: conflict: X]
// sym: ??0X@fn_001caf10@@QAE@H@Z
namespace fn_001caf10 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#endif

class X {
  public:
    X(int);
    int a[6];
};
X::X(int v) {
    memset(a, 0, 24);
    a[0] = 0x18;
    a[1] = 0x1c;
    a[5] = v;
}
} // namespace fn_001caf10


// 0x001caf80 FUN_001caf80 (66 B): matches/0x001caf80.cpp
// sym: ?FUN_001caf80@Obj_1caf80@owners@@QAEPAU12@PBDI@Z
owners::Obj_1caf80* owners::Obj_1caf80::FUN_001caf80(const char* a, u32_1caf80 b) {
    memset(this, 0, 0x54);
    data[0] = 0x54;
    data[1] = 0x1d;
    CopyText_00267760((char*)&data[5], 0x40, "%s", a);
    data[4] = b;
    return this;
}


// 0x001cafd0 FUN_001cafd0 (120 B): matches/0x001cafd0.cpp
// sym: ?FUN_001cafd0@Actor_1cafd0@owners@@QAE_NXZ
bool owners::Actor_1cafd0::FUN_001cafd0() {
    Writer_1cafd0* w = GetWriter_001d4c90();
    if (!w)
        return false;
    if (!((owners::Obj_1d2e80 *)w)->FUN_001d2e80())
        return false;
    ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"tv", (hulk_uintptr)(&mName));
    G_1cafd0* g = hulk_at_004dd700;
    int id = mId;
    if (!g) {
        w->Close_001d1d10();
        return false;
    }
    Look_1cafd0* l = g->look;
    Info_1cafd0* i = ((Info_1cafd0 *)((owners::ThisWrap_00059c10 *)l)->FUN_00059c10((void *)(hulk_uintptr)(int)id));
    if (i)
        ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)(i->Name_00036d00()));
    else
        ((owners::Thing_1d1d50 *)w)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)"UNKNOWN");
    w->Close_001d1d10();
    return true;
}


// 0x001cb050 FUN_001cb050 (66 B): matches/0x001cb050.cpp
// sym: ?FUN_001cb050@Obj_1cb050@owners@@QAEPAU12@HI@Z
owners::Obj_1cb050* owners::Obj_1cb050::FUN_001cb050(hulk_intptr a, unsigned int b) {
    memset(data, 0, 84);
    data[0] = 0x54;
    data[1] = 0x1e;
    Copy_00267760(&data[5], 0x40, "%s", (const char*)((hulk_uintptr)a));
    data[4] = b;
    return this;
}

namespace fn_ffd7287e {

// 0x001cb120 FUN_001cb120 (67 B): equivalent/0x001cb120.cpp
// sym: ?FUN_001cb120@fn_ffd7287e@@YIPAUData@1@PAU21@@Z @605106179774 @wad9c7b38e292
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cb120 @ 0x001cb120
Data* __fastcall FUN_001cb120(Data* value) { char* bytes = (char*)value; for (int i=0; i<0xe0; ++i) bytes[i]=0; value->kind=0x14; return value; }


// 0x001cb3a0 FUN_001cb3a0 (48 B): matches/0x001cb3a0.cpp
// sym: ?compare@fn_ffd7287e@@YAHPAUObj_1cb3a0@1@0@Z
// data: g_table_1cb3a0 = DAT_00421ce0
int __cdecl compare(Obj_1cb3a0* a, Obj_1cb3a0* b) {
    if (a != 0 && b != 0 && ((int*)&DAT_00421ce0)[a->index] > ((int*)&DAT_00421ce0)[b->index])
        return -1;
    return 1;
}

} // namespace fn_ffd7287e

// 0x001cb540 FUN_001cb540 (13 B): matches/0x001cb540.cpp
// sym: ?FUN_001cb540@CEventManager@@QAEXD@Z
void CEventManager::FUN_001cb540(char v) {
    this->f_3fc = v;
}

namespace fn_ffd7287e {

// 0x001cb550 FUN_001cb550 (3 B): matches/0x001cb550.cpp
// sym: _FUN_001cb550@4
extern "C" void __stdcall FUN_001cb550(int x) {}


// 0x001cb770 FUN_001cb770 (44 B): matches/0x001cb770.cpp
// sym: ?Set@Owner_1cb770@fn_ffd7287e@@QAEXPAVItem_1cb770@2@@Z
void Owner_1cb770::Set(Item_1cb770* p) {
    if (p)
        p->A();
    if (item)
        item->B();
    item = p;
}


// 0x001cb7c0 FUN_001cb7c0 (114 B): matches/0x001cb7c0.cpp
// sym: ?Alloc@T_1cb7c0@fn_ffd7287e@@QAEIPAUObj_1cb7c0@2@H@Z
// data: gFlag_1cb7c0 = DAT_004c54a0
unsigned T_1cb7c0::Alloc(Obj_1cb7c0* o, hulk_intptr v) {
    if (!o)
        return 0xffffffff;
    unsigned i = Find();
    if (i == 0xffffffff)
        return i;
    (*(char*)&DAT_004c54a0) = 1;
    o->Set_00231ad0(&mSlots[i], v, 0);
    return i;
}


// 0x001cb840 FUN_001cb840 (40 B): matches/0x001cb840.cpp
// sym: ?Target@Owner_1cb840@fn_ffd7287e@@QAEHXZ
int Owner_1cb840::Target() {
    int count = 0;
    Entry_1cb840* p = (Entry_1cb840*)((char*)this + 0x24);
    for (int i = 0x18; i != 0; --i, p = (Entry_1cb840*)((char*)p + 0x28)) {
        if (p->IsActive_00231ee0())
            ++count;
    }
    return count;
}


// 0x001cb930 FUN_001cb930 (82 B): matches/0x001cb930.cpp
// sym: ?Find@Owner_1cb930@fn_ffd7287e@@QAE_NH@Z
bool Owner_1cb930::Find(int value) {
    unsigned int i = 0;
    Entry_1cb930* entry = &entries[0];
    do {
        int a = entry->first;
        int b = entry->second;
        bool found = entry->Check_00231e80(value);
        if (value == a || value == b || found)
            return true;
        ++i;
        entry = (Entry_1cb930*)((char*)entry + 0x28);
    } while (i < 24);
    return false;
}


// 0x001cb990 FUN_001cb990 (98 B): equivalent/0x001cb990.cpp
// sym: ?FUN_001cb990@Container@fn_ffd7287e@@QAE_NUQueryArg@2@H@Z @1775d6cedec2 @w2e411032abff
// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 10/10)
// FUN_001cb990 @ 0x001cb990
bool Container::FUN_001cb990(QueryArg key, int second) {
    Entry *entry = end;
    while (entry != begin) {
        --entry;
        if (entry->type == 0x1b && entry->first == key.value && entry->second == second) {
            key.FUN_0027af50();
            return true;
        }
    }
    key.FUN_0027af50();
    return false;
}

} // namespace fn_ffd7287e

// 0x001cbae0 Method1<CEventManager,bool,const_char_*>::vfunc_0 (30 B): matches/0x001cbae0.cpp
// sym: ??_G?$Method1@VCEventManager@@_NPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CEventManager, bool, const char *>::~Method1() {}


// 0x001cbb00 Method1<CEventManager,bool,const_char_*>::vfunc_2 (29 B): matches/0x001cbb00.cpp
// sym: ?vfunc_2@?$Method1@VCEventManager@@_NPBD@@UAEXPAX00@Z
template <> void Method1<CEventManager, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CEventManager_1cbb00 * obj = (CEventManager_1cbb00 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CEventManager_1cbb00::*f)(const char*) = (*(bool (CEventManager_1cbb00::**)(const char *))&this->f_1c);
    const char* value = *arg;
    bool r = (obj->*f)(value);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CEventManager, bool, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cbae0)
#endif


// 0x001cbb60 Method1<CEventManager,void,bool>::vfunc_0 (30 B): matches/0x001cbb60.cpp
// sym: ??_G?$Method1@VCEventManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CEventManager, void, bool>::~Method1() {}


// 0x001cbb80 Method1<CEventManager,void,bool>::vfunc_2 (21 B): matches/0x001cbb80.cpp
// sym: ?vfunc_2@?$Method1@VCEventManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<CEventManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1cbb80 * obj = (CActorManager_1cbb80 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_1cbb80 *)&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CEventManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cbb60)
#endif


// 0x001cbbe0 Method1<CEventManager,void,const_char_*>::vfunc_0 (30 B): matches/0x001cbbe0.cpp
// sym: ??_G?$Method1@VCEventManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CEventManager, void, const char *>::~Method1() {}


// 0x001cbc00 Method1<CEventManager,void,const_char_*>::vfunc_2 (19 B): matches/0x001cbc00.cpp
// sym: ?vfunc_2@?$Method1@VCEventManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CEventManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1cbc00* d = (Dummy_1cbc00*)a;
    (d->*(*(void (Dummy_1cbc00::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CEventManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cbbe0)
#endif


// 0x001cbcb0 FUN_001cbcb0 (90 B): matches/0x001cbcb0.cpp
// sym: ?FUN_001cbcb0@Owner_1cbcb0@owners@@QAE_NH@Z
bool owners::Owner_1cbcb0::FUN_001cbcb0(int arg) {
    int i = 0;
    Entry_1cbcb0* entry = (Entry_1cbcb0*)((char*)this + 0x24);
    do {
        if (active[i] && i >= 0 && i < 0x18) {
            entry->Set_002322f0(1, arg);
            entry->Reset_00231f20(0);
            entry->Finish_002324b0(1);
            active[i] = 0;
        }
        ++i;
        entry = (Entry_1cbcb0*)((char*)entry + 0x28);
    } while ((unsigned int)i < 0x18);
    return true;
}


// 0x001cbd40 FUN_001cbd40 (57 B): matches/0x001cbd40.cpp
// sym: ?FUN_001cbd40@Obj_1cbd40@owners@@QAEXPAI0@Z
void owners::Obj_1cbd40::FUN_001cbd40(unsigned int* dst, unsigned int* src) {
    unsigned int* end = mEnd;
    unsigned int* out = dst;
    while (src != end) {
        memcpy(out, src, 0xe0);
        src += 0x38;
        out += 0x38;
    }
    mEnd = out;
}


// 0x001cbd90 FUN_001cbd90 (76 B): matches/0x001cbd90.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001cbd90@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001cbd90 {
// data: name1 = DAT_0048e0e4, name2 = DAT_0048e0f0
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.

typedef unsigned int uint;
extern "C++" __declspec(nothrow) unsigned char FUN_001d04d0(const char*);
class Function_1cbd90 : public ScriptFunctionFields {
  public:
    Function_1cbd90(const char*, int);
    virtual void f();
};
class Method1 : public Function_1cbd90 {
  public:
    ScriptMemberFn m;
    Method1(const char* p, ScriptMemberFn v) : Function_1cbd90(p, 1) {
        m = v;
        retType = FUN_001d04d0((const char*)&(*(const char**)&DAT_0048e0e4));
        argTypes[0] = FUN_001d04d0((const char*)&(*(const char**)&DAT_0048e0f0));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    void* n;
    Closure1(const char* p, void* q, ScriptMemberFn v);
    virtual void f();
};
Closure1::Closure1(const char* p, void* q, ScriptMemberFn v) : Method1(p, v) {
    n = q;
}
} // namespace fn_001cbd90


// 0x001cbde0 Closure1<CEventManager,bool,const_char_*>::vfunc_0 (30 B): matches/0x001cbde0.cpp
// sym: ??_G?$Method1@VCEventManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CEventManager, bool, const char *>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CEventManager, bool, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cbde0)
#endif


// 0x001cbe00 Closure1<CEventManager,bool,const_char_*>::vfunc_2 (30 B): matches/0x001cbe00.cpp [wrapped: conflict: Closure1]
// sym: ?V2@Closure1@fn_001cbe00@@UAEXPAXPAPBDPA_N@Z
namespace fn_001cbe00 {
// Same code shape as 0x00106cc0 (propagated; names are from that function)
class Closure1 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2(void*, const char**, bool*);
    char pad[0x18];
    typedef bool(__fastcall* Fn)(void*, const char*, const char*);
    Fn mFn;
    void* mObj;
};
void Closure1::V2(void* a, const char** p, bool* out) {
    void* obj = mObj;
    Fn fn = mFn;
    bool r = fn(obj, *p, *p);
    if (out)
        *out = r;
}
} // namespace fn_001cbe00

namespace fn_ffd7287e {

// 0x001cbe20 FUN_001cbe20 (76 B): matches/0x001cbe20.cpp
// sym: ??0Closure1_1cbe20@fn_ffd7287e@@QAE@PAX00@Z
// data: flagA = DAT_0048e100, flagB = DAT_0048e0e4
Closure1_1cbe20::Closure1_1cbe20(void* p, void* q, void* h) : Method1_1cbe20(p, h) {
    extra = q;
}

} // namespace fn_ffd7287e

// 0x001cbe70 Closure1<CEventManager,void,bool>::vfunc_0 (30 B): matches/0x001cbe70.cpp
// sym: ??_G?$Method1@VCEventManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CEventManager, void, bool>::~Closure1() {}


// 0x001cbe90 Closure1<CEventManager,void,bool>::vfunc_2 (20 B): matches/0x001cbe90.cpp
// sym: ?vfunc_2@?$Closure1@VCEventManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<CEventManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_1cbe90 * *)&this->f_20)->*(*(void (Actor_1cbe90::**)(unsigned char))&this->f_1c))(*arg);
}
#if defined(HULK_PTR64)
template class Closure1<CEventManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cbe70)
#endif


// 0x001cbeb0 FUN_001cbeb0 (76 B): matches/0x001cbeb0.cpp [wrapped: conflict: Closure1; Closure1::Closure1; Method1]
// sym: ??0Closure1@fn_001cbeb0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001cbeb0 {
// data: key1 = DAT_0048e100, key2 = DAT_0048e0f0
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.

struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C++" __declspec(nothrow) unsigned char FUN_001d04d0(const char*);
class Function_1cbeb0 : public CtorV_001d0480 {
  public:
    Function_1cbeb0(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Function_1cbeb0 {
  public:
    virtual void f();
    ScriptMemberFn fn;
    Method1(const char* s, ScriptMemberFn o) : Function_1cbeb0(s) {
        fn = o;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    void* owner;
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1::Closure1(const char* s, void* a, ScriptMemberFn o) : Method1(s, o) {
    owner = a;
}
} // namespace fn_001cbeb0


// 0x001cbf20 Closure1<CEventManager,void,const_char_*>::vfunc_2 (18 B): matches/0x001cbf20.cpp
// sym: ?vfunc_2@?$Closure1@VCEventManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CEventManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1cbf20 * *)&this->f_20)->*(*(void (CActorManager_1cbf20::**)(const char *))&this->f_1c))(*b);
}

namespace fn_ffd7287e {

// 0x001cbf40 FUN_001cbf40 (73 B): equivalent/0x001cbf40.cpp
// sym: ?FUN_001cbf40@Obj_1cbf40@fn_ffd7287e@@QAEXH@Z @49a7500f1bfa @we0ddab6a15b9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cbf40 @ 0x001cbf40
void Obj_1cbf40::FUN_001cbf40(hulk_intptr value)
{
    field8 = value;
    Registry* reg = (*(Registry**)&DAT_004e5af8);
    Entry* e = reg->FUN_00232840(FUN_002672f0(DAT_004c548c, 0, 0));
    listener = e->listener;
    listener->vfunc_0();
    field10 = fieldC;
    flag3fc = 0;
}


// 0x001cbf90 FUN_001cbf90 (72 B): matches/0x001cbf90.cpp
// sym: ?clear@Root_1cbf90@fn_ffd7287e@@QAEXXZ
void Root_1cbf90::clear() {
    if (r400) {
        r400->Release();
        r400 = 0;
    }
    if (r20) {
        r20->Release();
        r20 = 0;
    }
    b = a;
    Worker_1cbf90* p = &first;
    for (int i = 0; i < 24; i++, p++)
        p->run_00232240();
}


// 0x001cbfe0 FUN_001cbfe0 (583 B): equivalent/0x001cbfe0.cpp
// sym: ?FUN_001cbfe0@ItemQueue@fn_ffd7287e@@QAEXM@Z @939a5caa8e6d @w05f40a7ea672
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 39/40, incomplete)
// FUN_001cbfe0 @ 0x001cbfe0
void ItemQueue::FUN_001cbfe0(float dt)
{
    int old = FUN_00266da0(0xd);
    if (active && dt > 0.0f) {
        Event_1cbfe0 ev;
        ev.FUN_001caf10(dt);
        FUN_001cbc20(&ev);
    }
    for (int i = 0; i < 24; i++)
        free[i] = 1;
    qsort(vec.begin, vec.end - vec.begin, 0xe0, (int (__cdecl *)(const void *, const void *))FUN_001cb3a0);
    Item_1cbfe0 *last = vec.end;
    if (last != vec.begin) {
        if (sorted) {
            Item_1cbfe0 *item = last;
            do {
                item = item - 1;
                if (!FUN_001cb400(item)) {
                    void *mem = FUN_0008d690(0xf0);
                    CScenarioParams *task;
                    if (mem)
                        task = ((CScenarioParams_1cbfe0*)(((CScenarioParams *)mem)))->FUN_001d0360(item);
                    else
                        task = 0;
                    task->vfunc_0();
                    Node_1cbfe0 *o = owner;
                    if (o) {
                        if (current)
                            current->vf1();
                        current = 0;
                        Node_1cbfe0 *node = o->vf8(task, 0);
                        while (node) {
                            unsigned int idx = FUN_001cb7c0(node, task);
                            if (idx != (unsigned int)-1) {
                                bool match = false;
                                if (node == current || node->FUN_00232ed0(current))
                                    match = true;
                                if (item->type == 0xe || match) {
                                    if ((int)idx >= 0 && (int)idx < 24) {
                                        slots[idx].FUN_002322f0(1, dt);
                                        slots[idx].FUN_00231f20(0);
                                        slots[idx].FUN_002324b0(1);
                                        free[idx] = 0;
                                    }
                                }
                            }
                            node = node->FUN_00231a00(task);
                        }
                    }
                    task->vfunc_1();
                }
            } while (item != vec.begin);
        }
        Item_1cbfe0 *p = last;
        do {
            p = p - 1;
            if (p->type == 2)
                DAT_0052c2a8->v91();
        } while (p != vec.begin);
        vec.FUN_001cbd40(vec.begin, last);
    }
    FUN_001cbcb0(dt);
    FUN_00266da0(old);
}


// 0x001cc230 FUN_001cc230 (32 B): matches/0x001cc230.cpp
// sym: ?Target@fn_ffd7287e@@YIXPAUObj_1cc230@1@@Z
void __fastcall Target(Obj_1cc230* self) {
    self->b = self->a;
    for (int i = 0; i < 0x18; ++i)
        self->items[i].Init_00232240();
}


// 0x001cc2c0 FUN_001cc2c0 (70 B): matches/0x001cc2c0.cpp
// sym: ?FUN_001cc2c0@Registry_1cc2c0@fn_ffd7287e@@QAEXPBDPAVOwner@2@P832@AEX_N@Z@Z
void Registry_1cc2c0::FUN_001cc2c0(const char* a1, Owner* a2, Fn_1cc2c0 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure1_1cc2c0* e = new (FUN_0008d690((int)sizeof(ScriptClosureView))) Closure1_1cc2c0(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}

} // namespace fn_ffd7287e

// 0x001cc360 FUN_001cc360 (462 B): equivalent/0x001cc360.cpp [wrapped: conflict: CEventManager; Closure1; FUN_001d4c90; Method1]
// sym: ??0CEventManager@fn_001cc360@@QAE@XZ @2794076606d3 @w2a783f2bd06f
namespace fn_001cc360 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_001cc360 @ 0x001cc360
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

extern "C++" __declspec(nothrow) void *FUN_0008d690(unsigned int size);
extern "C" void *FUN_0008d6d0(unsigned int size);


template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1cc360 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char *, int);
    MethodBase_1cc360(const char *n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase_1cc360 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) : MethodBase_1cc360(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T *owner;
};

struct Registry_1cc360 {
    void FUN_001d3b70(const char *name, void *closure);
};
Registry_1cc360 *FUN_001d4c90();

struct EventSlot {
    char data[0x28];
    void FUN_00231e50();
};

class CEventManager {
  public:
    CEventManager();
    virtual void* vfn0_001cc570(char);

    bool FUN_001cbd10(const char *name);
    void FUN_001cb540(bool enabled);
    void FUN_001cb550(const char *name);

    int f04;
    int f08;
    char *buffer;           // 0x0c
    char *cursor;           // 0x10
    char *bufferEnd;        // 0x14
    char pad18[4];
    unsigned char f1c;
    char pad1d[3];
    int f20;
    EventSlot slots[24];    // 0x24
    int w3e4, w3e8, w3ec, w3f0, w3f4, w3f8;
    unsigned char f3fc;
    char pad3fd[3];
    int f400;
};

CEventManager::CEventManager()
{
    f04 = 0;
    f08 = 0;
    buffer = (char *)FUN_0008d6d0(0x7000);
    if (buffer) {
        cursor = buffer;
        bufferEnd = buffer + 0x7000;
    } else {
        cursor = 0;
        bufferEnd = 0;
    }
    f1c = 1;
    f20 = 0;
    for (int i = 0; i < 24; i++)
        slots[i].FUN_00231e50();
    f3fc = 0;
    f400 = 0;

    Registry_1cc360 *reg = FUN_001d4c90();
    if (reg) {
        typedef Closure1<CEventManager, bool, const char *> ClosureBS;
        HULK_SIZE32(ClosureBS, 0x24);
        typedef Closure1<CEventManager, void, bool> ClosureVB;
        HULK_SIZE32(ClosureVB, 0x24);
        typedef Closure1<CEventManager, void, const char *> ClosureVS;
        HULK_SIZE32(ClosureVS, 0x24);
        void *mem;

        mem = FUN_0008d690((int)sizeof(Closure1<CEventManager, bool, const char *>));
        Closure1<CEventManager, bool, const char *> *post = 0;
        if (mem)
            post = new (mem) Closure1<CEventManager, bool, const char *>("em_PostEventString", this, &CEventManager::FUN_001cbd10);
        reg->FUN_001d3b70("em_PostEventString", post);

        mem = FUN_0008d690((int)sizeof(Closure1<CEventManager, void, bool>));
        Closure1<CEventManager, void, bool> *tick = 0;
        if (mem)
            tick = new (mem) Closure1<CEventManager, void, bool>("em_SetTickEnabled", this, &CEventManager::FUN_001cb540);
        reg->FUN_001d3b70("em_SetTickEnabled", tick);

        mem = FUN_0008d690((int)sizeof(Closure1<CEventManager, void, const char *>));
        Closure1<CEventManager, void, const char *> *print = 0;
        if (mem)
            print = new (mem) Closure1<CEventManager, void, const char *>("em_PrintAllEvents", this, &CEventManager::FUN_001cb550);
        reg->FUN_001d3b70("em_PrintAllEvents", print);

        w3e4 = 0x01010101;
        w3e8 = 0x01010101;
        w3ec = 0x01010101;
        w3f0 = 0x01010101;
        w3f4 = 0x01010101;
        w3f8 = 0x01010101;
    }
}
} // namespace fn_001cc360
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cc530 FUN_001cc530 (56 B): matches/0x001cc530.cpp [wrapped: conflict: CEventManager]
// sym: ?FUN_001cc530@fn_001cc530@@YIXPAUCEventManager@1@@Z
namespace fn_001cc530 {
extern "C" char DAT_00421dfc[];
struct Item_1cc530 {
    char data[0x28];
    void Init_002325f0();
};
extern void ReleaseRef_0008d340(int);
struct CEventManager {
    void* vt;
    int a;
    int b;
    int ref;
    int ref2;
    char pad[0x10];
    Item_1cc530 items[24];
};
void __fastcall FUN_001cc530(CEventManager* self) {
    self->vt = (void*)((hulk_intptr)DAT_00421dfc);
    Item_1cc530* p = self->items + 24;
    int n = 24;
    do {
        --p;
        p->Init_002325f0();
        --n;
    } while (n != 0);
    self->ref2 = self->ref;
    if (self->ref)
        ReleaseRef_0008d340(self->ref);
}
} // namespace fn_001cc530


// 0x001cc570 CEventManager::vfunc_0 (78 B): matches/0x001cc570.cpp [wrapped: conflict: CEventManager]
// sym: ?vfunc_0@CEventManager@fn_001cc570@@QAEPAXE@Z
namespace fn_001cc570 {
extern int hulk_at_00421dfc;

void __cdecl FUN_0008d340(void*);
void __cdecl FUN_0008d330(void*);

struct Elem_1cc570 {
    char pad[0x28];
    void dtor_002325f0();
};

class CEventManager {
  public:
    void* mVptr;
    int a[2];
    void* mPtr;
    void* mPtr2;
    char pad[0x10];
    Elem_1cc570 mArr[0x18];

    void* vfunc_0(unsigned char flags);
};

void* CEventManager::vfunc_0(unsigned char flags) {
    mVptr = &hulk_at_00421dfc;
    Elem_1cc570* p = mArr + 0x18;
    for (int i = 0; i < 0x18; ++i) {
        --p;
        p->dtor_002325f0();
    }
    void* t = mPtr;
    mPtr2 = t;
    if (t) {
        FUN_0008d340(t);
    }
    if (flags & 1) {
        FUN_0008d330(this);
    }
    return this;
}
} // namespace fn_001cc570

