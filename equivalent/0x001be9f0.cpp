// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001be9f0 @ 0x001be9f0
// Register a (name id, value id) -> float binding unless the name id is already known or the table is full.
struct Id64 {
    unsigned int lo;
    unsigned int hi;
};

Id64 __cdecl FUN_002672f0(const char* name, int a, int b);
Id64 __cdecl FUN_0027b020(const char* name);

struct Binding {
    Id64 name;
    Id64 value;
    float amount;
    int pad14;
};

class BindingTable {
public:
    char pad0[0x3c];
    Binding* items;
    int count;

    int FUN_001be0e0(unsigned int lo, unsigned int hi);
    void FUN_001be9f0(const char* name, const char* valueName, float amount);
};

void BindingTable::FUN_001be9f0(const char* name, const char* valueName, float amount)
{
    if (count >= 0x47e) {
        return;
    }
    Id64 key = FUN_002672f0(name, 0, 0);
    Id64 value = FUN_0027b020(valueName);
    if (FUN_001be0e0(key.lo, key.hi) == -1) {
        items[count].name.lo = key.lo;
        items[count].name.hi = key.hi;
        items[count].value.lo = value.lo;
        items[count].value.hi = value.hi;
        items[count].amount = amount;
        count = count + 1;
    }
}
