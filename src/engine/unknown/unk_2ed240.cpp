// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002ed240..0x002ef300 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "decls/physics_world.h"
#define TREE_TU_BEGIN namespace fn_f671dae7 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f671dae7 {} using namespace fn_f671dae7;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f671dae7 {
struct Vec3_2ed240 { float x, y, z; };
class Body_2ed240 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_2ed240 *getPosition();
    char pad04[0x24];
    Vec3_2ed240 half;
};
struct Entry_2ed240 {
    char pad0[0x20];
    Body_2ed240 *body;
    char pad24[0x34];
    unsigned int maskA_lo;
    unsigned int maskA_hi;
    unsigned int maskB_lo;
    unsigned int maskB_hi;
};
struct Span_2ed240 {
    Entry_2ed240 *other;
    float lo;
    float hi;
    float zmax;
    float zmin;
};
struct Resolver_2ed240 {
    char pad0[0x30];
};
class Broadphase_2ed240 {
public:
    char pad0[0x14];
    Entry_2ed240 **entries;
    char pad18[0xc];
    Span_2ed240 *spans;
    unsigned int spanCount;
    char field2c[0x44];
    Resolver_2ed240 resolver;
    int resultCount;
    void FUN_002ed240(int index);
};
struct Vec3_2ed3d0 {
    float x, y, z;
};
struct Shape_2ed3d0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const Vec3_2ed3d0 *v4();
    char pad04[0x24];
    float radius;           // 0x28
    char pad2c[4];
    float halfZ;            // 0x30
};
struct Body_2ed3d0 {
    char pad0[0x20];
    Shape_2ed3d0 *shape;           // 0x20
    char pad24[0x58 - 0x24];
    unsigned int maskALo;   // 0x58
    unsigned int maskAHi;   // 0x5c
    unsigned int maskBLo;   // 0x60
    unsigned int maskBHi;   // 0x64
};
struct BitSet_2ed3d0 {
    int header;
    unsigned int bits[1];
};
struct Pairs {
    char pad0[0x2c];
};
class SweepAndPrune {
public:
    char pad0[0x10];
    BitSet_2ed3d0 *skip;           // 0x10
    Body_2ed3d0 **bodies;          // 0x14
    unsigned int count;     // 0x18
    float margin;           // 0x1c
    float zSlack;           // 0x20
    char pad24[8];
    char contact[0x70 - 0x2c];  // 0x2c
    Pairs pairs;            // 0x70
    char pad9c[4];
    int found;              // 0xa0

    void FUN_002ed3d0(unsigned int index);
};
typedef unsigned int u32_2ed6e0;
struct Sub_2ed6e0 {
    void Call_002f8020(void*, u32_2ed6e0, int);
};
namespace pure3d {
class Entity {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};
}
namespace pure3d {
class LightGroup : public Entity {
  public:
    LightGroup* Self();
    char pad2[0x40];
};
}
struct Key_2ed730 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual float* Get();
};
struct Item_2ed730 {
    char p[0x20];
    Key_2ed730* key;
};
struct Sorter {
    char p[0x14];
    Item_2ed730** items;
    unsigned count;
    void Sort();
};
class Obj_2ed7a0 {
  public:
    char pad[0x50];
    unsigned char flag;
};
class Container_2ed7a0 {
  public:
    char pad[0x14];
    int* items;
    unsigned int count;
    char pad2[8];
    int* wideItems;
    unsigned int wideCount;
    bool Find(Obj_2ed7a0* obj);
};
class Handler_2edb20 {
  public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual int GetKind();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15();
    virtual unsigned char Handle(int a, int b, int c);
};
struct Entry_2edb20 {
    char pad[0x10];
    Handler_2edb20* handler;
};
struct Sub_2edb20 {
};
class Mgr_2edb20 {
  public:
    // (x64t4) the contact buffer at the physics world's part offset (decls/physics_world.h)
    union {
        struct {
            char pad00[0x3c];
            Entry_2edb20** begin;
            Entry_2edb20** end;
        };
        char pool_[HULK_PW_BUFFER];
    };
    Sub_2edb20 sub;
    unsigned char FUN_002edb20(int a, int b, int c);
};
struct Child_2edb90 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int GetType();
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
    virtual bool Do(int a, int b);
};
struct Item_2edb90 {
    char pad[0x10];
    Child_2edb90* c;
};
struct Sub_2edb90 {
};
struct Vec_2edb90 {
    Item_2edb90** b;
    Item_2edb90** e;
    hulk_uintptr size() const { return e - b; }
    Item_2edb90*& operator[](unsigned i) { return b[i]; }
};
struct T_2edb90 {
    // (x64t4) the contact buffer at the physics world's part offset (decls/physics_world.h)
    union {
        struct {
            char pad[0x3c];
            Vec_2edb90 v;
        };
        char pool_[HULK_PW_BUFFER];
    };
    Sub_2edb90 sub;
    bool Run(int a, int b);
};
typedef unsigned int Word_2edc20;
struct Detail_2edc20 { char pad[0x10]; Word_2edc20 value; };
struct Entry_2edc20 { char pad0[0x20]; Detail_2edc20* detail; char pad1[0x2c]; unsigned char selected; char pad2[0x21]; unsigned char enabled; };
struct Work_2edc20 { Word_2edc20 first; Word_2edc20 second; Detail_2edc20* detail; };
extern char __cdecl FUN_002f1160(Word_2edc20,Word_2edc20,Word_2edc20,Word_2edc20,Work_2edc20*);
extern void __cdecl FUN_002f24f0(Word_2edc20,Work_2edc20*,Word_2edc20,Word_2edc20,Word_2edc20*);
struct Collection_2edc20 { Entry_2edc20** begin; Entry_2edc20** end; void FUN_002edc20(Word_2edc20,Word_2edc20,Word_2edc20,Word_2edc20,Word_2edc20*,char); };
struct Vec_2edce0 { float x,y,z; hulk_freg FUN_0022d110(); };
struct Hit_2edce0 { char pad[8]; void* object; };
struct Entry_2edce0 { char p0[0x20]; void* object; char p1[0x2c]; unsigned char flag50; char p2[0x21]; unsigned char enabled; };
extern unsigned char __cdecl FUN_002f15a0(Vec_2edce0*, Vec_2edce0*, Vec_2edce0*, float, void*, Hit_2edce0*);
struct Manager_2edce0 { Entry_2edce0** begin; Entry_2edce0** end; unsigned char FUN_002edce0(Hit_2edce0*, Vec_2edce0*, Vec_2edce0*, unsigned char); };
extern "C" void* __cdecl FUN_0008d690(unsigned int);  // (x64t4) the allocator by address (was `Alloc`)
struct Item_2ee0c0 {
    uint a, b, c, d, e;
};
struct Buffer_2ee0c0 {
    char pad0[4];
    Item_2ee0c0* cur;
    Item_2ee0c0* end;
    bool Add(Item_2ee0c0* value);
};
struct Vec_2ee140 { float x,y,z; hulk_freg FUN_0022d110(); };
struct Owner_2ee140 { char pad[16]; void* value; };
struct Item_2ee140 { char pad0[32]; Owner_2ee140* owner; char pad1[44]; unsigned char filter; char pad2[33]; unsigned char enabled; };
struct Entry_2ee140 { char pad[4]; Item_2ee140* item; };
struct Results { int count; char pad[4]; Entry_2ee140* entries; };
struct Record_2ee140 { int zero; void* object; Owner_2ee140* owner; };
extern bool __cdecl FUN_002f1160(Vec_2ee140*,Vec_2ee140*,Vec_2ee140*,float,Record_2ee140*);
extern void __cdecl FUN_002f24f0(Results*,Record_2ee140*,Vec_2ee140*,Vec_2ee140*,float*);
} // namespace fn_f671dae7
struct World { void FUN_002edc20(Results*,Vec_2ee140*,Vec_2ee140*,Vec_2ee140*,float*,int); bool target(Results*,Vec_2ee140*,Vec_2ee140*,int); };
namespace fn_f671dae7 {
struct V3_2ee260 {
    float x, y, z;
};
class Bounds_2ee260 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_2ee260 *GetPos();
    virtual void v5();
    virtual int GetKind();
    char pad04[0x24];
    float halfX;
    char pad2c[4];
    float halfZ;
    float limit;
};
class Obj_2ee260 {
public:
    virtual void AddRef();
    char pad04[0x1c];
    Bounds_2ee260 *bounds;
    char pad24[0x2c];
    bool listed;
};
struct Entry_2ee260 {
    Obj_2ee260 *obj;
    float x0;
    float x1;
    float z0;
    float z1;
};
class Tracker_2ee260 {
public:
    char pad0[4];
    Obj_2ee260 **end;
    Obj_2ee260 **capEnd;
    char padc[8];
    Obj_2ee260 **sorted;
    unsigned int sortedCount;
    float maxA;
    float maxB;
    Entry_2ee260 *entries;
    unsigned int entryCount;

