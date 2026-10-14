extern "C" int strcmp(const char*, const char*);
struct Entry_337130 {
    const char* name;
    char pad[20];
};
class Table_337130 {
    char pad[0x44];
    int count;
    char pad2[4];
    Entry_337130 entries[1];

  public:
    int Find(const char* name);
};
int Table_337130::Find(const char* name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(name, entries[i].name) == 0)
            return i;
    }
    return -1;
}