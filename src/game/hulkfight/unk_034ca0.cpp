// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00034ca0..0x00038290 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9673120 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9673120 {} using namespace fn_f9673120;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f9673120 {
typedef __int64 I64;
extern "C" I64 __cdecl convert(const char*, int, int);
struct X_34fb0 {
    void Call_0027af00();
    X_34fb0* Target();
};
struct X_34fe0 {
    void Call_0027af00();
    X_34fe0* Target();
};
struct X_35000 {
    void Call_0027af00();
    X_35000* Target();
};
struct Vec3 { int x; int y; int z; };
struct BoneEntry {
    char pad0[0x30];
    Vec3 pos;
    char pad1[0x40 - 0x3c];
};
struct Handler {
    void FUN_00059a50(Vec3* out);
};
struct Y_350c0 {
    char p0[0x14];
    int kind;
    char p1[0x18];
    float f30;
    float f34;
    char p2[4];
    float f3c;
};
struct X_350c0 {
    void Fn_00059a50(float* p);
};
struct C_350c0 {
    char p0[0x10];
    X_350c0* x;
    char p1[0x108];
    Y_350c0* y;
    char p2[0x20];
    int mode;
    bool F(float* p);
};
struct Callee_35140 {
    int Run_0027b040(int);
};
struct Obj_35140 {
    char pad[0x1d68];
    int Target(int);
};
struct Blk_35160 {
    unsigned int v[16];
};
struct X_35160 {
    void* get_00059a40();
};
struct Y_35160 {
    char pad[0x10];
    Blk_35160* get_00221c40();
};
struct Target_35160 {
    char pad[0x10];
    X_35160* x;
    bool f(Blk_35160* out);
};
struct Vec3_35190 { float x, y, z; };
struct Transform_35190 {
    char pad0[0x30];
    Vec3_35190 position;
};
class Effect_35190 {
public:
    void FUN_001c5e80(const Vec3_35190* position);
    void FUN_001c5ef0(bool enabled);
};
class Listener_35190 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Transform_35190* t, int flags);
};
class Scene_35190 {
public:
    void FUN_002226e0(Transform_35190* t);
};
class Owner_35190 {
public:
    Scene_35190* FUN_00059a40();
};
class Entity {
public:
    char pad0[0x10];
    Owner_35190* owner;
    char pad14[0x124 - 0x14];
    Effect_35190* effect;
    char pad128[4];
    Listener_35190* listener;
    char pad130[0x140 - 0x130];
    int mode;
    char pad144[0x1a84 - 0x144];
    char effectTarget[1];
    bool FUN_00035190(Transform_35190* t);
};
struct Blk_35250 {
    unsigned int d[16];
};
class Source_35250 {
  public:
    void* Get_00059a40();
};
class Image {
  public:
    Blk_35250* Data_00221c40();
};
class C_35250 {
  public:
    char pad[0x10];
    Source_35250* member;
    int Run(unsigned int* p);
    int Finish_00035190(Blk_35250* b);
};
struct Output { unsigned int x,y,z; };
struct Entry { char pad[0x30]; Output value; char rest[0x40-0x30-12]; };
struct Container { char pad0[12]; unsigned int count; char pad1[12]; Entry* entries; };
struct Selection { char pad[0x20]; unsigned int index; };
struct Triple_353a0 {
    unsigned a, b, c;
};
class Target_353a0 {
    char pad[0x90];
    unsigned x, y, z;

  public:
    bool Copy(Triple_353a0* out);
};
struct Inner_354c0 {
    char pad[0x10];
    void* Get_00059a40();
    float Calc_002220d0();   // returns st0; the Wine build reads it unrounded (clang_probe retfix)
};
struct Owner_354c0 {
    char pad[0x10];
    Inner_354c0* m;
    hulk_freg f();
};
class A_354e0 {
    char pad[16];

  public:
    int Get_00059a40();
};
class Tmp_354e0 {
    char x[64];

  public:
    void Init_0022b980();
    void SetArg_0022ba70(int);
};
class Obj_354e0 {
    char pad[16];

  public:
    bool target(int);
    bool Run_00035190(Tmp_354e0*);
};
struct Result_35550 {
    float a;
    int b;
    int c;
};
struct Payload_35550 {
    void Fill_00222120(Result_35550*);
};
struct Returned {
    char pad[0x10];
    Payload_35550 payload;
};
struct Fetcher {
    Returned* Get_00059a40();
};
struct Obj_35550 {
    char pad[0x10];
    Fetcher* fetch;
    bool Run(Result_35550* out);
};
struct Result_355d0 {
    int a, b, c;
};
struct Helper_355d0 {
    Result_355d0* Get_00222120(Result_355d0*);
};
struct Obj_355d0 {
    char pad[0x14];
    Helper_355d0 helper;
    bool Run(Result_355d0*);
};
struct Cache_35630 {
    void* get_00059a40();
};
struct Result_35630 {
    void run_00221f20(unsigned int, unsigned int);
};
struct Owner_35630 {
    char pad[16];
    Cache_35630* p;
    bool target(hulk_uintptr a, hulk_uintptr b);
};
struct Obj_35680 {
    char pad[0x78];
    float value;
};
class Obj_35690 {
  public:
    char pad[0x74];
    float a;
    char pad2[4];
    float b;
};
class CKeyPoseTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual float vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
};
class Obj_356f0 {
    char pad[0x84];

  public:
    float value;
};
struct V {
    char pad[0x80];
    float a;
    char pad2[4];
    float b;
};
struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x19c];
    struct {
        volatile float x;
        float y, z;
    } pos;

  public:
    void Add(const Vec* v);
};
class C_357e0 {
  public:
    char pad[0x1cc];
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};
struct Vec3_35810 { int x, y, z; float FUN_0022d110(); };
struct Mover_35810 {
    char pad0[0x1e4];
    float duration;
    Vec3_35810 delta;
    float speed, decel;
    int busy;
    void Start(float t, const Vec3_35810* d);
};
struct Obj_358a0 {
    char pad[0x1e4];
    float value;
};
class Queue_35930 {
  public:
    void Send_001cbc20(void*);
};
struct Global_35930 {
    char pad[0x30];
    Queue_35930* q;
};
extern Global_35930* hulk_at_004dd700;
class Temp_35930 {
  public:
    void Build_001ca210(int, int, int);
};
struct Quat_359e0 {
    unsigned x, y, z, w;
    void FUN_00034ca0(Quat_359e0 *src);
};
struct Pose {
    char pad00[0x2c];
    Quat_359e0 orientation;
};
class Source_359e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Pose *GetPose();
};
struct Link_359e0 {
    char pad00[8];
    Pose *pose;
};
struct Target_359e0 {
    void FUN_00059a50(Quat_359e0 *q);
};
class Character_359e0 {
public:
    char pad00[0x10];
    Target_359e0 *target;
    char pad14[0x11c - 0x14];
    Link_359e0 *link;
    char pad120[8];
    Character_359e0 *parent;
    bool FUN_000352b0(Quat_359e0 *q);
    bool FUN_000359e0(Quat_359e0 *out);
};
struct ParentLink {
    char pad00[0x11c];
    Source_359e0 *source;
};
class Inner_35a90 {
  public:
    bool Run_000456e0();
};
class Thing_35a90 {
  public:
    char pad[0x11c];
    Inner_35a90* member;
    bool Run();
};
struct Item {
    __int64 FUN_000443c0();
};
struct Object {
  public:
    char _m_pad_0[0x11c];
    union { Item* item; Selection* selection; };
    Container* container;
    bool FUN_000352b0(Output* out);
    bool FUN_00035ab0();
};
class Target_35ae0 {
public:
    bool FUN_000456e0();
    __int64 FUN_000443c0();
};
class Actor_35ae0 {
public:
    char pad0[0x11c];
    Target_35ae0* target;
    char pad120[0x140 - 0x120];
    int state;
    bool FUN_00035ae0();
};
struct X_35b60 {
    char pad[0x22e4];
    unsigned int value;
};
extern "C" int FUN_000969d0(int);
class Item_35cf0 {
    char pad[0x190];

  public:
    int value;
};
class Helper_35cf0 {
  public:
    int Method_001d73f0();
};
class Obj_35cf0 {
  public:
    char pad0[0x11c];
    Item_35cf0* item;
    char pad120[8];
    Helper_35cf0* thing;
    char pad12c[0x324 - 0x12c];
    int add;
    char pad328[0x1b0c - 0x328];
    float f;
    int FUN();
};
class Thing_35d80 {
    char pad[0x32c];

  public:
    unsigned char a;
    char pad2;
    unsigned char b;
};
struct Vec3_35dc0 {
    float x, y, z;
};
struct Inner_35dc0 {
    void GetVec_00222120(Vec3_35dc0* out);
};
struct Holder_35dc0 {
    char pad[0x10];
    Inner_35dc0 in;
};
struct Sub_35dc0 {
    Holder_35dc0* Find_00059a40();
};
struct Vec3q : Vec3_35dc0 {
    char Query_0022d2b0(Vec3_35dc0* v, unsigned int id);
};
struct Obj_35dc0 {
    char pad0[0x10];
    Sub_35dc0* mSub;
    char pad1[0x2074 - 0x14];
    float a, b, c;
    void Get(Vec3q* out);
};
struct Status { char padding[12]; int mode; };
extern "C" int __cdecl FUN_00044560(Status *);
class Obj_35f40 {
  public:
    char pad[0x3a8];
    int a;
    char p1[0x4c];
    int b;
    char p2[0x4c];
    int c;
    char p3[0x4c];
    int d;
    char p4[0x4c];
    int e;
    char p5[0x4c];
    int f;
    char p6[0x4c];
    int g;
    char p7[0x4c];
    int h;
};
typedef unsigned char u8_35fa0;
struct Item_35fa0 {
    char pad[0x74];
    void* sub;
};
struct Slot_35fa0 {
};
struct Sub_35fa0 {
    char pad[0x72];
    u8_35fa0 value;
};
struct Entry_35fa0 {
    Slot_35fa0* slot;
    char pad[0x4c];
};
struct Obj_35fa0 {
    char pad[0x3a8];
    Entry_35fa0 entries[8];
    void Set(u8_35fa0);
};
class Context {
  public:
    int Query_001d5e80(int);
};
class Obj_35fe0 {
  public:
    char pad[0x40];
    int arg;
    char pad2[0xa8];
    Context* ctx;
};
struct Slot_35fe0 {
    Obj_35fe0* p;
    char pad[0x4c];
};
class Owner_35fe0 {
  public:
    char pad[0x3a8];
    Slot_35fe0 items[8];
    int Find();
};
class Target_36090 {
    char pad[0x1b14];

  public:
    float value;
};
struct Obj_360b0 {
    char pad[0x11c];
    void* ptr;
    char pad2[0x1b14 - 0x120];
    float value;
};
class Obj_36170 {
    char pad[0x1b18];

