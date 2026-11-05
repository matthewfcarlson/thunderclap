unsigned __int64 FUN_0027b020(const char* s);
extern unsigned int g_hash_lo;
extern unsigned int g_hash_hi;

void FUN_0035c8e0() {
    unsigned long long r = FUN_0027b020("samson_car");
    g_hash_lo = (unsigned int)r;
    g_hash_hi = (unsigned int)(r >> 32);
}
