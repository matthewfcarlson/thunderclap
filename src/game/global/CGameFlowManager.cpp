// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00089400..0x0008c570 (kind game, layer game, confidence high), dominant class CGameFlowManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f53af43c {
#define TREE_TU_END }
namespace fn_f53af43c {} using namespace fn_f53af43c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f53af43c {
U64 __cdecl lookup_0027b020(int);
struct Entry {
    U64 key;
    char pad[16];
};
int __cdecl FUN_00267760(char* dest, int size, const char* fmt, ...);
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
int __cdecl strncmp(const char*, const char*, unsigned int);
#endif
struct LevelInfo {
};
struct LevelTable {
    LevelInfo* FUN_00086280();
};
} // namespace fn_f53af43c
struct World {
    char pad[0x54];
    LevelTable* levels;
};
namespace fn_f53af43c {
struct LevelAbbrev {
    const char* name;
    const char* abbrev;
};
struct Obj_897e0 {
    char pad[0x20];
};
class Obj_89800 {
  public:
    char pad[0x60];
    char* Get();
};
struct Base_89810 {
};
struct Obj_89810 {
    char pad[0x80];
    void FUN_00089810(hulk_intptr);
};
class Inner_89820 {
  public:
};
class Outer_89820 {
  public:
    char pad[0xa8];
    Inner_89820 inner;
    void Forward(int);
};
class Ret_89830 {
  public:
    void Last_000b7620(bool);
};
class Sub_89830 {
  public:
    int a;
    int b;
};
class Mid_89830 {
  public:
    char pad[0x54];
    Ret_89830* Get();
};
class Root_89830 {
  public:
    char pad[0x54];
    Mid_89830* m;
};
class Manager_89830 {
  public:
    char pad[0xd0];
    Sub_89830 sub;
    void Target(hulk_intptr p);
};
extern Root_89830* hulk_at_004dd700;
struct V {
    int x, y, z;
};
class Obj {
  public:
    char _m_pad_0[0xa8];
    int a;
    volatile int b;
    int c;
    char _m_pad_b4[0x44];
    V v;
    char _m_pad_104[0x8];
    int count;
    int slots[10];
    char _m_pad_138[0x20];
    Entry entries[100];
    int Find(hulk_intptr x);
    V* Get(V* out);
    void Add(int v);
};
class Obj_89910 {
  public:
    char pad[0x104];
    float Value();
};
extern "C" void __cdecl Format(char*, unsigned int, const char*, const char*);
class Obj_89a00 {
  public:
    char pad[0x134];
    void* Get();
};
struct Raw {
    unsigned short a;
    unsigned char b, c, d, e, f, g;
};
extern "C" void __cdecl FUN_00267ad0(Raw*);
struct Out {
    unsigned short v[6];
};
class Target_89ab0 {
    char pad[0xabf];

  public:
    char field;
};
extern "C" int __cdecl FUN_00267760(char*, unsigned int, const char*, ...);
struct Entry_89bf0 { int first, second; char reserved[16]; };
struct State_89bf0 {
 char text0[32], text1[32], text2[32], text3[32];
 int id0, index0; char pad88[32];
 int id1, index1; char padB0[32];
 int id2, index2; char name[32];
 int values[6];
 int handles[10];
 char text4[32];
 Entry_89bf0 entries[100];
 int mode;
 unsigned char flag0, flag1, flag2, flag3;
 int counters[4];
 State_89bf0* FUN_00089bf0();
};
struct Sub_89e10;
struct Root_89e10 {
    char pad[0x54];
    Sub_89e10* sub;
};
extern Root_89e10* g_root;
int fmt_00267760(char* buf, int n, const char* f, ...);
struct R_89e10 {
    void Go_000c3ea0();
};
struct Sub_89e10 {
    R_89e10* Get();
};
class Manager_89e80 {
  public:
};
class Obj_89e80 {
    char pad[0xabd];

