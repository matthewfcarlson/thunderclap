// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
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


// 0x001db770 FUN_001db770 (3 B): matches/0x001db770.cpp
// sym: ?Get@A_1db770@fn_f75938cb@@QAEPAV12@XZ
A_1db770* A_1db770::Get() {
    return this;
}


// 0x001db780 FUN_001db780 (146 B): equivalent/0x001db780.cpp
// sym: ?FUN_001db780@PackedRotation@fn_f75938cb@@QAEXPBUQuat_1db780@2@@Z @dd1a4de6e926 @w8638e66ea0ac
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_001db780 @ 0x001db780
void PackedRotation::FUN_001db780(const Quat_1db780 *q)
{
    Quat_1db780 a = *q;
    Quat_1db780 identity;
    identity.x = 0.0f;
    identity.y = 0.0f;
    identity.z = 0.0f;
    identity.w = 1.0f;
    ((owners::Vec4_22b560 *)&a)->FUN_0022b560((owners::Vec4_22b560 *)(const Quat_1db780 *)(&identity));
    x = (short)(__int64)(a.x * 32767.0f);
    y = (short)(__int64)(a.y * 32767.0f);
    z = (short)(__int64)(a.z * 32767.0f);
}


// 0x001db820 FUN_001db820 (176 B): equivalent/0x001db820.cpp
// sym: ?FUN_001db820@PackedQuaternion_1db820@fn_f75938cb@@QAEPAUQuaternion_1db820@2@PAU32@@Z @14f2f3b4f541 @w9c4d68097c7d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001db820 @ 0x001db820
Quaternion_1db820* PackedQuaternion_1db820::FUN_001db820(Quaternion_1db820* out) {
 const float scale = 3.0518509447574615478515625e-5f;
 double a = (double)x * scale;
 float b = (float)((double)y * scale);
 double c = (double)z * scale;
 float cf = (float)c;
 double remainder = 1.0f - ((c * cf + (double)b * b) + a * a);
 float w = remainder > 0.0f ? (float)sqrt(remainder) : 0.0f;
 out->x = (float)a;
 out->y = b;
 out->z = cf;
 out->w = w;
 return out;
}


// 0x001db9e0 FUN_001db9e0 (4 B): matches/0x001db9e0.cpp
// sym: ?Get@Obj_1db9e0@fn_f75938cb@@QAEHXZ
void Target() {
    Obj_1db9e0 o;
    o.Get();
}


// 0x001db9f0 FUN_001db9f0 (4 B): matches/0x001db9f0.cpp
// sym: ?Get@Obj_1db9f0@fn_f75938cb@@QAEHXZ
int Obj_1db9f0::Get() {
    return value;
}


// 0x001dba00 FUN_001dba00 (15 B): matches/0x001dba00.cpp
// sym: ?Get@X_1dba00@fn_f75938cb@@QAEPADH@Z
char* X_1dba00::Get(int index) {
    return value + (index * 16);
}


// 0x001dba40 FUN_001dba40 (10 B): matches/0x001dba40.cpp
// sym: _FUN_001dba40
// data: gValue_1dba40 = DAT_004c6170
extern "C" void __cdecl FUN_001dba40(int value) {
    DAT_004c6170 = value;
}


// 0x001dba50 FUN_001dba50 (10 B): matches/0x001dba50.cpp
// sym: _FUN_001dba50
// data: gValue_1dba50 = DAT_004c6174
extern "C" void FUN_001dba50(int* p) {
    (*(int**)&DAT_004c6174) = p;
}


// 0x001dba60 FUN_001dba60 (10 B): matches/0x001dba60.cpp
// sym: _FUN_001dba60
extern "C" void __cdecl FUN_001dba60(int x) {
    DAT_004c6178 = x;
}


// 0x001dba70 FUN_001dba70 (10 B): matches/0x001dba70.cpp
// sym: _FUN_001dba70
// data: g_value_1dba70 = DAT_004c617c
extern "C" void FUN_001dba70(int value) {
    DAT_004c617c = value;
}


// 0x001dba80 FUN_001dba80 (13 B): matches/0x001dba80.cpp
// sym: ?Set@Big_1dba80@fn_f75938cb@@QAEXE@Z
void Big_1dba80::Set(unsigned char x) {
    value = x;
}


// 0x001dba90 FUN_001dba90 (13 B): matches/0x001dba90.cpp
// sym: ?Set@Obj_1dba90@fn_f75938cb@@QAEXH@Z
void Obj_1dba90::Set(int v) {
    mValue = v;
}


// 0x001dbba0 FUN_001dbba0 (94 B): matches/0x001dbba0.cpp
// sym: ?FUN_001dbba0@fn_f75938cb@@YIXPAUState_1dbba0@1@@Z
void __fastcall FUN_001dbba0(State_1dbba0* s) {
    ((owners::Target_27b040 *)(((Init*)s)))->FUN_0027b040((hulk_uintptr)0);
    ((owners::Target_27b040 *)(((Init*)((char*)s + 8))))->FUN_0027b040((hulk_uintptr)0);
    float local[4];
    s->at1c = 0;
    local[0] = 0;
    local[1] = 0;
    local[2] = 0;
    local[3] = 1.0f;
    ((Setup_1dbba0*)((char*)s + 0x10))->Init_001db780(local);
    s->at18 = 0;
    s->at20 = 0;
    *((unsigned short*)((char*)s + 0x16)) = 0;
    *((unsigned char*)s + 0x26) = 0;
    *((unsigned short*)((char*)s + 0x24)) = 0;
    *((unsigned short*)((char*)s + 0x22)) = 0xffff;
    *((unsigned char*)s + 0x27) = 1;
}


// 0x001dbc40 FUN_001dbc40 (20 B): matches/0x001dbc40.cpp
// sym: ?target@X_1dbc40@fn_f75938cb@@QAEPAV12@XZ
// Same code shape as 0x00090450 (propagated; names are from that function)
X_1dbc40* X_1dbc40::target() {
    Fnf_0027af00();
    ((X_1dbc40*)((char*)this + 8))->Fnf_0027af00();
    return this;
}


// 0x001dbc60 FUN_001dbc60 (19 B): matches/0x001dbc60.cpp
// sym: ?f@C_1dbc60@fn_f75938cb@@QAEXXZ
// Same code shape as 0x00090470 (propagated; names are from that function)
void C_1dbc60::f() {
    ((S_1dbc60*)((char*)this + 8))->Fnh_0027af50();
    ((S_1dbc60*)this)->Fnh_0027af50();
}


// 0x001dbc90 FUN_001dbc90 (12 B): matches/0x001dbc90.cpp
// sym: ?Target@X_1dbc90@fn_f75938cb@@QAEPAU12@XZ
// Same code shape as 0x00034ad0 (propagated; names are from that function)
X_1dbc90* X_1dbc90::Target() {
    Call_0027af00();
    return this;
}

} // namespace fn_f75938cb

// 0x001dbcb0 FUN_001dbcb0 (111 B): matches/0x001dbcb0.cpp [wrapped: conflict: CSPManager]
// sym: ?Construct@CSPManager@fn_001dbcb0@@QAEXXZ
namespace fn_001dbcb0 {
extern "C" char DAT_003feefc[];
extern "C" char DAT_004231ac[];
struct Element_1dbcb0 {
    void Init_0027af50();
};
class CSPManager {
  public:
    void* vftable;
    void Construct();
};
void CSPManager::Construct() {
    char* p;
    int i;
    vftable = (void*)((hulk_intptr)DAT_004231ac);
    p = (char*)this + 0x1eee0;
    for (i = 0x10; i != 0; --i) {
        p -= 0x18;
        ((Element_1dbcb0*)p)->Init_0027af50();
    }
    p = (char*)this + 0x1ec40;
    for (i = 0x80; i != 0; --i) {
        p -= 8;
        ((Element_1dbcb0*)p)->Init_0027af50();
    }
    p = (char*)this + 0x14608;
    for (i = 0x800; i != 0; --i) {
        p -= 0x28;
        ((Element_1dbcb0*)(p + 8))->Init_0027af50();
        ((Element_1dbcb0*)p)->Init_0027af50();
    }
    vftable = (void*)((hulk_intptr)DAT_003feefc);
}
} // namespace fn_001dbcb0


// 0x001dbd20 CSPManager::vfunc_2 (6 B): matches/0x001dbd20.cpp
// sym: ?vfunc_2@CSPManager@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int CSPManager::vfunc_2() {
    return 1;
}


// 0x001dbd30 CSPManager::vfunc_3 (8 B): matches/0x001dbd30.cpp [wrapped: conflict: CDHGameObjectCreator; CSPManager]
// sym: ?vfunc_3@CSPManager@fn_001dbd30@@UAEPBDPAX@Z
namespace fn_001dbd30 {
// Same code shape as 0x00078c40 (propagated; names are from that function)
// data: gWaypoint = DAT_00422fbc

class CDHGameObjectCreator {
    char a[4];
};
class DataHandler {
  public:
    class ObjectCreator {
        char b[4];
    };
};
class CSPManager : public CDHGameObjectCreator, public DataHandler::ObjectCreator {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual const char* vfunc_3(void*);
};
const char* CSPManager::vfunc_3(void*) {
    return ((char*)&DAT_00422fbc);
}
} // namespace fn_001dbd30

namespace fn_f75938cb {

// 0x001dbd40 FUN_001dbd40 (11 B): matches/0x001dbd40.cpp
// sym: ?target@fn_f75938cb@@YIXPAVObj_1dbd40@1@@Z
void __fastcall target(Obj_1dbd40* self) {
    self->x = 0x32;
}


// 0x001dbd50 FUN_001dbd50 (84 B): matches/0x001dbd50.cpp
// sym: ?FUN_001dbd50@fn_f75938cb@@YAXPAX@Z
// data: vals = DAT_004c602c
void __cdecl FUN_001dbd50(void* /*this, unused: callers pass it (unb4)*/) {
    Loader_1dbd50* p = FUN_001d4c90();
    if (p) {
        p->Config_001d2ba0("constants", 1, 1);
        p->Type_001d2ba0("weaponTypes", 0, 1);
        const int* q = ((const int*)&DAT_004c602c);
        do {
            ((owners::Thing_1d1d50 *)p)->FUN_001d1d50((hulk_uintptr)(*q), (hulk_uintptr)(*q));
            ++q;
        } while ((hulk_intptr)q < ((hulk_intptr)DAT_004c6044));
        ((owners::Obj_1d19d0 *)p)->FUN_001d19d0(2);
    }
}

} // namespace fn_f75938cb

// 0x001dbe50 FUN_001dbe50 (3 B): matches/0x001dbe50.cpp [wrapped: conflict: CAgent]
// sym: ?vfunc_7@CAgent@fn_001dbe50@@UAEXH@Z
namespace fn_001dbe50 {
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
    virtual void vfunc_7(hulk_intptr a);
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};

void CAgent::vfunc_7(hulk_intptr a) {
    (void)a;
}
} // namespace fn_001dbe50

namespace fn_f75938cb {

// 0x001dbe60 FUN_001dbe60 (94 B): matches/0x001dbe60.cpp
// sym: ?run@CSPManager_1dbe60@fn_f75938cb@@QAEXXZ
void CSPManager_1dbe60::run() {
    int i = index + 1;
    if (i < 0x800) {
        short* p = &entries[i][0];
        do {
            if (*p == 0) {
                index = i;
                return;
            }
            ++i;
            p += 20;
        } while (i < 0x800);
    }
    i = 0;
    if (index < 0)
        return;
    short* p = &entries[0][0];
    do {
        if (*p == 0) {
            index = i;
            return;
        }
        ++i;
        p += 20;
    } while (i <= *(volatile int*)&index);
}


// 0x001dbec0 FUN_001dbec0 (287 B): equivalent/0x001dbec0.cpp
// sym: ?FUN_001dbec0@fn_f75938cb@@YG_N_K@Z @6c92d4422c60 @w7cb5aa6ea88f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dbec0 @ 0x001dbec0
bool __stdcall FUN_001dbec0(Key_1dbec0 key)
{
    if (!((*(unsigned int*)((char*)&DAT_004e2658 + 80)) & 1)) {
        (*(unsigned int*)((char*)&DAT_004e2658 + 80)) |= 1;
        ((Key_1dbec0*)&DAT_004e2658)[0] = FUN_0027afb0("agcfWaves");
        ((Key_1dbec0*)&DAT_004e2658)[1] = FUN_0027afb0("fire01");
        ((Key_1dbec0*)&DAT_004e2658)[2] = FUN_0027afb0("fire02");
        ((Key_1dbec0*)&DAT_004e2658)[3] = FUN_0027afb0("icyGas");
        ((Key_1dbec0*)&DAT_004e2658)[4] = FUN_0027afb0("roadFlare");
        ((Key_1dbec0*)&DAT_004e2658)[5] = FUN_0027afb0("smoke01");
        ((Key_1dbec0*)&DAT_004e2658)[6] = FUN_0027afb0("smoke02");
        ((Key_1dbec0*)&DAT_004e2658)[7] = FUN_0027afb0("spark02");
        ((Key_1dbec0*)&DAT_004e2658)[8] = FUN_0027afb0("waterGyserDamLeak");
        ((Key_1dbec0*)&DAT_004e2658)[9] = FUN_0027afb0("waterGyserPenstock");
    }
    for (int i = 0; i < 10; ++i) {
        if (((Key_1dbec0*)&DAT_004e2658)[i] == key) return true;
    }
    return false;
}

} // namespace fn_f75938cb

// 0x001dbfe0 FUN_001dbfe0 (64 B): matches/0x001dbfe0.cpp [wrapped: conflict: Key]
// sym: ?Find@CSPManager_1dbfe0@fn_001dbfe0@@QAEHH@Z
namespace fn_001dbfe0 {
struct Key {
    __int64 value;
    char pad[32];
};
extern "C++" __declspec(nothrow) __int64 __cdecl FUN_00096d80(int);
class CSPManager_1dbfe0 {
    char pad[0x608];
    Key entries[2048];

  public:
    int Find(int);
};
int CSPManager_1dbfe0::Find(int x) {
    __int64 key = FUN_00096d80(x);
    for (int i = 0; i < 2048; i++) {
        if (entries[i].value == key)
            return i;
    }
    return -1;
}
} // namespace fn_001dbfe0

namespace fn_f75938cb {

// 0x001dc070 FUN_001dc070 (51 B): equivalent/0x001dc070.cpp
// sym: ?FUN_001dc070@CSPManager_1dc070@fn_f75938cb@@QAEHPBUKey@2@@Z @27f19064a017 @w28ec4c80f09c
// STATUS: equivalent (tools/equiv.py level 3: 5999 inputs, branch coverage 6/6)
// FUN_001dc070 @ 0x001dc070
int CSPManager_1dc070::FUN_001dc070(const Key* key) { for (int i = 0; i < 0x800; ++i) { if (entries[i].first == key->first && entries[i].second == key->second) return i; } return -1; }

} // namespace fn_f75938cb

// 0x001dc0b0 FUN_001dc0b0 (32 B): matches/0x001dc0b0.cpp
// sym: ?FUN_001dc0b0@CGrabAction_1dc0b0@owners@@QAEHH@Z
hulk_intptr owners::CGrabAction_1dc0b0::FUN_001dc0b0(int index) {
    int r = 0;
    if (index < mCount) {
        if (index >= 0)
            r = *(int*)((char*)this + 0x1e620 + index * 4);
    }
    return r;
}


// 0x001dc0d0 FUN_001dc0d0 (33 B): matches/0x001dc0d0.cpp
// sym: ?FUN_001dc0d0@Obj_1dc0d0@owners@@QAEHH@Z
hulk_intptr owners::Obj_1dc0d0::FUN_001dc0d0(hulk_intptr i) {
    if (((int)i) >= 0 && ((int)i) < 0x800)
        return vals[((int)i)][0];
    return 0;
}


// 0x001dc100 FUN_001dc100 (101 B): equivalent/0x001dc100.cpp
// sym: ?FUN_001dc100@CSPManager@@QAEDH_N@Z @cbcf17d62d6f @wd45fb3cac823
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001dc100 @ 0x001dc100
char CSPManager::FUN_001dc100(int key, bool set) {
    int idx = ((CSPManager_nv_1dc100*)this)->FUN_001dbfe0(key);
    if (idx < 0)
        return 0;
    char* base = (char*)this;
    int link = *(short*)(base + idx * 40 + 0x62a);
    unsigned char* flags = (unsigned char*)(base + (link + 0x104e) * 20);
    if (set)
        *flags |= 2;
    else
        *flags &= 0xfd;
    return 1;
}

namespace fn_f75938cb {

// 0x001dc170 FUN_001dc170 (127 B): equivalent/0x001dc170.cpp
// sym: ?FUN_001dc170@SlotTable_1dc170@fn_f75938cb@@QAE_NPBUKeyRef@2@D@Z @dfcad9d3b8b6 @wee3de99a1736
// STATUS: equivalent (tools/equiv.py level 3: 950 inputs, branch coverage 9/10, incomplete)
// FUN_001dc170 @ 0x001dc170
// Looks up the entry for a key and sets or clears bit 1 of its slot; false when the key is unknown.
bool SlotTable_1dc170::FUN_001dc170(const KeyRef* ref, char set)
{
    int hi = ref->key.hi;
    int lo = ref->key.lo;
    for (int i = 0; i < 0x800; i++) {
        if (entries[i].key.lo == lo && entries[i].key.hi == hi) {
            Slot_1dc170* slot = &slots[entries[i].slot];
            if (set)
                slot->flags |= 2;
            else
                slot->flags &= 0xfd;
            return true;
        }
    }
    return false;
}

} // namespace fn_f75938cb

// 0x001dc1f0 FUN_001dc1f0 (63 B): matches/0x001dc1f0.cpp
// sym: ?FUN_001dc1f0@Obj_1dc1f0@owners@@QAE_NPAX@Z
bool owners::Obj_1dc1f0::FUN_001dc1f0(void* param) {
    if (param) {
        int i = ((CSPManager_nv_1dc1f0*)(((CSPManager*)this)))->FUN_001dc070((char*)param + 8);
        if (i >= 0) {
            int x = values[i * 20];
            return ((unsigned char*)this)[(x + 0x104e) * 20] >> 1 & 1;
        }
    }
    return false;
}

namespace fn_f75938cb {

// 0x001dc230 FUN_001dc230 (92 B): matches/0x001dc230.cpp
// sym: ?target@Obj_1dc230@fn_f75938cb@@QAE_NHH@Z
bool Obj_1dc230::target(int index, int mode) {
    bool result = false;
    if (index >= 0 && index < 0x800) {
        short n = indices[index].value;
        unsigned short* p = (unsigned short*)((char*)this + (n + 0x104e) * 0x14);
        unsigned short v = *p & 0xf3ff;
        if (mode == 1 || mode == 3)
            v |= 0x400;
        if (mode == 2 || mode == 3)
            v |= 0x800;
        *p = v;
        result = true;
    }
    return result;
}


// 0x001dc290 FUN_001dc290 (59 B): matches/0x001dc290.cpp
// sym: ?get@Obj_1dc290@fn_f75938cb@@QAEHH@Z
int Obj_1dc290::get(int index) {
    int result = -1;
    if (index >= 0) {
        Entry* e = (Entry*)((char*)this + 0x608 + index * 0x28);
        short state = *(short*)((char*)e + 0x22);
        if ((*(unsigned char*)((char*)this + (state + 0x104e) * 0x14) & 1) != 0) {
            int* p = (int*)((char*)e + 0x18);
            if (*p != 0)
                return *(int*)((char*)*(hulk_intptr*)p + 0x40);
        }
        result = *(signed char*)((char*)e + 0x26);
    }
    return result;
}


// 0x001dc2d0 FUN_001dc2d0 (124 B): equivalent/0x001dc2d0.cpp
// sym: ?FUN_001dc2d0@Mixer@fn_f75938cb@@QAEHHH@Z @3283cc160745 @w35d2862d16dd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dc2d0 @ 0x001dc2d0
int Mixer::FUN_001dc2d0(int index, int value) {
    if (index < 0) {
        return -1;
    }
    Voice_1dc2d0 *voice = &voices[index];
    Channel *channel = (Channel *)((char *)this + 0x14608) + voice->channel;
    if ((channel->flags & 1) && voice->player != 0) {
        voice->player->Play(value, 1);
        int handle = voice->player->tracker->FUN_001d5c70(value);
        if (handle > 0) {
            ((owners::C_1d63b0 *)(voice->player))->FUN_001d63b0(handle);
        }
    } else {
        voice->value = (unsigned char)value;
        voice->state = 0xfde8;
        channel->flags &= 0xfb;
    }
    return value;
}

} // namespace fn_f75938cb

// 0x001dc350 FUN_001dc350 (93 B): matches/0x001dc350.cpp
// sym: ?FUN_001dc350@CSPManager@@QAEHPAD@Z
int CSPManager::FUN_001dc350(char* s) {
    int result = -1;
    int idx = ((CSPManager_nv_1dc350*)this)->Find_001dbfe0(s);
    if (idx >= 0 && s != 0 && *s != 0) {
        char* entry = (char*)this + 0x608 + idx * 0x28;
        short v = *(short*)(entry + 0x22);
        if ((*((unsigned char*)this + (v + 0x104e) * 0x14) & 1) != 0 && *(int*)(entry + 0x18) != 0)
            result = *(int*)(*(hulk_intptr*)(entry + 0x18) + 0x40);
        else
            result = (int)*(signed char*)(entry + 0x26);
    }
    return result;
}

namespace fn_f75938cb {

// 0x001dc3b0 FUN_001dc3b0 (107 B): equivalent/0x001dc3b0.cpp
// sym: ?FUN_001dc3b0@Target_1dc3b0@fn_f75938cb@@QAEPAXH@Z @cdc591905a20 @w663e46a5c967
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dc3b0 @ 0x001dc3b0
void *Target_1dc3b0::FUN_001dc3b0(int idx)
{
    if ((DAT_004e26b8 & 1) == 0) {
        DAT_004e26b8 |= 1;
        (*(Vec3_1dc3b0*)&DAT_004e26ac).x = 3.4028234663852886e+38f;
        (*(Vec3_1dc3b0*)&DAT_004e26ac).y = 3.4028234663852886e+38f;
        (*(Vec3_1dc3b0*)&DAT_004e26ac).z = 3.4028234663852886e+38f;
    }
    if (idx < 0)
        return ((Vec3_1dc3b0*)&DAT_004e26ac);
    Entry_1dc3b0 *e = &entries[idx];
    Record_1dc3b0 *r = &records[e->recordIndex];
    if ((r->flags & 1) == 0)
        return r;
    Link_1dc3b0 *l = e->link;
    if (l == 0)
        return r;
    return l->FUN_001d6b40();
}


// 0x001dc420 FUN_001dc420 (114 B): equivalent/0x001dc420.cpp
// sym: ?FUN_001dc420@Table_1dc420@fn_f75938cb@@QAE_NHPAUVec3_1dc420@2@@Z @e601bb953f65 @w18ba40e1165e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001dc420 @ 0x001dc420
bool Table_1dc420::FUN_001dc420(int index, Vec3_1dc420 *pos)
{
    if (index < 0)
        return false;
    Slot_1dc420 *slot = &slots[index];
    Entry_1dc420 *e = &entries[slot->link];
    if ((e->flags & 1) && slot->target) {
        slot->target->FUN_001d7810(*pos);
        return true;
    }
    e->pos = *pos;
    return true;
}


// 0x001dc4a0 FUN_001dc4a0 (171 B): equivalent/0x001dc4a0.cpp
// sym: ?target@Owner_1dc4a0@fn_f75938cb@@QAEMH@Z @7d67f0044b96 @wd41956ccd304
// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 6/6)
// FUN_001dc4a0 @ 0x001dc4a0
hulk_freg Owner_1dc4a0::target(int id) { Vec_1dc4a0 out; Transform_1dc4a0 temp; int n=FUN_001dbfe0(id); if(n<0) return 0.0f; Entry_1dc4a0& e=entries[n]; Flag_1dc4a0* flags=(Flag_1dc4a0*)this; if((flags[e.index+0x104e].bits&1) && e.object) { ((owners::M_22c3b0 *)(e.object->query()))->FUN_0022c3b0((float *)(Vec_1dc4a0 *)(((Vec_1dc4a0*)&DAT_004c6194)), (float *)(Vec_1dc4a0 *)(&out)); } else { e.part.FUN_001db820(&temp); temp.FUN_0022b4d0(((Vec_1dc4a0*)&DAT_004c6194),&out); } return FUN_00224ea0(out.x,out.z)*57.2957763671875f; }


// 0x001dc550 FUN_001dc550 (272 B): equivalent/0x001dc550.cpp
// sym: ?target@CSPManager_1dc550@fn_f75938cb@@QAE_NHMMM@Z @db2948540898 @w9d01d2276474
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 6/6)
// FUN_001dc550 @ 0x001dc550
bool CSPManager_1dc550::target(int key,float x,float y,float z) {
 int index=FUN_001dbfe0(key);
 if(index<0) return false;
 Record_1dc550* record=&entries.records[index];
 if((status.flags[record->id].bits&1) && record->node) {
  Matrix transform;
  transform.FUN_0022b980();
  ((owners::Target_22be40 *)&transform)->FUN_0022be40((const int *)(const Matrix *)(record->node->FUN_001d6b40()));
  ((owners::Matrix_22bc20 *)&transform)->FUN_0022bc20(x*0.0174532924f, y*0.0174532924f, z*0.0174532924f);
  record->node->FUN_001d6b60(transform,0);
 } else {
  Vector angles;
  ((owners::Quaternion_22b220 *)&angles)->FUN_0022b220(x*0.0174532924f, y*0.0174532924f, z*0.0174532924f);
  record->rotation.FUN_001db780(&angles);
 }
 return true;
}


// 0x001dc660 FUN_001dc660 (191 B): equivalent/0x001dc660.cpp
// sym: ?target@CSPManager_1dc660@fn_f75938cb@@QAEPAUVec_1dc660@2@PAU32@H@Z @244cf684fda4 @w26385df4e3e0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dc660 @ 0x001dc660
Vec_1dc660* CSPManager_1dc660::target(Vec_1dc660* out, int id) {
 Vec_1dc660 value; value.x=0; value.y=0; value.z=0;
 int i=FUN_001dbfe0(id);
 if(i>=0) {
  Record_1dc660* rec=&entries.records[i];
  if ((flags[rec->index+0x104e].bits&1) && rec->handle) {
   Node* node=((Result_1dc660 *)((owners::C_1d72e0 *)(rec->handle))->FUN_001d72e0())->node;
   if(node) {
    node->update(0);
    node->transform->apply(node->data,&value,-1);
   } else {
    Vec_1dc660* p=rec->handle->FUN_001d77c0();
    value.x=p->x; value.y=p->y; value.z=p->z;
   }
  }
 }
 out->x=value.x; out->y=value.y; out->z=value.z;
 return out;
}


// 0x001dc720 FUN_001dc720 (225 B): equivalent/0x001dc720.cpp
// sym: ?FUN_001dc720@CSPManager_1dc720@fn_f75938cb@@QAE_NHUVec_1dc720@2@@Z @dfec6ee7ce96 @wb6d322ba4285
// STATUS: equivalent (tools/equiv.py level 3: 19998 inputs, branch coverage 10/10)
// FUN_001dc720 @ 0x001dc720
bool CSPManager_1dc720::FUN_001dc720(int id, Vec_1dc720 position) {
 int i = FUN_001dbfe0(id);
 if(i < 0) return false;
 Record_1dc720* r = &records[i];
 if(!(flags[r->index].bits & 1) || !r->object) return false;
 Motion_1dc720* motion = ((State_1dc720 *)((owners::C_1d72e0 *)(((CSPManager_nv_1dc720*)(r->object))))->FUN_001d72e0())->motion;
 if(motion) { motion->v6(0); motion->FUN_002f5a20(&position); }
 else { Vec_1dc720* destination = ((CSPManager_nv_1dc720*)(r->object))->FUN_001d77c0(); *destination = position; }
 Vec_1dc720 zero; zero.x=0.0f; zero.y=0.0f; zero.z=0.0f;
 if(!position.FUN_0022d2b0(&zero, 0.00001f)) ((CSPManager_nv_1dc720*)(r->object))->FUN_001d7510();
 return true;
}

} // namespace fn_f75938cb

// 0x001dc810 FUN_001dc810 (183 B): equivalent/0x001dc810.cpp [wrapped: conflict: Vector]
// sym: ?FUN_001dc810@CSPManager_1dc810@fn_001dc810@@QAEPAUVector@2@PAU32@I@Z @1f71db465913 @w2814cb8470d3
namespace fn_001dc810 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 8/8)
// FUN_001dc810 @ 0x001dc810

struct Vector { unsigned int x, y, z; };
struct Attached_1dc810 { char pad[0x188]; Vector position; };
struct Entry_1dc810 { char pad[0x18]; Attached_1dc810* attached; char unknown[6]; short index; char tail[4]; };
struct Position_1dc810 { Vector value; unsigned int unknown; unsigned int flags; };
struct CSPManager_1dc810 {
 char pad[0x608];
 Entry_1dc810 entries[2048];
 Position_1dc810 positions[1];
 int FUN_001dbfe0(unsigned int key);
 Vector* FUN_001dc810(Vector* output, unsigned int key);
};
Vector* CSPManager_1dc810::FUN_001dc810(Vector* output, unsigned int key) {
 int index = FUN_001dbfe0(key);
 if (index < 0) {
 output->x = 0x7f7fffff; output->y = 0x7f7fffff; output->z = 0x7f7fffff;
 return output;
 }
 if (!((*(unsigned int*)&DAT_004e26c8) & 1)) {
 (*(unsigned int*)&DAT_004e26c8) |= 1;
 DAT_004e26bc = 3.402823466e+38f;
 DAT_004e26c0 = 3.402823466e+38f;
 DAT_004e26c4 = 3.402823466e+38f;
 }
 Entry_1dc810& entry = entries[index];
 Position_1dc810& position = positions[entry.index];
 Vector* source = &position.value;
 if ((position.flags & 1) && entry.attached) source = &entry.attached->position;
 output->x = source->x;
 output->y = source->y;
 output->z = source->z;
 return output;
}
} // namespace fn_001dc810

namespace fn_f75938cb {

// 0x001dc8d0 FUN_001dc8d0 (99 B): matches/0x001dc8d0.cpp
// sym: ?Get@CSPManager_1dc8d0@fn_f75938cb@@QAEMH@Z
hulk_freg CSPManager_1dc8d0::Get(int key) {
    hulk_freg r = -1.0f;
    int i = Find_001dbfe0(key);
    if (i >= 0) {
        Slot_1dc8d0* s = &slots[i];
        short idx = *(short*)((char*)&s->p2);
        if ((((Rec_1dc8d0*)this)[idx + 0x104e].flags & 1) && s->e)
            return s->e->f;
        r = (hulk_freg)s->cnt;
    }
    return r;
}


// 0x001dc940 FUN_001dc940 (86 B): equivalent/0x001dc940.cpp
// sym: ?FUN_001dc940@CSPManager_1dc940@fn_f75938cb@@QAEHH@Z @71f85c9f019c @w08053edb7e6c
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 6/6)
// FUN_001dc940 @ 0x001dc940
int CSPManager_1dc940::FUN_001dc940(int key) { int index = FUN_001dbfe0(key); if (index < 0) return 0; Entry &entry = entries[index]; int id = entry.id; if ((((Flag*)this)[id + 0x104e].bits & 1) && entry.linked) return entry.linked->value; return entry.fallback; }


// 0x001dc9a0 FUN_001dc9a0 (91 B): matches/0x001dc9a0.cpp
// sym: ?Func@CSPManager_1dc9a0@fn_f75938cb@@QAEXHH@Z
void CSPManager_1dc9a0::Func(int key, int val) {
    int n = Find_001dbfe0(key);
    if (n >= 0) {
        Entry_1dc9a0* e = &entries[n];
        Flag_1dc9a0* f = (Flag_1dc9a0*)((char*)this + 0x14608 + e->index * 20);
        if ((f->bits & 1) && e->item) {
            ((owners::C_1d63b0 *)(e->item))->FUN_001d63b0(val);
            return;
        }
        e->value = (short)val;
        f->bits |= 4;
    }
}


// 0x001dca40 FUN_001dca40 (3 B): matches/0x001dca40.cpp
// sym: ?Fn@A_1dca40@fn_f75938cb@@QAEXHHH@Z
void A_1dca40::Fn(int a, int b, int c) {}

} // namespace fn_f75938cb

// 0x001dca50 FUN_001dca50 (49 B): matches/0x001dca50.cpp [wrapped: compile error C2264: 'FUN_0027b020' : error in function definition or declaration; function not called]
// sym: _FUN_001dca50
namespace fn_001dca50 {
typedef unsigned int u32_1dca50;
struct Pair_1dca50 {
    u32_1dca50 a, b;
};
Pair_1dca50 FUN_0027b020(u32_1dca50);
void FUN_002f2750(u32_1dca50, u32_1dca50);
void FUN_002f28d0(u32_1dca50, u32_1dca50, u32_1dca50, u32_1dca50, u32_1dca50);
extern "C" void FUN_001dca50(u32_1dca50 p1, u32_1dca50 p2, u32_1dca50 p3, u32_1dca50 p4, u32_1dca50 p5) {
    Pair_1dca50 q = FUN_0027b020(p1);
    FUN_002f2750(q.a, q.b);
    FUN_002f28d0(p1, p2, p3, p4, p5);
}
} // namespace fn_001dca50

