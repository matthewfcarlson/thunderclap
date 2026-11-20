// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001fc690..0x00201740 (kind game, layer game, confidence high), dominant class CTriggerVolumeManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#include "game/script_bind.h"
#define TREE_TU_BEGIN namespace fn_f3d6a774 {
#define TREE_TU_END }
namespace fn_f3d6a774 {} using namespace fn_f3d6a774;
#include "game/global.h"
#include "game/script_bind.h"

// ---- declarations shared by the functions below
namespace fn_f3d6a774 {
class Unit_1fc6a0 {
public:
    void FUN_00036be0(class Handler_1fc6a0 *best);
};
class Handler_1fc6a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual char vf12(Unit_1fc6a0 *unit);
    char pad0[0xcd - 4];
    char active;
    char enabled;
};
class Slot_1fc6a0 {
public:
    void FUN_001fa7d0(Unit_1fc6a0 *unit, int arg);
    char data[0xc70];
};
class UnitList {
public:
    Unit_1fc6a0 *FUN_00024190(int index);
    char pad0[0xc];
    int count;
    char pad1[0x124 - 0x10];
    Unit_1fc6a0 *current;
};
} // namespace fn_f3d6a774
class World {
public:
    char pad0[0x20];
    UnitList *units;
};
namespace fn_f3d6a774 {
class Dispatcher_1fc6a0 {
public:
    void FUN_001fc6a0(hulk_intptr arg);

    char pad0[4];
    World *world;
    int handlerCount;
    Handler_1fc6a0 *handlers[(0x234 - 0xc) / 4];
    char *slots;
};
class Item_1fc790 {
  public:
};
class Thing_1fc790 {
  public:
    char pad[8];
    int count;
    Item_1fc790* items[1];
    void ClearAll();
};
class Item_1fc7c0 {
  public:
    void Clear_001fb950();
};
class Thing_1fc7c0 {
  public:
    char pad[8];
    int count;
    Item_1fc7c0* items[1];
    void ClearAll();
};
struct Entry {
  public:
    char _m_pad_0[0x8];
    unsigned __int64 key;
    char _m_pad_10[0x448];
    int active;
    char _m_pad_45c[0x814];
    void FUN_001fa500(int mode);
};
struct CTriggerVolumeManager_1fc7f0 {
    char pad[12];
    Entry* slots[128];
    Entry* FUN_001fc7f0(unsigned value);
};
unsigned __int64 __cdecl FUN_00096d80(unsigned value);
class Entry_1fc890 {
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
    virtual void f9(void*, void*, int);
};
class Owner_1fc890 {
  public:
    char pad[12];
    Entry_1fc890* entries[128];
    void run(void*, void*);
};
struct Entry_1fc8c0 {
    char pad[8];
    unsigned int key1;
    unsigned int key2;
    char rest[48];
};
struct Bucket_1fc8c0 { int count; Entry_1fc8c0 *entries; };
struct CTriggerVolumeManager_1fc8c0 {
    char pad[0x20c];
    int count;
    Entry_1fc8c0 *entries;
    Bucket_1fc8c0 *groups[6];
    Entry_1fc8c0 *FUN_001fc8c0(unsigned int key1, unsigned int key2);
};
class Item {
  public:
    char _m_pad_0[0x8];
    hulk_intptr a;
    int b;
    char _m_pad_10[0x30];
    Item* Get_001fba60();
    void SetAngle_001fb9b0(float);
    void Send_001d6ec0(int, int, int);
    bool Set_001f9460(int, int, int);
};
class Obj {
    char pad[0x20c];
    int count;
    Item* items;

  public:
    Item* Find(int index);
};
struct CTriggerVolumeManager_nv_1fc9d0 {
    int FUN_001fc7f0(int);
};
struct Result { int x, y, z; };
struct Object_1fc9f0 { char pad[0xb0]; Result value; };
struct CTriggerVolumeManager_nv_1fc9f0 {
    Object_1fc9f0* FUN_001fc7f0(int id);
};
struct Vec3 { unsigned int x, y, z; };
struct Object_1fca40 { char padding[0xbc]; Vec3 position; };
struct CTriggerVolumeManager_nv_1fca40 {
    Object_1fca40* FUN_001fc7f0(unsigned int id);
};
struct Info {
    char pad[0xc8];
    float value;
};
struct CTriggerVolumeManager_nv_1fca90 {
    Info* GetInfo_001fc7f0(int);
};
struct Vec3_1fcab0 {
    float x, y, z;
};
struct Actor_1fcab0 {
    char pad0[0xb0];
    Vec3_1fcab0 a;
    Vec3_1fcab0 b;
    void FUN_001fbb80(Vec3_1fcab0 *a, Vec3_1fcab0 *b, float angle);
};
struct CTriggerVolumeManager_nv_1fcab0 {
    Actor_1fcab0 * FUN_001fc7f0(int id);
};
struct Vec3_1fcb30 {
    float x, y, z;
};
struct CTriggerVolumeManager_nv_1fcb30 {
    void Set_001fbb80(Vec3_1fcb30*, Vec3_1fcb30*, float);
};
struct ThisWrap_001fcb30 {
    CTriggerVolumeManager* Find_001fc7f0(int);
    bool Target(int id, Vec3_1fcb30 a, Vec3_1fcb30 d, float angle);
};
struct R {
    char pad[0xcd];
    char f;
};
struct CTriggerVolumeManager_nv_1fcb70 {
    hulk_intptr FUN_001fc7f0(unsigned int);
};
struct CTriggerVolumeManager_1fcb90 {
    char pad[0xcd];
    unsigned char a;
    unsigned char b;
};
struct CTriggerVolumeManager_nv_1fcb90 {
    CTriggerVolumeManager_1fcb90* Find_001fc7f0(int);
};
struct X_1fcbc0 {
    char pad[0xce];
    char m;
};
struct CTriggerVolumeManager_nv_1fcbc0 {
    X_1fcbc0* FUN_001fc7f0(void* p);
};
class CTriggerVolumeManager_1fcbe0 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual char V11();
};
struct CTriggerVolumeManager_nv_1fcbe0 {
    CTriggerVolumeManager_1fcbe0* FUN_001fc7f0(int);
};
class CTriggerVolumeManager_1fcc00 {
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
    virtual char act(__int64);
    char pad[0xc9];
    char enabled;
};
struct CTriggerVolumeManager_nv_1fcc00 {
    CTriggerVolumeManager_1fcc00* lookup_001fc7f0(int);
};
extern "C" __int64 __cdecl convert(int);
struct Obj_1fcc40 {
    char pad[0xcd];
    char flag;
};
struct CTriggerVolumeManager_nv_1fcc40 {
    Obj_1fcc40* Helper_001fc7f0(void*);
};
struct CTriggerVolumeManager_1fcc60 {
    char pad[0xcd];
    unsigned char flag;
};
struct CTriggerVolumeManager_nv_1fcc60 {
    CTriggerVolumeManager_1fcc60* findObj_001fc7f0(int);
};
class Item;
class Helper {
  public:
    void Apply_001e7290(Item*, int);
};
class Mid {
    char pad[12];

  public:
    Helper* helper;
};
struct CTriggerVolumeManager_nv_1fcc80 {
    Item* Find_001fc7f0(int);
};
extern char hulk_at_004e58e8[];
extern "C" void __cdecl FUN_00096d50(char*, int, int, int);
class CTriggerVolumeManager_1fccb0 {
    char pad[0x238];
    int count;
    Item* items[1];

  public:
    char* get(int index);
};
struct Vector {
    unsigned int x, y, z;
};
struct Filter_1fccf0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual bool test(Vector v);
};
struct Item_1fccf0 {
    char pad[0x114];
    int excluded;
    bool FUN_001d7300();
    Vector* FUN_001d6b40();
};
struct Collection_1fccf0 {
    int FUN_001dcf50();
};
struct Owner_1fccf0 {
    char pad[12];
    Collection_1fccf0* collection;
};
struct CTriggerVolumeManager_1fccf0 {
    char pad0[4];
    Owner_1fccf0* owner;
    char pad1[0x230];
    int count;
    Item_1fccf0* results[1];
    Filter_1fccf0* FUN_001fc7f0(unsigned int arg);
    void FUN_001fccf0(unsigned int arg, unsigned char active);
};
class Target_1fcdb0 {
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
    virtual bool Accepts(int a, int b);
};
struct Entity {
    char pad0[8];
    int fieldA;         // 8
    int fieldB;         // 0xc
    void FUN_00043350(int a, int b, int c, float d, int e, int f);
};
struct EntityList_1fcdb0 {
    char pad0[0xc];
    int count;          // 0xc
    Entity *FUN_00024190(int index);
    bool FUN_000242d0(Entity *e);
};
struct Holder_1fcdb0 {
    char pad0[0x20];
    EntityList_1fcdb0 *list;   // 0x20
};
unsigned __int64 __cdecl FUN_00096d80(int key);
class Spawner_1fcdb0 {
public:
    char pad0[4];
    Holder_1fcdb0 *holder;     // 4
    Target_1fcdb0 *FUN_001fc850(unsigned __int64 id);
    void FUN_001fcdb0(int key, int arg);
};
struct Trip {
    int a, b, c;
};
class CTriggerVolumeManager_1fce50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual unsigned char run(Trip t);
    char pad[0xc9];
    unsigned char flag;
};
struct CTriggerVolumeManager_nv_1fce50 {
    CTriggerVolumeManager_1fce50* Find_001fc7f0(int);
    unsigned char FUN_001fce50(Trip a, int id, unsigned char enabled);
};
class Input_1fcea0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int get(void*);
    virtual float value();
    int process_001fba60();
};
struct Record_1fcea0 {
    char data[0x40];
    void second_001fb9b0(float);
    void third_001fbfd0(int);
};
class Owner_1fcea0 {
  public:
    char pad[0x20c];
    int count;
    Record_1fcea0* records;
    bool add(Input_1fcea0*);
};
extern void __fastcall FUN_001fb970(void*);
struct Item_1fd070 { char data[0x40]; };
struct Group_1fd070 { int count; Item_1fd070* items; };
struct State_1fd070 {
 char pad[0x458]; int enabled; char tail[0xc70-0x45c];
 bool FUN_001f8740(int type);
 void FUN_001f8fe0(Item_1fd070* item);
};
struct Owner_1fd070 {
 char pad[0x214]; Group_1fd070* groups[6]; char gap[8]; State_1fd070* states;
 void target(int index);
};
class Elem_1fd130 {
  public:
    char pad[0x458];
    int mFlag;
    char pad2[0xc70 - 0x45c];
    bool Check_001f8740(void* p);
    void Do_001f8fe0(void* p);
};
class CTriggerVolumeManager_1fd130 {
  public:
    char pad[0x234];
    int mArray;
    void Target(void* p2, void* p3);
};
struct S8_1fd220 {
    int a;
    int b;
    void FUN_0027af30(char* p);
};
struct Entry_1fd220 {
    int count;
    char* data;
};
struct Slot_1fd220 {
    char pad[0x418];
    int active;
    char pad2[0xc70 - 0x41c];
    void FUN_001f8670(S8_1fd220 s);
};
class Obj_1fd220 {
public:
    void run(int id);
    char p0[0x214];
    Entry_1fd220* lists[6];
    int* ids;
    int pad230;
    char* slots;
};
struct Vec3_1fd640 { float x,y,z; };
extern "C" void __cdecl FUN_0022d3a0(void*, Vec3_1fd640*, Vec3_1fd640*, float, float*);
class Item_1fd730 {
  public:
    virtual void A();
    virtual void Release();
};
class Part_1fd730 {
  public:
    void Run_001fa040();
};
class Obj_1fd730 {
  public:
    char p0[8];
    int f8;
    Item_1fd730* items[128];
    int f20c;
    char p210[0x24];
    Part_1fd730* parts;
    void Clear();
};
typedef unsigned int U_1fd780;
typedef unsigned __int64 U64_1fd780;
} // namespace fn_f3d6a774
extern U64_1fd780 __cdecl FUN_0027b020(U_1fd780);
namespace fn_f3d6a774 {
struct CTriggerVolumeManager_1fd780 {
    int Second_001fc8c0(U64_1fd780);
    hulk_intptr Target(U_1fd780);
};
class Result_1fd830 {
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
    virtual float Get();
};
struct CTriggerVolumeManager_nv_1fd830 {
    Result_1fd830* Find_001fc8c0(unsigned long long key);
};
} // namespace fn_f3d6a774
extern unsigned long long FUN_0027b020(unsigned int);
namespace fn_f3d6a774 {
struct Data {
    int a, b, c;
};
U64 __cdecl Convert_0027b020(int);
class CTriggerVolumeManager_1fd870 {
  public:
    Item* Find_001fc8c0(U64);
    bool Do(int, Data);
};
struct CTriggerVolumeManager_nv_1fd8b0 {
    Item* Find_001fc8c0(int, int);
};
struct Pair {
    int a, b;
};
Pair __cdecl Lookup_0027b020(int);
struct CTriggerVolumeManager_nv_1fd8f0 {
    void* Find_001fc8c0(__int64);
};
extern __int64 __cdecl Convert_0027b020(void*);
class Other {
  public:
    unsigned char Valid_001fba00();
};
class CTriggerVolumeManager_1fd920 {
    char pad[0x238];

  public:
    int count;
    Item* items[1];
    void Setup_001fccf0(int, int);
    void Run(int a, int b, int c);
};
struct CTriggerVolumeManager_nv_1fd980 {
    void Helper_001fccf0(int a, int b);
};
struct Game { char pad[0x234]; Entry *entries; bool FUN_001fdeb0(int id, bool flag); int FUN_001fcff0(int id); };
class CTriggerVolumeManager_1fdf10 {
  public:
    char pad[0x234];
    char* data;
    char check(int x);
};
struct CTriggerVolumeManager_nv_1fdf10 {
    int FUN_001fcff0(int);
};
class CTriggerVolumeManager_1fdf50 {
    char pad[0x234];
    Item* items;

  public:
    int Find_001fcff0(int);
    bool Run(int id, int a, int b, int c);
};
class CTriggerVolumeManager_1fdf90 {
  public:
    char pad[0x234];
    char* data;
    int GetIndex_001fcff0(int);
    void* Lookup(int);
};
struct Id8 {
    int lo, hi;
    Id8(const Id8 &other) throw();
};
struct RawName {
    Id8 id;
    unsigned char a, b;
    char pad[6];
    RawName(const RawName &o) : id(o.id), a(o.a), b(o.b) {}
};
struct Name {
    Id8 id;
    unsigned char a, b;
    char pad[6];
    Name(const Name &other) throw();
};
struct Slot_1fe000 {
    char pad[0xc70];
    short FUN_001f9630(RawName n);
    bool FUN_001f9670(Name n, short value);
};
struct Entry_1fe000 {
    Id8 id;
    unsigned char slot;
    unsigned char b;
};
struct Pool_1fe000 {
    char pad[0x22b8];
    Entry_1fe000 entry;
};
class Mixer {
public:
    void FUN_001fe000(Pool_1fe000 *pool);

