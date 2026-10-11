extern "C" char DAT_00423478[];
class CSPManager {
  public:
    void Init(int, int);
    int m0;
    char pad4[0x0c];
    char m10, m11, m12;
    char pad13[5];
    char m18;
    char pad19[3];
    int m1c;
    CSPManager(int, int);
};
extern char g1[];
extern char g2[];
extern "C" char __cdecl FUN_001d04d0(const char*);
CSPManager::CSPManager(int x, int y) {
    Init(x, 3);
    m0 = ((int)DAT_00423478);
    m1c = y;
    m18 = FUN_001d04d0(g1);
    m10 = FUN_001d04d0(g2);
    m11 = FUN_001d04d0(g2);
    m12 = FUN_001d04d0(g2);
}