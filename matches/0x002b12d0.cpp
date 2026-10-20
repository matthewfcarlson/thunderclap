struct Item {
    char pad[12];
    int value;
    void FUN_002b0e90(Item* source);
};
Item* __cdecl FUN_002b12d0(Item* destination, unsigned int count, Item* source) {
    while (count) {
        if (destination) {
            destination->FUN_002b0e90(source);
            destination->value = source->value;
        }
        destination = (Item*)((char*)destination + sizeof(Item));
        --count;
    }
    return destination;
}