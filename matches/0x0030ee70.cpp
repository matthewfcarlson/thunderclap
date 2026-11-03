#include "gen/owners.h"
struct B_30ee70 {
    void F(int);
};
void owners::A_30ee70::FUN_0030ee70(hulk_intptr x) {
    Init();
    ((B_30ee70*)((char*)this + 0x68))->F(((int)x));
    *(int*)((char*)this + 0xbc) = 1;
    Finish();
}