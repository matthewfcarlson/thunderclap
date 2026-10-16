#include "decls/address.h"
extern char g100_be5c0[], g0f0[], g134[];
class Base_be5c0 {
  public:
    Base_be5c0(const char*, int);
    virtual void v0();
    char pad[0xc];
};
class CFEManager : public Base_be5c0 {
  public:
    CFEManager(const char*, int);
    char c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c1a, c1b;
    int m1c;
};
CFEManager::CFEManager(const char* p, int x) : Base_be5c0(p, 6) {
    m1c = x;
    c18 = FUN_001d04d0(g100_be5c0);
    c10 = FUN_001d04d0(g0f0);
    c11 = FUN_001d04d0(g0f0);
    c12 = FUN_001d04d0(g0f0);
    c13 = FUN_001d04d0(g0f0);
    c14 = FUN_001d04d0(g134);
    c15 = FUN_001d04d0(g134);
}
