// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::IntentionButtonDownAnyCondition::vfunc_6 @ 0x00166b40
namespace fight { class Params; }
class CFightParams;

class Holder {
public:
    char pad0[0x1f58];
    struct Slot { int state; int a; int b; } slots[11];
};
class Inner {
public:
    Holder* FUN_00059a30();
};
namespace fight {
class Params {
public:
    virtual void p0();
    Inner* FUN_000592a0();
};
}
class CFightParams : public fight::Params {
public:
    virtual void c0();
};

namespace hulkfight { namespace motion {
class IntentionButtonDownAnyCondition {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int unused1, fight::Params* params, int unused2);
    char pad04[8];
    char expected;
};

bool IntentionButtonDownAnyCondition::vfunc_6(int unused1, fight::Params* params, int unused2) {
    if (!dynamic_cast<CFightParams*>(params))
        return false;
    Holder* h = params->FUN_000592a0()->FUN_00059a30();
    char down = 0;
    for (int i = 0; i < 11; i++) {
        if (h->slots[i].state == 2 || h->slots[i].state == 1) {
            down = 1;
            break;
        }
    }
    return down == expected;
}
}}
