// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 33/34, incomplete)
// FUN_0003e780 @ 0x0003e780
extern "C" double sqrt(double);
extern "C" double cos(double);
extern "C" double fabs(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Elem64 {
    char pad0[0x30];
    Vec3 pos;
    char pad1[0x40 - 0x3c];
};

struct ElemArray {
    char pad[0x1c];
    Elem64 *items;
};

struct FlagHolder {
    char pad[0x72];
    char flag;
};

struct Slot {
    char pad[0x74];
    FlagHolder *holder;
};

struct Locator {
    void FUN_00222120(Vec3 *out);
};

struct Anchor {
    char pad[0x10];
    Locator loc;
};

struct AnchorOwner {
    Anchor *FUN_00059a40();
};

struct Hasher {
    unsigned __int64 FUN_000443c0();
};

struct Gesture {
    char pad[8];
    unsigned __int64 id;
};

struct Probe {
    Slot *FUN_001d72e0();
};

struct Actor {
    char pad0[0x10];
    AnchorOwner *owner;
    char pad1[0xdc - 0x14];
    Gesture *gesture;
    char pad2[0x11c - 0xe0];
    Hasher *hasher;
    ElemArray *elems;
    char pad3[0x128 - 0x124];
    Probe *probe;
    Slot *slot;
    char pad4[0x1cc8 - 0x130];
    float angle;
    char pad5[0x1f54 - 0x1ccc];
    unsigned index;

    void FUN_00035fa0(int mode);
    bool FUN_0003e780(void *a1, Vec3 *target, float maxDist, bool *outA, bool *outB);
};

unsigned __int64 __cdecl FUN_0027b020(const char *s);
bool __cdecl FUN_00036b10(void *a1, Vec3 *p, Vec3 *target, Vec3 *z, Vec3 *tmp, bool *outA, float *ang);

struct Frame {
    float dot;
    float dist;
    Vec3 D;
    Vec3 P;
    Vec3 W;
    Vec3 tmp;
    Vec3 Z;
};

bool Actor::FUN_0003e780(void *a1, Vec3 *target, float maxDist, bool *outA, bool *outB)
{
    *outA = false;
    *outB = false;
    if (index == 0xffff)
        return false;

    Frame fr;
    Vec3 &P = fr.P;
    Vec3 &D = fr.D;
    Vec3 &W = fr.W;
    Vec3 &tmp = fr.tmp;
    P = elems->items[index].pos;
    if (hasher->FUN_000443c0() == FUN_0027b020("tank"))
        P.y = P.y + 1.0f;

    D.x = target->x - P.x;
    D.y = 0.0f;
    D.z = target->z - P.z;
    float &dist = fr.dist;
    dist = (float)sqrt((double)(D.z * D.z + D.x * D.x));
    D.FUN_0022d110();

    Anchor *g = owner->FUN_00059a40();
    if (g) {
        g->loc.FUN_00222120(&tmp);
        W.x = tmp.x;
        W.z = tmp.z;
    }
    W.y = 0.0f;
    W.FUN_0022d110();

    float &dot = fr.dot;
    dot = W.z * D.z + W.x * D.x + W.y * D.y;
    float ang = angle * 0.008726646f;
    if (gesture) {
        unsigned __int64 gid = gesture->id;
        if (gid == FUN_0027b020("gesture_3"))
            ang = angle;
    }
    double c = cos((double)ang);

    if (!((double)dot > c)) {
        ang = (float)fabs((double)dot - c);
        if (!(ang <= 1e-05f)) {
            if (!(dist < 3.0f))
                return false;
        }
    }
    if ((double)dot < c)
        *outB = true;

    if (!(dist <= maxDist))
        return false;

    if (slot->holder)
        slot->holder->flag = 0;
    FUN_00035fa0(0);

    FlagHolder *saved = 0;
    char savedFlag = 0;
    if (probe) {
        Slot *s = probe->FUN_001d72e0();
        saved = s->holder;
        if (saved) {
            savedFlag = saved->flag;
            saved->flag = 0;
        }
    }
    bool result = FUN_00036b10(a1, &P, target, &fr.Z, &tmp, outA, &ang);
    if (slot->holder)
        slot->holder->flag = 1;
    FUN_00035fa0(1);
    if (saved)
        saved->flag = savedFlag;
    return result;
}
