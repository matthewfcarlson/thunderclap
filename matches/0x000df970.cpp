extern "C" int strcmp(const char*, const char*);
struct Entry_df970 {
    char* name;
    int value;
};
class Table_df970 {
  public:
    Entry_df970 entries[64];
    int Find(char*);
};
int Table_df970::Find(char* s) {
    int i;
    for (i = 0; i < 64; ++i) {
        if (!entries[i].name)
            return 0;
        if (strcmp(entries[i].name, s) == 0)
            return entries[i].value;
    }
    return 0;
}