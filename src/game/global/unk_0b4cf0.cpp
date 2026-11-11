// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b4cf0..0x000bba40 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fedc4c02 {
#define TREE_TU_END }
namespace fn_fedc4c02 {} using namespace fn_fedc4c02;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fedc4c02 {
struct Entry {
    unsigned __int64 first, second;
    char rest[0x18];
};
struct Owner {
    char padding[0x470];
    Entry entries[128];
    int FUN_000b4d70(unsigned __int64 value);
};
typedef unsigned __int64 U64_b4e30;
struct Key_b4e30 { unsigned lo, hi;  };
struct Entry_b4e30 { Key_b4e30 first, second, third, fourth; unsigned a,b; };
struct Object {
  public:
    char _m_pad_0[0x470];
    Entry_b4e30 entries[128];
    char _m_pad_1870[0x359];
    void target(const char*,const char*,const char*,const char*,unsigned,unsigned);
};
int FUN_000fc310();
extern "C" int FUN_000fc320();
struct Slot_b5030 {  };
struct Holder_b5030 { Slot_b5030 *FUN_00086270(); };
} // namespace fn_fedc4c02
struct World {
    char pad00[0x54];
    Holder_b5030 *holder;
};
namespace fn_fedc4c02 {
struct Target_b5030 { void FUN_0008ffe0(); };
struct Panel_b5030 {
    void FUN_00089830(const char *name);
    bool FUN_000893c0();
    void FUN_00089810(const char *name);
    void FUN_00089300(const char *name);
};
class Screen_b5030 {
public:
    char pad00[0x34];
    Panel_b5030 *panel;
    char pad38[0x50 - 0x38];
    Target_b5030 *target;
    void FUN_000b5030(int a);
};
struct Event {
    char data[32];
    Event(const char*);
};
struct Receiver {
    void Send(Event*);
};
struct Global {
    char pad[0x30];
    Receiver* rec;
};
extern Global* g;
class Sub {
  public:
    void Set(const char*, int, int);
};
class Obj {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void f3();
    char _m_pad_4[0x14];
    Sub sub;
    char _m_pad_19[0x1bb3];
    void Set(const char*);
};
extern "C" Obj* __cdecl Lookup(const char*);
extern "C" void* __cdecl Find(const char*);
class Result {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char data[20];
    int member;
};
extern "C" void* __cdecl FUN_000fc260(const char*);
class Record {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char pad[0x14];
    char data[4];
};
struct Rec {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void done();
    char pad[20];
    char data[4];
};
extern Rec* findrec(const char*);
struct Control_b5920 {
    char pad00[5];
    char busy;
    char pad06[2];
    void FUN_000afe10(int enable);
    void FUN_000aff30(int a, float x, float y, float z, const char *name);
};
struct Entry_b5920 {
    char pad[0x134];
    char name[1];
};
struct Registry_b5920 {
};
struct Panel_b5920 {
    char pad00[0x44];
    Control_b5920 *control;
    char pad48[0x58 - 0x48];
    Registry_b5920 *registry;
    void FUN_000b5920(int enable);
};
class Widget {
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
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void set(int);
};
extern "C" void* __cdecl lookup(const char*);
extern "C" Widget* __cdecl convert(void*, int, void*, void*, int);
extern int r1, r2;
extern "C" int __cdecl makeName(const char*);
extern "C" class Selector* __cdecl findSelector(int, int, void*, void*, int);
extern int gA, gB;
class Selector {
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
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void set(int);
};
struct State {
    char pad[5];
    char flag;
};
class Screen {
    char pad[0x44];
    State* state;

  public:
    void setup();
};
extern "C" char DAT_0049dba4[];
extern "C" char DAT_0049dbbc[];
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
class Selector_b5ad0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(int selected);
};
class Mgr_b7760 {
  public:
};
class Obj_b7760 {
    char pad[0x4c];

  public:
    Mgr_b7760* mgr;
    void Run();
};
struct Button_b7760 {
    char pad[0x141];
    char flag;
};
extern "C" Button_b7760* __cdecl Convert(void*, int, void*, void*, int);
extern int type1_b7760, type2;
} // namespace fn_fedc4c02
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
#endif
namespace fn_fedc4c02 {
class Settings_b77c0 {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual int GetLanguage();
};
struct Lookup_b77c0 {
    char data[0x24];
    void FUN_000f8500(int key, int language, int flag);
    const unsigned short *FUN_000f83f0(int language, int flag);
};
Settings_b77c0 *__cdecl FUN_000fc3d0();
extern "C" int __cdecl FUN_00294b80(const unsigned short *s);
} // namespace fn_fedc4c02
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_fedc4c02 {
struct Obj_b8c50;
struct Entry_b8c50 {
    char pad[0x14];
    int field14;
};
Obj_b8c50* __cdecl GetManager();
Entry_b8c50* __cdecl FindEntry(int key);
struct Obj_b8c50 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Obj_b8c50* v3(int arg);
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(int arg);
};
struct Obj_b8c90 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual const char* Name();
};
Obj_b8c90* GetObj();
extern "C" void __cdecl CallA(int);
extern "C" int __cdecl CallB();
extern "C" int __cdecl CallC();
class Renderer_b90c0 {
  public:
    void FUN_001b98e0(float a, float b, float c, float d, float e, float f);
    void FUN_001b8780(int flag);
};
class Menu_b90c0 {
  public:
    char pad0[0x54];
    Renderer_b90c0* renderer;
    char pad1[0x1d00 - 0x58];
    unsigned char savedFlag;
    char pad2[3];
    int saved0[3];
    int saved1[3];
    float saved2[6];
    void FUN_000b90c0(bool save);
};
} // namespace fn_fedc4c02
class Gfx {
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
    virtual void v12(int a);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int mode);
    virtual int v25();
};
namespace fn_fedc4c02 {
class Layer_b9230 {
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
    virtual void v13(int a);
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};
class Viewport_b9230 {
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
    virtual float v16();
};
class Widget_b9230 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a, int b);
};
struct Canvas {
    Layer_b9230* layer;
    void FUN_00293d40(float x, float y, float z);
    void FUN_00293da0(float x, float y, float z);
};
struct Inner_b9620 {
    void A();
    void B(int);
    bool C();
};
struct Obj_b9620 {
    char pad[0x54];
    Inner_b9620* p;
    void Target();
};
extern "C" void FUN_000fc2f0();
struct State_b9770 {
    char pad[0x9a8];
    char flag;
};
struct Glob_b9770 {
    char pad[0x2218];
    State_b9770* state;
    int mode;
};
extern Glob_b9770* GetGlobal();
struct A_b9770 {
    void F();
    void G(int);
};
struct B_b9770 {
    void F(int);
};
class Obj_b9770 {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x20];
    A_b9770* a;
    B_b9770* b;
    void Run();
};
class Sub_bb5c0 {
  public:
    void Init();
    void Fn(int a, int b);
};
class Obj_bb5c0 {
  public:
    char pad[0x34];
    Sub_bb5c0* flag;
    char pad2[0x14];
    Sub_bb5c0* sub;
    void Finish();
};
struct Provider_bb820 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual int get(); };
struct Text_bb820 { void FUN_000f8500(const char*, int, int); char storage[0x58]; };
struct Item_bb820 { char pad[0x18]; Text_bb820 text; int state; };
struct Owner_bb820 { char pad0[4]; Provider_bb820* provider; char pad1[0x984]; Item_bb820* mainItem; Item_bb820* secondItem; Item_bb820* thirdItem; void target(const char*, const char*, const char*); };

} // namespace fn_fedc4c02

// 0x000b4cf0 FUN_000b4cf0 (115 B): equivalent/0x000b4cf0.cpp
// sym: ?FUN_000b4cf0@NameTable_b4cf0@owners@@QAEIPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 14/14)
// FUN_000b4cf0 @ 0x000b4cf0
hulk_uintptr owners::NameTable_b4cf0::FUN_000b4cf0(const char *name)
{
    for (int i = 0; i < 128; i++) {
        const char *s = names[i];
        if (s == 0)
            return 0;
        const char *p = name;
        while (*p == *s) {
            if (*p == 0)
                break;
            p++;
            s++;
        }
        if (*p == *s)
            return values[i];
    }
    return 0;
}

