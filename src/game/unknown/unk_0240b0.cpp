// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000240b0..0x0002c4f0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6d645d0 {
#define TREE_TU_END }
namespace fn_f6d645d0 {} using namespace fn_f6d645d0;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f6d645d0 {
extern "C" __int64 __cdecl fetch_002672f0(int, int, int);
struct Part_24130 {
    char x[8];
    void FnF_0027af00();
};
struct Obj_24130 {
    char pad[0x40];
    Part_24130 a;
    Part_24130 b;
    Obj_24130* Target();
};
struct Sub_24150 {
    void Helper_0027af50();
};
struct Owner_24150 {
    char pad[0x40];
    void Func();
};
class Obj_24190 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int f11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
    virtual int f15();
    virtual int f16();
    virtual int f17();
    int pad[2];
    int count;
    int items[1];
    hulk_intptr get(int index);
};
class Helper_24190 {
  public:
};
struct Item_241c0 {
    char pad[8];
    unsigned __int64 id;
};
struct Sub_241c0 {
};
struct Mgr_241c0 {
    char pad[0x44];
    Sub_241c0* sub;
};
unsigned __int64 Hash_0027b020(int);
class List_241c0 {
  public:
    Mgr_241c0* mMgr;
    char pad[8];
    int mCount;
    int mIds[1];
    int Find(int key);
};
typedef unsigned char u8_242d0;
struct Obj_242d0 {
    u8_242d0 run_00035ab0();
};
typedef unsigned char u8_24300;
struct Obj_24300 {
    u8_24300 run_00035a90();
};
class Helper_24380 {
  public:
};
class Obj_24380 {
  public:
    virtual void v0();
    char pad[8];
    int count;
    int items[1];
    bool find(int);
};
struct Obj_243d0 {
    char pad[0x124];
    void* member;
    void* go_00036d00();
};
void InitGlobal_000436f0();
int __stdcall FUN_00024400(int a, int b);
struct Y_244a0 {
    void Fng_00044be0(int);
};
struct X_244a0 {
    char pad[4];
    Y_244a0* p;
    void f(hulk_intptr);
};
class EnergyDoorParams_244c0 {
  public:
    void Set(int a, int b);
};
class Helper_244e0 {
  public:
};
class Owner_244e0 {
  public:
    char pad[0x44];
    Helper_244e0* mHelper;
};
class Outer_244e0 {
  public:
    Owner_244e0* mOwner;
    int pad[2];
    int count;
    int items[1];
    void run();
};
class Helper_24510 {
  public:
};
class Owner_24510 {
  public:
    char pad[0x44];
    Helper_24510* mHelper;
};
class Outer_24510 {
  public:
    Owner_24510* mOwner;
    int pad[2];
    int count;
    int items[1];
    void run();
};
class Obj_24570 {
  public:
    char pad[0x588];
    unsigned char mValue;
    void Set(unsigned char value);
};
class Inner_24580 {
  public:
};
class Holder_24580 {
  public:
    char pad[0x44];
    Inner_24580* inner;
};
class Obj_24580 {
  public:
    Holder_24580* owner;
    int pad[2];
    int count;
    int values[1];
    void Target(int unused);
};
typedef unsigned __int64 Key_245b0;
struct Vec_245b0 { float x,y,z; };
struct Entry_245b0 { char pad[0x30]; Vec_245b0 position; char tail[4]; };
struct Bones_245b0 { char pad[0x1c]; Entry_245b0 *entries; unsigned FUN_002843a0(Key_245b0 key); };
struct Owner_245b0 { char pad[0x120]; Bones_245b0 *bones; };
struct Result_245b0 { void FUN_001c3c10(int, Vec_245b0*); };
extern Result_245b0* __cdecl FUN_001c3d90();
struct Target_245b0 { char pad[0x124]; Owner_245b0 *owner; void FUN_000245b0(); };
struct Pair {
  public:
    union { int a; int first; };
    union { int b; int second; };
};
} // namespace fn_f6d645d0
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memmove(void*, const void*, unsigned int);
#endif
namespace fn_f6d645d0 {
class Target_24770 {
  public:
    char pad[0x584];
    int value;
    void Set(int x);
};
struct Item_24780 {
    char pad[8];
    unsigned __int64 v;
};
struct Mgr_24780 {
};
struct Owner_24780 {
    char pad[0x44];
    Mgr_24780* mgr;
};
struct C_24780 {
    Owner_24780* owner;
    char pad[8];
    int count;
    int ids[1];
    int Target(unsigned a);
};
unsigned __int64 Hash_0027b020(unsigned a);
class Worker_24800 {
  public:
};
struct Container_24800 {
    char pad[0x44];
    Worker_24800* worker;
};
class Owner_24800 {
  public:
    Container_24800* mCont; // 0x00
    int f4;           // 0x04
    int f8;           // 0x08
    int count;        // 0x0c
    int arr[69];      // 0x10 .. 0x123
    int cmpVal;       // 0x124

    int func();
};
extern char hulk_at_003f335c;
struct Sub_248e0 {
};
struct Item_248e0 {
    void* Get_00036d00();
};
struct Owner_248e0 {
    char pad[0x44];
    Sub_248e0* sub;
};
struct Thing_248e0 {
    Owner_248e0* owner;
    char pad[8];
    int count;
    int items[69];
    int excluded;
    void* run(int);
};
struct Obj_24970 {
    char pad[0x20a8];
    int a;
    int b;
};
struct B_249d0 {
    char pad[0x44];
    struct Lookuper* lk;
};
struct Lookuper {
};
struct Node {
  public:
    char _m_pad_0[0x14];
    Node* parent;
    char _m_pad_18[0x2090];
    int a;
    int b;
    void FUN_00231ad0(void *slot, int arg, unsigned int flags);
};
class Target_249d0 {
  public:
    B_249d0* mB;
    int pad1[2];
    int mCount;
    int mArr[1];
    bool Process();
};
struct Head_24a10 { char pad[0xb4]; };
struct NodeB_24a10 { char data[0x28]; void FUN_00232240(); };
struct NodeA_24a10 { char data[0x20]; void FUN_00232240(); };
struct Item_24a10 : public Head_24a10, public NodeB_24a10, public NodeA_24a10 {
    void FUN_00037000();
};
struct Registry_24a10 {  };
struct Owner_24a10 { char pad[0x44]; Registry_24a10* registry; };
struct Inner_24a10 { char pad[0x124]; Item_24a10* current; };
} // namespace fn_f6d645d0
struct World { char pad[0x20]; Inner_24a10* inner; };
namespace fn_f6d645d0 {
struct Group_24a10 {
    Owner_24a10* owner;
    char pad4[8];
    int count;
    int ids[16];
    bool FUN_00024a10();
};
struct Name_24b00 {
    char pad0[8];
    char c8;
    char c9;
    char padA[2];
    bool FUN_0027af90(const Name_24b00* other);
};
struct Item_24b00 { char pad[0x22b8]; Name_24b00 name; };
struct Registry_24b00 {  };
struct Owner_24b00 { char pad[0x44]; Registry_24b00* registry; };
struct Group_24b00 {
    Owner_24b00* owner;
    char pad4[8];
    int count;
    int ids[16];
    int FUN_00024b00(const Name_24b00* key);
};
extern "C" void* __cdecl FUN_000678d0();
struct Result {
  public:
    char _m_pad_0[0x1b40];
    int a;
    int b;
    char _m_pad_1b48[0x158];
    class Mid* mid;
    char _m_pad_1ca4[0x49c];
    unsigned char flag;
    void* FUN_00035140(void* value);
    char Check_000353d0(void*);
    char Check_000360f0();
    void get_00035760(void*);
};
struct Provider {
};
struct Header {
    char padding[0x44];
    Provider* provider;
};
struct Container {
    Header* header;
    char padding[8];
    int count;
    void* entries[1];
    void* FUN_00024e90(int index, void* value);
};
class C_24f50 {
  public:
};
typedef unsigned __int64 U64_24f60;
struct Detail_24f60 { char pad[0x9e]; unsigned char enabled; char pad9f; unsigned low; unsigned high; };
struct Item_24f60 { char pad[0x1ca0]; Detail_24f60* detail; };
struct Manager_24f60 {  };
struct Owner_24f60 { char pad[0x44]; Manager_24f60* manager; };
struct List_24f60 { Owner_24f60* owner; char pad[8]; int count; unsigned ids[1]; int FUN_00024f60(const char* text); };
typedef unsigned __int64 U64_25010;
struct Info_25010 { char pad[0x9e]; unsigned char enabled; char pad2; U64_25010 key; };
struct Item_25010 { char pad[0x1ca0]; Info_25010* info; const char* FUN_00036d00(); };
struct Registry_25010 {  };
struct Owner_25010 { char pad[0x44]; Registry_25010* registry; };
struct Target_25010 { Owner_25010* owner; char pad[8]; int count; int ids[1]; const char* FUN_00025010(const char* name,int occurrence); };
struct X_25260 {
};
struct Y_25260 {
    void Use_000368d0(int);
};
struct Ctx_25370 {
    int pad[17];
};
struct Act_25370 {
    int pad;
    void Do_00036910(int);
};
struct Ctx_253c0 {
    int pad[17];
};
struct Act_253c0 {
    int pad;
    void Do_00035fa0(int);
};
struct Triple {
  public:
    union { unsigned a; unsigned int x; };
    union { unsigned b; unsigned int y; };
    unsigned int z;
};
void __cdecl FUN_00095fa0(Triple* value, unsigned int arg);
class Item_25470 {
  public:
    char pad0[0x128];
    int id;
    char pad1[0x20b4 - 0x12c];
    float value;
};
class Manager_25470 {
  public:
};
class C {
  public:
    char pad[0xd4];
    int x;
    int y;
    int z;
    void Set(int a, int b, int c);
};
struct O {
    char pad[0x50];
    unsigned char b50;
    char pad2[0x80];
    int d1;
    int d2;
    int d3;
    void Fn();
};
struct Obj_25560 {
    char pad[0x353];
    unsigned char m353;
    void Clear();
};
class Obj_25570 {
  public:
    char pad[0x32c];
    int value;
    void Set(int v);
};
class Obj_25580 {
  public:
    char pad[0x32c];
    int m32c;
    int GetX();
};
struct Mat4_25590 { float m[16]; };
struct Name_25590 {
    int lo;
    int hi;
    void FUN_0027af00();
    void FUN_0027af50();
    void FUN_0027af70(int v);
};
struct Record_25590 {
    char pad0[0x44];
    char fixed;             // 0x44
    char pad1[3];
    int key;                // 0x48
};
struct Layout_25590 {
    void FUN_00283a40(Name_25590 *n, const Mat4_25590 *m, int a, int v);
};
Layout_25590 *FUN_0027f250();
struct Entry_25590 {              // 0x68 bytes
    Mat4_25590 mat;               // 0x00
    Name_25590 nameA;             // 0x40
    Name_25590 nameB;             // 0x48
    int key;                // 0x50
    unsigned int stamp;     // 0x54
    int f58;
    int f5c;
    int f60;
    char fixed;             // 0x64
    char pad[3];
};
class Mgr_25590 {
public:
    char pad0[0x58c];
    int count;              // 0x58c
    Entry_25590 entries[16];      // 0x590
    void FUN_00025590(Record_25590 *rec, int a1, int a2, int a3, int a4, const Mat4_25590 *mat, int a6, unsigned int stamp);
};
struct E_25720 {
    char x[0x50];
    int key;
    char y[0x10];
    char flag;
};
extern int __cdecl FUN_00096600(const char*, const char*);
extern void* __cdecl FUN_00267830(void* dst, const void* src, int n);
class Table_25820 {
  public:
    char pad[0xc10];
    char names[9][32];
    void FUN_00025820(const char* name, const void* src);
};
class Palette_258b0 {
public:
    char pad0[0xd30];
    unsigned int colors[4];
    void FUN_000258b0(const char *name, float r, float g, float b);
};
class Obj_25960 {
  public:
    virtual void A();
    virtual void B();
};
struct Vec3 {
    float x, y, z;
};
struct Vec3I { int x, y, z; };
struct Params {
    char pad00[0xc];
    int state;          // 0x0c
    char pad10[0x48 - 0x10];
    int a;              // 0x48
    int b;              // 0x4c
    Vec3I v0;           // 0x50
    Vec3I v1;           // 0x5c
    int lo;             // 0x68
    int hi;             // 0x6c
    void Set(int a, int b, const Vec3I* v0, const Vec3I* v1, float lo, float hi);
};
void *FUN_0008d690(unsigned int size);
struct Name_25a90 {
    int lo;
    int hi;
    void FUN_0027af00();
};
struct Entry_25a90 {              // 0x68 bytes
    char pad0[0x40];
    Name_25a90 nameA;             // 0x40
    Name_25a90 nameB;             // 0x48
    char pad50[0x68 - 0x50];
};
struct Pair_25a90 {
    int a;
    int b;
};
struct Slot_25a90 {
    char flag;
    char pad[0x1f];
};
struct Thing_25a90;
struct CCharacterTemplateManager_25a90 {
    CCharacterTemplateManager_25a90 *FUN_00047890(Thing_25a90 *owner, int n);
};
struct Obj908 {
    Obj908 *FUN_00067ea0();
};
struct Registry_25a90 {
    void *FUN_00232840(unsigned int lo, unsigned int hi);
};
void __cdecl FUN_00232d70(void (*fn)(), int arg);
void FUN_00024120();
void __cdecl FUN_000553d0(void *p);
void __cdecl FUN_00073700(void *p);
void __cdecl FUN_00055d80(void *p);
void __cdecl FUN_00074790(void *p);
void __cdecl FUN_00056460(void *p);
void __cdecl FUN_000749e0(void *p);
struct ThisNote_00031310 {
    void FUN_00031310();
};
struct Thing_25a90 {
    int f00;
    CCharacterTemplateManager_25a90 *f04;
    Obj908 *f08;
    int f0c;
    char pad10[0x50 - 0x10];
    char f50;
    char pad51[0x94 - 0x51];
    char f94[0xd4 - 0x94];
    int fd4;
    int fd8;
    int fdc;
    int zeros[16];          // 0xe0
    char pad120[0x124 - 0x120];
    int f124;
    char f128;
    char pad129[0x228 - 0x129];
    Pair_25a90 pairs[32];         // 0x228
    int f328;
    int f32c;
    char pad330[0x33c - 0x330];
    float f33c;
    int f340;
    int f344;
    int f348;
    int f34c;
    char f350;
    char f351;
    char f352;
    char f353;
    int f354;
    int f358;
    int f35c;
    int f360;
    int f364;
    int f368;
    char f36c;
    char pad36d[3];
    int f370;
    int f374;
    int f378;
    char pad37c[0x580 - 0x37c];
    int f580;
    char pad584[0x590 - 0x584];
    Entry_25a90 entries[16];      // 0x590
    Slot_25a90 slots[9];
    unsigned int fd30;
    unsigned int fd34;
    unsigned int fd38;
    Thing_25a90 *FUN_00025a90();
};
struct Vec_25d50 { float x,y,z; };
struct Actor_25d50 { bool FUN_00035ab0(); int FUN_00036d00(); };
struct Entry_25d50 { Actor_25d50* FUN_00059a30(); void FUN_00059a50(Vec_25d50*); };
struct Manager_25d50 { Entry_25d50* FUN_00059ba0(int);  };
struct Owner_25d50 { char pad[0x44]; Manager_25d50* manager; };
struct Selection_25d50 { Owner_25d50* owner; char pad[8]; int count; int ids[1]; int FUN_00025d50(float x,float y,float z); };
extern void __fastcall InitThing_00044c00(void*);
extern "C" __int64 __cdecl Find(int, int, int);
extern "C" __int64 __cdecl Convert(int, int, int);
struct Vec3_26910 {
    int x, y, z;
};
typedef unsigned __int64 Key_26c30;
struct Vec3_26c30 {
    float x, y, z;
};
struct Child_26c30 {
    void FUN_00059a50(Vec3_26c30* out);
};
struct Entry_26c30 {
    char pad[0x10];
    Child_26c30* child;
};
struct Owner_26c30 {
    Entry_26c30* FUN_00024280(Key_26c30 key);
    Vec3_26c30 FUN_00026c30(const char* name);
};
struct Vec3_26cc0 {
    float x, y, z;
};
struct Pawn_26cc0 {
};
struct Group_26cc0 {
    Pawn_26cc0 *FUN_00024280(unsigned __int64 key);
    Vec3_26cc0 *FUN_00026cc0(Vec3_26cc0 *out, const char *name);
};
struct Name_26f30 {
    unsigned int lo, hi;
    Name_26f30 *FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};
struct Link_26f30 {
    char pad0[0x118];
    unsigned int nameLo;
    unsigned int nameHi;
};
struct Pawn_26f30 {
    char pad0[0x1ca0];
    Link_26f30 *link;
};
struct Group_26f30 {
    Pawn_26f30 *FUN_00024280(unsigned __int64 key);
    bool FUN_00026f30(const char *pawnName, const char *linkName);
};
struct Item {
  public:
    char _m_pad_0[0x11c];
    struct Handler* handler;
    char _m_pad_120[0x1a48];
    int a;
    int b;
    int c;
};
extern "C" unsigned __int64 __cdecl makeKey_002672f0(void*, int, int);
Pair __cdecl other_002672f0(int, int, int);
} // namespace fn_f6d645d0
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
namespace fn_f6d645d0 {
extern "C" unsigned __int64 __cdecl source_002672f0(unsigned, unsigned, unsigned);
extern U64 __cdecl lookup_002672f0(void*, int, int);
extern void __cdecl FUN_00224d70(float angle, struct V3_27b50 *v);
struct V3_27b50 {
    float x, y, z;
};
struct Sub_27b50 {
    char FUN_00059a50(V3_27b50 *out);
};
struct Desc_27b50 {
    unsigned int idLo, idHi;
    V3_27b50 pos;
    int pad14;
    V3_27b50 dir;
    char f24;
    char pad25[0x54 - 0x25];
    int f54;
    float f58;
    char pad5c[0x68 - 0x5c];
    int f68;
    char pad6c[0x74 - 0x6c];
    int f74;
    char pad78[0x98 - 0x78];
    Desc_27b50 *FUN_00059820();
    void FUN_000595f0(V3_27b50 *v, int a, float b, int c);
    void FUN_00059300();
};
struct Obj_27b50 {
    char pad0[0x10];
    Sub_27b50 *sub;
    char FUN_00035550(V3_27b50 *out);
    char FUN_000437a0(int a, Desc_27b50 *d, int b, int c, int e);
};
struct Table_27b50 {
    Obj_27b50 *FUN_00024280(unsigned __int64 key);
    void FUN_00027b50(const char *name, float a1, int a2, float a3, int a4, int a5, const char *s);
};
struct Frame_27b50 {
    V3_27b50 v;
    Desc_27b50 d;
};
typedef unsigned __int64 Key_27c90;
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, const void *srcType, const void *dstType, int isRef);
extern char DAT_0048e090;
extern char DAT_0048e0ac;
struct Found_27c90 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Node *Resolve(int arg, int zero);       // slot 8
};
struct Flags_27c90 {
    char pad[0xa8];
    char flag;                      // 0xa8
};
struct Pawn2 {
    char pad00[0xdc];
    char slot[4];                   // 0xdc
    char pad0e0[0x104 - 0xe0];
    int arg;                        // 0x104
};
struct Tree_27c90 {
    Found_27c90 *FUN_00233580(const char *path);
};
struct Entry_27c90 {
    char pad[0x5c];
    Tree_27c90 *tree;                     // 0x5c
};
struct Registry_27c90 {
    Entry_27c90 *FUN_00232840(Key_27c90 key);
};
struct Group_27c90 {
    Pawn2 *FUN_00024280(Key_27c90 key);
    void FUN_00027c90(const char *name, const char *path);
};
typedef unsigned __int64 Key_27d60;
extern char DAT_0048e0c8;
struct Found_27d60 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Node *Resolve(int arg, int zero);       // slot 8
};
struct Pawn_27d60 {
    char pad00[0xb4];
    char slot[4];                   // 0xb4
    char pad0b8[0x104 - 0xb8];
    int arg;                        // 0x104
};
struct Tree_27d60 {
    Found_27d60 *FUN_00233580(const char *path);
};
struct Entry_27d60 {
    char pad[0x5c];
    Tree_27d60 *tree;                     // 0x5c
};
struct Registry_27d60 {
    Entry_27d60 *FUN_00232840(Key_27d60 key);
};
struct Group_27d60 {
    Pawn_27d60 *FUN_00024280(Key_27d60 key);
    void FUN_00027d60(const char *name, const char *path);
};
typedef unsigned __int64 Key_28050;
struct Handle_28050 { Node* node; bool FUN_00231ee0(); };
struct Entry_28050 { char pad[0xb4]; Handle_28050 handle; };
struct Tree_28050 { Node* FUN_00233580(const char*); };
struct Manager_28050 {  };
hulk_freg __cdecl FUN_00224ea0(float x, float z);
hulk_freg __cdecl FUN_00224fc0(float a, float b);
struct Vec3_28330 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_28330 *other, float epsilon);
};
struct Pawn_28330 {
    char pad[0x2064];
    Vec3_28330 pos;                       // 0x2064
};
struct Group_28330 {
    Pawn_28330 *FUN_00024280(unsigned __int64 key);
    bool FUN_00028330(const char *name, float heading, float arc);
};
struct Vec3_28400 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Pawn_28400 {
    char pad[0x1b68];
    Vec3_28400 aimDir;
};
struct Group_28400 {
    Pawn_28400 *FUN_00024280(unsigned __int64 key);
    void FUN_00028400(const char *name, float x, float y, float z);
};
typedef unsigned __int64 Key_28530;
} // namespace fn_f6d645d0
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif
namespace fn_f6d645d0 {
void FUN_00363b40();
struct NameKey_28530 {
    int lo, hi;
    void FUN_0027af00();
};
struct Entry_28530 {
    int FUN_00036e70(NameKey_28530* key, int value);
};
struct Owner_28530 {
    Entry_28530* FUN_00024280(Key_28530 key);
    int FUN_00028530(const char* name, const char* attr, float value);
};
typedef unsigned __int64 Key_285b0;
void FUN_00363b50();
struct NameKey_285b0 {
    int lo, hi;
    void FUN_0027af00();
};
struct Entry_285b0 {
};
struct Owner_285b0 {
    Entry_285b0* FUN_00024280(Key_285b0 key);
    int FUN_000285b0(const char* name, const char* attr);
};
typedef unsigned __int64 Key_28840;
struct Focus_28840 {
};
struct Root_28840 {
    char pad[0x2c];
    Focus_28840* focus;
};
struct Entry_28840 {
    void FUN_0003b1c0(float value, int flag);
};
struct Owner_28840 {
    Root_28840* root;
    char pad04[0x120];
    Entry_28840* current;
    Entry_28840* FUN_00024280(Key_28840 key);
    void FUN_00028840(const char* name, float value);
};
union Two {
    __int64 both;
    struct {
        int a, b;
    } halves;
};
char __cdecl FUN_00345475(int c);
struct Pawn_28ba0 {
    char pad[0x1e58];
    int value;
    int mode;
};
struct Group_28ba0 {
    Pawn_28ba0 *FUN_00024280(unsigned __int64 key);
    void FUN_00028ba0(const char *name, int value, const char *modeName);
};
class End {
  public:
    char _m_pad_0[0xc8];
    unsigned char flag;
    void Act_00103b60(int, int, int);
    void act_00103b60(int, int, int);
};
class Mid {
  public:
    End* Get_000fdc40();
    End* get_000fdc40();
};
extern "C" __int64 __cdecl Decode_002672f0(int, int, int);
struct Obj;
struct Inner { Obj* FUN_000fdc40(); };
class Obj {
  public:
    char _m_pad_0[0x1ca0];
    union { Inner* inner; Mid* mid; };
    char _m_pad_1ca4[0x51];
    char flag;
    char _m_pad_1cf6[0x1e];
    int value;
    void use_00024280(int, int);
    void fn(int x, int y);
    Result* FUN_00024280(__int64);
    unsigned char FUN_00027270(int);
    Result* get_00024280(U64);
    void run(void*, int);
    Item* Find_00024280(__int64);
    void Func(int id, int value);
};
struct Handler {
  public:
    int field;
    Obj* Find_00024280(__int64);
    void Run(int a, int b);
};
class Main {
  public:
    int value;
    Obj* lookup_00024280(__int64);
    void fn(const char*, int);
};
struct Final { unsigned int FUN_001034d0(); };
struct Vec_29140 { float x,y,z; };
struct Transform_29140 {  };
struct Position_29140 { void FUN_00059a50(Vec_29140*); };
struct Manager_29140 {  };
struct Owner_29140 { char pad[0x44]; Manager_29140* manager; };
struct Target_29140 { Owner_29140* owner; char pad[8]; int count; int ids[1]; void FUN_00029140(Vec_29140 center,float radius); };
struct Destination { int FUN_001035f0(int value, int flag, int extra); };
struct Intermediate { Destination* FUN_000fdc40(); };
struct Entry { char padding[0x1ca0]; Intermediate* intermediate; };
typedef unsigned __int64 Key_29500;
extern Key_29500 __cdecl FUN_00096d80(const char*);
struct Slot_29500 {
    char pad[0x60];
    int value;
};
struct Item_29500 {
};
struct Registry_29500 {
    Item_29500* FUN_001dee40(Key_29500 key);
};
struct Core_29500 {
    char pad[0xc];
    Registry_29500* registry;
};
struct Entry_29500 {
    char pad0[0x12c];
    int handle;                     // 0x12c
    char pad130[0x1ca0 - 0x130];
    Slot_29500* slot;                     // 0x1ca0
    void FUN_0003ffa0(int value, bool flag);
};
struct Owner_29500 {
    Core_29500* core;
    char pad04[0x120];
    Entry_29500* current;                 // 0x124
    Entry_29500* FUN_00024280(Key_29500 key);
    void FUN_00029500(const char* name, const char* other);
};
void __cdecl FUN_00096d50(char *buf, int size, int a, int b);
struct Text_295a0 {
    char pad[8];
    int a;
    int b;
    const char *FUN_00036d00();
};
struct Param {
    char pad[8];
    Text_295a0 *text;
    int type;
};
struct Pawn_295a0 {
    char pad[0x328];
    Param *param;
};
struct Group_295a0 {
    Pawn_295a0 *FUN_00024280(unsigned __int64 key);
    const char *FUN_000295a0(const char *name);
};
class Controller_296a0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void SetMode(int mode);       // slot 8
    virtual int GetMode();                // slot 9
    char pad04[0x60];
    int value;                            // 0x64
    char pad68[0x36];
    char dirty;                           // 0x9e
    char pad9f[0x21];
    int flag;                             // 0xc0
};
struct Pawn_296a0 {
    char pad[0x12c];
    int value;                            // 0x12c
    char pad130[0x1b70];
    Controller_296a0 *controller;               // 0x1ca0
};
struct Prop_296a0 {
};
struct Manager_296a0 {
    Prop_296a0 *FUN_001def30(const char *name);
};
struct Env_296a0 {
    char pad[0xc];
    Manager_296a0 *manager;
};
struct Group_296a0 {
    Env_296a0 *env;
    Pawn_296a0 *FUN_00024280(unsigned __int64 key);
    void FUN_000296a0(const char *nameA, const char *nameB, int flag);
};
struct Vec3_29740 {
    float x, y, z;
};
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
    virtual Vec3_29740 *GetPos(Vec3_29740 *out);
    virtual void _m_vf9();
    virtual void GetTarget(Vec3_29740 *out);
    char _m_pad_4[0x224];
    Pair entries[32];
    int count;
    int FUN_000246e0(int first, int second);
    bool FUN_00035ab0();
    Entry_28050* FUN_00024280(Key_28050);
    bool FUN_00028050(const char*, const char*);
};
struct Path_29740 {
    void FUN_00025a20(unsigned __int64 key, Vec3_29740 *from, Vec3_29740 *to, float a, float b);
};
class Controller_29740 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void SetMode(int mode);             // slot 8
    virtual int GetMode();                      // slot 9
    char pad04[0x54];
    Path_29740 path;                                  // 0x58
    char pad5c[0x9e - 0x58 - sizeof(Path_29740)];
    char dirty;                                 // 0x9e
};
struct Pawn_29740 {
    char pad[0x1ca0];
    Controller_29740 *controller;                     // 0x1ca0
};
struct Finder_29740 {
    Object *FUN_001fd780(const char *name);
};
struct Env_29740 {
    char pad[0x28];
    Finder_29740 *finder;
};
struct Group_29740 {
    Env_29740 *env;
    Pawn_29740 *FUN_00024280(unsigned __int64 key);
    void FUN_00029740(const char *pawnName, const char *objectName, float a, float b);
};
struct Owner_29820 {
    char pad[0x9e];
    char hasId;
    char pad9f;
    unsigned int idLo;
    unsigned int idHi;
};
struct Holder_29820 {
    char pad[0x1ca0];
    Owner_29820 *owner;
};
union Id64_29820 {
    unsigned __int64 q;
    unsigned int w[2];
};
struct ThisWrap_00029820 {
    bool FUN_00029820(const char *a, const char *b);
};
struct Output_29990 { char data[12]; };
struct Info_29990 { void FUN_00059a50(Output_29990*); };
struct Value_29990 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual int v9(); };
struct Entity {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual bool vfunc_4(int a);
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void setState(int);
    virtual int getState();
    char _m_pad_4[0xc];
    Info_29990* info;
    char _m_pad_14[0x44];
    Transform_29140 transform;
    char _m_pad_59[0x2db];
    int flag334;
    int flag338;
    char _m_pad_33c[0x17d0];
    float amount;
    char _m_pad_1b10[0x190];
    Value_29990* value;
    bool FUN_00035ab0();
};
struct Item_29140 { char pad0[0x10]; Position_29140* position; char pad1[0x1ca0-0x14]; Entity* entity; char pad2[0x1cbc-0x1ca4]; float radius; bool FUN_00035ab0(); };
struct Manager_29990 {  };
struct Owner_29990 { char pad[0x44]; Manager_29990* manager; };
struct Target_29990 { Owner_29990* owner; char pad[8]; int count; int ids[1]; int FUN_00029990(); };
class Ref_29b50 {
  public:
    virtual void Add();
    virtual void Release();
};
class Owner_29b50 {
    char pad[0x344];
    Ref_29b50* a;
    Ref_29b50* b;
    int c;

  public:
    void Set(Ref_29b50* x, Ref_29b50* y, int z);
};
class Thing_29bb0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_29bb0 {
  public:
    char pad[0x344];
    int key;
    Thing_29bb0* current;
    int value;
    void Set(int k, Thing_29bb0* t, int v);
};
struct Resource { virtual void slot0(); virtual void slot1(); };
struct Owner {
  public:
    char _m_pad_0[0x344];
    Resource *primary;
    Resource *secondary;
    int state;
    Result* Find_00024280(__int64);
    char Test(int a, Vec3_26910 b);
    Item* find_00024280(unsigned __int64);
    void work(void*, int);
    Item* Get_00024280(__int64);
    void Fn(int);
    Obj* FUN_00024280(unsigned int low, unsigned int high);
    unsigned int FUN_00028ee0(const char* name);
    Entry* FUN_00024280(__int64 key);
    hulk_intptr FUN_00029390(int key, int value, int flag, int extra);
    void Set(int, unsigned char);
    void FUN_00029c00(Resource *item);
    Result* Get_00024280(unsigned a, unsigned b);
    char Fn(unsigned x);
};
extern "C" unsigned __int64 __cdecl External_002672f0(unsigned x, unsigned a, unsigned b);
struct Vec3_29f20 {
    float x, y, z;
};
struct Body_29f20 {
    bool FUN_00059a50(Vec3_29f20 *out);
};
struct Pawn_29f20 {
    char pad[0x10];
    Body_29f20 *body;
};
hulk_freg __cdecl FUN_00025990(Vec3_29f20 *a, Vec3_29f20 *b);
struct Group_29f20 {
    Pawn_29f20 *FUN_00024280(unsigned __int64 key);
    hulk_freg FUN_00029f20(const char *nameA, const char *nameB);
};
struct Vec3_2a0a0 {
    int x, y, z;
};
class X {
  public:
    Obj* Get_00024280(__int64);
    char Run(int a, int b);
    void FUN_00024280(__int64);
    void FUN_00027190(int, int);
    Obj* get(unsigned a, unsigned b);
    Obj* FUN_00024280(unsigned __int64 key);
    void* FUN_00024280(int, int);
    int FUN_00028aa0(int);
    Result* find_00024280(unsigned __int64);
    void fn(int a, Vec3_2a0a0 b);
};
extern "C" unsigned __int64 __cdecl makekey_002672f0(int, int, int);
struct Vec3_2a0e0 {
    float x, y, z;
};
struct HitExtra_2a0e0 {
    int b, c, d, e;
};
struct Pawn_2a0e0 {
};
union NameSlot_2a0e0 {
    const char *name;
    int out;
};
struct Group_2a0e0 {
    char pad000[0x124];
    Pawn_2a0e0 *current;              // 0x124
    char pad128[0x353 - 0x128];
    char active;                // 0x353
    Vec3_2a0e0 from;                  // 0x354
    Vec3_2a0e0 to;                    // 0x360
    char hit;                   // 0x36c
    char pad36d[3];
    HitExtra_2a0e0 extra;             // 0x370

    Pawn_2a0e0 *FUN_00024280(unsigned __int64 key);
    char FUN_0002a0e0(NameSlot_2a0e0 name, float fx, float fy, float fz, float tx, float ty, float tz);
};
struct Vec {
    float x, y, z;
};
class Resource_2a800 {
public:
    virtual void vfunc_0();
    virtual void Release();
};
struct Child_2a800 {
    void FUN_00036d40(int arg);
};
struct Slot_2a800 {
    Child_2a800 *FUN_00059c10(void *item);
};
struct Manager_2a800 {
    void FUN_001b4c40(Resource_2a800 *resource);
};
Manager_2a800 *__cdecl FUN_001b6580();
struct Item_2a890 { void FUN_0003b620(int); };
struct Registry_2a890 {  };
struct Owner_2a890 { char pad[0x44]; Registry_2a890* registry; };
struct Component_2a890 { void FUN_00044c30(); void FUN_00046230(); };
struct Interface_2a890 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); };
struct Entry_2a890 { char pad[0x5c]; Interface_2a890* object; };
struct Manager_2a890 { int FUN_002327c0(); Entry_2a890* FUN_00232810(int); };
struct Resource_2a890 { virtual void slot0(); virtual void release(); };
struct Target_2a890 {
 Owner_2a890* owner;
 Component_2a890* component;
 int unknown;
 int count;
 int ids[205];
 Resource_2a890* resource1;
 Resource_2a890* resource2;
 void FUN_0002a800();
 void FUN_0002a890();
};
struct Vec3_2a960 {
    float x, y, z;
    hulk_freg FUN_000111f0();
};
struct Body_2a960 {
    char pad00[0x18];
    char pad18[4];
    bool FUN_00059a50(Vec3_2a960 *out);
};
struct Named_2a960 {
    unsigned __int64 FUN_000443c0();
};
struct Zone_2a960 {
    Zone_2a960 *FUN_00204200(float x, float y, float z);
};
struct ZoneTest {
    bool FUN_00204440(Zone_2a960 *z);
};
struct Fighter_2a960 {
    char pad000[0x10];
    Body_2a960 *body;                  // 0x10
    char pad14[0x119 - 0x14];
    unsigned char flag119;       // 0x119
    char pad11a[2];
    Named_2a960 *name;                 // 0x11c
    char pad120[0x1cf4 - 0x120];
    unsigned char flag1cf4;
    unsigned char flag1cf5;
    char pad1cf6[0x1d05 - 0x1cf6];
    unsigned char flag1d05;      // 0x1d05
    char pad1d06[0x1d78 - 0x1d06];
    unsigned char flag1d78;      // 0x1d78
};
struct Roster_2a960 {
};
struct Holder_2a960 {
    char pad00[0x28];
    ZoneTest *zoneTest;          // 0x28 (read by the FUN_000862a0 getter)
};
struct Context {
  public:
    char _m_pad_0[0x44];
    union { Manager_25470* mgr; Roster_2a960 *roster; Slot_2a800 *slot; };
    char _m_pad_48[0xc];
    Holder_2a960 *holder;
    char _m_pad_58[0x4];
    Tree_28050* tree;
};
class Manager_24970 {
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
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    char pad[0x40];
    Context* ctx;
};
class Thing_24970 {
  public:
    Manager_24970* mgr;
    char pad4[8];
    int count;
    int items[1];
    bool Set(int);
};
class Owner_25470 {
  public:
    Context* ctx;
    char pad[8];
    int count;
    int entries[1];
    void Run(int);
};
class ItemList_2a800 {
public:
    Context *context;       // 0x0
    char pad04[8];
    int count;              // 0xc
    void *items[69];        // 0x10
    Resource_2a800 *resource;     // 0x124
    void FUN_0002a4b0(int index, int arg);
    bool FUN_0002a800();
};
ZoneTest *__fastcall FUN_000862a0(Holder_2a960 *h);
struct Frame_2a960 {
    Vec3_2a960 pos;
    Vec3_2a960 delta;
    Vec3_2a960 other;
};
class SpawnWatcher {
public:
    char pad00[0xc];
    int count;                   // 0x0c
    int ids[52];                 // 0x10
    int state[1];                // 0xe0
    char padE4[0x124 - 0xe4];
    Fighter_2a960 *self;               // 0x124

