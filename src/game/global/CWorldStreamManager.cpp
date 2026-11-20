// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00203870..0x00208b9c (kind game, layer game, confidence high), dominant class CWorldStreamManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "compat/fixedint.h"
#include "decls/address.h"
#include "decls/loaders.h"
#include "decls/load_inventory.h"
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/content.h"
#include "gen/global.h"
#include "gen/owners.h"
#include "gen/core.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f49dcb8d {
#define TREE_TU_END }
namespace fn_f49dcb8d {} using namespace fn_f49dcb8d;
void __cdecl operator delete[](void* p);   // (x64t21, D115) the game's 0x0008d340
namespace fn_f49dcb8d { extern "C" char DAT_00425b20[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"
#include "decls/managers.h"
#include "game/script_bind.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f49dcb8d {
struct RandState_2039a0 {
    unsigned int a;
    unsigned int b;
};
extern "C" RandState_2039a0* __cdecl FUN_000964d0();
class Obj_203a10 {
  public:
    bool FnA_00092dc0(int);
    bool FnB_00092de0(int);
};
class Manager_203a10 {
  public:
};
class Root_203a10 {
  public:
    char pad[0x54];
    Manager_203a10* mgr;
};
extern Root_203a10* hulk_at_004dd700;
struct Id_203cd0 { int a, b, c; };
struct Rec_203cd0 { char pad[0x54]; short value; };
struct Registry_203cd0 {
    Rec_203cd0* FUN_001c8060(Id_203cd0* id, void* tag);
    Rec_203cd0* FUN_001c81a0(Id_203cd0* id);
};
struct Holder_203cd0 { char pad[4]; Registry_203cd0* reg; };
struct Cursor_203cd0 { bool FUN_00059a50(Id_203cd0* out); };
struct Source_203cd0 { char pad[0x10]; Cursor_203cd0* cursor; };
struct Part_203cd0 { char pad[0x124]; Source_203cd0* src; };
struct Link_203cd0 { char pad[0x20]; Part_203cd0* part; };
struct Group_203cd0 { char pad[0xc]; Link_203cd0* link; };
Holder_203cd0* FUN_001c3d90();
struct Actor_203cd0 {
    char pad0[0x588]; Group_203cd0* group;
    char pad1[0xaf8 - 0x58c]; int busy;
    int GetValue();
};
} // namespace fn_f49dcb8d
struct Gfx {
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
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void aa();
    virtual void ab();
    virtual void ac();
    virtual void ad();
    virtual void ae();
    virtual void af();
    virtual void ag();
    virtual void ah();
    virtual void ai();
    virtual void aj();
    virtual void ak();
    virtual void al();
    virtual void am();
    virtual void an();
    virtual void ao();
    virtual void ap();
    virtual void aq();
    virtual void ar();
    virtual void as();
    virtual void at();
    virtual void au();
    virtual void av();
    virtual void aw();
    virtual void ax();
    virtual void ay();
    virtual void az();
    virtual void ba();
    virtual void bb();
    virtual void bc();
    virtual void bd();
    virtual void be();
    virtual void bf();
    virtual void bg();
    virtual void bh();
    virtual void bi();
    virtual void bj();
    virtual void bk();
    virtual void bl();
    virtual void bm();
    virtual void bn();
    virtual void bo();
    virtual void bp();
    virtual void bq();
    virtual void br();
    virtual void bs();
    virtual void bt();
    virtual void bu();
    virtual void bv();
    virtual void bw();
    virtual void bx();
    virtual void by();
    virtual void bz();
    virtual void ca();
    virtual void cb();
    virtual void cc();
    virtual void cd();
    virtual void ce();
    virtual void cf();
    virtual void cg();
    virtual void ch();
    virtual void ci();
    virtual void cj();
    virtual void ck();
    virtual void cl();
    virtual void cm();
    virtual void cn();
};
namespace fn_f49dcb8d {
struct Item_203e00 {
    void run_002665a0();
};
extern void helper();
struct CWorldStreamManager_203e00 {
    char pad[0x578];
    Item_203e00* items[1];
    void target(int index);
};
struct Manager_203e30 {
    int Get_00264870();
};
struct Waiter {
    bool Ready_00266750();
};
struct Target_203e30 {
    void Run(Waiter*);
};
extern "C" int32_t __cdecl FUN_00266da0(int32_t pool);   // (x64t16, D70) the heap id: a 32-bit integer
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);
struct Item_204180 {
    char data[0x56];
    void FUN_00208a90();
};
class ItemSet {
public:
    char pad0[0x58c];
    Item_204180* items;
    char pad1[8];
    int count;
    void FUN_00204180(int n);
};
struct Item {
  public:
    char _m_pad_0[0x56];
    short value;
    void Go_002660a0(void*);
};
struct Mgr {
    Item* Find_001c7f10(int);
};
struct Root {
    char pad[4];
    Mgr* volatile mgr;
};
Root* __cdecl GetRoot_001c3d90();
struct Sub_204350 {
    int Count_001c7520();
};
struct Item_204350 {
    char Check_001c6660(int*);
};
struct Obj_204350 {
    char pad[4];
    Obj_204350* child;
};
extern Obj_204350* GetQuery_001c3d90();
class CWorldStreamManager_204410 {
  public:
    char pad[0x5a4];
    signed char flags[0x400];
    int Find(int index);
};
struct CWorldStreamManager_204440 { char pad[0x5a4]; unsigned char flags[1024]; unsigned int FUN_00204440(int index); };
struct Entry_204540 {
    unsigned int data;
    unsigned char active;
    char name[55];
};
struct Registry_204540 {
    char padding[0x48];
    Entry_204540 primary[20];
    Entry_204540 secondary[2];
    Entry_204540* FUN_00204540(const char* name);
};
struct Record { char pad[0x56]; short value; };
struct Lookup { Record* FUN_001c7f10(int index); };
struct Provider { char pad[4]; Lookup* lookup; };
struct Game { char pad[0x5a4]; unsigned char states[0x400]; Provider* FUN_001c3d90(); bool FUN_002046b0(int value); };
class Obj {
    char a[0x44];
    void* m;
    char b[0x570 - 0x48];
    void* slots[2];

