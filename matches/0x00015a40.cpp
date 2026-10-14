struct EventSource {
    char pad[0xfc];
    int kind;
};
struct Event_15a40 {
    char pad[8];
    EventSource* source;
    int kind;
};
struct Position_15a40 {
    char data[12];
};
struct Actor_15a40 {
    char pad0[0xdc];
    Position_15a40 position;
    char pad1[0x334 - 0xdc - 12];
    int busy;
    int FUN_00036020();
    int FUN_00035ef0(int);
    void FUN_0003a9d0(Event_15a40*);
};
struct Intermediate_15a40 {
    Actor_15a40* FUN_00059a30();
};
struct Owner_15a40 {
    Intermediate_15a40* FUN_000592a0();
    void FUN_00059790(Event_15a40*);
};
struct Effect_15a40 {
    void FUN_00231ad0(Position_15a40*, Owner_15a40*, int);
};
struct Factory_15a40 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual Effect_15a40* slot8(Owner_15a40*, int);
};
struct Context {
    char pad[0x44];
    Factory_15a40* factory;
};
extern int __cdecl FUN_00266da0(int);
struct Target_15a40 {
    char pad[0x1c];
    Owner_15a40* owner;
    Context* context;
    char pad2[0x38 - 0x24];
    unsigned char done;
    void run(Event_15a40*, int, int);
};
void Target_15a40::run(Event_15a40* event, int, int) {
    if (done || event->kind != 5 || !event->source || event->source->kind == 2 || event->source->kind == 3)
        return;
    Actor_15a40* actor = owner->FUN_000592a0()->FUN_00059a30();
    if (actor->FUN_00036020() || actor->busy || actor->FUN_00035ef0(0))
        return;
    int previous = FUN_00266da0(13);
    actor->FUN_0003a9d0(event);
    if (owner)
        owner->FUN_00059790(event);
    Effect_15a40* effect = context->factory->slot8(owner, 0);
    if (effect) {
        effect->FUN_00231ad0(&actor->position, owner, 0);
        done = 1;
    }
    FUN_00266da0(previous);
}
