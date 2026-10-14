// STATUS: equivalent (tools/equiv.py level 3: 2971 inputs, branch coverage 4/4)
// FUN_001b4360 @ 0x001b4360
struct Mask { unsigned lo, hi; };
extern Mask DAT_004c39e8, DAT_004c39f0, DAT_004c39f8, DAT_004c3a18, DAT_004c3a20;
struct Data { char pad[0x58]; Mask a; Mask b; };
struct Ctl { char pad[8]; void* owner; int state; char pad2[0x74 - 0x10]; Data* data; };
struct Entity { char pad[0x100]; Ctl* ctl; };
struct Sink { void FUN_002ee6b0(Data* d); };
struct Router {
    char pad[8];
    Sink* sink;
    bool Apply(Entity* e);
};
bool Router::Apply(Entity* e) {
    Ctl* c = e->ctl;
    if (!c || !c->data) return false;
    Data* d = c->data;
    c->owner = e;
    c->state = 7;
    d->a = DAT_004c3a18;
    d->b.lo = DAT_004c3a20.lo | (DAT_004c39e8.lo | (DAT_004c39f8.lo | DAT_004c39f0.lo));
    d->b.hi = DAT_004c3a20.hi | (DAT_004c39e8.hi | (DAT_004c39f8.hi | DAT_004c39f0.hi));
    sink->FUN_002ee6b0(d);
    return true;
}
