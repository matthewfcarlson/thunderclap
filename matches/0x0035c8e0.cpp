extern "C" unsigned long long Hash(const char* s);
extern unsigned int g_hash_lo;
extern unsigned int g_hash_hi;

void FUN_0035c8e0() {
    unsigned long long r = Hash("samson_car");
    g_hash_lo = (unsigned int)r;
    g_hash_hi = (unsigned int)(r >> 32);
}
