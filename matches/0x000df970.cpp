extern "C" int strcmp(const char*, const char*);
struct Entry {
    char* name;
    int value;
};
class Table {
  public:
    Entry entries[64];
    int Find(char*);
};
int Table::Find(char* s) {
    int i;
    for (i = 0; i < 64; ++i) {
        if (!entries[i].name)
            return 0;
        if (strcmp(entries[i].name, s) == 0)
            return entries[i].value;
    }
    return 0;
}