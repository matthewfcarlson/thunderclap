// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b3020..0x001b6800 (kind game, layer game, confidence high), dominant class CCollisionManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5af65ff {
#define TREE_TU_END }
namespace fn_f5af65ff {} using namespace fn_f5af65ff;
#include "game/global.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f5af65ff {
class Obj_1b3020 {
  public:
    char pad0[0x0c];
    int m0c;
    char pad1[0x30 - 0x10];
    int m30;
    int m34;
    Obj_1b3020() throw();
};
struct Matrix { float data[12]; unsigned int x,y,z; float last; void FUN_0022b980(); };
struct String { unsigned int value[2]; void FUN_0027b0e0(const char*); void FUN_0027af50(); };
struct Manager_1b3040 { unsigned int FUN_00283a40(String*, Matrix*, float, float); };
extern "C" Manager_1b3040* __cdecl FUN_0027f250();
struct Entry_1b3040 { char first[64]; char second[64]; char reserved[48]; unsigned int value; };
struct Entry { float low; float middle; float high; char pad[0xa8]; };
class C_1b3300 {
    char pad[0x30];

  public:
    unsigned int value;
};
struct Vec {
    int x, y, z;
};
extern "C" void * __cdecl FUN_001b6580(void);
} // namespace fn_f5af65ff
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f5af65ff {
class Obj_1b3420 {
  public:
    virtual void f0();
    virtual void f1();
};
class Target_1b3420 {
  public:
    char pad[0x0c];
    volatile int state;
    char pad2[0x20];
    Obj_1b3420* volatile ptr;
    void Run();
};
extern const float kMinDist = 0.02f;
class Thing_1b3760 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_1b3760 {
  public:
    char pad[0x30];
    Thing_1b3760* mThing;
    void Set(Thing_1b3760*);
};
} // namespace fn_f5af65ff
namespace math {
struct Vector_1b37e0 { float x,y,z; };
}
namespace fn_f5af65ff {
struct Function_1b37e0 { virtual void vfunc_0(); virtual void vfunc_1(); };
extern "C" char DAT_0041d9a4[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
} // namespace fn_f5af65ff
extern char __cdecl FUN_001d04d0(hulk_intptr);
namespace fn_f5af65ff {
class Function5_1b38b0 : public FUN_001d0480 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    ScriptMemberFn field1c;
    Function5_1b38b0(const char*, ScriptMemberFn);
};
struct Function_1b3930 {
    virtual void f0();
    virtual void f1();
};
void FUN_001b3950(const char*, const char*, const char*, int);
typedef void(__cdecl* Fn)(int, int, int, int, int);
class Obj_1b39f0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Target_1b39f0 {
  public:
    char pad[0x0c];
    volatile int state;
    char pad2[0x20];
    Obj_1b39f0* volatile ptr;
    void Run();
};
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f5af65ff
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f5af65ff {
class Registry_1b3c00 {
  public:
    void FUN_001b3c00(const char*, Owner*);
};
class Function5_1b3c00 {
  public:
    Function5_1b3c00(const char*, Owner*);
    char pad[0x20];
};
struct Arg_1b3f90 {
    char p[0xc];
    int a;
    char q[0x14];
    int b;
};
struct Obj_1b3f90 {
    char p[0x4f0];
    hulk_intptr a, b, c;
    void target(Arg_1b3f90*);
};
struct Callee_1b3f90 {
    void call_002eccd0(int);
};
struct Helper_1b3fc0 {
    void init_002eccd0(int);
};
extern "C" void __cdecl FUN_002fa580(int);
extern "C++" __declspec(nothrow) void __cdecl FUN_001b3c50();
extern "C" void __cdecl FUN_002fa4e0(int, int, int);
struct Obj_1b3fc0 {
    char pad[8];
    int field;
};
struct State_1b4060 { char pad[0x58]; uint firstLow, firstHigh, secondLow, secondHigh; };
struct Link_1b4060 { char pad[0x74]; State_1b4060* state; };
struct Input_1b4060 { char pad[0x12c]; Link_1b4060* primary; Link_1b4060* secondary; };
struct Manager_1b4060 {  };
struct Owner_1b4060 { char pad[8]; Manager_1b4060* manager; bool FUN_001b4060(Input_1b4060* input); };
class Item_1b4140 {
  public:
    char pad[0x74];
    int value;
};
class Param {
  public:
    char pad[0x12c];
    Item_1b4140* first;
    Item_1b4140* second;
};
class Context {
  public:
    void call_002eecb0(int);
};
class Target_1b4140 {
  public:
    char pad[8];
    Context* context;
    bool f(Param* p);
};
struct Target_1b4190 {
    char pad[0x58];
    unsigned int w58, w5c, w60, w64;
};
struct Source_1b4190 {
    char pad[0x74];
    Target_1b4190* target;
};
struct Sink_1b4190 {
};
class Obj_1b4190 {
  public:
    char pad00[8];
    Sink_1b4190* sink;
    char FUN_001b4190(Source_1b4190* s);
};
struct Arg {
    char pad[0x74];
    void* p;
};
class Mgr {
  public:
    void Act_002eecb0(void*);
};
typedef unsigned int u32_1b4230;
struct Obj_1b4230 {
    char pad[0x74];
    void* child;
};
struct Worker_1b4230 {
};
struct Ctx_1b4230 {
    char pad[8];
    Worker_1b4230* worker;
    bool Target(Obj_1b4230*);
};
struct F_1b42b0 {
    unsigned lo, hi;
};
inline F_1b42b0 Or(const F_1b42b0& a, const F_1b42b0& b) {
    F_1b42b0 r;
    r.lo = a.lo | b.lo;
    r.hi = a.hi | b.hi;
    return r;
}
struct Inner_1b42b0 {
    char pad[0x58];
    F_1b42b0 a, b;
};
struct Obj_1b42b0 {
    char pad[0x74];
    Inner_1b42b0* in;
};
struct Mgr_1b42b0 {
};
struct Foo_1b42b0 {
    char pad[8];
    Mgr_1b42b0* mgr;
    bool Fn(Obj_1b42b0* o);
};
struct Data {
  public:
    char _m_pad_0[0x8];
    unsigned int first;
    unsigned int second;
    unsigned int* value;
    char _m_pad_14[0x60];
    void* ptr;
    char* FUN_00036d00();
};
class Inner {
  public:
    void thunk_002eecb0(void*);
};
struct Mask_1b4360 { unsigned lo, hi; };
struct Data_1b4360 { char pad[0x58]; Mask_1b4360 a; Mask_1b4360 b; };
struct Ctl_1b4360 { char pad[8]; void* owner; int state; char pad2[0x74 - 0x10]; Data_1b4360* data; };
struct Entity { char pad[0x100]; Ctl_1b4360* ctl; };
struct Sink_1b4360 {  };
struct Router {
    char pad[8];
    Sink_1b4360* sink;
    bool Apply(Entity* e);
};
class D {
  public:
    void Fnf_002eecb0(void*);
};
class C_1b43f0 {
    char pad[8];
    D* d;

  public:
    bool target(void* p);
};
struct Payload_1b4450 { char pad[0x58]; uint firstLow, firstHigh, combinedLow, combinedHigh; };
struct Subject_1b4450;
struct Record_1b4450 { char pad[8]; Subject_1b4450* owner; uint kind; char pad2[0x64]; Payload_1b4450* payload; };
struct Subject_1b4450 { char pad[0x1d9]; unsigned char flag; bool FUN_001d64c0();  };
struct Sink_1b4450 {  };
struct Controller_1b4450 { char pad[8]; Sink_1b4450* sink; bool target(Subject_1b4450* subject, bool force); };
struct Data_1b4540 { char pad[0x74]; void* resource; };
struct Item_1b4540 { char pad[0x14c]; Data_1b4540* owner; void FUN_00038c40(); };
struct List_1b4540 { char pad[0xc]; int count; Item_1b4540* FUN_00024190(int index); };
struct Container_1b4540 { char pad[0x20]; List_1b4540* list; };
struct Argument_1b4540 { char pad[0x1d9]; unsigned char flag;  };
extern "C" bool __cdecl FUN_002020a0(Data_1b4540*);
struct Receiver_1b4540 { void FUN_002eecb0(void*); };
struct Target_1b4540 { char pad0[8]; Receiver_1b4540* receiver; char pad1[0x4f4-0xc]; void* enabled; Container_1b4540* container; bool FUN_001b4540(Argument_1b4540* arg); };
class OtherClass {
  public:
    void Other_002ece90(int a, float b, float c);
};
class Target {
  public:
    char pad[0x5a8];
    float value;
    void Fn(int a, float b, float c);
};
extern "C" void __cdecl FUN_00096d50(char*, unsigned int, unsigned int, unsigned int);
struct Vec3_1b4770 {
    float x, y, z;
};
struct Triangle_1b4770 {
    char pad00[0x10];
    unsigned short a, b, c;
    char pad16[2];
};
struct Mesh_1b4770 {
    char pad00[8];
    Vec3_1b4770 *vertices;
    char pad0c[0xc];
    Triangle_1b4770 *triangles;
};
struct Model_1b4770 {
    char pad00[0x44];
    Mesh_1b4770 *mesh;
};
class Ref {
  public:
    virtual void a();
    virtual void release();
};
class Elem {
  public:
    void clear_001b3420();
};
class Other {
  public:
    void clean_002eee00();
};
class Obj {
  public:
    char _m_pad_0[0x8];
    union { Inner* field; Mgr* mgr; Other* other; };
    Ref* ref;
    char _m_pad_10[0x4e0];
    int x;
    int y;
    int z;
    void doIt_001b4620(Vec, int, int, int);
    bool Run(Arg* a);
    bool Fn(Data* d);
    void reset();
};
struct V3_1b4ab0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Kind_1b4ab0 {
    char pad0[0xc];
    int kind;
};
struct Probe_1b4ab0 {
    bool FUN_00201e00(V3_1b4ab0 *a, V3_1b4ab0 *b, int c, V3_1b4ab0 *d, V3_1b4ab0 *e, int f, int g);
};
void FUN_002f1ce0(V3_1b4ab0 *a, int value, V3_1b4ab0 *b, int *outv);
class Ref_1b4c40 {
public:
    virtual void AddRef();
    virtual void Release();
};
class RefHolder {
public:
    char pad00[0xc];
    Ref_1b4c40 *target;
    void FUN_001b4140(Ref_1b4c40 *r);
    void FUN_001b4060(Ref_1b4c40 *r);
    void FUN_001b4c40(Ref_1b4c40 *newTarget);
};
struct Triple {
    int x, y, z;
};
struct Actor {
    void FUN_001b4620(Triple value, int fourth, int fifth, int sixth);
    void FUN_001b4cd0(Triple value, int fourth);
};
class Entry_1b55c0 {
  public:
    int a, b, c;
};
class Owner_1b55c0 {
  public:
    virtual void Fn();
    char pad[0x3c];
    int value;
    void* data;
};
class Dummy_1b55c0 {
  public:
    virtual void x();
    virtual void y();
};
class Base_1b55c0 {
  public:
    int* items;
    int pad[3];
    int count;
    void Func(Owner_1b55c0*, int);
};
class List {
  public:
    void** first;
    void** last;
    void* Get(unsigned i);
};
struct Result_1b56a0 {
    char pad[0x0c];
};
struct Inner_1b5760 {
    char pad[0x18];
};
struct Item_1b5760 {
    char pad[0x44];
    Inner_1b5760* p;
};
struct Entry_1b57a0 {
    char bytes[24];
};
struct Item_1b57a0 {
    char pad[0x18];
    Entry_1b57a0* entries;
    char pad2[4];
    unsigned short count;
};
struct Obj_1b57a0 {
    char pad[0x44];
    Item_1b57a0* item;
};
class Manager_1b57a0 {
  public:
    Obj_1b57a0** begin;
    Obj_1b57a0** end;
    Entry_1b57a0* Get(int id);
};
struct Entry_1b5800 {
    char bytes[24];
};
struct Sub_1b5800 {
    char pad[0x18];
    Entry_1b5800* entries;
    char pad2[4];
    unsigned short count;
};
struct Item_1b5800 {
    char pad[0x44];
    Sub_1b5800* sub;
};
struct Vec_1b5800 {
    Item_1b5800** begin;
    Item_1b5800** end;
    Entry_1b5800* Get(int id);
};
struct Vec_1b5860 { unsigned int x,y,z; };
struct Plane_1b5860 { Vec_1b5860 n; unsigned int d; void FUN_0022dfe0(const Vec_1b5860*,const Vec_1b5860*,const Vec_1b5860*); };
struct Face_1b5860 { char pad[16]; unsigned short a,b,c; unsigned short pad2; };
struct Mesh_1b5860 { char pad[8]; Vec_1b5860* vertices; char pad2[12]; Face_1b5860* faces; };
struct Object { char pad[68]; Mesh_1b5860* mesh; };
struct Manager_1b5860 { Object** objects; Vec_1b5860* FUN_001b5860(Vec_1b5860* out,unsigned int id); };
struct Vec3_1b5a20 { float x,y,z; };
struct Triangle_1b5a20 { char pad[16]; unsigned short a,b,c; char tail[2]; };
struct Mesh_1b5a20 { char pad0[8]; Vec3_1b5a20* vertices; char pad1[12]; Triangle_1b5a20* triangles; };
struct Entry_1b5a20 { char pad[68]; Mesh_1b5a20* mesh; };
struct Table_1b5a20 { Entry_1b5a20** entries; Vec3_1b5a20* FUN_001b5a20(Vec3_1b5a20* output, unsigned int id); };
extern "C" char DAT_0041da1c[];
struct This_FUN_001d0480 {
    int FUN_001d0480(const char*, int);
};
class Method3_1b5bc0 {
  public:
    hulk_intptr vtable;
    ScriptFunctionFields f;
    ScriptMemberFn value1c;
    Method3_1b5bc0(const char*, ScriptMemberFn);
};
class CCollisionManager_1b5c40 {
  public:
    void Run(float, float, float);
};
class Function_1b5c40 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CCollisionManager_1b5c40*, float*, int);
};
struct Vec_1b5ce0 {
    float x, y, z;
};
struct VecI {
    float x, y, z;
    int i;
};
class Callee_1b5ce0 {
  public:
    bool Call(Vec_1b5ce0 v, int i);
};
typedef bool (Callee_1b5ce0::*Fn_1b5ce0)(Vec_1b5ce0, int);
struct Record_1b5d20 {
    char pad0[0x16];
    unsigned short flags;   // bits 13..15: group tag
};
struct RecordTable_1b5d20 {
    char pad0[0x18];
    Record_1b5d20* records;
    char pad1c[4];
    unsigned short count;
};
struct Node {
  public:
    char _m_pad_0[0x8];
    union { Data* data; char* items; };
    unsigned int type;
    char _m_pad_10[0x8];
    union { Kind_1b4ab0 *info; ushort* records; };
    char _m_pad_1c[0x28];
    RecordTable_1b5d20* table;
};
struct Hit_1b4ab0 {
    float scale;
    Node *node;
    int value;
};
struct HitList_1b4ab0 {
    int count;
    int pad4;
    Hit_1b4ab0 *hits;
};
} // namespace fn_f5af65ff
struct World {
    bool FUN_002ee140(HitList_1b4ab0 *list, V3_1b4ab0 *a, V3_1b4ab0 *b, int c);
};
namespace fn_f5af65ff {
extern "C" HitList_1b4ab0 *FUN_00202f00();
class Caster_1b4ab0 {
public:
    char pad0[8];
    World *world;
    char pad0c[0x4f4 - 0xc];
    Probe_1b4ab0 *probe;
    bool FUN_001b4ab0(V3_1b4ab0 *from, V3_1b4ab0 *to, V3_1b4ab0 *outA, V3_1b4ab0 *outB, char *flag, char *done);
};
struct Entry_1b56a0 {
    char pad[0x44];
    Node* node;
};
struct Owner_1b56a0 {
    Entry_1b56a0** entries;
    Result_1b56a0* Lookup(int key, int index);
};
class NodeList_1b5d20 {
public:
    Node** begin;
    Node** end;
    // Clears the group tag (bits 13..15) of every record whose tag equals `tag`.
    void FUN_001b5d20(unsigned short index, int tag);
};
struct Obj_1b5ec0 {
    virtual void AddRef();
    virtual void Release();
    int p0, p1, p2;
    hulk_intptr h;
};
struct Mesh_1b5ec0 {
    void Set_001b55c0(void* c, int v);
};
int FUN_002ee6d0(Obj_1b5ec0* o);
struct Ctx_1b5ec0 {
    void Reg_002ee6d0(Obj_1b5ec0* o);
};
extern char hulk_at_004c38f8[], hulk_at_004c3920[];
struct Holder_1b5ec0 {
    char pad[8];
    Ctx_1b5ec0* ctx;
    char pad2[0x4fc - 0xc];
    Obj_1b5ec0* slots[19];
    int vals[19];
    Mesh_1b5ec0 mesh;
    bool Add(Obj_1b5ec0* o, int v);
};
struct Voice {
    virtual void v0();
    virtual void Release();     // slot 1
};
struct Cache {
    void thunk_FUN_002ee510(Voice *v);
};
struct SoundData {
    char pad0[0x20];
    unsigned short size;        // 0x20
};
struct Sound_1b5f60 {
    virtual void v0();
    virtual void Release();     // slot 1
    char pad4[0x40];
    SoundData *data;            // 0x44
};
class SoundBank {
public:
    char pad0[8];
    Cache *cache;               // 0x8
    char pad0c[0x4fc - 0xc];
    Voice *voices[19];          // 0x4fc
    int voiceIds[19];           // 0x548
    Sound_1b5f60 **sounds;             // 0x594
    char pad598[0x5a4 - 0x598];
    unsigned int totalSize;     // 0x5a4

