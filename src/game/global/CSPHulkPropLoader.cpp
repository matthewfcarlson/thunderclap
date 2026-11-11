// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001d4d50..0x001d64c0 (kind game, layer game, confidence medium), dominant class CSPHulkPropLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f590c0bf {
#define TREE_TU_END }
namespace fn_f590c0bf {} using namespace fn_f590c0bf;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f590c0bf {
typedef unsigned int u32_1d4e00;
class C_1d4e30 {
    char pad[0xb2];

  public:
    unsigned char value;
};
class A_1d4e90 {
  public:
    char pad[0xa4];
    float value;
};
struct Obj_1d4f40 {
    char pad[0xa0];
    int index;
};
struct Pair_1d4f40 {
    int lo;
    int hi;
};
struct X_1d4f70 {
    char pad[0xc0];
    unsigned long long value;
};
struct X_1d5000 {
    char pad[0x18];
    int value;
};
class C_1d5000 {
  public:
    char pad[0x90];
    X_1d5000* p;
    int f();
};
struct Obj_1d5040 {
    char pad[0x10];
};
extern void* vProp[];
class Ref_1d55d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Part_1d55d0 {
  public:
    void Fini() throw();
};
struct Entity_1d55d0 {
    void* vf;
    void Dtor() throw();
};
struct CSPHulkProp_1d55d0 : Entity_1d55d0 {
    char pad[0x8c];
    Ref_1d55d0* p90;
    char pad2[0x24];
    void* pb8;
    int pbc;
    Part_1d55d0 pc0;
    void Dtor2() throw();
};
struct Query_1d5630 { void FUN_0008ced0(int,int,unsigned*,int,int,int); };
extern "C" Query_1d5630* __cdecl FUN_0008ceb0();
extern "C" unsigned __cdecl FUN_00266da0(hulk_uintptr);
struct Owner_1d5630;
struct Entry_1d5630;
struct CSPHulkPropInstance_nv_1d5630 {
    CSPHulkPropInstance* FUN_001d7890(Owner_1d5630*,int);
    void FUN_001d7490(Entry_1d5630*);
};
extern "C" CSPHulkPropInstance* __cdecl FUN_00263ea0(unsigned);
struct Entry_1d5630 { char pad[0x1c]; CSPHulkPropInstance* object; char pad20[2]; unsigned char enabled; char pad23[0xa9-0x23]; unsigned char flag; };
struct Table_1d5630 { Entry_1d5630* FUN_001c59d0(unsigned); };
struct Manager_1d5630 { char pad[12]; Table_1d5630* table; void FUN_001c3a40(unsigned,unsigned); };
extern "C" Manager_1d5630* __cdecl FUN_001c3d90();
struct Owner_1d5630 { char pad[0xb0]; unsigned char flag; CSPHulkPropInstance* target(hulk_uintptr,unsigned); };
struct Inner_1d56f0 {
    char pad[0x1c];
    int* data;
};
class C_1d56f0 {
  public:
    char pad[0x90];
    Inner_1d56f0* m;
    hulk_intptr f(int index);
};
struct Vec_1d5710 {
    int first;
    int last;
};
struct Inner_1d5710 {
    char pad[0x1c];
    Vec_1d5710 v;
};
class Obj_1d5710 {
  public:
    char pad[0x90];
    Inner_1d5710* p;
    int Count();
};
void thunk_FUN_00267090(void *p);
extern "C" void *FUN_0008d6d0(unsigned int size);
class Resource_1d5730 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x1c - 4];
    int *begin;
    int *end;
};
struct Holder_1d5730 {
    char pad[0x90];
    Resource_1d5730 *resource;
    char pad94[0xb8 - 0x94];
    void *buffer;
    void FUN_001d5730(Resource_1d5730 *r);
};
typedef unsigned long U32_1d5c70;
typedef unsigned __int64 U64_1d5c70;
extern long __cdecl _atol(const char*);
struct Attribute { U32_1d5c70 low, high; const char* text; U32_1d5c70 unused; };
struct Item_1d5c70 { char pad[0x3c]; int count; Attribute* attributes; };
struct List_1d5c70 { char pad[0x1c]; Item_1d5c70** begin; Item_1d5c70** end; };
struct CSPHulkPropInstance_1d5c70 { char pad[0x90]; List_1d5c70* list; long FUN_001d5c70(int index); };
struct Property_1d5d20 { uint low, high; const char* value; uint extra; };
struct Item_1d5d20 { char pad[0x3c]; int count; Property_1d5d20* properties; };
struct Collection_1d5d20 { char pad[0x1c]; Item_1d5d20** begin; Item_1d5d20** end; };
struct CSPHulkPropInstance_1d5d20 { char pad[0x90]; Collection_1d5d20* collection; long target(int index); };
extern "C" int __cdecl FUN_001d5140(const char *);
struct Property_1d5dd0 { uint low, high, value, unused; };
struct Entry_1d5dd0 { char pad[0x3c]; int count; Property_1d5dd0* properties; };
struct Collection_1d5dd0 { char pad[0x1c]; Entry_1d5dd0** begin; Entry_1d5dd0** end; };
struct Property_1d5e80 { unsigned int keyLow; unsigned int keyHigh; void* value; unsigned int reserved; };
struct Entry_1d5e80 { char pad[0x3c]; int count; Property_1d5e80* properties; };
struct Entries_1d5e80 { char pad[0x1c]; Entry_1d5e80** begin; Entry_1d5e80** end; };
struct CSPHulkPropInstance_1d5e80 { char pad[0x90]; Entries_1d5e80* entries; int FUN_001d5e80(int index); };
struct Entry_1d60c0 { int unused[2]; int type; int next; };
struct Node { char pad[0x24]; int count; Entry_1d60c0* entries; };
struct Table_1d60c0 { char pad[0x1c]; Node** nodes; };
struct Object {
  public:
    char _m_pad_0[0x90];
    union { Collection_1d5dd0* collection; Table_1d60c0* table; };
    int target(int index);
    int FUN_001d5c70(int index);
    int FUN_001d60c0();
};
struct X_1d6240 {
    void Call();
    X_1d6240* Target();
};
class A_1d6270 {
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
    virtual unsigned int f11();
};
struct B_1d6270 {
    void FUN(unsigned int);
};
struct Obj_1d6270 {
    char pad[0x9c];
    A_1d6270* p;
    char pad2[0x7c];
    B_1d6270* q;
};
class C_1d62a0 {
  public:
    char pad[0xf9];
    unsigned char value;
};

} // namespace fn_f590c0bf

