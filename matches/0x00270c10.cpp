extern "C" int strcmp(const char*, const char*);
extern unsigned int gCount;
struct Entry {
    char name[0x11c];
};
extern Entry gEntries[];
int Find(const char* s) {
    unsigned int n = gCount;
    int i;
    for (i = 0; i < n; ++i) {
        if (strcmp(s, gEntries[i].name) == 0)
            return i;
    }
    return -1;
}