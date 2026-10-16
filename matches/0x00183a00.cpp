#include "gen/hulkfight.h"

typedef unsigned char u8;
struct Obj_183a00 {
    char pad[0x15];
    u8 flag;
};
struct PropActorToPropAction_nv_183a00 {
    void FUN_00181d30();
};

void hulkfight::motion::PropActorToPropAction::vfunc_4() {
    if ((*(Obj_183a00 * *)&this->f_1c)->flag)
        ((PropActorToPropAction_nv_183a00*)this)->FUN_00181d30();
}
