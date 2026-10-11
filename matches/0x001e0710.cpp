extern "C" char DAT_00423418[];
extern "C" char DAT_0048e0f0[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e10c[];
class CSPManager;
class Target {
  public:
    char p00[0x10];
    unsigned char b10, b11, b12, b13;
    char p14[4];
    unsigned char b18;
    char p19[3];
    CSPManager* mgr;
    Target(const char*, CSPManager*);
};
extern void __stdcall FUN_001d0480(const char*, int);
extern unsigned char FUN_001d04d0(const char*);
Target::Target(const char* s, CSPManager* m) {
    FUN_001d0480(s, 4);
    *(int*)this = ((int)DAT_00423418);
    mgr = m;
    b18 = FUN_001d04d0((const char*)((int)DAT_0048e100));
    b10 = FUN_001d04d0((const char*)((int)DAT_0048e0f0));
    b11 = FUN_001d04d0((const char*)((int)DAT_0048e0f0));
    b12 = FUN_001d04d0((const char*)((int)DAT_0048e10c));
    b13 = FUN_001d04d0((const char*)((int)DAT_0048e10c));
}