extern "C" int strcmp(const char*, const char*);
struct Entry_dfa60 {
    const char* name;
    int value;
};
class Search_dfa60 {
  public:
    char pad[0x400];
    Entry_dfa60 entries[64];
    int Find(const char* s);
};
int Search_dfa60::Find(const char* s) {
    for (int i = 0; i < 64 && entries[i].name; ++i) {
        if (strcmp(entries[i].name, s) == 0)
            return entries[i].value;
    }
    return 0;
}