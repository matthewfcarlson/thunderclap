// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001bddc0..0x001be0e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fdbebb2a {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fdbebb2a {} using namespace fn_fdbebb2a;
#include "game/unknown.h"
#include "compat/ptr.h"
#include "decls/managers.h"
// (gfx8, C18) The functions below are CSubtitleManager's (its constructor binds them as stm_ script functions; the FE
// manager calls 0x001bdf00 on it): the views place their words by decls/managers.h's HulkSubtitleManager offsets, so
// the 32-bit layout is the one they had and natively the words follow the record's pointer words. HULK_SUB gives a
// word's offset, HULK_SUB_AT checks on every build that a view's word sits where the record's does.
#if defined(__clang__)
#define HULK_SUB_OFF(T, f) __builtin_offsetof(T, f)
#else
#define HULK_SUB_OFF(T, f) ((unsigned int)(hulk_uintptr)&((T*)0)->f)
#endif
#define HULK_SUB(f) HULK_SUB_OFF(HulkSubtitleManager, f)
#define HULK_SUB_CAT2(a, b) a##b
#define HULK_SUB_CAT(a, b) HULK_SUB_CAT2(a, b)
#define HULK_SUB_AT(V, v, f) \
    typedef char HULK_SUB_CAT(hulk_sub_at_, __LINE__)[(HULK_SUB_OFF(V, v) == HULK_SUB(f)) ? 1 : -1]

// ---- declarations shared by the functions below
namespace fn_fdbebb2a {
class Obj_1bddc0 {
  public:
    char pad[HULK_SUB(ready)];
    unsigned char value;
    void Set(unsigned char x);
};
HULK_SUB_AT(Obj_1bddc0, value, ready);
class Obj_1bde90 {
  public:
    void clean_000f7850();
};
class Thing_1bde90 {
  public:
    char pad[HULK_SUB(resource1)];
    Obj_1bde90* a;
    Obj_1bde90* b;
    void target();
};
HULK_SUB_AT(Thing_1bde90, a, resource1);
HULK_SUB_AT(Thing_1bde90, b, resource2);
class Obj_1bdeb0 {
  public:
    void clean_000f89e0();
};
class Thing_1bdeb0 {
  public:
    char pad[HULK_SUB(resource1)];
    Obj_1bdeb0* a;
    Obj_1bdeb0* b;
    void target();
};
HULK_SUB_AT(Thing_1bdeb0, a, resource1);
HULK_SUB_AT(Thing_1bdeb0, b, resource2);
struct Ref_1bded0 {
    void FnF_000f8970(void*);
};
struct Obj_1bded0 {
    char pad[HULK_SUB(resource1)];
    Ref_1bded0* a;
    Ref_1bded0* b;
    void Clear(void*);
};
HULK_SUB_AT(Obj_1bded0, a, resource1);
HULK_SUB_AT(Obj_1bded0, b, resource2);
class Obj_1bdf00 {
  public:
    void clean_000f7ce0();
};
class Thing_1bdf00 {
  public:
    char pad[HULK_SUB(resource1)];
    Obj_1bdf00* a;
    Obj_1bdf00* b;
    void target();
};
HULK_SUB_AT(Thing_1bdf00, a, resource1);
HULK_SUB_AT(Thing_1bdf00, b, resource2);
struct Entry {
    float a, b;
    __int64 c;
};
class Obj {
  public:
    char pad[HULK_SUB(count)];
    int count;
    Entry* entries;
    void Set(int i, float a, float x, float b);
};
HULK_SUB_AT(Obj, count, count);
HULK_SUB_AT(Obj, entries, events);
} // namespace fn_fdbebb2a
extern "C" __int64 __cdecl FUN_0027b020(float);
namespace fn_fdbebb2a {
class Obj_1bdfb0 {
  public:
    char pad[HULK_SUB(d)];
    int value;
    void Set(int v);
};
HULK_SUB_AT(Obj_1bdfb0, value, d);
struct Subtitle { char pad[HULK_SUB(resource2)]; struct Sink* sink; char pad2[HULK_SUB(g) - HULK_SUB(resource2) - sizeof(struct Sink*)]; int key; void FUN_001be060(); };
HULK_SUB_AT(Subtitle, sink, resource2);
HULK_SUB_AT(Subtitle, key, g);
struct Sink { void FUN_000f7110(); void FUN_000f7a80(char*); };
extern const char* __cdecl FUN_000f7120(int);   // (x64t11) the language's name (FEThingsBase_3.cpp)
extern "C" int __cdecl FUN_000964a0(char*, int, const char*, ...);   // (x64t13) as defined (CUnlockablesManager.cpp)
extern int DAT_004d9968;
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern void __fastcall __security_check_cookie(int);
#endif


// 0x001bddc0 FUN_001bddc0 (10 B): matches/0x001bddc0.cpp
// sym: ?Set@Obj_1bddc0@fn_fdbebb2a@@QAEXE@Z
void Obj_1bddc0::Set(unsigned char x) {
    value = x;
}

} // namespace fn_fdbebb2a

