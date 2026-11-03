#include "gen/owners.h"
typedef unsigned char u8_1d1980;
typedef unsigned int u32_1d1980;
void f1(int, u32_1d1980);
void f2(int, int, int);
void f3(int, int);
bool owners::Obj_1d1980::FUN_001d1980(hulk_uintptr arg, u8_1d1980 flag) {
    int v = -3;
    if (flag)
        v = -10001;
    f1(member, ((u32_1d1980)arg));
    f2(member, 0, 0);
    f3(member, v);
    return true;
}