// 0x001d4d50 FUN_001d4d50 (132 B): matches/0x001d4d50.cpp [wrapped: conflict: CSPHulkProp]
// sym: ??0CSPHulkProp@fn_001d4d50@@QAE@XZ
namespace fn_001d4d50 {
class Entity_1d4d50 {
  public:
    Entity_1d4d50();
    virtual void G();
    char pad[0x90 - 4];
};
class M_1d4d50 {
  public:
    void Init();
    char q[8];
};
class CSPHulkProp : public Entity_1d4d50 {
  public:
    virtual void G();
    int a, b, c, d, e, f, g, h;
    unsigned char i, j, k, l, m, n, o;
    int p;
    char pad2[4];
    M_1d4d50 mm;
    CSPHulkProp();
};
CSPHulkProp::CSPHulkProp() {
    a = 0;
    b = 0;
    c = 0xffff;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    h = 0;
    i = 1;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
    n = 0;
    o = 0;
    p = 0;
    mm.Init();
}
} // namespace fn_001d4d50


// 0x001d4de0 FUN_001d4de0 (7 B): matches/0x001d4de0.cpp
// sym: ?FUN_001d4de0@C_1d4de0@owners@@QAEHXZ
int owners::C_1d4de0::FUN_001d4de0() {
    return *(int*)((char*)this + 0x94);
}


// 0x001d4df0 FUN_001d4df0 (14 B): matches/0x001d4df0.cpp
// sym: ?FUN_001d4df0@Target_1d4df0@owners@@QAEHXZ
int owners::Target_1d4df0::FUN_001d4df0() {
    return value != 0;
}


// 0x001d4e00 FUN_001d4e00 (7 B): matches/0x001d4e00.cpp
// sym: ?FUN_001d4e00@C_1d4e00@owners@@QAEIXZ
hulk_uintptr owners::C_1d4e00::FUN_001d4e00() {
    return value;
}


// 0x001d4e10 FUN_001d4e10 (7 B): matches/0x001d4e10.cpp
// sym: ?FUN_001d4e10@C_1d4e10@owners@@QAEIXZ
unsigned int owners::C_1d4e10::FUN_001d4e10() {
    return value;
}


// 0x001d4e20 FUN_001d4e20 (7 B): matches/0x001d4e20.cpp
// sym: ?FUN_001d4e20@Obj_1d4e20@owners@@QAEEXZ
unsigned char owners::Obj_1d4e20::FUN_001d4e20() {
    return value;
}

namespace fn_f590c0bf {

// 0x001d4e30 FUN_001d4e30 (7 B): matches/0x001d4e30.cpp
// sym: ?target@fn_f590c0bf@@YIEPAVC_1d4e30@1@@Z
unsigned char __fastcall target(C_1d4e30* self) {
    return self->value;
}

} // namespace fn_f590c0bf

