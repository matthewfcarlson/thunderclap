// STATUS: equivalent (tools/equiv.py level 3: 270 inputs, branch coverage 8/8)
// FUN_001b5d20 @ 0x001b5d20
struct Record {
    char pad0[0x16];
    unsigned short flags;   // bits 13..15: group tag
};

struct RecordTable {
    char pad0[0x18];
    Record* records;
    char pad1c[4];
    unsigned short count;
};

struct Node {
    char pad0[0x44];
    RecordTable* table;
};

class NodeList {
public:
    Node** begin;
    Node** end;
    // Clears the group tag (bits 13..15) of every record whose tag equals `tag`.
    void FUN_001b5d20(unsigned short index, int tag);
};

void NodeList::FUN_001b5d20(unsigned short index, int tag) {
    Node* node = 0;
    if ((unsigned int)index < (unsigned int)(end - begin))
        node = begin[index];
    for (unsigned int i = 0; i < node->table->count; i++) {
        Record* r = &node->table->records[(unsigned short)i];
        unsigned short f = r->flags;
        unsigned short low = f >> 3;
        if ((int)((unsigned int)low >> 10 & 7) == tag)
            r->flags = (unsigned short)(((low & 0x3ff) << 3) | (f & 7));
    }
}
