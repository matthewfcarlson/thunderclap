class CSPManager {};
extern "C" void __stdcall FUN_001d0480(const char*, int);
extern "C" unsigned char FUN_001d04d0(const char*);
extern const char s0[], s1[], s2[], s3[];
class Target {
  public:
    void* vf;
    char p4[12];
    unsigned char b10, b11, b12;
    char p13[5];
    unsigned char b18;
    char p19[3];
    CSPManager* mgr;
    Target(const char*, CSPManager*);
};
Target::Target(const char* a, CSPManager* c) {
    FUN_001d0480(a, 3);
    vf = (void*)0x423398;
    mgr = c;
    b18 = FUN_001d04d0(s0);
    b10 = FUN_001d04d0(s1);
    b11 = FUN_001d04d0(s2);
    b12 = FUN_001d04d0(s3);
}