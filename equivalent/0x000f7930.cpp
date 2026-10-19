// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_000f7930 @ 0x000f7930
#include "decls/data/game/global.h"

struct State {
    int value;
    bool flag;
    char pad5[3];
    float scale;
    int fieldC;
    int field10;
    int field14;
    bool flag18;
    char pad19[3];
    float amount;
    int field20;
    State* FUN_000f7930();
};
State* State::FUN_000f7930() {
    scale = (*(float*)&DAT_004a1734);
    field10 = 0;
    field14 = -1;
    value = 0;
    flag = false;
    fieldC = 0;
    field20 = -1;
    amount = 20.0f;
    flag18 = false;
    return this;
}