  public:
    float value;
    int count;
};
struct D {
    char pad[0x1a4];
    int v;
};
class C_36270 {
  public:
    char pad[0x11c];
    D* p;
    char pad2[0x1f8];
    int a;
    int b;
    int f();
};
struct Sub_363d0 {
    void Run_00232240();
};
struct Thing_363d0 {
    char pad[0xdc];
    Sub_363d0 sub;
    char pad2[0x1e58 - 0xdc - 4];
    int field;
    void f();
};
class Child_363f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int);
};
class Owner_363f0 {
  public:
    char pad0[0x118];
    unsigned char a;
    unsigned char b;
    char pad1[0x1ca0 - 0x11a];
    Child_363f0* p;
    char pad2[0x22e0 - 0x1ca4];
    unsigned char c;
    void f(int, int);
};
class Next_36430 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int, int);
};
class Child_36430 {
  public:
    void run_00060170();
};
class Obj_36430 {
  public:
    char pad118[0x118];
    unsigned char a;
    unsigned char b;
    char pad11a[0x1ca0 - 0x11a];
    Next_36430* next;
    char pad1ca4[0x1f58 - 0x1ca4];
    Child_36430 child;
    char pad1f5c[0x22e0 - 0x1f59];
    unsigned char c;
    void target(int, int);
};
struct Vec3_36480 { float x, y, z; };
struct Mat_36480 {
    float m[16];
};
struct Xform_36480 {
    char pad0[4];
    const Mat_36480 *FUN_00221c40();
};
struct Body_36480 {
    char pad0[0x10];
    Xform_36480 xform;
};
struct Fighter_36480 { char pad[4]; };
Body_36480 *__fastcall FUN_00059a40(Fighter_36480 *f);
class Drawable_36480;
struct Holder_36480 {
    char pad0[0x20];
    Drawable_36480 *target;
};
class Drawable_36480 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Draw(const Mat_36480 *m, int arg);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad04[0x74 - 4];
    Holder_36480 *holder;
};
struct Props_36480 {
    char pad0[0x30];
    float f30;
    float f34;
};
class Overlay_36480 {
public:
    char pad0[1];
    void FUN_001d6b60(Mat_36480 m, int flag);
};
class Actor_36480 {
public:
    char pad0[0x10];
    Fighter_36480 *fighter;
    char pad14[0x11c - 0x14];
    Props_36480 *props;
    char pad120[0x128 - 0x120];
    Overlay_36480 *overlay;
    Drawable_36480 *shadow;
    Drawable_36480 *shape;
    char pad134[0x140 - 0x134];
    int mode;
    char pad144[0x22e0 - 0x144];
    char overlayEnabled;
    void FUN_00035550(Vec3_36480 *out);
    void FUN_00036480(int unused, int arg);
};
struct Frame_36480 {
    Vec3_36480 offset;
    Mat_36480 shadowMat;
    Mat_36480 bodyMat;
};
typedef unsigned long U32_365f0;
struct Names_365f0 { int FUN_0027b200(U32_365f0,U32_365f0); };
struct Attachment_365f0 { void FUN_002ef8b0(int); };
struct Helper_366d0 {
    void method_00231f20(int);
};
struct Target_366d0 {
    unsigned char pad[0x118];
    unsigned char flag;
};
struct V3_366f0 { float x, y, z; };
struct Matrix {
  public:
    float m[12];
    V3_366f0 pos;
    char _m_pad_3c[0x4];
    void FUN_0022b980();
};
struct Skeleton {
  public:
    char _m_pad_0[0x8];
    Names_365f0* names;
    char _m_pad_c[0x10];
    union { BoneEntry* bones; Matrix* matrices; };
    int FUN_002843a0(__int64 key);
};
struct Character {
    char pad0[0x10];
    Handler* handler;
    char pad1[0x120 - 0x14];
    Skeleton* skeleton;
    bool FUN_00035020(Vec3* out);
};
struct Model_365f0 { char pad[0x64]; Skeleton* skeleton; };
struct Provider_365f0 { Model_365f0* FUN_00059a40(); };
struct Weapon_365f0 { char pad[0x100]; Attachment_365f0* attachment; void FUN_00080e50(Matrix*); };
struct Actor_365f0 { char pad[0x10]; Provider_365f0* provider; char pad2[0x618]; Weapon_365f0* weapon; void target(int,int); };
struct Sub2324b0 { void FUN_002324b0(int a); };
struct Attach_366f0 {
    char pad[0x10];
    Attach_366f0* inner;
    void FUN_001c5e80(V3_366f0* p);
    void FUN_001c5ef0(bool b);
};
struct Obj000366f0 {
    char pad0[0x10];
    void* owner;
    char pad1[0xdc - 0x14];
    Sub2324b0 sub;
    char pad2[0x118 - 0xdc - 1];
    char skip;
    char pad3[0x124 - 0x119];
    Attach_366f0* attach;
    char pad4[0x140 - 0x128];
    int mode;
    char pad5[0x308 - 0x144];
    float f308;
    float f30c;
    float f310;
    float f314;
    char pad6[0x1a84 - 0x318];
    V3_366f0 vec1a84;
    char pad7[0x20b0 - 0x1a90];
    int flag20b0;
    void FUN_000366f0(int unused, float dt);
};
extern "C" void __fastcall FUN_0022b980(Matrix* m);
extern void* __fastcall FUN_00059a40(void* o);
extern Matrix* __fastcall FUN_00221c40(void* p);
struct ThisNote_001c5080 {
};
class Obj_368d0 {
  public:
    char pad[0x72];
    unsigned char flag;
};
class Holder_368d0 {
  public:
    char pad[0x74];
    Obj_368d0* obj;
};
class Result_368d0 {
  public:
    char pad[0x74];
    Obj_368d0* obj;
};
class Thing_368d0 {
  public:
    char pad[0x128];
    Context* context;
    Holder_368d0* holder;
    void Set(unsigned char);
};
struct Temp_36a20 {
    char data[16];
    bool Test();
};
struct Obj_36a20 {
    char pad[0x1d78];
    unsigned char flag;
    unsigned char result;
    void Make_000359e0(Temp_36a20* t);
};
struct Global_36a20 {
    char pad[0x20];
    int x;
};
extern Global_36a20* gGlobal_36a20;
extern "C" bool __stdcall FUN_00025d30(Obj_36a20* o);
struct Single_36a20 { bool Test_001c4010(Temp_36a20* t); };
extern "C" Single_36a20* FUN_001c3d90();
struct A_36a80 {
    char pad[0x10];
    int value;
};
struct B_36a80 {
    char pad[0x11c];
    int value;
};
struct Inner_36ac0 {
    unsigned char data[1];
};
struct Holder_36ac0 {
    char pad[0x1c];
    Inner_36ac0* inner;
};
struct Service_36ac0 {
    int Check_00059a40();
};
struct Obj_36ac0 {
    char pad0[0x10];
    Service_36ac0* field10;
    char pad1[0x10c];
    Holder_36ac0* holder;
    char pad2[0x1f54 - 0x124];
    unsigned int index;
    bool target(unsigned int* out);
};
struct Vec3_36b10 {
    float x, y, z;
};
class Player_36b10 {
public:
    void FUN_00035fa0(int flag);
};
} // namespace fn_f9673120
class World {
public:
    char pad0[0x124];
    Player_36b10* player;
};
namespace fn_f9673120 {
class Target_36b10 {
public:
    char FUN_0022d2b0(int a, float f);
};
class Manager_36b10 {
public:
    char FUN_001b4ab0(Target_36b10* target, int a, int b, Vec3_36b10* out, char* flagA, char* flagB);
};
class Owner_36b10 {
public:
    char pad0[0x10];
    Manager_36b10* manager;
    char pad14[0xc];
    World* world;
};
class Builder {
  public:
    void Make_00059a50(void*);
};
class Dest_36be0 {
  public:
};
class Obj_36be0 {
  public:
    char pad[0x10];
    Builder* builder;
    char pad2[0x1ca0 - 0x14];
    int m1ca0;
    void Run(hulk_intptr);
};
struct T_36d00 {
    char pad[0x20b8];
};
class Target_36d30 {
    char pad[0x20f8];
};
extern "C" void __cdecl FUN_00267760(char*, unsigned int, const char*, ...);
struct Key_36d90 { unsigned int low, high; };
struct Entry_36d90 {
 unsigned int low, high;
 unsigned int value, extra;
 char FUN_0027af90(Key_36d90* key);
 void FUN_0027af70(Key_36d90* key);
};
struct Cache_36d90 {
 char padding[0x2150];
 Entry_36d90 entries[16];
 int next;
 int FUN_00036d90(Key_36d90* key);
};
typedef unsigned int u32_36e40;
class Item_36e70 {
  public:
    char pad[0x10];
    char Check_0027af90(int key);
};
class Owner_36e70 {
  public:
    char pad[0x2150];
    Item_36e70 items[16];
    int Find_00036d90(int key);
    char Update(hulk_intptr key, int value);
};
struct Key_36f00 { unsigned int low, high; };
struct Entry_36f00 { unsigned int low, high; unsigned char flag, active; char pad[6]; bool FUN_0027af90(Key_36f00*); void FUN_0027af70(Key_36f00*); };
struct Manager_36f00 { char pad[0x2258]; Entry_36f00 entries[4]; int next; char tailPad[4]; unsigned char extraFlag; unsigned char extraActive; int FUN_00036f00(Key_36f00* key); };
struct Entry_37000 {
    unsigned char a;
    unsigned char flag;
    unsigned char rest[14];
};
struct Obj_37000 {
    unsigned char pad[0x2260];
    Entry_37000 entries[4];
};
class Helper_37000 {
  public:
};
class Target_373d0 {
    char pad[0x22e0];

  public:
    unsigned char value;
};
class Obj_37400 {
    char pad[0x22b4];

  public:
    int value;
};
class Obj_37510 {
  public:
    virtual void A();
    virtual void B();
};
struct V3_375a0 {
    float x;
    float y;
    float z;
};
class Plane {
  public:
    float x, y, z, d;
    Plane(const Vec* a, const Vec* b);
};
class Obj_37710 {
  public:
    char pad[0x1c];
    int value;
    int a;
    int b;
    void init_0027af00();
};
class Obj_37750 {
  public:
    virtual void f0();
    virtual void f1();
};
class Holder_37750 {
  public:
    Obj_37750* a;
    Obj_37750* b;
    void Clear();
};
class Ref_37780 {
  public:
    virtual void A();
    virtual void B();
};
struct V3_37780 {
    int x, y, z;
    void Set(const V3_37780* o) {
        x = o->x;
        y = o->y;
        z = o->z;
    }
};
struct Ptr_37780 {
    Ref_37780* r;
    void Set(Ref_37780* n) {
        if (n)
            n->A();
        if (r)
            r->B();
        r = n;
    }
};
class Obj_37780 {
  public:
    Ptr_37780 a;
    Ptr_37780 b;
    int x;
    V3_37780 p;
    V3_37780 q;
    int z;
    void Set(Ref_37780*, Ref_37780*, int, V3_37780*, V3_37780*, int);
};
class Obj_37800 {
  public:
    virtual void f0();
    virtual void f1();
};
class Holder_37800 {
  public:
    Obj_37800* a;
    Obj_37800* b;
    void Clear();
};

} // namespace fn_f9673120

// 0x00034ca0 FUN_00034ca0 (31 B): matches/0x00034ca0.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ??4Vec4@fn_00034ca0@@QAEAAU01@ABU01@@Z
namespace fn_00034ca0 {
struct Vec4 {
    int a, b, c, d;
    Vec4& operator=(const Vec4&);
};
Vec4& Vec4::operator=(const Vec4& x) {
    a = x.a;
    b = x.b;
    c = x.c;
    d = x.d;
    return *this;
}
} // namespace fn_00034ca0


// 0x00034ce0 FUN_00034ce0 (33 B): matches/0x00034ce0.cpp
// sym: ?FUN_00034ce0@Obj_34ce0@owners@@QAEHPBD@Z
int owners::Obj_34ce0::FUN_00034ce0(const char* s) {
    return take(convert(s, 0, 0));
}


// 0x00034d80 FUN_00034d80 (37 B): matches/0x00034d80.cpp
// sym: ?FUN_00034d80@C_34d80@owners@@QAEXHPAI@Z
void owners::C_34d80::FUN_00034d80(int index, unsigned int* src) {
    unsigned int* dst = (unsigned int*)(base + index * 0x40 + 0x30);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}


// 0x00034e60 FUN_00034e60 (4 B): matches/0x00034e60.cpp
// sym: ?FUN_00034e60@C_34e60@owners@@QAEMXZ
float owners::C_34e60::FUN_00034e60() {
    return *(float*)((char*)this + 0x18);
}

namespace fn_f9673120 {

// 0x00034fb0 FUN_00034fb0 (12 B): matches/0x00034fb0.cpp
// sym: ?Target@X_34fb0@fn_f9673120@@QAEPAU12@XZ
// Same code shape as 0x00034ad0 (propagated; names are from that function)
X_34fb0* X_34fb0::Target() {
    Call_0027af00();
    return this;
}


// 0x00034fe0 FUN_00034fe0 (12 B): matches/0x00034fe0.cpp
// sym: ?Target@X_34fe0@fn_f9673120@@QAEPAU12@XZ
// Same code shape as 0x00034ad0 (propagated; names are from that function)
X_34fe0* X_34fe0::Target() {
    Call_0027af00();
    return this;
}


// 0x00035000 FUN_00035000 (12 B): matches/0x00035000.cpp
// sym: ?Target@X_35000@fn_f9673120@@QAEPAU12@XZ
// Same code shape as 0x00034ad0 (propagated; names are from that function)
X_35000* X_35000::Target() {
    Call_0027af00();
    return this;
}


// 0x00035020 FUN_00035020 (149 B): equivalent/0x00035020.cpp
// sym: ?FUN_00035020@Character@fn_f9673120@@QAE_NPAUVec3@2@@Z @9c4cfcf5dede @wc1b0056985ca
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 6/6)
// FUN_00035020 @ 0x00035020
bool Character::FUN_00035020(Vec3* out)
{
    // the skeleton pointer is re-read after every call, as in the original
    Skeleton* volatile* slot = &skeleton;
    Skeleton* sk = *slot;
    if (sk == 0)
        return false;
    int bone = sk->FUN_002843a0(FUN_002672f0("Head", 0, 0));
    if (bone == 0xffff) {
        sk = *slot;
        bone = sk->FUN_002843a0(FUN_002672f0("Neck", 0, 0));
        if (bone == 0xffff) {
            handler->FUN_00059a50(out);
            return false;
        }
    }
    sk = *slot;
    *out = sk->bones[bone].pos;
    return true;
}


// 0x000350c0 FUN_000350c0 (113 B): matches/0x000350c0.cpp
// sym: ?F@C_350c0@fn_f9673120@@QAE_NPAM@Z
bool C_350c0::F(float* p) {
    x->Fn_00059a50(p);
    Y_350c0* q;
    if (mode == 1 && (q = y) != 0) {
        hulk_freg v = q->f30;
        if (v <= 0.0f)
            v = q->f34 + q->f34;
        double r = v * 0.5f + (double)p[1];
        p[1] = r;
        int k = y->kind;
        if (k == 2 || k == 3)
            p[1] = (float)(y->f3c * 0.5f + r);
    }
    return true;
}


// 0x00035140 FUN_00035140 (11 B): matches/0x00035140.cpp
// sym: ?Target@Obj_35140@fn_f9673120@@QAEHH@Z
int Obj_35140::Target(int a0) {
    return ((Callee_35140*)((char*)this + 0x1d68))->Run_0027b040(a0);
}


// 0x00035160 FUN_00035160 (47 B): matches/0x00035160.cpp
// sym: ?f@Target_35160@fn_f9673120@@QAE_NPAUBlk_35160@2@@Z
bool Target_35160::f(Blk_35160* out) {
    void* p = x->get_00059a40();
    if (p) {
        Blk_35160* src = ((Y_35160*)((char*)p + 0x10))->get_00221c40();
        *out = *src;
        return true;
    }
    return false;
}


