// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 20/22, incomplete)
// FUN_001fc6a0 @ 0x001fc6a0
class Unit_1fc6a0 {
public:
    void FUN_00036be0(class Handler_1fc6a0 *best);
};

class Handler_1fc6a0 {
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
    virtual char vf12(Unit_1fc6a0 *unit);
    char pad0[0xcd - 4];
    char active;
    char enabled;
};

class Slot_1fc6a0 {
public:
    void FUN_001fa7d0(Unit_1fc6a0 *unit, int arg);
    char data[0xc70];
};

class UnitList {
public:
    Unit_1fc6a0 *FUN_00024190(int index);
    char pad0[0xc];
    int count;
    char pad1[0x124 - 0x10];
    Unit_1fc6a0 *current;
};

class World {
public:
    char pad0[0x20];
    UnitList *units;
};

class Dispatcher_1fc6a0 {
public:
    void FUN_001fc6a0(int arg);

    char pad0[4];
    World *world;
    int handlerCount;
    Handler_1fc6a0 *handlers[(0x234 - 0xc) / 4];
    char *slots;
};

void Dispatcher_1fc6a0::FUN_001fc6a0(int arg)
{
    UnitList *list = world->units;
    int count = list->count;
    for (int i = 0; i < count; i++) {
        Unit_1fc6a0 *unit = list->FUN_00024190(i);
        if (unit == 0)
            continue;
        Handler_1fc6a0 *best = 0;
        for (int j = 0; j < handlerCount; j++) {
            if (handlers[j]->vf12(unit) && handlers[j]->enabled && handlers[j]->active)
                best = handlers[j];
        }
        unit->FUN_00036be0(best);
        if (unit == list->current) {
            for (int off = 0; off < 0x6380; off += 0xc70)
                ((Slot_1fc6a0 *)(slots + off))->FUN_001fa7d0(unit, arg);
        }
    }
}
