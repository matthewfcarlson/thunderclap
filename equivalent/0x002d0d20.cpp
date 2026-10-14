// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 6/8, incomplete)
// FUN_002d0d20 @ 0x002d0d20
struct Item_2d0d20 {
    char pad[0xc];
    int slot;           // 0xc
};

struct Group_2d0d20 {
    Item_2d0d20** items;
    int a, b;
};

struct Container_2d0d20 {
    char pad[0x14];
    Group_2d0d20* groups;      // 0x14
};

struct Handler_2d0d20 {
    void FUN_002e0cc0(Item_2d0d20* item, int arg);
};

struct Iter_2d0d20 {
    int arg;            // 0x0
    int group;          // 0x4
    int index;          // 0x8
    Container_2d0d20* cont;    // 0xc
    void FUN_002e5850(Container_2d0d20* c, int arg);
    void FUN_002e5310();
};

class Dispatcher_2d0d20 {
public:
    char pad0[8];
    Container_2d0d20* source;      // 0x8
    Handler_2d0d20** handlers;     // 0xc
    void FUN_002d0d20(int selector, int arg);
};

// Walks the selected group from its last item down to the first and dispatches each to its handler.
void Dispatcher_2d0d20::FUN_002d0d20(int selector, int arg)
{
    Iter_2d0d20 it;
    it.FUN_002e5850(source, selector);
    if (it.index >= 0) {
        do {
            Item_2d0d20* item = 0;
            if (it.index >= 0)
                item = it.cont->groups[it.group].items[it.index];
            handlers[item->slot]->FUN_002e0cc0(item, arg);
            if (it.index < 0)
                break;
            it.index--;
        } while (it.index >= 0);
    }
    it.FUN_002e5310();
}
