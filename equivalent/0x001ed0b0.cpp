// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_001ed0b0 @ 0x001ed0b0
extern "C" double sqrt(double);
extern "C" char * __cdecl strcat(char *, const char *);
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

extern __int64 DAT_004dc068;
extern __int64 DAT_004dc0a8;
extern __int64 DAT_004dc0c8;

__int64 __cdecl FUN_002672f0(const char *name, int a, int b);

struct V3 {
    float x, y, z;
};

struct Anim {
    __int64 FUN_000443c0();
};

struct BoneEntry {
    char pad0[0x30];
    V3 pos;                 // 0x30
    char pad3c[0x40 - 0x3c];
};

struct Skeleton {
    char pad0[0x1c];
    BoneEntry *bones;       // 0x1c
    int FUN_002843a0(__int64 hash);
};

struct Actor {
    char pad0[0x11c];
    Anim *anim;             // 0x11c
    Skeleton *skel;         // 0x120
    char pad124[0x1a64 - 0x124];
    float groundY;          // 0x1a64
    char pad1a68[0x1aa8 - 0x1a68];
    int leftDown;           // 0x1aa8
    int rightDown;          // 0x1aac
    void FUN_00035660(V3 *out);
};

struct Frame {
    float scale;            // 0x00
    void *self;             // 0x04
    V3 vel;                 // 0x08
    V3 foot;                // 0x14
    float ground;           // 0x20
    float groundCopy;       // 0x24
    char buf[16];           // 0x28
    unsigned int cookie;    // 0x38
};

class Footsteps {
public:
    void FUN_001ec980(Actor *a, char *name);
    void FUN_001ed0b0(Actor *a);
};

void Footsteps::FUN_001ed0b0(Actor *a)
{
    Frame f;
    f.cookie = DAT_004d9968;
    f.self = this;
    f.scale = 2.0f;
    __int64 id = a->anim->FUN_000443c0();
    if (id == DAT_004dc068) {
        f.scale = 15.0f;
    } else if (a->anim->FUN_000443c0() == DAT_004dc0a8) {
        f.scale = 7.5f;
    } else if (a->anim->FUN_000443c0() == DAT_004dc0c8) {
        f.scale = 5.0f;
    }

    Skeleton *skel = a->skel;
    BoneEntry *e = &skel->bones[skel->FUN_002843a0(FUN_002672f0("Ball_L", 0, 0))];
    f.foot.x = e->pos.x;
    f.foot.y = e->pos.y - a->groundY;
    f.foot.z = e->pos.z;
    f.groundCopy = a->groundY;
    f.buf[0] = 's';
    f.buf[1] = 't';
    f.buf[2] = 'e';
    f.buf[3] = 'p';
    f.buf[4] = '_';
    f.buf[5] = 0;
    for (int i = 6; i < 16; i++)
        f.buf[i] = 0;
    a->FUN_00035660(&f.vel);
    double len = sqrt(f.vel.z * f.vel.z + f.vel.y * f.vel.y + f.vel.x * f.vel.x);
    if (len < 5.0f) {
        strcat(f.buf, "slow");
    } else if (len < 12.0f) {
        strcat(f.buf, "mid");
    } else {
        strcat(f.buf, "fast");
    }
    float thr = f.scale * 0.1f;
    if (a->leftDown == 0) {
        if (f.foot.y < thr) {
            a->leftDown = 1;
            FUN_001ec980(a, f.buf);
        }
    } else if (f.foot.y > thr) {
        a->leftDown = 0;
    }

    float ry = skel->bones[skel->FUN_002843a0(FUN_002672f0("Ball_R", 0, 0))].pos.y - f.groundCopy;
    if (a->rightDown == 0) {
        if (ry < thr) {
            a->rightDown = 1;
            FUN_001ec980(a, f.buf);
        }
    } else if (ry > thr) {
        a->rightDown = 0;
    }
    __security_check_cookie(f.cookie);
}
