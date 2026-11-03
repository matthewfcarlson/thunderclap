#include "gen/owners.h"
struct R {
    int a;
    int b;
};
R __cdecl FUN_002672f0(int a, int b, int c);
hulk_intptr owners::Obj_259f0::FUN_000259f0(hulk_intptr a) {
    R r = FUN_002672f0(((int)a), 0, 0);
    return Sub(r.a, r.b);
}
