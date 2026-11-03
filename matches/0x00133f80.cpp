#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

struct A_133f80 {
    A_133f80* Second();
};

bool hulkfight::motion::HoverAction::vfunc_5(hulk_intptr param, int unused) {
    if (param == 0) {
        A_133f80* p = ((A_133f80 *)((owners::Object_592a0 *)(((A_133f80*)*(void**)((char*)this + 0x20))))->FUN_000592a0());
        p = p->Second();
        if (this->f_1c > 0)
            ((owners::C_359c0 *)p)->FUN_000359c0(1);
        else
            ((owners::C_359c0 *)p)->FUN_000359c0(3);
    }
    return true;
}
