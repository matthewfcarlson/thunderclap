struct Entry {
    char pad[0x28];
    bool IsActive();
};
struct Owner {
    char pad[0x24];
    int Target();
};
int Owner::Target() {
    int count = 0;
    Entry* p = (Entry*)((char*)this + 0x24);
    for (int i = 0x18; i != 0; --i, p = (Entry*)((char*)p + 0x28)) {
        if (p->IsActive())
            ++count;
    }
    return count;
}