// 0x001bde50 FUN_001bde50 (61 B): matches/0x001bde50.cpp
// sym: ?FUN_001bde50@Thing_1bde50@owners@@QAE_NH@Z
bool owners::Thing_1bde50::FUN_001bde50(int x) {
    value = x;
    if (a) {
        a->FUN_000f6fe0(x);
        a->FUN_000f7110();
    }
    if (b) {
        b->FUN_000f6fe0(value);
        b->FUN_000f7110();
    }
    return true;
}

namespace fn_fdbebb2a {

// 0x001bde90 FUN_001bde90 (29 B): matches/0x001bde90.cpp
// sym: ?target@Thing_1bde90@fn_fdbebb2a@@QAEXXZ
void Thing_1bde90::target() {
    if (a)
        a->clean_000f7850();
    if (b)
        b->clean_000f7850();
}


// 0x001bdeb0 FUN_001bdeb0 (29 B): matches/0x001bdeb0.cpp
// sym: ?target@Thing_1bdeb0@fn_fdbebb2a@@QAEXXZ
// Same code shape as 0x001bde90 (propagated; names are from that function)
void Thing_1bdeb0::target() {
    if (a)
        a->clean_000f89e0();
    if (b)
        b->clean_000f89e0();
}


// 0x001bded0 FUN_001bded0 (39 B): matches/0x001bded0.cpp
// sym: ?Clear@Obj_1bded0@fn_fdbebb2a@@QAEXPAX@Z
void Obj_1bded0::Clear(void* p) {
    if (a)
        a->FnF_000f8970(p);
    if (b)
        b->FnF_000f8970(p);
}


// 0x001bdf00 FUN_001bdf00 (29 B): matches/0x001bdf00.cpp
// sym: ?target@Thing_1bdf00@fn_fdbebb2a@@QAEXXZ
// Same code shape as 0x001bde90 (propagated; names are from that function)
void Thing_1bdf00::target() {
    if (a)
        a->clean_000f7ce0();
    if (b)
        b->clean_000f7ce0();
}


// 0x001bdf20 FUN_001bdf20 (66 B): matches/0x001bdf20.cpp
// sym: ?Set@Obj@fn_fdbebb2a@@QAEXHMMM@Z
void Obj::Set(int i, float a, float x, float b) {
    if (i < count) {
        entries[i].a = a;
        entries[i].c = FUN_0027b020(x);
        entries[i].b = b;
    }
}


// 0x001bdfb0 FUN_001bdfb0 (10 B): matches/0x001bdfb0.cpp
// sym: ?Set@Obj_1bdfb0@fn_fdbebb2a@@QAEXH@Z
void Obj_1bdfb0::Set(int v) {
    value = v;
}


// 0x001bdfc0 FUN_001bdfc0 (12 B): matches/0x001bdfc0.cpp
// sym: _FUN_001bdfc0@4
// data: g_value_1bdfc0 = DAT_004c4c1c
extern "C" void __stdcall FUN_001bdfc0(int x) {
    DAT_004c4c1c = *(float*)&x;
}


// 0x001bdfd0 FUN_001bdfd0 (32 B): matches/0x001bdfd0.cpp
// sym: _FUN_001bdfd0@12
extern "C" {
void __stdcall FUN_001bdfd0(unsigned int a, unsigned int b, unsigned int c) {
    (*(unsigned int*)&DAT_004e2308) = a;
    (*(unsigned int*)&DAT_004e230c) = b;
    (*(unsigned int*)&DAT_004e2310) = c;
}
}


// 0x001be060 FUN_001be060 (97 B): equivalent/0x001be060.cpp
// sym: ?FUN_001be060@Subtitle@fn_fdbebb2a@@QAEXXZ @50a6b8b08df2 @w1c8c6ea5a304 @v376b494beb0e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001be060 @ 0x001be060
void Subtitle::FUN_001be060() { int cookie=DAT_004d9968; const char* value = FUN_000f7120(key); if (value && sink) { sink->FUN_000f7110(); char text[64]; FUN_000964a0(text,64,(*(const char**)&DAT_004c4c6c),value); sink->FUN_000f7a80(text); } __security_check_cookie(cookie); }

} // namespace fn_fdbebb2a
