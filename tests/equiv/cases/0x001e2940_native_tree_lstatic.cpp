// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// (regress, tri2) lstaticbr: a function-local static's guard `$S1` in a wrapped block: MSVC's and clang's manglings differ in the scope token and in the back-references after it
// object 0x001db770..0x001e5f10 (kind game, layer game, confidence high), dominant class CSPManager
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
#define TREE_TU_BEGIN namespace fn_f75938cb {
#define TREE_TU_END }
namespace fn_f75938cb {} using namespace fn_f75938cb;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f75938cb {
class A_1db770 {
  public:
    A_1db770* Get();
};
struct Quat_1db780 {
    float x, y, z, w;
};
struct PackedRotation {
    short x, y, z;

    void FUN_001db780(const Quat_1db780 *q);
};
struct Quaternion_1db820 { float x, y, z, w; };
struct PackedQuaternion_1db820 {
 short x, y, z;
 Quaternion_1db820* FUN_001db820(Quaternion_1db820* out);
};
class Obj_1db9e0 {
  public:
    char pad[0x10];
    int value;
    int Get() { return value; }
};
struct Obj_1db9f0 {
    char pad[0x34];
    int value;
    int Get();
};
class X_1dba00 {
  public:
    char pad[0x38];
    char* value;
    char* Get(int index);
};
class Big_1dba80 {
  public:
    char pad[0x1e834];
    unsigned char value;
    void Set(unsigned char x);
};
class Obj_1dba90 {
  public:
    void Set(int v);
    char pad[0x1e838];
    int mValue;
};
struct Init {
};
struct State_1dbba0 {
    char x[0x10];
    int at10;
    char x14[4];
    int at18;
    int at1c;
    unsigned short at20;
    unsigned short at22;
    unsigned short at24;
    unsigned char at26;
    unsigned char at27;
};
struct Setup_1dbba0 {
    void Init_001db780(float*);
};
class X_1dbc40 {
  public:
    char pad[8];
    void Fnf_0027af00();
    X_1dbc40* target();
};
class C_1dbc60 {
    char pad[8];

  public:
    void f();
};
class S_1dbc60 {
  public:
    void Fnh_0027af50();
};
struct X_1dbc90 {
    void Call_0027af00();
    X_1dbc90* Target();
};
class pddiObject_1dbd20 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_1dbd20 : public pddiObject_1dbd20 {};
class pddiBaseShader_1dbd20 : public pddiShader_1dbd20 {
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
class d3dShader_1dbd20 : public pddiBaseShader_1dbd20 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class Obj_1dbd40 {
  public:
    char pad[0x1eee4];
    int x;
};
class Loader_1dbd50 {
  public:
    void Config_001d2ba0(const char*, int, int);
    void Type_001d2ba0(const char*, int, int);
};
extern "C" Loader_1dbd50* __cdecl FUN_001d4c90();
class CSPManager_1dbe60 {
  public:
    char pad0[0x61e];
    short entries[0x800][20];
    char pad1[0x1e608 - 0x61e - 0x800 * 40];
    int index;
    void run();
};
typedef unsigned __int64 Key_1dbec0;
extern "C" Key_1dbec0 __cdecl FUN_0027afb0(const char*);
struct Key { int first; int second; };
struct CSPManager_nv_1dc100 {
    int FUN_001dbfe0(int key);
};
struct Key_1dc170 {
    int lo;
    int hi;
};
struct Entry_1dc170 {
    Key_1dc170 key;                // 0x00
    char pad8[0x22 - 8];
    short slot;             // 0x22
    char pad24[4];
};
struct Slot_1dc170 {
    unsigned char flags;
    char pad1[19];
};
struct KeyRef {
    char pad0[8];
    Key_1dc170 key;                // 0x08
};
class SlotTable_1dc170 {
public:
    char pad0[0x608];
    Entry_1dc170 entries[0x800];   // 0x608
    char pad14608[0x10];
    Slot_1dc170 slots[1];          // 0x14618; indexed by Entry::slot (may be negative)
    bool FUN_001dc170(const KeyRef* ref, char set);
};
struct CSPManager_nv_1dc1f0 {
    int FUN_001dc070(void*);
};
struct Item_1dc230 {
    short value;
    char pad[0x26];
};
class Obj_1dc230 {
  public:
    char pad[0x62a];
    Item_1dc230 indices[0x800];
    bool target(int index, int mode);
};
class Obj_1dc290 {
  public:
    char pad0[0x608];
    struct Entry {
        char pad[0x28];
    } entries[1];
    int get(int index);
};
struct Tracker_1dc2d0 {
    int FUN_001d5c70(int value);
};
class Player_1dc2d0 {
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
    virtual void Play(int value, int mode);

    char pad04[0xe8];
    Tracker_1dc2d0 *tracker;   // +0xec
};
struct Voice_1dc2d0 {
    char pad0[0x18];
    Player_1dc2d0 *player;     // +0x18
    char pad1c[4];
    unsigned short state;   // +0x20
    short channel;      // +0x22
    char pad24[2];
    unsigned char value;    // +0x26
    char pad27;
};
struct Channel {
    char pad0[0x10];
    unsigned char flags;    // +0x10
    char pad11[3];
};
class Mixer {
public:
    int FUN_001dc2d0(int index, int value);

