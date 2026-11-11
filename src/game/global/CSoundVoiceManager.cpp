// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f2e40..0x001f6bc0 (kind game, layer game, confidence high), dominant class CSoundVoiceManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7fca51a {
#define TREE_TU_END }
namespace fn_f7fca51a {} using namespace fn_f7fca51a;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f7fca51a {
struct Part_1f2e40 {
    char pad[8];
    void Reset();
};
struct Thing_1f2e40 {
    Part_1f2e40 a;
    Part_1f2e40 b;
    Part_1f2e40 c;
    Thing_1f2e40* Reset();
};
struct Sub_1f2e60 {
    void f();
};
struct Obj_1f2e60 {
    char pad[0x18];
    void run();
};
struct Item_1f2e80 {
    char pad[0x6c];
    float f;
    char p[4];
    int n;
};
struct Id64_1f2f30 { unsigned int lo; unsigned int hi; };
struct Item_1f2f30 {
    char pad0[8];
    int id;
    char padc[4];
    Id64_1f2f30* key;
};
struct Group_1f2f30 {
    char pad0[8];
    Item_1f2f30* items[32];
    int count;
    char pad8c[0xcc - 0x8c];
    Item_1f2f30* current;
    Item_1f2f30* FUN_001f2f30(int id, Id64_1f2f30* key);
};
class Item_1f2fb0 {
  public:
    char pad[16];
    int key;
};
class Container_1f2fb0 {
  public:
    char pad0[8];
    Item_1f2fb0* items[32];
    int count;
    Item_1f2fb0* excluded;
    Item_1f2fb0* Find(int key);
};
struct Entry {
    unsigned __int64 key;
    char pad[24];
};
typedef unsigned __int64 u64_1f3040;
struct Node {
  public:
    char _m_pad_0[0x8];
    int nameA;
    int nameB;
    int nameC;
    int nameD;
    int flag;
    char _m_pad_1c[0x14];
    float x;
    float y;
    float z;
    unsigned int f3c;
    unsigned int f40;
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    unsigned int f54;
    unsigned int f58;
    unsigned int f5c;
    char _m_pad_60[0xc];
    float dist;
    unsigned char flag70;
    char _m_pad_71[0x3];
    int limit;
    int f78;
};
struct Key_1f3040 {
    u64_1f3040 key;
};
struct Dest_1f3040 {
    char pad00[0x10];
    int handleA;
    int handleB;
    char pad18[0x5c];
    int flag;
};
struct Sound_1f3040 {
    int FUN_001e9860(int a, int b);
};
extern "C" void * __cdecl FUN_001f2ff0(unsigned __int64 *);
struct StringValue_1f30e0 {
    char data[8];
    StringValue_1f30e0* FUN_0027b0e0(const char* text);
    void FUN_0027af70(StringValue_1f30e0* source);
    void FUN_0027af50();
};
struct Record_1f30e0 {
    StringValue_1f30e0 first;
    StringValue_1f30e0 second;
    StringValue_1f30e0 third;
    unsigned value;
    unsigned padding;
};
struct Id_1f31a0 {
    unsigned int lo;
    unsigned int hi;
};
struct Entry_1f31a0 {
    Id_1f31a0 id;
};
struct Registry_1f31a0 {
    char pad[0xd4];
    Entry_1f31a0 *entries[1];
    char pad2[0x324 - 0xd8];
    int count;
    Entry_1f31a0 *FUN_001f31a0(const Id_1f31a0 *key);
};
struct Resource_1f32b0 { char pad[0x18]; int id; void FUN_001e8a90(); };
struct Manager_1f32b0 { char pad[0x518]; int context; };
struct State_1f32b0 { char pad[0x334]; float value; };
extern "C" int __cdecl FUN_00240750();
extern int __cdecl FUN_0024ace0(int, int*, int, int, int, int*);
extern void __cdecl FUN_00247890(int, float);
extern "C" void __cdecl FUN_002478b0(int, float);
extern "C" void __cdecl FUN_002478d0(int, int);
extern "C" void __cdecl FUN_00247900(int, int);
extern int __cdecl Find(int, int);
extern void __cdecl Act(int, int, int, int, int);
typedef unsigned int u32_1f33b0;
extern u32_1f33b0 __cdecl Find(u32_1f33b0, u32_1f33b0);
extern "C" u32_1f33b0 __cdecl FUN_0024a9c0(u32_1f33b0, u32_1f33b0);
extern "C" void __cdecl FUN_00247a10(u32_1f33b0);
extern "C" void __cdecl FUN_00247a20(u32_1f33b0, u32_1f33b0, u32_1f33b0, u32_1f33b0, u32_1f33b0);
typedef unsigned int u32_1f3400;
void F249A90(u32_1f3400 a, u32_1f3400* b);
void F24A800(u32_1f3400 a, int b);
void F2497E0(u32_1f3400 a);
struct Pair_1f3400 {
    u32_1f3400 x;
    u32_1f3400 y;
};
typedef unsigned int u32_1f3460;
struct Target_1f3460 {
    char pad[4];
    void* value;
};
struct Pair_1f3460 {
    u32_1f3460 a;
    u32_1f3460 b;
};
extern void __cdecl FUN_00249a90(void*, Pair_1f3460*);
extern void __cdecl FUN_0024a800(void*, u32_1f3460);
extern int FindThing(int, int);
extern void DoThing(int, int, void*);
typedef unsigned int u32_1f34f0;
struct H {
    void Run();
};
extern void f2(u32_1f34f0);
extern void f3(u32_1f34f0, u32_1f34f0);
extern void f4(u32_1f34f0, u32_1f34f0);
extern void f5(u32_1f34f0);
class Obj_1f34f0 {
  public:
    char p0[4];
    int b;
    hulk_intptr c;
    char p1[4];
    int d;
    char e;
    char p2[3];
    int i;
    void Run();
};
extern int FUN_00249b40(int);
struct Obj_1f3550 {
    int pad;
    int member;
};
struct ThisCall_0027af60 {
};
struct Pair_1f3720 {
    int a;
    int b;
};
class Target_1f3720 {
  public:
    char pad[8];
    int x;
    int y;
    int z;
    int w;
    unsigned char q;
    void Set(Pair_1f3720*, int, int, int, int, unsigned char);
};
struct Name_1f3780 {
    void FUN_0027af00();
    char data[8];
};
struct Slot_1f3780 {
    int a;
    int b;
    int pad08;
    char flag;
    char pad0d[11];
    float sx;
    float sy;
    float sz;
    int pad24;
};
class Holder_1f3780 {
public:
    Name_1f3780 name0;
    Name_1f3780 name1;
    char pad10[0x64];
    int id;
    int field_78;
    int pad7c;
    Slot_1f3780 slots[4];
    int field_120;
    Holder_1f3780* FUN_001f3780();
};
class C_1f3800 {
    char pad[8];

  public:
    void f();
};
class S_1f3800 {
  public:
    void h();
};
struct Helper_1f3830 {
    void Run();
};
struct Thing_1f3830 {
    char pad[8];
    Helper_1f3830 sub;
    Thing_1f3830* F(unsigned char);
};
void __cdecl thunk_FUN_00267090(Thing_1f3830*);
struct Item_1f38a0 {
    int a;
    void* h;
    char pad[0x10];
    void* buf;
};
struct Vec_1f38a0 {
    int x;
    int y;
};
struct Mgr_1f38a0 {
    char pad0[8];
    Item_1f38a0* items[32];
    int count;
    char pad1[0xc0 - 0x8c];
    Item_1f38a0* skipA;
    Item_1f38a0* skipB;
    void Release();
};
void FUN_00249a90(void* h, Vec_1f38a0* out);
void FUN_0024a800(void* h, int v);
void FUN_002497e0(void* p);
struct T_1f3930 {
};
extern float gScale_1f3950;
void __cdecl Apply(int, float);
class Anim_1f3a50 {
public:
    char pad0[4];
    int next;
    int current;
    void FUN_001f34f0();
    void FUN_001f32b0(int a, int b, int c);
};
class Player_1f3a50 {
public:
    char pad0[0xc4];
    Anim_1f3a50* anim;
    char pad1[0x334 - 0xc8];
    float speedScale;
    bool FUN_001f3a50(int target, int arg);
};
struct Child_1f3ad0 {
    char pad[8];
    int value;
};
struct Obj_1f3ad0 {
    char pad[0xc8];
    Child_1f3ad0* child;
    bool run();
};
struct Item_1f3af0 { void FUN_001e8ac0(); };
struct State_1f3af0 {
 char pad0[4]; void* handle; Item_1f3af0* item; char padC[8]; bool active;
 void FUN_001f32b0(Item_1f3af0*,int,int);
};
struct Input_1f3af0 { char pad[0x6c]; float value; };
struct Object {
  public:
    char _m_pad_0[0x4];
    int handle;
    Resource_1f32b0* resource;
    char _m_pad_c[0x1c];
    float mode;
    char _m_pad_2c[0x9c];
    State_1f3af0* state;
    char _m_pad_cc[0x268];
    float scale;
    int initialize(Resource_1f32b0*, int, int);
    bool run(Item_1f3af0*,void*,Input_1f3af0*);
};
extern bool __cdecl FUN_00249b40(void*);
extern void __cdecl FUN_0024af00(void*);
extern void __cdecl FUN_00247890(void*,float);
struct Id_1f3c00 {
    int lo;
    int hi;
};
struct Voice_1f3c00 {
    void FUN_001e8ac0();
};
struct Sound_1f3c00 {
    char pad;
};
struct Notifier_1f3c00 {
};
struct Channel {
    char pad00[4];
    Sound_1f3c00* sound;               // 0x04
    Voice_1f3c00* voice;               // 0x08
    char pad0c[4];
    int f10;                    // 0x10
    char b14;                   // 0x14
    char pad15[3];

};
struct Slot_1f3c00 {
    char pad00[8];
    Voice_1f3c00* voice;               // 0x08
    int value;                  // 0x0c
    int qty;                    // 0x10
    const char* name;           // 0x14
    char flag;                  // 0x18
    char pad19[3];

    void FUN_001f3720(Id_1f3c00* id, Voice_1f3c00* voice, int value, int qty, const char* name, int flag);
};
bool __cdecl FUN_00249b40(Sound_1f3c00* s);
void __cdecl FUN_0024af00(Sound_1f3c00* s);
void __cdecl FUN_00247890(Sound_1f3c00* s, float volume);
struct Init_1f3c00 { void FUN_001f32b0(Voice_1f3c00* voice, bool active, int flag); };
class Player_1f3c00 {
public:
    bool FUN_001f3c00(Voice_1f3c00* voice, int* value, Id_1f3c00* id, const char* name, int qty, int flag);
    int FUN_001f31a0(Id_1f3c00* id);

    char pad00[0x8c];
    Channel* channel;           // 0x8c
    int limit;                  // 0x90
    char b94;                   // 0x94
    char pad95[0xa0 - 0x95];
    Slot_1f3c00 slot;                  // 0xa0
    char pad_after_slot[0x334 - 0xa0 - sizeof(Slot_1f3c00)];
    float volume;               // 0x334
    Notifier_1f3c00* notifier;         // 0x338
};
struct Voice_1f3ec0 {
    char pad0[4];
    void *sound;
    char pad8[0x10 - 8];
    int flags;
    char pad14[0x1d - 0x14];
    char tag;
    void FUN_001f32b0(int a, bool b, int c);
};
class VoicePool_1f3ec0 {
public:
    Voice_1f3ec0 *FUN_001f3ec0(int a, int unused, int flags, int c, char tag);

    char pad0[8];
    Voice_1f3ec0 *voices[32];
    int count;
    Voice_1f3ec0 *reserved8c;
    char pad90[0xc0 - 0x90];
    Voice_1f3ec0 *reservedC0;
    Voice_1f3ec0 *reservedC4;
    Voice_1f3ec0 *reservedC8;
    Voice_1f3ec0 *reservedCC;
    char padd0[0x334 - 0xd0];
    float volumeScale;
};
struct Sound;
struct Voice_1f4140 {
    char pad0[4];
    Sound *sound;           // 0x4
    hulk_intptr handle;             // 0x8
    char pad1[4];
    int owner;              // 0x10
    char finished;          // 0x14
    void FUN_001f32b0(int id, bool flag, int vol);
};
struct Names_1f4140 {
};
struct State_1f4140 {
    char pad[8];
};
struct ThisNote_001e8ac0 {
    void FUN_001e8ac0();
};
bool FUN_00249b40(Sound *s);
void FUN_0024af00(Sound *s);
void FUN_00247890(Sound *s, float volume);
class Player_1f4140 {
public:
    char pad0[0x8c];
    Voice_1f4140 *voice;           // 0x8c
    int f90;
    char f94;
    char pad1[0xa0 - 0x95];
    State_1f4140 state;            // 0xa0
    int id;                 // 0xa8
    int fac;
    int count;              // 0xb0
    const char *name;       // 0xb4
    char vol;               // 0xb8
    char pad4[0x334 - 0xb9];
    float gain;             // 0x334
    Names_1f4140 *names;           // 0x338
    int FUN_001f31a0(State_1f4140 *s);
    void FUN_001f4140(bool force);
};
struct Id_1f42d0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};
} // namespace fn_f7fca51a
struct World {
    char pad0[8];
    struct Gate {
        char FUN_000997a0();
    } *gate;
};
namespace fn_f7fca51a {
union IdSlot {
    unsigned int raw[3];
    Id_1f42d0 id;
};
class Manager_1f42d0 {
public:
    char pad0[0x328];
    Node *parent;

