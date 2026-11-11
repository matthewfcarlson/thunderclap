// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00203870..0x00208b9c (kind game, layer game, confidence high), dominant class CWorldStreamManager
// (tree_prelude.h: not needed)


// 0x00204880 FUN_00204880 (327 B): equivalent/0x00204880.cpp [isolated: code differs from its standalone build; on include/gen/ and not mergeable]
// sym: ?FUN_00204880@Loader_204880@@QAEXTSlot_204880@@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 16690 inputs, branch coverage 10/10)
// FUN_00204880 @ 0x00204880
#include "gen/content.h"
#include "gen/owners.h"
struct LoadInventory_nv_204880 {
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

    ((owners::X_2647e0 *)(((LoadInventory_nv_204880*)(rd->stream))))->FUN_002647e0((hulk_intptr)(&arg.value), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(((LoadInventory_nv_204880*)(rd->stream))))->FUN_002647e0((hulk_intptr)(&fr.second), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(((LoadInventory_nv_204880*)(rd->stream))))->FUN_002647e0((hulk_intptr)(&fr.junk), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(((LoadInventory_nv_204880*)(rd->stream))))->FUN_002647e0((hulk_intptr)(&fr.junk), (hulk_intptr)1, 4, (hulk_intptr)1);

    unsigned int second = fr.second;
    Table_204880 *t = table;
    Entry_204880 *e = ((Entry_204880 *)((owners::Owner_204060 *)t)->FUN_00204060((int)(arg.value), (int)second));
    if (e == 0) {
        t->entries[t->count].FUN_00208ac0(arg.value, second);
        e = t->entries + t->count;
        t->count++;
    }
    while (rd->FUN_002669f0()) {
        rd->FUN_00266a30();
        if (rd->FUN_00266c30() == 0x60000724) {
            ((owners::X_2647e0 *)(((LoadInventory_nv_204880*)(rd->stream))))->FUN_002647e0((hulk_intptr)(&arg.value), (hulk_intptr)1, 4, (hulk_intptr)1);
            e->FUN_00208b40(arg.value);
        } else if (rd->FUN_00266c30() == 0x60000725) {
            ((owners::X_2647e0 *)(((LoadInventory_nv_204880*)(rd->stream))))->FUN_002647e0((hulk_intptr)(&fr.second), (hulk_intptr)1, 4, (hulk_intptr)1);
            e->FUN_00208b60(fr.second);
        }
        rd->FUN_00266be0();
    }
}

