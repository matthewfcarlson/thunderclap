// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 21/24, incomplete)
// hulkfight::ai::MotionClosestWaypointAction::vfunc_3 @ 0x00117ab0
extern "C" double sqrt(double);

struct Vec3 { float x, y, z; };

struct WaypointList {
    char pad[0x14];
    int count;
    Vec3 *FUN_00106160(int index);
};

struct Registry {
    WaypointList *FUN_00106230(int key);
};

struct Globals {
    char pad[0x18];
    Registry *registry;
};
extern Globals *DAT_004dd700;

struct Locator {
    void FUN_00059a50(Vec3 *out);
};

struct Selector {
    void *FUN_000fdc40();
    int FUN_001034d0();
};

struct Name {
    void FUN_0027b040(const char *s);
};

struct Fighter {
    char pad0[0x10];
    Locator *locator;
    char pad1[0x1ca0 - 0x14];
    Selector *selector;
    char pad2[0x2140 - 0x1ca4];
    unsigned char flag2140;
    char pad3[8];
    unsigned char flag2149;
    void FUN_00036e70(Name *n, int v);
    int FUN_00036d30();
    void FUN_000353d0(Vec3 *p);
};

struct Owner {
    char pad[0x29];
    char enabled;
};

struct Finder {
    void *FUN_000592a0();
};
struct Finder2 {
    Fighter *FUN_00059a30();
};

class MotionClosestWaypointAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Owner *owner;
    Finder *finder;
    Vec3 savedPos;
    char pad30[0x3c - 0x30];
    Vec3 target;
    int index;
    char pad4c[0x58 - 0x4c];
    unsigned char savedFlag;
    char pad59[0x60 - 0x59];
    Name name;
};

bool MotionClosestWaypointAction::vfunc_3(int a, int b)
{
    Fighter *fighter = ((Finder2 *)finder->FUN_000592a0())->FUN_00059a30();
    float best;
    Vec3 *first;
    Vec3 firstCopy;
    Vec3 pos;
    Vec3 unused;
    WaypointList *list;
    int i;
    int count;

    index = 0;
    if (fighter == 0) {
        return false;
    }
    savedFlag = fighter->flag2140;
    fighter->locator->FUN_00059a50(&unused);
    fighter->locator->FUN_00059a50(&savedPos);
    fighter->flag2140 = 1;
    name.FUN_0027b040("waypoint_stuck");
    fighter->FUN_00036e70(&name, 0);

    Registry *reg = DAT_004dd700->registry;
    list = reg->FUN_00106230(fighter->FUN_00036d30());
    if (list == 0) {
        if (fighter->selector == 0 || fighter->selector->FUN_000fdc40() == 0) {
            return false;
        }
        Selector *sel = (Selector *)fighter->selector->FUN_000fdc40();
        reg = DAT_004dd700->registry;
        list = reg->FUN_00106230(sel->FUN_001034d0());
        if (list == 0) {
            return false;
        }
    }

    first = list->FUN_00106160(index);
    firstCopy = *first;
    fighter->locator->FUN_00059a50(&pos);
    {
        double dx = firstCopy.x - pos.x;
        double dy = firstCopy.y - pos.y;
        double dz = firstCopy.z - pos.z;
        best = (float)sqrt(dz * dz + dy * dy + dx * dx);
    }
    count = list->count;
    for (i = 1; i < count; i++) {
        Vec3 *v = list->FUN_00106160(i);
        volatile float dx = v->x - pos.x;
        double dy = v->y - pos.y;
        double dz = v->z - pos.z;
        double d = sqrt(dz * dz + dy * dy + dx * dx);
        if (d < best && d > 0.01) {
            best = (float)d;
            index = i;
        }
    }

    if (index != 0) {
        target = *list->FUN_00106160(index);
    } else {
        target = *first;
    }
    if (owner->enabled) {
        fighter->FUN_000353d0(&target);
    }
    fighter->flag2149 = 1;
    return true;
}