namespace fn_fedc4c02 {

// 0x000b4d70 FUN_000b4d70 (74 B): matches/0x000b4d70.cpp
// sym: ?FUN_000b4d70@Owner@fn_fedc4c02@@QAEH_K@Z
int Owner::FUN_000b4d70(unsigned __int64 value) {
    for (int i = 0; i < 128; ++i) {
        Entry& entry = entries[i];
        if (entry.first == 0)
            return -1;
        if (entry.first == value)
            return i;
        if (entry.second == value)
            return i;
    }
    return -1;
}


// 0x000b4dc0 FUN_000b4dc0 (102 B): matches/0x000b4dc0.cpp
// sym: _FUN_000b4dc0@4
extern "C" bool __stdcall FUN_000b4dc0(const char* s) {
    const char** p = (const char**)DAT_0049f3d8;
    do {
        const char* q = *p;
        if (q == 0)
            break;
        if (strcmp(s, q) == 0)
            return true;
        ++p;
    } while ((hulk_intptr)p < ((hulk_intptr)DAT_0049f3e4));
    return false;
}


// 0x000b4e30 FUN_000b4e30 (233 B): equivalent/0x000b4e30.cpp
// sym: ?target@Object@fn_fedc4c02@@QAEXPBD000II@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/12, incomplete)
// FUN_000b4e30 @ 0x000b4e30
void Object::target(const char* s1,const char* s2,const char* s3,const char* s4,unsigned a,unsigned b) {
 if (!*s1) return;
 U64_b4e30 key=FUN_0027b020(s1);
 FUN_0027b020(s2); FUN_0027b020(s3); FUN_0027b020(s4);
 for (int i=0;i<128;++i) {
 Entry_b4e30& e=entries[i];
 if (!(e.first.lo|e.first.hi)) {
 ((owners::Target_27b040 *)&(e.first))->FUN_0027b040((hulk_uintptr)s1); ((owners::Target_27b040 *)&(e.second))->FUN_0027b040((hulk_uintptr)s2); ((owners::Target_27b040 *)&(e.third))->FUN_0027b040((hulk_uintptr)s3); ((owners::Target_27b040 *)&(e.fourth))->FUN_0027b040((hulk_uintptr)s4); e.a=a; e.b=b; return;
 }
 if (e.first.lo==(unsigned)key && e.first.hi==(unsigned)(key>>32)) return;
 }
}


// 0x000b4f20 FUN_000b4f20 (25 B): matches/0x000b4f20.cpp
// sym: ?FUN_000b4f20@fn_fedc4c02@@YAHXZ
int FUN_000b4f20() {
    if (FUN_000fc310() == 0) {
        if (FUN_000fc320() == 0)
            return 0;
    }
    return 1;
}


// 0x000b4f40 FUN_000b4f40 (6 B): matches/0x000b4f40.cpp
// sym: _FUN_000b4f40
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_000b4f40() {
    return (int*)&DAT_00406140;
}

// 0x000b4ff0 thunk_FUN_000fc1b0 (5 B): not yet verified

// 0x000b5000 FUN_000b5000 (4 B): matches/0x000b5000.cpp
// sym: ?FUN_000b5000@fn_fedc4c02@@YIIPAX@Z
// Same code shape as 0x00086300 (propagated; names are from that function)
hulk_uintptr __fastcall FUN_000b5000(void* p) {
    return *(unsigned int*)((char*)p + 0x34);
}


// 0x000b5030 FUN_000b5030 (135 B): matches/0x000b5030.cpp
// sym: ?FUN_000b5030@Screen_b5030@fn_fedc4c02@@QAEXH@Z
// FUN_000b5030 @ 0x000b5030
void Screen_b5030::FUN_000b5030(int a)
{
    if (!panel)
        return;
    ((owners::C_895c0 *)panel)->FUN_000895c0(a);
    panel->FUN_00089830("c00m01");
    void *item = ((void *)((owners::NameTable_b4cf0 *)this)->FUN_000b4cf0("c00m01"));
    if (!item)
        return;
    if (!panel->FUN_000893c0())
        target->FUN_0008ffe0();
    ((owners::LevelName_895e0 *)panel)->FUN_000895e0((const char *)item);
    panel->FUN_00089810("c00m01");
    panel->FUN_00089300("story");
    ((owners::Target_86420 *)(DAT_004dd700->holder->FUN_00086270()))->FUN_00086420(1);
}


// 0x000b50c0 FUN_000b50c0 (1 B): matches/0x000b50c0.cpp
// sym: ?FUN_000b50c0@fn_fedc4c02@@YAXXZ
void FUN_000b50c0() {}

} // namespace fn_fedc4c02

// 0x000b50d0 FUN_000b50d0 (167 B): equivalent/0x000b50d0.cpp [wrapped: conflict: FUN_000fc260; World]
// sym: ?FUN_000b50d0@JumpMarkerHud@fn_000b50d0@@QAEXXZ
namespace fn_000b50d0 {
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 10/10)
// FUN_000b50d0 @ 0x000b50d0
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

class FEObject_b50d0 {
public:
    virtual void v0();
};

class TextSelector_b50d0 : public FEObject_b50d0 {
public:
    char pad04[0x154 - 4];
    int selected;             // 0x154
    char pad158[0x1d58 - 0x158];
    void *items;              // 0x1d58
};

struct Marker_b50d0 {
};

struct Table_b50d0 {
    int FUN_00093260(int idx);
};

struct Message_b50d0 {
    char data[0x20];
};

struct Sink_b50d0 {
    void FUN_001cbc20(Message_b50d0 *msg);
};

struct World {
    char pad0[0x30];
    Sink_b50d0 *sink;               // 0x30
};

FEObject_b50d0 *__cdecl FUN_000fc260(const char *name);
extern "C" void __cdecl FUN_000fc300();

class JumpMarkerHud {
public:
    char pad0[0x34];
    Marker_b50d0 *marker;           // 0x34
    char pad38[0x4c - 0x38];
    Table_b50d0 *table;             // 0x4c
    void FUN_000b50d0();
};

void JumpMarkerHud::FUN_000b50d0()
{
    if (marker == 0 || table == 0)
        return;
    TextSelector_b50d0 *sel = dynamic_cast<TextSelector_b50d0 *>(FUN_000fc260("jump_marker_selector"));
    if (sel == 0 || sel->items == 0)
        return;
    int id = ((owners::C_89960 *)marker)->FUN_00089960(sel->selected);
    if (id == -1)
        return;
    int value = table->FUN_00093260(id);
    ((owners::Obj_899d0 *)marker)->FUN_000899d0((const char *)(hulk_uintptr)(int)value);
    ((owners::Obj_89980 *)marker)->FUN_00089980();
    Message_b50d0 msg;
    ((owners::Result_1cae40 *)&msg)->FUN_001cae40((hulk_uintptr)"JumpMarkerSelected");
    DAT_004dd700->sink->FUN_001cbc20(&msg);
    FUN_000fc300();
}
} // namespace fn_000b50d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fedc4c02 {

// 0x000b5180 FUN_000b5180 (46 B): matches/0x000b5180.cpp
// sym: ?target@fn_fedc4c02@@YAXXZ
// data: flag = DAT_004e222c
void target() {
    Event e("JumpMarkerSelectionCancelled");
    g->rec->Send(&e);
    (*(unsigned char*)&DAT_004e222c) = 1;
}


// 0x000b5490 FUN_000b5490 (52 B): matches/0x000b5490.cpp
// sym: _FUN_000b5490@4
extern "C" void __stdcall FUN_000b5490(const char* name) {
    Obj* p = Lookup("side_mission_success_name");
    if (p && &p->sub) {
        p->sub.Set(name, 0, 1);
        p->f3();
    }
}

} // namespace fn_fedc4c02

// 0x000b54d0 FUN_000b54d0 (85 B): matches/0x000b54d0.cpp
// sym: ?FUN_000b54d0@Owner_b54d0@owners@@QAEXHHHHHHH@Z
void owners::Owner_b54d0::FUN_000b54d0(int a, int b, int c, int d, int e, int f, int g) {
    Result* r = (Result*)Find("side_mission_success_result");
    if (r && &r->member) {
        Apply(&r->member, a, b, c, d, e, f, g);
        r->f3();
    }
}


// 0x000b5530 FUN_000b5530 (85 B): matches/0x000b5530.cpp
// sym: ?FUN_000b5530@Owner_b5530@owners@@QAEXHHHHHHH@Z
void owners::Owner_b5530::FUN_000b5530(int a, int b, int c, int d, int e, int f, int g) {
    Record* r = (Record*)FUN_000fc260("side_mission_success_record");
    if (r && &r->data) {
        process(&r->data, a, b, c, d, e, f, g);
        r->f3();
    }
}


// 0x000b5590 FUN_000b5590 (224 B): equivalent/0x000b5590.cpp [wrapped: conflict: FUN_000fc260]
// sym: _FUN_000b5590@4
namespace fn_000b5590 {
// STATUS: equivalent (tools/equiv.py level 3: 19973 inputs, branch coverage 9/9)
// FUN_000b5590 @ 0x000b5590
// FUN_000b5590 @ 0x000b5590: set the colour and text of the side-mission success ranking.
// The extent is 0xb5590..0xb566f: the switch arms at 0xb55e0/5600/5620/5640 are part of this function.

struct Ranking { void FUN_000f8500(const float*, int, int); };
struct Object {
    virtual void FUN_00000000(); virtual void FUN_00000001(); virtual void FUN_00000002(); virtual void FUN_00000003();
    char pad[0x14];
    Ranking ranking;                // 0x18
    char pad2[0x3c - 0x18 - 1];
    int color;                      // 0x3c
};
extern "C++" __declspec(nothrow) Object* __cdecl FUN_000fc260(const char*);

extern "C" void __stdcall FUN_000b5590(hulk_uintptr value)
{
    Object* object = FUN_000fc260("side_mission_success_ranking");
    if (!object)
        return;
    const char* text;
    switch (value) {
    case 0:
        object->ranking.FUN_000f8500(((float*)&DAT_003f335c), 0, 1);
        object->FUN_00000003();
        return;
    case 1:  object->color = 0xffc8821e; text = "TBS_SIDE_MISSION_TEXT_8"; break;
    case 2:  object->color = 0xffb4c5c4; text = "TBS_SIDE_MISSION_TEXT_9"; break;
    case 3:  object->color = 0xffe6e11e; text = "TBS_SIDE_MISSION_TEXT_10"; break;
    default: object->color = 0xffffffff; text = "UNKNOWN"; break;
    }
    object->ranking.FUN_000f8500((const float*)text, 0, 1);
    object->FUN_00000003();
}
} // namespace fn_000b5590


// 0x000b5710 FUN_000b5710 (119 B): equivalent/0x000b5710.cpp [wrapped: conflict: FUN_000fc260]
// sym: ?FUN_000b5710@Menu_b5710@fn_000b5710@@QAEXPBDHHHHHH@Z
namespace fn_000b5710 {
// STATUS: equivalent (tools/equiv.py level 3: 19955 inputs, branch coverage 5/5)
// FUN_000b5710 @ 0x000b5710

struct Head_b5710 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    char pad04[0x14];
};
struct Body_b5710 { char data[0x5c]; };
struct Entry_b5710 : public Head_b5710, public Body_b5710 {
    char done;
};
Entry_b5710* __cdecl FUN_000fc260(const char* name);

struct Menu_b5710 {
    void FUN_000b5250(Body_b5710* body, const char* name, int a2, int a3, int a4, int a5, int a6, int a7);
    void FUN_000b5710(const char* name, int a2, int a3, int a4, int a5, int a6, int a7);
};

void Menu_b5710::FUN_000b5710(const char* name, int a2, int a3, int a4, int a5, int a6, int a7) {
    Entry_b5710* entry = FUN_000fc260("side_mission_success_new_record");
    if (entry == 0)
        return;
    if (name[0] == 0) {
        entry->done = 0;
        return;
    }
    FUN_000b5250(static_cast<Body_b5710*>(entry), name, a2, a3, a4, a5, a6, a7);
    entry->done = 1;
    entry->v3();
}
} // namespace fn_000b5710


// 0x000b5790 FUN_000b5790 (52 B): matches/0x000b5790.cpp [wrapped: conflict: Obj]
// sym: _FUN_000b5790@4
namespace fn_000b5790 {
struct Str {
    char pad[24];
    void Set(const char*, int, int);
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    char pad[20];
    Str str;
};
extern Obj* findObj(const char*);
extern "C" void __stdcall FUN_000b5790(const char* s) {
    Obj* p = findObj("side_mission_fail_name");
    if (p && &p->str) {
        p->str.Set(s, 0, 1);
        p->d();
    }
}
} // namespace fn_000b5790


