// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 12/16, incomplete)
// FUN_001def30 @ 0x001def30
struct Id {
    int lo, hi;
};

struct Entry {
    char pad0[8];
    int idLo;
    int idHi;
};

Id __cdecl FUN_00096d80(const char *name);

class Table {
public:
    Entry *FUN_001def30(const char *name);

    char pad0[0x1e620];
    Entry *entries[128];
    int count;

    Entry *At(int i) {
        if (i < count && i >= 0) {
            return entries[i];
        }
        return 0;
    }
};

Entry *Table::FUN_001def30(const char *name) {
    Id id = FUN_00096d80(name);
    for (int i = 0; i < count; i++) {
        Entry *e = At(i);
        if (e->idLo == id.lo && e->idHi == id.hi) {
            return At(i);
        }
    }
    return 0;
}
