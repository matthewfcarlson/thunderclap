extern "C" int strcmp(const char*, const char*);
struct Entry {
    const char* name;
    int value;
};
class Search {
  public:
    char pad[0x400];
    Entry entries[64];
    int Find(const char* s);
};
int Search::Find(const char* s) {
    for (int i = 0; i < 64 && entries[i].name; ++i) {
        if (strcmp(entries[i].name, s) == 0)
            return entries[i].value;
    }
    return 0;
}