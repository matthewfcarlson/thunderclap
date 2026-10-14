// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 10/10)
// FUN_00231590 @ 0x00231590
struct Entry_231590 {
    unsigned int first;
    unsigned int second;
};

struct Table_231590;

struct Probe_231590 {
    Table_231590 *table;           // 0x00
    int pad04;
    unsigned int first;     // 0x08
    unsigned int second;    // 0x0c
    unsigned int index;     // 0x10
    unsigned int step;      // 0x14
    void *FUN_002312b0(unsigned int first, unsigned int second);
    void *FUN_00231370();
};

struct Table_231590 {
    unsigned int capacity;  // 0x00
    unsigned int count;     // 0x04
    unsigned int used;      // 0x08
    char pad0c[8];
    unsigned int maxLoad;   // 0x14
    void **slots;           // 0x18
    Entry_231590 *entries;         // 0x1c
    char sentinel[4];       // 0x20
    void FUN_002310a0(unsigned int newCapacity);
    void FUN_00231590(unsigned int first, unsigned int second, void *item);
};

void Table_231590::FUN_00231590(unsigned int first, unsigned int second, void *item)
{
    Probe_231590 it;
    it.table = this;
    it.first = 0;
    it.second = 0;
    it.index = 0;
    it.step = 0;
    void *p = it.FUN_002312b0(first, second);
    while (p != 0 && p != it.table->sentinel)
        p = it.FUN_00231370();

    unsigned int idx = it.index;
    void **slot = &slots[idx];
    if (*slot == sentinel)
        used--;
    *slot = item;
    entries[idx].first = first;
    entries[idx].second = second;
    unsigned int n = count + 1;
    unsigned int cap = capacity;
    unsigned int load = n * 100 / cap;
    count = n;
    if (load > maxLoad)
        FUN_002310a0(cap * 2);
}
