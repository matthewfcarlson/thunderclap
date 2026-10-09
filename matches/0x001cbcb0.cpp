struct Entry {
    void Set(int, int);
    void Reset(int);
    void Finish(int);
};
struct Owner {
    char pad[0x3e4];
    unsigned char active[0x18];
    bool Run(int);
};
bool Owner::Run(int arg) {
    int i = 0;
    Entry* entry = (Entry*)((char*)this + 0x24);
    do {
        if (active[i] && i >= 0 && i < 0x18) {
            entry->Set(1, arg);
            entry->Reset(0);
            entry->Finish(1);
            active[i] = 0;
        }
        ++i;
        entry = (Entry*)((char*)entry + 0x28);
    } while ((unsigned int)i < 0x18);
    return true;
}