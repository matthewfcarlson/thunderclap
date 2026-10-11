// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 38/40, incomplete)
// hulkfight::motion::SmartPropGrabbableCondition::vfunc_6 @ 0x00183670
struct Entry {
    int pad0[2];
    int id;
    int pad0c;
};

struct Group {
    char pad0[0x24];
    int count;
    Entry *entries;
};

struct Table {
    char pad0[0x1c];
    Group **groups;
};

class Listener {
public:
    int FUN_001d4de0();
    char FUN_001d4e20();
    int FUN_001d5e80(int x);
    int FUN_001d5dd0(int x);
    Table *FUN_001d4fc0();
};

struct Info {
    char pad0[0x40];
    int index;
    char pad44[0xec - 0x44];
    Listener *listener;
};

struct Target {
    char pad0[8];
    Info *info;
};

struct Stats {
    char pad0[0x3a4];
    Target *target;
};

struct Fighter { char pad[4]; };
Fighter *__fastcall FUN_000592a0(void *owner);
Stats *__fastcall FUN_00059a30(Fighter *f);

namespace fight {
class Params {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    void FUN_00059790(Target *t);
};
}

class CFightParams : public fight::Params {
public:
    virtual void v3();
    virtual void v4();
};

class SmartPropGrabbableCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg1, fight::Params *params, int arg3);
    char pad04[8];
    char useId;
    char pad0d[3];
    int id;
    char useFlag;
    char flag;
    char useValue;
    char pad17;
    int value;
    char useOther;
    char pad1d[3];
    int other;
    char useIndex;
    char pad25[3];
    int wanted;
};

bool SmartPropGrabbableCondition::vfunc_6(int arg1, fight::Params *params, int arg3)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;

    Stats *stats = FUN_00059a30(FUN_000592a0(params));
    Target *target = stats->target;
    if (target == 0)
        return false;

    bool ok = true;
    char useId = this->useId;
    if (useId || this->useFlag || this->useValue || this->useOther) {
        Info *info = target->info;
        Listener *listener = info->listener;
        if (useId) {
            int want = this->id;
            ok = listener->FUN_001d4de0() == want;
        }
        if (this->useFlag) {
            char want = this->flag;
            ok &= listener->FUN_001d4e20() == want;
        }
        if (this->useValue) {
            int want = this->value;
            ok &= listener->FUN_001d5e80(info->index) == want;
        }
        if (this->useOther) {
            int want = this->other;
            ok &= listener->FUN_001d5dd0(info->index) == want;
        }
        if (this->useIndex) {
            int idx = info->index;
            bool found = false;
            if (idx >= 0) {
                Group *g = listener->FUN_001d4fc0()->groups[idx];
                int n = g->count;
                if (n > 0) {
                    Entry *e = g->entries;
                    int want = this->wanted;
                    for (int i = 0; i < n; i++) {
                        if (e[i].id == want) {
                            found = true;
                            break;
                        }
                    }
                }
            }
            ok &= found;
        }
    }
    if (ok)
        params->FUN_00059790(target);
    return ok;
}