    bool FUN_001b5f60(int id);
};
struct Rec_1b6000 {
    char pad0[0x18];
    float x;
    float y;
    float z;
    float w;
    char pad1[0x44 - 0x28];
    void FUN_002f8e10(void **item, int *id);
};
class Registry_1b6000 {
public:
    char pad0[0x1b0];
    Rec_1b6000 *begin;
    Rec_1b6000 *end;
    char FUN_002edb90(int id, int mode);
};
class CCollisionManager_1b61c0 {
  public:
    void Method(float, float, float);
};
class CCollisionManager_1b62d0 {};
typedef void (CCollisionManager_1b62d0::*Fn_1b62d0)(float, float, float);
class Registry_1b62d0 { public:
    void FUN_001b62d0(const char* a1, CCollisionManager_1b62d0* a2, Fn_1b62d0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1b62d0;
template<> class Closure3_1b62d0<CCollisionManager_1b62d0, void, float, float, float> : public ScriptFunctionFields { public: virtual void* Fnv_001b61a0(int); Fn_1b62d0 fn; CCollisionManager_1b62d0* owner; Closure3_1b62d0(CCollisionManager_1b62d0* o) { owner = o; } };
class Raw_1b62d0 { public: void FUN_001b5bc0(const char*, Fn_1b62d0); };
extern "C" void* Alloc(hulk_uintptr);
class Arena_1b6380 {
  public:
    unsigned int *mStart, *mFree, *mEnd;
    Arena_1b6380();
};
extern void* hulk_at_0041da90[];
extern void* hulk_at_003f6098[];
struct Elem_1b6530 {
    char b[0x138];
    void Fini_001b39f0();
};
class CCollisionManager_1b6530 {
  public:
    void* vptr;
    char pad[0xc];
    Elem_1b6530 arr[4];
    char pad2[0xa4];
    void* m594;
    void* m598;
    ~CCollisionManager_1b6530();
};
} // namespace fn_f5af65ff
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_f5af65ff {
class CCollisionManager_1b6580 {
  public:
    CCollisionManager_1b6580() throw();
    virtual void Init() throw();
    char pad[0x5a8];
};
struct Vec3_1b65f0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct MeshIndices {
    char pad00[0x10];
    unsigned short idx[1];     // 0x10
};
struct MeshData_1b65f0 {
    char pad00[8];
    Vec3_1b65f0 *verts;               // 0x08
    char pad0c[0x18 - 0x0c];
    MeshIndices *indices;      // 0x18
};
struct MeshObj {
    char pad00[0x44];
    MeshData_1b65f0 *data;            // 0x44
};
class Locator {
public:
    virtual void v0();
    char pad04[0x5ac - 4];
    Locator();                 // FUN_001b6440
    char FUN_001b6000(Vec3_1b65f0 *pos, int *a1, int *a0);
};
class Mgr_1b65f0 {
public:
    MeshObj **objs;            // 0x00
    void FUN_001b5860(Vec3_1b65f0 *out, int id);
    int *FUN_001b5800(int id);
    char FUN_001b65f0(int id, int slot);
};


// 0x001b3020 FUN_001b3020 (18 B): matches/0x001b3020.cpp
// sym: ??0Obj_1b3020@fn_f5af65ff@@QAE@XZ
Obj_1b3020::Obj_1b3020() throw() {
    m0c = -1;
    m34 = 0;
    m30 = 0;
}

} // namespace fn_f5af65ff

// 0x001b3040 FUN_001b3040 (293 B): equivalent/0x001b3040.cpp
// sym: ?FUN_001b3040@Object_1b3040@owners@@QAEXIIIH@Z @7b4a24adc218 @w21db582c5790
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001b3040 @ 0x001b3040
void owners::Object_1b3040::FUN_001b3040(unsigned int px,unsigned int py,unsigned int pz,int kind) {
 if(kind<0 || kind>=13) return;
 index=kind; value=((Entry_1b3040*)&DAT_004e1830)[kind].value; c=0; x=px;y=py;z=pz;a=0;b=0;d=0;firstHandle=0x10000;
 if(((Entry_1b3040*)&DAT_004e1830)[kind].first[0]) { Matrix m; m.FUN_0022b980(); m.x=x;m.y=y;m.z=z; String s; s.FUN_0027b0e0(((Entry_1b3040*)&DAT_004e1830)[kind].first); Manager_1b3040* manager=FUN_0027f250(); firstHandle=manager->FUN_00283a40(&s,&m,-1.0f,1.0f); s.FUN_0027af50(); }
 secondHandle=0x10000;
 if(((Entry_1b3040*)&DAT_004e1830)[kind].second[0]) { Matrix m; m.FUN_0022b980(); m.x=x;m.y=y;m.z=z; String s; s.FUN_0027b0e0(((Entry_1b3040*)&DAT_004e1830)[kind].second); Manager_1b3040* manager=FUN_0027f250(); secondHandle=manager->FUN_00283a40(&s,&m,-1.0f,1.0f); s.FUN_0027af50(); }
}


// 0x001b3250 FUN_001b3250 (90 B): equivalent/0x001b3250.cpp
// sym: ?FUN_001b3250@Object_1b3250@owners@@QAEHM@Z @5979680e8e1b @we9d2940bbecf
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001b3250 @ 0x001b3250
int owners::Object_1b3250::FUN_001b3250(float value) {
 int i = index;
 if (i < 0 || value < ((Entry*)((char*)&DAT_004e1830 + 128))[i].low) return 0;
 if (value < ((Entry*)((char*)&DAT_004e1830 + 128))[i].middle) return 1;
 return value < ((Entry*)((char*)&DAT_004e1830 + 128))[i].high ? 2 : 3;
}


// 0x001b32b0 FUN_001b32b0 (41 B): matches/0x001b32b0.cpp
// sym: ?FUN_001b32b0@X_1b32b0@owners@@QAE_NH@Z
bool owners::X_1b32b0::FUN_001b32b0(hulk_intptr value) {
    int i = 0;
    if (count > 0) {
        while (i < count) {
            if (items[i] == ((int)value))
                return true;
            ++i;
        }
    }
    return false;
}


// 0x001b32e0 FUN_001b32e0 (22 B): matches/0x001b32e0.cpp
// sym: ?FUN_001b32e0@Thing_1b32e0@owners@@QAEXH@Z
void owners::Thing_1b32e0::FUN_001b32e0(hulk_intptr value) {
    if (count < 0x40) {
        vals[count] = ((int)value);
        ++count;
    }
}

namespace fn_f5af65ff {

// 0x001b3300 FUN_001b3300 (4 B): matches/0x001b3300.cpp
// sym: ?FUN_001b3300@fn_f5af65ff@@YIIPAVC_1b3300@1@@Z
// Same code shape as 0x000862e0 (propagated; names are from that function)
hulk_uintptr __fastcall FUN_001b3300(C_1b3300* self) {
    return self->value;
}


// 0x001b3320 FUN_001b3320 (56 B): matches/0x001b3320.cpp
// sym: ?FUN_001b3320@fn_f5af65ff@@YAXHUVec@1@@Z
void __cdecl FUN_001b3320(int n, Vec v) {
    if (n >= 0 && n < 13) {
        ((Obj *)FUN_001b6580())->doIt_001b4620(v, n, 0, 0);
        _ReadWriteBarrier();
    }
}


// 0x001b3360 FUN_001b3360 (105 B): matches/0x001b3360.cpp
// sym: ?FUN_001b3360@fn_f5af65ff@@YAXHPAD0H@Z
// data: gData_1b3360 = DAT_004e1830
void FUN_001b3360(int index, char* name, char* description, int value) {
    if (index < 0 || index >= 13)
        return;
    if (name != 0)
        strncpy(((char*)&DAT_004e1830) + index * 0xb4, name, 0x3f);
    int offset = index * 0xb4;
    ((char*)&DAT_004e1830)[offset + 0x3f] = 0;
    if (description != 0)
        strncpy(((char*)&DAT_004e1830) + offset + 0x40, description, 0x3f);
    ((char*)&DAT_004e1830)[offset + 0x7f] = 0;
    *(int*)(((char*)&DAT_004e1830) + offset + 0xb0) = value;
}

} // namespace fn_f5af65ff

// 0x001b33d0 FUN_001b33d0 (65 B): matches/0x001b33d0.cpp [wrapped: conflict: Entry]
// sym: ?FUN_001b33d0@fn_001b33d0@@YAXHHHHH@Z
namespace fn_001b33d0 {
// data: gEntries = DAT_004e18b0

struct Entry {
    int a[4];
    int b[4];
    int c[37];
};
void __cdecl FUN_001b33d0(int row, int col, int a, int b, int c) {
    if (row >= 0 && row < 13 && col >= 0 && col < 4) {
        ((Entry*)((char*)&DAT_004e1830 + 128))[row].a[col] = a;
        ((Entry*)((char*)&DAT_004e1830 + 128))[row].b[col] = b;
        ((Entry*)((char*)&DAT_004e1830 + 128))[row].c[col] = c;
    }
}
} // namespace fn_001b33d0

namespace fn_f5af65ff {

// 0x001b3420 FUN_001b3420 (31 B): matches/0x001b3420.cpp
// sym: ?Run@Target_1b3420@fn_f5af65ff@@QAEXXZ
void Target_1b3420::Run() {
    state = -1;
    Obj_1b3420* p = ptr;
    if (p) {
        p->f1();
        ptr = 0;
    }
}

} // namespace fn_f5af65ff

// 0x001b3440 FUN_001b3440 (118 B): equivalent/0x001b3440.cpp
// sym: ?FUN_001b3440@Timeline_1b3440@owners@@QAE_NM@Z @04a011501ec9 @wa1aad688cc92
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 8/8)
// FUN_001b3440 @ 0x001b3440
bool owners::Timeline_1b3440::FUN_001b3440(float dt)
{
    int t = track;
    if (t < 0)
        return false;
    int seg = FUN_001b3250(pos);
    if (((float*)((char*)&DAT_004e1830 + 144))[t * 45 + seg] == 0.0f && ((float*)((char*)&DAT_004e1830 + 160))[t * 45 + seg] == 0.0f)
        return false;
    hulk_freg t2 = dt + time; // the original keeps the sum and the product in x87 registers
    time = t2;
    hulk_freg p = t2 * rate;
    pos = p;
    if (p >= ((float*)((char*)&DAT_004e1830 + 140))[t * 45])
        return false;
    return true;
}


// 0x001b35d0 FUN_001b35d0 (80 B): equivalent/0x001b35d0.cpp
// sym: ?FUN_001b35d0@Obj_1b35d0@owners@@QAEMM@Z @384482976f3a @wf25911637433
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 6/6)
// FUN_001b35d0 @ 0x001b35d0
float owners::Obj_1b35d0::FUN_001b35d0(float time) { int savedIndex = index; if (savedIndex < 0) return (*(float*)&DAT_003f32e0); if (time < (*(float*)&DAT_0041d97c)) time = 0.02f; if (time >= limit) return (*(float*)&DAT_003f32e0); int pos = FUN_001b3250(time); return ((float*)((char*)&DAT_004e1830 + 144))[(unsigned int)pos + savedIndex * 45]; }


