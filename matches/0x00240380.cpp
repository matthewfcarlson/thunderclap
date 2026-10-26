#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
// data: gEmpty_240380 = DAT_003f335c, gSentinel_240380 = DAT_004cc02c

extern "C" int strcmp(const char*, const char*);
class StringLike {
  public:
    char* mData;
    char Compare(const char* other);
};
char StringLike::Compare(const char* other) {
    char* p = mData;
    if (other == 0)
        return p == (*(char**)&DAT_004cc02c);
    if (p == (*(char**)&DAT_004cc02c))
        p = ((char*)&DAT_003f335c);
    return strcmp(p, other) == 0;
}
