#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
// data: fmt = DAT_004298a8, newline = DAT_00422518

extern "C" char print(const char*, const char*, ...);
extern "C" char other(const char**, const char*);
char target(const char** p, const char* s, const char** q) {
    const char* v = *p;
    if (print(v, DAT_004298a8, s) && other(p, *q)) {
        v = *p;
        return print(v, DAT_00422518);
    }
    return 0;
}