// 0x001b3670 FUN_001b3670 (85 B): matches/0x001b3670.cpp
// sym: ?FUN_001b3670@Vec_1b3670@owners@@QAEEPBU12@@Z
unsigned char owners::Vec_1b3670::FUN_001b3670(const owners::Vec_1b3670* other) {
    hulk_freg dx = other->x - x, dy = other->y - y, dz = other->z - z;
    hulk_freg a = dz * dz;
    a += dx * dx;
    a += dy * dy;
    a = (hulk_freg)sqrt(a);
    if (a < kMinDist)
        a = kMinDist;
    return a <= limit;
}

namespace fn_f5af65ff {

// 0x001b3760 FUN_001b3760 (38 B): matches/0x001b3760.cpp
// sym: ?Set@Owner_1b3760@fn_f5af65ff@@QAEXPAVThing_1b3760@2@@Z
void Owner_1b3760::Set(Thing_1b3760* p) {
    if (p)
        p->A();
    if (mThing)
        mThing->B();
    mThing = p;
}

} // namespace fn_f5af65ff

// 0x001b3790 FUN_001b3790 (76 B): matches/0x001b3790.cpp [wrapped: conflict: Function2]
// sym: ??0Function2@fn_001b3790@@QAE@HH@Z
namespace fn_001b3790 {

struct Vector {
    float x, y, z;
};
extern int hulk_at_0048e10c;
unsigned char __cdecl lookup_001d04d0(const void*);
class Function_1b3790 {
  public:
    virtual void f();
    Function_1b3790(int, int);
    char pad[12];
};
class Function2 : public Function_1b3790 {
  public:
    virtual void f();
    Function2(int, int);
    unsigned char x, y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    int val;
};
Function2::Function2(int arg, int v) : Function_1b3790(arg, 2) {
    val = v;
    z = lookup_001d04d0(((int*)&DAT_0048e100));
    x = lookup_001d04d0(((int*)&DAT_0048e134));
    y = lookup_001d04d0(&hulk_at_0048e10c);
}
} // namespace fn_001b3790


// 0x001b37e0 Function2<void,int,math::Vector>::vfunc_2 (45 B): equivalent/0x001b37e0.cpp
// sym: ?vfunc_2@?$Function2@XHVVector@math@@@@UAEXPAX00@Z @b33272d857a4 @wd6dde55d7ec9
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Function2<void,int,math::Vector>::vfunc_2 @ 0x001b37e0
template <> void Function2<void, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; const math::Vector_1b37e0 * value = (const math::Vector_1b37e0 *)__p1; hulk_intptr extra = (hulk_intptr)__p2;

    (*(void (**)(int, math::Vector_1b37e0))&this->f_1c)(*(const int*)value, *(const math::Vector_1b37e0*)((const char*)value+4));
}


// 0x001b3810 FUN_001b3810 (102 B): matches/0x001b3810.cpp [wrapped: conflict: Function4]
// sym: ??0Function4@fn_001b3810@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001b3810 {

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

// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
extern const int hulk_at_0041d994;
class Function4 : public FUN_001d0480 {
  public:
    hulk_intptr vf;
    ScriptFunctionFields f;
    ScriptMemberFn fn;
    Function4(const char*, ScriptMemberFn);
};
Function4::Function4(const char* a, ScriptMemberFn b) : FUN_001d0480(a, 4) {
    vf = (hulk_intptr)&hulk_at_0041d994;
    fn = b;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e128));
}
} // namespace fn_001b3810
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b3880 Function4<void,int,const_char_*,const_char_*,float>::vfunc_2 (37 B): matches/0x001b3880.cpp [wrapped: conflict: Function; Function4]
// sym: ?vfunc_2@Function4@fn_001b3880@@UAEXHPAHH@Z
namespace fn_001b3880 {
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Function4 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_2(int, int*, int);
    char pad[24];
    void(__cdecl* fn)(int, const char*, const char*, float);
};
void Function4::vfunc_2(int, int* a, int) {
    int* p = a;
    int x = *p++;
    const char* y = (const char*)*p++;
    const char* z = (const char*)*p++;
    float w = *(float*)p;
    fn(x, y, z, w);
}
} // namespace fn_001b3880