// 0x001d4e40 FUN_001d4e40 (7 B): matches/0x001d4e40.cpp
// sym: ?FUN_001d4e40@Obj_1d4e40@owners@@QAEEXZ
unsigned char owners::Obj_1d4e40::FUN_001d4e40() {
    return value;
}


// 0x001d4e50 FUN_001d4e50 (7 B): matches/0x001d4e50.cpp
// sym: ?FUN_001d4e50@C_1d4e50@owners@@QAEEXZ
unsigned char owners::C_1d4e50::FUN_001d4e50() {
    return pad[0xb4];
}


// 0x001d4e60 FUN_001d4e60 (7 B): matches/0x001d4e60.cpp
// sym: ?FUN_001d4e60@C_1d4e60@owners@@QAEEXZ
unsigned char owners::C_1d4e60::FUN_001d4e60() {
    return value;
}


// 0x001d4e70 FUN_001d4e70 (7 B): matches/0x001d4e70.cpp
// sym: ?FUN_001d4e70@C_1d4e70@owners@@QAEEXZ
unsigned char owners::C_1d4e70::FUN_001d4e70() {
    return field;
}


// 0x001d4e80 FUN_001d4e80 (7 B): matches/0x001d4e80.cpp
// sym: ?FUN_001d4e80@C_1d4e80@owners@@QAEHXZ
int owners::C_1d4e80::FUN_001d4e80() {
    return value;
}

namespace fn_f590c0bf {

// 0x001d4e90 FUN_001d4e90 (7 B): matches/0x001d4e90.cpp
// sym: ?target@fn_f590c0bf@@YIMPAVA_1d4e90@1@@Z
float __fastcall target(A_1d4e90* self) {
    return self->value;
}

} // namespace fn_f590c0bf

// 0x001d4ea0 FUN_001d4ea0 (16 B): matches/0x001d4ea0.cpp
// sym: ?FUN_001d4ea0@Target_1d4ea0@owners@@QAEMH@Z
float owners::Target_1d4ea0::FUN_001d4ea0(int index) {
    return values[index];
}


// 0x001d4ef0 FUN_001d4ef0 (45 B): matches/0x001d4ef0.cpp
// sym: ?FUN_001d4ef0@Thing_1d4ef0@owners@@QAEHXZ
int owners::Thing_1d4ef0::FUN_001d4ef0() {
    int x = state;
    if (x == 2 || x == 3 || x == 4 || x == 5 || x == 7 || x == 6)
        return 1;
    return 0;
}

namespace fn_f590c0bf {

// 0x001d4f20 FUN_001d4f20 (5 B): matches/0x001d4f20.cpp
// sym: ?FUN_001d4f20@fn_f590c0bf@@YG_NH@Z
bool __stdcall FUN_001d4f20(int x) {
    return false;
}

} // namespace fn_f590c0bf

// 0x001d4f30 FUN_001d4f30 (7 B): matches/0x001d4f30.cpp
// sym: ?FUN_001d4f30@C_1d4f30@owners@@QAEHXZ
int owners::C_1d4f30::FUN_001d4f30() {
    return value;
}

namespace fn_f590c0bf {

// 0x001d4f40 FUN_001d4f40 (21 B): matches/0x001d4f40.cpp
// sym: ?target@fn_f590c0bf@@YI?AUPair_1d4f40@1@PAUObj_1d4f40@1@@Z
// data: gTable_1d4f40 = DAT_004e24c0
Pair_1d4f40 __fastcall target(Obj_1d4f40* self) {
    return ((Pair_1d4f40*)&DAT_004e24c0)[self->index];
}


// 0x001d4f70 FUN_001d4f70 (13 B): matches/0x001d4f70.cpp
// sym: @FUN_001d4f70@4
extern "C" unsigned long long __fastcall FUN_001d4f70(X_1d4f70* p) {
    return p->value;
}

} // namespace fn_f590c0bf

// 0x001d4fc0 FUN_001d4fc0 (7 B): matches/0x001d4fc0.cpp
// sym: ?FUN_001d4fc0@C_1d4fc0@owners@@QAEIXZ
hulk_uintptr owners::C_1d4fc0::FUN_001d4fc0() {
    return value;
}