    char pad0[0x234];
    char *slots;
};
} // namespace fn_f3d6a774
namespace math {
struct Vector_1fe8f0 { float x,y,z; };
}
namespace fn_f3d6a774 {
struct CTriggerVolumeManager_1fe8f0 { math::Vector_1fe8f0* FUN_001fe8f0(math::Vector_1fe8f0*, const char*); };
struct Function_1fe8f0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };
class CActorManager_1fe9a0;
typedef float (CActorManager_1fe9a0::*Fn_1fe9a0)(const char*);
class CActorManager_1fe9a0 {
  public:
    float Get(const char* s);
};
struct Vector_1fea40 { float x,y,z; };
struct Parameters { const char *name; Vector_1fea40 position; };
struct CTriggerVolumeManager_1fea40 { bool FUN_001fea40(const char *, Vector_1fea40); };
struct Function_1fea40 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };
class CTriggerVolumeManager_1feaf0 {
  public:
    bool Fn(const char*, float);
};
class Function_1feaf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
struct Args {
  public:
    union { const char* a; const char* s; };
    union { int b; float f; };
    int c;
    bool d;
    char _m_pad_d[0x3];
};
class CTriggerVolumeManager_1feb80 {
  public:
    bool Run(const char*);
};
class Function_1feb80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
class Function_1fec00 {
  public:
    virtual void f0();
    virtual void f1();
};
class CTriggerVolumeManager_1fec80 {
  public:
    int invoke(const char*);
    typedef int (CTriggerVolumeManager_1fec80::*Method)(const char*);
    inline int Do(Method fn, const char* arg) { return (this->*fn)(arg); }
};
class Function_1fec80 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CTriggerVolumeManager_1fec80*, const char**, int*) = 0;
};
extern "C" char DAT_0048e10c[];
extern "C" char DAT_004252e4[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
class Method4_1feca0 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    Method4_1feca0* FUN_001feca0(const char*, ScriptMemberFn);
};
struct Vec_1fed30 {
    unsigned x, y, z;
};
struct Args_1fed30 {
    const char *name;
    Vec_1fed30 from;
    Vec_1fed30 to;
    unsigned radius;
};
class CTriggerVolumeManager_1fed30 {
  public:
    bool Check(const char *name, Vec_1fed30 from, Vec_1fed30 to, unsigned radius);
};
typedef bool (CTriggerVolumeManager_1fed30::*CheckFn_1fed30)(const char *, Vec_1fed30, Vec_1fed30, unsigned);
class Function_1fed30 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Dummy_1fee90 {
  public:
    void Call(void*);
};
class CFEManager_1fefc0 {
  public:
    void Call(const char*, int);
};
class Function_1fefc0 {
  public:
    virtual void f0();
    virtual void f1();
};
extern "C" char DAT_00425334[];
class Method3_1fefe0 {
  public:
    hulk_intptr vftable;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn p1c;      // 0x1c
    void Init_001d0480(const char*, int);
    Method3_1fefe0* Build(const char*, ScriptMemberFn);
};
} // namespace fn_f3d6a774
namespace math {
struct Vector_1ff060 {
    float x, y, z;
};
}
namespace fn_f3d6a774 {
class CTriggerVolumeManager_1ff060 {
  public:
    bool Execute(math::Vector_1ff060, const char*, bool);
};
typedef bool (CTriggerVolumeManager_1ff060::*Fn)(math::Vector_1ff060, const char*, bool);
class Function_1ff060 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Params_1ff060 {
    math::Vector_1ff060 v;
    const char* name;
    bool flag;
};
class Function_1ff120 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_1ff120 {
  public:
    bool (CActorManager_1ff120::*m)(const char*, bool);
};
struct Pair_1ff120 {
    const char* p;
    bool b;
};
extern "C" char DAT_00425354[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
extern "C" char __cdecl ReadBool_001d04d0(const char*);
class Method4_1ff150 : public FUN_001d0480 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn value;    // 0x1c
    Method4_1ff150(const char* x, ScriptMemberFn y);
};
struct Function_1ff1e0 {
    virtual void f0();
    virtual void f1();
};
void FUN_001ff200(const char*, const char*, const char*, int);
class CTriggerVolumeManager_1ff200 {
  public:
    typedef unsigned char (CTriggerVolumeManager_1ff200::*Fn)(int, int, int, int);
};
class CTriggerVolumeManager_1ff2a0 {
  public:
    int Invoke(const char*);
};
class Function_1ff2a0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CTriggerVolumeManager_1ff2a0*, const char**, int*);
};
extern "C" char DAT_00425374[];
struct Function_1ff2c0 {
    void Init_001d0480(const char*, int);
};
class Method3_1ff2c0 : public Function_1ff2c0 {
  public:
    Method3_1ff2c0(const char*, ScriptMemberFn);
    hulk_intptr m0;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
};
struct CTriggerVolumeManager_1ff340 {};
struct TriggerArguments {
    const char *name;
    int value;
    bool enabled;
};
extern "C" char DAT_00425384[];
class Method5_1ff360 : public FUN_001d0480 {
  public:
    void* vft;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
    Method5_1ff360(const char*, ScriptMemberFn);
};
struct Function_1ff400 {
    virtual void f0();
    virtual void f1();
};
void FUN_001ff420(const char*, const char*, const char*, int);
struct Triple { int a,b,c; };
struct Receiver { int invoke(Triple value, int x, int y, int z, int w); };
class CTriggerVolumeManager_1ff4e0 {
  public:
    void* Fn(const char*);
    inline void* Invoke(void* (CTriggerVolumeManager_1ff4e0::*fn)(const char*), const char* arg) {
        return (this->*fn)(arg);
    }
};
class Function_1ff4e0 {
  public:
    virtual void v0();
    virtual void v1();
};
class Dummy_1ff560 {
  public:
    void Call(void*);
};
struct CTriggerVolumeManager_nv_1ff950 {
    int FUN_001fba60();
};
struct Factory {
    CTriggerVolumeManager* FUN_001fe080(Triple a, int b, int c, int d, int e);
    int FUN_001ff950(Triple a, int b, int c, int d, int e);
};
extern char hulk_at_0048e10c[];
char __cdecl check_001d04d0(const char*);
class Function_1ff9a0 {
  public:
    Function_1ff9a0(const char*, int);
    virtual void f();
};
class Method1_1ff9a0 : public Function_1ff9a0 {
  public:
    inline Method1_1ff9a0(const char* n, void* ctx) : Function_1ff9a0(n, 1) {
        v = ctx;
        y = check_001d04d0(hulk_at_0048e10c);
        x = check_001d04d0(((char*)&DAT_0048e0f0));
    }
    virtual bool Fnh_001d04c0(int, int);
    char pad[0x0c];
    char x;
    char p1[7];
    char y;
    char p2[3];
    void* v;
    void* w;
};
class Closure1_1ff9a0 : public Method1_1ff9a0 {
  public:
    Closure1_1ff9a0(const char*, void*, void*);
    virtual void Fng_001ffa10(void*, void*, void*);
};
struct Vector_1ffa10 { float x,y,z; };
struct CTriggerVolumeManager_1ffa10 { char padding[28]; };
class CActorManager_1ffad0 {
  public:
    float Method(const char*);
};
typedef float (CActorManager_1ffad0::*Fn_1ffad0)(const char*);
struct Vector_1ffb80 { float x,y,z,w; };
struct CTriggerVolumeManager_1ffb80 {};
class CActorManager_1ffd60 {
  public:
    int act();
};
struct Arg_1ffef0 {
    const char* s;
    unsigned char b;
};
class Actor_1ffef0 {
  public:
    void invoke(const char*, unsigned char);
};
class CActorManager_1fff80 {
  public:
    void invoke(const char*);
};
class CTriggerVolumeManager_200020 {};
class CActorManager_2000d0 {
  public:
    void Method(const char*, float);
};
struct Pair_2000d0 {
    const char* s;
    float f;
};
struct Arguments { const char *name; bool value; };
struct CTriggerVolumeManager_200210 { bool invoke(const char *, bool); };
class CTriggerVolumeManager_200290 {
  public:
    bool Fire(const char*, int, int, bool);
};
class Function_2002d0 : public ScriptFunctionFields {
  public:
    Function_2002d0(const char*, int);
    virtual void f0();
};
class Method1_2002d0 : public Function_2002d0 {
  public:
    ScriptMemberFn v1c;  // 0x1c
    Method1_2002d0(const char* a, ScriptMemberFn b) : Function_2002d0(a, 1) {
        v1c = b;
        retType = FUN_001d04d0(((char*)&DAT_0048e134));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    }
    virtual bool f1_001d04c0(int, int);
};
class Closure1_2002d0 : public Method1_2002d0 {
  public:
    void* v20;  // 0x20
    Closure1_2002d0(const char* a, void* b, ScriptMemberFn c);
    virtual void f2_00200340(void*, void*, void*);
};
class CTriggerVolumeManager_200340 { public: int FUN_00200340(const char *); };
class Function_200420 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
struct CTriggerVolumeManager_2004b0 {};
typedef const char* (CTriggerVolumeManager_2004b0::*TriggerMethod)(const char*);
class CActorManager_200540 {
  public:
    void invoke(const char*);
};
} // namespace fn_f3d6a774
namespace math {
class Vector_2007b0 { public: float x, y, z; };
}
namespace fn_f3d6a774 {
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f3d6a774
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f3d6a774 {
class CTriggerVolumeManager_2007b0 {};
typedef bool (CTriggerVolumeManager_2007b0::*Fn_2007b0)(const char*, math::Vector_2007b0, math::Vector_2007b0, float);
class Registry_2007b0 { public:
    void FUN_002007b0(const char* a1, CTriggerVolumeManager_2007b0* a2, Fn_2007b0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_2007b0;
template<> class Closure4_2007b0<CTriggerVolumeManager_2007b0, bool, const char*, math::Vector_2007b0, math::Vector_2007b0, float> : public ScriptFunctionFields { public: virtual void v(); Fn_2007b0 fn; CTriggerVolumeManager_2007b0* owner; Closure4_2007b0(CTriggerVolumeManager_2007b0* o) { owner = o; } };
class Raw_2007b0 { public: void FUN_001feca0(const char*, Fn_2007b0); };
class Owner {};
typedef bool (Owner::*Fn_2008b0)(const char*, const char*);
class Registry_2008b0 { public:
    void FUN_002008b0(const char* a1, Owner* a2, Fn_2008b0 a3);
};
class Closure2_2008b0 { public: void* FUN_001fffa0(const char*, Owner*, Fn_2008b0); };
typedef void (Owner::*Fn_200900)(const char*, float);
class Registry_200900 { public:
    void FUN_00200900(const char* a1, Owner* a2, Fn_200900 a3);
};
class Closure2_200900 { public: void* FUN_00200050(const char*, Owner*, Fn_200900); };
} // namespace fn_f3d6a774
namespace math {
class Vector_200950 { public: float x, y, z; };
}
namespace fn_f3d6a774 {
class CTriggerVolumeManager_200950 {};
typedef bool (CTriggerVolumeManager_200950::*Fn_200950)(math::Vector_200950, const char*, bool);
class Registry_200950 { public:
    void FUN_00200950(const char* a1, CTriggerVolumeManager_200950* a2, Fn_200950 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_200950;
template<> class Closure3_200950<CTriggerVolumeManager_200950, bool, math::Vector_200950, const char*, bool> : public ScriptFunctionFields { public: virtual void v(); Fn_200950 fn; CTriggerVolumeManager_200950* owner; Closure3_200950(CTriggerVolumeManager_200950* o) { owner = o; } };
class Raw_200950 { public: void FUN_001fefe0(const char*, Fn_200950); };
class CTriggerVolumeManager_200a00 {};
typedef bool (CTriggerVolumeManager_200a00::*Fn_200a00)(const char*, int, int, bool);
class Registry_200a00 { public:
    void FUN_00200a00(const char* a1, CTriggerVolumeManager_200a00* a2, Fn_200a00 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_200a00;
template<> class Closure4_200a00<CTriggerVolumeManager_200a00, bool, const char*, int, int, bool> : public ScriptFunctionFields { public: virtual void v(); Fn_200a00 fn; CTriggerVolumeManager_200a00* owner; Closure4_200a00(CTriggerVolumeManager_200a00* o) { owner = o; } };
class Raw_200a00 { public: void FUN_001ff150(const char*, Fn_200a00); };
class CTriggerVolumeManager_200ab0 {};
typedef void (CTriggerVolumeManager_200ab0::*Fn_200ab0)(const char*, int, bool);
class Registry_200ab0 { public:
    void FUN_00200ab0(const char* a1, CTriggerVolumeManager_200ab0* a2, Fn_200ab0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_200ab0;
template<> class Closure3_200ab0<CTriggerVolumeManager_200ab0, void, const char*, int, bool> : public ScriptFunctionFields { public: virtual void v(); Fn_200ab0 fn; CTriggerVolumeManager_200ab0* owner; Closure3_200ab0(CTriggerVolumeManager_200ab0* o) { owner = o; } };
class Raw_200ab0 { public: void FUN_001ff2c0(const char*, Fn_200ab0); };
} // namespace fn_f3d6a774
namespace math {
class Vector_200b10 { public: float x, y, z; };
}
namespace fn_f3d6a774 {
class CTriggerVolumeManager_200b10 {};
typedef const char* (CTriggerVolumeManager_200b10::*Fn_200b10)(const math::Vector_200b10, int, int, float, float);
class Registry_200b10 { public:
    void FUN_00200b10(const char* a1, CTriggerVolumeManager_200b10* a2, Fn_200b10 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5_200b10;
template<> class Closure5_200b10<CTriggerVolumeManager_200b10, const char*, const math::Vector_200b10, int, int, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_200b10 fn; CTriggerVolumeManager_200b10* owner; Closure5_200b10(CTriggerVolumeManager_200b10* o) { owner = o; } };
class Raw_200b10 { public: void FUN_001ff360(const char*, Fn_200b10); };


// 0x001fc690 FUN_001fc690 (1 B): matches/0x001fc690.cpp
// sym: ?FUN_001fc690@fn_f3d6a774@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001fc690(void* /*this, unused: callers pass it (unb4)*/) {}


// 0x001fc6a0 FUN_001fc6a0 (228 B): equivalent/0x001fc6a0.cpp
// sym: ?FUN_001fc6a0@Dispatcher_1fc6a0@fn_f3d6a774@@QAEXH@Z @cd163d5fb243 @wf5c71573033d @vde0505be02dc
// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 20/22, incomplete)
// FUN_001fc6a0 @ 0x001fc6a0
void Dispatcher_1fc6a0::FUN_001fc6a0(hulk_intptr arg)
{
    UnitList *list = world->units;
    int count = list->count;
    for (int i = 0; i < count; i++) {
        Unit_1fc6a0 *unit = list->FUN_00024190(i);
        if (unit == 0)
            continue;
        Handler_1fc6a0 *best = 0;
        for (int j = 0; j < handlerCount; j++) {
            if (handlers[j]->vf12(unit) && handlers[j]->enabled && handlers[j]->active)
                best = handlers[j];
        }
        unit->FUN_00036be0(best);
        if (unit == list->current) {
            for (int off = 0; off < 0x6380; off += 0xc70)
                ((Slot_1fc6a0 *)(slots + off))->FUN_001fa7d0(unit, arg);
        }
    }
}


// 0x001fc790 FUN_001fc790 (39 B): matches/0x001fc790.cpp
// sym: ?ClearAll@Thing_1fc790@fn_f3d6a774@@QAEXXZ
void Thing_1fc790::ClearAll() {
    for (int i = 0; i < count; ++i)
        ((owners::Obj_1fb940 *)(items[i]))->FUN_001fb940();
}


// 0x001fc7c0 FUN_001fc7c0 (39 B): matches/0x001fc7c0.cpp
// sym: ?ClearAll@Thing_1fc7c0@fn_f3d6a774@@QAEXXZ
// Same code shape as 0x001fc790 (propagated; names are from that function)
void Thing_1fc7c0::ClearAll() {
    for (int i = 0; i < count; ++i)
        items[i]->Clear_001fb950();
}


// 0x001fc7f0 FUN_001fc7f0 (72 B): matches/0x001fc7f0.cpp
// sym: ?FUN_001fc7f0@CTriggerVolumeManager_1fc7f0@fn_f3d6a774@@QAEPAUEntry@2@I@Z
Entry* CTriggerVolumeManager_1fc7f0::FUN_001fc7f0(unsigned value) {
    unsigned __int64 key = FUN_00096d80(value);
    for (int i = 0; i < 128; ++i) {
        Entry* entry = slots[i];
        if (entry && entry->key == key)
            return entry;
    }
    return 0;
}

} // namespace fn_f3d6a774

// 0x001fc850 FUN_001fc850 (56 B): equivalent/0x001fc850.cpp [wrapped: conflict: Entry]
// sym: ?FUN_001fc850@Table@fn_001fc850@@QAEPAUEntry@2@HH@Z @80ecf4e0f7df @w6172117bd66d @v7f8c65a6f0f7
namespace fn_001fc850 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 8/8)
// FUN_001fc850 @ 0x001fc850
struct Entry { char padding[8]; int first; int second; }; struct Table { char padding[12]; Entry* entries[128]; Entry* FUN_001fc850(int first, int second); }; Entry* Table::FUN_001fc850(int first, int second) { for (int i = 0; i < 128; ++i) { Entry* entry = entries[i]; if (entry && entry->first == first && entry->second == second) return entry; } return 0; }
} // namespace fn_001fc850

namespace fn_f3d6a774 {

// 0x001fc890 FUN_001fc890 (48 B): matches/0x001fc890.cpp
// sym: ?run@Owner_1fc890@fn_f3d6a774@@QAEXPAX0@Z
void Owner_1fc890::run(void* a, void* b) {
    for (int i = 0; i != 128; ++i) {
        Entry_1fc890* p = entries[i];
        if (p != 0)
            p->f9(a, b, 0);
    }
}


// 0x001fc8c0 FUN_001fc8c0 (185 B): equivalent/0x001fc8c0.cpp
// sym: ?FUN_001fc8c0@CTriggerVolumeManager_1fc8c0@fn_f3d6a774@@QAEPAUEntry_1fc8c0@2@II@Z @2deb760b9542 @wb1ea42e3e8ef @v7f706201db1a
// STATUS: equivalent (tools/equiv.py level 3: 178 inputs, branch coverage 22/22)
// FUN_001fc8c0 @ 0x001fc8c0
Entry_1fc8c0 *CTriggerVolumeManager_1fc8c0::FUN_001fc8c0(unsigned int key1, unsigned int key2) {
    for (int i = 0; i < count; ++i) {
        if (entries[i].key1 == key1 && entries[i].key2 == key2)
            return entries + i;
    }
    for (int g = 0; g < 6; ++g) {
        Bucket_1fc8c0 *buckets = groups[g];
        for (int b = 0; b < 20; ++b) {
            Entry_1fc8c0 *entry = buckets[b].entries;
            int n = buckets[b].count;
            for (int j = 0; j < n; ++j, ++entry) {
                if (entry && entry->key1 == key1 && entry->key2 == key2)
                    return entry;
            }
        }
    }
    return 0;
}


// 0x001fc9a0 FUN_001fc9a0 (45 B): matches/0x001fc9a0.cpp
// sym: ?Find@Obj@fn_f3d6a774@@QAEPAVItem@2@H@Z
// data: fallback = DAT_003f335c
Item* Obj::Find(int index) {
    if (index < 0 || index > count)
        return (Item*)&(*(int*)&DAT_003f335c);
    Item* p = &items[index];
    return p->Get_001fba60();
}

} // namespace fn_f3d6a774

// 0x001fc9d0 FUN_001fc9d0 (18 B): matches/0x001fc9d0.cpp
// sym: ?FUN_001fc9d0@CTriggerVolumeManager@@QAE_NH@Z
bool CTriggerVolumeManager::FUN_001fc9d0(int x) {
    return (bool)((CTriggerVolumeManager_nv_1fc9d0*)(this))->FUN_001fc7f0(x);
}


// 0x001fc9f0 FUN_001fc9f0 (65 B): equivalent/0x001fc9f0.cpp
// sym: ?FUN_001fc9f0@CTriggerVolumeManager@@QAEXPAXH@Z @d3fcc8226970 @wcf3638e04c92 @v57db8f1ea0a9
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 2/2)
// FUN_001fc9f0 @ 0x001fc9f0
void CTriggerVolumeManager::FUN_001fc9f0(void* __p0, int id) { Result * out = (Result *)__p0;

    Object_1fc9f0* object = ((CTriggerVolumeManager_nv_1fc9f0*)(this))->FUN_001fc7f0(id);
    if (object) *out = object->value;
    else { out->x = 0; out->y = 0; out->z = 0; }
}


// 0x001fca40 FUN_001fca40 (65 B): equivalent/0x001fca40.cpp
// sym: ?FUN_001fca40@CTriggerVolumeManager@@QAEXPAXI@Z @8d92f3583eef @wcf9643a13b01 @vebc044152f66
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 2/2)
// FUN_001fca40 @ 0x001fca40
void CTriggerVolumeManager::FUN_001fca40(void* __p0, unsigned int id) { Vec3 * output = (Vec3 *)__p0;

    Object_1fca40* object = ((CTriggerVolumeManager_nv_1fca40*)(this))->FUN_001fc7f0(id);
    if (object) *output = object->position;
    else { output->x = 0; output->y = 0; output->z = 0; }
}


// 0x001fca90 FUN_001fca90 (32 B): matches/0x001fca90.cpp
// sym: ?FUN_001fca90@CTriggerVolumeManager@@QAEMH@Z
float CTriggerVolumeManager::FUN_001fca90(int arg) {
    Info* p = ((CTriggerVolumeManager_nv_1fca90*)(this))->GetInfo_001fc7f0(arg);
    if (!p)
        return (*(float*)&DAT_003f32e0);
    return p->value;
}


// 0x001fcab0 FUN_001fcab0 (115 B): matches/0x001fcab0.cpp
// sym: ?FUN_001fcab0@CTriggerVolumeManager@@QAE_NHM@Z
// FUN_001fcab0 @ 0x001fcab0
bool CTriggerVolumeManager::FUN_001fcab0(int id, float degrees) {
    Actor_1fcab0 *actor = ((CTriggerVolumeManager_nv_1fcab0*)(this))->FUN_001fc7f0(id);
    if (actor == 0)
        return false;
    Vec3_1fcab0 a = actor->a;
    Vec3_1fcab0 b = actor->b;
    actor->FUN_001fbb80(&a, &b, degrees * 0.01745329238474369f);
    return true;
}

namespace fn_f3d6a774 {

// 0x001fcb30 FUN_001fcb30 (55 B): matches/0x001fcb30.cpp
// sym: ?Target@ThisWrap_001fcb30@fn_f3d6a774@@QAE_NHUVec3_1fcb30@2@0M@Z
// a..c and d..f: two vectors passed by value.
bool ThisWrap_001fcb30::Target(int id, Vec3_1fcb30 a, Vec3_1fcb30 d, float angle) {
    CTriggerVolumeManager* o = this->Find_001fc7f0(id);
    if (!o)
        return false;
    ((CTriggerVolumeManager_nv_1fcb30*)(o))->Set_001fbb80(&a, &d, angle * 0.017453292519943295f);
    return true;
}

} // namespace fn_f3d6a774

// 0x001fcb70 FUN_001fcb70 (28 B): matches/0x001fcb70.cpp
// sym: ?FUN_001fcb70@CTriggerVolumeManager@@QAEDI@Z
char CTriggerVolumeManager::FUN_001fcb70(unsigned int x) {
    R* p = (R*)((CTriggerVolumeManager_nv_1fcb70*)(this))->FUN_001fc7f0(x);
    if (p == 0)
        return 0;
    return p->f;
}


// 0x001fcb90 FUN_001fcb90 (44 B): matches/0x001fcb90.cpp
// sym: ?FUN_001fcb90@CTriggerVolumeManager@@QAEEH@Z
unsigned char CTriggerVolumeManager::FUN_001fcb90(int n) {
    CTriggerVolumeManager_1fcb90* p = ((CTriggerVolumeManager_nv_1fcb90*)(this))->Find_001fc7f0(n);
    if (p && p->b && p->a)
        return 1;
    return 0;
}


// 0x001fcbc0 FUN_001fcbc0 (27 B): matches/0x001fcbc0.cpp
// sym: ?FUN_001fcbc0@CTriggerVolumeManager@@QAEXPAXD@Z
void CTriggerVolumeManager::FUN_001fcbc0(void* p, char c) {
    X_1fcbc0* q = ((CTriggerVolumeManager_nv_1fcbc0*)(this))->FUN_001fc7f0(p);
    if (q)
        q->m = c;
}


// 0x001fcbe0 FUN_001fcbe0 (29 B): matches/0x001fcbe0.cpp
// sym: ?FUN_001fcbe0@CTriggerVolumeManager@@QAEDH@Z
char CTriggerVolumeManager::FUN_001fcbe0(int a) {
    CTriggerVolumeManager_1fcbe0* r = ((CTriggerVolumeManager_nv_1fcbe0*)(this))->FUN_001fc7f0(a);
    if (!r)
        return 1;
    return r->V11();
}


// 0x001fcc00 FUN_001fcc00 (61 B): matches/0x001fcc00.cpp
// sym: ?FUN_001fcc00@CTriggerVolumeManager@@QAEDHH@Z
char CTriggerVolumeManager::FUN_001fcc00(int a, int b) {
    CTriggerVolumeManager_1fcc00* o = ((CTriggerVolumeManager_nv_1fcc00*)(this))->lookup_001fc7f0(b);
    if (!o)
        return 0;
    if (!o->enabled)
        return 0;
    return o->act(convert(a));
}


// 0x001fcc40 FUN_001fcc40 (24 B): matches/0x001fcc40.cpp
// sym: ?FUN_001fcc40@CTriggerVolumeManager@@QAEXPAX@Z
void CTriggerVolumeManager::FUN_001fcc40(void* p) {
    Obj_1fcc40* r = ((CTriggerVolumeManager_nv_1fcc40*)(this))->Helper_001fc7f0(p);
    if (r) {
        r->flag = 0;
    }
}


// 0x001fcc60 FUN_001fcc60 (24 B): matches/0x001fcc60.cpp
// sym: ?FUN_001fcc60@CTriggerVolumeManager@@QAEXH@Z
void CTriggerVolumeManager::FUN_001fcc60(int id) {
    CTriggerVolumeManager_1fcc60* p = ((CTriggerVolumeManager_nv_1fcc60*)(this))->findObj_001fc7f0(id);
    if (p)
        p->flag = 1;
}


// 0x001fcc80 FUN_001fcc80 (38 B): matches/0x001fcc80.cpp
// sym: ?FUN_001fcc80@CTriggerVolumeManager@@QAEXHH@Z
void CTriggerVolumeManager::FUN_001fcc80(int a, int b) {
    Item* p = ((CTriggerVolumeManager_nv_1fcc80*)this)->Find_001fc7f0(a);
    if (p)
        (*(Mid * *)&this->f_04)->helper->Apply_001e7290(p, b);
}

namespace fn_f3d6a774 {

// 0x001fccb0 FUN_001fccb0 (55 B): matches/0x001fccb0.cpp
// sym: ?get@CTriggerVolumeManager_1fccb0@fn_f3d6a774@@QAEPADH@Z
char* CTriggerVolumeManager_1fccb0::get(int index) {
    if (index >= count)
        return 0;
    Item* p = items[index];
    FUN_00096d50(hulk_at_004e58e8, 0x40, p->a, p->b);
    return hulk_at_004e58e8;
}


// 0x001fccf0 FUN_001fccf0 (188 B): matches/0x001fccf0.cpp
// sym: ?FUN_001fccf0@CTriggerVolumeManager_1fccf0@fn_f3d6a774@@QAEXIE@Z
void CTriggerVolumeManager_1fccf0::FUN_001fccf0(unsigned int arg, unsigned char active) {
    Filter_1fccf0* filter = FUN_001fc7f0(arg);
    if (!filter)
        return;
    count = 0;
    Collection_1fccf0* collection = owner->collection;
    int n = collection->FUN_001dcf50();
    for (int i = n - 1; i >= 0; --i) {
        Item_1fccf0* item = ((Item_1fccf0 *)((owners::CGrabAction_1dc0b0 *)collection)->FUN_001dc0b0(i));
        ((owners::C_1d72e0 *)item)->FUN_001d72e0();
        if (active && !item->FUN_001d7300())
            continue;
        if (item->excluded)
            continue;
        Vector* v = item->FUN_001d6b40();
        if (filter->test(*v)) {
            results[count] = item;
            ++count;
        }
    }
}


// 0x001fcdb0 FUN_001fcdb0 (150 B): equivalent/0x001fcdb0.cpp
// sym: ?FUN_001fcdb0@Spawner_1fcdb0@fn_f3d6a774@@QAEXHH@Z @b863a5a0e26e @w7dbc1b7e109f @vf5fe5744abab
// STATUS: equivalent (tools/equiv.py level 3: 344 inputs, branch coverage 13/14, incomplete)
// FUN_001fcdb0 @ 0x001fcdb0
void Spawner_1fcdb0::FUN_001fcdb0(int key, int arg)
{
    Target_1fcdb0 *target = FUN_001fc850(FUN_00096d80(key));
    if (target == 0)
        return;
    EntityList_1fcdb0 *list = holder->list;
    int count = list->count;
    for (int i = 0; i < count; i++) {
        Entity *e = list->FUN_00024190(i);
        if (e == 0)
            continue;
        if (list->FUN_000242d0(e))
            continue;
        if (target->Accepts(e->fieldA, e->fieldB))
            e->FUN_00043350(arg, 0, 0, 1.0f, 1, 0);
    }
}


// 0x001fce50 FUN_001fce50 (75 B): matches/0x001fce50.cpp
// sym: ?FUN_001fce50@CTriggerVolumeManager_nv_1fce50@fn_f3d6a774@@QAEEUTrip@2@HE@Z
// a..c: a 3-word value passed by value and forwarded to the volume's slot 8. A by-value struct parameter can't be
// declared in include/gen (tools/gen_headers.py nv_sig_type), so the member is defined on a local stand-in.
unsigned char CTriggerVolumeManager_nv_1fce50::FUN_001fce50(Trip a, int id, unsigned char enabled) {
    CTriggerVolumeManager_1fce50* p = Find_001fc7f0(id);
    if (!p)
        return 0;
    if (enabled && !p->flag)
        return 0;
    return p->run(a);
}


// 0x001fcea0 FUN_001fcea0 (146 B): equivalent/0x001fcea0.cpp
// sym: ?add@Owner_1fcea0@fn_f3d6a774@@QAE_NPAVInput_1fcea0@2@@Z @b6f941d46a42 @wea94feab86b7 @vfe36ed42de3a
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 2/2)
// FUN_001fcea0 @ 0x001fcea0
bool Owner_1fcea0::add(Input_1fcea0* p) {
    if (count < 0x100) {
        char tmp[12];
        int a = p->get(tmp);
        ((owners::Target_1fb990 *)&(records[count]))->FUN_001fb990((const int *)(hulk_uintptr)(int)a);
        float arg1 = p->value();
        records[count].second_001fb9b0(arg1);
        int b = p->process_001fba60();
        records[count].third_001fbfd0(b);
        ++count;
        return true;
    }
    return false;
}

} // namespace fn_f3d6a774

// 0x001fcf40 FUN_001fcf40 (49 B): matches/0x001fcf40.cpp
// sym: ?FUN_001fcf40@CTriggerVolumeManager@@QAEHXZ
hulk_intptr CTriggerVolumeManager::FUN_001fcf40() {
    hulk_intptr result = 0;
    if (this->f_20c < 256) {
        char* p = (char*)(*(void * *)&this->f_210) + (this->f_20c << 6);
        FUN_001fb970(p);
        ++this->f_20c;
        result = (hulk_intptr)p;
    }
    return result;
}


// 0x001fcff0 FUN_001fcff0 (75 B): matches/0x001fcff0.cpp [wrapped: conflict: Entry]
// sym: ?Find@Obj@fn_001fcff0@@QAEHI@Z
namespace fn_001fcff0 {
unsigned __int64 __cdecl lookup_0027b020(unsigned);
struct Entry {
    unsigned __int64 key;
    char pad[0x448];
    unsigned active;
    char tail[0x81c];
};
struct Holder {
    char pad[8];
    Entry entries[8];
};
class Obj {
    char pad[0x234];
    Holder* holder;

  public:
    int Find(unsigned x);
};
int Obj::Find(unsigned x) {
    unsigned __int64 k = lookup_0027b020(x);
    for (int i = 0; i < 8; i++) {
        Entry* e = &holder->entries[i];
        if (e->active && e->key == k)
            return i;
    }
    return -1;
}
} // namespace fn_001fcff0

namespace fn_f3d6a774 {

// 0x001fd070 FUN_001fd070 (189 B): equivalent/0x001fd070.cpp
// sym: ?target@Owner_1fd070@fn_f3d6a774@@QAEXH@Z @73b743d69b10 @w41e296adcd28 @v402f5d026d44
// STATUS: equivalent (tools/equiv.py level 3: 424 inputs, branch coverage 12/12)
// FUN_001fd070 @ 0x001fd070
void Owner_1fd070::target(int index) {
 if (!states[index].enabled) return;
 for (int type=0; type<6; ++type) {
  for (int group=0; group<20; ++group) {
   for (int n=0; n<groups[type][group].count; ++n) {
    if (states[index].FUN_001f8740(type)) {
     Item_1fd070* item = &groups[type][group].items[n];
     states[index].FUN_001f8fe0(item);
    }
   }
  }
 }
}


// 0x001fd130 FUN_001fd130 (80 B): matches/0x001fd130.cpp
// sym: ?Target@CTriggerVolumeManager_1fd130@fn_f3d6a774@@QAEXPAX0@Z
void CTriggerVolumeManager_1fd130::Target(void* p2, void* p3) {
    for (hulk_intptr i = 0; i < 0x6380; i += 0xc70) {
        Elem_1fd130* e = (Elem_1fd130*)(mArray + i);
        if (e->mFlag != 0) {
            if (((Elem_1fd130*)(mArray + i))->Check_001f8740(p3)) {
                ((Elem_1fd130*)(mArray + i))->Do_001f8fe0(p2);
            }
        }
    }
}

} // namespace fn_f3d6a774

// 0x001fd180 FUN_001fd180 (148 B): matches/0x001fd180.cpp
// sym: ?FUN_001fd180@C_1fd180@owners@@QAEXH@Z
void owners::C_1fd180::FUN_001fd180(int value) {
    int i;
    int found = -1;
    for (i = 0; i < 20; i++) {
        if (slots[i] == value) {
            found = i;
            break;
        }
        if (slots[i] == -1)
            found = i;
    }
    last = found;
    if (found != -1) {
        a[0][found * 2] = 0;
        a[1][found * 2] = 0;
        a[2][found * 2] = 0;
        a[3][found * 2] = 0;
        a[4][found * 2] = 0;
        a[5][found * 2] = 0;
        slots[found] = value;
    }
}

namespace fn_f3d6a774 {

// 0x001fd220 FUN_001fd220 (313 B): equivalent/0x001fd220.cpp
// sym: ?run@Obj_1fd220@fn_f3d6a774@@QAEXH@Z @8117e7f9c304 @w81dde8294d90 @ve70670d60f9d
// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 15/16, incomplete)
// FUN_001fd220 @ 0x001fd220
void Obj_1fd220::run(int id)
{
    int idx;
    for (idx = 0; idx < 20; idx++) {
        if (ids[idx] == id)
            break;
    }
    if (idx >= 20)
        return;

    ids[idx] = -1;
    for (int off = 0; off < 0x6380; off += 0xc70) {
        Slot_1fd220* slot = (Slot_1fd220*)(slots + off);
        if (*(int*)(slots + off + 0x418) == 0)
            continue;
        for (int k = 0; k < 6; k++) {
            for (int i = 0; i < lists[k][idx].count; i++) {
                S8_1fd220 s;
                s.FUN_0027af30(lists[k][idx].data + i * 0x40 + 8);
                ((Slot_1fd220*)(slots + off))->FUN_001f8670(s);
            }
        }
    }
    for (int k = 0; k < 6; k++)
        lists[k][idx].count = 0;
}

} // namespace fn_f3d6a774

// 0x001fd360 FUN_001fd360 (35 B): matches/0x001fd360.cpp
// sym: ?FUN_001fd360@X_1fd360@owners@@QAEHH@Z
int owners::X_1fd360::FUN_001fd360(int value) {
    int r = -1;
    int i = 0;
    do {
        if (items[i] == value) {
            r = i;
            break;
        }
        ++i;
    } while (i < 0x14);
    return r;
}

namespace fn_f3d6a774 {

// 0x001fd390 FUN_001fd390 (161 B): matches/0x001fd390.cpp
// sym: ?FindName@fn_f3d6a774@@YGHPBD@Z
int __stdcall FindName(const char* s) {
    if (s) {
        if (strcmp(s, "rooftop") == 0)
            return 1;
        if (strcmp(s, "intersection") == 0)
            return 2;
        if (strcmp(s, "pasture") == 0)
            return 3;
        if (strcmp(s, "canyon") == 0)
            return 4;
        return ((strcmp(s, "military") != 0) - 1 & 6) - 1;
    }
    return -1;
}


// 0x001fd4c0 FUN_001fd4c0 (12 B): matches/0x001fd4c0.cpp
// sym: _FUN_001fd4c0@4
// data: hulk_at_004c83e8 = DAT_004c83e8
extern "C" unsigned int __stdcall FUN_001fd4c0(unsigned int x) {
    *(unsigned int*)((hulk_intptr)((char*)&DAT_004c83e8)) = x;
    return x;
}


// 0x001fd4d0 FUN_001fd4d0 (12 B): matches/0x001fd4d0.cpp
// sym: _FUN_001fd4d0@4
// data: g_value_1fd4d0 = DAT_004c83ec
extern "C" void __stdcall FUN_001fd4d0(int value) {
    (*(int*)&DAT_004c83ec) = value;
}


// 0x001fd640 FUN_001fd640 (238 B): equivalent/0x001fd640.cpp
// sym: ?FUN_001fd640@fn_f3d6a774@@YAXPAXPAUVec3_1fd640@1@11@Z @3bdb2035caa7 @w683e7f6174f1 @v53add7b90617
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 2/2)
// FUN_001fd640 @ 0x001fd640
void __cdecl FUN_001fd640(void* context, Vec3_1fd640* start, Vec3_1fd640* end, Vec3_1fd640* output) {
    double dx = (double)end->x - start->x;
    float dy = end->y - start->y;
    double dz = (double)end->z - start->z;
    float length = (float)sqrt((dz*dz + (double)dy*dy) + dx*dx);
    if (length == 0.0f) {
        output->x = start->x;
        output->y = start->y;
        output->z = start->z;
        return;
    }
    double inv = 1.0 / length;
    Vec3_1fd640 direction;
    direction.x = (float)(dx*inv);
    direction.y = (float)(dy*inv);
    direction.z = (float)(dz*inv);
    FUN_0022d3a0(context,start,&direction,length,&length);
    double x = (double)direction.x * length;
    volatile float y = direction.y * length; // rounded frame copies in the original
    volatile float z = direction.z * length;
    double ox = x + start->x;
    double oy = (double)y + start->y;
    double oz = (double)z + start->z;
    output->x = (float)ox;
    output->y = (float)oy;
    output->z = (float)oz;
}


// 0x001fd730 FUN_001fd730 (80 B): matches/0x001fd730.cpp
// sym: ?Clear@Obj_1fd730@fn_f3d6a774@@QAEXXZ
void Obj_1fd730::Clear() {
    int i;
    for (i = 0; i < 128; i++) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    f8 = 0;
    f20c = 0;
    for (i = 0; i < 0x6380; i += 0xc70)
        ((Part_1fd730*)((char*)parts + i))->Run_001fa040();
}


// 0x001fd780 FUN_001fd780 (29 B): matches/0x001fd780.cpp
// sym: ?Target@CTriggerVolumeManager_1fd780@fn_f3d6a774@@QAEHI@Z
// Same code shape as 0x000238b0 (propagated; names are from that function)
hulk_intptr CTriggerVolumeManager_1fd780::Target(U_1fd780 param) {
    U64_1fd780 a = FUN_0027b020(param);
    return Second_001fc8c0(a);
}

} // namespace fn_f3d6a774

// 0x001fd7a0 FUN_001fd7a0 (34 B): matches/0x001fd7a0.cpp [wrapped: conflict: convert]
// sym: ?run@CTriggerVolumeManager_1fd7a0@fn_001fd7a0@@QAEDH@Z
namespace fn_001fd7a0 {
struct Pair {
    int a, b;
};
Pair __cdecl convert_0027b020(int);
class CTriggerVolumeManager_1fd7a0 {
  public:
    int check_001fc8c0(int, int);
    char run(int);
};
char CTriggerVolumeManager_1fd7a0::run(int x) {
    Pair p = convert_0027b020(x);
    return check_001fc8c0(p.a, p.b) != 0;
}
} // namespace fn_001fd7a0


// 0x001fd7d0 FUN_001fd7d0 (95 B): matches/0x001fd7d0.cpp [wrapped: conflict: Result]
// sym: ?FUN_001fd7d0@CTriggerVolumeManager_1fd7d0@fn_001fd7d0@@QAEPAUResult@2@PAU32@I@Z
namespace fn_001fd7d0 {
struct Result {
    unsigned int x, y, z;
};
struct Item {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void FUN_001fd7d0_slot8(Result* out);
};
unsigned __int64 __cdecl FUN_0027b020(unsigned int value);
struct CTriggerVolumeManager_1fd7d0 {
    Item* FUN_001fc8c0(unsigned __int64 key);
    Result* FUN_001fd7d0(Result* out, unsigned int value);
};
Result* CTriggerVolumeManager_1fd7d0::FUN_001fd7d0(Result* out, unsigned int value) {
    unsigned __int64 key = FUN_0027b020(value);
    Item* item = FUN_001fc8c0(key);
    if (!item) {
        out->x = 0;
        out->y = 0;
        out->z = 0;
        return out;
    }
    Result result;
    item->FUN_001fd7d0_slot8(&result);
    *out = result;
    return out;
}
} // namespace fn_001fd7d0


// 0x001fd830 FUN_001fd830 (55 B): matches/0x001fd830.cpp
// sym: ?FUN_001fd830@CTriggerVolumeManager@@QAEMI@Z
// data: scale_1fd830 = DAT_003f3ef4, zero_1fd830 = DAT_003f32e0
hulk_freg CTriggerVolumeManager::FUN_001fd830(unsigned int arg) {
    unsigned long long k = FUN_0027b020(arg);
    Result_1fd830* r = ((CTriggerVolumeManager_nv_1fd830*)this)->Find_001fc8c0(k);
    if (!r)
        return DAT_003f32e0;
    return r->Get() * DAT_003f3ef4;
}

namespace fn_f3d6a774 {

// 0x001fd870 FUN_001fd870 (52 B): matches/0x001fd870.cpp
// sym: ?Do@CTriggerVolumeManager_1fd870@fn_f3d6a774@@QAE_NHUData@2@@Z
bool CTriggerVolumeManager_1fd870::Do(int n, Data d) {
    U64 id = Convert_0027b020(n);
    Item* item = Find_001fc8c0(id);
    if (!item)
        return false;
    ((owners::Target_1fb990 *)item)->FUN_001fb990((const int *)(Data *)(&d));
    return true;
}

} // namespace fn_f3d6a774

// 0x001fd8b0 FUN_001fd8b0 (61 B): matches/0x001fd8b0.cpp
// sym: ?FUN_001fd8b0@CTriggerVolumeManager@@QAE_NHM@Z
bool CTriggerVolumeManager::FUN_001fd8b0(int key, float angle) {
    Pair p = Lookup_0027b020(key);
    Item* item = ((CTriggerVolumeManager_nv_1fd8b0*)this)->Find_001fc8c0(p.a, p.b);
    if (!item)
        return false;
    item->SetAngle_001fb9b0(angle * 0.017453292519943295f);
    return true;
}


// 0x001fd8f0 FUN_001fd8f0 (45 B): matches/0x001fd8f0.cpp
// sym: ?FUN_001fd8f0@CTriggerVolumeManager@@QAEEPAX@Z
unsigned char CTriggerVolumeManager::FUN_001fd8f0(void* p) {
    __int64 x = Convert_0027b020(p);
    Other* o = (Other*)((CTriggerVolumeManager_nv_1fd8f0*)this)->Find_001fc8c0(x);
    if (!o)
        return 0;
    return o->Valid_001fba00();
}

namespace fn_f3d6a774 {

// 0x001fd920 FUN_001fd920 (81 B): matches/0x001fd920.cpp
// sym: ?Run@CTriggerVolumeManager_1fd920@fn_f3d6a774@@QAEXHHH@Z
void CTriggerVolumeManager_1fd920::Run(int a, int b, int c) {
    Setup_001fccf0(a, c);
    for (int i = 0; i < count; i++)
        items[i]->Send_001d6ec0(b, 0, 0);
}

} // namespace fn_f3d6a774

// 0x001fd980 FUN_001fd980 (25 B): matches/0x001fd980.cpp
// sym: ?FUN_001fd980@CTriggerVolumeManager@@QAEHH@Z
int CTriggerVolumeManager::FUN_001fd980(int a) {
    ((CTriggerVolumeManager_nv_1fd980*)this)->Helper_001fccf0(a, 1);
    return this->f_238;
}

namespace fn_f3d6a774 {

// 0x001fdeb0 FUN_001fdeb0 (82 B): equivalent/0x001fdeb0.cpp
// sym: ?FUN_001fdeb0@Game@fn_f3d6a774@@QAE_NH_N@Z @ff165ac74b78 @w0d58c7bfd47b @v7b2a57244125
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001fdeb0 @ 0x001fdeb0
bool Game::FUN_001fdeb0(int id, bool flag) { int index = FUN_001fcff0(id); if (index == -1 || !entries[index].active) return false; entries[index].FUN_001fa500(flag ? 2 : 1); return true; }


// 0x001fdf10 FUN_001fdf10 (51 B): matches/0x001fdf10.cpp
// sym: ?check@CTriggerVolumeManager_1fdf10@fn_f3d6a774@@QAEDH@Z
char CTriggerVolumeManager_1fdf10::check(int x) {
    int i = ((CTriggerVolumeManager_nv_1fdf10*)(((CTriggerVolumeManager*)this)))->FUN_001fcff0(x);
    if (i == -1)
        return 0;
    return *(int*)(data + i * 0xc70 + 0x458) == 2;
}


// 0x001fdf50 FUN_001fdf50 (64 B): matches/0x001fdf50.cpp
// sym: ?Run@CTriggerVolumeManager_1fdf50@fn_f3d6a774@@QAE_NHHHH@Z
bool CTriggerVolumeManager_1fdf50::Run(int id, int a, int b, int c) {
    int i = Find_001fcff0(id);
    if (i == -1)
        return false;
    return ((Item*)((char*)items + i * 0xc70))->Set_001f9460(a, b, c);
}


// 0x001fdf90 FUN_001fdf90 (47 B): matches/0x001fdf90.cpp
// sym: ?Lookup@CTriggerVolumeManager_1fdf90@fn_f3d6a774@@QAEPAXH@Z
void* CTriggerVolumeManager_1fdf90::Lookup(int x) {
    int i = GetIndex_001fcff0(x);
    if (i == -1)
        return 0;
    return *(void**)(data + i * 0xc70 + 0x6e0);
}

} // namespace fn_f3d6a774

// 0x001fdfc0 FUN_001fdfc0 (51 B): matches/0x001fdfc0.cpp [wrapped: conflict: Obj]
// sym: ?Go@Obj@fn_001fdfc0@@QAE_NH@Z
namespace fn_001fdfc0 {
class Item {
  public:
    void Act_001fa040();
    char pad[0xc70];
};
struct This_Lookup {
    int Lookup_001fcff0(int);
};
class Obj {
    char pad[0x234];
    Item* items;

  public:
    bool Go(int);
};
bool Obj::Go(int id) {
    int i = ((This_Lookup*)this)->Lookup_001fcff0(id);
    if (i == -1)
        return false;
    items[i].Act_001fa040();
    return true;
}
} // namespace fn_001fdfc0

namespace fn_f3d6a774 {

// 0x001fe000 FUN_001fe000 (123 B): equivalent/0x001fe000.cpp
// sym: ?FUN_001fe000@Mixer@fn_f3d6a774@@QAEXPAUPool_1fe000@2@@Z @1df5399d9886 @w5541a6751352 @vccc418f3da96
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 9/10, incomplete)
// FUN_001fe000 @ 0x001fe000
// 8-byte id with the game's copy routine.
// equiv-map: ??0Id8@@QAE@ABU0@@Z = 0x0027af30
// equiv-map: ??0Name@@QAE@ABU0@@Z = 0x001f8940
void Mixer::FUN_001fe000(Pool_1fe000 *pool) {
    Entry_1fe000 *e = &pool->entry;
    if (e == 0) {
        return;
    }
    char slot = e->slot;
    if (slot == (char)0xff) {
        return;
    }
    int offset = slot * 0xc70;
    short idx = ((Slot_1fe000 *)(slots + offset))->FUN_001f9630(*(RawName *)e);
    if (idx == -2 || idx == -1 || idx < 0) {
        return;
    }
    ((Slot_1fe000 *)(slots + offset))->FUN_001f9670(*(Name *)e, idx + 1);
}

} // namespace fn_f3d6a774

// 0x001fe080 FUN_001fe080 (500 B): equivalent/0x001fe080.cpp [wrapped: conflict: World]
// sym: ?FUN_001fe080@ElemSet@fn_001fe080@@QAEPAVElem_1fe080@2@MMMHHMM@Z @45112fe8e4b8 @wf9f2bb93055d @v1a55313782b3
namespace fn_001fe080 {
// STATUS: equivalent (tools/equiv.py level 3: 3059 inputs, branch coverage 34/34)
// FUN_001fe080 @ 0x001fe080
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

struct V3_1fe080 {
    float x, y, z;
};

class Elem_1fe080 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual V3_1fe080 *getPos(V3_1fe080 *out);
    char pad04[0x40 - 4];
};

struct Group_1fe080 {
    int count;
    Elem_1fe080 *data;
};

struct Rng_1fe080 {
};
extern "C" Rng_1fe080 *__cdecl FUN_000964d0();

struct Zones {
    int FUN_00204200(float x, float y, float z);
};

struct Holder54_1fe080 {
};

struct World {
    void* vftable; void* parts[20];   /* (sweep2) the World's words (HulkWorld): +0x54 is CGame */
    Holder54_1fe080 *holder;        // 0x54
};

class ElemSet {
public:
    char pad00[0x214];
    Group_1fe080 *groups[6];        // 0x214

    Elem_1fe080 *FUN_001fe080(float x, float y, float z, int type, int mode, float yMin, float yMax);
};

Elem_1fe080 *ElemSet::FUN_001fe080(float x, float y, float z, int type, int mode, float yMin, float yMax)
{
    if (type < 0 || type >= 6)
        return 0;

    Elem_1fe080 *best = 0;
    float bestDist = 3.4028235e38f;

    if (mode == 2) {
        int zone = ((Zones *)((owners::Target_862a0 *)(DAT_004dd700->holder))->FUN_000862a0())->FUN_00204200(x, y, z);
        if (zone == -1)
            return 0;
        int idx = ((owners::X_1fd360 *)this)->FUN_001fd360(zone);
        if (idx == -1)
            return 0;
        int count = groups[type][idx].count;
        if (count <= 0)
            return 0;
        int pick = ((int)((owners::Random_11330 *)(FUN_000964d0()))->FUN_00011330((unsigned int)(count - 1)));
        return groups[type][idx].data + pick;
    }

    if (mode == 1)
        bestDist = 1.17549435e-38f;

    for (int gi = 0; gi < 20; gi++) {
        for (int j = 0; j < groups[type][gi].count; j++) {
            Elem_1fe080 *e = groups[type][gi].data + j;
            V3_1fe080 tmp;
            V3_1fe080 q = *e->getPos(&tmp);
            if (q.y < yMin)
                continue;
            if (q.y > yMax)
                continue;
            double dx = (double)x - (double)q.x;
            double dy = (double)y - (double)q.y;
            double dz = (double)z - (double)q.z;
            double total = dz * dz + dx * dx + dy * dy;
            if (mode == 0) {
                if (total < bestDist) {
                    bestDist = (float)total;
                    best = e;
                }
            } else if (mode == 1) {
                if (total > bestDist) {
                    bestDist = (float)total;
                    best = e;
                }
            } else {
                return e;
            }
        }
    }
    return best;
}
} // namespace fn_001fe080
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001fe280 FUN_001fe280 (249 B): equivalent/0x001fe280.cpp [wrapped: conflict: World]
// sym: ?FUN_001fe280@Target_1fe280@fn_001fe280@@QAEPBDH@Z @f40b4f9b5269 @w81e22615056c @v1478a09e56e7
namespace fn_001fe280 {
// STATUS: equivalent (tools/equiv.py level 3: 201 inputs, branch coverage 14/14)
// FUN_001fe280 @ 0x001fe280
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

struct Vec_1fe280 { float x,y,z; };
struct Item_1fe280 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual Vec_1fe280* position(Vec_1fe280*);
 char pad[60];
 const char* FUN_001fba60();
};
struct List_1fe280 { int count; Item_1fe280* items; };
struct Lookup_1fe280 { void FUN_00026c30(Vec_1fe280*, const char*); };
struct State_1fe280 { char pad[0x59c]; int key; };
struct Manager_1fe280 {  };
struct World { char pad[0x20]; Lookup_1fe280* lookup; char gap[0x30]; Manager_1fe280* manager; };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

struct Target_1fe280 {
 char pad[0x20c]; List_1fe280 fallback; List_1fe280* lists[6]; int* keys;
 int FUN_001fd390(int);
 const char* FUN_001fe280(int);
};
const char* Target_1fe280::FUN_001fe280(int arg) {
 Vec_1fe280 origin; DAT_004dd700->lookup->FUN_00026c30(&origin,"hulk");
 int index=FUN_001fd390(arg);
 int count=0; Item_1fe280* items=0;
 if(index<0) { count=fallback.count; items=fallback.items; }
 else { int key=((State_1fe280 *)((owners::Target_862a0 *)(DAT_004dd700->manager))->FUN_000862a0())->key;
 for(int i=0;i<20;++i) if(keys[i]==key) { count=lists[index][i].count; items=lists[index][i].items; break; }
 }
 Item_1fe280* selected=0;
 for(int n=0;n<count;++n) { Vec_1fe280 temp; Vec_1fe280* p=items[n].position(&temp);
 double x=(double)origin.x-p->x, y=(double)origin.y-p->y, z=(double)origin.z-p->z;
 if(sqrt(z*z+y*y+x*x)<999999.0f) selected=&items[n];
 }
 if(selected) return selected->FUN_001fba60();
 return "none";
}
} // namespace fn_001fe280
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001fe380 FUN_001fe380 (1292 B): equivalent/0x001fe380.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_001fe380@Finder@fn_001fe380@@QAEDPAUV3@2@0@Z @54b398f5f1cd @wddc6375888b4 @v2d6e45092dca
namespace fn_001fe380 {
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 39/46, incomplete)
// FUN_001fe380 @ 0x001fe380
struct V3 {
    union {
        float x;
        int ix;
    };
    union {
        float y;
        int iy;
    };
    union {
        float z;
        int iz;
    };
};

extern "C++" __declspec(nothrow) void __cdecl FUN_001fd640(V3 *o, V3 *p, V3 *q, V3 *res);
// (integ2, D103) the object classes it gathers, {2, 3, 4, 5}: a const table in the XBE's .rdata (read-only), which
// only this function references (0x001fe389)
extern "C" const int DAT_00425260[4] HULK_RDATA;

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual V3 *v8(V3 *tmp);
    char pad[0x40 - 4];
};

