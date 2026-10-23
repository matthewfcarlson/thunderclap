#include "decls/address.h"
class CSPManager;
extern const char DAT_0048e100[];
extern const char DAT_0048e0e4[];
class Function_1e2340 {
  public:
    virtual void f();
    Function_1e2340(void*, int);
};
class Method1 : public Function_1e2340 {
  public:
    virtual void f();
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    void* data;
    Method1(void* p, void* d) : Function_1e2340(p, 1) {
        data = d;
        y = FUN_001d04d0(DAT_0048e100);
        x = FUN_001d04d0(DAT_0048e0e4);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    CSPManager* mgr;
    Closure1(void*, CSPManager*, void*);
};
Closure1::Closure1(void* p, CSPManager* m, void* d) : Method1(p, d) {
    mgr = m;
}