namespace fn_f75938cb {

// 0x001dcab0 FUN_001dcab0 (1 B): matches/0x001dcab0.cpp
// sym: ?FUN_001dcab0@fn_f75938cb@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001dcab0(void* /*this, unused: callers pass it (unb4)*/) {}


// 0x001dcac0 FUN_001dcac0 (1 B): matches/0x001dcac0.cpp
// sym: ?FUN_001dcac0@fn_f75938cb@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001dcac0(void* /*this, unused: callers pass it (unb4)*/) {}


// 0x001dcb00 FUN_001dcb00 (452 B): equivalent/0x001dcb00.cpp
// sym: ?FUN_001dcb00@fn_f75938cb@@YGPAUV3_1dcb00@1@PAU21@PBU21@@Z @37d97f4572a4 @wcfc1b6c46eff
// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 24/25, incomplete)
// FUN_001dcb00 @ 0x001dcb00
// FUN_001dcb00 @ 0x001dcb00
// Nudges a half-unit box around a position in +-x / +-z steps until both corners test clear.
V3_1dcb00* __stdcall FUN_001dcb00(V3_1dcb00* out, const V3_1dcb00* in)
{
    Frame_1dcb00 f;
    float y1 = in->y + 1.0f;
    f.pos.x = in->x;
    f.pos.y = y1;
    f.pos.z = in->z;
    f.boxMin.x = in->x - 0.5f;
    f.boxMin.y = y1;
    f.boxMin.z = in->z - 0.5f;
    f.boxMax.x = in->x + 0.5f;
    f.boxMax.y = y1;
    f.boxMax.z = in->z + 0.5f;

    int i = 0;
    bool found = false;
    do {
        Holder_1dcb00* h = FUN_001c3d90();
        if (h->finder != 0 && h->finder->FUN_001c8060(&f.boxMin, 0) != 0) {
            h = FUN_001c3d90();
            if (h->finder != 0 && h->finder->FUN_001c8060(&f.boxMax, 0) != 0) {
                found = true;
                break;
            }
        }
        i++;
        switch (i % 9) {
        case 0:
        case 2:
            f.boxMin.z += 1.0f;
            f.boxMax.z += 1.0f;
            f.pos.z += 1.0f;
            break;
        case 1:
        case 7:
        case 8:
            f.boxMin.x -= 1.0f;
            f.boxMax.x -= 1.0f;
            f.pos.x -= 1.0f;
            break;
        case 3:
        case 4:
            f.boxMin.x += 1.0f;
            f.boxMax.x += 1.0f;
            f.pos.x += 1.0f;
            break;
        default:
            f.boxMin.z -= 1.0f;
            f.boxMax.z -= 1.0f;
            f.pos.z -= 1.0f;
            break;
        }
    } while (i <= 36);

    if (!found) {
        f.pos.x = in->x;
        f.pos.z = in->z;
    }
    out->x = f.pos.x;
    out->y = y1;
    out->z = f.pos.z;
    return out;
}


// 0x001dccf0 FUN_001dccf0 (61 B): matches/0x001dccf0.cpp
// sym: ?set@CSPManager_1dccf0@fn_f75938cb@@QAE_NHE@Z
bool CSPManager_1dccf0::set(int key, unsigned char value) {
    bool result = false;
    int index = find_001dbfe0(key);
    if (index >= 0) {
        volatile Entry* e = &entries[index];
        Item* p = e->item;
        if (p) {
            p->value = value;
            result = true;
        }
    }
    return result;
}


// 0x001dcd30 FUN_001dcd30 (185 B): equivalent/0x001dcd30.cpp
// sym: ?FUN_001dcd30@CSPManager_1dcd30@fn_f75938cb@@QAEXH@Z @d018daae9277 @w3cec96fb17ff
// STATUS: equivalent (tools/equiv.py level 3: 2546 inputs, branch coverage 18/18)
// FUN_001dcd30 @ 0x001dcd30
void CSPManager_1dcd30::FUN_001dcd30(int index) {
 if (index < 0 || index > 2048) return;
 if (count >= 64) {
  int removed = 0;
  for (int i = 0; i < 2048; ++i) {
   int slot = (int)((unsigned int)cursor + (unsigned int)i) % 2048;
   if (entries[slot].active != 0) {
    unsigned short flags = records[entries[slot].recordIndex].flags;
    if ((flags & 0x2000) && !(flags & 1)) {
     FUN_001e5bc0(slot);
     ++removed;
    }
   }
   if (removed >= 5) break;
  }
 }
 records[entries[index].recordIndex].flags |= 0x2000;
 ++count;
}


// 0x001dcdf0 FUN_001dcdf0 (259 B): equivalent/0x001dcdf0.cpp
// sym: ?FUN_001dcdf0@Object@fn_f75938cb@@QAE_NMMMM@Z @8796b5066a70 @wc591785869ad
// STATUS: equivalent (tools/equiv.py level 3: 795 inputs, branch coverage 16/16)
// FUN_001dcdf0 @ 0x001dcdf0
bool Object::FUN_001dcdf0(float x,float y,float z,float radius) {
 float minX=x-radius,minY=y-radius,minZ=z-radius;
 float maxX=x+radius,maxY=y+radius,maxZ=z+radius;
 for(int i=0;i<count;++i) {
  Vec3_1dcdf0 p=*entries[i]->FUN_001d6b40();
  if(p.x>minX && p.x<maxX && p.y>minY && p.y<maxY && p.z>minZ && p.z<maxZ) return true;
 }
 return false;
}


// 0x001dcf00 FUN_001dcf00 (67 B): equivalent/0x001dcf00.cpp
// sym: ?FUN_001dcf00@Wrapper@fn_f75938cb@@QAEXUTriple@2@I@Z @5280c2b8d7b0 @w4f59a888a0f2
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001dcf00 @ 0x001dcf00
void Wrapper::FUN_001dcf00(Triple value, unsigned int last)
{
    FUN_001dcdf0(value, last);
}

} // namespace fn_f75938cb

// 0x001dcf50 FUN_001dcf50 (7 B): matches/0x001dcf50.cpp [wrapped: conflict: CGrabAction]
// sym: @FUN_001dcf50@4
namespace fn_001dcf50 {
class CGrabAction {
    char pad[0x1e820];

  public:
    int value;
};
extern "C" int __fastcall FUN_001dcf50(CGrabAction* self) {
    return self->value;
}
} // namespace fn_001dcf50


// 0x001dcf60 FUN_001dcf60 (99 B): matches/0x001dcf60.cpp [wrapped: conflict: CGrabAction]
// sym: ?Set@CGrabAction@fn_001dcf60@@QAEXD@Z
namespace fn_001dcf60 {
struct Data_1dcf60 {
    char pad[0x74];
    hulk_intptr p;
};
class Obj_1dcf60 {
  public:
    Data_1dcf60* Get_001d72e0();
    char Check_001d6980();
};
class CGrabAction {
  public:
    char pad[0x1e620];
    Obj_1dcf60* items[128];
    int count;
    void Set(char value);
};
void CGrabAction::Set(char value) {
    int i = 0;
    while (i < count) {
        Obj_1dcf60* o = items[i];
        Data_1dcf60* d = o->Get_001d72e0();
        if (d && !o->Check_001d6980()) {
            d = o->Get_001d72e0();
            if (d->p)
                *((char*)d->p + 0x72) = value;
        }
        ++i;
    }
}
} // namespace fn_001dcf60


// 0x001dd030 FUN_001dd030 (94 B): matches/0x001dd030.cpp [wrapped: merged class would differ: Obj: field entries: Field(+0x1e840 Entry [128] entries) vs Field(+0x1e840 Entry [128] entries)]
// sym: ?Fn@Obj@fn_001dd030@@QAEXHHH@Z
namespace fn_001dd030 {
struct Entry {
    char pad[8];
};
class Obj {
    char pad[0x1e840];
    Entry entries[128];

  public:
    void Fn(int a, int b, int v);
};
void Obj::Fn(int a, int b, int v) {
    if (a < 4 && b < 32) {
        if (b == -1) {
            for (int i = 0; i < 32; i++)
                ((owners::Target_27b040 *)&(entries[a * 32 + i]))->FUN_0027b040((hulk_uintptr)v);
        } else
            ((owners::Target_27b040 *)&(entries[a * 32 + b]))->FUN_0027b040((hulk_uintptr)v);
    }
}
} // namespace fn_001dd030

namespace fn_f75938cb {

// 0x001dd090 FUN_001dd090 (128 B): equivalent/0x001dd090.cpp
// sym: ?FUN_001dd090@Registry_1dd090@fn_f75938cb@@QAEXHHH@Z @df135c55dbac @wa7d60f889532
// STATUS: equivalent (tools/equiv.py level 3: 630 inputs, branch coverage 8/8)
// FUN_001dd090 @ 0x001dd090
// 0x001dd090: push a three word value into the control block of every registered item
void Registry_1dd090::FUN_001dd090(int a, int b, int c)
{
    for (int i = 0; i < count; i++) {
        Item_1dd090* it = items[i];
        if (((Info_1dd090 *)((owners::C_1d72e0 *)it)->FUN_001d72e0()) != 0 && ((Info_1dd090 *)((owners::C_1d72e0 *)it)->FUN_001d72e0())->block != 0) {
            Block_1dd090* blk = ((Info_1dd090 *)((owners::C_1d72e0 *)it)->FUN_001d72e0())->block;
            blk->v0 = a;
            blk->v1 = b;
            blk->v2 = c;
            blk->flag = 1;
        }
    }
}


// 0x001dd110 FUN_001dd110 (122 B): equivalent/0x001dd110.cpp
// sym: ?FUN_001dd110@SlotTable_1dd110@fn_f75938cb@@QAE_NPBDM@Z @49b6e2936841 @w002f1b9b60b4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dd110 @ 0x001dd110
bool SlotTable_1dd110::FUN_001dd110(const char* name, float value) {
    unsigned __int64 key = FUN_0027b020(name);
    unsigned int lo = (unsigned int)key;
    unsigned int hi = (unsigned int)(key >> 32);
    for (int i = 0; i < 16; i++) {
        Slot_1dd110* s = &slots[i];
        if (s->keyLo == lo && s->keyHi == hi) {
            s->value = value;
            return true;
        }
        if ((s->keyLo | s->keyHi) == 0) {
            s->keyLo = lo;
            s->keyHi = hi;
            s->value = value;
            return true;
        }
    }
    return false;
}

} // namespace fn_f75938cb

// 0x001dd190 FUN_001dd190 (78 B): equivalent/0x001dd190.cpp [wrapped: conflict: Object]
// sym: ?FUN_001dd190@Object@fn_001dd190@@QAEMHH@Z @c5156f3c95b4 @w119c3a61390b
namespace fn_001dd190 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001dd190 @ 0x001dd190
struct Entry { int first; int second; float value; int unused; };
struct Object { char pad[0x1ec60]; Entry entries[16]; float FUN_001dd190(int first, int second); };
float Object::FUN_001dd190(int first, int second) {
    for (int i = 0; i < 16; ++i) {
        if (entries[i].first == first && entries[i].second == second)
            return entries[i].value;
    }
    return -1.0f;
}
} // namespace fn_001dd190


// 0x001dd1e0 FUN_001dd1e0 (216 B): equivalent/0x001dd1e0.cpp [wrapped: conflict: Object]
// sym: ?update@Object@fn_001dd1e0@@QAE_NPBDMIH@Z @8585d57b11ca @wbda485b3692f
namespace fn_001dd1e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001dd1e0 @ 0x001dd1e0
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

typedef unsigned __int64 KeyValue;
struct Key_1dd1e0 { unsigned low, high;  };
struct Entry_1dd1e0 { Key_1dd1e0 key; float value; unsigned mode; int priority; unsigned unused; };
struct Object { char padding[0x1ed60]; Entry_1dd1e0 entries[16]; bool update(const char* name, float value, unsigned mode, int priority); };
bool Object::update(const char* name, float value, unsigned mode, int priority) {
 if (priority < 0) priority = 255;
 KeyValue key = FUN_0027b020(name);
 for (int i=0; i<16; ++i) {
  Entry_1dd1e0& e = entries[i];
  if (e.key.low == (unsigned)key && e.key.high == (unsigned)(key >> 32)) {
   e.value = value; e.mode = mode; e.priority = priority; return true;
  }
  if ((e.key.low | e.key.high) == 0) {
   ((owners::Target_27b040 *)&(e.key))->FUN_0027b040((hulk_uintptr)name);
   e.mode = mode; e.priority = priority; e.value = value; return true;
  }
 }
 return false;
}
} // namespace fn_001dd1e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001dd2c0 FUN_001dd2c0 (84 B): matches/0x001dd2c0.cpp [wrapped: conflict: Node]
// sym: ?Target@Obj_1dd2c0@fn_001dd2c0@@QAEXPAVSearch_1dd2c0@2@H@Z
namespace fn_001dd2c0 {
class Node {
  public:
    int a[4];
    hulk_intptr next;
};
class Search_1dd2c0 {
  public:
};
class Worker_1dd2c0 {
  public:
    void Run_0027d4f0(int);
};
class Obj_1dd2c0 {
  public:
    char pad[0x608];
    void Target(Search_1dd2c0*, int);
};
void Obj_1dd2c0::Target(Search_1dd2c0* search, int value) {
    Node* p = ((Node *)((owners::C_1d6660 *)search)->FUN_001d6660());
    while (p) {
        char* rec = (char*)this + (p->a[0] * 0x28) + 0x608;
        short n = *(short*)(rec + 0x22);
        if (*(unsigned char*)((char*)this + (n + 0x104e) * 0x14) & 1) {
            Worker_1dd2c0* w = *(Worker_1dd2c0**)(rec + 0x18);
            w->Run_0027d4f0(value);
        }
        p = (Node*)p->next;
    }
}
} // namespace fn_001dd2c0


// 0x001dd320 FUN_001dd320 (3 B): matches/0x001dd320.cpp [wrapped: conflict: CAgent]
// sym: ?vfunc_7@CAgent@fn_001dd320@@UAEXH@Z
namespace fn_001dd320 {
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
} // namespace fn_001dd320

namespace fn_f75938cb {

// 0x001dd330 FUN_001dd330 (287 B): equivalent/0x001dd330.cpp
// sym: ?target@CSPManager_1dd330@fn_f75938cb@@QAEHPAX0PAUSource_1dd330@2@EEEE@Z @d6485bad1833 @w1f3a08e5c531
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001dd330 @ 0x001dd330
int CSPManager_1dd330::target(void* a,void* b,Source_1dd330* source,unsigned char mark,unsigned char notify,unsigned char flag,unsigned char enabled) {
 if(count>=2048) return -1;
 Item_1dd330* item=&items[nextItem]; Record_1dd330* record=&records[count];
 item->FUN_001dbba0();
 record->itemIndex=0xffff;
 record->x=0; record->y=0; record->z=0;
 record->distance=3.402823466e+38f; record->flags=0;
 item->state.recordIndex=(unsigned short)count;
 record->itemIndex=(unsigned short)nextItem;
 Temp_1dd330 temp; ((owners::Quat_22b370 *)&temp)->FUN_0022b370((const float *)(Source_1dd330 *)source);
 item->first.FUN_0027af70(a);
 item->state.FUN_001db780(&temp);
 item->state.active=0;
 item->second.FUN_0027af70(b);
 item->state.id=0xffff; item->state.inverted=(enabled==0);
 record->x=source->x; record->y=source->y; record->z=source->z;
 if(flag) record->bytes.low|=0x20; else record->bytes.low&=0xdf;
 int result=nextItem; ++count;
 FUN_001dbe60();
 if(mark) record->bytes.low|=2;
 if(notify) FUN_001dcd30(result);
 return result;
}

} // namespace fn_f75938cb

// 0x001dd450 FUN_001dd450 (24 B): matches/0x001dd450.cpp
// sym: ?FUN_001dd450@CSPManager@@QAEXPAX@Z
void CSPManager::FUN_001dd450(void* __p0) { A_1dd450 * arg = (A_1dd450 *)__p0;

    int x = ((owners::C_1d6c70 *)arg)->FUN_001d6c70();
    ((CSPManager_nv_1dd450*)this)->Fng_001e5bc0(x);
}

namespace fn_f75938cb {

// 0x001dd470 FUN_001dd470 (176 B): matches/0x001dd470.cpp
// sym: ?target@Manager_1dd470@fn_f75938cb@@QAE_NHPBUMatrix@2@I@Z
bool Manager_1dd470::target(int index, const Matrix* matrix, unsigned int option) {
    if (index < 0 || index >= 2048)
        return false;
    Entry_1dd470* entry = &entries[index];
    Position_1dd470* position = &positions[entry->stateIndex];
    if ((position->flags & 1) && entry->object) {
        ((CSPManager_nv_1dd470*)(entry->object))->FUN_001d6b60(*matrix, option);
        return true;
    }
    Rotation_1dd470 rotation;
    ((owners::Quat_22b370 *)&rotation)->FUN_0022b370((const float *)(const Matrix *)matrix);
    entry->state.FUN_001db780(&rotation);
    position->x = matrix->words[12];
    position->y = matrix->words[13];
    position->z = matrix->words[14];
    return true;
}


// 0x001dd520 FUN_001dd520 (171 B): equivalent/0x001dd520.cpp
// sym: ?target@Manager_1dd520@fn_f75938cb@@QAE_NHPAUMatrix@2@@Z @80fa192fa5fd @wdfebabb08c89
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dd520 @ 0x001dd520
bool Manager_1dd520::target(int index, Matrix* out) { if (index < 0 || index >= 2048) return false; Entry_1dd520* entry = &entries[index]; Type* type = &types[entry->type]; if ((type->flags & 1) && entry->object) { Matrix* source = entry->object->v15(); for (int i=0;i<16;++i) out->words[i]=source->words[i]; return true; } out->FUN_0022b980(); Rotation_1dd520 rotation; entry->orientation.FUN_001db820(&rotation); rotation.FUN_0022b650(out); out->words[12]=type->position[0]; out->words[13]=type->position[1]; out->words[14]=type->position[2]; return true; }


// 0x001dd5d0 FUN_001dd5d0 (134 B): equivalent/0x001dd5d0.cpp
// sym: ?GetPosition@Registry_1dd5d0@fn_f75938cb@@QAE_NPBUId_1dd5d0@2@PAUVec3_1dd5d0@2@@Z @caa2f18942be @wc5732720920a
// STATUS: equivalent (tools/equiv.py level 3: 1098 inputs, branch coverage 11/12, incomplete)
// FUN_001dd5d0 @ 0x001dd5d0
bool Registry_1dd5d0::GetPosition(const Id_1dd5d0 *key, Vec3_1dd5d0 *out)
{
    unsigned int lo = key->lo;
    unsigned int hi = key->hi;
    int i;
    for (i = 0; i < 0x800; i++) {
        if (entries[i].id.lo == lo && entries[i].id.hi == hi)
            break;
    }
    if (i == 0x800)
        return false;
    Entry_1dd5d0 *e = &entries[i];
    Slot_1dd5d0 *s = &slots[e->slot];
    const Vec3_1dd5d0 *src = &s->pos;
    if ((s->flags & 1) && e->anchor != 0)
        src = e->anchor->FUN_001d6b40();
    out->x = src->x;
    out->y = src->y;
    out->z = src->z;
    return true;
}

} // namespace fn_f75938cb

// 0x001dd660 FUN_001dd660 (334 B): equivalent/0x001dd660.cpp [wrapped: conflict: Matrix]
// sym: ?FUN_001dd660@Registry_1dd660@fn_001dd660@@QAE_NPAUKey_1dd660@2@PAUV3_1dd660@2@@Z @625163a26a30 @w4ea4139dd6e0
namespace fn_001dd660 {
// STATUS: equivalent (tools/equiv.py level 3: 706 inputs, branch coverage 13/14, incomplete)
// FUN_001dd660 @ 0x001dd660
struct V3_1dd660 { float x, y, z; };

struct Matrix {
    float r[12];
    V3_1dd660 pos;
    float w;
    void FUN_0022b980();
};

struct Quat_1dd660 {
    float x, y, z, w;
    void FUN_0022b650(Matrix *m);
};

struct CompressedQuaternion6 {
    short v[3];
    void FUN_001db820(Quat_1dd660 *out);
};

struct Bone_1dd660 {
    char pad0[0x30];
    V3_1dd660 pos;
    int pad3c;
};

struct BoneTable_1dd660 {
    char pad0[0x1c];
    Bone_1dd660 *bones;
};

class BoneSource_1dd660 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual BoneTable_1dd660 *v11();
};

class BoneIndexer { public:  };

class Skeleton {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual Matrix *v15();
    char pad04[0x9c - 4];
    BoneSource_1dd660 *source;
    char padA0[0xec - 0xa0];
    BoneIndexer *indexer;
};

struct Key_1dd660 { int lo; int hi; };

struct Entry_1dd660 {
    int keyLo;
    int keyHi;
    char pad8[8];
    CompressedQuaternion6 rot;
    char pad16[2];
    Skeleton *skel;
    char pad1c[6];
    short slot;
    char pad24[4];
};

struct Slot_1dd660 {
    V3_1dd660 pos;
    int pad0c;
    unsigned char flags;
    char pad11[3];
};

struct Frame_1dd660 {
    V3_1dd660 v;
    Quat_1dd660 q;
    Matrix m;
};

class Registry_1dd660 {
public:
    char pad0[0x608];
    Entry_1dd660 entries[0x800];
    Slot_1dd660 slots[1];
    bool FUN_001dd660(Key_1dd660 *key, V3_1dd660 *out);
};

bool Registry_1dd660::FUN_001dd660(Key_1dd660 *key, V3_1dd660 *out)
{
    int lo = key->lo;
    int hi = key->hi;
    int i;
    for (i = 0; i < 0x800; i++) {
        if (entries[i].keyLo == lo && entries[i].keyHi == hi)
            break;
    }
    if (i >= 0x800)
        return false;

    Entry_1dd660 *e = &entries[i];
    Slot_1dd660 *s = &slots[e->slot];
    Frame_1dd660 f;
    f.v.x = 0.0f;
    f.v.y = 0.75f;
    f.v.z = 0.0f;
    if ((s->flags & 1) && e->skel) {
        int bone = ((owners::C_1d4f30 *)(e->skel->indexer))->FUN_001d4f30();
        if (bone != 0xffff) {
            BoneTable_1dd660 *t = e->skel->source->v11();
            *out = t->bones[bone].pos;
            return true;
        }
        ((owners::Mat_22c2b0 *)(e->skel->v15()))->FUN_0022c2b0((float *)(V3_1dd660 *)(&f.v), (float *)(V3_1dd660 *)out);
        return true;
    }
    f.m.FUN_0022b980();
    e->rot.FUN_001db820(&f.q);
    f.q.FUN_0022b650(&f.m);
    f.m.pos = s->pos;
    ((owners::Mat_22c2b0 *)&(f.m))->FUN_0022c2b0((float *)(V3_1dd660 *)(&f.v), (float *)(V3_1dd660 *)out);
    return true;
}
} // namespace fn_001dd660

namespace fn_f75938cb {

// 0x001dd7b0 FUN_001dd7b0 (69 B): equivalent/0x001dd7b0.cpp
// sym: ?FUN_001dd7b0@Table@fn_f75938cb@@QAE_NPBUKey@2@@Z @bdec5271a609 @w0a3ac6614461
// STATUS: equivalent (tools/equiv.py level 3: 857 inputs, branch coverage 7/8, incomplete)
// FUN_001dd7b0 @ 0x001dd7b0
bool Table::FUN_001dd7b0(const Key *key) { for (int i = 0; i < 0x800; ++i) { if (entries[i].first == key->first && entries[i].second == key->second) return true; } return false; }


// 0x001dd800 FUN_001dd800 (50 B): matches/0x001dd800.cpp
// sym: ?target@Obj_1dd800@fn_f75938cb@@QAE_NH@Z
bool Obj_1dd800::target(int index) {
    if (index < 0 || index >= 0x800)
        return false;
    short v = rec[index].index;
    return *((unsigned char*)this + (v + 0x104e) * 0x14) & 1;
}


// 0x001dd840 FUN_001dd840 (76 B): matches/0x001dd840.cpp
// sym: ?Set@Obj_1dd840@fn_f75938cb@@QAEXHE@Z
void Obj_1dd840::Set(int n, unsigned char value) {
    if (n >= 0 && n < 0x800) {
        Entry* e = &entries[n];
        int i = e->index;
        if ((*(unsigned char*)((char*)this + (i + 0x104e) * 0x14) & 1) && e->p) {
            Result_1dd840* r = ((Result_1dd840 *)((owners::C_1d72e0 *)(e->p))->FUN_001d72e0());
            if (r && r->p)
                *((unsigned char*)r->p + 0x72) = value;
        }
    }
}

} // namespace fn_f75938cb

// 0x001dd890 FUN_001dd890 (79 B): equivalent/0x001dd890.cpp [wrapped: conflict: Flag]
// sym: ?FUN_001dd890@Owner@fn_001dd890@@QAEXHE@Z @e0b420a7241c @wafcd86079d0a
namespace fn_001dd890 {
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 10/10)
// FUN_001dd890 @ 0x001dd890
struct Node { char pad0[0x14c]; unsigned char enabled; };
struct Entry { char pad0[0x18]; Node* node; char pad1[6]; short slot; char pad2[4]; };
struct Flag { char pad[0x10]; unsigned char bits; char rest[3]; };
struct Owner { char pad0[0x608]; Entry entries[0x800]; Flag flags[1]; void FUN_001dd890(int index, unsigned char value); };
void Owner::FUN_001dd890(int index, unsigned char value) {
    if (index < 0 || index >= 0x800) return;
    Entry& entry = entries[index];
    Flag& flag = flags[entry.slot];
    if (value) flag.bits |= 0x10;
    else flag.bits &= 0xef;
    if ((flag.bits & 1) && entry.node) entry.node->enabled = value;
}
} // namespace fn_001dd890


// 0x001dd8e0 FUN_001dd8e0 (79 B): equivalent/0x001dd8e0.cpp [wrapped: conflict: Entry]
// sym: ?FUN_001dd8e0@Controller@fn_001dd8e0@@QAEXHE@Z @5765cb9252fa @wb5a9363cd1cc
namespace fn_001dd8e0 {
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 10/10)
// FUN_001dd8e0 @ 0x001dd8e0
struct LinkedObject { char pad[0x14d]; unsigned char enabled; };
struct Entry { char pad0[0x18]; LinkedObject* linked; char pad1[6]; short stateIndex; char pad2[4]; };
struct State { char pad[0x10]; unsigned char flags; char remainder[3]; };
struct Controller {
    char pad0[0x608];
    Entry entries[0x800];
    State states[1];
    void FUN_001dd8e0(int index, unsigned char enabled);
};
void Controller::FUN_001dd8e0(int index, unsigned char enabled) {
    if (index < 0 || index >= 0x800) return;
    Entry& entry = entries[index];
    State& state = states[entry.stateIndex];
    if (enabled) state.flags |= 0x20;
    else state.flags &= 0xdf;
    if ((state.flags & 1) && entry.linked)
        entry.linked->enabled = enabled;
}
} // namespace fn_001dd8e0

namespace fn_f75938cb {

// 0x001dd930 FUN_001dd930 (88 B): matches/0x001dd930.cpp
// sym: ?Run@Obj_1dd930@fn_f75938cb@@QAE_NHPAUHelper_1dd930@2@@Z
bool Obj_1dd930::Run(int index, Helper_1dd930* arg) {
    if (index < 0 || index >= 0x800)
        return false;
    Entry_1dd930* e = &entries[index];
    if ((((char*)this)[(e->index + 0x104e) * 0x14] & 1) && e->ptr != 0) {
        arg->Use_0027af70((void*)(e->ptr + 8));
        return true;
    }
    arg->Use_0027af70((void*)e);
    return true;
}


// 0x001dd9e0 FUN_001dd9e0 (78 B): matches/0x001dd9e0.cpp
// sym: ?Target@Obj_1dd9e0@fn_f75938cb@@QAEEH@Z
unsigned char Obj_1dd9e0::Target(int index) {
    if (index < 0 || index >= 0x800)
        return 0;
    Entry_1dd9e0* e = &entries[index];
    int i = e->index + 0x104e;
    if ((*(unsigned char*)((char*)this + i * 0x14) & 1) && e->node && e->node->next)
        return e->node->next->Check_00078b20();
    return 1;
}

} // namespace fn_f75938cb

// 0x001dda30 FUN_001dda30 (67 B): equivalent/0x001dda30.cpp [wrapped: conflict: Object]
// sym: ?FUN_001dda30@Object@fn_001dda30@@QAEEHE@Z @db8dc96945e4 @w81b69dad7d66
namespace fn_001dda30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001dda30 @ 0x001dda30
struct Entry { char pad[17]; unsigned char flags; char rest[2]; };
struct Mapping { short entry; char rest[38]; };
struct Object { char pad[0x62a]; union { Mapping mappings[0x800]; struct { char gap[0x14608-0x62a]; Entry entries[1]; } table; } fields; unsigned char FUN_001dda30(int index, unsigned char enabled); };
unsigned char Object::FUN_001dda30(int index, unsigned char enabled) {
    if (index < 0 || index >= 0x800) return 0;
    Entry &entry = fields.table.entries[fields.mappings[index].entry];
    if (enabled) entry.flags |= 0x10;
    else entry.flags &= 0xef;
    return 1;
}
} // namespace fn_001dda30

namespace fn_f75938cb {

// 0x001dda80 FUN_001dda80 (53 B): matches/0x001dda80.cpp
// sym: ?check@CSPManager_1dda80@fn_f75938cb@@QAEEH@Z
unsigned char CSPManager_1dda80::check(int index) {
    if (index < 0 || index >= 0x800)
        return 0;
    short n = *(short*)((char*)this + 0x62a + index * 40);
    return ((Bits*)((char*)this + (n + 0x104e) * 20))->b;
}


// 0x001ddb30 FUN_001ddb30 (70 B): matches/0x001ddb30.cpp
// sym: ?Set@CSPManager_1ddb30@fn_f75938cb@@QAEXHE@Z
void CSPManager_1ddb30::Set(int id, unsigned char v) {
    int i = Find_001dbfe0(id);
    if (i >= 0) {
        Entry* e = &entries[i];
        if (((Record*)this)[(short)e->x + 0x104e].flags & 1) {
            Obj* o = (Obj*)e->obj;
            if (o)
                o->flag = v;
        }
    }
}


// 0x001ddb80 FUN_001ddb80 (70 B): matches/0x001ddb80.cpp
// sym: ?Set@CSPManager_1ddb80@fn_f75938cb@@QAEXHE@Z
void CSPManager_1ddb80::Set(int id, unsigned char v) {
    int i = Find_001dbfe0(id);
    if (i >= 0) {
        Entry* e = &entries[i];
        int j = e->n + 0x104e;
        if (((char*)this)[j * 20] & 1) {
            char* p = e->p;
            if (p)
                p[0x1a1] = v;
        }
    }
}

} // namespace fn_f75938cb

// 0x001ddbd0 FUN_001ddbd0 (70 B): matches/0x001ddbd0.cpp [wrapped: merged class would differ: CSPManager_1ddbd0: field items: Field(+0x608 Item [1] items) vs Field(+0x608 Item [1] items)]
// sym: ?Run@CSPManager_1ddbd0@fn_001ddbd0@@QAEXHH@Z
namespace fn_001ddbd0 {
struct Obj {
};
struct Item {
    char pad[0x18];
    Obj* obj;
    char gap[6];
    short a;
    char tail[4];
};
class CSPManager_1ddbd0 {
  public:
    int Find_001dbfe0(int);
    void Run(int, int);
    char pad[0x608];
    Item items[1];
};
void CSPManager_1ddbd0::Run(int id, int v) {
    int n = Find_001dbfe0(id);
    if (n >= 0) {
        Item* p = &items[n];
        int k = p->a + 0x104e;
        if (((char*)this)[k * 20] & 1) {
            Obj* o = p->obj;
            if (o)
                ((owners::C_1d6cc0 *)o)->FUN_001d6cc0(v);
        }
    }
}
} // namespace fn_001ddbd0

namespace fn_f75938cb {

// 0x001ddc20 FUN_001ddc20 (155 B): matches/0x001ddc20.cpp
// sym: ?FUN_001ddc20@CSPManager_1ddc20@fn_f75938cb@@QAEXHPBD@Z
// FUN_001ddc20 @ 0x001ddc20
// FUN_001ddc20: set a mode on the object of a keyed slot from the first letter of a string
void CSPManager_1ddc20::FUN_001ddc20(int key, const char *name)
{
    int i = FUN_001dbfe0(key);
    if (i < 0)
        return;
    Entry_1ddc20 *e = &entries[i];
    if (!(slots[e->slot].flags & 1))
        return;
    if (e->obj == 0)
        return;
    int mode = 0;
    if (name != 0) {
        switch (FUN_00345475(*name)) {
        case 'b':
            mode = 2;
            break;
        case 'e':
            mode = 3;
            break;
        case 'g':
            mode = 1;
            break;
        }
    }
    e->obj->mode = mode;
}


// 0x001ddcc0 FUN_001ddcc0 (116 B): equivalent/0x001ddcc0.cpp
// sym: ?FUN_001ddcc0@CSPManager_1ddcc0@fn_f75938cb@@QAEPBDH@Z @3aa3359fd11f @w25678454c90b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001ddcc0 @ 0x001ddcc0
const char *CSPManager_1ddcc0::FUN_001ddcc0(int key)
{
    int idx = FUN_001dbfe0(key);
    if (idx < 0)
        return 0;
    Slot_1ddcc0 *s = &slots[idx];
    if ((pools[s->id].flags & 1) == 0)
        return 0;
    if (s->brain == 0)
        return 0;
    switch (s->brain->kind) {
    case 0:
        return "Neutral";
    case 1:
        return "Good";
    case 2:
        return "Bad";
    case 3:
        return "Evil";
    }
    return 0;
}

} // namespace fn_f75938cb

// 0x001ddd50 FUN_001ddd50 (70 B): matches/0x001ddd50.cpp [wrapped: merged class would differ: CSPManager_1ddd50: field items: Field(+0x608 Item [1] items) vs Field(+0x608 Item [1] items)]
// sym: ?Set@CSPManager_1ddd50@fn_001ddd50@@QAEXHH@Z
namespace fn_001ddd50 {
struct Obj {
    char pad[0x19c];
    int value;
};
struct Item {
    char pad[0x18];
    Obj* obj;
    char tail[0x22 - 0x1c];
    short index;
    char end[4];
};
class CSPManager_1ddd50 {
  public:
    char pad[0x608];
    Item items[1];
    int Find_001dbfe0(int);
    void Set(int, int);
};
void CSPManager_1ddd50::Set(int key, int value) {
    int i = Find_001dbfe0(key);
    if (i >= 0) {
        Item* p = &items[i];
        int n = p->index + 0x104e;
        if (((char*)this)[n * 20] & 1) {
            Obj* o = p->obj;
            if (o)
                o->value = value;
        }
    }
}
} // namespace fn_001ddd50