struct List {
    int count;
    char *base;
};

struct Lists {
    List l[20];
};

struct Frame {
    int s0;
    V3 res;
    int n;
    int cnt;
    int idx;
    float best;
    union {
        V3 q;
        struct {
            int pad[2];
            V3 tmp;
        } tt;
    };
    int pad52;
    V3 p;
    V3 dd;
    V3 pts[160];
};

static hulk_freg DistSq(const V3 &a, const V3 &b)   // (inlined: the differences and the sum kept in st)
{
    hulk_freg dx = a.x - b.x;
    hulk_freg dy = a.y - b.y;
    hulk_freg dz = a.z - b.z;
    return dz * dz + dy * dy + dx * dx;
}

class Finder {
public:
    char pad0[0x214];
    Lists *lists[64];
    char FUN_001fe380(V3 *o, V3 *out);
};

char Finder::FUN_001fe380(V3 *o, V3 *out)
{
    Frame f;
    f.n = 0;
    for (const int *tp = DAT_00425260; tp < DAT_00425260 + 4; tp++) {
        int cls = *tp;
        for (int k = 0; k < 20; k++) {
            int count = lists[cls]->l[k].count;
            for (int i = 0; i < count; i++) {
                Obj *e = (Obj *)(lists[cls]->l[k].base + i * 0x40);
                if (e) {
                    if (f.n >= 160)
                        break;
                    V3 *r = e->v8(&f.tt.tmp);
                    f.pts[f.n].ix = r->ix;
                    f.pts[f.n].iy = r->iy;
                    f.pts[f.n].iz = r->iz;
                    f.n++;
                }
            }
        }
    }

    bool found = false;
    int n = f.n;
    if (n > 1) {
        float best = 3.4028235e38f;
        for (int i = 1; i < n; i++) {
            f.p.ix = f.pts[i - 1].ix;
            f.p.iy = f.pts[i - 1].iy;
            f.p.iz = f.pts[i - 1].iz;
            for (int j = i; j < n; j++) {
                f.q.ix = f.pts[j].ix;
                f.q.iy = f.pts[j].iy;
                f.q.iz = f.pts[j].iz;
                f.dd.ix = f.p.ix;
                f.dd.iy = f.p.iy;
                f.dd.iz = f.p.iz;
                if (!(DistSq(f.p, f.q) > 22500.0f)) {
                    f.res.x = 0.0f;
                    f.res.y = 0.0f;
                    f.res.z = 0.0f;
                    FUN_001fd640(o, &f.p, &f.q, &f.res);
                    int rx = f.res.ix, ry = f.res.iy, rz = f.res.iz;
                    V3 r;
                    r.ix = rx;
                    r.iy = ry;
                    r.iz = rz;
                    hulk_freg d = DistSq(r, *o);
                    if (d < best) {
                        best = d;
                        found = true;
                        out->ix = rx;
                        out->iy = ry;
                        out->iz = rz;
                    }
                }
            }
        }
        if (found)
            return found;
    }

    float best = 3.4028235e38f;
    for (int i = 0; i < n; i++) {
        hulk_freg d = DistSq(f.pts[i], *o);
        if (d < best) {
            best = d;
            out->ix = f.pts[i].ix;
            out->iy = f.pts[i].iy;
            out->iz = f.pts[i].iz;
            found = true;
        }
    }
    return found;
}
} // namespace fn_001fe380


