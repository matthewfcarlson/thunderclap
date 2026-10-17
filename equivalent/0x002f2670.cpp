// STATUS: equivalent (tools/equiv.py level 3: 2288 inputs, branch coverage 9/10, incomplete)
// FUN_002f2670 @ 0x002f2670
struct Entry { int first; int second; char rest[24]; };
struct Table {
    Entry entries[64];
    int count;
    Entry* FUN_002f2670(int first, int second);
};
Entry* Table::FUN_002f2670(int first, int second) {
    for (int i = 0; i < count; ++i) {
        if (entries[i].first == first && entries[i].second == second)
            return &entries[i];
    }
    return &entries[0];
}