// 0x00035190 FUN_00035190 (120 B): matches/0x00035190.cpp
// sym: ?FUN_00035190@Entity@fn_f9673120@@QAE_NPAUTransform_35190@2@@Z
// FUN_00035190 @ 0x00035190
bool Entity::FUN_00035190(Transform_35190* t) {
    Scene_35190* scene = owner->FUN_00059a40();
    if (!scene)
        return false;
    scene->FUN_002226e0(t);
    if (effect) {
        effect->FUN_001c5e80(&t->position);
        ((owners::Owner_1c5ed0 *)effect)->FUN_001c5ed0(effectTarget);
        effect->FUN_001c5ef0(mode == 3);
    }
    if (listener)
        listener->v6(t, 0);
    return true;
}

} // namespace fn_f9673120

// 0x00035230 FUN_00035230 (26 B): matches/0x00035230.cpp
// sym: ?FUN_00035230@Obj_35230@owners@@QAE_NPAI@Z
bool owners::Obj_35230::FUN_00035230(unsigned* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}

namespace fn_f9673120 {

// 0x00035250 FUN_00035250 (86 B): matches/0x00035250.cpp
// sym: ?Run@C_35250@fn_f9673120@@QAEHPAI@Z
int C_35250::Run(unsigned int* p) {
    Blk_35250 local;
    void* x = member->Get_00059a40();
    if (x) {
        Image* q = (Image*)((char*)x + 0x10);
        Blk_35250* src = q->Data_00221c40();
        local = *src;
    }
    local.d[12] = p[0];
    local.d[13] = p[1];
    local.d[14] = p[2];
    return Finish_00035190(&local);
}


// 0x000352b0 FUN_000352b0 (77 B): equivalent/0x000352b0.cpp
// sym: ?FUN_000352b0@Object@fn_f9673120@@QAE_NPAUOutput@2@@Z @e40e295a3209 @w05368ed57493
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 8/8)
// FUN_000352b0 @ 0x000352b0
bool Object::FUN_000352b0(Output* out) {
    Container* c = container;
    if (!c) return false;
    Selection* s = selection;
    if (!s) return false;
    unsigned int i = s->index;
    if (i == 0xffff || i >= c->count) return false;
    out->x = c->entries[i].value.x;
    out->y = c->entries[i].value.y;
    out->z = c->entries[i].value.z;
    return true;
}

} // namespace fn_f9673120

// 0x00035350 FUN_00035350 (77 B): equivalent/0x00035350.cpp [wrapped: conflict: Entry; Selection]
// sym: ?FUN_00035350@Object@fn_00035350@@QAEEPAUPoint@2@@Z @1698c03bc4c3 @wfa17755f936f
namespace fn_00035350 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00035350 @ 0x00035350
struct Point { unsigned x,y,z; }; struct Entry { char pad[0x30]; Point point; char rest[0x40-0x30-12]; }; struct Table { char pad0[12]; unsigned count; char pad1[12]; Entry *entries; }; struct Selection { char pad[0x28]; unsigned index; }; struct Object { char pad[0x11c]; Selection *selection; Table *table; unsigned char FUN_00035350(Point *out); }; unsigned char Object::FUN_00035350(Point *out) { if (table && selection && selection->index != 0xffff && selection->index < table->count) { *out = table->entries[selection->index].point; return 1; } return 0; }
} // namespace fn_00035350

namespace fn_f9673120 {

// 0x000353a0 FUN_000353a0 (35 B): matches/0x000353a0.cpp
// sym: ?Copy@Target_353a0@fn_f9673120@@QAE_NPAUTriple_353a0@2@@Z
bool Target_353a0::Copy(Triple_353a0* out) {
    out->a = x;
    out->b = y;
    out->c = z;
    return true;
}

} // namespace fn_f9673120

// 0x000353d0 FUN_000353d0 (35 B): matches/0x000353d0.cpp
// sym: ?FUN_000353d0@C_353d0@owners@@QAE_NPBH@Z
bool owners::C_353d0::FUN_000353d0(const int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return true;
}


// 0x00035400 FUN_00035400 (35 B): matches/0x00035400.cpp
// sym: ?FUN_00035400@Obj_35400@owners@@QAE_NPAI@Z
bool owners::Obj_35400::FUN_00035400(unsigned int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}


// 0x00035430 FUN_00035430 (35 B): matches/0x00035430.cpp
// sym: ?FUN_00035430@C_35430@owners@@QAE_NPAI@Z
bool owners::C_35430::FUN_00035430(unsigned* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return true;
}


// 0x00035460 FUN_00035460 (35 B): matches/0x00035460.cpp
// sym: ?FUN_00035460@C_35460@owners@@QAE_NPAI@Z
bool owners::C_35460::FUN_00035460(unsigned* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}


// 0x00035490 FUN_00035490 (35 B): matches/0x00035490.cpp
// sym: ?FUN_00035490@Obj_35490@owners@@QAE_NPAI@Z
bool owners::Obj_35490::FUN_00035490(unsigned* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return true;
}

namespace fn_f9673120 {

// 0x000354c0 FUN_000354c0 (27 B): matches/0x000354c0.cpp
// sym: ?f@Owner_354c0@fn_f9673120@@QAEMXZ
// data: gZero_354c0 = DAT_003f32e0
// The original tail-jumps to FUN_002220d0: its st0 (the unrounded heading) is this function's result, so the
// clang build must not round it to float here: the definition returns hulk_freg (callees stay declared float).
hulk_freg Owner_354c0::f() {
    Inner_354c0* p = m;
    void* q = p->Get_00059a40();
    if (!q)
        return DAT_003f32e0;
    return ((Inner_354c0*)((char*)q + 0x10))->Calc_002220d0();
}


// 0x000354e0 FUN_000354e0 (87 B): matches/0x000354e0.cpp
// sym: ?target@Obj_354e0@fn_f9673120@@QAE_NH@Z
bool Obj_354e0::target(int arg) {
    int p = ((A_354e0*)*(hulk_intptr*)((char*)this + 0x10))->Get_00059a40();
    if (!p)
        return false;
    Tmp_354e0 t;
    t.Init_0022b980();
    t.SetArg_0022ba70(arg);
    ((owners::Target_22be40 *)&t)->FUN_0022be40((const int *)(hulk_uintptr)(int)(p + 0x40));
    return Run_00035190(&t);
}


// 0x00035550 FUN_00035550 (66 B): matches/0x00035550.cpp
// sym: ?Run@Obj_35550@fn_f9673120@@QAE_NPAUResult_35550@2@@Z
bool Obj_35550::Run(Result_35550* out) {
    Fetcher* f = fetch;
    Result_35550 local;
    Returned* r = f->Get_00059a40();
    if (!r)
        return false;
    r->payload.Fill_00222120(&local);
    out->a = local.a;
    out->b = local.b;
    out->c = local.c;
    return true;
}


// 0x000355d0 FUN_000355d0 (43 B): matches/0x000355d0.cpp
// sym: ?Run@Obj_355d0@fn_f9673120@@QAE_NPAUResult_355d0@2@@Z
bool Obj_355d0::Run(Result_355d0* out) {
    Result_355d0 local;
    Result_355d0* r = helper.Get_00222120(&local);
    *out = *r;
    return true;
}


// 0x00035630 FUN_00035630 (40 B): matches/0x00035630.cpp
// sym: ?target@Owner_35630@fn_f9673120@@QAE_NII@Z
bool Owner_35630::target(hulk_uintptr a, hulk_uintptr b) {
    void* x = p->get_00059a40();
    if (!x)
        return false;
    ((Result_35630*)((char*)x + 16))->run_00221f20(a, b);
    return true;
}

} // namespace fn_f9673120

// 0x00035660 FUN_00035660 (26 B): matches/0x00035660.cpp
// sym: ?FUN_00035660@C_35660@owners@@QAE_NPAH@Z
bool owners::C_35660::FUN_00035660(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}

namespace fn_f9673120 {

// 0x00035680 FUN_00035680 (4 B): matches/0x00035680.cpp
// sym: ?FUN_00035680@fn_f9673120@@YIMPAUObj_35680@1@@Z
float __fastcall FUN_00035680(Obj_35680* self) {
    return self->value;
}


// 0x00035690 FUN_00035690 (23 B): matches/0x00035690.cpp
// sym: ?FUN_00035690@fn_f9673120@@YIMPAVObj_35690@1@@Z
hulk_freg __fastcall FUN_00035690(Obj_35690* p) {
    return sqrt((double)p->b * p->b + (double)p->a * p->a);
}


// 0x000356b0 FUN_000356b0 (7 B): matches/0x000356b0.cpp
// sym: ?vfunc_7@CKeyPoseTrack@fn_f9673120@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
float CKeyPoseTrack::vfunc_7() {
    return DAT_003f32dc;
}

} // namespace fn_f9673120

// 0x000356c0 FUN_000356c0 (35 B): matches/0x000356c0.cpp
// sym: ?FUN_000356c0@Thing_356c0@owners@@QAE_NPAI@Z
bool owners::Thing_356c0::FUN_000356c0(unsigned int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}

namespace fn_f9673120 {

// 0x000356f0 FUN_000356f0 (7 B): matches/0x000356f0.cpp
// sym: ?FUN_000356f0@fn_f9673120@@YIMPAVObj_356f0@1@@Z
float __fastcall FUN_000356f0(Obj_356f0* self) {
    return self->value;
}


// 0x00035700 FUN_00035700 (29 B): matches/0x00035700.cpp
// sym: ?FUN_00035700@fn_f9673120@@YIMPAUV@1@@Z
hulk_freg __fastcall FUN_00035700(V* p) {
    return sqrt((double)p->b * p->b + (double)p->a * p->a);
}


// 0x00035720 FUN_00035720 (51 B): matches/0x00035720.cpp
// sym: ?Add@Obj@fn_f9673120@@QAEXPBUVec@2@@Z
void Obj::Add(const Vec* v) {
    pos.x += v->x;
    pos.y += v->y;
    pos.z += v->z;
}

} // namespace fn_f9673120

// 0x00035760 FUN_00035760 (51 B): matches/0x00035760.cpp [wrapped: conflict: Obj]
// sym: ?Add@Obj@fn_00035760@@QAEXPAUVec@2@@Z
namespace fn_00035760 {
struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x1a8];
    volatile float x;
    float y, z;

  public:
    void Add(Vec* v);
};
void Obj::Add(Vec* v) {
    x = x + v->x;
    y = v->y + y;
    z = v->z + z;
}
} // namespace fn_00035760


// 0x000357a0 FUN_000357a0 (51 B): matches/0x000357a0.cpp
// sym: ?FUN_000357a0@C_357a0@owners@@QAEXPAM@Z
void owners::C_357a0::FUN_000357a0(float* p) {
    a = a + p[0];
    b = p[1] + b;
    c = p[2] + c;
}

namespace fn_f9673120 {

// 0x000357e0 FUN_000357e0 (39 B): matches/0x000357e0.cpp
// sym: ?FUN_000357e0@fn_f9673120@@YIXPAVC_357e0@1@@Z
void __fastcall FUN_000357e0(C_357e0* p) {
    p->c = 0;
    p->b = 0;
    p->a = 0;
    p->f = 0;
    p->e = 0;
    p->d = 0;
}


// 0x00035810 FUN_00035810 (137 B): equivalent/0x00035810.cpp
// sym: ?Start@Mover_35810@fn_f9673120@@QAEXMPBUVec3_35810@2@@Z @62afac99c897 @w7d5a8bdd7412
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00035810 @ 0x00035810
void Mover_35810::Start(float t, const Vec3_35810* d) {
    if (busy > 0 || !(t > (*(float*)&DAT_003f32e0))) return;
    duration = t;
    delta.x = d->x; delta.y = d->y; delta.z = d->z;
    delta.y = 0;
    float len = delta.FUN_0022d110();
    speed = len + len;
    decel = ((len * duration - (len + len) * duration) * 2.0f) / (duration * duration);
}


// 0x000358a0 FUN_000358a0 (28 B): matches/0x000358a0.cpp
// sym: ?target@fn_f9673120@@YIHPAUObj_358a0@1@@Z
// data: zero_358a0 = DAT_003f32e0
int __fastcall target(Obj_358a0* self) {
    return self->value > DAT_003f32e0;
}

} // namespace fn_f9673120

// 0x000358c0 FUN_000358c0 (75 B): matches/0x000358c0.cpp
// sym: ?FUN_000358c0@C_358c0@owners@@QAEX_N@Z
void owners::C_358c0::FUN_000358c0(bool x) {
    if (x) {
        ++count;
        if (count > 0) {
            a = 0;
            b = 0;
            c = 0;
            d = 0;
            e = 0;
            f = 0;
        }
    } else
        --count;
}


// 0x00035910 FUN_00035910 (7 B): matches/0x00035910.cpp
// sym: ?FUN_00035910@Widget_35910@owners@@QAEHXZ
hulk_intptr owners::Widget_35910::FUN_00035910() {
    return mValue;
}


// 0x00035930 FUN_00035930 (79 B): matches/0x00035930.cpp
// sym: ?FUN_00035930@Obj_35930@owners@@QAEXH@Z
void owners::Obj_35930::FUN_00035930(int x) {
    char local[28];
    int old = value;
    if (old != x) {
        Queue_35930* q = hulk_at_004dd700->q;
        if (q) {
            ((Temp_35930*)local)->Build_001ca210(old, x, *ptr);
            q->Send_001cbc20(local);
        }
        value = x;
    }
}


// 0x00035980 FUN_00035980 (34 B): matches/0x00035980.cpp
// sym: ?FUN_00035980@C_35980@owners@@QAEX_N@Z
void owners::C_35980::FUN_00035980(bool x) {
    if (x)
        ++value;
    else
        --value;
}