// 0x001fe8d0 Method1<CTriggerVolumeManager,math::Vector,const_char_*>::vfunc_0 (30 B): matches/0x001fe8d0.cpp
// sym: ?vfunc_0@Vector_const_char_1fe8d0@fn_001fe8d0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CTriggerVolumeManager,math::Vector, const char
// *>::~Method1() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature,
// as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001fe8d0 {
struct Vector_const_char_1fe8d0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Vector_const_char_1fe8d0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fe8d0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001fe8f0 Method1<CTriggerVolumeManager,math::Vector,const_char_*>::vfunc_2 (69 B): equivalent/0x001fe8f0.cpp
// sym: ?vfunc_2@Method1_1fe8f0@fn_001fe8f0@@QAEXPAX00@Z @a8a827e1a186 @we320285f6b9d @v0cba1b514b75
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method1<CTriggerVolumeManager,math::Vector,const_char_*>::vfunc_2 @ 0x001fe8f0
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CTriggerVolumeManager,math::Vector, const char *>::vfunc_2`.
namespace fn_001fe8f0 {
struct Method1_1fe8f0 : hulk_script::FunctionGenView {
    math::Vector (::CTriggerVolumeManager::*f_1c)(const char *);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_1fe8f0::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1fe8f0 * manager = (CTriggerVolumeManager_1fe8f0 *)__p0; const char ** text = (const char **)__p1; math::Vector_1fe8f0 * result = (math::Vector_1fe8f0 *)__p2;

 math::Vector_1fe8f0 temp;
 math::Vector_1fe8f0* source = (manager->*(*(math::Vector_1fe8f0 *(CTriggerVolumeManager_1fe8f0::**)(math::Vector_1fe8f0 *, const char *))&this->f_1c))(&temp, *text);
 temp = *source;
 if(result) *result = temp;
}
} // namespace fn_001fe8f0


// 0x001fe980 Method1<CTriggerVolumeManager,float,const_char_*>::vfunc_0 (30 B): matches/0x001fe980.cpp
// sym: ?vfunc_0@Method1_1fe980@fn_001fe980@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CTriggerVolumeManager, float, const char *>::~Method1() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001fe980 {
struct Method1_1fe980 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1fe980::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fe980
// (x64t21) the destructor itself, which other objects' code references:


// 0x001fe9a0 Method1<CTriggerVolumeManager,float,const_char_*>::vfunc_2 (42 B): matches/0x001fe9a0.cpp
// sym: ?vfunc_2@Method1_1fe9a0@fn_001fe9a0@@QAEXPAX00@Z
// Same code shape as 0x0002c760 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CTriggerVolumeManager, float, const char *>::vfunc_2`.
namespace fn_001fe9a0 {
struct Method1_1fe9a0 : hulk_script::FunctionGenView {
    float (::CTriggerVolumeManager::*f_1c)(const char *);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_1fe9a0::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1fe9a0 * a = (CActorManager_1fe9a0 *)__p0; const char ** p = (const char **)__p1; float * out = (float *)__p2;

    Fn_1fe9a0 f = (*(Fn_1fe9a0 *)&this->f_1c);
    const char* s = *p;
    float x = (a->*f)(s);
    if (out)
        *out = x;
}
} // namespace fn_001fe9a0


// 0x001fea20 Method2<CTriggerVolumeManager,bool,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x001fea20.cpp
// sym: ?vfunc_0@Vector_1fea20@fn_001fea20@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CTriggerVolumeManager, bool, const char
// *,math::Vector>::~Method2() {}` stood for it, which natively defines no function for the vftable slot (with the
// `??_G` signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001fea20 {
struct Vector_1fea20 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Vector_1fea20::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fea20
// (x64t21) the destructor itself, which other objects' code references:


// 0x001fea40 Method2<CTriggerVolumeManager,bool,const_char_*,math::Vector>::vfunc_2 (58 B): equivalent/0x001fea40.cpp
// sym: ?vfunc_2@Method2_1fea40@fn_001fea40@@QAEXPAX00@Z @5070c124e04e @w8cf067245f4c @v78f384363325
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Method2<CTriggerVolumeManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x001fea40
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method2<CTriggerVolumeManager, bool, const char *,math::Vector>::vfunc_2`.
namespace fn_001fea40 {
struct Method2_1fea40 : hulk_script::FunctionGenView {
    bool (::CTriggerVolumeManager::*f_1c)(const char *, math::Vector);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method2_1fea40::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1fea40 * manager = (CTriggerVolumeManager_1fea40 *)__p0; Parameters * params = (Parameters *)__p1; bool * result = (bool *)__p2;

 bool value = (manager->*(*(bool (CTriggerVolumeManager_1fea40::**)(const char *, Vector_1fea40))&this->f_1c))(params->name, params->position);
 if (result) *result = value;
}
} // namespace fn_001fea40


// 0x001fead0 Method2<CTriggerVolumeManager,bool,const_char_*,float>::vfunc_0 (30 B): matches/0x001fead0.cpp
// sym: ?vfunc_0@Method2_1fead0@fn_001fead0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CTriggerVolumeManager, bool, const char *,
// float>::~Method2() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001fead0 {
struct Method2_1fead0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1fead0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fead0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001feaf0 Method2<CTriggerVolumeManager,bool,const_char_*,float>::vfunc_2 (37 B): matches/0x001feaf0.cpp
// sym: ?vfunc_2@Method2_1feaf0@fn_001feaf0@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method2<CTriggerVolumeManager, bool, const char *, float>::vfunc_2`.
namespace fn_001feaf0 {
struct Method2_1feaf0 : hulk_script::FunctionGenView {
    bool (::CTriggerVolumeManager::*f_1c)(const char *, float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method2_1feaf0::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1feaf0 * o = (CTriggerVolumeManager_1feaf0 *)__p0; Args * p = (Args *)__p1; bool * out = (bool *)__p2;

    bool (CTriggerVolumeManager_1feaf0::*f)(const char*, float) = (*(bool (CTriggerVolumeManager_1feaf0::**)(const char *, float))&this->f_1c);
    const char* s = p->s;
    float x = p->f;
    bool v = (o->*f)(s, x);
    if (out)
        *out = v;
}
} // namespace fn_001feaf0


// 0x001feb60 Method1<CTriggerVolumeManager,bool,const_char_*>::vfunc_0 (30 B): matches/0x001feb60.cpp
// sym: ?vfunc_0@Method1_1feb60@fn_001feb60@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CTriggerVolumeManager, bool, const char *>::~Method1() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001feb60 {
struct Method1_1feb60 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1feb60::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001feb60
// (x64t21) the destructor itself, which other objects' code references:


// 0x001feb80 Method1<CTriggerVolumeManager,bool,const_char_*>::vfunc_2 (29 B): matches/0x001feb80.cpp
// sym: ?vfunc_2@Method1_1feb80@fn_001feb80@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CTriggerVolumeManager, bool, const char *>::vfunc_2`.
namespace fn_001feb80 {
struct Method1_1feb80 : hulk_script::FunctionGenView {
    bool (::CTriggerVolumeManager::*f_1c)(const char *);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_1feb80::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1feb80 * obj = (CTriggerVolumeManager_1feb80 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CTriggerVolumeManager_1feb80::*f)(const char*) = (*(bool (CTriggerVolumeManager_1feb80::**)(const char *))&this->f_1c);
    const char* s = *arg;
    bool r = (obj->*f)(s);
    if (out)
        *out = r;
}
} // namespace fn_001feb80


// 0x001febe0 Method0<CTriggerVolumeManager,int>::vfunc_0 (30 B): matches/0x001febe0.cpp
// sym: ?vfunc_0@Method0_1febe0@fn_001febe0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CTriggerVolumeManager, int>::~Method0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001febe0 {
struct Method0_1febe0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_1febe0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001febe0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001fec00 Method0<CTriggerVolumeManager,int>::vfunc_2 (22 B): matches/0x001fec00.cpp
// sym: ?vfunc_2@Method0_1fec00@fn_001fec00@@QAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method0<CTriggerVolumeManager, int>::vfunc_2`.
namespace fn_001fec00 {
struct Method0_1fec00 : hulk_script::FunctionGenView {
    int (::CTriggerVolumeManager::*f_1c)();
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method0_1fec00::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)&this->f_1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
} // namespace fn_001fec00


// 0x001fec60 Method1<CTriggerVolumeManager,const_char_*,int>::vfunc_0 (30 B): matches/0x001fec60.cpp
// sym: ?vfunc_0@Method1_1fec60@fn_001fec60@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method1<CTriggerVolumeManager, const char *,
// int>::~Method1() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_001fec60 {
struct Method1_1fec60 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1fec60::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fec60


// 0x001fec80 Method1<CTriggerVolumeManager,const_char_*,int>::vfunc_2 (29 B): matches/0x001fec80.cpp
// sym: ?vfunc_2@Method1_1fec80@fn_001fec80@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CTriggerVolumeManager, const char *, int>::vfunc_2`.
namespace fn_001fec80 {
struct Method1_1fec80 : hulk_script::FunctionGenView {
    const char * (::CTriggerVolumeManager::*f_1c)(int);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_1fec80::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1fec80 * obj = (CTriggerVolumeManager_1fec80 *)__p0; const char ** args = (const char **)__p1; int * result = (int *)__p2;

    CTriggerVolumeManager_1fec80::Method fn = (*(CTriggerVolumeManager_1fec80::Method *)&this->f_1c);
    int r = obj->Do(fn, *args);
    if (result)
        *result = r;
}
} // namespace fn_001fec80

namespace fn_f3d6a774 {

// 0x001feca0 FUN_001feca0 (102 B): matches/0x001feca0.cpp
// sym: ?FUN_001feca0@Method4_1feca0@fn_f3d6a774@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
// FUN_001feca0 @ 0x001feca0
Method4_1feca0* Method4_1feca0::FUN_001feca0(const char* name, ScriptMemberFn fp) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (hulk_intptr)DAT_004252e4;
    fn = fp;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e0e4));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(DAT_0048e10c);
    f.argTypes[2] = FUN_001d04d0(DAT_0048e10c);
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e128));
    return this;
}

} // namespace fn_f3d6a774