  public:
    void Add(void* p);
};
struct Resource_2047c0 { virtual void activate(); };
struct LoadInventory_nv_2047c0 {
    content::LoadInventory* FUN_00266480(void*);
};
extern "C" Resource_2047c0* __cdecl FUN_0026cfa0(void*, int, int, const char*);
extern "C" void __cdecl FUN_002670b0(int, int, Resource_2047c0*);
extern void* __cdecl FUN_00263ea0(unsigned int);
struct Object_2047c0 {
 char prefix[5]; char name[33]; short id; short count; char pad[2]; void* context; Resource_2047c0* resource; void* config; content::LoadInventory* helper;
 void FUN_002047c0(const char* text, int identifier, int mode, int amount);
};
struct Owner_204de0 {
    char pad[0x58c];
    void* ptr;
    char pad2[4];
    int a;
    int b;
};
struct Item_204de0 {
    char pad[0x56];
    void Destroy_00208ab0();
};
extern unsigned char hulk_at_004c91d8, hulk_at_004c91d9;
extern int __cdecl switchState_00266da0(int);
struct Item_204e40 {
    char pad[0x3c];
    void init_002047c0(const char*, int, int, int);
};
struct Obj_204e40 {
    char pad[0x48];
    Item_204e40 items[20];
    void run();
};
class Obj_204ea0 {
  public:
    virtual void a();
    virtual void release();
};
class Inner_204ea0 {
  public:
    void dispose_00263e90();
};
class A_204ea0 {
  public:
    char p0[4];
    unsigned char a, b;
    char p1[0x20];
    short value;
    char p2[4];
    void* ptr2c;
    Obj_204ea0* obj30;
    char p3[4];
    Inner_204ea0* ptr38;
    void close();
};
extern "C" void FUN_00267110(int);
extern void fptr_00267090(void*);
class Obj_204f00 {
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
    virtual int f11();
};
class S_204f00 {
  public:
    void run_00263e90();
};
class A_204f00 {
  public:
    char pad0[4];
    char flag;
    char pad5[0x21];
    short x26;
    short x28;
    char pad2a[6];
    Obj_204f00* p30;
    char gap34[4];
    Obj_204f00* p38;
    void finish_002047c0(char*, int, int, int);
};
extern char DAT_0048d5bc;
extern char DAT_004c9268;
class DynamicCasterBase {
  public:
    virtual void* Cast(void*);
};
class DynamicCaster : public DynamicCasterBase {
  public:
    virtual void* Cast(void*);
};
typedef unsigned int u32_205050;
class Dummy_2050d0 {
  public:
    void Call(void*);
};
extern "C" char DAT_00425b54[];
class Function_2050f0 {
  public:
    void Init_001d0480(const char*, int);
};
class Method3_2050f0 : public Function_2050f0 {
  public:
    Method3_2050f0(const char*, ScriptMemberFn);
    void* vf;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn mgr;      // 0x1c
};
struct CWorldStreamManager_205170 {
    bool FUN_00205170(float, float, float);
};
extern "C" char DAT_00425b64[];
struct B_2051b0 {
    void Init_001d0480(int, int);
};
class Method3_2051b0 {
  public:
    hulk_intptr vptr;
    char p04[12];
    char b10, b11, b12;
    char p13[5];
    char b18;
    char p19[3];
    int value1c;
    Method3_2051b0(hulk_intptr a, hulk_intptr b);
};
struct CWorldStreamManager_205230 {};
class Function_2052d0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CWorldStreamManager_205360 {
  public:
    int Invoke(int, int);
};
struct Args {
  public:
    union { int a; const char *name; };
    union { int b; int number; };
    bool flag;
    char _m_pad_9[0x3];
};
class Function_205360 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct CWorldStreamManager_2053f0 {};
struct Function_2053f0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Function_205470 {
  public:
    virtual void f0();
    virtual void f1();
};
class CWorldStreamManager_2054f0 {
  public:
    bool Work(int);
};
class Function_2054f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class CActorManager_205570;
typedef unsigned char(__fastcall* Fn_205570)(CActorManager_205570*);
class CActorManager_2055f0 {
  public:
    void f();
};
extern "C" char DAT_00425be4[];
class InitBase_205600 {
  public:
    void Init_001d0480(const char*, int);
};
class Method3_205600 {
  public:
    Method3_205600(const char*, ScriptMemberFn);
    hulk_intptr vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn f1c;      // 0x1c
};
struct CWorldStreamManager_205680 {};
struct Arguments {
  public:
    union { int first; const char* volatile name; };
    union { volatile int number; int second; };
    bool flag;
    char _m_pad_9[0x3];
};
struct Function_205680 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct LoadInventory_nv_205910 {
    content::LoadInventory* FUN_00266480(int);
};
extern "C" void __cdecl FUN_00266d90();
struct Texture_205910 {
 char pad[0x34];
 unsigned int size;
 char tail[4];
 void FUN_002047c0(const char*, int, int, int);
};
struct Object_205910 {
 char pad0[0x44];
 content::LoadInventory* resource;
 char pad1[0x4f8-0x48];
 Texture_205910 textures[2];
 char pad2[0xaf4-0x570];
 unsigned char flag;
 void FUN_00204e40();
 void target();
};
struct Resource_2059d0 { virtual void unused(); virtual void release(); void FUN_002665a0(); };
struct Handle_2059d0 { void FUN_00263e90(); };
extern void __cdecl FUN_00267090(void*);
struct Entry_2059d0 {
 unsigned char active, flag;
 char pad0[32];
 short id;
 char pad1[4];
 void* allocation;
 Resource_2059d0* resource;
 char pad2[4];
 Handle_2059d0* handle;
 char pad3[4];
};
struct Object {
 char pad[0x44];
 Resource_2059d0* mainResource;
 char pad1[4];
 Entry_2059d0 entries[20];
 union { Entry_2059d0 extra[2]; struct {char padding[116]; int values[2];} tail; };
 void cleanup();
};
class CActorManager_205c70 {
  public:
    void invoke(const char*);
};
struct CWorldStreamManager_205ce0;
typedef bool (__fastcall *StreamCallback)(CWorldStreamManager_205ce0 *, unsigned, float, float, float);
struct CWorldStreamManager_205d70 { int dummy; };
class CActorManager_205e10 {
  public:
    int act();
};
struct CWorldStreamManager_205eb0 { int method(int, int); };
class CWorldStreamManager_205f50 {};
class CActorManager_205fd0 {
  public:
    int act();
};
class CActorManager_2060e0;
typedef unsigned char(__fastcall* Fn_2060e0)(CActorManager_2060e0*);
class CActorManager_206160 {
  public:
    void run();
};
struct CWorldStreamManager_2061c0 {
    void FUN_002061c0(const char *, int, bool);
};
extern "C" char DAT_00425c28[];
extern void* __cdecl Alloc_00263ea0(unsigned int);
struct Loader_2062d0 : HulkChunkHandler {   // (sweep-allocsize) TransitionsLoader: the chunk handler's words (decls/loaders.h;
    void* owner;                             // natively its reader on 8 at +0x18) and the owner (allocated by its sizeof)
};
HULK_LOADER_SIZE32(Loader_2062d0, 0x18);
class Manager_2062d0 {
  public:
    void Register_00265210(Loader_2062d0*, unsigned int);
};
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f49dcb8d
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f49dcb8d {
class CWorldStreamManager_206c90 {};
typedef bool (CWorldStreamManager_206c90::*Fn_206c90)(float, float, float);
class Registry_206c90 { public:
    void FUN_00206c90(const char* a1, CWorldStreamManager_206c90* a2, Fn_206c90 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_206c90;
template<> class Closure3_206c90<CWorldStreamManager_206c90, bool, float, float, float> : public ScriptFunctionFields { public: virtual void* Fnv_00205cc0(int); Fn_206c90 fn; CWorldStreamManager_206c90* owner; Closure3_206c90(CWorldStreamManager_206c90* o) { owner = o; } };
class Raw_206c90 { public: void FUN_002050f0(const char*, Fn_206c90); };
class CWorldStreamManager_206cf0 {};
typedef int (CWorldStreamManager_206cf0::*Fn_206cf0)(float, float, float);
class Registry_206cf0 { public:
    void FUN_00206cf0(const char* a1, CWorldStreamManager_206cf0* a2, Fn_206cf0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_206cf0;
template<> class Closure3_206cf0<CWorldStreamManager_206cf0, int, float, float, float> : public ScriptFunctionFields { public: virtual void* Fnv_00205d50(int); Fn_206cf0 fn; CWorldStreamManager_206cf0* owner; Closure3_206cf0(CWorldStreamManager_206cf0* o) { owner = o; } };
class Raw_206cf0 { public: void FUN_002051b0(const char*, Fn_206cf0); };
class CWorldStreamManager_207000 {};
typedef void (CWorldStreamManager_207000::*Fn_207000)(const char*, int, bool);
class Registry_207000 { public:
    void FUN_00207000(const char* a1, CWorldStreamManager_207000* a2, Fn_207000 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_207000;
template<> class Closure3_207000<CWorldStreamManager_207000, void, const char*, int, bool> : public ScriptFunctionFields { public: virtual void v(); Fn_207000 fn; CWorldStreamManager_207000* owner; Closure3_207000(CWorldStreamManager_207000* o) { owner = o; } };
class Raw_207000 { public: void FUN_00205600(const char*, Fn_207000); };
class CAction_207060 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_207060* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CWorldStreamManager_207060 : public CAction_207060 {
  public:
    CWorldStreamManager_207060* vfunc_2(unsigned char);
};
struct CWorldStreamManager_nv_207060 {
    void FUN_002061e0();
};
extern void thunk_FUN_00267090(CWorldStreamManager_207060*);
struct Voice_2071e0 {
    virtual void v0();
    virtual void v1();
};
struct Stream {
    void *FUN_00266480(int size);
    void FUN_002660a0(Stream *first);
    virtual void v0();
    virtual void v1();
};
struct Handle_2071e0 {
    void FUN_00263e90();
};
struct Mgr54_2071e0 {
};
struct Dummy_2071e0 {
    void FUN_001b9020();
};
struct Mgr3c {
    int FUN_000d6f50();
    void FUN_000d7030(int v);
};
} // namespace fn_f49dcb8d
struct World {
    char pad0[0x3c];
    Mgr3c *mgr3c;          // 0x3c
    char pad40[0x54 - 0x40];
    Mgr54_2071e0 *mgr54;          // 0x54
};
namespace fn_f49dcb8d {
struct Slot_2071e0 {
    unsigned char used;            // 0x00
    unsigned char used2;           // 0x01
    char pad02[0x22 - 2];
    short id;                      // 0x22
    char pad24[4];
    void *buf;                     // 0x28
    Voice_2071e0 *voice;                  // 0x2c
    char pad30[4];
    Handle_2071e0 *handle;                // 0x34
    char pad38[4];
};
class Mixer {
public:
    char pad0[0x4c];
    Slot_2071e0 slots[20];                // 0x4c
    char pad4fc[0x578 - 0x4fc];
    Stream *streams[3];            // 0x578
    char pad584[0x5a4 - 0x584];
    unsigned char flags[0x400];    // 0x5a4
    int field9a4;                  // 0x9a4
    int count;                     // 0x9a8
    int ids[20];                   // 0x9ac
    int vals[20];                  // 0x9fc
    char pada4c[0xaf1 - 0xa4c];
    unsigned char ready;           // 0xaf1
    char padaf2[2];
    unsigned char dirty;           // 0xaf4

    int FUN_00204c10(int a);
    int FUN_00204ad0(int a, int *b);
    void FUN_00207080(int a);
    void FUN_002071e0(int n);
};
struct Slot_207410 {
    void FUN_00266220(int v);
};
struct Node_207410 {
    char pad0[0x38];
    Slot_207410 *slot;
    void FUN_00204f00();
};
struct LoadInventory_nv_207410 {
    int FUN_00266710();
    int FUN_00266700();
    void FUN_00263e90();
};
class Player_207410 {
public:
    char pad0[0x578];
    Slot_207410 *slots[3];
    int curSlot;
    char pad588[0xaec - 0x588];
    content::LoadInventory *stream;
    char busy;
    char pad_af1;
    char pending;
    char locked;

    int FUN_00203a80();
    Node_207410 *FUN_00204540(int a);
    int FUN_00203bb0();
    void FUN_00204720(int v);
    void FUN_002067d0(int v, int w);
    char FUN_00207410();
};
extern "C" void __stdcall FUN_00203e30(void*);
class Sub_2078f0 {
  public:
    int Check_00266710();
    int Other_002666e0();
};
class Obj_2078f0 {
  public:
    char pad[0xaec];
    Sub_2078f0* m;
    char flag;
    char Run(char);
    void Do_00203e30(Sub_2078f0*);
    char Finish_00207410();
};
struct CWorldStreamManager_nv_207b90 {
    void FUN_002071e0(int);
};
struct Sink_208040 {
};
struct Table_208040 {
    char pad[0x588];
    Sink_208040 *sink;
    // equiv-conv absent: plain thiscall members
    void FUN_00207e80();
    void FUN_00207a00(unsigned short *entry);
    bool FUN_00208040(int a, int b);
};
class Subject_208820 {
  public:
    int GetState_00266710();
    void OnGlobal_002666e0();
};
struct CWorldStreamManager_nv_208820 {
    void OnState_00207410();
    void OnOther_00203e30(Subject_208820*);
    void Step1_002080b0();
    void Step2_00207d80();
    void Step3_00207e80();
    void Step4_00204de0();
    void Step5_002059d0();
};
class Releasable_2088a0 {
public:
    virtual void v0();
    virtual void Release();
};
struct Buffer_2088a0 {
    void FUN_00263e90();
};
struct Slot_2088a0 {
    unsigned char active;       // +0x00
    unsigned char ready;        // +0x01
    char pad02[0x20];
    short handle;               // +0x22
    char pad24[4];
    char *name;                 // +0x28
    Releasable_2088a0 *resource;       // +0x2c
    char pad30[4];
    Buffer_2088a0 *buffer;             // +0x34
    char pad38[4];
};
void __cdecl FUN_00267090(char *p);
class Pool_2088a0 {
public:
    void FUN_002088a0();
    void FUN_00207e80();

    char pad0[0x4c];
    Slot_2088a0 slots[20];             // +0x4c
    char pad4fc[0xaf4 - 0x4fc];
    char cleared;               // +0xaf4
};
int FUN_00267f80();
struct S_208a90 {
    unsigned short a;
    unsigned short b;
    unsigned char c;
    unsigned char d;
    S_208a90();
};

} // namespace fn_f49dcb8d

// 0x00203870 FUN_00203870 (25 B): matches/0x00203870.cpp
// sym: ?FUN_00203870@Target_203870@owners@@QAEXPAD@Z
void owners::Target_203870::FUN_00203870(char* p) {
    strncpy((char*)this + 0xaa4, p, 0x20);
}


// 0x00203890 FUN_00203890 (206 B): equivalent/0x00203890.cpp
// sym: ?FUN_00203890@Object_203890@owners@@QAEXH@Z @cfa221d435d8 @wcabcb086c82e @v36396a62ac60
// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 18/19, incomplete)
// FUN_00203890 @ 0x00203890
void owners::Object_203890::FUN_00203890(int index) {
 switch (index) {
 case 0: FUN_00203870("hulk_australia"); break;
 case 1: FUN_00203870("grey_hulk"); break;
 case 2: FUN_00203870("joefixit"); break;
 case 3: FUN_00203870("abomination_ashulk"); break;
 case 4: FUN_00203870("banner_savage"); break;
 case 5: FUN_00203870("hulk_canada"); break;
 case 6: FUN_00203870("hulk_us"); break;
 case 7: FUN_00203870("hulk_uk"); break;
 case 8: FUN_00203870("hulk_france"); break;
 case 9: FUN_00203870("hulk_german"); break;
 case 10: FUN_00203870("hulk_italy"); break;
 case 11: FUN_00203870("hulk_spain"); break;
 case 12: FUN_00203870("hulk_japan"); break;
 }
}


// 0x002039a0 FUN_002039a0 (100 B): matches/0x002039a0.cpp
// sym: ?FUN_002039a0@Obj_2039a0@owners@@QAEXHH@Z
void owners::Obj_2039a0::FUN_002039a0(int lo, int hi) {
    RandState_2039a0* p = FUN_000964d0();
    unsigned int* pa = &p->a;
    unsigned int* pb = &p->b;
    *pa = (*pa & 0xffff) * 0x9069 + (*pa >> 16);
    *pb = (*pb & 0xffff) * 0x4650 + (*pb >> 16);
    unsigned int value = (*pa << 16) + (*pb & 0xffff);
    Set(value % (hi - lo + 1) + lo);
}


// 0x00203a10 FUN_00203a10 (100 B): matches/0x00203a10.cpp
// sym: ?FUN_00203a10@C_203a10@owners@@QAEXXZ
void owners::C_203a10::FUN_00203a10() {
    strncpy(name, "hulk", 0x20);
    Obj_203a10* o = ((Obj_203a10 *)((owners::A_86340 *)(hulk_at_004dd700->mgr))->FUN_00086340());
    if (o != 0) {
        int i = 0;
        while (o->FnA_00092dc0(i) || !o->FnB_00092de0(i)) {
            ++i;
            if (i > 12)
                return;
        }
        if (i != -1)
            Apply(i);
    }
}

namespace fn_f49dcb8d {

// 0x00203cd0 FUN_00203cd0 (138 B): equivalent/0x00203cd0.cpp
// sym: ?GetValue@Actor_203cd0@fn_f49dcb8d@@QAEHXZ @243694e42754 @wa0699d733520 @vc8d0c6caa507
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 14/14)
// FUN_00203cd0 @ 0x00203cd0
int Actor_203cd0::GetValue() {
    if (busy > 0) return busy;
    Link_203cd0* l = group->link;
    if (!l) return 0;
    Part_203cd0* part = l->part;
    if (!part) return 0;
    Source_203cd0* src = part->src;
    if (!src) return 0;
    Registry_203cd0* reg = ((Registry_203cd0*)FUN_001c3d90()->reg);
    Id_203cd0 id;
    if (!src->cursor->FUN_00059a50(&id)) return 0;
    Rec_203cd0* r = reg->FUN_001c8060(&id, DAT_004e5a88);
    if (!r) r = reg->FUN_001c81a0(&id);
    if (!r) return 0;
    return r->value;
}

} // namespace fn_f49dcb8d

// 0x00203d60 FUN_00203d60 (14 B): matches/0x00203d60.cpp
// sym: ?FUN_00203d60@C_203d60@owners@@QAEHH@Z
hulk_intptr owners::C_203d60::FUN_00203d60(int index) {
    return *(int*)((char*)this + 0x578 + index * 4);
}


// 0x00203d70 FUN_00203d70 (4 B): matches/0x00203d70.cpp
// sym: ?FUN_00203d70@Target_203d70@owners@@QAEHXZ
hulk_intptr owners::Target_203d70::FUN_00203d70() {
    return value;
}


// 0x00203db0 FUN_00203db0 (69 B): matches/0x00203db0.cpp
// sym: ?FUN_00203db0@Obj_203db0@owners@@QAEHH@Z
// data: g_flag_203db0 = DAT_004c91d9
hulk_intptr owners::Obj_203db0::FUN_00203db0(hulk_intptr key) {
    int result = 0;
    if ((*(unsigned char*)((char*)&DAT_004c91d8 + 1))) {
        int i;
        for (i = 0; i < 2; ++i) {
            if (keys[i] == ((int)key)) {
                if (i >= 0)
                    result = *(int*)((char*)this + 0x530 + i * 0x3c);
                break;
            }
        }
    }
    return result;
}

namespace fn_f49dcb8d {

// 0x00203e00 FUN_00203e00 (41 B): matches/0x00203e00.cpp
// sym: ?target@CWorldStreamManager_203e00@fn_f49dcb8d@@QAEXH@Z
void CWorldStreamManager_203e00::target(int index) {
    DAT_0052c2a8->cn();
    if (items[index])
        items[index]->run_002665a0();
}


// 0x00203e30 FUN_00203e30 (81 B): matches/0x00203e30.cpp
// sym: ?Run@Target_203e30@fn_f49dcb8d@@QAEXPAUWaiter@2@@Z
// data: gManager_203e30 = DAT_00527c58
void Target_203e30::Run(Waiter* w) {
    int old = (*(Manager_203e30**)&DAT_00527c58)->Get_00264870();
    ((owners::C_264860 *)((*(Manager_203e30**)&DAT_00527c58)))->FUN_00264860(250000);
    while (!w->Ready_00266750())
        FUN_00087990();
    ((owners::C_264860 *)((*(Manager_203e30**)&DAT_00527c58)))->FUN_00264860(old);
}

} // namespace fn_f49dcb8d

// 0x00204060 FUN_00204060 (91 B): matches/0x00204060.cpp
// sym: ?FUN_00204060@Owner_204060@owners@@QAEPAFHH@Z
short* owners::Owner_204060::FUN_00204060(int a, int b) {
    if (a < 0 || b < 0)
        return 0;
    int i = 0;
    if (count > 0) {
        short* p = items;
        do {
            if (a == p[0] && b == p[1])
                return items + i * 0x2b;
            ++i;
            p += 0x2b;
        } while (i < count);
    }
    return 0;
}

namespace fn_f49dcb8d {

// 0x00204180 FUN_00204180 (122 B): equivalent/0x00204180.cpp
// sym: ?FUN_00204180@ItemSet@fn_f49dcb8d@@QAEXH@Z @232fe2c03850 @w41a45b819eae @vea25fbb14505
// STATUS: equivalent (tools/equiv.py level 3: 383 inputs, branch coverage 6/6)
// FUN_00204180 @ 0x00204180
void ItemSet::FUN_00204180(int n) {
    int savedPool = FUN_00266da0(0xb);
    int* block = (int*)FUN_0008d6d0(n * sizeof(Item_204180) + 4);
    Item_204180* arr;
    if (block) {
        *block = n;
        arr = (Item_204180*)(block + 1);
        Item_204180* p = arr;
        for (int i = n; i > 0; i--) {
            p->FUN_00208a90();
            p++;
        }
    } else {
        arr = 0;
    }
    items = arr;
    count = n;
    FUN_00266da0(savedPool);
}

} // namespace fn_f49dcb8d

// 0x00204200 FUN_00204200 (147 B): equivalent/0x00204200.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_00204200@CB_00204200@fn_00204200@@QAEHMMM@Z @fe4fe39b16bb @w61d800e8a942 @v5ed186384713
namespace fn_00204200 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00204200 @ 0x00204200
struct Query_204200 {
    int a;
    int b;
    int c;
};

struct Item_204200 {
    char pad0[0x54];
    short index;
    bool FUN_001c6660(Query_204200 *query);
};

struct Counter_204200 {
    int FUN_001c7520();
};

class Items_204200 {
public:
    char pad0[0x18];
    Counter_204200 counter;
};

struct Sys_204200 {
    int pad0;
    Items_204200 *items;
};

Sys_204200 *__cdecl FUN_001c3d90();

// (script2) a member of CWorldStreamManager (other callers call it on the manager; bound as Closure3<CWorldStreamManager,
// int,float,float,float>; this unused); was `int __stdcall FUN_00204200(int a, int b, int c)`
struct CB_00204200 { int FUN_00204200(float, float, float); };
int CB_00204200::FUN_00204200(float a, float b, float c)
{
    if (FUN_001c3d90() == 0 || FUN_001c3d90()->items == 0) {
        return -1;
    }
    Items_204200 *items = FUN_001c3d90()->items;
    int count = items->counter.FUN_001c7520();
    Query_204200 q;
    q.a = *(int*)&a;
    q.b = *(int*)&b;
    q.c = *(int*)&c;
    for (int i = 0; i < count; i++) {
        Item_204200 *item = ((Item_204200 *)((owners::Thing_1c7f80 *)items)->FUN_001c7f80((unsigned int)i));
        if (item != 0 && item->FUN_001c6660(&q)) {
            return item->index;
        }
    }
    return -1;
}
} // namespace fn_00204200


// 0x002042a0 FUN_002042a0 (79 B): matches/0x002042a0.cpp
// sym: ?FUN_002042a0@CWorldStreamManager@@QAEHHH@Z
int CWorldStreamManager::FUN_002042a0(int nth, int key) {
    int n = this->f_594;
    int found = 0;
    int i = 0;
    if (n > 0) {
        short* base = (*(short * *)&this->f_58c);
        short* p = base;
        do {
            if (*p == key) {
                if (found == nth)
                    return base[i * 0x2b + 1];
                ++found;
            }
            ++i;
            p += 0x2b;
        } while (i < n);
    }
    return -1;
}


// 0x002042f0 FUN_002042f0 (43 B): matches/0x002042f0.cpp [wrapped: lost its match in the tree (codegen differs (2 of 18 instructions))]
// sym: ?Find@CWorldStreamManager_2042f0@fn_002042f0@@QAEHH@Z
namespace fn_002042f0 {
struct Item {
    short id;
    char pad[0x54];
};
class CWorldStreamManager_2042f0 {
    char pad[0x58c];
    Item* items;
    char pad2[4];
    int count;

  public:
    int Find(int id);
};
int CWorldStreamManager_2042f0::Find(int id) {
    int n = 0;
    for (int i = 0; i < count; i++)
        if (items[i].id == id)
            ++n;
    return n;
}
} // namespace fn_002042f0

namespace fn_f49dcb8d {

// 0x00204320 FUN_00204320 (37 B): matches/0x00204320.cpp
// sym: ?FUN_00204320@CB_00204320@fn_f49dcb8d@@QAEHH@Z
// (script2) bound as a member (Closure/Method; this unused): the site's types; was `int __stdcall FUN_00204320(int id)`
struct CB_00204320 { int FUN_00204320(int); };
int CB_00204320::FUN_00204320(int id) {
    Root* r = GetRoot_001c3d90();
    Mgr* m = r->mgr;
    Item* item = m->Find_001c7f10(id);
    if (!item)
        return -1;
    return item->value;
}


// 0x00204350 FUN_00204350 (143 B): matches/0x00204350.cpp
// sym: ?FUN_00204350@CB_00204350@fn_f49dcb8d@@QAE_NMMM@Z
// (script2) bound as CWorldStreamManager's member (Closure3<CWorldStreamManager,bool,float,float,float>; this unused); was
// `char __stdcall Target(int a, int b, int c)`
struct CB_00204350 { bool FUN_00204350(float, float, float); };
bool CB_00204350::FUN_00204350(float a, float b, float c) {
    Obj_204350* q = GetQuery_001c3d90();
    if (!q)
        return 0;
    q = GetQuery_001c3d90();
    Obj_204350* h = q->child;
    if (!h)
        return 0;
    q = GetQuery_001c3d90();
    h = q->child;
    int n = ((Sub_204350*)((char*)h + 0x18))->Count_001c7520();
    int args[3];
    args[0] = *(int*)&a;
    args[1] = *(int*)&b;
    args[2] = *(int*)&c;
    for (int i = 0; i < n; ++i) {
        q = GetQuery_001c3d90();
        h = q->child;
        Item_204350* item = (Item_204350*)((hulk_intptr)((owners::Thing_1c7f80 *)h)->FUN_001c7f80((unsigned int)i));
        if (item && item->Check_001c6660(args))
            return 1;
    }
    return 0;
}


// 0x002043e0 FUN_002043e0 (47 B): matches/0x002043e0.cpp
// sym: ?FUN_002043e0@fn_f49dcb8d@@YIHH@Z
int __fastcall FUN_002043e0(hulk_intptr object) {
    int count = 0;
    unsigned char* p = (unsigned char*)(object + 0x5a5);
    int n = 0x100;
    do {
        if (p[-1] == 1)
            ++count;
        if (p[0] == 1)
            ++count;
        if (p[1] == 1)
            ++count;
        if (p[2] == 1)
            ++count;
        p += 4;
        --n;
    } while (n != 0);
    return count;
}


// 0x00204410 FUN_00204410 (46 B): matches/0x00204410.cpp
// sym: ?Find@CWorldStreamManager_204410@fn_f49dcb8d@@QAEHH@Z
int CWorldStreamManager_204410::Find(int index) {
    int count = 0;
    int i = 0;
    do {
        if (flags[i] == 1) {
            if (count == index)
                return i;
            ++count;
        }
        ++i;
    } while (i < 0x400);
    return -1;
}


// 0x00204440 FUN_00204440 (48 B): equivalent/0x00204440.cpp
// sym: ?FUN_00204440@CWorldStreamManager_204440@fn_f49dcb8d@@QAEIH@Z @15bece14bb11 @w5bd92076019c @v048131b84836
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00204440 @ 0x00204440
unsigned int CWorldStreamManager_204440::FUN_00204440(int index) { if (index < 0 || index >= 1024) return (unsigned int)index & 0xffffff00u; unsigned char value = flags[index]; return value == 1 || value == 3; }

} // namespace fn_f49dcb8d

// 0x00204470 FUN_00204470 (42 B): matches/0x00204470.cpp
// sym: ?FUN_00204470@C_204470@owners@@QAE_NH@Z
bool owners::C_204470::FUN_00204470(hulk_intptr i) {
    if (((int)i) < 0)
        return false;
    if (((int)i) >= 0x400)
        return false;
    return a[((int)i)] == 2;
}

namespace fn_f49dcb8d {

// 0x00204540 FUN_00204540 (211 B): equivalent/0x00204540.cpp
// sym: ?FUN_00204540@Registry_204540@fn_f49dcb8d@@QAEPAUEntry_204540@2@PBD@Z @1afc8dfb445e @w5834e524c9e2 @ve12dd44ba22f
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 28/28)
// FUN_00204540 @ 0x00204540
Entry_204540* Registry_204540::FUN_00204540(const char* name) {
    for (int i = 0; i < 20; ++i) {
        const unsigned char* a = (const unsigned char*)name;
        const unsigned char* b = (const unsigned char*)primary[i].name;
        while (*a == *b && *a) { ++a; ++b; }
        if (*a == *b && primary[i].active != 0) return &primary[i];
    }
    for (int j = 0; j < 2; ++j) {
        const unsigned char* a = (const unsigned char*)name;
        const unsigned char* b = (const unsigned char*)secondary[j].name;
        while (*a == *b && *a) { ++a; ++b; }
        if (*a == *b && secondary[j].active != 0) return &secondary[j];
    }
    return 0;
}


// 0x002046b0 FUN_002046b0 (99 B): equivalent/0x002046b0.cpp
// sym: ?FUN_002046b0@Game@fn_f49dcb8d@@QAE_NH@Z @5ce6c4729c20 @w08210f02f521 @v6f8546d9a182
// STATUS: equivalent (tools/equiv.py level 3: 702 inputs, branch coverage 12/12)
// FUN_002046b0 @ 0x002046b0
bool Game::FUN_002046b0(int value) {
    Lookup* lookup = FUN_001c3d90()->lookup;
    for (int i = 0; i < 0x400; ++i) {
        unsigned char state = states[i];
        if (state == 1 || state == 3 || state == 2) {
            Record* record = lookup->FUN_001c7f10(i);
            if (record && record->value == value) return true;
        }
    }
    return false;
}


// 0x00204720 FUN_00204720 (59 B): matches/0x00204720.cpp
// sym: ?Add@Obj@fn_f49dcb8d@@QAEXPAX@Z
void Obj::Add(void* p) {
    int i = 0;
    void** q = slots;
    do {
        if (!*q) {
            slots[i] = p;
            break;
        }
        ++i;
        ++q;
    } while (i < 2);
    ((Item *)((owners::Obj_203db0 *)this)->FUN_00203db0((hulk_intptr)p))->Go_002660a0(m);
}

} // namespace fn_f49dcb8d

// 0x00204760 FUN_00204760 (48 B): matches/0x00204760.cpp
// sym: ?FUN_00204760@Thing_204760@owners@@QAEXH@Z
void owners::Thing_204760::FUN_00204760(int value) {
    for (int i = 0; i < 2; ++i) {
        if (slots[i] == value) {
            slots[i] = 0;
            return;
        }
    }
}

namespace fn_f49dcb8d {

// 0x002047c0 FUN_002047c0 (187 B): equivalent/0x002047c0.cpp
// sym: ?FUN_002047c0@Object_2047c0@fn_f49dcb8d@@QAEXPBDHHH@Z @9dfc930d970d @wc3d9afee575e @v6e2231ea4777
// STATUS: equivalent (tools/equiv.py level 3: 20011 inputs, branch coverage 8/8)
// FUN_002047c0 @ 0x002047c0
void Object_2047c0::FUN_002047c0(const char* text, int identifier, int mode, int amount) {
 if(id != 0) return;
 id = (short)identifier;
 count = (short)amount;
 char* dest = name;
 do { *dest++ = *text; } while (*text++ != 0);
 if (!context) context = FUN_00266e00(amount, mode);
 resource = FUN_0026cfa0(context, mode, amount, name);
 resource->activate();
 FUN_002670b0(id, amount, resource);
 int old = FUN_00266da0(id);
 content::LoadInventory* p = (content::LoadInventory*)FUN_00263ea0(HULK_LOADINVENTORY_SIZE);
 if(p) p = ((LoadInventory_nv_2047c0*)(((content::LoadInventory*)(p))))->FUN_00266480(config);
 helper = p;
 helper->vfunc_0();
 FUN_00266da0(old);
}

} // namespace fn_f49dcb8d

// 0x00204ad0 FUN_00204ad0 (308 B): equivalent/0x00204ad0.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_00204ad0@Owner_204ad0@fn_00204ad0@@QAEHHPAH@Z @18b669427b21 @w922a1363e12a @v0390919b7a77
namespace fn_00204ad0 {
// STATUS: equivalent (tools/equiv.py level 3: 19273 inputs, branch coverage 20/20)
// FUN_00204ad0 @ 0x00204ad0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_204ad0 {
    float x, y, z;
};

struct Item_204ad0 {
    char pad00[9];
    char skip;
    char pad0a[0x20 - 0xa];
    Vec3_204ad0 pos;
    char pad2c[0x54 - 0x2c];
    short id;
};

struct ItemSub {
    int FUN_001c7520();
};

struct ItemList_204ad0 {
    char pad00[0x18];
    ItemSub sub;
};

struct Manager_204ad0 {
    char pad00[4];
    ItemList_204ad0 *items;
};

struct Position_204ad0 {
    void FUN_00059a50(Vec3_204ad0 *out);
};

struct Anchor_204ad0 {
    char pad00[0x10];
    Position_204ad0 *position;
};

struct Node3 {
    char pad00[0x124];
    Anchor_204ad0 *anchor;
};

struct Node2_204ad0 {
    char pad00[0x20];
    Node3 *c;
};

struct Mid_204ad0 {
    char pad00[0xc];
    Node2_204ad0 *b;
};

struct Owner_204ad0 {
    char pad00[0x588];
    Mid_204ad0 *mid;
    char pad58c[0x59c - 0x58c];
    int excludedId;
    char pad5a0[4];
    char flags[1];
    int FUN_00204ad0(int count, int *ignore);
};

Manager_204ad0 *FUN_001c3d90();

int Owner_204ad0::FUN_00204ad0(int count, int *ignore)
{
    Node3 *c = mid->b->c;
    Anchor_204ad0 *anchor = c->anchor;
    if (anchor == 0)
        return -1;
    Vec3_204ad0 origin;
    anchor->position->FUN_00059a50(&origin);
    ItemList_204ad0 *items = FUN_001c3d90()->items;
    int total = items->sub.FUN_001c7520();
    int bestId = -1;
    hulk_freg bestDist = -999999.0f;
    for (int i = 0; i < total; i++) {
        Item_204ad0 *it = ((Item_204ad0 *)((owners::Thing_1c7f80 *)items)->FUN_001c7f80(i));
        if (it->skip != 0)
            continue;
        int id = it->id;
        bool ignored = false;
        for (int k = 0; k < count; k++) {
            if (id == ignore[k]) {
                ignored = true;
                break;
            }
        }
        if (ignored)
            continue;
        if (id == excludedId || flags[id] != 1)
            continue;
        hulk_freg dx = it->pos.x - origin.x;
        hulk_freg dy = it->pos.y - origin.y;
        hulk_freg dz = it->pos.z - origin.z;
        double dist = sqrt((double)(dx * dx + dy * dy + dz * dz));
        if (dist > bestDist) {
            bestDist = (float)dist;
            bestId = id;
        }
    }
    return bestId;
}
} // namespace fn_00204ad0


// 0x00204c10 FUN_00204c10 (347 B): equivalent/0x00204c10.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_00204c10@Finder_204c10@fn_00204c10@@QAEHD@Z @9e7ae45e3786 @w43389eb2ba0a @v297e774051e8
namespace fn_00204c10 {
// STATUS: equivalent (tools/equiv.py level 3: 19593 inputs, branch coverage 28/28)
// FUN_00204c10 @ 0x00204c10

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_204c10 {
    float x, y, z;
};

class Node {
public:
    char pad0[0x10];
    class Locator *loc;
};

class Locator {
public:
    char FUN_00059a50(Vec3_204c10 *out);
};

struct Item_204c10 {
    char pad0[0x20];
    Vec3_204c10 pos;
    char pad1[0x54 - 0x2c];
    short index;
};

struct Info_204c10 {
    char pad0[9];
    char blocked;
};

struct Counter_204c10 {
    int FUN_001c7520();
};

class Items_204c10 {
public:
    char pad0[0x18];
    Counter_204c10 counter;
    Info_204c10 *FUN_001c7f10(int index);
};

struct Sys_204c10 {
    int pad0;
    Items_204c10 *items;
};

Sys_204c10 *FUN_001c3d90();

struct Level3_204c10 {
    char pad0[0x124];
    Node *node;
};

struct Level2_204c10 {
    char pad0[0x20];
    Level3_204c10 *l3;
};

struct Level1_204c10 {
    char pad0[0xc];
    Level2_204c10 *l2;
};

class Finder_204c10 {
public:
    char pad0[0x588];
    Level1_204c10 *l1;
    char pad1[0x5a4 - 0x58c];
    char kind[1];
    int FUN_00204c10(char wantNear);
};

int Finder_204c10::FUN_00204c10(char wantNear)
{
    Node *node = l1->l2->l3->node;
    if (node == 0)
        return -1;
    Vec3_204c10 origin;
    node->loc->FUN_00059a50(&origin);
    Items_204c10 *items = FUN_001c3d90()->items;
    int count = items->counter.FUN_001c7520();
    int bestIndex = -1;
    hulk_freg bestDist = wantNear ? 999999.0f : -999999.0f;
    for (int i = 0; i < count; i++) {
        Item_204c10 *item = ((Item_204c10 *)((owners::Thing_1c7f80 *)items)->FUN_001c7f80((unsigned int)i));
        int idx = item->index;
        char k = kind[idx];
        if ((k == 2 && wantNear) || (k == 3 && !wantNear)) {
            Vec3_204c10 p = item->pos;
            hulk_freg dx = p.x - origin.x;
            hulk_freg dy = p.y - origin.y;
            hulk_freg dz = p.z - origin.z;
            hulk_freg d = (float)sqrt(dy * dy + dz * dz + dx * dx);
            if (d < bestDist) {
                if (wantNear) {
                    bestDist = d;
                    bestIndex = idx;
                }
            } else if (d > bestDist && !wantNear) {
                Info_204c10 *info = FUN_001c3d90()->items->FUN_001c7f10(idx);
                if (info == 0 || info->blocked == 0) {
                    bestDist = d;
                    bestIndex = idx;
                }
            }
        }
    }
    return bestIndex;
}
} // namespace fn_00204c10

namespace fn_f49dcb8d {

// 0x00204de0 FUN_00204de0 (84 B): matches/0x00204de0.cpp
// sym: ?target@fn_f49dcb8d@@YIXPAUOwner_204de0@1@@Z
void __fastcall target(Owner_204de0* self) {
    char* p = (char*)self->ptr;
    if (p != 0) {
        int n = *(int*)(p - 4);
        Item_204de0* q = (Item_204de0*)(p + n * 0x56);
        while (--n >= 0) {
            q = (Item_204de0*)((char*)q - 0x56);
            q->Destroy_00208ab0();
        }
        ::operator delete[](p - 4);
    }
    self->ptr = 0;
    self->a = 0;
    self->b = 0;
}


// 0x00204e40 FUN_00204e40 (93 B): matches/0x00204e40.cpp
// sym: ?run@Obj_204e40@fn_f49dcb8d@@QAEXXZ
void Obj_204e40::run() {
    if (hulk_at_004c91d8) {
        int id = 0x13 + (hulk_at_004c91d9 != 0 ? 2 : 0);
        int old = switchState_00266da0(7);
        for (int i = 0; i < 20; i++)
            items[i].init_002047c0("room data", id++, 0x25800, 7);
        switchState_00266da0(old);
    }
}


// 0x00204ea0 FUN_00204ea0 (86 B): matches/0x00204ea0.cpp
// sym: ?close@A_204ea0@fn_f49dcb8d@@QAEXXZ
void A_204ea0::close() {
    if (ptr38) {
        ptr38->dispose_00263e90();
        ptr38 = 0;
    }
    if (obj30)
        FUN_00267110((int)value);
    if (obj30) {
        obj30->release();
        obj30 = 0;
    }
    if (ptr2c) {
        fptr_00267090(ptr2c);
        ptr2c = 0;
    }
    a = 0;
    b = 0;
    value = 0;
}


// 0x00204f00 FUN_00204f00 (91 B): matches/0x00204f00.cpp
// sym: ?target@fn_f49dcb8d@@YIXPAVA_204f00@1@@Z
void __fastcall target(A_204f00* a) {
    a->flag = 0;
    ((S_204f00*)a->p38)->run_00263e90();
    a->p38 = 0;
    if (a->p30) {
        int r = a->p30->f11();
        FUN_00267110((int)a->x26);
        int old = (int)a->x26;
        a->x26 = 0;
        a->p30->f1();
        a->p30 = 0;
        a->finish_002047c0((char*)a + 5, old, r, (int)a->x28);
    }
}

} // namespace fn_f49dcb8d

// 0x00204f60 TransitionsLoader::vfunc_5 (162 B): equivalent/0x00204f60.cpp [wrapped: conflict: TransitionsLoader]
// sym: ?vfunc_5@TransitionsLoader@fn_00204f60@@UAEPAHPAH0TStreamArg_204f60@2@H@Z @9b4d61171c69 @w9f34a7cbcbb0 @vb585a6dcaf81
namespace fn_00204f60 {
// STATUS: equivalent (tools/equiv.py level 3: 2565 inputs, branch coverage 6/6)
// TransitionsLoader::vfunc_5 @ 0x00204f60
struct Reader {
    void FUN_002647e0(void *dst, int a, int size, int count);
};

struct Stream {
    char pad[0x280];
    int index;               // 0x280
    Reader *reader;          // 0x284
    bool FUN_002669f0();
    void FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};

union StreamArg_204f60 {
    Stream *stream;
    unsigned int value;
};

struct Handler_204f60 {
    void FUN_00204180(unsigned int v);
};

class TransitionsLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual int *vfunc_5(int *out1, int *out2, StreamArg_204f60 arg, int arg4);
    char pad04[0x10];
    Handler_204f60 *handler;        // 0x14
    void FUN_00204880(Stream *s, int arg4);
};

int *TransitionsLoader::vfunc_5(int *out1, int *out2, StreamArg_204f60 arg, int arg4)
{
    Stream *stream = arg.stream;
    stream->reader->FUN_002647e0(&arg.value, 1, 4, 1);
    stream->reader->FUN_002647e0(&arg.value, 1, 4, 1);
    handler->FUN_00204180(arg.value);
    if (stream->FUN_002669f0()) {
        do {
            stream->FUN_00266a30();
            if (stream->FUN_00266c30() == 0x60000720)
                FUN_00204880(stream, arg4);
            stream->FUN_00266be0();
        } while (stream->FUN_002669f0());
    }
    *out1 = 0;
    out2[0] = 0;
    out2[1] = 0;
    return out2;
}
} // namespace fn_00204f60

namespace fn_f49dcb8d {

// 0x00205020 content::LoadInventory::DynamicCaster<pure3d::Shadow>::vfunc_0 (30 B): matches/0x00205020.cpp
// sym: ?Cast@DynamicCaster@fn_f49dcb8d@@UAEPAXPAX@Z
void* DynamicCaster::Cast(void* p) {
    return __RTDynamicCast(p, 0, (void*)&DAT_0048d5bc, (void*)&DAT_004c9268, 0);
}

} // namespace fn_f49dcb8d

// 0x00205050 content::LoadInventory::DynamicCaster<physics::WorldCollisionObject>::vfunc_0 (30 B): matches/0x00205050.cpp
// sym: ?vfunc_0@?$DynamicCaster@VWorldCollisionObject@physics@@@LoadInventory@content@@UAEPAXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void* content::LoadInventory::DynamicCaster<physics::WorldCollisionObject>::vfunc_0(void* p) {
    return dynamic_cast<::physics::WorldCollisionObject*>((::core::IRefCount*)p);   // (sweep2, G7) the cast is the slot's result
}


// 0x002050b0 Method1<CWorldStreamManager,void,int>::vfunc_0 (30 B): matches/0x002050b0.cpp
// sym: ?vfunc_0@Method1_2050b0@fn_002050b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CWorldStreamManager, void, int>::~Method1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_002050b0 {
struct Method1_2050b0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_2050b0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002050b0
// (x64t21) the destructor itself, which other objects' code references:


// 0x002050d0 Method1<CWorldStreamManager,void,int>::vfunc_2 (19 B): matches/0x002050d0.cpp
// sym: ?vfunc_2@Method1_2050d0@fn_002050d0@@QAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CWorldStreamManager, void, int>::vfunc_2`.
namespace fn_002050d0 {
struct Method1_2050d0 : hulk_script::FunctionGenView {
    void (::CWorldStreamManager::*f_1c)(int);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_2050d0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_2050d0* d = (Dummy_2050d0*)a;
    (d->*(*(void (Dummy_2050d0::**)(void *))&this->f_1c))(*b);
}
} // namespace fn_002050d0

namespace fn_f49dcb8d {

// 0x002050f0 FUN_002050f0 (89 B): matches/0x002050f0.cpp
// sym: ??0Method3@fn_002050f0@fn_f49dcb8d@@QAE@PBDP8Owner_2050f0@12@AEXXZ@Z
namespace fn_002050f0 {
// (script1) Method3<class CWorldStreamManager,bool,float,float,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_00425b54[];   // Method3<class CWorldStreamManager,bool,float,float,float>
class Owner_2050f0 {};
typedef void (Owner_2050f0::*Fn_2050f0)();
struct Method3 : hulk_script::ScriptFunction {
    Fn_2050f0 fn;
    Method3(const char* name, Fn_2050f0 function);
};
Method3::Method3(const char* name, Fn_2050f0 function) : hulk_script::ScriptFunction(name, 3) {
    vftable = DAT_00425b54;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
}
} // namespace fn_002050f0

} // namespace fn_f49dcb8d

// 0x00205150 Method3<CWorldStreamManager,bool,float,float,float>::vfunc_0 (30 B): matches/0x00205150.cpp
// sym: ?vfunc_0@Method3_205150@fn_00205150@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method3<CWorldStreamManager, bool, float, float, float>::~Method3()
// {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views
// call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205150 {
struct Method3_205150 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method3_205150::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205150
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205170 Method3<CWorldStreamManager,bool,float,float,float>::vfunc_2 (64 B): matches/0x00205170.cpp
// sym: ?vfunc_2@Method3_205170@fn_00205170@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method3<CWorldStreamManager, bool, float, float, float>::vfunc_2`.
namespace fn_00205170 {
struct Method3_205170 : hulk_script::FunctionGenView {
    bool (::CWorldStreamManager::*f_1c)(float, float, float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method3_205170::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_205170 * object = (CWorldStreamManager_205170 *)__p0; const float * args = (const float *)__p1; bool * result = (bool *)__p2;

    bool (CWorldStreamManager_205170::*fn)(float, float, float) = (*(bool (CWorldStreamManager_205170::**)(float, float, float))&this->f_1c);
    float a = args[0], b = args[1], c = args[2];
    bool value = (object->*fn)(a, b, c);
    if (result)
        *result = value;
}
} // namespace fn_00205170

namespace fn_f49dcb8d {

// 0x002051b0 FUN_002051b0 (89 B): matches/0x002051b0.cpp
// sym: ??0Method3@fn_002051b0@fn_f49dcb8d@@QAE@PBDP8Owner_2051b0@12@AEXXZ@Z
namespace fn_002051b0 {
// (script1) Method3<class CWorldStreamManager,int,float,float,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_00425b64[];   // Method3<class CWorldStreamManager,int,float,float,float>
class Owner_2051b0 {};
typedef void (Owner_2051b0::*Fn_2051b0)();
struct Method3 : hulk_script::ScriptFunction {
    Fn_2051b0 fn;
    Method3(const char* name, Fn_2051b0 function);
};
Method3::Method3(const char* name, Fn_2051b0 function) : hulk_script::ScriptFunction(name, 3) {
    vftable = DAT_00425b64;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
}
} // namespace fn_002051b0

} // namespace fn_f49dcb8d

// 0x00205210 Method3<CWorldStreamManager,int,float,float,float>::vfunc_0 (30 B): matches/0x00205210.cpp
// sym: ?vfunc_0@Method3_205210@fn_00205210@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method3<CWorldStreamManager, int, float, float, float>::~Method3()
// {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views
// call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205210 {
struct Method3_205210 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method3_205210::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205210
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205230 Method3<CWorldStreamManager,int,float,float,float>::vfunc_2 (64 B): matches/0x00205230.cpp
// sym: ?vfunc_2@Method3_205230@fn_00205230@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method3<CWorldStreamManager, int, float, float, float>::vfunc_2`.
namespace fn_00205230 {
struct Method3_205230 : hulk_script::FunctionGenView {
    int (::CWorldStreamManager::*f_1c)(float, float, float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method3_205230::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_205230 * manager = (CWorldStreamManager_205230 *)__p0; const float * args = (const float *)__p1; int * result = (int *)__p2;

    int (CWorldStreamManager_205230::*fn)(float, float, float) = (*(int (CWorldStreamManager_205230::**)(float, float, float))&this->f_1c);
    float a = args[0], b = args[1], c = args[2];
    int value = (manager->*fn)(a, b, c);
    if (result)
        *result = value;
}
} // namespace fn_00205230


// 0x002052b0 Method0<CWorldStreamManager,const_char_*>::vfunc_0 (30 B): matches/0x002052b0.cpp
// sym: ?vfunc_0@Method0_2052b0@fn_002052b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CWorldStreamManager, const char *>::~Method0() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_002052b0 {
struct Method0_2052b0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_2052b0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002052b0
// (x64t21) the destructor itself, which other objects' code references:


// 0x002052d0 Method0<CWorldStreamManager,const_char_*>::vfunc_2 (22 B): matches/0x002052d0.cpp
// sym: ?vfunc_2@Method0_2052d0@fn_002052d0@@QAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method0<CWorldStreamManager, const char *>::vfunc_2`.
namespace fn_002052d0 {
struct Method0_2052d0 : hulk_script::FunctionGenView {
    const char * (::CWorldStreamManager::*f_1c)();
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method0_2052d0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)&this->f_1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
} // namespace fn_002052d0


// 0x00205340 Method2<CWorldStreamManager,int,int,int>::vfunc_0 (30 B): matches/0x00205340.cpp
// sym: ?vfunc_0@Method2_205340@fn_00205340@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CWorldStreamManager, int, int, int>::~Method2() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205340 {
struct Method2_205340 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_205340::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205340
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205360 Method2<CWorldStreamManager,int,int,int>::vfunc_2 (33 B): matches/0x00205360.cpp
// sym: ?vfunc_2@Method2_205360@fn_00205360@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method2<CWorldStreamManager, int, int, int>::vfunc_2`.
namespace fn_00205360 {
struct Method2_205360 : hulk_script::FunctionGenView {
    int (::CWorldStreamManager::*f_1c)(int, int);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method2_205360::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_205360 * obj = (CWorldStreamManager_205360 *)__p0; Args * args = (Args *)__p1; int * result = (int *)__p2;

