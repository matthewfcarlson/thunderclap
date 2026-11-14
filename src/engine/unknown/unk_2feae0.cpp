// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002feae0..0x00301620 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "decls/physics_world.h"
#define TREE_TU_BEGIN namespace fn_fb493392 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb493392 {} using namespace fn_fb493392;
namespace fn_fb493392 { extern "C" char DAT_00431ac0[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fb493392 {
typedef unsigned int uint_2feb70;
struct Source_2ff0c0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void activate(); char pad[0x15]; unsigned char active; };
struct Destination_2ff0c0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int type(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void attach(Source_2ff0c0*,int); };
struct SourceEntry_2ff0c0 { char pad[0x20]; Source_2ff0c0* source; };
struct DestEntry_2ff0c0 { char pad[0x10]; Destination_2ff0c0* destination; };
struct Group_2ff0c0 { char pad[0x10]; SourceEntry_2ff0c0** sources; SourceEntry_2ff0c0** sourcesEnd; char pad2[8]; DestEntry_2ff0c0** destinations; DestEntry_2ff0c0** destinationsEnd; char pad3[0x44]; };
struct Manager_2ff0c0 { Group_2ff0c0* groups; char pad[0x54]; int state; void target(int index); };
struct V3_2ff200 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Target;
struct Element_2ff200 {
    char pad00[0x20];
    Target *owner;           // 0x20
    char pad24[0x50 - 0x24];
    char f50;
    char pad51[0x72 - 0x51];
    char f72;
};
struct Group_2ff200 {
    Element_2ff200 **begin;         // 0x00
    Element_2ff200 **end;           // 0x04
    char pad08[0x50 - 8];
    char active;             // 0x50
    char pad51[0x6c - 0x51];
};
struct Query_2ff200 {
    char pad00[8];
    Target *target;          // 0x08
};
char __cdecl FUN_002f15a0(V3_2ff200 *from, V3_2ff200 *dir, V3_2ff200 *delta, float len, Target *skip, Query_2ff200 *q);
class Tracer_2ff200 {
public:
    Group_2ff200 *groups;           // 0x00
    int count;               // 0x04

    char FUN_002ff200(Query_2ff200 *q, V3_2ff200 *from, V3_2ff200 *to, char flag, int index);
};
struct Body_2ff3f0 {
    char pad0[0x7c];
    float limit;
};
struct Actor_2ff3f0 {
    char pad0[0x18];
    Body_2ff3f0 *body;
    char pad1c[0x4c];
    char hit68;
    char hit69;
};
struct Link_2ff3f0 {
    Actor_2ff3f0 *a;
    Actor_2ff3f0 *b;
    int f8;
    float maxLimit;
    char active;
    char pad11[3];
};
class ActorSet {
public:
    Actor_2ff3f0 **begin;
    Actor_2ff3f0 **end;
    char pad8[0x28];
    Link_2ff3f0 *linkBegin;
    Link_2ff3f0 *linkEnd;

    void FUN_002ff3f0(unsigned char flags);
};
struct Vec3_2ff530 { float x, y, z; };
struct Shape_2ff530 {
    char pad0[0x10];
    int f10;
};
struct Hit_2ff530 {
    int f0;
    int f4;
    Shape_2ff530 *shape;
};
struct Elem_2ff530 {
    char pad0[0x20];
    Shape_2ff530 *shape;
    char pad24[0x50 - 0x24];
    unsigned char flag50;
    char pad51[0x72 - 0x51];
    unsigned char flag72;
};
extern "C" bool FUN_002f0780(Vec3_2ff530 a, Vec3_2ff530 b, Vec3_2ff530 *c, Vec3_2ff530 d, int e, int f);
extern "C" bool FUN_002f1160(void *a, int b, Vec3_2ff530 *c, int d, Hit_2ff530 *out);
extern "C" void FUN_002f24f0(void *a, Hit_2ff530 *hit, int b, Vec3_2ff530 *c, int *d);
struct Group_2ff530 {
    Elem_2ff530 **begin;
    Elem_2ff530 **end;
    char pad8[0x50 - 8];
    unsigned char active;
    char pad51[3];
    Vec3_2ff530 v54;
    Vec3_2ff530 v60;
    void Run(void *a0, Vec3_2ff530 *a1, int a2, Vec3_2ff530 *a3, int *a4, bool a5);
};
extern "C" void __cdecl FUN_002feb70(unsigned int *, int, int, unsigned int);
struct Item { char data[0x6c]; void FUN_002ff3f0(int); };
struct Container { Item* items; char pad4[4]; int* begin; int* end; char pad10[0x218c]; int value; void FUN_002ff910(); };
struct Entry {
  public:
    int *begin;
    int *end;
    char _m_pad_8[0x48];
    unsigned char active;
    char _m_pad_51[0x1b];
};
struct Vec3_2ffa00 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Aux_2ffa00 {
    char pad0[0x10];
    hulk_intptr field10;
};
struct Node {
    char pad0[0x20];
    Aux_2ffa00 *aux;
    char pad24[0x2c];
    char flag50;
    char pad51[0x21];
    char flag72;
};
struct Group_2ffa00 {
    char pad0[4];
    Node *node;
};
struct Rec_2ffa00 {
    int zero;
    Node *node;
    Aux_2ffa00 *aux;
};
} // namespace fn_fb493392
struct World {
    int count;
    char pad4[4];
    Group_2ffa00 *group;
};
namespace fn_fb493392 {
bool __cdecl FUN_002f1160(Vec3_2ffa00 *from, Vec3_2ffa00 *v, Vec3_2ffa00 *d, float dist, Rec_2ffa00 *r);
void __cdecl FUN_002f24f0(World *w, Rec_2ffa00 *r, Vec3_2ffa00 *v, Vec3_2ffa00 *d, float *dist);
struct Item_2ffa00 {
    char pad0[0x6c];
    void FUN_002ff530(World *w, Vec3_2ffa00 *from, Vec3_2ffa00 *v, Vec3_2ffa00 *d, float *dist, char flag);
};
class Probe_2ffa00 {
public:
    Item_2ffa00 *items;
    int count;
    bool FUN_002ffa00(World *w, Vec3_2ffa00 *from, Vec3_2ffa00 *to, char flag, int index);
};
extern "C" void __cdecl FUN_002ff860(unsigned int *, int, int, unsigned int);
} // namespace fn_fb493392
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void * __cdecl bsearch(const void *, const void *, unsigned, unsigned, int (__cdecl *)(const void *, const void *));
#endif
namespace fn_fb493392 {
int __cdecl FUN_002feae0(const void *, const void *);
struct Search { Entry *entries; int count; };
struct Edge_300080 {
    int a;
    int b;
    int c;
    int d;
    int e;
};
struct Graph_300080 {
    char pad0[0x30];
    Edge_300080 *begin;
    Edge_300080 *end;
    void FUN_00300080(int a, int b);
};
struct UIntRange_300100 {
    unsigned int *first;
    unsigned int *second;
};
extern "C" void __cdecl FUN_002ffce0(unsigned int *, unsigned int *, unsigned int *);
struct Obj_300360 {
    virtual void v0();
    virtual void Release();
};
struct ObjArray {
    Obj_300360** begin;
    Obj_300360** end;
    int pad[2];
};
class Container_300360 {
public:
    ObjArray a;
    ObjArray b;
    ObjArray c;
    ObjArray d;
    ObjArray e;
    void FUN_00300360();
};
class Obj_300400 {
  public:
    char pad[0x40];
    int a;
    int b;
    void Copy();
};
struct State_300410 { char pad[0x19]; unsigned char enabled; };
struct Item_300410 { char pad0[0x20]; State_300410* state; char pad1[0x2c]; unsigned char flag50; char pad2[0x17]; unsigned char flag68; unsigned char flag69; char pad3; unsigned char flag6b; };
struct Entry_300410 { Item_300410* first; Item_300410* second; char pad[12]; void FUN_002f8e80(); };
struct Owner_300410 { char pad[0x30]; Entry_300410* begin; Entry_300410* end; char pad2[8]; unsigned int current; unsigned int previous; void FUN_00300410(hulk_uintptr flags); };
struct Resource_3005e0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
};
struct Entry_3005e0 { char pad[12]; Resource_3005e0* first; Resource_3005e0* second; };
struct Item_3005e0 { char pad0[0x28]; int count; char pad2[4]; Entry_3005e0* entries; char pad3[0x3d]; unsigned char active; };
struct Vector { char data[16]; };
struct Row_3005e0 { Item_3005e0** begin; Item_3005e0** end; char pad[0x28]; Vector a; Vector b; unsigned char active; char tail[0x1b]; void FUN_00300410(void*); };
struct Processor {   };
struct Owner_3005e0 { Row_3005e0* rows; char pad0[0x24]; Processor processor; char pad1[0x2173]; void* context; void FUN_003005e0(int, void*); };
struct Obj_3006e0 {
    char data[0x6c];
    void FUN_002ff3f0(int arg);
};
class Group_3006e0 {
public:
    Obj_3006e0 *objs;
    char pad04[4];
    int *begin;
    int *end;
    char pad10[0x20];
    void *cursor;
    char pad34[0x2198 - 0x34];
    char active;
    char pad2199[3];
    int param;

