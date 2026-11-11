// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b45a0..0x000b4cf0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb479c50 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb479c50 {} using namespace fn_fb479c50;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fb479c50 {
extern "C" void __cdecl FUN_000fc100(void*, int);
class X {
  public:
    int a;
    int b;
    int fn(int x, int y);
    void other();
};
class A {
  public:
    char pad[4];
    int x;
    void f();
    int g(int, int);
};
struct Item_b4640 {
    void Clear();
    char pad[8];
};
struct Thing_b4640 {
    Item_b4640 a;
    Item_b4640 b;
    Item_b4640 c;
    Item_b4640 d;
    Thing_b4640* Run();
};
struct Sub_b4670 {
    char pad[8];
    void Clear();
};
struct Thing_b4670 {
    char pad[8];
    Sub_b4670 a;
    Sub_b4670 b;
    Sub_b4670 c;
    void Clear();
};
struct Object {
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
};
extern char DAT_0049dba4;
extern char DAT_0049f454;
extern void* __cdecl FUN_000fc260(const char*);
extern Object* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" char* __cdecl FUN_00096450(const char*);

// 0x000b45a0 thunk_FUN_000fc280 (5 B): not yet verified
// 0x000b45b0 thunk_FUN_000fc2f0 (5 B): not yet verified

// 0x000b45d0 FUN_000b45d0 (16 B): matches/0x000b45d0.cpp
// sym: _FUN_000b45d0
extern "C" void __cdecl FUN_000b45d0(void* p) {
    FUN_000fc100(p, 0);
}


// 0x000b45e0 FUN_000b45e0 (5 B): matches/0x000b45e0.cpp
// sym: _FUN_000b45e0@8
extern "C" int __stdcall FUN_000b45e0(int a, int b) {
    return 0;
}


// 0x000b45f0 FUN_000b45f0 (23 B): matches/0x000b45f0.cpp
// sym: ?fn@X@fn_fb479c50@@QAEHHH@Z
int X::fn(int x, int y) {
    if (!b)
        return -1;
    other();
    return 0;
}


// 0x000b4610 FUN_000b4610 (23 B): matches/0x000b4610.cpp
// sym: ?g@A@fn_fb479c50@@QAEHHH@Z
int A::g(int a, int b) {
    if (!x)
        return -1;
    f();
    return 0;
}


// 0x000b4640 FUN_000b4640 (36 B): matches/0x000b4640.cpp
// sym: ?Run@Thing_b4640@fn_fb479c50@@QAEPAU12@XZ
Thing_b4640* Thing_b4640::Run() {
    a.Clear();
    b.Clear();
    c.Clear();
    d.Clear();
    return this;
}


// 0x000b4670 FUN_000b4670 (35 B): matches/0x000b4670.cpp
// sym: ?Clear@Thing_b4670@fn_fb479c50@@QAEXXZ
void Thing_b4670::Clear() {
    c.Clear();
    b.Clear();
    a.Clear();
    ((Sub_b4670*)this)->Clear();
}


// 0x000b46c0 FUN_000b46c0 (235 B): matches/0x000b46c0.cpp
// sym: ?FUN_000b46c0@fn_fb479c50@@YAXXZ
void __cdecl FUN_000b46c0() {
    const char* names[] = {"comic_book_selector_1",
                           "comic_book_selector_2",
                           "comic_book_selector_3",
                           "comic_book_selector_4",
                           "comic_book_selector_5",
                           "comic_book_selector_6",
                           "character_selector_1",
                           "character_selector_2",
                           "character_selector_3",
                           "character_selector_4",
                           "enemy_selector_1",
                           "enemy_selector_2",
                           "environment_selector_1",
                           "environment_selector_2",
                           "environment_selector_3",
                           "environment_selector_4",
                           "character_render_selector_1",
                           "character_render_selector_2",
                           "character_render_selector_3",
                           "enemy_render_selector_1",
                           0};
    for (int i = 0; names[i]; ++i) {
        Object* obj = FUN_00344e74(FUN_000fc260(names[i]), 0, &DAT_0049dba4, &DAT_0049f454, 0);
        if (obj)
            obj->v21();
    }
}

} // namespace fn_fb479c50

// 0x000b4b60 FUN_000b4b60 (175 B): equivalent/0x000b4b60.cpp
// sym: ?FUN_000b4b60@Registry_b4b60@owners@@QAEXPBD0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 19/20, incomplete)
// FUN_000b4b60 @ 0x000b4b60
void owners::Registry_b4b60::FUN_000b4b60(const char* key, const char* value) {
 if (!*key || !*value) return;
 for (int i=0; i<128; ++i) {
  const char* stored=keys[i];
  if (!stored) {
   keys[i]=FUN_00096450(key);
   values[i]=FUN_00096450(value);
   return;
  }
  const char* p=key;
  while (*p == *stored) {
   if (!*p) return;
   ++p; ++stored;
  }
 }
}


// 0x000b4c10 FUN_000b4c10 (99 B): matches/0x000b4c10.cpp
// sym: ?FUN_000b4c10@K_b4c10@owners@@QAE_NPBD@Z
bool owners::K_b4c10::FUN_000b4c10(const char* s) {
    for (int i = 0; i < 128; i++) {
        const char* n = names[i];
        if (!n)
            break;
        if (strcmp(s, n) == 0)
            return true;
    }
    return false;
}


// 0x000b4c80 FUN_000b4c80 (99 B): matches/0x000b4c80.cpp
// sym: ?FUN_000b4c80@Table_b4c80@owners@@QAE_NPBD@Z
bool owners::Table_b4c80::FUN_000b4c80(const char* name) {
    for (int i = 0; i < 0x80; i++) {
        const char* s = names[i];
        if (!s)
            return false;
        if (strcmp(name, s) == 0)
            return true;
    }
    return false;
}