  public:
    char flag;
    char other;
    void Init_001d4c90();
    char Fn(Manager_89e80*, char);
};
struct Entry_89f00 {
    __int64 id;
    char name[16];
};
extern "C" __int64 F27b020_0027b020(int s);
extern "C" int F267760_00267760(char* buf, int n, const char* fmt, ...);
class T_89f00 {
  public:
    char pad[0x158];
    Entry_89f00 mE[100];
    int Find_00089400(int k);
    void Set(hulk_intptr k, hulk_intptr s);
    inline int FindFree() {
        for (int i = 0; i < 100; i++) {
            if (mE[i].id == 0)
                return i;
        }
        return -1;
    }
};
struct Session_8a090 {
    bool FUN_001d1cb0();
    bool FUN_001d2ba0(void *item, int a, int b);
    void FUN_001d1d30();
};
struct ThisCall_00089400 {
    int FUN_00089400(void *item);
};
extern "C" Session_8a090 *FUN_001d4c90();
struct Entry_8a090 {
    char data[0x18];
};
class Holder_8a090 {
public:
    char pad000[0x160];
    Entry_8a090 entries[1];
    bool Run(void *item);
};
static inline int memcmp(const char *a, const char *b, unsigned n)
{
    for (; n != 0; n--, a++, b++)
        if (*a != *b)
            return (unsigned char)*a - (unsigned char)*b;
    return 0;
}
struct NameEntry_8a120 {
    unsigned __int64 key;
    char name[16];
};
class LevelRegistry {
public:
    char pad0[0x158];
    NameEntry_8a120 entries[100];
    int FUN_00089400(const char *s);
    void FUN_00089f00(const char *key, const char *value);
    void FUN_0008a120();
};
struct A_8a2b0 {
    char p0[0x80];
    int x;
    char p1[0x84];
    int y;
    char p2[0x9ac];
    int z;
};
struct O {
    char pad[0x80];
    int a;
    int b;
    void* p;
};
class Function_8a390 {
  public:
    virtual void f0();
    virtual void f1();
};
class Function_8a410 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_8a490;
typedef unsigned char(__fastcall* Fn_8a490)(CActorManager_8a490*);
class Dummy_8a510 {
  public:
    void Call(void*);
};
class Dummy_8a590 {
  public:
    void Call(void*);
};
struct Vector_8a610 {
    int x, y, z;
};
class CGameFlowManager_8a610 {
  public:
    virtual Vector_8a610* Get(Vector_8a610*);
};
typedef Vector_8a610* (CGameFlowManager_8a610::*Fn_8a610)(Vector_8a610*);
class CGameFlowManager_8a750 {
  public:
    bool Invoke(const char*);
};
class Function_8a750 {
  public:
    virtual void v0();
    virtual void v1();
};
class CFEManager_8a7e0 {
  public:
    void Call(const char*, int);
};
class Function_8a7e0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CGameFlowManager_8a860;
class CGameFlowManager_8a860 {
  public:
    const char* Get(const char* s);
};
typedef const char* (CGameFlowManager_8a860::*Fn_8a860)(const char*);
struct Function_8a860 {
    virtual void f0();
    virtual void f1();
};
class CActorManager_8a8e0 {
  public:
    void f();
};
typedef unsigned __int64 U64_8ad90;
int __cdecl FUN_00345804(const char*,const char*,int*,int*);
struct Entry_8ad90 { char text[24]; };
struct Obj_8ad90 { char pad[0x160]; Entry_8ad90 entries[1]; int FUN_00089400(const char*); void target(int*,int*); };
class CActorManager_8af10 {
  public:
    int act();
};
class CActorManager_8af90 {
  public:
    int act();
};
class CActorManager_8b010;
typedef unsigned char(__fastcall* Fn_8b010)(CActorManager_8b010*);
class CActorManager_8b0a0 {
  public:
    void invoke(const char*);
};
class CActorManager_8b130 {
  public:
    void invoke(const char*);
};
} // namespace fn_f53af43c
namespace math {
struct Vector_8b1b0 { float x, y, z; };
}
namespace fn_f53af43c {
struct CGameFlowManager_8b1b0 { math::Vector_8b1b0* run(math::Vector_8b1b0* result); };
struct Function_8b1b0 { virtual void vfunc_0(); virtual void vfunc_1(); };
class CActorManager_8b250 {
  public:
    float Get();
};
typedef float (CActorManager_8b250::*Fn_8b250)();
unsigned char Find_001d04d0(const char*);
class Function_8b280 {
  public:
    virtual void Invoke();
    Function_8b280(const char*, int);
    char pad[0xc];
    unsigned char flag2;
    char pad2[7];
    unsigned char flag1;
    char pad3[3];
    void* target;
    void* extra;
};
class Method1_8b280 : public Function_8b280 {
  public:
    virtual void Invoke();
    Method1_8b280(const char* n, void* m) : Function_8b280(n, 1) {
        target = m;
        flag1 = Find_001d04d0(((const char*)&DAT_0048e0e4));
        flag2 = Find_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
class Closure1_8b280 : public Method1_8b280 {
  public:
    virtual void Invoke();
    Closure1_8b280(const char*, void*, void*);
};
class CActorManager_8b390 {
  public:
    void Method(const char*, float);
};
struct Pair_8b390 {
    const char* s;
    float f;
};
struct CGameFlowManager_8b420 {};
struct Function_8b420 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CActorManager_8b4a0 {
  public:
    void run();
};
struct Vec3_8b4b0 {
    int x, y, z;
};
struct Record_8b4b0 {
    char pad0[4];
    char flag;                 // 0x04
    char pad5[7];
    Vec3_8b4b0 pos;                  // 0x0c
    char pad18[0xb68 - 0x18];
    char sub[0xbe8 - 0xb68];   // 0xb68
};
union Slot_8b4b0 {
    char *ptr;
    int value;
};
void __cdecl FUN_000964a0(char *dst, int size, const char *fmt, ...);
class Missions_8b4b0 {
public:
    char pad0[0xabf];
    char complete;             // 0xabf
    char padac0[0xac8 - 0xac0];
    Record_8b4b0 *records;           // 0xac8
    void FUN_0008ad90(int *chapter, int *mission);
    bool FUN_0008b4b0(int index, Slot_8b4b0 out, char *name, int nameSize, Vec3_8b4b0 *pos, void **sub);
};
extern "C" int __cdecl FUN_00345804(const char*, const char*, ...);


// 0x00089400 FUN_00089400 (70 B): matches/0x00089400.cpp
// sym: ?Find@Obj@fn_f53af43c@@QAEHH@Z
int Obj::Find(hulk_intptr x) {
    U64 key = lookup_0027b020(x);
    for (int i = 0; i < 100; ++i) {
        if (!entries[i].key)
            return -1;
        if (key == entries[i].key)
            return i;
    }
    return -1;
}

} // namespace fn_f53af43c

// 0x00089450 FUN_00089450 (89 B): equivalent/0x00089450.cpp [wrapped: conflict: Entry]
// sym: ?FUN_00089450@Obj@fn_00089450@@QAEHXZ
namespace fn_00089450 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00089450 @ 0x00089450
struct Entry { unsigned int first; unsigned int second; char unused[16]; }; struct Obj { char pad[0x158]; Entry entries[100]; int FUN_00089450(); }; int Obj::FUN_00089450() { int count = 0; Entry* entry = entries; for (int group = 0; group < 20; ++group) { for (int slot = 0; slot < 5; ++slot) { if (entry->first == 0 && entry->second == 0) break; ++entry; ++count; } } return count; }
} // namespace fn_00089450


// 0x000895c0 FUN_000895c0 (32 B): matches/0x000895c0.cpp
// sym: ?FUN_000895c0@C_895c0@owners@@QAEXH@Z
void owners::C_895c0::FUN_000895c0(int x) {
    value = x;
    if (x < 0 || 2 < x)
        value = 1;
}


// 0x000895e0 FUN_000895e0 (511 B): equivalent/0x000895e0.cpp
// sym: ?FUN_000895e0@LevelName_895e0@owners@@QAEXPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2056 inputs, branch coverage 18/20, incomplete)
// FUN_000895e0 @ 0x000895e0
void owners::LevelName_895e0::FUN_000895e0(const char* levelName) {
    char* cur = name;
    if (cur && cur[0])
        FUN_00267760(displayName, 0x20, "%s", cur);
    else
        displayName[0] = 0;
    if (levelName == 0) {
        cur[0] = 0;
        shortName[0] = 0;
        return;
    }
    if (!((owners::Table_b4c80 *)(DAT_004dd700->levels->FUN_00086280()))->FUN_000b4c80(levelName))
        return;
    LevelAbbrev table[16] = {
        { "downtown", "dt" },
        { "outskirts", "os" },
        { "industrial", "in" },
        { "sandbox", "sb" },
        { "division_bio_facility", "bf" },
        { "proving_ground", "pg" },
        { "nuclear_power_plant", "pp" },
        { "turning_point", "tp" },
        { "crossroads", "cr" },
        { "the_dam", "dm" },
        { "vault_interior", "vi" },
        { "church", "ch" },
        { "tutorial", "tu" },
        { "banners_cabin", "bc" },
        { "desert_tutorial", "ot" },
        { 0, 0 }
    };
    int len = 0;
    while (levelName[len])
        len++;
    const char* suffix = levelName + len;
    while (*suffix != '_')
        suffix--;
    suffix++;
    for (const LevelAbbrev* e = table; e->name; e++) {
        if (strncmp(e->name, levelName, 4) == 0)
            FUN_00267760(shortName, 0x20, "%s_%s", e->abbrev, suffix);
    }
    if (shortName[0])
        FUN_00267760(cur, 0x20, "%s", levelName);
}

namespace fn_f53af43c {

// 0x000897e0 FUN_000897e0 (4 B): matches/0x000897e0.cpp
// sym: @FUN_000897e0@4
extern "C" void* __fastcall FUN_000897e0(Obj_897e0* p) {
    return (char*)p + 0x20;
}


// 0x000897f0 FUN_000897f0 (4 B): matches/0x000897f0.cpp
// sym: ?FUN_000897f0@fn_f53af43c@@YIPAHPAH@Z
int* __fastcall FUN_000897f0(int* p) {
    return (int*)((char*)p + 0x40);
}


// 0x00089800 FUN_00089800 (4 B): matches/0x00089800.cpp
// sym: ?Get@Obj_89800@fn_f53af43c@@QAEPADXZ
char* Obj_89800::Get() {
    return (char*)this + 0x60;
}


// 0x00089810 FUN_00089810 (11 B): matches/0x00089810.cpp
// sym: ?FUN_00089810@Obj_89810@fn_f53af43c@@QAEXH@Z
void Obj_89810::FUN_00089810(hulk_intptr a0) {
    ((owners::Obj_88fe0 *)(((Base_89810*)((char*)this + 0x80))))->FUN_00088fe0((unsigned int)a0);
}


// 0x00089820 FUN_00089820 (11 B): matches/0x00089820.cpp
// sym: ?Forward@Outer_89820@fn_f53af43c@@QAEXH@Z
void Outer_89820::Forward(int a0) {
    ((owners::Obj_88fe0 *)&inner)->FUN_00088fe0((unsigned int)a0);
}


// 0x00089830 FUN_00089830 (70 B): matches/0x00089830.cpp
// sym: ?Target@Manager_89830@fn_f53af43c@@QAEXH@Z
void Manager_89830::Target(hulk_intptr p) {
    Sub_89830* s = &sub;
    ((owners::Obj_88fe0 *)s)->FUN_00088fe0((unsigned int)p);
    Ret_89830* r = hulk_at_004dd700->m->Get();
    bool f = s->a != -1 && s->b != -1;
    r->Last_000b7620(f);
}

} // namespace fn_f53af43c

// 0x00089880 FUN_00089880 (27 B): matches/0x00089880.cpp
// sym: ?FUN_00089880@C_89880@owners@@QAEXPAI0@Z
void owners::C_89880::FUN_00089880(unsigned* x, unsigned* y) {
    *x = a;
    *y = b;
}


// 0x000898a0 FUN_000898a0 (33 B): matches/0x000898a0.cpp
// sym: ?FUN_000898a0@Obj_898a0@owners@@QAEXIII@Z
void owners::Obj_898a0::FUN_000898a0(unsigned int x, unsigned int y, unsigned int z) {
    a = x;
    b = y;
    c = z;
}

namespace fn_f53af43c {

// 0x000898d0 FUN_000898d0 (33 B): matches/0x000898d0.cpp
// sym: ?Get@Obj@fn_f53af43c@@QAEPAUV@2@PAU32@@Z
V* Obj::Get(V* out) {
    *out = v;
    return out;
}

} // namespace fn_f53af43c

// 0x00089900 FUN_00089900 (13 B): matches/0x00089900.cpp
// sym: ?FUN_00089900@Target_89900@owners@@QAEXH@Z
void owners::Target_89900::FUN_00089900(int x) {
    value = x;
}

namespace fn_f53af43c {

// 0x00089910 FUN_00089910 (7 B): matches/0x00089910.cpp
// sym: ?Value@Obj_89910@fn_f53af43c@@QAEMXZ
float Obj_89910::Value() {
    return *(float*)((char*)this + 0x104);
}


// 0x00089920 FUN_00089920 (45 B): matches/0x00089920.cpp
// sym: ?Add@Obj@fn_f53af43c@@QAEXH@Z
void Obj::Add(int v) {
    for (int i = 0; i < 10; ++i) {
        if (slots[i] == -1) {
            ++count;
            slots[i] = v;
            return;
        }
    }
}

} // namespace fn_f53af43c

// 0x00089950 FUN_00089950 (7 B): matches/0x00089950.cpp
// sym: ?FUN_00089950@C_89950@owners@@QAEIXZ
unsigned int owners::C_89950::FUN_00089950() {
    return value;
}


// 0x00089960 FUN_00089960 (29 B): matches/0x00089960.cpp
// sym: ?FUN_00089960@C_89960@owners@@QAEHH@Z
int owners::C_89960::FUN_00089960(int index) {
    if (index >= 0 && index < 10)
        return values[index];
    return -1;
}


// 0x00089980 FUN_00089980 (74 B): matches/0x00089980.cpp
// sym: ?FUN_00089980@Obj_89980@owners@@QAEXXZ
void owners::Obj_89980::FUN_00089980() {
    fields[0] = -1;
    fields[1] = -1;
    fields[2] = -1;
    fields[3] = -1;
    fields[4] = -1;
    fields[5] = -1;
    fields[6] = -1;
    fields[7] = -1;
    fields[8] = -1;
    fields[9] = -1;
    field10c = 0;
}


// 0x000899d0 FUN_000899d0 (34 B): matches/0x000899d0.cpp
// sym: ?FUN_000899d0@Obj_899d0@owners@@QAEXPBD@Z
void owners::Obj_899d0::FUN_000899d0(const char* p) {
    if (p)
        Format(pad, 0x20, "%s", p);
}

namespace fn_f53af43c {

// 0x00089a00 FUN_00089a00 (7 B): matches/0x00089a00.cpp
// sym: ?Get@Obj_89a00@fn_f53af43c@@QAEPAXXZ
void* Obj_89a00::Get() {
    return (void*)((char*)this + 0x138);
}

} // namespace fn_f53af43c

// 0x00089a10 FUN_00089a10 (7 B): matches/0x00089a10.cpp
// sym: ?FUN_00089a10@C_89a10@owners@@QAEEXZ
unsigned char owners::C_89a10::FUN_00089a10() {
    return x;
}


// 0x00089a20 FUN_00089a20 (13 B): matches/0x00089a20.cpp
// sym: ?FUN_00089a20@C_89a20@owners@@QAEXE@Z
void owners::C_89a20::FUN_00089a20(unsigned char x) {
    value = x;
}


// 0x00089a30 FUN_00089a30 (13 B): matches/0x00089a30.cpp
// sym: ?FUN_00089a30@Target_89a30@owners@@QAEXE@Z
void owners::Target_89a30::FUN_00089a30(unsigned char value) {
    *((unsigned char*)this + 0xabd) = value;
}


// 0x00089a40 FUN_00089a40 (7 B): matches/0x00089a40.cpp
// sym: ?FUN_00089a40@Target_89a40@owners@@QAEEXZ
unsigned char owners::Target_89a40::FUN_00089a40() {
    return value;
}


// 0x00089a50 FUN_00089a50 (7 B): matches/0x00089a50.cpp
// sym: ?FUN_00089a50@Obj_89a50@owners@@QAEHXZ
hulk_intptr owners::Obj_89a50::FUN_00089a50() {
    return value;
}

namespace fn_f53af43c {

// 0x00089a60 FUN_00089a60 (80 B): matches/0x00089a60.cpp
// sym: ?FUN_00089a60@fn_f53af43c@@YGXPAUOut@1@@Z
void __stdcall FUN_00089a60(Out* p) {
    Raw x;
    FUN_00267ad0(&x);
    p->v[0] = x.a;
    p->v[1] = x.b;
    p->v[2] = x.c;
    p->v[3] = x.d;
    p->v[4] = x.e;
    p->v[5] = x.f;
}


// 0x00089ab0 FUN_00089ab0 (8 B): matches/0x00089ab0.cpp
// sym: @FUN_00089ab0@4
extern "C" void __fastcall FUN_00089ab0(Target_89ab0* self) {
    self->field = 1;
}


// 0x00089bf0 FUN_00089bf0 (306 B): equivalent/0x00089bf0.cpp
// sym: ?FUN_00089bf0@State_89bf0@fn_f53af43c@@QAEPAU12@XZ
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00089bf0 @ 0x00089bf0
State_89bf0* State_89bf0::FUN_00089bf0() {
 id0 = index0 = -1;
 id1 = index1 = -1;
 id2 = index2 = -1;
 values[0] = values[1] = values[2] = 0;
 mode = 1;
 flag1 = 1;
 values[3] = values[4] = values[5] = 0;
 flag0 = flag2 = flag3 = 0;
 counters[0] = counters[1] = counters[2] = counters[3] = 0;
 text0[0] = text1[0] = text3[0] = text2[0] = text4[0] = 0;
 index0 = id0 = -1;
 index1 = id1 = -1;
 index2 = 1;
 id2 = 0;
 FUN_00267760(name, 32, "c%02dm%02d", 0, 1);
 for (int i = 0; i < 10; ++i) handles[i] = -1;
 for (int j = 0; j < 100; ++j) {
 entries[j].first = 0;
 entries[j].second = 0;
 }
 return this;
}

} // namespace fn_f53af43c

// 0x00089d30 FUN_00089d30 (213 B): equivalent/0x00089d30.cpp [wrapped: conflict: FUN_00267760; World]
// sym: ?FUN_00089d30@Target_89d30@fn_00089d30@@QAEXXZ
namespace fn_00089d30 {
// STATUS: equivalent (tools/equiv.py level 3: 141 inputs, branch coverage 4/4)
// FUN_00089d30 @ 0x00089d30
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

struct Control_89d30 { void FUN_00090130(int); };
struct Entries_89d30 { void FUN_00093600(int,int); void FUN_00092870(int,float); void FUN_000929a0(int,float); };
struct Final_89d30 { void FUN_000c3ea0(); };
struct Manager_89d30 { Control_89d30* FUN_00086370(); Entries_89d30* FUN_00086340(); Final_89d30* FUN_00086280(); };
struct World { char pad[0x54]; Manager_89d30* manager; };
extern "C++" __declspec(nothrow) void __cdecl FUN_00267760(char*,int,const char*,...);
struct Item_89d30 { int first,second; char pad[16]; };
struct Target_89d30 {
 char p0[0x80]; int f80,f84; char p88[0x20]; int fa8,fac; char pb0[0x20]; int fd0,fd4; char name[0x20]; char pf8[0x60]; Item_89d30 items[100]; char pab8[7]; unsigned char flag;
 void FUN_00089d30();
};
void Target_89d30::FUN_00089d30() {
 Manager_89d30* manager=DAT_004dd700->manager;
 fd0=0; fd4=1;
 FUN_00267760(name,32,"c%02dm%02d",0,1);
 flag=0; f84=-1; f80=-1; fac=-1; fa8=-1;
 manager->FUN_00086370()->FUN_00090130(0);
 Entries_89d30* entries=manager->FUN_00086340();
 for(int i=0;i<0x2fe;++i) { entries->FUN_00093600(i,1); entries->FUN_00092870(i,0.0f); entries->FUN_000929a0(i,0.0f); }
 for(int j=0;j<100;++j) { items[j].first=0; items[j].second=0; }
 manager->FUN_00086280()->FUN_000c3ea0();
}
} // namespace fn_00089d30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00089e10 FUN_00089e10 (108 B): matches/0x00089e10.cpp
// sym: ?FUN_00089e10@W_89e10@owners@@QAEXXZ
void owners::W_89e10::FUN_00089e10() {
    Sub_89e10* s = g_root->sub;
    d0 = 0;
    d4 = 1;
    fmt_00267760(d8, 0x20, "c%02dm%02d", 0, 1);
    int* q = &i80;
    i84 = -1;
    *q = -1;
    iac = -1;
    ia8 = -1;
    P();
    s->Get()->Go_000c3ea0();
}

namespace fn_f53af43c {

// 0x00089e80 FUN_00089e80 (115 B): matches/0x00089e80.cpp
// sym: ?Fn@Obj_89e80@fn_f53af43c@@QAEDPAVManager_89e80@2@D@Z
char Obj_89e80::Fn(Manager_89e80* m, char param) {
    Init_001d4c90();
    char r = 0;
    int x = ((int)((::CScenarioManager *)m)->FUN_001cc840());
    if (x == 2) {
        flag = 0;
        r = 1;
    } else if (x == 5) {
        flag = 1;
        r = 1;
    } else if (x == 3) {
        flag = (other == 0);
        ((::CScenarioManager *)m)->FUN_001cc620(4);
    }
    x = ((int)((::CScenarioManager *)m)->FUN_001cc840());
    if (x == 4 && param)
        return 1;
    return r;
}


// 0x00089f00 FUN_00089f00 (114 B): matches/0x00089f00.cpp
// sym: ?Set@T_89f00@fn_f53af43c@@QAEXHH@Z
void T_89f00::Set(hulk_intptr k, hulk_intptr s) {
    int i = Find_00089400(k);
    if (i == -1)
        i = FindFree();
    if (i == -1)
        return;
    char* b = (char*)this + i * 0x18;
    *(__int64*)(b + 0x158) = F27b020_0027b020(k);
    F267760_00267760(b + 0x160, 0x10, "%s", s);
}

} // namespace fn_f53af43c

// 0x0008a060 FUN_0008a060 (41 B): matches/0x0008a060.cpp
// sym: ?FUN_0008a060@Obj_8a060@owners@@QAEPADH@Z
// data: gZero_8a060 = DAT_003f335c
char* owners::Obj_8a060::FUN_0008a060(hulk_intptr arg) {
    int i = Find(((int)arg));
    if (i == -1)
        return (char*)&(*(float*)&DAT_003f335c);
    return (char*)this + 0x160 + i * 0x18;
}

namespace fn_f53af43c {

// 0x0008a090 FUN_0008a090 (133 B): equivalent/0x0008a090.cpp
// sym: ?Run@Holder_8a090@fn_f53af43c@@QAE_NPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 8/8)
// FUN_0008a090 @ 0x0008a090
// FUN_0008a090 @ 0x0008a090
bool Holder_8a090::Run(void *item)
{
    int index = ((ThisCall_00089400*)(this))->FUN_00089400(item);
    if (index == -1)
        return false;
    Session_8a090 *s = FUN_001d4c90();
    if (s != 0 && s->FUN_001d1cb0()) {
        if (!s->FUN_001d2ba0(item, 0, 1)) {
            s->FUN_001d1d30();
            return false;
        }
        ((owners::Thing_1d1d50 *)s)->FUN_001d1d50((hulk_uintptr)"info", (hulk_uintptr)(&entries[index]));
        ((owners::Obj_1d19d0 *)s)->FUN_001d19d0(1);
        s->FUN_001d1d30();
        return true;
    }
    return false;
}


// 0x0008a120 FUN_0008a120 (398 B): equivalent/0x0008a120.cpp
// sym: ?FUN_0008a120@LevelRegistry@fn_f53af43c@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 7048 inputs, branch coverage 34/38, incomplete)
// FUN_0008a120 @ 0x0008a120
// MSVC expands memcmp against a string literal inline (repe cmpsb)
void LevelRegistry::FUN_0008a120()
{
    const char *seen = 0;
    int i;
    int k;
    for (i = 34; i >= 0; i--) {
        const char *s = ((const char**)&DAT_003ffde0)[i];
        unsigned __int64 h = FUN_0027b020(s);
        const char *name = ((const char*)&DAT_003f335c);
        for (k = 0; k < 100; k++) {
            if (entries[k].key == 0)
                break;
            if (entries[k].key == h) {
                name = entries[k].name;
                break;
            }
        }
        if (seen == 0) {
            if (memcmp(name, "complete", 9) == 0)
                seen = s;
        } else {
            if (memcmp(name, "complete", 9) != 0)
                FUN_00089f00(s, "complete");
        }
    }

    unsigned __int64 h = FUN_0027b020("c06m03");
    const char *name = ((const char*)&DAT_003f335c);
    for (k = 0; k < 100; k++) {
        if (entries[k].key == 0)
            break;
        if (entries[k].key == h) {
            name = entries[k].name;
            break;
        }
    }
    if (name[0] == 0) {
        int idx = FUN_00089400("c06m02");
        const char *n2 = ((const char*)&DAT_003f335c);
        if (idx != -1)
            n2 = entries[idx].name;
        if (n2[0] != 0)
            FUN_00089f00("c06m03", "locked");
    }
}


// 0x0008a2b0 FUN_0008a2b0 (32 B): matches/0x0008a2b0.cpp
// sym: @FUN_0008a2b0@4
extern "C" int __fastcall FUN_0008a2b0(A_8a2b0* a) {
    int v = a->z;
    if (v == 1 && a->x < 10 && a->y > 4)
        v = 0;
    return v;
}


// 0x0008a2d0 FUN_0008a2d0 (31 B): matches/0x0008a2d0.cpp
// sym: @FUN_0008a2d0@4
extern "C" void* __fastcall FUN_0008a2d0(O* self) {
    if (self->a == -1)
        return 0;
    if (self->b == -1)
        return 0;
    return (char*)&self->p;
}


// 0x0008a2f0 FUN_0008a2f0 (31 B): matches/0x0008a2f0.cpp
// sym: ?FUN_0008a2f0@fn_f53af43c@@YIPAHPAVObj@1@@Z
int* __fastcall FUN_0008a2f0(Obj* p) {
    if (p->a == -1)
        return 0;
    if (p->b == -1)
        return 0;
    return &p->c;
}

} // namespace fn_f53af43c

// 0x0008a310 FUN_0008a310 (31 B): matches/0x0008a310.cpp
// sym: ?FUN_0008a310@C_8a310@owners@@QAEPAHXZ
int* owners::C_8a310::FUN_0008a310() {
    if (a == -1)
        return 0;
    if (b == -1)
        return 0;
    return (int*)((char*)this + 0xd8);
}


// 0x0008a370 Method0<CGameFlowManager,int>::vfunc_0 (30 B): matches/0x0008a370.cpp
// sym: ??_G?$Method0@VCGameFlowManager@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CGameFlowManager, int>::~Method0() {}


// 0x0008a390 Method0<CGameFlowManager,int>::vfunc_2 (22 B): matches/0x0008a390.cpp
// sym: ?vfunc_2@?$Method0@VCGameFlowManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
template <> void Method0<CGameFlowManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)this + 0x1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}