// 0x000b57d0 FUN_000b57d0 (52 B): matches/0x000b57d0.cpp [wrapped: conflict: FUN_000fc260]
// sym: _FUN_000b57d0@4
namespace fn_000b57d0 {
class Sub {
  public:
    void Show(int, int, int);
};
class Item {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    char pad[20];
    Sub sub;
};
extern Item* FUN_000fc260(const char*);
extern "C" void __stdcall FUN_000b57d0(hulk_intptr x) {
    Item* p = FUN_000fc260("side_mission_fail_hint");
    if (p && &p->sub) {
        p->sub.Show(x, 0, 1);
        p->d();
    }
}
} // namespace fn_000b57d0


// 0x000b5810 FUN_000b5810 (85 B): matches/0x000b5810.cpp
// sym: ?FUN_000b5810@Handler_b5810@owners@@QAEXMMMMMMM@Z
void owners::Handler_b5810::FUN_000b5810(float a, float b, float c, float d, float e, float f, float g) {
    Rec* p = findrec("side_mission_fail_record");
    if (p && &p->data) {
        write(&p->data, a, b, c, d, e, f, g);
        p->done();
    }
}

namespace fn_fedc4c02 {

// 0x000b5920 FUN_000b5920 (109 B): equivalent/0x000b5920.cpp
// sym: ?FUN_000b5920@Panel_b5920@fn_fedc4c02@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000b5920 @ 0x000b5920
void Panel_b5920::FUN_000b5920(int enable)
{
    if (control != 0) {
        char wasBusy = control->busy;
        control->FUN_000afe10(enable);
        if (wasBusy == 0 && (char)enable != 0) {
            const char *name;
            if (((Entry_b5920 *)((owners::C_ae640 *)registry)->FUN_000ae640(0))->name[0] != 0)
                name = ((Entry_b5920 *)((owners::C_ae640 *)registry)->FUN_000ae640(0))->name;
            else
                name = DAT_004de768;
            control->FUN_000aff30(0, 100.0f, 100.0f, 0.4f, name);
        }
    }
}

} // namespace fn_fedc4c02

// 0x000b5a30 FUN_000b5a30 (70 B): matches/0x000b5a30.cpp
// sym: ?FUN_000b5a30@Owner_b5a30@owners@@QAEXXZ
// data: name = DAT_00407b14
void owners::Owner_b5a30::FUN_000b5a30() {
    Widget* w = convert(lookup(((char*)&DAT_00407b14)), 0, &r1, &r2, 0);
    if (w && state)
        w->set(state[5] == 0);
}

