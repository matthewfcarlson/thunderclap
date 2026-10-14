// STATUS: equivalent (tools/equiv.py level 3: 195 inputs, branch coverage 9/10, incomplete)
// FUN_00231230 @ 0x00231230
struct Slot;

struct Key {
    unsigned a, b;
};

struct Table {
    unsigned cap;
    char pad4[0x18 - 4];
    Slot **slots;
    Key *keys;
    char end[1];
};

class Probe {
public:
    Table *table;
    char pad4[4];
    unsigned ka, kb;
    unsigned pos;
    unsigned step;
    Slot *FUN_00231230();
};

Slot *Probe::FUN_00231230()
{
    Table *t = table;
    unsigned s = step;
    pos = pos + s;
    unsigned tries = 0;
    for (;;) {
        pos = (t->cap - 1) & pos;
        unsigned idx = pos;
        Slot *slot = t->slots[idx];
        bool hit = true;
        if (slot != 0) {
            if (t->keys[idx].a != ka || t->keys[idx].b != kb)
                hit = false;
        }
        if (hit && slot != (Slot *)t->end)
            return t->slots[idx];
        tries++;
        if (tries > t->cap - 1)
            return 0;
        pos = idx + s;
    }
}