    int (CWorldStreamManager_205360::*fn)(int, int) = (*(int (CWorldStreamManager_205360::**)(int, int))&this->f_1c);
    int a = args->a;
    int b = args->b;
    int value = (obj->*fn)(a, b);
    if (result)
        *result = value;
}
} // namespace fn_00205360


// 0x002053d0 Method1<CWorldStreamManager,int,int>::vfunc_0 (30 B): matches/0x002053d0.cpp
// sym: ?vfunc_0@Method1_2053d0@fn_002053d0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CWorldStreamManager, int, int>::~Method1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_002053d0 {
struct Method1_2053d0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_2053d0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002053d0
// (x64t21) the destructor itself, which other objects' code references:


// 0x002053f0 Method1<CWorldStreamManager,int,int>::vfunc_2 (29 B): matches/0x002053f0.cpp
// sym: ?vfunc_2@Method1_2053f0@fn_002053f0@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CWorldStreamManager, int, int>::vfunc_2`.
namespace fn_002053f0 {
struct Method1_2053f0 : hulk_script::FunctionGenView {
    int (::CWorldStreamManager::*f_1c)(int);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_2053f0::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_2053f0 * manager = (CWorldStreamManager_2053f0 *)__p0; int * input = (int *)__p1; int * result = (int *)__p2;