namespace fn_f590c0bf {

// 0x001d5000 FUN_001d5000 (10 B): matches/0x001d5000.cpp
// sym: ?f@C_1d5000@fn_f590c0bf@@QAEHXZ
int C_1d5000::f() {
    return p->value;
}


// 0x001d5040 FUN_001d5040 (4 B): matches/0x001d5040.cpp
// sym: ?FUN_001d5040@fn_f590c0bf@@YIPAUObj_1d5040@1@PAU21@@Z
// Same code shape as 0x001d03c0 (propagated; names are from that function)
Obj_1d5040* __fastcall FUN_001d5040(Obj_1d5040* self) {
    return (Obj_1d5040*)((char*)self + 0x10);
}


// 0x001d5050 FUN_001d5050 (140 B): equivalent/0x001d5050.cpp
// sym: _FUN_001d5050
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001d5050 @ 0x001d5050
// Map a weapon name to its id (0 for an unknown name).
   // string compare, 0 when equal
extern "C" int FUN_001d5050(const char* name)
{
    if (FUN_00096600(name, "small") == 0) {
        return 2;
    }
    if (FUN_00096600(name, "large") == 0) {
        return 3;
    }
    if (FUN_00096600(name, "club") == 0) {
        return 5;
    }
    if (FUN_00096600(name, "steel_fist") == 0) {
        return 6;
    }
    if (FUN_00096600(name, "shield") == 0) {
        return 7;
    }
    return 0;
}


// 0x001d50e0 FUN_001d50e0 (83 B): equivalent/0x001d50e0.cpp
// sym: _FUN_001d50e0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001d50e0 @ 0x001d50e0
extern "C" int __cdecl FUN_001d50e0(const char *name) {
    if (FUN_00096600(name, "static") == 0) return 0;
    if (FUN_00096600(name, "rigidbody") == 0) return 1;
    if (FUN_00096600(name, "articulated") == 0) return 2;
    return 0;
}


// 0x001d5140 FUN_001d5140 (166 B): equivalent/0x001d5140.cpp
// sym: _FUN_001d5140
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001d5140 @ 0x001d5140
extern "C" int FUN_001d5140(const char *name)
{
    if (FUN_00096600(name, "steel_fists") == 0)
        return 1;
    if (FUN_00096600(name, "shield") == 0)
        return 2;
    if (FUN_00096600(name, "bowling_ball") == 0)
        return 3;
    if (FUN_00096600(name, "hammer_toss") == 0)
        return 4;
    if (FUN_00096600(name, "ball_and_chain") == 0)
        return 5;
    if (FUN_00096600(name, "missile_pack") == 0)
        return 6;
    return 0;
}


// 0x001d51f0 FUN_001d51f0 (260 B): equivalent/0x001d51f0.cpp
// sym: _FUN_001d51f0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_001d51f0 @ 0x001d51f0
extern "C" int __cdecl FUN_001d51f0(const char* material)
{
    if (FUN_00096600(material, "hardmetal") == 0) return 6;
    if (FUN_00096600(material, "softmetal") == 0) return 7;
    if (FUN_00096600(material, "hardwood") == 0) return 2;
    if (FUN_00096600(material, "softwood") == 0) return 3;
    if (FUN_00096600(material, "hardrubber") == 0) return 4;
    if (FUN_00096600(material, "softrubber") == 0) return 5;
    if (FUN_00096600(material, "concrete") == 0) return 8;
    if (FUN_00096600(material, "icy") == 0) return 10;
    if (FUN_00096600(material, "sticky") == 0) return 9;
    return 0;
}


// 0x001d5300 FUN_001d5300 (442 B): equivalent/0x001d5300.cpp
// sym: _FUN_001d5300
// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 32/32)
// FUN_001d5300 @ 0x001d5300
extern "C" int FUN_001d5300(const char *name)
{
    if (!FUN_00096600(name, "Power") || !FUN_00096600(name, "MajorHealth") ||
        !FUN_00096600(name, "MinorHealth") || !FUN_00096600(name, "PowerMinor"))
        return 1;
    if (!FUN_00096600(name, "PowerMedium")) return 2;
    if (!FUN_00096600(name, "PowerMajor")) return 3;
    if (!FUN_00096600(name, "PowerFull")) return 4;
    if (!FUN_00096600(name, "StoryMission")) return 6;
    if (!FUN_00096600(name, "SideMission")) return 5;
    if (!FUN_00096600(name, "Hint")) return 7;
    if (!FUN_00096600(name, "ComicBook")) return 8;
    if (!FUN_00096600(name, "Unlock")) return 9;
    if (!FUN_00096600(name, "SmashMinor")) return 11;
    if (!FUN_00096600(name, "SmashMedium")) return 12;
    if (!FUN_00096600(name, "SmashMajor")) return 13;
    if (!FUN_00096600(name, "RouteMarker")) return 10;
    return 0;
}


// 0x001d54c0 FUN_001d54c0 (114 B): matches/0x001d54c0.cpp
// sym: _FUN_001d54c0
extern "C" int FUN_001d54c0(const char* s) {
    int r = 0;
    if (!FUN_00096600(s, "minor"))
        r = 1;
    else if (!FUN_00096600(s, "medium"))
        r = 2;
    else if (!FUN_00096600(s, "major"))
        r = 3;
    else if (!FUN_00096600(s, "major_only_on_destruction"))
        r = 4;
    return r;
}


// 0x001d55d0 FUN_001d55d0 (82 B): matches/0x001d55d0.cpp
// sym: ?Dtor2@CSPHulkProp_1d55d0@fn_f590c0bf@@QAEXXZ
void CSPHulkProp_1d55d0::Dtor2() throw() {
    vf = vProp;
    _ReadWriteBarrier();
    if (p90) {
        p90->Release();
        p90 = 0;
    }
    if (pb8) {
        FUN_0008d340(pb8);
        pb8 = 0;
    }
    pc0.Fini();
    Entity_1d55d0::Dtor();
}


// 0x001d5630 FUN_001d5630 (181 B): equivalent/0x001d5630.cpp
// sym: ?target@Owner_1d5630@fn_f590c0bf@@QAEPAVCSPHulkPropInstance@@II@Z
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// FUN_001d5630 @ 0x001d5630
CSPHulkPropInstance* Owner_1d5630::target(hulk_uintptr a,unsigned b) {
 unsigned size;
 FUN_0008ceb0()->FUN_0008ced0(10,0,&size,0,0,0);
 if(size<0xc800) return 0;
 unsigned old=FUN_00266da0(10);
 CSPHulkPropInstance* obj=FUN_00263ea0(0x278);
 if(obj) obj=((CSPHulkPropInstance_nv_1d5630*)(((CSPHulkPropInstance*)(obj))))->FUN_001d7890(this,0);
 FUN_00266da0(old);
 unsigned v=(*(unsigned int *)&obj->f_9c);
 FUN_001c3d90()->FUN_001c3a40(a,v);
 Entry_1d5630* entry=FUN_001c3d90()->table->FUN_001c59d0(a);
 if(entry) { entry->enabled=1; entry->object=obj; entry->flag=flag; ((CSPHulkPropInstance_nv_1d5630*)(((CSPHulkPropInstance*)(obj))))->FUN_001d7490(entry); }
 return obj;
}


// 0x001d56f0 FUN_001d56f0 (19 B): matches/0x001d56f0.cpp
// sym: ?f@C_1d56f0@fn_f590c0bf@@QAEHH@Z
hulk_intptr C_1d56f0::f(int index) {
    return m->data[index];
}


// 0x001d5710 FUN_001d5710 (21 B): matches/0x001d5710.cpp
// sym: ?Count@Obj_1d5710@fn_f590c0bf@@QAEHXZ
int Obj_1d5710::Count() {
    Vec_1d5710* v = &p->v;
    return (v->last - v->first) >> 2;
}


// 0x001d5730 FUN_001d5730 (111 B): equivalent/0x001d5730.cpp
// sym: ?FUN_001d5730@Holder_1d5730@fn_f590c0bf@@QAEXPAVResource_1d5730@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001d5730 @ 0x001d5730
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void Holder_1d5730::FUN_001d5730(Resource_1d5730 *r)
{
    if (r != 0)
        r->AddRef();
    if (resource != 0)
        resource->Release();
    resource = r;
    if (buffer != 0) {
        thunk_FUN_00267090(buffer);
        buffer = 0;
    }
    buffer = FUN_0008d6d0((resource->end - resource->begin) * 4);
}

} // namespace fn_f590c0bf