    void FUN_003005e0(int index, int arg);
    void FUN_002ff0c0(int index);
    void FUN_003006e0(int arg);
};
struct Vec3_300780 {
    float x, y, z;
};
struct Edge_300780 {
    void *a;
    void *b;
    int c;
    int d;
    char e;
    char pad11[3];
};
struct Body_300780 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Vec3_300780 *vfunc_3();
    char pad04[0x28 - 4];
    Vec3_300780 half;
};
struct Item_300780 {
    char pad00[0x20];
    Body_300780 *body;
};
struct Group_300780 {
    Item_300780 **begin;
    Item_300780 **end;
    char pad08[0x30 - 8];
    Edge_300780 *edgeBegin;
    Edge_300780 *edgeEnd;
    Edge_300780 *edgeCap;
};
struct Box_300780 {
    Vec3_300780 lo;
    Vec3_300780 hi;
};
struct GridPart {
    char pad00[0x2024];
    Box_300780 *boxes;
    short *links;
    short *heads;
    char pad2030[4];
    unsigned flags;
    void FUN_00312db0(hulk_intptr n);
    int FUN_00313450(hulk_intptr n);
};
class Broadphase_300780 {
public:
    Group_300780 *group;
    char pad04[0x168 - 4];
    GridPart grid;
    void FUN_003006e0(int arg);
    void FUN_002ff1b0(int arg);
    void FUN_00300780(int arg);
};
struct Item_300930 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); };
struct Entry_300930 { char pad[12]; Item_300930* first; Item_300930* second; };
struct Input_300930 { char pad[40]; int count; int unknown; Entry_300930* entries; char rest[61]; unsigned char enabled; };
struct Buffer_300930 { char* begin; char* end; char* capacity; };
struct Worker_300930 {  };
struct Receiver_300930 { void FUN_002f8020(Buffer_300930*,int,int); };
struct Owner_300930 { char pad[40]; Worker_300930 worker; char gap[63]; Receiver_300930 receiver; void target(Input_300930*,int); };
extern "C" void *FUN_0008d6d0(unsigned int size);
struct Buffer_300a00 {
    char *begin;
    char *end;
    char *cap;
    unsigned int pad;
};
class Pools {
public:
    Buffer_300a00 a;
    Buffer_300a00 c;
    Buffer_300a00 d;
    Buffer_300a00 b;
    Buffer_300a00 e;
    unsigned char flag;
    char pad51[3];
    unsigned int f54, f58, f5c, f60, f64, f68;

    Pools *FUN_00300a00();
};
extern void __cdecl Release_0008d340(void*);
struct Elem_300ea0 {
    char data[0x6c];
    Elem_300ea0 *FUN_00300a00();
};
struct ElemArray_300ea0 {
    void FUN_00300d80(int flags);
};
class ElemPool {
public:
    Elem_300ea0 *elems;            // 0
    int count;              // 4
    int *indices;           // 8
    int *begin;             // 0xc
    int *end;               // 0x10
    void FUN_00300ea0(int n);
};
class Small_300fa0 {
  public:
    void FnA_00300d80(int);
    void FnB_002f79f0();
    void FnC_003012c0();
    void FnD_00304350();
};
class Obj_300fa0 {
  public:
    int* p0;
    int p4;
    int* p8;
    int* pc;
    char pad10[8];
    Small_300fa0 s18;
    char pad19[15];
    Small_300fa0 s28;
    char pad29[63];
    Small_300fa0 s68;
    Obj_300fa0* Run(unsigned char flags);
};
void relA_0008d340(void*);
void relB_0008d330(void*);
struct Vec3_3011a0 {
    float x, y, z;
};
struct Xf_3011a0 {
    char pad[0x28];
    Vec3_3011a0 pos;
};
struct Ent_3011a0 {
    char pad[0x20];
    Xf_3011a0* xf;
};
struct Slot_3011a0 {
    char pad[0x6c];
    void Process_003010a0(Ent_3011a0* e, unsigned flags);
};
struct Sub_3011a0 {
    void Add_00312fa0(Vec3_3011a0* v);
};
class Sim_3011a0 {
  public:
    Slot_3011a0* mSlots;
    char pad[0x164];
    Sub_3011a0 mSub;
    char pad2[0x2033];
    unsigned mFlags;
    void Update(Ent_3011a0* e, int i);
};
// (x64t4) the environment (DAT_00554c10, 0x002ecf60): pure3d::Entity's words, then its floats (the damping word
// at 0x30 on the 32-bit builds)
struct Owner_301290 {
    void* vftable;
    char pad04[0xc];
    float f10[8];
    int value;
};
extern int hulk_at_00431ac0;
// (x64t4) the base physics::SubCollisionDetector by address (its constructor 0x00313500, unk_312d50.cpp) with the
// words it writes: was an empty local class (unbound natively) under a 0x40-byte pad
// (x64t9-pw) the collision detector's words (decls/physics_world.h HulkCollisionDetector): the word at 8 is the
// contact vector, a pointer
struct FUN_00313500 {
    void* vftable;
    int a;
    void* b;
    int c, d;
    char pad[0x20];
    char x, y;
    int z;
    FUN_00313500();
};
class CollisionDetector : public FUN_00313500 {
  public:
    int f3c;
    CollisionDetector();
};
#define HULK_AT_(T, m) ((int)(hulk_uintptr)&((T*)0)->m)
typedef char hulk_detector_view_[(sizeof(CollisionDetector) == sizeof(HulkCollisionDetector) &&
    HULK_AT_(CollisionDetector, b) == HULK_AT_(HulkCollisionDetector, contacts) &&
    HULK_AT_(CollisionDetector, d) == HULK_AT_(HulkCollisionDetector, tolerance) &&
    HULK_AT_(CollisionDetector, z) == HULK_AT_(HulkCollisionDetector, flags) &&
    HULK_AT_(CollisionDetector, f3c) == HULK_AT_(HulkCollisionDetector, m3c)) ? 1 : -1];
#undef HULK_AT_
void __fastcall FUN_00313530(CEffectStopTrack*);
struct Vec3_301310 { float x,y,z; };
struct Shape_301310 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual Vec3_301310* position();
 char pad[0x40];
 Vec3_301310 direction;
 float distance;
 unsigned int value;
 unsigned char special;
};
struct Context {
 char pad[0xc]; float a,b;
 void FUN_00317610(unsigned int, Shape_301310*, Vec3_301310*, unsigned int);
 void FUN_00315860(unsigned int, Shape_301310*);
 void FUN_00319270(unsigned int, Shape_301310*);
 void FUN_00315ca0(unsigned int, Shape_301310*);
 void FUN_003160f0(unsigned int, Shape_301310*);
 void target(hulk_uintptr, Shape_301310*);
};
struct Receiver {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4();
};
struct Object {
  public:
    Entry *entries;
    char _m_pad_4[0x4];
    unsigned int *first;
    unsigned int *last;
    char _m_pad_10[0x4];
    float x;
    float y;
    float z;
    char _m_pad_20[0x30];
    unsigned char flag;
    void FUN_002ff9c0();
    void FUN_00317610(int a, Receiver* receiver, int result, int value);
    void FUN_00301410(int a, Receiver* receiver, int value);
};
struct Pair_2ffc00 { Object* first; Object* second; unsigned int a,b,c;  };
struct Container_2ffc00 { char pad[0x30]; Pair_2ffc00* begin; Pair_2ffc00* end; Pair_2ffc00* capacity; void FUN_002ffc00(Object* first, Object* second); };
struct Vec3_301460 {
    float x, y, z;
};
struct Probe_301460 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int Sample();    // slot 4
    char pad04[0x30];
    int field34;             // 0x34
};
struct Link_301460 {
    int first;
};
class Body_301460 {
public:
    char pad00[0x14];
    float vx, vy, vz;        // 0x14
    char pad20[0xc];
    Link_301460 link;               // 0x2c
    bool FUN_00314430(int a, int sample, int field, Vec3_301460 *w, Link_301460 *l, Vec3_301460 *v, Vec3_301460 *u, int one);
    void FUN_00314be0(int a, Vec3_301460 *v, Probe_301460 *p, Vec3_301460 *u, int first, Vec3_301460 *w);
    void FUN_00301460(hulk_intptr a, Probe_301460 *probe);
};
struct Vec_3014f0 { float x,y,z; };
struct Body_3014f0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual Vec_3014f0* position();
 char pad[0x30]; float radius;
};
struct Contact_3014f0 {
 char pad[0x14]; Vec_3014f0 normal; char pad2[0xc]; float distance;
 void FUN_00314be0(Body_3014f0*,Vec_3014f0*,Body_3014f0*,Vec_3014f0*,float,Vec_3014f0*);
 void target(Body_3014f0*,Body_3014f0*);
};


// 0x002feae0 FUN_002feae0 (25 B): matches/0x002feae0.cpp
// sym: ?FUN_002feae0@fn_fb493392@@YAIPAI0@Z
// Same code shape as 0x002e66a0 (propagated; names are from that function)
unsigned int FUN_002feae0(unsigned int* a, unsigned int* b) {
    if (*a < *b)
        return 0xffffffff;
    return (unsigned int)(*b < *a);
}


