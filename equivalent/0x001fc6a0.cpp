// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 20/22, incomplete)
// FUN_001fc6a0 @ 0x001fc6a0
class Unit {
public:
    void FUN_00036be0(class Handler *best);
};

class Handler {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual char vf12(Unit *unit);
    char pad0[0xcd - 4];
    char active;
    char enabled;
};

class Slot {
public:
    void FUN_001fa7d0(Unit *unit, int arg);
    char data[0xc70];
};

class UnitList {
public:
    Unit *FUN_00024190(int index);
    char pad0[0xc];
    int count;
    char pad1[0x124 - 0x10];
    Unit *current;
};

class World {
public:
    char pad0[0x20];
    UnitList *units;
};

class Dispatcher {
public:
    void FUN_001fc6a0(int arg);

    char pad0[4];
    World *world;
    int handlerCount;
    Handler *handlers[(0x234 - 0xc) / 4];
    char *slots;
};

void Dispatcher::FUN_001fc6a0(int arg)
{
    UnitList *list = world->units;
    int count = list->count;
    for (int i = 0; i < count; i++) {
        Unit *unit = list->FUN_00024190(i);
        if (unit == 0)
            continue;
        Handler *best = 0;
        for (int j = 0; j < handlerCount; j++) {
            if (handlers[j]->vf12(unit) && handlers[j]->enabled && handlers[j]->active)
                best = handlers[j];
        }
        unit->FUN_00036be0(best);
        if (unit == list->current) {
            for (int off = 0; off < 0x6380; off += 0xc70)
                ((Slot *)(slots + off))->FUN_001fa7d0(unit, arg);
        }
    }
}
