#include "gen/owners.h"
struct Sub_d7d60 {
};
struct Obj_d7d60 {
    char pad[0x10];
    Sub_d7d60 sub;
    char pad2[0x23];
    unsigned char flag;
    Obj_d7d60* Run();
};
Obj_d7d60* Obj_d7d60::Run() {
    ((owners::State_f7930 *)&sub)->FUN_000f7930();
    flag = 0;
    return this;
}