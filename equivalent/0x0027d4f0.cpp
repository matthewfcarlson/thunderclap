// STATUS: equivalent (tools/equiv.py level 3: 177 inputs, branch coverage 14/14)
// FUN_0027d4f0 @ 0x0027d4f0
struct Group;
struct Item { int f0, f4; int key; int target; };
struct Entry { char pad[0x24]; int count; Item* items; };
struct Table { char pad[0x1c]; Entry** entries; };
class Node {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Fire(int target, int flag);
    char pad4[0x40 - 4];
    int index;
    char pad44[0x98 - 0x44];
    Table* table;
    char pad9c[0xb4 - 0x9c];
    int childCount;
    struct Child { Node* node; int f4; unsigned flags; } child[1];
    void FUN_0027d4f0(int key);
};
void Node::FUN_0027d4f0(int key) {
    if (index == -1) return;
    for (int i = 0; i < childCount; i++) {
        if (child[i].flags & 8)
            child[i].node->FUN_0027d4f0(key);
    }
    Entry* e = table->entries[index];
    int n = e->count;
    for (int k = 0; k < n; k++) {
        Item* it = (Item*)((char*)e->items + k * 0x10);
        if (it->key == key)
            Fire(it->target, 1);
    }
}
