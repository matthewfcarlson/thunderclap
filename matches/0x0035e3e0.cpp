extern "C" unsigned long long FUN_0027b020(const char*);
struct Hash_35e3e0 {
    unsigned int lo;
    unsigned int hi;
};
extern Hash_35e3e0 g_hash_35e3e0;
void FUN_0035e3e0() {
    unsigned long long result = FUN_0027b020("golfBall_golfBall");
    g_hash_35e3e0.lo = (unsigned int)result;
    g_hash_35e3e0.hi = (unsigned int)(result >> 32);
}
