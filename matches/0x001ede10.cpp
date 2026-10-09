extern "C" void __stdcall FUN_001d0480(const char*, int);
extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
class Obj {
  public:
    Obj(const char*, int);
    int* vptr;
    char p4[0x0c];
    unsigned char m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m1a, m1b;
    int m1c;
};
Obj::Obj(const char* a, int b) {
    FUN_001d0480(a, 4);
    vptr = (int*)0x4243b8;
    m1c = b;
    m18 = FUN_001d04d0((const char*)0x48e100);
    m10 = FUN_001d04d0((const char*)0x48e0f0);
    m11 = FUN_001d04d0((const char*)0x48e0f0);
    m12 = FUN_001d04d0((const char*)0x48e0f0);
    m13 = FUN_001d04d0((const char*)0x48e0f0);
}