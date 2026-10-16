// STATUS: equivalent (tools/equiv.py level 3: 217 inputs, branch coverage 79/96, incomplete)
// FUN_00039440 @ 0x00039440
#include "decls/address.h"
struct Fighter_39440;

struct Event_39440 {
    char pad0[8];
    Fighter_39440 *owner;
    int kind;
};

struct Handle_39440 {
    char pad0[0xa0];
    void *link;
    Event_39440 *FUN_001d72e0();
};

struct Slot_39440 {
    Handle_39440 *handle;
    char pad04[0x4c];
};

struct Team_39440 {
    char pad0[0x1b0];
    void *id;
};

struct Control_39440 {
    char pad0[0x60];
    Event_39440 *current;
};

struct World {
    char pad0[0x20];
    struct Mode_39440 *mode;
};

struct Mode_39440 {
    char pad0[0x124];
    Fighter_39440 *fighter;
};


bool __cdecl FUN_00096b50(Event_39440 *ev, void *out, int *result);

struct Fighter_39440 {
    char pad000[0x114];
    Event_39440 *f114;
    char pad118[4];
    Team_39440 *team;
    char pad120[8];
    Handle_39440 *held;
    Event_39440 *heldEvent;
    int mode130;
    char pad134[0x148 - 0x134];
    Fighter_39440 *f148;
    Event_39440 *target;
    char pad150[0x328 - 0x150];
    Event_39440 *grab;
    char pad32c[8];
    Fighter_39440 *partner;
    Fighter_39440 *partner2;
    char pad33c[0x3a8 - 0x33c];
    Slot_39440 slots[8];
    char pad628[0x1ca0 - 0x628];
    Control_39440 *control;
    bool FUN_00039440(Event_39440 *ev, void *out, int *result, char flag);
};

bool Fighter_39440::FUN_00039440(Event_39440 *ev, void *out, int *result, char flag)
{
    if (ev == 0)
        return false;

    for (int i = 0; i < 8; i++) {
        if (slots[i].handle != 0) {
            if (ev == slots[i].handle->FUN_001d72e0())
                return false;
        }
    }

    if (partner != 0) {
        if (ev == partner->heldEvent)
            return false;
        if (partner->held != 0 && ev == partner->held->FUN_001d72e0())
            return false;
        for (int i = 0; i < 8; i++) {
            Handle_39440 *h = partner->slots[i].handle;
            if (h != 0 && ev == h->FUN_001d72e0())
                return false;
        }
    }

    if (partner2 != 0) {
        if (ev == partner2->heldEvent)
            return false;
        if (partner2->held != 0 && ev == partner2->held->FUN_001d72e0())
            return false;
        for (int i = 0; i < 8; i++) {
            Handle_39440 *h = partner2->slots[i].handle;
            if (h != 0 && ev == h->FUN_001d72e0())
                return false;
        }
    }

    if (ev == target)
        return false;

    void *teamId = team->id;
    if (!FUN_00096b50(ev, out, result))
        return false;

    switch (ev->kind) {
    case 1: {
        Fighter_39440 *other = ev->owner;
        if (other == this)
            return false;
        if (other == partner)
            return false;
        if (other->team->id != teamId)
            return true;
        return ev == control->current;
    }
    case 5: {
        if (mode130 == 0) {
            if (ev != control->current)
                return false;
        }
        Fighter_39440 *other = ev->owner;
        if (other == 0)
            return false;
        Event_39440 *grabbed = other->f114;
        if (grabbed != 0) {
            if (flag != 0)
                return false;
            Event_39440 *g = grab;
            Event_39440 *gh = 0;
            if (g != 0 && g->kind == 5 && g->owner != 0)
                gh = g->owner->f114;
            if (ev != g && grabbed != g && grabbed != gh)
                return false;
        }
        Fighter_39440 *third = other->f148;
        if (third == 0)
            return true;
        if (third == this)
            return false;
        if (third == partner)
            return false;
        if (third->team->id != teamId)
            return true;
        return ev == control->current;
    }
    case 7:
        return DAT_004dd700->mode->fighter == this;
    default:
        return true;
    }
}
