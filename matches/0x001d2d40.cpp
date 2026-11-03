#include "gen/owners.h"
void f133d0(int, int);
void f13600(int, int);
int f12f00(int, int);
float f130e0(int, int);
void f12d80(int, int);
bool owners::Obj_1d2d40::FUN_001d2d40(hulk_intptr arg, float* out) {
    f133d0(field, ((int)arg));
    f13600(field, -2);
    bool result = true;
    if (f12f00(field, -1) != 3)
        result = false;
    if (result)
        *out = f130e0(field, -1);
    f12d80(field, -2);
    return result;
}