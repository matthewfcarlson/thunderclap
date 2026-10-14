struct Entry_231530 {
    unsigned a, b;
};
struct Table_231530 {
    unsigned count;
    char pad[24];
    Entry_231530* entries;
};
struct Owner_231530 {
    Table_231530* table;
    int index;
    unsigned long long get();
};
unsigned long long Owner_231530::get() {
    int i = index;
    if (i < 0 || (unsigned)i >= table->count)
        return 0;
    Entry_231530* e = table->entries + i;
    return *(unsigned long long*)e;
}