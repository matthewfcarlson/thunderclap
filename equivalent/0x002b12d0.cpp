// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 6/6)
// FUN_002b12d0 @ 0x002b12d0
struct Item { char pad[12]; int value; void FUN_002b0e90(Item* source); };
Item* __cdecl FUN_002b12d0(Item* destination, unsigned int count, Item* source) {
    if (count == 0) return destination;
    do {
        if (destination) {
            destination->FUN_002b0e90(source);
            destination->value = source->value;
        }
        destination = (Item*)((char*)destination + sizeof(Item));
    } while (--count);
    return destination;
}