    void FUN_002ee260(Obj_2ee260 *obj);
};
struct Entry_2ee570 {
    void *a;
    void *b;
    int c, d, e;
};
struct Item_2ee570 {
    char pad00[0x50];
    unsigned char flag;
};
struct Maker_2ee570 {
    Entry_2ee570 data;
    Entry_2ee570 *FUN_002f8ef0(Item_2ee570 *x, Item_2ee570 *y);
};
class Graph_2ee570 {
public:
    char pad00[0x4c];
    Entry_2ee570 *begin;
    Entry_2ee570 *end;
    Entry_2ee570 *limit;
    void FUN_002ee570(Item_2ee570 *x, Item_2ee570 *y);
};
class Item_2ee6d0 {
  public:
    virtual void Execute();
};
class Container_2ee6d0 {
  public:
    char pad[0x40];
    unsigned int* current;
    unsigned int* end;
    void Add(Item_2ee6d0* item);
};
struct Info_2ee710 {
    char pad[0x34];
    float value;
};
struct Item_2ee710 {
    virtual void FUN_slot0();
    virtual void FUN_slot1();
    char pad0[0x20 - 4];
    Info_2ee710 *info;
    char pad1[0x50 - 0x24];
    char flag;
};
struct Rec20_2ee710 {
    Item_2ee710 *a;
    Item_2ee710 *b;
    int c;
    int d;
    int e;
};
struct Rec14 {
    Item_2ee710 *key;
    int a;
    int b;
    int c;
    int d;
};
struct Rec44 {
    int w0;
    int w1;
    Item_2ee710 *k0;
    Item_2ee710 *k1;
    char pad[0x44 - 0x10];
};
union ArgSlot_2ee710 {
    Item_2ee710 *obj;
    float f;
};
struct Registry_2ee710 {
    Item_2ee710 **list_begin;
    Item_2ee710 **list_end;
    char pad0[0x14 - 8];
    Item_2ee710 **inf_begin;
    unsigned inf_count;
    float maxA;
    float maxB;
    Rec14 *rec_begin;
    unsigned rec_count;
    Rec44 *big_begin;
    Rec44 *big_end;
    char pad1[0x4c - 0x34];
    Rec20_2ee710 *pair_begin;
    Rec20_2ee710 *pair_end;

    void FUN_002ee710(Item_2ee710 *obj);
};
struct Edge_2ee9a0 {
    int a;
    int b;
    int c;
    int d;
    int e;
};
struct Graph_2ee9a0 {
    char pad0[0x4c];
    Edge_2ee9a0 *begin;
    Edge_2ee9a0 *end;
    void FUN_002ee9a0(int a, int b);
};
} // namespace fn_f671dae7
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memset(void *dst, int c, unsigned int n);
#endif
namespace fn_f671dae7 {
struct Info {
    char pad0[0xc];
    int kind;                       // 0xc
};
struct Sub {
    char pad0[0x18];
    Info *info;                     // 0x18
};
struct Child {
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
    virtual void touch();           // 0x28
    char pad4[0x10 - 4];
    Sub *sub;                       // 0x10
    char pad14[0x18 - 0x14];
    unsigned char active;           // 0x18
    unsigned char ready;            // 0x19
};
struct Item {
  public:
    virtual void _m_vf0();
    virtual void slot1();
    char _m_pad_4[0x1c];
    Child *child;
    char _m_pad_24[0x3c];
    unsigned int flags;
    char _m_pad_64[0x4];
    unsigned char hot;
    unsigned char hot2;
    char _m_pad_6a[0x2];
};
struct Container { char pad[0x3c]; Item **begin; Item **end; void FUN_002ee510(Item *item); };
struct Checker {
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
    virtual char accept(Item *item);    // 0x2c
};
struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int type();                 // 0x18
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void attach(Child *c, int flag);    // 0x3c
    char pad4[0x38 - 4];
    int slot;                       // 0x38
};
struct Node {
    char pad0[0x10];
    Target *target;                 // 0x10
};
struct Holder {
    char pad0[0x20];
    int ref;                        // 0x20
};
struct Link {
    Holder *a;                      // 0x0
    Holder *b;                      // 0x4
    int pad[3];
};
struct Bits {
    unsigned int nbits;
    unsigned int words[1];
};
struct Solver {
};
class Mgr {
public:
    Item **begin;                   // 0x00
    Item **end;                     // 0x04
    char pad8[8];
    Bits *bits;                     // 0x10
    Item **items;                   // 0x14
    unsigned int count;             // 0x18
    char pad1c[0x2c - 0x1c];
    int value;                      // 0x2c
    int valueCopy;                  // 0x30
    char pad34[0x3c - 0x34];
    Node **nodesBegin;              // 0x3c
    Node **nodesEnd;                // 0x40
    char pad44[0x4c - 0x44];
    Link *linksBegin;               // 0x4c
    Link *linksEnd;                 // 0x50
    char pad54[0x5c - 0x54];
    Child **hitBegin;               // 0x5c
    Child **hitEnd;                 // 0x60
    Child **hitCap;                 // 0x64
    char pad68[4];
    unsigned char force;            // 0x6c
    char pad6d[3];
    Solver solver;                  // 0x70
    char pad71[0x78 - 0x71];
    int *valuePtr;                  // 0x78
    char pad7c[0xa0 - 0x7c];
    int dirty;                      // 0xa0
    char pada4[0xb4 - 0xa4];
    Checker *checker;               // 0xb4

