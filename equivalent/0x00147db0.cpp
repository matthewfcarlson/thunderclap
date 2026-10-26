// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 8/8)
// hulkfight::motion::CivilianAttachAction::vfunc_3 @ 0x00147db0
// hulkfight::motion::CivilianAttachAction::vfunc_3 @ 0x00147db0
// equiv-map: ??0Name@@QAE@ABU0@@Z = 0x0027af30
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "decls/address.h"

struct Name {
    int lo;
    int hi;
    Name(const Name &o) throw();
    ~Name() throw();
};

struct Msg_147db0 {
    char data[0x20];
    Msg_147db0 *FUN_001c9b30(Name key);
};

struct Dispatcher_147db0 {
    void FUN_001cbc20(Msg_147db0 *m);
};

struct World {
    char pad0[0x30];
    Dispatcher_147db0 *dispatcher;
};

struct Target_147db0 {
    char pad0[8];
    Name name;
    char pad10[0x100 - 0x10];
    int f100;
    void FUN_00080cb0(int v);
};

struct Fighter_147db0 {
    char pad0[0x328];
    int f328;
    char pad32c[0x630 - 0x32c];
    Target_147db0 *target;
    char pad634[0x20a8 - 0x634];
    int f20a8;
    Target_147db0 *FUN_00036030();
    void FUN_0003b190(int v);
    void FUN_0003b160(Target_147db0 *t);
    void FUN_000393c0();
};

struct Holder_147db0 {
    Fighter_147db0 *FUN_00059a30();
};

struct Params_147db0 {
    Holder_147db0 *FUN_000592a0();
};

namespace hulkfight {
namespace motion {

}
}
bool hulkfight::motion::CivilianAttachAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    Fighter_147db0 *fighter = (*(Params_147db0 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
    if (fighter == 0)
        return false;
    Target_147db0 *target = fighter->FUN_00036030();
    if (target == 0)
        return false;

    fighter->FUN_0003b190(0);
    fighter->FUN_0003b160(target);
    target->FUN_00080cb0(5);

    Msg_147db0 msg;
    msg.FUN_001c9b30(target->name);
    DAT_004dd700->dispatcher->FUN_001cbc20(&msg);

    if (fighter->f20a8 >= 0 && fighter->f328 == target->f100)
        fighter->FUN_000393c0();
    return true;
}