namespace fn_fedc4c02 {

// 0x000b5a80 FUN_000b5a80 (70 B): matches/0x000b5a80.cpp
// sym: ?setup@Screen@fn_fedc4c02@@QAEXXZ
void Screen::setup() {
    Selector* s = findSelector(makeName("pause_config_vibration_selector"), 0, &gA, &gB, 0);
    if (s && state)
        s->set(state->flag == 0);
}


// 0x000b5ad0 FUN_000b5ad0 (125 B): matches/0x000b5ad0.cpp
// sym: ?FUN_000b5ad0@fn_fedc4c02@@YAXXZ
// FUN_000b5ad0 @ 0x000b5ad0
// Syncs the two camera-invert selectors with the stored flags.
void FUN_000b5ad0()
{
    Selector_b5ad0* x = (Selector_b5ad0*)FUN_00344e74(FUN_000fc260("camera_invert_x_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (x)
        x->vfunc_25(DAT_004dd83a == 0);
    Selector_b5ad0* y = (Selector_b5ad0*)FUN_00344e74(FUN_000fc260("camera_invert_y_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (y)
        y->vfunc_25(DAT_004dd83b == 0);
}

} // namespace fn_fedc4c02

// 0x000b5b50 FUN_000b5b50 (63 B): matches/0x000b5b50.cpp [wrapped: same definition as 0x000b5180 in this TU]
// sym: ?target@fn_000b5b50@@YAXXZ
namespace fn_000b5b50 {
struct Desc {
    int a;
};
extern Desc objA, objB;
extern "C++" __declspec(nothrow) void* __cdecl find(const char*);
extern "C++" __declspec(nothrow) void* __cdecl castObj(void*, int, Desc*, Desc*, int);
extern "C" char __cdecl FUN_00035da0();
class Selector {
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
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void set(int);
};
inline void use(Selector* s, int b) {
    s->set(b);
}
void target() {
    Selector* s = (Selector*)castObj(find("targeting_selector"), 0, &objA, &objB, 0);
    if (s)
        use(s, FUN_00035da0() == 0);
}
} // namespace fn_000b5b50


// 0x000b5b90 FUN_000b5b90 (83 B): matches/0x000b5b90.cpp [wrapped: conflict: FEObject]
// sym: ?FUN_000b5b90@fn_000b5b90@@YAXXZ
namespace fn_000b5b90 {
extern "C" char DAT_0049dba4[];
extern "C" char DAT_0049dbbc[];
class FEObject {
  public:
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
    virtual void Set(int);
};
extern int __cdecl FindName(const char*);
extern hulk_intptr __cdecl LookupThing(int, int, int*, int*, int);
extern int __cdecl GetFlagThing(int);
struct Result_b5b90 {
    char Check(int);
};
struct Ctx_b5b90 {
    Result_b5b90* Get();
};
struct Global_b5b90 {
    char pad[0x54];
    Ctx_b5b90* ctx;
};
extern Global_b5b90* gGlobal_b5b90;
void FUN_000b5b90() {
    FEObject* p = (FEObject*)LookupThing(FindName("cheat_invulnerability_selector"), 0, (int*)((hulk_intptr)DAT_0049dba4),
                                         (int*)((hulk_intptr)DAT_0049dbbc), 0);
    if (p) {
        int flag = gGlobal_b5b90->ctx->Get()->Check(0x2e4) == 0;
        p->Set(flag);
    }
}
} // namespace fn_000b5b90


// 0x000b5bf0 FUN_000b5bf0 (163 B): matches/0x000b5bf0.cpp [wrapped: conflict: FUN_000fc260; World]
// sym: ?FUN_000b5bf0@fn_000b5bf0@@YAXXZ
namespace fn_000b5bf0 {
// FUN_000b5bf0 @ 0x000b5bf0
// equiv-map: ??_R0?AVFEObject@@@8 = 0x0049dba4
// equiv-map: ??_R0?AVTextSelector@@@8 = 0x0049dbbc
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


class FEObject_b5bf0 {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
    virtual void f25(int v);
};

class TextSelector_b5bf0 : public FEObject_b5bf0 {
public:
    char pad[4];
};

struct Flags_b5bf0 {
    bool FUN_00092de0(int id);
};

struct Reg_b5bf0 {
};

struct World {
    char pad0[0x54];
    Reg_b5bf0 *f54;
};

FEObject_b5bf0 *__cdecl FUN_000fc260(const char *name);

void FUN_000b5bf0()
{
    TextSelector_b5bf0 *sel = dynamic_cast<TextSelector_b5bf0 *>(FUN_000fc260("cheat_gray_hulk_selector"));
    if (sel != 0)
        sel->f25(!((Flags_b5bf0 *)((owners::A_86340 *)(DAT_004dd700->f54))->FUN_00086340())->FUN_00092de0(2));

    sel = dynamic_cast<TextSelector_b5bf0 *>(FUN_000fc260("cheat_invulnerability_selector"));
    if (sel != 0)
        sel->f25(!((Flags_b5bf0 *)((owners::A_86340 *)(DAT_004dd700->f54))->FUN_00086340())->FUN_00092de0(0x2e4));
}
} // namespace fn_000b5bf0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000b5ca0 FUN_000b5ca0 (1780 B): equivalent/0x000b5ca0.cpp [wrapped: macros]
// sym: ?FUN_000b5ca0@Env@fn_000b5ca0@@QAEXXZ
namespace fn_000b5ca0 {
// STATUS: equivalent (tools/equiv.py level 3: 274 inputs, branch coverage 92/98, incomplete)
// FUN_000b5ca0 @ 0x000b5ca0
// equiv-map: ??_R0?AVFEObject@@@8 = 0x0049dba4
// equiv-map: ??_R0?AVTextSelector@@@8 = 0x0049dbbc
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


class FEObject {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22();
};

struct Item {
    char pad0[0x14];
    int value;                       // 0x14
    char pad18[0x24 - 0x18];
};

struct Entry {
    int enabled;                     // 0
    int id;                          // 4
    char pad8[0x14 - 8];
    Item *items;                     // 0x14
    char pad18[0x20 - 0x18];
    int sel;                         // 0x20
    char pad24[0x38 - 0x24];
};

class TextSelector : public FEObject {
public:
    char pad_ts[0x168 - 4];
    Entry entries[127];              // 0x168
    char pad_end[0x1d58 - 0x168 - 127 * 0x38];
    int count;                       // 0x1d58
};

struct Loc2 {
    char pad0[0x14];
    int f14;
    char pad18[0x24 - 0x18];
    void FUN_000f7930();
    void FUN_000f8500(const char *key, int a, int b);
    void FUN_000f7960();
};

struct Menu {
    void FUN_00092870(int i, int v);
};

struct Getter {
    void FUN_00203870(const char *s);
};

struct Reg {
    Getter *FUN_000862a0();
};

struct World {
    char pad0[0x54];
    Reg *f54;
};

FEObject *__cdecl FUN_000fc260(const char *name);

struct Frame {
    int i;                           // S+0x10
    Entry *p;                        // 0x14
    TextSelector *t;                 // 0x18
    Loc2 A;                          // 0x1c
    Loc2 B;                          // 0x40
    Loc2 C;                          // 0x64
};

#define CHEAT(NAME, KEY, K) \
    f.B.FUN_000f8500(NAME, 0, 1); \
    if (cur == f.B.f14) { \
        DAT_004dd700->f54->FUN_000862a0()->FUN_00203870(KEY); \
        f4c->FUN_00092870(K, 1); \
    }

#define OPTION(NAME, IDX) \
    f.A.FUN_000f8500(NAME, 0, 1); \
    if (id == f.A.f14) \
        f4c->FUN_00092870(IDX, cur == on);

class Env {
public:
    char pad0[0x4c];
    Menu *f4c;
    void FUN_000b5ca0();
};

void Env::FUN_000b5ca0()
{
    Frame f;
    f.t = dynamic_cast<TextSelector *>(FUN_000fc260("unlocked_cheats"));
    if (f.t == 0)
        return;
    int n;
    for (n = 0; n <= 12; n++)
        f4c->FUN_00092870(n, 0);
    f4c->FUN_00092870(0xe, 0);
    f4c->FUN_00092870(0xd, 0);
    f.i = 0;
    if (f.t->count <= 0)
        return;
    f.p = &f.t->entries[0];
    do {
        if (f.p->enabled != 0 || f.p->id != -1) {
            int id = f.p->id;
            if (id != -1) {
                int cur = f.p->items[f.p->sel].value;
                f.A.FUN_000f7930();
                f.A.FUN_000f8500("TBS_CHEAT_CHARACTER", 0, 1);
                if (id == f.A.f14) {
                    f.B.FUN_000f7930();
                    f.B.FUN_000f8500("TBS_CHEAT_HULK", 0, 1);
                    if (cur == f.B.f14) {
                        DAT_004dd700->f54->FUN_000862a0()->FUN_00203870("hulk");
                    }
            CHEAT("TBS_CHEAT_GREY_HULK", "grey_hulk", 0x1)
            CHEAT("TBS_CHEAT_JOE_FIXIT", "joefixit", 0x2)
            CHEAT("TBS_CHEAT_ABOMINATION", "abomination_ashulk", 0x3)
            CHEAT("TBS_CHEAT_SAVAGE_BANNER", "banner_savage", 0x4)
            CHEAT("TBS_CHEAT_FLAG_CANADA", "hulk_canada", 0x5)
            CHEAT("TBS_CHEAT_FLAG_AUSTRALIA", "hulk_australia", 0x0)
            CHEAT("TBS_CHEAT_FLAG_AMERICA", "hulk_us", 0x6)
            CHEAT("TBS_CHEAT_FLAG_ENGLAND", "hulk_uk", 0x7)
            CHEAT("TBS_CHEAT_FLAG_FRANCE", "hulk_france", 0x8)
            CHEAT("TBS_CHEAT_FLAG_GERMANY", "hulk_german", 0x9)
            CHEAT("TBS_CHEAT_FLAG_ITALY", "hulk_italy", 0xa)
            CHEAT("TBS_CHEAT_FLAG_SPAIN", "hulk_spain", 0xb)
            CHEAT("TBS_CHEAT_FLAG_JAPAN", "hulk_japan", 0xc)
                    f.B.FUN_000f7960();
                    f.A.FUN_000f7960();
                } else {
                    f.A.FUN_000f8500("TBS_CHEAT_RENDER_MODE", 0, 1);
                    if (id == f.A.f14) {
                        f.C.FUN_000f7930();
                        f.C.FUN_000f8500("TBS_CHEAT_SEPIA", 0, 1);
                        if (cur == f.C.f14)
                            f4c->FUN_00092870(0xe, 1);
                        f.C.FUN_000f8500("TBS_CHEAT_BLACK_AND_WHITE", 0, 1);
                        if (cur == f.C.f14)
                            f4c->FUN_00092870(0xd, 1);
                        f.C.FUN_000f7960();
                    }
                    f.A.FUN_000f8500("TBS_MENU_ITEM_CHOICE_ON", 0, 1);
                    int on = f.A.f14;
            OPTION("TBS_CHEAT_INVULNERABILITY", 0x2e4)
            OPTION("TBS_CHEAT_DOUBLE_DAMAGE", 0x14)
            OPTION("TBS_CHEAT_DOUBLE_HEALTH_COLLECTABLE", 0x15)
            OPTION("TBS_CHEAT_CABS", 0x16)
            OPTION("TBS_CHEAT_GIANT_BLUE_GORILLA", 0x1a)
            OPTION("TBS_CHEAT_LOW_GRAVITY", 0x13)
            OPTION("TBS_CHEAT_ROAD_RAGE", 0x25)
            OPTION("TBS_CHEAT_MASS_TRANSIT", 0x26)
            OPTION("TBS_CHEAT_COLOUR_CONCEPT_1", 0x27)
            OPTION("TBS_CHEAT_COLOUR_CONCEPT_2", 0x28)
            OPTION("TBS_CHEAT_COLOUR_CONCEPT_3", 0x29)
            OPTION("TBS_CHEAT_COW_MISSILES", 0x2f)
                    f.A.FUN_000f7960();
                }
            }
        }
        f.i++;
        f.p++;
    } while (f.i < f.t->count);
}
} // namespace fn_000b5ca0
#undef CHEAT
#undef OPTION
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000b73b0 FUN_000b73b0 (217 B): equivalent/0x000b73b0.cpp [wrapped: conflict: DAT_0049dba4; FUN_000fc1b0]
// sym: ?target@Owner_b73b0@fn_000b73b0@@QAEXXZ
namespace fn_000b73b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 10/10)
// FUN_000b73b0 @ 0x000b73b0

struct Manager_b73b0 { int FUN_000f7240(unsigned __int64 id); };
extern Manager_b73b0* __cdecl FUN_000fc1b0();
extern void* __cdecl FUN_000fc260(const char*);
extern int DAT_0049dba4; extern int DAT_0049f470;
struct Text_b73b0 { void FUN_000f8500(const char*,Manager_b73b0*,int);  };
struct Dialog_b73b0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void close(); char pad[0x14]; Text_b73b0 text; };
extern Dialog_b73b0* __cdecl FUN_00344e74(void*,int,void*,void*,int);
struct Source_b73b0 { void* FUN_0008a2f0(); };
extern "C++" __declspec(nothrow) unsigned __int64 __cdecl FUN_0027b020(void*);
struct Entry_b73b0 { unsigned __int64 id; char pad[32]; const char* FUN_0027b010(); };
struct Owner_b73b0 { char pad0[0x34]; Source_b73b0* source; char pad1[0x448]; Entry_b73b0 entries[1]; int FUN_000b4d70(unsigned __int64); void target(); };
void Owner_b73b0::target() { if (!source) return; Dialog_b73b0* d=FUN_00344e74(FUN_000fc260("mission_brief_text"),0,&DAT_0049dba4,&DAT_0049f470,0); if (!d) return; d->text.FUN_000f8500(((char*)&DAT_003f335c),FUN_000fc1b0(),0); void* p=source->FUN_0008a2f0(); if (!p) {d->close(); return;} int n=FUN_000b4d70(FUN_0027b020(p)); if(n!=-1) { Entry_b73b0* e=&entries[n]; unsigned __int64 id=e->id; int x=FUN_000fc1b0()->FUN_000f7240(id); if(x!=-1) ((owners::Obj_f7a10 *)&(d->text))->FUN_000f7a10((hulk_intptr)x, 0); else {Manager_b73b0* m=FUN_000fc1b0(); const char* s=e->FUN_0027b010(); d->text.FUN_000f8500(s,m,1);} } d->close(); }
} // namespace fn_000b73b0


// 0x000b7490 FUN_000b7490 (256 B): equivalent/0x000b7490.cpp [wrapped: conflict: DAT_0049dba4; FUN_00344e74]
// sym: ?FUN_000b7490@Owner_b7490@fn_000b7490@@QAEXXZ
namespace fn_000b7490 {
// STATUS: equivalent (tools/equiv.py level 3: 3058 inputs, branch coverage 32/32)
// FUN_000b7490 @ 0x000b7490

struct Button_b7490 { char pad[0x141]; unsigned char enabled; };
struct Source_b7490 { const char* FUN_0008a2d0();  };
extern char DAT_0049dba4;
extern char DAT_0049f4a4;
extern void* __cdecl FUN_000fc260(const char*);
extern Button_b7490* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Owner_b7490 { char pad[0x34]; Source_b7490* source; void FUN_000b7490(); };
void Owner_b7490::FUN_000b7490() {
 Button_b7490* button = FUN_00344e74(FUN_000fc260("abort_mission_button"),0,&DAT_0049dba4,&DAT_0049f4a4,0);
 if (!button || !source) return;
 const char* first = source->FUN_0008a2d0();
 const char* second = ((const char *)((owners::C_8a310 *)source)->FUN_0008a310());
 unsigned char enabled = 0;
 if (first && second) {
  const unsigned char* a=(const unsigned char*)first;
  const unsigned char* b=(const unsigned char*)second;
  while (*a == *b && *a) { ++a; ++b; }
  enabled = (*a != *b);
  for (int i=0; ((const char**)&DAT_004067a4)[i]; ++i) {
   a=(const unsigned char*)first;
   b=(const unsigned char*)((const char**)&DAT_004067a4)[i];
   while (*a == *b && *a) { ++a; ++b; }
   if (*a == *b) { enabled=0; break; }
  }
 }
 button->enabled=enabled;
}
} // namespace fn_000b7490


// 0x000b7590 FUN_000b7590 (132 B): matches/0x000b7590.cpp [wrapped: conflict: DAT_0049dba4; DAT_0049f4a4; FUN_000fc260]
// sym: ?Func@Menu_b7590@fn_000b7590@@QAEXXZ
namespace fn_000b7590 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int strcmp(const char*, const char*);
#endif


struct Obj2_b7590 {
    char pad[0x141];
    char flag;
};

struct Inner_b7590 {
    const char* GetName();
};

struct Menu_b7590 {
    char pad[0x34];
    Inner_b7590* mInner;
    void Func();
};

extern int DAT_0049dba4;
extern int DAT_0049f4a4;
extern int FUN_000fc260(const char* s);
extern Obj2_b7590* __cdecl FUN_00344e74(int a, int b, int* c, int* d, int e);

void Menu_b7590::Func() {
    Obj2_b7590* o = FUN_00344e74(FUN_000fc260("restart_mission_button"), 0, &DAT_0049dba4, &DAT_0049f4a4, 0);
    if (!o)
        return;
    if (!mInner)
        return;
    const char* n = mInner->GetName();
    char r = 1;
    if (n) {
        if (strcmp(n, "c00m01") != 0) {
            const char* s = ((const char *)((owners::Obj_8a060 *)mInner)->FUN_0008a060((hulk_intptr)n));
            if (strcmp(s, "complete") == 0)
                r = 0;
        }
    }
    o->flag = r;
}
} // namespace fn_000b7590