// 0x0008a3f0 Method0<CGameFlowManager,const_char_*>::vfunc_0 (30 B): matches/0x0008a3f0.cpp
// sym: ??_G?$Method0@VCGameFlowManager@@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CGameFlowManager, const char *>::~Method0() {}


// 0x0008a410 Method0<CGameFlowManager,const_char_*>::vfunc_2 (22 B): matches/0x0008a410.cpp
// sym: ?vfunc_2@?$Method0@VCGameFlowManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
template <> void Method0<CGameFlowManager, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)this + 0x1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}


// 0x0008a470 Method0<CGameFlowManager,bool>::vfunc_0 (30 B): matches/0x0008a470.cpp
// sym: ??_G?$Method0@VCGameFlowManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CGameFlowManager, bool>::~Method0() {}


// 0x0008a490 Method0<CGameFlowManager,bool>::vfunc_2 (22 B): matches/0x0008a490.cpp
// sym: ?vfunc_2@?$Method0@VCGameFlowManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002d750 (propagated; names are from that function)
template <> void Method0<CGameFlowManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_8a490 * obj = (CActorManager_8a490 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_8a490 fn = (*(Fn_8a490 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}


// 0x0008a4f0 Method1<CGameFlowManager,void,int>::vfunc_0 (30 B): matches/0x0008a4f0.cpp
// sym: ??_G?$Method1@VCGameFlowManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CGameFlowManager, void, int>::~Method1() {}


// 0x0008a510 Method1<CGameFlowManager,void,int>::vfunc_2 (19 B): matches/0x0008a510.cpp
// sym: ?vfunc_2@?$Method1@VCGameFlowManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CGameFlowManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_8a510* d = (Dummy_8a510*)a;
    (d->*(*(void (Dummy_8a510::**)(void *))&this->f_1c))(*b);
}


// 0x0008a570 Method1<CGameFlowManager,void,const_char_*>::vfunc_0 (30 B): matches/0x0008a570.cpp
// sym: ??_G?$Method1@VCGameFlowManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CGameFlowManager, void, const char *>::~Method1() {}


// 0x0008a590 Method1<CGameFlowManager,void,const_char_*>::vfunc_2 (19 B): matches/0x0008a590.cpp
// sym: ?vfunc_2@?$Method1@VCGameFlowManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CGameFlowManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_8a590* d = (Dummy_8a590*)a;
    (d->*(*(void (Dummy_8a590::**)(void *))&this->f_1c))(*b);
}


