// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000b4d70 @ 0x000b4d70
struct Entry { unsigned int firstLow, firstHigh, secondLow, secondHigh; char rest[0x18]; };
struct Owner { char padding[0x470]; Entry entries[128]; int FUN_000b4d70(unsigned int low, unsigned int high); };
int Owner::FUN_000b4d70(unsigned int low, unsigned int high) {
    for (int i = 0; i < 128; ++i) {
        Entry &entry = entries[i];
        if (entry.firstLow == 0 && entry.firstHigh == 0) return -1;
        if (entry.firstLow == low && entry.firstHigh == high) return i;
        if (entry.secondLow == low && entry.secondHigh == high) return i;
    }
    return -1;
}