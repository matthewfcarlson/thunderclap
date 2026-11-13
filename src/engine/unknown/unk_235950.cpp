// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00235950..0x00235a20 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7988f86 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7988f86 {} using namespace fn_f7988f86;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f7988f86 {
class X_235970 {
  public:
    char pad[0xc];
    int m_val;
    bool SetCompare_00235970(int v);
};
struct Obj_235980 {
    char pad[0x10];
    void* GetParent_00235980();
};
class Obj_235990 {
  public:
    char pad[0x1c];
    char m1c;
    unsigned char SetRecurse_00235990(unsigned char v);
};
extern "C" void FUN_00234810(void*, void*);

} // namespace fn_f7988f86

// 0x00235950 FUN_00235950 (12 B): matches/0x00235950.cpp
// sym: ?FUN_00235950@C_235950@owners@@QAEDH@Z
char owners::C_235950::FUN_00235950(int x) {
    m = x;
    return 1;
}


// 0x00235960 FUN_00235960 (4 B): matches/0x00235960.cpp
// sym: ?FUN_00235960@Thing_235960@owners@@QAEPADXZ
char* owners::Thing_235960::FUN_00235960() {
    return (char*)this + 0x10;
}

namespace fn_f7988f86 {

// 0x00235970 FUN_00235970 (12 B): matches/0x00235970.cpp
// sym: ?SetCompare_00235970@X_235970@fn_f7988f86@@QAE_NH@Z
bool X_235970::SetCompare_00235970(int v) {
    m_val = v;
    return true;
}


// 0x00235980 FUN_00235980 (4 B): matches/0x00235980.cpp
// sym: ?GetParent_00235980@Obj_235980@fn_f7988f86@@QAEPAXXZ
void* Obj_235980::GetParent_00235980() {
    char* p = (char*)this + 0x10;
    return p;
}


// 0x00235990 FUN_00235990 (12 B): matches/0x00235990.cpp
// sym: ?SetRecurse_00235990@Obj_235990@fn_f7988f86@@QAEEE@Z
unsigned char Obj_235990::SetRecurse_00235990(unsigned char v) {
    m1c = (char)v;
    return 1;
}

} // namespace fn_f7988f86

// 0x002359a0 FUN_002359a0 (12 B): matches/0x002359a0.cpp
// sym: ?FUN_002359a0@X_2359a0@owners@@QAEDH@Z
char owners::X_2359a0::FUN_002359a0(int a) {
    m = a;
    return 1;
}


// 0x002359b0 FUN_002359b0 (12 B): matches/0x002359b0.cpp
// sym: ?FUN_002359b0@Obj_2359b0@owners@@QAEDH@Z
char owners::Obj_2359b0::FUN_002359b0(int v) {
    *(int*)(m + 0x10) = v;
    return 1;
}

namespace fn_f7988f86 {

// 0x00235a00 FUN_00235a00 (19 B): matches/0x00235a00.cpp
// sym: ?FUN_00235a00@fn_f7988f86@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00235a00(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e5bdc), ((char*)&DAT_004e5be0));
}

} // namespace fn_f7988f86
