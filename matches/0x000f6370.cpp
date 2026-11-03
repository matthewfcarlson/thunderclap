#include "gen/owners.h"
struct API {
    int B(int, int);
};
struct V {
    int a;
    int b;
    int c;
};
struct S_f6370 {
    API* api;
    int b;
    int c;
    int d;
    V Target();
};
V S_f6370::Target() {
    V local;
    ((owners::C_284820 *)api)->FUN_00284820((hulk_intptr)0);
    ((owners::Obj_2848b0 *)api)->FUN_002848b0((hulk_intptr)(api->B(c, d)), 0, (int*)&local);
    return local;
}