    char pad0[0x608];
    Voice_1dc2d0 voices[1];
};
struct CSPManager_nv_1dc350 {
    int Find_001dbfe0(char*);
};
struct Vec3_1dc3b0 { float x, y, z; };
struct Record_1dc3b0 { char pad[0x10]; unsigned int flags; };
struct Link_1dc3b0 {
    void *FUN_001d6b40();
};
struct Entry_1dc3b0 {
    char pad0[0x18];
    Link_1dc3b0 *link;
    char pad1[0x22 - 0x1c];
    short recordIndex;
    char pad2[0x28 - 0x24];
};
struct Target_1dc3b0 {
    char pad0[0x608];
    Entry_1dc3b0 entries[1];
    char pad1[0x14608 - 0x608 - sizeof(Entry_1dc3b0)];
    Record_1dc3b0 records[1];
    void *FUN_001dc3b0(int idx);
};
struct Vec3_1dc420 {
    float x, y, z;
};
struct Target_1dc420 {
    void FUN_001d7810(Vec3_1dc420 v);
};
struct Slot_1dc420 {
    char pad0[0x18];
    Target_1dc420 *target;
    char pad1c[6];
    short link;
    char pad24[4];
};
struct Entry_1dc420 {
    Vec3_1dc420 pos;
    char pad0c[4];
    unsigned char flags;
    char pad11[3];
};
struct Table_1dc420 {
    char pad0[0x608];
    Slot_1dc420 slots[0x800];
    Entry_1dc420 entries[1];
    bool FUN_001dc420(int index, Vec3_1dc420 *pos);
};
struct Vec_1dc4a0 { float x,y,z; };
struct Vec_1dc4a0;
struct Result_1dc4a0 {  };
struct CSPManager_1dc4a0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual Result_1dc4a0* query(); };
struct Transform_1dc4a0 { char data[16]; void FUN_0022b4d0(Vec_1dc4a0*,Vec_1dc4a0*); };
struct Part_1dc4a0 { void FUN_001db820(Transform_1dc4a0*); };
struct Entry_1dc4a0 { char pad[16]; Part_1dc4a0 part; char p2[7]; CSPManager_1dc4a0* object; char p3[6]; short index; char p4[4]; };
struct Flag_1dc4a0 { unsigned char bits; char pad[19]; };
extern hulk_freg __cdecl FUN_00224ea0(float,float);
struct Owner_1dc4a0 { char pad[0x608]; Entry_1dc4a0 entries[1932]; int FUN_001dbfe0(int); hulk_freg target(int); };
struct Matrix {
  public:
    unsigned int words[16];
    void FUN_0022b980();
};
struct Vector { float x,y,z;  };
struct Rotation_1dc550 { char data[8]; void FUN_001db780(const Vector*); };
struct Flag_1dc550 { unsigned char bits; char pad[19]; };
struct Vec_1dc660 { unsigned int x,y,z; };
struct Transform_1dc660 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void apply(void*, Vec_1dc660*, int);
};
struct Node {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void update(int);
    char _m_pad_4[0xc];
    Transform_1dc660* transform;
    char _m_pad_14[0x84];
    unsigned char data[1];
    char _m_pad_99[0x83];
    Node* next;
    Matrix* FUN_001d6b40();
    void FUN_001d6b60(Matrix,int);
    unsigned int Check_00078b20();
};
struct Record_1dc550 { char pad[16]; Rotation_1dc550 rotation; Node* node; char pad2[6]; short id; char pad3[4]; };
struct CSPManager_1dc550 {
 union {
  struct { char pad[0x608]; Record_1dc550 records[1]; } entries;
  struct { char pad[0x14618]; Flag_1dc550 flags[1]; } status;
 };
 int FUN_001dbfe0(int);
 bool target(int key,float x,float y,float z);
};
struct Result_1dc660 { char pad[112]; Node* node; };
struct Handle_1dc660 {  Vec_1dc660* FUN_001d77c0(); };
struct Record_1dc660 { char pad0[24]; Handle_1dc660* handle; char pad1[6]; short index; char pad2[4]; };
struct Flag_1dc660 { unsigned char bits; char pad[19]; };
struct CSPManager_1dc660 {
 union { struct { char pad[0x608]; Record_1dc660 records[4096]; } entries; Flag_1dc660 flags[65536]; };
 int FUN_001dbfe0(int);
 Vec_1dc660* target(Vec_1dc660*, int);
};
struct Vec_1dc720 { float x,y,z; bool FUN_0022d2b0(const Vec_1dc720*, float); };
struct Motion_1dc720 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(int);
 void FUN_002f5a20(Vec_1dc720*);
};
struct State_1dc720 { char pad[0x70]; Motion_1dc720* motion; };
struct CSPManager_nv_1dc720 {
    Vec_1dc720* FUN_001d77c0();
    void FUN_001d7510();
};
struct Record_1dc720 { char pad[0x18]; CSPManager* object; char extra[6]; short index; char tail[4]; };
struct Flag_1dc720 { unsigned char bits; char pad[19]; };
struct CSPManager_1dc720 {
 char pad[0x608]; Record_1dc720 records[2048]; char gap[16]; Flag_1dc720 flags[32768];
 int FUN_001dbfe0(int);
 bool FUN_001dc720(int id, Vec_1dc720 position);
};
struct Obj_1dc8d0 {
    float v[0x44 / 4 + 1];
};
struct Ent_1dc8d0 {
    char p[0x44];
    float f;
};
struct Slot_1dc8d0 {
    char p0[0x18];
    Ent_1dc8d0* e;
    char p1[4];
    unsigned short cnt;
    char p2[6];
};
struct Rec_1dc8d0 {
    unsigned flags;
    char p[16];
};
class CSPManager_1dc8d0 {
  public:
    int Find_001dbfe0(int key);
    hulk_freg Get(int key);
    char pad[0x608];
    Slot_1dc8d0 slots[1];
};
struct Linked { char reserved[0x108]; int value; };
struct Flag { unsigned char bits; char unused[19]; };
struct Entry_1dc9a0 {
    char pad[0x18];
    struct Item_1dc9a0* item;
    char p2[6];
    short index;
    short value;
};
struct Item_1dc9a0 {
};
struct Flag_1dc9a0 {
    char pad[16];
    unsigned char bits;
};
class CSPManager_1dc9a0 {
  public:
    char pad[0x608];
    Entry_1dc9a0 entries[1];
    int Find_001dbfe0(int);
    void Func(int key, int val);
};
class A_1dca40 {
  public:
    void Fn(int a, int b, int c);
};
struct V3_1dcb00 {
    float x, y, z;
};
struct Finder_1dcb00 {
    int FUN_001c8060(V3_1dcb00* box, int flag);
};
struct Holder_1dcb00 {
    int pad;
    Finder_1dcb00* finder;
};
Holder_1dcb00* FUN_001c3d90();
struct Frame_1dcb00 {
    V3_1dcb00 pos;
    V3_1dcb00 boxMin;
    V3_1dcb00 boxMax;
};
class Item {
  public:
    char _m_pad_0[0xf8];
    unsigned char value;
};
struct Entry {
  public:
    int first;
    int second;
    char _m_pad_8[0x10];
    union { Item* item; Linked *linked; void* obj; char* p; };
    char _m_pad_1c[0x6];
    union { short id; short n; short x; };
    short fallback;
    char _m_pad_26[0x2];
};
struct CSPManager_1dc070 { char pad[0x608]; Entry entries[0x800]; int FUN_001dc070(const Key* key); };
struct CSPManager_1dc940 { char pad[0x608]; Entry entries[1]; int FUN_001dbfe0(int key); int FUN_001dc940(int key); };
class CSPManager_1dccf0 {
  public:
    char pad[0x608];
    Entry entries[1];
    int find_001dbfe0(int);
    bool set(int key, unsigned char value);
};
struct Entry_1dcd30 { char pad[22]; short active; char pad2[10]; short recordIndex; char pad3[4]; };
struct Record_1dcd30 { char pad[16]; unsigned short flags; char pad2[2]; };
struct CSPManager_1dcd30 {
 char pad[0x608];
 Entry_1dcd30 entries[2048];
 Record_1dcd30 records[2048];
 int cursor;
 char tail[0x64c];
 int count;
 void FUN_001e5bc0(int index);
 void FUN_001dcd30(int index);
};
struct Vec3_1dcdf0 { float x,y,z; };
struct Entry_1dcdf0 { Vec3_1dcdf0* FUN_001d6b40(); };
struct Object {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual Matrix* v15();
    char _m_pad_4[0x1e61c];
    Entry_1dcdf0* entries[128];
    int count;
    bool FUN_001dcdf0(float x,float y,float z,float radius);
};
struct Triple {
  public:
    float x;
    float y;
    float z;
};
struct Wrapper {
    void FUN_001dcdf0(Triple value, unsigned int last);
    void FUN_001dcf00(Triple value, unsigned int last);
};
struct Block_1dd090 {
    char pad[0x1b8];
    int v0;
    int v1;
    int v2;
    char flag;
};
struct Item_1dd090;
struct Info_1dd090 {
    char pad[0x70];
    Block_1dd090* block;
};
struct Item_1dd090 {
};
class Registry_1dd090 {
public:
    char pad[0x1e620];
    Item_1dd090* items[0x80];
    int count;
    void FUN_001dd090(int a, int b, int c);
};
struct Slot_1dd110 {
    unsigned int keyLo;
    unsigned int keyHi;
    float value;
    int pad;
};
class SlotTable_1dd110 {
public:
    char pad0[0x1ec60];
    Slot_1dd110 slots[16];
    bool FUN_001dd110(const char* name, float value);
};
struct Source_1dd330 { char pad[0x30]; unsigned int x,y,z; };
struct Temp_1dd330 { unsigned int data[4];  };
struct Link_1dd330 { unsigned int data[2]; void FUN_0027af70(void*); };
struct State_1dd330 { char pad[6]; unsigned short id; char rest[10]; unsigned short recordIndex; char pad2[2]; unsigned char active,inverted; void FUN_001db780(Temp_1dd330*); };
struct Item_1dd330 { Link_1dd330 first,second; State_1dd330 state; void FUN_001dbba0(); };
struct Record_1dd330 { unsigned int x,y,z; float distance; union { unsigned short flags; struct { unsigned char low,high; } bytes; }; unsigned short itemIndex; };
struct CSPManager_1dd330 { char pad[0x608]; Item_1dd330 items[2048]; Record_1dd330 records[2048]; int nextItem; char gap[8]; int count; void FUN_001dbe60(); void FUN_001dcd30(int); int target(void*,void*,Source_1dd330*,unsigned char,unsigned char,unsigned char,unsigned char); };
class A_1dd450 {
  public:
};
struct CSPManager_nv_1dd450 {
    void Fng_001e5bc0(int);
};
struct CSPManager_nv_1dd470 {
    void FUN_001d6b60(Matrix matrix, unsigned int option);
};
struct Rotation_1dd470 {
    unsigned int words[4];
};
struct State_1dd470 {
    unsigned int words[2];
    void FUN_001db780(const Rotation_1dd470*);
};
struct Entry_1dd470 {
    char pad[16];
    State_1dd470 state;
    CSPManager* object;
    char pad2[6];
    short stateIndex;
    char tail[4];
};
struct Position_1dd470 {
    unsigned int x, y, z;
    unsigned int other;
    unsigned char flags;
    char pad[3];
};
struct Manager_1dd470 {
    char pad[0x608];
    Entry_1dd470 entries[2048];
    Position_1dd470 positions[1];
    bool target(int index, const Matrix* matrix, unsigned int option);
};
struct Rotation_1dd520 { unsigned int words[4]; void FUN_0022b650(Matrix*); };
struct Orientation_1dd520 { unsigned int words[2]; void FUN_001db820(Rotation_1dd520*); };
struct Entry_1dd520 { char pad[16]; Orientation_1dd520 orientation; Object* object; char pad2[6]; short type; char pad3[4]; };
struct Type { unsigned int position[3]; unsigned int unused; unsigned char flags; char pad[3]; };
struct Manager_1dd520 { char pad[0x608]; Entry_1dd520 entries[2048]; Type types[1]; bool target(int index, Matrix* out); };
struct Id_1dd5d0 {
    unsigned int lo;
    unsigned int hi;
};
struct Vec3_1dd5d0 {
    float x, y, z;
};
struct Anchor_1dd5d0 {
    const Vec3_1dd5d0 *FUN_001d6b40();
};
struct Slot_1dd5d0 {
    Vec3_1dd5d0 pos;
    int pad0c;
    unsigned int flags;
};
struct Entry_1dd5d0 {
    Id_1dd5d0 id;
    char pad08[0x10];
    Anchor_1dd5d0 *anchor;
    char pad1c[6];
    short slot;
    char pad24[4];
};
class Registry_1dd5d0 {
public:
    char pad000[0x608];
    Entry_1dd5d0 entries[0x800];
    Slot_1dd5d0 slots[1];
    bool GetPosition(const Id_1dd5d0 *key, Vec3_1dd5d0 *out);
};
struct Table { char pad[0x608]; Entry entries[0x800]; bool FUN_001dd7b0(const Key *key); };
struct Obj_1dd800 {
    char pad[0x62a];
    struct Rec {
        short index;
        char rest[0x26];
    } rec[0x800];
    bool target(int index);
};
class Result_1dd840 {
  public:
    char pad[0x74];
    void* p;
};
class Context {
  public:
};
class Obj_1dd840 {
  public:
    char pad0[0x608];
    struct Entry {
        char pad[0x18];
        Context* p;
        char pad2[6];
        short index;
        char tail[4];
    } entries[0x800];
    void Set(int n, unsigned char value);
};
struct Helper_1dd930 {
    void Use_0027af70(void*);
};
struct Entry_1dd930 {
    char pad[0x18];
    hulk_intptr ptr;
    char gap[6];
    short index;
    char tail[4];
};
struct Obj_1dd930 {
    char pad[0x608];
    Entry_1dd930 entries[0x800];
    bool Run(int index, Helper_1dd930* arg);
};
class Entry_1dd9e0 {
  public:
    char pad[0x18];
    Node* node;
    char pad2[6];
    short index;
    char pad3[4];
};
class Obj_1dd9e0 {
  public:
    char pad[0x608];
    Entry_1dd9e0 entries[0x800];
    unsigned char Target(int index);
};
struct Bits {
    unsigned short a : 12;
    unsigned short b : 1;
    unsigned short c : 3;
};
class CSPManager_1dda80 {
  public:
    unsigned char check(int index);
    char pad[0x62a];
};
class Obj {
  public:
    char _m_pad_0[0x1a0];
    char flag;
    unsigned char Go_001dc230(Item*, int);
    unsigned char Run(hulk_intptr, int);
    int F(int a, int b);
    int FnG_001dc2d0(int a, int b);
    char Act_001d7150(int);
};
struct Record {
    unsigned char flags;
    char rest[19];
};
class CSPManager_1ddb30 {
  public:
    char pad[0x608];
    Entry entries[1];
    int Find_001dbfe0(int);
    void Set(int, unsigned char);
};
class CSPManager_1ddb80 {
  public:
    int Find_001dbfe0(int);
    void Set(int, unsigned char);
    char pad[0x608];
    Entry entries[1];
};
struct Obj_1ddc20 {
    char pad00[0x198];
    int mode;
};
struct Slot_1ddc20 {
    char pad00[0x10];
    unsigned char flags;
    char pad11[3];
};
struct Entry_1ddc20 {
    char pad00[0x18];
    Obj_1ddc20 *obj;
    char pad1c[6];
    short slot;
    char pad24[4];
};
extern "C" int __cdecl FUN_00345475(int c);
class CSPManager_1ddc20 {
public:
    char pad00[0x608];
    Entry_1ddc20 entries[0x800];
    Slot_1ddc20 slots[1];