namespace fn_f5af65ff {

// 0x001b38b0 FUN_001b38b0 (115 B): matches/0x001b38b0.cpp
// sym: ??0Function5_1b38b0@fn_f5af65ff@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
// Method5's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
Function5_1b38b0::Function5_1b38b0(const char* a, ScriptMemberFn b) : FUN_001d0480(a, 5) {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_0041d9a4);
    field1c = b;
    f.retType = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[2] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
}

} // namespace fn_f5af65ff

// 0x001b3930 Function5<void,int,int,float,float,float>::vfunc_2 (30 B): matches/0x001b3930.cpp
// sym: ?vfunc_2@?$Function5@XHHMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Function5<void, int, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001b3950(a, b, c, this->f_1c);
}

namespace fn_f5af65ff {

// 0x001b3950 FUN_001b3950 (49 B): matches/0x001b3950.cpp
// sym: ?FUN_001b3950@fn_f5af65ff@@YAXHPAHHP6AXHHHHH@Z@Z
void FUN_001b3950(int unused, int* p, int unused2, Fn fn) {
    int a = *p++;
    int b = *p++;
    int* q = p;
    *(int* volatile*)&p = (int*)*q++;
    int e = q[1];
    int d = q[0];
    fn(a, b, (hulk_intptr)*(int* volatile*)&p, d, e);
}

} // namespace fn_f5af65ff

// 0x001b3990 Function2<void,int,math::Vector>::vfunc_0 (30 B): matches/0x001b3990.cpp
// sym: ??_G?$Function2@XHVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function2<void, int,math::Vector>::~Function2() {}
#if defined(HULK_PTR64)
template class Function2<void, int,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b3990)
#endif


// 0x001b39b0 Function4<void,int,const_char_*,const_char_*,float>::vfunc_0 (30 B): matches/0x001b39b0.cpp
// sym: ??_G?$Function4@XHPBDPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function4<void, int, const char *, const char *, float>::~Function4() {}
#if defined(HULK_PTR64)
template class Function4<void, int, const char *, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b39b0)
#endif


// 0x001b39d0 Function5<void,int,int,float,float,float>::vfunc_0 (30 B): matches/0x001b39d0.cpp
// sym: ??_G?$Function5@XHHMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function5<void, int, int, float, float, float>::~Function5() {}
#if defined(HULK_PTR64)
template class Function5<void, int, int, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b39d0)
#endif

namespace fn_f5af65ff {

// 0x001b39f0 FUN_001b39f0 (31 B): matches/0x001b39f0.cpp
// sym: ?Run@Target_1b39f0@fn_f5af65ff@@QAEXXZ
// Same code shape as 0x001b3420 (propagated; names are from that function)
void Target_1b39f0::Run() {
    state = -1;
    Obj_1b39f0* p = ptr;
    if (p) {
        p->f1();
        ptr = 0;
    }
}


// 0x001b3c00 FUN_001b3c00 (65 B): matches/0x001b3c00.cpp
// sym: ?FUN_001b3c00@Registry_1b3c00@fn_f5af65ff@@QAEXPBDPAUOwner@2@@Z
void Registry_1b3c00::FUN_001b3c00(const char* a1, Owner* a2) {
    Function5_1b3c00* e = new (FUN_0008d690(0x20)) Function5_1b3c00(a1, a2);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}

} // namespace fn_f5af65ff

// 0x001b3c50 FUN_001b3c50 (340 B): equivalent/0x001b3c50.cpp [wrapped: conflict: DAT_0048e100; DAT_0048e134; DAT_004e2194; Function (+1)]
// sym: _FUN_001b3c50 @854611259ded @w49c763b336b9
namespace fn_001b3c50 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_001b3c50 @ 0x001b3c50
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

extern "C" void* __cdecl FUN_0008d690(unsigned int size);
extern "C" void* __cdecl FUN_001d4c90();
extern "C++" { extern const char DAT_0048e100[]; }
extern "C" const char DAT_0048e10c[];
extern "C++" { extern const char DAT_0048e134[]; }


namespace math {
class Vector;
}

template <class T> struct TypeName;
template <> struct TypeName<void> { static const char* get() { return DAT_0048e100; } };
template <> struct TypeName<int> { static const char* get() { return DAT_0048e134; } };
template <> struct TypeName<math::Vector> { static const char* get() { return DAT_0048e10c; } };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) Function : public ScriptFunctionFields {
  public:
    virtual void* f0_001b3990(int);
    virtual bool f1_001d04c0(int, int);
    void FUN_001d0480(const char*, int);
    Function(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class R, class A, class B>
class Function2 : public Function {
  public:
    typedef R (__cdecl *Fn)(A, B);
    Function2(const char* name, Fn f) : Function(name, 2) {
        fn = f;
        retType = FUN_001d04d0(TypeName<R>::get());
        argTypes[0] = FUN_001d04d0(TypeName<A>::get());
        argTypes[1] = FUN_001d04d0(TypeName<B>::get());
    }
    Fn fn;
};

struct Registry_1b3c50 { void FUN_001d3b70(const char*, void*); };

// Function4 / Function5 (matches/0x001b3810.cpp, 0x001b38b0.cpp): Function's fields, then the bound free function
// (its type is the game's Function<N> instantiation; 0x00086fa0's Invoke calls it __cdecl).
struct Function4_1b3c50 { void* vftable; ScriptFunctionFields f; void (__cdecl* fn)(int, const char*, const char*, float); Function4_1b3c50* FUN_001b3810(const char*, void (__cdecl*)(int, const char*, const char*, float)); };
struct Function5_1b3c50 { void* vftable; ScriptFunctionFields f; void (__cdecl* fn)(int, int, float, float, float); Function5_1b3c50* FUN_001b38b0(const char*, void (__cdecl*)(int, int, float, float, float)); };

void __cdecl FUN_001b3360(int, const char*, const char*, float);
void __cdecl FUN_001b33d0(int, int, float, float, float);
void __cdecl FUN_001b3320(int, math::Vector);

/* 180-byte records starting at 0x4e1830; this view starts at each record's +0x40 byte. */
struct ProfileTail {
    char active;
    char pad01[0x3f];
    float v[13];
};
extern char DAT_004e1870[];
extern char DAT_004e2194[];

extern "C" void FUN_001b3c50()
{
    ProfileTail* e = (ProfileTail*)DAT_004e1870;
    do {
        e->v[12] = 20.0f;
        e->v[0] = 4.0f;
        e->v[4] = 8000.0f;
        e->v[8] = 10.0f;
        e->v[1] = 10.0f;
        e->v[5] = 5000.0f;
        e->v[9] = 50.0f;
        e->v[2] = 15.0f;
        e->v[6] = 2000.0f;
        e->v[10] = 2.0f;
        e->v[3] = 20.0f;
        e->v[7] = 0.0f;
        e->v[11] = 0.0f;
        ((char*)e)[-0x40] = 0; /* record +0x00: enabled */
        e->active = 0;
        e = (ProfileTail*)((char*)e + 0xb4);
    } while ((char*)e < DAT_004e2194);

    Registry_1b3c50* reg = (Registry_1b3c50*)FUN_001d4c90();
    if (reg) {
        typedef Function2<void, int, math::Vector> FunctionIV;
        HULK_SIZE32(FunctionIV, 0x20);
        void* mem = FUN_0008d690((int)sizeof(FunctionIV));
        Function2<void, int, math::Vector>* trigger = 0;
        if (mem)
            trigger = new (mem) Function2<void, int, math::Vector>("exp_Trigger", FUN_001b3320);
        reg->FUN_001d3b70("exp_Trigger", trigger);

        HULK_SIZE32(Function4_1b3c50, 0x20);
        Function4_1b3c50* profile = (Function4_1b3c50*)FUN_0008d690((int)sizeof(Function4_1b3c50));
        if (profile)
            profile = profile->FUN_001b3810("exp_DefineProfile", FUN_001b3360);
        reg->FUN_001d3b70("exp_DefineProfile", profile);

        HULK_SIZE32(Function5_1b3c50, 0x20);
        Function5_1b3c50* damage = (Function5_1b3c50*)FUN_0008d690((int)sizeof(Function5_1b3c50));
        if (damage) {
            damage = damage->FUN_001b38b0("exp_DefineProfileDamage", FUN_001b33d0);
            reg->FUN_001d3b70("exp_DefineProfileDamage", damage);
        } else {
            reg->FUN_001d3b70("exp_DefineProfileDamage", 0);
        }
    }
}
} // namespace fn_001b3c50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f5af65ff {

// 0x001b3f90 FUN_001b3f90 (48 B): matches/0x001b3f90.cpp
// sym: ?target@Obj_1b3f90@fn_f5af65ff@@QAEXPAUArg_1b3f90@2@@Z
void Obj_1b3f90::target(Arg_1b3f90* arg) {
    a = arg->a;
    int t = arg->b;
    c = (hulk_intptr)arg;
    int g = DAT_004c3880;
    b = t;
    ((Callee_1b3f90*)(*(void**)&DAT_00554c10))->call_002eccd0(g);
}


// 0x001b3fc0 FUN_001b3fc0 (80 B): matches/0x001b3fc0.cpp
// sym: ?target@fn_f5af65ff@@YIXPAUObj_1b3fc0@1@@Z
void __fastcall target(Obj_1b3fc0* self) {
    if ((*(int*)&DAT_004e215c) == 0) {
        (*(int*)&DAT_004e215c) = (*(int*)&DAT_00554c10);
        ((Helper_1b3fc0*)(*(int*)&DAT_00554c10))->init_002eccd0(0x40000000);
    }
    if (self->field == 0)
        self->field = (*(int*)&DAT_00554c14);
    FUN_002fa580(1);
    FUN_001b3c50();
    FUN_002fa4e0(0x14, 0x19, 500);
}


// 0x001b4060 FUN_001b4060 (212 B): equivalent/0x001b4060.cpp
// sym: ?FUN_001b4060@Owner_1b4060@fn_f5af65ff@@QAE_NPAUInput_1b4060@2@@Z @79b1103476a6 @w920c821555dd
// STATUS: equivalent (tools/equiv.py level 3: 2772 inputs, branch coverage 8/8)
// FUN_001b4060 @ 0x001b4060
bool Owner_1b4060::FUN_001b4060(Input_1b4060* input) {
    if (!input->primary) return false;
    State_1b4060* primary = input->primary->state;
    if (!primary) return false;
    primary->firstLow = (*(uint*)&DAT_004c39f0);
    primary->firstHigh = (*(uint*)((char*)&DAT_004c39f0 + 4));
    primary->secondLow = (*(uint*)&DAT_004c39f0) | (*(uint*)&DAT_004c3a18) | (*(uint*)&DAT_004c39e8) | (*(uint*)&DAT_004c3a10) | (*(uint*)&DAT_004c3a20);
    primary->secondHigh = (*(uint*)((char*)&DAT_004c39f0 + 4)) | (*(uint*)((char*)&DAT_004c3a18 + 4)) | (*(uint*)((char*)&DAT_004c39e8 + 4)) | (*(uint*)((char*)&DAT_004c3a10 + 4)) | (*(uint*)((char*)&DAT_004c3a20 + 4));
    State_1b4060* secondary = 0;
    if (input->secondary) {
        secondary = input->secondary->state;
        secondary->firstLow = (*(uint*)&DAT_004c3a08);
        secondary->firstHigh = (*(uint*)&DAT_004c3a0c);
        secondary->secondLow = (*(uint*)&DAT_004c39e8);
        secondary->secondHigh = (*(uint*)((char*)&DAT_004c39e8 + 4));
    }
    ((owners::Obj_2ee6b0 *)manager)->FUN_002ee6b0((hulk_intptr)(State_1b4060 *)primary);
    if (secondary) ((owners::Obj_2ee6b0 *)manager)->FUN_002ee6b0((hulk_intptr)(State_1b4060 *)secondary);
    return true;
}


// 0x001b4140 FUN_001b4140 (69 B): matches/0x001b4140.cpp
// sym: ?f@Target_1b4140@fn_f5af65ff@@QAE_NPAVParam@2@@Z
bool Target_1b4140::f(Param* p) {
    int a = 0;
    if (p->first)
        a = p->first->value;
    if (p->second && p->second->value)
        context->call_002eecb0(p->second->value);
    if (a)
        context->call_002eecb0(a);
    return true;
}


// 0x001b4190 FUN_001b4190 (102 B): equivalent/0x001b4190.cpp
// sym: ?FUN_001b4190@Obj_1b4190@fn_f5af65ff@@QAEDPAUSource_1b4190@2@@Z @afc3ef336691 @w70fca2b5e28c
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 4/4)
// FUN_001b4190 @ 0x001b4190
char Obj_1b4190::FUN_001b4190(Source_1b4190* s) {
    if (s == 0)
        return 0;
    Target_1b4190* t = s->target;
    if (t == 0)
        return 0;
    t->w58 = (*(unsigned int*)&DAT_004c39f8);
    t->w5c = (*(unsigned int*)((char*)&DAT_004c39f8 + 4));
    t->w60 = (*(unsigned int*)&DAT_004c3a20) | ((*(unsigned int*)&DAT_004c3a18) | (*(unsigned int*)&DAT_004c39e8));
    t->w64 = (*(unsigned int*)((char*)&DAT_004c3a20 + 4)) | ((*(unsigned int*)((char*)&DAT_004c3a18 + 4)) | (*(unsigned int*)((char*)&DAT_004c39e8 + 4)));
    ((owners::Obj_2ee6b0 *)sink)->FUN_002ee6b0((hulk_intptr)(Target_1b4190 *)t);
    return 1;
}