    void FUN_002ed730();
    void FUN_002ed240(unsigned int i);
    void FUN_002ed3d0(unsigned int i);
    void FUN_002eea80();
};
struct Item_2eecc0 { virtual void slot0(); virtual void clear(); };
struct Record_2eecc0 { unsigned value; char rest[16]; };
struct Bits_2eecc0 { unsigned count; unsigned words[1]; };
struct State_2eecc0 {
 Item_2eecc0** begin; Item_2eecc0** end; char pad08[8]; Bits_2eecc0* bits;
 unsigned* values; unsigned valueCount; char pad1c[8];
 Record_2eecc0* records; unsigned recordCount;
 void* begin2; void* end2; char pad34[8];
 Item_2eecc0** begin3; Item_2eecc0** end3; char pad44[8];
 void* begin4; void* end4;
 void reset();
};
class Inner_2eedd0 {
  public:
    void First_002eea80();
    void Second_002f8020(void*, void*, int);
};
class Obj_2eedd0 {
  public:
    char pad[HULK_PW_SOLVER];
    void Run(void*);
};
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
struct RawVec {
    char *first;
    char *last;
    char *end;
};
class Pool_2eee10 {
public:
    RawVec ids;              // 0x00: DAT_004d293c * 4 bytes
    unsigned int *used;      // 0x0c unused
    unsigned int *bits;      // 0x10: bit set of DAT_004d293c bits
    int *slots;              // 0x14
    int slotCount[3];        // 0x18
    char *links;             // 0x24
    int linkCount;           // 0x28
    RawVec records;          // 0x2c: DAT_004d2944 * 0x44 bytes
    char pad38[4];
    RawVec indices;          // 0x3c: DAT_004d2940 * 4 bytes
    char pad48[4];
    RawVec edges;            // 0x4c: DAT_004d2948 * 20 bytes
    char pad58[4];
    RawVec flags;            // 0x5c: DAT_004d293c * 4 bytes
    Pool_2eee10 *FUN_002eee10();
};
} // namespace fn_f671dae7
void __cdecl operator delete[](void*);
namespace fn_f671dae7 {
struct CollisionDetector_2ef050 {
    void Fnf_00301290();
};
struct ImpulseBasedCollisionSolver_2ef050 {
    void Fnf_002f7ee0();
};
struct S3_2ef050 {
    void Fnf_00304300();
};
struct C_2ef050 {
    char pad[HULK_PW_DETECTOR];
    void Fnf_002eee10();
    C_2ef050* target();
};
struct A_2ef080 {
    void one_00304350();
};
struct ImpulseBasedCollisionSolver_2ef080 {
    void two_002f79f0();
};
struct CollisionDetector_2ef080 {
    void three_003012c0();
};
struct Obj_2ef080 {
    // (x64t4) the physics world's parts at their offsets (decls/physics_world.h)
    char p70[HULK_PW_DETECTOR];
    CollisionDetector_2ef080 c;
    char p_after_c[HULK_PW_SOLVER - HULK_PW_DETECTOR - 1];
    ImpulseBasedCollisionSolver_2ef080 b;
    char p_after_b[HULK_PW_BUFFER - HULK_PW_SOLVER - 1];
    A_2ef080 a;
    void target();
};
class Obj_2ef0b0 {
  public:
    void Init_002eee10();
};
class CollisionDetector_2ef0b0 {
  public:
    void Init_00301290();
};
class ImpulseBasedCollisionSolver_2ef0b0 {
  public:
    void Init_002f7ee0();
};
class Obj1B0 {
  public:
    void Init_00304300();
};
struct CollisionDetector_2ef110 {
    void f1_003012c0();
};
struct ImpulseBasedCollisionSolver_2ef110 {
    void f2_002f79f0();
};
struct D {
    void f3_00304350();
};
struct C_2ef110 {
    // (x64t4) the physics world's parts at their offsets (decls/physics_world.h)
    char p0[HULK_PW_DETECTOR];
    CollisionDetector_2ef110 a;
    char p1[HULK_PW_SOLVER - HULK_PW_DETECTOR - 1];
    ImpulseBasedCollisionSolver_2ef110 b;
    char p2[HULK_PW_BUFFER - HULK_PW_SOLVER - 1];
    D c;
    C_2ef110* target(unsigned char flag);
};
void destroy_0008d330(C_2ef110*);
class CollisionDetector_2ef150 {
  public:
    void Fnf_003012c0();
    char pad[HULK_PW_SOLVER - HULK_PW_DETECTOR];
};
class ImpulseBasedCollisionSolver_2ef150 {
  public:
    void Fnf_002f79f0();
    char pad[HULK_PW_BUFFER - HULK_PW_SOLVER];
};
class C {
  public:
    void Fnf_00304350();
};
class Obj {
  public:
    char p0[HULK_PW_DETECTOR];  // (x64t4) the physics world's parts at their offsets (decls/physics_world.h)
    CollisionDetector_2ef150 a;
    ImpulseBasedCollisionSolver_2ef150 b;
    C c;
};
extern "C" void __cdecl freeObj_0008d330(void*);
struct Vec_2ef200 {
    float x, y, z;
};
class Inner_2ef200 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual Vec_2ef200* Get();
    char pad[0x15];
    unsigned char flag;
};
class Obj_2ef200 {
  public:
    char pad0[0x20];
    Inner_2ef200* inner;
    char pad1[0x44];
    unsigned char changed;
    void Add(Vec_2ef200* v);
};
class Inner_2ef270 {
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
};
class Target_2ef270 {
  public:
    char pad[0x20];
    Inner_2ef270* p;
    char pad2[0x44];
    unsigned char a, b;
    void run();
};
extern int hulk_at_00431214;
extern int hulk_at_003f6098;
class Obj_2ef2c0 {
  public:
    virtual void f0();
    virtual void Release();
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
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void Do(int);
};
class Inner_2ef2c0 {
  public:
    virtual void f0();
    virtual void Release();
    char pad[0x14];
    int value;
};
struct SimState {
    int* vptr;
    char pad[0x70 - 4];
    Obj_2ef2c0* m70;
    Inner_2ef2c0* m74;
    void Cleanup();
};


// 0x002ed240 FUN_002ed240 (386 B): equivalent/0x002ed240.cpp
// sym: ?FUN_002ed240@Broadphase_2ed240@fn_f671dae7@@QAEXH@Z @5b54c6aa4ef4 @w33725a3c6406
// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 25/26, incomplete; run with --inputs 12000)
// FUN_002ed240 @ 0x002ed240
void Broadphase_2ed240::FUN_002ed240(int index)
{
    Entry_2ed240 *en = entries[index];
    Body_2ed240 *body = en->body;
    Vec3_2ed240 *p = body->getPosition();
    float px = p->x;
    float pz = p->z;
    unsigned int maskB_lo = en->maskB_lo;
    float hx = body->half.x;
    float hz = body->half.z;
    float xmin = px - hx;
    float xmax = hx + px;
    unsigned int maskB_hi = en->maskB_hi;
    unsigned int maskA_hi = en->maskA_hi;
    unsigned int maskA_lo = en->maskA_lo;
    bool seen = false;
    for (unsigned int i = 0; i < spanCount; i++) {
        Span_2ed240 *s = &spans[i];
        if (s->lo > xmax)
            break;
        if (!seen) {
            if (s->lo > xmin)
                seen = true;
            else if (!(s->hi > xmin))
                continue;
        }
        if (!(pz - hz < s->zmin || s->zmax < hz + pz))
            continue;
        Entry_2ed240 *o = s->other;
        if ((o->maskA_lo & maskB_lo) == 0 && (o->maskA_hi & maskB_hi) == 0)
            continue;
        if ((o->maskB_lo & maskA_lo) == 0 && (o->maskB_hi & maskA_hi) == 0)
            continue;
        resultCount = 0;
        ((owners::Obj_302ed0 *)&resolver)->FUN_00302ed0((hulk_intptr)(Body_2ed240 *)(en->body), (hulk_intptr)(Body_2ed240 *)(s->other->body), (hulk_intptr)field2c);
    }
}


