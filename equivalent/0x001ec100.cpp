// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 20/20)
// FUN_001ec100 @ 0x001ec100
extern "C" int strcmp(const char *a, const char *b);
extern "C" char *strcpy(char *dst, const char *src);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct Query {
    char data[0x44];
    Query *FUN_001ef320();
    void FUN_001ef350();
    void FUN_001ef370(const char *name);
};
struct Vec3 { float x, y, z; };
struct Entity {
    char pad0[8];
    Vec3 pos;                // 0x8
    char pad1[0x11c - 0x14];
    struct Info *info;       // 0x11c
};
struct Info {
    const char *FUN_000443b0();
    long long FUN_000443c0();
};
struct Flags {
    bool FUN_00092de0(int v);
};
struct Config {
    Flags *FUN_00086340();
};
struct Logic {
    bool FUN_00027fc0(const char *a, const char *b);
};
struct Env {
    char pad[0x20];
    Logic *logic;            // 0x20
};
struct Lookup {
    void *FUN_00086310();
};
struct Spawner {
    void FUN_001efe20(Query *q, Vec3 *pos, const char *name, float radius);
};
struct SpawnGlobals {
    Spawner *spawner;        // 0x0
    char pad[4];
    char enabled;            // 0x8
};
void FUN_001eb440(void *target, Query *q);

extern Config *DAT_004dd6ec;
extern int DAT_004dc0e0;
extern int DAT_004dc0e4;
extern SpawnGlobals *DAT_004e36d8;

class Handler {
public:
    Env *env;                // 0x0
    Lookup *lookup;          // 0x4
    void FUN_001ec100(Entity *entity, const char *name);
};

struct Frame {
    int spill;
    Query q;
    int gap;
    char buf[0x40];
    unsigned int cookie;
};

void Handler::FUN_001ec100(Entity *entity, const char *name)
{
    Frame f;
    f.cookie = DAT_004d9968;
    if (entity != 0 && entity->info != 0) {
        int i;
        for (i = 0; i < 0x40; i++) f.buf[i] = 0;
        bool flag = DAT_004dd6ec->FUN_00086340()->FUN_00092de0(2);
        long long id = entity->info->FUN_000443c0();
        if ((int)id == DAT_004dc0e0 && (int)(id >> 32) == DAT_004dc0e4) {
            if (!flag) {
                __security_check_cookie(f.cookie);
                return;
            }
            strcpy(f.buf, "joefixit");
        } else {
            strcpy(f.buf, entity->info->FUN_000443b0());
        }
        if (strcmp(name, "spawn") == 0) {
            if (env->logic->FUN_00027fc0("hulk", "//hulk/opening/holding/stealth_truck")) {
                __security_check_cookie(f.cookie);
                return;
            }
        }
        f.q.FUN_001ef320();
        f.q.FUN_001ef370("Objects");
        f.q.FUN_001ef370("Dialogue");
        f.q.FUN_001ef370(f.buf);
        void *target = lookup->FUN_00086310();
        if (target != 0)
            FUN_001eb440(target, &f.q);
        if (DAT_004e36d8->enabled)
            DAT_004e36d8->spawner->FUN_001efe20(&f.q, &entity->pos, name, 100.0f);
        f.q.FUN_001ef350();
    }
    __security_check_cookie(f.cookie);
}
