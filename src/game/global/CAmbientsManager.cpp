// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000788e0..0x00081340 (kind game, layer game, confidence high), dominant class CAmbientsManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/content.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9399ba1 {
#define TREE_TU_END }
namespace fn_f9399ba1 {} using namespace fn_f9399ba1;
#include "game/global.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f9399ba1 {
class Thing_788e0 {
  public:
    char pad[0x3740];
    int mValue;
    void Set();
};
class Object {
  public:
    virtual void _m_vf0();
    virtual void release();
    char _m_pad_4[0xc];
    int type;
    char _m_pad_14[0x24];
    int groupId;
    int subIndex;
    char _m_pad_40[0x1c];
    int category;
    char _m_pad_60[0x20];
    float value;
};
struct X_78b70 {
    void Call_0027af00();
    X_78b70* Target();
};
struct X_78b90 {
    void Call_0027af00();
    X_78b90* Target();
};
class pddiObject_78c30 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_78c30 : public pddiObject_78c30 {};
class pddiBaseShader_78c30 : public pddiShader_78c30 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_78c30 : public pddiBaseShader_78c30 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class C_78d00 {
  public:
    char pad[0x364c];
    char m364c;
    void Set(char value);
};
struct Rng_78d20 {
    unsigned int s0;
    unsigned int s1;
};
Rng_78d20 *__cdecl FUN_000964d0();
struct Rec_78d20 {
    int count;
    int pad[3];
};
struct Slot_78d20 {
    char pad0[0x18];
    int f18;
    char pad1c[0xbc - 0x1c];
    int keyA;
    int keyB;
};
class Pool_78d20 {
public:
    char pad0[0x34b0];
    Rec_78d20 recs[9];
    char pad3540[8];
    int count;
    Slot_78d20 *slots[20];
    int slotCount;

    bool FUN_00078d20(int a, int b, int *pIdx, int *pSub);
};
struct Vec3_78ee0 {
    float x, y, z;
    float FUN_0022d110();
};
struct Anchor_78ee0 {
    void FUN_00059a50(Vec3_78ee0 *out);
};
struct Ref124 {
    char pad0[0x10];
    Anchor_78ee0 *anchor;
};
struct Ref20_78ee0 {
    char pad0[0x124];
    Ref124 *ref;
};
struct Ref382c {
    char pad0[0x20];
    Ref20_78ee0 *ref;
};
extern "C" char FUN_0022d550(Vec3_78ee0 *p0, Vec3_78ee0 *dir, Vec3_78ee0 *a, Vec3_78ee0 *b, float *outA, float *outB);
class Walker_78ee0 {
public:
    char pad0[0x382c];
    Ref382c *owner;
    void FUN_00078ee0(Vec3_78ee0 *a, Vec3_78ee0 *b);
};
struct Position { float x,y,z; };
struct Entry { char pad[8]; int first; int second; };
struct Owner { char pad[0x354c]; Entry* entries[20]; int count; int FUN_00079220(int first, int second); };
struct Target_79270 {
    char pad[0x359c];
    unsigned int value;
};
class Obj_79290 {
  public:
    char pad[0x3548];
    int value;
    void Clear();
};
struct Name_792a0 {
    int lo;
    int hi;
    Name_792a0* FUN_0027b0e0(const char* text);
    void FUN_0027af70(const Name_792a0* other);
    void FUN_0027af50();
};
struct Entry_792a0 {
    Name_792a0 name;            // 0x00
    int value;            // 0x08
    char flag;            // 0x0c
    char pad0d[3];
};
struct Registry_792a0 {
    char pad00[0x34a8];
    Entry_792a0 entries[1];     // 0x34a8
    char pad34b8[0x3548 - 0x34b8];
    int count;            // 0x3548
    void Add(const char* text, int value, char flag);
};
class Obj_79310 {
  public:
    char pad[0x3640];
    int mValue;
    void SetZero();
};
class Obj_79420 {
  public:
    char pad[0x3744];
    int mField;
    int mLimit;
    void SetX(int x);
};
struct Obj_79440 {
    char pad1[0x36f0];
    int arr[20];  // 0x36f0
    int count;    // 0x3740
    int pad_3744; // 0x3744
    int divv;     // 0x3748

    void SetScale(int p);
};
struct Id64_794a0 {
    unsigned int lo;
    unsigned int hi;
    Id64_794a0 *FUN_0027b0e0(const char *name);
    void FUN_0027af70(Id64_794a0 *src);
    void FUN_0027af50();
};
struct SlotEntry_794a0 {
    Id64_794a0 id;                // 0x0
    int value;              // 0x8
    int pad0c;
};
extern "C" int __cdecl FUN_0034483c();
class SlotList_794a0 {
public:
    char pad0000[0x3650];
    SlotEntry_794a0 entries[10];  // 0x3650
    int ints[10];           // 0x36f0
    int zeros[10];          // 0x3718
    int count;              // 0x3740
    char pad3744[4];
    int scale;              // 0x3748
    void FUN_000794a0(const char *name, int value, float amount);
};
typedef unsigned __int64 u64_79530;
class Item {
  public:
    void Set(float);
};
class Thing {
  public:
    char pad[0x374c];
    Item* items[20];
    int count;
    void Run(float value);
};
class Obj {
  public:
    virtual void Add();
    virtual void Release();
    char _m_pad_4[0x7];
    char data[6408];
    char _m_pad_1913[0x1e39];
    Item* items[20];
    int count;
    void Run(float x);
    void Set(int n);
};
extern float hulk_at_0049b888;
class Target_79640 {
  public:
    char pad[0x37a4];
    int a;
    int b;
    void Set(int x, int y);
};
class X_79660 {
  public:
    void call_00083d30(int);
};
class C_79660 {
  public:
    char pad[0x374c];
    X_79660* items[1];
    char pad2[0x379c - 0x3750];
    int count;
    void f(int);
};
class Item_796a0 {
  public:
    char pad[0x1c];
    float value;
    void update_00083d30(float);
};
class Owner_796a0 {
  public:
    char pad[0x374c];
    Item_796a0* items[20];
    int count;
    void run(float);
};
__declspec(align(8)) struct Name {
    int lo, hi;
    Name() throw();
    ~Name() throw();
    bool FUN_0027af90(const Name *other) throw();
};
struct Resolver_79800 {
    void FUN_001dd930(int id, Name *out) throw();
};
struct Owner_79800 {
    char pad0[0xc];
    Resolver_79800 *resolver;         // 0xc
};
struct Item_79800 {
    char pad0[0x34];
    int id;                     // 0x34
};
class Scene_79800 {
public:
    char pad0[0x374c];
    Item_79800 *items[1];             // 0x374c
    char pad3750[0x379c - 0x3750];
    int count;                  // 0x379c
    char pad37a0[0x382c - 0x37a0];
    Owner_79800 *owner;               // 0x382c

    int FUN_00079800(const Name *key);
};
struct Entry_79990 {
    float f0;
    float f4;
    float f8;
    float fc;
    char active;
    char pad11[3];
};
struct Rec_79990 {
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    int f18;
    char pad1c[0xc];
    int f28;
    int f2c;
    int f30[4];
    int f40;
    char f44;
    char pad45[3];
};
class Stage_79990 {
public:
    char pad0[0x1904];
    Rec_79990 recs[256];

    void FUN_00079990(Entry_79990 *tab, int a2, int a3, int a4, int a5, int a6, int a7, int *counter, int a9, int a10);
};
struct Item_79c80 {
    float f0;
    float f4;
    float f8;
    float fc;
    char flag;
    char pad11[3];
};
struct Rec_79c80 {
    float f00;
    int f04;
    float f08;
    float f0c;
    int f10;
    float f14;
    int f18;
    char pad1c[0xc];
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    char f44;
    char pad45[3];
};
class Mesh_79c80 {
public:
    char pad0[0x1904];
    Rec_79c80 recs[1];
    void FUN_00079c80(Item_79c80 *p, int i2, int i3, int i4, int a5, int a6, int a7, int *cnt, int v9, int v10);
};
struct Item_79f40 {
    float f0;
    float f4;
    float f8;
    float fc;
    char flag;
    char pad11[3];
};
struct Rec_79f40 {
    float f00;
    int f04;
    float f08;
    float f0c;
    int f10;
    float f14;
    int f18;
    char pad1c[0xc];
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    char f44;
    char pad45[3];
};
class Mesh_79f40 {
public:
    char pad0[0x1904];
    Rec_79f40 recs[1];
    void FUN_00079f40(Item_79f40 *p, int i2, int i3, int i4, int i5, int i6, int a7, int *cnt, int v9, int v10);
};
class Obj_7a200 {
  public:
    char pad[0x1920];
    int item;
    char rest[0x3f0 - 4];
};
struct Cell_7a230 {
    int id;
    int pad04;
    int row;
    int col;
    int count;
    char pad14[0x2c - 0x14];
    char active;
    char pad2d[0x48 - 0x2d];
};
struct Rng_7a230 {
    unsigned int a;
    unsigned int b;
};
struct Grid_7a230 {
    char pad0[0x191c];
    Cell_7a230 cells[0x400];
    int FUN_0007a230(int idA, int idB, int rowIdx, int span);
};
struct Cell_7a3b0 {
    int a;
    int b;
    char pad[0x1c];
    char flag;
    char pad2[0x23];
};
class G_7a3b0 {
  public:
    char pad[0x1924];
    Cell_7a3b0 cells[1];
    void Fn(int x, int y, int* o1, int* o2);
};
struct Record_7a840;
struct Shape_7a840 {
    char data[56];
    bool FUN_0022d2b0(Record_7a840* other, float tolerance);
};
struct Record_7a840 {
    char prefix[12];
    Shape_7a840 shape;
    unsigned char active;
    char padding[3];
};
struct Owner_7a840 {
    char prefix[0x1904];
    Record_7a840 records[7][14];
    void FUN_0007a840(int group, int index, int* foundGroup, int* foundIndex);
};
struct Resolver_7ac30 {
    void FUN_001dd930(int id, Name *out) throw();
};
struct Owner_7ac30 {
    char pad0[0xc];
    Resolver_7ac30 *resolver;         // 0xc
};
struct Item_7ac30 {
    char pad0[0x10];
    int id;                     // 0x10
};
class Scene_7ac30 {
public:
    char pad0[0x3800];
    Item_7ac30 *items[1];             // 0x3800
    char pad3804[0x3828 - 0x3804];
    int count;                  // 0x3828
    Owner_7ac30 *owner;               // 0x382c

    int FUN_0007ac30(const Name *key);
};
struct V3_7afb0 {
    float x, y, z;
};
struct Matrix {
  public:
    float m[16];
    void FUN_0022b980();
    void FUN_0022ba70(float angle);
    void FUN_0022c3b0(const V3_7afb0* in, V3_7afb0* out);
};
struct Cell_7afb0 {
    V3_7afb0 b2;
    V3_7afb0 b1;
    int z;
    int key;
    char pad20[8];
    int cnt;
    int pad2c[3];
    int f38;
    int f3c;
    int f40;
    int f44;
};
struct Frame_7afb0 {
    float fu;
    int turn;
    float fx;
    int pad0c;
    float fz;
    unsigned int dir;
    Matrix m1;
    Matrix m2;
};
class Grid_7afb0 {
public:
    int tbl[0x1904 / 4];
    Cell_7afb0 cells[98];

    int FUN_00079190(int a, int b);
    void FUN_0007afb0(int row, int col, int n, int swap, V3_7afb0* p1, V3_7afb0* p2);
};
class Param {
  public:
    virtual void Prepare();
    virtual void Destroy();
    int unused;
    int a;
    int b;
};
class Owner_7b380 {
  public:
    char pad[0x354c];
    Param* entries[20];
    int count;
    int Find_00079220(int, int);
    void Add(Param* p);
};
struct Entry_7b3e0 {
    char pad0[0x1c];
    int groupId;            // 0x1c (only meaningful in a group's first entry)
    char pad20[0xc];
    int count;              // 0x2c
    int counts[6];          // 0x30
};
struct Group_7b3e0 {
    Entry_7b3e0 entries[14];
};
class Item_7b3e0 {
public:
    virtual void v0();
    virtual void Release();
    char pad04[0xbc - 4];
    int groupId;            // 0xbc
    int entryIndex;         // 0xc0
    char padc4[4];
    int countIndex;         // 0xc8
};
class Manager_7b3e0 {
public:
    char pad0[0x1904];
    Group_7b3e0 groups[7];        // 0x1904
    char pad_after[0x354c - 0x1904 - sizeof(Group_7b3e0) * 7];
    Item_7b3e0 *items[20];        // 0x354c
    int itemCount;          // 0x359c
    void FUN_0007b3e0(int idx);
};
class Thing_7b480 {
  public:
    char pad[0x359c];
    int count;
    void step_0007b3e0(int);
};
struct Raw3_7b4f0 {
    int a;
    int b;
    int c;
};
class Tracker_7b4f0 {
public:
    char pad00[0x10];
    int state;
    char pad14[0x38 - 0x14];
    int f38;
    int f3c;
    void FUN_00084920(Raw3_7b4f0 d1, Raw3_7b4f0 d2, Raw3_7b4f0 d3);
};
struct Cell_7b4f0 {
    Raw3_7b4f0 b2;
    Raw3_7b4f0 b1;
    int z;
    int key;
    char pad20[8];
    int cnt;
    char pad2c[0x48 - 0x2c];
};
struct Flags_7b4f0 {
    unsigned char a;
    unsigned char b;
};
class Grid_7b4f0 {
public:
    char pad0000[0x1904];
    Cell_7b4f0 cells[98];
    Flags_7b4f0 flags[7];
    char pad34a2[0x374c - 0x34a2];
    Tracker_7b4f0* objs[8];

    int FUN_0007a200(int key);
    int FUN_0007a230(int a, int b, int c, int d);
    void FUN_0007a3b0(int a, int b, int* out1, int* out2);
    void FUN_0007b4f0(int idx);
};
class Obj_7b820 {
  public:
    virtual void A();
    virtual void B();
};
class C_7b820 {
  public:
    char pad[0x374c];
    Obj_7b820* items[20];
    int count;
    int total;
    int F(Obj_7b820* p);
};
struct Item72 {
    int count;
    char pad[0x44];
};
struct Target_7b880 {
    void FUN_001e5bc0(int arg);
};
struct Mgr_7b880 {
    char pad[0xc];
    Target_7b880* target;
};
class Obj_7b9c0 {
  public:
    char pad[0x379c];
    int count;
    void remove_0007b880(int);
    void target();
};
class Item_7b9f0 {
public:
};
class Obj_7b9f0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Manager_7b9f0 {
public:
    char pad0[0x374c];
    Item_7b9f0* items[20];
    char pad379c[0x37ac - 0x379c];
    Obj_7b9f0* objs[20];
    int FUN_00079800(int key);
    void FUN_0007b9f0(int key);
};
class Item_7ba60 {
  public:
    virtual void A();
    virtual void Release();
};
class Owner_7ba60 {
    char pad[0x374c];
    Item_7ba60* indexed[24];
    Item_7ba60* items[20];

  public:
    void Remove(int n);
};
struct Cell_7bac0 { int id; char pad04[8]; int count; char pad10[56]; };
struct Group_7bac0 { Cell_7bac0 cells[14]; };
struct Flags_7bac0 { unsigned char first, second; };
struct Manager_7bac0 {
    char pad00[0x1920];
    union {
        Group_7bac0 groups[7];
        struct { char padToFlags[0x1b72]; Flags_7bac0 flags[8]; } flagView;
    };
    char pad34b0[0x268];
    union {
        int categoryCounts[13];
        struct { char padToBefore[48]; Object* before; } tailView;
    };
    Object* objects[20];
    int count;
    int FUN_00079800(int key);
    int remove(int key);
};
struct Mat4_7bbd0;
struct Vec3_7bbd0 {
    float x, y, z;
};
struct Mat4_7bbd0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(Vec3_7bbd0* axis, float angle);
};
struct Tile_7bbd0 {
    short id;
    char active;
    char pad03;
    int bits;
};
struct EntryTail {
    Vec3_7bbd0 b;
    int pad18;
    int owner;
    int p;
    int q;
    char pad28[0x1c];
    char on;
    char pad45[3];
};
struct Entry_7bbd0 {
    Vec3_7bbd0 a;
    EntryTail t;
};
struct Flags_7bbd0 {
    char a;
    char b;
};
struct Cfg_7bbd0 {
    float a, b, c, d;
    char on;
    char pad[3];
};
struct Frame_7bbd0 {
    int count;
    int l14;
    EntryTail* cur;
    int l1c;
    int tmp20;
    int slotBase;
    Vec3_7bbd0 pos;
    Vec3_7bbd0 axis;
    Mat4_7bbd0 mat;
    Cfg_7bbd0 cfg[7];
};
class HexBoard {
public:
    Tile_7bbd0 tiles[800];
    char pad1900[4];
    Entry_7bbd0 entries[98];
    Flags_7bbd0 flags[7];

    void FUN_00079990(Cfg_7bbd0* cfg, int a2, int a3, int a4, int a5, int a6, int slot, int* out, int a9, int a10);
    void FUN_00079c80(Cfg_7bbd0* cfg, int a2, int a3, int a4, int a5, int a6, int slot, int* out, int a9, int a10);
    void FUN_00079f40(Cfg_7bbd0* cfg, int a2, int a3, int a4, int a5, int a6, int slot, int* out, int a9, int a10);
    void FUN_0007a840(int slot, int k, int* a, int* b);
    void FUN_0007bbd0(int idx);
};
struct V3_7bf80 {
    float x, y, z;
    char FUN_0022d2b0(const V3_7bf80 *other, float eps);
};
struct Rec_7bf80 {
    char pad0[0x18];
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int cnt;
    int hist[4];
    int f40;
    char active;
    char pad45[3];
};
struct XObj_7bf80 {
    char pad0[0x14];
    int count;
    int FUN_00106160(int idx);
};
struct Obj18_7bf80 {
    XObj_7bf80 *FUN_00106210(int id);
};
struct P382c {
    char pad0[0x18];
    Obj18_7bf80 *p18;
};
struct Item_7bf80 {
    char pad0[0x10];
    int type;
    char pad14[0x20 - 0x14];
    int i20;
    char pad24[0x28 - 0x24];
    unsigned int f28;
    char pad2c[0x64 - 0x2c];
    V3_7bf80 v64;
    char pad70[0xbc - 0x70];
    int ibc;
    int ic0;
    int ic4;
    int ic8;
    int icc;
    char padd0[0xdc - 0xd0];
    V3_7bf80 vdc;
    void FUN_00080ea0(void *dst, void *src);
    void FUN_00080f20(int a);
    void FUN_00080cb0(int a);
    void FUN_00080f40(int a);
    void FUN_00080f00(int a);
    void FUN_00080f10(int a);
    void FUN_00080ef0(int a);
};
class Anim_7bf80 {
public:
    char pad0[0x1904];
    char recsRaw[0x354c - 0x1904];
    Item_7bf80 *items[8];
    char pad356c[0x382c - 0x356c];
    P382c *p382c;
    int FUN_0007a200(int a);
    void FUN_0007afb0(int g, int to, int slot, int icc, void *out1, void *out2);
    Rec_7bf80 *R(int i) { return (Rec_7bf80 *)(recsRaw) + i; }
    void F(int idx);
};
struct V3_7c930 {
    float x, y, z;
    void FUN_0022d180();
};
struct Mat_7c930 {
    float m[16];
};
struct Body_7c930 {
    char pad0[0x34];
    int id;
};
struct Lookup_7c930 {
    void FUN_001dd520(int id, Mat_7c930* out);
};
struct Env_7c930 {
    char pad0[0xc];
    Lookup_7c930* lookup;
};
class Group_7c930 {
public:
    char pad0[0x374c];
    Body_7c930* bodies[20];
    int count;
    char pad37a0[0x382c - 0x37a0];
    Env_7c930* env;
    bool FUN_0007c930(V3_7c930 pos, int skip);
};
struct Vec3_7cab0 { float x, y, z; };
struct Item_7cab0 {
    char pad0[0x10];
    int type;
    char pad14[0x20];
    int id;
};
struct Position_7cab0 {
    void FUN_00059a50(Vec3_7cab0 *out);
};
class Entity {
  public:
    virtual void _m_vf0();
    virtual void v1();
    char _m_pad_4[0xc];
    union { int kind; Position_7cab0 *position; };
    char _m_pad_14[0x20];
    int arg34;
    int key;
    int row;
    char _m_pad_40[0x1c];
    int category;
};
class Pool_7b880 {
public:
    void run(int slot);
    char p0[0x3718];
    int counters[12];
    Entity* stack0;
    Entity* slots[20];
    int depth;
    char p4[12];
    Entity* active[20];
    char p5[0x382c - (0x37ac + 80)];
    Mgr_7b880* mgr;
};
struct Holder_7cab0 {
    char pad0[0x124];
    Entity *entity;
};
struct Manager_7cab0 {
    bool FUN_001dd800(int id);
    void FUN_001dda30(int id, int flag);
    bool FUN_001df4c0(int id);
    bool FUN_001dd520(int id, Matrix *out);
};
struct Context {
    char pad0[0xc];
    Manager_7cab0 *manager;
    char pad10[0x10];
    Holder_7cab0 *holder;
};
class Group_7cab0 {
public:
    char pad0[0x374c];
    Item_7cab0 *items[20];
    int count;
    char pad37a0[0x8c];
    Context *context;
    void FUN_0007cab0(int limit);
};
class Item_7cc40 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
};
class Manager_7cc40 {
  public:
    char pad[0x3800];
    Item_7cc40* slots[10];
    int count;
    int Search_0007abe0(int, int);
    void Add(Item_7cc40* item);
};
class Item_7ccf0 {
  public:
    virtual void F();
    virtual void G();
};
class Obj_7ccf0 {
    char pad[0x3800];
    Item_7ccf0* slots[10];

  public:
    int count;
    void Remove(int);
};
class Obj_7cdb0 {
  public:
    void Process_001e5bc0(int);
};
class Holder_7cdb0 {
  public:
    char pad[0xc];
    Obj_7cdb0* mObj;
};
class Thing_7cdb0 {
  public:
    char pad[0x3800];
    int* mPtr;
    char pad2[0x24];
    int mCount;
    Holder_7cdb0* mHolder;
    void Run();
    void Cleanup_0007ccf0(int);
};
typedef unsigned int u32_7ce10;
class Function_7cfc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class CAmbientsManager_7cfc0 {
  public:
    void invoke(const char*, bool);
};
class CActorManager_7d040 {
  public:
    void f();
};
class CAmbientsManager_7d0d0 {};
struct AmbientArgs { const char* name; int value; unsigned char enabled; };
class Function_7d0d0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Dummy_7d150 {
  public:
    void Call(void*);
};
class Dummy_7d1d0 {
  public:
    void Call(void*);
};
class Dummy_7d250 {
  public:
    void Call(void*);
};
class CFEManager_7d2e0 {
  public:
    void Call(const char*, int);
};
class Function_7d2e0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_7d360 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_7d360::*MFn_7d360)(unsigned char);
class Function_7d360 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" char DAT_003ff014[];
extern const char hulk_at_0048e10c[];
class Function_7d380 {
  public:
    void Init_001d0480(const char*, int);
};
class Owner_7d380 {};
typedef void (Owner_7d380::*Fn_7d380)();
class Method4_7d380 : public Function_7d380 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_7d380 member1c;
    Method4_7d380(const char*, Fn_7d380);
};
} // namespace fn_f9399ba1
namespace math {
struct Vector_7d410 {
    float x, y, z;
};
}
namespace fn_f9399ba1 {
struct CAmbientsManager_7d410 {
    void f(const char*, int, const math::Vector_7d410, const math::Vector_7d410);
};
struct Function_7d410 {
    virtual void v0();
    virtual void v1();
};
struct CAmbientsManager_7d500 { void FUN_0007d500(const char *, unsigned int, float); };
struct Args { const char *name; unsigned int value; float amount; };
class CFEManager_7d590 {
  public:
    void Call(const char*, int);
};
class Function_7d590 {
  public:
    virtual void f0();
    virtual void f1();
};
class Obj_7d5b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Mgr_7d5b0 {
  public:
    void Reset();
    void FnA_0007b3e0(int);
    void FnB_0007b880(int);
    void FnC_0007cdb0();
    char pad0[0xb];
    char flags[0x320 * 8];
    char pad1[0x3548 - 0xb - 0x320 * 8];
    int v3548;
    char pad2[0x359c - 0x354c];
    int v359c;
    char pad3[0x3640 - 0x35a0];
    int v3640;
    char pad4[0x3740 - 0x3644];
    int v3740;
    char pad5[0x379c - 0x3744];
    int v379c;
    char pad6[0x37ac - 0x37a0];
    Obj_7d5b0* objs[20];
    int v37fc;
    char pad8[0x3828 - 0x3800];
    int v3828;
};
struct Pair_7da40 {
    int a;
    int b;
};
struct Obj_7da40 {
    int first_000797b0(int, int);
    void second_0007b880(int);
    void target(Pair_7da40*);
};
struct Group_7da70 { char pad[0x59c]; int id;  };
struct Resolver_7da70 {  };
struct Owner_7da70 { char pad[0x54]; Resolver_7da70* resolver; };
struct Slot_7da70 { int id; char pad[0x3ec]; };
struct Item_7da70 { char pad[0x10]; int type; char pad2[0x24]; int id; };
struct State_7da70 { char pad[0x1920]; Slot_7da70 slots[7]; char pad2[0x374c-0x1920-7*0x3f0]; Item_7da70* items[20]; int count; char pad3[0x382c-0x37a0]; Owner_7da70* owner; int current; void FUN_0007b880(int index); void FUN_0007bbd0(int id); void target(int unused); };
struct V3_7db80 {
    float x, y, z;
};
struct Rng_7db80 {
    unsigned int a;
    unsigned int b;
};
static inline unsigned int NextRandom()
{
    Rng_7db80 *r = (*(Rng_7db80**)&DAT_004e5acc);
    r->a = (r->a & 0xffff) * 0x9069 + (r->a >> 16);
    r->b = (r->b & 0xffff) * 0x4650 + (r->b >> 16);
    return (r->a << 16) + (r->b & 0xffff);
}
struct Ref_7db80 {
    void FUN_00059a50(V3_7db80 *out);
};
struct Level3_7db80 {
    char pad[0x10];
    Ref_7db80 *ref;
};
struct Level2_7db80 {
    char pad[0x124];
    Level3_7db80 *inner;
};
struct Level1_7db80 {
    char pad[0x20];
    Level2_7db80 *next;
};
struct Item_7db80 {
    V3_7db80 a;
    V3_7db80 b;
    int f18;
    int count;
    int u;
    int v;
    int state;
    char pad2c[0x44 - 0x2c];
    bool flag;
    char pad45[3];
};
class Spawner_7db80 {
public:
    char pad0[0x1904];
    Item_7db80 items[98];
    char pad_rest[0x382c - 0x1904 - sizeof(Item_7db80) * 98];
    Level1_7db80 *owner;

