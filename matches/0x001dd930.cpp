struct Helper {
    void Use(void*);
};
struct Entry {
    char pad[0x18];
    int ptr;
    char gap[6];
    short index;
    char tail[4];
};
struct Obj {
    char pad[0x608];
    Entry entries[0x800];
    bool Run(int index, Helper* arg);
};
bool Obj::Run(int index, Helper* arg) {
    if (index < 0 || index >= 0x800)
        return false;
    Entry* e = &entries[index];
    if ((((char*)this)[(e->index + 0x104e) * 0x14] & 1) && e->ptr != 0) {
        arg->Use((void*)(e->ptr + 8));
        return true;
    }
    arg->Use((void*)e);
    return true;
}
