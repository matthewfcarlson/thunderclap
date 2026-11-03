#include "gen/owners.h"
struct Temp_265310 {
    char x[0x18];
    void f(int);
    int g(int, int);
};
hulk_intptr owners::Obj_265310::FUN_00265310(hulk_intptr param) {
    Temp_265310 t;
    t.f(value);
    return t.g(((int)param), 0);
}