    bool FUN_0007c5b0(V3_7db80 a, V3_7db80 b);
    bool FUN_0007c930(V3_7db80 a, int x);
    void FUN_0007db80(int *outSlot, int *outItem);
};
class Function_7dfa0 : public ScriptFunctionFields {
  public:
    Function_7dfa0(const char*, int);
    virtual void f();
};
class Owner_7dfa0 {};
typedef void (Owner_7dfa0::*Fn_7dfa0)();
class Method2_7dfa0 : public Function_7dfa0 {
  public:
    Method2_7dfa0(const char*, Fn_7dfa0);
    virtual void f();
    Fn_7dfa0 arg;
};
class Closure2_7dfa0 : public Method2_7dfa0 {
  public:
    virtual void f();
    Owner_7dfa0* extra;
    Closure2_7dfa0(const char*, Owner_7dfa0*, Fn_7dfa0);
};
inline Method2_7dfa0::Method2_7dfa0(const char* s, Fn_7dfa0 v) : Function_7dfa0(s, 2) {
    arg = v;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
}
struct Arg_7e020 {
    const char* s;
    unsigned char b;
};
class Actor_7e020 {
  public:
    void invoke(const char*, unsigned char);
};
class CActorManager_7e0a0 {
  public:
    void run();
};
class CActorManager_7e190 {
  public:
    void invoke(const char*);
};
class CActorManager_7e220 {
  public:
    void invoke(const char*);
};
class CActorManager_7e2b0 {
  public:
    void invoke(const char*);
};
class CActorManager_7e350 {
  public:
    void Method(const char*, float);
};
struct Pair_7e350 {
    const char* s;
    float f;
};
class Actor_7e3e0 {
  public:
    void fn(unsigned char);
};
struct CAmbientsManager_7e4b0 {};
struct AmbientArguments {
    const char *name;
    unsigned int id;
    float volume;
};
class CActorManager_7e550 {
  public:
    void Method(const char*, float);
};
struct Pair_7e550 {
    const char* s;
    float f;
};
} // namespace fn_f9399ba1
namespace math {
class Vector_7e9f0 { public: float x, y, z; };
}
namespace fn_f9399ba1 {
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f9399ba1
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f9399ba1 {
class CAmbientsManager_7e9f0 {};
typedef void (CAmbientsManager_7e9f0::*Fn_7e9f0)(const char*, int, bool, math::Vector_7e9f0, math::Vector_7e9f0);
class Registry_7e9f0 { public:
    void FUN_0007e9f0(const char* a1, CAmbientsManager_7e9f0* a2, Fn_7e9f0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5_7e9f0;
template<> class Closure5_7e9f0<CAmbientsManager_7e9f0, void, const char*, int, bool, math::Vector_7e9f0, math::Vector_7e9f0> : public ScriptFunctionFields { public: virtual void v(); Fn_7e9f0 fn; CAmbientsManager_7e9f0* owner; Closure5_7e9f0(CAmbientsManager_7e9f0* o) { owner = o; } };
class Raw_7e9f0 { public: void FUN_0007ce30(const char*, Fn_7e9f0); };
class CAmbientsManager_7eb10 {};
typedef void (CAmbientsManager_7eb10::*Fn_7eb10)(const char*, int, bool);
class Registry_7eb10 { public:
    void FUN_0007eb10(const char* a1, CAmbientsManager_7eb10* a2, Fn_7eb10 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_7eb10;
template<> class Closure3_7eb10<CAmbientsManager_7eb10, void, const char*, int, bool> : public ScriptFunctionFields { public: virtual void v(); Fn_7eb10 fn; CAmbientsManager_7eb10* owner; Closure3_7eb10(CAmbientsManager_7eb10* o) { owner = o; } };
class Raw_7eb10 { public: void FUN_0007d050(const char*, Fn_7eb10); };
} // namespace fn_f9399ba1
namespace math {
class Vector_7ed00 { public: float x, y, z; };
}
namespace fn_f9399ba1 {
class CAmbientsManager_7ed00 {};
typedef void (CAmbientsManager_7ed00::*Fn_7ed00)(const char*, int, const math::Vector_7ed00, const math::Vector_7ed00);
class Registry_7ed00 { public:
    void FUN_0007ed00(const char* a1, CAmbientsManager_7ed00* a2, Fn_7ed00 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_7ed00;
template<> class Closure4_7ed00<CAmbientsManager_7ed00, void, const char*, int, const math::Vector_7ed00, const math::Vector_7ed00> : public ScriptFunctionFields { public: virtual void v(); Fn_7ed00 fn; CAmbientsManager_7ed00* owner; Closure4_7ed00(CAmbientsManager_7ed00* o) { owner = o; } };
class Raw_7ed00 { public: void FUN_0007d380(const char*, Fn_7ed00); };
class CAmbientsManager_7ed60 {};
typedef void (CAmbientsManager_7ed60::*Fn_7ed60)(const char*, unsigned int, float);
class Registry_7ed60 { public:
    void FUN_0007ed60(const char* a1, CAmbientsManager_7ed60* a2, Fn_7ed60 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_7ed60;
template<> class Closure3_7ed60<CAmbientsManager_7ed60, void, const char*, unsigned int, float> : public ScriptFunctionFields { public: virtual void v(); Fn_7ed60 fn; CAmbientsManager_7ed60* owner; Closure3_7ed60(CAmbientsManager_7ed60* o) { owner = o; } };
class Raw_7ed60 { public: void FUN_0007d480(const char*, Fn_7ed60); };
struct V3_7efc0 {
    float x, y, z;
};
struct Mat4_7efc0 {
    float m[16];
};
class Ent_7efc0 {
public:
    virtual void addRef();
    virtual void release();
    char pad04[0xc];
    int f10;
    char pad14[0x30 - 0x14];
    int f30;
    int f34;
    char pad38[0x60 - 0x38];
    V3_7efc0 pos;                // 0x60
    void FUN_00084c40(int arg);
    char FUN_00083d10();
};
struct Anchor_7efc0 {
    char FUN_00059a50(V3_7efc0 *out);
};
struct Holder124_7efc0 {
    char pad0[0x10];
    Anchor_7efc0 *f10;
};
struct Holder20_7efc0 {
    char pad0[0x124];
    Holder124_7efc0 *f124;
};
struct Probe_7efc0 {
    char FUN_00201f20(V3_7efc0 *p, int one, V3_7efc0 *out1, V3_7efc0 *out2, int a, int b);
};
struct Target_7efc0 {
    void FUN_001d7510();
};
struct WorldSys_7efc0 {
    char FUN_001dd520(int id, Mat4_7efc0 *out);
    char FUN_001dda80(int id);
    char FUN_001dd9e0(int id);
};
struct Env_7efc0 {
    char pad0[0xc];
    WorldSys_7efc0 *f0c;
    char pad10[0x20 - 0x10];
    Holder20_7efc0 *f20;
    Probe_7efc0 *f24;
};
class Mgr_7efc0 {
public:
    char pad0[0x3740];
    int f3740;
    int f3744;
    int f3748;
    Ent_7efc0 *list[20];         // 0x374c
    int count;             // 0x379c
    char pad37a0[0x37ac - 0x37a0];
    Ent_7efc0 *ring[20];         // 0x37ac
    int head;              // 0x37fc
    char pad3800[0x382c - 0x3800];
    Env_7efc0 *env;              // 0x382c

    void FUN_0007b880(int i);
    void FUN_0007b4f0(int i);
    void FUN_0007ba60(int i);
    void FUN_0007cab0(int n);
    void FUN_0007efc0(int arg);
};
struct Frame_7efc0 {
    int removed;           // 0x10
    WorldSys_7efc0 *world;       // 0x14
    int pad18;
    int k;                 // 0x1c
    V3_7efc0 q;                  // 0x20
    V3_7efc0 pos;                // 0x2c
    V3_7efc0 g1;                 // 0x38
    V3_7efc0 g2;                 // 0x44
    Mat4_7efc0 mat;              // 0x50
};
typedef unsigned int U_80b70;
class Obj_80ba0 {
  public:
    float method_000787e0(unsigned int, unsigned int);
};
struct Vec3_80cd0 {
    float x, y, z;
};
struct Xform_80cd0 {
    char data[0x30];
    void FUN_0022cc90(Vec3_80cd0 *v);
};
class Pusher_80cd0 {
public:
    char pad00[0x10];
    int state;
    char pad14[0x28 - 0x14];
    unsigned int flags;
    char pad2c[0x34 - 0x2c];
    Xform_80cd0 xform;
    Vec3_80cd0 origin;
    char pad70[0xd0 - 0x70];
    Vec3_80cd0 prev;
    Vec3_80cd0 cur;
    void FUN_00080cd0(Vec3_80cd0 *dir, bool keep);
};
struct Block_80e50 {
    unsigned int x[16];
};
class Target_80e50 {
    char pad[0x34];

  public:
    void Copy(const Block_80e50* src);
};
struct Vec3_80ea0 {
    int a, b, c;
};
class Obj_80ea0 {
  public:
    char pad0[0x28];
    unsigned int flags;
    char pad2[0xd0 - 0x2c];
    int x[6];
    void Set(Vec3_80ea0* p, Vec3_80ea0* q);
};
struct Vec_80f60 { float x,y,z; };
struct Rotation_80f60 { float x,y,z,w;  void FUN_0022b650(Matrix*); };
extern "C" void __cdecl FUN_0022b080(Rotation_80f60*, const Rotation_80f60*, const Vec_80f60*);
struct First_80f60 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void query(int,int,Vec_80f60*); };
struct Second_80f60 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void query(int,Vec_80f60*); };


// 0x000788e0 FUN_000788e0 (11 B): matches/0x000788e0.cpp
// sym: ?Set@Thing_788e0@fn_f9399ba1@@QAEXXZ
void Thing_788e0::Set() {
    mValue = 0;
}


// 0x00078b20 FUN_00078b20 (30 B): matches/0x00078b20.cpp
// sym: ?target@fn_f9399ba1@@YIHPAVObject@1@@Z
// data: g_one_78b20 = DAT_00421894
int __fastcall target(Object* self) {
    return self->value == DAT_00421894;
}

} // namespace fn_f9399ba1

// 0x00078b40 FUN_00078b40 (7 B): matches/0x00078b40.cpp
// sym: ?FUN_00078b40@A_78b40@owners@@QAEPAXXZ
void* owners::A_78b40::FUN_00078b40() {
    return m59c;
}

namespace fn_f9399ba1 {

// 0x00078b70 FUN_00078b70 (12 B): matches/0x00078b70.cpp
// sym: ?Target@X_78b70@fn_f9399ba1@@QAEPAU12@XZ
// Same code shape as 0x00034ad0 (propagated; names are from that function)
X_78b70* X_78b70::Target() {
    Call_0027af00();
    return this;
}


// 0x00078b90 FUN_00078b90 (12 B): matches/0x00078b90.cpp
// sym: ?Target@X_78b90@fn_f9399ba1@@QAEPAU12@XZ
// Same code shape as 0x00034ad0 (propagated; names are from that function)
X_78b90* X_78b90::Target() {
    Call_0027af00();
    return this;
}

} // namespace fn_f9399ba1

// 0x00078bc0 FUN_00078bc0 (103 B): matches/0x00078bc0.cpp [wrapped: conflict: CAmbientsManager; DataHandler::ObjectCreator]
// sym: ??1CAmbientsManager@fn_00078bc0@@UAE@XZ
namespace fn_00078bc0 {
struct Elem_78bc0 {
    void FnD_0027af50();
};
struct E16 {
    char p[16];
};
struct E8 {
    char p[8];
};
namespace DataHandler {
class ObjectCreator {
  public:
    virtual void f();
    virtual ~ObjectCreator() throw() {}
};
} // namespace DataHandler
class CAmbientsManager : public DataHandler::ObjectCreator {
  public:
    virtual void f();
    virtual ~CAmbientsManager() throw();
    char pad[0x34a8 - 4];
    E16 a[10];
    char pad2[0x35a0 - 0x3548];
    E8 b[20];
    E16 c[10];
};
CAmbientsManager::~CAmbientsManager() throw() {
    E16* p = (E16*)((char*)this + 0x36f0);
    int i = 10;
    do {
        p--;
        ((Elem_78bc0*)p)->FnD_0027af50();
        i--;
    } while (i != 0);
    E8* q = (E8*)((char*)this + 0x3640);
    i = 20;
    do {
        q--;
        ((Elem_78bc0*)q)->FnD_0027af50();
        i--;
    } while (i != 0);
    p = (E16*)((char*)this + 0x3548);
    i = 10;
    do {
        p--;
        ((Elem_78bc0*)p)->FnD_0027af50();
        i--;
    } while (i != 0);
}
} // namespace fn_00078bc0


// 0x00078c30 CAmbientsManager::vfunc_2 (6 B): matches/0x00078c30.cpp
// sym: ?vfunc_2@CAmbientsManager@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int CAmbientsManager::vfunc_2() {
    return 1;
}


// 0x00078c40 CAmbientsManager::vfunc_3 (8 B): matches/0x00078c40.cpp [wrapped: conflict: CAmbientsManager; CDHGameObjectCreator]
// sym: ?vfunc_3@CAmbientsManager@fn_00078c40@@UAEPBDPAX@Z
namespace fn_00078c40 {
// data: gWaypoint = DAT_003fef18

class CDHGameObjectCreator {
    char a[4];
};
class DataHandler {
  public:
    class ObjectCreator {
        char b[4];
    };
};
class CAmbientsManager : public CDHGameObjectCreator, public DataHandler::ObjectCreator {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual const char* vfunc_3(void*);
};
const char* CAmbientsManager::vfunc_3(void*) {
    return ((char*)&DAT_003fef18);
}
} // namespace fn_00078c40


// 0x00078c50 FUN_00078c50 (13 B): matches/0x00078c50.cpp
// sym: ?FUN_00078c50@C_78c50@owners@@QAEXH@Z
void owners::C_78c50::FUN_00078c50(hulk_intptr x) {
    value = ((int)x);
}

namespace fn_f9399ba1 {

// 0x00078c60 FUN_00078c60 (1 B): matches/0x00078c60.cpp
// sym: ?FUN_00078c60@fn_f9399ba1@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00078c60() {}

} // namespace fn_f9399ba1

// 0x00078c70 CAmbientsManager::vfunc_1 (133 B): equivalent/0x00078c70.cpp [wrapped: conflict: CAmbientsManager]
// sym: ?vfunc_1@CAmbientsManager@fn_00078c70@@QAE_NTArg_78c70@2@@Z @941f60c7ca72 @w345f026c450f
namespace fn_00078c70 {
// STATUS: equivalent (tools/equiv.py level 3: 769 inputs, branch coverage 6/6)
// CAmbientsManager::vfunc_1 @ 0x00078c70
struct Parser_78c70 {
    void FUN_00336690(const char *name, int *out);
    void FUN_003366f0(const char *name, int index, int *out);
};

union Arg_78c70 {
    Parser_78c70 *parser;
    int count;
};

struct OrientSlot {
    int bits;
    short orient;
    char valid;
    char pad07;
};

class CAmbientsManager {
public:
    virtual void vfunc_0();
    OrientSlot slots[0x320];
    bool vfunc_1(Arg_78c70 arg);
};

bool CAmbientsManager::vfunc_1(Arg_78c70 arg)
{
    Parser_78c70 *parser = arg.parser;
    int orientCount;
    int tmp;
    parser->FUN_00336690("Orients", &arg.count);
    parser->FUN_00336690("BitDef", &orientCount);
    for (int i = 0; i < arg.count && i < orientCount; i++) {
        parser->FUN_003366f0("BitDef", i, &slots[i].bits);
        parser->FUN_003366f0("Orients", i, &tmp);
        slots[i].orient = (short)tmp;
        slots[i].valid = 1;
        if (i + 1 >= 0x320)
            break;
    }
    return true;
}
} // namespace fn_00078c70

namespace fn_f9399ba1 {

// 0x00078d00 FUN_00078d00 (13 B): matches/0x00078d00.cpp
// sym: ?Set@C_78d00@fn_f9399ba1@@QAEXD@Z
void C_78d00::Set(char value) {
    m364c = value;
}


// 0x00078d20 FUN_00078d20 (441 B): equivalent/0x00078d20.cpp
// sym: ?FUN_00078d20@Pool_78d20@fn_f9399ba1@@QAE_NHHPAH0@Z @3b88ea3919ed @w9c61b706c9ad
// STATUS: equivalent (tools/equiv.py level 3: 47 inputs, branch coverage 24/24)
// FUN_00078d20 @ 0x00078d20
bool Pool_78d20::FUN_00078d20(int a, int b, int *pIdx, int *pSub)
{
    Rng_78d20 *r = FUN_000964d0();
    r->s0 = 36969 * (r->s0 & 0xffff) + (r->s0 >> 16);
    r->s1 = 18000 * (r->s1 & 0xffff) + (r->s1 >> 16);
    *pIdx = ((r->s0 << 16) + (r->s1 & 0xffff)) % count;

    r->s0 = 36969 * (r->s0 & 0xffff) + (r->s0 >> 16);
    r->s1 = 18000 * (r->s1 & 0xffff) + (r->s1 >> 16);
    *pSub = ((r->s0 << 16) + (r->s1 & 0xffff)) % recs[*pIdx].count;

    if (count <= 0)
        return false;
    int i = 0;
    do {
        int sum = 0;
        for (int k = 0; k < *pIdx; k++)
            sum += recs[k].count;
        int m = recs[*pIdx].count;
        for (int j = 0; j < m; j++) {
            int k = 0;
            for (; k < slotCount; k++) {
                Slot_78d20 *s = slots[k];
                if (s->keyA == a && s->keyB == b && s->f18 == *pSub + sum)
                    break;
            }
            if (k == slotCount)
                return true;
            *pSub = (*pSub + 1) % m;
        }
        *pIdx = (*pIdx + 1) % count;
        i++;
    } while (i < count);
    return false;
}


// 0x00078ee0 FUN_00078ee0 (592 B): equivalent/0x00078ee0.cpp
// sym: ?FUN_00078ee0@Walker_78ee0@fn_f9399ba1@@QAEXPAUVec3_78ee0@2@0@Z @7f0c805bf7a7 @wbe1e578de0a3
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 6/6)
// FUN_00078ee0 @ 0x00078ee0
void Walker_78ee0::FUN_00078ee0(Vec3_78ee0 *argA, Vec3_78ee0 *argB)
{
    // the argument slots double as scratch floats in the original frame
    float *slotA = (float *)&argA;
    float *slotB = (float *)&argB;
    Vec3_78ee0 *a = argA;
    Vec3_78ee0 *b = argB;
    Vec3_78ee0 cur;
    owner->ref->ref->anchor->FUN_00059a50(&cur);

    Vec3_78ee0 da;
    da.x = cur.x - a->x;
    da.y = 0;
    da.z = cur.z - a->z;
    float lenA = da.FUN_0022d110();

    Vec3_78ee0 db;
    db.x = cur.x - b->x;
    db.y = 0;
    db.z = cur.z - b->z;
    float lenB = db.FUN_0022d110();

    if (lenB > DAT_0049b898 && lenA > DAT_0049b898) {
        Vec3_78ee0 t;
        t.x = b->x - a->x;
        t.y = b->y - a->y;
        t.z = b->z - a->z;
        t.FUN_0022d110();
        a->x = b->x;
        a->y = b->y;
        a->z = b->z;
        a->x = a->x - t.x;
        a->y = a->y - t.y;
        a->z = a->z - t.z;
        return;
    }

    Vec3_78ee0 dir;
    if (lenB > lenA) {
        dir.x = -db.x;
        dir.y = -db.y;
        dir.z = -db.z;
    } else {
        dir.x = -da.x;
        dir.y = -da.y;
        dir.z = -da.z;
    }

    Vec3_78ee0 p0;
    p0.x = dir.x * DAT_0049b898 + cur.x;
    p0.y = dir.y * DAT_0049b898 + cur.y;
    p0.z = dir.z * DAT_0049b898 + cur.z;

    // dir x (0, 1, 0)
    Vec3_78ee0 side;
    *slotA = dir.y * 0.0f;
    side.x = *slotA - dir.z;
    side.y = dir.z * 0.0f - dir.x * 0.0f;
    side.z = dir.x * 1.0f - dir.y * 0.0f;

    FUN_0022d550(&p0, &side, a, b, slotB, slotA);
    float t = *slotA;

    Vec3_78ee0 w;
    w.x = b->x - a->x;
    w.y = b->y - a->y;
    w.z = b->z - a->z;
    w.FUN_0022d110();
    a->x = w.x * t + a->x;
    a->y = w.y * t + a->y;
    a->z = w.z * t + a->z;
}


// 0x00079130 FUN_00079130 (86 B): equivalent/0x00079130.cpp
// sym: ?FUN_00079130@fn_f9399ba1@@YAPAUPosition@1@HPAU21@@Z @9f3753d505e7 @w0f9ebb7abe44
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00079130 @ 0x00079130
// equiv-conv: FUN_00079130 eax esi
Position * FUN_00079130(int index, Position *result)
{
    int quotient = (index - 1) / 30;
    int remainder = (index - 1) % 30;
    int parity = remainder % 2;
    int row = -2 * quotient - (parity != 0);
    result->y = 0.0f;
    result->x = (float)row * (*(float*)&DAT_003fef3c);
    result->z = ((float)remainder - (*(float*)&DAT_003f32f4)) * (*(float*)&DAT_003fef38);
    return result;
}


// 0x00079190 FUN_00079190 (141 B): matches/0x00079190.cpp
// sym: ?FUN_00079190@fn_f9399ba1@@YGIHH@Z
// FUN_00079190 @ 0x00079190
// Maps a (from, to) pair of states to a transition id.
unsigned int __stdcall FUN_00079190(int from, int to) {
    if (from == 0) {
        if (to == 1) return 0;
        return to != 0 ? 2 : 5;
    }
    if (from == 2) {
        if (to == 1) return 5;
        return to != 0 ? 2 : 0;
    }
    if (from == 1) {
        if (to == 1) return 1;
        return to == 0 ? 6 : 4;
    }
    if (from == 3) {
        if (to == 1) return 6;
        return to != 0 ? 4 : 1;
    }
    return 3;
}


// 0x00079220 FUN_00079220 (66 B): equivalent/0x00079220.cpp
// sym: ?FUN_00079220@Owner@fn_f9399ba1@@QAEHHH@Z @041e1192b513 @wb31c9fb84eae
// STATUS: equivalent (tools/equiv.py level 3: 1712 inputs, branch coverage 8/8)
// FUN_00079220 @ 0x00079220
int Owner::FUN_00079220(int first, int second) { for (int i = 0; i < count; ++i) { if (entries[i]->first == first && entries[i]->second == second) return i; } return -1; }


// 0x00079270 FUN_00079270 (7 B): matches/0x00079270.cpp
// sym: ?FUN_00079270@fn_f9399ba1@@YIIPAUTarget_79270@1@@Z
unsigned int __fastcall FUN_00079270(Target_79270* self) {
    return self->value;
}

} // namespace fn_f9399ba1

// 0x00079280 FUN_00079280 (14 B): matches/0x00079280.cpp
// sym: ?FUN_00079280@Target_79280@owners@@QAEHH@Z
hulk_intptr owners::Target_79280::FUN_00079280(int index) {
    return values[index];
}

namespace fn_f9399ba1 {

// 0x00079290 FUN_00079290 (11 B): matches/0x00079290.cpp
// sym: ?Clear@Obj_79290@fn_f9399ba1@@QAEXXZ
void Obj_79290::Clear() {
    value = 0;
}


// 0x000792a0 FUN_000792a0 (106 B): matches/0x000792a0.cpp
// sym: ?Add@Registry_792a0@fn_f9399ba1@@QAEXPBDHD@Z
// FUN_000792a0 @ 0x000792a0
void Registry_792a0::Add(const char* text, int value, char flag)
{
    Name_792a0 tmp;
    Name_792a0* t = tmp.FUN_0027b0e0(text);
    entries[count].name.FUN_0027af70(t);
    tmp.FUN_0027af50();
    entries[count].value = value;
    entries[count].flag = flag;
    count++;
}


// 0x00079310 FUN_00079310 (11 B): matches/0x00079310.cpp
// sym: ?SetZero@Obj_79310@fn_f9399ba1@@QAEXXZ
void Obj_79310::SetZero() {
    mValue = 0;
}

} // namespace fn_f9399ba1

// 0x00079320 FUN_00079320 (66 B): matches/0x00079320.cpp [wrapped: conflict: Item; Owner]
// sym: ?Add@Owner@fn_00079320@@QAEXPAX@Z
namespace fn_00079320 {
struct Item {
    hulk_intptr a, b;
    Item(void*) throw();
    void Assign_0027af70(const Item*) throw();
    ~Item() throw();
};
class Owner {
    char pad[0x35a0];
    Item items[20];
    int count;

  public:
    void Add(void*);
};
void Owner::Add(void* p) {
    Item t(p);
    items[count++].Assign_0027af70(&t);
}
} // namespace fn_00079320

namespace fn_f9399ba1 {

// 0x00079370 FUN_00079370 (17 B): matches/0x00079370.cpp
// sym: _FUN_00079370@4
// data: gValue_79370 = DAT_004dd040
extern "C" void __stdcall FUN_00079370(int v) {
    if (v <= 0x14)
        DAT_004dd040 = v;
}


// 0x00079390 FUN_00079390 (12 B): matches/0x00079390.cpp
// sym: _FUN_00079390@4
// data: hulk_at_0049b894 = DAT_0049b894
extern "C" void __stdcall FUN_00079390(int x) {
    *(int*)((hulk_intptr)((char*)&DAT_0049b894)) = x;
}


// 0x000793a0 FUN_000793a0 (17 B): matches/0x000793a0.cpp
// sym: _FUN_000793a0@4
// data: hulk_at_0049b8a0 = DAT_0049b8a0
extern "C" void __stdcall FUN_000793a0(float x) {
    float v = x * x;
    *(float*)((hulk_intptr)((char*)&DAT_0049b8a0)) = v;
}


// 0x000793c0 FUN_000793c0 (50 B): matches/0x000793c0.cpp
// sym: _FUN_000793c0@8
extern "C" void __stdcall FUN_000793c0(float x, float y) {
    DAT_0049b898 = x;
    (*(float*)&DAT_0049b89c) = y;
    DAT_0049b8e4 = x * x;
    DAT_0049b8e8 = y * y;
}


// 0x00079400 FUN_00079400 (31 B): matches/0x00079400.cpp
// sym: _FUN_00079400@8
extern "C" void __stdcall FUN_00079400(float a, float b) {
    DAT_0049b8a4 = a * a;
    DAT_0049b8a8 = b * b;
}


// 0x00079420 FUN_00079420 (21 B): matches/0x00079420.cpp
// sym: ?SetX@Obj_79420@fn_f9399ba1@@QAEXH@Z
void Obj_79420::SetX(int x) {
    if (x <= mLimit)
        mField = x;
}


// 0x00079440 FUN_00079440 (88 B): matches/0x00079440.cpp
// sym: ?SetScale@Obj_79440@fn_f9399ba1@@QAEXH@Z
void Obj_79440::SetScale(int p) {
    if (p <= 0x14) {
        float local = (float)p / (float)divv;
        for (int i = 0; i < count; ++i) {
            arr[i] = (int)(__int64)((float)arr[i] * local);
        }
        divv = p;
    }
}


// 0x000794a0 FUN_000794a0 (130 B): matches/0x000794a0.cpp
// sym: ?FUN_000794a0@SlotList_794a0@fn_f9399ba1@@QAEXPBDHM@Z
// FUN_000794a0 @ 0x000794a0
void SlotList_794a0::FUN_000794a0(const char *name, int value, float amount)
{
    Id64_794a0 id;

    // MSVC evaluates the argument before the object expression
    Id64_794a0 *src = id.FUN_0027b0e0(name);
    entries[count].id.FUN_0027af70(src);
    id.FUN_0027af50();
    entries[count].value = value;
    ints[count] = (int)(__int64)(scale * amount);
    zeros[count] = 0;
    count++;
}

} // namespace fn_f9399ba1

// 0x00079530 FUN_00079530 (23 B): matches/0x00079530.cpp
// sym: ?FUN_00079530@Obj_79530@owners@@QAE_KH@Z
u64_79530 owners::Obj_79530::FUN_00079530(int index) {
    return *(u64_79530*)((char*)this + (index + 0x365) * 16);
}

namespace fn_f9399ba1 {

// 0x00079550 FUN_00079550 (66 B): matches/0x00079550.cpp
// sym: ?Run@Thing@fn_f9399ba1@@QAEXM@Z
// data: gValue = DAT_0049b88c
void Thing::Run(float value) {
    (*(float*)&DAT_0049b88c) = value;
    for (int i = 0; i < count; ++i)
        items[i]->Set(value);
}

} // namespace fn_f9399ba1

// 0x000795a0 FUN_000795a0 (66 B): matches/0x000795a0.cpp [wrapped: conflict: DAT_0049b890]
// sym: ?Run@Obj@fn_000795a0@@QAEXM@Z
namespace fn_000795a0 {
extern "C++" { extern float DAT_0049b890; }
class Item {
  public:
    void Update_00083d70(float);
};
class Obj {
  public:
    char pad[0x374c];
    Item* items[20];
    int count;
    void Run(float);
};
void Obj::Run(float value) {
    DAT_0049b890 = value;
    for (int i = 0; i < count; ++i)
        items[i]->Update_00083d70(value);
}
} // namespace fn_000795a0

namespace fn_f9399ba1 {

// 0x000795f0 FUN_000795f0 (66 B): matches/0x000795f0.cpp
// sym: ?Run@Obj@fn_f9399ba1@@QAEXM@Z
void Obj::Run(float x) {
    hulk_at_0049b888 = x;
    for (int i = 0; i < count; i++)
        items[i]->Set(x);
}


// 0x00079640 FUN_00079640 (23 B): matches/0x00079640.cpp
// sym: ?Set@Target_79640@fn_f9399ba1@@QAEXHH@Z
void Target_79640::Set(int x, int y) {
    a = x;
    b = y;
}


// 0x00079660 FUN_00079660 (61 B): matches/0x00079660.cpp
// sym: ?f@C_79660@fn_f9399ba1@@QAEXH@Z
void C_79660::f(int p) {
    for (int i = 0; i < count; ++i)
        items[i]->call_00083d30(p);
}


// 0x000796a0 FUN_000796a0 (61 B): matches/0x000796a0.cpp
// sym: ?run@Owner_796a0@fn_f9399ba1@@QAEXM@Z
void Owner_796a0::run(float x) {
    for (int i = 0; i < count; ++i)
        items[i]->update_00083d30(x + items[i]->value);
}

} // namespace fn_f9399ba1

// 0x000797b0 FUN_000797b0 (66 B): equivalent/0x000797b0.cpp [wrapped: conflict: Owner]
// sym: ?FUN_000797b0@Owner@fn_000797b0@@QAEHHH@Z @da6d15d484f2 @w760d0f615c15
namespace fn_000797b0 {
// STATUS: equivalent (tools/equiv.py level 3: 1727 inputs, branch coverage 8/8)
// FUN_000797b0 @ 0x000797b0
struct Entry { char pad[8]; int first; int second; }; struct Owner { char pad[0x374c]; Entry* entries[20]; int count; int FUN_000797b0(int first, int second); }; int Owner::FUN_000797b0(int first, int second) { for (int i = 0; i < count; ++i) { if (entries[i]->first == first && entries[i]->second == second) return i; } return -1; }
} // namespace fn_000797b0

namespace fn_f9399ba1 {

// 0x00079800 FUN_00079800 (145 B): matches/0x00079800.cpp
// sym: ?FUN_00079800@Scene_79800@fn_f9399ba1@@QAEHPBUName@2@@Z
// FUN_00079800 @ 0x00079800
// equiv-map: ??0Name@@QAE@XZ = 0x0027af00
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
int Scene_79800::FUN_00079800(const Name *key)
{
    Name found;
    for (int i = 0; i < count; i++) {
        owner->resolver->FUN_001dd930(items[i]->id, &found);
        if (found.FUN_0027af90(key))
            return i;
    }
    return -1;
}

} // namespace fn_f9399ba1

// 0x000798a0 FUN_000798a0 (81 B): equivalent/0x000798a0.cpp [wrapped: conflict: Owner]
// sym: ?FUN_000798a0@Owner@fn_000798a0@@QAEPAUEntry@2@HH@Z @9fa21e1c64fd @w5ff11b28015d
namespace fn_000798a0 {
// STATUS: equivalent (tools/equiv.py level 3: 1727 inputs, branch coverage 8/8)
// FUN_000798a0 @ 0x000798a0
struct Entry { char pad[8]; int key1; int key2; }; struct Owner { char pad[0x374c]; Entry* entries[20]; int count; Entry* FUN_000798a0(int a, int b); }; Entry* Owner::FUN_000798a0(int a, int b) { for (int i=0; i<count; ++i) { Entry* e=entries[i]; if(e->key1==a && e->key2==b) return entries[i]; } return 0; }
} // namespace fn_000798a0


// 0x00079950 FUN_00079950 (46 B): matches/0x00079950.cpp
// sym: ?FUN_00079950@C_79950@owners@@QAE_NH@Z
bool owners::C_79950::FUN_00079950(hulk_intptr x) {
    int i = lookup(((int)x));
    if (i == -1)
        return false;
    return *(int*)((char*)arr[i] + 0x10) != 0x13;
}


// 0x00079980 FUN_00079980 (3 B): matches/0x00079980.cpp [wrapped: conflict: CAgent]
// sym: ?vfunc_7@CAgent@fn_00079980@@UAEXH@Z
namespace fn_00079980 {
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
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

void CAgent::vfunc_7(int a) {
    (void)a;
}
} // namespace fn_00079980

namespace fn_f9399ba1 {

// 0x00079990 FUN_00079990 (740 B): equivalent/0x00079990.cpp
// sym: ?FUN_00079990@Stage_79990@fn_f9399ba1@@QAEXPAUEntry_79990@2@HHHHHHPAHHH@Z @b727b90f0aab @w13ed0b370428
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 16/16)
// FUN_00079990 @ 0x00079990
void Stage_79990::FUN_00079990(Entry_79990 *tab, int a2, int a3, int a4, int a5, int a6, int a7, int *counter, int a9, int a10)
{
    Entry_79990 *a = &tab[a2];
    if (!a->active)
        return;

    float aBits = a->f0;
    float l1 = (float)((double)a5 * DAT_004dd048 * 90.0f);
    float l2 = (float)((double)DAT_004dd04c * a6);
    float l3 = (float)((double)DAT_004dd04c * a6 * 90.0f);

    Entry_79990 *x = &tab[a3];
    if (!x->active) {
        x = &tab[a4];
        if (!x->active)
            x = 0;
    }
    double v = 10.0f;
    if (x)
        v = (double)x->f8 * 2 + (double)x->f4 * 0.5f + x->fc + 10.0f;

    int parity = a2 % 2;
    double t = (double)a->f4 + a->f8 + 3.0f;
    float m = (float)(t * parity + aBits);

    double na = (double)(-a5) * DAT_004dd048;
    float n = (float)na;
    float p = (float)((double)l2 * m);
    float q = (float)(na * m + l1);
    float r = (float)((double)p + l3);

    Rec_79990 *r1 = &recs[*counter + a7 * 14];
    r1->f4 = 0;
    r1->f0 = q;
    r1->f8 = r;
    float w = (float)(a6 * v);
    r1->fc = r1->f0;
    r1->f10 = 0;
    r1->f14 = w;
    r1->f18 = a9;
    r1->f28 = 0;
    r1->f2c = 0;
    r1->f30[0] = 0;
    r1->f30[1] = 0;
    r1->f30[2] = 0;
    r1->f30[3] = 0;
    int first = 0;
    if (a2 == 0 || a2 == 1)
        first = 1;
    r1->f40 = first;
    r1->f44 = 1;
    ++*counter;

    int prod = a5 * a6;
    Rec_79990 *r2 = &recs[*counter + a7 * 14];
    double t2 = (double)a->f4 + a->f8 + 3.0f;
    r2->f10 = 0;
    double d = m - t2 * prod;
    float x1 = (float)(n * d);
    float x2 = (float)(l2 * d);
    r2->fc = x1 + l1;
    r2->f14 = x2 + l3;
    r2->f0 = r2->fc;
    r2->f4 = 0;
    r2->f8 = w;
    r2->f18 = a10;
    r2->f28 = 0;
    r2->f2c = 0;
    r2->f30[0] = 0;
    r2->f30[1] = 0;
    r2->f30[2] = 0;
    r2->f30[3] = 0;
    int second = 0;
    if (a2 != 0 && a2 != 1)
        second = 1;
    r2->f40 = second;
    r2->f44 = 1;
    ++*counter;
}


// 0x00079c80 FUN_00079c80 (691 B): equivalent/0x00079c80.cpp
// sym: ?FUN_00079c80@Mesh_79c80@fn_f9399ba1@@QAEXPAUItem_79c80@2@HHHHHHPAHHH@Z @37503b6a2386 @wf876043fba5c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00079c80 @ 0x00079c80
void Mesh_79c80::FUN_00079c80(Item_79c80 *p, int i2, int i3, int i4, int a5, int a6, int a7, int *cnt, int v9, int v10)
{
    Item_79c80 *it2 = &p[i2];
    if (it2->flag == 0)
        return;
    volatile float f5 = (float)a5;
    volatile float la = a5 * DAT_004dd048 * 90.0f;
    volatile float l18 = a6 * DAT_004dd04c * 90.0f;
    hulk_freg x = it2->f0;
    hulk_freg w = 35.0f;
    Item_79c80 *it3 = &p[i3];
    if (it3->flag != 0) {
        w = 35.0f - (it3->f8 + it3->f8 + it3->f4 * 0.5f + it3->fc);
    } else {
        Item_79c80 *it4 = &p[i4];
        if (it4->flag != 0)
            w = 35.0f - (it4->f8 + it4->f8 + it4->f4 * 0.5f + it4->fc);
    }
    int k = a7 * 14;
    int na5 = -a5;
    volatile float l2c = na5 * w;
    volatile float q = (it2->f4 + it2->f8 + 3.0f) * i3 + x;
    volatile float l24 = -q;
    hulk_freg a = la;
    recs[*cnt + k].f10 = 0;
    recs[*cnt + k].f0c = a;
    recs[*cnt + k].f14 = l24 + l18;
    hulk_freg r = DAT_004dd048 * l2c + la;
    recs[*cnt + k].f00 = r;
    recs[*cnt + k].f04 = 0;
    recs[*cnt + k].f08 = recs[*cnt + k].f14;
    recs[*cnt + k].f18 = v9;
    recs[*cnt + k].f28 = 0;
    recs[*cnt + k].f2c = 0;
    recs[*cnt + k].f30 = 0;
    recs[*cnt + k].f34 = 0;
    recs[*cnt + k].f38 = 0;
    recs[*cnt + k].f3c = 0;
    recs[*cnt + k].f40 = (i3 != 0) + 2;
    recs[*cnt + k].f44 = 1;
    *cnt = *cnt + 1;
    recs[*cnt + k].f10 = 0;
    hulk_freg t = (it2->f4 + it2->f8 + 3.0f) * f5;
    recs[*cnt + k].f00 = a;
    hulk_freg l24b = -(q - t);        // `fst [esp+0x24]`: the sum below takes st0, not the stored float
    l24 = l24b;
    recs[*cnt + k].f04 = 0;
    recs[*cnt + k].f14 = l24b + l18;
    recs[*cnt + k].f0c = r;
    recs[*cnt + k].f08 = recs[*cnt + k].f14;
    recs[*cnt + k].f18 = v10;
    recs[*cnt + k].f28 = 0;
    recs[*cnt + k].f2c = 0;
    recs[*cnt + k].f30 = 0;
    recs[*cnt + k].f34 = 0;
    recs[*cnt + k].f38 = 0;
    recs[*cnt + k].f3c = 0;
    recs[*cnt + k].f40 = (i3 != 0) ? 2 : 3;
    recs[*cnt + k].f44 = 1;
    *cnt = *cnt + 1;
}


// 0x00079f40 FUN_00079f40 (696 B): equivalent/0x00079f40.cpp
// sym: ?FUN_00079f40@Mesh_79f40@fn_f9399ba1@@QAEXPAUItem_79f40@2@HHHHHHPAHHH@Z @a78f59514fe1 @we8c8e8ea172f
// STATUS: equivalent (tools/equiv.py level 3: 19983 inputs, branch coverage 10/10)
// FUN_00079f40 @ 0x00079f40
void Mesh_79f40::FUN_00079f40(Item_79f40 *p, int i2, int i3, int i4, int i5, int i6, int a7, int *cnt, int v9, int v10)
{
    Item_79f40 *e = &p[i2];
    if (e->flag == 0)
        return;
    hulk_freg ten = 10.0f;
    volatile float v = 10.0f;
    Item_79f40 *t3 = &p[i3];
    Item_79f40 *t = 0;
    if (t3->flag != 0)
        t = t3;
    else if (p[5].flag != 0)
        t = &p[i4];
    if (t != 0)
        v = (t->f8 + t->f8 + t->f4 * 0.5f + t->fc) + 10.0f;
    hulk_freg f = ten;
    Item_79f40 *u = &p[i5];
    if (u->flag != 0) {
        f = (u->f8 + u->f8 + u->f4 * 0.5f + u->fc) + 10.0f;
    } else {
        Item_79f40 *w = &p[i6];
        if (w->flag != 0)
            f = (w->f8 + w->f8 + w->f4 * 0.5f + w->fc) + 10.0f;
    }
    int k = a7 * 14;
    volatile float l = (v + 45.0f - 90.0f) * DAT_004dd048;
    hulk_freg r = DAT_004dd048 * 90.0f - (f + 45.0f) * DAT_004dd048;
    hulk_freg z = (e->f8 + 1.0f) * 1.5f + e->f4 * 0.5f;
    recs[*cnt + k].f0c = l;
    recs[*cnt + k].f10 = 0;
    recs[*cnt + k].f14 = z;
    recs[*cnt + k].f00 = r;
    recs[*cnt + k].f04 = 0;
    recs[*cnt + k].f08 = z;
    recs[*cnt + k].f18 = v9;
    recs[*cnt + k].f28 = 0;
    recs[*cnt + k].f2c = 0;
    recs[*cnt + k].f30 = 0;
    recs[*cnt + k].f34 = 0;
    recs[*cnt + k].f38 = 0;
    recs[*cnt + k].f3c = 0;
    recs[*cnt + k].f40 = 2;
    recs[*cnt + k].f44 = 1;
    hulk_freg z2 = z - (e->f8 + e->f4 + 3.0f);
    *cnt = *cnt + 1;
    recs[*cnt + k].f00 = l;
    recs[*cnt + k].f04 = 0;
    recs[*cnt + k].f08 = z2;
    recs[*cnt + k].f0c = r;
    recs[*cnt + k].f10 = 0;
    recs[*cnt + k].f14 = z2;
    recs[*cnt + k].f18 = v10;
    recs[*cnt + k].f28 = 0;
    recs[*cnt + k].f2c = 0;
    recs[*cnt + k].f30 = 0;
    recs[*cnt + k].f34 = 0;
    recs[*cnt + k].f38 = 0;
    recs[*cnt + k].f3c = 0;
    recs[*cnt + k].f40 = 3;
    recs[*cnt + k].f44 = 1;
    *cnt = *cnt + 1;
}


// 0x0007a200 FUN_0007a200 (38 B): matches/0x0007a200.cpp
// sym: ?find@fn_f9399ba1@@YIHPAVObj_7a200@1@PAXH@Z
int __fastcall find(Obj_7a200* self, void*, int key) {
    int i = 0;
    int* p = &self->item;
    do {
        if (*p == key)
            return i;
        ++i;
        p += 0xfc;
    } while (i < 7);
    return -1;
}


// 0x0007a230 FUN_0007a230 (376 B): equivalent/0x0007a230.cpp
// sym: ?FUN_0007a230@Grid_7a230@fn_f9399ba1@@QAEHHHHH@Z @b6573af5fe93 @wd0d15965fc93
// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 47/48, incomplete)
// FUN_0007a230 @ 0x0007a230
int Grid_7a230::FUN_0007a230(int idA, int idB, int rowIdx, int span)
{
    int list[14];
    int n = 0;
    int lim = span - span % 2;
    Cell_7a230* c = &cells[rowIdx * 14];
    for (int i = 0; i < 14; i += 2) {
        if (!c[0].active)
            break;
        if (c[0].count < 3 && (c[0].id == idA || c[0].id == idB) && (i < lim || i > lim + 1)) {
            int r = c[0].row;
            int q = c[0].col;
            if (r == -1 || q == -1 || !cells[r * 14 + q].active || cells[r * 14 + q].count < 3) {
                list[n] = i;
                n++;
            }
        }
        if (!c[1].active)
            break;
        if (c[1].count < 3 && (c[1].id == idA || c[1].id == idB) && (i + 1 < lim || i + 1 > lim + 1)) {
            int r = c[1].row;
            int q = c[1].col;
            if (r == -1 || q == -1 || !cells[r * 14 + q].active || cells[r * 14 + q].count < 3) {
                list[n] = i + 1;
                n++;
            }
        }
        c += 2;
    }
    if (n == 0)
        return -1;
    (*(Rng_7a230**)&DAT_004e5acc)->a = ((*(Rng_7a230**)&DAT_004e5acc)->a & 0xffff) * 0x9069 + ((*(Rng_7a230**)&DAT_004e5acc)->a >> 16);
    (*(Rng_7a230**)&DAT_004e5acc)->b = ((*(Rng_7a230**)&DAT_004e5acc)->b & 0xffff) * 0x4650 + ((*(Rng_7a230**)&DAT_004e5acc)->b >> 16);
    unsigned int v = ((*(Rng_7a230**)&DAT_004e5acc)->a << 16) + ((*(Rng_7a230**)&DAT_004e5acc)->b & 0xffff);
    return list[(int)(v % (unsigned int)n) % n];
}


// 0x0007a3b0 FUN_0007a3b0 (106 B): matches/0x0007a3b0.cpp
// sym: ?Fn@G_7a3b0@fn_f9399ba1@@QAEXHHPAH0@Z
void G_7a3b0::Fn(int x, int y, int* o1, int* o2) {
    int i = x * 0xe + y;
    int a = cells[i].a;
    int b = cells[i].b;
    if (a != -1 && b != -1 && *((char*)&cells[0] + (a * 0xe + b) * 0x48 + 0x24) != 0) {
        *o1 = a;
        *o2 = b;
        return;
    }
    *o1 = -1;
    *o2 = -1;
}

} // namespace fn_f9399ba1

// 0x0007a420 FUN_0007a420 (1007 B): equivalent/0x0007a420.cpp [wrapped: conflict: FUN_000964d0]
// sym: ?FUN_0007a420@Grid_7a420@fn_0007a420@@QAEDPAH000@Z @5c7a6d4166eb @wbacc97158f92
namespace fn_0007a420 {
// STATUS: equivalent (tools/equiv.py level 3: 19867 inputs, branch coverage 60/64, incomplete)
// FUN_0007a420 @ 0x0007a420

struct V3_7a420 {
    float x, y, z;
};

struct Rng_7a420 {
    unsigned int s0;
    unsigned int s1;
};

struct Cell_7a420 {
    float x0;
    float pad04;
    float z0;
    float x1;
    float pad10;
    float z1;
    char pad18[4];
    int f1c;
    char pad20[0xc];
    int state;
    int arr[4];
    char pad40[4];
    char active;
    char pad45[3];
};

struct Probe_7a420 {
    void FUN_00059a50(V3_7a420 *out);
};

struct Actor_7a420 {
    char pad00[0x10];
    Probe_7a420 *probe;
};

struct Ctx_7a420 {
    char pad00[0x124];
    Actor_7a420 *actor;
};

struct Owner_7a420 {
    char pad00[0x20];
    Ctx_7a420 *ctx;
};

Rng_7a420 *FUN_000964d0();

class Grid_7a420 {
public:
    char pad0000[0x1904];
    Cell_7a420 cells[98];
    char pad3494[0x382c - 0x3494];
    Owner_7a420 *owner;
    char FUN_0007a420(int *outRow, int *outCol, int *outSlot, int *outFlag);
};

char Grid_7a420::FUN_0007a420(int *outRow, int *outCol, int *outSlot, int *outFlag)
{
    struct Frame {
        Grid_7a420 *self;
        int row;
        int bestFlag;
        int n;
        int k;
        float u0;
        float pad28;
        float u2;
        float t0;
        float pad34;
        float t2;
        V3_7a420 B;
        int start;
        V3_7a420 A;
        int flags[14];
        int cand[14];
    } fr;

    fr.self = this;
    Actor_7a420 *actor = owner->ctx->actor;
    actor->probe->FUN_00059a50(&fr.A);
    ((owners::C_35660 *)actor)->FUN_00035660((int *)(V3_7a420 *)(&fr.B));

    Rng_7a420 *r0 = (*(Rng_7a420**)&DAT_004e5acc);
    r0->s0 = (r0->s0 & 0xffff) * 0x9069 + (r0->s0 >> 16);
    r0->s1 = (r0->s1 & 0xffff) * 0x4650 + (r0->s1 >> 16);
    unsigned int v = (r0->s0 << 16) + (r0->s1 & 0xffff);
    fr.start = (int)(v % 7);
    fr.k = 0;
    for (;;) {
        fr.row = (fr.k + fr.start) % 7;
        Cell_7a420 *row0 = &cells[fr.row * 14];
        if (row0->f1c > 0) {
            int n = 0;
            for (int j = 0; j < 14; j++) {
                Cell_7a420 *c = &row0[j];
                if (!c->active)
                    continue;
                if (c->state >= 4)
                    continue;
                fr.t0 = fr.A.x - c->x0;
                double t2x = fr.A.z - c->z0;
                fr.t2 = (float)t2x;
                double d0 = t2x * fr.t2 + fr.t0 * fr.t0;
                bool b4900 = d0 < DAT_0049b8e8;
                bool b2500 = d0 < DAT_0049b8e4;
                fr.u0 = fr.A.x - c->x1;
                double u2x = fr.A.z - c->z1;
                fr.u2 = (float)u2x;
                double d1 = u2x * fr.u2 + fr.u0 * fr.u0;
                bool c4900 = d1 < DAT_0049b8e8;
                bool c2500 = d1 < DAT_0049b8e4;
                if (b4900 && !b2500 && c2500) {
                    double dot = fr.B.z * fr.t2 + fr.t0 * fr.B.x + fr.B.y * 0.0f;
                    int flag;
                    if (!(dot <= 0.0))
                        flag = 0;
                    else if (((int)((owners::Random_11330 *)(FUN_000964d0()))->FUN_00011330(1)))
                        flag = 1;
                    else
                        flag = 0;
                    fr.flags[n] = flag;
                    fr.cand[n] = j;
                    n++;
                } else if (c4900 && !c2500 && b2500) {
                    double dot = fr.B.z * fr.u2 + fr.u0 * fr.B.x + fr.B.y * 0.0f;
                    int flag;
                    if (!(dot <= 0.0))
                        flag = 1;
                    else if (((int)((owners::Random_11330 *)(FUN_000964d0()))->FUN_00011330(1)))
                        flag = 0;
                    else
                        flag = 1;
                    fr.flags[n] = flag;
                    fr.cand[n] = j;
                    n++;
                }
            }
            fr.n = n;
            if (n != 0) {
                int best = 5;
                int bi = -1;
                fr.bestFlag = 0;
                for (int m = 0; m < n; m++) {
                    int ci = fr.cand[m];
                    int st = cells[ci + fr.row * 14].state;
                    if (st < best) {
                        bi = ci;
                        fr.bestFlag = fr.flags[m];
                        best = st;
                    }
                }
                if (bi != -1) {
                    int best2 = 2;
                    int bj = -1;
                    Rng_7a420 *rr = FUN_000964d0();
                    rr->s0 = (rr->s0 & 0xffff) * 0x9069 + (rr->s0 >> 16);
                    unsigned int b = (rr->s1 & 0xffff) * 0x4650 + (rr->s1 >> 16);
                    rr->s1 = b;
                    int k = (int)(b & 3);
                    Cell_7a420 *cc = &cells[bi + fr.row * 14];
                    if (cc->arr[k] < best2) {
                        best2 = cc->arr[0];
                        bj = 0;
                    }
                    k = (k + 1) % 4;
                    if (cc->arr[k] < best2) {
                        best2 = cc->arr[1];
                        bj = 1;
                    }
                    k = (k + 1) % 4;
                    if (cc->arr[k] < best2) {
                        best2 = cc->arr[2];
                        bj = 2;
                    }
                    k = (k + 1) % 4;
                    if (cc->arr[k] < best2)
                        bj = 3;
                    if (bj != -1) {
                        *outRow = fr.row;
                        *outCol = bi;
                        *outSlot = bj;
                        *outFlag = fr.bestFlag;
                        return 1;
                    }
                }
            }
        }
        fr.k++;
        if (fr.k >= 7)
            return 0;
    }
}
} // namespace fn_0007a420


// 0x0007a820 FUN_0007a820 (17 B): matches/0x0007a820.cpp
// sym: ?FUN_0007a820@Thing_7a820@owners@@QAEMH@Z
float owners::Thing_7a820::FUN_0007a820(int index) {
    return *(float*)((char*)entries[index] + 0x18);
}

namespace fn_f9399ba1 {

// 0x0007a840 FUN_0007a840 (174 B): matches/0x0007a840.cpp
// sym: ?FUN_0007a840@Owner_7a840@fn_f9399ba1@@QAEXHHPAH0@Z
void Owner_7a840::FUN_0007a840(int group, int index, int* foundGroup, int* foundIndex) {
    for (int g = 0; g < 7; ++g) {
        if (g == group)
            continue;
        for (int i = 0; i < 14; ++i) {
            Record_7a840* candidate = &records[g][i];
            if (!candidate->active)
                break;
            if (records[group][index].shape.FUN_0022d2b0(candidate, 0.1f)) {
                *foundGroup = g;
                *foundIndex = i;
                return;
            }
        }
    }
    *foundGroup = -1;
    *foundIndex = -1;
}

} // namespace fn_f9399ba1

// 0x0007a8f0 FUN_0007a8f0 (609 B): equivalent/0x0007a8f0.cpp [wrapped: conflict: DAT_0049b8e4; DAT_0049b8e8]
// sym: ?FUN_0007a8f0@Finder_7a8f0@fn_0007a8f0@@QAEHPAH0@Z @d4fad24e083b @wb6db4981cdac
namespace fn_0007a8f0 {
// STATUS: equivalent (tools/equiv.py level 3: 18606 inputs, branch coverage 34/34)
// FUN_0007a8f0 @ 0x0007a8f0
struct Vec3_7a8f0 {
    float x, y, z;
};

struct Transform_7a8f0 {
    void FUN_00059a50(Vec3_7a8f0 *out);
};

struct Holder_7a8f0 {
    char pad0[0x10];
    Transform_7a8f0 *transform;
};

struct Table_7a8f0 {
    char pad0[0x124];
    Holder_7a8f0 *player;
};

struct Handle_7a8f0 {
    int a;
    int b;
    Handle_7a8f0 *FUN_0027af30(const Handle_7a8f0 *src);
    void FUN_0027af50();
};

struct Item_7a8f0 {
    char pad0[0x14];
    int count;
};

struct Mgr_7a8f0 {
    int FUN_00106290(int a, int b);
};

struct World {
    char pad0[0x18];
    Mgr_7a8f0 *mgr;
    char pad1c[4];
    Table_7a8f0 *table;
};

extern "C" int __cdecl FUN_000113e0(int lo, int hi);
extern float DAT_0049b8e4;  // 2500 (50^2)
extern float DAT_0049b8e8;  // 4900 (70^2)

class Finder_7a8f0 {
public:
    int FUN_0007a8f0(int *outIndex, int *outSide);

    char pad0[0x35a0];
    Handle_7a8f0 handles[(0x3640 - 0x35a0) / 8];
    int count;
    char pad3644[0x382c - 0x3644];
    World *world;
};

int Finder_7a8f0::FUN_0007a8f0(int *outIndex, int *outSide)
{
    if (count < 1)
        return -1;
    Mgr_7a8f0 *mgr = world->mgr;
    int start = FUN_000113e0(0, count - 1);
    for (int i = 0; i < count; i++) {
        Handle_7a8f0 key;
        key.FUN_0027af30(&handles[(unsigned int)(start + i) % (unsigned int)count]);
        int id = mgr->FUN_00106290(key.a, key.b);
        if (id != -1) {
            Item_7a8f0 *item = ((Item_7a8f0 *)((owners::C_106210 *)mgr)->FUN_00106210(id));
            if (item != 0) {
                Vec3_7a8f0 player;
                world->table->player->transform->FUN_00059a50(&player);
                int first = FUN_000113e0(0, item->count - 1);
                for (int j = 0; j < item->count; j++) {
                    int cur = (first + j) % item->count;
                    Vec3_7a8f0 p = *((Vec3_7a8f0 *)((owners::Target_106160 *)item)->FUN_00106160(cur));
                    double dx = p.x - player.x;
                    double dz = p.z - player.z;
                    double d2 = dz * dz + dx * dx;
                    bool inFar = d2 < DAT_0049b8e8;
                    bool inNear = d2 < DAT_0049b8e4;

                    Vec3_7a8f0 *q = ((Vec3_7a8f0 *)((owners::Target_106160 *)item)->FUN_00106160((cur + 1) % item->count));
                    // the original rounds the x difference to float (stored in p.x) but keeps z on the FPU stack
                    float dz2 = q->z;
                    p.x = q->x - player.x;
                    double d3 = (dz2 - player.z) * (dz2 - player.z) + p.x * p.x;
                    bool inFar2 = d3 < DAT_0049b8e8;
                    bool inNear2 = d3 < DAT_0049b8e4;

                    if (inFar && !inNear && inNear2) {
                        *outSide = 0;
                        *outIndex = cur;
                        key.FUN_0027af50();
                        return id;
                    }
                    if (inFar2 && !inNear2 && inNear) {
                        *outSide = 1;
                        *outIndex = cur;
                        key.FUN_0027af50();
                        return id;
                    }
                }
            }
        }
        key.FUN_0027af50();
    }
    return -1;
}
} // namespace fn_0007a8f0

namespace fn_f9399ba1 {

// 0x0007ab60 FUN_0007ab60 (23 B): matches/0x0007ab60.cpp
// sym: ?Set@Obj@fn_f9399ba1@@QAEXH@Z
void Obj::Set(int n) {
    if (n > 0 && n <= 800)
        data[n * 8] = 1;
}


// 0x0007aba0 FUN_0007aba0 (22 B): matches/0x0007aba0.cpp
// sym: _FUN_0007aba0@8
extern "C" void __stdcall FUN_0007aba0(float x, float y) {
    DAT_0049b8ac = x;
    DAT_0049b8b0 = y;
}


// 0x0007abc0 FUN_0007abc0 (17 B): matches/0x0007abc0.cpp
// sym: _FUN_0007abc0@4
// data: gValue_7abc0 = DAT_004dd044
extern "C" void __stdcall FUN_0007abc0(int value) {
    if (value <= 10)
        DAT_004dd044 = value;
}

} // namespace fn_f9399ba1

// 0x0007abe0 FUN_0007abe0 (66 B): equivalent/0x0007abe0.cpp [wrapped: conflict: Owner]
// sym: ?FUN_0007abe0@Owner@fn_0007abe0@@QAEHHH@Z @ce21322d6e25 @wa5587f3bc8ca
namespace fn_0007abe0 {
// STATUS: equivalent (tools/equiv.py level 3: 1697 inputs, branch coverage 8/8)
// FUN_0007abe0 @ 0x0007abe0
struct Entry { char pad[8]; int first; int second; }; struct Owner { char pad[0x3800]; Entry* entries[10]; int count; int FUN_0007abe0(int first, int second); }; int Owner::FUN_0007abe0(int first, int second) { for (int i = 0; i < count; ++i) { Entry* e = entries[i]; if (e->first == first && e->second == second) return i; } return -1; }
} // namespace fn_0007abe0

namespace fn_f9399ba1 {

// 0x0007ac30 FUN_0007ac30 (146 B): matches/0x0007ac30.cpp
// sym: ?FUN_0007ac30@Scene_7ac30@fn_f9399ba1@@QAEHPBUName@2@@Z
// FUN_0007ac30 @ 0x0007ac30
// equiv-map: ??0Name@@QAE@XZ = 0x0027af00
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
int Scene_7ac30::FUN_0007ac30(const Name *key)
{
    Name found;
    Resolver_7ac30 *resolver = owner->resolver;
    for (int i = 0; i < count; i++) {
        resolver->FUN_001dd930(items[i]->id, &found);
        if (found.FUN_0027af90(key))
            return i;
    }
    return -1;
}

} // namespace fn_f9399ba1

// 0x0007ad00 FUN_0007ad00 (34 B): matches/0x0007ad00.cpp
// sym: ?FUN_0007ad00@Obj_7ad00@owners@@QAEHH@Z
hulk_intptr owners::Obj_7ad00::FUN_0007ad00(hulk_intptr arg) {
    int i = helper(((int)arg));
    if (i >= 0)
        return vals[i];
    return 0;
}


// 0x0007af90 CDHGameObjectCreator::vfunc_0 (31 B): matches/0x0007af90.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0007af90@@UAEPAV123@E@Z
namespace fn_0007af90 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ObjectCreator_7af90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003feefc[];
namespace pure3d {
class NonCopyable : public ObjectCreator_7af90 {
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
} // namespace fn_0007af90

namespace fn_f9399ba1 {

// 0x0007afb0 FUN_0007afb0 (806 B): equivalent/0x0007afb0.cpp
// sym: ?FUN_0007afb0@Grid_7afb0@fn_f9399ba1@@QAEXHHHHPAUV3_7afb0@2@0@Z @7b3a5f2202dc @wa08a67205f6b
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 24/24)
// FUN_0007afb0 @ 0x0007afb0
void Grid_7afb0::FUN_0007afb0(int row, int col, int n, int swap, V3_7afb0* p1, V3_7afb0* p2)
{
    Frame_7afb0 f;
    int key = cells[row * 14].key;
    int q = (key - 1) / 30;
    int rem = (key - 1) % 30;
    int t1 = -((rem % 2) != 0) - q * 2;
    f.fx = (float)t1 * 77.942283630371f;
    f.fz = ((float)rem - 0.5f) * -135.0f;
    f.m1.FUN_0022b980();
    f.turn = (short)tbl[key * 2];
    f.m1.FUN_0022ba70((float)f.turn * 1.0471975803375244f);
    f.m2.FUN_0022b980();
    f.turn = 6 - (short)tbl[key * 2];
    f.m2.FUN_0022ba70((float)f.turn * 1.0471975803375244f);

    Cell_7afb0& c = cells[row * 14 + col];
    *p1 = c.b2;
    *p2 = c.b1;
    f.dir = c.f40;
    int r = FUN_00079190(c.z, c.f40);
    float val = ((tbl[key * 2 - 1] >> (r * 4)) & 2) ? 8.5f : 7.0f;
    f.fu = (float)n + val - 2.0f + 1.0f;
    p1->x = p1->x - f.fx;
    p1->z = p1->z - f.fz;
    p2->x = p2->x - f.fx;
    p2->z = p2->z - f.fz;
    f.m1.FUN_0022c3b0(p1, p1);
    f.m1.FUN_0022c3b0(p2, p2);
    if (f.dir <= 3) {
        switch (f.dir) {
        case 0: {
            float a = DAT_004dd048 * f.fu;
            p1->x = p1->x + a;
            p2->x = p2->x + a;
            float b = DAT_004dd04c * f.fu;
            if (r == 0)
                p2->z = p2->z + b;
            else if (r == 6)
                p1->z = p1->z + b;
            else if (r == 1)
                p2->z = p2->z - b;
            else
                p1->z = p1->z - b;
            break;
        }
        case 1: {
            float a = DAT_004dd048 * f.fu;
            p1->x = p1->x - a;
            p2->x = p2->x - a;
            float b = DAT_004dd04c * f.fu;
            if (r == 0)
                p1->z = p1->z - b;
            else if (r == 6)
                p2->z = p2->z - b;
            else if (r == 1)
                p1->z = p1->z + b;
            else
                p2->z = p2->z + b;
            break;
        }
        case 2:
            p1->z = f.fu + p1->z;
            p2->z = f.fu + p2->z;
            break;
        case 3:
            p1->z = p1->z - f.fu;
            p2->z = p2->z - f.fu;
            break;
        }
    }
    f.m2.FUN_0022c3b0(p1, p1);
    f.m2.FUN_0022c3b0(p2, p2);
    p1->x = f.fx + p1->x;
    p1->z = f.fz + p1->z;
    p2->x = f.fx + p2->x;
    p2->z = f.fz + p2->z;
    if (swap == 1) {
        V3_7afb0 t = *p1;
        *p1 = *p2;
        *p2 = t;
    }
}


// 0x0007b380 FUN_0007b380 (91 B): matches/0x0007b380.cpp
// sym: ?Add@Owner_7b380@fn_f9399ba1@@QAEXPAVParam@2@@Z
void Owner_7b380::Add(Param* p) {
    int i = Find_00079220(p->a, p->b);
    if (i < 0 || entries[i] == 0) {
        i = count;
        if (i != 20) {
            p->Prepare();
            if (entries[i])
                entries[i]->Destroy();
            entries[i] = p;
            ++count;
        }
    }
}


// 0x0007b3e0 FUN_0007b3e0 (157 B): equivalent/0x0007b3e0.cpp
// sym: ?FUN_0007b3e0@Manager_7b3e0@fn_f9399ba1@@QAEXH@Z @3719115d2c25 @w69fdfb23ea59
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0007b3e0 @ 0x0007b3e0
// FUN_0007b3e0 @ 0x0007b3e0: remove the item in slot idx (swap with the last) after dropping its group count
void Manager_7b3e0::FUN_0007b3e0(int idx)
{
    Item_7b3e0 *item = items[idx];
    int id = item->groupId;
    if (id >= 0) {
        int g;
        for (g = 0; g < 7; g++) {
            if (groups[g].entries[0].groupId == id)
                break;
        }
        if (g >= 7)
            g = -1;
        Entry_7b3e0 *e = &groups[g].entries[item->entryIndex];
        e->counts[item->countIndex]--;
        e->count--;
    }
    item->Release();

    items[idx] = items[itemCount - 1];
    items[itemCount - 1] = 0;
    itemCount--;
}


// 0x0007b480 FUN_0007b480 (37 B): matches/0x0007b480.cpp
// sym: @FUN_0007b480@4
extern "C" void __fastcall FUN_0007b480(Thing_7b480* self) {
    while (self->count > 0)
        self->step_0007b3e0(0);
}


// 0x0007b4f0 FUN_0007b4f0 (807 B): equivalent/0x0007b4f0.cpp
// sym: ?FUN_0007b4f0@Grid_7b4f0@fn_f9399ba1@@QAEXH@Z @389fd0d71cb2 @w29978070afff
// STATUS: equivalent (tools/equiv.py level 3: 3046 inputs, branch coverage 26/26)
// FUN_0007b4f0 @ 0x0007b4f0
void Grid_7b4f0::FUN_0007b4f0(int idx)
{
    Tracker_7b4f0* o = objs[idx];
    if (o->state == 3) {
        int key = o->f38;
        int i = 0;
        while (i < 7 && cells[i * 14].key != key)
            i++;
        if (i == 7)
            i = -1;
        if (flags[i].a)
            return;
        int b = o->f3c;
        int r = FUN_0007a230(2, 4, i, b);
        if (r == -1)
            return;
        cells[i * 14 + b].cnt = cells[i * 14 + b].cnt - 1;
        cells[i * 14 + r].cnt = cells[i * 14 + r].cnt + 1;
        Cell_7b4f0& d = cells[i * 14 + r];
        Raw3_7b4f0 first;
        first.a = cells[i * 14].key;
        first.b = r;
        first.c = d.z;
        objs[idx]->FUN_00084920(first, d.b2, d.b1);
        flags[i].a = 1;
    } else if (o->state == 4) {
        int j = FUN_0007a200(o->f38);
        if (flags[j].b)
            return;
        int b = o->f3c;
        int r = FUN_0007a230(3, 5, j, b);
        if (r == -1)
            return;
        cells[j * 14 + b].cnt = cells[j * 14 + b].cnt - 1;
        cells[j * 14 + r].cnt = cells[j * 14 + r].cnt + 1;
        Cell_7b4f0& d = cells[j * 14 + r];
        Raw3_7b4f0 first;
        first.a = cells[j * 14].key;
        first.b = r;
        first.c = d.z;
        objs[idx]->FUN_00084920(first, d.b2, d.b1);
        flags[j].b = 1;
    } else if (o->state == 11) {
        int j = FUN_0007a200(o->f38);
        flags[j].a = 0;
        ((owners::Thing_83d20 *)(objs[idx]))->FUN_00083d20(0);
    } else if (o->state == 12) {
        int j = FUN_0007a200(o->f38);
        flags[j].b = 0;
        ((owners::Thing_83d20 *)(objs[idx]))->FUN_00083d20(0);
    } else if (o->state == 13) {
        int j = FUN_0007a200(o->f38);
        int b = o->f3c;
        int row;
        FUN_0007a3b0(j, b, &row, &idx);
        if (row == -1)
            return;
        if (idx == -1)
            return;
        Cell_7b4f0& d = cells[row * 14 + idx];
        Raw3_7b4f0 first;
        first.a = cells[row * 14].key;
        first.b = idx;
        first.c = d.z;
        o->FUN_00084920(first, d.b2, d.b1);
        cells[j * 14 + b].cnt = cells[j * 14 + b].cnt - 1;
        d.cnt = d.cnt + 1;
    }
}


// 0x0007b820 FUN_0007b820 (95 B): matches/0x0007b820.cpp
// sym: ?F@C_7b820@fn_f9399ba1@@QAEHPAVObj_7b820@2@@Z
int C_7b820::F(Obj_7b820* p) {
    int i = count;
    if (i == 20)
        return -1;
    if (p)
        p->A();
    if (items[i])
        items[i]->B();
    items[i] = p;
    ++count;
    ++total;
    return i;
}


// 0x0007b880 FUN_0007b880 (315 B): equivalent/0x0007b880.cpp
// sym: ?run@Pool_7b880@fn_f9399ba1@@QAEXH@Z @1d20f701749d @wec16daa20828
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 31/32, incomplete)
// FUN_0007b880 @ 0x0007b880
void Pool_7b880::run(int slot)
{
    counters[slots[slot]->category]--;

    int key = slots[slot]->key;
    int found = -1;
    for (int i = 0; i < 7; i++) {
        if (*(int*)((char*)this + 0x1920 + i * 0x3f0) == key) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        Item72* items = (Item72*)((char*)this + 0x192c);
        items[found * 14 + slots[slot]->row].count--;
    }

    int kind = slots[slot]->kind;
    if (kind == 5 || kind == 9 || kind == 7 || kind == 11)
        ((unsigned char*)this)[0x3494 + found * 2] = 0;
    else if (kind == 6 || kind == 10 || kind == 8 || kind == 12)
        ((unsigned char*)this)[0x3495 + found * 2] = 0;

    int i;
    for (i = 0; i < 20; i++) {
        if (active[i] == slots[slot])
            break;
    }
    if (i < 20) {
        if (active[i] != 0) {
            active[i]->v1();
            active[i] = 0;
        }
    }

    int saved = slots[slot]->arg34;
    if (slots[slot] != 0) {
        slots[slot]->v1();
        slots[slot] = 0;
    }

    Entity** stack = &stack0;
    if (stack[depth] != 0) {
        slots[slot] = stack[depth];
        stack[depth] = 0;
    }
    depth = depth - 1;
    mgr->target->FUN_001e5bc0(saved);
}


// 0x0007b9c0 FUN_0007b9c0 (37 B): matches/0x0007b9c0.cpp
// sym: ?target@Obj_7b9c0@fn_f9399ba1@@QAEXXZ
void Obj_7b9c0::target() {
    while (count > 0)
        remove_0007b880(0);
}


// 0x0007b9f0 FUN_0007b9f0 (103 B): equivalent/0x0007b9f0.cpp
// sym: ?FUN_0007b9f0@Manager_7b9f0@fn_f9399ba1@@QAEXH@Z @7e615c49f59c @w96eab8f85460
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0007b9f0 @ 0x0007b9f0
void Manager_7b9f0::FUN_0007b9f0(int key) {
    int idx = FUN_00079800(key);
    if (idx == -1)
        return;
    ((owners::Thing_83d20 *)(items[idx]))->FUN_00083d20(0x13);
    Item_7b9f0* item = items[idx];
    for (int i = 0; i < 20; i++) {
        if ((Item_7b9f0*)objs[i] == item) {
            if (objs[i] != 0) {
                objs[i]->vfunc_1();
                objs[i] = 0;
            }
            return;
        }
    }
}


// 0x0007ba60 FUN_0007ba60 (90 B): matches/0x0007ba60.cpp
// sym: ?Remove@Owner_7ba60@fn_f9399ba1@@QAEXH@Z
void Owner_7ba60::Remove(int n) {
    ((owners::Thing_83d20 *)(indexed[n]))->FUN_00083d20(0x13);
    int i = 0;
    Item_7ba60* p = indexed[n];
    for (; i < 20; ++i) {
        if (items[i] == p) {
            if (items[i]) {
                items[i]->Release();
                items[i] = 0;
            }
            return;
        }
    }
}


// 0x0007bac0 FUN_0007bac0 (258 B): equivalent/0x0007bac0.cpp
// sym: ?remove@Manager_7bac0@fn_f9399ba1@@QAEHH@Z @78e7ea757bbb @w5bb937d4ba09
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 27/28, incomplete)
// FUN_0007bac0 @ 0x0007bac0
int Manager_7bac0::remove(int key) {
    int index = FUN_00079800(key);
    if (index == -1) return index;
    --categoryCounts[objects[index]->category];
    Object* object = objects[index];
    int id = object->groupId;
    int group = -1;
    for (int i=0; i<7; ++i) {
        if (groups[i].cells[0].id == id) { group=i; break; }
    }
    if (group != -1) --groups[group].cells[object->subIndex].count;
    int type = objects[index]->type;
    if (type==5 || type==9 || type==7 || type==11)
        flagView.flags[group+1].first=0;
    else if (type==6 || type==10 || type==8 || type==12)
        flagView.flags[group+1].second=0;
    if (objects[index]) {
        objects[index]->release();
        objects[index]=0;
    }
    Object* last = count == 0 ? tailView.before : objects[count-1];
    if (last) {
        objects[index]=last;
        if (count == 0) tailView.before=0; else objects[count-1]=0;
    }
    return --count;
}


// 0x0007bbd0 FUN_0007bbd0 (940 B): equivalent/0x0007bbd0.cpp
// sym: ?FUN_0007bbd0@HexBoard@fn_f9399ba1@@QAEXH@Z @668d8000da60 @w0a94e1f282f9
// STATUS: equivalent (tools/equiv.py level 3: 417 inputs, branch coverage 30/32, incomplete)
// FUN_0007bbd0 @ 0x0007bbd0
void HexBoard::FUN_0007bbd0(int idx)
{
    if (!tiles[idx].active)
        return;

    int slot = 0;
    while (entries[slot * 14].t.owner != 0) {
        slot++;
        if (slot >= 7)
            return;
    }

    Frame_7bbd0 f;
    entries[slot * 14].t.owner = idx;
    flags[slot].a = 0;
    flags[slot].b = 0;
    int bits = tiles[idx - 1].bits;
    for (int shift = 0; shift < 0x1c; shift += 4) {
        int n = (bits >> shift) & 0xf;
        Cfg_7bbd0* c = &f.cfg[shift >> 2];
        if (!(n & 1)) {
            c->on = 0;
        } else {
            c->on = 1;
            if (n & 2) {
                c->a = 39.0f;
                c->b = 8.0f;
                c->c = 1.0f;
                c->d = 2.0f;
            } else {
                c->a = 43.5f;
                c->b = 0;
                c->c = 0;
                c->d = 0;
            }
        }
    }

    f.count = 0;
    FUN_00079990(f.cfg, 0, 3, 2, -1, 1, slot, &f.count, 0, 2);
    FUN_00079990(f.cfg, 1, 3, 4, 1, 1, slot, &f.count, 1, 3);
    FUN_00079c80(f.cfg, 2, 0, 5, -1, 1, slot, &f.count, 2, 0);
    FUN_00079f40(f.cfg, 3, 0, 5, 1, 6, slot, &f.count, 5, 4);
    FUN_00079c80(f.cfg, 4, 1, 6, 1, 1, slot, &f.count, 3, 1);
    FUN_00079990(f.cfg, 5, 3, 2, -1, -1, slot, &f.count, 0, 2);
    FUN_00079990(f.cfg, 6, 3, 4, 1, -1, slot, &f.count, 1, 3);

    f.mat.FUN_0022b980();
    int quot = (idx - 1) / 30;
    int rem = (idx - 1) % 30;
    f.l1c = rem;
    f.l14 = -((rem % 2) != 0) - quot * 2;
    int tileId = tiles[idx].id;
    f.pos.x = (float)f.l14 * 77.9422836f;
    f.l14 = tileId;
    f.pos.y = 0;
    f.axis.x = 0;
    f.axis.y = 1.0f;
    f.axis.z = 0;
    f.pos.z = ((float)f.l1c - 0.5f) * -135.0f;
    f.mat.FUN_0022baf0(&f.axis, (float)f.l14 * 1.04719758f);
    ((owners::Target_22be40 *)&(f.mat))->FUN_0022be40((const int *)(Vec3_7bbd0 *)(&f.pos));

    if (f.count > 0) {
        Entry_7bbd0* e = &entries[slot * 14];
        f.slotBase = slot * 14;
        for (int k = 0; k < f.count; k++) {
            f.cur = &e->t;
            ((owners::Obj_22d210 *)&(e->a))->FUN_0022d210((owners::Obj_22d210 *)(Mat4_7bbd0 *)(&f.mat));
            ((owners::Obj_22d210 *)&(e->t.b))->FUN_0022d210((owners::Obj_22d210 *)(Mat4_7bbd0 *)(&f.mat));
            int sgn = ((k % 2) != 0) ? -1 : 1;
            FUN_0007a840(slot, k, &f.l14, &f.l1c);
            f.cur->p = f.l14;
            f.cur->q = f.l1c;
            if (f.l14 != -1 && f.l1c != -1) {
                int sgn2 = ((f.l1c % 2) != 0) ? -1 : 1;
                f.tmp20 = f.l14 * 14;
                Entry_7bbd0* a = &entries[f.tmp20 + sgn2 + f.l1c];
                a->t.p = slot;
                a->t.q = k + sgn;
                Entry_7bbd0* b = &entries[f.tmp20 + f.l1c];
                b->t.p = slot;
                b->t.q = k;
                Entry_7bbd0* c = &entries[f.slotBase + sgn + k];
                c->t.p = f.l14;
                c->t.q = sgn2 + f.l1c;
            }
            e = e + 1;
        }
    }
    for (int j = f.count; j < 14; j++)
        entries[slot * 14 + j].t.on = 0;
}


// 0x0007bf80 FUN_0007bf80 (1505 B): equivalent/0x0007bf80.cpp
// sym: ?F@Anim_7bf80@fn_f9399ba1@@QAEXH@Z @4b468bc70bfa @w2a46ec752abd
// STATUS: equivalent (tools/equiv.py level 3: 3086 inputs, branch coverage 85/86, incomplete)
// FUN_0007bf80 @ 0x0007bf80
void Anim_7bf80::F(int idx)
{
    struct Frame {
        int pa[3];
        int pb[3];
    } fr;
    Item_7bf80 *it = items[idx];
    if (it->type != 1)
        return;
    if (!it->v64.FUN_0022d2b0(&it->vdc, 0.3f))
        return;
    if (it->ibc < 0) {
        int ic0 = it->ic0;
        Obj18_7bf80 *o = p382c->p18;
        int ic8 = it->ic8;
        XObj_7bf80 *x = o->FUN_00106210(ic0);
        if (x) {
            int nxt;
            if (it->icc == 0) {
                nxt = (ic8 + 1) % x->count;
            } else {
                int cnt = x->count;
                nxt = (cnt + ic8 - 1) % cnt;
            }
            hulk_intptr v = x->FUN_00106160(nxt);
            it->FUN_00080ea0(&it->vdc, (void *)v);
            it->FUN_00080f20(nxt);
            return;
        }
        it->i20 = 0;
        it->FUN_00080cb0(0xc);
        return;
    }
    int g = FUN_0007a200(it->ibc);
    int ic0 = it->ic0;
    int ic8 = it->ic8;
    int ic4 = it->ic4;
    int base = g * 14;
    Rec_7bf80 *rec = R(ic0 + base);
    int s2 = rec->f18;
    int icc = it->icc;
    int s1 = rec->f40;
    int ebx = ic4;
    int edi2;
    if (ic4 != -1) {
        FUN_0007afb0(g, ic4, ic8, icc, fr.pb, fr.pa);
        if ((it->f28 >> 4) & 1) {
            it->FUN_00080ea0(&it->v64, fr.pb);
            it->FUN_00080f40(0);
            return;
        }
        it->FUN_00080ea0(fr.pb, fr.pa);
        it->FUN_00080f00(ic4);
        it->FUN_00080f10(-1);
        rec->cnt--;
        rec->hist[ic8]--;
        Rec_7bf80 *r2 = R(ic4 + base);
        r2->cnt++;
        r2->hist[ic8]++;
        return;
    }
    bool have = true;
    bool skip = false;
    if (s1 > 3) {
        have = false;
    } else if (s1 == 0) {
        if (s2 > 3) {
            have = false;
        } else if (s2 == 0) {
            if (icc != 0) skip = true; else { fr.pa[0] = 4; fr.pa[1] = 2; fr.pa[2] = 2; fr.pb[0] = 3; fr.pb[1] = 0; fr.pb[2] = 2; }
        } else if (s2 == 1) {
            if (icc != 0) skip = true; else { fr.pa[0] = 3; fr.pa[1] = 3; fr.pa[2] = 5; fr.pb[0] = 3; fr.pb[1] = 0; fr.pb[2] = 2; }
        } else if (s2 == 2) {
            if (icc == 0) skip = true; else { fr.pa[0] = 5; fr.pa[1] = 0; fr.pa[2] = 0; fr.pb[0] = 2; fr.pb[1] = 0; fr.pb[2] = 2; }
        } else {
            if (icc == 0) skip = true; else { fr.pa[0] = 1; fr.pa[1] = 1; fr.pa[2] = 4; fr.pb[0] = 2; fr.pb[1] = 0; fr.pb[2] = 3; }
        }
    } else if (s1 == 1) {
        if (s2 > 3) {
            have = false;
        } else if (s2 == 0) {
            if (icc != 0) skip = true; else { fr.pa[0] = 2; fr.pa[1] = 2; fr.pa[2] = 4; fr.pb[0] = 2; fr.pb[1] = 1; fr.pb[2] = 3; }
        } else if (s2 == 1) {
            if (icc != 0) skip = true; else { fr.pa[0] = 5; fr.pa[1] = 3; fr.pa[2] = 3; fr.pb[0] = 2; fr.pb[1] = 1; fr.pb[2] = 3; }
        } else if (s2 == 2) {
            if (icc == 0) skip = true; else { fr.pa[0] = 0; fr.pa[1] = 0; fr.pa[2] = 5; fr.pb[0] = 3; fr.pb[1] = 1; fr.pb[2] = 2; }
        } else {
            if (icc == 0) skip = true; else { fr.pa[0] = 4; fr.pa[1] = 1; fr.pa[2] = 1; fr.pb[0] = 1; fr.pb[1] = 1; fr.pb[2] = 2; }
        }
    } else {
        if (s2 > 5) {
            have = false;
        } else if (s2 == 0) {
            if (icc != 0) skip = true; else { fr.pa[0] = 2; fr.pa[1] = 4; fr.pa[2] = 2; fr.pb[0] = 1; fr.pb[1] = 3; fr.pb[2] = 0; }
        } else if (s2 == 1) {
            if (icc != 0) skip = true; else { fr.pa[0] = 3; fr.pa[1] = 5; fr.pa[2] = 3; fr.pb[0] = 0; fr.pb[1] = 2; fr.pb[2] = 1; }
        } else if (s2 == 2) {
            if (icc == 0) skip = true; else { fr.pa[0] = 0; fr.pa[1] = 5; fr.pa[2] = 0; fr.pb[0] = 1; fr.pb[1] = 2; fr.pb[2] = 0; }
        } else if (s2 == 3) {
            if (icc == 0) skip = true; else { fr.pa[0] = 1; fr.pa[1] = 4; fr.pa[2] = 1; fr.pb[0] = 0; fr.pb[1] = 3; fr.pb[2] = 1; }
        } else if (s2 == 4) {
            if (icc == 0) { fr.pa[0] = 3; fr.pa[1] = 3; fr.pa[2] = 3; fr.pb[0] = 1; fr.pb[1] = 3; fr.pb[2] = 0; }
            else { fr.pa[0] = 0; fr.pa[1] = 0; fr.pa[2] = 0; fr.pb[0] = 0; fr.pb[1] = 3; fr.pb[2] = 1; }
        } else {
            if (icc == 0) { fr.pa[0] = 2; fr.pa[1] = 2; fr.pa[2] = 2; fr.pb[0] = 0; fr.pb[1] = 2; fr.pb[2] = 1; }
            else { fr.pa[0] = 1; fr.pa[1] = 1; fr.pa[2] = 1; fr.pb[0] = 1; fr.pb[1] = 2; fr.pb[2] = 0; }
        }
    }
    if (skip) {
        edi2 = rec->f20;
        ebx = rec->f24;
        if (edi2 != g) {
            if (edi2 == -1)
                return;
            FUN_0007afb0(edi2, ebx, ic8, icc, fr.pa, fr.pb);
            it->FUN_00080ea0(&it->v64, fr.pb);
            it->FUN_00080ef0(R(edi2 * 14)->f1c);
            it->FUN_00080f00(ebx);
            rec->cnt--;
            rec->hist[ic8]--;
            Rec_7bf80 *r2 = R(edi2 * 14 + ebx);
            r2->cnt++;
            r2->hist[ic8]++;
            return;
        }
    }
    for (int k = 0; k < 3; k++) {
        if (ebx != -1)
            break;
        Rec_7bf80 *rj = R(base);
        for (int j = 0; j < 14; j++, rj++) {
            if (rj->active) {
                if (rj->f18 == fr.pa[k] && rj->f40 == fr.pb[k]) {
                    ebx = j;
                    break;
                }
            }
        }
    }
    if (ebx == -1)
        return;
    FUN_0007afb0(g, ebx, ic8, icc, fr.pb, fr.pa);
    it->FUN_00080ea0(&it->v64, fr.pb);
    it->FUN_00080f40(0);
    it->FUN_00080f10(ebx);
}

} // namespace fn_f9399ba1

// 0x0007c5b0 FUN_0007c5b0 (888 B): equivalent/0x0007c5b0.cpp [wrapped: conflict: World]
// sym: ?FUN_0007c5b0@World@fn_0007c5b0@@QAE_NUV3_7c5b0@2@0@Z @713bfbcf5cf1 @w4a1980990e4c
namespace fn_0007c5b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_0007c5b0 @ 0x0007c5b0
struct V3_7c5b0 {
    float x, y, z;
};

struct Plane_7c5b0 {
    float x, y, z, d;
    void FUN_0022e1f0(V3_7c5b0 *a, V3_7c5b0 *b, float *t);
};

struct Frustum;

struct PlaneList {
    int count;
    Plane_7c5b0 p[10];
    void FUN_001c2e10(Frustum *fr);
    char FUN_001c27d0(V3_7c5b0 *pt);
    void FUN_001c27c0();
};

struct Cam_7c5b0 {
    char pad0[0xc];
    char fr[1];
};

Cam_7c5b0 **FUN_001c3d90();

struct Tracker_7c5b0 {
    char pad0[0x10];
    struct Inner {
        void FUN_00059a50(V3_7c5b0 *out);
    } *inner;
};

struct Rig_7c5b0 {
    char pad0[0x124];
    Tracker_7c5b0 *tracker;
};

struct Owner_7c5b0 {
    char pad0[0x20];
    Rig_7c5b0 *rig;
};

struct Frame_7c5b0 {
    float f10;
    float f14;
    float f18;
    float negd;     // 0x1c
    Plane_7c5b0 pl;       // 0x20
    float t;        // 0x30
    V3_7c5b0 pos;         // 0x34
    PlaneList list; // 0x40
};

class World {
public:
    char pad0[0x382c];
    Owner_7c5b0 *owner;
    bool FUN_0007c5b0(V3_7c5b0 a, V3_7c5b0 b);
};

bool World::FUN_0007c5b0(V3_7c5b0 a, V3_7c5b0 b)
{
    Frame_7c5b0 f;
    Cam_7c5b0 *cam = *FUN_001c3d90();
    f.list.FUN_001c2e10((Frustum *)&cam->fr);
    for (int i = 0; i < f.list.count; i++) {
        f.pl = f.list.p[i];
        f.negd = -f.pl.d;
        double s0 = a.z * f.pl.z + a.y * f.pl.y + a.x * f.pl.x;
        bool clip;
        if (!(s0 <= f.negd)) {
            double s1 = b.z * f.pl.z + b.y * f.pl.y + b.x * f.pl.x;
            if (!(s1 <= f.negd)) {
                f.list.FUN_001c27c0();
                return false;
            }
            clip = true;
        } else {
            double s1 = b.z * f.pl.z + b.y * f.pl.y + b.x * f.pl.x;
            clip = !(s1 <= f.negd);
        }
        if (clip) {
            f.pl.FUN_0022e1f0(&a, &b, &f.t);
            float cx = (b.x - a.x) * f.t + a.x;
            f.f14 = (b.y - a.y) * f.t + a.y;
            f.f18 = (b.z - a.z) * f.t + a.z;
            double sa = a.z * f.pl.z + a.y * f.pl.y + a.x * f.pl.x;
            if (!(f.negd >= sa)) {
                a.x = cx;
                a.y = f.f14;
                a.z = f.f18;
            } else {
                b.x = cx;
                b.y = f.f14;
                b.z = f.f18;
            }
        }
    }
    owner->rig->tracker->inner->FUN_00059a50(&f.pos);
    if (f.list.FUN_001c27d0(&a) == 0) {
        f.f10 = f.pos.x;
        f.f14 = f.pos.y;
        f.f18 = f.pos.z;
        double d2 = (f.f18 - a.z) * (f.f18 - a.z) + (f.f14 - a.y) * (f.f14 - a.y) + (f.f10 - a.x) * (f.f10 - a.x);
        if (d2 < 1600.0f) {
            f.list.FUN_001c27c0();
            return false;
        }
    } else {
        f.f10 = f.pos.x;
        f.f14 = f.pos.y;
        f.f18 = f.pos.z;
        double d2 = (f.f18 - a.z) * (f.f18 - a.z) + (f.f14 - a.y) * (f.f14 - a.y) + (f.f10 - a.x) * (f.f10 - a.x);
        if (d2 < 6400.0f) {
            f.list.FUN_001c27c0();
            return false;
        }
        f.f10 = f.pos.x;
        f.f14 = f.pos.y;
        f.f18 = f.pos.z;
        double d3 = (f.f18 - b.z) * (f.f18 - b.z) + (f.f14 - b.y) * (f.f14 - b.y) + (f.f10 - b.x) * (f.f10 - b.x);
        if (d3 > 10000.0f) {
            f.list.FUN_001c27c0();
            return false;
        }
    }
    f.list.FUN_001c27c0();
    return true;
}
} // namespace fn_0007c5b0

namespace fn_f9399ba1 {

// 0x0007c930 FUN_0007c930 (370 B): equivalent/0x0007c930.cpp
// sym: ?FUN_0007c930@Group_7c930@fn_f9399ba1@@QAE_NUV3_7c930@2@H@Z @281e769fb9e8 @w7b54f2ebcb3a
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 13/14, incomplete)
// FUN_0007c930 @ 0x0007c930
bool Group_7c930::FUN_0007c930(V3_7c930 pos, int skip)
{
    V3_7c930 ref;
    if (skip != -1) {
        Mat_7c930 basis;
        env->lookup->FUN_001dd520(bodies[skip]->id, &basis);
        V3_7c930 axis;
        axis.x = -1.0f;
        axis.y = 0.0f;
        axis.z = 0.0f;
        ((owners::M_22c3b0 *)&basis)->FUN_0022c3b0((float *)(V3_7c930 *)(&axis), (float *)(V3_7c930 *)(&ref));
    }
    for (int i = 0; i < count; i++) {
        if (i == skip)
            continue;
        Mat_7c930 m;
        env->lookup->FUN_001dd520(bodies[i]->id, &m);
        V3_7c930 d;
        float dx = m.m[12] - pos.x;
        float dy = m.m[13] - pos.y;
        float dz = m.m[14] - pos.z;
        d.x = dx;
        d.y = dy;
        d.z = dz;
        if (!(dz * dz + dy * dy + dx * dx < 100.0f))
            continue;
        if (skip == -1)
            return true;
        d.FUN_0022d180();
        float dot = ref.z * d.z + ref.y * d.y + ref.x * d.x - 1.0f;
        float a = dot < 0.0f ? -dot : dot;
        if (a <= 1e-5f)
            return true;
    }
    return false;
}


// 0x0007cab0 FUN_0007cab0 (385 B): equivalent/0x0007cab0.cpp
// sym: ?FUN_0007cab0@Group_7cab0@fn_f9399ba1@@QAEXH@Z @d4618b87269d @w6c0366a3c185
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 25/26, incomplete)
// FUN_0007cab0 @ 0x0007cab0
void Group_7cab0::FUN_0007cab0(int limit)
{
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (found >= limit)
            break;
        if (items[i]->type == 0x13) {
            if (!context->manager->FUN_001dd800(items[i]->id)) {
                context->manager->FUN_001dda30(items[i]->id, 1);
                found++;
            }
        }
    }

    Vec3_7cab0 vec;
    context->holder->entity->position->FUN_00059a50(&vec);

    if (found >= limit)
        return;
    for (int i = 0; i < count; i++) {
        if (found >= limit)
            return;
        if (items[i]->type == 0x13) {
            Matrix m;
            context->manager->FUN_001dd520(items[i]->id, &m);
            float dx = vec.x - m.m[12];
            float dz = vec.z - m.m[14];
            bool a = context->manager->FUN_001dd800(items[i]->id);
            bool b = context->manager->FUN_001df4c0(items[i]->id);
            if (a && !b && dz * dz + dx * dx > 1600.0f) {
                context->manager->FUN_001dda30(items[i]->id, 1);
                found++;
            }
        }
    }
}


