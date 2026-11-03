#include "gen/global.h"
#include "gen/owners.h"

struct A_17c40 {
    void* first();
};
struct B_17c40 {
    B_17c40* second();
};

bool CSnapToWallAction::vfunc_7(int arg) {
    B_17c40* b = (B_17c40*)(*(A_17c40 * *)&this->f_1c)->first();
    b = b->second();
    if (*(char*)((char*)(*(B_17c40 * *)&this->f_20) + 0x24)) {
        ((owners::C_359c0 *)b)->FUN_000359c0(1);
        return true;
    }
    ((owners::C_359c0 *)b)->FUN_000359c0(3);
    return true;
}
