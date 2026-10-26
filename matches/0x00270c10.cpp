#include "decls/data/engine/unknown.h"
// data: gCount_270c10 = DAT_0052a128, gEntries_270c10 = DAT_00528418

extern "C" int strcmp(const char*, const char*);
struct Entry_270c10 {
    char name[0x11c];
};
int Find(const char* s) {
    unsigned int n = (*(unsigned int*)&DAT_0052a128);
    int i;
    for (i = 0; i < n; ++i) {
        if (strcmp(s, ((Entry_270c10*)&DAT_00528418)[i].name) == 0)
            return i;
    }
    return -1;
}