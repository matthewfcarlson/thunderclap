#include "gen/hulkfight.h"
#include "gen/owners.h"

struct C_1725c0 {
    void* a;
    void* f59a30();
    void f373e0(int);
};

void hulkfight::motion::MoveJointAction::vfunc_4() {
    C_1725c0* p = (C_1725c0*)(*(C_1725c0 * *)&this->f_20);
    p = (C_1725c0*)((void *)((owners::Object_592a0 *)p)->FUN_000592a0());
    p = (C_1725c0*)p->f59a30();
    p->f373e0(1);
}