// 0x000359c0 FUN_000359c0 (29 B): matches/0x000359c0.cpp
// sym: ?FUN_000359c0@C_359c0@owners@@QAEXH@Z
void owners::C_359c0::FUN_000359c0(int x) {
    if (value == 0 || x == value || x > value)
        value = x;
}

namespace fn_f9673120 {

// 0x000359e0 FUN_000359e0 (161 B): matches/0x000359e0.cpp
// sym: ?FUN_000359e0@Character_359e0@fn_f9673120@@QAE_NPAUQuat_359e0@2@@Z
// FUN_000359e0 @ 0x000359e0
// FUN_000359e0 @ 0x000359e0: fetches the current orientation of a character (own or its parent's) and applies it
bool Character_359e0::FUN_000359e0(Quat_359e0 *out)
{
    if (link == 0)
        return false;
    Pose *pose = link->pose;
    if (pose != 0) {
        out->x = pose->orientation.x;
        out->y = pose->orientation.y;
        out->z = pose->orientation.z;
        out->w = pose->orientation.w;
        if (!FUN_000352b0(out))
            target->FUN_00059a50(out);
        return true;
    }
    if (parent != 0) {
        Source_359e0 *source = ((ParentLink *)parent)->source;
        if (source != 0) {
            Pose *p = source->GetPose();
            if (p != 0) {
                out->FUN_00034ca0(&p->orientation);
                if (!FUN_000352b0(out))
                    target->FUN_00059a50(out);
                return true;
            }
        }
    }
    return false;
}


// 0x00035a90 FUN_00035a90 (18 B): matches/0x00035a90.cpp
// sym: ?Run@Thing_35a90@fn_f9673120@@QAE_NXZ
bool Thing_35a90::Run() {
    if (!member)
        return false;
    return member->Run_000456e0();
}


// 0x00035ab0 FUN_00035ab0 (43 B): matches/0x00035ab0.cpp
// sym: ?FUN_00035ab0@Object@fn_f9673120@@QAE_NXZ
bool Object::FUN_00035ab0() {
    Item* p = item;
    if (!p)
        return false;
    __int64 value = p->FUN_000443c0();
    return value == (*(__int64*)&DAT_004dc0e0);
}


// 0x00035ae0 FUN_00035ae0 (121 B): equivalent/0x00035ae0.cpp
// sym: ?FUN_00035ae0@Actor_35ae0@fn_f9673120@@QAE_NXZ @aa45b3ce99c4 @w27849bdf0b4a
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 22/22)
// FUN_00035ae0 @ 0x00035ae0
bool Actor_35ae0::FUN_00035ae0() {
    if (!target)
        return false;
    if (target->FUN_000456e0())
        return true;
    __int64 id = target->FUN_000443c0();
    if (id == DAT_004dc0a8)
        return true;
    if (id == DAT_004dc068)
        return true;
    if (id == DAT_004dc0b8)
        return state == 3;
    if (id == DAT_004dc0c8)
        return state == 3;
    return false;
}


// 0x00035b60 FUN_00035b60 (7 B): matches/0x00035b60.cpp
// sym: ?target@fn_f9673120@@YIIPAUX_35b60@1@@Z
hulk_uintptr __fastcall target(X_35b60* self) {
    return self->value;
}

} // namespace fn_f9673120

// 0x00035b70 FUN_00035b70 (181 B): equivalent/0x00035b70.cpp
// sym: ?FUN_00035b70@State_35b70@owners@@QAEXMMM@Z @029b210d5ee1 @w5985f47c1529
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 14/14)
// FUN_00035b70 @ 0x00035b70
void owners::State_35b70::FUN_00035b70(float a, float b, float c) {
    if (b <= 0.0f)
        return;
    hulk_freg len = b;
    hulk_freg stop = c;
    if (start > 0.0f && a > start) {
        len = len - (a - start);
    } else
        start = a;
    if (duration > 0.0f && len < duration) {
        stop = stop - (duration - len);
    } else
        duration = len;
    if (!(end > 0.0f) || !(stop > end))
        end = stop;
}


// 0x00035c30 FUN_00035c30 (58 B): matches/0x00035c30.cpp
// sym: ?FUN_00035c30@Thing_35c30@owners@@QAE_NH@Z
bool owners::Thing_35c30::FUN_00035c30(hulk_intptr x) {
    int v = FUN_000969d0(((int)x));
    int i = 0;
    if (count > 0) {
        do {
            if (values[i] == v)
                return true;
            ++i;
        } while (i < count);
    }
    return false;
}


// 0x00035c70 FUN_00035c70 (87 B): matches/0x00035c70.cpp
// sym: ?FUN_00035c70@Queue_35c70@owners@@QAEXH@Z
void owners::Queue_35c70::FUN_00035c70(hulk_intptr value) {
    int result = FUN_000969d0(((int)value));
    if (count >= 64) {
        entries[index] = result;
        index = (index + 1) % 64;
        return;
    }
    entries[count] = result;
    ++count;
}


// 0x00035cd0 FUN_00035cd0 (15 B): matches/0x00035cd0.cpp
// sym: ?FUN_00035cd0@C_35cd0@owners@@QAEXXZ
void owners::C_35cd0::FUN_00035cd0() {
    a = 0;
    b = 0;
}


// 0x00035ce0 FUN_00035ce0 (13 B): matches/0x00035ce0.cpp
// sym: ?FUN_00035ce0@Target_35ce0@owners@@QAEXE@Z
void owners::Target_35ce0::FUN_00035ce0(unsigned char x) {
    value = x;
}

namespace fn_f9673120 {

// 0x00035cf0 FUN_00035cf0 (84 B): matches/0x00035cf0.cpp
// sym: ?FUN@Obj_35cf0@fn_f9673120@@QAEHXZ
// data: zero_35cf0 = DAT_003f32e0
int Obj_35cf0::FUN() {
    int x = 100;
    if (item)
        x = item->value + 100;
    x += add;
    if (thing)
        x += thing->Method_001d73f0();
    if (f <= DAT_003f32e0 && x > 0)
        return 0;
    return x;
}


// 0x00035d80 FUN_00035d80 (26 B): matches/0x00035d80.cpp
// sym: ?FUN_00035d80@fn_f9673120@@YIEPAVThing_35d80@1@@Z
unsigned char __fastcall FUN_00035d80(Thing_35d80* self) {
    if (self->b && self->a)
        return 1;
    return 0;
}


// 0x00035da0 FUN_00035da0 (6 B): matches/0x00035da0.cpp
// sym: _FUN_00035da0
// data: gValue_35da0 = DAT_004dc290
extern "C" unsigned char __cdecl FUN_00035da0() {
    return (*(unsigned char*)&DAT_004dc290);
}


// 0x00035db0 FUN_00035db0 (16 B): matches/0x00035db0.cpp
// sym: _FUN_00035db0
// data: gState_35db0 = DAT_004dc290
extern "C" unsigned char __cdecl FUN_00035db0(unsigned char value) {
    unsigned char old = (*(unsigned char*)&DAT_004dc290);
    (*(unsigned char*)&DAT_004dc290) = value;
    return old;
}


// 0x00035dc0 FUN_00035dc0 (135 B): matches/0x00035dc0.cpp
// sym: ?Get@Obj_35dc0@fn_f9673120@@QAEXPAUVec3q@2@@Z
void Obj_35dc0::Get(Vec3q* out) {
    out->x = a;
    out->y = b;
    out->z = c;
    Vec3_35dc0 t;
    t.x = 0;
    t.y = 0;
    t.z = 0;
    if (out->Query_0022d2b0(&t, 0x3727c5ac)) {
        Holder_35dc0* h = mSub->Find_00059a40();
        if (h) {
            h->in.GetVec_00222120(&t);
            out->x = t.x;
            out->y = t.y;
            out->z = t.z;
        }
    }
}


// 0x00035e70 FUN_00035e70 (93 B): equivalent/0x00035e70.cpp
// sym: _FUN_00035e70 @2b9cbd71e42e @wd12c8636c396
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 12/12)
// FUN_00035e70 @ 0x00035e70
// equiv-conv: FUN_00035e70 eax stack
extern "C" unsigned int FUN_00035e70(Status *status, float value)
{
    if (status->mode != 1)
        return ((hulk_uintptr)status & ~255u) | 1u;
    int category = FUN_00044560(status);
    float limit = 0.0f;
    switch (category) {
    case 0: limit = (*(float*)&DAT_003f5c48); break;
    case 1: case 4: case 5: limit = (*(float*)&DAT_003f5c44); break;
    case 2: case 3: limit = (*(float*)&DAT_003f3f08); break;
    }
    return value > limit ? 1 : 0;
}

} // namespace fn_f9673120

// 0x00035ef0 FUN_00035ef0 (34 B): matches/0x00035ef0.cpp
// sym: ?FUN_00035ef0@C_35ef0@owners@@QAEHH@Z
hulk_intptr owners::C_35ef0::FUN_00035ef0(hulk_intptr i) {
    if (((int)i) >= 0 && ((int)i) < 8)
        return values[((int)i)][0];
    return 0;
}


// 0x00035f20 FUN_00035f20 (28 B): matches/0x00035f20.cpp
// sym: ?FUN_00035f20@C_35f20@owners@@QAE_NXZ
bool owners::C_35f20::FUN_00035f20() {
    int i = 0;
    do {
        if (a[i][0] != 0)
            return true;
        ++i;
    } while (i < 8);
    return false;
}

namespace fn_f9673120 {

// 0x00035f40 FUN_00035f40 (95 B): matches/0x00035f40.cpp
// sym: ?FUN_00035f40@fn_f9673120@@YIHPAVObj_35f40@1@@Z
int __fastcall FUN_00035f40(Obj_35f40* x) {
    int n = 0;
    if (x->a)
        n = 1;
    if (x->b)
        ++n;
    if (x->c)
        ++n;
    if (x->d)
        ++n;
    if (x->e)
        ++n;
    if (x->f)
        ++n;
    if (x->g)
        ++n;
    if (x->h)
        ++n;
    return n;
}


// 0x00035fa0 FUN_00035fa0 (55 B): matches/0x00035fa0.cpp
// sym: ?Set@Obj_35fa0@fn_f9673120@@QAEXE@Z
void Obj_35fa0::Set(u8_35fa0 value) {
    for (int i = 0; i < 8; ++i) {
        Slot_35fa0* s = entries[i].slot;
        if (s) {
            Item_35fa0* p = ((Item_35fa0 *)((owners::C_1d72e0 *)s)->FUN_001d72e0());
            if (p && p->sub)
                ((Sub_35fa0*)p->sub)->value = value;
        }
    }
}


// 0x00035fe0 FUN_00035fe0 (64 B): matches/0x00035fe0.cpp
// sym: ?Find@Owner_35fe0@fn_f9673120@@QAEHXZ
int Owner_35fe0::Find() {
    for (int i = 0; i < 8; ++i) {
        Obj_35fe0* p = items[i].p;
        if (p) {
            int a = p->arg;
            Context* c = p->ctx;
            if (c->Query_001d5e80(a) == 2)
                return i;
        }
    }
    return -1;
}

} // namespace fn_f9673120

// 0x00036020 FUN_00036020 (7 B): matches/0x00036020.cpp
// sym: ?FUN_00036020@Thing_36020@owners@@QAEIXZ
hulk_uintptr owners::Thing_36020::FUN_00036020() {
    return value;
}


// 0x00036030 FUN_00036030 (7 B): matches/0x00036030.cpp
// sym: ?FUN_00036030@C_36030@owners@@QAEIXZ
hulk_uintptr owners::C_36030::FUN_00036030() {
    return value;
}


// 0x00036040 FUN_00036040 (66 B): matches/0x00036040.cpp
// sym: ?FUN_00036040@Obj_36040@owners@@QAEDM@Z
char owners::Obj_36040::FUN_00036040(float x) {
    if (b <= 0.0f)
        return 0;
    b = x;
    if (a > x)
        a = x;
    return 1;
}

namespace fn_f9673120 {

// 0x00036090 FUN_00036090 (7 B): matches/0x00036090.cpp
// sym: ?TargetFunction@fn_f9673120@@YIMPAVTarget_36090@1@@Z
float __fastcall TargetFunction(Target_36090* self) {
    return self->value;
}


// 0x000360b0 FUN_000360b0 (30 B): matches/0x000360b0.cpp
// sym: ?FUN_000360b0@fn_f9673120@@YIMPAUObj_360b0@1@@Z
// data: g_zero_360b0 = DAT_003f32e0
hulk_freg __fastcall FUN_000360b0(Obj_360b0* p) {
    if (p->ptr)
        return p->value * *(float*)((char*)p->ptr + 0x134);
    return DAT_003f32e0;
}

} // namespace fn_f9673120

// 0x000360f0 FUN_000360f0 (36 B): matches/0x000360f0.cpp
// sym: ?FUN_000360f0@Thing_360f0@owners@@QAE_NXZ
// data: Zero_360f0 = DAT_003f32e0
bool owners::Thing_360f0::FUN_000360f0() {
    if (value > (*(float*)&DAT_003f32e0))
        return true;
    return count > 0;
}


// 0x00036120 FUN_00036120 (19 B): matches/0x00036120.cpp
// sym: ?FUN_00036120@C_36120@owners@@QAEXM@Z
void owners::C_36120::FUN_00036120(float x) {
    value += x;
}


// 0x00036140 FUN_00036140 (34 B): matches/0x00036140.cpp
// sym: ?FUN_00036140@C_36140@owners@@QAEXD@Z
void owners::C_36140::FUN_00036140(char b) {
    if (b)
        ++value;
    else
        --value;
}