// 0x001ddda0 FUN_001ddda0 (76 B): matches/0x001ddda0.cpp [wrapped: merged class would differ: CSPManager_1ddda0: field items: Field(+0x608 Item [1] items) vs Field(+0x608 Item [1] items)]
// sym: ?get@CSPManager_1ddda0@fn_001ddda0@@QAEMH@Z
namespace fn_001ddda0 {
struct Obj {
    char pad[0x19c];
    float val;
};
struct Item {
    char pad[0x18];
    Obj* ptr;
    char gap[6];
    short index;
    char rest[4];
};
class CSPManager_1ddda0 {
  public:
    char flags[0x608];
    Item items[1];
    float get(int x);
    int find_001dbfe0(int);
};
float CSPManager_1ddda0::get(int x) {
    int i = find_001dbfe0(x);
    if (i >= 0) {
        Item* p = &items[i];
        int n = p->index + 0x104e;
        if (flags[n * 20] & 1) {
            Obj* o = p->ptr;
            if (o)
                return o->val;
        }
    }
    return 0.0f;
}
} // namespace fn_001ddda0

namespace fn_f75938cb {

// 0x001dddf0 FUN_001dddf0 (7 B): matches/0x001dddf0.cpp
// sym: ?FUN_001dddf0@fn_f75938cb@@YIMPAVTarget_1dddf0@1@@Z
float __fastcall FUN_001dddf0(Target_1dddf0* self) {
    return self->value;
}


// 0x001dde00 FUN_001dde00 (13 B): matches/0x001dde00.cpp
// sym: ?Set@Obj_1dde00@fn_f75938cb@@QAEXH@Z
void Obj_1dde00::Set(int x) {
    value = x;
}


// 0x001dde20 FUN_001dde20 (13 B): matches/0x001dde20.cpp
// sym: ?Set@Target_1dde20@fn_f75938cb@@QAEXH@Z
void Target_1dde20::Set(int value) {
    m1eee4 = value;
}


// 0x001dde30 FUN_001dde30 (3 B): matches/0x001dde30.cpp
// sym: _FUN_001dde30@4
extern "C" void __stdcall FUN_001dde30(int x) {
    return;
}


// 0x001dde50 FUN_001dde50 (5 B): matches/0x001dde50.cpp
// sym: _FUN_001dde50@12
extern "C" char __stdcall FUN_001dde50(int a, int b, int c) {
    return 0;
}

// 0x001ddfc0 thunk_FUN_001d04a0 (5 B): not yet verified
// 0x001de000 thunk_FUN_001d04a0 (5 B): not yet verified

// 0x001de140 FUN_001de140 (168 B): matches/0x001de140.cpp
// sym: ?FUN_001de140@fn_f75938cb@@YAPAUEntry_1de140@1@PAU21@HHU21@@Z
Entry_1de140* __cdecl FUN_001de140(Entry_1de140* entries, int index, int limit, Entry_1de140 value) {
    int parent = (index - 1) / 2;
    while (limit < index) {
        if (!(entries[parent].priority < value.priority))
            break;
        entries[index].a = entries[parent].a;
        entries[index].b = entries[parent].b;
        entries[index].c = entries[parent].c;
        entries[index].priority = entries[parent].priority;
        entries[index].d = entries[parent].d;
        entries[index].e = entries[parent].e;
        index = parent;
        parent = (parent - 1) / 2;
    }
    entries[index].a = value.a;
    entries[index].b = value.b;
    entries[index].c = value.c;
    entries[index].priority = value.priority;
    entries[index].d = value.d;
    entries[index].e = value.e;
    return &entries[index];
}


// 0x001de1f0 FUN_001de1f0 (331 B): equivalent/0x001de1f0.cpp
// sym: ?FUN_001de1f0@fn_f75938cb@@YAXPAUElem_1de1f0@1@00@Z @190181649f14 @wa02779a5c54b
// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 17/18, incomplete)
// FUN_001de1f0 @ 0x001de1f0
// std::rotate(first, middle, last) for 20-byte elements (gcd-cycle algorithm).
void __cdecl FUN_001de1f0(Elem_1de1f0 *first, Elem_1de1f0 *middle, Elem_1de1f0 *last)
{
    int shift = (int)((char *)middle - (char *)first) / 20;
    int total = (int)((char *)last - (char *)first) / 20;
    int count = total;
    for (int factor = shift; factor != 0; ) {
        int rest = count % factor;
        count = factor;
        factor = rest;
    }
    if (count < total && count > 0) {
        for (; count > 0; --count) {
            Elem_1de1f0 *hole = first + count;
            Elem_1de1f0 *next = hole;
            Elem_1de1f0 holeVal = *hole;
            Elem_1de1f0 *next1 = hole + shift;
            if (next1 == last)
                next1 = first;
            while (next1 != hole) {
                *next = *next1;
                next = next1;
                int left = (int)((char *)last - (char *)next1) / 20;
                if (shift < left)
                    next1 = next1 + shift;
                else
                    next1 = first + (shift - left);
            }
            *next = holeVal;
        }
    }
}

} // namespace fn_f75938cb

// 0x001de340 CSPManager::vfunc_0 (30 B): matches/0x001de340.cpp
// sym: ??_GCSPManager@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CSPManager::~CSPManager() {}

namespace fn_f75938cb {

// 0x001de360 FUN_001de360 (114 B): equivalent/0x001de360.cpp
// sym: ?FUN_001de360@Owner_1de360@fn_f75938cb@@QAEXH@Z @575a6d7b5f17 @wa419c0a179a5
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 6/6)
// FUN_001de360 @ 0x001de360
void Owner_1de360::FUN_001de360(hulk_intptr a)
{
    CSPListener_1de360 *raw = (CSPListener_1de360 *)FUN_0008d690(0x10);
    CSPListener_1de360 *item;
    if (raw)
        item = raw->FUN_001db1c0(a);
    else
        item = 0;
    if (item)
        (&item->sub)->v0();
    if (current)
        (&current->sub)->v1();
    current = item;
    arg = a;
    z0 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
}


// 0x001de3f0 FUN_001de3f0 (113 B): equivalent/0x001de3f0.cpp
// sym: ?FUN_001de3f0@ObjList_1de3f0@fn_f75938cb@@QAEXPAVObj_1de3f0@2@@Z @8593a218ba94 @wb705647102d3
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 12/12)
// FUN_001de3f0 @ 0x001de3f0
// Removes target from the list, shifting the following entries down.
void ObjList_1de3f0::FUN_001de3f0(Obj_1de3f0* target)
{
    bool found = false;
    int n = count;
    for (int i = 0; i < n; i++) {
        Obj_1de3f0* o = items[i];
        if (found) {
            items[i - 1] = o;
        } else if (o == target) {
            found = true;
            o->FUN_001d7ff0();
            if (items[i] != 0)
                items[i]->Release();
            items[i] = 0;
        }
    }
    items[count - 1] = 0;
    if (found)
        count--;
}

} // namespace fn_f75938cb

// 0x001de4f0 FUN_001de4f0 (1809 B): equivalent/0x001de4f0.cpp [wrapped: macros]
// sym: ?FUN_001de4f0@World@fn_001de4f0@@QAEPAUObj@2@PAURegistry@2@PAUResName@2@HPBUMat4@2@@Z @0a8367f7b7b7 @w769e19d7cbb6
namespace fn_001de4f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3148 inputs, branch coverage 111/112, incomplete)
// FUN_001de4f0 @ 0x001de4f0
typedef unsigned __int64 u64;

struct V3 { float x, y, z; };
struct Mat4 { float m[16]; };

struct ResName {
    char data[12];
    const char *FUN_0027b010();
    void FUN_0027af70(const ResName *other);
};

struct Sub {
    char pad0[8];
    u64 id;                                  // 8
    int FUN_001d5e80(int a);
    int FUN_001d5dd0(int a);
    u64 FUN_001d4f40();
    u64 FUN_001d4f70();
};

struct Dyn {
    char pad0[0x164];
    float f164;
    char pad168[0x1b8 - 0x168];
    float f1b8, f1bc, f1c0;
    char b1c4;
    char pad1c5[0x1e4 - 0x1c5];
    float f1e4;
    float f1e8;
    char pad1ec[0x1f1 - 0x1ec];
    unsigned char b1f1;
    void FUN_002f57d0(const V3 *v);
};

struct Q {
    char pad0[0x70];
    Dyn *f70;
    void FUN_002ef440(void *what);
};

struct Obj {
    char pad0[8];
    ResName name;                            // 8
    char padc[0x40 - 0x14];
    int f40;
    char pad44[0xec - 0x44];
    Sub *fec;
    char padf0[0x148 - 0xf0];
    void *f148;
    char pad14c[0x198 - 0x14c];
    int f198;
    int f19c;

    void FUN_001d6b60(Mat4 m, int z);
    void FUN_001d6270();
    void FUN_001d7b80(int a, int b);
    void *FUN_001d6b40();
};

struct Hook {
    void FUN_001b4540(Obj *o);
};
extern "C" void * __cdecl FUN_001b6580(void);

struct Sink {
    void FUN_001eb7e0(ResName *name, u64 *id, void *r, const V3 *a, const V3 *b, V3 zero, int flag);
};

struct Holder {
    Sink *FUN_000862e0();
};

struct World2 {
    char pad0[0x54];
    Holder *f54;
};

#define DAT_004dd700 (*(World2 * *)&::DAT_004dd700)


struct Registry {
    char pad0[8];
    u64 id;                                  // 8
    Obj *FUN_001d5630(ResName *name, int v);
};

u64 FUN_0027b020(const char *s);
void *FUN_002f2750(u64 id);
void FUN_002f28d0(const char *s, float a, float b, float c, float d);

extern u64 DAT_004e2770;
extern u64 DAT_004dc0c0;
extern u64 DAT_004dc098;
extern u64 DAT_004dc078;
extern unsigned int DAT_004e2720;
extern u64 DAT_004e2718;                     // "car"
extern u64 DAT_004e2710;                     // "bus"
extern u64 DAT_004e2708;                     // "small_object"
extern u64 DAT_004e2700;                     // "large_vehicle"
extern u64 DAT_004e26d0;                     // "dumpster1_dumpster1"
extern u64 DAT_004e26f8;                     // "van_van"
extern u64 DAT_004e26f0;                     // "bus1_bus1"
extern u64 DAT_004e26e8;                     // "suv1_suv1"
extern u64 DAT_004e26e0;                     // "cubeVan_cubeVan"
extern u64 DAT_004e26d8;                     // "ambulance_ambulance"

#define INIT(bit, var, str) if (!(DAT_004e2720 & (bit))) { DAT_004e2720 = DAT_004e2720 | (bit); var = FUN_0027b020(str); }

struct TblA {
    u64 key;
    float f8;
    float fc;
};

struct TblB {
    u64 key;
    float a;
    float b;
    int c;
    int pad;
};

class World {
public:
    char pad0[0x1e824];
    int f1e824;
    char pad1e828[0x1ec60 - 0x1e828];
    TblA tblA[16];                           // 0x1ec60
    TblB tblB[16];                           // 0x1ed60

    Obj *FUN_001de4f0(Registry *reg, ResName *rn, int v, const Mat4 *m);
};

Obj *World::FUN_001de4f0(Registry *reg, ResName *rn, int v, const Mat4 *m)
{
    Obj *o = reg->FUN_001d5630(rn, v);
    if (o == 0)
        return o;

    ((owners::Target_27b040 *)&(o->name))->FUN_0027b040((hulk_uintptr)(rn->FUN_0027b010()));
    o->name.FUN_0027af70(rn);
    o->FUN_001d6b60(*m, 0);
    o->FUN_001d6270();
    if (o->fec->id == DAT_004e2770) {
        o->f198 = 2;
        o->f19c = 0;
    }
    ((owners::C_27cb80 *)o)->FUN_0027cb80((void *)(hulk_uintptr)(int)f1e824);
    ((Hook *)FUN_001b6580())->FUN_001b4540(o);
    o->FUN_001d7b80(0, 5);

    int flag = 5;
    if (o->f148 != 0)
        flag = 2;
    World2 *w2 = DAT_004dd700;
    Sub *s0 = o->fec;
    Holder *h = w2->f54;
    V3 up;
    up.x = 0.0f; up.y = 1.0f; up.z = 0.0f;
    V3 zero;
    zero.x = 0.0f; zero.y = 0.0f; zero.z = 0.0f;
    V3 zv;
    zv.x = 0.0f; zv.y = 0.0f; zv.z = 0.0f;
    void *r = o->FUN_001d6b40();
    h->FUN_000862e0()->FUN_001eb7e0(&o->name, &s0->id, r, &zero, &up, zv, flag);

    if (o->fec->FUN_001d5e80(o->f40) == 3 || o->fec->FUN_001d5dd0(o->f40) == 3) {
        FUN_002f28d0("bowling_ball", 1.05f, 100.0f, -0.25f, 1000.0f);
        void *w = FUN_002f2750(FUN_0027b020("bowling_ball"));
        ((Q *)((owners::C_1d72e0 *)o)->FUN_001d72e0())->FUN_002ef440(w);
        Dyn *d = ((Q *)((owners::C_1d72e0 *)o)->FUN_001d72e0())->f70;
        d->f1b8 = 5.0f;
        d->f1bc = 5.0f;
        d->f1c0 = 5.0f;
        d->b1c4 = 1;
    } else if (((Q *)((owners::C_1d72e0 *)o)->FUN_001d72e0()) != 0) {
        Sub *s = o->fec;
        u64 none = FUN_0027b020("NONE");
        if (s->FUN_001d4f40() != none) {
            void *w = FUN_002f2750(o->fec->FUN_001d4f40());
            if (w != 0)
                ((Q *)((owners::C_1d72e0 *)o)->FUN_001d72e0())->FUN_002ef440(w);
        }
    }

    if (((Q *)((owners::C_1d72e0 *)o)->FUN_001d72e0()) == 0)
        return o;
    if (((Q *)((owners::C_1d72e0 *)o)->FUN_001d72e0())->f70 == 0)
        return o;
    Dyn *p = ((Q *)((owners::C_1d72e0 *)o)->FUN_001d72e0())->f70;
    p->f164 = 1.0f;

    u64 key = reg->id;
    int idx = -1;
    int i;
    for (i = 0; i < 16; i++) {
        if (tblB[i].key == key) {
            idx = i;
            break;
        }
    }
    if (idx >= 0) {
        p->f1e8 = tblB[idx].a;
        p->f1e4 = tblB[idx].b;
        int c = tblB[idx].c;
        if (c < 0)
            p->b1f1 = 0xff;
        else
            p->b1f1 = (unsigned char)c;
    } else {
        INIT(1, DAT_004e2718, "car");
        INIT(2, DAT_004e2710, "bus");
        INIT(4, DAT_004e2708, "small_object");
        INIT(8, DAT_004e2700, "large_vehicle");
        volatile float v = ((owners::Target_1d4ea0 *)(o->fec))->FUN_001d4ea0(o->f40);
        if (v > 0.0f) {
            int j = -1;
            for (i = 0; i < 16; i++) {
                volatile float d = v - tblA[i].f8;
                volatile int bits = *(volatile int *)&d & 0x7fffffff;
                float ad = *(volatile float *)&bits;
                if (ad <= 1e-05f) {
                    j = i;
                    break;
                }
            }
            if (j >= 0) {
                u64 k = tblA[j].key;
                float val = 0.0f;
                bool store = true;
                if (k == DAT_004e2718) {
                    INIT(0x10, DAT_004e26d0, "dumpster1_dumpster1");
                    if (reg->id != DAT_004e26d0) {
                        val = 15.0f;
                        p->b1f1 = 0;
                    } else {
                        p->b1f1 = 1;
                        val = 6.0f;
                    }
                } else if (k == DAT_004e2710) {
                    val = 20.0f;
                } else if (k == DAT_004e2700) {
                    val = 10.0f;
                } else if (k == DAT_004e2708) {
                    val = 60.0f;
                } else {
                    store = false;
                }
                if (store) {
                    p->f1e8 = val;
                    p->f1e4 = val;
                }
            } else {
                INIT(0x20, DAT_004e26f8, "van_van");
                INIT(0x40, DAT_004e26f0, "bus1_bus1");
                INIT(0x80, DAT_004e26e8, "suv1_suv1");
                INIT(0x100, DAT_004e26e0, "cubeVan_cubeVan");
                INIT(0x200, DAT_004e26d8, "ambulance_ambulance");
                u64 k2 = reg->id;
                float val = 0.0f;
                bool store = true;
                if (k2 == DAT_004e26f8) {
                    val = 10.0f;
                    p->b1f1 = 0;
                } else if (k2 == DAT_004e26f0) {
                    val = 25.0f;
                    p->b1f1 = 0;
                } else if (k2 == DAT_004e26e0) {
                    val = 25.0f;
                    p->b1f1 = 1;
                } else if (k2 == DAT_004e26d8 || k2 == DAT_004e26e8) {
                    val = 10.0f;
                    p->b1f1 = 0;
                } else {
                    store = false;
                }
                if (store) {
                    p->f1e8 = val;
                    p->f1e4 = val;
                }
            }
        }
    }

    u64 st = o->fec->FUN_001d4f70();
    if (st == DAT_004dc0c0 || st == DAT_004dc098 || st == DAT_004dc078) {
        V3 dir;
        dir.x = 0.0f; dir.y = -0.5f; dir.z = 0.0f;
        ((Q *)((owners::C_1d72e0 *)o)->FUN_001d72e0())->f70->FUN_002f57d0(&dir);
    }
    return o;
}
} // namespace fn_001de4f0
#undef INIT
#undef DAT_004dd700

namespace fn_f75938cb {

// 0x001dec10 FUN_001dec10 (388 B): equivalent/0x001dec10.cpp
// sym: ?FUN_001dec10@Pool_1dec10@fn_f75938cb@@QAEXXZ @a8239d51e39b @wa47ec575e534
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 20/20)
// FUN_001dec10 @ 0x001dec10
void Pool_1dec10::FUN_001dec10()
{
    int i;
    for (i = 0; i < itemCount; i++) {
        items[i]->FUN_001d7ff0();
        if (items[i]) {
            items[i]->vfn1();
            items[i] = 0;
        }
    }
    itemCount = 0;
    if (buffer) {
        buffer->FUN_00263e90();
        buffer = 0;
    }
    f1e61c = 0;
    Quat q;
    q.x = 0.0f;
    q.y = 0.0f;
    q.z = 0.0f;
    q.w = 1.0f;
    for (i = 0x800; i != 0; i--) {
        Slot_1dec10 *s = &slots[0x800 - i];
        if (s->active != 0) {
            Rec *r = &recs[s->recIndex];
            if (r->s10 & 1) {
                if (s->res) {
                    s->res->vfn1();
                    s->res = 0;
                }
            }
            r->a = 0;
            r->b = 0;
            r->c = 0;
            r->maxv = 3.4028235e+38f;
            r->s10 = 0;
            r->s12 = -1;
        }
        s->a.FUN_0027b040(0);
        s->b.FUN_0027b040(0);
        s->field1c = 0;
        s->c.FUN_001db780(&q);
        s->res = 0;
        s->field20 = 0;
        s->active = 0;
        s->recIndex = -1;
        s->field26 = 0;
        s->field24 = 0;
        s->field27 = 1;
    }
    for (i = 0; i < recCount; i++) {
        Rec *r = &recs[i];
        r->a = 0;
        r->b = 0;
        r->c = 0;
        r->maxv = 3.4028235e+38f;
        r->s10 = 0;
        r->s12 = -1;
    }
    recCount = 0;
    f1e608 = 0;
    f1ec58 = 0;
    f1e60c = 0;
    f1e610 = 0;
}


// 0x001deda0 FUN_001deda0 (155 B): equivalent/0x001deda0.cpp
// sym: ?FUN_001deda0@Manager_1deda0@fn_f75938cb@@QAEXPAUKey_1deda0@2@@Z @513de6aa4c11 @w31540dab5f66
// STATUS: equivalent (tools/equiv.py level 3: 1047 inputs, branch coverage 14/16, incomplete)
// FUN_001deda0 @ 0x001deda0
// FUN_001deda0: find the entry with the given 64-bit key and notify its owner about the slot's flags
void Manager_1deda0::FUN_001deda0(Key_1deda0 *key)
{
    int i;
    for (i = 0; i < 0x800; i++) {
        if (entries[i].keyLo == key->lo && entries[i].keyHi == key->hi)
            break;
    }
    if (i >= 0x800)
        return;
    Entry_1deda0 *e = &entries[i];
    Slot_1deda0 *s = &slots[e->slot];
    if (!(s->flags & 0x300))
        return;
    char *t = (char *)FUN_001b6580() + 0x594;
    if (t == 0)
        return;
    unsigned int flags = s->flags;
    unsigned int mode = 0;
    if (flags & 0x100)
        mode = 1;
    if (flags & 0x200)
        mode += 2;
    ((Target_1deda0 *)t)->FUN_001b5d20(e->f16, mode);
}


// 0x001dee40 FUN_001dee40 (101 B): equivalent/0x001dee40.cpp
// sym: ?FUN_001dee40@Table_1dee40@fn_f75938cb@@QAEPAUItem_1dee40@2@HH@Z @651ad0d1bd47 @wbaa25db78ae6
// STATUS: equivalent (tools/equiv.py level 3: 141 inputs, branch coverage 12/16, incomplete)
// FUN_001dee40 @ 0x001dee40
Item_1dee40 *Table_1dee40::FUN_001dee40(int a, int b)
{
    for (int i = 0; i < count; i++) {
        Item_1dee40 *it = Get(i);
        if (it->f8 == a && it->fc == b)
            return Get(i);
    }
    return 0;
}


// 0x001deeb0 FUN_001deeb0 (113 B): equivalent/0x001deeb0.cpp
// sym: ?FUN_001deeb0@EntryList_1deeb0@fn_f75938cb@@QAEPAUEntry_1deeb0@2@PBUKey_1deeb0@2@@Z @80c92e4ff5cc @wa7d9c34575d6
// STATUS: equivalent (tools/equiv.py level 3: 142 inputs, branch coverage 12/16, incomplete)
// FUN_001deeb0 @ 0x001deeb0
// Finds the entry whose id matches the key.
Entry_1deeb0* EntryList_1deeb0::FUN_001deeb0(const Key_1deeb0* key)
{
    int lo = key->lo;
    int hi = key->hi;
    for (int i = 0; i < count; i++) {
        Entry_1deeb0* e = 0;
        if (i < count && i >= 0)
            e = entries[i];
        if (e->id.lo == lo && e->id.hi == hi) {
            if (i < count && i >= 0)
                return entries[i];
            return 0;
        }
    }
    return 0;
}


// 0x001def30 FUN_001def30 (123 B): equivalent/0x001def30.cpp
// sym: ?FUN_001def30@Table_1def30@fn_f75938cb@@QAEPAUEntry_1def30@2@PBD@Z @89c407819c14 @w369db0816f0c
// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 12/16, incomplete)
// FUN_001def30 @ 0x001def30
Entry_1def30 *Table_1def30::FUN_001def30(const char *name) {
    Id_1def30 id = FUN_00096d80(name);
    for (int i = 0; i < count; i++) {
        Entry_1def30 *e = At(i);
        if (e->idLo == id.lo && e->idHi == id.hi) {
            return At(i);
        }
    }
    return 0;
}


// 0x001defb0 FUN_001defb0 (44 B): matches/0x001defb0.cpp
// sym: ?Run@Obj@fn_f75938cb@@QAEEHH@Z
unsigned char Obj::Run(hulk_intptr a, int b) {
    unsigned char result = 0;
    hulk_intptr n = ((owners::C_1d6c70 *)(((Item*)a)))->FUN_001d6c70();
    if (n >= 0)
        result = Go_001dc230((Item*)n, b);
    return result;
}

} // namespace fn_f75938cb

// 0x001defe0 FUN_001defe0 (37 B): matches/0x001defe0.cpp [wrapped: conflict: Obj]
// sym: ?FUN_001defe0@ThisWrap_001defe0@fn_001defe0@@QAEXHD@Z
namespace fn_001defe0 {
struct Obj {
    char pad[0xa8];
    char flag;
};
struct Holder {
    char pad[0x11c];
    Obj* obj;
};
struct ThisWrap_001defe0 {
    Holder* get_001def30(int);
    void FUN_001defe0(int id, char v);
};
void ThisWrap_001defe0::FUN_001defe0(int id, char v) {
    Holder* h = this->get_001def30(id);
    if (h) {
        Obj* o = h->obj;
        if (o)
            o->flag = v;
    }
}
} // namespace fn_001defe0

namespace fn_f75938cb {

// 0x001df010 FUN_001df010 (235 B): matches/0x001df010.cpp
// sym: ?FUN_001df010@Owner_1df010@fn_f75938cb@@QAEXHPBDH0HHHMMM@Z
// FUN_001df010 @ 0x001df010
void Owner_1df010::FUN_001df010(int a1, const char *actorName, int a3, const char *partName, int px, int py, int pz,
                         float rx, float ry, float rz)
{
    Registry_1df010 *registry = group->registry;
    Actor_1df010 *actor = registry->FUN_00024280(FUN_002672f0(actorName, 0, 0));
    Part *part = FUN_001def30(a1);
    if (!actor || !part)
        return;
    int index = 0xffff;
    if (actor->holder) {
        Index_1df010 *table = actor->holder->index;
        index = table->FUN_0027b200(FUN_0027b020(partName));
    }
    Mat4_1df010 m;
    m.FUN_0022b980();
    ((owners::Matrix_22bc20 *)&m)->FUN_0022bc20(rx * 0.01745329238474369f, ry * 0.01745329238474369f, rz * 0.01745329238474369f);
    m.tx = px;
    m.ty = py;
    m.tz = pz;
    actor->FUN_0003acf0(a3, part, index, 0, 0, &m);
}


// 0x001df100 FUN_001df100 (41 B): matches/0x001df100.cpp
// sym: ?F@Obj@fn_f75938cb@@QAEHHH@Z
int Obj::F(int a, int b) {
    int n = ((CSPManager_nv_1df100*)(((CSPManager*)(((CSPManager*)this)))))->lookup_001dbfe0(a);
    if (n >= 0)
        return FnG_001dc2d0(n, b);
    return -1;
}


// 0x001df130 FUN_001df130 (40 B): matches/0x001df130.cpp
// sym: ?FUN_001df130@CSPManager_1df130@fn_f75938cb@@QAEHH@Z
int CSPManager_1df130::FUN_001df130(int value) {
    int ret = -1;
    CSPManager_1df130* result = (CSPManager_1df130*)FUN_001def30(value);
    if (result)
        ret = result->FUN_001d7100(ret);
    return ret;
}


// 0x001df160 FUN_001df160 (39 B): matches/0x001df160.cpp
// sym: ?Target@ThisWrap_001df160@fn_f75938cb@@QAEDHH@Z
char ThisWrap_001df160::Target(int id, int arg) {
    char result = 0;
    Obj* p = this->Find_001def30(id);
    if (p)
        result = p->Act_001d7150(arg);
    return result;
}

} // namespace fn_f75938cb

// 0x001df190 FUN_001df190 (74 B): matches/0x001df190.cpp
// sym: ?FUN_001df190@CSPManager@@QAEPAXPAXH@Z
void* CSPManager::FUN_001df190(void* __p0, int arg) { Vec3_1df190 * out = (Vec3_1df190 *)__p0;

    int i = ((CSPManager_nv_1df190*)this)->Find_001dbfe0(arg);
    if (i < 0) {
        out->x = 0x7f7fffff;
        out->y = 0x7f7fffff;
        out->z = 0x7f7fffff;
        return (void*)(out);
    }
    Vec3_1df190* p = ((CSPManager_nv_1df190*)this)->Get_001dc3b0(i);
    *out = *p;
    return (void*)(out);
}

namespace fn_f75938cb {

// 0x001df1e0 FUN_001df1e0 (40 B): matches/0x001df1e0.cpp
// sym: ?FUN_001df1e0@CSPManager_1df1e0@fn_f75938cb@@QAEDHUVec3_1df1e0@2@@Z
// b..d: a vector passed by value (FUN_001dc420 copies its three words). A by-value struct parameter can't be
// declared in include/gen (tools/gen_headers.py nv_sig_type), so the member is defined on a local stand-in.
char CSPManager_1df1e0::FUN_001df1e0(int a, Vec3_1df1e0 b) {
    int n = Find_001dbfe0(a);
    if (n < 0)
        return 0;
    return Do_001dc420(n, &b);
}


// 0x001df210 FUN_001df210 (119 B): matches/0x001df210.cpp
// sym: ?Add@Owner_1df210@fn_f75938cb@@QAE_NPAVItem_1df210@2@@Z
bool Owner_1df210::Add(Item_1df210* item) {
    int n = count;
    if (n >= 4)
        return false;
    int i = 0;
    while (i < count) {
        if (items[i] == item)
            return false;
        ++i;
    }
    if (item)
        item->Destroy();
    if (items[n])
        items[n]->Release();
    items[n] = item;
    count = count + 1;
    return true;
}


// 0x001df290 FUN_001df290 (74 B): matches/0x001df290.cpp
// sym: ?Clear@Owner_1df290@fn_f75938cb@@QAEXXZ
void Owner_1df290::Clear() {
    int i = 0;
    if (count > 0) {
        Item_1df290** p = items;
        do {
            if (*p) {
                (*p)->B();
                *p = 0;
            }
            *p = 0;
            ++i;
            ++p;
        } while (i < count);
    }
    count = 0;
}

} // namespace fn_f75938cb

// 0x001df2e0 FUN_001df2e0 (51 B): matches/0x001df2e0.cpp [wrapped: conflict: Obj]
// sym: ?FUN_001df2e0@ThisWrap_001df2e0@fn_001df2e0@@QAEHHH@Z
namespace fn_001df2e0 {
class Obj {
  public:
    char pad[0x150];
    int value;
    int Check_001d6990();
};
struct ThisWrap_001df2e0 {
    Obj* Find_001def30(int);
    int FUN_001df2e0(int key, int value);
};
int ThisWrap_001df2e0::FUN_001df2e0(int key, int value) {
    Obj* p = this->Find_001def30(key);
    if (!p || !p->Check_001d6990())
        return -1;
    p->value = value;
    return 0;
}
} // namespace fn_001df2e0

namespace fn_f75938cb {

// 0x001df320 FUN_001df320 (13 B): matches/0x001df320.cpp
// sym: ?FUN_001df320@ThisWrap_001df320@fn_f75938cb@@QAEXHHHHHH@Z
void ThisWrap_001df320::FUN_001df320(int a, int b, int c, int d, int e, int f) {
    this->FUN_001def30(a);
}


// 0x001df330 FUN_001df330 (27 B): matches/0x001df330.cpp
// sym: ?Set@Obj_1df330@fn_f75938cb@@QAEXHD@Z
void Obj_1df330::Set(int id, char c) {
    Obj_1df330* p = Find_001def30(id);
    if (p)
        p->flag = c;
}

} // namespace fn_f75938cb

// 0x001df350 FUN_001df350 (30 B): matches/0x001df350.cpp [wrapped: conflict: Obj]
// sym: ?FUN_001df350@ThisWrap_001df350@fn_001df350@@QAEEH@Z
namespace fn_001df350 {
class Obj {
    char pad[0x194];

  public:
    unsigned char flag;
};
struct ThisWrap_001df350 {
    Obj* lookup_001def30(int);
    unsigned char FUN_001df350(int id);
};
unsigned char ThisWrap_001df350::FUN_001df350(int id) {
    Obj* p = this->lookup_001def30(id);
    unsigned char r = 0;
    if (p)
        r = p->flag;
    return r;
}
} // namespace fn_001df350


// 0x001df370 FUN_001df370 (43 B): matches/0x001df370.cpp [wrapped: conflict: Obj]
// sym: ?Target@ThisWrap_001df370@fn_001df370@@QAEDH@Z
namespace fn_001df370 {
class Obj {
  public:
    char pad[0x70];
    char flag;
};
class Mid {
  public:
    char pad[0x74];
    Obj* obj;
};
struct ThisWrap_001df370 {
    Mid* Find_001def30(int);
    char Target(int id);
};
char ThisWrap_001df370::Target(int id) {
    Mid* p = this->Find_001def30(id);
    if (!p)
        return 0;
    p = ((Mid *)((owners::C_1d72e0 *)p)->FUN_001d72e0());
    if (!p)
        return 0;
    Obj* q = p->obj;
    if (!q)
        return 0;
    return q->flag;
}
} // namespace fn_001df370


// 0x001df3a0 FUN_001df3a0 (49 B): matches/0x001df3a0.cpp [wrapped: conflict: Obj]
// sym: ?target@ThisWrap_001df3a0@fn_001df3a0@@QAEDHD@Z
namespace fn_001df3a0 {
class Obj {
  public:
    char pad[0x70];
    char flag;
    char gap[3];
    Obj* link;
};
struct ThisWrap_001df3a0 {
    Obj* findObj_001def30(int);
    char target(int id, char value);
};
char ThisWrap_001df3a0::target(int id, char value) {
    Obj* a = this->findObj_001def30(id);
    if (!a)
        return 0;
    Obj* b = ((Obj *)((owners::C_1d72e0 *)a)->FUN_001d72e0());
    if (!b)
        return 0;
    Obj* c = b->link;
    if (!c)
        return 0;
    c->flag = value;
    return 1;
}
} // namespace fn_001df3a0


// 0x001df3e0 FUN_001df3e0 (29 B): matches/0x001df3e0.cpp [wrapped: compile error in a shared declaration (C2556)]
// sym: ?Target@Obj_1df3e0@fn_001df3e0@@QAEMI@Z
namespace fn_001df3e0 {
// Same code shape as 0x000238b0 (propagated; names are from that function)
typedef unsigned int U_1df3e0;
typedef unsigned __int64 U64_1df3e0;
extern U64_1df3e0 __cdecl FUN_0027b020(U_1df3e0);
struct Obj_1df3e0 {
    float Second_001dd190(U64_1df3e0);
    hulk_freg Target(U_1df3e0);
};
hulk_freg Obj_1df3e0::Target(U_1df3e0 param) {
    U64_1df3e0 a = FUN_0027b020(param);
    return Second_001dd190(a);
}
} // namespace fn_001df3e0

