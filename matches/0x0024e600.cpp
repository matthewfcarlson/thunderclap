extern "C" unsigned char __cdecl Check1(int, int, int);
extern "C" unsigned char __cdecl Validate1(int, int);
extern "C" unsigned char __cdecl Final1(int, int);
extern int kTenAddr;
unsigned char Target(int* p, int a, int b) {
    int v = *p;
    unsigned char r = Check1(v, 0x4298a8, a);
    if (r) {
        r = Validate1((int)p, b);
        if (r) {
            p = (int*)*p;
            return Final1((int)p, (int)&kTenAddr);
        }
    }
    return 0;
}
