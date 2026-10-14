// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_0008c740 @ 0x0008c740
struct Slot {
    int owner;
    unsigned int bits;
    char rest[0xc0];
};

struct SlotTable {
    char pad0[0x5c];
    Slot slots[1];
};

extern "C" void __cdecl FUN_0008c710(Slot* slot, int value);

class SlotSet {
public:
    char pad0[8];
    SlotTable* table;
    int FUN_0008c740(int index, unsigned int* outBits, int value);
};

int SlotSet::FUN_0008c740(int index, unsigned int* outBits, int value) {
    if (value)
        FUN_0008c710(&table->slots[index], value);
    if (outBits) {
        Slot* s = (Slot*)((char*)table + 0x5c + index * sizeof(Slot));
        if (s == 0 || s->owner != 0) {
            *outBits = 0;
            return table->slots[index].owner;
        }
        *outBits = s->bits >> 14;
    }
    return table->slots[index].owner;
}
