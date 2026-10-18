// FUN_00313450 @ 0x00313450
extern "C" void *__cdecl memset(void *dst, int value, unsigned int n);

struct Ids_313450 {
    short *table;                   // +0x2000 (relative to the owner)
    char enabled;                   // +0x2004
    char pad05[3];
    int FUN_00312ed0(int count, int limit);
};

class Table_313450 {
public:
    int FUN_00313450(int count);
    void FUN_003130a0(int a, int count);
    void FUN_003132d0(int a, int count);

    char slots[0x2000];
    Ids_313450 ids;                        // +0x2000
    char pad2008[0x2024 - 0x2008];
    int param;                      // +0x2024
    int limit;                      // +0x2028
    short *spare;                   // +0x202c
};

int Table_313450::FUN_00313450(int count) {
    if (count < 2) {
        return 0;
    }
    memset(this, -1, 0x2000);
    ids.table = spare;
    for (int i = 0; i < count; i++) {
        ids.table[i] = (short)i;
    }
    if (ids.enabled) {
        FUN_003130a0(param, count);
    }
    FUN_003132d0(param, count);
    return ids.FUN_00312ed0(count, limit);
}
