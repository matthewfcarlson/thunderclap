struct Entry_1cb840 {
    char pad[0x28];
    bool IsActive();
};
struct Owner_1cb840 {
    char pad[0x24];
    int Target();
};
int Owner_1cb840::Target() {
    int count = 0;
    Entry_1cb840* p = (Entry_1cb840*)((char*)this + 0x24);
    for (int i = 0x18; i != 0; --i, p = (Entry_1cb840*)((char*)p + 0x28)) {
        if (p->IsActive())
            ++count;
    }
    return count;
}