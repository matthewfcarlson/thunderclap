extern "C" int strcmp(const char*, const char*);
extern unsigned int gCount_270c10;
struct Entry_270c10 {
    char name[0x11c];
};
extern Entry_270c10 gEntries_270c10[];
int Find(const char* s) {
    unsigned int n = gCount_270c10;
    int i;
    for (i = 0; i < n; ++i) {
        if (strcmp(s, gEntries_270c10[i].name) == 0)
            return i;
    }
    return -1;
}