#include "gen/hulkfight.h"
#include "gen/owners.h"

struct A_1719f0 {
    char pad[0x14];
    unsigned char flag;
};
struct B_1719f0 {
    char pad[0x1e58];
    int value;
};
struct First_1719f0 {
};
struct Second_1719f0 {
    B_1719f0* g();
};

void hulkfight::motion::ChargeClearAction::vfunc_4() {
    if (!((A_1719f0*)(*(void * *)&this->f_1c))->flag) {
        B_1719f0* x = ((B_1719f0 *)((owners::Object_592a0 *)(((First_1719f0*)(*(void * *)&this->f_20))))->FUN_000592a0());
        B_1719f0* y = ((Second_1719f0*)x)->g();
        y->value = 0;
    }
}