// 0x000b7620 FUN_000b7620 (53 B): matches/0x000b7620.cpp [wrapped: conflict: DAT_0049dba4]
// sym: ?FUN_000b7620@fn_000b7620@@YGXD@Z
namespace fn_000b7620 {
struct Desc {
    int x;
};
extern Desc DAT_0049dba4, DAT_0049f4a4;
extern "C++" __declspec(nothrow) int __cdecl FUN_000fc260(const char*);
extern "C++" __declspec(nothrow) char* __cdecl FUN_00344e74(int, int, Desc*, Desc*, int);
void __stdcall FUN_000b7620(char v) {
    char* p = FUN_00344e74(FUN_000fc260("mission_success_continue_button"), 0, &DAT_0049dba4, &DAT_0049f4a4, 0);
    if (p)
        p[0x141] = v;
}
} // namespace fn_000b7620


// 0x000b7660 FUN_000b7660 (95 B): matches/0x000b7660.cpp [wrapped: conflict: DAT_0049dba4; FUN_000fc260]
// sym: ?update@Owner_b7660@fn_000b7660@@QAEXXZ
namespace fn_000b7660 {
class Selector_b7660 {
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
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void select(int);
    char pad[0x1d54];
    int count;
};
class State_b7660 {
    char pad[12];

  public:
    char active;
};
class Owner_b7660 {
    char pad[0x5c];
    State_b7660* state;

  public:
    void update();
};
extern int DAT_0049dba4, DAT_0049dbbc;
extern int __cdecl FUN_000fc260(const char*);
extern Selector_b7660* __cdecl FUN_00344e74(int, int, void*, void*, int);
void Owner_b7660::update() {
    if (state) {
        Selector_b7660* p = FUN_00344e74(FUN_000fc260("subtitle_selector"), 0, &DAT_0049dba4, &DAT_0049dbbc, 0);
        if (p) {
            if (state->active) {
                if (p->count > 0)
                    p->select(0);
            } else {
                if (p->count > 1)
                    p->select(1);
            }
        }
    }
}
} // namespace fn_000b7660


// 0x000b76c0 FUN_000b76c0 (153 B): equivalent/0x000b76c0.cpp [wrapped: conflict: FUN_000fc260]
// sym: ?FUN_000b76c0@PauseScreen@fn_000b76c0@@QAEXXZ
namespace fn_000b76c0 {
// STATUS: equivalent (tools/equiv.py level 3: 19939 inputs, branch coverage 10/10)
// FUN_000b76c0 @ 0x000b76c0
// MSVC 7.1 expands memcmp inline (repe cmpsb); so does this.
static inline int memcmp_inline(const void *a, const void *b, unsigned n)
{
    const unsigned char *p = (const unsigned char *)a;
    const unsigned char *q = (const unsigned char *)b;
    for (; n != 0; n--, p++, q++)
        if (*p != *q)
            return *p - *q;
    return 0;
}

class FEObject_b76c0 {
public:
    virtual void v0();
};
class TextButton_b76c0 : public FEObject_b76c0 {
public:
    char pad04[0x141 - 4];
    char complete;
};

struct Counter_b76c0 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};
struct Stats_b76c0 {
    char pad0[0x80];
    Counter_b76c0 counter;
    int FUN_0008a2d0();
};

FEObject_b76c0 *__cdecl FUN_000fc260(const char *name);

class PauseScreen {
public:
    char pad0[0x34];
    Stats_b76c0 *stats;
    void FUN_000b76c0();
};

// Marks the pause menu's save button as "complete" for save states 1..7.
void PauseScreen::FUN_000b76c0()
{
    TextButton_b76c0 *button = dynamic_cast<TextButton_b76c0 *>(FUN_000fc260("pause_save"));
    if (button) {
        int state = stats->counter.FUN_00088fa0();
        int other = stats->counter.FUN_00088fb0();
        int nameId = stats->FUN_0008a2d0(); // the argument is evaluated (and stats reloaded) before the lookup call
        const char *name = ((const char *)((owners::Obj_8a060 *)stats)->FUN_0008a060((hulk_intptr)nameId));
        if (state >= 1 && state <= 7 && (other == 0 || memcmp_inline("complete", name, 9) == 0))
            button->complete = 1;
        else
            button->complete = 0;
    }
}
} // namespace fn_000b76c0

namespace fn_fedc4c02 {

// 0x000b7760 FUN_000b7760 (94 B): matches/0x000b7760.cpp
// sym: ?Run@Obj_b7760@fn_fedc4c02@@QAEXXZ
// data: key = DAT_004080a8
void Obj_b7760::Run() {
    Button_b7760* b = Convert(Find(DAT_004080a8), 0, &type1_b7760, &type2, 0);
    if (b) {
        int count = 0;
        for (int i = 0x266; i <= 0x2c9; ++i)
            if (!((char)((owners::C_92860 *)mgr)->FUN_00092860((hulk_intptr)i)))
                ++count;
        b->flag = count > 0;
    }
}


// 0x000b77c0 FUN_000b77c0 (151 B): matches/0x000b77c0.cpp
// sym: ?FUN_000b77c0@fn_fedc4c02@@YG_NHPAGHH@Z
// FUN_000b77c0 @ 0x000b77c0
// Looks the key up in the string table and copies the localised text into buf if it fits.
bool __stdcall FUN_000b77c0(int key, unsigned short *buf, int maxLength, int unused)
{
    Lookup_b77c0 lookup;
    ((owners::State_f7930 *)&lookup)->FUN_000f7930();
    lookup.FUN_000f8500(key, FUN_000fc3d0()->GetLanguage(), 1);
    const unsigned short *text = lookup.FUN_000f83f0(FUN_000fc3d0()->GetLanguage(), 0);
    int length = FUN_00294b80(text);
    if (length > maxLength) {
        ((owners::Thing_f7960 *)&lookup)->FUN_000f7960();
        return false;
    }
    memcpy(buf, text, (length + 1) * 2);
    ((owners::Thing_f7960 *)&lookup)->FUN_000f7960();
    return true;
}

} // namespace fn_fedc4c02

// 0x000b7860 FUN_000b7860 (122 B): equivalent/0x000b7860.cpp [wrapped: conflict: FEObject; FUN_000fc260; TextLabel]
// sym: ?FUN_000b7860@FileLock@fn_000b7860@@QAEXPAUEntry_b7860@2@@Z
namespace fn_000b7860 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000b7860 @ 0x000b7860
class FEObject { public: virtual void o0(); };

struct LabelText {
    void FUN_000f8500(const char* text, int value, int flag);
};

class TextLabel : public FEObject {
public:
    char pad04[0x14];
    LabelText label;                  // 0x18
};

struct Journal {
    bool FUN_00092860(const void* key);
};

struct Entry_b7860 {
    char pad0[0x34];
    char key[1];
};

FEObject* __cdecl FUN_000fc260(const char* name);
int __cdecl FUN_000fc1b0();

class FileLock {
public:
    char pad0[0x4c];
    Journal* journal;
    void FUN_000b7860(Entry_b7860* entry);
};

void FileLock::FUN_000b7860(Entry_b7860* entry) {
    if (!journal)
        return;
    TextLabel* text = dynamic_cast<TextLabel*>(FUN_000fc260("blonsky_file_lock_label"));
    if (!text)
        return;
    bool found = journal->FUN_00092860(entry->key);
    text->label.FUN_000f8500(found ? "" : "TBS_BLONSKY_FILE_FOUND", FUN_000fc1b0(), 1);
}
} // namespace fn_000b7860


// 0x000b78e0 FUN_000b78e0 (163 B): equivalent/0x000b78e0.cpp [wrapped: conflict: FUN_000fc260]
// sym: ?FUN_000b78e0@Screen_b78e0@fn_000b78e0@@QAEXPBD@Z
namespace fn_000b78e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000b78e0 @ 0x000b78e0
// equiv-map: ??_R0?AVFEObject@@@8 = 0x0049dba4
// equiv-map: ??_R0?AVTextSelector@@@8 = 0x0049dbbc
// equiv-map: ??_R0?AVCUnlockable@@@8 = 0x0049dab8
// equiv-map: ??_R0?AVCUnlockableBlonskyFile@@@8 = 0x0049dad4

class FEObject_b78e0 {
public:
    virtual void f0();
};

class Target_b78e0 {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39(); virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); virtual void f44(); virtual void f45(); virtual void f46(); virtual void f47(); virtual void f48();
    virtual void f49(int v);
};

class CUnlockable_b78e0 {
public:
    virtual void u0();
};

class CUnlockableBlonskyFile_b78e0 : public CUnlockable_b78e0 {
public:
    virtual void u1();
};

struct Link8_b78e0 {
    char pad0[4];
    Target_b78e0 *target;          // 0x04
};

struct Link14 {
    char pad0[8];
    Link8_b78e0 *next;             // 0x08
};

class TextSelector_b78e0 : public FEObject_b78e0 {
public:
    char pad04[0x14 - 4];
    Link14 *link;            // 0x14
    char pad18[0x154 - 0x18];
    char *list;              // 0x154
    char pad158[0x1d58 - 0x158];
    int count;               // 0x1d58
};

struct Store {
};

struct Cursor_b78e0 {
    void FUN_001be060();
};

FEObject_b78e0 *__cdecl FUN_000fc260(const char *name);

class Screen_b78e0 {
public:
    char pad0[0x4c];
    Store *store;            // 0x4c
    char pad50[0x5c - 0x50];
    Cursor_b78e0 *cursor;          // 0x5c
    void FUN_000b78e0(const char *name);
};

void Screen_b78e0::FUN_000b78e0(const char *name)
{
    if (store == 0)
        return;
    TextSelector_b78e0 *sel = dynamic_cast<TextSelector_b78e0 *>(FUN_000fc260(name));
    if (sel == 0)
        return;
    if (sel->count == 0)
        return;
    if (cursor != 0)
        cursor->FUN_001be060();
    CUnlockableBlonskyFile_b78e0 *file = dynamic_cast<CUnlockableBlonskyFile_b78e0 *>(((CUnlockable_b78e0 *)((owners::C_92ad0 *)store)->FUN_00092ad0((hulk_intptr)(sel->list + 0x34))));
    if (file == 0)
        return;
    sel->link->next->target->f49(((int)(hulk_uintptr)((owners::C_91d20 *)(CUnlockable_b78e0 *)file)->FUN_00091d20()));
}
} // namespace fn_000b78e0


