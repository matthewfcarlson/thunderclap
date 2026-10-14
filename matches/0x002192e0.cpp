struct Node {
    Node* next;
    unsigned unknown;
    unsigned hash;
};
struct Table_2192e0 {
    Node** buckets;
    int unknown;
    int count;
    char pad[0x18];
    int locked;
};
struct Owner_2192e0 {
    char pad[0x10];
    Table_2192e0* table;
};
extern void* __cdecl FUN_0021add0(Owner_2192e0*, void*, unsigned, unsigned);
void __cdecl FUN_002192e0(Owner_2192e0* owner, int count) {
    if (owner->table->locked > 0)
        return;
    Node** buckets = (Node**)FUN_0021add0(owner, 0, 0, (unsigned)count * 4);
    Table_2192e0* table = owner->table;
    for (int i = 0; i < count; ++i)
        buckets[i] = 0;
    for (int i = 0; i < table->count; ++i) {
        Node* node = table->buckets[i];
        while (node) {
            unsigned index = node->hash & ((unsigned)count - 1);
            Node* next = node->next;
            node->next = buckets[index];
            buckets[index] = node;
            node = next;
        }
    }
    FUN_0021add0(owner, table->buckets, (unsigned)table->count * 4, 0);
    table->buckets = buckets;
    table->count = count;
}