    void FUN_0002a4b0(int index, int flag);
    void FUN_0002a960(Context *ctx);
};
struct Vec3_2ab40 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
class Selector_2ab40 {
public:
    int FUN_000fdc40();
    char pad0[0xe8];
    char armed;
};
class Agent_2ab40 {
public:
    void FUN_000363f0(int a0, float v);
    void FUN_00036430(int a0, float v);
    void FUN_0003b7d0(int a0, float v);
    void FUN_00040970(int a0, float v);
    void FUN_0003e2a0(int a0, Vec3_2ab40 dir, int a1, float v, unsigned int flags);
    int FUN_00035660(Vec3_2ab40 *out);

    char pad0[0x1ca0];
    Selector_2ab40 *selector;
    char pad1[0x1cf0 - 0x1ca4];
    float gain;
    char pad2[0x2064 - 0x1cf4];
    float dirX;
    float dirY;
    float dirZ;
    float dirScale;
    char pad3[0x2140 - 0x2074];
    char forced;
};
class Lookup_2ab40 {
public:
};
struct Registry_2ab40 {
    char pad0[0x44];
    Lookup_2ab40 *lookup;
};
class AgentSet {
public:
    void FUN_0002ab40(hulk_intptr a0, hulk_intptr a1);
    void FUN_0002a960(int a0);
    void FUN_00025ff0(int a0, int a1);

    Registry_2ab40 *registry;
    char pad0[8];
    int count;
    int ids[16];
    char pad2[4];
    unsigned int flags[16];
    float args[16];
    char pad1[0xe0 - 0xd4];
    int modes[16];
};
struct Item_2b250 {
 char pad[8];
 int value8;
 int valueC;
};
struct Manager_2b250 {  };
struct Owner_2b250 { char pad[0x44]; Manager_2b250* manager; };
struct Container_2b250 {
 Owner_2b250* owner;
 char pad4[8];
 int count;
 int handles[69];
 Item_2b250* excluded;
 char pad128[0x200];
 int used;
 unsigned char FUN_00024720(int a, int b);
 void FUN_0002a4b0(int index, int flag);
 int FUN_0002b250(int desired, int filter);
};
struct Vec3_2b310 { unsigned int x, y, z; };
extern void __cdecl FUN_00224d70(float angle, Vec3_2b310* v);
class Obj_2b310 {
  public:
    void FUN_00028400(int a, Vec3_2b310 v);
    void FUN_0002b310(int a, float degrees);
};
class Ret_2b3d0 {
  public:
    void FnD_0003b620(int);
    void FnE_000401a0();
    char pad[0x20a8];
    int m;
};
class Prov_2b3d0 {
  public:
};
class Sub_2b3d0 {
  public:
    char pad[0x44];
    Prov_2b3d0* prov;
    Ret_2b3d0* Get(int id) { return ((Ret_2b3d0 *)((owners::ThisWrap_00059c10 *)prov)->FUN_00059c10((void *)(hulk_uintptr)(int)id)); }
};
class Obj_2b3d0 {
  public:
    Sub_2b3d0* sub;
    int pad4[2];
    int count;
    int items[0x124 / 4 - 4];
    Ret_2b3d0* current;
    void removeAt_0002a4b0(int, int);
    void run();
};
typedef unsigned __int64 Key_2b450;
struct Vec3_2b450 {
    float x, y, z;
};
extern hulk_freg __cdecl FUN_0002a380(Vec3_2b450* a, Vec3_2b450* b);
struct Child_2b450 {
    bool FUN_00059a50(Vec3_2b450* out);
};
struct Entry_2b450 {
    char pad[0x10];
    Child_2b450* child;
};
struct Owner_2b450 {
    Entry_2b450* FUN_00024280(Key_2b450 key);
    hulk_freg FUN_0002b450(const char* nameA, const char* nameB);
};
struct Item_2b590 {
 char pad[0x1d78];
 unsigned char protectedFlag;
 char pad2[7];
 int priority;
 void FUN_00036a20();
 void FUN_0003e640();
};
struct Registry_2b590 {  };
struct Owner_2b590 { char pad[0x44]; Registry_2b590* registry; };
extern unsigned char DAT_0048e0e1;
struct Manager_2b590 {
 Owner_2b590* owner;
 char pad[8];
 int count;
 int ids[69];
 Item_2b590* preserved;
 char pad2[0x204];
 int limit;
 void FUN_0002a4b0(int index,int flag);
 void FUN_0002b590();
};
struct Ref_2b690 {
    virtual void x();
    virtual void Release(int);
};
struct Ref0 {
    virtual void x();
    virtual void Release();
};
struct Elem_2b690 {
    void Fn_0027af50();
};
struct T_2b690 {
    char p[4];
    Ref_2b690* r;
    Ref_2b690* q;
    char p2[0x338];
    Ref0* c;
    Ref0* d;
    char p3[0x904];
    void A();
    void init_0002a890();
    void fini_0002c110();
};
extern void __cdecl dispose_0008d330(Ref_2b690*);
extern void globalf_00232bb0();
struct Name_2b730 {
    unsigned int lo, hi;
    Name_2b730 *FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};
struct Link_2b730 {
    char pad0[0x118];
    unsigned int nameLo;        // 0x118
    unsigned int nameHi;        // 0x11c
    char flagA;                 // 0x120
    char flagB;                 // 0x121
};
struct Item_2b730 {
    char pad0[0x1ca0];
    Link_2b730 *link;                 // 0x1ca0
    bool FUN_00035ab0();
};
struct Registry_2b730 {
};
struct Owner_2b730 {
    char pad0[0x44];
    Registry_2b730 *registry;         // 0x44
};
class Group_2b730 {
public:
    Owner_2b730 *owner;
    char pad4[8];
    int count;                  // 0xc
    int ids[16];                // 0x10
    bool FUN_0002b730(const char *name);
    void FUN_0002a4b0(int index, int flag);
};
struct Vec_2b860 { float x,y,z; };
struct Item_2b860 { Entity* FUN_00059a30(); void FUN_00059a50(Vec_2b860*); };
struct Manager_2b860 { Item_2b860* FUN_00059ba0(int);  };
struct Owner_2b860 { char pad[0x44]; Manager_2b860* manager; };
struct Target_2b860 { Owner_2b860* owner; char pad[8]; int count; int items[1]; void FUN_0002a4b0(int,int); bool FUN_0002b860(float x,float y,float z); };
class Thing_2bf50 {
  public:
    bool Check_0002b7d0();
    void Run(int count);
};
struct Actor {
    int FUN_0002b970(unsigned, Triple, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
    int FUN_0002bf80(unsigned a, Triple b, unsigned e, unsigned f, unsigned g, unsigned h, unsigned i);
};
struct Vec3_2bfd0 {
    int x, y, z;
};
struct Pawn_2bfd0 {
};
struct Group_2bfd0 {
    Pawn_2bfd0 *FUN_00024280(unsigned __int64 key);
    bool FUN_0002b970(int a1, Vec3_2bfd0 pos, int a5, int a6, int a7, int a8, const char *name, int zero);
    bool FUN_0002bfd0(int a1, int x, int y, int z, int a5, int a6, int a7, int a8, const char *name);
};
class C_2c0e0 {
  public:
    char pad[0x352];
    char m;
    void Set(char x);
};
class Obj_2c0f0 {
  public:
    char pad[0x50];
    char flag;
    char GetFlag();
};
class Obj_2c100 {
  public:
    char pad[0x50];
    char m50;
    void Set(unsigned char v);
};
} // namespace fn_f6d645d0
extern "C" int FUN_001d04d0(void*);


// 0x000240b0 FUN_000240b0 (33 B): matches/0x000240b0.cpp
// sym: ?FUN_000240b0@Obj_240b0@owners@@QAEHH@Z
hulk_intptr owners::Obj_240b0::FUN_000240b0(hulk_intptr x) {
    return set(fetch_002672f0(((int)x), 0, 0));
}

namespace fn_f6d645d0 {

// 0x00024120 FUN_00024120 (1 B): matches/0x00024120.cpp
// sym: ?FUN_00024120@fn_f6d645d0@@YAXXZ
void FUN_00024120() {}


// 0x00024130 FUN_00024130 (23 B): matches/0x00024130.cpp
// sym: ?Target@Obj_24130@fn_f6d645d0@@QAEPAU12@XZ
Obj_24130* Obj_24130::Target() {
    a.FnF_0027af00();
    b.FnF_0027af00();
    return this;
}


// 0x00024150 FUN_00024150 (20 B): matches/0x00024150.cpp
// sym: ?Func@Owner_24150@fn_f6d645d0@@QAEXXZ
void Owner_24150::Func() {
    Sub_24150* p = (Sub_24150*)((char*)this + 0x48);
    p->Helper_0027af50();
    p = (Sub_24150*)((char*)this + 0x40);
    p->Helper_0027af50();
}

} // namespace fn_f6d645d0

// 0x00024170 FUN_00024170 (30 B): matches/0x00024170.cpp [wrapped: conflict: CAction; CCollisionAction]
// sym: ?vfunc_2@CCollisionAction@fn_00024170@@UAEPAV12@E@Z
namespace fn_00024170 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_00067a20 {
    void FUN_00067a20();
};
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_00067a20*)(this))->FUN_00067a20();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00024170

namespace fn_f6d645d0 {

// 0x00024190 FUN_00024190 (38 B): matches/0x00024190.cpp
// sym: ?get@Obj_24190@fn_f6d645d0@@QAEHH@Z
hulk_intptr Obj_24190::get(int index) {
    if (index >= 0 && index < count) {
        Helper_24190* h = (Helper_24190*)*(hulk_intptr*)((hulk_intptr)*(int*)this + 0x44);
        return ((int)((owners::ThisWrap_00059c10 *)h)->FUN_00059c10((void *)(hulk_uintptr)(int)(items[index])));
    }
    return 0;
}


// 0x000241c0 FUN_000241c0 (109 B): matches/0x000241c0.cpp
// sym: ?Find@List_241c0@fn_f6d645d0@@QAEHH@Z
int List_241c0::Find(int key) {
    unsigned __int64 h = Hash_0027b020(key);
    int i = 0;
    if (0 < mCount) {
        int* p = mIds;
        do {
            Sub_241c0* s = mMgr->sub;
            Item_241c0* it = ((Item_241c0 *)((owners::ThisWrap_00059c10 *)s)->FUN_00059c10((void *)(hulk_uintptr)(int)(*p)));
            if (it && it->id == h)
                return i;
            i++;
            p++;
        } while (i < mCount);
    }
    return -1;
}

} // namespace fn_f6d645d0

// 0x00024230 FUN_00024230 (73 B): equivalent/0x00024230.cpp [wrapped: conflict: Lookup]
// sym: ?FUN_00024230@Finder@fn_00024230@@QAEHH@Z @daf27835e093 @w4aa879152803
namespace fn_00024230 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00024230 @ 0x00024230
struct Lookup {  };
struct Finder { struct Data { char pad[0x44]; Lookup* lookup; }; Data* data; char pad[8]; int count; int entries[1]; int FUN_00024230(hulk_intptr wanted); };
int Finder::FUN_00024230(hulk_intptr wanted) {
    for (int i = 0; i < count; ++i) {
        int result = ((int)((owners::ThisWrap_00059c10 *)(data->lookup))->FUN_00059c10((void *)(hulk_uintptr)(int)(entries[i])));
        if (result != 0 && result == wanted) return i;
    }
    return -1;
}
} // namespace fn_00024230


// 0x00024280 FUN_00024280 (75 B): equivalent/0x00024280.cpp [wrapped: conflict: Lookup]
// sym: ?FUN_00024280@Table@fn_00024280@@QAEPAUEntry@2@HH@Z @466c9c72354a @w577675291d25
namespace fn_00024280 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00024280 @ 0x00024280
struct Entry { char pad[8]; int key1; int key2; };
struct Receiver {  };
struct Lookup { char pad[0x44]; Receiver* receiver; };
struct Table { Lookup* lookup; char pad[8]; int count; int items[1]; Entry* FUN_00024280(int key1, int key2); };
Entry* Table::FUN_00024280(int key1, int key2) {
    for (int i = 0; i < count; ++i) {
        Entry* result = ((Entry *)((owners::ThisWrap_00059c10 *)(lookup->receiver))->FUN_00059c10((void *)(hulk_uintptr)(int)(items[i])));
        if (result && result->key1 == key1 && result->key2 == key2)
            return result;
    }
    return 0;
}
} // namespace fn_00024280

namespace fn_f6d645d0 {

// 0x000242d0 FUN_000242d0 (21 B): matches/0x000242d0.cpp
// sym: ?FUN_000242d0@fn_f6d645d0@@YGEPAUObj_242d0@1@@Z
u8_242d0 __stdcall FUN_000242d0(Obj_242d0* p) {
    if (!p)
        return 0;
    return p->run_00035ab0();
}


// 0x000242f0 FUN_000242f0 (5 B): matches/0x000242f0.cpp
// sym: ?vfunc_4@Entity@fn_f6d645d0@@UAE_NH@Z
// Same code shape as 0x00244f40 (propagated; names are from that function)
bool Entity::vfunc_4(int a) {
    return false;
}


// 0x00024300 FUN_00024300 (21 B): matches/0x00024300.cpp
// sym: ?FUN_00024300@fn_f6d645d0@@YGEPAUObj_24300@1@@Z
// Same code shape as 0x000242d0 (propagated; names are from that function)
u8_24300 __stdcall FUN_00024300(Obj_24300* p) {
    if (!p)
        return 0;
    return p->run_00035a90();
}

} // namespace fn_f6d645d0

// 0x00024320 FUN_00024320 (91 B): matches/0x00024320.cpp
// sym: ?FUN_00024320@ItemList_24320@owners@@QAE_NH@Z
bool owners::ItemList_24320::FUN_00024320(int index) {
    if (index < 0 || index >= count)
        return false;
    --count;
    values[index] = 0;
    if (count > 0) {
        values[index] = values[count];
        values[count] = 0;
        field54[index] = field54[count];
        field94[index] = field94[count];
    }
    return true;
}

namespace fn_f6d645d0 {

// 0x00024380 FUN_00024380 (80 B): matches/0x00024380.cpp
// sym: ?find@Obj_24380@fn_f6d645d0@@QAE_NH@Z
bool Obj_24380::find(int value) {
    int i = 0;
    if (count > 0) {
        do {
            Helper_24380* h = *(Helper_24380**)((char*)*(int**)this + 0x44);
            int result = ((int)((owners::ThisWrap_00059c10 *)h)->FUN_00059c10((void *)(hulk_uintptr)(int)(items[i])));
            if (result != 0 && result == value) {
                ((owners::ItemList_24320 *)this)->FUN_00024320(i);
                return true;
            }
            ++i;
        } while (i < count);
    }
    return false;
}


// 0x000243d0 FUN_000243d0 (21 B): matches/0x000243d0.cpp
// sym: ?FUN_000243d0@fn_f6d645d0@@YIPAXPAUObj_243d0@1@@Z
// data: zeroValue_243d0 = DAT_003f335c
void* __fastcall FUN_000243d0(Obj_243d0* self) {
    Obj_243d0* p = (Obj_243d0*)self->member;
    if (!p)
        return ((char*)&DAT_003f335c);
    return p->go_00036d00();
}

} // namespace fn_f6d645d0

// 0x000243f0 FUN_000243f0 (14 B): matches/0x000243f0.cpp
// sym: ?FUN_000243f0@X_243f0@owners@@QAEXH@Z
void owners::X_243f0::FUN_000243f0(hulk_intptr x) {
    value = ((int)x);
    InitGlobal_000436f0();
}


// 0x00024400 FUN_00024400 (121 B): matches/0x00024400.cpp [wrapped: conflict: gMaker]
// sym: ?FUN_00024400@fn_00024400@@YGHHD@Z
namespace fn_00024400 {

extern "C" void* __cdecl thunk_FUN_0008d690(unsigned int);
class Thing_24400 {
  public:
    virtual void A();
    virtual void B();
    char pad[8];
    unsigned char ready;
};
class LoadStream_24400 {
  public:
    Thing_24400* Make_00264430(int, int, int);
};
class Manager_24400 {
  public:
};
extern "C++" { extern LoadStream_24400* gMaker; }
LoadStream_24400* gMaker;
int __stdcall FUN_00024400(int param, char skip) {
    Thing_24400* p;
    int result;
    if (skip && !(*(char*)&DAT_004dd841))
        return 0;
    LoadStream_24400* f = (LoadStream_24400*)thunk_FUN_0008d690(0x48);
    if (f)
        p = f->Make_00264430(param, 0, 1);
    else
        p = 0;
    p->A();
    if (!p->ready) {
        p->B();
        return 0;
    }
    result = ((owners::A_232b80 *)((*(Manager_24400**)&DAT_004e5af8)))->FUN_00232b80((hulk_intptr)"fig0", (hulk_intptr)(Thing_24400 *)p, 0);
    p->B();
    return result;
}
} // namespace fn_00024400

namespace fn_f6d645d0 {

// 0x00024480 FUN_00024480 (24 B): equivalent/0x00024480.cpp
// sym: ?FUN_00024480@fn_f6d645d0@@YGHHH@Z @2cc19a33bbba @w9009cb9a92e9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00024480 @ 0x00024480
int __stdcall FUN_00024480(int a, int b) {
    return FUN_00024400(a, b) != 0;
}


// 0x000244a0 FUN_000244a0 (8 B): matches/0x000244a0.cpp
// sym: ?f@X_244a0@fn_f6d645d0@@QAEXH@Z
void X_244a0::f(hulk_intptr a0) {
    p->Fng_00044be0(a0);
}


// 0x000244b0 FUN_000244b0 (12 B): matches/0x000244b0.cpp
// sym: ?FUN_000244b0@fn_f6d645d0@@YGEE@Z
// data: gValue_244b0 = DAT_004dc038
unsigned char __stdcall FUN_000244b0(unsigned char value) {
    (*(unsigned char*)&DAT_004dc038) = value;
    return value;
}


// 0x000244c0 D3D8::D3D_SetPushBufferSize (22 B): matches/0x000244c0.cpp
// sym: ?Set@EnergyDoorParams_244c0@fn_f6d645d0@@QAEXHH@Z
// CActorManager's script binding EnergyDoorSetParams (equivalent/0x00031310.cpp registers it with a Closure2 over
// <const char*, float>): stores its two arguments in the energy-door globals. Called through the closure's
// member-function pointer (thiscall: `this` unused).
void EnergyDoorParams_244c0::Set(int a, int b) {
    DAT_0048e06c = a;
    DAT_0048e070 = b;
}


// 0x000244e0 FUN_000244e0 (45 B): matches/0x000244e0.cpp
// sym: ?run@Outer_244e0@fn_f6d645d0@@QAEXXZ
void Outer_244e0::run() {
    int i = 0;
    if (count > 0) {
        int* p = items;
        do {
            ((owners::ThisWrap_00059c10 *)(mOwner->mHelper))->FUN_00059c10((void *)(hulk_uintptr)(int)(*p));
            ++i;
            ++p;
        } while (i < count);
    }
}


// 0x00024510 FUN_00024510 (45 B): matches/0x00024510.cpp
// sym: ?run@Outer_24510@fn_f6d645d0@@QAEXXZ
// Same code shape as 0x000244e0 (propagated; names are from that function)
void Outer_24510::run() {
    int i = 0;
    if (count > 0) {
        int* p = items;
        do {
            ((owners::ThisWrap_00059c10 *)(mOwner->mHelper))->FUN_00059c10((void *)(hulk_uintptr)(int)(*p));
            ++i;
            ++p;
        } while (i < count);
    }
}

} // namespace fn_f6d645d0

// 0x00024540 FUN_00024540 (45 B): matches/0x00024540.cpp
// sym: ?FUN_00024540@Obj_24540@owners@@QAE_NH@Z
bool owners::Obj_24540::FUN_00024540(hulk_intptr x) {
    int i = Lookup(((int)x));
    if (i == -1)
        return false;
    return values[i] == 1;
}

namespace fn_f6d645d0 {

// 0x00024570 FUN_00024570 (13 B): matches/0x00024570.cpp
// sym: ?Set@Obj_24570@fn_f6d645d0@@QAEXE@Z
void Obj_24570::Set(unsigned char value) {
    mValue = value;
}


// 0x00024580 FUN_00024580 (47 B): matches/0x00024580.cpp
// sym: ?Target@Obj_24580@fn_f6d645d0@@QAEXH@Z
void Obj_24580::Target(int unused) {
    for (int i = 0; i < count; ++i)
        ((owners::ThisWrap_00059c10 *)(owner->inner))->FUN_00059c10((void *)(hulk_uintptr)(int)(values[i]));
}


// 0x000245b0 FUN_000245b0 (252 B): equivalent/0x000245b0.cpp
// sym: ?FUN_000245b0@Target_245b0@fn_f6d645d0@@QAEXXZ @c84fc3de3948 @w427bd9765e8b
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 8/8)
// FUN_000245b0 @ 0x000245b0
// FUN_000245b0 @ 0x000245b0
void Target_245b0::FUN_000245b0() {
 Vec_245b0 head = {0,0,0}; Vec_245b0 pelvis = {0,0,0};
 if (!owner) return;
 Bones_245b0 *bones = owner->bones;
 if (!bones) return;
 unsigned index = bones->FUN_002843a0(FUN_002672f0("Head",0,0));
 if (index != 0xffff) {
 head = bones->entries[index].position;
 FUN_001c3d90()->FUN_001c3c10(0,&head);
 }
 index = bones->FUN_002843a0(FUN_002672f0("Pelvis",0,0));
 if (index != 0xffff) {
 pelvis = bones->entries[index].position;
 FUN_001c3d90()->FUN_001c3c10(1,&pelvis);
 }
}


// 0x000246e0 FUN_000246e0 (62 B): equivalent/0x000246e0.cpp
// sym: ?FUN_000246e0@Object@fn_f6d645d0@@QAEHHH@Z @36348a8d2338 @wf9617dc197ae
// STATUS: equivalent (tools/equiv.py level 3: 2188 inputs, branch coverage 8/8)
// FUN_000246e0 @ 0x000246e0
int Object::FUN_000246e0(int first, int second) { for (int i=0; i<count; ++i) { if (entries[i].first==first && entries[i].second==second) return i; } return -1; }

} // namespace fn_f6d645d0

// 0x00024720 FUN_00024720 (80 B): matches/0x00024720.cpp
// sym: ?FUN_00024720@ItemList_24720@owners@@QAE_NHH@Z
bool owners::ItemList_24720::FUN_00024720(int a, int b) {
    int index = Find(a, b);
    if (index == -1)
        return false;
    int n = --count;
    memmove((char*)this + 0x228 + index * 8, (char*)this + 0x230 + index * 8, (n - index) * 8);
    return true;
}

namespace fn_f6d645d0 {

// 0x00024770 FUN_00024770 (13 B): matches/0x00024770.cpp
// sym: ?Set@Target_24770@fn_f6d645d0@@QAEXH@Z
void Target_24770::Set(int x) {
    value = x;
}


// 0x00024780 FUN_00024780 (118 B): matches/0x00024780.cpp
// sym: ?Target@C_24780@fn_f6d645d0@@QAEHI@Z
int C_24780::Target(unsigned a) {
    int n = 0;
    unsigned __int64 h = Hash_0027b020(a);
    for (int i = 0; i < count; i++) {
        Mgr_24780* m = owner->mgr;
        Item_24780* it = ((Item_24780 *)((owners::ThisWrap_00059c10 *)m)->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
        if (it->v == h)
            n++;
    }
    return n;
}


// 0x00024800 FUN_00024800 (64 B): matches/0x00024800.cpp
// sym: ?func@Owner_24800@fn_f6d645d0@@QAEHXZ
int Owner_24800::func() {
    int sum = 0;
    int i = 0;
    if (count > 0) {
        int* p = arr;
        do {
            Worker_24800* w = mCont->worker;
            int r = ((int)((owners::ThisWrap_00059c10 *)w)->FUN_00059c10((void *)(hulk_uintptr)(int)(*p)));
            if (r != 0 && r != cmpVal)
                ++sum;
            ++i;
            ++p;
        } while (i < count);
    }
    return sum;
}

} // namespace fn_f6d645d0

// 0x00024840 FUN_00024840 (146 B): equivalent/0x00024840.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_00024840@Group_24840@fn_00024840@@QAEHPBD@Z @1976761a05fc @w2676f6f4c53c
namespace fn_00024840 {
// STATUS: equivalent (tools/equiv.py level 3: 599 inputs, branch coverage 14/14)
// FUN_00024840 @ 0x00024840
union Hash_24840 {
    unsigned __int64 q;
    unsigned int w[2];
};
Hash_24840 FUN_0027b020(const char *s);

struct Target_24840 {
    char pad0[0x118];
    unsigned int hashLo;    // 0x118
    unsigned int hashHi;    // 0x11c
};

struct Actor_24840 {
    char pad0[0x1ca0];
    Target_24840 *target;         // 0x1ca0
};

struct Registry_24840 {
};

struct Manager_24840 {
    char pad0[0x44];
    Registry_24840 *registry;     // 0x44
};

class Group_24840 {
public:
    Manager_24840 *manager;       // 0x0
    char pad4[8];
    int count;              // 0xc
    int ids[1];             // 0x10
    char pad14[0x124 - 0x14];
    Actor_24840 *self;            // 0x124

