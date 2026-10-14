// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 2/2)
// FUN_000f9530 @ 0x000f9530
struct Entry_f9530 {
    int a;
    int b;
    int nextSlot;
    int pad;
};

struct Map_f9530 {
    int count;
    int pad04;
    Entry_f9530 entries[1];
    int FUN_000f9140(int a, int b);
};

struct Store {
    char pad[0x1248];
    Map_f9530 map;
    char padMap[0x1650 - 0x1248 - sizeof(Map_f9530)];
    int numValues;
    float values[1];
    void FUN_000f9530(int a, int b, float value);
};

void Store::FUN_000f9530(int a, int b, float value)
{
    int idx = map.FUN_000f9140(a, b);
    if (idx != -1) {
        values[idx] = value;
        return;
    }
    values[numValues] = value;
    int slot = numValues;
    map.entries[map.count].a = a;
    map.entries[map.count].b = b;
    map.entries[map.count].nextSlot = slot;
    map.count++;
    numValues = numValues + 1;
}