// 0x002ed3d0 FUN_002ed3d0 (772 B): equivalent/0x002ed3d0.cpp
// sym: ?FUN_002ed3d0@SweepAndPrune@fn_f671dae7@@QAEXI@Z @80c5fa163ecd @wbad7938629bd
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 37/40, incomplete)
// FUN_002ed3d0 @ 0x002ed3d0
void SweepAndPrune::FUN_002ed3d0(unsigned int index)
{
    Body_2ed3d0 *self = bodies[index];
    float keySelf = self->shape->v4()->x;
    float mrg = margin;
    unsigned int bLo = self->maskBLo;
    unsigned int bHi = self->maskBHi;
    unsigned int aLo = self->maskALo;
    unsigned int aHi = self->maskAHi;

    if (index > 0) {
        unsigned int j = index;
        unsigned int k = index - 1;
        Body_2ed3d0 *other = bodies[k];
        float otherKey = other->shape->v4()->x;
        for (;;) {
            float r = self->shape->radius;
            k = j - 1;
            float lo = keySelf - mrg;
            if (!(lo < r + otherKey))
                break;
            if (!(skip->bits[k >> 5] & (1u << (k & 31)))) {
                if (((other->maskALo & bLo) != 0 || (other->maskAHi & bHi) != 0) &&
                    ((other->maskBLo & aLo) != 0 || (other->maskBHi & aHi) != 0)) {
                    bool hit = true;
                    Shape_2ed3d0 *hs = self->shape;
                    Shape_2ed3d0 *os = other->shape;
                    float t1 = hs->v4()->z - zSlack;
                    if (os->v4()->z + os->halfZ < t1) {
                        hs = self->shape;
                        os = other->shape;
                        float t2 = hs->v4()->z + zSlack;
                        if (os->v4()->z - os->halfZ > t2)
                            hit = false;
                    }
                    if (hit) {
                        found = 0;
                        ((owners::Obj_302ed0 *)&pairs)->FUN_00302ed0((hulk_intptr)(Shape_2ed3d0 *)(self->shape), (hulk_intptr)(Shape_2ed3d0 *)(other->shape), (hulk_intptr)contact);
                    }
                }
            }
            j--;
            k--;
            if (j == 0)
                break;
            other = bodies[j - 1];
            otherKey = other->shape->v4()->x;
        }
    }

    if (index >= count - 1)
        return;
    Body_2ed3d0 *other = bodies[index + 1];
    float nbKey = other->shape->v4()->x;
    float r = self->shape->radius;
    if (index >= count - 1)
        return;
    float limit = mrg + keySelf;
    unsigned int j = index;
    unsigned int m = index + 1;
    for (;;) {
        if (!(nbKey - r < limit))
            break;
        if (!(skip->bits[m >> 5] & (1u << (m & 31)))) {
            if ((self->maskBLo & other->maskALo) != 0 || (self->maskBHi & other->maskAHi) != 0) {
                bool hit = true;
                Shape_2ed3d0 *hs = self->shape;
                Shape_2ed3d0 *os = other->shape;
                float t1 = hs->v4()->z - zSlack;
                if (os->v4()->z + os->halfZ < t1) {
                    hs = self->shape;
                    os = other->shape;
                    float t2 = hs->v4()->z + zSlack;
                    if (os->v4()->z - os->halfZ > t2)
                        hit = false;
                }
                if (hit) {
                    found = 0;
                    ((owners::Obj_302ed0 *)&pairs)->FUN_00302ed0((hulk_intptr)(Shape_2ed3d0 *)(self->shape), (hulk_intptr)(Shape_2ed3d0 *)(other->shape), (hulk_intptr)contact);
                }
            }
        }
        j++;
        m++;
        if (j < count - 1) {
            other = bodies[j + 1];
            nbKey = other->shape->v4()->x;
            r = self->shape->radius;
        }
        if (!(j < count - 1))
            break;
    }
}

} // namespace fn_f671dae7

// 0x002ed6e0 FUN_002ed6e0 (25 B): matches/0x002ed6e0.cpp
// sym: ?FUN_002ed6e0@Obj_2ed6e0@owners@@QAEXI@Z
void owners::Obj_2ed6e0::FUN_002ed6e0(u32_2ed6e0 arg) {
    ((Sub_2ed6e0*)((char*)this + HULK_PW_SOLVER))->Call_002f8020((char*)this + 0x2c, arg, 0);
}

namespace fn_f671dae7 {

// 0x002ed700 FUN_002ed700 (3 B): matches/0x002ed700.cpp
// sym: ?Self@LightGroup@pure3d@fn_f671dae7@@QAEPAV123@XZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
namespace pure3d {
LightGroup* LightGroup::Self() {
    return this;
}
}


// 0x002ed730 FUN_002ed730 (111 B): matches/0x002ed730.cpp
// sym: ?Sort@Sorter@fn_f671dae7@@QAEXXZ
void Sorter::Sort() {
    unsigned i = 1;
    if (i < count) {
        do {
            Item_2ed730* cur = items[i];
            float v = *cur->key->Get();
            unsigned j = i;
            while (j > 0 && *items[j - 1]->key->Get() > v) {
                items[j] = items[j - 1];
                j--;
            }
            items[j] = cur;
            i++;
        } while (i < count);
    }
}


// 0x002ed7a0 FUN_002ed7a0 (78 B): matches/0x002ed7a0.cpp
// sym: ?Find@Container_2ed7a0@fn_f671dae7@@QAE_NPAVObj_2ed7a0@2@@Z
bool Container_2ed7a0::Find(Obj_2ed7a0* obj) {
    unsigned int i;
    if (obj->flag) {
        for (i = 0; i < wideCount; ++i) {
            if ((Obj_2ed7a0*)wideItems[i * 5] == obj)
                return true;
        }
    } else {
        for (i = 0; i < count; ++i) {
            if ((Obj_2ed7a0*)items[i] == obj)
                return true;
        }
    }
    return false;
}


// 0x002edb20 FUN_002edb20 (102 B): equivalent/0x002edb20.cpp
// sym: ?FUN_002edb20@Mgr_2edb20@fn_f671dae7@@QAEEHHH@Z @a6786aa7f582 @w842c1666b553
// STATUS: equivalent (tools/equiv.py level 3: 131 inputs, branch coverage 6/6)
// FUN_002edb20 @ 0x002edb20
unsigned char Mgr_2edb20::FUN_002edb20(int a, int b, int c) {
    unsigned char result = 0;
    ((owners::Obj_3037e0 *)&sub)->FUN_003037e0();
    for (unsigned int i = 0; i < (unsigned int)(end - begin); i++) {
        Handler_2edb20* h = begin[i]->handler;
        if (h->GetKind() == 4)
            result |= h->Handle(a, b, c);
    }
    return result;
}


// 0x002edb90 FUN_002edb90 (97 B): matches/0x002edb90.cpp
// sym: ?Run@T_2edb90@fn_f671dae7@@QAE_NHH@Z
bool T_2edb90::Run(int a, int p) {
    bool r = false;
    ((owners::Obj_3037e0 *)&sub)->FUN_003037e0();
    for (unsigned i = 0; i < v.size(); i++) {
        Child_2edb90* c = v[i]->c;
        if (c->GetType() == 4)
            r |= c->Do(a, p);
    }
    return r;
}

} // namespace fn_f671dae7

