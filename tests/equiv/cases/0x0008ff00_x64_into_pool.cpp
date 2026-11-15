// FUN_0008ff00 @ 0x0008ff00
// (x64t13) the projectile pool's free (src/game/unknown/unk_08ed50.cpp, records.h GameStaticAllocator): VALUE is
// annotated HULK_INTO(base), so it is generated inside the pool's data and the block index is the same on both runs
// (fuzzed as an unrelated object, `value - base` is a difference between two objects that the heaps lay out apart)
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
void Thing_8ff00::FUN_0008ff00(void* value HULK_INTO(base), int unused) {
    unsigned int index = (unsigned int)((char*)value - base) / divisor;
    bits[index >> 5] &= ~(1u << (index & 31));
    if (index < limit)
        limit = index;
}
