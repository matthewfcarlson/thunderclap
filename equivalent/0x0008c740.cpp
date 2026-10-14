// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_0008c740 @ 0x0008c740
struct Slot_8c740 {
    int owner;
    unsigned int bits;
    char rest[0xc0];
};

struct SlotTable_8c740 {
    char pad0[0x5c];
    Slot_8c740 slots[1];
};

extern "C" void __cdecl FUN_0008c710(Slot_8c740* slot, int value);

class SlotSet {
public:
    char pad0[8];
    SlotTable_8c740* table;
    int FUN_0008c740(int index, unsigned int* outBits, int value);
};

int SlotSet::FUN_0008c740(int index, unsigned int* outBits, int value) {
    if (value)
        FUN_0008c710(&table->slots[index], value);
    if (outBits) {
        Slot_8c740* s = (Slot_8c740*)((char*)table + 0x5c + index * sizeof(Slot_8c740));
        if (s == 0 || s->owner != 0) {
            *outBits = 0;
            return table->slots[index].owner;
        }
        *outBits = s->bits >> 14;
    }
    return table->slots[index].owner;
}
