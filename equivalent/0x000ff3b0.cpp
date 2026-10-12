// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 36/36)
// CHand2HandAgent::vfunc_11 @ 0x000ff3b0
struct NameKey {
    unsigned lo;
    unsigned hi;
    void FUN_0027af30(const NameKey *src);
    void FUN_0027af50();
    void FUN_0027af60(unsigned long long key);
};

struct Gate {
    char FUN_00099730();
    char FUN_00099750();
    char FUN_00099760();
    char FUN_00099790();
};

struct World {
    char pad[8];
    Gate *gate;
};
extern World *DAT_004dd700;

struct RandState {
    unsigned s0;
    unsigned s1;
    float FUN_00078780();
};
RandState *__cdecl FUN_000964d0();

struct Check {
    char FUN_00231ee0();
};

struct Zone {
    char pad[0x3a0];
    float level;
};

struct Player {
    char pad0[0xdc];
    Check check;
    char pad1[0x11c - 0xdd];
    Zone *zone;
    char pad2[0x1cac - 0x120];
    float limitA;
    char pad3[0x1cd0 - 0x1cb0];
    float scale;
    float chance;
    char pad4[0x1d68 - 0x1cd8];
    NameKey key;
    char pad5[0x1f58 - 0x1d70];
    int flagA;
    char pad6[0x1f64 - 0x1f5c];
    int flagB;
    char pad7[0x1f7c - 0x1f68];
    int flagC;
    char pad8[0x2098 - 0x1f80];
    NameKey lastKey;
    unsigned char active;

    void FUN_00035140(int a);
    int FUN_00035ef0(int a);
};

class CAgentBase {
public:
    virtual void v0();
    virtual void v1();
};

class CHand2HandAgent : public CAgentBase {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual char vfunc_11(Player *player, float a, float b);
    char pad04[0x64 - 4];
    float rv;
    int f68;
    char pad6c[0x7a - 0x6c];
    char r7a;
    char r7b;
    char r7c;
    char pad7d[0xcd - 0x7d];
    char blocked;
};

char CHand2HandAgent::vfunc_11(Player *player, float a, float b)
{
    char result = 0;
    RandState *rng = FUN_000964d0();
    float scale = player->scale;
    float limitA = player->limitA;
    rng->s0 = (rng->s0 & 0xffff) * 0x9069 + (rng->s0 >> 16);
    rng->s1 = (rng->s1 & 0xffff) * 0x4650 + (rng->s1 >> 16);
    union {
        unsigned u;
        float f;
    } bits;
    bits.u = (((rng->s0 << 16) + (rng->s1 & 0xffff)) & 0x7fffff) | 0x3f800000;
    float rv0 = (bits.f - 1.0f + 1.0f) * scale;
    char ready = player->check.FUN_00231ee0();
    float chance = player->chance;
    Gate *gate = DAT_004dd700->gate;
    if (gate) {
        if (gate->FUN_00099730() || gate->FUN_00099750() || gate->FUN_00099760() || gate->FUN_00099790())
            return 0;
    }
    if (b > 0.7f && a <= limitA && rv <= 0.0f && !ready && !blocked) {
        NameKey q;
        q.FUN_0027af30(&player->key);
        if (player->key.lo != 0 || player->key.hi != 0) {
            player->lastKey.FUN_0027af60(*(unsigned long long *)&player->key);
            player->active = 1;
            player->FUN_00035140(0);
            rv = rv0;
            r7a = 0;
            r7b = 0;
            r7c = 0;
            result = 1;
        } else if (player->FUN_00035ef0(0)) {
            if (player->zone->level < 4.0f) {
                if (a < 2.0f)
                    player->flagA = 1;
                else
                    player->flagB = 1;
                rv = rv0;
                f68 = 0;
                r7a = 1;
                r7b = 1;
                r7c = rng->FUN_00078780() < chance;
                result = 1;
            }
        } else {
            float rnd = rng->FUN_00078780();
            if (rnd < 0.33f) {
                player->flagA = 1;
            } else if (rnd < 0.66f) {
                player->flagB = 1;
            } else {
                player->flagC = 1;
            }
            rv = rv0;
            f68 = 0;
            r7a = 1;
            r7b = 1;
            r7c = rng->FUN_00078780() < chance;
            result = 1;
        }
        q.FUN_0027af50();
    }
    return result;
}
