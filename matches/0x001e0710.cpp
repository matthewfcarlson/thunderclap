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
    *(int*)this = 0x423418;
    mgr = m;
    b18 = FUN_001d04d0((const char*)0x48e100);
    b10 = FUN_001d04d0((const char*)0x48e0f0);
    b11 = FUN_001d04d0((const char*)0x48e0f0);
    b12 = FUN_001d04d0((const char*)0x48e10c);
    b13 = FUN_001d04d0((const char*)0x48e10c);
}