namespace fn_f75938cb {

// 0x001df400 FUN_001df400 (121 B): equivalent/0x001df400.cpp
// sym: ?FUN_001df400@Manager_1df400@fn_f75938cb@@QAE_NTArg_1df400@2@HHHPBD@Z @6149df4b3e43 @wcab6c1cff6e2
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/9)
// FUN_001df400 @ 0x001df400
// Arg is passed by value as a union: the original reuses the dead first argument slot as a
// bool local and pushes the whole dword (stale high bytes) to the final call.
bool Manager_1df400::FUN_001df400(Arg_1df400 id, int a2, int a3, int a4, const char* mode) {
    Target_1df400* target = FUN_001def30(id.id);
    if (!target)
        return false;
    int value = DAT_004dd700->registry->FUN_00106230(a2);
    id.flag = 1;
    if (mode && (*mode == 'Z' || *mode == 'z'))
        id.flag = 0;
    target->FUN_001d74c0(value, a3, a4, id.word);
    return true;
}


// 0x001df4c0 FUN_001df4c0 (156 B): equivalent/0x001df4c0.cpp
// sym: ?FUN_001df4c0@Manager_1df4c0@fn_f75938cb@@QAEDH@Z @be84c66bdcd8 @w4eab840f4396
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001df4c0 @ 0x001df4c0
// FUN_001df4c0: is the entry's owner away from the origin
char Manager_1df4c0::FUN_001df4c0(int index)
{
    if (index < 0 || index >= 0x800)
        return 0;
    Entry_1df4c0 *e = &entries[index];
    if (!(slots[e->slot].flags & 1))
        return 0;
    if (e->owner == 0)
        return 0;
    if (((Holder_1df4c0 *)((owners::C_1d72e0 *)(e->owner))->FUN_001d72e0()) == 0)
        return 0;
    V3_1df4c0 v = ((Holder_1df4c0 *)((owners::C_1d72e0 *)(e->owner))->FUN_001d72e0())->pos;
    if (FUN_00018960(v.FUN_000111f0(), 0.0f, 1e-5f))
        return 0;
    return 1;
}


// 0x001df560 FUN_001df560 (115 B): matches/0x001df560.cpp
// sym: ??0Function5_1df560@fn_f75938cb@@QAE@PBDH@Z
Function5_1df560::Function5_1df560(const char* p, hulk_intptr x) : Function_1df560(p, 5) {
    m1c = x;
    c18 = FUN_001d04d0(((char*)&DAT_0048e100));
    c10 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    c11 = FUN_001d04d0(((char*)&DAT_0048e128));
    c12 = FUN_001d04d0(((char*)&DAT_0048e128));
    c13 = FUN_001d04d0(((char*)&DAT_0048e128));
    c14 = FUN_001d04d0(((char*)&DAT_0048e128));
}

} // namespace fn_f75938cb

// 0x001df5e0 Function5<void,const_char_*,float,float,float,float>::vfunc_2 (30 B): matches/0x001df5e0.cpp
// sym: ?vfunc_2@?$Function5@XPBDMMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Function5<void, const char *, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001df600(a, b, c, this->f_1c);
}

namespace fn_f75938cb {

// 0x001df600 FUN_001df600 (54 B): equivalent/0x001df600.cpp
// sym: ?FUN_001df600@fn_f75938cb@@YAXIPBIIP6AXIIIII@Z@Z @4510a995c00e @wd562d1160fb4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001df600 @ 0x001df600
void __cdecl FUN_001df600(unsigned int unused, const unsigned int *values, unsigned int unused2, Callback callback)
{
    callback(values[0], values[1], values[2], values[3], values[4]);
}

} // namespace fn_f75938cb

// 0x001df680 Function1<void,float>::vfunc_2 (14 B): matches/0x001df680.cpp [wrapped: conflict: Function; Function1]
// sym: ?v2@Function1@fn_001df680@@UAEXHPAPBDH@Z
namespace fn_001df680 {
// Same code shape as 0x000be4c0 (propagated; names are from that function)
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Function1 : public Function {
    char pad[0x18];

  public:
    void(__cdecl* mFn)(const char*);
    virtual void v0();
    virtual void v1();
    virtual void v2(int, const char**, int);
};
void Function1::v2(int, const char** p, int) {
    mFn(*p);
}
} // namespace fn_001df680


// 0x001df690 Function5<void,const_char_*,float,float,float,float>::vfunc_0 (30 B): matches/0x001df690.cpp
// sym: ??_G?$Function5@XPBDMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function5<void, const char *, float, float, float, float>::~Function5() {}
#if defined(HULK_PTR64)
template class Function5<void, const char *, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1df690)
#endif


// 0x001df6b0 Function1<void,float>::vfunc_0 (30 B): matches/0x001df6b0.cpp
// sym: ??_G?$Function1@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function1<void, float>::~Function1() {}
#if defined(HULK_PTR64)
template class Function1<void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1df6b0)
#endif


// 0x001df710 Method1<CSPManager,void,int>::vfunc_0 (30 B): matches/0x001df710.cpp
// sym: ??_G?$Method1@VCSPManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSPManager, void, int>::~Method1() {}


// 0x001df730 Method1<CSPManager,void,int>::vfunc_2 (19 B): matches/0x001df730.cpp
// sym: ?vfunc_2@?$Method1@VCSPManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSPManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1df730* d = (Dummy_1df730*)a;
    (d->*(*(void (Dummy_1df730::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSPManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1df710)
#endif


// 0x001df750 FUN_001df750 (89 B): matches/0x001df750.cpp [wrapped: conflict: Method3]
// sym: ??0Method3@fn_001df750@@QAE@PBDH@Z
namespace fn_001df750 {
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

class Function_1df750 {
  public:
    virtual void f();
    char pad[12];
    Function_1df750(const char*, int);
};
class Method3 : public Function_1df750 {
  public:
    char a;
    char b;
    char c;
    char pad2[5];
    char d;
    char pad3[3];
    int value;
    Method3(const char*, hulk_intptr);
    virtual void f();
};
Method3::Method3(const char* name, hulk_intptr v) : Function_1df750(name, 3) {
    value = v;
    d = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    a = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b = FUN_001d04d0(((const char*)&DAT_0048e134));
    c = FUN_001d04d0(((const char*)&DAT_0048e134));
}
} // namespace fn_001df750
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001df7b0 Method3<CSPManager,bool,const_char_*,int,int>::vfunc_0 (30 B): matches/0x001df7b0.cpp
// sym: ??_G?$Method3@VCSPManager@@_NPBDHH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CSPManager, bool, const char *, int, int>::~Method3() {}


// 0x001df7d0 Method3<CSPManager,bool,const_char_*,int,int>::vfunc_2 (39 B): matches/0x001df7d0.cpp
// sym: ?vfunc_2@?$Method3@VCSPManager@@_NPBDHH@@UAEXPAX00@Z
template <> void Method3<CSPManager, bool, const char *, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1df7d0 * obj = (CSPManager_1df7d0 *)__p0; Args_1df7d0 * args = (Args_1df7d0 *)__p1; bool * out = (bool *)__p2;

    bool (CSPManager_1df7d0::*fn)(const char*, int, int) = (*(bool (CSPManager_1df7d0::**)(const char *, int, int))&this->f_1c);
    const char* a = args->a;
    int b = args->b;
    int c = args->c;
    bool r = (obj->*fn)(a, b, c);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method3<CSPManager, bool, const char *, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1df7b0)
#endif


// 0x001df800 FUN_001df800 (76 B): matches/0x001df800.cpp [wrapped: conflict: Method2]
// sym: ??0Method2@fn_001df800@@QAE@PBDH@Z
namespace fn_001df800 {

class Function_1df800 {
  public:
    Function_1df800(const char*, int);
    virtual void a();
};
extern "C++" __declspec(nothrow) unsigned char __cdecl FnF_001d04d0(const char*);
class Method2 : public Function_1df800 {
  public:
    char p0[12];
    unsigned char b10, b11;
    char p12[6];
    unsigned char b18;
    char p19[3];
    int x1c;
    virtual void a();
    Method2(const char*, int);
};
Method2::Method2(const char* s, int x) : Function_1df800(s, 2) {
    x1c = x;
    b18 = FnF_001d04d0(((const char*)&DAT_0048e0e4));
    b10 = FnF_001d04d0(((const char*)&DAT_0048e0f0));
    b11 = FnF_001d04d0(((const char*)&DAT_0048e0e4));
}
} // namespace fn_001df800


// 0x001df850 Method2<CSPManager,bool,const_char_*,bool>::vfunc_0 (30 B): matches/0x001df850.cpp
// sym: ??_G?$Method2@VCSPManager@@_NPBD_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSPManager, bool, const char *, bool>::~Method2() {}


// 0x001df870 Method2<CSPManager,bool,const_char_*,bool>::vfunc_2 (41 B): matches/0x001df870.cpp
// sym: ?vfunc_2@?$Method2@VCSPManager@@_NPBD_N@@UAEXPAX00@Z
// Same code shape as 0x0002c510 (propagated; names are from that function)
template <> void Method2<CSPManager, bool, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1df870 * obj = (CActorManager_1df870 *)__p0; Pair_1df870 * p = (Pair_1df870 *)__p1; bool * out = (bool *)__p2;

    bool (CActorManager_1df870::*fn)(const char*, bool) = (*(bool (CActorManager_1df870::**)(const char *, bool))&this->f_1c);
    const char* s = p->p;
    bool b = p->b;
    bool r = (obj->*fn)(s, b);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method2<CSPManager, bool, const char *, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1df850)
#endif


// 0x001df8f0 Method2<CSPManager,bool,const_char_*,int>::vfunc_0 (30 B): matches/0x001df8f0.cpp
// sym: ??_G?$Method2@VCSPManager@@_NPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSPManager, bool, const char *, int>::~Method2() {}


// 0x001df910 Method2<CSPManager,bool,const_char_*,int>::vfunc_2 (33 B): matches/0x001df910.cpp
// sym: ?vfunc_2@?$Method2@VCSPManager@@_NPBDH@@UAEXPAX00@Z
template <> void Method2<CSPManager, bool, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1df910 * obj = (CSPManager_1df910 *)__p0; Args * args = (Args *)__p1; bool * out = (bool *)__p2;

    bool (CSPManager_1df910::*fn)(const char*, int) = (*(bool (CSPManager_1df910::**)(const char *, int))&this->f_1c);
    const char* s = args->s;
    int n = args->n;
    bool value = (obj->*fn)(s, n);
    if (out)
        *out = value;
}
#if defined(HULK_PTR64)
template class Method2<CSPManager, bool, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1df8f0)
#endif


// 0x001df980 Method1<CSPManager,int,const_char_*>::vfunc_0 (30 B): matches/0x001df980.cpp
// sym: ??_G?$Method1@VCSPManager@@HPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSPManager, int, const char *>::~Method1() {}


// 0x001df9a0 Method1<CSPManager,int,const_char_*>::vfunc_2 (29 B): matches/0x001df9a0.cpp
// sym: ?vfunc_2@?$Method1@VCSPManager@@HPBD@@UAEXPAX00@Z
template <> void Method1<CSPManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1df9a0 * obj = (CSPManager_1df9a0 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (CSPManager_1df9a0::*f)(const char*) = (*(int (CSPManager_1df9a0::**)(const char *))&this->f_1c);
    const char* a = *arg;
    int r = (obj->*f)(a);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CSPManager, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1df980)
#endif


// 0x001dfa10 Method2<CSPManager,void,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001dfa10.cpp
// sym: ??_G?$Method2@VCSPManager@@XPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSPManager, void, const char *, const char *>::~Method2() {}


// 0x001dfa30 Method2<CSPManager,void,const_char_*,const_char_*>::vfunc_2 (23 B): matches/0x001dfa30.cpp
// sym: ?vfunc_2@?$Method2@VCSPManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CSPManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1dfa30* m = (CFEManager_1dfa30*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1dfa30::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CSPManager, void, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1dfa10)
#endif


// 0x001dfaa0 Method2<CSPManager,void,const_char_*,bool>::vfunc_0 (30 B): matches/0x001dfaa0.cpp
// sym: ??_G?$Method2@VCSPManager@@XPBD_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSPManager, void, const char *, bool>::~Method2() {}
#if defined(HULK_PTR64)
template class Method2<CSPManager, void, const char *, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1dfaa0)
#endif


// 0x001dfac0 Method2<CSPManager,void,const_char_*,bool>::vfunc_2 (25 B): matches/0x001dfac0.cpp [wrapped: conflict: Args; CSPManager; Function; Method2]
// sym: ?v2@Method2@fn_001dfac0@@UAEXPAXPAUArgs@2@0@Z
namespace fn_001dfac0 {
class CSPManager {
  public:
    void Act(const char*, bool);
};
struct Args {
    const char* s;
    bool b;
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Method2 : public Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(void*, Args*, void*);
    char pad[0x18];
    void (CSPManager::*method)(const char*, bool);
};
void Method2::v2(void* obj, Args* args, void*) {
    CSPManager* p = (CSPManager*)obj;
    (p->*method)(args->s, args->b);
}
} // namespace fn_001dfac0

namespace fn_f75938cb {

// 0x001dfae0 FUN_001dfae0 (128 B): matches/0x001dfae0.cpp
// sym: ??0Method6_1dfae0@fn_f75938cb@@QAE@PBDH@Z
Method6_1dfae0::Method6_1dfae0(const char* p, hulk_intptr n) : Function_1dfae0(p, 6) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00423318);
    m1c = n;
    m18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    m10 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m11 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m12 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    m13 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m14 = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    m15 = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
}

} // namespace fn_f75938cb

// 0x001dfb60 Method6<CSPManager,void,const_char_*,const_char_*,int,const_char_*,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x001dfb60.cpp
// sym: ??_G?$Method6@VCSPManager@@XPBDPBDHPBDVVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CSPManager, void, const char *, const char *, int, const char *,math::Vector,math::Vector>::~Method6() {}


// 0x001dfb80 Method6<CSPManager,void,const_char_*,const_char_*,int,const_char_*,math::Vector,math::Vector>::vfunc_2 (30 B): matches/0x001dfb80.cpp
// sym: ?vfunc_2@?$Method6@VCSPManager@@XPBDPBDHPBDVVector@math@@V23@@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CSPManager, void, const char *, const char *, int, const char *,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001dfba0(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CSPManager, void, const char *, const char *, int, const char *,math::Vector,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1dfb60)
#endif

namespace fn_f75938cb {

// 0x001dfba0 FUN_001dfba0 (123 B): equivalent/0x001dfba0.cpp
// sym: ?FUN_001dfba0@fn_f75938cb@@YAXPAVTarget_1dfba0@1@PAHHP821@AEXHHHHUTriple_1dfba0@1@2@Z@Z @5df3fd110d8f @w5334739705dd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001dfba0 @ 0x001dfba0
// Calls `callback` on `self` with the ten words of `args`
// (four scalars, then two 3-word records).
void FUN_001dfba0(Target_1dfba0 *self, int *args, int unused, Callback_1dfba0 callback) {
    Triple_1dfba0 first = { args[4], args[5], args[6] };
    Triple_1dfba0 second = { args[7], args[8], args[9] };
    (self->*callback)(args[0], args[1], args[2], args[3], first, second);
}

} // namespace fn_f75938cb

// 0x001dfc70 Method2<CSPManager,int,const_char_*,int>::vfunc_0 (30 B): matches/0x001dfc70.cpp
// sym: ??_G?$Method2@VCSPManager@@HPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSPManager, int, const char *, int>::~Method2() {}


// 0x001dfc90 Method2<CSPManager,int,const_char_*,int>::vfunc_2 (33 B): matches/0x001dfc90.cpp
// sym: ?vfunc_2@?$Method2@VCSPManager@@HPBDH@@UAEXPAX00@Z
template <> void Method2<CSPManager, int, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; Pair_1dfc90 * p = (Pair_1dfc90 *)__p1; int * out = (int *)__p2;

    int (CSPManager_1dfc90::*fn)(int, int) = (*(int (CSPManager_1dfc90::**)(int, int))&this->f_1c);
    CSPManager_1dfc90* m = (CSPManager_1dfc90*)x;
    int a = p->a;
    int b = p->b;
    int r = (m->*fn)(a, b);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method2<CSPManager, int, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1dfc70)
#endif


// 0x001dfd10 Method2<CSPManager,int,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001dfd10.cpp
// sym: ??_G?$Method2@VCSPManager@@HPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSPManager, int, const char *, const char *>::~Method2() {}


// 0x001dfd30 Method2<CSPManager,int,const_char_*,const_char_*>::vfunc_2 (33 B): matches/0x001dfd30.cpp
// sym: ?vfunc_2@?$Method2@VCSPManager@@HPBDH@@UAEXPAX00@Z
template <> void Method2<CSPManager, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1dfd30 * o = (CSPManager_1dfd30 *)__p0; Pair * p = (Pair *)__p1; int * out = (int *)__p2;

    int (CSPManager_1dfd30::*fn)(const char*, const char*) = (*(int (CSPManager_1dfd30::**)(const char *, const char *))&this->f_1c);
    const char* a = p->a;
    const char* b = p->b;
    int r = (o->*fn)(a, b);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method2<CSPManager, int, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1dfd10)
#endif


// 0x001dfdb0 Method2<CSPManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x001dfdb0.cpp
// sym: ??_G?$Method2@VCSPManager@@XPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSPManager, void, const char *, int>::~Method2() {}


// 0x001dfdd0 Method2<CSPManager,void,const_char_*,int>::vfunc_2 (23 B): matches/0x001dfdd0.cpp
// sym: ?vfunc_2@?$Method2@VCSPManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CSPManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1dfdd0* m = (CFEManager_1dfdd0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1dfdd0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CSPManager, void, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1dfdb0)
#endif


// 0x001dfe30 Method1<CSPManager,void,float>::vfunc_0 (30 B): matches/0x001dfe30.cpp
// sym: ??_G?$Method1@VCSPManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSPManager, void, float>::~Method1() {}


// 0x001dfe50 Method1<CSPManager,void,float>::vfunc_2 (19 B): matches/0x001dfe50.cpp
// sym: ?vfunc_2@?$Method1@VCSPManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSPManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1dfe50* d = (Dummy_1dfe50*)a;
    (d->*(*(void (Dummy_1dfe50::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSPManager, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1dfe30)
#endif

namespace fn_f75938cb {

// 0x001dfe70 FUN_001dfe70 (115 B): matches/0x001dfe70.cpp
// sym: ?Init@Method5_1dfe70@fn_f75938cb@@QAEPAV12@PAX0@Z
// FUN_001dfe70 @ 0x001dfe70
Method5_1dfe70* Method5_1dfe70::Init(void* arg, void* value) {
    FUN_001d0480(arg, 5);
    vptr = (hulk_intptr)DAT_00423368;
    p1c = value;
    b18 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b10 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    b11 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    b12 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    b13 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    b14 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    return this;
}

} // namespace fn_f75938cb

// 0x001dfef0 Method5<CSPManager,bool,const_char_*,const_char_*,int,float,const_char_*>::vfunc_0 (30 B): matches/0x001dfef0.cpp
// sym: ??_G?$Method5@VCSPManager@@_NPBDPBDHMPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method5<CSPManager, bool, const char *, const char *, int, float, const char *>::~Method5() {}


// 0x001dff10 Method5<CSPManager,bool,const_char_*,const_char_*,int,float,const_char_*>::vfunc_2 (30 B): matches/0x001dff10.cpp
// sym: ?vfunc_2@?$Method5@VCSPManager@@_NPBDPBDHMPBD@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method5<CSPManager, bool, const char *, const char *, int, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001dff30(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method5<CSPManager, bool, const char *, const char *, int, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1dfef0)
#endif


// 0x001dff30 FUN_001dff30 (61 B): equivalent/0x001dff30.cpp [wrapped: conflict: Callback]
// sym: ?FUN_001dff30@fn_001dff30@@YAXPAUContext@1@PBIPAEP6GEIIIII@Z@Z @a7f980522b4d @we903cd7b5c63
namespace fn_001dff30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001dff30 @ 0x001dff30
typedef unsigned int Word;
typedef unsigned char Byte;
struct Context {};
typedef Byte (__stdcall *Callback)(Word, Word, Word, Word, Word);
void __cdecl FUN_001dff30(Context* context, const Word* values, Byte* result, Callback callback)
{
    Byte value = callback(values[0], values[1], values[2], values[3], values[4]);
    if (result) *result = value;
}
} // namespace fn_001dff30


// 0x001dff70 FUN_001dff70 (102 B): matches/0x001dff70.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Method4_1dff70@fn_001dff70@@QAE@HH@Z
namespace fn_001dff70 {

class Function_1dff70 {
  public:
    Function_1dff70(int a, int b);
    virtual void f0();
    char pad[0x0c];
};

class Method4_1dff70 : public Function_1dff70 {
  public:
    Method4_1dff70(hulk_intptr a, hulk_intptr b);
    virtual void f0();
    char m10, m11, m12, m13;
    int m14;
    char m18;
    char m19[3];
    int m1c;
};

extern char GetFlag_001d04d0(const char* s);

void Method4_1dff70::f0() {}

Method4_1dff70::Method4_1dff70(hulk_intptr a, hulk_intptr b) : Function_1dff70(a, 4) {
    m1c = b;
    m18 = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    m10 = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    m11 = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    m12 = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    m13 = GetFlag_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}
} // namespace fn_001dff70


// 0x001dffe0 Method4<CSPManager,void,int,float,float,float>::vfunc_0 (30 B): matches/0x001dffe0.cpp
// sym: ??_G?$Method4@VCSPManager@@XHMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CSPManager, void, int, float, float, float>::~Method4() {}


// 0x001e0000 Method4<CSPManager,void,int,float,float,float>::vfunc_2 (46 B): matches/0x001e0000.cpp
// sym: ?vfunc_2@?$Method4@VCSPManager@@XHMMM@@UAEXPAX00@Z
template <> void Method4<CSPManager, void, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0000 * manager = (CSPManager_1e0000 *)__p0; Arguments * arguments = (Arguments *)__p1; void * unused = (void *)__p2;

    int* p = (int*)arguments;
    int id = *p++;
    float first = *(float*)p++;
    float second = *(float*)p++;
    float third = *(float*)p++;
    (manager->*(*(void (CSPManager_1e0000::**)(int, float, float, float))&this->f_1c))(id, first, second, third);
}
#if defined(HULK_PTR64)
template class Method4<CSPManager, void, int, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1dffe0)
#endif

namespace fn_f75938cb {

// 0x001e0030 FUN_001e0030 (115 B): matches/0x001e0030.cpp
// sym: ?Init@Method5_1e0030@fn_f75938cb@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
// FUN_001e0030 @ 0x001e0030
Method5_1e0030* Method5_1e0030::Init(const char* arg, ScriptMemberFn value) {
    FUN_001d0480(arg, 5);
    vptr = (hulk_intptr)DAT_00423388;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    return this;
}

} // namespace fn_f75938cb

// 0x001e00b0 Method5<CSPManager,void,int,float,float,float,const_char_*>::vfunc_0 (30 B): matches/0x001e00b0.cpp
// sym: ??_G?$Method5@VCSPManager@@XHMMMPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method5<CSPManager, void, int, float, float, float, const char *>::~Method5() {}


// 0x001e00d0 Method5<CSPManager,void,int,float,float,float,const_char_*>::vfunc_2 (30 B): matches/0x001e00d0.cpp
// sym: ?vfunc_2@?$Method5@VCSPManager@@XHMMMPBD@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method5<CSPManager, void, int, float, float, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001e00f0(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method5<CSPManager, void, int, float, float, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e00b0)
#endif


// 0x001e00f0 FUN_001e00f0 (56 B): equivalent/0x001e00f0.cpp [wrapped: conflict: Callback]
// sym: ?FUN_001e00f0@fn_001e00f0@@YAXPAUCallbackTarget@1@PBIIP821@AEXIIIII@Z@Z @90a47938d0a5 @w83c856a5e08e
namespace fn_001e00f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e00f0 @ 0x001e00f0
struct CallbackTarget;
typedef void (CallbackTarget::*Callback)(unsigned, unsigned, unsigned, unsigned, unsigned);
struct CallbackTarget {};
void __cdecl FUN_001e00f0(CallbackTarget *target, const unsigned *values, unsigned unused, Callback callback)
{
    (target->*callback)(values[0], values[1], values[2], values[3], values[4]);
}
} // namespace fn_001e00f0


// 0x001e0130 FUN_001e0130 (89 B): matches/0x001e0130.cpp [wrapped: conflict: CSPManager]
// sym: ??0Method3_1e0130@fn_001e0130@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e0130 {

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

extern "C" char DAT_00423398[];
class CSPManager {};
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Method3_1e0130 : public FUN_001d0480 {
  public:
    void* vf;
    ScriptFunctionFields f;
    ScriptMemberFn mgr;
    Method3_1e0130(const char*, ScriptMemberFn);
};
Method3_1e0130::Method3_1e0130(const char* a, ScriptMemberFn c) : FUN_001d0480(a, 3) {
    vf = (void*)((hulk_intptr)DAT_00423398);
    mgr = c;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    f.argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e128));
}
} // namespace fn_001e0130
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e0190 Method3<CSPManager,void,const_char_*,bool,float>::vfunc_0 (30 B): matches/0x001e0190.cpp
// sym: ??_G?$Method3@VCSPManager@@XPBD_NM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CSPManager, void, const char *, bool, float>::~Method3() {}
#if defined(HULK_PTR64)
template class Method3<CSPManager, void, const char *, bool, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0190)
#endif


// 0x001e01b0 Method3<CSPManager,void,const_char_*,bool,float>::vfunc_2 (30 B): equivalent/0x001e01b0.cpp [wrapped: conflict: Args; CSPManager; Method3]
// sym: ?vfunc_2@Method3@fn_001e01b0@@UAEXPAUCSPManager@2@PAUArgs@2@PAX@Z @6d6a1f4b3dc3 @w9701e43e3e04
namespace fn_001e01b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSPManager,void,const_char_*,bool,float>::vfunc_2 @ 0x001e01b0
struct Args { const char* text; unsigned char flag; char pad[3]; float value; };
struct CSPManager { void FUN_001e01b0(const char*,unsigned char,float); };
struct Method3 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(CSPManager*,Args*,void*); char pad[24]; void (CSPManager::*callback)(const char*,unsigned char,float); };
void Method3::vfunc_2(CSPManager* manager, Args* args, void* extra) { (manager->*callback)(args->text,args->flag,args->value); }
} // namespace fn_001e01b0


// 0x001e0210 Method1<CSPManager,math::Vector,const_char_*>::vfunc_0 (30 B): matches/0x001e0210.cpp
// sym: ??_G?$Method1@VCSPManager@@VVector@math@@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSPManager,math::Vector, const char *>::~Method1() {}


// 0x001e0230 Method1<CSPManager,math::Vector,const_char_*>::vfunc_2 (69 B): equivalent/0x001e0230.cpp
// sym: ?vfunc_2@?$Method1@VCSPManager@@VVector@math@@PBD@@UAEXPAX00@Z @97077a2a52c1 @wec1d426c7e71
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method1<CSPManager,math::Vector,const_char_*>::vfunc_2 @ 0x001e0230
template <> void Method1<CSPManager,math::Vector, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0230 * manager = (CSPManager_1e0230 *)__p0; const char ** name = (const char **)__p1; Vector_1e0230 * output = (Vector_1e0230 *)__p2;

 Vector_1e0230 value = (manager->*(*(Vector_1e0230 (CSPManager_1e0230::**)(const char *))&this->f_1c))(*name);
 if (output) *output = value;
}
#if defined(HULK_PTR64)
template class Method1<CSPManager,math::Vector, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0210)
#endif


// 0x001e02d0 Method2<CSPManager,bool,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x001e02d0.cpp
// sym: ??_G?$Method2@VCSPManager@@_NPBDVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSPManager, bool, const char *,math::Vector>::~Method2() {}
#if defined(HULK_PTR64)
template class Method2<CSPManager, bool, const char *,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e02d0)
#endif


// 0x001e02f0 Method2<CSPManager,bool,const_char_*,math::Vector>::vfunc_2 (58 B): equivalent/0x001e02f0.cpp [wrapped: conflict: Args; CSPManager; Function; Method2]
// sym: ?vfunc_2@Method2@fn_001e02f0@@QAEXPAUCSPManager@2@PBUArgs@2@PA_N@Z @5070c124e04e @w66fe1ac90c4f
namespace fn_001e02f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CSPManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x001e02f0
namespace math { struct Vector { float x, y, z; }; }
struct CSPManager { };
struct Args { const char *name; math::Vector position; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };
struct Method2 : Function {
    char pad[0x1c - sizeof(Function)];
    bool (CSPManager::*method)(const char *, math::Vector);
    void vfunc_2(CSPManager *manager, const Args *args, bool *result);
};
void Method2::vfunc_2(CSPManager *manager, const Args *args, bool *result) {
    bool value = (manager->*method)(args->name, args->position);
    if (result) *result = value;
}
} // namespace fn_001e02f0


// 0x001e0370 Method1<CSPManager,float,const_char_*>::vfunc_0 (30 B): matches/0x001e0370.cpp
// sym: ??_G?$Method1@VCSPManager@@MPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSPManager, float, const char *>::~Method1() {}


// 0x001e0390 Method1<CSPManager,float,const_char_*>::vfunc_2 (42 B): matches/0x001e0390.cpp
// sym: ?vfunc_2@?$Method1@VCSPManager@@MPBD@@UAEXPAX00@Z
// Same code shape as 0x0002c760 (propagated; names are from that function)
template <> void Method1<CSPManager, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1e0390 * a = (CActorManager_1e0390 *)__p0; const char ** p = (const char **)__p1; float * out = (float *)__p2;

    Fn_1e0390 f = (*(Fn_1e0390 *)&this->f_1c);
    const char* s = *p;
    float x = (a->*f)(s);
    if (out)
        *out = x;
}
#if defined(HULK_PTR64)
template class Method1<CSPManager, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0370)
#endif


// 0x001e03c0 FUN_001e03c0 (128 B): matches/0x001e03c0.cpp [wrapped: conflict: Method6]
// sym: ??0Method6@fn_001e03c0@@QAE@HH@Z
namespace fn_001e03c0 {

struct Function_1e03c0 {
    Function_1e03c0(int a, int b);
    virtual void F0();
    int pad[3];
};

char ParseArg_001d04d0(const char* s);

struct Method6 : Function_1e03c0 {
    Method6(hulk_intptr a, hulk_intptr b);
    virtual void F0();
    char c10, c11, c12, c13, c14, c15;
    char pad16[2];
    char c18;
    char pad19[3];
    int m1c;
};

Method6::Method6(hulk_intptr a, hulk_intptr b) : Function_1e03c0(a, 6) {
    m1c = b;
    c18 = ParseArg_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    c10 = ParseArg_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    c11 = ParseArg_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    c12 = ParseArg_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    c13 = ParseArg_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    c14 = ParseArg_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    c15 = ParseArg_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}
} // namespace fn_001e03c0


// 0x001e0440 Method6<CSPManager,void,const_char_*,int,float,float,float,float>::vfunc_0 (30 B): matches/0x001e0440.cpp
// sym: ??_G?$Method6@VCSPManager@@XPBDHMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CSPManager, void, const char *, int, float, float, float, float>::~Method6() {}


// 0x001e0460 Method6<CSPManager,void,const_char_*,int,float,float,float,float>::vfunc_2 (30 B): matches/0x001e0460.cpp
// sym: ?vfunc_2@?$Method6@VCSPManager@@XPBDHMMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CSPManager, void, const char *, int, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001e0480(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CSPManager, void, const char *, int, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0440)
#endif

namespace fn_f75938cb {

// 0x001e0480 FUN_001e0480 (66 B): matches/0x001e0480.cpp
// sym: ?invoke@fn_f75938cb@@YAXPAVC@1@PAHHP821@AEXHHHHHH@Z@Z
void invoke(C* obj, int* p, int b, CB fn) {
    int x0 = *p++;
    int x1 = *p++;
    volatile int x2 = *p++;
    volatile int x3 = *p++;
    (obj->*fn)(x0, x1, x2, x3, p[0], p[1]);
}

} // namespace fn_f75938cb

// 0x001e0510 Method1<CSPManager,bool,const_char_*>::vfunc_0 (30 B): matches/0x001e0510.cpp
// sym: ??_G?$Method1@VCSPManager@@_NPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSPManager, bool, const char *>::~Method1() {}


// 0x001e0530 Method1<CSPManager,bool,const_char_*>::vfunc_2 (29 B): matches/0x001e0530.cpp
// sym: ?vfunc_2@?$Method1@VCSPManager@@_NPBD@@UAEXPAX00@Z
template <> void Method1<CSPManager, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0530 * obj = (CSPManager_1e0530 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CSPManager_1e0530::*f)(const char*) = (*(bool (CSPManager_1e0530::**)(const char *))&this->f_1c);
    const char* a = *arg;
    bool r = (obj->*f)(a);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CSPManager, bool, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0510)
#endif

namespace fn_f75938cb {

// 0x001e0550 FUN_001e0550 (115 B): matches/0x001e0550.cpp
// sym: ?Make@Method5_1e0550@fn_f75938cb@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
Method5_1e0550* Method5_1e0550::Make(const char* p, ScriptMemberFn x) {
    Init_001d0480(p, 5);
    v = ((hulk_intptr)DAT_004233f8);
    m1c = x;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[4] = FUN_001d04d0(((char*)&DAT_0048e128));
    return this;
}

} // namespace fn_f75938cb

// 0x001e05d0 Method5<CSPManager,void,const_char_*,const_char_*,float,float,float>::vfunc_0 (30 B): matches/0x001e05d0.cpp
// sym: ??_G?$Method5@VCSPManager@@XPBDPBDMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method5<CSPManager, void, const char *, const char *, float, float, float>::~Method5() {}


// 0x001e05f0 Method5<CSPManager,void,const_char_*,const_char_*,float,float,float>::vfunc_2 (30 B): matches/0x001e05f0.cpp
// sym: ?vfunc_2@?$Method5@VCSPManager@@XPBDPBDMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method5<CSPManager, void, const char *, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001e0610(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method5<CSPManager, void, const char *, const char *, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e05d0)
#endif