// 0x002feb70 FUN_002feb70 (74 B): matches/0x002feb70.cpp
// sym: _FUN_002feb70
extern "C" void __cdecl FUN_002feb70(unsigned int * p, int n, int limit, unsigned int value) {
    int parent = (n - 1) / 2;
    if (limit < n) {
        do {
            uint_2feb70 x = p[parent];
            if (x >= value)
                break;
            p[n] = x;
            n = parent;
            parent = (n - 1) / 2;
        } while (limit < n);
    }
    p[n] = value;
}


// 0x002febc0 FUN_002febc0 (150 B): equivalent/0x002febc0.cpp
// sym: ?FUN_002febc0@fn_fb493392@@YAXPAH00@Z @fff34162d876 @w209cc2860326
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 17/18, incomplete)
// FUN_002febc0 @ 0x002febc0
// std::rotate for a range of 4-byte elements (cycle-leader algorithm)
void FUN_002febc0(int *first, int *middle, int *last)
{
    int shift = (int)(middle - first);
    int total = (int)(last - first);
    int cycles = total;
    for (int factor = shift; factor != 0;) {
        int rem = cycles % factor;
        cycles = factor;
        factor = rem;
    }
    if (cycles < total) {
        for (; cycles > 0; --cycles) {
            int *hole = first + cycles;
            int *next = hole;
            int holeValue = *hole;
            int *next1 = (next + shift == last) ? first : next + shift;
            while (next1 != hole) {
                *next = *next1;
                next = next1;
                int left = (int)(last - next1);
                next1 = (shift < left) ? next1 + shift : first + (shift - left);
            }
            *next = holeValue;
        }
    }
}


// 0x002ff0c0 FUN_002ff0c0 (225 B): equivalent/0x002ff0c0.cpp
// sym: ?target@Manager_2ff0c0@fn_fb493392@@QAEXH@Z @524296d1a85a @wdbf89ec5088e
// STATUS: equivalent (tools/equiv.py level 3: 356 inputs, branch coverage 12/12)
// FUN_002ff0c0 @ 0x002ff0c0
void Manager_2ff0c0::target(int index) {
 unsigned int i=0;
 while(i < (unsigned int)(groups[index].sourcesEnd-groups[index].sources)) {
  Source_2ff0c0* source=groups[index].sources[i]->source;
  if(!source->active) source->activate();
  unsigned int j=0;
  while(j < (unsigned int)(groups[index].destinationsEnd-groups[index].destinations)) {
   state=0;
   Destination_2ff0c0* destination=groups[index].destinations[j]->destination;
   if(destination->type()==4) destination->attach(source,1);
   ++j;
  }
  ++i;
 }
}

} // namespace fn_fb493392

// 0x002ff1b0 FUN_002ff1b0 (80 B): equivalent/0x002ff1b0.cpp [wrapped: merged class would differ: Owner: field entry: Field(+0x40 Entry entry) vs Field(+0x40 Entry entry)]
// sym: ?FUN_002ff1b0@Controller@fn_002ff1b0@@QAEXI@Z @b6ef8a9a3c2d @we4ffcd241405
namespace fn_002ff1b0 {
// STATUS: equivalent (tools/equiv.py level 3: 798 inputs, branch coverage 6/6)
// FUN_002ff1b0 @ 0x002ff1b0
struct Entry { char pad[0x10]; char active; }; struct Owner { char pad[0x40]; Entry entry; }; struct Helper { void FUN_002f8020(void*, unsigned int, int); }; struct Controller { Owner* owner; char pad0[4]; int* begin; int* end; char pad1[0x58]; Helper helper; void FUN_002ff1b0(unsigned int value); }; void Controller::FUN_002ff1b0(unsigned int value) { for (unsigned int i = 0; i < (unsigned int)(end - begin); ++i) { char* entry = (char*)owner + begin[i] * 0x6c; if (entry[0x50]) helper.FUN_002f8020(entry + 0x40, value, 0); } }
} // namespace fn_002ff1b0

namespace fn_fb493392 {

// 0x002ff200 FUN_002ff200 (492 B): equivalent/0x002ff200.cpp
// sym: ?FUN_002ff200@Tracer_2ff200@fn_fb493392@@QAEDPAUQuery_2ff200@2@PAUV3_2ff200@2@1DH@Z @2e3d1ac24d6e @w28d023408222
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 42/46, incomplete)
// FUN_002ff200 @ 0x002ff200
char Tracer_2ff200::FUN_002ff200(Query_2ff200 *q, V3_2ff200 *from, V3_2ff200 *to, char flag, int index)
{
    V3_2ff200 d;
    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    V3_2ff200 v = d;
    float len = v.FUN_0022d110();
    char hit = 0;

    if (q->target != 0) {
        hit = FUN_002f15a0(from, &v, &d, len, q->target, q);
        if (hit)
            return hit;
    }

    if (index == -1) {
        for (int i = 0; i < count; i++) {
            if (groups[i].active) {
                for (unsigned j = 0; j < (unsigned)(groups[i].end - groups[i].begin); j++) {
                    Element_2ff200 *e = groups[i].begin[j];
                    if (e->f72 && e->owner != q->target && (!flag || e->f50)) {
                        hit = FUN_002f15a0(from, &v, &d, len, e->owner, q);
                        if (hit)
                            break;
                    }
                }
            }
        }
        if (hit)
            return hit;
    } else if (index >= 0 && index < count) {
        for (unsigned j = 0; j < (unsigned)(groups[index].end - groups[index].begin); j++) {
            Element_2ff200 *e = groups[index].begin[j];
            if (e->f72 && e->owner != q->target && (!flag || e->f50)) {
                hit = FUN_002f15a0(from, &v, &d, len, e->owner, q);
                if (hit)
                    return hit;
            }
        }
        if (hit)
            return hit;
    }
    q->target = 0;
    return hit;
}


// 0x002ff3f0 FUN_002ff3f0 (318 B): equivalent/0x002ff3f0.cpp
// sym: ?FUN_002ff3f0@ActorSet@fn_fb493392@@QAEXE@Z @4450e168c792 @w5eb7b44ad88a
// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 26/26)
// FUN_002ff3f0 @ 0x002ff3f0
void ActorSet::FUN_002ff3f0(unsigned char flags)
{
    unsigned i;
    unsigned j;

    if (flags & 4) {
        for (i = 0; i < (unsigned)(end - begin); i++) {
            begin[i]->hit69 = 0;
            begin[i]->hit68 = 0;
        }
        return;
    }
    if (DAT_00555480 == 0) {
        for (i = 0; i < (unsigned)(end - begin); i++) {
            begin[i]->hit69 = 0;
            begin[i]->hit68 = 0;
        }
        return;
    }
    for (i = 0; i < (unsigned)(end - begin); i++) {
        Actor_2ff3f0 *a = begin[i];
        a->hit69 = 0;
        a->hit68 = 0;
        a->body->limit = DAT_004d2f14;
    }
    for (j = 0; j < (unsigned)(linkEnd - linkBegin); j++) {
        Link_2ff3f0 *l = &linkBegin[j];
        if (l->active != 0) {
            Body_2ff3f0 *p = l->a->body;
            p->limit = (p->limit < l->maxLimit) ? p->limit : l->maxLimit;
            l = &linkBegin[j];
            p = l->b->body;
            p->limit = (p->limit < l->maxLimit) ? p->limit : l->maxLimit;
        }
    }
}


// 0x002ff530 FUN_002ff530 (421 B): equivalent/0x002ff530.cpp
// sym: ?Run@Group_2ff530@fn_fb493392@@QAEXPAXPAUVec3_2ff530@2@H1PAH_N@Z @c7e5c9f88338 @wb8b6f87703e9
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 24/28, incomplete)
// FUN_002ff530 @ 0x002ff530
void Group_2ff530::Run(void *a0, Vec3_2ff530 *a1, int a2, Vec3_2ff530 *a3, int *a4, bool a5)
{
    if (!active)
        return;

    Hit_2ff530 hit;
    hit.f0 = 0;
    hit.f4 = 0;
    hit.shape = 0;

    if (!(v54.x == 0.0f && v54.y == 0.0f && v54.z == 0.0f &&
          v60.x == 0.0f && v60.y == 0.0f && v60.z == 0.0f)) {
        Vec3_2ff530 sum;
        sum.x = a1->x + a3->x;
        sum.y = a1->y + a3->y;
        sum.z = a1->z + a3->z;
        if (!FUN_002f0780(*a1, sum, &v54, v60, 0, 0))
            return;
    }

    unsigned int i = 0;
    while (i < (unsigned int)(end - begin)) {
        Elem_2ff530 *e = begin[i];
        hit.shape = e->shape;
        if (e->flag72 && (!a5 || e->flag50)) {
            if (FUN_002f1160(a1, a2, a3, *a4, &hit)) {
                hit.f4 = hit.shape->f10;
                FUN_002f24f0(a0, &hit, a2, a3, a4);
            }
        }
        i++;
    }
}


