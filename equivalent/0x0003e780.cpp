// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 33/34, incomplete)
// FUN_0003e780 @ 0x0003e780
extern "C" double sqrt(double);
extern "C" double cos(double);
extern "C" double fabs(double);

struct Vec3_3e780 {
    float x, y, z;
    float FUN_0022d110();
};

struct Elem64 {
    char pad0[0x30];
    Vec3_3e780 pos;
    char pad1[0x40 - 0x3c];
};

struct ElemArray_3e780 {
    char pad[0x1c];
    Elem64 *items;
};

struct FlagHolder {
    char pad[0x72];
    char flag;
};

struct Slot_3e780 {
    char pad[0x74];
    FlagHolder *holder;
};

struct Locator {
    void FUN_00222120(Vec3_3e780 *out);
};

struct Anchor_3e780 {
    char pad[0x10];
    Locator loc;
};

struct AnchorOwner {
    Anchor_3e780 *FUN_00059a40();
};

struct Hasher {
    unsigned __int64 FUN_000443c0();
};

struct Gesture {
    char pad[8];
    unsigned __int64 id;
};

struct Probe_3e780 {
    Slot_3e780 *FUN_001d72e0();
};

struct Actor_3e780 {
    char pad0[0x10];
    AnchorOwner *owner;
    char pad1[0xdc - 0x14];
    Gesture *gesture;
    char pad2[0x11c - 0xe0];
    Hasher *hasher;
    ElemArray_3e780 *elems;
    char pad3[0x128 - 0x124];
    Probe_3e780 *probe;
    Slot_3e780 *slot;
    char pad4[0x1cc8 - 0x130];
    float angle;
    char pad5[0x1f54 - 0x1ccc];
    unsigned index;

    void FUN_00035fa0(int mode);
    bool FUN_0003e780(void *a1, Vec3_3e780 *target, float maxDist, bool *outA, bool *outB);
};

unsigned __int64 __cdecl FUN_0027b020(const char *s);
bool __cdecl FUN_00036b10(void *a1, Vec3_3e780 *p, Vec3_3e780 *target, Vec3_3e780 *z, Vec3_3e780 *tmp, bool *outA, float *ang);

struct Frame_3e780 {
    float dot;
    float dist;
    Vec3_3e780 D;
    Vec3_3e780 P;
    Vec3_3e780 W;
    Vec3_3e780 tmp;
    Vec3_3e780 Z;
};

bool Actor_3e780::FUN_0003e780(void *a1, Vec3_3e780 *target, float maxDist, bool *outA, bool *outB)
{
    *outA = false;
    *outB = false;
    if (index == 0xffff)
        return false;

    Frame_3e780 fr;
    Vec3_3e780 &P = fr.P;
    Vec3_3e780 &D = fr.D;
    Vec3_3e780 &W = fr.W;
    Vec3_3e780 &tmp = fr.tmp;
    P = elems->items[index].pos;
    if (hasher->FUN_000443c0() == FUN_0027b020("tank"))
        P.y = P.y + 1.0f;

    D.x = target->x - P.x;
    D.y = 0.0f;
    D.z = target->z - P.z;
    float &dist = fr.dist;
    dist = (float)sqrt((double)(D.z * D.z + D.x * D.x));
    D.FUN_0022d110();

    Anchor_3e780 *g = owner->FUN_00059a40();
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
        Slot_3e780 *s = probe->FUN_001d72e0();
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