// 0x001d5c50 CSPHulkProp::vfunc_2 (30 B): matches/0x001d5c50.cpp
// sym: ??_GCSPHulkProp@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CSPHulkProp::~CSPHulkProp() {}

namespace fn_f590c0bf {

// 0x001d5c70 FUN_001d5c70 (175 B): equivalent/0x001d5c70.cpp
// sym: ?FUN_001d5c70@CSPHulkPropInstance_1d5c70@fn_f590c0bf@@QAEJH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19928 inputs, branch coverage 14/14)
// FUN_001d5c70 @ 0x001d5c70
long CSPHulkPropInstance_1d5c70::FUN_001d5c70(int index) {
 U32_1d5c70 low, high;
 if (!((*(U32_1d5c70*)&DAT_004e23d8) & 1)) {
  (*(U32_1d5c70*)&DAT_004e23d8) |= 1;
  U64_1d5c70 key = FUN_0027b020("hitpoints");
  low = (U32_1d5c70)key; high = (U32_1d5c70)(key >> 32);
  (*(U32_1d5c70*)&DAT_004e23d0) = low; (*(U32_1d5c70*)&DAT_004e23d4) = high;
 } else { low = (*(U32_1d5c70*)&DAT_004e23d0); high = (*(U32_1d5c70*)&DAT_004e23d4); }
 if (index < 0) return -1;
 List_1d5c70* values = list;
 if (index >= values->end - values->begin) return -1;
 Item_1d5c70* item = values->begin[index];
 int count = item->count;
 if (count <= 0) return -1;
 Attribute* attr = item->attributes;
 for (int i=0; i<count; ++i, ++attr) {
  if (attr->low == low && attr->high == high) return _atol(attr->text);
 }
 return -1;
}


// 0x001d5d20 FUN_001d5d20 (175 B): equivalent/0x001d5d20.cpp
// sym: ?target@CSPHulkPropInstance_1d5d20@fn_f590c0bf@@QAEJH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19966 inputs, branch coverage 14/14)
// FUN_001d5d20 @ 0x001d5d20
long CSPHulkPropInstance_1d5d20::target(int index) {
 uint low, high;
 if (!((*(uint*)&DAT_004e23e8) & 1)) {
  (*(uint*)&DAT_004e23e8) |= 1;
  unsigned __int64 key = FUN_0027b020("target_priority");
  low = (uint)key; high = (uint)(key >> 32);
  (*(uint*)&DAT_004e23e0) = low; (*(uint*)&DAT_004e23e4) = high;
 } else { low = (*(uint*)&DAT_004e23e0); high = (*(uint*)&DAT_004e23e4); }
 if(index < 0) return 0;
 Collection_1d5d20* c = collection;
 hulk_intptr count = c->end - c->begin;
 if(index >= count) return 0;
 Item_1d5d20* item = c->begin[index];
 int n = item->count;
 if(n <= 0) return 0;
 Property_1d5d20* p = item->properties;
 for(int i=0; i<n; ++i, ++p) {
  if(p->low == low && p->high == high) return _atol(p->value);
 }
 return 0;
}


// 0x001d5dd0 FUN_001d5dd0 (175 B): equivalent/0x001d5dd0.cpp
// sym: ?target@Object@fn_f590c0bf@@QAEHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 1352 inputs, branch coverage 14/14)
// FUN_001d5dd0 @ 0x001d5dd0
int Object::target(int index) {
 uint low,high;
 if (!((*(uint*)&DAT_004e23f8) & 1)) {
  (*(uint*)&DAT_004e23f8) |= 1;
  unsigned __int64 key = FUN_0027b020("weaponizable_type");
  low = (uint)key; high = (uint)(key >> 32);
  (*(uint*)&DAT_004e23f0) = low; (*(uint*)&DAT_004e23f4) = high;
 } else { low=(*(uint*)&DAT_004e23f0); high=(*(uint*)&DAT_004e23f4); }
 if (index < 0) return 0;
 Collection_1d5dd0* c=collection;
 if (index >= c->end-c->begin) return 0;
 Entry_1d5dd0* e=c->begin[index];
 for (int i=0;i<e->count;++i) {
  Property_1d5dd0* p=&e->properties[i];
  if (p->low==low && p->high==high) return FUN_001d5140((const char *)(hulk_uintptr)(unsigned int)(p->value));
 }
 return 0;
}


// 0x001d5e80 FUN_001d5e80 (183 B): equivalent/0x001d5e80.cpp
// sym: ?FUN_001d5e80@CSPHulkPropInstance_1d5e80@fn_f590c0bf@@QAEHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 18951 inputs, branch coverage 14/14)
// FUN_001d5e80 @ 0x001d5e80
int CSPHulkPropInstance_1d5e80::FUN_001d5e80(int index) {
 unsigned int low, high;
 if (!((*(unsigned int*)&DAT_004e2408) & 1)) {
  (*(unsigned int*)&DAT_004e2408) |= 1;
  unsigned __int64 key = FUN_0027b020("weapon_type");
  low = (unsigned int)key; high = (unsigned int)(key >> 32);
  DAT_004e2400 = low; DAT_004e2404 = high;
 } else { low = DAT_004e2400; high = DAT_004e2404; }
 if (index < 0 || index >= entries->end - entries->begin) index = 0;
 Entry_1d5e80* entry = entries->begin[index];
 for (int i=0; i<entry->count; ++i) {
  Property_1d5e80* p = &entry->properties[i];
  if (p->keyLow == low && p->keyHigh == high) return FUN_001d5140((const char *)(void *)(p->value));
 }
 return 0;
}

} // namespace fn_f590c0bf

