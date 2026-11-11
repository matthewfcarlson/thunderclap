// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002036c0..0x00203870 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f46f06fe {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f46f06fe {} using namespace fn_f46f06fe;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f46f06fe {
extern "C" int __cdecl snprintf(char*, unsigned int, const char*, ...);
struct Item {
    char pad[0x54];
    short id;
};
struct List {
    char pad[0x18];
    int Count_001c7520();
};
struct Holder {
    char pad[4];
    List* list;
};
extern "C" Holder* __cdecl FUN_001c3d90();
class Object {
  public:
    char pad[0xaec];
    void* member;
};
extern "C" int __fastcall FUN_002666f0(void*);


// 0x002036c0 FUN_002036c0 (17 B): matches/0x002036c0.cpp
// sym: ?FUN_002036c0@fn_f46f06fe@@YGXPAX@Z
// data: g_flag_2036c0 = DAT_004e5a50
void __stdcall FUN_002036c0(void* p) {
    (*(unsigned char*)&DAT_004e5a50) = (unsigned char)(p != 0);
}

} // namespace fn_f46f06fe

// 0x002036e0 FUN_002036e0 (13 B): matches/0x002036e0.cpp
// sym: ?FUN_002036e0@Obj_2036e0@owners@@QAEXH@Z
void owners::Obj_2036e0::FUN_002036e0(int x) {
    mAf8 = x;
}


// 0x002036f0 FUN_002036f0 (7 B): matches/0x002036f0.cpp
// sym: ?FUN_002036f0@Obj_2036f0@owners@@QAEHXZ
int owners::Obj_2036f0::FUN_002036f0() {
    return value;
}

namespace fn_f46f06fe {

// 0x00203740 FUN_00203740 (43 B): matches/0x00203740.cpp
// sym: ?FUN_00203740@fn_f46f06fe@@YAPADXZ
// data: buffer = DAT_004e5950, counter = DAT_004e5a54
char* FUN_00203740() {
    int n = (*(int*)&DAT_004e5a54)++;
    snprintf(((char*)((char*)&DAT_004e5948 + 8)), 256, "unique%d", n);
    return ((char*)((char*)&DAT_004e5948 + 8));
}

} // namespace fn_f46f06fe

// 0x00203780 FUN_00203780 (26 B): matches/0x00203780.cpp
// sym: ?FUN_00203780@Vec_203780@owners@@QAEXPAX@Z
void owners::Vec_203780::FUN_00203780(void* item) {
    mItems[mCount] = item;
    mCount++;
}


// 0x002037a0 FUN_002037a0 (67 B): matches/0x002037a0.cpp
// sym: ?FUN_002037a0@Obj_2037a0@owners@@QAEHXZ
int owners::Obj_2037a0::FUN_002037a0() {
    Holder* h = FUN_001c3d90();
    List* list = h->list;
    int count = ((List*)((char*)list + 0x18))->Count_001c7520();
    for (int i = 0; i < count; ++i) {
        Item* p = ((Item *)((owners::Thing_1c7f80 *)list)->FUN_001c7f80((unsigned int)i));
        int id = p->id;
        if (flags[id] == 2)
            return id;
    }
    return -1;
}

namespace fn_f46f06fe {

// 0x00203840 FUN_00203840 (18 B): matches/0x00203840.cpp
// sym: ?FUN_00203840@fn_f46f06fe@@YIHPAVObject@1@@Z
hulk_intptr __fastcall FUN_00203840(Object* self) {
    if (self->member)
        return FUN_002666f0(self->member);
    return 0;
}

} // namespace fn_f46f06fe

// 0x00203860 FUN_00203860 (7 B): matches/0x00203860.cpp
// sym: ?FUN_00203860@Thing_203860@owners@@QAEPAXXZ
void* owners::Thing_203860::FUN_00203860() {
    return (char*)this + 0xaa4;
}