// 0x002edc00 FUN_002edc00 (18 B): matches/0x002edc00.cpp
// sym: ?FUN_002edc00@ThisWrap_002edc00@owners@@QAEEI@Z
unsigned char owners::ThisWrap_002edc00::FUN_002edc00(hulk_uintptr value) {
    return (unsigned char)(this->FUN_002ed7a0(((unsigned int)value)) != 0);
}

namespace fn_f671dae7 {

// 0x002edc20 FUN_002edc20 (184 B): equivalent/0x002edc20.cpp
// sym: ?FUN_002edc20@Collection_2edc20@fn_f671dae7@@QAEXIIIIPAID@Z @05c08dce6576 @w7351f50c9ccf
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// FUN_002edc20 @ 0x002edc20
void Collection_2edc20::FUN_002edc20(Word_2edc20 output,Word_2edc20 query,Word_2edc20 a,Word_2edc20 b,Word_2edc20* result,char onlySelected)
{
 Work_2edc20 work;
 work.first=0; work.second=0; work.detail=0;
 for(unsigned int i=0; i < (unsigned int)(end-begin); ++i) {
  Entry_2edc20* entry=begin[i];
  work.detail=entry->detail;
  if(entry->enabled && (!onlySelected || entry->selected)) {
   if(FUN_002f1160(query,a,b,*result,&work)) {
    work.second=work.detail->value;
    FUN_002f24f0(output,&work,a,b,result);
   }
  }
 }
}


// 0x002edce0 FUN_002edce0 (265 B): equivalent/0x002edce0.cpp
// sym: ?FUN_002edce0@Manager_2edce0@fn_f671dae7@@QAEEPAUHit_2edce0@2@PAUVec_2edce0@2@1E@Z @916d0506bb34 @wed6711eb1bea
// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 19/20, incomplete)
// FUN_002edce0 @ 0x002edce0
unsigned char Manager_2edce0::FUN_002edce0(Hit_2edce0* hit, Vec_2edce0* start, Vec_2edce0* finish, unsigned char filter) {
 Vec_2edce0 delta; delta.x=finish->x-start->x; delta.y=finish->y-start->y; delta.z=finish->z-start->z;
 Vec_2edce0 direction=delta;
 float length=direction.FUN_0022d110();
 unsigned char result=0;
 if(hit->object) { result=FUN_002f15a0(start,&direction,&delta,length,hit->object,hit); if(result) return result; }
 unsigned int i=0;
 if((unsigned int)(end-begin)>0) {
 do {
 Entry_2edce0* entry=begin[i];
 if(entry->enabled && entry->object!=hit->object && (!filter || entry->flag50)) {
 result=FUN_002f15a0(start,&direction,&delta,length,entry->object,hit);
 if(result) return result;
 }
 ++i;
 } while(i<(unsigned int)(end-begin));
 }
 hit->object=0;
 return result;
}

} // namespace fn_f671dae7

// 0x002ede00 FUN_002ede00 (72 B): matches/0x002ede00.cpp
// sym: ?FUN_002ede00@Buffer_2ede00@owners@@QAEXH@Z
void owners::Buffer_2ede00::FUN_002ede00(int n) {
    if (n != 0) {
        void* q = FUN_0008d6d0(n * 4);  // (x64t4) by address (was `Alloc`, unbound)
        p = q;
        if (q != 0) {
            end = (char*)q + n * 4;
            begin = q;
            return;
        }
    } else {
        p = 0;
    }
    begin = 0;
    end = 0;
}

namespace fn_f671dae7 {

// 0x002ee0c0 FUN_002ee0c0 (60 B): matches/0x002ee0c0.cpp
// sym: ?Add@Buffer_2ee0c0@fn_f671dae7@@QAE_NPAUItem_2ee0c0@2@@Z
bool Buffer_2ee0c0::Add(Item_2ee0c0* value) {
    Item_2ee0c0* p = cur;
    if ((hulk_uintptr)p < (hulk_uintptr)end) {
        cur = p + 1;
        if (p)
            *p = *value;
        return true;
    }
    return false;
}

} // namespace fn_f671dae7

// 0x002ee140 FUN_002ee140 (275 B): equivalent/0x002ee140.cpp
// sym: ?target@World@@QAE_NPAUResults@fn_f671dae7@@PAUVec_2ee140@3@1H@Z @28cd5d2a125e @w52589322b788
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_002ee140 @ 0x002ee140
bool World::target(Results* results, Vec_2ee140* start, Vec_2ee140* end, int filter) {
 Vec_2ee140 difference; difference.x=end->x-start->x; difference.y=end->y-start->y; difference.z=end->z-start->z;
 Vec_2ee140 direction=difference;
 float length=direction.FUN_0022d110();
 if((*(unsigned char*)&DAT_00554c1c) && results->count>0) {
  Record_2ee140 record; record.zero=0; record.object=0; record.owner=0;
  Item_2ee140* item=results->entries->item;
  record.object=item;
  results->count=0;
  record.owner=item->owner;
  if(item->enabled && (!(filter & 255) || item->filter)) {
   if(FUN_002f1160(start,&direction,&difference,length,&record)) {
    record.object=record.owner->value;
    FUN_002f24f0(results,&record,&direction,&difference,&length);
   }
  }
 }
 FUN_002edc20(results,start,&direction,&difference,&length,filter);
 return results->count>0;
}

