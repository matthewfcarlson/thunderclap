// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00257dd0..0x00258140 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fea88065 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fea88065 {} using namespace fn_fea88065;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fea88065 {
typedef unsigned int u32_257e80;
struct Node {
  public:
    Node* next;
    Node* prev;
};
struct Head_257e80 {
    Node* first;
    Node* last;
};
typedef unsigned int u32_257ec0;
typedef unsigned int u32_257ee0;
extern void* IRefCount_vftable_2580e0;


// 0x00257dd0 FUN_00257dd0 (18 B): matches/0x00257dd0.cpp
// sym: _FUN_00257dd0
extern "C" void FUN_00257dd0(unsigned int* pair) {
    pair[0] = 0;
    pair[1] = 0;
}


// 0x00257df0 FUN_00257df0 (1 B): matches/0x00257df0.cpp
// sym: _FUN_00257df0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_00257df0() {}


// 0x00257e80 FUN_00257e80 (53 B): matches/0x00257e80.cpp
// sym: _FUN_00257e80
extern "C" void FUN_00257e80(Head_257e80* h, Node* n) {
    if (h->first == 0) {
        h->first = n;
        n->prev = 0;
        h->last = n;
        n->next = 0;
        return;
    }
    h->last->next = n;
    n->prev = h->last;
    h->last = n;
    n->next = 0;
}


// 0x00257ec0 FUN_00257ec0 (7 B): matches/0x00257ec0.cpp
// sym: _FUN_00257ec0
extern "C" u32_257ec0 __cdecl FUN_00257ec0(u32_257ec0* ptr) {
    return *ptr;
}


// 0x00257ee0 FUN_00257ee0 (7 B): matches/0x00257ee0.cpp
// sym: _FUN_00257ee0
// Same code shape as 0x00257ec0 (propagated; names are from that function)
extern "C" u32_257ee0 __cdecl FUN_00257ee0(u32_257ee0* ptr) {
    return *ptr;
}


// 0x00257f00 FUN_00257f00 (47 B): matches/0x00257f00.cpp
// sym: _FUN_00257f00
extern "C" void FUN_00257f00(Node* out, Node* n) {
    if (n->prev == 0)
        out->next = n->next;
    else
        n->prev->next = n->next;
    if (n->next == 0) {
        out->prev = n->prev;
        return;
    }
    n->next->prev = n->prev;
}


// 0x00257f50 FUN_00257f50 (24 B): matches/0x00257f50.cpp
// sym: ?Count@fn_fea88065@@YAHPAPAUNode@1@@Z
int Count(Node** p) {
    int n = 0;
    Node* cur = *p;
    while (cur) {
        cur = cur->next;
        n++;
    }
    return n;
}


// 0x002580e0 FUN_002580e0 (7 B): matches/0x002580e0.cpp
// sym: @FUN_002580e0@4
// Same code shape as 0x001b6820 (propagated; names are from that function)
extern "C" void __fastcall FUN_002580e0(void* self) {
    *(void**)self = &IRefCount_vftable_2580e0;
}

} // namespace fn_fea88065
