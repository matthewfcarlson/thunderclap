// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 51/66, incomplete)
// FUN_0003a830 @ 0x0003a830
struct Event_3a830;

struct Slot_3a830 {
    Event_3a830 *FUN_001d72e0();
};

struct Weapon_3a830 {
    char pad0[0xfc];
    int mode;
    char pad100[0x114 - 0x100];
    int f114;
    char pad118[0x148 - 0x118];
    struct Owner_3a830 *owner;
    bool FUN_001d6980();
    void FUN_001d69f0(int a);
};

struct SlotEntry_3a830 {
    Slot_3a830 *slot;
    char pad[0x4c];
};

struct Event_3a830 {
    char pad0[8];
    Weapon_3a830 *weapon;
    int kind;
};

struct Owner_3a830 {
    char pad0[0x128];
    Slot_3a830 *slot128;
    Event_3a830 *ev12c;
    char pad130[0x1b0c - 0x130];
    float f1b0c;
    char pad1b10[0x20b0 - 0x1b10];
    int f20b0;
};

struct Fighter_3a830 {
    char pad0[0x128];
    Slot_3a830 *slot128;
    Event_3a830 *ev12c;
    char pad130[0x14c - 0x130];
    Event_3a830 *ev14c;
    char pad150[0x334 - 0x150];
    Fighter_3a830 *t334;
    Fighter_3a830 *t338;
    char pad33c[0x3a8 - 0x33c];
    SlotEntry_3a830 slots[8];
    bool FUN_0003a830(Event_3a830 *ev, int arg);
};

bool Fighter_3a830::FUN_0003a830(Event_3a830 *ev, int arg)
{
    int i;
    if (!ev || ev->kind != 5)
        return false;
    Weapon_3a830 *w = ev->weapon;
    if (!w)
        return false;
    for (i = 0; i < 8; i++) {
        if (slots[i].slot && (Slot_3a830 *)w == slots[i].slot)
            return false;
    }
    for (int k = 0; k < 2; k++) {
        Fighter_3a830 *f = (k == 0) ? t334 : t338;
        if (!f)
            continue;
        if (ev == f->ev12c)
            return false;
        if (f->slot128 && ev == f->slot128->FUN_001d72e0())
            return false;
        for (i = 0; i < 8; i++) {
            // the callee may modify the table, so the pointer is re-read each time
            Fighter_3a830 *g = (k == 0) ? t334 : t338;
            Slot_3a830 *s = g->slots[i].slot;
            if (s && ev == s->FUN_001d72e0())
                return false;
        }
    }
    if (ev == ev14c)
        return false;
    if (w->mode == 2 || w->mode == 3 || w->mode == 1)
        return false;
    if (w->FUN_001d6980())
        return false;
    if (w->f114)
        return false;
    Owner_3a830 *o = w->owner;
    if (o) {
        if (o->f20b0)
            return false;
        if (o->f1b0c <= 0.0f)
            return false;
    }
    w->FUN_001d69f0(arg);
    return true;
}
