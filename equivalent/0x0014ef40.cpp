// STATUS: equivalent (tools/equiv.py level 3: 343 inputs, branch coverage 14/14)
// hulkfight::motion::HitPauseAction::vfunc_3 @ 0x0014ef40
struct Fighter {
    char pad[4];
};
Fighter *__fastcall FUN_000592a0(void *owner);

struct Key {
    char pad00[0x10];
    unsigned int lo;
    unsigned int hi;
};

struct Pausable {
    void FUN_00035b70(int zero, unsigned int lo, unsigned int hi);
};

struct Attached {
    char pad00[0x148];
    Pausable *pausable148;
};

struct Slot {
    char pad00[8];
    Pausable *direct;
    int kind;
};
struct SlotHolder {
    char pad00[8];
    Attached *attached;
    int kind;
};

struct Stats {
    char pad00[0x200];
    SlotHolder *slots[64];
    int slotCount;
};
Stats *__fastcall FUN_00059a30(Fighter *f);

class Action {
public:
    virtual void vfunc_0();
};

namespace hulkfight {
namespace motion {

class HitPauseAction {
public:
    virtual void vfunc_0();
    char pad04[0x18];
    Key *key;
    void *owner;
    bool vfunc_3(int a, int b);
};

bool HitPauseAction::vfunc_3(int a, int b)
{
    Stats *stats = FUN_00059a30(FUN_000592a0(owner));
    int count = stats->slotCount;
    if (count > 0) {
        unsigned int lo = key->lo;
        unsigned int hi = key->hi;
        for (int i = 0; i < count; i++) {
            SlotHolder *holder = stats->slots[i];
            if (holder == 0)
                continue;
            Pausable *p;
            if (holder->kind == 1)
                p = (Pausable *)holder->attached;
            else if (holder->kind == 5) {
                p = 0;
                if (holder->attached != 0)
                    p = holder->attached->pausable148;
            } else
                continue;
            if (p != 0)
                p->FUN_00035b70(0, lo, hi);
        }
    }
    return false;
}

}
}
