extern unsigned char data[];
extern unsigned int g_lo;
extern unsigned int g_hi;

struct Hash {
    unsigned int lo;
    unsigned int hi;
};

Hash __cdecl FUN_0027b020(const void* p);

void FUN_0035db30() {
    Hash h = FUN_0027b020(data);
    g_lo = h.lo;
    g_hi = h.hi;
}
