// cl-flags: /O1
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011b800..0x0011c310 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb8340db {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb8340db {} using namespace fn_fb8340db;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fb8340db {
class Obj_11b800 {
  public:
    char pad[12];
    int mValue;
    int Get();
};


// 0x0011b800 FUN_0011b800 (4 B): matches/0x0011b800.cpp
// sym: ?Get@Obj_11b800@fn_fb8340db@@QAEHXZ
int Obj_11b800::Get() {
    return mValue;
}

} // namespace fn_fb8340db

// 0x0011c0d0 FUN_0011c0d0 (12 B): matches/0x0011c0d0.cpp
// sym: ?FUN_0011c0d0@Obj_11c0d0@owners@@QAEDD@Z
char owners::Obj_11c0d0::FUN_0011c0d0(char c) {
    m3c = c;
    return 1;
}

