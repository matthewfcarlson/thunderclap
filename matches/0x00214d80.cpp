#include "decls/data/engine/unknown.h"
// data: fmt1 = DAT_00426708, fmt2 = DAT_00426728, types = DAT_00426948

extern "C" int logmsg(void*, const char*, ...);
int compare_error(void* p, int* a, int* b) {
    const char* x = ((const char**)&DAT_00426948)[*a];
    const char* y = ((const char**)&DAT_00426948)[*b];
    if (x[2] == y[2]) {
        logmsg(p, DAT_00426728, x);
        return 0;
    }
    logmsg(p, DAT_00426708, x, y);
    return 0;
}