extern "C" unsigned long long __cdecl FUN_0027b020(const char*);
extern unsigned int g_result_lo;
extern unsigned int g_result_hi;

void __cdecl FUN_0035e4a0() {
    unsigned long long hash = FUN_0027b020("golfBall_golfBall");
    g_result_lo = (unsigned int)hash;
    g_result_hi = (unsigned int)(hash >> 32);
}
