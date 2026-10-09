extern "C" void __stdcall FUN_001d0480(const char*, int);
extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
class Target {
  public:
    int vptr;
    char pad04[12];
    unsigned char b10, b11, b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    int m1c;
    Target(const char*, int);
};
Target::Target(const char* a, int b) {
    FUN_001d0480(a, 3);
    vptr = 0x3f5d4c;
    m1c = b;
    b18 = FUN_001d04d0((const char*)0x48e100);
    b10 = FUN_001d04d0((const char*)0x48e0f0);
    b11 = FUN_001d04d0((const char*)0x48e0f0);
    b12 = FUN_001d04d0((const char*)0x48e128);
}