// 0x001b4200 FUN_001b4200 (35 B): matches/0x001b4200.cpp
// sym: ?Run@Obj@fn_f5af65ff@@QAE_NPAUArg@2@@Z
bool Obj::Run(Arg* a) {
    void* p = a->p;
    bool r = true;
    if (p)
        mgr->Act_002eecb0(p);
    else
        r = false;
    return r;
}


// 0x001b4230 FUN_001b4230 (70 B): matches/0x001b4230.cpp
// sym: ?Target@Ctx_1b4230@fn_f5af65ff@@QAE_NPAUObj_1b4230@2@@Z
bool Ctx_1b4230::Target(Obj_1b4230* p) {
    if (p == 0)
        return false;
    void* child = p->child;
    if (child == 0)
        return false;
    u32_1b4230* q = (u32_1b4230*)child;
    q[0x58 / 4] = (*(u32_1b4230*)&DAT_004c3a00);
    q[0x5c / 4] = (*(u32_1b4230*)&DAT_004c3a04);
    q[0x60 / 4] = (*(u32_1b4230*)&DAT_004c39e8);
    q[0x64 / 4] = (*(u32_1b4230*)((char*)&DAT_004c39e8 + 4));
    ((owners::Obj_2ee6b0 *)worker)->FUN_002ee6b0((hulk_intptr)q);
    return true;
}

} // namespace fn_f5af65ff

// 0x001b4280 FUN_001b4280 (35 B): matches/0x001b4280.cpp [wrapped: conflict: Obj]
// sym: ?Test@Obj@fn_001b4280@@QAE_NPAUThing@2@@Z
namespace fn_001b4280 {
struct Thing {
    char pad[0x74];
    void* item;
};
class Manager {
  public:
    void Act_002eecb0(void*);
};
class Obj {
  public:
    char pad[8];
    Manager* mgr;
    bool Test(Thing* t);
};
bool Obj::Test(Thing* t) {
    bool result = true;
    if (t->item)
        mgr->Act_002eecb0(t->item);
    else
        result = false;
    return result;
}
} // namespace fn_001b4280

namespace fn_f5af65ff {

// 0x001b42b0 FUN_001b42b0 (118 B): matches/0x001b42b0.cpp
// sym: ?Fn@Foo_1b42b0@fn_f5af65ff@@QAE_NPAUObj_1b42b0@2@@Z
bool Foo_1b42b0::Fn(Obj_1b42b0* o) {
    if (!o)
        return false;
    Inner_1b42b0* i = o->in;
    if (!i)
        return false;
    i->a = (*(F_1b42b0*)&DAT_004c3a10);
    i->b = Or((*(F_1b42b0*)&DAT_004c3a20), Or((*(F_1b42b0*)&DAT_004c3a18), Or((*(F_1b42b0*)&DAT_004c39f0), (*(F_1b42b0*)&DAT_004c39e8))));
    ((owners::Obj_2ee6b0 *)mgr)->FUN_002ee6b0((hulk_intptr)(Inner_1b42b0 *)i);
    return true;
}


// 0x001b4330 FUN_001b4330 (35 B): matches/0x001b4330.cpp
// sym: ?Fn@Obj@fn_f5af65ff@@QAE_NPAUData@2@@Z
bool Obj::Fn(Data* d) {
    void* p = d->ptr;
    bool ok = true;
    if (p)
        field->thunk_002eecb0(p);
    else
        ok = false;
    return ok;
}


// 0x001b4360 FUN_001b4360 (137 B): equivalent/0x001b4360.cpp
// sym: ?Apply@Router@fn_f5af65ff@@QAE_NPAUEntity@2@@Z @e9c4085c06cf @w8785700cc4b1
// STATUS: equivalent (tools/equiv.py level 3: 2971 inputs, branch coverage 4/4)
// FUN_001b4360 @ 0x001b4360
bool Router::Apply(Entity* e) {
    Ctl_1b4360* c = e->ctl;
    if (!c || !c->data) return false;
    Data_1b4360* d = c->data;
    c->owner = e;
    c->state = 7;
    d->a = (*(Mask_1b4360*)&DAT_004c3a18);
    d->b.lo = (*(Mask_1b4360*)&DAT_004c3a20).lo | ((*(Mask_1b4360*)&DAT_004c39e8).lo | ((*(Mask_1b4360*)&DAT_004c39f8).lo | (*(Mask_1b4360*)&DAT_004c39f0).lo));
    d->b.hi = (*(Mask_1b4360*)&DAT_004c3a20).hi | ((*(Mask_1b4360*)&DAT_004c39e8).hi | ((*(Mask_1b4360*)&DAT_004c39f8).hi | (*(Mask_1b4360*)&DAT_004c39f0).hi));
    ((owners::Obj_2ee6b0 *)sink)->FUN_002ee6b0((hulk_intptr)(Data_1b4360 *)d);
    return true;
}


// 0x001b43f0 FUN_001b43f0 (35 B): matches/0x001b43f0.cpp
// sym: ?target@C_1b43f0@fn_f5af65ff@@QAE_NPAX@Z
bool C_1b43f0::target(void* p) {
    void* a = *(void**)((char*)p + 0x100);
    if (a) {
        void* b = *(void**)((char*)a + 0x74);
        if (b)
            d->Fnf_002eecb0(b);
    }
    return true;
}

} // namespace fn_f5af65ff

// 0x001b4420 FUN_001b4420 (35 B): matches/0x001b4420.cpp
// sym: ?FUN_001b4420@C_1b4420@owners@@QAEHH@Z
int owners::C_1b4420::FUN_001b4420(int key) {
    int result = 0;
    int* p = (int*)((char*)this + 0x4fc);
    for (int i = 0; i < 0x13; i++, p++)
        if (p[0x13] == key)
            result = p[0];
    return result;
}

namespace fn_f5af65ff {

// 0x001b4450 FUN_001b4450 (226 B): equivalent/0x001b4450.cpp
// sym: ?target@Controller_1b4450@fn_f5af65ff@@QAE_NPAUSubject_1b4450@2@_N@Z @389dcea9d9a5 @wceb9ebc04026
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_001b4450 @ 0x001b4450
bool Controller_1b4450::target(Subject_1b4450* subject, bool force) {
 if (!force && subject->FUN_001d64c0()) return false;
 Record_1b4450* record = ((Record_1b4450 *)((owners::C_1d72e0 *)subject)->FUN_001d72e0());
 if (!record || !record->payload) return false;
 Payload_1b4450* p = record->payload;
 record->owner = subject;
 p->firstLow = (*(uint*)&DAT_004c39e8);
 p->firstHigh = (*(uint*)((char*)&DAT_004c39e8 + 4));
 p->combinedLow = (*(uint*)&DAT_004c3a20) | (*(uint*)&DAT_004c3a10) | (*(uint*)&DAT_004c39f8) | (*(uint*)&DAT_004c39e8) | (*(uint*)&DAT_004c3a08) | (*(uint*)&DAT_004c3a18) | (*(uint*)&DAT_004c39f0);
 p->combinedHigh = (*(uint*)((char*)&DAT_004c3a20 + 4)) | (*(uint*)((char*)&DAT_004c3a10 + 4)) | (*(uint*)((char*)&DAT_004c39f8 + 4)) | (*(uint*)((char*)&DAT_004c39e8 + 4)) | (*(uint*)&DAT_004c3a0c) | (*(uint*)((char*)&DAT_004c3a18 + 4)) | (*(uint*)((char*)&DAT_004c39f0 + 4));
 Payload_1b4450* finalPayload = record->payload;
 record->kind = 5;
 ((owners::Obj_2ee6b0 *)sink)->FUN_002ee6b0((hulk_intptr)(Payload_1b4450 *)finalPayload);
 subject->flag = 0;
 return true;
}


// 0x001b4540 FUN_001b4540 (217 B): equivalent/0x001b4540.cpp
// sym: ?FUN_001b4540@Target_1b4540@fn_f5af65ff@@QAE_NPAUArgument_1b4540@2@@Z @f74adc8f8978 @w7ceecf5d4ce5
// STATUS: equivalent (tools/equiv.py level 3: 2034 inputs, branch coverage 18/18)
// FUN_001b4540 @ 0x001b4540
bool Target_1b4540::FUN_001b4540(Argument_1b4540* arg) {
 if (!((Data_1b4540 *)((owners::C_1d72e0 *)arg)->FUN_001d72e0())) return false;
 void* resource = ((Data_1b4540 *)((owners::C_1d72e0 *)arg)->FUN_001d72e0())->resource;
 if (!resource) return false;
 if (enabled && container && FUN_002020a0(((Data_1b4540 *)((owners::C_1d72e0 *)arg)->FUN_001d72e0()))) {
  List_1b4540* list = container->list;
  int count = list->count;
  for (int i=0; i<count; ++i) {
   Item_1b4540* item = list->FUN_00024190(i);
   if (item) {
    Data_1b4540* owner = item->owner;
    if (owner == ((Data_1b4540 *)((owners::C_1d72e0 *)arg)->FUN_001d72e0())) item->FUN_00038c40();
   }
  }
 }
 receiver->FUN_002eecb0(resource);
 arg->flag = 1;
 return true;
}


// 0x001b46d0 FUN_001b46d0 (21 B): matches/0x001b46d0.cpp
// sym: ?Fn@Target@fn_f5af65ff@@QAEXHMM@Z
void Target::Fn(int a, float b, float c) {
    value = b;
    (*(OtherClass**)&DAT_00554c10)->Other_002ece90(a, b, c);
}


// 0x001b46f0 FUN_001b46f0 (94 B): equivalent/0x001b46f0.cpp
// sym: _FUN_001b46f0 @f6b1230d8e8a @wedf399fca036
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 11/11)
// FUN_001b46f0 @ 0x001b46f0
extern "C" char* __cdecl FUN_001b46f0(Node* node, unsigned int* output)
{
    if (!node) return 0;
    switch (node->type) {
    case 1: {
        Data* data = node->data;
        char* result = data->FUN_00036d00();
        *output = *data->value;
        return result;
    }
    case 5:
        FUN_00096d50(((char*)&DAT_004e21a0), 64, node->data->first, node->data->second);
        return ((char*)&DAT_004e21a0);
    case 6: return "projectile";
    case 7: return "civilian";
    default: return 0;
    }
}