    int FUN_00024840(const char *name);
};

// Number of members whose target has the hash of `name`.
int Group_24840::FUN_00024840(const char *name)
{
    int matches = 0;
    Hash_24840 h;
    h.q = FUN_0027b020(name).q;
    for (int i = 0; i < count; i++) {
        Actor_24840 *a = ((Actor_24840 *)((owners::ThisWrap_00059c10 *)(manager->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
        if (a != 0 && a != self) {
            Target_24840 *t = a->target;
            if (t != 0 && t->hashLo == h.w[0] && t->hashHi == h.w[1])
                matches++;
        }
    }
    return matches;
}
} // namespace fn_00024840

namespace fn_f6d645d0 {

// 0x000248e0 FUN_000248e0 (110 B): matches/0x000248e0.cpp
// sym: ?run@Thing_248e0@fn_f6d645d0@@QAEPAXH@Z
void* Thing_248e0::run(int index) {
    if (index < 0 || index >= count)
        return &hulk_at_003f335c;
    int found = 0, i = 0;
    if (count > 0) {
        int* p = items;
        do {
            Sub_248e0* s = owner->sub;
            Item_248e0* v = (Item_248e0*)((void *)((owners::ThisWrap_00059c10 *)s)->FUN_00059c10((void *)(hulk_uintptr)(int)(*p)));
            if (v && (hulk_intptr)v != excluded) {
                if (found == index)
                    return v->Get_00036d00();
                ++found;
            }
            ++i;
            ++p;
        } while (i < count);
    }
    return &hulk_at_003f335c;
}

} // namespace fn_f6d645d0

// 0x00024950 FUN_00024950 (18 B): matches/0x00024950.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?FUN_00024950@fn_00024950@@YGXH@Z
namespace fn_00024950 {
class Obj {
  public:
    char pad[0x2c4];
    int field;
};
Obj* __stdcall getObj_000678d0();
void __stdcall FUN_00024950(int x) {
    Obj* p = getObj_000678d0();
    p->field = x;
}
} // namespace fn_00024950

namespace fn_f6d645d0 {

// 0x00024970 FUN_00024970 (94 B): matches/0x00024970.cpp
// sym: ?Set@Thing_24970@fn_f6d645d0@@QAE_NH@Z
bool Thing_24970::Set(int value) {
    if (value < -1 || value >= 5)
        return false;
    int n = count;
    for (int i = 0; i < n; ++i) {
        Context* c = mgr->ctx;
        Obj_24970* o = ((Obj_24970 *)((owners::ThisWrap_00059c10 *)c)->FUN_00059c10((void *)(hulk_uintptr)(int)(items[i])));
        if (o) {
            o->b = o->a;
            o->a = value;
        }
        n = count;
    }
    return true;
}


// 0x000249d0 FUN_000249d0 (63 B): matches/0x000249d0.cpp
// sym: ?Process@Target_249d0@fn_f6d645d0@@QAE_NXZ
bool Target_249d0::Process() {
    int n = mCount;
    int i = 0;
    if (n > 0) {
        int* p = mArr;
        do {
            Lookuper* l = mB->lk;
            Node* node = (Node*)((hulk_intptr)((owners::ThisWrap_00059c10 *)l)->FUN_00059c10((void *)(hulk_uintptr)(int)(*p)));
            if (node != 0) {
                node->a = node->b;
            }
            n = mCount;
            ++i;
            ++p;
        } while (i < n);
    }
    return true;
}


// 0x00024a10 FUN_00024a10 (118 B): equivalent/0x00024a10.cpp
// sym: ?FUN_00024a10@Group_24a10@fn_f6d645d0@@QAE_NXZ @e5472088f9ba @wa277e4ded196
// STATUS: equivalent (tools/equiv.py level 3: 623 inputs, branch coverage 10/12, incomplete)
// FUN_00024a10 @ 0x00024a10
bool Group_24a10::FUN_00024a10() {
    Item_24a10* keep = DAT_004dd700->inner->current;
    for (int i = 0; i < count; ++i) {
        Item_24a10* item = ((Item_24a10 *)((owners::ThisWrap_00059c10 *)(owner->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
        if (item && item != keep) {
            static_cast<NodeA_24a10*>(item)->FUN_00232240();
            static_cast<NodeB_24a10*>(item)->FUN_00232240();
            item->FUN_00037000();
        }
    }
    return true;
}

} // namespace fn_f6d645d0

// 0x00024a90 FUN_00024a90 (111 B): equivalent/0x00024a90.cpp [wrapped: conflict: World]
// sym: ?FUN_00024a90@Roster_24a90@fn_00024a90@@QAEHPBD@Z @a13eb04f3e67 @waf48c5d6c64d
namespace fn_00024a90 {
// STATUS: equivalent (tools/equiv.py level 3: 599 inputs, branch coverage 8/8)
// FUN_00024a90 @ 0x00024a90
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

union Id64_24a90 {
    unsigned __int64 q;
    unsigned int w[2];
};


struct Clock_24a90 {
    unsigned __int64 FUN_000443c0();
};

struct Entity {
    char pad[0x11c];
    Clock_24a90 *clock;
};

struct World {
};

struct Game_24a90 {
    char pad[0x44];
    World *world;
};

struct Roster_24a90 {
    Game_24a90 *game;
    char pad04[8];
    int count;
    int handles[1];
    int FUN_00024a90(const char *name);
};

int Roster_24a90::FUN_00024a90(const char *name)
{
    Id64_24a90 key;
    key.q = FUN_0027b020(name);
    int matches = 0;
    for (int i = 0; i < count; i++) {
        Id64_24a90 id;
        id.q = ((Entity *)((owners::ThisWrap_00059c10 *)(game->world))->FUN_00059c10((void *)(hulk_uintptr)(int)(handles[i])))->clock->FUN_000443c0();
        if (key.w[0] == id.w[0] && key.w[1] == id.w[1])
            matches++;
    }
    return matches;
}
} // namespace fn_00024a90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f6d645d0 {

// 0x00024b00 FUN_00024b00 (119 B): equivalent/0x00024b00.cpp
// sym: ?FUN_00024b00@Group_24b00@fn_f6d645d0@@QAEHPBUName_24b00@2@@Z @d6db16e68b63 @w7e0d5e8ea343
// STATUS: equivalent (tools/equiv.py level 3: 599 inputs, branch coverage 10/10)
// FUN_00024b00 @ 0x00024b00
int Group_24b00::FUN_00024b00(const Name_24b00* key) {
    int matches = 0;
    for (int i = 0; i < count; ++i) {
        Name_24b00* n = &((Item_24b00 *)((owners::ThisWrap_00059c10 *)(owner->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])))->name;
        if (n->FUN_0027af90(key) && n->c8 == key->c8 && n->c9 == key->c9)
            matches++;
    }
    return matches;
}

} // namespace fn_f6d645d0

// 0x00024b80 FUN_00024b80 (16 B): matches/0x00024b80.cpp [wrapped: conflict: FUN_000678d0]
// sym: ?FUN_00024b80@fn_00024b80@@YAXPAX@Z
namespace fn_00024b80 {
struct Obj_24b80 {
    char pad[0x354];
    int field;
};
Obj_24b80* __cdecl FUN_000678d0();
void __cdecl FUN_00024b80(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_000678d0()->field = 0;
}
} // namespace fn_00024b80

namespace fn_f6d645d0 {

// 0x00024b90 FUN_00024b90 (18 B): matches/0x00024b90.cpp
// sym: ?FUN_00024b90@fn_f6d645d0@@YGPAXPAX@Z
void* __stdcall FUN_00024b90(void* x) {
    char* p = (char*)FUN_000678d0();
    *(void**)(p + 0x2b8) = x;
    return (void*)p;
}

} // namespace fn_f6d645d0

// 0x00024bb0 FUN_00024bb0 (18 B): matches/0x00024bb0.cpp [wrapped: conflict: FUN_000678d0]
// sym: ?FUN_00024bb0@fn_00024bb0@@YGXH@Z
namespace fn_00024bb0 {
struct T_24bb0 {
    char pad[0x2c0];
    int value;
};
T_24bb0* __stdcall FUN_000678d0();
void __stdcall FUN_00024bb0(int arg) {
    T_24bb0* p = FUN_000678d0();
    p->value = arg;
}
} // namespace fn_00024bb0


// 0x00024bd0 FUN_00024bd0 (54 B): matches/0x00024bd0.cpp [wrapped: conflict: Convert]
// sym: ?Get@Owner@fn_00024bd0@@QAEMPBD@Z
namespace fn_00024bd0 {
extern float hulk_at_003f3f08;
struct Result {
    char pad[0x128];
    float value;
};
struct Manager {
    Result* Find_00044ad0(int, int);
};
struct Owner {
    char pad[4];
    Manager* mgr;
    float Get(const char* name);
};
struct Pair {
    int a, b;
};
Pair Convert_0027b020(const char*);
float Owner::Get(const char* name) {
    Manager* m = mgr;
    if (!m)
        return hulk_at_003f3f08;
    Pair p = Convert_0027b020(name);
    Result* r = m->Find_00044ad0(p.a, p.b);
    if (!r)
        return hulk_at_003f3f08;
    return r->value;
}
} // namespace fn_00024bd0


// 0x00024c10 FUN_00024c10 (44 B): matches/0x00024c10.cpp [wrapped: conflict: convert]
// sym: ?set@Obj@fn_00024c10@@QAEXHH@Z
namespace fn_00024c10 {
struct Node {
    char pad[0x128];
    int value;
};
struct Manager {
    Node* get_00044ad0(__int64);
};
__int64 __cdecl convert_0027b020(int);
struct Obj {
    int pad;
    Manager* mgr;
    void set(int x, int y);
};
void Obj::set(int x, int y) {
    Manager* m = mgr;
    if (m) {
        __int64 a = convert_0027b020(x);
        Node* n = m->get_00044ad0(a);
        n->value = y;
    }
}
} // namespace fn_00024c10


// 0x00024c40 FUN_00024c40 (49 B): matches/0x00024c40.cpp [wrapped: conflict: Convert]
// sym: ?Get@Owner@fn_00024c40@@QAEMH@Z
namespace fn_00024c40 {
class Item {
    char pad[0x1a8];

  public:
    float value;
};
class Manager {
  public:
    Item* Find_00044ad0(unsigned long long);
};
extern "C++" unsigned long long __cdecl Convert_0027b020(int);
extern const float hulk_at_003f32e0;
class Owner {
    char pad[4];
    Manager* mgr;

  public:
    float Get(int x);
};
float Owner::Get(int x) {
    Manager* m = mgr;
    unsigned long long v = Convert_0027b020(x);
    Item* p = m->Find_00044ad0(v);
    if (!p)
        return hulk_at_003f32e0;
    return p->value;
}
} // namespace fn_00024c40


// 0x00024c80 FUN_00024c80 (40 B): matches/0x00024c80.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?fn@Holder@fn_00024c80@@QAEXHH@Z
namespace fn_00024c80 {
struct Obj {
    char pad[0x1a8];
    int value;
};
struct Mgr {
    Obj* get_00044ad0(unsigned __int64);
};
struct Holder {
    char pad[4];
    Mgr* mgr;
    void fn(int a, int b);
};
extern "C++" unsigned __int64 __cdecl FUN_0027b020(hulk_intptr);
void Holder::fn(int a, int b) {
    Mgr* m = mgr;
    unsigned __int64 x = FUN_0027b020(a);
    Obj* o = m->get_00044ad0(x);
    o->value = b;
}
} // namespace fn_00024c80


// 0x00024cb0 FUN_00024cb0 (49 B): matches/0x00024cb0.cpp [wrapped: conflict: Obj]
// sym: ?fn@Obj@fn_00024cb0@@QAEMPBD@Z
namespace fn_00024cb0 {
class Thing {
  public:
    char pad[0x1ac];
    float value;
};
class Mgr {
  public:
    Thing* get_00044ad0(unsigned a, unsigned b);
};
class Obj {
  public:
    char pad[4];
    Mgr* mgr;
    float fn(const char* s);
};
extern "C++" unsigned __int64 __cdecl parse_0027b020(const char* s);
extern const float zero;
float Obj::fn(const char* s) {
    Mgr* m = mgr;
    unsigned __int64 id = parse_0027b020(s);
    Thing* t = m->get_00044ad0((unsigned)id, (unsigned)(id >> 32));
    if (!t)
        return zero;
    return t->value;
}
} // namespace fn_00024cb0


// 0x00024cf0 FUN_00024cf0 (40 B): matches/0x00024cf0.cpp [wrapped: conflict: Lookup; Result]
// sym: ?Fn@Host@fn_00024cf0@@QAEXHH@Z
namespace fn_00024cf0 {
struct Result {
    char pad[0x1ac];
    int value;
};
struct Manager {
    Result* Get_00044ad0(unsigned int, unsigned int);
};
struct Host {
    char pad[4];
    Manager* mgr;
    void Fn(int, int);
};
extern "C++" unsigned __int64 __cdecl Lookup_0027b020(int);
void Host::Fn(int a, int b) {
    Manager* m = mgr;
    unsigned __int64 v = Lookup_0027b020(a);
    Result* r = m->Get_00044ad0((unsigned int)v, (unsigned int)(v >> 32));
    r->value = b;
}
} // namespace fn_00024cf0


// 0x00024d20 FUN_00024d20 (43 B): matches/0x00024d20.cpp [wrapped: conflict: Convert; Result]
// sym: ?Fetch@Owner@fn_00024d20@@QAEHH@Z
namespace fn_00024d20 {
struct Result {
    char pad[0x1a4];
    int value;
};
class Provider {
  public:
    Result* Get_00044ad0(__int64);
};
class Owner {
  public:
    char pad[4];
    Provider* provider;
    int Fetch(int x);
};
extern __int64 __cdecl Convert_0027b020(int);
int Owner::Fetch(int x) {
    Provider* p = provider;
    __int64 key = Convert_0027b020(x);
    Result* r = p->Get_00044ad0(key);
    if (!r)
        return 0;
    return r->value;
}
} // namespace fn_00024d20


// 0x00024d50 FUN_00024d50 (40 B): matches/0x00024d50.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Fn@Obj@fn_00024d50@@QAEXHH@Z
namespace fn_00024d50 {
struct Result {
    char pad[0x1a4];
    int value;
};
struct Mid {
    Result* Get_00044ad0(unsigned long long);
};
struct Obj {
    char pad[4];
    Mid* mid;
    void Fn(int, int);
};
extern "C++" unsigned long long __cdecl Conv_0027b020(int);
void Obj::Fn(int a, int b) {
    Mid* m = mid;
    unsigned long long n = Conv_0027b020(a);
    Result* r = m->Get_00044ad0(n);
    r->value = b;
}
} // namespace fn_00024d50

namespace fn_f6d645d0 {

// 0x00024e90 FUN_00024e90 (45 B): equivalent/0x00024e90.cpp
// sym: ?FUN_00024e90@Container@fn_f6d645d0@@QAEPAXHPAX@Z @98a6fb7f3025 @w870ab00b2b26
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00024e90 @ 0x00024e90
void* Container::FUN_00024e90(int index, void* value) {
    if (index < 0 || index >= count)
        return this;
    Result* result = ((Result *)((owners::ThisWrap_00059c10 *)(header->provider))->FUN_00059c10(entries[index]));
    return result->FUN_00035140(value);
}

} // namespace fn_f6d645d0

// 0x00024f10 FUN_00024f10 (15 B): matches/0x00024f10.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?FUN_00024f10@fn_00024f10@@YAXPAX@Z
namespace fn_00024f10 {
extern "C" void _ReadWriteBarrier();
void* __stdcall Get_000678d0();
class Obj {
  public:
    void Run_00065b80(int);
};
void FUN_00024f10(void* /*this, unused: callers pass it (unb4)*/) {
    ((Obj*)Get_000678d0())->Run_00065b80(1);
    _ReadWriteBarrier();
}
} // namespace fn_00024f10


// 0x00024f20 FUN_00024f20 (18 B): matches/0x00024f20.cpp [wrapped: conflict: FUN_000678d0]
// sym: ?FUN_00024f20@fn_00024f20@@YGXH@Z
namespace fn_00024f20 {
struct Obj_24f20 {
    char pad[0x368];
    int m;
};
extern "C++" Obj_24f20* __stdcall FUN_000678d0();
void __stdcall FUN_00024f20(int x) {
    Obj_24f20* p = FUN_000678d0();
    p->m = x;
}
} // namespace fn_00024f20


// 0x00024f40 FUN_00024f40 (12 B): matches/0x00024f40.cpp [wrapped: conflict: FUN_000678d0]
// sym: ?FUN_00024f40@fn_00024f40@@YAMPAX@Z
namespace fn_00024f40 {
extern void* __stdcall FUN_000678d0();
float __cdecl FUN_00024f40(void* /*this, unused: callers pass it (unb4)*/) {
    return *(float*)((char*)FUN_000678d0() + 0x368);
}
} // namespace fn_00024f40

namespace fn_f6d645d0 {

// 0x00024f50 FUN_00024f50 (12 B): matches/0x00024f50.cpp
// sym: ?FUN_00024f50@fn_f6d645d0@@YAXPAX@Z
void FUN_00024f50(void* /*this, unused: callers pass it (unb4)*/) {
    C_24f50* r = (C_24f50*)FUN_000678d0();
    ((owners::C_65ab0 *)r)->FUN_00065ab0();
}


// 0x00024f60 FUN_00024f60 (172 B): equivalent/0x00024f60.cpp
// sym: ?FUN_00024f60@List_24f60@fn_f6d645d0@@QAEHPBD@Z @77281265bde6 @wec7e65611323
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 19/20, incomplete)
// FUN_00024f60 @ 0x00024f60
int List_24f60::FUN_00024f60(const char* text) {
 if (!text || !*text) return 0;
 int matches=0;
 for(int i=0;i<count;++i) {
  Item_24f60* item=((Item_24f60 *)((owners::ThisWrap_00059c10 *)(owner->manager))->FUN_00059c10((void *)(hulk_uintptr)(unsigned)(ids[i])));
  if(item && item->detail) {
   Detail_24f60* d=item->detail;
   if ((char*)d+0x58 && d->enabled) {
    unsigned lo=d->low, hi=d->high;
    U64_24f60 value=FUN_0027b020(text);
    if(lo==(unsigned)value && hi==(unsigned)(value>>32)) ++matches;
   }
  }
 }
 return matches;
}


// 0x00025010 FUN_00025010 (225 B): equivalent/0x00025010.cpp
// sym: ?FUN_00025010@Target_25010@fn_f6d645d0@@QAEPBDPBDH@Z @2c5eec7d650c @we4e217d23780
// STATUS: equivalent (tools/equiv.py level 3: 2359 inputs, branch coverage 23/24, incomplete)
// FUN_00025010 @ 0x00025010
const char* Target_25010::FUN_00025010(const char* name,int occurrence) {
 if (!name || !*name || occurrence<=0) return ((char*)&DAT_003f335c);
 for (int i=0;i<count;++i) {
  Item_25010* item=((Item_25010 *)((owners::ThisWrap_00059c10 *)(owner->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
  if(item && item->info && (char*)item->info+0x58 != 0 && item->info->enabled) {
   U64_25010 key=item->info->key;
   if(key==FUN_0027b020(name) && --occurrence==0) return item->FUN_00036d00();
  }
 }
 return ((char*)&DAT_003f335c);
}

} // namespace fn_f6d645d0

// 0x00025110 FUN_00025110 (296 B): equivalent/0x00025110.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_00025110@Actor_25110@fn_00025110@@QAEXM@Z @08fbf02b2333 @waa191e71a3c3
namespace fn_00025110 {
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 18/18)
// FUN_00025110 @ 0x00025110
struct Vec3_25110 { float x,y,z; };
struct Vec4_25110 { float x,y,z,w; };
struct Position_25110 { void FUN_000382c0(Vec3_25110*); };
struct Entity { char pad[0x148]; Position_25110* position; void FUN_001d69f0(Vec3_25110*); };
struct Selection_25110 { char pad[8]; void* object; int type; };
struct Source_25110 { char pad[0x328]; Selection_25110* selection; unsigned char enabled; };
struct Manager_25110 { unsigned char FUN_001c4050(Vec4_25110*); };
extern Manager_25110* __cdecl FUN_001c3d90();
extern unsigned char __cdecl FUN_00096b50(Selection_25110*,Vec3_25110*,float*);
struct Actor_25110 { char pad0[0x124]; Source_25110* source; char pad1[0x330-0x128]; Vec3_25110 position; float timerReset; float timer; char pad2[0x350-0x344]; unsigned char active; unsigned char inactive; void FUN_00025110(float); };
void Actor_25110::FUN_00025110(float delta) {
 Source_25110* s=source; active=0; inactive=0;
 if (!s) return;
 if (timer >= 0.0f) timer -= delta; else timerReset=5.0f;
 Selection_25110* selection=s->selection;
 if (!selection || !s->enabled) return;
 Vec3_25110 point;
 if (!FUN_00096b50(selection,&point,&delta)) return;
 Manager_25110* manager=FUN_001c3d90();
 Vec4_25110 query; query.x=point.x; query.y=point.y; query.z=point.z; query.w=1.0f;
 unsigned char blocked=manager->FUN_001c4050(&query);
 if (selection->type==5) { Entity* e=(Entity*)selection->object; if (e->position) e->position->FUN_000382c0(&position); else e->FUN_001d69f0(&position); }
 else if (selection->type==1) ((Position_25110*)selection->object)->FUN_000382c0(&position);
 if (!blocked) inactive=1; else active=1;
}
} // namespace fn_00025110


// 0x00025240 FUN_00025240 (30 B): matches/0x00025240.cpp
// sym: ?FUN_00025240@C_25240@owners@@QAEXM@Z
void owners::C_25240::FUN_00025240(float x) {
    if (x > value)
        value = x;
}


// 0x00025260 FUN_00025260 (65 B): matches/0x00025260.cpp
// sym: ?FUN_00025260@C_25260@owners@@QAEXHHH@Z
void owners::C_25260::FUN_00025260(int arg, int, int) {
    int i = 0;
    if (count > 0) {
        do {
            void* p = ((void**)v)[17];
            hulk_intptr x = ((int)((owners::ThisWrap_00059c10 *)(((X_25260*)p)))->FUN_00059c10((void *)(hulk_uintptr)(int)(items[i])));
            if (x)
                ((Y_25260*)x)->Use_000368d0(arg);
            ++i;
        } while (i < count);
    }
}


// 0x00025310 FUN_00025310 (87 B): matches/0x00025310.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Run@Host@fn_00025310@@QAEXHH@Z
namespace fn_00025310 {
struct Info {
    char a[0x1b0];
    int key;
};
struct Item {
    char a[0x11c];
    Info* info;
    void Act_000368d0(int);
};
struct Finder {
};
struct Root {
    char pad[0x44];
    Finder* finder;
    Item* Get(const int* id) {
        Finder* f = finder;
        return ((Item *)((owners::ThisWrap_00059c10 *)f)->FUN_00059c10((void *)(hulk_uintptr)(int)(*id)));
    }
};
class Host {
  public:
    Root* root;
    char pad[8];
    int count;
    int entries[1];
    Item* Get(int i) {
        Root* r = root;
        return r->Get(&entries[i]);
    }
    void Run(int key, volatile int arg);
};
void Host::Run(int key, volatile int arg) {
    for (int i = 0; i < count; i++) {
        Item* p = Get(i);
        if (p && p->info && p->info->key == key)
            p->Act_000368d0(arg);
    }
}
} // namespace fn_00025310


// 0x00025370 FUN_00025370 (65 B): matches/0x00025370.cpp
// sym: ?FUN_00025370@Target_25370@owners@@QAEXH@Z
void owners::Target_25370::FUN_00025370(int arg) {
    int i = 0;
    while (i < count) {
        Ctx_25370* c = (Ctx_25370*)vt[17];
        hulk_intptr r = ((int)((owners::ThisWrap_00059c10 *)c)->FUN_00059c10((void *)(hulk_uintptr)(int)(items[i])));
        if (r)
            ((Act_25370*)r)->Do_00036910(arg);
        ++i;
    }
}


// 0x000253c0 FUN_000253c0 (65 B): matches/0x000253c0.cpp
// sym: ?FUN_000253c0@Target_253c0@owners@@QAEXH@Z
// Same code shape as 0x00025370 (propagated; names are from that function)
void owners::Target_253c0::FUN_000253c0(int arg) {
    int i = 0;
    while (i < count) {
        Ctx_253c0* c = (Ctx_253c0*)vt[17];
        hulk_intptr r = ((int)((owners::ThisWrap_00059c10 *)c)->FUN_00059c10((void *)(hulk_uintptr)(int)(items[i])));
        if (r)
            ((Act_253c0*)r)->Do_00035fa0(arg);
        ++i;
    }
}

namespace fn_f6d645d0 {

// 0x00025410 FUN_00025410 (1 B): matches/0x00025410.cpp
// sym: ?FUN_00025410@fn_f6d645d0@@YAXPAX@Z
void FUN_00025410(void* /*this, unused: callers pass it (unb4)*/) {}


// 0x00025420 FUN_00025420 (73 B): matches/0x00025420.cpp
// sym: ?FUN_00025420@fn_f6d645d0@@YGPAUTriple@1@PAU21@IIII@Z
Triple* __stdcall FUN_00025420(Triple* result, unsigned int x, unsigned int y, unsigned int z,
                               unsigned int arg) {
    Triple value;
    value.x = x;
    value.y = y;
    value.z = z;
    FUN_00095fa0(&value, arg);
    *result = value;
    return result;
}


// 0x00025470 FUN_00025470 (88 B): matches/0x00025470.cpp
// sym: ?Run@Owner_25470@fn_f6d645d0@@QAEXH@Z
// data: gValue_25470 = DAT_003f5bac
void Owner_25470::Run(int id) {
    for (int i = 0; i < count; ++i) {
        Context* c = ctx;
        Manager_25470* m = c->mgr;
        Item_25470* item = ((Item_25470 *)((owners::ThisWrap_00059c10 *)m)->FUN_00059c10((void *)(hulk_uintptr)(int)(entries[i])));
        if (item && item->id == id) {
            ((owners::Controller_3ea10 *)item)->FUN_0003ea10(1);
            item->value = (*(float*)&DAT_003f5bac);
        }
    }
}


// 0x000254d0 FUN_000254d0 (33 B): matches/0x000254d0.cpp
// sym: ?Set@C@fn_f6d645d0@@QAEXHHH@Z
void C::Set(int a, int b, int c) {
    x = a;
    y = b;
    z = c;
}


// 0x00025500 FUN_00025500 (35 B): matches/0x00025500.cpp
// sym: ?Fn@O@fn_f6d645d0@@QAEXXZ
void O::Fn() {
    b50 = 1;
    d1 = 4;
    d2 = 3;
    d3 = 1;
}


// 0x00025530 FUN_00025530 (39 B): matches/0x00025530.cpp
// sym: ?SetLimit@fn_f6d645d0@@YGXM@Z
// data: limitValue = DAT_004dc0d8, zeroValue = DAT_003f32e0
void __stdcall SetLimit(float v) {
    (*(float*)&DAT_004dc0d8) = v;
    if (v < DAT_003f32e0)
        (*(float*)&DAT_004dc0d8) = 8.0f;
}


// 0x00025560 FUN_00025560 (8 B): matches/0x00025560.cpp
// sym: ?Clear@Obj_25560@fn_f6d645d0@@QAEXXZ
void Obj_25560::Clear() {
    m353 = 0;
}


// 0x00025570 FUN_00025570 (13 B): matches/0x00025570.cpp
// sym: ?Set@Obj_25570@fn_f6d645d0@@QAEXH@Z
void Obj_25570::Set(int v) {
    value = v;
}


// 0x00025580 FUN_00025580 (7 B): matches/0x00025580.cpp
// sym: ?GetX@Obj_25580@fn_f6d645d0@@QAEHXZ
int Obj_25580::GetX() {
    return m32c;
}


// 0x00025590 FUN_00025590 (390 B): equivalent/0x00025590.cpp
// sym: ?FUN_00025590@Mgr_25590@fn_f6d645d0@@QAEXPAURecord_25590@2@HHHHPBUMat4_25590@2@HI@Z @3bbfc5882583 @wf65002d1d0f9
// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 13/14, incomplete)
// FUN_00025590 @ 0x00025590
void Mgr_25590::FUN_00025590(Record_25590 *rec, int a1, int a2, int a3, int a4, const Mat4_25590 *mat, int a6, unsigned int stamp)
{
    int n = count;
    int i = 0;
    if (n > 0) {
        Entry_25590 *e = &entries[0];
        do {
            if (e->key == rec->key) {
                if (e->stamp > stamp) return;
                e->nameA.FUN_0027af70(a1);
                e->f58 = a2;
                e->nameB.FUN_0027af70(a3);
                e->f5c = a4;
                e->mat = *mat;
                e->stamp = stamp;
                e->f60 = a6;
                e->fixed = rec->fixed;
                return;
            }
            i++;
            e++;
        } while (i < count);
    }
    if (n >= 16) {
        Name_25590 name;
        int v;
        name.FUN_0027af00();
        if (rec->fixed) {
            name.FUN_0027af70(a3);
            v = a4;
        } else {
            name.FUN_0027af70(a1);
            v = a2;
        }
        if ((name.lo | name.hi) != 0) {
            FUN_0027f250()->FUN_00283a40(&name, mat, a6, v);
        }
        name.FUN_0027af50();
        return;
    }
    Entry_25590 *e = &entries[n];
    e->key = rec->key;
    e->nameA.FUN_0027af70(a1);
    e->f58 = a2;
    e->nameB.FUN_0027af70(a3);
    e->f5c = a4;
    e->mat = *mat;
    e->stamp = stamp;
    e->f60 = a6;
    e->fixed = rec->fixed;
    count++;
}

} // namespace fn_f6d645d0

// 0x00025720 FUN_00025720 (48 B): matches/0x00025720.cpp
// sym: ?FUN_00025720@C_25720@owners@@QAEXH@Z
void owners::C_25720::FUN_00025720(int key) {
    int n = count;
    int i = 0;
    if (n > 0) {
        E_25720* p = (E_25720*)((char*)this + 0x590);
        do {
            if (p->key == key) {
                p->flag = 1;
                return;
            }
            ++i;
            p = (E_25720*)((char*)p + 0x68);
        } while (i < n);
    }
}


// 0x00025750 FUN_00025750 (193 B): equivalent/0x00025750.cpp [wrapped: conflict: Object]
// sym: ?FUN_00025750@Object@fn_00025750@@QAEXXZ @6527152319a3 @waed9a91638f3
namespace fn_00025750 {
// STATUS: equivalent (tools/equiv.py level 3: 759 inputs, branch coverage 8/8)
// FUN_00025750 @ 0x00025750
struct Handle_25750 {
 unsigned int a,b;
 void FUN_0027af00();
 void FUN_0027af70(const void*);
 void FUN_0027af50();
};
struct Entry_25750 {
 char data[0x40];
 Handle_25750 first;
 Handle_25750 second;
 char gap[8];
 unsigned int valueFirst;
 unsigned int valueSecond;
 unsigned int kind;
 unsigned char useSecond;
 char tail[3];
};
struct Manager_25750 { void FUN_00283a40(Handle_25750*, Entry_25750*, unsigned int, unsigned int); };
struct Object {
 char pad[0x58c];
 int count;
 Entry_25750 entries[1];
 Manager_25750* FUN_0027f250();
 void FUN_00025750();
};
void Object::FUN_00025750() {
 Manager_25750* manager=FUN_0027f250();
 for(int i=0;i<count;++i) {
  Entry_25750* entry=&entries[i];
  Handle_25750 temp;
  temp.FUN_0027af00();
  unsigned int value;
  if(entry->useSecond) {temp.FUN_0027af70(&entry->second);value=entry->valueSecond;}
  else {temp.FUN_0027af70(&entry->first);value=entry->valueFirst;}
  if(temp.a | temp.b) manager->FUN_00283a40(&temp,entry,entry->kind,value);
  temp.FUN_0027af50();
 }
 count=0;
}
} // namespace fn_00025750

namespace fn_f6d645d0 {

// 0x00025820 FUN_00025820 (101 B): matches/0x00025820.cpp
// sym: ?FUN_00025820@Table_25820@fn_f6d645d0@@QAEXPBDPBX@Z
// FUN_00025820 @ 0x00025820
void Table_25820::FUN_00025820(const char* name, const void* src) {
    int i = 0;
    if ((*(int*)&DAT_003fa114) > 0) {
        do {
            if (FUN_00096600(name, ((const char**)&DAT_0049548c)[i]) == 0) {
                int k = i - 1;
                if (k >= 0 && k < 9)
                    FUN_00267830(names[k], src, 0x20);
                return;
            }
            i++;
        } while (i < (*(int*)&DAT_003fa114));
    }
}

} // namespace fn_f6d645d0

// 0x00025890 FUN_00025890 (31 B): matches/0x00025890.cpp
// sym: ?FUN_00025890@C_25890@owners@@QAEPAXH@Z
void* owners::C_25890::FUN_00025890(int x) {
    if (x >= 0 && x < 9)
        return (void*)((char*)this + 0xc10 + x * 0x20);
    return 0;
}

namespace fn_f6d645d0 {

// 0x000258b0 FUN_000258b0 (116 B): equivalent/0x000258b0.cpp
// sym: ?FUN_000258b0@Palette_258b0@fn_f6d645d0@@QAEXPBDMMM@Z @18182650d012 @wd74be07e1197
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/8, incomplete)
// FUN_000258b0 @ 0x000258b0
void Palette_258b0::FUN_000258b0(const char *name, float r, float g, float b)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (FUN_00096600(name, ((const char**)&DAT_00496f8c)[i]) == 0)
            break;
    }
    if (i >= 4)
        return;
    unsigned int c = (int)r | 0xffffff00u;
    c <<= 8;
    c |= (int)g;
    c <<= 8;
    c |= (int)b;
    colors[i] = c;
}

} // namespace fn_f6d645d0

// 0x00025930 FUN_00025930 (42 B): matches/0x00025930.cpp
// sym: ?FUN_00025930@Palette_25930@owners@@QAEPAIPAIH@Z
unsigned int* owners::Palette_25930::FUN_00025930(unsigned int* out, int index) {
    if (index >= 0 && index < 4)
        *out = colors[index];
    else
        *out = 0xffff00ff;
    return out;
}

namespace fn_f6d645d0 {

// 0x00025960 FUN_00025960 (36 B): matches/0x00025960.cpp
// sym: ?Set@fn_f6d645d0@@YAXPAPAVObj_25960@1@PAV21@@Z
// Same code shape as 0x000187a0 (propagated; names are from that function)
void Set(Obj_25960** p, Obj_25960* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}


// 0x00025990 FUN_00025990 (45 B): matches/0x00025990.cpp
// sym: ?FUN_00025990@fn_f6d645d0@@YAMPBUVec3@1@0@Z
hulk_freg __cdecl FUN_00025990(const Vec3* a, const Vec3* b) {
    hulk_freg x = a->x - b->x;
    hulk_freg y = a->y - b->y;
    hulk_freg z = a->z - b->z;
    hulk_freg r = x * x;
    r += z * z;
    r += y * y;
    return r;
}


// 0x000259c0 FUN_000259c0 (33 B): matches/0x000259c0.cpp
// sym: ?FUN_000259c0@fn_f6d645d0@@YIMPAM@Z
// Same code shape as 0x00018990 (propagated; names are from that function)
hulk_freg __fastcall FUN_000259c0(float* p) {
    return sqrt((double)(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]));
}


// 0x00025a20 FUN_00025a20 (105 B): equivalent/0x00025a20.cpp
// sym: ?Set@Params@fn_f6d645d0@@QAEXHHPBUVec3I@2@0MM@Z @1f4e9b75e0a0 @w9e0b4afabd0f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00025a20 @ 0x00025a20
void Params::Set(int a_, int b_, const Vec3I* p0, const Vec3I* p1, float lo_, float hi_)
{
    a = a_;
    b = b_;
    state = 0;
    v0 = *p0;
    v1 = *p1;
    lo = reinterpret_cast<int&>(lo_);
    if (lo_ >= hi_)
        hi = reinterpret_cast<int&>(lo_);
    else
        hi = reinterpret_cast<int&>(hi_);
}


// 0x00025a90 FUN_00025a90 (671 B): equivalent/0x00025a90.cpp
// sym: ?FUN_00025a90@Thing_25a90@fn_f6d645d0@@QAEPAU12@XZ @0cf2b4a86fbe @w3441c748adf0
// STATUS: equivalent (tools/equiv.py level 3: 6310 inputs, branch coverage 16/16)
// FUN_00025a90 @ 0x00025a90
// FUN_00025a90 @ 0x00025a90
Thing_25a90 *Thing_25a90::FUN_00025a90()
{
    f00 = 0;
    f0c = 0;
    f124 = 0;
    f328 = 0;
    f32c = 9;
    f33c = 5.0f;
    f340 = 0;
    f344 = 0;
    f348 = 0;
    f34c = 0;
    f350 = 0;
    f351 = 0;
    f352 = 1;
    f353 = 0;
    f354 = 0;
    f358 = 0;
    f35c = 0;
    f360 = 0;
    f364 = 0;
    f368 = 0;
    f36c = 0;
    f370 = 0;
    f374 = 0;
    f378 = 0;
    for (int i = 0; i < 16; i++) {
        entries[i].nameA.FUN_0027af00();
        entries[i].nameB.FUN_0027af00();
    }
    f50 = 1;
    fd4 = 4;
    fd8 = 3;
    fdc = 1;
    for (int i = 0; i < 16; i++)
        zeros[i] = 0;

    void *mem = FUN_0008d690(0x14);
    if (mem)
        f04 = ((CCharacterTemplateManager_25a90 *)mem)->FUN_00047890(this, 0x20);
    else
        f04 = 0;
    mem = FUN_0008d690(0x908);
    if (mem)
        f08 = ((Obj908 *)mem)->FUN_00067ea0();
    else
        f08 = 0;

    for (int i = 0; i < 32; i++) {
        pairs[i].a = 0;
        pairs[i].b = 0;
    }
    FUN_00232d70(FUN_00024120, 0);

    Registry_25a90 *reg = (*(Registry_25a90**)&DAT_004e5af8);
    if (reg) {
        unsigned __int64 h = FUN_002672f0((*(const char**)&DAT_0048e060), 0, 0);
        void *p = reg->FUN_00232840((unsigned int)h, (unsigned int)(h >> 32));
        if (p) {
            FUN_000553d0(p);
            FUN_00073700(p);
        }
        h = FUN_002672f0((*(const char**)&DAT_0048e064), 0, 0);
        p = reg->FUN_00232840((unsigned int)h, (unsigned int)(h >> 32));
        if (p) {
            FUN_00055d80(p);
            FUN_00074790(p);
        }
        h = FUN_002672f0((*(const char**)&DAT_0048e068), 0, 0);
        p = reg->FUN_00232840((unsigned int)h, (unsigned int)(h >> 32));
        if (p) {
            FUN_00056460(p);
            FUN_000749e0(p);
        }
    }
    ((ThisNote_00031310*)this)->FUN_00031310();
    f128 = 0;
    (*(float*)&DAT_004dc0d8) = 8.0f;
    f580 = 0;
    for (int i = 0; i < 9; i++)
        slots[i].flag = 0;
    fd30 = 0xff3fc0ff;
    fd34 = 0xffff00e0;
    fd38 = 0xff3fffe1;
    return this;
}


// 0x00025d30 FUN_00025d30 (30 B): equivalent/0x00025d30.cpp
// sym: ?FUN_00025d30@fn_f6d645d0@@YGHPAUObject@1@@Z @698bca028fdf @w617f481624c2
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00025d30 @ 0x00025d30
int __stdcall FUN_00025d30(Object* object) {
    return object && object->FUN_00035ab0() ? 1 : 0;
}


// 0x00025d50 FUN_00025d50 (255 B): equivalent/0x00025d50.cpp
// sym: ?FUN_00025d50@Selection_25d50@fn_f6d645d0@@QAEHMMM@Z @b141a988d606 @w0e06c9b26eeb
// STATUS: equivalent (tools/equiv.py level 3: 569 inputs, branch coverage 16/16)
// FUN_00025d50 @ 0x00025d50
int Selection_25d50::FUN_00025d50(float x,float y,float z) {
 float best=-1.0f; int selected=-1;
 for(int i=0;i<count;++i) {
  Entry_25d50* entry=owner->manager->FUN_00059ba0(ids[i]);
  if(!entry) continue;
  Actor_25d50* actor=entry->FUN_00059a30();
  if(!actor || actor->FUN_00035ab0()) continue;
  Vec_25d50 p; entry->FUN_00059a50(&p);
  double dx=(double)p.x-x, dy=(double)p.y-y, dz=(double)p.z-z;
  double distance=sqrt(dz*dz+dy*dy+dx*dx);
  if(best<0.0f || distance<best) {best=(float)distance;selected=i;}
 }
 if(selected<0) return 0;
 return ((Actor_25d50 *)((owners::ThisWrap_00059c10 *)(owner->manager))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[selected])))->FUN_00036d00();
}

} // namespace fn_f6d645d0

// 0x00025e50 FUN_00025e50 (91 B): equivalent/0x00025e50.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?FUN_00025e50@Owner@fn_00025e50@@QAEHPAUObj@2@@Z @09dfc3fb77c0 @w51229c3365b5
namespace fn_00025e50 {
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 8/8)
// FUN_00025e50 @ 0x00025e50
struct Obj { virtual void FUN_00000000(); virtual void FUN_00000004(); char pad[0x20a4]; int state; }; struct Owner { char pad[0x124]; Obj* object; int FUN_00025e50(Obj* next); }; struct Result { unsigned int FUN_001b4c40(Obj*); }; Result* __cdecl FUN_001b6580(); int Owner::FUN_00025e50(Obj* next) { hulk_uintptr value=(hulk_uintptr)object; if (next != object) { if (next) next->FUN_00000000(); if (object) object->FUN_00000004(); object=next; if (next) next->state=0; Obj* current=object; value=FUN_001b6580()->FUN_001b4c40(current); } return (value & 0xffffff00u)|1; }
} // namespace fn_00025e50


// 0x00025eb0 FUN_00025eb0 (94 B): matches/0x00025eb0.cpp
// sym: ?FUN_00025eb0@Thing_25eb0@owners@@QAEXXZ
// data: gValue_25eb0 = DAT_004dc0d8
void owners::Thing_25eb0::FUN_00025eb0() {
    mFlag50 = 1;
    mA = 4;
    mB = 3;
    mC = 1;
    InitThing_00044c00(mChild);
    m350 = 0;
    m351 = 0;
    m352 = 1;
    (*(int*)&DAT_004dc0d8) = 0x41000000;
    m584 = 0x7fffffff;
    m588 = 0;
}


// 0x00025f10 FUN_00025f10 (169 B): equivalent/0x00025f10.cpp [wrapped: conflict: World]
// sym: ?SetFlag@Group_25f10@fn_00025f10@@QAEXPBDD@Z @c002d19819a9 @w6e3984a7c347
namespace fn_00025f10 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 20/20)
// FUN_00025f10 @ 0x00025f10
// 0x00025f10: set a flag on the controller(s) selected by name ("all" or one named entry)
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

int __cdecl FUN_00096600(const char* a, const char* b);

struct Pawn_25f10 {
    char pad[0x1ca0];
    struct Ctl_25f10* ctl;
    char pad2[0];
    char FUN_00035ab0();
};
struct Ctl_25f10 {
    char pad[0xf4];
    char flag;
};
struct Pawns {
};
struct World {
    char pad[0x44];
    Pawns* pawns;
};

class Group_25f10 {
public:
    World* world;
    int pad04[2];
    int count;
    int ids[16];
    Pawn_25f10* FUN_00024280(unsigned __int64 key);
    void SetFlag(const char* name, char flag);
};

void Group_25f10::SetFlag(const char* name, char flag)
{
    if (name == 0 || *name == 0)
        return;

    if (FUN_00096600(name, "all") == 0) {
        for (int i = 0; i < count; i++) {
            Pawn_25f10* p = ((Pawn_25f10 *)((owners::ThisWrap_00059c10 *)(world->pawns))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
            if (p == 0 || p->FUN_00035ab0() == 0) {
                Ctl_25f10* c = p->ctl;
                if (c != 0)
                    c->flag = flag;
            }
        }
    } else {
        Pawn_25f10* p = FUN_00024280(FUN_002672f0(name, 0, 0));
        if (p != 0) {
            Ctl_25f10* c = p->ctl;
            if (c != 0)
                c->flag = flag;
        }
    }
}
} // namespace fn_00025f10
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00025fc0 FUN_00025fc0 (41 B): matches/0x00025fc0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Target@Obj@fn_00025fc0@@QAEXH@Z
namespace fn_00025fc0 {
extern "C++" __int64 __cdecl FUN_002672f0(int, int, int);
class Obj {
  public:
    int FUN_00024280(__int64);
    void FUN_00025e50(int);
    void Target(int);
};
void Obj::Target(int x) {
    FUN_00025e50(FUN_00024280(FUN_002672f0(x, 0, 0)));
}
} // namespace fn_00025fc0


// 0x00025ff0 FUN_00025ff0 (2198 B): equivalent/0x00025ff0.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?Update@Selector_25ff0@fn_00025ff0@@QAEXMM@Z @a9c76e00c442 @w7e52608ddc7a
namespace fn_00025ff0 {
// STATUS: equivalent (tools/equiv.py level 3: 1306 inputs, branch coverage 143/146, incomplete)
// FUN_00025ff0 @ 0x00025ff0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif


struct V3_25ff0 {
    float x, y, z;
    hulk_freg FUN_000111f0();
};
struct V4_25ff0 { float x, y, z, w; };

struct Mat_25ff0 {
    float m[16];
};

struct Query_25ff0 {
    float f[5];
};

struct Pos10_25ff0 {
    void FUN_00059a50(V3_25ff0 *out);
};

struct Sink_25ff0 {
    char FUN_001c4010(Query_25ff0 *q);
    Mat_25ff0 *FUN_001c3990();
};
Sink_25ff0 *FUN_001c3d90();

class Selector_25ff0;
struct Gadget11c {
    char pad00[0x10];
    char b10;
};
struct Gadget1ca0 {
    char pad00[0xe8];
    char be8;
};

struct Entity;

struct Entity {
    char pad00[0x10];
    Pos10_25ff0 *f10;
    char pad14[0x11c - 0x14];
    Gadget11c *f11c;
    char pad120[0x12c - 0x120];
    int f12c;
    char pad130[0x328 - 0x130];
    int f328;
    char pad32c[0x334 - 0x32c];
    Entity *f334;
    Entity *f338;
    char pad33c[0x1ca0 - 0x33c];
    Gadget1ca0 *f1ca0;
    char pad1ca4[0x1d04 - 0x1ca4];
    char b1d04;
    char pad1d05[0x1f50 - 0x1d05];
    char b1f50;
    char pad1f51[0x20b0 - 0x1f51];
    int f20b0;
    void FUN_000359e0(Query_25ff0 *q);
};

struct EntityTable {
    char pad00[0x44];
    struct Lookup_25ff0 *f44;
};
struct Lookup_25ff0 {
};

struct Frame_25ff0 {
    int k;                  // 0x00
    int i;                  // 0x04
    int q;                  // 0x08
    int m;                  // 0x0c
    float s;                // 0x10
    V3_25ff0 d;                   // 0x14
    union {
        V4_25ff0 vt;              // 0x20
        Query_25ff0 qe;           // 0x20..0x33
    };
    float pY, pZ;           // 0x34, 0x38 (P.x is qe.f[4])
    int u;                  // 0x3c
    Selector_25ff0 *savedThis;    // 0x40
    V3_25ff0 zeroV;               // 0x44
    int t50, t54, t58;      // 0x50
    Sink_25ff0 *sink;             // 0x5c
    float S1[16];           // 0x60
    Query_25ff0 q0;               // 0xa0..0xb3, q0.f[4] is the first word of mat / L2
    char matRest[0xf0 - 0xb4];
    int L1[12];             // 0xf0
    char tail[0x130 - 0x120];
};

class Selector_25ff0 {
public:
    EntityTable *tbl;
    char pad04[8];
    int count;
    int ids[16];
    char enabled;
    char pad51[3];
    int flags[16];
    float score[16];
    int lim1;
    int lim2;
    int lim3;
    char pade0[0x124 - 0xe0];
    Entity *me;

