// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00302fa0 @ 0x00302fa0
struct Entry_302fa0 {
    unsigned int data[9];
    float priority;
    unsigned int rest[7];
    void FUN_002f7a90(const Entry_302fa0* source);
};
Entry_302fa0* __cdecl FUN_00302fa0(Entry_302fa0* entries, int index, int lowerBound, Entry_302fa0 value) {
    int parent = (index - 1) / 2;
    while (lowerBound < index) {
        if (!(entries[parent].priority < value.priority)) break;
        entries[index].FUN_002f7a90(&entries[parent]);
        index = parent;
        parent = (parent - 1) / 2;
    }
    Entry_302fa0* destination = &entries[index];
    *destination = value;
    return destination;
}