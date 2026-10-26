// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::TargetIconDistanceAction::vfunc_5 @ 0x00172220
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "decls/address.h"

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
struct World {
    char pad[0x20];
    Hero_172220* hero;
};
struct Game_172220 {
    Player_172220* FUN_00059a30();
};
struct Holder_172220 {
    Game_172220* FUN_000592a0();
};
struct Range_172220 {
    char pad[0x14];
    float a;
    float b;
    int code;
};

bool hulkfight::motion::TargetIconDistanceAction::vfunc_5(hulk_intptr arg, int unused) {
    if (arg != 0)
        return (bool)(1);
    Game_172220* g = (*(Holder_172220 * *)&this->f_20)->FUN_000592a0();
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