    char FUN_00024300(Entity *e);
    void Update(float unusedA, float dt);
};

void Selector_25ff0::Update(float unusedA, float dt)
{
    if (!enabled) {
        for (int i = 0; i < count; i++) {
            flags[i] = 3;
            score[i] = dt + score[i];
        }
        return;
    }

    Frame_25ff0 f;
    Mat_25ff0 *mat = (Mat_25ff0 *)&f.q0.f[4];
    int *L2 = (int *)&f.q0.f[4];
    f.savedThis = this;
    f.zeroV.x = 0;
    f.zeroV.y = 0;
    f.zeroV.z = 0;
    f.sink = FUN_001c3d90();
    float r;
    if (me != 0) {
        me->FUN_000359e0(&f.q0);
        f.q0.f[3] = f.q0.f[3] * 0.5f;
        if (f.sink->FUN_001c4010(&f.q0)) {
            // Our own position goes in the same slot the loop later uses for each entity's
            // position (just past the query): the loop's first query sees it there.
            V3_25ff0 *pos = (V3_25ff0 *)&f.qe.f[4];
            pos->x = 0;
            pos->y = 0;
            pos->z = 0;
            me->f10->FUN_00059a50(pos);
            V3_25ff0 *c = ((V3_25ff0 *)((owners::Object_1c39d0 *)(f.sink))->FUN_001c39d0());
            f.d.x = pos->x - c->x;
            f.d.y = pos->y - c->y;
            f.d.z = pos->z - c->z;
            *mat = *f.sink->FUN_001c3990();
            r = (float)(sqrt((double)(f.d.z * f.d.z + f.d.y * f.d.y + f.d.x * f.d.x)) * 0.5f);
        } else {
            *mat = *f.sink->FUN_001c3990();
            r = 10.0f;
        }
    } else {
        *mat = *f.sink->FUN_001c3990();
        r = 10.0f;
    }
    f.vt.x = 0;
    f.vt.y = 0;
    f.vt.z = r;
    f.vt.w = 0;
    ((owners::Mat_22c2b0 *)mat)->FUN_0022c2b0((float *)(const V4_25ff0 *)(&f.vt), (float *)(V3_25ff0 *)(&f.zeroV));

    f.k = 0;
    f.m = 0;
    f.u = 0;
    for (f.i = 0; f.i < count; f.i++) {
        Entity *es = ((Entity *)((owners::ThisWrap_00059c10 *)(tbl->f44))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[f.i])));
        float sc = dt + score[f.i];
        bool had4 = (flags[f.i] & 4) != 0;
        score[f.i] = sc;
        if (had4) {
            flags[f.i] = 3;
            continue;
        }
        flags[f.i] = 0;
        if (es == me) {
            f.k++;
            flags[f.i] = 3;
            continue;
        }
        Gadget11c *g = es->f11c;
        if (es->b1f50) {
            f.k++;
            flags[f.i] = 3;
            continue;
        }
        if (es->f1ca0 && es->f1ca0->be8) {
            f.k++;
            flags[f.i] = 3;
            continue;
        }
        if (es->b1d04) {
            f.k++;
            flags[f.i] = 3;
            continue;
        }
        if (me) {
            if (es->f12c == me->f328 || es == me->f334 || es == me->f338) {
                f.k++;
                flags[f.i] = 3;
                continue;
            }
        }
        f.qe.f[3] = 1.0f;
        es->FUN_000359e0(&f.qe);
        f.qe.f[3] = f.qe.f[3] * 0.75f;
        if (!f.sink->FUN_001c4010(&f.qe)) {
            f.s = score[f.i];
            int pos = 0;
            while (pos < f.u && !(f.s > score[L2[pos]]))
                pos++;
            for (int e = f.u; e > pos; e--)
                L2[e] = L2[e - 1];
            L2[pos] = f.i;
            f.u++;
            continue;
        }
        flags[f.i] |= 2;
        if (g && g->b10) {
            flags[f.i] |= 1;
            f.k++;
            continue;
        }
        if (FUN_00024300(es)) {
            flags[f.i] |= 1;
            continue;
        }
        if (es->f20b0 != 0) {
            f.L1[f.m] = f.i;
            f.S1[f.m] = 3.4028235e+38f;
            f.m++;
            continue;
        }
        V3_25ff0 *P = (V3_25ff0 *)&f.qe.f[4];
        P->x = 0;
        P->y = 0;
        P->z = 0;
        es->f10->FUN_00059a50(P);
        f.d.x = P->x - f.zeroV.x;
        f.d.y = P->y - f.zeroV.y;
        f.d.z = P->z - f.zeroV.z;
        float x = f.d.FUN_000111f0();
        if (f.qe.f[3] > 0.0f)
            x = x / (f.qe.f[3] * f.qe.f[3]);
        int pos = 0;
        while (pos < f.m && !(x < f.S1[pos]))
            pos++;
        for (int e = f.m; e > pos; e--) {
            f.L1[e] = f.L1[e - 1];
            f.S1[e] = f.S1[e - 1];
        }
        f.S1[pos] = x;
        f.L1[pos] = f.i;
        f.m++;
    }

    int n1 = lim1 - f.k;
    if (n1 > 0) {
        if (n1 > f.m)
            n1 = f.m;
        for (int j = 0; j < n1; j++)
            flags[f.L1[j]] |= 1;
    } else {
        n1 = 0;
    }
    if (f.m - n1 > 0) {
        int q2 = lim2;
        if (q2 <= 0) {
            int rem = f.m - n1;
            q2 = rem % 2 + rem / 2;
        }
        int *L3 = (int *)f.S1;
        int cnt = 0;
        for (int j = n1; j < f.m; j++) {
            int id = f.L1[j];
            float s = score[id];
            int pos = 0;
            while (pos < cnt && !(s > score[L3[pos]]))
                pos++;
            for (int e = cnt; e > pos; e--)
                L3[e] = L3[e - 1];
            L3[pos] = id;
            cnt++;
        }
        if (q2 > cnt)
            q2 = cnt;
        for (int j = 0; j < q2; j++)
            flags[L3[j]] |= 1;
    }

    int n3 = lim3;
    if (n3 < 1)
        n3 = 1;
    if (n3 > f.u)
        n3 = f.u;
    for (int j = 0; j < n3; j++)
        flags[L2[j]] |= 1;
}
} // namespace fn_00025ff0


// 0x00026890 FUN_00026890 (56 B): matches/0x00026890.cpp [wrapped: conflict: Owner::Run; Parse]
// sym: ?Run@Owner@fn_00026890@@QAE_NHH@Z
namespace fn_00026890 {
struct Obj {
    void Func_00035ce0(int);
};
struct Owner {
    Obj* Find_00024280(unsigned long long);
    bool Run(int, int);
};
extern "C++" unsigned long long __cdecl Parse_002672f0(int, int, int);
bool Owner::Run(int a, int b) {
    unsigned long long x = Parse_002672f0(a, 0, 0);
    Obj* p = Find_00024280(x);
    if (!p)
        return false;
    p->Func_00035ce0(b);
    return true;
}
} // namespace fn_00026890

namespace fn_f6d645d0 {

// 0x000268d0 FUN_000268d0 (51 B): matches/0x000268d0.cpp
// sym: ?Run@X@fn_f6d645d0@@QAEDHH@Z
char X::Run(int a, int b) {
    __int64 v = Find(a, 0, 0);
    Obj* o = Get_00024280(v);
    if (!o)
        return 0;
    o->flag = 1;
    return 1;
}


// 0x00026910 FUN_00026910 (54 B): matches/0x00026910.cpp
// sym: ?Test@Owner@fn_f6d645d0@@QAEDHUVec3_26910@2@@Z
char Owner::Test(int a, Vec3_26910 b) {
    __int64 key = Convert(a, 0, 0);
    Result* r = Find_00024280(key);
    if (!r)
        return 0;
    return r->Check_000353d0(&b);
}

} // namespace fn_f6d645d0

// 0x00026950 FUN_00026950 (56 B): matches/0x00026950.cpp [wrapped: conflict: Owner; Owner::Run]
// sym: ?Run@Owner@fn_00026950@@QAEDHH@Z
namespace fn_00026950 {
class Item {
  public:
};
extern "C++" __int64 __cdecl Lookup_002672f0(int, int, int);
class Owner {
  public:
    Item* Get_00024280(__int64);
    char Run(int, int);
};
char Owner::Run(int key, int value) {
    __int64 id = Lookup_002672f0(key, 0, 0);
    Item* item = Get_00024280(id);
    if (!item)
        return 0;
    ((owners::Obj_35930 *)item)->FUN_00035930(value);
    return 1;
}
} // namespace fn_00026950


// 0x00026990 FUN_00026990 (47 B): matches/0x00026990.cpp [wrapped: conflict: Owner]
// sym: ?Run@Owner@fn_00026990@@QAEPAVItem@2@H@Z
namespace fn_00026990 {
class Item {
  public:
};
class Owner {
  public:
    Item* Run(int);
    Item* Find_00024280(unsigned __int64);
};
extern "C++" unsigned __int64 __cdecl Make_002672f0(int, int, int);
Item* Owner::Run(int x) {
    unsigned __int64 v = Make_002672f0(x, 0, 0);
    Item* p = Find_00024280(v);
    if (!p)
        return p;
    return ((Item *)((owners::Widget_35910 *)p)->FUN_00035910());
}
} // namespace fn_00026990


// 0x000269c0 FUN_000269c0 (45 B): matches/0x000269c0.cpp [wrapped: conflict: Lookup]
// sym: ?Do@Owner@fn_000269c0@@QAEXHH@Z
namespace fn_000269c0 {
typedef __int64 i64;
extern "C++" i64 __cdecl Lookup_002672f0(int a, int b, int c);
class Result {
  public:
    void Apply_0003dd00(int);
};
class Owner {
  public:
    Result* Select_00024280(i64);
    void Do(int, int);
};
void Owner::Do(int a, int b) {
    Result* r = Select_00024280(Lookup_002672f0(a, 0, 0));
    r->Apply_0003dd00(b);
}
} // namespace fn_000269c0


// 0x000269f0 FUN_000269f0 (91 B): matches/0x000269f0.cpp
// sym: ?FUN_000269f0@C_269f0@owners@@QAE_NHH@Z
bool owners::C_269f0::FUN_000269f0(int x, int y) {
    int i = count;
    if (i >= 0x20)
        return false;
    if (find(x, y) != -1)
        return false;
    *(int*)(slots + i * 8) = x;
    *(int*)(slots + i * 8 + 4) = y;
    count = count + 1;
    return true;
}


// 0x00026ab0 FUN_00026ab0 (47 B): matches/0x00026ab0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?set@Owner@fn_00026ab0@@QAEXHE@Z
namespace fn_00026ab0 {
extern "C++" __int64 __cdecl makeKey_002672f0(int, int, int);
struct Item {
    char pad[0x1d78];
    unsigned char flag;
};
class Owner {
  public:
    Item* lookup_00024280(__int64 key);
    void set(int key, unsigned char value);
};
void Owner::set(int key, unsigned char value) {
    __int64 k = makeKey_002672f0(key, 0, 0);
    Item* p = lookup_00024280(k);
    if (p)
        p->flag = value;
}
} // namespace fn_00026ab0


// 0x00026ae0 FUN_00026ae0 (47 B): matches/0x00026ae0.cpp [wrapped: conflict: Result]
// sym: ?set@X@fn_00026ae0@@QAEXHH@Z
namespace fn_00026ae0 {
struct Result {
    char pad[0x1d7c];
    int value;
};
struct X {
    Result* lookup_00024280(unsigned long long);
    void set(int a, int b);
};
extern "C++" unsigned long long __cdecl convert_002672f0(int, int, int);
void X::set(int a, int b) {
    unsigned long long v = convert_002672f0(a, 0, 0);
    Result* r = lookup_00024280(v);
    if (r)
        r->value = b;
}
} // namespace fn_00026ae0


// 0x00026b10 FUN_00026b10 (49 B): matches/0x00026b10.cpp [wrapped: compile error C2661: 'fn_f6d645d0::Owner::lookup' : no overloaded function takes 3 arguments]
// sym: ?Action@Owner@fn_00026b10@@QAEXHUVec3_26b10@2@@Z
namespace fn_00026b10 {
extern "C++" __int64 __cdecl lookup_002672f0(int, int, int);
// b..d: a 3-word vector passed by value.
struct Vec3_26b10 {
    int x, y, z;
};
class Result {
  public:
    void Set_0003f400(void*);
};
class Owner {
  public:
    Result* Find_00024280(__int64);
    void Action(int a, Vec3_26b10 b);
};
void Owner::Action(int a, Vec3_26b10 b) {
    __int64 id = lookup_002672f0(a, 0, 0);
    Result* r = Find_00024280(id);
    if (r)
        r->Set_0003f400(&b);
}
} // namespace fn_00026b10

namespace fn_f6d645d0 {

// 0x00026c30 FUN_00026c30 (133 B): equivalent/0x00026c30.cpp
// sym: ?FUN_00026c30@Owner_26c30@fn_f6d645d0@@QAE?AUVec3_26c30@2@PBD@Z @11a8ebf30695 @wfc801b6199b8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00026c30 @ 0x00026c30
Vec3_26c30 Owner_26c30::FUN_00026c30(const char* name)
{
    Entry_26c30* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!entry) {
        Vec3_26c30 none = { 0.0f, 0.0f, 0.0f };
        return none;
    }
    Vec3_26c30 result = { 0.0f, 0.0f, 0.0f };
    entry->child->FUN_00059a50(&result);
    return result;
}


// 0x00026cc0 FUN_00026cc0 (133 B): equivalent/0x00026cc0.cpp
// sym: ?FUN_00026cc0@Group_26cc0@fn_f6d645d0@@QAEPAUVec3_26cc0@2@PAU32@PBD@Z @9c560aaf6fc0 @w6c06a66b2f8f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00026cc0 @ 0x00026cc0
Vec3_26cc0 *Group_26cc0::FUN_00026cc0(Vec3_26cc0 *out, const char *name)
{
    Pawn_26cc0 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!pawn) {
        out->x = 0;
        out->y = 0;
        out->z = 0;
        return out;
    }
    Vec3_26cc0 v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    ((owners::C_35660 *)pawn)->FUN_00035660((int *)(Vec3_26cc0 *)(&v));
    out->x = v.x;
    out->y = v.y;
    out->z = v.z;
    return out;
}

} // namespace fn_f6d645d0

// 0x00026d50 FUN_00026d50 (94 B): equivalent/0x00026d50.cpp [wrapped: conflict: Vec3]
// sym: ?FUN_00026d50@Object@fn_00026d50@@QAEXPAUVec3@2@H@Z @29a370466b56 @we6a7de92ecd8
namespace fn_00026d50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00026d50 @ 0x00026d50
struct Vec3 { unsigned int x, y, z; };
struct Record { char padding[0x1a84]; Vec3 position; };
__int64 __cdecl FUN_002672f0(int key, int a, int b);
struct Object {
    Record* FUN_00024280(__int64 id);
    void FUN_00026d50(Vec3* result, int key);
};
void Object::FUN_00026d50(Vec3* result, int key)
{
    __int64 id = FUN_002672f0(key, 0, 0);
    Record* record = FUN_00024280(id);
    if (record) {
        *result = record->position;
    } else {
        result->x = 0;
        result->y = 0;
        result->z = 0;
    }
}
} // namespace fn_00026d50


// 0x00026db0 FUN_00026db0 (58 B): matches/0x00026db0.cpp [wrapped: conflict: Owner; lookup]
// sym: ?Do@Owner@fn_00026db0@@QAEXPAXM@Z
namespace fn_00026db0 {
extern "C++" __int64 __cdecl lookup_002672f0(void*, int, int);
class Item {
  public:
    void Set_000354e0(float);
};
class Owner {
  public:
    Item* Find_00024280(__int64);
    void Do(void*, float);
};
void Owner::Do(void* name, float angle) {
    __int64 id = lookup_002672f0(name, 0, 0);
    Item* item = Find_00024280(id);
    if (item)
        item->Set_000354e0(angle * 0.017453292519943295f);
}
} // namespace fn_00026db0


// 0x00026df0 FUN_00026df0 (59 B): matches/0x00026df0.cpp [wrapped: conflict: Make]
// sym: ?Fn@X@fn_00026df0@@QAEMH@Z
namespace fn_00026df0 {
// data: deg = DAT_003f3ef4

struct V {
    float Get_000354c0();
};
struct X {
    V* Find_00024280(__int64);
    hulk_freg Fn(int);
};
extern "C++" __int64 __cdecl Make_002672f0(int, int, int);
hulk_freg X::Fn(int x) {
    __int64 a = Make_002672f0(x, 0, 0);
    V* v = Find_00024280(a);
    if (!v)
        return 0.0f;
    return v->Get_000354c0() * DAT_003f3ef4;
}
} // namespace fn_00026df0


// 0x00026e30 FUN_00026e30 (247 B): equivalent/0x00026e30.cpp [wrapped: conflict: Entity]
// sym: ?FUN_00026e30@Target_26e30@fn_00026e30@@QAEHMPAHH@Z @64864c4906b1 @w12b5fe721b6a
namespace fn_00026e30 {
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 24/24)
// FUN_00026e30 @ 0x00026e30
struct Vec_26e30 { float x,y,z; };
struct Position_26e30 { bool FUN_00059a50(Vec_26e30*); };
struct Category { char pad[0x18]; int index; };
struct Entity { char pad[0x10]; Position_26e30* position; char pad2[0x108]; Category* category; };
struct Registry_26e30 {  };
struct Root_26e30 { char pad[0x44]; Registry_26e30* registry; };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

struct Target_26e30 { Root_26e30* root; char pad[8]; int count; int ids[69]; Entity* self; int FUN_00026e30(float radius,int* output,int size); };
int Target_26e30::FUN_00026e30(float radius,int* output,int size) {
 for(int j=0;j<size;++j) output[j]=0;
 int result=0; Vec_26e30 origin;
 if(!self->position->FUN_00059a50(&origin)) return 0;
 for(int i=0;i<count;++i) {
 Entity* e=((Entity *)((owners::ThisWrap_00059c10 *)(root->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
 if(!e || e==self) continue;
 if(radius>0.0f) {
 Vec_26e30 p;
 if(!e->position->FUN_00059a50(&p)) continue;
 double dx=(double)p.x-origin.x, dz=(double)p.z-origin.z;
 if(sqrt(dx*dx+dz*dz)>radius) continue;
 }
 Category* c=e->category;
 if(c && c->index>=0 && c->index<size) ++output[c->index];
 ++result;
 }
 return result;
}
} // namespace fn_00026e30

namespace fn_f6d645d0 {

// 0x00026f30 FUN_00026f30 (122 B): matches/0x00026f30.cpp
// sym: ?FUN_00026f30@Group_26f30@fn_f6d645d0@@QAE_NPBD0@Z
// FUN_00026f30 @ 0x00026f30
// True when the pawn's link carries the given name.
bool Group_26f30::FUN_00026f30(const char *pawnName, const char *linkName)
{
    Pawn_26f30 *pawn = FUN_00024280(FUN_002672f0(pawnName, 0, 0));
    if (!pawn)
        return false;
    Name_26f30 key;
    key.FUN_0027b0e0(linkName);
    Link_26f30 *link = pawn->link;
    if (link && key.lo == link->nameLo && key.hi == link->nameHi) {
        key.FUN_0027af50();
        return true;
    }
    key.FUN_0027af50();
    return false;
}

} // namespace fn_f6d645d0

// 0x00026fb0 FUN_00026fb0 (63 B): matches/0x00026fb0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Func@Obj@fn_00026fb0@@QAEXHH@Z
namespace fn_00026fb0 {
struct Found {
    char pad[0x1ca0];
    struct Inner* inner;
};
struct Inner {
    char pad[0x118];
    void Run_0027b040(int);
};
struct Obj {
    Found* Lookup_00024280(unsigned long long);
    void Func(int, int);
};
extern "C++" unsigned long long __cdecl Search_002672f0(int, int, int);
void Obj::Func(int a, int b) {
    unsigned long long v = Search_002672f0(a, 0, 0);
    Found* f = Lookup_00024280(v);
    if (f && f->inner)
        ((Inner*)((char*)f->inner + 0x118))->Run_0027b040(b);
}
} // namespace fn_00026fb0


// 0x00026ff0 FUN_00026ff0 (59 B): matches/0x00026ff0.cpp [wrapped: conflict: Lookup; Owner]
// sym: ?Run@Owner@fn_00026ff0@@QAEXHH@Z
namespace fn_00026ff0 {
typedef unsigned __int64 U64;
struct Result {
    char pad[0x1ca0];
    struct Thing* thing;
};
struct Thing {
    void Act_000fdcb0(int);
};
U64 __cdecl Lookup_002672f0(int, int, int);
class Owner {
  public:
    Result* Resolve_00024280(U64);
    void Run(int key, int value);
};
void Owner::Run(int key, int value) {
    U64 id = Lookup_002672f0(key, 0, 0);
    Result* r = Resolve_00024280(id);
    if (r && r->thing)
        r->thing->Act_000fdcb0(value);
}
} // namespace fn_00026ff0


// 0x00027030 FUN_00027030 (47 B): matches/0x00027030.cpp [wrapped: conflict: Result]
// sym: ?Set@Obj@fn_00027030@@QAEXPBDH@Z
namespace fn_00027030 {
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

struct Result {
    char pad[0x1d00];
    int value;
};
class Obj {
  public:
    Result* Lookup_00024280(__int64);
    void Set(const char*, int);
};
void Obj::Set(const char* name, int value) {
    __int64 id = FUN_002672f0(name, 0, 0);
    Result* p = Lookup_00024280(id);
    if (p)
        p->value = value;
}
} // namespace fn_00027030
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f6d645d0 {

// 0x00027060 FUN_00027060 (59 B): matches/0x00027060.cpp
// sym: ?work@Owner@fn_f6d645d0@@QAEXPAXH@Z
void Owner::work(void* p, int x) {
    unsigned __int64 k = makeKey_002672f0(p, 0, 0);
    Item* item = find_00024280(k);
    if (item && item->handler)
        ((owners::Config_447b0 *)(item->handler))->FUN_000447b0((const char *)(hulk_uintptr)(int)x);
}

} // namespace fn_f6d645d0

// 0x000270a0 FUN_000270a0 (46 B): matches/0x000270a0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Fn@Owner@fn_000270a0@@QAEHH@Z
namespace fn_000270a0 {
struct Item {
    char pad[0x39c];
    int value;
};
struct Owner {
    Item* Lookup_00024280(__int64);
    int Fn(int);
};
extern "C++" __int64 __cdecl Convert_002672f0(int, int, int);
int Owner::Fn(int x) {
    __int64 k = Convert_002672f0(x, 0, 0);
    Item* p = Lookup_00024280(k);
    if (!p)
        return 0;
    return p->value;
}
} // namespace fn_000270a0


// 0x000270d0 FUN_000270d0 (47 B): matches/0x000270d0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?fn@Obj@fn_000270d0@@QAEXHH@Z
namespace fn_000270d0 {
struct Item {
    char pad[0x39c];
    int value;
};
extern "C++" __int64 __cdecl lookup(int, int, int);
class Obj {
  public:
    Item* get_00024280(__int64);
    void fn(int id, int value);
};
void Obj::fn(int id, int value) {
    __int64 key = lookup(id, 0, 0);
    Item* p = get_00024280(key);
    if (p)
        p->value = value;
}
} // namespace fn_000270d0


// 0x00027100 FUN_00027100 (48 B): matches/0x00027100.cpp [wrapped: conflict: Convert]
// sym: ?Query@Owner@fn_00027100@@QAEEH@Z
namespace fn_00027100 {
struct Item {
    char pad[0x1d4c];
    unsigned char flag;
};
class Owner {
  public:
    Item* Lookup_00024280(unsigned __int64);
    unsigned char Query(int);
};
unsigned __int64 __cdecl Convert_002672f0(int, int, int);
unsigned char Owner::Query(int value) {
    unsigned __int64 key = Convert_002672f0(value, 0, 0);
    Item* item = Lookup_00024280(key);
    if (!item)
        return 0;
    return item->flag;
}
} // namespace fn_00027100

namespace fn_f6d645d0 {

// 0x00027130 FUN_00027130 (33 B): matches/0x00027130.cpp
// sym: ?fn@Obj@fn_f6d645d0@@QAEXHH@Z
void Obj::fn(int x, int y) {
    Pair p = other_002672f0(x, 0, 0);
    use_00024280(p.a, p.b);
}

} // namespace fn_f6d645d0

// 0x00027160 FUN_00027160 (48 B): matches/0x00027160.cpp [wrapped: conflict: Parse]
// sym: ?Check@Obj@fn_00027160@@QAEEH@Z
namespace fn_00027160 {
typedef __int64 I64;
extern "C++" I64 __cdecl Parse_002672f0(int, int, int);
class Obj {
  public:
    void* Lookup_00024280(I64);
    unsigned char Check(int);
};
unsigned char Obj::Check(int x) {
    I64 v = Parse_002672f0(x, 0, 0);
    unsigned char* p = (unsigned char*)Lookup_00024280(v);
    if (!p)
        return 0;
    return p[0x1d4d];
}
} // namespace fn_00027160

namespace fn_f6d645d0 {

// 0x00027190 FUN_00027190 (33 B): matches/0x00027190.cpp
// sym: ?FUN_00027190@X@fn_f6d645d0@@QAEXHH@Z
void X::FUN_00027190(int a, int b) {
    FUN_00024280(FUN_002672f0(a, 0, 0));
}

} // namespace fn_f6d645d0

// 0x000271c0 FUN_000271c0 (61 B): matches/0x000271c0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?fn@Obj@fn_000271c0@@QAEXHPBD@Z
namespace fn_000271c0 {
extern "C++" unsigned __int64 __cdecl resolve_002672f0(int, int, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strcpy(char*, const char*);
#endif

class Obj {
  public:
    char* get_00024280(unsigned int, unsigned int);
    void fn(int, const char*);
};
void Obj::fn(int a, const char* s) {
    unsigned __int64 id = resolve_002672f0(a, 0, 0);
    char* p = get_00024280((unsigned int)id, (unsigned int)(id >> 32));
    if (p)
        strcpy(p + 0x20f8, s);
}
} // namespace fn_000271c0


// 0x00027200 FUN_00027200 (47 B): matches/0x00027200.cpp [wrapped: conflict: Item; Lookup]
// sym: ?Set@Owner@fn_00027200@@QAEXHD@Z
namespace fn_00027200 {
typedef unsigned __int64 U64;
struct Item {
    char pad[0x2138];
    char flag;
};
extern "C++" U64 __cdecl Lookup_002672f0(int, int, int);
class Owner {
  public:
    Item* Find_00024280(U64);
    void Set(int, char);
};
void Owner::Set(int x, char v) {
    U64 key = Lookup_002672f0(x, 0, 0);
    Item* p = Find_00024280(key);
    if (p)
        p->flag = v;
}
} // namespace fn_00027200


// 0x00027230 FUN_00027230 (56 B): matches/0x00027230.cpp [wrapped: conflict: Item]
// sym: ?fn@Obj@fn_00027230@@QAEXPAXE@Z
namespace fn_00027230 {
struct Item {
    char pad[0x213c];
    float value;
};
struct Obj {
    Item* get_00024280(unsigned __int64 x);
    void fn(void* x, unsigned char b);
};
extern "C++" unsigned __int64 __cdecl make_002672f0(void*, int, hulk_intptr);
void Obj::fn(void* x, unsigned char b) {
    Item* p = get_00024280(make_002672f0(x, 0, 0));
    if (p)
        p->value = (float)b;
}
} // namespace fn_00027230

namespace fn_f6d645d0 {

// 0x00027270 FUN_00027270 (48 B): matches/0x00027270.cpp
// sym: ?FUN_00027270@Obj@fn_f6d645d0@@QAEEH@Z
unsigned char Obj::FUN_00027270(int x) {
    __int64 v = FUN_002672f0(x, 0, 0);
    Result* p = FUN_00024280(v);
    if (!p)
        return 0;
    return p->flag;
}

} // namespace fn_f6d645d0

// 0x000272a0 FUN_000272a0 (47 B): matches/0x000272a0.cpp [wrapped: conflict: Item]
// sym: ?get@Obj@fn_000272a0@@QAEPAUItem@2@II@Z
namespace fn_000272a0 {
struct Item {
    char pad[0x2140];
    char flag;
};
class Obj {
  public:
    Item* get(unsigned a, unsigned b);
    Item* lookup_00024280(unsigned lo, unsigned hi);
};
extern "C++" unsigned __int64 __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
Item* Obj::get(unsigned a, unsigned b) {
    unsigned __int64 n = FUN_002672f0(a, 0, 0);
    Item* p = lookup_00024280((unsigned)n, (unsigned)(n >> 32));
    if (p)
        p->flag = (char)b;
    return p;
}
} // namespace fn_000272a0


// 0x000272d0 FUN_000272d0 (47 B): matches/0x000272d0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?Get@Obj@fn_000272d0@@QAEPAUItem@2@II@Z
namespace fn_000272d0 {
struct Item {
    char pad[0x394];
    int field;
};
struct Obj {
    Item* Find_00024280(__int64 v);
    Item* Get(unsigned a, unsigned b);
};
extern "C++" __int64 __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
Item* Obj::Get(unsigned a, unsigned b) {
    __int64 v = FUN_002672f0(a, 0, 0);
    Item* p = Find_00024280(v);
    if (p)
        p->field = b;
    return p;
}
} // namespace fn_000272d0


// 0x00027300 FUN_00027300 (47 B): matches/0x00027300.cpp [wrapped: conflict: Result]
// sym: ?assign@Obj@fn_00027300@@QAEXHH@Z
namespace fn_00027300 {
struct Result {
    char pad[0x1d48];
    int value;
};
struct Obj {
    Result* setPair_00024280(int a, int b);
    void assign(int a, int b);
};
extern "C++" unsigned __int64 __cdecl makePair_002672f0(int a, int b, int c);
void Obj::assign(int a, int b) {
    unsigned __int64 v = makePair_002672f0(a, 0, 0);
    Result* p = setPair_00024280((int)v, (int)(v >> 32));
    if (p)
        p->value = b;
}
} // namespace fn_00027300


// 0x00027370 FUN_00027370 (47 B): matches/0x00027370.cpp [wrapped: conflict: Item]
// sym: ?Func@Obj@fn_00027370@@QAEXPADH@Z
namespace fn_00027370 {
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

struct Item {
    char pad[0x1cfc];
    int value;
};
struct Obj {
    Item* Set_00024280(unsigned long long v);
    void Func(char* name, int val);
};
void Obj::Func(char* name, int val) {
    unsigned long long v = FUN_002672f0(name, 0, 0);
    Item* p = Set_00024280(v);
    if (p)
        p->value = val;
}
} // namespace fn_00027370
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000273a0 FUN_000273a0 (47 B): matches/0x000273a0.cpp [wrapped: compile error C2666: 'FUN_002672f0' : 2 overloads have similar conversions]
// sym: ?Set@C@fn_000273a0@@QAEXIH@Z
namespace fn_000273a0 {
struct Obj {
    char pad[0x1cf8];
    int value;
};
class C {
  public:
    Obj* Get_00024280(unsigned, unsigned);
    void Set(unsigned id, int v);
};
extern "C++" unsigned __int64 __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
void C::Set(unsigned id, int v) {
    unsigned __int64 x = FUN_002672f0(id, 0, 0);
    Obj* p = Get_00024280((unsigned)x, (unsigned)(x >> 32));
    if (p)
        p->value = v;
}
} // namespace fn_000273a0

namespace fn_f6d645d0 {

// 0x000273d0 FUN_000273d0 (47 B): matches/0x000273d0.cpp
// sym: ?get@X@fn_f6d645d0@@QAEPAVObj@2@II@Z
Obj* X::get(unsigned a, unsigned b) {
    unsigned __int64 n = source_002672f0(a, 0, 0);
    Obj* p = FUN_00024280(n);
    if (p)
        p->value = b;
    return p;
}

} // namespace fn_f6d645d0

// 0x00027400 FUN_00027400 (47 B): matches/0x00027400.cpp [wrapped: conflict: Item]
// sym: ?fn@Obj@fn_00027400@@QAEXHH@Z
namespace fn_00027400 {
struct Item {
    char pad[0x1d18];
    int value;
};
struct Obj {
    Item* get_00024280(unsigned a, unsigned b);
    void fn(int x, int y);
};
extern "C++" unsigned __int64 __cdecl decode_002672f0(int, int, int);
void Obj::fn(int x, int y) {
    unsigned __int64 n = decode_002672f0(x, 0, 0);
    Item* p = get_00024280((unsigned)n, (unsigned)(n >> 32));
    if (p)
        p->value = y;
}
} // namespace fn_00027400


// 0x00027430 FUN_00027430 (47 B): matches/0x00027430.cpp [wrapped: conflict: Item]
// sym: ?set@Obj@fn_00027430@@QAEXHH@Z
namespace fn_00027430 {
struct Item {
    char pad[0x1d1c];
    int value;
};
struct Obj {
    Item* get_00024280(unsigned __int64 x);
    void set(int a, int b);
};
extern "C++" unsigned __int64 __cdecl make64_002672f0(int a, int b, int c);
void Obj::set(int a, int b) {
    unsigned __int64 x = make64_002672f0(a, 0, 0);
    Item* p = get_00024280(x);
    if (p)
        p->value = b;
}
} // namespace fn_00027430


// 0x00027460 FUN_00027460 (47 B): matches/0x00027460.cpp [wrapped: conflict: Result; convert]
// sym: ?set@X@fn_00027460@@QAEXHH@Z
namespace fn_00027460 {
struct Result {
    char pad[0x1d20];
    int value;
};
struct X {
    Result* lookup_00024280(__int64);
    void set(int a, int b);
};
extern "C++" __int64 __cdecl convert_002672f0(int, int, int);
void X::set(int a, int b) {
    __int64 v = convert_002672f0(a, 0, 0);
    Result* r = lookup_00024280(v);
    if (r)
        r->value = b;
}
} // namespace fn_00027460


// 0x00027490 FUN_00027490 (47 B): matches/0x00027490.cpp [wrapped: conflict: Convert; Item]
// sym: ?Set@Obj@fn_00027490@@QAEXHH@Z
namespace fn_00027490 {
struct Item {
    char pad[0x1d24];
    int value;
};
struct Obj {
    Item* Find_00024280(unsigned long long x);
    void Set(int id, int val);
};
extern "C++" unsigned long long __cdecl Convert_002672f0(int x, int a, int b);
void Obj::Set(int id, int val) {
    unsigned long long k = Convert_002672f0(id, 0, 0);
    Item* p = Find_00024280(k);
    if (p)
        p->value = val;
}
} // namespace fn_00027490


// 0x000274c0 FUN_000274c0 (48 B): matches/0x000274c0.cpp [wrapped: conflict: fetch]
// sym: ?fn@Obj@fn_000274c0@@QAEEH@Z
namespace fn_000274c0 {
struct Result {
    char pad[0x1d05];
    unsigned char val;
};
class Obj {
  public:
    Result* lookup_00024280(int, int);
    unsigned char fn(int);
};
extern "C++" unsigned __int64 __cdecl fetch_002672f0(int, int, int);
unsigned char Obj::fn(int x) {
    unsigned __int64 v = fetch_002672f0(x, 0, 0);
    Result* p = lookup_00024280((int)v, (int)(v >> 32));
    if (!p)
        return 1;
    return p->val;
}
} // namespace fn_000274c0


// 0x000274f0 FUN_000274f0 (47 B): matches/0x000274f0.cpp [wrapped: conflict: Item]
// sym: ?Set@Obj@fn_000274f0@@QAEXHE@Z
namespace fn_000274f0 {
struct Item {
    char pad[0x1d05];
    char flag;
};
struct Obj {
    Item* Get_00024280(unsigned long long x);
    void Set(int a, unsigned char b);
};
extern "C++" unsigned long long __cdecl Make(int, int, int);
void Obj::Set(int a, unsigned char b) {
    unsigned long long x = Make(a, 0, 0);
    Item* p = Get_00024280(x);
    if (p)
        p->flag = b;
}
} // namespace fn_000274f0


// 0x00027520 FUN_00027520 (47 B): matches/0x00027520.cpp [wrapped: conflict: FUN_002672f0; Result]
// sym: ?func@Obj@fn_00027520@@QAEXHH@Z
namespace fn_00027520 {
struct Result {
    char pad[0x1d08];
    int value;
};
struct Obj {
    Result* get_00024280(int, int);
    void func(int a, int b);
};
extern "C++" unsigned __int64 __cdecl FUN_002672f0(int, int, int);
void Obj::func(int a, int b) {
    unsigned __int64 x = FUN_002672f0(a, 0, 0);
    Result* r = get_00024280((int)x, (int)(x >> 32));
    if (r)
        r->value = b;
}
} // namespace fn_00027520


// 0x00027550 FUN_00027550 (52 B): matches/0x00027550.cpp [wrapped: conflict: Find; Item]
// sym: ?Func@Obj@fn_00027550@@QAEMI@Z
namespace fn_00027550 {
extern "C++" unsigned __int64 __cdecl Find_002672f0(unsigned int, int, int);
struct Item {
    char pad[0x1d20];
    float value;
};
class Obj {
  public:
    Item* Get_00024280(unsigned __int64);
    float Func(unsigned int);
};
float Obj::Func(unsigned int id) {
    unsigned __int64 v = Find_002672f0(id, 0, 0);
    Item* p = Get_00024280(v);
    if (!p)
        return 1.0f;
    return p->value;
}
} // namespace fn_00027550


// 0x00027590 FUN_00027590 (52 B): matches/0x00027590.cpp [wrapped: conflict: Lookup; Obj]
// sym: ?Get@C@fn_00027590@@QAEMH@Z
namespace fn_00027590 {
struct Obj {
    char pad[0x1d24];
    float value;
};
class C {
  public:
    Obj* Find_00024280(int lo, int hi);
    float Get(int id);
};
struct Pair {
    int lo, hi;
};
Pair __cdecl Lookup_002672f0(int id, int a, int b);
float C::Get(int id) {
    Pair p = Lookup_002672f0(id, 0, 0);
    Obj* o = Find_00024280(p.lo, p.hi);
    if (!o)
        return 1.0f;
    return o->value;
}
} // namespace fn_00027590


// 0x000275d0 FUN_000275d0 (47 B): matches/0x000275d0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?set@C@fn_000275d0@@QAEXPADE@Z
namespace fn_000275d0 {
struct Obj {
    char pad[0x1d28];
    unsigned char flag;
};
class C {
  public:
    Obj* lookup_00024280(unsigned int lo, unsigned int hi);
    void set(char* name, unsigned char v);
};
extern "C++" unsigned __int64 __cdecl hash_002672f0(char*, int, int);
void C::set(char* name, unsigned char v) {
    unsigned __int64 id = hash_002672f0(name, 0, 0);
    Obj* p = lookup_00024280((unsigned int)id, (unsigned int)(id >> 32));
    if (p)
        p->flag = v;
}
} // namespace fn_000275d0


// 0x00027600 FUN_00027600 (48 B): matches/0x00027600.cpp [wrapped: conflict: Lookup; Obj]
// sym: ?Test@C@fn_00027600@@QAEEH@Z
namespace fn_00027600 {
struct Obj {
    char pad[0x1d28];
    unsigned char flag;
};
class C {
  public:
    Obj* Find_00024280(unsigned int a, unsigned int b);
    unsigned char Test(int x);
};
extern "C++" unsigned __int64 __cdecl Lookup_002672f0(int x, int a, int b);
unsigned char C::Test(int x) {
    unsigned __int64 v = Lookup_002672f0(x, 0, 0);
    Obj* p = Find_00024280((unsigned int)v, (unsigned int)(v >> 32));
    if (!p)
        return 1;
    return p->flag;
}
} // namespace fn_00027600


// 0x00027670 FUN_00027670 (64 B): matches/0x00027670.cpp [wrapped: conflict: Obj; Result]
// sym: ?fn@Obj@fn_00027670@@QAEXHH@Z
namespace fn_00027670 {
struct Result {
    char pad[0x1b40];
    unsigned long long value;
};
struct Obj {
    Result* get_00024280(unsigned long long);
    void fn(int, int);
};
extern "C++" unsigned long long __cdecl first_002672f0(int, int, int);
extern "C++" unsigned long long __cdecl second_0027afb0(int);
void Obj::fn(int x, int y) {
    unsigned long long a = first_002672f0(x, 0, 0);
    Result* r = get_00024280(a);
    if (r)
        r->value = second_0027afb0(y);
}
} // namespace fn_00027670

namespace fn_f6d645d0 {

// 0x000276b0 FUN_000276b0 (57 B): matches/0x000276b0.cpp
// sym: ?run@Obj@fn_f6d645d0@@QAEXPAXH@Z
void Obj::run(void* p, int unused) {
    U64 v = lookup_002672f0(p, 0, 0);
    Result* r = get_00024280(v);
    if (r) {
        r->a = 0;
        r->b = 0;
    }
}


// 0x000276f0 FUN_000276f0 (59 B): matches/0x000276f0.cpp
// sym: ?Func@Obj@fn_f6d645d0@@QAEXHH@Z
void Obj::Func(int id, int value) {
    __int64 key = Convert(id, 0, 0);
    Item* item = Find_00024280(key);
    if (item && item->handler)
        ((owners::Config_447b0 *)(item->handler))->FUN_000447b0((const char *)(hulk_uintptr)(int)value);
}

} // namespace fn_f6d645d0

// 0x00027730 FUN_00027730 (281 B): equivalent/0x00027730.cpp [wrapped: conflict: Object]
// sym: ?FUN_00027730@Object@fn_00027730@@QAE_NPADPBD@Z @a60f8e0884be @w0dc82de9904e
namespace fn_00027730 {
// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 22/22)
// FUN_00027730 @ 0x00027730

struct Key_27730 { unsigned first, second; void FUN_0027af00();  };
extern void __cdecl FUN_00363b00();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern int __cdecl _atexit(void (__cdecl*)());
#endif

struct Entry_27730 { unsigned first, second; unsigned char flag; char pad[7]; };
struct Object { char pad[0x380]; Entry_27730 entries[32]; int count; bool FUN_00027730(char* destination, const char* source); };
bool Object::FUN_00027730(char* destination, const char* source) {
 if (!((*(unsigned*)&DAT_004dc0f0) & 1)) { (*(unsigned*)&DAT_004dc0f0) |= 1; (*(Key_27730*)&DAT_004dc0e8).FUN_0027af00(); _atexit(FUN_00363b00); }
 if (!destination || !source) return false;
 const char* end=source; while (*end++) {}
 char* out=destination; while (*out) ++out;
 unsigned length=(unsigned)(end-source);
 for(unsigned j=0;j<length;++j) out[j]=source[j];
 ((owners::Target_27b040 *)&((*(Key_27730*)&DAT_004dc0e8)))->FUN_0027b040((hulk_uintptr)destination);
 int oldCount=count;
 if(oldCount>0) { unsigned a=(*(Key_27730*)&DAT_004dc0e8).first,b=(*(Key_27730*)&DAT_004dc0e8).second; for(int i=0;i<count;++i) if(entries[i].first==a && entries[i].second==b) return entries[i].flag==0; }
 int next=oldCount+1;
 if(next<32) { count=next; entries[next].flag=0; entries[count].first=(*(Key_27730*)&DAT_004dc0e8).first; entries[count].second=(*(Key_27730*)&DAT_004dc0e8).second; }
 return true;
}
} // namespace fn_00027730


// 0x00027850 FUN_00027850 (221 B): equivalent/0x00027850.cpp [wrapped: conflict: Object]
// sym: ?FUN_00027850@Object@fn_00027850@@QAE_NPADPBD@Z @1a1ecdf230e9 @w7e5d9253aa97
namespace fn_00027850 {
// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 20/20)
// FUN_00027850 @ 0x00027850

struct Key_27850 { unsigned int first; unsigned int second; void FUN_0027af00();  };
extern void __cdecl FUN_00363b10();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern int __cdecl _atexit(void (__cdecl*)());
#endif

struct Entry_27850 { unsigned int first, second; unsigned char enabled; char pad[7]; };
struct Object { char pad[0x380]; Entry_27850 entries[32]; int count; bool FUN_00027850(char* destination, const char* source); };
bool Object::FUN_00027850(char* destination, const char* source) {
 if (!((*(unsigned int*)&DAT_004dc100) & 1)) { (*(unsigned int*)&DAT_004dc100) |= 1; (*(Key_27850*)&DAT_004dc0f8).FUN_0027af00(); _atexit(FUN_00363b10); }
 if (!destination || !source) return false;
 const char* end = source; while (*end) ++end;
 unsigned int length = (unsigned int)(end-source)+1;
 char* append = destination; while (*append) ++append;
 unsigned int words=length/4;
 unsigned int* out=(unsigned int*)append;
 const unsigned int* in=(const unsigned int*)source;
 for(unsigned int j=0;j<words;++j) out[j]=in[j];
 char* tail=append+words*4; const char* rest=source+words*4;
 for(unsigned int k=0;k<(length&3);++k) tail[k]=rest[k];
 ((owners::Target_27b040 *)&((*(Key_27850*)&DAT_004dc0f8)))->FUN_0027b040((hulk_uintptr)destination);
 for(int i=0;i<count;++i) { if(entries[i].first==(*(Key_27850*)&DAT_004dc0f8).first && entries[i].second==(*(Key_27850*)&DAT_004dc0f8).second) return entries[i].enabled != 0; }
 return false;
}
} // namespace fn_00027850


// 0x00027a50 FUN_00027a50 (253 B): equivalent/0x00027a50.cpp [wrapped: conflict: Object; memmove]
// sym: ?FUN_00027a50@Object@fn_00027a50@@QAE_NPADPBD@Z @55d1c7d84538 @wb1f98e532e12
namespace fn_00027a50 {
// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 18/18)
// FUN_00027a50 @ 0x00027a50

struct Key_27a50 { unsigned int first, second; void FUN_0027af00();  };
extern void __cdecl FUN_00363b30();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern int __cdecl atexit(void (__cdecl*)());
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern void* __cdecl memmove(void*, const void*, unsigned int);
#endif

struct Entry_27a50 { unsigned int first, second; char rest[8]; };
struct Object { char pad[0x380]; Entry_27a50 entries[32]; int count; bool FUN_00027a50(char* destination, const char* suffix); };
bool Object::FUN_00027a50(char* destination, const char* suffix) {
 if (!((*(unsigned int*)&DAT_004dc120) & 1)) { (*(unsigned int*)&DAT_004dc120) |= 1; (*(Key_27a50*)&DAT_004dc118).FUN_0027af00(); atexit(FUN_00363b30); }
 if (!destination || !suffix) return false;
 unsigned int length=0; do { ++length; } while(suffix[length-1]);
 char* end=destination; while(*end) ++end;
 for(unsigned int j=0;j<length;++j) end[j]=suffix[j];
 ((owners::Target_27b040 *)&((*(Key_27a50*)&DAT_004dc118)))->FUN_0027b040((hulk_uintptr)destination);
 int oldCount=count;
 if(oldCount>0) {
 unsigned int first=(*(Key_27a50*)&DAT_004dc118).first, second=(*(Key_27a50*)&DAT_004dc118).second;
 for(int i=0;i<count;++i) { if(entries[i].first==first && entries[i].second==second) {
 count=oldCount-1;
 memmove(&entries[i], &entries[i+1], (count-i)*16);
 return true;
 } }
 }
 return false;
}
} // namespace fn_00027a50

namespace fn_f6d645d0 {

// 0x00027b50 FUN_00027b50 (305 B): equivalent/0x00027b50.cpp
// sym: ?FUN_00027b50@Table_27b50@fn_f6d645d0@@QAEXPBDMHMHH0@Z @bf63e7a8c432 @wbc31f73010cc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00027b50 @ 0x00027b50
void Table_27b50::FUN_00027b50(const char *name, float a1, int a2, float a3, int a4, int a5, const char *s) {
    Obj_27b50 *o = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (o) {
        Frame_27b50 f;
        o->FUN_00035550(&f.v);
        f.v.y = 0.0f;
        FUN_00224d70(3.1415927f, &f.v);
        f.d.FUN_00059820();
        f.d.f74 = 2;
        o->sub->FUN_00059a50(&f.d.pos);
        f.d.dir = f.v;
        unsigned __int64 id = FUN_0027b020(s);
        f.d.idLo = (unsigned int)id;
        f.d.idHi = (unsigned int)(id >> 32);
        f.d.f68 = a5;
        f.d.f54 = 0x7fffffff;
        f.d.f24 = 1;
        f.d.f58 = a1;
        if (a3 <= 0.0f) {
            a3 = a1;
        }
        f.d.FUN_000595f0(&f.v, a2, a3, a4);
        o->FUN_000437a0(0, &f.d, 0, 0, 0);
        f.d.FUN_00059300();
    }
}


// 0x00027c90 FUN_00027c90 (202 B): equivalent/0x00027c90.cpp
// sym: ?FUN_00027c90@Group_27c90@fn_f6d645d0@@QAEXPBD0@Z @1d2919b90126 @wea532214aee6
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 12/12)
// FUN_00027c90 @ 0x00027c90
// Group method: look up a named pawn and a node by path, then register the pawn's slot with it.
void Group_27c90::FUN_00027c90(const char *name, const char *path)
{
    Pawn2 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!pawn)
        return;
    if (!path)
        return;
    const char *keyName = (*(const char**)&DAT_0048e060);
    Registry_27c90 *registry = (*(Registry_27c90**)&DAT_004e5af8);
    Found_27c90 *found = registry->FUN_00232840(FUN_002672f0(keyName, 0, 0))->tree->FUN_00233580(path);
    if (!found)
        return;
    int arg = pawn->arg;
    Node *node = (Node *)FUN_00344e74(found, 0, &DAT_0048e090, &DAT_0048e0ac, 0);
    if (!node) {
        node = found->Resolve(arg, 0);
        if (!node)
            return;
    }
    Flags_27c90 *f = ((Flags_27c90 *)((owners::Obj_36a80 *)pawn)->FUN_00036a80(1));
    if (f)
        f->flag = 1;
    node->FUN_00231ad0(pawn->slot, arg, 0x80000000);
}


// 0x00027d60 FUN_00027d60 (202 B): equivalent/0x00027d60.cpp
// sym: ?FUN_00027d60@Group_27d60@fn_f6d645d0@@QAEXPBD0@Z @bc7e75c3d644 @w924288d8ebf9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00027d60 @ 0x00027d60
// Group method: look up a named pawn and a bank/node by path, then register the pawn's slot with it.
void Group_27d60::FUN_00027d60(const char *name, const char *path)
{
    Pawn_27d60 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!pawn)
        return;
    if (!path)
        return;
    const char *keyName = (*(const char**)&DAT_0048e064);
    Registry_27d60 *registry = (*(Registry_27d60**)&DAT_004e5af8);
    Found_27d60 *found = registry->FUN_00232840(FUN_002672f0(keyName, 0, 0))->tree->FUN_00233580(path);
    if (!found)
        return;
    int arg = pawn->arg;
    Node *node = (Node *)FUN_00344e74(found, 0, &DAT_0048e090, &DAT_0048e0ac, 0);
    if (!node) {
        Found_27d60 *bank = (Found_27d60 *)FUN_00344e74(found, 0, &DAT_0048e090, &DAT_0048e0c8, 0);
        if (!bank)
            return;
        node = bank->Resolve(arg, 0);
        if (!node)
            return;
    }
    node->FUN_00231ad0(pawn->slot, arg, 0x80000000);
}

} // namespace fn_f6d645d0

