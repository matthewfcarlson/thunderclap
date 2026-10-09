extern "C" int __stdcall XCalculateSignatureBegin(unsigned int);
extern "C" void __stdcall FUN_002120f5(int, unsigned int, unsigned int);
extern "C" void __stdcall FUN_00212143(int, unsigned int);
extern "C" unsigned char __cdecl Target(unsigned int a, unsigned int b, unsigned int c) {
    int h = XCalculateSignatureBegin(0);
    if (h == -1)
        return 0;
    FUN_002120f5(h, a, b);
    FUN_00212143(h, c);
    return 1;
}