// 0x0007cc40 FUN_0007cc40 (91 B): matches/0x0007cc40.cpp
// sym: ?Add@Manager_7cc40@fn_f9399ba1@@QAEXPAVItem_7cc40@2@@Z
void Manager_7cc40::Add(Item_7cc40* item) {
    int index = Search_0007abe0(*(int*)((char*)item + 8), *(int*)((char*)item + 12));
    if (index < 0 || slots[index] == 0) {
        int n = count;
        if (n != 10) {
            item->A();
            if (slots[n])
                slots[n]->B();
            slots[n] = item;
            ++count;
        }
    }
}


// 0x0007ccf0 FUN_0007ccf0 (114 B): matches/0x0007ccf0.cpp
// sym: ?Remove@Obj_7ccf0@fn_f9399ba1@@QAEXH@Z
void Obj_7ccf0::Remove(int i) {
    if (count <= 0) {
        count = 0;
        return;
    }
    Item_7ccf0* p = slots[i];
    if (p) {
        p->G();
        slots[i] = 0;
    }
    slots[i] = slots[count - 1];
    slots[count - 1] = 0;
    count--;
}


// 0x0007cdb0 FUN_0007cdb0 (76 B): matches/0x0007cdb0.cpp
// sym: ?Run@Thing_7cdb0@fn_f9399ba1@@QAEXXZ
void Thing_7cdb0::Run() {
    while (mCount > 0) {
        int* p = mPtr;
        mHolder->mObj->Process_001e5bc0(p[4]);
        if (mPtr != 0 && mPtr == p)
            Cleanup_0007ccf0(0);
    }
}

} // namespace fn_f9399ba1