    Node *FUN_001f31a0(const Id_1f42d0 *id);
    void FUN_001f42d0(const Id_1f42d0 *id, void *owner, float px, float py, float pz,
                      unsigned int a6, unsigned int a7, unsigned int a8,
                      unsigned int a9, unsigned int a10, unsigned int a11,
                      IdSlot a12, int a15);
};
struct ThisCall_001f4010 {
    Node * FUN_001f4010(void *owner, const Id_1f42d0 *id, int limit);
};
struct Item_1f4610 {
    int pad;
    int h;
};
struct Obj_1f4610 {
    char p[8];
    Item_1f4610* list[1];
    char q[0x88 - 0x0c];
    int count;
    Item_1f4610* a;
    char r[0xc0 - 0x90];
    Item_1f4610* b;
    Item_1f4610* c;
    char s[4];
    Item_1f4610* d;
    char t[0x330 - 0xd0];
    int guard;
    void Fn(char, char, char);
};
extern "C" void __cdecl Wait(int, int);
class Obj_1f46a0 {
  public:
    char pad0[8];
    struct Entry {
        int pad;
        int value;
    }* items[32];
    int count;
    char pad1[0x330 - 0x8 - 32 * 4 - 4];
    int state;
    void Fn();
};
extern "C" void __cdecl FUN_00247970(int, int);
bool __cdecl FUN_00249b40(Handle* h);
struct Fade_1f4710 { int a; int b; };
void __cdecl FUN_00249a90(Handle* h, Fade_1f4710* f);
void __cdecl FUN_0024a800(Handle* h, int n);
struct Item_1f4710 { int pad0; Handle* handle; char pad8[0x10]; void* extra; };
class Player_1f4710 {
public:
    char pad0[8];
    Item_1f4710* items[32];
    int count;
    bool FUN_001f4710();
};
struct Key_1f47b0 {
    int lo, hi;
};
struct Timer {
    Key_1f47b0 key;                 // 0x00
    int field08;
    int field0c;
    int field10;
    int field14;
    char field18;
};
struct Target_1f47b0 {
    char pad00[0x10];
    int expected;            // 0x10
};
class Owner_1f47b0 {
public:
    char pad00[0x8c];
    Target_1f47b0 *target;          // 0x8c
    char pad90[0x10];
    Timer timer;             // 0xa0
    int FUN_001f31a0(Key_1f47b0 *key);
    bool FUN_001f47b0(Key_1f47b0 *key);
};
extern "C" char DAT_00424b0c[];
class Method3_1f4980 {
  public:
    void Init(const char*, int);
    hulk_intptr vf;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn a;        // 0x1c
    Method3_1f4980* Fn(const char*, ScriptMemberFn);
};
struct CSoundVoiceManager_1f4a00 {
    void FUN_001f4a00(unsigned int, unsigned int, unsigned int);
};
struct Args { unsigned char first; char pad0[3]; unsigned char second; char pad1[3]; unsigned char third; };
struct Function_1f4a00 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CActorManager_1f4a90 {
  public:
    void f();
};
extern "C" char DAT_00424b2c[];
class Method4_1f4aa0 {
  public:
    hulk_intptr vptr;
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn m1c;      // 0x1c
    Method4_1f4aa0(const char*, ScriptMemberFn);
};
struct ThisCall_001d0480 {
    void Init(const char*, int);
};
extern "C" char __cdecl Get(void*);
struct CSoundVoiceManager_1f4b30 {};
struct Function_1f4b30 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Obj_1f4b60 {
  public:
    char pad[8];
    int a;
    int b;
    int c;
    int d;
    char e;
    void first();
};
extern int f2(int, int);
struct Name_1f4c50 {
    unsigned int lo, hi;
    unsigned int tail[2];   // (the constructor writes up to 0xb bytes; the original reuses the tail as the ID temporary)
    void FUN_0027b0e0(const char *s);
    void FUN_0027af50();
};
struct Voice_1f4c50 {
    char pad0[4];
    void *f4;               // 0x04
    char pad8[0x1d - 8];
    char flag;              // 0x1d
    void FUN_001f32b0(void *src, int a, int b);
};
struct Mixer {
    void *FUN_001e98b0(ID *id);
};
struct V3_1f4c50 {
    float x, y, z;
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Props_1f4c50 {
    char pad0[0x30];
    V3_1f4c50 v30;                 // 0x30
    float f3c;              // 0x3c
    int f40, f44;           // 0x40
    V3_1f4c50 v48;                 // 0x48
    char pad54[0x74 - 0x54];
    int f74;                // 0x74
};
class Sound_1f4c50 {
public:
    char pad0[8];
    Voice_1f4c50 *v8;              // 0x08
    Voice_1f4c50 *vc;              // 0x0c
    Voice_1f4c50 *v10;             // 0x10
    Voice_1f4c50 *v14;             // 0x14
    Voice_1f4c50 *v18;             // 0x18
    char pad1c[0x88 - 0x1c];
    int f88;                // 0x88
    Voice_1f4c50 *v8c;             // 0x8c
    int f90;                // 0x90
    char f94;               // 0x94
    char pad95[0xc0 - 0x95];
    Voice_1f4c50 *vc0;             // 0xc0
    Voice_1f4c50 *vc4;             // 0xc4
    Voice_1f4c50 *vc8;             // 0xc8
    Voice_1f4c50 *vcc;             // 0xcc
    char padd0[0x328 - 0xd0];
    Props_1f4c50 *props;           // 0x328
    char pad32c[0x334 - 0x32c];
    float volume;           // 0x334
    Mixer *mixer;           // 0x338
    Props_1f4c50 *FUN_001f4010(Name_1f4c50 *a, Name_1f4c50 *b, int c);
    void FUN_001f4c50();
};
class Inner_1f5640 {
public:
    char pad0[8];
    int f8;
    void FUN_001f34f0();
    void FUN_001f32b0(int a, int b, int c);
};
class Player_1f5640 {
public:
    char pad0[0xc0];
    Inner_1f5640 *fc0;
    char padc4[0x334 - 0xc4];
    float f334;
    char FUN_001f5640(int obj, int arg);
};
extern "C" char DAT_004c7eb4[];
extern "C" char DAT_004c7ed4[];
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
struct Pair_1f57e0 {
    unsigned int lo;
    unsigned int hi;
};
struct Inner_1f57e0 {
    char pad0[8];
    Pair_1f57e0 value;             // 0x08
};
struct Found_1f57e0 {
    char pad0[8];
    Inner_1f57e0* inner;           // 0x08
};
extern "C" Item* __cdecl FUN_002495c0(List* list);
void* __cdecl FUN_002495f0(Item* item);
extern "C" void* __cdecl FUN_00249610(List* list, void* key);
Item* __cdecl FUN_002495e0(List* list, Item* item);
class Registry_1f57e0 {
public:
    int f00;
    List* list;             // 0x04
    unsigned __int64 FUN_001f57e0();
};
char __cdecl FUN_002478f0(void *voice);
extern "C" void __cdecl FUN_002485c0(void *voice, void *params, int a, int b);
int __cdecl FUN_00247930(void *voice, void *sound);
void __cdecl FUN_00247a90(void *voice, void *sound, int flag);
class Emitter_1f5860 {
public:
    virtual void start(unsigned __int64 id);
    virtual void stop(unsigned __int64 id);
};
struct Owner_1f5860 {
    char padd0[0xd0];
    Emitter_1f5860 *emitter;        // 0xd0
};
class SoundSlot {
public:
    char pad0[4];
    void *voice;             // 0x04
    char pad08[4];
    Owner_1f5860 *owner;            // 0x0c
    char *params;            // 0x10
    char pad14[4];
    void *sound;             // 0x18
    char pending;            // 0x1c
    char active;             // 0x1d
    char pad1e[2];
    unsigned __int64 current; // 0x20
    int param28;             // 0x28
    unsigned __int64 FUN_001f57e0();
    char FUN_001f3550();
    void FUN_001f5860(float dt);
};
struct CSoundVoiceManager_1f5a50 { void FUN_001f5a50(unsigned, unsigned, unsigned); };
struct Function_1f5a50 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(int, Args *, int); };
class CActorManager_1f5ae0 {
  public:
    void run();
};
struct CSoundVoiceManager_1f5b40 { void callback(char*, char*, char*, int); };
struct VoiceArgs { char* first; char* second; char* third; int fourth; };
int FUN_00247930(int a, int b);
void FUN_00247a90(int a, int b, int c);
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f7fca51a
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f7fca51a {
class CSoundVoiceManager_1f6860 {};
typedef void (CSoundVoiceManager_1f6860::*Fn_1f6860)(bool, bool, bool);
class Registry_1f6860 { public:
    void FUN_001f6860(const char* a1, CSoundVoiceManager_1f6860* a2, Fn_1f6860 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_1f6860;
template<> class Closure3_1f6860<CSoundVoiceManager_1f6860, void, bool, bool, bool> : public ScriptFunctionFields { public: virtual void v(); Fn_1f6860 fn; CSoundVoiceManager_1f6860* owner; Closure3_1f6860(CSoundVoiceManager_1f6860* o) { owner = o; } };
class Raw_1f6860 { public: void FUN_001f4980(const char*, Fn_1f6860); };
class CSoundVoiceManager_1f6930 {};
typedef void (CSoundVoiceManager_1f6930::*Fn_1f6930)(char*, char*, char*, int);
class Registry_1f6930 { public:
    void FUN_001f6930(const char* a1, CSoundVoiceManager_1f6930* a2, Fn_1f6930 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_1f6930;
template<> class Closure4_1f6930<CSoundVoiceManager_1f6930, void, char*, char*, char*, int> : public ScriptFunctionFields { public: virtual void v(); Fn_1f6930 fn; CSoundVoiceManager_1f6930* owner; Closure4_1f6930(CSoundVoiceManager_1f6930* o) { owner = o; } };
class Raw_1f6930 { public: void FUN_001f4aa0(const char*, Fn_1f6930); };
class Obj_1f6ba0 {
  public:
    char pad[8];
    int field;
};
class Owner_1f6ba0 {
  public:
    char pad[0xc8];
    Obj_1f6ba0* member;
};


// 0x001f2e40 FUN_001f2e40 (28 B): matches/0x001f2e40.cpp
// sym: ?Reset@Thing_1f2e40@fn_f7fca51a@@QAEPAU12@XZ
Thing_1f2e40* Thing_1f2e40::Reset() {
    a.Reset();
    b.Reset();
    c.Reset();
    return this;
}


// 0x001f2e60 FUN_001f2e60 (27 B): matches/0x001f2e60.cpp
// sym: ?run@Obj_1f2e60@fn_f7fca51a@@QAEXXZ
void Obj_1f2e60::run() {
    ((Sub_1f2e60*)((char*)this + 0x10))->f();
    ((Sub_1f2e60*)((char*)this + 8))->f();
    ((Sub_1f2e60*)this)->f();
}


// 0x001f2e80 FUN_001f2e80 (81 B): matches/0x001f2e80.cpp
// sym: ?Compare@fn_f7fca51a@@YAHPAPAUItem_1f2e80@1@0@Z
int Compare(Item_1f2e80** a, Item_1f2e80** b) {
    Item_1f2e80* x = *a;
    Item_1f2e80* y = *b;
    if (!x)
        return y != 0;
    if (!y)
        return -1;
    if (x->n < y->n)
        return -1;
    if (x->f < y->f)
        return -1;
    if (x->f > y->f)
        return 1;
    return 0;
}


// 0x001f2f30 FUN_001f2f30 (120 B): equivalent/0x001f2f30.cpp
// sym: ?FUN_001f2f30@Group_1f2f30@fn_f7fca51a@@QAEPAUItem_1f2f30@2@HPAUId64_1f2f30@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 21/22, incomplete)
// FUN_001f2f30 @ 0x001f2f30
Item_1f2f30* Group_1f2f30::FUN_001f2f30(int id, Id64_1f2f30* key) {
    if (current->id == id)
        return current;
    for (int i = 0; i < count; ++i) {
        Item_1f2f30* item = items[i];
        if (item->id != id)
            continue;
        if (key == 0 || (key->lo | key->hi) == 0) {
            if (item->key == 0)
                return items[i];
        }
        if (key != 0 && item->key != 0 && item->key->lo == key->lo && item->key->hi == key->hi)
            return items[i];
    }
    return 0;
}


// 0x001f2fb0 FUN_001f2fb0 (63 B): matches/0x001f2fb0.cpp
// sym: ?Find@Container_1f2fb0@fn_f7fca51a@@QAEPAVItem_1f2fb0@2@H@Z
Item_1f2fb0* Container_1f2fb0::Find(int key) {
    int i = 0;
    if (count > 0) {
        Item_1f2fb0** p = items;
        do {
            Item_1f2fb0* item = *p;
            if (item->key == key && item != excluded)
                return items[i];
            ++i;
            ++p;
        } while (i < count);
    }
    return 0;
}


// 0x001f2ff0 FUN_001f2ff0 (71 B): matches/0x001f2ff0.cpp
// sym: _FUN_001f2ff0
// data: count = DAT_004e3764, entries = DAT_004e37b8
extern "C" void * FUN_001f2ff0(unsigned __int64* k) {
    int n = DAT_004e3764;
    for (int i = 0; i < n; i++) {
        unsigned __int64 v = *k;
        if (((Entry*)&DAT_004e37b8)[i].key == v)
            return (Entry *)(&((Entry*)&DAT_004e37b8)[i]);
    }
    return (Entry *)0;
}


// 0x001f3040 FUN_001f3040 (156 B): equivalent/0x001f3040.cpp
// sym: _FUN_001f3040
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 6/6)
// FUN_001f3040 @ 0x001f3040
// FUN_001f3040: look up an entry and fetch two sound handles from it (or default to "hulk")
extern "C" void __cdecl FUN_001f3040(void *d, void *k)
{
    Node *n = ((Node *)FUN_001f2ff0((unsigned __int64 *)(Key_1f3040 *)((Key_1f3040 *)k)));
    if (n != 0) {
        ((Dest_1f3040 *)d)->handleA = (*(Sound_1f3040**)&DAT_004e3690)->FUN_001e9860(n->nameA, n->nameB);
        ((Dest_1f3040 *)d)->handleB = (*(Sound_1f3040**)&DAT_004e3690)->FUN_001e9860(n->nameC, n->nameD);
        ((Dest_1f3040 *)d)->flag = n->flag;
        return;
    }
    u64_1f3040 hulk = FUN_0027b020("hulk"); // MSVC calls it before reading k->key
    if (((Key_1f3040 *)k)->key == hulk) {
        ((Dest_1f3040 *)d)->handleA = ((owners::X_1ea010 *)((*(Sound_1f3040**)&DAT_004e3690)))->FUN_001ea010((hulk_intptr)"hulk_sfx");
        ((Dest_1f3040 *)d)->handleB = ((owners::X_1ea010 *)((*(Sound_1f3040**)&DAT_004e3690)))->FUN_001ea010((hulk_intptr)"hulk_vox");
        ((Dest_1f3040 *)d)->flag = 1;
    }
}


// 0x001f30e0 FUN_001f30e0 (180 B): matches/0x001f30e0.cpp
// sym: ?FUN_001f30e0@fn_f7fca51a@@YGXPBD00I@Z
void __stdcall FUN_001f30e0(const char* first, const char* second, const char* third, unsigned value) {
    if (DAT_004e3764 < 264) {
        StringValue_1f30e0 temporary;
        StringValue_1f30e0* source = temporary.FUN_0027b0e0(first);
        ((Record_1f30e0*)&DAT_004e37b8)[DAT_004e3764].first.FUN_0027af70(source);
        temporary.FUN_0027af50();
        source = temporary.FUN_0027b0e0(second);
        ((Record_1f30e0*)&DAT_004e37b8)[DAT_004e3764].second.FUN_0027af70(source);
        temporary.FUN_0027af50();
        source = temporary.FUN_0027b0e0(third);
        ((Record_1f30e0*)&DAT_004e37b8)[DAT_004e3764].third.FUN_0027af70(source);
        temporary.FUN_0027af50();
        int index = DAT_004e3764;
        ((Record_1f30e0*)&DAT_004e37b8)[index].value = value;
        DAT_004e3764 = index + 1;
    }
}


// 0x001f31a0 FUN_001f31a0 (111 B): equivalent/0x001f31a0.cpp
// sym: ?FUN_001f31a0@Registry_1f31a0@fn_f7fca51a@@QAEPAUEntry_1f31a0@2@PBUId_1f31a0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 140 inputs, branch coverage 12/12)
// FUN_001f31a0 @ 0x001f31a0
Entry_1f31a0 *Registry_1f31a0::FUN_001f31a0(const Id_1f31a0 *key)
{
    if (key == 0)
        return 0;
    unsigned int lo = key->lo;
    unsigned int hi = key->hi;
    if ((lo | hi) == 0)
        return 0;
    for (int i = 0; i < count; i++) {
        if (entries[i]->id.lo == lo && entries[i]->id.hi == hi)
            return entries[i];
    }
    return 0;
}

} // namespace fn_f7fca51a

// 0x001f3280 FUN_001f3280 (34 B): matches/0x001f3280.cpp [wrapped: conflict: CSoundSequenceVoice]
// sym: ?FUN_001f3280@fn_001f3280@@YIXPAVCSoundSequenceVoice@1@@Z
namespace fn_001f3280 {
extern "C" char DAT_00424ae4[];
class CSoundSequenceVoice {
  public:
    void* vftable;
    void* member;
};
extern void __cdecl FUN_0024af00(void*);
void __fastcall FUN_001f3280(CSoundSequenceVoice* self) {
    self->vftable = (void*)((hulk_intptr)DAT_00424ae4);
    if (self->member) {
        FUN_0024af00(self->member);
        self->member = 0;
    }
}
} // namespace fn_001f3280

namespace fn_f7fca51a {

// 0x001f32b0 FUN_001f32b0 (191 B): equivalent/0x001f32b0.cpp
// sym: ?initialize@Object@fn_f7fca51a@@QAEHPAUResource_1f32b0@2@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// FUN_001f32b0 @ 0x001f32b0
int Object::initialize(Resource_1f32b0* input, int flag, int option) {
 if (!input) return 0;
 resource = input;
 int id = input->id;
 int context = (*(Manager_1f32b0**)&DAT_004e3690)->context;
 int created = FUN_0024ace0(context, ((int*)&DAT_004e58b8), id, FUN_00240750(), 3000, ((int*)&DAT_004c7e3c));
 handle = created;
 mode = (option & 255) ? 1.0f : 0.0f;
 FUN_00247890(created, (*(State_1f32b0**)&DAT_004e3760)->value);
 FUN_002478b0(handle, 1.0f);
 FUN_002478d0(handle, flag);
 FUN_00247900(handle, (flag & 255) ? 0 : option);
 resource->FUN_001e8a90();
 return 1;
}

} // namespace fn_f7fca51a

// 0x001f3370 FUN_001f3370 (62 B): matches/0x001f3370.cpp
// sym: ?FUN_001f3370@Obj_1f3370@owners@@QAEHH@Z
int owners::Obj_1f3370::FUN_001f3370(hulk_intptr arg) {
    int p = member;
    if (p == 0)
        return 0;
    int found = Find(p, ((int)arg));
    if (found == 0)
        return 0;
    Act(member, found, 1, 0, 0);
    return 1;
}


// 0x001f33b0 FUN_001f33b0 (80 B): matches/0x001f33b0.cpp
// sym: ?FUN_001f33b0@Obj_1f33b0@owners@@QAEXI@Z
void owners::Obj_1f33b0::FUN_001f33b0(u32_1f33b0 arg) {
    u32_1f33b0 x = Find(mArg, arg);
    if (x && !mResult) {
        mFlag = 0;
        u32_1f33b0 y = FUN_0024a9c0(mArg, x);
        mResult = y;
        FUN_00247a10(y);
        FUN_00247a20(mArg, mResult, 0, 1, 0);
    }
}


// 0x001f3400 FUN_001f3400 (84 B): matches/0x001f3400.cpp
// sym: ?FUN_001f3400@Obj_1f3400@owners@@QAEXI@Z
void owners::Obj_1f3400::FUN_001f3400(u32_1f3400 param) {
    Pair_1f3400 p;
    if (a != 0) {
        p.x = 0;
        p.y = param;
        F249A90(a, &p.x);
        F24A800(a, 0x32);
        if (b != 0) {
            F2497E0(b);
            b = 0;
        }
    }
}

namespace fn_f7fca51a {

// 0x001f3460 FUN_001f3460 (55 B): matches/0x001f3460.cpp
// sym: ?FUN_001f3460@fn_f7fca51a@@YIXPAUTarget_1f3460@1@PAX@Z
void __fastcall FUN_001f3460(Target_1f3460* self, void*) {
    Pair_1f3460 p;
    p.a = 0;
    p.b = 0xfa;
    FUN_00249a90(self->value, &p);
    FUN_0024a800(self->value, 0x32);
}

} // namespace fn_f7fca51a

// 0x001f34a0 FUN_001f34a0 (68 B): matches/0x001f34a0.cpp
// sym: ?FUN_001f34a0@Owner_1f34a0@owners@@QAEXHH@Z
void owners::Owner_1f34a0::FUN_001f34a0(hulk_intptr param2, int param3) {
    int found = FindThing(value, ((int)param2));
    if (found != 0) {
        int local[2];
        local[1] = param3;
        local[0] = 0;
        DoThing(value, found, local);
    }
}

namespace fn_f7fca51a {

// 0x001f34f0 FUN_001f34f0 (89 B): matches/0x001f34f0.cpp
// sym: ?Run@Obj_1f34f0@fn_f7fca51a@@QAEXXZ
void Obj_1f34f0::Run() {
    if (c)
        ((H*)c)->Run();
    c = 0;
    d = 0;
    if (i) {
        f2(i);
        i = 0;
    }
    if (b) {
        f3(b, 0);
        f4(b, 0x32);
        f5(b);
        b = 0;
    }
    e = 0;
}


// 0x001f3550 FUN_001f3550 (20 B): matches/0x001f3550.cpp
// sym: ?FUN_001f3550@fn_f7fca51a@@YIEPAUObj_1f3550@1@@Z
unsigned char __fastcall FUN_001f3550(Obj_1f3550* self) {
    if (self->member)
        return (unsigned char)FUN_00249b40(self->member);
    return 1;
}

} // namespace fn_f7fca51a

// 0x001f36e0 FUN_001f36e0 (54 B): matches/0x001f36e0.cpp
// sym: ?FUN_001f36e0@Object_1f36e0@owners@@QAEXXZ
void owners::Object_1f36e0::FUN_001f36e0() {
    ((owners::Pair_27af60 *)(((ThisCall_0027af60*)(this))))->FUN_0027af60(0, 0);
    field8 = 0;
    int* p = &fieldC;
    *p = FUN_002673a0(0, 0);
    field10 = 999;
    field14 = 0;
    field18 = 0;
}

namespace fn_f7fca51a {

// 0x001f3720 FUN_001f3720 (60 B): matches/0x001f3720.cpp
// sym: ?Set@Target_1f3720@fn_f7fca51a@@QAEXPAUPair_1f3720@2@HHHHE@Z
void Target_1f3720::Set(Pair_1f3720* p, int a, int b, int c, int d, unsigned char e) {
    ((owners::Pair_27af60 *)this)->FUN_0027af60(p->a, p->b);
    x = a;
    y = b;
    z = c;
    w = d;
    q = e;
}


// 0x001f3780 FUN_001f3780 (128 B): equivalent/0x001f3780.cpp
// sym: ?FUN_001f3780@Holder_1f3780@fn_f7fca51a@@QAEPAV12@XZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f3780 @ 0x001f3780
// 0x001f3780: constructor that resets two names, an id and four unit-scale slots
Holder_1f3780* Holder_1f3780::FUN_001f3780()
{
    name0.FUN_0027af00();
    name1.FUN_0027af00();
    id = 99;
    field_78 = 0;
    for (int i = 0; i < 4; i++) {
        slots[i].a = 0;
        slots[i].b = 0;
        slots[i].flag = 0;
        slots[i].sx = 1.0f;
        slots[i].sy = 1.0f;
        slots[i].sz = 1.0f;
    }
    field_120 = 0;
    return this;
}


// 0x001f3800 FUN_001f3800 (19 B): matches/0x001f3800.cpp
// sym: ?f@C_1f3800@fn_f7fca51a@@QAEXXZ
// Same code shape as 0x00090470 (propagated; names are from that function)
void C_1f3800::f() {
    ((S_1f3800*)((char*)this + 8))->h();
    ((S_1f3800*)this)->h();
}


// 0x001f3830 FUN_001f3830 (40 B): matches/0x001f3830.cpp
// sym: ?F@Thing_1f3830@fn_f7fca51a@@QAEPAU12@E@Z
Thing_1f3830* Thing_1f3830::F(unsigned char flags) {
    sub.Run();
    ((Helper_1f3830*)this)->Run();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f7fca51a

// 0x001f3860 FUN_001f3860 (54 B): matches/0x001f3860.cpp [wrapped: conflict: CSoundSequenceVoice]
// sym: ?FUN_001f3860@CSoundSequenceVoice@fn_001f3860@@QAEPAU12@E@Z
namespace fn_001f3860 {
typedef unsigned char byte_1f3860;
extern void __cdecl release(void*);
extern void __cdecl destroy(void*);
extern int vtable_1f3860;
struct CSoundSequenceVoice {
    int* vf;
    void* m;
    CSoundSequenceVoice* FUN_001f3860(byte_1f3860);
};
CSoundSequenceVoice* CSoundSequenceVoice::FUN_001f3860(byte_1f3860 flags) {
    vf = &vtable_1f3860;
    if (m) {
        release(m);
        m = 0;
    }
    if (flags & 1)
        destroy(this);
    return this;
}
} // namespace fn_001f3860

namespace fn_f7fca51a {

// 0x001f38a0 FUN_001f38a0 (139 B): matches/0x001f38a0.cpp
// sym: ?Release@Mgr_1f38a0@fn_f7fca51a@@QAEXXZ
void Mgr_1f38a0::Release() {
    int i = 0;
    for (i = 0; i < count; i++) {
        Item_1f38a0* it = items[i];
        if (it == skipA)
            continue;
        if (it == skipB)
            continue;
        void* h = it->h;
        if (h == 0)
            continue;
        Vec_1f38a0 v;
        v.x = 0;
        v.y = 0;
        FUN_00249a90(h, &v);
        FUN_0024a800(it->h, 0x32);
        void* b = it->buf;
        if (b != 0) {
            FUN_002497e0(b);
            it->buf = 0;
        }
    }
}


// 0x001f3930 FUN_001f3930 (21 B): matches/0x001f3930.cpp
// sym: ?FUN_001f3930@fn_f7fca51a@@YIXPAXH@Z
void __fastcall FUN_001f3930(void* self, int) {
    T_1f3930* p = *(T_1f3930**)((char*)self + 0xc0);
    if (p)
        ((owners::Obj_1f3400 *)p)->FUN_001f3400(0xfa);
}

} // namespace fn_f7fca51a

// 0x001f3950 FUN_001f3950 (62 B): matches/0x001f3950.cpp
// sym: ?FUN_001f3950@Obj_1f3950@owners@@QAEXM@Z
void owners::Obj_1f3950::FUN_001f3950(float value) {
    *(volatile float*)((hulk_intptr)((char*)&DAT_004c7df0)) = value;
    if (mPtr != 0 && mBusy == 0) {
        int x = *(int*)(mPtr + 4);
        if (x != 0)
            Apply(x, value * 0.01f);
    }
}


// 0x001f3990 FUN_001f3990 (62 B): matches/0x001f3990.cpp
// sym: ?FUN_001f3990@Thing_1f3990@owners@@QAEXM@Z
// data: gHundred = DAT_004c7df4
void owners::Thing_1f3990::FUN_001f3990(float x) {
    DAT_004c7df4 = x;
    if (mA && !mB) {
        int v = *(int*)(mA + 4);
        if (v)
            Apply(v, x * 0.01f);
    }
}

namespace fn_f7fca51a {

// 0x001f3a50 FUN_001f3a50 (122 B): equivalent/0x001f3a50.cpp
// sym: ?FUN_001f3a50@Player_1f3a50@fn_f7fca51a@@QAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001f3a50 @ 0x001f3a50
bool Player_1f3a50::FUN_001f3a50(int target, int arg) {
    if (!anim || !target)
        return false;
    if (anim->current != target) {
        anim->FUN_001f34f0();
        anim->FUN_001f32b0(target, 0, 0);
    }
    if (anim->next)
        FUN_00247890(anim->next, DAT_004c7df8 * speedScale * 0.01f);
    ((owners::Obj_1f3370 *)anim)->FUN_001f3370((hulk_intptr)arg);
    return true;
}


// 0x001f3ad0 FUN_001f3ad0 (30 B): matches/0x001f3ad0.cpp
// sym: ?run@Obj_1f3ad0@fn_f7fca51a@@QAE_NXZ
bool Obj_1f3ad0::run() {
    if (child && child->value) {
        ((owners::Obj_1f3400 *)child)->FUN_001f3400(0);
        return true;
    }
    return false;
}


// 0x001f3af0 FUN_001f3af0 (263 B): equivalent/0x001f3af0.cpp
// sym: ?run@Object@fn_f7fca51a@@QAE_NPAUItem_1f3af0@2@PAXPAUInput_1f3af0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 19971 inputs, branch coverage 16/16)
// FUN_001f3af0 @ 0x001f3af0
bool Object::run(Item_1f3af0* item,void* arg,Input_1f3af0* input) {
 if (!state || !item) return false;
 if (state->handle && !FUN_00249b40(state->handle)) return false;
 if (input->value > 75.0f) return false;
 if (state->item) {
  if (state->item != item) {
   ((owners::Obj_1f3400 *)state)->FUN_001f3400(250);
   state->item->FUN_001e8ac0();
   state->item=0;
   FUN_0024af00(state->handle);
   state->handle=0;
   state->active=false;
   state->FUN_001f32b0(item,0,0);
  }
 } else state->FUN_001f32b0(item,0,0);
 if(state->handle) FUN_00247890(state->handle,DAT_004c7df8 * scale * 0.01f);
 ((owners::Obj_1f3370 *)state)->FUN_001f3370((hulk_intptr)arg);
 return true;
}


// 0x001f3c00 FUN_001f3c00 (587 B): equivalent/0x001f3c00.cpp
// sym: ?FUN_001f3c00@Player_1f3c00@fn_f7fca51a@@QAE_NPAUVoice_1f3c00@2@PAHPAUId_1f3c00@2@PBDHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19351 inputs, branch coverage 50/50)
// FUN_001f3c00 @ 0x001f3c00
bool Player_1f3c00::FUN_001f3c00(Voice_1f3c00* voice, int* value, Id_1f3c00* id, const char* name, int qty, int flag)
{
    int count = slot.qty;
    if (count < 99) {
        if (qty > count)
            return false;
        int v = *value;
        ((owners::Pair_27af60 *)&slot)->FUN_0027af60(id->lo, id->hi);
        slot.voice = voice;
        slot.value = v;
        slot.qty = qty;
        slot.name = name;
        slot.flag = (char)flag;
        return true;
    }

    if (channel && channel->sound && !FUN_00249b40(channel->sound)) {
        int lim = limit;
        if (qty > lim)
            return false;
        if ((qty == 1 || qty == 3 || qty == 4) && lim == qty)
            return false;
    }

    int found = FUN_001f31a0(id);
    if (found == 0 && (id->lo | id->hi))
        return false;

    if (channel->voice) {
        if (channel->sound && !FUN_00249b40(channel->sound)) {
            ((owners::Obj_1f3400 *)channel)->FUN_001f3400(0xfa);
            slot.FUN_001f3720(id, voice, *value, qty, name, flag);
            return true;
        }
        if (channel->voice != voice) {
            channel->voice->FUN_001e8ac0();
            channel->voice = 0;
            FUN_0024af00(channel->sound);
            channel->sound = 0;
            channel->b14 = 0;
        }
    }

    if (channel->voice != voice)
        ((Init_1f3c00*)channel)->FUN_001f32b0(voice, found != 0, flag);
    channel->f10 = found;
    if (channel->sound)
        FUN_00247890(channel->sound, DAT_004c7df4 * volume * 0.01f);
    if (((owners::Obj_1f3370 *)channel)->FUN_001f3370((hulk_intptr)value) == 0)
        return false;

    limit = qty;
    if (channel->sound && !FUN_00249b40(channel->sound) && name && *name) {
        ((owners::ThisWrap_001e9a90 *)notifier)->FUN_001e9a90((hulk_intptr)name, 0x1f4);
        b94 = 1;
    }
    return true;
}

} // namespace fn_f7fca51a

// 0x001f3e50 FUN_001f3e50 (49 B): matches/0x001f3e50.cpp
// sym: ?FUN_001f3e50@Obj_1f3e50@owners@@QAEXHHHHMH@Z
void owners::Obj_1f3e50::FUN_001f3e50(int a, hulk_intptr b, int c, hulk_intptr d, float e, int f) {
    other(a, ((int)b), c, ((int)d), (int)e, f);
}


// 0x001f3e90 FUN_001f3e90 (46 B): matches/0x001f3e90.cpp
// sym: ?FUN_001f3e90@Obj_1f3e90@owners@@QAEXHHHMH@Z
void owners::Obj_1f3e90::FUN_001f3e90(int a, hulk_intptr b, int c, float d, int e) {
    fn(a, ((int)b), c, 0, (int)d, e);
}

namespace fn_f7fca51a {

// 0x001f3ec0 FUN_001f3ec0 (322 B): equivalent/0x001f3ec0.cpp
// sym: ?FUN_001f3ec0@VoicePool_1f3ec0@fn_f7fca51a@@QAEPAUVoice_1f3ec0@2@HHHHD@Z
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 27/28, incomplete)
// FUN_001f3ec0 @ 0x001f3ec0
Voice_1f3ec0 *VoicePool_1f3ec0::FUN_001f3ec0(int a, int unused, int flags, int c, char tag)
{
    int n = count;
    for (int i = 0; i < n; i++) {
        Voice_1f3ec0 *v = voices[i];
        if (v->sound == 0 && v != reserved8c && v != reservedCC && v != reservedC0
            && v != reservedC4 && v != reservedC8) {
            voices[i]->flags = flags;
            voices[i]->FUN_001f32b0(a, flags != 0, c);
            if (voices[i]->sound != 0)
                FUN_00247890(voices[i]->sound, DAT_004c7df8 * 0.01f * volumeScale);
            voices[i]->tag = tag;
            return voices[i];
        }
        n = count;
    }

    if (n >= 32)
        return 0;
    voices[n]->flags = flags;
    if (a != 0)
        voices[count]->FUN_001f32b0(a, flags != 0, c);
    count = count + 1;
    if (voices[count - 1]->sound != 0)
        FUN_00247890(voices[count - 1]->sound, DAT_004c7df8 * 0.01f * volumeScale);
    return voices[count - 1];
}

} // namespace fn_f7fca51a

// 0x001f4010 FUN_001f4010 (291 B): equivalent/0x001f4010.cpp [wrapped: conflict: Object]
// sym: ?target@Owner_1f4010@fn_001f4010@@QAEPAUEntry_1f4010@2@III@Z
namespace fn_001f4010 {
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 24/24)
// FUN_001f4010 @ 0x001f4010
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

struct Handle_1f4010 { unsigned a,b; void FUN_0027af70(unsigned); };
struct Object { char pad[0x18]; unsigned ready; };
struct Entry_1f4010 { Handle_1f4010 first,second; Object* objects[4]; unsigned results[4]; char pad30[0x44]; int type; char pad78[8]; struct Block { unsigned low,high,value; char pad[0x1c]; } blocks[4]; };
extern unsigned __cdecl FUN_002673a0(unsigned,unsigned);
extern "C++" __declspec(nothrow) void __cdecl FUN_001f3040(void *, void *);
struct Owner_1f4010 { char pad[0xd4]; Entry_1f4010* entries[148]; int count; unsigned FUN_001f3ec0(Object*,Entry_1f4010*,Entry_1f4010*,unsigned,unsigned); Entry_1f4010* target(hulk_uintptr,hulk_uintptr,unsigned); };
Entry_1f4010* Owner_1f4010::target(hulk_uintptr arg1,hulk_uintptr arg2,unsigned arg3) {
 Entry_1f4010* selected=0;
 int n=count;
 for(int i=0;i<n;++i) { Entry_1f4010* e=entries[i]; if((e->first.a|e->first.b)==0) selected=e; }
 if(!selected) { if(n>=148) return selected; selected=entries[n]; if(!selected) return selected; }
 selected->first.FUN_0027af70(arg2);
 selected->second.FUN_0027af70(arg1);
 for(int j=0;j<4;++j) selected->objects[j]=0;
 for(int k=0;k<4;++k) selected->results[k]=0;
 for(int b=0;b<4;++b) { unsigned __int64 v=FUN_002672f0(0,0,0); selected->blocks[b].low=(unsigned)v; selected->blocks[b].high=(unsigned)(v>>32); selected->blocks[b].value=FUN_002673a0(0,0); }
 ++count;
 FUN_001f3040((Entry_1f4010 *)selected,(void *)(hulk_uintptr)(unsigned)arg1);
 if(selected->type<=3 && selected->results[0]==0 && selected->objects[0] && selected->objects[0]->ready) {
 selected->results[0]=FUN_001f3ec0(selected->objects[0],selected,selected,1,0);
 if(selected->objects[1]) selected->results[1]=FUN_001f3ec0(selected->objects[1],selected,selected,1,0);
 }
 return selected;
}
} // namespace fn_001f4010
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f7fca51a {

// 0x001f4140 FUN_001f4140 (389 B): equivalent/0x001f4140.cpp
// sym: ?FUN_001f4140@Player_1f4140@fn_f7fca51a@@QAEX_N@Z
// STATUS: equivalent (tools/equiv.py level 3: 19961 inputs, branch coverage 30/30)
// FUN_001f4140 @ 0x001f4140
// FUN_001f4140 @ 0x001f4140
void Player_1f4140::FUN_001f4140(bool force)
{
    if (voice == 0) return;
    if (voice->sound != 0) {
        if (!FUN_00249b40(voice->sound)) return;
    }
    if (count >= 999) return;
    int r = FUN_001f31a0(&state);
    int group = ((owners::X_1ea010 *)names)->FUN_001ea010((hulk_intptr)"front_end");
    if (!force) {
        if (id != group) return;
    }
    if (voice->handle != id) {
        ((ThisNote_001e8ac0*)(voice->handle))->FUN_001e8ac0();
        voice->handle = 0;
        FUN_0024af00(voice->sound);
        voice->sound = 0;
        voice->finished = 0;
    }
    if (voice->handle == 0) {
        voice->FUN_001f32b0(id, r != 0, (unsigned char)vol);
    }
    voice->owner = r;
    if (voice->sound != 0) {
        FUN_00247890(voice->sound, DAT_004c7df4 * gain * 0.01f);
    }
    if (((owners::Obj_1f3370 *)voice)->FUN_001f3370((hulk_intptr)(&fac)) != 0) {
        f90 = count;
        if (voice->sound != 0) {
            if (!FUN_00249b40(voice->sound)) {
                if (name != 0) {
                    if (*name != 0) {
                        ((owners::ThisWrap_001e9a90 *)names)->FUN_001e9a90((hulk_intptr)name, 0x32);
                        f94 = 1;
                    }
                }
            }
        }
    }
    ((owners::Object_1f36e0 *)&state)->FUN_001f36e0();
}


// 0x001f42d0 FUN_001f42d0 (326 B): equivalent/0x001f42d0.cpp
// sym: ?FUN_001f42d0@Manager_1f42d0@fn_f7fca51a@@QAEXPBUId_1f42d0@2@PAXMMMIIIIIITIdSlot@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 13302 inputs, branch coverage 12/12)
// FUN_001f42d0 @ 0x001f42d0
// FUN_001f42d0 @ 0x001f42d0
void Manager_1f42d0::FUN_001f42d0(const Id_1f42d0 *id, void *owner, float px, float py, float pz,
                           unsigned int a6, unsigned int a7, unsigned int a8,
                           unsigned int a9, unsigned int a10, unsigned int a11,
                           IdSlot a12, int a15)
{
    Node *n = FUN_001f31a0(id);
    if (n == 0) {
        n = ((ThisCall_001f4010*)(this))->FUN_001f4010(owner, id, a15);
        if (n == 0)
            return;
    }
    if (n->limit > a15)
        n->limit = a15;
    n->x = px;
    n->y = py;
    n->z = pz;
    n->f54 = a12.raw[0];
    n->f58 = a12.raw[1];
    n->f5c = a12.raw[2];
    n->f78 = 0;
    if (DAT_004dd700->gate->FUN_000997a0()) {
        a12.id.FUN_0027b0e0("hulk");
        Node *p = FUN_001f31a0(&a12.id);
        if (p) {
            px = px - p->x;
            py = py - p->y;
            pz = pz - p->z;
        }
        a12.id.FUN_0027af50();
    } else {
        Node *p = parent;
        if (p) {
            px = px - p->x;
            py = py - p->y;
            pz = pz - p->z;
        }
    }
    n->dist = (float)sqrt(pz * pz + py * py + px * px);
    n->f3c = a6;
    n->f40 = a7;
    n->f44 = a8;
    n->f48 = a9;
    n->f4c = a10;
    n->f50 = a11;
    n->flag70 = 1;
}

} // namespace fn_f7fca51a

// 0x001f4420 FUN_001f4420 (489 B): equivalent/0x001f4420.cpp [wrapped: conflict: FUN_002673a0]
// sym: ?FUN_001f4420@ThisWrap_001f4420@fn_001f4420@@QAEXH@Z
namespace fn_001f4420 {
// STATUS: equivalent (tools/equiv.py level 3: 4899 inputs, branch coverage 28/28)
// FUN_001f4420 @ 0x001f4420
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

struct Name_1f4420 {
    unsigned int lo, hi;
};

struct Ptr_1f4420 {
    char pad0[4];
};

struct Item_1f4420 {
    char pad0[4];
};

struct Params {
    int a;
    int b;
};

struct Linked_1f4420 {
    void FUN_001e8ac0();
};

struct Slot_1f4420 {
    char pad0[4];
    Ptr_1f4420 *p;
    Linked_1f4420 *linked;
    char padc[4];
    int f10;
    char f14;
    char pad15[3];
    void *buf;
};

struct Entry_1f4420 {
    unsigned int lo;
    unsigned int hi;
    void *value;
    char pad0c[0x28 - 0xc];
};

struct Obj_1f4420 {
    Name_1f4420 nameA;
    Name_1f4420 nameB;
    int active[4];
    Slot_1f4420 *slots[4];
    char pad30[0x60 - 0x30];
    int f60;
    int f64;
    int f68;
    char pad6c[0x74 - 0x6c];
    int f74;
    int f78;
    char pad7c[0x80 - 0x7c];
    Entry_1f4420 entries[4];
};

void *__cdecl FUN_002673a0(int a, int b);
Item_1f4420 *__cdecl FUN_0024a370(Ptr_1f4420 *p, void *key);
void __cdecl FUN_00249bd0(Ptr_1f4420 *p, Item_1f4420 *item, Params *params);
void __cdecl FUN_002497e0(void *buf);
void __cdecl FUN_00249a90(Ptr_1f4420 *p, int x);
void __cdecl FUN_0024a800(Ptr_1f4420 *p, int x);
void __cdecl FUN_0024af00(Ptr_1f4420 *p);
struct ThisWrap_001f4420 {
    Obj_1f4420 * FUN_001f31a0(int arg);
    void FUN_001f4420(hulk_intptr arg);
};

void ThisWrap_001f4420::FUN_001f4420(hulk_intptr arg) {
    Obj_1f4420 *obj = this->FUN_001f31a0(arg);
    if (!obj)
        return;

    for (int i = 0; i < 4; i++) {
        Entry_1f4420 *e = &obj->entries[i];
        unsigned __int64 h = FUN_002672f0(0, 0, 0);
        if (e->lo == (unsigned int)h && e->hi == (unsigned int)(h >> 32))
            continue;
        for (int j = 0; j < 4; j++) {
            Slot_1f4420 *s = obj->slots[j];
            if (obj->active[j] && s) {
                Item_1f4420 *item = FUN_0024a370(s->p, &e->value);
                if (item) {
                    Params params;
                    params.a = 0;
                    params.b = 0xc8;
                    FUN_00249bd0(s->p, item, &params);
                }
            }
        }
        h = FUN_002672f0(0, 0, 0);
        e->lo = (unsigned int)h;
        e->hi = (unsigned int)(h >> 32);
        e->value = FUN_002673a0(0, 0);
    }

    for (int j = 0; j < 4; j++) {
        Slot_1f4420 *s = obj->slots[j];
        if (s) {
            if (s->linked)
                s->linked->FUN_001e8ac0();
            void *buf = s->buf;
            s->linked = 0;
            s->f10 = 0;
            if (buf) {
                FUN_002497e0(buf);
                s->buf = 0;
            }
            if (s->p) {
                FUN_00249a90(s->p, 0);
                FUN_0024a800(s->p, 0x32);
                FUN_0024af00(s->p);
                s->p = 0;
            }
            s->f14 = 0;
            obj->slots[j]->f10 = 0;
            obj->slots[j] = 0;
        }
    }

    obj->f74 = 0x63;
    obj->f78 = 0;
    obj->f64 = 0;
    obj->f60 = 0;
    obj->f68 = 0;
    ((owners::Target_27b040 *)&(obj->nameA))->FUN_0027b040((hulk_uintptr)0);
    ((owners::Target_27b040 *)&(obj->nameB))->FUN_0027b040((hulk_uintptr)0);
    obj->active[0] = 0;
    obj->slots[0] = 0;
    obj->active[1] = 0;
    obj->slots[1] = 0;
    obj->active[2] = 0;
    obj->slots[2] = 0;
    obj->active[3] = 0;
    obj->slots[3] = 0;
    for (int i = 0; i < 4; i++) {
        unsigned __int64 h = FUN_002672f0(0, 0, 0);
        obj->entries[i].lo = (unsigned int)h;
        obj->entries[i].hi = (unsigned int)(h >> 32);
        obj->entries[i].value = FUN_002673a0(0, 0);
    }
}
} // namespace fn_001f4420
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f7fca51a {

// 0x001f4610 FUN_001f4610 (144 B): matches/0x001f4610.cpp
// sym: ?Fn@Obj_1f4610@fn_f7fca51a@@QAEXDDD@Z
void Obj_1f4610::Fn(char x, char y, char z) {
    if (++guard == 1) {
        for (int i = 0; i < count; ++i) {
            Item_1f4610* v = list[i];
            if (v == a) {
                if (!x)
                    continue;
            } else if (v == b) {
                if (!y)
                    continue;
            } else if (v == c) {
                if (!z)
                    continue;
            } else if (v == d)
                continue;
            if (v->h)
                Wait(v->h, 500);
        }
    }
}


// 0x001f46a0 FUN_001f46a0 (100 B): matches/0x001f46a0.cpp
// sym: ?Fn@Obj_1f46a0@fn_f7fca51a@@QAEXXZ
void Obj_1f46a0::Fn() {
    int x = state;
    if (x == 1) {
        state = 0;
        for (int i = 0; i < count; ++i) {
            int v = items[i]->value;
            if (v)
                FUN_00247970(v, 500);
        }
    } else if (x > 1)
        state = x - 1;
}


// 0x001f4710 FUN_001f4710 (152 B): equivalent/0x001f4710.cpp
// sym: ?FUN_001f4710@Player_1f4710@fn_f7fca51a@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 2135 inputs, branch coverage 12/12)
// FUN_001f4710 @ 0x001f4710
bool Player_1f4710::FUN_001f4710()
{
    for (int i = 0; i < count; i++) {
        if (items[i]->handle != 0 && !FUN_00249b40(items[i]->handle)) {
            Item_1f4710* it = items[i];
            if (it->handle != 0) {
                Fade_1f4710 f;
                f.a = 0;
                f.b = 0xfa;
                FUN_00249a90(it->handle, &f);
                FUN_0024a800(it->handle, 0x32);
                if (it->extra != 0) {
                    FUN_002497e0(it->extra);
                    it->extra = 0;
                }
            }
            return true;
        }
    }
    return false;
}


// 0x001f47b0 FUN_001f47b0 (142 B): equivalent/0x001f47b0.cpp
// sym: ?FUN_001f47b0@Owner_1f47b0@fn_f7fca51a@@QAE_NPAUKey_1f47b0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 10/10)
// FUN_001f47b0 @ 0x001f47b0
bool Owner_1f47b0::FUN_001f47b0(Key_1f47b0 *key) {
    if (key && key->lo == timer.key.lo && key->hi == timer.key.hi) {
        ((owners::Pair_27af60 *)&timer)->FUN_0027af60(0, 0);
        timer.field08 = 0;
        timer.field0c = FUN_002673a0(0, 0);
        timer.field10 = 999;
        timer.field14 = 0;
        timer.field18 = 0;
    }
    Target_1f47b0 *t = target;
    if (t) {
        int current = FUN_001f31a0(key); // MSVC calls this before reading t->expected; clang would read t->expected first
        if (t->expected == current) {
            ((owners::Obj_1f3400 *)t)->FUN_001f3400(250);
            return true;
        }
    }
    return false;
}


// 0x001f4980 FUN_001f4980 (89 B): matches/0x001f4980.cpp
// sym: ?Fn@Method3_1f4980@fn_f7fca51a@@QAEPAV12@PBDP8ScriptBoundClass@@AEXXZ@Z
Method3_1f4980* Method3_1f4980::Fn(const char* p, ScriptMemberFn v) {
    Init(p, 3);
    vf = ((hulk_intptr)DAT_00424b0c);
    a = v;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    return this;
}

} // namespace fn_f7fca51a

// 0x001f49e0 Method3<CSoundVoiceManager,void,bool,bool,bool>::vfunc_0 (30 B): matches/0x001f49e0.cpp
// sym: ??_G?$Method3@VCSoundVoiceManager@@X_N_N_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CSoundVoiceManager, void, bool, bool, bool>::~Method3() {}


// 0x001f4a00 Method3<CSoundVoiceManager,void,bool,bool,bool>::vfunc_2 (38 B): equivalent/0x001f4a00.cpp
// sym: ?vfunc_2@?$Method3@VCSoundVoiceManager@@X_N_N_N@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CSoundVoiceManager,void,bool,bool,bool>::vfunc_2 @ 0x001f4a00
template <> void Method3<CSoundVoiceManager, void, bool, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundVoiceManager_1f4a00 * manager = (CSoundVoiceManager_1f4a00 *)__p0; Args * args = (Args *)__p1; void * unused = (void *)__p2;

    unsigned int first = ((hulk_uintptr)args & ~255u) | args->first;
    (manager->*(*(void (CSoundVoiceManager_1f4a00::**)(unsigned int, unsigned int, unsigned int))&this->f_1c))(first, args->second, args->third);
}


// 0x001f4a70 Method0<CSoundVoiceManager,void>::vfunc_0 (30 B): matches/0x001f4a70.cpp
// sym: ??_G?$Method0@VCSoundVoiceManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CSoundVoiceManager, void>::~Method0() {}


// 0x001f4a90 Method0<CSoundVoiceManager,void>::vfunc_2 (12 B): matches/0x001f4a90.cpp
// sym: ?vfunc_2@?$Method0@VCSoundVoiceManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<CSoundVoiceManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1f4a90 * a = (CActorManager_1f4a90 *)__p0;

    (a->*(*(void (CActorManager_1f4a90::**)())&this->f_1c))();
}

namespace fn_f7fca51a {

// 0x001f4aa0 FUN_001f4aa0 (102 B): matches/0x001f4aa0.cpp
// sym: ??0Method4_1f4aa0@fn_f7fca51a@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
Method4_1f4aa0::Method4_1f4aa0(const char* a, ScriptMemberFn b) {
    ((ThisCall_001d0480*)(this))->Init(a, 4);
    vptr = ((hulk_intptr)DAT_00424b2c);
    m1c = b;
    f.retType = Get((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = Get((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[1] = Get((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[2] = Get((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    f.argTypes[3] = Get((void*)((hulk_intptr)((char*)&DAT_0048e134)));
}

} // namespace fn_f7fca51a

// 0x001f4b10 Method4<CSoundVoiceManager,void,char_*,char_*,char_*,int>::vfunc_0 (30 B): matches/0x001f4b10.cpp
// sym: ??_G?$Method4@VCSoundVoiceManager@@XPADPADPADH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CSoundVoiceManager, void, char *, char *, char *, int>::~Method4() {}


// 0x001f4b30 Method4<CSoundVoiceManager,void,char_*,char_*,char_*,int>::vfunc_2 (40 B): equivalent/0x001f4b30.cpp
// sym: ?vfunc_2@?$Method4@VCSoundVoiceManager@@XPADPADPADH@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method4<CSoundVoiceManager,void,char_*,char_*,char_*,int>::vfunc_2 @ 0x001f4b30
template <> void Method4<CSoundVoiceManager, void, char *, char *, char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundVoiceManager_1f4b30 * object = (CSoundVoiceManager_1f4b30 *)__p0; void ** arguments = (void **)__p1; void * unused = (void *)__p2;

    (object->*(*(void (CSoundVoiceManager_1f4b30::**)(char *, char *, char *, int))&this->f_1c))((char *)arguments[0], (char *)arguments[1], (char *)arguments[2], (hulk_intptr)arguments[3]);
}

namespace fn_f7fca51a {

// 0x001f4b60 FUN_001f4b60 (63 B): matches/0x001f4b60.cpp
// sym: ?target@fn_f7fca51a@@YIPAVObj_1f4b60@1@PAV21@PAX@Z
Obj_1f4b60* __fastcall target(Obj_1f4b60* self, void*) {
    self->first();
    ((owners::Pair_27af60 *)self)->FUN_0027af60(0, 0);
    self->a = 0;
    self->b = f2(0, 0);
    self->c = 999;
    self->d = 0;
    self->e = 0;
    return self;
}

} // namespace fn_f7fca51a

// 0x001f4ba0 FUN_001f4ba0 (170 B): equivalent/0x001f4ba0.cpp [wrapped: conflict: FUN_002673a0; Object]
// sym: ?FUN_001f4ba0@Object@fn_001f4ba0@@QAEPAU12@I@Z
namespace fn_001f4ba0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f4ba0 @ 0x001f4ba0

struct State_1f4ba0 {
 unsigned int first, second, value, handle, limit, extra;
 unsigned char flag;
 char pad[7];
 void FUN_0027af00();
};
extern unsigned int __cdecl FUN_002673a0(int,int);
struct Object;
struct Object {
 char pad0[0x88];
 unsigned int f88, f8c;
 char pad90[8];
 unsigned int f98, f9c;
 State_1f4ba0 state;
 unsigned int fc0, fc4, fc8, fcc, fd0;
 char padd4[0x324-0xd4];
 unsigned int f324, f328, f32c, f330;
 float f334;
 unsigned int argument;
 Object* FUN_001f4ba0(hulk_uintptr arg);
};
Object* Object::FUN_001f4ba0(hulk_uintptr arg) {
 state.FUN_0027af00();
 ((owners::Pair_27af60 *)&state)->FUN_0027af60(0, 0);
 state.value=0;
 state.handle=FUN_002673a0(0,0);
 state.extra=0;
 state.flag=0;
 state.limit=999;
 argument=arg;
 f88=0;
 f324=0; f328=0; f32c=0; f330=0;
 fd0=0; f98=0; f9c=0; f8c=0;
 fc0=0; fcc=0; fc4=0; fc8=0;
 f334=1.0f;
 (*(Object**)&DAT_004e3760)=this;
 return this;
}
} // namespace fn_001f4ba0

namespace fn_f7fca51a {

// 0x001f4c50 FUN_001f4c50 (649 B): equivalent/0x001f4c50.cpp
// sym: ?FUN_001f4c50@Sound_1f4c50@fn_f7fca51a@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 19813 inputs, branch coverage 12/12)
// FUN_001f4c50 @ 0x001f4c50
void Sound_1f4c50::FUN_001f4c50()
{
    Name_1f4c50 nm;
    nm.FUN_0027b0e0("vo_camera");
    props = FUN_001f4010(&nm, &nm, 0);
    if (props != 0) {
        props->f40 = 0;
        props->f44 = 0;
        props->f3c = 1.0f;
        props->v30.Set(0, 0, 0);
        props->v48.Set(0, 1.0f, 0);
        props->f74 = 0;
    }
    v8c = v8;
    if (v8->f4 != 0)
        FUN_00247890(v8->f4, DAT_004c7df4 * 0.01f * volume);
    v8c->flag = 1;
    f90 = -1;
    f94 = 0;
    vcc = vc;
    ID &h = *(ID *)nm.tail;
    h = FUN_002672f0("front_end", 0, 0);
    void * arg1 = mixer->FUN_001e98b0(&h);
    vcc->FUN_001f32b0(arg1, 0, 0);
    if (vcc->f4 != 0)
        FUN_00247890(vcc->f4, DAT_004c7df8 * 0.01f * volume);

    vc0 = v10;
    h = FUN_002672f0("fe", 0, 0);
    void * arg2 = mixer->FUN_001e98b0(&h);
    vc0->FUN_001f32b0(arg2, 0, 0);
    if (vc0->f4 != 0)
        FUN_00247890(vc0->f4, DAT_004c7df0 * 0.01f * volume);

    vc4 = v14;
    h = FUN_002672f0("bgambience", 0, 0);
    void * arg3 = mixer->FUN_001e98b0(&h);
    vc4->FUN_001f32b0(arg3, 0, 0);
    if (vc4->f4 != 0)
        FUN_00247890(vc4->f4, DAT_004c7df8 * 0.01f * volume);
    vc4->flag = 1;

    vc8 = v18;
    h = FUN_002672f0("explosions", 0, 0);
    void * arg4 = mixer->FUN_001e98b0(&h);
    vc8->FUN_001f32b0(arg4, 0, 1);
    if (vc8->f4 != 0)
        FUN_00247890(vc8->f4, DAT_004c7df8 * 0.01f * volume);
    vc8->flag = 1;
    f88 = 5;
    nm.FUN_0027af50();
}

} // namespace fn_f7fca51a

// 0x001f4f00 FUN_001f4f00 (1470 B): equivalent/0x001f4f00.cpp [wrapped: conflict: FUN_002673a0; Node]
// sym: ?reset@State_1f4f00@fn_001f4f00@@QAEXXZ
namespace fn_001f4f00 {
// STATUS: equivalent (tools/equiv.py level 3: 25 inputs, branch coverage 86/86)
// FUN_001f4f00 @ 0x001f4f00
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

typedef unsigned long U_1f4f00; typedef unsigned __int64 Q_1f4f00;
struct Pair_1f4f00 { U_1f4f00 a,b; };
U_1f4f00 __cdecl FUN_002673a0(int,int);
void __cdecl FUN_00249a90(U_1f4f00,Pair_1f4f00*);
void __cdecl FUN_0024a800(U_1f4f00,int);
void __cdecl FUN_002497e0(U_1f4f00);
void __cdecl FUN_0024af00(U_1f4f00);
bool __cdecl FUN_00249b40(U_1f4f00);
void __cdecl FUN_00240bb0();
void __cdecl FUN_002656a0();
struct Small_1f4f00 { char pad[8]; void FUN_0027b040(int); void FUN_0027af60(int,int); };
struct Block_1f4f00 { Small_1f4f00 first,second; U_1f4f00 values[8]; char pad[0x74-0x30]; U_1f4f00 type,flag; char gap[4]; struct Entry { Q_1f4f00 q; U_1f4f00 r; char pad[28]; } entries[4]; };
struct Resource_1f4f00 { void FUN_001e8ac0(); };
struct Node { U_1f4f00 unknown,handle; Resource_1f4f00* resource; U_1f4f00 other,state; unsigned char active; char pad[3]; U_1f4f00 allocation; void FUN_001f4940(); };
struct State_1f4f00 { char pad0[8]; Node* nodes[32]; int count; Node* primary; int index; char pad94[12]; Small_1f4f00 small; U_1f4f00 s8,sC,s10,s14; unsigned char s18; char padB9[7]; Node* extra[4]; U_1f4f00 padD0; Block_1f4f00* blocks[148]; U_1f4f00 reset324,reset328; U_1f4f00 pad32C; int pending; void FUN_001f46a0(); void reset(); };
void State_1f4f00::reset(){
 while(pending>0) FUN_001f46a0();
 for(int i=0;i<148;++i){
 blocks[i]->type=99; blocks[i]->flag=0;
 blocks[i]->first.FUN_0027b040(0); blocks[i]->second.FUN_0027b040(0);
 blocks[0]->values[0]=0; blocks[0]->values[4]=0;
 blocks[1]->values[1]=0; blocks[1]->values[5]=0;
 blocks[2]->values[2]=0; blocks[2]->values[6]=0;
 blocks[3]->values[3]=0; blocks[3]->values[7]=0;
 for(int j=0;j<4;++j){ Q_1f4f00 q=FUN_002672f0(0,0,0); blocks[j]->entries[j].q=q; U_1f4f00 r=FUN_002673a0(0,0); blocks[j]->entries[j].r=r; }
 }
 reset328=0; reset324=0; small.FUN_0027af60(0,0); s8=0; sC=FUN_002673a0(0,0); s10=999; s14=0; s18=0;
 for(int k=0;k<5;++k){
 Node** slot=k==0?&primary: k==1?&extra[3]:&extra[k-2];
 if(k==1) index=-1;
 Node* n=*slot;
 if(n){
 if(n->handle){ Pair_1f4f00 p={0,0}; FUN_00249a90(n->handle,&p); FUN_0024a800(n->handle,50); if(n->allocation){FUN_002497e0(n->allocation); n->allocation=0;} }
 (*slot)->FUN_001f4940(); n=*slot;
 if(n->resource) n->resource->FUN_001e8ac0();
 U_1f4f00 a=n->allocation; n->resource=0; n->state=0;
 if(a){FUN_002497e0(a); n->allocation=0;}
 if(n->handle){ FUN_00249a90(n->handle,0); FUN_0024a800(n->handle,50); FUN_0024af00(n->handle); n->handle=0; }
 n->active=0; *slot=0;
 }
 }
 for(int t=0;t<count;++t){
 Node* n=nodes[t];
 if(n->handle){Pair_1f4f00 p={0,0}; FUN_00249a90(n->handle,&p); FUN_0024a800(n->handle,50); if(n->allocation){FUN_002497e0(n->allocation); n->allocation=0;}}
 n=nodes[t];
 while(n->handle){if(FUN_00249b40(n->handle)) break; FUN_0024a800(n->handle,10); FUN_00240bb0(); FUN_002656a0();}
 n=nodes[t]; if(n->resource) n->resource->FUN_001e8ac0(); U_1f4f00 a=n->allocation; n->resource=0; n->state=0;
 if(a){FUN_002497e0(a); n->allocation=0;}
 if(n->handle){FUN_00249a90(n->handle,0); FUN_0024a800(n->handle,50); FUN_0024af00(n->handle); n->handle=0;} n->active=0;
 }
 count=0; pending=0;
}
} // namespace fn_001f4f00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001f54c0 FUN_001f54c0 (380 B): equivalent/0x001f54c0.cpp [wrapped: conflict: CSoundSequenceVoice]
// sym: ?FUN_001f54c0@SoundMgr@fn_001f54c0@@QAEXXZ
namespace fn_001f54c0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_001f54c0 @ 0x001f54c0


void FUN_0008d330(void* p);
void FUN_002497e0(void* p);
void FUN_00249a90(void* handle, void* out);
void FUN_0024a800(void* handle, int arg);
bool FUN_00249b40(void* handle);
void FUN_0024af00(void* handle);
extern "C" void FUN_00240bb0();
void FUN_002656a0();

struct Part_1f54c0 {
    char data[8];
    void FUN_0027af50();
};

struct Buffer_1f54c0 {
    Part_1f54c0 first;
    Part_1f54c0 second;
};

struct Emitter_1f54c0 {
    void FUN_001e8ac0();
};

class CSoundSequenceVoice {
public:
    virtual void v0();
    void* handle;
    Emitter_1f54c0* emitter;
    int pad0c;
    int f10;
    char f14;
    char pad15[3];
    void* extra;
};

struct StopState {
    int a;
    int b;
};

class SoundMgr {
public:
    char pad00[8];
    CSoundSequenceVoice* voices[32];
    int voiceCount;
    char pad8c[0xd4 - 0x8c];
    Buffer_1f54c0* buffers[0x94];
    int f324;
    void FUN_001f54c0();
};

void SoundMgr::FUN_001f54c0()
{
    for (int i = 0; i < 0x94; i++) {
        Buffer_1f54c0* b = buffers[i];
        if (b) {
            b->second.FUN_0027af50();
            b->first.FUN_0027af50();
            FUN_0008d330(b);
        }
        buffers[i] = 0;
    }
    f324 = 0;
    if (voiceCount <= 0) {
        voiceCount = 0;
        return;
    }
    for (int i = 0; i < voiceCount; i++) {
        CSoundSequenceVoice* v = voices[i];
        if (v->handle) {
            StopState st;
            st.a = 0;
            st.b = 0;
            FUN_00249a90(v->handle, &st);
            FUN_0024a800(v->handle, 0x32);
            if (v->extra) {
                FUN_002497e0(v->extra);
                v->extra = 0;
            }
        }
        v = voices[i];
        while (v->handle) {
            if (FUN_00249b40(v->handle))
                break;
            FUN_0024a800(v->handle, 10);
            FUN_00240bb0();
            FUN_002656a0();
        }
        v = voices[i];
        if (v->emitter)
            v->emitter->FUN_001e8ac0();
        void* extra = v->extra;
        v->emitter = 0;
        v->f10 = 0;
        if (extra) {
            FUN_002497e0(extra);
            v->extra = 0;
        }
        if (v->handle) {
            FUN_00249a90(v->handle, 0);
            FUN_0024a800(v->handle, 0x32);
            FUN_0024af00(v->handle);
            v->handle = 0;
        }
        v->f14 = 0;
        v = voices[i];
        if (v) {
            void* handle = v->handle;
            new (v) CSoundSequenceVoice;
            if (handle) {
                FUN_0024af00(handle);
                v->handle = 0;
            }
            FUN_0008d330(v);
        }
        voices[i] = 0;
    }
    voiceCount = 0;
}
} // namespace fn_001f54c0

namespace fn_f7fca51a {

// 0x001f5640 FUN_001f5640 (101 B): equivalent/0x001f5640.cpp
// sym: ?FUN_001f5640@Player_1f5640@fn_f7fca51a@@QAEDHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 6/6)
// FUN_001f5640 @ 0x001f5640
char Player_1f5640::FUN_001f5640(int obj, int arg)
{
    if (fc0 == 0 || obj == 0)
        return 0;
    if (fc0->f8 != obj) {
        fc0->FUN_001f34f0();
        fc0->FUN_001f32b0(obj, 0, 0);
    }
    ((owners::Obj_1f3950 *)this)->FUN_001f3950(DAT_004c7df0 * f334);
    ((owners::Obj_1f3370 *)fc0)->FUN_001f3370((hulk_intptr)arg);
    return 1;
}

} // namespace fn_f7fca51a

// 0x001f56b0 FUN_001f56b0 (293 B): equivalent/0x001f56b0.cpp [wrapped: conflict: Object]
// sym: ?FUN_001f56b0@Object@fn_001f56b0@@QAE_NPAXH@Z
namespace fn_001f56b0 {
// STATUS: equivalent (tools/equiv.py level 3: 20011 inputs, branch coverage 16/16)
// FUN_001f56b0 @ 0x001f56b0
struct Resource_1f56b0 {
 char pad0[4]; void* handle; void* owner; char pad12[12]; int active;
 void FUN_001f34f0();
 void FUN_001f32b0(void*,int,int);
};
extern bool __cdecl FUN_00249b40(void*);
extern int __cdecl FUN_002673a0(const char*,int);
extern void __cdecl FUN_00247890(void*,float);
extern void __cdecl thunk_FUN_00270a50();
extern void __cdecl FUN_002656a0();
extern void __cdecl FUN_0024a800(void*,int);
struct Object {
 char pad0[0xc8]; Resource_1f56b0* resource; char padcc[0x334-0xcc]; float scale;
 bool FUN_001f56b0(void* owner,int value);
};
bool Object::FUN_001f56b0(void* owner,int value) {
 if (!resource || !owner) return false;
 if (resource->handle && !FUN_00249b40(resource->handle)) {
 ((owners::Obj_1f3400 *)resource)->FUN_001f3400(0); ((owners::Thing_1f4940 *)resource)->FUN_001f4940();
 }
 if (resource->active) {
 if (resource->owner == owner) return false;
 ((owners::Obj_1f3400 *)resource)->FUN_001f3400(0); ((owners::Thing_1f4940 *)resource)->FUN_001f4940();
 }
 resource->FUN_001f34f0();
 resource->FUN_001f32b0(owner,0,0);
 int init = FUN_002673a0("init",0);
 ((owners::Obj_1f3370 *)resource)->FUN_001f3370((hulk_intptr)(&init));
 ((owners::Obj_1f33b0 *)resource)->FUN_001f33b0((unsigned int)value);
 if (resource->handle) FUN_00247890(resource->handle,DAT_004c7df8 * scale * 0.01f);
 if (!resource->active) return false;
 thunk_FUN_00270a50();
 FUN_002656a0();
 FUN_0024a800(resource->handle,0);
 return true;
}
} // namespace fn_001f56b0

namespace fn_f7fca51a {

// 0x001f57e0 FUN_001f57e0 (125 B): equivalent/0x001f57e0.cpp
// sym: ?FUN_001f57e0@Registry_1f57e0@fn_f7fca51a@@QAE_KXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001f57e0 @ 0x001f57e0
// Walks the list for the first entry that casts to the wanted type and returns its pair.
unsigned __int64 Registry_1f57e0::FUN_001f57e0()
{
    if (list == 0)
        return 0;
    for (Item* item = FUN_002495c0(list); item; item = FUN_002495e0(list, item)) {
        void* key = FUN_002495f0(item);
        if (key) {
            Found_1f57e0* f = (Found_1f57e0*)FUN_00344e74(FUN_00249610(list, key), 0, DAT_004c7eb4, DAT_004c7ed4, 0);
            if (f) {
                union {
                    Pair_1f57e0 pair;
                    unsigned __int64 packed;
                } r;
                r.pair = f->inner->value;
                return r.packed;
            }
        }
    }
    return 0;
}


// 0x001f5860 FUN_001f5860 (413 B): matches/0x001f5860.cpp
// sym: ?FUN_001f5860@SoundSlot@fn_f7fca51a@@QAEXM@Z
// FUN_001f5860 @ 0x001f5860
void SoundSlot::FUN_001f5860(float dt)
{
    if (voice) {
        if (FUN_002478f0(voice)) {
            if (params)
                FUN_002485c0(voice, params + 0x30, 0, param28);
        }
        FUN_0024a800(voice, (int)(dt * 1000.0f));
    }
    if (sound) {
        if (pending && FUN_00247930(voice, sound) == 2) {
            FUN_00247a90(voice, sound, 0);
            pending = 0;
        } else if (FUN_00247930(voice, sound) == 0) {
            FUN_002497e0(sound);
            sound = 0;
        }
    }
    if (!active || owner->emitter == 0)
        return;

    unsigned __int64 next = 0;
    if (sound == 0 || FUN_00247930(voice, sound) == 4)
        next = FUN_001f57e0();

    if (current == 0 && next != 0) {
        owner->emitter->start(next);
        current = next;
        return;
    }
    if (current != 0 && next == 0) {
        owner->emitter->stop(current);
        current = 0;
        return;
    }
    if (current != 0 && next != 0 && current != next) {
        owner->emitter->stop(current);
        owner->emitter->start(next);
        current = next;
        return;
    }
    if (current != 0) {
        if (voice == 0 || FUN_001f3550()) {
            owner->emitter->stop(current);
            current = 0;
        }
    }
}

} // namespace fn_f7fca51a

// 0x001f5a50 Closure3<CSoundVoiceManager,void,bool,bool,bool>::vfunc_2 (37 B): equivalent/0x001f5a50.cpp
// sym: ?vfunc_2@?$Closure3@VCSoundVoiceManager@@X_N_N_N@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSoundVoiceManager,void,bool,bool,bool>::vfunc_2 @ 0x001f5a50
template <> void Closure3<CSoundVoiceManager, void, bool, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; Args * args = (Args *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

 ((*(CSoundVoiceManager_1f5a50 * *)&this->f_20)->*(*(void (CSoundVoiceManager_1f5a50::**)(unsigned int, unsigned int, unsigned int))&this->f_1c))((reinterpret_cast<hulk_uintptr>(args) & ~255u) | args->first,args->second,args->third);
}


// 0x001f5ae0 Closure0<CSoundVoiceManager,void>::vfunc_2 (11 B): matches/0x001f5ae0.cpp
// sym: ?vfunc_2@?$Closure0@VCSoundVoiceManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<CSoundVoiceManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_1f5ae0 * *)&this->f_20)->*(*(void (CActorManager_1f5ae0::**)())&this->f_1c))();
}


// 0x001f5b40 Closure4<CSoundVoiceManager,void,char_*,char_*,char_*,int>::vfunc_2 (39 B): equivalent/0x001f5b40.cpp
// sym: ?vfunc_2@?$Closure4@VCSoundVoiceManager@@XPADPADPADH@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CSoundVoiceManager,void,char_*,char_*,char_*,int>::vfunc_2 @ 0x001f5b40
template <> void Closure4<CSoundVoiceManager, void, char *, char *, char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { VoiceArgs * arguments = (VoiceArgs *)__p1;

    ((*(CSoundVoiceManager_1f5b40 * *)&this->f_20)->*(*(void (CSoundVoiceManager_1f5b40::**)(char *, char *, char *, int))&this->f_1c))(arguments->first, arguments->second, arguments->third, arguments->fourth);
}


// 0x001f5b70 FUN_001f5b70 (171 B): equivalent/0x001f5b70.cpp [wrapped: conflict: Object]
// sym: ?update@Object@fn_001f5b70@@QAEXXZ
namespace fn_001f5b70 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_001f5b70 @ 0x001f5b70
struct Source_1f5b70 {
 unsigned __int64 FUN_001f57e0();
 bool FUN_001f3550();
};
struct Timer { void FUN_001e9b20(int); };
struct Object {
 char pad0[0x8c];
 Source_1f5b70* source;
 int state;
 unsigned char active;
 char pad95[3];
 unsigned __int64 value;
 char pada0[0x338-0xa0];
 Timer* timer;
 void update();
};
void Object::update() {
 if (state == -1 || !source) return;
 unsigned __int64 current = source->FUN_001f57e0();
 unsigned __int64 old = value;
 if (!old && current) { value = current; return; }
 if (old && (!current || (source && source->FUN_001f3550()))) {
  if (active) { timer->FUN_001e9b20(500); active = 0; }
  value = 0;
  state = -1;
 }
}
} // namespace fn_001f5b70


// 0x001f5c20 FUN_001f5c20 (1571 B): equivalent/0x001f5c20.cpp [wrapped: conflict: FUN_00249b40]
// sym: ?FUN_001f5c20@Mgr_1f5c20@fn_001f5c20@@QAEXH@Z
namespace fn_001f5c20 {
// STATUS: equivalent (tools/equiv.py level 3: 18776 inputs, branch coverage 99/102, incomplete)
// FUN_001f5c20 @ 0x001f5c20
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
extern "C" double sqrt(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __cdecl qsort(void *base, unsigned int count, unsigned int size,
                              int (__cdecl *cmp)(const void *, const void *));
#endif


struct __declspec(align(8)) Pair_1f5c20 {
    int a, b;
};

struct HandleKey {
    unsigned int lo, hi;
};

struct Slot20_1f5c20 {
    char pad0[0x20];
    union {
        float f20;
        int bits20;
    };
};

struct Info30 {
    char pad0[0x30];
    Slot20_1f5c20 *slot;
};

struct VoiceRef {
    char pad0[4];
    void *res;
};

struct Resource_1f5c20 {
    char pad0[4];
    VoiceRef *ref;
    void FUN_001f34f0();
};

struct Binding_1f5c20 {
    char pad0[0x18];
    int f18;
    HandleKey *FUN_001e8b00();
};

union Target_1f5c20 {
    float f;
    int bits;
};

union Key_1f5c20 {
    __int64 q;
    unsigned int w[2];
};

struct Row_1f5c20 {
    Key_1f5c20 key;
    int hash;
    char flag;
    char pad0d[3];
    Target_1f5c20 f90;
    float f94;
    float f98;
    float f9c;
    float fa0;
    char pad24[4];
};

struct Voice_1f5c20 {
    char pad0[0x10];
    Binding_1f5c20 *bind[4];
    Resource_1f5c20 *res[4];
    char pad30[0x54 - 0x30];
    float vx, vy, vz;
    char pad60[0x6c - 0x60];
    float f6c;
    char pad70[4];
    int type;
    char pad78[8];
    Row_1f5c20 rows[4];
};


int __cdecl FUN_001f2e80(const void *a, const void *b);
Resource_1f5c20 *FUN_0024a370(void *voice, int *hash);
void FUN_0024ac40(void *voice, void *r2, int a, int b, int c);
char FUN_00249b40(void *voice);
Info30 *FUN_002495f0(void *r2);
void FUN_00249bd0(void *voice, void *r2, Pair_1f5c20 *p);
int FUN_002673a0(int a, int b);

class Mgr_1f5c20 {
public:
    char pad0[8];
    void *handles[(0x88 - 8) / 4];
    int count88;
    char pad8c[0xd4 - 0x8c];
    Voice_1f5c20 *voices[(0x324 - 0xd4) / 4];
    int count324;
    Resource_1f5c20 *FUN_001f3ec0(Binding_1f5c20 *b, Voice_1f5c20 *v, Voice_1f5c20 *v2, int a, int c);
    void FUN_001f5b70();
    void FUN_001f5c20(int arg);
};

struct Handle_1f5c20 {
    void FUN_001f5860(int arg);
};

// Spare stack words of the original's frame that matter to the callees (the two scratch pairs) or are
// read back after the call.
struct Frame_1f5c20 {
    union {
        float len;
        Resource_1f5c20 *saved;
    } w;
    Pair_1f5c20 pairA;
    Pair_1f5c20 pairB;
};

void Mgr_1f5c20::FUN_001f5c20(int arg)
{
    Frame_1f5c20 f;
    int started = 0;
    DAT_004e3768[1] = 0;
    DAT_004e3798[1] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[1] = 0;
    DAT_004e3768[2] = 0;
    DAT_004e3798[2] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[2] = 0;
    DAT_004e3768[3] = 0;
    DAT_004e3798[3] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[3] = 0;
    DAT_004e3768[4] = 0;
    DAT_004e3798[4] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[4] = 0;
    DAT_004e3768[5] = 0;
    DAT_004e3798[5] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[5] = 0;
    DAT_004e3768[6] = 0;
    DAT_004e3798[6] = 0;
    ((int*)((char*)&DAT_004e3768 + 24))[6] = 0;
    qsort(voices, count324, 4, FUN_001f2e80);

    for (int k = 0; k < count324; k++) {
        Voice_1f5c20 **p = &voices[k];
        DAT_004e3798[(*p)->type]++;
        for (int i = 0; i < 4; i++) {
            Voice_1f5c20 *v = *p;
            Binding_1f5c20 *b = v->bind[i];
            if (!b)
                continue;
            if (!b->f18)
                continue;
            Resource_1f5c20 *cur = v->res[i];
            if (!cur) {
                if (!(DAT_004e3768[(*p)->type] < ((int*)&DAT_004c7df8)[(*p)->type]))
                    continue;
                if (!((float)DAT_004c7e10[(*p)->type] > (*p)->f6c))
                    continue;
                if (!(started < 0x18))
                    continue;
                Resource_1f5c20 *r = FUN_001f3ec0(b, *p, *p, 1, 0);
                if (r)
                    (*p)->res[i] = r;
                DAT_004e3768[(*p)->type]++;
                started++;
                continue;
            }
            if (DAT_004e3768[(*p)->type] < ((int*)&DAT_004c7df8)[(*p)->type] &&
                !((float)DAT_004c7e10[(*p)->type] <= (*p)->f6c) && started < 0x18) {
                DAT_004e3768[(*p)->type]++;
                Resource_1f5c20 *r = (*p)->res[i];
                started++;
                if (!r)
                    continue;
                r = (*p)->res[i];
                if (!r->ref)
                    continue;
                if (FUN_00249b40(r->ref))
                    continue;
                ((int*)((char*)&DAT_004e3768 + 24))[(*p)->type]++;
                continue;
            }
            if (cur->ref && !FUN_00249b40(cur->ref)) {
                DAT_004e3768[(*p)->type]++;
                started++;
                continue;
            }
            (*p)->res[i]->FUN_001f34f0();
            (*p)->res[i] = 0;
        }

        for (int m = 0; m < 4; m++) {
            Key_1f5c20 empty;
            empty.q = FUN_002672f0(0, 0, 0);
            if ((*p)->rows[m].key.w[0] == empty.w[0] && (*p)->rows[m].key.w[1] == empty.w[1])
                continue;
            for (int n = 0; n < 4; n++) {
                Voice_1f5c20 *v = *p;
                if (v->res[n] == 0)
                    continue;
                HandleKey *hk = v->bind[n]->FUN_001e8b00();
                if (hk->lo != v->rows[m].key.w[0])
                    continue;
                if (hk->hi != v->rows[m].key.w[1])
                    continue;
                Resource_1f5c20 *res = (*p)->res[n];
                int *hashp = &(*p)->rows[m].hash;
                if (res->ref) {
                    Resource_1f5c20 *r2 = FUN_0024a370(res->ref, hashp);
                    if (r2)
                        FUN_0024ac40(res->ref, r2, 1, 0, 0);
                }
                v = *p;
                double dlen = sqrt(v->vx * v->vx + v->vy * v->vy + v->vz * v->vz);
                f.w.len = (float)dlen;
                Row_1f5c20 *row = &v->rows[m];
                if (row->flag == 0) {
                    float t = 1.0f;
                    if (row->fa0 > 0.01f)
                        t = (row->f9c - row->f98) * (f.w.len / row->fa0) + row->f98;
                    if (t > row->f9c)
                        t = row->f9c;
                    Resource_1f5c20 *rr = v->res[n];
                    if (!rr->ref)
                        continue;
                    Resource_1f5c20 *r2 = FUN_0024a370(rr->ref, &row->hash);
                    if (!r2)
                        continue;
                    FUN_002495f0(r2)->slot->f20 = t;
                    continue;
                }
                Resource_1f5c20 *rr = v->res[n];
                if (!rr->ref)
                    continue;
                int *hashSaved = &row->hash;
                Resource_1f5c20 *r2 = FUN_0024a370(rr->ref, hashSaved);
                if (!r2)
                    continue;
                Info30 *q = FUN_002495f0(r2);
                if (!q)
                    continue;
                Slot20_1f5c20 *sl = q->slot;
                if (!sl)
                    continue;
                float cur20 = sl->f20;
                if (cur20 == -1.0f)
                    continue;
                float sum = 0.0f;
                bool viaSum = false;
                if (row->f94 == 0.0f) {
                } else {
                    sum = cur20 + row->f94;
                    viaSum = true;
                    bool to4b2;
                    if (sum < 0.01f)
                        to4b2 = true;
                    else if (!(row->f94 > 0.0f))
                        to4b2 = false;
                    else
                        to4b2 = sum > row->f90.f;
                    if (!to4b2) {
                        Resource_1f5c20 *rr2 = (*p)->res[n];
                        if (!rr2->ref)
                            continue;
                        Resource_1f5c20 *r3 = FUN_0024a370(rr2->ref, hashSaved);
                        if (!r3)
                            continue;
                        FUN_002495f0(r3)->slot->f20 = sum;
                        continue;
                    }
                }
                if (!viaSum) {
                    int copy90 = row->f90.bits;
                    Resource_1f5c20 *rr2 = (*p)->res[n];
                    if (rr2->ref) {
                        Resource_1f5c20 *r3 = FUN_0024a370(rr2->ref, hashSaved);
                        if (r3)
                            FUN_002495f0(r3)->slot->bits20 = copy90;
                    }
                }
                if (!(row->f90.f < 0.01f))
                    continue;
                Resource_1f5c20 *rr3 = (*p)->res[n];
                f.w.saved = rr3;
                Resource_1f5c20 *r4 = FUN_0024a370(rr3->ref, hashSaved);
                if (r4) {
                    if (!viaSum) {
                        f.pairA.a = 0;
                        f.pairA.b = 200;
                        FUN_00249bd0(f.w.saved->ref, r4, &f.pairA);
                    } else {
                        f.pairB.a = 0;
                        f.pairB.b = 200;
                        FUN_00249bd0(f.w.saved->ref, r4, &f.pairB);
                    }
                }
                v->rows[m].key.q = FUN_002672f0(0, 0, 0);
                *hashSaved = FUN_002673a0(0, 0);
            }
        }
    }
    FUN_001f5b70();
    int j = 0;
    if (count88 > 0) {
        void **hp = &handles[0];
        do {
            ((Handle_1f5c20 *)*hp)->FUN_001f5860(arg);
            j++;
            hp++;
        } while (j < count88);
    }
}
} // namespace fn_001f5c20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001f6250 FUN_001f6250 (322 B): matches/0x001f6250.cpp [wrapped: conflict: FUN_00249b40; FUN_0024a370]
// sym: ?FUN_001f6250@Manager_1f6250@fn_001f6250@@QAEDPAUItem_1f6250@2@@Z
namespace fn_001f6250 {
// FUN_001f6250 @ 0x001f6250
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

struct Source_1f6250 { char pad0[4]; void *handle; };

struct Slot_1f6250 {
    unsigned __int64 stamp;
    int hash;
    char pad0c[0x28 - 0xc];
};

struct Params {
    int a;
    int b;
};

struct Item_1f6250 {
    char pad0[0x10];
    int active[4];
    Source_1f6250 *sources[4];
    char pad30[0x80 - 0x30];
    Slot_1f6250 slots[4];
};

struct Current_1f6250 {
    char pad0[0x10];
    Item_1f6250 *item;
    unsigned __int64 FUN_001f57e0();
};

int __cdecl FUN_002673a0(int a, int b);
int __cdecl FUN_0024a370(void *handle, int *hash);
void __cdecl FUN_00249bd0(void *handle, int x, Params *p);
char __cdecl FUN_00249b40(void *handle);

class Manager_1f6250 {
public:
    char FUN_001f6250(Item_1f6250 *item);
    void FUN_001f47b0(Item_1f6250 *item);

    char pad0[0x8c];
    Current_1f6250 *current;
};

char Manager_1f6250::FUN_001f6250(Item_1f6250 *item)
{
    if (item == 0)
        return 0;

    if (current->item == item) {
        if (current->FUN_001f57e0() != 0)
            return 1;
        FUN_001f47b0(item);
    }

    for (int k = 0; k < 4; k++) {
        Slot_1f6250 *slot = &item->slots[k];
        if (slot->stamp != FUN_002672f0(0, 0, 0)) {
            for (int j = 0; j < 4; j++) {
                if (item->active[j] != 0) {
                    Source_1f6250 *src = item->sources[j];
                    if (src != 0) {
                        int x = FUN_0024a370(src->handle, &slot->hash);
                        if (x != 0) {
                            Params p;
                            p.a = 0;
                            p.b = 200;
                            FUN_00249bd0(src->handle, x, &p);
                        }
                    }
                }
            }
            slot->stamp = FUN_002672f0(0, 0, 0);
            slot->hash = FUN_002673a0(0, 0);
        }
    }

    if (item->sources[0] != 0 && item->sources[0]->handle != 0 && !FUN_00249b40(item->sources[0]->handle))
        return 1;
    if (item->sources[1] != 0 && item->sources[1]->handle != 0 && !FUN_00249b40(item->sources[1]->handle))
        return 1;
    return 0;
}
} // namespace fn_001f6250
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001f63a0 FUN_001f63a0 (275 B): equivalent/0x001f63a0.cpp [wrapped: conflict: FUN_00249b40]
// sym: ?update@Manager_1f63a0@fn_001f63a0@@QAEXXZ
namespace fn_001f63a0 {
// STATUS: equivalent (tools/equiv.py level 3: 1919 inputs, branch coverage 34/34)
// FUN_001f63a0 @ 0x001f63a0
struct Resource_1f63a0 { char pad[4]; void* handle; };
struct Entry_1f63a0 { unsigned int a,b; char pad08[0x18]; Resource_1f63a0* first; Resource_1f63a0* second; char pad28[0x48]; unsigned char active; char pad71[7]; int age; };
void __cdecl FUN_00249b40(void*);
struct Manager_1f63a0 { char pad[0xd4]; Entry_1f63a0* entries[148]; int count; Entry_1f63a0* selected; char pad32c[4]; int suspended; bool FUN_001f6250(Entry_1f63a0*); void FUN_001f4420(Entry_1f63a0*); void update(); };
void Manager_1f63a0::update() {
 if (suspended > 0) return;
 for (int i=0;i<count;++i) {
  if (entries[i] == selected) continue;
  if (entries[i]->active == 1) entries[i]->age=0;
  if (entries[i]->active == 0) {
   ++entries[i]->age;
   if (entries[i]->age > 5) {
    Resource_1f63a0* r=entries[i]->first;
    if(r && r->handle) FUN_00249b40(r->handle);
    r=entries[i]->second;
    if(r && r->handle) FUN_00249b40(r->handle);
    if(!FUN_001f6250(entries[i])) FUN_001f4420(entries[i]);
   }
  }
  entries[i]->active=0;
 }
 int i=0;
 while(i<count) {
  if ((entries[i]->a | entries[i]->b)==0) {
   for(int j=i;j<count-1;++j) {
    Entry_1f63a0* t=entries[j]; entries[j]=entries[j+1]; entries[j+1]=t;
   }
   --count;
  } else ++i;
 }
}
} // namespace fn_001f63a0


// 0x001f67c0 FUN_001f67c0 (148 B): matches/0x001f67c0.cpp
// sym: ?FUN_001f67c0@Obj_1f67c0@owners@@QAEXXZ
void owners::Obj_1f67c0::FUN_001f67c0() {
    if (!mB)
        return;
    if (FUN_00247930(mA, mB) == 1) {
        while (FUN_00247930(mA, mB) != 2) {
            thunk_FUN_00270a50();
            FUN_002656a0();
            FUN_00240bb0();
            Step(0.001f);
        }
    }
    if (FUN_00247930(mA, mB) == 2) {
        FUN_00247a90(mA, mB, 0);
        return;
    }
    mFlag = 1;
}

namespace fn_f7fca51a {

// 0x001f6860 FUN_001f6860 (83 B): equivalent/0x001f6860.cpp
// sym: ?FUN_001f6860@Registry_1f6860@fn_f7fca51a@@QAEXPBDPAVCSoundVoiceManager_1f6860@2@P832@AEX_N22@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001f6860 @ 0x001f6860
// FUN_001f6860 @ 0x001f6860  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1f6860::FUN_001f6860(const char* a1, CSoundVoiceManager_1f6860* a2, Fn_1f6860 a3) {
    typedef Closure3_1f6860<CSoundVoiceManager_1f6860, void, bool, bool, bool> Alloc_1f6860;
    HULK_SIZE32(Alloc_1f6860, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1f6860));
    void* x = 0;
    if (m) {
        ((Raw_1f6860*)m)->FUN_001f4980(a1, a3);
        x = new (m) Closure3_1f6860<CSoundVoiceManager_1f6860, void, bool, bool, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f7fca51a

// 0x001f68c0 FUN_001f68c0 (109 B): equivalent/0x001f68c0.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_001f68c0@Registry_1f68c0@fn_001f68c0@@QAEXPBDPAVCSoundVoiceManager@2@P832@AEXXZ@Z
namespace fn_001f68c0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001f68c0 @ 0x001f68c0
// FUN_001f68c0 @ 0x001f68c0  (generated by work/closure/gen.py)
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


class CSoundVoiceManager { public: float FUN_dummy(); };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) MethodBase_1f68c0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1f68c0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1f68c0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1f68c0(name, 0) {
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

struct Registry_1f68c0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001f68c0(const char* name, CSoundVoiceManager* owner, void (CSoundVoiceManager::*fn)());
};

void Registry_1f68c0::FUN_001f68c0(const char* name, CSoundVoiceManager* owner, void (CSoundVoiceManager::*fn)()) {
    typedef Closure0<CSoundVoiceManager, void> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CSoundVoiceManager, void>));
    Closure0<CSoundVoiceManager, void>* c = 0;
    if (mem)
        c = new (mem) Closure0<CSoundVoiceManager, void>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001f68c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f7fca51a {

// 0x001f6930 FUN_001f6930 (83 B): equivalent/0x001f6930.cpp
// sym: ?FUN_001f6930@Registry_1f6930@fn_f7fca51a@@QAEXPBDPAVCSoundVoiceManager_1f6930@2@P832@AEXPAD22H@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_001f6930 @ 0x001f6930
// FUN_001f6930 @ 0x001f6930  (generated by tools/equiv_gen/reg_helper.py)
void Registry_1f6930::FUN_001f6930(const char* a1, CSoundVoiceManager_1f6930* a2, Fn_1f6930 a3) {
    typedef Closure4_1f6930<CSoundVoiceManager_1f6930, void, char*, char*, char*, int> Alloc_1f6930;
    HULK_SIZE32(Alloc_1f6930, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_1f6930));
    void* x = 0;
    if (m) {
        ((Raw_1f6930*)m)->FUN_001f4aa0(a1, a3);
        x = new (m) Closure4_1f6930<CSoundVoiceManager_1f6930, void, char*, char*, char*, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f7fca51a

// 0x001f6990 FUN_001f6990 (526 B): equivalent/0x001f6990.cpp [wrapped: conflict: CSoundSequenceVoice; CSoundVoiceManager; Closure0; Closure3 (+5)]
// sym: ?FUN_001f6990@CSoundVoiceManager@fn_001f6990@@QAEXXZ
namespace fn_001f6990 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_001f6990 @ 0x001f6990
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



extern "C" void *FUN_0008d690(unsigned int size);
extern "C" void *FUN_0008d710(unsigned int size, int tag);

template <class T> struct TypeName;
template <> struct TypeName<void> { static const char *get() { return ((const char*)&DAT_0048e100); } };
template <> struct TypeName<bool> { static const char *get() { return ((const char*)&DAT_0048e0e4); } };
template <> struct TypeName<char *> { static const char *get() { return ((const char*)&DAT_0049cad8); } };
template <> struct TypeName<int> { static const char *get() { return ((const char*)&DAT_0048e134); } };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) Function : public ScriptFunctionFields {
public:
    virtual void f0();
    virtual void f1();
    void FUN_001d0480(const char *name, int arity);
    Function(const char *name, int arity) { FUN_001d0480(name, arity); }
};

class CSoundVoiceManager;

template <class T, class R>
class Method0 : public Function {
public:
    typedef R (T::*Fn)();
    Method0(const char *name, Fn f) : Function(name, 0) {
        fn = f;
        retType = FUN_001d04d0(TypeName<R>::get());
    }
    Fn fn;
};

template <class T, class R, class A, class B, class C>
class Method3 : public Function {
public:
    typedef R (T::*Fn)(A, B, C);
    Method3(const char *name, Fn f) : Function(name, 3) {
        fn = f;
        retType = FUN_001d04d0(TypeName<R>::get());
        argTypes[0] = FUN_001d04d0(TypeName<A>::get());
        argTypes[1] = FUN_001d04d0(TypeName<B>::get());
        argTypes[2] = FUN_001d04d0(TypeName<C>::get());
    }
    Fn fn;
};

template <class T, class R, class A, class B, class C, class D>
class Method4 : public Function {
public:
    typedef R (T::*Fn)(A, B, C, D);
    Method4(const char *name, Fn f) : Function(name, 4) {
        fn = f;
        retType = FUN_001d04d0(TypeName<R>::get());
        argTypes[0] = FUN_001d04d0(TypeName<A>::get());
        argTypes[1] = FUN_001d04d0(TypeName<B>::get());
        argTypes[2] = FUN_001d04d0(TypeName<C>::get());
        argTypes[3] = FUN_001d04d0(TypeName<D>::get());
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
public:
    Closure0(const char *name, T *o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T *owner;
};

template <class T, class R, class A, class B, class C>
class Closure3 : public Method3<T, R, A, B, C> {
public:
    Closure3(const char *name, T *o, typename Method3<T, R, A, B, C>::Fn f) : Method3<T, R, A, B, C>(name, f), owner(o) {}
    T *owner;
};

template <class T, class R, class A, class B, class C, class D>
class Closure4 : public Method4<T, R, A, B, C, D> {
public:
    Closure4(const char *name, T *o, typename Method4<T, R, A, B, C, D>::Fn f) : Method4<T, R, A, B, C, D>(name, f), owner(o) {}
    T *owner;
};

struct Registry_1f6990 {
    void FUN_001d3b70(const char *name, void *closure);
    void FUN_001d3600(const char *path, int flag);
};
extern "C" Registry_1f6990 *FUN_001d4c90();

struct Buffer_1f6990 {
    char pad00[0x70];
    char flag;
    char pad71[0x128 - 0x71];
    Buffer_1f6990 *FUN_001f3780();
    void FUN_0027b040(const char *s);
};

class CSoundSequenceVoice {
public:
    CSoundSequenceVoice(CSoundVoiceManager *o) : owner(o), f04(0), f08(0), f10(0), f18(0), f1c(0), f1d(0), f20(0), f24(0), gain(1.0f) {}
    virtual void v0();
    int f04;
    int f08;
    CSoundVoiceManager *owner;
    int f10;
    int pad14;
    int f18;
    char f1c;
    char f1d;
    char pad1e[2];
    int f20;
    int f24;
    float gain;
};

class CSoundVoiceManager {
public:
    char pad00[8];
    CSoundSequenceVoice *voices[0x20];
    char pad88[0xd4 - 0x88];
    Buffer_1f6990 *buffers[0x94];

    void FUN_001f4610(bool a, bool b, bool c);
    void FUN_001f46a0();
    void FUN_001f30e0(char *a, char *b, char *c, int d);
    void FUN_001f6990();
};

void CSoundVoiceManager::FUN_001f6990()
{
    for (int i = 0; i < 0x94; i++) {
        void *mem = FUN_0008d710(0x128, 6);
        Buffer_1f6990 *b = 0;
        if (mem)
            b = ((Buffer_1f6990 *)mem)->FUN_001f3780();
        buffers[i] = b;
        b->FUN_0027b040(0);
        buffers[i]->flag = 0;
    }
    for (int i = 0; i < 0x20; i++) {
        void *mem = FUN_0008d710(0x30, 6);
        CSoundSequenceVoice *v = 0;
        if (mem)
            v = new (mem) CSoundSequenceVoice(this);
        voices[i] = v;
        v->f10 = 0;
    }

    Registry_1f6990 *reg = FUN_001d4c90();
    { typedef Closure3<CSoundVoiceManager, void, bool, bool, bool> Sized; HULK_SIZE32(Sized, 0x24); }
    void *mem = FUN_0008d690((int)sizeof(Closure3<CSoundVoiceManager, void, bool, bool, bool>));
    Closure3<CSoundVoiceManager, void, bool, bool, bool> *pause = 0;
    if (mem)
        pause = new (mem) Closure3<CSoundVoiceManager, void, bool, bool, bool>("snd_Pause", this, &CSoundVoiceManager::FUN_001f4610);
    reg->FUN_001d3b70("snd_Pause", pause);

    { typedef Closure0<CSoundVoiceManager, void> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure0<CSoundVoiceManager, void>));
    Closure0<CSoundVoiceManager, void> *unpause = 0;
    if (mem)
        unpause = new (mem) Closure0<CSoundVoiceManager, void>("snd_UnPause", this, &CSoundVoiceManager::FUN_001f46a0);
    reg->FUN_001d3b70("snd_UnPause", unpause);

    { typedef Closure4<CSoundVoiceManager, void, char *, char *, char *, int> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure4<CSoundVoiceManager, void, char *, char *, char *, int>));
    Closure4<CSoundVoiceManager, void, char *, char *, char *, int> *mapInst = 0;
    if (mem)
        mapInst = new (mem) Closure4<CSoundVoiceManager, void, char *, char *, char *, int>("snd_MapInstance", this, &CSoundVoiceManager::FUN_001f30e0);
    reg->FUN_001d3b70("snd_MapInstance", mapInst);

    FUN_001d4c90()->FUN_001d3600("sound\\map.lua", 0);
}
} // namespace fn_001f6990
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f7fca51a {

// 0x001f6ba0 FUN_001f6ba0 (28 B): matches/0x001f6ba0.cpp
// sym: ?run@fn_f7fca51a@@YI_NPAVOwner_1f6ba0@1@@Z
bool __fastcall run(Owner_1f6ba0* self) {
    Obj_1f6ba0* p = self->member;
    if (p && p->field) {
        ((owners::Obj_1f67c0 *)p)->FUN_001f67c0();
        return true;
    }
    return false;
}

} // namespace fn_f7fca51a
