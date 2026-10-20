// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_00204880 @ 0x00204880
#include "gen/content.h"
struct LoadInventory_nv_204880 {
    void FUN_002647e0(void *dest, int a, int b, int c);
};

struct Entry_204880 {
    char data[0x56];
    void FUN_00208ac0(unsigned int a, unsigned int b);
    void FUN_00208b40(unsigned int v);
    void FUN_00208b60(unsigned int v);
};

struct Table_204880 {
    char pad0[0x58c];
    Entry_204880 *entries;
    char pad590[4];
    int count;
    Entry_204880 *FUN_00204060(unsigned int a, unsigned int b);
};

struct Reader_204880 {
    char pad0[0x284];
    content::LoadInventory *stream;
    char FUN_002669f0();
    void FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};

union Slot_204880 {
    Reader_204880 *reader;
    unsigned int value;
};

class Loader_204880 {
public:
    char pad0[0x14];
    Table_204880 *table;
    void FUN_00204880(Slot_204880 arg, int unused);
};

void Loader_204880::FUN_00204880(Slot_204880 arg, int unused)
{
    Reader_204880 *rd = arg.reader;
    struct Frame {
        unsigned int second;
        unsigned int junk;
    } fr;

    ((LoadInventory_nv_204880*)(rd->stream))->FUN_002647e0(&arg.value, 1, 4, 1);
    ((LoadInventory_nv_204880*)(rd->stream))->FUN_002647e0(&fr.second, 1, 4, 1);
    ((LoadInventory_nv_204880*)(rd->stream))->FUN_002647e0(&fr.junk, 1, 4, 1);
    ((LoadInventory_nv_204880*)(rd->stream))->FUN_002647e0(&fr.junk, 1, 4, 1);

    unsigned int second = fr.second;
    Table_204880 *t = table;
    Entry_204880 *e = t->FUN_00204060(arg.value, second);
    if (e == 0) {
        t->entries[t->count].FUN_00208ac0(arg.value, second);
        e = t->entries + t->count;
        t->count++;
    }
    while (rd->FUN_002669f0()) {
        rd->FUN_00266a30();
        if (rd->FUN_00266c30() == 0x60000724) {
            ((LoadInventory_nv_204880*)(rd->stream))->FUN_002647e0(&arg.value, 1, 4, 1);
            e->FUN_00208b40(arg.value);
        } else if (rd->FUN_00266c30() == 0x60000725) {
            ((LoadInventory_nv_204880*)(rd->stream))->FUN_002647e0(&fr.second, 1, 4, 1);
            e->FUN_00208b60(fr.second);
        }
        rd->FUN_00266be0();
    }
}