// 0x0008a5f0 Method0<CGameFlowManager,math::Vector>::vfunc_0 (30 B): matches/0x0008a5f0.cpp
// sym: ??_G?$Method0@VCGameFlowManager@@VVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CGameFlowManager,math::Vector>::~Method0() {}


// 0x0008a610 Method0<CGameFlowManager,math::Vector>::vfunc_2 (69 B): matches/0x0008a610.cpp
// sym: ?vfunc_2@?$Method0@VCGameFlowManager@@VVector@math@@@@UAEXPAX00@Z
template <> void Method0<CGameFlowManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CGameFlowManager_8a610 * mgr = (CGameFlowManager_8a610 *)__p0; Vector_8a610 * out = (Vector_8a610 *)__p2;

    Fn_8a610 fn = (*(Fn_8a610 *)&this->f_1c);
    Vector_8a610 temp;
    volatile Vector_8a610 r;
    Vector_8a610* p = (mgr->*fn)(&temp);
    r.x = p->x;
    r.y = p->y;
    r.z = p->z;
    if (out) {
        out->x = r.x;
        out->y = r.y;
        out->z = r.z;
    }
}


// 0x0008a6a0 Method0<CGameFlowManager,float>::vfunc_0 (30 B): matches/0x0008a6a0.cpp
// sym: ??_G?$Method0@VCGameFlowManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CGameFlowManager, float>::~Method0() {}


// 0x0008a6c0 Method0<CGameFlowManager,float>::vfunc_2 (34 B): matches/0x0008a6c0.cpp [wrapped: conflict: Function]
// sym: ?f2@Method0Base_8a6c0@fn_0008a6c0@@UAEXPAX0PAM@Z
namespace fn_0008a6c0 {
// Same code shape as 0x0002e080 (propagated; names are from that function)
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method0Base_8a6c0 : public Function {
  public:
    char pad[0x18];
    float(__fastcall* fn)(void*);
    virtual void f2(void* a, void* b, float* out);
};
void Method0Base_8a6c0::f2(void* a, void* b, float* out) {
    float(__fastcall * f)(void*) = fn;
    float value = f(a);
    if (out)
        *out = value;
}
} // namespace fn_0008a6c0