// 0x001e0610 FUN_001e0610 (50 B): equivalent/0x001e0610.cpp [wrapped: conflict: Callback]
// sym: ?target@fn_001e0610@@YAXPAUObj@1@PBUParams@1@PAXP821@AEXIIIII@Z@Z @90a47938d0a5 @w83c856a5e08e
namespace fn_001e0610 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e0610 @ 0x001e0610
struct Params { unsigned int a,b,c,d,e; };
struct Obj { void FUN_001e0610(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); };
typedef void (Obj::*Callback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void __cdecl target(Obj* object, const Params* values, void* unused, Callback callback)
{
    (object->*callback)(values->a, values->b, values->c, values->d, values->e);
}
} // namespace fn_001e0610


// 0x001e0650 FUN_001e0650 (89 B): matches/0x001e0650.cpp [wrapped: conflict: Method3]
// sym: ??0Method3@fn_001e0650@@QAE@PBDPAX@Z
namespace fn_001e0650 {

class CSPManager;
class Function_1e0650 {
  public:
    virtual void* basefn_001e06b0(int);
    Function_1e0650(const char*, int);
};
class Method3 : public Function_1e0650 {
  public:
    virtual bool dummy_001d04c0(int, int);
    Method3(const char*, void*);
    char pad[0x0c];
    char a, b, c;
    char pad2[5];
    char d;
    char pad3[3];
    void* x;
};
extern const char hulk_at_0048e10c[];
extern char fun_001d04d0(const char*);
Method3::Method3(const char* s, void* p) : Function_1e0650(s, 3) {
    x = p;
    d = fun_001d04d0(((const char*)&DAT_0048e100));
    a = fun_001d04d0(((const char*)&DAT_0048e0f0));
    b = fun_001d04d0(((const char*)&DAT_0048e0f0));
    c = fun_001d04d0(hulk_at_0048e10c);
}
} // namespace fn_001e0650


// 0x001e06b0 Method3<CSPManager,void,const_char_*,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x001e06b0.cpp
// sym: ??_G?$Method3@VCSPManager@@XPBDPBDVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CSPManager, void, const char *, const char *,math::Vector>::~Method3() {}


// 0x001e06d0 Method3<CSPManager,void,const_char_*,const_char_*,math::Vector>::vfunc_2 (57 B): matches/0x001e06d0.cpp
// sym: ?vfunc_2@?$Method3@VCSPManager@@XPBDPBDVVector@math@@@@UAEXPAX00@Z
template <> void Method3<CSPManager, void, const char *, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e06d0 * obj = (CSPManager_1e06d0 *)__p0; void * raw = (void *)__p1;

    const char** p = (const char**)raw;
    const char* a = *p++;
    const char* b = *p++;
    math::Vector_1e06d0 v = *(math::Vector_1e06d0*)p;
    (obj->*(*(void (CSPManager_1e06d0::**)(const char *, const char *, math::Vector_1e06d0))&this->f_1c))(a, b, v);
}
#if defined(HULK_PTR64)
template class Method3<CSPManager, void, const char *, const char *,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e06b0)
#endif

namespace fn_f75938cb {

// 0x001e0710 FUN_001e0710 (102 B): matches/0x001e0710.cpp
// sym: ??0Method4_1e0710@fn_f75938cb@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
Method4_1e0710::Method4_1e0710(const char* s, ScriptMemberFn m) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(s, 4);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00423418);
    mgr = m;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
}

} // namespace fn_f75938cb

// 0x001e0780 Method4<CSPManager,void,const_char_*,const_char_*,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x001e0780.cpp
// sym: ??_G?$Method4@VCSPManager@@XPBDPBDVVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CSPManager, void, const char *, const char *,math::Vector,math::Vector>::~Method4() {}


// 0x001e07a0 Method4<CSPManager,void,const_char_*,const_char_*,math::Vector,math::Vector>::vfunc_2 (106 B): matches/0x001e07a0.cpp
// sym: ?vfunc_2@?$Method4@VCSPManager@@XPBDPBDVVector@math@@V23@@@UAEXPAX00@Z
template <> void Method4<CSPManager, void, const char *, const char *,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CAmbientsManager_1e07a0 * o = (CAmbientsManager_1e07a0 *)__p0; char * a = (char *)__p1; hulk_intptr u = (hulk_intptr)__p2;

    char* p = a;
    const char* s = *(const char**)p;
    p += 4;
    int i = *(int*)p;
    p += 4;
    math::Vector_1e07a0 va = *(math::Vector_1e07a0*)p;
    p += 12;
    math::Vector_1e07a0 vb = *(math::Vector_1e07a0*)p;
    (o->*(*(void (CAmbientsManager_1e07a0::**)(const char *, int, const math::Vector_1e07a0, const math::Vector_1e07a0))&this->f_1c))(s, i, va, vb);
}
#if defined(HULK_PTR64)
template class Method4<CSPManager, void, const char *, const char *,math::Vector,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0780)
#endif


// 0x001e0860 Method2<CSPManager,bool,math::Vector,float>::vfunc_0 (30 B): matches/0x001e0860.cpp
// sym: ??_G?$Method2@VCSPManager@@_NVVector@math@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSPManager, bool,math::Vector, float>::~Method2() {}


// 0x001e0880 Method2<CSPManager,bool,math::Vector,float>::vfunc_2 (57 B): matches/0x001e0880.cpp
// sym: ?vfunc_2@?$Method2@VCSPManager@@_NVVector@math@@M@@UAEXPAX00@Z
template <> void Method2<CSPManager, bool,math::Vector, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0880 * obj = (CSPManager_1e0880 *)__p0; Arg_1e0880 * a = (Arg_1e0880 *)__p1; bool * out = (bool *)__p2;

    bool (CSPManager_1e0880::*fn)(Vector_1e0880, float) = (*(bool (CSPManager_1e0880::**)(Vector_1e0880, float))&this->f_1c);
    Vector_1e0880 v = a->v;
    float f = a->f;
    bool r = (obj->*fn)(v, f);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method2<CSPManager, bool,math::Vector, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0860)
#endif

namespace fn_f75938cb {

// 0x001e08c0 FUN_001e08c0 (102 B): matches/0x001e08c0.cpp
// sym: ?Init@Method4_1e08c0@fn_f75938cb@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
Method4_1e08c0* Method4_1e08c0::Init(const char* p, ScriptMemberFn b) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(p, 4);
    vtable = ((hulk_intptr)DAT_00423438);
    field1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_f75938cb

// 0x001e0930 Method4<CSPManager,bool,float,float,float,float>::vfunc_0 (30 B): matches/0x001e0930.cpp
// sym: ??_G?$Method4@VCSPManager@@_NMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CSPManager, bool, float, float, float, float>::~Method4() {}


// 0x001e0950 Method4<CSPManager,bool,float,float,float,float>::vfunc_2 (30 B): matches/0x001e0950.cpp
// sym: ?vfunc_2@?$Method4@VCSPManager@@_NMMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method4<CSPManager, bool, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001e0970(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method4<CSPManager, bool, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0930)
#endif


// 0x001e0970 FUN_001e0970 (75 B): equivalent/0x001e0970.cpp [wrapped: conflict: Callback]
// sym: ?FUN_001e0970@fn_001e0970@@YAXIPAIPAEP6GE1III@Z@Z @c55eb241873c @w199094e1ec19
namespace fn_001e0970 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001e0970 @ 0x001e0970
typedef unsigned char (__stdcall *Callback)(unsigned char *, unsigned int, unsigned int, unsigned int);
void __cdecl FUN_001e0970(unsigned int unused, unsigned int *values, unsigned char *output, Callback callback)
{
    unsigned char result = callback((unsigned char *)values[0], values[1], values[2], values[3]);
    if (output != 0)
        *output = result;
}
} // namespace fn_001e0970


// 0x001e0a00 Method0<CSPManager,int>::vfunc_0 (30 B): matches/0x001e0a00.cpp
// sym: ??_G?$Method0@VCSPManager@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CSPManager, int>::~Method0() {}


// 0x001e0a20 Method0<CSPManager,int>::vfunc_2 (22 B): matches/0x001e0a20.cpp
// sym: ?vfunc_2@?$Method0@VCSPManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
template <> void Method0<CSPManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)&this->f_1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
#if defined(HULK_PTR64)
template class Method0<CSPManager, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0a00)
#endif


// 0x001e0a80 Method1<CSPManager,void,bool>::vfunc_0 (30 B): matches/0x001e0a80.cpp
// sym: ??_G?$Method1@VCSPManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSPManager, void, bool>::~Method1() {}


// 0x001e0aa0 Method1<CSPManager,void,bool>::vfunc_2 (21 B): matches/0x001e0aa0.cpp
// sym: ?vfunc_2@?$Method1@VCSPManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<CSPManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1e0aa0 * obj = (CActorManager_1e0aa0 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_1e0aa0 *)&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSPManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0a80)
#endif

namespace fn_f75938cb {

// 0x001e0ac0 FUN_001e0ac0 (89 B): matches/0x001e0ac0.cpp
// sym: ?Run@Method3_1e0ac0@fn_f75938cb@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
Method3_1e0ac0* Method3_1e0ac0::Run(const char* a, ScriptMemberFn b) {
    Init_001d0480(a, 3);
    x = ((hulk_intptr)DAT_00423468);
    m1c = b;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e134));
    f.argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    return this;
}

} // namespace fn_f75938cb

// 0x001e0b20 Method3<CSPManager,void,int,int,const_char_*>::vfunc_0 (30 B): matches/0x001e0b20.cpp
// sym: ??_G?$Method3@VCSPManager@@XHHPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CSPManager, void, int, int, const char *>::~Method3() {}


// 0x001e0b40 Method3<CSPManager,void,int,int,const_char_*>::vfunc_2 (29 B): equivalent/0x001e0b40.cpp
// sym: ?vfunc_2@?$Method3@VCSPManager@@XHHPBD@@UAEXPAX00@Z @a7a6d240b96d @w2ac42a573389
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSPManager,void,int,int,const_char_*>::vfunc_2 @ 0x001e0b40
template <> void Method3<CSPManager, void, int, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0b40 * object = (CSPManager_1e0b40 *)__p0; const int * args = (const int *)__p1; void * unused = (void *)__p2;

    (object->*(*(void (CSPManager_1e0b40::**)(int, int, const char *))&this->f_1c))(args[0], args[1], (const char *)args[2]);
}
#if defined(HULK_PTR64)
template class Method3<CSPManager, void, int, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0b20)
#endif

namespace fn_f75938cb {

// 0x001e0b60 FUN_001e0b60 (89 B): matches/0x001e0b60.cpp
// sym: ??0Method3_1e0b60@fn_f75938cb@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
Method3_1e0b60::Method3_1e0b60(const char* x, ScriptMemberFn y) {
    Init_001d0480(x, 3);
    m0 = ((hulk_intptr)DAT_00423478);
    m1c = y;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
}

} // namespace fn_f75938cb

// 0x001e0bc0 Method3<CSPManager,void,float,float,float>::vfunc_0 (30 B): matches/0x001e0bc0.cpp
// sym: ??_G?$Method3@VCSPManager@@XMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CSPManager, void, float, float, float>::~Method3() {}


// 0x001e0be0 Method3<CSPManager,void,float,float,float>::vfunc_2 (35 B): equivalent/0x001e0be0.cpp
// sym: ?vfunc_2@?$Method3@VCSPManager@@XHHPBD@@UAEXPAX00@Z @a7a6d240b96d @w2ac42a573389
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CSPManager,void,float,float,float>::vfunc_2 @ 0x001e0be0
template <> void Method3<CSPManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0be0 * manager = (CSPManager_1e0be0 *)__p0; Triple * values = (Triple *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CSPManager_1e0be0::**)(float, float, float))&this->f_1c))(values->x, values->y, values->z);
}
#if defined(HULK_PTR64)
template class Method3<CSPManager, void, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0bc0)
#endif


// 0x001e0c60 Method2<CSPManager,bool,const_char_*,float>::vfunc_0 (30 B): matches/0x001e0c60.cpp
// sym: ??_G?$Method2@VCSPManager@@_NPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSPManager, bool, const char *, float>::~Method2() {}


// 0x001e0c80 Method2<CSPManager,bool,const_char_*,float>::vfunc_2 (37 B): matches/0x001e0c80.cpp
// sym: ?vfunc_2@?$Method2@VCSPManager@@_NPBDM@@UAEXPAX00@Z
template <> void Method2<CSPManager, bool, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0c80 * obj = (CSPManager_1e0c80 *)__p0; Args * a = (Args *)__p1; bool * out = (bool *)__p2;

    bool (CSPManager_1e0c80::*fn)(const char*, float) = (*(bool (CSPManager_1e0c80::**)(const char *, float))&this->f_1c);
    const char* name = a->name;
    float val = a->val;
    bool result = (obj->*fn)(name, val);
    if (out)
        *out = result;
}
#if defined(HULK_PTR64)
template class Method2<CSPManager, bool, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0c60)
#endif

namespace fn_f75938cb {

// 0x001e0cb0 FUN_001e0cb0 (102 B): matches/0x001e0cb0.cpp
// sym: ?FUN_001e0cb0@Method4_1e0cb0@fn_f75938cb@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
// FUN_001e0cb0 @ 0x001e0cb0
Method4_1e0cb0* Method4_1e0cb0::FUN_001e0cb0(const char* name, ScriptMemberFn m) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (hulk_intptr)DAT_00423498;
    fn = m;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e0e4));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e134));
    return this;
}

} // namespace fn_f75938cb

// 0x001e0d20 Method4<CSPManager,bool,const_char_*,float,float,int>::vfunc_0 (30 B): matches/0x001e0d20.cpp
// sym: ??_G?$Method4@VCSPManager@@_NPBDMMH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CSPManager, bool, const char *, float, float, int>::~Method4() {}


// 0x001e0d40 Method4<CSPManager,bool,const_char_*,float,float,int>::vfunc_2 (30 B): matches/0x001e0d40.cpp
// sym: ?vfunc_2@?$Method4@VCSPManager@@_NPBDMMH@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method4<CSPManager, bool, const char *, float, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001e0d60(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method4<CSPManager, bool, const char *, float, float, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0d20)
#endif


// 0x001e0d60 FUN_001e0d60 (58 B): equivalent/0x001e0d60.cpp [wrapped: conflict: Arguments; Callback]
// sym: ?FUN_001e0d60@fn_001e0d60@@YAXPAXPBUArguments@1@PAEP6GEIIII@Z@Z @c55eb241873c @w199094e1ec19
namespace fn_001e0d60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001e0d60 @ 0x001e0d60
struct Arguments { unsigned int first; unsigned int second; unsigned int third; unsigned int fourth; };
typedef unsigned char (__stdcall *Callback)(unsigned int, unsigned int, unsigned int, unsigned int);
void __cdecl FUN_001e0d60(void* object, const Arguments* args, unsigned char* result, Callback method)
{
    unsigned char value = method(args->first, args->second, args->third, args->fourth);
    if (result) *result = value;
}
} // namespace fn_001e0d60


// 0x001e0de0 Method1<CSPManager,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001e0de0.cpp
// sym: ??_G?$Method1@VCSPManager@@PBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSPManager, const char *, const char *>::~Method1() {}


// 0x001e0e00 Method1<CSPManager,const_char_*,const_char_*>::vfunc_2 (29 B): matches/0x001e0e00.cpp
// sym: ?vfunc_2@?$Method1@VCSPManager@@PBDPBD@@UAEXPAX00@Z
template <> void Method1<CSPManager, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0e00 * a = (CSPManager_1e0e00 *)__p0; const char ** b = (const char **)__p1; void ** out = (void **)__p2;

    void* (CSPManager_1e0e00::*f)(const char*) = (*(void *(CSPManager_1e0e00::**)(const char *))&this->f_1c);
    const char* arg = *b;
    void* result = (a->*f)(arg);
    if (out)
        *out = result;
}
#if defined(HULK_PTR64)
template class Method1<CSPManager, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0de0)
#endif


// 0x001e0e70 Method2<CSPManager,void,const_char_*,float>::vfunc_0 (30 B): matches/0x001e0e70.cpp
// sym: ??_G?$Method2@VCSPManager@@XPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CSPManager, void, const char *, float>::~Method2() {}


// 0x001e0e90 Method2<CSPManager,void,const_char_*,float>::vfunc_2 (23 B): matches/0x001e0e90.cpp
// sym: ?vfunc_2@?$Method2@VCSPManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CSPManager, void, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1e0e90* m = (CFEManager_1e0e90*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1e0e90::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CSPManager, void, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0e70)
#endif

namespace fn_f75938cb {

// 0x001e0eb0 FUN_001e0eb0 (128 B): matches/0x001e0eb0.cpp
// sym: ??0Method6_1e0eb0@fn_f75938cb@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
Method6_1e0eb0::Method6_1e0eb0(const char* a, ScriptMemberFn b) : FUN_001d0480(a, 6) {
    vp = ((hulk_intptr)DAT_004234c8);
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[5] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
}

} // namespace fn_f75938cb

// 0x001e0f30 Method6<CSPManager,void,int,float,float,float,float,int>::vfunc_0 (30 B): matches/0x001e0f30.cpp
// sym: ??_G?$Method6@VCSPManager@@XHMMMMH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CSPManager, void, int, float, float, float, float, int>::~Method6() {}


// 0x001e0f50 Method6<CSPManager,void,int,float,float,float,float,int>::vfunc_2 (30 B): matches/0x001e0f50.cpp
// sym: ?vfunc_2@?$Method6@VCSPManager@@XHMMMMH@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CSPManager, void, int, float, float, float, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_001e0f70(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CSPManager, void, int, float, float, float, float, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e0f30)
#endif


// 0x001e0f70 FUN_001e0f70 (75 B): equivalent/0x001e0f70.cpp [wrapped: conflict: Callback]
// sym: ?FUN_001e0f70@fn_001e0f70@@YAXIPBIIP6GXIIIIII@Z@Z @7714bd012fdc @w65626380b34f
namespace fn_001e0f70 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e0f70 @ 0x001e0f70
typedef void (__stdcall *Callback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void __cdecl FUN_001e0f70(unsigned int unused, const unsigned int *values, unsigned int unused2, Callback callback)
{
    callback(values[0], values[1], values[2], values[3], values[4], values[5]);
}
} // namespace fn_001e0f70

namespace fn_f75938cb {

// 0x001e0fc0 FUN_001e0fc0 (128 B): equivalent/0x001e0fc0.cpp
// sym: ?FUN_001e0fc0@fn_f75938cb@@YAXPAURecord_1e0fc0@1@0@Z @bb299afccda8 @w16c5aed51c51
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e0fc0 @ 0x001e0fc0
// 0x001e0fc0: swap two 20-byte records
void FUN_001e0fc0(Record_1e0fc0* x, Record_1e0fc0* y)
{
    Record_1e0fc0 t = *x;
    *x = *y;
    *y = t;
}


// 0x001e1040 FUN_001e1040 (225 B): equivalent/0x001e1040.cpp
// sym: ?FUN_001e1040@fn_f75938cb@@YAXPAUEntry_1e1040@1@HHU21@@Z @c3b01c5667ee @wb99f64d6fd3f
// STATUS: equivalent (tools/equiv.py level 3: 1134 inputs, branch coverage 8/8)
// FUN_001e1040 @ 0x001e1040
void __cdecl FUN_001e1040(Entry_1e1040* entries, int hole, hulk_intptr count, Entry_1e1040 value) {
 int start=hole;
 int child=2*hole+2;
 while(child<count) {
  if (entries[child].priority < entries[child-1].priority) --child;
  entries[hole].a=entries[child].a;
  entries[hole].b=entries[child].b;
  entries[hole].c=entries[child].c;
  entries[hole].priority=entries[child].priority;
  entries[hole].d=entries[child].d;
  entries[hole].e=entries[child].e;
  hole=child;
  child=2*child+2;
 }
 if(child==count) {
  entries[hole].a=entries[count-1].a;
  entries[hole].b=entries[count-1].b;
  entries[hole].c=entries[count-1].c;
  entries[hole].priority=entries[count-1].priority;
  entries[hole].d=entries[count-1].d;
  entries[hole].e=entries[count-1].e;
  hole=count-1;
 }
 FUN_001de140(entries,hole,start,value);
}


// 0x001e1150 FUN_001e1150 (121 B): matches/0x001e1150.cpp
// sym: _FUN_001e1150
extern "C" void __cdecl FUN_001e1150(S_1e1150* src, S_1e1150* end, S_1e1150* dst, T_1e1150 t) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    FUN_001e1040(src, 0, end - src, t);
}

} // namespace fn_f75938cb

// 0x001e11d0 FUN_001e11d0 (140 B): matches/0x001e11d0.cpp
// sym: ?FUN_001e11d0@Obj_1e11d0@owners@@QAEXXZ
void owners::Obj_1e11d0::FUN_001e11d0() {
    memset((char*)this + 8, 0, 0x600);
    char* s = (char*)this + 0x1ed68;
    int i;
    for (i = 0; i < 16; ++i) {
        ((owners::Target_27b040 *)(((Elem_1e11d0*)(s - 8))))->FUN_0027b040((hulk_uintptr)0);
        *(int*)s = 0;
        *(int*)(s + 4) = 0;
        *(int*)(s + 8) = 0xff;
        s += 0x18;
    }
    Dec();
    Df();
    *(int*)((char*)this + 0x1e82c) = 0;
    *(int*)((char*)this + 0x1e828) = 0;
    char* t = (char*)this + 0x1e840;
    int j, k;
    for (j = 0; j < 4; ++j)
        for (k = 0; k < 32; ++k) {
            ((owners::Target_27b040 *)(((Elem_1e11d0*)t)))->FUN_0027b040((hulk_uintptr)0);
            t += 8;
        }
}


// 0x001e12b0 FUN_001e12b0 (109 B): equivalent/0x001e12b0.cpp [wrapped: conflict: Function1]
// sym: ?FUN_001e12b0@Registry_1e12b0@fn_001e12b0@@QAEXPBDP6AXM@Z@Z @597a1c832b39 @w86f449ed52f3
namespace fn_001e12b0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001e12b0 @ 0x001e12b0
// FUN_001e12b0 @ 0x001e12b0  (generated by work/closure/gen.py)
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



// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1e12b0 : public ScriptFunctionFields {
  public:
    virtual void* m0_001df6b0(int);
    MethodBase_1e12b0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class R, class A>
class Function1 : public MethodBase_1e12b0 {
  public:
    typedef R (*Fn)(A);
    Function1(const char* name, Fn f) : MethodBase_1e12b0(name, 1) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
    Fn fn;
};

struct Registry_1e12b0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001e12b0(const char* name, void (*fn)(float));
};

void Registry_1e12b0::FUN_001e12b0(const char* name, void (*fn)(float)) {
    typedef Function1<void, float> Closure_t;
    HULK_SIZE32(Closure_t, 0x20);
    void* mem = FUN_0008d690((int)sizeof(Function1<void, float>));
    Function1<void, float>* c = 0;
    if (mem)
        c = new (mem) Function1<void, float>(name, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001e12b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f75938cb {

// 0x001e1320 FUN_001e1320 (76 B): matches/0x001e1320.cpp
// sym: ??0Closure1_1e1320@fn_f75938cb@@QAE@PAXHH@Z
Closure1_1e1320::Closure1_1e1320(void* p, int v, int w) : Method1_1e1320(p, w) {
    y = v;
}

} // namespace fn_f75938cb

// 0x001e1370 Closure1<CSPManager,void,int>::vfunc_0 (30 B): matches/0x001e1370.cpp
// sym: ??_G?$Method2@VCSPManager@@_NPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSPManager, void, int>::~Closure1() {}


// 0x001e1390 Closure1<CSPManager,void,int>::vfunc_2 (18 B): matches/0x001e1390.cpp
// sym: ?vfunc_2@?$Closure1@VCSPManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSPManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1e1390 * *)&this->f_20)->*(*(void (CActorManager_1e1390::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CSPManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1370)
#endif


// 0x001e13e0 Closure3<CSPManager,bool,const_char_*,int,int>::vfunc_0 (30 B): matches/0x001e13e0.cpp
// sym: ??_G?$Method1@VCSPManager@@HPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CSPManager, bool, const char *, int, int>::~Closure3() {}


// 0x001e1400 Closure3<CSPManager,bool,const_char_*,int,int>::vfunc_2 (42 B): equivalent/0x001e1400.cpp
// sym: ?vfunc_2@?$Closure3@VCSPManager@@_NPBDHH@@UAEXPAX00@Z @eec6867036bb @wec43bf295a6c
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure3<CSPManager,bool,const_char_*,int,int>::vfunc_2 @ 0x001e1400
template <> void Closure3<CSPManager, bool, const char *, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arguments * args = (Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CSPManager_1e1400 * *)&this->f_20)->*(*(bool (CSPManager_1e1400::**)(const char *, int, int))&this->f_1c))(args->text, args->a, args->b);
    if (result) *result = value;
}
#if defined(HULK_PTR64)
template class Closure3<CSPManager, bool, const char *, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e13e0)
#endif


// 0x001e1430 FUN_001e1430 (89 B): matches/0x001e1430.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001e1430@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e1430 {
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


extern void* hulk_at_004232c8[2];
extern void* hulk_at_004234f8[2];

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
    vfptr = (void*)hulk_at_004232c8;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e0e4));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e0e4));
    vfptr = (void*)hulk_at_004234f8;
    owner = a2;
}
} // namespace fn_001e1430
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e1490 Closure2<CSPManager,bool,const_char_*,bool>::vfunc_0 (30 B): matches/0x001e1490.cpp
// sym: ??_G?$Method2@VCSPManager@@XPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CSPManager, bool, const char *, bool>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<CSPManager, bool, const char *, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1490)
#endif


// 0x001e14b0 Closure2<CSPManager,bool,const_char_*,bool>::vfunc_2 (46 B): equivalent/0x001e14b0.cpp [wrapped: conflict: Arguments; CSPManager; Closure2]
// sym: ?vfunc_2@Closure2@fn_001e14b0@@UAEXPAXPAUArguments@2@PA_N@Z @8eb15ebc569e @w77c25302b90b
namespace fn_001e14b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,bool,const_char_*,bool>::vfunc_2 @ 0x001e14b0
struct CSPManager {
    bool FUN_001e14b0(const char *text, bool flag);
};
struct Arguments {
    const char *text;
    bool flag;
};
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, Arguments *arguments, bool *result);
    char padding[0x18];
    bool (CSPManager::*method)(const char *, bool);
    CSPManager *object;
};
void Closure2::vfunc_2(void *unused, Arguments *arguments, bool *result)
{
    bool value = (object->*method)(arguments->text, arguments->flag);
    if (result) *result = value;
}
} // namespace fn_001e14b0


// 0x001e14e0 FUN_001e14e0 (89 B): matches/0x001e14e0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001e14e0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e14e0 {
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


extern void* hulk_at_004232d8[2];
extern void* hulk_at_00423508[2];

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
    vfptr = (void*)hulk_at_004232d8;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e0e4));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_00423508;
    owner = a2;
}
} // namespace fn_001e14e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e1540 Closure2<CSPManager,bool,const_char_*,int>::vfunc_0 (30 B): matches/0x001e1540.cpp
// sym: ??_G?$Method2@VCSPManager@@XPBD_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CSPManager, bool, const char *, int>::~Closure2() {}


// 0x001e1560 Closure2<CSPManager,bool,const_char_*,int>::vfunc_2 (36 B): equivalent/0x001e1560.cpp
// sym: ?vfunc_2@?$Closure2@VCSPManager@@_NPBDH@@UAEXPAX00@Z @e654de0dce29 @w4e3d89bebec6
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CSPManager,bool,const_char_*,int>::vfunc_2 @ 0x001e1560
template <> void Closure2<CSPManager, bool, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CSPManager_1e1560 * *)&this->f_20)->*(*(bool (CSPManager_1e1560::**)(const char *, int))&this->f_1c))(args->text, args->number);
    if (result) *result = value;
}
#if defined(HULK_PTR64)
template class Closure2<CSPManager, bool, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1540)
#endif


// 0x001e1590 FUN_001e1590 (76 B): matches/0x001e1590.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001e1590@@QAE@PBDHH@Z
namespace fn_001e1590 {

extern "C++" __declspec(nothrow) unsigned char __cdecl check_001d04d0(const void*);
class Function_1e1590 {
  public:
    virtual void run();
    char pad[0x0c];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    int id;
    Function_1e1590(const char*, int);
};
class Method1 : public Function_1e1590 {
  public:
    virtual void run();
    Method1(const char* name, int key) : Function_1e1590(name, 1) {
        id = key;
        y = check_001d04d0(((char*)&DAT_0048e134));
        x = check_001d04d0(((char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void run();
    int arg;
    Closure1(const char*, int, int);
};
Closure1::Closure1(const char* name, int value, int key) : Method1(name, key) {
    arg = value;
}
} // namespace fn_001e1590


// 0x001e15e0 Closure1<CSPManager,int,const_char_*>::vfunc_0 (30 B): matches/0x001e15e0.cpp
// sym: ??_G?$Method2@VCSPManager@@HPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSPManager, int, const char *>::~Closure1() {}


// 0x001e1600 Closure1<CSPManager,int,const_char_*>::vfunc_2 (30 B): matches/0x001e1600.cpp
// sym: ?vfunc_2@?$Closure1@VCSPManager@@HPBD@@UAEXPAX00@Z
template <> void Closure1<CSPManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    CSPManager_1e1600* o = (*(CSPManager_1e1600 * *)&this->f_20);
    int (CSPManager_1e1600::*f)(const char*) = (*(int (CSPManager_1e1600::**)(const char *))&this->f_1c);
    int r = (o->*f)(*arg);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Closure1<CSPManager, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e15e0)
#endif


// 0x001e1620 FUN_001e1620 (89 B): matches/0x001e1620.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001e1620@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e1620 {
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


extern void* hulk_at_004232f8[2];
extern void* hulk_at_00423528[2];

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
    vfptr = (void*)hulk_at_004232f8;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_00423528;
    owner = a2;
}
} // namespace fn_001e1620
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e1680 Closure2<CSPManager,void,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001e1680.cpp
// sym: ??_G?$Method2@VCSPManager@@HPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CSPManager, void, const char *, const char *>::~Closure2() {}


// 0x001e16a0 Closure2<CSPManager,void,const_char_*,const_char_*>::vfunc_2 (22 B): matches/0x001e16a0.cpp
// sym: ?vfunc_2@?$Closure2@VCSPManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CSPManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1e16a0 * p = (Pair_1e16a0 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1e16a0 * *)&this->f_20)->*(*(void (CActorManager_1e16a0::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CSPManager, void, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1680)
#endif


// 0x001e16c0 FUN_001e16c0 (89 B): matches/0x001e16c0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001e16c0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e16c0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_00423308[2];
extern void* hulk_at_00423538[2];

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
    vfptr = (void*)hulk_at_00423308;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0e4));
    vfptr = (void*)hulk_at_00423538;
    owner = a2;
}
} // namespace fn_001e16c0


// 0x001e1720 Closure2<CSPManager,void,const_char_*,bool>::vfunc_0 (30 B): matches/0x001e1720.cpp
// sym: ??_G?$Method2@VCSPManager@@XPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CSPManager, void, const char *, bool>::~Closure2() {}


// 0x001e1740 Closure2<CSPManager,void,const_char_*,bool>::vfunc_2 (24 B): matches/0x001e1740.cpp
// sym: ?vfunc_2@?$Closure2@VCSPManager@@XPBD_N@@UAEXPAX00@Z
// Same code shape as 0x0002ec60 (propagated; names are from that function)
template <> void Closure2<CSPManager, void, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_1e1740 * p = (Arg_1e1740 *)__p1;

    ((*(Actor_1e1740 * *)&this->f_20)->*(*(void (Actor_1e1740::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}
#if defined(HULK_PTR64)
template class Closure2<CSPManager, void, const char *, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1720)
#endif


// 0x001e1790 Closure6<CSPManager,void,const_char_*,const_char_*,int,const_char_*,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x001e1790.cpp
// sym: ??_G?$Method1@VCSPManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure6<CSPManager, void, const char *, const char *, int, const char *,math::Vector,math::Vector>::~Closure6() {}


// 0x001e17b0 Closure6<CSPManager,void,const_char_*,const_char_*,int,const_char_*,math::Vector,math::Vector>::vfunc_2 (29 B): matches/0x001e17b0.cpp
// sym: ?vfunc_2@?$Closure6@VCSPManager@@XPBDPBDHPBDVVector@math@@V23@@@UAEXPAX00@Z
// Same code shape as 0x0002ebc0 (propagated; names are from that function)
template <> void Closure6<CSPManager, void, const char *, const char *, int, const char *,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; hulk_intptr y = (hulk_intptr)__p1; hulk_intptr z = (hulk_intptr)__p2;

    invoke(this->f_20, y, z, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Closure6<CSPManager, void, const char *, const char *, int, const char *,math::Vector,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1790)
#endif


// 0x001e17d0 FUN_001e17d0 (89 B): matches/0x001e17d0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001e17d0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e17d0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_00423328[2];
extern void* hulk_at_00423558[2];

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
    vfptr = (void*)hulk_at_00423328;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_00423558;
    owner = a2;
}
} // namespace fn_001e17d0


// 0x001e1830 Closure2<CSPManager,int,const_char_*,int>::vfunc_0 (30 B): matches/0x001e1830.cpp
// sym: ??_G?$Method5@VCSPManager@@XHMMMPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CSPManager, int, const char *, int>::~Closure2() {}


// 0x001e1850 Closure2<CSPManager,int,const_char_*,int>::vfunc_2 (36 B): equivalent/0x001e1850.cpp
// sym: ?vfunc_2@?$Closure2@VCSPManager@@HPBDH@@UAEXPAX00@Z @5f2db1ebe681 @w86b55a1d05f0
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CSPManager,int,const_char_*,int>::vfunc_2 @ 0x001e1850
template <> void Closure2<CSPManager, int, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const void * arguments = (const void *)__p1; int * result = (int *)__p2;

    const struct Arguments { int first; const char *second; } *args = (const Arguments *)arguments;
    int value = ((*(CSPManager_1e1850 * *)&this->f_20)->*(*(int (CSPManager_1e1850::**)(int, const char *))&this->f_1c))(args->first, args->second);
    if (result) *result = value;
}
#if defined(HULK_PTR64)
template class Closure2<CSPManager, int, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1830)
#endif


