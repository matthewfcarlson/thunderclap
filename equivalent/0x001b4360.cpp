// STATUS: equivalent (tools/equiv.py level 3: 2971 inputs, branch coverage 4/4)
// FUN_001b4360 @ 0x001b4360
#include "decls/data/game/global.h"

struct Mask_1b4360 { unsigned lo, hi; };
struct Data_1b4360 { char pad[0x58]; Mask_1b4360 a; Mask_1b4360 b; };
struct Ctl_1b4360 { char pad[8]; void* owner; int state; char pad2[0x74 - 0x10]; Data_1b4360* data; };
struct Entity { char pad[0x100]; Ctl_1b4360* ctl; };
struct Sink_1b4360 { void FUN_002ee6b0(Data_1b4360* d); };
struct Router {
    char pad[8];
    Sink_1b4360* sink;
    bool Apply(Entity* e);
};
bool Router::Apply(Entity* e) {
    Ctl_1b4360* c = e->ctl;
    if (!c || !c->data) return false;
    Data_1b4360* d = c->data;
    c->owner = e;
    c->state = 7;
    d->a = (*(Mask_1b4360*)&DAT_004c3a18);
    d->b.lo = (*(Mask_1b4360*)&DAT_004c3a20).lo | ((*(Mask_1b4360*)&DAT_004c39e8).lo | ((*(Mask_1b4360*)&DAT_004c39f8).lo | (*(Mask_1b4360*)&DAT_004c39f0).lo));
    d->b.hi = (*(Mask_1b4360*)&DAT_004c3a20).hi | ((*(Mask_1b4360*)&DAT_004c39e8).hi | ((*(Mask_1b4360*)&DAT_004c39f8).hi | (*(Mask_1b4360*)&DAT_004c39f0).hi));
    sink->FUN_002ee6b0(d);
    return true;
}
