// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 0/0)
// FUN_000794a0 @ 0x000794a0
struct Id64 {
    unsigned int lo;
    unsigned int hi;
    Id64 *FUN_0027b0e0(const char *name);
    void FUN_0027af70(Id64 *src);
    void FUN_0027af50();
};

struct SlotEntry {
    Id64 id;                // 0x0
    int value;              // 0x8
    int pad0c;
};

extern "C" int __cdecl FUN_0034483c();

class SlotList {
public:
    char pad0000[0x3650];
    SlotEntry entries[10];  // 0x3650
    int ints[10];           // 0x36f0
    int zeros[10];          // 0x3718
    int count;              // 0x3740
    char pad3744[4];
    int scale;              // 0x3748
    void FUN_000794a0(const char *name, int value, float amount);
};

void SlotList::FUN_000794a0(const char *name, int value, float amount)
{
    Id64 id;

    entries[count].id.FUN_0027af70(id.FUN_0027b0e0(name));
    id.FUN_0027af50();
    entries[count].value = value;
    ints[count] = (int)(scale * amount);
    zeros[count] = 0;
    count++;
}
