#include "gen/global.h"

struct A_17c40 {
    void* first();
};
struct B_17c40 {
    B_17c40* second();
    void act(int);
};

bool CSnapToWallAction::vfunc_7(int arg) {
    B_17c40* b = (B_17c40*)(*(A_17c40 * *)&this->f_1c)->first();
    b = b->second();
    if (*(char*)((char*)(*(B_17c40 * *)&this->f_20) + 0x24)) {
        b->act(1);
        return true;
    }
    b->act(3);
    return true;
}