    int FUN_001dbfe0(int key);
    void FUN_001ddc20(int key, const char *name);
};
struct Alignment {
    char pad0[0x198];
    int kind;
};
struct Slot_1ddcc0 {
    char pad0[0x18];
    Alignment *brain;
    char pad1c[6];
    short id;
    char pad24[4];
};
struct Pool_1ddcc0 {
    unsigned char flags;
    char pad[19];
};
class CSPManager_1ddcc0 {
public:
    char pad0[0x608];
    Slot_1ddcc0 slots[0x800];
    char pad14608[0x10];
    Pool_1ddcc0 pools[1];
    int FUN_001dbfe0(int key);
    const char *FUN_001ddcc0(int key);
};
class Target_1dddf0 {
    char pad[0x1eee0];

  public:
    float value;
};
class Obj_1dde00 {
  public:
    char pad[0x1eee0];
    int value;
    void Set(int x);
};
class Target_1dde20 {
  public:
    char pad[0x1eee4];
    int m1eee4;
    void Set(int value);
};
struct Entry_1de140 {
    unsigned int a, b, c;
    float priority;
    unsigned short d, e;
};
struct Elem_1de1f0 {
    int a;
    int b;
    int c;
    int d;
    short e;
    short f;
};
struct Sub_1de360 {
    virtual void v0();
    virtual void v1();
};
struct CSPListener_1de360 {
    int pad0;
    Sub_1de360 sub;
    CSPListener_1de360 *FUN_001db1c0(int arg);
};
extern "C" void *FUN_0008d690(unsigned int size);
struct Owner_1de360 {
    char pad[0x1e824];
    CSPListener_1de360 *current;
    char pad1e828[8];
    int arg;
    char pad1e834[0x1ec40 - 0x1e834];
    int z0, z1, z2, z3;
    void FUN_001de360(hulk_intptr a);
};
class Obj_1de3f0 {
public:
    virtual void v0();
    virtual void Release();
    void FUN_001d7ff0();
};
class ObjList_1de3f0 {
public:
    char pad[0x1e620];
    Obj_1de3f0* items[128];    // 0x1e620
    int count;          // 0x1e820
    void FUN_001de3f0(Obj_1de3f0* target);
};
struct Quat { float x, y, z, w; };
struct Item_1dec10 {
    virtual void vfn0();
    virtual void vfn1();
    void FUN_001d7ff0();
};
struct Res {
    virtual void vfn0();
    virtual void vfn1();
};
struct Buffer {
    void FUN_00263e90();
};
struct SlotA {
    char pad[8];
    void FUN_0027b040(int v);
};
struct SlotC_1dec10 {
    char pad[6];
    void FUN_001db780(Quat *q);
};
struct Slot_1dec10 {
    SlotA a;            // 0x00
    SlotA b;            // 0x08
    SlotC_1dec10 c;            // 0x10
    short active;       // 0x16
    Res *res;           // 0x18
    int field1c;        // 0x1c
    short field20;      // 0x20
    short recIndex;     // 0x22
    short field24;      // 0x24
    char field26;       // 0x26
    char field27;       // 0x27
};
struct Rec {
    int a;
    int b;
    int c;
    float maxv;
    short s10;
    short s12;
};
class Pool_1dec10 {
public:
    char pad0[0x608];
    Slot_1dec10 slots[0x800];      // 0x608
    Rec recs[0x800];        // 0x14608
    int f1e608;
    int f1e60c;
    int f1e610;
    int recCount;           // 0x1e614
    Buffer *buffer;         // 0x1e618
    int f1e61c;
    Item_1dec10 *items[0x80];      // 0x1e620
    int itemCount;          // 0x1e820
    char pad1[0x1ec58 - 0x1e824];
    int f1ec58;
    void FUN_001dec10();
};
struct Entry_1deda0 {
    int keyLo;
    int keyHi;
    char pad08[0xe];
    unsigned short f16;
    char pad18[0xa];
    short slot;
    char pad24[4];
};
struct Slot_1deda0 {
    char pad00[0x10];
    unsigned short flags;
    char pad12[2];
};
struct Key_1deda0 {
    char pad00[8];
    int lo;
    int hi;
};
struct Target_1deda0 {
    char pad00[0x594];
    void FUN_001b5d20(unsigned int a, unsigned int b);
};
class Manager_1deda0 {
public:
    char pad00[0x608];
    Entry_1deda0 entries[0x800];
    Slot_1deda0 slots[1];

    Target_1deda0 *FUN_001b6580();
    void FUN_001deda0(Key_1deda0 *key);
};
struct Item_1dee40 {
    char pad0[8];
    int f8;
    int fc;
};
class Table_1dee40 {
public:
    char pad0[0x1e620];
    Item_1dee40 *items[0x200 / 4];
    int count;                  // 0x1e820

    Item_1dee40 *Get(int i) { return (i < count && i >= 0) ? items[i] : 0; }
    Item_1dee40 *FUN_001dee40(int a, int b);
};
struct Key_1deeb0 {
    int lo, hi;
};
struct Entry_1deeb0 {
    char pad[8];
    Key_1deeb0 id;         // 0x8
};
class EntryList_1deeb0 {
public:
    char pad[0x1e620];
    Entry_1deeb0* entries[128];    // 0x1e620
    int count;              // 0x1e820
    Entry_1deeb0* FUN_001deeb0(const Key_1deeb0* key);
};
struct Id_1def30 {
    int lo, hi;
};
struct Entry_1def30 {
    char pad0[8];
    int idLo;
    int idHi;
};
Id_1def30 __cdecl FUN_00096d80(const char *name);
class Table_1def30 {
public:
    Entry_1def30 *FUN_001def30(const char *name);

    char pad0[0x1e620];
    Entry_1def30 *entries[128];
    int count;