// 0x0007ce10 content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>::vfunc_0 (30 B): matches/0x0007ce10.cpp
// sym: ?vfunc_0@?$DynamicCaster@VCompositeDrawable@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    __RTDynamicCast((void*)((hulk_uintptr)p), 0, (void*)(&type_refcount), (void*)(&type_animation), 0);
}


// 0x0007ce30 FUN_0007ce30 (115 B): matches/0x0007ce30.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ??0Method5@fn_0007ce30@@QAE@HH@Z
namespace fn_0007ce30 {

extern "C" char DAT_0048e10c[];
class Base_7ce30 {
  public:
    Base_7ce30(int a, int b);
    virtual void f0();
    int pad4[3];
};

extern "C++" __declspec(nothrow) char GetFlag_001d04d0(const char* name);

class Method5 : public Base_7ce30 {
  public:
    Method5(hulk_intptr a, hulk_intptr b);
    virtual void f0();
    char m10, m11, m12, m13, m14;
    char pad15[3];
    char m18;
    char pad19[3];
    int m1c;
};

void Base_7ce30::f0() {}
void Method5::f0() {}

Method5::Method5(hulk_intptr a, hulk_intptr b) : Base_7ce30(a, 5) {
    m1c = b;
    m18 = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    m10 = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m11 = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    m12 = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    m13 = GetFlag_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    m14 = GetFlag_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
}
} // namespace fn_0007ce30


