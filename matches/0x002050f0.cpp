extern "C" char DAT_00425b54[];
extern "C" char DAT_0048e0e4[];
extern "C" char DAT_0048e128[];
class Base {
  public:
    void Init(int, int);
};
extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
class Target : public Base {
  public:
    Target(int, int);
    void* vf;
    char pad04[0x0c];
    unsigned char b10, b11, b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    int mgr;
};
Target::Target(int a, int b) {
    Init(a, 3);
    vf = (void*)((int)DAT_00425b54);
    mgr = b;
    b18 = FUN_001d04d0((const char*)((int)DAT_0048e0e4));
    b10 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    b11 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    b12 = FUN_001d04d0((const char*)((int)DAT_0048e128));
}