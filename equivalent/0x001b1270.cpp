// STATUS: equivalent (tools/equiv.py level 3: 3064 inputs, branch coverage 50/56, incomplete)
// FUN_001b1270 @ 0x001b1270
struct Vec3 {
    float x, y, z;
};

struct Body {
    char pad00[0x50];
    Vec3 vel;
};

struct Contact {
    char pad00[0x18];
    Vec3 f18;
    char pad24[0x2c - 0x24];
    Vec3 f2c;
    Vec3 f38;
};

struct Slot {
    unsigned __int64 FUN_001d4f70();
    int FUN_001d5e80(int id);
};

struct Joint {
    char FUN_001b6e90(Body* other);
    void FUN_001b6e60(Body* other);
};

struct Sink {
    void FUN_001cbd10(const char* name);
};

struct Game {
    char pad00[0x30];
    Sink* sink;
};

extern Game* DAT_004dd700;
extern unsigned __int64 DAT_004e1828;

struct Actor {
    char pad00[0x40];
    int id;
    char pad44[0xec - 0x44];
    Slot* slot;
    char padf0[0x118 - 0xf0];
    int f118;
    char pad11c[0x1a4 - 0x11c];
    Joint joint;
    char pad1a4[0x1c9 - 0x1a4 - sizeof(Joint)];
    char flag;
    int FUN_001d72e0();
    int FUN_001d73f0();
    float FUN_001d6670();
    float FUN_001afb00();
    void FUN_001d66b0(Vec3* a, Vec3* b);
    void FUN_001d6ec0(int a, int b, int c);
    void FUN_001d8d90(int v);
    void FUN_001d71e0(int v);
};

extern "C" int __cdecl FUN_0034483c();

int __stdcall FUN_001b1270(Actor* a, Actor* b, Vec3* v, Contact* c, Body* bodyA, Body* bodyB)
{
    if (!(v->x * v->x + v->y * v->y + v->z * v->z > 25.0f))
        return 0;
    if (a->joint.FUN_001b6e90(bodyB))
        return 0;
    if (!a->flag && !b->flag)
        return 0;
    float sqA = bodyA->vel.x * bodyA->vel.x + bodyA->vel.y * bodyA->vel.y + bodyA->vel.z * bodyA->vel.z;
    float sqB = bodyB->vel.x * bodyB->vel.x + bodyB->vel.y * bodyB->vel.y + bodyB->vel.z * bodyB->vel.z;
    int owner = b->FUN_001d72e0();
    if (!(sqA > 25.0f) && !(sqB > 25.0f))
        return 0;
    if (owner != 0) {
        a->joint.FUN_001b6e60(bodyB);
        b->joint.FUN_001b6e60(bodyA);
    }
    if (a->slot->FUN_001d4f70() == DAT_004e1828 || b->slot->FUN_001d4f70() == DAT_004e1828)
        DAT_004dd700->sink->FUN_001cbd10("golf_stroke");
    Actor* heavy = sqA > sqB ? a : b;
    float mult = heavy->FUN_001afb00();
    int aN = a->FUN_001d73f0();
    int bN = b->FUN_001d73f0();
    float fA = a->FUN_001d6670();
    if (a->flag && bN <= -10)
        fA = 0.1f;
    float fB = b->FUN_001d6670();
    if (b->flag && aN <= -10)
        fB = 0.1f;

    int kA = a->slot->FUN_001d5e80(a->id);
    bool is3A = kA == 3;
    bool is2A = kA == 2;
    a->FUN_001d6ec0((int)(fA * mult), b->f118, 0);
    if (b->flag)
        b->FUN_001d66b0(&c->f38, &c->f18);

    int kB = b->slot->FUN_001d5e80(b->id);
    bool is3B = kB == 3;
    bool is2B = kB == 2;
    b->FUN_001d6ec0((int)(fB * mult), a->f118, 0);
    if (a->flag) {
        Vec3 neg = c->f18;
        neg.x = neg.x * -1.0f;
        neg.y = neg.y * -1.0f;
        neg.z = neg.z * -1.0f;
        a->FUN_001d66b0(&c->f2c, &neg);
    }
    if (!is3A && !is2A && bN > -10) {
        a->FUN_001d8d90(0);
        a->FUN_001d71e0(0);
    }
    if (!is3B && !is2B && aN > -10) {
        b->FUN_001d8d90(0);
        b->FUN_001d71e0(0);
    }
    return 0;
}