// 0x0007ceb0 Method5<CAmbientsManager,void,const_char_*,int,bool,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x0007ceb0.cpp
// sym: ??_G?$Method5@VCAmbientsManager@@XPBDH_NVVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method5<CAmbientsManager, void, const char *, int, bool,math::Vector,math::Vector>::~Method5() {}
#if defined(HULK_PTR64)
template class Method5<CAmbientsManager, void, const char *, int, bool,math::Vector,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7ceb0)
#endif


// 0x0007ced0 Method5<CAmbientsManager,void,const_char_*,int,bool,math::Vector,math::Vector>::vfunc_2 (119 B): equivalent/0x0007ced0.cpp [wrapped: conflict: CAmbientsManager; Function; Method5]
// sym: ?vfunc_2@Method5@fn_0007ced0@@UAEXPAVCAmbientsManager@2@TArgsSlot@2@PAX@Z @ab324c6eedb7 @w8be8d86a032f
namespace fn_0007ced0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method5<CAmbientsManager,void,const_char_*,int,bool,math::Vector,math::Vector>::vfunc_2 @ 0x0007ced0
namespace math {
struct Vector {
    float x, y, z;
};
}
class CAmbientsManager {
public:
    // The flag is passed as a full dword (its upper bytes are whatever the caller's slot held).
    void Dummy(const char* name, int n, unsigned int flag, math::Vector a, math::Vector b);
};
typedef void (CAmbientsManager::*AmbientFn)(const char* name, int n, unsigned int flag, math::Vector a, math::Vector b);
struct Args_7ced0 {
    const char* name;
    int n;
    bool flag;
    char pad9[3];
    math::Vector a;
    math::Vector b;
};
// The incoming args pointer is dead once read, and its stack slot then carries the flag byte.
union ArgsSlot {
    Args_7ced0* args;
    bool flag;
    unsigned int word;
};
class Function {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method5 : public Function {
public:
    char pad04[0x18];
    AmbientFn fn;
    virtual void vfunc_2(CAmbientsManager* owner, ArgsSlot slot, void* result);
};
void Method5::vfunc_2(CAmbientsManager* owner, ArgsSlot slot, void* result) {
    Args_7ced0* args = slot.args;
    const char* name = args->name;
    int n = args->n;
    slot.flag = args->flag;
    (owner->*fn)(name, n, slot.word, args->a, args->b);
}
} // namespace fn_0007ced0


// 0x0007cfa0 Method2<CAmbientsManager,void,const_char_*,bool>::vfunc_0 (30 B): matches/0x0007cfa0.cpp
// sym: ??_G?$Method2@VCAmbientsManager@@XPBD_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CAmbientsManager, void, const char *, bool>::~Method2() {}


// 0x0007cfc0 Method2<CAmbientsManager,void,const_char_*,bool>::vfunc_2 (25 B): matches/0x0007cfc0.cpp
// sym: ?vfunc_2@?$Method2@VCAmbientsManager@@XPBD_N@@UAEXPAX00@Z
template <> void Method2<CAmbientsManager, void, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CAmbientsManager_7cfc0 * obj = (CAmbientsManager_7cfc0 *)__p0; void * args = (void *)__p1; void * unused = (void *)__p2;

    struct Args {
        const char* s;
        bool b;
    };
    Args* a = (Args*)args;
    (obj->*(*(void (CAmbientsManager_7cfc0::**)(const char *, bool))&this->f_1c))(a->s, a->b);
}
#if defined(HULK_PTR64)
template class Method2<CAmbientsManager, void, const char *, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7cfa0)
#endif


// 0x0007d020 Method0<CAmbientsManager,void>::vfunc_0 (30 B): matches/0x0007d020.cpp
// sym: ??_G?$Method0@VCAmbientsManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CAmbientsManager, void>::~Method0() {}


// 0x0007d040 Method0<CAmbientsManager,void>::vfunc_2 (12 B): matches/0x0007d040.cpp
// sym: ?vfunc_2@?$Method0@VCAmbientsManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<CAmbientsManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_7d040 * a = (CActorManager_7d040 *)__p0;

    (a->*(*(void (CActorManager_7d040::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Method0<CAmbientsManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7d020)
#endif


// 0x0007d050 FUN_0007d050 (89 B): matches/0x0007d050.cpp [wrapped: conflict: Method3]
// sym: ??0Method3@fn_0007d050@@QAE@PBDH@Z
namespace fn_0007d050 {

class Function_7d050 {
  public:
    Function_7d050(const char*, int);
    virtual void f();
};
extern "C++" __declspec(nothrow) unsigned char __cdecl check_001d04d0(const char*);
class Method3 : public Function_7d050 {
  public:
    Method3(const char*, hulk_intptr);
    virtual void f();
    char pad[12];
    unsigned char x, y, z;
    char pad2[5];
    unsigned char w;
    char pad3[3];
    int n;
};
Method3::Method3(const char* s, hulk_intptr k) : Function_7d050(s, 3) {
    n = k;
    w = check_001d04d0(((const char*)&DAT_0048e100));
    x = check_001d04d0(((const char*)&DAT_0048e0f0));
    y = check_001d04d0(((const char*)&DAT_0048e134));
    z = check_001d04d0(((const char*)&DAT_0048e0e4));
}
} // namespace fn_0007d050


// 0x0007d0b0 Method3<CAmbientsManager,void,const_char_*,int,bool>::vfunc_0 (30 B): matches/0x0007d0b0.cpp
// sym: ??_G?$Method3@VCAmbientsManager@@XPBDH_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CAmbientsManager, void, const char *, int, bool>::~Method3() {}


// 0x0007d0d0 Method3<CAmbientsManager,void,const_char_*,int,bool>::vfunc_2 (31 B): equivalent/0x0007d0d0.cpp
// sym: ?vfunc_2@?$Method3@VCAmbientsManager@@XPBDH_N@@UAEXPAX00@Z @df298f4335fd @w022c10218034
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CAmbientsManager,void,const_char_*,int,bool>::vfunc_2 @ 0x0007d0d0
template <> void Method3<CAmbientsManager, void, const char *, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CAmbientsManager_7d0d0 * manager = (CAmbientsManager_7d0d0 *)__p0; AmbientArgs * args = (AmbientArgs *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CAmbientsManager_7d0d0::**)(const char *, int, int))&this->f_1c))(args->name, args->value, args->enabled);
}
#if defined(HULK_PTR64)
template class Method3<CAmbientsManager, void, const char *, int, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7d0b0)
#endif


// 0x0007d130 Method1<CAmbientsManager,void,const_char_*>::vfunc_0 (30 B): matches/0x0007d130.cpp
// sym: ??_G?$Method1@VCAmbientsManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CAmbientsManager, void, const char *>::~Method1() {}


// 0x0007d150 Method1<CAmbientsManager,void,const_char_*>::vfunc_2 (19 B): matches/0x0007d150.cpp
// sym: ?vfunc_2@?$Method1@VCAmbientsManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CAmbientsManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_7d150* d = (Dummy_7d150*)a;
    (d->*(*(void (Dummy_7d150::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CAmbientsManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7d130)
#endif


// 0x0007d1b0 Method1<CAmbientsManager,void,int>::vfunc_0 (30 B): matches/0x0007d1b0.cpp
// sym: ??_G?$Method1@VCAmbientsManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CAmbientsManager, void, int>::~Method1() {}


// 0x0007d1d0 Method1<CAmbientsManager,void,int>::vfunc_2 (19 B): matches/0x0007d1d0.cpp
// sym: ?vfunc_2@?$Method1@VCAmbientsManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CAmbientsManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_7d1d0* d = (Dummy_7d1d0*)a;
    (d->*(*(void (Dummy_7d1d0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CAmbientsManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7d1b0)
#endif


// 0x0007d230 Method1<CAmbientsManager,void,float>::vfunc_0 (30 B): matches/0x0007d230.cpp
// sym: ??_G?$Method1@VCAmbientsManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CAmbientsManager, void, float>::~Method1() {}


// 0x0007d250 Method1<CAmbientsManager,void,float>::vfunc_2 (19 B): matches/0x0007d250.cpp
// sym: ?vfunc_2@?$Method1@VCAmbientsManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CAmbientsManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_7d250* d = (Dummy_7d250*)a;
    (d->*(*(void (Dummy_7d250::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CAmbientsManager, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7d230)
#endif


// 0x0007d2c0 Method2<CAmbientsManager,void,float,float>::vfunc_0 (30 B): matches/0x0007d2c0.cpp
// sym: ??_G?$Method2@VCAmbientsManager@@XMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CAmbientsManager, void, float, float>::~Method2() {}


// 0x0007d2e0 Method2<CAmbientsManager,void,float,float>::vfunc_2 (23 B): matches/0x0007d2e0.cpp
// sym: ?vfunc_2@?$Method2@VCAmbientsManager@@XMM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CAmbientsManager, void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_7d2e0* m = (CFEManager_7d2e0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_7d2e0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CAmbientsManager, void, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7d2c0)
#endif


// 0x0007d340 Method1<CAmbientsManager,void,bool>::vfunc_0 (30 B): matches/0x0007d340.cpp
// sym: ??_G?$Method1@VCAmbientsManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CAmbientsManager, void, bool>::~Method1() {}


// 0x0007d360 Method1<CAmbientsManager,void,bool>::vfunc_2 (21 B): matches/0x0007d360.cpp
// sym: ?vfunc_2@?$Method1@VCAmbientsManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<CAmbientsManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_7d360 * obj = (CActorManager_7d360 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_7d360 *)&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CAmbientsManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7d340)
#endif

namespace fn_f9399ba1 {

// 0x0007d380 FUN_0007d380 (102 B): matches/0x0007d380.cpp
// sym: ??0Method4_7d380@fn_f9399ba1@@QAE@PBDP8Owner_7d380@1@AEXXZ@Z
Method4_7d380::Method4_7d380(const char* p, Fn_7d380 x) {
    Init_001d0480(p, 4);
    vptr = (void*)DAT_003ff014;
    member1c = x;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e134));
    f.argTypes[2] = FUN_001d04d0(hulk_at_0048e10c);
    f.argTypes[3] = FUN_001d04d0(hulk_at_0048e10c);
}

} // namespace fn_f9399ba1

// 0x0007d3f0 Method4<CAmbientsManager,void,const_char_*,int,const_math::Vector,const_math::Vector>::vfunc_0 (30 B): matches/0x0007d3f0.cpp
// sym: ??_G?$Method4@VCAmbientsManager@@XPBDH$$CBVVector@math@@$$CBV23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CAmbientsManager, void, const char *, int, const ::math::Vector, const ::math::Vector>::~Method4() {}


// 0x0007d410 Method4<CAmbientsManager,void,const_char_*,int,const_math::Vector,const_math::Vector>::vfunc_2 (106 B): matches/0x0007d410.cpp
// sym: ?vfunc_2@?$Method4@VCAmbientsManager@@XPBDH$$CBVVector@math@@$$CBV23@@@UAEXPAX00@Z
template <> void Method4<CAmbientsManager, void, const char *, int, const ::math::Vector, const ::math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CAmbientsManager_7d410 * o = (CAmbientsManager_7d410 *)__p0; char * a = (char *)__p1; hulk_intptr u = (hulk_intptr)__p2;

    char* p = a;
    const char* s = *(const char**)p;
    p += 4;
    int i = *(int*)p;
    p += 4;
    math::Vector_7d410 va = *(math::Vector_7d410*)p;
    p += 12;
    math::Vector_7d410 vb = *(math::Vector_7d410*)p;
    (o->*(*(void (CAmbientsManager_7d410::**)(const char *, int, const math::Vector_7d410, const math::Vector_7d410))&this->f_1c))(s, i, va, vb);
}
#if defined(HULK_PTR64)
template class Method4<CAmbientsManager, void, const char *, int, const ::math::Vector, const ::math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7d3f0)
#endif


// 0x0007d4e0 Method3<CAmbientsManager,void,const_char_*,unsigned_int,float>::vfunc_0 (30 B): matches/0x0007d4e0.cpp
// sym: ??_G?$Method3@VCAmbientsManager@@XPBDIM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CAmbientsManager, void, const char *, unsigned int, float>::~Method3() {}


// 0x0007d500 Method3<CAmbientsManager,void,const_char_*,unsigned_int,float>::vfunc_2 (29 B): equivalent/0x0007d500.cpp
// sym: ?vfunc_2@?$Method3@VCAmbientsManager@@XPBDIM@@UAEXPAX00@Z @a7a6d240b96d @w7a58705a9035
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CAmbientsManager,void,const_char_*,unsigned_int,float>::vfunc_2 @ 0x0007d500
template <> void Method3<CAmbientsManager, void, const char *, unsigned int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CAmbientsManager_7d500 * manager = (CAmbientsManager_7d500 *)__p0; const Args * args = (const Args *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CAmbientsManager_7d500::**)(const char *, unsigned int, float))&this->f_1c))(args->name, args->value, args->amount);
}
#if defined(HULK_PTR64)
template class Method3<CAmbientsManager, void, const char *, unsigned int, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7d4e0)
#endif


// 0x0007d570 Method2<CAmbientsManager,void,const_char_*,float>::vfunc_0 (30 B): matches/0x0007d570.cpp
// sym: ??_G?$Method2@VCAmbientsManager@@XPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CAmbientsManager, void, const char *, float>::~Method2() {}


// 0x0007d590 Method2<CAmbientsManager,void,const_char_*,float>::vfunc_2 (23 B): matches/0x0007d590.cpp
// sym: ?vfunc_2@?$Method2@VCAmbientsManager@@XMM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CAmbientsManager, void, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_7d590* m = (CFEManager_7d590*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_7d590::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CAmbientsManager, void, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7d570)
#endif

namespace fn_f9399ba1 {

// 0x0007d5b0 FUN_0007d5b0 (144 B): matches/0x0007d5b0.cpp
// sym: ?Reset@Mgr_7d5b0@fn_f9399ba1@@QAEXXZ
void Mgr_7d5b0::Reset() {
    for (int i = 0; i < 20; i++) {
        if (objs[i]) {
            objs[i]->Release();
            objs[i] = 0;
        }
    }
    v3548 = 0;
    while (v359c > 0)
        FnA_0007b3e0(0);
    v3640 = 0;
    v3740 = 0;
    while (v379c > 0)
        FnB_0007b880(0);
    for (int i = 0; i < 0x320; i++)
        flags[i * 8] = 0;
    FnC_0007cdb0();
    v3828 = 0;
    v37fc = 0;
}

} // namespace fn_f9399ba1

