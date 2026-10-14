// STATUS: equivalent (tools/equiv.py level 3: 176 inputs, branch coverage 9/10, incomplete)
// FUN_002f27c0 @ 0x002f27c0
struct Entry_2f27c0 {
    int key1, key2;
    int value2, value4;
    int value1, value3, copy2, copy4;
};
struct Table_2f27c0 {
    Entry_2f27c0 entries[64];
    int count;
    Entry_2f27c0* FUN_002f27c0(int key1, int key2, int value1, int value2, int value3, int value4);
};
Entry_2f27c0* Table_2f27c0::FUN_002f27c0(int key1, int key2, int value1, int value2, int value3, int value4) {
    int originalCount = count;
    for (int i = 0; i < count; ++i) {
        Entry_2f27c0 &e = entries[i];
        if (e.key1 == key1 && e.key2 == key2) {
            e.key2 = key2;
            e.value1 = value1;
            e.copy2 = value2;
            e.value3 = value3;
            e.key1 = key1;
            e.copy4 = value4;
            e.value2 = value2;
            e.value4 = value4;
            return &e;
        }
    }
    Entry_2f27c0 &e = entries[originalCount];
    e.value1 = value1;
    e.copy2 = value2;
    e.value3 = value3;
    e.copy4 = value4;
    e.value2 = value2;
    e.key1 = key1;
    e.key2 = key2;
    e.value4 = value4;
    Entry_2f27c0 *result = &entries[count];
    ++count;
    return result;
}
