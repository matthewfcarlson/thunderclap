extern "C" int strcmp(const char*, const char*);
class Thing_df9e0 {
  public:
    char pad[0x200];
    struct Entry {
        const char* name;
        int value;
    };
    Entry entries[64];
    int Find(const char*);
};
int Thing_df9e0::Find(const char* s) {
    for (int i = 0; i < 64; ++i) {
        if (!entries[i].name)
            return 0;
        if (strcmp(entries[i].name, s) == 0)
            return entries[i].value;
    }
    return 0;
}