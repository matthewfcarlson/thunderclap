// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 31/32, incomplete)
// FUN_0007b880 @ 0x0007b880
class Entity {
public:
    virtual void v0();
    virtual void v1();
    char pad04[0x10 - 4];
    int kind;
    char pad14[0x34 - 0x14];
    int arg34;
    int key;
    int row;
    char pad40[0x5c - 0x40];
    int category;
};

struct Item72 {
    int count;
    char pad[0x44];
};

struct Target {
    void FUN_001e5bc0(int arg);
};

struct Mgr {
    char pad[0xc];
    Target* target;
};

class Pool {
public:
    void run(int slot);
    char p0[0x3718];
    int counters[12];
    Entity* stack0;
    Entity* slots[20];
    int depth;
    char p4[12];
    Entity* active[20];
    char p5[0x382c - (0x37ac + 80)];
    Mgr* mgr;
};

void Pool::run(int slot)
{
    counters[slots[slot]->category]--;

    int key = slots[slot]->key;
    int found = -1;
    for (int i = 0; i < 7; i++) {
        if (*(int*)((char*)this + 0x1920 + i * 0x3f0) == key) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        Item72* items = (Item72*)((char*)this + 0x192c);
        items[found * 14 + slots[slot]->row].count--;
    }

    int kind = slots[slot]->kind;
    if (kind == 5 || kind == 9 || kind == 7 || kind == 11)
        ((unsigned char*)this)[0x3494 + found * 2] = 0;
    else if (kind == 6 || kind == 10 || kind == 8 || kind == 12)
        ((unsigned char*)this)[0x3495 + found * 2] = 0;

    int i;
    for (i = 0; i < 20; i++) {
        if (active[i] == slots[slot])
            break;
    }
    if (i < 20) {
        if (active[i] != 0) {
            active[i]->v1();
            active[i] = 0;
        }
    }

    int saved = slots[slot]->arg34;
    if (slots[slot] != 0) {
        slots[slot]->v1();
        slots[slot] = 0;
    }

    Entity** stack = &stack0;
    if (stack[depth] != 0) {
        slots[slot] = stack[depth];
        stack[depth] = 0;
    }
    depth = depth - 1;
    mgr->target->FUN_001e5bc0(saved);
}
