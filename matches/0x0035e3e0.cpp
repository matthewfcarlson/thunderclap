#include "decls/address.h"
#include "decls/data/game/hulkfight/motion.h"
// data: g_hash_35e3e0 = DAT_004e12c8
struct Hash_35e3e0 {
    unsigned int lo;
    unsigned int hi;
};
void FUN_0035e3e0() {
    unsigned long long result = FUN_0027b020("golfBall_golfBall");
    (*(Hash_35e3e0*)&DAT_004e12c8).lo = (unsigned int)result;
    (*(Hash_35e3e0*)&DAT_004e12c8).hi = (unsigned int)(result >> 32);
}
