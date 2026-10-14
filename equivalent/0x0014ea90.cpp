// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 18/18)
// hulkfight::motion::CollisionTargetTypeCondition::vfunc_6 @ 0x0014ea90
namespace fight { class Params; }
class CFightParams;

struct Stats {
    char pad0[0xc];
    int value;
};
struct Info {
    char pad0[0x50];
    Stats* stats;
};

namespace fight {
class Params {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual Info* GetInfo();
};
}
class CFightParams : public fight::Params {
public:
    virtual void c0();
};

namespace hulkfight { namespace motion {
class CollisionTargetTypeCondition {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int unused1, fight::Params* params, int unused2);
    char pad04[8];
    int compare;     // 0: equal, 1: not equal
    int kind;        // 0 -> type 1, 1 -> type 5
};

bool CollisionTargetTypeCondition::vfunc_6(int unused1, fight::Params* params, int unused2) {
    if (!dynamic_cast<CFightParams*>(params))
        return false;
    Info* info = params->GetInfo();
    if (!info)
        return false;
    Stats* stats = info->stats;
    if (!stats)
        return false;
    int actual = stats->value;
    int expected = 0;
    switch (kind) {
    case 0:
        expected = 1;
        break;
    case 1:
        expected = 5;
        break;
    }
    switch (compare) {
    case 0:
        return expected == actual;
    case 1:
        return expected != actual;
    }
    return false;
}
}}