namespace fn_f9673120 {

// 0x00036170 FUN_00036170 (36 B): matches/0x00036170.cpp
// sym: ?FUN_00036170@fn_f9673120@@YI_NPAVObj_36170@1@@Z
// data: zero_36170 = DAT_003f32e0
bool __fastcall FUN_00036170(Obj_36170* self) {
    if (self->value > DAT_003f32e0)
        return true;
    return self->count > 0;
}

} // namespace fn_f9673120

// 0x000361a0 FUN_000361a0 (19 B): matches/0x000361a0.cpp
// sym: ?FUN_000361a0@A_361a0@owners@@QAEXM@Z
void owners::A_361a0::FUN_000361a0(float v) {
    x += v;
}


// 0x000361c0 FUN_000361c0 (34 B): matches/0x000361c0.cpp
// sym: ?FUN_000361c0@C_361c0@owners@@QAEXD@Z
void owners::C_361c0::FUN_000361c0(char b) {
    if (b)
        ++value;
    else
        --value;
}


// 0x000361f0 FUN_000361f0 (34 B): matches/0x000361f0.cpp
// sym: ?FUN_000361f0@X_361f0@owners@@QAEXD@Z
void owners::X_361f0::FUN_000361f0(char b) {
    if (b)
        ++value;
    else
        --value;
}


// 0x00036220 FUN_00036220 (34 B): matches/0x00036220.cpp
// sym: ?FUN_00036220@Thing_36220@owners@@QAEXD@Z
void owners::Thing_36220::FUN_00036220(char up) {
    if (up)
        ++value;
    else
        --value;
}


// 0x00036250 FUN_00036250 (23 B): matches/0x00036250.cpp
// sym: ?FUN_00036250@C_36250@owners@@QAEXH@Z
void owners::C_36250::FUN_00036250(int x) {
    a = x;
    if (!x)
        b = x;
}

namespace fn_f9673120 {

// 0x00036270 FUN_00036270 (33 B): matches/0x00036270.cpp
// sym: ?f@C_36270@fn_f9673120@@QAEHXZ
int C_36270::f() {
    int x = 0;
    if (p != 0)
        x = p->v;
    return b + a + x;
}

} // namespace fn_f9673120

// 0x000362f0 FUN_000362f0 (90 B): matches/0x000362f0.cpp
// sym: ?FUN_000362f0@Obj_362f0@owners@@QAEXXZ
// data: gCounter_362f0 = DAT_004dc2a8
void owners::Obj_362f0::FUN_000362f0() {
    if (enabled) {
        int n = ++(*(int*)&DAT_004dc2a8);
        flag = (n % 2 == 0);
        if (n % 3 == 1)
            mode = 0;
        else
            mode = (n % 3 != 2) + 1;
    }
}


// 0x00036350 FUN_00036350 (114 B): equivalent/0x00036350.cpp
// sym: ?FUN_00036350@Owner_36350@owners@@QAEXHM@Z @4db40eefc333 @w10d811df56c6
// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 12/14, incomplete)
// FUN_00036350 @ 0x00036350
void owners::Owner_36350::FUN_00036350(int index, float offset)
{
    if (index < 0 || index >= 14)
        return;
    bool odd = (index % 2) != 0;
    if (odd == (flip != 0))
        values[index] = FUN_000964e0() + offset;
    else
        values[index] = FUN_000964e0();
    dirty[index] = 1;
}

namespace fn_f9673120 {

// 0x000363d0 FUN_000363d0 (26 B): matches/0x000363d0.cpp
// sym: ?f@Thing_363d0@fn_f9673120@@QAEXXZ
void Thing_363d0::f() {
    sub.Run_00232240();
    field = 0;
}


// 0x000363f0 FUN_000363f0 (50 B): matches/0x000363f0.cpp
// sym: ?f@Owner_363f0@fn_f9673120@@QAEXHH@Z
void Owner_363f0::f(int x, int y) {
    if (!a && !b && c && p)
        p->f3(x, y);
}


// 0x00036430 FUN_00036430 (66 B): matches/0x00036430.cpp
// sym: ?target@Obj_36430@fn_f9673120@@QAEXHH@Z
void Obj_36430::target(int x, int y) {
    if (!a && !b && c) {
        child.run_00060170();
        if (next) {
            next->f4(x, y);
            return;
        }
    }
}


// 0x00036480 FUN_00036480 (365 B): equivalent/0x00036480.cpp
// sym: ?FUN_00036480@Actor_36480@fn_f9673120@@QAEXHH@Z @6b7509058f36 @w131f430801cb
// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 16/16)
// FUN_00036480 @ 0x00036480
void Actor_36480::FUN_00036480(int unused, int arg)
{
    Frame_36480 f;
    FUN_00059a40(fighter);
    Body_36480 *body = FUN_00059a40(fighter);
    if (body != 0)
        f.bodyMat = *body->xform.FUN_00221c40();
    if (shadow != 0) {
        f.shadowMat = f.bodyMat;
        if (mode == 4) {
            FUN_00035550(&f.offset);
            hulk_freg k = props->f34 * -1.1f;
            f.offset.y = f.offset.y * k;
            f.offset.z = f.offset.z * k;
            f.shadowMat.m[12] = f.shadowMat.m[12] + f.offset.x * k;
            f.shadowMat.m[13] = f.shadowMat.m[13] + f.offset.y;
            f.shadowMat.m[14] = f.shadowMat.m[14] + f.offset.z;
            f.shadowMat.m[13] = f.shadowMat.m[13] - props->f30 * 0.5f;
        } else if (mode == 3) {
            f.shadowMat.m[13] = f.shadowMat.m[13] - props->f30 * 0.5f;
        }
        shadow->Draw(&f.shadowMat, arg);
    }
    if (shape != 0)
        shape->Draw(&f.bodyMat, arg);
    if (overlay != 0 && overlayEnabled != 0) {
        Drawable_36480 *d = ((Drawable_36480 *)((owners::C_1d72e0 *)overlay)->FUN_001d72e0());
        if (d != 0) {
            d->Draw(&f.bodyMat, 0);
            d->holder->target->v10();
        }
        overlay->FUN_001d6b60(f.bodyMat, 0);
    }
}


// 0x000365f0 FUN_000365f0 (213 B): equivalent/0x000365f0.cpp
// sym: ?target@Actor_365f0@fn_f9673120@@QAEXHH@Z @bf4aa2dfc8ca @w4ce63d4661bc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000365f0 @ 0x000365f0
void Actor_365f0::target(int,int) {
 Model_365f0* model=provider->FUN_00059a40();
 Weapon_365f0* w=weapon;
 if(w) {
  if(!((*(U32_365f0*)&DAT_004dc2b8) & 1)) {
   (*(U32_365f0*)&DAT_004dc2b8) |= 1;
   unsigned __int64 key=FUN_0027b020("Wealded_Weap_1");
   (*(U32_365f0*)&DAT_004dc2b0)=(U32_365f0)key;
   (*(U32_365f0*)&DAT_004dc2b4)=(U32_365f0)(key>>32);
  }
  int index=model->skeleton->names->FUN_0027b200((*(U32_365f0*)&DAT_004dc2b0),(*(U32_365f0*)&DAT_004dc2b4));
  if(w->attachment) w->attachment->FUN_002ef8b0(0);
  Matrix bone=model->skeleton->matrices[index];
  Matrix identity;
  identity.FUN_0022b980();
  Matrix result;
  ((owners::Matrix_22ca90 *)&result)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Matrix *)(&identity), (const owners::Matrix_22ca90 *)(const Matrix *)(&bone));
  w->FUN_00080e50(&result);
 }
}


// 0x000366d0 FUN_000366d0 (26 B): matches/0x000366d0.cpp
// sym: ?target@fn_f9673120@@YIXPAUTarget_366d0@1@PAXHH@Z
void __fastcall target(Target_366d0* self, void*, int a, int b) {
    if (self->flag == 0)
        ((Helper_366d0*)((char*)self + 0xdc))->method_00231f20(1);
}


// 0x000366f0 FUN_000366f0 (470 B): equivalent/0x000366f0.cpp
// sym: ?FUN_000366f0@Obj000366f0@fn_f9673120@@QAEXHM@Z @852d79ed200f @w2539dea88abe
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 28/28)
// FUN_000366f0 @ 0x000366f0
// FUN_000366f0 @ 0x000366f0
void Obj000366f0::FUN_000366f0(int unused, float dt)
{
    if (skip != 0) return;
    if (f310 > 0.0f && f30c <= 0.0f) {
        float v = dt / f310 * (1.0f - f314) + f314;
        f314 = v;
        if (v > 1.0f) f314 = 1.0f;
        f310 = f310 - dt;
    }
    if (f308 > 0.0f) {
        f308 = f308 - dt;
    }
    if (f308 <= 0.0f && f30c > 0.0f) {
        f314 = 0.01f;
        f30c = f30c - dt;
    }
    if (f310 <= 0.0f && f30c <= 0.0f) {
        f314 = 1.0f;
    }
    sub.FUN_002324b0(1);
    if (attach != 0) {
        Matrix m;
        FUN_0022b980(&m);
        void* o = FUN_00059a40(owner);
        if (o != 0) {
            Matrix* src = FUN_00221c40((char*)o + 0x10);
            m = *src;
        }
        ((owners::Obj_1c5e40 *)attach)->FUN_001c5e40((hulk_uintptr)(Matrix *)(&m));
        attach->FUN_001c5e80(&m.pos);
        ((owners::Owner_1c5ed0 *)attach)->FUN_001c5ed0((V3_366f0 *)(&vec1a84));
        attach->FUN_001c5ef0(mode == 3);
        if (flag20b0 == 1) {
            if (attach->inner != 0) {
                ((owners::Blend_1c5080 *)(((ThisNote_001c5080*)(attach->inner))))->FUN_001c5080((*(float*)&DAT_00421894), 1.5f);
            }
        }
    }
}


// 0x000368d0 FUN_000368d0 (58 B): matches/0x000368d0.cpp
// sym: ?Set@Thing_368d0@fn_f9673120@@QAEXE@Z
void Thing_368d0::Set(unsigned char value) {
    if (holder && holder->obj)
        holder->obj->flag = value;
    if (context) {
        Result_368d0* b = ((Result_368d0 *)((owners::C_1d72e0 *)context)->FUN_001d72e0());
        if (b && b->obj)
            b->obj->flag = value;
    }
}

} // namespace fn_f9673120

// 0x00036910 FUN_00036910 (27 B): matches/0x00036910.cpp
// sym: ?FUN_00036910@C_36910@owners@@QAEXE@Z
void owners::C_36910::FUN_00036910(unsigned char x) {
    hulk_intptr p = *(int*)((char*)this + 0x12c);
    if (p && *(int*)(p + 0x74))
        *(unsigned char*)(*(hulk_intptr*)(p + 0x74) + 0x72) = x;
}


// 0x00036950 FUN_00036950 (24 B): matches/0x00036950.cpp
// sym: ?FUN_00036950@A_36950@owners@@QAEEH@Z
unsigned char owners::A_36950::FUN_00036950(int x) {
    if (a)
        return 0;
    return b;
}

namespace fn_f9673120 {

// 0x00036a20 FUN_00036a20 (95 B): matches/0x00036a20.cpp
// sym: ?Target@fn_f9673120@@YIXPAUObj_36a20@1@@Z
void __fastcall Target(Obj_36a20* self) {
    Temp_36a20 temp;
    if (self->flag == 1) {
        self->result = 0;
        return;
    }
    if (gGlobal_36a20->x != 0 && FUN_00025d30(self)) {
        self->result = 0;
        return;
    }
    self->Make_000359e0(&temp);
    self->result = FUN_001c3d90()->Test_001c4010(&temp) ? 0 : 1;
}

} // namespace fn_f9673120

// 0x00036a80 FUN_00036a80 (37 B): matches/0x00036a80.cpp
// sym: ?FUN_00036a80@Obj_36a80@owners@@QAEHH@Z
hulk_intptr owners::Obj_36a80::FUN_00036a80(int unused) {
    int result = 0;
    void* p = a;
    if (p)
        return ((A_36a80*)p)->value;
    p = b;
    if (p)
        result = ((B_36a80*)p)->value;
    return result;
}

namespace fn_f9673120 {

// 0x00036ac0 FUN_00036ac0 (76 B): matches/0x00036ac0.cpp
// sym: ?target@Obj_36ac0@fn_f9673120@@QAE_NPAI@Z
bool Obj_36ac0::target(unsigned int* out) {
    if (!field10->Check_00059a40())
        return false;
    unsigned int i = index;
    if (i == 0xffff)
        return false;
    unsigned int* src = (unsigned int*)(holder->inner->data + i * 0x40 + 0x30);
    out[0] = src[0];
    out[1] = src[1];
    out[2] = src[2];
    return true;
}


// 0x00036b10 FUN_00036b10 (139 B): equivalent/0x00036b10.cpp
// sym: _FUN_00036b10 @5ad9e328095c @w133619325bdd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00036b10 @ 0x00036b10
// Try the cheap test first; otherwise ask the manager, with the player's flag raised around the request.
extern "C" char __cdecl FUN_00036b10(Owner_36b10* owner, Target_36b10* target, hulk_intptr a, hulk_intptr b, Vec3_36b10* out, char* flagA, char* flagB)
{
    out->z = 0;
    out->y = 0;
    out->x = 0;
    *flagB = 0;
    *flagA = 1;

    Player_36b10* player = owner->world->player;
    if (player != 0) {
        player->FUN_00035fa0(0);
    }
    if (target->FUN_0022d2b0(a, 1.0f)) {
        return 1;
    }
    char result = owner->manager->FUN_001b4ab0(target, a, b, out, flagA, flagB);
    if (player != 0) {
        player->FUN_00035fa0(1);
    }
    return result;
}


// 0x00036be0 FUN_00036be0 (58 B): matches/0x00036be0.cpp
// sym: ?Run@Obj_36be0@fn_f9673120@@QAEXH@Z
void Obj_36be0::Run(hulk_intptr arg) {
    char local[12];
    hulk_intptr value = m1ca0;
    if (value) {
        Dest_36be0* p = (Dest_36be0*)(value + 0x58);
        if (p) {
            builder->Make_00059a50(local);
            ((owners::C_fddf0 *)p)->FUN_000fddf0((void *)(hulk_uintptr)(int)arg, (unsigned *)local);
        }
    }
}

} // namespace fn_f9673120

