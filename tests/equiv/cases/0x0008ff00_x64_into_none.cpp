// FUN_0008ff00 @ 0x0008ff00
// (x64t13) 0x0008ff00_x64_into_pool without HULK_INTO: VALUE is fuzzed as an object of its own, the difference fails
#if defined(HULK_EQ64_PARSE)
#define HULK_INTO(field) __attribute__((annotate("hulk_into " #field)))
#else
#define HULK_INTO(field)
#endif
struct Thing_8ff00 {
    const void* vftable;
    unsigned int divisor;
    unsigned int count;
    int flags;
    char* base;
    unsigned int* bits;
    unsigned int limit;
    void FUN_0008ff00(void* value, int unused);
};
void Thing_8ff00::FUN_0008ff00(void* value, int unused) {
    unsigned int index = (unsigned int)((char*)value - base) / divisor;
    bits[index >> 5] &= ~(1u << (index & 31));
    if (index < limit)
        limit = index;
}
