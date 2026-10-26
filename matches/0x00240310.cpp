#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
// data: gEmpty_240310 = DAT_004cc02c, gZero_240310 = DAT_003f335c

extern "C" int strcmp(const char*, const char*);
struct S_240310 {
    const char* p;
    char Eq(const S_240310& o);
};
char S_240310::Eq(const S_240310& o) {
    const char* b = o.p;
    if (b == (*(const char**)&DAT_004cc02c))
        return p == (*(const char**)&DAT_004cc02c);
    const char* a = p;
    if (a == (*(const char**)&DAT_004cc02c))
        a = ((const char*)&DAT_003f335c);
    return strcmp(a, b) == 0;
}
