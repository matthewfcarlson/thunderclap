// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// hulkfight::motion::HitWaitAction::vfunc_5 @ 0x0014ee80
struct Stats {
    char pad00[0x58];
    float primary;           // 0x58
    float secondary;         // 0x5c
    char pad60[8];
    float tertiary;          // 0x68
};

struct Settings {
    char pad00[0x10];
    int mode;                // 0x10
};

struct Context {
    void FUN_00059a30();
};

class Entity {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Stats *GetStats();       // slot 3
    Context *FUN_000592a0();
};

class HitWaitAction {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x18];
    Settings *settings;      // 0x1c
    Entity *entity;          // 0x20
    float elapsed;           // 0x24
};

bool HitWaitAction::vfunc_5(int a, float dt) {
    entity->FUN_000592a0()->FUN_00059a30();
    elapsed = dt + elapsed;
    float limit = 0.0f;
    Stats *stats = entity->GetStats();
    if (stats != 0) {
        switch (settings->mode) {
        case 0:
            limit = stats->primary;
            if (limit <= 0.0f)
                limit = stats->secondary;
            break;
        case 1:
            limit = stats->secondary;
            if (limit <= 0.0f)
                limit = stats->primary;
            break;
        case 2:
            limit = stats->tertiary;
            break;
        }
    }
    return !(limit <= elapsed);
}
