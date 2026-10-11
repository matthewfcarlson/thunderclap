// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 38/38)
// FUN_001d7b80 @ 0x001d7b80
struct Vec3 {
    float x, y, z;
};

struct Key {
    unsigned int lo;
    unsigned int hi;
};

struct Flags {
    char pad00[0x68];
    unsigned char b68;
    unsigned char b69;
};

struct State {
    char pad00[8];
    void *owner;              // 0x08
    int mode;                 // 0x0c
    char pad10[0x74 - 0x10];
    Flags *flags;             // 0x74
};

struct Xform {
    char pad00[0x30];
    Vec3 pos;                 // 0x30
};

class Part {
public:
    char pad00[0x10];
    State *state;             // 0x10
    Xform *FUN_002fc6f0();
};

class Locator {
public:
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3();
    virtual Vec3 *l4();
};

struct Matched {
    char pad00[8];
    unsigned int lo;          // 0x08
    unsigned int hi;          // 0x0c
};

struct Recorder {
    void FUN_00066a10();
};

struct Manager {
    char pad00[0xc];
    struct Listener *listener; // 0x0c
};

class Actor;
struct Listener {
    void FUN_001dc170(Actor *a, int flag);
};

extern Manager *DAT_004dd700;
extern Key DAT_004e2520;
extern Key DAT_004e2528;
extern Key DAT_004e2530;
extern Key DAT_004e2550;
extern Key DAT_004e2558;

Recorder *__stdcall FUN_000678d0(Key *key);

class Actor {
public:
    char pad000[8];
    Key key;                  // 0x08
    char pad10[0xa0 - 0x10];
    Part *part;               // 0xa0
    char pada4[0xb0 - 0xa4];
    unsigned char hasHook;    // 0xb0
    char padb1[0xec - 0xb1];
    Matched *match;           // 0xec
    int fF0;
    int fF4;
    unsigned char fF8;
    char padF9[3];
    int fFC;
    char pad100[0x11c - 0x100];
    Locator *locator;         // 0x11c
    char pad120[0x164 - 0x120];
    Vec3 posA;                // 0x164
    Vec3 posB;                // 0x170
    Vec3 posC;                // 0x17c
    Vec3 posD;                // 0x188
    char pad194[0x1a0 - 0x194];
    unsigned char fired;      // 0x1a0

    void FUN_0027de50(int a, Actor *b);
    void FUN_001d7b80(int a, int b);
};

void Actor::FUN_001d7b80(int a, int b)
{
    fFC = 0;
    if (part) {
        State *st = part->state;
        if (st) {
            st->mode = 5;
            st->owner = this;
            Flags *fl = st->flags;
            if (fl) {
                fl->b69 = 0;
                fl->b68 = 0;
            }
        }
    }
    if (hasHook)
        FUN_0027de50(5, this);

    const Vec3 *src;
    if (part)
        src = &part->FUN_002fc6f0()->pos;
    else
        src = locator->l4();
    posB = *src;
    posA = posB;

    if (part)
        src = &part->FUN_002fc6f0()->pos;
    else
        src = locator->l4();
    posC = *src;

    if (part)
        src = &part->FUN_002fc6f0()->pos;
    else
        src = locator->l4();
    posD = *src;

    Matched *m = match;
    fF0 = 0;
    fF4 = 0;
    fF8 = 0;
    if (m) {
        if (m->lo == DAT_004e2530.lo && m->hi == DAT_004e2530.hi) {
            if (key.lo == DAT_004e2528.lo && key.hi == DAT_004e2528.hi)
                return;
            if (key.lo == DAT_004e2550.lo && key.hi == DAT_004e2550.hi)
                return;
            if (key.lo == DAT_004e2558.lo && key.hi == DAT_004e2558.hi)
                return;
            if (key.lo == DAT_004e2520.lo && key.hi == DAT_004e2520.hi)
                return;
            Key k;
            k.lo = key.lo;
            k.hi = key.hi;
            FUN_000678d0(&k)->FUN_00066a10();
            fired = 1;
            Listener *l = DAT_004dd700->listener;
            if (l)
                l->FUN_001dc170(this, 1);
        }
    }
}
