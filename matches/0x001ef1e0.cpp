struct Key {
    int first;
    int second;
};
struct Entry {
    int first;
    int second;
    char pad[4];
    Entry* next;
};
struct Node {
    char pad[4];
    Entry* entries;
    Node* next;
    Entry* FUN_001ef1e0(const Key* key);
};
Entry* Node::FUN_001ef1e0(const Key* key) {
    Node* node = this;
    for (;;) {
        Entry* entry = node->entries;
        if (entry) {
            __int64 value = *(__int64*)key;
            do {
                if (*(__int64*)entry == value)
                    return entry;
                entry = entry->next;
            } while (entry);
        }
        Node* n = node->next;
        if (!n)
            return 0;
        node = n;
    }
}