// 0x000b8240 FUN_000b8240 (494 B): equivalent/0x000b8240.cpp [wrapped: conflict: FUN_000fc3d0]
// sym: ?FUN_000b8240@HintMenu_b8240@fn_000b8240@@QAEXXZ
namespace fn_000b8240 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 42/42)
// FUN_000b8240 @ 0x000b8240
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_000fc260(const char *name);

struct Label_b8240 {
    int f00;
    char f04;
    char pad05[3];
    int f08;
    int f0c;
    char *f10;
    int f14;
    char f18;
    char pad19[3];
    float f1c;
    int f20;
    void FUN_000f8500(const char *text, int a, char flag);
};

class Anim_b8240 {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
};
Anim_b8240 *__cdecl FUN_000fc3d0();

class HintList {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19(Label_b8240 *label, int a, int b);
    void FUN_000e36c0();
};

struct CodeTable_b8240 {
};

class HintMenu_b8240 {
public:
    char pad00[0x4c];
    CodeTable_b8240 *codes;        // 0x4c
    char pad50[0x1b50 - 0x50];
    int shown[32];           // 0x1b50
    void FUN_000b8240();
};

void HintMenu_b8240::FUN_000b8240()
{
    Label_b8240 label;
    HintList *list = (HintList *)FUN_00344e74(FUN_000fc260("smart_hint_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (list) {
        list->FUN_000e36c0();
        FUN_000fc3d0()->v44();
        int *out = shown;
        for (int id = 0x2e9; id <= 0x2fd; id++) {
            if (((char)((owners::C_92860 *)codes)->FUN_00092860((hulk_intptr)id)))
                continue;
            const char *name = 0;
            switch (id) {
            case 0x2e9: name = "TBS_SH_HEAD_COLLECTIBLE_BOSSMARKER"; break;
            case 0x2ea: name = "TBS_SH_HEAD_CHASE_HUD"; break;
            case 0x2eb: name = "TBS_SH_HEAD_STORY_MODE"; break;
            case 0x2ec: name = "TBS_SH_HEAD_OBJECTIVE_HEALTH"; break;
            case 0x2ed: name = "TBS_SH_HEAD_BUYMOVES"; break;
            case 0x2ee: name = "TBS_SH_HEAD_SMART_HINTS"; break;
            case 0x2ef: name = "TBS_SH_HEAD_BLONSKY_FILES"; break;
            case 0x2f0: name = "TBS_SH_HEAD_DEPENDENCIES"; break;
            case 0x2f1: name = "TBS_SH_HEAD_BOSS_HEALTH"; break;
            case 0x2f2: name = "TBS_SH_HEAD_TIMER"; break;
            case 0x2f3: name = "TBS_SH_HEAD_NEWMISSION"; break;
            case 0x2f4: name = "TBS_SH_HEAD_STRUGGLE"; break;
            case 0x2f5: name = "TBS_SH_HEAD_ADRENALINE"; break;
            case 0x2f6: name = "TBS_SH_HEAD_GRAB_THROW"; break;
            case 0x2f7: name = "TBS_SH_HEAD_STRIKE_COMBO"; break;
            case 0x2f8: name = "TBS_SH_HEAD_RUNNING"; break;
            case 0x2f9: name = "TBS_SH_HEAD_FLOATER"; break;
            case 0x2fa: name = "TBS_SH_HEAD_SUB_TARGETING"; break;
            }
            if (name == 0)
                continue;
            ((owners::State_f7930 *)&label)->FUN_000f7930();
            label.FUN_000f8500(name, 0, 1);
            list->vfunc_19(&label, 0, 0);
            *out = id;
            out++;
            ((owners::Thing_f7960 *)&label)->FUN_000f7960();
        }
        list->vfunc_3();
    }
}
} // namespace fn_000b8240


// 0x000b8860 FUN_000b8860 (211 B): equivalent/0x000b8860.cpp [wrapped: conflict: DAT_0049dba4]
// sym: ?FUN_000b8860@Target_b8860@fn_000b8860@@QAEXXZ
namespace fn_000b8860 {
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 12/12)
// FUN_000b8860 @ 0x000b8860

