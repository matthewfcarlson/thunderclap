// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00302fa0 @ 0x00302fa0
struct Entry {
    unsigned int data[9];
    float priority;
    unsigned int rest[7];
    void FUN_002f7a90(const Entry* source);
};
Entry* __cdecl FUN_00302fa0(Entry* entries, int index, int lowerBound, Entry value) {
    int parent = (index - 1) / 2;
    while (lowerBound < index) {
        if (!(entries[parent].priority < value.priority)) break;
        entries[index].FUN_002f7a90(&entries[parent]);
        index = parent;
        parent = (parent - 1) / 2;
    }
    Entry* destination = &entries[index];
    *destination = value;
    return destination;
}