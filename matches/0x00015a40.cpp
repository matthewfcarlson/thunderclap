struct EventSource {
    char pad[0xfc];
    int kind;
};
struct Event {
    char pad[8];
    EventSource* source;
    int kind;
};
struct Position {
    char data[12];
};
struct Actor {
    char pad0[0xdc];
    Position position;
    char pad1[0x334 - 0xdc - 12];
    int busy;
    int FUN_00036020();
    int FUN_00035ef0(int);
    void FUN_0003a9d0(Event*);
};
struct Intermediate {
    Actor* FUN_00059a30();
};
struct Owner {
    Intermediate* FUN_000592a0();
    void FUN_00059790(Event*);
};
struct Effect {
    void FUN_00231ad0(Position*, Owner*, int);
};
struct Factory {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual Effect* slot8(Owner*, int);
};
struct Context {
    char pad[0x44];
    Factory* factory;
};
extern int __cdecl FUN_00266da0(int);
struct Target {
    char pad[0x1c];
    Owner* owner;
    Context* context;
    char pad2[0x38 - 0x24];
    unsigned char done;
    void run(Event*, int, int);
};
void Target::run(Event* event, int, int) {
    if (done || event->kind != 5 || !event->source || event->source->kind == 2 || event->source->kind == 3)
        return;
    Actor* actor = owner->FUN_000592a0()->FUN_00059a30();
    if (actor->FUN_00036020() || actor->busy || actor->FUN_00035ef0(0))
        return;
    int previous = FUN_00266da0(13);
    actor->FUN_0003a9d0(event);
    if (owner)
        owner->FUN_00059790(event);
    Effect* effect = context->factory->slot8(owner, 0);
    if (effect) {
        effect->FUN_00231ad0(&actor->position, owner, 0);
        done = 1;
    }
    FUN_00266da0(previous);
}
