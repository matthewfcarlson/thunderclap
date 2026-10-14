// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 12/16, incomplete)
// FUN_001def30 @ 0x001def30
struct Id_1def30 {
    int lo, hi;
};

struct Entry_1def30 {
    char pad0[8];
    int idLo;
    int idHi;
};

Id_1def30 __cdecl FUN_00096d80(const char *name);

class Table_1def30 {
public:
    Entry_1def30 *FUN_001def30(const char *name);

    char pad0[0x1e620];
    Entry_1def30 *entries[128];
    int count;

    Entry_1def30 *At(int i) {
        if (i < count && i >= 0) {
            return entries[i];
        }
        return 0;
    }
};

Entry_1def30 *Table_1def30::FUN_001def30(const char *name) {
    Id_1def30 id = FUN_00096d80(name);
    for (int i = 0; i < count; i++) {
        Entry_1def30 *e = At(i);
        if (e->idLo == id.lo && e->idHi == id.hi) {
            return At(i);
        }
    }
    return 0;
}
