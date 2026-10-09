typedef unsigned short ushort;
struct Node {
    char pad[8];
    char* items;
    char pad2[0x0c];
    ushort* records;
};
struct Entry {
    char pad[0x44];
    Node* node;
};
struct Result {
    char pad[0x0c];
};
extern char gFallback;
struct Owner {
    Entry** entries;
    Result* Lookup(int key, int index);
};
Result* Owner::Lookup(int key, int index) {
    Entry* e = entries[(key >> 16) & 0xffff];
    if (e) {
        Node* n = e->node;
        ushort low = (ushort)key;
        ushort v = *(ushort*)((char*)n->records + 0x10 + (index + low * 12) * 2);
        return (Result*)((char*)n->items + v * 12);
    }
    return (Result*)&gFallback;
}
