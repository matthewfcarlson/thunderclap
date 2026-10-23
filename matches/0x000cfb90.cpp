#include "decls/address.h"
extern const char DAT_0048e100[];
extern const char DAT_0048e10c[];
class Function_cfb90 {
  public:
    Function_cfb90(void*, int);
    virtual void f();
    char pad[0x0c];
};
class Method1 : public Function_cfb90 {
  public:
    Method1(void* a, void* c) : Function_cfb90(a, 1) {
        p = c;
        flag2 = FUN_001d04d0(DAT_0048e100);
        flag1 = FUN_001d04d0(DAT_0048e10c);
    }
    virtual void g();
    char flag1;
    char pad2[7];
    unsigned char flag2;
    char pad3[3];
    void* p;
};
class Closure1 : public Method1 {
  public:
    Closure1(void*, void*, void*);
    virtual void g();
    void* q;
};
Closure1::Closure1(void* a, void* b, void* c) : Method1(a, c) {
    q = b;
}