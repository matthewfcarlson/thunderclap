// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c6f20 @ 0x000c6f20
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
    int FUN_000c6f20(int kind, int a, int b, int c);

    char pad0[0x60];
    Slot slots[16];
};

// Claims the first free slot with the given kind and parameters and returns its index, or -1 when full.
int SlotTable::FUN_000c6f20(int kind, int a, int b, int c) {
    for (int i = 0; i < 16; i++) {
        if (slots[i].kind == -1) {
            Slot *slot = &slots[i];
            slots[i].kind = kind;
            Name empty;
            slot->name.FUN_0027af70(empty.FUN_0027af00());
            empty.FUN_0027af50();
            slot->c = c;
            slot->a = a;
            slot->b = b;
            slot->value = 0;
            return i;
        }
    }
    return -1;
}