namespace fn_f671dae7 {

// 0x002ee260 FUN_002ee260 (631 B): equivalent/0x002ee260.cpp
// sym: ?FUN_002ee260@Tracker_2ee260@fn_f671dae7@@QAEXPAVObj_2ee260@2@@Z @37cbd20b32da @w424f9df701a5
// STATUS: equivalent (tools/equiv.py level 3: 2857 inputs, branch coverage 28/28; --wine 74 inputs)
// FUN_002ee260 @ 0x002ee260
void Tracker_2ee260::FUN_002ee260(Obj_2ee260 *obj)
{
    if (end < capEnd) {
        Obj_2ee260 **p = end;
        end = p + 1;
        if (p != 0)
            *p = obj;
    }
    obj->AddRef();
    if (obj->listed) {
        Bounds_2ee260 *b;
        b = obj->bounds;
        float x0 = b->GetPos()->x - b->halfX;
        b = obj->bounds;
        float x1 = b->GetPos()->x + b->halfX;   // the original reads halfX after the call
        b = obj->bounds;
        float z0 = b->GetPos()->z - b->halfZ;
        b = obj->bounds;
        float z1 = b->GetPos()->z + b->halfZ;
        entries[entryCount].obj = obj;
        entries[entryCount].x0 = x0;
        entries[entryCount].x1 = x1;
        entries[entryCount].z0 = z0;
        entries[entryCount].z1 = z1;
        entryCount++;
        if (obj->bounds->GetKind() == 8)
            return;
        unsigned int k = entryCount;
        while (k > 1) {
            if (entries[k - 1].obj->bounds->GetKind() != 8) {
                float hi = entries[k - 1].x0;
                float lo = entries[k - 2].x0;
                if (entries[k - 2].obj->bounds->GetKind() != 8) {
                    if (!(hi < lo))
                        return;
                }
                Entry_2ee260 *p1 = &entries[k - 1];
                Entry_2ee260 tmp = *p1;
                *p1 = entries[k - 2];
                entries[k - 2] = tmp;
            }
            k--;
        }
    } else {
        sorted[sortedCount] = obj;
        sortedCount++;
        if (obj->bounds->limit > maxA)
            maxA = obj->bounds->limit;
        if (obj->bounds->limit > maxB)
            maxB = obj->bounds->limit;
        unsigned int k = sortedCount;
        while (k > 1) {
            float a = sorted[k - 1]->bounds->GetPos()->x;
            if (!(a < sorted[k - 2]->bounds->GetPos()->x))
                return;
            Obj_2ee260 *lo = sorted[k - 2];
            Obj_2ee260 *hi = sorted[k - 1];
            sorted[k - 1] = lo;
            sorted[k - 2] = hi;
            k--;
        }
    }
}


// 0x002ee510 FUN_002ee510 (92 B): equivalent/0x002ee510.cpp
// sym: ?FUN_002ee510@Container@fn_f671dae7@@QAEXPAUItem@2@@Z @b3ec4426e495 @w5e6149fbf3f8
// STATUS: equivalent (tools/equiv.py level 3: 783 inputs, branch coverage 8/8)
// FUN_002ee510 @ 0x002ee510
void Container::FUN_002ee510(Item *item) {
    if (begin == end) return;
    for (unsigned i = 0; i < (unsigned)(end - begin); ++i) {
        if (begin[i] == item) {
            Item **last = end - 1;
            end = last;
            if (begin + i < last) begin[i] = *last;
            item->slot1();
            return;
        }
    }
}


// 0x002ee570 FUN_002ee570 (136 B): equivalent/0x002ee570.cpp
// sym: ?FUN_002ee570@Graph_2ee570@fn_f671dae7@@QAEXPAUItem_2ee570@2@0@Z @fd2dfe32d7bb @w17629570943c
// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 18/18)
// FUN_002ee570 @ 0x002ee570
// Adds an edge between x and y unless one already connects them.
void Graph_2ee570::FUN_002ee570(Item_2ee570 *x, Item_2ee570 *y)
{
    for (Entry_2ee570 *e = begin; e != end; e++) {
        if ((e->a == x || e->b == x) && (e->a == y || e->b == y))
            return;
    }
    Maker_2ee570 maker;
    Entry_2ee570 *made = x->flag ? maker.FUN_002f8ef0(x, y) : maker.FUN_002f8ef0(y, x);
    if (end < limit) {
        Entry_2ee570 *slot = end;
        end = slot + 1;
        if (slot)
            *slot = *made;
    }
}

} // namespace fn_f671dae7

// 0x002ee6b0 FUN_002ee6b0 (21 B): matches/0x002ee6b0.cpp
// sym: ?FUN_002ee6b0@Obj_2ee6b0@owners@@QAEXH@Z
void owners::Obj_2ee6b0::FUN_002ee6b0(hulk_intptr arg) {
    callee(((int)arg));
    flag = 1;
}

namespace fn_f671dae7 {

// 0x002ee6d0 FUN_002ee6d0 (37 B): matches/0x002ee6d0.cpp
// sym: ?Add@Container_2ee6d0@fn_f671dae7@@QAEXPAVItem_2ee6d0@2@@Z
void Container_2ee6d0::Add(Item_2ee6d0* item) {
    unsigned int* p = current;
    if (p < end) {
        current = p + 1;
        if (p != 0)
            *(hulk_uintptr*)p = (hulk_uintptr)item;
    }
    item->Execute();
}

// 0x002ee700 thunk_FUN_002ee510 (5 B): not yet verified

// 0x002ee710 FUN_002ee710 (646 B): equivalent/0x002ee710.cpp
// sym: ?FUN_002ee710@Registry_2ee710@fn_f671dae7@@QAEXPAUItem_2ee710@2@@Z @34683b3547ce @w2038d0552b62
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 65/66, incomplete)
// FUN_002ee710 @ 0x002ee710
void Registry_2ee710::FUN_002ee710(Item_2ee710 *obj)
{
    float f;
    bool removed = false;

    for (unsigned i = 0; i < (unsigned)(list_end - list_begin); i++) {
        if (list_begin[i] == obj) {
            Item_2ee710 **last = list_end - 1;
            removed = true;
            Item_2ee710 **slot = list_begin + i;
            list_end = last;
            if (slot < last)
                *slot = *last;
            break;
        }
    }

    for (unsigned i = 0; i < (unsigned)(pair_end - pair_begin); i++) {
        Rec20_2ee710 *e = pair_begin + i;
        if (e->a == obj || e->b == obj) {
            Rec20_2ee710 *last = pair_end - 1;
            pair_end = last;
            if (e < last)
                *e = *last;
        }
    }

    for (unsigned i = 0; i < (unsigned)(big_end - big_begin); i++) {
        Rec44 *e = big_begin + i;
        if (e->k0 == obj || e->k1 == obj) {
            big_begin[i].w0 = 0;
            big_begin[i].w1 = 0;
            big_begin[i].k0 = 0;
            big_begin[i].k1 = 0;
        }
    }

    if (obj->flag) {
        bool found = false;
        if (rec_count != 0) {
            for (unsigned i = 0; i < rec_count; i++) {
                if (found)
                    rec_begin[i - 1] = rec_begin[i];
                else if (rec_begin[i].key == obj)
                    found = true;
            }
            if (found)
                rec_count = rec_count - 1;
        }
    } else {
        f = obj->info->value;
        unsigned cnt = inf_count;
        if (cnt != 0) {
            unsigned i = 0;
            while (i < inf_count) {
                if (inf_begin[i] == obj)
                    break;
                i++;
            }
            if (i < inf_count) {
                while (i < cnt - 1) {
                    inf_begin[i] = inf_begin[i + 1];
                    i++;
                    cnt = inf_count;
                }
                inf_begin[inf_count - 1] = 0;
                inf_count = inf_count - 1;
            }
        }
        if (f >= maxA) {
            float m = DAT_003f32e0;
            unsigned c = inf_count;
            Item_2ee710 **q = inf_begin;
            for (; c != 0; c--, q++) {
                Info_2ee710 *in = (*q)->info;
                if (m < in->value)
                    m = in->value;
            }
            maxA = m;
        }
        if (f >= maxB) {
            float m = DAT_003f32e0;
            unsigned c = inf_count;
            Item_2ee710 **q = inf_begin;
            for (; c != 0; c--, q++) {
                Info_2ee710 *in = (*q)->info;
                if (m < in->value)
                    m = in->value;
            }
            maxB = m;
        }
    }

    if (removed)
        obj->FUN_slot1();
}


