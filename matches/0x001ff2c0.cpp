struct Base {
    void Init(const char*, int);
};
extern unsigned char __cdecl FUN_001d04d0(const char*);
extern char g0, g1, g2, g3;
class CTriggerVolumeManager : public Base {
  public:
    CTriggerVolumeManager(const char*, int);
    int m0;
    char p04[0x0c];
    char b10;
    char b11;
    char b12;
    char p13[5];
    char b18;
    char p19[3];
    int m1c;
};
CTriggerVolumeManager::CTriggerVolumeManager(const char* a, int c) {
    Init(a, 3);
    m0 = 0x425374;
    m1c = c;
    b18 = FUN_001d04d0(&g0);
    b10 = FUN_001d04d0(&g1);
    b11 = FUN_001d04d0(&g2);
    b12 = FUN_001d04d0(&g3);
}