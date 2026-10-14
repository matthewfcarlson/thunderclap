// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::ai::SemaphoreWaitAction::vfunc_5 @ 0x0010e2c0
struct Settings {
    char pad00[0x18];
    char timer[8];
    char pad20;
    unsigned char useGlobal;
    char pad22[2];
    float limit;
};

struct Globals {
    char pad00[0x1d08];
    float limit;
    bool FUN_00036fd0(void *timer);
    bool FUN_00037040(void *timer, int a, int b);
};

struct Table {
    Globals *FUN_00059a30();
};

struct Owner {
    Table *FUN_000592a0();
};


namespace hulkfight {
namespace ai {

class SemaphoreWaitAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int cancelled, float dt);
    char pad04[0x18];
    Settings *settings;
    Owner *owner;
    float elapsed;
};

bool SemaphoreWaitAction::vfunc_5(int cancelled, float dt)
{
    if (cancelled)
        return true;
    Globals *globals = owner->FUN_000592a0()->FUN_00059a30();
    if (!globals)
        return true;
    elapsed += dt;
    Settings *s = settings;
    float limit = s->useGlobal ? globals->limit : s->limit;
    if (limit != 0.0f && elapsed >= limit) {
        globals->FUN_00037040(s->timer, 0, 1);
        return false;
    }
    return globals->FUN_00036fd0(s->timer);
}

}
}
