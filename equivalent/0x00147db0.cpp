// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::CivilianAttachAction::vfunc_3 @ 0x00147db0
// hulkfight::motion::CivilianAttachAction::vfunc_3 @ 0x00147db0
// equiv-map: ??0Name@@QAE@ABU0@@Z = 0x0027af30
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
struct Name {
    int lo;
    int hi;
    Name(const Name &o) throw();
    ~Name() throw();
};

struct Msg {
    char data[0x20];
    Msg *FUN_001c9b30(Name key);
};

struct Dispatcher {
    void FUN_001cbc20(Msg *m);
};

struct System {
    char pad0[0x30];
    Dispatcher *dispatcher;
};
extern System *DAT_004dd700;

struct Target {
    char pad0[8];
    Name name;
    char pad10[0x100 - 0x10];
    int f100;
    void FUN_00080cb0(int v);
};

struct Fighter {
    char pad0[0x328];
    int f328;
    char pad32c[0x630 - 0x32c];
    Target *target;
    char pad634[0x20a8 - 0x634];
    int f20a8;
    Target *FUN_00036030();
    void FUN_0003b190(int v);
    void FUN_0003b160(Target *t);
    void FUN_000393c0();
};

struct Holder {
    Fighter *FUN_00059a30();
};

struct Params {
    Holder *FUN_000592a0();
};

namespace hulkfight {
namespace motion {

class CivilianAttachAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c];
    Params *owner;  // 0x20
};

bool CivilianAttachAction::vfunc_3(int a, int b)
{
    Fighter *fighter = owner->FUN_000592a0()->FUN_00059a30();
    if (fighter == 0)
        return false;
    Target *target = fighter->FUN_00036030();
    if (target == 0)
        return false;

    fighter->FUN_0003b190(0);
    fighter->FUN_0003b160(target);
    target->FUN_00080cb0(5);

    Msg msg;
    msg.FUN_001c9b30(target->name);
    DAT_004dd700->dispatcher->FUN_001cbc20(&msg);

    if (fighter->f20a8 >= 0 && fighter->f328 == target->f100)
        fighter->FUN_000393c0();
    return true;
}

}
}
