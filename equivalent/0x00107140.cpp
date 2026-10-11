// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_00107140 @ 0x00107140
struct Clock {
    float FUN_00078780();
};
Clock *__cdecl FUN_000964d0();

struct Tuning {
    char pad0[0x394];
    float f394;
    float f398;
    float f39c;
    float f3a0;
    float f3a4;
    float f3a8;
};

struct Player {
    char pad0[0x11c];
    Tuning *tuning;
    char pad120[0x1cd0 - 0x120];
    float f1cd0;
};

struct PlayerHolder {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Player *GetPlayer();
};

struct Agent {
    char pad0[0x58];
    PlayerHolder *holder;
    char pad5c[0x84 - 0x5c];
    float f84;
    float f88;
    float f8c;
    float f90;
    float f94;
    float f98;
    float f9c;

    void Init();
};

void Agent::Init()
{
    Clock *clock = FUN_000964d0();
    Player *player = holder->GetPlayer();
    if (player == 0)
        return;
    Tuning *t = player->tuning;
    if (t == 0)
        return;

    f8c = t->f394;
    f8c = (clock->FUN_00078780() * 0.5f + 1.0f) * f8c;
    f90 = t->f398;
    f90 = (clock->FUN_00078780() * 0.5f + 1.0f) * f90;
    {
        float lim = f8c + 2.0f;
        if (!(lim < f90))
            f90 = lim;
    }
    f84 = t->f39c;
    f84 = (clock->FUN_00078780() * 0.5f + 1.0f) * f84;
    f88 = t->f3a0;
    f88 = (clock->FUN_00078780() * 0.5f + 1.0f) * f88;
    if (!(f84 < f8c))
        f84 = f8c;
    if (f88 < f90)
        f88 = f90;
    f94 = t->f3a4;
    f98 = t->f3a8;
    f98 = (clock->FUN_00078780() * 0.5f + 1.0f) * f98;
    f9c = player->f1cd0;
    f9c = (clock->FUN_00078780() * 0.5f + 1.0f) * f9c;
}