    int (CWorldStreamManager_2053f0::*fn)(int) = (*(int (CWorldStreamManager_2053f0::**)(int))&this->f_1c);
    int arg = *input;
    int value = (manager->*fn)(arg);
    if (result)
        *result = value;
}
} // namespace fn_002053f0


// 0x00205450 Method0<CWorldStreamManager,int>::vfunc_0 (30 B): matches/0x00205450.cpp
// sym: ?vfunc_0@Method0_205450@fn_00205450@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CWorldStreamManager, int>::~Method0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205450 {
struct Method0_205450 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_205450::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205450
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205470 Method0<CWorldStreamManager,int>::vfunc_2 (22 B): matches/0x00205470.cpp
// sym: ?vfunc_2@Method0_205470@fn_00205470@@QAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method0<CWorldStreamManager, int>::vfunc_2`.
namespace fn_00205470 {
struct Method0_205470 : hulk_script::FunctionGenView {
    int (::CWorldStreamManager::*f_1c)();
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method0_205470::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)&this->f_1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
} // namespace fn_00205470


// 0x002054d0 Method1<CWorldStreamManager,bool,int>::vfunc_0 (30 B): matches/0x002054d0.cpp
// sym: ?vfunc_0@Method1_2054d0@fn_002054d0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CWorldStreamManager, bool, int>::~Method1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_002054d0 {
struct Method1_2054d0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_2054d0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002054d0
// (x64t21) the destructor itself, which other objects' code references:


// 0x002054f0 Method1<CWorldStreamManager,bool,int>::vfunc_2 (29 B): matches/0x002054f0.cpp
// sym: ?vfunc_2@Method1_2054f0@fn_002054f0@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CWorldStreamManager, bool, int>::vfunc_2`.
namespace fn_002054f0 {
struct Method1_2054f0 : hulk_script::FunctionGenView {
    bool (::CWorldStreamManager::*f_1c)(int);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_2054f0::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_2054f0 * obj = (CWorldStreamManager_2054f0 *)__p0; int * arg = (int *)__p1; bool * out = (bool *)__p2;