    Entry_1def30 *At(int i) {
        if (i < count && i >= 0) {
            return entries[i];
        }
        return 0;
    }
};
struct Mat4_1df010 {
    float m[12];
    int tx, ty, tz;
    float w;
    void FUN_0022b980();
};
struct Index_1df010 {
    int FUN_0027b200(unsigned __int64 key);
};
struct Holder_1df010 {
    char pad00[8];
    Index_1df010 *index;
};
struct Part;
struct Actor_1df010 {
    char pad00[0x120];
    Holder_1df010 *holder;
    void FUN_0003acf0(int a, Part *part, int index, int c, int d, Mat4_1df010 *mat);
};
struct Registry_1df010 {
    Actor_1df010 *FUN_00024280(unsigned __int64 id);
};
struct Group_1df010 {
    char pad00[0x20];
    Registry_1df010 *registry;
};
class Owner_1df010 {
public:
    char pad00[0x1e830];
    Group_1df010 *group;
    Part *FUN_001def30(int a);
    void FUN_001df010(int a1, const char *actorName, int a3, const char *partName, int px, int py, int pz,
                      float rx, float ry, float rz);
};
struct CSPManager_nv_1df100 {
    int lookup_001dbfe0(int);
};
struct CSPManager_1df130 {
    hulk_intptr FUN_001def30(int);
    int FUN_001d7100(int);
    int FUN_001df130(int);
};
struct ThisWrap_001df160 {
    Obj* Find_001def30(int);
    char Target(int id, int arg);
};
struct Vec3_1df190 {
    unsigned int x, y, z;
};
struct CSPManager_nv_1df190 {
    int Find_001dbfe0(int arg);
    Vec3_1df190* Get_001dc3b0(int index);
};
struct Vec3_1df1e0 {
    float x, y, z;
};
struct CSPManager_1df1e0 {
    int Find_001dbfe0(int);
    char Do_001dc420(int, Vec3_1df1e0*);
    char FUN_001df1e0(int a, Vec3_1df1e0 b);
};
class Item_1df210 {
  public:
    virtual void Destroy();
    virtual void Release();
};
class Owner_1df210 {
  public:
    char pad[0x1ec40];
    Item_1df210* items[4];
    int count;
    bool Add(Item_1df210* item);
};
class Item_1df290 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_1df290 {
  public:
    char pad[0x1ec40];
    Item_1df290* items[4];
    int count;
    void Clear();
};
struct ThisWrap_001df320 {
    void FUN_001def30(int);
    void FUN_001df320(int a, int b, int c, int d, int e, int f);
};
class Obj_1df330 {
  public:
    char pad[0x194];
    char flag;
    Obj_1df330* Find_001def30(int id);
    void Set(int id, char c);
};
union Arg_1df400 {
    int id;
    unsigned char flag;
    unsigned int word;
};
class Target_1df400 {
public:
    void FUN_001d74c0(int a, int b, int c, unsigned int flag);
};
class Registry_1df400 {
public:
    int FUN_00106230(int a);
};
} // namespace fn_f75938cb
struct World {
    char pad0[0x18];
    Registry_1df400* registry;
};
namespace fn_f75938cb {
class Manager_1df400 {
public:
    Target_1df400* FUN_001def30(int id);
    bool FUN_001df400(Arg_1df400 id, int a2, int a3, int a4, const char* mode);
};
struct V3_1df4c0 {
    float x, y, z;
    hulk_freg FUN_000111f0();
};
struct Holder_1df4c0 {
    char pad00[0x50];
    V3_1df4c0 pos;
};
struct Owner_1df4c0 {
};
struct Entry_1df4c0 {
    char pad00[0x18];
    Owner_1df4c0 *owner;
    char pad1c[6];
    short slot;
    char pad24[4];
};
struct Slot_1df4c0 {
    char pad00[0x10];
    unsigned char flags;
    char pad11[3];
};
class Manager_1df4c0 {
public:
    char pad00[0x608];
    Entry_1df4c0 entries[0x800];
    Slot_1df4c0 slots[1];

