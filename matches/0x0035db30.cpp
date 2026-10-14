extern unsigned char data[];
extern unsigned int g_lo_35db30;
extern unsigned int g_hi_35db30;

struct Hash_35db30 {
    unsigned int lo;
    unsigned int hi;
};

Hash_35db30 __cdecl FUN_0027b020(const void* p);

void FUN_0035db30() {
    Hash_35db30 h = FUN_0027b020(data);
    g_lo_35db30 = h.lo;
    g_hi_35db30 = h.hi;
}
