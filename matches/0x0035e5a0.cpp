extern "C" unsigned __int64 __cdecl FUN_0027b020(const char* s);

extern unsigned int g_hash_lo;
extern unsigned int g_hash_hi;

void FUN_0035e5a0() {
    unsigned __int64 result = FUN_0027b020("flux");
    g_hash_lo = (unsigned int)result;
    g_hash_hi = (unsigned int)(result >> 32);
}