// 0x002ff860 FUN_002ff860 (90 B): matches/0x002ff860.cpp
// sym: _FUN_002ff860
extern "C" void FUN_002ff860(unsigned int* data, int index, int count, unsigned int value) {
    int orig = index;
    int child = index * 2 + 2;
    if (child < count) {
        do {
            unsigned int v = data[child];
            if (v < data[child - 1])
                --child;
            v = data[child];
            data[index] = v;
            index = child;
            child = child * 2 + 2;
        } while (child < count);
    }
    if (child == count) {
        data[index] = data[count - 1];
        index = count - 1;
    }
    FUN_002feb70(data, index, orig, value);
}


// 0x002ff910 FUN_002ff910 (61 B): equivalent/0x002ff910.cpp
// sym: ?FUN_002ff910@Container@fn_fb493392@@QAEXXZ @10de32c259ca @wb24563f7f841
// STATUS: equivalent (tools/equiv.py level 3: 2246 inputs, branch coverage 4/4)
// FUN_002ff910 @ 0x002ff910
void Container::FUN_002ff910() { for (unsigned int i=0; i<(unsigned int)((int)((char*)end-(char*)begin)>>2); ++i) items[begin[i]].FUN_002ff3f0(value); }


// 0x002ff9c0 FUN_002ff9c0 (57 B): equivalent/0x002ff9c0.cpp
// sym: ?FUN_002ff9c0@Object@fn_fb493392@@QAEXXZ @8fec92570bec @weca632bdd3e7
// STATUS: equivalent (tools/equiv.py level 3: 144 inputs, branch coverage 4/4)
// FUN_002ff9c0 @ 0x002ff9c0
void Object::FUN_002ff9c0() {
    for (unsigned int i = 0; i < (unsigned int)(last - first); ++i)
        entries[first[i]].active = 0;
    last = first;
}


// 0x002ffa00 FUN_002ffa00 (385 B): equivalent/0x002ffa00.cpp
// sym: ?FUN_002ffa00@Probe_2ffa00@fn_fb493392@@QAE_NPAUWorld@@PAUVec3_2ffa00@2@1DH@Z @a0e1c0aa61e4 @wca2901449f00
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 26/26)
// FUN_002ffa00 @ 0x002ffa00
bool Probe_2ffa00::FUN_002ffa00(World *w, Vec3_2ffa00 *from, Vec3_2ffa00 *to, char flag, int index)
{
    Vec3_2ffa00 d;
    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    Vec3_2ffa00 v = d;
    float dist = v.FUN_0022d110();
    if ((*(char*)&DAT_00554c1c) && w->count > 0) {
        Rec_2ffa00 r;
        r.aux = 0;
        r.node = 0;
        r.zero = 0;
        Node *n = w->group->node;
        r.node = n;
        w->count = 0;
        r.aux = n->aux;
        if (n->flag72 && (!flag || n->flag50)) {
            if (FUN_002f1160(from, &v, &d, dist, &r)) {
                r.node = (Node *)r.aux->field10;
                FUN_002f24f0(w, &r, &v, &d, &dist);
            }
        }
    }
    if (index == -1) {
        for (int i = 0; i < count; i++)
            items[i].FUN_002ff530(w, from, &v, &d, &dist, flag);
    } else if (index >= 0 && index < count) {
        items[index].FUN_002ff530(w, from, &v, &d, &dist, flag);
    }
    return w->count > 0;
}


// 0x002ffc00 FUN_002ffc00 (136 B): equivalent/0x002ffc00.cpp
// sym: ?FUN_002ffc00@Container_2ffc00@fn_fb493392@@QAEXPAUObject@2@0@Z @a0fe109f0c70 @we6cf7bcf6a93
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 18/18)
// FUN_002ffc00 @ 0x002ffc00
void Container_2ffc00::FUN_002ffc00(Object* first,Object* second) {
 for(Pair_2ffc00* p=begin;p!=end;++p) {
  if((p->first==first || p->second==first) && (p->first==second || p->second==second)) return;
 }
 Pair_2ffc00 local;
 Pair_2ffc00* source;
 if(first->flag) source=((Pair_2ffc00 *)((owners::X_2f8ef0 *)&local)->FUN_002f8ef0((hulk_uintptr)(Object *)first, (hulk_uintptr)(Object *)second));
 else source=((Pair_2ffc00 *)((owners::X_2f8ef0 *)&local)->FUN_002f8ef0((hulk_uintptr)(Object *)second, (hulk_uintptr)(Object *)first));
 Pair_2ffc00* dest=end;
 if((hulk_uintptr)dest >= (hulk_uintptr)capacity) return;
 end=(Pair_2ffc00*)((hulk_uintptr)dest+sizeof(Pair_2ffc00));
 if(dest) {
 dest->first=source->first; dest->second=source->second; dest->a=source->a; dest->b=source->b; dest->c=source->c;
 }
}


// 0x002ffce0 FUN_002ffce0 (287 B): equivalent/0x002ffce0.cpp
// sym: _FUN_002ffce0 @b90cbbcfac42 @w26f5def4a45f
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 32/32)
// FUN_002ffce0 @ 0x002ffce0
extern "C" void __cdecl FUN_002ffce0(unsigned int* first, unsigned int* middle, unsigned int* last)
{
    unsigned int a,b;
    hulk_intptr count = last-first;
    if(count > 40) {
        hulk_intptr step=(count+1)/8;
        unsigned int* p=first+step;
        unsigned int* q=first+2*step;
        a=*p; b=*first; if(a<b){*p=b;*first=a;}
        a=*q; b=*p; if(a<b){*q=b;*p=a;}
        a=*p; b=*first; if(a<b){*p=b;*first=a;}
        unsigned int* lo=middle-step;
        unsigned int* hi=middle+step;
        a=*middle; b=*lo; if(a<b){*middle=b;*lo=a;}
        a=*hi; b=*middle; if(a<b){*hi=b;*middle=a;}
        a=*middle; b=*lo; if(a<b){*middle=b;*lo=a;}
        unsigned int* r=last-step;
        unsigned int* s=last-2*step;
        a=*r; b=*s; if(a<b){*r=b;*s=a;}
        a=*last; b=*r; if(a<b){*last=b;*r=a;}
        a=*r; b=*s; if(a<b){*r=b;*s=a;}
        a=*middle; b=*p; if(a<b){*middle=b;*p=a;}
        a=*r; b=*middle; if(a<b){*r=b;*middle=a;}
        a=*middle; b=*p; if(a<b){*middle=b;*p=a;}
    } else {
        a=*middle; b=*first; if(a<b){*middle=b;*first=a;}
        a=*last; b=*middle; if(a<b){*last=b;*middle=a;}
        a=*middle; b=*first; if(a<b){*middle=b;*first=a;}
    }
}


// 0x002ffe00 FUN_002ffe00 (57 B): equivalent/0x002ffe00.cpp
// sym: ?FUN_002ffe00@fn_fb493392@@YAXPAH0@Z @db8626ae0806 @w4ff5f47d2df5
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_002ffe00 @ 0x002ffe00
void __cdecl FUN_002ffe00(int* begin, int* end)
{
    hulk_intptr count = end - begin;
    hulk_intptr half = (count - (count >> 31)) >> 1;
    while (half > 0) {
        int value = begin[half - 1];
        --half;
        FUN_002ff860((unsigned int *)(int *)begin, (hulk_intptr)half, (hulk_intptr)count, (int)value);
    }
}


// 0x002ffee0 FUN_002ffee0 (96 B): equivalent/0x002ffee0.cpp
// sym: ?FUN_002ffee0@fn_fb493392@@YAIPAUSearch@1@IH@Z @8d487255361e @webb92ff57b4b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002ffee0 @ 0x002ffee0
// equiv-conv: FUN_002ffee0 ecx eax stack
unsigned FUN_002ffee0(Search *self, unsigned originalEax, int key) {
    if (self->count <= 0) return originalEax & ~255u;
    for (int i = 0; i < self->count; ++i) {
        Entry &e = self->entries[i];
        int query = key;
        void *found = bsearch(&query, e.begin, e.end - e.begin, 4, FUN_002feae0);
        if (found) return ((hulk_uintptr)found & ~255u) | 1;
    }
    return self->count & ~255u;
}

} // namespace fn_fb493392

