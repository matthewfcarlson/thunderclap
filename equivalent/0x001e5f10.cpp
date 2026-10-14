// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 46/46)
// CSPManager::vfunc_1 @ 0x001e5f10
// CSPManager::vfunc_1 @ 0x001e5f10
typedef unsigned __int64 Key;
extern Key __cdecl FUN_002672f0(const char *, Key) throw();

struct NameHolder {
    char data[8];
    void FUN_0027b040(const char *name);
};
struct IdHolder {
    char data[8];
    void FUN_0027af60(Key k);
};
struct Quat {
    float x, y, z, w;
    void FUN_0022b220(float x, float y, float z);
};
struct QSlot {
    char data[6];
    void FUN_001db780(Quat *q);
};

struct Element {
    char pad0[0xc];
    const char *name;
    const char *FUN_003365b0(const char *attr);
    void FUN_00336600(const char *attr, float *x, float *y, float *z);
    void FUN_003364c0(const char *attr, int *out);
    void FUN_003366f0(const char *attr, int def, int *out);
    void FUN_00336490(const char *attr, char *out);
    void FUN_003364f0(const char *attr, int *out);
};

struct Unlocks {
    char FUN_00092940(int id);
    char FUN_00092860(int idx);
};
struct Sub80 {
    int FUN_00088fa0();
};
struct OptMain {
    char pad[0x80];
    Sub80 s80;
};
struct OptHolder {
    OptMain *FUN_00086310();
    Unlocks *FUN_00086340();
};
struct Sub2c {
    char FUN_001cd010();
};
struct Globals {
    char pad[0x2c];
    Sub2c *sub2c;
    char pad30[0x54 - 0x30];
    OptHolder *opt;
};
extern Globals *DAT_004dd700;

struct SPEntry {
    NameHolder name;     // 0
    IdHolder id;         // 8
    QSlot q;             // 0x10
    short rooms;         // 0x16
    char pad18[4];
    int i1c;
    short s20;
    short s22;
    char pad24[2];
    char initial;        // 0x26
    char pad27;
    void FUN_001dbba0();
};

struct Frame {
    char pad10[3];
    char persistent;
    int unlockable, collision, fade, initialState, rooms, usage;
    Key key;
    float rx, ry, rz;
    float tx, ty, tz;
    Quat q;
};

struct SPLink {
    float x, y, z, w;
    short s10;
    short s12;
};

class CSPManager {
public:
    virtual void vfunc_0();
    virtual bool vfunc_1(Element *e);
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x608 - 4];
    SPEntry entries[0x800];
    SPLink links[0x800];
    int entryCount;
    char pad1e60c[8];
    int linkCount;
    int FUN_001dbfe0(const char *name);
    void FUN_001e5bc0(int idx);
    void FUN_001dbe60();
};

bool CSPManager::vfunc_1(Element *e)
{
    if (linkCount >= 0x800)
        return false;
    Frame f;
    f.unlockable = -1;
    f.collision = 0;
    f.fade = 0;
    f.initialState = 0;
    f.rooms = 0;
    f.persistent = 0;
    const char *name = e->name;
    const char *drawable = e->FUN_003365b0("drawable");
    e->FUN_00336600("translate", &f.tx, &f.ty, &f.tz);
    e->FUN_00336600("rotate", &f.rx, &f.ry, &f.rz);
    e->FUN_003364c0("InitialState", &f.initialState);
    e->FUN_003366f0("Rooms", 0, &f.rooms);
    e->FUN_00336490("Persistent", &f.persistent);
    e->FUN_003364c0("CollisionPropIndex", &f.collision);
    e->FUN_003364c0("FadeRange", &f.fade);
    e->FUN_003364c0("UnlockableIndex", &f.unlockable);
    Key key = FUN_002672f0(drawable, 0);
    key = FUN_002672f0("_", key);
    key = FUN_002672f0(drawable, key);
    static Key streetLight = FUN_002672f0("streetLight_streetLight", 0);
    Unlocks *u = DAT_004dd700->opt->FUN_00086340();
    if (key == streetLight && u->FUN_00092940(0x1a))
        key = FUN_002672f0("gorilla_gorilla", 0);
    if (DAT_004dd700->opt->FUN_00086310()->s80.FUN_00088fa0() != 8 && f.unlockable >= 0) {
        if (!DAT_004dd700->opt->FUN_00086340()->FUN_00092860(f.unlockable))
            return false;
    }
    e->FUN_003364f0("Usage", &f.usage);
    if (f.usage == 3)
        f.persistent = 1;
    if (DAT_004dd700->sub2c->FUN_001cd010()) {
        int idx = FUN_001dbfe0(name);
        if (idx != -1)
            FUN_001e5bc0(idx);
    }
    if (FUN_001dbfe0(name) != -1)
        return false;
    f.rx = f.rx * -0.01745329238474369f;
    f.ry = f.ry * -0.01745329238474369f;
    f.rz = f.rz * 0.01745329238474369f;
    f.tz = -f.tz;
    f.q.FUN_0022b220(f.rx, f.ry, f.rz);
    entries[entryCount].FUN_001dbba0();
    SPLink *l = &links[linkCount];
    l->x = 0;
    l->y = 0;
    l->z = 0;
    l->w = 3.4028235e+38f;
    l->s10 = 0;
    l->s12 = -1;
    entries[entryCount].s22 = (short)linkCount;
    links[linkCount].s12 = (short)entryCount;
    entries[entryCount].name.FUN_0027b040(name);
    entries[entryCount].id.FUN_0027af60(key);
    entries[entryCount].initial = (char)f.initialState;
    entries[entryCount].i1c = 0;
    entries[entryCount].q.FUN_001db780(&f.q);
    entries[entryCount].s20 = (short)0xfde8;
    entries[entryCount].rooms = (short)f.rooms;
    l = &links[linkCount];
    l->x = f.tx;
    l->y = f.ty;
    l->z = f.tz;
    unsigned char *flags = (unsigned char *)&links[linkCount].s10;
    if (f.persistent)
        flags[0] |= 8;
    if (f.collision != 0) {
        if (f.collision == 3 || f.collision == 1)
            flags[1] |= 1;
        if (f.collision == 3 || f.collision == 2)
            flags[1] |= 2;
    }
    if (f.fade != 0) {
        if (f.fade == 3 || f.fade == 1)
            flags[1] |= 4;
        if (f.fade == 3 || f.fade == 2)
            flags[1] |= 8;
    }
    linkCount++;
    FUN_001dbe60();
    return true;
}