// 0x00036c20 FUN_00036c20 (23 B): matches/0x00036c20.cpp
// sym: ?FUN_00036c20@Thing_36c20@owners@@QAEXH@Z
void owners::Thing_36c20::FUN_00036c20(hulk_intptr x) {
    a = ((int)x);
    b = 0x3e800000;
}


// 0x00036c40 FUN_00036c40 (23 B): matches/0x00036c40.cpp
// sym: ?FUN_00036c40@Obj_36c40@owners@@QAEXII@Z
void owners::Obj_36c40::FUN_00036c40(unsigned int index, unsigned int value) {
    if (index < 0x20)
        slots[index] = value;
}


// 0x00036c60 FUN_00036c60 (24 B): matches/0x00036c60.cpp
// sym: ?FUN_00036c60@C_36c60@owners@@QAEII@Z
hulk_uintptr owners::C_36c60::FUN_00036c60(unsigned int i) {
    if (i >= 32)
        return 0;
    return values[i];
}

namespace fn_f9673120 {

// 0x00036c80 FUN_00036c80 (6 B): matches/0x00036c80.cpp
// sym: _FUN_00036c80
extern "C" unsigned int FUN_00036c80(void) {
    return 0x20;
}

} // namespace fn_f9673120

// 0x00036c90 FUN_00036c90 (23 B): matches/0x00036c90.cpp
// sym: ?FUN_00036c90@C_36c90@owners@@QAEXII@Z
void owners::C_36c90::FUN_00036c90(unsigned int index, unsigned int value) {
    if (index < 0x10)
        *(unsigned int*)(pad + 0x1e04 + index * 4) = value;
}


// 0x00036cb0 FUN_00036cb0 (24 B): matches/0x00036cb0.cpp
// sym: ?FUN_00036cb0@X_36cb0@owners@@QAEII@Z
unsigned int owners::X_36cb0::FUN_00036cb0(unsigned int i) {
    if (i >= 16)
        return 0;
    return values[i];
}

namespace fn_f9673120 {

// 0x00036d00 FUN_00036d00 (7 B): matches/0x00036d00.cpp
// sym: @FUN_00036d00@4
extern "C" T_36d00* __fastcall FUN_00036d00(T_36d00* self) {
    return (T_36d00*)((char*)self + 0x20b8);
}


// 0x00036d30 FUN_00036d30 (7 B): matches/0x00036d30.cpp
// sym: ?FUN_00036d30@fn_f9673120@@YIPAVTarget_36d30@1@PAV21@@Z
Target_36d30* __fastcall FUN_00036d30(Target_36d30* self) {
    return (Target_36d30*)((char*)self + 0x20f8);
}

} // namespace fn_f9673120

// 0x00036d40 FUN_00036d40 (22 B): matches/0x00036d40.cpp
// sym: ?FUN_00036d40@C_36d40@owners@@QAEXH@Z
void owners::C_36d40::FUN_00036d40(int x) {
    if (x >= 0 && x < 0xe)
        value = x;
}


// 0x00036d60 FUN_00036d60 (45 B): matches/0x00036d60.cpp
// sym: ?FUN_00036d60@Obj_36d60@owners@@QAEXPBD@Z
void owners::Obj_36d60::FUN_00036d60(const char* arg) {
    FUN_00267760((char*)this + 0x20b8, 0x40, "%s", arg);
    ((owners::Obj_36d60*)((char*)this + 8))->Finish(arg);
}

namespace fn_f9673120 {

// 0x00036d90 FUN_00036d90 (171 B): equivalent/0x00036d90.cpp
// sym: ?FUN_00036d90@Cache_36d90@fn_f9673120@@QAEHPAUKey_36d90@2@@Z @2635586c8c76 @w9ecd693759e9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_00036d90 @ 0x00036d90
int Cache_36d90::FUN_00036d90(Key_36d90* key) {
 if ((key->low | key->high) == 0) return -1;
 for (int i=0;i<16;++i) {
  if (entries[i].FUN_0027af90(key)) return i;
 }
 int chosen=next;
 entries[chosen].FUN_0027af70(key);
 entries[chosen].value=0;
 for (int j=0;j<16;++j) {
  if ((entries[j].low | entries[j].high)==0) {
   next=j;
   return chosen;
  }
 }
 next=(chosen+1)%16;
 return chosen;
}

} // namespace fn_f9673120

// 0x00036e40 FUN_00036e40 (37 B): matches/0x00036e40.cpp
// sym: ?FUN_00036e40@Obj_36e40@owners@@QAEII@Z
u32_36e40 owners::Obj_36e40::FUN_00036e40(hulk_uintptr arg) {
    int i = FUN_00036d90(((u32_36e40)arg));
    if (i < 0)
        return 0;
    return *(u32_36e40*)((char*)this + 0x2158 + i * 16);
}

namespace fn_f9673120 {

// 0x00036e70 FUN_00036e70 (135 B): matches/0x00036e70.cpp
// sym: ?Update@Owner_36e70@fn_f9673120@@QAEDHH@Z
char Owner_36e70::Update(hulk_intptr key, int value) {
    int i;
    if (value == 0) {
        for (i = 0; i < 16; ++i) {
            if (items[i].Check_0027af90(key)) {
                ((owners::Target_27b040 *)&(items[i]))->FUN_0027b040((hulk_uintptr)0);
                *(int*)((char*)this + 0x2158 + i * 16) = 0;
                return 1;
            }
        }
        return 1;
    }
    i = Find_00036d90(key);
    if (i < 0)
        return 0;
    *(int*)((char*)this + 0x2158 + i * 16) = value;
    return 1;
}


// 0x00036f00 FUN_00036f00 (196 B): equivalent/0x00036f00.cpp
// sym: ?FUN_00036f00@Manager_36f00@fn_f9673120@@QAEHPAUKey_36f00@2@@Z @fe2773bf9c64 @w0f36e6379d06
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_00036f00 @ 0x00036f00
int Manager_36f00::FUN_00036f00(Key_36f00* key) {
 if ((key->low | key->high)==0) return -1;
 for(int i=0;i<4;++i) if(entries[i].FUN_0027af90(key)) return i;
 int slot=next;
 entries[slot].FUN_0027af70(key);
 entries[slot].flag=0;
 extraActive=1;
 int empty=0;
 for(;empty<4;++empty) if((entries[empty].low|entries[empty].high)==0) break;
 if(empty<4) next=empty;
 else next=(slot+1)%4;
 return slot;
}

} // namespace fn_f9673120

// 0x00036fd0 FUN_00036fd0 (38 B): matches/0x00036fd0.cpp
// sym: ?FUN_00036fd0@Thing_36fd0@owners@@QAEEH@Z
unsigned char owners::Thing_36fd0::FUN_00036fd0(hulk_intptr arg) {
    int index = FUN_00036f00(((int)arg));
    if (index < 0)
        return 0;
    return *((unsigned char*)this + ((index + 0x226) << 4));
}

namespace fn_f9673120 {

// 0x00037000 FUN_00037000 (58 B): matches/0x00037000.cpp
// sym: ?target@fn_f9673120@@YIXPAUObj_37000@1@@Z
void __fastcall target(Obj_37000* self) {
    Entry_37000* p = self->entries;
    int n = 4;
    do {
        if (p->flag) {
            p->a = 0;
            Helper_37000* h = (Helper_37000*)((char*)p - 8);
            ((owners::Pair_27af60 *)h)->FUN_0027af60(0, 0);
        }
        ++p;
        --n;
    } while (n != 0);
    *(int*)((char*)self + 0x2298) = 0;
}

} // namespace fn_f9673120

// 0x00037040 FUN_00037040 (59 B): matches/0x00037040.cpp
// sym: ?FUN_00037040@C_37040@owners@@QAE_NHHH@Z
bool owners::C_37040::FUN_00037040(hulk_intptr key, int a, int b) {
    int n = Find(((int)key));
    if (n < 0)
        return false;
    ((char*)this)[(n + 0x226) * 16] = (char)a;
    ((char*)this)[n * 16 + 0x2261] = (char)b;
    return true;
}


// 0x00037080 FUN_00037080 (153 B): equivalent/0x00037080.cpp [wrapped: conflict: World]
// sym: ?FUN_00037080@Tracker_37080@fn_00037080@@QAEDHD@Z @828194b297d9 @w3b8c4d2e0056
namespace fn_00037080 {
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 6/6)
// FUN_00037080 @ 0x00037080
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

struct Vec4_37080 { float x, y, z, w; };
struct Scale_37080 { char pad[0x34]; float value; };
struct Planner {
    char FUN_00067ce0(int a, int b, Vec4_37080 *v, void *buf, int *out);
};
struct Holder_37080 { char pad[8]; Planner *planner; };
struct World { char pad[0x20]; Holder_37080 *holder; };

class Tracker_37080 {
public:
    char pad0[0x10];
    int *f10;
    char pad14[0x11c - 0x14];
    Scale_37080 *scale;
    char pad120[0x214c - 0x120];
    int saved;
    char pad2150[0x229c - 0x2150];
    char active;
    char found;
    char pad229e[2];
    char buf[4];
    void FUN_000350c0(Vec4_37080 *v);
    char FUN_00037080(int a, char useSaved);
};

char Tracker_37080::FUN_00037080(int a, char useSaved)
{
    Planner *planner = DAT_004dd700->holder->planner;
    Vec4_37080 v;
    FUN_000350c0(&v);
    float s = scale ? scale->value : 1.0f;
    v.w = s + s;
    int cur = 0;
    if (useSaved)
        cur = saved;
    char ok = planner->FUN_00067ce0(a, *f10, &v, buf, &cur);
    found = ok;
    active = 1;
    if (ok)
        saved = cur;
    return ok;
}
} // namespace fn_00037080
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00037120 FUN_00037120 (34 B): matches/0x00037120.cpp
// sym: ?FUN_00037120@X_37120@owners@@QAEX_N@Z
void owners::X_37120::FUN_00037120(bool b) {
    if (b)
        ++value;
    else
        --value;
}


// 0x00037160 FUN_00037160 (13 B): matches/0x00037160.cpp
// sym: ?FUN_00037160@Target_37160@owners@@QAEXH@Z
void owners::Target_37160::FUN_00037160(int x) {
    value = x;
}


// 0x00037170 FUN_00037170 (13 B): matches/0x00037170.cpp
// sym: ?FUN_00037170@Obj_37170@owners@@QAEXH@Z
void owners::Obj_37170::FUN_00037170(int x) {
    *(int*)((char*)this + 0x22dc) = x;
}


// 0x00037180 FUN_00037180 (33 B): matches/0x00037180.cpp
// sym: ?FUN_00037180@O_37180@owners@@QAEXHHH@Z
void owners::O_37180::FUN_00037180(int a, int b, int c) {
    m1 = a;
    m2 = b;
    m3 = c;
}


// 0x000371b0 FUN_000371b0 (13 B): matches/0x000371b0.cpp
// sym: ?FUN_000371b0@Obj_371b0@owners@@QAEXH@Z
void owners::Obj_371b0::FUN_000371b0(int x) {
    value = x;
}


// 0x00037290 FUN_00037290 (85 B): equivalent/0x00037290.cpp [wrapped: conflict: Object]
// sym: ?FUN_00037290@Object@fn_00037290@@QAEMHH@Z @5e3eded9def2 @w55f5fbd997c6
namespace fn_00037290 {
// STATUS: equivalent (tools/equiv.py level 3: 2412 inputs, branch coverage 8/8)
// FUN_00037290 @ 0x00037290

struct Object {
    char pad[0x1ba8];
    struct Entry { int first; int second; float value; int unused; } entries[14];
    int count;
    float FUN_00037290(int first, int second);
};
float Object::FUN_00037290(int first, int second) {
    int n = count;
    for (int i = 0; i < n; ++i) {
        if (entries[i].first == first && entries[i].second == second)
            return entries[i].value;
    }
    return DAT_003f3388;
}
} // namespace fn_00037290

namespace fn_f9673120 {

// 0x000372f0 FUN_000372f0 (7 B): matches/0x000372f0.cpp
// sym: ?FUN_000372f0@fn_f9673120@@YIEPAX@Z
unsigned char __fastcall FUN_000372f0(void* object) {
    return *((unsigned char*)object + 0x1c8c);
}

} // namespace fn_f9673120

// 0x00037300 FUN_00037300 (13 B): matches/0x00037300.cpp
// sym: ?FUN_00037300@Obj_37300@owners@@QAEXE@Z
void owners::Obj_37300::FUN_00037300(unsigned char b) {
    value = b;
}


// 0x000373a0 FUN_000373a0 (30 B): matches/0x000373a0.cpp
// sym: ?FUN_000373a0@Obj_373a0@owners@@QAEDH@Z
char owners::Obj_373a0::FUN_000373a0(int x) {
    return strcmp((const char*)m, "hulk") == 0;
}