// 0x001fed10 Method4<CTriggerVolumeManager,bool,const_char_*,math::Vector,math::Vector,float>::vfunc_0 (30 B): matches/0x001fed10.cpp
// sym: ?vfunc_0@Vector_float_1fed10@fn_001fed10@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method4<CTriggerVolumeManager, bool, const char
// *,math::Vector,math::Vector, float>::~Method4() {}` stood for it, which natively defines no function for the vftable
// slot (with the `??_G` signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1)
// operator delete.
namespace fn_001fed10 {
struct Vector_float_1fed10 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Vector_float_1fed10::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fed10
// (x64t21) the destructor itself, which other objects' code references:


// 0x001fed30 Method4<CTriggerVolumeManager,bool,const_char_*,math::Vector,math::Vector,float>::vfunc_2 (110 B): equivalent/0x001fed30.cpp
// sym: ?vfunc_2@Method4_1fed30@fn_001fed30@@QAEXPAX00@Z @0fd9e26ce8ae @w351da021458c @v818e6b5ebb4f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method4<CTriggerVolumeManager,bool,const_char_*,math::Vector,math::Vector,float>::vfunc_2 @ 0x001fed30
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method4<CTriggerVolumeManager, bool, const char *,math::Vector,math::Vector, float>::vfunc_2`.
namespace fn_001fed30 {
struct Method4_1fed30 : hulk_script::FunctionGenView {
    bool (::CTriggerVolumeManager::*f_1c)(const char *, math::Vector, math::Vector, float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method4_1fed30::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1fed30 * obj = (CTriggerVolumeManager_1fed30 *)__p0; Args_1fed30 * args = (Args_1fed30 *)__p1; bool * out = (bool *)__p2;

    CheckFn_1fed30 fn = (*(CheckFn_1fed30 *)&this->f_1c);
    bool r = (obj->*fn)(args->name, args->from, args->to, args->radius);
    if (out)
        *out = r;
}
} // namespace fn_001fed30


// 0x001fedf0 Method2<CTriggerVolumeManager,void,const_char_*,bool>::vfunc_0 (30 B): matches/0x001fedf0.cpp
// sym: ?vfunc_0@Method2_1fedf0@fn_001fedf0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method2<CTriggerVolumeManager, void, const char *,
// bool>::~Method2() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_001fedf0 {
struct Method2_1fedf0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1fedf0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fedf0


// 0x001fee10 Method2<CTriggerVolumeManager,void,const_char_*,bool>::vfunc_2 (25 B): matches/0x001fee10.cpp [wrapped: conflict: Args; CTriggerVolumeManager; Function; Method2]
// sym: ?v2@Method2@fn_001fee10@@QAEXPAVCTriggerVolumeManager@2@PAUArgs@2@PAX@Z
namespace fn_001fee10 {
class CTriggerVolumeManager {
  public:
    void Action(const char*, bool);
};
struct Args {
    const char* s;
    bool b;
};
class Function { void* vftable;   /* (script2) the vftable word, no stand-in vftable */
  public:
    void v0();
    void v1();
    void v2();
};
class Method2 : public Function {
  public:
    ScriptFunctionFields fields;   // (script2) Function's fields (was char pad[24])
    void (CTriggerVolumeManager::*method)(const char*, bool);
    void v2(CTriggerVolumeManager*, Args*, void*);
};
void Method2::v2(CTriggerVolumeManager* obj, Args* a, void*) {
    (obj->*method)(a->s, a->b);
}
} // namespace fn_001fee10


// 0x001fee70 Method1<CTriggerVolumeManager,void,const_char_*>::vfunc_0 (30 B): matches/0x001fee70.cpp
// sym: ?vfunc_0@Method1_1fee70@fn_001fee70@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CTriggerVolumeManager, void, const char *>::~Method1() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001fee70 {
struct Method1_1fee70 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1fee70::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fee70
// (x64t21) the destructor itself, which other objects' code references:


// 0x001fee90 Method1<CTriggerVolumeManager,void,const_char_*>::vfunc_2 (19 B): matches/0x001fee90.cpp
// sym: ?vfunc_2@Method1_1fee90@fn_001fee90@@QAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CTriggerVolumeManager, void, const char *>::vfunc_2`.
namespace fn_001fee90 {
struct Method1_1fee90 : hulk_script::FunctionGenView {
    void (::CTriggerVolumeManager::*f_1c)(const char *);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_1fee90::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1fee90* d = (Dummy_1fee90*)a;
    (d->*(*(void (Dummy_1fee90::**)(void *))&this->f_1c))(*b);
}
} // namespace fn_001fee90


// 0x001fef00 Method2<CTriggerVolumeManager,bool,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001fef00.cpp
// sym: ?vfunc_0@Method2_1fef00@fn_001fef00@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method2<CTriggerVolumeManager, bool, const char *,
// const char *>::~Method2() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body
// 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001fef00 {
struct Method2_1fef00 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1fef00::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fef00


// 0x001fef20 Method2<CTriggerVolumeManager,bool,const_char_*,const_char_*>::vfunc_2 (33 B): matches/0x001fef20.cpp [wrapped: conflict: CTriggerVolumeManager; Function; Method2; Pair]
// sym: ?vfunc_2@Method2@fn_001fef20@@QAEXPAVCTriggerVolumeManager@2@PAUPair@2@PA_N@Z
namespace fn_001fef20 {
class CTriggerVolumeManager {
  public:
    bool run(const char*, const char*);
};
struct Pair {
    const char* a;
    const char* b;
};
class Function { void* vftable;   /* (script2) the vftable word, no stand-in vftable */
  public:
    void v0();
    void v1();
};
class Method2 : public Function {
  public:
    void v0();
    void v1();
    void vfunc_2(CTriggerVolumeManager*, Pair*, bool*);
    ScriptFunctionFields fields;   // (script2) Function's fields (was char pad[24])
    bool (CTriggerVolumeManager::*fn)(const char*, const char*);
};
void Method2::vfunc_2(CTriggerVolumeManager* obj, Pair* p, bool* out) {
    bool (CTriggerVolumeManager::*f)(const char*, const char*) = fn;
    const char* a = p->a;
    const char* b = p->b;
    bool r = (obj->*f)(a, b);
    if (out)
        *out = r;
}
} // namespace fn_001fef20


// 0x001fefa0 Method2<CTriggerVolumeManager,void,const_char_*,float>::vfunc_0 (30 B): matches/0x001fefa0.cpp
// sym: ?vfunc_0@Method2_1fefa0@fn_001fefa0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method2<CTriggerVolumeManager, void, const char *,
// float>::~Method2() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_001fefa0 {
struct Method2_1fefa0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1fefa0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fefa0


// 0x001fefc0 Method2<CTriggerVolumeManager,void,const_char_*,float>::vfunc_2 (23 B): matches/0x001fefc0.cpp
// sym: ?vfunc_2@Method2_1fefc0@fn_001fefc0@@QAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method2<CTriggerVolumeManager, void, const char *, float>::vfunc_2`.
namespace fn_001fefc0 {
struct Method2_1fefc0 : hulk_script::FunctionGenView {
    void (::CTriggerVolumeManager::*f_1c)(const char *, float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method2_1fefc0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1fefc0* m = (CFEManager_1fefc0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + sizeof(void*));   // (script2, stop 6) the second argument follows a pointer cell
    (m->*(*(void (CFEManager_1fefc0::**)(const char *, int))&this->f_1c))(s, x);
}
} // namespace fn_001fefc0

namespace fn_f3d6a774 {

// 0x001fefe0 FUN_001fefe0 (89 B): matches/0x001fefe0.cpp
// sym: ?Build@Method3_1fefe0@fn_f3d6a774@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
Method3_1fefe0* Method3_1fefe0::Build(const char* arg1, ScriptMemberFn arg2) {
    Init_001d0480(arg1, 3);
    vftable = ((hulk_intptr)DAT_00425334);
    p1c = arg2;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    return this;
}

} // namespace fn_f3d6a774

// 0x001ff040 Method3<CTriggerVolumeManager,bool,math::Vector,const_char_*,bool>::vfunc_0 (30 B): matches/0x001ff040.cpp
// sym: ?vfunc_0@Vector_const_char_bool_1ff040@fn_001ff040@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method3<CTriggerVolumeManager, bool,math::Vector, const char *,
// bool>::~Method3() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ff040 {
struct Vector_const_char_bool_1ff040 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Vector_const_char_bool_1ff040::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ff040
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ff060 Method3<CTriggerVolumeManager,bool,math::Vector,const_char_*,bool>::vfunc_2 (65 B): matches/0x001ff060.cpp
// sym: ?vfunc_2@Method3_1ff060@fn_001ff060@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method3<CTriggerVolumeManager, bool,math::Vector, const char *, bool>::vfunc_2`.
namespace fn_001ff060 {
struct Method3_1ff060 : hulk_script::FunctionGenView {
    bool (::CTriggerVolumeManager::*f_1c)(math::Vector, const char *, bool);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method3_1ff060::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1ff060 * obj = (CTriggerVolumeManager_1ff060 *)__p0; Params_1ff060 * p = (Params_1ff060 *)__p1; bool * result = (bool *)__p2;

    Fn fn = (*(Fn *)&this->f_1c);
    const char* name = p->name;
    bool flag = p->flag;
    bool r = (obj->*fn)(p->v, name, flag);
    if (result)
        *result = r;
}
} // namespace fn_001ff060


// 0x001ff100 Method2<CTriggerVolumeManager,bool,const_char_*,bool>::vfunc_0 (30 B): matches/0x001ff100.cpp
// sym: ?vfunc_0@Method2_1ff100@fn_001ff100@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CTriggerVolumeManager, bool, const char *,
// bool>::~Method2() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ff100 {
struct Method2_1ff100 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1ff100::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ff100
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ff120 Method2<CTriggerVolumeManager,bool,const_char_*,bool>::vfunc_2 (41 B): matches/0x001ff120.cpp
// sym: ?vfunc_2@Method2_1ff120@fn_001ff120@@QAEXPAX00@Z
// Same code shape as 0x0002c510 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method2<CTriggerVolumeManager, bool, const char *, bool>::vfunc_2`.
namespace fn_001ff120 {
struct Method2_1ff120 : hulk_script::FunctionGenView {
    bool (::CTriggerVolumeManager::*f_1c)(const char *, bool);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method2_1ff120::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1ff120 * obj = (CActorManager_1ff120 *)__p0; Pair_1ff120 * p = (Pair_1ff120 *)__p1; bool * out = (bool *)__p2;