// 0x001d5f40 FUN_001d5f40 (186 B): equivalent/0x001d5f40.cpp [wrapped: conflict: Object; Object::target]
// sym: ?target@Object@fn_001d5f40@@QAE_NH@Z
namespace fn_001d5f40 {
// STATUS: equivalent (tools/equiv.py level 3: 1515 inputs, branch coverage 14/14)
// FUN_001d5f40 @ 0x001d5f40
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

typedef unsigned int uint;
extern "C" int __cdecl FUN_00096600(const char*, const char*);
struct Property_1d5f40 { uint low, high; const char* value; uint other; };
struct Item_1d5f40 { char pad[0x3c]; int count; Property_1d5f40* properties; };
struct Collection_1d5f40 { char pad[0x1c]; Item_1d5f40** begin; Item_1d5f40** end; };
struct Object { char pad[0x90]; Collection_1d5f40* collection; bool target(int index); };
bool Object::target(int index) {
 uint low, high;
 if (!((*(uint*)&DAT_004e2418) & 1)) {
  (*(uint*)&DAT_004e2418) |= 1;
  unsigned __int64 key = FUN_0027b020("electrified");
  low = (uint)key; high = (uint)(key >> 32);
  (*(uint*)&DAT_004e2410) = low; (*(uint*)&DAT_004e2414) = high;
 } else { low = (*(uint*)&DAT_004e2410); high = (*(uint*)&DAT_004e2414); }
 if (index < 0) return false;
 Collection_1d5f40* c = collection;
 if (index >= c->end - c->begin) return false;
 Item_1d5f40* item = c->begin[index];
 int count = item->count;
 Property_1d5f40* p = item->properties;
 for (int i = 0; i < count; ++i, ++p) {
  if (p->low == low && p->high == high) return FUN_00096600(p->value, "true") == 0;
 }
 return false;
}
} // namespace fn_001d5f40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001d6000 FUN_001d6000 (186 B): equivalent/0x001d6000.cpp [wrapped: conflict: Object]
// sym: ?check@Object@fn_001d6000@@QAE_NH@Z
namespace fn_001d6000 {
// STATUS: equivalent (tools/equiv.py level 3: 1590 inputs, branch coverage 14/14)
// FUN_001d6000 @ 0x001d6000
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

typedef unsigned int uint;
extern "C" int __cdecl FUN_00096600(const char*, const char*);
struct Property_1d6000 { uint low, high; const char* value; uint unused; };
struct Item_1d6000 { char pad[0x3c]; int count; Property_1d6000* properties; };
struct Collection_1d6000 { char pad[0x1c]; Item_1d6000** begin; Item_1d6000** end; };
struct Object { char pad[0x90]; Collection_1d6000* collection; bool check(int index); };
bool Object::check(int index) {
 uint low,high;
 if (!((*(uint*)&DAT_004e2428) & 1)) {
  (*(uint*)&DAT_004e2428) |= 1;
  unsigned __int64 key = FUN_0027b020("climbable");
  low=(uint)key; high=(uint)(key>>32);
  (*(uint*)&DAT_004e2420)=low; (*(uint*)&DAT_004e2424)=high;
 } else { low=(*(uint*)&DAT_004e2420); high=(*(uint*)&DAT_004e2424); }
 if(index<0) return false;
 Collection_1d6000* c=collection;
 hulk_intptr n=c->end-c->begin;
 if(index>=n) return false;
 Item_1d6000* item=c->begin[index];
 int count=item->count;
 if(count<=0) return false;
 Property_1d6000* p=item->properties;
 for(int i=0;i<count;++i,++p) {
  if(p->low==low && p->high==high) return FUN_00096600(p->value,"true")==0;
 }
 return false;
}
} // namespace fn_001d6000
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f590c0bf {

// 0x001d60c0 FUN_001d60c0 (215 B): equivalent/0x001d60c0.cpp
// sym: ?FUN_001d60c0@Object@fn_f590c0bf@@QAEHXZ
// STATUS: equivalent (tools/equiv.py level 3: 571 inputs, branch coverage 20/22, incomplete)
// FUN_001d60c0 @ 0x001d60c0
int Object::FUN_001d60c0() {
 int total=0;
 int value=FUN_001d5c70(0);
 if(value>0) total=value;
 int history[8]={-1,-1,-1,-1,-1,-1,-1,-1};
 int slot=0, current=0;
 for(int step=0;step<16;++step) {
  history[slot]=current; slot=(slot+1)%8;
  Node* node=table->nodes[current];
  bool found=false;
  for(int i=0;i<node->count;++i) {
   if(node->entries[i].type==13) {
    current=node->entries[i].next;
    found=true;
    if(current==0) return 1000;
    value=FUN_001d5c70(current);
    if(value>0) total+=value;
    for(int j=0;j<8;++j) if(history[j]==current) return 1000;
    break;
   }
  }
  if(!found) break;
 }
 return total;
}


// 0x001d6240 FUN_001d6240 (12 B): matches/0x001d6240.cpp
// sym: ?Target@X_1d6240@fn_f590c0bf@@QAEPAU12@XZ
// Same code shape as 0x00034ad0 (propagated; names are from that function)
X_1d6240* X_1d6240::Target() {
    Call();
    return this;
}


// 0x001d6270 FUN_001d6270 (28 B): matches/0x001d6270.cpp
// sym: ?FUN_001d6270@fn_f590c0bf@@YIXPAUObj_1d6270@1@@Z
void __fastcall FUN_001d6270(Obj_1d6270* self) {
    unsigned int x = self->p->f11();
    self->q->FUN(x);
}

} // namespace fn_f590c0bf