// 0x001e1880 FUN_001e1880 (89 B): matches/0x001e1880.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001e1880@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e1880 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_00423338[2];
extern void* hulk_at_00423568[2];

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
    vfptr = (void*)hulk_at_00423338;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_00423568;
    owner = a2;
}
} // namespace fn_001e1880


// 0x001e18e0 Closure2<CSPManager,int,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001e18e0.cpp
// sym: ??_G?$Method3@VCSPManager@@XPBD_NM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CSPManager, int, const char *, const char *>::~Closure2() {}


// 0x001e1900 Closure2<CSPManager,int,const_char_*,const_char_*>::vfunc_2 (36 B): equivalent/0x001e1900.cpp
// sym: ?vfunc_2@?$Closure2@VCSPManager@@HPBDH@@UAEXPAX00@Z @5f2db1ebe681 @w86b55a1d05f0
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CSPManager,int,const_char_*,const_char_*>::vfunc_2 @ 0x001e1900
template <> void Closure2<CSPManager, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; const char ** arguments = (const char **)__p1; int * result = (int *)__p2;

    int value = ((*(CSPManager_1e1900 * *)&this->f_20)->*(*(int (CSPManager_1e1900::**)(const char *, const char *))&this->f_1c))(arguments[0], arguments[1]);
    if (result)
        *result = value;
}
#if defined(HULK_PTR64)
template class Closure2<CSPManager, int, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e18e0)
#endif


// 0x001e1930 FUN_001e1930 (89 B): matches/0x001e1930.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001e1930@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e1930 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_00423348[2];
extern void* hulk_at_00423578[2];

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
    vfptr = (void*)hulk_at_00423348;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_00423578;
    owner = a2;
}
} // namespace fn_001e1930


// 0x001e1990 Closure2<CSPManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x001e1990.cpp
// sym: ??_G?$Method1@VCSPManager@@VVector@math@@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CSPManager, void, const char *, int>::~Closure2() {}


// 0x001e19b0 Closure2<CSPManager,void,const_char_*,int>::vfunc_2 (22 B): matches/0x001e19b0.cpp
// sym: ?vfunc_2@?$Closure2@VCSPManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CSPManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1e19b0 * p = (Pair_1e19b0 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1e19b0 * *)&this->f_20)->*(*(void (CActorManager_1e19b0::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CSPManager, void, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1990)
#endif


// 0x001e19d0 FUN_001e19d0 (76 B): matches/0x001e19d0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_001e19d0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e19d0 {
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

class CSPManager;
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(const char* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_1e19d0 : public Base {
  public:
    virtual void invoke(float);
    ScriptMemberFn obj;  // 0x1c
    Closure1_1e19d0(const char*, ScriptMemberFn);
};
class Closure1 : public Closure1_1e19d0 {
  public:
    virtual void invoke(float);
    void* data;  // 0x20
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1_1e19d0::Closure1_1e19d0(const char* p, ScriptMemberFn f) : Base(p) {
    obj = f;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
}
Closure1::Closure1(const char* p, void* f, ScriptMemberFn q) : Closure1_1e19d0(p, q) {
    data = f;
}
} // namespace fn_001e19d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e1a20 Closure1<CSPManager,void,float>::vfunc_0 (30 B): matches/0x001e1a20.cpp
// sym: ??_G?$Method2@VCSPManager@@_NPBDVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSPManager, void, float>::~Closure1() {}


// 0x001e1a40 Closure1<CSPManager,void,float>::vfunc_2 (18 B): matches/0x001e1a40.cpp
// sym: ?vfunc_2@?$Closure1@VCSPManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSPManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1e1a40 * *)&this->f_20)->*(*(void (CActorManager_1e1a40::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CSPManager, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1a20)
#endif


// 0x001e1a90 Closure5<CSPManager,bool,const_char_*,const_char_*,int,float,const_char_*>::vfunc_0 (30 B): matches/0x001e1a90.cpp
// sym: ??_G?$Method1@VCSPManager@@MPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure5<CSPManager, bool, const char *, const char *, int, float, const char *>::~Closure5() {}


// 0x001e1ab0 Closure5<CSPManager,bool,const_char_*,const_char_*,int,float,const_char_*>::vfunc_2 (69 B): matches/0x001e1ab0.cpp
// sym: ?vfunc_2@?$Closure5@VCSPManager@@_NPBDPBDHMPBD@@UAEXPAX00@Z
template <> void Closure5<CSPManager, bool, const char *, const char *, int, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * args = (void *)__p1; void * result = (void *)__p2;

    CSPManager_1e1ab0* p = (*(CSPManager_1e1ab0 * *)&this->f_20);
    bool (CSPManager_1e1ab0::*method)(const char*, const char*, int, float, const char*) = (*(bool (CSPManager_1e1ab0::**)(const char *, const char *, int, float, const char *))&this->f_1c);
    void** a = (void**)args;
    const char* s1 = (const char*)*a++;
    const char* s2 = (const char*)*a++;
    hulk_intptr n = (hulk_intptr)*a++;
    float v = *(float*)a++;
    const char* s3 = (const char*)*a;
    bool r = (p->*method)(s1, s2, n, v, s3);
    if (result)
        *(bool*)result = r;
}
#if defined(HULK_PTR64)
template class Closure5<CSPManager, bool, const char *, const char *, int, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1a90)
#endif


// 0x001e1b30 Closure4<CSPManager,void,int,float,float,float>::vfunc_0 (30 B): matches/0x001e1b30.cpp
// sym: ??_G?$Method6@VCSPManager@@XPBDHMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CSPManager, void, int, float, float, float>::~Closure4() {}


// 0x001e1b50 Closure4<CSPManager,void,int,float,float,float>::vfunc_2 (45 B): matches/0x001e1b50.cpp
// sym: ?vfunc_2@?$Closure4@VCSPManager@@XHMMM@@UAEXPAX00@Z
template <> void Closure4<CSPManager, void, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; const float * p = (const float *)__p1; hulk_intptr y = (hulk_intptr)__p2;

    const int* q = (const int*)p;
    int a = *q++;
    volatile int b = *q++;
    int d = q[1];
    int c = q[0];
    ((*(CSPManager_1e1b50 * *)&this->f_20)->*(*(void (CSPManager_1e1b50::**)(int, float, float, float))&this->f_1c))(a, *(float*)&b, *(float*)&c, *(float*)&d);
}
#if defined(HULK_PTR64)
template class Closure4<CSPManager, void, int, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1b30)
#endif


// 0x001e1bb0 Closure5<CSPManager,void,int,float,float,float,const_char_*>::vfunc_0 (30 B): matches/0x001e1bb0.cpp
// sym: ??_G?$Method1@VCSPManager@@_NPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure5<CSPManager, void, int, float, float, float, const char *>::~Closure5() {}


// 0x001e1bd0 Closure5<CSPManager,void,int,float,float,float,const_char_*>::vfunc_2 (62 B): matches/0x001e1bd0.cpp
// sym: ?vfunc_2@?$Closure5@VCSPManager@@XHMMMPBD@@UAEXPAX00@Z
template <> void Closure5<CSPManager, void, int, float, float, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; int * args = (int *)__p1; hulk_intptr other = (hulk_intptr)__p2;

    int a = *args++;
    float b = *(float*)args++;
    float c = *(float*)args++;
    float d = *(float*)args++;
    const char* e = (const char*)*args++;
    ((*(CSPManager_1e1bd0 * *)&this->f_20)->*(*(void (CSPManager_1e1bd0::**)(int, float, float, float, const char *))&this->f_1c))(a, b, c, d, e);
}
#if defined(HULK_PTR64)
template class Closure5<CSPManager, void, int, float, float, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1bb0)
#endif


// 0x001e1c40 Closure3<CSPManager,void,const_char_*,bool,float>::vfunc_0 (30 B): matches/0x001e1c40.cpp
// sym: ??_G?$Method5@VCSPManager@@XPBDPBDMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CSPManager, void, const char *, bool, float>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<CSPManager, void, const char *, bool, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1c40)
#endif


// 0x001e1c80 FUN_001e1c80 (76 B): matches/0x001e1c80.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ??0Closure1@fn_001e1c80@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e1c80 {
extern "C++" __declspec(nothrow) char Fnf_001d04d0(const char*);
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern char label1[];
extern char hulk_at_0048e0f0[];
class Root : public CtorV_001d0480 {
  public:
    Root(const char*, int);
};
Root::Root(const char* p, int n) : CtorV_001d0480(p, n) {
}
class Closure1_1e1c80 : public Root {
  public:
    virtual void a();
    Closure1_1e1c80(const char*, ScriptMemberFn);
    ScriptMemberFn val;  // 0x1c
};
Closure1_1e1c80::Closure1_1e1c80(const char* s, ScriptMemberFn p) : Root(s, 1) {
    val = p;
    retType = Fnf_001d04d0(label1);
    argTypes[0] = Fnf_001d04d0(hulk_at_0048e0f0);
}
class Closure1 : public Closure1_1e1c80 {
  public:
    virtual void a();
    Closure1(const char*, void*, ScriptMemberFn);
    void* val2;  // 0x20
};
Closure1::Closure1(const char* s, void* p, ScriptMemberFn q) : Closure1_1e1c80(s, q) {
    val2 = p;
}
} // namespace fn_001e1c80


// 0x001e1cd0 Closure1<CSPManager,math::Vector,const_char_*>::vfunc_0 (30 B): matches/0x001e1cd0.cpp
// sym: ??_G?$Method3@VCSPManager@@XPBDPBDVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSPManager,math::Vector, const char *>::~Closure1() {}


// 0x001e1cf0 Closure1<CSPManager,math::Vector,const_char_*>::vfunc_2 (70 B): matches/0x001e1cf0.cpp
// sym: ?vfunc_2@?$Closure1@VCSPManager@@VVector@math@@PBD@@UAEXPAX00@Z
template <> void Closure1<CSPManager,math::Vector, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** name = (const char **)__p1; Vector_1e1cf0 * out = (Vector_1e1cf0 *)__p2;

    CSPManager_1e1cf0* p = (*(CSPManager_1e1cf0 * *)&this->f_20);
    Vector_1e1cf0 (CSPManager_1e1cf0::*f)(const char*) = (*(Vector_1e1cf0 (CSPManager_1e1cf0::**)(const char *))&this->f_1c);
    Vector_1e1cf0 value = (p->*f)(*name);
    if (out)
        *out = value;
}
#if defined(HULK_PTR64)
template class Closure1<CSPManager,math::Vector, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1cd0)
#endif


// 0x001e1d40 FUN_001e1d40 (89 B): matches/0x001e1d40.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001e1d40@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e1d40 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_004233b8[2];
extern void* hulk_at_004235e8[2];
extern void* TAB_48e134;

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
    vfptr = (void*)hulk_at_004233b8;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e0e4));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(&TAB_48e134);
    vfptr = (void*)hulk_at_004235e8;
    owner = a2;
}
} // namespace fn_001e1d40


// 0x001e1da0 Closure2<CSPManager,bool,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x001e1da0.cpp
// sym: ??_G?$Method4@VCSPManager@@XPBDPBDVVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CSPManager, bool, const char *,math::Vector>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<CSPManager, bool, const char *,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1da0)
#endif


// 0x001e1dc0 Closure2<CSPManager,bool,const_char_*,math::Vector>::vfunc_2 (61 B): equivalent/0x001e1dc0.cpp [wrapped: conflict: Arguments; CSPManager; Closure2]
// sym: ?vfunc_2@Closure2@fn_001e1dc0@@UAEXPAXPBUArguments@2@PA_N@Z @6c585092a365 @w54271f29a7dd
namespace fn_001e1dc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x001e1dc0
struct Vector { float x, y, z; };
struct Arguments { const char *name; Vector position; };
struct CSPManager {};
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const Arguments *arguments, bool *result);
    char padding[0x18];
    bool (CSPManager::*method)(const char *, Vector);
    CSPManager *object;
};
void Closure2::vfunc_2(void *unused, const Arguments *arguments, bool *result) {
    bool value = (object->*method)(arguments->name, arguments->position);
    if (result) *result = value;
}
} // namespace fn_001e1dc0


// 0x001e1e00 FUN_001e1e00 (76 B): matches/0x001e1e00.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_001e1e00@@QAE@PBDPAX1@Z
namespace fn_001e1e00 {
// data: str1 = DAT_0048e128, str2 = DAT_0048e0f0

extern "C++" __declspec(nothrow) unsigned char __cdecl fn_001d04d0(const char*);
class Base {
  public:
    Base(const char*, int);
    virtual void f();
};
class Closure1_1e1e00 : public Base {
  public:
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* c;
    Closure1_1e1e00(const char*, void*);
    virtual void f();
};
class Closure1 : public Closure1_1e1e00 {
  public:
    void* d;
    Closure1(const char*, void*, void*);
    virtual void f();
};
Closure1_1e1e00::Closure1_1e1e00(const char* s, void* p) : Base(s, 1) {
    c = p;
    b = fn_001d04d0(((const char*)&DAT_0048e128));
    a = fn_001d04d0(((const char*)&DAT_0048e0f0));
}
Closure1::Closure1(const char* s, void* p, void* q) : Closure1_1e1e00(s, q) {
    d = p;
}
} // namespace fn_001e1e00


// 0x001e1e50 Closure1<CSPManager,float,const_char_*>::vfunc_0 (30 B): matches/0x001e1e50.cpp
// sym: ??_G?$Method2@VCSPManager@@_NVVector@math@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSPManager, float, const char *>::~Closure1() {}


// 0x001e1e70 Closure1<CSPManager,float,const_char_*>::vfunc_2 (43 B): matches/0x001e1e70.cpp
// sym: ?vfunc_2@?$Closure1@VCSPManager@@MPBD@@UAEXPAX00@Z
// Same code shape as 0x0002e800 (propagated; names are from that function)
template <> void Closure1<CSPManager, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr ignored = (hulk_intptr)__p0; const char ** arg = (const char **)__p1; float * out = (float *)__p2;

    CActorManager_1e1e70* obj = (*(CActorManager_1e1e70 * *)&this->f_20);
    Fn_1e1e70 fn = (*(Fn_1e1e70 *)&this->f_1c);
    float value = (obj->*fn)(*arg);
    if (out)
        *out = value;
}
#if defined(HULK_PTR64)
template class Closure1<CSPManager, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1e50)
#endif


// 0x001e1ed0 Closure6<CSPManager,void,const_char_*,int,float,float,float,float>::vfunc_0 (30 B): matches/0x001e1ed0.cpp
// sym: ??_G?$Method4@VCSPManager@@_NMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure6<CSPManager, void, const char *, int, float, float, float, float>::~Closure6() {}


// 0x001e1ef0 Closure6<CSPManager,void,const_char_*,int,float,float,float,float>::vfunc_2 (71 B): matches/0x001e1ef0.cpp
// sym: ?vfunc_2@?$Closure6@VCSPManager@@XPBDHMMMM@@UAEXPAX00@Z
template <> void Closure6<CSPManager, void, const char *, int, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const unsigned int * p = (const unsigned int *)__p1;

    const char* a = (const char*)*p++;
    int b = *p++;
    float c = *(float*)p++;
    float d = *(float*)p++;
    float e = *(float*)p++;
    float f = *(float*)p++;
    ((*(CSPManager_1e1ef0 * *)&this->f_20)->*(*(void (CSPManager_1e1ef0::**)(const char *, int, float, float, float, float))&this->f_1c))(a, b, c, d, e, f);
}
#if defined(HULK_PTR64)
template class Closure6<CSPManager, void, const char *, int, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1ed0)
#endif


// 0x001e1f40 FUN_001e1f40 (76 B): matches/0x001e1f40.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001e1f40@@QAE@PBDPAVCSPManager@1@P8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e1f40 {
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

class CSPManager;
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct Function_1e1f40 : public ScriptFunctionFields {
    virtual void run();
    ScriptMemberFn fn;  // 0x1c
    Function_1e1f40(const char*, int);
};
struct Method1 : Function_1e1f40 {
    virtual void run();
    Method1(const char* x, ScriptMemberFn z) : Function_1e1f40(x, 1) {
        fn = z;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
struct Closure1 : Method1 {
    virtual void run();
    CSPManager* mgr;  // 0x20
    Closure1(const char*, CSPManager*, ScriptMemberFn);
};
Closure1::Closure1(const char* x, CSPManager* m, ScriptMemberFn z) : Method1(x, z) {
    mgr = m;
}
} // namespace fn_001e1f40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e1f90 Closure1<CSPManager,bool,const_char_*>::vfunc_0 (30 B): matches/0x001e1f90.cpp
// sym: ??_G?$Method1@VCSPManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSPManager, bool, const char *>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CSPManager, bool, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e1f90)
#endif


// 0x001e1fb0 Closure1<CSPManager,bool,const_char_*>::vfunc_2 (30 B): matches/0x001e1fb0.cpp [wrapped: conflict: Closure1]
// sym: ?V2@Closure1@fn_001e1fb0@@UAEXPAXPAPBDPA_N@Z
namespace fn_001e1fb0 {
// Same code shape as 0x00106cc0 (propagated; names are from that function)
class Closure1 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2(void*, const char**, bool*);
    char pad[0x18];
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
} // namespace fn_001e1fb0


// 0x001e2000 Closure5<CSPManager,void,const_char_*,const_char_*,float,float,float>::vfunc_0 (30 B): matches/0x001e2000.cpp
// sym: ??_G?$Method3@VCSPManager@@XHHPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure5<CSPManager, void, const char *, const char *, float, float, float>::~Closure5() {}


// 0x001e2020 Closure5<CSPManager,void,const_char_*,const_char_*,float,float,float>::vfunc_2 (55 B): matches/0x001e2020.cpp
// sym: ?vfunc_2@?$Closure5@VCSPManager@@XPBDPBDMMM@@UAEXPAX00@Z
template <> void Closure5<CSPManager, void, const char *, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; void * c = (void *)__p2;

    char* p = (char*)b;
    const char* x = *(const char**)p;
    p += 4;
    const char* y = *(const char**)p;
    p += 4;
    float z = *(float*)p;
    p += 4;
    float w = *(float*)p;
    p += 4;
    float v = *(float*)p;
    ((*(CSPManager_1e2020 * *)&this->f_20)->*(*(void (CSPManager_1e2020::**)(const char *, const char *, float, float, float))&this->f_1c))(x, y, z, w, v);
}
#if defined(HULK_PTR64)
template class Closure5<CSPManager, void, const char *, const char *, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e2000)
#endif


// 0x001e2090 Closure3<CSPManager,void,const_char_*,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x001e2090.cpp
// sym: ??_G?$Method3@VCSPManager@@XMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CSPManager, void, const char *, const char *,math::Vector>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<CSPManager, void, const char *, const char *,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e2090)
#endif


// 0x001e2120 Closure4<CSPManager,void,const_char_*,const_char_*,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x001e2120.cpp
// sym: ??_G?$Method2@VCSPManager@@_NPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CSPManager, void, const char *, const char *,math::Vector,math::Vector>::~Closure4() {}
#if defined(HULK_PTR64)
template class Closure4<CSPManager, void, const char *, const char *,math::Vector,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e2120)
#endif


// 0x001e2140 Closure4<CSPManager,void,const_char_*,const_char_*,math::Vector,math::Vector>::vfunc_2 (12 B): matches/0x001e2140.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure2@fn_001e2140@@UAEXHHH@Z
namespace fn_001e2140 {
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
} // namespace fn_001e2140


// 0x001e2150 FUN_001e2150 (89 B): matches/0x001e2150.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001e2150@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e2150 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_00423428[2];
extern void* hulk_at_00423658[2];
extern void* TAB_48e0f0;

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
    vfptr = (void*)hulk_at_00423428;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e0e4));
    f.argTypes[0] = LookupFlag_001d04d0(&TAB_48e0f0);
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e128));
    vfptr = (void*)hulk_at_00423658;
    owner = a2;
}
} // namespace fn_001e2150


// 0x001e21b0 Closure2<CSPManager,bool,math::Vector,float>::vfunc_0 (30 B): matches/0x001e21b0.cpp
// sym: ??_G?$Method4@VCSPManager@@_NPBDMMH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CSPManager, bool,math::Vector, float>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<CSPManager, bool,math::Vector, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e21b0)
#endif


// 0x001e21d0 Closure2<CSPManager,bool,math::Vector,float>::vfunc_2 (60 B): matches/0x001e21d0.cpp [wrapped: conflict: Arguments; CSPManager; Closure2]
// sym: ?vfunc_2@Closure2@fn_001e21d0@@UAEXPAXPBUArguments@2@PA_N@Z
namespace fn_001e21d0 {
namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
struct CSPManager {};
struct Arguments {
    math::Vector vector;
    float value;
};
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, const Arguments*, bool*);
    char padding[0x18];
    bool (CSPManager::*method)(math::Vector, float);
    CSPManager* manager;
};
void Closure2::vfunc_2(void* unused, const Arguments* arguments, bool* result) {
    CSPManager* mgr = manager;
    bool (CSPManager::*fn)(math::Vector, float) = method;
    float f = arguments->value;
    bool value = (mgr->*fn)(arguments->vector, f);
    if (result)
        *result = value;
}
} // namespace fn_001e21d0


// 0x001e2240 Closure4<CSPManager,bool,float,float,float,float>::vfunc_0 (30 B): matches/0x001e2240.cpp
// sym: ??_G?$Method1@VCSPManager@@PBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CSPManager, bool, float, float, float, float>::~Closure4() {}


// 0x001e2260 Closure4<CSPManager,bool,float,float,float,float>::vfunc_2 (81 B): matches/0x001e2260.cpp
// sym: ?vfunc_2@?$Closure4@VCSPManager@@_NMMMM@@UAEXPAX00@Z
template <> void Closure4<CSPManager, bool, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { float * a = (float *)__p1; bool * result = (bool *)__p2;

    CSPManager_1e2260* o = (*(CSPManager_1e2260 * *)&this->f_20);
    bool (CSPManager_1e2260::*m)(float, float, float, float) = (*(bool (CSPManager_1e2260::**)(float, float, float, float))&this->f_1c);
    float v0 = *a++;
    float v1 = *a++;
    float v2 = *a++;
    float v3 = *a++;
    bool r = (o->*m)(v0, v1, v2, v3);
    if (result)
        *result = r;
}
#if defined(HULK_PTR64)
template class Closure4<CSPManager, bool, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e2240)
#endif


// 0x001e2300 Closure0<CSPManager,int>::vfunc_0 (30 B): matches/0x001e2300.cpp
// sym: ??_G?$Method2@VCSPManager@@XPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CSPManager, int>::~Closure0() {}


// 0x001e2320 Closure0<CSPManager,int>::vfunc_2 (23 B): matches/0x001e2320.cpp
// sym: ?vfunc_2@?$Closure0@VCSPManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
template <> void Closure0<CSPManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_1e2320* obj = (*(CActorManager_1e2320 * *)&this->f_20);
    int (CActorManager_1e2320::*fn)() = (*(int (CActorManager_1e2320::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
#if defined(HULK_PTR64)
template class Closure0<CSPManager, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e2300)
#endif


// 0x001e2340 FUN_001e2340 (76 B): matches/0x001e2340.cpp [wrapped: conflict: Closure1; Closure1::Closure1; Method1]
// sym: ??0Closure1@fn_001e2340@@QAE@PBDPAVCSPManager@1@P8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e2340 {
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

class CSPManager;
// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Function_1e2340 : public ScriptFunctionFields {
  public:
    virtual void f();
    Function_1e2340(const char*, int);
};
class Method1 : public Function_1e2340 {
  public:
    virtual void f();
    ScriptMemberFn data;  // 0x1c
    Method1(const char* p, ScriptMemberFn d) : Function_1e2340(p, 1) {
        data = d;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    CSPManager* mgr;  // 0x20
    Closure1(const char*, CSPManager*, ScriptMemberFn);
};
Closure1::Closure1(const char* p, CSPManager* m, ScriptMemberFn d) : Method1(p, d) {
    mgr = m;
}
} // namespace fn_001e2340
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e2390 Closure1<CSPManager,void,bool>::vfunc_0 (30 B): matches/0x001e2390.cpp
// sym: ??_G?$Method6@VCSPManager@@XHMMMMH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSPManager, void, bool>::~Closure1() {}


// 0x001e23b0 Closure1<CSPManager,void,bool>::vfunc_2 (20 B): matches/0x001e23b0.cpp
// sym: ?vfunc_2@?$Closure1@VCSPManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<CSPManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_1e23b0 * *)&this->f_20)->*(*(void (Actor_1e23b0::**)(unsigned char))&this->f_1c))(*arg);
}
#if defined(HULK_PTR64)
template class Closure1<CSPManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e2390)
#endif


// 0x001e2490 Closure3<CSPManager,void,float,float,float>::vfunc_2 (34 B): equivalent/0x001e2490.cpp
// sym: ?vfunc_2@?$Closure3@VCSPManager@@XMMM@@UAEXPAX00@Z @737c210bc5da @waa2711c8626c
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSPManager,void,float,float,float>::vfunc_2 @ 0x001e2490
template <> void Closure3<CSPManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Values * values = (Values *)__p1; void * unused2 = (void *)__p2;
 ((*(CSPManager_1e2490 * *)&this->f_20)->*(*(void (CSPManager_1e2490::**)(float, float, float))&this->f_1c))(values->a,values->b,values->c); }


// 0x001e24c0 FUN_001e24c0 (89 B): matches/0x001e24c0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001e24c0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e24c0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_00423488[2];
extern void* hulk_at_004236b8[2];

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
    vfptr = (void*)hulk_at_00423488;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e0e4));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e128));
    vfptr = (void*)hulk_at_004236b8;
    owner = a2;
}
} // namespace fn_001e24c0


// 0x001e2540 Closure2<CSPManager,bool,const_char_*,float>::vfunc_2 (40 B): equivalent/0x001e2540.cpp
// sym: ?vfunc_2@?$Closure2@VCSPManager@@_NPBDM@@UAEXPAX00@Z @e654de0dce29 @w869ed99f0dcb
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CSPManager,bool,const_char_*,float>::vfunc_2 @ 0x001e2540
template <> void Closure2<CSPManager, bool, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CSPManager_1e2540 * *)&this->f_20)->*(*(bool (CSPManager_1e2540::**)(const char *, float))&this->f_1c))(args->text, args->value);
    if (result) *result = value;
}


// 0x001e25c0 Closure4<CSPManager,bool,const_char_*,float,float,int>::vfunc_2 (67 B): matches/0x001e25c0.cpp
// sym: ?vfunc_2@?$Closure4@VCSPManager@@_NPBDMMH@@UAEXPAX00@Z
template <> void Closure4<CSPManager, bool, const char *, float, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * p = (void *)__p1; void * out = (void *)__p2;

    CSPManager_1e25c0* o = (*(CSPManager_1e25c0 *volatile *)&this->f_20);
    bool (CSPManager_1e25c0::*f)(const char*, float, float, int) = (*(bool (CSPManager_1e25c0::**)(const char *, float, float, int))&this->f_1c);
    unsigned* a = (unsigned*)p;
    const char* s = (const char*)*a++;
    float x = *(float*)a++;
    float y = *(float*)a++;
    int n = *a++;
    bool r = (o->*f)(s, x, y, n);
    if (out)
        *(bool*)out = r;
}

namespace fn_f75938cb {

// 0x001e2610 FUN_001e2610 (76 B): matches/0x001e2610.cpp
// sym: ??0Closure1_1e2610@fn_f75938cb@@QAE@PBD00@Z
Closure1_1e2610::Closure1_1e2610(const char* a, const char* b, const char* c) throw() : Method1_1e2610(a, c) {
    second = b;
}

} // namespace fn_f75938cb

// 0x001e2680 Closure1<CSPManager,const_char_*,const_char_*>::vfunc_2 (30 B): equivalent/0x001e2680.cpp [wrapped: conflict: CSPManager]
// sym: ?vfunc_2@Closure1_CSPManager@fn_001e2680@@UAEHPAXPAPBDPAH@Z @d5fcbfd9f63b @w2294ab6d838a
namespace fn_001e2680 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CSPManager,const_char_*,const_char_*>::vfunc_2 @ 0x001e2680
struct CSPManager {
    int FUN_001e2680(const char*);
};

struct Closure1_CSPManager {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2(void* unused, const char** value, int* result);
    char pad[0x18];
    int (CSPManager::*callback)(const char*);
    CSPManager* manager;
};

int Closure1_CSPManager::vfunc_2(void* unused, const char** value, int* result) {
    int answer = (manager->*callback)(*value);
    if (result) *result = answer;
    return answer;
}
} // namespace fn_001e2680


// 0x001e26a0 FUN_001e26a0 (89 B): matches/0x001e26a0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001e26a0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001e26a0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_004234b8[2];
extern void* hulk_at_004236e8[2];

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
    vfptr = (void*)hulk_at_004234b8;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e128));
    vfptr = (void*)hulk_at_004236e8;
    owner = a2;
}
} // namespace fn_001e26a0


// 0x001e2720 Closure2<CSPManager,void,const_char_*,float>::vfunc_2 (22 B): matches/0x001e2720.cpp
// sym: ?vfunc_2@?$Closure2@VCSPManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CSPManager, void, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1e2720 * p = (Pair_1e2720 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1e2720 * *)&this->f_20)->*(*(void (CActorManager_1e2720::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x001e2790 Closure6<CSPManager,void,int,float,float,float,float,int>::vfunc_2 (82 B): matches/0x001e2790.cpp
// sym: ?vfunc_2@?$Closure6@VCSPManager@@XHMMMMH@@UAEXPAX00@Z
template <> void Closure6<CSPManager, void, int, float, float, float, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; void * arg = (void *)__p1; hulk_intptr y = (hulk_intptr)__p2;

    int* p = (int*)arg;
    int a = *p++;
    float b = *(float*)p++;
    float c = *(float*)p++;
    float d = *(float*)p++;
    float e = *(float*)p++;
    int f = *p++;
    ((*(CSPManager_1e2790 * *)&this->f_20)->*(*(void (CSPManager_1e2790::**)(int, float, float, float, float, int))&this->f_1c))(a, b, c, d, e, f);
}

namespace fn_f75938cb {

// 0x001e2800 FUN_001e2800 (110 B): matches/0x001e2800.cpp
// sym: ?Heapify@fn_f75938cb@@YAXPAUE_1e2800@1@0@Z
void Heapify(E_1e2800* first, E_1e2800* last) {
    hulk_intptr n = (last - first);
    hulk_intptr i = n / 2;
    if (i > 0) {
        E_1e2800* p = first + i;
        do {
            i--;
            Sift_001e1040(first, i, n, *--p);
        } while (i > 0);
    }
}


// 0x001e28a0 FUN_001e28a0 (86 B): matches/0x001e28a0.cpp
// sym: _FUN_001e28a0
extern "C" void FUN_001e28a0(void * a, void * b, void * c) {
    if (((Item_1e28a0 *)b)->value < ((Item_1e28a0 *)a)->value)
        swap_item_001e0fc0(((Item_1e28a0 *)b), ((Item_1e28a0 *)a));
    if (((Item_1e28a0 *)c)->value < ((Item_1e28a0 *)b)->value)
        swap_item_001e0fc0(((Item_1e28a0 *)c), ((Item_1e28a0 *)b));
    if (((Item_1e28a0 *)b)->value < ((Item_1e28a0 *)a)->value)
        swap_item_001e0fc0(((Item_1e28a0 *)b), ((Item_1e28a0 *)a));
}

} // namespace fn_f75938cb

// 0x001e2940 FUN_001e2940 (1423 B): equivalent/0x001e2940.cpp [wrapped: conflict: DAT_004dd700; FUN_001c3d90; FUN_0027b020; Node (+2)]
// sym: ?F@Mgr_1e2940@fn_001e2940@@QAEPAUProp_1e2940@2@H@Z @42f9e879af70 @w0656fa2118e4
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


// 0x001e2ed0 FUN_001e2ed0 (334 B): equivalent/0x001e2ed0.cpp [wrapped: conflict: Skeleton; content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ?FUN_001e2ed0@Inventory_1e2ed0@fn_001e2ed0@@QAEHHHH@Z @f7db0b9b4bdb @we60a36dbe9f9
namespace fn_001e2ed0 {
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 20/24, incomplete)
// FUN_001e2ed0 @ 0x001e2ed0
class CSPHulkProp;

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

struct Item_1e2ed0 {
    char pad0[8];
    int keyLo;
    int keyHi;
};

struct ItemList_1e2ed0 {
    char pad0[0x1c];
    Item_1e2ed0 **begin;
    Item_1e2ed0 **end;
};

class Skeleton;

struct Indexer_1e2ed0 {
    int FUN_001d5c70(int index);
    ItemList_1e2ed0 *FUN_001d4fc0();
};

class Skeleton {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(int index, int flag);
    char pad04[0xec - 4];
    Indexer_1e2ed0 *indexer;
    void FUN_001d63b0(int count);
};

class Factory_1e2ed0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Indexer_1e2ed0 *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, int lo, int hi);
};

struct Holder44_1e2ed0 {
    Factory_1e2ed0 *FUN_00203d70();
};

struct Holder28_1e2ed0 {
    Holder44_1e2ed0 *FUN_000862a0();
};

struct Manager_1e2ed0 {
    char pad0[0x54];
    Holder28_1e2ed0 *holder;
};

struct Entry_1e2ed0 {
    char pad0[8];
    int resLo;
    int resHi;
    char pad10[8];
    Skeleton *skel;
    char pad1c[4];
    short pad20;
    short slot;
    char pad24[2];
    signed char index;
    char pad27;
};

struct Slot_1e2ed0 {
    char pad0[0x10];
    unsigned char flags;
    char pad11[3];
};

class Inventory_1e2ed0 {
public:
    char pad0[0x608];
    Entry_1e2ed0 entries[0x800];
    Slot_1e2ed0 slots[1];
    char pad_rest[0x1e830 - 0x14608 - 0x14];
    Manager_1e2ed0 *mgr;
    int FUN_001e2ed0(int idx, int lo, int hi);
};