    bool (CActorManager_1ff120::*fn)(const char*, bool) = (*(bool (CActorManager_1ff120::**)(const char *, bool))&this->f_1c);
    const char* s = p->p;
    bool b = p->b;
    bool r = (obj->*fn)(s, b);
    if (out)
        *out = r;
}
} // namespace fn_001ff120

namespace fn_f3d6a774 {

// 0x001ff150 FUN_001ff150 (102 B): matches/0x001ff150.cpp
// sym: ??0Method4@fn_001ff150@fn_f3d6a774@@QAE@PBDP8Owner_1ff150@12@AEXXZ@Z
namespace fn_001ff150 {
// (script1) Method4<class CTriggerVolumeManager,bool,const char *,int,int,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_00425354[];   // Method4<class CTriggerVolumeManager,bool,const char *,int,int,bool>
class Owner_1ff150 {};
typedef void (Owner_1ff150::*Fn_1ff150)();
struct Method4 : hulk_script::ScriptFunction {
    Fn_1ff150 fn;
    Method4(const char* name, Fn_1ff150 function);
};
Method4::Method4(const char* name, Fn_1ff150 function) : hulk_script::ScriptFunction(name, 4) {
    vftable = DAT_00425354;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[3] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
}
} // namespace fn_001ff150

} // namespace fn_f3d6a774

// 0x001ff1c0 Method4<CTriggerVolumeManager,bool,const_char_*,int,int,bool>::vfunc_0 (30 B): matches/0x001ff1c0.cpp
// sym: ?vfunc_0@Method4_1ff1c0@fn_001ff1c0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method4<CTriggerVolumeManager, bool, const char *, int, int,
// bool>::~Method4() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ff1c0 {
struct Method4_1ff1c0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method4_1ff1c0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ff1c0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ff1e0 Method4<CTriggerVolumeManager,bool,const_char_*,int,int,bool>::vfunc_2 (30 B): matches/0x001ff1e0.cpp
// sym: ?vfunc_2@Method4_1ff1e0@fn_001ff1e0@@QAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method4<CTriggerVolumeManager, bool, const char *, int, int, bool>::vfunc_2`.
namespace fn_001ff1e0 {
struct Method4_1ff1e0 : hulk_script::FunctionGenView {
    bool (::CTriggerVolumeManager::*f_1c)(const char *, int, int, bool);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method4_1ff1e0::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001ff200(a, b, c, (*(int *)&this->f_1c));
}
} // namespace fn_001ff1e0

namespace fn_f3d6a774 {

// 0x001ff200 FUN_001ff200 (54 B): matches/0x001ff200.cpp
// sym: ?f@fn_f3d6a774@@YAXPAVCTriggerVolumeManager_1ff200@1@PAHPAEP821@AEEHHHH@Z@Z
void f(CTriggerVolumeManager_1ff200* obj, int* args, unsigned char* out, CTriggerVolumeManager_1ff200::Fn fn) {
    int* p = args;
    int a = *p++;
    int b = *p;
    int c = *++p;
    *(unsigned char*)&args = *(unsigned char*)(p + 1);
    unsigned char v = (obj->*fn)(a, b, c, (hulk_intptr)args);
    if (out)
        *out = v;
}

} // namespace fn_f3d6a774

// 0x001ff280 Method1<CTriggerVolumeManager,int,const_char_*>::vfunc_0 (30 B): matches/0x001ff280.cpp
// sym: ?vfunc_0@Method1_1ff280@fn_001ff280@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CTriggerVolumeManager, int, const char *>::~Method1() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ff280 {
struct Method1_1ff280 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1ff280::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ff280
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ff2a0 Method1<CTriggerVolumeManager,int,const_char_*>::vfunc_2 (29 B): matches/0x001ff2a0.cpp
// sym: ?vfunc_2@Method1_1ff2a0@fn_001ff2a0@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CTriggerVolumeManager, int, const char *>::vfunc_2`.
namespace fn_001ff2a0 {
struct Method1_1ff2a0 : hulk_script::FunctionGenView {
    int (::CTriggerVolumeManager::*f_1c)(const char *);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_1ff2a0::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1ff2a0 * obj = (CTriggerVolumeManager_1ff2a0 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (CTriggerVolumeManager_1ff2a0::*f)(const char*) = (*(int (CTriggerVolumeManager_1ff2a0::**)(const char *))&this->f_1c);
    const char* s = *arg;
    int r = (obj->*f)(s);
    if (out)
        *out = r;
}
} // namespace fn_001ff2a0

namespace fn_f3d6a774 {

// 0x001ff2c0 FUN_001ff2c0 (89 B): matches/0x001ff2c0.cpp
// sym: ??0Method3@fn_001ff2c0@fn_f3d6a774@@QAE@PBDP8Owner_1ff2c0@12@AEXXZ@Z
namespace fn_001ff2c0 {
// (script1) Method3<class CTriggerVolumeManager,void,const char *,int,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_00425374[];   // Method3<class CTriggerVolumeManager,void,const char *,int,bool>
class Owner_1ff2c0 {};
typedef void (Owner_1ff2c0::*Fn_1ff2c0)();
struct Method3 : hulk_script::ScriptFunction {
    Fn_1ff2c0 fn;
    Method3(const char* name, Fn_1ff2c0 function);
};
Method3::Method3(const char* name, Fn_1ff2c0 function) : hulk_script::ScriptFunction(name, 3) {
    vftable = DAT_00425374;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
}
} // namespace fn_001ff2c0

} // namespace fn_f3d6a774

// 0x001ff320 Method3<CTriggerVolumeManager,void,const_char_*,int,bool>::vfunc_0 (30 B): matches/0x001ff320.cpp
// sym: ?vfunc_0@Method3_1ff320@fn_001ff320@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method3<CTriggerVolumeManager, void, const char *, int,
// bool>::~Method3() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ff320 {
struct Method3_1ff320 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method3_1ff320::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ff320
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ff340 Method3<CTriggerVolumeManager,void,const_char_*,int,bool>::vfunc_2 (31 B): equivalent/0x001ff340.cpp
// sym: ?vfunc_2@Method3_1ff340@fn_001ff340@@QAEXPAX00@Z @086ee6cd29ba @wf4247e7733f6 @v74f60cd51399
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CTriggerVolumeManager,void,const_char_*,int,bool>::vfunc_2 @ 0x001ff340
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method3<CTriggerVolumeManager, void, const char *, int, bool>::vfunc_2`.
namespace fn_001ff340 {
struct Method3_1ff340 : hulk_script::FunctionGenView {
    void (::CTriggerVolumeManager::*f_1c)(const char *, int, bool);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method3_1ff340::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1ff340 * manager = (CTriggerVolumeManager_1ff340 *)__p0; TriggerArguments * args = (TriggerArguments *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CTriggerVolumeManager_1ff340::**)(const char *, int, bool))&this->f_1c))(args->name, args->value, args->enabled);
}
} // namespace fn_001ff340

namespace fn_f3d6a774 {

// 0x001ff360 FUN_001ff360 (115 B): matches/0x001ff360.cpp
// sym: ??0Method5@fn_001ff360@fn_f3d6a774@@QAE@PBDP8Owner_1ff360@12@AEXXZ@Z
namespace fn_001ff360 {
// (script1) Method5<class CTriggerVolumeManager,const char *,const class math::Vector,int,int,float,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_00425384[];   // Method5<class CTriggerVolumeManager,const char *,const class math::Vector,int,int,float,float>
class Owner_1ff360 {};
typedef void (Owner_1ff360::*Fn_1ff360)();
struct Method5 : hulk_script::ScriptFunction {
    Fn_1ff360 fn;
    Method5(const char* name, Fn_1ff360 function);
};
Method5::Method5(const char* name, Fn_1ff360 function) : hulk_script::ScriptFunction(name, 5) {
    vftable = DAT_00425384;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e10c);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[3] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[4] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
}
} // namespace fn_001ff360

} // namespace fn_f3d6a774

// 0x001ff3e0 Method5<CTriggerVolumeManager,const_char_*,const_math::Vector,int,int,float,float>::vfunc_0 (30 B): matches/0x001ff3e0.cpp
// sym: ?vfunc_0@Vector_int_int_float_float_1ff3e0@fn_001ff3e0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method5<CTriggerVolumeManager, const char *, const ::math::Vector,
// int, int, float, float>::~Method5() {}` stood for it, which natively defines no function for the vftable slot (with
// the `??_G` signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator
// delete.
namespace fn_001ff3e0 {
struct Vector_int_int_float_float_1ff3e0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Vector_int_int_float_float_1ff3e0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ff3e0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ff400 Method5<CTriggerVolumeManager,const_char_*,const_math::Vector,int,int,float,float>::vfunc_2 (30 B): matches/0x001ff400.cpp
// sym: ?vfunc_2@Method5_1ff400@fn_001ff400@@QAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method5<CTriggerVolumeManager, const char *, const ::math::Vector, int, int, float, float>::vfunc_2`.
namespace fn_001ff400 {
struct Method5_1ff400 : hulk_script::FunctionGenView {
    const char * (::CTriggerVolumeManager::*f_1c)(const ::math::Vector, int, int, float, float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method5_1ff400::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001ff420(a, b, c, (*(int *)&this->f_1c));
}
} // namespace fn_001ff400

namespace fn_f3d6a774 {

// 0x001ff420 FUN_001ff420 (90 B): equivalent/0x001ff420.cpp
// sym: ?target@fn_f3d6a774@@YAXPAUReceiver@1@PBHPAHP821@AEHUTriple@1@HHHH@Z@Z @e4eae9032a61 @w678b92123535 @v9fef5291dfd3
// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 2/2)
// FUN_001ff420 @ 0x001ff420
void __cdecl target(Receiver* receiver, const int* values, int* result, int (Receiver::*callback)(Triple,int,int,int,int)) {
    Triple v;
    v.a=values[0]; v.b=values[1]; v.c=values[2];
    int returned=(receiver->*callback)(v,values[3],values[4],values[5],values[6]);
    if (result) *result=returned;
}

} // namespace fn_f3d6a774

// 0x001ff4c0 Method1<CTriggerVolumeManager,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001ff4c0.cpp
// sym: ?vfunc_0@Method1_1ff4c0@fn_001ff4c0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method1<CTriggerVolumeManager, const char *, const
// char *>::~Method1() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0,
// then (flags & 1) operator delete.
namespace fn_001ff4c0 {
struct Method1_1ff4c0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1ff4c0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ff4c0


// 0x001ff4e0 Method1<CTriggerVolumeManager,const_char_*,const_char_*>::vfunc_2 (29 B): matches/0x001ff4e0.cpp
// sym: ?vfunc_2@Method1_1ff4e0@fn_001ff4e0@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CTriggerVolumeManager, const char *, const char *>::vfunc_2`.
namespace fn_001ff4e0 {
struct Method1_1ff4e0 : hulk_script::FunctionGenView {
    const char * (::CTriggerVolumeManager::*f_1c)(const char *);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_1ff4e0::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1ff4e0 * obj = (CTriggerVolumeManager_1ff4e0 *)__p0; const char ** arg = (const char **)__p1; void ** out = (void **)__p2;

    void* (CTriggerVolumeManager_1ff4e0::*fn)(const char*) = (*(void *(CTriggerVolumeManager_1ff4e0::**)(const char *))&this->f_1c);
    void* result = obj->Invoke(fn, *arg);
    if (out)
        *out = result;
}
} // namespace fn_001ff4e0


// 0x001ff540 Method1<CTriggerVolumeManager,void,float>::vfunc_0 (30 B): matches/0x001ff540.cpp
// sym: ?vfunc_0@Method1_1ff540@fn_001ff540@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CTriggerVolumeManager, void, float>::~Method1() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ff540 {
struct Method1_1ff540 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1ff540::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ff540
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ff560 Method1<CTriggerVolumeManager,void,float>::vfunc_2 (19 B): matches/0x001ff560.cpp
// sym: ?vfunc_2@Method1_1ff560@fn_001ff560@@QAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CTriggerVolumeManager, void, float>::vfunc_2`.
namespace fn_001ff560 {
struct Method1_1ff560 : hulk_script::FunctionGenView {
    void (::CTriggerVolumeManager::*f_1c)(float);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_1ff560::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1ff560* d = (Dummy_1ff560*)a;
    (d->*(*(void (Dummy_1ff560::**)(void *))&this->f_1c))(*b);
}
} // namespace fn_001ff560


// 0x001ff580 FUN_001ff580 (416 B): equivalent/0x001ff580.cpp [wrapped: conflict: CTriggerVolumeManager]
// sym: ??0CTriggerVolumeManager@fn_001ff580@@QAE@XZ @6c6402386526 @wda299ae5b1c8 @v63ca263318fd
namespace fn_001ff580 {
// STATUS: equivalent (tools/equiv.py level 3: 15 inputs, branch coverage 21/22, incomplete)
// FUN_001ff580 @ 0x001ff580

extern void* __cdecl FUN_00263ec0(unsigned);
extern "C" void* __cdecl FUN_0008d6d0(unsigned);
struct CLocator_1ff580 { char data[64]; void FUN_001fbf40(); };   // (sweep-allocsize) unidentified: a 64-byte element whose
                                                                  // constructor is CLocator's (0x24 B); its native size is unknown
struct CEncounterGenerator_1ff580 : ::CEncounterGenerator { void FUN_001fa630(); };   // (sweep-allocsize) gen's record (0xc70 B)
typedef char CEncounterGenerator_1ff580_size32[(sizeof(void*) != 4 || sizeof(CEncounterGenerator_1ff580) == 0xc70) ? 1 : -1];
struct Entry_1ff580 { unsigned count; CLocator_1ff580* volumes; };
struct CTriggerVolumeManager {
 virtual void* slot0_001ff750(char);
 unsigned untouched;
 unsigned count;
 unsigned table[128];
 unsigned active;
 CLocator_1ff580* volumes;
 Entry_1ff580* entries[6];
 int* indices;
 int selected;
 CEncounterGenerator_1ff580* groups;
 unsigned groupCount;
 CTriggerVolumeManager();
};
CTriggerVolumeManager::CTriggerVolumeManager() {
 for(int i=0;i<128;++i) table[i]=0;
 count=0;
 unsigned* allocation=(unsigned*)FUN_00263ec0(256*sizeof(CLocator_1ff580)+4);   // (allocsize1) the elements by their records, after the count word
 CLocator_1ff580* first=0;
 if(allocation) {
  first=(CLocator_1ff580*)(allocation+1); *allocation=256;
  for(int i=0;i<256;++i) first[i].FUN_001fbf40();
 }
 volumes=first;
 for(int type=0;type<6;++type) {
  entries[type]=(Entry_1ff580*)FUN_0008d6d0(20*sizeof(Entry_1ff580));   // (allocsize1) count + volumes pointer: 0xa0 on 32-bit
  for(int j=0;j<20;++j) {
   unsigned n=((unsigned*)&DAT_00425168)[type];
   unsigned* block=(unsigned*)(n ? FUN_00263ec0(n*sizeof(CLocator_1ff580)+4) : FUN_0008d6d0(4));
   CLocator_1ff580* result=0;
   if(block) {
    result=(CLocator_1ff580*)(block+1); *block=n;
    if((int)(n-1)>=0) {
     CLocator_1ff580* p=result;
     do { p->FUN_001fbf40(); ++p; } while(--n);
    }
   }
   entries[type][j].volumes=result;
   entries[type][j].count=0;
  }
 }
 indices=(int*)FUN_0008d6d0(20*sizeof(int));
 for(int k=0;k<20;++k) indices[k]=-1;
 selected=-1; active=0;
 unsigned* block=(unsigned*)FUN_00263ec0(8*sizeof(CEncounterGenerator_1ff580)+4);
 CEncounterGenerator_1ff580* result=0;
 if(block) {
  result=(CEncounterGenerator_1ff580*)(block+1); *block=8;
  for(int k=0;k<8;++k) result[k].FUN_001fa630();
 }
 groups=result; groupCount=0;
}
} // namespace fn_001ff580


// 0x001ff720 CTriggerVolumeManager::vfunc_2 (6 B): matches/0x001ff720.cpp
// sym: ?vfunc_2@CTriggerVolumeManager@@UAEHXZ
// Same code shape as 0x0004e0b0 (propagated; names are from that function)
int CTriggerVolumeManager::vfunc_2() {
    return 2;
}


// 0x001ff730 CTriggerVolumeManager::vfunc_3 (21 B): matches/0x001ff730.cpp
// sym: ?vfunc_3@CTriggerVolumeManager@@UAEPAXPAX@Z
void* CTriggerVolumeManager::vfunc_3(void* __p0) { hulk_intptr x = (hulk_intptr)__p0;

    return (void*)((char*)(x ? "Volume" : "Locator"));
}


// 0x001ff750 CTriggerVolumeManager::vfunc_0 (31 B): matches/0x001ff750.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001ff750@@UAEPAV123@E@Z
namespace fn_001ff750 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CDHGameObjectCreator_1ff750 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003feefc[];
namespace pure3d {
class NonCopyable : public CDHGameObjectCreator_1ff750 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003feefc;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001ff750


// 0x001ff770 CTriggerVolumeManager::vfunc_1 (479 B): equivalent/0x001ff770.cpp [wrapped: conflict: CTriggerVolumeManager; World]
// sym: ?v1@CTriggerVolumeManager@fn_001ff770@@UAE_NPAUElem_1ff770@2@@Z @699d7c4a370f @wbb7f438d4a2e @v373fa7ba6d65
namespace fn_001ff770 {
// STATUS: equivalent (tools/equiv.py level 3: 20046 inputs, branch coverage 38/38)
// CTriggerVolumeManager::vfunc_1 @ 0x001ff770
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
extern "C" int __cdecl strcmp(const char *a, const char *b);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl strncmp(const char *a, const char *b, unsigned n);
#endif

void *__cdecl FUN_00263ea0(unsigned int size);

struct Tag_1ff770 {
    char pad0[4];
    char name[1];
};

struct Elem_1ff770 {
    char pad0[4];
    Tag_1ff770 *tag;
    char pad8[4];
    const char *name;
    void FUN_003364c0(const char *attr, int *out);
    void FUN_00336490(const char *attr, char *out);
    const char *FUN_003365b0(const char *attr);
};

struct CTriggerVolume_1ff770 {
    virtual void v0();
    CTriggerVolume_1ff770 *FUN_001fbb30();
    void FUN_001fbd00(Elem_1ff770 *e);
    void FUN_001fc3c0(Elem_1ff770 *e);
};

struct Inner_1ff770 {
    bool FUN_001cd010();
};

struct Parent_1ff770 {
    char pad0[0x2c];
    Inner_1ff770 *inner;
};

struct Unlocks_1ff770 {
    bool FUN_00092860(int index);
};

struct Table_1ff770 {
    Unlocks_1ff770 *FUN_00086340();
};

struct World {
    void* vftable; void* parts[20];   /* (sweep2) the World's words (HulkWorld): +0x54 is CGame */
    Table_1ff770 *table;
};


struct Bucket_1ff770 {
    int count;
    char *buf;
};

class CTriggerVolumeManager {
public:
    virtual void v0();
    virtual bool v1(Elem_1ff770 *e);
    virtual void v2();
    virtual void v3();

    Parent_1ff770 *parent;
    int itemCount;
    CTriggerVolume_1ff770 *items[0x80];
    char pad20c[8];
    Bucket_1ff770 *buckets[7];        // 0x214
    int curBucket;                    // 0x230

    CTriggerVolume_1ff770 *FUN_001fc7f0(const char *name);
    int FUN_001fd390(const char *type);
    void FUN_001fd130(char *slot, int idx);
    CTriggerVolume_1ff770 *FUN_001fc8c0(int lo, int hi);
    CTriggerVolume_1ff770 *FUN_001fcf40();
};

bool CTriggerVolumeManager::v1(Elem_1ff770 *e)
{
    if (parent && parent->inner && parent->inner->FUN_001cd010())
        return true;

    const char *name = e->name;
    if (strcmp(e->tag->name, "Volume") == 0) {
        if (strncmp(name, "hint_", 5) == 0) {
            int unlockIndex;
            e->FUN_003364c0("UnlockableIndex", &unlockIndex);
            if (unlockIndex > 0) {
                if (!DAT_004dd700->table->FUN_00086340()->FUN_00092860(unlockIndex))
                    return false;
            }
        }
        CTriggerVolume_1ff770 *item = FUN_001fc7f0(name);
        if (itemCount >= 0x80)
            return false;
        if (!item) {
            void *mem = FUN_00263ea0(0xd8);
            if (mem)
                item = ((CTriggerVolume_1ff770 *)mem)->FUN_001fbb30();
            else
                item = 0;
            item->v0();
            items[itemCount] = item;
            itemCount++;
        }
        item->FUN_001fbd00(e);
        return true;
    }
    if (strcmp(e->tag->name, "Locator") == 0) {
        char streamed = 0;
        CTriggerVolume_1ff770 *item;
        e->FUN_00336490("IsStreamed", &streamed);
        if (streamed) {
            if (curBucket == -1)
                return true;
            int idx = FUN_001fd390(e->FUN_003365b0("Type"));
            if (idx == -1)
                idx = 0;
            Bucket_1ff770 *b = &buckets[idx][curBucket];
            if (b->count >= ((int*)&DAT_00425168)[idx])
                return true;
            item = (CTriggerVolume_1ff770 *)(b->buf + b->count * 64);
            b->count++;
            FUN_001fd130((char *)item, idx);
        } else {
            unsigned __int64 h = FUN_0027b020(name);
            item = FUN_001fc8c0((int)h, (int)(h >> 32));
            if (!item)
                item = FUN_001fcf40();
        }
        if (item)
            item->FUN_001fc3c0(e);
    }
    return true;
}
} // namespace fn_001ff770
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3d6a774 {

// 0x001ff950 FUN_001ff950 (69 B): matches/0x001ff950.cpp
// sym: ?FUN_001ff950@Factory@fn_f3d6a774@@QAEHUTriple@2@HHHH@Z
int Factory::FUN_001ff950(Triple a, int b, int c, int d, int e) {
    CTriggerVolumeManager* p = FUN_001fe080(a, b, c, d, e);
    if (p)
        return ((CTriggerVolumeManager_nv_1ff950*)(p))->FUN_001fba60();
    return 0;
}


// 0x001ff9a0 FUN_001ff9a0 (76 B): matches/0x001ff9a0.cpp
// sym: ??0Closure1@fn_001ff9a0@fn_f3d6a774@@QAE@PBDPAVOwner_1ff9a0@12@P8312@AEXXZ@Z
namespace fn_001ff9a0 {
// (script1) Closure1<class CTriggerVolumeManager,class math::Vector,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425274[];   // Method1<class CTriggerVolumeManager,class math::Vector,const char *>
extern "C" char DAT_004253ec[];   // Closure1<class CTriggerVolumeManager,class math::Vector,const char *>
class Owner_1ff9a0 {};
typedef void (Owner_1ff9a0::*Fn_1ff9a0)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ff9a0 fn;
    Owner_1ff9a0* owner;
    Closure1(const char* name, Owner_1ff9a0* object, Fn_1ff9a0 function);
};
Closure1::Closure1(const char* name, Owner_1ff9a0* object, Fn_1ff9a0 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00425274;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e10c);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_004253ec;
    owner = object;
}
} // namespace fn_001ff9a0

} // namespace fn_f3d6a774

// 0x001ff9f0 Closure1<CTriggerVolumeManager,math::Vector,const_char_*>::vfunc_0 (30 B): matches/0x001ff9f0.cpp
// sym: ?vfunc_0@Vector_const_char_1ff9f0@fn_001ff9f0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CTriggerVolumeManager,math::Vector, const char
// *>::~Closure1() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature,
// as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ff9f0 {
struct Vector_const_char_1ff9f0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Vector_const_char_1ff9f0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ff9f0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ffa10 Closure1<CTriggerVolumeManager,math::Vector,const_char_*>::vfunc_2 (70 B): equivalent/0x001ffa10.cpp
// sym: ?vfunc_2@Closure1_1ffa10@fn_001ffa10@@QAEXPAX00@Z @307fff147072 @wc421665ee9f8 @v687fd8e6a024
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CTriggerVolumeManager,math::Vector,const_char_*>::vfunc_2 @ 0x001ffa10
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CTriggerVolumeManager,math::Vector, const char *>::vfunc_2`.
namespace fn_001ffa10 {
struct Closure1_1ffa10 : hulk_script::FunctionGenView {
    math::Vector (::CTriggerVolumeManager::*f_1c)(const char *);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_1ffa10::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** input = (const char **)__p1; Vector_1ffa10 * result = (Vector_1ffa10 *)__p2;

    Vector_1ffa10 value = ((*(CTriggerVolumeManager_1ffa10 * *)&this->f_20)->*(*(Vector_1ffa10 (CTriggerVolumeManager_1ffa10::**)(const char *))&this->f_1c))(*input);
    if (result) *result = value;
}
} // namespace fn_001ffa10


// 0x001ffa60 FUN_001ffa60 (76 B): matches/0x001ffa60.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ffa60@@QAE@PBDPAVOwner_1ffa60@1@P821@AEXXZ@Z
namespace fn_001ffa60 {
// (script1) Closure1<class CTriggerVolumeManager,float,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425284[];   // Method1<class CTriggerVolumeManager,float,const char *>
extern "C" char DAT_004253fc[];   // Closure1<class CTriggerVolumeManager,float,const char *>
class Owner_1ffa60 {};
typedef void (Owner_1ffa60::*Fn_1ffa60)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ffa60 fn;
    Owner_1ffa60* owner;
    Closure1(const char* name, Owner_1ffa60* object, Fn_1ffa60 function);
};
Closure1::Closure1(const char* name, Owner_1ffa60* object, Fn_1ffa60 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00425284;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_004253fc;
    owner = object;
}
} // namespace fn_001ffa60


// 0x001ffab0 Closure1<CTriggerVolumeManager,float,const_char_*>::vfunc_0 (30 B): matches/0x001ffab0.cpp
// sym: ?vfunc_0@Closure1_1ffab0@fn_001ffab0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CTriggerVolumeManager, float, const char *>::~Closure1()
// {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views
// call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ffab0 {
struct Closure1_1ffab0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1ffab0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ffab0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ffad0 Closure1<CTriggerVolumeManager,float,const_char_*>::vfunc_2 (43 B): matches/0x001ffad0.cpp
// sym: ?vfunc_2@Closure1_1ffad0@fn_001ffad0@@QAEXPAX00@Z
// Same code shape as 0x0002e800 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CTriggerVolumeManager, float, const char *>::vfunc_2`.
namespace fn_001ffad0 {
struct Closure1_1ffad0 : hulk_script::FunctionGenView {
    float (::CTriggerVolumeManager::*f_1c)(const char *);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_1ffad0::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr ignored = (hulk_intptr)__p0; const char ** arg = (const char **)__p1; float * out = (float *)__p2;

    CActorManager_1ffad0* obj = (*(CActorManager_1ffad0 * *)&this->f_20);
    Fn_1ffad0 fn = (*(Fn_1ffad0 *)&this->f_1c);
    float value = (obj->*fn)(*arg);
    if (out)
        *out = value;
}
} // namespace fn_001ffad0


// 0x001ffb00 FUN_001ffb00 (89 B): matches/0x001ffb00.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ffb00@@QAE@PBDPAVOwner_1ffb00@1@P821@AEXXZ@Z
namespace fn_001ffb00 {
// (script1) Closure2<class CTriggerVolumeManager,bool,const char *,class math::Vector>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425294[];   // Method2<class CTriggerVolumeManager,bool,const char *,class math::Vector>
extern "C" char DAT_0042540c[];   // Closure2<class CTriggerVolumeManager,bool,const char *,class math::Vector>
class Owner_1ffb00 {};
typedef void (Owner_1ffb00::*Fn_1ffb00)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_1ffb00 fn;
    Owner_1ffb00* owner;
    Closure2(const char* name, Owner_1ffb00* object, Fn_1ffb00 function);
};
Closure2::Closure2(const char* name, Owner_1ffb00* object, Fn_1ffb00 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00425294;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e10c);
    vftable = DAT_0042540c;
    owner = object;
}
} // namespace fn_001ffb00


// 0x001ffb60 Closure2<CTriggerVolumeManager,bool,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x001ffb60.cpp
// sym: ?vfunc_0@Vector_1ffb60@fn_001ffb60@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CTriggerVolumeManager, bool, const char
// *,math::Vector>::~Closure2() {}` stood for it, which natively defines no function for the vftable slot (with the
// `??_G` signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ffb60 {
struct Vector_1ffb60 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Vector_1ffb60::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ffb60
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ffb80 Closure2<CTriggerVolumeManager,bool,const_char_*,math::Vector>::vfunc_2 (61 B): equivalent/0x001ffb80.cpp
// sym: ?vfunc_2@Closure2_1ffb80@fn_001ffb80@@QAEXPAX00@Z @eaabcb9b97d0 @w3e55d6888abb @v6a39d842839e
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CTriggerVolumeManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x001ffb80
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure2<CTriggerVolumeManager, bool, const char *,math::Vector>::vfunc_2`.
namespace fn_001ffb80 {
struct Closure2_1ffb80 : hulk_script::FunctionGenView {
    bool (::CTriggerVolumeManager::*f_1c)(const char *, math::Vector);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure2_1ffb80::vfunc_2(void* __p0, void* __p1, void* __p2) { const Vector_1ffb80 * value = (const Vector_1ffb80 *)__p1; bool * result = (bool *)__p2;

    bool answer = ((*(CTriggerVolumeManager_1ffb80 * *)&this->f_20)->*(*(bool (CTriggerVolumeManager_1ffb80::**)(Vector_1ffb80))&this->f_1c))(*value);
    if (result) *result = answer;
}
} // namespace fn_001ffb80


// 0x001ffbc0 FUN_001ffbc0 (89 B): matches/0x001ffbc0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ffbc0@@QAE@PBDPAVOwner_1ffbc0@1@P821@AEXXZ@Z
namespace fn_001ffbc0 {
// (script1) Closure2<class CTriggerVolumeManager,bool,const char *,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_004252a4[];   // Method2<class CTriggerVolumeManager,bool,const char *,float>
extern "C" char DAT_0042541c[];   // Closure2<class CTriggerVolumeManager,bool,const char *,float>
class Owner_1ffbc0 {};
typedef void (Owner_1ffbc0::*Fn_1ffbc0)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_1ffbc0 fn;
    Owner_1ffbc0* owner;
    Closure2(const char* name, Owner_1ffbc0* object, Fn_1ffbc0 function);
};
Closure2::Closure2(const char* name, Owner_1ffbc0* object, Fn_1ffbc0 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_004252a4;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    vftable = DAT_0042541c;
    owner = object;
}
} // namespace fn_001ffbc0


// 0x001ffc20 Closure2<CTriggerVolumeManager,bool,const_char_*,float>::vfunc_0 (30 B): matches/0x001ffc20.cpp
// sym: ?vfunc_0@Closure2_1ffc20@fn_001ffc20@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure2<CTriggerVolumeManager, bool, const char *,
// float>::~Closure2() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0,
// then (flags & 1) operator delete.
namespace fn_001ffc20 {
struct Closure2_1ffc20 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_1ffc20::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ffc20


// 0x001ffc40 Closure2<CTriggerVolumeManager,bool,const_char_*,float>::vfunc_2 (40 B): equivalent/0x001ffc40.cpp [wrapped: conflict: CTriggerVolumeManager; Closure2; Function; TriggerArguments]
// sym: ?vfunc_2@Closure2@fn_001ffc40@@QAEXPAXPBUTriggerArguments@2@PA_N@Z @e654de0dce29 @wba6b7cc7fabf @v074133740b4d
namespace fn_001ffc40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CTriggerVolumeManager,bool,const_char_*,float>::vfunc_2 @ 0x001ffc40
struct CTriggerVolumeManager {
    bool FUN_001ffc40_member(const char *, float);
};
struct TriggerArguments {
    const char *name;
    float value;
};
struct Function { void* vftable;   /* (script2) the vftable word, no stand-in vftable */
    void vfunc_0();
    void vfunc_1();
    void vfunc_2(void *, const TriggerArguments *, bool *);
};
struct Closure2 : Function {
    ScriptFunctionFields fields;   // (script2) Function's fields (was char padding[0x18])
    bool (CTriggerVolumeManager::*method)(const char *, float);
    CTriggerVolumeManager *object;
    void vfunc_2(void *unused, const TriggerArguments *arguments, bool *result);
};
void Closure2::vfunc_2(void *unused, const TriggerArguments *arguments, bool *result) {
    bool value = (object->*method)(arguments->name, arguments->value);
    if (result) *result = value;
}
} // namespace fn_001ffc40


// 0x001ffc70 FUN_001ffc70 (76 B): matches/0x001ffc70.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ffc70@@QAE@PBDPAVOwner_1ffc70@1@P821@AEXXZ@Z
namespace fn_001ffc70 {
// (script1) Closure1<class CTriggerVolumeManager,bool,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_004252b4[];   // Method1<class CTriggerVolumeManager,bool,const char *>
extern "C" char DAT_0042542c[];   // Closure1<class CTriggerVolumeManager,bool,const char *>
class Owner_1ffc70 {};
typedef void (Owner_1ffc70::*Fn_1ffc70)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ffc70 fn;
    Owner_1ffc70* owner;
    Closure1(const char* name, Owner_1ffc70* object, Fn_1ffc70 function);
};
Closure1::Closure1(const char* name, Owner_1ffc70* object, Fn_1ffc70 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_004252b4;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_0042542c;
    owner = object;
}
} // namespace fn_001ffc70
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ffcc0 Closure1<CTriggerVolumeManager,bool,const_char_*>::vfunc_0 (30 B): matches/0x001ffcc0.cpp
// sym: ?vfunc_0@Closure1_1ffcc0@fn_001ffcc0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure1<CTriggerVolumeManager, bool, const char
// *>::~Closure1() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_001ffcc0 {
struct Closure1_1ffcc0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1ffcc0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ffcc0


// 0x001ffce0 Closure1<CTriggerVolumeManager,bool,const_char_*>::vfunc_2 (30 B): matches/0x001ffce0.cpp [wrapped: conflict: Closure1]
// sym: ?V2@Closure1@fn_001ffce0@@QAEXPAXPAPBDPA_N@Z
namespace fn_001ffce0 {
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
} // namespace fn_001ffce0


// 0x001ffd00 FUN_001ffd00 (63 B): matches/0x001ffd00.cpp [wrapped: conflict: Closure0; Method0]
// sym: ??0Closure0@fn_001ffd00@@QAE@PBDPAVOwner_1ffd00@1@P821@AEXXZ@Z
namespace fn_001ffd00 {
// (script1) Closure0<class CTriggerVolumeManager,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_004252c4[];   // Method0<class CTriggerVolumeManager,int>
extern "C" char DAT_0042543c[];   // Closure0<class CTriggerVolumeManager,int>
class Owner_1ffd00 {};
typedef void (Owner_1ffd00::*Fn_1ffd00)();
struct Closure0 : hulk_script::ScriptFunction {
    Fn_1ffd00 fn;
    Owner_1ffd00* owner;
    Closure0(const char* name, Owner_1ffd00* object, Fn_1ffd00 function);
};
Closure0::Closure0(const char* name, Owner_1ffd00* object, Fn_1ffd00 function) : hulk_script::ScriptFunction(name, 0) {
    vftable = DAT_004252c4;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_0042543c;
    owner = object;
}
} // namespace fn_001ffd00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ffd40 Closure0<CTriggerVolumeManager,int>::vfunc_0 (30 B): matches/0x001ffd40.cpp
// sym: ?vfunc_0@Closure0_1ffd40@fn_001ffd40@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure0<CTriggerVolumeManager, int>::~Closure0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ffd40 {
struct Closure0_1ffd40 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure0_1ffd40::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ffd40
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ffd60 Closure0<CTriggerVolumeManager,int>::vfunc_2 (23 B): matches/0x001ffd60.cpp
// sym: ?vfunc_2@Closure0_1ffd60@fn_001ffd60@@QAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure0<CTriggerVolumeManager, int>::vfunc_2`.
namespace fn_001ffd60 {
struct Closure0_1ffd60 : hulk_script::FunctionGenView {
    int (::CTriggerVolumeManager::*f_1c)();
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure0_1ffd60::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_1ffd60* obj = (*(CActorManager_1ffd60 * *)&this->f_20);
    int (CActorManager_1ffd60::*fn)() = (*(int (CActorManager_1ffd60::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
} // namespace fn_001ffd60


// 0x001ffd80 FUN_001ffd80 (76 B): matches/0x001ffd80.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_001ffd80@@QAE@PBDPAVOwner_1ffd80@1@P821@AEXXZ@Z
namespace fn_001ffd80 {
// (script1) Closure1<class CTriggerVolumeManager,const char *,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_004252d4[];   // Method1<class CTriggerVolumeManager,const char *,int>
extern "C" char DAT_0042544c[];   // Closure1<class CTriggerVolumeManager,const char *,int>
class Owner_1ffd80 {};
typedef void (Owner_1ffd80::*Fn_1ffd80)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ffd80 fn;
    Owner_1ffd80* owner;
    Closure1(const char* name, Owner_1ffd80* object, Fn_1ffd80 function);
};
Closure1::Closure1(const char* name, Owner_1ffd80* object, Fn_1ffd80 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_004252d4;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_0042544c;
    owner = object;
}
} // namespace fn_001ffd80


// 0x001ffdd0 Closure1<CTriggerVolumeManager,const_char_*,int>::vfunc_0 (30 B): matches/0x001ffdd0.cpp
// sym: ?vfunc_0@Closure1_1ffdd0@fn_001ffdd0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure1<CTriggerVolumeManager, const char *,
// int>::~Closure1() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_001ffdd0 {
struct Closure1_1ffdd0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1ffdd0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ffdd0


// 0x001ffdf0 Closure1<CTriggerVolumeManager,const_char_*,int>::vfunc_2 (30 B): matches/0x001ffdf0.cpp [wrapped: conflict: Closure1]
// sym: ?v2@Closure1@fn_001ffdf0@@QAEHPAPAVCActorManager@2@PAPBDPAPAH@Z
namespace fn_001ffdf0 {
class CActorManager {
  public:
    int f(const char* a);
};
class Closure1 { void* vftable;   /* (script2) the vftable word, no stand-in vftable */
  public:
    void v0();
    void v1();
    int v2(CActorManager** obj, const char** arg, int** out);
    ScriptFunctionFields fields;   // (script2) Function's fields (was char pad[0x18])
    int (CActorManager::*mFn)(const char*);
    CActorManager* mObj;
};
int Closure1::v2(CActorManager** obj, const char** arg, int** out) {
    CActorManager* o = mObj;
    const char* a = *arg;
    int (CActorManager::*fn)(const char*) = mFn;
    hulk_intptr r = (o->*fn)(a);
    if (out)
        *out = (int*)r;
    return r;
}
} // namespace fn_001ffdf0


// 0x001ffe40 Closure4<CTriggerVolumeManager,bool,const_char_*,math::Vector,math::Vector,float>::vfunc_0 (30 B): matches/0x001ffe40.cpp
// sym: ?vfunc_0@Closure4_1ffe40@fn_001ffe40@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure4<CTriggerVolumeManager, bool, const char
// *,math::Vector,math::Vector, float>::~Closure4() {}` stood for it, whose MSVC `??_G` matched only under /GX. The
// destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ffe40 {
struct Closure4_1ffe40 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure4_1ffe40::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ffe40


// 0x001ffe60 Closure4<CTriggerVolumeManager,bool,const_char_*,math::Vector,math::Vector,float>::vfunc_2 (12 B): matches/0x001ffe60.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure2@fn_001ffe60@@UAEXHHH@Z
namespace fn_001ffe60 {
// Same code shape as 0x0002ff10 (propagated; names are from that function)
class CActorManager;
struct Vector {
    float x, y, z;
};
class Method2 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int, int, int);
    ScriptFunctionFields fields;   // (script2) Function's fields (was char pad[0x18])
};
class Function {
  public:
    virtual void g0();
};
class Closure2 : public Method2, public Function {
  public:
    int val;
    virtual void vfunc_2(int, int, int);
};
void Closure2::vfunc_2(int x, int a2, int a3) {
    Method2::vfunc_2(val, a2, a3);
}
} // namespace fn_001ffe60


// 0x001ffe70 FUN_001ffe70 (89 B): matches/0x001ffe70.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ffe70@@QAE@PBDPAVOwner_1ffe70@1@P821@AEXXZ@Z
namespace fn_001ffe70 {
// (script1) Closure2<class CTriggerVolumeManager,void,const char *,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_004252f4[];   // Method2<class CTriggerVolumeManager,void,const char *,bool>
extern "C" char DAT_0042546c[];   // Closure2<class CTriggerVolumeManager,void,const char *,bool>
class Owner_1ffe70 {};
typedef void (Owner_1ffe70::*Fn_1ffe70)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_1ffe70 fn;
    Owner_1ffe70* owner;
    Closure2(const char* name, Owner_1ffe70* object, Fn_1ffe70 function);
};
Closure2::Closure2(const char* name, Owner_1ffe70* object, Fn_1ffe70 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_004252f4;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    vftable = DAT_0042546c;
    owner = object;
}
} // namespace fn_001ffe70


// 0x001ffed0 Closure2<CTriggerVolumeManager,void,const_char_*,bool>::vfunc_0 (30 B): matches/0x001ffed0.cpp
// sym: ?vfunc_0@Closure2_1ffed0@fn_001ffed0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CTriggerVolumeManager, void, const char *,
// bool>::~Closure2() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ffed0 {
struct Closure2_1ffed0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_1ffed0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ffed0
// (x64t21) the destructor itself, which other objects' code references:


// 0x001ffef0 Closure2<CTriggerVolumeManager,void,const_char_*,bool>::vfunc_2 (24 B): matches/0x001ffef0.cpp
// sym: ?vfunc_2@Closure2_1ffef0@fn_001ffef0@@QAEXPAX00@Z
// Same code shape as 0x0002ec60 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure2<CTriggerVolumeManager, void, const char *, bool>::vfunc_2`.
namespace fn_001ffef0 {
struct Closure2_1ffef0 : hulk_script::FunctionGenView {
    void (::CTriggerVolumeManager::*f_1c)(const char *, bool);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure2_1ffef0::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_1ffef0 * p = (Arg_1ffef0 *)__p1;

    ((*(Actor_1ffef0 * *)&this->f_20)->*(*(void (Actor_1ffef0::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}
} // namespace fn_001ffef0


// 0x001fff10 FUN_001fff10 (76 B): matches/0x001fff10.cpp [wrapped: conflict: Closure1; Closure1::Closure1; Method1]
// sym: ??0Closure1@fn_001fff10@@QAE@PBDPAVOwner_1fff10@1@P821@AEXXZ@Z
namespace fn_001fff10 {
// (script1) Closure1<class CTriggerVolumeManager,void,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425304[];   // Method1<class CTriggerVolumeManager,void,const char *>
extern "C" char DAT_0042547c[];   // Closure1<class CTriggerVolumeManager,void,const char *>
class Owner_1fff10 {};
typedef void (Owner_1fff10::*Fn_1fff10)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1fff10 fn;
    Owner_1fff10* owner;
    Closure1(const char* name, Owner_1fff10* object, Fn_1fff10 function);
};
Closure1::Closure1(const char* name, Owner_1fff10* object, Fn_1fff10 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00425304;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_0042547c;
    owner = object;
}
} // namespace fn_001fff10
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001fff60 Closure1<CTriggerVolumeManager,void,const_char_*>::vfunc_0 (30 B): matches/0x001fff60.cpp
// sym: ?vfunc_0@Closure1_1fff60@fn_001fff60@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CTriggerVolumeManager, void, const char *>::~Closure1()
// {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views
// call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001fff60 {
struct Closure1_1fff60 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1fff60::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fff60
// (x64t21) the destructor itself, which other objects' code references:


// 0x001fff80 Closure1<CTriggerVolumeManager,void,const_char_*>::vfunc_2 (18 B): matches/0x001fff80.cpp
// sym: ?vfunc_2@Closure1_1fff80@fn_001fff80@@QAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CTriggerVolumeManager, void, const char *>::vfunc_2`.
namespace fn_001fff80 {
struct Closure1_1fff80 : hulk_script::FunctionGenView {
    void (::CTriggerVolumeManager::*f_1c)(const char *);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_1fff80::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1fff80 * *)&this->f_20)->*(*(void (CActorManager_1fff80::**)(const char *))&this->f_1c))(*b);
}
} // namespace fn_001fff80


// 0x001fffa0 FUN_001fffa0 (89 B): matches/0x001fffa0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001fffa0@@QAE@PBDPAVOwner_1fffa0@1@P821@AEXXZ@Z
namespace fn_001fffa0 {
// (script1) Closure2<class CTriggerVolumeManager,bool,const char *,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425314[];   // Method2<class CTriggerVolumeManager,bool,const char *,const char *>
extern "C" char DAT_0042548c[];   // Closure2<class CTriggerVolumeManager,bool,const char *,const char *>
class Owner_1fffa0 {};
typedef void (Owner_1fffa0::*Fn_1fffa0)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_1fffa0 fn;
    Owner_1fffa0* owner;
    Closure2(const char* name, Owner_1fffa0* object, Fn_1fffa0 function);
};
Closure2::Closure2(const char* name, Owner_1fffa0* object, Fn_1fffa0 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00425314;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_0042548c;
    owner = object;
}
} // namespace fn_001fffa0


// 0x00200000 Closure2<CTriggerVolumeManager,bool,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x00200000.cpp
// sym: ?vfunc_0@Closure2_200000@fn_00200000@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CTriggerVolumeManager, bool, const char *, const char
// *>::~Closure2() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature,
// as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00200000 {
struct Closure2_200000 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_200000::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00200000
// (x64t21) the destructor itself, which other objects' code references:


// 0x00200020 Closure2<CTriggerVolumeManager,bool,const_char_*,const_char_*>::vfunc_2 (37 B): equivalent/0x00200020.cpp
// sym: ?vfunc_2@Closure2_200020@fn_00200020@@QAEXPAX00@Z @e654de0dce29 @w4e3d89bebec6 @v30e1d7bcd577
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CTriggerVolumeManager,bool,const_char_*,const_char_*>::vfunc_2 @ 0x00200020
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure2<CTriggerVolumeManager, bool, const char *, const char *>::vfunc_2`.
namespace fn_00200020 {
struct Closure2_200020 : hulk_script::FunctionGenView {
    bool (::CTriggerVolumeManager::*f_1c)(const char *, const char *);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure2_200020::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** arguments = (const char **)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CTriggerVolumeManager_200020 * *)&this->f_20)->*(*(bool (CTriggerVolumeManager_200020::**)(const char *, const char *))&this->f_1c))(arguments[0], arguments[1]);
    if (result)
        *result = value;
}
} // namespace fn_00200020


// 0x00200050 FUN_00200050 (89 B): matches/0x00200050.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_00200050@@QAE@PBDPAVOwner_200050@1@P821@AEXXZ@Z
namespace fn_00200050 {
// (script1) Closure2<class CTriggerVolumeManager,void,const char *,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425324[];   // Method2<class CTriggerVolumeManager,void,const char *,float>
extern "C" char DAT_0042549c[];   // Closure2<class CTriggerVolumeManager,void,const char *,float>
class Owner_200050 {};
typedef void (Owner_200050::*Fn_200050)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_200050 fn;
    Owner_200050* owner;
    Closure2(const char* name, Owner_200050* object, Fn_200050 function);
};
Closure2::Closure2(const char* name, Owner_200050* object, Fn_200050 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00425324;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    vftable = DAT_0042549c;
    owner = object;
}
} // namespace fn_00200050


// 0x002000b0 Closure2<CTriggerVolumeManager,void,const_char_*,float>::vfunc_0 (30 B): matches/0x002000b0.cpp
// sym: ?vfunc_0@Closure2_2000b0@fn_002000b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CTriggerVolumeManager, void, const char *,
// float>::~Closure2() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_002000b0 {
struct Closure2_2000b0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_2000b0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002000b0
// (x64t21) the destructor itself, which other objects' code references:


// 0x002000d0 Closure2<CTriggerVolumeManager,void,const_char_*,float>::vfunc_2 (22 B): matches/0x002000d0.cpp
// sym: ?vfunc_2@Closure2_2000d0@fn_002000d0@@QAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure2<CTriggerVolumeManager, void, const char *, float>::vfunc_2`.
namespace fn_002000d0 {
struct Closure2_2000d0 : hulk_script::FunctionGenView {
    void (::CTriggerVolumeManager::*f_1c)(const char *, float);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure2_2000d0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_2000d0 * p = (Pair_2000d0 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2000d0 * *)&this->f_20)->*(*(void (CActorManager_2000d0::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
} // namespace fn_002000d0


// 0x00200120 Closure3<CTriggerVolumeManager,bool,math::Vector,const_char_*,bool>::vfunc_0 (30 B): matches/0x00200120.cpp
// sym: ?vfunc_0@Closure3_200120@fn_00200120@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure3<CTriggerVolumeManager, bool,math::Vector,
// const char *, bool>::~Closure3() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body
// 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00200120 {
struct Closure3_200120 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure3_200120::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00200120


// 0x00200190 FUN_00200190 (89 B): matches/0x00200190.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_00200190@@QAE@PBDPAVOwner_200190@1@P821@AEXXZ@Z
namespace fn_00200190 {
// (script1) Closure2<class CTriggerVolumeManager,bool,const char *,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425344[];   // Method2<class CTriggerVolumeManager,bool,const char *,bool>
extern "C" char DAT_004254bc[];   // Closure2<class CTriggerVolumeManager,bool,const char *,bool>
class Owner_200190 {};
typedef void (Owner_200190::*Fn_200190)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_200190 fn;
    Owner_200190* owner;
    Closure2(const char* name, Owner_200190* object, Fn_200190 function);
};
Closure2::Closure2(const char* name, Owner_200190* object, Fn_200190 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00425344;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    vftable = DAT_004254bc;
    owner = object;
}
} // namespace fn_00200190


// 0x002001f0 Closure2<CTriggerVolumeManager,bool,const_char_*,bool>::vfunc_0 (30 B): matches/0x002001f0.cpp
// sym: ?vfunc_0@Closure2_2001f0@fn_002001f0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CTriggerVolumeManager, bool, const char *,
// bool>::~Closure2() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_002001f0 {
struct Closure2_2001f0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_2001f0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002001f0
// (x64t21) the destructor itself, which other objects' code references:


// 0x00200210 Closure2<CTriggerVolumeManager,bool,const_char_*,bool>::vfunc_2 (46 B): equivalent/0x00200210.cpp
// sym: ?vfunc_2@Closure2_200210@fn_00200210@@QAEXPAX00@Z @8eb15ebc569e @w69c2d2ef61d1
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CTriggerVolumeManager,bool,const_char_*,bool>::vfunc_2 @ 0x00200210
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure2<CTriggerVolumeManager, bool, const char *, bool>::vfunc_2`.
namespace fn_00200210 {
struct Closure2_200210 : hulk_script::FunctionGenView {
    bool (::CTriggerVolumeManager::*f_1c)(const char *, bool);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure2_200210::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * arguments = (Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CTriggerVolumeManager_200210 * *)&this->f_20)->*(*(bool (CTriggerVolumeManager_200210::**)(const char *, bool))&this->f_1c))(arguments->name, arguments->value);
    if (result) *result = value;
}
} // namespace fn_00200210


// 0x00200290 Closure4<CTriggerVolumeManager,bool,const_char_*,int,int,bool>::vfunc_2 (62 B): matches/0x00200290.cpp
// sym: ?vfunc_2@?$Closure4@VCTriggerVolumeManager@@_NPBDHH_N@@UAEXPAX00@Z
template <> void Closure4<CTriggerVolumeManager, bool, const char *, int, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr n = (hulk_intptr)__p0; Args * args = (Args *)__p1; bool * out = (bool *)__p2;

    CTriggerVolumeManager_200290* o = (*(CTriggerVolumeManager_200290 * *)&this->f_20);
    bool (CTriggerVolumeManager_200290::*fn)(const char*, int, int, bool) = (*(bool (CTriggerVolumeManager_200290::**)(const char *, int, int, bool))&this->f_1c);
    char* p = (char*)args;
    const char* a = *(const char**)p;
    int b = *(int*)(p += 4);
    int c = *(int*)(p += 4);
    bool d = *(bool*)(p += 4);
    bool r = (o->*fn)(a, b, c, d);
    if (out)
        *out = r;
}

namespace fn_f3d6a774 {

// 0x002002d0 FUN_002002d0 (76 B): matches/0x002002d0.cpp
// sym: ??0Closure1_2002d0@fn_f3d6a774@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
// Function (include/decls/data/script.h): the vftable, then Function's fields.
Closure1_2002d0::Closure1_2002d0(const char* a, void* b, ScriptMemberFn c) : Method1_2002d0(a, c), v20(b) {}

} // namespace fn_f3d6a774

// 0x00200340 Closure1<CTriggerVolumeManager,int,const_char_*>::vfunc_2 (30 B): equivalent/0x00200340.cpp
// sym: ?vfunc_2@Closure1_200340@fn_00200340@@QAEXPAX00@Z @d5fcbfd9f63b @we2b2731e125e @v16583a6edbf7
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure1<CTriggerVolumeManager,int,const_char_*>::vfunc_2 @ 0x00200340
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CTriggerVolumeManager, int, const char *>::vfunc_2`.
namespace fn_00200340 {
struct Closure1_200340 : hulk_script::FunctionGenView {
    int (::CTriggerVolumeManager::*f_1c)(const char *);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_200340::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** value = (const char **)__p1; int * result = (int *)__p2;

    int answer = ((*(CTriggerVolumeManager_200340 * *)&this->f_20)->*(*(int (CTriggerVolumeManager_200340::**)(const char *))&this->f_1c))(*value);
    if (result)
        *result = answer;
}
} // namespace fn_00200340


// 0x00200420 Closure5<CTriggerVolumeManager,const_char_*,const_math::Vector,int,int,float,float>::vfunc_2 (29 B): matches/0x00200420.cpp
// sym: ?vfunc_2@Closure5_200420@fn_00200420@@QAEXPAX00@Z
// Same code shape as 0x0002ebc0 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure5<CTriggerVolumeManager, const char *, const ::math::Vector, int, int, float, float>::vfunc_2`.
namespace fn_00200420 {
struct Closure5_200420 : hulk_script::FunctionGenView {
    const char * (::CTriggerVolumeManager::*f_1c)(const ::math::Vector, int, int, float, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure5_200420::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; hulk_intptr y = (hulk_intptr)__p1; hulk_intptr z = (hulk_intptr)__p2;

    invoke(this->f_20, y, z, (*(int *)&this->f_1c));
}
} // namespace fn_00200420


// 0x00200440 FUN_00200440 (76 B): matches/0x00200440.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_00200440@@QAE@PBDPAVOwner_200440@1@P821@AEXXZ@Z
namespace fn_00200440 {
// (script1) Closure1<class CTriggerVolumeManager,const char *,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00425394[];   // Method1<class CTriggerVolumeManager,const char *,const char *>
extern "C" char DAT_0042550c[];   // Closure1<class CTriggerVolumeManager,const char *,const char *>
class Owner_200440 {};
typedef void (Owner_200440::*Fn_200440)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_200440 fn;
    Owner_200440* owner;
    Closure1(const char* name, Owner_200440* object, Fn_200440 function);
};
Closure1::Closure1(const char* name, Owner_200440* object, Fn_200440 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00425394;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_0042550c;
    owner = object;
}
} // namespace fn_00200440


// 0x002004b0 Closure1<CTriggerVolumeManager,const_char_*,const_char_*>::vfunc_2 (30 B): equivalent/0x002004b0.cpp
// sym: ?vfunc_2@Closure1_2004b0@fn_002004b0@@QAEXPAX00@Z @d5fcbfd9f63b @we2b2731e125e @vf6a24a1921ca
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure1<CTriggerVolumeManager,const_char_*,const_char_*>::vfunc_2 @ 0x002004b0
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CTriggerVolumeManager, const char *, const char *>::vfunc_2`.
namespace fn_002004b0 {
struct Closure1_2004b0 : hulk_script::FunctionGenView {
    const char * (::CTriggerVolumeManager::*f_1c)(const char *);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_2004b0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** argument = (const char **)__p1; const char ** result = (const char **)__p2;

    const char* value = ((*(CTriggerVolumeManager_2004b0 * *)&this->f_20)->*(*(TriggerMethod *)&this->f_1c))(*argument);
    if (result) *result = value;
}
} // namespace fn_002004b0


// 0x002004d0 FUN_002004d0 (76 B): equivalent/0x002004d0.cpp [wrapped: conflict: CTriggerVolumeManager; Closure1; Method1]
// sym: ??0?$Closure1@UCTriggerVolumeManager@fn_002004d0@@XM@fn_002004d0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z @ad4fb406a6f2 @weef8ebde1591 @vb3a7c00c1f68
namespace fn_002004d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002004d0 @ 0x002004d0
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


struct CTriggerVolumeManager {};
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct BaseInit : public ScriptFunctionFields { virtual void invoke(float); BaseInit(const char*, int); };
template<class T,class R,class A> struct Method1 : BaseInit { virtual void invoke(A); ScriptMemberFn value; Method1(const char* a,int b):BaseInit(a,b) {} };
template<class T,class R,class A> struct Closure1 : Method1<T,R,A> { virtual void invoke(A); void* other; Closure1(const char* a,void* otherArg,ScriptMemberFn valueArg); };
extern "C" void* DAT_0042551c;
template<> Closure1<CTriggerVolumeManager,void,float>::Closure1(const char* arg,void* otherArg,ScriptMemberFn valueArg) : Method1<CTriggerVolumeManager,void,float>(arg,1) { this->value=valueArg; this->retType=FUN_001d04d0(((char*)&DAT_0048e100)); this->argTypes[0]=FUN_001d04d0(((char*)&DAT_0048e128)); this->other=otherArg; *(void**)this=&DAT_0042551c; }
} // namespace fn_002004d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00200540 Closure1<CTriggerVolumeManager,void,float>::vfunc_2 (18 B): matches/0x00200540.cpp
// sym: ?vfunc_2@Closure1_200540@fn_00200540@@QAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure1<CTriggerVolumeManager, void, float>::vfunc_2`.
namespace fn_00200540 {
struct Closure1_200540 : hulk_script::FunctionGenView {
    void (::CTriggerVolumeManager::*f_1c)(float);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure1_200540::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_200540 * *)&this->f_20)->*(*(void (CActorManager_200540::**)(const char *))&this->f_1c))(*b);
}
} // namespace fn_00200540


// 0x002006f0 FUN_002006f0 (109 B): matches/0x002006f0.cpp [wrapped: conflict: CTriggerVolumeManager; Closure0; Method0]
// sym: ?FUN_002006f0@Registry_2006f0@fn_002006f0@@QAEXPBDPAVOwner_2006f0@2@P832@AEXXZ@Z
namespace fn_002006f0 {
// (script1) ScriptHandler's registration of a Closure0<class CTriggerVolumeManager,int>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_004252c4[];   // Method0<class CTriggerVolumeManager,int>
extern "C" char DAT_0042543c[];   // Closure0<class CTriggerVolumeManager,int>
class Owner_2006f0 {};
typedef void (Owner_2006f0::*Fn_2006f0)();
struct Closure_2006f0 : hulk_script::ScriptFunction {
    Fn_2006f0 fn;
    Owner_2006f0* owner;
    Closure_2006f0(const char* name, Owner_2006f0* object, Fn_2006f0 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_004252c4;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
        vftable = DAT_0042543c;
        owner = object;
    }
};
struct Registry_2006f0 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_002006f0(const char* name, Owner_2006f0* object, Fn_2006f0 function);
};
void Registry_2006f0::FUN_002006f0(const char* name, Owner_2006f0* object, Fn_2006f0 function) {
    Closure_2006f0* c = new Closure_2006f0(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_002006f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3d6a774 {

// 0x002007b0 FUN_002007b0 (83 B): equivalent/0x002007b0.cpp
// sym: ?FUN_002007b0@Registry_2007b0@fn_f3d6a774@@QAEXPBDPAVCTriggerVolumeManager_2007b0@2@P832@AE_N0VVector_2007b0@math@@2M@Z@Z @06d2a372320f @w35113775f73a @v070913548785
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_002007b0 @ 0x002007b0
// FUN_002007b0 @ 0x002007b0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_2007b0::FUN_002007b0(const char* a1, CTriggerVolumeManager_2007b0* a2, Fn_2007b0 a3) {
    typedef Closure4_2007b0<CTriggerVolumeManager_2007b0, bool, const char*, math::Vector_2007b0, math::Vector_2007b0, float> Alloc_2007b0;
    HULK_SIZE32(Alloc_2007b0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_2007b0));
    void* x = 0;
    if (m) {
        ((Raw_2007b0*)m)->FUN_001feca0(a1, a3);
        x = new (m) Closure4_2007b0<CTriggerVolumeManager_2007b0, bool, const char*, math::Vector_2007b0, math::Vector_2007b0, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x002008b0 FUN_002008b0 (70 B): equivalent/0x002008b0.cpp
// sym: ?FUN_002008b0@Registry_2008b0@fn_f3d6a774@@QAEXPBDPAVOwner@2@P832@AE_N00@Z@Z @e7bb1abdcf61 @wf6a47327b7f7 @v04bb9b587e41
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002008b0 @ 0x002008b0
// FUN_002008b0 @ 0x002008b0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_2008b0::FUN_002008b0(const char* a1, Owner* a2, Fn_2008b0 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure2_2008b0* e = (Closure2_2008b0*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_001fffa0(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00200900 FUN_00200900 (70 B): equivalent/0x00200900.cpp
// sym: ?FUN_00200900@Registry_200900@fn_f3d6a774@@QAEXPBDPAVOwner@2@P832@AEX0M@Z@Z @02a25f33fc68 @w8fe8845b0c31 @v8b873317a0bb
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00200900 @ 0x00200900
// FUN_00200900 @ 0x00200900  (generated by tools/equiv_gen/reg_helper.py)
void Registry_200900::FUN_00200900(const char* a1, Owner* a2, Fn_200900 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure2_200900* e = (Closure2_200900*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_00200050(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00200950 FUN_00200950 (83 B): equivalent/0x00200950.cpp
// sym: ?FUN_00200950@Registry_200950@fn_f3d6a774@@QAEXPBDPAVCTriggerVolumeManager_200950@2@P832@AE_NVVector_200950@math@@0_N@Z@Z @66631cd14399 @wfe91faaff79c @v73a12064e4a6
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00200950 @ 0x00200950
// FUN_00200950 @ 0x00200950  (generated by tools/equiv_gen/reg_helper.py)
void Registry_200950::FUN_00200950(const char* a1, CTriggerVolumeManager_200950* a2, Fn_200950 a3) {
    typedef Closure3_200950<CTriggerVolumeManager_200950, bool, math::Vector_200950, const char*, bool> Alloc_200950;
    HULK_SIZE32(Alloc_200950, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_200950));
    void* x = 0;
    if (m) {
        ((Raw_200950*)m)->FUN_001fefe0(a1, a3);
        x = new (m) Closure3_200950<CTriggerVolumeManager_200950, bool, math::Vector_200950, const char*, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00200a00 FUN_00200a00 (83 B): equivalent/0x00200a00.cpp
// sym: ?FUN_00200a00@Registry_200a00@fn_f3d6a774@@QAEXPBDPAVCTriggerVolumeManager_200a00@2@P832@AE_N0HH_N@Z@Z @60f9afb744cb @w6f55b88f594b @vb70676fd185d
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00200a00 @ 0x00200a00
// FUN_00200a00 @ 0x00200a00  (generated by tools/equiv_gen/reg_helper.py)
void Registry_200a00::FUN_00200a00(const char* a1, CTriggerVolumeManager_200a00* a2, Fn_200a00 a3) {
    typedef Closure4_200a00<CTriggerVolumeManager_200a00, bool, const char*, int, int, bool> Alloc_200a00;
    HULK_SIZE32(Alloc_200a00, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_200a00));
    void* x = 0;
    if (m) {
        ((Raw_200a00*)m)->FUN_001ff150(a1, a3);
        x = new (m) Closure4_200a00<CTriggerVolumeManager_200a00, bool, const char*, int, int, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00200ab0 FUN_00200ab0 (83 B): equivalent/0x00200ab0.cpp
// sym: ?FUN_00200ab0@Registry_200ab0@fn_f3d6a774@@QAEXPBDPAVCTriggerVolumeManager_200ab0@2@P832@AEX0H_N@Z@Z @5ca03c897f24 @wd70ef31329ac @v2f1c7b27b64c
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00200ab0 @ 0x00200ab0
// FUN_00200ab0 @ 0x00200ab0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_200ab0::FUN_00200ab0(const char* a1, CTriggerVolumeManager_200ab0* a2, Fn_200ab0 a3) {
    typedef Closure3_200ab0<CTriggerVolumeManager_200ab0, void, const char*, int, bool> Alloc_200ab0;
    HULK_SIZE32(Alloc_200ab0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_200ab0));
    void* x = 0;
    if (m) {
        ((Raw_200ab0*)m)->FUN_001ff2c0(a1, a3);
        x = new (m) Closure3_200ab0<CTriggerVolumeManager_200ab0, void, const char*, int, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00200b10 FUN_00200b10 (83 B): equivalent/0x00200b10.cpp
// sym: ?FUN_00200b10@Registry_200b10@fn_f3d6a774@@QAEXPBDPAVCTriggerVolumeManager_200b10@2@P832@AEPBDVVector_200b10@math@@HHMM@Z@Z @6ae189a32c6f @waea06d0ad40b @v5a6c3b2d6e42
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00200b10 @ 0x00200b10
// FUN_00200b10 @ 0x00200b10  (generated by tools/equiv_gen/reg_helper.py)
void Registry_200b10::FUN_00200b10(const char* a1, CTriggerVolumeManager_200b10* a2, Fn_200b10 a3) {
    typedef Closure5_200b10<CTriggerVolumeManager_200b10, const char*, const math::Vector_200b10, int, int, float, float> Alloc_200b10;
    HULK_SIZE32(Alloc_200b10, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_200b10));
    void* x = 0;
    if (m) {
        ((Raw_200b10*)m)->FUN_001ff360(a1, a3);
        x = new (m) Closure5_200b10<CTriggerVolumeManager_200b10, const char*, const math::Vector_200b10, int, int, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f3d6a774

// 0x00200c10 FUN_00200c10 (2853 B): equivalent/0x00200c10.cpp [wrapped: macros]
// sym: ?Register@CTriggerVolumeManager@fn_00200c10@@QAEXH@Z @51b6c8a8c724 @wf1887f9a64ce @vb3bf370d62ac
void* operator new(hulk_uintptr) throw();
namespace fn_00200c10 {
// STATUS: equivalent (tools/equiv.py level 3: 485 inputs, branch coverage 66/66)
// FUN_00200c10 @ 0x00200c10


void* FUN_0008d690(unsigned int);
char FUN_001d04d0(const void*) throw();
class CTriggerVolumeManager;
namespace math { class Vector { public: float x, y, z; }; }
} // namespace fn_00200c10
// (script2) math::Vector's type_info 0x0048e10c ('V') for the records' type codes
template <> struct hulk_script::ScriptType<fn_00200c10::math::Vector> { static const void* tag() { return hulk_script::DAT_0048e10c; } };
namespace fn_00200c10 {
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
extern char DAT_0048e0e4, DAT_0048e0f0, DAT_0048e100, DAT_0048e10c, DAT_0048e128, DAT_0048e134;
#define tBool DAT_0048e0e4
#define tString DAT_0048e0f0
#define tVoid DAT_0048e100
#define tVector DAT_0048e10c
#define tFloat DAT_0048e128
#define tInt DAT_0048e134
// Function (include/decls/data/script.h): the vftable, then Function's fields; Method<N> adds the member-function
// pointer, Closure<N> the object.
// (script2) the Closure1s are include/game/script_bind.h's records: Method1<C,R,A1>'s and Closure1<C,R,A1>'s game vftables
// by address (Vft1), as the game's inlined constructors store them; no stand-in vftable.
template <class R, class A1> struct Vft1;
class Registry { public:
    void FUN_001d3b70(const char*, void*);
    void FUN_002006f0(const char*, CTriggerVolumeManager*, ScriptMemberFn);
    void FUN_002007b0(const char*, CTriggerVolumeManager*, ScriptMemberFn);
    void FUN_00200950(const char*, CTriggerVolumeManager*, ScriptMemberFn);
    void FUN_00200a00(const char*, CTriggerVolumeManager*, ScriptMemberFn);
    void FUN_00200ab0(const char*, CTriggerVolumeManager*, ScriptMemberFn);
    void FUN_00200b10(const char*, CTriggerVolumeManager*, ScriptMemberFn);
};
class Entry { public:
    void* FUN_001ffb00(const char*, CTriggerVolumeManager*, ScriptMemberFn);
    void* FUN_001ffbc0(const char*, CTriggerVolumeManager*, ScriptMemberFn);
    void* FUN_001ffe70(const char*, CTriggerVolumeManager*, ScriptMemberFn);
    void* FUN_001fffa0(const char*, CTriggerVolumeManager*, ScriptMemberFn);
    void* FUN_00200050(const char*, CTriggerVolumeManager*, ScriptMemberFn);
    void* FUN_00200190(const char*, CTriggerVolumeManager*, ScriptMemberFn);
};
Registry* FUN_001d4c90();
#define MF(b) reinterpret_cast<ScriptMemberFn>(&CTriggerVolumeManager::FUN_##b)
#define G1(n, b, R, A1) { r->FUN_001d3b70(n, new hulk_script::ScriptClosure<hulk_script::ScriptMethod1<CTriggerVolumeManager, R, A1>, CTriggerVolumeManager>(n, this, reinterpret_cast<R (CTriggerVolumeManager::*)(A1)>(&CTriggerVolumeManager::FUN_##b), Vft1<R, A1>::mv(), Vft1<R, A1>::cv())); }
#define E(n, c, b) { HULK_SIZE32(ScriptClosureView, 0x24); Entry* e = (Entry*)FUN_0008d690((unsigned int)sizeof(ScriptClosureView)); void* x = 0; if (e) x = e->FUN_##c(n, this, MF(b)); r->FUN_001d3b70(n, x); }
#define O(n, c, b) { r->FUN_##c(n, this, MF(b)); }

class CTriggerVolumeManager {
public:
    // The member functions bound to Lua below.
    void FUN_001fd7d0();
    void FUN_001fd830();
    void FUN_001fd7a0();
    void FUN_001fc9a0();
    void FUN_001fc9d0();
    void FUN_001fc9f0();
    void FUN_001fca40();
    void FUN_001fca90();
    void FUN_001fcb70();
    void FUN_001fcb90();
    void FUN_001fcc40();
    void FUN_001fcc60();
    void FUN_001fcbe0();
    void FUN_001fd8f0();
    void FUN_001fd9a0();
    void FUN_001fdfc0();
    void FUN_001fdf10();
    void FUN_001fdf90();
    void FUN_001fd980();
    void FUN_001fccb0();
    void FUN_001fe280();
    void FUN_001fd4c0();
    void FUN_001fd4d0();
    void FUN_001fd870();
    void FUN_001fd8b0();
    void FUN_001fc480();
    void FUN_001fcab0();
    void FUN_001fcb30();
    void FUN_001fcbc0();
    void FUN_001fcc00();
    void FUN_001fcc80();
    void FUN_001fcdb0();
    void FUN_001fce50();
    void FUN_001fdc90();
    void FUN_001fdeb0();
    void FUN_001fdf50();
    void FUN_001fd920();
    void FUN_001ff950();
    void Register(int a);
    int i0;
    int i4;
};
extern "C" char DAT_00425274[], DAT_00425284[], DAT_004252b4[], DAT_004252d4[], DAT_00425304[], DAT_00425364[], DAT_00425394[], DAT_004253a4[];
extern "C" char DAT_004253ec[], DAT_004253fc[], DAT_0042542c[], DAT_0042544c[], DAT_0042547c[], DAT_004254dc[], DAT_0042550c[];
extern "C" void* DAT_0042551c;   // (declared so by 0x002004d0's block: one type per C name)
#define VFT1(R, A, M, C) template <> struct Vft1<R, A> { static const void* mv() { return M; } static const void* cv() { return C; } };
VFT1(Vector, String, DAT_00425274, DAT_004253ec)
VFT1(Float, String, DAT_00425284, DAT_004253fc)
VFT1(Bool, String, DAT_004252b4, DAT_0042542c)
VFT1(String, Int, DAT_004252d4, DAT_0042544c)
VFT1(Void, String, DAT_00425304, DAT_0042547c)
VFT1(Int, String, DAT_00425364, DAT_004254dc)
VFT1(String, String, DAT_00425394, DAT_0042550c)
VFT1(Void, Float, DAT_004253a4, &DAT_0042551c)
#undef VFT1

void CTriggerVolumeManager::Register(int a) {
    i4 = a;
    Registry* r = FUN_001d4c90();
    if (r) {
G1("tvm_GetLocatorPosition", 001fd7d0, Vector, String)
G1("tvm_GetLocatorOrientation", 001fd830, Float, String)
E("tvm_SetLocatorPosition", 001ffb00, 001fd870)
E("tvm_SetLocatorOrientation", 001ffbc0, 001fd8b0)
G1("tvm_DoesLocatorExist", 001fd7a0, Bool, String)
O("tvm_GetLocatorCount", 002006f0, 001fc480)
G1("tvm_GetLocatorName", 001fc9a0, String, Int)
G1("tvm_DoesTriggerVolumeExist", 001fc9d0, Bool, String)
G1("tvm_GetTriggerVolumeMinPosition", 001fc9f0, Vector, String)
G1("tvm_GetTriggerVolumeMaxPosition", 001fca40, Vector, String)
G1("tvm_GetTriggerVolumeOrientation", 001fca90, Float, String)
E("tvm_SetTriggerVolumeOrientation", 001ffbc0, 001fcab0)
O("tvm_SetTriggerVolume", 002007b0, 001fcb30)
G1("tvm_IsTriggerVolumeEnabled", 001fcb70, Bool, String)
G1("tvm_IsNPCAvoidTriggerVolume", 001fcb90, Bool, String)
E("tvm_SetNPCAvoidTriggerVolume", 001ffe70, 001fcbc0)
G1("tvm_DisableTriggerVolume", 001fcc40, Void, String)
G1("tvm_EnableTriggerVolume", 001fcc60, Void, String)
G1("tvm_IsTriggerVolumeEmpty", 001fcbe0, Bool, String)
E("tvm_IsActorInTriggerVolume", 001fffa0, 001fcc00)
G1("tvm_IsLocatorInCameraView", 001fd8f0, Bool, String)
E("tvm_KillPropsInTriggerVolume", 001ffe70, 001fcc80)
E("tvm_DamageAllActorsInTriggerVolume", 00200050, 001fcdb0)
O("tvm_IsVectorInTriggerVolume", 00200950, 001fce50)
G1("tvm_CreateEncounterGenerator", 001fd9a0, Bool, String)
E("tvm_AddCharacterToEncounterGenerator", 001fffa0, 001fdc90)
G1("tvm_DeleteEncounterGenerator", 001fdfc0, Bool, String)
E("tvm_SetEncounterGeneratorEnabled", 00200190, 001fdeb0)
G1("tvm_IsEncounterGeneratorEnabled", 001fdf10, Bool, String)
O("tvm_SetEncounterCharacterEnabled", 00200a00, 001fdf50)
G1("tvm_GetEncounterGeneratorCharacterTypeCount", 001fdf90, Int, String)
O("tvm_DamagePropsInTriggerVolume", 00200ab0, 001fd920)
G1("tvm_GetNumPropsInTriggerVolume", 001fd980, Int, String)
G1("tvm_GetPropInTriggerVolume", 001fccb0, String, Int)
O("tvm_GetStreamedLocatorName", 00200b10, 001ff950)
G1("tvm_GetNearestLocator", 001fe280, String, String)
G1("tvm_SetSpawnDistanceOffCamera", 001fd4c0, Void, Float)
G1("tvm_SetSpawnDistanceOnCamera", 001fd4d0, Void, Float)
    }
}
} // namespace fn_00200c10
#undef E
#undef G1
#undef MF
#undef O
#undef tBool
#undef tFloat
#undef tInt
#undef tString
#undef tVector
#undef tVoid

