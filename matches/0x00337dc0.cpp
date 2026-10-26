#include "decls/data/engine/movie.h"
// data: g_tab = DAT_004d982c

extern "C" int strcmp(const char*, const char*);
int Find(const char* s) {
    for (int i = 0; i < 11; i++) {
        if (strcmp(s, ((const char**)&DAT_004d982c)[i]) == 0)
            return i;
    }
    return -1;
}