// 0x00027e30 FUN_00027e30 (208 B): equivalent/0x00027e30.cpp [wrapped: conflict: FUN_00344e74]
// sym: ?FUN_00027e30@Target_27e30@fn_00027e30@@QAE_NPBD0@Z @ea544ad17d9d @wa1c98e182150
namespace fn_00027e30 {
// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 23/24, incomplete)
// FUN_00027e30 @ 0x00027e30
// Does the named pawn's current item match the item at `path` (or the item with that name hash)?
// Variant of 0x00027f00 that rejects the pawn's excluded item first.
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

typedef unsigned __int64 Key_27e30;
struct Item_27e30 { char pad[8]; unsigned low; unsigned high; };
struct Handle_27e30 { Item_27e30* item; bool FUN_00231ee0(); };
struct Object { char pad[0xdc]; Handle_27e30 handle; char pad0e0[0x108 - 0xe0]; Item_27e30* excluded; };
struct Root_27e30 { void* FUN_00233580(const char* path); };
struct Context { char pad[0x5c]; Root_27e30* root; };
struct Manager_27e30 {  };
extern char DAT_0048e090;
extern char DAT_0048e0ac;
extern Item_27e30* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct Target_27e30 {
 Object* FUN_00024280(Key_27e30 key);
 bool FUN_00027e30(const char* name, const char* path);
};
bool Target_27e30::FUN_00027e30(const char* name, const char* path) {
 if (!path) return false;
 Key_27e30 key = FUN_002672f0(name,0,0);
 Object* object = FUN_00024280(key);
 if (!object) return false;
 Handle_27e30* handle = &object->handle;
 if (!handle) return false;
 Item_27e30* item = handle->item;
 if (!item) return false;
 if (!handle->FUN_00231ee0()) return false;
 if (item == object->excluded) return false;
 if (path[0] == '/') {
 Context* context = ((Context *)((owners::Obj_240b0 *)((*(Manager_27e30**)&DAT_004e5af8)))->FUN_000240b0((hulk_intptr)((*(void**)&DAT_0048e060))));
 void* found = context->root->FUN_00233580(path);
 if (!found) return false;
 Item_27e30* result = FUN_00344e74(found,0,&DAT_0048e090,&DAT_0048e0ac,0);
 if (!result) return false;
 return result == item;
 }
 Key_27e30 other = FUN_0027b020(path);
 return item->low == (unsigned)other && item->high == (unsigned)(other >> 32);
}
} // namespace fn_00027e30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00027f00 FUN_00027f00 (187 B): equivalent/0x00027f00.cpp [wrapped: conflict: Context; FUN_00344e74; Object]
// sym: ?FUN_00027f00@Target_27f00@fn_00027f00@@QAE_NPBD0@Z @8fe9dc43a0f7 @w7d33622482ea
namespace fn_00027f00 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 21/22, incomplete)
// FUN_00027f00 @ 0x00027f00
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

typedef unsigned __int64 Key_27f00;
struct Item_27f00 { char pad[8]; unsigned low; unsigned high; };
struct Handle_27f00 { Item_27f00* item; bool FUN_00231ee0(); };
struct Object { char pad[0xdc]; Handle_27f00 handle; };
struct Root_27f00 { void* FUN_00233580(const char* path); };
struct Context { char pad[0x5c]; Root_27f00* root; };
struct Manager_27f00 {  };
extern char DAT_0048e090;
extern char DAT_0048e0ac;
extern Item_27f00* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct Target_27f00 {
 Object* FUN_00024280(Key_27f00 key);
 bool FUN_00027f00(const char* name, const char* path);
};
bool Target_27f00::FUN_00027f00(const char* name, const char* path) {
 if (!path) return false;
 Key_27f00 key = FUN_002672f0(name,0,0);
 Object* object = FUN_00024280(key);
 if (!object) return false;
 Handle_27f00* handle = &object->handle;
 if (!handle) return false;
 Item_27f00* item = handle->item;
 if (!item) return false;
 if (!handle->FUN_00231ee0()) return false;
 if (path[0] == '/') {
 Context* context = ((Context *)((owners::Obj_240b0 *)((*(Manager_27f00**)&DAT_004e5af8)))->FUN_000240b0((hulk_intptr)((*(void**)&DAT_0048e060))));
 void* found = context->root->FUN_00233580(path);
 if (!found) return false;
 Item_27f00* result = FUN_00344e74(found,0,&DAT_0048e090,&DAT_0048e0ac,0);
 if (!result) return false;
 return result == item;
 }
 Key_27f00 other = FUN_0027b020(path);
 return item->low == (unsigned)other && item->high == (unsigned)(other >> 32);
}
} // namespace fn_00027f00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00027fc0 FUN_00027fc0 (137 B): equivalent/0x00027fc0.cpp [wrapped: conflict: FUN_002672f0; Object]
// sym: ?FUN_00027fc0@Owner_27fc0@fn_00027fc0@@QAE_NII@Z @4116de80d4b5 @w3a7a90d23258
namespace fn_00027fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 17/18, incomplete)
// FUN_00027fc0 @ 0x00027fc0

typedef unsigned __int64 Key_27fc0;
extern Key_27fc0 __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
struct Node { char pad[0x14]; Node* next; };
struct Handle_27fc0 { Node* node; bool FUN_00231ee0(); };
struct Object { char pad[0xdc]; Handle_27fc0 handle; };
struct Lookup_27fc0 { Node* FUN_00233580(unsigned); };
struct Result_27fc0 { char pad[0x5c]; Lookup_27fc0* lookup; };
struct Manager_27fc0 {  };
struct Owner_27fc0 { Object* FUN_00024280(Key_27fc0); bool FUN_00027fc0(hulk_uintptr key, hulk_uintptr name); };
bool Owner_27fc0::FUN_00027fc0(hulk_uintptr key, hulk_uintptr name) {
 if (!name) return false;
 Object* object = FUN_00024280(FUN_002672f0(key, 0, 0));
 if (!object) return false;
 Handle_27fc0* handle = &object->handle;
 if (!handle) return false;
 Node* node = handle->node;
 if (!node || !handle->FUN_00231ee0()) return false;
 Result_27fc0* result = ((Result_27fc0 *)((owners::Obj_240b0 *)((*(Manager_27fc0**)&DAT_004e5af8)))->FUN_000240b0((hulk_intptr)((*(hulk_uintptr*)&DAT_0048e060))));
 Node* target = result->lookup->FUN_00233580(name);
 if (!target) return false;
 for (Node* p = node->next; p; p = p->next) {
  if (p == target) return true;
 }
 return false;
}
} // namespace fn_00027fc0

namespace fn_f6d645d0 {

// 0x00028050 FUN_00028050 (137 B): equivalent/0x00028050.cpp
// sym: ?FUN_00028050@Object@fn_f6d645d0@@QAE_NPBD0@Z @39bf2c3ab959 @w313e6e44a853
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 17/18, incomplete)
// FUN_00028050 @ 0x00028050
bool Object::FUN_00028050(const char* name, const char* ancestor) {
 if (!ancestor) return false;
 Key_28050 key = FUN_002672f0(name, 0, 0);
 Entry_28050* entry = FUN_00024280(key);
 if (!entry) return false;
 Handle_28050* handle = &entry->handle;
 if (!handle) return false;
 Node* node = handle->node;
 if (!node || !handle->FUN_00231ee0()) return false;
 Context* context = ((Context *)((owners::Obj_240b0 *)((*(Manager_28050**)&DAT_004e5af8)))->FUN_000240b0((hulk_intptr)((*(hulk_uintptr*)&DAT_0048e064))));
 Node* target = context->tree->FUN_00233580(ancestor);
 if (!target) return false;
 for (Node* parent = node->parent; parent; parent = parent->parent) {
  if (parent == target) return true;
 }
 return false;
}

} // namespace fn_f6d645d0

// 0x000280e0 FUN_000280e0 (72 B): matches/0x000280e0.cpp [wrapped: conflict: Find]
// sym: ?Test@Host@fn_000280e0@@QAEDPAX@Z
namespace fn_000280e0 {
struct Sub {
    char f[0xdc];
};
struct Obj {
    char pad[0x338];
    void* p;
};
extern "C++" unsigned __int64 __cdecl Find_002672f0(void*, int, int);
class Host {
  public:
    Obj* Get_00024280(unsigned __int64);
    char Test(void*);
};
char Host::Test(void* x) {
    unsigned __int64 n = Find_002672f0(x, 0, 0);
    Obj* p = Get_00024280(n);
    if (!p)
        return 0;
    if (p->p)
        return 1;
    Sub* q = (Sub*)((char*)p + 0xdc);
    if (!q)
        return 0;
    return ((char)((owners::C_231ee0 *)q)->FUN_00231ee0());
}
} // namespace fn_000280e0


// 0x00028130 FUN_00028130 (68 B): matches/0x00028130.cpp [wrapped: conflict: lookup]
// sym: ?set@Manager@fn_00028130@@QAE_NHH@Z
namespace fn_00028130 {
struct Pair {
    int a, b;
};
extern "C++" Pair __cdecl lookup_002672f0(int, int, int);
struct Item {
    char pad[0x20a8];
    int index;
};
class Manager {
  public:
    Item* find_00024280(int, int);
    bool set(int key, int index);
};
bool Manager::set(int key, int index) {
    if (index < -1 || index >= 5)
        return false;
    Pair p = lookup_002672f0(key, 0, 0);
    Item* item = find_00024280(p.a, p.b);
    if (!item)
        return false;
    item->index = index;
    return true;
}
} // namespace fn_00028130


// 0x00028180 FUN_00028180 (84 B): matches/0x00028180.cpp [wrapped: conflict: Owner; Owner::Run]
// sym: ?Run@Owner@fn_00028180@@QAEDH@Z
namespace fn_00028180 {
struct Part {
    void Clear_00232240();
};
struct Item {
    char a[0xb4];
    Part p;
    char b[0x27];
    Part q;
    void Done_00037000();
    Part* GetP() { return this ? &p : 0; }
    Part* GetQ() { return this ? &q : 0; }
};
struct Owner {
  public:
    Item* Find_00024280(__int64);
    char Run(int);
};
extern "C++" __int64 __cdecl Lookup(int, int, int);
char Owner::Run(int x) {
    __int64 id = Lookup(x, 0, 0);
    Item* i = Find_00024280(id);
    if (!i)
        return 0;
    Part* q = i->GetQ();
    if (q)
        q->Clear_00232240();
    Part* p = i->GetP();
    if (p)
        p->Clear_00232240();
    i->Done_00037000();
    return 1;
}
} // namespace fn_00028180


// 0x000281e0 FUN_000281e0 (54 B): matches/0x000281e0.cpp [wrapped: conflict: Obj]
// sym: ?Set@Owner@fn_000281e0@@QAEEPBDE@Z
namespace fn_000281e0 {
struct Obj {
    char pad[0x1b91];
    unsigned char flag;
};
struct Owner {
    Obj* get_00024280(unsigned long long);

  public:
    unsigned char Set(const char*, unsigned char);
};
extern "C++" unsigned long long __cdecl Parse_002672f0(const char*, int, int);
unsigned char Owner::Set(const char* s, unsigned char v) {
    unsigned long long id = Parse_002672f0(s, 0, 0);
    Obj* p = get_00024280(id);
    if (!p)
        return 0;
    p->flag = v;
    return 1;
}
} // namespace fn_000281e0


// 0x00028220 FUN_00028220 (54 B): matches/0x00028220.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Set@Obj@fn_00028220@@QAEDHD@Z
namespace fn_00028220 {
typedef unsigned __int64 U64;
extern "C++" U64 __cdecl MakeId_002672f0(int, int, int);
struct Entry {
    char pad[0x1cef];
    char flag;
};
class Obj {
  public:
    Entry* Lookup_00024280(U64);
    char Set(int id, char value);
};
char Obj::Set(int id, char value) {
    Entry* e = Lookup_00024280(MakeId_002672f0(id, 0, 0));
    if (!e)
        return 0;
    e->flag = value;
    return 1;
}
} // namespace fn_00028220


// 0x00028260 FUN_00028260 (46 B): matches/0x00028260.cpp [wrapped: conflict: Obj]
// sym: ?Get@Thing@fn_00028260@@QAEHH@Z
namespace fn_00028260 {
struct Obj {
    char pad[0x20a8];
    int value;
};
struct Thing {
    int Get(int);
    Obj* Find_00024280(__int64);
};
extern "C++" __int64 __cdecl FUN_002672f0(int, int, int);
int Thing::Get(int a) {
    __int64 v = FUN_002672f0(a, 0, 0);
    Obj* p = Find_00024280(v);
    if (!p)
        return 0;
    return p->value;
}
} // namespace fn_00028260


// 0x00028290 FUN_00028290 (94 B): equivalent/0x00028290.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?FUN_00028290@Context@fn_00028290@@QAE_NHH@Z @511c2a632203 @w853cc6029d0d
namespace fn_00028290 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00028290 @ 0x00028290
typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(int value, int a, int b);
U64 __cdecl FUN_0027b020(int value);
struct ItemOwner {
    U64 FUN_000443c0();
};
struct Item {
    char padding[0x11c];
    ItemOwner *owner;
};
struct Context {
    Item *FUN_00024280(U64 key);
    bool FUN_00028290(int first, int second);
};
bool Context::FUN_00028290(int first, int second) {
    U64 key = FUN_002672f0(first, 0, 0);
    Item *item = FUN_00024280(key);
    if (!item || !item->owner) return false;
    U64 ownerKey = item->owner->FUN_000443c0();
    return ownerKey == FUN_0027b020(second);
}
} // namespace fn_00028290


// 0x000282f0 FUN_000282f0 (54 B): matches/0x000282f0.cpp [wrapped: conflict: Obj]
// sym: ?Run@Obj@fn_000282f0@@QAEDHH@Z
namespace fn_000282f0 {
class Result {
  public:
};
class Obj {
  public:
    Result* Find_00024280(__int64);
    char Run(int a, int b);
};
extern "C++" __int64 __cdecl Convert(int, int, int);
char Obj::Run(int a, int b) {
    __int64 v = Convert(a, 0, 0);
    Result* r = Find_00024280(v);
    if (!r)
        return 0;
    return ((char)((owners::A_36950 *)r)->FUN_00036950(b));
}
} // namespace fn_000282f0

namespace fn_f6d645d0 {

// 0x00028330 FUN_00028330 (202 B): equivalent/0x00028330.cpp
// sym: ?FUN_00028330@Group_28330@fn_f6d645d0@@QAE_NPBDMM@Z @870a65079c17 @w2d904896cded
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 6/6)
// FUN_00028330 @ 0x00028330
// Group method: is the named pawn's ground position in front of the given heading, within the given arc?
bool Group_28330::FUN_00028330(const char *name, float heading, float arc)
{
    Pawn_28330 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!pawn)
        return false;
    Vec3_28330 p = pawn->pos;
    Vec3_28330 zero;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    if (p.FUN_0022d2b0(&zero, 1.0e-5f))
        return false;
    float bearing = FUN_00224ea0(p.x, p.z);
    AbsFloat diff;
    diff.f = FUN_00224fc0(heading, bearing);
    diff.bits &= 0x7fffffff;
    return arc * 0.00872664619f > diff.f;
}


// 0x00028400 FUN_00028400 (110 B): equivalent/0x00028400.cpp
// sym: ?FUN_00028400@Group_28400@fn_f6d645d0@@QAEXPBDMMM@Z @523eca804881 @w2d604529b834
// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 2/2)
// FUN_00028400 @ 0x00028400
void Group_28400::FUN_00028400(const char *name, float x, float y, float z)
{
    Pawn_28400 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (pawn) {
        Vec3_28400 v;
        v.x = x;
        v.y = y;
        v.z = z;
        v.FUN_0022d110();
        pawn->aimDir = v;
    }
}


// 0x00028470 FUN_00028470 (67 B): matches/0x00028470.cpp
// sym: ?Fn@Owner@fn_f6d645d0@@QAEXH@Z
void Owner::Fn(int x) {
    __int64 v = Convert(x, 0, 0);
    Item* p = Get_00024280(v);
    if (p) {
        p->a = 0;
        p->b = 0;
        p->c = 0;
    }
}

} // namespace fn_f6d645d0

// 0x000284c0 FUN_000284c0 (52 B): matches/0x000284c0.cpp [wrapped: conflict: Obj]
// sym: ?get@C@fn_000284c0@@QAEMH@Z
namespace fn_000284c0 {
// data: zero = DAT_003f32e0

class Obj {
  public:
    char pad[0x1b0c];
    float value;
};
class C {
  public:
    Obj* lookup_00024280(__int64);
    float get(int id);
};
extern "C++" __int64 __cdecl find_002672f0(int, int, int);
float C::get(int id) {
    __int64 x = find_002672f0(id, 0, 0);
    Obj* p = lookup_00024280(x);
    if (!p)
        return DAT_003f32e0;
    return p->value;
}
} // namespace fn_000284c0


// 0x00028500 FUN_00028500 (48 B): matches/0x00028500.cpp [wrapped: conflict: Make]
// sym: ?Test@Obj@fn_00028500@@QAEEH@Z
namespace fn_00028500 {
struct Pair {
    int a, b;
};
extern "C++" Pair __cdecl Make_002672f0(int, int, int);
class Obj {
  public:
    void* Find_00024280(int, int);
    unsigned char Test(int x);
};
unsigned char Obj::Test(int x) {
    Pair p = Make_002672f0(x, 0, 0);
    unsigned char* q = (unsigned char*)Find_00024280(p.a, p.b);
    if (!q)
        return 0;
    return q[0x1b34];
}
} // namespace fn_00028500

namespace fn_f6d645d0 {

// 0x00028530 FUN_00028530 (128 B): equivalent/0x00028530.cpp
// sym: ?FUN_00028530@Owner_28530@fn_f6d645d0@@QAEHPBD0M@Z @a482a33505a8 @w23bcee08b2fd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00028530 @ 0x00028530
int Owner_28530::FUN_00028530(const char* name, const char* attr, float value)
{
    Entry_28530* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!entry) {
        return 0;
    }
    if (((*(unsigned int*)&DAT_004dc130) & 1) == 0) {
        (*(unsigned int*)&DAT_004dc130) |= 1;
        (*(NameKey_28530*)&DAT_004dc128).FUN_0027af00();
        atexit(FUN_00363b40);
    }
    ((owners::Target_27b040 *)&((*(NameKey_28530*)&DAT_004dc128)))->FUN_0027b040((hulk_uintptr)attr);
    return entry->FUN_00036e70(((NameKey_28530*)&DAT_004dc128), (int)value);
}


// 0x000285b0 FUN_000285b0 (122 B): matches/0x000285b0.cpp
// sym: ?FUN_000285b0@Owner_285b0@fn_f6d645d0@@QAEHPBD0@Z
// FUN_000285b0 @ 0x000285b0
int Owner_285b0::FUN_000285b0(const char* name, const char* attr)
{
    Entry_285b0* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!entry) {
        return 0;
    }
    if (((*(unsigned int*)&DAT_004dc140) & 1) == 0) {
        (*(unsigned int*)&DAT_004dc140) |= 1;
        (*(NameKey_285b0*)&DAT_004dc138).FUN_0027af00();
        atexit(FUN_00363b50);
    }
    ((owners::Target_27b040 *)&((*(NameKey_285b0*)&DAT_004dc138)))->FUN_0027b040((hulk_uintptr)attr);
    return ((int)((owners::Obj_36e40 *)entry)->FUN_00036e40((hulk_uintptr)(NameKey_285b0 *)(((NameKey_285b0*)&DAT_004dc138))));
}

} // namespace fn_f6d645d0

// 0x00028630 FUN_00028630 (53 B): matches/0x00028630.cpp [wrapped: same definition as 0x000276f0 in this TU]
// sym: ?Func@Obj@fn_00028630@@QAEXHH@Z
namespace fn_00028630 {
struct Sub {
};
struct Item {
    char pad[0x1d70];
    Sub sub;
};
struct Obj {
    Item* Find_00024280(unsigned int, unsigned int);
    void Func(int, int);
};
extern "C++" unsigned __int64 __cdecl Query_002672f0(int, int, hulk_intptr);
void Obj::Func(int id, int value) {
    unsigned __int64 x = Query_002672f0(id, 0, 0);
    Item* p = Find_00024280((unsigned int)x, (unsigned int)(x >> 32));
    if (p)
        ((owners::Target_27b040 *)&(p->sub))->FUN_0027b040((hulk_uintptr)value);
}
} // namespace fn_00028630