struct TypeInfo_b8860 { unsigned int value; }; extern TypeInfo_b8860 DAT_0049dba4, DAT_0049dbbc;
extern void* __cdecl FUN_000fc260(const char*);
struct Temp_b8860 { char storage[36];  void FUN_000f8500(unsigned int, int, int);  };
struct List_b8860 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void finish(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void add(Temp_b8860*, int, int); void FUN_000e36c0(); };
extern List_b8860* __cdecl FUN_00344e74(void*, int, TypeInfo_b8860*, TypeInfo_b8860*, int);
struct Entry_b8860 { const char* key; unsigned int value; unsigned int unknown; }; 
struct State_b8860 {  bool FUN_000893c0(); };
struct Target_b8860 { char pad[52]; State_b8860* state; void FUN_000b8860(); };
void Target_b8860::FUN_000b8860() {
 List_b8860* list=FUN_00344e74(FUN_000fc260("story_recap_list"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 if (!list) return;
 list->FUN_000e36c0();
 Entry_b8860* entry=((Entry_b8860*)&DAT_00406738);
 if(entry->key) {
 do {
 const char* result=((const char *)((owners::Obj_8a060 *)state)->FUN_0008a060((hulk_intptr)(entry->key)));
 if(!state->FUN_000893c0()) {
 if(!result) break;
 const char* text="complete"; int i;
 for(i=0;i<9;++i) if(result[i]!=text[i]) break;
 if(i!=9) break;
 }
 Temp_b8860 temp; ((owners::State_f7930 *)&temp)->FUN_000f7930(); temp.FUN_000f8500(entry->value,0,1); list->add(&temp,0,0); ((owners::Thing_f7960 *)&temp)->FUN_000f7960();
 ++entry;
 } while(entry->key);
 }
 list->finish();
}
} // namespace fn_000b8860


// 0x000b8940 FUN_000b8940 (122 B): matches/0x000b8940.cpp [wrapped: conflict: FEObject; FUN_000fc260; TextSelector; TextWindow]
// sym: ?FUN_000b8940@fn_000b8940@@YAXXZ
namespace fn_000b8940 {
// FUN_000b8940 @ 0x000b8940

class FEObject { public: virtual void o0(); };
class TextSelector : public FEObject {
public:
    virtual void t1();
    virtual void t2();
    char pad04[0x150];
    int selection;
};
class TextWindow : public FEObject {
public:
    virtual void w1();
    virtual void w2();
    virtual void w3();
    void FUN_000e2a60(const char* text);
};

struct StoryText {
    const char* text;
    int a;
    int b;
};

FEObject* __cdecl FUN_000fc260(const char* name);

void FUN_000b8940() {
    TextSelector* list = dynamic_cast<TextSelector*>(FUN_000fc260("story_recap_list"));
    if (!list)
        return;
    TextWindow* window = dynamic_cast<TextWindow*>(FUN_000fc260("story_recap_text"));
    if (!window)
        return;
    window->FUN_000e2a60(((StoryText*)&DAT_00406740)[list->selection].text);
    window->w3();
}
} // namespace fn_000b8940

namespace fn_fedc4c02 {

// 0x000b89c0 FUN_000b89c0 (25 B): matches/0x000b89c0.cpp
// sym: ?Set@Obj@fn_fedc4c02@@QAEXPBD@Z
void Obj::Set(const char* s) {
    strncpy((char*)this + 0x1bcc, s, 0x40);
}


// 0x000b8c50 FUN_000b8c50 (56 B): matches/0x000b8c50.cpp
// sym: ?TargetFn@fn_fedc4c02@@YGXHH@Z
void __stdcall TargetFn(int param1, int param2) {
    Obj_b8c50* obj = GetManager()->v3(param1);
    if (obj) {
        Entry_b8c50* entry = FindEntry(param2);
        if (entry) {
            obj->v19(entry->field14);
        }
    }
}

} // namespace fn_fedc4c02

// 0x000b8c90 FUN_000b8c90 (97 B): matches/0x000b8c90.cpp
// sym: ?FUN_000b8c90@Foo_b8c90@owners@@QAE_NXZ
bool owners::Foo_b8c90::FUN_000b8c90() {
    if (GetObj()) {
        const char* s = GetObj()->Name();
        if (s) {
            if (strcmp("fullscreen_message", s) == 0 || strcmp("mission_accept", s) == 0) {
                if (v < 2.0f)
                    return true;
            }
        }
    }
    return false;
}


// 0x000b8e70 FUN_000b8e70 (147 B): matches/0x000b8e70.cpp [wrapped: conflict: FUN_000fc260]
// sym: ?FUN_000b8e70@JumpMarkers@fn_000b8e70@@QAEXH@Z
namespace fn_000b8e70 {
// FUN_000b8e70 @ 0x000b8e70
class FEObject_b8e70 {
public:
    virtual void v0();
};

class TextSelector_b8e70 : public FEObject_b8e70 {
public:
    char pad4[0x154 - 4];
    int selection;          // 0x154
    char pad158[0x1d58 - 0x158];
    void *items;            // 0x1d58
};

class MapThing_b8e70 : public FEObject_b8e70 {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual void SetMarker(int marker);     // slot 11
};

FEObject_b8e70 *__cdecl FUN_000fc260(const char *name);

struct MarkerIndex {
};

struct MarkerTable {
    int FUN_00093260(int index);
};

class JumpMarkers {
public:
    char pad0[0x34];
    MarkerIndex *index;     // 0x34
    char pad38[0x4c - 0x38];
    MarkerTable *table;     // 0x4c

    void FUN_000b8e70(int unused);
};

void JumpMarkers::FUN_000b8e70(int unused)
{
    if (table == 0)
        return;
    TextSelector_b8e70 *selector = dynamic_cast<TextSelector_b8e70 *>(FUN_000fc260("jump_marker_selector"));
    if (selector == 0 || selector->items == 0)
        return;
    int i = ((owners::C_89960 *)index)->FUN_00089960(selector->selection);
    if (i == -1)
        return;
    int marker = table->FUN_00093260(i);
    MapThing_b8e70 *map = dynamic_cast<MapThing_b8e70 *>(FUN_000fc260("jump_marker_map"));
    if (map != 0)
        map->SetMarker(marker);
}
} // namespace fn_000b8e70


// 0x000b9090 FUN_000b9090 (45 B): matches/0x000b9090.cpp
// sym: ?FUN_000b9090@Target_b9090@owners@@QAEXH@Z
void owners::Target_b9090::FUN_000b9090(int value) {
    CallA(value);
    if (CallB() == 0) {
        if (CallC() == 0) {
            state = 4;
        }
    }
}

namespace fn_fedc4c02 {

// 0x000b90c0 FUN_000b90c0 (358 B): equivalent/0x000b90c0.cpp
// sym: ?FUN_000b90c0@Menu_b90c0@fn_fedc4c02@@QAEX_N@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000b90c0 @ 0x000b90c0
void Menu_b90c0::FUN_000b90c0(bool save) {
    if (save) {
        ((owners::C_1b8820 *)renderer)->FUN_001b8820(&saved0[0], &saved0[1], &saved0[2]);
        ((owners::C_1b8840 *)renderer)->FUN_001b8840(&saved1[0], &saved1[1], &saved1[2]);
        ((owners::C_1b8860 *)renderer)->FUN_001b8860((int *)(&saved2[0]), (int *)(&saved2[1]), (int *)(&saved2[2]), (int *)(&saved2[3]), (int *)(&saved2[4]), (int *)(&saved2[5]));
        savedFlag = ((char)((owners::Obj_1b8810 *)renderer)->FUN_001b8810());
        ((::CRenderManager *)renderer)->FUN_001b87d0(255, 255, 255);
        ((::CRenderManager *)renderer)->FUN_001b87f0(255, 255, 255);
        renderer->FUN_001b98e0(1.0f, 0.1f, 12.0f, -24.0f, 0.0f, 0.0f);
        renderer->FUN_001b8780(1);
    } else {
        ((::CRenderManager *)renderer)->FUN_001b87d0(saved0[0], saved0[1], saved0[2]);
        ((::CRenderManager *)renderer)->FUN_001b87f0(saved1[0], saved1[1], saved1[2]);
        renderer->FUN_001b98e0(saved2[0], saved2[1], saved2[2], saved2[3], saved2[4], saved2[5]);
        renderer->FUN_001b8780(savedFlag);
    }
}


// 0x000b9230 FUN_000b9230 (187 B): matches/0x000b9230.cpp
// sym: _FUN_000b9230
// FUN_000b9230 @ 0x000b9230
extern "C" void __cdecl FUN_000b9230(Widget_b9230* widget) {
    int saved = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(1);
    DAT_0052c2a8->v12(6);
    (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
    float scale = 1.3333f / (*(Viewport_b9230**)&DAT_0052c2a4)->v16();
    (*(Canvas**)&DAT_0052c2ac)->layer->v13(0);
    (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(scale, scale, 1.0f);
    (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(-0.5f, -0.375f, 1.0f);
    if (widget)
        widget->v8(0, 0);
    (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
    DAT_0052c2a8->v24(saved);
}

} // namespace fn_fedc4c02

// 0x000b92f0 FUN_000b92f0 (250 B): equivalent/0x000b92f0.cpp [wrapped: conflict: DAT_0049dba4; FUN_00344e74]
// sym: ?target@Owner_b92f0@fn_000b92f0@@QAEXHHH@Z
namespace fn_000b92f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2938 inputs, branch coverage 11/11)
// FUN_000b92f0 @ 0x000b92f0

struct Label_b92f0 { void FUN_000f8500(const char*, int, int); };
struct Item_b92f0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); char pad[20]; Label_b92f0 label; };
extern int DAT_0049dba4, DAT_0049f48c;
extern "C" void __cdecl FUN_000fc280(const char*);
void* __cdecl FUN_000fc260(const char*);
Item_b92f0* __cdecl FUN_00344e74(void*, int, void*, void*, int);
int __cdecl FUN_000fc1b0();
extern "C" int __cdecl FUN_000fc320();
extern "C" void __cdecl FUN_000fc2e0();
void __cdecl FUN_000fc1a0();
extern "C" unsigned int __cdecl FUN_00267f80();
extern "C" void __cdecl FUN_000fc300();
struct Renderer_b92f0 { char pad[0xd8]; int state;  void FUN_0028faf0(int); };
struct Scene_b92f0 { void FUN_00293ef0(); void FUN_00294080(); };
struct Owner_b92f0 { char pad[0x20]; Scene_b92f0* scene; void target(int,int,int); };
void Owner_b92f0::target(int a,int b,int flag) {
 FUN_000fc280("Loading");
 Item_b92f0* item=FUN_00344e74(FUN_000fc260("loading_loading_label"),0,&DAT_0049dba4,&DAT_0049f48c,0);
 if(item) {
  Label_b92f0* label=&item->label;
  if(label) { int token=FUN_000fc1b0(); label->FUN_000f8500((unsigned char)flag ? "TBS_MENU_ITEM_PRESS_START2" : "TBS_MENU_ITEM_MC_LOADING_1",token,1); }
  item->v3();
 }
 if(FUN_000fc320()) FUN_000fc2e0();
 for(int i=0;i<3;++i) {
  (*(Renderer_b92f0**)&DAT_0052c2b4)->state=-1;
  ((owners::X_28f9a0 *)((*(Renderer_b92f0**)&DAT_0052c2b4)))->FUN_0028f9a0();
  scene->FUN_00293ef0();
  FUN_000fc1a0();
  scene->FUN_00294080();
  (*(Renderer_b92f0**)&DAT_0052c2b4)->FUN_0028faf0(1);
 }
 (*(float*)&DAT_004ddbd4)=(float)FUN_00267f80()*0.001f;
 FUN_000fc300();
}
} // namespace fn_000b92f0


// 0x000b9470 FUN_000b9470 (425 B): equivalent/0x000b9470.cpp [wrapped: conflict: Canvas; Gfx]
// sym: ?FUN_000b9470@fn_000b9470@@YGXIPAVTexture@1@@Z
namespace fn_000b9470 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000b9470 @ 0x000b9470
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

struct Vertex_b9470 {
    float x;
    float y;
    float z;
};
class Mesh_b9470 {
  public:
    char pad0[8];
    Vertex_b9470* verts;
    char pad1[4];
    unsigned int* colors;
    void FUN_0008ef00();
};
class Texture {
  public:
    char pad[0x10];
    int handle;
};
class Gfx {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int mode);
    virtual int v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual Mesh_b9470* v30(int handle, int a, int b, int c, int d);
    virtual void v31(Mesh_b9470* m);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(int on);
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58(int on);
};
class Layer_b9470 {
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
    virtual void v13(int a);
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};
class Viewport_b9470 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
};
struct Canvas {
    Layer_b9470* layer;
};

void __stdcall FUN_000b9470(unsigned int alpha, Texture* texture) {
    float width = (float)(*(Viewport_b9470**)&DAT_0052c2a4)->v7();
    float height = (float)(*(Viewport_b9470**)&DAT_0052c2a4)->v6();
    if (alpha > 0xff)
        alpha = 0xff;
    int saved = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(2);
    DAT_0052c2a8->v54(0);
    DAT_0052c2a8->v58(0);
    (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
    (*(Canvas**)&DAT_0052c2ac)->layer->v13(0);
    unsigned int color = alpha << 24;
    Mesh_b9470* mesh = DAT_0052c2a8->v30(texture->handle, 1, 0x2020, 4, 0);
    *mesh->colors = color;
    mesh->verts->x = 0.0f;
    mesh->verts->y = height;
    mesh->verts->z = 2.0f;
    mesh->FUN_0008ef00();
    *mesh->colors = color;
    mesh->verts->x = 0.0f;
    mesh->verts->y = 0.0f;
    mesh->verts->z = 2.0f;
    mesh->FUN_0008ef00();
    *mesh->colors = color;
    mesh->verts->x = width;
    mesh->verts->y = height;
    mesh->verts->z = 2.0f;
    mesh->FUN_0008ef00();
    *mesh->colors = color;
    mesh->verts->x = width;
    mesh->verts->y = 0.0f;
    mesh->verts->z = 2.0f;
    mesh->FUN_0008ef00();
    DAT_0052c2a8->v31(mesh);
    DAT_0052c2a8->v24(saved);
    DAT_0052c2a8->v54(1);
    DAT_0052c2a8->v58(1);
    (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
}
} // namespace fn_000b9470
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fedc4c02 {

// 0x000b9620 FUN_000b9620 (45 B): matches/0x000b9620.cpp
// sym: ?Target@Obj_b9620@fn_fedc4c02@@QAEXXZ
void Obj_b9620::Target() {
    if (p) {
        p->A();
        p->B(0);
        if (!p->C())
            FUN_000fc2f0();
    }
}

} // namespace fn_fedc4c02

// 0x000b9650 FUN_000b9650 (134 B): matches/0x000b9650.cpp [wrapped: conflict: FUN_000fc3d0]
// sym: ?FUN_000b9650@Menu_b9650@fn_000b9650@@QAEXXZ
namespace fn_000b9650 {
// FUN_000b9650 @ 0x000b9650
class Player_b9650 {
  public:
    char pad[0x9a8];
    char busy;
};
class Game_b9650 {
  public:
    char pad[0x2218];
    Player_b9650* player;
    int mode;
};
class Fader_b9650 {
  public:
    void FUN_001eb870();
    void FUN_001eb2a0(float dt, int flag);
    void FUN_001eb890();
};
class Panel_b9650 {
  public:
    void FUN_00089d30();
};
Game_b9650* __cdecl FUN_000fc3d0();
extern "C" void __cdecl FUN_000fc280(const char* name);

class Menu_b9650 {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x34 - 0x14];
    Panel_b9650* panel;
    char pad1b[4];
    Fader_b9650* fader;
    char pad2[0x1cf8 - 0x40];
    int saveSlot;
    void FUN_000b5030(int slot);
    void FUN_000b9650();
};

void Menu_b9650::FUN_000b9650() {
    if (state != 0x12)
        return;
    Player_b9650* p = FUN_000fc3d0()->player;
    if (p != 0 && p->busy != 0)
        return;
    state = 0;
    if (FUN_000fc3d0()->mode != 1)
        return;
    fader->FUN_001eb870();
    for (int i = 0; i < 10; i++)
        fader->FUN_001eb2a0(0.01f, 0);
    panel->FUN_00089d30();
    FUN_000b5030(saveSlot);
    FUN_000fc280("save_new_game");
    fader->FUN_001eb890();
}
} // namespace fn_000b9650


