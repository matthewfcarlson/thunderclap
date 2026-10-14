extern "C" unsigned long long __cdecl Alloc(unsigned int x);
extern unsigned int gA;
extern unsigned int gB;
void __cdecl FUN_0035dde0() {
    unsigned long long p = Alloc(0x40048c);
    gA = (unsigned int)p;
    gB = (unsigned int)((unsigned long long)p >> 32);
}
