// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 6/8, incomplete)
// FUN_002d0e20 @ 0x002d0e20
struct Item {
    char pad[0xc];
    int slot;           // 0xc
};

struct Group {
    Item** items;
    int a, b;
};

struct Container {
    char pad[0x14];
    Group* groups;      // 0x14
};

struct Handler {
    void FUN_002e11e0(Item* item, int arg);
};

struct Iter {
    int arg;            // 0x0
    int group;          // 0x4
    int index;          // 0x8
    Container* cont;    // 0xc
    void FUN_002e5850(Container* c, int arg);
    void FUN_002e5310();
};

class Dispatcher {
public:
    char pad0[8];
    Container* source;      // 0x8
    Handler** handlers;     // 0xc
    void FUN_002d0e20(int selector, int arg);
};

// Walks the selected group from its last item down to the first and dispatches each to its handler.
void Dispatcher::FUN_002d0e20(int selector, int arg)
{
    Iter it;
    it.FUN_002e5850(source, selector);
    if (it.index >= 0) {
        do {
            Item* item = 0;
            if (it.index >= 0)
                item = it.cont->groups[it.group].items[it.index];
            handlers[item->slot]->FUN_002e11e0(item, arg);
            if (it.index < 0)
                break;
            it.index--;
        } while (it.index >= 0);
    }
    it.FUN_002e5310();
}
