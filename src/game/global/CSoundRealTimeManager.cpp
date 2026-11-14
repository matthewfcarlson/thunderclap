// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001eab10..0x001eecb0 (kind game, layer game, confidence high), dominant class CSoundRealTimeManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f014178b {
#define TREE_TU_END }
namespace fn_f014178b {} using namespace fn_f014178b;
#include "game/global.h"
#include "decls/managers.h"

// ---- declarations shared by the functions below
namespace fn_f014178b {
struct Entry_1eadf0 {
    int state;
    char pad[12];
    int blocked;
    void FUN_001ea700();
};
struct Manager_1eadf0 {
    bool FUN_00266750();
    void FUN_00263e90();
};
struct Object {
  public:
    char _m_pad_0[0x29];
    unsigned char active;
    char _m_pad_2a[0x2];
    Entry_1eadf0* entries[64];
    int count;
    bool FUN_001eadf0();
    const char* FUN_000443b0();
};
struct Ref_1eaea0 {
    char pad0[0xc];
    int refs;
};
struct Slot_1eaea0 {
    virtual void v0();
    virtual void v1();
    virtual void Destroy(int flag);
    char pad04[0x24 - 4];
    int users;
    char pad28[0x2c - 0x28];
    Ref_1eaea0 *refs[64];
    int refCount;
    void FUN_001eadf0();
};
struct Handle_1eaea0 {
    int state;
    void FUN_001ea700();
};
struct Timer {
    char pad0[0x34];
    int pending;
};
struct Job_1eaea0 {
    virtual void v0();
    virtual void v1();
    virtual void Destroy(int flag);
    char pad04[0xc - 4];
    Timer *timer;
};
struct Sync {
    char FUN_00266750();
    void FUN_00263e90();
};
struct Pool_1eaea0 {
    void FUN_002665a0();
};
extern "C" void FUN_00241280(int a, int b, int c);
extern "C" void *FUN_00240750();
extern "C" void FUN_002416c0(void *a, Timer *t, int c);
extern "C" void FUN_00243090(void *a, float step);
void FUN_00242ca0(void *a, Timer **t);
class Manager_1eaea0 {
public:
    char pad0[8];
    Slot_1eaea0 *slots[100];
    int slotCount;
    Handle_1eaea0 *handles[200];
    int handleCount;
    Job_1eaea0 *jobs[20];
    int jobCount;
    int f514;
    Pool_1eaea0 *pool;
    char pad51c[4];
    char f520;

    void FUN_001eaea0();
};
struct Resource_1eb220 {
    void* FUN_001f1270();
};
extern "C" Resource_1eb220* __cdecl FUN_0008d710(int size, int category);
class Other_1eb2a0 {
  public:
    void target_001f22f0(int, int);
};
struct StringList_1eb440 {
    char data[0x48];
    void FUN_001ef370(const char *s);
};
struct NameSource_1eb440 {
    const char *FUN_0008a2d0();
};
class Inner_1eb4d0 {
  public:
};
class Outer_1eb4d0 {
  public:
    Inner_1eb4d0* p;
    void g();
};
class Inner {
  public:
    void FUN_001f46a0();
    void Set_001e8a50(int);
};
struct Outer { Inner* inner; void FUN_001ef9c0(int); };
struct Thing {
    Outer* outer;
    char padding[4];
    unsigned char active;
    unsigned char flagged;
    void FUN_001eb4f0(int unused);
};
class Inner_1eb550 {
  public:
    void FnA_001f3930();
};
class X_1eb550 {
  public:
    Inner_1eb550** p;
    void Target();
};
struct Temp_1eb560 {
    char pad[0x48];
    void SetName_001ef370(const char*);
};
struct Obj_1eb560 {};
struct Owner_1eb560 {
};
struct Renderer_1eb560 {
    void Draw_001efe20(Temp_1eb560*, int, int, float);
};
void Build_001eb440(Obj_1eb560*, Temp_1eb560*);
struct C_1eb560 {
    Renderer_1eb560* m0;
    Owner_1eb560* m4;
    char m8;
    void Fn(hulk_intptr);
};
struct String {
 char data[8];
 void FUN_0027af00();
 void FUN_0027af30(const String&);
 void FUN_0027af50();
};
struct List_1eb5e0 {
 char data[72];
 void FUN_001ef370(const char*);
 void FUN_001ef3c0(String);
};
struct Lookup_1eb5e0 {  };
struct Display_1eb5e0 { void FUN_001efe20(List_1eb5e0*, String*, unsigned int, float); };
void __cdecl FUN_001eb440(void*, List_1eb5e0*);
struct Target_1eb5e0 {
 Display_1eb5e0* display;
 Lookup_1eb5e0* lookup;
 unsigned char enabled;
 void run(const String& input, unsigned int value, const char* text);
};
class B_1eb6a0 {
  public:
    void FnG_001f6ba0();
};
class A_1eb6a0 {
  public:
    virtual void F();
};
class B_1eb6b0 {
  public:
    void FnG_001f3ad0();
};
class A_1eb6b0 {
  public:
    virtual void F();
};
struct Temp_1eb6c0 {
    char pad[0x48];
    void SetName_001ef370(const char*);
};
struct Obj_1eb6c0 {};
struct Owner_1eb6c0 {
};
struct Renderer_1eb6c0 {
    void Draw_001efe20(Temp_1eb6c0*, int, int, float);
};
void Build_001eb440(Obj_1eb6c0*, Temp_1eb6c0*);
struct C_1eb6c0 {
    Renderer_1eb6c0* m0;
    Owner_1eb6c0* m4;
    char m8;
    void Fn(hulk_intptr);
};
struct Vec3_1eb7e0 {
    float x, y, z;
};
struct Impl_1eb7e0 {
    void FUN_001f42d0(int a, int b, Vec3_1eb7e0 v3, Vec3_1eb7e0 v4, Vec3_1eb7e0 v5, Vec3_1eb7e0 v6, int last);
};
struct Handle_1eb7e0 {
    Impl_1eb7e0 *impl;
};
struct Owner_1eb7e0 {
    Handle_1eb7e0 *handle;
    void FUN_001eb7e0(int a, int b, const Vec3_1eb7e0 *p3, const Vec3_1eb7e0 *p4, const Vec3_1eb7e0 *p5,
                      float f6, float f7, float f8, int p9);
};
class B_1eb870 {
  public:
    void FnF_001f6580();
};
class A_1eb870 {
  public:
    void* v;
    char pad[4];
    char flag;
};
class B_1eb890 {
  public:
    void FnF_001f6650();
};
class A_1eb890 {
  public:
    void* v;
    char pad[4];
    char flag;
};
class Temp_1eb8d0 {
  public:
    char pad[0x48];
    void Add_001ef370(const char*);
};
class Manager_1eb8d0 {
  public:
};
class Root_1eb8d0 {
  public:
    void Run_001efe20(Temp_1eb8d0*, int, int, float);
};
class Owner_1eb8d0 {
  public:
    Root_1eb8d0* root;
    Manager_1eb8d0* manager;
    unsigned char flag;
    void Target(hulk_intptr);
};
extern void __cdecl FUN_001eb440(void*, Temp_1eb8d0*);
struct Temp_1eb950 {
    char data[0x48];
    void Add_001ef370(const char*);
};
struct Manager_1eb950 {
};
struct Obj_1eb950 {
    void Send_001efe20(Temp_1eb950*, int, float, float);
};
struct Owner_1eb950 {
    char pad[4];
    Manager_1eb950* mgr;
    char enabled;
    void Run(float);
};
void Use_001eb440(int*, Temp_1eb950*);
} // namespace fn_f014178b
namespace hulkfight { namespace ai {
class HulkActionTrack {
  public:
    char pad0[0xc];
    float mValue;

    float vfunc_6();
};
} }
namespace fn_f014178b {
struct Chain_1eb9e0 {
};
struct Wrap_1eb9e0 {
    Chain_1eb9e0* inner;
};
struct Obj_1eb9e0 {
    Wrap_1eb9e0* next;
    char pad[8];
    float value;
    void UpdateValue(float x);
};
struct Deep {
};
struct Inner_1eba30 {
    Deep* d;
};
struct Obj_1eba30 {
    Inner_1eba30* inner;
    char pad[12];
    float value;
    void set(float);
};
class Inner_1eba80 {
  public:
};
struct Holder_1eba80 {
    Inner_1eba80* obj;
};
class C_1eba80 {
  public:
    Holder_1eba80* holder;
    char pad[0x10];
    float value;
    void F(float x);
};
struct Provider {
    char pad[4];
    Inner* inner;
};
class Obj {
  public:
    Provider* provider;
    char pad[0x14];
    int value;
    void Set(int v);
};
struct S7 {
    char c[7];
};
struct S8_1ebaf0 {
    char c[8];
};
struct Obj_1ebaf0 {
    char d[12];
};
void Use_00240760(void*);
struct Path_1ebbc0 {
 char storage[72];
 void FUN_001ef370(const char*);
};
struct Actor_1ebbc0 { char pad[8]; char position[32]; unsigned flags; };
struct Context {  };
struct Audio_1ebbc0 { void FUN_001efe20(Path_1ebbc0*, void*, const char*, float); };
struct Manager_1ebbc0 { Audio_1ebbc0* audio; char pad[4]; unsigned char enabled; };
extern void __cdecl FUN_001eb440(void*, Path_1ebbc0*);
struct Owner_1ebbc0 {
 char pad[4]; Context* context;
 void target(Actor_1ebbc0*, const char*);
};
class Builder {
  public:
    void Add_001ef370(const char*);
};
class Runner_1ebc80 {
  public:
    void Run_001efe20(void*, void*, const char*, float);
};
class State_1ebc80 {
  public:
    Runner_1ebc80* runner;
    char pad[4];
    char enabled;
};
class Temp_1ebd00 {
  public:
    void Add_001ef370(const char*);
};
class Manager_1ebd00 {
  public:
    void Run_001efe20(char*, int, const char*, float);
};
struct Id_1ebd80 {
    unsigned __int64 key;
};
struct IdCopy_1ebd80 {
    unsigned __int64 key;
    void FUN_0027af30(const Id_1ebd80 *src);
    IdCopy_1ebd80(const Id_1ebd80 &o) { FUN_0027af30(&o); }
};
struct StringList_1ebd80 {
    char data[0x48];
    void FUN_001ef370(const char *s);
    void FUN_001ef3c0(IdCopy_1ebd80 id);
};
struct EventSink_1ebd80 {
    void *handler;
    bool FUN_001efe20(StringList_1ebd80 *args, const void *where, int name, float delay);
};
struct EventConfig_1ebd80 {
    EventSink_1ebd80 *sink;
    char pad04[4];
    char enabled;
};
struct Descriptor_1ebd80 {
    char pad00[8];
    Id_1ebd80 id;                  // 0x08
};
struct Prop_1ebd80 {
    char pad00[8];
    char where[1];          // 0x08
    char pad09[0xe3];
    Descriptor_1ebd80 *descriptor; // 0xec
};
struct StringList_1ebe10 {
    char data[0x48];
    void FUN_001ef370(const char *s);
    void FUN_001ef390(unsigned __int64 id);
};
struct EventSink_1ebe10 {
    void *handler;
    bool FUN_001efe20(StringList_1ebe10 *args, const void *where, int name, float delay);
};
struct EventConfig_1ebe10 {
    EventSink_1ebe10 *sink;
    char pad04[4];
    char enabled;
};
struct Registry_1ebe10 {
};
struct Source_1ebe10 {
    char pad00[0x5c];
    int key;
};
struct Owner_1ebe10 {
    char pad00[0x4c];
    Registry_1ebe10 *registry;
};
class Emitter_1ebe10 {
public:
    Owner_1ebe10 *owner;
    void Emit(Source_1ebe10 *source, const void *where, hulk_intptr name);
};
struct NameList_1ebfd0 {
    char data[0x48];
    void FUN_001ef370(const char *name);
};
struct Key_1ebfd0 {
    unsigned int lo;
    unsigned int hi;
};
struct Target_1ebfd0 {
    char pad00[8];
    Key_1ebfd0 key;
    char pad10[0x11c - 0x10];
    void *handle;
};
struct Dispatcher_1ebfd0 {
    void FUN_001efe20(NameList_1ebfd0 *names, Key_1ebfd0 *key, int a, float scale);
};
struct Registry_1ebfd0 {
    Dispatcher_1ebfd0 *dispatcher;
    char pad04[4];
    unsigned char enabled;
};
struct StringList_1ec060 {
    char data[0x48];
    void FUN_001ef370(const char *s);
};
struct EventSink_1ec060 {
    void *handler;
    bool FUN_001efe20(StringList_1ec060 *args, const void *where, int name, float delay);
};
struct EventConfig_1ec060 {
    EventSink_1ec060 *sink;        // 0
    char pad04[4];
    char enabled;           // 8
};
struct Slot_1ec060 {
    unsigned __int64 FUN_001d4f70();
};
struct Entity {
    char pad00[8];
    char pos[0xe4];         // 0x8: position block passed to the sink
    Slot_1ec060 *slot;             // 0xec
};
struct physics_CollisionRay_1ec0f0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(hulk_intptr a, hulk_intptr b);
    virtual void vfunc_6();
};
struct StringList_1ec3d0 {
    char data[0x44];
    void FUN_001ef370(const char *s);
};
struct Level_1ec3d0 {
};
struct Handler_1ec3d0 {
    void FUN_001f46a0();
};
struct EventSink_1ec3d0 {
    Handler_1ec3d0 *handler;
    bool FUN_001efe20(StringList_1ec3d0 *args, int zero, const char *name, float delay);
};
class LevelEnter {
public:
    void FUN_001ec3d0();

