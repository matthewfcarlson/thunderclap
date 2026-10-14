extern "C" unsigned long long __cdecl Alloc(unsigned int x);
extern unsigned int gA_35dde0;
extern unsigned int gB_35dde0;
void __cdecl FUN_0035dde0() {
    unsigned long long p = Alloc(0x40048c);
    gA_35dde0 = (unsigned int)p;
    gB_35dde0 = (unsigned int)((unsigned long long)p >> 32);
}
