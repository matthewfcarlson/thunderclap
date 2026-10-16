// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000944d0 @ 0x000944d0
#include "decls/address.h"
class CUnlockablesManager;
extern char DAT_0048e0e4, DAT_0048e0f0, DAT_0048e100, DAT_0048e128, DAT_0048e134;
class Base_944d0 {
public:
    virtual void v();
    char p[12];
    char a[8];
    char result;
    char z[3];
    Base_944d0(const char*, int) throw();
};
template<class C, class R, class A1, class A2, class A3, class A4>
class Method4 : public Base_944d0 {
public:
    void (*f)();
    Method4(const char* n, void (*x)());
    virtual void v();
};
template<> Method4<CUnlockablesManager, void, const char *, int, const char *, const char *>::Method4(const char* n, void (*x)()) : Base_944d0(n, 4) {
    f = x;
    result = FUN_001d04d0(&DAT_0048e100);
    a[0] = FUN_001d04d0(&DAT_0048e0f0);
    a[1] = FUN_001d04d0(&DAT_0048e134);
    a[2] = FUN_001d04d0(&DAT_0048e0f0);
    a[3] = FUN_001d04d0(&DAT_0048e0f0);
}