// 0x001b4770 FUN_001b4770 (161 B): equivalent/0x001b4770.cpp
// sym: ?FUN_001b4770@fn_f5af65ff@@YGXPAUVec3_1b4770@1@PAUModel_1b4770@1@G@Z @54d3c4181adb @w0ea1d4bbe4e2
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_001b4770 @ 0x001b4770
// FUN_001b4770 @ 0x001b4770: centroid of one triangle of a mesh
void __stdcall FUN_001b4770(Vec3_1b4770 *out, Model_1b4770 *model, unsigned short index)
{
    Mesh_1b4770 *mesh = model->mesh;
    Triangle_1b4770 *t = &mesh->triangles[index];
    Vec3_1b4770 *a = &mesh->vertices[t->a];
    Vec3_1b4770 *b = &mesh->vertices[t->b];
    Vec3_1b4770 *c = &mesh->vertices[t->c];
    volatile float sumX = a->x + b->x + c->x;
    volatile float sumZ01 = a->z + b->z;
    Vec3_1b4770 r; // the original builds the result in a frame temporary and copies it, so out may alias the vertices
    r.x = sumX * 0.33333334f;
    r.y = (a->y + b->y + c->y) * 0.33333334f;
    r.z = (sumZ01 + c->z) * 0.33333334f;
    *out = r;
}


// 0x001b4890 FUN_001b4890 (5 B): matches/0x001b4890.cpp
// sym: ?FUN_001b4890@fn_f5af65ff@@YGHHHHH@Z
int __stdcall FUN_001b4890(int a, int b, int c, int d) {
    return 0;
}


// 0x001b4a50 FUN_001b4a50 (83 B): matches/0x001b4a50.cpp
// sym: ?reset@Obj@fn_f5af65ff@@QAEXXZ
void Obj::reset() {
    volatile Obj* v = this;
    v->x = 0;
    v->y = 0;
    v->z = 0;
    Ref* r = v->ref;
    if (r) {
        r->release();
        ref = 0;
    }
    other->clean_002eee00();
    Elem* p = (Elem*)((char*)this + 0x3b8);
    int n = 4;
    do {
        p->clear_001b3420();
        p = (Elem*)((char*)p - 0x138);
        --n;
    } while (n);
}


// 0x001b4ab0 FUN_001b4ab0 (397 B): equivalent/0x001b4ab0.cpp
// sym: ?FUN_001b4ab0@Caster_1b4ab0@fn_f5af65ff@@QAE_NPAUV3_1b4ab0@2@000PAD1@Z @40dd2e3092c8 @w9ffa7464b31b
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 16/16)
// FUN_001b4ab0 @ 0x001b4ab0
bool Caster_1b4ab0::FUN_001b4ab0(V3_1b4ab0 *from, V3_1b4ab0 *to, V3_1b4ab0 *outA, V3_1b4ab0 *outB, char *flag, char *done)
{
    outA->x = 0.0f; outA->y = 0.0f; outA->z = 0.0f;
    outB->x = 0.0f; outB->y = 0.0f; outB->z = 0.0f;
    *flag = 1;
    *done = 0;
    HitList_1b4ab0 *list = FUN_00202f00();
    DAT_004d2a3c = 2;
    (*(char*)&DAT_00554c1c) = 0;
    DAT_00554c18 = 0;
    if (probe->FUN_00201e00(from, to, 1, outA, outB, 0, 0)) {
        *flag = 0;
        return false;
    }
    if (world->FUN_002ee140(list, from, to, 0)) {
        for (int i = 0; i < list->count; i++) {
            Node *n = list->hits[i].node;
            if (!n || !n->info)
                continue;
            int k = n->info->kind;
            if (k == 1) {
                *flag = 0;
            } else if (k == 5) {
                int tmpv = 0;
                FUN_002f1ce0(from, list->hits[i].value, outB, &tmpv);
                V3_1b4ab0 d;
                d.x = to->x - from->x;
                d.y = to->y - from->y;
                d.z = to->z - from->z;
                d.FUN_0022d110();
                float s = list->hits[i].scale;
                outA->x = d.x * s + from->x;
                outA->y = d.y * s + from->y;
                outA->z = d.z * s + from->z;
                *flag = 0;
                return false;
            }
        }
    }
    return true;
}


// 0x001b4c40 FUN_001b4c40 (134 B): equivalent/0x001b4c40.cpp
// sym: ?FUN_001b4c40@RefHolder@fn_f5af65ff@@QAEXPAVRef_1b4c40@2@@Z @4e486aced508 @wffd9e98ab96c
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// FUN_001b4c40 @ 0x001b4c40
void RefHolder::FUN_001b4c40(Ref_1b4c40 *newTarget)
{
    Ref_1b4c40 *old = target;
    if (newTarget == old)
        return;
    Ref_1b4c40 *detached = 0;
    if (old) {
        old->AddRef();
        FUN_001b4140(old);
        detached = old;
        if (target) {
            target->Release();
            target = 0;
        }
    }
    if (newTarget) {
        FUN_001b4140(newTarget);
        if (newTarget)
            newTarget->AddRef();
    }
    if (target)
        target->Release();
    target = newTarget;
    if (newTarget)
        FUN_001b4060(newTarget);
    if (detached) {
        FUN_001b4060(detached);
        detached->Release();
    }
}


// 0x001b4cd0 FUN_001b4cd0 (42 B): matches/0x001b4cd0.cpp
// sym: ?FUN_001b4cd0@Actor@fn_f5af65ff@@QAEXUTriple@2@H@Z
void Actor::FUN_001b4cd0(Triple value, int fourth) {
    FUN_001b4620(value, fourth, 0, 0);
}


// 0x001b55c0 FUN_001b55c0 (142 B): matches/0x001b55c0.cpp
// sym: ?Func@Base_1b55c0@fn_f5af65ff@@QAEXPAVOwner_1b55c0@2@H@Z
void Base_1b55c0::Func(Owner_1b55c0* obj, int value) {
    obj->value = value;
    int n = (unsigned short)*(unsigned short*)((char*)obj->data + 0x20);
    for (int i = 0; i < n; ++i) {
        Entry_1b55c0* e = (Entry_1b55c0*)(*(hulk_intptr*)((char*)obj->data + 0x18) + (unsigned short)i * 0x18);
        if (e->a != -1)
            e->a = (value << 16) | e->a;
        if (e->b != -1)
            e->b = (value << 16) | e->b;
        if (e->c != -1)
            e->c = (value << 16) | e->c;
    }
    count += n;
    int* p = items + value;
    obj->Fn();
    if (*p) {
        ((Dummy_1b55c0*)*(hulk_intptr*)p)->y();
    }
    *(hulk_intptr*)p = (hulk_intptr)obj;
}


// 0x001b5680 FUN_001b5680 (29 B): matches/0x001b5680.cpp
// sym: ?Get@List@fn_f5af65ff@@QAEPAXI@Z
void* List::Get(unsigned i) {
    if (i < (unsigned)(last - first))
        return first[i];
    return 0;
}


// 0x001b56a0 FUN_001b56a0 (67 B): matches/0x001b56a0.cpp
// sym: ?Lookup@Owner_1b56a0@fn_f5af65ff@@QAEPAUResult_1b56a0@2@HH@Z
// data: gFallback_1b56a0 = DAT_004e2160
Result_1b56a0* Owner_1b56a0::Lookup(int key, int index) {
    Entry_1b56a0* e = entries[(key >> 16) & 0xffff];
    if (e) {
        Node* n = e->node;
        ushort low = (ushort)key;
        ushort v = *(ushort*)((char*)n->records + 0x10 + (index + low * 12) * 2);
        return (Result_1b56a0*)((char*)n->items + v * 12);
    }
    return (Result_1b56a0*)&(*(char*)((char*)&DAT_004e215c + 4));
}

} // namespace fn_f5af65ff

// 0x001b5760 FUN_001b5760 (49 B): matches/0x001b5760.cpp
// sym: ?FUN_001b5760@Table_1b5760@owners@@QAEPAXI@Z
// data: gFallback_1b5760 = DAT_004e216c
void* owners::Table_1b5760::FUN_001b5760(unsigned int key) {
    Item_1b5760* item = (Item_1b5760*)slots[(((int)key >> 16) & 0xffff)];
    if (item) {
        unsigned short lo = (unsigned short)key;
        return (char*)(*(void**)((char*)item->p + 0x18)) + lo * 24;
    }
    return ((char*)((char*)&DAT_004e215c + 16));
}

