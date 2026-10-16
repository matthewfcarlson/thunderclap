#include "decls/address.h"
extern "C" char DAT_00425374[];
struct Base_1ff2c0 {
    void Init(const char*, int);
};
extern char g0_1ff2c0, g1, g2, g3;
class CTriggerVolumeManager : public Base_1ff2c0 {
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
    m0 = ((int)DAT_00425374);
    m1c = c;
    b18 = FUN_001d04d0(&g0_1ff2c0);
    b10 = FUN_001d04d0(&g1);
    b11 = FUN_001d04d0(&g2);
    b12 = FUN_001d04d0(&g3);
}