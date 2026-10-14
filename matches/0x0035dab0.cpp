extern "C" unsigned long long FUN_0027b020(const char*);
extern unsigned int g_hash;
extern unsigned int g_hash_hi;
void FUN_0035dab0() {
    unsigned long long r = FUN_0027b020("TextInputEntryLocators");
    g_hash = (unsigned int)r;
    g_hash_hi = (unsigned int)(r >> 32);
}
