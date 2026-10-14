// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 10/10)
// FUN_00044820 @ 0x00044820
struct Id64 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(const Id64 *src);
};

union FloatBits {
    float f;
    int i;
};

union Slot {
    float f;
    int i;
};

struct Entry {
    Id64 id;                // 0x0
    Slot value;             // 0x8
    int pad0c;
};

class ValueTable {
public:
    char pad000[0x480];
    Entry entries[14];      // 0x480
    int count;              // 0x560
    void FUN_00044820(const Id64 *key, FloatBits value);
};

void ValueTable::FUN_00044820(const Id64 *key, FloatBits value)
{
    for (int i = 0; i < count; i++) {
        if (entries[i].id.lo == key->lo && entries[i].id.hi == key->hi)
            entries[i].value.i = value.i;
    }

    if (count < 14) {
        entries[count].id.FUN_0027af70(key);
        entries[count].value.f = value.f;
        count++;
    }
}