int Inventory_1e2ed0::FUN_001e2ed0(int idx, int lo, int hi)
{
    if (idx < 0)
        return -1;
    Entry_1e2ed0 *e = &entries[idx];
    Slot_1e2ed0 *s = &slots[e->slot];
    Indexer_1e2ed0 *indexer;
    bool direct;
    if ((s->flags & 1) && e->skel) {
        indexer = e->skel->indexer;
        direct = true;
    } else {
        int rlo = e->resLo;
        int rhi = e->resHi;
        direct = false;
        Factory_1e2ed0 *factory = mgr->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
        indexer = factory->f3(&caster, rlo, rhi);
        if (!indexer)
            return -1;
    }
    ItemList_1e2ed0 *list = indexer->FUN_001d4fc0();
    if (!list)
        return -1;
    hulk_intptr count = list->end - list->begin;
    int n;
    for (n = 0; n < count; n++) {
        Item_1e2ed0 *it = list->begin[n];
        if (it->keyLo == lo && it->keyHi == hi)
            break;
    }
    if (n >= count || n == -1)
        return -1;
    if (direct) {
        e->skel->v16(n, 1);
        int v = e->skel->indexer->FUN_001d5c70(n);
        if (v > 0)
            e->skel->FUN_001d63b0(v);
        return n;
    }
    e->index = (signed char)n;
    e->pad20 = (short)0xfde8;
    s->flags &= 0xfb;
    return n;
}
} // namespace fn_001e2ed0


// 0x001e3020 FUN_001e3020 (206 B): equivalent/0x001e3020.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: ?FUN_001e3020@Game_1e3020@fn_001e3020@@QAEHHHH@Z @6a1bd629b589 @w7041cb77170c
namespace fn_001e3020 {
// STATUS: equivalent (tools/equiv.py level 3: 725 inputs, branch coverage 18/18)
// FUN_001e3020 @ 0x001e3020
class CSPHulkProp;
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; }}
struct Entry_1e3020 { char pad[8]; int key1; int key2; };
struct Inventory_1e3020 { char pad[0x1c]; Entry_1e3020 **begin; Entry_1e3020 **end; };
struct Prop_1e3020 { Inventory_1e3020 *FUN_001d4fc0(); };
struct Linked_1e3020 { char pad[0xec]; Prop_1e3020 *prop; };
struct Resolver_1e3020 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Prop_1e3020 *find(content::LoadInventory::DynamicCaster<CSPHulkProp> *, int, int); };
struct Service_1e3020 { Resolver_1e3020 *FUN_00203d70(); };
struct Provider_1e3020 { Service_1e3020 *FUN_000862a0(); };
struct Owner_1e3020 { char pad[0x54]; Provider_1e3020 *provider; };
struct Record_1e3020 { char pad[8]; int key1; int key2; char pad2[8]; Linked_1e3020 *linked; char pad3[6]; short type; char pad4[4]; };
struct Flags_1e3020 { unsigned char flags; char pad[19]; };
struct Game_1e3020 { char pad[0x608]; Record_1e3020 records[0x704]; char rest[0x14618 - 0x608 - 0x704*40]; Flags_1e3020 flags[0x800]; char rest2[0x1e830 - 0x14618 - 0x800*20]; Owner_1e3020 *owner; int FUN_001e3020(int index,int key1,int key2); };
int Game_1e3020::FUN_001e3020(int index,int key1,int key2) {
 if(index < 0) return -1;
 Record_1e3020 &r=records[index];
 Prop_1e3020 *p;
 if((flags[r.type].flags & 1) && r.linked) p=r.linked->prop;
 else { int a=r.key1,b=r.key2; Service_1e3020 *s=owner->provider->FUN_000862a0(); Resolver_1e3020 *v=s->FUN_00203d70(); content::LoadInventory::DynamicCaster<CSPHulkProp> caster; p=v->find(&caster,a,b); if(!p) return -1; }
 Inventory_1e3020 *inv=p->FUN_001d4fc0();
 if(!inv) return -1;
 Entry_1e3020 **entries=inv->begin; hulk_intptr count=inv->end-entries;
 for(int i=0;i<count;++i) { Entry_1e3020 *e=entries[i]; if(e->key1==key1 && e->key2==key2) return i; }
 return -1;
}
} // namespace fn_001e3020


// 0x001e30f0 FUN_001e30f0 (261 B): equivalent/0x001e30f0.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: ?target@CSPManager_1e30f0@fn_001e30f0@@QAEXII@Z @bf26c60c3917 @wcd50b7f568c8
namespace fn_001e30f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2230 inputs, branch coverage 20/20)
// FUN_001e30f0 @ 0x001e30f0
class CSPHulkProp;
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
struct Object;
struct Entry_1e30f0 { unsigned low, high; int unused; int index; };
struct Table_1e30f0 { char pad[0x24]; int count; Entry_1e30f0* entries; };
struct Info_1e30f0 { char pad[0x1c]; Table_1e30f0** tables; };
struct Object { Info_1e30f0* FUN_001d4fc0(); void FUN_0027e760(unsigned); };
struct Inventory_1e30f0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual Object* find(content::LoadInventory::DynamicCaster<CSPHulkProp>*, unsigned, unsigned); };
struct Provider_1e30f0 { Inventory_1e30f0* FUN_00203d70(); };
struct Context { Provider_1e30f0* FUN_000862a0(); };
struct Owner_1e30f0 { char pad[0x54]; Context* context; };
unsigned __int64 __cdecl FUN_0027b020(unsigned);
struct Record_1e30f0 { char pad[8]; unsigned key1,key2; char pad2[8]; Object* object; char pad3[4]; short state; short type; char pad4[2]; signed char table; char pad5; };
struct Flag_1e30f0 { unsigned flags; char pad[16]; };
struct CSPManager_1e30f0 { char pad[0x608]; Record_1e30f0 records[1923]; char rest[0x14618-0x608-1923*40]; Flag_1e30f0 flags[2073]; char tail[0x1e830-0x14618-2073*20]; Owner_1e30f0* owner; int FUN_001dbfe0(unsigned); void target(unsigned id,unsigned value); };
void CSPManager_1e30f0::target(unsigned id,unsigned value) {
 int n=FUN_001dbfe0(id); if(n<0) return;
 Record_1e30f0* r=&records[n];
 if((flags[r->type].flags&1) && r->object) { r->object->FUN_0027e760(value); return; }
 unsigned k1=r->key1,k2=r->key2;
 Provider_1e30f0* p=owner->context->FUN_000862a0();
 Inventory_1e30f0* inv=p->FUN_00203d70();
 content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
 Object* obj=inv->find(&caster,k1,k2);
 if(!obj) return;
 unsigned __int64 key=FUN_0027b020(value);
 Info_1e30f0* info=obj->FUN_001d4fc0();
 int ti=r->table; if(ti<0) return;
 Table_1e30f0* t=info->tables[ti];
 for(int i=0;i<t->count;++i) { Entry_1e30f0& e=t->entries[i]; if(e.low==(unsigned)key && e.high==(unsigned)(key>>32)) { if(e.index!=-1) { r->table=(signed char)e.index; r->state=0; } return; } }
}
} // namespace fn_001e30f0


// 0x001e3200 FUN_001e3200 (35 B): matches/0x001e3200.cpp
// sym: ?FUN_001e3200@A_1e3200@owners@@QAEIIII@Z
U_1e3200 owners::A_1e3200::FUN_001e3200(hulk_uintptr a, U_1e3200 b, U_1e3200 c) {
    U_1e3200 x = ((CSPManager_nv_1e3200*)(((CSPManager*)(((CSPManager*)this)))))->Fng_001dbfe0(((U_1e3200)a));
    return ((C_1e3200*)this)->Fnh_001e2ed0(x, b, c);
}


// 0x001e3230 FUN_001e3230 (123 B): matches/0x001e3230.cpp [wrapped: conflict: FUN_00096d80]
// sym: ?FUN_001e3230@CSPManager_1e3230@fn_001e3230@@QAEXPBD0@Z
namespace fn_001e3230 {
// FUN_001e3230 @ 0x001e3230

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl strcmp(const char *a, const char *b);
#endif


struct Id_1e3230 {
    int lo, hi;
};

Id_1e3230 __cdecl FUN_00096d80(const char *name);

struct Config_1e3230 {
    char pad0[0x124];
    int value;
};

struct Owner_1e3230 {
    char pad0[0x20];
    Config_1e3230 *config;
};

struct Item_1e3230 {
    int FUN_001d6990();
    void FUN_001d8350(int value);
};

class CSPManager_1e3230 {
public:
    void FUN_001e3230(const char *name, const char *state);
    Item_1e3230 *FUN_001def30(const char *name);
    int FUN_001dbfe0(const char *name);
    void FUN_001e2ed0(int stateId, int idLo, int idHi);

    char pad0[0x1e830];
    Owner_1e3230 *owner;
};

void CSPManager_1e3230::FUN_001e3230(const char *name, const char *state) {
    Item_1e3230 *item = FUN_001def30(name);
    if (item != 0 && item->FUN_001d6990() == 7 && strcmp(state, "collected") == 0) {
        item->FUN_001d8350(owner->config->value);
    }
    Id_1e3230 id = FUN_00096d80(state);
    int stateId = FUN_001dbfe0(name);
    FUN_001e2ed0(stateId, id.lo, id.hi);
}
} // namespace fn_001e3230


// 0x001e32b0 FUN_001e32b0 (166 B): equivalent/0x001e32b0.cpp [wrapped: conflict: World; content::LoadInventory::DynamicCaster]
// sym: ?FUN_001e32b0@CSPManager_1e32b0@fn_001e32b0@@QAEHH@Z @ea68abd1995b @w931a73c5b7b2
namespace fn_001e32b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001e32b0 @ 0x001e32b0
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



namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

class CSPHulkProp;

struct Item_1e32b0 {
    int FUN_001d5dd0(int arg);
};

struct Part_1e32b0 {
    char pad0[0x40];
    int key;                 // 0x40
    char pad1[0xec - 0x44];
    Item_1e32b0 *item;              // 0xec
};

class Factory_1e32b0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Item_1e32b0 *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_1e32b0 { Factory_1e32b0 *FUN_00203d70(); };
struct Holder28_1e32b0 { Holder44_1e32b0 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_1e32b0 *holder; };

struct Slot_1e32b0 {
    unsigned char flags;
    char pad[19];
};

struct Entry_1e32b0 {
    char pad0[8];
    unsigned int idLo;       // 0x08
    unsigned int idHi;       // 0x0c
    char pad1[0x18 - 0x10];
    Part_1e32b0 *part;              // 0x18
    char pad2[0x22 - 0x1c];
    short group;             // 0x22
    char pad3[0x26 - 0x24];
    signed char index;       // 0x26
    char pad4[0x28 - 0x27];
};

class CSPManager_1e32b0 {
public:
    int FUN_001e32b0(int name);
    int FUN_001dbfe0(int name);

    char pad0[0x608];
    Entry_1e32b0 entries[1];        // 0x608
};

int CSPManager_1e32b0::FUN_001e32b0(int name)
{
    int idx = FUN_001dbfe0(name);
    if (idx < 0)
        return 0;
    Entry_1e32b0 *e = &entries[idx];
    Slot_1e32b0 *slots = (Slot_1e32b0 *)this;
    if ((slots[e->group + 0x104e].flags & 1) && e->part != 0)
        return e->part->item->FUN_001d5dd0(e->part->key);

    Factory_1e32b0 *fa = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
    Item_1e32b0 *obj = fa->f3(&caster, e->idLo, e->idHi);
    if (obj != 0)
        return obj->FUN_001d5dd0(e->index);
    return 0;
}
} // namespace fn_001e32b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e3360 FUN_001e3360 (166 B): equivalent/0x001e3360.cpp [wrapped: conflict: World; content::LoadInventory::DynamicCaster]
// sym: ?FUN_001e3360@CSPManager_1e3360@fn_001e3360@@QAEHH@Z @ffa9056362d5 @wa0b35f2bbd10
namespace fn_001e3360 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001e3360 @ 0x001e3360
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



namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

class CSPHulkProp;

struct Item_1e3360 {
    int FUN_001d5e80(int arg);
};

struct Part_1e3360 {
    char pad0[0x40];
    int key;                 // 0x40
    char pad1[0xec - 0x44];
    Item_1e3360 *item;              // 0xec
};

class Factory_1e3360 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Item_1e3360 *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_1e3360 { Factory_1e3360 *FUN_00203d70(); };
struct Holder28_1e3360 { Holder44_1e3360 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_1e3360 *holder; };

struct Slot_1e3360 {
    unsigned char flags;
    char pad[19];
};

struct Entry_1e3360 {
    char pad0[8];
    unsigned int idLo;       // 0x08
    unsigned int idHi;       // 0x0c
    char pad1[0x18 - 0x10];
    Part_1e3360 *part;              // 0x18
    char pad2[0x22 - 0x1c];
    short group;             // 0x22
    char pad3[0x26 - 0x24];
    signed char index;       // 0x26
    char pad4[0x28 - 0x27];
};

class CSPManager_1e3360 {
public:
    int FUN_001e3360(int name);
    int FUN_001dbfe0(int name);

    char pad0[0x608];
    Entry_1e3360 entries[1];        // 0x608
};

int CSPManager_1e3360::FUN_001e3360(int name)
{
    int idx = FUN_001dbfe0(name);
    if (idx < 0)
        return 0;
    Entry_1e3360 *e = &entries[idx];
    Slot_1e3360 *slots = (Slot_1e3360 *)this;
    if ((slots[e->group + 0x104e].flags & 1) && e->part != 0)
        return e->part->item->FUN_001d5e80(e->part->key);

    Factory_1e3360 *fa = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
    Item_1e3360 *obj = fa->f3(&caster, e->idLo, e->idHi);
    if (obj != 0)
        return obj->FUN_001d5e80(e->index);
    return 0;
}
} // namespace fn_001e3360
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f75938cb {

// 0x001e35a0 FUN_001e35a0 (83 B): equivalent/0x001e35a0.cpp
// sym: ?FUN_001e35a0@Registry_1e35a0@fn_f75938cb@@QAEXPBDPAVCSPManager_1e35a0@2@P832@AE_N0HH@Z@Z @adf547391a93 @wa1088e58a265
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e35a0 @ 0x001e35a0
// FUN_001e35a0 @ 0x001e35a0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e35a0::FUN_001e35a0(const char* a1, CSPManager_1e35a0* a2, Fn_1e35a0 a3) {
    typedef Closure3_1e35a0<CSPManager_1e35a0, bool, const char*, int, int> Alloc_1e35a0;
    HULK_SIZE32(Alloc_1e35a0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e35a0));
    void* x = 0;
    if (m) {
        ((Raw_1e35a0*)m)->FUN_001df750(a1, a3);
        x = new (m) Closure3_1e35a0<CSPManager_1e35a0, bool, const char*, int, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e3790 FUN_001e3790 (83 B): equivalent/0x001e3790.cpp
// sym: ?FUN_001e3790@Registry_1e3790@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3790@2@P832@AEX00H0VVector_1e3790@math@@2@Z@Z @0cd3e0e7cc49 @w501c4cd8cac5
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3790 @ 0x001e3790
// FUN_001e3790 @ 0x001e3790  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3790::FUN_001e3790(const char* a1, CSPManager_1e3790* a2, Fn_1e3790 a3) {
    typedef Closure6_1e3790<CSPManager_1e3790, void, const char*, const char*, int, const char*, math::Vector_1e3790, math::Vector_1e3790> Alloc_1e3790;
    HULK_SIZE32(Alloc_1e3790, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3790));
    void* x = 0;
    if (m) {
        ((Raw_1e3790*)m)->FUN_001dfae0(a1, a3);
        x = new (m) Closure6_1e3790<CSPManager_1e3790, void, const char*, const char*, int, const char*, math::Vector_1e3790, math::Vector_1e3790>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e3930 FUN_001e3930 (83 B): equivalent/0x001e3930.cpp
// sym: ?FUN_001e3930@Registry_1e3930@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3930@2@P832@AE_N00HM0@Z@Z @e1fd58c0663b @w4a2ed04dd30f
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3930 @ 0x001e3930
// FUN_001e3930 @ 0x001e3930  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3930::FUN_001e3930(const char* a1, CSPManager_1e3930* a2, Fn_1e3930 a3) {
    typedef Closure5_1e3930<CSPManager_1e3930, bool, const char*, const char*, int, float, const char*> Alloc_1e3930;
    HULK_SIZE32(Alloc_1e3930, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3930));
    void* x = 0;
    if (m) {
        ((Raw_1e3930*)m)->FUN_001dfe70(a1, a3);
        x = new (m) Closure5_1e3930<CSPManager_1e3930, bool, const char*, const char*, int, float, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e3990 FUN_001e3990 (83 B): equivalent/0x001e3990.cpp
// sym: ?FUN_001e3990@Registry_1e3990@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3990@2@P832@AEXHMMM@Z@Z @2bda1540a5e8 @w1c1abd6ac302
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3990 @ 0x001e3990
// FUN_001e3990 @ 0x001e3990  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3990::FUN_001e3990(const char* a1, CSPManager_1e3990* a2, Fn_1e3990 a3) {
    typedef Closure4_1e3990<CSPManager_1e3990, void, int, float, float, float> Alloc_1e3990;
    HULK_SIZE32(Alloc_1e3990, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3990));
    void* x = 0;
    if (m) {
        ((Raw_1e3990*)m)->FUN_001dff70(a1, a3);
        x = new (m) Closure4_1e3990<CSPManager_1e3990, void, int, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e39f0 FUN_001e39f0 (83 B): equivalent/0x001e39f0.cpp
// sym: ?FUN_001e39f0@Registry_1e39f0@fn_f75938cb@@QAEXPBDPAVCSPManager_1e39f0@2@P832@AEXHMMM0@Z@Z @a533d532f410 @w297821c08e00
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e39f0 @ 0x001e39f0
// FUN_001e39f0 @ 0x001e39f0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e39f0::FUN_001e39f0(const char* a1, CSPManager_1e39f0* a2, Fn_1e39f0 a3) {
    typedef Closure5_1e39f0<CSPManager_1e39f0, void, int, float, float, float, const char*> Alloc_1e39f0;
    HULK_SIZE32(Alloc_1e39f0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e39f0));
    void* x = 0;
    if (m) {
        ((Raw_1e39f0*)m)->FUN_001e0030(a1, a3);
        x = new (m) Closure5_1e39f0<CSPManager_1e39f0, void, int, float, float, float, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e3a50 FUN_001e3a50 (83 B): equivalent/0x001e3a50.cpp
// sym: ?FUN_001e3a50@Registry_1e3a50@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3a50@2@P832@AEX0_NM@Z@Z @a3b0492437b4 @wf2c7379d8b35
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3a50 @ 0x001e3a50
// FUN_001e3a50 @ 0x001e3a50  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3a50::FUN_001e3a50(const char* a1, CSPManager_1e3a50* a2, Fn_1e3a50 a3) {
    typedef Closure3_1e3a50<CSPManager_1e3a50, void, const char*, bool, float> Alloc_1e3a50;
    HULK_SIZE32(Alloc_1e3a50, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3a50));
    void* x = 0;
    if (m) {
        ((Raw_1e3a50*)m)->FUN_001e0130(a1, a3);
        x = new (m) Closure3_1e3a50<CSPManager_1e3a50, void, const char*, bool, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e3ba0 FUN_001e3ba0 (83 B): equivalent/0x001e3ba0.cpp
// sym: ?FUN_001e3ba0@Registry_1e3ba0@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3ba0@2@P832@AEX0HMMMM@Z@Z @2d70f242a5fd @w26b8d450451a
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3ba0 @ 0x001e3ba0
// FUN_001e3ba0 @ 0x001e3ba0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3ba0::FUN_001e3ba0(const char* a1, CSPManager_1e3ba0* a2, Fn_1e3ba0 a3) {
    typedef Closure6_1e3ba0<CSPManager_1e3ba0, void, const char*, int, float, float, float, float> Alloc_1e3ba0;
    HULK_SIZE32(Alloc_1e3ba0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3ba0));
    void* x = 0;
    if (m) {
        ((Raw_1e3ba0*)m)->FUN_001e03c0(a1, a3);
        x = new (m) Closure6_1e3ba0<CSPManager_1e3ba0, void, const char*, int, float, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e3c50 FUN_001e3c50 (83 B): equivalent/0x001e3c50.cpp
// sym: ?FUN_001e3c50@Registry_1e3c50@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3c50@2@P832@AEX00MMM@Z@Z @986c46adcd54 @wbfddcd5c0e31
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3c50 @ 0x001e3c50
// FUN_001e3c50 @ 0x001e3c50  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3c50::FUN_001e3c50(const char* a1, CSPManager_1e3c50* a2, Fn_1e3c50 a3) {
    typedef Closure5_1e3c50<CSPManager_1e3c50, void, const char*, const char*, float, float, float> Alloc_1e3c50;
    HULK_SIZE32(Alloc_1e3c50, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3c50));
    void* x = 0;
    if (m) {
        ((Raw_1e3c50*)m)->FUN_001e0550(a1, a3);
        x = new (m) Closure5_1e3c50<CSPManager_1e3c50, void, const char*, const char*, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e3cb0 FUN_001e3cb0 (83 B): equivalent/0x001e3cb0.cpp
// sym: ?FUN_001e3cb0@Registry_1e3cb0@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3cb0@2@P832@AEX00VVector_1e3cb0@math@@@Z@Z @cda3d99b072a @w244ad3289981
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3cb0 @ 0x001e3cb0
// FUN_001e3cb0 @ 0x001e3cb0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3cb0::FUN_001e3cb0(const char* a1, CSPManager_1e3cb0* a2, Fn_1e3cb0 a3) {
    typedef Closure3_1e3cb0<CSPManager_1e3cb0, void, const char*, const char*, math::Vector_1e3cb0> Alloc_1e3cb0;
    HULK_SIZE32(Alloc_1e3cb0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3cb0));
    void* x = 0;
    if (m) {
        ((Raw_1e3cb0*)m)->FUN_001e0650(a1, a3);
        x = new (m) Closure3_1e3cb0<CSPManager_1e3cb0, void, const char*, const char*, math::Vector_1e3cb0>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e3d10 FUN_001e3d10 (83 B): equivalent/0x001e3d10.cpp
// sym: ?FUN_001e3d10@Registry_1e3d10@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3d10@2@P832@AEX00VVector_1e3d10@math@@2@Z@Z @5b90bce347ed @w8e6e6071de8f
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3d10 @ 0x001e3d10
// FUN_001e3d10 @ 0x001e3d10  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3d10::FUN_001e3d10(const char* a1, CSPManager_1e3d10* a2, Fn_1e3d10 a3) {
    typedef Closure4_1e3d10<CSPManager_1e3d10, void, const char*, const char*, math::Vector_1e3d10, math::Vector_1e3d10> Alloc_1e3d10;
    HULK_SIZE32(Alloc_1e3d10, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3d10));
    void* x = 0;
    if (m) {
        ((Raw_1e3d10*)m)->FUN_001e0710(a1, a3);
        x = new (m) Closure4_1e3d10<CSPManager_1e3d10, void, const char*, const char*, math::Vector_1e3d10, math::Vector_1e3d10>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e3dc0 FUN_001e3dc0 (83 B): equivalent/0x001e3dc0.cpp
// sym: ?FUN_001e3dc0@Registry_1e3dc0@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3dc0@2@P832@AE_NMMMM@Z@Z @814ab45d59fe @w8fea13641ca9
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3dc0 @ 0x001e3dc0
// FUN_001e3dc0 @ 0x001e3dc0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3dc0::FUN_001e3dc0(const char* a1, CSPManager_1e3dc0* a2, Fn_1e3dc0 a3) {
    typedef Closure4_1e3dc0<CSPManager_1e3dc0, bool, float, float, float, float> Alloc_1e3dc0;
    HULK_SIZE32(Alloc_1e3dc0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3dc0));
    void* x = 0;
    if (m) {
        ((Raw_1e3dc0*)m)->FUN_001e08c0(a1, a3);
        x = new (m) Closure4_1e3dc0<CSPManager_1e3dc0, bool, float, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f75938cb

// 0x001e3e20 FUN_001e3e20 (109 B): equivalent/0x001e3e20.cpp [wrapped: conflict: CSPManager; Closure0; Method0]
// sym: ?FUN_001e3e20@Registry_1e3e20@fn_001e3e20@@QAEXPBDPAVCSPManager@2@P832@AEHXZ@Z @3cf3d100f234 @w57d245c525b3
namespace fn_001e3e20 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001e3e20 @ 0x001e3e20
// FUN_001e3e20 @ 0x001e3e20  (generated by work/closure/gen.py)
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


class CSPManager { public: float FUN_dummy(); };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) MethodBase_1e3e20 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1e3e20(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1e3e20 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1e3e20(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e134));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_1e3e20 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001e3e20(const char* name, CSPManager* owner, int (CSPManager::*fn)());
};

void Registry_1e3e20::FUN_001e3e20(const char* name, CSPManager* owner, int (CSPManager::*fn)()) {
    typedef Closure0<CSPManager, int> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CSPManager, int>));
    Closure0<CSPManager, int>* c = 0;
    if (mem)
        c = new (mem) Closure0<CSPManager, int>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001e3e20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f75938cb {

// 0x001e3ee0 FUN_001e3ee0 (83 B): equivalent/0x001e3ee0.cpp
// sym: ?FUN_001e3ee0@Registry_1e3ee0@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3ee0@2@P832@AEXHH0@Z@Z @e2c7cb3d586c @w6028edfcadd7
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3ee0 @ 0x001e3ee0
// FUN_001e3ee0 @ 0x001e3ee0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3ee0::FUN_001e3ee0(const char* a1, CSPManager_1e3ee0* a2, Fn_1e3ee0 a3) {
    typedef Closure3_1e3ee0<CSPManager_1e3ee0, void, int, int, const char*> Alloc_1e3ee0;
    HULK_SIZE32(Alloc_1e3ee0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3ee0));
    void* x = 0;
    if (m) {
        ((Raw_1e3ee0*)m)->FUN_001e0ac0(a1, a3);
        x = new (m) Closure3_1e3ee0<CSPManager_1e3ee0, void, int, int, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e3f40 FUN_001e3f40 (83 B): equivalent/0x001e3f40.cpp
// sym: ?FUN_001e3f40@Registry_1e3f40@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3f40@2@P832@AEXMMM@Z@Z @05fc09591bd3 @w863958780da8
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3f40 @ 0x001e3f40
// FUN_001e3f40 @ 0x001e3f40  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3f40::FUN_001e3f40(const char* a1, CSPManager_1e3f40* a2, Fn_1e3f40 a3) {
    typedef Closure3_1e3f40<CSPManager_1e3f40, void, float, float, float> Alloc_1e3f40;
    HULK_SIZE32(Alloc_1e3f40, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3f40));
    void* x = 0;
    if (m) {
        ((Raw_1e3f40*)m)->FUN_001e0b60(a1, a3);
        x = new (m) Closure3_1e3f40<CSPManager_1e3f40, void, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e3ff0 FUN_001e3ff0 (83 B): equivalent/0x001e3ff0.cpp
// sym: ?FUN_001e3ff0@Registry_1e3ff0@fn_f75938cb@@QAEXPBDPAVCSPManager_1e3ff0@2@P832@AE_N0MMH@Z@Z @0ca9a86becb6 @wbf839a256550
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e3ff0 @ 0x001e3ff0
// FUN_001e3ff0 @ 0x001e3ff0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e3ff0::FUN_001e3ff0(const char* a1, CSPManager_1e3ff0* a2, Fn_1e3ff0 a3) {
    typedef Closure4_1e3ff0<CSPManager_1e3ff0, bool, const char*, float, float, int> Alloc_1e3ff0;
    HULK_SIZE32(Alloc_1e3ff0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e3ff0));
    void* x = 0;
    if (m) {
        ((Raw_1e3ff0*)m)->FUN_001e0cb0(a1, a3);
        x = new (m) Closure4_1e3ff0<CSPManager_1e3ff0, bool, const char*, float, float, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e40f0 FUN_001e40f0 (83 B): equivalent/0x001e40f0.cpp
// sym: ?FUN_001e40f0@Registry_1e40f0@fn_f75938cb@@QAEXPBDPAVCSPManager_1e40f0@2@P832@AEXHMMMMH@Z@Z @1c8a146d0afe @w055777c82dda
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001e40f0 @ 0x001e40f0
// FUN_001e40f0 @ 0x001e40f0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1e40f0::FUN_001e40f0(const char* a1, CSPManager_1e40f0* a2, Fn_1e40f0 a3) {
    typedef Closure6_1e40f0<CSPManager_1e40f0, void, int, float, float, float, float, int> Alloc_1e40f0;
    HULK_SIZE32(Alloc_1e40f0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1e40f0));
    void* x = 0;
    if (m) {
        ((Raw_1e40f0*)m)->FUN_001e0eb0(a1, a3);
        x = new (m) Closure6_1e40f0<CSPManager_1e40f0, void, int, float, float, float, float, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x001e4190 FUN_001e4190 (124 B): equivalent/0x001e4190.cpp
// sym: _FUN_001e4190 @228fa3b3d3ae @w2adf13d268a9
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 15/18, incomplete)
// FUN_001e4190 @ 0x001e4190
// Insertion sort of [first, last) by ascending key.
extern "C" void FUN_001e4190(void *first, void *last) {
    if (((Item_1e4190 *)first) == ((Item_1e4190 *)last)) {
        return;
    }
    for (Item_1e4190 *cur = ((Item_1e4190 *)first) + 1; cur != ((Item_1e4190 *)last); cur++) {
        Item_1e4190 *next = cur + 1;
        Item_1e4190 *pos;
        if (cur->key < ((Item_1e4190 *)first)->key) {
            pos = ((Item_1e4190 *)first);
        } else {
            pos = cur;
            while (cur->key < (pos - 1)->key) {
                pos--;
            }
        }
        if (pos != cur && cur != next) {
            FUN_001de1f0(pos, cur, next, 0, 0);
        }
    }
}


// 0x001e4210 FUN_001e4210 (156 B): matches/0x001e4210.cpp
// sym: ?FUN_001e4210@fn_f75938cb@@YAXPAUElem20@1@00@Z
// FUN_001e4210 @ 0x001e4210
// FUN_001e4210: median-of-nine pivot selection step of a sort over 20-byte elements
void __cdecl FUN_001e4210(Elem20 *first, Elem20 *mid, Elem20 *last)
{
    int n = (int)(last - first);
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_001e28a0((Elem20 *)first, (Elem20 *)(first + step), (Elem20 *)(first + 2 * step));
        FUN_001e28a0((Elem20 *)(mid - step), (Elem20 *)mid, (Elem20 *)(mid + step));
        FUN_001e28a0((Elem20 *)(last - 2 * step), (Elem20 *)(last - step), (Elem20 *)last);
        FUN_001e28a0((Elem20 *)(first + step), (Elem20 *)mid, (Elem20 *)(last - step));
    } else {
        FUN_001e28a0((Elem20 *)first, (Elem20 *)mid, (Elem20 *)last);
    }
}


// 0x001e4310 FUN_001e4310 (154 B): equivalent/0x001e4310.cpp
// sym: ?FUN_001e4310@CSPManager_1e4310@fn_f75938cb@@QAEHPAUInfo_1e4310@2@PBUKey_1e4310@2@HHHHH@Z @f80b0841cc08 @wd118e6ab8dd7
// STATUS: equivalent (tools/equiv.py level 3: 914 inputs, branch coverage 9/10, incomplete)
// FUN_001e4310 @ 0x001e4310
int CSPManager_1e4310::FUN_001e4310(Info_1e4310 *info, const Key_1e4310 *key, int unused, int a, int b, int c, int d)
{
    for (int i = 0; i < 0x800; i++) {
        if (entries[i].lo == key->lo && entries[i].hi == key->hi)
            return 0;
    }
    int idx = FUN_001dd330(key, &info->pos, a, b, c, d, 1);
    if (idx == -1)
        return 0;
    return FUN_001e2940(entries[idx].id);
}

} // namespace fn_f75938cb

// 0x001e43b0 FUN_001e43b0 (218 B): equivalent/0x001e43b0.cpp [wrapped: conflict: World; content::LoadInventory::DynamicCaster]
// sym: ?FUN_001e43b0@CSPManager_1e43b0@fn_001e43b0@@QAEXHTKeyArg@2@HH@Z @0ba0a9d7e8e8 @waa535c5783a6
namespace fn_001e43b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 6/6)
// FUN_001e43b0 @ 0x001e43b0
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
// Finds a prop in the inventory by key, spawns the matching entity and notifies the event sink.
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



class CSPHulkProp;
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct Key {
    unsigned int lo, hi;
    Key(const Key &src) throw();
};

struct Event_1e43b0 {
    char data[0x28];
    Event_1e43b0 *FUN_001ca9a0(Key a, Key b) throw();
};

struct Sink_1e43b0 {
    void FUN_001cbc20(Event_1e43b0 *e) throw();
};

struct Manager_1e43b0 {
    char pad[0x30];
    Sink_1e43b0 *sink;                     // 0x30
};

struct Spawner_1e43b0 {
    int FUN_001c5080(unsigned int a, int b);
};

struct KeyHolder {
    char pad[8];
    Key key;                        // 8
};

struct Spawned_1e43b0 {
    char pad00[8];
    Key key;                        // 8
    char pad10[0xec - 0x10];
    KeyHolder *holder;              // 0xec
    char pad0f0[0x11c - 0xf0];
    Spawner_1e43b0 *spawner;               // 0x11c
    char pad120[0x144 - 0x120];
    char flag144;                   // 0x144
    char pad145[0x1d8 - 0x145];
    char flag1d8;                   // 0x1d8
    void FUN_001d7510();
};

class Found_1e43b0 {
public:
    virtual void v0();
};

class Inventory_1e43b0 {
public:
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Found_1e43b0 *find(void *caster, unsigned __int64 key);    // slot 3
};

struct Holder2_1e43b0 {
    Inventory_1e43b0 *FUN_00203d70();
};

struct Holder1 {
    Holder2_1e43b0 *FUN_000862a0();
};

struct World {
    char pad[0x54];
    Holder1 *f54;                   // 0x54
};