// 0x00028670 FUN_00028670 (51 B): matches/0x00028670.cpp [wrapped: conflict: Obj]
// sym: ?fn@Obj@fn_00028670@@QAEHPBDH@Z
namespace fn_00028670 {
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

struct Sub {
    int done_0027b010();
};
struct Result {
    char pad[0x1d70];
    Sub sub;
};
struct Obj {
    Result* get_00024280(unsigned a, unsigned b);
    int fn(const char* s, int n);
};
int Obj::fn(const char* s, int n) {
    unsigned __int64 v = FUN_002672f0(s, 0, 0);
    Result* r = get_00024280((unsigned)v, (unsigned)(v >> 32));
    if (!r)
        return 0;
    return r->sub.done_0027b010();
}
} // namespace fn_00028670
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000286b0 FUN_000286b0 (112 B): matches/0x000286b0.cpp [wrapped: conflict: FUN_000678d0]
// sym: ?FUN_000286b0@fn_000286b0@@YGXHPBD@Z
namespace fn_000286b0 {
// FUN_000286b0 @ 0x000286b0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif

void FUN_00363b60();

struct NameKey_286b0 {
    int lo, hi;
    void FUN_0027af00();
};

struct Registry_286b0 {
    void FUN_00066a10(NameKey_286b0* key);
};

Registry_286b0* FUN_000678d0();

// Looks up the static name key in the registry.
void __stdcall FUN_000286b0(int unused, const char* name)
{
    if (((*(unsigned int*)&DAT_004dc150) & 1) == 0) {
        (*(unsigned int*)&DAT_004dc150) |= 1;
        (*(NameKey_286b0*)&DAT_004dc148).FUN_0027af00();
        atexit(FUN_00363b60);
    }
    ((owners::Target_27b040 *)&((*(NameKey_286b0*)&DAT_004dc148)))->FUN_0027b040((hulk_uintptr)name);
    NameKey_286b0 key = (*(NameKey_286b0*)&DAT_004dc148);
    FUN_000678d0()->FUN_00066a10(&key);
}
} // namespace fn_000286b0


// 0x00028720 FUN_00028720 (112 B): matches/0x00028720.cpp [wrapped: conflict: FUN_000678d0]
// sym: ?FUN_00028720@fn_00028720@@YGXPBDH@Z
namespace fn_00028720 {
// FUN_00028720 @ 0x00028720


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif

void FUN_00363b70();

struct NameKey_28720 {
    int lo, hi;
    void FUN_0027af00();
};

struct Registry_28720 {
    void FUN_00065ee0(NameKey_28720* key);
};

Registry_28720* FUN_000678d0();

// Looks up the static name key in the registry.
void __stdcall FUN_00028720(const char* name, int unused)
{
    if (((*(unsigned int*)&DAT_004dc160) & 1) == 0) {
        (*(unsigned int*)&DAT_004dc160) |= 1;
        (*(NameKey_28720*)&DAT_004dc158).FUN_0027af00();
        atexit(FUN_00363b70);
    }
    ((owners::Target_27b040 *)&((*(NameKey_28720*)&DAT_004dc158)))->FUN_0027b040((hulk_uintptr)name);
    NameKey_28720 key = (*(NameKey_28720*)&DAT_004dc158);
    FUN_000678d0()->FUN_00065ee0(&key);
}
} // namespace fn_00028720


// 0x00028790 FUN_00028790 (54 B): matches/0x00028790.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?target@Owner@fn_00028790@@QAEXPBDHH@Z
namespace fn_00028790 {
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

typedef unsigned __int64 U64;
class Item {
  public:
    void fn_0003ed40(int, int);
};
class Owner {
  public:
    Item* lookup_00024280(U64);
    void target(const char*, int, int);
};
void Owner::target(const char* s, int a, int b) {
    U64 n = FUN_002672f0(s, 0, 0);
    Item* p = lookup_00024280(n);
    if (p)
        p->fn_0003ed40(a, b);
}
} // namespace fn_00028790
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000287d0 FUN_000287d0 (49 B): matches/0x000287d0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Act@Host@fn_000287d0@@QAEXPBDH@Z
namespace fn_000287d0 {
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

class Item {
  public:
    void Apply_00037300(int);
};
class Host {
  public:
    Item* Lookup_00024280(__int64);
    void Act(const char*, int);
};
void Host::Act(const char* s, int n) {
    __int64 k = FUN_002672f0(s, 0, 0);
    Item* p = Lookup_00024280(k);
    if (p)
        p->Apply_00037300(n);
}
} // namespace fn_000287d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00028810 FUN_00028810 (47 B): matches/0x00028810.cpp [wrapped: conflict: Result; make]
// sym: ?fn@Obj@fn_00028810@@QAEXHE@Z
namespace fn_00028810 {
struct Result {
    char pad[0x1cee];
    unsigned char flag;
};
class Obj {
  public:
    Result* get_00024280(__int64);
    void fn(int, unsigned char);
};
extern "C++" __int64 __cdecl make_002672f0(int, int, hulk_intptr);
void Obj::fn(int a, unsigned char b) {
    Result* p = get_00024280(make_002672f0(a, 0, 0));
    if (p)
        p->flag = b;
}
} // namespace fn_00028810

namespace fn_f6d645d0 {

// 0x00028840 FUN_00028840 (106 B): matches/0x00028840.cpp
// sym: ?FUN_00028840@Owner_28840@fn_f6d645d0@@QAEXPBDM@Z
// FUN_00028840 @ 0x00028840
void Owner_28840::FUN_00028840(const char* name, float value)
{
    Entry_28840* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (entry) {
        entry->FUN_0003b1c0(value, 1);
        if (value <= 0.0f) {
            if (entry == current) {
                ((::CScenarioManager *)(root->focus))->FUN_001cc620(2);
            } else {
                ((owners::Controller_3ea10 *)entry)->FUN_0003ea10(1);
            }
        }
    }
}

} // namespace fn_f6d645d0

// 0x000288b0 FUN_000288b0 (65 B): matches/0x000288b0.cpp [wrapped: conflict: Lookup]
// sym: ?Do@Owner@fn_000288b0@@QAEXPBDHH@Z
namespace fn_000288b0 {
typedef __int64 I64;
extern "C++" I64 __cdecl Lookup_002672f0(const char*, int, int);
class Node {
  public:
    void Play_00043350(int, int, int, float, int, int);
};
class Owner {
  public:
    Node* Find_00024280(I64);
    void Do(const char*, int, int);
};
void Owner::Do(const char* name, int a, int b) {
    I64 id = Lookup_002672f0(name, 0, 0);
    Node* n = Find_00024280(id);
    if (n)
        n->Play_00043350(a, 0, 0, 1.0f, b, 0);
}
} // namespace fn_000288b0


// 0x00028900 FUN_00028900 (52 B): matches/0x00028900.cpp [wrapped: conflict: Obj]
// sym: ?Get@Holder@fn_00028900@@QAEMH@Z
namespace fn_00028900 {
struct Obj {
    char pad[0x1b10];
    float value;
};
long long __cdecl Fetch_002672f0(int, int, int);
class Holder {
  public:
    Obj* Find_00024280(long long);
    float Get(int);
};
float Holder::Get(int id) {
    long long key = Fetch_002672f0(id, 0, 0);
    Obj* p = Find_00024280(key);
    if (!p)
        return 0.0f;
    return p->value;
}
} // namespace fn_00028900


// 0x00028940 FUN_00028940 (49 B): matches/0x00028940.cpp [wrapped: conflict: Obj]
// sym: ?Do@Obj@fn_00028940@@QAEXPBDH@Z
namespace fn_00028940 {
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

struct Result {
    void Apply_00036040(int);
};
struct Obj {
    Result* Find_00024280(unsigned, unsigned);
    void Do(const char*, int);
};
void Obj::Do(const char* s, int x) {
    unsigned __int64 v = FUN_002672f0(s, 0, 0);
    Result* r = Find_00024280((unsigned)v, (unsigned)(v >> 32));
    if (r)
        r->Apply_00036040(x);
}
} // namespace fn_00028940
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00028980 FUN_00028980 (53 B): matches/0x00028980.cpp [wrapped: conflict: Hash]
// sym: ?Fn@X@fn_00028980@@QAEMPBD@Z
namespace fn_00028980 {
class Obj {
  public:
    float Value_00036090();
};
class X {
  public:
    Obj* Find_00024280(unsigned __int64);
    hulk_freg Fn(const char*);
};
extern "C++" unsigned __int64 __cdecl Hash_002672f0(const char*, int, int);
hulk_freg X::Fn(const char* s) {
    unsigned __int64 h = Hash_002672f0(s, 0, 0);
    Obj* p = Find_00024280(h);
    if (!p)
        return 0.0f;
    return p->Value_00036090();
}
} // namespace fn_00028980


// 0x000289c0 FUN_000289c0 (53 B): matches/0x000289c0.cpp [wrapped: conflict: Obj]
// sym: ?Run@Obj@fn_000289c0@@QAEMPBD@Z
namespace fn_000289c0 {
// data: zero = DAT_003f32e0

struct Result {
    float Get_000360b0();
};
struct Obj {
    Result* Find_00024280(unsigned a, unsigned b);
    hulk_freg Run(const char* s);
};
extern "C++" unsigned __int64 __cdecl Parse(const char*, int, int);
hulk_freg Obj::Run(const char* s) {
    unsigned __int64 v = Parse(s, 0, 0);
    Result* r = Find_00024280((unsigned)v, (unsigned)(v >> 32));
    if (!r)
        return DAT_003f32e0;
    return r->Get_000360b0();
}
} // namespace fn_000289c0


// 0x00028a00 FUN_00028a00 (71 B): matches/0x00028a00.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?get@Obj@fn_00028a00@@QAEMH@Z
namespace fn_00028a00 {
struct Entry {
    char pad[0x160];
    float value;
};
struct Found {
    char pad[0x11c];
    Entry* entry;
};
extern "C++" unsigned __int64 __cdecl FUN_002672f0(int, int, int);
extern float zeroA;
extern float zeroB;
class Obj {
  public:
    Found* lookup_00024280(unsigned __int64);
    float get(int);
};
float Obj::get(int id) {
    unsigned __int64 key = FUN_002672f0(id, 0, 0);
    Found* f = lookup_00024280(key);
    if (!f)
        return zeroA;
    Entry* e = f->entry;
    if (e)
        return e->value;
    return zeroB;
}
} // namespace fn_00028a00


// 0x00028a50 FUN_00028a50 (71 B): matches/0x00028a50.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Get@Owner@fn_00028a50@@QAEMH@Z
namespace fn_00028a50 {
extern float zeroFloat1, zeroFloat2;
extern "C++" __int64 __cdecl FindKey_002672f0(int, int, int);
struct Data {
    char pad[0x164];
    float value;
};
struct Item {
    char pad[0x11c];
    Data* data;
};
class Owner {
  public:
    Item* Lookup_00024280(__int64 key);
    float Get(int key);
};
float Owner::Get(int key) {
    __int64 id = FindKey_002672f0(key, 0, 0);
    Item* item = Lookup_00024280(id);
    if (!item)
        return zeroFloat1;
    Data* data = item->data;
    if (data)
        return data->value;
    return zeroFloat2;
}
} // namespace fn_00028a50

namespace fn_f6d645d0 {

// 0x00028aa0 FUN_00028aa0 (46 B): matches/0x00028aa0.cpp
// sym: ?FUN_00028aa0@X@fn_f6d645d0@@QAEHH@Z
int X::FUN_00028aa0(int x) {
    Two p;
    p.both = FUN_002672f0(x, 0, 0);
    char* q = (char*)FUN_00024280(p.halves.a, p.halves.b);
    if (!q)
        return 0;
    return *(int*)(q + 0x318);
}

} // namespace fn_f6d645d0

// 0x00028ad0 FUN_00028ad0 (47 B): matches/0x00028ad0.cpp [wrapped: conflict: FUN_002672f0; Result]
// sym: ?target@X@fn_00028ad0@@QAEXHH@Z
namespace fn_00028ad0 {
struct Result {
    char pad[0x318];
    int value;
};
struct X {
    void target(int, int);
    Result* lookup_00024280(unsigned __int64);
};
extern "C++" unsigned __int64 __cdecl FUN_002672f0(int, int, int);
void X::target(int a, int b) {
    unsigned __int64 n = FUN_002672f0(a, 0, 0);
    Result* r = lookup_00024280(n);
    if (r)
        r->value = b;
}
} // namespace fn_00028ad0


// 0x00028b00 FUN_00028b00 (46 B): matches/0x00028b00.cpp [wrapped: conflict: Result]
// sym: ?get@Owner@fn_00028b00@@QAEHH@Z
namespace fn_00028b00 {
struct Result {
    char pad[0x324];
    int value;
};
unsigned __int64 __cdecl lookup_002672f0(int, int, int);
class Owner {
  public:
    Result* resolve_00024280(unsigned __int64);
    int get(int);
};
int Owner::get(int id) {
    unsigned __int64 key = lookup_002672f0(id, 0, 0);
    Result* p = resolve_00024280(key);
    if (!p)
        return 0;
    return p->value;
}
} // namespace fn_00028b00


// 0x00028b30 FUN_00028b30 (47 B): matches/0x00028b30.cpp [wrapped: conflict: Item]
// sym: ?fn@Obj@fn_00028b30@@QAEXHH@Z
namespace fn_00028b30 {
struct Item {
    char pad[0x324];
    int value;
};
extern "C++" unsigned __int64 __cdecl conv_002672f0(int, int, int);
class Obj {
  public:
    Item* lookup_00024280(unsigned, unsigned);
    void fn(int, int);
};
void Obj::fn(int arg, int value) {
    unsigned __int64 key = conv_002672f0(arg, 0, 0);
    Item* p = lookup_00024280((unsigned)key, (unsigned)(key >> 32));
    if (p)
        p->value = value;
}
} // namespace fn_00028b30


// 0x00028b60 FUN_00028b60 (52 B): matches/0x00028b60.cpp [wrapped: conflict: Obj; Result]
// sym: ?get@Obj@fn_00028b60@@QAEMH@Z
namespace fn_00028b60 {
struct Result {
    char pad[0x1e58];
    float value;
};
struct Obj {
    Result* lookup_00024280(unsigned long long);
    float get(int);
};
extern "C++" unsigned long long __cdecl acquire_002672f0(int, int, int);
float Obj::get(int x) {
    unsigned long long v = acquire_002672f0(x, 0, 0);
    Result* r = lookup_00024280(v);
    if (!r)
        return 0.0f;
    return r->value;
}
} // namespace fn_00028b60

namespace fn_f6d645d0 {

// 0x00028ba0 FUN_00028ba0 (121 B): equivalent/0x00028ba0.cpp
// sym: ?FUN_00028ba0@Group_28ba0@fn_f6d645d0@@QAEXPBDH0@Z @e4d9da70c229 @w148a10e781d1
// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 8/8)
// FUN_00028ba0 @ 0x00028ba0
void Group_28ba0::FUN_00028ba0(const char *name, int value, const char *modeName)
{
    Pawn_28ba0 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (pawn) {
        pawn->mode = 0;
        if (modeName) {
            char c = FUN_00345475(*modeName);
            if (c == 'a') {
                pawn->mode = 1;
            } else if (c == 't') {
                pawn->mode = 2;
            }
        }
        pawn->value = value;
    }
}

} // namespace fn_f6d645d0

// 0x00028c20 FUN_00028c20 (62 B): matches/0x00028c20.cpp [wrapped: conflict: DAT_003f335c]
// sym: ?FUN_00028c20@Thing@fn_00028c20@@QAEPAMPAX@Z
namespace fn_00028c20 {
extern float DAT_003f335c;
extern __int64 __cdecl FUN_002672f0(void*, int, int);
struct Value {
    float* FUN_00036d00();
};
struct Object {
    char pad[0x334];
    Value* value;
};
struct Thing {
    Object* FUN_00024280(unsigned int low, unsigned int high);
    float* FUN_00028c20(void* arg);
};
float* Thing::FUN_00028c20(void* arg) {
    unsigned __int64 result = FUN_002672f0(arg, 0, 0);
    Object* object = FUN_00024280((unsigned int)result, (unsigned int)(result >> 32));
    Value* v = object ? object->value : 0;
    if (!v)
        return &DAT_003f335c;
    return v->FUN_00036d00();
}
} // namespace fn_00028c20


// 0x00028c60 FUN_00028c60 (49 B): matches/0x00028c60.cpp [wrapped: conflict: Obj]
// sym: ?run@Target@fn_00028c60@@QAEHH@Z
namespace fn_00028c60 {
typedef unsigned __int64 U64;
U64 __cdecl getValue_002672f0(int, int, int);
class Obj {
  public:
    char pad[0x20b0];
    int value;
};
class Target {
  public:
    Obj* lookup_00024280(U64);
    int run(int);
};
int Target::run(int x) {
    U64 v = getValue_002672f0(x, 0, 0);
    Obj* o = lookup_00024280(v);
    if (!o)
        return -1;
    return o->value;
}
} // namespace fn_00028c60


// 0x00028ca0 FUN_00028ca0 (54 B): matches/0x00028ca0.cpp [wrapped: conflict: Obj; Pair; find]
// sym: ?run@C@fn_00028ca0@@QAEXI@Z
namespace fn_00028ca0 {
struct Obj {
    char pad[0xe8];
    unsigned char flag;
};
struct Wrap {
    char pad[0x1ca0];
    Obj* obj;
};
struct Pair {
    unsigned a, b;
};
Pair __cdecl find_002672f0(unsigned, unsigned, unsigned);
class C {
  public:
    Wrap* get_00024280(unsigned, unsigned);
    void run(unsigned);
};
void C::run(unsigned x) {
    Pair p = find_002672f0(x, 0, 0);
    Wrap* w = get_00024280(p.a, p.b);
    if (w && w->obj)
        w->obj->flag = 1;
}
} // namespace fn_00028ca0


// 0x00028ce0 FUN_00028ce0 (61 B): matches/0x00028ce0.cpp [wrapped: conflict: Item]
// sym: ?act@Owner@fn_00028ce0@@QAEXPBD@Z
namespace fn_00028ce0 {
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

struct Sub {
    char pad[0xe8];
    char flag;
};
struct Item {
    char pad[0x1ca0];
    Sub* sub;
    char pad2[0x22b0 - 0x1ca4];
    char flag;
};
struct Owner {
    Item* get_00024280(unsigned a, unsigned b);
    void act(const char* s);
};
void Owner::act(const char* s) {
    unsigned __int64 v = FUN_002672f0(s, 0, 0);
    Item* p = get_00024280((unsigned)v, (unsigned)(v >> 32));
    if (p && p->sub) {
        p->flag = 0;
        p->sub->flag = 0;
    }
}
} // namespace fn_00028ce0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00028d20 FUN_00028d20 (58 B): matches/0x00028d20.cpp [wrapped: conflict: Make]
// sym: ?Check@Owner@fn_00028d20@@QAEEI@Z
namespace fn_00028d20 {
typedef unsigned __int64 U64;
U64 __cdecl Make_002672f0(unsigned int, int, int);
struct State {
    char pad[0xe8];
    unsigned char flag;
};
class Item {
  public:
    char pad[0x1ca0];
    State* state;
};
class Owner {
  public:
    Item* Lookup_00024280(U64);
    unsigned char Check(unsigned int);
};
unsigned char Owner::Check(unsigned int id) {
    Item* item = Lookup_00024280(Make_002672f0(id, 0, 0));
    State* state = item ? item->state : 0;
    if (!state)
        return 0;
    return state->flag;
}
} // namespace fn_00028d20


// 0x00028d60 FUN_00028d60 (54 B): matches/0x00028d60.cpp [wrapped: conflict: makeKey]
// sym: ?act@Owner@fn_00028d60@@QAEXH@Z
namespace fn_00028d60 {
typedef unsigned __int64 U64;
U64 __cdecl makeKey_002672f0(int, int, int);
struct Item {
    char pad[0x1ca0];
    struct Status* status;
};
struct Status {
    char pad[0xe9];
    unsigned char enabled;
};
class Owner {
  public:
    Item* get_00024280(U64);
    void act(int);
};
void Owner::act(int n) {
    U64 key = makeKey_002672f0(n, 0, 0);
    Item* item = get_00024280(key);
    if (item && item->status)
        item->status->enabled = 1;
}
} // namespace fn_00028d60


// 0x00028da0 FUN_00028da0 (54 B): matches/0x00028da0.cpp [wrapped: conflict: Item]
// sym: ?Act@Owner@fn_00028da0@@QAEXPAX@Z
namespace fn_00028da0 {
extern "C++" __int64 __cdecl FindThing_002672f0(void*, int, int);
struct Item {
    char pad[0x1ca0];
    struct Flag* flag;
};
struct Flag {
    char pad[0xe9];
    unsigned char value;
};
class Owner {
  public:
    Item* Get_00024280(__int64);
    void Act(void*);
};
void Owner::Act(void* p) {
    __int64 id = FindThing_002672f0(p, 0, 0);
    Item* item = Get_00024280(id);
    if (item && item->flag)
        item->flag->value = 0;
}
} // namespace fn_00028da0

namespace fn_f6d645d0 {

// 0x00028de0 FUN_00028de0 (73 B): matches/0x00028de0.cpp
// sym: ?Run@Handler@fn_f6d645d0@@QAEXHH@Z
void Handler::Run(int a, int b) {
    Obj* obj = Find_00024280(Decode_002672f0(a, 0, 0));
    if (obj) {
        Mid* m = obj->mid;
        if (m) {
            End* e = m->Get_000fdc40();
            if (e)
                e->Act_00103b60(field, b, 0);
        }
    }
}

} // namespace fn_f6d645d0

// 0x00028e30 FUN_00028e30 (84 B): equivalent/0x00028e30.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?FUN_00028e30@Owner@fn_00028e30@@QAEXPAX@Z @4a5aa60ce6e0 @wbaf1a043871d
namespace fn_00028e30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00028e30 @ 0x00028e30
struct Target { void FUN_00103b60(void*, int, int); }; struct Link { Target* FUN_000fdc40(); }; struct Item { char pad[0x1ca0]; Link* link; int FUN_00036d30(); }; __int64 __cdecl FUN_002672f0(void*, int, int); struct Owner { void* first; Item* FUN_00024280(__int64); void FUN_00028e30(void* input); }; void Owner::FUN_00028e30(void* input) { __int64 value = FUN_002672f0(input, 0, 0); Item* item = FUN_00024280(value); if (item && item->link) { Target* target = item->link->FUN_000fdc40(); if (target) { target->FUN_00103b60(first, item->FUN_00036d30(), 0); } } }
} // namespace fn_00028e30

namespace fn_f6d645d0 {

// 0x00028e90 FUN_00028e90 (73 B): matches/0x00028e90.cpp
// sym: ?fn@Main@fn_f6d645d0@@QAEXPBDH@Z
void Main::fn(const char* text, int x) {
    Obj* o = lookup_00024280(FUN_002672f0(text, 0, 0));
    if (!o)
        return;
    if (!o->mid)
        return;
    End* e = o->mid->get_000fdc40();
    if (!e)
        return;
    e->act_00103b60(value, x, 1);
}


// 0x00028ee0 FUN_00028ee0 (68 B): equivalent/0x00028ee0.cpp
// sym: ?FUN_00028ee0@Owner@fn_f6d645d0@@QAEIPBD@Z @18965fc50462 @w621c8122eaf8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00028ee0 @ 0x00028ee0
unsigned int Owner::FUN_00028ee0(const char* name) {
    __int64 id = FUN_002672f0(name, 0, 0);
    Obj* object = FUN_00024280((unsigned int)id, (unsigned int)(id >> 32));
    if (!object || !object->inner) return 0;
    Final* result = (Final*)object->inner->FUN_000fdc40();
    if (!result) return 0;
    return result->FUN_001034d0();
}

} // namespace fn_f6d645d0

// 0x00028f30 FUN_00028f30 (68 B): equivalent/0x00028f30.cpp [wrapped: conflict: Query; Result]
// sym: ?FUN_00028f30@Owner@fn_00028f30@@QAEHPBD@Z @002a251a609a @w8abeaa0332f4
namespace fn_00028f30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00028f30 @ 0x00028f30
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

typedef unsigned __int64 U64;
struct Result { char pad[0xb4]; int value; };
struct Item { char pad[0x1ca0]; struct Query *query; };
struct Query { Result *FUN_000fdc40(); };
struct Owner {
    Item *FUN_00024280(U64);
    int FUN_00028f30(const char *name);
};
int Owner::FUN_00028f30(const char *name) {
    U64 id = FUN_002672f0(name, 0, 0);
    Item *item = FUN_00024280(id);
    if (item && item->query) {
        Result *result = item->query->FUN_000fdc40();
        if (result) return result->value;
    }
    return -1;
}
} // namespace fn_00028f30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00028f80 FUN_00028f80 (68 B): equivalent/0x00028f80.cpp [wrapped: conflict: Result]
// sym: ?FUN_00028f80@Handler@fn_00028f80@@QAEHH@Z @7db91bf70f82 @w01ea53565bd3
namespace fn_00028f80 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00028f80 @ 0x00028f80
struct Result { char pad[0xb8]; int value; }; struct Object { Result* FUN_000fdc40(); }; struct Item { char pad[0x1ca0]; Object *object; }; struct Handler { Item* FUN_00024280(unsigned int, unsigned int); int FUN_00028f80(int); }; extern "C++" __int64 __cdecl FUN_002672f0(int, int, int); int Handler::FUN_00028f80(int arg) { __int64 id = FUN_002672f0(arg,0,0); Item* item = FUN_00024280((unsigned int)id, (unsigned int)(id >> 32)); if (item && item->object) { Result* result = item->object->FUN_000fdc40(); if (result) return result->value; } return -1; }
} // namespace fn_00028f80


// 0x00028fd0 FUN_00028fd0 (63 B): matches/0x00028fd0.cpp [wrapped: conflict: FUN_002672f0; Owner]
// sym: ?FUN_00028fd0@Owner@fn_00028fd0@@QAEPAUFoundObject@2@H@Z
namespace fn_00028fd0 {
typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(int value, int zero1, int zero2);
struct FoundObject;
struct FinalObject {
    FoundObject* FUN_001034e0();
};
struct IntermediateObject {
    FinalObject* FUN_000fdc40();
};
struct FoundObject {
    char pad[0x1ca0];
    IntermediateObject* next;
};
struct Owner {
    FoundObject* FUN_00024280(U64 key);
    FoundObject* FUN_00028fd0(int value);
};
FoundObject* Owner::FUN_00028fd0(int value) {
    U64 key = FUN_002672f0(value, 0, 0);
    FoundObject* found = FUN_00024280(key);
    if (found && found->next) {
        FinalObject* result = found->next->FUN_000fdc40();
        found = (FoundObject*)result;
        if (result)
            found = result->FUN_001034e0();
    }
    return found;
}
} // namespace fn_00028fd0


// 0x00029060 FUN_00029060 (49 B): matches/0x00029060.cpp [wrapped: conflict: Obj]
// sym: ?Fn@Obj@fn_00029060@@QAEXHH@Z
namespace fn_00029060 {
extern "C++" __int64 __cdecl Convert(int, int, int);
class Elem {
  public:
    void Test_00035140(int);
};
class Obj {
  public:
    Elem* Find_00024280(__int64);
    void Fn(int, int);
};
void Obj::Fn(int a, int b) {
    Elem* p = Find_00024280(Convert(a, 0, 0));
    if (p)
        p->Test_00035140(b);
}
} // namespace fn_00029060


// 0x000290a0 FUN_000290a0 (73 B): equivalent/0x000290a0.cpp [wrapped: conflict: Item]
// sym: ?FUN_000290a0@Owner@fn_000290a0@@QAEXH@Z @7a9ce429bcbb @wced57e9a2e1b
namespace fn_000290a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000290a0 @ 0x000290a0
struct Result { char pad[0x1ca0]; void *field; }; 
struct Item { char pad[0x12c]; int value; };
struct Action { void FUN_000fe4d0(int, int); };
long long __cdecl FUN_002672f0(int, int, int);
struct Owner { char pad[0x124]; Item *item; Result *FUN_00024280(int, int); void FUN_000290a0(int); };
void Owner::FUN_000290a0(int arg) {
    long long pair = FUN_002672f0(arg, 0, 0);
    Result *result = FUN_00024280((int)pair, (int)(pair >> 32));
    if (result && result->field && item)
        ((Action *)result->field)->FUN_000fe4d0(item->value, 1);
}
} // namespace fn_000290a0


// 0x000290f0 FUN_000290f0 (71 B): matches/0x000290f0.cpp [wrapped: conflict: Fetch; Obj]
// sym: ?Target@Obj@fn_000290f0@@QAEXPAX@Z
namespace fn_000290f0 {
class Actor {
  public:
    void Act_000fe4d0(int, int);
};
struct Result {
    char pad[0x1ca0];
    Actor* ptr;
};
struct Inner {
    char pad[0x12c];
    int val;
};
class Obj {
  public:
    char pad[0x124];
    Inner* inner;
    Result* Find_00024280(__int64);
    void Target(void*);
};
extern "C++" __int64 __cdecl Fetch_002672f0(void*, int, int);
void Obj::Target(void* p) {
    Result* r = Find_00024280(Fetch_002672f0(p, 0, 0));
    if (r != 0 && r->ptr != 0 && inner != 0)
        r->ptr->Act_000fe4d0(inner->val, 0);
}
} // namespace fn_000290f0

namespace fn_f6d645d0 {

// 0x00029140 FUN_00029140 (267 B): equivalent/0x00029140.cpp
// sym: ?FUN_00029140@Target_29140@fn_f6d645d0@@QAEXUVec_29140@2@M@Z @a7decbaedf9b @w2d8f7e47d366
// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 20/22, incomplete)
// FUN_00029140 @ 0x00029140
void Target_29140::FUN_00029140(Vec_29140 center,float radius) {
 int n=count;
 for(int i=0;i<n;++i) {
  if(i<0 || i>=count) continue;
  Item_29140* item=((Item_29140 *)((owners::ThisWrap_00059c10 *)(owner->manager))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
  if(!item) continue;
  Vec_29140 p; item->position->FUN_00059a50(&p);
  if(item->FUN_00035ab0()) continue;
  float r=item->radius;
  if(!(r>0.0f)) continue;
  Entity* entity=item->entity;
  if(!entity) continue;
  Transform_29140* t=&entity->transform;
  if(!t) continue;
  double dx=(double)center.x-p.x,dy=(double)center.y-p.y,dz=(double)center.z-p.z;
  if(!((double)r+radius>sqrt(dz*dz+dy*dy+dx*dx))) continue;
  ((owners::Obj_fddb0 *)t)->FUN_000fddb0((int *)(Vec_29140 *)(&center));
  if(entity->getState()<2) entity->setState(2);
 }
}

} // namespace fn_f6d645d0

// 0x00029250 FUN_00029250 (233 B): equivalent/0x00029250.cpp [wrapped: conflict: Entity]
// sym: ?FUN_00029250@Target_29250@fn_00029250@@QAEXHPBUVec3_29250@2@MH@Z @d653b53d5c75 @wad100147b2d0
namespace fn_00029250 {
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 17/20, incomplete)
// FUN_00029250 @ 0x00029250

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

struct Vec3_29250 { float x,y,z; };
struct Effect_29250 { char pad[0x58]; char data; void FUN_000fe4d0(int, int); };
struct Position_29250 { void FUN_00059a50(Vec3_29250*); };
struct Entity { char pad0[0x10]; Position_29250* position; char pad1[0x1ca0-0x14]; Effect_29250* effect; char pad2[0x1cbc-0x1ca4]; float value; bool FUN_00035ab0(); };
struct Registry_29250 {  };
struct Owner_29250 { char pad[0x44]; Registry_29250* registry; };
struct Target_29250 { Owner_29250* owner; char pad[8]; int count; int ids[1]; void FUN_00029250(int, const Vec3_29250*, float, int); };
void Target_29250::FUN_00029250(int a, const Vec3_29250* point, float radius, int b) {
 int n=count;
 for(int i=0;i<n;++i) {
  if(i<0 || i>=count) continue;
  Entity* e=((Entity *)((owners::ThisWrap_00059c10 *)(owner->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
  if(!e) continue;
  Vec3_29250 p;
  e->position->FUN_00059a50(&p);
  if(e->FUN_00035ab0()) continue;
  if(!(e->value>0.0f)) continue;
  Effect_29250* effect=e->effect;
  if(!effect || !&effect->data) continue;
  double x=(double)point->x-p.x;
  double y=(double)point->y-p.y;
  double z=(double)point->z-p.z;
  if(sqrt(z*z+y*y+x*x)<radius) effect->FUN_000fe4d0(a,b);
 }
}
} // namespace fn_00029250


// 0x00029340 FUN_00029340 (75 B): equivalent/0x00029340.cpp [wrapped: conflict: FUN_002672f0; Node]
// sym: ?FUN_00029340@Owner@fn_00029340@@QAEHPAX@Z @2a20adf2696e @w5467263e98ba
namespace fn_00029340 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00029340 @ 0x00029340
struct Handler { int FUN_000fdf40(int value); };
struct Result { char pad[0x1ca0]; Handler *handler; };
struct Node { char pad[0x12c]; int value; };
struct Owner { char pad[0x124]; Node *node; Result *FUN_00024280(unsigned __int64 value); hulk_intptr FUN_00029340(void *input); };
unsigned __int64 __cdecl FUN_002672f0(void *input, int a, int b);
hulk_intptr Owner::FUN_00029340(void *input) {
    unsigned __int64 key = FUN_002672f0(input, 0, 0);
    Result *result = FUN_00024280(key);
    if (!result) return 0;
    Handler *handler = result->handler;
    if (!handler) return 0;
    if (!node) return (hulk_intptr)handler;
    return handler->FUN_000fdf40(node->value);
}
} // namespace fn_00029340

namespace fn_f6d645d0 {

// 0x00029390 FUN_00029390 (94 B): equivalent/0x00029390.cpp
// sym: ?FUN_00029390@Owner@fn_f6d645d0@@QAEHHHHH@Z @c47d54118d57 @w8993f632b52d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00029390 @ 0x00029390
hulk_intptr Owner::FUN_00029390(int key, int value, int flag, int extra) {
    __int64 lookup = FUN_002672f0(key, 0, 0);
    Entry* entry = FUN_00024280(lookup);
    if (!entry) return 0;
    Intermediate* intermediate = entry->intermediate;
    if (!intermediate) return (hulk_intptr)entry;
    Destination* destination = intermediate->FUN_000fdc40();
    if (!destination) return 0;
    return destination->FUN_001035f0(value, flag ? 1 : 0, extra);
}

} // namespace fn_f6d645d0

// 0x000293f0 FUN_000293f0 (67 B): matches/0x000293f0.cpp [wrapped: conflict: Item; i64]
// sym: ?update@Manager@fn_000293f0@@QAEXHHHH@Z
namespace fn_000293f0 {
typedef long long i64;
extern "C++" i64 __cdecl lookupKey_002672f0(int, int, int);
struct Item {
    char pad[0x1d30];
    hulk_intptr a, b, c;
};
class Manager {
  public:
    Item* get_00024280(i64);
    void update(int key, int a, int b, int c);
};
void Manager::update(int key, int a, int b, int c) {
    i64 id = lookupKey_002672f0(key, 0, 0);
    Item* p = get_00024280(id);
    if (p) {
        p->a = a;
        p->b = b;
        p->c = c;
    }
}
} // namespace fn_000293f0


// 0x00029440 FUN_00029440 (47 B): matches/0x00029440.cpp [wrapped: conflict: Obj; Result]
// sym: ?target@Obj@fn_00029440@@QAEXHD@Z
namespace fn_00029440 {
struct Result {
    char pad[0x1d40];
    char flag;
};
struct Obj {
    Result* get_00024280(unsigned long long v);
    void target(int id, char flag);
};
extern "C++" unsigned long long __cdecl convert(int id, int a, int b);
void Obj::target(int id, char flag) {
    unsigned long long v = convert(id, 0, 0);
    Result* r = get_00024280(v);
    if (r)
        r->flag = flag;
}
} // namespace fn_00029440


// 0x00029470 FUN_00029470 (44 B): matches/0x00029470.cpp [wrapped: conflict: Obj; Pair; lookup]
// sym: ?run@Obj@fn_00029470@@QAEXH@Z
namespace fn_00029470 {
struct Pair {
    unsigned a, b;
};
extern "C++" Pair __cdecl lookup(int, int, int);
class Result {
  public:
    void finish_000403f0();
};
class Obj {
  public:
    Result* get_00024280(unsigned, unsigned);
    void run(int);
};
void Obj::run(int x) {
    Pair p = lookup(x, 0, 0);
    Result* r = get_00024280(p.a, p.b);
    if (r)
        r->finish_000403f0();
}
} // namespace fn_00029470


// 0x000294a0 FUN_000294a0 (83 B): matches/0x000294a0.cpp [wrapped: conflict: Owner]
// sym: ?Run@Owner@fn_000294a0@@QAEXPBDHHHH@Z
namespace fn_000294a0 {
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

typedef __int64 I64;
class End {
  public:
    void Work_00103640(int, int, int, int);
};
class Mid {
  public:
    End* Get_000fdc40();
};
class Holder {
    char pad[0x1ca0];

  public:
    Mid* value;
};
class Owner {
  public:
    Holder* Find_00024280(I64);
    void Run(const char* name, int a, int b, int c, int d);
};
void Owner::Run(const char* name, int a, int b, int c, int d) {
    Holder* h = Find_00024280(FUN_002672f0(name, 0, 0));
    if (h && h->value) {
        End* e = h->value->Get_000fdc40();
        if (e)
            e->Work_00103640(a, b, c, d);
    }
}
} // namespace fn_000294a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f6d645d0 {

// 0x00029500 FUN_00029500 (148 B): equivalent/0x00029500.cpp
// sym: ?FUN_00029500@Owner_29500@fn_f6d645d0@@QAEXPBD0@Z @b176bbda2f76 @w3b7aed01e1fc
// STATUS: equivalent (tools/equiv.py level 3: 19977 inputs, branch coverage 10/10)
// FUN_00029500 @ 0x00029500
void Owner_29500::FUN_00029500(const char* name, const char* other)
{
    Entry_29500* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (entry) {
        int value = 0;
        Entry_29500* found = FUN_00024280(FUN_002672f0(other, 0, 0));
        if (found) {
            value = found->handle;
        } else {
            Key_29500 tmp1 = FUN_00096d80(other);
            Item_29500* item = core->registry->FUN_001dee40(tmp1);
            if (item) {
                value = ((int)((owners::C_1d72e0 *)item)->FUN_001d72e0());
            }
        }
        Slot_29500* slot = entry->slot;
        if (slot) {
            slot->value = value;
            entry->FUN_0003ffa0(value, entry != current);
        }
    }
}


// 0x000295a0 FUN_000295a0 (126 B): matches/0x000295a0.cpp
// sym: ?FUN_000295a0@Group_295a0@fn_f6d645d0@@QAEPBDPBD@Z
// FUN_000295a0 @ 0x000295a0
const char *Group_295a0::FUN_000295a0(const char *name)
{
    Pawn_295a0 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!pawn)
        return 0;
    Param *param = pawn->param;
    if (param) {
        if (param->type == 1) {
            if (param->text)
                return param->text->FUN_00036d00();
        } else if (param->type == 5) {
            Text_295a0 *text = param->text;
            if (text) {
                FUN_00096d50(((char*)&DAT_004dc168), 0x100, text->a, text->b);
                return ((char*)&DAT_004dc168);
            }
        }
    }
    return "";
}

} // namespace fn_f6d645d0