    bool (CWorldStreamManager_2054f0::*f)(int) = (*(bool (CWorldStreamManager_2054f0::**)(int))&this->f_1c);
    int value = *arg;
    bool result = (obj->*f)(value);
    if (out)
        *out = result;
}
} // namespace fn_002054f0


// 0x00205550 Method0<CWorldStreamManager,bool>::vfunc_0 (30 B): matches/0x00205550.cpp
// sym: ?vfunc_0@Method0_205550@fn_00205550@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CWorldStreamManager, bool>::~Method0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205550 {
struct Method0_205550 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_205550::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205550
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205570 Method0<CWorldStreamManager,bool>::vfunc_2 (22 B): matches/0x00205570.cpp
// sym: ?vfunc_2@Method0_205570@fn_00205570@@QAEXPAX00@Z
// Same code shape as 0x0002d750 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method0<CWorldStreamManager, bool>::vfunc_2`.
namespace fn_00205570 {
struct Method0_205570 : hulk_script::FunctionGenView {
    bool (::CWorldStreamManager::*f_1c)();
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method0_205570::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_205570 * obj = (CActorManager_205570 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_205570 fn = (*(Fn_205570 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
} // namespace fn_00205570


// 0x002055d0 Method0<CWorldStreamManager,void>::vfunc_0 (30 B): matches/0x002055d0.cpp
// sym: ?vfunc_0@Method0_2055d0@fn_002055d0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CWorldStreamManager, void>::~Method0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_002055d0 {
struct Method0_2055d0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_2055d0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002055d0
// (x64t21) the destructor itself, which other objects' code references:


// 0x002055f0 Method0<CWorldStreamManager,void>::vfunc_2 (12 B): matches/0x002055f0.cpp
// sym: ?vfunc_2@Method0_2055f0@fn_002055f0@@QAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method0<CWorldStreamManager, void>::vfunc_2`.
namespace fn_002055f0 {
struct Method0_2055f0 : hulk_script::FunctionGenView {
    void (::CWorldStreamManager::*f_1c)();
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method0_2055f0::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2055f0 * a = (CActorManager_2055f0 *)__p0;

    (a->*(*(void (CActorManager_2055f0::**)())&this->f_1c))();
}
} // namespace fn_002055f0

namespace fn_f49dcb8d {

// 0x00205600 FUN_00205600 (89 B): matches/0x00205600.cpp
// sym: ??0Method3@fn_00205600@fn_f49dcb8d@@QAE@PBDP8Owner_205600@12@AEXXZ@Z
namespace fn_00205600 {
// (script1) Method3<class CWorldStreamManager,void,const char *,int,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_00425be4[];   // Method3<class CWorldStreamManager,void,const char *,int,bool>
class Owner_205600 {};
typedef void (Owner_205600::*Fn_205600)();
struct Method3 : hulk_script::ScriptFunction {
    Fn_205600 fn;
    Method3(const char* name, Fn_205600 function);
};
Method3::Method3(const char* name, Fn_205600 function) : hulk_script::ScriptFunction(name, 3) {
    vftable = DAT_00425be4;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
}
} // namespace fn_00205600

} // namespace fn_f49dcb8d

// 0x00205660 Method3<CWorldStreamManager,void,const_char_*,int,bool>::vfunc_0 (30 B): matches/0x00205660.cpp
// sym: ?vfunc_0@Method3_205660@fn_00205660@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method3<CWorldStreamManager, void, const char *, int,
// bool>::~Method3() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205660 {
struct Method3_205660 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method3_205660::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205660
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205680 Method3<CWorldStreamManager,void,const_char_*,int,bool>::vfunc_2 (31 B): matches/0x00205680.cpp
// sym: ?vfunc_2@Method3_205680@fn_00205680@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method3<CWorldStreamManager, void, const char *, int, bool>::vfunc_2`.
namespace fn_00205680 {
struct Method3_205680 : hulk_script::FunctionGenView {
    void (::CWorldStreamManager::*f_1c)(const char *, int, bool);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method3_205680::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_205680 * object = (CWorldStreamManager_205680 *)__p0; Arguments * arguments = (Arguments *)__p1; void * unused = (void *)__p2;

    const char* name = arguments->name;
    (object->*(*(void (CWorldStreamManager_205680::**)(const char *, int, bool))&this->f_1c))(name, arguments->number, arguments->flag);
}
} // namespace fn_00205680

namespace fn_f49dcb8d {

// 0x00205910 FUN_00205910 (188 B): equivalent/0x00205910.cpp
// sym: ?target@Object_205910@fn_f49dcb8d@@QAEXXZ @1642b471b5d4 @wb99d331257ad @vb49c0e843edd
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 14/14)
// FUN_00205910 @ 0x00205910
void Object_205910::target() {
 content::LoadInventory* memory = (content::LoadInventory*)FUN_00263ea0(HULK_LOADINVENTORY_SIZE);
 content::LoadInventory* replacement = memory ? ((LoadInventory_nv_205910*)(((content::LoadInventory*)(memory))))->FUN_00266480(0x400) : 0;
 if (replacement) replacement->vfunc_0();
 if (resource) resource->vfunc_1();
 resource = replacement;
 if ((*(unsigned char*)&DAT_004c91d8) || (*(unsigned char*)((char*)&DAT_004c91d8 + 1))) {
 int previous = FUN_00266da0(11);
 FUN_00266d90();
 if ((*(unsigned char*)((char*)&DAT_004c91d8 + 1))) {
 for (int i=0; i<2; ++i) {
 textures[i].size = 0x200;
 textures[i].FUN_002047c0("texture data",19+i,0x32000,11);
 }
 }
 FUN_00204e40();
 flag = 0;
 FUN_00266da0(previous);
 }
}


// 0x002059d0 FUN_002059d0 (258 B): equivalent/0x002059d0.cpp
// sym: ?cleanup@Object@fn_f49dcb8d@@QAEXXZ @01927733a62c @w1e2d907c68da @v3b47e5f2cfa4
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 28/28)
// FUN_002059d0 @ 0x002059d0
void Object::cleanup() {
 if ((*(unsigned char*)&DAT_004c91d8)) {
  for (int i=0;i<20;++i) {
   Entry_2059d0& e=entries[i];
   if(e.handle) {e.handle->FUN_00263e90(); e.handle=0;}
   if(e.resource) FUN_00267110(e.id);
   if(e.resource) {e.resource->release(); e.resource=0;}
   if(e.allocation) {FUN_00267090(e.allocation); e.allocation=0;}
   e.active=0; e.flag=0; e.id=0;
  }
 }
 if(mainResource) {
  mainResource->FUN_002665a0();
  if(mainResource) {mainResource->release();mainResource=0;}
 }
 for(int j=0;j<2;++j) {
  if((*(unsigned char*)((char*)&DAT_004c91d8 + 1))) {
   Entry_2059d0& e=extra[j];
   if(e.handle) {e.handle->FUN_00263e90();e.handle=0;}
   if(e.resource) FUN_00267110(e.id);
   if(e.resource) {e.resource->release();e.resource=0;}
   if(e.allocation) {FUN_00267090(e.allocation);e.allocation=0;}
   e.active=0;e.flag=0;e.id=0;
  }
  tail.values[j]=0;
 }
}

} // namespace fn_f49dcb8d

// 0x00205b20 TransitionsLoader::vfunc_2 (31 B): matches/0x00205b20.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00205b20@@UAEPAV123@E@Z
namespace fn_00205b20 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_205b20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_205b20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00205b20


// 0x00205c00 FUN_00205c00 (76 B): matches/0x00205c00.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ??0Closure1@fn_00205c00@@QAE@PBDPAVOwner_205c00@1@P821@AEXXZ@Z
namespace fn_00205c00 {
// (script1) Closure1<class CWorldStreamManager,void,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425b44[];   // Method1<class CWorldStreamManager,void,int>
extern "C" char DAT_00425c44[];   // Closure1<class CWorldStreamManager,void,int>
class Owner_205c00 {};
typedef void (Owner_205c00::*Fn_205c00)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_205c00 fn;
    Owner_205c00* owner;
    Closure1(const char* name, Owner_205c00* object, Fn_205c00 function);
};
Closure1::Closure1(const char* name, Owner_205c00* object, Fn_205c00 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00425b44;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_00425c44;
    owner = object;
}
} // namespace fn_00205c00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00205c50 Closure1<CWorldStreamManager,void,int>::vfunc_0 (30 B): matches/0x00205c50.cpp
// sym: ?vfunc_0@Closure1_205c50@fn_00205c50@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CWorldStreamManager, void, int>::~Closure1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205c50 {
struct Closure1_205c50 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_205c50::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205c50
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205c70 Closure1<CWorldStreamManager,void,int>::vfunc_2 (18 B): matches/0x00205c70.cpp
// sym: ?vfunc_2@?$Closure1@VCWorldStreamManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CWorldStreamManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_205c70 * *)&this->f_20)->*(*(void (CActorManager_205c70::**)(const char *))&this->f_1c))(*b);
}


// 0x00205cc0 Closure3<CWorldStreamManager,bool,float,float,float>::vfunc_0 (30 B): matches/0x00205cc0.cpp
// sym: ?vfunc_0@Closure3_205cc0@fn_00205cc0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure3<CWorldStreamManager, bool, float, float,
// float>::~Closure3() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205cc0 {
struct Closure3_205cc0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure3_205cc0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205cc0
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205ce0 Closure3<CWorldStreamManager,bool,float,float,float>::vfunc_2 (64 B): equivalent/0x00205ce0.cpp
// sym: ?vfunc_2@Closure3_205ce0@fn_00205ce0@@QAEXPAX00@Z @b66dd089ba69 @w9c630f34be59 @v86acb1cedc30
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure3<CWorldStreamManager,bool,float,float,float>::vfunc_2 @ 0x00205ce0
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CWorldStreamManager, bool, float, float, float>::vfunc_2`.
namespace fn_00205ce0 {
struct Closure3_205ce0 : hulk_script::FunctionGenView {
    bool (::CWorldStreamManager::*f_1c)(float, float, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_205ce0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; float * arguments = (float *)__p1; bool * result = (bool *)__p2;

    bool value = (*(StreamCallback *)&this->f_1c)((*(CWorldStreamManager_205ce0 * *)&this->f_20), 0, arguments[0], arguments[1], arguments[2]);
    if (result) *result = value;
}
} // namespace fn_00205ce0


// 0x00205d50 Closure3<CWorldStreamManager,int,float,float,float>::vfunc_0 (30 B): matches/0x00205d50.cpp
// sym: ?vfunc_0@Closure3_205d50@fn_00205d50@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure3<CWorldStreamManager, int, float, float,
// float>::~Closure3() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205d50 {
struct Closure3_205d50 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure3_205d50::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205d50
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205d70 Closure3<CWorldStreamManager,int,float,float,float>::vfunc_2 (64 B): equivalent/0x00205d70.cpp
// sym: ?vfunc_2@Closure3_205d70@fn_00205d70@@QAEXPAX00@Z @df53f4d6ac4d @wf56146c9fa5a @v2918d819faef
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure3<CWorldStreamManager,int,float,float,float>::vfunc_2 @ 0x00205d70
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CWorldStreamManager, int, float, float, float>::vfunc_2`.
namespace fn_00205d70 {
struct Closure3_205d70 : hulk_script::FunctionGenView {
    int (::CWorldStreamManager::*f_1c)(float, float, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_205d70::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; const float * args = (const float *)__p1; int * result = (int *)__p2;
 int value = ((*(CWorldStreamManager_205d70 * *)&this->f_20)->*(*(int (CWorldStreamManager_205d70::**)(float, float, float))&this->f_1c))(args[0], args[1], args[2]); if (result) *result = value; }
} // namespace fn_00205d70


// 0x00205df0 Closure0<CWorldStreamManager,const_char_*>::vfunc_0 (30 B): matches/0x00205df0.cpp
// sym: ?vfunc_0@Closure0_205df0@fn_00205df0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure0<CWorldStreamManager, const char *>::~Closure0() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205df0 {
struct Closure0_205df0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure0_205df0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205df0
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205e10 Closure0<CWorldStreamManager,const_char_*>::vfunc_2 (23 B): matches/0x00205e10.cpp
// sym: ?vfunc_2@Closure0_205e10@fn_00205e10@@QAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure0<CWorldStreamManager, const char *>::vfunc_2`.
namespace fn_00205e10 {
struct Closure0_205e10 : hulk_script::FunctionGenView {
    const char * (::CWorldStreamManager::*f_1c)();
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure0_205e10::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_205e10* obj = (*(CActorManager_205e10 * *)&this->f_20);
    int (CActorManager_205e10::*fn)() = (*(int (CActorManager_205e10::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
} // namespace fn_00205e10


// 0x00205e30 FUN_00205e30 (89 B): matches/0x00205e30.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_00205e30@@QAE@PBDPAVOwner_205e30@1@P821@AEXXZ@Z
namespace fn_00205e30 {
// (script1) Closure2<class CWorldStreamManager,int,int,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425b84[];   // Method2<class CWorldStreamManager,int,int,int>
extern "C" char DAT_00425c84[];   // Closure2<class CWorldStreamManager,int,int,int>
class Owner_205e30 {};
typedef void (Owner_205e30::*Fn_205e30)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_205e30 fn;
    Owner_205e30* owner;
    Closure2(const char* name, Owner_205e30* object, Fn_205e30 function);
};
Closure2::Closure2(const char* name, Owner_205e30* object, Fn_205e30 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00425b84;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_00425c84;
    owner = object;
}
} // namespace fn_00205e30


// 0x00205e90 Closure2<CWorldStreamManager,int,int,int>::vfunc_0 (30 B): matches/0x00205e90.cpp
// sym: ?vfunc_0@Closure2_205e90@fn_00205e90@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CWorldStreamManager, int, int, int>::~Closure2() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205e90 {
struct Closure2_205e90 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_205e90::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205e90
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205eb0 Closure2<CWorldStreamManager,int,int,int>::vfunc_2 (36 B): equivalent/0x00205eb0.cpp
// sym: ?vfunc_2@Closure2_205eb0@fn_00205eb0@@QAEXPAX00@Z @5f2db1ebe681 @w1a588241b2b0 @v4f83eba10421
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CWorldStreamManager,int,int,int>::vfunc_2 @ 0x00205eb0
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure2<CWorldStreamManager, int, int, int>::vfunc_2`.
namespace fn_00205eb0 {
struct Closure2_205eb0 : hulk_script::FunctionGenView {
    int (::CWorldStreamManager::*f_1c)(int, int);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure2_205eb0::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; Arguments * arguments = (Arguments *)__p1; int * result = (int *)__p2;

    int value = ((*(CWorldStreamManager_205eb0 * *)&this->f_20)->*(*(int (CWorldStreamManager_205eb0::**)(int, int))&this->f_1c))(arguments->first, arguments->second);
    if (result) *result = value;
}
} // namespace fn_00205eb0


// 0x00205ee0 FUN_00205ee0 (76 B): matches/0x00205ee0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_00205ee0@@QAE@PBDPAVOwner_205ee0@1@P821@AEXXZ@Z
namespace fn_00205ee0 {
// (script1) Closure1<class CWorldStreamManager,int,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425b94[];   // Method1<class CWorldStreamManager,int,int>
extern "C" char DAT_00425c94[];   // Closure1<class CWorldStreamManager,int,int>
class Owner_205ee0 {};
typedef void (Owner_205ee0::*Fn_205ee0)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_205ee0 fn;
    Owner_205ee0* owner;
    Closure1(const char* name, Owner_205ee0* object, Fn_205ee0 function);
};
Closure1::Closure1(const char* name, Owner_205ee0* object, Fn_205ee0 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00425b94;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_00425c94;
    owner = object;
}
} // namespace fn_00205ee0


// 0x00205f30 Closure1<CWorldStreamManager,int,int>::vfunc_0 (30 B): matches/0x00205f30.cpp
// sym: ?vfunc_0@Closure1_205f30@fn_00205f30@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CWorldStreamManager, int, int>::~Closure1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205f30 {
struct Closure1_205f30 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_205f30::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205f30
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205f50 Closure1<CWorldStreamManager,int,int>::vfunc_2 (30 B): equivalent/0x00205f50.cpp
// sym: ?vfunc_2@Closure1_205f50@fn_00205f50@@QAEXPAX00@Z @d5fcbfd9f63b @we2b2731e125e @v04020684a3df
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure1<CWorldStreamManager,int,int>::vfunc_2 @ 0x00205f50
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CWorldStreamManager, int, int>::vfunc_2`.
namespace fn_00205f50 {
struct Closure1_205f50 : hulk_script::FunctionGenView {
    int (::CWorldStreamManager::*f_1c)(int);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_205f50::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; int * argument = (int *)__p1; int * result = (int *)__p2;

    int value = ((*(CWorldStreamManager_205f50 * *)&this->f_20)->*(*(int (CWorldStreamManager_205f50::**)(int))&this->f_1c))(*argument);
    if (result)
        *result = value;
}
} // namespace fn_00205f50


// 0x00205fb0 Closure0<CWorldStreamManager,int>::vfunc_0 (30 B): matches/0x00205fb0.cpp
// sym: ?vfunc_0@Closure0_205fb0@fn_00205fb0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure0<CWorldStreamManager, int>::~Closure0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00205fb0 {
struct Closure0_205fb0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure0_205fb0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00205fb0
// (x64t21) the destructor itself, which other objects' code references:


// 0x00205fd0 Closure0<CWorldStreamManager,int>::vfunc_2 (23 B): matches/0x00205fd0.cpp
// sym: ?vfunc_2@Closure0_205fd0@fn_00205fd0@@QAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure0<CWorldStreamManager, int>::vfunc_2`.
namespace fn_00205fd0 {
struct Closure0_205fd0 : hulk_script::FunctionGenView {
    int (::CWorldStreamManager::*f_1c)();
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure0_205fd0::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_205fd0* obj = (*(CActorManager_205fd0 * *)&this->f_20);
    int (CActorManager_205fd0::*fn)() = (*(int (CActorManager_205fd0::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
} // namespace fn_00205fd0


// 0x00205ff0 FUN_00205ff0 (76 B): matches/0x00205ff0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_00205ff0@@QAE@PBDPAVOwner_205ff0@1@P821@AEXXZ@Z
namespace fn_00205ff0 {
// (script1) Closure1<class CWorldStreamManager,bool,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425bb4[];   // Method1<class CWorldStreamManager,bool,int>
extern "C" char DAT_00425cb4[];   // Closure1<class CWorldStreamManager,bool,int>
class Owner_205ff0 {};
typedef void (Owner_205ff0::*Fn_205ff0)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_205ff0 fn;
    Owner_205ff0* owner;
    Closure1(const char* name, Owner_205ff0* object, Fn_205ff0 function);
};
Closure1::Closure1(const char* name, Owner_205ff0* object, Fn_205ff0 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00425bb4;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_00425cb4;
    owner = object;
}
} // namespace fn_00205ff0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00206060 Closure1<CWorldStreamManager,bool,int>::vfunc_2 (30 B): matches/0x00206060.cpp [wrapped: conflict: Closure1]
// sym: ?V2@Closure1@fn_00206060@@QAEXPAXPAPBDPA_N@Z
namespace fn_00206060 {
// Same code shape as 0x00106cc0 (propagated; names are from that function)
class Closure1 { void* vftable;   /* (script2) the vftable word, no stand-in vftable */
  public:
    void V0();
    void V1();
    void V2(void*, const char**, bool*);
    ScriptFunctionFields fields;   // (script2) Function's fields (was char pad[0x18])
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
} // namespace fn_00206060


// 0x002060e0 Closure0<CWorldStreamManager,bool>::vfunc_2 (23 B): matches/0x002060e0.cpp
// sym: ?vfunc_2@Closure0_2060e0@fn_002060e0@@QAEXPAX00@Z
// Same code shape as 0x0002f6a0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure0<CWorldStreamManager, bool>::vfunc_2`.
namespace fn_002060e0 {
struct Closure0_2060e0 : hulk_script::FunctionGenView {
    bool (::CWorldStreamManager::*f_1c)();
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure0_2060e0::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_2060e0* o = (*(CActorManager_2060e0 * *)&this->f_20);
    Fn_2060e0 fn = (*(Fn_2060e0 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}
} // namespace fn_002060e0


// 0x00206160 Closure0<CWorldStreamManager,void>::vfunc_2 (11 B): matches/0x00206160.cpp
// sym: ?vfunc_2@Closure0_206160@fn_00206160@@QAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure0<CWorldStreamManager, void>::vfunc_2`.
namespace fn_00206160 {
struct Closure0_206160 : hulk_script::FunctionGenView {
    void (::CWorldStreamManager::*f_1c)();
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure0_206160::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_206160 * *)&this->f_20)->*(*(void (CActorManager_206160::**)())&this->f_1c))();
}
} // namespace fn_00206160


// 0x002061c0 Closure3<CWorldStreamManager,void,const_char_*,int,bool>::vfunc_2 (30 B): equivalent/0x002061c0.cpp
// sym: ?vfunc_2@Closure3_2061c0@fn_002061c0@@QAEXPAX00@Z @bf9aeccd3fbc @w361740b851d9 @v3f45b90602c2
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CWorldStreamManager,void,const_char_*,int,bool>::vfunc_2 @ 0x002061c0
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CWorldStreamManager, void, const char *, int, bool>::vfunc_2`.
namespace fn_002061c0 {
struct Closure3_2061c0 : hulk_script::FunctionGenView {
    void (::CWorldStreamManager::*f_1c)(const char *, int, bool);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_2061c0::vfunc_2(void* __p0, void* __p1, void* __p2) { const Args * args = (const Args *)__p1;

    ((*(CWorldStreamManager_2061c0 * *)&this->f_20)->*(*(void (CWorldStreamManager_2061c0::**)(const char *, int, bool))&this->f_1c))(args->name, args->number, args->flag);
}
} // namespace fn_002061c0


// 0x002061e0 FUN_002061e0 (226 B): matches/0x002061e0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Dtor@Target_2061e0@fn_002061e0@@QAEXXZ
namespace fn_002061e0 {
extern void* hulk_at_00425cf4[];
extern void* hulk_at_00425b20[];
class Ref_2061e0 {
  public:
    virtual void F0();
    virtual void Release();
};
extern void __fastcall FUN_00263e90(Ref_2061e0*);
extern "C" void FUN_00267110(int);
extern void FUN_00267090(void*);
struct CWorldStreamManager_2061e0 {
    void* vf;
    char b4;
    char b5;
    char pad6[0x20];
    short w26;
    char pad28[4];
    void* p2c;
    Ref_2061e0* p30;
    char pad34[4];
    Ref_2061e0* p38;
    void Fini() throw();
};
void CWorldStreamManager_2061e0::Fini() throw() {
    vf = hulk_at_00425b20;
    if (p38) {
        FUN_00263e90(p38);
        p38 = 0;
    }
    if (p30)
        FUN_00267110(w26);
    if (p30) {
        p30->Release();
        p30 = 0;
    }
    if (p2c) {
        FUN_00267090(p2c);
        p2c = 0;
    }
    b4 = 0;
    b5 = 0;
    w26 = 0;
}
struct Target_2061e0 {
    void* vf;
    char pad[0x44];
    CWorldStreamManager_2061e0 a[0x14];
    CWorldStreamManager_2061e0 b[2];
    void Dtor() throw();
};
void Target_2061e0::Dtor() throw() {
    vf = hulk_at_00425cf4;
    CWorldStreamManager_2061e0* p = b + 2;
    for (int i = 2; i; --i) {
        --p;
        p->Fini();
    }
    p = a + 0x14;
    for (int i = 0x14; i; --i) {
        --p;
        p->Fini();
    }
}
} // namespace fn_002061e0


// 0x002062d0 FUN_002062d0 (79 B): matches/0x002062d0.cpp
// sym: ?FUN_002062d0@Owner_2062d0@owners@@QAEXH@Z
// data: gManager_2062d0 = DAT_00527c58
void owners::Owner_2062d0::FUN_002062d0(hulk_intptr value) {
    param = ((int)value);
    Loader_2062d0* r;
    Loader_2062d0* p = (Loader_2062d0*)Alloc_00263ea0(sizeof(Loader_2062d0));
    if (p != 0) {
        p->refs = 0;
        p->id = 0x60000722;
        p->f0c = 0;
        p->f10 = 0;
        p->vftable = (void*)DAT_00425c28;
        p->owner = this;
        r = p;
    } else {
        r = 0;
    }
    (*(Manager_2062d0**)&DAT_00527c58)->Register_00265210(r, 0x60000722);
}


// 0x00206c10 CWorldStreamManager::CMemoryPool::vfunc_0 (36 B): matches/0x00206c10.cpp [wrapped: conflict: CTrack]
// sym: ?vfunc_5@CMemoryPool_206c10@fn_00206c10@@QAEPAV12@C@Z
namespace fn_00206c10 {
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)

extern void* CTrack_vftable[];

class CTrack {
  public:
    void Destroy_00204ea0(); // FUN_00236d60, __thiscall, this in ecx
};

class CMemoryPool_206c10 : public CTrack {
  public:
    CMemoryPool_206c10* vfunc_5(signed char flags);
};

void __cdecl SweepTrack_DeleteThis_0008d330(void* p); // thunk_FUN_00267090

CMemoryPool_206c10* CMemoryPool_206c10::vfunc_5(signed char flags) {
    *(void***)this = (void**)DAT_00425b20;
    Destroy_00204ea0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}
} // namespace fn_00206c10

namespace fn_f49dcb8d {

// 0x00206c90 FUN_00206c90 (83 B): equivalent/0x00206c90.cpp
// sym: ?FUN_00206c90@Registry_206c90@fn_f49dcb8d@@QAEXPBDPAVCWorldStreamManager_206c90@2@P832@AE_NMMM@Z@Z @57b38241786c @w754d32f6f3d4 @vce210739b689
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00206c90 @ 0x00206c90
// FUN_00206c90 @ 0x00206c90  (generated by tools/equiv_gen/reg_helper.py)
void Registry_206c90::FUN_00206c90(const char* a1, CWorldStreamManager_206c90* a2, Fn_206c90 a3) {
    typedef Closure3_206c90<CWorldStreamManager_206c90, bool, float, float, float> Alloc_206c90;
    HULK_SIZE32(Alloc_206c90, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_206c90));
    void* x = 0;
    if (m) {
        ((Raw_206c90*)m)->FUN_002050f0(a1, a3);
        x = new (m) Closure3_206c90<CWorldStreamManager_206c90, bool, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00206cf0 FUN_00206cf0 (83 B): equivalent/0x00206cf0.cpp
// sym: ?FUN_00206cf0@Registry_206cf0@fn_f49dcb8d@@QAEXPBDPAVCWorldStreamManager_206cf0@2@P832@AEHMMM@Z@Z @e16d4541ca0a @w1b1ccce25d0d @v791c074f268b
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00206cf0 @ 0x00206cf0
// FUN_00206cf0 @ 0x00206cf0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_206cf0::FUN_00206cf0(const char* a1, CWorldStreamManager_206cf0* a2, Fn_206cf0 a3) {
    typedef Closure3_206cf0<CWorldStreamManager_206cf0, int, float, float, float> Alloc_206cf0;
    HULK_SIZE32(Alloc_206cf0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_206cf0));
    void* x = 0;
    if (m) {
        ((Raw_206cf0*)m)->FUN_002051b0(a1, a3);
        x = new (m) Closure3_206cf0<CWorldStreamManager_206cf0, int, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f49dcb8d

// 0x00206d50 FUN_00206d50 (109 B): matches/0x00206d50.cpp [wrapped: conflict: CWorldStreamManager; Closure0; Method0]
// sym: ?FUN_00206d50@Registry_206d50@fn_00206d50@@QAEXPBDPAVOwner_206d50@2@P832@AEXXZ@Z
namespace fn_00206d50 {
// (script1) ScriptHandler's registration of a Closure0<class CWorldStreamManager,const char *>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_00425b74[];   // Method0<class CWorldStreamManager,const char *>
extern "C" char DAT_00425c74[];   // Closure0<class CWorldStreamManager,const char *>
class Owner_206d50 {};
typedef void (Owner_206d50::*Fn_206d50)();
struct Closure_206d50 : hulk_script::ScriptFunction {
    Fn_206d50 fn;
    Owner_206d50* owner;
    Closure_206d50(const char* name, Owner_206d50* object, Fn_206d50 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_00425b74;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
        vftable = DAT_00425c74;
        owner = object;
    }
};
struct Registry_206d50 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_00206d50(const char* name, Owner_206d50* object, Fn_206d50 function);
};
void Registry_206d50::FUN_00206d50(const char* name, Owner_206d50* object, Fn_206d50 function) {
    Closure_206d50* c = new Closure_206d50(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_00206d50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00206e60 FUN_00206e60 (109 B): matches/0x00206e60.cpp [wrapped: conflict: CWorldStreamManager; Closure0; Method0]
// sym: ?FUN_00206e60@Registry_206e60@fn_00206e60@@QAEXPBDPAVOwner_206e60@2@P832@AEXXZ@Z
namespace fn_00206e60 {
// (script1) ScriptHandler's registration of a Closure0<class CWorldStreamManager,int>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_00425ba4[];   // Method0<class CWorldStreamManager,int>
extern "C" char DAT_00425ca4[];   // Closure0<class CWorldStreamManager,int>
class Owner_206e60 {};
typedef void (Owner_206e60::*Fn_206e60)();
struct Closure_206e60 : hulk_script::ScriptFunction {
    Fn_206e60 fn;
    Owner_206e60* owner;
    Closure_206e60(const char* name, Owner_206e60* object, Fn_206e60 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_00425ba4;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
        vftable = DAT_00425ca4;
        owner = object;
    }
};
struct Registry_206e60 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_00206e60(const char* name, Owner_206e60* object, Fn_206e60 function);
};
void Registry_206e60::FUN_00206e60(const char* name, Owner_206e60* object, Fn_206e60 function) {
    Closure_206e60* c = new Closure_206e60(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_00206e60
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00206f20 FUN_00206f20 (109 B): matches/0x00206f20.cpp [wrapped: conflict: CWorldStreamManager; Closure0; Method0]
// sym: ?FUN_00206f20@Registry_206f20@fn_00206f20@@QAEXPBDPAVOwner_206f20@2@P832@AEXXZ@Z
namespace fn_00206f20 {
// (script1) ScriptHandler's registration of a Closure0<class CWorldStreamManager,bool>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_00425bc4[];   // Method0<class CWorldStreamManager,bool>
extern "C" char DAT_00425cc4[];   // Closure0<class CWorldStreamManager,bool>
class Owner_206f20 {};
typedef void (Owner_206f20::*Fn_206f20)();
struct Closure_206f20 : hulk_script::ScriptFunction {
    Fn_206f20 fn;
    Owner_206f20* owner;
    Closure_206f20(const char* name, Owner_206f20* object, Fn_206f20 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_00425bc4;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
        vftable = DAT_00425cc4;
        owner = object;
    }
};
struct Registry_206f20 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_00206f20(const char* name, Owner_206f20* object, Fn_206f20 function);
};
void Registry_206f20::FUN_00206f20(const char* name, Owner_206f20* object, Fn_206f20 function) {
    Closure_206f20* c = new Closure_206f20(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_00206f20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00206f90 FUN_00206f90 (109 B): matches/0x00206f90.cpp [wrapped: conflict: CWorldStreamManager; Closure0; Method0]
// sym: ?FUN_00206f90@Registry_206f90@fn_00206f90@@QAEXPBDPAVOwner_206f90@2@P832@AEXXZ@Z
namespace fn_00206f90 {
// (script1) ScriptHandler's registration of a Closure0<class CWorldStreamManager,void>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_00425bd4[];   // Method0<class CWorldStreamManager,void>
extern "C" char DAT_00425cd4[];   // Closure0<class CWorldStreamManager,void>
class Owner_206f90 {};
typedef void (Owner_206f90::*Fn_206f90)();
struct Closure_206f90 : hulk_script::ScriptFunction {
    Fn_206f90 fn;
    Owner_206f90* owner;
    Closure_206f90(const char* name, Owner_206f90* object, Fn_206f90 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_00425bd4;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
        vftable = DAT_00425cd4;
        owner = object;
    }
};
struct Registry_206f90 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_00206f90(const char* name, Owner_206f90* object, Fn_206f90 function);
};
void Registry_206f90::FUN_00206f90(const char* name, Owner_206f90* object, Fn_206f90 function) {
    Closure_206f90* c = new Closure_206f90(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_00206f90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f49dcb8d {

// 0x00207000 FUN_00207000 (83 B): equivalent/0x00207000.cpp
// sym: ?FUN_00207000@Registry_207000@fn_f49dcb8d@@QAEXPBDPAVCWorldStreamManager_207000@2@P832@AEX0H_N@Z@Z @27e3346d5e83 @web88aa33fe50 @v95983c35fe3b
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00207000 @ 0x00207000
// FUN_00207000 @ 0x00207000  (generated by tools/equiv_gen/reg_helper.py)
void Registry_207000::FUN_00207000(const char* a1, CWorldStreamManager_207000* a2, Fn_207000 a3) {
    typedef Closure3_207000<CWorldStreamManager_207000, void, const char*, int, bool> Alloc_207000;
    HULK_SIZE32(Alloc_207000, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_207000));
    void* x = 0;
    if (m) {
        ((Raw_207000*)m)->FUN_00205600(a1, a3);
        x = new (m) Closure3_207000<CWorldStreamManager_207000, void, const char*, int, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00207060 CWorldStreamManager::vfunc_0 (30 B): matches/0x00207060.cpp
// sym: ?vfunc_2@CWorldStreamManager_207060@fn_f49dcb8d@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CWorldStreamManager_207060* CWorldStreamManager_207060::vfunc_2(unsigned char flags) {
    ((CWorldStreamManager_nv_207060*)(((CWorldStreamManager*)(this))))->FUN_002061e0();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f49dcb8d

// 0x00207130 FUN_00207130 (30 B): matches/0x00207130.cpp
// sym: ?FUN_00207130@Obj_207130@owners@@QAE_NXZ
bool owners::Obj_207130::FUN_00207130() {
    int n = GetCount(0);
    if (n > 0) {
        DoThing(n);
        return true;
    }
    return false;
}


// 0x00207150 FUN_00207150 (129 B): matches/0x00207150.cpp
// sym: ?FUN_00207150@C_207150@owners@@QAE_NXZ
bool owners::C_207150::FUN_00207150() {
    for (;;) {
        int n = 0;
        if (a[0] > 0)
            n = 1;
        if (a[1] > 0)
            n++;
        if (n >= 2) {
            int i;
            for (i = 0; i < 2; i++) {
                if (a[i] > 0 && !Check(a[i])) {
                    Finish(a[i]);
                    return true;
                }
            }
            int r = Get(0);
            if (r > 0)
                Do(r);
        } else {
            break;
        }
    }
    return false;
}

namespace fn_f49dcb8d {

// 0x002071e0 FUN_002071e0 (548 B): equivalent/0x002071e0.cpp
// sym: ?FUN_002071e0@Mixer@fn_f49dcb8d@@QAEXH@Z @0d7d933b2332 @w149160aa25b7 @vaafaf4e9c125
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 48/48)
// FUN_002071e0 @ 0x002071e0
void Mixer::FUN_002071e0(int n)
{
    if (ready)
        return;

    for (int i = 0; i < n; ++i) {
        int r = FUN_00204c10(0);
        if (r > 0)
            FUN_00207080(r);
    }

    int used = 0;
    for (int i = 0; i < 0x400; ++i) {
        if (flags[i] == 1)
            ++used;
    }

    int limit = 0x14 - n;
    if (used > limit) {
        int k = used - limit;
        do {
            int r = FUN_00204c10(0);
            if (r < 0) {
                r = FUN_00204ad0(count, &ids[0]);
                ids[count] = -1;
                vals[count] = r;
                ++count;
            }
            FUN_00207080(r);
            --k;
        } while (k != 0);
    }

    if ((*(unsigned char*)&DAT_004c91d8)) {
        for (int i = 0; i < 20; ++i) {
            Slot_2071e0 *s = &slots[i];
            if (s->used)
                continue;
            if (s->handle != 0) {
                s->handle->FUN_00263e90();
                s->handle = 0;
            }
            if (s->voice != 0)
                FUN_00267110(s->id);
            if (s->voice != 0) {
                s->voice->v1();
                s->voice = 0;
            }
            if (s->buf != 0) {
                FUN_00267090(s->buf);
                s->buf = 0;
            }
            s->used = 0;
            s->used2 = 0;
            s->id = 0;
        }
        dirty = 1;
    }

    ids[count] = -1;
    vals[count] = -1;
    ++count;
    int tag = FUN_00266da0(7);

    for (int i = 0; i < 3; ++i) {
        Stream *st = 0;
        void *mem = FUN_00263ea0(HULK_LOADINVENTORY_SIZE);
        if (mem) {
            st = (Stream *)((Stream *)mem)->FUN_00266480(0x400);
            if (st)
                st->v0();
        }
        if (streams[i])
            streams[i]->v1();
        streams[i] = st;
        if (i > 0)
            st->FUN_002660a0(streams[0]);
    }
    ready = 1;
    Mgr54_2071e0 *m54 = DAT_004dd700->mgr54;
    ((Dummy_2071e0 *)((void *)((owners::Obj_86290 *)m54)->FUN_00086290()))->FUN_001b9020();
    field9a4 = DAT_004dd700->mgr3c->FUN_000d6f50();
    DAT_004dd700->mgr3c->FUN_000d7030(0x180);
    FUN_00266da0(tag);
}


// 0x00207410 FUN_00207410 (354 B): equivalent/0x00207410.cpp
// sym: ?FUN_00207410@Player_207410@fn_f49dcb8d@@QAEDXZ @11803fbe1783 @w0a23b8e3960b @v069da9d2e722
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 26/26)
// FUN_00207410 @ 0x00207410
char Player_207410::FUN_00207410()
{
    if (!stream)
        return 0;
    if (((LoadInventory_nv_207410*)(stream))->FUN_00266710() != 3)
        return 0;

    unsigned char flag;
    if (pending)
        flag = DAT_004c91d8[1];
    else
        flag = locked ? 0 : DAT_004c91d8[0];

    int id = FUN_00203a80();

    if (busy) {
        ((LoadInventory_nv_207410*)(stream))->FUN_00263e90();
        char wasLocked = locked;
        stream = 0;
        if (wasLocked) {
            locked = 0;
            return 0;
        }
        if (flag)
            FUN_00204540(id)->FUN_00204f00();
        busy = 0;
        pending = 0;
        return 0;
    }

    if (!pending && !locked)
        ((owners::Obj_207130 *)this)->FUN_00207130();

    if (flag) {
        Node_207410 *n = FUN_00204540(id);
        int r = ((LoadInventory_nv_207410*)(stream))->FUN_00266700();
        n->slot->FUN_00266220(r);
    } else if (locked) {
        int r = ((LoadInventory_nv_207410*)(stream))->FUN_00266700();
        slots[curSlot]->FUN_00266220(r);
    }

    if (!locked) {
        int r = FUN_00203bb0();
        if (pending) {
            pending = 0;
            FUN_00204720(r);
        } else {
            FUN_002067d0(r, 0);
        }
    }

    ((LoadInventory_nv_207410*)(stream))->FUN_00263e90();
    stream = 0;
    return 1;
}

} // namespace fn_f49dcb8d

// 0x00207850 FUN_00207850 (127 B): equivalent/0x00207850.cpp
// sym: ?FUN_00207850@LoadInventory_207850@owners@@QAE_NH@Z @4a4f06948147 @w732bccc5a1ec @va88a7bf10ad7
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 12/12)
// FUN_00207850 @ 0x00207850
bool owners::LoadInventory_207850::FUN_00207850(int flag)
{
    if (blocked == 0 && pending != 0) {
        int n = (char)flag ? FUN_002037a0() : FUN_00204c10(1);
        if (n >= 1) {
            FUN_00207580(n, flag);
            return true;
        }
        pending = 0;
        for (;;) {
            int m = FUN_00204c10(0);
            if (m <= 0)
                break;
            FUN_00207080(m);
        }
        return false;
    }
    return pending != 0;
}


// 0x002078d0 FUN_002078d0 (31 B): matches/0x002078d0.cpp
// sym: ?FUN_002078d0@Obj_2078d0@owners@@QAE_NXZ
bool owners::Obj_2078d0::FUN_002078d0() {
    if (field) {
        FUN_00203e30(field);
        return FUN_00207410();
    }
    return false;
}

namespace fn_f49dcb8d {

// 0x002078f0 FUN_002078f0 (103 B): matches/0x002078f0.cpp
// sym: ?Run@Obj_2078f0@fn_f49dcb8d@@QAEDD@Z
// data: gFlag_2078f0 = DAT_004c91da
char Obj_2078f0::Run(char b) {
    if (!m)
        return 0;
    int x = m->Check_00266710();
    flag = 1;
    if (x != 3) {
        if (b)
            Do_00203e30(m);
        else {
            if ((*(char*)&DAT_004c91da)) {
                m->Other_002666e0();
                return 0;
            }
            Do_00203e30(m);
            return 0;
        }
    }
    return Finish_00207410();
}

} // namespace fn_f49dcb8d

// 0x00207960 FUN_00207960 (159 B): matches/0x00207960.cpp [wrapped: conflict: FUN_00267f80]
// sym: ?FUN_00207960@CWorldStreamManager_207960@fn_00207960@@QAEXHHTFlag_207960@2@@Z
namespace fn_00207960 {
// FUN_00207960 @ 0x00207960
// FUN_00207960: (re)start a playing object from the table at +0x578
unsigned int __cdecl FUN_00267f80();

struct Playing_207960 {
    void FUN_00263e90();
};

union Flag_207960 {
    unsigned int word;
    char on;
};

class CWorldStreamManager_207960 {
public:
    char pad000[0x578];
    int table[3];
    int selected;
    char pad588[0xaec - 0x588];
    Playing_207960 *current;
    char padaf0[3];
    char started;
    char padaf4[8];
    unsigned int startTime;

    void FUN_00203e30(Playing_207960 *p);
    void FUN_00207410();
    Playing_207960 *FUN_00203e90(hulk_intptr a, Flag_207960 flag, int z0, hulk_intptr z1, hulk_intptr entry, hulk_intptr first, int seven);   // (decl1, recs1 Q5) pointer-sized where 0x00203e90 takes pointers (the name, the actor, the target, the callback)
    void FUN_00207960(int a, int index, Flag_207960 flag);
};

void CWorldStreamManager_207960::FUN_00207960(int a, int index, Flag_207960 flag)
{
    if (!flag.on)
        startTime = FUN_00267f80();
    if (current) {
        FUN_00203e30(current);
        FUN_00207410();
    }
    Playing_207960 *p = FUN_00203e90(a, flag, 0, 0, table[index], table[0], 7);
    current = p;
    if (flag.on) {
        selected = index;
        started = 1;
        startTime = 0;
    } else {
        p->FUN_00263e90();
        current = 0;
        startTime = 0;
    }
}
} // namespace fn_00207960


// 0x00207b90 FUN_00207b90 (8 B): matches/0x00207b90.cpp
// sym: ?FUN_00207b90@CWorldStreamManager@@QAEXXZ
void CWorldStreamManager::FUN_00207b90() {
    ((CWorldStreamManager_nv_207b90*)(this))->FUN_002071e0(4);
}


// 0x00207ba0 FUN_00207ba0 (471 B): equivalent/0x00207ba0.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_00207ba0@CWorldStreamManager_207ba0@fn_00207ba0@@QAEXXZ @66119de0f620 @w8a30fbbdbfbf @v02a137b2f471
namespace fn_00207ba0 {
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 41/42, incomplete)
// FUN_00207ba0 @ 0x00207ba0
struct Entity {
    char pad0[9];
    char flag9;
    char pad1[0x58 - 0xa];
    int f58;
};
struct Registry_207ba0 {
    Entity* FUN_001c7f10(int id);
};
struct Manager_207ba0 {
    char pad0[4];
    Registry_207ba0* reg;
};
extern Manager_207ba0* FUN_001c3d90();
extern int FUN_00267f80();

struct CWorldStreamManager_207ba0 {
    char pad0[0x5a4];
    char kind[0x400];
    char pad1[0x9a8 - 0x9a4];
    int slotCount;
    int slotId[20];
    int slotVal[20];
    int idCount;
    int ids[39];
    void* cur;
    char pad5[0xaf2 - 0xaf0];
    char flagF2;
    char flagF3;
    char padF4;
    char flagF5;
    char pad6[0xafc - 0xaf6];
    int stamp;

    int FUN_00203bb0();
    int FUN_00204ad0(int count, int* list);
    int FUN_00204c10(int a);
    void FUN_00203e30(void* p);
    void FUN_00207410();
    void FUN_00207080(int a);
    char FUN_00207580(int id, int flag);
    void FUN_00207ba0();
};

void CWorldStreamManager_207ba0::FUN_00207ba0()
{
    stamp = FUN_00267f80();
    flagF5 = 1;
    for (int i = 0; i < idCount; i++) {
        int id = ids[i];
        Entity* e = FUN_001c3d90()->reg->FUN_001c7f10(id);
        e->f58 = 0;
        e->flag9 = 1;
        if (id >= 0 && id < 0x400) {
            char k = kind[id];
            if (k == 1 || k == 3) continue;
            if (cur != 0 && flagF2 == 0 && flagF3 == 0) {
                if (FUN_00203bb0() == id) continue;
            }
        }
        bool useFirst = true;
        int first = FUN_00204ad0(idCount, ids);
        int second = FUN_00204c10(0);
        int sel = first;
        if (second > 0) {
            int j = 0;
            bool found = false;
            while (j < idCount) {
                if (id == ids[j]) { found = true; break; }
                j++;
            }
            if (!found) {
                useFirst = false;
                sel = second;
            }
        }
        bool setId = (kind[id] != 2);
        slotVal[slotCount] = useFirst ? sel : -1;
        slotId[slotCount] = setId ? id : -1;
        slotCount = slotCount + 1;
        if (cur != 0) {
            FUN_00203e30(cur);
            FUN_00207410();
        }
        if (sel > 0) {
            FUN_00207080(sel);
        }
        if (FUN_00207580(id, 1) == 0) {
            slotId[slotCount] = -1;
        }
    }
    stamp = 0;
}
} // namespace fn_00207ba0


// 0x00207d80 FUN_00207d80 (252 B): equivalent/0x00207d80.cpp [wrapped: conflict: FUN_001c3d90; Gfx]
// sym: ?target@CWorldStreamManager_207d80@fn_00207d80@@QAEXXZ @66f750b361eb @wdf497badf1a5 @v400061b77016
namespace fn_00207d80 {
// STATUS: equivalent (tools/equiv.py level 3: 19975 inputs, branch coverage 14/14)
// FUN_00207d80 @ 0x00207d80
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

struct Entry_207d80 { char pad[9]; unsigned char flag; };
struct Manager_207d80 { Entry_207d80* FUN_001c7f10(int); };
struct Context { int unused; Manager_207d80* manager; };
Context* __cdecl FUN_001c3d90();
struct Gfx {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void refresh();
};
struct CWorldStreamManager_207d80 {
 char pad[0x9a8]; int count; int first[20]; int second[20]; int entryCount; int entries[41]; unsigned char flag1,flag2; char pad2[6]; int state;
 int FUN_00267f80(); void FUN_00204e40(); void FUN_00207080(int); void FUN_00207580(int,int); void target();
};
void CWorldStreamManager_207d80::target() {
 state=FUN_00267f80();
 DAT_0052c2a8->refresh();
 if (!FUN_001c3d90()->manager) {
 entryCount=0; count=0; flag1=0; flag2=0; FUN_00204e40(); state=0; return;
 }
 for(int i=0;i<entryCount;++i) {
 int id=entries[i];
 FUN_001c3d90()->manager->FUN_001c7f10(id)->flag=0;
 }
 entryCount=0;
 FUN_00204e40();
 for(int j=0;j<count;++j) {
 if(first[j]>0) FUN_00207080(first[j]);
 if(second[j]>0) FUN_00207580(second[j],1);
 }
 count=0; state=0; flag1=0; flag2=0;
}
} // namespace fn_00207d80
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f49dcb8d {

// 0x00208040 FUN_00208040 (110 B): equivalent/0x00208040.cpp
// sym: ?FUN_00208040@Table_208040@fn_f49dcb8d@@QAE_NHH@Z @f39ec1dd04f1 @w054c6f530fbd @vc76d78348bb8
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 7/8, incomplete)
// FUN_00208040 @ 0x00208040
bool Table_208040::FUN_00208040(int a, int b)
{
    unsigned short *entry = ((unsigned short *)((owners::Owner_204060 *)this)->FUN_00204060(a, b));
    ((owners::C_86310 *)sink)->FUN_00086310();
    if (entry == 0) {
        entry = ((unsigned short *)((owners::Owner_204060 *)this)->FUN_00204060(0, b));
        if (entry == 0)
            return false;
    }
    bool wasEmpty = false;
    DAT_004e5a90 = DAT_004e5a90 + 1;
    if (*entry == 0) {
        FUN_00207e80();
        wasEmpty = true;
    }
    FUN_00207a00(entry);
    return wasEmpty;
}

} // namespace fn_f49dcb8d

// 0x00208210 FUN_00208210 (1544 B): equivalent/0x00208210.cpp [wrapped: conflict: CWorldStreamManager; Closure1; Method1]
// sym: ??0CWorldStreamManager@fn_00208210@@QAE@XZ @db195b140561 @w47512810076e @v36401eacd201
namespace fn_00208210 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_00208210 @ 0x00208210
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

class CWorldStreamManager;

extern "C" void* FUN_0008d690(unsigned size);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, hulk_uintptr);
#endif



template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void* get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void* get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<int> { static const void* get() { return ((char*)&DAT_0048e134); } };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
// (script1) records (include/game/script_bind.h): the game's vftables by address, per instantiation (VftOf), no
// stand-in vftable.
template <class X> struct VftOf;
class MethodBase_208210 : public hulk_script::ScriptVftable, public ScriptFunctionFields {
  public:
    void FUN_001d0480(const char*, int);
    MethodBase_208210(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase_208210 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char* name, Fn f) throw() : MethodBase_208210(name, 1) {
        vftable = VftOf<Method1>::get();
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char* name, T* o, typename Method1<T, R, A>::Fn f) throw() : Method1<T, R, A>(name, f) {
        this->vftable = VftOf<Closure1>::get();
        owner = o;
    }
    T* owner;
};

extern "C" char DAT_00425b44[], DAT_00425c44[];   // Method1 / Closure1<CWorldStreamManager,void,int>
extern "C" char DAT_00425b94[], DAT_00425c94[];   // Method1 / Closure1<CWorldStreamManager,int,int>
extern "C" char DAT_00425bb4[], DAT_00425cb4[];   // Method1 / Closure1<CWorldStreamManager,bool,int>
template <> struct VftOf<Method1<CWorldStreamManager, void, int> > { static void* get() { return DAT_00425b44; } };
template <> struct VftOf<Closure1<CWorldStreamManager, void, int> > { static void* get() { return DAT_00425c44; } };
template <> struct VftOf<Method1<CWorldStreamManager, int, int> > { static void* get() { return DAT_00425b94; } };
template <> struct VftOf<Closure1<CWorldStreamManager, int, int> > { static void* get() { return DAT_00425c94; } };
template <> struct VftOf<Method1<CWorldStreamManager, bool, int> > { static void* get() { return DAT_00425bb4; } };
template <> struct VftOf<Closure1<CWorldStreamManager, bool, int> > { static void* get() { return DAT_00425cb4; } };
struct Closure2_208210 {
    Closure2_208210* FUN_00205e30(const char* name, CWorldStreamManager* owner, int (CWorldStreamManager::*fn)(int, int));
};

class CWorldStreamManager {
  public:
    CWorldStreamManager();
    virtual void* vfn0_00207060(char);

    class CMemoryPool {
      public:
        CMemoryPool() {
            state = 0;
            flagA = 0;
            word26 = 0;
            f2c = 0;
            f30 = 0;
            f34 = 0x80;
            f38 = 0;
        }
        virtual void* vfn0_00206c10(char);
        char state;
        char flagA;
        char pad6[0x26 - 6];
        short word26;
        short count28;
        char pad2a[2];
        void* f2c;                  // (x64t9-mgr) the heap, the resource (0x002047c0), the size, the inventory
        void* f30;
        int f34;
        void* f38;
    };

    void FUN_002036c0(int);
    void FUN_002036e0(int);
    void FUN_00203780(int);
    void FUN_00203e00(int);
    void FUN_002071e0(int);
    int FUN_002042f0(int);
    int FUN_00204410(int);
    bool FUN_00204440(int);
    int FUN_00204320(int);
    bool FUN_00204350(float, float, float);   // (script2) the bound instantiations' signatures (RTTI)
    int FUN_00204200(float, float, float);
    const char* FUN_00203740();
    int FUN_002042a0(int, int);
    int FUN_002043e0();
    bool FUN_001e8710();
    void FUN_00207ba0();
    void FUN_00207d80();
    void FUN_00207960();
    void FUN_00207b90();
    void FUN_002080b0();
    int FUN_00078b40();
    int FUN_002036f0();

    char pad04[0x44 - 4];
    void* f44;
    CMemoryPool pools[20];
    CMemoryPool poolA;
    CMemoryPool poolB;
    void *f570, *f574, *f578, *f57c, *f580;
    char pad584[4];
    void *f588, *f58c, *f590;
    int f594, f598, f59c;
    char pad5a0[4];
    int buf5a4[256];
    int f9a4, f9a8;
    char pad9ac[0xa4c - 0x9ac];
    int fa4c;
    char padA50[0xaa0 - 0xa50];
    void* faa0;
    char name[0x20];
    char nameTerm;
    char padAC5[0xae4 - 0xac5];
    void *fae4, *fae8, *faec;
    char faf0, faf1, faf2, faf3, faf4, faf5;
    char padAF6[2];
    int faf8, fafc;
};
// (x64t9-mgr) include/decls/managers.h's HulkWorldStreamManager / HulkWorldMemoryPool: the pointer words as the
// manager's methods use them (0x002047c0, 0x00204720, 0x00207960, 0x002062d0, 0x00204de0, 0x002067d0, 0x00206320)
HULK_MGR_SAME(CWorldStreamManager::CMemoryPool, HulkWorldMemoryPool);
HULK_MGR_SAME(CWorldStreamManager, HulkWorldStreamManager);

struct Registry_208210 {
    void FUN_001d3b70(const char* name, void* closure);
    void FUN_00206c90(const char* name, CWorldStreamManager* owner, bool (CWorldStreamManager::*fn)(float, float, float));
    void FUN_00206cf0(const char* name, CWorldStreamManager* owner, int (CWorldStreamManager::*fn)(float, float, float));
    void FUN_00206d50(const char* name, CWorldStreamManager* owner, const char* (CWorldStreamManager::*fn)());
    void FUN_00206e60(const char* name, CWorldStreamManager* owner, int (CWorldStreamManager::*fn)());
    void FUN_00206f20(const char* name, CWorldStreamManager* owner, bool (CWorldStreamManager::*fn)());
    void FUN_00206f90(const char* name, CWorldStreamManager* owner, void (CWorldStreamManager::*fn)());
    void FUN_00207000(const char* name, CWorldStreamManager* owner, void (CWorldStreamManager::*fn)());
};
extern "C" Registry_208210* FUN_001d4c90();

CWorldStreamManager::CWorldStreamManager()
{
    f44 = 0;
    f588 = 0;
    f58c = 0;
    f590 = 0;
    f594 = 0;
    f598 = 0;
    f59c = 0;
    f9a4 = 0;
    f9a8 = 0;
    fa4c = 0;
    faa0 = 0;
    fae4 = 0;
    fae8 = 0;
    faec = 0;
    faf0 = 0;
    faf1 = 0;
    faf2 = 0;
    faf3 = 0;
    faf4 = 0;
    faf5 = 0;
    faf8 = 0;
    fafc = 0;

    Registry_208210* reg = FUN_001d4c90();
    if (reg) {
        void* mem;

        { typedef Closure1<CWorldStreamManager, void, int> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldStreamManager, void, int>));
        Closure1<CWorldStreamManager, void, int>* setSync = 0;
        if (mem)
            setSync = new (mem) Closure1<CWorldStreamManager, void, int>("wsm_SetSynchronous", this, &CWorldStreamManager::FUN_002036c0);
        reg->FUN_001d3b70("wsm_SetSynchronous", setSync);

        reg->FUN_00206c90("wm_IsPointInARoom", this, &CWorldStreamManager::FUN_00204350);

        reg->FUN_00206cf0("wm_FindRoomWithPoint", this, &CWorldStreamManager::FUN_00204200);

        reg->FUN_00206d50("wm_GetUniqueName", this, &CWorldStreamManager::FUN_00203740);

        { HULK_SIZE32(ScriptClosureView, 0x24); }
        mem = FUN_0008d690((int)sizeof(ScriptClosureView));
        Closure2_208210* adjacent = 0;
        if (mem)
            adjacent = ((Closure2_208210*)mem)->FUN_00205e30("wm_GetAdjacentRoom", this, &CWorldStreamManager::FUN_002042a0);
        reg->FUN_001d3b70("wm_GetAdjacentRoom", adjacent);

        { typedef Closure1<CWorldStreamManager, int, int> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldStreamManager, int, int>));
        Closure1<CWorldStreamManager, int, int>* numAdjacent = 0;
        if (mem)
            numAdjacent = new (mem) Closure1<CWorldStreamManager, int, int>("wm_GetNumAdjacentRoom", this, &CWorldStreamManager::FUN_002042f0);
        reg->FUN_001d3b70("wm_GetNumAdjacentRoom", numAdjacent);

        reg->FUN_00206e60("wm_GetNumRoomsLoaded", this, &CWorldStreamManager::FUN_002043e0);

        { typedef Closure1<CWorldStreamManager, int, int> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldStreamManager, int, int>));
        Closure1<CWorldStreamManager, int, int>* loadedNum = 0;
        if (mem)
            loadedNum = new (mem) Closure1<CWorldStreamManager, int, int>("wm_GetLoadedRoomNum", this, &CWorldStreamManager::FUN_00204410);
        reg->FUN_001d3b70("wm_GetLoadedRoomNum", loadedNum);

        { typedef Closure1<CWorldStreamManager, bool, int> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldStreamManager, bool, int>));
        Closure1<CWorldStreamManager, bool, int>* roomLoaded = 0;
        if (mem)
            roomLoaded = new (mem) Closure1<CWorldStreamManager, bool, int>("wm_IsRoomLoaded", this, &CWorldStreamManager::FUN_00204440);
        reg->FUN_001d3b70("wm_IsRoomLoaded", roomLoaded);

        reg->FUN_00206f20("wsm_IsLoading", this, &CWorldStreamManager::FUN_001e8710);

        { typedef Closure1<CWorldStreamManager, void, int> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldStreamManager, void, int>));
        Closure1<CWorldStreamManager, void, int>* setRoom = 0;
        if (mem)
            setRoom = new (mem) Closure1<CWorldStreamManager, void, int>("wsm_SetCurrentRoom", this, &CWorldStreamManager::FUN_002036e0);
        reg->FUN_001d3b70("wsm_SetCurrentRoom", setRoom);

        { typedef Closure1<CWorldStreamManager, void, int> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldStreamManager, void, int>));
        Closure1<CWorldStreamManager, void, int>* loadRoom = 0;
        if (mem)
            loadRoom = new (mem) Closure1<CWorldStreamManager, void, int>("wsm_LoadRoomTemp", this, &CWorldStreamManager::FUN_00203780);
        reg->FUN_001d3b70("wsm_LoadRoomTemp", loadRoom);

        reg->FUN_00206f90("wsm_LoadRoomTempFlush", this, &CWorldStreamManager::FUN_00207ba0);

        reg->FUN_00206f90("wsm_UnloadTempRooms", this, &CWorldStreamManager::FUN_00207d80);

        reg->FUN_00207000("wsm_LoadTempFile", this, &CWorldStreamManager::FUN_00207960);

        { typedef Closure1<CWorldStreamManager, void, int> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldStreamManager, void, int>));
        Closure1<CWorldStreamManager, void, int>* unloadTemp = 0;
        if (mem)
            unloadTemp = new (mem) Closure1<CWorldStreamManager, void, int>("wsm_UnloadTempFile", this, &CWorldStreamManager::FUN_00203e00);
        reg->FUN_001d3b70("wsm_UnloadTempFile", unloadTemp);

        reg->FUN_00206f90("wsm_SetupTempMemory", this, &CWorldStreamManager::FUN_00207b90);

        { typedef Closure1<CWorldStreamManager, void, int> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldStreamManager, void, int>));
        Closure1<CWorldStreamManager, void, int>* setupTempEx = 0;
        if (mem)
            setupTempEx = new (mem) Closure1<CWorldStreamManager, void, int>("wsm_SetupTempMemoryEx", this, &CWorldStreamManager::FUN_002071e0);
        reg->FUN_001d3b70("wsm_SetupTempMemoryEx", setupTempEx);

        reg->FUN_00206f90("wsm_ReleaseTempMemory", this, &CWorldStreamManager::FUN_002080b0);

        reg->FUN_00206e60("wsm_GetCurrentRoom", this, &CWorldStreamManager::FUN_00078b40);

        reg->FUN_00206e60("wsm_GetLastRoom", this, &CWorldStreamManager::FUN_002036f0);

        { typedef Closure1<CWorldStreamManager, int, int> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldStreamManager, int, int>));
        Closure1<CWorldStreamManager, int, int>* districtFromRoom = 0;
        if (mem)
            districtFromRoom = new (mem) Closure1<CWorldStreamManager, int, int>("wsm_GetDistrictFromRoom", this, &CWorldStreamManager::FUN_00204320);
        reg->FUN_001d3b70("wsm_GetDistrictFromRoom", districtFromRoom);

        strncpy(name, "hulk", 0x20);
        nameTerm = 0;
        f578 = 0;
        f57c = 0;
        f580 = 0;
        for (int i = 0; i < 256; i++)
            buf5a4[i] = 0;
        f570 = 0;
        f574 = 0;
    }
}
} // namespace fn_00208210
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00208820 FUN_00208820 (127 B): matches/0x00208820.cpp
// sym: ?FUN_00208820@CWorldStreamManager@@QAEXXZ
// data: gFlag_208820 = DAT_004c91da
void CWorldStreamManager::FUN_00208820() {
    if ((*(Subject_208820 * *)&this->f_aec)) {
        int r = (*(Subject_208820 * *)&this->f_aec)->GetState_00266710();
        this->f_af0 = 1;
        if (r == 3)
            ((CWorldStreamManager_nv_208820*)this)->OnState_00207410();
        else if (DAT_004c91da)
            (*(Subject_208820 * *)&this->f_aec)->OnGlobal_002666e0();
        else
            ((CWorldStreamManager_nv_208820*)this)->OnOther_00203e30((*(Subject_208820 * *)&this->f_aec));
    }
    ((CWorldStreamManager_nv_208820*)this)->Step1_002080b0();
    ((CWorldStreamManager_nv_208820*)this)->Step2_00207d80();
    ((CWorldStreamManager_nv_208820*)this)->Step3_00207e80();
    ((CWorldStreamManager_nv_208820*)this)->Step4_00204de0();
    ((CWorldStreamManager_nv_208820*)this)->Step5_002059d0();
    ((owners::C_203a10 *)(((CWorldStreamManager_nv_208820*)this)))->FUN_00203a10();
    this->f_04 = 0;
    this->f_24 = 0;
}

namespace fn_f49dcb8d {

// 0x002088a0 FUN_002088a0 (124 B): equivalent/0x002088a0.cpp
// sym: ?FUN_002088a0@Pool_2088a0@fn_f49dcb8d@@QAEXXZ @94760b38b8c7 @w25f5df33b30b @v540431442a38
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002088a0 @ 0x002088a0
void Pool_2088a0::FUN_002088a0() {
    FUN_00207e80();
    if ((*(char*)&DAT_004c91d8) != 0) {
        for (int i = 0; i < 20; i++) {
            Slot_2088a0 *s = &slots[i];
            if (s->buffer != 0) {
                s->buffer->FUN_00263e90();
                s->buffer = 0;
            }
            if (s->resource != 0) {
                FUN_00267110(s->handle);
            }
            if (s->resource != 0) {
                s->resource->Release();
                s->resource = 0;
            }
            if (s->name != 0) {
                FUN_00267090(s->name);
                s->name = 0;
            }
            s->active = 0;
            s->ready = 0;
            s->handle = 0;
        }
    }
    cleared = 1;
}

} // namespace fn_f49dcb8d

// 0x00208920 FUN_00208920 (196 B): matches/0x00208920.cpp [wrapped: conflict: World]
// sym: ?FUN_00208920@Actor_208920@fn_00208920@@QAE_NXZ
namespace fn_00208920 {
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

struct Transition_208920 {
    char data[28];
    void FUN_001cac80(int oldState, int newState);
};
struct Queue_208920 {
    void FUN_001cbc20(Transition_208920*);
};
struct World {
    char pad[0x30];
    Queue_208920* queue;
};
struct Item_208920 {
    void FUN_000bd1b0(int);
};
struct Holder_208920 {
    Item_208920* FUN_00086280();
};
struct Actor_208920 {
    char pad0[0x588];
    Holder_208920* holder;
    char pad1[0x10];
    int state;
    int previous;
    unsigned char flags[0x400];
    char pad2[0x148];
    void* pending;
    int FUN_00203cd0();
    bool FUN_00208040(int, int);
    void FUN_00203e30(void*);
    void FUN_00207410();
    bool FUN_00208920();
};
bool Actor_208920::FUN_00208920() {
    bool result = false;
    int next = FUN_00203cd0();
    if (!next)
        return false;
    if (next != state) {
        Transition_208920 transition;
        transition.FUN_001cac80(state, next);
        DAT_004dd700->queue->FUN_001cbc20(&transition);
        result = FUN_00208040(state, next);
        if (next < 0 || next >= 0x400 || (flags[next] != 1 && flags[next] != 3)) {
            result = true;
            Item_208920* item = holder->FUN_00086280();
            if (item)
                item->FUN_000bd1b0(0);
            if (pending) {
                FUN_00203e30(pending);
                FUN_00207410();
            }
        }
        previous = state;
        state = next;
    }
    return result;
}
} // namespace fn_00208920
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002089f0 FUN_002089f0 (151 B): equivalent/0x002089f0.cpp
// sym: ?FUN_002089f0@Pump_2089f0@owners@@QAEXXZ @4514210b35bc @w95ef3279148a @vf1b4eea19b13
// STATUS: equivalent (tools/equiv.py level 3: 62 inputs, branch coverage 14/14)
// FUN_002089f0 @ 0x002089f0
void owners::Pump_2089f0::FUN_002089f0()
{
    tick = FUN_00267f80();
    if (pending)
        FUN_00207410();
    if (busy <= 0 && !locked) {
        if (dirty) {
            FUN_00204e40();
            dirty = 0;
        }
        char again = 0;
        for (;;) {
            FUN_00207410();
            char progressed = FUN_00207850(again);
            if (FUN_00208920()) {
                again = 1;
                continue;
            }
            if (!again)
                break;
            again = progressed;
            if (!progressed)
                break;
        }
    }
    tick = 0;
}

namespace fn_f49dcb8d {

// 0x00208a90 FUN_00208a90 (18 B): matches/0x00208a90.cpp
// sym: ??0S_208a90@fn_f49dcb8d@@QAE@XZ
S_208a90::S_208a90() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
}


// 0x00208ab0 FUN_00208ab0 (1 B): matches/0x00208ab0.cpp
// sym: ?FUN_00208ab0@fn_f49dcb8d@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00208ab0(void* /*this, unused: callers pass it (unb4)*/) {}

} // namespace fn_f49dcb8d

// 0x00208ac0 FUN_00208ac0 (28 B): matches/0x00208ac0.cpp
// sym: ?FUN_00208ac0@A_208ac0@owners@@QAEXGG@Z
void owners::A_208ac0::FUN_00208ac0(unsigned short x, unsigned short y) {
    a = x;
    b = y;
    c = 0;
    d = 0;
}


// 0x00208b40 FUN_00208b40 (20 B): matches/0x00208b40.cpp
// sym: ?FUN_00208b40@A_208b40@owners@@QAEXG@Z
void owners::A_208b40::FUN_00208b40(unsigned short x) {
    *(unsigned short*)(pad + 6 + count * 2) = x;
    ++count;
}


// 0x00208b60 FUN_00208b60 (20 B): matches/0x00208b60.cpp
// sym: ?FUN_00208b60@Obj_208b60@owners@@QAEXG@Z
void owners::Obj_208b60::FUN_00208b60(unsigned short value) {
    values[(int)count] = value;
    ++count;
}


// 0x00208b80 FUN_00208b80 (12 B): matches/0x00208b80.cpp
// sym: ?FUN_00208b80@X_208b80@owners@@QAEHH@Z
int owners::X_208b80::FUN_00208b80(int i) {
    return data[i + 3];
}


// 0x00208b90 FUN_00208b90 (12 B): matches/0x00208b90.cpp
// sym: ?FUN_00208b90@C_208b90@owners@@QAEHH@Z
int owners::C_208b90::FUN_00208b90(int index) {
    return items[index];
}

