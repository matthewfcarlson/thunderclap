typedef unsigned short ushort;
struct Node {
    char pad[8];
    char* items;
    char pad2[0x0c];
    ushort* records;
};
struct Entry_1b56a0 {
    char pad[0x44];
    Node* node;
};
struct Result_1b56a0 {
    char pad[0x0c];
};
extern char gFallback_1b56a0;
struct Owner_1b56a0 {
    Entry_1b56a0** entries;
    Result_1b56a0* Lookup(int key, int index);
};
Result_1b56a0* Owner_1b56a0::Lookup(int key, int index) {
    Entry_1b56a0* e = entries[(key >> 16) & 0xffff];
    if (e) {
        Node* n = e->node;
        ushort low = (ushort)key;
        ushort v = *(ushort*)((char*)n->records + 0x10 + (index + low * 12) * 2);
        return (Result_1b56a0*)((char*)n->items + v * 12);
    }
    return (Result_1b56a0*)&gFallback_1b56a0;
}