// 0x002fffa0 FUN_002fffa0 (217 B): equivalent/0x002fffa0.cpp [wrapped: conflict: Object]
// sym: ?remove@Manager_2fffa0@fn_002fffa0@@QAE_NPAUObject@2@I@Z @9f5864b6df3f @wec323d1c190c
namespace fn_002fffa0 {
// STATUS: equivalent (tools/equiv.py level 3: 20 inputs, branch coverage 28/30, incomplete)
// FUN_002fffa0 @ 0x002fffa0
struct Object { virtual void slot0(); virtual void release(); };
struct Pair_2fffa0 { Object* first; Object* second; unsigned x,y,z; };
struct Manager_2fffa0 {
 Object** begin; Object** end; char pad0[8];
 Object** otherBegin; Object** otherEnd; char pad1[24];
 Pair_2fffa0* pairsBegin; Pair_2fffa0* pairsEnd;
 bool remove(Object* object, unsigned flags);
};
bool Manager_2fffa0::remove(Object* object, unsigned flags) {
 Object** p=begin;
 Object** stop=end;
 if(p!=stop) {
  while(*p!=object) { ++p; if(p==end) break; }
  if(p!=end) {
   Object** src=p+1;
   while(src!=stop) { *p++=*src++; }
   --end;
   object->release();
  }
 }
 p=otherBegin;
 if(p!=otherEnd) {
  while(*p!=object) { ++p; if(p==otherEnd) break; }
  if(p!=otherEnd) {
   Object** last=otherEnd-1;
   otherEnd=last;
   if(p<last) *p=*last;
   object->release();
  }
 }
 bool found=false;
 if(!(flags&8)) {
  Pair_2fffa0* q=pairsBegin;
  if(q!=pairsEnd) {
   do {
    if(q->first==object || q->second==object) {
     Pair_2fffa0* last=pairsEnd-1;
     pairsEnd=last;
     if(q<last) { q->first=last->first; q->second=last->second; q->x=last->x; q->y=last->y; q->z=last->z; }
     found=true;
    } else ++q;
   } while(q!=pairsEnd);
  }
 }
 return found;
}
} // namespace fn_002fffa0

namespace fn_fb493392 {

// 0x00300080 FUN_00300080 (114 B): equivalent/0x00300080.cpp
// sym: ?FUN_00300080@Graph_300080@fn_fb493392@@QAEXHH@Z @0718044efdb7 @w98c23434764e
// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 16/16)
// FUN_00300080 @ 0x00300080
void Graph_300080::FUN_00300080(int a, int b)
{
    if (a == b)
        return;
    for (Edge_300080 *p = begin; p != end; p++) {
        if ((p->a == a || p->b == a) && (p->a == b || p->b == b)) {
            Edge_300080 *last = end - 1;
            end = last;
            if (p < last)
                *p = *last;
            return;
        }
    }
}


// 0x00300100 FUN_00300100 (310 B): equivalent/0x00300100.cpp
// sym: _FUN_00300100 @3c358e9fd704 @w15d1eaaf86a9
// STATUS: equivalent (tools/equiv.py level 3: 26 inputs, branch coverage 36/42, incomplete)
// FUN_00300100 @ 0x00300100
// std::_Unguarded_partition for unsigned int* (three-way split around a median pivot).
extern "C" void *__cdecl FUN_00300100(void *out, unsigned int *first, unsigned int *last)
{
    unsigned int *mid = first + (last - first) / 2;
    FUN_002ffce0(first, mid, last - 1);

    unsigned int *pfirst = mid;
    unsigned int *plast = pfirst + 1;
    while (first < pfirst && !(*(pfirst - 1) < *pfirst) && !(*pfirst < *(pfirst - 1)))
        --pfirst;
    while (plast < last && !(*plast < *pfirst) && !(*pfirst < *plast))
        ++plast;

    unsigned int *gfirst = plast;
    unsigned int *glast = pfirst;
    unsigned int t;

    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (*pfirst < *gfirst)
                ;
            else if (*gfirst < *pfirst)
                break;
            else {
                t = *plast;
                *plast = *gfirst;
                *gfirst = t;
                ++plast;
            }
        }
        for (; first < glast; --glast) {
            if (*(glast - 1) < *pfirst)
                ;
            else if (*pfirst < *(glast - 1))
                break;
            else {
                --pfirst;
                t = *pfirst;
                *pfirst = *(glast - 1);
                *(glast - 1) = t;
            }
        }
        if (glast == first && gfirst == last) {
            ((UIntRange_300100 *)out)->first = pfirst;
            ((UIntRange_300100 *)out)->second = plast;
            return (UIntRange_300100 *)((UIntRange_300100 *)out);
        }
        if (glast == first) {
            if (plast != gfirst) {
                t = *pfirst;
                *pfirst = *plast;
                *plast = t;
            }
            ++plast;
            t = *pfirst;
            *pfirst = *gfirst;
            *gfirst = t;
            ++pfirst;
            ++gfirst;
        } else if (gfirst == last) {
            --glast;
            --pfirst;
            if (glast != pfirst) {
                t = *glast;
                *glast = *pfirst;
                *pfirst = t;
            }
            --plast;
            t = *pfirst;
            *pfirst = *plast;
            *plast = t;
        } else {
            --glast;
            t = *gfirst;
            *gfirst = *glast;
            *glast = t;
            ++gfirst;
        }
    }
}


// 0x00300270 FUN_00300270 (112 B): matches/0x00300270.cpp
// sym: _FUN_00300270
extern "C" void FUN_00300270(unsigned* first, unsigned* last) {
    if (first != last) {
        unsigned* i = first + 1;
        if (i != last) {
            unsigned* j = first + 2;
            do {
                unsigned v = *i;
                unsigned* p = first;
                if (v < *first) {
                    if (p != i && i != j)
                        Rot(p, i, j, 0, 0);
                } else {
                    unsigned* q = j - 2;
                    if (v < *q) {
                        do {
                            p = q;
                            q = p - 1;
                        } while (v < *q);
                        if (p != i && i != j)
                            Rot(p, i, j, 0, 0);
                    }
                }
                i = i + 1;
                j = j + 1;
            } while (i != last);
        }
    }
}

} // namespace fn_fb493392

// 0x00300320 FUN_00300320 (31 B): matches/0x00300320.cpp [wrapped: merged class would differ: Owner: field value: Field(+0x21f8 int value) vs Field(+0x219c int value)]
// sym: ?Target@Owner@fn_00300320@@QAEXHH@Z
namespace fn_00300320 {
struct Item {
    void Fn_002fffa0(int, int);
    char pad[0x6c];
};
struct Owner {
    Item* items;
    char pad[0x2198];
    int value;
    void Target(int a, int b);
};
void Owner::Target(int a, int b) {
    items[b].Fn_002fffa0(a, value);
}
} // namespace fn_00300320

namespace fn_fb493392 {

// 0x00300360 FUN_00300360 (153 B): equivalent/0x00300360.cpp
// sym: ?FUN_00300360@Container_300360@fn_fb493392@@QAEXXZ @4c42a81ed0a9 @w4337033dc486
// STATUS: equivalent (tools/equiv.py level 3: 117 inputs, branch coverage 12/12)
// FUN_00300360 @ 0x00300360
// Releases every element of the first three arrays, then empties all five.
void Container_300360::FUN_00300360()
{
    for (unsigned i = 0; i < (unsigned)(a.end - a.begin); i++)
        a.begin[i]->Release();
    for (unsigned i = 0; i < (unsigned)(b.end - b.begin); i++)
        b.begin[i]->Release();
    for (unsigned i = 0; i < (unsigned)(c.end - c.begin); i++)
        c.begin[i]->Release();
    a.end = a.begin;
    b.end = b.begin;
    c.end = c.begin;
    d.end = d.begin;
    e.end = e.begin;
}


// 0x00300400 FUN_00300400 (7 B): matches/0x00300400.cpp
// sym: ?Copy@Obj_300400@fn_fb493392@@QAEXXZ
void Obj_300400::Copy() {
    b = a;
}


// 0x00300410 FUN_00300410 (242 B): equivalent/0x00300410.cpp
// sym: ?FUN_00300410@Owner_300410@fn_fb493392@@QAEXI@Z @d85ca9414dff @wc61e76dda696
// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 18/18)
// FUN_00300410 @ 0x00300410
void Owner_300410::FUN_00300410(hulk_uintptr flags) {
 previous = current;
 unsigned int count = (unsigned int)(((char*)end-(char*)begin)/20);
 if (!count) return;
 unsigned int i=0;
 do {
  if(flags & 4) {
   Item_300410* p=begin[i].first;
   if(!p->flag50 && !p->flag6b) { p->state->enabled=0; p->flag68=1; p->flag69=1; }
   p=begin[i].second;
   if(!p->flag50 && !p->flag6b) { p->state->enabled=0; p->flag68=1; p->flag69=1; }
  }
  begin[i].FUN_002f8e80();
  ++i;
 } while(i < (unsigned int)(((char*)end-(char*)begin)/20));
}


// 0x00300510 FUN_00300510 (67 B): equivalent/0x00300510.cpp
// sym: _FUN_00300510 @0abbe54c80db @w0f5124549b4b
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_00300510 @ 0x00300510
extern "C" void __cdecl FUN_00300510(int *first, int *last)
{
    hulk_intptr count = last - first;
    while (count > 1) {
        int value = first[count - 1];
        first[count - 1] = first[0];
        FUN_002ff860((unsigned int *)(int *)first, 0, (hulk_intptr)(count - 1), (int)value);
        --count;
    }
}

} // namespace fn_fb493392

// 0x00300580 FUN_00300580 (40 B): matches/0x00300580.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_00300580@@YIXPAUContainer_300580@1@@Z
namespace fn_00300580 {
struct Item_300580 {
    char pad[0x6c];
    void Process_00300360();
};
struct Container_300580 {
    Item_300580* items;
    int count;
};
void __fastcall Target(Container_300580* self) {
    int i;
    for (i = 0; i < self->count; ++i)
        self->items[i].Process_00300360();
}
} // namespace fn_00300580

