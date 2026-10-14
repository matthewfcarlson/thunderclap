// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c70c0 @ 0x000c70c0
struct Name {
    int lo, hi;
    Name *FUN_0027af00();
    void FUN_0027af70(const Name *src);
    void FUN_0027af50();
};

struct Slot {
    int kind;       // -1 when free
    int a;
    int b;
    int c;
    Name name;
    int value;
    int pad1c;
};

class SlotTable {
public:
    int FUN_000c70c0(int value);

    char pad0[0x60];
    Slot slots[16];
};

// Claims the first free slot as kind 5 and returns its index, or -1 when full.
int SlotTable::FUN_000c70c0(int value) {
    for (int i = 0; i < 16; i++) {
        if (slots[i].kind == -1) {
            Slot *slot = &slots[i];
            slots[i].kind = 5;
            Name empty;
            slot->name.FUN_0027af70(empty.FUN_0027af00());
            empty.FUN_0027af50();
            slot->a = 0;
            slot->b = 0;
            slot->c = 0;
            slot->value = value;
            return i;
        }
    }
    return -1;
}