// 0x000373c0 FUN_000373c0 (13 B): matches/0x000373c0.cpp
// sym: ?FUN_000373c0@Obj_373c0@owners@@QAEXE@Z
void owners::Obj_373c0::FUN_000373c0(unsigned char v) {
    field = v;
}

namespace fn_f9673120 {

// 0x000373d0 FUN_000373d0 (7 B): matches/0x000373d0.cpp
// sym: ?FUN_000373d0@fn_f9673120@@YIEPAVTarget_373d0@1@@Z
unsigned char __fastcall FUN_000373d0(Target_373d0* self) {
    return self->value;
}

} // namespace fn_f9673120

// 0x000373e0 FUN_000373e0 (13 B): matches/0x000373e0.cpp
// sym: ?FUN_000373e0@Target_373e0@owners@@QAEXE@Z
void owners::Target_373e0::FUN_000373e0(unsigned char x) {
    value = x;
}

namespace fn_f9673120 {

// 0x00037400 FUN_00037400 (7 B): matches/0x00037400.cpp
// sym: ?target@fn_f9673120@@YIHPAVObj_37400@1@@Z
hulk_intptr __fastcall target(Obj_37400* self) {
    return self->value;
}

} // namespace fn_f9673120

// 0x00037410 FUN_00037410 (7 B): matches/0x00037410.cpp
// sym: ?FUN_00037410@Target_37410@owners@@QAEEXZ
unsigned char owners::Target_37410::FUN_00037410() {
    return *(unsigned char*)((char*)this + 0x22fc);
}


// 0x00037420 FUN_00037420 (13 B): matches/0x00037420.cpp
// sym: ?FUN_00037420@Target_37420@owners@@QAEXE@Z
void owners::Target_37420::FUN_00037420(unsigned char x) {
    value = x;
}

namespace fn_f9673120 {

// 0x00037510 FUN_00037510 (36 B): matches/0x00037510.cpp
// sym: ?Set@fn_f9673120@@YAXPAPAVObj_37510@1@PAV21@@Z
// Same code shape as 0x000187a0 (propagated; names are from that function)
void Set(Obj_37510** p, Obj_37510* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}


// 0x000375a0 FUN_000375a0 (78 B): matches/0x000375a0.cpp
// sym: @FUN_000375a0@4
// data: gEpsilon = DAT_003f5b94
extern "C" bool __fastcall FUN_000375a0(V3_375a0* p) {
    union U {
        float f;
        unsigned int i;
    } u;
    u.f = p->x * p->x + p->y * p->y + p->z * p->z - DAT_003f32dc;  // the listing's order (MSVC 7.1 reassociates; clang does not)
    u.i &= 0x7fffffff;
    return u.f <= DAT_003f5b94;
}

} // namespace fn_f9673120

// 0x000375f0 FUN_000375f0 (139 B): matches/0x000375f0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Test@Box_375f0@fn_000375f0@@QAEHPAU12@M@Z
namespace fn_000375f0 {
extern "C" char __cdecl FUN_00018960(float, float, float);
struct Box_375f0 {
    float x, y, z, w;
    int Test(Box_375f0*, float);
};
static float absbits(float v) {
    union U {
        float f;
        unsigned long i;
    } u;
    u.f = v;
    u.i &= 0x7fffffffUL;
    return u.f;
}
int Box_375f0::Test(Box_375f0* other, float tolerance) {
    if (!(absbits(x - other->x) <= tolerance)) {
    } else if (!(absbits(y - other->y) <= tolerance)) {
    } else if (!(absbits(z - other->z) <= tolerance)) {
    } else {
        if (FUN_00018960(w, other->w, tolerance))
            return 1;
    }
    return 0;
}
} // namespace fn_000375f0

namespace fn_f9673120 {

// 0x00037680 FUN_00037680 (51 B): matches/0x00037680.cpp
// sym: ??0Plane@fn_f9673120@@QAE@PBUVec@1@0@Z
Plane::Plane(const Vec* a, const Vec* b) {
    x = a->x;
    y = a->y;
    z = a->z;
    d = -(b->z * z + b->y * y + b->x * x);
}


// 0x00037710 FUN_00037710 (47 B): matches/0x00037710.cpp
// sym: ?target@fn_f9673120@@YIPAVObj_37710@1@PAV21@@Z
// data: zero_37710 = DAT_003f335c
Obj_37710* __fastcall target(Obj_37710* self) {
    self->init_0027af00();
    self->value = (int)0xbf800000;
    ((owners::Target_27b040 *)self)->FUN_0027b040((hulk_uintptr)(&DAT_003f335c));
    self->pad[8] = (char)0xff;
    self->pad[9] = (char)0xff;
    self->a = 0;
    self->b = 0;
    return self;
}


// 0x00037750 FUN_00037750 (41 B): matches/0x00037750.cpp
// sym: ?Clear@Holder_37750@fn_f9673120@@QAEXXZ
void Holder_37750::Clear() {
    if (b) {
        b->f1();
        b = 0;
    }
    if (a) {
        a->f1();
        a = 0;
    }
}


// 0x00037780 FUN_00037780 (121 B): matches/0x00037780.cpp
// sym: ?Set@Obj_37780@fn_f9673120@@QAEXPAVRef_37780@2@0HPAUV3_37780@2@1H@Z
void Obj_37780::Set(Ref_37780* na, Ref_37780* nb, int nx, V3_37780* np, V3_37780* nq, int nz) {
    a.Set(na);
    b.Set(nb);
    x = nx;
    p.Set(np);
    q.Set(nq);
    z = nz;
}


// 0x00037800 FUN_00037800 (41 B): matches/0x00037800.cpp
// sym: ?Clear@Holder_37800@fn_f9673120@@QAEXXZ
// Same code shape as 0x00037750 (propagated; names are from that function)
void Holder_37800::Clear() {
    if (b) {
        b->f1();
        b = 0;
    }
    if (a) {
        a->f1();
        a = 0;
    }
}

} // namespace fn_f9673120

// 0x00037860 FUN_00037860 (2608 B): equivalent/0x00037860.cpp [wrapped: conflict: Matrix; World]
// sym: ??0CCharacter@fn_00037860@@QAE@H@Z @2fb993887d04 @w1b538c90b046
namespace fn_00037860 {
// STATUS: equivalent (tools/equiv.py level 3: 11024 inputs, branch coverage 26/26)
// FUN_00037860 @ 0x00037860
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

struct Name_37860 {
    int lo;
    int hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *s);
};
struct Matrix {
    float m[16];
    void FUN_0022b980();
};
struct Obj222050 {
    char pad[0x54];
    void FUN_00222050();
};
struct Obj231e50 {
    char pad[0x28];
    void FUN_00231e50();
};
struct Slot50 {
    int a;
    int b;
    int c;
    int d;
    Matrix m;
};
struct Ent28 {
    int a[10];
};
struct NameSlot_37860 {
    Name_37860 n;
    int c;
    int pad;
};
struct NameSlotF {
    Name_37860 n;
    float b;
    int pad;
};
struct NameSlot2 {
    Name_37860 n;
    char b8;
    char b9;
    char pad[6];
};
struct Item38 {
    char pad[0x30];
    int f30;
    char f34;
    char pad35[3];
};
struct Obj1f58 {
    char pad[0x150];
    int FUN_000601f0();
};
class Obj59260 {
public:
    virtual void AddRef();
    char pad[0x10];
    Obj59260 *FUN_00059260(int a);
};
class Obj0fee10 {
public:
    virtual void AddRef();
    char pad[0x12c];
    Obj0fee10 *FUN_000fee10(void *parent);
    void FUN_000fdc00(void *o);
};
class Obj109ba0 {
public:
    virtual void AddRef();
    char pad[0x34];
    Obj109ba0 *FUN_00109ba0();
};
class Obj120 {
public:
    char pad[0x120];
    Obj120 *FUN_000fcd30(Obj0fee10 *p);
};
struct Mgr_37860 {
    int FUN_00059ba0(int a);
};
struct World {
    char pad[0x44];
    Mgr_37860 *mgr;
};
extern "C" void __cdecl FUN_000964d0();
extern "C" void *__cdecl FUN_0008d690(unsigned int size);

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0();
    char pad04[4];
    Name_37860 nameHolder;
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

class CCharacter : public pure3d::Entity {
public:
    CCharacter(hulk_intptr a);
    virtual void v1();
    virtual void v2();
    int f10;
    Obj222050 o14;
    int f0068;
    int f006c;
    int f0070;
    int f0074;
    int f0078;
    int f007c;
    int f0080;
    int f0084;
    int f0088;
    int f008c;
    int f0090;
    int f0094;
    int f0098;
    int f009c;
    int f00a0;
    int f00a4;
    int f00a8;
    int f00ac;
    int f00b0;
    Obj231e50 ob4;
    Obj231e50 odc;
    Obj59260* f104;
    int f0108;
    int f010c;
    int f0110;
    int f0114;
    char f0118;
    char f0119;
    char pad011a[0x2];
    int f011c;
    int f0120;
    int f0124;
    int f0128;
    int f012c;
    int f0130;
    int f0134;
    int f0138;
    int f013c;
    int f0140;
    int f0144;
    float f0148;
    int f014c;
    Matrix m150;
    int f0190;
    int f0194;
    int f0198;
    int f019c;
    int f01a0;
    int f01a4;
    int f01a8;
    int f01ac;
    int f01b0;
    int f01b4;
    int f01b8;
    int f01bc;
    int f01c0;
    int f01c4;
    int f01c8;
    int f01cc;
    int f01d0;
    int f01d4;
    int f01d8;
    int f01dc;
    int f01e0;
    int f01e4;
    int f01e8;
    int f01ec;
    int f01f0;
    int f01f4;
    int f01f8;
    int f01fc;
    char pad0200[0x100];
    int f0300;
    int f0304;
    int f0308;
    int f030c;
    int f0310;
    float f0314;
    int f0318;
    int f031c;
    int f0320;
    int f0324;
    int f0328;
    char f032c;
    char f032d;
    char f032e;
    char pad032f[0x1];
    int f0330;
    int f0334;
    int f0338;
    int f033c;
    int f0340;
    int f0344;
    Matrix m348;
    int f0388;
    int f038c;
    int f0390;
    int f0394;
    char f0398;
    char pad0399[0x3];
    int f039c;
    float f03a0;
    int f03a4;
    Slot50 slots[8];
    int f0628;
    int f062c;
    int f0630;
    int f0634;
    Ent28 ents[128];
    char f1a38;
    char f1a39;
    char pad1a3a[0x2];
    int f1a3c;
    int f1a40;
    int f1a44;
    int f1a48;
    int f1a4c;
    int f1a50;
    int f1a54;
    int f1a58;
    int f1a5c;
    int f1a60;
    int f1a64;
    int f1a68;
    int f1a6c;
    float f1a70;
    int f1a74;
    int f1a78;
    float f1a7c;
    int f1a80;
    int f1a84;
    int f1a88;
    int f1a8c;
    int f1a90;
    int f1a94;
    int f1a98;
    int f1a9c;
    int f1aa0;
    int f1aa4;
    int f1aa8;
    int f1aac;
    int f1ab0;
    int f1ab4;
    int f1ab8;
    int f1abc;
    int f1ac0;
    int f1ac4;
    int f1ac8;
    int f1acc;
    int f1ad0;
    int f1ad4;
    int f1ad8;
    int f1adc;
    int f1ae0;
    int f1ae4;
    int f1ae8;
    int f1aec;
    int f1af0;
    int f1af4;
    int f1af8;
    int f1afc;
    int f1b00;
    int f1b04;
    char f1b08;
    char pad1b09[0x3];
    float f1b0c;
    char pad1b10[0x4];
    float f1b14;
    int f1b18;
    int f1b1c;
    int f1b20;
    int f1b24;
    int f1b28;
    int f1b2c;
    int f1b30;
    char f1b34;
    char pad1b35[0x3];
    int f1b38;
    char pad1b3c[0x4];
    int f1b40;
    int f1b44;
    char f1b48;
    char f1b49;
    char pad1b4a[0x6];
    Name_37860 n1b50;
    int f1b58;
    int f1b5c;
    int f1b60;
    int f1b64;
    int f1b68;
    int f1b6c;
    int f1b70;
    char f1b74;
    char pad1b75[0x3];
    int f1b78;
    int f1b7c;
    int f1b80;
    char f1b84;
    char pad1b85[0x3];
    int f1b88;
    int f1b8c;
    char f1b90;
    char f1b91;
    char pad1b92[0x6];
    Name_37860 n1b98;
    int f1ba0;
    char f1ba4;
    char pad1ba5[0x3];
    NameSlotF ns1ba8[14];
    int f1c88;
    char f1c8c;
    char f1c8d;
    char pad1c8e[0x2];
    int f1c90;
    char pad1c94[0x4];
    Name_37860 n1c98;
    Obj0fee10* f1ca0;
    Obj109ba0* f1ca4;
    float f1ca8;
    float f1cac;
    float f1cb0;
    float f1cb4;
    float f1cb8;
    int f1cbc;
    int f1cc0;
    int f1cc4;
    int f1cc8;
    int f1ccc;
    int f1cd0;
    int f1cd4;
    int f1cd8;
    int f1cdc;
    float f1ce0;
    float f1ce4;
    float f1ce8;
    char f1cec;
    char f1ced;
    char f1cee;
    char f1cef;
    float f1cf0;
    char f1cf4;
    char f1cf5;
    char pad1cf6[0x2];
    float f1cf8;
    int f1cfc;
    float f1d00;
    char f1d04;
    char f1d05;
    char pad1d06[0x2];
    int f1d08;
    float f1d0c;
    float f1d10;
    int f1d14;
    int f1d18;
    int f1d1c;
    float f1d20;
    float f1d24;
    char f1d28;
    char pad1d29[0x3];
    int f1d2c;
    float f1d30;
    float f1d34;
    float f1d38;
    int f1d3c;
    char f1d40;
    char pad1d41[0x3];
    int f1d44;
    float f1d48;
    char f1d4c;
    char f1d4d;
    char pad1d4e[0x2];
    int f1d50;
    int f1d54;
    int f1d58;
    int f1d5c;
    char pad1d60[0x8];
    Name_37860 n1d68;
    Name_37860 n1d70;
    char f1d78;
    char f1d79;
    char pad1d7a[0x2];
    int f1d7c;
    int f1d80;
    int z1d84[32];
    int z1e04[16];
    int f1e44;
    int f1e48;
    int f1e4c;
    int f1e50;
    int f1e54;
    int f1e58;
    int f1e5c;
    float f1e60[14];
    char b1e98[14];
    char pad1ea6[0x2];
    Item38 it1ea8[3];
    char f1f50;
    char f1f51;
    char pad1f52[0x2];
    int f1f54;
    Obj1f58 o1f58;
    int f20a8;
    int f20ac;
    int f20b0;
    int f20b4;
    char f20b8;
    char pad20b9[0x3f];
    char f20f8;
    char pad20f9[0x3f];
    char f2138;
    char pad2139[0x3];
    int f213c;
    char f2140;
    char pad2141[0x3];
    int f2144;
    char f2148;
    char f2149;
    char pad214a[0x2];
    int f214c;
    NameSlot_37860 ns2150[16];
    int f2250;
    char pad2254[0x4];
    NameSlot2 ns2258[4];
    int f2298;
    char f229c;
    char f229d;
    char pad229e[0x2];
    int f22a0;
    int f22a4;
    int f22a8;
    int f22ac;
    char f22b0;
    char pad22b1[0x3];
    int f22b4;
    Name_37860 n22b8;
    char f22c0;
    char f22c1;
    char pad22c2[0x12];
    float f22d4;
    int f22d8;
    int f22dc;
    char f22e0;
    char pad22e1[0x3];
    int f22e4;
    char f22e8;
    char f22e9;
    char pad22ea[0x2];
    int f22ec;
    int f22f0;
    int f22f4;
    float f22f8;
    char f22fc;
};

