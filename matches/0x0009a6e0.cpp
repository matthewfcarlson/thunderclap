class CCameraManager {
  public:
    int v;
    char pad4[0xc];
    unsigned char b10, b11, b12, b13, b14, b15, b16, b17, b18;
    char pad19[3];
    int m1c;
    void Init(int, int);
    CCameraManager* Run(int, int);
};
extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
CCameraManager* CCameraManager::Run(int a, int b) {
    Init(a, 6);
    v = 0x404c00;
    m1c = b;
    b18 = FUN_001d04d0((const char*)0x48e100);
    b10 = FUN_001d04d0((const char*)0x48e128);
    b11 = FUN_001d04d0((const char*)0x48e128);
    b12 = FUN_001d04d0((const char*)0x48e128);
    b13 = FUN_001d04d0((const char*)0x48e128);
    b14 = FUN_001d04d0((const char*)0x48e128);
    b15 = FUN_001d04d0((const char*)0x48e128);
    return this;
}