namespace fn_f5af65ff {

// 0x001b57a0 FUN_001b57a0 (89 B): matches/0x001b57a0.cpp
// sym: ?Get@Manager_1b57a0@fn_f5af65ff@@QAEPAUEntry_1b57a0@2@H@Z
Entry_1b57a0* Manager_1b57a0::Get(int id) {
    if (id == -1)
        return 0;
    int hi = (id >> 16) & 0xffff;
    if (hi >= 0 && hi < end - begin) {
        Obj_1b57a0* p = begin[hi];
        if (p) {
            int lo = id & 0xffff;
            if (lo >= 0) {
                Item_1b57a0* item = p->item;
                if (lo < item->count)
                    return &item->entries[(unsigned short)lo];
            }
        }
    }
    return 0;
}


// 0x001b5800 FUN_001b5800 (89 B): matches/0x001b5800.cpp
// sym: ?Get@Vec_1b5800@fn_f5af65ff@@QAEPAUEntry_1b5800@2@H@Z
Entry_1b5800* Vec_1b5800::Get(int id) {
    if (id == -1)
        return 0;
    int hi = (id >> 16) & 0xffff;
    if (hi >= 0 && hi < end - begin) {
        Item_1b5800* p = begin[hi];
        if (p) {
            int lo = id & 0xffff;
            if (lo >= 0 && lo < p->sub->count)
                return &p->sub->entries[(unsigned short)lo];
        }
    }
    return 0;
}


// 0x001b5860 FUN_001b5860 (183 B): equivalent/0x001b5860.cpp
// sym: ?FUN_001b5860@Manager_1b5860@fn_f5af65ff@@QAEPAUVec_1b5860@2@PAU32@I@Z @f73dfc4c9770 @w5e5b2fe2c93b
// STATUS: equivalent (tools/equiv.py level 3: 19999 inputs, branch coverage 6/6)
// FUN_001b5860 @ 0x001b5860
Vec_1b5860* Manager_1b5860::FUN_001b5860(Vec_1b5860* out,unsigned int id) {
 Object* obj=objects[id >> 16];
 const Vec_1b5860 *a=((Vec_1b5860*)((char*)&DAT_004e215c + 4)),*b=((Vec_1b5860*)((char*)&DAT_004e215c + 4)),*c=((Vec_1b5860*)((char*)&DAT_004e215c + 4));
 if(obj) { Mesh_1b5860* m=obj->mesh; Face_1b5860* f=&m->faces[id & 65535]; a=&m->vertices[f->a]; b=&m->vertices[f->b]; c=&m->vertices[f->c]; }
 Plane_1b5860 plane; plane.FUN_0022dfe0(a,b,c);
 out->x=plane.n.x; out->y=plane.n.y; out->z=plane.n.z;
 return out;
}


// 0x001b5a20 FUN_001b5a20 (241 B): equivalent/0x001b5a20.cpp
// sym: ?FUN_001b5a20@Table_1b5a20@fn_f5af65ff@@QAEPAUVec3_1b5a20@2@PAU32@I@Z @85498a7f128a @wb946948fd1e3
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001b5a20 @ 0x001b5a20
Vec3_1b5a20* Table_1b5a20::FUN_001b5a20(Vec3_1b5a20* output, unsigned int id) {
 Entry_1b5a20* entry = entries[id >> 16];
 Vec3_1b5a20 *a, *b, *c;
 if (entry) {
  Mesh_1b5a20* mesh=entry->mesh;
  Triangle_1b5a20* tri=&mesh->triangles[id & 65535];
  a=&mesh->vertices[tri->a]; b=&mesh->vertices[tri->b]; c=&mesh->vertices[tri->c];
 } else { a=b=c=((Vec3_1b5a20*)((char*)&DAT_004e215c + 4)); }
 volatile float zpair=b->z+a->z;
 volatile float xsum=b->x+a->x+c->x;
 double ysum=(double)b->y+a->y+c->y;
 double zsum=(double)zpair+c->z;
 output->x=xsum*0.333333333333333333f;
 output->y=(float)(ysum*0.333333333333333333f);
 output->z=(float)(zsum*0.333333333333333333f);
 return output;
}


// 0x001b5bc0 FUN_001b5bc0 (89 B): matches/0x001b5bc0.cpp
// sym: ??0Method3_1b5bc0@fn_f5af65ff@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
// data: str1_1b5bc0 = DAT_0048e100, str2 = DAT_0048e128
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
Method3_1b5bc0::Method3_1b5bc0(const char* a, ScriptMemberFn b) {
    ((This_FUN_001d0480*)this)->FUN_001d0480(a, 3);
    vtable = ((hulk_intptr)DAT_0041da1c);
    value1c = b;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
}

} // namespace fn_f5af65ff

// 0x001b5c20 Method3<CCollisionManager,void,float,float,float>::vfunc_0 (30 B): matches/0x001b5c20.cpp
// sym: ??_G?$Method3@VCCollisionManager@@XMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CCollisionManager, void, float, float, float>::~Method3() {}


// 0x001b5c40 Method3<CCollisionManager,void,float,float,float>::vfunc_2 (35 B): matches/0x001b5c40.cpp
// sym: ?vfunc_2@?$Method3@VCCollisionManager@@XMMM@@UAEXPAX00@Z
template <> void Method3<CCollisionManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CCollisionManager_1b5c40 * obj = (CCollisionManager_1b5c40 *)__p0; float * args = (float *)__p1; hulk_intptr unused = (hulk_intptr)__p2;

    float* p = args;
    *(volatile int*)&args = *(int*)p;
    (obj->*(*(void (CCollisionManager_1b5c40::**)(float, float, float))&this->f_1c))(*(float*)&args, p[1], p[2]);
}
#if defined(HULK_PTR64)
template class Method3<CCollisionManager, void, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b5c20)
#endif


// 0x001b5cc0 Method2<CCollisionManager,bool,math::Vector,int>::vfunc_0 (30 B): matches/0x001b5cc0.cpp
// sym: ??_G?$Method2@VCCollisionManager@@_NVVector@math@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CCollisionManager, bool,math::Vector, int>::~Method2() {}


// 0x001b5ce0 Method2<CCollisionManager,bool,math::Vector,int>::vfunc_2 (53 B): matches/0x001b5ce0.cpp
// sym: ?vfunc_2@?$Method2@VCCollisionManager@@_NVVector@math@@H@@UAEXPAX00@Z
template <> void Method2<CCollisionManager, bool,math::Vector, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { Callee_1b5ce0 * a = (Callee_1b5ce0 *)__p0; VecI * p = (VecI *)__p1; char * out = (char *)__p2;

    Fn_1b5ce0 f = (*(Fn_1b5ce0 *)&this->f_1c);
    bool r = (a->*f)(*(Vec_1b5ce0*)p, p->i);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method2<CCollisionManager, bool,math::Vector, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b5cc0)
#endif

namespace fn_f5af65ff {

// 0x001b5d20 FUN_001b5d20 (122 B): equivalent/0x001b5d20.cpp
// sym: ?FUN_001b5d20@NodeList_1b5d20@fn_f5af65ff@@QAEXGH@Z @780b2f676c63 @w4c3e4cd617eb
// STATUS: equivalent (tools/equiv.py level 3: 270 inputs, branch coverage 8/8)
// FUN_001b5d20 @ 0x001b5d20
void NodeList_1b5d20::FUN_001b5d20(unsigned short index, int tag) {
    Node* node = 0;
    if ((unsigned int)index < (unsigned int)(end - begin))
        node = begin[index];
    for (unsigned int i = 0; i < node->table->count; i++) {
        Record_1b5d20* r = &node->table->records[(unsigned short)i];
        unsigned short f = r->flags;
        unsigned short low = f >> 3;
        if ((int)((unsigned int)low >> 10 & 7) == tag)
            r->flags = (unsigned short)(((low & 0x3ff) << 3) | (f & 7));
    }
}


// 0x001b5ec0 FUN_001b5ec0 (148 B): matches/0x001b5ec0.cpp
// sym: ?Add@Holder_1b5ec0@fn_f5af65ff@@QAE_NPAUObj_1b5ec0@2@H@Z
bool Holder_1b5ec0::Add(Obj_1b5ec0* o, int v) {
    int i = 0;
    do {
        if (slots[i] == 0) {
            if (o)
                o->AddRef();
            if (slots[i])
                slots[i]->Release();
            slots[i] = o;
            vals[i] = v;
            ctx->Reg_002ee6d0(o);
            o = (Obj_1b5ec0*)o->h;
            void* c = __RTDynamicCast((void*)((hulk_intptr)o), 0, (void*)(hulk_at_004c38f8), (void*)(hulk_at_004c3920), 0);
            if (c)
                mesh.Set_001b55c0(c, v);
            return true;
        }
        i++;
    } while (i < 19);
    return false;
}


// 0x001b5f60 FUN_001b5f60 (145 B): equivalent/0x001b5f60.cpp
// sym: ?FUN_001b5f60@SoundBank@fn_f5af65ff@@QAE_NH@Z @172048860707 @w80473ba84ba4
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 10/10)
// FUN_001b5f60 @ 0x001b5f60
// equiv-map: ?thunk_FUN_002ee510@Cache@@QAEXPAUVoice@@@Z = 0x002ee700
bool SoundBank::FUN_001b5f60(int id)
{
    int i = 0;
    while (voiceIds[i] != id) {
        i++;
        if (i >= 19)
            return false;
    }

    cache->thunk_FUN_002ee510(voices[i]);
    voiceIds[i] = -1;
    if (voices[i] != 0) {
        voices[i]->Release();
        voices[i] = 0;
    }

    Sound_1b5f60 **slot = &sounds[id];
    if (*slot != 0)
        totalSize -= (*slot)->data->size;
    if (*slot != 0) {
        (*slot)->Release();
        *slot = 0;
    }
    return true;
}

} // namespace fn_f5af65ff

// 0x001b6000 FUN_001b6000 (347 B): equivalent/0x001b6000.cpp
// sym: ?FUN_001b6000@Tracker_1b6000@owners@@QAEDHPAPAPAXPAH@Z @2501278cd97e @w034b1ac5e413
// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 16/18, incomplete)
// FUN_001b6000 @ 0x001b6000
char owners::Tracker_1b6000::FUN_001b6000(int id, void ***outList, int *outId)
{
    Registry_1b6000 *reg = (*(Registry_1b6000**)&DAT_00554c14);
    if (!reg->FUN_002edb90(id, 10))
        return 0;
    Rec_1b6000 *begin = reg->begin;
    hulk_intptr n = reg->end - begin;
    unsigned int i;
    for (i = 0; i < (unsigned int)n; i++) {
        Rec_1b6000 *r = &reg->begin[i];
        if (!(r->w < 0.0f)) {
            void *item;
            r->FUN_002f8e10(&item, &id);
            Rec_1b6000 *r2 = &reg->begin[i];
            if (!((r2->z * 0.0f + r2->y * (*(float*)&DAT_003f3388)) + r2->x * 0.0f > 0.0f)) {
                void ***list = (void ***)&itemsBegin;
                unsigned int idx = 0;
                if ((int)(((char *)itemsEnd - (char *)itemsBegin) & 0xfffffffc) > 0) {
                    for (;;) {
                        hulk_uintptr cnt = itemsEnd - itemsBegin;
                        void *e = idx < cnt ? itemsBegin[idx] : 0;
                        if (e == item) {
                            id |= idx << 16;
                            break;
                        }
                        idx++;
                        if ((int)idx >= (int)(itemsEnd - itemsBegin))
                            break;
                    }
                }
                *outList = (void **)&itemsBegin;
                *outId = id;
                return 1;
            }
        }
    }
    return 0;
}


