#include "gen/hulkfight.h"

typedef unsigned char u8;
struct Inner_10e000;
struct Mid_10e000 {
    int a;
};
struct Ret_10e000 {
    void last();
};
struct Obj_10e000 {
    Inner_10e000* getA();
};
struct Inner_10e000 {
    Mid_10e000* getB();
};
struct State_10e000 {
    char pad[0x14];
    u8 flag;
};
Ret_10e000* FUN_678d0();

void hulkfight::ai::TokenAction::vfunc_4() {
    if ((*(Obj_10e000 * *)&this->f_20)) {
        Inner_10e000* a = (*(Obj_10e000 * *)&this->f_20)->getA();
        Mid_10e000* b = a->getB();
        *((u8*)b + 0x1b84) = 0;
        if ((*(State_10e000 * *)&this->f_1c)->flag) {
            FUN_678d0()->last();
        }
    }
}
