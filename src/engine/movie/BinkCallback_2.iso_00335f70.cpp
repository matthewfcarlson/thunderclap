// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335f70 FUN_00335f70 (99 B): matches/0x00335f70.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?Fetch@Obj_335f70@fn_f55c1305@@QAEHHH@Z
#include "gen/owners.h"
namespace fn_f55c1305 {} using namespace fn_f55c1305;
namespace fn_f55c1305 {
struct Node {
    int first;
    int dummy;
    int kind;
    Node* child;
};
struct Manager_335f70 {
    char pad[0x44];
    int count;
};
extern int Size_00337f20(int);
class Obj_335f70 {
  public:
    char pad[4];
    Manager_335f70* mgr;
    int** data;
    int Fetch(int index, int n);
};
int Obj_335f70::Fetch(int index, int n) {
    if (index < 0)
        return 0;
    if (index >= mgr->count)
        return 0;
    if (((Node *)((owners::Thing_337090 *)mgr)->FUN_00337090(index))->kind != 9)
        return 0;
    int* p = (int*)((char*)data[index] + 4);
    if (((Node *)((owners::Thing_337090 *)mgr)->FUN_00337090(index))->child->first != 10)
        return 0;
    p = (int*)((char*)p + Size_00337f20(10) * n);
    return *p;
}
} // namespace fn_f55c1305

