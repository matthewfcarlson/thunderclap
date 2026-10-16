struct Entry {
    char pad[16];
    unsigned int key;
};
int __cdecl compare(const Entry* a, const Entry* b) {
    if (a->key < b->key)
        return -1;
    return a->key > b->key;
}