// 0x000b96e0 FUN_000b96e0 (134 B): matches/0x000b96e0.cpp [wrapped: conflict: FUN_000fc3d0]
// sym: ?FUN_000b96e0@Menu_b96e0@fn_000b96e0@@QAEXXZ
namespace fn_000b96e0 {
// FUN_000b96e0 @ 0x000b96e0
class Player_b96e0 {
  public:
    char pad[0x9a8];
    char busy;
};
class Game_b96e0 {
  public:
    char pad[0x2218];
    Player_b96e0* player;
    int mode;
};
class Fader_b96e0 {
  public:
    void FUN_001eb870();
    void FUN_001eb2a0(float dt, int flag);
    void FUN_001eb890();
};
class Panel_b96e0 {
  public:
};
Game_b96e0* __cdecl FUN_000fc3d0();
extern "C" void __cdecl FUN_000fc280(const char* name);

class Menu_b96e0 {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x34 - 0x14];
    Panel_b96e0* panel;
    char pad1b[4];
    Fader_b96e0* fader;
    char pad2[0x1cf8 - 0x40];
    int saveSlot;
    void FUN_000b5030(int slot);
    void FUN_000b96e0();
};

void Menu_b96e0::FUN_000b96e0() {
    if (state != 0x13)
        return;
    Player_b96e0* p = FUN_000fc3d0()->player;
    if (p != 0 && p->busy != 0)
        return;
    state = 0;
    if (FUN_000fc3d0()->mode != 1)
        return;
    fader->FUN_001eb870();
    for (int i = 0; i < 10; i++)
        fader->FUN_001eb2a0(0.01f, 0);
    ((owners::W_89e10 *)panel)->FUN_00089e10();
    FUN_000b5030(saveSlot);
    FUN_000fc280("save_new_game");
    fader->FUN_001eb890();
}
} // namespace fn_000b96e0

namespace fn_fedc4c02 {

// 0x000b9770 FUN_000b9770 (91 B): matches/0x000b9770.cpp
// sym: ?Run@Obj_b9770@fn_fedc4c02@@QAEXXZ
void Obj_b9770::Run() {
    if (state == 0x14) {
        Glob_b9770* g = GetGlobal();
        if (!g->state || !g->state->flag) {
            state = 9;
            g = GetGlobal();
            if (g->mode == 1) {
                a->F();
                b->F(9);
                a->G(0);
                FUN_000fc300();
            }
        }
    }
}

} // namespace fn_fedc4c02

// 0x000b99b0 FUN_000b99b0 (275 B): matches/0x000b99b0.cpp [wrapped: conflict: DAT_0049dba4; DAT_0049dbbc; FUN_00344e74]
// sym: ?update@Target_b99b0@fn_000b99b0@@QAEXXZ
namespace fn_000b99b0 {
extern char DAT_0049dba4;
extern char DAT_0049dbbc;
extern char DAT_0049f4d8;
extern void* __cdecl FUN_000fc260(const char*);
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Slider_b99b0 {
    void FUN_000f1a70(float);
};
struct Selector_b99b0 {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(int);
};
struct Audio_b99b0 {
    float FUN_001eba70();
    float FUN_001eb9d0();
    float FUN_001eba20();
    int FUN_001ebac0();
};
struct Target_b99b0 {
    char pad[0x3c];
    Audio_b99b0* audio;
    void update();
};
void Target_b99b0::update() {
    if (!audio)
        return;
    Slider_b99b0* dialogue =
        (Slider_b99b0*)FUN_00344e74(FUN_000fc260("DialogueVolumeSlider"), 0, &DAT_0049dba4, &DAT_0049f4d8, 0);
    Slider_b99b0* music =
        (Slider_b99b0*)FUN_00344e74(FUN_000fc260("MusicVolumeSlider"), 0, &DAT_0049dba4, &DAT_0049f4d8, 0);
    Slider_b99b0* effects =
        (Slider_b99b0*)FUN_00344e74(FUN_000fc260("SoundFXVolumeSlider"), 0, &DAT_0049dba4, &DAT_0049f4d8, 0);
    Selector_b99b0* surround =
        (Selector_b99b0*)FUN_00344e74(FUN_000fc260("SurroundSelector"), 0, &DAT_0049dba4, &DAT_0049dbbc, 0);
    if (dialogue)
        dialogue->FUN_000f1a70(audio->FUN_001eba70());
    if (music)
        music->FUN_000f1a70(audio->FUN_001eb9d0());
    if (effects)
        effects->FUN_000f1a70(audio->FUN_001eba20());
    if (surround)
        surround->v25(audio->FUN_001ebac0());
}
} // namespace fn_000b99b0


// 0x000b9ad0 FUN_000b9ad0 (286 B): matches/0x000b9ad0.cpp [wrapped: conflict: DAT_0049f4d8; FUN_000fc260]
// sym: ?FUN_000b9ad0@OptionsMenu@fn_000b9ad0@@QAEXXZ
namespace fn_000b9ad0 {
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern char DAT_0049f4d8[];

struct Widget;
extern Widget* __cdecl FUN_000fc260(const char* name);
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

struct Slider_b9ad0 {
    void FUN_000f1a70(float value);
};
class Selector_b9ad0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(int value);
};
struct Settings_b9ad0 {
    float FUN_001eba70();
    float FUN_001eb9d0();
    float FUN_001eba20();
    int FUN_001ebac0();
};
class OptionsMenu {
  public:
    char pad[0x3c];
    Settings_b9ad0* settings;
    char pad40[0x1a06 - 0x40];
    unsigned char ready;
    void FUN_000b9ad0();
};
void OptionsMenu::FUN_000b9ad0() {
    if (!settings) {
        ready = 1;
        return;
    }
    Slider_b9ad0* dialogue =
        (Slider_b9ad0*)FUN_00344e74(FUN_000fc260("DialogueVolumeSlider"), 0, DAT_0049dba4, DAT_0049f4d8, 0);
    Slider_b9ad0* music =
        (Slider_b9ad0*)FUN_00344e74(FUN_000fc260("MusicVolumeSlider"), 0, DAT_0049dba4, DAT_0049f4d8, 0);
    Slider_b9ad0* fx = (Slider_b9ad0*)FUN_00344e74(FUN_000fc260("SoundFXVolumeSlider"), 0, DAT_0049dba4, DAT_0049f4d8, 0);
    Selector_b9ad0* surround =
        (Selector_b9ad0*)FUN_00344e74(FUN_000fc260("SurroundSelector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (dialogue)
        dialogue->FUN_000f1a70(settings->FUN_001eba70());
    if (music)
        music->FUN_000f1a70(settings->FUN_001eb9d0());
    if (fx)
        fx->FUN_000f1a70(settings->FUN_001eba20());
    if (surround)
        surround->vfunc_25(settings->FUN_001ebac0());
    ready = 0;
}
} // namespace fn_000b9ad0

namespace fn_fedc4c02 {

// 0x000bb5c0 FUN_000bb5c0 (52 B): matches/0x000bb5c0.cpp
// sym: @FUN_000bb5c0@4
extern "C" void __fastcall FUN_000bb5c0(Obj_bb5c0* self) {
    if (self->flag) {
        self->flag->Init();
        for (int i = 0x248; i <= 0x257; ++i)
            self->sub->Fn(i, 0);
        self->Finish();
    }
}


// 0x000bb670 FUN_000bb670 (7 B): matches/0x000bb670.cpp
// sym: ?FUN_000bb670@fn_fedc4c02@@YIHPAUObject@1@@Z
hulk_intptr __fastcall FUN_000bb670(Object* self) {
    return (hulk_intptr)((char*)self + 0x1bc9);
}

// 0x000bb800 thunk_FUN_001d04a0 (5 B): not yet verified

// 0x000bb820 FUN_000bb820 (181 B): equivalent/0x000bb820.cpp
// sym: ?target@Owner_bb820@fn_fedc4c02@@QAEXPBD00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 16/16)
// FUN_000bb820 @ 0x000bb820
void Owner_bb820::target(const char* mainText, const char* secondText, const char* thirdText) {
 Text_bb820* text = &mainItem->text;
 int value = provider->get();
 text->FUN_000f8500(mainText, value, 1);
 if ((secondText && *secondText) || (thirdText && *thirdText)) mainItem->state = 1; else mainItem->state = 2;
 if (secondText && secondItem) { text = &secondItem->text; value = provider->get(); text->FUN_000f8500(secondText, value, 1); }
 if (thirdText && thirdItem) { text = &thirdItem->text; value = provider->get(); text->FUN_000f8500(thirdText, value, 1); }
}

} // namespace fn_fedc4c02

// 0x000bb970 FUN_000bb970 (177 B): equivalent/0x000bb970.cpp [wrapped: conflict: Object]
// sym: ?update@Object@fn_000bb970@@QAEXPBG00@Z
namespace fn_000bb970 {
// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 16/16)
// FUN_000bb970 @ 0x000bb970
struct Provider_bb970 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual int v44();
};
struct Text_bb970 {  };
struct Element_bb970 { char pad[0x18]; Text_bb970 text; char gap[0x57]; int state; };
struct Object { char pad0[4]; Provider_bb970* provider; char pad1[0x984]; Element_bb970* main; Element_bb970* first; Element_bb970* second; void update(const unsigned short*,const unsigned short*,const unsigned short*); };
void Object::update(const unsigned short* a,const unsigned short* b,const unsigned short* c) {
 Text_bb970* text = &main->text;
 int value = provider->v44();
 ((owners::Obj_f79a0 *)text)->FUN_000f79a0((const short *)a, (hulk_intptr)value);
 main->state = ((b && *b) || (c && *c)) ? 1 : 2;
 if (b && first) { text = &first->text; value = provider->v44(); ((owners::Obj_f79a0 *)text)->FUN_000f79a0((const short *)b, (hulk_intptr)value); }
 if (c && second) { text = &second->text; value = provider->v44(); ((owners::Obj_f79a0 *)text)->FUN_000f79a0((const short *)c, (hulk_intptr)value); }
}
} // namespace fn_000bb970