// 0x002ee9a0 FUN_002ee9a0 (114 B): equivalent/0x002ee9a0.cpp
// sym: ?FUN_002ee9a0@Graph_2ee9a0@fn_f671dae7@@QAEXHH@Z @f11a29d29f4b @w3e98a508cdd6
// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 16/16)
// FUN_002ee9a0 @ 0x002ee9a0
void Graph_2ee9a0::FUN_002ee9a0(int a, int b)
{
    if (a == b)
        return;
    for (Edge_2ee9a0 *p = begin; p != end; p++) {
        if ((p->a == a || p->b == a) && (p->a == b || p->b == b)) {
            Edge_2ee9a0 *last = end - 1;
            end = last;
            if (p < last)
                *p = *last;
            return;
        }
    }
}


// 0x002eea80 FUN_002eea80 (550 B): equivalent/0x002eea80.cpp
// sym: ?FUN_002eea80@Mgr@fn_f671dae7@@QAEXXZ @aac6fd504437 @w047996085034
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 51/51)
// FUN_002eea80 @ 0x002eea80
void Mgr::FUN_002eea80()
{
    valueCopy = value;
    unsigned int nwords = (bits->nbits + 0x1f) >> 5;
    if (nwords != 0)
        memset(&bits->words[0], 0, nwords * 4);
    valuePtr = &value;
    FUN_002ed730();
    hitEnd = hitBegin;

    for (unsigned int i = 0; i < count; ++i) {
        Item *it = items[i];
        if (!it->child->active)
            continue;
        if (it->hot || it->hot2 || force) {
            bits->words[i >> 5] |= 1u << (i & 0x1f);
            FUN_002ed240(i);
            FUN_002ed3d0(i);
        }
        if (it->hot || it->hot2) {
            if (!(it->flags & 0x80000000))
                continue;
            Child *c = it->child;
            if (!c->ready)
                c->touch();
            if (!checker->accept(it))
                continue;
            Child **p = hitEnd;
            if (p >= hitCap)
                continue;
            hitEnd = p + 1;
            if (p)
                *p = c;
        }
    }

    hulk_intptr nnodes = nodesEnd - nodesBegin;
    for (int i = 0; i < nnodes; ++i) {
        Target *t = nodesBegin[i]->target;
        if (t->type() == 4) {
            hulk_uintptr nhits = hitEnd - hitBegin;
            for (unsigned int j = 0; j < nhits; ++j) {
                dirty = 0;
                Child *c = hitBegin[j];
                if (c->sub->info->kind != 3 || t->slot == 5)
                    t->attach(c, 1);
            }
        }
    }

    hulk_intptr nlinks = linksEnd - linksBegin;
    for (int i = 0; i < nlinks; ++i) {
        dirty = 0;
        Link *l = &linksBegin[i];
        ((owners::Obj_302ed0 *)&solver)->FUN_00302ed0((hulk_intptr)(l->a->ref), (hulk_intptr)(l->b->ref), (hulk_intptr)(&value));
    }

    hulk_uintptr nitems = end - begin;
    for (unsigned int i = 0; i < nitems; i = i + 1, nitems = end - begin) {
        Item *it = begin[i];
        it->hot2 = 0;
        it->hot = 0;
    }
    force = 0;
}

// 0x002eecb0 thunk_FUN_002ee710 (5 B): not yet verified

// 0x002eecc0 FUN_002eecc0 (228 B): equivalent/0x002eecc0.cpp
// sym: ?reset@State_2eecc0@fn_f671dae7@@QAEXXZ @312a3fdbd699 @w1c2f1536feb2
// STATUS: equivalent (tools/equiv.py level 3: 27 inputs, branch coverage 18/18)
// FUN_002eecc0 @ 0x002eecc0
void State_2eecc0::reset() {
 unsigned i;
 for (i=0; i<(unsigned)(end-begin); ++i) begin[i]->clear();
 end=begin;
 for(i=0;i<valueCount;++i) values[i]=0;
 valueCount=0;
 for(i=0;i<recordCount;++i) records[i].value=0;
 recordCount=0;
 for(i=0;i<(unsigned)(end3-begin3);++i) begin3[i]->clear();
 end3=begin3;
 end2=begin2;
 unsigned n=(bits->count+31u)>>5;
 unsigned* words=bits->words;
 for(i=0;i<n;++i) words[i]=0;
 end4=begin4;
}


// 0x002eedd0 FUN_002eedd0 (34 B): matches/0x002eedd0.cpp
// sym: ?Run@Obj_2eedd0@fn_f671dae7@@QAEXPAX@Z
void Obj_2eedd0::Run(void* arg) {
    ((Inner_2eedd0*)this)->First_002eea80();
    ((Inner_2eedd0*)((char*)this + HULK_PW_SOLVER))->Second_002f8020((char*)this + 0x2c, arg, 0);
}

// 0x002eee00 thunk_FUN_002eecc0 (5 B): not yet verified

// 0x002eee10 FUN_002eee10 (432 B): equivalent/0x002eee10.cpp
// sym: ?FUN_002eee10@Pool_2eee10@fn_f671dae7@@QAEPAV12@XZ @5df244d0a4bb @w6afb8e897b15
// STATUS: equivalent (tools/equiv.py level 3: 29 inputs, branch coverage 24/24)
// FUN_002eee10 @ 0x002eee10
Pool_2eee10 *Pool_2eee10::FUN_002eee10()
{
    ids.first = 0; ids.last = 0; ids.end = 0;
    records.first = 0; records.last = 0; records.end = 0;
    indices.first = 0; indices.last = 0; indices.end = 0;
    edges.first = 0; edges.last = 0; edges.end = 0;
    flags.first = 0; flags.last = 0; flags.end = 0;

    if ((*(unsigned int*)&DAT_004d293c) != 0) {
        unsigned int bytes = (*(unsigned int*)&DAT_004d293c) * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        ids.first = p;
        if (p != 0) {
            ids.last = p;
            ids.end = p + bytes;
        } else {
            ids.last = 0;
            ids.end = 0;
        }
    } else {
        ids.first = 0;
        ids.last = 0;
        ids.end = 0;
    }

    if ((*(unsigned int*)&DAT_004d2948) != 0) {
        unsigned int bytes = (*(unsigned int*)&DAT_004d2948) * 20;
        char *p = (char *)FUN_0008d6d0(bytes);
        edges.first = p;
        if (p != 0) {
            edges.last = p;
            edges.end = p + bytes;
        } else {
            edges.last = 0;
            edges.end = 0;
        }
    } else {
        edges.first = 0;
        edges.last = 0;
        edges.end = 0;
    }

    if ((*(unsigned int*)&DAT_004d293c) != 0) {
        unsigned int bytes = (*(unsigned int*)&DAT_004d293c) * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        flags.first = p;
        if (p != 0) {
            flags.last = p;
            flags.end = p + bytes;
        } else {
            flags.last = 0;
            flags.end = 0;
        }
    } else {
        flags.first = 0;
        flags.last = 0;
        flags.end = 0;
    }

    slots = (int *)FUN_0008d6d0((*(unsigned int*)&DAT_004d293c) * 4);
    slotCount[0] = 0;
    slotCount[1] = 0;
    slotCount[2] = 0;
    links = (char *)FUN_0008d6d0((*(unsigned int*)&DAT_004d293c) * 20);
    linkCount = 0;

    unsigned int nbits = (*(unsigned int*)&DAT_004d293c);
    unsigned int words = (nbits + 0x1f) >> 5;
    unsigned int *b = (unsigned int *)FUN_0008d6d0(words * 4 + 4);
    b[0] = nbits;
    for (unsigned int i = 0; i < words; i++)
        b[1 + i] = 0;
    bits = b;
    unsigned int words2 = (b[0] + 0x1f) >> 5;
    for (unsigned int i = 0; i < words2; i++)
        b[1 + i] = 0;

    if ((*(unsigned int*)&DAT_004d2940) != 0) {
        unsigned int bytes = (*(unsigned int*)&DAT_004d2940) * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        indices.first = p;
        if (p != 0) {
            indices.last = p;
            indices.end = p + bytes;
        } else {
            indices.last = 0;
            indices.end = 0;
        }
    } else {
        indices.first = 0;
        indices.last = 0;
        indices.end = 0;
    }

    if ((*(unsigned int*)&DAT_004d2944) != 0) {
        unsigned int bytes = (*(unsigned int*)&DAT_004d2944) * 0x44;
        char *p = (char *)FUN_0008d6d0(bytes);
        records.first = p;
        if (p != 0) {
            records.end = p + bytes;
            records.last = p;
        } else {
            records.last = 0;
            records.end = 0;
        }
    } else {
        records.first = 0;
        records.last = 0;
        records.end = 0;
    }
    return this;
}

} // namespace fn_f671dae7

