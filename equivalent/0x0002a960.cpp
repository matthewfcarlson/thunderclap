// STATUS: equivalent (tools/equiv.py level 3: 15 inputs, branch coverage 28/32, incomplete)
// FUN_0002a960 @ 0x0002a960
struct Vec3_2a960 {
    float x, y, z;
    float FUN_000111f0();
};

unsigned __int64 FUN_0027b020(const char *name);

struct Body_2a960 {
    char pad00[0x18];
    char pad18[4];
    bool FUN_00059a50(Vec3_2a960 *out);
};

struct Named_2a960 {
    unsigned __int64 FUN_000443c0();
};

struct Zone_2a960 {
    Zone_2a960 *FUN_00204200(float x, float y, float z);
};

struct ZoneTest {
    bool FUN_00204440(Zone_2a960 *z);
    bool FUN_00204470(Zone_2a960 *z);
};

struct Fighter_2a960 {
    char pad000[0x10];
    Body_2a960 *body;                  // 0x10
    char pad14[0x119 - 0x14];
    unsigned char flag119;       // 0x119
    char pad11a[2];
    Named_2a960 *name;                 // 0x11c
    char pad120[0x1cf4 - 0x120];
    unsigned char flag1cf4;
    unsigned char flag1cf5;
    char pad1cf6[0x1d05 - 0x1cf6];
    unsigned char flag1d05;      // 0x1d05
    char pad1d06[0x1d78 - 0x1d06];
    unsigned char flag1d78;      // 0x1d78
};

struct Roster_2a960 {
    Fighter_2a960 *FUN_00059c10(int id);
};

struct Holder_2a960 {
    char pad00[0x28];
    ZoneTest *zoneTest;          // 0x28 (read by the FUN_000862a0 getter)
};

struct Context {
    char pad00[0x44];
    Roster_2a960 *roster;              // 0x44
    char pad48[0x54 - 0x48];
    Holder_2a960 *holder;              // 0x54
};

ZoneTest *__fastcall FUN_000862a0(Holder_2a960 *h);

struct Frame_2a960 {
    Vec3_2a960 pos;
    Vec3_2a960 delta;
    Vec3_2a960 other;
};

class SpawnWatcher {
public:
    char pad00[0xc];
    int count;                   // 0x0c
    int ids[52];                 // 0x10
    int state[1];                // 0xe0
    char padE4[0x124 - 0xe4];
    Fighter_2a960 *self;               // 0x124

    void FUN_0002a4b0(int index, int flag);
    void FUN_0002a960(Context *ctx);
};

void SpawnWatcher::FUN_0002a960(Context *ctx)
{
    for (int i = count - 1; i >= 0; i--) {
        state[i] = 0;
        Fighter_2a960 *f = ctx->roster->FUN_00059c10(ids[i]);
        if (f == self)
            continue;
        unsigned __int64 nm = f->name->FUN_000443c0();
        unsigned __int64 harrier = FUN_0027b020("harrier");
        if (nm == harrier)
            continue;
        if (f->flag1cf5 != 0)
            continue;
        Frame_2a960 fr;
        if (!f->body->FUN_00059a50(&fr.pos))
            continue;
        Zone_2a960 *zone = ((Zone_2a960 *)FUN_000862a0(ctx->holder))->FUN_00204200(fr.pos.x, fr.pos.y, fr.pos.z);
        bool a = FUN_000862a0(ctx->holder)->FUN_00204440((Zone_2a960 *)zone);
        bool b = FUN_000862a0(ctx->holder)->FUN_00204470((Zone_2a960 *)zone);
        if (a)
            continue;
        if (b) {
            state[i] = 1;
            continue;
        }
        if (self != 0 && self->body->FUN_00059a50(&fr.other)) {
            fr.delta.x = fr.pos.x - fr.other.x;
            fr.delta.y = 0;
            fr.delta.z = fr.pos.z - fr.other.z;
            if (fr.delta.FUN_000111f0() <= 56700.0f && f->flag1d05 == 0)
                continue;
        }
        if (f->flag1cf4) {
            state[i] = 1;
        } else if (f->flag119 == 0 && f->flag1d78 == 0) {
            FUN_0002a4b0(i, 0);
        }
    }
}