namespace fn_fb493392 {

// 0x003005e0 FUN_003005e0 (244 B): equivalent/0x003005e0.cpp
// sym: ?FUN_003005e0@Owner_3005e0@fn_fb493392@@QAEXHPAX@Z @27a12ed969c8 @w2bf1514186d7
// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 12/12)
// FUN_003005e0 @ 0x003005e0
void Owner_3005e0::FUN_003005e0(int index, void* arg) {
 if (!rows[index].active) return;
 rows[index].FUN_00300410(context);
 ((owners::Thing_302ef0 *)&processor)->FUN_00302ef0((hulk_intptr)(Vector *)(&rows[index].a), (hulk_intptr)(Vector *)(&rows[index].b), (hulk_intptr)arg);
 unsigned int n = (unsigned int)(rows[index].end - rows[index].begin);
 for (unsigned int i=0; i<n; ++i) {
  Item_3005e0* item = rows[index].begin[i];
  if (item->active) {
   for (int j=0; j<item->count; ++j) {
    Entry_3005e0* entry=&item->entries[j];
    entry->first->v10();
    entry->second->v10();
    ((owners::Obj_302ed0 *)&processor)->FUN_00302ed0((hulk_intptr)(Resource_3005e0 *)(entry->first), (hulk_intptr)(Resource_3005e0 *)(entry->second), (hulk_intptr)(Vector *)(&rows[index].b));
   }
  }
  n=(unsigned int)(rows[index].end - rows[index].begin);
 }
}


// 0x003006e0 FUN_003006e0 (156 B): matches/0x003006e0.cpp
// sym: ?FUN_003006e0@Group_3006e0@fn_fb493392@@QAEXH@Z
// FUN_003006e0 @ 0x003006e0
// FUN_003006e0: update every active object, then every object once more
void Group_3006e0::FUN_003006e0(int arg)
{
    unsigned int i;
    for (i = 0; i < (unsigned int)(end - begin); i++) {
        FUN_003005e0(begin[i], arg);
        if (active) {
            cursor = (char *)&objs[i] + 0x40;
            FUN_002ff0c0(begin[i]);
        }
    }
    for (i = 0; i < (unsigned int)(end - begin); i++)
        objs[begin[i]].FUN_002ff3f0(param);
}


// 0x00300780 FUN_00300780 (417 B): equivalent/0x00300780.cpp
// sym: ?FUN_00300780@Broadphase_300780@fn_fb493392@@QAEXH@Z @b17ee2f35b76 @w5c71b22c7112
// STATUS: equivalent (tools/equiv.py level 3: 123 inputs, branch coverage 22/22)
// FUN_00300780 @ 0x00300780
void Broadphase_300780::FUN_00300780(int arg)
{
    if (grid.flags & 8) {
        Group_300780 *g = group;
        g->edgeEnd = g->edgeBegin;
        hulk_intptr count = g->end - g->begin;
        grid.FUN_00312db0(count);
        Box_300780 *boxes = grid.boxes;
        for (int i = 0; i < count; i++) {
            Body_300780 *body = g->begin[i]->body;
            Vec3_300780 *c = body->vfunc_3();
            Vec3_300780 lo = { c->x - body->half.x, c->y - body->half.y, c->z - body->half.z };
            boxes[i].lo = lo;
            Vec3_300780 hi = { body->half.x + c->x, c->y + body->half.y, c->z + body->half.z };
            boxes[i].hi = hi;
        }
        int n = grid.FUN_00313450(count);
        short *links = grid.links;
        short *heads = grid.heads;
        for (int i = 0; i < n; i++) {
            short bx = heads[i];
            if (bx == -1)
                continue;
            do {
                int a = bx;
                unsigned short ax = links[a];
                while (ax != 0xffff) {
                    int b = (short)ax;
                    Edge_300780 tmp;
                    Edge_300780 *e = ((Edge_300780 *)((owners::X_2f8ef0 *)&tmp)->FUN_002f8ef0((hulk_uintptr)(g->begin[a]), (hulk_uintptr)(g->begin[b])));
                    Edge_300780 *end = g->edgeEnd;
                    if (end < g->edgeCap) {
                        g->edgeEnd = end + 1;
                        if (end)
                            *end = *e;
                    }
                    ax = links[b];
                }
                bx = links[a];
            } while (bx != -1);
        }
    }
    FUN_003006e0(arg);
    FUN_002ff1b0(arg);
}


// 0x00300930 FUN_00300930 (197 B): equivalent/0x00300930.cpp
// sym: ?target@Owner_300930@fn_fb493392@@QAEXPAUInput_300930@2@H@Z @2ffb6c5b3faf @w7754cf70ac57
// STATUS: equivalent (tools/equiv.py level 3: 1215 inputs, branch coverage 10/10)
// FUN_00300930 @ 0x00300930
void Owner_300930::target(Input_300930* input,int arg) {
 if (!input->enabled) return;
 Buffer_300930 buffer = {0,0,0};
 int offset=0;
 for(int i=0;i<input->count;++i) {
 Entry_300930* entry = (Entry_300930*)((char*)input->entries+offset);
 entry->first->v10();
 entry->second->v10();
 ((owners::Obj_302ed0 *)&worker)->FUN_00302ed0((hulk_intptr)(Item_300930 *)(entry->first), (hulk_intptr)(Item_300930 *)(entry->second), (hulk_intptr)(Buffer_300930 *)(&buffer));
 offset+=20;
 }
 if ((buffer.end-buffer.begin)/68 != 0) receiver.FUN_002f8020(&buffer,arg,0);
 if(buffer.begin) FUN_0008d340(buffer.begin);
}


// 0x00300a00 FUN_00300a00 (327 B): equivalent/0x00300a00.cpp
// sym: ?FUN_00300a00@Pools@fn_fb493392@@QAEPAV12@XZ @1dc16911df7c @wb112f7a92045
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_00300a00 @ 0x00300a00
Pools *Pools::FUN_00300a00()
{
    a.begin = 0;
    a.end = 0;
    a.cap = 0;
    c.begin = 0;
    c.end = 0;
    c.cap = 0;
    d.begin = 0;
    d.end = 0;
    d.cap = 0;
    b.begin = 0;
    b.end = 0;
    b.cap = 0;
    e.begin = 0;
    e.end = 0;
    e.cap = 0;
    flag = 0;

    if ((*(unsigned int*)&DAT_004d2ef0) != 0) {
        unsigned int bytes = (*(unsigned int*)&DAT_004d2ef0) * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        a.begin = p;
        if (p != 0) {
            a.end = p;
            a.cap = p + bytes;
        } else {
            a.end = 0;
            a.cap = 0;
        }
    } else {
        a.begin = 0;
        a.end = 0;
        a.cap = 0;
    }

    if ((*(unsigned int*)&DAT_004d2efc) != 0) {
        unsigned int bytes = (*(unsigned int*)&DAT_004d2efc) * 20;
        char *p = (char *)FUN_0008d6d0(bytes);
        b.begin = p;
        if (p != 0) {
            b.end = p;
            b.cap = p + bytes;
        } else {
            b.end = 0;
            b.cap = 0;
        }
    } else {
        b.begin = 0;
        b.end = 0;
        b.cap = 0;
    }

    if ((*(unsigned int*)&DAT_004d2ef4) != 0) {
        unsigned int bytes = (*(unsigned int*)&DAT_004d2ef4) * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        c.begin = p;
        if (p != 0) {
            c.end = p;
            c.cap = p + bytes;
        } else {
            c.end = 0;
            c.cap = 0;
        }
    } else {
        c.begin = 0;
        c.end = 0;
        c.cap = 0;
    }

    if ((*(unsigned int*)&DAT_004d2ef8) != 0) {
        unsigned int bytes = (*(unsigned int*)&DAT_004d2ef8) * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        d.begin = p;
        if (p != 0) {
            d.end = p;
            d.cap = p + bytes;
        } else {
            d.end = 0;
            d.cap = 0;
        }
    } else {
        d.begin = 0;
        d.end = 0;
        d.cap = 0;
    }

    if ((*(unsigned int*)&DAT_004d2f00) != 0) {
        unsigned int bytes = (*(unsigned int*)&DAT_004d2f00) * 0x44;
        char *p = (char *)FUN_0008d6d0(bytes);
        e.begin = p;
        if (p != 0) {
            e.end = p;
            e.cap = p + bytes;
        } else {
            e.end = 0;
            e.cap = 0;
        }
    } else {
        e.begin = 0;
        e.end = 0;
        e.cap = 0;
    }

    f54 = 0;
    f58 = 0;
    f5c = 0;
    f60 = 0;
    f64 = 0;
    f68 = 0;
    return this;
}

} // namespace fn_fb493392