// 0x0007d640 FUN_0007d640 (56 B): matches/0x0007d640.cpp [wrapped: conflict: Owner]
// sym: ?run@Owner@fn_0007d640@@QAEXHH@Z
namespace fn_0007d640 {
struct Pair {
    int a, b;
};
Pair __cdecl lookup_0027b020(int);
class Item {
  public:
    void apply_00080c80(int);
};
class Owner {
    char pad[0x354c];
    Item* items[1];

  public:
    int locate_00079220(int, int);
    void run(int key, int value);
};
void Owner::run(int key, int value) {
    Pair p = lookup_0027b020(key);
    int i = locate_00079220(p.a, p.b);
    if (i >= 0 && items[i])
        items[i]->apply_00080c80(value);
}
} // namespace fn_0007d640


// 0x0007d680 FUN_0007d680 (51 B): matches/0x0007d680.cpp [wrapped: conflict: Obj]
// sym: ?fn@Obj@fn_0007d680@@QAEXHH@Z
namespace fn_0007d680 {
struct Pair {
    int a, b;
};
extern "C++" __declspec(nothrow) Pair __cdecl getPair_0027b020(int);
class Item {
  public:
    void act_00083d30(int);
};
class Obj {
    char pad[0x374c];
    Item* items[1];

  public:
    int find_000797b0(int, int);
    void fn(int x, int y);
};
void Obj::fn(int x, int y) {
    Pair p = getPair_0027b020(x);
    int i = find_000797b0(p.a, p.b);
    if (i != -1)
        items[i]->act_00083d30(y);
}
} // namespace fn_0007d680


// 0x0007d6c0 FUN_0007d6c0 (59 B): matches/0x0007d6c0.cpp [wrapped: conflict: Obj]
// sym: ?Run@Obj@fn_0007d6c0@@QAEXHM@Z
namespace fn_0007d6c0 {
struct Item {
    char pad[0x1c];
    float value;
    void Set_00083d30(float);
};
class Obj {
  public:
    char pad[0x374c];
    Item* items[1];
    int Find_000797b0(__int64);
    void Run(int id, float delta);
};
extern __int64 __cdecl Convert_0027b020(int);
void Obj::Run(int id, float delta) {
    __int64 x = Convert_0027b020(id);
    int index = Find_000797b0(x);
    if (index != -1) {
        Item* p = items[index];
        p->Set_00083d30(p->value + delta);
    }
}
} // namespace fn_0007d6c0


// 0x0007d700 FUN_0007d700 (825 B): equivalent/0x0007d700.cpp [wrapped: conflict: FUN_000964d0; World]
// sym: ?FUN_0007d700@Spawner_7d700@fn_0007d700@@QAEXPBDHHH@Z @83c112affed3 @wadf8efdd7b7b
namespace fn_0007d700 {
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 38/38)
// FUN_0007d700 @ 0x0007d700
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

void* __cdecl FUN_00263ea0(unsigned int size) throw();

struct Vec3_7d700 {
    float x, y, z;
};

struct Cell_7d700 {
    Vec3_7d700 a;
    Vec3_7d700 b;
    int f18;
    int f1c;
    char pad20[8];
    int count;
    char pad2c[0x48 - 0x2c];
};

struct Entry_7d700 {
    unsigned __int64 hash;
    int f08;
    int f0c;
};

struct Flags_7d700 {
    bool FUN_00092940(int id);
};

struct Opt_7d700 {
};

struct World {
    char pad00[0x54];
    Opt_7d700* opt;
};

struct Sim_7d700 {
    hulk_freg FUN_000787e0(unsigned __int64 id);
};

struct Wing {
    char pad00[0xc];
    struct Node* node;
};

struct Node {
    void FUN_001dc2d0(int id, int variant);
    void FUN_001dd890(int id, int flag);
};

struct Holder_7d700 {
    char pad00[0xc];
    Node* node;
};

class CVehicle_7d700 {
public:
    virtual void v0();
    virtual void v1();
    char pad04[0xc8 - 4];
    CVehicle_7d700* FUN_00083c30(const char* name, int id, int rowField, int a4, int f18, Vec3_7d700 a, Vec3_7d700 b, float speed, int idx);
    void FUN_00083d50(float v);
    void FUN_00083d60(float v);
    void FUN_00083d70(float v);
};


void __cdecl FUN_00224d70(float angle, Vec3_7d700* v);
Sim_7d700* __cdecl FUN_000964d0();

union VariantOrSpeed {
    int variant;
    float speed;
};

class Spawner_7d700 {
public:
    char pad0000[0x1904];
    Cell_7d700 cells[1];
    char pad194c[0x3650 - 0x1904 - sizeof(Cell_7d700)];
    Entry_7d700 entries[1];
    char pad3660[0x3718 - 0x3650 - sizeof(Entry_7d700)];
    int counts[1];
    char pad371c[0x3740 - 0x371c];
    int count;
    char pad3744[0x37a4 - 0x3744];
    unsigned int id37a4;
    unsigned int id37a8;
    char pad37ac[0x382c - 0x37ac];
    Holder_7d700* holder;
    int FUN_000798a0(unsigned __int64 id);
    int FUN_000796e0(Entry_7d700* entry, const char* name, Cell_7d700* cell, Vec3_7d700* dir, int a, int b, int c);
    int FUN_0007b820(CVehicle_7d700* v);
    void FUN_0007d700(const char* name, int idx, int row, int col);
};

void Spawner_7d700::FUN_0007d700(const char* name, int idx, int row, int col)
{
    if (idx < 0 || idx >= count)
        return;
    if (FUN_000798a0(FUN_0027b020(name)) != 0)
        return;
    Cell_7d700* cell = (Cell_7d700*)((char*)this + (row * 14 + col) * 0x48 + 0x1904);
    Entry_7d700* entry = (Entry_7d700*)((char*)this + 0x3650 + idx * 16);
    Vec3_7d700 d;
    d.x = cell->b.x - cell->a.x;
    d.y = cell->b.y - cell->a.y;
    d.z = cell->b.z - cell->a.z;
    FUN_00224d70(1.5707964f, &d);
    Sim_7d700* sim = FUN_000964d0();
    VariantOrSpeed slot;
    slot.variant = ((int)((owners::Random_11330 *)sim)->FUN_00011330((unsigned int)(entry->f08 - 1)));
    Node* node = holder->node;
    Flags_7d700* flags = ((Flags_7d700 *)((owners::A_86340 *)(DAT_004dd700->opt))->FUN_00086340());
    if (flags->FUN_00092940(0x26)) {
        if (((*(unsigned*)&DAT_004dd060) & 1) == 0) {
            (*(unsigned*)&DAT_004dd060) |= 1;
            (*(unsigned __int64*)&DAT_004dd058) = FUN_0027b020("bus1_bus1");
        }
        if (count > 0) {
            int i = 0;
            do {
                Entry_7d700* e = (Entry_7d700*)((char*)this + 0x3650 + i * 16);
                if (e->hash == (*(unsigned __int64*)&DAT_004dd058)) {
                    entry = e;
                    slot.variant = 0;
                    break;
                }
                i++;
            } while (i < count);
        }
    } else if (flags->FUN_00092940(0x16)) {
        if (((*(unsigned*)&DAT_004dd060) & 2) == 0) {
            (*(unsigned*)&DAT_004dd060) |= 2;
            (*(unsigned __int64*)&DAT_004dd050) = FUN_0027b020("carPT_carPT");
        }
        if (count > 0) {
            int i = 0;
            do {
                Entry_7d700* e = (Entry_7d700*)((char*)this + 0x3650 + i * 16);
                if (e->hash == (*(unsigned __int64*)&DAT_004dd050)) {
                    entry = e;
                    slot.variant = 1;
                    break;
                }
                i++;
            } while (i < count);
        }
    }
    int id = FUN_000796e0(entry, name, cell, &d, 0, 0, 0);
    if (id == -1)
        return;
    node->FUN_001dc2d0(id, slot.variant);
    node->FUN_001dd890(id, 1);
    slot.speed = sim->FUN_000787e0((unsigned __int64)id37a8 << 32 | id37a4);
    if (flags->FUN_00092940(0x25))
        slot.speed = slot.speed + slot.speed;
    CVehicle_7d700* v;
    void* mem = FUN_00263ea0(0xc8);
    if (mem != 0) {
        Cell_7d700* rowCell = (Cell_7d700*)((char*)this + row * 0x3f0 + 0x1904);
        v = ((CVehicle_7d700*)mem)->FUN_00083c30(name, id, rowCell->f1c, col, cell->f18, cell->a, cell->b, slot.speed, idx);
    } else {
        v = 0;
    }
    v->v0();
    if (FUN_0007b820(v) != -1) {
        v->FUN_00083d50((*(float*)&DAT_0049b888));
        v->FUN_00083d60((*(float*)&DAT_0049b88c));
        v->FUN_00083d70((*(float*)&DAT_0049b890));
        counts[idx]++;
        cell->count++;
    }
    v->v1();
}
} // namespace fn_0007d700
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f9399ba1 {

// 0x0007da40 FUN_0007da40 (38 B): matches/0x0007da40.cpp
// sym: ?target@Obj_7da40@fn_f9399ba1@@QAEXPAUPair_7da40@2@@Z
void Obj_7da40::target(Pair_7da40* p) {
    int i = first_000797b0(p->a, p->b);
    if (i != -1)
        second_0007b880(i);
}


// 0x0007da70 FUN_0007da70 (271 B): equivalent/0x0007da70.cpp
// sym: ?target@State_7da70@fn_f9399ba1@@QAEXH@Z @99c5a7864134 @w6b2d9c55ce3f
// STATUS: equivalent (tools/equiv.py level 3: 535 inputs, branch coverage 31/32, incomplete)
// FUN_0007da70 @ 0x0007da70
void State_7da70::target(int unused) {
 Group_7da70* group=((Group_7da70 *)((owners::Target_862a0 *)(owner->resolver))->FUN_000862a0());
 int ids[7]; ids[0]=group->id;
 if(ids[0]==current) return;
 current=ids[0];
 for(int i=0;i<6;++i) ids[i+1]=((::CWorldStreamManager *)group)->FUN_002042a0(i, ids[0]);
 for(int s=0;s<7;++s) { if(slots[s].id!=0) { int j; for(j=0;j<7;++j) if(slots[s].id==ids[j]) break; if(j==7) slots[s].id=0; } }
 for(int k=0;k<count;++k) { Item_7da70* item=items[k]; if(item->type!=0x13) { int j; for(j=0;j<7;++j) if(item->id==ids[j]) break; if(j==7) { FUN_0007b880(k); --k; } } }
 for(int n=0;n<7;++n) { if(ids[n]!=-1) { int j; for(j=0;j<7;++j) if(slots[j].id==ids[n]) break; if(j==7) FUN_0007bbd0(ids[n]); } }
}


// 0x0007db80 FUN_0007db80 (636 B): equivalent/0x0007db80.cpp
// sym: ?FUN_0007db80@Spawner_7db80@fn_f9399ba1@@QAEXPAH0@Z @e9eeb469427d @w4870fa8bf406
// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 29/30, incomplete)
// FUN_0007db80 @ 0x0007db80
void Spawner_7db80::FUN_0007db80(int *outSlot, int *outItem)
{
    V3_7db80 pos;
    int cands[14];
    owner->next->inner->ref->FUN_00059a50(&pos);

    int start = NextRandom() % 7;
    for (int i = 0; i < 7; i++) {
        int slot = (i + start) % 7;
        Item_7db80 *group = &items[slot * 14];
        if (group[0].count <= 0)
            continue;
        int n = 0;
        for (int j = 0; j < 14; j++) {
            Item_7db80 *it = &group[j];
            if (!it->flag)
                break;
            // the original keeps the three differences in st0..st2 (never rounded to float)
            hulk_freg dx = pos.x - it->a.x;
            hulk_freg dy = pos.y - it->a.y;
            hulk_freg dz = pos.z - it->a.z;
            if (it->state >= 3)
                continue;
            if (!(dz * dz + dy * dy + dx * dx < 10000.0f))
                continue;
            if (!FUN_0007c5b0(it->a, it->b))
                continue;
            if (it->u != -1 && it->v != -1) {
                Item_7db80 *other = &items[it->u * 14 + it->v];
                if (other->flag && other->state >= 3)
                    continue;
            }
            cands[n] = j;
            n++;
        }
        if (n == 0)
            continue;
        int r = NextRandom() % (unsigned int)n;
        for (int k = 0; k < n; k++) {
            int j = cands[(k + r) % n];
            if (!FUN_0007c930(items[slot * 14 + j].a, -1)) {
                *outSlot = slot;
                *outItem = j;
                return;
            }
        }
    }
    *outSlot = -1;
    *outItem = -1;
}

} // namespace fn_f9399ba1

// 0x0007de00 FUN_0007de00 (233 B): equivalent/0x0007de00.cpp [wrapped: conflict: FUN_000964d0; FUN_00263ea0]
// sym: ?target@Manager_7de00@fn_0007de00@@QAEXPBDHUVec3_7de00@2@1@Z @569285ee1564 @w0109cd7edf41
namespace fn_0007de00 {
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 11/12, incomplete)
// FUN_0007de00 @ 0x0007de00
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

typedef unsigned __int64 U64_7de00;
struct Vec3_7de00 { float x,y,z; };
struct Name_7de00 { void FUN_0027b0e0(const char*); };
extern "C" void __cdecl FUN_00363c40();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern int __cdecl _atexit(void (__cdecl*)());
#endif

struct Loaded_7de00 { void FUN_001dd8e0(int,int); };
struct Container_7de00 { char pad[12]; Loaded_7de00* loaded; };
struct Factory_7de00 {  };
extern Factory_7de00* __cdecl FUN_000964d0();
struct Object { virtual void slot0(); virtual void slot1(); Object* FUN_000831c0(const char*,int,int,Vec3_7de00*,Vec3_7de00*); };
extern Object* __cdecl FUN_00263ea0(unsigned);
struct Manager_7de00 {
 char pad[0x3800]; Object* objects[11]; Container_7de00* container;
 int FUN_0007abe0(U64_7de00);
 int FUN_000796e0(Name_7de00*,const char*,Vec3_7de00*,Vec3_7de00*,int,int,int);
 void FUN_0007cc40(Object*);
 void target(const char*,int,Vec3_7de00,Vec3_7de00);
};
void Manager_7de00::target(const char* name,int unused,Vec3_7de00 a,Vec3_7de00 b) {
 int index=FUN_0007abe0(FUN_0027b020(name));
 if(index>=0 && objects[index]) return;
 if(!(DAT_004dd070 & 1)) { DAT_004dd070 |= 1; (*(Name_7de00*)&DAT_004dd068).FUN_0027b0e0("cow_male_cow_male"); _atexit(FUN_00363c40); }
 int id=FUN_000796e0(((Name_7de00*)&DAT_004dd068),name,&a,&b,0,0,1);
 if(id==-1) return;
 container->loaded->FUN_001dd8e0(id,1);
 ((owners::Random_11330 *)(FUN_000964d0()))->FUN_00011330(3);
 Object* obj=FUN_00263ea0(0x50);
 if(!obj) return;
 obj=obj->FUN_000831c0(name,id,0,&a,&b);
 if(!obj) return;
 obj->slot0(); FUN_0007cc40(obj); obj->slot1();
}
} // namespace fn_0007de00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0007def0 FUN_0007def0 (30 B): matches/0x0007def0.cpp
// sym: ?FUN_0007def0@C_7def0@owners@@QAEXH@Z
void owners::C_7def0::FUN_0007def0(hulk_intptr p) {
    int i = ac30(((int)p));
    if (i != -1)
        ccf0(i);
}


// 0x0007df70 Closure5<CAmbientsManager,void,const_char_*,int,bool,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x0007df70.cpp
// sym: ??_G?$Method1@VCAmbientsManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure5<CAmbientsManager, void, const char *, int, bool,math::Vector,math::Vector>::~Closure5() {}
#if defined(HULK_PTR64)
template class Closure5<CAmbientsManager, void, const char *, int, bool,math::Vector,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7df70)
#endif


// 0x0007df90 Closure5<CAmbientsManager,void,const_char_*,int,bool,math::Vector,math::Vector>::vfunc_2 (12 B): matches/0x0007df90.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure2@fn_0007df90@@UAEXHHH@Z
namespace fn_0007df90 {
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
    char pad[0x18];
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
} // namespace fn_0007df90

namespace fn_f9399ba1 {

// 0x0007dfa0 FUN_0007dfa0 (89 B): matches/0x0007dfa0.cpp
// sym: ??0Closure2_7dfa0@fn_f9399ba1@@QAE@PBDPAVOwner_7dfa0@1@P821@AEXXZ@Z
// data: a_7dfa0 = DAT_0048e100
// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
Closure2_7dfa0::Closure2_7dfa0(const char* s, Owner_7dfa0* v, Fn_7dfa0 w) : Method2_7dfa0(s, w) {
    extra = v;
}

} // namespace fn_f9399ba1

// 0x0007e000 Closure2<CAmbientsManager,void,const_char_*,bool>::vfunc_0 (30 B): matches/0x0007e000.cpp
// sym: ??_G?$Method1@VCAmbientsManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CAmbientsManager, void, const char *, bool>::~Closure2() {}


