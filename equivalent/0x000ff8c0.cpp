// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 43/44, incomplete)
// CHand2HandAgent::vfunc_17 @ 0x000ff8c0
struct Id64 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af30(Id64 *src);
    Id64 *FUN_0027b0e0(const char *s);
    char FUN_0027af90(Id64 *other);
    void FUN_0027af50();
    void FUN_0027b040(const char *s);
};

struct Clock {
    float FUN_00078780();
};
Clock *__cdecl FUN_000964d0();

struct Owner {
    char pad0[8];
    char *base;
};

struct Target {
    char pad0[0x140];
    Id64 id;                // 0x140
    char b148;
};

struct Frame {
    char pad0c;
    char flag3;             // 0xd
    char result;            // 0xe
    char matched;           // 0xf
    Id64 a;                 // 0x10
    Id64 t1;                // 0x18
    Id64 t2;                // 0x20
    Id64 t3;                // 0x28
    Id64 t4;                // 0x30
    Id64 t5;                // 0x38
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual char vfunc_17(Target *target, float dt);
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    char pad04[0x6c - 4];
    float timer;            // 0x6c
    float f70;
    float f74;
    char b78;
    char pad79[0x94 - 0x79];
    float dirX;
    float dirY;
    float dirZ;
    Owner *owner;           // 0xa0
    char pada4[0xb0 - 0xa4];
    float velX;
    float velY;
    float velZ;
    char padbc[0xcf - 0xbc];
    char bcf;
    char padd0[3];
    char bd3;
};

char CHand2HandAgent::vfunc_17(Target *target, float dt)
{
    Frame f;
    f.a.lo = 0;
    f.result = 0;
    Clock *clock = FUN_000964d0();
    if (bd3 != 0 || bcf == 0) {
        timer = 0.0f;
        return f.result;
    }
    f.a.FUN_0027af30((Id64 *)(owner->base + 0x1b50));
    char same = f.a.FUN_0027af90(f.t1.FUN_0027b0e0(""));
    f.t1.FUN_0027af50();
    if (same) {
        f.a.FUN_0027af50();
        return 0;
    }
    f.flag3 = 0;
    if (dirZ * velZ + dirY * velY + dirX * velX < -0.7f) {
        unsigned int live = 1;
        f.matched = 1;
        char hit = f.a.FUN_0027af90(f.t5.FUN_0027b0e0("jump_punch_charge"));
        if (!hit) {
            live = 3;
            hit = f.a.FUN_0027af90(f.t4.FUN_0027b0e0("jump_stomp_charge"));
            if (!hit) {
                live = 7;
                hit = f.a.FUN_0027af90(f.t3.FUN_0027b0e0("sonic_clap_hold"));
                if (!hit) {
                    live = 0xf;
                    hit = f.a.FUN_0027af90(f.t2.FUN_0027b0e0("hook_l_hold"));
                    if (!hit) {
                        live = 0x1f;
                        hit = f.a.FUN_0027af90(f.t1.FUN_0027b0e0("hook_r_hold"));
                        f.matched = 0;
                        if (hit)
                            f.matched = 1;
                    }
                }
            }
        }
        if (hit)
            f.matched = 1;
        if (live & 0x10) {
            live &= ~0x10;
            f.t1.FUN_0027af50();
        }
        if (live & 8) {
            live &= ~8;
            f.t2.FUN_0027af50();
        }
        if (live & 4) {
            live &= ~4;
            f.t3.FUN_0027af50();
        }
        if (live & 2) {
            live &= ~2;
            f.t4.FUN_0027af50();
        }
        if (live & 1)
            f.t5.FUN_0027af50();
        if (!f.matched) {
            timer = 0.0f;
            f.a.FUN_0027af50();
            return f.result;
        }
        f.result = 1;
        if (dirZ * velZ + dirY * velY + dirX * velX < -0.98f)
            f.flag3 = 1;
    } else {
        char stomp = f.a.FUN_0027af90(f.t5.FUN_0027b0e0("jump_stomp_charge"));
        f.t5.FUN_0027af50();
        if (stomp) {
            f.result = 1;
        } else {
            char rage = f.a.FUN_0027af90(f.t5.FUN_0027b0e0("rage"));
            f.t5.FUN_0027af50();
            if (!rage) {
                timer = 0.0f;
                f.a.FUN_0027af50();
                return f.result;
            }
            f.result = 1;
            f.flag3 = 1;
            if (!(clock->FUN_00078780() < 0.5f))
                f.flag3 = 0;
        }
    }
    double t = (double)dt + timer;
    timer = (float)t;
    if (!(t > 0.2f)) {
        f.a.FUN_0027af50();
        return f.result;
    }
    f70 = 2.0f - clock->FUN_00078780() * 0.5f;
    f74 = clock->FUN_00078780() * 3.5f + 7.0f;
    bd3 = 1;
    if (f.flag3) {
        target->id.FUN_0027b040("awestruck");
        target->b148 = 1;
        b78 = 0;
        f.a.FUN_0027af50();
        return f.result;
    }
    if (clock->FUN_00078780() < 0.5f)
        b78 = 0;
    else
        b78 = 1;
    f.a.FUN_0027af50();
    return f.result;
}