// 0x00300b50 FUN_00300b50 (102 B): matches/0x00300b50.cpp
// sym: ?FUN_00300b50@Obj_300b50@owners@@QAEXXZ
void owners::Obj_300b50::FUN_00300b50() {
    Init();
    void* p = p4;
    q4 = p;
    if (p)
        Release_0008d340(p);
    p = p3;
    q3 = p;
    if (p)
        Release_0008d340(p);
    p = p2;
    q2 = p;
    if (p)
        Release_0008d340(p);
    p = p1;
    q1 = p;
    if (p)
        Release_0008d340(p);
    p = p0;
    q0 = p;
    if (p)
        Release_0008d340(p);
}


// 0x00300bc0 FUN_00300bc0 (203 B): equivalent/0x00300bc0.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_00300bc0 @f53255767b0a @w873f10019891
namespace fn_00300bc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 12/14, incomplete)
// FUN_00300bc0 @ 0x00300bc0
struct Partition { int* first; int* second; };
extern "C++" void * __cdecl FUN_00300100(void *, unsigned int *, unsigned int *);
extern "C++" void __cdecl FUN_00300270(unsigned *, unsigned *);
void __cdecl FUN_002ffe00(int*, int*, int, int);
extern "C++" void __cdecl FUN_00300510(int *, int *);
extern "C" void __cdecl FUN_00300bc0(int* first, int* last, int budget) {
    while (last - first > 32) {
        if (budget <= 0) {
            if (last - first > 1) FUN_002ffe00(first, last, 0, 0);
            FUN_00300510(first, last);
            return;
        }
        Partition split;
        FUN_00300100((Partition *)(&split), (unsigned int *)(int *)first, (unsigned int *)(int *)last);
        budget = budget / 2;
        budget += budget / 2;
        if (split.first - first < last - split.second) {
            FUN_00300bc0(first, split.first, budget);
            first = split.second;
        } else {
            FUN_00300bc0(split.second, last, budget);
            last = split.first;
        }
    }
    if (last - first > 1) FUN_00300270((unsigned *)(int *)first, (unsigned *)(int *)last);
}
} // namespace fn_00300bc0


// 0x00300c90 FUN_00300c90 (228 B): equivalent/0x00300c90.cpp [wrapped: conflict: Object]
// sym: ?FUN_00300c90@Object@fn_00300c90@@QAEPAU12@XZ @236922bf2b92 @w359157cdb425
namespace fn_00300c90 {
// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 15/16, incomplete)
// FUN_00300c90 @ 0x00300c90

extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);
// (x64t9-pw) the contact buffer, the collision detector and the solver as the physics world has them
// (decls/physics_world.h; were 16-, 64- and 256-byte pads)
struct A_300c90 : HulkContactBuffer {  };
struct CollisionDetector_300c90 : HulkCollisionDetector { void FUN_00301290(); };
struct ImpulseBasedCollisionSolver_300c90 : HulkCollisionSolver { void FUN_002f7ee0(); };
struct D { char data[0x2030]; void FUN_00312d50(); };
struct Entry_300c90 { char pad[0x50]; unsigned char active; char rest[0x1b]; void FUN_00300a00(); };
struct Object {
 Entry_300c90* entries; int count; unsigned int* begin; unsigned int* end; unsigned int* limit; char pad14[4]; A_300c90 a; CollisionDetector_300c90 b; ImpulseBasedCollisionSolver_300c90 c; D d; unsigned char flag; char pad2199[3]; int mode;
 Object* FUN_00300c90();
};
Object* Object::FUN_00300c90() {
 begin=0; end=0; limit=0;
 ((owners::Buffer_304300 *)&a)->FUN_00304300(); b.FUN_00301290(); c.FUN_002f7ee0(); d.FUN_00312d50();
 flag=0; mode=18;
 int n=DAT_004d2eec; count=n;
 unsigned int* allocation=(unsigned int*)FUN_0008d6d0((unsigned int)n*0x6c+4);
 Entry_300c90* list=0;
 if(allocation) { *allocation=(unsigned int)n; list=(Entry_300c90*)(allocation+1); if(n-1>=0) { Entry_300c90* item=list; unsigned int remaining=(unsigned int)n; do { item->FUN_00300a00(); ++item; } while(--remaining); } }
 entries=list;
 if(count!=0) { unsigned int bytes=(unsigned int)count*4; unsigned int* p=(unsigned int*)FUN_0008d6d0(bytes); begin=p; if(p) {end=p; limit=(unsigned int*)((char*)p+bytes);} else {end=0; limit=0;} }
 else {begin=0;end=0;limit=0;}
 if(entries->active!=1) {entries->active=1; unsigned int* p=end; if((hulk_uintptr)p<(hulk_uintptr)limit) {end=p+1; if(p) *p=0;} }
 return this;
}
} // namespace fn_00300c90


// 0x00300d80 FUN_00300d80 (212 B): equivalent/0x00300d80.cpp
// sym: ?FUN_00300d80@Item_300d80@owners@@QAEPAXE@Z @0704e30cc0b8 @w4ea52747f367
// STATUS: equivalent (tools/equiv.py level 3: 292 inputs, branch coverage 20/20)
// FUN_00300d80 @ 0x00300d80
void* owners::Item_300d80::FUN_00300d80(unsigned char flags) {
 if(flags & 2) {
  int* header = reinterpret_cast<int*>(this)-1;
  int count = *header;
  owners::Item_300d80* p = this + count;
  if(count > 0) {
   do {
    --p;
    p->FUN_00300360();
    p->eEnd=p->e; if(p->e) FUN_0008d340(p->e);
    p->dEnd=p->d; if(p->d) FUN_0008d340(p->d);
    p->cEnd=p->c; if(p->c) FUN_0008d340(p->c);
    p->bEnd=p->b; if(p->b) FUN_0008d340(p->b);
    p->aEnd=p->a; if(p->a) FUN_0008d340(p->a);
   } while(--count);
  }
  if(flags & 1) FUN_0008d340(header);
  return header;
 }
 FUN_00300b50();
 if(flags & 1) FUN_0008d330(this);
 return this;
}


// 0x00300e60 FUN_00300e60 (59 B): matches/0x00300e60.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_00300e60@@YIXPAUObj_300e60@1@@Z
namespace fn_00300e60 {
struct Child_300e60 {
    void FnF_00300d80(int);
};
void __fastcall FUN_002f79f0(void* self);
void __fastcall FUN_003012c0(void* self);
extern "C" void __fastcall FUN_00304350(void* self);
void __cdecl FUN_0008d340(unsigned int n);
struct Obj_300e60 {
    Child_300e60* first;
    unsigned int x;
    unsigned int p2;
    unsigned int p3;
    char pad[0x54];
};
void __fastcall Target(Obj_300e60* p) {
    if (p->first)
        p->first->FnF_00300d80(3);
    FUN_002f79f0((char*)p + 0x68);
    FUN_003012c0((char*)p + 0x28);
    FUN_00304350((char*)p + 0x18);
    p->p3 = p->p2;
    if (p->p2)
        FUN_0008d340(p->p2);
}
} // namespace fn_00300e60

namespace fn_fb493392 {

// 0x00300ea0 FUN_00300ea0 (150 B): equivalent/0x00300ea0.cpp
// sym: ?FUN_00300ea0@ElemPool@fn_fb493392@@QAEXH@Z @33e73f53c046 @w778b939e05ec
// STATUS: equivalent (tools/equiv.py level 3: 402 inputs, branch coverage 12/12)
// FUN_00300ea0 @ 0x00300ea0
void ElemPool::FUN_00300ea0(int n)
{
    if (elems != 0)
        ((ElemArray_300ea0 *)elems)->FUN_00300d80(3);

    Elem_300ea0 *arr;
    int *raw = (int *)FUN_0008d6d0(n * sizeof(Elem_300ea0) + 4);
    if (raw != 0) {
        raw[0] = n;
        arr = (Elem_300ea0 *)(raw + 1);
        for (int i = 0; i < n; i++)
            arr[i].FUN_00300a00();
    } else {
        arr = 0;
    }
    elems = arr;
    count = n;

    if (n != 0) {
        unsigned int bytes = n * 4;
        int *q = (int *)FUN_0008d6d0(bytes);
        indices = q;
        if (q != 0) {
            end = (int *)((char *)q + bytes);
            begin = q;
            return;
        }
    } else {
        indices = 0;
    }
    begin = 0;
    end = 0;
}


// 0x00300fa0 FUN_00300fa0 (81 B): matches/0x00300fa0.cpp
// sym: ?Run@Obj_300fa0@fn_fb493392@@QAEPAV12@E@Z
Obj_300fa0* Obj_300fa0::Run(unsigned char flags) {
    if (p0)
        ((Small_300fa0*)p0)->FnA_00300d80(3);
    s68.FnB_002f79f0();
    s28.FnC_003012c0();
    s18.FnD_00304350();
    pc = p8;
    if (p8)
        relA_0008d340(p8);
    if (flags & 1)
        relB_0008d330(this);
    return this;
}

} // namespace fn_fb493392

