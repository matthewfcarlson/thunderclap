// STATUS: equivalent (tools/equiv.py level 3: 177 inputs, branch coverage 14/14)
// FUN_0027d580 @ 0x0027d580
class Node;

struct ChildLink {
    Node *node;             // 0x0
    int pad4;
    unsigned char flags;    // 0x8
    char pad9[3];
};

struct Record_27d580 {
    int keyA;               // 0x0
    int keyB;               // 0x4
    int pad8;
    int value;              // 0xc
};

struct Group_27d580 {
    char pad0[0x24];
    int recordCount;        // 0x24
    Record_27d580 *records;        // 0x28
};

struct Table_27d580 {
    char pad0[0x1c];
    Group_27d580 **groups;         // 0x1c
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void Trigger(int value, int flag);      // slot 16

    char pad4[0x40 - 4];
    int groupIndex;         // 0x40
    char pad44[0x98 - 0x44];
    Table_27d580 *table;           // 0x98
    char pad9c[0xb4 - 0x9c];
    int childCount;         // 0xb4
    ChildLink children[1];  // 0xb8

    void FUN_0027d580(int keyA, int keyB);
};

void Node::FUN_0027d580(int keyA, int keyB)
{
    for (int i = 0; i < childCount; i++) {
        if (children[i].flags & 8)
            children[i].node->FUN_0027d580(keyA, keyB);
    }

    Group_27d580 *g = table->groups[groupIndex];
    int recordCount = g->recordCount;
    for (int i = 0; i < recordCount; i++) {
        Record_27d580 *r = &g->records[i];
        if (r->keyA == keyA && r->keyB == keyB)
            Trigger(r->value, 1);
    }
}
