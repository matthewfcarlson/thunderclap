#include "decls/data/game/unknown.h"

typedef unsigned int uint;
int Random(int low, int high) {
    uint* p = (*(uint**)&DAT_004e5acc);
    uint* q = (*(uint**)&DAT_004e5acc) + 1;
    *(*(uint**)&DAT_004e5acc) = (*(*(uint**)&DAT_004e5acc) & 65535) * 36969 + (*(*(uint**)&DAT_004e5acc) >> 16);
    uint b = *q;
    b = (b & 65535) * 18000 + (b >> 16);
    *q = b;
    return low + ((*p << 16) + (b & 65535)) % (high - low + 1);
}