// 0x001d6290 FUN_001d6290 (13 B): matches/0x001d6290.cpp
// sym: ?FUN_001d6290@Target_1d6290@owners@@QAEXE@Z
void owners::Target_1d6290::FUN_001d6290(unsigned char x) {
    value = x;
}

namespace fn_f590c0bf {

// 0x001d62a0 FUN_001d62a0 (7 B): matches/0x001d62a0.cpp
// sym: ?Target@fn_f590c0bf@@YIEPAVC_1d62a0@1@@Z
unsigned char __fastcall Target(C_1d62a0* self) {
    return self->value;
}

} // namespace fn_f590c0bf

// 0x001d62b0 FUN_001d62b0 (13 B): matches/0x001d62b0.cpp
// sym: ?FUN_001d62b0@C_1d62b0@owners@@QAEXE@Z
void owners::C_1d62b0::FUN_001d62b0(unsigned char x) {
    value = x;
}


// 0x001d62c0 FUN_001d62c0 (7 B): matches/0x001d62c0.cpp
// sym: ?FUN_001d62c0@Obj_1d62c0@owners@@QAEEXZ
unsigned char owners::Obj_1d62c0::FUN_001d62c0() {
    return value;
}


// 0x001d62d0 FUN_001d62d0 (218 B): equivalent/0x001d62d0.cpp [wrapped: conflict: Node]
// sym: ?FUN_001d62d0@Object@fn_001d62d0@@QAEHXZ
namespace fn_001d62d0 {
// STATUS: equivalent (tools/equiv.py level 3: 518 inputs, branch coverage 20/22, incomplete)
// FUN_001d62d0 @ 0x001d62d0
struct Entry_1d62d0 { int a,b,type,next; };
struct Node { char pad[0x24]; int count; Entry_1d62d0* entries; };
struct Manager_1d62d0 { Node* FUN_001d56f0(int); int FUN_001d5c70(int); };
struct Object { char pad0[0x40]; int start; char pad1[0xa8]; Manager_1d62d0* manager; char pad2[0x18]; int value; int FUN_001d62d0(); };
int Object::FUN_001d62d0() {
 int total=value>0?value:0;
 int current=start;
 int history[8]; for(int i=0;i<8;++i) history[i]=-1;
 int slot=0;
 for(int iteration=0;iteration<16;++iteration) {
  bool found=false;
  history[slot]=current; slot=(slot+1)%8;
  Node* node=manager->FUN_001d56f0(current);
  for(int j=0;j<node->count;++j) {
   Entry_1d62d0* e=&node->entries[j];
   if(e->type==13) {
    current=e->next; found=true;
    if(current==start) return 1000;
    int amount=manager->FUN_001d5c70(current);
    if(amount>0) total+=amount;
    for(int k=0;k<8;++k) if(current==history[k]) return 1000;
    break;
   }
  }
  if(!found) break;
 }
 return total;
}
} // namespace fn_001d62d0


// 0x001d63b0 FUN_001d63b0 (24 B): matches/0x001d63b0.cpp
// sym: ?FUN_001d63b0@C_1d63b0@owners@@QAEXH@Z
void owners::C_1d63b0::FUN_001d63b0(int x) {
    value = x;
    if (x > 0)
        flag = 1;
}


// 0x001d6490 FUN_001d6490 (7 B): matches/0x001d6490.cpp
// sym: ?FUN_001d6490@C_1d6490@owners@@QAEHXZ
hulk_intptr owners::C_1d6490::FUN_001d6490() {
    return value;
}

