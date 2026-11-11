// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001721f0..0x00172290 (kind game, layer game, confidence medium), dominant class hulkfight::motion::TargetIconDistanceAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8ae5d41 {
#define TREE_TU_END }
namespace fn_f8ae5d41 {} using namespace fn_f8ae5d41;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f8ae5d41 {
class Holder_1721f0 {
  public:
    int second_00059a30();
};
struct Player_172220 {
    char pad[0x1e58];
    float scale;
};
struct Hero_172220 {
    char pad[0x124];
    Player_172220* player;
    char pad128[0x33c - 0x128];
    float value;
    void FUN_00025240(int v);
};
} // namespace fn_f8ae5d41
struct World {
    char pad[0x20];
    Hero_172220* hero;
};
namespace fn_f8ae5d41 {
struct Game_172220 {
    Player_172220* FUN_00059a30();
};
struct Holder_172220 {
};
struct Range_172220 {
    char pad[0x14];
    float a;
    float b;
    int code;
};

} // namespace fn_f8ae5d41

// 0x001721f0 hulkfight::motion::SuckInPropsAction::vfunc_3 (32 B): matches/0x001721f0.cpp
// sym: ?vfunc_3@SuckInPropsAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::SuckInPropsAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    hulk_intptr value = ((int)((owners::Object_592a0 *)((*(Holder_1721f0 * *)&this->f_20)))->FUN_000592a0());
    if (value == 0)
        return false;
    if (((Holder_1721f0*)value)->second_00059a30() == 0)
        return false;
    return true;
}

namespace fn_f8ae5d41 {

// 0x00172210 hulkfight::motion::SuckInPropsAction::vfunc_4 (1 B): matches/0x00172210.cpp
// sym: ?FUN_00172210@fn_f8ae5d41@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00172210() {}

} // namespace fn_f8ae5d41

// 0x00172220 hulkfight::motion::TargetIconDistanceAction::vfunc_5 (102 B): equivalent/0x00172220.cpp
// sym: ?vfunc_5@TargetIconDistanceAction@motion@hulkfight@@UAE_NHH@Z @5aa283c2d94d @wc11b87e82229
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::TargetIconDistanceAction::vfunc_5 @ 0x00172220
bool hulkfight::motion::TargetIconDistanceAction::vfunc_5(hulk_intptr arg, int unused) {
    if (arg != 0)
        return (bool)(1);
    Game_172220* g = ((Game_172220 *)((owners::Object_592a0 *)((*(Holder_172220 * *)&this->f_20)))->FUN_000592a0());
    if (g == 0)
        return (bool)(0);
    Player_172220* p = g->FUN_00059a30();
    if (p == 0)
        return (bool)(0);
    Hero_172220* h = DAT_004dd700->hero;
    if (p != h->player)
        return (bool)(0);
    h->value = ((*(Range_172220 * *)&this->f_1c)->b - (*(Range_172220 * *)&this->f_1c)->a) * p->scale + (*(Range_172220 * *)&this->f_1c)->a;
    h->FUN_00025240((*(Range_172220 * *)&this->f_1c)->code);
    return (bool)(1);
}