// 0x0008a730 Method1<CGameFlowManager,bool,const_char_*>::vfunc_0 (30 B): matches/0x0008a730.cpp
// sym: ??_G?$Method1@VCGameFlowManager@@_NPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CGameFlowManager, bool, const char *>::~Method1() {}


// 0x0008a750 Method1<CGameFlowManager,bool,const_char_*>::vfunc_2 (29 B): matches/0x0008a750.cpp
// sym: ?vfunc_2@?$Method1@VCGameFlowManager@@_NPBD@@UAEXPAX00@Z
template <> void Method1<CGameFlowManager, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CGameFlowManager_8a750 * obj = (CGameFlowManager_8a750 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CGameFlowManager_8a750::*f)(const char*) = (*(bool (CGameFlowManager_8a750::**)(const char *))&this->f_1c);
    const char* value = *arg;
    bool r = (obj->*f)(value);
    if (out)
        *out = r;
}


// 0x0008a7c0 Method2<CGameFlowManager,void,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0008a7c0.cpp
// sym: ??_G?$Method2@VCGameFlowManager@@XPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CGameFlowManager, void, const char *, const char *>::~Method2() {}


// 0x0008a7e0 Method2<CGameFlowManager,void,const_char_*,const_char_*>::vfunc_2 (23 B): matches/0x0008a7e0.cpp
// sym: ?vfunc_2@?$Method2@VCGameFlowManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CGameFlowManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_8a7e0* m = (CFEManager_8a7e0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_8a7e0::**)(const char *, int))&this->f_1c))(s, x);
}


// 0x0008a840 Method1<CGameFlowManager,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0008a840.cpp
// sym: ??_G?$Method1@VCGameFlowManager@@PBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CGameFlowManager, const char *, const char *>::~Method1() {}


// 0x0008a860 Method1<CGameFlowManager,const_char_*,const_char_*>::vfunc_2 (29 B): matches/0x0008a860.cpp
// sym: ?vfunc_2@?$Method1@VCGameFlowManager@@PBDPBD@@UAEXPAX00@Z
template <> void Method1<CGameFlowManager, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CGameFlowManager_8a860 * a = (CGameFlowManager_8a860 *)__p0; const char ** p = (const char **)__p1; const char ** out = (const char **)__p2;

    Fn_8a860 f = (*(Fn_8a860 *)&this->f_1c);
    const char* s = *p;
    const char* x = (a->*f)(s);
    if (out)
        *out = x;
}


// 0x0008a8c0 Method0<CGameFlowManager,void>::vfunc_0 (30 B): matches/0x0008a8c0.cpp
// sym: ??_G?$Method0@VCGameFlowManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CGameFlowManager, void>::~Method0() {}


// 0x0008a8e0 Method0<CGameFlowManager,void>::vfunc_2 (12 B): matches/0x0008a8e0.cpp
// sym: ?vfunc_2@?$Method0@VCGameFlowManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<CGameFlowManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_8a8e0 * a = (CActorManager_8a8e0 *)__p0;

    (a->*(*(void (CActorManager_8a8e0::**)())&this->f_1c))();
}


// 0x0008a8f0 FUN_0008a8f0 (706 B): equivalent/0x0008a8f0.cpp [wrapped: conflict: DAT_004dd6ec; World]
// sym: ?FUN_0008a8f0@Game_8a8f0@fn_0008a8f0@@QAE_NHPAUWorld@2@@Z
namespace fn_0008a8f0 {
// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 26/28, incomplete)
// FUN_0008a8f0 @ 0x0008a8f0

extern "C++" __declspec(nothrow) int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
void __cdecl FUN_00035db0(int v);

struct Bag_8a8f0 {
    void FUN_001eb870();
    void FUN_001eb890();
    void FUN_001eb9e0(int v);
    void FUN_001eba30(int v);
    void FUN_001eba80(int v);
    void FUN_001ebad0(int v);
};

struct FlagObj {
    char pad0[0xc];
    char flag;
    void FUN_001be490();
};

struct Opt1 { void FUN_000ae930(int v); };
struct Opt2 { void FUN_000afe10(bool v); };
struct Bits_8a8f0 {
    void FUN_00093600(int i, bool v);
    void FUN_00092870(int i, bool v);
    void FUN_000929a0(int i, int v);
};
struct Pool_8a8f0 { void FUN_000901d0(int i, int v); };
struct Pair_8a8f0 {
    void FUN_000b46c0();
    void FUN_000c3ea0();
};

struct World {
    Bag_8a8f0 *FUN_000862e0();
    Opt1 *FUN_000862c0();
    Opt2 *FUN_00086330();
    Bits_8a8f0 *FUN_00086340();
    Pool_8a8f0 *FUN_00086370();
    Pair_8a8f0 *FUN_00086280();
    FlagObj *FUN_00086380();
};

#define DAT_004dd6ec (*(World * *)&::DAT_004dd6ec)


struct Rec24_8a8f0 {
    int a, b, c, d, e, f;
};

struct Level_8a8f0 {
    char pad0[0x18];
    unsigned char b18;
    unsigned char b19;
    unsigned char b1a;
    char pad1b;
    int f1c;
    int f20;
    int f24;
    unsigned char b28;
    unsigned char b29;
    unsigned char b2a;
    unsigned char b2b;
    unsigned char b2c;
    char pad2d[7];
    unsigned char b34;
    unsigned char b35;
    unsigned char b36;
    char pad37;
    int bits1[32];      // 0x38
    int bits2[32];      // 0xb8
    Rec24_8a8f0 recs[100];    // 0x138
    int arr[51];        // 0xa98
    int count;          // 0xb64
    char padb68[0xbe8 - 0xb68];
};

class Game_8a8f0 {
public:
    char pad0[0x80];
    int f80;
    int f84;
    char pad88[0x20];
    int fa8;
    int fac;
    char padb0[0x20];
    int fd0;
    int fd4;
    char name[0x20];
    char padf8[0x60];
    Rec24_8a8f0 recs[100];    // 0x158
    int fab8;
    char padabc[3];
    char babf;
    char pad_ac0[8];
    Level_8a8f0 *table;       // 0xac8
    bool FUN_0008a8f0(int idx, World *w);
    void FUN_0008a120();
};

bool Game_8a8f0::FUN_0008a8f0(int idx, World *w)
{
    DAT_004dd6ec->FUN_000862e0()->FUN_001eb870();
    Level_8a8f0 *lv = &table[idx];
    fd4 = lv->b19;
    fd0 = lv->b18;
    FUN_00267760(name, 0x20, "c%02dm%02d", lv->b18, lv->b19);
    babf = lv->b1a;
    f84 = -1;
    f80 = -1;
    fac = -1;
    fa8 = -1;
    w->FUN_000862e0()->FUN_001eb9e0(lv->f1c);
    w->FUN_000862e0()->FUN_001eba30(lv->f20);
    w->FUN_000862e0()->FUN_001eba80(lv->f24);
    bool f = lv->b29 != 0;
    FlagObj *fo = w->FUN_00086380();
    if (fo->flag != f)
        fo->FUN_001be490();
    fo->flag = f;
    w->FUN_000862e0()->FUN_001ebad0(lv->b28);
    FUN_00035db0(lv->b34);
    DAT_004dd83a = lv->b35;
    DAT_004dd83b = lv->b36;
    w->FUN_000862c0()->FUN_000ae930(lv->b2b);
    w->FUN_00086330()->FUN_000afe10(lv->b2a != 0);
    fab8 = lv->b2c;
    if (fab8 < 0 || fab8 > 2)
        fab8 = 1;
    Bits_8a8f0 *bits = w->FUN_00086340();
    for (int i = 0; i < 0x2fe; i++) {
        bits->FUN_00093600(i, 1);
        bits->FUN_00092870(i, 0);
    }
    for (int i = 0; i < 0x2fe; i++) {
        unsigned int mask = 1 << (i % 32);
        bits->FUN_00093600(i, (mask & lv->bits1[i / 32]) != 0);
        bits->FUN_00092870(i, (mask & lv->bits2[i / 32]) != 0);
    }
    for (int i = 0; i < 0x2fe; i++)
        bits->FUN_000929a0(i, 0);
    Pool_8a8f0 *pool = w->FUN_00086370();
    for (int i = 0; i < lv->count; i++)
        pool->FUN_000901d0(i, lv->arr[i]);
    for (int k = 0; k < 100; k++) {
        recs[k].a = lv->recs[k].a;
        recs[k].b = lv->recs[k].b;
        recs[k].c = lv->recs[k].c;
        recs[k].d = lv->recs[k].d;
        recs[k].e = lv->recs[k].e;
        recs[k].f = lv->recs[k].f;
    }
    FUN_0008a120();
    w->FUN_00086280()->FUN_000b46c0();
    w->FUN_00086280()->FUN_000c3ea0();
    DAT_004dd6ec->FUN_000862e0()->FUN_001eb890();
    return true;
}
} // namespace fn_0008a8f0
#undef DAT_004dd6ec