// 0x001b61c0 Closure3<CCollisionManager,void,float,float,float>::vfunc_2 (34 B): matches/0x001b61c0.cpp
// sym: ?vfunc_2@?$Closure3@VCCollisionManager@@XMMM@@UAEXPAX00@Z
template <> void Closure3<CCollisionManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { float * p = (float *)__p1;

    float* q = p;
    *(volatile int*)&p = *(int*)q;
    ((*(CCollisionManager_1b61c0 * *)&this->f_20)->*(*(void (CCollisionManager_1b61c0::**)(float, float, float))&this->f_1c))(*(float*)&p, q[1], q[2]);
}


// 0x001b61f0 FUN_001b61f0 (89 B): matches/0x001b61f0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001b61f0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001b61f0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
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


extern void* hulk_at_0041da2c[2];
extern void* hulk_at_0041da60[2];
extern void* TAB_48e0f0;

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_0041da2c;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e0e4));
    f.argTypes[0] = FUN_001d04d0(&TAB_48e0f0);
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_0041da60;
    owner = a2;
}
} // namespace fn_001b61f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b6270 Closure2<CCollisionManager,bool,math::Vector,int>::vfunc_2 (56 B): matches/0x001b6270.cpp [wrapped: conflict: CCollisionManager; Closure2; Function]
// sym: ?vfunc_2@Closure2@fn_001b6270@@UAEXPAX00@Z
namespace fn_001b6270 {
namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class CCollisionManager {
  public:
    bool fn(math::Vector, int);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, void*);
};
class Closure2 : public Function {
  public:
    char pad[0x18];
    typedef bool (CCollisionManager::*Method)(math::Vector, int);
    Method method;
    CCollisionManager* obj;
    virtual void vfunc_2(void*, void*, void*);
};
void Closure2::vfunc_2(void* unused, void* input, void* output) {
    CCollisionManager* target = obj;
    Method fn = method;
    math::Vector* v = (math::Vector*)input;
    bool r = (target->*fn)(*v, ((int*)input)[3]);
    if (output)
        *(bool*)output = r;
}
} // namespace fn_001b6270

namespace fn_f5af65ff {

// 0x001b62d0 FUN_001b62d0 (83 B): equivalent/0x001b62d0.cpp
// sym: ?FUN_001b62d0@Registry_1b62d0@fn_f5af65ff@@QAEXPBDPAVCCollisionManager_1b62d0@2@P832@AEXMMM@Z@Z @c39f01137cb0 @w94b621308c23
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001b62d0 @ 0x001b62d0
// FUN_001b62d0 @ 0x001b62d0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1b62d0::FUN_001b62d0(const char* a1, CCollisionManager_1b62d0* a2, Fn_1b62d0 a3) {
    typedef Closure3_1b62d0<CCollisionManager_1b62d0, void, float, float, float> Alloc_1b62d0;
    HULK_SIZE32(Alloc_1b62d0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1b62d0));
    void* x = 0;
    if (m) {
        ((Raw_1b62d0*)m)->FUN_001b5bc0(a1, a3);
        x = new (m) Closure3_1b62d0<CCollisionManager_1b62d0, void, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001b6380 FUN_001b6380 (152 B): matches/0x001b6380.cpp
// sym: ??0Arena_1b6380@fn_f5af65ff@@QAE@XZ
Arena_1b6380::Arena_1b6380() {
    mStart = 0;
    mFree = 0;
    mEnd = 0;
    unsigned int* p = (unsigned int*)Alloc(0x1000);
    mStart = p;
    if (p) {
        mFree = p;
        mEnd = (unsigned int*)((char*)p + 0x1000);
    } else {
        mFree = 0;
        mEnd = 0;
    }
    register int n = 0x100;
    do {
        unsigned int* q = mFree;
        if (q < mEnd) {
            mFree = q + 1;
            if (q)
                *q = 0;
        }
        q = mFree;
        if (q < mEnd) {
            mFree = q + 1;
            if (q)
                *q = 0;
        }
        q = mFree;
        if (q < mEnd) {
            mFree = q + 1;
            if (q)
                *q = 0;
        }
        q = mFree;
        if (q < mEnd) {
            mFree = q + 1;
            if (q)
                *q = 0;
        }
    } while (--n);
}

} // namespace fn_f5af65ff

// 0x001b6440 FUN_001b6440 (225 B): equivalent/0x001b6440.cpp [wrapped: conflict: CCollisionManager; FUN_001d4c90]
// sym: ??0CCollisionManager@fn_001b6440@@QAE@XZ @ff01b76818e4 @w012b5a3c1b01
namespace fn_001b6440 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001b6440 @ 0x001b6440

struct Part_1b6440 { char data[0x138]; void FUN_001b3020(); };
struct Tail_1b6440 { char data[0x14]; void FUN_001b6380(); };
struct CCollisionManager;
typedef void (__cdecl *Callback_1b6440)();
void __cdecl FUN_001b46d0();
void __cdecl FUN_001b4cd0();
struct Closure2_1b6440 { Closure2_1b6440* FUN_001b61f0(const char*, CCollisionManager*, Callback_1b6440); };
struct Registry_1b6440 { void FUN_001b62d0(const char*, CCollisionManager*, Callback_1b6440); void FUN_001d3b70(const char*,Closure2_1b6440*); };
Registry_1b6440* __cdecl FUN_001d4c90();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Physics_1b6440 { void FUN_002ece90(int,float,int); };
struct CCollisionManager {
 virtual void slot0_00018b30();
 int a,b,c;
 Part_1b6440 parts[4];
 int d,e,f;
 int counters[19];
 int ids[19];
 Tail_1b6440 tail;
 float gravity;
 CCollisionManager();
};
CCollisionManager::CCollisionManager() {
 a=0;b=0;c=0;
 for(int i=0;i<4;++i) parts[i].FUN_001b3020();
 d=0;e=0;f=0;
 tail.FUN_001b6380();
 gravity=-3000.0f;
 Registry_1b6440* registry=FUN_001d4c90();
 if(registry) {
 registry->FUN_001b62d0("cm_SetGravity",this,FUN_001b46d0);
 Closure2_1b6440* command=(Closure2_1b6440*)FUN_0008d690(0x24);
 if(command) command=command->FUN_001b61f0("cm_AddExplosion",this,FUN_001b4cd0);
 registry->FUN_001d3b70("cm_AddExplosion",command);
 for(int j=0;j<19;++j) { counters[j]=0; ids[j]=-1; }
 (*(Physics_1b6440**)&DAT_00554c10)->FUN_002ece90(0,gravity,0);
 }
}
} // namespace fn_001b6440

namespace fn_f5af65ff {

// 0x001b6530 FUN_001b6530 (74 B): matches/0x001b6530.cpp
// sym: ??1CCollisionManager_1b6530@fn_f5af65ff@@QAE@XZ
CCollisionManager_1b6530::~CCollisionManager_1b6530() {
    *(void* volatile*)&vptr = hulk_at_0041da90;

    void* t = *(void* volatile*)&m594;
    m598 = t;
    if (t)
        operator delete(t);
    Elem_1b6530* p = arr + 4;
    int i = 4;
    do {
        p--;
        p->Fini_001b39f0();
        i--;
    } while (i);
    vptr = hulk_at_003f6098;
}


// 0x001b6580 FUN_001b6580 (69 B): matches/0x001b6580.cpp
// sym: _FUN_001b6580
// data: gThing = DAT_004e2158
extern "C" void * FUN_001b6580() {
    if (!(*(CCollisionManager_1b6580**)&DAT_004e2158)) {
        (*(CCollisionManager_1b6580**)&DAT_004e2158) = new CCollisionManager_1b6580;
        (*(CCollisionManager_1b6580**)&DAT_004e2158)->Init();
        return (CCollisionManager_1b6580 *)((*(CCollisionManager_1b6580**)&DAT_004e2158));
    }
    return (CCollisionManager_1b6580 *)((*(CCollisionManager_1b6580**)&DAT_004e2158));
}

} // namespace fn_f5af65ff

// 0x001b65d0 CCollisionManager::vfunc_2 (30 B): matches/0x001b65d0.cpp
// sym: ??_GCCollisionManager@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CCollisionManager::~CCollisionManager() {}

namespace fn_f5af65ff {

// 0x001b65f0 FUN_001b65f0 (461 B): equivalent/0x001b65f0.cpp
// sym: ?FUN_001b65f0@Mgr_1b65f0@fn_f5af65ff@@QAEDHH@Z @9822544be5eb @w08700e1bb369
// STATUS: equivalent (tools/equiv.py level 3: 19439 inputs, branch coverage 12/12)
// FUN_001b65f0 @ 0x001b65f0
char Mgr_1b65f0::FUN_001b65f0(int id, int slot)
{
    MeshObj *obj = objs[(id >> 16) & 0xffff];
    const Vec3_1b65f0 *p1;
    const Vec3_1b65f0 *p2;
    if (obj) {
        MeshData_1b65f0 *d = obj->data;
        p1 = &d->verts[d->indices->idx[slot + 12 * (unsigned short)id]];
    } else {
        p1 = ((Vec3_1b65f0*)((char*)&DAT_004e215c + 4));
    }
    if (obj) {
        int s2 = ((signed char*)&DAT_0041da9c)[slot];
        MeshData_1b65f0 *d = obj->data;
        p2 = &d->verts[d->indices->idx[s2 + 12 * (unsigned short)id]];
    } else {
        p2 = ((Vec3_1b65f0*)((char*)&DAT_004e215c + 4));
    }

    float sx = p2->x + p1->x;
    float sy = p2->y + p1->y;
    volatile float sz = p1->z + p2->z;
    // mx, my, mz are rounded frame copies in the original
    volatile float mx = sx * 0.5f;
    volatile float my = sy * 0.5f;
    volatile float mz = sz * 0.5f;

    Vec3_1b65f0 d;
    d.x = p1->x - p2->x;
    d.y = p1->y - p2->y;
    d.z = p1->z - p2->z;

    Vec3_1b65f0 out;
    out.z = sz;  // the original's out buffer shares its last slot with the sum
    FUN_001b5860(&out, id);

    Vec3_1b65f0 r;
    r.x = out.y * d.z - out.z * d.y;
    r.y = out.z * d.x - d.z * out.x;
    r.z = d.y * out.x - out.y * d.x;
    r.FUN_0022d110();
    r.x = r.x + mx;
    r.y = r.y + my;
    r.z = r.z + mz;

    if ((*(Locator**)&DAT_004e2158) == 0) {
        void *mem = FUN_0008d690((int)sizeof(Locator));
        Locator *loc = 0;
        if (mem)
            loc = new (mem) Locator();
        (*(Locator**)&DAT_004e2158) = loc;
        loc->v0();
    }
    int origId = id;
    int origSlot = slot;
    if (!(*(Locator**)&DAT_004e2158)->FUN_001b6000(&r, &slot, &id))
        return 0;
    int *table = FUN_001b5800(origId);
    if (!table)
        return 0;
    table[origSlot] = id;
    return 1;
}

} // namespace fn_f5af65ff
