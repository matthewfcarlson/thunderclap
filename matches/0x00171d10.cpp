#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct B_171d10 {
    int go();
};
struct A_171d10 {
    B_171d10* go();
};
struct C_171d10 {
    void go(const char*);
};
struct D {
    void go(void*, int);
};

bool hulkfight::motion::TeleportRelativeAction::vfunc_3(hulk_intptr __p0, hulk_intptr ) {
    hulk_intptr r = (*(A_171d10 * *)&this->f_20)->go()->go();
    ((C_171d10*)((char*)this + 0x28))->go("teleport_failed");
    if (!(*(A_171d10 * *)&this->f_20))
        return false;
    if (r)
        ((D*)r)->go((char*)this + 0x28, 0);
    return true;
}