// 0x003010a0 FUN_003010a0 (251 B): equivalent/0x003010a0.cpp [wrapped: conflict: Object]
// sym: ?target@Container_3010a0@fn_003010a0@@QAEXPAUObject@2@I@Z @5997caa902b4 @w371c4f759a0f
namespace fn_003010a0 {
// STATUS: equivalent (tools/equiv.py level 3: 155 inputs, branch coverage 32/32)
// FUN_003010a0 @ 0x003010a0

struct Object {
 virtual void addRef();
 char pad[0x4c];
 unsigned char flag50, flag51;
};
struct Service_3010a0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual bool pair(Object*,Object*);
 virtual bool single(Object*);
};
struct Global_3010a0 { char pad[0x6c]; Service_3010a0* service; };
struct Pair_3010a0 { char data[20];  };
struct Queue_3010a0 { void FUN_002ee0c0(Pair_3010a0*); };
extern "C++" void __cdecl FUN_00300bc0(int *, int *, int);
struct Container_3010a0 {
 Object** begin; Object** end; Object** capacity;
 char pad0[8];
 Object** specialEnd; Object** specialCapacity;
 char pad1[0x14];
 Queue_3010a0 queue;
 void target(Object* object, unsigned flags);
};
void Container_3010a0::target(Object* object, unsigned flags) {
 if (!(flags & 8)) {
  if ((*(Global_3010a0**)&DAT_0055547c)->service->single(object)) {
   if ((hulk_uintptr)specialEnd < (hulk_uintptr)specialCapacity) {
    Object** slot=specialEnd; specialEnd=slot+1;
    if(slot) *slot=object;
   }
   object->addRef();
  }
  unsigned i=0;
  if ((unsigned)(end-begin)>0) {
   do {
    Object* other=begin[i];
    if ((*(Global_3010a0**)&DAT_0055547c)->service->pair(object,other)) {
     unsigned char a=object->flag50;
     if (!(a && other->flag50) && (object->flag51 || !other->flag50) && (other->flag51 || !a)) {
      if(a) { Pair_3010a0 p; queue.FUN_002ee0c0(((Pair_3010a0 *)((owners::X_2f8ef0 *)&p)->FUN_002f8ef0((hulk_uintptr)(Object *)object, (hulk_uintptr)(Object *)other))); }
      else { Pair_3010a0 p; queue.FUN_002ee0c0(((Pair_3010a0 *)((owners::X_2f8ef0 *)&p)->FUN_002f8ef0((hulk_uintptr)(Object *)other, (hulk_uintptr)(Object *)object))); }
     }
    }
    ++i;
   } while(i < (unsigned)(end-begin));
  }
 }
 if ((hulk_uintptr)end < (hulk_uintptr)capacity) {
  Object** slot=end; end=slot+1;
  if(slot) *slot=object;
 }
 FUN_00300bc0((int *)(Object * *)begin,(int *)(Object * *)end,(unsigned)((unsigned)(end-begin)));
 object->addRef();
}
} // namespace fn_003010a0

namespace fn_fb493392 {

// 0x003011a0 FUN_003011a0 (100 B): matches/0x003011a0.cpp
// sym: ?Update@Sim_3011a0@fn_fb493392@@QAEXPAUEnt_3011a0@2@H@Z
void Sim_3011a0::Update(Ent_3011a0* e, int i) {
    mSlots[i].Process_003010a0(e, mFlags);
    if (mFlags & 8) {
        Xf_3011a0* x = e->xf;
        Vec3_3011a0 v;
        const Vec3_3011a0& p = x->pos;
        float z = p.z + p.z;
        float y = p.y + p.y;
        float x0 = p.x + p.x;
        v.x = x0;
        v.y = y;
        v.z = z;
        mSub.Add_00312fa0(&v);
    }
}


// 0x00301290 FUN_00301290 (36 B): matches/0x00301290.cpp
// sym: ??0CollisionDetector@fn_fb493392@@QAE@XZ
// data: g_owner = DAT_00554c10
CollisionDetector::CollisionDetector() : FUN_00313500() {
    vftable = (void*)&hulk_at_00431ac0;
    f3c = 0;
    d = (*(Owner_301290**)&DAT_00554c10)->value;
}


// 0x003012c0 FUN_003012c0 (11 B): matches/0x003012c0.cpp
// sym: ?FUN_003012c0@fn_fb493392@@YIXPAVCEffectStopTrack@1@@Z
// Same code shape as 0x00060920 (propagated; names are from that function)
void __fastcall FUN_003012c0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)((int*)DAT_00431ac0);
    FUN_00313530(self);
}

} // namespace fn_fb493392

// 0x003012d0 FUN_003012d0 (57 B): matches/0x003012d0.cpp
// sym: ?FUN_003012d0@C_3012d0@owners@@QAEXHH@Z
void owners::C_3012d0::FUN_003012d0(hulk_intptr a, hulk_intptr b) {
    if (!Check(((int)a), ((int)b))) {
        Pair(((int)a), ((int)b));
        Pair(((int)b), ((int)a));
        Finish(((int)a), ((int)b));
    }
}

namespace fn_fb493392 {

// 0x00301310 FUN_00301310 (256 B): equivalent/0x00301310.cpp
// sym: ?target@Context@fn_fb493392@@QAEXIPAUShape_301310@2@@Z @9b30ae68a18c @w29ce14f9234a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00301310 @ 0x00301310
void Context::target(hulk_uintptr arg, Shape_301310* s) {
 if (!s->special) {
  float d=s->distance;
  Vec3_301310* p=s->position();
  Vec3_301310 v;
  v.x=d*s->direction.x+p->x;
  v.y=d*s->direction.y+p->y;
  v.z=d*s->direction.z+p->z;
  FUN_00317610(arg,s,&v,s->value);
  d=-s->distance;
  p=s->position();
  v.x=d*s->direction.x+p->x;
  v.y=d*s->direction.y+p->y;
  v.z=d*s->direction.z+p->z;
  FUN_00317610(arg,s,&v,s->value);
 } else {
  FUN_00315860(arg,s);
  if(a==b) FUN_00319270(arg,s);
 }
 if(a==b) FUN_00315ca0(arg,s);
 FUN_003160f0(arg,s);
}


// 0x00301410 FUN_00301410 (75 B): matches/0x00301410.cpp
// sym: ?FUN_00301410@Object@fn_fb493392@@QAEXHPAUReceiver@2@H@Z
void Object::FUN_00301410(int a, Receiver* receiver, int value) {
    x *= -1.0f;
    y *= -1.0f;
    z *= -1.0f;
    FUN_00317610(a, receiver, receiver->slot4(), value);
}


// 0x00301460 FUN_00301460 (143 B): equivalent/0x00301460.cpp
// sym: ?FUN_00301460@Body_301460@fn_fb493392@@QAEXHPAUProbe_301460@2@@Z @e490551c0a2d @w0da054a8b0d4
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 2/2)
// FUN_00301460 @ 0x00301460
void Body_301460::FUN_00301460(hulk_intptr a, Probe_301460 *probe) {
    Vec3_301460 w, u, v;
    vx = vx * -1.0f;
    vy = vy * -1.0f;
    vz = vz * -1.0f;
    if (FUN_00314430(a, probe->Sample(), probe->field34, &w, &link, &v, &u, 1))
        FUN_00314be0(a, &v, probe, &u, link.first, &w);
}


// 0x003014f0 FUN_003014f0 (208 B): equivalent/0x003014f0.cpp
// sym: ?target@Contact_3014f0@fn_fb493392@@QAEXPAUBody_3014f0@2@0@Z @41b13b382da8 @wbb205d6f469b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003014f0 @ 0x003014f0
void Contact_3014f0::target(Body_3014f0* a,Body_3014f0* b) {
 double root=sqrt(distance);
 distance=(float)root;
 double inv=1.0/root;
 normal.x=(float)(inv*normal.x);
 normal.y=(float)(inv*normal.y);
 normal.z=(float)(inv*normal.z);
 float ra=-a->radius;
 Vec_3014f0* p=a->position();
 Vec_3014f0 pa;
 pa.x=ra*normal.x+p->x;
 pa.y=ra*normal.y+p->y;
 pa.z=ra*normal.z+p->z;
 float rb=b->radius;
 p=b->position();
 Vec_3014f0 pb;
 pb.x=rb*normal.x+p->x;
 pb.y=rb*normal.y+p->y;
 pb.z=rb*normal.z+p->z;
 float separation=distance-(a->radius+b->radius);
 FUN_00314be0(a,&pa,b,&pb,separation,&normal);
}

} // namespace fn_fb493392

// 0x003015c0 FUN_003015c0 (67 B): equivalent/0x003015c0.cpp [wrapped: conflict: Object]
// sym: ?FUN_003015c0@fn_003015c0@@YAMPAUObject@1@0@Z @04133036f33f @w3220adda717a
namespace fn_003015c0 {
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 0/0)
// FUN_003015c0 @ 0x003015c0
struct Vec3 { float x,y,z; };
struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3* slot4();
    char pad[0x30];
    float offset;
    float normalX, normalY, normalZ;
};
hulk_freg __cdecl FUN_003015c0(Object* a, Object* b) {
    Vec3* first = a->slot4();
    Vec3* second = b->slot4();
    return ((second->y - first->y) * a->normalY + (second->z - first->z) * a->normalZ + (second->x - first->x) * a->normalX) - b->offset;
}
} // namespace fn_003015c0

