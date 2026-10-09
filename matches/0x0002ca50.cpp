extern "C" void __stdcall FUN_001d0480(const char*, int);
extern "C" char __cdecl FUN_001d04d0(const char*);
class Method6 {
  public:
    char* vt;
    char pad4[0x0c];
    char b10, b11, b12, b13, b14, b15;
    char pad16[2];
    char b18;
    char pad19[3];
    int m1c;
    Method6(const char*, int);
};
Method6::Method6(const char* a, int b) {
    FUN_001d0480(a, 6);
    vt = (char*)0x3f40cc;
    m1c = b;
    b18 = FUN_001d04d0((const char*)0x48e0e4);
    b10 = FUN_001d04d0((const char*)0x48e0f0);
    b11 = FUN_001d04d0((const char*)0x48e0f0);
    b12 = FUN_001d04d0((const char*)0x48e0f0);
    b13 = FUN_001d04d0((const char*)0x48e0f0);
    b14 = FUN_001d04d0((const char*)0x48e0e4);
    b15 = FUN_001d04d0((const char*)0x48e0f0);
}