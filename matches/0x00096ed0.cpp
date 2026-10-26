#include "decls/data/game/hulkfight.h"
// data: buf = DAT_004dd948, fmt = DAT_00404adc

extern "C" unsigned __int64 f1(unsigned int);
extern "C" unsigned __int64 f2(unsigned int, unsigned __int64);
extern "C" int f3(char*, unsigned int, const char*, ...);
char* target(unsigned int a, unsigned int b) {
    unsigned __int64 n = f2(b, f1(a));
    f3(((char*)&DAT_004dd948), 64, DAT_00404adc, (unsigned int)(n >> 32), (unsigned int)n);
    return ((char*)&DAT_004dd948);
}