    char FUN_001df4c0(int index);
};
class Function_1df560 {
  public:
    Function_1df560(const char*, int);
    virtual void* v0_001df690(int);
    char pad[0xc];
};
class Function5_1df560 : public Function_1df560 {
  public:
    Function5_1df560(const char*, hulk_intptr);
    char c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c1a, c1b;
    int m1c;
};
struct Function_1df5e0 {
    virtual void f0();
    virtual void f1();
};
void FUN_001df600(const char*, const char*, const char*, int);
typedef void (__cdecl *Callback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
class Dummy_1df730 {
  public:
    void Call(void*);
};
class CSPManager_1df7d0 {
  public:
    bool invoke(const char*, int, int);
};
struct Args_1df7d0 {
    const char* a;
    int b;
    int c;
};
class Function_1df870 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_1df870 {
  public:
    bool (CActorManager_1df870::*m)(const char*, bool);
};
struct Pair_1df870 {
    const char* p;
    bool b;
};
class CSPManager_1df910 {
  public:
    bool fn(const char*, int);
};
struct Args {
  public:
    union { const char* name; const char* s; };
    union { int n; float val; };
};
class Function_1df910 {
  public:
    virtual void v0();
    virtual void v1();
};
class CSPManager_1df9a0 {
  public:
    int method(const char*);
};
class Function_1df9a0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, void*);
};
class CFEManager_1dfa30 {
  public:
    void Call(const char*, int);
};
class Function_1dfa30 {
  public:
    virtual void f0();
    virtual void f1();
};
extern "C" char DAT_00423318[];
extern "C" char DAT_0048e10c[];
class Function_1dfae0 {
  public:
    Function_1dfae0(const char*, int);
};
class Method6_1dfae0 : public Function_1dfae0 {
  public:
    char pad[0x10];
    char m10;
    char m11;
    char m12;
    char m13;
    char m14;
    char m15;
    char pad16[2];
    char m18;
    char pad19[3];
    int m1c;
    Method6_1dfae0(const char*, hulk_intptr);
};
struct Function_1dfb80 {
    virtual void f0();
    virtual void f1();
};
void FUN_001dfba0(const char*, const char*, const char*, int);
struct Triple_1dfba0 {
    int a, b, c;
};
class Target_1dfba0 {
public:
    virtual void v0();
};
typedef void (Target_1dfba0::*Callback_1dfba0)(int, int, int, int, Triple_1dfba0, Triple_1dfba0);
class Function_1dfc90 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Pair_1dfc90 {
    int a;
    int b;
};
class CSPManager_1dfc90 {
  public:
    int Fn(int, int);
};
class CSPManager_1dfd30 {
  public:
    int Fn(const char*, const char*);
};
struct Pair {
    const char* a;
    const char* b;
};
class Function_1dfd30 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class CFEManager_1dfdd0 {
  public:
    void Call(const char*, int);
};
class Function_1dfdd0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Dummy_1dfe50 {
  public:
    void Call(void*);
};
extern "C" char DAT_00423368[];
class Method5_1dfe70 {
  public:
    hulk_intptr vptr;
    char pad4[12];
    char b10, b11, b12, b13, b14;
    char pad15[3];
    char b18;
    char pad19[3];
    void* p1c;
    void FUN_001d0480(void*, int);
    Method5_1dfe70* Init(void*, void*);
};
struct Function_1dff10 {
    virtual void f0();
    virtual void f1();
};
void FUN_001dff30(const char*, const char*, const char*, int);
struct CSPManager_1e0000 {
    void FUN_001e0000_callback(int, float, float, float);
};
struct Arguments {
  public:
    union { int id; const char* text; };
    union { int a; float first; int number; float value; };
    union { int b; float second; };
    float third;
};
extern "C" char DAT_00423388[];
class Method5_1e0030 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;
    ScriptMemberFn p1c;
    void FUN_001d0480(const char*, int);
    Method5_1e0030* Init(const char*, ScriptMemberFn);
};
struct Function_1e00d0 {
    virtual void f0();
    virtual void f1();
};
void FUN_001e00f0(const char*, const char*, const char*, int);
struct Vector_1e0230 { float x,y,z; };
struct CSPManager_1e0230 {};
struct Function_1e0230 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };
class CActorManager_1e0390;
typedef float (CActorManager_1e0390::*Fn_1e0390)(const char*);
class CActorManager_1e0390 {
  public:
    float Get(const char* s);
};
struct Function_1e0460 {
    virtual void f0();
    virtual void f1();
};
void FUN_001e0480(const char*, const char*, const char*, int);
class C {
  public:
    void f(int, int, int, int, int, int);
};
typedef void (C::*CB)(int, int, int, int, int, int);
class CSPManager_1e0530 {
  public:
    bool fn(const char*);
};
class Function_1e0530 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern "C" char DAT_004233f8[];
class Method5_1e0550 {
  public:
    hulk_intptr v;
    ScriptFunctionFields f;
    ScriptMemberFn m1c;
    char p20[0x20];
    void Init_001d0480(const char*, int);
    Method5_1e0550* Make(const char*, ScriptMemberFn);
};
struct Function_1e05f0 {
    virtual void f0();
    virtual void f1();
};
void FUN_001e0610(const char*, const char*, const char*, int);
} // namespace fn_f75938cb
namespace math {
struct Vector_1e06d0 {
    float x, y, z;
};
}
namespace fn_f75938cb {
class CSPManager_1e06d0 {
  public:
    void doIt(const char*, const char*, math::Vector_1e06d0);
};
class Function_1e06d0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSPManager_1e06d0*, void*, void*);
};
extern "C" char DAT_00423418[];
} // namespace fn_f75938cb
class CSPManager;
namespace fn_f75938cb {
class Method4_1e0710 {
  public:
    hulk_intptr vtable;
    ScriptFunctionFields f;
    ScriptMemberFn mgr;
    Method4_1e0710(const char*, ScriptMemberFn);
};
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
} // namespace fn_f75938cb
namespace math {
struct Vector_1e07a0 {
    float x, y, z;
};
}
namespace fn_f75938cb {
struct CAmbientsManager_1e07a0 {
    void f(const char*, int, const math::Vector_1e07a0, const math::Vector_1e07a0);
};
struct Function_1e07a0 {
    virtual void v0();
    virtual void v1();
};
struct Vector_1e0880 {
    float x, y, z;
};
struct CSPManager_1e0880 {
    int dummy;
};
struct Arg_1e0880 {
    Vector_1e0880 v;
    float f;
};
extern "C" char DAT_00423438[];
class Method4_1e08c0 {
  public:
    hulk_intptr vtable;
    ScriptFunctionFields f;
    ScriptMemberFn field1c;
    Method4_1e08c0* Init(const char*, ScriptMemberFn);
};
struct Function_1e0950 {
    virtual void f0();
    virtual void f1();
};
void FUN_001e0970(const char*, const char*, const char*, int);
class Function_1e0a20 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_1e0aa0 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_1e0aa0::*MFn_1e0aa0)(unsigned char);
class Function_1e0aa0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" char DAT_00423468[];
class Method3_1e0ac0 {
  public:
    hulk_intptr x;
    ScriptFunctionFields f;
    ScriptMemberFn m1c;
    void Init_001d0480(const char*, int);
    Method3_1e0ac0* Run(const char*, ScriptMemberFn);
};
struct CSPManager_1e0b40 { void FUN_001e0b40(int, int, const char *); };
struct Function_1e0b40 { virtual void vfunc_0(); virtual void vfunc_1(); };
extern "C" char DAT_00423478[];
class Method3_1e0b60 {
  public:
    void Init_001d0480(const char*, int);
    hulk_intptr m0;
    ScriptFunctionFields f;
    ScriptMemberFn m1c;
    Method3_1e0b60(const char*, ScriptMemberFn);
};
struct CSPManager_1e0be0 {};
struct Function_1e0be0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CSPManager_1e0c80 {
  public:
    bool Invoke(const char*, float);
};
class Function_1e0c80 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSPManager_1e0c80*, Args*, bool*);
};
extern "C" char DAT_00423498[];
class Method4_1e0cb0 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;
    ScriptMemberFn fn;
    Method4_1e0cb0* FUN_001e0cb0(const char*, ScriptMemberFn);
};
struct Function_1e0d40 {
    virtual void f0();
    virtual void f1();
};
void FUN_001e0d60(const char*, const char*, const char*, int);
class CSPManager_1e0e00 {
  public:
    void* Get(const char*);
};
class Function_1e0e00 {
  public:
    virtual void v0();
    virtual void v1();
};
class CFEManager_1e0e90 {
  public:
    void Call(const char*, int);
};
class Function_1e0e90 {
  public:
    virtual void f0();
    virtual void f1();
};
extern "C" char DAT_004234c8[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
class Method6_1e0eb0 : public FUN_001d0480 {
  public:
    hulk_intptr vp;
    ScriptFunctionFields f;
    ScriptMemberFn m1c;
    Method6_1e0eb0(const char*, ScriptMemberFn);
};
struct Function_1e0f50 {
    virtual void f0();
    virtual void f1();
};
void FUN_001e0f70(const char*, const char*, const char*, int);
struct Record_1e0fc0 {
    int a, b, c, d;
    short e;
    short f;
};
struct Entry_1e1040 { unsigned int a,b,c; float priority; unsigned short d,e; };
extern void __cdecl FUN_001de140(Entry_1e1040*, int, int, Entry_1e1040);
struct S_1e1150 {
    int a, b, c, d;
    short e, f;
};
struct T_1e1150 {
    int a, b, c, d, e;
};
extern "C" void __cdecl FUN_001e1040(S_1e1150*, int, hulk_intptr, T_1e1150);
} // namespace fn_f75938cb
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned int);
#endif
namespace fn_f75938cb {
struct Elem_1e11d0 {
};
extern "C" unsigned char __cdecl query_001d04d0(const void*);
class Function_1e1320 {
  public:
    virtual void fn();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int x;
    Function_1e1320(void*, int);
};
class Method1_1e1320 : public Function_1e1320 {
  public:
    virtual void fn();
    Method1_1e1320(void* p, int v) : Function_1e1320(p, 1) {
        x = v;
        b = query_001d04d0(((const char*)&DAT_0048e100));
        a = query_001d04d0(((const char*)&DAT_0048e134));
    }
};
class Closure1_1e1320 : public Method1_1e1320 {
  public:
    virtual void fn();
    int y;
    Closure1_1e1320(void*, int, int);
};
class CActorManager_1e1390 {
  public:
    void invoke(const char*);
};
struct CSPManager_1e1400 { bool FUN_001e1400(const char*, int, int); };
struct CSPManager_1e1560 {};
class CSPManager_1e1600 {
  public:
    int Fn(const char*);
};
class Function_1e1600 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class CActorManager_1e16a0 {
  public:
    void Method(const char*, float);
};
struct Pair_1e16a0 {
    const char* s;
    float f;
};
struct Arg_1e1740 {
    const char* s;
    unsigned char b;
};
class Actor_1e1740 {
  public:
    void invoke(const char*, unsigned char);
};
class Function_1e17b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
struct CSPManager_1e1850 { int FUN_001e1850(int, const char *); };
struct CSPManager_1e1900 {
    int FUN_001e1900(const char *, const char *);
};
class CActorManager_1e19b0 {
  public:
    void Method(const char*, float);
};
struct Pair_1e19b0 {
    const char* s;
    float f;
};
class CActorManager_1e1a40 {
  public:
    void invoke(const char*);
};
class CSPManager_1e1ab0 {
  public:
    bool invoke(const char*, const char*, int, float, const char*);
};
class Function_1e1ab0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, void*, void*);
};
class CSPManager_1e1b50 {
  public:
    void Fn(int, float, float, float);
};
class Function_1e1b50 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
};
class Method4_1e1b50 : public Function_1e1b50 {
  public:
    char pad[24];
    void (CSPManager_1e1b50::*fn)(int, float, float, float);
    CSPManager_1e1b50* obj;
};
class CSPManager_1e1bd0 {
  public:
    void Fn(int, float, float, float, const char*);
};
struct Vector_1e1cf0 {
    float x, y, z;
    Vector_1e1cf0() {}
    Vector_1e1cf0(const Vector_1e1cf0& v) : x(v.x), y(v.y), z(v.z) {}
};
class CSPManager_1e1cf0 {
  public:
    Vector_1e1cf0 method(const char*);
};
class Function_1e1cf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(void*, const char**, Vector_1e1cf0*);
};
class CActorManager_1e1e70 {
  public:
    float Method(const char*);
};
typedef float (CActorManager_1e1e70::*Fn_1e1e70)(const char*);
class CSPManager_1e1ef0 {
  public:
    void Fn(const char*, int, float, float, float, float);
};
class CSPManager_1e2020 {
  public:
    void Act(const char*, const char*, float, float, float);
};
class Function_1e2020 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class CSPManager_1e2260 {
  public:
    bool invoke(float, float, float, float);
};
class Function_1e2260 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, float*, bool*);
};
class CActorManager_1e2320 {
  public:
    int act();
};
class Actor_1e23b0 {
  public:
    void fn(unsigned char);
};
struct CSPManager_1e2490 { void FUN_001e2490(float, float, float); };
struct Values { float a,b,c; };
struct CSPManager_1e2540 { };
struct CSPManager_1e25c0 {
    bool Invoke(const char*, float, float, int);
};
class Function_1e25c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(void*, void*, void*);
};
extern "C" unsigned char __cdecl lookup(const char*);
class Function_1e2610 {
  public:
    Function_1e2610(const char*, int) throw();
    virtual void action();
};
class Method1_1e2610 : public Function_1e2610 {
  public:
    unsigned char pad[12];
    unsigned char flag1;
    char p1[7];
    unsigned char flag2;
    char p2[3];
    const char* third;
    Method1_1e2610(const char* a, const char* c) throw() : Function_1e2610(a, 1) {
        third = c;
        flag2 = lookup(((char*)&DAT_0048e0f0));
        flag1 = lookup(((char*)&DAT_0048e0f0));
    }
    virtual void action();
};
class Closure1_1e2610 : public Method1_1e2610 {
  public:
    const char* second;
    Closure1_1e2610(const char* a, const char* b, const char* c) throw();
    virtual void action();
};
class CActorManager_1e2720 {
  public:
    void Method(const char*, float);
};
struct Pair_1e2720 {
    const char* s;
    float f;
};
class CSPManager_1e2790 {
  public:
    void Fn(int, float, float, float, float, int);
};
class Function_1e2790 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int, void*, int);
};
struct E_1e2800 {
    int a, b, c, d, e;
};
void Sift_001e1040(E_1e2800* base, hulk_intptr idx, hulk_intptr n, E_1e2800 v);
struct Item_1e28a0 {
    char pad[12];
    float value;
};
void swap_item_001e0fc0(Item_1e28a0*, Item_1e28a0*);
typedef unsigned int U_1e3200;
struct CSPManager_nv_1e3200 {
    U_1e3200 Fng_001dbfe0(U_1e3200);
};
struct C_1e3200 {
    U_1e3200 Fnh_001e2ed0(U_1e3200, U_1e3200, U_1e3200);
};
} // namespace fn_f75938cb
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f75938cb {
class CSPManager_1e35a0 {};
typedef bool (CSPManager_1e35a0::*Fn_1e35a0)(const char*, int, int);
class Registry_1e35a0 { public:
    void FUN_001e35a0(const char* a1, CSPManager_1e35a0* a2, Fn_1e35a0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1e35a0;
template<> class Closure3_1e35a0<CSPManager_1e35a0, bool, const char*, int, int> : public ScriptFunctionFields { public: virtual void v(); Fn_1e35a0 fn; CSPManager_1e35a0* owner; Closure3_1e35a0(CSPManager_1e35a0* o) { owner = o; } };
class Raw_1e35a0 { public: void FUN_001df750(const char*, Fn_1e35a0); };
} // namespace fn_f75938cb
namespace math {
class Vector_1e3790 { public: float x, y, z; };
}
namespace fn_f75938cb {
class CSPManager_1e3790 {};
typedef void (CSPManager_1e3790::*Fn_1e3790)(const char*, const char*, int, const char*, math::Vector_1e3790, math::Vector_1e3790);
class Registry_1e3790 { public:
    void FUN_001e3790(const char* a1, CSPManager_1e3790* a2, Fn_1e3790 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_1e3790;
template<> class Closure6_1e3790<CSPManager_1e3790, void, const char*, const char*, int, const char*, math::Vector_1e3790, math::Vector_1e3790> : public ScriptFunctionFields { public: virtual void v(); Fn_1e3790 fn; CSPManager_1e3790* owner; Closure6_1e3790(CSPManager_1e3790* o) { owner = o; } };
class Raw_1e3790 { public: void FUN_001dfae0(const char*, Fn_1e3790); };
class CSPManager_1e3930 {};
typedef bool (CSPManager_1e3930::*Fn_1e3930)(const char*, const char*, int, float, const char*);
class Registry_1e3930 { public:
    void FUN_001e3930(const char* a1, CSPManager_1e3930* a2, Fn_1e3930 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5_1e3930;
template<> class Closure5_1e3930<CSPManager_1e3930, bool, const char*, const char*, int, float, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_1e3930 fn; CSPManager_1e3930* owner; Closure5_1e3930(CSPManager_1e3930* o) { owner = o; } };
class Raw_1e3930 { public: void FUN_001dfe70(const char*, Fn_1e3930); };
class CSPManager_1e3990 {};
typedef void (CSPManager_1e3990::*Fn_1e3990)(int, float, float, float);
class Registry_1e3990 { public:
    void FUN_001e3990(const char* a1, CSPManager_1e3990* a2, Fn_1e3990 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_1e3990;
template<> class Closure4_1e3990<CSPManager_1e3990, void, int, float, float, float> : public ScriptFunctionFields { public: virtual void* Fnv_001e1b30(int); Fn_1e3990 fn; CSPManager_1e3990* owner; Closure4_1e3990(CSPManager_1e3990* o) { owner = o; } };
class Raw_1e3990 { public: void FUN_001dff70(const char*, Fn_1e3990); };
class CSPManager_1e39f0 {};
typedef void (CSPManager_1e39f0::*Fn_1e39f0)(int, float, float, float, const char*);
class Registry_1e39f0 { public:
    void FUN_001e39f0(const char* a1, CSPManager_1e39f0* a2, Fn_1e39f0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5_1e39f0;
template<> class Closure5_1e39f0<CSPManager_1e39f0, void, int, float, float, float, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_1e39f0 fn; CSPManager_1e39f0* owner; Closure5_1e39f0(CSPManager_1e39f0* o) { owner = o; } };
class Raw_1e39f0 { public: void FUN_001e0030(const char*, Fn_1e39f0); };
class CSPManager_1e3a50 {};
typedef void (CSPManager_1e3a50::*Fn_1e3a50)(const char*, bool, float);
class Registry_1e3a50 { public:
    void FUN_001e3a50(const char* a1, CSPManager_1e3a50* a2, Fn_1e3a50 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1e3a50;
template<> class Closure3_1e3a50<CSPManager_1e3a50, void, const char*, bool, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1e3a50 fn; CSPManager_1e3a50* owner; Closure3_1e3a50(CSPManager_1e3a50* o) { owner = o; } };
class Raw_1e3a50 { public: void FUN_001e0130(const char*, Fn_1e3a50); };
class CSPManager_1e3ba0 {};
typedef void (CSPManager_1e3ba0::*Fn_1e3ba0)(const char*, int, float, float, float, float);
class Registry_1e3ba0 { public:
    void FUN_001e3ba0(const char* a1, CSPManager_1e3ba0* a2, Fn_1e3ba0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_1e3ba0;
template<> class Closure6_1e3ba0<CSPManager_1e3ba0, void, const char*, int, float, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1e3ba0 fn; CSPManager_1e3ba0* owner; Closure6_1e3ba0(CSPManager_1e3ba0* o) { owner = o; } };
class Raw_1e3ba0 { public: void FUN_001e03c0(const char*, Fn_1e3ba0); };
class CSPManager_1e3c50 {};
typedef void (CSPManager_1e3c50::*Fn_1e3c50)(const char*, const char*, float, float, float);
class Registry_1e3c50 { public:
    void FUN_001e3c50(const char* a1, CSPManager_1e3c50* a2, Fn_1e3c50 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5_1e3c50;
template<> class Closure5_1e3c50<CSPManager_1e3c50, void, const char*, const char*, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_1e3c50 fn; CSPManager_1e3c50* owner; Closure5_1e3c50(CSPManager_1e3c50* o) { owner = o; } };
class Raw_1e3c50 { public: void FUN_001e0550(const char*, Fn_1e3c50); };
} // namespace fn_f75938cb
namespace math {
class Vector_1e3cb0 { public: float x, y, z; };
}
namespace fn_f75938cb {
class CSPManager_1e3cb0 {};
typedef void (CSPManager_1e3cb0::*Fn_1e3cb0)(const char*, const char*, math::Vector_1e3cb0);
class Registry_1e3cb0 { public:
    void FUN_001e3cb0(const char* a1, CSPManager_1e3cb0* a2, Fn_1e3cb0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1e3cb0;
template<> class Closure3_1e3cb0<CSPManager_1e3cb0, void, const char*, const char*, math::Vector_1e3cb0> : public ScriptFunctionFields { public: virtual void v(); Fn_1e3cb0 fn; CSPManager_1e3cb0* owner; Closure3_1e3cb0(CSPManager_1e3cb0* o) { owner = o; } };
class Raw_1e3cb0 { public: void FUN_001e0650(const char*, Fn_1e3cb0); };
} // namespace fn_f75938cb
namespace math {
class Vector_1e3d10 { public: float x, y, z; };
}
namespace fn_f75938cb {
class CSPManager_1e3d10 {};
typedef void (CSPManager_1e3d10::*Fn_1e3d10)(const char*, const char*, math::Vector_1e3d10, math::Vector_1e3d10);
class Registry_1e3d10 { public:
    void FUN_001e3d10(const char* a1, CSPManager_1e3d10* a2, Fn_1e3d10 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_1e3d10;
template<> class Closure4_1e3d10<CSPManager_1e3d10, void, const char*, const char*, math::Vector_1e3d10, math::Vector_1e3d10> : public ScriptFunctionFields { public: virtual void v(); Fn_1e3d10 fn; CSPManager_1e3d10* owner; Closure4_1e3d10(CSPManager_1e3d10* o) { owner = o; } };
class Raw_1e3d10 { public: void FUN_001e0710(const char*, Fn_1e3d10); };
class CSPManager_1e3dc0 {};
typedef bool (CSPManager_1e3dc0::*Fn_1e3dc0)(float, float, float, float);
class Registry_1e3dc0 { public:
    void FUN_001e3dc0(const char* a1, CSPManager_1e3dc0* a2, Fn_1e3dc0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_1e3dc0;
template<> class Closure4_1e3dc0<CSPManager_1e3dc0, bool, float, float, float, float> : public ScriptFunctionFields { public: virtual void* Fnv_001e2240(int); Fn_1e3dc0 fn; CSPManager_1e3dc0* owner; Closure4_1e3dc0(CSPManager_1e3dc0* o) { owner = o; } };
class Raw_1e3dc0 { public: void FUN_001e08c0(const char*, Fn_1e3dc0); };
class CSPManager_1e3ee0 {};
typedef void (CSPManager_1e3ee0::*Fn_1e3ee0)(int, int, const char*);
class Registry_1e3ee0 { public:
    void FUN_001e3ee0(const char* a1, CSPManager_1e3ee0* a2, Fn_1e3ee0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1e3ee0;
template<> class Closure3_1e3ee0<CSPManager_1e3ee0, void, int, int, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_1e3ee0 fn; CSPManager_1e3ee0* owner; Closure3_1e3ee0(CSPManager_1e3ee0* o) { owner = o; } };
class Raw_1e3ee0 { public: void FUN_001e0ac0(const char*, Fn_1e3ee0); };
class CSPManager_1e3f40 {};
typedef void (CSPManager_1e3f40::*Fn_1e3f40)(float, float, float);
class Registry_1e3f40 { public:
    void FUN_001e3f40(const char* a1, CSPManager_1e3f40* a2, Fn_1e3f40 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1e3f40;
template<> class Closure3_1e3f40<CSPManager_1e3f40, void, float, float, float> : public ScriptFunctionFields { public: virtual void* Fnv_001e2470(int); Fn_1e3f40 fn; CSPManager_1e3f40* owner; Closure3_1e3f40(CSPManager_1e3f40* o) { owner = o; } };
class Raw_1e3f40 { public: void FUN_001e0b60(const char*, Fn_1e3f40); };
class CSPManager_1e3ff0 {};
typedef bool (CSPManager_1e3ff0::*Fn_1e3ff0)(const char*, float, float, int);
class Registry_1e3ff0 { public:
    void FUN_001e3ff0(const char* a1, CSPManager_1e3ff0* a2, Fn_1e3ff0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_1e3ff0;
template<> class Closure4_1e3ff0<CSPManager_1e3ff0, bool, const char*, float, float, int> : public ScriptFunctionFields { public: virtual void v(); Fn_1e3ff0 fn; CSPManager_1e3ff0* owner; Closure4_1e3ff0(CSPManager_1e3ff0* o) { owner = o; } };
class Raw_1e3ff0 { public: void FUN_001e0cb0(const char*, Fn_1e3ff0); };
class CSPManager_1e40f0 {};
typedef void (CSPManager_1e40f0::*Fn_1e40f0)(int, float, float, float, float, int);
class Registry_1e40f0 { public:
    void FUN_001e40f0(const char* a1, CSPManager_1e40f0* a2, Fn_1e40f0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_1e40f0;
template<> class Closure6_1e40f0<CSPManager_1e40f0, void, int, float, float, float, float, int> : public ScriptFunctionFields { public: virtual void* Fnv_001e2770(int); Fn_1e40f0 fn; CSPManager_1e40f0* owner; Closure6_1e40f0(CSPManager_1e40f0* o) { owner = o; } };
class Raw_1e40f0 { public: void FUN_001e0eb0(const char*, Fn_1e40f0); };
struct Item_1e4190 {
    char pad0[0xc];
    float key;
    char pad10[4];
};
void __cdecl FUN_001de1f0(Item_1e4190 *dest, Item_1e4190 *first, Item_1e4190 *last, int a, int b);
struct Elem20 { char data[20]; };
extern "C" void __cdecl FUN_001e28a0(void *, void *, void *);
struct Vec3_1e4310 { float x, y, z; };
struct Info_1e4310 { char pad[8]; Vec3_1e4310 pos; };
struct Key_1e4310 { unsigned lo, hi; };
struct Entry_1e4310 {
    unsigned lo, hi;
    char pad08[0x1a];
    short id;
    char pad24[4];
};
class CSPManager_1e4310 {
public:
    char pad0[0x608];
    Entry_1e4310 entries[0x800];
    int FUN_001dd330(const Key_1e4310 *key, const Vec3_1e4310 *pos, int a, int b, int c, int d, int flag);
    int FUN_001e2940(int id);
    int FUN_001e4310(Info_1e4310 *info, const Key_1e4310 *key, int unused, int a, int b, int c, int d);
};
struct Elem_1e4490 {
    char pad0[0xc];
    float key;
    char pad1[4];
};
struct ElemPair_1e4490 {
    Elem_1e4490* first;
    Elem_1e4490* second;
};
void FUN_001e4210(Elem_1e4490* a, Elem_1e4490* b, Elem_1e4490* c);
void FUN_001e0fc0(Elem_1e4490* a, Elem_1e4490* b);
class Obj_1e4760 {
  public:
    Obj_1e4760() throw();
    ~Obj_1e4760() throw();
};
struct CSPManager_nv_1e4760 {
    int Fn_001e4310(int, Obj_1e4760*, int, int, int, int, int);
};
struct Vec3_1e51b0 {
    float x, y, z;
};
struct Entity {
    char pad00[0x164];
    Vec3_1e51b0 pos;
    // equiv-conv: FUN_001d6990 ecx stack
    int FUN_001d6990(int extra);
};
char FUN_00202560(Vec3_1e51b0* p, float radius, int a, Vec3_1e51b0* hit, Vec3_1e51b0* normal, int b, int c, int d);
void* FUN_001d68e0(int count);
struct Frame_1e51b0 {
    float tmp;
    Vec3_1e51b0 p;
    Vec3_1e51b0 hit;
    Vec3_1e51b0 normal;
    Vec3_1e51b0 snapped;
    Vec3_1e51b0 corners[4];
};
struct Listener_1e51b0 {
    void FUN_001d7460(Entity* e);
};
class CSPManager_1e51b0 {
public:
    Vec3_1e51b0* FUN_001dcb00(Vec3_1e51b0* out, Vec3_1e51b0* in);
    Listener_1e51b0* FUN_001e4c40(void* p, Vec3_1e51b0* corners, int count, int a, int b, int c);

    // equiv-conv: FUN_001e51b0 ecx stack esi
    void FUN_001e51b0(Entity* e, int extra);
};
struct Id_1e54b0 {
    unsigned int lo, hi;
    void FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};
struct Vec3_1e54b0 {
    float x, y, z;
};
struct Transform_1e54b0 {
    char data[0x3c];
    void FUN_0022b980();
};
struct CSPManager_nv_1e54b0 {
    void FUN_001e43b0(Id_1e54b0 *a, Id_1e54b0 *b, Transform_1e54b0 *xf, int flag);
};
struct Handle_1e5540 {
 char data[8];
 Handle_1e5540* FUN_0027b0e0(void*);
 void FUN_0027af50();
};
struct CSPManager_1e5540 {
 void FUN_001e43b0(Handle_1e5540*,Handle_1e5540*,Matrix*,int);
 void target(void* a,void* b,Vector position,float x,float y,float z);
};
struct Item_1e55f0 { char data[20]; };
struct Partition { Item_1e55f0* first; Item_1e55f0* second; };
void __cdecl FUN_001e4490(Partition*, Item_1e55f0*, Item_1e55f0*);
extern "C" void __cdecl FUN_001e4190(void *, void *);
void __cdecl FUN_001e2800(Item_1e55f0*, Item_1e55f0*, int, int);
extern "C++" __declspec(nothrow) void __cdecl FUN_001e46d0(void *, void *);
class Thing_1e5720 {
  public:
    char pad0[0x14c];
    char f14c;
    char f14d;
    char f14e;
    void Init_001d7ff0();
    void Set_001d6290(int);
};
class Manager_1e5720 {
  public:
    char pad[0x4c];
    void FnA_0007bac0(void*);
};
class CSPManager_1e5720 {
  public:
    char pad[0x1e830];
    struct Sub {
        char pad[0x4c];
        Manager_1e5720* m;
    }* mgr;
    // equiv-conv: FUN_001e51b0 ecx stack esi
    void Notify_001e51b0(Thing_1e5720*, int);
    void Run(Thing_1e5720*);
};
class CSPManager_1e57a0 {
  public:
    char pad[0x1ec40];
    int values[4];
    int count;
    void ClearOne_001e53d0(int);
    void Finish_001df290();
    void Cleanup();
};
struct Vec3_1e57e0 {
    float x, y, z;
    Vec3_1e57e0(float a, float b, float c) : x(a), y(b), z(c) {}
};
class CSPManager_1e57e0 {
public:
    void FUN_001e5540(int a, int b, Vec3_1e57e0 pos, Vec3_1e57e0 offset);
    void FUN_001e57e0(int a, int b, Vec3_1e57e0 pos);
};
struct V {
    float x, y, z;
    V() : x(0), y(0), z(0) {}
};
struct CSPManager_1e5860 {
    void inner_001e5540(int, int, V, V);
    void target(int a, int b, V v);
};
struct Vec3_1e58d0 { float x, y, z; };
struct CSPManager_1e58d0 {
    void FUN_001e5540(const char* a, const char* b, Vec3_1e58d0 v1, Vec3_1e58d0 v2);
    void FUN_001e58d0(const char* a, const char* b, Vec3_1e58d0 v1, Vec3_1e58d0 v2);
};
struct CSPManager_nv_1e5bb0 {
    void FUN_001e5720(int);
};



// 0x001e2940 FUN_001e2940 (1423 B): equivalent/0x001e2940.cpp [wrapped: conflict: DAT_004dd700; FUN_001c3d90; FUN_0027b020; Node (+2)]
// sym: ?F@Mgr_1e2940@fn_001e2940@@QAEPAUProp_1e2940@2@H@Z
namespace fn_001e2940 {
// STATUS: equivalent (tools/equiv.py level 3: 19661 inputs, branch coverage 87/88, incomplete)
// FUN_001e2940 @ 0x001e2940

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

class CSPHulkProp;

struct V3_1e2940 {
    float x, y, z;
};

struct Quat_1e2940 {
    float x, y, z, w;
    void FUN_0022b650(struct Mat4_1e2940 *m);
};

struct Mat4_1e2940 {
    float m[12];
    V3_1e2940 trans;
    float w;
    void FUN_0022b980();
};

struct Thing;

struct Factory_1e2940 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Thing *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, int a, int b);
};
struct Zone_1e2940 {
    Thing *FUN_00046400(int a, int b);
};
struct Holder44_1e2940 { Factory_1e2940 *FUN_00203d70(); Zone_1e2940 *FUN_00204d70(int idx); };
struct Holder28_1e2940 {
    Holder44_1e2940 *FUN_000862a0();
};
struct Manager_1e2940 { char pad0[0x54]; Holder28_1e2940 *holder; };

#define DAT_004dd700 (*(Manager_1e2940 * *)&::DAT_004dd700)


struct Camera { V3_1e2940 *FUN_001c39d0(); };
Camera *FUN_001c3d90();

struct Rec_1e2940;
struct Sub8_1e2940 {
    void FUN_0027b040(const char *name);
    void FUN_0027af70(void *other);
};

struct Ptr9c { char pad[0x38]; float f38; };
struct PtrA0 {
    void *FUN_002fc2d0();
    void FUN_002fc670(hulk_intptr v);
};
struct Link_1e2940 { int FUN_001d5c70(int index); Rec_1e2940 *FUN_001d56f0(int a); };
struct Holder11c { void FUN_001c5080(float a, float b); };

struct Event_1e2940;
struct Sub74_1e2940;

struct Prop_1e2940 {
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
    virtual void v16(int a, int b);
    char pad04[4];
    Sub8_1e2940 sub8;
    char pad09[0x40 - 9];
    int f40;
    char pad44[0x9c - 0x44];
    Ptr9c *p9c;
    PtrA0 *pa0;
    char pada4[0xec - 0xa4];
    Link_1e2940 *link;
    char padf0[0x11c - 0xf0];
    Holder11c *holder;
    char pad120[0x144 - 0x120];
    char b144;
    char pad145[0x14c - 0x145];
    char b14c;
    char b14d;
    char pad14e[0x1c4 - 0x14e];
    int f1c4;
    char pad1c8[0x1d8 - 0x1c8];
    char b1d8;
    void FUN_001d6650(void *a);
    void FUN_001d6aa0(int a);
    void FUN_001d7b80(int a, int b);
    void FUN_001d62b0(int a);
    void FUN_001d6c80(int a);
    int FUN_001d6990();
    void FUN_001d6b60(Mat4_1e2940 m, int flag);
    void FUN_001d63b0(int count);
    Event_1e2940 *FUN_001d72e0();
    void FUN_001d7e70();
    void FUN_001d7590();
    void FUN_001d7510();
    void FUN_001d6cc0(float v);
    void FUN_0027cb40(float f);
    void FUN_0027cd10(void *q);
};

struct Item_1e2940 {
    char pad[0x28];
    int a28;
    int a2c;
    char pad30[0x40 - 0x30];
    int lo;
    int hi;
};
struct Rec_1e2940 {
    char pad[0x44];
    int count;
    char *items;
};

struct Sub20_1e2940 {
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
};
struct Sub74_1e2940 {
    char pad[8];
    char sub8[1];
    char pad9[0x20 - 9];
    Sub20_1e2940 *s20;
    char pad24[0x68 - 0x24];
    char b68;
    char b69;
};
struct Sub70_1e2940 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a);
};
struct Event_1e2940 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    char pad04[0x70 - 4];
    Sub70_1e2940 *p70;
    Sub74_1e2940 *p74;
};

struct Obj1b {
    void FUN_001b4450(Prop_1e2940 *p, int z);
};
extern "C" void * __cdecl FUN_001b6580(void);

struct Node {
    int value;
    char pad[0xc];
    Node *next;
};

struct SrcPart {
    char pad0[6];
    short s16;
    void FUN_001db820(Quat_1e2940 *out);
};

struct Entry_1e2940 {
    char pad0[8];
    int a8;
    int ac;
    SrcPart src;
    Prop_1e2940 *obj;
    Node *list;
    unsigned short w20;
    short s22;
    short s24;
    char c26;
    char c27;
    const char *FUN_0027b010();
};

struct Slot_1e2940 {
    V3_1e2940 pos;
    char pad0c[4];
    unsigned short flags;
    short entry;
};

unsigned __int64 FUN_0027b020(const char *name) throw();

class Mgr_1e2940 {
public:
    char pad0[0x608];
    Entry_1e2940 entries[2048];
    Slot_1e2940 slots[2048];
    char pad1e608[0x18];
    Prop_1e2940 *objs[128];
    int objCount;
    Prop_1e2940 *FUN_001de4f0(Thing *t, Entry_1e2940 *e, int c, Mat4_1e2940 *m);
    char FUN_001dbec0(int a, int b);
    Prop_1e2940 *F(int idx);
};

Prop_1e2940 *Mgr_1e2940::F(int idx)
{
    Slot_1e2940 *slot = &slots[idx];
    Entry_1e2940 *ent = &entries[slot->entry];
    if (slot->flags & 1)
        return 0;
    slot->flags = slot->flags | 1;
    struct Frame {
        volatile union { char b; int w; } fromLookup;
        int pad[2];
        Quat_1e2940 q;
        Mat4_1e2940 M;
    } fr;
    fr.fromLookup.b = 0;
    Mat4_1e2940 &M = fr.M;
    M.FUN_0022b980();
    ent->src.FUN_001db820(&fr.q);
    fr.q.FUN_0022b650(&M);
    M.trans.x = slot->pos.x;
    M.trans.y = slot->pos.y;
    M.trans.z = slot->pos.z;
    Prop_1e2940 *prop = 0;
    content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
    Thing *found = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70()->f3(&caster, ent->a8, ent->ac);
    if (!found) {
        Zone_1e2940 *zone = DAT_004dd700->holder->FUN_000862a0()->FUN_00204d70(ent->src.s16);
        if (!zone) {
            slot->flags &= 0xfffe;
            return prop;
        }
        found = zone->FUN_00046400(ent->a8, ent->ac);
        fr.fromLookup.b = 1;
        if (!found) {
            slot->flags &= 0xfffe;
            return prop;
        }
    }
    prop = FUN_001de4f0(found, ent, ent->c26, &M);
    if (!prop) {
        slot->flags &= 0xfffe;
        return prop;
    }
    prop->v0();
    for (Node *n = ent->list; n; n = n->next) {
        if (n->value >= 0) {
            int s = entries[n->value].s22;
            if (!(slots[s].flags & 1))
                F(s);
        }
    }
    if (ent->list)
        prop->FUN_001d6650(ent->list);
    prop->FUN_001d6aa0(1);
    prop->FUN_001d7b80(0, 0);
    prop->FUN_001d62b0(fr.fromLookup.w);
    prop->FUN_001d6c80(slot->entry);
    int kind = prop->FUN_001d6990();
    if (kind == 8 || kind == 7 || kind == 12 || kind == 13)
        prop->f1c4 = DAT_004c6180;
    else
        prop->f1c4 = DAT_004c617c;
    prop->b144 = (slot->flags >> 13) & 1;
    if (!(slot->flags & 2)) {
        Camera *cam = FUN_001c3d90();
        V3_1e2940 *cp = cam->FUN_001c39d0();
        hulk_freg dx = cp->x - M.trans.x;
        hulk_freg dy = cp->y - M.trans.y;
        hulk_freg dz = cp->z - M.trans.z;
        hulk_freg d = dz * dz + dy * dy + dx * dx;
        if (d < 4900.0f) {
            prop->holder->FUN_001c5080((*(float*)&DAT_00421898), 0.0f);
        } else {
            prop->holder->FUN_001c5080((*(float*)&DAT_00421894), 0.0f);
            prop->holder->FUN_001c5080((*(float*)&DAT_00421898), (*(float*)&DAT_0042189c));
        }
    } else {
        prop->holder->FUN_001c5080((*(float*)&DAT_00421898), 0.0f);
    }
    prop->sub8.FUN_0027b040(ent->FUN_0027b010());
    prop->sub8.FUN_0027af70(ent);
    prop->FUN_001d6b60(M, 0);
    prop->v16(ent->c26, 1);
    prop->b1d8 = 0;
    if (slot->flags & 4)
        prop->FUN_001d63b0(ent->s24);
    else
        prop->FUN_001d63b0(prop->link->FUN_001d5c70(ent->c26));
    prop->b14c = (slot->flags >> 4) & 1;
    prop->b14d = (slot->flags >> 5) & 1;
    unsigned short fl = slot->flags;
    int mode = 0;
    if (fl & 0x40)
        mode = 1;
    if (fl & 0x80)
        mode += 2;
    if (mode == 0) {
        hulk_freg v = prop->p9c->f38;
        int i;
        for (i = 1; i < 4; i++) {
            if (v <= ((float*)&DAT_00423198)[i])
                break;
        }
        if (i < 4) {
            if (i == 3 || i == 1) {
                fl |= 0x40;
                slot->flags = fl;
            }
            if (i == 3 || i == 2)
                slot->flags |= 0x80;
        }
    }
    if (ent->w20) {
        prop->FUN_0027cb40((float)(int)ent->w20 * 0.01f);
        static unsigned __int64 effectHash = FUN_0027b020("Effect");
        Rec_1e2940 *rec = prop->link->FUN_001d56f0(prop->f40);
        for (int i = 0; i < rec->count; i++) {
            Item_1e2940 *it = (Item_1e2940 *)(rec->items + i * 0x58);
            if ((unsigned __int64)(unsigned int)it->lo == (effectHash & 0xffffffff) &&
                (unsigned int)it->hi == (unsigned int)(effectHash >> 32)) {
                if (FUN_001dbec0(it->a28, it->a2c))
                    prop->FUN_0027cd10(it);
            }
        }
    }
    if (prop->pa0) {
        void *r = prop->pa0->FUN_002fc2d0();
        prop->pa0->FUN_002fc670(2);
        if (prop->FUN_001d72e0()->p70)
            prop->FUN_001d72e0()->p70->v6(1);
        prop->pa0->FUN_002fc670((hulk_intptr)r);
    }
    prop->FUN_001d7e70();
    Event_1e2940 *ev = prop->FUN_001d72e0();
    if (ev && ev->p74) {
        ((Obj1b *)FUN_001b6580())->FUN_001b4450(prop, 0);
        Sub74_1e2940 *e74 = ev->p74;
        ((Sub8_1e2940 *)(e74->sub8 - 0))->FUN_0027af70(ent);
        e74 = ev->p74;
        if (e74->b68 || e74->b69)
            e74->s20->v10();
        ev->v7();
    }
    if (ent->c27) {
        prop->FUN_001d7590();
    } else {
        prop->FUN_001d7510();
        prop->FUN_001d6cc0(0.5f);
    }
    int cnt = objCount;
    if (cnt < 0x80) {
        prop->v0();
        if (objs[cnt])
            objs[cnt]->v1();
        objs[cnt] = prop;
        objCount++;
        prop->v0();
        if (ent->obj)
            ent->obj->v1();
        ent->obj = prop;
    } else {
        slot->flags &= 0xfffe;
    }
    prop->FUN_001d6aa0(0);
    prop->v1();
    return prop;
}
} // namespace fn_001e2940
#undef DAT_004dd700


} // namespace
