#include "decls/address.h"
extern unsigned int g_hash_lo;
extern unsigned int g_hash_hi;
void Register() {
    unsigned long long h = FUN_0027b020("golfBall_golfBall");
    g_hash_lo = (unsigned int)h;
    g_hash_hi = (unsigned int)(h >> 32);
}