// 0x00029620 FUN_00029620 (57 B): matches/0x00029620.cpp [wrapped: conflict: Item]
// sym: ?Set@Obj@fn_00029620@@QAEXPBDE@Z
namespace fn_00029620 {
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

typedef __int64 I64;
struct Item {
    char pad[0x68];
    unsigned char a, b;
};
class Obj {
  public:
    Item* Get_00024280(I64);
    void Set(const char*, unsigned char);
};
void Obj::Set(const char* name, unsigned char value) {
    I64 id = FUN_002672f0(name, 0, 0);
    Item* item = Get_00024280(id);
    if (item) {
        Item* child = *(Item**)((char*)item + 0x1ca0);
        if (child) {
            child->a = value;
            child->b = value;
        }
    }
}
} // namespace fn_00029620
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f6d645d0 {

// 0x00029660 FUN_00029660 (62 B): matches/0x00029660.cpp
// sym: ?Set@Owner@fn_f6d645d0@@QAEXHE@Z
void Owner::Set(int key, unsigned char flag) {
    __int64 id = Decode_002672f0(key, 0, 0);
    Result* r = Find_00024280(id);
    if (r) {
        End* e = r->mid->Get_000fdc40();
        if (e)
            e->flag = flag;
    }
}


// 0x000296a0 FUN_000296a0 (158 B): equivalent/0x000296a0.cpp
// sym: ?FUN_000296a0@Group_296a0@fn_f6d645d0@@QAEXPBD0H@Z @f9669282e2bf @w00b0ab450c46
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 10/10)
// FUN_000296a0 @ 0x000296a0
// Group method: copy a value taken from a named pawn (or, failing that, a spawned prop)
// into the first pawn's controller and raise the controller's mode to at least 3.
void Group_296a0::FUN_000296a0(const char *nameA, const char *nameB, int flag)
{
    Pawn_296a0 *pawn = FUN_00024280(FUN_002672f0(nameA, 0, 0));
    if (pawn) {
        int value = 0;
        Pawn_296a0 *other = FUN_00024280(FUN_002672f0(nameB, 0, 0));
        if (other) {
            value = other->value;
        } else {
            Prop_296a0 *prop = env->manager->FUN_001def30(nameB);
            if (prop)
                value = ((int)((owners::C_1d72e0 *)prop)->FUN_001d72e0());
        }
        Controller_296a0 *c = pawn->controller;
        if (c) {
            c->value = value;
            c->flag = flag;
            c->dirty = 1;
            if (c->GetMode() < 3)
                c->SetMode(3);
        }
    }
}


// 0x00029740 FUN_00029740 (210 B): matches/0x00029740.cpp
// sym: ?FUN_00029740@Group_29740@fn_f6d645d0@@QAEXPBD0MM@Z
// FUN_00029740 @ 0x00029740
// Group method: look up a named pawn and a named object, and start the pawn's controller on a
// path between two of the object's points (clears the controller's dirty flag for an empty name).
void Group_29740::FUN_00029740(const char *pawnName, const char *objectName, float a, float b)
{
    struct Frame {
        Vec3_29740 target;
        Vec3_29740 pos;
    } fr;
    Pawn_29740 *pawn = FUN_00024280(FUN_002672f0(pawnName, 0, 0));
    if (!pawn)
        return;
    if (!env->finder)
        return;
    Controller_29740 *c = pawn->controller;
    if (!c)
        return;
    if (!objectName || !*objectName) {
        c->dirty = 0;
        return;
    }
    Object *obj = env->finder->FUN_001fd780(objectName);
    if (!obj)
        return;
    obj->GetPos(&fr.pos);
    obj->GetTarget(&fr.target);
    c->path.FUN_00025a20(FUN_0027b020(objectName), &fr.pos, &fr.target, a, b);
    c->dirty = 1;
    if (c->GetMode() < 3)
        c->SetMode(3);
}


// 0x00029820 FUN_00029820 (109 B): matches/0x00029820.cpp
// sym: ?FUN_00029820@ThisWrap_00029820@fn_f6d645d0@@QAE_NPBD0@Z
// FUN_00029820 @ 0x00029820
bool ThisWrap_00029820::FUN_00029820(const char *a, const char *b) {
    if (a == 0 || a[0] == 0 || b == 0 || b[0] == 0)
        return false;
    Holder_29820 *h = ((Holder_29820 *)((owners::Obj_259f0 *)this)->FUN_000259f0((hulk_intptr)a));
    if (h == 0)
        return false;
    Owner_29820 *o = h->owner;
    if (o == 0)
        return false;
    if (o->hasId) {
        unsigned int lo = o->idLo;
        unsigned int hi = o->idHi;
        Id64_29820 id;
        id.q = FUN_0027b020(b);
        if (lo == id.w[0] && hi == id.w[1])
            return true;
    }
    return false;
}

} // namespace fn_f6d645d0

// 0x00029890 FUN_00029890 (54 B): matches/0x00029890.cpp [wrapped: conflict: Sub; make]
// sym: ?func@Handler@fn_00029890@@QAEXI@Z
namespace fn_00029890 {
struct Sub {
    char pad[0x9e];
    char flag;
};
struct Obj {
    char pad[0x1ca0];
    Sub* sub;
};
unsigned __int64 __cdecl make_002672f0(unsigned, unsigned, unsigned);
class Handler {
  public:
    Obj* find_00024280(unsigned, unsigned);
    void func(unsigned x);
};
void Handler::func(unsigned x) {
    unsigned __int64 p = make_002672f0(x, 0, 0);
    Obj* o = find_00024280((unsigned)p, (unsigned)(p >> 32));
    if (o && o->sub)
        o->sub->flag = 0;
}
} // namespace fn_00029890


// 0x000298d0 FUN_000298d0 (57 B): matches/0x000298d0.cpp [wrapped: conflict: Sub]
// sym: ?set@Host@fn_000298d0@@QAEXPBDD@Z
namespace fn_000298d0 {
struct Obj {
    char pad[0x1ca0];
    struct Sub* sub;
};
struct Sub {
    char pad[0x128];
    char flag;
};
struct Host {
    Obj* lookup_00024280(unsigned a, unsigned b);
    void set(char const* name, char flag);
};
extern "C++" unsigned __int64 __cdecl hash_002672f0(char const*, unsigned, unsigned);
void Host::set(char const* name, char flag) {
    unsigned __int64 a = hash_002672f0(name, 0, 0);
    Obj* o = lookup_00024280((unsigned)a, (unsigned)(a >> 32));
    if (o && o->sub)
        o->sub->flag = flag;
}
} // namespace fn_000298d0


// 0x00029910 FUN_00029910 (59 B): matches/0x00029910.cpp [wrapped: conflict: make]
// sym: ?fn@Owner@fn_00029910@@QAEXIH@Z
namespace fn_00029910 {
typedef unsigned __int64 U64;
struct V {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void run(int);
};
struct Obj {
    char pad[0x1ca0];
    V* v;
};
extern "C++" U64 __cdecl make_002672f0(unsigned, unsigned, hulk_uintptr);
class Owner {
  public:
    Obj* lookup_00024280(U64);
    void fn(unsigned a, int b);
};
void Owner::fn(unsigned a, int b) {
    Obj* p = lookup_00024280(make_002672f0(a, 0, 0));
    if (!p)
        return;
    V* v = p->v;
    if (!v)
        return;
    v->run(b);
}
} // namespace fn_00029910


// 0x00029950 FUN_00029950 (60 B): matches/0x00029950.cpp [wrapped: conflict: Item]
// sym: ?get@Holder@fn_00029950@@QAEHH@Z
namespace fn_00029950 {
struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int index();
};
struct Node {
    char pad[0x1ca0];
    Item* item;
};
struct Holder {
    Node* lookup_00024280(unsigned __int64);
    int get(int x);
};
extern "C++" unsigned __int64 __cdecl makekey_002672f0(int, int, int);
int Holder::get(int x) {
    unsigned __int64 key = makekey_002672f0(x, 0, 0);
    Node* n = lookup_00024280(key);
    if (!n)
        return -1;
    Item* i = n->item;
    if (!i)
        return -1;
    return i->index();
}
} // namespace fn_00029950

namespace fn_f6d645d0 {

// 0x00029990 FUN_00029990 (189 B): equivalent/0x00029990.cpp
// sym: ?FUN_00029990@Target_29990@fn_f6d645d0@@QAEHXZ @bc5251c34ba1 @w773b03a32521
// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 21/22, incomplete)
// FUN_00029990 @ 0x00029990
int Target_29990::FUN_00029990() { int best=0; int n=count; Output_29990 output; for(int i=0;i<n;++i) { if(i>=0 && i<count) { Entity* e=((Entity *)((owners::ThisWrap_00059c10 *)(owner->manager))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i]))); if(e) { e->info->FUN_00059a50(&output); if(e->flag338==0 && e->flag334==0 && !(e->amount<=0.0f) && !e->FUN_00035ab0()) { Value_29990* v=e->value; if(v && v->v9()>best) best=v->v9(); } } } } return best; }

} // namespace fn_f6d645d0

// 0x00029a50 FUN_00029a50 (60 B): matches/0x00029a50.cpp [wrapped: conflict: Owner]
// sym: ?FUN_00029a50@Owner@fn_00029a50@@QAEEPAX@Z
namespace fn_00029a50 {
struct Part {
    char reserved[0x45];
    unsigned char flag;
};
struct Inner {
    char reserved[0x58];
    Part part;
};
struct Node {
    char reserved[0x1ca0];
    Inner* inner;
};
long long __cdecl FUN_002672f0(void*, int, int);
struct Owner {
    Node* FUN_00024280(long long);
    unsigned char FUN_00029a50(void*);
};
unsigned char Owner::FUN_00029a50(void* value) {
    long long result = FUN_002672f0(value, 0, 0);
    Node* node = FUN_00024280(result);
    if (!node)
        return 0;
    Inner* inner = node->inner;
    if (!inner)
        return 0;
    Part* part = &inner->part;
    if (!part)
        return 0;
    return part->flag;
}
} // namespace fn_00029a50


// 0x00029a90 FUN_00029a90 (191 B): equivalent/0x00029a90.cpp [wrapped: conflict: Object]
// sym: ?FUN_00029a90@Object@fn_00029a90@@QAE_NXZ @1cb5171f2e37 @waba15194ad95
namespace fn_00029a90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00029a90 @ 0x00029a90

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

struct Vec3_29a90 { float x,y,z; };
struct Owner_29a90 { char pad[0x328]; int identifier; void FUN_000350c0(Vec3_29a90* out); };
extern void __cdecl FUN_00096a90(void* object, Vec3_29a90* out);
struct Object {
 char pad0[0x124]; Owner_29a90* owner;
 char pad1[0x330-0x128]; Vec3_29a90 center; float radius;
 char pad2[4]; void* object; int identifier; float alternateRadius;
 bool FUN_00029a90();
};
bool Object::FUN_00029a90() {
 if (!owner) return true;
 Vec3_29a90 position = {0.0f,0.0f,0.0f};
 float r;
 if(object && identifier == owner->identifier) {
  FUN_00096a90(object, &position);
  r=alternateRadius;
 } else {
  owner->FUN_000350c0(&position);
  r=radius;
 }
 double dx = (double)position.x-center.x;
 double dy = (double)position.y-center.y;
 double dz = (double)position.z-center.z;
 return sqrt(dz*dz+dx*dx+dy*dy)<=r;
}
} // namespace fn_00029a90

namespace fn_f6d645d0 {

// 0x00029b50 FUN_00029b50 (89 B): matches/0x00029b50.cpp
// sym: ?Set@Owner_29b50@fn_f6d645d0@@QAEXPAVRef_29b50@2@0H@Z
void Owner_29b50::Set(Ref_29b50* x, Ref_29b50* y, int z) {
    if (x)
        x->Add();
    if (a)
        a->Release();
    a = x;
    if (y)
        y->Add();
    if (b)
        b->Release();
    _ReadWriteBarrier();
    b = y;
    c = z;
}


// 0x00029bb0 FUN_00029bb0 (66 B): matches/0x00029bb0.cpp
// sym: ?Set@Owner_29bb0@fn_f6d645d0@@QAEXHPAVThing_29bb0@2@H@Z
void Owner_29bb0::Set(int k, Thing_29bb0* t, int v) {
    if (k == key) {
        if (t)
            t->A();
        if (current)
            current->B();
        current = t;
        value = v;
    }
}


// 0x00029c00 FUN_00029c00 (75 B): equivalent/0x00029c00.cpp
// sym: ?FUN_00029c00@Owner@fn_f6d645d0@@QAEXPAUResource@2@@Z @683a508c6c86 @w4dbbce2477d7
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00029c00 @ 0x00029c00
void Owner::FUN_00029c00(Resource *item) { if (item == primary) { if (primary) { primary->slot1(); primary = 0; } if (secondary) { secondary->slot1(); secondary = 0; } state = 0; } }

} // namespace fn_f6d645d0

// 0x00029c50 FUN_00029c50 (49 B): matches/0x00029c50.cpp [wrapped: conflict: Hash]
// sym: ?Fn@X@fn_00029c50@@QAEXHH@Z
namespace fn_00029c50 {
struct Item {
};
struct X {
    Item* Get_00024280(unsigned __int64);
    void Fn(int id, int arg);
};
extern "C++" unsigned __int64 __cdecl Hash_002672f0(int, int, int);
void X::Fn(int id, int arg) {
    unsigned __int64 v = Hash_002672f0(id, 0, 0);
    Item* p = Get_00024280(v);
    if (p)
        ((owners::C_36d40 *)p)->FUN_00036d40(arg);
}
} // namespace fn_00029c50


// 0x00029c90 FUN_00029c90 (49 B): matches/0x00029c90.cpp [wrapped: conflict: Owner]
// sym: ?Run@Owner@fn_00029c90@@QAEXHH@Z
namespace fn_00029c90 {
class Obj {
  public:
    void Apply_000361c0(int);
};
extern "C++" __int64 __cdecl Build_002672f0(int, int, int);
class Owner {
  public:
    Obj* Find_00024280(__int64);
    void Run(int, int);
};
void Owner::Run(int a, int b) {
    __int64 v = Build_002672f0(a, 0, 0);
    Obj* p = Find_00024280(v);
    if (p)
        p->Apply_000361c0(b);
}
} // namespace fn_00029c90


// 0x00029cd0 FUN_00029cd0 (49 B): matches/0x00029cd0.cpp [wrapped: conflict: Owner]
// sym: ?Test@Owner@fn_00029cd0@@QAEDPBD@Z
namespace fn_00029cd0 {
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

struct Item {
    char Check_00036170();
};
struct Owner {
    Item* Find_00024280(__int64 value);
    char Test(const char* s);
};
char Owner::Test(const char* s) {
    __int64 x = FUN_002672f0(s, 0, 0);
    Item* p = Find_00024280(x);
    if (!p)
        return 0;
    return p->Check_00036170();
}
} // namespace fn_00029cd0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00029d10 FUN_00029d10 (49 B): matches/0x00029d10.cpp [wrapped: conflict: Hash]
// sym: ?Target@Obj@fn_00029d10@@QAEXHH@Z
namespace fn_00029d10 {
struct Item {
    void Do_00036140(int);
};
struct Obj {
    Item* Get_00024280(__int64);
    void Target(int, int);
};
extern "C++" __int64 __cdecl Hash_002672f0(int, int, int);
void Obj::Target(int a, int b) {
    __int64 h = Hash_002672f0(a, 0, 0);
    Item* p = Get_00024280(h);
    if (p)
        p->Do_00036140(b);
}
} // namespace fn_00029d10

namespace fn_f6d645d0 {

// 0x00029d50 FUN_00029d50 (49 B): matches/0x00029d50.cpp
// sym: ?Fn@Owner@fn_f6d645d0@@QAEDI@Z
char Owner::Fn(unsigned x) {
    unsigned __int64 v = External_002672f0(x, 0, 0);
    Result* r = Get_00024280((unsigned)v, (unsigned)(v >> 32));
    if (!r)
        return 0;
    return r->Check_000360f0();
}

} // namespace fn_f6d645d0

// 0x00029d90 FUN_00029d90 (61 B): matches/0x00029d90.cpp [wrapped: conflict: Obj]
// sym: ?Fn@Obj@fn_00029d90@@QAEXHH@Z
namespace fn_00029d90 {
struct Result {
    void FnA_000361c0(int);
    void FnB_00036140(int);
};
struct Obj {
    Result* Find_00024280(unsigned __int64);
    void Fn(int, int);
};
extern "C++" unsigned __int64 __cdecl Convert(int, int, int);
void Obj::Fn(int x, int y) {
    unsigned __int64 n = Convert(x, 0, 0);
    Result* r = Find_00024280(n);
    if (r) {
        r->FnA_000361c0(y);
        r->FnB_00036140(y);
    }
}
} // namespace fn_00029d90


// 0x00029dd0 FUN_00029dd0 (69 B): matches/0x00029dd0.cpp [wrapped: conflict: I64; Parse]
// sym: ?Check@Holder@fn_00029dd0@@QAEDPAX@Z
namespace fn_00029dd0 {
typedef long long I64;
extern "C++" I64 __cdecl Parse_002672f0(void*, int, int);
class Item {
  public:
    char FnA_00036170();
    char FnB_000360f0();
};
class Holder {
  public:
    Item* Find_00024280(I64);
    char Check(void*);
};
char Holder::Check(void* p) {
    I64 v = Parse_002672f0(p, 0, 0);
    Item* x = Find_00024280(v);
    if (x && x->FnA_00036170() && x->FnB_000360f0())
        return 1;
    return 0;
}
} // namespace fn_00029dd0


// 0x00029e20 FUN_00029e20 (49 B): matches/0x00029e20.cpp [wrapped: conflict: Obj; Obj::Run]
// sym: ?Run@Obj@fn_00029e20@@QAEXHH@Z
namespace fn_00029e20 {
class Item {
  public:
    void Apply_000361f0(int);
};
class Obj {
  public:
    Item* Lookup_00024280(__int64);
    void Run(int key, int value);
};
extern "C++" __int64 __cdecl GetPair_002672f0(int, int, int);
void Obj::Run(int key, int value) {
    __int64 pair = GetPair_002672f0(key, 0, 0);
    Item* item = Lookup_00024280(pair);
    if (item)
        item->Apply_000361f0(value);
}
} // namespace fn_00029e20


// 0x00029e60 FUN_00029e60 (57 B): matches/0x00029e60.cpp [wrapped: conflict: Lookup]
// sym: ?Check@Obj@fn_00029e60@@QAE_NPAX@Z
namespace fn_00029e60 {
extern "C++" __int64 __cdecl Lookup_002672f0(void*, int, int);
struct Item {
    char pad[0x1b20];
    int count;
};
class Obj {
  public:
    Item* Find_00024280(__int64);
    bool Check(void*);
};
bool Obj::Check(void* p) {
    __int64 id = Lookup_002672f0(p, 0, 0);
    Item* item = Find_00024280(id);
    if (!item)
        return false;
    return item->count > 0;
}
} // namespace fn_00029e60


// 0x00029ea0 FUN_00029ea0 (48 B): matches/0x00029ea0.cpp [wrapped: conflict: Fetch; Item; Obj; Obj::Check]
// sym: ?Check@Obj@fn_00029ea0@@QAEEPAX@Z
namespace fn_00029ea0 {
typedef __int64 i64;
struct Item {
    char pad[0x32c];
    char flag;
};
extern "C++" i64 __cdecl Fetch_002672f0(void*, int, int);
class Obj {
  public:
    Item* Find_00024280(i64);
    unsigned char Check(void*);
};
unsigned char Obj::Check(void* p) {
    i64 value = Fetch_002672f0(p, 0, 0);
    Item* item = Find_00024280(value);
    if (!item)
        return 0;
    return item->flag;
}
} // namespace fn_00029ea0


// 0x00029ed0 FUN_00029ed0 (68 B): matches/0x00029ed0.cpp [wrapped: conflict: Obj]
// sym: ?Read@Holder@fn_00029ed0@@QAEMH@Z
namespace fn_00029ed0 {
extern "C++" __int64 __cdecl Lookup(int, int, int);
class Obj {
  public:
    char pad[0x328];
    unsigned int value;
};
class Holder {
  public:
    Obj* Get_00024280(__int64);
    hulk_freg Read(int);
};
hulk_freg Holder::Read(int id) {
    __int64 key = Lookup(id, 0, 0);
    Obj* p = Get_00024280(key);
    if (!p)
        return 0.0f;
    return (hulk_freg)p->value;     // x87: fild of the unsigned value, returned unrounded
}
} // namespace fn_00029ed0

namespace fn_f6d645d0 {

// 0x00029f20 FUN_00029f20 (145 B): equivalent/0x00029f20.cpp
// sym: ?FUN_00029f20@Group_29f20@fn_f6d645d0@@QAEMPBD0@Z @6a92503ef1e1 @wc41ea5abf3a7
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 8/8)
// FUN_00029f20 @ 0x00029f20
// Distance between two named pawns (-1 when either is missing or has no position).
hulk_freg Group_29f20::FUN_00029f20(const char *nameA, const char *nameB)
{
    struct Frame {
        Vec3_29f20 b;
        Vec3_29f20 a;
    } fr;
    Pawn_29f20 *pa = FUN_00024280(FUN_002672f0(nameA, 0, 0));
    if (pa) {
        Pawn_29f20 *pb = FUN_00024280(FUN_002672f0(nameB, 0, 0));
        if (pb && pa->body->FUN_00059a50(&fr.a) && pb->body->FUN_00059a50(&fr.b))
            return FUN_00025990(&fr.a, &fr.b);
    }
    return -1.0f;
}

} // namespace fn_f6d645d0

// 0x00029fc0 FUN_00029fc0 (53 B): matches/0x00029fc0.cpp [wrapped: conflict: Item]
// sym: ?check@Obj@fn_00029fc0@@QAEDPAX@Z
namespace fn_00029fc0 {
typedef unsigned __int64 U64;
extern U64 __cdecl lookup_002672f0(void*, int, int);
struct Item {
    char pad[0x1b28];
    void* value;
};
class Obj {
  public:
    Item* fetch_00024280(U64);
    char check(void*);
};
char Obj::check(void* p) {
    U64 id = lookup_002672f0(p, 0, 0);
    Item* item = fetch_00024280(id);
    if (!item)
        return 0;
    return item->value != 0;
}
} // namespace fn_00029fc0


// 0x0002a000 FUN_0002a000 (48 B): matches/0x0002a000.cpp [wrapped: conflict: Result; lookup]
// sym: ?fn@X@fn_0002a000@@QAEEH@Z
namespace fn_0002a000 {
struct Result {
    char pad[0x1f50];
    unsigned char value;
};
struct X {
    Result* get_00024280(unsigned __int64);
    unsigned char fn(int);
};
extern "C++" unsigned __int64 __cdecl lookup_002672f0(int, int, int);
unsigned char X::fn(int a) {
    unsigned __int64 v = lookup_002672f0(a, 0, 0);
    Result* p = get_00024280(v);
    if (!p)
        return 0;
    return p->value;
}
} // namespace fn_0002a000


// 0x0002a030 FUN_0002a030 (47 B): matches/0x0002a030.cpp [wrapped: conflict: Result]
// sym: ?Func@X@fn_0002a030@@QAEXHD@Z
namespace fn_0002a030 {
struct Result {
    char pad[0x1f50];
    char flag;
};
struct X {
    Result* Make_00024280(unsigned int, unsigned int);
    void Func(int v, char flag);
};
extern "C++" unsigned __int64 __cdecl Other_002672f0(int, int, int);
void X::Func(int v, char flag) {
    unsigned __int64 n = Other_002672f0(v, 0, 0);
    Result* p = Make_00024280((unsigned int)n, (unsigned int)(n >> 32));
    if (p)
        p->flag = flag;
}
} // namespace fn_0002a030


// 0x0002a060 FUN_0002a060 (58 B): matches/0x0002a060.cpp [wrapped: conflict: FUN_002672f0]
// sym: ?Check@Holder@fn_0002a060@@QAE_NH@Z
namespace fn_0002a060 {
struct Obj {
    char pad[0x140];
    int state;
};
struct Holder {
  public:
    Obj* Get_00024280(unsigned long long);
    bool Check(int);
};
extern "C++" unsigned long long __cdecl FUN_002672f0(int, int, int);
bool Holder::Check(int x) {
    unsigned long long v = FUN_002672f0(x, 0, 0);
    Obj* o = Get_00024280(v);
    if (!o)
        return false;
    return o->state != 3;
}
} // namespace fn_0002a060

namespace fn_f6d645d0 {

// 0x0002a0a0 FUN_0002a0a0 (49 B): matches/0x0002a0a0.cpp
// sym: ?fn@X@fn_f6d645d0@@QAEXHUVec3_2a0a0@2@@Z
// b..d: a 3-word vector passed by value.
void X::fn(int a, Vec3_2a0a0 b) {
    unsigned __int64 key = makekey_002672f0(a, 0, 0);
    Result* r = find_00024280(key);
    if (r)
        r->get_00035760(&b);
}


// 0x0002a0e0 FUN_0002a0e0 (184 B): equivalent/0x0002a0e0.cpp
// sym: ?FUN_0002a0e0@Group_2a0e0@fn_f6d645d0@@QAEDTNameSlot_2a0e0@2@MMMMMM@Z @2e01ba03f136 @wd13928021128
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0002a0e0 @ 0x0002a0e0
// Group method: look up a named pawn and run a collision sweep between two points, caching the result.
char Group_2a0e0::FUN_0002a0e0(NameSlot_2a0e0 name, float fx, float fy, float fz, float tx, float ty, float tz)
{
    Pawn_2a0e0 *pawn = FUN_00024280(FUN_002672f0(name.name, 0, 0));
    if (!pawn)
        return 0;
    active = 1;
    from.x = fx;
    from.y = fy;
    from.z = fz;
    to.x = tx;
    to.y = ty;
    to.z = tz;
    int foreign = 0;
    if (pawn != current)
        foreign = 1;
    Vec3_2a0e0 normal;
    name.out = 0;
    hit = ((char)((owners::Obj_38de0 *)pawn)->FUN_00038de0((hulk_uintptr)(Vec3_2a0e0 *)(&from), (hulk_uintptr)(Vec3_2a0e0 *)(&to), 0, (unsigned int)foreign, (hulk_uintptr)(HitExtra_2a0e0 *)(&extra), (hulk_uintptr)(Vec3_2a0e0 *)(&normal), (hulk_uintptr)(&name.out), (hulk_uintptr)0));
    return hit;
}

} // namespace fn_f6d645d0

// 0x0002a1a0 FUN_0002a1a0 (86 B): matches/0x0002a1a0.cpp [wrapped: conflict: Pair]
// sym: ?Fn@C@fn_0002a1a0@@QAEPAMPBD@Z
namespace fn_0002a1a0 {
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

struct Pair {
    char pad[8];
    int a, b;
};
extern "C++" void __cdecl FUN_00096d50(void*, int, int, int);
class C {
  public:
    float* Fn(const char*);
    Pair* Make_00024280(__int64);
};
float* C::Fn(const char* s) {
    __int64 v = FUN_002672f0(s, 0, 0);
    Pair* p = Make_00024280(v);
    if (p)
        p = ((Pair *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)0));
    if (!p)
        return ((float*)&DAT_003f335c);
    FUN_00096d50(((char*)&DAT_004dc268), 0x20, p->a, p->b);
    return (float*)&(*(char*)&DAT_004dc268);
}
} // namespace fn_0002a1a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0002a200 FUN_0002a200 (65 B): matches/0x0002a200.cpp [wrapped: conflict: Lookup; Owner; Owner::Query; Result]
// sym: ?Query@Owner@fn_0002a200@@QAEPAMH@Z
namespace fn_0002a200 {
extern "C++" unsigned __int64 __cdecl Lookup(int, int, int);
extern float fallback;
class Result {
  public:
    float* Get_0027b000();
};
class Owner {
  public:
    Result* Find_00024280(unsigned __int64);
    float* Query(int);
};
float* Owner::Query(int id) {
    unsigned __int64 key = Lookup(id, 0, 0);
    Result* r = Find_00024280(key);
    if (!r)
        return &fallback;
    r = ((Result *)((owners::C_35ef0 *)r)->FUN_00035ef0((hulk_intptr)0));
    if (!r)
        return &fallback;
    return r->Get_0027b000();
}
} // namespace fn_0002a200


// 0x0002a250 FUN_0002a250 (94 B): matches/0x0002a250.cpp [wrapped: conflict: Hash; Parse]
// sym: ?Match@Owner_2a250@fn_0002a250@@QAEDPBD0@Z
namespace fn_0002a250 {
struct Pair_2a250 {
    unsigned a, b;
};
struct Item_2a250 {
    char pad[8];
    unsigned a, b;
};
struct Owner_2a250 {
  public:
    Item_2a250* Get_00024280(unsigned, unsigned);
    char Match(const char*, const char*);
};
extern "C++" Pair_2a250 __cdecl Parse_002672f0(const char*, int, int);
extern "C++" Pair_2a250 __cdecl Hash_0027b020(const char*);
char Owner_2a250::Match(const char* s, const char* t) {
    Pair_2a250 p = Parse_002672f0(s, 0, 0);
    Item_2a250* q = Get_00024280(p.a, p.b);
    if (!q)
        return 0;
    q = ((Item_2a250 *)((owners::C_35ef0 *)q)->FUN_00035ef0((hulk_intptr)0));
    if (!q)
        return 0;
    unsigned a = q->a, b = q->b;
    Pair_2a250 h = Hash_0027b020(t);
    return a == h.a && b == h.b;
}
} // namespace fn_0002a250


// 0x0002a2b0 FUN_0002a2b0 (94 B): matches/0x0002a2b0.cpp [wrapped: conflict: Decode]
// sym: ?Fn@C_2a2b0@fn_0002a2b0@@QAEPAMH@Z
namespace fn_0002a2b0 {
struct Vec_2a2b0 {
    unsigned a, b;
};
struct Sub_2a2b0 {
    int Lookup_001d5dd0(int);
};
struct Obj_2a2b0 {
    char pad[0x40];
    int id;
    char pad2[0xa8];
    Sub_2a2b0* ptr;
};
extern "C++" Vec_2a2b0 __cdecl Decode_002672f0(int, int, int);
extern float* hulk_at_004c6028[];
extern float zero_2a2b0;
class C_2a2b0 {
  public:
    Obj_2a2b0* Find_00024280(unsigned, unsigned);
    float* Fn(int);
};
float* C_2a2b0::Fn(int x) {
    Vec_2a2b0 v = Decode_002672f0(x, 0, 0);
    Obj_2a2b0* o = Find_00024280(v.a, v.b);
    if (!o)
        return &zero_2a2b0;
    o = ((Obj_2a2b0 *)((owners::C_35ef0 *)o)->FUN_00035ef0((hulk_intptr)0));
    if (!o)
        return &zero_2a2b0;
    Sub_2a2b0* p = o->ptr;
    if (!p)
        return &zero_2a2b0;
    int id = o->id;
    int n = p->Lookup_001d5dd0(id);
    if (n < 1 || n >= 7)
        return &zero_2a2b0;
    return hulk_at_004c6028[n];
}
} // namespace fn_0002a2b0


// 0x0002a310 FUN_0002a310 (52 B): matches/0x0002a310.cpp [wrapped: conflict: Obj; Pair]
// sym: ?run@Obj@fn_0002a310@@QAEXH@Z
namespace fn_0002a310 {
struct Pair {
    unsigned a, b;
};
Pair __cdecl findPair_002672f0(int, int, int);
class Obj {
  public:
    Obj* get_00024280(unsigned a, unsigned b);
    void act_0003b620(int);
    void run(int x);
};
void Obj::run(int x) {
    Pair p = findPair_002672f0(x, 0, 0);
    Obj* q = get_00024280(p.a, p.b);
    if (q)
        q->act_0003b620(1);
}
} // namespace fn_0002a310


// 0x0002a350 FUN_0002a350 (44 B): matches/0x0002a350.cpp [wrapped: conflict: make]
// sym: ?target@Foo@fn_0002a350@@QAEXPAX@Z
namespace fn_0002a350 {
class Bar {
  public:
    void act_000401a0();
};
extern "C++" __int64 __cdecl make_002672f0(void*, int, hulk_intptr);
class Foo {
  public:
    Bar* get_00024280(__int64);
    void target(void*);
};
void Foo::target(void* p) {
    __int64 v = make_002672f0(p, 0, 0);
    Bar* b = get_00024280(v);
    if (b)
        b->act_000401a0();
}
} // namespace fn_0002a350

