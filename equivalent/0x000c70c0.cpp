// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c70c0 @ 0x000c70c0
struct Name_c70c0 {
    int lo, hi;
    Name_c70c0 *FUN_0027af00();
    void FUN_0027af70(const Name_c70c0 *src);
    void FUN_0027af50();
};

struct Slot_c70c0 {
    int kind;       // -1 when free
    int a;
    int b;
    int c;
    Name_c70c0 name;
    int value;
    int pad1c;
};

class SlotTable_c70c0 {
public:
    int FUN_000c70c0(int value);

    char pad0[0x60];
    Slot_c70c0 slots[16];
};

// Claims the first free slot as kind 5 and returns its index, or -1 when full.
int SlotTable_c70c0::FUN_000c70c0(int value) {
    for (int i = 0; i < 16; i++) {
        if (slots[i].kind == -1) {
            Slot_c70c0 *slot = &slots[i];
            slots[i].kind = 5;
            Name_c70c0 empty;
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