CCharacter::CCharacter(hulk_intptr a)
{
    int i;
    f10 = 0;
    o14.FUN_00222050();
    f0068 = 0;
    f006c = 0;
    f0070 = 0;
    f0074 = 0;
    f0078 = 0;
    f007c = 0;
    f0080 = 0;
    f0084 = 0;
    f0088 = 0;
    f008c = 0;
    f0090 = 0;
    f0094 = 0;
    f0098 = 0;
    f009c = 0;
    f00a0 = 0;
    f00a4 = 0;
    f00a8 = 0;
    f00ac = 0;
    f00b0 = 0;
    ob4.FUN_00231e50();
    odc.FUN_00231e50();
    f104 = 0;
    f0108 = 0;
    f010c = 0;
    f0110 = 0;
    f0114 = 0;
    f0118 = 0;
    f0119 = 0;
    f011c = 0;
    f0120 = 0;
    f0124 = 0;
    f0128 = 0;
    f012c = 0;
    f0130 = 0;
    f0134 = 0;
    f0138 = 0;
    f013c = 0;
    f014c = 0;
    f0140 = 1;
    f0144 = 1;
    f0148 = 1.0f;
    f0190 = 0;
    f0194 = 0;
    f0198 = 0;
    f019c = 0;
    f01a0 = 0;
    f01a4 = 0;
    f01a8 = 0;
    f01ac = 0;
    f01b0 = 0;
    f01b4 = 0;
    f01b8 = 0;
    f01bc = 0;
    f01c0 = 0;
    f01c4 = 0;
    f01c8 = 0;
    f01cc = 0;
    f01d0 = 0;
    f01d4 = 0;
    f01d8 = 0;
    f01dc = 0;
    f01e0 = 0;
    f01e4 = 0;
    f01e8 = 0;
    f01ec = 0;
    f01f0 = 0;
    f032e = 1;
    f0394 = 1;
    f01f4 = 0;
    f01f8 = 0;
    f01fc = 0;
    f0308 = 0;
    f030c = 0;
    f0310 = 0;
    f0314 = 1.0f;
    f0318 = 0;
    f031c = 0;
    f0320 = 0;
    f0324 = 0;
    f0328 = 0;
    f032c = 0;
    f032d = 0;
    f0330 = 0;
    f0334 = 0;
    f0338 = 0;
    f033c = 0xffff;
    f0340 = 0;
    f0344 = 0;
    f0388 = 0;
    f038c = 0;
    f0390 = 0;
    f0398 = 0;
    f039c = 0;
    f03a0 = 2.0f;
    f03a4 = 0;
    f0628 = 0;
    f062c = 0;
    f0630 = 0;
    f0634 = 0;
    for (i = 0; i < 128; i++) {
        int j;
        for (j = 0; j < 10; j++) ents[i].a[j] = 0;
        ents[i].a[2] = -1;
    }
    f1a38 = 1;
    f1a39 = 1;
    f1a3c = 0;
    f1a40 = 0;
    f1a44 = 0;
    f1a48 = 0;
    f1a4c = 0;
    f1a50 = 0;
    f1a54 = 0;
    f1a58 = 0;
    f1a5c = 0;
    f1a60 = 0;
    f1a64 = 0;
    f1a68 = 0;
    f1a6c = 0;
    f1a70 = 1.0f;
    f1a74 = 0;
    f1a78 = 0;
    f1a7c = 1.0f;
    f1a80 = 0;
    f1a84 = 0;
    f1a88 = 0;
    f1a8c = 0;
    f1ab8 = 0;
    f1abc = 0;
    f1ac0 = 0;
    f1ac4 = 0;
    f1ac8 = 0;
    f1acc = 0;
    f1ad0 = 0;
    f1ad4 = 0;
    f1ad8 = 0;
    f1adc = 0;
    f1ae0 = 0;
    f1ae4 = 0;
    f1ae8 = 0;
    f1aec = 0;
    f1af0 = 0;
    f1af4 = 0;
    f1af8 = 0;
    f1afc = 0;
    f1b00 = 0;
    f1b04 = 0;
    f1b08 = 0;
    f1b0c = -1.0f;
    f1b14 = -1.0f;
    f1b18 = 0;
    f1b1c = 0;
    f1b20 = 0;
    f1b24 = 0;
    f1b28 = 0;
    f1b2c = 0;
    f1b30 = 0;
    f1b34 = 1;
    f1b38 = 0;
    f1b40 = 0;
    f1b44 = 0;
    f1b48 = 0;
    f1b49 = 0;
    n1b50.FUN_0027af00();
    f1b58 = 0;
    f1b5c = 0;
    f1b60 = 0;
    f1b64 = 0;
    f1b68 = 0;
    f1b6c = 0;
    f1b70 = 0;
    f1b74 = 0;
    f1b78 = 0;
    f1b7c = 0;
    f1b80 = 0;
    f1b84 = 0;
    f1b88 = 0;
    f1b8c = 0;
    f1b90 = 0;
    f1b91 = 1;
    n1b98.FUN_0027af00();
    f1ba0 = 0;
    f1ba4 = 1;
    for (i = 0; i < 14; i++) ns1ba8[i].n.FUN_0027af00();
    f1c8d = 0;
    f1c90 = 0;
    n1c98.FUN_0027af00();
    f1ca0 = 0;
    f1ca4 = 0;
    f1ca8 = -1.0f;
    f1cac = -1.0f;
    f1cb0 = -1.0f;
    f1cb4 = -1.0f;
    f1cb8 = -1.0f;
    f1cbc = 0;
    f1cc0 = 0;
    f1cc4 = 0;
    f1cc8 = 0;
    f1ccc = 0;
    f1cd0 = 0;
    f1cd4 = 0;
    f1cd8 = 0;
    f1cdc = 0;
    f1ce0 = 1.0f;
    f1ce4 = 4.0f;
    f1ce8 = 8.0f;
    f1cec = 1;
    f1ced = 0;
    f1cee = 0;
    f1cef = 1;
    f1cf0 = 1.0f;
    f1cf4 = 0;
    f1cf5 = 0;
    f1cf8 = 15.0f;
    f1cfc = 0;
    f1d00 = 25.0f;
    f1d04 = 0;
    f1d05 = 0;
    f1d08 = 0;
    f1d0c = -1.0f;
    f1d10 = -1.0f;
    f1d14 = 0;
    f1d18 = 0;
    f1d1c = 0;
    f1d20 = 1.0f;
    f1d24 = 1.0f;
    f1d28 = 0;
    f1d2c = 1;
    f1d30 = -1.0f;
    f1d34 = -1.0f;
    f1d38 = -1.0f;
    f1d3c = 0;
    f1d40 = 0;
    f1d44 = 0;
    f1d48 = 20.0f;
    f1d4c = 0;
    f1d4d = 0;
    f1d50 = 0;
    f1d54 = 0;
    f1d58 = 0;
    f1d5c = 0;
    n1d68.FUN_0027af00();
    n1d70.FUN_0027af00();
    f1d78 = 0;
    f1d79 = 0;
    f1d7c = 0x7fffffff;
    f1d80 = 0x7fffffff;
    f1e44 = 0;
    f1e48 = 0;
    f1e4c = 0;
    f1e50 = 0;
    f1e54 = 0;
    f1e58 = 0;
    f1e5c = 0;
    for (i = 0; i < 3; i++) { it1ea8[i].f30 = 0; it1ea8[i].f34 = 0; }
    f1f50 = 0;
    f1f51 = 0;
    f1f54 = 0xffff;
    o1f58.FUN_000601f0();
    f20a8 = -1;
    f20ac = -1;
    f20b0 = 0;
    f20b4 = 0;
    f2138 = 0;
    f213c = 0;
    f2140 = 0;
    f2144 = 0;
    f2148 = 0;
    f2149 = 0;
    f214c = 0;
    for (i = 0; i < 16; i++) ns2150[i].n.FUN_0027af00();
    for (i = 0; i < 4; i++) ns2258[i].n.FUN_0027af00();
    f229c = 0;
    f229d = 0;
    f22a0 = 0;
    f22a4 = 0;
    f22a8 = 0;
    f22ac = 0;
    f22b0 = 0;
    f22b4 = 0;
    n22b8.FUN_0027af00();
    f22d4 = -1.0f;
    n22b8.FUN_0027b040("");
    f22c0 = -1;
    f22c1 = -1;
    f22d8 = 0;
    f22dc = 0;
    f22e0 = 1;
    f22e4 = 0;
    f22e8 = 0;
    f22e9 = 1;
    f22ec = 0;
    f22f0 = 0;
    f22f4 = 0;
    f22f8 = 10000.0f;
    f22fc = 0;
    f10 = DAT_004dd700->mgr->FUN_00059ba0(a);
    f20b8 = 0;
    f20f8 = 0;
    FUN_000964d0();
    {
        void* mem = FUN_0008d690((int)sizeof(Obj59260));
        Obj59260* p = 0;
        if (mem) p = ((Obj59260*)mem)->FUN_00059260(a);
        f104 = p;
        p->AddRef();
        mem = FUN_0008d690((int)sizeof(Obj0fee10));
        Obj0fee10* q = 0;
        if (mem) q = ((Obj0fee10*)mem)->FUN_000fee10(this);
        f1ca0 = q;
        q->AddRef();
        mem = FUN_0008d690((int)sizeof(Obj109ba0));
        Obj109ba0* r = 0;
        if (mem) r = ((Obj109ba0*)mem)->FUN_00109ba0();
        f1ca4 = r;
        r->AddRef();
        mem = FUN_0008d690((int)sizeof(Obj120));
        Obj120* s = 0;
        if (mem) s = ((Obj120*)mem)->FUN_000fcd30(f1ca0);
        f1ca0->FUN_000fdc00(s);
    }
    n1d68.FUN_0027b040(0);
    m150.FUN_0022b980();
    m348.FUN_0022b980();
    for (i = 0; i < 8; i++) {
        slots[i].a = 0;
        slots[i].b = 0xffff;
        slots[i].c = 0;
        slots[i].d = 0;
        slots[i].m.FUN_0022b980();
    }
    for (i = 0; i < 32; i++) z1d84[i] = 0;
    for (i = 0; i < 16; i++) z1e04[i] = 0;
    f1a98 = 0;
    f1a94 = 0;
    f1a90 = 0;
    f1ab0 = 0;
    f1aa4 = 0;
    f1aa0 = 0;
    f1a9c = 0;
    f1ab4 = 0;
    f1aa8 = 0;
    f1aac = 0;
    f0300 = 0;
    f0304 = 0;
    for (i = 0; i < 14; i++) {
        f1e60[i] = 1000.0f;
        b1e98[i] = 0;
    }
    for (i = 0; i < 16; i++) ns2150[i].c = 0;
    f2250 = 0;
    for (i = 0; i < 4; i++) {
        ns2258[i].b8 = 0;
        ns2258[i].b9 = 1;
    }
    f2298 = 0;
    n1b98.FUN_0027b040("NULL");
    for (i = 0; i < 14; i++) ns1ba8[i].b = -1.0f;
    f1c88 = 0;
    f1c8c = 0;
}
} // namespace fn_00037860
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

