extern "C" unsigned long long FUN_0027b020(const char*);
struct Hash {
    unsigned int lo;
    unsigned int hi;
};
extern Hash g_hash;
void FUN_0035e3e0() {
    unsigned long long result = FUN_0027b020("golfBall_golfBall");
    g_hash.lo = (unsigned int)result;
    g_hash.hi = (unsigned int)(result >> 32);
}
