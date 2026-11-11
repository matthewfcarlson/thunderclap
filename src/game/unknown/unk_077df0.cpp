// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077df0..0x00077f30 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f42fdcee {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f42fdcee {} using namespace fn_f42fdcee;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f42fdcee {
const float kFactor = 0.017453292f;
class Obj_77ed0 {
  public:
    char m0[0xc];
    int mVal;
    bool SetTimeBegin_00077ed0(int v);
};
class O_77ee0 {
  public:
    char pad[0x10];
    int m;
    char SetExplosion_00077ee0(int value);
};
struct Vec3 {
    float x, y, z;
};
class Obj {
    char pad[0x14];
    float x, y, z;

  public:
    bool SetOffset_00077ef0(const Vec3* p);
};

} // namespace fn_f42fdcee

// 0x00077df0 FUN_00077df0 (12 B): matches/0x00077df0.cpp
// sym: ?FUN_00077df0@Obj_77df0@owners@@QAE_NH@Z
bool owners::Obj_77df0::FUN_00077df0(int x) {
    value = x;
    return true;
}


// 0x00077e00 FUN_00077e00 (12 B): matches/0x00077e00.cpp
// sym: ?FUN_00077e00@C_77e00@owners@@QAE_NH@Z
bool owners::C_77e00::FUN_00077e00(int v) {
    mValue = v;
    return true;
}


// 0x00077e10 FUN_00077e10 (12 B): matches/0x00077e10.cpp
// sym: ?FUN_00077e10@X_77e10@owners@@QAEDH@Z
char owners::X_77e10::FUN_00077e10(int v) {
    m = v;
    return 1;
}


// 0x00077e20 FUN_00077e20 (18 B): matches/0x00077e20.cpp
// sym: ?FUN_00077e20@X_77e20@owners@@QAEDM@Z
char owners::X_77e20::FUN_00077e20(float v) {
    mVal = v * kFactor;
    return 1;
}


// 0x00077e40 FUN_00077e40 (18 B): matches/0x00077e40.cpp
// sym: ?FUN_00077e40@Obj_77e40@owners@@QAEDM@Z
char owners::Obj_77e40::FUN_00077e40(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}


// 0x00077e60 FUN_00077e60 (12 B): matches/0x00077e60.cpp
// sym: ?FUN_00077e60@X_77e60@owners@@QAE_NH@Z
bool owners::X_77e60::FUN_00077e60(int v) {
    m = v;
    return true;
}


// 0x00077e70 FUN_00077e70 (12 B): matches/0x00077e70.cpp
// sym: ?FUN_00077e70@A_77e70@owners@@QAE_NH@Z
bool owners::A_77e70::FUN_00077e70(int x) {
    mField = x;
    return true;
}


// 0x00077e80 FUN_00077e80 (18 B): matches/0x00077e80.cpp
// sym: ?FUN_00077e80@Target_77e80@owners@@QAEDM@Z
char owners::Target_77e80::FUN_00077e80(float x) {
    mAngle = x * 0.017453293f;
    return 1;
}


// 0x00077ea0 FUN_00077ea0 (12 B): matches/0x00077ea0.cpp
// sym: ?FUN_00077ea0@Obj_77ea0@owners@@QAEDH@Z
char owners::Obj_77ea0::FUN_00077ea0(int v) {
    m2c = v;
    return 1;
}


// 0x00077eb0 FUN_00077eb0 (12 B): matches/0x00077eb0.cpp
// sym: ?FUN_00077eb0@X_77eb0@owners@@QAE_NH@Z
bool owners::X_77eb0::FUN_00077eb0(int v) {
    m30 = v;
    return true;
}


// 0x00077ec0 FUN_00077ec0 (12 B): matches/0x00077ec0.cpp
// sym: ?FUN_00077ec0@Obj_77ec0@owners@@QAE_NH@Z
bool owners::Obj_77ec0::FUN_00077ec0(int x) {
    value = x;
    return true;
}

namespace fn_f42fdcee {

// 0x00077ed0 FUN_00077ed0 (12 B): matches/0x00077ed0.cpp
// sym: ?SetTimeBegin_00077ed0@Obj_77ed0@fn_f42fdcee@@QAE_NH@Z
bool Obj_77ed0::SetTimeBegin_00077ed0(int v) {
    mVal = v;
    return true;
}


// 0x00077ee0 FUN_00077ee0 (12 B): matches/0x00077ee0.cpp
// sym: ?SetExplosion_00077ee0@O_77ee0@fn_f42fdcee@@QAEDH@Z
char O_77ee0::SetExplosion_00077ee0(int value) {
    m = value;
    return 1;
}


// 0x00077ef0 FUN_00077ef0 (26 B): matches/0x00077ef0.cpp
// sym: ?SetOffset_00077ef0@Obj@fn_f42fdcee@@QAE_NPBUVec3@2@@Z
bool Obj::SetOffset_00077ef0(const Vec3* p) {
    x = p->x;
    y = p->y;
    z = p->z;
    return true;
}


// 0x00077f10 FUN_00077f10 (19 B): matches/0x00077f10.cpp
// sym: ?FUN_00077f10@fn_f42fdcee@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00077f10() {
    FUN_00234810(((char*)&DAT_004dd030), ((char*)&DAT_004dd034));
}

} // namespace fn_f42fdcee