// The key pointer's argument slot is reused for the caster object.
union KeyArg {
    const unsigned __int64 *key;
    int caster;
};

struct CSPManager_1e43b0 {
    char pad[0x1e830];
    Manager_1e43b0 *manager;               // 0x1e830
    Spawned_1e43b0 *FUN_001e4310(Found_1e43b0 *found, int a, int zero1, int b, int zero2, int c, int zero3);
    void FUN_001e43b0(int a, KeyArg key, int b, int c);
};

void CSPManager_1e43b0::FUN_001e43b0(int a, KeyArg key, int b, int c)
{
    Inventory_1e43b0 *inv = DAT_004dd700->f54->FUN_000862a0()->FUN_00203d70();
    unsigned __int64 id = *key.key;
    new (&key.caster) content::LoadInventory::DynamicCaster<CSPHulkProp>();
    Found_1e43b0 *found = inv->find(&key.caster, id);
    if (!found)
        return;
    Spawned_1e43b0 *s = FUN_001e4310(found, a, 0, b, 0, c, 0);
    if (!s)
        return;
    Sink_1e43b0 *sink = manager->sink;
    if (sink) {
        Event_1e43b0 ev;
        ev.FUN_001ca9a0(s->key, s->holder->key);
        sink->FUN_001cbc20(&ev);
    }
    s->flag144 = 1;
    s->flag1d8 = 1;
    s->spawner->FUN_001c5080((*(unsigned int*)&DAT_00421898), 0);
    s->FUN_001d7510();
}
} // namespace fn_001e43b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f75938cb {

// 0x001e4490 FUN_001e4490 (565 B): equivalent/0x001e4490.cpp
// sym: ?FUN_001e4490@fn_f75938cb@@YAPAUElemPair_1e4490@1@PAU21@PAUElem_1e4490@1@1@Z @89359e72841b @wef988a5629b7
// STATUS: equivalent (tools/equiv.py level 3: 62 inputs, branch coverage 60/62, incomplete)
// FUN_001e4490 @ 0x001e4490
ElemPair_1e4490* FUN_001e4490(ElemPair_1e4490* out, Elem_1e4490* first, Elem_1e4490* last)
{
    Elem_1e4490* mid = first + (last - first) / 2;
    FUN_001e4210(first, mid, last - 1);

    Elem_1e4490* pfirst = mid;
    Elem_1e4490* plast = mid + 1;
    while (first < pfirst && !(pfirst[-1].key < pfirst->key) && !(pfirst->key < pfirst[-1].key))
        --pfirst;
    while (plast < last && !(plast->key < pfirst->key) && !(pfirst->key < plast->key))
        ++plast;

    Elem_1e4490* gfirst = plast;
    Elem_1e4490* glast = pfirst;
    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (pfirst->key < gfirst->key) {
            } else if (gfirst->key < pfirst->key) {
                break;
            } else {
                FUN_001e0fc0(plast++, gfirst);
            }
        }
        for (; first < glast; --glast) {
            if (glast[-1].key < pfirst->key) {
            } else if (pfirst->key < glast[-1].key) {
                break;
            } else {
                FUN_001e0fc0(--pfirst, glast - 1);
            }
        }
        if (glast == first) {
            if (gfirst == last) {
                out->second = plast;
                out->first = pfirst;
                return out;
            }
            if (plast != gfirst)
                FUN_001e0fc0(pfirst, plast);
            ++plast;
            FUN_001e0fc0(pfirst, gfirst);
            ++pfirst;
            ++gfirst;
        } else {
            --glast;
            if (gfirst == last) {
                --pfirst;
                if (glast != pfirst)
                    FUN_001e0fc0(glast, pfirst);
                --plast;
                FUN_001e0fc0(pfirst, plast);
            } else {
                FUN_001e0fc0(gfirst, glast);
                ++gfirst;
            }
        }
    }
}

} // namespace fn_f75938cb

// 0x001e46d0 FUN_001e46d0 (132 B): equivalent/0x001e46d0.cpp [wrapped: conflict: FUN_001e1150]
// sym: _FUN_001e46d0 @72b0e11cd8c4 @w9cc0085f65ca
namespace fn_001e46d0 {
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 5/6, incomplete)
// FUN_001e46d0 @ 0x001e46d0
struct Elem_1e46d0 {
    int a, b, c, d, e;
};

void __cdecl FUN_001e1150(Elem_1e46d0 *first, Elem_1e46d0 *last, Elem_1e46d0 *dest, Elem_1e46d0 value, int flag);

extern "C" void FUN_001e46d0(void *begin, void *end)
{
    Elem_1e46d0 *last = ((Elem_1e46d0 *)end);
    while (last - ((Elem_1e46d0 *)begin) > 1) {
        last--;
        FUN_001e1150(((Elem_1e46d0 *)begin), last, last, *last, 0);
    }
}
} // namespace fn_001e46d0


// 0x001e4760 FUN_001e4760 (116 B): matches/0x001e4760.cpp
// sym: ?FUN_001e4760@CSPManager@@QAEHHHHHHHH@Z
int CSPManager::FUN_001e4760(int a, int b, int c, int d, int e, int f, int g) {
    static Obj_1e4760 s;
    ((owners::Target_27b040 *)&s)->FUN_0027b040((hulk_uintptr)b);
    return ((CSPManager_nv_1e4760*)this)->Fn_001e4310(a, &s, c, d, e, f, g);
}


// 0x001e4e50 FUN_001e4e50 (357 B): equivalent/0x001e4e50.cpp [wrapped: conflict: World]
// sym: ?target@CSPManager_1e4e50@fn_001e4e50@@QAEXHMMMMH@Z @59c00209ab47 @w0c3fb07718b2
namespace fn_001e4e50 {
// STATUS: equivalent (tools/equiv.py level 3: 406 inputs, branch coverage 20/20)
// FUN_001e4e50 @ 0x001e4e50
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

struct State_1e4e50 { int FUN_00088fa0(); int FUN_00088fb0(); };
struct Player_1e4e50 { char pad[0x80]; State_1e4e50 state; };
struct Manager_1e4e50 {  };
struct World { char pad[0x54]; Manager_1e4e50* manager; };
struct Random_1e4e50 { hulk_freg FUN_000787e0(float,float); };
struct Vec_1e4e50 { float x,y,z; };
struct Matrix { float m[16]; void FUN_0022b980();   };
extern void* __cdecl FUN_001d68e0(int);
struct CSPManager_1e4e50 { void FUN_001e4c40(void*,Vec_1e4e50*,int,int,Vec_1e4e50*,int); void target(int,float,float,float,float,int); };
void CSPManager_1e4e50::target(int type,float x,float y,float z,float scale,int count) {
 int active=((Player_1e4e50 *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310())->state.FUN_00088fa0();
 int mode=((Player_1e4e50 *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310())->state.FUN_00088fb0();
 if(active==0 && (mode==1 || mode==10) && (type==1 || type==2 || type==3 || type==4)) return;
 void* resource=FUN_001d68e0(type);
 if(!resource) return;
 Vec_1e4e50 velocity; velocity.x=scale*0.0f; velocity.y=scale*1000.0f; velocity.z=scale*200.0f;
 Vec_1e4e50 position; position.x=x; position.y=y; position.z=z;
 Matrix rotation;
 rotation.FUN_0022b980();
 ((owners::Mat_22ba70 *)&rotation)->FUN_0022ba70((*(Random_1e4e50**)&DAT_004e5acc)->FUN_000787e0(0.0f,6.283185482025146484375f));
 ((owners::M_22c3b0 *)&rotation)->FUN_0022c3b0((float *)(Vec_1e4e50 *)(&velocity), (float *)(Vec_1e4e50 *)(&velocity));
 rotation.FUN_0022b980();
 ((owners::Mat_22ba70 *)&rotation)->FUN_0022ba70(6.283185482025146484375f/count);
 for(int i=count;i>0;--i) {
 FUN_001e4c40(resource,&position,type,0,&velocity,1);
 ((owners::M_22c3b0 *)&rotation)->FUN_0022c3b0((float *)(Vec_1e4e50 *)(&velocity), (float *)(Vec_1e4e50 *)(&velocity));
 }
}
} // namespace fn_001e4e50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e4fc0 FUN_001e4fc0 (161 B): equivalent/0x001e4fc0.cpp [wrapped: conflict: World]
// sym: ?FUN_001e4fc0@CSPManager_1e4fc0@fn_001e4fc0@@QAEXIIII@Z @00935e379d8d @w5b83db487669
namespace fn_001e4fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 16/16)
// FUN_001e4fc0 @ 0x001e4fc0
// FUN_001e4fc0 @ 0x001e4fc0: like 0x001e5070 but skips a missing entry
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

struct Settings_1e4fc0 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};
struct Config_1e4fc0 {
    char pad00[0x80];
    Settings_1e4fc0 settings;
};
struct Manager_1e4fc0 {
};
struct World {
    char pad00[0x54];
    Manager_1e4fc0 *manager;
};

struct Triple_1e4fc0 {
    unsigned a;
    unsigned b;
    unsigned c;
};

void *__cdecl FUN_001d68e0(unsigned kind);

class CSPManager_1e4fc0 {
public:
    void FUN_001e4c40(void *entry, Triple_1e4fc0 *v, unsigned kind, unsigned w, unsigned x, unsigned y);
    void FUN_001e4fc0(unsigned kind, unsigned a, unsigned b, unsigned c);
};

void CSPManager_1e4fc0::FUN_001e4fc0(unsigned kind, unsigned a, unsigned b, unsigned c)
{
    int flag = ((Config_1e4fc0 *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310())->settings.FUN_00088fa0();
    int mode = ((Config_1e4fc0 *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310())->settings.FUN_00088fb0();
    if (flag == 0 && (mode == 1 || mode == 10)) {
        if (kind == 1 || kind == 2 || kind == 3 || kind == 4)
            return;
    }
    void *entry = FUN_001d68e0(kind);
    if (entry == 0)
        return;
    Triple_1e4fc0 v;
    v.a = a;
    v.b = b;
    v.c = c;
    FUN_001e4c40(entry, &v, kind, 0, 0, 1);
}
} // namespace fn_001e4fc0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e5070 FUN_001e5070 (160 B): equivalent/0x001e5070.cpp [wrapped: conflict: World]
// sym: ?FUN_001e5070@CSPManager_1e5070@fn_001e5070@@QAEXIIIII@Z @d16e64a1c04d @w897e0d3710ae
namespace fn_001e5070 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001e5070 @ 0x001e5070
// FUN_001e5070 @ 0x001e5070: same as 0x001e5110 with the trailing flag set
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

struct Settings_1e5070 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};
struct Config_1e5070 {
    char pad00[0x80];
    Settings_1e5070 settings;
};
struct Manager_1e5070 {
};
struct World {
    char pad00[0x54];
    Manager_1e5070 *manager;
};

struct Triple_1e5070 {
    unsigned a;
    unsigned b;
    unsigned c;
};

void *__cdecl FUN_001d68e0(unsigned kind);

class CSPManager_1e5070 {
public:
    void FUN_001e4c40(void *entry, Triple_1e5070 *v, unsigned kind, unsigned w, unsigned x, unsigned y);
    void FUN_001e5070(unsigned kind, unsigned a, unsigned b, unsigned c, unsigned w);
};

void CSPManager_1e5070::FUN_001e5070(unsigned kind, unsigned a, unsigned b, unsigned c, unsigned w)
{
    int flag = ((Config_1e5070 *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310())->settings.FUN_00088fa0();
    int mode = ((Config_1e5070 *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310())->settings.FUN_00088fb0();
    if (flag == 0 && (mode == 1 || mode == 10)) {
        if (kind == 1 || kind == 2 || kind == 3 || kind == 4)
            return;
    }
    void *entry = FUN_001d68e0(kind);
    Triple_1e5070 v;
    v.a = a;
    v.b = b;
    v.c = c;
    FUN_001e4c40(entry, &v, kind, w, 0, 1);
}
} // namespace fn_001e5070
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e5110 FUN_001e5110 (160 B): equivalent/0x001e5110.cpp [wrapped: conflict: World]
// sym: ?FUN_001e5110@CSPManager_1e5110@fn_001e5110@@QAEXIIIII@Z @a4aa8292074a @wfe4ae665f847
namespace fn_001e5110 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001e5110 @ 0x001e5110
// FUN_001e5110 @ 0x001e5110: spawns an effect entry for a kind unless suppressed by settings
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

struct Settings_1e5110 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};
struct Config_1e5110 {
    char pad00[0x80];
    Settings_1e5110 settings;
};
struct Manager_1e5110 {
};
struct World {
    char pad00[0x54];
    Manager_1e5110 *manager;
};

struct Triple_1e5110 {
    unsigned a;
    unsigned b;
    unsigned c;
};

void *__cdecl FUN_001d68e0(unsigned kind);

class CSPManager_1e5110 {
public:
    void FUN_001e4c40(void *entry, Triple_1e5110 *v, unsigned kind, unsigned w, unsigned x, unsigned y);
    void FUN_001e5110(unsigned kind, unsigned a, unsigned b, unsigned c, unsigned w);
};

void CSPManager_1e5110::FUN_001e5110(unsigned kind, unsigned a, unsigned b, unsigned c, unsigned w)
{
    int flag = ((Config_1e5110 *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310())->settings.FUN_00088fa0();
    int mode = ((Config_1e5110 *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310())->settings.FUN_00088fb0();
    if (flag == 0 && (mode == 1 || mode == 10)) {
        if (kind == 1 || kind == 2 || kind == 3 || kind == 4)
            return;
    }
    void *entry = FUN_001d68e0(kind);
    Triple_1e5110 v;
    v.a = a;
    v.b = b;
    v.c = c;
    FUN_001e4c40(entry, &v, kind, w, 0, 0);
}
} // namespace fn_001e5110
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f75938cb {

// 0x001e51b0 FUN_001e51b0 (516 B): equivalent/0x001e51b0.cpp
// sym: ?FUN_001e51b0@CSPManager_1e51b0@fn_f75938cb@@QAEXPAUEntity@2@H@Z @c34be7591f00 @w401a1bdff084
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 13/13)
// FUN_001e51b0 @ 0x001e51b0
    // equiv-conv: FUN_001d6990 ecx stack
    // equiv-conv: FUN_001e51b0 ecx stack esi
void CSPManager_1e51b0::FUN_001e51b0(Entity* e, int extra)
{
    Frame_1e51b0 f;

    f.p.x = e->pos.x;
    f.p.y = e->pos.y + 0.5f;
    f.p.z = e->pos.z;
    if (!FUN_00202560(&f.p, 20.0f, 0, &f.hit, &f.normal, 0, 0, 0))
        f.hit = f.p;

    f.p = *FUN_001dcb00(&f.snapped, &f.hit);

    int shape = ((owners::Target_1d69a0 *)e)->FUN_001d69a0();
    f.corners[0] = f.p;
    f.corners[1] = f.p;
    f.corners[2] = f.p;
    f.corners[3] = f.p;

    switch (shape) {
    case 0:
        return;
    case 2:
        f.corners[0].x = f.p.x + 0.5f;
        f.corners[1].x = f.p.x - 0.5f;
        break;
    case 3:
        f.corners[0].x = f.p.x + 0.5f;
        f.corners[1].x = f.p.x - 0.5f;
        f.corners[1].z = f.p.z - 0.5f;
        f.corners[2].x = f.p.x - 0.5f;
        f.corners[2].z = f.p.z + 0.5f;
        break;
    case 4:
        f.corners[0].x = f.p.x + 0.5f;
        f.corners[0].z = f.p.z + 0.5f;
        f.corners[1].x = f.p.x + 0.5f;
        f.corners[1].z = f.p.z - 0.5f;
        f.corners[2].x = f.p.x - 0.5f;
        f.corners[2].z = f.p.z + 0.5f;
        f.corners[3].x = f.p.x - 0.5f;
        f.corners[3].z = f.p.z - 0.5f;
        break;
    default:
        break;
    }

    int count = e->FUN_001d6990(extra);
    if (count > 0) {
        Listener_1e51b0* l = FUN_001e4c40(FUN_001d68e0(count), f.corners, count, 0, 0, 1);
        if (l)
            l->FUN_001d7460(e);
    }
}

} // namespace fn_f75938cb

// 0x001e53d0 FUN_001e53d0 (211 B): equivalent/0x001e53d0.cpp [wrapped: conflict: FUN_001d68e0]
// sym: ?FUN_001e53d0@CSPManager_1e53d0@fn_001e53d0@@QAEXPAUActor_1e53d0@2@@Z @21dfd56cb353 @wd71213042c42
namespace fn_001e53d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001e53d0 @ 0x001e53d0
struct Vec_1e53d0 { float x,y,z; };
struct PositionSource_1e53d0 { void FUN_00059a50(Vec_1e53d0*); };
struct Actor_1e53d0 { char pad0[0x10]; PositionSource_1e53d0* source; char pad1[0x2144-0x14]; int handle;  };
extern bool __cdecl FUN_00202560(Vec_1e53d0*,float,int,Vec_1e53d0*,Vec_1e53d0*,int,int,int);
extern int __cdecl FUN_001d68e0(int);
struct CSPManager_1e53d0 { Vec_1e53d0* FUN_001dcb00(Vec_1e53d0*,Vec_1e53d0*); void FUN_001e4c40(int,Vec_1e53d0*,int,int,int,int); void FUN_001e53d0(Actor_1e53d0*); };
void CSPManager_1e53d0::FUN_001e53d0(Actor_1e53d0* actor) {
 Vec_1e53d0 position, hit, extra, transformed;
 actor->source->FUN_00059a50(&position);
 position.y += 0.5f;
 if (!FUN_00202560(&position,20.0f,0,&hit,&extra,0,0,0)) {
   hit = position;
   position.y += 0.5f;
 }
 position = *FUN_001dcb00(&transformed,&hit);
 int result = FUN_001d68e0(actor->handle);
 FUN_001e4c40(result,&position,actor->handle,0,0,1);
 ((owners::C_36d40 *)actor)->FUN_00036d40(0);
}
} // namespace fn_001e53d0


// 0x001e54b0 FUN_001e54b0 (130 B): matches/0x001e54b0.cpp
// sym: ?FUN_001e54b0@CSPManager@@QAEXPBD0MMM@Z
// FUN_001e54b0 @ 0x001e54b0
void CSPManager::FUN_001e54b0(const char* nameA, const char* nameB, float x, float y, float z) {
    // Frame slots follow the original's layout; the position block is dead
    // before the second name is built, so they share a slot.
    struct Frame {
        Id_1e54b0 a;
        union {
            Vec3_1e54b0 pos;
            Id_1e54b0 b;
        } u;
        Transform_1e54b0 xf;
        int pad;
    } f;
    f.xf.FUN_0022b980();
    f.u.pos.x = x;
    f.u.pos.y = y;
    f.u.pos.z = z;
    ((owners::Target_22be40 *)&(f.xf))->FUN_0022be40((const int *)(const Vec3_1e54b0 *)(&f.u.pos));
    f.u.b.FUN_0027b0e0(nameB);
    f.a.FUN_0027b0e0(nameA);
    ((CSPManager_nv_1e54b0*)this)->FUN_001e43b0(&f.a, &f.u.b, &f.xf, 0);
    f.a.FUN_0027af50();
    f.u.b.FUN_0027af50();
}

namespace fn_f75938cb {

// 0x001e5540 FUN_001e5540 (171 B): equivalent/0x001e5540.cpp
// sym: ?target@CSPManager_1e5540@fn_f75938cb@@QAEXPAX0UVector@2@MMM@Z @2dbdae383bf7 @w28f5602d5415
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001e5540 @ 0x001e5540
void CSPManager_1e5540::target(void* a,void* b,Vector position,float x,float y,float z) {
 if(a && b) {
 Matrix matrix;
 matrix.FUN_0022b980();
 ((owners::Target_22be40 *)&matrix)->FUN_0022be40((const int *)(const Vector *)(&position));
 ((owners::Matrix_22bc20 *)&matrix)->FUN_0022bc20(x*0.0174532924f, y*0.0174532924f, z*0.0174532924f);
 Handle_1e5540 first,second;
 Handle_1e5540* pb=first.FUN_0027b0e0(b);
 Handle_1e5540* pa=second.FUN_0027b0e0(a);
 FUN_001e43b0(pa,pb,&matrix,1);
 second.FUN_0027af50();
 first.FUN_0027af50();
 }
}


// 0x001e55f0 FUN_001e55f0 (294 B): equivalent/0x001e55f0.cpp
// sym: _FUN_001e55f0 @e4d107566782 @w7226ffe4520f
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 12/14, incomplete)
// FUN_001e55f0 @ 0x001e55f0
extern "C" void __cdecl FUN_001e55f0(Item_1e55f0* begin, Item_1e55f0* end, int depth) {
 hulk_intptr count = end-begin;
 while (count > 32) {
  if (depth <= 0) {
   if (end-begin > 1) FUN_001e2800(begin,end,0,0);
   FUN_001e46d0((Item_1e55f0 *)begin,(Item_1e55f0 *)end);
   return;
  }
  Partition p;
  FUN_001e4490(&p,begin,end);
  depth = depth/2 + (depth/2)/2;
  if (p.first-begin < end-p.second) {
   FUN_001e55f0(begin,p.first,depth);
   begin=p.second;
  } else {
   FUN_001e55f0(p.second,end,depth);
   end=p.first;
  }
  count=end-begin;
 }
 if(count>1) FUN_001e4190((Item_1e55f0 *)begin,(Item_1e55f0 *)end);
}


// 0x001e5720 FUN_001e5720 (125 B): equivalent/0x001e5720.cpp
// sym: ?Run@CSPManager_1e5720@fn_f75938cb@@QAEXPAVThing_1e5720@2@@Z @976ed32341ac @wc61b3bba63fc
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 8/8)
// FUN_001e5720 @ 0x001e5720
    // equiv-conv: FUN_001e51b0 ecx stack esi
void CSPManager_1e5720::Run(Thing_1e5720* p) {
    if (!p)
        return;
    p->Init_001d7ff0();
    if (p->f14e)
        Notify_001e51b0(p, (int)p);
    p->Set_001d6290(1);
    if (p->f14c) {
        p->Set_001d6290(1);
        mgr->m->FnA_0007bac0(&p->pad0[8]);
    }
    if (p->f14d) {
        p->Set_001d6290(1);
        ((owners::C_7def0 *)(mgr->m))->FUN_0007def0((hulk_intptr)(&p->pad0[8]));
    }
}


// 0x001e57a0 FUN_001e57a0 (57 B): matches/0x001e57a0.cpp
// sym: ?Cleanup@CSPManager_1e57a0@fn_f75938cb@@QAEXXZ
void CSPManager_1e57a0::Cleanup() {
    int i = 0;
    if (count > 0) {
        int* p = values;
        do {
            ClearOne_001e53d0(*p);
            ++i;
            ++p;
        } while (i < count);
    }
    Finish_001df290();
}


// 0x001e57e0 FUN_001e57e0 (122 B): equivalent/0x001e57e0.cpp
// sym: ?FUN_001e57e0@CSPManager_1e57e0@fn_f75938cb@@QAEXHHUVec3_1e57e0@2@@Z @023191d77c52 @w1eec8aaf3768
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e57e0 @ 0x001e57e0
void CSPManager_1e57e0::FUN_001e57e0(int a, int b, Vec3_1e57e0 pos) {
    FUN_001e5540(a, b, pos, Vec3_1e57e0(0.0f, 0.0f, 0.0f));
}


// 0x001e5860 FUN_001e5860 (98 B): matches/0x001e5860.cpp
// sym: ?target@CSPManager_1e5860@fn_f75938cb@@QAEXHHUV@2@@Z
void CSPManager_1e5860::target(int a, int b, V v) {
    V zero;
    inner_001e5540(a, b, v, zero);
}


// 0x001e58d0 FUN_001e58d0 (120 B): equivalent/0x001e58d0.cpp
// sym: ?FUN_001e58d0@CSPManager_1e58d0@fn_f75938cb@@QAEXPBD0UVec3_1e58d0@2@1@Z @d8de4a1865f2 @w06984f9eae76
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_001e58d0 @ 0x001e58d0
void CSPManager_1e58d0::FUN_001e58d0(const char* a, const char* b, Vec3_1e58d0 v1, Vec3_1e58d0 v2) {
    FUN_001e5540(a, b, v1, v2);
}

} // namespace fn_f75938cb

// 0x001e5980 FUN_001e5980 (554 B): equivalent/0x001e5980.cpp [wrapped: conflict: FUN_001c3d90; Matrix; World]
// sym: ?FUN_001e5980@Manager_1e5980@fn_001e5980@@QAEXH@Z @4b7ae19f4781 @w44d0c9368c71
namespace fn_001e5980 {
// STATUS: equivalent (tools/equiv.py level 3: 20027 inputs, branch coverage 32/32)
// FUN_001e5980 @ 0x001e5980
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

struct V3_1e5980 {
    float x, y, z;
};

struct Matrix {
    char pad0[0x30];
    V3_1e5980 pos;                         // 0x30
};

struct Item_1e5980 {
    char pad0[8];
    int type;                       // 0x8
    char padc[4];
};

struct Parent_1e5980 {
    unsigned char valid;            // 0x0
    char pad1[3];
    int next;                       // 0x4
};

struct Node {
    char pad0[0x10];
    Parent_1e5980 *parent;                 // 0x10
    char pad14[0x34 - 0x14];
    int itemCount;                  // 0x34
    Item_1e5980 *items;                    // 0x38
};

struct NodeTable {
    char pad0[0x1c];
    Node **nodes;                   // 0x1c
};

struct Holder_1e5980 {
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
    virtual char check();           // 0x2c
};

struct Link_1e5980 {
    char pad0[0x70];
    Holder_1e5980 *holder;                 // 0x70
};

struct Quat_1e5980 {
    float v[4];
};

struct Slot_1e5980 {
    virtual void v0();
    virtual void release();         // 0x4
};

struct Entity {
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
    virtual Matrix *worldMatrix();  // 0x3c
    int field4;
    int field8;                     // 0x8 (after the vptr and field4)
    char padc[0x40 - 0xc];
    int nodeIndex;                  // 0x40
    float scale;                    // 0x44
    char pad48[0x98 - 0x48];
    NodeTable *table;               // 0x98
    char pad9c[0x108 - 0x9c];
    unsigned short word108;         // 0x108
    char pad10a[0x144 - 0x10a];
    unsigned char flag144;          // 0x144

    int FUN_001d62c0();
    char FUN_001d7300();
    float FUN_001d6cd0();
    void FUN_001d6770();
};

struct Pose {
    char data[8];
    void FUN_001db780(Quat_1e5980 *q);
};

struct Entry40 {
    char pad0[0x10];
    Pose pose;                      // 0x10
    Slot_1e5980 *slot;                     // 0x18
    char pad1c[4];
    short field20;                  // 0x20
    char pad22[2];
    short field24;                  // 0x24
    unsigned char count26;          // 0x26
    unsigned char free27;           // 0x27
};

struct Entry20 {
    V3_1e5980 pos;                         // 0x00
    char padc[4];
    union {
        unsigned short flags;       // 0x10
        struct {
            unsigned char flagsLo;  // 0x10
            unsigned char flagsHi;  // 0x11
        };
    };
    short slotIndex;                // 0x12
};

struct Pool_1e5980 {
    void FUN_001c3b80(int *p);
};
Pool_1e5980 *__cdecl FUN_001c3d90();

struct Registry_1e5980 {
    void FUN_001b4540(Entity *e);
};
extern "C" void * __cdecl FUN_001b6580(void);

struct Limits_1e5980 {
    char pad0[0x18];
    float maxY;                     // 0x18
};
struct World {
    char pad0[0x24];
    Limits_1e5980 *limits;                 // 0x24
};

class Manager_1e5980 {
public:
    char pad0[0x608];
    Entry40 slots[0x800];           // 0x608
    Entry20 entries[1];             // 0x14608

    void FUN_001de3f0(Entity *e);
    void FUN_001e5720(Entity *e);
    void FUN_001e5bc0(int a);
    void FUN_001e5980(int idx);
};

void Manager_1e5980::FUN_001e5980(int idx)
{
    struct Frame {
        bool found;
        V3_1e5980 pos;
        Quat_1e5980 rot;
    } fr;

    Entry20 *ent = &entries[idx];
    Entry40 *slot = &slots[ent->slotIndex];
    if (!(ent->flagsLo & 1))
        return;

    Entity *e = (Entity *)slot->slot;
    e->v0();
    ((owners::Owner_27cf40 *)e)->FUN_0027cf40(e->FUN_001d62c0());

    fr.found = false;
    bool first = true;
    int n = e->nodeIndex;
    if (n >= 0) {
        Node **nodes = e->table->nodes;
        for (;;) {
            Node *node = nodes[n];
            bool hit = false;
            for (int k = 0; k < node->itemCount; ++k) {
                if (node->items[k].type == 1) {
                    hit = true;
                    break;
                }
            }
            if (hit) {
                fr.found = true;
                break;
            }
            if (!first)
                break;
            Parent_1e5980 *parent = node->parent;
            if (parent->valid == 0)
                break;
            n = parent->next;
            first = false;
            if (n < 0)
                break;
        }
    }

    ent->flags &= 0xbffe;

    hulk_freg v = e->scale * 100.0f;
    if (!(v < 65000.0f))
        v = 65000.0f;
    slot->count26 = (unsigned char)e->nodeIndex;
    slot->field20 = (short)(__int64)v;
    slot->field24 = e->word108;

    bool noBlock;
    if (!e->FUN_001d7300())
        noBlock = true;
    else if (!((Link_1e5980 *)((owners::C_1d72e0 *)e)->FUN_001d72e0())->holder->check())
        noBlock = false;
    else
        noBlock = e->FUN_001d6cd0() <= 0.0f;
    slot->free27 = noBlock;

    if (e->flag144)
        ent->flagsHi |= 0x20;

    ((owners::Quat_22b370 *)&(fr.rot))->FUN_0022b370((const float *)(Matrix *)(e->worldMatrix()));
    slot->pose.FUN_001db780(&fr.rot);

    fr.pos = e->worldMatrix()->pos;
    ent->flagsLo |= 4;
    ent->pos = fr.pos;

    if (slot->slot) {
        slot->slot->release();
        slot->slot = 0;
    }

    FUN_001c3d90()->FUN_001c3b80(&e->field8);
    ((Registry_1e5980 *)FUN_001b6580())->FUN_001b4540(e);
    FUN_001de3f0(e);

    if (fr.pos.y < DAT_004dd700->limits->maxY) {
        e->FUN_001d6770();
        FUN_001e5720(e);
        FUN_001e5bc0(((owners::C_1d6c70 *)e)->FUN_001d6c70());
    }
    if (fr.found) {
        FUN_001e5720(e);
        FUN_001e5bc0(((owners::C_1d6c70 *)e)->FUN_001d6c70());
    }
    e->v1();
}
} // namespace fn_001e5980
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001e5bb0 FUN_001e5bb0 (13 B): matches/0x001e5bb0.cpp
// sym: ?FUN_001e5bb0@CSPManager@@QAEXHH@Z
void CSPManager::FUN_001e5bb0(int a, int b) {
    ((CSPManager_nv_1e5bb0*)(this))->FUN_001e5720(a);
}


// 0x001e5bc0 FUN_001e5bc0 (798 B): equivalent/0x001e5bc0.cpp [wrapped: conflict: Node]
// sym: ?FUN_001e5bc0@CSPManager_1e5bc0@fn_001e5bc0@@QAEXH@Z @5aa4676d1bd6 @wc0973927dd90
namespace fn_001e5bc0 {
// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 34/34)
// FUN_001e5bc0 @ 0x001e5bc0
struct Item_1e5bc0 {
    char pad00[0x16];
    short s16;
    char pad18[0x22 - 0x18];
    short s22;
    char pad24[4];
    void FUN_001dbba0();
};

struct Node {
    int w0;
    int w4;
    int w8;
    unsigned int wc;
    unsigned char flags;
    unsigned char flags2;
    short item;
};

class CSPManager_1e5bc0 {
public:
    char pad000[0x608];
    Item_1e5bc0 items[0x800];
    Node nodes[0x800];
    int pad1e608;
    int a;
    int b;
    int c;
    char pad1e618[0x1ec58 - 0x1e618];
    int counter;
    void FUN_001e5980(int node);
    void FUN_001e5bc0(int idx);
};

void CSPManager_1e5bc0::FUN_001e5bc0(int idx)
{
    if (idx < 0 || idx >= 0x800)
        return;
    Item_1e5bc0* it = &items[idx];
    if (it->s16 == 0)
        return;
    int ni = it->s22;
    Node* n = &nodes[ni];
    if (n->flags & 1) {
        FUN_001e5980(ni);
        if (it->s16 == 0)
            return;
    }
    if (n->flags2 & 0x20)
        counter--;
    it->FUN_001dbba0();
    int last = c - 1;
    int e = ni;
    if (ni != last) {
        if (ni < a) {
            if (ni != a - 1) {
                nodes[ni] = nodes[a - 1];
                items[nodes[ni].item].s22 = (short)ni;
                e = a - 1;
            }
            if (b <= c - 1) {
                nodes[e] = nodes[b];
                items[nodes[e].item].s22 = (short)e;
                e = b;
            }
            if (e < c - 1) {
                nodes[e] = nodes[c - 1];
                items[nodes[e].item].s22 = (short)e;
            }
            a = a - 1;
            b = b - 1;
        } else if (ni <= b && b <= last) {
            if (ni != b) {
                nodes[ni] = nodes[b];
                items[nodes[ni].item].s22 = (short)ni;
                e = b;
            }
            if (e < c - 1) {
                nodes[e] = nodes[c - 1];
                items[nodes[e].item].s22 = (short)e;
            }
            b = b - 1;
        } else {
            nodes[ni] = nodes[c - 1];
            items[nodes[ni].item].s22 = (short)ni;
        }
    }
    Node* t = &nodes[c - 1];
    t->w0 = 0;
    t->w4 = 0;
    t->w8 = 0;
    t->wc = 0x7f7fffff;
    t->flags = 0;
    t->flags2 = 0;
    t->item = -1;
    c = c - 1;
    if (a > c)
        a = c;
    if (b > c)
        b = c;
}
} // namespace fn_001e5bc0

