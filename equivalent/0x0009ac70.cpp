// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009ac70 @ 0x0009ac70
#include "decls/address.h"
class CCameraManager;
extern char DAT_0048e0e4, DAT_0048e0f0, DAT_0048e100, DAT_0048e128, DAT_0048e134;
class Base_9ac70 {
public:
    virtual void v();
    char p[12];
    char a[8];
    char result;
    char z[3];
    Base_9ac70(const char*, int) throw();
};
template<class C, class R, class A1, class A2, class A3, class A4>
class Method4 : public Base_9ac70 {
public:
    void (*f)();
    Method4(const char* n, void (*x)());
    virtual void v();
};
template<> Method4<CCameraManager, void, bool, bool, bool, bool>::Method4(const char* n, void (*x)()) : Base_9ac70(n, 4) {
    f = x;
    result = FUN_001d04d0(&DAT_0048e100);
    a[0] = FUN_001d04d0(&DAT_0048e0e4);
    a[1] = FUN_001d04d0(&DAT_0048e0e4);
    a[2] = FUN_001d04d0(&DAT_0048e0e4);
    a[3] = FUN_001d04d0(&DAT_0048e0e4);
}