// 0x002eefc0 FUN_002eefc0 (139 B): matches/0x002eefc0.cpp
// sym: ?FUN_002eefc0@Obj_2eefc0@owners@@QAEXXZ
void owners::Obj_2eefc0::FUN_002eefc0() {
    Base();
    if (p10)
        operator delete(p10);
    operator delete[](p14);
    operator delete[](p24);
    p60 = p5c;
    if (p60)
        operator delete[](p60);
    p50 = p4c;
    if (p50)
        operator delete[](p50);
    p40 = p3c;
    if (p40)
        operator delete[](p40);
    p30 = p2c;
    if (p30)
        operator delete[](p30);
    p4 = p0;
    if (p4)
        operator delete[](p4);
}

namespace fn_f671dae7 {

// 0x002ef050 FUN_002ef050 (46 B): matches/0x002ef050.cpp
// sym: ?target@C_2ef050@fn_f671dae7@@QAEPAU12@XZ
C_2ef050* C_2ef050::target() {
    Fnf_002eee10();
    ((CollisionDetector_2ef050*)(pad + HULK_PW_DETECTOR))->Fnf_00301290();
    ((ImpulseBasedCollisionSolver_2ef050*)(pad + HULK_PW_SOLVER))->Fnf_002f7ee0();
    ((S3_2ef050*)(pad + HULK_PW_BUFFER))->Fnf_00304300();
    pad[HULK_PW_FLAG] = 0;
    return this;
}


// 0x002ef080 FUN_002ef080 (41 B): matches/0x002ef080.cpp
// sym: ?target@Obj_2ef080@fn_f671dae7@@QAEXXZ
void Obj_2ef080::target() {
    a.one_00304350();
    b.two_002f79f0();
    c.three_003012c0();
    ((owners::Obj_2eefc0 *)this)->FUN_002eefc0();
}


// 0x002ef0b0 FUN_002ef0b0 (90 B): matches/0x002ef0b0.cpp
// sym: _FUN_002ef0b0
// data: gObject_2ef0b0 = DAT_00554c14
extern "C" void FUN_002ef0b0() {
    if ((*(void**)&DAT_00554c14) == 0) {
        // (x64t4) the allocator by address (FUN_0008d690; was `Alloc`, unbound) and the world's parts at their
        // offsets (decls/physics_world.h)
        void* p = FUN_0008d690(HULK_PW_SIZE);
        if (p != 0) {
            ((Obj_2ef0b0*)p)->Init_002eee10();
            ((CollisionDetector_2ef0b0*)((char*)p + HULK_PW_DETECTOR))->Init_00301290();
            ((ImpulseBasedCollisionSolver_2ef0b0*)((char*)p + HULK_PW_SOLVER))->Init_002f7ee0();
            ((Obj1B0*)((char*)p + HULK_PW_BUFFER))->Init_00304300();
            *((char*)p + HULK_PW_FLAG) = 0;
            (*(void**)&DAT_00554c14) = p;
        } else
            (*(void**)&DAT_00554c14) = 0;
    }
}


// 0x002ef110 FUN_002ef110 (62 B): matches/0x002ef110.cpp
// sym: ?target@C_2ef110@fn_f671dae7@@QAEPAU12@E@Z
C_2ef110* C_2ef110::target(unsigned char flag) {
    c.f3_00304350();
    b.f2_002f79f0();
    a.f1_003012c0();
    ((owners::Obj_2eefc0 *)this)->FUN_002eefc0();
    if (flag & 1)
        destroy_0008d330(this);
    return this;
}


// 0x002ef150 FUN_002ef150 (69 B): matches/0x002ef150.cpp
// sym: ?destroyObj@fn_f671dae7@@YAXXZ
void destroyObj() {
    Obj* p = (*(Obj**)&DAT_00554c14);
    if (p) {
        p->c.Fnf_00304350();
        p->b.Fnf_002f79f0();
        p->a.Fnf_003012c0();
        ((owners::Obj_2eefc0 *)p)->FUN_002eefc0();
        freeObj_0008d330(p);
    }
    (*(Obj**)&DAT_00554c14) = 0;
}


// 0x002ef200 FUN_002ef200 (54 B): matches/0x002ef200.cpp
// sym: ?Add@Obj_2ef200@fn_f671dae7@@QAEXPAUVec_2ef200@2@@Z
void Obj_2ef200::Add(Vec_2ef200* v) {
    changed = 1;
    Vec_2ef200* p = inner->Get();
    p->x = p->x + v->x;
    p->y = v->y + p->y;
    p->z = v->z + p->z;
    inner->flag = 0;
}


// 0x002ef270 FUN_002ef270 (28 B): matches/0x002ef270.cpp
// sym: ?run@Target_2ef270@fn_f671dae7@@QAEXXZ
void Target_2ef270::run() {
    a = 1;
    b = 1;
    p->f8();
    p->f9();
}


// 0x002ef2c0 FUN_002ef2c0 (61 B): matches/0x002ef2c0.cpp
// sym: ?Cleanup@SimState@fn_f671dae7@@QAEXXZ
void SimState::Cleanup() {
    Inner_2ef2c0* a = m74;
    vptr = &hulk_at_00431214;
    if (a) {
        a->value = 0;
        m74->Release();
    }
    if (m70) {
        m70->Do(0);
        m70->Release();
    }
    vptr = &hulk_at_003f6098;
}

} // namespace fn_f671dae7