    EventSink_1ec3d0 *sink;
    Level_1ec3d0 *level;
    char active;
    char entered;
};
void FUN_001eb440(void *id, StringList_1ec3d0 *out);
struct Text_1ec980 {
    char storage[0x48];
    void FUN_001ef370(const char*);
};
struct Actor_1ec980 {
    char pad[8];
    char location[0x114];
    Object* object;
    char gap[8];
    void* alternate;
};
struct Service_1ec980 {
};
struct Output_1ec980 {
    void FUN_001efe20(Text_1ec980*, void*, int, float);
};
struct Global_1ec980 {
    Output_1ec980* output;
    char pad[4];
    unsigned char enabled;
};
struct Target_1ec980 {
    char pad[4];
    Service_1ec980* service;
    void FUN_001ebd80(void*, int, float, int);
    void FUN_001ec980(Actor_1ec980*, hulk_intptr);
};
class Part_1ecc80 {
  public:
    int Check_001d5040();
};
class Obj_1ecc80 {
  public:
    char pad[0xec];
    Part_1ecc80* component;
};
class Owner_1ecc80 {
  public:
    char pad[0x11c];
    Part_1ecc80* component;
};
class Thing_1ecc80 {
  public:
    char pad[0x1c];
    void Play_001ebd80(Obj_1ecc80*, const char*, float, int);
    void Fn(Owner_1ecc80*, Obj_1ecc80*, Obj_1ecc80*, hulk_intptr);
};
struct Vec3_1ecda0 {
    float x, y, z;
};
struct Id_1ecda0 {
    unsigned lo, hi;               // a 64-bit key, kept as two words so it is only 4-aligned
    void FUN_0027af00();
    void FUN_0027af50();
    void FUN_0027af60(unsigned __int64 value);
    void FUN_0027af70(const Id_1ecda0 *src);
    Id_1ecda0 *FUN_0027b0e0(const char *name);
};
struct IdCopy_1ecda0 {
    unsigned __int64 key;
    void FUN_0027af30(const Id_1ecda0 *src);
    IdCopy_1ecda0(const Id_1ecda0 &o) { FUN_0027af30(&o); }
};
static __forceinline bool SameKey_1ecda0(unsigned __int64 k, unsigned lo, unsigned hi)
{
    union { unsigned __int64 q; unsigned w[2]; } u;
    u.q = k;
    return u.w[0] == lo && u.w[1] == hi;
}
struct Node {
    char FUN_00059a50(Vec3_1ecda0 *out);
};
struct Info_1ecda0 {
    const char *FUN_000443b0();
    unsigned __int64 FUN_000443c0();
};
struct Actor_1ecda0 {
    char pad0[8];
    Id_1ecda0 id;                  // 0x08
    Node *node;             // 0x10
    char pad14[0x11c - 0x14];
    Info_1ecda0 *info;             // 0x11c
    char pad120[0x1b0c - 0x120];
    float weight;           // 0x1b0c
};
struct Query_1ecda0 {
    char data[0x44];
    void FUN_001ef370(const char *name);
    void FUN_001ef3c0(IdCopy_1ecda0 id);
};
struct Logic_1ecda0 {
    char pad0[0xc];
    int count;              // 0xc
    char pad10[0x124 - 0x10];
    Actor_1ecda0 *self;            // 0x124
    bool FUN_00027fc0(const char *a, const char *b);
    Actor_1ecda0 *FUN_00024190(int index);
};
struct Env_1ecda0 {
    char pad[0x20];
    Logic_1ecda0 *logic;           // 0x20
};
struct Flags_1ecda0 {
    bool FUN_00092de0(int v);
};
} // namespace fn_f014178b
struct Singleton_4dd6ec {
};
namespace fn_f014178b {
struct Lookup_1ecda0 {
};
struct Spawner_1ecda0 {
    void FUN_001efe20(Query_1ecda0 *q, Id_1ecda0 *id, const char *name, float radius);
};
struct SpawnGlobals_1ecda0 {
    Spawner_1ecda0 *spawner;       // 0x0
    char pad[4];
    char enabled;           // 0x8
};
void FUN_001eb440(void *target, Query_1ecda0 *q);
class Handler_1ecda0 {
public:
    Env_1ecda0 *env;               // 0x0
    Lookup_1ecda0 *lookup;         // 0x4
    void FUN_001ecda0(const char *a1, int a2, const char *a3, const char *a4);
};
struct __declspec(align(8)) Frame_1ecda0 {
    Id_1ecda0 id1;                 // 0x10
    union {
        Id_1ecda0 temp;
        Actor_1ecda0 *best;
    } tb;                          // 0x18
    Id_1ecda0 id2;                 // 0x20
    int pad28;
    Vec3_1ecda0 p1;                // 0x2c
    int i;                         // 0x38
    Handler_1ecda0 *self;          // 0x3c
    float bestDist;                // 0x40
    Vec3_1ecda0 p0;                // 0x44
    Query_1ecda0 q;                // 0x50
    int pad94;
};
struct Triple_1eda90 {
    int a, b, c;
};
struct Manager_1eda90 {
    void Run_001ec900(Triple_1eda90, Triple_1eda90, Triple_1eda90);
};
class Dummy_1edb60 {
  public:
    void Call(void*);
};
class CActorManager_1edbe0 {
  public:
    void f();
};
class Dummy_1edc50 {
  public:
    void Call(void*);
};
class CActorManager_1edcd0 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_1edcd0::*MFn_1edcd0)(unsigned char);
class Function_1edcd0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" char DAT_00424398[];
extern "C" char Read_001d04d0(int*);
class Method3_1edcf0 {
  public:
    void Init_001d0480(char*, int);
    Method3_1edcf0* Fn(char*, hulk_intptr);
};
struct Layout_1edcf0 {
    void* v;
    char pad04[0x0c];
    char b10, b11, b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int m1c;
};
struct CSoundRealTimeManager_1edd70 { void placeholder(char *, char *, char *); };
struct Args { char *first; char *second; char *third; };
struct Function_1edd70 { virtual void vfunc_0(); virtual void vfunc_1(); };
class Dummy_1eddf0 {
  public:
    void Call(void*);
};
extern "C" char DAT_004243b8[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
class Method4_1ede10 : public FUN_001d0480 {
  public:
    Method4_1ede10(const char*, ScriptMemberFn);
    int* vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
};
class CSoundSimManager_1edea0 { public: void placeholder(); };
class CFEManager_1edf40 {
  public:
    void Call(const char*, int);
};
class Function_1edf40 {
  public:
    virtual void f0();
    virtual void f1();
};
class Volume_1edf60 {
  public:
};
class Loader_1edf60 {
  public:
};
class Engine_1edf60 {
  public:
    Volume_1edf60* volume;
    Loader_1edf60* loader;
    void FUN_001efa40(int a, const char* name, int b);
    void FUN_001f22f0(float dt, int flag);
};
class Boot {
  public:
    Engine_1edf60* engine;
    char pad0[4];
    char active;
    char pad1[3];
    float level;
    void FUN_001ec480(const char* a, const char* b);
    void FUN_001edf60();
};
struct B_1ee020 { unsigned char FUN_001f4710(); };
struct A_1ee020 { B_1ee020* b; void FUN_001f22f0(float, int); void FUN_001ef9c0(int); };
struct S_1ee020 { A_1ee020* a; char pad[4]; unsigned char active; void FUN_001ee020(); };
struct ThisCall_001ec480 {
    void FUN_001ec480(const float*, const char*);
};
struct Sub_1ee090 {
    int Check_001d5040();
};
struct A_1ee090 {
    char pad[0xec];
    Sub_1ee090* s;
    char pad2[0x11c - 0xf0];
    int m11c;
    char pad3[0x128 - 0x120];
    int m128;
};
struct M_1ee090 {
    void F1_001ecc80(A_1ee090* a, int b, A_1ee090* c, int d);
    void F2_001ebd80(A_1ee090* a, const char* n, float f, int z);
    void F3_001ec980(A_1ee090* a, const char* n);
    void Run(A_1ee090* a, A_1ee090* b, A_1ee090* c, hulk_intptr d);
};
class CActorManager_1ee190 {
  public:
    void invoke(const char*);
};
class CActorManager_1ee210 {
  public:
    void run();
};
class CActorManager_1ee290 {
  public:
    void invoke(const char*);
};
class Actor_1ee320 {
  public:
    void fn(unsigned char);
};
struct CSoundRealTimeManager_1ee390 {};
class CActorManager_1ee420 {
  public:
    void invoke(const char*);
};
struct CSoundSimManager_1ee490 { void callback(const char *, const char *, const char *, const char *); };
class CActorManager_1ee540 {
  public:
    void Method(const char*, float);
};
struct Pair_1ee540 {
    const char* s;
    float f;
};
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f014178b
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f014178b {
class CSoundRealTimeManager_1ee6c0 {};
typedef void (CSoundRealTimeManager_1ee6c0::*Fn_1ee6c0)(char*, char*, char*);
class Registry_1ee6c0 { public:
    void FUN_001ee6c0(const char* a1, CSoundRealTimeManager_1ee6c0* a2, Fn_1ee6c0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1ee6c0;
template<> class Closure3_1ee6c0<CSoundRealTimeManager_1ee6c0, void, char*, char*, char*> : public ScriptFunctionFields { public: virtual void v(); Fn_1ee6c0 fn; CSoundRealTimeManager_1ee6c0* owner; Closure3_1ee6c0(CSoundRealTimeManager_1ee6c0* o) { owner = o; } };
class Raw_1ee6c0 { public: void FUN_001edcf0(const char*, Fn_1ee6c0); };
class CSoundSimManager_1ee770 {};
typedef void (CSoundSimManager_1ee770::*Fn_1ee770)(const char*, const char*, const char*, const char*);
class Registry_1ee770 { public:
    void FUN_001ee770(const char* a1, CSoundSimManager_1ee770* a2, Fn_1ee770 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_1ee770;
template<> class Closure4_1ee770<CSoundSimManager_1ee770, void, const char*, const char*, const char*, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_1ee770 fn; CSoundSimManager_1ee770* owner; Closure4_1ee770(CSoundSimManager_1ee770* o) { owner = o; } };
class Raw_1ee770 { public: void FUN_001ede10(const char*, Fn_1ee770); };


// 0x001eadf0 FUN_001eadf0 (170 B): equivalent/0x001eadf0.cpp
// sym: ?FUN_001eadf0@Object@fn_f014178b@@QAE_NXZ @cdd2c73dc86c @wdce7f5c7238f
// STATUS: equivalent (tools/equiv.py level 3: 2810 inputs, branch coverage 20/20)
// FUN_001eadf0 @ 0x001eadf0
bool Object::FUN_001eadf0() {
    for (int i = 0; i < count; ++i) {
        if (entries[i] && entries[i]->blocked == 0 && entries[i]->state != 0) {
            entries[i]->FUN_001ea700();
            while (entries[i]->state != 0) {
                FUN_002656a0();
                thunk_FUN_00270a50();
                if (entries[i]->state == 3)
                    entries[i]->FUN_001ea700();
                Entry_1eadf0* entry = entries[i];
                if (entry->state == 1 && (*(Manager_1eadf0**)&DAT_004e3694)->FUN_00266750()) {
                    entry->state = 3;
                    (*(Manager_1eadf0**)&DAT_004e3694)->FUN_00263e90();
                    (*(Manager_1eadf0**)&DAT_004e3694) = 0;
                }
            }
        }
    }
    active = 0;
    return true;
}


// 0x001eaea0 FUN_001eaea0 (437 B): equivalent/0x001eaea0.cpp
// sym: ?FUN_001eaea0@Manager_1eaea0@fn_f014178b@@QAEXXZ @5b5e53c725f7 @w31d6a4a2bb82
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 31/34, incomplete)
// FUN_001eaea0 @ 0x001eaea0
void Manager_1eaea0::FUN_001eaea0()
{
    FUN_00241280(0, 0, 0);

    for (int i = 0; i < slotCount; i++) {
        Slot_1eaea0 *s = slots[i];
        if (s->users > 0) {
            if (s->refCount > 0) {
                int j = 0;
                do {
                    if (s->refs[j])
                        s->refs[j]->refs--;
                    j++;
                } while (j < s->refCount);
            }
            s->users--;
        }
        slots[i]->FUN_001eadf0();
        if (slots[i])
            slots[i]->Destroy(1);
        slots[i] = 0;
    }

    int n = handleCount;
    slotCount = 0;
    for (int i = 0; i < n; i++) {
        if (handles[i]) {
            handles[i]->FUN_001ea700();
            Handle_1eaea0 *h = handles[i];
            if (h->state == 1) {
                if ((*(Sync**)&DAT_004e3694)->FUN_00266750()) {
                    h->state = 3;
                    (*(Sync**)&DAT_004e3694)->FUN_00263e90();
                    (*(Sync**)&DAT_004e3694) = 0;
                }
            }
            FUN_0008d330(handles[i]);
            handles[i] = 0;
        }
        n = handleCount;
    }

    n = jobCount;
    handleCount = 0;
    for (int i = 0; i < n; i++) {
        Job_1eaea0 *job = jobs[i];
        void *mgr = FUN_00240750();
        FUN_002416c0(mgr, job->timer, 0);
        while (job->timer->pending != 0)
            FUN_00243090(FUN_00240750(), 0.001f);
        FUN_00242ca0(FUN_00240750(), &job->timer);
        if (jobs[i])
            jobs[i]->Destroy(1);
        jobs[i] = 0;
        n = jobCount;
    }

    jobCount = 0;
    (*(hulk_intptr*)&DAT_004e3698) = 0;
    f514 = 0;
    pool->FUN_002665a0();
    f520 = 0;
    (*(int*)&DAT_004e36ac) = 0;
}


// 0x001eb130 FUN_001eb130 (3 B): matches/0x001eb130.cpp
// sym: ?FUN_001eb130@fn_f014178b@@YGXH@Z
void __stdcall FUN_001eb130(int a) {}


// 0x001eb140 FUN_001eb140 (3 B): matches/0x001eb140.cpp
// sym: ?FUN_001eb140@fn_f014178b@@YGXH@Z
void __stdcall FUN_001eb140(int arg) {}


// 0x001eb150 FUN_001eb150 (3 B): matches/0x001eb150.cpp
// sym: ?Target@fn_f014178b@@YGXH@Z
void __stdcall Target(int x) {}


// 0x001eb160 FUN_001eb160 (3 B): matches/0x001eb160.cpp
// sym: ?FUN_001eb160@fn_f014178b@@YGXH@Z
void __stdcall FUN_001eb160(int a) {}


// 0x001eb200 FUN_001eb200 (6 B): matches/0x001eb200.cpp
// sym: _FUN_001eb200
// Same code shape as 0x00085cd0 (propagated); reads 0x004e36d8, a pointer item
extern "C" hulk_intptr FUN_001eb200(void) {
    return *(hulk_intptr*)&DAT_004e36d8;
}


// 0x001eb210 FUN_001eb210 (6 B): matches/0x001eb210.cpp
// sym: _FUN_001eb210
// Same code shape as 0x00085cd0 (propagated; names are from that function)
extern "C" int FUN_001eb210(void) {
    return *(int*)&DAT_004e36dc;
}

} // namespace fn_f014178b

// 0x001eb220 FUN_001eb220 (96 B): equivalent/0x001eb220.cpp
// sym: ?FUN_001eb220@SoundRealTimeManager_1eb220@@QAEPAU1@IIE@Z @a1883fd6f91e @w0bf0014e3273
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001eb220 @ 0x001eb220
// (x64t9-mgr) CSoundRealTimeManager's words are include/decls/managers.h's HulkSoundRealTimeManager (0x00088020
// allocates it): the owner is CGame, a pointer (gen owners' State_1eb220 held it as a 32-bit word)
struct SoundRealTimeManager_1eb220 : HulkSoundRealTimeManager {
    SoundRealTimeManager_1eb220* FUN_001eb220(hulk_uintptr ownerValue, hulk_uintptr unused, unsigned char modeValue);
};
SoundRealTimeManager_1eb220* SoundRealTimeManager_1eb220::FUN_001eb220(hulk_uintptr ownerValue, hulk_uintptr unused, unsigned char modeValue) {
    mode = modeValue;
    (*(SoundRealTimeManager_1eb220**)&DAT_004e36d8) = this;
    active = 0;
    first = 100.0f;
    third = 100.0f;
    second = 100.0f;
    count = 1;
    Resource_1eb220* allocated = FUN_0008d710(20, 6);
    void* result = 0;
    if (allocated)
        result = allocated->FUN_001f1270();
    resource = result;
    owner = (void*)ownerValue;
    return this;
}


// 0x001eb2a0 FUN_001eb2a0 (17 B): matches/0x001eb2a0.cpp
// sym: ?FUN_001eb2a0@Thing_1eb2a0@owners@@QAEXHH@Z
void owners::Thing_1eb2a0::FUN_001eb2a0(int a, int b) {
    if (enabled)
        ((Other_1eb2a0*)*(void**)this)->target_001f22f0(a, b);
}

namespace fn_f014178b {

// 0x001eb440 FUN_001eb440 (132 B): equivalent/0x001eb440.cpp
// sym: ?FUN_001eb440@fn_f014178b@@YAXPAUNameSource_1eb440@1@PAUStringList_1eb440@1@@Z @99f96b2bc424 @w28a216697169
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_001eb440 @ 0x001eb440
void FUN_001eb440(NameSource_1eb440 *source, StringList_1eb440 *list)
{
    const char *name = source->FUN_0008a2d0();
    char field2[4];
    char field1[4];
    field1[0] = 0;
    field1[1] = 0;
    field1[2] = 0;
    field1[3] = 0;
    strncat(field1, name, 3);
    atol(field1 + 1);
    field2[0] = 0;
    field2[1] = 0;
    field2[2] = 0;
    field2[3] = 0;
    strncat(field2, name + 3, 3);
    atol(field2 + 1);
    list->FUN_001ef370(field1);
    list->FUN_001ef370(field2);
}


// 0x001eb4d0 FUN_001eb4d0 (7 B): matches/0x001eb4d0.cpp
// sym: ?g@Outer_1eb4d0@fn_f014178b@@QAEXXZ
// Same code shape as 0x001c3830 (propagated; names are from that function)
void Outer_1eb4d0::g() {
    ((owners::Obj_1eef00 *)p)->FUN_001eef00();
}


// 0x001eb4e0 FUN_001eb4e0 (1 B): matches/0x001eb4e0.cpp
// sym: ?FUN_001eb4e0@fn_f014178b@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001eb4e0(void* /*this, unused: callers pass it (unb4)*/) {}


// 0x001eb4f0 FUN_001eb4f0 (47 B): equivalent/0x001eb4f0.cpp
// sym: ?FUN_001eb4f0@Thing@fn_f014178b@@QAEXH@Z @3e61472a4807 @we1f512df49e4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001eb4f0 @ 0x001eb4f0
void Thing::FUN_001eb4f0(int unused) {
    (*(unsigned char*)&DAT_004e36e0) = 0;
    if (active) {
        if (flagged) {
            flagged = 0;
            outer->inner->FUN_001f46a0();
        }
        outer->FUN_001ef9c0(1);
    }
}


// 0x001eb550 FUN_001eb550 (9 B): matches/0x001eb550.cpp
// sym: ?Target@X_1eb550@fn_f014178b@@QAEXXZ
void X_1eb550::Target() {
    (*p)->FnA_001f3930();
}


// 0x001eb560 FUN_001eb560 (116 B): matches/0x001eb560.cpp
// sym: ?Fn@C_1eb560@fn_f014178b@@QAEXH@Z
void C_1eb560::Fn(hulk_intptr t) {
    Temp_1eb560 a;
    ((owners::Obj_1ef320 *)&a)->FUN_001ef320();
    a.SetName_001ef370(DAT_00424208);
    a.SetName_001ef370(DAT_00424200);
    Obj_1eb560* o = ((Obj_1eb560 *)((owners::C_86310 *)m4)->FUN_00086310());
    if (o)
        Build_001eb440(o, &a);
    if (m8)
        m0->Draw_001efe20(&a, 0, t, 100.0f);
    ((owners::C_1ef350 *)&a)->FUN_001ef350();
}


// 0x001eb5e0 FUN_001eb5e0 (184 B): equivalent/0x001eb5e0.cpp
// sym: ?run@Target_1eb5e0@fn_f014178b@@QAEXABUString@2@IPBD@Z @8678d210e2e6 @wf71ac779ded8
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 8/8)
// FUN_001eb5e0 @ 0x001eb5e0
void Target_1eb5e0::run(const String& input, unsigned int value, const char* text) {
 List_1eb5e0 items;
 ((owners::Obj_1ef320 *)&items)->FUN_001ef320();
 items.FUN_001ef370("Objects");
 items.FUN_001ef370("NIS");
 void* found = ((void *)((owners::C_86310 *)lookup)->FUN_00086310());
 if (found) FUN_001eb440(found, &items);
 String copied;
 copied.FUN_0027af30(input);
 items.FUN_001ef3c0(copied);
 String label;
 label.FUN_0027af00();
 if (text && *text) ((owners::Target_27b040 *)&label)->FUN_0027b040((hulk_uintptr)text);
 if (enabled) display->FUN_001efe20(&items, &label, value, 100.0f);
 label.FUN_0027af50();
 ((owners::C_1ef350 *)&items)->FUN_001ef350();
}


// 0x001eb6a0 FUN_001eb6a0 (9 B): matches/0x001eb6a0.cpp
// sym: ?F@A_1eb6a0@fn_f014178b@@UAEXXZ
void A_1eb6a0::F() {
    ((B_1eb6a0*)*(void**)*(void**)this)->FnG_001f6ba0();
}


// 0x001eb6b0 FUN_001eb6b0 (9 B): matches/0x001eb6b0.cpp
// sym: ?F@A_1eb6b0@fn_f014178b@@UAEXXZ
// Same code shape as 0x001eb6a0 (propagated; names are from that function)
void A_1eb6b0::F() {
    ((B_1eb6b0*)*(void**)*(void**)this)->FnG_001f3ad0();
}


// 0x001eb6c0 FUN_001eb6c0 (116 B): matches/0x001eb6c0.cpp
// sym: ?Fn@C_1eb6c0@fn_f014178b@@QAEXH@Z
void C_1eb6c0::Fn(hulk_intptr t) {
    Temp_1eb6c0 a;
    ((owners::Obj_1ef320 *)&a)->FUN_001ef320();
    a.SetName_001ef370(DAT_00424208);
    a.SetName_001ef370(DAT_00424214);
    Obj_1eb6c0* o = ((Obj_1eb6c0 *)((owners::C_86310 *)m4)->FUN_00086310());
    if (o)
        Build_001eb440(o, &a);
    if (m8)
        m0->Draw_001efe20(&a, 0, t, 100.0f);
    ((owners::C_1ef350 *)&a)->FUN_001ef350();
}

} // namespace fn_f014178b

// 0x001eb740 FUN_001eb740 (156 B): matches/0x001eb740.cpp [wrapped: merged class would differ: Name: size 1 vs 8]
// sym: ?FUN_001eb740@Loader_1eb740@fn_001eb740@@QAEXPBDH0@Z
namespace fn_001eb740 {
// FUN_001eb740 @ 0x001eb740
// FUN_001eb740: build a search list ("Objects", "Dialogue", name) and start a lookup
// equiv-map: ??0StrList@@QAE@XZ = 0x001ef320
// equiv-map: ??1StrList@@QAE@XZ = 0x001ef350
// equiv-map: ??0Name@@QAE@PBD@Z = 0x0027b0e0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
struct StrList {
    char data[0x48];
    StrList() throw();
    ~StrList() throw();
    void FUN_001ef370(const char *s) throw();
};

struct Name {
    char data[8];
    Name(const char *s) throw();
    ~Name() throw();
};

struct Finder_1eb740 {
};

struct Sink_1eb740 {
    void FUN_001efe20(StrList *list, Name *name, int a, float scale) throw();
};

void __cdecl FUN_001eb440(int found, StrList *list) throw();

class Loader_1eb740 {
public:
    Sink_1eb740 *sink;
    Finder_1eb740 *finder;
    char enabled;

    void FUN_001eb740(const char *dir, hulk_intptr a, const char *name) throw();
};

void Loader_1eb740::FUN_001eb740(const char *dir, hulk_intptr a, const char *name)
{
    StrList list;
    list.FUN_001ef370("Objects");
    list.FUN_001ef370("Dialogue");
    list.FUN_001ef370(dir);
    int found = ((int)((owners::C_86310 *)finder)->FUN_00086310());
    if (found != 0)
        FUN_001eb440(found, &list);
    Name n(name);
    if (enabled)
        sink->FUN_001efe20(&list, &n, a, 100.0f);
}
} // namespace fn_001eb740

namespace fn_f014178b {

// 0x001eb7e0 FUN_001eb7e0 (129 B): equivalent/0x001eb7e0.cpp
// sym: ?FUN_001eb7e0@Owner_1eb7e0@fn_f014178b@@QAEXHHPBUVec3_1eb7e0@2@00MMMH@Z @269cf67920f4 @w9179bec6fb5c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001eb7e0 @ 0x001eb7e0
void Owner_1eb7e0::FUN_001eb7e0(int a, int b, const Vec3_1eb7e0 *p3, const Vec3_1eb7e0 *p4, const Vec3_1eb7e0 *p5,
                         float f6, float f7, float f8, int p9)
{
    Vec3_1eb7e0 last;
    last.x = f6;
    last.y = f7;
    last.z = f8;
    (*handle).impl->FUN_001f42d0(a, b, *p3, *p4, *p5, last, p9);
}


// 0x001eb870 FUN_001eb870 (17 B): matches/0x001eb870.cpp
// sym: ?target@fn_f014178b@@YIXPAVA_1eb870@1@@Z
void __fastcall target(A_1eb870* p) {
    if (p->flag)
        ((B_1eb870*)**(void***)p)->FnF_001f6580();
}


// 0x001eb890 FUN_001eb890 (17 B): matches/0x001eb890.cpp
// sym: ?target@fn_f014178b@@YIXPAVA_1eb890@1@@Z
// Same code shape as 0x001eb870 (propagated; names are from that function)
void __fastcall target(A_1eb890* p) {
    if (p->flag)
        ((B_1eb890*)**(void***)p)->FnF_001f6650();
}


// 0x001eb8d0 FUN_001eb8d0 (123 B): matches/0x001eb8d0.cpp
// sym: ?Target@Owner_1eb8d0@fn_f014178b@@QAEXH@Z
void Owner_1eb8d0::Target(hulk_intptr arg) {
    Temp_1eb8d0 t;
    if (flag) {
        ((owners::Obj_1ef320 *)&t)->FUN_001ef320();
        t.Add_001ef370("Objects");
        t.Add_001ef370("Mix");
        void* p = ((void *)((owners::C_86310 *)manager)->FUN_00086310());
        if (p)
            FUN_001eb440(p, &t);
        if (flag)
            root->Run_001efe20(&t, 0, arg, 100.0f);
        ((owners::C_1ef350 *)&t)->FUN_001ef350();
    }
}


// 0x001eb950 FUN_001eb950 (123 B): matches/0x001eb950.cpp
// sym: ?Run@Owner_1eb950@fn_f014178b@@QAEXM@Z
void Owner_1eb950::Run(float x) {
    Temp_1eb950 t;
    if (enabled) {
        ((owners::Obj_1ef320 *)&t)->FUN_001ef320();
        t.Add_001ef370("Objects");
        t.Add_001ef370("DSP");
        int* p = ((int *)((owners::C_86310 *)mgr)->FUN_00086310());
        if (p)
            Use_001eb440(p, &t);
        if (enabled)
            ((Obj_1eb950*)*(void**)this)->Send_001efe20(&t, 0, x, 100.0f);
        ((owners::C_1ef350 *)&t)->FUN_001ef350();
    }
}

} // namespace fn_f014178b

// 0x001eb9d0 FUN_001eb9d0 (4 B): matches/0x001eb9d0.cpp
// sym: ?vfunc_6@HulkActionTrack@ai@hulkfight@@QAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
namespace hulkfight { namespace ai {
float HulkActionTrack::vfunc_6() {
    return mValue;
}
} }

namespace fn_f014178b {

// 0x001eb9e0 FUN_001eb9e0 (53 B): matches/0x001eb9e0.cpp
// sym: ?UpdateValue@Obj_1eb9e0@fn_f014178b@@QAEXM@Z
// data: g_limit_1eb9e0 = DAT_003f32d8, g_zero_1eb9e0 = DAT_003f32e0
void Obj_1eb9e0::UpdateValue(float x) {
    if (x < DAT_003f32e0 || x > DAT_003f32d8)
        return;
    value = x;
    ((owners::Obj_1f3950 *)(next->inner))->FUN_001f3950(x);
}

} // namespace fn_f014178b

// 0x001eba20 FUN_001eba20 (4 B): matches/0x001eba20.cpp
// sym: ?FUN_001eba20@CHapticTrack_1eba20@owners@@QAEMXZ
// Same code shape as 0x0005d1d0 (propagated; names are from that function)
float owners::CHapticTrack_1eba20::FUN_001eba20() {
    return value;
}

namespace fn_f014178b {

// 0x001eba30 FUN_001eba30 (53 B): matches/0x001eba30.cpp
// sym: ?set@Obj_1eba30@fn_f014178b@@QAEXM@Z
void Obj_1eba30::set(float v) {
    if (v < 0.0f || v > 100.0f)
        return;
    value = v;
    ((owners::Obj_1f39d0 *)(inner->d))->FUN_001f39d0(v);
}

} // namespace fn_f014178b

// 0x001eba70 FUN_001eba70 (4 B): matches/0x001eba70.cpp
// sym: ?FUN_001eba70@CJumpTrack_1eba70@owners@@QAEMXZ
// Same code shape as 0x00069050 (propagated; names are from that function)
float owners::CJumpTrack_1eba70::FUN_001eba70() {
    return value;
}

namespace fn_f014178b {

// 0x001eba80 FUN_001eba80 (62 B): matches/0x001eba80.cpp
// sym: ?F@C_1eba80@fn_f014178b@@QAEXM@Z
// data: Limit = DAT_003f32d8, Zero_1eba80 = DAT_003f32e0
void C_1eba80::F(float x) {
    if (!(x < DAT_003f32e0) && !(x > DAT_003f32d8)) {
        ((owners::Thing_1f3990 *)(holder->obj))->FUN_001f3990(x);
        value = x;
    }
}


// 0x001ebac0 FUN_001ebac0 (4 B): matches/0x001ebac0.cpp
// sym: ?FUN_001ebac0@fn_f014178b@@YIHH@Z
// Same code shape as 0x00059a40 (propagated; names are from that function)
int __fastcall FUN_001ebac0(hulk_intptr object) {
    return *(int*)(object + 0x18);
}


// 0x001ebad0 FUN_001ebad0 (21 B): matches/0x001ebad0.cpp
// sym: ?Set@Obj@fn_f014178b@@QAEXH@Z
void Obj::Set(int v) {
    value = v;
    provider->inner->Set_001e8a50(v);
}


// 0x001ebaf0 FUN_001ebaf0 (168 B): matches/0x001ebaf0.cpp
// sym: ?Fn@fn_f014178b@@YGXPBD@Z
// data: g_lang = DAT_0049caa4
void __stdcall Fn(const char* s) {
    Obj_1ebaf0 o;
    if (strcmp(s, "fr") == 0) {
        *(S7*)DAT_0049caa4 = *(const S7*)"french";
    } else if (strcmp(s, "it") == 0) {
        *(S8_1ebaf0*)DAT_0049caa4 = *(const S8_1ebaf0*)"italian";
    } else {
        *(S8_1ebaf0*)DAT_0049caa4 = *(const S8_1ebaf0*)"english";
    }
    Use_00240760(((Obj_1ebaf0 *)((owners::String_23fc40 *)&o)->FUN_0023fc40(DAT_0049caa4, (hulk_intptr)2)));
    ((owners::Str_240060 *)&o)->FUN_00240060();
}

} // namespace fn_f014178b

// 0x001ebba0 FUN_001ebba0 (23 B): matches/0x001ebba0.cpp
// sym: ?FUN_001ebba0@C_1ebba0@owners@@QAEPAU12@HH@Z
owners::C_1ebba0* owners::C_1ebba0::FUN_001ebba0(hulk_intptr x, hulk_intptr y) {
    (*(owners::C_1ebba0**)&DAT_004e36dc) = this;
    a = ((int)x);
    b = ((int)y);
    return this;
}

namespace fn_f014178b {

// 0x001ebbc0 FUN_001ebbc0 (187 B): equivalent/0x001ebbc0.cpp
// sym: ?target@Owner_1ebbc0@fn_f014178b@@QAEXPAUActor_1ebbc0@2@PBD@Z @b31fd38a9ff7 @wa01817e2b3dd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001ebbc0 @ 0x001ebbc0
void Owner_1ebbc0::target(Actor_1ebbc0* actor, const char* text) {
 if (!actor || !text || !*text) return;
 Path_1ebbc0 path;
 ((owners::Obj_1ef320 *)&path)->FUN_001ef320();
 path.FUN_001ef370("Objects");
 path.FUN_001ef370("Dialogue");
 path.FUN_001ef370((actor->flags & 4) ? "civ_female" : "civ_male");
 void* object = ((void *)((owners::C_86310 *)context)->FUN_00086310());
 if (object) FUN_001eb440(object, &path);
 if ((*(Manager_1ebbc0**)&DAT_004e36d8)->enabled) (*(Manager_1ebbc0**)&DAT_004e36d8)->audio->FUN_001efe20(&path, actor->position, text, 100.0f);
 ((owners::C_1ef350 *)&path)->FUN_001ef350();
}


// 0x001ebc80 FUN_001ebc80 (128 B): matches/0x001ebc80.cpp
// sym: ?target@fn_f014178b@@YGXPAXPBD@Z
// data: gState_1ebc80 = DAT_004e36d8, sDialogue = DAT_00424220, sObjects = DAT_00424208
void __stdcall target(void* param1, const char* param2) {
    char local[72];
    if (!param1)
        return;
    if (!param2)
        return;
    if (!*param2)
        return;
    Builder* b = (Builder*)local;
    ((owners::Obj_1ef320 *)b)->FUN_001ef320();
    b->Add_001ef370(DAT_00424208);
    b->Add_001ef370(DAT_00424220);
    b->Add_001ef370(DAT_0042424c);
    State_1ebc80* s = (*(State_1ebc80**)&DAT_004e36d8);
    if (s->enabled)
        s->runner->Run_001efe20(local, (char*)param1 + 8, param2, 100.0f);
    ((owners::C_1ef350 *)b)->FUN_001ef350();
}

} // namespace fn_f014178b

// 0x001ebd00 FUN_001ebd00 (127 B): matches/0x001ebd00.cpp
// sym: ?FUN_001ebd00@Owner_1ebd00@owners@@QAEXPBD0@Z
// data: gManager_1ebd00 = DAT_004e36d8
void owners::Owner_1ebd00::FUN_001ebd00(const char* a, const char* b) {
    if (!a || !*a)
        return;
    if (!b || !*b)
        return;
    char storage[0x48];
    Temp_1ebd00* t = (Temp_1ebd00*)storage;
    ((owners::Obj_1ef320 *)t)->FUN_001ef320();
    t->Add_001ef370("Objects");
    t->Add_001ef370("FE");
    t->Add_001ef370(a);
    if (*(char*)((char*)(*(Manager_1ebd00**)&DAT_004e36d8) + 8))
        ((Manager_1ebd00*)*(void**)(*(Manager_1ebd00**)&DAT_004e36d8))->Run_001efe20((char*)t, 0, b, 100.0f);
    ((owners::C_1ef350 *)t)->FUN_001ef350();
}

namespace fn_f014178b {

// 0x001ebd80 FUN_001ebd80 (142 B): equivalent/0x001ebd80.cpp
// sym: ?FUN_001ebd80@fn_f014178b@@YGXPAUProp_1ebd80@1@HMH@Z @03124e3472d7 @wea4da663af3e
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// FUN_001ebd80 @ 0x001ebd80
// Posts a "Objects/Props/<id>" event for a prop.
void __stdcall FUN_001ebd80(Prop_1ebd80 *prop, int name, float delay, int unused) {
    if (prop == 0 || prop->descriptor == 0)
        return;
    StringList_1ebd80 path;
    ((owners::Obj_1ef320 *)&path)->FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("Props");
    path.FUN_001ef3c0(IdCopy_1ebd80(prop->descriptor->id));
    if ((*(EventConfig_1ebd80**)&DAT_004e36d8)->enabled)
        (*(EventConfig_1ebd80**)&DAT_004e36d8)->sink->FUN_001efe20(&path, prop->where, name, delay);
    ((owners::C_1ef350 *)&path)->FUN_001ef350();
}


// 0x001ebe10 FUN_001ebe10 (133 B): matches/0x001ebe10.cpp
// sym: ?Emit@Emitter_1ebe10@fn_f014178b@@QAEXPAUSource_1ebe10@2@PBXH@Z
// FUN_001ebe10 @ 0x001ebe10
void Emitter_1ebe10::Emit(Source_1ebe10 *source, const void *where, hulk_intptr name)
{
    if (source == 0)
        return;
    StringList_1ebe10 path;
    ((owners::Obj_1ef320 *)&path)->FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("Props");
    path.FUN_001ef390(((owners::Obj_79530 *)(owner->registry))->FUN_00079530(source->key));
    if ((*(EventConfig_1ebe10**)&DAT_004e36d8)->enabled)
        (*(EventConfig_1ebe10**)&DAT_004e36d8)->sink->FUN_001efe20(&path, where, name, 100.0f);
    ((owners::C_1ef350 *)&path)->FUN_001ef350();
}


// 0x001ebfd0 FUN_001ebfd0 (136 B): matches/0x001ebfd0.cpp
// sym: ?FUN_001ebfd0@fn_f014178b@@YGXPAUTarget_1ebfd0@1@H@Z
// FUN_001ebfd0 @ 0x001ebfd0
void __stdcall FUN_001ebfd0(Target_1ebfd0 *target, int a)
{
    if (!target)
        return;
    if (!target->handle)
        return;
    Key_1ebfd0 *key = &target->key;
    if (key->lo != (*(unsigned int*)&DAT_004dc0e0) || key->hi != (*(unsigned int*)((char*)&DAT_004dc0e0 + 4)))
        return;
    NameList_1ebfd0 names;
    ((owners::Obj_1ef320 *)&names)->FUN_001ef320();
    names.FUN_001ef370("Objects");
    names.FUN_001ef370("FE");
    Registry_1ebfd0 *registry = (*(Registry_1ebfd0**)&DAT_004e36d8);
    if (registry->enabled)
        registry->dispatcher->FUN_001efe20(&names, key, a, 100.0f);
    ((owners::C_1ef350 *)&names)->FUN_001ef350();
}


// 0x001ec060 FUN_001ec060 (130 B): matches/0x001ec060.cpp
// sym: ?FUN_001ec060@fn_f014178b@@YGXPAUEntity@1@H@Z
// FUN_001ec060 @ 0x001ec060
void __stdcall FUN_001ec060(Entity *entity, int name)
{
    if (entity == 0)
        return;
    if (entity->slot->FUN_001d4f70() != (*(unsigned __int64*)&DAT_004e3700))
        return;

    StringList_1ec060 path;
    ((owners::Obj_1ef320 *)&path)->FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("FE");
    if ((*(EventConfig_1ec060**)&DAT_004e36d8)->enabled)
        (*(EventConfig_1ec060**)&DAT_004e36d8)->sink->FUN_001efe20(&path, entity->pos, name, 100.0f);
    ((owners::C_1ef350 *)&path)->FUN_001ef350();
}


// 0x001ec0f0 FUN_001ec0f0 (3 B): matches/0x001ec0f0.cpp
// sym: ?vfunc_5@physics_CollisionRay_1ec0f0@fn_f014178b@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics_CollisionRay_1ec0f0::vfunc_5(hulk_intptr a, hulk_intptr b) {}


// 0x001ec3d0 FUN_001ec3d0 (164 B): equivalent/0x001ec3d0.cpp
// sym: ?FUN_001ec3d0@LevelEnter@fn_f014178b@@QAEXXZ @58e958c97047 @wa16a99d7182c
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_001ec3d0 @ 0x001ec3d0
void LevelEnter::FUN_001ec3d0()
{
    if (!active)
        return;
    void *id = ((void *)((owners::C_86310 *)level)->FUN_00086310());
    if (!id)
        return;
    StringList_1ec3d0 path;
    ((owners::Obj_1ef320 *)&path)->FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("World");
    FUN_001eb440(id, &path);
    if (entered) {
        entered = 0;
        sink->handler->FUN_001f46a0();
    } else if (active) {
        sink->FUN_001efe20(&path, 0, "EnterLevel", 100.0f);
    }
    ((owners::C_1ef350 *)&path)->FUN_001ef350();
}

} // namespace fn_f014178b

// 0x001ec480 FUN_001ec480 (1079 B): equivalent/0x001ec480.cpp [wrapped: macros]
// sym: ?run@Target@fn_001ec480@@QAEXPBD0@Z @2f2e7631f83c @wd5482d00a3d0
namespace fn_001ec480 {
// STATUS: equivalent (tools/equiv.py level 3: 12048 inputs, branch coverage 64/68, incomplete; run with --inputs 12000)
// FUN_001ec480 @ 0x001ec480

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl strncmp(const char*, const char*, unsigned);
#endif

struct Path {
    char data[72];
    void FUN_001ef370(const char*);
};
struct Screen {
    void FUN_001f4610(int, int, int);
    void FUN_001f47b0(int);
    void FUN_001f46a0();
};
struct UI {
    Screen* screen;
    void FUN_001efe20(Path*, int, const char*, float);
};
struct Info { const char* FUN_0008a2f0(); };
struct Owner {  };
struct Target {
    UI* ui;
    Owner* owner;
    unsigned char enabled, active;
    void FUN_001ec480(const char*, const char*);
    void run(const char*, const char*);
};
// Compare locally: these comparisons do not call the string library.
#define EQUAL(result, text, literal) \
    do { const char* a = (text); const char* b = (literal); \
         while (*a == *b && *b) { ++a; ++b; } \
         (result) = (*a == *b); } while (0)
void Target::run(const char* name, const char* value) {
    Path path;
    ((owners::Obj_1ef320 *)&path)->FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("FE");
    path.FUN_001ef370(name);
    if (enabled) ui->FUN_001efe20(&path, 0, value, 100.0f);

    const char* names[] = {
        "pause", "location_map", "mission_objectives", "mission_success",
        "mission_fail", "story_mission_success", "story_mission_fail",
        "side_mission_success", "side_mission_fail", "move_gallery",
        "jump_marker_select", "fullscreen_message", "mission_accept",
        "blonsky_file", "mission_briefing"
    };
    int kind;
    for (kind = 0; kind < 15; ++kind) {
        bool equal;
        EQUAL(equal, name, names[kind]);
        if (equal) break;
    }
    bool equal;
    if (kind < 10) {
        if (!active) {
            EQUAL(equal, value, "FE_screen_enter_start");
            if (equal) {
                bool success;
                EQUAL(success, name, "mission_success");
                if (!success) EQUAL(success, name, "story_mission_success");
                if (!success) EQUAL(success, name, "side_mission_success");
                if (success) FUN_001ec480("success", "success");
                UI* current = ui;
                active = 1;
                current->screen->FUN_001f4610(1, 1, 1);
            }
        } else {
            EQUAL(equal, value, "FE_back");
            if (equal) {
                UI* current = ui;
                active = 0;
                current->screen->FUN_001f46a0();
            }
        }
    } else if (kind < 12) {
        if (!active) {
            EQUAL(equal, value, "FE_screen_enter_start");
            if (equal) {
                FUN_001ec480("success", "success");
                UI* current = ui;
                active = 1;
                current->screen->FUN_001f4610(1, 0, 0);
            } else {
                EQUAL(equal, value, "c07m02");
                if (equal) {
                    FUN_001ec480("Briefings", value);
                    ui->screen->FUN_001f4610(0, 1, 1);
                    active = 1;
                }
            }
        } else {
            EQUAL(equal, value, "FE_back");
            if (equal) {
                UI* current = ui;
                active = 0;
                current->screen->FUN_001f46a0();
                ui->screen->FUN_001f47b0(0);
            }
        }
    } else if (kind == 12) {
        EQUAL(equal, value, "FE_screen_enter_start");
        if (equal) {
            UI* current = ui;
            active = 1;
            current->screen->FUN_001f4610(0, 1, 1);
            const char* briefing = ((Info *)((owners::C_86310 *)owner)->FUN_00086310())->FUN_0008a2f0();
            FUN_001ec480("Briefings", briefing);
        }
        EQUAL(equal, value, "FE_back");
        if (equal) {
            ui->screen->FUN_001f47b0(0);
            UI* current = ui;
            active = 0;
            current->screen->FUN_001f46a0();
        }
    } else if (kind < 15) {
        if (strncmp(value, "bf", 2) == 0) {
            ui->screen->FUN_001f4610(0, 1, 1);
            active = 1;
        } else {
            EQUAL(equal, value, "FE_back");
            if (equal) {
                ui->screen->FUN_001f47b0(0);
                if (active) {
                    UI* current = ui;
                    active = 0;
                    current->screen->FUN_001f46a0();
                }
            }
        }
    }
    ((owners::C_1ef350 *)&path)->FUN_001ef350();
}
} // namespace fn_001ec480
#undef EQUAL


// 0x001ec900 FUN_001ec900 (117 B): matches/0x001ec900.cpp [wrapped: merged class would differ: Name: size 1 vs 8]
// sym: ?FUN_001ec900@Camera@fn_001ec900@@QAEXUV3_1ec900@2@00@Z
namespace fn_001ec900 {
// FUN_001ec900 @ 0x001ec900
// equiv-map: ??0Name@@QAE@PBD@Z = 0x0027b0e0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
struct Name {
    char d[8];
    Name(const char *s) throw();
    ~Name() throw();
};

struct V3_1ec900 {
    float x, y, z;
};

class Camera {
public:
    void FUN_001eb7e0(Name *a, Name *b, V3_1ec900 *p, V3_1ec900 *q, V3_1ec900 *r, V3_1ec900 zero, int z) throw();
    void FUN_001ec900(V3_1ec900 a, V3_1ec900 b, V3_1ec900 c);
};

void Camera::FUN_001ec900(V3_1ec900 a, V3_1ec900 b, V3_1ec900 c)
{
    Name name("vo_camera");
    V3_1ec900 zero;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    FUN_001eb7e0(&name, &name, &a, &b, &c, zero, 0);
}
} // namespace fn_001ec900

namespace fn_f014178b {

// 0x001ec980 FUN_001ec980 (192 B): matches/0x001ec980.cpp
// sym: ?FUN_001ec980@Target_1ec980@fn_f014178b@@QAEXPAUActor_1ec980@2@H@Z
void Target_1ec980::FUN_001ec980(Actor_1ec980* actor, hulk_intptr value) {
    if (!actor || !actor->object)
        return;
    if (actor->alternate) {
        FUN_001ebd80(actor->alternate, value, 100.0f, 0);
        return;
    }
    Text_1ec980 text;
    ((owners::Obj_1ef320 *)&text)->FUN_001ef320();
    text.FUN_001ef370("Objects");
    text.FUN_001ef370("Actors");
    text.FUN_001ef370(actor->object->FUN_000443b0());
    ((owners::C_86310 *)service)->FUN_00086310();
    if ((*(Global_1ec980**)&DAT_004e36d8)->enabled)
        (*(Global_1ec980**)&DAT_004e36d8)->output->FUN_001efe20(&text, actor->location, value, 100.0f);
    ((owners::C_1ef350 *)&text)->FUN_001ef350();
}


// 0x001ecc80 FUN_001ecc80 (123 B): matches/0x001ecc80.cpp
// sym: ?Fn@Thing_1ecc80@fn_f014178b@@QAEXPAVOwner_1ecc80@2@PAVObj_1ecc80@2@1H@Z
void Thing_1ecc80::Fn(Owner_1ecc80* a, Obj_1ecc80* b, Obj_1ecc80* c, hulk_intptr d) {
    if (!a)
        return;
    if (!a->component)
        return;
    if (!b)
        return;
    if (!b->component)
        return;
    if (!b->component->Check_001d5040())
        return;
    if (!c)
        return;
    if (!c->component)
        return;
    if (!c->component->Check_001d5040())
        return;
    Play_001ebd80(c, "impact_big", 100.0f, 0);
    Play_001ebd80(b, "impact_big", 100.0f, 0);
}


// 0x001ecda0 FUN_001ecda0 (782 B): equivalent/0x001ecda0.cpp
// sym: ?FUN_001ecda0@Handler_1ecda0@fn_f014178b@@QAEXPBDH00@Z @4b11456652ba @wd80f67066eb9
// STATUS: equivalent (tools/equiv.py level 3: 3056 inputs, branch coverage 45/46, incomplete)
// FUN_001ecda0 @ 0x001ecda0
void Handler_1ecda0::FUN_001ecda0(const char *a1, int a2, const char *a3, const char *a4)
{
    Frame_1ecda0 f;
    bool online;
    f.id1.FUN_0027af00();
    f.id1.FUN_0027af60(0);
    f.id2.FUN_0027af00();
    f.self = this;

    do {
        if (strcmp(a4, "spawn") == 0) {
            if (f.self->env->logic->FUN_00027fc0("hulk", "//hulk/opening/holding/stealth_truck"))
                break;
        }
        if (a1 != 0 && a1[0] != 0) {
            f.id1.FUN_0027af70(f.tb.temp.FUN_0027b0e0(a1));
            f.tb.temp.FUN_0027af50();
        }
        online = ((Flags_1ecda0 *)((owners::A_86340 *)DAT_004dd6ec)->FUN_00086340())->FUN_00092de0(2);

        // A named target other than hulk/joefixit skips the lookup; the nearest actor's
        // name is looked up even when it is null.
        const char *name;
        bool lookup = true;
        if (a3 != 0 && a3[0] != 0) {
            ((owners::Target_27b040 *)&(f.id2))->FUN_0027b040((hulk_uintptr)a3);
            if (strcmp(a3, "hulk") != 0 && strcmp(a3, "joefixit") != 0)
                lookup = false;
            else {
                if (!online)
                    break;
                name = "joefixit";
            }
        } else {
            f.tb.best = 0;
            f.bestDist = 9999.0f;
            f.self->env->logic->self->node->FUN_00059a50(&f.p0);
            f.i = 0;
            if (f.self->env->logic->count <= 0)
                break;
            do {
                Actor_1ecda0 *actor = f.self->env->logic->FUN_00024190(f.i);
                if (actor != f.self->env->logic->self && actor->weight > 0.0f) {
                    unsigned lo = f.id1.lo, hi = f.id1.hi;
                    if ((lo | hi) == 0 || SameKey_1ecda0(actor->info->FUN_000443c0(), lo, hi)) {
                        actor->node->FUN_00059a50(&f.p1);
                        f.p1.x = f.p1.x - f.p0.x;
                        f.p1.y = f.p1.y - f.p0.y;
                        f.p1.z = f.p1.z - f.p0.z;
                        double dist = sqrt(f.p1.z * f.p1.z + f.p1.y * f.p1.y + f.p1.x * f.p1.x);
                        if (dist < f.bestDist) {
                            f.bestDist = (float)dist;
                            f.tb.best = actor;
                        }
                    }
                }
                f.i++;
            } while (f.i < f.self->env->logic->count);
            if (f.tb.best == 0)
                break;
            f.id2.FUN_0027af70(&f.tb.best->id);
            name = f.tb.best->info->FUN_000443b0();
        }
        if (lookup) {
            f.id1.FUN_0027af70(f.tb.temp.FUN_0027b0e0(name));
            f.tb.temp.FUN_0027af50();
        }

        if ((f.id1.lo | f.id1.hi) == 0)
            break;
        if (a4 == 0 || a4[0] == 0)
            break;
        ((Query_1ecda0 *)((owners::Obj_1ef320 *)&(f.q))->FUN_001ef320());
        f.q.FUN_001ef370("Objects");
        f.q.FUN_001ef370("Dialogue");
        f.q.FUN_001ef3c0(f.id1);
        void *target = ((void *)((owners::C_86310 *)(f.self->lookup))->FUN_00086310());
        if (target != 0)
            FUN_001eb440(target, &f.q);
        if ((*(SpawnGlobals_1ecda0**)&DAT_004e36d8)->enabled)
            (*(SpawnGlobals_1ecda0**)&DAT_004e36d8)->spawner->FUN_001efe20(&f.q, &f.id2, a4, 100.0f);
        ((owners::C_1ef350 *)&(f.q))->FUN_001ef350();
    } while (0);
    f.id2.FUN_0027af50();
    f.id1.FUN_0027af50();
}

} // namespace fn_f014178b

// 0x001ed320 FUN_001ed320 (1893 B): equivalent/0x001ed320.cpp [wrapped: conflict: Entity]
// sym: ?run@Target_1ed320@fn_001ed320@@QAEXPAUWorld@2@M@Z @788010034158 @w3838252ac2e5
namespace fn_001ed320 {
// STATUS: equivalent (tools/equiv.py level 3: 184 inputs, branch coverage 109/120, incomplete)
// FUN_001ed320 @ 0x001ed320

typedef unsigned __int64 ID;
struct V { float x,y,z; hulk_freg FUN_000259c0(); };
struct Name_1ed320 { unsigned a,b; void FUN_0027b0e0(const char*); void FUN_0027af50(); };
struct Named_1ed320 { char header[8]; Name_1ed320 name; };
struct Info_1ed320 { char p[20]; int flag; ID FUN_000443c0(); const char* FUN_000443b0(); };
struct Position_1ed320 { bool FUN_00059a50(V*); };
struct Entity { char p0[8]; ID id; Position_1ed320* pos; char p14[0x108]; Info_1ed320* info; char p120[8]; int excluded; char p12c[20]; int state; char p144[0x1f4]; Entity* link; char p33c[0x1724]; V origin; char p1a6c[0x221]; unsigned char screaming; char p1c8e[2]; float timer;  };
struct Actor_1ed320 { char p0[8]; ID id; char p10[0xdc]; Named_1ed320* name; char pf0[12]; int state; char p100[20]; void* flag; char p118[48]; Entity* entity; char p14c[125]; unsigned char flag2; V* FUN_001d6b40(); V* FUN_001d77c0(); };
struct Item_1ed320 { char p0[8]; ID id; char p10[84]; V location; };
struct Extra_1ed320 { char p[8]; ID id;  };
struct List_1ed320 { char p[12]; int count; Entity* FUN_00024190(int);  };
struct Items_1ed320 { char p[0x3800]; Extra_1ed320* extras[10]; int count; int FUN_00079270();  };
struct Actors { int FUN_001dcf50();  };
struct Slot_1ed320 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual Actor_1ed320* v5(); };
struct Slots_1ed320 {  };
struct World { char p[12]; Actors* actors; char p10[4]; Slots_1ed320* slots; char p18[8]; List_1ed320* list; char p24[40]; Items_1ed320* items; };
struct Renderer_1ed320 { void FUN_001f42d0(ID*,Name_1ed320*,V,V,V,V,int); };
struct Indirect { Renderer_1ed320* renderer; };
struct Manager_1ed320 { Indirect* indirect; void FUN_001eb7e0(ID*,Name_1ed320*,V*,V*,V*,V,int); void FUN_001eb560(const char*); void FUN_001eb6c0(const char*); };
struct Target_1ed320 { World* world; void FUN_001ed0b0(Entity*); void FUN_001ec100(Entity*,const char*); void run(World*,float); };
void Target_1ed320::run(World* w,float dt) {
 if(!DAT_0049caa0) return;
 world=w;
 if(!w) return;
 V velocity,position,delta,origin;
 Name_1ed320 name;
 int count=world->list->count;
 for(int i=0;i<count;++i) {
  Entity* e=world->list->FUN_00024190(i);
  if(!e || !e->pos->FUN_00059a50(&position) || e->excluded || ((owners::Obj_24540 *)(world->list))->FUN_00024540((hulk_intptr)(Entity *)e)) continue;
  int kind;
  if(e->info->FUN_000443c0()==(*(ID*)&DAT_004dc0e0)) kind=1;
  else kind=e->info->flag?2:4;
  ((owners::C_35660 *)e)->FUN_00035660((int *)(V *)(&velocity));
  name.FUN_0027b0e0(e->info->FUN_000443b0());
  (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb7e0(&e->id,&name,&position,((V*)&DAT_004e36e4),((V*)&DAT_004c7614),velocity,kind);
  if(e->id==(*(ID*)&DAT_004dc0e0)) {
   FUN_001ed0b0(e);
   if(!(*(unsigned char*)&DAT_004e3708)) {
    if(position.y>100.0f && velocity.FUN_000259c0()<5.0f && e->state!=3) {
     (*(unsigned char*)&DAT_004e3708)=1;
     (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb560("city_rooftop");
     (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb6c0("city_rooftop");
    }
   } else if(position.y<100.0f) {
    (*(unsigned char*)&DAT_004e3708)=0;
    (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb560("city_rooftop_done");
    (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb6c0("city_rooftop_done");
   }
  } else if(e->info->FUN_000443c0()==(*(ID*)&DAT_004dc068) || e->info->FUN_000443c0()==(*(ID*)&DAT_004dc0a8) || e->info->FUN_000443c0()==(*(ID*)&DAT_004dc0b8) || e->info->FUN_000443c0()==(*(ID*)&DAT_004dc0c8)) {
   FUN_001ed0b0(e);
  } else {
   int state=e->state;
   if(state==3) e->timer+=dt; else e->timer=0.0f;
   unsigned char screaming=e->screaming;
   Entity* link=e->link;
   if((!screaming && !link && state==3) || (link && link->id==(*(ID*)&DAT_004dc0e0))) {
    origin=e->origin;
    e->pos->FUN_00059a50(&delta);
    delta.x-=origin.x;
    double height=(double)delta.y-origin.y;
    delta.y=(float)height;
    delta.z-=origin.z;
    if(height>15.0f || (!e->link && e->timer>2.5f)) {
     e->screaming=1;
     FUN_001ec100(e,"screaming");
    }
   } else if(screaming && state!=3 && !link) {
    e->screaming=0; e->timer=0.0f;
   }
  }
  name.FUN_0027af50();
 }
 count=world->items->FUN_00079270();
 for(int i=0;i<count;++i) {
  Item_1ed320* e=((Item_1ed320 *)((owners::Target_79280 *)(world->items))->FUN_00079280(i));
  if(e) {
   origin=e->location;
   name.FUN_0027b0e0("civilians");
   (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb7e0(&e->id,&name,&origin,((V*)&DAT_004e36e4),((V*)&DAT_004c7614),(*(V*)&DAT_004e36e4),6);
   name.FUN_0027af50();
  }
 }
 if(world->actors) {
  count=world->actors->FUN_001dcf50();
  for(int i=0;i<count;++i) {
   Actor_1ed320* a=((Actor_1ed320 *)((owners::CGrabAction_1dc0b0 *)(world->actors))->FUN_001dc0b0(i));
   if(!a || a->state==2 || a->state==3) continue;
   Entity* e=a->entity;
   bool valid=false;
   if(e) valid=((owners::C_35660 *)e)->FUN_00035660((int *)(V *)(&velocity));
   position=*a->FUN_001d6b40();
   if(!valid) velocity=*a->FUN_001d77c0();
   int kind=a->flag||a->flag2?3:(e?2:5);
   (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb7e0(&a->id,&a->name->name,&position,((V*)&DAT_004e36e4),((V*)&DAT_004c7614),velocity,kind);
  }
 }
 if(world->slots) {
  for(int i=0;i<32;++i) {
   Slot_1ed320* slot=((Slot_1ed320 *)((owners::C_1b68e0 *)(world->slots))->FUN_001b68e0(i));
   if(!slot) continue;
   Actor_1ed320* a=slot->v5();
   if(!a) continue;
   position=*a->FUN_001d6b40();
   velocity=*a->FUN_001d77c0();
   (*(Manager_1ed320**)&DAT_004e36d8)->indirect->renderer->FUN_001f42d0(&a->id,&a->name->name,position,(*(V*)&DAT_004e36e4),(*(V*)&DAT_004c7614),velocity,3);
  }
 }
 count=world->items->count;
 for(int i=0;i<count;++i) {
  Extra_1ed320* e=world->items->extras[i];
  if(e) {
   V location=*((V *)((owners::Owner_82cf0 *)e)->FUN_00082cf0());
   name.FUN_0027b0e0("civilians");
   (*(Manager_1ed320**)&DAT_004e36d8)->indirect->renderer->FUN_001f42d0(&e->id,&name,location,(*(V*)&DAT_004e36e4),(*(V*)&DAT_004c7614),(*(V*)&DAT_004e36e4),6);
   name.FUN_0027af50();
  }
 }
}
} // namespace fn_001ed320

namespace fn_f014178b {

// 0x001eda90 FUN_001eda90 (98 B): matches/0x001eda90.cpp
// sym: ?FUN_001eda90@fn_f014178b@@YGXUTriple_1eda90@1@00@Z
// data: enabled = DAT_0049caa0, manager_1eda90 = DAT_004e36d8
void __stdcall FUN_001eda90(Triple_1eda90 a, Triple_1eda90 b, Triple_1eda90 c) {
    if (DAT_0049caa0)
        (*(Manager_1eda90**)&DAT_004e36d8)->Run_001ec900(a, b, c);
}

} // namespace fn_f014178b

// 0x001edb40 Method1<CSoundRealTimeManager,void,const_char_*>::vfunc_0 (30 B): matches/0x001edb40.cpp
// sym: ??_G?$Method1@VCSoundRealTimeManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSoundRealTimeManager, void, const char *>::~Method1() {}


// 0x001edb60 Method1<CSoundRealTimeManager,void,const_char_*>::vfunc_2 (19 B): matches/0x001edb60.cpp
// sym: ?vfunc_2@?$Method1@VCSoundRealTimeManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSoundRealTimeManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1edb60* d = (Dummy_1edb60*)a;
    (d->*(*(void (Dummy_1edb60::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSoundRealTimeManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1edb40)
#endif


// 0x001edbc0 Method0<CSoundRealTimeManager,void>::vfunc_0 (30 B): matches/0x001edbc0.cpp
// sym: ??_G?$Method0@VCSoundRealTimeManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CSoundRealTimeManager, void>::~Method0() {}


// 0x001edbe0 Method0<CSoundRealTimeManager,void>::vfunc_2 (12 B): matches/0x001edbe0.cpp
// sym: ?vfunc_2@?$Method0@VCSoundRealTimeManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<CSoundRealTimeManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1edbe0 * a = (CActorManager_1edbe0 *)__p0;

    (a->*(*(void (CActorManager_1edbe0::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Method0<CSoundRealTimeManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1edbc0)
#endif


// 0x001edc30 Method1<CSoundRealTimeManager,void,float>::vfunc_0 (30 B): matches/0x001edc30.cpp
// sym: ??_G?$Method1@VCSoundRealTimeManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSoundRealTimeManager, void, float>::~Method1() {}


// 0x001edc50 Method1<CSoundRealTimeManager,void,float>::vfunc_2 (19 B): matches/0x001edc50.cpp
// sym: ?vfunc_2@?$Method1@VCSoundRealTimeManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSoundRealTimeManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1edc50* d = (Dummy_1edc50*)a;
    (d->*(*(void (Dummy_1edc50::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSoundRealTimeManager, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1edc30)
#endif


// 0x001edcb0 Method1<CSoundRealTimeManager,void,bool>::vfunc_0 (30 B): matches/0x001edcb0.cpp
// sym: ??_G?$Method1@VCSoundRealTimeManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSoundRealTimeManager, void, bool>::~Method1() {}


// 0x001edcd0 Method1<CSoundRealTimeManager,void,bool>::vfunc_2 (21 B): matches/0x001edcd0.cpp
// sym: ?vfunc_2@?$Method1@VCSoundRealTimeManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<CSoundRealTimeManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1edcd0 * obj = (CActorManager_1edcd0 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_1edcd0 *)&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSoundRealTimeManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1edcb0)
#endif

namespace fn_f014178b {

// 0x001edcf0 FUN_001edcf0 (89 B): matches/0x001edcf0.cpp
// sym: ?Fn@Method3_1edcf0@fn_f014178b@@QAEPAV12@PADH@Z
Method3_1edcf0* Method3_1edcf0::Fn(char* p, hulk_intptr x) {
    Layout_1edcf0* s = (Layout_1edcf0*)this;
    Init_001d0480(p, 3);
    s->v = (void*)((hulk_intptr)DAT_00424398);
    s->m1c = x;
    s->b18 = Read_001d04d0((int*)((hulk_intptr)((char*)&DAT_0048e100)));
    s->b10 = Read_001d04d0((int*)((hulk_intptr)((char*)&DAT_0049cad8)));
    s->b11 = Read_001d04d0((int*)((hulk_intptr)((char*)&DAT_0049cad8)));
    s->b12 = Read_001d04d0((int*)((hulk_intptr)((char*)&DAT_0049cad8)));
    return this;
}

} // namespace fn_f014178b

// 0x001edd50 Method3<CSoundRealTimeManager,void,char_*,char_*,char_*>::vfunc_0 (30 B): matches/0x001edd50.cpp
// sym: ??_G?$Method3@VCSoundRealTimeManager@@XPADPADPAD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CSoundRealTimeManager, void, char *, char *, char *>::~Method3() {}


// 0x001edd70 Method3<CSoundRealTimeManager,void,char_*,char_*,char_*>::vfunc_2 (29 B): equivalent/0x001edd70.cpp
// sym: ?vfunc_2@?$Method3@VCSoundRealTimeManager@@XPADPADPAD@@UAEXPAX00@Z @a7a6d240b96d @w2ac42a573389
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CSoundRealTimeManager,void,char_*,char_*,char_*>::vfunc_2 @ 0x001edd70
template <> void Method3<CSoundRealTimeManager, void, char *, char *, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundRealTimeManager_1edd70 * manager = (CSoundRealTimeManager_1edd70 *)__p0; Args * args = (Args *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CSoundRealTimeManager_1edd70::**)(char *, char *, char *))&this->f_1c))(args->first, args->second, args->third);
}
#if defined(HULK_PTR64)
template class Method3<CSoundRealTimeManager, void, char *, char *, char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1edd50)
#endif


// 0x001eddd0 Method1<CSoundRealTimeManager,void,char_*>::vfunc_0 (30 B): matches/0x001eddd0.cpp
// sym: ??_G?$Method1@VCSoundRealTimeManager@@XPAD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSoundRealTimeManager, void, char *>::~Method1() {}


// 0x001eddf0 Method1<CSoundRealTimeManager,void,char_*>::vfunc_2 (19 B): matches/0x001eddf0.cpp
// sym: ?vfunc_2@?$Method1@VCSoundRealTimeManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSoundRealTimeManager, void, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1eddf0* d = (Dummy_1eddf0*)a;
    (d->*(*(void (Dummy_1eddf0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSoundRealTimeManager, void, char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1eddd0)
#endif

namespace fn_f014178b {

// 0x001ede10 FUN_001ede10 (102 B): matches/0x001ede10.cpp
// sym: ??0Method4_1ede10@fn_f014178b@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
Method4_1ede10::Method4_1ede10(const char* a, ScriptMemberFn b) : FUN_001d0480(a, 4) {
    vptr = (int*)((hulk_intptr)DAT_004243b8);
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
}

} // namespace fn_f014178b

// 0x001ede80 Method4<CSoundSimManager,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001ede80.cpp
// sym: ??_G?$Method4@VCSoundSimManager@@XPBDPBDPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CSoundSimManager, void, const char *, const char *, const char *, const char *>::~Method4() {}


// 0x001edea0 Method4<CSoundSimManager,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 (40 B): equivalent/0x001edea0.cpp
// sym: ?vfunc_2@?$Method4@VCSoundSimManager@@XPBDPBDPBDPBD@@UAEXPAX00@Z @06f2e20faa8a @we84ffb84b326
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method4<CSoundSimManager,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x001edea0
template <> void Method4<CSoundSimManager, void, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundSimManager_1edea0 * manager = (CSoundSimManager_1edea0 *)__p0; const char ** arguments = (const char **)__p1; void * unused = (void *)__p2;

 (manager->*(*(void (CSoundSimManager_1edea0::**)(const char *, const char *, const char *, const char *))&this->f_1c))(arguments[0], arguments[1], arguments[2], arguments[3]);
}
#if defined(HULK_PTR64)
template class Method4<CSoundSimManager, void, const char *, const char *, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ede80)
#endif


// 0x001edf20 Method2<CSoundSimManager,void,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001edf20.cpp
// sym: ??_G?$Method2@VCSoundSimManager@@XPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSoundSimManager, void, const char *, const char *>::~Method2() {}


// 0x001edf40 Method2<CSoundSimManager,void,const_char_*,const_char_*>::vfunc_2 (23 B): matches/0x001edf40.cpp
// sym: ?vfunc_2@?$Method2@VCSoundSimManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CSoundSimManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1edf40* m = (CFEManager_1edf40*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1edf40::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CSoundSimManager, void, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1edf20)
#endif

namespace fn_f014178b {

// 0x001edf60 FUN_001edf60 (179 B): matches/0x001edf60.cpp
// sym: ?FUN_001edf60@Boot@fn_f014178b@@QAEXXZ
// FUN_001edf60 @ 0x001edf60
void Boot::FUN_001edf60() {
    if ((*(unsigned char*)&DAT_004e36e0))
        return;
    ((owners::Manager_1eb060 *)(engine->loader))->FUN_001eb060((const char *)(hulk_uintptr)(int)0, (const char *)(hulk_uintptr)(int)0);
    engine->FUN_001efa40(1, "frontend", 0);
    float v = level;
    if (!(v < 0.0f) && !(v > 100.0f))
        ((owners::Obj_1f3950 *)(engine->volume))->FUN_001f3950(v);
    FUN_001ec480("", "Enter");
    FUN_001ec480("", "Boot");
    for (int i = 0; i < 10; i++) {
        if (active)
            engine->FUN_001f22f0(0.001f, 0);
    }
    (*(unsigned char*)&DAT_004e36e0) = 1;
}


// 0x001ee020 FUN_001ee020 (108 B): equivalent/0x001ee020.cpp
// sym: ?FUN_001ee020@S_1ee020@fn_f014178b@@QAEXXZ @9830bf6bf692 @wd113e84cc96a
// STATUS: equivalent (tools/equiv.py level 3: 3351 inputs, branch coverage 8/8)
// FUN_001ee020 @ 0x001ee020
void S_1ee020::FUN_001ee020(){
  (*(unsigned char*)&DAT_004e36e0) = 0;
  if (active) {
    ((ThisCall_001ec480*)(this))->FUN_001ec480(&DAT_003f335c, "EnterPreGame");
    while (a->b->FUN_001f4710()) {
      thunk_FUN_00270a50(); FUN_002656a0(); FUN_00240bb0();
      if (active) a->FUN_001f22f0(0.001f, 0);
    }
    a->FUN_001ef9c0(1);
  }
}


// 0x001ee090 FUN_001ee090 (138 B): matches/0x001ee090.cpp
// sym: ?Run@M_1ee090@fn_f014178b@@QAEXPAUA_1ee090@2@00H@Z
void M_1ee090::Run(A_1ee090* a, A_1ee090* b, A_1ee090* c, hulk_intptr d) {
    if (b && b->m128) {
        F1_001ecc80(a, b->m128, c, d);
    }
    if (a && a->m11c && b && b->m11c && c && c->s && c->s->Check_001d5040()) {
        F2_001ebd80(c, "impact_big", 100.0f, 0);
        F3_001ec980(b, "impact_big");
    }
}

} // namespace fn_f014178b

// 0x001ee120 FUN_001ee120 (76 B): matches/0x001ee120.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ee120@@QAE@HPAX0@Z
namespace fn_001ee120 {

class Function_1ee120 {
  public:
    virtual void F0();
    Function_1ee120(int, int);
};
extern "C++" __declspec(nothrow) unsigned char Check_001d04d0(const char*);
class Method1 : public Function_1ee120 {
  public:
    virtual bool FnF_001d04c0(int, int);
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    void* p;
    Method1(int v, void* q) : Function_1ee120(v, 1), p(q) {
        y = Check_001d04d0(((char*)&DAT_0048e100));
        x = Check_001d04d0(((char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void FnG_001ee190(void*, void*, void*);
    void* r;
    Closure1(int v, void* r0, void* q);
};
Closure1::Closure1(int v, void* r0, void* q) : Method1(v, q), r(r0) {}
} // namespace fn_001ee120


// 0x001ee170 Closure1<CSoundRealTimeManager,void,const_char_*>::vfunc_0 (30 B): matches/0x001ee170.cpp
// sym: ??_G?$Method1@VCSoundRealTimeManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSoundRealTimeManager, void, const char *>::~Closure1() {}


// 0x001ee190 Closure1<CSoundRealTimeManager,void,const_char_*>::vfunc_2 (18 B): matches/0x001ee190.cpp
// sym: ?vfunc_2@?$Closure1@VCSoundRealTimeManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSoundRealTimeManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ee190 * *)&this->f_20)->*(*(void (CActorManager_1ee190::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CSoundRealTimeManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ee170)
#endif


// 0x001ee1f0 Closure0<CSoundRealTimeManager,void>::vfunc_0 (30 B): matches/0x001ee1f0.cpp
// sym: ??_G?$Method1@VCSoundRealTimeManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CSoundRealTimeManager, void>::~Closure0() {}


// 0x001ee210 Closure0<CSoundRealTimeManager,void>::vfunc_2 (11 B): matches/0x001ee210.cpp
// sym: ?vfunc_2@?$Closure0@VCSoundRealTimeManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<CSoundRealTimeManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_1ee210 * *)&this->f_20)->*(*(void (CActorManager_1ee210::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Closure0<CSoundRealTimeManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ee1f0)
#endif


// 0x001ee220 FUN_001ee220 (76 B): matches/0x001ee220.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ee220@@QAE@PAX00@Z
namespace fn_001ee220 {

extern "C++" __declspec(nothrow) unsigned char __cdecl lookup_001d04d0(const void*);
class Function_1ee220 {
  public:
    Function_1ee220(void*, int);
    virtual void invoke();
    char pad[12];
    unsigned char b;
    char pad2[7];
    unsigned char a;
    char pad3[3];
    void* obj;
};
class Method1 : public Function_1ee220 {
  public:
    Method1(void* x, void* z) : Function_1ee220(x, 1) {
        obj = z;
        a = lookup_001d04d0(((int*)&DAT_0048e100));
        b = lookup_001d04d0(((int*)&DAT_0048e128));
    }
    virtual void invoke();
};
class Closure1 : public Method1 {
  public:
    Closure1(void*, void*, void*);
    virtual void invoke();
    void* fn;
};
Closure1::Closure1(void* x, void* y, void* z) : Method1(x, z) {
    fn = y;
}
} // namespace fn_001ee220


// 0x001ee270 Closure1<CSoundRealTimeManager,void,float>::vfunc_0 (30 B): matches/0x001ee270.cpp
// sym: ??_G?$Method1@VCSoundRealTimeManager@@XPAD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSoundRealTimeManager, void, float>::~Closure1() {}


// 0x001ee290 Closure1<CSoundRealTimeManager,void,float>::vfunc_2 (18 B): matches/0x001ee290.cpp
// sym: ?vfunc_2@?$Closure1@VCSoundRealTimeManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSoundRealTimeManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ee290 * *)&this->f_20)->*(*(void (CActorManager_1ee290::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CSoundRealTimeManager, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ee270)
#endif


// 0x001ee2b0 FUN_001ee2b0 (76 B): matches/0x001ee2b0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_001ee2b0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ee2b0 {
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

// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(const char* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_1ee2b0 : public Base {
  public:
    virtual void Invoke(bool);
    ScriptMemberFn fn;  // 0x1c
    Closure1_1ee2b0(const char* p, ScriptMemberFn r);
};
class Closure1 : public Closure1_1ee2b0 {
  public:
    virtual void Invoke(bool);
    void* owner;  // 0x20
    Closure1(const char* p, void* q, ScriptMemberFn r);
};
Closure1_1ee2b0::Closure1_1ee2b0(const char* p, ScriptMemberFn r) : Base(p) {
    fn = r;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
}
Closure1::Closure1(const char* p, void* q, ScriptMemberFn r) : Closure1_1ee2b0(p, r) {
    owner = q;
}
} // namespace fn_001ee2b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ee320 Closure1<CSoundRealTimeManager,void,bool>::vfunc_2 (20 B): matches/0x001ee320.cpp
// sym: ?vfunc_2@?$Closure1@VCSoundRealTimeManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<CSoundRealTimeManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_1ee320 * *)&this->f_20)->*(*(void (Actor_1ee320::**)(unsigned char))&this->f_1c))(*arg);
}


// 0x001ee390 Closure3<CSoundRealTimeManager,void,char_*,char_*,char_*>::vfunc_2 (28 B): matches/0x001ee390.cpp
// sym: ?vfunc_2@?$Closure3@VCSoundRealTimeManager@@XPADPADPAD@@UAEXPAX00@Z
template <> void Closure3<CSoundRealTimeManager, void, char *, char *, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { char *volatile * args = (char *volatile *)__p1;

    char* a = args[0];
    ((*(CSoundRealTimeManager_1ee390 * *)&this->f_20)->*(*(void (CSoundRealTimeManager_1ee390::**)(char *, char *, char *))&this->f_1c))(a, args[1], args[2]);
}


// 0x001ee3b0 FUN_001ee3b0 (76 B): matches/0x001ee3b0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_001ee3b0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ee3b0 {
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

// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(const char* x) : CtorV_001d0480(x, 1) { }
};
class Closure1_1ee3b0 : public Base {
  public:
    virtual void f();
    ScriptMemberFn p;  // 0x1c
    Closure1_1ee3b0(const char*, void*, ScriptMemberFn);
};
class Closure1 : public Closure1_1ee3b0 {
  public:
    virtual void f();
    void* q;  // 0x20
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1::Closure1(const char* x, void* y, ScriptMemberFn z) : Closure1_1ee3b0(x, y, z) {
    q = y;
}
Closure1_1ee3b0::Closure1_1ee3b0(const char* x, void* y, ScriptMemberFn z) : Base(x) {
    p = z;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0049cad8));
}
} // namespace fn_001ee3b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ee420 Closure1<CSoundRealTimeManager,void,char_*>::vfunc_2 (18 B): matches/0x001ee420.cpp
// sym: ?vfunc_2@?$Closure1@VCSoundRealTimeManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSoundRealTimeManager, void, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ee420 * *)&this->f_20)->*(*(void (CActorManager_1ee420::**)(const char *))&this->f_1c))(*b);
}


// 0x001ee490 Closure4<CSoundSimManager,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 (39 B): equivalent/0x001ee490.cpp
// sym: ?vfunc_2@?$Closure4@VCSoundSimManager@@XPBDPBDPBDPBD@@UAEXPAX00@Z @35da6a76506a @wb6eafd89dd0c
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CSoundSimManager,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x001ee490
template <> void Closure4<CSoundSimManager, void, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** args = (const char **)__p1; void * unused2 = (void *)__p2;
 ((*(CSoundSimManager_1ee490 * *)&this->f_20)->*(*(void (CSoundSimManager_1ee490::**)(const char *, const char *, const char *, const char *))&this->f_1c))(args[0], args[1], args[2], args[3]); }


// 0x001ee4c0 FUN_001ee4c0 (89 B): matches/0x001ee4c0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ee4c0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ee4c0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_004243c8[2];
extern void* hulk_at_0042446c[2];

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h),
// then Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_004243c8;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_0042446c;
    owner = a2;
}
} // namespace fn_001ee4c0


// 0x001ee540 Closure2<CSoundSimManager,void,const_char_*,const_char_*>::vfunc_2 (22 B): matches/0x001ee540.cpp
// sym: ?vfunc_2@?$Closure2@VCSoundSimManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CSoundSimManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1ee540 * p = (Pair_1ee540 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ee540 * *)&this->f_20)->*(*(void (CActorManager_1ee540::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x001ee5b0 FUN_001ee5b0 (109 B): equivalent/0x001ee5b0.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_001ee5b0@Registry_1ee5b0@fn_001ee5b0@@QAEXPBDPAVCSoundRealTimeManager@2@P832@AEXXZ@Z @30491622728a @wf87c26bde7eb
namespace fn_001ee5b0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001ee5b0 @ 0x001ee5b0
// FUN_001ee5b0 @ 0x001ee5b0  (generated by work/closure/gen.py)
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


class CSoundRealTimeManager { public: float FUN_dummy(); };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) MethodBase_1ee5b0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1ee5b0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1ee5b0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1ee5b0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_1ee5b0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001ee5b0(const char* name, CSoundRealTimeManager* owner, void (CSoundRealTimeManager::*fn)());
};

void Registry_1ee5b0::FUN_001ee5b0(const char* name, CSoundRealTimeManager* owner, void (CSoundRealTimeManager::*fn)()) {
    typedef Closure0<CSoundRealTimeManager, void> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CSoundRealTimeManager, void>));
    Closure0<CSoundRealTimeManager, void>* c = 0;
    if (mem)
        c = new (mem) Closure0<CSoundRealTimeManager, void>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001ee5b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f014178b {

// 0x001ee6c0 FUN_001ee6c0 (83 B): equivalent/0x001ee6c0.cpp
// sym: ?FUN_001ee6c0@Registry_1ee6c0@fn_f014178b@@QAEXPBDPAVCSoundRealTimeManager_1ee6c0@2@P832@AEXPAD22@Z@Z @327d247f4f43 @w13ae3f2c19ea
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001ee6c0 @ 0x001ee6c0
// FUN_001ee6c0 @ 0x001ee6c0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1ee6c0::FUN_001ee6c0(const char* a1, CSoundRealTimeManager_1ee6c0* a2, Fn_1ee6c0 a3) {
    typedef Closure3_1ee6c0<CSoundRealTimeManager_1ee6c0, void, char*, char*, char*> Alloc_1ee6c0;
    HULK_SIZE32(Alloc_1ee6c0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1ee6c0));
    void* x = 0;
    if (m) {
        ((Raw_1ee6c0*)m)->FUN_001edcf0(a1, a3);
        x = new (m) Closure3_1ee6c0<CSoundRealTimeManager_1ee6c0, void, char*, char*, char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001ee770 FUN_001ee770 (83 B): equivalent/0x001ee770.cpp
// sym: ?FUN_001ee770@Registry_1ee770@fn_f014178b@@QAEXPBDPAVCSoundSimManager_1ee770@2@P832@AEX0000@Z@Z @058bfe922f60 @w03fdad76a818
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001ee770 @ 0x001ee770
// FUN_001ee770 @ 0x001ee770  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1ee770::FUN_001ee770(const char* a1, CSoundSimManager_1ee770* a2, Fn_1ee770 a3) {
    typedef Closure4_1ee770<CSoundSimManager_1ee770, void, const char*, const char*, const char*, const char*> Alloc_1ee770;
    HULK_SIZE32(Alloc_1ee770, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1ee770));
    void* x = 0;
    if (m) {
        ((Raw_1ee770*)m)->FUN_001ede10(a1, a3);
        x = new (m) Closure4_1ee770<CSoundSimManager_1ee770, void, const char*, const char*, const char*, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f014178b

// 0x001eebc0 FUN_001eebc0 (139 B): equivalent/0x001eebc0.cpp [wrapped: macros]
// sym: ?Register@CSoundSimManager@fn_001eebc0@@QAEXXZ @84d9f26a9299 @we2c8ff18873f
namespace fn_001eebc0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 4/4)
// FUN_001eebc0 @ 0x001eebc0
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


void* FUN_0008d690(unsigned int);
class CSoundSimManager;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
// Function (include/decls/data/script.h): the vftable, then Function's fields; Method<N> adds the member-function
// pointer, Closure<N> the object.
class Base : public ScriptFunctionFields { public: virtual void v(); Base(const char*, int) throw(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Method4 : public Base { public: ScriptMemberFn f; Method4(const char* n, ScriptMemberFn x, const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Base(n, 4) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4 : public Method4<C, R, A1, A2, A3, A4> { public: C* owner; Closure4(const char* n, C* o, ScriptMemberFn f, const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Method4<C, R, A1, A2, A3, A4>(n, f, r, a1, a2, a3, a4) { owner = o; } virtual void v(); };
// The Method4 part is built by 0x001ede10 (below); this specialization only adds the object.
template<> class Closure4<CSoundSimManager, void, const char*, const char*, const char*, const char*> : public ScriptFunctionFields { public: virtual void v(); ScriptMemberFn fn; CSoundSimManager* owner; Closure4(CSoundSimManager* o) { owner = o; } };
class Registry { public:
    void FUN_001d3b70(const char*, void*);
};
class Entry { public:
    void* FUN_001ee4c0(const char*, CSoundSimManager*, ScriptMemberFn);
};
class Raw_001ede10 { public: void FUN_001ede10(const char*, ScriptMemberFn); };
Registry* FUN_001d4c90();
#define MF(b) reinterpret_cast<ScriptMemberFn>(&CSoundSimManager::FUN_##b)
#define M4(n, c, b, R, A1, A2, A3, A4) { typedef Closure4<CSoundSimManager, R, A1, A2, A3, A4> Closure_t; HULK_SIZE32(Closure_t, 0x24); void* m = FUN_0008d690((unsigned int)sizeof(Closure_t)); void* x = 0; if (m) { ((Raw_##c*)m)->FUN_##c(n, MF(b)); x = new (m) Closure_t(this); } r->FUN_001d3b70(n, x); }
#define E(n, c, b) { HULK_SIZE32(ScriptClosureView, 0x24); Entry* e = (Entry*)FUN_0008d690((unsigned int)sizeof(ScriptClosureView)); void* x = 0; if (e) x = e->FUN_##c(n, this, MF(b)); r->FUN_001d3b70(n, x); }

class CSoundSimManager {
public:
    // The member functions bound to Lua below.
    void FUN_001ecda0();
    void FUN_001ebd00();
    void Register();
    int i0;
};

void CSoundSimManager::Register() {
    Registry* r = FUN_001d4c90();
M4("snd_PlayFightDialogue", 001ede10, 001ecda0, Void, String, String, String, String)
E("snd_HUDEvent", 001ee4c0, 001ebd00)
}
} // namespace fn_001eebc0
#undef E
#undef M4
#undef MF
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