// 0x0007e020 Closure2<CAmbientsManager,void,const_char_*,bool>::vfunc_2 (24 B): matches/0x0007e020.cpp
// sym: ?vfunc_2@?$Closure2@VCAmbientsManager@@XPBD_N@@UAEXPAX00@Z
// Same code shape as 0x0002ec60 (propagated; names are from that function)
template <> void Closure2<CAmbientsManager, void, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_7e020 * p = (Arg_7e020 *)__p1;

    ((*(Actor_7e020 * *)&this->f_20)->*(*(void (Actor_7e020::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}
#if defined(HULK_PTR64)
template class Closure2<CAmbientsManager, void, const char *, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7e000)
#endif


// 0x0007e080 Closure0<CAmbientsManager,void>::vfunc_0 (30 B): matches/0x0007e080.cpp
// sym: ??_G?$Method2@VCAmbientsManager@@XMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CAmbientsManager, void>::~Closure0() {}


// 0x0007e0a0 Closure0<CAmbientsManager,void>::vfunc_2 (11 B): matches/0x0007e0a0.cpp
// sym: ?vfunc_2@?$Closure0@VCAmbientsManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<CAmbientsManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_7e0a0 * *)&this->f_20)->*(*(void (CActorManager_7e0a0::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Closure0<CAmbientsManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7e080)
#endif


// 0x0007e0e0 Closure3<CAmbientsManager,void,const_char_*,int,bool>::vfunc_0 (30 B): matches/0x0007e0e0.cpp
// sym: ??_G?$Method1@VCAmbientsManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CAmbientsManager, void, const char *, int, bool>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<CAmbientsManager, void, const char *, int, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7e0e0)
#endif


// 0x0007e120 FUN_0007e120 (76 B): matches/0x0007e120.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0007e120@@QAE@PBDPAVOwner_7e120@1@P821@AEXXZ@Z
namespace fn_0007e120 {
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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern const char hulk_at_0048e100[], hulk_at_0048e0f0[];
class Function_7e120 : public CtorV_001d0480 {
  public:
    Function_7e120(const char* s) : CtorV_001d0480(s, 1) { }
};
class Owner_7e120 {};
typedef void (Owner_7e120::*Fn_7e120)();
class Method1 : public Function_7e120 {
  public:
    virtual void f();
    Fn_7e120 name;
    Method1(const char* s, Fn_7e120 p) : Function_7e120(s) {
        name = p;
        retType = FUN_001d04d0(hulk_at_0048e100);
        argTypes[0] = FUN_001d04d0(hulk_at_0048e0f0);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    Owner_7e120* obj;
    Closure1(const char*, Owner_7e120*, Fn_7e120);
};
Closure1::Closure1(const char* s, Owner_7e120* o, Fn_7e120 p) : Method1(s, p) {
    obj = o;
}
} // namespace fn_0007e120
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0007e170 Closure1<CAmbientsManager,void,const_char_*>::vfunc_0 (30 B): matches/0x0007e170.cpp
// sym: ??_G?$Method3@VCAmbientsManager@@XPBDIM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CAmbientsManager, void, const char *>::~Closure1() {}


// 0x0007e190 Closure1<CAmbientsManager,void,const_char_*>::vfunc_2 (18 B): matches/0x0007e190.cpp
// sym: ?vfunc_2@?$Closure1@VCAmbientsManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CAmbientsManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_7e190 * *)&this->f_20)->*(*(void (CActorManager_7e190::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CAmbientsManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7e170)
#endif


// 0x0007e1b0 FUN_0007e1b0 (76 B): matches/0x0007e1b0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0007e1b0@@QAE@PBDPAVOwner_7e1b0@1@P821@AEXH@Z@Z
namespace fn_0007e1b0 {
// data: key1 = DAT_0048e100, key2 = DAT_0048e134
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C++" __declspec(nothrow) unsigned char Decode_001d04d0(const void*);
class Function_7e1b0 : public CtorV_001d0480 {
  public:
    Function_7e1b0(const char* p) : CtorV_001d0480(p, 1) { }
};
class Owner_7e1b0 {};
typedef void (Owner_7e1b0::*Fn_7e1b0)(int);
class Method1 : public Function_7e1b0 {
  public:
    virtual void Invoke(int);
    Fn_7e1b0 arg;
    Method1(const char* p, Fn_7e1b0 x) : Function_7e1b0(p) {
        arg = x;
        retType = Decode_001d04d0(((int*)&DAT_0048e100));
        argTypes[0] = Decode_001d04d0(((int*)&DAT_0048e134));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(int);
    Owner_7e1b0* data;
    Closure1(const char*, Owner_7e1b0*, Fn_7e1b0);
};
Closure1::Closure1(const char* p, Owner_7e1b0* x, Fn_7e1b0 y) : Method1(p, y) {
    data = x;
}
} // namespace fn_0007e1b0


// 0x0007e200 Closure1<CAmbientsManager,void,int>::vfunc_0 (30 B): matches/0x0007e200.cpp
// sym: ??_G?$Method2@VCAmbientsManager@@XPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CAmbientsManager, void, int>::~Closure1() {}


// 0x0007e220 Closure1<CAmbientsManager,void,int>::vfunc_2 (18 B): matches/0x0007e220.cpp
// sym: ?vfunc_2@?$Closure1@VCAmbientsManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CAmbientsManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_7e220 * *)&this->f_20)->*(*(void (CActorManager_7e220::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CAmbientsManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7e200)
#endif


// 0x0007e240 FUN_0007e240 (76 B): matches/0x0007e240.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0007e240@@QAE@PBDPAVCAmbientsManager_7e240@1@P821@AEXM@Z@Z
namespace fn_0007e240 {
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

// Closure1<CAmbientsManager, void, float>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class CAmbientsManager_7e240 {};
typedef void (CAmbientsManager_7e240::*Fn_7e240)(float);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_7e240 : public CtorV_001d0480 {
  public:
    Function_7e240(const char* x) : CtorV_001d0480(x, 1) { }
};
class Method1 : public Function_7e240 {
  public:
    virtual void Invoke(float);
    Fn_7e240 obj;
    Method1(const char* x, Fn_7e240 z) : Function_7e240(x) {
        obj = z;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(float);
    CAmbientsManager_7e240* extra;
    Closure1(const char*, CAmbientsManager_7e240*, Fn_7e240);
};
Closure1::Closure1(const char* x, CAmbientsManager_7e240* y, Fn_7e240 z) : Method1(x, z) {
    extra = y;
}
} // namespace fn_0007e240
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0007e2b0 Closure1<CAmbientsManager,void,float>::vfunc_2 (18 B): matches/0x0007e2b0.cpp
// sym: ?vfunc_2@?$Closure1@VCAmbientsManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CAmbientsManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_7e2b0 * *)&this->f_20)->*(*(void (CActorManager_7e2b0::**)(const char *))&this->f_1c))(*b);
}


// 0x0007e2d0 FUN_0007e2d0 (89 B): matches/0x0007e2d0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0?$Closure2@VCAmbientsManager_7e2d0@fn_0007e2d0@@XMM@fn_0007e2d0@@QAE@PBDPAVCAmbientsManager_7e2d0@1@P821@AEXMM@Z@Z
namespace fn_0007e2d0 {
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

// Closure2<CAmbientsManager, void, float, float>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class CAmbientsManager_7e2d0 {};
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class MethodBase_7e2d0 : public CtorV_001d0480 {
  public:
    MethodBase_7e2d0(const char* a) : CtorV_001d0480(a, 2) { }
};
template <class T, class R, class A, class B> class Method2 : public MethodBase_7e2d0 {
  public:
    typedef R (T::*Fn)(A, B);
    virtual void Invoke();
    Fn obj;
    T* fn;
    Method2(const char*, T*, Fn);
};
template <class T, class R, class A, class B> class Closure2 : public Method2<T, R, A, B> {
  public:
    virtual void Extra();
    Closure2(const char*, T*, typename Method2<T, R, A, B>::Fn);
};
template <>
Method2<CAmbientsManager_7e2d0, void, float, float>::Method2(const char* a, CAmbientsManager_7e2d0* b, Fn c)
    : MethodBase_7e2d0(a) {
    obj = c;
    retType = FUN_001d04d0(((int*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e128));
    argTypes[1] = FUN_001d04d0(((int*)&DAT_0048e128));
}
template <>
Closure2<CAmbientsManager_7e2d0, void, float, float>::Closure2(const char* a, CAmbientsManager_7e2d0* b,
                                                              Method2<CAmbientsManager_7e2d0, void, float, float>::Fn c)
    : Method2<CAmbientsManager_7e2d0, void, float, float>(a, b, c) {
    fn = b;
}
} // namespace fn_0007e2d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0007e350 Closure2<CAmbientsManager,void,float,float>::vfunc_2 (22 B): matches/0x0007e350.cpp
// sym: ?vfunc_2@?$Closure2@VCAmbientsManager@@XMM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CAmbientsManager, void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_7e350 * p = (Pair_7e350 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_7e350 * *)&this->f_20)->*(*(void (CActorManager_7e350::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x0007e370 FUN_0007e370 (76 B): matches/0x0007e370.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0007e370@@QAE@HHH@Z
namespace fn_0007e370 {
// data: keyA = DAT_0048e100, keyB = DAT_0048e0e4

extern "C++" __declspec(nothrow) unsigned char __cdecl Query_001d04d0(const void*);
class Function_7e370 {
  public:
    Function_7e370(int, int);
    virtual void f();
    char pad[12];
    unsigned char b;
    char pad2[7];
    unsigned char a;
    char pad3[3];
    int x;
    int y;
};
class Method1 : public Function_7e370 {
  public:
    Method1(int n, int xx) : Function_7e370(n, 1) {
        x = xx;
        a = Query_001d04d0(((int*)&DAT_0048e100));
        b = Query_001d04d0(((int*)&DAT_0048e0e4));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(int n, int xx, int yy);
    virtual void f();
};
Closure1::Closure1(int n, int xx, int yy) : Method1(n, yy) {
    y = xx;
}
} // namespace fn_0007e370


// 0x0007e3e0 Closure1<CAmbientsManager,void,bool>::vfunc_2 (20 B): matches/0x0007e3e0.cpp
// sym: ?vfunc_2@?$Closure1@VCAmbientsManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<CAmbientsManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_7e3e0 * *)&this->f_20)->*(*(void (Actor_7e3e0::**)(unsigned char))&this->f_1c))(*arg);
}


// 0x0007e450 Closure4<CAmbientsManager,void,const_char_*,int,const_math::Vector,const_math::Vector>::vfunc_2 (12 B): matches/0x0007e450.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure2@fn_0007e450@@UAEXHHH@Z
namespace fn_0007e450 {
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
    char pad[0x18];
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
} // namespace fn_0007e450


// 0x0007e4b0 Closure3<CAmbientsManager,void,const_char_*,unsigned_int,float>::vfunc_2 (28 B): equivalent/0x0007e4b0.cpp
// sym: ?vfunc_2@?$Closure3@VCAmbientsManager@@XPBDIM@@UAEXPAX00@Z @737c210bc5da @we909f5656d8a
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CAmbientsManager,void,const_char_*,unsigned_int,float>::vfunc_2 @ 0x0007e4b0
template <> void Closure3<CAmbientsManager, void, const char *, unsigned int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; AmbientArguments * arguments = (AmbientArguments *)__p1; void * unused2 = (void *)__p2;

    ((*(CAmbientsManager_7e4b0 * *)&this->f_20)->*(*(void (CAmbientsManager_7e4b0::**)(const char *, unsigned int, float))&this->f_1c))(arguments->name, arguments->id, arguments->volume);
}


// 0x0007e4d0 FUN_0007e4d0 (89 B): matches/0x0007e4d0.cpp [wrapped: conflict: Closure2; Method2]
// sym: ??0Closure2@fn_0007e4d0@@QAE@PBDPAVOwner_7e4d0@1@P821@AEXXZ@Z
namespace fn_0007e4d0 {
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

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Owner_7e4d0 {};
typedef void (Owner_7e4d0::*Fn_7e4d0)();
class Function_7e4d0 : public ScriptFunctionFields {
  public:
    virtual void fn();
    Function_7e4d0(const char*, int);
    Fn_7e4d0 u;
};
class Method2 : public Function_7e4d0 {
  public:
    virtual void fn();
    Method2(const char* p, Fn_7e4d0 r) : Function_7e4d0(p, 2) {
        u = r;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
        argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
};
class Closure2 : public Method2 {
  public:
    virtual void fn();
    Owner_7e4d0* v;
    Closure2(const char*, Owner_7e4d0*, Fn_7e4d0);
};
Closure2::Closure2(const char* p, Owner_7e4d0* q, Fn_7e4d0 r) : Method2(p, r) {
    v = q;
}
} // namespace fn_0007e4d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0007e550 Closure2<CAmbientsManager,void,const_char_*,float>::vfunc_2 (22 B): matches/0x0007e550.cpp
// sym: ?vfunc_2@?$Closure2@VCAmbientsManager@@XMM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CAmbientsManager, void, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_7e550 * p = (Pair_7e550 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_7e550 * *)&this->f_20)->*(*(void (CActorManager_7e550::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x0007e570 FUN_0007e570 (262 B): equivalent/0x0007e570.cpp [wrapped: conflict: content::LoadInventory; pure3d::CompositeDrawable]
// sym: ?run@Target_7e570@fn_0007e570@@QAEPAUCompositeDrawable@pure3d@2@PAUKey_7e570@2@H@Z @8713358171f6 @w2ead0738437e
namespace fn_0007e570 {
// STATUS: equivalent (tools/equiv.py level 3: 385 inputs, branch coverage 10/10)
// FUN_0007e570 @ 0x0007e570
namespace pure3d { struct CompositeDrawable; }
namespace content { template<class T> struct LoadInventoryDynamicCaster; struct LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; }; }
struct Item_7e570 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void update(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void set(float,float); };
struct Group_7e570 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int count(); virtual void v17(); virtual Item_7e570* get(int); };
struct Entry_7e570 { int a,b; Group_7e570* group; };
struct List_7e570 { char pad[0x3c]; Entry_7e570* begin; Entry_7e570* end; };
namespace pure3d { struct CompositeDrawable { virtual void prepare(); char pad[0x40]; List_7e570* list; }; }
struct Result_7e570 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual pure3d::CompositeDrawable* drawable(); };
struct Inventory_7e570 { virtual void v0(); virtual void v1(); virtual void v2(); virtual Result_7e570* find(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>*,int,int); };
struct Context { Inventory_7e570* FUN_00203d70(); };
struct Service_7e570 { Context* FUN_000862a0(); };
struct Holder_7e570 { char pad[0x54]; Service_7e570* service; };
struct Key_7e570 { int first,second; };
struct Target_7e570 { char pad[0x382c]; Holder_7e570* holder; pure3d::CompositeDrawable* run(Key_7e570*,int); };
pure3d::CompositeDrawable* Target_7e570::run(Key_7e570* key,int value) {
 Inventory_7e570* inv=holder->service->FUN_000862a0()->FUN_00203d70();
 content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
 Result_7e570* result=inv->find(&caster,key->first,key->second);
 if(!result) return 0;
 pure3d::CompositeDrawable* object=result->drawable();
 object->prepare();
 float f=(float)value;
 List_7e570* list=object->list;
 int count=(unsigned char)(list->end-list->begin);
 for(int i=0;i<count;++i) {
 Group_7e570* group=list->begin[(unsigned char)i].group;
 int n=group->count();
 for(int j=0;j<n;++j) {
 group->get(j)->set(f,f);
 group->get(j)->update();
 }
 }
 return object;
}
} // namespace fn_0007e570

namespace fn_f9399ba1 {

// 0x0007e9f0 FUN_0007e9f0 (83 B): equivalent/0x0007e9f0.cpp
// sym: ?FUN_0007e9f0@Registry_7e9f0@fn_f9399ba1@@QAEXPBDPAVCAmbientsManager_7e9f0@2@P832@AEX0H_NVVector_7e9f0@math@@3@Z@Z @a2c6afa337e5 @wc88ec8639f21
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0007e9f0 @ 0x0007e9f0
// FUN_0007e9f0 @ 0x0007e9f0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_7e9f0::FUN_0007e9f0(const char* a1, CAmbientsManager_7e9f0* a2, Fn_7e9f0 a3) {
    typedef Closure5_7e9f0<CAmbientsManager_7e9f0, void, const char*, int, bool, math::Vector_7e9f0, math::Vector_7e9f0> Alloc_7e9f0;
    HULK_SIZE32(Alloc_7e9f0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_7e9f0));
    void* x = 0;
    if (m) {
        ((Raw_7e9f0*)m)->FUN_0007ce30(a1, a3);
        x = new (m) Closure5_7e9f0<CAmbientsManager_7e9f0, void, const char*, int, bool, math::Vector_7e9f0, math::Vector_7e9f0>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f9399ba1

// 0x0007eaa0 FUN_0007eaa0 (109 B): equivalent/0x0007eaa0.cpp [wrapped: conflict: CAmbientsManager; Closure0; Method0]
// sym: ?FUN_0007eaa0@Registry_7eaa0@fn_0007eaa0@@QAEXPBDPAVCAmbientsManager@2@P832@AEXXZ@Z @713ca321db5f @w669b867c262d
namespace fn_0007eaa0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0007eaa0 @ 0x0007eaa0
// FUN_0007eaa0 @ 0x0007eaa0  (generated by work/closure/gen.py)
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


class CAmbientsManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_7eaa0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_7eaa0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_7eaa0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_7eaa0(name, 0) {
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

struct Registry_7eaa0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_0007eaa0(const char* name, CAmbientsManager* owner, void (CAmbientsManager::*fn)());
};

void Registry_7eaa0::FUN_0007eaa0(const char* name, CAmbientsManager* owner, void (CAmbientsManager::*fn)()) {
    typedef Closure0<CAmbientsManager, void> Alloc_7eaa0;
    HULK_SIZE32(Alloc_7eaa0, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CAmbientsManager, void>));
    Closure0<CAmbientsManager, void>* c = 0;
    if (mem)
        c = new (mem) Closure0<CAmbientsManager, void>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_0007eaa0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f9399ba1 {

// 0x0007eb10 FUN_0007eb10 (83 B): equivalent/0x0007eb10.cpp
// sym: ?FUN_0007eb10@Registry_7eb10@fn_f9399ba1@@QAEXPBDPAVCAmbientsManager_7eb10@2@P832@AEX0H_N@Z@Z @0b48ee52c8e2 @w7c8cce3b4a57
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0007eb10 @ 0x0007eb10
// FUN_0007eb10 @ 0x0007eb10  (generated by tools/equiv_gen/reg_helper.py)
void Registry_7eb10::FUN_0007eb10(const char* a1, CAmbientsManager_7eb10* a2, Fn_7eb10 a3) {
    typedef Closure3_7eb10<CAmbientsManager_7eb10, void, const char*, int, bool> Alloc_7eb10;
    HULK_SIZE32(Alloc_7eb10, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_7eb10));
    void* x = 0;
    if (m) {
        ((Raw_7eb10*)m)->FUN_0007d050(a1, a3);
        x = new (m) Closure3_7eb10<CAmbientsManager_7eb10, void, const char*, int, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0007ed00 FUN_0007ed00 (83 B): equivalent/0x0007ed00.cpp
// sym: ?FUN_0007ed00@Registry_7ed00@fn_f9399ba1@@QAEXPBDPAVCAmbientsManager_7ed00@2@P832@AEX0HVVector_7ed00@math@@2@Z@Z @e1e853dd1603 @w0a7b3776ba79
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0007ed00 @ 0x0007ed00
// FUN_0007ed00 @ 0x0007ed00  (generated by tools/equiv_gen/reg_helper.py)
void Registry_7ed00::FUN_0007ed00(const char* a1, CAmbientsManager_7ed00* a2, Fn_7ed00 a3) {
    typedef Closure4_7ed00<CAmbientsManager_7ed00, void, const char*, int, const math::Vector_7ed00, const math::Vector_7ed00> Alloc_7ed00;
    HULK_SIZE32(Alloc_7ed00, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_7ed00));
    void* x = 0;
    if (m) {
        ((Raw_7ed00*)m)->FUN_0007d380(a1, a3);
        x = new (m) Closure4_7ed00<CAmbientsManager_7ed00, void, const char*, int, const math::Vector_7ed00, const math::Vector_7ed00>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0007ed60 FUN_0007ed60 (83 B): equivalent/0x0007ed60.cpp
// sym: ?FUN_0007ed60@Registry_7ed60@fn_f9399ba1@@QAEXPBDPAVCAmbientsManager_7ed60@2@P832@AEX0IM@Z@Z @4c8e6558d8fc @w8651711392b6
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0007ed60 @ 0x0007ed60
// FUN_0007ed60 @ 0x0007ed60  (generated by tools/equiv_gen/reg_helper.py)
void Registry_7ed60::FUN_0007ed60(const char* a1, CAmbientsManager_7ed60* a2, Fn_7ed60 a3) {
    typedef Closure3_7ed60<CAmbientsManager_7ed60, void, const char*, unsigned int, float> Alloc_7ed60;
    HULK_SIZE32(Alloc_7ed60, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_7ed60));
    void* x = 0;
    if (m) {
        ((Raw_7ed60*)m)->FUN_0007d480(a1, a3);
        x = new (m) Closure3_7ed60<CAmbientsManager_7ed60, void, const char*, unsigned int, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f9399ba1

// 0x0007ee10 FUN_0007ee10 (419 B): equivalent/0x0007ee10.cpp [wrapped: conflict: World]
// sym: ?FUN_0007ee10@World@fn_0007ee10@@QAEXH@Z @a403e682ef54 @w44a2468f9749
namespace fn_0007ee10 {
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 26/26)
// FUN_0007ee10 @ 0x0007ee10


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double floor(double);
#endif


struct Vec3_7ee10 {
    float x, y, z;
};

union FloatBits_7ee10 {
    float f;
    int i;
};

struct Pos_7ee10 {
    float x, y, z;
};

struct Locator {
    char FUN_00059a50(Vec3_7ee10 *out);
};

struct Link124_7ee10 {
    char pad00[0x10];
    Locator *loc;
};

struct Scene_7ee10 {
    char pad00[0xc];
    int count;
    char pad10[0x124 - 0x10];
    Link124_7ee10 *f124;
};

struct Objs_7ee10 {
    char pad00[0x59c];
    int index;
};

struct Slots_7ee10 {
};

struct Mgr_7ee10 {
    void FUN_001e5bc0(int id);
};

struct Ctx_7ee10 {
    char pad00[0xc];
    Mgr_7ee10 *mgr;
    char pad10[0x20 - 0x10];
    Scene_7ee10 *scene;
    char pad24[0x54 - 0x24];
    Slots_7ee10 *slots;
};

class Item_7ee10 {
public:
    char pad00[0x10];
    int id;
    int f14;
    void FUN_00082cd0(Vec3_7ee10 *v);
    void FUN_000835a0(int arg);
};

struct Flag8 {
    char pad[3];
    char on;
    char pad4[4];
};

class World {
public:
    char pad00[8];
    Flag8 flags[(0x3800 - 8) / 8];
    Item_7ee10 *items[10];
    int count;
    Ctx_7ee10 *ctx;
    void FUN_0007e740();
    void FUN_0007ccf0(int index);
    void FUN_0007ee10(int arg);
};

void World::FUN_0007ee10(int arg)
{
    Ctx_7ee10 *c = ctx;
    Scene_7ee10 *scene = c->scene;
    int idx = ((Objs_7ee10 *)((owners::Target_862a0 *)(c->slots))->FUN_000862a0())->index;
    if (flags[idx].on) {
        int n = scene->count;
        int limit = DAT_004dd044;
        if ((float)n >= 3.0f)
            limit = limit - (int)floor((float)(DAT_004dd044 * n) * 0.125f);
        if (count < limit)
            FUN_0007e740();
    }
    Vec3_7ee10 pos;
    scene->f124->loc->FUN_00059a50(&pos);
    int i = 0;
    Item_7ee10 **p = &items[0];
    while (i < count) {
        Item_7ee10 *item = *p;
        Pos_7ee10 *q = ((Pos_7ee10 *)((owners::Owner_82cf0 *)item)->FUN_00082cf0());
        float dz = pos.z - q->z;
        FloatBits_7ee10 dy;
        dy.f = pos.y - q->y;
        Vec3_7ee10 d;
        d.x = pos.x - q->x;
        d.y = 0.0f;
        d.z = dz;
        float dist2 = d.x * d.x + dz * dz;
        if (dist2 > DAT_0049b8ec || q->y < -100.0f) {
            item = *p;
            ctx->mgr->FUN_001e5bc0(item->id);
            if (*p && *p == item)
                FUN_0007ccf0(i);
            i--;
            p--;
        } else {
            if (dist2 < DAT_0049b8b8) {
                dy.i &= 0x7fffffff;
                if (dy.f < 3.0f) {
                    if (item->f14 == 0 || item->f14 == 2)
                        item->FUN_00082cd0(&d);
                }
            }
            item->FUN_000835a0(arg);
        }
        i++;
        p++;
    }
}
} // namespace fn_0007ee10

namespace fn_f9399ba1 {

// 0x0007efc0 FUN_0007efc0 (844 B): equivalent/0x0007efc0.cpp
// sym: ?FUN_0007efc0@Mgr_7efc0@fn_f9399ba1@@QAEXH@Z @45eb43ad14a9 @w6f2f744eb69b
// STATUS: equivalent (tools/equiv.py level 3: 16969 inputs, branch coverage 60/60)
// FUN_0007efc0 @ 0x0007efc0
void Mgr_7efc0::FUN_0007efc0(int arg)
{
    Frame_7efc0 f;
    env->f20->f124->f10->FUN_00059a50(&f.pos);
    f.world = env->f0c;
    f.removed = 0;
    for (int i = 0; i < count; i++) {
        Ent_7efc0 *e = list[i];
        if (e)
            e->addRef();
        if (e->f30 > 0x96) {
            FUN_0007b880(i);
            i--;
            e->release();
            continue;
        }
        if (e->f10 == 0x13) {
            f.world->FUN_001dd520(e->f34, &f.mat);
            hulk_freg dx = f.pos.x - f.mat.m[12];
            hulk_freg dz = f.pos.z - f.mat.m[14];
            if (dz * dz + dx * dx > 32400.0f) {
                FUN_0007b880(i);
                i--;
                e->release();
                continue;
            }
            if (!f.world->FUN_001dda80(e->f34)) {
                e->release();
                continue;
            }
            if (!f.world->FUN_001dd9e0(e->f34)) {
                e->release();
                continue;
            }
            FUN_0007b880(i);
            i--;
            e->release();
            continue;
        }
        FUN_0007b4f0(i);
        e->FUN_00084c40(arg);
        if (list[i] != e) {
            i--;
            e->release();
            continue;
        }
        f.removed++;
        if (e->FUN_00083d10()) {
            int j;
            for (j = 0; j < 0x14; j++) {
                if (ring[j] == e)
                    break;
            }
            if (j >= 0x14) {
                int h = head;
                f.k = 0;
                do {
                    int slot = h % 0x14;
                    if (ring[slot] == 0) {
                        e->addRef();
                        if (ring[slot])
                            ring[slot]->release();
                        ring[slot] = e;
                        break;
                    }
                    f.k++;
                    h++;
                } while (f.k < 0x14);
            }
        }
        e->release();
    }

    int pending = f3744 - f.removed;
    if (pending > 0 && count == f3748)
        FUN_0007cab0(pending);
    if (f.removed < f3744 && count < f3748 && f3740 > 0)
        ((owners::VehicleManager_7e680 *)this)->FUN_0007e680();

    char done = 0;
    for (int n = 0; n < 0x14; n++) {
        int slot = (head + n) % 0x14;
        Ent_7efc0 *e = ring[slot];
        if (e) {
            if (done) {
                head = slot;
                return;
            }
            e->addRef();
            if (ring[slot]) {
                ring[slot]->release();
                ring[slot] = 0;
            }
            f.q.x = e->pos.x;
            f.q.y = e->pos.y + 1.0f;
            f.q.z = e->pos.z;
            if (!env->f24->FUN_00201f20(&f.q, 1, &f.g1, &f.g2, 0, 0) || e->pos.y - f.g1.y > 0.7f) {
                int i = 0;
                for (; i < count; i++) {
                    if (list[i] == e) {
                        Target_7efc0 *t = ((Target_7efc0 *)((owners::Obj_1dc0d0 *)(env->f0c))->FUN_001dc0d0((hulk_intptr)(e->f34)));
                        if (t)
                            t->FUN_001d7510();
                        FUN_0007ba60(i);
                        break;
                    }
                }
            }
            e->release();
            done = 1;
        }
    }
}

} // namespace fn_f9399ba1

// 0x0007f450 FUN_0007f450 (269 B): equivalent/0x0007f450.cpp [wrapped: conflict: FUN_000964d0]
// sym: ?target@Owner_7f450@fn_0007f450@@QAEXHHHUVec3_7f450@2@MMM@Z @b34c3bc8722b @w98e178827ecc
namespace fn_0007f450 {
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 8/8)
// FUN_0007f450 @ 0x0007f450
typedef unsigned __int64 Key_7f450;
extern Key_7f450 __cdecl FUN_0027b020(int);
struct RandomResult {  };
extern RandomResult* __stdcall FUN_000964d0();
struct Vec3_7f450 { float x,y,z; };
struct Matrix { char data[64]; void FUN_0022b980();   };
struct Object { virtual void start(); virtual void finish(); void FUN_00080e50(Matrix*); void FUN_00080c60(int); void FUN_00080c80(int); };
struct Record_7f450 { int count; char rest[12]; };
struct Owner_7f450 {
 char pad[0x34b0];
 union { Record_7f450 records[256]; struct { char gap[0x98]; int count; Object* objects[256]; } list; };
 int FUN_00079220(Key_7f450);
 Object* FUN_0007f310(int,int,int,int);
 void FUN_0007b380(Object*);
 void target(int,int,int,Vec3_7f450,float,float,float);
};
void Owner_7f450::target(int name,int arg,int flags,Vec3_7f450 position,float x,float y,float z) {
 Key_7f450 key=FUN_0027b020(name);
 int index=FUN_00079220(key);
 if ((index<0 || list.objects[index]==0) && list.count>0) {
  int arg1_ = list.count-1;
  int a= ((int)((owners::Random_11330 *)(FUN_000964d0()))->FUN_00011330((unsigned int)arg1_));
  int arg2_ = records[a].count-1;
  int b= ((int)((owners::Random_11330 *)(FUN_000964d0()))->FUN_00011330((unsigned int)arg2_));
  Object* object=FUN_0007f310(name,arg,a,b);
  if(object) {
   object->start();
   Matrix matrix;
   matrix.FUN_0022b980();
   ((owners::Target_22be40 *)&matrix)->FUN_0022be40((const int *)(Vec3_7f450 *)(&position));
   ((owners::Matrix_22bc20 *)&matrix)->FUN_0022bc20(x*0.0174532924f, y*0.0174532924f, z*0.0174532924f);
   object->FUN_00080e50(&matrix);
   object->FUN_00080c60(flags);
   object->FUN_00080c80(1);
   FUN_0007b380(object);
   object->finish();
  }
 }
}
} // namespace fn_0007f450


// 0x0007f690 FUN_0007f690 (692 B): equivalent/0x0007f690.cpp [wrapped: conflict: FUN_000964d0]
// sym: ?FUN_0007f690@Spawner_7f690@fn_0007f690@@QAEXHHHH@Z @6008551aae7b @w1b93a2bdc10e
namespace fn_0007f690 {
// STATUS: equivalent (tools/equiv.py level 3: 157 inputs, branch coverage 25/26, incomplete)
// FUN_0007f690 @ 0x0007f690

struct V3_7f690 {
    float x, y, z;
};

struct Rng_7f690 {
    unsigned int s0;
    unsigned int s1;
};
Rng_7f690 *FUN_000964d0();

struct Path_7f690 {
    char pad0[0x14];
    int count;
    V3_7f690 *FUN_00106160(int index);
};

struct Library_7f690 {
    Path_7f690 *FUN_00106210(int id);
};

struct Manager_7f690 {
    char pad0[0x18];
    Library_7f690 *library;
};

struct Handle_7f690 {
    void FUN_001c5080(float a, float b);
};

struct Part_7f690 {
    virtual void AddRef();
    virtual void Release();
    char pad4[0x4];
    int key0;
    int key1;
    char pad10[0x54];
    V3_7f690 pos;
    char pad70[0x7c];
    Handle_7f690 *handle;
    void FUN_00080ea0(V3_7f690 *a, V3_7f690 *b);
    void FUN_00080ef0(int v);
    void FUN_00080f00(int v);
    void FUN_00080f20(int v);
    void FUN_00080f30(int v);
    void FUN_00080e30(V3_7f690 *a);
    void FUN_00081b20(int v);
};

struct Slot16_7f690 {
    unsigned int limit;
    char pad4[12];
};

class Spawner_7f690 {
public:
    char pad0[0x34b0];
    Slot16_7f690 slots[9];
    char pad3540[8];
    unsigned int slotCount;
    Part_7f690 *parts[20];
    int partCount;
    char pad35a0[0x28c];
    Manager_7f690 *mgr;
    void FUN_00078ee0(V3_7f690 *a, V3_7f690 *b);
    Part_7f690 *FUN_0007f310(int a, int b, int c, int d);
    void FUN_0007f690(int a1, int a2, int a3, int a4);
};

void Spawner_7f690::FUN_0007f690(int a1, int a2, int a3, int a4)
{
    Path_7f690 *path = mgr->library->FUN_00106210(a2);
    int i0;
    int i1;
    if (a4 == 0) {
        i0 = a3;
        i1 = (a3 + 1) % path->count;
    } else {
        i1 = a3;
        i0 = (a3 + 1) % path->count;
    }
    V3_7f690 a = *path->FUN_00106160(i0);
    V3_7f690 b = *path->FUN_00106160(i1);
    FUN_00078ee0(&a, &b);
    for (int i = partCount - 1; i >= 0; i--) {
        V3_7f690 p = parts[i]->pos;
        float dx = p.x - a.x;
        float dy = p.y - a.y;
        float dz = p.z - a.z;
        if (dz * dz + dy * dy + dx * dx < DAT_0049b8a0)
            return;
    }
    unsigned int n1 = slotCount;
    Rng_7f690 *r = FUN_000964d0();
    r->s0 = (r->s0 & 0xffff) * 0x9069 + (r->s0 >> 16);
    r->s1 = (r->s1 & 0xffff) * 0x4650 + (r->s1 >> 16);
    unsigned int v1 = (r->s0 << 16) + (r->s1 & 0xffff);
    unsigned int pick = v1 % n1;
    unsigned int n2 = slots[pick].limit;
    r = FUN_000964d0();
    r->s0 = (r->s0 & 0xffff) * 0x9069 + (r->s0 >> 16);
    r->s1 = (r->s1 & 0xffff) * 0x4650 + (r->s1 >> 16);
    unsigned int v2 = (r->s0 << 16) + (r->s1 & 0xffff);
    Part_7f690 *p = FUN_0007f310(a1, 1, pick, v2 % n2);
    if (p == 0)
        return;
    p->AddRef();
    p->handle->FUN_001c5080((*(float*)&DAT_00421898), (*(float*)&DAT_004218c0));
    p->FUN_00080ea0(&a, &b);
    p->FUN_00080ef0(-1);
    p->FUN_00080f00(a2);
    p->FUN_00080f20(i1);
    p->FUN_00080f30(a4);
    p->FUN_00080e30(&a);
    int cnt = partCount;
    int k0 = p->key0;
    bool have = false;
    if (cnt > 0) {
        int idx = 0;
        do {
            Part_7f690 *q = parts[idx];
            if (q->key0 == k0 && q->key1 == p->key1) {
                have = parts[idx] != 0;
                break;
            }
            idx++;
        } while (idx < partCount);
    }
    if (!have && cnt != 20) {
        p->AddRef();
        if (parts[cnt] != 0)
            parts[cnt]->Release();
        parts[cnt] = p;
        partCount++;
    }
    p->FUN_00081b20(0);
    p->Release();
}
} // namespace fn_0007f690


// 0x0007f950 FUN_0007f950 (3788 B): equivalent/0x0007f950.cpp [wrapped: macros]
// sym: ??0CAmbientsManager@fn_0007f950@@QAE@XZ @846c9273be7b @wf228a90a0f21
void* operator new(hulk_uintptr) throw();
namespace fn_0007f950 {
// STATUS: equivalent (tools/equiv.py level 3: 479 inputs, branch coverage 74/74)
// FUN_0007f950 @ 0x0007f950


void* FUN_0008d690(unsigned int);
char FUN_001d04d0(const void*) throw();
class CAmbientsManager;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
typedef const math::Vector ConstMathVector;
typedef unsigned int UnsignedInt;
extern char DAT_0048e0e4, DAT_0048e0f0, DAT_0048e100, DAT_0048e10c, DAT_0048e128, DAT_0048e134, DAT_0049b95c;
#define tBool DAT_0048e0e4
#define tString DAT_0048e0f0
#define tVoid DAT_0048e100
#define tVector DAT_0048e10c
#define tConstMathVector DAT_0048e10c
#define tFloat DAT_0048e128
#define tInt DAT_0048e134
#define tUnsignedInt DAT_0049b95c
class Base : public ScriptFunctionFields { public: virtual void v(); Base(const char*, int) throw(); };
template<class C, class R> class Method0 : public Base { public: R (C::*f)(); Method0(const char* n, R (C::*x)(), const void* r) : Base(n, 0) { f = x; retType = FUN_001d04d0(r); } virtual void v(); };
template<class C, class R> class Closure0 : public Method0<C, R> { public: C* owner; Closure0(const char* n, C* o, R (C::*f)(), const void* r) : Method0<C, R>(n, f, r) { owner = o; } virtual void v(); };
template<class C, class R, class A1> class Method1 : public Base { public: R (C::*f)(A1); Method1(const char* n, R (C::*x)(A1), const void* r, const void* a1) : Base(n, 1) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); } virtual void v(); };
template<class C, class R, class A1> class Closure1 : public Method1<C, R, A1> { public: C* owner; Closure1(const char* n, C* o, R (C::*f)(A1), const void* r, const void* a1) : Method1<C, R, A1>(n, f, r, a1) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2> class Method2 : public Base { public: R (C::*f)(A1, A2); Method2(const char* n, R (C::*x)(A1, A2), const void* r, const void* a1, const void* a2) : Base(n, 2) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); } virtual void v(); };
template<class C, class R, class A1, class A2> class Closure2 : public Method2<C, R, A1, A2> { public: C* owner; Closure2(const char* n, C* o, R (C::*f)(A1, A2), const void* r, const void* a1, const void* a2) : Method2<C, R, A1, A2>(n, f, r, a1, a2) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3> class Method3 : public Base { public: R (C::*f)(A1, A2, A3); Method3(const char* n, R (C::*x)(A1, A2, A3), const void* r, const void* a1, const void* a2, const void* a3) : Base(n, 3) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3> class Closure3 : public Method3<C, R, A1, A2, A3> { public: C* owner; Closure3(const char* n, C* o, R (C::*f)(A1, A2, A3), const void* r, const void* a1, const void* a2, const void* a3) : Method3<C, R, A1, A2, A3>(n, f, r, a1, a2, a3) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Method4 : public Base { public: R (C::*f)(A1, A2, A3, A4); Method4(const char* n, R (C::*x)(A1, A2, A3, A4), const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Base(n, 4) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4 : public Method4<C, R, A1, A2, A3, A4> { public: C* owner; Closure4(const char* n, C* o, R (C::*f)(A1, A2, A3, A4), const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Method4<C, R, A1, A2, A3, A4>(n, f, r, a1, a2, a3, a4) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Method5 : public Base { public: R (C::*f)(A1, A2, A3, A4, A5); Method5(const char* n, R (C::*x)(A1, A2, A3, A4, A5), const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5) : Base(n, 5) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); argTypes[4] = FUN_001d04d0(a5); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5 : public Method5<C, R, A1, A2, A3, A4, A5> { public: C* owner; Closure5(const char* n, C* o, R (C::*f)(A1, A2, A3, A4, A5), const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5) : Method5<C, R, A1, A2, A3, A4, A5>(n, f, r, a1, a2, a3, a4, a5) { owner = o; } virtual void v(); };
#define FN(b) extern void FUN_##b();
#define G0(n, b, R) { r->FUN_001d3b70(n, new Closure0<CAmbientsManager, R>(n, this, &CAmbientsManager::FUN_##b, &t##R)); }
#define G1(n, b, R, A1) { r->FUN_001d3b70(n, new Closure1<CAmbientsManager, R, A1>(n, this, &CAmbientsManager::FUN_##b, &t##R, &t##A1)); }
#define G2(n, b, R, A1, A2) { r->FUN_001d3b70(n, new Closure2<CAmbientsManager, R, A1, A2>(n, this, &CAmbientsManager::FUN_##b, &t##R, &t##A1, &t##A2)); }
#define G3(n, b, R, A1, A2, A3) { r->FUN_001d3b70(n, new Closure3<CAmbientsManager, R, A1, A2, A3>(n, this, &CAmbientsManager::FUN_##b, &t##R, &t##A1, &t##A2, &t##A3)); }
#define G4(n, b, R, A1, A2, A3, A4) { r->FUN_001d3b70(n, new Closure4<CAmbientsManager, R, A1, A2, A3, A4>(n, this, &CAmbientsManager::FUN_##b, &t##R, &t##A1, &t##A2, &t##A3, &t##A4)); }
#define G5(n, b, R, A1, A2, A3, A4, A5) { r->FUN_001d3b70(n, new Closure5<CAmbientsManager, R, A1, A2, A3, A4, A5>(n, this, &CAmbientsManager::FUN_##b, &t##R, &t##A1, &t##A2, &t##A3, &t##A4, &t##A5)); }

class Link16 { public: char b[16]; void FUN_0027af00(); };
class Link8 { public: char b[8]; void FUN_0027af00(); };
struct Slot8 { char pad0[2]; char b2; char b3; char pad4[4]; };

class CAmbientsManager {
public:
    CAmbientsManager();
    virtual void v0();
    char pad04[4];
    Slot8 slots[0x320];
    char pad1908[0x18];
    char tab[0x1b88];
    Link16 links1[10];
    int i3548;
    int z354c[20];
    int i359c;
    Link8 links2[0x14];
    int i3640;
    float f3644;
    float f3648;
    char c364c;
    char pad364d[3];
    Link16 links3[10];
    char pad36f0[0x50];
    int i3740;
    int i3744;
    int i3748;
    int z374c[20];
    int i379c;
    int i37a0;
    float f37a4;
    float f37a8;
    int z37ac[20];
    int i37fc;
    int z3800[10];
    int i3828, i382c, i3830;
    // The member functions bound to Lua below (types: the game's Closure<N> instantiations).
    void FUN_000788e0();
    void FUN_00078d00(bool);
    void FUN_00079290();
    void FUN_000792a0(const char*, int, bool);
    void FUN_00079310();
    void FUN_00079320(const char*);
    void FUN_00079370(int);
    void FUN_00079390(int);
    void FUN_000793a0(float);
    void FUN_000793c0(float, float);
    void FUN_00079400(float, float);
    void FUN_00079420(int);
    void FUN_00079440(int);
    void FUN_000794a0(const char*, unsigned int, float);
    void FUN_00079550(float);
    void FUN_000795a0(float);
    void FUN_000795f0(float);
    void FUN_00079640(float, float);
    void FUN_00079660(float);
    void FUN_000796a0(float);
    void FUN_0007ab60(int);
    void FUN_0007aba0(float, float);
    void FUN_0007abc0(int);
    void FUN_0007b480();
    void FUN_0007d640(const char*, bool);
    void FUN_0007d680(const char*, float);
    void FUN_0007d6c0(const char*, float);
    void FUN_0007de00(const char*, int, const math::Vector, const math::Vector);
    void FUN_0007f450(const char*, int, bool, math::Vector, math::Vector);
};
class Registry { public:
    void FUN_001d3b70(const char*, void*);
};
class Entry { public:
};
Registry* FUN_001d4c90();

CAmbientsManager::CAmbientsManager() {
    int i, k;
    for (i = 0; i < 10; i++)
        links1[i].FUN_0027af00();
    i3548 = 0;
    i359c = 0;
    for (i = 0; i < 0x14; i++)
        links2[i].FUN_0027af00();
    i3640 = 0;
    f3644 = 1.0f;
    f3648 = 1.5f;
    c364c = 0;
    for (i = 0; i < 10; i++)
        links3[i].FUN_0027af00();
    i3740 = 0;
    i3744 = 1;
    i3748 = 0;
    i379c = 0;
    i37a0 = 0;
    f37a4 = 5.0f;
    f37a8 = 10.0f;
    i37fc = 0;
    i3828 = 0;
    i382c = 0;
    i3830 = 0;
    for (i = 0; i < 0x320; i++) {
        slots[i].b3 = 0;
        slots[i].b2 = 0;
    }
    {
        char* p = tab + 0x28;
        for (k = 0; k < 7; k++) {
            *(int*)(p - 0x28) = 0;
            for (i = 0; i < 14; i++) {
                *p = 0;
                p += 0x48;
            }
        }
    }
    {
        char* p = tab + 0x3495 - 0x1920;
        for (i = 0; i < 7; i++) {
            p[-1] = 0;
            *p = 0;
            p += 2;
        }
    }
    for (i = 0; i < 20; i++) z354c[i] = 0;
    for (i = 0; i < 10; i++) z3800[i] = 0;
    for (i = 0; i < 20; i++) z374c[i] = 0;
    for (i = 0; i < 20; i++) z37ac[i] = 0;
    for (i = 0; i < 10; i++) {
        int j;
        for (j = 0; j < 4; j++) *(int*)(links1[i].b + j * 4) = 0;
    }
    Registry* r = FUN_001d4c90();
    if (r) {
G5("amb_CreateCivilian", 0007f450, Void, String, Int, Bool, Vector, Vector)
G2("amb_SetCivilianPersistent", 0007d640, Void, String, Bool)
G0("amb_ClearCivilianModels", 00079290, Void)
G3("amb_AddCivilianModel", 000792a0, Void, String, Int, Bool)
G0("amb_ClearPatrolPaths", 00079310, Void)
G1("amb_AddPatrolPath", 00079320, Void, String)
G1("amb_SetMaxActiveCivilianCount", 00079370, Void, Int)
G1("amb_SetAllowedCharacterCount", 00079390, Void, Int)
G1("amb_SetMinDistanceBetweenCivilians", 000793a0, Void, Float)
G2("amb_SetCivilianSpawnRadii", 000793c0, Void, Float, Float)
G2("amb_SetCivilianPanicRadii", 00079400, Void, Float, Float)
G0("amb_RemoveAllCivilians", 0007b480, Void)
G1("amb_SetCiviliansIgnoreHulk", 00078d00, Void, Bool)
G1("amb_AddCattleRoom", 0007ab60, Void, Int)
G2("amb_SetCowSpawnStrata", 0007aba0, Void, Float, Float)
G1("amb_SetMaxActiveCattleCount", 0007abc0, Void, Int)
G4("amb_CreateCow", 0007de00, Void, String, Int, ConstMathVector, ConstMathVector)
G1("amb_SetMaxActiveVehicleCount", 00079420, Void, Int)
G1("amb_SetMaxTotalVehicleCount", 00079440, Void, Int)
G0("amb_ClearVehicleTypes", 000788e0, Void)
G3("amb_AddVehicleType", 000794a0, Void, String, UnsignedInt, Float)
G1("amb_SetVehiclePerceptionRadius", 00079550, Void, Float)
G1("amb_SetVehiclePanicRadius", 000795a0, Void, Float)
G1("amb_SetVehiclePanicAcceleration", 000795f0, Void, Float)
G2("amb_SetVehicleSpeed", 0007d680, Void, String, Float)
G1("amb_SetAllVehicleSpeeds", 00079660, Void, Float)
G2("amb_SetVehicleSpeedRange", 00079640, Void, Float, Float)
G2("amb_VaryVehicleSpeed", 0007d6c0, Void, String, Float)
G1("amb_VaryAllVehicleSpeeds", 000796a0, Void, Float)
    }
}
} // namespace fn_0007f950
#undef FN
#undef G0
#undef G1
#undef G2
#undef G3
#undef G4
#undef G5
#undef tBool
#undef tConstMathVector
#undef tFloat
#undef tInt
#undef tString
#undef tUnsignedInt
#undef tVector
#undef tVoid


// 0x00080900 FUN_00080900 (612 B): equivalent/0x00080900.cpp [wrapped: conflict: World]
// sym: ?FUN_00080900@PropList_80900@fn_00080900@@QAEXH@Z @9223956276cc @we1abf7678ec5
namespace fn_00080900 {
// STATUS: equivalent (tools/equiv.py level 3: 19094 inputs, branch coverage 42/42)
// FUN_00080900 @ 0x00080900

struct Vec3_80900 {
    float x, y, z;
};

union FloatBits_80900 {
    float f;
    unsigned int u;
};

struct Transform_80900 {
    void FUN_00059a50(Vec3_80900 *out);
};

struct Holder_80900 {
    char pad0[0x10];
    Transform_80900 *transform;
};

struct Table_80900 {
    char pad0[0xc];
    int count;
    char pad10[0x124 - 0x10];
    Holder_80900 *player;
};

struct World {
    char pad0[0x20];
    Table_80900 *table;
};

struct Emitter_80900 {
    char pad0[0x80];
    float scale;
};

struct Prop_80900 {
    char pad0[0x10];
    int state;
    char pad14[0x28 - 0x14];
    unsigned int flags;
    char pad2c[0x64 - 0x2c];
    Vec3_80900 pos;
    char pad70[0xec - 0x70];
    Emitter_80900 *emitter;

    Vec3_80900 *FUN_00080c10(Vec3_80900 *out);
    void FUN_00080cd0(Vec3_80900 *dir, bool keep);
    void FUN_00081b20(int arg);
};


class PropList_80900 {
public:
    void FUN_00080900(int arg);

    char pad0[0x3548];
    int pending;
    Prop_80900 *props[20];
    int count;
    char pad_35a0[0x364c - 0x35a0];
    char frozen;
    char pad_364d[0x382c - 0x364d];
    World *world;

    void FUN_0007b3e0(int index);
    void FUN_0007bf80(int index);
};

void PropList_80900::FUN_00080900(int arg)
{
    int limit = DAT_004dd040;
    Table_80900 *table = world->table;
    int n = table->count;
    if (n >= 3)
        limit = limit - (int)(__int64)((double)n / DAT_0049b894 * DAT_004dd040);
    if (count < limit && pending > 0)
        ((owners::Actor_80820 *)this)->FUN_00080820();

    float best;
    int bestIdx;
    Vec3_80900 player;
    Vec3_80900 dir;
    Vec3_80900 axis;
    float dy;

    best = 0.0f;
    bestIdx = -1;
    table->player->transform->FUN_00059a50(&player);
    for (int i = 0; i < count; i++) {
        Prop_80900 *p = props[i];
        float dz = player.z - p->pos.z;
        dy = player.y - p->pos.y;
        dir.y = 0.0f;
        dir.x = player.x - p->pos.x;
        dir.z = dz;
        unsigned int flags = p->flags;
        float d2 = dir.x * dir.x + dz * dz;

        if (!((flags >> 8) & 1) && (d2 > DAT_0049b8e8 || p->pos.y < -100.0f)) {
            FUN_0007b3e0(i);
            i--;
            continue;
        }
        if (!frozen && (p->state == 1 || p->state == 0)) {
            FloatBits_80900 b;
            b.f = dy;
            b.u &= 0x7fffffff;
            if (b.f < 3.0f) {
                bool push = false;
                if (d2 < DAT_0049b8a4) {
                    push = true;
                } else if (d2 < DAT_0049b8a8) {
                    Vec3_80900 *r = p->FUN_00080c10(&axis);
                    if (dir.z * r->z + dir.y * r->y + dir.x * r->x > 0.0f)
                        push = true;
                }
                if (push)
                    p->FUN_00080cd0(&dir, true);
            }
        }
        p->FUN_00081b20(arg);
        FUN_0007bf80(i);
        flags = p->flags;
        if (((flags >> 7) & 1) && p->emitter->scale == 1.0f) {
            FUN_0007b3e0(i);
            i--;
            continue;
        }
        if (d2 > best && !((flags >> 8) & 1)) {
            best = d2;
            bestIdx = i;
        }
    }
    if (count > limit && bestIdx > 0)
        FUN_0007b3e0(bestIdx);
}
} // namespace fn_00080900


// 0x00080b70 FUN_00080b70 (35 B): matches/0x00080b70.cpp
// sym: ?FUN_00080b70@C_80b70@owners@@QAEXII@Z
void owners::C_80b70::FUN_00080b70(hulk_uintptr a, hulk_uintptr b) {
    A(((U_80b70)b));
    B(((U_80b70)b));
    D(((U_80b70)b));
}

namespace fn_f9399ba1 {

// 0x00080ba0 FUN_00080ba0 (22 B): matches/0x00080ba0.cpp
// sym: _FUN_00080ba0
// data: gObject_80ba0 = DAT_004e5acc
extern "C" float FUN_00080ba0(unsigned int a, unsigned int b) {
    return (*(Obj_80ba0**)&DAT_004e5acc)->method_000787e0(a, b);
}

} // namespace fn_f9399ba1

// 0x00080c10 FUN_00080c10 (77 B): equivalent/0x00080c10.cpp [wrapped: conflict: Object]
// sym: ?FUN_00080c10@Object@fn_00080c10@@QAEPAUVec3@2@PAU32@@Z @401a93f93530 @wd3d77d7dc7e8
namespace fn_00080c10 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_00080c10 @ 0x00080c10
// FUN_00080c10 @ 0x00080c10
struct Vec3 { float x,y,z;  }; struct Object { char pad[0x34]; Vec3 transform; Vec3 * FUN_00080c10(Vec3 *out); }; Vec3 * Object::FUN_00080c10(Vec3 *out) { Vec3 direction = {0.0f,0.0f,-1.0f}; Vec3 result; ((owners::M_22c3b0 *)&transform)->FUN_0022c3b0((float *)(Vec3 *)(&direction), (float *)(Vec3 *)(&result)); *out = result;     return out;
}
} // namespace fn_00080c10


// 0x00080c60 FUN_00080c60 (29 B): matches/0x00080c60.cpp
// sym: ?FUN_00080c60@Obj_80c60@owners@@QAEXD@Z
void owners::Obj_80c60::FUN_00080c60(char value) {
    if (value)
        flags |= 2;
    else
        flags &= 0xfffffffd;
}


// 0x00080c80 FUN_00080c80 (33 B): matches/0x00080c80.cpp
// sym: ?FUN_00080c80@Obj_80c80@owners@@QAEXD@Z
void owners::Obj_80c80::FUN_00080c80(char value) {
    if (value)
        flags |= 0x100;
    else
        flags &= 0xfffffeff;
}


// 0x00080cb0 FUN_00080cb0 (23 B): matches/0x00080cb0.cpp
// sym: ?FUN_00080cb0@C_80cb0@owners@@QAEXH@Z
void owners::C_80cb0::FUN_00080cb0(int x) {
    if (x >= 0 && x < 16) {
        value = x;
        flags |= 2;
    }
}

namespace fn_f9399ba1 {

// 0x00080cd0 FUN_00080cd0 (344 B): equivalent/0x00080cd0.cpp
// sym: ?FUN_00080cd0@Pusher_80cd0@fn_f9399ba1@@QAEXPAUVec3_80cd0@2@_N@Z @ca8149131cd6 @wf412140497f3
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 8/8)
// FUN_00080cd0 @ 0x00080cd0
void Pusher_80cd0::FUN_00080cd0(Vec3_80cd0 *dir, bool keep)
{
    Vec3_80cd0 neg;
    neg.x = -dir->x;
    neg.y = -dir->y;
    neg.z = -dir->z;
    xform.FUN_0022cc90(&neg);

    state = 2;
    flags |= 2;
    if (keep)
        return;

    hulk_freg a = cur.x - origin.x;
    hulk_freg b = cur.y - origin.y;
    hulk_freg c = cur.z - origin.z;
    hulk_freg sum = b * dir->y + c * dir->z + a * dir->x;
    if (sum > 0.0f) {
        Vec3_80cd0 old = cur;
        cur = prev;
        prev = old;
        flags |= 0x40;
        return;
    }
    if (a == 0.0f && c == 0.0f) {
        cur.x = origin.x;
        cur.y = origin.y;
        cur.z = origin.z;
        cur.x = cur.x - dir->x * 10.0f;
        cur.y = cur.y - dir->y * 10.0f;
        cur.z = cur.z - dir->z * 10.0f;
    }
    flags |= 0x40;
}

} // namespace fn_f9399ba1

// 0x00080e30 FUN_00080e30 (24 B): matches/0x00080e30.cpp
// sym: ?FUN_00080e30@C_80e30@owners@@QAEXPAH@Z
void owners::C_80e30::FUN_00080e30(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
}

namespace fn_f9399ba1 {

// 0x00080e50 FUN_00080e50 (21 B): matches/0x00080e50.cpp
// sym: ?Copy@Target_80e50@fn_f9399ba1@@QAEXPBUBlock_80e50@2@@Z
void Target_80e50::Copy(const Block_80e50* src) {
    *(Block_80e50*)((char*)this + 0x34) = *src;
}

} // namespace fn_f9399ba1

// 0x00080e70 FUN_00080e70 (20 B): matches/0x00080e70.cpp
// sym: ?FUN_00080e70@Target_80e70@owners@@QAEXPAD@Z
void owners::Target_80e70::FUN_00080e70(char* p) {
    member = (hulk_intptr)p;
    p[0xa9] = 1;
}

namespace fn_f9399ba1 {

// 0x00080ea0 FUN_00080ea0 (67 B): matches/0x00080ea0.cpp
// sym: ?Set@Obj_80ea0@fn_f9399ba1@@QAEXPAUVec3_80ea0@2@0@Z
void Obj_80ea0::Set(Vec3_80ea0* p, Vec3_80ea0* q) {
    x[0] = p->a;
    x[1] = p->b;
    x[2] = p->c;
    x[3] = q->a;
    x[4] = q->b;
    x[5] = q->c;
    flags |= 0x20;
}

} // namespace fn_f9399ba1

// 0x00080ef0 FUN_00080ef0 (13 B): matches/0x00080ef0.cpp
// sym: ?FUN_00080ef0@C_80ef0@owners@@QAEXH@Z
void owners::C_80ef0::FUN_00080ef0(int x) {
    *(int*)(pad + 0xbc) = x;
}


// 0x00080f00 FUN_00080f00 (13 B): matches/0x00080f00.cpp
// sym: ?FUN_00080f00@C_80f00@owners@@QAEXH@Z
void owners::C_80f00::FUN_00080f00(int x) {
    field = x;
}


// 0x00080f10 FUN_00080f10 (13 B): matches/0x00080f10.cpp
// sym: ?FUN_00080f10@C_80f10@owners@@QAEXH@Z
void owners::C_80f10::FUN_00080f10(int x) {
    value = x;
}


// 0x00080f20 FUN_00080f20 (13 B): matches/0x00080f20.cpp
// sym: ?FUN_00080f20@C_80f20@owners@@QAEXH@Z
void owners::C_80f20::FUN_00080f20(int x) {
    m = x;
}


// 0x00080f30 FUN_00080f30 (13 B): matches/0x00080f30.cpp
// sym: ?FUN_00080f30@Thing_80f30@owners@@QAEXH@Z
void owners::Thing_80f30::FUN_00080f30(int x) {
    value = x;
}


// 0x00080f40 FUN_00080f40 (29 B): matches/0x00080f40.cpp
// sym: ?FUN_00080f40@C_80f40@owners@@QAEX_N@Z
void owners::C_80f40::FUN_00080f40(bool b) {
    if (b)
        flags |= 0x10;
    else
        flags &= 0xffffffef;
}

namespace fn_f9399ba1 {

// 0x00080f60 FUN_00080f60 (261 B): equivalent/0x00080f60.cpp
// sym: _FUN_00080f60 @abad7c37dc95 @w2e6d5445228c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00080f60 @ 0x00080f60
extern "C" void __cdecl FUN_00080f60(First_80f60* first, Second_80f60* second, const Matrix* input, int value, int extra, Vec_80f60* result) {
 struct Locals { Vec_80f60 a; Vec_80f60 b; float padding; Rotation_80f60 rotation; Matrix matrix; } local;
 result->z=0.0f; result->y=0.0f; result->x=0.0f;
 if(first) first->query(value,extra,&local.a); else { local.a.z=0.0f;local.a.y=0.0f;local.a.x=0.0f; }
 if(second) {
 ((owners::Quat_22b370 *)&(local.rotation))->FUN_0022b370((const float *)(const Matrix *)input);
 second->query(value,&local.b);
 local.b.x=-local.b.x; local.b.y=-local.b.y; local.b.z=-local.b.z;
 FUN_0022b080(&local.rotation,&local.rotation,&local.b);
 local.rotation.FUN_0022b650(&local.matrix);
 } else { local.matrix=*input; }
 ((owners::M_22c3b0 *)&(local.matrix))->FUN_0022c3b0((float *)(const Vec_80f60 *)(&local.a), (float *)(Vec_80f60 *)result);
}


// 0x00081070 FUN_00081070 (36 B): matches/0x00081070.cpp
// sym: ?f@fn_f9399ba1@@YAXPAPAVObj@1@PAV21@@Z
void f(Obj** slot, Obj* value) {
    if (value)
        value->Add();
    if (*slot)
        (*slot)->Release();
    *slot = value;
}

} // namespace fn_f9399ba1

// 0x000810f0 FUN_000810f0 (578 B): equivalent/0x000810f0.cpp [wrapped: conflict: CCivilian; World; pure3d::Entity]
// sym: ??0CCivilian@fn_000810f0@@QAE@HPAVDevice_810f0@1@HHHD@Z @3e09b4858017 @w2f34eb238bf9
namespace fn_000810f0 {
// STATUS: equivalent (tools/equiv.py level 3: 19916 inputs, branch coverage 18/18)
// FUN_000810f0 @ 0x000810f0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
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

struct Vec3_810f0 {
    float x, y, z;
};

struct NameHolder_810f0 {
    char pad[8];
    void FUN_0027b040(const char* name);
};

struct Matrix {
    char pad[0x40];
    void FUN_0022b980();
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0_00038290();
    char pad04[4];
    NameHolder_810f0 nameHolder;
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

// ref-counted object: slot 0 = AddRef, slot 1 = Release
class Device_810f0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual int s11();
};

class Skeleton {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x148 - 4];
    int f148;
    Skeleton* FUN_00287860();
    void FUN_00288080(int a);
    void FUN_00284ad0(int a);
};

class CollisionSphere_810f0 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x70];
    char* f74;
    CollisionSphere_810f0* FUN_002efe50(Vec3_810f0* v, float f);
};

struct Camera {
    void FUN_001b4360(void* who);
};

struct World {
    char pad00[0x10];
    Camera* camera;
};


extern "C" void* FUN_0008d690(unsigned int size);
void* thunk_FUN_0008d690(unsigned int size);
extern "C" CollisionSphere_810f0* FUN_002efca0(void* mem, int arg);

class CCivilian : public pure3d::Entity {
public:
    CCivilian(int a1, Device_810f0* dev, int a3, int a4, int a5, char flag);
    virtual void v1_000382a0();
    virtual void v2();

    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    Matrix m34;
    int f74;
    int f78;
    int f7c;
    int f80[15];  // 0x80 .. 0xbc
    int fbc[4];   // 0xbc .. 0xcc
    int fcc[7];   // 0xcc .. 0xe8
    Device_810f0* fe8;
    int fec;
    Skeleton* ff0;
    char padf4[0x100 - 0xf4];
    CollisionSphere_810f0* f100;
};

CCivilian::CCivilian(int a1, Device_810f0* dev, int a3, int a4, int a5, char flag)
{
    int i;
    f18 = a4;
    f1c = a5;
    f10 = a3;
    f14 = 0x10;
    f20 = 1;
    f24 = 0;
    f28 = 2;
    f2c = 0;
    f30 = 0;
    for (i = 0; i < 15; i++)
        f80[i] = 0;
    for (i = 0; i < 4; i++)
        fbc[i] = -1;
    for (i = 0; i < 7; i++)
        fcc[i] = 0;
    fe8 = 0;
    fec = 0;
    ff0 = 0;
    f100 = 0;
    nameHolder.FUN_0027b040((const char*)a1);
    if (flag)
        f28 |= 4;
    m34.FUN_0022b980();
    f7c = 0;
    f78 = 0;
    f74 = 0;
    f10 = a3;

    if (dev)
        dev->AddRef();
    if (fe8)
        fe8->Release();
    fe8 = dev;
    void* mem = thunk_FUN_0008d690(0x150);
    Skeleton* skel = 0;
    if (mem)
        skel = ((Skeleton*)mem)->FUN_00287860();
    if (skel)
        skel->AddRef();
    if (ff0)
        ff0->Release();
    ff0 = skel;
    int value = fe8->s11();
    ff0->FUN_00288080(value);
    ff0->FUN_00284ad0(0);
    *(int*)((char*)ff0 + 0x148) = 0;

    Vec3_810f0 v;
    v.x = 0.0f;
    v.y = 0.8f;
    v.z = 0.0f;
    mem = FUN_0008d690(0x48);
    CollisionSphere_810f0* ctl = 0;
    if (mem)
        ctl = ((CollisionSphere_810f0*)mem)->FUN_002efe50(&v, 0.801f);
    ctl = FUN_002efca0(ctl, a1);
    if (ctl)
        ctl->AddRef();
    if (f100)
        f100->Release();
    f100 = ctl;
    ctl->f74[0x72] = 0;
    DAT_004dd700->camera->FUN_001b4360(this);
}
} // namespace fn_000810f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