namespace fn_f6d645d0 {

// 0x0002a380 FUN_0002a380 (49 B): matches/0x0002a380.cpp
// sym: ?FUN_0002a380@fn_f6d645d0@@YAMPBUVec@1@0@Z
hulk_freg __cdecl FUN_0002a380(const Vec* a, const Vec* b) {
    hulk_freg x = a->x - b->x;
    hulk_freg y = a->y - b->y;
    hulk_freg z = a->z - b->z;
    return (hulk_freg)sqrt(y * y + (x * x + z * z));
}


// 0x0002a800 FUN_0002a800 (131 B): equivalent/0x0002a800.cpp
// sym: ?FUN_0002a800@ItemList_2a800@fn_f6d645d0@@QAE_NXZ @a976e9871b39 @w8cd5f4e6e74d
// STATUS: equivalent (tools/equiv.py level 3: 1354 inputs, branch coverage 8/10, incomplete)
// FUN_0002a800 @ 0x0002a800
bool ItemList_2a800::FUN_0002a800()
{
    if (resource != 0) {
        resource->Release();
        resource = 0;
        Resource_2a800 * arg1_ = resource;
        FUN_001b6580()->FUN_001b4c40(arg1_);
    }

    for (int i = count - 1; i >= 0; i--) {
        context->slot->FUN_00059c10(items[i])->FUN_00036d40(0);
        FUN_0002a4b0(i, 0);
    }
    return true;
}


// 0x0002a890 FUN_0002a890 (196 B): equivalent/0x0002a890.cpp
// sym: ?FUN_0002a890@Target_2a890@fn_f6d645d0@@QAEXXZ @cde2cd08d43b @wf62884a74f74
// STATUS: equivalent (tools/equiv.py level 3: 132 inputs, branch coverage 16/18, incomplete)
// FUN_0002a890 @ 0x0002a890
void Target_2a890::FUN_0002a890() {
 for (int i = 0; i < count; ++i) {
  if (i >= 0 && i < count) {
   Item_2a890* item = ((Item_2a890 *)((owners::ThisWrap_00059c10 *)(owner->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
   if (item) item->FUN_0003b620(1);
  }
 }
 FUN_0002a800();
 component->FUN_00044c30();
 component->FUN_00046230();
 Manager_2a890* manager = (*(Manager_2a890**)&DAT_004e5af8);
 int n = manager->FUN_002327c0();
 for (int j = 0; j < n; ++j) {
  Interface_2a890* object = manager->FUN_00232810(j)->object;
  object->slot6();
  object->slot7();
 }
 if (resource1) { resource1->release(); resource1 = 0; }
 if (resource2) { resource2->release(); resource2 = 0; }
}


// 0x0002a960 FUN_0002a960 (465 B): equivalent/0x0002a960.cpp
// sym: ?FUN_0002a960@SpawnWatcher@fn_f6d645d0@@QAEXPAUContext@2@@Z @ecaf266a628b @wf7ac8e61f863
// STATUS: equivalent (tools/equiv.py level 3: 402 inputs, branch coverage 32/32)
// FUN_0002a960 @ 0x0002a960
void SpawnWatcher::FUN_0002a960(Context *ctx)
{
    for (int i = count - 1; i >= 0; i--) {
        state[i] = 0;
        Fighter_2a960 *f = ((Fighter_2a960 *)((owners::ThisWrap_00059c10 *)(ctx->roster))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
        if (f == self)
            continue;
        unsigned __int64 nm = f->name->FUN_000443c0();
        unsigned __int64 harrier = FUN_0027b020("harrier");
        if (nm == harrier)
            continue;
        if (f->flag1cf5 != 0)
            continue;
        Frame_2a960 fr;
        if (!f->body->FUN_00059a50(&fr.pos))
            continue;
        Zone_2a960 *zone = ((Zone_2a960 *)FUN_000862a0(ctx->holder))->FUN_00204200(fr.pos.x, fr.pos.y, fr.pos.z);
        bool a = FUN_000862a0(ctx->holder)->FUN_00204440((Zone_2a960 *)zone);
        bool b = ((owners::C_204470 *)(FUN_000862a0(ctx->holder)))->FUN_00204470((hulk_intptr)(Zone_2a960 *)((Zone_2a960 *)zone));
        if (a)
            continue;
        if (b) {
            state[i] = 1;
            continue;
        }
        if (self != 0 && self->body->FUN_00059a50(&fr.other)) {
            fr.delta.x = fr.pos.x - fr.other.x;
            fr.delta.y = 0;
            fr.delta.z = fr.pos.z - fr.other.z;
            if (fr.delta.FUN_000111f0() <= 56700.0f && f->flag1d05 == 0)
                continue;
        }
        if (f->flag1cf4) {
            state[i] = 1;
        } else if (f->flag119 == 0 && f->flag1d78 == 0) {
            FUN_0002a4b0(i, 0);
        }
    }
}


// 0x0002ab40 FUN_0002ab40 (825 B): equivalent/0x0002ab40.cpp
// sym: ?FUN_0002ab40@AgentSet@fn_f6d645d0@@QAEXHH@Z @b600bfb3d999 @w9fe543400b93
// STATUS: equivalent (tools/equiv.py level 3: 3029 inputs, branch coverage 68/68)
// FUN_0002ab40 @ 0x0002ab40
// FUN_0002ab40 @ 0x0002ab40
void AgentSet::FUN_0002ab40(hulk_intptr a0, hulk_intptr a1)
{
    FUN_0002a960(a0);
    FUN_00025ff0(a0, a1);
    for (int i = 0; i < count; i++) {
        if ((flags[i] & 1) || modes[i] != 0) {
            Agent_2ab40 *agent = ((Agent_2ab40 *)((owners::ThisWrap_00059c10 *)(registry->lookup))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
            if (agent)
                agent->FUN_000363f0(a0, args[i]);
        }
    }
    for (int i = 0; i < count; i++) {
        if ((flags[i] & 1) || modes[i] != 0) {
            Agent_2ab40 *agent = ((Agent_2ab40 *)((owners::ThisWrap_00059c10 *)(registry->lookup))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
            if (agent)
                agent->FUN_00036430(a0, args[i]);
        }
    }
    for (int i = 0; i < count; i++) {
        if ((flags[i] & 1) || modes[i] != 0) {
            Agent_2ab40 *agent = ((Agent_2ab40 *)((owners::ThisWrap_00059c10 *)(registry->lookup))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
            if (agent)
                agent->FUN_0003b7d0(a0, args[i]);
        }
    }
    for (int i = 0; i < count; i++) {
        Agent_2ab40 *agent = ((Agent_2ab40 *)((owners::ThisWrap_00059c10 *)(registry->lookup))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
        if ((flags[i] & 1) && modes[i] == 0) {
            if (agent)
                agent->FUN_00040970(a0, args[i]);
        } else if (agent) {
            Vec3_2ab40 dir;
            dir.x = 0;
            dir.y = 0;
            dir.z = 0;
            if (modes[i] == 0) {
                agent->FUN_00035660(&dir);
                if (sqrt(dir.z * dir.z + dir.y * dir.y + dir.x * dir.x) > 50.0f) {
                    dir.FUN_0022d110();
                    dir.x = dir.x * 50.0f;
                    dir.y = dir.y * 50.0f;
                    dir.z = dir.z * 50.0f;
                }
            } else if (modes[i] == 1) {
                Selector_2ab40 *sel = agent->selector;
                if (sel) {
                    char armed = sel->armed;
                    int current = ((owners::C_fdc80 *)sel)->FUN_000fdc80();
                    int found = sel->FUN_000fdc40();
                    if (agent->forced || (current != 0 && current == found && armed)) {
                        // x uses the unrounded product, y and z the value rounded to float.
                        volatile float s;
                        dir.x = agent->dirX * (agent->gain * agent->dirScale);
                        s = agent->gain * agent->dirScale;
                        dir.y = agent->dirY * s;
                        dir.z = agent->dirZ * s;
                    }
                }
            }
            agent->FUN_0003e2a0(a0, dir, a1, args[i], (flags[i] >> 1) & 0xffffff01u);
        }
    }
    for (int i = 0; i < count; i++) {
        if ((flags[i] & 1) && modes[i] == 0) {
            Agent_2ab40 *agent = ((Agent_2ab40 *)((owners::ThisWrap_00059c10 *)(registry->lookup))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
            if (agent)
                ((owners::C_42930 *)agent)->FUN_00042930(a0, args[i]);
        }
    }
}


// 0x0002b250 FUN_0002b250 (188 B): equivalent/0x0002b250.cpp
// sym: ?FUN_0002b250@Container_2b250@fn_f6d645d0@@QAEHHH@Z @0fe9c0423d52 @wc2682a872409
// STATUS: equivalent (tools/equiv.py level 3: 140 inputs, branch coverage 14/14)
// FUN_0002b250 @ 0x0002b250
int Container_2b250::FUN_0002b250(int desired, int filter) {
 int capacity = 32 - used;
 int needed = desired - capacity;
 if (needed <= 0) return capacity;
 int index = count - 1;
 Item_2b250* savedExcluded = excluded;
 int added = 0;
 for (; index >= 0 && added < needed; --index) {
  Item_2b250* item = ((Item_2b250 *)((owners::ThisWrap_00059c10 *)(owner->manager))->FUN_00059c10((void *)(hulk_uintptr)(int)(handles[index])));
  if (item != savedExcluded && ((owners::A_36950 *)item)->FUN_00036950(filter) == 1) {
   if (FUN_00024720(item->value8, item->valueC)) ++added;
   FUN_0002a4b0(index, 0);
  }
 }
 return 32 - used;
}


// 0x0002b310 FUN_0002b310 (101 B): matches/0x0002b310.cpp
// sym: ?FUN_0002b310@Obj_2b310@fn_f6d645d0@@QAEXHM@Z
// FUN_0002b310 @ 0x0002b310
void Obj_2b310::FUN_0002b310(int a, float degrees) {
    Vec3_2b310 v;
    v.x = (*(unsigned int*)&DAT_0048e084);
    v.y = (*(unsigned int*)&DAT_0048e088);
    v.z = (*(unsigned int*)&DAT_0048e08c);
    FUN_00224d70(degrees * 0.01745329238474369f, &v);
    FUN_00028400(a, v);
}

} // namespace fn_f6d645d0

// 0x0002b380 FUN_0002b380 (66 B): matches/0x0002b380.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?FUN_0002b380@Obj@fn_0002b380@@QAEXHHH@Z
namespace fn_0002b380 {
struct Args {
    int x, y, z;
};
struct Obj {
    void FUN_00028400(int, Args);
    void FUN_0002b380(int a, int b, int c);
};
void Obj::FUN_0002b380(int a, int b, int c) {
    volatile Args args;
    args.x = b;
    args.z = c;
    args.y = 0;
    FUN_00028400(a, *(Args*)&args);
}
} // namespace fn_0002b380

namespace fn_f6d645d0 {

// 0x0002b3d0 FUN_0002b3d0 (116 B): matches/0x0002b3d0.cpp
// sym: ?run@Obj_2b3d0@fn_f6d645d0@@QAEXXZ
void Obj_2b3d0::run() {
    int i = count - 1;
    if (i >= 0) {
        int* p = &items[i];
        do {
            Prov_2b3d0* pr = sub->prov;
            Ret_2b3d0* r = ((Ret_2b3d0 *)((owners::ThisWrap_00059c10 *)pr)->FUN_00059c10((void *)(hulk_uintptr)(int)(*p)));
            if (r && r != current) {
                ((owners::C_36d40 *)r)->FUN_00036d40(0);
                removeAt_0002a4b0(i, 0);
            }
            --i;
            --p;
        } while (i >= 0);
    }
    if (current) {
        current->FnD_0003b620(1);
        current->FnE_000401a0();
        current->m = 0;
    }
}


// 0x0002b450 FUN_0002b450 (145 B): equivalent/0x0002b450.cpp
// sym: ?FUN_0002b450@Owner_2b450@fn_f6d645d0@@QAEMPBD0@Z @6c530fc555c2 @wdfec69e33602
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 8/8)
// FUN_0002b450 @ 0x0002b450
hulk_freg Owner_2b450::FUN_0002b450(const char* nameA, const char* nameB)
{
    struct {
        Vec3_2b450 b;
        Vec3_2b450 a;
    } v;
    Entry_2b450* first = FUN_00024280(FUN_002672f0(nameA, 0, 0));
    if (first) {
        Entry_2b450* second = FUN_00024280(FUN_002672f0(nameB, 0, 0));
        if (second && first->child->FUN_00059a50(&v.a) && second->child->FUN_00059a50(&v.b)) {
            return FUN_0002a380(&v.a, &v.b);
        }
    }
    return -1.0f;
}

} // namespace fn_f6d645d0

// 0x0002b4f0 FUN_0002b4f0 (153 B): equivalent/0x0002b4f0.cpp [wrapped: conflict: Object]
// sym: ?FUN_0002b4f0@Group_2b4f0@fn_0002b4f0@@QAEMPBDH@Z @0970b2ce7658 @w74cde5e011a4
namespace fn_0002b4f0 {
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 8/8)
// FUN_0002b4f0 @ 0x0002b4f0
// Distance from a named pawn to an object found by id (-1 when either is missing).
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


struct Vec3_2b4f0 {
    float x, y, z;
};

struct Body_2b4f0 {
    bool FUN_00059a50(Vec3_2b4f0 *out);
};

struct Pawn_2b4f0 {
    char pad[0x10];
    Body_2b4f0 *body;
};

class Object {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Vec3_2b4f0 *GetPos(Vec3_2b4f0 *out);
};

struct Finder_2b4f0 {
    Object *FUN_001fd780(int key);
};

struct Env_2b4f0 {
    char pad[0x28];
    Finder_2b4f0 *finder;
};

hulk_freg __cdecl FUN_0002a380(Vec3_2b4f0 *a, Vec3_2b4f0 *b);

struct Group_2b4f0 {
    Env_2b4f0 *env;
    Pawn_2b4f0 *FUN_00024280(unsigned __int64 key);
    hulk_freg FUN_0002b4f0(const char *name, int objectKey);
};

hulk_freg Group_2b4f0::FUN_0002b4f0(const char *name, int objectKey)
{
    struct Frame {
        Vec3_2b4f0 copy;
        Vec3_2b4f0 pawnPos;
        Vec3_2b4f0 objPos;
    } fr;
    Pawn_2b4f0 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (pawn && env->finder) {
        Object *obj = env->finder->FUN_001fd780(objectKey);
        if (obj && pawn->body->FUN_00059a50(&fr.pawnPos)) {
            fr.copy = *obj->GetPos(&fr.objPos);
            return FUN_0002a380(&fr.pawnPos, &fr.copy);
        }
    }
    return -1.0f;
}
} // namespace fn_0002b4f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f6d645d0 {

// 0x0002b590 FUN_0002b590 (256 B): equivalent/0x0002b590.cpp
// sym: ?FUN_0002b590@Manager_2b590@fn_f6d645d0@@QAEXXZ @f7e973b21bfa @w15a6448d1057
// STATUS: equivalent (tools/equiv.py level 3: 437 inputs, branch coverage 28/28)
// FUN_0002b590 @ 0x0002b590
void Manager_2b590::FUN_0002b590() {
 for (int i=0;i<count;++i) {
  Item_2b590* item=((Item_2b590 *)((owners::ThisWrap_00059c10 *)(owner->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
  if(item) {
   item->FUN_00036a20();
   item->FUN_0003e640();
  }
 }
 Item_2b590* keep=preserved;
 while(count>limit) {
  int best=0x7fffffff;
  int index=-1;
  for(int j=0;j<count;++j) {
   Item_2b590* item=((Item_2b590 *)((owners::ThisWrap_00059c10 *)(owner->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[j])));
   if(item!=keep && !item->protectedFlag && item->priority<=best) {
    best=item->priority;
    index=j;
   }
  }
  if(index==-1 || best==0x7fffffff) {
   if(DAT_0048e0e1) DAT_0048e0e1=0;
   break;
  }
  FUN_0002a4b0(index,0);
 }
 if(count<=limit) DAT_0048e0e1=1;
}


// 0x0002b690 FUN_0002b690 (152 B): matches/0x0002b690.cpp
// sym: ?A@T_2b690@fn_f6d645d0@@QAEXXZ
void T_2b690::A() {
    init_0002a890();
    fini_0002c110();
    Ref_2b690* z = q;
    if (z) {
        ((owners::C_67a20 *)z)->FUN_00067a20();
        dispose_0008d330(z);
    }
    if (r)
        r->Release(1);
    if (c) {
        c->Release();
        c = 0;
    }
    if (d) {
        d->Release();
        d = 0;
    }
    globalf_00232bb0();
    Elem_2b690* e = (Elem_2b690*)((char*)this + 0xc50);
    for (int i = 0; i < 16; i++) {
        e = (Elem_2b690*)((char*)e - 0x68);
        ((Elem_2b690*)((char*)e + 8))->Fn_0027af50();
        e->Fn_0027af50();
    }
}


// 0x0002b730 FUN_0002b730 (151 B): equivalent/0x0002b730.cpp
// sym: ?FUN_0002b730@Group_2b730@fn_f6d645d0@@QAE_NPBD@Z @17bd3b9ed2ef @w237f024260c3
// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 14/14)
// FUN_0002b730 @ 0x0002b730
// Walks the ids backwards and releases every item whose link carries the given name.
bool Group_2b730::FUN_0002b730(const char *name)
{
    Name_2b730 key;
    key.FUN_0027b0e0(name);
    for (int i = count - 1; i >= 0; i--) {
        Item_2b730 *item = ((Item_2b730 *)((owners::ThisWrap_00059c10 *)(owner->registry))->FUN_00059c10((void *)(hulk_uintptr)(int)(ids[i])));
        if (item == 0)
            continue;
        if (item->FUN_00035ab0())
            continue;
        Link_2b730 *link = item->link;
        if (link == 0)
            continue;
        link->flagB = 0;
        link->flagA = 0;
        if (key.lo == link->nameLo && key.hi == link->nameHi)
            FUN_0002a4b0(i, 0);
    }
    key.FUN_0027af50();
    return true;
}

} // namespace fn_f6d645d0

// 0x0002b7d0 FUN_0002b7d0 (89 B): equivalent/0x0002b7d0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?FUN_0002b7d0@Target@fn_0002b7d0@@QAEEXZ @0429baf6f160 @wcd7a5d1f6264
namespace fn_0002b7d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0002b7d0 @ 0x0002b7d0
struct Item { unsigned char FUN_00035ab0(); };
struct Manager {  };
struct Owner { char pad[0x44]; Manager* manager; };
struct Target { Owner* owner; char pad[8]; int count; int entries[1]; void FUN_0002a4b0(int,int); unsigned char FUN_0002b7d0(); };
unsigned char Target::FUN_0002b7d0() { for(int i=0;i<count;++i) { Item* item=((Item *)((owners::ThisWrap_00059c10 *)(owner->manager))->FUN_00059c10((void *)(hulk_uintptr)(int)(entries[i]))); if(item && !item->FUN_00035ab0()) { FUN_0002a4b0(i,0); return 1; } } return 0; }
} // namespace fn_0002b7d0


// 0x0002b830 FUN_0002b830 (40 B): matches/0x0002b830.cpp [wrapped: conflict: Obj::Run]
// sym: ?Run@Obj@fn_0002b830@@QAEDPBD@Z
namespace fn_0002b830 {
class Obj {
  public:
    void Act_0002a4b0(int, int);
    char Run(const char*);
};
struct This_Lookup {
    int Lookup_000241c0(const char*);
};
char Obj::Run(const char* s) {
    int i = ((This_Lookup*)this)->Lookup_000241c0(s);
    if (i == -1)
        return 0;
    Act_0002a4b0(i, 0);
    return 1;
}
} // namespace fn_0002b830

namespace fn_f6d645d0 {

// 0x0002b860 FUN_0002b860 (260 B): equivalent/0x0002b860.cpp
// sym: ?FUN_0002b860@Target_2b860@fn_f6d645d0@@QAE_NMMM@Z @0d054c89604a @w6dc2b60684bb
// STATUS: equivalent (tools/equiv.py level 3: 569 inputs, branch coverage 16/16)
// FUN_0002b860 @ 0x0002b860
bool Target_2b860::FUN_0002b860(float x,float y,float z) { float best=-1.0f; int selected=-1; for(int i=0;i<count;++i) { Item_2b860* item=owner->manager->FUN_00059ba0(items[i]); if(!item) continue; Entity* entity=item->FUN_00059a30(); if(!entity || entity->FUN_00035ab0()) continue; Vec_2b860 position; item->FUN_00059a50(&position); double dx=(double)position.x-x,dy=(double)position.y-y,dz=(double)position.z-z; double distance=sqrt(dz*dz+dy*dy+dx*dx); if(best<0.0f || distance<best) { best=(float)distance; selected=i; } } if(selected>=0) { ((owners::ThisWrap_00059c10 *)(owner->manager))->FUN_00059c10((void *)(hulk_uintptr)(int)(items[selected])); FUN_0002a4b0(selected,0); } return true; }

} // namespace fn_f6d645d0

// 0x0002b970 FUN_0002b970 (1499 B): equivalent/0x0002b970.cpp [wrapped: helper definitions (6 out-of-line function bodies)]
// sym: ?F@Spawner_2b970@fn_0002b970@@QAEDPBDUV3_2b970@2@M00D0D@Z @67991a53ccc1 @w4dfa8bd1100c
namespace fn_0002b970 {
// STATUS: equivalent (tools/equiv.py level 3: 20068 inputs, branch coverage 100/100)
// FUN_0002b970 @ 0x0002b970
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int memcmp(const void *a, const void *b, unsigned int n);
#endif

// MSVC 7.1 expands memcmp against a string literal inline (repe cmpsb); so does this.
static inline int memcmp_lit(const char *a, const char *b, unsigned n)
{
    for (; n != 0; n--, a++, b++)
        if (*a != *b)
            return (unsigned char)*a - (unsigned char)*b;
    return 0;
}
extern "C" int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
int FUN_00266da0(int mode);
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d690(unsigned int size);
char FUN_00202560(void *from, float a2, int flag, void *a3, void *a4, void *o38, void *o48, void *opts);


struct V3_2b970 {
    float x, y, z;
};

struct Name_2b970 {
};

struct Comp_2b970;
struct CCharacter_2b970;

struct Ent_2b970 {
    char pad0[0x60];
    int f60;
    char pad64[0xe8 - 0x64];
    char be8;
    char pad0e9[0x118 - 0xe9];
    Name_2b970 name;
    void FUN_000fdbd0(Comp_2b970 *c);
};

struct Def {
    char pad0[0x14];
    int f14;
    char pad18[0x1b0 - 0x18];
    int f1b0;
    char pad1b4[0x37c - 0x1b4];
    char b37c;
    char pad37d[0x38c - 0x37d];
    char b38c, b38d, b38e, b38f, b390;
    unsigned __int64 FUN_000443c0();
};

struct Registry_2b970 {
    char pad0[0xc];
    int count;
    Def *FUN_00044ad0(unsigned int lo, unsigned int hi);
};

struct Owner_2b970 {
    void FUN_00059cd0(CCharacter_2b970 *c);
};
struct Factory_2b970 {
    int *FUN_00059b60();
    Owner_2b970 *FUN_00059ba0(int *x);
};
struct Slot8b {
    void FUN_000c7d10(int a, const char *name);
};
struct Slot8_2b970 {
};
struct P3c_2b970 {
    char pad0[8];
    Slot8_2b970 *p8;
};
struct Pl2 {
    char pad0[0x12c];
    int f12c;
};
struct G20 {
    char pad0[0x124];
    Pl2 *f124;
};
struct World {
    char pad0[0x20];
    G20 *p20;
    char pad24[0x3c - 0x24];
    P3c_2b970 *p3c;
    char pad40[4];
    Factory_2b970 *p44;
};

struct Comp_2b970 {
    Comp_2b970 *FUN_001076f0(Ent_2b970 *e);
    Comp_2b970 *FUN_000ff180(Ent_2b970 *e);
    Comp_2b970 *FUN_000fcb10(Ent_2b970 *e);
    Comp_2b970 *FUN_00105f50(Ent_2b970 *e);
    Comp_2b970 *FUN_00103340(Ent_2b970 *e);
    void FUN_00103b60(World *w, const char *anim, int z);
    void FUN_001034b0(int a);
};

class CCharacter_2b970 {
public:
    virtual void v0();
    virtual void v1();
    char pad04[0x11c - 4];
    Def *p11c;
    char pad120[0x128 - 0x120];
    void *p128;
    char pad12c[0x1ca0 - 0x12c];
    Ent_2b970 *p1ca0;
    char pad1ca4[0x1d7c - 0x1ca4];
    int f1d7c;
    CCharacter_2b970 *FUN_00037860(int *x);
    void FUN_00042b40(Def *d);
    void FUN_0003f650();
    char FUN_00035a90();
    void FUN_000368d0(int a);
    void FUN_00035fa0(int a);
    void FUN_0003f400(V3_2b970 *p);
    void FUN_000354e0(float a);
    void FUN_00035ce0(int a);
};

class Spawner_2b970 {
public:
    World *p0;
    Registry_2b970 *p4;
    char pad8[0x128 - 8];
    char name[0x100];
    char pad228[0x584 - 0x228];
    int f584;
    char b588;
    int FUN_00024280(unsigned int lo, unsigned int hi);
    int FUN_0002a3c0(CCharacter_2b970 *c);
    void FUN_0002b590();
    char F(const char *defName, V3_2b970 pos, float angle, const char *name2, const char *anim, char flag8,
           const char *name9, char arg10);
};

static Comp_2b970 *MakeComp1(Ent_2b970 *e)
{
    void *m = FUN_0008d690(0xb0);
    return m ? ((Comp_2b970 *)m)->FUN_001076f0(e) : 0;
}
static Comp_2b970 *MakeComp2(Ent_2b970 *e)
{
    void *m = FUN_0008d690(0x1a0);
    return m ? ((Comp_2b970 *)m)->FUN_000ff180(e) : 0;
}
static Comp_2b970 *MakeComp3(Ent_2b970 *e)
{
    void *m = FUN_0008d690(0x74);
    return m ? ((Comp_2b970 *)m)->FUN_000fcb10(e) : 0;
}
static Comp_2b970 *MakeComp4(Ent_2b970 *e)
{
    void *m = FUN_0008d690(0xf4);
    return m ? ((Comp_2b970 *)m)->FUN_00105f50(e) : 0;
}
static Comp_2b970 *MakeComp5(Ent_2b970 *e)
{
    void *m = FUN_0008d690(0xf0);
    return m ? ((Comp_2b970 *)m)->FUN_00103340(e) : 0;
}

char Spawner_2b970::F(const char *defName, V3_2b970 pos, float angle, const char *name2, const char *anim, char flag8,
                const char *name9, char arg10)
{
    int old = FUN_00266da0(0xc);
    if ((*(char*)&DAT_004dc038)) {
        FUN_00266da0(old);
        return 0;
    }
    FUN_00267760(name, 0x100, "%s", name9);
    unsigned __int64 nh = FUN_0027b020(name);
    if (FUN_00024280((unsigned int)nh, (unsigned int)(nh >> 32))) {
        FUN_00266da0(old);
        return 0;
    }
    Registry_2b970 *reg0 = p4;
    unsigned __int64 dh = FUN_0027b020(defName);
    Def *def = reg0->FUN_00044ad0((unsigned int)dh, (unsigned int)(dh >> 32));
    if (!def) {
        unsigned __int64 dh2 = FUN_0027b020(defName);
        int i = 0;
        int n = p4->count;
        bool found = false;
        if (n > 0) {
            do {
                unsigned __int64 id = ((Def *)((owners::C_44ab0 *)p4)->FUN_00044ab0(i))->FUN_000443c0();
                if (id == dh2) {
                    found = true;
                    break;
                }
                i++;
            } while (i < p4->count);
        }
        if (!found) {
            FUN_00266da0(old);
            return 0;
        }
        def = ((Def *)((owners::C_44ab0 *)p4)->FUN_00044ab0(i));
        if (!def) {
            FUN_00266da0(old);
            return 0;
        }
    }
    Factory_2b970 *fac = p0->p44;
    int *fx = fac->FUN_00059b60();
    void *mem = thunk_FUN_0008d690(0x2300);
    CCharacter_2b970 *ch;
    if (mem)
        ch = ((CCharacter_2b970 *)mem)->FUN_00037860(fx);
    else
        ch = 0;
    ch->v0();
    Owner_2b970 *ow = fac->FUN_00059ba0(fx);
    if (ow)
        ow->FUN_00059cd0(ch);
    ((owners::Obj_36d60 *)ch)->FUN_00036d60((const char *)name);
    ch->FUN_00042b40(def);
    ch->FUN_0003f650();
    ((owners::Obj_362f0 *)ch)->FUN_000362f0();
    if (arg10 && !ch->FUN_00035a90()) {
        V3_2b970 A, B;
        ch->FUN_000368d0(0);
        ch->FUN_00035fa0(0);
        if (FUN_00202560(&pos, 10.0f, 0, &B, &A, 0, 0, 0))
            pos.y = B.y;
        ch->FUN_000368d0(1);
        ch->FUN_00035fa0(1);
    }
    ch->FUN_0003f400(&pos);
    ch->FUN_000354e0(angle * 0.0174532924f);
    bool doTail = false;
    if (ch->p128 == 0) {
        Ent_2b970 *ent = ch->p1ca0;
        unsigned __int64 did = def->FUN_000443c0();
        bool skipAll = (unsigned int)did == (*(unsigned int*)&DAT_004dc0e0) && (unsigned int)(did >> 32) == (*(unsigned int*)((char*)&DAT_004dc0e0 + 4));
        if (!skipAll) {
            if (!def->b37c) {
                if (def->b38c)
                    ent->FUN_000fdbd0(MakeComp1(ent));
                if (def->b38d)
                    ent->FUN_000fdbd0(MakeComp2(ent));
                if (def->b38e)
                    ent->FUN_000fdbd0(MakeComp3(ent));
                if (def->b38f)
                    ent->FUN_000fdbd0(MakeComp4(ent));
                if (def->b390) {
                    Comp_2b970 *c = MakeComp5(ent);
                    if (memcmp_lit(anim, "none", 5) != 0)
                        c->FUN_00103b60(p0, anim, 0);
                    ent->FUN_000fdbd0(c);
                }
            }
            ((owners::Target_27b040 *)&(ent->name))->FUN_0027b040((hulk_uintptr)name2);
            ent->be8 = flag8;
        }
        if (ch->p128 == 0)
            doTail = true;
    }
    if (!doTail && !def->b37c) {
        Def *cd = ch->p11c;
        Ent_2b970 *ent = ch->p1ca0;
        if (cd->b390) {
            Comp_2b970 *c = MakeComp5(ent);
            if (memcmp_lit(anim, "none", 5) != 0) {
                c->FUN_00103b60(p0, anim, 0);
                if (ch->p11c->f14 == 5)
                    c->FUN_001034b0((*(unsigned char*)&DAT_004dc288));
                else
                    c->FUN_001034b0(1);
            }
            ent->FUN_000fdbd0(c);
            ((owners::Target_27b040 *)&(ent->name))->FUN_0027b040((hulk_uintptr)name2);
            ent->be8 = flag8;
        }
        Def *cd2 = ch->p11c;
        Comp_2b970 *c2 = 0;
        bool add = false;
        if (cd2->f14 == 4) {
            if (cd2->b38c) {
                c2 = MakeComp1(ent);
                add = true;
            }
        } else {
            if (cd2->b38f) {
                c2 = MakeComp4(ent);
                add = true;
            }
        }
        if (add)
            ent->FUN_000fdbd0(c2);
        Def *cd3 = ch->p11c;
        if (cd3->f14 == 5 && cd3->b38c)
            ent->FUN_000fdbd0(MakeComp1(ent));
    }
    Pl2 *pl = p0->p20->f124;
    if (pl)
        ch->p1ca0->f60 = pl->f12c;
    ch->f1d7c = f584;
    ch->FUN_00035ce0((unsigned char)b588);
    if (b588 == 0 && f584 == 0x7fffffff)
        ch->f1d7c = 2;
    f584 = 0x7fffffff;
    b588 = 0;
    int res = FUN_0002a3c0(ch);
    Slot8_2b970 *s8 = p0->p3c->p8;
    Def *cd4 = ch->p11c;
    if (cd4 && cd4->f1b0 != 1 && s8) {
        if (((Slot8b *)((owners::C_cae70 *)s8)->FUN_000cae70()))
            ((Slot8b *)((owners::C_cae70 *)s8)->FUN_000cae70())->FUN_000c7d10(1, name9);
    }
    ch->v1();
    FUN_0002b590();
    FUN_00266da0(old);
    return res != -1;
}
} // namespace fn_0002b970
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f6d645d0 {

// 0x0002bf50 FUN_0002bf50 (38 B): matches/0x0002bf50.cpp
// sym: ?Run@Thing_2bf50@fn_f6d645d0@@QAEXH@Z
void Thing_2bf50::Run(int count) {
    int i = 0;
    while (i < count && Check_0002b7d0())
        ++i;
}


// 0x0002bf80 FUN_0002bf80 (65 B): matches/0x0002bf80.cpp
// sym: ?FUN_0002bf80@Actor@fn_f6d645d0@@QAEHIUTriple@2@IIIII@Z
int Actor::FUN_0002bf80(unsigned a, Triple b, unsigned e, unsigned f, unsigned g, unsigned h, unsigned i) {
    return FUN_0002b970(a, b, e, f, g, h, i, 1);
}


// 0x0002bfd0 FUN_0002bfd0 (114 B): equivalent/0x0002bfd0.cpp
// sym: ?FUN_0002bfd0@Group_2bfd0@fn_f6d645d0@@QAE_NHHHHHHHHPBD@Z @614d7bffcb8a @w0d4687d2b3fb
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0002bfd0 @ 0x0002bfd0
// Components are plain ints: the original copies them with integer moves.
bool Group_2bfd0::FUN_0002bfd0(int a1, int x, int y, int z, int a5, int a6, int a7, int a8, const char *name)
{
    Vec3_2bfd0 pos;
    pos.x = x;
    pos.y = y;
    pos.z = z;
    bool result = FUN_0002b970(a1, pos, a5, a6, a7, a8, name, 0);
    Pawn_2bfd0 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (pawn)
        ((owners::C_359c0 *)pawn)->FUN_000359c0(3);
    return result;
}

} // namespace fn_f6d645d0

// 0x0002c050 FUN_0002c050 (138 B): equivalent/0x0002c050.cpp [wrapped: conflict: Object]
// sym: ?Place@Actor_2c050@fn_0002c050@@QAEDHHHHHH@Z @1520d0757c2e @we66db23b34d2
namespace fn_0002c050 {
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 4/4)
// FUN_0002c050 @ 0x0002c050

struct Loc_2c050 { int x, y, z; };
struct Pose { int x, y, z; float deg; };
class Object {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void GetPos(Loc_2c050* out);
    virtual float GetAngle();
};
struct Finder_2c050 { Object* FUN_001fd780(int key); };
struct Env_2c050 { char pad[0x28]; Finder_2c050* finder; };
struct Actor_2c050 {
    Env_2c050* env;
    char FUN_0002b970(int a1, Pose pose, int a3, int a4, int a5, int a6, int flag);
    char Place(int a1, int key, int a3, int a4, int a5, int a6);
};
char Actor_2c050::Place(int a1, int key, int a3, int a4, int a5, int a6) {
    if (!env->finder) return 0;
    Object* o = env->finder->FUN_001fd780(key);
    if (!o) return 0;
    Loc_2c050 loc;
    o->GetPos(&loc);
    Pose pose;
    pose.deg = o->GetAngle() * (*(float*)&DAT_003f3ef4);
    pose.x = loc.x; pose.y = loc.y; pose.z = loc.z;
    return FUN_0002b970(a1, pose, a3, a4, a5, a6, 1);
}
} // namespace fn_0002c050

namespace fn_f6d645d0 {

// 0x0002c0e0 FUN_0002c0e0 (13 B): matches/0x0002c0e0.cpp
// sym: ?Set@C_2c0e0@fn_f6d645d0@@QAEXD@Z
void C_2c0e0::Set(char x) {
    m = x;
}


// 0x0002c0f0 FUN_0002c0f0 (4 B): matches/0x0002c0f0.cpp
// sym: ?GetFlag@Obj_2c0f0@fn_f6d645d0@@QAEDXZ
char Obj_2c0f0::GetFlag() {
    return flag;
}


// 0x0002c100 FUN_0002c100 (10 B): matches/0x0002c100.cpp
// sym: ?Set@Obj_2c100@fn_f6d645d0@@QAEXE@Z
void Obj_2c100::Set(unsigned char v) {
    m50 = v;
}


// 0x0002c110 FUN_0002c110 (1 B): matches/0x0002c110.cpp
// sym: ?FUN_0002c110@fn_f6d645d0@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0002c110(void* /*this, unused: callers pass it (unb4)*/) {}

// 0x0002c230 thunk_FUN_001d04a0 (5 B): not yet verified
// 0x0002c400 thunk_FUN_001d04a0 (5 B): not yet verified

// 0x0002c480 FUN_0002c480 (14 B): matches/0x0002c480.cpp
// sym: ?FUN_0002c480@fn_f6d645d0@@YAHXZ
// data: gThing = DAT_0048e128
int FUN_0002c480() {
    return FUN_001d04d0(((char*)&DAT_0048e128));
}

} // namespace fn_f6d645d0
