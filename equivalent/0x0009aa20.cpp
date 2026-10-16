// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009aa20 @ 0x0009aa20
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
class CCameraManager;
class Base_9aa20 {
public:
    virtual void v();
    char p[12];
    char a[8];
    char result;
    char z[3];
    Base_9aa20(const char*, int) throw();
};
template<class C, class R, class A1, class A2, class A3, class A4>
class Method4 : public Base_9aa20 {
public:
    void (*f)();
    Method4(const char* n, void (*x)());
    virtual void v();
};
template<> Method4<CCameraManager, void, float, float, float, float>::Method4(const char* n, void (*x)()) : Base_9aa20(n, 4) {
    f = x;
    result = FUN_001d04d0(((char*)&DAT_0048e100));
    a[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    a[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    a[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    a[3] = FUN_001d04d0(((char*)&DAT_0048e128));
}