// 0x0008abc0 FUN_0008abc0 (459 B): equivalent/0x0008abc0.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_0008abc0@Profile_8abc0@fn_0008abc0@@QAEPBDXZ
namespace fn_0008abc0 {
// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 45/50, incomplete)
// FUN_0008abc0 @ 0x0008abc0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int strcmp(const char*, const char*);
#endif

unsigned __int64 __cdecl FUN_0027b020(const char* s) throw();


struct Entry_8abc0 {
    unsigned __int64 id;
    char name[0x10];
};

class Profile_8abc0 {
public:
    char pad00[0xd0];
    int curLo;
    int curHi;
    char curName[0x80];
    Entry_8abc0 entries[100];
    const char* FUN_0008abc0();
};

const char* Profile_8abc0::FUN_0008abc0()
{
    static unsigned __int64 hashComplete = FUN_0027b020("complete");
    static unsigned __int64 hashLocked = FUN_0027b020("locked");
    int bestIndex = -1;
    const char* bestName = "";
    for (int i = 0; i < 0x23; i++) {
        const char* name = ((const char**)&DAT_003ffde0)[i];
        unsigned __int64 h = FUN_0027b020(name);
        const char* s = "";
        for (int k = 0; k < 100; k++) {
            if (entries[k].id == 0)
                break;
            if (entries[k].id == h) {
                s = entries[k].name;
                break;
            }
        }
        unsigned __int64 state = FUN_0027b020(s);
        if (state == 0 || state == hashComplete || state == hashLocked)
            continue;
        bestIndex = i;
        bestName = name;
        break;
    }
    const char* cur;
    if (curLo == -1 || curHi == -1)
        cur = 0;
    else
        cur = curName;
    int found = -1;
    if (cur != 0 && strcmp(cur, "") != 0) {
        for (int j = 0; j < 0x23; j++) {
            if (strcmp(((const char**)&DAT_003ffde0)[j], cur) == 0) {
                found = j;
                break;
            }
        }
    }
    if (bestIndex < found)
        return cur;
    return bestName;
}
} // namespace fn_0008abc0

namespace fn_f53af43c {

// 0x0008ad90 FUN_0008ad90 (273 B): equivalent/0x0008ad90.cpp
// sym: ?target@Obj_8ad90@fn_f53af43c@@QAEXPAH0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 16/18, incomplete)
// FUN_0008ad90 @ 0x0008ad90
void Obj_8ad90::target(int* a,int* b) {
 if (!((*(unsigned*)&DAT_004dd730) & 1)) { (*(unsigned*)&DAT_004dd730) |= 1; (*(U64_8ad90*)&DAT_004dd728)=FUN_0027b020("complete"); }
 *a=0; *b=0;
 int index=FUN_00089400("c00m01");
 const char* s=index==-1 ? "" : entries[index].text;
 if (*s==0) { FUN_00345804("c00m01","c%dm%d",a,b); return; }
 for(int i=0;i<35;++i) {
 const char* name=((const char**)&DAT_003ffde0)[i];
 index=FUN_00089400(name);
 s=index==-1 ? "" : entries[index].text;
 if(s) { U64_8ad90 v=FUN_0027b020(s); if(v && v!=(*(U64_8ad90*)&DAT_004dd728)) {FUN_00345804(name,"c%dm%d",a,b);return;} }
 }
}

} // namespace fn_f53af43c

// 0x0008aef0 Closure0<CGameFlowManager,int>::vfunc_0 (30 B): matches/0x0008aef0.cpp
// sym: ??_G?$Method0@VCGameFlowManager@@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CGameFlowManager, int>::~Closure0() {}


// 0x0008af10 Closure0<CGameFlowManager,int>::vfunc_2 (23 B): matches/0x0008af10.cpp
// sym: ?vfunc_2@?$Closure0@VCGameFlowManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
template <> void Closure0<CGameFlowManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_8af10* obj = (*(CActorManager_8af10 * *)&this->f_20);
    int (CActorManager_8af10::*fn)() = (*(int (CActorManager_8af10::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}


// 0x0008af70 Closure0<CGameFlowManager,const_char_*>::vfunc_0 (30 B): matches/0x0008af70.cpp
// sym: ??_G?$Method0@VCGameFlowManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CGameFlowManager, const char *>::~Closure0() {}


// 0x0008af90 Closure0<CGameFlowManager,const_char_*>::vfunc_2 (23 B): matches/0x0008af90.cpp
// sym: ?vfunc_2@?$Closure0@VCGameFlowManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
template <> void Closure0<CGameFlowManager, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_8af90* obj = (*(CActorManager_8af90 * *)&this->f_20);
    int (CActorManager_8af90::*fn)() = (*(int (CActorManager_8af90::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}


// 0x0008aff0 Closure0<CGameFlowManager,bool>::vfunc_0 (30 B): matches/0x0008aff0.cpp
// sym: ??_G?$Method1@VCGameFlowManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CGameFlowManager, bool>::~Closure0() {}


// 0x0008b010 Closure0<CGameFlowManager,bool>::vfunc_2 (23 B): matches/0x0008b010.cpp
// sym: ?vfunc_2@?$Closure0@VCGameFlowManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002f6a0 (propagated; names are from that function)
template <> void Closure0<CGameFlowManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_8b010* o = (*(CActorManager_8b010 * *)&this->f_20);
    Fn_8b010 fn = (*(Fn_8b010 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}


// 0x0008b030 FUN_0008b030 (76 B): matches/0x0008b030.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_0008b030@@QAE@PAVCGameFlowManager@1@HH@Z
namespace fn_0008b030 {
// data: key1 = DAT_0048e100, key2 = DAT_0048e134

extern "C++" __declspec(nothrow) unsigned char __cdecl getFlag_001d04d0(const char*);
class CGameFlowManager;
class Base {
  public:
    virtual void f();
    Base(CGameFlowManager*, int);
    char pad[0xc];
    unsigned char b;
    char pad2[7];
    unsigned char a;
    char pad3[3];
    int val;
};
class Closure1_8b030 : public Base {
  public:
    virtual void f();
    Closure1_8b030(CGameFlowManager*, int);
};
class Closure1 : public Closure1_8b030 {
  public:
    virtual void f();
    int extra;
    Closure1(CGameFlowManager*, int, int);
};
Closure1_8b030::Closure1_8b030(CGameFlowManager* p, int x) : Base(p, 1) {
    val = x;
    a = getFlag_001d04d0(((const char*)&DAT_0048e100));
    b = getFlag_001d04d0(((const char*)&DAT_0048e134));
}
Closure1::Closure1(CGameFlowManager* p, int x, int y) : Closure1_8b030(p, y) {
    extra = x;
}
} // namespace fn_0008b030


// 0x0008b080 Closure1<CGameFlowManager,void,int>::vfunc_0 (30 B): matches/0x0008b080.cpp
// sym: ??_G?$Method0@VCGameFlowManager@@VVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CGameFlowManager, void, int>::~Closure1() {}


// 0x0008b0a0 Closure1<CGameFlowManager,void,int>::vfunc_2 (18 B): matches/0x0008b0a0.cpp
// sym: ?vfunc_2@?$Closure1@VCGameFlowManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CGameFlowManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_8b0a0 * *)&this->f_20)->*(*(void (CActorManager_8b0a0::**)(const char *))&this->f_1c))(*b);
}


// 0x0008b0c0 FUN_0008b0c0 (76 B): matches/0x0008b0c0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1_8b0c0@fn_0008b0c0@@QAE@PBDHH@Z
namespace fn_0008b0c0 {

int GetValue_001d04d0(int*);
class Base {
  public:
    Base(const char*, int);
    virtual void Run();
    char pad[12];
};
class Method : public Base {
  public:
    Method(const char*, int);
    virtual void Run();
    char a;
    char pad3[7];
    char b;
    char pad4[3];
    int value;
};
class Closure1_8b0c0 : public Method {
  public:
    Closure1_8b0c0(const char*, int, int);
    virtual void Run();
    int extra;
};
Method::Method(const char* name, int v) : Base(name, 1) {
    value = v;
    b = GetValue_001d04d0(((int*)&DAT_0048e100));
    a = GetValue_001d04d0(((int*)&DAT_0048e0f0));
}
Closure1_8b0c0::Closure1_8b0c0(const char* name, int v, int w) : Method(name, w) {
    extra = v;
}
} // namespace fn_0008b0c0


// 0x0008b110 Closure1<CGameFlowManager,void,const_char_*>::vfunc_0 (30 B): matches/0x0008b110.cpp
// sym: ??_G?$Method0@VCGameFlowManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CGameFlowManager, void, const char *>::~Closure1() {}


// 0x0008b130 Closure1<CGameFlowManager,void,const_char_*>::vfunc_2 (18 B): matches/0x0008b130.cpp
// sym: ?vfunc_2@?$Closure1@VCGameFlowManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CGameFlowManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_8b130 * *)&this->f_20)->*(*(void (CActorManager_8b130::**)(const char *))&this->f_1c))(*b);
}


// 0x0008b190 Closure0<CGameFlowManager,math::Vector>::vfunc_0 (30 B): matches/0x0008b190.cpp
// sym: ??_G?$Method1@VCGameFlowManager@@_NPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CGameFlowManager,math::Vector>::~Closure0() {}


// 0x0008b1b0 Closure0<CGameFlowManager,math::Vector>::vfunc_2 (63 B): equivalent/0x0008b1b0.cpp
// sym: ?vfunc_2@?$Closure0@VCGameFlowManager@@VVector@math@@@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure0<CGameFlowManager,math::Vector>::vfunc_2 @ 0x0008b1b0
template <> void Closure0<CGameFlowManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused1 = (void *)__p0; void * unused2 = (void *)__p1; math::Vector_8b1b0 * output = (math::Vector_8b1b0 *)__p2;

    math::Vector_8b1b0 temporary;
    math::Vector_8b1b0 result = ((*(CGameFlowManager_8b1b0 * *)&this->f_20)->*(*(math::Vector_8b1b0 *(CGameFlowManager_8b1b0::**)(math::Vector_8b1b0 *))&this->f_1c))(&temporary)[0];
    if (output) *output = result;
}


// 0x0008b230 Closure0<CGameFlowManager,float>::vfunc_0 (30 B): matches/0x0008b230.cpp
// sym: ??_G?$Method1@VCGameFlowManager@@PBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CGameFlowManager, float>::~Closure0() {}


// 0x0008b250 Closure0<CGameFlowManager,float>::vfunc_2 (35 B): matches/0x0008b250.cpp
// sym: ?vfunc_2@?$Closure0@VCGameFlowManager@@M@@UAEXPAX00@Z
// Same code shape as 0x0002fe60 (propagated; names are from that function)
template <> void Closure0<CGameFlowManager, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; float * out = (float *)__p2;

    CActorManager_8b250* m = (*(CActorManager_8b250 * *)&this->f_20);
    Fn_8b250 fn = (*(Fn_8b250 *)&this->f_1c);
    float v = (m->*fn)();
    if (out)
        *out = v;
}

namespace fn_f53af43c {

// 0x0008b280 FUN_0008b280 (76 B): matches/0x0008b280.cpp
// sym: ??0Closure1_8b280@fn_f53af43c@@QAE@PBDPAX1@Z
// data: gName1 = DAT_0048e0e4, gName2 = DAT_0048e0f0
Closure1_8b280::Closure1_8b280(const char* name, void* ctx, void* method) : Method1_8b280(name, method) {
    extra = ctx;
}

} // namespace fn_f53af43c

// 0x0008b2d0 Closure1<CGameFlowManager,bool,const_char_*>::vfunc_0 (30 B): matches/0x0008b2d0.cpp
// sym: ??_G?$Method0@VCGameFlowManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CGameFlowManager, bool, const char *>::~Closure1() {}


// 0x0008b2f0 Closure1<CGameFlowManager,bool,const_char_*>::vfunc_2 (30 B): matches/0x0008b2f0.cpp [wrapped: conflict: Closure1]
// sym: ?V2@Closure1@fn_0008b2f0@@UAEXPAXPAPBDPA_N@Z
namespace fn_0008b2f0 {
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
} // namespace fn_0008b2f0


// 0x0008b310 FUN_0008b310 (89 B): matches/0x0008b310.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0008b310@@QAE@PBDPAVOwner_8b310@1@P821@AEXXZ@Z
namespace fn_0008b310 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_00400168[2];
extern void* hulk_at_00400218[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_8b310 {};
typedef void (Owner_8b310::*Fn_8b310)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_8b310 fn;            // 0x1c
    Owner_8b310* owner;     // 0x20
    Closure2(const char* a1, Owner_8b310* a2, Fn_8b310 a3);
};

Closure2::Closure2(const char* a1, Owner_8b310* a2, Fn_8b310 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_00400168;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_00400218;
    owner = a2;
}
} // namespace fn_0008b310


