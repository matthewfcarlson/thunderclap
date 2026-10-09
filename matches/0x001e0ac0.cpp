class CSPManager {
  public:
    int x;
    char pad4[12];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int m1c;
    void Init(int, int);
    CSPManager* Run(int, int);
};
extern char __cdecl FUN_001d04d0(const char*);
extern const char s0[];
extern const char s1[];
extern const char s2[];
extern const char s3[];
CSPManager* CSPManager::Run(int a, int b) {
    Init(a, 3);
    x = 0x423468;
    m1c = b;
    b18 = FUN_001d04d0(s0);
    b10 = FUN_001d04d0(s1);
    b11 = FUN_001d04d0(s2);
    b12 = FUN_001d04d0(s3);
    return this;
}