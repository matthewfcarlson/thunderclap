// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000c7c60 @ 0x000c7c60
struct Str8;

__declspec(align(8)) struct Key {
    int lo, hi;
    void FUN_0027af50();
    bool FUN_0027af90(Str8 *s);
};

struct Str8 {
    char pad[8];
};

struct Entry {
    int key;
    char pad04[0x28 - 4];
    Str8 str;                  // 0x28
    char pad30[0x40 - 0x30];
};

struct Registry {
    int FUN_00024280(int id0, int id1);
};

struct Lookup {
    bool FUN_001dd7b0(Key *k);
};

struct Manager {
    char pad0[0xc];
    Lookup *lookup;
    char pad10[0x20 - 0x10];
    Registry *registry;
};

extern Manager *DAT_004dd700;

void __cdecl FUN_00096e50(Key *k, int name);

class Table {
public:
    char pad0[0x258];
    Entry entries[128];
    int FUN_000c7c60(int a, int b);
};

int Table::FUN_000c7c60(int a, int b)
{
    Key key;
    FUN_00096e50(&key, b);
    if (DAT_004dd700->registry->FUN_00024280(key.lo, key.hi) || DAT_004dd700->lookup->FUN_001dd7b0(&key)) {
        for (int i = 0; i < 128; i++) {
            if (entries[i].key == a && key.FUN_0027af90(&entries[i].str)) {
                key.FUN_0027af50();
                return i;
            }
        }
    }
    key.FUN_0027af50();
    return -1;
}