// 0x0008b390 Closure2<CGameFlowManager,void,const_char_*,const_char_*>::vfunc_2 (22 B): matches/0x0008b390.cpp
// sym: ?vfunc_2@?$Closure2@VCGameFlowManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CGameFlowManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_8b390 * p = (Pair_8b390 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_8b390 * *)&this->f_20)->*(*(void (CActorManager_8b390::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x0008b3b0 FUN_0008b3b0 (76 B): matches/0x0008b3b0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0008b3b0@@QAE@PBDPAVOwner_8b3b0@1@P821@AEX0@Z@Z
namespace fn_0008b3b0 {
// data: key = DAT_0048e0f0
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C++" __declspec(nothrow) unsigned char __cdecl get_001d04d0(const char*);
struct Function_8b3b0 : public CtorV_001d0480 {
    Function_8b3b0(const char* s) : CtorV_001d0480(s, 1) { }
};
class Owner_8b3b0 {};
typedef void (Owner_8b3b0::*Fn_8b3b0)(const char*);
class Method1 : public Function_8b3b0 {
  public:
    virtual void f();
    Fn_8b3b0 name;
    Method1(const char* s, Fn_8b3b0 n) : Function_8b3b0(s) {
        name = n;
        retType = get_001d04d0(((const char*)&DAT_0048e0f0));
        argTypes[0] = get_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    Owner_8b3b0* val;
    Closure1(const char* s, Owner_8b3b0* v, Fn_8b3b0 n);
};
Closure1::Closure1(const char* s, Owner_8b3b0* v, Fn_8b3b0 n) : Method1(s, n) {
    val = v;
}
} // namespace fn_0008b3b0


// 0x0008b420 Closure1<CGameFlowManager,const_char_*,const_char_*>::vfunc_2 (30 B): matches/0x0008b420.cpp
// sym: ?vfunc_2@?$Closure1@VCGameFlowManager@@PBDPBD@@UAEXPAX00@Z
template <> void Closure1<CGameFlowManager, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** argument = (const char **)__p1; const char ** result = (const char **)__p2;

    CGameFlowManager_8b420* obj = (*(CGameFlowManager_8b420 * *)&this->f_20);
    const char* (CGameFlowManager_8b420::*fn)(const char*) = (*(const char *(CGameFlowManager_8b420::**)(const char *))&this->f_1c);
    const char* value = (obj->*fn)(*argument);
    if (result)
        *result = value;
}


// 0x0008b4a0 Closure0<CGameFlowManager,void>::vfunc_2 (11 B): matches/0x0008b4a0.cpp
// sym: ?vfunc_2@?$Closure0@VCGameFlowManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<CGameFlowManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_8b4a0 * *)&this->f_20)->*(*(void (CActorManager_8b4a0::**)())&this->f_1c))();
}

namespace fn_f53af43c {

// 0x0008b4b0 FUN_0008b4b0 (166 B): matches/0x0008b4b0.cpp
// sym: ?FUN_0008b4b0@Missions_8b4b0@fn_f53af43c@@QAE_NHTSlot_8b4b0@2@PADHPAUVec3_8b4b0@2@PAPAX@Z
// FUN_0008b4b0 @ 0x0008b4b0
bool Missions_8b4b0::FUN_0008b4b0(int index, Slot_8b4b0 out, char *name, int nameSize, Vec3_8b4b0 *pos, void **sub)
{
    Record_8b4b0 *rec = records + index;
    if (out.ptr != 0)
        *out.ptr = rec->flag;
    if (name != 0) {
        FUN_0008ad90(&out.value, &index);
        if (complete)
            FUN_000964a0(name, nameSize, "TBS_COMPLETE_PROMPT");
        else
            FUN_000964a0(name, nameSize, "TBS_C%dM%d_NAME", out.value, index);
    }
    if (pos != 0)
        *pos = rec->pos;
    if (sub != 0)
        *sub = rec->sub;
    return true;
}

} // namespace fn_f53af43c

// 0x0008baf0 FUN_0008baf0 (81 B): equivalent/0x0008baf0.cpp
// sym: ?FUN_0008baf0@ThisWrap_0008baf0@owners@@QAEXPAH0@Z
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_0008baf0 @ 0x0008baf0
void owners::ThisWrap_0008baf0::FUN_0008baf0(int* column, int* mode) {
    const char* text = this->FUN_0008abc0();
    if (text && text[0] != '\0') {
        FUN_00345804(text, "c%dm%d", column, mode);
        return;
    }
    *column = 0;
    *mode = 0;
}


// 0x0008bb50 FUN_0008bb50 (109 B): equivalent/0x0008bb50.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_0008bb50@Registry_8bb50@fn_0008bb50@@QAEXPBDPAVCGameFlowManager@2@P832@AEHXZ@Z
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_0008bb50 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0008bb50 @ 0x0008bb50
// FUN_0008bb50 @ 0x0008bb50  (generated by work/closure/gen.py)
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


class CGameFlowManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_8bb50 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_8bb50(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_8bb50 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_8bb50(name, 0) {
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

struct Registry_8bb50 {
    void FUN_001d3b70(const char*, void*);
    void FUN_0008bb50(const char* name, CGameFlowManager* owner, int (CGameFlowManager::*fn)());
};

void Registry_8bb50::FUN_0008bb50(const char* name, CGameFlowManager* owner, int (CGameFlowManager::*fn)()) {
    typedef Closure0<CGameFlowManager, int> Alloc_8bb50;
    HULK_SIZE32(Alloc_8bb50, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CGameFlowManager, int>));
    Closure0<CGameFlowManager, int>* c = 0;
    if (mem)
        c = new (mem) Closure0<CGameFlowManager, int>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_0008bb50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0008bbc0 FUN_0008bbc0 (109 B): equivalent/0x0008bbc0.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_0008bbc0@Registry_8bbc0@fn_0008bbc0@@QAEXPBDPAVCGameFlowManager@2@P832@AEPBDXZ@Z
namespace fn_0008bbc0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0008bbc0 @ 0x0008bbc0
// FUN_0008bbc0 @ 0x0008bbc0  (generated by work/closure/gen.py)
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


class CGameFlowManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_8bbc0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_8bbc0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_8bbc0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_8bbc0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_8bbc0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_0008bbc0(const char* name, CGameFlowManager* owner, const char* (CGameFlowManager::*fn)());
};

void Registry_8bbc0::FUN_0008bbc0(const char* name, CGameFlowManager* owner, const char* (CGameFlowManager::*fn)()) {
    typedef Closure0<CGameFlowManager, const char*> Alloc_8bbc0;
    HULK_SIZE32(Alloc_8bbc0, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CGameFlowManager, const char*>));
    Closure0<CGameFlowManager, const char*>* c = 0;
    if (mem)
        c = new (mem) Closure0<CGameFlowManager, const char*>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_0008bbc0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0008bc30 FUN_0008bc30 (109 B): equivalent/0x0008bc30.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_0008bc30@Registry_8bc30@fn_0008bc30@@QAEXPBDPAVCGameFlowManager@2@P832@AE_NXZ@Z
namespace fn_0008bc30 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0008bc30 @ 0x0008bc30
// FUN_0008bc30 @ 0x0008bc30  (generated by work/closure/gen.py)
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


class CGameFlowManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_8bc30 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_8bc30(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_8bc30 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_8bc30(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_8bc30 {
    void FUN_001d3b70(const char*, void*);
    void FUN_0008bc30(const char* name, CGameFlowManager* owner, bool (CGameFlowManager::*fn)());
};

void Registry_8bc30::FUN_0008bc30(const char* name, CGameFlowManager* owner, bool (CGameFlowManager::*fn)()) {
    typedef Closure0<CGameFlowManager, bool> Alloc_8bc30;
    HULK_SIZE32(Alloc_8bc30, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CGameFlowManager, bool>));
    Closure0<CGameFlowManager, bool>* c = 0;
    if (mem)
        c = new (mem) Closure0<CGameFlowManager, bool>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_0008bc30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0008bd40 FUN_0008bd40 (109 B): equivalent/0x0008bd40.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_0008bd40@Registry_8bd40@fn_0008bd40@@QAEXPBDPAVCGameFlowManager@2@P832@AE?AVVector@math@2@XZ@Z
namespace fn_0008bd40 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0008bd40 @ 0x0008bd40
// FUN_0008bd40 @ 0x0008bd40  (generated by work/closure/gen.py)
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
extern "C" const char DAT_0048e10c[];


class CGameFlowManager { public: float FUN_dummy(); };
namespace math {
class Vector { public: float FUN_dummy(); };
}

class __declspec(novtable) MethodBase_8bd40 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_8bd40(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_8bd40 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_8bd40(name, 0) {
        fn = f;
        retType = FUN_001d04d0(DAT_0048e10c);
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_8bd40 {
    void FUN_001d3b70(const char*, void*);
    void FUN_0008bd40(const char* name, CGameFlowManager* owner, math::Vector (CGameFlowManager::*fn)());
};

void Registry_8bd40::FUN_0008bd40(const char* name, CGameFlowManager* owner, math::Vector (CGameFlowManager::*fn)()) {
    typedef Closure0<CGameFlowManager, math::Vector> Alloc_8bd40;
    HULK_SIZE32(Alloc_8bd40, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CGameFlowManager, math::Vector>));
    Closure0<CGameFlowManager, math::Vector>* c = 0;
    if (mem)
        c = new (mem) Closure0<CGameFlowManager, math::Vector>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_0008bd40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0008bdb0 FUN_0008bdb0 (109 B): equivalent/0x0008bdb0.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_0008bdb0@Registry_8bdb0@fn_0008bdb0@@QAEXPBDPAVCGameFlowManager@2@P832@AEMXZ@Z
namespace fn_0008bdb0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0008bdb0 @ 0x0008bdb0
// FUN_0008bdb0 @ 0x0008bdb0  (generated by work/closure/gen.py)
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


class CGameFlowManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_8bdb0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_8bdb0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_8bdb0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_8bdb0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_8bdb0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_0008bdb0(const char* name, CGameFlowManager* owner, float (CGameFlowManager::*fn)());
};

void Registry_8bdb0::FUN_0008bdb0(const char* name, CGameFlowManager* owner, float (CGameFlowManager::*fn)()) {
    typedef Closure0<CGameFlowManager, float> Alloc_8bdb0;
    HULK_SIZE32(Alloc_8bdb0, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CGameFlowManager, float>));
    Closure0<CGameFlowManager, float>* c = 0;
    if (mem)
        c = new (mem) Closure0<CGameFlowManager, float>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_0008bdb0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0008bf10 FUN_0008bf10 (109 B): equivalent/0x0008bf10.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_0008bf10@Registry_8bf10@fn_0008bf10@@QAEXPBDPAVCGameFlowManager@2@P832@AEXXZ@Z
namespace fn_0008bf10 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0008bf10 @ 0x0008bf10
// FUN_0008bf10 @ 0x0008bf10  (generated by work/closure/gen.py)
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


class CGameFlowManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_8bf10 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_8bf10(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_8bf10 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_8bf10(name, 0) {
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

struct Registry_8bf10 {
    void FUN_001d3b70(const char*, void*);
    void FUN_0008bf10(const char* name, CGameFlowManager* owner, void (CGameFlowManager::*fn)());
};

void Registry_8bf10::FUN_0008bf10(const char* name, CGameFlowManager* owner, void (CGameFlowManager::*fn)()) {
    typedef Closure0<CGameFlowManager, void> Alloc_8bf10;
    HULK_SIZE32(Alloc_8bf10, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CGameFlowManager, void>));
    Closure0<CGameFlowManager, void>* c = 0;
    if (mem)
        c = new (mem) Closure0<CGameFlowManager, void>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_0008bf10
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0008c400 FUN_0008c400 (30 B): matches/0x0008c400.cpp [wrapped: conflict: CMemoryCardManager]
// sym: ?target@fn_0008c400@@YIXPAVCMemoryCardManager@1@@Z
namespace fn_0008c400 {
extern "C" char DAT_004004f4[];
class CMemoryCardManager {
  public:
    void* vtable;
    int x;
    void* field8;
};
void __cdecl thunk_FUN_00267090(void*);
void __fastcall target(CMemoryCardManager* self) {
    void* value = self->field8;
    self->vtable = (void*)((hulk_intptr)DAT_004004f4);
    thunk_FUN_00267090(value);
    self->field8 = 0;
}
} // namespace fn_0008c400


// 0x0008c470 FUN_0008c470 (245 B): equivalent/0x0008c470.cpp [wrapped: conflict: FUN_0008d690]
// sym: ?FUN_0008c470@Owner_8c470@fn_0008c470@@QAEXI@Z
namespace fn_0008c470 {
// STATUS: equivalent (tools/equiv.py level 3: 2974 inputs, branch coverage 2/2)
// FUN_0008c470 @ 0x0008c470
struct Owner_8c470;
struct Pair_8c470 { unsigned a,b; };
struct Interface_8c470 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void attach(Owner_8c470*, unsigned);
 virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual unsigned open(Pair_8c470*, unsigned);
};
struct State_8c470 { Interface_8c470* object; unsigned zero; char pad[0x64]; unsigned char flag1,flag2; char pad2[0x42]; unsigned result; unsigned a,b,c,d,e; };
extern "C" State_8c470* __cdecl FUN_0008d6d0(unsigned);
extern "C" unsigned __cdecl FUN_00266da0(unsigned);
extern Pair_8c470* __cdecl FUN_0008d690(unsigned);
extern void __cdecl thunk_FUN_00270f10(const char*,unsigned);
extern void __cdecl thunk_FUN_00271530(State_8c470*,const char*,unsigned,unsigned);
extern void __cdecl FUN_0008d330(Pair_8c470*);
struct Owner_8c470 { unsigned unknown; unsigned parameter; State_8c470* state; void FUN_0008c470(unsigned); };
void Owner_8c470::FUN_0008c470(unsigned value) {
 parameter=value;
 state=FUN_0008d6d0(0xc8);
 unsigned saved=FUN_00266da0(1);
 Pair_8c470* pair=FUN_0008d690((int)sizeof(Pair_8c470));
 pair->a=0; pair->b=0;
 FUN_00266da0(saved);
 state->zero=0;
 thunk_FUN_00270f10("U:",0);
 thunk_FUN_00271530(state,"U:",1,0);
 if(state->object) {
 state->object->attach(this,0);
 unsigned result=state->object->open(pair,parameter);
 state->result=result;
 state->flag1=0; state->flag2=0; state->zero=0;
 state->a=1; state->b=1; state->c=1; state->d=1; state->e=1;
 } else { state->object=0; }
 FUN_0008d330(pair);
}
} // namespace fn_0008c470

